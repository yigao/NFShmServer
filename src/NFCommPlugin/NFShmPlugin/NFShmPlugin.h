// -------------------------------------------------------------------------
//    @FileName         :    NFKernelPlugin.h
//    @Author           :    LvSheng.Huang
//    @Date             :   xxxx-xx-xx
//    @Module           :    NFKernelPlugin
//
// -------------------------------------------------------------------------

#pragma once

#include "NFComm/NFPluginModule/NFIPlugin.h"
#include "NFComm/NFPluginModule/NFIPluginManager.h"

//////////////////////////////////////////////////////////////////////////
class NFShmPlugin : public NFIPlugin
{
public:
	explicit NFShmPlugin(NFIPluginManager* p):NFIPlugin(p)
	{

	}

	virtual ~NFShmPlugin()
	{
	}

	virtual int GetPluginVersion() override;

	virtual std::string GetPluginName() override;

	virtual void Install() override;

	virtual void Uninstall() override;

	virtual bool IsDynamicLoad() override;

	virtual bool InitShmObjectRegister() override;
};

