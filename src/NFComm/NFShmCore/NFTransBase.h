// -------------------------------------------------------------------------
//    @FileName         :    NFTransBase.h
//    @Author           :    Gao.Yi
//    @Date             :   2022-09-18
//    @Email			:    445267987@qq.com
//    @Module           :    NFTransBase.h
//
// -------------------------------------------------------------------------

#pragma once

#include "NFComm/NFShmCore/NFShmObj.h"

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
    
	int ProcessDispSvrRes(uint32_t nMsgId, const NFDataPackage &packet, uint32_t reqTransId, uint32_t rspTransId);
    int ProcessDBMsgRes(const google::protobuf::Message *pSSMsgRes, uint32_t cmd, uint32_t table_id, uint32_t seq, int32_t err_code);
    int ProcessDBMsgRes(proto_ff::Proto_SvrPkg& svrPkg);
    bool CanRelease();
    virtual std::string DebugString() const;

    uint16_t GetState() const { return m_wCurState; }
    void SetState( uint16_t wState ) { m_wCurState = wState; }

    virtual int OnTimeOut();
    virtual bool IsTimeOut();

    virtual int OnTransFinished(int iRunLogicRetCode) { return 0;}
    virtual int HandleTransFinished( int iRunLogicRetCode ) { return 0;}
protected:
    virtual int HandleCSMsgReq(const google::protobuf::Message *pCSMsgReq);
    
	virtual int HandleDispSvrRes(uint32_t nMsgId, const NFDataPackage &packet, uint32_t reqTransId, uint32_t rspTransId);
    virtual int HandleDBMsgRes(const google::protobuf::Message *pSSMsgRes, uint32_t cmd, uint32_t table_id, uint32_t seq,
                   int32_t err_code);
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

#define CHECK_ERR_AND_FIN_TRANS( iRetCode, pTrans, format, ...)\
    if( iRetCode != 0 )\
    {\
        pTrans->SetFinished( iRetCode );\
        std::string log_event = NF_FORMAT(format, ##__VA_ARGS__);\
		NFLogError(NF_LOG_SYSTEMLOG, 0, "CHCK TRANS RetCode:{} failed:{}", iRetCode, log_event);\
        return iRetCode;\
    }\


#define CHECK_EXPR_AND_FIN_TRANS( expr, iRetCode, pTrans, format, ...)\
    if( !(expr) )\
    {\
        pTrans->SetFinished( iRetCode );\
        std::string log_event = NF_FORMAT(format, ##__VA_ARGS__);\
		NFLogError(NF_LOG_SYSTEMLOG, 0, "CHECK Trans:{} RetCode:{} failed:{}", #expr, iRetCode, log_event);\
        return iRetCode;\
    }\


