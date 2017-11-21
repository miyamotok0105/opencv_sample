//
//  DetectingFacialFeaturesViewController.h
//  opencv_ios
//
//  Created by USER on 2017/11/20.
//  Copyright © 2017年 USER. All rights reserved.
//

#import <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#import <opencv2/imgcodecs/ios.h>
#include <opencv2/videoio/cap_ios.h>

#include "FaceAnimator.hpp"
#include "Processing.hpp"

#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>

@interface DetectingFacialFeaturesViewController : UIViewController <CvVideoCameraDelegate>
{
    CvVideoCamera* videoCamera;
    BOOL isCapturing;
    
    FaceAnimator::Parameters parameters;
    cv::Ptr<FaceAnimator> faceAnimator;
}

@property (nonatomic, strong) CvVideoCamera* videoCamera;
@property (nonatomic, strong) IBOutlet UIImageView *imageView;
@property (nonatomic, strong) IBOutlet UIToolbar* toolbar;
@property (nonatomic, weak) IBOutlet UIBarButtonItem* startCaptureButton;
@property (nonatomic, weak) IBOutlet UIBarButtonItem* stopCaptureButton;

-(IBAction)startCaptureButtonPressed:(id)sender;
-(IBAction)stopCaptureButtonPressed:(id)sender;


@end
