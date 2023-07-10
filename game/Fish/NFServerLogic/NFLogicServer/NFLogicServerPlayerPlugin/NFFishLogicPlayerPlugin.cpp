// -------------------------------------------------------------------------
//    @FileName         :    NFLogicServerPlayerPlugin.cpp
//    @Author           :    gaoyi
//    @Date             :   2023-07-10
//    @Email			:    445267987@qq.com
//    @Module           :    NFLogicServerPlayerPlugin
//
// -------------------------------------------------------------------------

#include "NFFishLogicPlayerPlugin.h"
#include "NFComm/NFPluginModule/NFIPluginManager.h"
#include "NFComm/NFPluginModule/NFConfigDefine.h"
#include "NFComm/NFPluginModule/NFIConfigModule.h"
#include "NFLogicPlayerModule.h"
#include "NFPlayerMgr.h"
#include "NFPlayer.h"

#ifdef NF_DYNAMIC_PLUGIN

NF_EXPORT void DllStartPlugin(NFIPluginManager* pm)
{
    CREATE_PLUGIN(pm, NFFishLogicPlayerPlugin)

};

NF_EXPORT void DllStopPlugin(NFIPluginManager* pm)
{
    DESTROY_PLUGIN(pm, NFFishLogicPlayerPlugin)
};

#endif


//////////////////////////////////////////////////////////////////////////

int NFFishLogicPlayerPlugin::GetPluginVersion()
{
	return 0;
}

std::string NFFishLogicPlayerPlugin::GetPluginName()
{
	return GET_CLASS_NAME(NFFishLogicPlayerPlugin);
}

void NFFishLogicPlayerPlugin::Install()
{
    REGISTER_MODULE(m_pObjPluginManager, NFCLogicPlayerModule, NFCLogicPlayerModule);
}

void NFFishLogicPlayerPlugin::Uninstall()
{
    UNREGISTER_MODULE(m_pObjPluginManager, NFCLogicPlayerModule, NFCLogicPlayerModule);
}

bool NFFishLogicPlayerPlugin::InitShmObjectRegister()
{
    NFServerConfig* pConfig = FindModule<NFIConfigModule>()->GetAppConfig(NF_ST_LOGIC_SERVER);
    NF_ASSERT(pConfig);

    uint32_t maxOnlinePlayerNum = pConfig->GetMaxOnlinePlayerNum();

    REGISTER_SHM_OBJ_WITH_HASH(NFPlayer, maxOnlinePlayerNum);
    REGISTER_SINGLETON_SHM_OBJ(NFPlayerMgr);//

    return true;
}