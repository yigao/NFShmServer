// -------------------------------------------------------------------------
//    @FileName         :    NFTutorialPlugin.h
//    @Author           :    gaoyi
//    @Date             :    24-1-13
//    @Email			:    445267987@qq.com
//    @Module           :    NFTutorialPlugin
//
// -------------------------------------------------------------------------

#pragma once

#include "NFComm/NFPluginModule/NFIPlugin.h"
#include "NFComm/NFPluginModule/NFIPluginManager.h"

//////////////////////////////////////////////////////////////////////////
class NFTutorialPlugin : public NFIPlugin
{
public:
    explicit NFTutorialPlugin(NFIPluginManager* p):NFIPlugin(p)
    {

    }

    virtual int GetPluginVersion();

    virtual std::string GetPluginName();

    virtual void Install();

    virtual void Uninstall();

    virtual bool InitShmObjectRegister() override;
};