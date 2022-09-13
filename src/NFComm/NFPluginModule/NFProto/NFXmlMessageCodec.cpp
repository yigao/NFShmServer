// -------------------------------------------------------------------------
//    @FileName         :    NFXmlMessageCodec.cpp
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFXmlMessageCodec.cpp
//
// -------------------------------------------------------------------------

#include "NFXmlMessageCodec.h"

#include <sstream>
#include <cstring>
#include <stack>
#include <google/protobuf/descriptor.h>
#include <NFComm/NFCore/NFCommon.h>
#include "NFComm/NFPluginModule/NFCheck.h"
#include "NFComm/NFCore/NFStringUtility.h"

#ifdef GetMessage
#undef GetMessage
#endif

#define XML_GET(reflection, message, descriptor, TYPE, out) \
do {\
  const string &field_name = descriptor->name();\
  if (descriptor->label() == FieldDescriptor::LABEL_REPEATED) {\
    out << "<" << field_name << "s>";\
    int size = reflection->FieldSize(message, descriptor);\
    int i = 0; \
    for (; i< size - 1; ++i) {\
      out << "<" << field_name << ">";\
      out << reflection->GetRepeated##TYPE (message, descriptor, i); \
      out << "</" << field_name << ">";\
    }\
    if ( i == size - 1) {\
      out << "<" << field_name << ">";\
      out << reflection->GetRepeated##TYPE (message, descriptor, i); \
      out << "</" << field_name << ">";\
    }\
    out << "</" << field_name << "s>";\
  } else {\
    out << "<" << field_name << ">";\
    out << reflection->Get##TYPE (message, descriptor);\
    out << "</" << field_name << ">";\
  }\
} while (0)

#define XML_SET_INTERGER(reflection, message, descriptor, TYPE, CASTTYPE, CVTF, tkReader) \
do {\
  Token tok;\
  if (field_descriptor->label() == FieldDescriptor::LABEL_REPEATED) {\
    do {\
      NFTokenType type = tkReader.NextToken(tok);\
      if (type != T_BEGIN_ELEMENT) {\
        if (type == T_AFTER_ELEMENT && field_name == string(tok.base, tok.len)){\
          break;\
        }\
        NFLogError(NF_LOG_SYSTEMLOG, 0, "xml数据错误，不是一个有效的常量:type:{} {}", type, tok.base);\
        return false;\
      }\
      if ( field_name.find(string(tok.base, tok.len)) == string::npos ) { \
        NFLogError(NF_LOG_SYSTEMLOG, 0, "xml数据错误，不是一个有效的数组元素:type:{} {}", type, tok.base);\
        return false; \
      }\
      type = tkReader.NextToken(tok);\
      if (type != T_CONSTANTS) {\
        NFLogError(NF_LOG_SYSTEMLOG, 0, "xml数据错误，不是一个有效的常量:type:{} {}", type, tok.base);\
        return false;\
      }\
      char *endptr = NULL;\
      CASTTYPE to_value = CVTF(tok.base, &endptr, 10);\
      reflection->Add##TYPE(message, descriptor, to_value);\
      type = tkReader.NextToken(tok);\
      if (type != T_AFTER_ELEMENT || field_name.find(string(tok.base, tok.len)) == string::npos) {\
        NFLogError(NF_LOG_SYSTEMLOG, 0, "xml数据错误，不是一个有效的常量:type:{} {}", type, tok.base);\
        return false;\
      }\
    } while (true);\
  } else {\
    NFTokenType type = tkReader.NextToken(tok);\
    if (type != T_CONSTANTS) {\
      NFLogError(NF_LOG_SYSTEMLOG, 0, "xml数据错误，不是一个有效的常量:type:{} {}", type, tok.base);\
      return false;\
    }\
    char *endptr = NULL;\
    CASTTYPE to_value = CVTF(tok.base, &endptr, 10);\
    reflection->Set##TYPE(message, field_descriptor, to_value);\
    type = tkReader.NextToken(tok);\
    if (type != T_AFTER_ELEMENT) {\
      NFLogError(NF_LOG_SYSTEMLOG, 0, "xml数据错误，不是一个有效的常量:type:{} {}", type, tok.base);\
      return false;\
    }\
  }\
} while (0)

#define XML_SET_FLOAT(reflection, message, descriptor, TYPE, CASTTYPE, CVTF, tkReader) \
do {\
  Token tok;\
  if (field_descriptor->label() == FieldDescriptor::LABEL_REPEATED) {\
    do {\
      NFTokenType type = tkReader.NextToken(tok);\
      if (type != T_BEGIN_ELEMENT) {\
        if (type == T_AFTER_ELEMENT && field_name == string(tok.base, tok.len - 1)) {\
          break;\
        }\
        NFLogError(NF_LOG_SYSTEMLOG, 0, "xml数据错误，不是一个有效的常量:type:{} {}", type, tok.base);\
        return false;\
      }\
      if ( field_name.find(string(tok.base, tok.len)) == string::npos ) { \
        NFLogError(NF_LOG_SYSTEMLOG, 0, "xml数据错误，不是一个有效的数组元素:type:{} {}", type, tok.base);\
        return false; \
      }\
      type = tkReader.NextToken(tok);\
      if (type != T_CONSTANTS) {\
        NFLogError(NF_LOG_SYSTEMLOG, 0, "xml数据错误，不是一个有效的常量:type:{} {}", type, tok.base);\
        return false;\
      }\
      char *endptr = NULL;\
      CASTTYPE to_value = CVTF(tok.base, &endptr);\
      reflection->Add##TYPE(message, descriptor, to_value);\
      type = tkReader.NextToken(tok);\
      if (type != T_AFTER_ELEMENT || field_name.find(string(tok.base, tok.len)) == string::npos) {\
        NFLogError(NF_LOG_SYSTEMLOG, 0, "xml数据错误，不是一个有效的常量:type:{} {}", type, tok.base);\
        return false;\
      }\
    } while (true);\
  } else {\
    NFTokenType type = tkReader.NextToken(tok);\
    if (type != T_CONSTANTS) {\
      NFLogError(NF_LOG_SYSTEMLOG, 0, "xml数据错误，不是一个有效的常量:type:{} {}", type, tok.base);\
      return false;\
    }\
    char *endptr = NULL;\
    CASTTYPE to_value = CVTF(tok.base, &endptr);\
    reflection->Set##TYPE(message, field_descriptor, to_value);\
    type = tkReader.NextToken(tok);\
    if (type != T_AFTER_ELEMENT) {\
      NFLogError(NF_LOG_SYSTEMLOG, 0, "xml数据错误，不是一个有效的常量:type:{} {}", type, tok.base);\
      return false;\
    }\
  }\
} while (0)

using namespace std;  // NOLINT
using namespace google::protobuf;  // NOLINT

enum NFTokenType {
    T_END, T_ERROR, T_STRING, T_CONSTANTS, T_BEGIN_ELEMENT, T_AFTER_ELEMENT
};

struct Token {
    Token() : base(NULL), len(0) {
    }

    ~Token() {
    }

    void reset(char *base, int len) {
        this->base = base;
        this->len = len;
    }

    const char *base;
    int len;
};

struct NFXmlTokenReader {
    NFXmlTokenReader(const char *data, int size) :
            data_ptr_(data),size_(size), idx_(0) {
    }

    inline NFTokenType NextToken(Token &tok) {
        int i = idx_;
        int size =size_;
        NFTokenType type = T_END;
        while (i < size) {
            char ch = data_ptr_[i++];
            switch (ch) {
                case ' ':
                case '\t':
                case '\r':
                case '\n': {
                    break;
                }
                case '<': {
                    type = T_BEGIN_ELEMENT;
                    if (data_ptr_[i] == '/') {
                        type = T_AFTER_ELEMENT;
                        i++;
                    }
                    tok.base = &data_ptr_[i];
                    while (LABEL_CHARS[static_cast<uint8_t>(data_ptr_[i])]) {
                        i++;
                    }
                    if (data_ptr_[i] != '>') {
                        NFLogError(NF_LOG_SYSTEMLOG, 0, "数据错误，不是一个有效的element:{}", tok.base);
                        type = T_ERROR;
                        goto out;
                    }
                    tok.len = &data_ptr_[i] - tok.base;
                    i++; //skip '>'
                    goto out;
                }
                case '\'':
                case '\"': {
                    type = T_STRING;
                    char expect = ch;
                    tok.base = &data_ptr_[i];
                    while (i < size) {
                        if (data_ptr_[i] == expect && data_ptr_[i - 1] != '\\') {
                            //end string
                            tok.len = &data_ptr_[i] - tok.base;
                            i++;
                            goto out;
                        }
                        ++i;
                    }
                    type = T_ERROR;
                    NFLogError(NF_LOG_SYSTEMLOG, 0, "数据错误，不是一个有效的字符串:{}", tok.base);
                    goto out;
                }
                default: {
                    type = T_CONSTANTS;
                    tok.base = &data_ptr_[i - 1];
                    while (LABEL_CHARS[static_cast<uint8_t>(data_ptr_[i])]
                           || data_ptr_[i] == '.') {
                        i++;
                    }
                    if (data_ptr_[i] != '<'
                        && data_ptr_[i] != ' '
                        && data_ptr_[i] != '\t'
                        && data_ptr_[i] != '\n'
                        && data_ptr_[i] != '\r') {
                        NFLogError(NF_LOG_SYSTEMLOG, 0, "数据错误，不是一个有效的element:{}", tok.base);
                        type = T_ERROR;
                        goto out;
                    }
                    tok.len = &data_ptr_[i] - tok.base;
                    goto out;
                }

            }
        }
        out:
        idx_ = i;
        return type;
    }

private:
    const char *data_ptr_;
    int size_;
    int idx_;
};

NFXmlMessageCodec::NFXmlMessageCodec() {}

NFXmlMessageCodec::~NFXmlMessageCodec() {}

bool NFXmlMessageCodec::ToString(const google::protobuf::Message &message,
                                 std::string &result) {
    std::ostringstream out;
    const Descriptor* descriptor = message.GetDescriptor();
    out << "<" << descriptor->name() << ">";
    ToXmlString(message, out);
    out << "</" << descriptor->name() << ">";
    result.assign(out.str());
    return true;
}

void NFXmlMessageCodec::TemplateString(const google::protobuf::Message &msg,
                                       std::string &result){
    google::protobuf::Message * tmp = msg.New();
    if (tmp) {
        FillDefaultValue(tmp);
        ToString(*tmp, result);
        delete tmp;
    }
}

void NFXmlMessageCodec::ToXmlString(const google::protobuf::Message &message,
                                    std::ostringstream &out) {
    const Reflection* reflection = message.GetReflection();
    const Descriptor* descriptor = message.GetDescriptor();
    int field_count = descriptor->field_count();
    int i = 0;
    for (; i < field_count - 1; ++i) {
        FieldToXmlString(message, descriptor->field(i), reflection, out);
    }
    if (i == field_count - 1) {
        FieldToXmlString(message, descriptor->field(i), reflection, out);
    }
}

void NFXmlMessageCodec::FieldToXmlString(const Message &message,
                                         const FieldDescriptor *field_descriptor,
                                         const Reflection* reflection,
                                         std::ostringstream &out) {
    if ((field_descriptor->label() == FieldDescriptor::LABEL_REPEATED)) {
        if (reflection->FieldSize(message, field_descriptor) == 0) {
            return;
        }
    } else if ( ! reflection->HasField(message, field_descriptor)) {
        return;
    }

    switch (field_descriptor->type()) {
        case FieldDescriptor::TYPE_SFIXED64:
        case FieldDescriptor::TYPE_INT64:
            XML_GET(reflection, message, field_descriptor, Int64, out);
            break;
        case FieldDescriptor::TYPE_UINT64:
        case FieldDescriptor::TYPE_FIXED64:
            XML_GET(reflection, message, field_descriptor, UInt64, out);
            break;
        case FieldDescriptor::TYPE_SFIXED32:
        case FieldDescriptor::TYPE_INT32:
            XML_GET(reflection, message, field_descriptor, Int32, out);
            break;
        case FieldDescriptor::TYPE_UINT32:
        case FieldDescriptor::TYPE_FIXED32:
            XML_GET(reflection, message, field_descriptor, UInt32, out);
            break;
        case FieldDescriptor::TYPE_BYTES:
        case FieldDescriptor::TYPE_STRING: {
            const string &field_name = field_descriptor->name();
            if (field_descriptor->label() == FieldDescriptor::LABEL_REPEATED) {
                out << "<" << field_name << "s>";
                int size = reflection->FieldSize(message, field_descriptor);
                int i = 0;
                for (; i < size - 1; ++i) {
                    string value = reflection->GetRepeatedString(
                            message, field_descriptor, i);
                    //boost::replace_all(value, "\"", "\\\"");
                    NFStringUtility::Replace(value, "\"", "\\\"");
                    out << "<" << field_name << ">";
                    out << "\"" << value << "\"";
                    out << "</" << field_name << ">";
                }
                if (i == size - 1) {
                    string value = reflection->GetRepeatedString(message,
                                                                 field_descriptor, i);
                    //boost::replace_all(value, "\"", "\\\"");
                    NFStringUtility::Replace(value, "\"", "\\\"");
                    out << "<" << field_name << ">";
                    out << "\"" << value << "\"";
                    out << "</" << field_name << ">";
                }
                out << "</" << field_name << "s>";\
  } else {
                string value = reflection->GetString(message, field_descriptor);
                //boost::replace_all(value, "\"", "\\\"");
                NFStringUtility::Replace(value, "\"", "\\\"");
                out << "<" << field_name << ">";
                out << "\"" << value << "\"";
                out << "</" << field_name << ">";
            }
            break;
        }
        case FieldDescriptor::TYPE_DOUBLE:
            XML_GET(reflection, message, field_descriptor, Double, out);
            break;
        case FieldDescriptor::TYPE_FLOAT:
            XML_GET(reflection, message, field_descriptor, Float, out);
            break;
        case FieldDescriptor::TYPE_BOOL: {
            const string &field_name = field_descriptor->name();
            if (field_descriptor->label() == FieldDescriptor::LABEL_REPEATED) {
                out << "<" << field_name << "s>";
                int size = reflection->FieldSize(message, field_descriptor);
                int i = 0;
                for (; i < size - 1; ++i) {
                    bool value = reflection->GetRepeatedBool(
                            message, field_descriptor, i);
                    out << "<" << field_name << ">";
                    out << (value ? "true" : "false");
                    out << "</" << field_name << ">";
                }
                if (i == size - 1) {
                    bool value = reflection->GetRepeatedBool(
                            message, field_descriptor, i);
                    out << "<" << field_name << ">";
                    out << (value ? "true" : "false");
                    out << "</" << field_name << ">";
                }
                out << "</" << field_name << "s>";
            } else {
                bool value = reflection->GetBool(message, field_descriptor);
                out << "<" << field_name << ">";
                out << (value ? "true" : "false");
                out << "</" << field_name << ">";
            }
            break;
        }
        case FieldDescriptor::TYPE_ENUM: {
            const string &field_name = field_descriptor->name();
            if (field_descriptor->label() == FieldDescriptor::LABEL_REPEATED) {
                out << "<" << field_name << "s>";
                int size = reflection->FieldSize(message, field_descriptor);
                int i = 0;
                for (; i < size - 1; ++i) {
                    const EnumValueDescriptor* value
                            = reflection->GetRepeatedEnum(message, field_descriptor, i);
                    out << "<" << field_name << ">";
                    out << value->name();
                    out << "</" << field_name << ">";
                }
                if (i == size - 1) {
                    const EnumValueDescriptor* value
                            = reflection->GetRepeatedEnum(message, field_descriptor, i);
                    out << "<" << field_name << ">";
                    out << value->name();
                    out << "</" << field_name << ">";
                }
                out << "</" << field_name << "s>";
            } else {
                const EnumValueDescriptor* value
                        = reflection->GetEnum(message, field_descriptor);
                out << "<" << field_name << ">";
                out << value->name();
                out << "</" << field_name << ">";
            }
            break;
        }
        case FieldDescriptor::TYPE_MESSAGE: {
            const string &field_name = field_descriptor->name();
            if (field_descriptor->label() != FieldDescriptor::LABEL_REPEATED) {
                const Message &field_message = reflection->GetMessage(message,
                                                                      field_descriptor, NULL);
                out << "<" << field_name << ">";
                ToXmlString(field_message, out);
                out << "</" << field_name << ">";
            } else {
                out << "<" << field_name << "s>";
                int size = reflection->FieldSize(message, field_descriptor);
                int i = 0;
                for (; i < size - 1; ++i) {
                    const Message &field_message = reflection->GetRepeatedMessage(
                            message, field_descriptor, i);
                    out << "<" << field_name << ">";
                    ToXmlString(field_message, out);
                    out << "</" << field_name << ">";
                }
                if (i == size - 1) {
                    const Message &field_message = reflection->GetRepeatedMessage(
                            message, field_descriptor, i);
                    out << "<" << field_name << ">";
                    ToXmlString(field_message, out);
                    out << "</" << field_name << ">";
                }
                out << "</" << field_name << "s>";
            }
            break;
        }
        default:
            NFLogError(NF_LOG_SYSTEMLOG, 0, "字段[{}]是不支持的数据类型:{}",
                  field_descriptor->name().c_str(), field_descriptor->type());
    }
}

bool NFXmlMessageCodec::FillFieldValue(NFXmlTokenReader &tkReader,
                                       const FieldDescriptor* field_descriptor,
                                       const Reflection* reflection,
                                       Message *message) {
    const string &field_name = field_descriptor->name();
    switch (field_descriptor->type()) {
        case FieldDescriptor::TYPE_SFIXED64:
        case FieldDescriptor::TYPE_INT64:
            XML_SET_INTERGER(reflection, message, field_descriptor,
                             Int64, int64, strtoll, tkReader);
            break;
        case FieldDescriptor::TYPE_UINT64:
        case FieldDescriptor::TYPE_FIXED64:
            XML_SET_INTERGER(reflection, message, field_descriptor,
                             UInt64, uint64, strtoull, tkReader);
            break;
        case FieldDescriptor::TYPE_SFIXED32:
        case FieldDescriptor::TYPE_INT32:
            XML_SET_INTERGER(reflection, message, field_descriptor,
                             Int32, uint32, strtol, tkReader);
            break;
        case FieldDescriptor::TYPE_UINT32:
        case FieldDescriptor::TYPE_FIXED32:
            XML_SET_INTERGER(reflection, message, field_descriptor,
                             UInt32, uint32, strtoul, tkReader);
            break;
        case FieldDescriptor::TYPE_BYTES:
        case FieldDescriptor::TYPE_STRING:{
            Token tok;
            if (field_descriptor->label() == FieldDescriptor::LABEL_REPEATED) {
                do {
                    NFTokenType type = tkReader.NextToken(tok);
                    if (type != T_BEGIN_ELEMENT) {
                        if (type == T_AFTER_ELEMENT
                            && field_name == string(tok.base, tok.len)) {
                            break;
                        }
                        NFLogError(NF_LOG_SYSTEMLOG, 0, "xml数据错误，不是一个有效的常量:type:{} {}",
                              type, tok.base);
                        return false;
                    }
                    if (field_name.find(string(tok.base, tok.len)) == string::npos) {
                        NFLogError(NF_LOG_SYSTEMLOG, 0, "xml数据错误，不是一个有效的数组元素:type:{} {}",
                              type, tok.base);
                        return false;
                    }
                    type = tkReader.NextToken(tok);
                    if (type != T_STRING) {
                        NFLogError(NF_LOG_SYSTEMLOG, 0, "xml数据错误，不是一个有效的字串:type:{} {}",
                              type, tok.base);
                        return false;
                    }
                    string value(tok.base, tok.len);
                    //boost::replace_all(value, "\\\"", "\"");
                    NFStringUtility::Replace(value, "\\\"", "\"");
                    reflection->AddString(message, field_descriptor, value);
                    type = tkReader.NextToken(tok);
                    if (type != T_AFTER_ELEMENT
                        || field_name.find(string(tok.base, tok.len)) == string::npos) {
                        NFLogError(NF_LOG_SYSTEMLOG, 0, "xml数据错误，不是一个有效的常量:type:{} {}",
                              type, tok.base);
                        return false;
                    }
                } while (true);
            } else {
                NFTokenType type = tkReader.NextToken(tok);
                if (type != T_STRING) {
                    NFLogError(NF_LOG_SYSTEMLOG, 0, "xml数据错误，不是一个有效的字串:type:{} {}",
                          type, tok.base);
                    return false;
                }
                string value(tok.base, tok.len);
                //boost::replace_all(value, "\\\"", "\"");
                NFStringUtility::Replace(value, "\\\"", "\"");
                reflection->SetString(message, field_descriptor, value);
                type = tkReader.NextToken(tok);
                if (type != T_AFTER_ELEMENT) {
                    NFLogError(NF_LOG_SYSTEMLOG, 0, "xml数据错误，不是一个有效的常量:type:{} {}",
                          type, tok.base);
                    return false;
                }
            }
            break;
        }
        case FieldDescriptor::TYPE_DOUBLE:
            XML_SET_FLOAT(reflection, message, field_descriptor,
                          Double, double, strtod, tkReader);
            break;
        case FieldDescriptor::TYPE_FLOAT:
            XML_SET_FLOAT(reflection, message, field_descriptor,
                          Float, float, strtof, tkReader);
            break;
        case FieldDescriptor::TYPE_BOOL: {
            Token tok;
            if (field_descriptor->label() == FieldDescriptor::LABEL_REPEATED) {
                do {
                    NFTokenType type = tkReader.NextToken(tok);
                    if (type != T_BEGIN_ELEMENT) {
                        if (type == T_AFTER_ELEMENT
                            && field_name == string(tok.base, tok.len)) {
                            break;
                        }
                        NFLogError(NF_LOG_SYSTEMLOG, 0, "xml数据错误，不是一个有效的常量:type:%d %s",
                              type, tok.base);
                        return false;
                    }
                    if (field_name.find(string(tok.base, tok.len)) == string::npos) {
                        NFLogError(NF_LOG_SYSTEMLOG, 0, "xml数据错误，不是一个有效的数组元素:type:%d %s",
                              type, tok.base);
                        return false;
                    }
                    type = tkReader.NextToken(tok);
                    if (type != T_CONSTANTS) {
                        NFLogError(NF_LOG_SYSTEMLOG, 0, "xml数据错误，不是一个有效的常量:type:%d %s",
                              type, tok.base);
                        return false;
                    }
                    bool value = strncasecmp(tok.base, "true", 4) == 0 ? true : false;
                    reflection->AddBool(message, field_descriptor, value);
                    type = tkReader.NextToken(tok);
                    if (type != T_AFTER_ELEMENT
                        || field_name.find(string(tok.base, tok.len)) == string::npos) {
                        NFLogError(NF_LOG_SYSTEMLOG, 0, "xml数据错误，不是一个有效的常量:type:%d %s",
                              type, tok.base);
                        return false;
                    }
                } while (true);
            } else {
                NFTokenType type = tkReader.NextToken(tok);
                if (type != T_CONSTANTS) {
                    NFLogError(NF_LOG_SYSTEMLOG, 0, "xml数据错误，不是一个有效的常量:type:%d %s",
                          type, tok.base);
                    return false;
                }
                bool value = strncasecmp(tok.base, "true", 4) == 0 ? true : false;
                reflection->SetBool(message, field_descriptor, value);
                type = tkReader.NextToken(tok);
                if (type != T_AFTER_ELEMENT) {
                    NFLogError(NF_LOG_SYSTEMLOG, 0, "xml数据错误，不是一个有效的常量:type:%d %s",
                          type, tok.base);
                    return false;
                }
            }
            break;
        }
        case FieldDescriptor::TYPE_ENUM: {
            const EnumDescriptor* enum_desc = field_descriptor->enum_type();
            Token tok;
            if (field_descriptor->label() == FieldDescriptor::LABEL_REPEATED) {
                do {
                    NFTokenType type = tkReader.NextToken(tok);
                    if (type != T_BEGIN_ELEMENT) {
                        if (type == T_AFTER_ELEMENT
                            && field_name == string(tok.base, tok.len)) {
                            break;
                        }
                        NFLogError(NF_LOG_SYSTEMLOG, 0, "xml数据错误，不是一个有效的常量:type:%d %s",
                              type, tok.base);
                        return false;
                    }
                    if (field_name.find(string(tok.base, tok.len)) == string::npos) {
                        NFLogError(NF_LOG_SYSTEMLOG, 0, "xml数据错误，不是一个有效的数组元素:type:%d %s",
                              type, tok.base);
                        return false;
                    }
                    type = tkReader.NextToken(tok);
                    if (type != T_CONSTANTS) {
                        NFLogError(NF_LOG_SYSTEMLOG, 0, "xml数据错误，不是一个有效的常量:type:%d %s",
                              type, tok.base);
                        return false;
                    }
                    string key(tok.base, tok.len);
                    const EnumValueDescriptor* enum_value = enum_desc->FindValueByName(key);
                    if (enum_value == NULL) {
                        enum_value = enum_desc->FindValueByNumber(NFCommon::strto<int>(key));
                        if(enum_value == NULL){
                            NFLogError(NF_LOG_SYSTEMLOG, 0, "字段[%s]不存在枚举值[%s]",
                                  field_descriptor->name().c_str(), key.c_str());
                            return false;
                        }
                    }
                    type = tkReader.NextToken(tok);
                    if (type != T_AFTER_ELEMENT
                        || field_name.find(string(tok.base, tok.len)) == string::npos) {
                        NFLogError(NF_LOG_SYSTEMLOG, 0, "xml数据错误，不是一个有效的常量:type:%d %s",
                              type, tok.base);
                        return false;
                    }
                } while (true);
            } else {
                NFTokenType type = tkReader.NextToken(tok);
                if (type != T_CONSTANTS) {
                    NFLogError(NF_LOG_SYSTEMLOG, 0, "xml数据错误，不是一个有效的常量:type:%d %s", type, tok.base);
                    return false;
                }
                string key(tok.base, tok.len);
                const EnumValueDescriptor* enum_value = enum_desc->FindValueByName(key);
                if (enum_value == NULL) {
                    enum_value = enum_desc->FindValueByNumber(NFCommon::strto<int>(key));
                    if(enum_value == NULL){
                        NFLogError(NF_LOG_SYSTEMLOG, 0, "字段[%s]不存在枚举值[%s]",
                              field_descriptor->name().c_str(), key.c_str());
                        return false;
                    }
                }
                reflection->SetEnum(message, field_descriptor, enum_value);
                type = tkReader.NextToken(tok);
                if (type != T_AFTER_ELEMENT) {
                    NFLogError(NF_LOG_SYSTEMLOG, 0, "xml数据错误，不是一个有效的常量:type:%d %s", type, tok.base);
                    return false;
                }
            }
            break;
        }
        case FieldDescriptor::TYPE_MESSAGE: {
            Token tok;
            if (field_descriptor->label() != FieldDescriptor::LABEL_REPEATED) {
                Message* field_message = reflection->MutableMessage(
                        message, field_descriptor, NULL);
                FromXmlObject(tkReader, field_message, field_name);
            } else {
                do {
                    NFTokenType type = tkReader.NextToken(tok);
                    if (type != T_BEGIN_ELEMENT) {
                        if (type == T_AFTER_ELEMENT
                            && field_name == string(tok.base, tok.len - 1)) {
                            break;
                        }
                        NFLogError(NF_LOG_SYSTEMLOG, 0, "xml数据错误，不是一个有效的常量:type:%d %s",
                              type, tok.base);
                        return false;
                    }
                    Message* field_message = reflection->AddMessage(
                            message, field_descriptor, NULL);
                    if (!FromXmlObject(tkReader, field_message, field_name)) {
                        return false;
                    }

                } while (true);

            }
            break;
        }
        default:
            NFLogError(NF_LOG_SYSTEMLOG, 0, "字段[%s]是不支持的数据类型:%d",
                  field_descriptor->name().c_str(), field_descriptor->type());
    }
    return true;
}

bool NFXmlMessageCodec::FromXmlObject(NFXmlTokenReader &tkReader,
                                      Message *message,
                                      const string &name) {
    const Reflection* reflection = message->GetReflection();
    const Descriptor* descriptor = message->GetDescriptor();
    do {
        Token tok;
        NFTokenType type = tkReader.NextToken(tok);
        if (type != T_BEGIN_ELEMENT) {
            if (type == T_AFTER_ELEMENT && name == string(tok.base, tok.len)) {
                break;
            }
            NFLogError(NF_LOG_SYSTEMLOG, 0, "给出的xml不合法:{}", type);
            return false;
        }
        string field_name(tok.base, tok.len);
        const FieldDescriptor* field_descriptor
                = descriptor->FindFieldByName(field_name);
        if (field_descriptor == NULL) {
            //if (! (boost::ends_with(field_name, "s")
            if (! (NFStringUtility::EndsWith(field_name, "s")
                   && (field_descriptor
                               = descriptor->FindFieldByName(
                            field_name.substr(0, field_name.size() - 1))))) {
                NFLogError(NF_LOG_SYSTEMLOG, 0, "在消息类型[{}]中不存在字段[{}]",
                      descriptor->name().c_str(), field_name.c_str());
                return false;
            }
        }
        // NFLogError(NF_LOG_SYSTEMLOG, 0, "在消息类型[%s]中不存在字段[%s]",
        //           descriptor->name().c_str(), field_name.c_str());
        FillFieldValue(tkReader, field_descriptor, reflection, message);

    } while (true);
    return true;
}

bool NFXmlMessageCodec::FromString(const std::string &xml,
                                   google::protobuf::Message &msg) {
    int size = xml.size();
    if (size < 8) {  // <a>1</a>
        return false;
    }
    NFXmlTokenReader Reader(xml.c_str(), xml.size());
    const Descriptor* descriptor = msg.GetDescriptor();
    Token tok;
    if (Reader.NextToken(tok) != T_BEGIN_ELEMENT
        || descriptor->name() != string(tok.base, tok.len)) {
        NFLogError(NF_LOG_SYSTEMLOG, 0, "数据无效，不是开始于一个有效的element:{}", xml.c_str());
        return false;
    }
    return FromXmlObject(Reader, &msg, descriptor->name());
}

bool NFXmlMessageCodec::CompactAndCheckString(const string &xml, string &result) {
    NFXmlTokenReader tkReader(xml.c_str(), xml.size());
    std::stack< string > stack;
    do {
        Token tok;
        NFTokenType type = tkReader.NextToken(tok);
        switch (type) {
            case T_BEGIN_ELEMENT:{
                string tmp(tok.base, tok.len);
                stack.push(tmp);
                result += "<";
                result += tmp;
                result += ">";
                break;
            }
            case T_AFTER_ELEMENT:{
                string tmp(tok.base, tok.len);
                if(stack.empty() || stack.top() != tmp){
                    NFLogError(NF_LOG_SYSTEMLOG, 0, "输入的xml数据不是有效的xml，element不匹配!");
                    return false;
                }
                stack.pop();
                result += "</";
                result += tmp;
                result += ">";
                break;
            }
            case T_ERROR:{
                NFLogError(NF_LOG_SYSTEMLOG, 0, "输入的xml数据不是有效的xml，读取token失败!");
                return false;
            }
            case T_END:{
                goto out;
            }
            default:
                result += string(tok.base, tok.len);
        }  // end switch
    } while (true);
    out:
    if(! stack.empty()){
        NFLogError(NF_LOG_SYSTEMLOG, 0, "输入的xml数据不是有效的xml，element不配对!");
        return false;
    }
    return true;
}

bool NFXmlMessageCodec::PrettyString(const std::string &xml,
                                     std::string &result) {

    static const char *indent[] = {
            "",
            "  ",
            "    ",
            "      ",
            "        ",
            "          ",
            "            ",
            "              ",
            "                ",
            "                  ",
            "                    ",
            "                      ",
            "                        "
    };

    NFXmlTokenReader tkReader(xml.c_str(), xml.size());
    result.clear();
    int level = 0;
    NFTokenType type = T_END;
    std::stack< string > stack;
    string pre_token;
    do {
        Token tok;
        type = tkReader.NextToken(tok);
        switch (type) {
            case T_BEGIN_ELEMENT: {
                string tmp(tok.base, tok.len);
                if (! stack.empty() && tmp != stack.top()
                    && result[result.size() - 1] != '\n') {
                    result += "\n";
                }
                result += indent[level++];
                result += "<";
                result += tmp;
                result += ">";
                pre_token.assign(tmp);
                stack.push(tmp);
                break;
            }
            case T_AFTER_ELEMENT: {
                string tmp(tok.base, tok.len);
                level--;
                if (pre_token != tmp) {
                    result += indent[level];
                }

                if (tmp == stack.top()) {
                    result += "</";
                    result += tmp;
                    result += ">";
                    result += "\n";
                    stack.pop();
                } else {
                    result += "</";
                    result += tmp;
                    result += ">";
                    stack.push(tmp);
                }
                pre_token.assign(tmp);
                break;
            }
            case T_ERROR: {
                NFLogError(NF_LOG_SYSTEMLOG, 0, "输入的xml数据不是有效的xml，读取token失败!");
                goto out;
            }
            case T_END: {
                goto out;
            }
            case T_STRING: {
                result += "\"";
                result += string(tok.base, tok.len);
                result += "\"";
                break;
            }
            default:
                result += string(tok.base, tok.len);
        }  // end switch
    } while (type != T_END);

    out:
    if(level != 0){
        NFLogError(NF_LOG_SYSTEMLOG, 0, "输入的xml数据不是有效的xml，element不配对!");
        type = T_ERROR;
    }
    return type != T_ERROR;
}