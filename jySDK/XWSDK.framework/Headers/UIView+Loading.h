//
//  UIView+Loading.h
//  XWSDK
//
//  Created by yang on 2020/6/5.
//  Copyright © 2020 xuanwu. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface UIView (Loading)
/**
 * 弹出提示语
 */
- (void)showMessage:(NSString *) message;

- (void)showMessage:(NSString *) message messageColor:(UIColor *) color loadingViewBGColor:(UIColor *) bgColor;

/**
* 弹出提示语和loading图标
*/
- (void)showLoadingWithMessage:(NSString *) message;

- (void)showLoadingWithMessage:(NSString *) message messageColor:(UIColor *) color loadingViewBGColor:(UIColor *) bgColor;

/**
* 弹出提示语和gif动画
*/
- (void)showLoadingWithGifName:(NSString *) name WithMessage:(NSString *) message;

- (void)showLoadingWithGifName:(NSString *)name WithMessage:(NSString *)message messageColor: (UIColor *) color loadingViewBGColor:(UIColor *) bgColor;


- (void)hiddenLoading;

- (void)hiddenLoadingAfterDelay:(NSTimeInterval)delay;

@end

NS_ASSUME_NONNULL_END
