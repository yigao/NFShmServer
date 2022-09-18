// -------------------------------------------------------------------------
//    @FileName         :    NFMasterServerPlugin.cpp
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFMasterServerPlugin
//
// -------------------------------------------------------------------------

#include "NFServerCommonPlugin.h"
#include "NFComm/NFPluginModule/NFIPluginManager.h"
#include "NFServerMessageModule.h"

#ifdef NF_DYNAMIC_PLUGIN

NF_EXPORT void DllStartPlugin(NFIPluginManager* pm)
{
    CREATE_PLUGIN(pm, NFServerCommonPlugin)

};

NF_EXPORT void DllStopPlugin(NFIPluginManager* pm)
{
    DESTROY_PLUGIN(pm, NFServerCommonPlugin)
};

#endif


//////////////////////////////////////////////////////////////////////////

int NFServerCommonPlugin::GetPluginVersion()
{
    return 0;
}

std::string NFServerCommonPlugin::GetPluginName()
{
    return GET_CLASS_NAME(NFServerCommonPlugin);
}

void NFServerCommonPlugin::Install()
{
    REGISTER_MODULE(m_pObjPluginManager, NFIServerMessageModule, NFServerMessageModule)
}

void NFServerCommonPlugin::Uninstall()
{
    UNREGISTER_MODULE(m_pObjPluginManager, NFIServerMessageModule, NFServerMessageModule)
}
