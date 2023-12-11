// -------------------------------------------------------------------------
//    @FileName         :    NFBattleBuffPart.h
//    @Author           :    gaoyi
//    @Date             :    23-12-11
//    @Email			:    445267987@qq.com
//    @Module           :    NFBattleBuffPart
//
// -------------------------------------------------------------------------

#pragma once

#include "NFComm/NFCore/NFPlatform.h"
#include "NFLogicCommon/NFLogicShmTypeDefines.h"
#include "NFComm/NFShmCore/NFShmObjTemplate.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmCore/NFShmObj.h"
#include "NFBattlePart.h"

class NFBattleBuffPart : public NFShmObjTemplate<NFBattleBuffPart, EOT_NFBattlePart_ID+BATTLE_PART_MOVE, NFBattlePart>
{
public:
    NFBattleBuffPart();
    
    virtual ~NFBattleBuffPart();
    
    int CreateInit();
    
    int ResumeInit();
public:
    //ÄÜ·ñÒÆ¶¯
    bool CanMove() { return true; }
};