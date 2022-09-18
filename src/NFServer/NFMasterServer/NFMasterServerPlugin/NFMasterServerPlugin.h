// -------------------------------------------------------------------------
//    @FileName         :    NFMasterServerPlugin.h
//    @Author           :    Gao.Yi
//    @Date             :   2022-09-18
//    @Email			:    445267987@qq.com
//    @Module           :    NFMasterServerPlugin
//
// -------------------------------------------------------------------------

#pragma once

#include "NFComm/NFPluginModule/NFIPlugin.h"
#include "NFComm/NFPluginModule/NFIPluginManager.h"
#include <string>

//////////////////////////////////////////////////////////////////////////
class NFMasterServerPlugin : public NFIPlugin
{
public:
	explicit NFMasterServerPlugin(NFIPluginManager* p):NFIPlugin(p)
	{
		
	}

	virtual int GetPluginVersion() override;

	virtual std::string GetPluginName() override;

	virtual void Install() override;

	virtual void Uninstall() override;
};

