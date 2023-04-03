/** ****************************************************************************
 * @FilePath     : /src/ara/phm...
 * @Description  : 
 * @Author       : Liujixin
 * @Date         : 2023-04-03 11:54:34
 * @Copyright (c) 2023 by Techinao, All Rights Reserved.
 ** ***************************************************************************/
#ifndef MESSAGEPUSHSERVICER_H
#define MESSAGEPUSHSERVICER_H

#include "ComServicer.h"
namespace ComService
{
    /*
        此类满足消息推送服务的需求
        继承自ComServicer
    */
    class MessagePushServicer : public ComServicer
    {
    public:
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
        MessagePushServicer(const std::string& brokerURL, 
                            const std::string& clientId, 
                            std::queue<std::pair<std::string, std::string>> * pmessageQueue,
                            const std::vector<std::string>& topics);
        /** ****************************************************************************
         * @brief        析构函数
         * @param        无
         * @return       {}
         * @retval       无
         * @version      2023-04-03 Liujixin 新建
         ** ***************************************************************************/
        ~MessagePushServicer();
        /** ****************************************************************************
         * @brief        启动服务
         * @param        无
         * @return       {}
         * @retval       无
         * @version      2023-04-03 Liujixin 新建
         ** ***************************************************************************/
        void start();
    private:
    };
}
#endif