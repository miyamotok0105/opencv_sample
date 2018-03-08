//http://cvwww.ee.ous.ac.jp/semi/opencv#2.1
//warpAffine関数によるアフィン変換
//g++ -o 025 025.cpp `pkg-config --cflags opencv` `pkg-config --libs opencv`

#include <opencv2/opencv.hpp>
 
int main(void)
{
    cv::Mat src, dst;
 
    src = cv::imread("../../../img/hari.jpg");
 
    // アフィン変換行列(2行3列）
    cv::Mat affine = (cv::Mat_<double>(2, 3) << 0.8, 0, 0, 0, 1.5, 0);
 
    // アフィン変換
    // * warpAffine(原画像, 変換後画像, 変換後画像サイズ, 補間方法)
    // * INTER_LINEAR  線形補間（バイリニア）
    //   INTER_NEAREST 再近傍補間
    //   INTER_CUBIC   バイキュービック補間
    //   INTER_LANCZOS4 Lanczos（ランチョス）補間
    cv::warpAffine(src, dst, affine, src.size(), cv::INTER_LINEAR);
 
    cv::imshow("原画像", src);
    cv::imshow("変換後画像", dst);
 
    cv::waitKey();
 
    return 0;
}


