# RssAnalyser

## 简述

RssAnalyser使用[TinyXML-2](https://github.com/leethomason/tinyxml2) 从RSS文档中提取信息。

目标：能够正确解析资源站点的RSS订阅内容，提取出标题、种子文件下载地址；

样本：在{Project}/resource目录下，文件来自五个站点；

```
├─resource
│      acgrip.xml
│      bangumi.xml
│      dmhy.xml
│      kisssub.xml
│      mikan.rss
```

## 构建

项目使用[xmake](https://xmake.io/#/zh-cn/)自动构建工具;

构建对象:

静态库(LibRssAnalyser)、可执行文件(RssAnalyser)、TinyXML2演示程序(Tinyxml2Demo)、LibRssAnalyser测试程序(LibRssAnalyserDemo);

在windows环境使用MSVC 2019、2022均可构建，linux环境未测试；

```
--构建命令--
xmake build
```

构建完成后文件位于/build目录下;

## 测试

预先构建好的二进制文件在resource目录下

1、RssAnalyser需要传入一至两个参数

```
RssAnalyser.exe 输入文件名 [输出文件名]
```

如果只传入输入文件名，默认输出文件名为out.txt;

资源文件位于src/rssanalyser.cpp

2、Tinyxml2Demo是文章中的示例程序

直接将mikan.rss处理后的内容输出至命令窗口，在windows下使用注意切换至utf8编码;

3、LibRssAnalyserDemo是LibRssAnalyser的测试程序

会将mikan.rss的内容输出到out.txt，windows下可以直接双击运行;