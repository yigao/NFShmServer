// -------------------------------------------------------------------------
//    @FileName         :    NFLuaScriptPlugin.h
//    @Author           :    GaoYi
//    @Date             :    2019-08-29 08:51
//    @Module           :   NFLuaThreadScriptPlugin
//
// -------------------------------------------------------------------------

#include "NFLuaThreadScriptPlugin.h"
#include "NFCLuaThreadModule.h"

#ifdef NF_DYNAMIC_PLUGIN

NF_EXPORT void DllStartPlugin(NFIPluginManager* pm)
{
    CREATE_PLUGIN(pm, NFLuaThreadScriptPlugin)

};

NF_EXPORT void DllStopPlugin(NFIPluginManager* pm)
{
    DESTROY_PLUGIN(pm, NFLuaThreadScriptPlugin)
};

#endif
//////////////////////////////////////////////////////////////////////////

int NFLuaThreadScriptPlugin::GetPluginVersion()
{
    return 0;
}

std::string NFLuaThreadScriptPlugin::GetPluginName()
{
    return GET_CLASS_NAME(NFLuaThreadScriptPlugin);
}

void NFLuaThreadScriptPlugin::Install()
{;
	REGISTER_MODULE(m_pPluginManager, NFILuaScriptModule, NFCLuaThreadModule);
}

void NFLuaThreadScriptPlugin::Uninstall()
{
	UNREGISTER_MODULE(m_pPluginManager, NFILuaScriptModule, NFCLuaThreadModule);
}