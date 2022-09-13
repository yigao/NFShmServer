// -------------------------------------------------------------------------
//    @FileName         :    NFMasterServerPlugin.h
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
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

