// -------------------------------------------------------------------------
//    @FileName         :    NFShmPlugin.cpp
//    @Author           :    LvSheng.Huang
//    @Date             :   2022-09-18
//    @Module           :    NFShmPlugin
//
// -------------------------------------------------------------------------

#include "NFLuaScriptPlugin.h"
#include "NFComm/NFPluginModule/NFIConfigModule.h"
#include "NFCLuaScriptModule.h"

//
//
#ifdef NF_DYNAMIC_PLUGIN

NF_EXPORT void DllStartPlugin(NFIPluginManager* pm)
{
	CREATE_PLUGIN(pm, NFLuaScriptPlugin)
};

NF_EXPORT void DllStopPlugin(NFIPluginManager* pm)
{
	DESTROY_PLUGIN(pm, NFLuaScriptPlugin)
};

#endif

//////////////////////////////////////////////////////////////////////////

int NFLuaScriptPlugin::GetPluginVersion()
{
	return 0;
}

std::string NFLuaScriptPlugin::GetPluginName()
{
	return GET_CLASS_NAME(NFLuaScriptPlugin);
}

bool NFLuaScriptPlugin::IsDynamicLoad()
{
	return false;
}

void NFLuaScriptPlugin::Install()
{
    REGISTER_MODULE(m_pObjPluginManager, NFILuaScriptModule, NFCLuaScriptModule);
}

void NFLuaScriptPlugin::Uninstall()
{
    UNREGISTER_MODULE(m_pObjPluginManager, NFILuaScriptModule, NFCLuaScriptModule);
}


