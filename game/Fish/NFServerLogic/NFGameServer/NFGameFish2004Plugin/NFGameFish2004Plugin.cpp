// -------------------------------------------------------------------------
//    @FileName         :    NFGameLogicPlugin.cpp
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFGameLogicPlugin
//
// -------------------------------------------------------------------------

#include "NFGameFish2004Plugin.h"
#include "NFComm/NFPluginModule/NFIPluginManager.h"
#include "NFComm/NFPluginModule/NFConfigDefine.h"
#include "NFGameFish2004Module.h"
#include "NFLogicCommon/NFIGameConfig.h"
#include "NFLogicCommon/NFFishDefine.h"
#include "NFFishTraceConfig.h"
#include "NFFishGroupConfig.h"
#include "NFFishConfigConfig.h"
#include "NFFishWayBillConfig.h"
#include "NFFishSettingConfig.h"
#include "NFFishPromptConfig.h"
#include "NFGameFish2004Desk.h"

#define MAX_FISH_ROOM_DESK_COUNT 255
#define MAX_GAME_FISH_ROBOT_COUNT 1000

#ifdef NF_DYNAMIC_PLUGIN

NF_EXPORT void DllStartPlugin(NFIPluginManager* pm)
{
	CREATE_PLUGIN(pm, NFGameFish2004Plugin)

};

NF_EXPORT void DllStopPlugin(NFIPluginManager* pm)
{
	DESTROY_PLUGIN(pm, NFGameFish2004Plugin)
};

#endif


//////////////////////////////////////////////////////////////////////////

int NFGameFish2004Plugin::GetPluginVersion()
{
	return 0;
}

std::string NFGameFish2004Plugin::GetPluginName()
{
	return GET_CLASS_NAME(NFGameFish2004Plugin);
}

void NFGameFish2004Plugin::Install()
{
	REGISTER_MODULE(m_pObjPluginManager, NFGameFish2004Module,    NFGameFish2004Module);
}

void NFGameFish2004Plugin::Uninstall()
{
	UNREGISTER_MODULE(m_pObjPluginManager, NFGameFish2004Module,    NFGameFish2004Module);
}

bool NFGameFish2004Plugin::InitShmObjectRegister()
{
    auto pGameConfig = FindModule<NFIGameConfig>()->GetConfig();
    NF_ASSERT(pGameConfig);

    uint32_t roomNum = FindModule<NFIGameConfig>()->GetRoomNum(GAME_ID_FISH_HAIWANG_2004);
    uint32_t maxDeskNum =  FindModule<NFIGameConfig>()->GetRoomMaxDeskNum();
    REGISTER_SHM_OBJ(NFGameFish2004Desk, roomNum*maxDeskNum*1.2);
    REGISTER_SHM_OBJ_WITH_HASH(NFFishTraceConfig, roomNum);
    REGISTER_SHM_OBJ_WITH_HASH(NFFishGroupConfig, roomNum);
    REGISTER_SHM_OBJ_WITH_HASH(NFFishConfigConfig, roomNum);
    REGISTER_SHM_OBJ_WITH_HASH(NFFishWayBillConfig, roomNum);
    REGISTER_SHM_OBJ_WITH_HASH(NFFishSettingConfig, roomNum);
    REGISTER_SHM_OBJ_WITH_HASH(NFFishPromptConfig, roomNum);

	return true;
}