// -------------------------------------------------------------------------
//    @FileName         :    NFServerCommonPlugin.cpp
//    @Author           :    Gao.Yi
//    @Date             :   2022-09-18
//    @Email			:    445267987@qq.com
//    @Module           :    NFServerCommonPlugin
//
// -------------------------------------------------------------------------

#include "NFDescStorePlugin.h"
#include "NFComm/NFPluginModule/NFIPluginManager.h"
#include "NFComm/NFPluginModule/NFIConfigModule.h"
#include "NFServerComm/NFServerCommon/NFBaseDBObj.h"
#include "NFServerComm/NFServerCommon/NFDBObjTrans.h"
#include "NFServerComm/NFServerCommon/NFDBObjMgr.h"
#include "NFDescStoreTrans.h"
#include "NFCDescStoreModule.h"


#ifdef NF_DYNAMIC_PLUGIN

NF_EXPORT void DllStartPlugin(NFIPluginManager* pm)
{
    CREATE_PLUGIN(pm, NFDescStorePlugin)

};

NF_EXPORT void DllStopPlugin(NFIPluginManager* pm)
{
    DESTROY_PLUGIN(pm, NFDescStorePlugin)
};

#endif


//////////////////////////////////////////////////////////////////////////

int NFDescStorePlugin::GetPluginVersion()
{
    return 0;
}

std::string NFDescStorePlugin::GetPluginName()
{
    return GET_CLASS_NAME(NFDescStorePlugin);
}

void NFDescStorePlugin::Install()
{
    REGISTER_MODULE(m_pObjPluginManager, NFIDescStoreModule, NFCDescStoreModule);
}

void NFDescStorePlugin::Uninstall()
{
    UNREGISTER_MODULE(m_pObjPluginManager, NFIDescStoreModule, NFCDescStoreModule);
}

bool NFDescStorePlugin::InitShmObjectRegister()
{
    uint32_t maxOnlinePlayerNum = 100;
    if (!m_pObjPluginManager->IsLoadAllServer())
    {
        NFServerConfig* pConfig = FindModule<NFIConfigModule>()->GetAppConfig(NF_ST_NONE);
        NF_ASSERT(pConfig);

        maxOnlinePlayerNum = pConfig->MaxOnlinePlayerNum;
    }

    REGISTER_SHM_OBJ(NFBaseDBObj, 0);
    REGISTER_SHM_OBJ(NFDBObjTrans, 100);
    REGISTER_SINGLETON_SHM_OBJ(NFDBObjMgr);
    REGISTER_SHM_OBJ(NFDescStoreTrans, 100);
    return true;
}
