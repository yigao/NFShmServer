// -------------------------------------------------------------------------
//    @FileName         :    NFShmSubcribeInfo.h
//    @Author           :    Gao.Yi
//    @Date             :   2022-09-18
//    @Email			:    445267987@qq.com
//    @Module           :    NFShmSubcribeInfo.h
//
// -------------------------------------------------------------------------

#pragma once

#include "NFComm/NFCore/NFPlatform.h"
#include "NFComm/NFPluginModule/NFLogMgr.h"
#include <stddef.h>
#include <string.h>
#include <NFComm/NFShmCore/NFTypeDefines.h>
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmCore/NFShmObj.h"
#include "NFComm/NFShmCore/NFShmPtr.h"
#include "NFComm/NFShmCore/NFShmString.h"
#include "NFComm/NFShmCore/NFShmNodeList.h"
#include "NFShmEventKey.h"

enum {
    NF_SHM_SUBSCRIBEINFO_EVENT_KEY_INDEX_0 = 0,
    NF_SHM_SUBSCRIBEINFO_SHM_OBJ_INDEX_1 = 1,
    NF_SHM_SUBSCRIBEINFO_MAX_INDEX_NUM = 2,
};

/**
 *@brief 事件描述信息
 */
class NFShmSubscribeInfo : public NFShmObj, public NFMultiListNodeObjWithGlobalID<NFShmSubscribeInfo, EOT_TYPE_SUBSCRIBEINFO_OBJ, NF_SHM_SUBSCRIBEINFO_MAX_INDEX_NUM>
{
public:
    NFShmSubscribeInfo();

    int CreateInit();

    int ResumeInit();

    /**
    *@brief 增加引用
    */
    void Add();

    /**
    *@brief 减少引用
    */
    void Sub();

    std::string ToString() const
    {
        return NF_FORMAT("refCount:{},removeFlag:{},desc:{},eventKey:{},shmObjId:{}", nRefCount, bRemoveFlag, szDesc.ToString(), m_eventKey.ToString(), m_shmObjId);
    }
public:
    /**
    *@brief 事件对象
    */
    NFShmPtr<NFShmObj> pSink;

    /**
    *@brief 引用次数
    */
    int32_t nRefCount;

    /**
    *@brief 移除标志
    */
    bool bRemoveFlag;

    /**
    *@brief 描述信息
    */
    NFShmString<32> szDesc;

    /**
     * @brief
     */
    NFShmEventKey m_eventKey;

    /**
     * @brief
     */
    int m_shmObjId;
DECLARE_IDCREATE(NFShmSubscribeInfo)
};
