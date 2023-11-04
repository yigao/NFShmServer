#pragma once

#include "NFServerComm/NFServerCommon/NFIDescStoreEx.h"
#include "NFServerComm/NFServerCommon/NFIDescTemplate.h"
#include "NFComm/NFShmCore/NFResDb.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmStl/NFShmHashMap.h"
#include "NFComm/NFShmStl/NFShmVector.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "DescStore/FunctionunlockFunctionunlockDesc.h"
#include "NFGameCommon/NFComTypeDefine.h"

#define MAX_FUNCTIONUNLOCK_FUNCTIONUNLOCK_SPECIAL_TYPE_NUM 4

//功能开放解锁类型
enum FunctionUnlockType
{
    FUNCTION_UNLOCK_TYPE_LEVEL	  = 1,	// 等级开放
    FUNCTION_UNLOCK_TYPE_TAST	  = 2,	// 任务开放
    FUNCTION_UNLOCK_TYPE_TRANSFER = 3,	// 转职开放
    FUNCTION_UNLOCK_TYPE_PAYRMB	  = 4,	// 历史总充值人名币
    FUNCTION_UNLOCK_TYPE_VIP_LEV = 5,	// VIP等级
    FUNCTION_UNLOCK_TYPE_SPECIAL = 6,	// 特殊开放类型(由外部系统触发开启,比如使用物品,此类型每次登录时不会重新检查功能是否开启)
    FUNCTION_UNLOCK_TYPE_DUP = 8,		// 副本开放
    FUNCTION_UNLOCK_TYPE_GOD_EVIL = 9,		// 神魔开放
    FUNCTION_UNLOCK_TYPE_BEST_EQ  = 10,	 // 神机装备
    FUNCTION_UNLOCK_TYPE_MARRY_TASK = 11, //结婚领奖
    FUNCTION_UNLOCK_TYPE_RECHARGE = 12, //充值开发/关闭功能
    FUNCTION_UNLOCK_TYPE_TURN_TASK = 13, //完成神体前置任务
    FUNCTION_UNLOCK_TYPE_SOUL_TASK = 14, //完成战魂前置任务
};


//功能开放同步类型
enum FunctionSyncType
{
    FUNCTION_SYNC_TYPE_ALL	  = 1,	// 全部
    FUNCTION_SYNC_TYPE_ADD	  = 2,	// 新增
};

class FunctionunlockDescEx : public NFShmObjGlobalTemplate<FunctionunlockDescEx, EOT_CONST_FUNCTIONUNLOCK_DESC_EX_ID, NFIDescStoreEx>
{
public:
	FunctionunlockDescEx();
	virtual ~FunctionunlockDescEx();
	int CreateInit();
	int ResumeInit();
public:
	virtual int Load() override;
	virtual int CheckWhenAllDataLoaded() override;
public:
    //根据解锁类型和解锁值 获取对应的功能列表
    const SET_UINT64* GetUnlockFunctionList(uint32_t nType, uint64_t nValue, bool externFlag = false);
protected:
    //任务解锁的 分类数据  map<解锁类型，map<解锁值，vector<系统ID>>>
    MAP_UINT32_MAP_UINT64_VEC_UINT64 m_unlockFuncList;
    
    //任务解锁的 分类数据  map<解锁类型，map<解锁值，set<功能ID> > >
    ORDER_MAP_UINT32_ORDER_MAP_UINT64_SET_UINT64 m_mapUnlockCfg;
};
