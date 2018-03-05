//http://cvwww.ee.ous.ac.jp/semi/opencv#2.1
//動画ファイルの読み込みと動画の表示
//g++ -o 004 004.cpp `pkg-config --cflags opencv` `pkg-config --libs opencv`
#include <opencv2/opencv.hpp>
 
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
        // * 引数にキー入力の待ち時間を指定できる。（ミリ秒単位）
        // * 引数が 0 または何も書かない場合、キー入力があるまで待ち続ける
        cv::waitKey(33);
    }
 
    return 0;
}