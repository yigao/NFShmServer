// -------------------------------------------------------------------------
//    @FileName         :    NFIConsoleModule.h
//    @Author           :    Yi.Gao
//    @Date             :   2022-09-18
//    @Module           :    NFPluginModule
//
// -------------------------------------------------------------------------

#pragma once

#include "NFIModule.h"

class NFIConsoleModule : public NFIModule
{
public:
	NFIConsoleModule(NFIPluginManager* p) :NFIModule(p)
	{

	}

	virtual ~NFIConsoleModule()
	{

	}

	virtual void AddDynamicPluginFile(const std::string& file) = 0;
};
