//http://cvwww.ee.ous.ac.jp/semi/opencv#2.1
//画像の色変換とファイル保存
//g++ -o 002 002.cpp `pkg-config --cflags opencv` `pkg-config --libs opencv`
#include <opencv2/opencv.hpp>
 
int main(void)
{
    // 画像を格納するオブジェクトを宣言する
    cv::Mat src, dst;
 
    // 画像ファイルから画像データを読み込む
    src = cv::imread("../../../img/hari.jpg");
 
    // グレイスケール画像に変換する
    // * カラーはBGR順である（RGBではない）ことに注意
    cv::cvtColor(src, dst, cv::COLOR_BGR2GRAY);
 
    // ウィンドウに画像を表示する
    cv::imshow("原画像",   src);
    cv::imshow("変換画像", dst);
 
    // 画像を保存する
    // * ファイルフォーマットは拡張子で自動判別される
    cv::imwrite("変換画像.jpg", dst);
 
    // 何かキーが押されるまで待つ
    cv::waitKey();
 
    return 0;
}