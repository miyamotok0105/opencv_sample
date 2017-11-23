//
//  SubImageView.m
//  opencv_ios
//
//  Created by USER on 2017/11/23.
//  Copyright © 2017年 USER. All rights reserved.
//

#import "SubImageView.h"

@implementation SubImageView

static CGRect const kSubViewFrame = {{10, 10}, {300, 180}};
static CGRect const kButtonFrame = {{10, 10}, {220, 30}};

- (id)initWithFrame:(CGRect)frame
{
    self = [super initWithFrame:frame];
    if (self) {
        // Initialization code
        
        // [1-1] タッチ操作を許可する
        self.userInteractionEnabled = true;
        
        // [1-2] 背景の色を灰色 (R,G,B)={0.5, 0.5, 0.5} に設定
        self.backgroundColor = [UIColor colorWithRed:0.5 green:0.5 blue:0.5 alpha:1.0];
    }
    return self;
}

// [1-3] 自力で追加！「touchesBegan関数」。このViewをタッチした時の命令
- (void)touchesBegan:(NSSet *)touches withEvent:(UIEvent *)event
{
    // [1-4] タッチした時、背景の色を薄赤 (R,G,B)={1.0, 0.5, 0.5}に設定
    self.backgroundColor = [UIColor colorWithRed:1.0 green:0.5 blue:0.5 alpha:1.0];
}

// [1-5] 自力で追加！「touchesEnded関数。このViewから指を離した時の命令
- (void)touchesEnded:(NSSet *)touches withEvent:(UIEvent *)event
{
    // [1-6] 指を離した時、元の色に戻す
    self.backgroundColor = [UIColor colorWithRed:0.5 green:0.5 blue:0.5 alpha:1.0];
}



/*
// Only override drawRect: if you perform custom drawing.
// An empty implementation adversely affects performance during animation.
- (void)drawRect:(CGRect)rect {
    // Drawing code
}
*/

@end
