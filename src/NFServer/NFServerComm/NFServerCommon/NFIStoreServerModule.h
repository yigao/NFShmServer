// -------------------------------------------------------------------------
//    @FileName         :    NFIGameServerModule.h
//    @Author           :    Gao.Yi
//    @Date             :   2022-09-18
//    @Email			:    445267987@qq.com
//    @Module           :    NFServerCommon
//
// -------------------------------------------------------------------------

#pragma once

#include "NFWorkServerModule.h"

class NFIStoreServerModule : public NFWorkServerModule
{
public:
	NFIStoreServerModule(NFIPluginManager* p) :NFWorkServerModule(p, NF_ST_STORE_SERVER)
	{

	}

	virtual ~NFIStoreServerModule()
	{

	}
};
