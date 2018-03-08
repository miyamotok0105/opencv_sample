//http://cvwww.ee.ous.ac.jp/semi/opencv#2.1
//連立方程式の解
//g++ -o 018 018.cpp `pkg-config --cflags opencv` `pkg-config --libs opencv`

#include <opencv2/opencv.hpp>
 
using namespace std;
 
int main(void)
{
    // 零行列を宣言する
    cv::Mat mat1 = cv::Mat::zeros(3, 3, CV_32F);
 
    // 単位行列を宣言する
    cv::Mat mat2 = cv::Mat::eye(3, 3, CV_32F);
 
    // 全要素が1の行列を宣言する
    // * Mat mat3(3, 3, CV_32F) で宣言後、mat3 = 1 としても全要素を1にできる
    cv::Mat mat3 = cv::Mat::ones(3, 3, CV_32F);
 
    cout << "mat1=\n" << mat1 << endl;
    cout << "mat2=\n" << mat2 << endl;
    cout << "mat3=\n" << mat3 << endl;
 
 
    // 連立1次方程式を解く
    
    // 2変数の連立1次方程式
    //    x + 2y = 5
    //   3x -  y = 8 を解く
 
    // 左辺と右辺の値
    cv::Mat lhand = (cv::Mat_<float>(2, 2) << 1, 2, 3, -1);
    cv::Mat rhand = (cv::Mat_<float>(2, 1) << 5, 8);
    cv::Mat ans;
 
    // 逆行列を計算して解く
    ans = lhand.inv() * rhand;
    cout << "ans=\n" << ans << endl;
    
    // solve関数を用いて解く
    // * solveは、パラメータ数と方程式の数とが違う問題（優決定、劣決定）も解くことができる
    cv::solve(lhand, rhand, ans);
    cout << "ans=\n" << ans << endl;
 
    return 0;
}