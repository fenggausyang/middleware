#include "LocationService.h"
#include <iostream>
namespace LBS
{
    // 默认构造函数
    LocationService::LocationService()
    {
    }
    // 默认析构函数
    LocationService::~LocationService()
    {
    }
    // 查找周边地点
    Json::Value LocationService::searchLocation(const std::string &keyword, const std::string &region, const std::pair<double, double> &coordinate, int range)
    {
        // 获取基本URL
        std::string url = LBS::m_url["searchLocation_URL"];

        // 将坐标转换为字符串
        std::string boundary = "nearby(" + std::to_string(coordinate.first) + "," + std::to_string(coordinate.second) + "," + std::to_string(range) + ")";
        // 编码请求参数
        auto keyword_encode = cpr::util::urlEncode(keyword);
        auto region_encode = cpr::util::urlEncode(region);
        // 检查是否是在缓存中
        auto it = location_cache_.p_cache_searchLocation->find(ParamStruct{.address = "",
                                                                                .region = region_encode,
                                                                                .boundary = boundary,
                                                                                .key= api_key_,
                                                                                .keyword = keyword_encode,
                                                                                .location = "",
                                                                                .from = "",
                                                                                .to = "",
                                                                                .locations = ""});
        // 如果在缓存中存在，直接返回                                                                    
        if (it != location_cache_.p_cache_searchLocation->end()) {
            return it->second;
        }
        else
        {
            // 建立连接,并且将返回结果存入缓存
            Json::Value jsonresult = connector_.connect(url, cpr::Parameters{{"keyword", keyword_encode},
                                                                                {"region", region_encode},
                                                                                {"boundary", boundary},
                                                                                {"key", api_key_}});
            location_cache_.p_cache_searchLocation->insert({ParamStruct{.address = "",
                                                                            .region = region_encode,
                                                                            .boundary = boundary,
                                                                            .key= api_key_,
                                                                            .keyword = keyword_encode,
                                                                            .location = "",
                                                                            .from = "",
                                                                            .to = "",
                                                                            .locations = ""}, jsonresult});
            return jsonresult;
        }
        
    }
    // 地址转坐标
    std::pair<double, double> LocationService::addressToCoordinate(const std::string &address)
    {
        // 判断地址是否为空
        if (address.empty()) {
            throw std::runtime_error("Address is empty");
        }
        std::pair<double, double> result;
        // 获取基本URL
        std::string url = LBS::m_url["addressToCoordinate_URL"];
        // 编码请求参数
        auto address_encode = cpr::util::urlEncode(address);
        // 检查是否是在缓存中
        auto it = location_cache_.p_cache_addressToCoordinate->find(ParamStruct{.address = address_encode,
                                                                                .region = "",
                                                                                .boundary = "",
                                                                                .key= api_key_,
                                                                                .keyword = "",
                                                                                .location = "",
                                                                                .from = "",
                                                                                .to = "",
                                                                                .locations = ""});
        // 如果在缓存中存在，直接返回
        if (it != location_cache_.p_cache_addressToCoordinate->end()) {
            result.first = it->second["result"]["location"]["lat"].asDouble();
            result.second = it->second["result"]["location"]["lng"].asDouble();
            return result;
        }
        else
        {
            // 建立连接,并且将返回结果存入缓存
            Json::Value jsonresult = connector_.connect(url, cpr::Parameters{{"address", address_encode},
                                                                                {"key", api_key_}});
            location_cache_.p_cache_addressToCoordinate->insert({ParamStruct{.address = address_encode,
                                                                            .region = "",
                                                                            .boundary = "",
                                                                            .key= api_key_,
                                                                            .keyword = "",
                                                                            .location = "",
                                                                            .from = "",
                                                                            .to = "",
                                                                            .locations = ""}, jsonresult});
            result.first = jsonresult["result"]["location"]["lat"].asDouble();
            result.second = jsonresult["result"]["location"]["lng"].asDouble();
            return result;
        }
    }
    // 坐标转地址
    std::string LocationService::coordinateToAddress(const std::pair<double, double> &coordinate)
    {   
        // 获取基本URL
        std::string location = std::to_string(coordinate.first) + "," + std::to_string(coordinate.second);

        // 将经纬度拼接到URL中
        std::string url = LBS::m_url["coordinateToAddress_URL"];
        // 检查是否是在缓存中
        auto it = location_cache_.p_cache_coordinateToAddress->find(ParamStruct{.address = "",
                                                                                .region = "",
                                                                                .boundary = "",
                                                                                .key= api_key_,
                                                                                .keyword = "",
                                                                                .location = location,
                                                                                .from = "",
                                                                                .to = "",
                                                                                .locations = ""});
        // 如果在缓存中存在，直接返回
        if (it != location_cache_.p_cache_coordinateToAddress->end()) {
            return it->second["result"]["address"].asString();
        }
        else
        {
            // 建立连接,并且将返回结果存入缓存
            Json::Value jsonresult = connector_.connect(url, cpr::Parameters{{"location", location},
                                                                                {"key", api_key_}});
            location_cache_.p_cache_coordinateToAddress->insert({ParamStruct{.address = "",
                                                                            .region = "",
                                                                            .boundary = "",
                                                                            .key= api_key_,
                                                                            .keyword = "",
                                                                            .location = location,
                                                                            .from = "",
                                                                            .to = "",
                                                                            .locations = ""}, jsonresult});
            // 从Json中解析出地址
            std::string result = jsonresult["result"]["address"].asString();
            return result;
        }
    }
    // 路径规划
    Json::Value LocationService::getRoute(const std::pair<double, double> &ori_coordinate, const std::pair<double, double> &des_coordinate)
    {
        // 拼接出发点和目的地的经纬度
        std::string ori = std::to_string(ori_coordinate.first) + "," + std::to_string(ori_coordinate.second);
        std::string des = std::to_string(des_coordinate.first) + "," + std::to_string(des_coordinate.second);
        // 拼接URL
        std::string url = LBS::m_url["getRoute_URL"];
        // 检查是否是在缓存中
        auto it = location_cache_.p_cache_getRoute->find(ParamStruct{.address = "",
                                                                    .region = "",
                                                                    .boundary = "",
                                                                    .key= api_key_,
                                                                    .keyword = "",
                                                                    .location = "",
                                                                    .from = ori,
                                                                    .to = des,
                                                                    .locations = ""});
        // 如果在缓存中存在，直接返回
        if (it != location_cache_.p_cache_getRoute->end()) {
            return it->second;
        }
        else
        {
            // 建立连接,并且将返回结果存入缓存
            Json::Value jsonresult = connector_.connect(url, cpr::Parameters{{"from", ori},
                                                                                {"to", des},
                                                                                {"key", api_key_}});
            location_cache_.p_cache_getRoute->insert({ParamStruct{.address = "",
                                                                .region = "",
                                                                .boundary = "",
                                                                .key= api_key_,
                                                                .keyword = "",
                                                                .location = "",
                                                                .from = ori,
                                                                .to = des,
                                                                .locations = ""}, jsonresult});
            return jsonresult;
        }
    }
    // 获取路径规划的距离
    int LocationService::getRouteDistance(const std::pair<double, double> &ori_coordinate, const std::pair<double, double> &des_coordinate)
    {
        // 获取路径规划的Json
        Json::Value jsonresult = getRoute(ori_coordinate, des_coordinate);
        // 获取距离
        int distance = jsonresult["result"]["routes"][0]["distance"].asInt();
        return distance;
    }
    // 地址关键字搜索
    Json::Value LocationService::addressSuggestion(const std::string &keyword) {
        // 判断地址是否为空
        if (keyword.empty()) {
            throw std::runtime_error("Address is empty");
        }
        // 获取基本URL
        std::string url = LBS::m_url["addressSuggestion_URL"];
        // 编码请求参数
        auto keyword_encode = cpr::util::urlEncode(keyword);
        // 检查是否是在缓存中
        auto it = location_cache_.p_cache_addressSuggestion->find(ParamStruct{.address = "",
                                                                            .region = "",
                                                                            .boundary = "",
                                                                            .key= api_key_,
                                                                            .keyword = keyword_encode,
                                                                            .location = "",
                                                                            .from = "",
                                                                            .to = "",
                                                                            .locations = ""});
        // 如果在缓存中存在，直接返回
        if (it != location_cache_.p_cache_addressSuggestion->end()) {
            return it->second;
        }
        else
        {
            // 建立连接,并且将返回结果存入缓存
            Json::Value jsonresult = connector_.connect(url, cpr::Parameters{{"keyword", keyword_encode},
                                                                                {"key", api_key_}});
            location_cache_.p_cache_addressSuggestion->insert({ParamStruct{.address = "",
                                                                        .region = "",
                                                                        .boundary = "",
                                                                        .key= api_key_,
                                                                        .keyword = keyword_encode,
                                                                        .location = "",
                                                                        .from = "",
                                                                        .to = "",
                                                                        .locations = ""}, jsonresult});
            return jsonresult;
        }
    }
    // 坐标系转换
    std::pair<double, double> LocationService::coordinateTransform(const std::pair<double, double> &coordinate) {
        // 获取基本URL
        std::string location = std::to_string(coordinate.first) + "," + std::to_string(coordinate.second);

        // 将经纬度拼接到URL中
        std::string url = LBS::m_url["coordinateTransform_URL"];
        // 检查是否是在缓存中
        auto it = location_cache_.p_cache_coordinateTransform->find(ParamStruct{.address = "",
                                                                                .region = "",
                                                                                .boundary = "",
                                                                                .key= api_key_,
                                                                                .keyword = "",
                                                                                .location = location,
                                                                                .from = "",
                                                                                .to = "",
                                                                                .locations = "",
                                                                                .type = "1"});
        // 如果在缓存中存在，直接返回
        if (it != location_cache_.p_cache_coordinateTransform->end()) {
            std::pair<double, double> result;
            result.first = it->second["locations"][0]["lat"].asDouble();
            result.second = it->second["locations"][0]["lng"].asDouble();
            return result;
        }
        else
        {
            // 建立连接,并且将返回结果存入缓存
            Json::Value jsonresult = connector_.connect(url, cpr::Parameters{{"locations", location},
                                                                                {"type", "1"},
                                                                                {"key", api_key_}});
            location_cache_.p_cache_coordinateTransform->insert({ParamStruct{.address = "",
                                                                            .region = "",
                                                                            .boundary = "",
                                                                            .key= api_key_,
                                                                            .keyword = "",
                                                                            .location = location,
                                                                            .from = "",
                                                                            .to = "",
                                                                            .locations = "",
                                                                            .type = "1"}, jsonresult});
            // 获取经纬度
            std::pair<double, double> result;
            result.first = jsonresult["locations"][0]["lat"].asDouble();
            result.second = jsonresult["locations"][0]["lng"].asDouble();
            return result;
        }
    }
    // 获取IP地址所在位置
    Json::Value LocationService::ipLocation() {
        // 获取基本URL
        // std::string url = "https://apis.map.qq.com/ws/location/v1/ip?key=" + api_key_;
        std::string url = LBS::m_url["ipLocation_URL"];
        // 检查是否是在缓存中
        auto it = location_cache_.p_cache_ipLocation->find(ParamStruct{.address = "",
                                                                        .region = "",
                                                                        .boundary = "",
                                                                        .key= api_key_,
                                                                        .keyword = "",
                                                                        .location = "",
                                                                        .from = "",
                                                                        .to = "",
                                                                        .locations = "",
                                                                        .type = "1"});
        // 如果在缓存中存在，直接返回
        if (it != location_cache_.p_cache_ipLocation->end()) {
            return it->second;
        }
        else
        {
            // 建立连接,并且将返回结果存入缓存
            Json::Value jsonresult = connector_.connect(url, cpr::Parameters{{"key", api_key_}});
            location_cache_.p_cache_ipLocation->insert({ParamStruct{.address = "",
                                                                    .region = "",
                                                                    .boundary = "",
                                                                    .key= api_key_,
                                                                    .keyword = "",
                                                                    .location = "",
                                                                    .from = "",
                                                                    .to = "",
                                                                    .locations = "",
                                                                    .type = "1"}, jsonresult});
            return jsonresult;
        }
    }
}