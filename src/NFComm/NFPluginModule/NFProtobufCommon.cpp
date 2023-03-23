// -------------------------------------------------------------------------
//    @FileName         :    NFProtobufCommon.cpp
//    @Author           :    Gao.Yi
//    @Date             :   2022-09-18
//    @Email			:    445267987@qq.com
//    @Module           :    NFProtobufCommon
//
// -------------------------------------------------------------------------

#include <fstream>
#include "NFProtobufCommon.h"
#include "NFLogMgr.h"
#include "NFCheck.h"
#include "NFComm/NFKernelMessage/yd_fieldoptions.pb.h"
#include "NFComm/NFPluginModule/NFJson2PB/NFPbToJson.h"
#include "NFComm/NFPluginModule/NFJson2PB/NFJsonToPb.h"
#include "NFComm/NFCore/NFStringUtility.h"
#include "NFComm/NFPluginModule/NFProto/NFXmlMessageCodec.h"
#include "NFComm/NFCore/NFCommon.h"
#include "NFComm/NFCore/NFLock.h"

#ifdef GetMessage
#undef GetMessage
#endif

std::string NFProtobufCommon::GetRepeatedFieldsString(const google::protobuf::Message &message,
                                                      const google::protobuf::FieldDescriptor *pFieldDesc, int index)
{
    const google::protobuf::Reflection *pReflect = message.GetReflection();
    if (pReflect == nullptr || pFieldDesc == nullptr) return std::string();
    if (pFieldDesc->is_repeated() == false) return std::string();

    switch (pFieldDesc->cpp_type())
    {
        case google::protobuf::FieldDescriptor::CPPTYPE_INT32:
        {
            int32_t value = pReflect->GetRepeatedInt32(message, pFieldDesc, index);
            return NFCommon::tostr(value);
        }
            break;
        case google::protobuf::FieldDescriptor::CPPTYPE_INT64:
        {
            int64_t value = pReflect->GetRepeatedInt64(message, pFieldDesc, index);
            return NFCommon::tostr(value);
        }
            break;
        case google::protobuf::FieldDescriptor::CPPTYPE_UINT32:
        {
            uint32_t value = pReflect->GetRepeatedUInt32(message, pFieldDesc, index);
            return NFCommon::tostr(value);
        }
            break;
        case google::protobuf::FieldDescriptor::CPPTYPE_UINT64:
        {
            uint64_t value = pReflect->GetRepeatedUInt64(message, pFieldDesc, index);
            return NFCommon::tostr(value);
        }
            break;
        case google::protobuf::FieldDescriptor::CPPTYPE_DOUBLE:
        {
            double value = pReflect->GetRepeatedDouble(message, pFieldDesc, index);
            return NFCommon::tostr(value);
        }
            break;
        case google::protobuf::FieldDescriptor::CPPTYPE_FLOAT:
        {
            float value = pReflect->GetRepeatedFloat(message, pFieldDesc, index);
            return NFCommon::tostr(value);
        }
            break;
        case google::protobuf::FieldDescriptor::CPPTYPE_BOOL:
        {
            bool value = pReflect->GetRepeatedBool(message, pFieldDesc, index);
            return NFCommon::tostr(value);
        }
            break;
        case google::protobuf::FieldDescriptor::CPPTYPE_ENUM:
        {
            const google::protobuf::EnumValueDescriptor *pEnumDesc = pReflect->GetRepeatedEnum(message, pFieldDesc,
                                                                                               index);
            if (pEnumDesc)
            {
                return NFCommon::tostr(pEnumDesc->number());
            }
        }
            break;
        case google::protobuf::FieldDescriptor::CPPTYPE_STRING:
        {
            std::string value = pReflect->GetRepeatedString(message, pFieldDesc, index);
            return value;
        }
            break;
        case google::protobuf::FieldDescriptor::CPPTYPE_MESSAGE:
        {
            const google::protobuf::Message &value = pReflect->GetRepeatedMessage(message, pFieldDesc, index);
            std::string msg;
            value.SerializePartialToString(&msg);
            return msg;
        }
            break;
        default:
            break;
    }
    return std::string();
}

int NFProtobufCommon::CopyMessageByFields(google::protobuf::Message *pSrcMessage, const google::protobuf::Message *pDescMessage)
{
    if (!pSrcMessage || !pDescMessage) return -1;

    const google::protobuf::Descriptor *pDestDesc = pDescMessage->GetDescriptor();
    const google::protobuf::Reflection *pDestReflect = pDescMessage->GetReflection();
    if (pDestDesc == NULL || pDestReflect == NULL) return -1;

    const google::protobuf::Descriptor *pSrcDesc = pSrcMessage->GetDescriptor();
    const google::protobuf::Reflection *pSrcReflect = pSrcMessage->GetReflection();
    if (pSrcDesc == NULL || pSrcReflect == NULL) return -1;

    for (int j = 0; j < pSrcDesc->field_count(); j++)
    {
        const google::protobuf::FieldDescriptor *pSrcFieldDesc = pSrcDesc->field(j);
        if (pSrcFieldDesc == NULL) continue;

        const google::protobuf::FieldDescriptor *pDescFieldDesc = pDestDesc->FindFieldByLowercaseName(pSrcFieldDesc->lowercase_name());
        if (pDescFieldDesc == NULL) continue;

        if (pSrcFieldDesc->cpp_type() == pDescFieldDesc->cpp_type())
        {
            if (!pSrcFieldDesc->is_repeated())
            {
                switch (pSrcFieldDesc->cpp_type())
                {
                    case google::protobuf::FieldDescriptor::CPPTYPE_INT32:
                    {
                        pSrcReflect->SetInt32(pSrcMessage, pSrcFieldDesc, pDestReflect->GetInt32(*pDescMessage, pDescFieldDesc));
                    }
                        break;
                    case google::protobuf::FieldDescriptor::CPPTYPE_INT64:
                    {
                        pSrcReflect->SetInt64(pSrcMessage, pSrcFieldDesc, pDestReflect->GetInt64(*pDescMessage, pDescFieldDesc));
                    }
                        break;
                    case google::protobuf::FieldDescriptor::CPPTYPE_UINT32:
                    {
                        pSrcReflect->SetUInt32(pSrcMessage, pSrcFieldDesc, pDestReflect->GetUInt32(*pDescMessage, pDescFieldDesc));
                    }
                        break;
                    case google::protobuf::FieldDescriptor::CPPTYPE_UINT64:
                    {
                        pSrcReflect->SetUInt64(pSrcMessage, pSrcFieldDesc, pDestReflect->GetUInt64(*pDescMessage, pDescFieldDesc));
                    }
                        break;
                    case google::protobuf::FieldDescriptor::CPPTYPE_DOUBLE:
                    {
                        pSrcReflect->SetDouble(pSrcMessage, pSrcFieldDesc, pDestReflect->GetDouble(*pDescMessage, pDescFieldDesc));
                    }
                        break;
                    case google::protobuf::FieldDescriptor::CPPTYPE_FLOAT:
                    {
                        pSrcReflect->SetFloat(pSrcMessage, pSrcFieldDesc, pDestReflect->GetFloat(*pDescMessage, pDescFieldDesc));
                    }
                        break;
                    case google::protobuf::FieldDescriptor::CPPTYPE_BOOL:
                    {
                        pSrcReflect->SetBool(pSrcMessage, pSrcFieldDesc, pDestReflect->GetBool(*pDescMessage, pDescFieldDesc));
                    }
                        break;
                    case google::protobuf::FieldDescriptor::CPPTYPE_ENUM:
                    {
                        pSrcReflect->SetEnum(pSrcMessage, pSrcFieldDesc, pDestReflect->GetEnum(*pDescMessage, pDescFieldDesc));
                    }
                        break;
                    case google::protobuf::FieldDescriptor::CPPTYPE_STRING:
                    {
                        pSrcReflect->SetString(pSrcMessage, pSrcFieldDesc, pDestReflect->GetString(*pDescMessage, pDescFieldDesc));
                    }
                        break;
                    case google::protobuf::FieldDescriptor::CPPTYPE_MESSAGE:
                    {
                        const google::protobuf::Message &destFieldMessage = pDestReflect->GetMessage(*pDescMessage, pDescFieldDesc);
                        google::protobuf::Message *pMutableMessage = pSrcReflect->MutableMessage(pSrcMessage, pSrcFieldDesc);
                        if (pMutableMessage)
                        {
                            CopyMessageByFields(pMutableMessage, &destFieldMessage);
                        }
                    }
                        break;
                    default:
                        break;
                }
            }
            else
            {
                switch (pSrcFieldDesc->cpp_type())
                {
                    case google::protobuf::FieldDescriptor::CPPTYPE_INT32:
                    {
                        for (int i = 0; i < (int) pDestReflect->FieldSize(*pDescMessage, pDescFieldDesc); i++)
                        {
                            pSrcReflect->AddInt32(pSrcMessage, pSrcFieldDesc, pDestReflect->GetRepeatedInt32(*pDescMessage, pDescFieldDesc, i));
                        }
                    }
                        break;
                    case google::protobuf::FieldDescriptor::CPPTYPE_INT64:
                    {
                        for (int i = 0; i < (int) pDestReflect->FieldSize(*pDescMessage, pDescFieldDesc); i++)
                        {
                            pSrcReflect->AddInt64(pSrcMessage, pSrcFieldDesc, pDestReflect->GetRepeatedInt64(*pDescMessage, pDescFieldDesc, i));
                        }
                    }
                        break;
                    case google::protobuf::FieldDescriptor::CPPTYPE_UINT32:
                    {
                        for (int i = 0; i < (int) pDestReflect->FieldSize(*pDescMessage, pDescFieldDesc); i++)
                        {
                            pSrcReflect->AddUInt32(pSrcMessage, pSrcFieldDesc, pDestReflect->GetRepeatedUInt32(*pDescMessage, pDescFieldDesc, i));
                        }
                    }
                        break;
                    case google::protobuf::FieldDescriptor::CPPTYPE_UINT64:
                    {
                        for (int i = 0; i < (int) pDestReflect->FieldSize(*pDescMessage, pDescFieldDesc); i++)
                        {
                            pSrcReflect->AddUInt64(pSrcMessage, pSrcFieldDesc, pDestReflect->GetRepeatedUInt64(*pDescMessage, pDescFieldDesc, i));
                        }
                    }
                        break;
                    case google::protobuf::FieldDescriptor::CPPTYPE_DOUBLE:
                    {
                        for (int i = 0; i < (int) pDestReflect->FieldSize(*pDescMessage, pDescFieldDesc); i++)
                        {
                            pSrcReflect->AddDouble(pSrcMessage, pSrcFieldDesc, pDestReflect->GetRepeatedDouble(*pDescMessage, pDescFieldDesc, i));
                        }
                    }
                        break;
                    case google::protobuf::FieldDescriptor::CPPTYPE_FLOAT:
                    {
                        for (int i = 0; i < (int) pDestReflect->FieldSize(*pDescMessage, pDescFieldDesc); i++)
                        {
                            pSrcReflect->AddFloat(pSrcMessage, pSrcFieldDesc, pDestReflect->GetRepeatedFloat(*pDescMessage, pDescFieldDesc, i));
                        }
                    }
                        break;
                    case google::protobuf::FieldDescriptor::CPPTYPE_BOOL:
                    {
                        for (int i = 0; i < (int) pDestReflect->FieldSize(*pDescMessage, pDescFieldDesc); i++)
                        {
                            pSrcReflect->AddBool(pSrcMessage, pSrcFieldDesc, pDestReflect->GetRepeatedBool(*pDescMessage, pDescFieldDesc, i));
                        }
                    }
                        break;
                    case google::protobuf::FieldDescriptor::CPPTYPE_ENUM:
                    {
                        for (int i = 0; i < (int) pDestReflect->FieldSize(*pDescMessage, pDescFieldDesc); i++)
                        {
                            pSrcReflect->AddEnum(pSrcMessage, pSrcFieldDesc, pDestReflect->GetRepeatedEnum(*pDescMessage, pDescFieldDesc, i));
                        }
                    }
                        break;
                    case google::protobuf::FieldDescriptor::CPPTYPE_STRING:
                    {
                        for (int i = 0; i < (int) pDestReflect->FieldSize(*pDescMessage, pDescFieldDesc); i++)
                        {
                            pSrcReflect->AddString(pSrcMessage, pSrcFieldDesc, pDestReflect->GetRepeatedString(*pDescMessage, pDescFieldDesc, i));
                        }
                    }
                        break;
                    case google::protobuf::FieldDescriptor::CPPTYPE_MESSAGE:
                    {
                        for (int i = 0; i < (int) pDestReflect->FieldSize(*pDescMessage, pDescFieldDesc); i++)
                        {
                            const google::protobuf::Message &destFieldMessage = pDestReflect->GetRepeatedMessage(*pDescMessage, pDescFieldDesc, i);
                            google::protobuf::Message *pMutableMessage = pSrcReflect->AddMessage(pSrcMessage, pSrcFieldDesc);
                            if (pMutableMessage)
                            {
                                CopyMessageByFields(pMutableMessage, &destFieldMessage);
                            }
                        }
                    }
                        break;
                    default:
                        break;
                }
            }
        }
    }

    return 0;
}

std::string NFProtobufCommon::GetFieldsString(const google::protobuf::Message &message,
                                              const google::protobuf::FieldDescriptor *pFieldDesc)
{
    const google::protobuf::Reflection *pReflect = message.GetReflection();
    if (pReflect == nullptr || pFieldDesc == nullptr) return std::string();
    if (pFieldDesc->is_repeated()) return std::string();

    switch (pFieldDesc->cpp_type())
    {
        case google::protobuf::FieldDescriptor::CPPTYPE_INT32:
        {
            int32_t value = pReflect->GetInt32(message, pFieldDesc);
            return NFCommon::tostr(value);
        }
            break;
        case google::protobuf::FieldDescriptor::CPPTYPE_INT64:
        {
            int64_t value = pReflect->GetInt64(message, pFieldDesc);
            return NFCommon::tostr(value);
        }
            break;
        case google::protobuf::FieldDescriptor::CPPTYPE_UINT32:
        {
            uint32_t value = pReflect->GetUInt32(message, pFieldDesc);
            return NFCommon::tostr(value);
        }
            break;
        case google::protobuf::FieldDescriptor::CPPTYPE_UINT64:
        {
            uint64_t value = pReflect->GetUInt64(message, pFieldDesc);
            return NFCommon::tostr(value);
        }
            break;
        case google::protobuf::FieldDescriptor::CPPTYPE_DOUBLE:
        {
            double value = pReflect->GetDouble(message, pFieldDesc);
            return NFCommon::tostr(value);
        }
            break;
        case google::protobuf::FieldDescriptor::CPPTYPE_FLOAT:
        {
            float value = pReflect->GetFloat(message, pFieldDesc);
            return NFCommon::tostr(value);
        }
            break;
        case google::protobuf::FieldDescriptor::CPPTYPE_BOOL:
        {
            bool value = pReflect->GetBool(message, pFieldDesc);
            return NFCommon::tostr(value);
        }
            break;
        case google::protobuf::FieldDescriptor::CPPTYPE_ENUM:
        {
            const google::protobuf::EnumValueDescriptor *pEnumDesc = pReflect->GetEnum(message, pFieldDesc);
            if (pEnumDesc)
            {
                return NFCommon::tostr(pEnumDesc->number());
            }
        }
            break;
        case google::protobuf::FieldDescriptor::CPPTYPE_STRING:
        {
            std::string value = pReflect->GetString(message, pFieldDesc);
            return value;
        }
            break;
        case google::protobuf::FieldDescriptor::CPPTYPE_MESSAGE:
        {
            const google::protobuf::Message &value = pReflect->GetMessage(message, pFieldDesc);
            std::string msg;
            value.SerializePartialToString(&msg);
            return msg;
        }
            break;
        default:
            break;
    }
    return std::string();
}

void NFProtobufCommon::SetFieldsString(google::protobuf::Message &message, const google::protobuf::FieldDescriptor *pFieldDesc,
                                       const std::string &strValue)
{
    const google::protobuf::Reflection *pReflect = message.GetReflection();
    if (pReflect == nullptr || pFieldDesc == nullptr) return;
    if (pFieldDesc->is_repeated()) return;

    switch (pFieldDesc->cpp_type())
    {
        case google::protobuf::FieldDescriptor::CPPTYPE_INT32:
        {
            int32_t value = NFCommon::strto<int32_t>(strValue);
            pReflect->SetInt32(&message, pFieldDesc, value);
            return;
        }
            break;
        case google::protobuf::FieldDescriptor::CPPTYPE_INT64:
        {
            int64_t value = NFCommon::strto<int64_t>(strValue);
            pReflect->SetInt64(&message, pFieldDesc, value);
            return;
        }
            break;
        case google::protobuf::FieldDescriptor::CPPTYPE_UINT32:
        {
            uint32_t value = NFCommon::strto<uint32_t>(strValue);
            pReflect->SetUInt32(&message, pFieldDesc, value);
            return;
        }
            break;
        case google::protobuf::FieldDescriptor::CPPTYPE_UINT64:
        {
            uint64_t value = NFCommon::strto<uint64_t>(strValue);
            pReflect->SetUInt64(&message, pFieldDesc, value);
            return;
        }
            break;
        case google::protobuf::FieldDescriptor::CPPTYPE_DOUBLE:
        {
            double value = NFCommon::strto<double>(strValue);
            pReflect->SetDouble(&message, pFieldDesc, value);
            return;
        }
            break;
        case google::protobuf::FieldDescriptor::CPPTYPE_FLOAT:
        {
            float value = NFCommon::strto<float>(strValue);
            pReflect->SetFloat(&message, pFieldDesc, value);
            return;
        }
            break;
        case google::protobuf::FieldDescriptor::CPPTYPE_BOOL:
        {
            bool value = (bool) NFCommon::strto<bool>(strValue);
            pReflect->SetBool(&message, pFieldDesc, value);
            return;
        }
            break;
        case google::protobuf::FieldDescriptor::CPPTYPE_ENUM:
        {
            int value = NFCommon::strto<int>(strValue);
            const google::protobuf::EnumDescriptor *pEnumDesc = pFieldDesc->enum_type();
            if (pEnumDesc == nullptr) return;

            const google::protobuf::EnumValueDescriptor *pEnumValueDesc = pEnumDesc->FindValueByNumber(value);
            if (pEnumValueDesc == nullptr) return;

            pReflect->SetEnum(&message, pFieldDesc, pEnumValueDesc);
            return;
        }
            break;
        case google::protobuf::FieldDescriptor::CPPTYPE_STRING:
        {
            pReflect->SetString(&message, pFieldDesc, strValue);
            return;
        }
            break;
        case google::protobuf::FieldDescriptor::CPPTYPE_MESSAGE:
        {
            google::protobuf::Message *pMutableMessage = pReflect->MutableMessage(&message, pFieldDesc);
            if (pMutableMessage == nullptr) return;

            pMutableMessage->ParsePartialFromString(strValue);
            return;
        }
            break;
        default:
            break;
    }
    return;
}

void NFProtobufCommon::AddFieldsString(google::protobuf::Message &message, const google::protobuf::FieldDescriptor *pFieldDesc,
                                       const std::string &strValue)
{
    const google::protobuf::Reflection *pReflect = message.GetReflection();
    if (pReflect == nullptr || pFieldDesc == nullptr) return;
    if (pFieldDesc->is_repeated() == false) return;

    switch (pFieldDesc->cpp_type())
    {
        case google::protobuf::FieldDescriptor::CPPTYPE_INT32:
        {
            int32_t value = NFCommon::strto<int32_t>(strValue);
            pReflect->AddInt32(&message, pFieldDesc, value);
            return;
        }
            break;
        case google::protobuf::FieldDescriptor::CPPTYPE_INT64:
        {
            int64_t value = NFCommon::strto<int64_t>(strValue);
            pReflect->AddInt64(&message, pFieldDesc, value);
            return;
        }
            break;
        case google::protobuf::FieldDescriptor::CPPTYPE_UINT32:
        {
            uint32_t value = NFCommon::strto<uint32_t>(strValue);
            pReflect->AddUInt32(&message, pFieldDesc, value);
            return;
        }
            break;
        case google::protobuf::FieldDescriptor::CPPTYPE_UINT64:
        {
            uint64_t value = NFCommon::strto<uint64_t>(strValue);
            pReflect->AddUInt64(&message, pFieldDesc, value);
            return;
        }
            break;
        case google::protobuf::FieldDescriptor::CPPTYPE_DOUBLE:
        {
            double value = NFCommon::strto<double>(strValue);
            pReflect->AddDouble(&message, pFieldDesc, value);
            return;
        }
            break;
        case google::protobuf::FieldDescriptor::CPPTYPE_FLOAT:
        {
            float value = NFCommon::strto<float>(strValue);
            pReflect->AddFloat(&message, pFieldDesc, value);
            return;
        }
            break;
        case google::protobuf::FieldDescriptor::CPPTYPE_BOOL:
        {
            bool value = (bool) NFCommon::strto<bool>(strValue);
            pReflect->AddBool(&message, pFieldDesc, value);
            return;
        }
            break;
        case google::protobuf::FieldDescriptor::CPPTYPE_ENUM:
        {
            int value = NFCommon::strto<int>(strValue);
            const google::protobuf::EnumDescriptor *pEnumDesc = pFieldDesc->enum_type();
            if (pEnumDesc == nullptr) return;

            const google::protobuf::EnumValueDescriptor *pEnumValueDesc = pEnumDesc->FindValueByNumber(value);
            if (pEnumValueDesc == nullptr) return;

            pReflect->AddEnum(&message, pFieldDesc, pEnumValueDesc);
            return;
        }
            break;
        case google::protobuf::FieldDescriptor::CPPTYPE_STRING:
        {
            pReflect->AddString(&message, pFieldDesc, strValue);
            return;
        }
            break;
        case google::protobuf::FieldDescriptor::CPPTYPE_MESSAGE:
        {
            google::protobuf::Message *pMutableMessage = pReflect->AddMessage(&message, pFieldDesc);
            if (pMutableMessage == nullptr) return;

            pMutableMessage->ParsePartialFromString(strValue);
            return;
        }
            break;
        default:
            break;
    }
    return;
}

const ::google::protobuf::Message *NFProtobufCommon::FindMessageTypeByName(const std::string &full_name)
{
    const google::protobuf::Descriptor *pDescriptor = ::google::protobuf::DescriptorPool::generated_pool()->FindMessageTypeByName(
            full_name);
    if (pDescriptor)
    {
        return ::google::protobuf::MessageFactory::generated_factory()->GetPrototype(pDescriptor);
    }
    return NULL;
}

::google::protobuf::Message *NFProtobufCommon::CreateMessageByName(const std::string &full_name)
{
    const ::google::protobuf::Message *pMessageType = FindMessageTypeByName(full_name);
    if (pMessageType)
    {
        return pMessageType->New();
    }
    return NULL;
}

int NFProtobufCommon::GetMapFieldsStringFromMessage(const google::protobuf::Message &message, std::string &msg)
{
    const google::protobuf::Descriptor *pDesc = message.GetDescriptor();
    const google::protobuf::Reflection *pReflect = message.GetReflection();
    if (pDesc == NULL || pReflect == NULL) return -1;

    for (int i = 0; i < pDesc->field_count(); i++)
    {
        const google::protobuf::FieldDescriptor *pFieldDesc = pDesc->field(i);
        if (pFieldDesc == NULL) continue;
        if (pFieldDesc->is_repeated()) continue;

        if (pFieldDesc->cpp_type() == google::protobuf::FieldDescriptor::CPPTYPE_MESSAGE)
        {
            const google::protobuf::Message &subMessage = pReflect->GetMessage(message, pFieldDesc);
            GetMapFieldsStringFromMessage(subMessage, msg);
        }
        else
        {
            msg += "|" + GetFieldsString(message, pFieldDesc);
        }
    }
    return 0;
}

void NFProtobufCommon::GetMapFieldsFromMessage(const google::protobuf::Message &message,
                                               std::map<std::string, std::string> &mapFields,
                                               bool ignore_special_repeted, bool primary_ikey)
{
    const google::protobuf::Descriptor *pDesc = message.GetDescriptor();
    const google::protobuf::Reflection *pReflect = message.GetReflection();
    if (pDesc == NULL || pReflect == NULL) return;

    for (int i = 0; i < pDesc->field_count(); i++)
    {
        const google::protobuf::FieldDescriptor *pFieldDesc = pDesc->field(i);
        if (pFieldDesc == NULL) continue;
        if (pFieldDesc->options().HasExtension(yd_fieldoptions::no_db_field)) continue;
        if (!pFieldDesc->is_repeated() && pReflect->HasField(message, pFieldDesc) == false) continue;
        if (pFieldDesc->is_repeated() && pReflect->FieldSize(message, pFieldDesc) == 0) continue;

        if (primary_ikey)
        {
            if (pFieldDesc->is_repeated()) continue;
            if (pFieldDesc->cpp_type() == google::protobuf::FieldDescriptor::CPPTYPE_MESSAGE) continue;

            if (!pFieldDesc->options().HasExtension(yd_fieldoptions::db_field_type))
            {
                continue;
            }
            if (pFieldDesc->options().GetExtension(yd_fieldoptions::db_field_type) !=
                ::yd_fieldoptions::message_db_field_type::E_FIELDTYPE_PRIMARYKEY)
            {
                continue;
            }
        }

        //ignore special repeated
        if (ignore_special_repeted)
        {
            if (pFieldDesc->is_repeated() == false)
            {
                mapFields.emplace(pFieldDesc->name(), GetFieldsString(message, pFieldDesc));
            }
        }
        else
        { //handle special repeated
            if (pFieldDesc->is_repeated())
            {
                if (pFieldDesc->cpp_type() != google::protobuf::FieldDescriptor::CPPTYPE_MESSAGE)
                {
                    const google::protobuf::FieldOptions &fieldoptions = pFieldDesc->options();
                    if (fieldoptions.HasExtension(yd_fieldoptions::db_field_arysize))
                    {
                        ::google::protobuf::int32 arysize = fieldoptions.GetExtension(yd_fieldoptions::db_field_arysize);
                        ::google::protobuf::int32 repeatedSize = pReflect->FieldSize(message, pFieldDesc);
                        for (::google::protobuf::int32 a_i = 0; a_i < arysize && a_i < repeatedSize; a_i++)
                        {
                            std::string field = pFieldDesc->name() + "_" + NFCommon::tostr(a_i + 1);
                            mapFields.emplace(field, GetRepeatedFieldsString(message, pFieldDesc, a_i));
                        }
                    }
                }
                else
                {
                    const google::protobuf::FieldOptions &fieldoptions = pFieldDesc->options();
                    if (fieldoptions.HasExtension(yd_fieldoptions::db_field_arysize))
                    {
                        ::google::protobuf::int32 arysize = fieldoptions.GetExtension(yd_fieldoptions::db_field_arysize);
                        ::google::protobuf::int32 repeatedSize = pReflect->FieldSize(message, pFieldDesc);
                        for (::google::protobuf::int32 a_i = 0; a_i < arysize && a_i < repeatedSize; a_i++)
                        {
                            const ::google::protobuf::Message &pSubMessageObject = pReflect->GetRepeatedMessage(message,
                                                                                                                pFieldDesc,
                                                                                                                a_i);
                            const google::protobuf::Descriptor *pSubDesc = pSubMessageObject.GetDescriptor();
                            const google::protobuf::Reflection *pSubReflect = pSubMessageObject.GetReflection();
                            if (pSubDesc == NULL || pSubReflect == NULL) continue;

                            for (int sub_i = 0; sub_i < pSubDesc->field_count(); sub_i++)
                            {
                                const google::protobuf::FieldDescriptor *pSubFieldDesc = pSubDesc->field(sub_i);
                                if (pSubFieldDesc == NULL) continue;
                                if (pSubFieldDesc->is_repeated()) continue;

                                std::string field = pFieldDesc->name() + "_" + NFCommon::tostr(a_i + 1) + "_" +
                                                    pSubFieldDesc->name();
                                mapFields.emplace(field, GetFieldsString(pSubMessageObject, pSubFieldDesc));
                            }

                        }
                    }
                }
            }
            else
            {
                mapFields.emplace(pFieldDesc->name(), GetFieldsString(message, pFieldDesc));
            }
        }
    }
}

void NFProtobufCommon::GetMapFieldsFromMessage(const google::protobuf::Message &message,
                                               std::map<std::string, std::string> &keyMap,
                                               std::map<std::string, std::string> &kevValueMap,
                                               bool ignore_special_repeted)
{
    const google::protobuf::Descriptor *pDesc = message.GetDescriptor();
    const google::protobuf::Reflection *pReflect = message.GetReflection();
    if (pDesc == NULL || pReflect == NULL) return;

    for (int i = 0; i < pDesc->field_count(); i++)
    {
        const google::protobuf::FieldDescriptor *pFieldDesc = pDesc->field(i);
        if (pFieldDesc == NULL) continue;
        if (!pFieldDesc->is_repeated() && pReflect->HasField(message, pFieldDesc) == false) continue;
        if (pFieldDesc->is_repeated() && pReflect->FieldSize(message, pFieldDesc) == 0) continue;

        if (pFieldDesc->options().HasExtension(yd_fieldoptions::db_field_type))
        {
            if (pFieldDesc->options().GetExtension(yd_fieldoptions::db_field_type) ==
                ::yd_fieldoptions::message_db_field_type::E_FIELDTYPE_PRIMARYKEY ||
                pFieldDesc->options().GetExtension(yd_fieldoptions::db_field_type) ==
                ::yd_fieldoptions::message_db_field_type::E_FIELDTYPE_UNIQUE_INDEX)
            {
                keyMap.emplace(pFieldDesc->name(), GetFieldsString(message, pFieldDesc));
            }
        }

        //ignore special repeated
        if (ignore_special_repeted)
        {
            if (pFieldDesc->is_repeated() == false)
            {
                kevValueMap.emplace(pFieldDesc->name(), GetFieldsString(message, pFieldDesc));
            }
        }
        else
        { //handle special repeated
            if (pFieldDesc->is_repeated())
            {
                if (pFieldDesc->cpp_type() != google::protobuf::FieldDescriptor::CPPTYPE_MESSAGE)
                {
                    const google::protobuf::FieldOptions &fieldoptions = pFieldDesc->options();
                    if (fieldoptions.HasExtension(yd_fieldoptions::db_field_arysize))
                    {
                        ::google::protobuf::int32 arysize = fieldoptions.GetExtension(yd_fieldoptions::db_field_arysize);
                        ::google::protobuf::int32 repeatedSize = pReflect->FieldSize(message, pFieldDesc);
                        for (::google::protobuf::int32 a_i = 0; a_i < arysize && a_i < repeatedSize; a_i++)
                        {
                            std::string field = pFieldDesc->name() + "_" + NFCommon::tostr(a_i + 1);
                            kevValueMap.emplace(field, GetRepeatedFieldsString(message, pFieldDesc, a_i));
                        }
                    }
                }
                else
                {
                    const google::protobuf::FieldOptions &fieldoptions = pFieldDesc->options();
                    if (fieldoptions.HasExtension(yd_fieldoptions::db_field_arysize))
                    {
                        ::google::protobuf::int32 arysize = fieldoptions.GetExtension(yd_fieldoptions::db_field_arysize);
                        ::google::protobuf::int32 repeatedSize = pReflect->FieldSize(message, pFieldDesc);
                        for (::google::protobuf::int32 a_i = 0; a_i < arysize && a_i < repeatedSize; a_i++)
                        {
                            const ::google::protobuf::Message &pSubMessageObject = pReflect->GetRepeatedMessage(message,
                                                                                                                pFieldDesc,
                                                                                                                a_i);
                            const google::protobuf::Descriptor *pSubDesc = pSubMessageObject.GetDescriptor();
                            const google::protobuf::Reflection *pSubReflect = pSubMessageObject.GetReflection();
                            if (pSubDesc == NULL || pSubReflect == NULL) continue;

                            for (int sub_i = 0; sub_i < pSubDesc->field_count(); sub_i++)
                            {
                                const google::protobuf::FieldDescriptor *pSubFieldDesc = pSubDesc->field(sub_i);
                                if (pSubFieldDesc == NULL) continue;
                                if (pSubFieldDesc->is_repeated()) continue;

                                std::string field = pFieldDesc->name() + "_" + NFCommon::tostr(a_i + 1) + "_" +
                                                    pSubFieldDesc->name();
                                kevValueMap.emplace(field, GetFieldsString(pSubMessageObject, pSubFieldDesc));
                            }

                        }
                    }
                }
            }
            else
            {
                kevValueMap.emplace(pFieldDesc->name(), GetFieldsString(message, pFieldDesc));
            }
        }
    }
}

void NFProtobufCommon::GetMessageFromMapFields(const std::map<std::string, std::string> &result, google::protobuf::Message *pMessageObject)
{
    if (pMessageObject == NULL) return;
    /* message AttrValue
       {
           optional int32 attr = 1 [(yd_fieldoptions.field_cname) = "attr"];
           optional int32 value = 2 [(yd_fieldoptions.field_cname) = "value"];
           optional string value2 = 3 [(yd_fieldoptions.field_cname) = "value2", (yd_fieldoptions.db_field_bufsize)=128];
       }

       message FishConfigDesc
       {
           optional int32 fish_id = 1 [(yd_fieldoptions.field_cname) = "鱼id", (yd_fieldoptions.db_field_type) = E_FIELDTYPE_PRIMARYKEY];
           optional int32 fish_type = 2 [(yd_fieldoptions.field_cname) = "鱼的玩法类型"];
           optional int32 build_fish_type = 3 [(yd_fieldoptions.field_cname) = "客户端创建鱼类型"];
           optional int32 ratio_max = 4  [(yd_fieldoptions.field_cname) = "倍率最大值"];
           optional int32 double_award_min_ratio = 5  [(yd_fieldoptions.field_cname) = "可能触发双倍奖励所需最低倍率"];
           optional int32 child_fish_count = 6  [(yd_fieldoptions.field_cname) = "组合鱼携带子鱼个数"];
           repeated string child_fish_ids = 7  [(yd_fieldoptions.field_cname) = "组合鱼位置可选子鱼id列表", (yd_fieldoptions.field_bufsize)=128, (yd_fieldoptions.db_field_bufsize)=128, (yd_fieldoptions.field_arysize) = 6];
           repeated AttrValue attr_values = 8 [(yd_fieldoptions.field_cname) = "attr_values", (yd_fieldoptions.field_arysize)=2];
       }

       如上，将一个result结果， 转化为protobuf的message, 比如FishConfigDesc, 代表这数据库FishConfigDesc或Excel表格中的一列
    */
    const google::protobuf::Descriptor *pMessageObjectFieldDesc = pMessageObject->GetDescriptor();
    const google::protobuf::Reflection *pMessageObjectReflect = pMessageObject->GetReflection();
    if (pMessageObjectFieldDesc == NULL || pMessageObjectReflect == NULL) return;

    for (int i = 0; i < pMessageObjectFieldDesc->field_count(); i++)
    {
        const google::protobuf::FieldDescriptor *pFieldDesc = pMessageObjectFieldDesc->field(i);
        if (pFieldDesc == NULL) continue;
        //如果不是repeated, 只是简单信息，就直接给
        if (pFieldDesc->is_repeated() == false)
        {
            std::string field = pFieldDesc->name();
            auto iter = result.find(field);
            if (iter != result.end())
            {
                NFProtobufCommon::SetFieldsString(*pMessageObject, pFieldDesc, iter->second);
            }
        }
        else
        {
            //如果只是简单的repeated, 比如:repeated string child_fish_ids = 7
            //把数据库里的多行，搞成数组的形式
            if (pFieldDesc->cpp_type() != google::protobuf::FieldDescriptor::CPPTYPE_MESSAGE)
            {
                const google::protobuf::FieldOptions &fieldoptions = pFieldDesc->options();
                if (fieldoptions.HasExtension(yd_fieldoptions::db_field_arysize))
                {
                    ::google::protobuf::int32 arysize = fieldoptions.GetExtension(yd_fieldoptions::db_field_arysize);
                    for (::google::protobuf::int32 a_i = 0; a_i < arysize; a_i++)
                    {
                        std::string field = pFieldDesc->name() + "_" + NFCommon::tostr(a_i + 1);

                        auto iter = result.find(field);
                        if (iter != result.end())
                        {
                            NFProtobufCommon::AddFieldsString(*pMessageObject, pFieldDesc, iter->second);
                        }
                    }
                }
            }
            else
            {
                //如果只是复杂的repeated, 比如:
                //message AttrValue
                //{
                //	optional int32 attr = 1 [(yd_fieldoptions.field_cname) = "attr"];
                //	optional int32 value = 2 [(yd_fieldoptions.field_cname) = "value"];
                //	optional string value2 = 3 [(yd_fieldoptions.field_cname) = "value2", (yd_fieldoptions.db_field_bufsize)=128];
                //}
                //repeated AttrValue attr_values = 8 [(yd_fieldoptions.field_cname) = "attr_values", (yd_fieldoptions.field_arysize)=2];
                //把数据库里的多行，配合结构转成repeated数组
                const google::protobuf::Descriptor *pSubDescriptor = pFieldDesc->message_type();
                if (pSubDescriptor == NULL) continue;
                const google::protobuf::FieldOptions &fieldoptions = pFieldDesc->options();

                if (fieldoptions.HasExtension(yd_fieldoptions::db_field_arysize))
                {
                    ::google::protobuf::int32 arysize = fieldoptions.GetExtension(yd_fieldoptions::db_field_arysize);
                    for (::google::protobuf::int32 a_i = 0; a_i < arysize; a_i++)
                    {
                        ::google::protobuf::Message *pSubMessageObject = pMessageObjectReflect->AddMessage(pMessageObject, pFieldDesc);
                        if (pSubMessageObject == NULL) continue;
                        for (int field_i = 0; field_i < pSubDescriptor->field_count(); field_i++)
                        {
                            const google::protobuf::FieldDescriptor *pSubFieldDesc = pSubDescriptor->field(field_i);
                            if (pSubFieldDesc == NULL) continue;
                            if (pSubFieldDesc->is_repeated() == false)
                            {
                                std::string field = pFieldDesc->name() + "_" + NFCommon::tostr(a_i + 1) + "_" + pSubFieldDesc->name();

                                auto iter = result.find(field);
                                if (iter != result.end())
                                {
                                    NFProtobufCommon::SetFieldsString(*pSubMessageObject, pSubFieldDesc, iter->second);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}

bool NFProtobufCommon::ProtoMessageToJson(const google::protobuf::Message &message,
                                          std::string *json,
                                          std::string *error)
{
    return NFJson2PB::ProtoMessageToJson(message, json, error);
}

bool NFProtobufCommon::ProtoMessageToJson(const google::protobuf::Message &message,
                                          google::protobuf::io::ZeroCopyOutputStream *json,
                                          std::string *error)
{
    return NFJson2PB::ProtoMessageToJson(message, json, error);
}

bool NFProtobufCommon::JsonToProtoMessage(const std::string &json,
                                          google::protobuf::Message *message,
                                          std::string *error)
{
    return NFJson2PB::JsonToProtoMessage(json, message, error);
}

bool NFProtobufCommon::JsonToProtoMessage(google::protobuf::io::ZeroCopyInputStream *stream,
                                          google::protobuf::Message *message,
                                          std::string *error)
{

    return NFJson2PB::JsonToProtoMessage(stream, message, error);
}

bool NFProtobufCommon::LuaToProtoMessage(NFLuaRef luaRef, google::protobuf::Message *pMessageObject)
{
    if (pMessageObject == NULL) return false;
    if (!luaRef.isTable()) return false;

    const google::protobuf::Descriptor *pMessageObjectFieldDesc = pMessageObject->GetDescriptor();
    const google::protobuf::Reflection *pMessageObjectReflect = pMessageObject->GetReflection();
    if (pMessageObjectFieldDesc == NULL || pMessageObjectReflect == NULL) return false;

    for (int i = 0; i < pMessageObjectFieldDesc->field_count(); i++)
    {
        const google::protobuf::FieldDescriptor *pFieldDesc = pMessageObjectFieldDesc->field(i);
        if (pFieldDesc == NULL) continue;
        const google::protobuf::Reflection *pReflect = pMessageObject->GetReflection();
        if (pReflect == nullptr || pFieldDesc == nullptr) continue;

        //如果不是repeated, 只是简单信息，就直接给
        if (pFieldDesc->is_repeated() == false)
        {
            std::string field = pFieldDesc->name();
            switch (pFieldDesc->cpp_type())
            {
                case google::protobuf::FieldDescriptor::CPPTYPE_INT32:
                {
                    int32_t value = 0;
                    if (luaRef.has(field) && NFILuaLoader::GetLuaTableValue(luaRef, field, value))
                    {
                        pReflect->SetInt32(pMessageObject, pFieldDesc, value);
                    }
                }
                    break;
                case google::protobuf::FieldDescriptor::CPPTYPE_INT64:
                {
                    int64_t value = 0;
                    if (luaRef.has(field) && NFILuaLoader::GetLuaTableValue(luaRef, field, value))
                    {
                        pReflect->SetInt64(pMessageObject, pFieldDesc, value);
                    }
                }
                    break;
                case google::protobuf::FieldDescriptor::CPPTYPE_UINT32:
                {
                    uint32_t value = 0;
                    if (luaRef.has(field) && NFILuaLoader::GetLuaTableValue(luaRef, field, value))
                    {
                        pReflect->SetUInt32(pMessageObject, pFieldDesc, value);
                    }
                }
                    break;
                case google::protobuf::FieldDescriptor::CPPTYPE_UINT64:
                {
                    uint64_t value = 0;
                    if (luaRef.has(field) && NFILuaLoader::GetLuaTableValue(luaRef, field, value))
                    {
                        pReflect->SetUInt64(pMessageObject, pFieldDesc, value);
                    }
                }
                    break;
                case google::protobuf::FieldDescriptor::CPPTYPE_DOUBLE:
                {
                    double value = 0;
                    if (luaRef.has(field) && NFILuaLoader::GetLuaTableValue(luaRef, field, value))
                    {
                        pReflect->SetDouble(pMessageObject, pFieldDesc, value);
                    }
                }
                    break;
                case google::protobuf::FieldDescriptor::CPPTYPE_FLOAT:
                {
                    float value = 0;
                    if (luaRef.has(field) && NFILuaLoader::GetLuaTableValue(luaRef, field, value))
                    {
                        pReflect->SetFloat(pMessageObject, pFieldDesc, value);
                    }
                }
                    break;
                case google::protobuf::FieldDescriptor::CPPTYPE_BOOL:
                {
                    bool value = false;
                    if (luaRef.has(field) && NFILuaLoader::GetLuaTableValue(luaRef, field, value))
                    {
                        pReflect->SetBool(pMessageObject, pFieldDesc, value);
                    }
                }
                    break;
                case google::protobuf::FieldDescriptor::CPPTYPE_ENUM:
                {
                    int value = 0;
                    if (luaRef.has(field) && NFILuaLoader::GetLuaTableValue(luaRef, field, value))
                    {
                        const google::protobuf::EnumDescriptor *pEnumDesc = pFieldDesc->enum_type();
                        const google::protobuf::EnumValueDescriptor *pEnumValueDesc = pEnumDesc->FindValueByNumber(
                                value);
                        pReflect->SetEnum(pMessageObject, pFieldDesc, pEnumValueDesc);
                    }
                }
                    break;
                case google::protobuf::FieldDescriptor::CPPTYPE_STRING:
                {
                    std::string value;
                    if (luaRef.has(field) && NFILuaLoader::GetLuaTableValue(luaRef, field, value))
                    {
                        pReflect->SetString(pMessageObject, pFieldDesc, value);
                    }
                }
                    break;
                case google::protobuf::FieldDescriptor::CPPTYPE_MESSAGE:
                {
                    LuaIntf::LuaRef valueRef = luaRef[field];
                    if (valueRef.isTable())
                    {
                        google::protobuf::Message *pMutableMessage = pReflect->MutableMessage(pMessageObject, pFieldDesc);
                        LuaToProtoMessage(valueRef, pMutableMessage);
                    }
                }
            }
        }
        else
        {
            if (luaRef.isTable())
            {
                std::string field = pFieldDesc->name();
                NFLuaRef listRef;
                if (!NFILuaLoader::GetLuaTableValue(luaRef, field, listRef))
                {
                    continue;
                }

                for (int j = 1; j <= listRef.len(); j++)
                {
                    switch (pFieldDesc->cpp_type())
                    {
                        case google::protobuf::FieldDescriptor::CPPTYPE_INT32:
                        {
                            int32_t value = 0;
                            if (NFILuaLoader::GetLuaTableValue(listRef, j, value))
                            {
                                pReflect->AddInt32(pMessageObject, pFieldDesc, value);
                            }
                        }
                            break;
                        case google::protobuf::FieldDescriptor::CPPTYPE_INT64:
                        {
                            int64_t value = 0;
                            if (NFILuaLoader::GetLuaTableValue(listRef, j, value))
                            {
                                pReflect->AddInt64(pMessageObject, pFieldDesc, value);
                            }
                        }
                            break;
                        case google::protobuf::FieldDescriptor::CPPTYPE_UINT32:
                        {
                            uint32_t value = 0;
                            if (NFILuaLoader::GetLuaTableValue(listRef, j, value))
                            {
                                pReflect->AddUInt32(pMessageObject, pFieldDesc, value);
                            }
                        }
                            break;
                        case google::protobuf::FieldDescriptor::CPPTYPE_UINT64:
                        {
                            uint64_t value = 0;
                            if (NFILuaLoader::GetLuaTableValue(listRef, j, value))
                            {
                                pReflect->AddUInt64(pMessageObject, pFieldDesc, value);
                            }
                        }
                            break;
                        case google::protobuf::FieldDescriptor::CPPTYPE_DOUBLE:
                        {
                            double value = 0;
                            if (NFILuaLoader::GetLuaTableValue(listRef, j, value))
                            {
                                pReflect->AddDouble(pMessageObject, pFieldDesc, value);
                            }
                        }
                            break;
                        case google::protobuf::FieldDescriptor::CPPTYPE_FLOAT:
                        {
                            float value = 0;
                            if (NFILuaLoader::GetLuaTableValue(listRef, j, value))
                            {
                                pReflect->AddFloat(pMessageObject, pFieldDesc, value);
                            }
                        }
                            break;
                        case google::protobuf::FieldDescriptor::CPPTYPE_BOOL:
                        {
                            bool value = false;
                            if (NFILuaLoader::GetLuaTableValue(listRef, j, value))
                            {
                                pReflect->AddBool(pMessageObject, pFieldDesc, value);
                            }
                        }
                            break;
                        case google::protobuf::FieldDescriptor::CPPTYPE_ENUM:
                        {
                            int value = 0;
                            if (NFILuaLoader::GetLuaTableValue(listRef, j, value))
                            {
                                const google::protobuf::EnumDescriptor *pEnumDesc = pFieldDesc->enum_type();
                                const google::protobuf::EnumValueDescriptor *pEnumValueDesc = pEnumDesc->FindValueByNumber(value);
                                pReflect->AddEnum(pMessageObject, pFieldDesc, pEnumValueDesc);
                            }
                        }
                            break;
                        case google::protobuf::FieldDescriptor::CPPTYPE_STRING:
                        {
                            std::string value;
                            if (NFILuaLoader::GetLuaTableValue(listRef, j, value))
                            {
                                pReflect->AddString(pMessageObject, pFieldDesc, value);
                            }
                        }
                            break;
                        case google::protobuf::FieldDescriptor::CPPTYPE_MESSAGE:
                        {
                            NFLuaRef value;
                            if (NFILuaLoader::GetLuaTableValue(listRef, j, value))
                            {
                                google::protobuf::Message *pSubMessage = pReflect->AddMessage(pMessageObject, pFieldDesc);
                                LuaToProtoMessage(value, pSubMessage);
                            }
                        }
                            break;
                        default:
                            break;
                    }
                }
            }
        }
    }
    return true;
}

bool
NFProtobufCommon::ProtoMessageToXml(const google::protobuf::Message &message, std::string *json)
{
    CHECK_EXPR(json, false, "json == NULL");
    NFXmlMessageCodec codec;
    std::string result;
    bool ret = codec.ToString(message, result);
    if (ret == false)
    {
        return false;
    }
    ret = codec.PrettyString(result, *json);
    if (ret == false)
    {
        return false;
    }
    return ret;
}

bool NFProtobufCommon::XmlToProtoMessage(const string &json, google::protobuf::Message *message)
{
    CHECK_EXPR(message, false, "message == NULL");
    NFXmlMessageCodec codec;
    bool ret = codec.FromString(json, *message);
    if (ret == false)
    {
        return false;
    }

    return ret;
}

int NFProtobufCommon::GetMessageFromGetHttp(google::protobuf::Message *pSrcMessage, const NFIHttpHandle &req)
{
    if (!pSrcMessage) return -1;

    const google::protobuf::Descriptor *pSrcDesc = pSrcMessage->GetDescriptor();
    if (!pSrcDesc) return -1;

    for (int i = 0; i < pSrcDesc->field_count(); i++)
    {
        const google::protobuf::FieldDescriptor *pSrcFieldDesc = pSrcDesc->field(i);
        if (pSrcFieldDesc == NULL) continue;

        std::string strValue = req.GetQuery(pSrcFieldDesc->lowercase_name());
        SetFieldsString(*pSrcMessage, pSrcFieldDesc, strValue);
    }

    return 0;
}

NFProtobufCommon::NFProtobufCommon()
{
    m_pDynamicMessageFactory = new google::protobuf::DynamicMessageFactory();
    m_pDescriptorPool = new google::protobuf::DescriptorPool();
}

NFProtobufCommon::~NFProtobufCommon()
{
    NF_SAFE_DELETE(m_pDynamicMessageFactory);
    NF_SAFE_DELETE(m_pDescriptorPool);
    for(int i = 0; i < (int)m_pOldPoolVec.size(); i++)
    {
        NF_SAFE_DELETE(m_pOldPoolVec[i]);
    }
    m_pOldPoolVec.clear();
}


int NFProtobufCommon::LoadProtoDsFile(const std::string &ds)
{
    std::ifstream pb_file(ds.c_str(), std::ios::binary);
    if (!pb_file.is_open())
    {
        return -1;
    }

    google::protobuf::FileDescriptorSet file_descriptor_set;
    if (!file_descriptor_set.ParseFromIstream(&pb_file))
    {
        return -1;
    }

    if (m_fileMd5.empty())
    {
        for (int i = 0; i < file_descriptor_set.file_size(); ++i)
        {
            auto pResult = m_pDescriptorPool->BuildFile(file_descriptor_set.file(i));
            CHECK_EXPR(pResult, -1, "pResult == NULL, load file:{} failed", ds);
        }

        NFFileUtility::GetFileContainMD5(ds, m_fileMd5);
    }
    else
    {
        std::string md5;
        NFFileUtility::GetFileContainMD5(ds, md5);
        if (m_fileMd5 != md5)
        {
            m_fileMd5 = md5;
            m_pOldPoolVec.push_back(m_pDescriptorPool);
            m_pDescriptorPool = new google::protobuf::DescriptorPool();
            for (int i = 0; i < file_descriptor_set.file_size(); ++i)
            {
                auto pResult = m_pDescriptorPool->BuildFile(file_descriptor_set.file(i));
                CHECK_EXPR(pResult, -1, "pResult == NULL, load file:{} failed", ds);
            }
        }
    }

    return 0;
}

const google::protobuf::Descriptor *NFProtobufCommon::FindDynamicMessageTypeByName(const std::string &full_name)
{
    return m_pDescriptorPool->FindMessageTypeByName(full_name);
}

::google::protobuf::Message *NFProtobufCommon::CreateDynamicMessageByName(const std::string &full_name)
{
    const google::protobuf::Descriptor *pDescriptor = m_pDescriptorPool->FindMessageTypeByName(
            full_name);
    if (pDescriptor)
    {
        const ::google::protobuf::Message *pMessageType = m_pDynamicMessageFactory->GetPrototype(pDescriptor);
        if (pMessageType)
        {
            return pMessageType->New();
        }
    }

    return NULL;
}

int NFProtobufCommon::GetDbFieldsInfoFromMessage(const google::protobuf::Descriptor *pDesc, std::map<std::string, DBTableColInfo> &primaryKeyMap, std::map<std::string, DBTableColInfo> &mapFileds)
{
    CHECK_NULL(pDesc);

    for (int i = 0; i < pDesc->field_count(); i++)
    {
        const google::protobuf::FieldDescriptor *pFieldDesc = pDesc->field(i);
        if (pFieldDesc == NULL) continue;
        if (pFieldDesc->options().HasExtension(yd_fieldoptions::no_db_field)) continue;

        //如果不是repeated, 只是简单信息，就直接给
        if (pFieldDesc->is_repeated() == false)
        {
            DBTableColInfo colInfo;
            colInfo.m_colType = pFieldDesc->cpp_type();
            colInfo.m_fieldIndex = i;
            if (pFieldDesc->options().HasExtension(yd_fieldoptions::db_field_type))
            {
                if (pFieldDesc->options().GetExtension(yd_fieldoptions::db_field_type) ==
                    ::yd_fieldoptions::message_db_field_type::E_FIELDTYPE_PRIMARYKEY)
                {
                    colInfo.m_primaryKey = true;
                    colInfo.m_notNull = true;

                    if (pFieldDesc->options().HasExtension(yd_fieldoptions::db_field_auto_increment))
                    {
                        colInfo.m_autoIncrement = pFieldDesc->options().GetExtension(yd_fieldoptions::db_field_auto_increment);
                        if (pFieldDesc->options().HasExtension(yd_fieldoptions::db_field_auto_increment_value))
                        {
                            colInfo.m_autoIncrementValue = pFieldDesc->options().GetExtension(yd_fieldoptions::db_field_auto_increment_value);
                        }
                    }
                }
                else if (pFieldDesc->options().GetExtension(yd_fieldoptions::db_field_type) ==
                         ::yd_fieldoptions::message_db_field_type::E_FIELDTYPE_UNIQUE_INDEX)
                {
                    colInfo.m_unionKey = true;
                }
                else if (pFieldDesc->options().GetExtension(yd_fieldoptions::db_field_type) ==
                         ::yd_fieldoptions::message_db_field_type::E_FIELDTYPE_INDEX)
                {
                    colInfo.m_indexKey = true;
                }
            }

            if (colInfo.m_colType == google::protobuf::FieldDescriptor::CPPTYPE_STRING || colInfo.m_colType == google::protobuf::FieldDescriptor::CPPTYPE_MESSAGE)
            {
                if (pFieldDesc->options().HasExtension(yd_fieldoptions::db_field_bufsize))
                {
                    colInfo.m_bufsize = pFieldDesc->options().GetExtension(yd_fieldoptions::db_field_bufsize);
                }
            }

            if (pFieldDesc->options().HasExtension(yd_fieldoptions::db_field_not_null))
            {
                colInfo.m_notNull = pFieldDesc->options().GetExtension(yd_fieldoptions::db_field_not_null);
            }


            if (pFieldDesc->options().HasExtension(yd_fieldoptions::db_field_comment))
            {
                colInfo.m_comment = pFieldDesc->options().GetExtension(yd_fieldoptions::db_field_comment);
            }

            if (colInfo.m_primaryKey)
            {
                primaryKeyMap.emplace(pFieldDesc->name(), colInfo);
            }
            else {
                mapFileds.emplace(pFieldDesc->name(), colInfo);
            }
        }
        else
        {
            //如果只是简单的repeated, 比如:repeated string child_fish_ids = 7
            //把数据库里的多行，搞成数组的形式
            if (pFieldDesc->cpp_type() != google::protobuf::FieldDescriptor::CPPTYPE_MESSAGE)
            {
                const google::protobuf::FieldOptions &fieldoptions = pFieldDesc->options();
                if (fieldoptions.HasExtension(yd_fieldoptions::db_field_arysize))
                {
                    ::google::protobuf::int32 arysize = fieldoptions.GetExtension(yd_fieldoptions::db_field_arysize);
                    for (::google::protobuf::int32 a_i = 0; a_i < arysize; a_i++)
                    {
                        DBTableColInfo colInfo;
                        colInfo.m_colType = pFieldDesc->cpp_type();
                        colInfo.m_fieldIndex = i;
                        std::string field = pFieldDesc->name() + "_" + NFCommon::tostr(a_i + 1);

                        if (colInfo.m_colType == google::protobuf::FieldDescriptor::CPPTYPE_STRING || colInfo.m_colType == google::protobuf::FieldDescriptor::CPPTYPE_MESSAGE)
                        {
                            if (pFieldDesc->options().HasExtension(yd_fieldoptions::db_field_bufsize))
                            {
                                colInfo.m_bufsize = pFieldDesc->options().GetExtension(yd_fieldoptions::db_field_bufsize);
                            }
                        }

                        if (pFieldDesc->options().HasExtension(yd_fieldoptions::db_field_not_null))
                        {
                            colInfo.m_notNull = pFieldDesc->options().GetExtension(yd_fieldoptions::db_field_not_null);
                        }

                        mapFileds.emplace(field, colInfo);
                    }
                }
            }
            else
            {
                //如果只是复杂的repeated, 比如:
                //message AttrValue
                //{
                //	optional int32 attr = 1 [(yd_fieldoptions.field_cname) = "attr"];
                //	optional int32 value = 2 [(yd_fieldoptions.field_cname) = "value"];
                //	optional string value2 = 3 [(yd_fieldoptions.field_cname) = "value2", (yd_fieldoptions.db_field_bufsize)=128];
                //}
                //repeated AttrValue attr_values = 8 [(yd_fieldoptions.field_cname) = "attr_values", (yd_fieldoptions.field_arysize)=2];
                //把数据库里的多行，配合结构转成repeated数组
                const google::protobuf::Descriptor *pSubDescriptor = pFieldDesc->message_type();
                if (pSubDescriptor == NULL) continue;
                const google::protobuf::FieldOptions &fieldoptions = pFieldDesc->options();

                if (fieldoptions.HasExtension(yd_fieldoptions::db_field_arysize))
                {
                    ::google::protobuf::int32 arysize = fieldoptions.GetExtension(yd_fieldoptions::db_field_arysize);
                    for (::google::protobuf::int32 a_i = 0; a_i < arysize; a_i++)
                    {
                        for (int field_i = 0; field_i < pSubDescriptor->field_count(); field_i++)
                        {
                            const google::protobuf::FieldDescriptor *pSubFieldDesc = pSubDescriptor->field(field_i);
                            if (pSubFieldDesc == NULL) continue;
                            if (pSubFieldDesc->is_repeated() == false)
                            {
                                DBTableColInfo colInfo;
                                colInfo.m_colType = pSubFieldDesc->cpp_type();
                                colInfo.m_fieldIndex = i;

                                std::string field = pFieldDesc->name() + "_" + NFCommon::tostr(a_i + 1) + "_" + pSubFieldDesc->name();

                                if (colInfo.m_colType == google::protobuf::FieldDescriptor::CPPTYPE_STRING || colInfo.m_colType == google::protobuf::FieldDescriptor::CPPTYPE_MESSAGE)
                                {
                                    if (pSubFieldDesc->options().HasExtension(yd_fieldoptions::db_field_bufsize))
                                    {
                                        colInfo.m_bufsize = pSubFieldDesc->options().GetExtension(yd_fieldoptions::db_field_bufsize);
                                    }
                                }

                                if (pSubFieldDesc->options().HasExtension(yd_fieldoptions::db_field_not_null))
                                {
                                    colInfo.m_notNull = pSubFieldDesc->options().GetExtension(yd_fieldoptions::db_field_not_null);
                                }

                                mapFileds.emplace(field, colInfo);
                            }
                        }
                    }
                }
            }
        }
    }

    return 0;
}

uint32_t NFProtobufCommon::GetPBDataTypeFromDBDataType(const std::string& dbDataType, const std::string& strColumnType)
{
    if (dbDataType == "varchar" || dbDataType == "char" || dbDataType == "tinytext" || dbDataType == "text" || dbDataType == "mediumtext" || dbDataType == "longtext")
    {
        return google::protobuf::FieldDescriptor::CPPTYPE_STRING;
    }
    else if (dbDataType == "int" || dbDataType == "tinyint" || dbDataType == "smallint" || dbDataType == "mediumint")
    {
        if (strColumnType.find("unsigned") != std::string::npos)
        {
            return google::protobuf::FieldDescriptor::CPPTYPE_UINT32;
        }
        else {
            return google::protobuf::FieldDescriptor::CPPTYPE_INT32;
        }
    }
    else if (dbDataType == "float")
    {
        return google::protobuf::FieldDescriptor::CPPTYPE_FLOAT;
    }
    else if (dbDataType == "double")
    {
        return google::protobuf::FieldDescriptor::CPPTYPE_DOUBLE;
    }
    else if (dbDataType == "enum")
    {
        return google::protobuf::FieldDescriptor::CPPTYPE_INT32;
    }
    else if (dbDataType == "bigint" || dbDataType == "datetime")
    {
        if (strColumnType.find("unsigned") != std::string::npos)
        {
            return google::protobuf::FieldDescriptor::CPPTYPE_UINT64;
        }
        else {
            return google::protobuf::FieldDescriptor::CPPTYPE_INT64;
        }
    }
    else if (dbDataType == "blob" || dbDataType == "varbinary" || dbDataType == "tinyblob" || dbDataType == "mediumblob" || dbDataType == "longblob")
    {
        return google::protobuf::FieldDescriptor::CPPTYPE_MESSAGE;
    }

    return google::protobuf::FieldDescriptor::CPPTYPE_STRING;
}

std::string NFProtobufCommon::GetDBDataTypeFromPBDataType(uint32_t pbDataType, uint32_t textMax)
{
    switch(pbDataType)
    {
        case google::protobuf::FieldDescriptor::CPPTYPE_INT32:
        {
            return "int";
        }
            break;
        case google::protobuf::FieldDescriptor::CPPTYPE_INT64:
        {
            return "bigint";
        }
            break;
        case google::protobuf::FieldDescriptor::CPPTYPE_UINT32:
        {
            return "int unsigned";
        }
            break;
        case google::protobuf::FieldDescriptor::CPPTYPE_UINT64:
        {
            return "bigint unsigned";
        }
            break;
        case google::protobuf::FieldDescriptor::CPPTYPE_DOUBLE:
        {
            return "double";
        }
            break;
        case google::protobuf::FieldDescriptor::CPPTYPE_FLOAT:
        {
            return "float";
        }
            break;
        case google::protobuf::FieldDescriptor::CPPTYPE_BOOL:
        {
            return "int";
        }
            break;
        case google::protobuf::FieldDescriptor::CPPTYPE_ENUM:
        {
            return "int";
        }
            break;
        case google::protobuf::FieldDescriptor::CPPTYPE_STRING:
        {
            return "varchar(" + NFCommon::tostr(textMax) + ")";
        }
            break;
        case google::protobuf::FieldDescriptor::CPPTYPE_MESSAGE:
        {
            if (textMax > 16777216)
            {
                return "LONGBLOB";
            }
            else if (textMax > 65535)
            {
                return "MEDIUMBLOB";
            }
            else {
                return "blob";
            }
        }
    }

    return "int";
}