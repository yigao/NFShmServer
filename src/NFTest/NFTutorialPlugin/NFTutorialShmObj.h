// -------------------------------------------------------------------------
//    @FileName         :    NFTutorialShmObj.h
//    @Author           :    gaoyi
//    @Date             :    24-1-13
//    @Email			:    445267987@qq.com
//    @Module           :    NFTutorialShmObj
//
// -------------------------------------------------------------------------

#pragma once


#include "NFComm/NFCore/NFPlatform.h"
#include "NFComm/NFShmCore/NFShmObj.h"

class NFTutorialShmObj : public NFShmObjTemplate<NFTutorialShmObj, 100, NFShmObj>
{
public:
    NFTutorialShmObj();
    
    virtual ~NFTutorialShmObj();
    
    int CreateInit();
    int ResumeInit();

    virtual int OnTimer(int timeId, int callcount);
private:
    uint32_t m_idCount;
    int m_timerId;
};