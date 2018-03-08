//http://cvwww.ee.ous.ac.jp/semi/opencv#2.1
//立方体の面への画像の貼り付け
//g++ -o 028 028.cpp `pkg-config --cflags opencv` `pkg-config --libs opencv` -std=c++11

#include <opencv2/opencv.hpp>
 
int main(void)
{
    cv::Mat src, dst;
 
    src = cv::imread("../../../img/hari.jpg");
 
    // 射影変換行列
    cv::Mat homography1, homography2, homography3;
 
    // 対応点の設定
    float w = src.cols - 1, h = src.rows - 1;
    cv::Point2f srcPoint[4] = { { 0, 0 },{ w, 0 },{ w, h },{ 0, h } };
    cv::Point2f dstPoint1[4] = { { 25, 100 },{ 230, 45 },{ 362, 60 },{ 195, 150 } };
    cv::Point2f dstPoint2[4] = { { 25, 100 },{ 195, 150 },{ 225, 370 },{ 85, 285 } };
    cv::Point2f dstPoint3[4] = { { 195, 150 },{ 362, 60 },{ 350, 215 },{ 225, 370 } };
 
 
    // 対応点から射影変換行列を求める（srcPoint → dstPoint1）
    homography1 = cv::getPerspectiveTransform(srcPoint, dstPoint1);
    homography2 = cv::getPerspectiveTransform(srcPoint, dstPoint2);
    homography3 = cv::getPerspectiveTransform(srcPoint, dstPoint3);
 
    // 射影変換
    // * BORDER_TRANSPARENT  変換後画像を初期化しないで上書きする
    cv::warpPerspective(src, dst, homography1, cv::Size(400, 400), cv::INTER_LINEAR);
    cv::warpPerspective(src, dst, homography2, cv::Size(400, 400), cv::INTER_LINEAR, cv::BORDER_TRANSPARENT);
    cv::warpPerspective(src, dst, homography3, cv::Size(400, 400), cv::INTER_LINEAR, cv::BORDER_TRANSPARENT);
 
    // 立方体の辺を描く
    for (int i = 0; i < 4; i++) {
        cv::line(dst, dstPoint1[i], dstPoint1[(i + 1) & 3], cv::Scalar::all(255), 1, CV_AA);
        cv::line(dst, dstPoint2[i], dstPoint2[(i + 1) & 3], cv::Scalar::all(255), 1, CV_AA);
        cv::line(dst, dstPoint3[i], dstPoint3[(i + 1) & 3], cv::Scalar::all(255), 1, CV_AA);
    }
 
    cv::imshow("原画像", src);
    cv::imshow("立方体へのマッピング", dst);
 
    cv::waitKey();
 
    return 0;
}


