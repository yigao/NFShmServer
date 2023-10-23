// -------------------------------------------------------------------------
//    @FileName         :    NFMMOCenterPlayerPlugin.cpp
//    @Author           :    gaoyi
//    @Date             :    23-10-21
//    @Email			:    445267987@qq.com
//    @Module           :    NFMMOCenterPlayerPlugin
//
// -------------------------------------------------------------------------

#include "NFMMOCenterPlayerPlugin.h"
#include "NFComm/NFPluginModule/NFIPluginManager.h"
#include "NFCenterRegisterModule.h"

#include "NFServerAddrMgr.h"

#ifdef NF_DYNAMIC_PLUGIN

NF_EXPORT void DllStartPlugin(NFIPluginManager* pm)
{
    CREATE_PLUGIN(pm, NFMMOCenterPlayerPlugin)

};

NF_EXPORT void DllStopPlugin(NFIPluginManager* pm)
{
    DESTROY_PLUGIN(pm, NFMMOCenterPlayerPlugin)
};

#endif


//////////////////////////////////////////////////////////////////////////

int NFMMOCenterPlayerPlugin::GetPluginVersion()
{
    return 0;
}

std::string NFMMOCenterPlayerPlugin::GetPluginName()
{
    return GET_CLASS_NAME(NFMMOCenterPlayerPlugin);
}

void NFMMOCenterPlayerPlugin::Install()
{
    REGISTER_MODULE(m_pObjPluginManager, NFCenterRegisterModule, NFCenterRegisterModule);
}

void NFMMOCenterPlayerPlugin::Uninstall()
{
    UNREGISTER_MODULE(m_pObjPluginManager, NFCenterRegisterModule, NFCenterRegisterModule);
}

bool NFMMOCenterPlayerPlugin::InitShmObjectRegister()
{
    REGISTER_SINGLETON_SHM_OBJ(NFServerAddrMgr);//
    return true;
}