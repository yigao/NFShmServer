// -------------------------------------------------------------------------
//    @FileName         :    NFCProxyClientModule.cpp
//    @Author           :    Gao.Yi
//    @Date             :   2022-09-18
//    @Email			:    445267987@qq.com
//    @Module           :    NFCProxyClientModule
//
// -------------------------------------------------------------------------

#include <NFComm/NFCore/NFTime.h>
#include <NFComm/NFPluginModule/NFCheck.h>
#include "NFProxyClientModule.h"
#include "NFComm/NFPluginModule/NFIMessageModule.h"
#include "NFComm/NFPluginModule/NFIConfigModule.h"

NFCProxyClientModule::NFCProxyClientModule(NFIPluginManager *p) : NFIProxyClientModule(p)
{
    m_proxyClientLinkId = 0;
}

NFCProxyClientModule::~NFCProxyClientModule()
{
}

bool NFCProxyClientModule::Awake()
{
    NFServerConfig *pConfig = FindModule<NFIConfigModule>()->GetAppConfig(NF_ST_PROXY_SERVER);
    if (pConfig)
    {
        if (!m_pObjPluginManager->IsLoadAllServer())
        {
            if (pConfig->ServerType != NF_ST_PROXY_SERVER)
            {
                NFLogError(NF_LOG_SYSTEMLOG, 0, "server config error, server id not match the server type!");
                exit(0);
            }
        }

        std::string externUrl = NF_FORMAT("tcp://{}:{}", pConfig->ExternalServerIp, pConfig->ExternalServerPort);
        uint64_t extern_unlinkId = FindModule<NFIMessageModule>()->BindServer(NF_ST_PROXY_SERVER, externUrl, pConfig->NetThreadNum,
                                                                              pConfig->MaxConnectNum,
                                                                              pConfig->ParseType, pConfig->Security);
        if (extern_unlinkId > 0)
        {
            /*
            注册服务器事件
            */
            m_proxyClientLinkId = extern_unlinkId;
            FindModule<NFIMessageModule>()->SetClientLinkId(NF_ST_PROXY_SERVER, extern_unlinkId);
            NFLogInfo(NF_LOG_SYSTEMLOG, 0, "proxy client listen success, serverId:{}, ip:{}, port:{}",
                      pConfig->ServerId, pConfig->ExternalServerIp, pConfig->ExternalServerPort);
        }
        else
        {
            NFLogInfo(NF_LOG_SYSTEMLOG, 0, "proxy client listen failed!, serverId:{}, ip:{}, port:{}",
                      pConfig->ServerId, pConfig->ExternalServerIp, pConfig->ExternalServerPort);
            return false;
        }
    }
    else
    {
        NFLogError(NF_LOG_SYSTEMLOG, 0, "I Can't get the Proxy Server config!");
        return false;
    }

    return true;
}

bool NFCProxyClientModule::Init()
{
    return true;
}

bool NFCProxyClientModule::Execute()
{
    return true;
}

bool NFCProxyClientModule::OnDynamicPlugin()
{
    FindModule<NFIMessageModule>()->CloseLinkId(m_proxyClientLinkId);
    return true;
}