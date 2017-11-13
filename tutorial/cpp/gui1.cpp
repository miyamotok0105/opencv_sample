#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

//g++ -o gui1 gui1.cpp `pkg-config --cflags opencv` `pkg-config --libs opencv`
//http://opencv.jp/cookbook/opencv_io.html#id1

int
main(int argc, char *argv[])
{
  cv::Mat src_img = cv::imread("../../img/hari.jpg", 1);
  if(src_img.empty()) return -1;

  /// 画像を表示するウィンドウ
  // ウィンドウの名前，プロパティ
  // CV_WINDOW_AUTOSIZE : ウィンドウサイズを画像サイズに合わせる
  // CV_WINDOW_FREERATIO : ウィンドウのアスペクト比を固定しない
  cv::namedWindow("image1", CV_WINDOW_AUTOSIZE|CV_WINDOW_FREERATIO);
  // ウィンドウ名でウィンドウを指定して，そこに画像を描画
  cv::imshow("image1", src_img);
   
  // デフォルトのプロパティで表示
  cv::imshow("image2", src_img);

  // キー入力を（無限に）待つ
  cv::waitKey(0);
}