// -------------------------------------------------------------------------
//    @FileName         :    NFGameServerPlugin.cpp
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFGameServerPlugin
//
// -------------------------------------------------------------------------

#include "NFGameServerPlugin.h"
#include "NFComm/NFPluginModule/NFIPluginManager.h"
#include "NFGameServerModule.h"
#include "NFGameRoomModule.h"

#include "NFGameSession.h"
#include "NFGameSessionMgr.h"

#include "NFGameRobot.h"
#include "NFGameRobotMgr.h"

#include "NFGameRoom.h"
#include "NFGameDesk.h"
#include "NFGameRoomMgr.h"

#include "NFTransGamePlayerBase.h"
#include "NFTransQueryCoinBalance.h"

#include "NFTransCreateRobot.h"
#include "NFRobotCommon.h"
#include "NFRobotMgr.h"

#include "NFComm/NFPluginModule/NFConfigMgr.h"
#include "NFGameWebHandleModule.h"

#ifdef NF_DYNAMIC_PLUGIN

NF_EXPORT void DllStartPlugin(NFIPluginManager* pm)
{
    CREATE_PLUGIN(pm, NFGameServerPlugin)

};

NF_EXPORT void DllStopPlugin(NFIPluginManager* pm)
{
    DESTROY_PLUGIN(pm, NFGameServerPlugin)
};

#endif


//////////////////////////////////////////////////////////////////////////

int NFGameServerPlugin::GetPluginVersion()
{
	return 0;
}

std::string NFGameServerPlugin::GetPluginName()
{
	return GET_CLASS_NAME(NFGameServerPlugin);
}

void NFGameServerPlugin::Install()
{
	REGISTER_MODULE(m_pPluginManager, NFIGameServerModule, NFCGameServerModule);
    REGISTER_MODULE(m_pPluginManager, NFIGameRoomModule,   NFCGameRoomModule);
    REGISTER_MODULE(m_pPluginManager, NFCGameWebHandleModule,   NFCGameWebHandleModule);
}

void NFGameServerPlugin::Uninstall()
{
	UNREGISTER_MODULE(m_pPluginManager, NFIGameServerModule, NFCGameServerModule);
    UNREGISTER_MODULE(m_pPluginManager, NFIGameRoomModule,   NFCGameRoomModule);
    UNREGISTER_MODULE(m_pPluginManager, NFCGameWebHandleModule,   NFCGameWebHandleModule);
}

bool NFGameServerPlugin::InitShmObjectRegister()
{
	NFServerConfig* pConfig = NFConfigMgr::Instance()->GetAppConfig(NF_ST_GAME_SERVER);
	NF_ASSERT(pConfig);

	uint32_t maxRoomNum = pConfig->GetMaxRoomNum();
	uint32_t maxOnlinePlayerNum = pConfig->mMaxOnlinePlayerNum;
	uint32_t maxDeskCount = pConfig->GetMaxDeskNum();

	///////init player shm//////////////////////////
	REGISTER_SHM_OBJ_WITH_HASH(NFGameSession, EOT_GAME_PLAYER_ID, maxOnlinePlayerNum);
    REGISTER_SINGLETON_SHM_OBJ(NFGameSessionMgr, EOT_GAME_PLAYER_HASH_TABLE_ID, 1);//

	REGISTER_SHM_OBJ_WITH_HASH(NFGameRobot, EOT_GAME_ROBOT_ID, maxOnlinePlayerNum);
    REGISTER_SINGLETON_SHM_OBJ(NFGameRobotMgr, EOT_GAME_ROBOT_ID_HASH_TABLE_ID, 1);//


	////////init game desk shm///////////////////
	REGISTER_SHM_OBJ(NFGameDesk, EOT_GAME_DESK_ID, maxDeskCount);
	///////init game room shm///////////////////
	REGISTER_SHM_OBJ_WITH_HASH(NFGameRoom, EOT_GAME_ROOM_ID, maxRoomNum);
    REGISTER_SINGLETON_SHM_OBJ(NFGameRoomMgr, EOT_GAME_ROOM_ID_HASH_TABLE_ID, 1);

	REGISTER_SHM_OBJ(NFTransGamePlayerBase, EOT_TRANS_GAME_PLAYER_BASE, 0);
	REGISTER_SHM_OBJ(NFTransQueryCoinBalance, EOT_TRANS_QUERY_COIN_BALANCE_BASE, maxOnlinePlayerNum);

    REGISTER_SHM_OBJ(NFTransCreateRobot, EOT_GAME_CREATE_ROBOT_TRANS_ID, maxDeskCount*10);
    REGISTER_SHM_OBJ(NFRobotCommon, EOT_GAME_ROBOT_COMMON_ID, maxRoomNum);
    REGISTER_SINGLETON_SHM_OBJ(NFRobotMgr, EOT_GAME_ROBOT_MGR_ID, 1);
	return true;
}
