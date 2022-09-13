// -------------------------------------------------------------------------
//    @FileName         :    NFTransQueryCoinBalance.h
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFTransQueryCoinBalance.h
//
// -------------------------------------------------------------------------

#pragma once

#include "NFTransGamePlayerBase.h"
#include "NFServer/NFCommHead/NFCommLogicHead.h"
#include "NFComm/NFShmCore/NFSizeString.h"
#include "NFComm/NFMessageDefine/proto_svr_common.pb.h"
#include "NFComm/NFMessageDefine/proto_svr_game.pb.h"

class NFTransQueryCoinBalance : public NFTransGamePlayerBase {
public:
	NFTransQueryCoinBalance();

	virtual ~NFTransQueryCoinBalance();

	int CreateInit();

	int ResumeInit();

	virtual int HandleCSMsgReq(const google::protobuf::Message *pCSMsgReq);

	virtual int HandleDispSvrRes(uint64_t unLinkId, uint64_t destLinkId, uint64_t req_trans_id, uint32_t nMsgId, const char* msg, uint32_t nLen);

	virtual int HandleTransFinished(int iRunLogicRetCode);

	int ProQueryCoinBalanceReq(uint32_t gameId, uint32_t roomId, int32_t deskId, int32_t stationId);
	int ProQueryCoinBalanceReq();

	int HandleQueryCoinBalanceRsp(const proto_ff::Proto_QueryCoinBalanceRsp& xMsg);
protected:
	uint32_t m_gameId;
	uint32_t m_roomId;
	int32_t m_deskId;
	int32_t m_stationId;
	DECLARE_IDCREATE(NFTransQueryCoinBalance)
};
