// -------------------------------------------------------------------------
//    @FileName         :    NFGameServerPlugin.cpp
//    @Author           :    Gao.Yi
//    @Date             :   2022-09-18
//    @Email			:    445267987@qq.com
//    @Module           :    NFGameServerPlugin
//
// -------------------------------------------------------------------------

#include "NFMMOGamePlayerPlugin.h"
#include "NFComm/NFPluginModule/NFIPluginManager.h"
#include "NFComm/NFPluginModule/NFConfigDefine.h"
#include "NFComm/NFPluginModule/NFIConfigModule.h"
#include "NFCSceneModule.h"
#include "Part/NFBattlePartModule.h"

#include "Map/NFMapMgr.h"
#include "Map/NFMap.h"
#include "Scene/NFSceneMgr.h"
#include "Scene/NFScene.h"
#include "NFGameConfig.h"
#include "Creature/NFCreature.h"
#include "Creature/NFBattlePlayer.h"
#include "Creature/NFCreatureMgr.h"

#include "Part/NFBattlePart.h"
#include "Part/NFBattleMovePart.h"
#include "NFLogicCommon/NFAttr.h"

#ifdef NF_DYNAMIC_PLUGIN

NF_EXPORT void DllStartPlugin(NFIPluginManager* pm)
{
    CREATE_PLUGIN(pm, NFMMOGamePlayerPlugin)

};

NF_EXPORT void DllStopPlugin(NFIPluginManager* pm)
{
    DESTROY_PLUGIN(pm, NFGamePlayerPlugin)
};

#endif


//////////////////////////////////////////////////////////////////////////

int NFMMOGamePlayerPlugin::GetPluginVersion()
{
	return 0;
}

std::string NFMMOGamePlayerPlugin::GetPluginName()
{
	return GET_CLASS_NAME(NFMMOGamePlayerPlugin);
}

void NFMMOGamePlayerPlugin::Install()
{
    REGISTER_MODULE(m_pObjPluginManager, NFCSceneModule, NFCSceneModule);
    REGISTER_MODULE(m_pObjPluginManager, NFBattlePartModule, NFBattlePartModule);
}

void NFMMOGamePlayerPlugin::Uninstall()
{
    UNREGISTER_MODULE(m_pObjPluginManager, NFCSceneModule, NFCSceneModule);
    UNREGISTER_MODULE(m_pObjPluginManager, NFBattlePartModule, NFBattlePartModule);
}

bool NFMMOGamePlayerPlugin::InitShmObjectRegister()
{
	NFServerConfig* pConfig = FindModule<NFIConfigModule>()->GetAppConfig(NF_ST_GAME_SERVER);
	NF_ASSERT(pConfig);

	uint32_t maxOnlinePlayerNum = pConfig->MaxOnlinePlayerNum;
    REGISTER_SINGLETON_SHM_OBJ(NFGameConfig);
    REGISTER_SINGLETON_SHM_OBJ(NFMapMgr);
    REGISTER_SHM_OBJ_WITH_HASH(NFMap, GAME_SERVER_MAX_BATTLE_MAP_SIZE);
    REGISTER_SINGLETON_SHM_OBJ(NFSceneMgr);
    REGISTER_SHM_OBJ_WITH_HASH(NFScene, GAME_SERVER_MAX_BATTLE_SCENE_SIZE);

    REGISTER_SHM_OBJ(RoleFightAttr, maxOnlinePlayerNum);
    REGISTER_SHM_OBJ(RoleAttr, maxOnlinePlayerNum);
    REGISTER_SINGLETON_SHM_OBJ(NFCreatureMgr);
    REGISTER_SHM_OBJ(NFCreature, 1);
    REGISTER_SHM_OBJ_WITH_HASH(NFBattlePlayer, maxOnlinePlayerNum);

    REGISTER_SHM_OBJ(NFBattlePart, 1);
    REGISTER_SHM_OBJ(NFBattleMovePart, maxOnlinePlayerNum);
	return true;
}
