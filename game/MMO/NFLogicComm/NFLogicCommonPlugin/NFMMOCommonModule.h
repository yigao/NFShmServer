// -------------------------------------------------------------------------
//    @FileName         :    NFCommLogicModule.h
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFCommLogicPlugin
//
// -------------------------------------------------------------------------

#pragma once


#include "NFLogicCommon/NFMMODynamicModule.h"


class NFMMOCommonModule : public NFMMODynamicModule
{
public:
	NFMMOCommonModule(NFIPluginManager* p) : NFMMODynamicModule(p)
	{

	}

	virtual ~NFMMOCommonModule()
	{

	}

    virtual bool Awake();
};