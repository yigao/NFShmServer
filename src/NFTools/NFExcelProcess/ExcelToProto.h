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

struct ExcelRelation
{
    ExcelRelation()
    {

    }

    std::string excel_name;
    std::string sheet_name;
    std::string col_name;
};

struct ExcelSheetIndex
{
    ExcelSheetIndex()
    {
        m_unique = false;
        m_colIndex = -1;
        m_maxNum = 0;
        m_maxUniqueNum = 0;
        m_maxUniqueListNum = 0;
    }

    std::string m_key;
    bool m_unique;
    int m_colIndex;
    int m_maxNum;
    int m_maxUniqueNum;
    int m_maxUniqueListNum;
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

struct ExcelSheetColSubInfo
{
    ExcelSheetColSubInfo()
    {
        m_colTypeStrMaxSize = 32;
    }

    std::string m_enSubName;
    std::string m_cnSubName;
    std::string m_colType;
    uint32_t m_colTypeStrMaxSize;
};

struct ExcelSheetColInfo
{
    ExcelSheetColInfo()
    {
        m_colIndex = 0;
        m_colTypeStrMaxSize = 32;
        m_maxSubNum = 0;
        m_colUniqueKeys = 0;
        m_maxColNum = 0;
        m_colUniqueListKeys = 0;
    }

    uint32_t m_colIndex;
    std::string m_structEnName;
    std::string m_structCnName;
    std::string m_colType;
    uint32_t m_maxSubNum;
    uint32_t m_colTypeStrMaxSize;
    uint32_t m_colUniqueKeys;
    uint32_t m_colUniqueListKeys;
    uint32_t m_maxColNum;

    std::unordered_map<std::string, ExcelSheetColSubInfo> m_subInfoMap;
};

struct ExcelSheet
{
    std::string m_name;
    worksheet m_sheet;
    std::map<uint32_t, ExcelSheetColInfo*> m_colInfoVec;
    std::map<std::string, ExcelSheetColInfo *> m_colInfoMap;

    std::unordered_map<std::string, ExcelSheetIndex> m_indexMap;
    std::unordered_map<std::string, ExcelSheetComIndex> m_comIndexMap;
    std::unordered_map<std::string, ExcelRelation> m_colRelationMap;
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
    int HandleSheetList();
    int HandleSheetList(worksheet sheet);
public:
    int HandleSheetWork();
    int HandleSheetWork(worksheet sheet);
    int HandleSheetIndex();
public:
    void HandleColOtherInfo(cell_vector &col, const std::string& colType, uint32_t& uniqueKeysNum, uint32_t& uniqueKeysListNum, uint32_t &maxSize);
    int HandleColSubMsg(ExcelSheet *pSheet, int col_index, cell_vector &sheet_col, const std::string &struct_en_name,
                                      const std::string &struct_cn_name, const std::string &col_type, uint32_t struct_num,
                                      const std::string &struct_en_sub_name, const std::string &struct_cn_sub_name);
    int HandleColMsg(ExcelSheet *pSheet, int col_index, cell_vector &sheet_col, const std::string &struct_en_name,
                        const std::string &struct_cn_name, const std::string &col_type, uint32_t struct_num);
public:
    void WriteExcelProto();
    void WriteSheetProto(ExcelSheet* pSheet, std::string& write_str);
public:
    static int get_max_num(int num);
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
    std::string m_excelName;
    std::unordered_map<std::string, ExcelSheet> m_sheets;
    workbook m_workbook;
};

