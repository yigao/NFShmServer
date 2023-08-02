// -------------------------------------------------------------------------
//    @FileName         :    NFCommLogicModule.h
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFCommLogicPlugin
//
// -------------------------------------------------------------------------

#pragma once

#include "NFComm/NFCore/NFPlatform.h"
#include "NFComm/NFPluginModule/NFConfigDefine.h"
#include "NFComm/NFPluginModule/NFIDynamicModule.h"


class NFCommLogicModule : public NFIDynamicModule
{
public:
	NFCommLogicModule(NFIPluginManager* p) :NFIDynamicModule(p)
	{

	}

	virtual ~NFCommLogicModule()
	{

	}

};