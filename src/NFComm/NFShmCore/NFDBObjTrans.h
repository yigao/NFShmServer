// -------------------------------------------------------------------------
//    @FileName         :    NFDBObjTrans.h
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFDBObjTrans.h
//
// -------------------------------------------------------------------------

#pragma once

#include "NFTransBase.h"
#include "NFComm/NFPluginModule/NFCheck.h"
#include "NFComm/NFPluginModule/NFServerDefine.h"
#include "google/protobuf/message.h"
#include "NFComm/NFKernelMessage/proto_kernel.pb.h"

class NFDBObjTrans : public NFTransBase
{
public:
    NFDBObjTrans();
    virtual ~NFDBObjTrans();

    //非继承函数, 不要加virtual
    int CreateInit();
    //非继承函数, 不要加virtual
    int ResumeInit();
public:
    int Init(NF_SERVER_TYPES eType, int iObjID, uint32_t iSeqOP);
    int Insert(proto_ff::TableID eTableID, const std::string& sTableName, uint64_t iModKey, google::protobuf::Message* data);
    int Save(proto_ff::TableID eTableID, const std::string& sTableName, uint64_t iModKey, google::protobuf::Message* data);
    int Load(proto_ff::TableID eTableID, const std::string& sTableName, uint64_t iModKey, google::protobuf::Message* data);

    virtual int OnTimeOut();
    virtual int HandleTransFinished(int iRunLogicRetCode);

    int GetLinkedObjID() { return m_iLinkedObjID; }
    uint32_t GetObjSeqOP() { return m_iObjSeqOP; }
public:
    virtual int HandleDBMsgRes(const google::protobuf::Message *pSSMsgRes, uint32_t cmd, uint32_t table_id, uint32_t seq, uint32_t err_code);
private:
    int m_iLinkedObjID;
    uint32_t m_iObjSeqOP;
    int m_iDBOP;
    NF_SERVER_TYPES m_iServerType;
DECLARE_IDCREATE(NFDBObjTrans)
};