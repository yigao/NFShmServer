// -------------------------------------------------------------------------
//    @FileName         :    ExcelToProto.h
//    @Author           :    gaoyi
//    @Date             :    23-8-19
//    @Email			:    445267987@qq.com
//    @Module           :    ExcelToProto
//
// -------------------------------------------------------------------------

#pragma once

#include "ExcelParse.h"

class ExcelToProto : public ExcelParse, public NFSingleton<ExcelToProto>
{
public:
    ExcelToProto();
    virtual ~ExcelToProto();
public:
    virtual int HandleExcel();
    virtual void HandleColOtherInfo(int col_index, MiniExcelReader::Sheet& sheet, const std::string& colType, uint32_t& uniqueKeysNum, uint32_t& uniqueKeysListNum, uint32_t &maxSize);
public:
    void WriteExcelProto();
    void WriteSheetProto(ExcelSheet* pSheet, std::string& write_str);
    void WriteSheetDescStoreH(ExcelSheet* pSheet);
    void WriteSheetDescStoreCPP(ExcelSheet* pSheet);
    void WriteSheetDescStore();
    void WriteMakeFile();
    void WriteDestStoreDefine();

};

