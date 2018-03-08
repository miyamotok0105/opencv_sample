//http://cvwww.ee.ous.ac.jp/semi/opencv#2.1
//グレイスケール画像の画素
//g++ -o 019 019.cpp `pkg-config --cflags opencv` `pkg-config --libs opencv`

#include <opencv2/opencv.hpp>
 
int main(void)
{
    // 画像を格納するオブジェクトを宣言する
    // * uchar = unsigned char = 8bit/画素
    cv::Mat_<uchar> src, dst1, dst2;
 
    // 画像ファイルから画像データを読み込む
    // * 第2引数に IMREAD_GRAYSCALE を指定すると、グレイスケール画像に変換する
    src = cv::imread("../../../img/hari.jpg", cv::IMREAD_GRAYSCALE);
 
    // srcと同じサイズで画像を作成する。
    dst1 = cv::Mat_<uchar>(src.size());
    dst2 = cv::Mat_<uchar>(src.size());
 
    // 1画素ごとの変換
    for (int y = 0; y < src.rows; y++) {
        for (int x = 0; x < src.cols; x++) {
            // srcの座標(x,y)の画素値を取り出す
            uchar value = src(y, x);
 
            // dst1の座標(x,y)に画素値を書き込む
            dst1(y, x) = 255 - value;
 
            // dst2の座標(x,src.rows-y-1)に画素値を書き込む
            dst2(src.rows - y - 1, x) = value;
        }
    }
    
    cv::imshow("原画像", src);
    cv::imshow("画像dst1", dst1);
    cv::imshow("画像dst2", dst2);
 
    cv::waitKey();
 
    return 0;
}