
//g++ -o cameraCapture cameraCapture.cpp `pkg-config --cflags opencv` `pkg-config --libs opencv`
//g++ -std=c++11 -o cameraCapture cameraCapture.cpp `pkg-config --cflags opencv` `pkg-config --libs opencv`
//g++ --version
//./cameraCapture

#include <opencv2/opencv.hpp>
#include <iostream>
#include <stdio.h>
using namespace std;
using namespace cv;

void detectAndDisplay( Mat frame );
String window_name = "Capture ";

int main( int argc, const char** argv )
{
    VideoCapture capture;
    Mat frame;
    capture.open( 0 );
    if ( ! capture.isOpened() ) { printf("--(!)Error opening video capture\n"); return -1; }

    while ( capture.read(frame) )
    {
        if( frame.empty() )
        {
            printf(" --(!) No captured frame -- Break!");
            break;
        }
        detectAndDisplay( frame );
        char c = (char)waitKey(10);
        if( c == 27 ) { break; } // escape
    }
    return 0;
}

void detectAndDisplay( Mat frame )
{
    imshow( window_name, frame );
}
