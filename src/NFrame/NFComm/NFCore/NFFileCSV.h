// -------------------------------------------------------------------------
//    @FileName         :    NFFileCSV.h
//    @Author           :    Gao.Yi
//    @Date             :   2022-09-18
//    @Email			:    445267987@qq.com
//    @Module           :    NFFileCSV.h
//
// -------------------------------------------------------------------------

#pragma once

#include <vector>
#include <string>
#include "NFFileUtility.h"
#include "NFStringUtility.h"
#include "NFCommon.h"

class NFFileCSV {
public:
    static bool ReadCsvFile(const std::string &szFileName, std::vector<std::vector<std::string>> &table);

    static bool WriteCsvFile(const std::string &szFileName, const std::vector<std::vector<std::string>> &table);
};