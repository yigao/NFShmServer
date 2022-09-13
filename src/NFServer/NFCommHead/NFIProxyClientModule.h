// -------------------------------------------------------------------------
//    @FileName         :    NFIProxyClientModule.h
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFServerCommon
//
// -------------------------------------------------------------------------

#pragma once

#include "NFComm/NFPluginModule/NFIModule.h"
#include "NFComm/NFPluginModule/NFIDynamicModule.h"

class NFIProxyClientModule : public NFIDynamicModule
{
public:
	NFIProxyClientModule(NFIPluginManager* p) :NFIDynamicModule(p)
	{

	}
	virtual ~NFIProxyClientModule()
	{

	}

	virtual int OnHandleOtherServerOtherMessage(uint64_t unLinkId, uint64_t playerId, uint64_t value2, uint32_t nMsgId, const char* msg, uint32_t nLen) = 0;
};
