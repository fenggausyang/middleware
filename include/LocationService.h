/** ****************************************************************************
 * @FilePath     : MiddleWare/include/LocationService.h
 * @Description  : 定位服务
 * @Author       : Liujixin
 * @Date         : 2023-03-13 11:44:25
 * @Copyright (c) 2022 by CarNong, All Rights Reserved.
 ** ***************************************************************************/
#ifndef MIDDLEWARE_INCLUDE__LOCATIONSERVICE_H__
#define MIDDLEWARE_INCLUDE__LOCATIONSERVICE_H__
#include <string>
#include <utility>
#include "cpr/cpr.h"
#include "json/json.h"
#include "Connector.h"
#include <unordered_map>
#include "LocationCache.h"
namespace LBS
{
    // 各类函数所需URL
    std::unordered_map<std::string, std::string> m_url = {
        {"searchLocation_URL", "https://apis.map.qq.com/ws/place/v1/search"},
        {"addressToCoordinate_URL", "https://apis.map.qq.com/ws/geocoder/v1/?address="},
        {"coordinateToAddress_URL", "https://apis.map.qq.com/ws/geocoder/v1/"},
        {"getRoute_URL", "https://apis.map.qq.com/ws/direction/v1/driving/"},
        {"addressSuggestion_URL", "https://apis.map.qq.com/ws/place/v1/suggestion"},
        {"coordinateTransform_URL", "https://apis.map.qq.com/ws/coord/v1/translate"},
        {"ipLocation_URL", "https://apis.map.qq.com/ws/location/v1/ip"}
    };
    class LocationService
    {
    public:
        /** ****************************************************************************
         * @brief        默认构造函数
         * @param        无
         * @return       {}
         * @retval       无
         * @version      2023-03-13 Liujixin 新建
         ** ***************************************************************************/
        LocationService();
        /** ****************************************************************************
         * @brief        带参构造函数
         * @param        api_key: API密钥
         * @return       {}
         * @retval       无
         * @version      2023-03-13 Liujixin 新建
         ** ***************************************************************************/
        LocationService(const std::string &api_key) : api_key_(api_key) {};
        /** ****************************************************************************
         * @brief        默认析构函数
         * @param        无
         * @return       {}
         * @retval       无
         * @version      2023-03-13 Liujixin 新建
         ** ***************************************************************************/
        ~LocationService();
        /** ****************************************************************************
         * @brief        查找周边地点
         * @param        keyword: 设施关键字
         * @param        region: 区域
         * @param        coordinate: 坐标
         * @param        range: 范围
         * @return       {Json::Value} 周边地点信息
         * @retval       无
         * @version      2023-03-13 Liujixin 新建
         ** ***************************************************************************/
        Json::Value searchLocation(const std::string &keyword, const std::string &region, const std::pair<double, double> &coordinate, int range = 1000);
        /** ****************************************************************************
         * @brief        地址转坐标
         * @param        address: 地址
         * @return       {std::pair<double, double>} 坐标 经纬度
         * @retval       无
         * @version      2023-03-13 Liujixin 新建
         ** ***************************************************************************/
        std::pair<double, double> addressToCoordinate(const std::string &address);
        /** ****************************************************************************
         * @brief        坐标转地址
         * @param        coordinate: 坐标
         * @return       {std::string} 地址
         * @retval       无
         * @version      2023-03-13 Liujixin 新建
         ** ***************************************************************************/
        std::string coordinateToAddress(const std::pair<double, double> &coordinate);
        /** ****************************************************************************
         * @brief        获取路径
         * @param        ori_coordinate: 起点坐标
         * @param        des_coordinate: 终点坐标
         * @return       {Json::Value} 路径信息
         * @retval       无
         * @version      2023-03-13 Liujixin 新建
         ** ***************************************************************************/
        Json::Value getRoute(const std::pair<double, double> &ori_coordinate, const std::pair<double, double> &des_coordinate);
        /** ****************************************************************************
         * @brief        获取路径距离
         * @param        ori_coordinate: 起点坐标
         * @param        des_coordinate: 终点坐标
         * @return       {int} 路径距离
         * @retval       无
         * @version      2023-03-15 Liujixin 新建
         ** ***************************************************************************/
        int getRouteDistance(const std::pair<double, double> &ori_coordinate, const std::pair<double, double> &des_coordinate);
        /** ****************************************************************************
         * @brief        地址关键字提示
         * @param        address: 地址
         * @return       {Json::Value} 后续关键字提示
         * @retval       无
         * @version      2023-03-15 Liujixin 新建
         ** ***************************************************************************/
        Json::Value addressSuggestion(const std::string &keyword);
        /** ****************************************************************************
         * @brief        坐标系转换 （GPS->Tencent)
         * @param        coordinate: 坐标
         * @return       {std::pair<double, double>} 坐标
         * @retval       无
         * @version      2023-03-15 Liujixin 新建
         ** ***************************************************************************/
        std::pair<double, double> coordinateTransform(const std::pair<double, double> &coordinate);
        /** ****************************************************************************
         * @brief        IP定位 通过终端设备IP地址获取其当前所在地理位置
         * @param        无
         * @return       {}
         * @retval       无
         * @version      2023-03-15 Liujixin 新建
         ** ***************************************************************************/
        Json::Value ipLocation();
    private:
        std::string api_key_;
        Connector connector_;
        LocationCache location_cache_;
    };
} // namespace LBS
#endif