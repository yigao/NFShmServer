// -------------------------------------------------------------------------
//    @FileName         :    NFKernelPlugin.h
//    @Author           :    LvSheng.Huang
//    @Date             :   2022-09-18
//    @Module           :    NFKernelPlugin
//
// -------------------------------------------------------------------------

#pragma once

#include "NFComm/NFPluginModule/NFIPlugin.h"
#include "NFComm/NFPluginModule/NFIPluginManager.h"

//////////////////////////////////////////////////////////////////////////
class NFKernelPlugin : public NFIPlugin
{
public:
	explicit NFKernelPlugin(NFIPluginManager* p):NFIPlugin(p)
	{

	}

	virtual ~NFKernelPlugin()
	{
	}

	virtual int GetPluginVersion() override;

	virtual std::string GetPluginName() override;

	virtual void Install() override;

	virtual void Uninstall() override;

	virtual bool IsDynamicLoad() override;

	virtual bool InitShmObjectRegister() override;
};

