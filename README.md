# RssAnalyser

## 简述

RssAnalyser使用[TinyXML-2](https://github.com/leethomason/tinyxml2) 从RSS文档中提取信息。

目标：能够正确解析资源站点的RSS订阅内容，提取出标题、种子文件下载地址；

样本：在{Project}/resource目录下，文件来自四个站点；

```
├─resource
│      acgrip.xml
│      bangumi.xml
│      dmhy.xml
│      kisssub.xml
```

## 结构

项目使用[xmake](https://xmake.io/#/zh-cn/)自动构建工具;

构建对象:

静态库(LibRssAnalyser)、可执行文件(RssAnalyser)、TinyXML2演示程序(Tinyxml2Demo);

