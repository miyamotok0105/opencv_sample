//
//  LinkingOpenCvViewController.h
//  opencv_ios
//
//  Created by USER on 2017/11/20.
//  Copyright © 2017年 USER. All rights reserved.
//

#ifdef __cplusplus
#import <opencv2/opencv.hpp>
#endif

#import <UIKit/UIKit.h>

@interface LinkingOpenCvViewController : UIViewController {
    UIImage* image;
    cv::Mat cvImage;
}

@property (nonatomic, weak) IBOutlet UIImageView* imageView;

@end
