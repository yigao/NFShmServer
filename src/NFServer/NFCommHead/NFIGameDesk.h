// -------------------------------------------------------------------------
//    @FileName         :    NFGameDesk.h
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFGameDesk.h
//
// -------------------------------------------------------------------------

#pragma once

#include "NFComm/NFShmCore/NFShmObj.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmCore/NFSizeString.h"
#include "NFComm/NFShmCore/NFShmPtr.h"
#include "NFServer/NFCommHead/NFIGameDeskHandle.h"
#include "NFComm/NFPluginModule/NFMessageMgr.h"
#include "NFComm/NFShmCore/NFArray.h"

#include "NFComm/NFMessageDefine/proto_common_s.h"

class NFIGameDesk : public NFShmObj
{
public:
	NFIGameDesk()
	{
		if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
			CreateInit();
		}
		else {
			ResumeInit();
		}
	}

	virtual ~NFIGameDesk()
	{

	}

	int CreateInit() {
		return 0;
	}

	int ResumeInit() {
		return 0;
	}

public:
	virtual bool AddMessageCallBack(uint16_t subMsgId) = 0;

	virtual int SendMsgToClient(uint64_t playerId, uint16_t nSubMsgId, const google::protobuf::Message &xData) = 0;

	virtual int BroadCastMsgToDesk(uint16_t nSubMsgId, const google::protobuf::Message &xData, int32_t chairId = INVALID_ID) = 0;

	virtual int SendMsgToWorldServer(uint32_t nMsgId, const google::protobuf::Message &xData) = 0;

	virtual int SendMsgToLogicServer(uint32_t nMsgId, const google::protobuf::Message &xData, uint64_t playerId = 0) = 0;

	virtual int SendMsgToSnsServer(uint32_t nMsgId, const google::protobuf::Message &xData) = 0;

	virtual int ModifyGameMoney(uint64_t playerId, uint32_t changeType, uint64_t moneyChange) = 0;

	virtual int DeduceGameMoney(uint64_t playerId, uint64_t moneyChange, bool procUserSettlement = false) = 0;

    virtual int AddGameMoney(uint64_t playerId, uint64_t moneyChange, bool procUserSettlement = false) = 0;

    virtual int ProcUserSettlement(uint64_t playerId) = 0;

    virtual uint64_t GetPlayerCurMoney(uint64_t playerId) = 0;

    virtual int PaoMaDengNotify(const std::string& playerName, uint64_t winJetton) = 0;

    virtual int LogGameRecord(uint64_t recordId, uint64_t playerId, const google::protobuf::Message& betInfo, const google::protobuf::Message& resultInfo) = 0;

	virtual int ForceExitGame(uint64_t playerId) = 0;

    virtual int GameDataCommit(uint64_t cur_fee, uint64_t cur_pour, int64_t cur_win) = 0;

    virtual int64_t CommissionCount(uint64_t userid, int64_t CountByFee, int64_t pourJetton) = 0;

    virtual int AchievementCount(uint64_t userid, uint64_t Count, uint64_t fee) = 0;

    virtual bool GetOperateCtrlVal(uint64_t userid, int *iOperateCtrlRate, int *iOperateCtrlLevel = NULL, uint64_t *iOperateMaxWinJetton = NULL) = 0;

    virtual uint64_t GetMaxWinJetton(uint64_t userid) = 0;

    virtual proto_ff_s::tbGameUserManagerData_s *GetUserManagerData(uint64_t playerId) = 0;

    virtual proto_ff_s::tbGmCtrlGiveCtrlData_s *GetGmCtrlGiveData(uint64_t playerId) = 0;

    virtual int FinishGmCtrlGiveData(uint64_t playerId) = 0;
};
