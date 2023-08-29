// -------------------------------------------------------------------------
//    @FileName         :    ExcelToTxt.cpp
//    @Author           :    gaoyi
//    @Date             :    23-8-28
//    @Email			:    445267987@qq.com
//    @Module           :    ExcelToTxt
//
// -------------------------------------------------------------------------

#include "ExcelToTxt.h"

ExcelToTxt::ExcelToTxt()
{

}

ExcelToTxt::~ExcelToTxt()
{
}

int ExcelToTxt::HandleExcel()
{
    int iRet = ExcelParse::HandleExcel();
    if (iRet != 0)
    {
        return iRet;
    }

    iRet = WriteToTxt();
    if (iRet != 0)
    {
        return iRet;
    }
    return 0;
}

int ExcelToTxt::WriteToTxt()
{
    for (auto iter = m_sheets.begin(); iter != m_sheets.end(); iter++)
    {
        ExcelSheet &sheet = iter->second;
        if (sheet.m_colInfoMap.empty()) continue;

        int iRet = WriteToTxt(sheet);
        if (iRet != 0)
        {
            return iRet;
        }
    }
    return 0;
}

int ExcelToTxt::WriteToTxt(ExcelSheet &sheet)
{
    std::string str;
    for (int i = sheet.m_protoInfo.m_startRow; i < (int) sheet.m_rows + 4; i++)
    {
        int iRet = WriteToTxt(sheet, i, str);
        if (iRet != 0)
        {
            return iRet;
        }
    }

    std::string bin_file = m_outPath + NFStringUtility::Capitalize(m_excelName) + "_" + sheet.m_name + ".txt";
    NFFileUtility::WriteFile(bin_file, str);

    std::string h_file = m_outPath + NFStringUtility::Capitalize(m_excelName) + NFStringUtility::Capitalize(sheet.m_name) + ".h";
    NFFileUtility::WriteFile(h_file, str);

    std::string cpp_file = m_outPath + NFStringUtility::Capitalize(m_excelName) + NFStringUtility::Capitalize(sheet.m_name) + ".cpp";
    NFFileUtility::WriteFile(cpp_file, str);
    return 0;
}

int ExcelToTxt::WriteToTxt(ExcelSheet &sheet, int row, std::string& fileStr)
{
    MiniExcelReader::Sheet *pExcelSheet = m_excelReader->getSheet(sheet.m_name);
    CHECK_EXPR(pExcelSheet, -1, "excel:{} Can't find sheet:{} data", m_excel, sheet.m_name);
    for (auto iter = sheet.m_allColInfoList.begin(); iter != sheet.m_allColInfoList.end(); iter++)
    {
        int col = iter->first;
        auto pCell = pExcelSheet->getCell(row, col);
        CHECK_EXPR(pCell, -1, "excel:{} can't get data, row:{} col:{}", row, col);
        std::string value = pCell->to_string();
        if (iter == sheet.m_allColInfoList.begin())
        {
            if (value.empty())
            {
                return 0;
            }
            fileStr += value;
        }
        else {
            fileStr += "#" + value;
        }
    }
    fileStr += "\n";
    return 0;
}


