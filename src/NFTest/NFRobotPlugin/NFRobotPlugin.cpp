// -------------------------------------------------------------------------
//    @FileName         :    NFRobotPlugin.cpp
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFRobotPlugin.cpp
//
// -------------------------------------------------------------------------
#include "NFRobotPlugin.h"
#include "NFRobotModule.h"

#ifdef NF_DYNAMIC_PLUGIN

NF_EXPORT void DllStartPlugin(NFIPluginManager* pm)
{
    CREATE_PLUGIN(pm, NFRobotPlugin)
};

NF_EXPORT void DllStopPlugin(NFIPluginManager* pm)
{
    DESTROY_PLUGIN(pm, NFRobotPlugin)
};

#endif

//////////////////////////////////////////////////////////////////////////

int NFRobotPlugin::GetPluginVersion()
{
    return 0;
}

std::string NFRobotPlugin::GetPluginName()
{
    return GET_CLASS_NAME(NFRobotPlugin);
}

void NFRobotPlugin::Install()
{
    REGISTER_MODULE(m_pPluginManager, NFCRobotModule, NFCRobotModule);
}

void NFRobotPlugin::Uninstall()
{
    UNREGISTER_MODULE(m_pPluginManager, NFCRobotModule, NFCRobotModule);
}
