Pod::Spec.new do |s|
  # 名称，pod search 搜索的关键词,注意这里一定要和.podspec的名称一样,否则报错
  s.name         = "GTIOPSDK"
  # 版本号/库原代码的版本
  s.version      = "1.0.0.0"
  # 简介
  s.summary      = "个推 鲸智运营中心 iOS SDK CocoaPods集成库"

  # 项目主页地址
  s.homepage     = "https://github.com/GetuiLaboratory/getui-gtiop-ios-cocoapods"
  # 许可证/所采用的授权版本
  s.license      = 'MIT'
  # 库的作者
  s.author       = { "个推" => "support@getui.com" }
  # 项目的地址
  s.source       = { :git => "https://github.com/GetuiLaboratory/getui-gtiop-ios-cocoapods.git", :tag => s.version }

  # 支持的平台及版本
  s.platform     = :ios, "8.0"
  # iOS支持的pod最低版本 / iOS对应的版本
  s.ios.deployment_target = "8.0"

  s.source_files  = 'GTIOPSDK/*.h'
  # 使用了第三方静态库
  # s.ios.vendored_library = ''
  #s.ios.vendored_libraries = ''
  s.ios.vendored_libraries = 'GTIOPSDK/GTExtensionSDK.a','GTIOPSDK/libGTCommonSDK.a','GTIOPSDK/libGTIOP.a'

  # 所需的framework，多个用逗号隔开
  s.ios.frameworks = 'SystemConfiguration', 'CFNetwork','CoreTelephony','CoreLocation','AVFoundation','Security','AdSupport'

  # “弱引用”所需的framework，多个用逗号隔开
  s.ios.weak_frameworks = 'UserNotifications'

  # 所需的library，多个用逗号隔开
  s.ios.libraries = 'z','sqlite3.0','c++','resolv'

  # 是否使用ARC，如果指定具体文件，则具体的问题使用ARC
  s.requires_arc = true
  
end
