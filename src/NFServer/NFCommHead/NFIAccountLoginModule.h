// -------------------------------------------------------------------------
//    @FileName         :    NFIAccountLoginModule.h
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFIAccountLoginModule
//
// -------------------------------------------------------------------------

#pragma once

#include "NFComm/NFPluginModule/NFIDynamicModule.h"

class NFIAccountLoginModule : public NFIDynamicModule
{
public:
	NFIAccountLoginModule(NFIPluginManager* p) :NFIDynamicModule(p)
	{

	}

	virtual ~NFIAccountLoginModule()
	{

	}
};
