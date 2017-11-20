/*****************************************************************************
 *   Processing.cpp
 ******************************************************************************
 *   by Kirill Kornyakov and Alexander Shishkov, 13th May 2013
 ****************************************************************************** *
 *   Copyright Packt Publishing 2013.
 *   http://bit.ly/OpenCV_for_iOS_book
 *****************************************************************************/

#include <opencv2/core/core.hpp>
#include "Processing.hpp"
#include <Accelerate/Accelerate.h>

//#if defined(__ARM_NEON__)
//#include <arm_neon.h>
//#endif

//#define USE_NEON true
//#define USE_FIXED_POINT false

using namespace cv;

void alphaBlendC1(const Mat& src, Mat& dst, const Mat& alpha)
{
    for (int i = 0; i < src.rows; i++)
        for (int j = 0; j < src.cols; j++)
        {
            uchar alphaVal = alpha.at<uchar>(i, j);
            if (alphaVal != 0)
            {
                float weight = static_cast<float>(alphaVal) / 255.0f;
                dst.at<uchar>(i, j) = weight * src.at<uchar>(i, j) +
                    (1 - weight) * dst.at<uchar>(i, j);
            }
        }
}

void alphaBlendC4(const Mat& src, Mat& dst, const Mat& alpha)
{
    for (int i = 0; i < src.rows; i++)
        for (int j = 0; j < src.cols; j++)
        {
            uchar alpha_value = alpha.at<uchar>(i, j);
            if (alpha_value != 0)
            {
                float weight = float(alpha_value) / 255.f;
                dst.at<Vec4b>(i, j) = weight * src.at<Vec4b>(i, j) +
                    (1 - weight) * dst.at<Vec4b>(i, j);
            }
        }
}

void ExtractAlpha(cv::Mat& rgbaSrc, cv::Mat& alpha)
{
    std::vector<Mat> channels;
    split(rgbaSrc, channels);
    channels[3].copyTo(alpha);
}

int cvtColor_Accelerate(const Mat& src, Mat& dst,
                        Mat buff1, Mat buff2)
{
    vImagePixelCount rows = static_cast<vImagePixelCount>(src.rows);
    vImagePixelCount cols = static_cast<vImagePixelCount>(src.cols);

    vImage_Buffer _src = { src.data, rows, cols, src.step };
    vImage_Buffer _dst = { dst.data, rows, cols, dst.step };
    vImage_Buffer _buff1 = { buff1.data, rows, cols, buff1.step };
    vImage_Buffer _buff2 = { buff2.data, rows, cols, buff2.step };

    const int16_t matrix[4 * 4] = {  77, 0, 0, 0,
        150, 0, 0, 0,
        29, 0, 0, 0,
        0, 0, 0, 0 };
    int32_t divisor = 256;

    vImage_Error err;
    err = vImageMatrixMultiply_ARGB8888(&_src, &_buff1,
                                        matrix, divisor,
                                        NULL, NULL, 0 );

    err = vImageConvert_ARGB8888toPlanar8(&_buff1, &_dst,
                                          &_buff2, &_buff2,
                                          &_buff2, 0);
    return err;
}


int equalizeHist_Accelerate(const Mat& src, Mat& dst)
{
    vImagePixelCount rows = static_cast<vImagePixelCount>(src.rows);
    vImagePixelCount cols = static_cast<vImagePixelCount>(src.cols);

    vImage_Buffer _src = { src.data, rows, cols, src.step };
    vImage_Buffer _dst = { dst.data, rows, cols, dst.step };

    vImage_Error err;
    err = vImageEqualization_Planar8( &_src, &_dst, 0 );

    return err;
}

void alphaBlendC1_NEON(const Mat& src, Mat& dst, const Mat& alpha)
{
    CV_Assert(src.type() == dst.type() == alpha.type() == CV_8UC1 &&
              src.isContinuous() && dst.isContinuous() &&
              alpha.isContinuous() &&
              (src.cols % 8 == 0) &&
              (src.cols == dst.cols) && (src.cols == alpha.cols));

#if !defined(__ARM_NEON__) || !USE_NEON
    alphaBlendC1(src, dst, alpha);
#else
    uchar* pSrc = src.data;
    uchar* pDst = dst.data;
    uchar* pAlpha = alpha.data;
    for(int i=0; i < src.total(); i+=8, pSrc+=8, pDst+=8, pAlpha+=8)
    {
        //load
        uint8x8_t vsrc = vld1_u8(pSrc);
        uint8x8_t vdst = vld1_u8(pDst);
        uint8x8_t valpha = vld1_u8(pAlpha);
        uint8x8_t v255 = vdup_n_u8(255);

        // source
        uint16x8_t mult1 = vmull_u8(vsrc, valpha);

        // destination
        uint8x8_t tmp = vsub_u8(v255, valpha);
        uint16x8_t mult2 = vmull_u8(tmp, vdst);

        //add them
        uint16x8_t sum = vaddq_u16(mult1, mult2);

        //take upper bytes, emulation /255
        uint8x8_t out = vshrn_n_u16(sum, 8);

        // store to the memory
        vst1_u8(pDst, out);
    }
#endif
}

void multiply_NEON(Mat& src, float multiplier)
{
    CV_Assert(src.type() == CV_8UC1 && src.isContinuous() &&
              (src.cols % 8 == 0));

#if !defined(__ARM_NEON__) || !USE_NEON
    src *= multiplier;
#elif USE_FIXED_POINT
    uchar fpMult = uchar((multiplier * 128.f) + 0.5f);
    uchar* ptr = src.data;
    for(int i = 0; i < src.total(); i+=8, ptr+=8)
    {
        uint8x8_t vsrc = vld1_u8(ptr);
        uint8x8_t vmult = vdup_n_u8(fpMult);
        uint16x8_t product = vmull_u8(vsrc, vmult);
        uint8x8_t out = vqshrn_n_u16(product, 7);
        vst1_u8(ptr, out);
    }
#else
    uchar* ptr = src.data;
    for(int i = 0; i < src.total(); i+=8, ptr+=8)
    {
        float32x4_t vmult1 = vdupq_n_f32(multiplier);
        float32x4_t vmult2 = vdupq_n_f32(multiplier);

        uint8x8_t in = vld1_u8(ptr); //load

        //convert to 16bit
        uint16x8_t in16bit = vmovl_u8(in);

        // split vector
        uint16x4_t in16bit1 = vget_high_u16(in16bit);
        uint16x4_t in16bit2 = vget_low_u16(in16bit);

        // convert to float
        uint32x4_t in32bit1 = vmovl_u16(in16bit1);
        uint32x4_t in32bit2 = vmovl_u16(in16bit2);
        float32x4_t inFlt1 = vcvtq_f32_u32(in32bit1);
        float32x4_t inFlt2 = vcvtq_f32_u32(in32bit2);

        // multiplication
        float32x4_t outFlt1 = vmulq_f32(vmult1, inFlt1);
        float32x4_t outFlt2 = vmulq_f32(vmult2, inFlt2);

        // convert from float
        uint32x4_t out32bit1 = vcvtq_u32_f32(outFlt1);
        uint32x4_t out32bit2 = vcvtq_u32_f32(outFlt2);
        uint16x4_t out16bit1 = vmovn_u32(out32bit1);
        uint16x4_t out16bit2 = vmovn_u32(out32bit2);

        // combine back
        uint16x8_t out16bit = vcombine_u16(out16bit2, out16bit1);

        // convert to 8bit
        uint8x8_t out8bit = vqmovn_u16(out16bit);

        // store to the memory
        vst1_u8(ptr, out8bit);
    }
#endif
}




