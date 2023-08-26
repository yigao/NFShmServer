// -------------------------------------------------------------------------
//    @FileName         :    ExcelToProto.cpp
//    @Author           :    gaoyi
//    @Date             :    23-8-19
//    @Email			:    445267987@qq.com
//    @Module           :    ExcelToProto
//
// -------------------------------------------------------------------------

#include "ExcelToProto.h"


ExcelToProto::ExcelToProto()
{

}

ExcelToProto::~ExcelToProto()
{

}

int ExcelToProto::HandleExcel()
{
    int iRet = ExcelParse::HandleExcel();
    if (iRet != 0)
    {
        return iRet;
    }

    WriteExcelProto();
    WriteSheetDescStore();
    WriteMakeFile();

    return iRet;
}

void ExcelToProto::HandleColOtherInfo(int col_index, MiniExcelReader::Sheet& sheet, const std::string &colType, uint32_t &uniqueKeysNum, uint32_t &uniqueKeysListNum,
                                      uint32_t &maxSize)
{
    std::unordered_map<std::string, uint32_t> map;
    for (int i = 4; i < (int) sheet.rows(); i++)
    {
        std::string str = sheet.getCell(i, col_index)->to_string();
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



void ExcelToProto::WriteExcelProto()
{
    std::string write_str;

    std::string excel_proto_file = m_outPath + m_excelName + ".proto";

    write_str += "package proto_ff;\n\n";
    write_str += "import \"yd_fieldoptions.proto\";\n\n";
    std::vector<MiniExcelReader::Sheet> &sheets = m_excelReader->sheets();
    for (MiniExcelReader::Sheet &sheet: sheets)
    {
        if (m_sheets.find(sheet.title()) != m_sheets.end() && m_sheets[sheet.title()].m_colInfoMap.size() > 0)
        {
            WriteSheetProto(&m_sheets[sheet.title()], write_str);
        }
    }

    NFFileUtility::WriteFile(excel_proto_file, write_str);
}

void ExcelToProto::WriteSheetDescStore()
{
    std::vector<MiniExcelReader::Sheet> &sheets = m_excelReader->sheets();
    for (MiniExcelReader::Sheet &sheet: sheets)
    {
        if (m_sheets.find(sheet.title()) != m_sheets.end() && m_sheets[sheet.title()].m_colInfoMap.size() > 0)
        {
            WriteSheetDescStoreH(&m_sheets[sheet.title()]);
            WriteSheetDescStoreCPP(&m_sheets[sheet.title()]);
        }
    }

    WriteDestStoreDefine();
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
                  NFStringUtility::Capitalize(m_excelName) + NFStringUtility::Capitalize(sheet_name) + "_List = 1[(yd_fieldoptions.field_arysize)=" +
                  NFCommon::tostr(get_max_num(pSheet->m_rows)) + "];\n";
    proto_file += "}\n";
}

void ExcelToProto::WriteSheetDescStoreH(ExcelSheet *pSheet)
{
    std::string sheet_name = pSheet->m_name;
    std::string desc_file_name = NFStringUtility::Capitalize(m_excelName) + NFStringUtility::Capitalize(sheet_name) + "Desc.h";
    std::string desc_file_path = m_outPath + desc_file_name;
    std::string desc_file;
    desc_file += "#pragma once\n\n";
    desc_file += "#include \"NFServerComm/NFDescStorePlugin/NFIDescStore.h\"\n";
    desc_file += "#include \"NFComm/NFShmCore/NFShmMgr.h\"\n";
    desc_file += "#include \"NFComm/NFShmStl/NFShmHashMap.h\"\n";
    desc_file += "#include \"NFComm/NFShmStl/NFShmVector.h\"\n";
    desc_file += "#include \"NFLogicCommon/NFDescStoreTypeDefines.h\"\n";
    desc_file += "#include \"NFServerLogicMessage/" + m_excelName + "_s.h\"\n";

    desc_file += "\n#define MAX_" + NFStringUtility::Upper(m_excelName) + "_" + NFStringUtility::Upper(sheet_name) + "_NUM " +
                 NFCommon::tostr(get_max_num(pSheet->m_rows)) + "\n";
    for (auto iter = pSheet->m_indexMap.begin(); iter != pSheet->m_indexMap.end(); iter++)
    {
        ExcelSheetIndex &index = iter->second;
        std::string index_key = iter->second.m_key;
        index.m_define = "MAX_INDEX_" + NFStringUtility::Upper(m_excelName) + "_" + NFStringUtility::Upper(sheet_name) + "_" +
                         NFStringUtility::Upper(index_key) + "_NUM";
        index.m_define_one = "UNIQUE_KEY_MAX_INDEX_" + NFStringUtility::Upper(m_excelName) + "_" + NFStringUtility::Upper(sheet_name) + "_" +
                             NFStringUtility::Upper(index_key) + "_NUM";
        desc_file += "\n#define " + index.m_define + " " + NFCommon::tostr(get_max_num(index.m_maxUniqueListNum)) + "\n";
        desc_file += "\n#define " + index.m_define_one + " " + NFCommon::tostr(get_max_num(index.m_maxUniqueNum)) + "\n";
    }

    for (auto iter = pSheet->m_comIndexMap.begin(); iter != pSheet->m_comIndexMap.end(); iter++)
    {
        ExcelSheetComIndex &comIndex = iter->second;
        for (int i = 0; i < (int) comIndex.m_index.size(); i++)
        {
            ExcelSheetIndex &index = comIndex.m_index[i];
            std::string index_key = index.m_key;
            index.m_define = "MAX_COM_INDEX_" + NFStringUtility::Upper(m_excelName) + "_" + NFStringUtility::Upper(sheet_name) + "_" +
                             NFStringUtility::Upper(index_key) + "_NUM";
            index.m_define_one = "UNIQUE_KEY_MAX_COM_INDEX_" + NFStringUtility::Upper(m_excelName) + "_" + NFStringUtility::Upper(sheet_name) + "_" +
                                 NFStringUtility::Upper(index_key) + "_NUM";
            desc_file += "\n#define " + index.m_define + " " + NFCommon::tostr(get_max_num(index.m_maxUniqueListNum)) + "\n";
            desc_file += "\n#define " + index.m_define_one + " " + NFCommon::tostr(get_max_num(index.m_maxUniqueNum)) + "\n";
        }
    }

    desc_file += "\nclass " + NFStringUtility::Capitalize(m_excelName) + NFStringUtility::Capitalize(sheet_name) + "Desc : public NFIDescStore\n";
    desc_file += "{\n";
    desc_file += "public:\n";
    desc_file += "\t" + NFStringUtility::Capitalize(m_excelName) + NFStringUtility::Capitalize(sheet_name) + "Desc();\n";
    desc_file += "\tvirtual ~" + NFStringUtility::Capitalize(m_excelName) + NFStringUtility::Capitalize(sheet_name) + "Desc();\n";
    desc_file += "\tint CreateInit();\n";
    desc_file += "\tint ResumeInit();\n";
    desc_file += "\tconst proto_ff_s::E_" + NFStringUtility::Capitalize(m_excelName) + NFStringUtility::Capitalize(sheet_name) +
                 "_s* GetDesc(int64_t id) const;\n";
    desc_file +=
            "\tproto_ff_s::E_" + NFStringUtility::Capitalize(m_excelName) + NFStringUtility::Capitalize(sheet_name) + "_s* GetDesc(int64_t id);\n";
    desc_file += "\tint GetDescIndex(int id) const;\n";
    desc_file += "\tconst proto_ff_s::E_" + NFStringUtility::Capitalize(m_excelName) + NFStringUtility::Capitalize(sheet_name) +
                 "_s* GetDescByIndex(int index) const;\n";
    desc_file += "\tproto_ff_s::E_" + NFStringUtility::Capitalize(m_excelName) + NFStringUtility::Capitalize(sheet_name) +
                 "_s* GetDescByIndex(int index);\n";
    desc_file += "public:\n";

    for (auto iter = pSheet->m_indexMap.begin(); iter != pSheet->m_indexMap.end(); iter++)
    {
        ExcelSheetIndex &index = iter->second;
        std::string index_key = iter->second.m_key;
        if (index.m_unique)
        {
            desc_file +=
                    "\tconst proto_ff_s::E_" + NFStringUtility::Capitalize(m_excelName) + NFStringUtility::Capitalize(sheet_name) + "_s* GetDescBy" +
                    NFStringUtility::Capitalize(index_key) + "(int64_t " + NFStringUtility::Capitalize(index_key) + ") const;\n";
        }
        else
        {
            desc_file += "\tstd::vector<const proto_ff_s::E_" + NFStringUtility::Capitalize(m_excelName) + NFStringUtility::Capitalize(sheet_name) +
                         "_s*> GetDescBy" + NFStringUtility::Capitalize(index_key) + "(int64_t " + NFStringUtility::Capitalize(index_key) +
                         ") const;\n";
        }

    }

    for (auto iter = pSheet->m_comIndexMap.begin(); iter != pSheet->m_comIndexMap.end(); iter++)
    {
        ExcelSheetComIndex &comIndex = iter->second;
        if (comIndex.m_queue)
        {
            desc_file +=
                    "\tconst proto_ff_s::E_" + NFStringUtility::Capitalize(m_excelName) + NFStringUtility::Capitalize(sheet_name) + "_s* GetDescBy";
        }
        else
        {
            desc_file += "\tstd::vector<const proto_ff_s::E_" + NFStringUtility::Capitalize(m_excelName) + NFStringUtility::Capitalize(sheet_name) +
                         "_s*> GetDescBy";
        }

        for (int i = 0; i < (int) comIndex.m_index.size(); i++)
        {
            std::string index_key = comIndex.m_index[i].m_key;
            desc_file += NFStringUtility::Capitalize(index_key);
        }

        desc_file += "(";

        for (int i = 0; i < (int) comIndex.m_index.size(); i++)
        {
            std::string index_key = comIndex.m_index[i].m_key;
            if (i == (int) comIndex.m_index.size() - 1)
            {
                desc_file += "int64_t " + NFStringUtility::Capitalize(index_key);
            }
            else
            {
                desc_file += "int64_t " + NFStringUtility::Capitalize(index_key) + ", ";
            }
        }

        desc_file += ");\n";
    }

    desc_file += "private:\n";

    for (auto iter = pSheet->m_indexMap.begin(); iter != pSheet->m_indexMap.end(); iter++)
    {
        ExcelSheetIndex &index = iter->second;
        std::string index_key = iter->second.m_key;
        if (index.m_unique)
        {
            desc_file += "\tNFShmHashMap<int64_t, uint32_t, " + index.m_define_one + "> m_" + NFStringUtility::Capitalize(index_key) + "IndexMap;\n";
        }
        else
        {
            desc_file += "\tNFShmHashMap<int64_t, NFShmVector<uint32_t, " + index.m_define_one + ">," + index.m_define + "> m_" +
                         NFStringUtility::Capitalize(index_key) + "IndexMap;\n";
        }
    }

    for (auto iter = pSheet->m_comIndexMap.begin(); iter != pSheet->m_comIndexMap.end(); iter++)
    {
        ExcelSheetComIndex &comIndex = iter->second;
        desc_file += "\tNFShmHashMap<int64_t, ";

        for (int i = 1; i < (int) comIndex.m_index.size(); i++)
        {
            desc_file += "NFShmHashMap<int64_t, ";
        }

        for (int i = comIndex.m_index.size() - 1; i > 0; i--)
        {
            ExcelSheetIndex &index = comIndex.m_index[i];
            std::string index_key = comIndex.m_index[i].m_key;
            if (i == (int) comIndex.m_index.size() - 1)
            {
                if (comIndex.m_queue)
                {
                    desc_file += "uint32_t, " + index.m_define_one + ">";
                }
                else
                {
                    desc_file += "NFShmVector<uint32_t, " + index.m_define_one + ">, " + index.m_define + ">";
                }
            }
            else
            {
                desc_file += ", " + index.m_define_one + ">";
            }
        }

        desc_file += ", " + comIndex.m_index[0].m_define_one + "> m_";
        for (int i = 0; i < (int) comIndex.m_index.size(); i++)
        {
            std::string index_key = comIndex.m_index[i].m_key;
            desc_file += NFStringUtility::Capitalize(index_key);
        }

        desc_file += "ComIndexMap;\n";
    }

    desc_file += "IMPL_RES_HASH_DESC(" + NFStringUtility::Capitalize(m_excelName) + NFStringUtility::Capitalize(sheet_name) + "Desc, proto_ff_s::E_" +
                 NFStringUtility::Capitalize(m_excelName) + NFStringUtility::Capitalize(sheet_name) + "_s, E_" +
                 NFStringUtility::Capitalize(m_excelName) + NFStringUtility::Capitalize(sheet_name) + ", MAX_" + NFStringUtility::Upper(m_excelName) +
                 "_" +
                 NFStringUtility::Upper(sheet_name) + "_NUM);\n";
    desc_file += "DECLARE_IDCREATE(" + NFStringUtility::Capitalize(m_excelName) + NFStringUtility::Capitalize(sheet_name) + "Desc);\n";
    desc_file += "};\n";

    NFFileUtility::WriteFile(desc_file_path, desc_file);
}

void ExcelToProto::WriteSheetDescStoreCPP(ExcelSheet *pSheet)
{
    ExcelSheetColInfo *one_col_info = pSheet->m_colInfoVec.begin()->second;
    std::string key_en_name = "m_" + NFStringUtility::Lower(one_col_info->m_structEnName);

    std::string sheet_name = pSheet->m_name;
    std::string desc_file_name = NFStringUtility::Capitalize(m_excelName) + NFStringUtility::Capitalize(sheet_name) + "Desc.cpp";
    std::string desc_file_path = m_outPath + desc_file_name;
    std::string desc_file;

    desc_file += "#include \"" + NFStringUtility::Capitalize(m_excelName) + NFStringUtility::Capitalize(sheet_name) + "Desc.h\"\n";
    std::set<std::string> headFileHead;
    for (auto iter = pSheet->m_colRelationMap.begin(); iter != pSheet->m_colRelationMap.end(); iter++)
    {
        headFileHead.insert(NFStringUtility::Capitalize(iter->second.m_excelName) + NFStringUtility::Capitalize(iter->second.m_sheetName));
    }

    for (auto iter = headFileHead.begin(); iter != headFileHead.end(); iter++)
    {
        desc_file += "#include \"" + *iter + "Desc.h\"\n";
    }

    desc_file += "#include \"NFComm/NFPluginModule/NFCheck.h\"\n\n";
    desc_file +=
            "IMPLEMENT_IDCREATE_WITHTYPE(" + NFStringUtility::Capitalize(m_excelName) + NFStringUtility::Capitalize(sheet_name) + "Desc, EOT_CONST_" +
            NFStringUtility::Upper(m_excelName) + "_" + NFStringUtility::Upper(sheet_name) + "_DESC_ID, NFShmObj)\n\n";
//////////////////////////////////////////////////////////////
    desc_file +=
            NFStringUtility::Capitalize(m_excelName) + NFStringUtility::Capitalize(sheet_name) + "Desc::" + NFStringUtility::Capitalize(m_excelName) +
            NFStringUtility::Capitalize(sheet_name) + "Desc():NFIDescStore()\n";
    desc_file += "{\n";
    desc_file += "\tif (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {\n";
    desc_file += "\t\tCreateInit();\n";
    desc_file += "\t}\n";
    desc_file += "\telse {\n";
    desc_file += "\t\tResumeInit();\n";
    desc_file += "\t}\n";
    desc_file += "}\n\n";
//////////////////////////////////////////////////////////////////
    desc_file += NFStringUtility::Capitalize(m_excelName) + NFStringUtility::Capitalize(sheet_name) + "Desc::~" +
                 NFStringUtility::Capitalize(m_excelName) + NFStringUtility::Capitalize(sheet_name) + "Desc()\n";
    desc_file += "{\n";
    desc_file += "}\n\n";
///////////////////////////////////////////////////////////
    desc_file += "int " + NFStringUtility::Capitalize(m_excelName) + NFStringUtility::Capitalize(sheet_name) + "Desc::CreateInit()\n";
    desc_file += "{\n";
    desc_file += "\treturn 0;\n";
    desc_file += "}\n\n";
////////////////////////////////////////////////////////////////
    desc_file += "int " + NFStringUtility::Capitalize(m_excelName) + NFStringUtility::Capitalize(sheet_name) + "Desc::ResumeInit()\n";
    desc_file += "{\n";
    desc_file += "\treturn 0;\n";
    desc_file += "}\n\n";
////////////////////////////////////////////////////////////////
    desc_file += "int " + NFStringUtility::Capitalize(m_excelName) + NFStringUtility::Capitalize(sheet_name) + "Desc::Load(NFResDB *pDB)\n";
    desc_file += "{\n";
    desc_file += "\tNFLogTrace(NF_LOG_SYSTEMLOG, 0, \"--begin--\");\n";
    desc_file += "\tCHECK_EXPR(pDB != NULL, -1, \"pDB == NULL\");\n";
    desc_file += "\n";
    desc_file += "\tNFLogTrace(NF_LOG_SYSTEMLOG, 0, \"" + NFStringUtility::Capitalize(m_excelName) + NFStringUtility::Capitalize(sheet_name) +
                 "Desc::Load() strFileName = {}\", GetFileName());\n";
    desc_file += "\n";
    desc_file += "\tproto_ff::Sheet_" + NFStringUtility::Capitalize(m_excelName) + NFStringUtility::Capitalize(sheet_name) + " table;\n";
    desc_file += "\tNFResTable* pResTable = pDB->GetTable(GetFileName());\n";
    desc_file += "\tCHECK_EXPR(pResTable != NULL, -1, \"pTable == NULL, GetTable:{} Error\", GetFileName());\n";
    desc_file += "\n";
    desc_file += "\tint iRet = 0;\n";
    desc_file += "\tiRet = pResTable->FindAllRecord(GetDBName(), &table);\n";
    desc_file += "\tCHECK_EXPR(iRet == 0, -1, \"FindAllRecord Error:{}\", GetFileName());\n";
    desc_file += "\n";
    desc_file += "\t//NFLogTrace(NF_LOG_SYSTEMLOG, 0, \"{}\", table.Utf8DebugString());\n";
    desc_file += "\n";
    desc_file += "\tif ((table.e_" + NFStringUtility::Lower(m_excelName) + NFStringUtility::Lower(sheet_name) + "_list_size() < 0) || (table.e_" +
                 NFStringUtility::Lower(m_excelName) + NFStringUtility::Lower(sheet_name) + "_list_size() > (int)(m_astDesc.max_size())))\n";
    desc_file += "\t{\n";
    desc_file += "\t\tNFLogError(NF_LOG_SYSTEMLOG, 0, \"Invalid TotalNum:{}\", table.e_" + NFStringUtility::Lower(m_excelName) +
                 NFStringUtility::Lower(sheet_name) + "_list_size());\n";
    desc_file += "\t\treturn -2;\n";
    desc_file += "\t}\n";
    desc_file += "\n";
    desc_file +=
            "\tfor (int i = 0; i < (int)table.e_" + NFStringUtility::Lower(m_excelName) + NFStringUtility::Lower(sheet_name) + "_list_size(); i++)\n";
    desc_file += "\t{\n";
    desc_file += "\t\tconst proto_ff::E_" + NFStringUtility::Capitalize(m_excelName) + NFStringUtility::Capitalize(sheet_name) + "& desc = table.e_" +
                 NFStringUtility::Lower(m_excelName) + NFStringUtility::Lower(sheet_name) + "_list(i);\n";
    desc_file += "\t\tif (desc.has_" + key_en_name + "() == false && desc.ByteSize() == 0)\n";
    desc_file += "\t\t{\n";
    desc_file += "\t\t\tNFLogError(NF_LOG_SYSTEMLOG, 0, \"the desc no value, {}\", desc.Utf8DebugString());\n";
    desc_file += "\t\t\tcontinue;\n";
    desc_file += "\t\t}\n";
    desc_file += "\t\t//NFLogTrace(NF_LOG_SYSTEMLOG, 0, \"{}\", desc.Utf8DebugString());\n";
    desc_file += "\t\tif (m_astDescMap.find(desc." + key_en_name + "()) != m_astDescMap.end())\n";
    desc_file += "\t\t{\n";
    desc_file += "\t\t\tif (IsReloading())\n";
    desc_file += "\t\t\t{\n";
    desc_file += "\t\t\t\tauto pDesc = GetDesc(desc." + key_en_name + "());\n";
    desc_file += "\t\t\t\tNF_ASSERT_MSG(pDesc, \"the desc:{} Reload, GetDesc Failed!, id:{}\", GetClassName(), desc." + key_en_name + "());\n";
    desc_file += "\t\t\t\tpDesc->read_from_pbmsg(desc);\n";
    desc_file += "\t\t\t}\n";
    desc_file += "\t\t\telse\n";
    desc_file += "\t\t\t{\n";
    desc_file += "\t\t\t\tNFLogError(NF_LOG_SYSTEMLOG, 0, \"the desc:{} id:{} exist\", GetClassName(), desc." + key_en_name + "());\n";
    desc_file += "\t\t\t}\n";
    desc_file += "\t\t\tcontinue;\n";
    desc_file += "\t\t}\n";


    desc_file += "\t\tm_astDesc.push_back();\n";
    desc_file += "\t\tauto pDesc = &m_astDesc.back();\n";
    desc_file += "\t\tint curIndex = m_astDesc.size() - 1;\n";
    desc_file += "\t\tCHECK_EXPR_ASSERT(pDesc, -1, \"m_astDesc Index Failed desc.id:{}\", desc." + key_en_name + "());\n";
    desc_file += "\t\tpDesc->read_from_pbmsg(desc);\n";
    desc_file += "\t\tauto iter = m_astDescMap.emplace_hint(desc." + key_en_name + "(), curIndex);\n";
    desc_file +=
            "\t\tCHECK_EXPR_ASSERT(iter != m_astDescMap.end(), -1, \"m_astDescMap.Insert Failed desc.id:{}, key maybe exist\", desc." + key_en_name +
            "());\n";
    desc_file += "\t\tuint64_t hashKey = desc." + key_en_name + "();\n";
    desc_file += "\t\tif (hashKey < NF_MAX_DESC_STORE_INDEX_SIZE)\n";
    desc_file += "\t\t{\n";
    desc_file += "\t\t\tif (m_astDescIndex[hashKey] != -1)\n";
    desc_file += "\t\t\t{\n";
    desc_file += "\t\t\t\tNFLogError(NF_LOG_SYSTEMLOG, 0, \"the desc store:{} exist repeated key:{}\", GetFileName(), hashKey);\n";
    desc_file += "\t\t\t\tm_astDescIndex[hashKey] = -1;\n";
    desc_file += "\t\t\t}\n";
    desc_file += "\t\t\telse\n";
    desc_file += "\t\t\t{\n";
    desc_file += "\t\t\t\tm_astDescIndex[hashKey] = curIndex;\n";
    desc_file += "\t\t\t}\n";
    desc_file += "\t\t}\n";
    desc_file += "\t\telse\n";
    desc_file += "\t\t{\n";
    desc_file += "\t\t\t//NFLogError(NF_LOG_SYSTEMLOG, 0, \"the desc store:{} exist key:{} than the max index:{}\", GetFileName(), hashKey, NF_MAX_DESC_STORE_INDEX_SIZE);\n";
    desc_file += "\t\t}\n";
    desc_file += "\t\tCHECK_EXPR_ASSERT(GetDesc(hashKey) == pDesc, -1, \"GetDesc != pDesc, id:{}\", hashKey);\n";


    desc_file += "\t}\n";
    for (auto iter = pSheet->m_indexMap.begin(); iter != pSheet->m_indexMap.end(); iter++)
    {
        ExcelSheetIndex &index = iter->second;
        std::string index_key = index.m_key;
        std::string index_map = "m_" + NFStringUtility::Capitalize(index_key) + "IndexMap";
        desc_file += "\t" + index_map + ".clear();\n";
    }

    if (pSheet->m_indexMap.size() > 0 || pSheet->m_comIndexMap.size() > 0)
    {
        desc_file += "\tfor(int i = 0; i < (int)m_astDesc.size(); i++)\n";
        desc_file += "\t{\n";
        desc_file += "\t\tauto pDesc = &m_astDesc[i];\n";
        for (auto iter = pSheet->m_indexMap.begin(); iter != pSheet->m_indexMap.end(); iter++)
        {
            ExcelSheetIndex &index = iter->second;
            std::string index_key = index.m_key;
            std::string index_key_en_name = "m_" + NFStringUtility::Lower(index_key);
            std::string index_map = "m_" + NFStringUtility::Capitalize(index_key) + "IndexMap";
            if (index.m_unique)
            {
                desc_file += "\t\tCHECK_EXPR_ASSERT(" + index_map + ".find(pDesc->" + index_key_en_name + ") == " + index_map +
                             ".end(), -1, \"unique index:" + index_key + " repeat key:{}\", pDesc->" + index_key_en_name + ");\n";
                desc_file += "\t\tauto key_iter = " + index_map + ".emplace_hint(pDesc->" + index_key_en_name + ", i);\n";
                desc_file += "\t\tCHECK_EXPR_ASSERT(key_iter != " + index_map + ".end(), -1, \"" + index_map + ".emplace_hint Failed pDesc->" +
                             index_key_en_name + ":{}, space not enough\", pDesc->" + index_key_en_name + ");\n";
            }
            else
            {
                desc_file += "\t\tif(" + index_map + ".full())\n";
                desc_file += "\t\t{\n";
                desc_file +=
                        "\t\t\tCHECK_EXPR_ASSERT(" + index_map + ".find(pDesc->" + index_key_en_name + ") != " + index_map + ".end(), -1, \"index:" +
                        index_key + " key:{}, space not enough\", pDesc->" + index_key_en_name + ");\n";
                desc_file += "\t\t}\n";
                desc_file += "\t\t" + index_map + "[pDesc->" + index_key_en_name + "].push_back(i);\n";
            }
        }

        for (auto iter = pSheet->m_comIndexMap.begin(); iter != pSheet->m_comIndexMap.end(); iter++)
        {
            ExcelSheetComIndex &comIndex = iter->second;
            std::string index_map = "m_";
            for (int i = 0; i < (int) comIndex.m_index.size(); i++)
            {
                ExcelSheetIndex &index = comIndex.m_index[i];
                std::string index_key = index.m_key;
                index_map += NFStringUtility::Capitalize(index_key);
            }
            index_map += "ComIndexMap";

            std::string index_0_key = comIndex.m_index[0].m_key;
            std::string index_0_key_en_name = "m_" + NFStringUtility::Lower(index_0_key);
            desc_file += "\t\tif(" + index_map + ".full())\n";
            desc_file += "\t\t{\n";
            desc_file += "\t\t\tCHECK_EXPR_ASSERT(" + index_map + ".find(pDesc->" + index_0_key_en_name + ") != " + index_map +
                         ".end(), -1, \"space not enough\");\n";
            desc_file += "\t\t}\n";

            desc_file += "\t\t" + index_map + "[pDesc->" + index_0_key_en_name + "];\n";
            desc_file += "\t\tauto iter_0 = " + index_map + ".find(pDesc->" + index_0_key_en_name + ");\n";
            desc_file += "\t\tif(iter_0 != " + index_map + ".end())\n";
            desc_file += "\t\t{\n";

            desc_file += "\t\t\tstd::string error = \"" + index_0_key + ":\" + NFCommon::tostr(pDesc->" + index_0_key_en_name + ");\n";

            for (int i = 1; i < (int) comIndex.m_index.size(); i++)
            {
                ExcelSheetIndex &index = comIndex.m_index[i];
                std::string index_key = index.m_key;
                std::string index_key_en_name = "m_" + NFStringUtility::Lower(index_key);

                std::string white_t;
                white_t.append(i + 2, '\t');
                desc_file += white_t + "error += \", " + index_key + ":\" + NFCommon::tostr(pDesc->" + index_key_en_name + ");\n";
                desc_file += white_t + "if(iter_" + NFCommon::tostr(i - 1) + "->second.full())\n";
                desc_file += white_t + "{\n";
                desc_file +=
                        white_t + "\tCHECK_EXPR_ASSERT(iter_" + NFCommon::tostr(i - 1) + "->second.find(pDesc->" + index_key_en_name + ") != iter_" +
                        NFCommon::tostr(i - 1) + "->second.end(), -1, \"space not enough\");\n";
                desc_file += white_t + "}\n";

                if (i == (int) comIndex.m_index.size() - 1)
                {
                    if (comIndex.m_queue)
                    {
                        desc_file += white_t + "CHECK_EXPR_ASSERT(iter_" + NFCommon::tostr(i - 1) + "->second.find(pDesc->" + index_key_en_name +
                                     ") == iter_" + NFCommon::tostr(i - 1) + "->second.end(), -1, \"index: " + index_key +
                                     " repeated:{}\", error);\n";
                        desc_file += white_t + "iter_" + NFCommon::tostr(i - 1) + "->second[pDesc->" + index_key_en_name + "] = i;\n";
                    }
                    else
                    {
                        desc_file += white_t + "iter_" + NFCommon::tostr(i - 1) + "->second[pDesc->" + index_key_en_name + "].push_back(i);\n";
                    }

                    for (int x = comIndex.m_index.size() - 2; x > 0; x--)
                    {
                        white_t = "";
                        white_t.append(x + 2, '\t');
                        desc_file += white_t + "}\n";
                    }
                }
                else
                {
                    desc_file += white_t + "iter_" + NFCommon::tostr(i - 1) + "->second[pDesc->" + index_key_en_name + "];\n";
                    desc_file += white_t + "auto iter_" + NFCommon::tostr(i) + " = iter_" + NFCommon::tostr(i - 1) + "->second.find(pDesc->" +
                                 index_key_en_name + ");\n";
                    desc_file += white_t + "if(iter_" + NFCommon::tostr(i) + " != iter_" + NFCommon::tostr(i - 1) + "->second.end())\n";
                    desc_file += white_t + "{\n";
                }
            }

            desc_file += "\t\t}\n";
        }

        desc_file += "\t}\n";
    }

    desc_file += "\n";
    desc_file += "\tNFLogTrace(NF_LOG_SYSTEMLOG, 0, \"load {}, num={}\", iRet, table.e_" + NFStringUtility::Lower(m_excelName) +
                 NFStringUtility::Lower(sheet_name) + "_list_size());\n";
    desc_file += "\tNFLogTrace(NF_LOG_SYSTEMLOG, 0, \"--end--\");\n";
    desc_file += "\treturn 0;\n";
    desc_file += "}\n\n";
////////////////////////////////////////////////////////////////
    desc_file += "int " + NFStringUtility::Capitalize(m_excelName) + NFStringUtility::Capitalize(sheet_name) + "Desc::CheckWhenAllDataLoaded()\n";
    desc_file += "{\n";
    if (pSheet->m_colRelationMap.size() > 0)
    {
        desc_file += "\tint result = 0;\n";
        desc_file += "\tfor(int i = 0; i < (int)m_astDesc.size(); i++)\n";
        desc_file += "\t{\n";
        desc_file += "\t\tauto pDesc = &m_astDesc[i];\n";
        for (auto iter = pSheet->m_colRelationMap.begin(); iter != pSheet->m_colRelationMap.end(); iter++)
        {
            if (iter->second.m_myColSubName.empty())
            {
                CHECK_EXPR_ASSERT(pSheet->m_colInfoMap.find(iter->second.m_myColName) != pSheet->m_colInfoMap.end(), , "");
                ExcelSheetColInfo* pColInfo = pSheet->m_colInfoMap[iter->second.m_myColName];
                if (pColInfo->m_maxSubNum == 0)
                {
                    desc_file +=
                            "\t\tCHECK_EXPR_MSG_RESULT(" + NFStringUtility::Capitalize(iter->second.m_excelName) +
                            NFStringUtility::Capitalize(iter->second.m_sheetName) +
                            "Desc::Instance(m_pObjPluginManager)->GetDesc(pDesc->m_" + NFStringUtility::Lower(iter->second.m_myColName) +
                            "), result, \"can't find the " + NFStringUtility::Lower(iter->second.m_myColName) + ":{} in the Excel:" +
                            NFStringUtility::Capitalize(iter->second.m_excelName) + ".xlsx Sheet:" +
                            NFStringUtility::Capitalize(iter->second.m_sheetName) +
                            "\", pDesc->m_" + NFStringUtility::Lower(iter->second.m_myColName) + ");\n";
                }
                else
                {
                    desc_file += "\t\tfor(int j = 0; j < (int)pDesc->m_" + NFStringUtility::Lower(iter->second.m_myColName) + ".size(); j++)\n";
                    desc_file += "\t\t{\n";
                    desc_file +=
                            "\t\t\tCHECK_EXPR_MSG_RESULT(" + NFStringUtility::Capitalize(iter->second.m_excelName) +
                            NFStringUtility::Capitalize(iter->second.m_sheetName) +
                            "Desc::Instance(m_pObjPluginManager)->GetDesc(pDesc->m_" + NFStringUtility::Lower(iter->second.m_myColName) +
                            "[j]), result, \"can't find the " + NFStringUtility::Lower(iter->second.m_myColName) + ":{} in the Excel:" +
                            NFStringUtility::Capitalize(iter->second.m_excelName) + ".xlsx Sheet:" +
                            NFStringUtility::Capitalize(iter->second.m_sheetName) +
                            "\", pDesc->m_" + NFStringUtility::Lower(iter->second.m_myColName) + "[j]);\n";
                    desc_file += "\t\t}\n";
                }
            }
            else
            {
                desc_file += "\t\tfor(int j = 0; j < (int)pDesc->m_" + NFStringUtility::Lower(iter->second.m_myColName) + ".size(); j++)\n";
                desc_file += "\t\t{\n";
                desc_file +=
                        "\t\t\tCHECK_EXPR_MSG_RESULT(" + NFStringUtility::Capitalize(iter->second.m_excelName) +
                        NFStringUtility::Capitalize(iter->second.m_sheetName) +
                        "Desc::Instance(m_pObjPluginManager)->GetDesc(pDesc->m_" + NFStringUtility::Lower(iter->second.m_myColName) +
                        "[j].m_" +NFStringUtility::Lower(iter->second.m_myColSubName) + "), result, \"can't find the " + NFStringUtility::Lower(iter->second.m_myColName) + "_" + NFStringUtility::Lower(iter->second.m_myColSubName) + ":{} in the Excel:" +
                        NFStringUtility::Capitalize(iter->second.m_excelName) + ".xlsx Sheet:" +
                        NFStringUtility::Capitalize(iter->second.m_sheetName) +
                        "\", pDesc->m_" + NFStringUtility::Lower(iter->second.m_myColName) + "[j].m_" + NFStringUtility::Lower(iter->second.m_myColSubName) + ");\n";
                desc_file += "\t\t}\n";
            }
        }
        desc_file += "\t}\n";
        desc_file += "\treturn result;\n";
    }
    else
    {
        desc_file += "\treturn 0;\n";
    }

    desc_file += "}\n\n";
////////////////////////////////////////////////////////////////
    desc_file += "const proto_ff_s::E_" + NFStringUtility::Capitalize(m_excelName) + NFStringUtility::Capitalize(sheet_name) + "_s * " +
                 NFStringUtility::Capitalize(m_excelName) + NFStringUtility::Capitalize(sheet_name) + "Desc::GetDesc(int64_t id) const\n";
    desc_file += "{\n";
    desc_file += "\tif (id >= 0 && id < NF_MAX_DESC_STORE_INDEX_SIZE)\n";
    desc_file += "\t{\n";
    desc_file += "\t\tint index = m_astDescIndex[id];\n";
    desc_file += "\t\tif (index >= 0)\n";
    desc_file += "\t\t{\n";
    desc_file += "\t\t\tCHECK_EXPR_ASSERT(index < (int)m_astDesc.size(), NULL, \"the index:{} of the id:{} exist error, than the m_astDesc max index:{}\", index, id, m_astDesc.size());\n";
    desc_file += "\t\t\treturn &m_astDesc[index];\n";
    desc_file += "\t\t}\n";
    desc_file += "\t}\n";
    desc_file += "\n";
    desc_file += "\tauto iter = m_astDescMap.find(id);\n";
    desc_file += "\tif (iter != m_astDescMap.end())\n";
    desc_file += "\t{\n";
    desc_file += "\t\tint index = iter->second;\n";
    desc_file += "\t\tCHECK_EXPR_ASSERT(index >= 0 && index < (int)m_astDesc.size(), NULL, \"the index:{} of the id:{} exist error, than the m_astDesc max index:{}\", index, id, m_astDesc.size());\n";
    desc_file += "\t\treturn &m_astDesc[index];\n";
    desc_file += "\t}\n";
    desc_file += "\n";
    desc_file += "\treturn NULL;\n";
    desc_file += "}\n\n";
#////////////////////////////////////////////////////////////////
    desc_file += "proto_ff_s::E_" + NFStringUtility::Capitalize(m_excelName) + NFStringUtility::Capitalize(sheet_name) + "_s * " +
                 NFStringUtility::Capitalize(m_excelName) + NFStringUtility::Capitalize(sheet_name) + "Desc::GetDesc(int64_t id)\n";
    desc_file += "{\n";
    desc_file += "\treturn const_cast<proto_ff_s::E_" + NFStringUtility::Capitalize(m_excelName) + NFStringUtility::Capitalize(sheet_name) +
                 "_s *>((static_cast<const " + NFStringUtility::Capitalize(m_excelName) + NFStringUtility::Capitalize(sheet_name) +
                 "Desc*>(this))->GetDesc(id));\n";
    desc_file += "}\n\n";
#////////////////////////////////////////////////////////////////
    desc_file += "int " + NFStringUtility::Capitalize(m_excelName) + NFStringUtility::Capitalize(sheet_name) + "Desc::GetDescIndex(int id) const\n";
    desc_file += "{\n";
    desc_file += "\tauto iter = m_astDescMap.find(id);\n";
    desc_file += "\tif (iter != m_astDescMap.end())\n";
    desc_file += "\t{\n";
    desc_file += "\t\treturn iter->second;\n";
    desc_file += "\t}\n";
    desc_file += "\n";
    desc_file += "\treturn -1;\n";
    desc_file += "}\n\n";
#////////////////////////////////////////////////////////////////
    desc_file += "const proto_ff_s::E_" + NFStringUtility::Capitalize(m_excelName) + NFStringUtility::Capitalize(sheet_name) + "_s * " +
                 NFStringUtility::Capitalize(m_excelName) + NFStringUtility::Capitalize(sheet_name) + "Desc::GetDescByIndex(int index) const\n";
    desc_file += "{\n";
    desc_file += "\tCHECK_EXPR_ASSERT(index < (int)m_astDesc.size(), NULL, \"the index:{} exist error, than the m_astDesc max index:{}\", index, m_astDesc.size());\n";
    desc_file += "\treturn &m_astDesc[index];\n";
    desc_file += "}\n\n";

    desc_file += "proto_ff_s::E_" + NFStringUtility::Capitalize(m_excelName) + NFStringUtility::Capitalize(sheet_name) + "_s * " +
                 NFStringUtility::Capitalize(m_excelName) + NFStringUtility::Capitalize(sheet_name) + "Desc::GetDescByIndex(int index)\n";
    desc_file += "{\n";
    desc_file += "\tCHECK_EXPR_ASSERT(index < (int)m_astDesc.size(), NULL, \"the index:{} exist error, than the m_astDesc max index:{}\", index, m_astDesc.size());\n";
    desc_file += "\treturn &m_astDesc[index];\n";
    desc_file += "}\n\n";

    for (auto iter = pSheet->m_indexMap.begin(); iter != pSheet->m_indexMap.end(); iter++)
    {
        ExcelSheetIndex &index = iter->second;
        std::string index_key = index.m_key;
        std::string index_map = "m_" + NFStringUtility::Capitalize(index_key) + "IndexMap";
        if (index.m_unique)
        {
            desc_file += "const proto_ff_s::E_" + NFStringUtility::Capitalize(m_excelName) + NFStringUtility::Capitalize(sheet_name) + "_s* " +
                         NFStringUtility::Capitalize(m_excelName) + NFStringUtility::Capitalize(sheet_name) + "Desc::GetDescBy" +
                         NFStringUtility::Capitalize(index_key) + "(int64_t " + NFStringUtility::Capitalize(index_key) + ") const\n";
            desc_file += "{\n";
            desc_file += "\tauto iter = " + index_map + ".find(" + NFStringUtility::Capitalize(index_key) + ");\n";
            desc_file += "\tif(iter != " + index_map + ".end())\n";
            desc_file += "\t{\n";
            desc_file += "\t\treturn GetDescByIndex(iter->second);\n";
            desc_file += "\t}\n";
            desc_file += "\treturn nullptr;\n";
            desc_file += "}\n\n";
        }
        else
        {
            desc_file += "std::vector<const proto_ff_s::E_" + NFStringUtility::Capitalize(m_excelName) + NFStringUtility::Capitalize(sheet_name) +
                         "_s*> " + NFStringUtility::Capitalize(m_excelName) + NFStringUtility::Capitalize(sheet_name) + "Desc::GetDescBy" +
                         NFStringUtility::Capitalize(index_key) + "(int64_t " + NFStringUtility::Capitalize(index_key) + ") const\n";
            desc_file += "{\n";
            desc_file += "\tstd::vector<const proto_ff_s::E_" + NFStringUtility::Capitalize(m_excelName) + NFStringUtility::Capitalize(sheet_name) +
                         "_s*> m_vec;\n";
            desc_file += "\tauto iter = " + index_map + ".find(" + NFStringUtility::Capitalize(index_key) + ");\n";
            desc_file += "\tif(iter != " + index_map + ".end())\n";
            desc_file += "\t{\n";
            desc_file += "\t\tfor(int i = 0; i < (int)iter->second.size(); i++)\n";
            desc_file += "\t\t{\n";
            desc_file += "\t\t\tauto pDesc = GetDescByIndex(iter->second[i]);\n";
            desc_file += "\t\t\tCHECK_EXPR_CONTINUE(pDesc, \"key:{} GetDescByIndex error:{}\", " + NFStringUtility::Capitalize(index_key) +
                         ", iter->second[i]);\n";
            desc_file += "\t\t\tm_vec.push_back(pDesc);\n";
            desc_file += "\t\t}\n";
            desc_file += "\t}\n";
            desc_file += "\treturn m_vec;\n";
            desc_file += "}\n\n";
        }
    }

    for (auto iter = pSheet->m_comIndexMap.begin(); iter != pSheet->m_comIndexMap.end(); iter++)
    {
        ExcelSheetComIndex &comIndex = iter->second;
        std::string index_0_key = comIndex.m_index[0].m_key;
        std::string index_map = "m_";
        for (int i = 0; i < (int) comIndex.m_index.size(); i++)
        {
            ExcelSheetIndex &index = comIndex.m_index[i];
            std::string index_key = index.m_key;
            index_map += NFStringUtility::Capitalize(index_key);
        }

        index_map += "ComIndexMap";

        if (comIndex.m_queue)
        {
            desc_file += "const proto_ff_s::E_" + NFStringUtility::Capitalize(m_excelName) + NFStringUtility::Capitalize(sheet_name) + "_s* " +
                         NFStringUtility::Capitalize(m_excelName) + NFStringUtility::Capitalize(sheet_name) + "Desc::GetDescBy";
        }
        else
        {
            desc_file += "std::vector<const proto_ff_s::E_" + NFStringUtility::Capitalize(m_excelName) + NFStringUtility::Capitalize(sheet_name) +
                         "_s*> " + NFStringUtility::Capitalize(m_excelName) + NFStringUtility::Capitalize(sheet_name) + "Desc::GetDescBy";
        }

        for (int i = 0; i < (int) comIndex.m_index.size(); i++)
        {
            ExcelSheetIndex &index = comIndex.m_index[i];
            std::string index_key = index.m_key;
            desc_file += NFStringUtility::Capitalize(index_key);
        }

        desc_file += "(";

        for (int i = 0; i < (int) comIndex.m_index.size(); i++)
        {
            ExcelSheetIndex &index = comIndex.m_index[i];
            std::string index_key = index.m_key;
            if (i == (int) comIndex.m_index.size() - 1)
            {
                desc_file += "int64_t " + NFStringUtility::Capitalize(index_key);
            }
            else
            {
                desc_file += "int64_t " + NFStringUtility::Capitalize(index_key) + ", ";
            }
        }

        desc_file += ")\n";

        if (comIndex.m_queue)
        {
            desc_file += "{\n";
            desc_file += "\tauto iter = " + index_map + ".find(" + NFStringUtility::Capitalize(index_0_key) + ");\n";
            desc_file += "\tif(iter != " + index_map + ".end())\n";
            desc_file += "\t{\n";

            for (int i = 1; i < (int) comIndex.m_index.size(); i++)
            {
                ExcelSheetIndex &index = comIndex.m_index[i];
                std::string index_key = index.m_key;
                std::string white_t;
                white_t.append(i + 1, '\t');
                if (i == (int) comIndex.m_index.size() - 1)
                {
                    if (i == 1)
                    {
                        desc_file += white_t + "auto iter_" + NFCommon::tostr(i) + " = iter->second.find(" + NFStringUtility::Capitalize(index_key) +
                                     ");\n";
                        desc_file += white_t + "if (iter_" + NFCommon::tostr(i) + " != iter->second.end())\n";
                        desc_file += white_t + "{\n";
                        desc_file += white_t + "\treturn GetDescByIndex(iter_" + NFCommon::tostr(i) + "->second);\n";
                        desc_file += white_t + "}\n";
                    }
                    else
                    {
                        desc_file += white_t + "auto iter_" + NFCommon::tostr(i) + " = iter_" + NFCommon::tostr(i - 1) + "->second.find(" +
                                     NFStringUtility::Capitalize(index_key) + ");\n";
                        desc_file += white_t + "if (iter_" + NFCommon::tostr(i) + " != iter_" + NFCommon::tostr(i - 1) + "->second.end())\n";
                        desc_file += white_t + "{\n";
                        desc_file += white_t + "\treturn GetDescByIndex(iter_" + NFCommon::tostr(i) + "->second);\n";
                        desc_file += white_t + "}\n";

                        for (int x = (int) comIndex.m_index.size() - 2; x > 0; x--)
                        {
                            white_t = "";
                            white_t.append(x + 1, '\t');
                            desc_file += white_t + "}\n";
                        }
                    }
                }
                else
                {
                    if (i == 1)
                    {
                        desc_file += white_t + "auto iter_" + NFCommon::tostr(i) + " = iter->second.find(" + NFStringUtility::Capitalize(index_key) +
                                     ");\n";
                        desc_file += white_t + "if (iter_" + NFCommon::tostr(i) + " != iter->second.end())\n";
                        desc_file += white_t + "{\n";
                    }
                    else
                    {
                        desc_file += white_t + "auto iter_" + NFCommon::tostr(i) + " = iter_" + NFCommon::tostr(i - 1) + "->second.find(" +
                                     NFStringUtility::Capitalize(index_key) + ");\n";
                        desc_file += white_t + "if (iter_" + NFCommon::tostr(i) + " != iter_" + NFCommon::tostr(i - 1) + "->second.end())\n";
                        desc_file += white_t + "{\n";
                    }
                }
            }

            desc_file += "\t}\n";
            desc_file += "\treturn nullptr;\n";
            desc_file += "}\n\n";
        }
        else
        {
            desc_file += "{\n";
            desc_file += "\tstd::vector<const proto_ff_s::E_" + NFStringUtility::Capitalize(m_excelName) + NFStringUtility::Capitalize(sheet_name) +
                         "_s*> m_vec;\n";
            desc_file += "\tauto iter = " + index_map + ".find(" + NFStringUtility::Capitalize(index_0_key) + ");\n";
            desc_file += "\tif(iter != " + index_map + ".end())\n";
            desc_file += "\t{\n";

            for (int i = 1; i < (int) comIndex.m_index.size(); i++)
            {
                ExcelSheetIndex &index = comIndex.m_index[i];
                std::string index_key = index.m_key;
                std::string white_t;
                white_t.append(i + 1, '\t');
                if (i == (int) comIndex.m_index.size() - 1)
                {
                    if (i == 1)
                    {
                        desc_file += white_t + "auto iter_" + NFCommon::tostr(i) + " = iter->second.find(" + NFStringUtility::Capitalize(index_key) +
                                     ");\n";
                        desc_file += white_t + "if (iter_" + NFCommon::tostr(i) + " != iter->second.end())\n";
                        desc_file += white_t + "{\n";
                        desc_file += white_t + "\tfor(int i = 0; i < (int)iter_" + NFCommon::tostr(i) + "->second.size(); i++)\n";
                        desc_file += white_t + "\t{\n";
                        desc_file += white_t + "\t\tauto pDesc = GetDescByIndex(iter_" + NFCommon::tostr(i) + "->second[i]);\n";
                        desc_file += white_t + "\t\tCHECK_EXPR_CONTINUE(pDesc, \"error\");\n";
                        desc_file += white_t + "\t\tm_vec.push_back(pDesc);\n";
                        desc_file += white_t + "\t}\n";
                        desc_file += white_t + "}\n";
                    }
                    else
                    {
                        desc_file += white_t + "auto iter_" + NFCommon::tostr(i) + " = iter_" + NFCommon::tostr(i - 1) + "->second.find(" +
                                     NFStringUtility::Capitalize(index_key) + ");\n";
                        desc_file += white_t + "if (iter_" + NFCommon::tostr(i) + " != iter_" + NFCommon::tostr(i - 1) + "->second.end())\n";
                        desc_file += white_t + "{\n";
                        desc_file += white_t + "\tfor(int i = 0; i < (int)iter_" + NFCommon::tostr(i) + "->second.size(); i++)\n";
                        desc_file += white_t + "\t{\n";
                        desc_file += white_t + "\t\tauto pDesc = GetDescByIndex(iter_" + NFCommon::tostr(i) + "->second[i]);\n";
                        desc_file += white_t + "\t\tCHECK_EXPR_CONTINUE(pDesc, \"error\");\n";
                        desc_file += white_t + "\t\tm_vec.push_back(pDesc);\n";
                        desc_file += white_t + "\t}\n";
                        desc_file += white_t + "}\n";

                        for (int x = (int) comIndex.m_index.size() - 2; x > 0; x--)
                        {
                            white_t = "";
                            white_t.append(x + 1, '\t');
                            desc_file += white_t + "}\n";
                        }
                    }
                }
                else
                {
                    if (i == 1)
                    {
                        desc_file += white_t + "auto iter_" + NFCommon::tostr(i) + " = iter->second.find(" + NFStringUtility::Capitalize(index_key) +
                                     ");\n";
                        desc_file += white_t + "if (iter_" + NFCommon::tostr(i) + " != iter->second.end())\n";
                        desc_file += white_t + "{\n";
                    }
                    else
                    {
                        desc_file += white_t + "auto iter_" + NFCommon::tostr(i) + " = iter_" + NFCommon::tostr(i - 1) + "->second.find(" +
                                     NFStringUtility::Capitalize(index_key) + ");\n";
                        desc_file += white_t + "if (iter_" + NFCommon::tostr(i) + " != iter_" + NFCommon::tostr(i - 1) + "->second.end())\n";
                        desc_file += white_t + "{\n";
                    }
                }
            }

            desc_file += "\t}\n";
            desc_file += "\treturn m_vec;\n";
            desc_file += "}\n\n";
        }

    }

    NFFileUtility::WriteFile(desc_file_path, desc_file);
}

void ExcelToProto::WriteMakeFile()
{
    std::string excel_src_file_name = NFFileUtility::GetFileName(m_excel);
    std::string sheet_makefile_name = m_outPath + m_excelName + "_gen.makefile";
    std::string makefile_file;
    makefile_file += "include ./define.makefile\n\n";
    makefile_file += ".PHONY:all\n\n";
    makefile_file += "all:module\n\n";

    makefile_file += "module:${PROTOCGEN_FILE_PATH}/" + m_excelName + ".proto.ds ${RESDB_EXCELMMO_PATH}/" + excel_src_file_name + "\n";
    makefile_file += "\tmkdir -p ${PROTOCGEN_FILE_PATH}\n";
    makefile_file += "\t${NFEXCELPROCESS} --work=\"exceltobin\" --src=${RESDB_EXCELMMO_PATH}/" + excel_src_file_name + "  --proto_ds=${PROTOCGEN_FILE_PATH}/" +
                     m_excelName + ".proto.ds --dst=${PROTOCGEN_FILE_PATH}/;\n";

    std::vector<MiniExcelReader::Sheet> &sheets = m_excelReader->sheets();
    for (MiniExcelReader::Sheet &sheet: sheets)
    {
        if (m_sheets.find(sheet.title()) != m_sheets.end() && m_sheets[sheet.title()].m_colInfoMap.size() > 0)
        {
            ExcelSheet *pSheet = &m_sheets[sheet.title()];
            std::string sheet_name = pSheet->m_name;

            makefile_file += "\t${FILE_COPY_EXE} --src=\"${PROTOCGEN_FILE_PATH}/E_" + NFStringUtility::Capitalize(m_excelName) +
                             NFStringUtility::Capitalize(sheet_name) + ".bin" + "\" --dst=${GAME_DATA_PATH}/\n";
            makefile_file += "\t${FILE_COPY_EXE} --src=\"${PROTOCGEN_FILE_PATH}/" + NFStringUtility::Capitalize(m_excelName) +
                             NFStringUtility::Capitalize(sheet_name) + "Desc.h " + "${PROTOCGEN_FILE_PATH}/" +
                             NFStringUtility::Capitalize(m_excelName) + NFStringUtility::Capitalize(sheet_name) +
                             "Desc.cpp\" --dst=${DESC_STORE_PATH}/\n";
        }
    }

    NFFileUtility::WriteFile(sheet_makefile_name, makefile_file);
}

void ExcelToProto::WriteDestStoreDefine()
{
    std::string descStoreHeadFile = m_outPath + "NFDescStoreHead.h";
    std::string destStoreHeadFileRead;
    std::string descStoreHeadFileStr;
    if (!NFFileUtility::IsFileExist(descStoreHeadFile))
    {
        descStoreHeadFileStr += "#pragma once\n\n";
    }
    else
    {
        NFFileUtility::ReadFileContent(descStoreHeadFile, destStoreHeadFileRead);
    }

    std::string descStoreDefineFile = m_outPath + "NFDescStoreDefine.h";
    std::string descStoreDefineFileStr;
    std::string descStoreDefineFileRead;
    if (!NFFileUtility::IsFileExist(descStoreDefineFile))
    {
        descStoreDefineFileStr += "#define EOT_DESC_STORE_ALL_ID_DEFINE \\\n";
    }
    else
    {
        NFFileUtility::ReadFileContent(descStoreDefineFile, descStoreDefineFileRead);
    }

    std::string descStoreRegisterFile = m_outPath + "NFDescStoreRegister.h";
    std::string descStoreRegisterFileStr;
    std::string descStoreRegisterFileRead;
    if (!NFFileUtility::IsFileExist(descStoreRegisterFile))
    {
        descStoreRegisterFileStr += "#define EOT_DESC_STORE_ALL_REGISTER_DEFINE \\\n";
    }
    else
    {
        NFFileUtility::ReadFileContent(descStoreRegisterFile, descStoreRegisterFileRead);
    }


    std::vector<MiniExcelReader::Sheet> &sheets = m_excelReader->sheets();
    for (MiniExcelReader::Sheet &sheet: sheets)
    {
        if (m_sheets.find(sheet.title()) != m_sheets.end() && m_sheets[sheet.title()].m_colInfoMap.size() > 0)
        {
            ExcelSheet *pSheet = &m_sheets[sheet.title()];
            std::string sheet_name = pSheet->m_name;
            if (destStoreHeadFileRead.find(NFStringUtility::Capitalize(m_excelName) + NFStringUtility::Capitalize(sheet_name)) == std::string::npos)
            {
                descStoreHeadFileStr +=
                        "#include \"DescStore/" + NFStringUtility::Capitalize(m_excelName) + NFStringUtility::Capitalize(sheet_name) + "Desc.h\"\n";
            }
        }
    }

    for (MiniExcelReader::Sheet &sheet: sheets)
    {
        if (m_sheets.find(sheet.title()) != m_sheets.end() && m_sheets[sheet.title()].m_colInfoMap.size() > 0)
        {
            ExcelSheet *pSheet = &m_sheets[sheet.title()];
            std::string sheet_name = pSheet->m_name;
            if (descStoreDefineFileRead.find(NFStringUtility::Upper(m_excelName) + "_" + NFStringUtility::Upper(sheet_name)) == std::string::npos)
            {
                descStoreDefineFileStr +=
                        "EOT_CONST_" + NFStringUtility::Upper(m_excelName) + "_" + NFStringUtility::Upper(sheet_name) + "_DESC_ID,\\\n";
            }
        }
    }

    for (MiniExcelReader::Sheet &sheet: sheets)
    {
        if (m_sheets.find(sheet.title()) != m_sheets.end() && m_sheets[sheet.title()].m_colInfoMap.size() > 0)
        {
            ExcelSheet *pSheet = &m_sheets[sheet.title()];
            std::string sheet_name = pSheet->m_name;
            if (descStoreRegisterFileRead.find(NFStringUtility::Capitalize(m_excelName) + NFStringUtility::Capitalize(sheet_name)) ==
                std::string::npos)
            {
                descStoreRegisterFileStr +=
                        "REGISTER_DESCSTORE(" + NFStringUtility::Capitalize(m_excelName) + NFStringUtility::Capitalize(sheet_name) + "Desc);\\\n";
            }
        }
    }

    NFFileUtility::AWriteFile(descStoreHeadFile, descStoreHeadFileStr);
    NFFileUtility::AWriteFile(descStoreDefineFile, descStoreDefineFileStr);
    NFFileUtility::AWriteFile(descStoreRegisterFile, descStoreRegisterFileStr);
}