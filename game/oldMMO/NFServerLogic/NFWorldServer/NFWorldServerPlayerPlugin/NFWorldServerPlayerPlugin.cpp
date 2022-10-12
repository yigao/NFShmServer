// -------------------------------------------------------------------------
//    @FileName         :    NFWorldServerPlayerPlugin.cpp
//    @Author           :    Gao.Yi
//    @Date             :   2022-09-18
//    @Email			:    445267987@qq.com
//    @Module           :    NFWorldServerPlayerPlugin
//
// -------------------------------------------------------------------------

#include "NFWorldServerPlayerPlugin.h"
#include "NFComm/NFPluginModule/NFIPluginManager.h"
#include "NFComm/NFPluginModule/NFIConfigModule.h"
#include "NFWorldConfig.h"
#include "NFWorldPlayerModule.h"
#include "NFWorldPlayer.h"
#include "NFWorldPlayerMgr.h"

#ifdef NF_DYNAMIC_PLUGIN

NF_EXPORT void DllStartPlugin(NFIPluginManager* pm)
{
    CREATE_PLUGIN(pm, NFWorldServerPlayerPlugin)

};

NF_EXPORT void DllStopPlugin(NFIPluginManager* pm)
{
    DESTROY_PLUGIN(pm, NFWorldServerPlayerPlugin)
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
	REGISTER_MODULE(m_pObjPluginManager, NFCWorldPlayerModule, NFCWorldPlayerModule);
}

void NFWorldServerPlayerPlugin::Uninstall()
{
	UNREGISTER_MODULE(m_pObjPluginManager, NFCWorldPlayerModule, NFCWorldPlayerModule);
}

bool NFWorldServerPlayerPlugin::InitShmObjectRegister()
{
    NFServerConfig* pConfig = FindModule<NFIConfigModule>()->GetAppConfig(NF_ST_WORLD_SERVER);
    NF_ASSERT(pConfig);

    uint32_t maxOnlinePlayerNum = pConfig->MaxOnlinePlayerNum;
    if (maxOnlinePlayerNum >= WORLD_SERVER_MAX_ONLINE_COUNT)
    {
        maxOnlinePlayerNum = WORLD_SERVER_MAX_ONLINE_COUNT;
    }

	REGISTER_SHM_OBJ_WITH_HASH(NFWorldPlayer, EOT_WORLD_PLAYER_ID, maxOnlinePlayerNum);
    REGISTER_SINGLETON_SHM_OBJ(NFWorldPlayerMgr, EOT_WORLD_PLAYER_MGR_ID);//
    REGISTER_SINGLETON_SHM_OBJ(NFWorldConfig, EOT_WOLRD_CONFIG_ID);//

	return true;
}
