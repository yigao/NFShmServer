// -------------------------------------------------------------------------
//    @FileName         :    ExcelToMakefile.cpp
//    @Author           :    gaoyi
//    @Date             :    23-8-19
//    @Email			:    445267987@qq.com
//    @Module           :    ExcelToMakefile
//
// -------------------------------------------------------------------------

#include "ExcelToMakefile.h"

void ExcelToMakeFile(const std::string& src, const std::string& dst)
{
    NFLogInfo(NF_LOG_SYSTEMLOG, 0, "src={}, dst={}", src, dst);
    workbook wb;
    wb.load(src);
    for(auto iter = wb.begin(); iter != wb.end(); iter++)
    {
        worksheet sheet = *iter;
        NFLogInfo(NF_LOG_SYSTEMLOG, 0, "read sheet:{}", sheet.title());
    }
}