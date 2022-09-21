// -------------------------------------------------------------------------
//    @FileName         :    NFMasterServerPlugin.cpp
//    @Author           :    Gao.Yi
//    @Date             :   2022-09-18
//    @Email			:    445267987@qq.com
//    @Module           :    NFMasterServerPlugin
//
// -------------------------------------------------------------------------

#include "NFServerCommonPlugin.h"
#include "NFComm/NFPluginModule/NFIPluginManager.h"
#include "NFComm/NFPluginModule/NFIConfigModule.h"
#include "NFBaseDBObj.h"
#include "NFDBObjTrans.h"
#include "NFDBObjMgr.h"
#include "NFDescStoreTrans.h"
#include "NFServerMessageModule.h"
#include "NFCDescStoreModule.h"


#ifdef NF_DYNAMIC_PLUGIN

NF_EXPORT void DllStartPlugin(NFIPluginManager* pm)
{
    CREATE_PLUGIN(pm, NFServerCommonPlugin)

};

NF_EXPORT void DllStopPlugin(NFIPluginManager* pm)
{
    DESTROY_PLUGIN(pm, NFServerCommonPlugin)
};

#endif


//////////////////////////////////////////////////////////////////////////

int NFServerCommonPlugin::GetPluginVersion()
{
    return 0;
}

std::string NFServerCommonPlugin::GetPluginName()
{
    return GET_CLASS_NAME(NFServerCommonPlugin);
}

void NFServerCommonPlugin::Install()
{
    REGISTER_MODULE(m_pObjPluginManager, NFIServerMessageModule, NFServerMessageModule);
    REGISTER_MODULE(m_pObjPluginManager, NFIDescStoreModule, NFCDescStoreModule);
}

void NFServerCommonPlugin::Uninstall()
{
    UNREGISTER_MODULE(m_pObjPluginManager, NFIServerMessageModule, NFServerMessageModule);
    UNREGISTER_MODULE(m_pObjPluginManager, NFIDescStoreModule, NFCDescStoreModule);
}

bool NFServerCommonPlugin::InitShmObjectRegister()
{
    uint32_t maxOnlinePlayerNum = 100;
    if (!m_pObjPluginManager->IsLoadAllServer())
    {
        NFServerConfig* pConfig = FindModule<NFIConfigModule>()->GetAppConfig(NF_ST_NONE);
        NF_ASSERT(pConfig);

        maxOnlinePlayerNum = pConfig->MaxOnlinePlayerNum;
    }

    REGISTER_SHM_OBJ(NFBaseDBObj, EOT_BASE_DB_OBJ, 0);
    REGISTER_SHM_OBJ(NFDBObjTrans, EOT_TRANS_DB_OBJ, 100);
    REGISTER_SINGLETON_SHM_OBJ(NFDBObjMgr, EOT_TRANS_DB_OBJ_MGR, 1);
    REGISTER_SHM_OBJ(NFDescStoreTrans, EOT_RPC_TRANS_ID, 100);
    return true;
}
