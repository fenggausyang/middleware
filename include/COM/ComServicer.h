/** ****************************************************************************
 * @FilePath     : /src/ara/phm...
 * @Description  : 
 * @Author       : Liujixin
 * @Date         : 2023-03-31 11:56:38
 * @Copyright (c) 2023 by Techinao, All Rights Reserved.
 ** ***************************************************************************/
#ifndef COMSERVICER_H
#define COMSERVICER_H

#include <iostream>
#include <queue>
#include <vector>
#include "ComCallback.h"
namespace ComService
{
    /*
    * @brief        通信服务类
    *               用于提供具体的通讯服务
    */
    class ComServicer
    {
    public:
        // 消息回调函数
        using MessageCallback = std::function<void (const std::string&, const std::string&)>;
        /** ****************************************************************************
         * @brief        默认构造函数
         * @param        无
         * @return       {}
         * @retval       无
         * @version      2023-03-31 Liujixin 新建
         ** ***************************************************************************/
        ComServicer() = default;
        /** ****************************************************************************
         * @brief        带参构造函数
         * @param        brokerURL: 服务器地址
         * @param        clientId: 客户端ID
         * @return       {}
         * @retval       无
         * @version      2023-03-31 Liujixin 新建
         ** ***************************************************************************/
        ComServicer(const std::string& brokerURL, const std::string& clientId, std::queue<std::pair<std::string, std::string>> * pmessageQueue);
        /** ****************************************************************************
         * @brief        默认析构函数
         * @param        无
         * @return       {}
         * @retval       无
         * @version      2023-03-31 Liujixin 新建
         ** ***************************************************************************/
        ~ComServicer();
        /** ****************************************************************************
         * @brief        与指定的服务器地址进行连接
         * @param        无
         * @return       {}
         * @retval       无
         * @version      2023-03-31 Liujixin 新建
         ** ***************************************************************************/
        void connect();
        /** ****************************************************************************
         * @brief        订阅单个主题
         * @param        topic: 主题
         * @return       {}
         * @retval       无
         * @version      2023-03-31 Liujixin 新建
         ** ***************************************************************************/
        void addTopic(const std::string& topic);
        /** ****************************************************************************
         * @brief        订阅一组主题
         * @param        topics: 主题列表
         * @return       {}
         * @retval       无
         * @version      2023-04-03 Liujixin 新建
         ** ***************************************************************************/
        void addTopics(const std::vector<std::string>& topics);
        /** ****************************************************************************
         * @brief        取消订阅某个主题
         * @param        topic: 主题
         * @return       {}
         * @retval       无
         * @version      2023-03-31 Liujixin 新建
         ** ***************************************************************************/
        void subTopic(const std::string& topic);
        /** ****************************************************************************
         * @brief        查看已经订阅的主题
         * @param        无
         * @return       {std::vector<std::string>} 主题列表
         * @retval       无
         * @version      2023-04-03 Liujixin 新建
         ** ***************************************************************************/
        std::vector<std::string>  getTopics();
        /** ****************************************************************************
         * @brief        断开与服务器的连接
         * @param        无
         * @return       {}
         * @retval       无
         * @version      2023-03-31 Liujixin 新建
         ** ***************************************************************************/
        void disconnect();
        /** ****************************************************************************
         * @brief        设置回调函数
         * @param        callback: 回调函数
         * @return       {}
         * @retval       无
         * @version      2023-03-31 Liujixin 新建
         ** ***************************************************************************/
        void setMessageCallback(mqtt::callback& callback);
        
    private:
        // 异步客户端
        mqtt::async_client client_;
        // 连接配置
        mqtt::connect_options connOpts_;
        // 回调消息
        // std::queue<std::pair<std::string, std::string>> *pmessageQueue_=nullptr;
        // 消息回调类
        ComCallback callback_;
        // 已经订阅的主题
        std::vector<std::string> topics_;
    };
} // namespace ComService
#endif