//http://cvwww.ee.ous.ac.jp/semi/opencv#2.1
//平滑化
//g++ -o 008 008.cpp `pkg-config --cflags opencv` `pkg-config --libs opencv`

#include <opencv2/opencv.hpp>
 
int main(void)
{
    // 画像を格納するオブジェクトを宣言する
    cv::Mat src, dst1, dst2, dst3, dst4;
 
    // 画像ファイルから画像データを読み込む
    src = cv::imread("../../../img/hari.jpg");
 
    // 平均値フィルタ
    // * Size(x, y)でx方向、y方向のフィルタサイズを指定する
    cv::blur(src, dst1, cv::Size(7, 7));
 
    // 中央値フィルタ
    cv::medianBlur(src, dst2, 7);
 
    // ガウシアンフィルタ
    // * Size(x, y)でx方向、y方向のフィルタサイズを指定する
    cv::GaussianBlur(src, dst3, cv::Size(7, 7), 0.0);
 
    // バイラテラルフィルタ
    cv::bilateralFilter(src, dst4, 20, 200, 20);
 
    // ウィンドウに画像を表示する
    cv::imshow("原画像", src);
    cv::imshow("平均値フィルタ", dst1);
    cv::imshow("中央値フィルタ", dst2);
    cv::imshow("ガウシアンフィルタ", dst3);
    cv::imshow("バイラテラルフィルタ", dst4);
 
    cv::waitKey();
 
    return 0;
}