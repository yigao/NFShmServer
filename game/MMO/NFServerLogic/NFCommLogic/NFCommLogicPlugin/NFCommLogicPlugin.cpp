// -------------------------------------------------------------------------
//    @FileName         :    NFCommLogicPlugin.cpp
//    @Author           :    Gao.Yi
//    @Date             :   2022-09-18
//    @Email			:    445267987@qq.com
//    @Module           :    NFCommLogicPlugin
//
// -------------------------------------------------------------------------

#include "NFCommLogicPlugin.h"
#include "NFCommLogicModule.h"
#include "NFComm/NFPluginModule/NFIPluginManager.h"
#include "NFComm/NFPluginModule/NFIConfigModule.h"
#include "NFComm/NFPluginModule/NFCheck.h"
#include "DescStore/NFDescStoreHead.h"
#include "DescStore/NFDescStoreRegister.h"
#include "DescStore/NFDescStoreDefine.h"

#include "DescStoreEx/NFMapDescStoreEx.h"
#include "NFLogicCommon/NFAttrMgr.h"
#include "DescStoreEx/NFRoleDescStoreEx.h"
#include "DescStoreEx/NFFuncUnLockDescStoreEx.h"
#include "DescStoreEx/NFItemDescStoreEx.h"
#include "DescStoreEx/NFMissionDescStoreEx.h"


#ifdef NF_DYNAMIC_PLUGIN

NF_EXPORT void DllStartPlugin(NFIPluginManager* pm)
{
    CREATE_PLUGIN(pm, NFCommLogicPlugin)

};

NF_EXPORT void DllStopPlugin(NFIPluginManager* pm)
{
    DESTROY_PLUGIN(pm, NFCommLogicPlugin)
};

#endif


//////////////////////////////////////////////////////////////////////////

int NFCommLogicPlugin::GetPluginVersion()
{
	return 0;
}

std::string NFCommLogicPlugin::GetPluginName()
{
	return GET_CLASS_NAME(NFCommLogicPlugin);
}

void NFCommLogicPlugin::Install()
{
	REGISTER_MODULE(m_pObjPluginManager, NFICommLogicModule, NFCommLogicModule)
}

void NFCommLogicPlugin::Uninstall()
{
	UNREGISTER_MODULE(m_pObjPluginManager, NFICommLogicModule, NFCommLogicModule)
}

bool NFCommLogicPlugin::InitShmObjectRegister()
{
    NFServerConfig* pConfig = FindModule<NFIConfigModule>()->GetAppConfig(NF_ST_NONE);
    CHECK_EXPR(pConfig, false, "pConfig == NULL");
    CHECK_EXPR(!pConfig->DefaultDBName.empty(), false, "pConfig->DefaultDBName.empty()");

    EOT_DESC_STORE_ALL_REGISTER_DEFINE

    /////////////////////////////////////////Register DescStroeEx//////////////////////////////////
    REGISTER_DESCSTORE(NFMapDescStoreEx);
    REGISTER_DESCSTORE(NFRoleDescStoreEx);
    REGISTER_DESCSTORE(NFFuncUnLockDescStoreEx);
    REGISTER_DESCSTORE(NFItemDescStoreEx);
    REGISTER_DESCSTORE(NFMissionDescStoreEx);

    /////////////////////////////////////Server Common////////////////////////////////////////////
    REGISTER_SINGLETON_SHM_OBJ(NFAttrMgr);
    /////////////////////////////////////Server Common////////////////////////////////////////////
	return true;
}
