// -------------------------------------------------------------------------
//    @FileName         :    ExcelToProto.h
//    @Author           :    gaoyi
//    @Date             :    23-8-19
//    @Email			:    445267987@qq.com
//    @Module           :    ExcelToProto
//
// -------------------------------------------------------------------------

#pragma once

#include "Common.h"
#include "NFComm/NFCore/NFSingleton.hpp"

struct ExcelSheetIndex
{
    ExcelSheetIndex()
    {
        m_queue = false;
        m_colIndex = -1;
        m_maxNum = 0;
        m_maxQueueNum = 0;
    }

    std::string m_key;
    bool m_queue;
    int m_colIndex;
    int m_maxNum;
    int m_maxQueueNum;
};

struct ExcelSheetComIndex
{
    ExcelSheetComIndex()
    {
        m_queue = false;
    }

    std::string m_key;
    bool m_queue;
    std::vector<ExcelSheetIndex> m_index;
};

struct ExcelSheet
{
    std::string m_name;
    worksheet m_sheet;
    std::unordered_map<std::string, ExcelSheetIndex> m_indexMap;
    std::unordered_map<std::string, ExcelSheetComIndex> m_comIndexMap;
};

class ExcelToProto : public NFSingleton<ExcelToProto>
{
public:
    ExcelToProto();
    virtual ~ExcelToProto();
public:
    int Init(const std::string& excel, const std::string& outPath);
    int HandleExcel();
public:
    std::string m_descStoreHeadFile;
    std::string m_descStoreHeadFileStr;
    std::string m_descStoreDefineFile;
    std::string m_descStoreDefineFileStr;
    std::string m_descStoreRegisterFile;
    std::string m_descStoreRegisterFileStr;
public:
    std::string m_outPath;
    std::string m_excel;
    std::unordered_map<std::string, ExcelSheet> m_sheets;
};

