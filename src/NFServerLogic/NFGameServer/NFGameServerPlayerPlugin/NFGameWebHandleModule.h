// -------------------------------------------------------------------------
//    @FileName         :    NFCUserWebHandleModule.h
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFCUserWebHandleModule.h
//
// -------------------------------------------------------------------------

#pragma once

#include "NFComm/NFPluginModule/NFServerDefine.h"
#include "NFComm/NFCore/NFMapEx.hpp"
#include "NFComm/NFCore/NFMap.hpp"
#include "NFServer/NFCommHead/NFCommLogicHead.h"
#include "NFComm/NFPluginModule/NFIDynamicModule.h"

class NFCGameWebHandleModule : public NFIDynamicModule
{
public:
    explicit NFCGameWebHandleModule(NFIPluginManager *p);

    virtual ~NFCGameWebHandleModule();

    virtual bool Awake() override;
public:

    int OnHandleClearJiangChi(uint64_t unLinkId, uint64_t value, uint64_t value2, uint32_t nMsgId, const char* msg, uint32_t nLen);
    int OnHandleSetJiangChi(uint64_t unLinkId, uint64_t value, uint64_t value2, uint32_t nMsgId, const char* msg, uint32_t nLen);
};