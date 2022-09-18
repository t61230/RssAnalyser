/**
 * @file    tinyxml2demo.cpp
 * @ingroup RssAnalyser
 * @brief   演示tinyxml2的使用,将结果输出至命令窗口
 *
 * Original code by L2493 (gitee.com/dove-L2493)
 *
 * Distributed under the MIT License (MIT) (See accompanying file LICENSE.txt
 * or copy at http://opensource.org/licenses/MIT)
 */
#include <librssanalyser.h>

using namespace tinyxml2;
using namespace std;

int main()
{
    const char *const DOC_FILE = "mikan.rss";//文件名mikan.rss
    XMLDocument doc;
    const XMLElement * rootEle;             //一个XML文档只有一个根节点
    const XMLElement * channelEle;
    const XMLElement * tempEle;
    const XMLElement * itemEle;

    if(doc.LoadFile(DOC_FILE) == XML_SUCCESS) {
        cout << "Open File Succeed！" << endl;
        /*获取XML根节点*/
        rootEle = doc.RootElement();        //有获得空指针的风险
        if(rootEle != nullptr) {            //正常的XML文档会有根节点,注意C++11中NULL和nullptr不同
            cout << "Get RootElement Succeed！" << endl;

            /*查找<channel元素>,假定只有一个*/
            channelEle = rootEle->FirstChildElement("channel");
            if(channelEle != nullptr){
                cout << "Get ChannelElement Succeed！" << endl;
                /*从channel中获取title*/
                tempEle = channelEle->FirstChildElement("title");
                if(tempEle != nullptr)
                    cout <<"Channel Title:" << tempEle->GetText() <<endl;
                /*从channel中获取link*/
                tempEle = channelEle->FirstChildElement("link");
                if(tempEle != nullptr)
                    cout <<"Channel Link:" << tempEle->GetText() <<endl;
            }

            /*循环遍历<item元素>*/
            itemEle = channelEle->FirstChildElement("item");
            while(itemEle != nullptr){
                cout <<endl;
                /*获取item元素的title，和上面一样*/
                tempEle = itemEle->FirstChildElement("title");
                if(tempEle != nullptr)
                    cout <<"Item Title:" << tempEle->GetText() <<endl;
                /*获取enclosure元素的url和type属性*/
                tempEle = itemEle->FirstChildElement("enclosure");
                if(tempEle != nullptr ) {
                    if(tempEle ->Attribute("url") != nullptr)
                        cout << "Item enclosure url:" << tempEle->Attribute("url") << endl;
                    if(tempEle ->Attribute("type") != nullptr)
                        cout << "Item enclosure type:" << tempEle->Attribute("type") << endl;
                }

                itemEle = itemEle->NextSiblingElement();//查找下一个item
            }
        }
    }
    return 0;
}