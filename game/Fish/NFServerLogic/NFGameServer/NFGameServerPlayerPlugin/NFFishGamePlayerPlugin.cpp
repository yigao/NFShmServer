// -------------------------------------------------------------------------
//    @FileName         :    NFFishGamePlayerPlugin.cpp
//    @Author           :    gaoyi
//    @Date             :    23-7-28
//    @Email			:    445267987@qq.com
//    @Module           :    NFFishGamePlayerPlugin
//
// -------------------------------------------------------------------------

#include "NFFishGamePlayerPlugin.h"

#include "NFComm/NFPluginModule/NFIPluginManager.h"
#include "NFComm/NFPluginModule/NFConfigDefine.h"
#include "NFComm/NFPluginModule/NFIConfigModule.h"
#include "DescStore/RoomRoomDesc.h"
#include "DescStoreEx/GameRoomDescEx.h"
#include "Desk/NFGameDesk.h"
#include "Room/NFGameRoom.h"
#include "Room/NFGameRoomMgr.h"
#include "Player/NFGamePlayer.h"
#include "Player/NFGamePlayerMgr.h"
#include "NFCGamePlayerModule.h"

#ifdef NF_DYNAMIC_PLUGIN

NF_EXPORT void DllStartPlugin(NFIPluginManager* pm)
{
    CREATE_PLUGIN(pm, NFFishGamePlayerPlugin)

};

NF_EXPORT void DllStopPlugin(NFIPluginManager* pm)
{
    DESTROY_PLUGIN(pm, NFFishGamePlayerPlugin)
};

#endif


//////////////////////////////////////////////////////////////////////////

int NFFishGamePlayerPlugin::GetPluginVersion()
{
    return 0;
}

std::string NFFishGamePlayerPlugin::GetPluginName()
{
    return GET_CLASS_NAME(NFFishGamePlayerPlugin);
}

void NFFishGamePlayerPlugin::Install()
{
    REGISTER_MODULE(m_pObjPluginManager, NFCGamePlayerModule, NFCGamePlayerModule);
}

void NFFishGamePlayerPlugin::Uninstall()
{
    UNREGISTER_MODULE(m_pObjPluginManager, NFCGamePlayerModule, NFCGamePlayerModule);
}

bool NFFishGamePlayerPlugin::InitShmObjectRegister()
{
    NFServerConfig* pConfig = FindModule<NFIConfigModule>()->GetAppConfig(NF_ST_GAME_SERVER);
    NF_ASSERT(pConfig);

    uint32_t maxOnlinePlayerNum = pConfig->GetMaxOnlinePlayerNum();
    uint32_t maxDescCount = 100;
    uint32_t maxRoomNum = 20;
    ////////init player shm///////////////////
    REGISTER_SHM_OBJ(NFGamePlayer, maxOnlinePlayerNum);
    REGISTER_SINGLETON_SHM_OBJ(NFGamePlayerMgr);

    ///////init game room shm///////////////////
    REGISTER_SHM_OBJ_WITH_HASH(NFGameRoom, maxRoomNum);
    REGISTER_SINGLETON_SHM_OBJ(NFGameRoomMgr);

    ////////init game desk shm///////////////////
    REGISTER_SHM_OBJ(NFGameDesk, maxDescCount);

    ////////init excel load shm///////////////////
    REGISTER_DESCSTORE(RoomRoomDesc);
    REGISTER_DESCSTORE(GameRoomDescEx);

    return true;
}
