// -------------------------------------------------------------------------
//    @FileName         :    NFWorldRoomMgr.h
//    @Author           :    gaoyi
//    @Date             :    23-7-28
//    @Email			:    445267987@qq.com
//    @Module           :    NFWorldRoomMgr
//
// -------------------------------------------------------------------------

#pragma once


#include "NFComm/NFCore/NFPlatform.h"
#include "NFComm/NFShmCore/NFShmObj.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmCore/NFISharedMemModule.h"
#include "NFWorldRoom.h"

class NFWorldRoomMgr : public NFShmObj
{
public:
    NFWorldRoomMgr();

    virtual ~NFWorldRoomMgr();

    int CreateInit();

    int ResumeInit();
public:
    NFWorldRoom* CreateRoom(uint32_t id);
    NFWorldRoom* GetRoom(uint32_t gameId, uint32_t roomId);
public:
    /**
     * @brief 根据配置创建全部房间信息
     * @return
     */
    int CreateRoom();
private:
    bool m_inited;
DECLARE_IDCREATE(NFWorldRoomMgr)
};