//http://cvwww.ee.ous.ac.jp/semi/opencv#2.1
//アフィン変換とバイリニア補間
//g++ -o 024 024.cpp `pkg-config --cflags opencv` `pkg-config --libs opencv`

#include <opencv2/opencv.hpp>
 
int main(void)
{
    // 画像を格納するオブジェクトを宣言する
    cv::Mat_<uchar> src, dst1, dst2;
 
    // 画像ファイルから画像データを読み込む
    src = cv::imread("../../../img/hari.jpg", cv::IMREAD_GRAYSCALE);
 
    // srcと同じサイズで画像を作成する。初期値を0にする。
    dst1 = cv::Mat_<uchar>(src.size(), 0);
    dst2 = cv::Mat_<uchar>(src.size(), 0);
 
    // アフィン変換行列
    cv::Mat affine = (cv::Mat_<double>(3, 3) << 3, 0, 0, 0, 1, 0, 0, 0, 1);
 
    cv::Mat_<double> p0(3, 1), p1(3, 1);    // p0:原画像の座標 p1:変換後画像の座標
 
    for (int y = 0; y < dst1.rows; y++) {
        for (int x = 0; x < dst1.cols; x++) {
            int x1, y1, x2, y2;
 
            p1(0, 0) = x;                   // 変換後画像の座標
            p1(1, 0) = y;
 
            // アフィン変換の計算（逆行列を使用）
            p0 = affine.inv() * p1;
 
            x1 = (int)(p0(0, 0) + 0.5);     // 原画像の座標
            y1 = (int)(p0(1, 0) + 0.5);
 
            // バイリニア補間
            double xr, yr;
            x2 = (int)p0(0, 0);             // 原画像の座標
            y2 = (int)p0(1, 0);
            xr = p0(0, 0) - x2;
            yr = p0(1, 0) - y2;
 
            if (x1 >= 0 && x1 < src.cols - 1 && y1 >= 0 && y1 < src.rows - 1) {
                // 最近傍補間
                dst1(y, x) = src(y1, x1);
 
                // バイリニア補間
                dst2(y, x) = (1 - xr)*(1 - yr)*src(y2, x2)    
                           + xr*(1 - yr)      *src(y2, x2 + 1)
                           + (1 - xr)* yr     *src(y2 + 1, x2)
                           + xr* yr           *src(y2 + 1, x2 + 1);
            }
        }
    }
 
    cv::imshow("原画像", src);
    cv::imshow("アフィン変換後画像（最近隣）", dst1);
    cv::imshow("アフィン変換後画像（バイリニア）", dst2);
    cv::waitKey();
 
    return 0;
}

