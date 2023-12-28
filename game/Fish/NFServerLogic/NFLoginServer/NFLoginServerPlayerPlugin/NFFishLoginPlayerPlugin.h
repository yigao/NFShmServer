// -------------------------------------------------------------------------
//    @FileName         :    NFFishLoginServerPlayerPlugin.h
//    @Author           :    gaoyi
//    @Date             :    23-7-6
//    @Email			:    445267987@qq.com
//    @Module           :    NFFishLoginServerPlayerPlugin
//
// -------------------------------------------------------------------------

#pragma once

#include "NFComm/NFPluginModule/NFIPlugin.h"
#include "NFComm/NFPluginModule/NFIPluginManager.h"
#include <string>

//////////////////////////////////////////////////////////////////////////
class NFFishLoginPlayerPlugin : public NFIPlugin
{
public:
	explicit NFFishLoginPlayerPlugin(NFIPluginManager* p): NFIPlugin(p)
	{
	}

	virtual int GetPluginVersion() override;

	virtual std::string GetPluginName() override;

	virtual void Install() override;

	virtual void Uninstall() override;

	virtual bool InitShmObjectRegister() override;
};
