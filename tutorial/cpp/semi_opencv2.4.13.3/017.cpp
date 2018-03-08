//http://cvwww.ee.ous.ac.jp/semi/opencv#2.1
//行列の計算
//g++ -o 017 017.cpp `pkg-config --cflags opencv` `pkg-config --libs opencv`

#include <opencv2/opencv.hpp>
 
using namespace std;
 
int main(void)
{
    // 行列を宣言する
    cv::Mat mat1 = (cv::Mat_<float>(2, 2) << 1, 2, 3, 4);
    cv::Mat mat2 = (cv::Mat_<float>(2, 2) << 1, 3, 4, 2);
    cv::Mat mat3, mat4, mat5, mat6, mat7;
 
    cout << "mat1=\n" << mat1 << endl;
    cout << "mat2=\n" << mat2 << endl;
 
    // 行列の和
    mat3 = mat1 + mat2;
    cout << "mat1+mat2=\n" << mat3 << endl;
 
    // 行列の積
    mat4 = mat1 * mat2;
    cout << "mat1*mat2=\n" << mat4 << endl;
 
    // 定数の乗算
    mat5 = mat1 * 2;
    cout << "mat1*2=\n" << mat5 << endl;
 
    // 転置行列
    mat6 = mat1.t();
    cout << "mat1.t()=\n" << mat6 << endl;
 
    // 逆行列
    mat7 = mat1.inv();
    cout << "mat1.inv()=\n" << mat7 << endl;
 
    // 行列式
    double det = cv::determinant(mat1);
    cout << "det(mat1)=" << det << endl;
    
    return 0;
}