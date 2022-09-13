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

class NFIRouteAgentServerModule : public NFIDynamicModule
{
public:
	NFIRouteAgentServerModule(NFIPluginManager* p) :NFIDynamicModule(p)
	{

	}

	virtual ~NFIRouteAgentServerModule()
	{

	}

};

