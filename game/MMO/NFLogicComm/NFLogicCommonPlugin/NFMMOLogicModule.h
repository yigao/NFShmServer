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


class NFMMOLogicModule : public NFMMODynamicModule
{
public:
	NFMMOLogicModule(NFIPluginManager* p) : NFMMODynamicModule(p)
	{

	}

	virtual ~NFMMOLogicModule()
	{

	}

    virtual bool Awake();
};