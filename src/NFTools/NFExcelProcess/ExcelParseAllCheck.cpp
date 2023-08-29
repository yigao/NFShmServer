// -------------------------------------------------------------------------
//    @FileName         :    ExcelParseAll.cpp
//    @Author           :    gaoyi
//    @Date             :    23-8-28
//    @Email			:    445267987@qq.com
//    @Module           :    ExcelParseAll
//
// -------------------------------------------------------------------------

#include "ExcelParseAllCheck.h"
#include "ExcelParseCheck.h"

ExcelParseAllCheck::ExcelParseAllCheck()
{

}

ExcelParseAllCheck::~ExcelParseAllCheck()
{
}

int ExcelParseAllCheck::CheckExcel(const string &listFile)
{
    m_listFile = listFile;
    NFStringUtility::Trim(m_listFile);
    CHECK_EXPR(NFFileUtility::IsFileExist(m_listFile), -1, "list file:{} not exist", m_listFile);

    std::string dir = NFFileUtility::GetFileDirName(m_listFile);
    dir = NFFileUtility::NormalizePath(dir);

    std::string content;
    NFFileUtility::ReadFileContent(m_listFile, content);
    NFStringUtility::Trim(content);
    std::vector<std::string> vec;
    NFStringUtility::Split(content, "\n", &vec);
    for(int i = 0; i < (int)vec.size(); i++)
    {
        NFStringUtility::Trim(vec[i]);
        std::string excel = dir + vec[i] + ".xlsx";
        CHECK_EXPR(NFFileUtility::IsFileExist(excel), -1, "excel file:{} not exist", excel);
        ExcelParseCheck* pCheck = new ExcelParseCheck();
        CHECK_EXPR(pCheck->Init(excel, "./") == 0, -1, "excel file:{} Init Failed", excel);
        CHECK_EXPR(pCheck->HandleExcel() == 0, -1, "excel file:{} HandleExcel Failed", excel);
        m_excelMap.emplace(vec[i], pCheck);
    }

    bool flag = false;
    for(auto iter = m_excelMap.begin(); iter != m_excelMap.end(); iter++)
    {
        ExcelParseCheck* pCheck = iter->second;
        int iRet = pCheck->CheckExcel();
        if (iRet != 0)
        {
            NFLogError(NF_LOG_SYSTEMLOG, 0, "excel file:{} Check Failed", iter->first);
            flag = true;
        }
    }

    for(auto iter = m_excelMap.begin(); iter != m_excelMap.end(); iter++)
    {
        ExcelParseCheck* pCheck = iter->second;
        int iRet = pCheck->CheckRelation();
        if (iRet != 0)
        {
            NFLogError(NF_LOG_SYSTEMLOG, 0, "excel file:{} CheckRelation Failed", iter->first);
            flag = true;
        }
    }

    if (flag)
    {
        return 1;
    }

    return 0;
}

ExcelParseCheck* ExcelParseAllCheck::GetExcelParse(const std::string& excelName)
{
    auto iter = m_excelMap.find(excelName);
    if (iter != m_excelMap.end())
    {
        return iter->second;
    }
    return nullptr;
}