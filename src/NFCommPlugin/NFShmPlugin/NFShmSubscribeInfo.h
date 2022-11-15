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
#include "NFComm/NFShmCore/NFSizeString.h"
#include "NFComm/NFShmCore/NFShmNodeList.h"

/**
 *@brief 事件描述信息
 */
class NFShmSubscribeInfo : public NFShmObj, public NFListNodeObjWithGlobalID<NFShmSubscribeInfo, EOT_TYPE_SUBSCRIBEINFO_OBJ>
{
public:
    NFShmSubscribeInfo(NFIPluginManager* pPluginManager);

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
    NFSizeString<16> szDesc;
DECLARE_IDCREATE(NFShmSubscribeInfo)
};
