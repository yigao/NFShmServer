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

int ExcelToProto::Init(const std::string& excel, const std::string& outPath)
{
    m_excel = excel;
    m_outPath = outPath;
    NFStringUtility::Trim(m_excel);
    NFStringUtility::Trim(m_outPath);
    m_outPath = NFFileUtility::NormalizePath(m_outPath);

    CHECK_EXPR(NFFileUtility::IsFileExist(m_excel), -1, "excel:%d not exist", m_excel);
    CHECK_EXPR(NFFileUtility::IsDir(m_outPath), -1, "outPath:%d not exist", m_outPath);

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

    return 0;
}

int ExcelToProto::HandleExcel()
{
    //首先处理list
    workbook wb;
    wb.load(m_excel);
    for(auto iter = wb.begin(); iter != wb.end(); iter++)
    {
        worksheet sheet = *iter;
        NFLogInfo(NF_LOG_SYSTEMLOG, 0, "handle excel:{} sheet:{}", m_excel, sheet.title());
        if (sheet.title() == "main")
        {
        }
        else if (sheet.title() == "list")
        {
            auto sheet_row = sheet.rows();
            for(int row = 1; row < (int)sheet_row.length(); row++)
            {
                auto col_vector = sheet_row[row];
                auto col_sheet_cell = col_vector[0];
                std::string sheet_name = col_sheet_cell.value<std::string>();
                worksheet find_sheet = wb.sheet_by_title(sheet_name);
                if (find_sheet == nullptr)
                {
                    NFLogError(NF_LOG_SYSTEMLOG, 0, "excel:{} list has sheet:{}, but can't find in the excel", m_excel, sheet_name);
                    continue;
                }

                ExcelSheet& excelSheet = m_sheets[sheet_name];
                excelSheet.m_name = sheet_name;
                excelSheet.m_sheet = sheet;
                for(int col = 1; col < (int)col_vector.length(); col++)
                {
                    auto col_index = col_vector[col];
                    std::string col_index_str = col_index.value<std::string>();
                    NFStringUtility::Trim(col_index_str);
                    if (col_index_str.empty()) continue;

                    bool sheet_index_unique = true;
                    if (col_index_str.find(":") != std::string::npos)
                    {
                        std::vector<std::string> tempVec;
                        NFStringUtility::Split(col_index_str, ":", &tempVec);
                        if (tempVec.size() != 2) continue;

                        col_index_str = tempVec[1];
                        NFStringUtility::Trim(col_index_str);
                        sheet_index_unique = false;
                    }

                    std::vector<std::string> col_index_str_vec;
                    NFStringUtility::Split(col_index_str, ",", &col_index_str_vec);

                    if (col_index_str_vec.size() == 1)
                    {
                        std::string key = col_index_str_vec[0];
                        NFStringUtility::Trim(key);
                        if (key.empty()) continue;

                        ExcelSheetIndex& excelSheetIndex = excelSheet.m_indexMap[key];
                        excelSheetIndex.m_key = key;
                        excelSheetIndex.m_queue = sheet_index_unique;
                        excelSheetIndex.m_colIndex = -1;
                        excelSheetIndex.m_maxNum = 0;
                        excelSheetIndex.m_maxQueueNum = 0;

                        NFLogInfo(NF_LOG_SYSTEMLOG, 0, "excel:{} sheet:{} add index:{}", m_excel, sheet_name, key);
                    }
                    else {
                        ExcelSheetComIndex& excelSheetComIndex = excelSheet.m_comIndexMap[col_index_str];
                        excelSheetComIndex.m_key = col_index_str;
                        excelSheetComIndex.m_queue = sheet_index_unique;

                        for(int i = 0; i < (int)col_index_str_vec.size(); i++)
                        {
                            std::string key = col_index_str_vec[i];
                            NFStringUtility::Trim(key);
                            if (key.empty()) continue;

                            ExcelSheetIndex excelSheetIndex;
                            excelSheetIndex.m_key = key;
                            excelSheetIndex.m_queue = true;
                            excelSheetIndex.m_colIndex = -1;
                            excelSheetIndex.m_maxNum = 0;
                            excelSheetIndex.m_maxQueueNum = 0;
                            excelSheetComIndex.m_index.push_back(excelSheetIndex);
                        }
                        NFLogInfo(NF_LOG_SYSTEMLOG, 0, "excel:{} sheet:{} add com_index:{}", m_excel, sheet_name, col_index_str);
                    }
                }
            }
        }
    }

    return 0;
}
