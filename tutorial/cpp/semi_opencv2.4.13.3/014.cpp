//http://cvwww.ee.ous.ac.jp/semi/opencv#2.1
//テキストの描画
//g++ -o 014 014.cpp `pkg-config --cflags opencv` `pkg-config --libs opencv` -std=c++11

//初期化リスト（initializer list）や統一初期化記法（uniform initialization）はC++11以降のコンパイラである必要がある。
#include <opencv2/opencv.hpp>
#include <string>
#include <vector>
 
int main(void)
{
    // 画像を格納するオブジェクトを宣言する
    // * CV_8UC3 : 8bit 3channel = カラー画像
    cv::Mat image(400, 400, CV_8UC3);
 
    // 画像を白色で塗りつぶす
    // * Scalar(Blue, Green, Red)  RGB順ではないことに注意
    image = cv::Scalar(255, 255, 255);
 
    // 文字を描く
    // * putText(画像, "文字列", 座標, フォント, スケール, 色, 線幅, 連結)
    cv::putText(image, "Sample Text", cv::Point(10, 40), cv::FONT_HERSHEY_SIMPLEX, 1.0, cv::Scalar(255, 0, 0), 2, CV_AA);
 
    // ベースラインの位置を描く
    cv::line(image, cv::Point(10, 40), cv::Point(390, 40), cv::Scalar(0, 0, 255), 1, 4);
 
    // フォントの一覧を表示
    std::vector<std::string> font{
        "SIMPLEX", "PLAIN", "DUPLEX", "COMPLEX", "TRIPLEX", "COMPLEX_SMALL", "SCRIPT_SIMPLEX", "SCRIPT_COMPLEX"
    };
    for(int i = 0; i < font.size(); i++) {
        cv::putText(image, "FONT_HERSHEY_" + font[i], cv::Point(10, i * 40 + 80), i, 0.6, cv::Scalar::all(0), 1, CV_AA);
    }
 
    cv::imshow("画像", image);
 
    cv::waitKey();
 
    return 0;
}