//
//  GTCountSDK.h
//  GTCountSDK
//
//  Created by GeTui on 2017/7/18.
//  Copyright © 2017年 GeTui. All rights reserved.
//
//  Version : GSIOP-IOS-1.3.0.0

#import <Foundation/Foundation.h>

@interface GTCountSDK : NSObject

/**
 设置会话时长（默认 30000 ms,单位毫秒），在应用退到后台后停留时间超过会话时长，视为一次新的应用会话。
 */
@property (nonatomic, assign) NSInteger sessionTime;

/**
 设置有效活跃时长，活跃时长满足[min, max]的才会上报服务器记录
 minAppActiveDuration默认 1000 ms, maxAppActiveDuration默认 12*3600*1000 ms, 单位毫秒
 */
@property (nonatomic, assign) NSInteger minAppActiveDuration;
@property (nonatomic, assign) NSInteger maxAppActiveDuration;

/**
 缓存的最大数据条数（默认2000，不得低于10）
 */
@property (nonatomic, assign) NSInteger maxOfflineEventCount;

/**
 设置活跃记录的定时更新周期，默认 5000 ms，单位毫秒，最小 1000 ms
 */
@property (nonatomic, assign) NSInteger appActiveUpdatePeriod;

/**
 设置同一个活跃记录的上报频率限制，默认 30*1000，单位毫秒
 */
@property (nonatomic, assign) NSInteger appActiveEventFrequencyLimit;

/**
 设置服务器地址，比如 https://a.b.c:8080
 */
@property (nonatomic, copy) NSString *requestHost;

/**
 设置服务器配置，无前后缀无换行
 */
@property (nonatomic, copy) NSString *publicKey;
@property (nonatomic, copy) NSString *publicKeyID;

/**
 SDK 实例，用于获取和设置 SDK 相关配置属性。
 示例，设置上报策略：[[GTCountSDK sharedInstance] setSessionTime:30*1000];
 */
+ (instancetype)sharedInstance;

/**
 初始化启动接口 
 
 @param appId 开发者后台生成的 appId
 @param channelId 渠道名称，默认为 'appstore'
 */
+ (void)startSDKWithAppId:(NSString *)appId withChannelId:(NSString *)channelId;

/**
 记录自定义事件的开始
 注意：需要跟 trackCustomKeyValueEventEnd:withArgs: 配对使用
 若多次调用则以最后一次开始的时间为准
 
 @param eventId 自定义事件 Id，需要在个数后台配置才能生效
 @param args 本参数不再使用，事件只以 eventId 为判断依据
 */
+ (void)trackCustomKeyValueEventBegin:(NSString *)eventId withArgs:(NSDictionary *)args __deprecated_msg("请使用不带args参数接口或args传nil");
+ (void)trackCustomKeyValueEventBegin:(NSString *)eventId;

/**
 记录自定义事件的结束
 注意：需要跟 trackCustomKeyValueEventBegin:withArgs: 配对使用
 若多次调用则以第一次结束的时间为准
 
 @param eventId 自定义事件 Id，需要在个数后台配置才能生效
 @param args 自定义属性，key 必须为 NSString 类型（注意：不能以$开头），value 仅支持NSNumber, BOOL, NSString, NSDate 4 种类型。
 @param ext 自定义ext字段内容。
 */
+ (void)trackCustomKeyValueEventEnd:(NSString *)eventId withArgs:(NSDictionary *)args withExt:(NSString *)ext;
+ (void)trackCustomKeyValueEventEnd:(NSString *)eventId withArgs:(NSDictionary *)args;

/**
 计数事件统计
 
 @param eventId 事件 Id，需要在个数后台配置才能生效
 @param args 自定义属性，key 必须为 NSString 类型（注意：不能以$开头），value 仅支持NSNumber, BOOL, NSString, NSDate 4 种类型
 @param ext 自定义ext字段内容。
 */
+ (void)trackCountEvent:(NSString *)eventId withArgs:(NSDictionary *)args withExt:(NSString *)ext;
+ (void)trackCountEvent:(NSString *)eventId withArgs:(NSDictionary *)args;

/**
 用户属性设置
 
 @param profiles 用户属性参数，key 必须为 NSString 类型，value 仅支持NSNumber, BOOL, NSString, NSDate 4 种类型
 @param ext 自定义ext字段内容。
 */
+ (void)setProfile:(NSDictionary *)profiles withExt:(NSString *)ext;
+ (void)setProfile:(NSDictionary *)profiles;

/**
 是否启动开发者模式，在该模式下数据会实时上传，并且将会打印相关的数据上传信息
 
 @param isDebug 是否开启
 */
+ (void)setDebugEnable:(BOOL)isDebug;

+ (NSString *)sdkVersion;

@end
