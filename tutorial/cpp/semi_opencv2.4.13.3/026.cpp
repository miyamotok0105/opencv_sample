//http://cvwww.ee.ous.ac.jp/semi/opencv#2.1
//対応点からアフィン変換行列を算出
//g++ -o 026 026.cpp `pkg-config --cflags opencv` `pkg-config --libs opencv` -std=c++11

#include <opencv2/opencv.hpp>
 
int main(void)
{
    cv::Mat src, dst;
 
    src = cv::imread("../../../img/hari.jpg");
 
    // アフィン変換行列
    cv::Mat affine;
 
    // 対応点（3点）の設定
    // * 0.8f の f は直前の数値がfloat型であることを示す。
    //   fをつけない実数定数はdouble型になる。
    cv::Point2f srcPoint[3] = { { 0, 0 },{ 1, 0 },{ 0, 1 } };
    cv::Point2f dstPoint[3] = { { 0, 0 },{ 0.8f, 0.2f },{ 0.2f, 0.8f } };
 
    // 対応点からアフィン変換行列を求める
    // * srcPoint から dstPoint への変換を行うアフィン変換行列が得られる。
    affine = cv::getAffineTransform(srcPoint, dstPoint);
 
    // アフィン変換
    cv::warpAffine(src, dst, affine, src.size(), cv::INTER_LINEAR);
 
    cv::imshow("原画像", src);
    cv::imshow("変換後画像", dst);
 
    cv::waitKey();
 
    return 0;
}



