//http://cvwww.ee.ous.ac.jp/semi/opencv#2.1
//動画像の変換とファイル保存
//g++ -o 006 006.cpp `pkg-config --cflags opencv` `pkg-config --libs opencv`

#include <opencv2/opencv.hpp>
#include "opencv2/video/video.hpp"
#include <opencv2/highgui/highgui.hpp>
#include <iostream>
#include <stdio.h>

using namespace cv;
using namespace std;


int main(void)
{
    // 動画ファイルを取り込むためのオブジェクトを宣言する
    cv::VideoCapture cap;
    cap.open("../../../img/shibuya.mp4");
 
    // 動画ファイルが開けたか調べる
    if (cap.isOpened() == false) {
        printf("ファイルが開けません。\n");
        return -1;
    }
 
    // 作成する動画ファイルの諸設定
    int    fourcc, width, height;
    double fps;
 
    width  = (int)cap.get(CV_CAP_PROP_FRAME_WIDTH);    // フレーム横幅を取得
    height = (int)cap.get(CV_CAP_PROP_FRAME_HEIGHT);   // フレーム縦幅を取得
    fps    = cap.get(CV_CAP_PROP_FPS);                 // フレームレートを取得
    // fourcc = CV_FOURCC('M', 'P', '4', 'V');   // 形式を指定
    fourcc = CV_FOURCC('m','p','e','g');
    // * エンコード形式 "XVID" = AVI, "MP4V" = MPEG4, "WMV1" = WMV
 
    // 動画ファイルを書き出すためのオブジェクトを宣言する
    VideoWriter writer;
    writer.open("shibuyaNew.mp4", fourcc, fps, cv::Size(width, height));
    
    // 画像を格納するオブジェクトを宣言する
    cv::Mat frame, dst;
 
    for (;;) {
        // 1フレームを取り込む
        cap >> frame;               // cap から frame へ
 
        // 画像から空のとき、無限ループを抜ける
        if (frame.empty() == true) {
            break;
        }
 
        // ウィンドウに画像を表示する
        cv::imshow("changing...", frame);
 
        // 画像処理（画像を反転）
        cv::flip(frame, dst, 1);
 
        // 動画ファイルへ書き出す
        writer << dst;              // dst から writer へ
 
        // 1ms待つ
        cv::waitKey(1);
    }
 
    return 0;
}
