// -------------------------------------------------------------------------
//    @FileName         :    NFSnsTransSaveDetailDB.cpp
//    @Author           :    gaoyi
//    @Date             :    23-7-14
//    @Email			:    445267987@qq.com
//    @Module           :    NFSnsTransSaveDetailDB
//
// -------------------------------------------------------------------------

#include "NFSnsTransSaveDetailDB.h"
#include "NFLogicCommon/NFLogicShmTypeDefines.h"
#include "Cache/NFPlayerDetail.h"
#include "NFServerComm/NFServerCommon/NFIServerMessageModule.h"
#include "Cache/NFCacheMgr.h"


IMPLEMENT_IDCREATE_WITHTYPE(NFSnsTransSaveDetailDB, EOT_SNS_TRANS_SAVE_PLAYER_DETAIL, NFTransBase)

NFSnsTransSaveDetailDB::NFSnsTransSaveDetailDB() {
    if (NFShmMgr::Instance()->GetCreateMode() == EN_OBJ_MODE_INIT) {
        CreateInit();
    }
    else {
        ResumeInit();
    }
}

NFSnsTransSaveDetailDB::~NFSnsTransSaveDetailDB() {

}

int NFSnsTransSaveDetailDB::CreateInit() {
    m_curSeq = 0;
    m_playerId = 0;
    return 0;
}

int NFSnsTransSaveDetailDB::ResumeInit() {
    return 0;
}

int NFSnsTransSaveDetailDB::SaveDB(NFPlayerDetail* pPlayer)
{
    CHECK_EXPR(pPlayer, -1, "Save Failed! Can't find player data, userId:{}", m_playerId);

    m_playerId = pPlayer->GetPlayerId();
    m_curSeq = pPlayer->GetAllSeq();
    pPlayer->SetLastSaveDBTime(NFTime::Now().UnixSec());

    proto_ff::tbFishSnsPlayerDetailData tbData;
    tbData.set_player_id(m_playerId);
    pPlayer->SaveDB(tbData);
    NFLogTrace(NF_LOG_SYSTEMLOG, m_playerId, "Ready Save Sns Player Detail InTo Mysql:{}", tbData.DebugString());

    m_rpcId = FindModule<NFIServerMessageModule>()->GetRpcModifyObjService(NF_ST_SNS_SERVER, m_playerId, tbData, [this](int rpcRetCode) {
        if (rpcRetCode == 0)
        {
            NFPlayerDetail* pPlayer = NFCacheMgr::Instance(m_pObjPluginManager)->GetPlayerDetail(m_playerId);
            if (pPlayer)
            {
                pPlayer->OnSaveDB(true, m_curSeq);
            }
        }

        SetFinished(rpcRetCode);
    });

    if (m_rpcId == INVALID_ID)
    {
        return proto_ff::ERR_CODE_RPC_SYSTEM_ERROR;
    }

    return 0;
}

int NFSnsTransSaveDetailDB::HandleTransFinished(int iRunLogicRetCode) {
    if (iRunLogicRetCode != 0) {
        NFPlayerDetail* pPlayer = NFCacheMgr::Instance(m_pObjPluginManager)->GetPlayerDetail(m_playerId);
        if (pPlayer) {
            pPlayer->OnSaveDB(false, 0);
        }
        return iRunLogicRetCode;
    }

    return 0;
}
