// -------------------------------------------------------------------------
//    @FileName         :    NFProtobufMessageCodec.h
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFProtobufMessageCodec.h
//
// -------------------------------------------------------------------------

#pragma once

#include <string>
#include <google/protobuf/message.h>
#include "NFProtoDefine.h"

class NFProtobufMessageCodec {
public:
    virtual ~NFProtobufMessageCodec() {};

    virtual bool ToString(const google::protobuf::Message &msg,
                          std::string &output) = 0;

    virtual bool FromString(const std::string &input,
                            google::protobuf::Message &msg) = 0;

    virtual bool CompactAndCheckString(const std::string &json,
                                       std::string &result) = 0;

    virtual bool PrettyString(const std::string &json,
                              std::string &result) = 0;

    virtual void TemplateString(const google::protobuf::Message &msg,
                                std::string &result) = 0;

protected:
    // set default value for message
    void FillDefaultValue(google::protobuf::Message* message);

    bool FillFieldValue(google::protobuf::Message *message,
                        const google::protobuf::FieldDescriptor* fieldDesc,
                        const google::protobuf::Reflection* reflection);

};