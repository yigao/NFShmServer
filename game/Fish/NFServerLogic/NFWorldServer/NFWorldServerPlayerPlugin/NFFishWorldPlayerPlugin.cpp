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

#include "Room/NFWorldRoomMgr.h"
#include "Room/NFWorldRoom.h"
#include "DescStore/NFDescStoreHead.h"
#include "NFWorldRoomModule.h"

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
	REGISTER_MODULE(m_pObjPluginManager, NFWorldRoomModule, NFWorldRoomModule);
}

void NFFishWorldPlayerPlugin::Uninstall()
{
	UNREGISTER_MODULE(m_pObjPluginManager, NFCWorldPlayerModule, NFCWorldPlayerModule);
	UNREGISTER_MODULE(m_pObjPluginManager, NFWorldRoomModule, NFWorldRoomModule);
}

bool NFFishWorldPlayerPlugin::InitShmObjectRegister()
{
	NFServerConfig* pConfig = FindModule<NFIConfigModule>()->GetAppConfig(NF_ST_WORLD_SERVER);
	NF_ASSERT(pConfig);

	uint32_t maxOnlinePlayerNum = pConfig->GetMaxOnlinePlayerNum();

	REGISTER_SHM_OBJ_WITH_HASH(NFWorldPlayer, maxOnlinePlayerNum);
	REGISTER_SINGLETON_SHM_OBJ(NFWorldPlayerMgr); //

	///////init game room shm///////////////////
	REGISTER_SHM_OBJ_WITH_HASH(NFWorldRoom, MAX_GAME_TYPE_NUM*MAX_GAME_ROOM_NUM);
	REGISTER_SINGLETON_SHM_OBJ(NFWorldRoomMgr);

	return true;
}
