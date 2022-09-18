/**
 * @file    librssanalyser.cpp
 * @ingroup RssAnalyser
 * @brief   处理RSS文档，获取channel包含的信息
 *
 * Original code by L2493 (gitee.com/dove-L2493)
 *
 * Distributed under the MIT License (MIT) (See accompanying file LICENSE.txt
 * or copy at http://opensource.org/licenses/MIT)
 */
#include "librssanalyser.h"
using namespace librssanalyser;
using namespace tinyxml2;

/**
 * make_shared不能访问私有构造方法
 * 这里采用友元解决
 *
 * @line https://stackoverflow.com/questions/8147027
 */
struct LibRssAnalyser::MakeSharedEnabler:public LibRssAnalyser{
    MakeSharedEnabler() : LibRssAnalyser(){}
};

std::shared_ptr<LibRssAnalyser> LibRssAnalyser::init() {
    return std::make_shared<MakeSharedEnabler>();
}

EleChannel LibRssAnalyser::readFromFile(const char *xmlFile) const{
    XMLDocument doc;
    const XMLElement * rootEle;
    EleChannel eleChannel;

    if(doc.LoadFile(xmlFile) == XML_SUCCESS) {
        rootEle = doc.RootElement();                    //获取根节点
        if(rootEle != nullptr){
            eleChannel = getChannelInfo(rootEle);       //调用getChannelInfo()方法获取<channel>元素内容
        }
    }

    return eleChannel;
}

EleChannel LibRssAnalyser::getChannelInfo(const tinyxml2::XMLElement * rootEle) const {
    EleChannel eleChannel;
    const XMLElement * channelEle;
    const XMLElement * tempEle;

    channelEle = rootEle->FirstChildElement("channel");
    if(channelEle != nullptr) {
        /*查找title元素，读取文本(text)*/
        tempEle = channelEle->FirstChildElement("title");   //此时tempEle <XMLElement>指向title元素
        if(tempEle != nullptr)
            eleChannel.title = channelEle->GetText();

        /*查找link元素，读取文本(text)*/
        tempEle = channelEle->FirstChildElement("link");
        if(tempEle != nullptr)
            eleChannel.link = channelEle->GetText();

        /*循环查找item元素，传入getItemInfo()方法获取信息*/
        tempEle = channelEle->FirstChildElement("item");
        while (tempEle != nullptr)
        {
            eleChannel.vecItem.push_back(getItemInfo(tempEle)); //将获取到的item信息尾插到vecItem中
            tempEle = tempEle->NextSiblingElement();                   //查找下一个同类元素(item)
        }
    }

    return eleChannel;
}

EleItem LibRssAnalyser::getItemInfo(const tinyxml2::XMLElement * itemEle) const{
    EleItem itemInfo;
    const XMLElement * tempEle;

    /*查找title元素，读取文本(text)*/
    tempEle = itemEle->FirstChildElement("title");
    if(tempEle != nullptr)
        itemInfo.title = tempEle->GetText();

    /*查找enclosure元素*/
    tempEle = itemEle->FirstChildElement("enclosure");
    if(tempEle != nullptr){
        /*检查url、type属性是否存在,存在则获取参数*/
        if(tempEle ->Attribute("url") != nullptr)
            itemInfo.enclosureUrl = tempEle -> Attribute("url");
        if(tempEle->Attribute("type") != nullptr)
            itemInfo.enclosureType = tempEle -> Attribute("type");
    }

    return itemInfo;
}