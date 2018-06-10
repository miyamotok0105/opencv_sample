// Example 2-2. Same as Example 2-1 but employing the “using namespace” directive
//g++ -o example_02-02 example_02-02.cpp `pkg-config --cflags opencv` `pkg-config --libs opencv`
//gcc -v example_02-02.cpp -I/usr/local/include/ -L/usr/lib/ -lstdc++ -L/usr/local/lib -lopencv_highgui -lopencv_core -o example_02-02
//g++ -I/usr/local/Cellar/opencv/3.4.1_5/include/opencv2 example_02-02.cpp -o example_02-02

#include "opencv2/highgui/highgui.hpp"
#include <iostream>

//cv名前空間を省略
using namespace cv;

void help(char** argv ) {
    std::cout << "\n"
    << "2.2: Like 2.1, but 'using namespace cv: \n"
    << argv[0] <<" <path/image>\n"
    << "For example:\n"
    << argv[0] << " ../fruits.jpg\n"
    << std::endl;
}
    

int main( int argc, char** argv ) {
    
    if (argc != 2) {
        help(argv);
        return 0;
    }

  Mat img = imread( argv[1], -1 );

  if( img.empty() ) return -1;

  namedWindow( "Example 2-2", cv::WINDOW_AUTOSIZE );

  imshow( "Example 2-2", img );

  waitKey( 0 );

  destroyWindow( "Example 2-2" );
}


