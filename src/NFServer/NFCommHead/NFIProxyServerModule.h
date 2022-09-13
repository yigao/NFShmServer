// -------------------------------------------------------------------------
//    @FileName         :    NFIProxyServerModule.h
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFServerCommon
//
// -------------------------------------------------------------------------

#pragma once

#include "NFComm/NFPluginModule/NFIModule.h"
#include "NFComm/NFPluginModule/NFIDynamicModule.h"

class NFIProxyServerModule : public NFIDynamicModule
{
public:	
	NFIProxyServerModule(NFIPluginManager* p) :NFIDynamicModule(p)
	{

	}

	virtual ~NFIProxyServerModule()
	{
		
	}
};
