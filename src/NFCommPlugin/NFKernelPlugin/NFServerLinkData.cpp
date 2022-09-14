// -------------------------------------------------------------------------
//    @FileName         :    NFCMsgModule.cpp
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFPluginModule
//
// -------------------------------------------------------------------------

#include <NFComm/NFCore/NFStringUtility.h>
#include "NFCMessageModule.h"
#include "NFComm/NFPluginModule/NFLogMgr.h"
#include "NFComm/NFPluginModule/NFCheck.h"
#include "NFComm/NFKernelMessage/storesvr_sqldata.pb.h"
#include "NFComm/NFKernelMessage/proto_kernel.pb.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmCore/NFTransBase.h"
#include "NFComm/NFPluginModule/NFConfigMgr.h"
#include "NFComm/NFPluginModule/NFCoMgr.h"
#include "NFComm/NFShmCore/NFDescStoreTrans.h"
#include "NFComm/NFPluginModule/NFMessageMgr.h"
#include "NFServerLinkData.h"

int ServerLinkData::SendMsgToServer(NFIMessageModule *pMessageModule, NF_SERVER_TYPES recvType, uint32_t busId, uint32_t nModuleId,
                                    uint32_t nMsgId, const google::protobuf::Message &xData, uint64_t param1) {
    CHECK_EXPR(pMessageModule, -1, "pMessageModule == NULL");
    NFServerConfig *pConfig = NFConfigMgr::Instance()->GetAppConfig(mServerType);
    CHECK_EXPR(pConfig, -1, "can't find server config! servertype:{}", GetServerName(mServerType));

    uint64_t destServerLinkId = GetUnLinkId(NF_IS_NONE, recvType, busId);
    uint64_t sendLinkId = param1;
    if (sendLinkId == 0) {
        sendLinkId = GetUnLinkId(NF_IS_NONE, mServerType, pConfig->mBusId);
    }

    pMessageModule->Send(m_routeData.mUnlinkId, nModuleId, nMsgId, xData, sendLinkId, destServerLinkId);
    return 0;
}

int ServerLinkData::SendMsgToServer(NFIMessageModule *pMessageModule, NF_SERVER_TYPES recvType, uint32_t nModuleId, uint32_t nMsgId,
                                    const google::protobuf::Message &xData, uint64_t param1) {
    CHECK_EXPR(pMessageModule, -1, "pMessageModule == NULL");
    NFServerConfig *pConfig = NFConfigMgr::Instance()->GetAppConfig(mServerType);
    CHECK_EXPR(pConfig, -1, "can't find server config! servertype:{}", GetServerName(mServerType));

    uint64_t destServerLinkId = GetUnLinkId(NF_IS_NONE, recvType, 0);
    uint64_t sendLinkId = param1;
    if (sendLinkId == 0) {
        sendLinkId = GetUnLinkId(NF_IS_NONE, mServerType, pConfig->mBusId);
    }

    pMessageModule->Send(m_routeData.mUnlinkId, nModuleId, nMsgId, xData, sendLinkId, destServerLinkId);
    return 0;
}

void ServerLinkData::CloseAllLink(NFIMessageModule *pMessageModule) {
    if (pMessageModule == NULL) return;

    pMessageModule->CloseLinkId(m_masterServerData.mUnlinkId);
    pMessageModule->CloseLinkId(m_routeData.mUnlinkId);
    pMessageModule->CloseLinkId(m_serverLinkId);
    for(auto iter = mLinkIdToBusIdMap.begin(); iter != mLinkIdToBusIdMap.end(); iter++)
    {
        pMessageModule->CloseLinkId(iter->first);
    }
}

int ServerLinkData::SendMsgToMasterServer(NFIMessageModule *pMessageModule, uint32_t nModuleId, uint32_t nMsgId,
                                          const google::protobuf::Message &xData, uint64_t valueId) {
    //NFLogTrace(NF_LOG_KERNEL_PLUGIN, 0, "-- begin --");
    CHECK_EXPR(pMessageModule, -1, "pMessageModule == NULL");

    pMessageModule->Send(m_masterServerData.mUnlinkId, nModuleId, nMsgId, xData, valueId);
    //NFLogTrace(NF_LOG_KERNEL_PLUGIN, 0, "-- end --");
    return 0;
}

NF_SHARE_PTR<NFServerData> ServerLinkData::GetServerByServerId(uint32_t busId) {
    return mServerMap.GetElement(busId);
}

NF_SHARE_PTR<NFServerData> ServerLinkData::GetServerByUnlinkId(uint64_t unlinkId) {
    auto iter = mLinkIdToBusIdMap.find(unlinkId);
    if (iter != mLinkIdToBusIdMap.end()) {
        return GetServerByServerId(iter->second);
    }
    return NULL;
}

uint64_t ServerLinkData::GetServerLinkId() const { return m_serverLinkId; }

NF_SHARE_PTR<NFServerData>
ServerLinkData::CreateServerByServerId(uint32_t busId, NF_SERVER_TYPES busServerType, const proto_ff::ServerInfoReport &data) {
    NF_SHARE_PTR<NFServerData> pServerData = GetServerByServerId(busId);
    if (pServerData == NULL) {
        pServerData = NF_SHARE_PTR<NFServerData>(NF_NEW NFServerData());
        mServerMap.AddElement(busId, pServerData);
        if (busServerType > 0 && busServerType < NF_ST_MAX)
        {
            mServerList[busServerType].push_back(pServerData);
            mServerListMap[busServerType].AddElement(busId, pServerData);
        }
        else
        {
            NFLogError(NF_LOG_SYSTEMLOG, 0, "CreateServerByServerId Error, servertype:{}", busServerType);
        }
    }

    pServerData->mServerInfo = data;

    if (busServerType == NF_ST_STORE_SERVER)
    {
        for(int i = 0; i < (int)pServerData->mServerInfo.db_name_list_size(); i++)
        {
            std::string dbName = pServerData->mServerInfo.db_name_list(i);
            auto pServerMap = mDBStoreServerMap.GetElement(dbName);
            if (!pServerMap)
            {
                pServerMap = NF_SHARE_PTR<NFConsistentHashMapEx<uint32_t, NFServerData>>(NF_NEW NFConsistentHashMapEx<uint32_t, NFServerData>());
                mDBStoreServerMap.AddElement(dbName, pServerMap);
            }

            if (pServerMap->GetElement(busId) == NULL)
            {
                pServerMap->AddElement(busId, pServerData);
            }
        }
    }

    return pServerData;
}

void ServerLinkData::CloseServer(NF_SERVER_TYPES busServerType, uint32_t busId, uint64_t usLinkId)
{
    DelServerLink(usLinkId);
    NF_SHARE_PTR<NFServerData> pServerData = GetServerByServerId(busId);
    if (pServerData)
    {
        if (busServerType > 0 && busServerType < NF_ST_MAX)
        {
            for(auto iter = mServerList[busServerType].begin(); iter != mServerList[busServerType].end(); iter++)
            {
                if (*iter == pServerData)
                {
                    mServerList[busServerType].erase(iter);
                    break;
                }
            }
            mServerListMap[busServerType].RemoveElement(busId);
        }

        if (pServerData->mServerInfo.server_type() == NF_ST_STORE_SERVER)
        {
            auto pServerMap = mDBStoreServerMap.First();
            while(pServerMap)
            {
                pServerMap->RemoveElement(busId);
                pServerMap = mDBStoreServerMap.Next();
            }
        }

        mServerMap.RemoveElement(busId);
    }
}

void ServerLinkData::CreateLinkToServer(uint32_t busId, uint64_t linkId) {
    mLinkIdToBusIdMap.emplace(linkId, busId);
}

void ServerLinkData::DelServerLink(uint64_t linkId) {
    NF_SHARE_PTR<NFServerData> pServerData = GetServerByUnlinkId(linkId);
    if (pServerData)
    {
        pServerData->mUnlinkId = 0;
    }
    mLinkIdToBusIdMap.erase(linkId);
}

void ServerLinkData::SetServerLinkId(uint64_t linkId) { m_serverLinkId = linkId; }

std::vector<NF_SHARE_PTR<NFServerData>> ServerLinkData::GetServerByServerType(NF_SERVER_TYPES serverTypes) {
    return mServerList[serverTypes];
}

NF_SHARE_PTR<NFServerData> ServerLinkData::GetFirstServerByServerType(NF_SERVER_TYPES serverTypes)
{
    if (!mServerList[serverTypes].empty())
    {
        return mServerList[serverTypes][0];
    }

    return NULL;
}

NF_SHARE_PTR<NFServerData> ServerLinkData::GetRandomServerByServerType(NF_SERVER_TYPES serverTypes)
{
    auto pServer =   mServerListMap[serverTypes].GetElementBySuitRandom();
    if (pServer)
    {
        NFLogTrace(NF_LOG_SYSTEMLOG, 0, "GetRandomServerByServerType result:{}", pServer->mServerInfo.server_name());
    }
    return pServer;
}

NF_SHARE_PTR<NFServerData> ServerLinkData::GetSuitServerByServerType(NF_SERVER_TYPES serverTypes, uint64_t value)
{
    auto pServer =  mServerListMap[serverTypes].GetElementBySuit(value);
    if (pServer)
    {
        NFLogTrace(NF_LOG_SYSTEMLOG, 0, "GetSuitServerByServerType value:{} result:{}", value, pServer->mServerInfo.server_name());
    }
    return pServer;
}

NF_SHARE_PTR<NFServerData> ServerLinkData::GetSuitServerByServerType(NF_SERVER_TYPES serverTypes, const std::string& value)
{
    auto pServer = mServerListMap[serverTypes].GetElementBySuit(value);
    if (pServer)
    {
        NFLogTrace(NF_LOG_SYSTEMLOG, 0, "GetSuitServerByServerType value:{} result:{}", value, pServer->mServerInfo.server_name());
    }
    return pServer;
}

std::vector<NF_SHARE_PTR<NFServerData>> ServerLinkData::GetAllServer() {
    std::vector<NF_SHARE_PTR<NFServerData>> vec;
    for(int i = 0; i < (int)mServerList.size(); i++)
    {
        for(int j = 0; j < (int)mServerList[i].size(); j++)
        {
            vec.push_back(mServerList[i][j]);
        }
    }
    return vec;
}

std::vector<NF_SHARE_PTR<NFServerData>> ServerLinkData::GetAllServer(NF_SERVER_TYPES serverTypes) {
    return mServerList[serverTypes];
}

std::vector<std::string> ServerLinkData::GetDBNames()
{
    std::vector<std::string> vec;
    for(auto iter = mDBStoreServerMap.Begin(); iter != mDBStoreServerMap.End(); iter++)
    {
        vec.push_back(iter->first);
    }

    return vec;
}

int ServerLinkData::SendMsgByBusId(NFIMessageModule *pMessageModule, uint32_t busId, uint32_t nModuleId, uint32_t nMsgId, const char *msg,
                                   uint32_t nLen, uint64_t param1, uint64_t param2) {
    CHECK_EXPR(pMessageModule, -1, "pMessageModule == NULL");
    NF_SHARE_PTR<NFServerData> pServerData = GetServerByServerId(busId);
    CHECK_EXPR(pServerData, -1, "pServerData == NULL, busId:{}", busId);

    pMessageModule->Send(pServerData->mUnlinkId, nModuleId, nMsgId, msg, nLen, param1, param2);
    return 0;
}

int ServerLinkData::SendMsgByBusId(NFIMessageModule *pMessageModule, uint32_t busId, uint32_t nModuleId, uint32_t nMsgId,
                                   const google::protobuf::Message &xData, uint64_t param1, uint64_t param2) {
    CHECK_EXPR(pMessageModule, -1, "pMessageModule == NULL");
    NF_SHARE_PTR<NFServerData> pServerData = GetServerByServerId(busId);
    CHECK_EXPR(pServerData, -1, "pServerData == NULL, busId:{}", busId);

    pMessageModule->Send(pServerData->mUnlinkId, nModuleId, nMsgId, xData, param1, param2);
    return 0;
}

