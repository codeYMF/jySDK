//
//  LoginHelper.h
//  XuanWuLoginSDK
//  TEST
//  Created by iSmart on 2019/2/28.
//  Copyright © 2019 xuanwu. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

#import "CustomUIConfig.h"

NS_ASSUME_NONNULL_BEGIN

@interface LoginHelper : NSObject
/**
 *开启debug模式，该模式下会输出部分流程日志，开发模式下可配置，线上请禁用
 */
+ (void)enableDebug;

/**
 *网络类型及运营商
 *网络类型  key:networkType / value: 0.无网络; 1.数据流量; 2.wifi; 3.数据+wifi
 *运营商   key:carrier / value: 0.未知;  1.中国移动;  2.中国联通; 3.中国电信
 */
+ (NSDictionary *)networkType;

/**
 *初始化SDK
 */
+(void)initialize:(void (^)(NSDictionary *_Nullable result))complete;

/**
 *根据应用信息初始化SDK
 */
+(void)initWithAppId:(NSString *)appId appKey:(NSString *)appKey appSecret:(NSString *)appSecret complete:(void (^)(NSDictionary *_Nullable result))complete;

/**
 *预取号
 */
+(void)preLogin:(NSTimeInterval)timeout complete:(void (^)(NSDictionary *_Nonnull result))complete;


/**
 *授权登录
 *@param complete 回调
 */
+(void)getPhoneTokenWithController:(UIViewController *)vc complete:(void (^)(id sender))complete;

/**
 *自定义登录授权页面UI
 */
+(void)setCustomLoginPageUI:(CustomUIConfig *) customUIConfig;

/**
 *关闭授权页
 */
//+(void)closeAuthVC:(void(^_Nullable)(void))complete;
+(void)manualCloseVC:(void(^_Nullable)(void))complete;

/**
 * 获取手机号校验token
 * @param complete 获取token异步回调函数，token:请求响应
 */
+ (void)getPhoneAuthToken:(void (^)(NSDictionary *_Nonnull result))complete;


+ (void)xwLogComplete:(void (^)(NSString *_Nonnull message))complete;

@end



NS_ASSUME_NONNULL_END
