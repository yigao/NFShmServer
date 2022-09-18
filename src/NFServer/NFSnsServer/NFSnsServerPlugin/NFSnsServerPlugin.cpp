// -------------------------------------------------------------------------
//    @FileName         :    NFGameServerPlugin.cpp
//    @Author           :    Gao.Yi
//    @Date             :   2022-09-18
//    @Email			:    445267987@qq.com
//    @Module           :    NFGameServerPlugin
//
// -------------------------------------------------------------------------

#include "NFSnsServerPlugin.h"
#include "NFComm/NFPluginModule/NFIPluginManager.h"
#include "NFSnsServerModule.h"


#ifdef NF_DYNAMIC_PLUGIN

NF_EXPORT void DllStartPlugin(NFIPluginManager* pm)
{
    CREATE_PLUGIN(pm, NFSnsServerPlugin)

};

NF_EXPORT void DllStopPlugin(NFIPluginManager* pm)
{
    DESTROY_PLUGIN(pm, NFSnsServerPlugin)
};

#endif


//////////////////////////////////////////////////////////////////////////

int NFSnsServerPlugin::GetPluginVersion()
{
	return 0;
}

std::string NFSnsServerPlugin::GetPluginName()
{
	return GET_CLASS_NAME(NFSnsServerPlugin);
}

void NFSnsServerPlugin::Install()
{
	REGISTER_MODULE(m_pPluginManager, NFISnsServerModule, NFCSnsServerModule);
}

void NFSnsServerPlugin::Uninstall()
{
	UNREGISTER_MODULE(m_pPluginManager, NFISnsServerModule, NFCSnsServerModule);
}

bool NFSnsServerPlugin::InitShmObjectRegister()
{
    //NFServerConfig* pConfig = FindModule<NFIConfigModule>()->GetAppConfig(NF_ST_SNS_SERVER);
    //NF_ASSERT(pConfig);

    //uint32_t maxOnlinePlayerNum = pConfig->mMaxOnlinePlayerNum;

    return true;
}