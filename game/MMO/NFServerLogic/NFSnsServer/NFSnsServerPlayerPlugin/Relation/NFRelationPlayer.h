// -------------------------------------------------------------------------
//    @FileName         :    NFRelationPlayer.h
//    @Author           :    gaoyi
//    @Date             :    23-4-3
//    @Email			:    445267987@qq.com
//    @Module           :    NFRelationPlayer
//
// -------------------------------------------------------------------------

#pragma once


#include "NFComm/NFCore/NFPlatform.h"
#include "NFComm/NFShmCore/NFShmObj.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFServerFrameTypeDefines.h"
#include "NFComm/NFShmCore/NFISharedMemModule.h"
#include "NFComm/NFShmCore/NFShmString.h"

//基本关系数据
struct NFRelationCommonPlayer
{
    NFRelationCommonPlayer();

    virtual ~NFRelationCommonPlayer();

    int CreateInit();

    int ResumeInit();

    uint64_t m_cid;
};

//最近联系人玩家结构体
struct NFRelationRecentPlayer : public NFRelationCommonPlayer
{
    NFRelationRecentPlayer();

    virtual ~NFRelationRecentPlayer();

    int CreateInit();

    int ResumeInit();

    uint32_t m_recentType; //交互类型
    uint64_t m_recentTime; //最后一次交互的时间
};

//好友玩家结构体
struct NFRelationFriendPlayer : public NFRelationCommonPlayer
{
    NFRelationFriendPlayer();

    virtual ~NFRelationFriendPlayer();

    int CreateInit();

    int ResumeInit();

    uint32_t closeness;            //亲密度
    uint32_t closenessLevel;    //亲密度等级 （不存库，每次登陆时重新计算）
    uint32_t todayCloseness;    //今天获得的亲密度值 （每天刷新，玩家身上保存刷新时间，每天定时重置亲密度值）
    uint64_t updateTime;        //亲密度刷新时间
};

//仇人玩家结构体
struct NFRelationHatePlayer : public NFRelationCommonPlayer
{
    NFRelationHatePlayer();
    virtual ~NFRelationHatePlayer();

    int CreateInit();

    int ResumeInit();
    uint32_t m_killMeTimes; //杀我的次数
};

//好友申请结构体
struct NFRelationApplyPlayer : public NFRelationCommonPlayer
{
    NFRelationApplyPlayer();
    virtual ~NFRelationApplyPlayer();

    int CreateInit();

    int ResumeInit();

    NFShmString<32> m_sConnect;    //介绍
};

