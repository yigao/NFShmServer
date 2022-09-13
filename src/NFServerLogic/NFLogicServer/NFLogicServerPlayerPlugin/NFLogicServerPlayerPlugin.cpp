// -------------------------------------------------------------------------
//    @FileName         :    NFLogicServerPlayerPlugin.cpp
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFLogicServerPlayerPlugin
//
// -------------------------------------------------------------------------

#include "NFLogicServerPlayerPlugin.h"
#include "NFComm/NFPluginModule/NFIPluginManager.h"
#include "NFUserDetailModule.h"

#include "NFComm/NFPluginModule/NFConfigMgr.h"

#include "NFUserDetail/NFTransLogicUserBase.h"
#include "NFUserDetail/NFUserDetail.h"
#include "NFUserDetail/NFUserDetailMgr.h"
#include "NFUserDetail/NFTransGetUserDetail.h"
#include "NFUserDetail/NFTransCreateUserDetail.h"
#include "NFUserDetail/NFTransSaveDB.h"
#include "NFUserDetail/NFTransSaveMoney.h"

#include "NFUserDetail/NFTransSendEventLog.h"
#include "NFUserDetail/NFTransGetEventLog.h"
#include "NFUserDetail/NFTransHandleEventLog.h"
#include "NFUserDetail/NFPlayerBindPhoneTrans.h"


#ifdef NF_DYNAMIC_PLUGIN

NF_EXPORT void DllStartPlugin(NFIPluginManager* pm)
{
    CREATE_PLUGIN(pm, NFLogicServerPlayerPlugin)

};

NF_EXPORT void DllStopPlugin(NFIPluginManager* pm)
{
    DESTROY_PLUGIN(pm, NFLogicServerPlayerPlugin)
};

#endif


//////////////////////////////////////////////////////////////////////////

int NFLogicServerPlayerPlugin::GetPluginVersion()
{
	return 0;
}

std::string NFLogicServerPlayerPlugin::GetPluginName()
{
	return GET_CLASS_NAME(NFLogicServerPlayerPlugin);
}

void NFLogicServerPlayerPlugin::Install()
{
    REGISTER_MODULE(m_pPluginManager, NFIUserDetailModule, NFCUserDetailModule);
}

void NFLogicServerPlayerPlugin::Uninstall()
{
    UNREGISTER_MODULE(m_pPluginManager, NFIUserDetailModule, NFCUserDetailModule);
}

bool NFLogicServerPlayerPlugin::InitShmObjectRegister()
{
    NFServerConfig* pConfig = NFConfigMgr::Instance()->GetAppConfig(NF_ST_LOGIC_SERVER);
    NF_ASSERT(pConfig);

    uint32_t maxOnlinePlayerNum = pConfig->mMaxOnlinePlayerNum;

    REGISTER_SHM_OBJ_WITH_HASH(NFUserDetail, EOT_USER_DETAIL_ID, maxOnlinePlayerNum);
    REGISTER_SINGLETON_SHM_OBJ(NFUserDetailMgr, EOT_USER_DETAIL_HASH_TABLE_ID, 1);
    REGISTER_SHM_OBJ(NFTransGetUserDetail, EOT_TRANS_GET_USER_DETAIL, maxOnlinePlayerNum);
    REGISTER_SHM_OBJ(NFTransCreateUserDetail, EOT_TRANS_CREATE_USER_DETAIL, maxOnlinePlayerNum);
	REGISTER_SHM_OBJ(NFTransLogicUserBase, EOT_TRANS_LOGIC_USER_BASE, 1);
	REGISTER_SHM_OBJ(NFTransSaveMoney, EOT_TRANS_SAVE_USER_MONEY, maxOnlinePlayerNum);
	REGISTER_SHM_OBJ(NFTransSaveDB, EOT_TRANS_SAVE_USER_DETAIL, maxOnlinePlayerNum);

    REGISTER_SHM_OBJ(NFTransSendEventLog, EOT_TRANS_SEND_EVENT_LOG_ID, maxOnlinePlayerNum);
    REGISTER_SHM_OBJ(NFTransGetEventLog, EOT_TRANS_GET_EVENT_LOG_ID, maxOnlinePlayerNum);
    REGISTER_SHM_OBJ(NFTransHandleEventLog, EOT_TRANS_HANDLE_EVENT_LOG_ID, maxOnlinePlayerNum);

    REGISTER_SHM_OBJ(NFPlayerBindPhoneTrans, EOT_TRANS_PLAYER_BIND_PHONE_TRANS_ID, maxOnlinePlayerNum);
	return true;
}