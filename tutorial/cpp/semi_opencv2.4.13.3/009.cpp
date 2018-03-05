//http://cvwww.ee.ous.ac.jp/semi/opencv#2.1
//輪郭抽出
//g++ -o 009 009.cpp `pkg-config --cflags opencv` `pkg-config --libs opencv`
#include <opencv2/opencv.hpp>
 
int main(void)
{
    // 画像を格納するオブジェクトを宣言する
    cv::Mat src, dst1, dst2, dst3, dst4, dst5, dst6;
 
    // 画像ファイルから画像データを読み込む
    // * 第2引数に IMREAD_GRAYSCALE を指定すると、グレイスケール画像に変換する
    src = cv::imread("../../../img/hari.jpg", cv::IMREAD_GRAYSCALE);
 
    // ラプラシアンフィルタ
    cv::Laplacian(src, dst1, -1);
 
    // Sobelフィルタ
    cv::Sobel(src, dst2, -1, 1, 0);     // x方向
    cv::Sobel(src, dst3, -1, 0, 1);     // y方向
 
    // Cannyフィルタ
    cv::Canny(src, dst4, 60.0, 150.0);
    
    // ウィンドウに画像を表示する
    cv::imshow("原画像", src);
    cv::imshow("ラプラシアンフィルタ", dst1);
    cv::imshow("Sobelフィルタ x方向", dst2);
    cv::imshow("Sobelフィルタ y方向", dst3);
    cv::imshow("Cannyフィルタ", dst4);
    
    cv::waitKey();
 
    return 0;
}
