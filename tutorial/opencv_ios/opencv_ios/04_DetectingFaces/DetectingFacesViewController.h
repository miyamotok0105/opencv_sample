//
//  DetectingFacesViewController.h
//  opencv_ios
//
//  Created by USER on 2017/11/22.
//  Copyright © 2017年 USER. All rights reserved.
//

#ifdef __cplusplus
#import <opencv2/opencv.hpp>
#import "opencv2/imgcodecs/ios.h"
#endif

#import <UIKit/UIKit.h>


@interface DetectingFacesViewController : UIViewController {
    cv::CascadeClassifier faceDetector;
}

@property (nonatomic, weak) IBOutlet UIImageView* imageView;

@end
