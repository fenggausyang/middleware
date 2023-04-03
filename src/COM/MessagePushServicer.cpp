/** ****************************************************************************
 * @FilePath     : /src/ara/phm...
 * @Description  : 
 * @Author       : Liujixin
 * @Date         : 2023-04-03 12:11:02
 * @Copyright (c) 2023 by Techinao, All Rights Reserved.
 ** ***************************************************************************/
#include "MessagePushServicer.h"
namespace ComService
{
    /** ****************************************************************************
     * @brief        构造函数
     * @param        brokerURL: 服务器地址
     * @param        clientId: 客户端ID
     * @param        pmessageQueue: 消息队列
     * @param        topics: 订阅的APP消息主题
     * @return       {}
     * @retval       无
     * @version      2023-04-03 Liujixin 新建
     ** ***************************************************************************/
    MessagePushServicer::MessagePushServicer(const std::string& brokerURL, 
                                             const std::string& clientId, 
                                             std::queue<std::pair<std::string, std::string>> * pmessageQueue,
                                             const std::vector<std::string>& topics)
    : ComServicer(brokerURL, clientId, pmessageQueue)
    {   
        connect();
        addTopics(topics);
    }
    /** ****************************************************************************
     * @brief        析构函数
     * @param        无
     * @return       {}
     * @retval       无
     * @version      2023-04-03 Liujixin 新建
     ** ***************************************************************************/
    MessagePushServicer::~MessagePushServicer(){}

    /** ****************************************************************************
     * @brief        启动服务
     * @param        无
     * @return       {}
     * @retval       无
     * @version      2023-04-03 Liujixin 新建
     ** ***************************************************************************/
    void MessagePushServicer::start()
    {
        connect();
    }
}