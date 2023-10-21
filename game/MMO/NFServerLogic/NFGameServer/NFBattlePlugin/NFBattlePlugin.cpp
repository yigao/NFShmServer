﻿// -------------------------------------------------------------------------
//    @FileName         :    NFGameServerPlugin.cpp
//    @Author           :    Gao.Yi
//    @Date             :   2022-09-18
//    @Email			:    445267987@qq.com
//    @Module           :    NFGameServerPlugin
//
// -------------------------------------------------------------------------

#include "NFBattlePlugin.h"
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
#include "Part/NFMovePart.h"
#include "NFLogicCommon/NFAttr.h"

#ifdef NF_DYNAMIC_PLUGIN

NF_EXPORT void DllStartPlugin(NFIPluginManager* pm)
{
    CREATE_PLUGIN(pm, NFBattlePlugin)

};

NF_EXPORT void DllStopPlugin(NFIPluginManager* pm)
{
    DESTROY_PLUGIN(pm, NFBattlePlugin)
};

#endif


//////////////////////////////////////////////////////////////////////////

int NFBattlePlugin::GetPluginVersion()
{
	return 0;
}

std::string NFBattlePlugin::GetPluginName()
{
	return GET_CLASS_NAME(NFBattlePlugin);
}

void NFBattlePlugin::Install()
{
    REGISTER_MODULE(m_pObjPluginManager, NFCSceneModule, NFCSceneModule);
    REGISTER_MODULE(m_pObjPluginManager, NFBattlePartModule, NFBattlePartModule);
}

void NFBattlePlugin::Uninstall()
{
    UNREGISTER_MODULE(m_pObjPluginManager, NFCSceneModule, NFCSceneModule);
    UNREGISTER_MODULE(m_pObjPluginManager, NFBattlePartModule, NFBattlePartModule);
}

bool NFBattlePlugin::InitShmObjectRegister()
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
    REGISTER_SHM_OBJ(NFMovePart, maxOnlinePlayerNum);
	return true;
}
