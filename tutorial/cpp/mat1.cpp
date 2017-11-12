#include <iostream>
#include <opencv2/core/core.hpp>

//g++ -o mat1 mat1.cpp `pkg-config --cflags opencv` `pkg-config --libs opencv`
//http://opencv.jp/cookbook/opencv_mat.html

int
main(int argc, char *argv[])
{
  // 64F, channels=10, 3x3 の2次元配列（行列）
  //CV_<ビット数><型>C<チャネル数>
  // S - 符号付き整数表現
  // U - 符号無し整数表現
  // F - 浮動小数点表現
  //なのでCV_64FCは64ビットの浮動小数点、Cは10チャンネル
  cv::Mat m1(3, 3, CV_64FC(10));
  cv::Mat m2(3, 3, CV_MAKETYPE(CV_64F, 10));
   
  CV_Assert(m1.type() == m2.type());
  std::cout << "mat1/mat2"<< std::endl;
  std::cout << "  dims: " << m1.dims << ", depth(byte/channel):" << m1.elemSize1() \
	    << ", channels: " << m1.channels() << std::endl;

  // 64F, channles=1, 2x2x3x4 の4次元配列
  const int sizes[] = {2, 2, 3, 4};
  cv::Mat m3(sizeof(sizes)/sizeof(int), sizes, CV_64FC1);
   
  CV_Assert(m3.dims == sizeof(sizes)/sizeof(sizes[0]));
  CV_Assert(m3.rows == -1); // 3次元以上のMatでは，
  CV_Assert(m3.cols == -1); // 常にrows==cols==-1
  
  std::cout << "mat3"<< std::endl;
  std::cout << "  dims: " << m3.dims << ", depth(byte/channel):" << m3.elemSize1() \
	    << ", channels: " << m3.channels() << std::endl;
}
