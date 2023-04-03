/** ****************************************************************************
 * @FilePath     : MyProject/MiddleWare/ParamStruct.h
 * @Description  : 
 * @Author       : Liujixin
 * @Date         : 2023-03-16 13:31:46
 * @Copyright (c) 2022 by CarNong, All Rights Reserved.
 ** ***************************************************************************/
#ifndef MYPROJECT_MIDDLEWARE_PARAMSTRUCT_H
#define MYPROJECT_MIDDLEWARE_PARAMSTRUCT_H
#include <string>
namespace LBS
{
    struct ParamStruct
    {
        std::string address = "";
        std::string region = "";
        std::string boundary = "";
        std::string key= "";
        std::string keyword = "";
        std::string location = "";
        std::string from = "";
        std::string to = "";
        std::string locations = "";
        std::string type = "";
    };

    struct ParamStructHash
    {
        std::size_t operator() (const ParamStruct& p) const;
    };

    struct ParamStructEqual
    {
        bool operator() (const ParamStruct& p1, const ParamStruct& p2) const;
    };
}
#endif