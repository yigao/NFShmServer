// -------------------------------------------------------------------------
//    @FileName         :    NFIGameServerModule.h
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFServerCommon
//
// -------------------------------------------------------------------------

#pragma once

#include "NFComm/NFPluginModule/NFIDynamicModule.h"

class NFIRouteServerModule : public NFIDynamicModule
{
public:
	NFIRouteServerModule(NFIPluginManager* p) :NFIDynamicModule(p)
	{

	}

	virtual ~NFIRouteServerModule()
	{

	}
};
