// -------------------------------------------------------------------------
//    @FileName         :    NFIGameServerModule.h
//    @Author           :    Gao.Yi
//    @Date             :   2022-09-18
//    @Email			:    445267987@qq.com
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

