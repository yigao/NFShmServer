// -------------------------------------------------------------------------
//    @FileName         :    NFWorldLoginModule.cpp
//    @Author           :    Gao.Yi
//    @Date             :   2022-09-18
//    @Email			:    445267987@qq.com
//    @Module           :    NFWorldLoginModule
//
// -------------------------------------------------------------------------

#include <ClientServerCmd.pb.h>
#include <Com.pb.h>
#include <ComDefine.pb.h>
#include <ClientServer.pb.h>
#include <ServerClient.pb.h>
#include <NFComm/NFPluginModule/NFCheck.h>
#include <NFComm/NFCore/NFServerIDUtil.h>
#include <NFComm/NFCore/NFTime.h>
#include <NFLogicCommon/NFLogicCommon.h>
#include "NFWorldPlayerModule.h"

#include "NFComm/NFPluginModule/NFIMessageModule.h"
#include "NFComm/NFPluginModule/NFIConfigModule.h"
#include "NFServerComm/NFServerCommon/NFIWorldServerModule.h"
#include "NFWorldConfig.h"
#include "NFWorldPlayer.h"
#include "NFWorldPlayerMgr.h"

NFCWorldPlayerModule::NFCWorldPlayerModule(NFIPluginManager *p) : NFIDynamicModule(p)
{

}

NFCWorldPlayerModule::~NFCWorldPlayerModule()
{
}

bool NFCWorldPlayerModule::Awake()
{
    ////////////proxy msg////player login,disconnect,reconnet/////////////////////
    FindModule<NFIMessageModule>()->AddMessageCallBack(NF_ST_WORLD_SERVER, proto_ff::CLIENT_TO_CENTER_LOGIN, this,
                                                       &NFCWorldPlayerModule::OnHandleClientCenterLogin);
    //////////check proxy msg///////////////////////
    FindModule<NFIWorldServerModule>()->AddProxyMsgCheckCallBack(this, &NFCWorldPlayerModule::OnCheckWorldServerMsg);

    return true;
}

bool NFCWorldPlayerModule::Execute()
{
    return true;
}

bool NFCWorldPlayerModule::OnDynamicPlugin()
{
    return true;
}

/**
 * @brief 处理登录协议
 * @param unLinkId
 * @param packet
 * @return
 */
int NFCWorldPlayerModule::OnHandleClientCenterLogin(uint64_t unLinkId, NFDataPackage &packet)
{
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "-- begin --");
    proto_ff::ClientLoginGateReq clogin;
    CLIENT_MSG_PROCESS_WITH_PRINTF(packet, clogin);

    NFServerConfig *pConfig = FindModule<NFIConfigModule>()->GetAppConfig(NF_ST_WORLD_SERVER);
    CHECK_EXPR(pConfig, -1, "pConfig == NULL, FindModule<NFIConfigModule>()->GetAppConfig(NF_ST_WORLD_SERVER)");
    const proto_ff_s::WorldExternalConfig_s* pExternalConfig = NFWorldConfig::Instance(m_pObjPluginManager)->GetConfig();
    CHECK_EXPR(pExternalConfig, -1, "pExternalConfig == NULL");

    //验证版本号，如果版本号不对，不让进入
    CHECK_EXPR(clogin.version() == pConfig->ClientVersion, -1, "xMsg.version():{} != pConfig->ClientVersion:{}", clogin.version(),
               pConfig->ClientVersion);

    uint32_t zid = NFServerIDUtil::GetZoneID(pConfig->BusId);
    uint32_t gateid = packet.nSrcId;

    /*
    因前端登录协议写入c#了，为了不重新出app包，前后端用  ClientLoginGateReq 协议中的 token字段格式为：MD5字符串|出生区服ID
    后面如果有校验 token的需要的话,可以通过分隔符来实现
    */
    const string &strParam = clogin.token();
    if (pExternalConfig->TokenTimeCheck)
    {
        uint64_t SecTime = NFTime::Now().UnixMSec();
        CHECK_EXPR((SecTime - clogin.logintimestamp()) <= MAX_CENTER_LOGIN_TIME_SEC, -1, "");
    }

    //
    VEC_STRING vecCheck;
    vecCheck.clear();
    CommonApi::SplitStr(strParam, "|", &vecCheck);
    if (vecCheck.size() != 2)
    {
        LogErrFmtPrint("[center] CenterAccountMgr::LoginGateReq...uid:%u,clientid:%u,paramsize:%d,param:%s", uid, clientId, (int32_t) vecCheck.size(),
                       strParam.c_str());
        goto Exit0;
    }
    string &strToken = vecCheck.at(0);
    int32_t bornZid = CommonApi::StrToInt(vecCheck.at(1));
    //校验Token
    string srvToken = g_MakeMd5(uid, clogin.logintimestamp());
    MMOLOG_PROCESS_ERROR(srvToken == strToken);

    return 0;
}

/**
 * @brief 检查服务器消息，是否应该处理
 * @param unLinkId
 * @param packet
 * @return
 */
int NFCWorldPlayerModule::OnCheckWorldServerMsg(uint64_t unLinkId, NFDataPackage &packet)
{
    if (!m_pObjPluginManager->IsInited())
    {
        NFLogError(NF_LOG_SYSTEMLOG, packet.nParam1, "World Server not inited, drop client msg:{}", packet.ToString());
        return -1;
    }

    if (m_pObjPluginManager->IsServerStopping())
    {
        NFLogError(NF_LOG_SYSTEMLOG, packet.nParam1, "World Server is Stopping, drop client msg:{}", packet.ToString());
        return -1;
    }
    return 0;
}
