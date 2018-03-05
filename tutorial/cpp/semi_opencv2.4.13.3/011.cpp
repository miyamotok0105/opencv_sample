//http://cvwww.ee.ous.ac.jp/semi/opencv#2.1
//2値化
//g++ -o 011 011.cpp `pkg-config --cflags opencv` `pkg-config --libs opencv`
#include <opencv2/opencv.hpp>
 
int main(void)
{
    // 画像を格納するオブジェクトを宣言する
    cv::Mat src, dst1, dst2, dst3, dst4;
 
    // 画像ファイルから画像データを読み込む
    // * 第2引数に IMREAD_GRAYSCALE を指定すると、グレイスケール画像に変換する
    src = cv::imread("../../../img/hari.jpg", cv::IMREAD_GRAYSCALE);
 
    // 2値化処理
    // * 2値化閾値 = 140, 変換後の最大値 = 255
    cv::threshold(src, dst1, 140, 255, cv::THRESH_BINARY);
 
    // 2値化処理（判別分析2値化法（大津の方法））
    // * 最適な閾値を自動的に算出する
    cv::threshold(src, dst2, 0, 255, cv::THRESH_OTSU);
 
    // 膨張処理（最大値フィルタ）
    cv::dilate(dst2, dst3, cv::Mat());
 
    // 収縮処理（最小値フィルタ）
    cv::erode(dst2, dst4, cv::Mat());
 
    cv::imshow("原画像", src);
    cv::imshow("2値化処理", dst1);
    cv::imshow("2値化処理（大津の方法）", dst2);
    cv::imshow("膨張処理", dst3);
    cv::imshow("収縮処理", dst4);
 
    cv::waitKey();
 
    return 0;
}