/** ****************************************************************************
 * @FilePath     : /src/ara/phm...
 * @Description  : 
 * @Author       : Liujixin
 * @Date         : 2023-03-31 12:46:40
 * @Copyright (c) 2023 by Techinao, All Rights Reserved.
 ** ***************************************************************************/
#include "ComServicer.h"
namespace ComService
{
    /** ****************************************************************************
     * @brief        带参构造函数
     * @param        brokerURL: 服务器地址
     * @param        clientId: 客户端ID
     * @return       {}
     * @retval       无
     * @version      2023-03-31 Liujixin 新建
     ** ***************************************************************************/
    ComServicer::ComServicer(const std::string& brokerURL, const std::string& clientId, std::queue<std::pair<std::string, std::string>> * pmessageQueue) :
    client_(brokerURL, clientId), connOpts_(), callback_(pmessageQueue)
    {   
        // 设置适当的keep alive的时间间隔
        connOpts_.set_keep_alive_interval(5);
        // 设置清除会话标志
        connOpts_.set_clean_session(true);
    }

    /** ****************************************************************************
     * @brief        默认析构函数
     * @param        无
     * @return       {}
     * @retval       无
     * @version      2023-03-31 Liujixin 新建
     ** ***************************************************************************/
    ComServicer::~ComServicer()
    {
    }

    /** ****************************************************************************
     * @brief        与指定的服务器地址进行连接
     * @param        无
     * @return       {}
     * @retval       无
     * @version      2023-03-31 Liujixin 新建
     ** ***************************************************************************/
    void ComServicer::connect()
    {
        try
        {
            this->setMessageCallback(callback_);
            std::cout << "Connecting to the Server..." << std::endl;
            client_.connect(connOpts_)->wait();
            std::cout << "Connection is established" << std::endl;
        }
        catch (const mqtt::exception& exc)
        {
            std::cerr << "Error: " << exc.what() << std::endl;
        }
    }

    /** ****************************************************************************
     * @brief        订阅某个主题
     * @param        topic: 主题
     * @return       {}
     * @retval       无
     * @version      2023-03-31 Liujixin 新建
     ** ***************************************************************************/
    void ComServicer::addTopic(const std::string& topic)
    {
        try
        {
            client_.subscribe(topic, 1)->wait();
            std::cout << "Subscribed to topic: " << topic << std::endl;
            topics_.push_back(topic);
        }
        catch (const mqtt::exception& exc)
        {
            std::cerr << "Error: " << exc.what() << std::endl;
        }
    }
    /** ****************************************************************************
     * @brief        订阅一组主题
     * @param        无
     * @return       {}
     * @retval       无
     * @version      2023-04-03 Liujixin 新建
     ** ***************************************************************************/
    void ComServicer::addTopics(const std::vector<std::string>& topics)
    {
        for(auto topic : topics)
        {
            this->addTopic(topic);
        }
    }
    /** ****************************************************************************
     * @brief        取消订阅某个主题
     * @param        无
     * @return       {}
     * @retval       无
     * @version      2023-03-31 Liujixin 新建
     ** ***************************************************************************/
    void ComServicer::subTopic(const std::string& topic)
    {
        try
        {
            client_.unsubscribe(topic)->wait();
            std::cout << "Unsubscribed to topic: " << topic << std::endl;
            // 删除已经订阅的主题
            for(auto it = topics_.begin(); it != topics_.end(); it++)
            {
                if(*it == topic)
                {
                    topics_.erase(it);
                    break;
                }
            }
        }
        catch (const mqtt::exception& exc)
        {
            std::cerr << "Error: " << exc.what() << std::endl;
        }
    }
    /** ****************************************************************************
     * @brief        查看已经订阅的主题
     * @param        无
     * @return       {std::vector<std::string>} 主题列表
     * @retval       无
     * @version      2023-04-03 Liujixin 新建
     ** ***************************************************************************/
    std::vector<std::string> ComServicer::getTopics()
    {
        return topics_;
    }
    /** ****************************************************************************
     * @brief        断开与服务器的连接
     * @param        无
     * @return       {}
     * @retval       无
     * @version      2023-03-31 Liujixin 新建
     ** ***************************************************************************/
    void ComServicer::disconnect()
    {
        try
        {
            client_.disconnect()->wait();
        }
        catch (const mqtt::exception& exc)
        {
            std::cerr << "Error: " << exc.what() << std::endl;
        }
    }

    /** ****************************************************************************
     * @brief        设置回调函数
     * @param        callback: 回调函数
     * @return       {}
     * @retval       无
     * @version      2023-03-31 Liujixin 新建
     ** ***************************************************************************/
    void ComServicer::setMessageCallback(mqtt::callback& callback)
    {
        client_.set_callback(callback);
    }
}