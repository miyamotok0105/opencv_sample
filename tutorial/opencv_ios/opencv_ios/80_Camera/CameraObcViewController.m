//
//  CameraObcViewController.m
//  opencv_ios
//
//  Created by USER on 2017/11/23.
//  Copyright © 2017年 USER. All rights reserved.
//

#import "CameraObcViewController.h"

@interface CameraObcViewController ()

@end

@implementation CameraObcViewController

AVCaptureSession *captureSession;

- (void)viewDidLoad {
    [super viewDidLoad];
    
    NSError *error = nil;
    //デバイス取得
    AVCaptureDevice* device = [AVCaptureDevice defaultDeviceWithMediaType:AVMediaTypeVideo];
    //入力作成
    AVCaptureDeviceInput *videoInput = [AVCaptureDeviceInput deviceInputWithDevice: device error:&error];
    if (!videoInput) { /* エラー処理 */ } else {
        // セッション初期化
        captureSession = [[AVCaptureSession alloc] init];
        [captureSession addInput:videoInput];
        [captureSession beginConfiguration];
        captureSession.sessionPreset = AVCaptureSessionPresetPhoto;
        [captureSession commitConfiguration];

        // プレビュー表示
        AVCaptureVideoPreviewLayer *previewLayer = [AVCaptureVideoPreviewLayer layerWithSession:captureSession];
        previewLayer.videoGravity = AVLayerVideoGravityResizeAspectFill;
        previewLayer.frame = self.view.bounds;
        [self.imageView.layer insertSublayer:previewLayer atIndex:0];
        

    }
    
    
}

- (void)viewDidAppear:(BOOL)animated {
    NSLog(@"subImageViewController");
    SubImageViewController* subImageViewController = [[SubImageViewController alloc] init];
    //    [self.view addSubview:subImageViewController];
    [self presentViewController:subImageViewController animated:YES completion:nil];
}

- (IBAction)btnCameraStart:(id)sender {
    // セッション開始
    [captureSession startRunning];
}

- (IBAction)btnCameraStop:(id)sender {
    [captureSession stopRunning];
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
