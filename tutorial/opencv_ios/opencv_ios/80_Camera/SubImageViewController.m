//
//  SubImageViewController.m
//  opencv_ios
//
//  Created by USER on 2017/11/23.
//  Copyright © 2017年 USER. All rights reserved.
//

#import "SubImageViewController.h"

@interface SubImageViewController ()

@end

@implementation SubImageViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
    m_SubImageView = [[SubImageView alloc] initWithFrame: CGRectMake(50, 50, 100, 100) ];
    
    [self.view addSubview:m_SubImageView];
    
    
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
