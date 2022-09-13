// -------------------------------------------------------------------------
//    @FileName         :    NFOnlineUserHashTable.h
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFOnlineUserHashTable.h
//
// -------------------------------------------------------------------------

#pragma once

#include "NFComm/NFShmCore/NFShmObj.h"
#include "NFComm/NFShmCore/NFShmHashMap.h"
#include "NFServer/NFCommHead/NFCommLogicHead.h"
class NFOnlineUser;

class NFOnlineUserMgr: public NFShmObj
{
public:
    NFOnlineUserMgr();

    virtual ~NFOnlineUserMgr()
    {
    }

    int CreateInit();

    int ResumeInit();

    NFOnlineUser * Find(uint64_t ullRoleID);

    NFOnlineUser* Insert(uint64_t ullRoleID);

    int Delete(uint64_t ullRoleID);

    bool IsFull();
private:
DECLARE_IDCREATE(NFOnlineUserMgr)
};