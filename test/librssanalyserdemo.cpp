/**
 * @file    librssanalyserdemo.cpp
 * @ingroup RssAnalyser
 * @brief   测试LibRssAnalyser能否正常工作,结果输出至文件
 *
 * Original code by L2493 (gitee.com/dove-L2493)
 *
 * Distributed under the MIT License (MIT) (See accompanying file LICENSE.txt
 * or copy at http://opensource.org/licenses/MIT)
 */
#include "librssanalyser.h"
#include <algorithm>

using namespace std;
using namespace librssanalyser;

ofstream file;
void outItem(const EleItem &);

int main()
{
    EleChannel eleChannel;
    file.open("out.txt",ios::trunc|ios::out);

    /*初始化LibRssAnalyser*/
    LibRssAnalyser::init();
    /*从mikan.rss获取信息*/
    eleChannel = LibRssAnalyser::readFromFile("mikan.rss");

    /*向文件中写入Channel包含的内容*/
    file << "ChannelName:" << eleChannel.title << endl
         << "ChannelLink:" << eleChannel.link << endl
         << "========" << endl;
    for_each(eleChannel.vecItem.begin(), eleChannel.vecItem.end(), outItem);

    file.close();
    return 0;
}

void outItem(const EleItem& item)
{
    file << "ItemTitle:" << item.title << endl
         << "ItemEnclosureUrl:" <<item.enclosureUrl << endl
         << "ItemEnclosureType:" <<item.enclosureType << endl
         << "========" << endl;
}