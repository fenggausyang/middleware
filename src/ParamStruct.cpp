/** ****************************************************************************
 * @FilePath     : MyProject/MiddleWare/ParamStruct.h
 * @Description  : 
 * @Author       : Liujixin
 * @Date         : 2023-03-16 13:31:46
 * @Copyright (c) 2022 by CarNong, All Rights Reserved.
 ** ***************************************************************************/
#include "ParamStruct.h"
namespace LBS
{
    std::size_t ParamStructHash::operator()(const ParamStruct &p) const
    {
        std::size_t h1 = std::hash<std::string>{}(p.address);
        std::size_t h2 = std::hash<std::string>{}(p.region);
        std::size_t h3 = std::hash<std::string>{}(p.boundary);
        std::size_t h4 = std::hash<std::string>{}(p.key);
        std::size_t h5 = std::hash<std::string>{}(p.keyword);
        std::size_t h6 = std::hash<std::string>{}(p.location);
        std::size_t h7 = std::hash<std::string>{}(p.from);
        std::size_t h8 = std::hash<std::string>{}(p.to);
        std::size_t h9 = std::hash<std::string>{}(p.locations);
        std::size_t h10 = std::hash<std::string>{}(p.type);
        return h1 ^ h2 ^ h3 ^ h4 ^ h5 ^ h6 ^ h7 ^ h8 ^ h9 ^ h10;
    }


    bool ParamStructEqual::operator()(const ParamStruct &p1, const ParamStruct &p2) const
    {
        return p1.address == p2.address && p1.region == p2.region && p1.boundary == p2.boundary && p1.key == p2.key && p1.keyword == p2.keyword && p1.location == p2.location && p1.from == p2.from && p1.to == p2.to && p1.locations == p2.locations && p1.type == p2.type;
    }
}
