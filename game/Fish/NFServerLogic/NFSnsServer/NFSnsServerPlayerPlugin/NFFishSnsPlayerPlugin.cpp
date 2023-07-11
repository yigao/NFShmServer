// -------------------------------------------------------------------------
//    @FileName         :    NFSnsServerPlayerPlugin.cpp
//    @Author           :    Gao.Yi
//    @Date             :   2022-09-18
//    @Email			:    445267987@qq.com
//    @Module           :    NFSnsServerPlayerPlugin
//
// -------------------------------------------------------------------------

#include "NFFishSnsPlayerPlugin.h"
#include "NFComm/NFPluginModule/NFIPluginManager.h"
#include "NFComm/NFPluginModule/NFIConfigModule.h"

#ifdef NF_DYNAMIC_PLUGIN

NF_EXPORT void DllStartPlugin(NFIPluginManager* pm)
{
    CREATE_PLUGIN(pm, NFFishSnsPlayerPlugin)

};

NF_EXPORT void DllStopPlugin(NFIPluginManager* pm)
{
    DESTROY_PLUGIN(pm, NFFishSnsPlayerPlugin)
};

#endif


//////////////////////////////////////////////////////////////////////////

int NFFishSnsPlayerPlugin::GetPluginVersion()
{
	return 0;
}

std::string NFFishSnsPlayerPlugin::GetPluginName()
{
	return GET_CLASS_NAME(NFFishSnsPlayerPlugin);
}

void NFFishSnsPlayerPlugin::Install()
{
	//REGISTER_MODULE(m_pObjPluginManager, NFCOnlineModule, NFCOnlineModule);
}

void NFFishSnsPlayerPlugin::Uninstall()
{
	//UNREGISTER_MODULE(m_pObjPluginManager, NFCOnlineModule, NFCOnlineModule);
}

bool NFFishSnsPlayerPlugin::InitShmObjectRegister()
{
    NFServerConfig* pConfig = FindModule<NFIConfigModule>()->GetAppConfig(NF_ST_SNS_SERVER);
    NF_ASSERT(pConfig);

    uint32_t maxOnlinePlayerNum = pConfig->MaxOnlinePlayerNum;

    return true;
}