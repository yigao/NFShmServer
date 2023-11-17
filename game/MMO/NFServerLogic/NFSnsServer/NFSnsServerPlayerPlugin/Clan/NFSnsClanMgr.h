// -------------------------------------------------------------------------
//    @FileName         :    NFSnsClanMgr.h
//    @Author           :    gaoyi
//    @Date             :    23-11-16
//    @Email			:    445267987@qq.com
//    @Module           :    NFSnsClanMgr
//
// -------------------------------------------------------------------------

#pragma once

#include <NFGameCommon/NFComTypeDefine.h>
#include <ObService/NFObService.h>

#include "NFComm/NFCore/NFPlatform.h"
#include "NFLogicCommon/NFLogicShmTypeDefines.h"
#include "NFComm/NFShmCore/NFShmObjTemplate.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmCore/NFShmObj.h"

//团队
struct stClanInfo
{
    uint64_t		clan_id = 0;
    int32_t			zid = 0;
    std::string		name;
    int32_t			score = 0;
    int32_t			badge_id = 0;				//战徽id
    std::string		badge_name;					//战徽名称
    std::string		notice;
    uint64_t		leader_cid = 0;				//队长
    SET_UINT64		members;					//成员ID
    SET_UINT64		refuse_list;				//今日拒绝申请玩家列表
    VEC_INT64		apply_list;					//申请列表
    uint64_t		update_score_time = 0;		//更新积分时间
    int32_t			clan_join_num = 0;			//战队总场次
    int32_t			clan_win_num = 0;			//战队胜场
    SET_INT32		open_badge;					//解锁的勋章
    uint64_t		refresh_time = 0;			//刷新时间
    uint64_t		fight = 0;					//团队战力
};

class NFSnsClanMgr : public NFShmObjTemplate<NFSnsClanMgr, EOT_SNS_SERVICE_ID+SNS_OB_SERVICE_CLAN, NFObService>
{
public:
    NFSnsClanMgr();
    
    virtual ~NFSnsClanMgr();
    
    int CreateInit();
    int ResumeInit();

    const stClanInfo*   GetClan3Info(uint64_t cid) { return nullptr; }
    const stClanInfo*	GetClan5Info(uint64_t icd) { return nullptr; }
};