// -------------------------------------------------------------------------
//    @FileName         :    ExcelToMakefile.cpp
//    @Author           :    gaoyi
//    @Date             :    23-8-19
//    @Email			:    445267987@qq.com
//    @Module           :    ExcelToMakefile
//
// -------------------------------------------------------------------------

#include "ExcelToMakefile.h"

void WriteMakeFile(std::string& excelmmo_gen, std::string& resmetas_gen, const std::string& file)
{
    excelmmo_gen += "${PROTOCGEN_FILE_PATH}/" + file +"_xlsx_finish:${RESDB_EXCELMMO_PATH}/" + file + ".xlsx\n";
    excelmmo_gen += "\tmkdir -p ${PROTOCGEN_FILE_PATH}\n";
    excelmmo_gen += "\trm -rf ${PROTOCGEN_FILE_PATH}/" + file + "_xlsx_finish\n";
    excelmmo_gen += "\t${NFEXCELPROCESS} --work=\"exceltoproto\" --src=$^ --dst=${PROTOCGEN_FILE_PATH}/\n";
    excelmmo_gen += "\t${FILE_COPY_EXE} --work=\"filecopy\" --src=\"${PROTOCGEN_FILE_PATH}/" + file + ".proto ${PROTOCGEN_FILE_PATH}/" + file + "_gen.makefile\" --dst=${RESDB_META_PATH}/\n";
    excelmmo_gen += "\ttouch ${PROTOCGEN_FILE_PATH}/" + file + "_xlsx_finish\n";
    excelmmo_gen += "\n\n";

    resmetas_gen += "${PROTOCGEN_FILE_PATH}/" + file+"_proto_finish:${PROTOCOL_COMM_XML} ${FIELD_OPTIONS_XML} ${RESDB_META_PATH}/" + file + ".proto\n";
    resmetas_gen += "\tmkdir -p ${PROTOCGEN_FILE_PATH}\n";
    resmetas_gen += "\trm -rf ${PROTOCGEN_FILE_PATH}/" + file + "_proto_finish\n";
    resmetas_gen += "\t${PROTOC} $^ -I${THIRD_PARTY_INC_PATH} -I${RESDB_META_PATH} -I${PROTOCOL_COMM_PATH} -I${PROTOCOL_SS_LOGIC_PATH} -I${PROTOCOL_KERNEL_PATH} --include_imports --descriptor_set_out=${PROTOCGEN_FILE_PATH}/" + file + ".proto.ds --cpp_out=${PROTOCGEN_FILE_PATH}\n";
    resmetas_gen += "\t${NFEXCELPROCESS} --work=\"exceltostruct\" --proto_ds=${PROTOCGEN_FILE_PATH}/" + file + ".proto.ds --src=" + file + ".proto --dst=${PROTOCGEN_FILE_PATH}/;\n";
    resmetas_gen += "\t${FILE_COPY_EXE} --work=\"filecopy\" --src=\"${PROTOCGEN_FILE_PATH}/" + file + ".pb.h ${PROTOCGEN_FILE_PATH}/" + file + ".pb.cc ${PROTOCGEN_FILE_PATH}/" + file + "_s.h ${PROTOCGEN_FILE_PATH}/" + file + "_s.cpp \" --dst=${NEW_PROTOCGEN_FILE_PATH}/\n";
    resmetas_gen += "\ttouch ${PROTOCGEN_FILE_PATH}/" + file + "_proto_finish\n";
    resmetas_gen += "\n\n";
}

void ExcelToMakeFile(const std::vector<std::string>& vecStr, const std::string& dst)
{
    NFLogInfo(NF_LOG_SYSTEMLOG, 0, "src={}, dst={}", NFCommon::tostr(vecStr), dst);
    std::string excelmmo_gen;
    std::string resmetas_gen;

    excelmmo_gen += "include ./define.makefile\n\n";
    excelmmo_gen += ".PHONY:all\n\n";
    excelmmo_gen += "all:";
    for(int i = 0; i < (int)vecStr.size(); i++)
    {
        if (vecStr[i].empty()) continue;

       excelmmo_gen += "${PROTOCGEN_FILE_PATH}/" + vecStr[i] + "_xlsx_finish ";
    }
    excelmmo_gen += "\n\n";

    resmetas_gen += "include ./define.makefile\n\n";
    resmetas_gen += ".PHONY:all\n\n";
    resmetas_gen += "all:";
    for(int i = 0; i < (int)vecStr.size(); i++)
    {
        if (vecStr[i].empty()) continue;

       resmetas_gen += "${PROTOCGEN_FILE_PATH}/" + vecStr[i] + "_proto_finish ";
    }
    resmetas_gen += "\n\n";

    for(int i = 0; i < (int)vecStr.size(); i++)
    {
        if (vecStr[i].empty()) continue;
        WriteMakeFile(excelmmo_gen, resmetas_gen, vecStr[i]);
    }

    if (NFFileUtility::IsDir(dst))
    {
        std::string dir = NFFileUtility::NormalizePath(dst);
        NFFileUtility::WriteFile(dir + "excelmmo_gen.makefile", excelmmo_gen);
        NFFileUtility::WriteFile(dir + "resmetas_gen.makefile", resmetas_gen);
        NFLogInfo(NF_LOG_SYSTEMLOG, 0, "create excelmmo_gen.makefile success");
        NFLogInfo(NF_LOG_SYSTEMLOG, 0, "create resmetas_gen.makefile success");
    }
    else {
        NFLogInfo(NF_LOG_SYSTEMLOG, 0, "create makefile fail");
    }
}