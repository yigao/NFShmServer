// -------------------------------------------------------------------------
//    @FileName         :    NFShmTimerObj.h
//    @Author           :    gaoyi
//    @Date             :    23-9-25
//    @Email			:    445267987@qq.com
//    @Module           :    NFShmTimerObj
//
// -------------------------------------------------------------------------

#pragma once


#include "NFComm/NFCore/NFPlatform.h"
#include "NFComm/NFShmCore/NFShmObj.h"
#include "NFComm/NFShmCore/NFShmPtr.h"

class NFRawShmObj
{
public:
    NFRawShmObj();

    virtual ~NFRawShmObj();

    int CreateInit();

    int ResumeInit();
public:
    int InitShmObj(NFShmObj* pShmObj);
    NFShmObj* GetShmObj();
public:
    virtual int OnTimer(int timeId, int callcount);
protected:
    NFShmPtr<NFShmObj> m_pShmObj;
};