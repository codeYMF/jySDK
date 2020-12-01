//
//  CustomUIConfig.h
//  XWSDK
//
//  Created by Cassie Lee on 2019/8/1.
//  Copyright © 2019 xuanwu. All rights reserved.
//
#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

/*
 注： 授权页一键登录按钮、运营商品牌标签、运营商条款必须显示，不得隐藏，否则取号能力可能被运营商关闭
 **/

@protocol CustomUIProtocol <NSObject>

@optional
/**
*  点击隐私协议的回调
*  url: 点击的隐私协议对应的url
*  返回值: true: 自动跳转到safari浏览器打开协议页面，
*         false: 不再自动跳转到safari浏览器打开协议页面, 用户可自定义跳转到定制页面
*/

@optional - (BOOL)customUIDidClickClauseWithLinkUrl:(NSURL *) url;

/**
*  选中或反选隐私协议的回调
*  status: 隐私协议选中的状态，true：隐私协议被选中，false：隐私协议未被选中
*  返回值: 无
*/

@optional - (void)customUIDidSelectClauseWithSelectStatus:(BOOL ) status;

/**
*  点击一键登录时未勾选协议选择框时需要弹出提示的回调，用户可以在这里自定义提示样式及提示语
*  注意：只有在用户未勾选协议选择框时，点击一键登录按钮才会调用此回调
*  selectView: 协议勾选框
*  返回值: true: 自动弹出SDK中的提示语，
*         false: 不再自动弹出SDK中的提示语, 用户可自定义提示样式及提示语
*/

@optional - (BOOL)showClauseUnselectedTipsWithSelectView:(UIView *) selectView;


/**
*  xwlog的回调，当打开日志时，打印日志时会调用此回调
*  message: 打印的消息
*/

@optional - (void)xwLog:(NSString *) message;

@end


@interface CustomUIConfig : NSObject

typedef enum {
    CheckboxAndClauseAlignmentLeft  = 0,
    CheckboxAndClauseAlignmentCenter,
    CheckboxAndClauseAlignmentRight
} CheckboxAndClauseAlignment;

typedef NS_ENUM(NSInteger, CheckboxAlignment) {
    CheckboxAlignmentTop = 1,
    CheckboxAlignmentMiddle,
    CheckboxAlignmentBottom
};

typedef NS_ENUM(NSInteger, CustomUIConfigType) {
    configPortraitFullscreen = 0,  // 竖屏全屏
    configLandscapeFullscreen,     // 横屏全屏
    configPortraitDialog,          // 竖屏弹窗
    configLandscapeDialog          // 横屏弹窗
};

@property (nonatomic, weak) id<CustomUIProtocol> delegate;

/*----------------------------------------授权页面-----------------------------------*/

/**
 *外部手动管理关闭界面
 *BOOL,default is NO
 *eg.@(YES)
 */
@property (nonatomic,strong)NSNumber * manualCloseVC;
/**是否为横屏样式，默认为否*/
@property (nonatomic,assign) BOOL isLandspace;
/**横屏样式，默认为UIInterfaceOrientationMaskLandscapeRight*/
@property (nonatomic,assign) UIInterfaceOrientationMask landspaceOrientation;
/**授权页面背景图片，若为弹窗模式则为弹窗的背景图*/
@property (nonatomic,strong) UIImage *bgImage;

/**授权页面背景View，若为弹窗模式则为弹窗的背景view，用户可放置图片或gif或播放视频等等，bgView在bgImage之上，如果设置bgView则会遮盖bgImage*/
@property (nonatomic,strong) UIView *bgView;

/*-------------------状态栏样式-----------------------------*/
/**状态栏样式, 默认为UIStatusBarStyleLightContent*/
@property (nonatomic,assign) UIStatusBarStyle statusBarStyle;
/**状态栏是否隐藏，默认不隐藏*/
@property (nonatomic,assign) BOOL statusBarHidden;

/*-------------------导航栏-----------------------------*/
/**导航栏颜色，默认为透明色*/
@property (nonatomic,strong) UIColor *navColor;
/**导航栏标题文字*/
@property (nonatomic,strong) NSString *navText;
/**导航栏标题文字颜色，默认为白色*/
@property (nonatomic,strong) UIColor *navTextColor;
/**导航返回图标*/
@property (nonatomic,strong) UIImage *navReturnImg;
/**是否隐藏导航，默认不隐藏，但是弹窗模式下会自动隐藏*/
@property (nonatomic,assign) BOOL navHidden;
/**是否隐藏导航的返回按钮，默认不隐藏 */
@property (nonatomic, assign) BOOL backItemHidden;
/**导航的返回按钮是否居右显示，默认居左显示 */
@property (nonatomic, assign) BOOL backItemIsAlignmentRight;

/*-------------------弹窗样式-----------------------------*/
/**是否为弹窗样式，默认为否*/
@property (nonatomic,assign) BOOL isPopupStyle;
/**弹窗样式，默认为:UIModalTransitionStyleCoverVertical 底部弹出
 * eg:  UIModalTransitionStyleFlipHorizontal         翻转
 *      UIModalTransitionStyleCrossDissolve          淡入
 */
@property (nonatomic,assign) UIModalTransitionStyle popupStyle;
/**弹窗高度*/
@property (nonatomic,assign) CGFloat popupViewHeight;
/**弹窗宽度*/
@property (nonatomic,assign) CGFloat popupViewWidth;
/**弹窗圆角*/
@property (nonatomic,assign) CGFloat popupViewCornerRidus;
/**弹窗X偏移量(以屏幕中心为原点)*/
@property (nonatomic,assign) CGFloat popupViewOffsetX;
/**弹窗Y偏移量(以屏幕中心为原点)*/
@property (nonatomic,assign) CGFloat popupViewOffsetY;
/**弹窗是否贴于屏幕底部*/
@property (nonatomic,assign) BOOL isPopupViewBottomInScreen;
/** 弹窗样式阴影层的颜色，默认是透明度为0.5的黑色 */
@property (nonatomic, strong) UIColor *maskBackgroundColor;

/*-------------------LOGO设置-----------------------------*/
/**LOGO图片是否隐藏*/
@property (nonatomic,assign) BOOL logoHidden;
/**LOGO图片*/
@property (nonatomic,strong) UIImage *logoImg;
/**LOGO图片的url，在图片下载成功之前会显示logoImg的图片，下载成功后会进行替换*/
@property (nonatomic,strong) NSString *logoImgUrl;
/**LOGO图片宽度，默认为80pt*/
@property (nonatomic,assign) CGFloat logoWidth;
/**LOGO图片高度，默认为80pt*/
@property (nonatomic,assign) CGFloat logoHeight;
/**LOGO图片X偏移量*/
@property (nonatomic,assign) CGFloat logoOffsetX;
/**LOGO图片Y偏移量*/
@property (nonatomic,assign) CGFloat logoOffsetY;

/*-------------------号码框设置-----------------------------*/
/**手机号码字体颜色, 默认为白色*/
@property (nonatomic,strong) UIColor *numberColor;
/**手机号码字体，默认为22*/
@property (nonatomic,strong)UIFont  *numberFont;
/**手机号码栏文字对齐方式，默认为NSTextAlignmentCenter*/
@property (nonatomic,assign) NSTextAlignment numberTextAlignment;
/**号码栏X偏移量*/
@property (nonatomic,assign) CGFloat numberOffsetX;
/**号码栏Y偏移量*/
@property (nonatomic,assign) CGFloat numberOffsetY;

/*-------------------运营商slogan-----------------------------*/
/**slogan文字，默认为相应运营商的slogan*/
@property (nonatomic,strong) NSString *sloganText;
/**slogan文字颜色, 默认为lightGrayColor*/
@property (nonatomic,strong) UIColor *sloganTextColor;
/**slogan文字大小, 默认为12pt*/
@property (nonatomic,assign) CGFloat sloganTextSize __attribute__((deprecated("此属性已弃用,请使用sloganTextFont属性")));
/**slogan文字字体, 默认为系统字体12pt, 使用sloganTextFont时sloganTextSize会无效*/
@property (nonatomic,strong) UIFont *sloganTextFont;
/**slogan偏移量X*/
@property (nonatomic,assign) CGFloat sloganOffsetX;
/**slogan偏移量Y*/
@property (nonatomic,assign) CGFloat sloganOffsetY;
/**slogan是否隐藏*/
@property (nonatomic,assign) BOOL sloganHidden;

/*-------------------登录按钮-----------------------------*/
/**登录按钮文本，默认为“本机号码一键登录”*/
@property (nonatomic,strong) NSString *logBtnText;
/**登录按钮文本颜色， 默认为白色*/
@property (nonatomic,strong) UIColor *logBtnTextColor;
/**登录按钮文本 字体， 默认为16*/
@property (nonatomic,strong)UIFont  *logBtnTextFont;
/**登录按钮宽度，默认为270*/
@property (nonatomic,assign) CGFloat logBtnWidth;
/**登录按钮高度，默认为45*/
@property (nonatomic,assign) CGFloat logBtnHeight;
/**登录按钮圆角*/
@property (nonatomic,assign) CGFloat logBtnCornerRadius;
/**登录按钮边框颜色,默认clearColor*/
@property (nonatomic,strong) UIColor *logBtnBoardColor;
/**登录按钮颜色，默认为 r:62,G:79,B:208*/
@property (nonatomic,strong) UIColor *logBtnColor;
/**登录按钮图片 激活状态的图片*/
@property (nonatomic,strong) UIImage *logBtnNormalImg;
/**登录按钮图片 禁用状态的图片*/
@property (nonatomic,strong) UIImage *logBtnDisableImg;
/**登录按钮图片 高亮状态的图片*/
@property (nonatomic,strong) UIImage *logBtnHiglightImg;
/**登录按钮图片右边距，默认为0*/
@property (nonatomic,assign) CGFloat logBtnImageEdgeInsetsRight;
/**登录按文本间左边距，默认为0*/
@property (nonatomic,assign) CGFloat logBtnTitleEdgeInsetsLeft;
/**登录按钮背景图片 激活状态的图片*/
@property (nonatomic,strong) UIImage *logBtnNormalBgImg;
/**登录按钮背景图片 禁用状态的图片*/
@property (nonatomic,strong) UIImage *logBtnDisableBgImg;
/**登录按钮背景图片 高亮状态的图片*/
@property (nonatomic,strong) UIImage *logBtnHiglightBgImg;
/**登录按钮X偏移量*/
@property (nonatomic,assign) CGFloat logBtnOffsetX;
/**登录按钮Y偏移量*/
@property (nonatomic,assign) CGFloat logBtnOffsetY;

/*-------------------切换账号-----------------------------*/
/**切换账号按钮显示文字，默认为“切换账号”*/
@property (nonatomic,strong) NSString *switchAccText;
/**切换账号按钮字体大小，默认大小为17*/
@property (nonatomic,assign) CGFloat switchAccTextSize;
/**切换账号按钮文字颜色, 默认为r:62,G:79,B:208*/
@property (nonatomic,strong) UIColor *switchAccTextColor;
/**切换账号按钮是否隐藏*/
@property (nonatomic,assign) BOOL switchAccHidden;
/**切换账号按钮X轴偏移量*/
@property (nonatomic,assign) CGFloat switchOffsetX;
/**切换账号按钮Y轴偏移量*/
@property (nonatomic,assign) CGFloat switchOffsetY;

/*-------------------loading-----------------------------*/
/**loading弹窗的图片名字，支持gif, 默认为空*/
@property (nonatomic,strong) NSString *loadingImageName;
/**loading弹窗提示语，默认为"加载中..."*/
@property (nonatomic,assign) NSString *loadingMessage;
/**loading弹窗的背景色，默认是白色*/
@property (nonatomic,assign) UIColor *loadingBgColor;
/**loading弹窗提示语文字颜色，默认是黑色*/
@property (nonatomic,assign) UIColor *loadingMessageColor;

/*-------------------自定义控件-----------------------------*/
/**自定义控件*/
@property (nonatomic,strong) UIView *customeWidget;
/**自定义控件宽度*/
@property (nonatomic,assign) CGFloat customeWidgetWidth;
/**自定义控件宽度*/
@property (nonatomic,assign) CGFloat customeWidgetHeight;
/**自定义控件X轴偏移量*/
@property (nonatomic,assign) CGFloat customeWidgetOffsetX;
/**自定义控件Y轴偏移量*/
@property (nonatomic,assign) CGFloat customeWidgetOffsetY;

/*-------------------隐私条款-----------------------------*/
/**复选框未选中时图片*/
@property (nonatomic,strong) UIImage *uncheckedImg;
/**复选框选中时图片*/
@property (nonatomic,strong) UIImage *checkedImg;
/**复选框宽度，默认为16*/
@property (nonatomic,assign) CGFloat checkboxWidth;
/**复选框高度，默认为16*/
@property (nonatomic,assign) CGFloat checkboxHeight;
/**复选框距离隐私协议文字顶部的距离，默认为0*/
@property (nonatomic,assign) CGFloat checkboxTopSpace;
/**复选框距离隐私协议文字的对齐方式， 默认是顶部对齐， 用户设置checkboxAlignment属性时checkboxTopSpace将会失效
 * CheckboxAlignmentTop:      复选框距离隐私协议文字顶部对齐
 * CheckboxAlignmentMiddle：  复选框距离隐私协议文字竖直居中对齐
 * CheckboxAlignmentBottom ： 复选框距离隐私协议文字底部对齐
 **/
@property (nonatomic,assign) CheckboxAlignment checkboxAlignment;
/**复选框距离隐私协议文字之间的距离， 默认为2*/
@property (nonatomic,assign) CGFloat checkboxRightSpace;
/**复选框是否隐藏*/
@property (nonatomic,assign) BOOL checkboxHidden;
/**复选框选中状态，默认为选中状态*/
@property (nonatomic,assign) BOOL checkState;
/**复选框选未选中时的提示信息，默认为“请同意服务条款”*/
@property (nonatomic,strong) NSString *uncheckedMsg;
/**运营商隐私条款是否放置于末尾， 默认放置在末尾*/
@property (nonatomic,assign) BOOL carrierClauseIsLast;
/**运营商隐私条款的《》是否隐藏， 默认不隐藏*/
@property (nonatomic,assign) BOOL carrierClauseAngleQuotesHidden;
/**隐私条款的文字，会取clauseArray中的key对其中的{*}内容进行替换
 * 默认为：“登录即同意{*}授权本应用获取本机号码”
 * eg： clauseString = @”登录即同意{*}和{*}授权本应用获取本机号码“
 *      clauseArray =  @[@{@"《我的应用条款》" : @"https://xxx"}]
 *  (以联通手机号为例)最终条款栏显示的文本为：
 *  当carrierClauseIsLast = YES（默认），登录即同意《我的应用条款》和《联通统一认证服务条款》授权本应用获取本机号码
 *  当carrierClauseIsLast = NO，登录即同意《联通统一认证服务条款》和《我的应用条款》授权本应用获取本机号码
 */
@property (nonatomic,strong) NSString *clauseString;
/**条款字典数组，key为条款名称，value为对应的条款链接*/
@property(nonatomic, strong) NSArray<NSDictionary*> *clauseArray;
/**隐私条款文字的对齐方式，默认为NSTextAlignmentCenter居中显示**/
@property(nonatomic, assign) NSTextAlignment clauseTextAlignment;
/**隐私条款行间距，默认为1**/
@property (nonatomic,assign) CGFloat clauseLineSpacing;
/**隐私条款行字体大小，默认为12**/
@property (nonatomic,assign) CGFloat clauseFontSize __attribute__((deprecated("此属性已弃用,请使用clauseFont属性")));
/**隐私条款行字体，默认为系统字体12pt, 使用clauseFont时clauseFontSize会无效*/
@property (nonatomic,strong) UIFont *clauseFont;
/**隐私条款非条款项文字颜色，默认为lightGrayColor**/
@property (nonatomic,strong) UIColor *clauseBaseColor;
/**隐私条款条款项文字(如运营商协议或用户协议)正常状态下的文字的颜色，默认为绿色**/
@property (nonatomic,strong) UIColor *clauseColor;
/**隐私条款条款项文字(如运营商协议或用户协议)点击时文字的颜色，默认为红色**/
@property (nonatomic,strong) UIColor *clauseSelectColor;
/**隐私条款条款项文字(如运营商协议或用户协议)是否显示下划线，默认false，不显示下划线**/
@property (nonatomic,assign) BOOL clauseUnderLine;
/**隐私条款X偏移量*/
@property (nonatomic,assign) CGFloat clauseOffsetX;
/**隐私条款Y偏移量*/
@property (nonatomic,assign) CGFloat clauseOffsetY;
/**隐私条款+复选框距离屏幕的左边距,  默认25*/
@property (nonatomic,assign) CGFloat clauseMarginLeft;
/**隐私条款+复选框距离屏幕的右边距，默认25*/
@property (nonatomic,assign) CGFloat clauseMarginRight;
/**隐私协议+复选框对齐方式，默认为NSTextAlignmentCenter*/
@property (nonatomic,assign) CheckboxAndClauseAlignment checkboxAndClauseAlignment;

/**用户每日登录次数限制，默认为30，设置为0表示不限制*/
@property (nonatomic,assign) NSInteger loginCountLimit;

/**
 * 根据type加载预置的模板样式view
 */
- (instancetype)initWithType:(CustomUIConfigType) type;
@end


