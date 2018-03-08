//http://cvwww.ee.ous.ac.jp/semi/opencv#2.1
//warpPerspective関数による射影変換
//g++ -o 027 027.cpp `pkg-config --cflags opencv` `pkg-config --libs opencv` -std=c++11

#include <opencv2/opencv.hpp>
 
int main(void)
{
    cv::Mat src, dst;
 
    src = cv::imread("../../../img/hari.jpg");
 
    // ホモグラフィ行列(3行3列）
    cv::Mat homography = (cv::Mat_<double>(3, 3) << 0.8, -0.2, 180, 0.4, 0.9, 40, 0.001, 0.0001, 1);
 
    // 射影変換
    cv::warpPerspective(src, dst, homography, src.size(), cv::INTER_LINEAR);
 
    cv::imshow("原画像", src);
    cv::imshow("変換後画像", dst);
 
    cv::waitKey();
 
    return 0;
}


