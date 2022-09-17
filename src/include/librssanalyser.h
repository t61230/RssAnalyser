/**
 * @file    librssanalyser.h
 * @ingroup RssAnalyser
 * @brief   处理RSS文档，获取channel包含的信息
 *
 * Original code by L2493 (gitee.com/dove-L2493)
 *
 * Distributed under the MIT License (MIT) (See accompanying file LICENSE.txt
 * or copy at http://opensource.org/licenses/MIT)
 */

#ifndef LIBRSSANALYSER_H
#define LIBRSSANALYSER_H

#include <string>
#include <memory>
#include <vector>
#include <iostream>
#include <fstream>
#include <tinyxml2.h>

/*存储RSS的Item元素信息*/
using EleItem = struct {
    std::string title;
    std::string enclosureUrl;
    std::string enclosureType;
};

/*存储RSS的channel元素信息*/
using EleChannel = struct {
    std::string title;
    std::string link;
    std::vector<EleItem> vecItem;
};

//namespace librssanalyser
//{
//
//    /* LibRssAnalyser是一个工具类，用于解析RSS文档*/
//    class LibRssAnalyser final
//    {
//    public:
//        /**
//        * @brief 初始化LibRssAnalyser工具类
//        * @return LibRssAnalyser类的静态引用对象
//        *
//        * 使用了单例实际模式，不需要使用new创建对象
//        */
//        static LibRssAnalyser* init();
//
//        /**
//        * @brief 从文件中读取RSS文档
//        * @param xmlFile 文件名称
//        * @return <Channel>元素包含的内容
//        * @throws tinyxml2::XMLError
//        */
//        static EleChannel readFromFile(const char* xmlFile);
//
//    private:
//        static LibRssAnalyser* LibRssAnalyser;
//
//        LibRssAnalyser() = default ;
//        ~LibRssAnalyser() = default;
//    };
//}

#endif
