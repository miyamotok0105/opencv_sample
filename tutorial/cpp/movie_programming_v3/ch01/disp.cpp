//g++ -o disp disp.cpp `pkg-config --cflags opencv` `pkg-config --libs opencv`

#include <opencv2/opencv.hpp>

int main() {
    
  try
  {
    const std::string input = "camera";

    cv::VideoCapture capture(0);
    if(!capture.isOpened())
      throw "camera not found!";
          
    cv::Mat src;
    cv::namedWindow(input, cv::WINDOW_AUTOSIZE);

    while(true)
    {
      capture >> src;
      if(src.empty()) break;
      cv::imshow(input, src);

      if(cv::waitKey(1) >= 0) break;
    }
    cv::destroyWindow(input);
  }
  catch(const char* str)
  {
    std::cerr << str << std::endl;
  }

  return 0;
}
