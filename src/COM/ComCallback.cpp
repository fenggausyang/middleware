/** ****************************************************************************
 * @FilePath     : /src/ara/phm...
 * @Description  : 
 * @Author       : Liujixin
 * @Date         : 2023-03-31 16:29:06
 * @Copyright (c) 2023 by Techinao, All Rights Reserved.
 ** ***************************************************************************/
#include "ComCallback.h"
namespace ComService
{
    /** ****************************************************************************
     * @brief        默认构造函数
     * @param        无
     * @return       {}
     * @retval       无
     * @version      2023-04-03 Liujixin 新建
     ** ***************************************************************************/
    ComCallback::ComCallback() {}
    /** ****************************************************************************
     * @brief        构造函数
     * @param        无
     * @return       {}
     * @retval       无
     * @version      2023-03-31 Liujixin 新建
     ** ***************************************************************************/
    ComCallback::ComCallback(std::queue<std::pair<std::string, std::string>> * pmessageQueue) : pmessageQueue_(pmessageQueue) {}

    /** ****************************************************************************
     * @brief        连接丢失
     * @param        cause: 丢失原因
     * @return       {}
     * @retval       无
     * @version      2023-03-31 Liujixin 新建
     ** ***************************************************************************/
    void ComCallback::connection_lost(const std::string& cause){
        std::cout << "\nConnection lost" << std::endl;
        if (!cause.empty())
        {
            std::cout << "\tcause: " << cause << std::endl;
        }
    }

    /** ****************************************************************************
     * @brief        消息到达
     * @param        msg: 消息
     * @return       {}
     * @retval       无
     * @version      2023-03-31 Liujixin 新建
     ** ***************************************************************************/
    void ComCallback::message_arrived(mqtt::const_message_ptr msg){

        // std::cout << "Message arrived" << std::endl;
        // std::cout << "\ttopic: '" << msg->get_topic() << "'" << std::endl;
        // std::cout << "\tpayload: '" << msg->to_string() << "'\n" << std::endl;
        pmessageQueue_->push(std::make_pair(msg->get_topic(), msg->to_string()));
        // std::cout << pmessageQueue_->size() << std::endl;
    }
    /** ****************************************************************************
     * @brief        重写函数
     * @param        token: 令牌
     * @return       {}
     * @retval       无
     * @version      2023-03-31 Liujixin 新建
     ** ***************************************************************************/
    void ComCallback::delivery_complete(mqtt::delivery_token_ptr token){}

}
