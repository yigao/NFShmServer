// -------------------------------------------------------------------------
//    @FileName         :    ExcelToTxtGen.cpp
//    @Author           :    gaoyi
//    @Date             :    23-8-28
//    @Email			:    445267987@qq.com
//    @Module           :    ExcelToTxtGen
//
// -------------------------------------------------------------------------

#include "ExcelToTxtGen.h"

ExcelToTxtGen::ExcelToTxtGen()
{

}

ExcelToTxtGen::~ExcelToTxtGen()
{
}

int ExcelToTxtGen::HandleExcel()
{
    int iRet = WriteToGen();
    if (iRet != 0)
    {
        return iRet;
    }

    return 0;
}

int ExcelToTxtGen::WriteToGen()
{
    std::string makefile_file;
    makefile_file += "include ./define.makefile\n\n";
    makefile_file += ".PHONY:all\n\n";
    makefile_file += "all:${PROTOCGEN_FILE_PATH}/"+ NFStringUtility::Capitalize(m_excelName)+"_all_finish";
    makefile_file += "\n\n";

    makefile_file += "${PROTOCGEN_FILE_PATH}/"+ NFStringUtility::Capitalize(m_excelName)+"_all_finish";

    makefile_file += ":${RESDB_EXCEL_PATH}/" + m_excelName + ".xlsx\n";
    makefile_file += "\tmkdir -p ${PROTOCGEN_FILE_PATH}\n";
    makefile_file += "\trm -rf ${PROTOCGEN_FILE_PATH}/"+ NFStringUtility::Capitalize(m_excelName)+"_all_finish\n";
    //makefile_file += "\t${EXCEL2BIN} --excel=$^ --out_path=${PROTOCGEN_FILE_PATH}/\n")
    makefile_file += "\t${NFEXCELPROCESS} --work=\"exceltotxt\" --src=$^ --dst=${PROTOCGEN_FILE_PATH}/\n";
    std::vector<MiniExcelReader::Sheet> &sheets = m_excelReader->sheets();
    for (MiniExcelReader::Sheet &sheet: sheets)
    {
        if (sheet.title() == "main")
        {
        }
        else if (sheet.title() == "list")
        {
        }
        else {
            int iRet = WriteToGen(sheet, makefile_file);
            if (iRet != 0)
            {
                return iRet;
            }
        }
    }
    makefile_file += "\ttouch ${PROTOCGEN_FILE_PATH}/"+ NFStringUtility::Capitalize(m_excelName)+"_all_finish\n";

    std::string gen_file = m_outPath + m_excelName + "_gen.makefile";
    NFFileUtility::WriteFile(gen_file, makefile_file);
    return 0;
}

int ExcelToTxtGen::WriteToGen(MiniExcelReader::Sheet &sheet, string &makefile_file)
{
    std::string sheetname = sheet.title();
    makefile_file += "\t${FILE_COPY_EXE} --src=\"${PROTOCGEN_FILE_PATH}/" + NFStringUtility::Capitalize(m_excelName) + "_" + sheetname + ".txt\" --dst=${GAME_DATA_PATH}/\n";
    makefile_file += "\t${FILE_COPY_EXE} --src=\"${PROTOCGEN_FILE_PATH}/" + NFStringUtility::Capitalize(m_excelName) + NFStringUtility::Capitalize(sheetname) + "Cfg.h \" --dst=${H_FILE_PATH}/\n";
    makefile_file += "\t${FILE_COPY_EXE} --src=\"${PROTOCGEN_FILE_PATH}/" + NFStringUtility::Capitalize(m_excelName) + NFStringUtility::Capitalize(sheetname) + "Cfg.cpp\" --dst=${CPP_FILE_PATH}/\n";
    makefile_file += "\tfor mk_file in $(PRODUCT_ZONE_DIR);do\\\n";
    makefile_file += "\t\tmkdir -p ${PRODUCT_DATA_SERVER_PATH}/$$mk_file/data/config;\\\n";
    makefile_file += "\t\t${FILE_COPY_EXE} --src=\"${PROTOCGEN_FILE_PATH}/" + NFStringUtility::Capitalize(m_excelName) + "_" + sheetname + ".txt\"  --dst=${PRODUCT_DATA_SERVER_PATH}/$$mk_file/data/config/\\\n";
    makefile_file += "\t\techo ${PRODUCT_DATA_SERVER_PATH}/$$mk_file;\\\n";
    makefile_file += "\t\tdone\n";
    makefile_file += "\tfor mk_file in $(PRODUCT_CROSS_DIR);do\\\n";
    makefile_file += "\t\tmkdir -p ${PRODUCT_DATA_SERVER_PATH}/$$mk_file/data/config;\\\n";
    makefile_file += "\t\t${FILE_COPY_EXE} --src=\"${PROTOCGEN_FILE_PATH}/" + NFStringUtility::Capitalize(m_excelName) + "_" + sheetname + ".txt\"  --dst=${PRODUCT_DATA_SERVER_PATH}/$$mk_file/data/config/\\\n";
    makefile_file += "\t\techo ${PRODUCT_DATA_SERVER_PATH}/$$mk_file;\\\n";
    makefile_file += "\t\tdone\n";
    return 0;
}