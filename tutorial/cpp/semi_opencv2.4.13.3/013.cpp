//http://cvwww.ee.ous.ac.jp/semi/opencv#2.1
//基本図形の描画
//g++ -o 013 013.cpp `pkg-config --cflags opencv` `pkg-config --libs opencv`

#include <opencv2/opencv.hpp>
#include "opencv2/imgproc/imgproc.hpp"

int main(void)
{
    // 画像を格納するオブジェクトを宣言する
    // * CV_8UC3 : 8bit 3channel = カラー画像
    cv::Mat image(400, 400, CV_8UC3);
 
    // 画像を白色で塗りつぶす
    // * Scalar(Blue, Green, Red)  RGB順ではないことに注意
    image = cv::Scalar(255, 255, 255);
 
    // 線を引く
    // * line(画像, 始点座標, 終点座標, 色, 線幅, 連結)
    cv::line(image, cv::Point(10, 10), cv::Point(390, 30), cv::Scalar(255, 0, 0), 1, 4);
    cv::line(image, cv::Point(10, 20), cv::Point(390, 40), cv::Scalar(255, 0, 0), 1, 8);
    cv::line(image, cv::Point(10, 30), cv::Point(390, 50), cv::Scalar(255, 0, 0), 1, CV_AA);
 
    // 四角形を描く
    // * rectangle(画像, 四角形, 色, 線幅, 連結)
    // * 線幅 < 0 のときは四角形内を塗りつぶす
    cv::rectangle(image, cv::Rect(10,  60, 100, 100), cv::Scalar(0, 255, 0),  1, CV_AA);
    cv::rectangle(image, cv::Rect(120, 60, 100, 100), cv::Scalar(0, 255, 0), -1, CV_AA);
 
    // 円を描く
    // * circlee(画像, 中心座標, 半径, 色, 線幅, 連結)
    cv::circle(image, cv::Point(60,  230), 50, cv::Scalar(0, 0, 255),  1, CV_AA);
    cv::circle(image, cv::Point(170, 230), 50, cv::Scalar(0, 0, 255), -1, CV_AA);
 
    // 楕円を描く
    // * RotatedRect(中心座標, サイズ(x, y), 回転角度degree)
    // * ellipse(画像, RotatedRect, 色, 線幅, 連結)
    cv::RotatedRect rrect(cv::Point2f(60, 340), cv::Size(100, 50), 30);
    cv::ellipse(image, rrect, cv::Scalar(255, 0, 255), 1, CV_AA);
 
    // 円弧を描く
    // * RotatedRect(中心座標, サイズ(x, y), 回転角度degree)
    // * ellipse(画像, 中心座標, Size(x径, y径), 楕円の回転角度, 始点角度, 終点角度, 色, 線幅, 連結)
    cv::ellipse(image, cv::Point(170, 340), cv::Size(50, 50), 0, 30, 180, cv::Scalar(255, 0, 255),  1, CV_AA);
    cv::ellipse(image, cv::Point(280, 340), cv::Size(50, 50), 0, 30, 180, cv::Scalar(255, 0, 255), -1, CV_AA);
 
    cv::imshow("画像", image);
 
    cv::waitKey();
 
    return 0;
}