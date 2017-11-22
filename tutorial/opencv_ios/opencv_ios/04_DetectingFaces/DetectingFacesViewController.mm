//
//  DetectingFacesViewController.m
//  opencv_ios
//
//  Created by USER on 2017/11/22.
//  Copyright © 2017年 USER. All rights reserved.
//

#import "DetectingFacesViewController.h"

@interface DetectingFacesViewController ()

@end

@implementation DetectingFacesViewController

@synthesize imageView;

- (void)viewDidLoad {
    [super viewDidLoad];
    
    // XMLファイルを読み込む
    NSString* cascadePath = [[NSBundle mainBundle]
                             pathForResource:@"haarcascade_frontalface_alt"
                             ofType:@"xml"];
    faceDetector.load([cascadePath UTF8String]);
    
    //顔画像を読み込み
    UIImage* image = [UIImage imageNamed:@"lena.png"];
    cv::Mat faceImage;
    //UIImageToMatでcv mat形式に変換
    UIImageToMat(image, faceImage);
    
    //cvtColorでグレースケールに変換
    cv::Mat gray;
    cvtColor(faceImage, gray, CV_BGR2GRAY);
    
    //detectMultiScaleで顔を検出
    std::vector<cv::Rect> faces;
    faceDetector.detectMultiScale(gray, faces, 1.1,
                                  2, 0|CV_HAAR_SCALE_IMAGE, cv::Size(30, 30));
    
    std::cout << " faces.size() : " << faces.size() << std::endl;
    
    // Draw all detected faces
    for(unsigned int i = 0; i < faces.size(); i++)
    {
        const cv::Rect& face = faces[i];
        // Get top-left and bottom-right corner points
        cv::Point tl(face.x, face.y);
        cv::Point br = tl + cv::Point(face.width, face.height);
        
        //レクタングルを描画
        cv::Scalar magenta = cv::Scalar(255, 0, 255);
        cv::rectangle(faceImage, tl, br, magenta, 4, 8, 0);
    }
    
    //MatToUIImageでimage型に変換しimageviewにセット
    imageView.image = MatToUIImage(faceImage);
    
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

/*
#pragma mark - Navigation

// In a storyboard-based application, you will often want to do a little preparation before navigation
- (void)prepareForSegue:(UIStoryboardSegue *)segue sender:(id)sender {
    // Get the new view controller using [segue destinationViewController].
    // Pass the selected object to the new view controller.
}
*/

@end
