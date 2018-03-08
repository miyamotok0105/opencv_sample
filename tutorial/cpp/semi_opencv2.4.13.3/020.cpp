//http://cvwww.ee.ous.ac.jp/semi/opencv#2.1
//フルカラー画像の画素
//g++ -o 020 020.cpp `pkg-config --cflags opencv` `pkg-config --libs opencv`

#include <opencv2/opencv.hpp>
 
int main(void)
{
    // 画像を格納するオブジェクトを宣言する
    // * Vec3b = 1byte * 3 = 24bit/画素
    cv::Mat_<cv::Vec3b> src, dst1, dst2;
 
    // 画像ファイルから画像データを読み込む
    // * 第2引数に IMREAD_COLOR を指定すると、カラー画像で読み込む
    src = cv::imread("../../../img/hari.jpg", cv::IMREAD_COLOR);
 
    // srcと同じサイズで画像を作成する。
    dst1 = cv::Mat_<cv::Vec3b>(src.size());
    dst2 = cv::Mat_<cv::Vec3b>(src.size());
 
    // 1画素ごとの変換
    for (int y = 0; y < src.rows; y++) {
        for (int x = 0; x < src.cols; x++) {
            // srcの座標(x,y)の画素値を取り出す
            uchar r, g, b;
            b = src(y, x)[0];   // 青成分
            g = src(y, x)[1];   // 緑成分
            r = src(y, x)[2];   // 赤成分
 
            // dst1の座標(x,y)に画素値を書き込む（方法1）
            dst1(y, x)[0] = 0;  // 青成分を0にする
            dst1(y, x)[1] = g;
            dst1(y, x)[2] = r;
 
            // dst2の座標(x,y)に画素値を書き込む（方法2）
            dst2(y, x) = cv::Vec3b(0, g, r);    // 青成分を0にする
        }
    }
 
    cv::imshow("原画像", src);
    cv::imshow("画像dst1", dst1);
    cv::imshow("画像dst2", dst2);
 
    cv::waitKey();
 
    return 0;
}