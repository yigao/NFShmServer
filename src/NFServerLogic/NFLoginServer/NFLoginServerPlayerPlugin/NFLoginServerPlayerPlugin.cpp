// -------------------------------------------------------------------------
//    @FileName         :    NFGameServerPlugin.cpp
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFGameServerPlugin
//
// -------------------------------------------------------------------------

#include "NFLoginServerPlayerPlugin.h"
#include "NFComm/NFPluginModule/NFIPluginManager.h"
#include "NFAccountLoginModule.h"
#include "NFAccountLoginMgr.h"
#include "NFGetAccountTrans.h"
#include "NFRegisterAccountTrans.h"
#include "NFPhoneAutoCodeMgr.h"
#include "NFBindPhoneTrans.h"
#include "NFComm/NFPluginModule/NFConfigMgr.h"

#ifdef NF_DYNAMIC_PLUGIN

NF_EXPORT void DllStartPlugin(NFIPluginManager* pm)
{
    CREATE_PLUGIN(pm, NFLoginServerPlayerPlugin)

};

NF_EXPORT void DllStopPlugin(NFIPluginManager* pm)
{
    DESTROY_PLUGIN(pm, NFLoginServerPlayerPlugin)
};

#endif


//////////////////////////////////////////////////////////////////////////

int NFLoginServerPlayerPlugin::GetPluginVersion()
{
	return 0;
}

std::string NFLoginServerPlayerPlugin::GetPluginName()
{
	return GET_CLASS_NAME(NFLoginServerPlayerPlugin);
}

void NFLoginServerPlayerPlugin::Install()
{
	REGISTER_MODULE(m_pPluginManager, NFIAccountLoginModule, NFCAccountLoginModule);
}

void NFLoginServerPlayerPlugin::Uninstall()
{
	UNREGISTER_MODULE(m_pPluginManager, NFIAccountLoginModule, NFCAccountLoginModule);
}

bool NFLoginServerPlayerPlugin::InitShmObjectRegister()
{
    NFServerConfig* pConfig = NFConfigMgr::Instance()->GetAppConfig(NF_ST_LOGIN_SERVER);
    NF_ASSERT(pConfig);

    uint32_t maxOnlinePlayerNum = pConfig->mMaxOnlinePlayerNum;

    REGISTER_SHM_OBJ_WITH_EXTERNAL_DATA(NFAccountLoginMgr, EOT_ACCOUNTLOGIN_HASHTABLE_ID, 1, maxOnlinePlayerNum);
    REGISTER_SHM_OBJ(NFGetAccountTrans, EOT_TRANS_GET_ACCOUNT, maxOnlinePlayerNum);
    REGISTER_SHM_OBJ(NFRegisterAccountTrans, EOT_TRANS_REGISTER_ACCOUNT, maxOnlinePlayerNum);
    REGISTER_SHM_OBJ_WITH_HASH(NFPhoneAutoCode, EOT_PHONE_AUTO_CODE_ID, maxOnlinePlayerNum);
    REGISTER_SINGLETON_SHM_OBJ(NFPhoneAutoCodeMgr, EOT_PHONE_AUTO_CODE_MGR_ID, 1);
    REGISTER_SHM_OBJ(NFBindPhoneTrans, EOT_TRANS_REGISTER_ACCOUNT_BIND_PHONE, maxOnlinePlayerNum);
	return true;
}