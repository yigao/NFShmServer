// -------------------------------------------------------------------------
//    @FileName         :    NFMMOMatchServerPlayerPlugin.cpp
//    @Author           :    gaoyi
//    @Date             :    23-10-21
//    @Email			:    445267987@qq.com
//    @Module           :    NFMMOMatchServerPlayerPlugin
//
// -------------------------------------------------------------------------

#include "NFMMOMatchPlayerPlugin.h"
#include "NFComm/NFPluginModule/NFIPluginManager.h"
#include "NFMatchPlayerModule.h"

#ifdef NF_DYNAMIC_PLUGIN

NF_EXPORT void DllStartPlugin(NFIPluginManager* pm)
{
    CREATE_PLUGIN(pm, NFMMOMatchPlayerPlugin)

};

NF_EXPORT void DllStopPlugin(NFIPluginManager* pm)
{
    DESTROY_PLUGIN(pm, NFMMOMatchServerPlayerPlugin)
};

#endif


//////////////////////////////////////////////////////////////////////////

int NFMMOMatchPlayerPlugin::GetPluginVersion()
{
    return 0;
}

std::string NFMMOMatchPlayerPlugin::GetPluginName()
{
    return GET_CLASS_NAME(NFMMOMatchPlayerPlugin);
}

void NFMMOMatchPlayerPlugin::Install()
{
    REGISTER_MODULE(m_pObjPluginManager, NFMatchPlayerModule, NFMatchPlayerModule);
}

void NFMMOMatchPlayerPlugin::Uninstall()
{
    UNREGISTER_MODULE(m_pObjPluginManager, NFMatchServerPlayerModule, NFMatchServerPlayerModule);
}

bool NFMMOMatchPlayerPlugin::InitShmObjectRegister()
{
    return true;
}