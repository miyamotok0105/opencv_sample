//g++ -o disp2 disp2.cpp `pkg-config --cflags opencv` `pkg-config --libs opencv`
//./disp2 ../../../../img/shibuya.mp4

#include "../Common.h"


int main(int argc, char* argv[]) 
{
    
  try
  {
    string input = "camera";
    int wait = 1;
    VideoCapture capture;

    if(argc == 2)
    {
      input = argv[1];
      capture = VideoCapture(input);
      //33fpsと仮定している。
      wait = 33;
    }
    else
    {
      capture = VideoCapture(0);
    }
    
    Mat src;
    namedWindow(input, WINDOW_AUTOSIZE);

    while(true)
    {
      capture >> src;
      if(src.empty()) break;
      imshow(input, src);

      if(waitKey(wait) >= 0) break;
    }
    destroyWindow(input);
  }
  catch(const char* str)
  {
    cerr << str << endl;
  }

  return 0;
}
