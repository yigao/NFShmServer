// -------------------------------------------------------------------------
//    @FileName         :    NFIBusModule.h
//    @Author           :    Yi.Gao
//    @Date             :   2022-09-18
//    @Module           :    NFPluginModule
//
// -------------------------------------------------------------------------

#pragma once

#include "NFIModule.h"
#include <vector>
#include <string>

class NFIBusModule : public NFIModule
{
public:
	NFIBusModule(NFIPluginManager* p) :NFIModule(p)
	{

	}

	virtual ~NFIBusModule()
	{

	}
};
