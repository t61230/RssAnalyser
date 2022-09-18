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

namespace librssanalyser
{
    /* LibRssAnalyser是一个工具类，用于解析RSS文档*/
    class LibRssAnalyser
    {
    public:
        /**
        * @brief 初始化LibRssAnalyser工具类
        * @return LibRssAnalyser类的静态引用对象
        */
        static std::shared_ptr<LibRssAnalyser> init();

        /**
        * @brief 从文件中读取RSS文档
        * @param xmlFile 文件名称
        * @return <Channel>元素包含的内容
        * @throws tinyxml2::XMLError
        */
        EleChannel readFromFile(const char* xmlFile) const;

    protected:
        /**.
         * @brief 从XML的根元素中获取<channel>元素信息
         * @param rootEle XML文档的根节点[通过tinyxml2::XMLElement::RootElement()方法获取]
         * @return librssanalyser::EleChannel <channel>元素包含的内容
         *
         * 注意：在传入参数前需要进行空指针检查
         */
        EleChannel getChannelInfo(const tinyxml2::XMLElement * rootEle) const;

        /**.
        * @brief 从<item>元素中获取信息
        * @param itemEle XML中的<item>元素
        * @return librssanalyser::EleItem <item>元素包含的内容
        *
        * 注意：在传入参数前需要进行空指针检查
        */
        EleItem getItemInfo(const tinyxml2::XMLElement * itemEle) const;

    private:
        LibRssAnalyser() = default;
        ~LibRssAnalyser() = default;

        struct MakeSharedEnabler;
    };
}

#endif