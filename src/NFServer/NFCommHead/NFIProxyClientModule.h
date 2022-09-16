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
#include "NFServerComm/NFServerCore/NFServerCommonDefine.h"

class NFIProxyClientModule : public NFIDynamicModule
{
public:
	NFIProxyClientModule(NFIPluginManager* p) :NFIDynamicModule(p)
	{

	}
	virtual ~NFIProxyClientModule()
	{

	}

	virtual int OnHandleOtherServerOtherMessage(uint64_t unLinkId, const NFDataPackage& packet) = 0;
};
