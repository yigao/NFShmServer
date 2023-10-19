﻿// -------------------------------------------------------------------------
//    @FileName         :    NFGameServerPlugin.cpp
//    @Author           :    gaoyi
//    @Date             :   2023-07-10
//    @Email			:    445267987@qq.com
//    @Module           :    NFGameServerPlugin
//
// -------------------------------------------------------------------------

#include "NFMMOWorldServerPlayerPlugin.h"
#include "NFComm/NFPluginModule/NFIPluginManager.h"

#include "NFWorldPlayerModule.h"

#include "NFWorldSession.h"
#include "NFWorldSessionMgr.h"
#include "NFWorldAccount.h"
#include "NFWorldAccountMgr.h"
#include "NFWorldRoleMgr.h"
#include "NFWorldRole.h"

#ifdef NF_DYNAMIC_PLUGIN

NF_EXPORT void DllStartPlugin(NFIPluginManager* pm)
{
    CREATE_PLUGIN(pm, NFMMOWorldServerPlayerPlugin)

};

NF_EXPORT void DllStopPlugin(NFIPluginManager* pm)
{
    DESTROY_PLUGIN(pm, NFMMOWorldServerPlayerPlugin)
};

#endif


//////////////////////////////////////////////////////////////////////////

int NFMMOWorldServerPlayerPlugin::GetPluginVersion()
{
	return 0;
}

std::string NFMMOWorldServerPlayerPlugin::GetPluginName()
{
	return GET_CLASS_NAME(NFMMOWorldServerPlayerPlugin);
}

void NFMMOWorldServerPlayerPlugin::Install()
{
	REGISTER_MODULE(m_pObjPluginManager, NFCWorldPlayerModule, NFCWorldPlayerModule);
}

void NFMMOWorldServerPlayerPlugin::Uninstall()
{
	UNREGISTER_MODULE(m_pObjPluginManager, NFCWorldPlayerModule, NFCWorldPlayerModule);
}

bool NFMMOWorldServerPlayerPlugin::InitShmObjectRegister()
{
    NFServerConfig* pConfig = FindModule<NFIConfigModule>()->GetAppConfig(NF_ST_WORLD_SERVER);
    NF_ASSERT(pConfig);

    uint32_t maxOnlinePlayerNum = pConfig->GetMaxOnlinePlayerNum();

    REGISTER_SHM_OBJ_WITH_HASH(NFWorldSession, maxOnlinePlayerNum * 2);//
    REGISTER_SINGLETON_SHM_OBJ(NFWorldSessionMgr);//

    REGISTER_SHM_OBJ_WITH_HASH(NFWorldAccount, maxOnlinePlayerNum);//
    REGISTER_SINGLETON_SHM_OBJ(NFWorldAccountMgr);//

    REGISTER_SHM_OBJ_WITH_HASH(NFWorldRole, maxOnlinePlayerNum);//
    REGISTER_SINGLETON_SHM_OBJ(NFWorldRoleMgr);//
	return true;
}
