//http://cvwww.ee.ous.ac.jp/semi/opencv#2.1
//逆変換を使うアフィン変換
//g++ -o 023 023.cpp `pkg-config --cflags opencv` `pkg-config --libs opencv`

#include <opencv2/opencv.hpp>
 
int main(void)
{
    // 画像を格納するオブジェクトを宣言する
    cv::Mat_<uchar> src, dst;
 
    // 画像ファイルから画像データを読み込む
    src = cv::imread("../../../img/hari.jpg", cv::IMREAD_GRAYSCALE);
 
    // srcと同じサイズで画像を作成する。初期値を0にする。
    dst = cv::Mat_<uchar>(src.size(), 0);
 
    // アフィン変換行列
    cv::Mat affine = (cv::Mat_<double>(3, 3) << 0.8, 0, 0, 0, 1.5, 0, 0, 0, 1);
 
    cv::Mat_<double> p0(3, 1), p1(3, 1);    // p0:原画像の座標 p1:変換後画像の座標
 
    for (int y = 0; y < dst.rows; y++) {
        for (int x = 0; x < dst.cols; x++) {
            int x1, y1;
 
            p1(0, 0) = x;                   // 変換後画像の座標
            p1(1, 0) = y;
 
            // アフィン変換の計算（逆行列を使用）
            p0 = affine.inv() * p1;
 
            x1 = (int)(p0(0, 0) + 0.5);     // 原画像の座標
            y1 = (int)(p0(1, 0) + 0.5);
 
            if (x1 >= 0 && x1 < src.cols && y1 >= 0 && y1 < src.rows) {
                // 座標(x1,y1)が原画像の範囲内であれば画素値を設定
                dst(y, x) = src(y1, x1);
            }
        }
    }
 
    cv::imshow("原画像", src);
    cv::imshow("アフィン変換後画像", dst);
    cv::waitKey();
 
    return 0;
}

