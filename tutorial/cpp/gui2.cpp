#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

//g++ -o gui2 gui2.cpp `pkg-config --cflags opencv` `pkg-config --libs opencv`
//http://opencv.jp/cookbook/opencv_io.html#id1

int
main(int argc, char *argv[])
{
  cv::VideoCapture cap(0);
  // 様々な設定...
  cap.set(CV_CAP_PROP_FRAME_WIDTH, 640);
  cap.set(CV_CAP_PROP_FRAME_HEIGHT, 480);
  // カメラがオープンできたかの確認
  if(!cap.isOpened()) return -1;

  cv::namedWindow("Capture", CV_WINDOW_AUTOSIZE|CV_WINDOW_FREERATIO);
  while(1) {
    cv::Mat frame;
    cap >> frame;  // キャプチャ
    // 様々な処理
    // ...
    cv::imshow("Capture", frame); // 表示
    if(cv::waitKey(3) >= 0)
    {
      // cv::imwrite("cap.png", frame);
      break;
    }
  }
}

