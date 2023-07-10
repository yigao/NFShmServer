// -------------------------------------------------------------------------
//    @FileName         :    NFTransGetUserDetail.cpp
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFTransGetUserDetail.cpp
//
// -------------------------------------------------------------------------

#include "NFTransSaveDB.h"

#include "NFComm/NFPluginModule/NFLogMgr.h"
#include "NFComm/NFPluginModule/NFCheck.h"
#include "NFComm/NFKernelMessage/storesvr_sqldata.pb.h"
#include "NFLogicCommon/NFLogicShmTypeDefines.h"
#include "NFComm/NFCore/NFTime.h"

#include "Player/NFPlayer.h"
#include "NFComm/NFPluginModule/NFICoroutineModule.h"
#include "NFServerComm/NFServerCommon/NFIServerMessageModule.h"

IMPLEMENT_IDCREATE_WITHTYPE(NFTransSaveDB, EOT_TRANS_SAVE_PLAYER, NFTransPlayerBase)

NFTransSaveDB::NFTransSaveDB() {
	if (NFShmMgr::Instance()->GetCreateMode() == EN_OBJ_MODE_INIT) {
		CreateInit();
	}
	else {
		ResumeInit();
	}
}

NFTransSaveDB::~NFTransSaveDB() {

}

int NFTransSaveDB::CreateInit() {
    m_curSeq = 0;
    m_reason = TRANS_SAVEROLEDETAIL_NORMAL;
	return 0;
}

int NFTransSaveDB::ResumeInit() {
	return 0;
}

int NFTransSaveDB::SaveDB(TRANS_SAVEROLEDETAIL_REASON iReason)
{
	NFPlayer* pPlayer = GetPlayer();
	CHECK_EXPR(pPlayer, -1, "Save Failed! Can't find player data, userId:{}", m_playerId);
	
	m_reason = iReason;
    m_curSeq = pPlayer->GetCurSeq();
    pPlayer->SetLastSaveDBTime(NFTime::Now().UnixSec());

	proto_ff::tbFishPlayerData tbData;
    tbData.set_player_id(m_playerId);
    pPlayer->SaveDB(tbData);
	NFLogTrace(NF_LOG_SYSTEMLOG, m_playerId, "Ready Save Player InTo Mysql:{}", tbData.DebugString());

    m_rpcId = FindModule<NFIServerMessageModule>()->GetRpcModifyObjService(NF_ST_LOGIC_SERVER, m_playerId, tbData, [this](int rpcRetCode) {
        if (rpcRetCode == 0)
        {
            NFPlayer* pPlayer = GetPlayer();
            if (pPlayer)
            {
                pPlayer->OnSaveDB(true, m_curSeq);
                if (m_reason == TRANS_SAVEROLEDETAIL_LOGOUT && pPlayer->GetStatus() == proto_ff::PLAYER_STATUS_LOGOUT)
                {
                    pPlayer->OnLogout();
                }
            }
        }

        SetFinished(rpcRetCode);
    });

	return 0;
}

int NFTransSaveDB::HandleTransFinished(int iRunLogicRetCode) {
	if (iRunLogicRetCode != 0) {
		NFPlayer *pPlayer = GetPlayer();
		if (pPlayer) {
            pPlayer->OnSaveDB(false, 0);
		}
		return iRunLogicRetCode;
	}

	return 0;
}
