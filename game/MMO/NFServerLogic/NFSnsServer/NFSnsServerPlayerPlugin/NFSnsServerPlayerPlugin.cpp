// -------------------------------------------------------------------------
//    @FileName         :    NFSnsServerPlayerPlugin.cpp
//    @Author           :    Gao.Yi
//    @Date             :   2022-09-18
//    @Email			:    445267987@qq.com
//    @Module           :    NFSnsServerPlayerPlugin
//
// -------------------------------------------------------------------------

#include "NFSnsServerPlayerPlugin.h"
#include "NFComm/NFPluginModule/NFIPluginManager.h"
#include "NFLogicCommon/NFServerFrameTypeDefines.h"
#include "NFOnlineModule.h"
#include "NFComm/NFPluginModule/NFIConfigModule.h"
#include "Cache/NFRoleSimple.h"
#include "Cache/NFCacheMgr.h"
#include "Trans/NFTransCacheBase.h"
#include "Trans/NFTransGetRoleSimple.h"
#include "LoadCache/NFLoadCacheData.h"
#include "NFLogicCommon/NFLogicCommonDefine.h"
#include "LoadCache/NFLoadCacheMgr.h"
#include "Trans/NFTransRoleLogin.h"
#include "Trans/NFTransGetRoleDetail.h"

#ifdef NF_DYNAMIC_PLUGIN

NF_EXPORT void DllStartPlugin(NFIPluginManager* pm)
{
    CREATE_PLUGIN(pm, NFSnsServerPlayerPlugin)

};

NF_EXPORT void DllStopPlugin(NFIPluginManager* pm)
{
    DESTROY_PLUGIN(pm, NFSnsServerPlayerPlugin)
};

#endif


//////////////////////////////////////////////////////////////////////////

int NFSnsServerPlayerPlugin::GetPluginVersion()
{
	return 0;
}

std::string NFSnsServerPlayerPlugin::GetPluginName()
{
	return GET_CLASS_NAME(NFSnsServerPlayerPlugin);
}

void NFSnsServerPlayerPlugin::Install()
{
	REGISTER_MODULE(m_pObjPluginManager, NFCOnlineModule, NFCOnlineModule);
}

void NFSnsServerPlayerPlugin::Uninstall()
{
	UNREGISTER_MODULE(m_pObjPluginManager, NFCOnlineModule, NFCOnlineModule);
}

bool NFSnsServerPlayerPlugin::InitShmObjectRegister()
{
    NFServerConfig* pConfig = FindModule<NFIConfigModule>()->GetAppConfig(NF_ST_SNS_SERVER);
    NF_ASSERT(pConfig);

    uint32_t maxOnlinePlayerNum = pConfig->MaxOnlinePlayerNum;

    REGISTER_SHM_OBJ_WITH_HASH(NFRoleSimple, SNSSVR_MAX_ROLE_SIMPLE_NUM);
    REGISTER_SHM_OBJ_WITH_HASH(NFRoleDetail, SNSSVR_MAX_ROLE_SIMPLE_NUM/3);
    REGISTER_SINGLETON_SHM_OBJ(NFCacheMgr);
    REGISTER_SHM_OBJ(NFTransCacheBase, 0);
    REGISTER_SHM_OBJ(NFTransGetRoleSimple, SNS_GETTING_ROLE_SIZE*1.2);
    REGISTER_SHM_OBJ(NFTransGetRoleDetail, SNS_GETTING_ROLE_SIZE*1.2);
    REGISTER_SINGLETON_SHM_OBJ(NFLoadCacheMgr);
    REGISTER_SHM_OBJ(NFTransRoleLogin, maxOnlinePlayerNum/10);
    return true;
}