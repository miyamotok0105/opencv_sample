//
//  DisplayingImageObcViewController.m
//  opencv_ios
//
//  Created by USER on 2017/11/20.
//  Copyright © 2017年 USER. All rights reserved.
//

#import "DisplayingImageObcViewController.h"

@interface DisplayingImageObcViewController ()

@end

@implementation DisplayingImageObcViewController
@synthesize imageView;

- (void)viewDidLoad {
    [super viewDidLoad];

    // Read the image
    image = [UIImage imageNamed:@"lena.png"];
    if (image != nil)
        imageView.image = image;
    
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
