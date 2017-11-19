//
//  DisplayingImageObcViewController.h
//  opencv_ios
//
//  Created by USER on 2017/11/20.
//  Copyright © 2017年 USER. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface DisplayingImageObcViewController : UIViewController {
    UIImage* image;
}

@property (nonatomic, weak) IBOutlet UIImageView* imageView;


@end
