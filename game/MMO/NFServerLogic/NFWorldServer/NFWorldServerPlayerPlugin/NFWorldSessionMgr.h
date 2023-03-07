// -------------------------------------------------------------------------
//    @FileName         :    NFWorldSessionMgr.h
//    @Author           :    gaoyi
//    @Date             :    22-10-28
//    @Email			:    445267987@qq.com
//    @Module           :    NFWorldSessionMgr
//
// -------------------------------------------------------------------------

#pragma once

#include "NFComm/NFShmCore/NFShmObj.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmCore/NFISharedMemModule.h"
#include "NFLogicCommon/NFServerFrameTypeDefines.h"
#include "NFLogicCommon/NFLogicCommonDefine.h"
#include "NFWorldCommonDefine.h"

class NFWorldSession;
class NFWorldSessionMgr : public NFShmObj
{
public:
    NFWorldSessionMgr();

    virtual ~NFWorldSessionMgr();

    int CreateInit();

    int ResumeInit();
public:
    /**
     * @brief 通过clientId获取Seesion数据
     * @param clientId
     * @return
     */
    NFWorldSession *GetSession(uint64_t clientId);

    /**
     * @brief 通过clientId创建Session数据, 如果玩家存在，返回NULL
     * @param ClientId
     * @return
     */
    NFWorldSession *CreateSession(uint64_t ClientId);

    /**
     * @brief 删除Session数据
     * @param pSession
     * @return
     */
    int DeleteSession(NFWorldSession *pSession);

    int DeleteSessionByClientId(uint64_t clientId);
private:
DECLARE_IDCREATE(NFWorldSessionMgr)
};