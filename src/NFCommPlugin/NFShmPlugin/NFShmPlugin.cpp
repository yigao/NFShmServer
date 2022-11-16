// -------------------------------------------------------------------------
//    @FileName         :    NFShmPlugin.cpp
//    @Author           :    LvSheng.Huang
//    @Date             :   2022-09-18
//    @Module           :    NFShmPlugin
//
// -------------------------------------------------------------------------

#include "NFShmPlugin.h"
#include "NFCSharedMemModule.h"

#include "NFGlobalID.h"
#include "NFShmTimer.h"
#include "NFShmTimerManager.h"
#include "NFTransMng.h"
#include "NFComm/NFShmCore/NFTransBase.h"
#include "NFComm/NFPluginModule/NFIConfigModule.h"
#include "NFShmSubscribeInfo.h"
#include "NFShmEventMgr.h"

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
    REGISTER_MODULE(m_pObjPluginManager, NFISharedMemModule, NFCSharedMemModule);
}

void NFShmPlugin::Uninstall()
{
    UNREGISTER_MODULE(m_pObjPluginManager, NFISharedMemModule, NFCSharedMemModule);
}

bool NFShmPlugin::InitShmObjectRegister()
{
    uint32_t maxOnlinePlayerNum = 100;
    if (!m_pObjPluginManager->IsLoadAllServer())
    {
        NFServerConfig* pConfig = FindModule<NFIConfigModule>()->GetAppConfig(NF_ST_NONE);
        NF_ASSERT(pConfig);

        maxOnlinePlayerNum = pConfig->MaxOnlinePlayerNum;
    }

    uint32_t maxShmtimer = ALL_TIMER_COUNT/10 + maxOnlinePlayerNum*10;
    if (maxShmtimer >= ALL_TIMER_COUNT)
    {
        maxShmtimer = ALL_TIMER_COUNT;
    }

    uint32_t maxShmEvent = NF_SHM_EVENT_KEY_MAX_NUM/10 + maxOnlinePlayerNum*10;
    if (maxShmEvent >= NF_SHM_EVENT_KEY_MAX_NUM)
    {
        maxShmEvent = NF_SHM_EVENT_KEY_MAX_NUM;
    }

    REGISTER_SHM_OBJ(NFShmObj, EOT_OBJECT, 0);
    REGISTER_SINGLETON_SHM_OBJ(NFGlobalID, EOT_GLOBAL_ID);
	REGISTER_SHM_OBJ(NFShmTimer, EOT_TYPE_TIMER_OBJ, maxShmtimer);
    REGISTER_SINGLETON_SHM_OBJ(NFShmTimerManager, EOT_TYPE_TIMER_MNG);
    REGISTER_SHM_OBJ(NFShmSubscribeInfo, EOT_TYPE_SUBSCRIBEINFO_OBJ, maxShmEvent);
    REGISTER_SINGLETON_SHM_OBJ(NFShmEventMgr, EOT_TYPE_EVENT_MGR);
    REGISTER_SINGLETON_SHM_OBJ(NFTransMng, EOT_TRANS_MNG);
    REGISTER_SHM_OBJ(NFTransBase, EOT_TRANS_BASE, 0);
	return true;
}
