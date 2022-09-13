// -------------------------------------------------------------------------
//    @FileName         :    NFPhoneAutoCodeMgr.h
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFPhoneAutoCodeMgr.h
//
// -------------------------------------------------------------------------

#pragma once

#include "NFComm/NFShmCore/NFShmObj.h"
#include "NFComm/NFShmCore/NFShmHashMap.h"
#include "NFComm/NFShmCore/NFSizeString.h"
#include "NFServer/NFCommHead/NFCommLogicHead.h"
#include "NFComm/NFShmCore/NFServerFrameTypeDefines.h"

class NFPhoneAutoCode: public NFShmObj
{
public:
    NFPhoneAutoCode();
    virtual ~NFPhoneAutoCode();
    int CreateInit();
    int ResumeInit();

public:
    uint64_t m_phoneNum;
    uint64_t m_lastTime;
    bool m_checkSuccess;
    uint32_t m_codeType;
DECLARE_IDCREATE(NFPhoneAutoCode)
};

class NFPhoneAutoCodeMgr: public NFShmObj
{
public:
    NFPhoneAutoCodeMgr();

    virtual ~NFPhoneAutoCodeMgr();

    int CreateInit();
    int ResumeInit();

    //must be virtual
    virtual void OnTimer(int timeId, int callcount);

    int Tick();

    int ReleaseNum(int num);

    bool IsFull() { return NFPhoneAutoCode::GetUsedCount() >= NFPhoneAutoCode::GetItemCount();}
    NFPhoneAutoCode *FindPhone(uint64_t phoneNum);
    NFPhoneAutoCode *CreatePhone(uint64_t phoneNum);
    int DeletePhone(uint64_t phoneNum);
private:
    int m_timerId;
DECLARE_IDCREATE(NFPhoneAutoCodeMgr)
};