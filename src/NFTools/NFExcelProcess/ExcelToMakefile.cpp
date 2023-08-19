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
    NFLogDebug(NF_LOG_SYSTEMLOG, 0, "src={}, dst={}", src, dst);
    WorkBook workBook(src, 0, "GBK");
}