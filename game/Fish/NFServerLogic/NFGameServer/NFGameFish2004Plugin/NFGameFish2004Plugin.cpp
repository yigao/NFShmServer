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
	return true;
}