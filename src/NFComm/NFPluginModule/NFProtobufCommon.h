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
#include <vector>
#include <map>

class _NFExport NFProtobufCommon {
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
};



