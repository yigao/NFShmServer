// -------------------------------------------------------------------------
//    @FileName         :    NFCommLogicPlugin.cpp
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFCommLogicPlugin
//
// -------------------------------------------------------------------------

#include "NFFishCommonPlugin.h"
#include "NFCommLogicModule.h"
#include "NFComm/NFPluginModule/NFIPluginManager.h"

#include "DescStore/NFDescStoreHead.h"
#include "DescStoreEx/GameRoomDescEx.h"

#ifdef NF_DYNAMIC_PLUGIN

NF_EXPORT void DllStartPlugin(NFIPluginManager* pm)
{
    CREATE_PLUGIN(pm, NFFishCommonPlugin)

};

NF_EXPORT void DllStopPlugin(NFIPluginManager* pm)
{
    DESTROY_PLUGIN(pm, NFFishCommonPlugin)
};

#endif


//////////////////////////////////////////////////////////////////////////

int NFFishCommonPlugin::GetPluginVersion()
{
	return 0;
}

std::string NFFishCommonPlugin::GetPluginName()
{
	return GET_CLASS_NAME(NFFishCommonPlugin);
}

void NFFishCommonPlugin::Install()
{
	REGISTER_MODULE(m_pObjPluginManager, NFCommLogicModule, NFCommLogicModule)
}

void NFFishCommonPlugin::Uninstall()
{
	UNREGISTER_MODULE(m_pObjPluginManager, NFCommLogicModule, NFCommLogicModule)
}

bool NFFishCommonPlugin::InitShmObjectRegister()
{
    ////////init excel load shm///////////////////
    REGISTER_DESCSTORE(RoomRoomDesc);


    ///////////////////////////////////////////////
    REGISTER_DESCSTORE(GameRoomDescEx);
	return true;
}
