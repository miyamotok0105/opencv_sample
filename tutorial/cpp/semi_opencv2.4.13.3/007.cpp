//http://cvwww.ee.ous.ac.jp/semi/opencv#2.1
//パソコンに接続したカメラからの映像の取り込み
//g++ -o 007 007.cpp `pkg-config --cflags opencv` `pkg-config --libs opencv`

#include <opencv2/opencv.hpp>
 
int main(void)
{
    // 映像を取り込むためのオブジェクトを宣言する
    cv::VideoCapture cap;
    cap.open(0);            // カメラ番号を指定する（通常は0）
 
    // カメラに接続できたか調べる
    if (cap.isOpened() == false) {
        printf("カメラに接続できません。\n");
        return -1;
    }
    
    int    width, height;
    double fps;
    width  = (int)cap.get(CV_CAP_PROP_FRAME_WIDTH);    // フレーム横幅を取得
    height = (int)cap.get(CV_CAP_PROP_FRAME_HEIGHT);   // フレーム縦幅を取得
    fps    = cap.get(CV_CAP_PROP_FPS); // フレームレートを取得（取得できないカメラもある）
 
    printf("画像サイズ %dx%d, %ffps\n", width, height, fps);
 
    // 画像を格納するオブジェクトを宣言する
    cv::Mat frame;
 
    for (;;) {
        // 1フレームを取り込む
        cap >> frame;
 
        // 画像から空のとき、無限ループを抜ける
        if (frame.empty() == true) {
            break;
        }
 
        // ウィンドウに画像を表示する
        cv::imshow("inputting...", frame);
 
        // 33ms待つ
        int key = cv::waitKey(33);
        if (key == 0x1b) {
            // ESCキーが押されたら終了する
            break;
        }
    }
 
    return 0;
}