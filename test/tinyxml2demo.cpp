/**
 * @file    tinyxml2demo.cpp
 * @ingroup RssAnalyser
 * @brief   演示tinyxml2的使用
 *
 * Original code by L2493 (gitee.com/dove-L2493)
 *
 * Distributed under the MIT License (MIT) (See accompanying file LICENSE.txt
 * or copy at http://opensource.org/licenses/MIT)
 */
#include "librssanalyser.h"

using namespace tinyxml2;
using namespace std;

int main()
{
    const char *const DOC_FILE = "mikan.rss";//文件名mikan.rss
    XMLDocument doc;
    const XMLElement * rootEle;             //一个XML文档只有一个根节点

    if(doc.LoadFile(DOC_FILE) == XML_SUCCESS) {
        cout << "Open File Succeed！" << endl;
        /*获取XML根节点*/
        rootEle = doc.RootElement();        //有获得空指针的风险
        if(rootEle != nullptr)              //正常的XML文档会有根节点,注意C++11中NULL和nullptr不一样
            cout << "Get RootElement Succeed！" << endl;
    }
    return 0;
}