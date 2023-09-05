// -------------------------------------------------------------------------
//    @FileName         :    ExcelToStruct.cpp
//    @Author           :    gaoyi
//    @Date             :    23-9-4
//    @Email			:    445267987@qq.com
//    @Module           :    ExcelToStruct
//
// -------------------------------------------------------------------------

#include <fstream>
#include "ExcelToStruct.h"
#include "NFComm/NFPluginModule/NFProtobufCommon.h"
#include "NFComm/NFPluginModule/NFLogMgr.h"
#include "NFComm/NFCore/NFStringUtility.h"
#include "NFComm/NFPluginModule/NFCheck.h"

ExcelToStruct::ExcelToStruct()
{

}

ExcelToStruct::~ExcelToStruct()
{
}

int ExcelToStruct::Init(const string &protoName, const string &outPath, const string &proto_ds)
{
    m_protoFileName = protoName;
    m_outPath = outPath;
    NFStringUtility::Trim(m_protoFileName);
    NFStringUtility::Trim(m_outPath);
    m_outPath = NFFileUtility::NormalizePath(m_outPath);
    m_protoName = NFFileUtility::GetFileNameWithoutExt(m_protoFileName);

    CHECK_EXPR(NFFileUtility::IsDir(m_outPath), -1, "outPath:{} not exist", m_outPath);
    m_proto_ds = proto_ds;
    std::ifstream pb_file(m_proto_ds.c_str(), std::ios::binary);
    if (!pb_file.is_open())
    {
        return -1;
    }


    if (!m_file_descriptor_set.ParseFromIstream(&pb_file))
    {
        return -1;
    }

    return ParseProto();
}

int ExcelToStruct::ParseProto()
{
    for (int i = 0; i < m_file_descriptor_set.file_size(); ++i)
    {
        const ::google::protobuf::FileDescriptorProto &fileProto = m_file_descriptor_set.file(i);
        if (fileProto.name() == m_protoFileName)
        {
            return ParseProto(fileProto);
        }
    }
    return -1;
}

int ExcelToStruct::ParseProto(const ::google::protobuf::FileDescriptorProto &fileProto)
{
    std::unordered_set<std::string> includeImport;
    includeImport.insert("descriptor");
    includeImport.insert("yd_fieldoptions");
    m_fileDesc.m_namespace = fileProto.package();
    m_fileDesc.m_include_list.push_back(m_protoName + ".pb.h");
    m_fileDesc.m_include_list.push_back(m_protoName + "_s.h");

    //这里得到该文件中的所有import项目
    for (int i = 0; i < (int) fileProto.dependency_size(); i++)
    {
        const std::string import_proto = fileProto.dependency(i);
        std::string protoName = NFFileUtility::GetFileNameWithoutExt(import_proto);
        if (includeImport.find(protoName) == includeImport.end())
        {
            m_fileDesc.m_include_list.push_back(protoName + ".pb.h");
            m_fileDesc.m_include_list.push_back(protoName + "_s.h");
        }
    }

    for (int i = 0; i < (int) fileProto.message_type_size(); i++)
    {
        const ::google::protobuf::DescriptorProto &message_desc_proto = fileProto.message_type(i);
        m_fileDesc.m_message_desc.push_back(ProtoMessageDesc());
        ProtoMessageDesc &message_info = m_fileDesc.m_message_desc.back();
        message_info.m_name = message_desc_proto.name();
        message_info.m_pb_msgname = "::" + m_fileDesc.m_namespace + "::" + message_info.m_name;

        for (int j = 0; j < (int) message_desc_proto.field_size(); j++)
        {
            const ::google::protobuf::FieldDescriptorProto &field_desc_proto = message_desc_proto.field(j);
            const ::google::protobuf::FieldOptions& field_options = field_desc_proto.options();

            message_info.m_fieldList.push_back(ProtoMessageFieldDesc());
            ProtoMessageFieldDesc *message_field_info = &message_info.m_fieldList.back();
            message_field_info->m_name = field_desc_proto.name();

            if (field_options.HasExtension(yd_fieldoptions::no_db_field))
            {
                message_field_info->m_noField = true;
            }

            if (field_options.HasExtension(yd_fieldoptions::field_use_stl))
            {
                message_info.m_useStl = true;
            }

            if (field_desc_proto.label() == ::google::protobuf::FieldDescriptorProto_Label_LABEL_REPEATED)
            {
                message_field_info->m_isArray = true;
                message_field_info->m_arraySize = field_options.GetExtension(yd_fieldoptions::field_arysize);
                if (message_field_info->m_arraySize == 0)
                {
                    message_field_info->m_arraySize = 1;
                }
            }

            if (field_desc_proto.type() == ::google::protobuf::FieldDescriptorProto_Type_TYPE_DOUBLE)
            {
                message_field_info->m_c_type = message_field_info->m_pb_type = message_field_info->m_convert_type = "double";
            }
            else if (field_desc_proto.type() == ::google::protobuf::FieldDescriptorProto_Type_TYPE_FLOAT)
            {
                message_field_info->m_c_type = message_field_info->m_pb_type = message_field_info->m_convert_type = "float";
            }
            else if (field_desc_proto.type() == ::google::protobuf::FieldDescriptorProto_Type_TYPE_INT64)
            {
                message_field_info->m_c_type = message_field_info->m_pb_type = message_field_info->m_convert_type = "int64_t";
            }
            else if (field_desc_proto.type() == ::google::protobuf::FieldDescriptorProto_Type_TYPE_UINT64)
            {
                message_field_info->m_c_type = message_field_info->m_pb_type = message_field_info->m_convert_type = "uint64_t";
            }
            else if (field_desc_proto.type() == ::google::protobuf::FieldDescriptorProto_Type_TYPE_INT32)
            {
                message_field_info->m_c_type = message_field_info->m_pb_type = message_field_info->m_convert_type = "int32_t";
            }
            else if (field_desc_proto.type() == ::google::protobuf::FieldDescriptorProto_Type_TYPE_UINT32)
            {
                message_field_info->m_c_type = message_field_info->m_pb_type = message_field_info->m_convert_type = "uint32_t";
            }
            else if (field_desc_proto.type() == ::google::protobuf::FieldDescriptorProto_Type_TYPE_BOOL)
            {
                message_field_info->m_c_type = message_field_info->m_pb_type = message_field_info->m_convert_type = "bool";
            }
            else if (field_desc_proto.type() == ::google::protobuf::FieldDescriptorProto_Type_TYPE_STRING)
            {
                message_field_info->m_c_type = "char";
                message_field_info->m_pb_type = "string";
                message_field_info->m_convert_type = "const char*";
                message_field_info->m_isBuffer = true;
                message_field_info->m_isString = true;
            }
            else if (field_desc_proto.type() == ::google::protobuf::FieldDescriptorProto_Type_TYPE_MESSAGE)
            {
                std::vector<std::string> vecTypeName;
                NFStringUtility::Split(field_desc_proto.type_name(), ".", &vecTypeName);
                CHECK_EXPR(vecTypeName.size() > 0, -1, "proto:{} message:{} field:{} type_name:{} is not support", m_protoName, message_info.m_name,
                           message_field_info->m_name, field_desc_proto.type_name());

                std::string type_name = vecTypeName.back();
                message_field_info->m_c_type = message_field_info->m_convert_type = "struct " + type_name + "_s";
                message_field_info->m_pb_type = "::" + m_fileDesc.m_namespace + "::" + type_name;
                message_field_info->m_isMessage = true;
            }
            else if (field_desc_proto.type() == ::google::protobuf::FieldDescriptorProto_Type_TYPE_BYTES)
            {
                message_field_info->m_c_type = "uint8_t";
                message_field_info->m_pb_type = "bytes";
                message_field_info->m_convert_type = "const void*";
                message_field_info->m_isBuffer = true;
            }
            else if (field_desc_proto.type() == ::google::protobuf::FieldDescriptorProto_Type_TYPE_ENUM)
            {
                std::vector<std::string> vecTypeName;
                NFStringUtility::Split(field_desc_proto.type_name(), ".", &vecTypeName);
                CHECK_EXPR(vecTypeName.size() > 0, -1, "proto:{} message:{} field:{} type_name:{} is not support", m_protoName, message_info.m_name,
                           message_field_info->m_name, field_desc_proto.type_name());

                std::string type_name = vecTypeName.back();
                message_field_info->m_c_type = message_field_info->m_pb_type = message_field_info->m_convert_type =
                        "::" + m_fileDesc.m_namespace + "::" + type_name;
                message_field_info->m_isEnum = true;
            }
            else
            {
                NFLogInfo(NF_LOG_SYSTEMLOG, 0, "proto:{} message:{} field:{} type_name:{} is not support", m_protoName, message_info.m_name,
                          message_field_info->m_name, field_desc_proto.type_name());
            }

            if (message_field_info->m_isBuffer)
            {
                message_field_info->m_bufferSize = field_options.GetExtension(yd_fieldoptions::field_bufsize);
                if (message_field_info->m_bufferSize == 0)
                {
                    message_field_info->m_bufferSize = 32;
                }
            }

            if (field_options.HasExtension(yd_fieldoptions::field_typename))
            {
                std::string special_name = field_options.GetExtension(yd_fieldoptions::field_typename);
                if (special_name.size() > 0)
                {
                    message_field_info->m_c_type = special_name;
                }
            }
        }
    }

    return 0;
}

int ExcelToStruct::WriteToStruct()
{
    WriteH();
    WriteCpp();
    return 0;
}

int ExcelToStruct::WriteH()
{
    std::string h_file;
    h_file += "#pragma once\n\n";

    h_file += "#include <stdint.h>\n";
    h_file += "#include <NFComm/NFShmStl/NFShmString.h>\n";
    h_file += "#include <NFComm/NFShmStl/NFShmVector.h>\n";
    h_file += "#include <NFComm/NFShmCore/NFSeqOP.h>\n";
    h_file += "#include <NFComm/NFShmCore/NFShmMgr.h>\n";
    for(int i = 0; i < (int)m_fileDesc.m_include_list.size(); i++)
    {
        h_file += "#include \"" + m_fileDesc.m_include_list[i] + "\"\n";
    }
    h_file += "\n";

    std::string line_struct = "";
    std::string define_max_num;
    line_struct += "namespace " + m_fileDesc.m_namespace + "_s {\n\n";

    for(int i = 0; i < (int)m_fileDesc.m_message_desc.size(); i++)
    {
        ProtoMessageDesc& message_desc = m_fileDesc.m_message_desc[i];
        if (message_desc.m_useStl)
        {
            line_struct += NF_FORMAT_FUNC("\tstruct {}_s ", message_desc.m_name);
        }
        else
        {
            line_struct += NF_FORMAT_FUNC("\tstruct {}_s : public NFDescStoreSeqOP ", message_desc.m_name);
        }

        line_struct += "{\n";

        line_struct += NF_FORMAT_FUNC("\t\t{}_s();\n", message_desc.m_name);
        line_struct += NF_FORMAT_FUNC("\t\tvirtual ~{}_s()", message_desc.m_name);
        line_struct += "{}\n";
        line_struct += "\t\tint CreateInit();\n";
        line_struct += "\t\tint ResumeInit();\n";

        for(int j = 0; j < (int)message_desc.m_fieldList.size(); j++)
        {
            ProtoMessageFieldDesc& msg_field = message_desc.m_fieldList[j];
            std::string line = "";

            if (msg_field.m_noField)
            {
                continue;
            }

            std::string define_max = NF_FORMAT_FUNC("DEFINE_{}_MAX_NUM" , NFStringUtility::Upper(message_desc.m_name) + "_" + NFStringUtility::Upper(msg_field.m_name));

            if (msg_field.m_isArray || msg_field.m_isBuffer)
            {
                if (msg_field.m_isArray == true && msg_field.m_isBuffer == false)
                {
                    if (message_desc.m_useStl)
                    {
                        line += NF_FORMAT_FUNC("\t\tstd::vector<{}> {}", msg_field.m_c_type,  msg_field.m_name);
                        line += ";\n";
                    }
                    else
                    {
                        define_max_num += NF_FORMAT_FUNC("#define {} {}\n", define_max,  msg_field.m_arraySize);
                        line += NF_FORMAT_FUNC("\t\tNFShmVector<{}, {}> {}", msg_field.m_c_type, define_max,  msg_field.m_name);
                        line += ";\n";
                    }
                }
                else if (msg_field.m_isArray == false && msg_field.m_isBuffer == true)
                {
                    if (message_desc.m_useStl)
                    {
                        line += NF_FORMAT_FUNC("\t\tstd::string {}", msg_field.m_name);
                        line += ";\n";
                    }
                    else {
                        line += NF_FORMAT_FUNC("\t\tNFShmString<{}> {}", msg_field.m_bufferSize, msg_field.m_name);
                        line += ";\n";
                    }
                }
                else if (msg_field.m_isArray == true && msg_field.m_isBuffer == true)
                {
                    if (message_desc.m_useStl)
                    {
                        line += NF_FORMAT_FUNC("\t\tstd::vector<std::string> {}", msg_field.m_name);
                        line += ";\n";
                    }
                    else {
                        define_max_num += NF_FORMAT_FUNC("#define {} {}\n", define_max,  msg_field.m_arraySize);
                        line += NF_FORMAT_FUNC("\t\tNFShmVector<NFShmString<{}>, {}> {}", msg_field.m_bufferSize,  define_max, msg_field.m_name);
                        line += ";\n";
                    }
                }
            }
            else {
                line += NF_FORMAT_FUNC("\t\t{} {}", msg_field.m_c_type, msg_field.m_name);
                line += ";\n";
            }

            line_struct += line;
        }

        line_struct += "\n";
        message_desc.m_func_write_to_pbmsg = NF_FORMAT_FUNC("write_to_pbmsg({} & msg) const", message_desc.m_pb_msgname);
        message_desc.m_func_read_from_pbmsg = NF_FORMAT_FUNC("read_from_pbmsg(const {} & msg)", message_desc.m_pb_msgname);
        message_desc.m_func_new_proto = "new_pbmsg()";
        message_desc.m_func_make_proto = "make_pbmsg()";

        line_struct += NF_FORMAT_FUNC("\t\tvirtual void {};\n", message_desc.m_func_write_to_pbmsg);
        line_struct += NF_FORMAT_FUNC("\t\tvirtual void {};\n", message_desc.m_func_read_from_pbmsg);
        line_struct += NF_FORMAT_FUNC("\t\tstatic {}* {}", message_desc.m_pb_msgname, message_desc.m_func_new_proto);
        line_struct += "{";
        line_struct += NF_FORMAT_FUNC(" return new {}(); ", message_desc.m_pb_msgname);
        line_struct += "}\n";
        line_struct += NF_FORMAT_FUNC("\t\tstatic {} {}", message_desc.m_pb_msgname, message_desc.m_func_make_proto);
        line_struct += "{";
        line_struct += NF_FORMAT_FUNC(" return {}(); ", message_desc.m_pb_msgname);
        line_struct += "}\n";
        line_struct += "\t};\n";
        line_struct += NF_FORMAT_FUNC("\ttypedef struct {}_s {}_t;\n\n", message_desc.m_name, message_desc.m_name);
    }

    line_struct += "}\n\n";

    h_file += define_max_num;
    h_file += "\n\n";
    h_file += line_struct;

    NFFileUtility::WriteFile(m_outPath + m_protoName + "_s.h", h_file);
    return 0;
}

int ExcelToStruct::WriteCpp()
{
    std::string cpp_file;

    cpp_file += NF_FORMAT("#include \"{}_s.h\"\n\n", m_protoName);
    cpp_file += NF_FORMAT("namespace {}_s ", m_fileDesc.m_namespace);
    cpp_file += "{\n\n";

    for(int i = 0; i < (int)m_fileDesc.m_message_desc.size(); i++)
    {
        ProtoMessageDesc &message_desc = m_fileDesc.m_message_desc[i];
        cpp_file += NF_FORMAT_FUNC("{}_s::{}_s() ", message_desc.m_name, message_desc.m_name);
        cpp_file += "{\n";
        if (message_desc.m_useStl)
        {
            cpp_file += "\tCreateInit();\n";
        }
        else
        {
            cpp_file += "\tif (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {\n";
            cpp_file += "\t\tCreateInit();\n";
            cpp_file += "\t} else {\n";
            cpp_file += "\t\tResumeInit();\n";
            cpp_file += "\t}\n";
        }

        cpp_file += "}\n\n";

        cpp_file += NF_FORMAT_FUNC("int {}_s::CreateInit() ", message_desc.m_name);
        cpp_file += "{\n";

        for(int j = 0; j < (int)message_desc.m_fieldList.size(); j++)
        {
            ProtoMessageFieldDesc &msg_field = message_desc.m_fieldList[j];
            std::string line = "";

            if (msg_field.m_noField)
            {
                continue;
            }

            if (!msg_field.m_isArray && !msg_field.m_isBuffer && !msg_field.m_isString && !msg_field.m_isMessage)
            {
                cpp_file += NF_FORMAT_FUNC("\t{} = ({})0;\n", msg_field.m_name, msg_field.m_convert_type);
            }
        }

        cpp_file += "\treturn 0;\n";
        cpp_file += "}\n\n";

        cpp_file += NF_FORMAT_FUNC("int {}_s::ResumeInit() ", message_desc.m_name);
        cpp_file += "{\n";
        cpp_file += "\treturn 0;\n";
        cpp_file += "}\n\n";

        cpp_file += NF_FORMAT_FUNC("void {}_s::{} ", message_desc.m_name, message_desc.m_func_write_to_pbmsg);
        cpp_file += "{\n";

        for(int j = 0; j < (int)message_desc.m_fieldList.size(); j++)
        {
            ProtoMessageFieldDesc &msg_field = message_desc.m_fieldList[j];
            std::string line = "";

            if (msg_field.m_noField)
            {
                continue;
            }

            if (msg_field.m_isArray)
            {
                cpp_file += NF_FORMAT_FUNC("\tfor(int32_t i = 0; i < (int32_t){}.size(); ++i) ", msg_field.m_name);
                cpp_file += "{\n";

                if (msg_field.m_isString || msg_field.m_isBuffer)
                {
                    cpp_file += NF_FORMAT_FUNC("\t\tmsg.add_{}({}[i].data());\n", NFStringUtility::Lower(msg_field.m_name), msg_field.m_name);
                }
                else if (msg_field.m_isMessage)
                {
                    cpp_file += NF_FORMAT_FUNC("\t\t{}* temp_{} = msg.add_{}();\n", msg_field.m_pb_type, NFStringUtility::Lower(msg_field.m_name), NFStringUtility::Lower(msg_field.m_name));
                    cpp_file += NF_FORMAT_FUNC("\t\t{}[i].write_to_pbmsg(*temp_{});\n", msg_field.m_name, NFStringUtility::Lower(msg_field.m_name));
                }
                else {
                    cpp_file += NF_FORMAT_FUNC("\t\tmsg.add_{}(({}){}[i]);\n", NFStringUtility::Lower(msg_field.m_name), msg_field.m_convert_type, msg_field.m_name);
                }
                cpp_file += "\t}\n";
            }
            else {
                if (msg_field.m_isString || msg_field.m_isBuffer)
                {
                    cpp_file += NF_FORMAT_FUNC("\tmsg.set_{}({}.data());\n", NFStringUtility::Lower(msg_field.m_name), msg_field.m_name);
                }
                else if (msg_field.m_isMessage)
                {
                    cpp_file += NF_FORMAT_FUNC("\t{}* temp_{} = msg.mutable_{}();\n", msg_field.m_pb_type, NFStringUtility::Lower(msg_field.m_name), NFStringUtility::Lower(msg_field.m_name));
                    cpp_file += NF_FORMAT_FUNC("\t{}.write_to_pbmsg(*temp_{});\n", msg_field.m_name, NFStringUtility::Lower(msg_field.m_name));
                }
                else {
                    cpp_file += NF_FORMAT_FUNC("\tmsg.set_{}(({}){});\n", NFStringUtility::Lower(msg_field.m_name), msg_field.m_convert_type, msg_field.m_name);
                }
            }
        }

        cpp_file += "}\n\n";

        cpp_file += NF_FORMAT_FUNC("void {}_s::{} ", message_desc.m_name, message_desc.m_func_read_from_pbmsg);
        cpp_file += "{\n";
        for(int j = 0; j < (int)message_desc.m_fieldList.size(); j++)
        {
            ProtoMessageFieldDesc &msg_field = message_desc.m_fieldList[j];
            std::string line = "";

            if (msg_field.m_noField)
            {
                continue;
            }

            if (msg_field.m_isArray)
            {
                if (message_desc.m_useStl)
                {
                    cpp_file += NF_FORMAT_FUNC("\t{}.resize(msg.{}_size());\n", msg_field.m_name, NFStringUtility::Lower(msg_field.m_name));
                    cpp_file += NF_FORMAT_FUNC("\tfor(int32_t i = 0; i < (int32_t){}.size(); ++i) ", msg_field.m_name);
                    cpp_file += "{\n";
                }
                else {
                    cpp_file += NF_FORMAT_FUNC("\t{}.resize((int)msg.{}_size() > (int){}.max_size() ? {}.max_size() : msg.{}_size());\n", msg_field.m_name, NFStringUtility::Lower(msg_field.m_name), msg_field.m_name,  msg_field.m_name, NFStringUtility::Lower(msg_field.m_name));
                    cpp_file += NF_FORMAT_FUNC("\tfor(int32_t i = 0; i < (int32_t){}.size(); ++i) ", msg_field.m_name);
                    cpp_file += "{\n";
                }

                if (msg_field.m_isString || msg_field.m_isBuffer)
                {
                    cpp_file += NF_FORMAT_FUNC("\t\t{}[i] = msg.{}(i);\n", msg_field.m_name, NFStringUtility::Lower(msg_field.m_name));
                }
                else if (msg_field.m_isMessage)
                {
                    cpp_file += NF_FORMAT_FUNC("\t\tconst {} & temp_{} = msg.{}(i);\n", msg_field.m_pb_type, NFStringUtility::Lower(msg_field.m_name), NFStringUtility::Lower(msg_field.m_name));
                    cpp_file += NF_FORMAT_FUNC("\t\t{}[i].read_from_pbmsg(temp_{});\n", msg_field.m_name, NFStringUtility::Lower(msg_field.m_name));
                }
                else {
                    cpp_file += NF_FORMAT_FUNC("\t\t{}[i] = msg.{}(i);\n", msg_field.m_name, NFStringUtility::Lower(msg_field.m_name));
                }

                cpp_file += "\t}\n";
            }
            else {
                if (msg_field.m_isString || msg_field.m_isBuffer)
                {
                    cpp_file += NF_FORMAT_FUNC("\t{} = msg.{}();\n", msg_field.m_name, NFStringUtility::Lower(msg_field.m_name));
                }
                else if (msg_field.m_isMessage)
                {
                    cpp_file += NF_FORMAT_FUNC("\tconst {} & temp_{} = msg.{}();\n", msg_field.m_pb_type, NFStringUtility::Lower(msg_field.m_name), NFStringUtility::Lower(msg_field.m_name));
                    cpp_file += NF_FORMAT_FUNC("\t{}.read_from_pbmsg(temp_{});\n", msg_field.m_name, NFStringUtility::Lower(msg_field.m_name));
                }
                else {
                    cpp_file += NF_FORMAT_FUNC("\t{} = msg.{}();\n", msg_field.m_name, NFStringUtility::Lower(msg_field.m_name));
                }
            }
        }

        cpp_file += "}\n\n";
    }

    cpp_file += "}\n";

    NFFileUtility::WriteFile(m_outPath + m_protoName + "_s.cpp", cpp_file);
    return 0;
}

