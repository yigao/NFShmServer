// -------------------------------------------------------------------------
//    @FileName         :    ExcelParseAll.h
//    @Author           :    gaoyi
//    @Date             :    23-8-28
//    @Email			:    445267987@qq.com
//    @Module           :    ExcelParseAll
//
// -------------------------------------------------------------------------

#pragma once

#include "ExcelParse.h"
#include "ExcelParseCheck.h"

class ExcelParseAllCheck : public NFSingleton<ExcelParseAllCheck>
{
public:
    ExcelParseAllCheck();

    virtual ~ExcelParseAllCheck();

public:
    virtual int CheckExcel(const std::string& listFile);
    ExcelParseCheck* GetExcelParse(const std::string& excelName);
public:
    std::string m_listFile;
    std::unordered_map<std::string, ExcelParseCheck*> m_excelMap;
};