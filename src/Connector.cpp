/** ****************************************************************************
 * @FilePath     : MyProject/MiddleWare/Connector.cpp
 * @Description  : 该类主要提供连接服务器的功能
 * @Author       : Liujixin
 * @Date         : 2023-03-15 19:42:47
 * @Copyright (c) 2022 by CarNong, All Rights Reserved.
 ** ***************************************************************************/
#include "Connector.h"
#include <iostream>
namespace LBS
{
    // 默认构造函数
    Connector::Connector(){}
    // 默认析构函数
    Connector::~Connector(){}
    // 连接服务器 API
    Json::Value Connector::connect(std::string url, cpr::Parameters parameters)
    {   // 发送请求
        auto r = cpr::Get(cpr::Url{url}, cpr::Parameters{parameters});
        // 对连接的状态进行判断
        if (r.status_code != 200) {
            throw std::runtime_error("HTTP request failed with status code: " + std::to_string(r.status_code));
        }
        // 解析返回的json数据
        Json::Value root;
        Json::CharReaderBuilder builder;
        std::string errors;
        auto reader = std::unique_ptr<Json::CharReader>(builder.newCharReader());
        // 解析json数据
        if (!reader->parse(r.text.c_str(), r.text.c_str() + r.text.size(), &root, &errors)) {
            throw std::runtime_error("Failed to parse JSON response: " + errors);
        }
        return root;
    }
}