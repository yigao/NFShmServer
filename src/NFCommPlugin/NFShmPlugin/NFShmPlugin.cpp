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

    REGISTER_SHM_OBJ(NFShmObj, 0);
    REGISTER_SINGLETON_SHM_OBJ(NFGlobalID);
	REGISTER_SHM_OBJ(NFShmTimer, maxShmtimer);
    REGISTER_SINGLETON_SHM_OBJ(NFShmTimerManager);
    REGISTER_SHM_OBJ(NFShmSubscribeInfo, maxShmEvent);
    REGISTER_SINGLETON_SHM_OBJ(NFShmEventMgr);
    REGISTER_SINGLETON_SHM_OBJ(NFTransMng);
    REGISTER_SHM_OBJ(NFTransBase, 0);
	return true;
}
