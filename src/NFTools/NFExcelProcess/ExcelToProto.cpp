// -------------------------------------------------------------------------
//    @FileName         :    ExcelToProto.cpp
//    @Author           :    gaoyi
//    @Date             :    23-8-19
//    @Email			:    445267987@qq.com
//    @Module           :    ExcelToProto
//
// -------------------------------------------------------------------------

#include "ExcelToProto.h"
#include "NFComm/NFPluginModule/NFCheck.h"

ExcelToProto::ExcelToProto()
{

}

ExcelToProto::~ExcelToProto()
{

}

int ExcelToProto::Init(const std::string &excel, const std::string &outPath)
{
    m_excel = excel;
    m_outPath = outPath;
    NFStringUtility::Trim(m_excel);
    NFStringUtility::Trim(m_outPath);
    m_outPath = NFFileUtility::NormalizePath(m_outPath);

    CHECK_EXPR(NFFileUtility::IsFileExist(m_excel), -1, "excel:{} not exist", m_excel);
    CHECK_EXPR(NFFileUtility::IsDir(m_outPath), -1, "outPath:{} not exist", m_outPath);

    m_descStoreHeadFile = m_outPath + "NFDescStoreHead.h";
    if (!NFFileUtility::IsFileExist(m_descStoreHeadFile))
    {
        m_descStoreHeadFileStr += "#pragma once\n\n";
    }

    m_descStoreDefineFile = m_outPath + "NFDescStoreDefine.h";
    if (!NFFileUtility::IsFileExist(m_descStoreDefineFile))
    {
        m_descStoreDefineFileStr += "#define EOT_DESC_STORE_ALL_ID_DEFINE \\\n";
    }

    m_descStoreRegisterFile = m_outPath + "NFDescStoreRegister.h";
    if (!NFFileUtility::IsFileExist(m_descStoreRegisterFile))
    {
        m_descStoreRegisterFileStr += "#define EOT_DESC_STORE_ALL_REGISTER_DEFINE \\\n";
    }

    m_workbook.load(m_excel);

    return 0;
}

int ExcelToProto::HandleExcel()
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

    WriteExcelProto();
    return 0;
}

int ExcelToProto::HandleSheetList()
{
    //首先处理list
    for (auto iter = m_workbook.begin(); iter != m_workbook.end(); iter++)
    {
        worksheet sheet = *iter;
        if (sheet.title() == "main")
        {
            NFLogInfo(NF_LOG_SYSTEMLOG, 0, "handle excel:{} sheet:{}", m_excel, sheet.title());
        }
        else if (sheet.title() == "list")
        {
            NFLogInfo(NF_LOG_SYSTEMLOG, 0, "handle excel:{} sheet:{}", m_excel, sheet.title());
            HandleSheetList(sheet);
        }
    }

    return 0;
}

int ExcelToProto::HandleSheetList(worksheet sheet)
{
    if (sheet.title() != "list") return -1;

    auto sheet_row = sheet.rows();
    if (sheet_row.length() <= 0) return 0;

    //list表的第一行第一个自动有sheet_name的话，这一行只是用来提示功能，第二列是unique_index唯一索引，multi_index不唯一所有，check用来检查列关联到的表数据是否存在
    int start_row = 0;
    if (sheet_row[0][0].value<std::string>() == "sheet_name")
    {
        start_row = 1;
    }

    for (int row = start_row; row < (int) sheet_row.length(); row++)
    {
        auto row_vector = sheet_row[row];
        auto col_sheet_cell = row_vector[0];
        std::string sheet_name = col_sheet_cell.value<std::string>();
        worksheet find_sheet = m_workbook.sheet_by_title(sheet_name);
        if (find_sheet == nullptr)
        {
            NFLogError(NF_LOG_SYSTEMLOG, 0, "excel:{} list has sheet:{}, but can't find in the excel", m_excel, sheet_name);
            continue;
        }

        ExcelSheet &excelSheet = m_sheets[sheet_name];
        excelSheet.m_name = sheet_name;
        excelSheet.m_sheet = find_sheet;

        for (int col = 1; col < (int) row_vector.length(); col++)
        {
            if (col != 1 && col != 2) continue;

            auto col_index = row_vector[col];
            std::string col_index_str = col_index.value<std::string>();
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
                    excelSheetComIndex.m_queue = sheet_index_unique;

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
                    NFLogInfo(NF_LOG_SYSTEMLOG, 0, "excel:{} sheet:{} add com_index:{}", m_excel, sheet_name, col_index_str);
                }
            }
        }

        if (row_vector.length() >= 4)
        {
            auto col_index = row_vector[3];
            std::string col_index_str = col_index.value<std::string>();
            NFStringUtility::Trim(col_index_str);
            if (col_index_str.empty()) continue;

            std::vector<std::string> col_index_str_list;
            NFStringUtility::Split(col_index_str, ";", &col_index_str_list);

            for (int j = 0; j < (int) col_index_str_list.size(); j++)
            {
                std::string col_index_str_list_str = col_index_str_list[j];
                NFStringUtility::Trim(col_index_str_list_str);
                if (col_index_str_list_str.empty()) continue;

                std::vector<std::string> col_index_str_vec;
                NFStringUtility::Split(col_index_str_list[j], ",", &col_index_str_vec);

                for (int x = 0; x < (int) col_index_str_vec.size(); x++)
                {
                    std::string relation_str = col_index_str_vec[x];
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

                    std::vector<std::string> dst_relation_str_vec;
                    NFStringUtility::Split(dst_relation_str, ".", &dst_relation_str_vec);

                    if (dst_relation_str_vec.size() != 3)
                    {
                        NFLogError(NF_LOG_SYSTEMLOG, 0, "the relation:{} is not right", relation_str);
                        return -1;
                    }

                    ExcelRelation relation;
                    relation.excel_name = dst_relation_str_vec[0];
                    relation.sheet_name = dst_relation_str_vec[1];
                    relation.col_name = dst_relation_str_vec[2];

                    if (relation.excel_name.empty() || relation.sheet_name.empty() || relation.col_name.empty())
                    {
                        NFLogError(NF_LOG_SYSTEMLOG, 0, "the relation:{} is not right", relation_str);
                        return -1;
                    }

                    if (excelSheet.m_colRelationMap.find(my_col_name) != excelSheet.m_colRelationMap.end())
                    {
                        NFLogError(NF_LOG_SYSTEMLOG, 0, "the relation:{} is not right, repeated", relation_str);
                        return -1;
                    }

                    excelSheet.m_colRelationMap.emplace(my_col_name, relation);
                    NFLogInfo(NF_LOG_SYSTEMLOG, 0, "excel:{} sheet:{} add relation:{}:{}.{}.{}", m_excel, sheet_name, my_col_name,
                              relation.excel_name, relation.sheet_name, relation.col_name);
                }
            }
        }
    }

    return 0;
}

int ExcelToProto::HandleSheetWork()
{
    for (auto iter = m_sheets.begin(); iter != m_sheets.end(); iter++)
    {
        worksheet sheet = iter->second.m_sheet;
        NFLogInfo(NF_LOG_SYSTEMLOG, 0, "handle excel:{} sheet:{}", m_excel, sheet.title());
        HandleSheetWork(sheet);
    }

    return 0;
}

int ExcelToProto::HandleSheetWork(worksheet sheet)
{
    auto all_col = sheet.columns();
    int col_size = all_col.length();

    ExcelSheet *pSheet = &m_sheets[sheet.title()];

    for (int col_index = 0; col_index < col_size; col_index++)
    {
        auto sheet_col = all_col[col_index];
        std::string col_en_name = sheet_col[0].to_string();
        std::string col_cn_name = sheet_col[1].to_string();
        std::string col_type = sheet_col[2].to_string();
        std::string col_sel_str = sheet_col[3].to_string();
        NFStringUtility::Trim(col_en_name);
        NFStringUtility::Trim(col_cn_name);
        NFStringUtility::Trim(col_type);
        NFStringUtility::Trim(col_sel_str);

        if (col_en_name.empty() || col_cn_name.empty() || col_type.empty() || col_sel_str.empty())
        {
            NFLogError(NF_LOG_SYSTEMLOG, 0, "col_en_name:{} col_cn_name:{} col_type:{} col_sel_str:{} is not right", col_en_name, col_cn_name,
                       col_type, col_sel_str);
            return -1;
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

                int iRet = HandleColSubMsg(pSheet, col_index, sheet_col, struct_en_name, struct_cn_name, col_type, struct_num,
                                           struct_en_sub_name, struct_cn_sub_name);
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
                bool has_col = false;
                bool has_diff = false;

                for (int col_index_temp = 0; col_index_temp < col_size; col_index_temp++)
                {
                    if (col_index_temp == col_index) continue;

                    auto sheet_temp_col = all_col[col_index_temp];

                    std::string col_en_name_temp = sheet_temp_col[0].to_string();
                    std::string col_cn_name_temp = sheet_temp_col[1].to_string();
                    std::string col_type_temp = sheet_temp_col[2].to_string();
                    std::string col_sel_temp_str = sheet_temp_col[3].to_string();
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
                        && col_cn_name_list_temp.size() == 3 && col_cn_name_list_temp[0].size() > 0 && col_cn_name_list_temp[1].size() > 0 &&
                        col_cn_name_list_temp[2].size() > 0 && col_cn_name_list_temp[0] == col_cn_name_list[0])
                    {
                        has_col = true;
                        break;
                    }
                        /** 处理数组特殊情况
                         * @brief item_id item_num item_id item_num
                         *        物品1    物x1     物品2    物x2
                         */
                    else if (col_en_name_list_temp.size() == 2 && col_en_name_temp != col_en_name && col_en_name_list_temp[0] == col_en_name_list[0]
                             && col_cn_name_list_temp.size() == 3 && col_cn_name_list_temp[0].size() > 0 && col_cn_name_list_temp[1].size() > 0 &&
                             col_cn_name_list_temp[2].size() == 0 && col_cn_name_list_temp[0] != col_cn_name_list[0])
                    {
                        has_diff = true;
                        break;
                    }
                }

                /** 处理数组特殊情况
                 * @brief item_id item_num item_id item_num
                 *        物品1    物品1Num     物品2    物品2Num
                 */
                if (has_col)
                {
                    std::string struct_en_name = col_en_name_list[0];
                    std::string struct_en_sub_name = col_en_name_list[1];
                    std::string struct_cn_name = col_cn_name_list[0];
                    uint32_t struct_num = NFCommon::strto<uint32_t>(col_cn_name_list[1]);
                    std::string struct_cn_sub_name = col_cn_name_list[2];

                    int iRet = HandleColSubMsg(pSheet, col_index, sheet_col, struct_en_name, struct_cn_name, col_type, struct_num,
                                               struct_en_sub_name, struct_cn_sub_name);
                    CHECK_EXPR(iRet == 0, -1, "excel:{} sheet:{} col_en_name:{} col_cn_name:{} is not right", m_excel,
                               pSheet->m_name, col_en_name, col_cn_name);
                }
                    /** 处理数组特殊情况
                     * @brief item_id item_num item_id item_num
                     *        物品1    物x1     物品2    物x2
                     */
                else if (has_diff)
                {
                    std::string struct_en_name = col_en_name_list[0];
                    std::string struct_en_sub_name = col_en_name_list[1];
                    std::string struct_cn_name = "$$$$";
                    uint32_t struct_num = NFCommon::strto<uint32_t>(col_cn_name_list[1]);
                    std::string struct_cn_sub_name = col_cn_name_list[0];

                    int iRet = HandleColSubMsg(pSheet, col_index, sheet_col, struct_en_name, struct_cn_name, col_type, struct_num,
                                               struct_en_sub_name, struct_cn_sub_name);
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
                    int iRet = HandleColMsg(pSheet, col_index, sheet_col, struct_en_name, struct_cn_name, col_type, struct_num);
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
            if (col_en_name_list[0].size() > 0
                && col_cn_name_list[0].size() > 0 && col_cn_name_list[1].size() > 0 && col_cn_name_list[2].size() == 0)
            {
                std::string struct_en_name = col_en_name;
                std::string struct_cn_name = col_cn_name_list[0];
                uint32_t struct_num = NFCommon::strto<uint32_t>(col_cn_name_list[1]);
                int iRet = HandleColMsg(pSheet, col_index, sheet_col, struct_en_name, struct_cn_name, col_type, struct_num);
                CHECK_EXPR(iRet == 0, -1, "excel:{} sheet:{} col_en_name:{} col_cn_name:{} is not right", m_excel,
                           pSheet->m_name, col_en_name, col_cn_name);
            }
                /** 处理特殊情况
                 * @brief itemid itemid
                 *        物品1ID 物品2ID
                 */
            else if (col_en_name_list[0].size() > 0
                     && col_cn_name_list[0].size() > 0 && col_cn_name_list[1].size() > 0 && col_cn_name_list[2].size() > 0)
            {
                std::string struct_en_name = col_en_name_list[0];
                std::string struct_cn_name = col_cn_name_list[0] + "9999" + col_cn_name_list[2];
                uint32_t struct_num = NFCommon::strto<uint32_t>(col_cn_name_list[1]);
                int iRet = HandleColMsg(pSheet, col_index, sheet_col, struct_en_name, struct_cn_name, col_type, struct_num);
                CHECK_EXPR(iRet == 0, -1, "excel:{} sheet:{} col_en_name:{} col_cn_name:{} is not right", m_excel,
                           pSheet->m_name, col_en_name, col_cn_name);
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
            int iRet = HandleColMsg(pSheet, col_index, sheet_col, struct_en_name, struct_cn_name, col_type, struct_num);
            CHECK_EXPR(iRet == 0, -1, "excel:{} sheet:{} col_en_name:{} col_cn_name:{} is not right", m_excel,
                       pSheet->m_name, col_en_name, col_cn_name);
        }
    }

    return 0;
}

int ExcelToProto::HandleColSubMsg(ExcelSheet *pSheet, int col_index, cell_vector &sheet_col, const std::string &struct_en_name,
                                  const std::string &struct_cn_name, const std::string &col_type, uint32_t struct_num,
                                  const std::string &struct_en_sub_name, const std::string &struct_cn_sub_name)
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

        NFLogInfo(NF_LOG_SYSTEMLOG, 0, "sheet:{} add col info, col:{} en_name:{} cn_name:{} col_type:{}", pSheet->m_name, pColInfo->m_colIndex,
                  pColInfo->m_structEnName, pColInfo->m_structCnName, pColInfo->m_colType);
    }
    else
    {
        pColInfo = pSheet->m_colInfoMap[struct_en_name];
    }

    if (pColInfo->m_structEnName == struct_en_name && pColInfo->m_structCnName == struct_cn_name)
    {
        if (struct_num > pColInfo->m_maxSubNum)
        {
            pColInfo->m_maxSubNum = struct_num;
        }

        ExcelSheetColSubInfo *pSubMsg = NULL;
        if (pColInfo->m_subInfoMap.find(struct_en_sub_name) == pColInfo->m_subInfoMap.end())
        {
            pSubMsg = &pColInfo->m_subInfoMap[struct_en_sub_name];
            pSubMsg->m_enSubName = struct_en_sub_name;
            pSubMsg->m_cnSubName = struct_cn_sub_name;
            pSubMsg->m_colType = col_type;
            pSubMsg->m_colTypeStrMaxSize = 32;
            pColInfo->m_maxColNum = sheet_col.length();

            NFLogInfo(NF_LOG_SYSTEMLOG, 0,
                      "sheet:{} add col info, col:{} en_name:{} cn_name:{} col_type:{} --- sub_col_info sub_en_name:{} sub_cn_name:{}",
                      pSheet->m_name, pColInfo->m_colIndex,
                      pColInfo->m_structEnName, pColInfo->m_structCnName, pColInfo->m_colType, pSubMsg->m_enSubName, pSubMsg->m_cnSubName);
        }
        else
        {
            pSubMsg = &pColInfo->m_subInfoMap[struct_en_sub_name];
            CHECK_EXPR(pSubMsg->m_cnSubName == struct_cn_sub_name, -1, "excel:{} sheet:{} struct_en_name:{} struct_cn_name:{} is not right", m_excel,
                       pSheet->m_name, struct_en_name, struct_cn_name);
        }

        HandleColOtherInfo(sheet_col, col_type, pColInfo->m_colUniqueKeys, pColInfo->m_colUniqueListKeys, pSubMsg->m_colTypeStrMaxSize);
    }

    return 0;
}

int ExcelToProto::HandleColMsg(ExcelSheet *pSheet, int col_index, cell_vector &sheet_col, const std::string &struct_en_name,
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
        pColInfo->m_maxColNum = sheet_col.length();

        NFLogInfo(NF_LOG_SYSTEMLOG, 0, "sheet:{} add col info, col:{} en_name:{} cn_name:{} col_type:{}", pSheet->m_name, pColInfo->m_colIndex,
                  pColInfo->m_structEnName, pColInfo->m_structCnName, pColInfo->m_colType);
    }
    else
    {
        pColInfo = pSheet->m_colInfoMap[struct_en_name];
    }

    if (pColInfo->m_structEnName == struct_en_name && pColInfo->m_structCnName == struct_cn_name)
    {
        if (struct_num > pColInfo->m_maxSubNum)
        {
            pColInfo->m_maxSubNum = struct_num;
        }

        HandleColOtherInfo(sheet_col, col_type, pColInfo->m_colUniqueKeys, pColInfo->m_colUniqueListKeys, pColInfo->m_colTypeStrMaxSize);
    }

    return 0;
}

void ExcelToProto::HandleColOtherInfo(cell_vector &col, const std::string &colType, uint32_t &uniqueKeysNum, uint32_t &uniqueKeysListNum,
                                      uint32_t &maxSize)
{
    std::unordered_map<std::string, uint32_t> map;
    for (int i = 4; i < (int) col.length(); i++)
    {
        std::string str = col[i].to_string();
        NFStringUtility::Trim(str);
        map[str]++;
        if (colType == "string")
        {
            if (str.size() > maxSize)
            {
                maxSize = str.size();
            }
        }
    }

    uniqueKeysNum = map.size();
    for (auto iter = map.begin(); iter != map.end(); iter++)
    {
        if (iter->second > uniqueKeysListNum)
        {
            uniqueKeysListNum = iter->second;
        }
    }
}

int ExcelToProto::HandleSheetIndex()
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
                iter_i->second.m_maxNum = find_iter->second->m_maxColNum;
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
                    index.m_maxNum = find_iter->second->m_maxColNum;
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
    }
    return 0;
}

void ExcelToProto::WriteExcelProto()
{
    std::string write_str;
    std::string m_excelName = NFFileUtility::GetFileNameWithoutExt(m_excel);
    std::string excel_proto_file = m_excelName + ".proto";

    write_str += "package proto_ff;\n\n";
    write_str += "import \"yd_fieldoptions.proto\";\n\n";

    for (auto iter = m_sheets.begin(); iter != m_sheets.end(); iter++)
    {
        WriteSheetProto(&iter->second, write_str);
    }

    NFFileUtility::WriteFile(excel_proto_file, write_str);
    NFLogInfo(NF_LOG_SYSTEMLOG, 0, "{}", write_str);
}

void ExcelToProto::WriteSheetProto(ExcelSheet *pSheet, std::string &proto_file)
{
    std::string sheet_name = pSheet->m_name;
    for (auto iter = pSheet->m_colInfoVec.begin(); iter != pSheet->m_colInfoVec.end(); iter++)
    {
        ExcelSheetColInfo *pColInfo = iter->second;
        if (pColInfo->m_subInfoMap.empty()) continue;

        std::string struct_en_name = pColInfo->m_structEnName;

        proto_file += "\nmessage E_" + NFStringUtility::Capitalize(m_excelName) + NFStringUtility::Capitalize(sheet_name) +
                      NFStringUtility::Capitalize(struct_en_name) + "Desc\n";
        proto_file += "{\n";
        int index = 0;

        for (auto sub_iter = pColInfo->m_subInfoMap.begin(); sub_iter != pColInfo->m_subInfoMap.end(); sub_iter++)
        {
            index = index + 1;
            std::string sub_en_name = "m_" + NFStringUtility::Lower(sub_iter->second.m_enSubName);
            std::string cn_sub_name = sub_iter->second.m_cnSubName;
            std::string col_type = sub_iter->second.m_colType;
            uint32_t colTypeStrMaxSize = sub_iter->second.m_colTypeStrMaxSize;
            if (col_type == "int" || col_type == "int32")
            {
                proto_file +=
                        "\toptional int32 " + sub_en_name + " = " + NFCommon::tostr(index) + "[(yd_fieldoptions.field_cname) = \"" + cn_sub_name +
                        "\"];\n";
            }
            else if (col_type == "uint" or col_type == "uint32")
            {
                proto_file +=
                        "\toptional uint32 " + sub_en_name + " = " + NFCommon::tostr(index) + "[(yd_fieldoptions.field_cname) = \"" + cn_sub_name +
                        "\"];\n";
            }
            else if (col_type == "int64")
            {
                proto_file +=
                        "\toptional int64 " + sub_en_name + " = " + NFCommon::tostr(index) + "[(yd_fieldoptions.field_cname) = \"" + cn_sub_name +
                        "\"];\n";
            }
            else if (col_type == "uint64")
            {
                proto_file +=
                        "\toptional uint64 " + sub_en_name + " = " + NFCommon::tostr(index) + "[(yd_fieldoptions.field_cname) = \"" + cn_sub_name +
                        "\"];\n";
            }
            else if (col_type == "float")
            {
                proto_file +=
                        "\toptional float " + sub_en_name + " = " + NFCommon::tostr(index) + "[(yd_fieldoptions.field_cname) = \"" + cn_sub_name +
                        "\"];\n";
            }
            else if (col_type == "double")
            {
                proto_file +=
                        "\toptional double " + sub_en_name + " = " + NFCommon::tostr(index) + "[(yd_fieldoptions.field_cname) = \"" + cn_sub_name +
                        "\"];\n";
            }
            else if (col_type == "string")
            {
                proto_file +=
                        "\toptional string " + sub_en_name + " = " + NFCommon::tostr(index) + "[(yd_fieldoptions.field_cname) = \"" + cn_sub_name +
                        "\"," + " (yd_fieldoptions.field_bufsize) = " + NFCommon::tostr(get_max_num(colTypeStrMaxSize)) + "];\n";
            }
        }

        proto_file += "}\n";
    }

    proto_file += "\nmessage E_" + NFStringUtility::Capitalize(m_excelName) + NFStringUtility::Capitalize(sheet_name) + "\n";
    proto_file += "{\n";

    int index = 0;
    for (auto iter = pSheet->m_colInfoVec.begin(); iter != pSheet->m_colInfoVec.end(); iter++)
    {
        ExcelSheetColInfo *pColInfo = iter->second;
        if (!pColInfo->m_subInfoMap.empty()) continue;
        if (pColInfo->m_maxSubNum != 0) continue;

        index += 1;
        std::string col_en_name = "m_" + NFStringUtility::Lower(pColInfo->m_structEnName);
        std::string col_cn_name = pColInfo->m_structCnName;
        std::string col_type = pColInfo->m_colType;
        uint32_t colTypeStrMaxSize = pColInfo->m_colTypeStrMaxSize;
        if (col_type == "int" || col_type == "int32")
        {
            proto_file +=
                    "\toptional int32 " + col_en_name + " = " + NFCommon::tostr(index) + "[(yd_fieldoptions.field_cname) = \"" + col_cn_name +
                    "\"];\n";
        }
        else if (col_type == "uint" or col_type == "uint32")
        {
            proto_file +=
                    "\toptional uint32 " + col_en_name + " = " + NFCommon::tostr(index) + "[(yd_fieldoptions.field_cname) = \"" + col_cn_name +
                    "\"];\n";
        }
        else if (col_type == "int64")
        {
            proto_file +=
                    "\toptional int64 " + col_en_name + " = " + NFCommon::tostr(index) + "[(yd_fieldoptions.field_cname) = \"" + col_cn_name +
                    "\"];\n";
        }
        else if (col_type == "uint64")
        {
            proto_file +=
                    "\toptional uint64 " + col_en_name + " = " + NFCommon::tostr(index) + "[(yd_fieldoptions.field_cname) = \"" + col_cn_name +
                    "\"];\n";
        }
        else if (col_type == "float")
        {
            proto_file +=
                    "\toptional float " + col_en_name + " = " + NFCommon::tostr(index) + "[(yd_fieldoptions.field_cname) = \"" + col_cn_name +
                    "\"];\n";
        }
        else if (col_type == "double")
        {
            proto_file +=
                    "\toptional double " + col_en_name + " = " + NFCommon::tostr(index) + "[(yd_fieldoptions.field_cname) = \"" + col_cn_name +
                    "\"];\n";
        }
        else if (col_type == "string")
        {
            proto_file +=
                    "\toptional string " + col_en_name + " = " + NFCommon::tostr(index) + "[(yd_fieldoptions.field_cname) = \"" + col_cn_name +
                    "\"," + " (yd_fieldoptions.field_bufsize) = " + NFCommon::tostr(get_max_num(colTypeStrMaxSize)) + "];\n";
        }
    }

    for (auto iter = pSheet->m_colInfoVec.begin(); iter != pSheet->m_colInfoVec.end(); iter++)
    {
        ExcelSheetColInfo *pColInfo = iter->second;
        if (pColInfo->m_subInfoMap.empty() && pColInfo->m_maxSubNum == 0) continue;

        index += 1;
        std::string col_en_name = "m_" + NFStringUtility::Lower(pColInfo->m_structEnName);
        std::string col_cn_name = pColInfo->m_structCnName;
        std::string col_type = pColInfo->m_colType;
        uint32_t colTypeStrMaxSize = pColInfo->m_colTypeStrMaxSize;
        uint32_t col_max_size = pColInfo->m_maxSubNum;

        if (pColInfo->m_subInfoMap.size() > 0)
        {
            proto_file += "\trepeated E_" + NFStringUtility::Capitalize(m_excelName) + NFStringUtility::Capitalize(sheet_name) +
                          NFStringUtility::Capitalize(pColInfo->m_structEnName) + "Desc " + col_en_name + " = " + NFCommon::tostr(index) +
                          "[(yd_fieldoptions.field_cname) = \"" + col_cn_name + "\"," + " (yd_fieldoptions.field_arysize) = " +
                          NFCommon::tostr(pColInfo->m_maxSubNum) + "];\n";
        }
        else
        {
            if (col_type == "int" || col_type == "int32")
            {
                proto_file +=
                        "\trepeated int32 " + col_en_name + " = " + NFCommon::tostr(index) + "[(yd_fieldoptions.field_cname) = \"" + col_cn_name +
                        "\", (yd_fieldoptions.field_arysize) = " + NFCommon::tostr(col_max_size) + "];\n";
            }
            else if (col_type == "uint" or col_type == "uint32")
            {
                proto_file +=
                        "\trepeated uint32 " + col_en_name + " = " + NFCommon::tostr(index) + "[(yd_fieldoptions.field_cname) = \"" + col_cn_name +
                        "\", (yd_fieldoptions.field_arysize) = " + NFCommon::tostr(col_max_size) + "];\n";
            }
            else if (col_type == "int64")
            {
                proto_file +=
                        "\trepeated int64 " + col_en_name + " = " + NFCommon::tostr(index) + "[(yd_fieldoptions.field_cname) = \"" + col_cn_name +
                        "\", (yd_fieldoptions.field_arysize) = " + NFCommon::tostr(col_max_size) + "];\n";
            }
            else if (col_type == "uint64")
            {
                proto_file +=
                        "\trepeated uint64 " + col_en_name + " = " + NFCommon::tostr(index) + "[(yd_fieldoptions.field_cname) = \"" + col_cn_name +
                        "\", (yd_fieldoptions.field_arysize) = " + NFCommon::tostr(col_max_size) + "];\n";
            }
            else if (col_type == "float")
            {
                proto_file +=
                        "\trepeated float " + col_en_name + " = " + NFCommon::tostr(index) + "[(yd_fieldoptions.field_cname) = \"" + col_cn_name +
                        "\", (yd_fieldoptions.field_arysize) = " + NFCommon::tostr(col_max_size) + "];\n";
            }
            else if (col_type == "double")
            {
                proto_file +=
                        "\trepeated double " + col_en_name + " = " + NFCommon::tostr(index) + "[(yd_fieldoptions.field_cname) = \"" + col_cn_name +
                        "\", (yd_fieldoptions.field_arysize) = " + NFCommon::tostr(col_max_size) + "];\n";
            }
            else if (col_type == "string")
            {
                proto_file +=
                        "\trepeated string " + col_en_name + " = " + NFCommon::tostr(index) + "[(yd_fieldoptions.field_cname) = \"" + col_cn_name +
                        +"\", (yd_fieldoptions.field_arysize) = " + NFCommon::tostr(col_max_size) + ", (yd_fieldoptions.field_bufsize) = " +
                        NFCommon::tostr(get_max_num(colTypeStrMaxSize)) + "];\n";
            }
        }
    }

    proto_file += "}\n";

    proto_file += "\n\nmessage Sheet_" + NFStringUtility::Capitalize(m_excelName) + NFStringUtility::Capitalize(sheet_name) + "\n";
    proto_file += "{\n";
    proto_file += "\trepeated E_" + NFStringUtility::Capitalize(m_excelName) + NFStringUtility::Capitalize(sheet_name) + " E_" +
                  NFStringUtility::Capitalize(m_excelName) + NFStringUtility::Capitalize(sheet_name) + "_List = 1[(yd_fieldoptions.field_arysize)=1" +
                  "];\n";
    proto_file += "}\n";
}

int ExcelToProto::get_max_num(int num)
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