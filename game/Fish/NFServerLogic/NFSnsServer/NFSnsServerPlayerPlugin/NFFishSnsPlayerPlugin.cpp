// -------------------------------------------------------------------------
//    @FileName         :    NFSnsServerPlayerPlugin.cpp
//    @Author           :    Gao.Yi
//    @Date             :   2022-09-18
//    @Email			:    445267987@qq.com
//    @Module           :    NFSnsServerPlayerPlugin
//
// -------------------------------------------------------------------------

#include "NFFishSnsPlayerPlugin.h"
#include "NFComm/NFPluginModule/NFIPluginManager.h"
#include "NFComm/NFPluginModule/NFIConfigModule.h"
#include "NFSnsPlayerModule.h"
#include "Cache/NFCacheMgr.h"
#include "Part/NFSnsPartModule.h"
#include "Part/NFSnsPart.h"
#include "LoadCache/NFLoadCacheMgr.h"
#include "Trans/NFTransGetRoleSimple.h"
#include "Trans/NFTransGetRoleDetail.h"
#include "Trans/NFTransCacheBase.h"

#ifdef NF_DYNAMIC_PLUGIN

NF_EXPORT void DllStartPlugin(NFIPluginManager* pm)
{
    CREATE_PLUGIN(pm, NFFishSnsPlayerPlugin)

};

NF_EXPORT void DllStopPlugin(NFIPluginManager* pm)
{
    DESTROY_PLUGIN(pm, NFFishSnsPlayerPlugin)
};

#endif


//////////////////////////////////////////////////////////////////////////

int NFFishSnsPlayerPlugin::GetPluginVersion()
{
	return 0;
}

std::string NFFishSnsPlayerPlugin::GetPluginName()
{
	return GET_CLASS_NAME(NFFishSnsPlayerPlugin);
}

void NFFishSnsPlayerPlugin::Install()
{
	REGISTER_MODULE(m_pObjPluginManager, NFCSnsPlayerModule, NFCSnsPlayerModule);
    REGISTER_MODULE(m_pObjPluginManager, NFSnsPartModule, NFSnsPartModule);
}

void NFFishSnsPlayerPlugin::Uninstall()
{
	UNREGISTER_MODULE(m_pObjPluginManager, NFCSnsPlayerModule, NFCSnsPlayerModule);
    UNREGISTER_MODULE(m_pObjPluginManager, NFSnsPartModule, NFSnsPartModule);
}

bool NFFishSnsPlayerPlugin::InitShmObjectRegister()
{
    NFServerConfig* pConfig = FindModule<NFIConfigModule>()->GetAppConfig(NF_ST_SNS_SERVER);
    NF_ASSERT(pConfig);

    uint32_t maxOnlinePlayerNum = pConfig->MaxOnlinePlayerNum;
    REGISTER_SINGLETON_SHM_OBJ(NFCacheMgr);//
    REGISTER_SINGLETON_SHM_OBJ(NFLoadCacheMgr);//

    REGISTER_SHM_OBJ_WITH_HASH(NFPlayerSimple, maxOnlinePlayerNum);//
    REGISTER_SHM_OBJ_WITH_HASH(NFPlayerDetail, maxOnlinePlayerNum);//

    REGISTER_SHM_OBJ(NFSnsPart,1);
    REGISTER_SHM_OBJ(NFTransCacheBase,1);
    REGISTER_SHM_OBJ(NFTransGetRoleSimple,maxOnlinePlayerNum/10);
    REGISTER_SHM_OBJ(NFTransGetRoleDetail,maxOnlinePlayerNum/10);
    return true;
}