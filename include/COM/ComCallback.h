/** ****************************************************************************
 * @FilePath     : /src/ara/phm...
 * @Description  : 
 * @Author       : Liujixin
 * @Date         : 2023-03-31 16:24:06
 * @Copyright (c) 2023 by Techinao, All Rights Reserved.
 ** ***************************************************************************/
#ifndef COMCALLBACK_H
#define COMCALLBACK_H
#include <mqtt/async_client.h>
namespace ComService
{
    class ComCallback : public virtual mqtt::callback
    {
    public:
        /** ****************************************************************************
         * @brief        默认构造函数
         * @param        无
         * @return       {}
         * @retval       无
         * @version      2023-04-03 Liujixin 新建
         ** ***************************************************************************/
        ComCallback();
        /** ****************************************************************************
         * @brief        构造函数
         * @param        无
         * @return       {}
         * @retval       无
         * @version      2023-03-31 Liujixin 新建
         ** ***************************************************************************/
        ComCallback(std::queue<std::pair<std::string, std::string>> * pmessageQueue);
        /** ****************************************************************************
         * @brief        连接丢失
         * @param        cause: 丢失原因
         * @return       {}
         * @retval       无
         * @version      2023-03-31 Liujixin 新建
         ** ***************************************************************************/
        virtual void connection_lost(const std::string& cause) override;

        /** ****************************************************************************
         * @brief        消息到达
         * @param        msg: 消息
         * @return       {}
         * @retval       无
         * @version      2023-03-31 Liujixin 新建
         ** ***************************************************************************/
        virtual void message_arrived(mqtt::const_message_ptr msg) override;

        /** ****************************************************************************
         * @brief        重写函数
         * @param        token: 令牌
         * @return       {}
         * @retval       无
         * @version      2023-03-31 Liujixin 新建
         ** ***************************************************************************/
        virtual void delivery_complete(mqtt::delivery_token_ptr token) override;
    private:
        std::queue<std::pair<std::string, std::string>> * pmessageQueue_ = nullptr;
    };
}
#endif
