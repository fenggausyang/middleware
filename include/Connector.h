/** ****************************************************************************
 * @FilePath     : MyProject/MiddleWare/Connector.h
 * @Description  : 该类主要提供连接服务器的功能
 * @Author       : Liujixin
 * @Date         : 2023-03-15 19:42:47
 * @Copyright (c) 2022 by CarNong, All Rights Reserved.
 ** ***************************************************************************/
#ifndef MYPROJECT_MIDDLEWARE_CONNECTOR_H
#define MYPROJECT_MIDDLEWARE_CONNECTOR_H
#include <string>
#include "cpr/cpr.h"
#include "json/json.h"
namespace LBS
{
    class Connector
    {
    public:
        /** ****************************************************************************
         * @brief        默认构造函数
         * @param        无
         * @return       {}
         * @retval       无
         * @version      2023-03-15 Liujixin 新建
         ** ***************************************************************************/
        Connector();
        /** ****************************************************************************
         * @brief        默认析构函数
         * @param        无
         * @return       {}
         * @retval       无
         * @version      2023-03-15 Liujixin 新建
         ** ***************************************************************************/
        ~Connector();
        /** ****************************************************************************
         * @brief        发送请求
         * @param        无
         * @return       {}
         * @retval       无
         * @version      2023-03-15 Liujixin 新建
         ** ***************************************************************************/
        Json::Value connect(std::string url, cpr::Parameters parameters);
    };
}
#endif