// -------------------------------------------------------------------------
//    @FileName         :    NFSnsServerPlayerPlugin.cpp
//    @Author           :    Gao.Yi
//    @Date             :   2022-09-18
//    @Email			:    445267987@qq.com
//    @Module           :    NFSnsServerPlayerPlugin
//
// -------------------------------------------------------------------------

#include "NFMMOSnsPlayerPlugin.h"

#include <Chat/NFSnsChatMgr.h>
#include <Chat/NFSnsChatPart.h>
#include <Clan/NFSnsClanMgr.h>
#include <Faction/NFFactionMgr.h>
#include <ObService/NFSnsObServiceModule.h>
#include <Relation/NFSnsRelationMgr.h>
#include <Team/NFSnsTeamMgr.h>

#include "NFComm/NFPluginModule/NFIPluginManager.h"
#include "NFComm/NFPluginModule/NFIConfigModule.h"
#include "NFSnsPlayerModule.h"
#include "Cache/NFCacheMgr.h"
#include "Part/NFSnsPartModule.h"
#include "Part/NFSnsPart.h"
#include "LoadCache/NFLoadCacheMgr.h"
#include "Trans/NFTransGetPlayerSimple.h"
#include "Trans/NFTransGetPlayerDetail.h"
#include "Trans/NFTransCacheBase.h"
#include "Trans/NFSnsTransSaveDetailDB.h"
#include "Relation/NFSnsRelationPart.h"

#ifdef NF_DYNAMIC_PLUGIN

NF_EXPORT void DllStartPlugin(NFIPluginManager* pm)
{
    CREATE_PLUGIN(pm, NFMMOSnsPlayerPlugin)

};

NF_EXPORT void DllStopPlugin(NFIPluginManager* pm)
{
    DESTROY_PLUGIN(pm, NFMMOSnsPlayerPlugin)
};

#endif


//////////////////////////////////////////////////////////////////////////

int NFMMOSnsPlayerPlugin::GetPluginVersion()
{
	return 0;
}

std::string NFMMOSnsPlayerPlugin::GetPluginName()
{
	return GET_CLASS_NAME(NFMMOSnsPlayerPlugin);
}

void NFMMOSnsPlayerPlugin::Install()
{
	REGISTER_MODULE(m_pObjPluginManager, NFCSnsPlayerModule, NFCSnsPlayerModule);
    REGISTER_MODULE(m_pObjPluginManager, NFSnsPartModule, NFSnsPartModule);
    REGISTER_MODULE(m_pObjPluginManager, NFSnsObServiceModule, NFSnsObServiceModule);

}

void NFMMOSnsPlayerPlugin::Uninstall()
{
	UNREGISTER_MODULE(m_pObjPluginManager, NFCSnsPlayerModule, NFCSnsPlayerModule);
    UNREGISTER_MODULE(m_pObjPluginManager, NFSnsPartModule, NFSnsPartModule);
    UNREGISTER_MODULE(m_pObjPluginManager, NFSnsObServiceModule, NFSnsObServiceModule);
}

bool NFMMOSnsPlayerPlugin::InitShmObjectRegister()
{
    NFServerConfig* pConfig = FindModule<NFIConfigModule>()->GetAppConfig(NF_ST_SNS_SERVER);
    NF_ASSERT(pConfig);

    uint32_t maxOnlinePlayerNum = pConfig->MaxOnlinePlayerNum*1.2;

    REGISTER_SHM_OBJ(NFSnsObService, 0);
    REGISTER_SINGLETON_SHM_OBJ(NFCacheMgr);//
    REGISTER_SINGLETON_SHM_OBJ(NFLoadCacheMgr);//
    REGISTER_SINGLETON_SHM_OBJ(NFSnsFactionMgr);//
    REGISTER_SINGLETON_SHM_OBJ(NFSnsChatMgr);//
    REGISTER_SINGLETON_SHM_OBJ(NFSnsClanMgr);//
    REGISTER_SINGLETON_SHM_OBJ(NFSnsTeamMgr);//
    REGISTER_SINGLETON_SHM_OBJ(NFSnsRelationMgr);//

    REGISTER_SHM_OBJ_WITH_HASH(NFPlayerSimple, maxOnlinePlayerNum*2);//
    REGISTER_SHM_OBJ_WITH_HASH(NFPlayerDetail, maxOnlinePlayerNum);//
    REGISTER_SHM_OBJ(NFSnsPart,1);
    REGISTER_SHM_OBJ(NFSnsRelationPart,maxOnlinePlayerNum);
    REGISTER_SHM_OBJ(NFSnsChatPart,maxOnlinePlayerNum);


    REGISTER_SHM_OBJ(NFTransCacheBase,1);
    REGISTER_SHM_OBJ(NFTransGetPlayerSimple, maxOnlinePlayerNum / 10);
    REGISTER_SHM_OBJ(NFTransGetPlayerDetail, maxOnlinePlayerNum / 10);
    REGISTER_SHM_OBJ(NFSnsTransSaveDetailDB, maxOnlinePlayerNum / 10);
    return true;
}