// -------------------------------------------------------------------------
//    @FileName         :    NFDBObjTrans.h
//    @Author           :    Gao.Yi
//    @Date             :   2022-09-18
//    @Email			:    445267987@qq.com
//    @Module           :    NFDBObjTrans.h
//
// -------------------------------------------------------------------------

#pragma once

#include "NFComm/NFShmCore/NFTransBase.h"

class NFDBObjTrans : public NFShmObjTemplate<NFDBObjTrans, EOT_TRANS_DB_OBJ, NFTransBase>
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
    int Insert(uint32_t eTableID, const std::string& sTableName, uint64_t iModKey, google::protobuf::Message* data);
    int Save(uint32_t eTableID, const std::string& sTableName, uint64_t iModKey, google::protobuf::Message* data);
    int Load(uint32_t eTableID, const std::string& sTableName, uint64_t iModKey, google::protobuf::Message* data);

    virtual int OnTimeOut();
    virtual int HandleTransFinished(int iRunLogicRetCode);

    int GetLinkedObjID() { return m_iLinkedObjID; }
    uint32_t GetObjSeqOP() { return m_iObjSeqOP; }
public:
    virtual int HandleDBMsgRes(const google::protobuf::Message *pSSMsgRes, uint32_t cmd, uint32_t table_id, uint32_t seq, int32_t err_code);
private:
    int m_iLinkedObjID;
    uint32_t m_iObjSeqOP;
    int m_iDBOP;
    NF_SERVER_TYPES m_iServerType;
};