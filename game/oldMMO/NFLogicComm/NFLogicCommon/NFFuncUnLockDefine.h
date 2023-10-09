// -------------------------------------------------------------------------
//    @FileName         :    NFFuncUnLockDefine.h
//    @Author           :    gaoyi
//    @Date             :    22-11-30
//    @Email			:    445267987@qq.com
//    @Module           :    NFFuncUnLockDefine
//
// -------------------------------------------------------------------------

#pragma once

#pragma once



//功能开放解锁类型
enum FunctionUnlockType
{
    FUNCTION_UNLOCK_TYPE_LEVEL	  = 1,	// 等级开放
    FUNCTION_UNLOCK_TYPE_TAST	  = 2,	// 任务开放
    FUNCTION_UNLOCK_TYPE_TRANSFER = 3,	// 转职开放
    FUNCTION_UNLOCK_TYPE_PAYRMB	  = 4,	// 历史总充值人名币
    FUNCTION_UNLOCK_TYPE_VIP_LEV = 5,	// VIP等级
    FUNCTION_UNLOCK_TYPE_SPECIAL = 6,	// 特殊开放类型(由外部系统触发开启,比如使用物品,此类型每次登录时不会重新检查功能是否开启)
};


//功能开放同步类型
enum FunctionSyncType
{
    FUNCTION_SYNC_TYPE_ALL	  = 1,	// 全部
    FUNCTION_SYNC_TYPE_ADD	  = 2,	// 新增
};
