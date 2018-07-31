//g++ -o write_movie_flip write_movie_flip.cpp `pkg-config --cflags opencv` `pkg-config --libs opencv`

#include "opencv2/opencv.hpp"
#include <opencv2/core.hpp>
#include <opencv2/videoio.hpp>
#include <string>
#include <iostream>

using namespace std;
using namespace cv;

int main(){

  string target = "../../img/shibuya.mp4";
  string result = "shibuya_fliped.avi";

  VideoCapture cap(target);
  // Check if camera opened successfully
  if(!cap.isOpened()){
    cout << "Error opening video stream or file" << endl;
    return -1;
  }

  int frame_width = cap.get(CV_CAP_PROP_FRAME_WIDTH);
  int frame_height = cap.get(CV_CAP_PROP_FRAME_HEIGHT);
  VideoWriter video(result, CV_FOURCC('M','J','P','G'),30, Size(frame_width,frame_height));
  int count = 0;

  while(1){

    Mat frame;
    // Capture frame-by-frame
    cap >> frame;
    count = count + 1;
    cout << count << endl;
    // If the frame is empty, break immediately
    if (frame.empty())
      break;

    video.write(frame);
    // imshow( "Frame", frame );

    // Press  ESC on keyboard to exit
    // char c=(char)waitKey(25);
    // if(c==27)
    //   break;
  }

  // When everything done, release the video capture object
  cap.release();
  video.release();

  // Closes all the frames
  destroyAllWindows();

  return 0;
}