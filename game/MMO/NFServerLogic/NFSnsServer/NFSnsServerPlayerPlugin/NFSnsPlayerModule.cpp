// -------------------------------------------------------------------------
//    @FileName         :    NFCOnlineModule.cpp
//    @Author           :    Gao.Yi
//    @Date             :   2022-09-18
//    @Email			:    445267987@qq.com
//    @Module           :    NFCOnlineModule
//
// -------------------------------------------------------------------------

#include "NFSnsPlayerModule.h"
#include "Cache/NFPlayerSimple.h"
#include "Cache/NFCacheMgr.h"

NFCSnsPlayerModule::NFCSnsPlayerModule(NFIPluginManager *p) : NFMMODynamicModule(p)
{
}

NFCSnsPlayerModule::~NFCSnsPlayerModule()
{
}

bool NFCSnsPlayerModule::Awake()
{
    ////////////proxy msg////player login,disconnect,reconnet/////////////////////

    ///////////world msg//////////////////////////////////////////////////////////

    RegisterAppTask(NF_ST_SNS_SERVER, APP_INIT_DESC_STORE_LOAD, "SnsServer Load Desc Store", APP_INIT_TASK_GROUP_SERVER_LOAD_DESC_STORE);


    ///////////logic msg//////////////////////////////////////////////////////////
    return true;
}

int
NFCSnsPlayerModule::OnExecute(uint32_t serverType, uint32_t nEventID, uint32_t bySrcType, uint64_t nSrcID, const google::protobuf::Message *pMessage)
{
    return 0;
}

bool NFCSnsPlayerModule::Init()
{
    return true;
}

bool NFCSnsPlayerModule::Execute()
{
    return true;
}

bool NFCSnsPlayerModule::OnDynamicPlugin()
{
    return true;
}

int NFCSnsPlayerModule::OnTimer(uint32_t nTimerID)
{
    NFCacheMgr::Instance(m_pObjPluginManager)->QueryPlayerSimple(10000);
    FindModule<NFICoroutineModule>()->MakeCoroutine([this]{
        NFCacheMgr::Instance(m_pObjPluginManager)->QueryPlayerSimpleByRpc(10000);
    });

    return 0;
}

int NFCSnsPlayerModule::OnHandleClientMessage(uint32_t msgId, NFDataPackage &packet, uint64_t playerId, uint64_t param2)
{
    if (!m_pObjPluginManager->IsInited(NF_ST_SNS_SERVER))
    {
        NFLogError(NF_LOG_SYSTEMLOG, packet.nParam1, "Sns Server not inited, drop client msg:{}", packet.ToString());
        return -1;
    }

    if (m_pObjPluginManager->IsServerStopping())
    {
        NFLogError(NF_LOG_SYSTEMLOG, packet.nParam1, "Sns Server is Stopping, drop client msg:{}", packet.ToString());
        return -1;
    }

    switch (msgId)
    {
        default:
        {
            NFLogError(NF_LOG_SYSTEMLOG, 0, "Client MsgId:{} Register, But Not Handle, Package:{}", msgId, packet.ToString());
            break;
        }
    }

    return 0;
}

int NFCSnsPlayerModule::OnHandleServerMessage(uint32_t msgId, NFDataPackage &packet, uint64_t param1, uint64_t param2)
{
    if (!m_pObjPluginManager->IsInited(NF_ST_SNS_SERVER))
    {
        NFLogError(NF_LOG_SYSTEMLOG, packet.nParam1, "Sns Server not inited, drop client msg:{}", packet.ToString());
        return -1;
    }

    if (m_pObjPluginManager->IsServerStopping())
    {
        NFLogError(NF_LOG_SYSTEMLOG, packet.nParam1, "Sns Server is Stopping, drop client msg:{}", packet.ToString());
        return -1;
    }

    switch (msgId)
    {
        default:
        {
            NFLogError(NF_LOG_SYSTEMLOG, 0, "Server Internal MsgId:{} Register, But Not Handle, Package:{}", msgId, packet.ToString());
            break;
        }
    }

    return 0;
}

