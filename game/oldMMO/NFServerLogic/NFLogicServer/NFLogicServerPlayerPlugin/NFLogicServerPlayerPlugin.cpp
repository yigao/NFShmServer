// -------------------------------------------------------------------------
//    @FileName         :    NFLogicServerPlayerPlugin.cpp
//    @Author           :    Gao.Yi
//    @Date             :   2022-09-18
//    @Email			:    445267987@qq.com
//    @Module           :    NFLogicServerPlayerPlugin
//
// -------------------------------------------------------------------------

#include "NFLogicServerPlayerPlugin.h"
#include "NFComm/NFPluginModule/NFIPluginManager.h"
#include "NFComm/NFPluginModule/NFIConfigModule.h"
#include "Login/NFLoginModule.h"
#include "Part/NFPartModule.h"
#include "GM/NFLogicGMModule.h"
#include "Player/NFPlayer.h"
#include "Player/NFPlayerMgr.h"
#include "Trans/NFTransGetRoleList.h"
#include "Trans/NFTransCreateRole.h"
#include "Trans/NFTransGetRole.h"
#include "Part/NFPart.h"
#include "Part/NFEquipPart.h"
#include "Part/NFFunctionUnlockPart.h"
#include "Part/NFGrowPart.h"
#include "Part/NFMiniPart.h"
#include "Part/NFPackagePart.h"
#include "Part/NFChatPart.h"
#include "Trans/NFTransTransScene.h"
#include "Part/NFMissionPart.h"
#include "Part/NFTitlePart.h"

#ifdef NF_DYNAMIC_PLUGIN

NF_EXPORT void DllStartPlugin(NFIPluginManager* pm)
{
    CREATE_PLUGIN(pm, NFLogicServerPlayerPlugin)

};

NF_EXPORT void DllStopPlugin(NFIPluginManager* pm)
{
    DESTROY_PLUGIN(pm, NFLogicServerPlayerPlugin)
};

#endif


//////////////////////////////////////////////////////////////////////////

int NFLogicServerPlayerPlugin::GetPluginVersion()
{
	return 0;
}

std::string NFLogicServerPlayerPlugin::GetPluginName()
{
	return GET_CLASS_NAME(NFLogicServerPlayerPlugin);
}

void NFLogicServerPlayerPlugin::Install()
{
    REGISTER_MODULE(m_pObjPluginManager, NFLoginModule, NFLoginModule);
    REGISTER_MODULE(m_pObjPluginManager, NFPartModule, NFPartModule);
    REGISTER_MODULE(m_pObjPluginManager, NFLogicGMModule, NFLogicGMModule);
}

void NFLogicServerPlayerPlugin::Uninstall()
{
    UNREGISTER_MODULE(m_pObjPluginManager, NFLoginModule, NFLoginModule);
    UNREGISTER_MODULE(m_pObjPluginManager, NFPartModule, NFPartModule);
    UNREGISTER_MODULE(m_pObjPluginManager, NFLogicGMModule, NFLogicGMModule);
}

bool NFLogicServerPlayerPlugin::InitShmObjectRegister()
{
    NFServerConfig* pConfig = FindModule<NFIConfigModule>()->GetAppConfig(NF_ST_LOGIC_SERVER);
    NF_ASSERT(pConfig);

    uint32_t maxOnlinePlayerNum = pConfig->MaxOnlinePlayerNum * 120 / 100;
    /**
     * @brief 通过roleId建立Hash， 同时通过uid创建索引
     */
    REGISTER_SHM_OBJ_WITH_HASH(NFPlayer, maxOnlinePlayerNum);
    REGISTER_SINGLETON_SHM_OBJ(NFPlayerMgr);
    REGISTER_SHM_OBJ(NFTransPlayerBase, 0);

    REGISTER_SINGLETON_SHM_OBJ(NFItemMgr);

    //////////////////////////////////part///////////////////////////////////////////////
    REGISTER_SHM_OBJ(NFPart, 0);
    REGISTER_SHM_OBJ(NFEquipPart, maxOnlinePlayerNum);
    REGISTER_SHM_OBJ(NFFunctionUnlockPart, maxOnlinePlayerNum);
    REGISTER_SHM_OBJ(NFGrowPart, maxOnlinePlayerNum);
    REGISTER_SHM_OBJ(NFMiniPart, maxOnlinePlayerNum);
    REGISTER_SHM_OBJ(NFChatPart, maxOnlinePlayerNum);
    REGISTER_SHM_OBJ(NFTitlePart, maxOnlinePlayerNum);
    REGISTER_SHM_OBJ(NFMissionPart, maxOnlinePlayerNum);

    REGISTER_SHM_OBJ(NFPackagePart, maxOnlinePlayerNum);
    REGISTER_SHM_OBJ(RoleFightAttr,maxOnlinePlayerNum);
    REGISTER_SHM_OBJ(RoleAttr, maxOnlinePlayerNum);

    ////////////////////////////////trans///////////////////////////////////////////////////
    REGISTER_SHM_OBJ(NFTransGetRoleList, maxOnlinePlayerNum/5);
    REGISTER_SHM_OBJ(NFTransCreateRole, maxOnlinePlayerNum/5);
    REGISTER_SHM_OBJ(NFTransGetRole, maxOnlinePlayerNum/5);
    REGISTER_SHM_OBJ(NFTransSaveRoleDetail, maxOnlinePlayerNum/5);
    REGISTER_SHM_OBJ(NFTransTransScene, maxOnlinePlayerNum / 10);
/*
    REGISTER_SINGLETON_SHM_OBJ(NFUserDetailMgr, EOT_USER_DETAIL_HASH_TABLE_ID, 1);
    REGISTER_SHM_OBJ(NFTransGetUserDetail, EOT_TRANS_GET_USER_DETAIL, maxOnlinePlayerNum);
    REGISTER_SHM_OBJ(NFTransCreateUserDetail, EOT_TRANS_CREATE_USER_DETAIL, maxOnlinePlayerNum);
	REGISTER_SHM_OBJ(NFTransPlayerBase, EOT_TRANS_LOGIC_USER_BASE, 1);
	REGISTER_SHM_OBJ(NFTransSaveMoney, EOT_TRANS_SAVE_USER_MONEY, maxOnlinePlayerNum);
	REGISTER_SHM_OBJ(NFTransSaveDB, EOT_TRANS_SAVE_USER_DETAIL, maxOnlinePlayerNum);

    REGISTER_SHM_OBJ(NFTransSendEventLog, EOT_TRANS_SEND_EVENT_LOG_ID, maxOnlinePlayerNum);
    REGISTER_SHM_OBJ(NFTransGetEventLog, EOT_TRANS_GET_EVENT_LOG_ID, maxOnlinePlayerNum);
    REGISTER_SHM_OBJ(NFTransHandleEventLog, EOT_TRANS_HANDLE_EVENT_LOG_ID, maxOnlinePlayerNum);

    REGISTER_SHM_OBJ(NFPlayerBindPhoneTrans, EOT_TRANS_PLAYER_BIND_PHONE_TRANS_ID, maxOnlinePlayerNum);*/
	return true;
}