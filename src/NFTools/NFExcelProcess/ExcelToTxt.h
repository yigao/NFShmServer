// -------------------------------------------------------------------------
//    @FileName         :    ExcelToTxt.h
//    @Author           :    gaoyi
//    @Date             :    23-8-28
//    @Email			:    445267987@qq.com
//    @Module           :    ExcelToTxt
//
// -------------------------------------------------------------------------

#pragma once

#include "ExcelParse.h"

class ExcelToTxt : public ExcelParse, public NFSingleton<ExcelToTxt>
{
public:
    ExcelToTxt();

    virtual ~ExcelToTxt();
public:
    virtual int HandleExcel();
    int WriteToTxt();
    int WriteToTxt(ExcelSheet& sheet);
    int WriteToTxt(ExcelSheet& sheet, int row, std::string& fileStr);
};