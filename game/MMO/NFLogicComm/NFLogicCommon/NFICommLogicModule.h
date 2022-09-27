// -------------------------------------------------------------------------
//    @FileName         :    NFICommLogicModule.h
//    @Author           :    Gao.Yi
//    @Date             :   2022-09-18
//    @Email			:    445267987@qq.com
//    @Module           :    NFCommLogicPlugin
//
// -------------------------------------------------------------------------

#pragma once

#include "NFComm/NFCore/NFPlatform.h"
#include "NFComm/NFPluginModule/NFIModule.h"
#include "NFComm/NFPluginModule/NFConfigDefine.h"
#include "NFComm/NFPluginModule/NFIDynamicModule.h"

class NFICommLogicModule : public NFIDynamicModule
{
public:
	NFICommLogicModule(NFIPluginManager* p) :NFIDynamicModule(p)
	{

	}

	virtual ~NFICommLogicModule()
	{

	}
};

