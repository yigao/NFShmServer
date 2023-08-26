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
        google::protobuf::Message *pRowMessage = pReflect->AddMessage(pSheetProto, pFieldDesc);
        CHECK_EXPR(pRowMessage, -1, "{} addfield:{} Failed", full_name, proto_sheet_repeatedfieldname);
        int iRet = WriteToBin(sheet, i, pRowMessage);
        if (iRet != 0)
        {
            return iRet;
        }
    }

    std::string bin_file = m_outPath + sheet.m_protoInfo.m_protoMsgName + ".bin";
    std::string content = pSheetProto->SerializeAsString();
    NFFileUtility::WriteFile(bin_file, content);
    return 0;
}

int ExcelToBin::WriteToBin(ExcelSheet &sheet, int row, google::protobuf::Message *pRowMessage)
{
    MiniExcelReader::Sheet *pExcelSheet = m_excelReader->getSheet(sheet.m_name);
    CHECK_EXPR(pExcelSheet, -1, "excel:{} Can't find sheet:{} data", m_excel, sheet.m_name);
    std::unordered_map<std::string, std::string> m_mapFields;
    for (auto iter = sheet.m_allColInfoList.begin(); iter != sheet.m_allColInfoList.end(); iter++)
    {
        int col = iter->first;
        auto pCell = pExcelSheet->getCell(row, col);
        CHECK_EXPR(pCell, -1, "excel:{} can't get data, row:{} col:{}", row, col);
        std::string value = pCell->to_string();
        ExcelSheetColIndex &sheelColIndex = iter->second;
        ExcelSheetColInfo *pColInfo = sheelColIndex.m_pColInfo;
        /**
         * @brief  不是数组，最正常的数据
         */
        if (pColInfo->m_maxSubNum == 0 && pColInfo->m_subInfoMap.empty())
        {
            std::string field = "m_" + NFStringUtility::Lower(pColInfo->m_structEnName);
            m_mapFields.emplace(field, value);
        }
            /**
             * @brief 简单数组， repeated int32 a 表 itemid itemid
             */
        else if (pColInfo->m_maxSubNum > 0 && pColInfo->m_subInfoMap.empty())
        {
            std::string field =
                    "m_" + NFStringUtility::Lower(pColInfo->m_structEnName) + "_" + NFCommon::tostr(sheelColIndex.m_structNum);
            m_mapFields.emplace(field, value);
        }
        else if (pColInfo->m_maxSubNum > 0 && !pColInfo->m_subInfoMap.empty())
        {
            std::string field =
                    "m_" + NFStringUtility::Lower(pColInfo->m_structEnName) + "_" + NFCommon::tostr(sheelColIndex.m_structNum) + "_" +
                    "m_" + NFStringUtility::Lower(sheelColIndex.m_structSubEnName);
            m_mapFields.emplace(field, value);
        }
        else
        {
            CHECK_EXPR(false, -1, "excel:{} row:{} col:{} can't parse", row, col);
        }
    }

    NFProtobufCommon::GetMessageFromMapFields(m_mapFields, pRowMessage);

    //NFLogInfo(NF_LOG_SYSTEMLOG, 0, "row:{} {}", row, pRowMessage->Utf8DebugString());

    return 0;
}

