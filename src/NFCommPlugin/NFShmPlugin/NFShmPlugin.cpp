// -------------------------------------------------------------------------
//    @FileName         :    NFShmPlugin.cpp
//    @Author           :    LvSheng.Huang
//    @Date             :   xxxx-xx-xx
//    @Module           :    NFShmPlugin
//
// -------------------------------------------------------------------------

#include "NFShmPlugin.h"
#include "NFCSharedMemModule.h"
#include "NFCDescStoreModule.h"

#include "NFGlobalID.h"
#include "NFShmTimer.h"
#include "NFShmTimerManager.h"
#include "NFTransMng.h"
#include "NFComm/NFShmCore/NFTransBase.h"
#include "NFComm/NFShmCore/NFBaseDBObj.h"
#include "NFComm/NFShmCore/NFDBObjTrans.h"
#include "NFComm/NFShmCore/NFDBObjMgr.h"
#include "NFComm/NFShmCore/NFDescStoreTrans.h"
#include "NFComm/NFPluginModule/NFConfigMgr.h"

//
//
#ifdef NF_DYNAMIC_PLUGIN

NF_EXPORT void DllStartPlugin(NFIPluginManager* pm)
{
	CREATE_PLUGIN(pm, NFShmPlugin)
};

NF_EXPORT void DllStopPlugin(NFIPluginManager* pm)
{
	DESTROY_PLUGIN(pm, NFShmPlugin)
};

#endif

//////////////////////////////////////////////////////////////////////////

int NFShmPlugin::GetPluginVersion()
{
	return 0;
}

std::string NFShmPlugin::GetPluginName()
{
	return GET_CLASS_NAME(NFShmPlugin);
}

bool NFShmPlugin::IsDynamicLoad()
{
	return false;
}

void NFShmPlugin::Install()
{
    REGISTER_MODULE(m_pPluginManager, NFISharedMemModule, NFCSharedMemModule);
    REGISTER_MODULE(m_pPluginManager, NFIDescStoreModule, NFCDescStoreModule);
}

void NFShmPlugin::Uninstall()
{
    UNREGISTER_MODULE(m_pPluginManager, NFISharedMemModule, NFCSharedMemModule);
    UNREGISTER_MODULE(m_pPluginManager, NFIDescStoreModule, NFCDescStoreModule);
}

bool NFShmPlugin::InitShmObjectRegister()
{
    uint32_t maxOnlinePlayerNum = 100;
    if (!NFIPluginManager::Instance()->IsLoadAllServer())
    {
        NFServerConfig* pConfig = NFConfigMgr::Instance()->GetAppConfig(NF_ST_NONE);
        NF_ASSERT(pConfig);

        maxOnlinePlayerNum = pConfig->mMaxOnlinePlayerNum;
    }

    uint32_t maxShmtimer = ALL_TIMER_COUNT/10 + maxOnlinePlayerNum*10;
    if (maxShmtimer >= ALL_TIMER_COUNT)
    {
        maxShmtimer = ALL_TIMER_COUNT;
    }


    REGISTER_SHM_OBJ(NFShmObj, EOT_OBJECT, 0);
    REGISTER_SINGLETON_SHM_OBJ(NFGlobalID, EOT_GLOBAL_ID, 1);
	REGISTER_SHM_OBJ(NFShmTimer, EOT_TYPE_TIMER_OBJ, maxShmtimer);
    REGISTER_SINGLETON_SHM_OBJ(NFShmTimerManager, EOT_TYPE_TIMER_MNG, 1);
    REGISTER_SINGLETON_SHM_OBJ(NFTransMng, EOT_TRANS_MNG, 1);
    REGISTER_SHM_OBJ(NFTransBase, EOT_TRANS_BASE, 0);
    REGISTER_SHM_OBJ(NFBaseDBObj, EOT_BASE_DB_OBJ, 0);
    REGISTER_SHM_OBJ(NFDBObjTrans, EOT_TRANS_DB_OBJ, 100);
    REGISTER_SINGLETON_SHM_OBJ(NFDBObjMgr, EOT_TRANS_DB_OBJ_MGR, 1);
    REGISTER_SHM_OBJ(NFDescStoreTrans, EOT_RPC_TRANS_ID, 100);
	return true;
}
