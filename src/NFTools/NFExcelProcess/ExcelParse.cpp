// -------------------------------------------------------------------------
//    @FileName         :    ExcelParse.cpp
//    @Author           :    gaoyi
//    @Date             :    23-8-26
//    @Email			:    445267987@qq.com
//    @Module           :    ExcelParse
//
// -------------------------------------------------------------------------

#include "ExcelParse.h"

ExcelParse::ExcelParse()
{

}

ExcelParse::~ExcelParse()
{
}


int ExcelParse::Init(const std::string &excel, const std::string &outPath, bool all)
{
    m_excel = excel;
    m_outPath = outPath;
    NFStringUtility::Trim(m_excel);
    NFStringUtility::Trim(m_outPath);
    m_outPath = NFFileUtility::NormalizePath(m_outPath);
    m_excelName = NFFileUtility::GetFileNameWithoutExt(m_excel);

    CHECK_EXPR(NFFileUtility::IsFileExist(m_excel), -1, "excel:{} not exist", m_excel);
    CHECK_EXPR(NFFileUtility::IsDir(m_outPath), -1, "outPath:{} not exist", m_outPath);

    m_excelReader = new MiniExcelReader::ExcelFile();
    if (!m_excelReader->open(m_excel.c_str(), all))
    {
        NFLogError(NF_LOG_SYSTEMLOG, 0, "load excel:{} failed", m_excel);
        NFSLEEP(1000);
        exit(-1);
    }

    return 0;
}

int ExcelParse::HandleExcel()
{
    int iRet = HandleSheetList();
    if (iRet != 0)
    {
        return iRet;
    }

    iRet = HandleSheetWork();
    if (iRet != 0)
    {
        return iRet;
    }

    iRet = HandleSheetIndex();
    if (iRet != 0)
    {
        return iRet;
    }

    return 0;
}

int ExcelParse::HandleSheetList()
{
    //首先处理list
    std::vector<MiniExcelReader::Sheet> &sheets = m_excelReader->sheets();
    for (MiniExcelReader::Sheet &sheet: sheets)
    {
        if (sheet.title() == "main")
        {
            //NFLogInfo(NF_LOG_SYSTEMLOG, 0, "handle excel:{} sheet:{}", m_excel, sheet.title());
        }
        else if (sheet.title() == "list")
        {
            //NFLogInfo(NF_LOG_SYSTEMLOG, 0, "handle excel:{} sheet:{}", m_excel, sheet.title());
            int iRet = HandleSheetList(sheet);
            if (iRet != 0)
            {
                return iRet;
            }
        }
    }

    return 0;
}


int ExcelParse::HandleSheetList(MiniExcelReader::Sheet &sheet)
{
    if (sheet.title() != "list") return -1;

    auto rows = sheet.rows();
    auto cols = sheet.cols();
    if (rows <= 0 || cols <= 0) return 0;

    //list表的第一行第一个自动有sheet_name的话，这一行只是用来提示功能，第二列是unique_index唯一索引，multi_index不唯一所有，check用来检查列关联到的表数据是否存在
    int start_row = 0;
    auto pCell0 = sheet.getCell(0, 0);
    if (pCell0 && pCell0->to_string() == "sheet_name")
    {
        start_row = 1;
    }

    for (int row = start_row; row < (int) rows; row++)
    {
        auto col_sheet_cell = sheet.getCell(row, 0);
        std::string sheet_name = col_sheet_cell->to_string();
        if (sheet_name.empty())
        {
            continue;
        }

        auto find_sheet = m_excelReader->getSheet(sheet_name);
        if (find_sheet == nullptr)
        {
            NFLogError(NF_LOG_SYSTEMLOG, 0, "excel:{} list has sheet:{}, but can't find in the excel", m_excel, sheet_name);
            continue;
        }

        ExcelSheet &excelSheet = m_sheets[sheet_name];
        excelSheet.m_name = sheet_name;
        excelSheet.m_rows = find_sheet->rows() - 4;

        for (int col = 1; col < (int) cols; col++)
        {
            if (col != 1 && col != 2) continue;

            auto col_index = sheet.getCell(row, col);
            CHECK_EXPR(col_index, -1, "sheet.getCell(row:{}, col:{})", row, col);
            std::string col_index_str = col_index->to_string();
            NFStringUtility::Trim(col_index_str);
            if (col_index_str.empty()) continue;

            bool sheet_index_unique = true;
            if (col == 2)
            {
                sheet_index_unique = false;
            }

            std::vector<std::string> col_index_str_list;
            NFStringUtility::Split(col_index_str, ";", &col_index_str_list);

            for (int j = 0; j < (int) col_index_str_list.size(); j++)
            {
                std::string col_index_str_list_str = col_index_str_list[j];
                NFStringUtility::Trim(col_index_str_list_str);
                if (col_index_str_list_str.empty()) continue;

                std::vector<std::string> col_index_str_vec;
                NFStringUtility::Split(col_index_str_list[j], ",", &col_index_str_vec);

                if (col_index_str_vec.size() == 1)
                {
                    std::string key = col_index_str_vec[0];
                    NFStringUtility::Trim(key);
                    if (key.empty()) continue;

                    ExcelSheetIndex &excelSheetIndex = excelSheet.m_indexMap[key];
                    excelSheetIndex.m_key = key;
                    excelSheetIndex.m_unique = sheet_index_unique;
                    excelSheetIndex.m_colIndex = -1;
                    excelSheetIndex.m_maxNum = 0;
                    excelSheetIndex.m_maxUniqueNum = 0;

                    NFLogInfo(NF_LOG_SYSTEMLOG, 0, "excel:{} sheet:{} add index:{}", m_excel, sheet_name, key);
                }
                else
                {
                    ExcelSheetComIndex &excelSheetComIndex = excelSheet.m_comIndexMap[col_index_str];
                    excelSheetComIndex.m_key = col_index_str;
                    excelSheetComIndex.m_unique = sheet_index_unique;

                    for (int x = 0; x < (int) col_index_str_vec.size(); x++)
                    {
                        std::string key = col_index_str_vec[x];
                        NFStringUtility::Trim(key);
                        if (key.empty()) continue;

                        ExcelSheetIndex excelSheetIndex;
                        excelSheetIndex.m_key = key;
                        excelSheetIndex.m_unique = true;
                        excelSheetIndex.m_colIndex = -1;
                        excelSheetIndex.m_maxNum = 0;
                        excelSheetIndex.m_maxUniqueNum = 0;
                        excelSheetComIndex.m_index.push_back(excelSheetIndex);
                    }
                    //NFLogInfo(NF_LOG_SYSTEMLOG, 0, "excel:{} sheet:{} add com_index:{}", m_excel, sheet_name, col_index_str);
                }
            }
        }

        if (cols >= 4)
        {
            auto col_index = sheet.getCell(row, 3);
            CHECK_EXPR(col_index, -1, "sheet.getCell(row, 3) NULL");
            std::string col_index_str = col_index->to_string();
            NFStringUtility::Trim(col_index_str);
            if (col_index_str.empty()) continue;

            std::vector<std::string> col_index_str_list;
            NFStringUtility::Split(col_index_str, ";", &col_index_str_list);

            for (int j = 0; j < (int) col_index_str_list.size(); j++)
            {
                std::string relation_str = col_index_str_list[j];
                NFStringUtility::Trim(relation_str);
                if (relation_str.empty()) continue;

                std::vector<std::string> relation_str_vec;
                NFStringUtility::Split(relation_str, ":", &relation_str_vec);

                if (relation_str_vec.size() != 2)
                {
                    NFLogError(NF_LOG_SYSTEMLOG, 0, "the relation:{} is not right", relation_str);
                    return -1;
                }

                std::string my_col_name = relation_str_vec[0];
                std::string dst_relation_str = relation_str_vec[1];

                if (my_col_name.empty() || dst_relation_str.empty())
                {
                    NFLogError(NF_LOG_SYSTEMLOG, 0, "the relation:{} is not right", relation_str);
                    return -1;
                }

                std::vector<std::string> my_col_str_vec;
                NFStringUtility::Split(my_col_name, "_", &my_col_str_vec);

                if (my_col_str_vec.size() > 2 || my_col_str_vec.size() <= 0)
                {
                    NFLogError(NF_LOG_SYSTEMLOG, 0, "the relation:{} is not right", relation_str);
                    return -1;
                }

                std::vector<std::string> dst_relation_str_vec;
                NFStringUtility::Split(dst_relation_str, ".", &dst_relation_str_vec);

                if (dst_relation_str_vec.size() != 2)
                {
                    NFLogError(NF_LOG_SYSTEMLOG, 0, "the relation:{} is not right", relation_str);
                    return -1;
                }

                ExcelRelation relation;
                relation.m_excelName = dst_relation_str_vec[0];
                relation.m_sheetName = dst_relation_str_vec[1];
                relation.m_myColName = my_col_str_vec[0];
                relation.m_mySrcColName = my_col_name;
                if (my_col_str_vec.size() == 2)
                {
                    relation.m_myColSubName = my_col_str_vec[1];
                }

                if (relation.m_excelName.empty() || relation.m_sheetName.empty())
                {
                    NFLogError(NF_LOG_SYSTEMLOG, 0, "the relation:{} is not right", relation_str);
                    return -1;
                }

                if (relation.m_myColSubName.empty())
                {
                    if (excelSheet.m_colRelationMap.find(relation.m_myColName) != excelSheet.m_colRelationMap.end())
                    {
                        NFLogError(NF_LOG_SYSTEMLOG, 0, "the relation:{} is not right, repeated", relation_str);
                        return -1;
                    }
                    excelSheet.m_colRelationMap.emplace(relation.m_myColName, relation);
                }
                else
                {
                    if (excelSheet.m_colRelationMap.find(relation.m_myColName + "_" + relation.m_myColSubName) != excelSheet.m_colRelationMap.end())
                    {
                        NFLogError(NF_LOG_SYSTEMLOG, 0, "the relation:{} is not right, repeated", relation_str);
                        return -1;
                    }
                    excelSheet.m_colRelationMap.emplace(relation.m_myColName + "_" + relation.m_myColSubName, relation);
                }

                //NFLogInfo(NF_LOG_SYSTEMLOG, 0, "excel:{} sheet:{} add relation:{}:{}", m_excel, sheet_name, my_col_name,
                //          dst_relation_str);
            }
        }
    }

    return 0;
}

int ExcelParse::HandleSheetWork()
{
    std::vector<MiniExcelReader::Sheet> &sheets = m_excelReader->sheets();
    for (MiniExcelReader::Sheet &sheet: sheets)
    {
        if (m_sheets.find(sheet.title()) != m_sheets.end())
        {
            //NFLogInfo(NF_LOG_SYSTEMLOG, 0, "handle excel:{} sheet:{}", m_excel, sheet.title());
            int iRet = HandleSheetWork(sheet);
            if (iRet != 0)
            {
                return iRet;
            }
        }
    }
    //NFLogInfo(NF_LOG_SYSTEMLOG, 0, "parse excel:{} success", m_excel);

    return 0;
}

int ExcelParse::HandleSheetWork(MiniExcelReader::Sheet &sheet)
{
    int rows = sheet.rows();
    int cols = sheet.cols();

    CHECK_EXPR(rows >= 4 && cols >= 1, -1, "sheet:{} rows:{} cols:{} not supported", sheet.title(), rows, cols);

    ExcelSheet *pSheet = &m_sheets[sheet.title()];

    for (int col_index = 0; col_index < cols; col_index++)
    {
        std::string col_en_name = sheet.getCell(0, col_index)->to_string();
        std::string col_cn_name = sheet.getCell(1, col_index)->to_string();
        std::string col_type = sheet.getCell(2, col_index)->to_string();
        std::string col_sel_str = sheet.getCell(3, col_index)->to_string();
        NFStringUtility::Trim(col_en_name);
        NFStringUtility::Trim(col_cn_name);
        NFStringUtility::Trim(col_type);
        NFStringUtility::Trim(col_sel_str);

        if (col_en_name.empty() || col_cn_name.empty() || col_type.empty() || col_sel_str.empty())
        {
            continue;
        }

        int col_sel = NFCommon::strto<int>(col_sel_str);
        if (col_sel != 2 && col_sel != 3)
            continue;

        std::vector<std::string> col_en_name_list;
        NFStringUtility::Split(col_en_name, "_", &col_en_name_list);
        for (int i = 0; i < (int) col_en_name_list.size(); i++)
        {
            NFStringUtility::Trim(col_en_name_list[i]);
        }

        std::vector<std::string> col_cn_name_list;
        NFStringUtility::SplitDigit(col_cn_name, &col_cn_name_list);
        for (int i = 0; i < (int) col_cn_name_list.size(); i++)
        {
            NFStringUtility::Trim(col_cn_name_list[i]);
        }

        if (col_en_name_list.size() == 2 and col_cn_name_list.size() == 3)
        {
            /** 处理正常数组
             * @brief item_id item_num item_id item_num
             *        物品1Id  物品1Num 物品2Id    物品2Num
             */
            if (col_en_name_list[0].size() > 0 && col_en_name_list[1].size() > 0
                && col_cn_name_list[0].size() > 0 && col_cn_name_list[1].size() > 0 && col_cn_name_list[2].size() > 0)
            {
                std::string struct_en_name = col_en_name_list[0];
                std::string struct_en_sub_name = col_en_name_list[1];
                std::string struct_cn_name = col_cn_name_list[0];
                uint32_t struct_num = NFCommon::strto<uint32_t>(col_cn_name_list[1]);
                std::string struct_cn_sub_name = col_cn_name_list[2];

                int iRet = HandleColSubMsg(pSheet, col_index, sheet, struct_en_name, struct_cn_name, col_type, struct_num,
                                           struct_en_sub_name, struct_cn_sub_name, false);
                CHECK_EXPR(iRet == 0, -1, "excel:{} sheet:{} col_en_name:{} col_cn_name:{} is not right", m_excel,
                           pSheet->m_name, col_en_name, col_cn_name);
            }
            else if (col_en_name_list[0].size() > 0 && col_en_name_list[1].size() > 0
                     && col_cn_name_list[0].size() == 0 && col_cn_name_list[1].size() > 0 && col_cn_name_list[2].size() > 0)
            {
                std::string struct_en_name = col_en_name_list[0];
                std::string struct_en_sub_name = col_en_name_list[1];
                std::string struct_cn_name = col_cn_name_list[2];
                uint32_t struct_num = NFCommon::strto<uint32_t>(col_cn_name_list[1]);
                std::string struct_cn_sub_name = col_cn_name_list[2];

                int iRet = HandleColSubMsg(pSheet, col_index, sheet, struct_en_name, struct_cn_name, col_type, struct_num,
                                           struct_en_sub_name, struct_cn_sub_name, false);
                CHECK_EXPR(iRet == 0, -1, "excel:{} sheet:{} col_en_name:{} col_cn_name:{} is not right", m_excel,
                           pSheet->m_name, col_en_name, col_cn_name);
            }
                /** 处理数组特殊情况
                 * @brief item_id item_num item_id item_num
                 *        物品1    物品1Num     物品2    物品2Num
                 */
                /** 处理数组特殊情况
                 * @brief item_id item_num item_id item_num
                 *        物品1    物x1     物品2    物x2
                 */
            else if (col_en_name_list[0].size() > 0 && col_en_name_list[1].size() > 0
                     && col_cn_name_list[0].size() > 0 && col_cn_name_list[1].size() > 0 && col_cn_name_list[2].size() == 0)
            {
                bool has_diff = false;

                for (int col_index_temp = 0; col_index_temp < cols; col_index_temp++)
                {
                    if (col_index_temp == col_index) continue;

                    std::string col_en_name_temp = sheet.getCell(0, col_index_temp)->to_string();
                    std::string col_cn_name_temp = sheet.getCell(1, col_index_temp)->to_string();
                    std::string col_type_temp = sheet.getCell(2, col_index_temp)->to_string();
                    std::string col_sel_temp_str = sheet.getCell(3, col_index_temp)->to_string();
                    NFStringUtility::Trim(col_en_name_temp);
                    NFStringUtility::Trim(col_cn_name_temp);
                    NFStringUtility::Trim(col_type_temp);
                    NFStringUtility::Trim(col_sel_temp_str);

                    int col_temp_sel = NFCommon::strto<int>(col_sel_temp_str);
                    if (col_temp_sel != 2 && col_temp_sel != 3)
                        continue;

                    std::vector<std::string> col_en_name_list_temp;
                    NFStringUtility::Split(col_en_name_temp, "_", &col_en_name_list_temp);
                    for (int i = 0; i < (int) col_en_name_list_temp.size(); i++)
                    {
                        NFStringUtility::Trim(col_en_name_list_temp[i]);
                    }

                    std::vector<std::string> col_cn_name_list_temp;
                    NFStringUtility::SplitDigit(col_cn_name_temp, &col_cn_name_list_temp);
                    for (int i = 0; i < (int) col_cn_name_list_temp.size(); i++)
                    {
                        NFStringUtility::Trim(col_cn_name_list_temp[i]);
                    }

                    /** 处理数组特殊情况
                     * @brief item_id item_num item_id item_num
                     *        物品1    物品1Num     物品2    物品2Num
                     */
                    if (col_en_name_list_temp.size() == 2 && col_en_name_temp != col_en_name && col_en_name_list_temp[0] == col_en_name_list[0]
                        && col_cn_name_list_temp.size() == 3 && col_cn_name_list_temp[1].size() > 0)
                    {
                        has_diff = true;
                        break;
                    }
                }

                /** 处理数组特殊情况
                 * @brief item_id item_num item_id item_num
                 *        物品1    物品1Num     物品2    物品2Num
                 */
                if (has_diff)
                {
                    std::string struct_en_name = col_en_name_list[0];
                    std::string struct_en_sub_name = col_en_name_list[1];
                    std::string struct_cn_name = col_cn_name_list[0];
                    uint32_t struct_num = NFCommon::strto<uint32_t>(col_cn_name_list[1]);
                    std::string struct_cn_sub_name = col_cn_name_list[0];

                    int iRet = HandleColSubMsg(pSheet, col_index, sheet, struct_en_name, struct_cn_name, col_type, struct_num,
                                               struct_en_sub_name, struct_cn_sub_name, false);
                    CHECK_EXPR(iRet == 0, -1, "excel:{} sheet:{} col_en_name:{} col_cn_name:{} is not right", m_excel,
                               pSheet->m_name, col_en_name, col_cn_name);
                }
                    /** 其余情况
                     * @brief item_id itemnum
                     *        物品1    物x1
                     */
                else
                {
                    uint32_t struct_num = NFCommon::strto<uint32_t>(col_cn_name_list[1]);
                    std::string struct_en_name = col_en_name;
                    std::string struct_cn_name = col_cn_name_list[0];
                    int iRet = HandleColMsg(pSheet, col_index, sheet, struct_en_name, struct_cn_name, col_type, struct_num);
                    CHECK_EXPR(iRet == 0, -1, "excel:{} sheet:{} col_en_name:{} col_cn_name:{} is not right", m_excel,
                               pSheet->m_name, col_en_name, col_cn_name);
                }
            }
            else if (col_en_name_list[0].size() > 0 && col_en_name_list[1].size() > 0
                     && col_cn_name_list[0].size() == 0 && col_cn_name_list[1].size() > 0 && col_cn_name_list[2].size() == 0)
            {
                bool has_diff = false;

                for (int col_index_temp = 0; col_index_temp < cols; col_index_temp++)
                {
                    if (col_index_temp == col_index) continue;

                    std::string col_en_name_temp = sheet.getCell(0, col_index_temp)->to_string();
                    std::string col_cn_name_temp = sheet.getCell(1, col_index_temp)->to_string();
                    std::string col_type_temp = sheet.getCell(2, col_index_temp)->to_string();
                    std::string col_sel_temp_str = sheet.getCell(3, col_index_temp)->to_string();
                    NFStringUtility::Trim(col_en_name_temp);
                    NFStringUtility::Trim(col_cn_name_temp);
                    NFStringUtility::Trim(col_type_temp);
                    NFStringUtility::Trim(col_sel_temp_str);

                    int col_temp_sel = NFCommon::strto<int>(col_sel_temp_str);
                    if (col_temp_sel != 2 && col_temp_sel != 3)
                        continue;

                    std::vector<std::string> col_en_name_list_temp;
                    NFStringUtility::Split(col_en_name_temp, "_", &col_en_name_list_temp);
                    for (int i = 0; i < (int) col_en_name_list_temp.size(); i++)
                    {
                        NFStringUtility::Trim(col_en_name_list_temp[i]);
                    }

                    std::vector<std::string> col_cn_name_list_temp;
                    NFStringUtility::SplitDigit(col_cn_name_temp, &col_cn_name_list_temp);
                    for (int i = 0; i < (int) col_cn_name_list_temp.size(); i++)
                    {
                        NFStringUtility::Trim(col_cn_name_list_temp[i]);
                    }

                    /** 处理数组特殊情况
                     * @brief item_id item_num item_id item_num
                     *        物品1    物品1Num     物品2    物品2Num
                     */
                    if (col_en_name_list_temp.size() == 2 && col_en_name_temp != col_en_name && col_en_name_list_temp[0] == col_en_name_list[0]
                        && col_cn_name_list_temp.size() == 3 && col_cn_name_list_temp[1].size() > 0)
                    {
                        has_diff = true;
                        break;
                    }
                }

                /** 处理数组特殊情况
                 * @brief item_id item_num item_id item_num
                 *        物品1    物品1Num     物品2    物品2Num
                 */
                if (has_diff)
                {
                    std::string struct_en_name = col_en_name_list[0];
                    std::string struct_en_sub_name = col_en_name_list[1];
                    std::string struct_cn_name = col_en_name_list[0];
                    uint32_t struct_num = NFCommon::strto<uint32_t>(col_cn_name_list[1]);
                    std::string struct_cn_sub_name = col_en_name_list[1];

                    int iRet = HandleColSubMsg(pSheet, col_index, sheet, struct_en_name, struct_cn_name, col_type, struct_num,
                                               struct_en_sub_name, struct_cn_sub_name, false);
                    CHECK_EXPR(iRet == 0, -1, "excel:{} sheet:{} col_en_name:{} col_cn_name:{} is not right", m_excel,
                               pSheet->m_name, col_en_name, col_cn_name);
                }
                    /** 其余情况
                     * @brief item_id itemnum
                     *        物品1    物x1
                     */
                else
                {
                    uint32_t struct_num = NFCommon::strto<uint32_t>(col_cn_name_list[1]);
                    std::string struct_en_name = col_en_name;
                    std::string struct_cn_name = col_en_name;
                    int iRet = HandleColMsg(pSheet, col_index, sheet, struct_en_name, struct_cn_name, col_type, struct_num);
                    CHECK_EXPR(iRet == 0, -1, "excel:{} sheet:{} col_en_name:{} col_cn_name:{} is not right", m_excel,
                               pSheet->m_name, col_en_name, col_cn_name);
                }
            }
            else
            {
                NFLogError(NF_LOG_SYSTEMLOG, 0, "excel:{} sheet:{} sub_name:{} cn_name:{} is not right", m_excel, pSheet->m_name, col_en_name,
                           col_cn_name);
                return -1;
            }
        }
        else if (col_en_name_list.size() == 1 and col_cn_name_list.size() == 3)
        {
            /** 处理特殊情况
             * @brief itemid itemid
             *        物品1   物品2
             */
            if (col_en_name_list[0].size() > 0 && col_cn_name_list[0].size() > 0 && col_cn_name_list[1].size() > 0 && col_cn_name_list[2].size() > 0)
            {
                bool has_diff = false;
                for (int col_index_temp = 0; col_index_temp < cols; col_index_temp++)
                {
                    if (col_index_temp == col_index) continue;

                    std::string col_en_name_temp = sheet.getCell(0, col_index_temp)->to_string();
                    std::string col_cn_name_temp = sheet.getCell(1, col_index_temp)->to_string();
                    std::string col_type_temp = sheet.getCell(2, col_index_temp)->to_string();
                    std::string col_sel_temp_str = sheet.getCell(3, col_index_temp)->to_string();
                    NFStringUtility::Trim(col_en_name_temp);
                    NFStringUtility::Trim(col_cn_name_temp);
                    NFStringUtility::Trim(col_type_temp);
                    NFStringUtility::Trim(col_sel_temp_str);

                    int col_temp_sel = NFCommon::strto<int>(col_sel_temp_str);
                    if (col_temp_sel != 2 && col_temp_sel != 3)
                        continue;

                    std::vector<std::string> col_en_name_list_temp;
                    NFStringUtility::Split(col_en_name_temp, "_", &col_en_name_list_temp);
                    for (int i = 0; i < (int) col_en_name_list_temp.size(); i++)
                    {
                        NFStringUtility::Trim(col_en_name_list_temp[i]);
                    }

                    std::vector<std::string> col_cn_name_list_temp;
                    NFStringUtility::SplitDigit(col_cn_name_temp, &col_cn_name_list_temp);
                    for (int i = 0; i < (int) col_cn_name_list_temp.size(); i++)
                    {
                        NFStringUtility::Trim(col_cn_name_list_temp[i]);
                    }

                    /** 处理数组特殊情况
                     * @brief item item_num item    item_num
                     *        物品1 物品1Num  物品2    物品2Num
                     */
                    /** 处理数组特殊情况
                     * @brief item item_num item    item_num
                     *        物品1 物x1Num  物品2    物品2Num
                     */
                    /** 处理数组特殊情况
                     * @brief item item_num item item_num
                     *        物品1    物x1     物品2    物x2
                     */
                    if (col_en_name_list_temp.size() == 2 && col_en_name_temp != col_en_name && col_en_name_list_temp[0] == col_en_name_list[0]
                        && col_cn_name_list_temp.size() == 3 && col_cn_name_list_temp[1].size() > 0)
                    {
                        has_diff = true;
                        break;
                    }
                }

                /** 处理数组特殊情况
                 * @brief item item_num item    item_num
                 *        物品1 物品1Num  物品2    物品2Num
                 */
                if (has_diff)
                {
                    std::string struct_en_name = col_en_name_list[0];
                    std::string struct_en_sub_name = col_en_name_list[0];
                    std::string struct_cn_name = col_cn_name_list[0];
                    uint32_t struct_num = NFCommon::strto<uint32_t>(col_cn_name_list[1]);
                    std::string struct_cn_sub_name = col_cn_name_list[2];

                    int iRet = HandleColSubMsg(pSheet, col_index, sheet, struct_en_name, struct_cn_name, col_type, struct_num,
                                               struct_en_sub_name, struct_cn_sub_name, true);
                    CHECK_EXPR(iRet == 0, -1, "excel:{} sheet:{} col_en_name:{} col_cn_name:{} is not right", m_excel,
                               pSheet->m_name, col_en_name, col_cn_name);
                }
                else
                {
                    std::string struct_en_name = col_en_name;
                    std::string struct_cn_name = col_cn_name_list[0] + col_cn_name_list[2];
                    uint32_t struct_num = NFCommon::strto<uint32_t>(col_cn_name_list[1]);
                    int iRet = HandleColMsg(pSheet, col_index, sheet, struct_en_name, struct_cn_name, col_type, struct_num);
                    CHECK_EXPR(iRet == 0, -1, "excel:{} sheet:{} col_en_name:{} col_cn_name:{} is not right", m_excel,
                               pSheet->m_name, col_en_name, col_cn_name);
                }
            }
                /** 处理特殊情况
                 * @brief itemid itemid
                 *        物品1ID 物品2ID
                 */
            else if (col_en_name_list[0].size() > 0
                     && col_cn_name_list[0].size() == 0 && col_cn_name_list[1].size() > 0 && col_cn_name_list[2].size() > 0)
            {
                bool has_diff = false;
                for (int col_index_temp = 0; col_index_temp < cols; col_index_temp++)
                {
                    if (col_index_temp == col_index) continue;

                    std::string col_en_name_temp = sheet.getCell(0, col_index_temp)->to_string();
                    std::string col_cn_name_temp = sheet.getCell(1, col_index_temp)->to_string();
                    std::string col_type_temp = sheet.getCell(2, col_index_temp)->to_string();
                    std::string col_sel_temp_str = sheet.getCell(3, col_index_temp)->to_string();
                    NFStringUtility::Trim(col_en_name_temp);
                    NFStringUtility::Trim(col_cn_name_temp);
                    NFStringUtility::Trim(col_type_temp);
                    NFStringUtility::Trim(col_sel_temp_str);

                    int col_temp_sel = NFCommon::strto<int>(col_sel_temp_str);
                    if (col_temp_sel != 2 && col_temp_sel != 3)
                        continue;

                    std::vector<std::string> col_en_name_list_temp;
                    NFStringUtility::Split(col_en_name_temp, "_", &col_en_name_list_temp);
                    for (int i = 0; i < (int) col_en_name_list_temp.size(); i++)
                    {
                        NFStringUtility::Trim(col_en_name_list_temp[i]);
                    }

                    std::vector<std::string> col_cn_name_list_temp;
                    NFStringUtility::SplitDigit(col_cn_name_temp, &col_cn_name_list_temp);
                    for (int i = 0; i < (int) col_cn_name_list_temp.size(); i++)
                    {
                        NFStringUtility::Trim(col_cn_name_list_temp[i]);
                    }

                    /** 处理数组特殊情况
                     * @brief item item_num item item_num
                     *        物品1ID    物品1Num     物品2ID    物品2Num
                     */
                    if (col_en_name_list_temp.size() == 2 && col_en_name_temp != col_en_name && col_en_name_list_temp[0] == col_en_name_list[0]
                        && col_cn_name_list_temp.size() == 3 && col_cn_name_list_temp[1].size() > 0)
                    {
                        has_diff = true;
                        break;
                    }
                }

                /** 处理数组特殊情况
                 * @brief item item_num item item_num
                 *        物品1ID    物品1Num     物品2ID    物品2Num
                 */
                if (has_diff)
                {
                    std::string struct_en_name = col_en_name_list[0];
                    std::string struct_en_sub_name = col_en_name_list[0];
                    std::string struct_cn_name = col_cn_name_list[2];
                    uint32_t struct_num = NFCommon::strto<uint32_t>(col_cn_name_list[1]);
                    std::string struct_cn_sub_name = col_cn_name_list[2];

                    int iRet = HandleColSubMsg(pSheet, col_index, sheet, struct_en_name, struct_cn_name, col_type, struct_num,
                                               struct_en_sub_name, struct_cn_sub_name, true);
                    CHECK_EXPR(iRet == 0, -1, "excel:{} sheet:{} col_en_name:{} col_cn_name:{} is not right", m_excel,
                               pSheet->m_name, col_en_name, col_cn_name);
                }
                else
                {
                    std::string struct_en_name = col_en_name_list[0];
                    std::string struct_cn_name = col_cn_name_list[0] + col_cn_name_list[2];
                    uint32_t struct_num = NFCommon::strto<uint32_t>(col_cn_name_list[1]);
                    int iRet = HandleColMsg(pSheet, col_index, sheet, struct_en_name, struct_cn_name, col_type, struct_num);
                    CHECK_EXPR(iRet == 0, -1, "excel:{} sheet:{} col_en_name:{} col_cn_name:{} is not right", m_excel,
                               pSheet->m_name, col_en_name, col_cn_name);
                }
            }
            else if (col_en_name_list[0].size() > 0
                     && col_cn_name_list[0].size() > 0 && col_cn_name_list[1].size() > 0 && col_cn_name_list[2].size() == 0)
            {
                bool has_diff = false;
                for (int col_index_temp = 0; col_index_temp < cols; col_index_temp++)
                {
                    if (col_index_temp == col_index) continue;

                    std::string col_en_name_temp = sheet.getCell(0, col_index_temp)->to_string();
                    std::string col_cn_name_temp = sheet.getCell(1, col_index_temp)->to_string();
                    std::string col_type_temp = sheet.getCell(2, col_index_temp)->to_string();
                    std::string col_sel_temp_str = sheet.getCell(3, col_index_temp)->to_string();
                    NFStringUtility::Trim(col_en_name_temp);
                    NFStringUtility::Trim(col_cn_name_temp);
                    NFStringUtility::Trim(col_type_temp);
                    NFStringUtility::Trim(col_sel_temp_str);

                    int col_temp_sel = NFCommon::strto<int>(col_sel_temp_str);
                    if (col_temp_sel != 2 && col_temp_sel != 3)
                        continue;

                    std::vector<std::string> col_en_name_list_temp;
                    NFStringUtility::Split(col_en_name_temp, "_", &col_en_name_list_temp);
                    for (int i = 0; i < (int) col_en_name_list_temp.size(); i++)
                    {
                        NFStringUtility::Trim(col_en_name_list_temp[i]);
                    }

                    std::vector<std::string> col_cn_name_list_temp;
                    NFStringUtility::SplitDigit(col_cn_name_temp, &col_cn_name_list_temp);
                    for (int i = 0; i < (int) col_cn_name_list_temp.size(); i++)
                    {
                        NFStringUtility::Trim(col_cn_name_list_temp[i]);
                    }

                    /** 处理数组特殊情况
                     * @brief item item_num item item_num
                     *        1ID    物品1Num     2ID    物品2Num
                     */
                    if (col_en_name_list_temp.size() == 2 && col_en_name_temp != col_en_name && col_en_name_list_temp[0] == col_en_name_list[0]
                        && col_cn_name_list_temp.size() == 3 && col_cn_name_list_temp[1].size() > 0)
                    {
                        has_diff = true;
                        break;
                    }
                }

                /** 处理数组特殊情况
                 * @brief item item_num item item_num
                 *        物品1ID    物品1Num     物品2ID    物品2Num
                 */
                if (has_diff)
                {
                    std::string struct_en_name = col_en_name_list[0];
                    std::string struct_en_sub_name = col_en_name_list[0];
                    std::string struct_cn_name = col_cn_name_list[2];
                    uint32_t struct_num = NFCommon::strto<uint32_t>(col_cn_name_list[1]);
                    std::string struct_cn_sub_name = col_cn_name_list[2];

                    int iRet = HandleColSubMsg(pSheet, col_index, sheet, struct_en_name, struct_cn_name, col_type, struct_num,
                                               struct_en_sub_name, struct_cn_sub_name, true);
                    CHECK_EXPR(iRet == 0, -1, "excel:{} sheet:{} col_en_name:{} col_cn_name:{} is not right", m_excel,
                               pSheet->m_name, col_en_name, col_cn_name);
                }
                else
                {
                    std::string struct_en_name = col_en_name_list[0];
                    std::string struct_cn_name = col_cn_name_list[0] + col_cn_name_list[2];
                    uint32_t struct_num = NFCommon::strto<uint32_t>(col_cn_name_list[1]);
                    int iRet = HandleColMsg(pSheet, col_index, sheet, struct_en_name, struct_cn_name, col_type, struct_num);
                    CHECK_EXPR(iRet == 0, -1, "excel:{} sheet:{} col_en_name:{} col_cn_name:{} is not right", m_excel,
                               pSheet->m_name, col_en_name, col_cn_name);
                }
            }
            else if (col_en_name_list[0].size() > 0
                     && col_cn_name_list[0].size() == 0 && col_cn_name_list[1].size() > 0 && col_cn_name_list[2].size() == 0)
            {
                bool has_diff = false;
                for (int col_index_temp = 0; col_index_temp < cols; col_index_temp++)
                {
                    if (col_index_temp == col_index) continue;

                    std::string col_en_name_temp = sheet.getCell(0, col_index_temp)->to_string();
                    std::string col_cn_name_temp = sheet.getCell(1, col_index_temp)->to_string();
                    std::string col_type_temp = sheet.getCell(2, col_index_temp)->to_string();
                    std::string col_sel_temp_str = sheet.getCell(3, col_index_temp)->to_string();
                    NFStringUtility::Trim(col_en_name_temp);
                    NFStringUtility::Trim(col_cn_name_temp);
                    NFStringUtility::Trim(col_type_temp);
                    NFStringUtility::Trim(col_sel_temp_str);

                    int col_temp_sel = NFCommon::strto<int>(col_sel_temp_str);
                    if (col_temp_sel != 2 && col_temp_sel != 3)
                        continue;

                    std::vector<std::string> col_en_name_list_temp;
                    NFStringUtility::Split(col_en_name_temp, "_", &col_en_name_list_temp);
                    for (int i = 0; i < (int) col_en_name_list_temp.size(); i++)
                    {
                        NFStringUtility::Trim(col_en_name_list_temp[i]);
                    }

                    std::vector<std::string> col_cn_name_list_temp;
                    NFStringUtility::SplitDigit(col_cn_name_temp, &col_cn_name_list_temp);
                    for (int i = 0; i < (int) col_cn_name_list_temp.size(); i++)
                    {
                        NFStringUtility::Trim(col_cn_name_list_temp[i]);
                    }

                    /** 处理数组特殊情况
                     * @brief item item_num item item_num
                     *        1ID    物品1Num     2ID    物品2Num
                     */
                    if (col_en_name_list_temp.size() == 2 && col_en_name_temp != col_en_name && col_en_name_list_temp[0] == col_en_name_list[0]
                        && col_cn_name_list_temp.size() == 3 && col_cn_name_list_temp[1].size() > 0)
                    {
                        has_diff = true;
                        break;
                    }
                }

                /** 处理数组特殊情况
                 * @brief item item_num item item_num
                 *        1    1        2    2
                 */
                if (has_diff)
                {
                    std::string struct_en_name = col_en_name_list[0];
                    std::string struct_en_sub_name = col_en_name_list[0];
                    std::string struct_cn_name = col_en_name_list[0];
                    uint32_t struct_num = NFCommon::strto<uint32_t>(col_cn_name_list[1]);
                    std::string struct_cn_sub_name = col_en_name_list[0];

                    int iRet = HandleColSubMsg(pSheet, col_index, sheet, struct_en_name, struct_cn_name, col_type, struct_num,
                                               struct_en_sub_name, struct_cn_sub_name, true);
                    CHECK_EXPR(iRet == 0, -1, "excel:{} sheet:{} col_en_name:{} col_cn_name:{} is not right", m_excel,
                               pSheet->m_name, col_en_name, col_cn_name);
                }
                else
                {
                    std::string struct_en_name = col_en_name_list[0];
                    std::string struct_cn_name = col_cn_name_list[0] + col_cn_name_list[2];
                    uint32_t struct_num = NFCommon::strto<uint32_t>(col_cn_name_list[1]);
                    int iRet = HandleColMsg(pSheet, col_index, sheet, struct_en_name, struct_cn_name, col_type, struct_num);
                    CHECK_EXPR(iRet == 0, -1, "excel:{} sheet:{} col_en_name:{} col_cn_name:{} is not right", m_excel,
                               pSheet->m_name, col_en_name, col_cn_name);
                }
            }
            else
            {
                NFLogError(NF_LOG_SYSTEMLOG, 0, "excel:{} sheet:{} sub_name:{} cn_name:{} is not right", m_excel, pSheet->m_name, col_en_name,
                           col_cn_name);
                return -1;
            }
        }
        else
        {
            std::string struct_en_name = col_en_name;
            std::string struct_cn_name = col_cn_name;
            uint32_t struct_num = 0;
            int iRet = HandleColMsg(pSheet, col_index, sheet, struct_en_name, struct_cn_name, col_type, struct_num);
            CHECK_EXPR(iRet == 0, -1, "excel:{} sheet:{} col_en_name:{} col_cn_name:{} is not right", m_excel,
                       pSheet->m_name, col_en_name, col_cn_name);
        }
    }

    return 0;
}


int ExcelParse::HandleColSubMsg(ExcelSheet *pSheet, int col_index, MiniExcelReader::Sheet &sheet, const std::string &struct_en_name,
                                const std::string &struct_cn_name, const std::string &col_type, uint32_t struct_num,
                                const std::string &struct_en_sub_name, const std::string &struct_cn_sub_name, bool is_special)
{
    ExcelSheetColInfo *pColInfo = NULL;
    if (pSheet->m_colInfoMap.find(struct_en_name) == pSheet->m_colInfoMap.end())
    {
        pColInfo = new ExcelSheetColInfo();
        pColInfo->m_colIndex = col_index;
        pSheet->m_colInfoVec.emplace(col_index, pColInfo);

        pSheet->m_colInfoMap.emplace(struct_en_name, pColInfo);
        pColInfo->m_structEnName = struct_en_name;
        pColInfo->m_structCnName = struct_cn_name;
        pColInfo->m_colType = col_type;
        pColInfo->m_maxSubNum = struct_num;
        pColInfo->m_colTypeStrMaxSize = 32;

        //NFLogInfo(NF_LOG_SYSTEMLOG, 0, "sheet:{} add col info, col:{} en_name:{} cn_name:{} col_type:{}", pSheet->m_name, col_index + 1,
        //          pColInfo->m_structEnName, pColInfo->m_structCnName, pColInfo->m_colType);
    }
    else
    {
        pColInfo = pSheet->m_colInfoMap[struct_en_name];
    }

    pColInfo->m_colIndexVec.push_back(col_index);

    CHECK_EXPR(pSheet->m_allColInfoList.find(col_index) == pSheet->m_allColInfoList.end(), -1, "sheet:{} col:{} repeated parse", pSheet->m_name,
               col_index + 1);
    ExcelSheetColIndex &sheetColIndex = pSheet->m_allColInfoList[col_index];
    sheetColIndex.m_colIndex = col_index;
    sheetColIndex.m_structEnName = struct_en_name;
    sheetColIndex.m_structSubEnName = struct_en_sub_name;
    sheetColIndex.m_pColInfo = pColInfo;
    sheetColIndex.m_isArray = true;
    sheetColIndex.m_isSpecial = is_special;
    sheetColIndex.m_structNum = struct_num;
    sheetColIndex.m_fullEnName = sheetColIndex.m_structEnName + "_" + NFCommon::tostr(struct_num) + "_" + struct_en_sub_name;
    CHECK_EXPR(pSheet->m_allFullEnName.find(sheetColIndex.m_fullEnName) == pSheet->m_allFullEnName.end(), -1,
               "sheet:{} col:{} en_name:{} cn_name:{} repeated eixst", pSheet->m_name, col_index + 1, struct_en_name + "_" + struct_en_sub_name,
               struct_cn_name + NFCommon::tostr(struct_num) + struct_cn_sub_name);
    pSheet->m_allFullEnName.insert(sheetColIndex.m_fullEnName);

    if (pColInfo->m_structEnName == struct_en_name)
    {
        ExcelSheetColSubInfo *pSubMsg = NULL;
        if (pColInfo->m_subInfoMap.find(struct_en_sub_name) == pColInfo->m_subInfoMap.end())
        {
            pSubMsg = &pColInfo->m_subInfoMap[struct_en_sub_name];
            pSubMsg->m_enSubName = struct_en_sub_name;
            pSubMsg->m_cnSubName = struct_cn_sub_name;
            pSubMsg->m_colType = col_type;
            pSubMsg->m_colTypeStrMaxSize = 32;
            pColInfo->m_maxRowNum = sheet.rows();

/*            NFLogInfo(NF_LOG_SYSTEMLOG, 0,
                      "sheet:{} add col info, col:{} en_name:{} cn_name:{} col_type:{} --- sub_col_info sub_en_name:{} sub_cn_name:{}",
                      pSheet->m_name, col_index + 1,
                      pColInfo->m_structEnName, pColInfo->m_structCnName, pColInfo->m_colType, pSubMsg->m_enSubName, pSubMsg->m_cnSubName);*/

            CHECK_EXPR(struct_num == 1, -1,
                       "sheet:{} add col info, col:{} en_name:{} cn_name:{} col_type:{} --- sub_col_info sub_en_name:{} sub_cn_name:{}, but the first struct_num is not 1",
                       pSheet->m_name, col_index + 1,
                       pColInfo->m_structEnName, pColInfo->m_structCnName, pColInfo->m_colType, pSubMsg->m_enSubName, pSubMsg->m_cnSubName);
        }
        else
        {
            pSubMsg = &pColInfo->m_subInfoMap[struct_en_sub_name];
            CHECK_EXPR(pSubMsg->m_cnSubName == struct_cn_sub_name, -1, "excel:{} sheet:{} struct_en_name:{} struct_cn_name:{} is not right", m_excel,
                       pSheet->m_name, struct_en_name, struct_cn_name);

        }

        pSubMsg->m_colIndexVec.push_back(col_index);

        if (struct_num > pColInfo->m_maxSubNum)
        {

            CHECK_EXPR(struct_num == pColInfo->m_maxSubNum + 1, -1,
                       "sheet:{} add col info, col:{} en_name:{} cn_name:{} col_type:{} --- sub_col_info sub_en_name:{} sub_cn_name:{}, but the struct_num is not the last struct_num + 1",
                       pSheet->m_name, col_index + 1,
                       pColInfo->m_structEnName, pColInfo->m_structCnName, pColInfo->m_colType, pSubMsg->m_enSubName, pSubMsg->m_cnSubName);

            pColInfo->m_maxSubNum = struct_num;
        }

        if (col_type == "string")
        {
            HandleColOtherInfo(col_index, sheet, col_type, pColInfo->m_colUniqueKeys, pColInfo->m_colUniqueListKeys, pSubMsg->m_colTypeStrMaxSize);
        }
    }

    return 0;
}

int ExcelParse::HandleColMsg(ExcelSheet *pSheet, int col_index, MiniExcelReader::Sheet &sheet, const std::string &struct_en_name,
                             const std::string &struct_cn_name, const std::string &col_type, uint32_t struct_num)
{
    ExcelSheetColInfo *pColInfo = NULL;
    if (pSheet->m_colInfoMap.find(struct_en_name) == pSheet->m_colInfoMap.end())
    {
        pColInfo = new ExcelSheetColInfo();
        pColInfo->m_colIndex = col_index;
        pSheet->m_colInfoVec.emplace(col_index, pColInfo);

        pSheet->m_colInfoMap.emplace(struct_en_name, pColInfo);
        pColInfo->m_structEnName = struct_en_name;
        pColInfo->m_structCnName = struct_cn_name;
        pColInfo->m_colType = col_type;
        pColInfo->m_maxSubNum = struct_num;
        pColInfo->m_maxRowNum = sheet.rows();

        if (struct_num > 0)
        {
            CHECK_EXPR(struct_num == 1, -1, "sheet:{} add col info, col:{} en_name:{} cn_name:{} col_type:{}, but the first struct_num is not 1",
                       pSheet->m_name, pColInfo->m_colIndex,
                       pColInfo->m_structEnName, pColInfo->m_structCnName, pColInfo->m_colType);
        }

/*        NFLogInfo(NF_LOG_SYSTEMLOG, 0, "sheet:{} add col info, col:{} en_name:{} cn_name:{} col_type:{}", pSheet->m_name, col_index+1,
                  pColInfo->m_structEnName, pColInfo->m_structCnName, pColInfo->m_colType);*/
    }
    else
    {
        pColInfo = pSheet->m_colInfoMap[struct_en_name];
        if (struct_num > 0)
        {
            CHECK_EXPR(struct_num == pColInfo->m_maxSubNum + 1, -1,
                       "sheet:{} add col info, col:{} en_name:{} cn_name:{} col_type:{}, but the struct_num is not the last struct_num + 1",
                       pSheet->m_name, col_index + 1,
                       pColInfo->m_structEnName, pColInfo->m_structCnName, pColInfo->m_colType);
        }
    }

    pColInfo->m_colIndexVec.push_back(col_index);

    CHECK_EXPR(pSheet->m_allColInfoList.find(col_index) == pSheet->m_allColInfoList.end(), -1, "sheet:{} col:{} repeated parse", pSheet->m_name,
               col_index + 1);
    ExcelSheetColIndex &sheetColIndex = pSheet->m_allColInfoList[col_index];
    sheetColIndex.m_colIndex = col_index;
    sheetColIndex.m_structEnName = struct_en_name;
    sheetColIndex.m_pColInfo = pColInfo;
    sheetColIndex.m_fullEnName = sheetColIndex.m_structEnName;
    if (struct_num > 0)
    {
        sheetColIndex.m_isArray = true;
        sheetColIndex.m_structNum = struct_num;
        sheetColIndex.m_fullEnName += "_" + NFCommon::tostr(struct_num);
    }

    CHECK_EXPR(pSheet->m_allFullEnName.find(sheetColIndex.m_fullEnName) == pSheet->m_allFullEnName.end(), -1,
               "sheet:{} col:{} en_name:{} cn_name:{} repeated eixst", pSheet->m_name, col_index + 1, struct_en_name, struct_cn_name);
    pSheet->m_allFullEnName.insert(sheetColIndex.m_fullEnName);

    if (pColInfo->m_structEnName == struct_en_name)
    {
        if (struct_num > pColInfo->m_maxSubNum)
        {
            pColInfo->m_maxSubNum = struct_num;
        }

        HandleColOtherInfo(col_index, sheet, col_type, pColInfo->m_colUniqueKeys, pColInfo->m_colUniqueListKeys, pColInfo->m_colTypeStrMaxSize);
    }

    return 0;
}

int ExcelParse::HandleSheetIndex()
{
    for (auto iter = m_sheets.begin(); iter != m_sheets.end(); iter++)
    {
        ExcelSheet &sheet = iter->second;
        for (auto iter_i = sheet.m_indexMap.begin(); iter_i != sheet.m_indexMap.end(); iter_i++)
        {
            std::string key = iter_i->first;
            auto find_iter = sheet.m_colInfoMap.find(key);
            if (find_iter != sheet.m_colInfoMap.end())
            {
                if (find_iter->second->m_maxSubNum != 0)
                {
                    NFLogError(NF_LOG_SYSTEMLOG, 0, "excel:{} sheet:{} index key:{} is not right, this is a array, array can't do the index", m_excel,
                               sheet.m_name, key);
                    return -1;
                }

                iter_i->second.m_colIndex = find_iter->second->m_colIndex;
                iter_i->second.m_maxNum = find_iter->second->m_maxRowNum;
                iter_i->second.m_maxUniqueNum = find_iter->second->m_colUniqueKeys;
                iter_i->second.m_maxUniqueListNum = find_iter->second->m_colUniqueListKeys;
            }
            else
            {
                NFLogError(NF_LOG_SYSTEMLOG, 0, "excel:{} sheet:{} index key:{} not exist", m_excel, sheet.m_name, key);
                return -1;
            }
        }

        for (auto iter_i = sheet.m_comIndexMap.begin(); iter_i != sheet.m_comIndexMap.end(); iter_i++)
        {
            ExcelSheetComIndex &comIndex = iter_i->second;
            for (int i = 0; i < (int) comIndex.m_index.size(); i++)
            {
                ExcelSheetIndex &index = comIndex.m_index[i];
                std::string key = index.m_key;
                auto find_iter = sheet.m_colInfoMap.find(key);
                if (find_iter != sheet.m_colInfoMap.end())
                {
                    if (find_iter->second->m_maxSubNum != 0)
                    {
                        NFLogError(NF_LOG_SYSTEMLOG, 0, "excel:{} sheet:{} index key:{} is not right, this is a array, array can't do the index",
                                   m_excel, sheet.m_name, key);
                        return -1;
                    }

                    index.m_colIndex = find_iter->second->m_colIndex;
                    index.m_maxNum = find_iter->second->m_maxRowNum;
                    index.m_maxUniqueNum = find_iter->second->m_colUniqueKeys;
                    index.m_maxUniqueListNum = find_iter->second->m_colUniqueListKeys;
                }
                else
                {
                    NFLogError(NF_LOG_SYSTEMLOG, 0, "excel:{} sheet:{} index key:{} not exist", m_excel, sheet.m_name, key);
                    return -1;
                }
            }
        }

        for (auto iter = sheet.m_colRelationMap.begin(); iter != sheet.m_colRelationMap.end(); iter++)
        {
            if (iter->second.m_myColSubName.empty())
            {
                CHECK_EXPR(sheet.m_colInfoMap.find(iter->second.m_myColName) != sheet.m_colInfoMap.end(), -1, "excel:{} sheet:{} can't find the colName:{} info in the relation", m_excelName, sheet.m_name, iter->second.m_myColName);
                ExcelSheetColInfo *pColInfo = sheet.m_colInfoMap[iter->second.m_myColName];
                if (!pColInfo->m_subInfoMap.empty())
                {
                    //repeated Attr...........
                    CHECK_EXPR(pColInfo->m_subInfoMap.find(iter->second.m_myColName) != pColInfo->m_subInfoMap.end(), -1, "excel:{} sheet:{} can't find the col:{} info in the relation", m_excelName, sheet.m_name, iter->second.m_myColName);
                    iter->second.m_myColSubName = iter->second.m_myColName;
                }
            }
            else
            {
                if (sheet.m_colInfoMap.find(iter->second.m_myColName) == sheet.m_colInfoMap.end())
                {
                    std::string key = iter->second.m_myColName + "_" + iter->second.m_myColSubName;
                    CHECK_EXPR(sheet.m_colInfoMap.find(key) != sheet.m_colInfoMap.end(), -1, "excel:{} sheet:{} can't find the colName:{} info in the relation", m_excelName, sheet.m_name, iter->second.m_mySrcColName);
                    iter->second.m_myColName = key;
                    iter->second.m_myColSubName = "";
                }
                else {
                    ExcelSheetColInfo *pColInfo = sheet.m_colInfoMap[iter->second.m_myColName];
                    if (pColInfo->m_maxSubNum == 0)
                    {
                        std::string key = iter->second.m_myColName + "_" + iter->second.m_myColSubName;
                        CHECK_EXPR(sheet.m_colInfoMap.find(key) != sheet.m_colInfoMap.end(), -1, "excel:{} sheet:{} can't find the colName:{} info in the relation", m_excelName, sheet.m_name, iter->second.m_mySrcColName);
                        iter->second.m_myColName = key;
                        iter->second.m_myColSubName = "";
                    }
                    else {
                        if (pColInfo->m_subInfoMap.find(iter->second.m_myColSubName) == pColInfo->m_subInfoMap.end())
                        {
                            std::string key = iter->second.m_myColName + "_" + iter->second.m_myColSubName;
                            CHECK_EXPR(sheet.m_colInfoMap.find(key) != sheet.m_colInfoMap.end(), -1, "excel:{} sheet:{} can't find the colName:{} info in the relation", m_excelName, sheet.m_name, iter->second.m_mySrcColName);
                            iter->second.m_myColName = key;
                            iter->second.m_myColSubName = "";
                        }
                    }
                }
            }
        }
    }
    return 0;
}

void ExcelParse::HandleColOtherInfo(int col_index, MiniExcelReader::Sheet &sheet, const string &colType, uint32_t &uniqueKeysNum,
                                    uint32_t &uniqueKeysListNum, uint32_t &maxSize)
{

}

int ExcelParse::get_max_num(int num)
{
    int i = 1;
    while (true)
    {
        i = i * 2;
        if (i > num)
        {
            return i;
        }
    }
}

ExcelSheet* ExcelParse::GetExcelSheet(const std::string& sheetName)
{
    auto iter = m_sheets.find(sheetName);
    if (iter != m_sheets.end())
    {
        return &iter->second;
    }
    return nullptr;
}