// -------------------------------------------------------------------------
//    @FileName         :    ExcelParseCheck.h
//    @Author           :    gaoyi
//    @Date             :    23-8-28
//    @Email			:    445267987@qq.com
//    @Module           :    ExcelParseCheck
//
// -------------------------------------------------------------------------

#pragma once

#include "ExcelParse.h"

class ExcelParseCheck : public ExcelParse
{
public:
    ExcelParseCheck();

    virtual ~ExcelParseCheck();
public:
    virtual int CheckExcel();
public:
    int CheckFirstCol();
    int CheckFirstCol(ExcelSheet& sheet);
    int CheckUniqueIndex();
    int CheckUniqueIndex(ExcelSheet& sheet);
    int CheckRelation();
    int FindRelation(ExcelSheet& sheet);
    int CheckRelation(ExcelSheet& sheet);
};