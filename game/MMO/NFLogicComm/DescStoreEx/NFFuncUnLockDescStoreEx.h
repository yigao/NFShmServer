// -------------------------------------------------------------------------
//    @FileName         :    NFFuncUnLockDescStoreEx.h
//    @Author           :    gaoyi
//    @Date             :    22-11-30
//    @Email			:    445267987@qq.com
//    @Module           :    NFFuncUnLockDescStoreEx
//
// -------------------------------------------------------------------------

#pragma once


#include "NFComm/NFCore/NFPlatform.h"
#include "NFComm/NFShmCore/NFShmObj.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFServerFrameTypeDefines.h"
#include "NFComm/NFShmCore/NFISharedMemModule.h"
#include "NFServerComm/NFDescStorePlugin/NFIDescStore.h"
#include "NFLogicCommon/NFDescStoreTypeDefines.h"
#include "NFLogicCommon/NFComTypeDefine.h"

#define MAX_FUNC_UNLOCK_OPEN_TYPE_NUMBER 10
#define MAX_FUNC_UNLOCK_OPEN_VAL_NUMBER 100
#define MAX_FUNC_UNLOCK_OPEN_VAL_FUNC_NUM 500

class NFFuncUnLockDescStoreEx : public NFIDescStore
{
public:
    NFFuncUnLockDescStoreEx();

    virtual ~NFFuncUnLockDescStoreEx();

    int CreateInit();

    int ResumeInit();
public:
    //根据解锁类型和解锁值 获取对应的功能列表
    NFShmHashMap<uint64_t, bool, MAX_FUNC_UNLOCK_OPEN_VAL_FUNC_NUM>* GetUnlockFunctionList(uint32_t nType, uint64_t nValue, bool externFlag = false);
private:
    //任务解锁的 分类数据  map<解锁类型，map<解锁值，set<功能ID> > >
    NFShmHashMap<uint32_t, NFShmHashMap<uint64_t, NFShmHashMap<uint64_t, bool, MAX_FUNC_UNLOCK_OPEN_VAL_FUNC_NUM>, MAX_FUNC_UNLOCK_OPEN_VAL_NUMBER>, MAX_FUNC_UNLOCK_OPEN_TYPE_NUMBER> m_mapUnlockCfg;
DECLARE_IDCREATE(NFFuncUnLockDescStoreEx)
IMPL_RES_SIMPLE_DESC(NFFuncUnLockDescStoreEx);
};