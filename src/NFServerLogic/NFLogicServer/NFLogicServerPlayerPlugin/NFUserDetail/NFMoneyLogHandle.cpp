// -------------------------------------------------------------------------
//    @FileName         :    NFMoneyLogHandle.cpp
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFMoneyLogHandle.cpp
//
// -------------------------------------------------------------------------
#include "NFMoneyLogHandle.h"
#include "NFUserDetail.h"
#include "NFComm/NFPluginModule/NFLogMgr.h"
#include "NFComm/NFPluginModule/NFMessageMgr.h"

NFMoneyLogHandle::NFMoneyLogHandle() {
    NFLogMgr::Instance()->AddLogBehaviorCB(NF_ST_LOGIC_SERVER, this, &NFMoneyLogHandle::MoneyLogCallBack);
}

NFMoneyLogHandle::~NFMoneyLogHandle() {

}

int NFMoneyLogHandle::UserMoneyChange(NFUserDetail* pUserDetail, uint32_t gameId, uint32_t roomId, uint32_t deskId, uint32_t chairId, uint32_t accountType, uint64_t moneyChange, uint32_t opt_type, uint32_t opt_reason) {
    CHECK_NULL(pUserDetail);

    proto_ff::LogMoneyDetail detail;
    detail.set_game_id(gameId);
    detail.set_room_id(roomId);
    detail.set_desk_id(deskId);
    detail.set_chair_id(chairId);

    detail.set_all_jetton(pUserDetail->GetJetton()+pUserDetail->GetBankJetton());
    detail.set_jetton(pUserDetail->GetJetton());
    detail.set_bank_jetton(pUserDetail->GetBankJetton());
    detail.set_account_type(accountType);
    detail.set_change_count(moneyChange);
    detail.set_opt_type(opt_type);
    detail.set_opt_reason(opt_reason);
    detail.set_agent_id(pUserDetail->GetAgentId());
    detail.set_ip(pUserDetail->GetData()->ip.GetString());

    NFLogBehavior(NF_ST_LOGIC_SERVER, pUserDetail->GetUserId(), pUserDetail->GetNickName(), detail);
    return 0;
}

int NFMoneyLogHandle::NFMoneyLogHandle::WebZhuangZhangRecharge(NFUserDetail* pUserDetail, int64_t amount, uint32_t status)
{
    CHECK_NULL(pUserDetail);

    proto_ff::LogZhuangRecord record;
    record.set_amount(amount);
    record.set_status(status);

    NFLogBehavior(NF_ST_LOGIC_SERVER, pUserDetail->GetUserId(), pUserDetail->GetNickName(), record);
    return 0;
}

int NFMoneyLogHandle::WebRedeemCodeRecharge(NFUserDetail* pUserDetail, uint64_t amount, uint32_t status)
{
    CHECK_NULL(pUserDetail);

    proto_ff::LogRedeemCodeRechargeRecord record;
    record.set_amount(amount);
    record.set_status(status);

    NFLogBehavior(NF_ST_LOGIC_SERVER, pUserDetail->GetUserId(), pUserDetail->GetNickName(), record);
    return 0;
}

int NFMoneyLogHandle::WebGiveMoney(NFUserDetail* pUserDetail, uint32_t reason, uint64_t amount, uint32_t status)
{
    CHECK_NULL(pUserDetail);

    proto_ff::LogGiveMoneyRecord record;
    record.set_amount(amount);
    record.set_type(reason);
    record.set_status(status);

    NFLogBehavior(NF_ST_LOGIC_SERVER, pUserDetail->GetUserId(), pUserDetail->GetNickName(), record);
    return 0;
}

int NFMoneyLogHandle::MoneyLogCallBack(uint64_t userId, const google::protobuf::Message* message)
{
    {
        const proto_ff::LogMoneyDetail* pLogMoneyDetail = dynamic_cast<const proto_ff::LogMoneyDetail*>(message);
        if (pLogMoneyDetail)
        {
            NFMessageMgr::Instance()->SendTransToStoreServer(NF_ST_LOGIC_SERVER,
                                                             proto_ff::E_STORESVR_C2S_INSERT, proto_ff::E_TABLE_NONE, NF_DEFAULT_MYSQL_DB_NAME, "LogMoneyDetail", *pLogMoneyDetail,
                                                             0, 0, userId);

            return 0;
        }
    }

    {
        const proto_ff::LogZhuangRecord* pLogZhuangRecord = dynamic_cast<const proto_ff::LogZhuangRecord*>(message);
        if (pLogZhuangRecord)
        {
            NFMessageMgr::Instance()->SendTransToStoreServer(NF_ST_LOGIC_SERVER,
                                                             proto_ff::E_STORESVR_C2S_INSERT, proto_ff::E_TABLE_NONE, NF_DEFAULT_MYSQL_DB_NAME, "LogZhuangRecord", *pLogZhuangRecord,
                                                             0, 0, userId);

            return 0;
        }
    }

    {
        const proto_ff::LogGiveMoneyRecord* pLogGiveMoneyRecord = dynamic_cast<const proto_ff::LogGiveMoneyRecord*>(message);
        if (pLogGiveMoneyRecord)
        {
            NFMessageMgr::Instance()->SendTransToStoreServer(NF_ST_LOGIC_SERVER,
                                                             proto_ff::E_STORESVR_C2S_INSERT, proto_ff::E_TABLE_NONE, NF_DEFAULT_MYSQL_DB_NAME, "LogGiveMoneyRecord", *pLogGiveMoneyRecord,
                                                             0, 0, userId);

            return 0;
        }
    }

    {
        const proto_ff::LogRedeemCodeRechargeRecord* pLogRedeemRecord = dynamic_cast<const proto_ff::LogRedeemCodeRechargeRecord*>(message);
        if (pLogRedeemRecord)
        {
            NFMessageMgr::Instance()->SendTransToStoreServer(NF_ST_LOGIC_SERVER,
                                                             proto_ff::E_STORESVR_C2S_INSERT, proto_ff::E_TABLE_NONE, NF_DEFAULT_MYSQL_DB_NAME, "LogRedeemCodeRechargeRecord", *pLogRedeemRecord,
                                                             0, 0, userId);

            return 0;
        }
    }

    return 0;
}

