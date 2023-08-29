// -------------------------------------------------------------------------
//    @FileName         :    ExcelParseCheck.cpp
//    @Author           :    gaoyi
//    @Date             :    23-8-28
//    @Email			:    445267987@qq.com
//    @Module           :    ExcelParseCheck
//
// -------------------------------------------------------------------------

#include "ExcelParseCheck.h"
#include "ExcelParseAllCheck.h"

ExcelParseCheck::ExcelParseCheck()
{

}

ExcelParseCheck::~ExcelParseCheck()
{
}

int ExcelParseCheck::CheckExcel()
{
    bool flag = false;
    int iRet = CheckFirstCol();
    if (iRet != 0)
    {
        flag = true;
    }

    iRet = CheckUniqueIndex();
    if (iRet != 0)
    {
        flag = true;
    }

    if (flag)
    {
        return -1;
    }

    //NFLogInfo(NF_LOG_SYSTEMLOG, 0, "Check Excel:{} Index Success", m_excel);

    return 0;
}

int ExcelParseCheck::CheckFirstCol()
{
    bool flag = false;
    for (auto iter = m_sheets.begin(); iter != m_sheets.end(); iter++)
    {
        ExcelSheet &sheet = iter->second;
        if (sheet.m_colInfoMap.empty()) continue;

        int iRet = CheckFirstCol(sheet);
        if (iRet != 0)
        {
            flag = true;
        }
    }

    if (flag)
    {
        return -1;
    }
    return 0;
}

int ExcelParseCheck::CheckFirstCol(ExcelSheet &sheet)
{
    MiniExcelReader::Sheet *pExcelSheet = m_excelReader->getSheet(sheet.m_name);
    CHECK_EXPR(pExcelSheet, -1, "excel:{} Can't find sheet:{} data", m_excel, sheet.m_name);

    bool flag = false;
    auto iter = sheet.m_allColInfoList.begin();
    if (iter != sheet.m_allColInfoList.end())
    {
        ExcelSheetColIndex &sheelColIndex = iter->second;
        ExcelSheetColInfo *pColInfo = sheelColIndex.m_pColInfo;

        if (pColInfo->m_maxSubNum > 0 || pColInfo->m_subInfoMap.size() > 0)
        {
            NFLogError(NF_LOG_SYSTEMLOG, 0, "excel:{} sheet:{} the first col is not array", m_excelName, sheet.m_name);
            return -1;
        }

        int first_empty_row = -1;
        for (int row = sheet.m_protoInfo.m_startRow; row < (int) sheet.m_rows + 4; row++)
        {
            int col = iter->first;
            auto pCell = pExcelSheet->getCell(row, col);
            CHECK_EXPR(pCell, -1, "excel:{} can't get data, row:{} col:{}", row, col);
            std::string value = pCell->to_string();
            NFStringUtility::Trim(value);
            if (value.empty())
            {
                if (first_empty_row < 0)
                {
                    first_empty_row = row;
                }
            }
            else
            {
                if (first_empty_row >= 0)
                {
                    NFLogError(NF_LOG_SYSTEMLOG, 0, "excel:{} sheet:{} row:{} the first col not empty ", m_excelName, sheet.m_name, first_empty_row + 1);
                    first_empty_row = -1;
                    flag = true;
                }

                auto key_iter = sheet.m_firstColKeyMap.find(value);
                if (key_iter != sheet.m_firstColKeyMap.end())
                {
                    NFLogError(NF_LOG_SYSTEMLOG, 0, "excel:{} sheet:{} row:{} key:{} 与 row:{} key repeated, ", m_excelName, sheet.m_name, row + 1,
                               value, key_iter->second + 1);
                    flag = true;
                }
                sheet.m_firstColKeyMap.emplace(value, row);
            }
        }
    }

    if (flag)
    {
        return -1;
    }

    return 0;
}

int ExcelParseCheck::CheckUniqueIndex()
{
    bool flag = false;
    for (auto iter = m_sheets.begin(); iter != m_sheets.end(); iter++)
    {
        ExcelSheet &sheet = iter->second;
        if (sheet.m_colInfoMap.empty()) continue;

        int iRet = CheckUniqueIndex(sheet);
        if (iRet != 0)
        {
            flag = true;
        }
    }

    if (flag)
    {
        return -1;
    }
    return 0;
}

int ExcelParseCheck::CheckUniqueIndex(ExcelSheet &sheet)
{
    MiniExcelReader::Sheet *pExcelSheet = m_excelReader->getSheet(sheet.m_name);
    CHECK_EXPR(pExcelSheet, -1, "excel:{} Can't find sheet:{} data", m_excel, sheet.m_name);

    bool flag = false;
    for (auto iter = sheet.m_indexMap.begin(); iter != sheet.m_indexMap.end(); iter++)
    {
        ExcelSheetIndex &sheetIndex = iter->second;
        if (sheetIndex.m_unique)
        {
            int col = sheetIndex.m_colIndex;
            std::unordered_map<std::string, uint32_t> keyMap;
            for (int row = sheet.m_protoInfo.m_startRow; row < (int) sheet.m_rows + 4; row++)
            {
                auto pCell = pExcelSheet->getCell(row, col);
                CHECK_EXPR(pCell, -1, "excel:{} can't get data, row:{} col:{}", row, col);
                std::string value = pCell->to_string();
                NFStringUtility::Trim(value);
                auto key_iter = keyMap.find(value);
                if (key_iter != keyMap.end())
                {
                    NFLogError(NF_LOG_SYSTEMLOG, 0, "excel:{} sheet:{} col:{} row:{} ----- row:{} repeated key:{}", m_excelName, sheet.m_name,
                               col + 1, row + 1, key_iter->second + 1, value);
                    flag = true;
                }
                keyMap.emplace(value, row);
            }
        }
    }

    for (auto iter = sheet.m_comIndexMap.begin(); iter != sheet.m_comIndexMap.end(); iter++)
    {
        ExcelSheetComIndex &sheetComIndex = iter->second;
        if (sheetComIndex.m_unique)
        {
            std::unordered_map<std::string, uint32_t> keyMap;
            for (int row = sheet.m_protoInfo.m_startRow; row < (int) sheet.m_rows + 4; row++)
            {
                std::string key;
                std::string error = "(";
                for (int i = 0; i < (int) sheetComIndex.m_index.size(); i++)
                {
                    ExcelSheetIndex &sheetIndex = sheetComIndex.m_index[i];
                    int col = sheetIndex.m_colIndex;
                    auto pCell = pExcelSheet->getCell(row, col);
                    CHECK_EXPR(pCell, -1, "excel:{} can't get data, row:{} col:{}", row, col);
                    std::string value = pCell->to_string();
                    NFStringUtility::Trim(value);
                    key += value + "_";
                    error += "col:" + NFCommon::tostr(col+1) + " " + sheetIndex.m_key + ":" + value + ";";
                }
                error += ")";
                auto key_iter = keyMap.find(key);
                if (key_iter != keyMap.end())
                {
                    NFLogError(NF_LOG_SYSTEMLOG, 0, "excel:{} sheet:{} row:{} ----  row:{} repeated com key:{}", m_excelName, sheet.m_name,
                               row + 1, key_iter->second + 1, error);
                    flag = true;
                }
                keyMap.emplace(key, row);
            }
        }
    }

    if (flag)
    {
        return -1;
    }
    return 0;
}

int ExcelParseCheck::CheckRelation()
{
    for (auto iter = m_sheets.begin(); iter != m_sheets.end(); iter++)
    {
        ExcelSheet &sheet = iter->second;
        if (sheet.m_colInfoMap.empty()) continue;

        int iRet = CheckRelation(sheet);
        if (iRet != 0)
        {
            return iRet;
        }
    }

    //NFLogInfo(NF_LOG_SYSTEMLOG, 0, "Check Excel:{} Relation Success", m_excel);
    return 0;
}

int ExcelParseCheck::CheckRelation(ExcelSheet &sheet)
{
    MiniExcelReader::Sheet *pExcelSheet = m_excelReader->getSheet(sheet.m_name);
    CHECK_EXPR(pExcelSheet, -1, "excel:{} Can't find sheet:{} data", m_excel, sheet.m_name);

    bool flag = false;
    for (auto iter = sheet.m_colRelationMap.begin(); iter != sheet.m_colRelationMap.end(); iter++)
    {
        ExcelRelation &relation = iter->second;
        ExcelParseCheck *pFindExcel = ExcelParseAllCheck::Instance()->GetExcelParse(relation.m_excelName);
        CHECK_EXPR(pFindExcel, -1, "excel:{} sheet:{} colName:{} can't find the relation excel:{}", m_excelName, sheet.m_name, relation.m_mySrcColName, relation.m_excelName);
        ExcelSheet *pFindSheet = pFindExcel->GetExcelSheet(relation.m_sheetName);
        CHECK_EXPR(pFindSheet, -1, "excel:{} sheet:{} colName:{} can't find the relation excel:{} sheet:{}", m_excelName, sheet.m_name, relation.m_mySrcColName, relation.m_excelName,
                   relation.m_sheetName);

        CHECK_EXPR(sheet.m_colInfoMap.find(iter->second.m_myColName) != sheet.m_colInfoMap.end(), -1,
                   "excel:{} sheet:{} can't find the colName:{}", m_excelName, sheet.m_name, iter->second.m_mySrcColName);

        ExcelSheetColInfo *pColInfo = sheet.m_colInfoMap[iter->second.m_myColName];

        if (iter->second.m_myColSubName.empty())
        {
            if (pColInfo->m_maxSubNum == 0)
            {
                int col = pColInfo->m_colIndex;
                CHECK_EXPR(sheet.m_allColInfoList.find(col) != sheet.m_allColInfoList.end(), -1,
                           "excel:{} sheet:{} can't find the col:{} colName:{} info", m_excelName, sheet.m_name, col + 1, iter->second.m_mySrcColName);

                ExcelSheetColIndex *pColIndex = &sheet.m_allColInfoList[col];
                CHECK_EXPR(!pColIndex->m_isArray, -1, "excel:{} sheet:{} the col:{} colName:{} info is array", m_excelName, sheet.m_name, col + 1,
                           iter->second.m_mySrcColName);
                CHECK_EXPR(pColIndex->m_structNum == 0, -1, "excel:{} sheet:{} the col:{} colName:{} info struct num > 0", m_excelName, sheet.m_name,
                           col + 1, iter->second.m_mySrcColName);
                CHECK_EXPR(pColIndex->m_structEnName == iter->second.m_myColName, -1,
                           "excel:{} sheet:{} the col:{} colName:{} info en name not right", m_excelName, sheet.m_name, col + 1,
                           iter->second.m_mySrcColName);
                for (int row = sheet.m_protoInfo.m_startRow; row < (int) sheet.m_rows + 4; row++)
                {
                    auto pCell = pExcelSheet->getCell(row, col);
                    CHECK_EXPR(pCell, -1, "excel:{} can't get data, row:{} col:{}", row, col);
                    std::string value = pCell->to_string();
                    NFStringUtility::Trim(value);

                    if (pColInfo->m_colType != "string")
                    {
                        int64_t value64 = NFCommon::strto<int64_t>(value);
                        if (value64 == 0)
                        {
                            continue;
                        }
                    }

                    if (!pFindSheet->IsExist(value))
                    {
                        NFLogError(NF_LOG_SYSTEMLOG, 0, "excel:{} sheet:{} row:{} col:{} colName:{} key:{} is not exist in the excel:{} sheet:{} ", m_excelName,
                                   sheet.m_name, row+1, col+1, iter->second.m_mySrcColName, value, relation.m_excelName,
                                   relation.m_sheetName);
                        flag = true;
                    }
                }
            }
            else
            {
                if (pColInfo->m_subInfoMap.empty())
                {
                    for (int i = 0; i < (int) pColInfo->m_colIndexVec.size(); i++)
                    {
                        int col = pColInfo->m_colIndexVec[i];
                        CHECK_EXPR(sheet.m_allColInfoList.find(col) != sheet.m_allColInfoList.end(), -1,
                                   "excel:{} sheet:{} can't find the col:{} colName:{} info", m_excelName, sheet.m_name, col + 1,
                                   iter->second.m_mySrcColName);

                        ExcelSheetColIndex *pColIndex = &sheet.m_allColInfoList[col];
                        CHECK_EXPR(pColIndex->m_isArray, -1, "excel:{} sheet:{} the col:{} colName:{} info is not array", m_excelName, sheet.m_name,
                                   col + 1, iter->second.m_myColName);
                        CHECK_EXPR(pColIndex->m_structNum > 0, -1, "excel:{} sheet:{} the col:{} colName:{} info struct num <= 0", m_excelName,
                                   sheet.m_name, col + 1, iter->second.m_myColName);
                        CHECK_EXPR(pColIndex->m_structEnName == iter->second.m_myColName, -1,
                                   "excel:{} sheet:{} the col:{} colName:{}  en name not right", m_excelName, sheet.m_name, col + 1,
                                   iter->second.m_myColName);
                        for (int row = sheet.m_protoInfo.m_startRow; row < (int) sheet.m_rows + 4; row++)
                        {
                            auto pCell = pExcelSheet->getCell(row, col);
                            CHECK_EXPR(pCell, -1, "excel:{} can't get data, row:{} col:{}", row, col);
                            std::string value = pCell->to_string();
                            NFStringUtility::Trim(value);

                            if (pColInfo->m_colType != "string")
                            {
                                int64_t value64 = NFCommon::strto<int64_t>(value);
                                if (value64 == 0)
                                {
                                    continue;
                                }
                            }

                            if (!pFindSheet->IsExist(value))
                            {
                                NFLogError(NF_LOG_SYSTEMLOG, 0, "excel:{} sheet:{} row:{} col:{} colName:{} key:{} is not exist in the excel:{} sheet:{} ",
                                           m_excelName,
                                           sheet.m_name, row+1, col+1, iter->second.m_mySrcColName, value, relation.m_excelName,
                                           relation.m_sheetName);
                                flag = true;
                            }
                        }
                    }
                }
                else
                {
                    CHECK_EXPR(pColInfo->m_subInfoMap.find(iter->second.m_myColName) != pColInfo->m_subInfoMap.end(), -1,
                               "excel:{} sheet:{} can't find the colName:{}", m_excelName, sheet.m_name, iter->second.m_mySrcColName);
                    ExcelSheetColSubInfo &subInfo = pColInfo->m_subInfoMap[iter->second.m_myColName];
                    for (int i = 0; i < (int) subInfo.m_colIndexVec.size(); i++)
                    {
                        int col = subInfo.m_colIndexVec[i];
                        CHECK_EXPR(sheet.m_allColInfoList.find(col) != sheet.m_allColInfoList.end(), -1,
                                   "excel:{} sheet:{} can't find the col:{} colName:{} info", m_excelName, sheet.m_name, col + 1,
                                   iter->second.m_myColName);

                        ExcelSheetColIndex *pColIndex = &sheet.m_allColInfoList[col];
                        CHECK_EXPR(pColIndex->m_isArray, -1, "excel:{} sheet:{} the col:{} colName:{} info is not array", m_excelName, sheet.m_name,
                                   col + 1, iter->second.m_myColName);
                        CHECK_EXPR(pColIndex->m_structNum > 0, -1, "excel:{} sheet:{} the col:{} colName:{} info struct num <= 0", m_excelName,
                                   sheet.m_name, col + 1, iter->second.m_myColName);
                        CHECK_EXPR(pColIndex->m_structEnName == iter->second.m_myColName, -1,
                                   "excel:{} sheet:{} the col:{} colName:{}  en name not right", m_excelName, sheet.m_name, col + 1,
                                   iter->second.m_myColName);
                        for (int row = sheet.m_protoInfo.m_startRow; row < (int) sheet.m_rows + 4; row++)
                        {
                            auto pCell = pExcelSheet->getCell(row, col);
                            CHECK_EXPR(pCell, -1, "excel:{} can't get data, row:{} col:{}", row, col);
                            std::string value = pCell->to_string();
                            NFStringUtility::Trim(value);

                            if (pColInfo->m_colType != "string")
                            {
                                int64_t value64 = NFCommon::strto<int64_t>(value);
                                if (value64 == 0)
                                {
                                    continue;
                                }
                            }

                            if (!pFindSheet->IsExist(value))
                            {
                                NFLogError(NF_LOG_SYSTEMLOG, 0, "excel:{} sheet:{} row:{} col:{} colName:{} key:{} is not exist in the excel:{} sheet:{} ",
                                           m_excelName,
                                           sheet.m_name, row+1, col+1, iter->second.m_myColName, value, relation.m_excelName,
                                           relation.m_sheetName);
                                flag = true;
                            }
                        }
                    }
                }
            }
        }
        else
        {
            CHECK_EXPR(pColInfo->m_subInfoMap.find(iter->second.m_myColSubName) != pColInfo->m_subInfoMap.end(), -1,
                       "excel:{} sheet:{} can't find the colName:{}", m_excelName, sheet.m_name, iter->second.m_mySrcColName);
            ExcelSheetColSubInfo &subInfo = pColInfo->m_subInfoMap[iter->second.m_myColSubName];
            for (int i = 0; i < (int) subInfo.m_colIndexVec.size(); i++)
            {
                int col = subInfo.m_colIndexVec[i];
                CHECK_EXPR(sheet.m_allColInfoList.find(col) != sheet.m_allColInfoList.end(), -1,
                           "excel:{} sheet:{} can't find the col:{} colName:{} info", m_excelName, sheet.m_name, col + 1,
                           iter->second.m_mySrcColName);

                ExcelSheetColIndex *pColIndex = &sheet.m_allColInfoList[col];
                CHECK_EXPR(pColIndex->m_isArray, -1, "excel:{} sheet:{} the col:{} colName:{} info is not array", m_excelName, sheet.m_name, col + 1,
                           iter->second.m_myColName);
                CHECK_EXPR(pColIndex->m_structNum > 0, -1, "excel:{} sheet:{} the col:{} colName:{} info struct num <= 0", m_excelName, sheet.m_name,
                           col + 1, iter->second.m_myColName);
                CHECK_EXPR(pColIndex->m_structEnName == iter->second.m_myColName && pColIndex->m_structSubEnName == iter->second.m_myColSubName, -1,
                           "excel:{} sheet:{} the col:{} colName:{} subColName:{}  en name not right",
                           m_excelName, sheet.m_name, col + 1, iter->second.m_myColName, iter->second.m_myColSubName);
                for (int row = sheet.m_protoInfo.m_startRow; row < (int) sheet.m_rows + 4; row++)
                {
                    auto pCell = pExcelSheet->getCell(row, col);
                    CHECK_EXPR(pCell, -1, "excel:{} can't get data, row:{} col:{}", row, col);
                    std::string value = pCell->to_string();
                    NFStringUtility::Trim(value);

                    if (pColInfo->m_colType != "string")
                    {
                        int64_t value64 = NFCommon::strto<int64_t>(value);
                        if (value64 == 0)
                        {
                            continue;
                        }
                    }

                    if (!pFindSheet->IsExist(value))
                    {
                        NFLogError(NF_LOG_SYSTEMLOG, 0, "excel:{} sheet:{} row:{} col:{} colName:{} key:{} is not exist in the excel:{} sheet:{} ", m_excelName,
                                   sheet.m_name, row + 1, col + 1, iter->second.m_mySrcColName, value, relation.m_excelName,
                                   relation.m_sheetName);
                        flag = true;
                    }
                }
            }
        }
    }

    if (flag)
    {
        return -1;
    }
    return 0;
}

