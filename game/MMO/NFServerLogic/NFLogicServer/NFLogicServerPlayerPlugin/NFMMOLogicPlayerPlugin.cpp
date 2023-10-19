// -------------------------------------------------------------------------
//    @FileName         :    NFLogicServerPlayerPlugin.cpp
//    @Author           :    gaoyi
//    @Date             :   2023-07-10
//    @Email			:    445267987@qq.com
//    @Module           :    NFLogicServerPlayerPlugin
//
// -------------------------------------------------------------------------

#include "NFMMOLogicPlayerPlugin.h"
#include "NFComm/NFPluginModule/NFIPluginManager.h"
#include "NFComm/NFPluginModule/NFConfigDefine.h"
#include "NFComm/NFPluginModule/NFIConfigModule.h"
#include "NFLogicPlayerModule.h"
#include "Player/NFPlayerMgr.h"
#include "Player/NFPlayer.h"
#include "Part/NFPartModule.h"

#ifdef NF_DYNAMIC_PLUGIN

NF_EXPORT void DllStartPlugin(NFIPluginManager* pm)
{
    CREATE_PLUGIN(pm, NFMMOLogicPlayerPlugin)

};

NF_EXPORT void DllStopPlugin(NFIPluginManager* pm)
{
    DESTROY_PLUGIN(pm, NFMMOLogicPlayerPlugin)
};

#endif


//////////////////////////////////////////////////////////////////////////

int NFMMOLogicPlayerPlugin::GetPluginVersion()
{
	return 0;
}

std::string NFMMOLogicPlayerPlugin::GetPluginName()
{
	return GET_CLASS_NAME(NFMMOLogicPlayerPlugin);
}

void NFMMOLogicPlayerPlugin::Install()
{
    REGISTER_MODULE(m_pObjPluginManager, NFCLogicPlayerModule, NFCLogicPlayerModule);
    REGISTER_MODULE(m_pObjPluginManager, NFPartModule, NFPartModule);
}

void NFMMOLogicPlayerPlugin::Uninstall()
{
    UNREGISTER_MODULE(m_pObjPluginManager, NFCLogicPlayerModule, NFCLogicPlayerModule);
    UNREGISTER_MODULE(m_pObjPluginManager, NFPartModule, NFPartModule);
}

bool NFMMOLogicPlayerPlugin::InitShmObjectRegister()
{
    NFServerConfig* pConfig = FindModule<NFIConfigModule>()->GetAppConfig(NF_ST_LOGIC_SERVER);
    NF_ASSERT(pConfig);

    uint32_t maxOnlinePlayerNum = pConfig->GetMaxOnlinePlayerNum();

    REGISTER_SHM_OBJ_WITH_HASH(NFPlayer, maxOnlinePlayerNum);
    REGISTER_SINGLETON_SHM_OBJ(NFPlayerMgr);//

    REGISTER_SHM_OBJ(NFTransPlayerBase, 1);
    REGISTER_SHM_OBJ(NFTransSaveDB, maxOnlinePlayerNum);
    return true;
}