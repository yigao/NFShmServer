// -------------------------------------------------------------------------
//    @FileName         :    NFIBusModule.h
//    @Author           :    Yi.Gao
//    @Date             :   xxxx-xx-xx
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
