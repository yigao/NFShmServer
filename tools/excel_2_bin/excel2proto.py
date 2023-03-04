#! /usr/bin/python
# -*- encoding: utf-8 -*-

# Excel to Protobuf bin
# Copyright (c) 2015, calmwu
# All rights reserved.
# Email: wubo0067@hotmail.com

"""
	1：用protoc去生成proto对应的*.proto.ds文件
	2：解析proto.ds文件，生成Sheet_xxxx对象
	1：读取excel文件，各个sheet，sheet的名字对应
	层次分割符-是关键字，不能使用在cname中
"""

import xlrd
import sys
import os
import commands
import getopt
import re
import shutil
import ctypes
import time
import string

import yd_fieldoptions_pb2

reload(sys)
sys.setdefaultencoding('utf-8')

from google.protobuf import descriptor
from google.protobuf import message
from google.protobuf import reflection
from google.protobuf import descriptor_pb2
from google.protobuf.descriptor_pb2 import DescriptorProto
from google.protobuf import text_format

from google.protobuf import descriptor_database
from google.protobuf import descriptor_pool
from google.protobuf import message_factory


def get_max_row_num(num):
	if num < 10:
		return 20
	elif num <= 100:
		return int(num / 10) * 10 * 2
	elif num <= 1000:
		return int(num/100) * 100 + 100
	else:
		return int(num/1000) * 1000 + 1000

def sheet_cell_value(sheet, row_index, col_index):
	if sheet.cell_type(row_index, col_index) == xlrd.XL_CELL_EMPTY or \
			sheet.cell_type(row_index, col_index) == xlrd.XL_CELL_BLANK:
		return 0
	elif sheet.cell_type(row_index, col_index) == xlrd.XL_CELL_TEXT and \
			len(sheet.cell_value(row_index, col_index)) == 0:
		return 0

	return sheet.cell_value(row_index, col_index)

def write_sheet_desc_store_h(excel_name, sheet_name, sheet, sheet_col_info, sheet_struct_info, out_path):
	desc_file_name = excel_name.capitalize() + sheet_name.capitalize() + "Desc.h"
	desc_file = open(desc_file_name, 'w')
	desc_file.write("#pragma once\n\n");
	desc_file.write("#include \"NFServerComm/NFDescStorePlugin/NFIDescStore.h\"\n");
	desc_file.write("#include \"NFComm/NFShmCore/NFShmMgr.h\"\n");
	desc_file.write("#include \"NFLogicCommon/NFDescStoreTypeDefines.h\"\n");
	desc_file.write("#include \"NFServerLogicMessage/" + excel_name + "_s.h\"\n");

	desc_file.write("\n#define MAX_" + excel_name.upper() + "_" + sheet_name.upper() + "_NUM " + str(get_max_row_num(sheet.nrows-4)) + "\n");

	desc_file.write("\nclass " + excel_name.capitalize() + sheet_name.capitalize() + "Desc : public NFIDescStore\n");
	desc_file.write("{\n")
	desc_file.write("public:\n")
	desc_file.write("\t" + excel_name.capitalize() + sheet_name.capitalize() + "Desc();\n")
	desc_file.write("\tvirtual ~" + excel_name.capitalize() + sheet_name.capitalize() + "Desc();\n")
	desc_file.write("\tint CreateInit();\n")
	desc_file.write("\tint ResumeInit();\n")
	desc_file.write("\tconst proto_ff_s::E_" + excel_name.capitalize() + sheet_name.capitalize() + "_s* GetDesc(int64_t id) const;\n");
	desc_file.write("\tproto_ff_s::E_" + excel_name.capitalize() + sheet_name.capitalize() + "_s* GetDesc(int64_t id);\n");
	desc_file.write("\tint GetDescIndex(int id) const;\n");
	desc_file.write("\tconst proto_ff_s::E_" + excel_name.capitalize() + sheet_name.capitalize() + "_s* GetDescByIndex(int index) const;\n");
	desc_file.write("\tproto_ff_s::E_" + excel_name.capitalize() + sheet_name.capitalize() + "_s* GetDescByIndex(int index);\n");
	desc_file.write("public:\n")
	desc_file.write("IMPL_RES_HASH_DESC(proto_ff_s::E_" + excel_name.capitalize() + sheet_name.capitalize() + "_s, E_" + excel_name.capitalize() + sheet_name.capitalize() + ", MAX_" + excel_name.upper() + "_" + sheet_name.upper() + "_NUM);\n")
	desc_file.write("DECLARE_IDCREATE(" + excel_name.capitalize() + sheet_name.capitalize() + "Desc);\n")
	desc_file.write("};\n")
	desc_file.close()

	#移动到指定路径
	if os.path.exists(out_path) and out_path != "./":
		shutil.copyfile(desc_file_name, out_path + desc_file_name)
		os.remove(desc_file_name)


def write_sheet_desc_store_cpp(excel_name, sheet_name, sheet, sheet_col_info, sheet_struct_info, out_path):
	one_col_info = sheet_col_info[0]
	key_en_name = "m_" + one_col_info["col_en_name"].lower().strip()

	desc_file_name = excel_name.capitalize() + sheet_name.capitalize() + "Desc.cpp"
	desc_file = open(desc_file_name, 'w')
	desc_file.write("#include \"" + excel_name.capitalize() + sheet_name.capitalize() + "Desc.h\"\n");
	desc_file.write("#include \"NFComm/NFPluginModule/NFCheck.h\"\n\n");
	desc_file.write("IMPLEMENT_IDCREATE_WITHTYPE(" + excel_name.capitalize() + sheet_name.capitalize() + "Desc, EOT_CONST_" + excel_name.upper() + "_" + sheet_name.upper() + "_DESC_ID, NFShmObj)\n\n")
#//////////////////////////////////////////////////////////////
	desc_file.write(excel_name.capitalize() + sheet_name.capitalize() + "Desc::" + excel_name.capitalize() + sheet_name.capitalize() + "Desc():NFIDescStore()\n")
	desc_file.write("{\n");
	desc_file.write("\tif (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {\n");
	desc_file.write("\t\tCreateInit();\n");
	desc_file.write("\t}\n");
	desc_file.write("\telse {\n");
	desc_file.write("\t\tResumeInit();\n");
	desc_file.write("\t}\n");
	desc_file.write("}\n\n");
#//////////////////////////////////////////////////////////////////
	desc_file.write(excel_name.capitalize() + sheet_name.capitalize() + "Desc::~" + excel_name.capitalize() + sheet_name.capitalize() + "Desc()\n")
	desc_file.write("{\n")
	desc_file.write("}\n\n")
#///////////////////////////////////////////////////////////
	desc_file.write("int " + excel_name.capitalize() + sheet_name.capitalize() + "Desc::CreateInit()\n")
	desc_file.write("{\n")
	desc_file.write("\tInitialize();\n")
	desc_file.write("\treturn 0;\n")
	desc_file.write("}\n\n")
#////////////////////////////////////////////////////////////////
	desc_file.write("int " + excel_name.capitalize() + sheet_name.capitalize() + "Desc::ResumeInit()\n")
	desc_file.write("{\n")
	desc_file.write("\treturn 0;\n")
	desc_file.write("}\n\n")
#////////////////////////////////////////////////////////////////
	desc_file.write("int " + excel_name.capitalize() + sheet_name.capitalize() + "Desc::Load(NFResDB *pDB)\n")
	desc_file.write("{\n")
	desc_file.write("\tNFLogTrace(NF_LOG_SYSTEMLOG, 0, \"--begin--\");\n")
	desc_file.write("\tCHECK_EXPR(pDB != NULL, -1, \"pDB == NULL\");\n")
	desc_file.write("\n")
	desc_file.write("\tNFLogTrace(NF_LOG_SYSTEMLOG, 0, \"" + excel_name.capitalize() + sheet_name.capitalize() + "Desc::Load() strFileName = {}\", GetFileName());\n")
	desc_file.write("\n")
	desc_file.write("\tproto_ff::Sheet_" + excel_name.capitalize() + sheet_name.capitalize() + " table;\n")
	desc_file.write("\tNFResTable* pResTable = pDB->GetTable(GetFileName());\n")
	desc_file.write("\tCHECK_EXPR(pResTable != NULL, -1, \"pTable == NULL, GetTable:{} Error\", GetFileName());\n")
	desc_file.write("\n")
	desc_file.write("\tint iRet = 0;\n")
	desc_file.write("\tiRet = pResTable->FindAllRecord(GetDBName(), &table);\n")
	desc_file.write("\tCHECK_EXPR(iRet == 0, -1, \"FindAllRecord Error:{}\", GetFileName());\n")
	desc_file.write("\n")
	desc_file.write("\t//NFLogTrace(NF_LOG_SYSTEMLOG, 0, \"{}\", table.Utf8DebugString());\n")
	desc_file.write("\n")
	desc_file.write("\tif ((table.e_" + excel_name.lower() + sheet_name.lower() + "_list_size() < 0) || (table.e_" + excel_name.lower() + sheet_name.lower() + "_list_size() > (int)(m_astDesc.max_size())))\n")
	desc_file.write("\t{\n")
	desc_file.write("\t\tNFLogError(NF_LOG_SYSTEMLOG, 0, \"Invalid TotalNum:{}\", table.e_" + excel_name.lower() + sheet_name.lower() + "_list_size());\n")
	desc_file.write("\t\treturn -2;\n")
	desc_file.write("\t}\n")
	desc_file.write("\n")
	desc_file.write("\tfor (int i = 0; i < (int)table.e_" + excel_name.lower() + sheet_name.lower() + "_list_size(); i++)\n")
	desc_file.write("\t{\n")
	desc_file.write("\t\tconst proto_ff::E_" + excel_name.capitalize() + sheet_name.capitalize() + "& desc = table.e_" + excel_name.lower() + sheet_name.lower() + "_list(i);\n")
	desc_file.write("\t\tif (desc.has_" + key_en_name + "() == false && desc.ByteSize() == 0)\n")
	desc_file.write("\t\t{\n")
	desc_file.write("\t\t\tNFLogError(NF_LOG_SYSTEMLOG, 0, \"the desc no value, {}\", desc.Utf8DebugString());\n")
	desc_file.write("\t\t\tcontinue;\n")
	desc_file.write("\t\t}\n")
	desc_file.write("\t\t//NFLogTrace(NF_LOG_SYSTEMLOG, 0, \"{}\", desc.Utf8DebugString());\n")
	desc_file.write("\t\tif (m_astDescMap.find(desc." + key_en_name + "()) != m_astDescMap.end())\n")
	desc_file.write("\t\t{\n")
	desc_file.write("\t\t\tif (IsReloading())\n")
	desc_file.write("\t\t\t{\n")
	desc_file.write("\t\t\t\tauto pDesc = GetDesc(desc." + key_en_name + "());\n")
	desc_file.write("\t\t\t\tNF_ASSERT_MSG(pDesc, \"the desc:{} Reload, GetDesc Failed!, id:{}\", GetClassName(), desc." + key_en_name + "());\n")
	desc_file.write("\t\t\t\tpDesc->read_from_pbmsg(desc);\n")
	desc_file.write("\t\t\t}\n")
	desc_file.write("\t\t\telse\n")
	desc_file.write("\t\t\t{\n")
	desc_file.write("\t\t\t\tNFLogError(NF_LOG_SYSTEMLOG, 0, \"the desc:{} id:{} exist\", GetClassName(), desc." + key_en_name + "());\n")
	desc_file.write("\t\t\t}\n")
	desc_file.write("\t\t\tcontinue;\n")
	desc_file.write("\t\t}\n")



	desc_file.write("\t\tm_astDesc.push_back();\n")
	desc_file.write("\t\tauto pDesc = &m_astDesc.back();\n")
	desc_file.write("\t\tint curIndex = m_astDesc.size() - 1;\n")
	desc_file.write("\t\tCHECK_EXPR(pDesc, -1, \"m_astDesc Index Failed desc.id:{}\", desc." + key_en_name + "());\n")
	desc_file.write("\t\tpDesc->read_from_pbmsg(desc);\n");
	desc_file.write("\t\tauto iter = m_astDescMap.emplace_hint(desc." + key_en_name + "(), curIndex);\n")
	desc_file.write("\t\tCHECK_EXPR(iter != m_astDescMap.end(), -1, \"m_astDescMap.Insert Failed desc.id:{}, key maybe exist\", desc." + key_en_name + "());\n")
	desc_file.write("\t\tuint64_t hashKey = desc." + key_en_name + "();\n");
	desc_file.write("\t\tif (hashKey < NF_MAX_DESC_STORE_INDEX_SIZE)\n")
	desc_file.write("\t\t{\n")
	desc_file.write("\t\t\tif (m_astDescIndex[hashKey] != -1)\n")
	desc_file.write("\t\t\t{\n")
	desc_file.write("\t\t\t\tNFLogError(NF_LOG_SYSTEMLOG, 0, \"the desc store:{} exist repeated key:{}\", GetFileName(), hashKey);\n")
	desc_file.write("\t\t\t\tm_astDescIndex[hashKey] = -1;\n")
	desc_file.write("\t\t\t}\n")
	desc_file.write("\t\t\telse\n")
	desc_file.write("\t\t\t{\n")
	desc_file.write("\t\t\t\tm_astDescIndex[hashKey] = curIndex;\n")
	desc_file.write("\t\t\t}\n")
	desc_file.write("\t\t}\n")
	desc_file.write("\t\telse\n")
	desc_file.write("\t\t{\n")
	desc_file.write("\t\t\t//NFLogError(NF_LOG_SYSTEMLOG, 0, \"the desc store:{} exist key:{} than the max index:{}\", GetFileName(), hashKey, NF_MAX_DESC_STORE_INDEX_SIZE);\n")
	desc_file.write("\t\t}\n")
	desc_file.write("\t\tCHECK_EXPR_ASSERT(GetDesc(hashKey) == pDesc, -1, \"GetDesc != pDesc, id:{}\", hashKey);\n")
	desc_file.write("\t}\n")
	desc_file.write("\n")
	desc_file.write("\tNFLogTrace(NF_LOG_SYSTEMLOG, 0, \"load {}, num={}\", iRet, table.e_" + excel_name.lower() + sheet_name.lower() + "_list_size());\n")
	desc_file.write("\tNFLogTrace(NF_LOG_SYSTEMLOG, 0, \"--end--\");\n")
	desc_file.write("\treturn 0;\n")
	desc_file.write("}\n\n")
#////////////////////////////////////////////////////////////////
	desc_file.write("int " + excel_name.capitalize() + sheet_name.capitalize() + "Desc::CheckWhenAllDataLoaded()\n")
	desc_file.write("{\n")
	desc_file.write("\treturn 0;\n")
	desc_file.write("}\n\n")
#////////////////////////////////////////////////////////////////
	desc_file.write("const proto_ff_s::E_" + excel_name.capitalize() + sheet_name.capitalize() + "_s * " + excel_name.capitalize() + sheet_name.capitalize() + "Desc::GetDesc(int64_t id) const\n")
	desc_file.write("{\n")
	desc_file.write("\tif (id >= 0 && id < NF_MAX_DESC_STORE_INDEX_SIZE)\n")
	desc_file.write("\t{\n")
	desc_file.write("\t\tint index = m_astDescIndex[id];\n")
	desc_file.write("\t\tif (index >= 0)\n")
	desc_file.write("\t\t{\n")
	desc_file.write("\t\t\tCHECK_EXPR_ASSERT(index < (int)m_astDesc.size(), NULL, \"the index:{} of the id:{} exist error, than the m_astDesc max index:{}\", index, id, m_astDesc.size());\n")
	desc_file.write("\t\t\treturn &m_astDesc[index];\n")
	desc_file.write("\t\t}\n")
	desc_file.write("\t}\n")
	desc_file.write("\n")
	desc_file.write("\tauto iter = m_astDescMap.find(id);\n")
	desc_file.write("\tif (iter != m_astDescMap.end())\n")
	desc_file.write("\t{\n")
	desc_file.write("\t\tint index = iter->second;\n")
	desc_file.write("\t\tCHECK_EXPR_ASSERT(index >= 0 && index < (int)m_astDesc.size(), NULL, \"the index:{} of the id:{} exist error, than the m_astDesc max index:{}\", index, id, m_astDesc.size());\n")
	desc_file.write("\t\treturn &m_astDesc[index];\n")
	desc_file.write("\t}\n")
	desc_file.write("\n")
	desc_file.write("\treturn NULL;\n")
	desc_file.write("}\n\n")
#////////////////////////////////////////////////////////////////
	desc_file.write("proto_ff_s::E_" + excel_name.capitalize() + sheet_name.capitalize() + "_s * " + excel_name.capitalize() + sheet_name.capitalize() + "Desc::GetDesc(int64_t id)\n")
	desc_file.write("{\n")
	desc_file.write("\treturn const_cast<proto_ff_s::E_" + excel_name.capitalize() + sheet_name.capitalize() + "_s *>((static_cast<const " + excel_name.capitalize() + sheet_name.capitalize() + "Desc*>(this))->GetDesc(id));\n")
	desc_file.write("}\n\n")
#////////////////////////////////////////////////////////////////
	desc_file.write("int " + excel_name.capitalize() + sheet_name.capitalize() + "Desc::GetDescIndex(int id) const\n")
	desc_file.write("{\n")
	desc_file.write("\tauto iter = m_astDescMap.find(id);\n")
	desc_file.write("\tif (iter != m_astDescMap.end())\n")
	desc_file.write("\t{\n")
	desc_file.write("\t\treturn iter->second;\n")
	desc_file.write("\t}\n")
	desc_file.write("\n")
	desc_file.write("\treturn -1;\n")
	desc_file.write("}\n\n")
#////////////////////////////////////////////////////////////////
	desc_file.write("const proto_ff_s::E_" + excel_name.capitalize() + sheet_name.capitalize() + "_s * " + excel_name.capitalize() + sheet_name.capitalize() + "Desc::GetDescByIndex(int index) const\n")
	desc_file.write("{\n")
	desc_file.write("\tCHECK_EXPR_ASSERT(index < (int)m_astDesc.size(), NULL, \"the index:{} exist error, than the m_astDesc max index:{}\", index, m_astDesc.size());\n")
	desc_file.write("\treturn &m_astDesc[index];\n")
	desc_file.write("}\n\n")

	desc_file.write("proto_ff_s::E_" + excel_name.capitalize() + sheet_name.capitalize() + "_s * " + excel_name.capitalize() + sheet_name.capitalize() + "Desc::GetDescByIndex(int index)\n")
	desc_file.write("{\n")
	desc_file.write("\tCHECK_EXPR_ASSERT(index < (int)m_astDesc.size(), NULL, \"the index:{} exist error, than the m_astDesc max index:{}\", index, m_astDesc.size());\n")
	desc_file.write("\treturn &m_astDesc[index];\n")
	desc_file.write("}\n\n")
#////////////////////////////////////////////////////////////////
#////////////////////////////////////////////////////////////////
	desc_file.close()
	#移动到指定路径
	if os.path.exists(out_path) and out_path != "./":
		shutil.copyfile(desc_file_name, out_path + desc_file_name)
		os.remove(desc_file_name)

def write_sheet_proto(proto_file, excel_name, sheet_name, sheet, sheet_col_info, sheet_struct_info):

	for struct_en_name, struct_info in sheet_struct_info.items():
		if struct_info.has_key("sub_msg") == False:
			continue;

		proto_file.write("\nmessage E_"+excel_name.capitalize()+sheet_name.capitalize()+ struct_en_name.capitalize() + "Desc\n");
		proto_file.write("{\n");
		index = 0
		for sub_en_name, sub_info in struct_info["sub_msg"].items():
			sub_en_name = "m_" + sub_en_name.lower()
			cn_sub_name = sub_info["cn_sub_name"]
			col_type = sub_info["col_type"]
			col_max_size = sub_info["col_max_size"]
			if col_type == "int" or col_type == "int32":
				proto_file.write("\toptional int32 " + sub_en_name + " = " + str(index + 1) + "[(yd_fieldoptions.field_cname) = \"" +cn_sub_name + "\"];\n")
			elif col_type == "uint" or col_type == "uint32":
				proto_file.write("\toptional uint32 " + sub_en_name + " = " + str(index + 1) + "[(yd_fieldoptions.field_cname) = \"" +cn_sub_name + "\"];\n")
			elif col_type == "int64":
				proto_file.write("\toptional int64 " + sub_en_name + " = " + str(index + 1) + "[(yd_fieldoptions.field_cname) = \"" +cn_sub_name + "\"];\n")
			elif col_type == "uint64":
				proto_file.write("\toptional uint64 " + sub_en_name + " = " + str(index + 1) + "[(yd_fieldoptions.field_cname) = \"" +cn_sub_name + "\"];\n")
			elif col_type == "float":
				proto_file.write("\toptional float " + sub_en_name + " = " + str(index + 1) + "[(yd_fieldoptions.field_cname) = \"" +cn_sub_name + "\"];\n")
			elif col_type == "double":
				proto_file.write("\toptional double " + sub_en_name + " = " + str(index + 1) + "[(yd_fieldoptions.field_cname) = \"" +cn_sub_name + "\"];\n")
			elif col_type == "string":
				proto_file.write("\toptional string " + sub_en_name + " = " + str(index + 1) + "[(yd_fieldoptions.field_cname) = \"" +cn_sub_name + "\","+" (yd_fieldoptions.field_bufsize) = " + str(get_max_row_num(col_max_size)) + "];\n");

			index = index + 1
		proto_file.write("}\n");

	proto_file.write("\nmessage E_"+excel_name.capitalize()+sheet_name.capitalize()+"\n");
	proto_file.write("{\n");

	index = 0
	for index in xrange(0, len(sheet_col_info)):
		col_en_name = "m_"+sheet_col_info[index]["col_en_name"].lower()
		if sheet_col_info[index]["col_type"] == "int" or sheet_col_info[index]["col_type"] == "int32":
			proto_file.write("\toptional int32 " + col_en_name + " = " + str(index + 1) + "[(yd_fieldoptions.field_cname) = \"" +sheet_col_info[index]["col_cn_name"] + "\"];\n")
		elif sheet_col_info[index]["col_type"] == "uint" or sheet_col_info[index]["col_type"] == "uint32":
			proto_file.write("\toptional uint32 " + col_en_name + " = " + str(index + 1) + "[(yd_fieldoptions.field_cname) = \"" +sheet_col_info[index]["col_cn_name"] + "\"];\n")
		elif sheet_col_info[index]["col_type"] == "int64":
			proto_file.write("\toptional int64 " + col_en_name + " = " + str(index + 1) + "[(yd_fieldoptions.field_cname) = \"" +sheet_col_info[index]["col_cn_name"] + "\"];\n")
		elif sheet_col_info[index]["col_type"] == "uint64":
			proto_file.write("\toptional uint64 " + col_en_name + " = " + str(index + 1) + "[(yd_fieldoptions.field_cname) = \"" +sheet_col_info[index]["col_cn_name"] + "\"];\n")
		elif sheet_col_info[index]["col_type"] == "float":
			proto_file.write("\toptional float " + col_en_name + " = " + str(index + 1) + "[(yd_fieldoptions.field_cname) = \"" +sheet_col_info[index]["col_cn_name"] + "\"];\n")
		elif sheet_col_info[index]["col_type"] == "double":
			proto_file.write("\toptional double " + col_en_name + " = " + str(index + 1) + "[(yd_fieldoptions.field_cname) = \"" +sheet_col_info[index]["col_cn_name"] + "\"];\n")
		elif sheet_col_info[index]["col_type"] == "string":
			proto_file.write("\toptional string " + col_en_name + " = " + str(index + 1) + "[(yd_fieldoptions.field_cname) = \"" +sheet_col_info[index]["col_cn_name"] + "\","+" (yd_fieldoptions.field_bufsize) = " + str(get_max_row_num(sheet_col_info[index]["col_max_size"])) + "];\n");

	for struct_en_name, struct_info in sheet_struct_info.items():
		index = index + 1
		m_struct_en_name = "m_" + struct_en_name.lower()
		if struct_info.has_key("sub_msg"):
			proto_file.write("\trepeated E_" + excel_name.capitalize() + sheet_name.capitalize() + struct_en_name.capitalize() + "Desc " + m_struct_en_name + " = " + str(index + 1) + "[(yd_fieldoptions.field_cname) = \"" +struct_info["cn_name"] + "\","+" (yd_fieldoptions.field_arysize) = " + str(struct_info["max_num"]) + "];\n");
		else:
			cn_name = struct_info["cn_name"]
			col_type = struct_info["col_type"]
			max_num = struct_info["max_num"]
			col_max_size = struct_info["col_max_size"]
			if col_type == "int" or col_type == "int32":
				proto_file.write("\trepeated int32 " + m_struct_en_name + " = " + str(index + 1) + "[(yd_fieldoptions.field_cname) = \"" +cn_name + "\","+" (yd_fieldoptions.field_arysize) = " + str(max_num) + "];\n");
			elif col_type == "uint" or col_type == "uint32":
				proto_file.write("\trepeated uint32 " + m_struct_en_name + " = " + str(index + 1) + "[(yd_fieldoptions.field_cname) = \"" +cn_name + "\","+" (yd_fieldoptions.field_arysize) = " + str(max_num) + "];\n");
			elif col_type == "int64":
				proto_file.write("\trepeated int64 " + m_struct_en_name + " = " + str(index + 1) + "[(yd_fieldoptions.field_cname) = \"" +cn_name + "\","+" (yd_fieldoptions.field_arysize) = " + str(max_num) + "];\n");
			elif col_type == "uint64":
				proto_file.write("\trepeated uint64 " + m_struct_en_name + " = " + str(index + 1) + "[(yd_fieldoptions.field_cname) = \"" +cn_name + "\","+" (yd_fieldoptions.field_arysize) = " + str(max_num) + "];\n");
			elif col_type == "float":
				proto_file.write("\trepeated float " + m_struct_en_name + " = " + str(index + 1) + "[(yd_fieldoptions.field_cname) = \"" +cn_name + "\","+" (yd_fieldoptions.field_arysize) = " + str(max_num) + "];\n");
			elif col_type == "double":
				proto_file.write("\trepeated double " + m_struct_en_name + " = " + str(index + 1) + "[(yd_fieldoptions.field_cname) = \"" +cn_name + "\","+" (yd_fieldoptions.field_arysize) = " + str(max_num) + "];\n");
			elif col_type == "string":
				proto_file.write("\trepeated string " + m_struct_en_name + " = " + str(index + 1) + "[(yd_fieldoptions.field_cname) = \"" +cn_name + "\","+" (yd_fieldoptions.field_arysize) = " + str(max_num) + ", (yd_fieldoptions.field_bufsize) = " + str(get_max_row_num(col_max_size)) + "];\n");

	proto_file.write("}\n");

	proto_file.write("\n\nmessage Sheet_" + excel_name.capitalize()+sheet_name.capitalize() + "\n")
	proto_file.write("{\n");
	proto_file.write("\trepeated E_" + excel_name.capitalize()+sheet_name.capitalize() + " E_" + excel_name.capitalize()+sheet_name.capitalize() + "_List = 1[(yd_fieldoptions.field_arysize)=" + str(get_max_row_num(sheet.nrows-4)) + "];\n");
	proto_file.write("}\n");


def read_excel(desc_store_head_file, desc_store_define_file, desc_store_register_file, excel_file, out_path):
	"""
	excel_file：文件名
	excel_sheetname：文件sheet名
	"""
	excel_fd = xlrd.open_workbook(excel_file)
	sheet_map = {}
	no_need_sheet = {}
	#循环所有sheet
	for sheet in excel_fd.sheets():
		if 0 == cmp(sheet.name, "main"):
			print "donot handle main"
		elif 0 == cmp(sheet.name, "list"):
			#找到对应的sheet
			#sheet的行数
			excel_sheet_row_count = sheet.nrows
			#sheet的列数
			excel_sheet_col_count = sheet.ncols

			#开始按行读取
			for row_index in xrange(0, excel_sheet_row_count):
				sheet_map[sheet.cell_value(row_index, 0)] = 1

	excel_src_file_name = os.path.basename(excel_file)
	excel_file_name = os.path.splitext(excel_src_file_name)
	excel_file_name = excel_file_name[0]

	sheet_proto_name = excel_file_name+".proto"
	proto_file = open(sheet_proto_name, 'w')
	proto_file.write("package proto_ff;\n\n");
	proto_file.write("import \"yd_fieldoptions.proto\";\n\n");

	for sheet in excel_fd.sheets():
		if 0 != cmp(sheet.name, "main") and 0 != cmp(sheet.name, "list") and sheet_map.has_key(sheet.name):
			print "handle the excel:%s.xls sheet:%s" % (excel_file_name, sheet.name)
			#找到对应的sheet
			#sheet的行数
			excel_sheet_row_count = sheet.nrows
			#sheet的列数
			excel_sheet_col_count = sheet.ncols
			sheet_col_info = []
			sheet_struct_info = {}
			sheet_struct_col_info = {}

			#开始按行读取
			for col_index in xrange(0, excel_sheet_col_count):
				col_en_name = str(sheet.cell_value(0, col_index)).strip()
				col_cn_name = str(sheet.cell_value(1, col_index)).strip()
				col_type = str(sheet.cell_value(2, col_index)).strip()

				if len(col_en_name) == 0 or len(col_cn_name) == 0 or len(col_type) == 0:
					continue

				col_sel = int(sheet_cell_value(sheet, 3, col_index))

				if col_sel != 2 and col_sel != 3:
					continue;

				col_en_name_list = col_en_name.split("_")
				col_cn_name_list = re.split('(\d+)', col_cn_name)
				if len(col_en_name_list) == 2 and len(col_cn_name_list) == 3 and len(col_en_name_list[0]) > 0 and len(col_en_name_list[1]) > 0 and len(col_cn_name_list[0]) > 0 and len(col_cn_name_list[2]) > 0:
					sheet_struct_col_info[col_index] = 1
					struct_num = int(col_cn_name_list[1])
					struct_en_name = str(col_en_name_list[0]).strip()
					struct_en_sub_name = str(col_en_name_list[1]).strip()
					struct_cn_name = str(col_cn_name_list[0]).strip()
					struct_cn_sub_name = str(col_cn_name_list[2]).strip()
					if sheet_struct_info.has_key(struct_en_name) == False:
						sheet_struct_info[struct_en_name] = {}
						sheet_struct_info[struct_en_name]["en_name"] = struct_en_name
						sheet_struct_info[struct_en_name]["cn_name"] = struct_cn_name
						sheet_struct_info[struct_en_name]["max_num"] = struct_num
						sheet_struct_info[struct_en_name]["sub_msg"] = {}
						sheet_struct_info[struct_en_name]["sub_msg"][struct_en_sub_name] = {}
						sheet_struct_info[struct_en_name]["sub_msg"][struct_en_sub_name]["en_sub_name"] = struct_en_sub_name
						sheet_struct_info[struct_en_name]["sub_msg"][struct_en_sub_name]["cn_sub_name"] = struct_cn_sub_name
						sheet_struct_info[struct_en_name]["sub_msg"][struct_en_sub_name]["col_type"] = col_type
						sheet_struct_info[struct_en_name]["sub_msg"][struct_en_sub_name]["col_max_size"] = 32
						if col_type == "string":
							for row_index in xrange(4, excel_sheet_row_count):
								string_value = str(sheet.cell_value(row_index, col_index))
								if len(string_value) > sheet_struct_info[struct_en_name]["sub_msg"][struct_en_sub_name]["col_max_size"]:
									sheet_struct_info[struct_en_name]["sub_msg"][struct_en_sub_name]["col_max_size"] = len(string_value)
					else:
						if sheet_struct_info[struct_en_name]["en_name"] == struct_en_name and sheet_struct_info[struct_en_name]["cn_name"] == struct_cn_name:
							if struct_num > sheet_struct_info[struct_en_name]["max_num"]:
								sheet_struct_info[struct_en_name]["max_num"] = struct_num
							if sheet_struct_info[struct_en_name]["sub_msg"].has_key(struct_en_sub_name) == False:
								sheet_struct_info[struct_en_name]["sub_msg"][struct_en_sub_name] = { }
								sheet_struct_info[struct_en_name]["sub_msg"][struct_en_sub_name]["en_sub_name"] = struct_en_sub_name
								sheet_struct_info[struct_en_name]["sub_msg"][struct_en_sub_name]["cn_sub_name"] = struct_cn_sub_name
								sheet_struct_info[struct_en_name]["sub_msg"][struct_en_sub_name]["col_type"] = col_type
								sheet_struct_info[struct_en_name]["sub_msg"][struct_en_sub_name]["col_max_size"] = 32
								if col_type == "string":
									for row_index in xrange(4, excel_sheet_row_count):
										string_value = str(sheet.cell_value(row_index, col_index))
										if len(string_value) > sheet_struct_info[struct_en_name]["sub_msg"][struct_en_sub_name]["col_max_size"]:
											sheet_struct_info[struct_en_name]["sub_msg"][struct_en_sub_name]["col_max_size"] = len(string_value)
				elif len(col_en_name_list) == 2 and len(col_cn_name_list) == 3 and len(col_cn_name_list[0]) > 0 and len(col_cn_name_list[2]) == 0:
					has_col = False
					has_diff = False
					for col_index_temp in xrange(0, excel_sheet_col_count):
						if col_index_temp == col_index:
							continue

						col_en_name_temp = str(sheet.cell_value(0, col_index_temp)).strip()
						col_cn_name_temp = str(sheet.cell_value(1, col_index_temp)).strip()
						col_type_temp = str(sheet.cell_value(2, col_index_temp))
						col_en_name_list_temp = col_en_name_temp.split("_")
						col_cn_name_list_temp = re.split('(\d+)', col_cn_name_temp)
						if len(col_en_name_list_temp) == 2 and col_en_name_temp != col_en_name and col_en_name_temp[0] == col_en_name[0] and\
								len(col_cn_name_list_temp) == 3 and len(col_cn_name_list_temp[0]) > 0 and \
								len(col_cn_name_list_temp[2]) > 0 and col_cn_name_list_temp[0] == col_cn_name_list[0]:
							has_col = True;
							break;
						elif len(col_en_name_list_temp) == 2 and col_en_name_temp != col_en_name and col_en_name_temp[0] == col_en_name[0] and \
								len(col_cn_name_list_temp) == 3 and len(col_cn_name_list_temp[0]) > 0 and len(col_cn_name_list_temp[2]) == 0 and \
								col_cn_name_list_temp[0] != col_cn_name_list[0]:
							has_diff = True
							break

					if has_col == True:
						sheet_struct_col_info[col_index] = 1
						struct_num = int(col_cn_name_list[1])
						struct_en_name = str(col_en_name_list[0]).strip()
						struct_en_sub_name = str(col_en_name_list[1]).strip()
						struct_cn_name = str(col_cn_name_list[0]).strip()
						struct_cn_sub_name = str(col_cn_name_list[2]).strip()
						if sheet_struct_info.has_key(struct_en_name) == False:
							sheet_struct_info[struct_en_name] = {}
							sheet_struct_info[struct_en_name]["en_name"] = struct_en_name
							sheet_struct_info[struct_en_name]["cn_name"] = struct_cn_name
							sheet_struct_info[struct_en_name]["max_num"] = struct_num
							sheet_struct_info[struct_en_name]["sub_msg"] = {}
							sheet_struct_info[struct_en_name]["sub_msg"][struct_en_sub_name] = {}
							sheet_struct_info[struct_en_name]["sub_msg"][struct_en_sub_name]["en_sub_name"] = struct_en_sub_name
							sheet_struct_info[struct_en_name]["sub_msg"][struct_en_sub_name]["cn_sub_name"] = struct_cn_sub_name
							sheet_struct_info[struct_en_name]["sub_msg"][struct_en_sub_name]["col_type"] = col_type
							sheet_struct_info[struct_en_name]["sub_msg"][struct_en_sub_name]["col_max_size"] = 32
							if col_type == "string":
								for row_index in xrange(4, excel_sheet_row_count):
									string_value = str(sheet.cell_value(row_index, col_index))
									if len(string_value) > sheet_struct_info[struct_en_name]["sub_msg"][struct_en_sub_name]["col_max_size"]:
										sheet_struct_info[struct_en_name]["sub_msg"][struct_en_sub_name]["col_max_size"] = len(string_value)
						else:
							if sheet_struct_info[struct_en_name]["en_name"] == struct_en_name and sheet_struct_info[struct_en_name]["cn_name"] == struct_cn_name:
								if struct_num > sheet_struct_info[struct_en_name]["max_num"]:
									sheet_struct_info[struct_en_name]["max_num"] = struct_num
								if sheet_struct_info[struct_en_name]["sub_msg"].has_key(struct_en_sub_name) == False:
									sheet_struct_info[struct_en_name]["sub_msg"][struct_en_sub_name] = { }
									sheet_struct_info[struct_en_name]["sub_msg"][struct_en_sub_name]["en_sub_name"] = struct_en_sub_name
									sheet_struct_info[struct_en_name]["sub_msg"][struct_en_sub_name]["cn_sub_name"] = struct_cn_sub_name
									sheet_struct_info[struct_en_name]["sub_msg"][struct_en_sub_name]["col_type"] = col_type
									sheet_struct_info[struct_en_name]["sub_msg"][struct_en_sub_name]["col_max_size"] = 32
									if col_type == "string":
										for row_index in xrange(4, excel_sheet_row_count):
											string_value = str(sheet.cell_value(row_index, col_index))
											if len(string_value) > sheet_struct_info[struct_en_name]["sub_msg"][struct_en_sub_name]["col_max_size"]:
												sheet_struct_info[struct_en_name]["sub_msg"][struct_en_sub_name]["col_max_size"] = len(string_value)
					elif has_diff == True:
						sheet_struct_col_info[col_index] = 1
						struct_num = int(col_cn_name_list[1])
						struct_en_name = str(col_en_name_list[0]).strip()
						struct_en_sub_name = str(col_en_name_list[1]).strip()
						struct_cn_name = "$$$$"
						struct_cn_sub_name = str(col_cn_name_list[0]).strip()
						if sheet_struct_info.has_key(struct_en_name) == False:
							sheet_struct_info[struct_en_name] = {}
							sheet_struct_info[struct_en_name]["en_name"] = struct_en_name
							sheet_struct_info[struct_en_name]["cn_name"] = struct_cn_name
							sheet_struct_info[struct_en_name]["max_num"] = struct_num
							sheet_struct_info[struct_en_name]["sub_msg"] = {}
							sheet_struct_info[struct_en_name]["sub_msg"][struct_en_sub_name] = {}
							sheet_struct_info[struct_en_name]["sub_msg"][struct_en_sub_name]["en_sub_name"] = struct_en_sub_name
							sheet_struct_info[struct_en_name]["sub_msg"][struct_en_sub_name]["cn_sub_name"] = struct_cn_sub_name
							sheet_struct_info[struct_en_name]["sub_msg"][struct_en_sub_name]["col_type"] = col_type
							sheet_struct_info[struct_en_name]["sub_msg"][struct_en_sub_name]["col_max_size"] = 32
							if col_type == "string":
								for row_index in xrange(4, excel_sheet_row_count):
									string_value = str(sheet.cell_value(row_index, col_index))
									if len(string_value) > sheet_struct_info[struct_en_name]["sub_msg"][struct_en_sub_name]["col_max_size"]:
										sheet_struct_info[struct_en_name]["sub_msg"][struct_en_sub_name]["col_max_size"] = len(string_value)
						else:
							if sheet_struct_info[struct_en_name]["en_name"] == struct_en_name and sheet_struct_info[struct_en_name]["cn_name"] == struct_cn_name:
								if struct_num > sheet_struct_info[struct_en_name]["max_num"]:
									sheet_struct_info[struct_en_name]["max_num"] = struct_num
								if sheet_struct_info[struct_en_name]["sub_msg"].has_key(struct_en_sub_name) == False:
									sheet_struct_info[struct_en_name]["sub_msg"][struct_en_sub_name] = { }
									sheet_struct_info[struct_en_name]["sub_msg"][struct_en_sub_name]["en_sub_name"] = struct_en_sub_name
									sheet_struct_info[struct_en_name]["sub_msg"][struct_en_sub_name]["cn_sub_name"] = struct_cn_sub_name
									sheet_struct_info[struct_en_name]["sub_msg"][struct_en_sub_name]["col_type"] = col_type
									sheet_struct_info[struct_en_name]["sub_msg"][struct_en_sub_name]["col_max_size"] = 32
									if col_type == "string":
										for row_index in xrange(4, excel_sheet_row_count):
											string_value = str(sheet.cell_value(row_index, col_index))
											if len(string_value) > sheet_struct_info[struct_en_name]["sub_msg"][struct_en_sub_name]["col_max_size"]:
												sheet_struct_info[struct_en_name]["sub_msg"][struct_en_sub_name]["col_max_size"] = len(string_value)
					else:
						sheet_struct_col_info[col_index] = 1
						struct_num = int(col_cn_name_list[1])
						struct_en_name = col_en_name
						struct_cn_name = str(col_cn_name_list[0]).strip()
						if sheet_struct_info.has_key(struct_en_name) == False:
							sheet_struct_info[struct_en_name] = {}
							sheet_struct_info[struct_en_name]["en_name"] = struct_en_name
							sheet_struct_info[struct_en_name]["cn_name"] = struct_cn_name
							sheet_struct_info[struct_en_name]["max_num"] = struct_num
							sheet_struct_info[struct_en_name]["col_type"] = col_type
							sheet_struct_info[struct_en_name]["col_max_size"] = 32
							if col_type == "string":
								for row_index in xrange(4, excel_sheet_row_count):
									string_value = str(sheet.cell_value(row_index, col_index))
									if len(string_value) > sheet_struct_info[struct_en_name]["col_max_size"]:
										sheet_struct_info[struct_en_name]["col_max_size"] = len(string_value)
						else:
							if sheet_struct_info[struct_en_name]["en_name"] == struct_en_name and sheet_struct_info[struct_en_name]["cn_name"] == struct_cn_name:
								if struct_num > sheet_struct_info[struct_en_name]["max_num"]:
									sheet_struct_info[struct_en_name]["max_num"] = struct_num
								if col_type == "string":
									for row_index in xrange(4, excel_sheet_row_count):
										string_value = str(sheet.cell_value(row_index, col_index))
										if len(string_value) > sheet_struct_info[struct_en_name]["col_max_size"]:
											sheet_struct_info[struct_en_name]["col_max_size"] = len(string_value)
				elif len(col_en_name_list) == 1 and len(col_cn_name_list) == 3 and len(col_cn_name_list[0]) > 0 and len(col_cn_name_list[2]) == 0:
					sheet_struct_col_info[col_index] = 1
					struct_num = int(col_cn_name_list[1])
					struct_en_name = col_en_name
					struct_cn_name = str(col_cn_name_list[0]).strip()
					if sheet_struct_info.has_key(struct_en_name) == False:
						sheet_struct_info[struct_en_name] = {}
						sheet_struct_info[struct_en_name]["en_name"] = struct_en_name
						sheet_struct_info[struct_en_name]["cn_name"] = struct_cn_name
						sheet_struct_info[struct_en_name]["max_num"] = struct_num
						sheet_struct_info[struct_en_name]["col_type"] = col_type
						sheet_struct_info[struct_en_name]["col_max_size"] = 32
						if col_type == "string":
							for row_index in xrange(4, excel_sheet_row_count):
								string_value = str(sheet.cell_value(row_index, col_index))
								if len(string_value) > sheet_struct_info[struct_en_name]["col_max_size"]:
									sheet_struct_info[struct_en_name]["col_max_size"] = len(string_value)
					else:
						if sheet_struct_info[struct_en_name]["en_name"] == struct_en_name and sheet_struct_info[struct_en_name]["cn_name"] == struct_cn_name:
							if struct_num > sheet_struct_info[struct_en_name]["max_num"]:
								sheet_struct_info[struct_en_name]["max_num"] = struct_num
							if col_type == "string":
								for row_index in xrange(4, excel_sheet_row_count):
									string_value = str(sheet.cell_value(row_index, col_index))
									if len(string_value) > sheet_struct_info[struct_en_name]["col_max_size"]:
										sheet_struct_info[struct_en_name]["col_max_size"] = len(string_value)
				elif len(col_en_name_list) == 1 and len(col_cn_name_list) == 3 and len(col_cn_name_list[0]) > 0 and len(col_cn_name_list[2]) > 0:
					sheet_struct_col_info[col_index] = 1
					struct_num = int(col_cn_name_list[1])
					struct_en_name = str(col_en_name_list[0]).strip()
					struct_cn_name = str(col_cn_name_list[0]).strip() + "9999" + str(col_cn_name_list[2]).strip()
					if sheet_struct_info.has_key(struct_en_name) == False:
						sheet_struct_info[struct_en_name] = {}
						sheet_struct_info[struct_en_name]["en_name"] = struct_en_name
						sheet_struct_info[struct_en_name]["cn_name"] = struct_cn_name
						sheet_struct_info[struct_en_name]["max_num"] = struct_num
						sheet_struct_info[struct_en_name]["col_type"] = col_type
						sheet_struct_info[struct_en_name]["col_max_size"] = 32
						if col_type == "string":
							for row_index in xrange(4, excel_sheet_row_count):
								string_value = str(sheet.cell_value(row_index, col_index))
								if len(string_value) > sheet_struct_info[struct_en_name]["col_max_size"]:
									sheet_struct_info[struct_en_name]["col_max_size"] = len(string_value)
					else:
						if sheet_struct_info[struct_en_name]["en_name"] == struct_en_name and sheet_struct_info[struct_en_name]["cn_name"] == struct_cn_name:
							if struct_num > sheet_struct_info[struct_en_name]["max_num"]:
								sheet_struct_info[struct_en_name]["max_num"] = struct_num
							if col_type == "string":
								for row_index in xrange(4, excel_sheet_row_count):
									string_value = str(sheet.cell_value(row_index, col_index))
									if len(string_value) > sheet_struct_info[struct_en_name]["col_max_size"]:
										sheet_struct_info[struct_en_name]["col_max_size"] = len(string_value)

			#开始按行读取
			for col_index in xrange(0, excel_sheet_col_count):
				col_en_name = str(sheet.cell_value(0, col_index)).strip()
				col_cn_name = str(sheet.cell_value(1, col_index)).strip()
				col_type = sheet.cell_value(2, col_index)

				if len(col_en_name) == 0 or len(col_cn_name) == 0 or len(col_type) == 0:
					continue

				col_sel = int(sheet_cell_value(sheet, 3, col_index))

				if col_sel != 2 and col_sel != 3:
					continue;

				if sheet_struct_col_info.has_key(col_index):
					continue;

				one_col_info = {}
				one_col_info["col_en_name"] = str(sheet.cell_value(0, col_index)).strip()
				one_col_info["col_cn_name"] = str(sheet.cell_value(1, col_index)).strip()
				one_col_info["col_type"] = col_type
				one_col_info["col_max_size"] = int(32)
				if col_type == "string":
					for row_index in xrange(4, excel_sheet_row_count):
						string_value = str(sheet.cell_value(row_index, col_index))
						if len(string_value) > one_col_info["col_max_size"]:
							one_col_info["col_max_size"] = len(string_value)

				sheet_col_info.append(one_col_info)

			if len(sheet_col_info) == 0 and bool(sheet_struct_info) == False:
				no_need_sheet[sheet.name] = 1
				continue;

			write_sheet_proto(proto_file, excel_file_name, sheet.name, sheet, sheet_col_info, sheet_struct_info)
			write_sheet_desc_store_h(excel_file_name, sheet.name, sheet, sheet_col_info, sheet_struct_info, out_path)
			write_sheet_desc_store_cpp(excel_file_name, sheet.name, sheet, sheet_col_info, sheet_struct_info, out_path)

	sheet_makefile_name = excel_file_name+"_gen.makefile"
	makefile_file = open(sheet_makefile_name, 'w')
	makefile_file.write("include ./define.makefile\n\n");
	makefile_file.write(".PHONY:all\n\n");
	makefile_file.write("all:");

	for sheet in excel_fd.sheets():
		if 0 != cmp(sheet.name, "main") and 0 != cmp(sheet.name, "list") and sheet_map.has_key(sheet.name) and no_need_sheet.has_key(sheet.name) == False:
			makefile_file.write("${PROTOCGEN_FILE_PATH}/E_" + excel_file_name.capitalize() + sheet.name.capitalize() + ".bin " + "${PROTOCGEN_FILE_PATH}/" + excel_file_name.capitalize() + sheet.name.capitalize() + "Desc.h " + "${PROTOCGEN_FILE_PATH}/" + excel_file_name.capitalize() + sheet.name.capitalize() + "Desc.cpp ");

	makefile_file.write("\n\n");

	for sheet in excel_fd.sheets():
		if 0 != cmp(sheet.name, "main") and 0 != cmp(sheet.name, "list") and sheet_map.has_key(sheet.name) and no_need_sheet.has_key(sheet.name) == False:
			makefile_file.write("${PROTOCGEN_FILE_PATH}/E_" + excel_file_name.capitalize() +sheet.name.capitalize() + ".bin:${PROTOCGEN_FILE_PATH}/" + excel_file_name + ".proto.ds ${RESDB_EXCELMMO_PATH}/" + excel_src_file_name + "\n");
			makefile_file.write("\tmkdir -p ${PROTOCGEN_FILE_PATH}\n")
			makefile_file.write("\t${EXCEL2BIN_MMO} --excel=${RESDB_EXCELMMO_PATH}/" + excel_src_file_name + "  --proto_ds=${PROTOCGEN_FILE_PATH}/" + excel_file_name + ".proto.ds --proto_package=proto_ff \\\n");
			makefile_file.write("\t\t--proto_sheet_msgname=Sheet_" + excel_file_name.capitalize()+sheet.name.capitalize() + "  --excel_sheetname=" + sheet.name + "  --proto_msgname=E_" + excel_file_name.capitalize()+sheet.name.capitalize() + "  --start_row=4 --out_path=${PROTOCGEN_FILE_PATH}/;\n");
			makefile_file.write("\t${FILE_COPY_EXE} --src=\"" + "${PROTOCGEN_FILE_PATH}/E_" + excel_file_name.capitalize() +sheet.name.capitalize() + ".bin" + "\" --dst=${GAME_DATA_PATH}/\n")
			makefile_file.write("\t${FILE_COPY_EXE} --src=\"" + "${PROTOCGEN_FILE_PATH}/" + excel_file_name.capitalize() + sheet.name.capitalize() + "Desc.h " + "${PROTOCGEN_FILE_PATH}/" + excel_file_name.capitalize() + sheet.name.capitalize() + "Desc.cpp\" --dst=${DESC_STORE_PATH}/\n\n")

	for sheet in excel_fd.sheets():
		if 0 != cmp(sheet.name, "main") and 0 != cmp(sheet.name, "list") and sheet_map.has_key(sheet.name) and no_need_sheet.has_key(sheet.name) == False:
			desc_store_head_file.write("#include \"DescStore/" + excel_file_name.capitalize() + sheet.name.capitalize() + "Desc.h\"\n")

	for sheet in excel_fd.sheets():
		if 0 != cmp(sheet.name, "main") and 0 != cmp(sheet.name, "list") and sheet_map.has_key(sheet.name) and no_need_sheet.has_key(sheet.name) == False:
			desc_store_define_file.write("EOT_CONST_" + excel_file_name.upper() + "_" + sheet.name.upper() + "_DESC_ID,\\\n")

	for sheet in excel_fd.sheets():
		if 0 != cmp(sheet.name, "main") and 0 != cmp(sheet.name, "list") and sheet_map.has_key(sheet.name) and no_need_sheet.has_key(sheet.name) == False:
			desc_store_register_file.write("REGISTER_DESCSTORE(" + excel_file_name.capitalize() + sheet.name.capitalize() + "Desc);\\\n")

	proto_file.close()
	makefile_file.close()

	#移动到指定路径
	if os.path.exists(out_path) and out_path != "./":
		shutil.copyfile(sheet_proto_name, out_path + sheet_proto_name)
		os.remove(sheet_proto_name)
		shutil.copyfile(sheet_makefile_name, out_path + sheet_makefile_name)
		os.remove(sheet_makefile_name)

def show_usage():
	print """usage for excel2bin example:
	./excel2bin --excel=x-1.xls
                --out_path=./"""

if __name__ == "__main__":
	(opts, args) = getopt.getopt(sys.argv[1:], "e:o", ["excel=", "out_path="])

	if( 0 == len( opts ) ):
		show_usage()
		sys.exit( -1 )

	excel_files = []
	excel_sheetnames = []
	out_path = ""

	reload(sys)
	sys.setdefaultencoding("utf-8")

	for (o, a) in opts:
		if o in ("-e", "--excel"):
			excel_files.append(a)
		elif o in ("-o", "--out_path"):
			out_path = a
		else:
			print "unknown command!"
			show_usage()
			sys.exit(-1)

	print "Input parameters:\n\texcel_files[%s]\n\t" % (excel_files)


	#读取excel
	desc_store_head_file_name = out_path + "NFDescStoreHead.h"
	desc_store_head_file_has = os.path.exists(desc_store_head_file_name)

	desc_store_head_file = open(desc_store_head_file_name, 'a')

	desc_store_define_file_name = out_path + "NFDescStoreDefine.h"
	desc_store_define_file_has = os.path.exists(desc_store_define_file_name)

	desc_store_define_file = open(desc_store_define_file_name, 'a')

	desc_store_register_file_name = out_path + "NFDescStoreRegister.h"
	desc_store_register_file_has = os.path.exists(desc_store_register_file_name)

	desc_store_register_file = open(desc_store_register_file_name, 'a')

	if not desc_store_head_file_has:
		desc_store_head_file.write("#pragma once\n\n");
	if not desc_store_define_file_has:
		desc_store_define_file.write("#define EOT_DESC_STORE_ALL_ID_DEFINE \\\n");
	if not desc_store_register_file_has:
		desc_store_register_file.write("#define EOT_DESC_STORE_ALL_REGISTER_DEFINE \\\n");

	for excel_file in excel_files:
		read_excel(desc_store_head_file, desc_store_define_file, desc_store_register_file, excel_file, out_path)

	desc_store_head_file.close()
	desc_store_define_file.close()
	desc_store_register_file.close()

	print "Success Handle Excel:\n\texcel_files[%s]\n\t" % (excel_files)
