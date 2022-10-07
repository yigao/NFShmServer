// -------------------------------------------------------------------------
//    @FileName         :    NFLuaScriptPlugin.h
//    @Author           :    GaoYi
//    @Date             :    2019-08-29 08:51
//    @Module           :   NFLuaThreadScriptPlugin
//
// -------------------------------------------------------------------------

#ifndef NF_LUA_THREAD_SCRIPT_LUGIN_H
#define NF_LUA_THREAD_SCRIPT_LUGIN_H

///
#include "NFComm/NFPluginModule/NFIPlugin.h"
#include "NFComm/NFPluginModule/NFIPluginManager.h"

class NFLuaThreadScriptPlugin : public NFIPlugin
{
public:
	NFLuaThreadScriptPlugin(NFIPluginManager* p)
    {
        m_pPluginManager = p;
    }

    virtual int GetPluginVersion() override;

	virtual std::string GetPluginName() override;

    virtual void Install();

    virtual void Uninstall();
};
#endif