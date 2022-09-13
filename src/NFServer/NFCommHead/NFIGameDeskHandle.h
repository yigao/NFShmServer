// -------------------------------------------------------------------------
//    @FileName         :    NFIGameDeskHandle.h
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFIGameDeskHandle.h
//
// -------------------------------------------------------------------------

#pragma once

#include "NFComm/NFShmCore/NFShmObj.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmCore/NFSizeString.h"
#include "NFComm/NFShmCore/NFShmPtr.h"
#include "NFComm/NFPluginModule/NFIPluginManager.h"
#include "NFServer/NFCommHead/NFIGameRoomModule.h"
//#include "NFGameLogic/NFFishMessage/msg_fish.pb.h"
#include "NFComm/NFMessageDefine/proto_cs.pb.h"
#include "NFComm/NFMessageDefine/proto_common_s.h"
#include "NFServer/NFCommHead/NFIGamePlayer.h"
#include "NFServer/NFCommHead/NFIGameDesk.h"

class NFIGameDeskHandle : public NFShmObj {
public:
    NFIGameDeskHandle() {
        if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
            CreateInit();
        } else {
            ResumeInit();
        }
    }

    virtual ~NFIGameDeskHandle() {}

    int CreateInit() {
        m_gameId = 0;
        m_roomId = 0;
        m_deskId = INVALID_ID;
        m_siteNum = 0;
        m_maxUserNum = 0;
		m_deskHandle = NULL;
        return 0;
    }

    int ResumeInit() {
        return 0;
    }

    virtual int Init(NFIGameDesk* pGameHandle, uint32_t gameId, uint32_t roomId, int32_t deskId, uint32_t sitNum, uint32_t maxUserNum)
    {
		m_deskHandle = pGameHandle;
        m_gameId = gameId;
        m_roomId = roomId;
        m_deskId = deskId;
        m_siteNum = sitNum;
        m_maxUserNum = maxUserNum;
        return 0;
    }

    bool AddMessageCallBack(uint16_t subMsgId) 
	{
        return m_deskHandle->AddMessageCallBack(subMsgId);
    }

    virtual int OnHandleClientMsg(uint64_t playerId, uint16_t nMsgId, const char *msg, uint32_t nLen) = 0;

    virtual int OnHandleServerMsg(uint64_t playerId, uint32_t nMsgId, const char *msg, uint32_t nLen) = 0;

    virtual bool IsPlayGame(int iDeskStation) = 0;
	virtual bool IsPlayGameCanLeave(int iDeskStation) { return false; }
	virtual bool IsGamePlayerReady(uint64_t playerId) { return false; };

    virtual int UserReCome(uint64_t playerId, int iChairIndex, proto_ff_s::GamePlayerDetailData_s& playerDetail) = 0;

    virtual int UserSitDesk(uint64_t playerId, int iChairIndex, proto_ff_s::GamePlayerDetailData_s& playerDetail) = 0;
    virtual int UserLeftDesk(uint64_t playerId, int iChairIndex, proto_ff_s::GamePlayerDetailData_s& playerDetail) = 0;
    virtual int UserReconDesk(uint64_t playerId, int iChairIndex, proto_ff_s::GamePlayerDetailData_s& playerDetail) = 0;
    virtual int UserAgreeGame(uint64_t playerId, int iChairIndex, proto_ff_s::GamePlayerDetailData_s& playerDetail) = 0;
    virtual int UserDisconnect(uint64_t playerId, int iChairIndex, proto_ff_s::GamePlayerDetailData_s& playerDetail) = 0;

    virtual int ClearJiangChi() { return -1; }
    virtual int ChangeJiangChi(int64_t jiangchi) { return -1; }
    virtual int UpdateUserInfo(uint64_t playerId, const proto_ff_s::GamePlayerDetailData_s* pUserDetailInfo) { return 0; }

    virtual int GameDataCommit(uint64_t cur_fee, uint64_t cur_pour, int64_t cur_win)
    {
        return m_deskHandle->GameDataCommit(cur_fee, cur_pour, cur_win);
    }

    virtual int64_t CommissionCount(uint64_t userid, int64_t CountByFee, int64_t pourJetton)
    {
        return m_deskHandle->CommissionCount(userid, CountByFee, pourJetton);
    }

    virtual int AchievementCount(uint64_t userid, uint64_t Count, uint64_t fee)
    {
        return m_deskHandle->AchievementCount(userid, Count, fee);
    }

    virtual int SendMsgToClient(uint64_t playerId, uint16_t nSubMsgId, const google::protobuf::Message &xData) 
	{
		return m_deskHandle->SendMsgToClient(playerId, nSubMsgId, xData);
    }

	virtual int	ModifyGameMoney(uint64_t playerId, uint32_t unChageType, uint64_t un64MoneyChange)
	{
		return m_deskHandle->ModifyGameMoney(playerId, unChageType, un64MoneyChange);
	}

    virtual int LogGameRecord(uint64_t recordId, uint64_t playerId, const google::protobuf::Message& betInfo, const google::protobuf::Message& resultInfo)
    {
        return m_deskHandle->LogGameRecord(recordId, playerId, betInfo, resultInfo);
    }

    virtual int DeduceGameMoney(uint64_t playerId, uint64_t moneyChange, bool procUserSettlement = false)
    {
        return m_deskHandle->DeduceGameMoney(playerId, moneyChange, procUserSettlement);
    }

    virtual int AddGameMoney(uint64_t playerId, uint64_t moneyChange, bool procUserSettlement = false)
    {
        return m_deskHandle->AddGameMoney(playerId, moneyChange, procUserSettlement);
    }

    virtual int ProcUserSettlement(uint64_t playerId)
    {
        return m_deskHandle->ProcUserSettlement(playerId);
    }

    virtual uint64_t GetPlayerCurMoney(uint64_t playerId)
    {
        return m_deskHandle->GetPlayerCurMoney(playerId);
    }

    virtual bool GetOperateCtrlVal(uint64_t userid, int *iOperateCtrlRate, int *iOperateCtrlLevel = NULL, uint64_t *iOperateMaxWinJetton = NULL)
    {
        return m_deskHandle->GetOperateCtrlVal(userid, iOperateCtrlRate, iOperateCtrlLevel, iOperateMaxWinJetton);
    }

    virtual proto_ff_s::tbGameUserManagerData_s *GetUserManagerData(uint64_t playerId)
    {
        return m_deskHandle->GetUserManagerData(playerId);
    }

    virtual proto_ff_s::tbGmCtrlGiveCtrlData_s *GetGmCtrlGiveData(uint64_t playerId)
    {
        return m_deskHandle->GetGmCtrlGiveData(playerId);
    }

    virtual int FinishGmCtrlGiveData(uint64_t playerId)
    {
        return m_deskHandle->FinishGmCtrlGiveData(playerId);
    }

    uint32_t GetGameId() const { return m_gameId; }

    uint32_t GetRoomId() const { return m_roomId; }

    int32_t GetDeskId() const { return m_deskId; }

    uint32_t GetSitNum() const { return m_siteNum; }

    uint32_t GetMaxUserNum() const { return m_maxUserNum; }

protected:
    uint32_t m_gameId;
    uint32_t m_roomId;
    int32_t m_deskId;
    uint32_t m_siteNum;
    uint32_t m_maxUserNum;
	NFRawShmPtr<NFIGameDesk> m_deskHandle;
};