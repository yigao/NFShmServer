// -------------------------------------------------------------------------
//    @FileName         :    NFIAccountLoginModule.h
//    @Author           :    Gao.Yi
//    @Date             :   2022-09-18
//    @Email			:    445267987@qq.com
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
