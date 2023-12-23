// -------------------------------------------------------------------------
//    @FileName         :    NFCMsgModule.cpp
//    @Author           :    Gao.Yi
//    @Date             :   2022-09-18
//    @Email			:    445267987@qq.com
//    @Module           :    NFPluginModule
//
// -------------------------------------------------------------------------

#include <NFComm/NFCore/NFStringUtility.h>
#include "NFComm/NFPluginModule/NFLogMgr.h"
#include "NFComm/NFPluginModule/NFCheck.h"
#include "NFComm/NFKernelMessage/storesvr_sqldata.pb.h"
#include "NFComm/NFKernelMessage/proto_kernel.pb.h"
#include "NFComm/NFPluginModule/NFIMessageModule.h"
#include "NFServerLinkData.h"

void ServerLinkData::CloseAllLink(NFIMessageModule* pMessageModule)
{
    if (pMessageModule == NULL) { return; }
    
    pMessageModule->CloseLinkId(m_masterServerData.mUnlinkId);
    pMessageModule->CloseLinkId(m_routeData.mUnlinkId);
    pMessageModule->CloseLinkId(m_serverLinkId);
    for (auto iter = mLinkIdToBusIdMap.begin(); iter != mLinkIdToBusIdMap.end(); iter++)
    {
        pMessageModule->CloseLinkId(iter->first);
    }
}

int ServerLinkData::SendMsgToMasterServer(NFIMessageModule* pMessageModule, uint32_t nModuleId, uint32_t nMsgId,
                                          const google::protobuf::Message& xData, uint64_t valueId)
{
    //NFLogTrace(NF_LOG_SYSTEMLOG, 0, "--- begin -- ");
    CHECK_EXPR(pMessageModule, -1, "pMessageModule == NULL");
    
    pMessageModule->Send(m_masterServerData.mUnlinkId, nModuleId, nMsgId, xData, valueId);
    //NFLogTrace(NF_LOG_SYSTEMLOG, 0, "--- end -- ");
    return 0;
}

NF_SHARE_PTR<NFServerData> ServerLinkData::GetServerByServerId(uint32_t busId)
{
    return mServerMap.GetElement(busId);
}

NF_SHARE_PTR<NFServerData> ServerLinkData::GetServerByUnlinkId(uint64_t unlinkId)
{
    auto iter = mLinkIdToBusIdMap.find(unlinkId);
    if (iter != mLinkIdToBusIdMap.end())
    {
        return GetServerByServerId(iter->second);
    }
    return NULL;
}

uint64_t ServerLinkData::GetServerLinkId() const { return m_serverLinkId; }

NF_SHARE_PTR<NFServerData>
ServerLinkData::CreateServerByServerId(uint32_t busId, NF_SERVER_TYPES busServerType, const proto_ff::ServerInfoReport& data)
{
    NF_SHARE_PTR<NFServerData> pServerData = GetServerByServerId(busId);
    if (pServerData == NULL)
    {
        pServerData = NF_SHARE_PTR<NFServerData>(NF_NEW NFServerData());
        mServerMap.AddElement(busId, pServerData);
        if (busServerType > 0 && busServerType < NF_ST_MAX)
        {
            mServerList[busServerType].push_back(pServerData);
            mServerListMap[busServerType].AddElement(busId, pServerData);
            if (data.is_cross_server())
            {
                mCrossServerListMap[busServerType].AddElement(busId, pServerData);
            }
            else
            {
                mNoCrossServerListMap[busServerType].AddElement(busId, pServerData);
            }
        }
        else
        {
            NFLogError(NF_LOG_SYSTEMLOG, 0, "CreateServerByServerId Error, servertype:{}", busServerType);
        }
    }
    
    pServerData->mServerInfo = data;
    
    if (busServerType == NF_ST_STORE_SERVER)
    {
        for (int i = 0; i < (int)pServerData->mServerInfo.db_name_list_size(); i++)
        {
            std::string dbName = pServerData->mServerInfo.db_name_list(i);
            auto pServerMap = mDBStoreServerMap.GetElement(dbName);
            if (!pServerMap)
            {
                pServerMap = NF_SHARE_PTR<NFConsistentCommMapEx<uint32_t, NFServerData>>(NF_NEW NFConsistentCommMapEx<uint32_t, NFServerData>());
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
            for (auto iter = mServerList[busServerType].begin(); iter != mServerList[busServerType].end(); iter++)
            {
                if (*iter == pServerData)
                {
                    mServerList[busServerType].erase(iter);
                    break;
                }
            }
            mServerListMap[busServerType].RemoveElement(busId);
            mCrossServerListMap[busServerType].RemoveElement(busId);
            mNoCrossServerListMap[busServerType].RemoveElement(busId);
        }
        
        if (pServerData->mServerInfo.server_type() == NF_ST_STORE_SERVER)
        {
            auto pServerMap = mDBStoreServerMap.First();
            while (pServerMap)
            {
                pServerMap->RemoveElement(busId);
                pServerMap = mDBStoreServerMap.Next();
            }
        }
        
        mServerMap.RemoveElement(busId);
    }
}

void ServerLinkData::CreateLinkToServer(uint32_t busId, uint64_t linkId)
{
    mLinkIdToBusIdMap.emplace(linkId, busId);
}

void ServerLinkData::DelServerLink(uint64_t linkId)
{
    NF_SHARE_PTR<NFServerData> pServerData = GetServerByUnlinkId(linkId);
    if (pServerData)
    {
        pServerData->mUnlinkId = 0;
    }
    mLinkIdToBusIdMap.erase(linkId);
}

void ServerLinkData::SetServerLinkId(uint64_t linkId) { m_serverLinkId = linkId; }

uint64_t ServerLinkData::GetClientLinkId() const
{
    return m_clientLinkId;
}

void ServerLinkData::SetClientLinkId(uint64_t linkId)
{
    m_clientLinkId = linkId;
}

std::vector<NF_SHARE_PTR<NFServerData>> ServerLinkData::GetServerByServerType(NF_SERVER_TYPES serverTypes)
{
    return mServerList[serverTypes];
}

NF_SHARE_PTR<NFServerData> ServerLinkData::GetFirstServerByServerType(NF_SERVER_TYPES serverTypes)
{
    return mServerListMap[serverTypes].First();
}

NF_SHARE_PTR<NFServerData> ServerLinkData::GetFirstServerByServerType(NF_SERVER_TYPES serverTypes, bool crossServer)
{
    if (crossServer)
    {
        return mCrossServerListMap[serverTypes].First();
    }
    else
    {
        return mNoCrossServerListMap[serverTypes].First();
    }
}

NF_SHARE_PTR<NFServerData> ServerLinkData::GetRandomServerByServerType(NF_SERVER_TYPES serverTypes)
{
    if (mServerListMap[serverTypes].Count() == 1)
    {
        auto pServer = mServerListMap[serverTypes].First();
        if (pServer)
        {
            NFLogTrace(NF_LOG_SYSTEMLOG, 0, "GetRandomServerByServerType result:{}", pServer->mServerInfo.server_name());
        }
        return pServer;
    }
    
    auto pServer = mServerListMap[serverTypes].GetElementBySuitRandom();
    if (pServer)
    {
        NFLogTrace(NF_LOG_SYSTEMLOG, 0, "GetRandomServerByServerType result:{}", pServer->mServerInfo.server_name());
    }
    return pServer;
}

NF_SHARE_PTR<NFServerData> ServerLinkData::GetRandomServerByServerType(NF_SERVER_TYPES serverTypes, bool crossServer)
{
    if (crossServer)
    {
        if (mCrossServerListMap[serverTypes].Count() == 1)
        {
            auto pServer = mCrossServerListMap[serverTypes].First();
            if (pServer)
            {
                NFLogTrace(NF_LOG_SYSTEMLOG, 0, "GetRandomServerByServerType mCrossServerListMap result:{}", pServer->mServerInfo.server_name());
            }
            return pServer;
        }
        
        auto pServer = mCrossServerListMap[serverTypes].GetElementBySuitRandom();
        if (pServer)
        {
            NFLogTrace(NF_LOG_SYSTEMLOG, 0, "GetRandomServerByServerType mCrossServerListMap result:{}", pServer->mServerInfo.server_name());
        }
        return pServer;
    }
    else
    {
        if (mNoCrossServerListMap[serverTypes].Count() == 1)
        {
            auto pServer = mNoCrossServerListMap[serverTypes].First();
            if (pServer)
            {
                NFLogTrace(NF_LOG_SYSTEMLOG, 0, "GetRandomServerByServerType mNoCrossServerListMap result:{}", pServer->mServerInfo.server_name());
            }
            return pServer;
        }
        
        auto pServer = mNoCrossServerListMap[serverTypes].GetElementBySuitRandom();
        if (pServer)
        {
            NFLogTrace(NF_LOG_SYSTEMLOG, 0, "GetRandomServerByServerType mNoCrossServerListMap result:{}", pServer->mServerInfo.server_name());
        }
        return pServer;
    }
}

NF_SHARE_PTR<NFServerData> ServerLinkData::GetSuitServerByServerType(NF_SERVER_TYPES serverTypes, uint64_t value)
{
    if (mServerListMap[serverTypes].Count() == 1)
    {
        auto pServer = mServerListMap[serverTypes].First();
        if (pServer)
        {
            NFLogTrace(NF_LOG_SYSTEMLOG, 0, "GetSuitServerByServerType result:{}", pServer->mServerInfo.server_name());
        }
        return pServer;
    }
    
    auto pServer = mServerListMap[serverTypes].GetElementBySuit(value);
    if (pServer)
    {
        NFLogTrace(NF_LOG_SYSTEMLOG, 0, "GetSuitServerByServerType value:{} result:{}", value, pServer->mServerInfo.server_name());
    }
    return pServer;
}

NF_SHARE_PTR<NFServerData> ServerLinkData::GetSuitServerByServerType(NF_SERVER_TYPES serverTypes, uint64_t value, bool crossServer)
{
    if (crossServer)
    {
        if (mCrossServerListMap[serverTypes].Count() == 1)
        {
            auto pServer = mCrossServerListMap[serverTypes].First();
            if (pServer)
            {
                NFLogTrace(NF_LOG_SYSTEMLOG, 0, "GetSuitServerByServerType mCrossServerListMap result:{}", pServer->mServerInfo.server_name());
            }
            return pServer;
        }
        
        auto pServer = mCrossServerListMap[serverTypes].GetElementBySuit(value);
        if (pServer)
        {
            NFLogTrace(NF_LOG_SYSTEMLOG, 0, "GetSuitServerByServerType mCrossServerListMap value:{} result:{}", value, pServer->mServerInfo.server_name());
        }
        return pServer;
    }
    else
    {
        if (mNoCrossServerListMap[serverTypes].Count() == 1)
        {
            auto pServer = mNoCrossServerListMap[serverTypes].First();
            if (pServer)
            {
                NFLogTrace(NF_LOG_SYSTEMLOG, 0, "GetSuitServerByServerType mNoCrossServerListMap result:{}", pServer->mServerInfo.server_name());
            }
            return pServer;
        }
        
        auto pServer = mNoCrossServerListMap[serverTypes].GetElementBySuit(value);
        if (pServer)
        {
            NFLogTrace(NF_LOG_SYSTEMLOG, 0, "GetSuitServerByServerType mNoCrossServerListMap value:{} result:{}", value, pServer->mServerInfo.server_name());
        }
        return pServer;
    }
}

NF_SHARE_PTR<NFServerData> ServerLinkData::GetFirstDbServer(const std::string& dbName)
{
    auto pServerMap = mDBStoreServerMap.GetElement(dbName);
    if (pServerMap)
    {
        return pServerMap->First();
    }
    return nullptr;
}

NF_SHARE_PTR<NFServerData> ServerLinkData::GeRandomDbServer(const std::string& dbName)
{
    auto pServerMap = mDBStoreServerMap.GetElement(dbName);
    if (pServerMap)
    {
        return pServerMap->GetElementBySuitRandom();
    }
    return nullptr;
}

NF_SHARE_PTR<NFServerData> ServerLinkData::GetSuitDbServer(const std::string&dbName, uint64_t value)
{
    auto pServerMap = mDBStoreServerMap.GetElement(dbName);
    if (pServerMap)
    {
        return pServerMap->GetElementBySuit(value);
    }
    return nullptr;
}

NF_SHARE_PTR<NFServerData> ServerLinkData::GetSuitServerByServerType(NF_SERVER_TYPES serverTypes, const std::string& value)
{
    if (mServerListMap[serverTypes].Count() == 1)
    {
        auto pServer = mServerListMap[serverTypes].First();
        if (pServer)
        {
            NFLogTrace(NF_LOG_SYSTEMLOG, 0, "GetSuitServerByServerType result:{}", pServer->mServerInfo.server_name());
        }
        return pServer;
    }
    
    auto pServer = mServerListMap[serverTypes].GetElementBySuit(value);
    if (pServer)
    {
        NFLogTrace(NF_LOG_SYSTEMLOG, 0, "GetSuitServerByServerType value:{} result:{}", value, pServer->mServerInfo.server_name());
    }
    return pServer;
}

NF_SHARE_PTR<NFServerData> ServerLinkData::GetSuitServerByServerType(NF_SERVER_TYPES serverTypes, const std::string& value, bool crossServer)
{
    if (crossServer)
    {
        if (mCrossServerListMap[serverTypes].Count() == 1)
        {
            auto pServer = mCrossServerListMap[serverTypes].First();
            if (pServer)
            {
                NFLogTrace(NF_LOG_SYSTEMLOG, 0, "GetSuitServerByServerType mCrossServerListMap result:{}", pServer->mServerInfo.server_name());
            }
            return pServer;
        }
        
        auto pServer = mCrossServerListMap[serverTypes].GetElementBySuit(value);
        if (pServer)
        {
            NFLogTrace(NF_LOG_SYSTEMLOG, 0, "GetSuitServerByServerType value:{} mCrossServerListMap result:{}", value, pServer->mServerInfo.server_name());
        }
        return pServer;
    }
    else
    {
        if (mNoCrossServerListMap[serverTypes].Count() == 1)
        {
            auto pServer = mNoCrossServerListMap[serverTypes].First();
            if (pServer)
            {
                NFLogTrace(NF_LOG_SYSTEMLOG, 0, "GetSuitServerByServerType mNoCrossServerListMap result:{}", pServer->mServerInfo.server_name());
            }
            return pServer;
        }
        
        auto pServer = mNoCrossServerListMap[serverTypes].GetElementBySuit(value);
        if (pServer)
        {
            NFLogTrace(NF_LOG_SYSTEMLOG, 0, "GetSuitServerByServerType mNoCrossServerListMap value:{} result:{}", value, pServer->mServerInfo.server_name());
        }
        return pServer;
    }
}

std::vector<NF_SHARE_PTR<NFServerData>> ServerLinkData::GetAllServer()
{
    std::vector<NF_SHARE_PTR<NFServerData>> vec;
    for (int i = 0; i < (int)mServerList.size(); i++)
    {
        for (int j = 0; j < (int)mServerList[i].size(); j++)
        {
            vec.push_back(mServerList[i][j]);
        }
    }
    return vec;
}

std::vector<NF_SHARE_PTR<NFServerData>> ServerLinkData::GetAllServer(NF_SERVER_TYPES serverTypes)
{
    return mServerList[serverTypes];
}

NF_SHARE_PTR<NFServerData> ServerLinkData::GetSuitDbServer(const std::string&dbName, const std::string& value)
{
    auto pServerMap = mDBStoreServerMap.GetElement(dbName);
    if (pServerMap)
    {
        return pServerMap->GetElementBySuit(value);
    }
    return nullptr;
}

std::vector<std::string> ServerLinkData::GetDBNames()
{
    std::vector<std::string> vec;
    for (auto iter = mDBStoreServerMap.Begin(); iter != mDBStoreServerMap.End(); iter++)
    {
        vec.push_back(iter->first);
    }
    
    return vec;
}

std::vector<NF_SHARE_PTR<NFServerData>> ServerLinkData::GetAllServer(NF_SERVER_TYPES serverTypes, bool isCrossServer)
{
    std::vector<NF_SHARE_PTR<NFServerData>> vec;
    for (auto iter = mServerList[serverTypes].begin(); iter != mServerList[serverTypes].end(); iter++)
    {
        NF_SHARE_PTR<NFServerData> pData = *iter;
        if (pData && pData->mServerInfo.is_cross_server() == isCrossServer)
        {
            vec.push_back(pData);
        }
    }
    return vec;
}