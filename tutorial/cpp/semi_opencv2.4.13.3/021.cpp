//http://cvwww.ee.ous.ac.jp/semi/opencv#2.1
//フィルタリングの計算
//g++ -o 021 021.cpp `pkg-config --cflags opencv` `pkg-config --libs opencv`

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
 
    // 平均値フィルタ
    // 3x3フィルタをかけるので、画像の走査範囲を1画素狭くしている
    for (int y = 1; y < src.rows - 1; y++) {
        for (int x = 1; x < src.cols - 1; x++) { 
            int value;
 
            value = src(y - 1, x - 1) + src(y - 1, x) + src(y - 1, x + 1)
                  + src(y,     x - 1) + src(y,     x) + src(y,     x + 1)
                  + src(y + 1, x - 1) + src(y + 1, x) + src(y + 1, x + 1);
            value /= 9;
            dst1(y, x) = value;
        }
    }
 
    // ラプラシアンフィルタ
    for (int y = 1; y < src.rows - 1; y++) {
        for (int x = 1; x < src.cols - 1; x++) {
            int value;
 
            value =               +   src(y - 1, x)
                  + src(y, x - 1) - 4*src(y,     x) + src(y, x + 1)
                                  +   src(y + 1, x);
 
            value *= 2;             // 画像が見やすくなるように値を大きくする
            value = abs(value);     // 値の絶対値をとる
 
            dst2(y, x) = cv::saturate_cast<uchar>(value);
            // saturate_cast<型>は、型の値域になるように値をまるめる。
            // saturate_cast<uchar>(value)は、value>255 のときvalue=255になり、
            // value<0 のときvalue=0になる。
        }
    }
 
    cv::imshow("原画像", src);
    cv::imshow("平均値フィルタ", dst1);
    cv::imshow("ラプラシアンフィルタ", dst2);
 
    cv::waitKey();
 
    return 0;
}
