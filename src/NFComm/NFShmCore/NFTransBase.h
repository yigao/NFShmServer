// -------------------------------------------------------------------------
//    @FileName         :    NFTransBase.h
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFTransBase.h
//
// -------------------------------------------------------------------------

#pragma once

#include "NFComm/NFShmCore/NFShmObj.h"
#include "google/protobuf/message.h"
#include "NFComm/NFKernelMessage/proto_kernel.pb.h"

enum
{
    ERR_TRANS_RUNED_TOO_MUCH = 100057,
    MAX_TRANS_RUNED_TIMES = 10000,
    TRANS_ACTIVE_TIMEOUT =  200,	 //trans每一步的最大生命周期5m
};

class NFTransBase : public NFShmObj {
public:
    NFTransBase();
    virtual ~NFTransBase();

    //非继承函数, 不要加virtual
    int CreateInit();
    //非继承函数, 不要加virtual
    int ResumeInit();

    int Init();
    void IncreaseRunTimes();
    void SetFinished(int iRetCode);
    bool IsFinished() const;
    int ProcessCSMsgReq(const google::protobuf::Message* pCSMsgReq);
    
	int ProcessDispSvrRes(uint64_t unLinkId, uint64_t destLinkId, uint64_t req_trans_id, uint32_t nMsgId, const char* msg, uint32_t nLen);
    int ProcessDBMsgRes(const google::protobuf::Message *pSSMsgRes, uint32_t cmd, uint32_t table_id, uint32_t seq, uint32_t err_code);
    int ProcessDBMsgRes(proto_ff::Proto_SvrPkg& svrPkg);
    bool CanRelease();
    virtual std::string GetDebugInfo() const;

    uint16_t GetState() { return m_wCurState; }
    void SetState( uint16_t wState ) { m_wCurState = wState; }

    virtual int OnTimeOut();
    virtual bool IsTimeOut();

    virtual int OnTransFinished(int iRunLogicRetCode) { return 0;}
    virtual int HandleTransFinished( int iRunLogicRetCode ) { return 0;}
protected:
    virtual int HandleCSMsgReq(const google::protobuf::Message *pCSMsgReq);
    
	virtual int HandleDispSvrRes(uint64_t unLinkId, uint64_t destLinkId, uint64_t req_trans_id, uint32_t nMsgId, const char* msg, uint32_t nLen);
    virtual int HandleDBMsgRes(const google::protobuf::Message *pSSMsgRes, uint32_t cmd, uint32_t table_id, uint32_t seq,
                   uint32_t err_code);
protected:
    int CheckCanRunNow();
    int RunCommLogic();
protected:
    bool m_bIsFinished;
    uint32_t m_dwStartTime;
    uint32_t m_dwKeepAliveTime;
    uint16_t m_wCurState;
    uint16_t m_wRunedTimes;
    int m_iRunLogicRetCode;
DECLARE_IDCREATE(NFTransBase)
};