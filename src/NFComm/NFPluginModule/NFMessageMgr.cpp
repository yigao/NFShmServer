// -------------------------------------------------------------------------
//    @FileName         :    NFMessageMgr.cpp
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFMessageMgr.cpp
//
// -------------------------------------------------------------------------

#include "NFMessageMgr.h"
#include "NFCheck.h"

NFMessageMgr::NFMessageMgr()
{
	m_pMessageModule = NULL;
}

NFMessageMgr::~NFMessageMgr()
{

}

bool NFMessageMgr::Init(NFIMessageModule *pMessageModule)
{
    m_pMessageModule = pMessageModule;
    return true;
}

void NFMessageMgr::UnInit()
{
    m_pMessageModule = NULL;
}

int64_t NFMessageMgr::BindServer(NF_SERVER_TYPES eServerType, const string &url, uint32_t netThreadNum, uint32_t nMaxConnectNum, uint32_t nPacketParseType)
{
    NF_ASSERT(m_pMessageModule);
    return m_pMessageModule->BindServer(eServerType, url, netThreadNum, nMaxConnectNum, nPacketParseType);
}

int64_t NFMessageMgr::ConnectServer(NF_SERVER_TYPES eServerType, const string &url, uint32_t nPacketParseType)
{
    NF_ASSERT(m_pMessageModule);
    return m_pMessageModule->ConnectServer(eServerType, url, nPacketParseType);
}

int NFMessageMgr::ResumeConnect(NF_SERVER_TYPES eServerType)
{
    NF_ASSERT(m_pMessageModule);
    return m_pMessageModule->ResumeConnect(eServerType);
}

std::string NFMessageMgr::GetLinkIp(uint64_t usLinkId)
{
    NF_ASSERT(m_pMessageModule);
    return m_pMessageModule->GetLinkIp(usLinkId);
}

void NFMessageMgr::CloseLinkId(uint64_t usLinkId)
{
    NF_ASSERT(m_pMessageModule);
    m_pMessageModule->CloseLinkId(usLinkId);
}

void NFMessageMgr::CloseServer(NF_SERVER_TYPES eServerType, NF_SERVER_TYPES destServer, uint32_t busId, uint64_t usLinkId)
{
    NF_ASSERT(m_pMessageModule);
    m_pMessageModule->CloseServer(eServerType, destServer, busId, usLinkId);
}

void NFMessageMgr::Send(uint64_t usLinkId, uint32_t nMsgID, const string &strData, uint64_t nSendValue, uint64_t nSendId)
{
    NF_ASSERT(m_pMessageModule);
    m_pMessageModule->Send(usLinkId, nMsgID, strData, nSendValue, nSendId);
}

void NFMessageMgr::Send(uint64_t usLinkId, uint32_t nMsgID, const char *msg, uint32_t nLen, uint64_t nSendValue, uint64_t nSendId)
{
    NF_ASSERT(m_pMessageModule);
    m_pMessageModule->Send(usLinkId, nMsgID, msg, nLen, nSendValue, nSendId);
}

void NFMessageMgr::Send(uint64_t usLinkId, uint32_t nMsgID, const google::protobuf::Message &xData, uint64_t nSendValue, uint64_t nSendId)
{
    NF_ASSERT(m_pMessageModule);
    m_pMessageModule->Send(usLinkId, nMsgID, xData, nSendValue, nSendId);
}

void NFMessageMgr::Send(uint64_t usLinkId, uint16_t nMainMsgID, uint16_t nSubMsgID, const string &strData, uint64_t nSendValue, uint64_t nSendId)
{
    NF_ASSERT(m_pMessageModule);
    m_pMessageModule->Send(usLinkId, nMainMsgID, nSubMsgID, strData, nSendValue, nSendId);
}

void NFMessageMgr::Send(uint64_t usLinkId, uint16_t nMainMsgID, uint16_t nSubMsgID, const char *msg, uint32_t nLen, uint64_t nSendValue, uint64_t nSendId)
{
    NF_ASSERT(m_pMessageModule);
    m_pMessageModule->Send(usLinkId, nMainMsgID, nSubMsgID, msg, nLen, nSendValue,  nSendId);
}

void NFMessageMgr::Send(uint64_t usLinkId, uint16_t nMainMsgID, uint16_t nSubMsgID, const google::protobuf::Message &xData, uint64_t nSendValue, uint64_t nSendId)
{
    NF_ASSERT(m_pMessageModule);
    m_pMessageModule->Send(usLinkId, nMainMsgID, nSubMsgID, xData, nSendValue, nSendId);
}

void NFMessageMgr::SendTrans(uint64_t usLinkId, uint32_t nMsgID, const google::protobuf::Message &xData, uint64_t nSendValue, uint64_t nSendId, uint32_t req_trans_id, uint32_t rsp_trans_id)
{
    NF_ASSERT(m_pMessageModule);
    m_pMessageModule->SendTrans(usLinkId, nMsgID, xData, nSendValue, nSendId, req_trans_id, rsp_trans_id);
}

void NFMessageMgr::SendStore(uint64_t usLinkId, uint32_t cmd, uint32_t table_id, uint64_t sendLinkId, uint64_t destLinkId, const string &dbname, const string &table_name,
                             const google::protobuf::Message &xData, int trans_id, uint32_t seq, uint64_t mod_key, uint8_t packet_type, const std::string& cls_name)
{
    NF_ASSERT(m_pMessageModule);
    m_pMessageModule->SendStore(usLinkId, cmd, table_id, sendLinkId, destLinkId, dbname, table_name, xData, trans_id, seq, mod_key, packet_type, cls_name);
}

void NFMessageMgr::SendStore(uint64_t usLinkId, uint32_t cmd, uint32_t table_id, uint64_t sendLinkId, uint64_t destLinkId, const string &dbname, const string &table_name,
                             std::vector<storesvr_sqldata::storesvr_vk> vk_list, const string &where_addtional_conds, int trans_id, uint32_t seq, uint64_t mod_key, uint8_t packet_type, const std::string& cls_name)
{
    NF_ASSERT(m_pMessageModule);
    m_pMessageModule->SendStore(usLinkId, cmd, table_id, sendLinkId, destLinkId, dbname, table_name, vk_list, where_addtional_conds, trans_id, seq, mod_key, packet_type, cls_name);
}

int NFMessageMgr::SendMsgByBusId(NF_SERVER_TYPES eType, uint32_t busId, uint32_t nMsgId, const google::protobuf::Message &xData, uint64_t valueId)
{
    NF_ASSERT(m_pMessageModule);
    return m_pMessageModule->SendMsgByBusId(eType, busId, nMsgId, xData, valueId);
}

int NFMessageMgr::SendMsgByBusId(NF_SERVER_TYPES eType, uint32_t busId, uint16_t nMainMsgId, uint16_t nSubMsgId, const google::protobuf::Message &xData, uint64_t valueId)
{
    NF_ASSERT(m_pMessageModule);
    return m_pMessageModule->SendMsgByBusId(eType, busId, nMainMsgId, nSubMsgId, xData, valueId);
}

int NFMessageMgr::SendMsgByBusId(NF_SERVER_TYPES eType, uint32_t busId, uint32_t nMsgId, const char *msg, uint32_t nLen, uint64_t valueId)
{
    NF_ASSERT(m_pMessageModule);
    return m_pMessageModule->SendMsgByBusId(eType, busId, nMsgId, msg, nLen, valueId);
}

int NFMessageMgr::SendMsgByBusId(NF_SERVER_TYPES eType, uint32_t busId, uint16_t nMainMsgId, uint16_t nSubMsgId, const char *msg, uint32_t nLen, uint64_t valueId)
{
    NF_ASSERT(m_pMessageModule);
    return m_pMessageModule->SendMsgByBusId(eType, busId, nMainMsgId, nSubMsgId, msg, nLen, valueId);
}

int NFMessageMgr::SendProxyMsgByBusId(NF_SERVER_TYPES eType, uint32_t busId, uint32_t nMsgId, const google::protobuf::Message &xData, uint64_t valueId)
{
    NF_ASSERT(m_pMessageModule);
    return m_pMessageModule->SendProxyMsgByBusId(eType, busId, nMsgId, xData, valueId);
}

int NFMessageMgr::SendProxyMsgByBusId(NF_SERVER_TYPES eType, uint32_t busId, uint16_t nMainMsgId, uint16_t nSubMsgId, const google::protobuf::Message &xData, uint64_t valueId)
{
    NF_ASSERT(m_pMessageModule);
    return m_pMessageModule->SendProxyMsgByBusId(eType, busId, nMainMsgId, nSubMsgId, xData, valueId);
}

int NFMessageMgr::SendProxyMsgByBusId(NF_SERVER_TYPES eType, uint32_t busId, uint32_t nMsgId, const char *msg, uint32_t nLen, uint64_t valueId)
{
    NF_ASSERT(m_pMessageModule);
    return m_pMessageModule->SendProxyMsgByBusId(eType, busId, nMsgId, msg, nLen, valueId);
}

int NFMessageMgr::SendProxyMsgByBusId(NF_SERVER_TYPES eType, uint32_t busId, uint16_t nMainMsgId, uint16_t nSubMsgId, const char *msg, uint32_t nLen, uint64_t valueId)
{
    NF_ASSERT(m_pMessageModule);
    return m_pMessageModule->SendProxyMsgByBusId(eType, busId, nMainMsgId, nSubMsgId, msg, nLen, valueId);
}

int NFMessageMgr::SendMsgToProxyServer(NF_SERVER_TYPES eType, uint32_t busId, uint32_t nMsgId, const google::protobuf::Message &xData, uint64_t valueId)
{
    NF_ASSERT(m_pMessageModule);
    return m_pMessageModule->SendMsgToProxyServer(eType, busId, nMsgId, xData, valueId);
}

int NFMessageMgr::SendMsgToProxyServer(NF_SERVER_TYPES eType, uint32_t busId, uint16_t nMainMsgId, uint16_t nSubMsgId, const google::protobuf::Message &xData, uint64_t valueId)
{
    NF_ASSERT(m_pMessageModule);
    return m_pMessageModule->SendMsgToProxyServer(eType, busId, nMainMsgId, nSubMsgId, xData, valueId);
}

int NFMessageMgr::SendMsgToProxyServer(NF_SERVER_TYPES eType, uint32_t busId, uint32_t nMsgId, const char *msg, uint32_t nLen, uint64_t valueId)
{
    NF_ASSERT(m_pMessageModule);
    return m_pMessageModule->SendMsgToProxyServer(eType, busId, nMsgId, msg, nLen, valueId);
}

int NFMessageMgr::SendMsgToProxyServer(NF_SERVER_TYPES eType, uint32_t busId, uint16_t nMainMsgId, uint16_t nSubMsgId, const char *msg, uint32_t nLen, uint64_t valueId)
{
    NF_ASSERT(m_pMessageModule);
    return m_pMessageModule->SendMsgToProxyServer(eType, busId, nMainMsgId, nSubMsgId, msg, nLen, valueId);
}

int NFMessageMgr::BroadMsgToProxyServer(NF_SERVER_TYPES eType, uint32_t nMsgId, const google::protobuf::Message &xData, const std::map<uint32_t, std::vector<uint64_t>>& map)
{
    NF_ASSERT(m_pMessageModule);
    for(auto iter = map.begin(); iter != map.end(); iter++)
    {
        uint64_t proxyId = iter->first;
        proto_ff::Proto_STSBroadPlayerMsgNotify msgNotify;
        int count = 0;
        for(int i = 0; i < (int)iter->second.size(); i++)
        {
            count++;
            msgNotify.add_user_id(iter->second[i]);
            if (count >= 200)
            {
                msgNotify.set_msg_id(nMsgId);
                msgNotify.set_msg_data(xData.SerializeAsString());
                m_pMessageModule->SendMsgToProxyServer(eType, proxyId, proto_ff::NF_STS_BROAD_PLAYER_MSG_NOTIFY, msgNotify, 0);
                msgNotify.Clear();
                count = 0;
            }
            else if (i == (int)iter->second.size() - 1)
            {
                msgNotify.set_msg_id(nMsgId);
                msgNotify.set_msg_data(xData.SerializeAsString());
                m_pMessageModule->SendMsgToProxyServer(eType, proxyId, proto_ff::NF_STS_BROAD_PLAYER_MSG_NOTIFY, msgNotify, 0);
            }
        }
    }
    return 0;
}

int NFMessageMgr::BroadMsgToProxyServer(NF_SERVER_TYPES eType, uint16_t nMainMsgId, uint16_t nSubMsgId, const google::protobuf::Message &xData, const std::map<uint32_t, std::vector<uint64_t>>& map)
{
    NF_ASSERT(m_pMessageModule);
    for(auto iter = map.begin(); iter != map.end(); iter++)
    {
        uint64_t proxyId = iter->first;
        proto_ff::Proto_STSBroadPlayerMsgNotify msgNotify;
        int count = 0;
        for(int i = 0; i < (int)iter->second.size(); i++)
        {
            count++;
            msgNotify.add_user_id(iter->second[i]);
            if (count >= 200)
            {
                msgNotify.set_msg_id(MAKE_UINT32(nSubMsgId, nMainMsgId));
                msgNotify.set_msg_data(xData.SerializeAsString());
                m_pMessageModule->SendMsgToProxyServer(eType, proxyId, proto_ff::NF_STS_BROAD_PLAYER_MSG_NOTIFY, msgNotify, 0);
                msgNotify.Clear();
                count = 0;
            }
            else if (i == (int)iter->second.size() - 1)
            {
                msgNotify.set_msg_id(MAKE_UINT32(nSubMsgId, nMainMsgId));
                msgNotify.set_msg_data(xData.SerializeAsString());
                m_pMessageModule->SendMsgToProxyServer(eType, proxyId, proto_ff::NF_STS_BROAD_PLAYER_MSG_NOTIFY, msgNotify, 0);
            }
        }
    }
    return 0;
}

int NFMessageMgr::BroadMsgToProxyServer(NF_SERVER_TYPES eType, uint32_t nMsgId, const char *msg, uint32_t nLen, const std::map<uint32_t, std::vector<uint64_t>>& map)
{
    NF_ASSERT(m_pMessageModule);
    for(auto iter = map.begin(); iter != map.end(); iter++)
    {
        uint64_t proxyId = iter->first;
        proto_ff::Proto_STSBroadPlayerMsgNotify msgNotify;
        int count = 0;
        for(int i = 0; i < (int)iter->second.size(); i++)
        {
            count++;
            msgNotify.add_user_id(iter->second[i]);
            if (count >= 200)
            {
                msgNotify.set_msg_id(nMsgId);
                msgNotify.set_msg_data(msg, nLen);
                m_pMessageModule->SendMsgToProxyServer(eType, proxyId, proto_ff::NF_STS_BROAD_PLAYER_MSG_NOTIFY, msgNotify, 0);
                msgNotify.Clear();
                count = 0;
            }
            else if (i == (int)iter->second.size() - 1)
            {
                msgNotify.set_msg_id(nMsgId);
                msgNotify.set_msg_data(msg, nLen);
                m_pMessageModule->SendMsgToProxyServer(eType, proxyId, proto_ff::NF_STS_BROAD_PLAYER_MSG_NOTIFY, msgNotify, 0);
            }
        }
    }
    return 0;
}

int NFMessageMgr::BroadMsgToProxyServer(NF_SERVER_TYPES eType, uint16_t nMainMsgId, uint16_t nSubMsgId, const char *msg, uint32_t nLen, const std::map<uint32_t, std::vector<uint64_t>>& map)
{
    NF_ASSERT(m_pMessageModule);
    for(auto iter = map.begin(); iter != map.end(); iter++)
    {
        uint64_t proxyId = iter->first;
        proto_ff::Proto_STSBroadPlayerMsgNotify msgNotify;
        int count = 0;
        for(int i = 0; i < (int)iter->second.size(); i++)
        {
            count++;
            msgNotify.add_user_id(iter->second[i]);
            if (count >= 200)
            {
                msgNotify.set_msg_id(MAKE_UINT32(nSubMsgId, nMainMsgId));
                msgNotify.set_msg_data(msg, nLen);
                m_pMessageModule->SendMsgToProxyServer(eType, proxyId, proto_ff::NF_STS_BROAD_PLAYER_MSG_NOTIFY, msgNotify, 0);
                msgNotify.Clear();
                count = 0;
            }
            else if (i == (int)iter->second.size() - 1)
            {
                msgNotify.set_msg_id(MAKE_UINT32(nSubMsgId, nMainMsgId));
                msgNotify.set_msg_data(msg, nLen);
                m_pMessageModule->SendMsgToProxyServer(eType, proxyId, proto_ff::NF_STS_BROAD_PLAYER_MSG_NOTIFY, msgNotify, 0);
            }
        }
    }
    return 0;
}

int
NFMessageMgr::SendMsgToWebServer(NF_SERVER_TYPES eType, uint64_t requestId, int32_t result, const std::string& err_msg)
{
    NF_ASSERT(m_pMessageModule);
    return m_pMessageModule->SendMsgToWebServer(eType, requestId, result, err_msg);
}

int NFMessageMgr::SendMsgToWebServer(NF_SERVER_TYPES eType, uint32_t nMsgId, const google::protobuf::Message &xData, uint64_t valueId)
{
    NF_ASSERT(m_pMessageModule);
    return m_pMessageModule->SendMsgToWebServer(eType, nMsgId, xData, valueId);
}

int NFMessageMgr::SendMsgToWorldServer(NF_SERVER_TYPES eType, uint32_t nMsgId, const google::protobuf::Message &xData, uint64_t valueId)
{
    NF_ASSERT(m_pMessageModule);
    return m_pMessageModule->SendMsgToWorldServer(eType, nMsgId, xData, valueId);
}

int NFMessageMgr::SendMsgToGameServer(NF_SERVER_TYPES eType, uint32_t busId, uint32_t nMsgId, const google::protobuf::Message &xData, uint64_t valueId)
{
    NF_ASSERT(m_pMessageModule);
    return m_pMessageModule->SendMsgToGameServer(eType, busId, nMsgId, xData, valueId);
}

int NFMessageMgr::SendMsgToLoginServer(NF_SERVER_TYPES eType, uint32_t busId, uint32_t nMsgId, const google::protobuf::Message &xData, uint64_t valueId)
{
    NF_ASSERT(m_pMessageModule);
    return m_pMessageModule->SendMsgToLoginServer(eType, busId, nMsgId, xData, valueId);
}

int NFMessageMgr::SendMsgToLogicServer(NF_SERVER_TYPES eType, uint32_t busId, uint32_t nMsgId, const google::protobuf::Message &xData, uint64_t valueId)
{
    NF_ASSERT(m_pMessageModule);
    return m_pMessageModule->SendMsgToLogicServer(eType, busId, nMsgId, xData, valueId);
}

int NFMessageMgr::SendMsgToLogicServer(NF_SERVER_TYPES eType, uint32_t busId, uint32_t nMsgId, const char *msg, int msgLen, uint64_t valueId)
{
    NF_ASSERT(m_pMessageModule);
    return m_pMessageModule->SendMsgToLogicServer(eType, busId, nMsgId, msg, msgLen, valueId);
}

int NFMessageMgr::SendMsgToSuitLogicServer(NF_SERVER_TYPES eType, uint64_t userId, uint32_t nMsgId, const google::protobuf::Message &xData, bool online)
{
    NF_ASSERT(m_pMessageModule);
    return m_pMessageModule->SendMsgToSuitLogicServer(eType, userId, nMsgId, xData, online);
}

int NFMessageMgr::SendMsgToSnsServer(NF_SERVER_TYPES eType, uint32_t nMsgId, const google::protobuf::Message &xData, uint64_t valueId)
{
    NF_ASSERT(m_pMessageModule);
    return m_pMessageModule->SendMsgToSnsServer(eType, nMsgId, xData, valueId);
}

int NFMessageMgr::SendTransToWebServer(NF_SERVER_TYPES eType, uint32_t nMsgId, const google::protobuf::Message &xData, uint32_t req_trans_id, uint32_t rsp_trans_id)
{
    NF_ASSERT(m_pMessageModule);
    return m_pMessageModule->SendTransToWebServer(eType, nMsgId, xData, req_trans_id, rsp_trans_id);
}

int NFMessageMgr::SendTransToWorldServer(NF_SERVER_TYPES eType, uint32_t nMsgId, const google::protobuf::Message &xData, uint32_t req_trans_id, uint32_t rsp_trans_id)
{
    NF_ASSERT(m_pMessageModule);
    return m_pMessageModule->SendTransToWorldServer(eType, nMsgId, xData, req_trans_id, rsp_trans_id);
}

int NFMessageMgr::SendTransToLoginServer(NF_SERVER_TYPES eType, uint32_t busId, uint32_t nMsgId, const google::protobuf::Message &xData, uint32_t req_trans_id, uint32_t rsp_trans_id)
{
    NF_ASSERT(m_pMessageModule);
    return m_pMessageModule->SendTransToLoginServer(eType, busId, nMsgId, xData, req_trans_id, rsp_trans_id);
}

int NFMessageMgr::SendTransToLogicServer(NF_SERVER_TYPES eType, uint32_t busId, uint32_t nMsgId, const google::protobuf::Message &xData, uint32_t req_trans_id, uint32_t rsp_trans_id)
{
    NF_ASSERT(m_pMessageModule);
    return m_pMessageModule->SendTransToLogicServer(eType, busId, nMsgId, xData, req_trans_id, rsp_trans_id);
}

int NFMessageMgr::SendTransToSnsServer(NF_SERVER_TYPES eType, uint32_t nMsgId, const google::protobuf::Message &xData, uint32_t req_trans_id, uint32_t rsp_trans_id)
{
    NF_ASSERT(m_pMessageModule);
    return m_pMessageModule->SendTransToSnsServer(eType, nMsgId, xData, req_trans_id, rsp_trans_id);
}

int NFMessageMgr::SendTransToGameServer(NF_SERVER_TYPES eType, uint32_t nMsgId, uint32_t gameBusId, const google::protobuf::Message &xData, uint32_t req_trans_id, uint32_t rsp_trans_id)
{
    NF_ASSERT(m_pMessageModule);
    return m_pMessageModule->SendTransToGameServer(eType, nMsgId, gameBusId, xData, req_trans_id, rsp_trans_id);
}

int NFMessageMgr::SendTransToStoreServer(NF_SERVER_TYPES eType, uint32_t cmd, uint32_t table_id, const string &dbname, const string &table_name, const std::string &xData, int trans_id,
                                         uint32_t seq, uint64_t mod_key)
{
    NF_ASSERT(m_pMessageModule);
    return m_pMessageModule->SendTransToStoreServer(eType, cmd, table_id, dbname, table_name, xData, trans_id, seq, mod_key);
}

int NFMessageMgr::SendTransToStoreServer(NF_SERVER_TYPES eType, uint32_t cmd, uint32_t table_id, const string &dbname, const string &table_name, const google::protobuf::Message &xData, int trans_id,
                                         uint32_t seq, uint64_t mod_key, const std::string& cls_name)
{
    NF_ASSERT(m_pMessageModule);
    return m_pMessageModule->SendTransToStoreServer(eType, cmd, table_id, dbname, table_name, xData, trans_id, seq, mod_key, cls_name);
}

int NFMessageMgr::SendTransToStoreServer(NF_SERVER_TYPES eType, uint32_t cmd, uint32_t table_id, const string &dbname, const string &table_name, std::vector<storesvr_sqldata::storesvr_vk> vk_list,
                                         const string &where_addtional_conds, int trans_id, uint32_t seq, uint64_t mod_key, const std::string& cls_name)
{
    NF_ASSERT(m_pMessageModule);
    return m_pMessageModule->SendTransToStoreServer(eType, cmd, table_id, dbname, table_name, vk_list, where_addtional_conds, trans_id, seq, mod_key, cls_name);
}

int NFMessageMgr::SendTransToStoreServer(NF_SERVER_TYPES eType, uint32_t cmd, uint32_t table_id, const string &dbname, const string &table_name, const google::protobuf::Message &xData, std::vector<storesvr_sqldata::storesvr_vk> vk_list,
                                         const string &where_addtional_conds, int trans_id, uint32_t seq, uint64_t mod_key, const std::string& cls_name)
{
    NF_ASSERT(m_pMessageModule);
    return m_pMessageModule->SendTransToStoreServer(eType, cmd, table_id, dbname, table_name, xData, vk_list, where_addtional_conds, trans_id, seq, mod_key, cls_name);
}

int NFMessageMgr::SendDescStoreToStoreServer(NF_SERVER_TYPES eType, const std::string& dbName, const string &table_name, const google::protobuf::Message *pMessage, const QueryDescStore_CB &cb)
{
    NF_ASSERT(m_pMessageModule);
    return m_pMessageModule->SendDescStoreToStoreServer(eType, dbName, table_name, pMessage, cb);
}

int NFMessageMgr::SendMsgToServer(NF_SERVER_TYPES eSendType, NF_SERVER_TYPES recvType, uint32_t nMsgId, const google::protobuf::Message &xData, uint64_t valueId)
{
    NF_ASSERT(m_pMessageModule);
    return m_pMessageModule->SendMsgToServer(eSendType, recvType, nMsgId, xData, valueId);
}

int NFMessageMgr::SendMsgToServer(NF_SERVER_TYPES eSendType, NF_SERVER_TYPES recvType, uint32_t busId, uint32_t nMsgId, const google::protobuf::Message &xData, uint64_t valueId)
{
    NF_ASSERT(m_pMessageModule);
    return m_pMessageModule->SendMsgToServer(eSendType, recvType, busId, nMsgId, xData, valueId);
}

int NFMessageMgr::SendMsgToMasterServer(NF_SERVER_TYPES eSendTyp, uint32_t nMsgId, const google::protobuf::Message &xData, uint64_t valueId)
{
    NF_ASSERT(m_pMessageModule);
    return m_pMessageModule->SendMsgToMasterServer(eSendTyp, nMsgId, xData, valueId);
}

NFServerData *NFMessageMgr::GetRouteData(NF_SERVER_TYPES eSendType)
{
    NF_ASSERT(m_pMessageModule);
    return m_pMessageModule->GetRouteData(eSendType);
}

const NFServerData *NFMessageMgr::GetRouteData(NF_SERVER_TYPES eSendType) const
{
    NF_ASSERT(m_pMessageModule);
    return m_pMessageModule->GetRouteData(eSendType);
}

NFServerData *NFMessageMgr::GetMasterData(NF_SERVER_TYPES eSendType)
{
    NF_ASSERT(m_pMessageModule);
    return m_pMessageModule->GetMasterData(eSendType);
}

const NFServerData *NFMessageMgr::GetMasterData(NF_SERVER_TYPES eSendType) const
{
    NF_ASSERT(m_pMessageModule);
    return m_pMessageModule->GetMasterData(eSendType);
}

void NFMessageMgr::CloseAllLink(NF_SERVER_TYPES eSendType)
{
    NF_ASSERT(m_pMessageModule);
    m_pMessageModule->CloseAllLink(eSendType);
}

NF_SHARE_PTR<NFServerData> NFMessageMgr::GetServerByServerId(NF_SERVER_TYPES eSendType, uint32_t busId)
{
    NF_ASSERT(m_pMessageModule);
    return m_pMessageModule->GetServerByServerId(eSendType, busId);
}

NF_SHARE_PTR<NFServerData> NFMessageMgr::GetServerByUnlinkId(NF_SERVER_TYPES eSendType, uint64_t unlinkId)
{
    NF_ASSERT(m_pMessageModule);
    return m_pMessageModule->GetServerByUnlinkId(eSendType, unlinkId);
}

NF_SHARE_PTR<NFServerData> NFMessageMgr::CreateServerByServerId(NF_SERVER_TYPES eSendType, uint32_t busId, NF_SERVER_TYPES busServerType, const proto_ff::ServerInfoReport &data)
{
    NF_ASSERT(m_pMessageModule);
    return m_pMessageModule->CreateServerByServerId(eSendType, busId, busServerType, data);
}

void NFMessageMgr::CreateLinkToServer(NF_SERVER_TYPES eSendType, uint32_t busId, uint64_t linkId)
{
    NF_ASSERT(m_pMessageModule);
    m_pMessageModule->CreateLinkToServer(eSendType, busId, linkId);
}

void NFMessageMgr::DelServerLink(NF_SERVER_TYPES eSendType, uint64_t linkId)
{
    NF_ASSERT(m_pMessageModule);
    m_pMessageModule->DelServerLink(eSendType, linkId);
}

bool NFMessageMgr::AddEventCallBack(NF_SERVER_TYPES eType, uint64_t linkId, void *pTaraget, const NET_EVENT_FUNCTOR &cb)
{
    NF_ASSERT(m_pMessageModule);
    return m_pMessageModule->AddEventCallBack(eType, linkId, pTaraget, cb);
}

bool NFMessageMgr::AddMessageCallBack(NF_SERVER_TYPES eType, uint32_t nMsgID, void *pTaraget, const NET_RECEIVE_FUNCTOR &cb)
{
    NF_ASSERT(m_pMessageModule);
    return m_pMessageModule->AddMessageCallBack(eType, nMsgID, pTaraget, cb);
}

bool NFMessageMgr::AddOtherCallBack(NF_SERVER_TYPES eType, uint64_t linkId, void *pTaraget, const NET_RECEIVE_FUNCTOR &cb)
{
    NF_ASSERT(m_pMessageModule);
    return m_pMessageModule->AddOtherCallBack(eType, linkId, pTaraget, cb);
}

int NFMessageMgr::HttpGet(NF_SERVER_TYPES serverType, const string &strUri, const HTTP_CLIENT_RESPONE &respone, const map<std::string, std::string> &xHeaders, int timeout)
{
    NF_ASSERT(m_pMessageModule);
    return m_pMessageModule->HttpGet(serverType, strUri, respone, xHeaders, timeout);
}

int NFMessageMgr::HttpPost(NF_SERVER_TYPES serverType, const string &strUri, const string &strPostData, const HTTP_CLIENT_RESPONE &respone, const map<std::string, std::string> &xHeaders, int timeout)
{
    NF_ASSERT(m_pMessageModule);
    return m_pMessageModule->HttpPost(serverType, strUri, strPostData, respone, xHeaders, timeout);
}

bool NFMessageMgr::DelAllCallBack(void *pTarget)
{
    NF_ASSERT(m_pMessageModule);
    return m_pMessageModule->DelAllCallBack(pTarget);
}

std::vector<NF_SHARE_PTR<NFServerData>> NFMessageMgr::GetAllServer(NF_SERVER_TYPES eSendType)
{
    NF_ASSERT(m_pMessageModule);
    return m_pMessageModule->GetAllServer(eSendType);
}

std::vector<NF_SHARE_PTR<NFServerData>> NFMessageMgr::GetAllServer(NF_SERVER_TYPES eSendType, NF_SERVER_TYPES serverTypes)
{
    NF_ASSERT(m_pMessageModule);
    return m_pMessageModule->GetAllServer(eSendType, serverTypes);
}

std::vector<std::string> NFMessageMgr::GetDBNames(NF_SERVER_TYPES eSendType)
{
    NF_ASSERT(m_pMessageModule);
    return m_pMessageModule->GetDBNames(eSendType);
}

bool NFMessageMgr::ResponseHttpMsg(NF_SERVER_TYPES serverType, const NFIHttpHandle &req, const string &strMsg, NFWebStatus code, const string &reason)
{
    NF_ASSERT(m_pMessageModule);
    return m_pMessageModule->ResponseHttpMsg(serverType, req, strMsg, code, reason);
}

bool NFMessageMgr::ResponseHttpMsg(NF_SERVER_TYPES serverType, uint64_t requestId, const string &strMsg, NFWebStatus code, const string &reason)
{
    NF_ASSERT(m_pMessageModule);
    return m_pMessageModule->ResponseHttpMsg(serverType, requestId, strMsg, code, reason);
}

uint64_t NFMessageMgr::GetServerLinkId(NF_SERVER_TYPES eSendType) const
{
    NF_ASSERT(m_pMessageModule);
    return m_pMessageModule->GetServerLinkId(eSendType);
}

void NFMessageMgr::SetServerLinkId(NF_SERVER_TYPES eSendType, uint64_t linkId)
{
    NF_ASSERT(m_pMessageModule);
    m_pMessageModule->SetServerLinkId(eSendType, linkId);
}

std::vector<NF_SHARE_PTR<NFServerData>> NFMessageMgr::GetServerByServerType(NF_SERVER_TYPES eSendType, NF_SERVER_TYPES serverTypes)
{
    NF_ASSERT(m_pMessageModule);
    return m_pMessageModule->GetServerByServerType(eSendType, serverTypes);
}

NF_SHARE_PTR<NFServerData> NFMessageMgr::GetFirstServerByServerType(NF_SERVER_TYPES eSendType, NF_SERVER_TYPES serverTypes)
{
    NF_ASSERT(m_pMessageModule);
    return m_pMessageModule->GetFirstServerByServerType(eSendType, serverTypes);
}

NF_SHARE_PTR<NFServerData> NFMessageMgr::GetRandomServerByServerType(NF_SERVER_TYPES eSendType, NF_SERVER_TYPES serverTypes)
{
    NF_ASSERT(m_pMessageModule);
    return m_pMessageModule->GetRandomServerByServerType(eSendType, serverTypes);
}

NF_SHARE_PTR<NFServerData> NFMessageMgr::GetSuitServerByServerType(NF_SERVER_TYPES eSendType, NF_SERVER_TYPES serverTypes, uint64_t value)
{
    NF_ASSERT(m_pMessageModule);
    return m_pMessageModule->GetSuitServerByServerType(eSendType, serverTypes, value);
}

NF_SHARE_PTR<NFServerData> NFMessageMgr::GetSuitServerByServerType(NF_SERVER_TYPES eSendType, NF_SERVER_TYPES serverTypes, const string &value)
{
    NF_ASSERT(m_pMessageModule);
    return m_pMessageModule->GetSuitServerByServerType(eSendType, serverTypes, value);
}
