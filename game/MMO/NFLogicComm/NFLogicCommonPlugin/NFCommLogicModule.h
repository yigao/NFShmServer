// -------------------------------------------------------------------------
//    @FileName         :    NFCommLogicModule.h
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFCommLogicPlugin
//
// -------------------------------------------------------------------------

#pragma once


#include "NFLogicCommon/NFFishDynamicModule.h"


class NFCommLogicModule : public NFFishDynamicModule
{
public:
	NFCommLogicModule(NFIPluginManager* p) :NFFishDynamicModule(p)
	{

	}

	virtual ~NFCommLogicModule()
	{

	}

    virtual bool Awake();
};