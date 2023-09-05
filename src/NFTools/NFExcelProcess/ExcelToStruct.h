// -------------------------------------------------------------------------
//    @FileName         :    ExcelToStruct.h
//    @Author           :    gaoyi
//    @Date             :    23-9-4
//    @Email			:    445267987@qq.com
//    @Module           :    ExcelToStruct
//
// -------------------------------------------------------------------------

#pragma once

#include <unordered_map>
#include "NFComm/NFCore/NFPlatform.h"
#include "NFComm/NFCore/NFSingleton.hpp"
#include "google/protobuf/descriptor.pb.h"

struct ProtoMessageFieldDesc
{
    ProtoMessageFieldDesc()
    {
        m_isArray = false;
        m_isBuffer = false;
        m_isString = false;
        m_isEnum = false;
        m_isMessage = false;
        m_noField = false;
        m_arraySize = 0;
        m_bufferSize = 0;
    }
    std::string m_name;
    std::string m_c_type;
    std::string m_pb_type;
    std::string m_convert_type;
    bool m_isArray;
    uint32_t m_arraySize;
    bool m_isBuffer;
    bool m_isString;
    uint32_t m_bufferSize;
    bool m_isEnum;
    bool m_isMessage;
    bool m_noField;
};

struct ProtoMessageDesc
{
    ProtoMessageDesc()
    {
        m_useStl = false;
    }

    std::string m_name;
    std::string m_pb_msgname;
    std::vector<ProtoMessageFieldDesc> m_fieldList;
    bool m_useStl;
    std::string m_func_write_to_pbmsg;
    std::string m_func_read_from_pbmsg;
    std::string m_func_new_proto;
    std::string m_func_make_proto;
};

struct ProtoFileDesc
{
    std::vector<std::string> m_include_list;
    std::string m_namespace;
    std::vector<ProtoMessageDesc> m_message_desc;
};

class ExcelToStruct : public NFSingleton<ExcelToStruct>
{
public:
    ExcelToStruct();

    virtual ~ExcelToStruct();
public:
    virtual int Init(const std::string& protoName, const std::string& outPath, const std::string& proto_ds);
    virtual int ParseProto();
    virtual int ParseProto(const ::google::protobuf::FileDescriptorProto& fileProto);
public:
    int WriteToStruct();
    int WriteH();
    int WriteCpp();
public:
    std::string m_protoFileName;
    std::string m_protoName;
    std::string m_outPath;
    std::string m_proto_ds;
public:
    google::protobuf::FileDescriptorSet m_file_descriptor_set;
    ProtoFileDesc m_fileDesc;
};