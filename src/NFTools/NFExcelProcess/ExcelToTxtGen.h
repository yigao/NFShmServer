// -------------------------------------------------------------------------
//    @FileName         :    ExcelToTxtGen.h
//    @Author           :    gaoyi
//    @Date             :    23-8-28
//    @Email			:    445267987@qq.com
//    @Module           :    ExcelToTxtGen
//
// -------------------------------------------------------------------------

#pragma once

#include "ExcelParse.h"

class ExcelToTxtGen : public ExcelParse, public NFSingleton<ExcelToTxtGen>
{
public:
    ExcelToTxtGen();

    virtual ~ExcelToTxtGen();
public:
    virtual int HandleExcel();
    int WriteToGen();
    int WriteToGen(MiniExcelReader::Sheet &sheet, std::string& fileStr);
};