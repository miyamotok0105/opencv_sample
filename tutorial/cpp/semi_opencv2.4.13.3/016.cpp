//http://cvwww.ee.ous.ac.jp/semi/opencv#2.1
//行列の浅いコピー、深いコピー
//g++ -o 016 016.cpp `pkg-config --cflags opencv` `pkg-config --libs opencv`

#include <opencv2/opencv.hpp>
 
using namespace std;
 
int main(void)
{
    // 行列を宣言する
    cv::Mat mat1 = (cv::Mat_<float>(3, 3) << 1, 2, 3, 4, 5, 6, 7, 8, 9);
 
    // 行と列を指定して要素の値を読み出す
    // * 行列の要素は0行0列目から始まる
    float x = mat1.at<float>(1, 2);
    cout << "mat1(1, 2)=" << x << endl;
 
    // 行と列を指定して値を代入する
    mat1.at<float>(0, 2) = 99;
    cout << "mat1=\n" << mat1 << endl;
 
 
    cv::Mat mat2, mat3;
    
    // 行列の浅いコピー
    // * mat2は、mat1と同じ記憶域のデータを指す
    mat2 = mat1;
    
    // 行列の深いコピー
    // * mat1の複製を作り、それをmat3へ代入する
    // * mat1.copyTo(mat3) でも可。
    mat3 = mat1.clone();
 
    // mat1のデータを変えてみる
    mat1 = mat1.t();
 
    cout << "変更後のmat1=\n" << mat1 << endl;
    cout << "mat2=\n" << mat2 << endl;          // mat2は変更後のmat1と同じ
    cout << "mat3=\n" << mat3 << endl;          // mat3は変更前のmat1と同じ
    
    return 0;
}