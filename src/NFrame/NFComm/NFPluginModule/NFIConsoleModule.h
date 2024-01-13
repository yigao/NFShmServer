// -------------------------------------------------------------------------
//    @FileName         :    NFIConsoleModule.h
//    @Author           :    Yi.Gao
//    @Date             :   2022-09-18
//    @Module           :    NFPluginModule
//
// -------------------------------------------------------------------------

#pragma once

#include "NFIModule.h"
#include "NFIDynamicModule.h"

class NFIConsoleModule : public NFIDynamicModule
{
public:
	NFIConsoleModule(NFIPluginManager* p) :NFIDynamicModule(p)
	{

	}

	virtual ~NFIConsoleModule()
	{

	}

	virtual void AddDynamicPluginFile(const std::string& file) = 0;
};
