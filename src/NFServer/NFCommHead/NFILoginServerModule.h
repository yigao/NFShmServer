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
class NFServerData;

class NFILoginServerModule : public NFIDynamicModule
{
public:
	NFILoginServerModule(NFIPluginManager* p) :NFIDynamicModule(p)
	{

	}

	virtual ~NFILoginServerModule()
	{

	}
};

