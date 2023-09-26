// -------------------------------------------------------------------------
//    @FileName         :    NFFIshTypeBaseData.h
//    @Author           :    gaoyi
//    @Date             :    23-9-26
//    @Email			:    445267987@qq.com
//    @Module           :    NFFIshTypeBaseData
//
// -------------------------------------------------------------------------

#pragma once


#include "NFComm/NFCore/NFPlatform.h"
#include "NFComm/NFShmCore/NFRawTimerObj.h"

class NFGameFishPlayer;
class NFFishTypeHandler;
class NFGameFishDesk;
class NFFishTypeBaseData: public NFRawTimerObj<2>
{
public:
    NFFishTypeBaseData();

    virtual ~NFFishTypeBaseData();

    int CreateInit();

    int ResumeInit();
public:
    NFGameFishPlayer* GetPlayer(uint64_t playerId);
    NFFishTypeHandler* GetFishTypeHandler();
    NFGameFishDesk* GetDesk();
};