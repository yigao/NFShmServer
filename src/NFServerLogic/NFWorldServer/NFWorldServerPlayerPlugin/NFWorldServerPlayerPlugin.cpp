// -------------------------------------------------------------------------
//    @FileName         :    NFGameServerPlugin.cpp
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFGameServerPlugin
//
// -------------------------------------------------------------------------

#include "NFWorldServerPlayerPlugin.h"
#include "NFComm/NFPluginModule/NFIPluginManager.h"
#include "NFWorldPlayerModule.h"

#include "NFWorldPlayer.h"
#include "NFWorldPlayerMgr.h"
#include "NFComm/NFPluginModule/NFConfigMgr.h"

#ifdef NF_DYNAMIC_PLUGIN

NF_EXPORT void DllStartPlugin(NFIPluginManager* pm)
{
    CREATE_PLUGIN(pm, NFWorldServerPlayerPlugin)

};

NF_EXPORT void DllStopPlugin(NFIPluginManager* pm)
{
    DESTROY_PLUGIN(pm, NFWorldServerPlugin)
};

#endif


//////////////////////////////////////////////////////////////////////////

int NFWorldServerPlayerPlugin::GetPluginVersion()
{
	return 0;
}

std::string NFWorldServerPlayerPlugin::GetPluginName()
{
	return GET_CLASS_NAME(NFWorldServerPlayerPlugin);
}

void NFWorldServerPlayerPlugin::Install()
{
	REGISTER_MODULE(m_pPluginManager, NFIWorldPlayerModule, NFCWorldPlayerModule);
}

void NFWorldServerPlayerPlugin::Uninstall()
{
	UNREGISTER_MODULE(m_pPluginManager, NFIWorldPlayerModule, NFCWorldPlayerModule);
}

bool NFWorldServerPlayerPlugin::InitShmObjectRegister()
{
    NFServerConfig* pConfig = NFConfigMgr::Instance()->GetAppConfig(NF_ST_WORLD_SERVER);
    NF_ASSERT(pConfig);

    uint32_t maxOnlinePlayerNum = pConfig->mMaxOnlinePlayerNum;

	REGISTER_SHM_OBJ_WITH_HASH(NFWorldPlayer, EOT_WORLD_PLAYER_ID, maxOnlinePlayerNum);
	REGISTER_SHM_OBJ(NFWorldPlayerMgr, EOT_WORLD_PLAYER_MGR_ID, 1);//

	return true;
}
