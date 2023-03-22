// -------------------------------------------------------------------------
//    @FileName         :    NFProtobufCommon.h
//    @Author           :    Gao.Yi
//    @Date             :   2022-09-18
//    @Email			:    445267987@qq.com
//    @Module           :    NFProtobufCommon
//
// -------------------------------------------------------------------------
#pragma once

#include "NFComm/NFCore/NFPlatform.h"
#include "google/protobuf/message.h"
#include "NFComm/NFCore/NFFileUtility.h"
#include "NFIHttpHandle.h"
#include "NFComm/NFPluginModule/NFILuaLoader.h"
#include "NFComm/NFCore/NFSingleton.hpp"
#include "google/protobuf/dynamic_message.h"
#include "NFComm/NFCore/NFMutex.h"
#include <vector>
#include <map>

#define DEFINE_DEFAULT_PROTO_PACKAGE "proto_ff"
#define DEFINE_DEFAULT_PROTO_PACKAGE_ADD "proto_ff."

struct DBTableColInfo
{
    DBTableColInfo()
    {
        m_colType = 0;
        m_primaryKey = false;
        m_unionKey = false;
        m_indexKey = false;
        m_bufsize = 32;
        m_fieldIndex = 0;
        m_autoIncrement = false;
        m_autoIncrementValue = 0;
        m_defaultValue = 0;
        m_isDefaultValue = false;
    }

    uint32_t m_colType;
    bool m_primaryKey;
    bool m_unionKey;
    bool m_indexKey;
    bool m_autoIncrement;
    bool m_notNull;
    bool m_isDefaultValue;
    uint32_t m_defaultValue;
    int64_t m_autoIncrementValue;
    uint32_t m_bufsize;
    uint32_t m_fieldIndex;
    std::string m_comment;
};

class _NFExport NFProtobufCommon : public NFSingleton<NFProtobufCommon>
{
public:
    static std::string
    GetFieldsString(const google::protobuf::Message &message, const google::protobuf::FieldDescriptor *pFieldDesc);

    static std::string GetRepeatedFieldsString(const google::protobuf::Message &message,
                                               const google::protobuf::FieldDescriptor *pFieldDesc, int index);

    static void SetFieldsString(google::protobuf::Message &message, const google::protobuf::FieldDescriptor *pFieldDesc,
                                const std::string &strValue);

    static void AddFieldsString(google::protobuf::Message &message, const google::protobuf::FieldDescriptor *pFieldDesc,
                                const std::string &strValue);

    /*
    ** 通过在Protobuf里的message名字创建出一个默认的此类的变量
    */
    static const ::google::protobuf::Message *FindMessageTypeByName(const std::string &full_name);

    /*
    ** 通过在Protobuf里的message名字创建出一个Message
    */
    static ::google::protobuf::Message *CreateMessageByName(const std::string &full_name);

    static void
    GetMapFieldsFromMessage(const google::protobuf::Message &message, std::map<std::string, std::string> &mapFileds,
                            bool ignore_special_repeted = true, bool primary_ikey = false);

    static void
    GetMapFieldsFromMessage(const google::protobuf::Message &message, std::map<std::string, std::string> &keyMap,
                            std::map<std::string, std::string> &kevValueMap, bool ignore_special_repeted = true);

    static void GetMessageFromMapFields(const std::map<std::string, std::string> &result,
                                        google::protobuf::Message *pMessageObject);

    static int GetMapFieldsStringFromMessage(const google::protobuf::Message &message, std::string &msg);

    static bool ProtoMessageToXml(const google::protobuf::Message &message,
                                  std::string *json);

    static bool XmlToProtoMessage(const std::string &json,
                                  google::protobuf::Message *message);

    static bool ProtoMessageToJson(const google::protobuf::Message &message,
                                   std::string *json,
                                   std::string *error = NULL);

    static bool ProtoMessageToJson(const google::protobuf::Message &message,
                                   google::protobuf::io::ZeroCopyOutputStream *json,
                                   std::string *error = NULL);

    static bool JsonToProtoMessage(const std::string &json,
                                   google::protobuf::Message *message,
                                   std::string *error = NULL);

    static bool JsonToProtoMessage(google::protobuf::io::ZeroCopyInputStream *stream,
                                   google::protobuf::Message *message,
                                   std::string *error = NULL);

    static bool LuaToProtoMessage(NFLuaRef luaRef, google::protobuf::Message *pMessageObject);

    static int CopyMessageByFields(google::protobuf::Message *pSrcMessage, const google::protobuf::Message *pDescMessage);

    static int GetMessageFromGetHttp(google::protobuf::Message *pSrcMessage, const NFIHttpHandle &req);

    /**
     * @brief 通过message的protobuf反射， 查找出数据库表的列信息
     * @param message
     * @param privaryKeyMap
     * @param IndexMap
     * @param mapFileds
     */
    static int GetDbFieldsInfoFromMessage(const google::protobuf::Descriptor *pDesc, std::map<std::string, DBTableColInfo> &primaryKeyMap, std::map<std::string, DBTableColInfo> &mapFileds);

    static uint32_t GetPBDataTypeFromDBDataType(const std::string& dbDataType, const std::string& strColumnType);
    static std::string GetDBDataTypeFromPBDataType(uint32_t pbDataType, uint32_t textMax);
public:
    NFProtobufCommon();

    virtual ~NFProtobufCommon();

public:
    /**
     * @brief 加载pb文件 protoc 通过--descriptor_set_out生存的文件
     * @param ds
     * @return
     */
    int LoadProtoDsFile(const std::string &ds);

    /**
     * @brief
     * @param full_name
     * @return
     */
    const google::protobuf::Descriptor *FindDynamicMessageTypeByName(const std::string &full_name);

    /*
    ** 通过在Protobuf里的message名字创建出一个Message
    */
    ::google::protobuf::Message *CreateDynamicMessageByName(const std::string &full_name);

private:
    google::protobuf::DescriptorPool *m_pDescriptorPool;
    google::protobuf::DynamicMessageFactory *m_pDynamicMessageFactory;
};

