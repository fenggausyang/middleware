#include "LocationService.h"
#include <iostream>
using namespace std;

#define MYKEY "VCFBZ-QAJES-K5MO6-6MUAX-CFSPZ-KGFTM"

int main() {
    LBS::LocationService ls(MYKEY);
    /*
        测试用例 1 ：查找周边地点 
        函数：Json::Value searchLocation(const std::string &keyword, const std::string &region, const std::pair<double, double> &coordinate, int range = 1000);
        参数 keyword: 酒店
        参数 region: 宁波
        参数 coordinate: 纬度 29.890387 经度 121.63806  {29.890387, 121.63806}
        参数 range: 1000 默认值
        输出：Json::Value
        {
        "count" : 70,
        "data" : 
        [
                {
                        "_distance" : 517.84000000000003,
                        "ad_info" : 
                        {
                                "adcode" : 330212,
                                "city" : "宁波市",
                                "district" : "鄞州区",
                                "province" : "浙江省"
                        },
                        "address" : "浙江省宁波市鄞州区聚贤路388-400号宁波科技广场2栋",
                        "category" : "酒店宾馆:酒店宾馆",
                        "id" : "15741099070718158255",
                        "location" : 
                        {
                                "lat" : 29.887314,
                                "lng" : 121.63403599999999
                        },
                        "tel" : "0574-87965588",
                        "title" : "宁波凯瑞商务宾馆",
                        "type" : 0
                },
                {
                        "_distance" : 1101.46,
                        "ad_info" : 
                        {
                                "adcode" : 330212,
                                "city" : "宁波市",
                                "district" : "鄞州区",
                                "province" : "浙江省"
                        },
                        "address" : "浙江省宁波市鄞州区高新区创苑路666号",
                        "category" : "酒店宾馆:星级酒店",
                        "id" : "3471487332084589517",
                        "location" : 
                        {
                                "lat" : 29.881653,
                                "lng" : 121.632699
                        },
                        "tel" : "18175380766;0574-87498666",
                        "title" : "格雷斯精选酒店(宁波高新区会展中心店)",
                        "type" : 0
                },
                {
                        "_distance" : 1418.8800000000001,
                        "ad_info" : 
                        {
                                "adcode" : 330211,
                                "city" : "宁波市",
                                "district" : "镇海区",
                                "province" : "浙江省"
                        },
                        "address" : "浙江省宁波市镇海区庄市街道勤勇村甬江外夏(甬江村公交站旁)",
                        "category" : "酒店宾馆:酒店宾馆",
                        "id" : "17488149899808959467",
                        "location" : 
                        {
                                "lat" : 29.901869999999999,
                                "lng" : 121.64443799999999
                        },
                        "tel" : "18958306869",
                        "title" : "宁波有间客栈",
                        "type" : 0
                },
                {
                        "_distance" : 877.46000000000004,
                        "ad_info" : 
                        {
                                "adcode" : 330212,
                                "city" : "宁波市",
                                "district" : "鄞州区",
                                "province" : "浙江省"
                        },
                        "address" : "浙江省宁波市鄞州区扬帆路686号(距会展中心2公里)",
                        "category" : "酒店宾馆:酒店宾馆",
                        "id" : "7661247360441409340",
                        "location" : 
                        {
                                "lat" : 29.882529000000002,
                                "lng" : 121.63735200000001
                        },
                        "tel" : "0574-87903839",
                        "title" : "桔红宾馆(宁波浙江大学软件学院店)",
                        "type" : 0
                },
                {
                        "_distance" : 1151.1900000000001,
                        "ad_info" : 
                        {
                                "adcode" : 330212,
                                "city" : "宁波市",
                                "district" : "鄞州区",
                                "province" : "浙江省"
                        },
                        "address" : "浙江省宁波市鄞州区新晖南路宁波高新宝龙广场",
                        "category" : "酒店宾馆:公寓式酒店",
                        "id" : "3543582224757910489",
                        "location" : 
                        {
                                "lat" : 29.882760999999999,
                                "lng" : 121.630005
                        },
                        "tel" : "021-26137886",
                        "title" : "亦同公寓(新晖南路1号分店)",
                        "type" : 0
                },
                {
                        "_distance" : 1344.3699999999999,
                        "ad_info" : 
                        {
                                "adcode" : 330212,
                                "city" : "宁波市",
                                "district" : "鄞州区",
                                "province" : "浙江省"
                        },
                        "address" : "浙江省宁波市鄞州区翔云北路199号1号楼7-7至7-15",
                        "category" : "酒店宾馆:酒店宾馆",
                        "id" : "6912974490234267032",
                        "location" : 
                        {
                                "lat" : 29.895695,
                                "lng" : 121.625552
                        },
                        "tel" : "0574-87903102",
                        "title" : "宁波深蓝城市民宿",
                        "type" : 0
                },
                {
                        "_distance" : 1348.8599999999999,
                        "ad_info" : 
                        {
                                "adcode" : 330212,
                                "city" : "宁波市",
                                "district" : "鄞州区",
                                "province" : "浙江省"
                        },
                        "address" : "浙江省宁波市鄞州区高新区文康路扬帆广场27号",
                        "category" : "酒店宾馆:酒店宾馆",
                        "id" : "14636603379290011210",
                        "location" : 
                        {
                                "lat" : 29.880987000000001,
                                "lng" : 121.62924099999999
                        },
                        "tel" : "0574-87856688",
                        "title" : "宁波拾意城市酒店",
                        "type" : 0
                },
                {
                        "_distance" : 1352.9400000000001,
                        "ad_info" : 
                        {
                                "adcode" : 330212,
                                "city" : "宁波市",
                                "district" : "鄞州区",
                                "province" : "浙江省"
                        },
                        "address" : "浙江省宁波市鄞州区翔云北路199号深蓝公寓1号楼12-7,12-16",
                        "category" : "酒店宾馆:公寓式酒店",
                        "id" : "5370225974276269166",
                        "location" : 
                        {
                                "lat" : 29.895748000000001,
                                "lng" : 121.62548099999999
                        },
                        "tel" : "13777631690",
                        "title" : "远月·乌托邦主题酒店式公寓(深蓝公寓店)",
                        "type" : 0
                },
                {
                        "_distance" : 1403.74,
                        "ad_info" : 
                        {
                                "adcode" : 330212,
                                "city" : "宁波市",
                                "district" : "鄞州区",
                                "province" : "浙江省"
                        },
                        "address" : "浙江省宁波市鄞州区扬帆路71号扬帆广场3幢1023室",
                        "category" : "酒店宾馆:酒店宾馆",
                        "id" : "13035827037227951240",
                        "location" : 
                        {
                                "lat" : 29.88036,
                                "lng" : 121.629245
                        },
                        "tel" : "15988601149",
                        "title" : "青岚民宿(宁波扬帆广场店)",
                        "type" : 0
                },
                {
                        "_distance" : 1537.6800000000001,
                        "ad_info" : 
                        {
                                "adcode" : 330212,
                                "city" : "宁波市",
                                "district" : "鄞州区",
                                "province" : "浙江省"
                        },
                        "address" : "浙江省宁波市鄞州区金沙码头奥莱公园(扬帆路1999号)",
                        "category" : "酒店宾馆:酒店宾馆",
                        "id" : "6887071357657580497",
                        "location" : 
                        {
                                "lat" : 29.891165000000001,
                                "lng" : 121.65396699999999
                        },
                        "tel" : "0574-56625588",
                        "title" : "四季阳光风情酒店(宁波高新店)",
                        "type" : 0
                }
        ],
        "message" : "query ok",
        "region" : 
        {
                "title" : "中国"
        },
        "request_id" : "1120151732413aac94ddee87d3f459163b97104387a0",
        "status" : 0
    */
//     Json::Value result = ls.searchLocation("酒店", "宁波", make_pair(29.890387, 121.63806));
//     Json::StreamWriterBuilder builder;
//     builder["emitUTF8"] = true;
//     std::unique_ptr<Json::StreamWriter> writer(builder.newStreamWriter());
//     writer->write(result, &std::cout);
    

    /*
        测试用例 2 ：地址转坐标
        函数原型：std::pair<double, double> addressToCoordinate(const std::string &address)
        参数 address：浙江省宁波市江南路1689号
        输出：std::pair<double, double>，经度和纬度
        29.8885 121.639
    */
//     std::pair<double, double> coordinate = ls.addressToCoordinate("浙江省宁波市江南路1689号");
//     cout << coordinate.first << " " << coordinate.second << endl;


    /*
        测试用例 3 ：坐标转地址
        函数原型：std::string coordinateToAddress(const std::pair<double, double> &coordinate)
        参数 coordinate：make_pair(29.8885, 121.639)
        输出：std::string，地址
        浙江省宁波市鄞州区江南路1689号
    */
//     std::string address = ls.coordinateToAddress(make_pair(29.8885, 121.639));
//     cout << address << endl;


    /*
        测试用例 4 ：路径规划
        函数原型：Json::Value getRoute(const std::pair<double, double> &ori_coordinate, const std::pair<double, double> &des_coordinate)
        参数 ori_coordinate：起点坐标 40.034852,116.319820
        参数 des_coordinate：终点坐标 39.771075,116.351395
        输出：Json::Value，路径规划结果
        ......
    */
//     Json::Value result1 = ls.getRoute(make_pair(40.034852,116.319820), make_pair(39.771075,116.351395));
//     Json::StreamWriterBuilder builder1;
//     builder1["emitUTF8"] = true;
//     std::unique_ptr<Json::StreamWriter> writer1(builder1.newStreamWriter());
//     writer1->write(result1, &std::cout);

    /*
        测试用例 5 ：地址关键词提示
        函数原型：Json::Value addressSuggestion(const std::string &keyword)
        参数 keyword：浙江大学
        输出：Json::Value，地址关键词提示结果
        {
        "count" : 100,
        "data" : 
        [
                {
                        "adcode" : 330106,
                        "address" : "浙江省杭州市西湖区浙大路38号",
                        "category" : "教育学校:大学",
                        "city" : "杭州市",
                        "district" : "西湖区",
                        "id" : "5516776883003765055",
                        "location" : 
                        {
                                "lat" : 30.263895999999999,
                                "lng" : 120.123051
                        },
                        "province" : "浙江省",
                        "title" : "浙江大学(玉泉校区)",
                        "type" : 0
                },
                {
                        "adcode" : 330106,
                        "address" : "浙江省杭州市西湖区余杭塘路866号",
                        "category" : "教育学校:大学",
                        "city" : "杭州市",
                        "district" : "西湖区",
                        "id" : "996187612050757311",
                        "location" : 
                        {
                                "lat" : 30.302610999999999,
                                "lng" : 120.08212899999999
                        },
                        "province" : "浙江省",
                        "title" : "浙江大学(紫金港校区)",
                        "type" : 0
                },
                {
                        "adcode" : 330102,
                        "address" : "浙江省杭州市上城区凯旋路268号",
                        "category" : "教育学校:大学",
                        "city" : "杭州市",
                        "district" : "上城区",
                        "id" : "5113708121244773741",
                        "location" : 
                        {
                                "lat" : 30.269407000000001,
                                "lng" : 120.195449
                        },
                        "province" : "浙江省",
                        "title" : "浙江大学(华家池校区)",
                        "type" : 0
                },
                {
                        "adcode" : 330106,
                        "address" : "浙江省杭州市西湖区天目山路34号",
                        "category" : "教育学校:大学",
                        "city" : "杭州市",
                        "district" : "西湖区",
                        "id" : "10132024128194361685",
                        "location" : 
                        {
                                "lat" : 30.275022,
                                "lng" : 120.140798
                        },
                        "province" : "浙江省",
                        "title" : "浙江大学(西溪校区)",
                        "type" : 0
                },
                {
                        "adcode" : 330102,
                        "address" : "浙江省杭州市上城区庆春路79号",
                        "category" : "医疗保健:综合医院",
                        "city" : "杭州市",
                        "district" : "上城区",
                        "id" : "12699979144822476775",
                        "location" : 
                        {
                                "lat" : 30.255939000000001,
                                "lng" : 120.177809
                        },
                        "province" : "浙江省",
                        "title" : "浙江大学附属第一医院",
                        "type" : 0
                },
                {
                        "adcode" : 330106,
                        "address" : "浙江省杭州市西湖区之江路51号",
                        "category" : "教育学校:大学",
                        "city" : "杭州市",
                        "district" : "西湖区",
                        "id" : "8441471689132839265",
                        "location" : 
                        {
                                "lat" : 30.192423000000002,
                                "lng" : 120.124872
                        },
                        "province" : "浙江省",
                        "title" : "浙江大学(之江校区)",
                        "type" : 0
                },
                {
                        "adcode" : 330102,
                        "address" : "浙江省杭州市上城区庆春东路3号",
                        "category" : "医疗保健:综合医院",
                        "city" : "杭州市",
                        "district" : "上城区",
                        "id" : "1786135175683179756",
                        "location" : 
                        {
                                "lat" : 30.256435,
                                "lng" : 120.202155
                        },
                        "province" : "浙江省",
                        "title" : "浙江大学医学院附属邵逸夫医院",
                        "type" : 0
                },
                {
                        "adcode" : 330212,
                        "address" : "浙江省宁波市鄞州区泰安西路168号",
                        "category" : "医疗保健:综合医院",
                        "city" : "宁波市",
                        "district" : "鄞州区",
                        "id" : "12235652875562351355",
                        "location" : 
                        {
                                "lat" : 29.806379,
                                "lng" : 121.537612
                        },
                        "province" : "浙江省",
                        "title" : "浙江大学明州医院",
                        "type" : 0
                },
                {
                        "adcode" : 330105,
                        "address" : "浙江省杭州市拱墅区竹竿巷57号",
                        "category" : "医疗保健:专科医院:儿科",
                        "city" : "杭州市",
                        "district" : "拱墅区",
                        "id" : "12894445013127802385",
                        "location" : 
                        {
                                "lat" : 30.260459999999998,
                                "lng" : 120.165846
                        },
                        "province" : "浙江省",
                        "title" : "浙江大学医学院附属儿童医院",
                        "type" : 0
                },
                {
                        "adcode" : 330105,
                        "address" : "浙江省杭州市拱墅区石祥路269号",
                        "category" : "教育学校:大学",
                        "city" : "杭州市",
                        "district" : "拱墅区",
                        "id" : "2560257403920513382",
                        "location" : 
                        {
                                "lat" : 30.326058,
                                "lng" : 120.15553
                        },
                        "province" : "浙江省",
                        "title" : "浙江大学城市学院北校区",
                        "type" : 0
                }
        ],
        "message" : "query ok",
        "request_id" : "13456571080097760385",
        "status" : 0
    */
//     Json::Value result = ls.addressSuggestion("浙江大学");
//     Json::StreamWriterBuilder builder;
//     builder["emitUTF8"] = true;
//     std::unique_ptr<Json::StreamWriter> writer(builder.newStreamWriter());
//     writer->write(result, &std::cout);

    /*
        测试用例6
        函数原型：std::pair<double, double> coordinateTransform(const std::pair<double, double> &coordinate);
        参数：coordinate：GPS经纬度坐标
        输出：std::pair<double, double> 转换后的腾讯坐标 
        0.2727 120.146
    */
//     std::pair<double, double> coordinate = std::make_pair(30.275022, 120.140798);
//     std::pair<double, double> result = ls.coordinateTransform(coordinate);
//     std::cout << result.first << " " << result.second << std::endl;

    /*
        测试用例7
        函数原型： Json::Value ipLocation();
        参数：无
        输出：Json::Value ip定位结果
        {
        "message" : "Success",
        "request_id" : "faac508cb494420e9d8c0f961f075564",
        "result" : 
        {
                "ad_info" : 
                {
                        "adcode" : 330212,
                        "city" : "宁波市",
                        "district" : "鄞州区",
                        "nation" : "中国",
                        "province" : "浙江省"
                },
                "ip" : "112.15.173.241",
                "location" : 
                {
                        "lat" : 29.8172,
                        "lng" : 121.547
                }
        },
        "status" : 0
        }
    */
    Json::Value result = ls.ipLocation();
    Json::StreamWriterBuilder builder;
    builder["emitUTF8"] = true;
    std::unique_ptr<Json::StreamWriter> writer(builder.newStreamWriter());
    writer->write(result, &std::cout);
    return 0;

}