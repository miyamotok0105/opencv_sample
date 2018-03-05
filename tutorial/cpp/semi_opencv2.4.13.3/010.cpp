//http://cvwww.ee.ous.ac.jp/semi/opencv#2.1
//濃淡変換
//g++ -o 010 010.cpp `pkg-config --cflags opencv` `pkg-config --libs opencv`
#include <opencv2/opencv.hpp>
 
int main(void)
{
    // 画像を格納するオブジェクトを宣言する
    cv::Mat src, dst1, dst2;
 
    // 画像ファイルから画像データを読み込む
    // * 第2引数に IMREAD_GRAYSCALE を指定すると、グレイスケール画像に変換する
    src = cv::imread("../../../img/hari.jpg", cv::IMREAD_GRAYSCALE);
 
    // ヒストグラム平坦化
    cv::equalizeHist(src, dst1);
 
    // ルックアップテーブルを用いたガンマ補正
    double gamma = 1.5;                                 // ガンマ値
    uchar  lut[256];                                    // ルックアップテーブル用配列
    for (int i = 0; i < 256; i++) {
        lut[i] = pow(i / 255.0, 1 / gamma) * 255.0;     // ガンマ補正式
    }
    cv::LUT(src, cv::Mat(1, 256, CV_8UC1, lut), dst2);  // ルックアップテーブル変換
 
    // ウィンドウに画像を表示する
    cv::imshow("原画像", src);
    cv::imshow("ヒストグラム平坦化", dst1);
    cv::imshow("ガンマ補正", dst2);
 
    cv::waitKey();
 
    return 0;
}
