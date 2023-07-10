// -------------------------------------------------------------------------
//    @FileName         :    NFGameServerPlugin.cpp
//    @Author           :    gaoyi
//    @Date             :   2023-07-10
//    @Email			:    445267987@qq.com
//    @Module           :    NFGameServerPlugin
//
// -------------------------------------------------------------------------

#include "NFFishWorldPlayerPlugin.h"
#include "NFComm/NFPluginModule/NFIPluginManager.h"

#include "NFWorldPlayer.h"
#include "NFWorldPlayerMgr.h"
#include "NFWorldPlayerModule.h"
#include "NFLogicCommon/NFLogicShmTypeDefines.h"

#ifdef NF_DYNAMIC_PLUGIN

NF_EXPORT void DllStartPlugin(NFIPluginManager* pm)
{
    CREATE_PLUGIN(pm, NFFishWorldPlayerPlugin)

};

NF_EXPORT void DllStopPlugin(NFIPluginManager* pm)
{
    DESTROY_PLUGIN(pm, NFFishWorldPlayerPlugin)
};

#endif


//////////////////////////////////////////////////////////////////////////

int NFFishWorldPlayerPlugin::GetPluginVersion()
{
	return 0;
}

std::string NFFishWorldPlayerPlugin::GetPluginName()
{
	return GET_CLASS_NAME(NFFishWorldPlayerPlugin);
}

void NFFishWorldPlayerPlugin::Install()
{
	REGISTER_MODULE(m_pObjPluginManager, NFCWorldPlayerModule, NFCWorldPlayerModule);
}

void NFFishWorldPlayerPlugin::Uninstall()
{
	UNREGISTER_MODULE(m_pObjPluginManager, NFCWorldPlayerModule, NFCWorldPlayerModule);
}

bool NFFishWorldPlayerPlugin::InitShmObjectRegister()
{
    NFServerConfig* pConfig = FindModule<NFIConfigModule>()->GetAppConfig(NF_ST_WORLD_SERVER);
    NF_ASSERT(pConfig);

    uint32_t maxOnlinePlayerNum = pConfig->GetMaxOnlinePlayerNum();

    REGISTER_SHM_OBJ_WITH_HASH(NFWorldPlayer, maxOnlinePlayerNum);
    REGISTER_SINGLETON_SHM_OBJ(NFWorldPlayerMgr);//

	return true;
}
