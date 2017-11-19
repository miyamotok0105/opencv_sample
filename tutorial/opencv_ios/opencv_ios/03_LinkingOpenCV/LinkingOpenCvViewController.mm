//
//  LinkingOpenCvViewController.m
//  opencv_ios
//
//  Created by USER on 2017/11/20.
//  Copyright © 2017年 USER. All rights reserved.
//

#import "LinkingOpenCvViewController.h"
#import "opencv2/imgcodecs/ios.h"

@interface LinkingOpenCvViewController ()

@end

@implementation LinkingOpenCvViewController
@synthesize imageView;

- (void)viewDidLoad {
    [super viewDidLoad];

    UIImage* image = [UIImage imageNamed:@"lena.png"];
    
    // Convert UIImage* to cv::Mat
    UIImageToMat(image, cvImage);
    
    if (0)
    {
        
        NSString* filePath = [[NSBundle mainBundle]
                              pathForResource:@"lena" ofType:@"png"];
        // Create file handle
        NSFileHandle* handle =
        [NSFileHandle fileHandleForReadingAtPath:filePath];
        // Read content of the file
        NSData* data = [handle readDataToEndOfFile];
        // Decode image from the data buffer
        cvImage = cv::imdecode(cv::Mat(1, [data length], CV_8UC1,
                                       (void*)data.bytes),
                               CV_LOAD_IMAGE_UNCHANGED);
    }
    
    if (0)
    {
        NSData* data = UIImagePNGRepresentation(image);
        // Decode image from the data buffer
        cvImage = cv::imdecode(cv::Mat(1, [data length], CV_8UC1,
                                       (void*)data.bytes),
                               CV_LOAD_IMAGE_UNCHANGED);
    }
    
    if (!cvImage.empty())
    {
        cv::Mat gray;
        // Convert the image to grayscale
        cv::cvtColor(cvImage, gray, CV_RGBA2GRAY);
        // Apply Gaussian filter to remove small edges
        cv::GaussianBlur(gray, gray,
                         cv::Size(5, 5), 1.2, 1.2);
        // Calculate edges with Canny
        cv::Mat edges;
        cv::Canny(gray, edges, 0, 50);
        // Fill image with white color
        cvImage.setTo(cv::Scalar::all(255));
        // Change color on edges
        cvImage.setTo(cv::Scalar(0, 128, 255, 255), edges);
        // Convert cv::Mat to UIImage* and show the resulting image
        imageView.image = MatToUIImage(cvImage);
    }
    
    
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
