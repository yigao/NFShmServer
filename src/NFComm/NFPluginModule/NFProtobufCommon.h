// -------------------------------------------------------------------------
//    @FileName         :    NFProtobufCommon.h
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFProtobufCommon
//
// -------------------------------------------------------------------------
#pragma once

#include "NFComm/NFCore/NFPlatform.h"
#include "google/protobuf/message.h"
#include "NFComm/NFCore/NFPlatform.h"
#include "NFComm/NFCore/NFCommon.h"
#include "NFComm/NFCore/NFSingleton.hpp"
#include "NFComm/NFCore/NFFileUtility.h"
#include "NFComm/NFPluginModule/NFLogMgr.h"
#include "NFIHttpHandle.h"

class _NFExport NFProtobufCommon : public NFSingleton<NFProtobufCommon> {
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

    static int IniToProtoMessage(const std::string &iniFile, google::protobuf::Message *pMessage);

    static int IniToProtoMessage(const std::string &iniFile, google::protobuf::Message *pMessage,
                                  const std::string& section);

    // 读取算法配置文件模板函数
    template<typename Proto_S>
    static int IniToProtoSturct(Proto_S &proto_s, const std::string &szFilePathName, bool moreSection = false) {
        auto proto_msg = Proto_S::make_pbmsg();

        if (NFFileUtility::IsFileExist(szFilePathName) == false) {
            NFLogError(NF_LOG_SYSTEMLOG, 0, "file:{} not exist", szFilePathName);
            return -1;
        }

        if (moreSection)
        {
            if (NFProtobufCommon::IniToProtoMessage(szFilePathName, &proto_msg) != 0) {
                NFLogError(NF_LOG_SYSTEMLOG, 0, "Ini To Message Failed!, file:{}", szFilePathName);
                return -1;
            }
        }
        else
        {
            if (NFProtobufCommon::IniToProtoMessage(szFilePathName, &proto_msg, "") != 0) {
                NFLogError(NF_LOG_SYSTEMLOG, 0, "Ini To Message Failed!, file:{}", szFilePathName);
                return -1;
            }
        }

        Proto_S::read_from_pbmsg(proto_msg, proto_s);

        return 0;
    }

    static int CopyMessageByFields(google::protobuf::Message *pSrcMessage, const google::protobuf::Message *pDescMessage);

    static int GetMessageFromGetHttp(google::protobuf::Message *pSrcMessage, const NFIHttpHandle &req);
};



