// -------------------------------------------------------------------------
//    @FileName         :    NFRoleDescStoreEx.h
//    @Author           :    gaoyi
//    @Date             :    22-11-30
//    @Email			:    445267987@qq.com
//    @Module           :    NFRoleDescStoreEx
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

class NFRoleDescStoreEx : public NFIDescStore
{
public:
    NFRoleDescStoreEx();

    virtual ~NFRoleDescStoreEx();

    int CreateInit();

    int ResumeInit();

    //获取最大等级
    uint32_t MaxLevel() { return m_maxLevel; }
private:
    uint32_t m_maxLevel;
DECLARE_IDCREATE(NFRoleDescStoreEx)
IMPL_RES_SIMPLE_DESC(NFRoleDescStoreEx);
};