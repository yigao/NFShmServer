// -------------------------------------------------------------------------
//    @FileName         :    NFIConsoleModule.h
//    @Author           :    Yi.Gao
//    @Date             :   xxxx-xx-xx
//    @Module           :    NFPluginModule
//
// -------------------------------------------------------------------------

#pragma once

#include "NFIModule.h"

class NFIConsoleModule : public NFIModule
{
NF_MODULE_STATIC_CONST_MODULE_ID(NF_CONSOLE_MODULE_ID)
public:
	NFIConsoleModule(NFIPluginManager* p) :NFIModule(p)
	{

	}

	virtual ~NFIConsoleModule()
	{

	}

	virtual void AddDynamicPluginFile(const std::string& file) = 0;
};
