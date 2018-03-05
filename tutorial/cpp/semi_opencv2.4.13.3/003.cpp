//http://cvwww.ee.ous.ac.jp/semi/opencv#2.1
//画像の反転
//g++ -o 003 003.cpp `pkg-config --cflags opencv` `pkg-config --libs opencv`
#include <opencv2/opencv.hpp>
 
int main(void)
{
    // 画像を格納するオブジェクトを宣言する
    cv::Mat src, dst;
 
    // 画像ファイルから画像データを読み込む
    src = cv::imread("../../../img/hari.jpg");
 
    // 画像を反転する
    // * 0:上下反転, 1:左右反転
    cv::flip(src, dst, 0);
    
    // ウィンドウに画像を表示する
    cv::imshow("原画像",   src);
    cv::imshow("反転画像", dst);
 
    // 何かキーが押されるまで待つ
    cv::waitKey();
 
    return 0;
}