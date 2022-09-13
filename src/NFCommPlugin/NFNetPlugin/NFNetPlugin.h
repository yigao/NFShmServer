//------------------------------------------------------------------------ -
//    @FileName         :    NFNetPlugin.h
//    @Author           :    LvSheng.Huang
//    @Date             :   xxxx-xx-xx
//    @Module           :    NFNetPlugin
//
// -------------------------------------------------------------------------

#pragma once

#include "NFComm/NFPluginModule/NFIPlugin.h"
#include "NFComm/NFPluginModule/NFIPluginManager.h"

//////////////////////////////////////////////////////////////////////////
class NFNetPlugin : public NFIPlugin
{
public:
	explicit NFNetPlugin(NFIPluginManager* p):NFIPlugin(p)
	{

	}

	virtual int GetPluginVersion() override;

	virtual std::string GetPluginName() override;

	virtual void Install() override;

	virtual void Uninstall() override;

	virtual bool IsDynamicLoad() override;
};
