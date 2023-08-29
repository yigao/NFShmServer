// -------------------------------------------------------------------------
//    @FileName         :    ExcelToBin.h
//    @Author           :    gaoyi
//    @Date             :    23-8-26
//    @Email			:    445267987@qq.com
//    @Module           :    ExcelToBin
//
// -------------------------------------------------------------------------

#pragma once

#include "NFComm/NFCore/NFPlatform.h"
#include "ExcelParse.h"

class ExcelToBin : public ExcelParse, public NFSingleton<ExcelToBin>
{
public:
    ExcelToBin();

    virtual ~ExcelToBin();
public:
    virtual int Init(const std::string& excel, const std::string& outPath, const std::string& proto_ds);
    virtual int HandleExcel();
public:
    void OnHandleSheetProtoInfo();
    void OnHandleSheetProtoInfo(ExcelSheet& sheet);
    int WriteToBin();
    int WriteToBin(ExcelSheet& sheet);
    int WriteToBin(ExcelSheet& sheet, int row, google::protobuf::Message *pSheetProto, const google::protobuf::Reflection *pReflect, const google::protobuf::FieldDescriptor *pFieldDesc);
public:
    std::string m_proto_ds;
};