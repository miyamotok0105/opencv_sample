//http://cvwww.ee.ous.ac.jp/semi/opencv#2.1
//行列の宣言と表示
//g++ -o 015 015.cpp `pkg-config --cflags opencv` `pkg-config --libs opencv`

#include <opencv2/opencv.hpp>
 
using namespace std;
 
int main(void)
{
    // 空の行列を宣言する
    cv::Mat mat1;
 
    // 大きさと型を指定して行列を宣言する（2行3列、float型）
    // * Debug: 初期化しない, Relese: 0で初期化
    cv::Mat_<float> mat2(2, 3);             // 方法1
    cv::Mat         mat3(2, 3, CV_32F);     // 方法2
 
    // 行列の宣言と初期値の代入をする
    cv::Mat mat4 = (cv::Mat_<float>(2, 3) << 1, 2, 3, 4, 5, 6);
 
    // 行列を表示する
    // * cout の使い方はC++の文法書を参照のこと
    cout << mat1 << endl;
    cout << mat3 << endl;
    cout << mat2 << endl;
    cout << mat4 << endl;
 
    // 行列の大きさを表示する
    printf("行数=%d, 列数=%d\n", mat2.rows, mat2.cols);
 
    return 0;
}