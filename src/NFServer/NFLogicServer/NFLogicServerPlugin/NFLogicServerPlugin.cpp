// -------------------------------------------------------------------------
//    @FileName         :    NFLogicServerPlugin.cpp
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFLogicServerPlugin
//
// -------------------------------------------------------------------------

#include "NFLogicServerPlugin.h"
#include "NFComm/NFPluginModule/NFIPluginManager.h"
#include "NFLogicServerModule.h"
#include "NFComm/NFPluginModule/NFConfigMgr.h"

#ifdef NF_DYNAMIC_PLUGIN

NF_EXPORT void DllStartPlugin(NFIPluginManager* pm)
{
    CREATE_PLUGIN(pm, NFLogicServerPlugin)

};

NF_EXPORT void DllStopPlugin(NFIPluginManager* pm)
{
    DESTROY_PLUGIN(pm, NFLogicServerPlugin)
};

#endif


//////////////////////////////////////////////////////////////////////////

int NFLogicServerPlugin::GetPluginVersion()
{
	return 0;
}

std::string NFLogicServerPlugin::GetPluginName()
{
	return GET_CLASS_NAME(NFLogicServerPlugin);
}

void NFLogicServerPlugin::Install()
{
	REGISTER_MODULE(m_pPluginManager, NFILogicServerModule, NFCLogicServerModule);
}

void NFLogicServerPlugin::Uninstall()
{
	UNREGISTER_MODULE(m_pPluginManager, NFILogicServerModule, NFCLogicServerModule);
}

bool NFLogicServerPlugin::InitShmObjectRegister()
{
    NFServerConfig* pConfig = NFConfigMgr::Instance()->GetAppConfig(NF_ST_LOGIC_SERVER);
    NF_ASSERT(pConfig);

    //uint32_t maxOnlinePlayerNum = pConfig->mMaxOnlinePlayerNum;

	return true;
}