//http://cvwww.ee.ous.ac.jp/semi/opencv#2.1
//簡単な動画再生ソフト
//g++ -o 005 005.cpp `pkg-config --cflags opencv` `pkg-config --libs opencv`

#include <opencv2/opencv.hpp>
#include <iostream>
#include <sstream>
#include <iomanip>

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
 
    // 画像を格納するオブジェクトを宣言する
    cv::Mat frame;
 
    for (;;) {
        // 1フレームを取り込む
        cap >> frame;               // cap から frame へ
 
        // 画像から空のとき、無限ループを抜ける
        if (frame.empty() == true) {
            break;
        }
 
        // ウィンドウに画像を表示する
        cv::imshow("再生中", frame);
 
        // 33ms待つ
        // キー入力されたらkeyへ文字コードを代入する
        int key = cv::waitKey(33);
 
        // 現在のフレーム番号（先頭から何フレーム目か）を表示する
        int n = (int)cap.get(CV_CAP_PROP_POS_FRAMES);  // フレームの位置を取得
        int m = (int)cap.get(CV_CAP_PROP_FRAME_COUNT); // 全フレーム数を取得
        printf("フレーム %4d/%d\r", n, m);
        
        if (key == ' ') {           // スペースキーが押されたら一時停止する
            printf("\n一時停止\n");
            cv::waitKey();
        
        } else if (key == 'r') {    // Rキーが押されたら先頭から再生しなおす
            printf("\n巻き戻し\n");
            cap.set(CV_CAP_PROP_POS_FRAMES, 0);  // フレームの位置を0に設定
 
        } else if (key == 's') {    // Sキーが押されたら30フレームスキップする
            printf("\nスキップ\n");
            cap.set(CV_CAP_PROP_POS_FRAMES, n + 30);   // n+30に設定
 
        } else if (key == 0x1b) {   // ESCキーが押されたら終了する
            break;
        }
    }
 
    return 0;
}