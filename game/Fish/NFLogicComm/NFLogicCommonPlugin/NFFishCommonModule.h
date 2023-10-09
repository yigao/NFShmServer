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


class NFFishCommonModule : public NFFishDynamicModule
{
public:
	NFFishCommonModule(NFIPluginManager* p) : NFFishDynamicModule(p)
	{

	}

	virtual ~NFFishCommonModule()
	{

	}

    virtual bool Awake();
};