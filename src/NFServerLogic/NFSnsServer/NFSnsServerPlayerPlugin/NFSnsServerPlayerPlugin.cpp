// -------------------------------------------------------------------------
//    @FileName         :    NFSnsServerPlayerPlugin.cpp
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFSnsServerPlayerPlugin
//
// -------------------------------------------------------------------------

#include "NFSnsServerPlayerPlugin.h"
#include "NFComm/NFPluginModule/NFIPluginManager.h"
#include "NFOnlineUser/NFOnlineUser.h"
#include "NFOnlineUser/NFOnlineUserMgr.h"
#include "NFComm/NFShmCore/NFServerFrameTypeDefines.h"
#include "NFOnlineModule.h"
#include "NFUserSimple/NFSnsUserSimple.h"
#include "NFUserSimple/NFSnsUserSimpleMgr.h"
#include "NFUserSimple/NFTransGetSnsUserSimple.h"
#include "NFUserSimple/NFSnsUserSimpleUtil.h"
#include "NFUserSimple/NFTransSaveSimpleDB.h"
#include "NFUserSimple/NFTransSnsBase.h"
#include "NFOnlineUser/NFTransSnsUserOnline.h"
#include "NFEventLog/NFTransSnsSendEventLog.h"

#include "NFComm/NFPluginModule/NFConfigMgr.h"

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
	REGISTER_MODULE(m_pPluginManager, NFCOnlineModule, NFCOnlineModule);
}

void NFSnsServerPlayerPlugin::Uninstall()
{
	UNREGISTER_MODULE(m_pPluginManager, NFCOnlineModule, NFCOnlineModule);
}

bool NFSnsServerPlayerPlugin::InitShmObjectRegister()
{
    NFServerConfig* pConfig = NFConfigMgr::Instance()->GetAppConfig(NF_ST_SNS_SERVER);
    NF_ASSERT(pConfig);

    uint32_t maxOnlinePlayerNum = pConfig->mMaxOnlinePlayerNum;

    REGISTER_SHM_OBJ_WITH_HASH(NFOnlineUser, EOT_SNS_ONLINE_USER_ID, maxOnlinePlayerNum);
    REGISTER_SINGLETON_SHM_OBJ(NFOnlineUserMgr, EOT_SNS_ONLINE_USER_HASH_TABLE_ID, 1);

    REGISTER_SHM_OBJ_WITH_HASH(NFSnsUserSimple, EOT_SNS_USER_SIMPLE_ID, maxOnlinePlayerNum*5);
    REGISTER_SINGLETON_SHM_OBJ(NFSnsUserSimpleMgr, EOT_SNS_USER_SIMPLE_HASH_TABLE_ID, 1);
    REGISTER_SINGLETON_SHM_OBJ(NFSnsUserSimpleUtil, EOT_SNS_USER_SIMPLE_UTIL_ID, 1);
    REGISTER_SHM_OBJ(NFTransGetSnsUserSimple, EOT_TRANS_GET_USER_SIMPLE, maxOnlinePlayerNum);
    REGISTER_SHM_OBJ(NFTransSnsBase, EOT_TRANS_SNS_BASE, maxOnlinePlayerNum);
	REGISTER_SHM_OBJ(NFTransSnsUserOnline, EOT_TRANS_SNS_USER_ONLINE, maxOnlinePlayerNum/10);
	REGISTER_SHM_OBJ(NFTransSaveSimpleDB, EOT_TRANS_SAVE_USER_SIMPLEL, maxOnlinePlayerNum);
    REGISTER_SHM_OBJ(NFTransSnsSendEventLog, EOT_TRANS_SNS_SEND_EVENT_LOG_ID, maxOnlinePlayerNum);

    return true;
}