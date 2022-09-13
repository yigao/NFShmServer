// -------------------------------------------------------------------------
//    @FileName         :    NFUserDetail.h
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFUserDetail.h
//
// -------------------------------------------------------------------------

#pragma once

#include "NFComm/NFShmCore/NFShmObj.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmCore/NFServerFrameTypeDefines.h"
#include "NFComm/NFMessageDefine/proto_common_s.h"
#include "NFComm/NFShmCore/NFSeqOP.h"
#include "NFTransSaveDB.h"
#include "NFComm/NFCore/NFTime.h"
#include "NFUserEventLog.h"

class NFUserDetail : public NFShmObj, public NFSeqOP
{
public:
    NFUserDetail();

    virtual ~NFUserDetail();

    int CreateInit();
    int ResumeInit();

    uint64_t GetUserId() const { return m_userData.userid; }
    int InitUserDetailData(const proto_ff::tbUserDetailData& data);
    int MakeUserDataCS(proto_ff::tbUserDetailData& data);

	PLAYER_STATUS GetOnlineStatus() const { return m_iStatus; }
	void SetOnlineStatus(PLAYER_STATUS status) { m_iStatus = status; }
	void SetOnline(bool online) { m_userData.online = online; }
    uint64_t GetLastDisconnectTime() const { return m_lastDiconnectTime; }
	void SetLastDisconnectTime(uint64_t distime) { m_lastDiconnectTime = distime; }
    uint64_t GetUserDetailSaveDBTime() const { return m_userDetailInfoSavingDBTime; }
	void SetUserDetailSaveDBTime(uint64_t saveTime) { m_userDetailInfoSavingDBTime = saveTime; }
	bool IsInSaving() { return m_userDetailInfoSavingDBTime > 0 && m_userDetailInfoSavingDBTime + TRANS_ACTIVE_TIMEOUT + 5 >= (uint64_t)NFTime::Now().UnixSec(); }
	bool IsSynced() { return m_bDetailInited; }
	bool IsInGaming() { return m_userData.game_id > 0 && m_userData.room_id > 0 && m_gameBusId > 0; }
    bool IsCheckedBankPassword() const { return m_bCheckedBankPassword; }
    void SetCheckedBankPassword() { m_bCheckedBankPassword = true; }
    void ClearCheckedBankPassword() { m_bCheckedBankPassword = false; }
	void IncreaseTransNum();
	void DecreaseTransNum();

	int HandleAddJetton(uint64_t moneyChange, uint32_t opt_type, uint32_t opt_reason, uint32_t changeTime);
	int HandleDeduceJetton(uint64_t moneyChange, uint32_t opt_type, uint32_t opt_reason, uint32_t changeTime);

    int HandleAddBankJetton(uint64_t moneyChange, uint32_t opt_type, uint32_t opt_reason, uint32_t changeTime);
    int HandleDeduceBankJetton(uint64_t moneyChange, uint32_t opt_type, uint32_t opt_reason, uint32_t changeTime);

	int SaveMoneyToDB();
	int SendMoneyToClient();
	int SaveGameRoomToDB();

	int SaveUserDetailToDB(TRANS_SAVEROLEDETAIL_REASON iReason = TRANS_SAVEROLEDETAIL_NORMAL);

	int SaveToDB(TRANS_SAVEROLEDETAIL_REASON iReason = TRANS_SAVEROLEDETAIL_NORMAL, bool bForce = false);

	int OnUserDetailSaved(bool success, uint32_t seq);

	int UserLogin(bool isLoadDB);
	int UserLogout();
	int UserDisConnect();
	int UserReconnect();

	void Tick();
	void DayTick();
	void WeekTick();
	void MonthTick();
	void LogicTick();

	int SendErrToClient(uint32_t nMsgId, proto_ff::Proto_CS_ErrorCode errCode);
    int SendMsgToClient(uint32_t nMsgId, const google::protobuf::Message &xData);
    int SendMsgToSnsServer(uint32_t nMsgId, const google::protobuf::Message &xData);
    int SendMsgToWorldServer(uint32_t nMsgId, const google::protobuf::Message &xData);
    int SendMsgToGameServer(uint32_t nMsgId, const google::protobuf::Message &xData);

    proto_ff_s::tbUserDetailData_s* GetData() { return &m_userData; }
    proto_ff_s::UserMiscData_s* GetMiscData() { return &m_userData.misc_data; }
    void ClearTmpPhoneData();
    uint64_t GetJetton() const { return m_userData.jetton; }
    uint64_t GetBankJetton() const { return m_userData.bank_jetton; }
    std::string GetBankPassword() const { return m_userData.bank_password.GetString(); }
    uint64_t GetLastLoginTime() const { return m_userData.last_login_time; }
    void SetLastLoginTime(uint64_t time);
    uint64_t GetLastLogoutTime() const { return m_userData.last_logout_time; }
    void SetLastLogoutTime(uint64_t time);
    uint32_t GetFaceId() const { return m_userData.faceid; }
    void SetFaceId(uint32_t faceId) { m_userData.faceid = faceId; }
    std::string GetNickName() const { return m_userData.nickname.GetString(); }
    uint32_t GetGender() const { return m_userData.gender; }
    uint32_t GetAge() const { return m_userData.age; }
    uint64_t GetAgentId() const { return m_userData.agent_id; }
    uint64_t GetRefererId() const { return m_userData.referrer_id; }
    bool IsFirstRecharge() const { return m_userData.first_recharge; }
    uint32_t GetAreadId() const { return m_userData.aread_id; }
    uint64_t GetPhonenum() const { return m_userData.phonenum; }
    uint32_t GetVipLevel() const { return m_userData.vip_level; }
    uint64_t GetShowUserId() const { return m_userData.show_userid; }
    int ChangeBankPassword(const std::string& newPass);
    NFUserEventLog* GetEventLog() { return &m_eventLog; }

    int NotifyGameMoneyChange();
public:
	int m_iTransNum;
	PLAYER_STATUS m_iStatus;
	uint64_t m_createTime;
	uint64_t m_lastDiconnectTime;
	bool m_bDetailInited;
    uint64_t m_userDetailInfoSavingDBTime;
	uint32_t m_gameBusId;
	uint32_t m_proxyBusId;
	bool m_bCheckedBankPassword;
	uint64_t m_lastUpdateGoldRankTime;
	bool m_needUpdateGoldRank;

    proto_ff_s::tbUserDetailData_s m_userData;
    NFUserEventLog m_eventLog;
DECLARE_IDCREATE(NFUserDetail)
};
