/**
 * @file    rssanalyser.cpp
 * @ingroup RssAnalyser
 * @brief   通过命令调用librssanalyser工具类,将结果输出至文件
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

void writeToFile(const char* fileName,EleChannel channelInfo);
ostream& operator<<(ostream & os,const EleChannel & eleChannel);
ostream& operator<<(ostream & os,const EleItem & eleItem);

int main(int argc,char *argv[])
{
    EleChannel eleChannel;

    /*初始化LibRssAnalyser*/
    LibRssAnalyser::init();

    /*argc(0)是程序名*/
    if(argc == 2) {
        eleChannel = LibRssAnalyser::readFromFile(argv[1]);
        writeToFile("out.txt",eleChannel);      //仅传入RSS文档名称，输出文件默认为out.txt
    }else if(argc == 3){
        eleChannel = LibRssAnalyser::readFromFile(argv[1]);
        writeToFile(argv[2],eleChannel);
    }else{
        cout<< "One or two arg" << endl
            << "RssAnalyser inputFile " <<endl
            << "RssAnalyser inputFile [OutputFileName]" <<endl
            << "Example: RssAnalyser mikan.rss mikan.txt" <<endl;
    }

    return 0;
}
void writeToFile(const char* fileName,EleChannel channelInfo)
{
    ofstream file;

    file.open(fileName,ios::trunc|ios::out);    //打开输出文件
    file << channelInfo <<endl;                          //把channel的内容都传进去
    file.close();
}

ostream& operator<<(ostream & os,const EleChannel & eleChannel)
{
    os << "ChannelTitle:" << eleChannel.title << endl
       << "ChannelLink:" << eleChannel.link << endl
       << "========" << endl;

    /*循环输出所有item元素信息*/
    for(int count = 0;count < eleChannel.vecItem.size();count++)
    {
        os << eleChannel.vecItem.at(count);
    }
    return os;
}

ostream& operator<<(ostream & os,const EleItem & eleItem)
{
    os << "ItemTitle:" << eleItem.title << endl
         << "ItemEnclosureUrl:" <<eleItem.enclosureUrl << endl
         << "ItemEnclosureType:" <<eleItem.enclosureType << endl
         << "========" << endl;

    return os;
}