#include "opencv2/opencv.hpp"

#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::endl;

//g++ -o parser parser.cpp `pkg-config --cflags opencv` `pkg-config --libs opencv`
// ./parser --a=20

void help()
{
  cout << endl
       << "OpenCV command-line parser test." << endl
       << "Call:" << endl
       << "./parser -b -i=2 -f=5.3 str1str in3val" << endl
       << endl;
}

const char* keys = 
{
  //  keys  //
  //  "{short tag|long tag|default value|notification}"  //
  "{1|||sample string without option tag}"
  "{2||-100|sample int without option tag}"
  "{b|bool|false|sample boolean}"
  "{i|int|0|sample int}"
  "{f|float|0.0|sample float}"
  "{a|10|20|}"
};

int main( int argc, const char** argv )
{
  //help();

  //  parser  //
  cv::CommandLineParser parser(argc, argv, keys);

  //  without 
  string str_1 = parser.get<string>("1");
  int   in_2 = parser.get<int>("2");
  //  value as corresponding type  //
  bool  bo_b = parser.get<bool>("b");
  int   in_i = parser.get<int>("i");
  float fl_f = parser.get<float>("f");
  //  value as string  //
  string str_b = parser.get<string>("b");
  //string str_i = parser.get<string>("i");
  //string str_f = parser.get<string>("f");
  int   in_a = parser.get<int>("a");

  cout << "str_1 = " << str_1 << endl;
  cout << "in_2 = " << in_2 << endl;

  cout << "bo_b = " << bo_b << endl;
  cout << "in_i = " << in_i << endl;
  cout << "fl_f = " << fl_f << endl;

  cout << "str_b = " << str_b << endl;
  cout << "in_a = " << in_a << endl;
  //cout << "str_i = " << str_i << endl;
  //cout << "str_f = " << str_f << endl;

  return 0;
}