// -------------------------------------------------------------------------
//    @FileName         :    NFGameServerPlugin.h
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFGameServerPlugin
//
// -------------------------------------------------------------------------

#pragma once

#include "NFComm/NFPluginModule/NFIPlugin.h"
#include "NFComm/NFPluginModule/NFIPluginManager.h"
#include <string>

//////////////////////////////////////////////////////////////////////////
class NFLoginServerPlayerPlugin : public NFIPlugin
{
public:
	explicit NFLoginServerPlayerPlugin(NFIPluginManager* p): NFIPlugin(p)
	{
	}

	virtual int GetPluginVersion() override;

	virtual std::string GetPluginName() override;

	virtual void Install() override;

	virtual void Uninstall() override;

	virtual bool InitShmObjectRegister() override;
};

