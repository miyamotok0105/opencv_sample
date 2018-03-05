//http://cvwww.ee.ous.ac.jp/semi/opencv#2.1
//画像ファイルの読み込みと画像の表示
//g++ -o 001 001.cpp `pkg-config --cflags opencv` `pkg-config --libs opencv`
#include <opencv2/opencv.hpp>
int main(void)
{
    std::cout << "OpenCV version : " << CV_VERSION << std::endl;

    // 画像を格納するオブジェクトを宣言する
    cv::Mat image;
 
    // 画像ファイルから画像データを読み込む
    image = cv::imread("../../../img/hari.jpg");
 
    // 表示するウィンドウを準備する（省略可）
    // ウィンドウにつける名前は自由
    cv::namedWindow("画像");
 
    // ウィンドウに画像を表示する
    cv::imshow("画像", image);
 
    // 何かキーが押されるまで待つ
    cv::waitKey();
 
    return 0;
}