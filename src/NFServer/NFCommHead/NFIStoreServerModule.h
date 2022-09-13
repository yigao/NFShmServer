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

class NFIStoreServerModule : public NFIDynamicModule
{
public:
	NFIStoreServerModule(NFIPluginManager* p) :NFIDynamicModule(p)
	{

	}

	virtual ~NFIStoreServerModule()
	{

	}
};
