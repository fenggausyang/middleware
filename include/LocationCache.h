/** ****************************************************************************
 * @FilePath     : MyProject/MiddleWare/LocationCache.h
 * @Description  : 
 * @Author       : Liujixin
 * @Date         : 2023-03-16 12:32:02
 * @Copyright (c) 2022 by CarNong, All Rights Reserved.
 ** ***************************************************************************/
#ifndef MYPROJECT_MIDDLEWARE_LOCATIONCACHE_H
#define MYPROJECT_MIDDLEWARE_LOCATIONCACHE_H
#include "json/json.h"
#include <unordered_map>
#include "cpr/cpr.h"
#include "ParamStruct.h"
namespace LBS
{
    class LocationCache
    {
        public:
        // 默认构造函数
        LocationCache();
        // 默认析构函数
        ~LocationCache();
        // cache for searchLocation
        std::unordered_map<LBS::ParamStruct, Json::Value, LBS::ParamStructHash> *p_cache_searchLocation;
        // cache for addressToCoordinate
        std::unordered_map<LBS::ParamStruct, Json::Value, LBS::ParamStructHash> *p_cache_addressToCoordinate;
        // cache for coordinateToAddress
        std::unordered_map<LBS::ParamStruct, Json::Value, LBS::ParamStructHash> *p_cache_coordinateToAddress;
        // cache for getRoute
        std::unordered_map<LBS::ParamStruct, Json::Value, LBS::ParamStructHash> *p_cache_getRoute;
        // cache for addressSuggestion
        std::unordered_map<LBS::ParamStruct, Json::Value, LBS::ParamStructHash> *p_cache_addressSuggestion;
        // cache for coordinateTransform
        std::unordered_map<LBS::ParamStruct, Json::Value, LBS::ParamStructHash> *p_cache_coordinateTransform;
        // cache for ipLocation
        std::unordered_map<LBS::ParamStruct, Json::Value, LBS::ParamStructHash> *p_cache_ipLocation;
    };
}
#endif