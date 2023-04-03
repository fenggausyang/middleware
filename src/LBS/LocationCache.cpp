/** ****************************************************************************
 * @FilePath     : MyProject/MiddleWare/LocationCache.cpp
 * @Description  : 
 * @Author       : Liujixin
 * @Date         : 2023-03-16 12:32:02
 * @Copyright (c) 2022 by CarNong, All Rights Reserved.
 ** ***************************************************************************/
#include "LocationCache.h"
namespace LBS
{
     // 默认构造函数
     LocationCache::LocationCache() {
        // 分配内存并初始化指针
        p_cache_addressSuggestion = new std::unordered_map<LBS::ParamStruct, Json::Value, LBS::ParamStructHash>();
        p_cache_addressToCoordinate = new std::unordered_map<LBS::ParamStruct, Json::Value, LBS::ParamStructHash>();
        p_cache_coordinateToAddress = new std::unordered_map<LBS::ParamStruct, Json::Value, LBS::ParamStructHash>();
        p_cache_coordinateTransform = new std::unordered_map<LBS::ParamStruct, Json::Value, LBS::ParamStructHash>();
        p_cache_getRoute = new std::unordered_map<LBS::ParamStruct, Json::Value, LBS::ParamStructHash>();
        p_cache_ipLocation = new std::unordered_map<LBS::ParamStruct, Json::Value, LBS::ParamStructHash>();
        p_cache_searchLocation = new std::unordered_map<LBS::ParamStruct, Json::Value, LBS::ParamStructHash>();
    }
    // 默认析构函数
    LocationCache::~LocationCache() {
        // 释放内存
        delete p_cache_addressSuggestion;
        delete p_cache_addressToCoordinate;
        delete p_cache_coordinateToAddress;
        delete p_cache_coordinateTransform;
        delete p_cache_getRoute;
        delete p_cache_ipLocation;
        delete p_cache_searchLocation;
    }
    
}