// -------------------------------------------------------------------------
//    @FileName         :    NFTransLogicUserBase.h
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFTransLogicUserBase.h
//
// -------------------------------------------------------------------------

#pragma once

#include <NFLogicCommon/NFLogicShmTypeDefines.h>

#include "NFComm/NFShmCore/NFTransBase.h"
#include "NFLogicCommon/NFPlayerDefine.h"

class NFPlayerSimple;

class NFSnsTransSaveSimpleDB : public NFShmObjTemplate<NFSnsTransSaveSimpleDB, EOT_SNS_TRANS_SAVE_PLAYER_SIMPLE, NFTransBase>
{
public:
	NFSnsTransSaveSimpleDB();

	virtual ~NFSnsTransSaveSimpleDB();

	int CreateInit();

	int ResumeInit();

	virtual int HandleTransFinished(int iRunLogicRetCode);
public:
	int SaveDB(NFPlayerSimple* pPlayer);
private:
	uint32_t m_curSeq;
	uint32_t m_playerId;
};
