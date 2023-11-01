// -------------------------------------------------------------------------
//    @FileName         :    ExcelToBin.cpp
//    @Author           :    gaoyi
//    @Date             :    23-8-26
//    @Email			:    445267987@qq.com
//    @Module           :    ExcelToBin
//
// -------------------------------------------------------------------------

#include "ExcelToBin.h"
#include "NFComm/NFPluginModule/NFProtobufCommon.h"

ExcelToBin::ExcelToBin()
{
}

ExcelToBin::~ExcelToBin()
{
}

int ExcelToBin::Init(const std::string &excel, const std::string &outPath, const std::string &proto_ds)
{
    int iRet = ExcelParse::Init(excel, outPath);
    if (iRet != 0)
    {
        return iRet;
    }

    m_proto_ds = proto_ds;
    iRet = NFProtobufCommon::Instance()->LoadProtoDsFile(m_proto_ds);
    if (iRet == 0)
    {
        NFLogInfo(NF_LOG_SYSTEMLOG, 0, "Reload proto ds success:{}", m_proto_ds);
    }
    else
    {
        NFLogInfo(NF_LOG_SYSTEMLOG, 0, "Reload proto ds fail:{}", m_proto_ds);
        return iRet;
    }

    return 0;
}

int ExcelToBin::HandleExcel()
{
    int iRet = ExcelParse::HandleExcel();
    if (iRet != 0)
    {
        return iRet;
    }

    OnHandleSheetProtoInfo();
    iRet = WriteToBin();
    if (iRet != 0)
    {
        return iRet;
    }
    return 0;
}

void ExcelToBin::OnHandleSheetProtoInfo()
{
    for (auto iter = m_sheets.begin(); iter != m_sheets.end(); iter++)
    {
        ExcelSheet &sheet = iter->second;
        OnHandleSheetProtoInfo(sheet);
    }
}

int ExcelToBin::WriteToBin()
{
    for (auto iter = m_sheets.begin(); iter != m_sheets.end(); iter++)
    {
        ExcelSheet &sheet = iter->second;
        if (sheet.m_colInfoMap.empty()) continue;

        int iRet = WriteToBin(sheet);
        if (iRet != 0)
        {
            return iRet;
        }
    }
    return 0;
}

void ExcelToBin::OnHandleSheetProtoInfo(ExcelSheet &sheet)
{
    sheet.m_protoInfo.m_sheetMsgName = "Sheet_" + NFStringUtility::Capitalize(m_excelName) + NFStringUtility::Capitalize(sheet.m_name);
    sheet.m_protoInfo.m_sheetName = sheet.m_name;
    sheet.m_protoInfo.m_protoMsgName = "E_" + NFStringUtility::Capitalize(m_excelName) + NFStringUtility::Capitalize(sheet.m_name);
}

int ExcelToBin::WriteToBin(ExcelSheet &sheet)
{
    std::string full_name = sheet.m_protoInfo.m_protoPackage + "." + sheet.m_protoInfo.m_sheetMsgName;
    auto pSheetProto = NFProtobufCommon::Instance()->CreateDynamicMessageByName(full_name);
    CHECK_EXPR(pSheetProto, -1, "CreateDynamicMessageByName:{} Failed", full_name);

    const google::protobuf::Descriptor *pDesc = pSheetProto->GetDescriptor();
    CHECK_EXPR(pDesc, -1, "GetDescriptor:{} Failed", full_name);
    const google::protobuf::Reflection *pReflect = pSheetProto->GetReflection();
    CHECK_EXPR(pReflect, -1, "pReflect:{} Failed", full_name);

    std::string proto_sheet_repeatedfieldname = sheet.m_protoInfo.m_protoMsgName + "_List";
    const google::protobuf::FieldDescriptor *pFieldDesc = pDesc->FindFieldByName(proto_sheet_repeatedfieldname);
    CHECK_EXPR(pReflect, -1, "{} Can't find field:{} Failed", full_name, proto_sheet_repeatedfieldname);
    CHECK_EXPR(pFieldDesc->is_repeated(), -1, "{} field:{} is not repeated", full_name, proto_sheet_repeatedfieldname);
    CHECK_EXPR(pFieldDesc->cpp_type() == google::protobuf::FieldDescriptor::CPPTYPE_MESSAGE, -1, "{} field:{} is not message", full_name,
               proto_sheet_repeatedfieldname);


    for (int i = sheet.m_protoInfo.m_startRow; i < (int) sheet.m_rows + 4; i++)
    {
        int iRet = WriteToBin(sheet, i, pSheetProto, pReflect, pFieldDesc);
        if (iRet != 0)
        {
            return iRet;
        }
    }

    std::string bin_file = m_outPath + sheet.m_protoInfo.m_protoMsgName + ".bin";
    std::string content = pSheetProto->SerializeAsString();
    NFFileUtility::WriteFile(bin_file, content);

    if (sheet.m_createSql)
    {
        WriteToSql(sheet, pSheetProto);
    }
    return 0;
}

int ExcelToBin::WriteToBin(ExcelSheet &sheet, int row, google::protobuf::Message *pSheetProto, const google::protobuf::Reflection *pReflect, const google::protobuf::FieldDescriptor *pFieldDesc)
{
    MiniExcelReader::Sheet *pExcelSheet = m_excelReader->getSheet(sheet.m_name);
    CHECK_EXPR(pExcelSheet, -1, "excel:{} Can't find sheet:{} data", m_excel, sheet.m_name);
    std::unordered_map<std::string, std::string> mapFields;
    for (auto iter = sheet.m_allColInfoList.begin(); iter != sheet.m_allColInfoList.end(); iter++)
    {
        int col = iter->first;
        auto pCell = pExcelSheet->getCell(row, col);
        CHECK_EXPR(pCell, -1, "excel:{} can't get data, row:{} col:{}", row, col);
        std::string value = pCell->to_string();
        NFStringUtility::Trim(value);
        ExcelSheetColIndex &sheelColIndex = iter->second;
        ExcelSheetColInfo *pColInfo = sheelColIndex.m_pColInfo;

        if (iter == sheet.m_allColInfoList.begin())
        {
            if (value.empty())
            {
                return 0;
            }
        }

        /**
         * @brief  不是数组，最正常的数据
         */
        if (pColInfo->m_maxSubNum == 0 && pColInfo->m_subInfoMap.empty())
        {
            std::string field = "m_" + pColInfo->m_structEnName;
            mapFields.emplace(field, value);
        }
            /**
             * @brief 简单数组， repeated int32 a 表 itemid itemid
             */
        else if (pColInfo->m_maxSubNum > 0 && pColInfo->m_subInfoMap.empty())
        {
            std::string field =
                    "m_" + pColInfo->m_structEnName + "_" + NFCommon::tostr(sheelColIndex.m_structNum);
            mapFields.emplace(field, value);
        }
        else if (pColInfo->m_maxSubNum > 0 && !pColInfo->m_subInfoMap.empty())
        {
            std::string field =
                    "m_" + pColInfo->m_structEnName + "_" + NFCommon::tostr(sheelColIndex.m_structNum) + "_" +
                    "m_" + sheelColIndex.m_structSubEnName;
            mapFields.emplace(field, value);
        }
        else
        {
            CHECK_EXPR(false, -1, "excel:{} row:{} col:{} can't parse", row, col);
        }
    }

    bool allEmpty = true;
    for(auto iter = mapFields.begin(); iter != mapFields.end(); iter++)
    {
        if (!iter->second.empty())
        {
            allEmpty = false;
            break;
        }
    }
    
    if (allEmpty) return 0;

    google::protobuf::Message *pRowMessage = pReflect->AddMessage(pSheetProto, pFieldDesc);
    CHECK_EXPR(pRowMessage, -1, "{} addfield:{} Failed", pSheetProto->GetTypeName(), pFieldDesc->full_name());
    NFProtobufCommon::GetMessageFromMapFields(mapFields, pRowMessage);

    //NFLogInfo(NF_LOG_SYSTEMLOG, 0, "row:{} {}", row, pRowMessage->Utf8DebugString());

    return 0;
}

int ExcelToBin::WriteToSql(ExcelSheet& sheet, const google::protobuf::Message *pSheetProto)
{
    std::string full_name = sheet.m_protoInfo.m_protoPackage + "." + sheet.m_protoInfo.m_sheetMsgName;

    const google::protobuf::Descriptor *pDesc = pSheetProto->GetDescriptor();
    CHECK_EXPR(pDesc, -1, "GetDescriptor:{} Failed", full_name);
    const google::protobuf::Reflection *pReflect = pSheetProto->GetReflection();
    CHECK_EXPR(pReflect, -1, "pReflect:{} Failed", full_name);

    std::string proto_sheet_repeatedfieldname = sheet.m_protoInfo.m_protoMsgName + "_List";
    const google::protobuf::FieldDescriptor *pFieldDesc = pDesc->FindFieldByName(proto_sheet_repeatedfieldname);
    CHECK_EXPR(pReflect, -1, "{} Can't find field:{} Failed", full_name, proto_sheet_repeatedfieldname);
    CHECK_EXPR(pFieldDesc->is_repeated(), -1, "{} field:{} is not repeated", full_name, proto_sheet_repeatedfieldname);
    CHECK_EXPR(pFieldDesc->cpp_type() == google::protobuf::FieldDescriptor::CPPTYPE_MESSAGE, -1, "{} field:{} is not message", full_name,
               proto_sheet_repeatedfieldname);

    std::string content;
    std::map<std::string, DBTableColInfo> primaryKey;
    std::map<std::string, DBTableColInfo> mapFields;
    int iRet = NFProtobufCommon::Instance()->GetDbFieldsInfoFromMessage(pFieldDesc->message_type(), primaryKey, mapFields);
    if (iRet != 0)
    {
        NFLogError(NF_LOG_SYSTEMLOG, 0, "GetDbFieldsInfoFromMessage Error, tableName:{}", pFieldDesc->full_name());
    }

    content += CreateTable(sheet.m_protoInfo.m_protoMsgName, primaryKey) + "\n\n";
    content += CreateAddCol(sheet.m_protoInfo.m_protoMsgName, primaryKey, mapFields) + "\n\n";

    ::google::protobuf::int32 repeatedSize = pReflect->FieldSize(*pSheetProto, pFieldDesc);
    for(int i = 0; i < (int)repeatedSize; i++)
    {
        const google::protobuf::Message& rowMessage = pReflect->GetRepeatedMessage(*pSheetProto, pFieldDesc, i);
        WriteToSql(content, sheet.m_protoInfo.m_protoMsgName, &rowMessage);
    }

    std::string bin_file = m_outPath + "CreateTable_" + sheet.m_protoInfo.m_protoMsgName + ".sql";
    NFFileUtility::WriteFile(bin_file, content);
    return 0;
}

std::string ExcelToBin::CreateTable(const std::string &tableName, const std::map<std::string, DBTableColInfo> &primaryKey)
{
    std::string sql;
    std::string colSql;
    std::string privateKey = "PRIMARY KEY(";
    std::string auto_increment;

    for(auto iter = primaryKey.begin(); iter != primaryKey.end(); iter++)
    {
        if (iter == primaryKey.begin())
        {
            privateKey += iter->first;
        }
        else {
            privateKey += ","+iter->first;
        }

        std::string col;
        std::string otherInfo;
        if (iter->second.m_notNull)
        {
            otherInfo += " NOT NULL ";
        }

        if (iter->second.m_autoIncrement)
        {
            otherInfo += " AUTO_INCREMENT ";
            auto_increment = "AUTO_INCREMENT = " + NFCommon::tostr(iter->second.m_autoIncrementValue);
        }

        if (iter->second.m_isDefaultValue)
        {
            otherInfo += " Default = " + NFCommon::tostr(iter->second.m_defaultValue);
        }

        if (iter->second.m_comment.size() > 0)
        {
            otherInfo += " COMMENT \"" + iter->second.m_comment + "\"";
        }
        NF_FORMAT_EXPR(col, " {} {} {},", iter->first, NFProtobufCommon::GetDBDataTypeFromPBDataType(iter->second.m_colType, iter->second.m_bufsize), otherInfo)
        colSql += col;
    }
    privateKey += ")";

    NF_FORMAT_EXPR(sql, "CREATE TABLE IF NOT EXISTS {} ({} {}) ENGINE=InnoDB {} DEFAULT CHARSET=utf8;", tableName, colSql, privateKey, auto_increment);

    return sql;
}

int ExcelToBin::WriteToSql(std::string& content, const std::string& tbName, const google::protobuf::Message *pRowMessage)
{
    std::vector<std::pair<std::string, std::string>> keyValueMap;

    NFProtobufCommon::GetFieldsFromMessage(*pRowMessage, keyValueMap);

    // update
    std::string sql;
    sql += "replace into " + tbName + "(";
    for (auto iter = keyValueMap.begin(); iter != keyValueMap.end(); ++iter)
    {
        if (iter == keyValueMap.begin())
        {
            sql += iter->first;
        }
        else
        {
            sql += "," + iter->first;
        }
    }

    sql += ") values (";
    for (auto iter = keyValueMap.begin(); iter != keyValueMap.end(); ++iter)
    {
        if (iter == keyValueMap.begin())
        {
            sql += + "\"" + iter->second + "\"";
        }
        else
        {
            sql += ",\"" + iter->second + "\"";
        }
    }
    sql += ");\n";
    content += sql;
    return 0;
}

std::string
ExcelToBin::CreateAddCol(const string &tableName, const map<std::string, DBTableColInfo> &primaryKey, const map<std::string, DBTableColInfo> &mapFields)
{
    std::string content;
    std::multimap<uint32_t, std::string> needCreateColumn;
    for (auto iter = primaryKey.begin(); iter != primaryKey.end(); iter++)
    {
        if (!iter->second.m_primaryKey)
        {
            std::string otherInfo;
            if (iter->second.m_notNull)
            {
                otherInfo += " NOT NULL ";
            }

            if (iter->second.m_autoIncrement)
            {
                otherInfo += " AUTO_INCREMENT ";
            }

            if (iter->second.m_isDefaultValue)
            {
                otherInfo += " Default = " + NFCommon::tostr(iter->second.m_defaultValue);
            }

            if (iter->second.m_comment.size() > 0)
            {
                otherInfo += " COMMENT \"" + iter->second.m_comment + "\"";
            }

            std::string sql;
            NF_FORMAT_EXPR(sql, "alter table {} add column {} {} {};", tableName, iter->first,
                           NFProtobufCommon::GetDBDataTypeFromPBDataType(iter->second.m_colType, iter->second.m_bufsize), otherInfo);

            if (sql.size() > 0)
                needCreateColumn.emplace(iter->second.m_fieldIndex, sql);
        }
    }

    for (auto iter = mapFields.begin(); iter != mapFields.end(); iter++)
    {
        std::string otherInfo;
        if (iter->second.m_notNull)
        {
            otherInfo += " NOT NULL ";
        }

        if (iter->second.m_isDefaultValue)
        {
            otherInfo += " Default = " + NFCommon::tostr(iter->second.m_defaultValue);
        }

        if (iter->second.m_comment.size() > 0)
        {
            otherInfo += " COMMENT \"" + iter->second.m_comment + "\"";
        }

        std::string sql;
        NF_FORMAT_EXPR(sql, "alter table {} add column {} {} {};", tableName, iter->first,
                       NFProtobufCommon::GetDBDataTypeFromPBDataType(iter->second.m_colType, iter->second.m_bufsize), otherInfo);

        if (sql.size() > 0)
            needCreateColumn.emplace(iter->second.m_fieldIndex, sql);

        if (iter->second.m_primaryKey)
        {
            sql.clear();
            NF_FORMAT_EXPR(sql, "alter table {} add PRIMARY KEY ({});", tableName, iter->first);
            if (sql.size() > 0)
                needCreateColumn.emplace(iter->second.m_fieldIndex, sql);
        }

        if (iter->second.m_unionKey)
        {
            sql.clear();
            NF_FORMAT_EXPR(sql, "alter table {} add UNIQUE {} ({});", tableName, iter->first, iter->first);
            if (sql.size() > 0)
                needCreateColumn.emplace(iter->second.m_fieldIndex, sql);
        }

        if (iter->second.m_indexKey)
        {
            sql.clear();
            NF_FORMAT_EXPR(sql, "alter table {} add INDEX {} ({});", tableName, iter->first, iter->first);
            if (sql.size() > 0)
                needCreateColumn.emplace(iter->second.m_fieldIndex, sql);
        }
    }

    for(auto iter = needCreateColumn.begin(); iter != needCreateColumn.end(); iter++)
    {
        content += iter->second + "\n";
    }

    return content;
}


