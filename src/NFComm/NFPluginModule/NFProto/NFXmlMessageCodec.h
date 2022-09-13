// -------------------------------------------------------------------------
//    @FileName         :    NFXmlMessageCodec.h
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFXmlMessageCodec.h
//
// -------------------------------------------------------------------------

#pragma once

#include "NFProtobufMessageCodec.h"

struct NFXmlTokenReader;

class NFXmlMessageCodec : public NFProtobufMessageCodec {
public:
    NFXmlMessageCodec();
    virtual ~NFXmlMessageCodec();

    virtual bool ToString(const google::protobuf::Message &msg,
                          std::string &output);

    virtual bool FromString(const std::string &input,
                            google::protobuf::Message &msg);

    virtual bool CompactAndCheckString(const std::string &text,
                                       std::string &result);

    virtual bool PrettyString(const std::string &text,
                              std::string &result);

    virtual void TemplateString(const google::protobuf::Message &msg,
                                std::string &result);

protected:
    virtual void ToXmlString(const google::protobuf::Message &message,
                             std::ostringstream &out);

    virtual void FieldToXmlString(const google::protobuf::Message &message,
                                  const google::protobuf::FieldDescriptor *field_descriptor,
                                  const google::protobuf::Reflection* reflection,
                                  std::ostringstream &out);

    virtual bool FromXmlObject(NFXmlTokenReader &tkReader,
                               google::protobuf::Message *message,
                               const std::string &name);

    virtual bool FillFieldValue(NFXmlTokenReader &tkReader,
                                const google::protobuf::FieldDescriptor* field_descriptor,
                                const google::protobuf::Reflection* reflection,
                                google::protobuf::Message *message);
};
