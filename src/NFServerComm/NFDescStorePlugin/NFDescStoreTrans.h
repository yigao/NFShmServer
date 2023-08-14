// -------------------------------------------------------------------------
//    @FileName         :    NFDescStoreTrans.h
//    @Author           :    Gao.Yi
//    @Date             :   2022-09-18
//    @Email			:    445267987@qq.com
//    @Module           :    NFDescStoreTrans.h
//
// -------------------------------------------------------------------------

#pragma once

#include "NFComm/NFShmCore/NFTransBase.h"
#include "NFComm/NFKernelMessage/storesvr_sqldata.pb.h"
#include "NFComm/NFPluginModule/NFIAsyDBModule.h"

class NFDescStoreTrans : public NFTransBase
{
public:
    enum
    {
        RPC_TYPE_NONE = 0,
    };

    NFDescStoreTrans();

    virtual ~NFDescStoreTrans();

    int Init(int64_t coId, const google::protobuf::Message *pDescStoreMessage);

    int CreateInit();

    int ResumeInit();

    virtual int HandleDBMsgRes(const google::protobuf::Message *pSSMsgRes, uint32_t cmd, uint32_t table_id, uint32_t seq, int32_t err_code);

    virtual bool IsTimeOut();

    virtual int OnTimeOut();

    //must be virtual
    virtual int OnTimer(int timeId, int callcount);

    int OnTransFinished(int iRunLogicRetCode);

    int HandleTransFinished(int iRunLogicRetCode) { return 0; }

    int SendGetDescStoreReq(NF_SERVER_TYPES eType, const std::string& dbName, const std::string &table_name, const QueryDescStore_CB& cb);

    int HandleDescStoreData(const storesvr_sqldata::storesvr_sel_res *pSelRsp, uint32_t err_code);

    std::string GetDescStoreClsName();
private:
    int m_timeId;
    int64_t m_coId;
    QueryDescStore_CB m_descStoreCB;
    NF_SERVER_TYPES m_eType;
    std::string m_tableName;
	std::string m_dbName;
    google::protobuf::Message *m_descStoreMessage;
DECLARE_IDCREATE(NFDescStoreTrans)
};