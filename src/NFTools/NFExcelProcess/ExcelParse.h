// -------------------------------------------------------------------------
//    @FileName         :    ExcelParse.h
//    @Author           :    gaoyi
//    @Date             :    23-8-26
//    @Email			:    445267987@qq.com
//    @Module           :    ExcelParse
//
// -------------------------------------------------------------------------

#pragma once

#include "NFComm/NFCore/NFSingleton.hpp"
#include "NFComm/NFCore/NFPlatform.h"
#include "NFComm/NFPluginModule/NFCheck.h"
#include "Common.h"
#include "MiniExcelReader.h"

class ExcelParseCheck;
class ExcelSheet;
class ExcelRelationDst
{
public:
    ExcelRelationDst()
    {
        m_pExcel = NULL;
        m_pSheet = NULL;
    }

    std::string m_excelName;
    std::string m_sheetName;
    ExcelParseCheck* m_pExcel;
    ExcelSheet* m_pSheet;
};

struct ExcelRelation
{
    ExcelRelation()
    {

    }

	std::string m_myColName;
	std::string m_myColSubName;
	std::string m_mySrcColName;
    std::vector<ExcelRelationDst> m_dst;
    std::string m_noFindError;
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

    std::string m_max_num_by_key;
    std::string m_unique_num; /**/
};

struct ExcelSheetComIndex
{
    ExcelSheetComIndex()
    {
        m_unique = false;
    }

    std::string m_key;
    bool m_unique;
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
    std::vector<uint32_t> m_colIndexVec;
};

struct ExcelSheetColInfo
{
    ExcelSheetColInfo()
    {
        m_colIndex = 0;
        m_colTypeStrMaxSize = 32;
        m_maxSubNum = 0;
        m_colUniqueKeys = 0;
        m_maxRowNum = 0;
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
    uint32_t m_maxRowNum;
    std::vector<uint32_t> m_colIndexVec;

    std::unordered_map<std::string, ExcelSheetColSubInfo> m_subInfoMap;
};

/**
 * @brief --proto_package=proto_ff \
		--proto_sheet_msgname=Sheet_AchievementAchievement
		--excel_sheetname=achievement  --proto_msgname=E_AchievementAchievement  --start_row=4 --dst=${PROTOCGEN_FILE_PATH}/;
 */
struct ExcelSheetProtoInfo
{
    ExcelSheetProtoInfo()
    {
        m_protoPackage = "proto_ff";
        m_startRow = 4;
    }

    std::string m_protoPackage;
    std::string m_sheetMsgName;
    std::string m_sheetName;
    std::string m_protoMsgName;
    uint32_t m_startRow;
};

struct ExcelSheetColIndex
{
    ExcelSheetColIndex()
    {
        m_pColInfo = NULL;
        m_isSpecial = false;
        m_isArray = false;
        m_structNum = 0;
    }

    ExcelSheetColInfo* m_pColInfo;
    uint32_t m_colIndex;
    std::string m_structEnName;
    std::string m_structSubEnName;
    bool m_isArray;
    /**
     * @brief 特殊情况 itemid item_num itemid item_num
     *                xx1   xx1num    xx2    xx2num
     */
    bool m_isSpecial;
    uint32_t m_structNum;
    std::string m_fullEnName;
};

struct ExcelSheet
{
    ExcelSheet()
    {
        m_rows = 0;
        m_createSql = false;
    }

    ~ExcelSheet()
    {
        for (auto iter = m_colInfoMap.begin(); iter != m_colInfoMap.end(); iter++)
        {
            delete iter->second;
        }
    }

    std::string m_name;
    uint32_t m_rows;
    std::map<uint32_t, ExcelSheetColInfo*> m_colInfoVec;
    std::map<std::string, ExcelSheetColInfo *> m_colInfoMap;
    std::map<uint32_t, ExcelSheetColIndex> m_allColInfoList;
    std::set<std::string> m_allFullEnName;

    std::unordered_map<std::string, ExcelSheetIndex> m_indexMap;
    std::unordered_map<std::string, ExcelSheetComIndex> m_comIndexMap;
    std::unordered_map<std::string, ExcelRelation> m_colRelationMap;

    ExcelSheetProtoInfo m_protoInfo;

    std::unordered_map<std::string, int> m_firstColKeyMap;

    bool m_createSql;

    bool IsExist(const std::string& firstColKey)
    {
        return m_firstColKeyMap.find(firstColKey) != m_firstColKeyMap.end();
    }
};

class ExcelParse
{
public:
    ExcelParse();

    virtual ~ExcelParse();
public:
    virtual int Init(const std::string& excel, const std::string& outPath, bool all = true);
    virtual int HandleExcel();
public:
    virtual int HandleSheetList();
    virtual int HandleSheetList(MiniExcelReader::Sheet& sheet);
public:
    virtual int HandleSheetWork();
    virtual int HandleSheetWork(MiniExcelReader::Sheet& sheet);
    virtual int HandleSheetIndex();
public:
    virtual void HandleColOtherInfo(int col_index, MiniExcelReader::Sheet& sheet, const std::string& colType, uint32_t& uniqueKeysNum, uint32_t& uniqueKeysListNum, uint32_t &maxSize);
    virtual int HandleColSubMsg(ExcelSheet *pSheet, int col_index, MiniExcelReader::Sheet& sheet, const std::string &struct_en_name,
                        const std::string &struct_cn_name, const std::string &col_type, uint32_t struct_num,
                        const std::string &struct_en_sub_name, const std::string &struct_cn_sub_name, bool is_special);
    virtual int HandleColMsg(ExcelSheet *pSheet, int col_index, MiniExcelReader::Sheet& sheet, const std::string &struct_en_name,
                     const std::string &struct_cn_name, const std::string &col_type, uint32_t struct_num);
public:
    virtual int get_max_num(int num);
    ExcelSheet* GetExcelSheet(const std::string& sheetName);
public:
    std::string m_outPath;
    std::string m_excel;
    std::string m_excelName;
    std::unordered_map<std::string, ExcelSheet> m_sheets;
    MiniExcelReader::ExcelFile* m_excelReader;
};