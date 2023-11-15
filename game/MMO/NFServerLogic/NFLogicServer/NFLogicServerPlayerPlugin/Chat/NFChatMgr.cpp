// -------------------------------------------------------------------------
//    @FileName         :    NFChatMgr.cpp
//    @Author           :    gaoyi
//    @Date             :    23-11-15
//    @Email			:    445267987@qq.com
//    @Module           :    NFChatMgr
//
// -------------------------------------------------------------------------

#include "NFChatMgr.h"

#include <Chat.pb.h>
#include <DescStore/ChatChatDesc.h>
#include <NFServerComm/NFServerCommon/NFIServerMessageModule.h>
#include <Player/NFPlayerMgr.h>

#include "Player/NFPlayer.h"

NFChatMgr::NFChatMgr()
{
    if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode())
    {
        CreateInit();
    }
    else
    {
        ResumeInit();
    }
}

NFChatMgr::~NFChatMgr()
{
}

int NFChatMgr::CreateInit()
{
    return 0;
}

int NFChatMgr::ResumeInit()
{
    return 0;
}

void NFChatMgr::SendBroadcastChat(BROADCAST_TYPE id, SystemChatMsgData& msgData, std::vector<CharIDType>& playerIdList)
{
    auto pCfg = ChatChatDesc::Instance()->GetDesc(id);
    if (nullptr == pCfg)
    {
        NFLogErrorFmt(NF_LOG_SYSTEMLOG, 0, "[logic] ChatManager::SendBroadcastChat ... nullptr == pCfg...nBroadcastChatID:%lu ", id);
        return;
    }

    proto_ff::GCSystemChatMsgNotify msg;

    if (pCfg->m_chatType < proto_ff::CHAT_CHANNEL_NONE || pCfg->m_chatType > proto_ff::CHAT_CHANNEL_LIMIT)
    {
        NFLogErrorFmt(NF_LOG_SYSTEMLOG, 0, "[logic] ChatManager::SendBroadcastChat ...pCfg chatType is error .nBroadcastChatID:%lu ", id);
        return;
    }

    if (!proto_ff::CHAT_CHANNEL_IsValid(pCfg->m_chatType))
    {
        NFLogErrorFmt(NF_LOG_SYSTEMLOG, 0, "[logic] ChatManager::SendBroadcastChat ...CHAT_CHANNEL_IsValid .nBroadcastChatID:%lu,type:%d ", id, pCfg->m_chatType);
        return;
    }

    msg.set_channel(proto_ff::CHAT_CHANNEL(pCfg->m_chatType));
    msg.set_msgtype(id);
    //填充角色信息
    for (uint32_t i = 0; i < msgData.players.size(); i++)
    {
        msg.add_players()->CopyFrom(msgData.players[i]);
    }

    //填充text
    for (uint32_t i = 0; i < msgData.text.size(); i++)
    {
        msg.add_text(msgData.text[i]);
    }

    //填充parmas
    for (uint32_t i = 0; i < msgData.params.size(); i++)
    {
        msg.add_parmas(msgData.params[i]);
    }

    //填充items
    for (uint32_t i = 0; i < msgData.items.size(); ++i)
    {
        proto_ff::ItemProtoInfo* proto = msg.add_items();
        if (nullptr != proto)
        {
            proto->CopyFrom(msgData.items.at(i));
        }
    }

    SendG2CChat(proto_ff::LOGIC_TO_CLIENT_SYSTEM_CHAT_MSG_NOTIFY, playerIdList, msg);
}

void NFChatMgr::SendBroadcastChat(BROADCAST_TYPE id, SystemChatMsgData& msgData, NFPlayer* pPlayer)
{
    if (nullptr == pPlayer)
    {
        NFLogError(NF_LOG_SYSTEMLOG, 0, "[logic] ChatManager::SendBroadcastChat ... nullptr == pPlayer...nBroadcastChatID:%lu ", id);
        return;
    }

    auto pCfg = ChatChatDesc::Instance()->GetDesc(id);
    if (nullptr == pCfg)
    {
        NFLogError(NF_LOG_SYSTEMLOG, 0, "[logic] ChatManager::SendBroadcastChat ... nullptr == pCfg...nBroadcastChatID:%lu ", id);
        return;
    }

    proto_ff::GCSystemChatMsgNotify msg;

    if (pCfg->m_chatType < proto_ff::CHAT_CHANNEL_NONE || pCfg->m_chatType > proto_ff::CHAT_CHANNEL_LIMIT)
    {
        NFLogError(NF_LOG_SYSTEMLOG, 0, "[logic] ChatManager::SendBroadcastChat ...pCfg chatType is error .nBroadcastChatID:%lu, chatType:%d ", id, pCfg->m_chatType);
        return;
    }

    if (!proto_ff::CHAT_CHANNEL_IsValid(pCfg->m_chatType))
    {
        NFLogError(NF_LOG_SYSTEMLOG, 0, "[logic] ChatManager::SendBroadcastChat ...CHAT_CHANNEL_IsValid .nBroadcastChatID:%lu,type:%d ", id, pCfg->m_chatType);
        return;
    }

    msg.set_channel(proto_ff::CHAT_CHANNEL(pCfg->m_chatType));
    msg.set_msgtype(id);
    //填充角色信息
    for (uint32_t i = 0; i < msgData.players.size(); i++)
    {
        msg.add_players()->CopyFrom(msgData.players[i]);
    }

    //填充text
    for (uint32_t i = 0; i < msgData.text.size(); i++)
    {
        msg.add_text(msgData.text[i]);
    }

    //填充parmas
    for (uint32_t i = 0; i < msgData.params.size(); i++)
    {
        msg.add_parmas(msgData.params[i]);
    }

    //填充items
    for (uint32_t i = 0; i < msgData.items.size(); ++i)
    {
        proto_ff::ItemProtoInfo* proto = msg.add_items();
        if (nullptr != proto)
        {
            proto->CopyFrom(msgData.items.at(i));
        }
    }
    //
    pPlayer->SendMsgToGameServer(proto_ff::LOGIC_TO_CLIENT_SYSTEM_CHAT_MSG_NOTIFY, msg);
}

void NFChatMgr::SendG2WBroadcast(BROADCAST_TYPE id, SystemChatMsgData& msgData, uint64_t extraId, uint32_t zid)
{
    proto_ff::GWSysChatMsgNotify notifyMsg;

    auto pCfg = ChatChatDesc::Instance()->GetDesc(id);
    if (nullptr == pCfg)
    {
        NFLogErrorFmt(NF_LOG_SYSTEMLOG, 0, "[logic] ChatManager::SendG2WBroadcast ... nullptr == pCfg...nBroadcastChatID:%lu ", id);
        return;
    }

    if (pCfg->m_chatType < proto_ff::CHAT_CHANNEL_NONE || pCfg->m_chatType > proto_ff::CHAT_CHANNEL_LIMIT)
    {
        NFLogErrorFmt(NF_LOG_SYSTEMLOG, 0, "[logic] ChatManager::SendG2WBroadcast ...pCfg chatType is error .nBroadcastChatID:%lu ", id);
        return;
    }
    if (!proto_ff::CHAT_CHANNEL_IsValid(pCfg->m_chatType))
    {
        NFLogErrorFmt(NF_LOG_SYSTEMLOG, 0, "[logic] ChatManager::SendG2WBroadcastxx ...CHAT_CHANNEL_IsValid .nBroadcastChatID:%lu,type:%d ", id, pCfg->m_chatType);
        return;
    }

    notifyMsg.set_channel(proto_ff::CHAT_CHANNEL(pCfg->m_chatType));
    notifyMsg.set_msgtype(id);

    //填充角色信息
    for (uint32_t i = 0; i < msgData.players.size(); i++)
    {
        notifyMsg.add_players()->CopyFrom(msgData.players[i]);
    }

    //填充text
    for (uint32_t i = 0; i < msgData.text.size(); i++)
    {
        notifyMsg.add_text(msgData.text[i]);
    }

    //填充parmas
    for (uint32_t i = 0; i < msgData.params.size(); i++)
    {
        notifyMsg.add_parmas(msgData.params[i]);
    }

    //填充装备items
    for (uint32_t i = 0; i < msgData.items.size(); ++i)
    {
        proto_ff::ItemProtoInfo* itemProto = notifyMsg.add_items();
        if (nullptr != itemProto)
            itemProto->CopyFrom(msgData.items[i]);
    }

    notifyMsg.set_extraid(extraId);

    auto pServerConfig = FindModule<NFIConfigModule>()->GetAppConfig(NF_ST_LOGIC_SERVER);
    CHECK_EXPR(pServerConfig, , "");

    //跑马灯类型的广播，是跨服的广播，并且当前再跨服地图中，需要整个跨服组都要广播
    if (proto_ff::CHAT_CHANNEL_RUMOR == pCfg->m_chatType && pCfg->m_CrossService && pServerConfig->IsCrossServer())
    {
        FindModule<NFIServerMessageModule>()->SendMsgToCrossCenterServer(NF_ST_LOGIC_SERVER, proto_ff::CENTER_SERVER_PROTOCOL_GWSYSCHATMSGNOTIFY, notifyMsg);
    }
    else
    {
        FindModule<NFIServerMessageModule>()->SendMsgToCenterServer(NF_ST_LOGIC_SERVER, proto_ff::CENTER_SERVER_PROTOCOL_GWSYSCHATMSGNOTIFY, notifyMsg);
    }
}

void NFChatMgr::SendG2WChannel(BROADCAST_TYPE id, SystemChatMsgData& msgData, proto_ff::CHAT_CHANNEL channelID, uint64_t extraId, uint32_t zid)
{
    proto_ff::GWSysChatMsgNotify notifyMsg;

    auto pCfg = ChatChatDesc::Instance()->GetDesc(id);
    if (nullptr == pCfg)
    {
        NFLogError(NF_LOG_SYSTEMLOG, 0, "[logic] ChatManager::SendG2WChannel ... nullptr == pCfg...nBroadcastChatID:%lu ", id);
        return;
    }

    if (pCfg->m_chatType < proto_ff::CHAT_CHANNEL_NONE || pCfg->m_chatType > proto_ff::CHAT_CHANNEL_LIMIT)
    {
        NFLogError(NF_LOG_SYSTEMLOG, 0, "[logic] ChatManager::SendG2WChannel ...pCfg chatType is error .nBroadcastChatID:%lu ", id);
        return;
    }

    notifyMsg.set_channel((proto_ff::CHAT_CHANNEL)pCfg->m_chatType);
    notifyMsg.set_msgtype(id);

    //填充角色信息
    for (uint32_t i = 0; i < msgData.players.size(); i++)
    {
        notifyMsg.add_players()->CopyFrom(msgData.players[i]);
    }

    //填充text
    for (uint32_t i = 0; i < msgData.text.size(); i++)
    {
        notifyMsg.add_text(msgData.text[i]);
    }

    //填充parmas
    for (uint32_t i = 0; i < msgData.params.size(); i++)
    {
        notifyMsg.add_parmas(msgData.params[i]);
    }

    //填充装备items
    for (uint32_t i = 0; i < msgData.items.size(); ++i)
    {
        proto_ff::ItemProtoInfo* itemProto = notifyMsg.add_items();
        if (nullptr != itemProto)
            itemProto->CopyFrom(msgData.items[i]);
    }

    notifyMsg.set_extraid(extraId);

    auto pServerConfig = FindModule<NFIConfigModule>()->GetAppConfig(NF_ST_LOGIC_SERVER);
    CHECK_EXPR(pServerConfig, , "");

    //跑马灯类型的广播 并且 是跨服的广播，并且当前再跨服地图中，需要整个跨服组都要广播
    if (proto_ff::CHAT_CHANNEL_RUMOR == pCfg->m_chatType && pCfg->m_CrossService && pServerConfig->IsCrossServer())
    {
        FindModule<NFIServerMessageModule>()->SendMsgToCrossCenterServer(NF_ST_LOGIC_SERVER, proto_ff::CENTER_SERVER_PROTOCOL_GWSYSCHATMSGNOTIFY, notifyMsg);
    }
    else
    {
        FindModule<NFIServerMessageModule>()->SendMsgToCenterServer(NF_ST_LOGIC_SERVER, proto_ff::CENTER_SERVER_PROTOCOL_GWSYSCHATMSGNOTIFY, notifyMsg);
    }
}

void NFChatMgr::InitPlayerMiniInfoStruct(NFPlayer* pPlayer, proto_ff::RolePlayerMiniInfo& info)
{
    if (pPlayer)
    {
        info.set_playerid(pPlayer->Cid());
        info.set_zid(pPlayer->GetZid());
        info.set_playername(pPlayer->GetName());
        info.set_level(pPlayer->GetAttr(proto_ff::A_LEVEL));
        info.set_prof(pPlayer->GetAttr(proto_ff::A_PROF));
        info.set_viplevel(pPlayer->GetAttr(proto_ff::A_VIP_LEVEL));
        info.set_teamid(pPlayer->GetAttr(proto_ff::A_TEAM_ID));
        info.set_unionid(pPlayer->GetAttr(proto_ff::A_FACTION_ID));
        pPlayer->SetFacadeProto(*info.mutable_facade());
    }
}

void NFChatMgr::OnUpdateVirForbid(uint32_t zid, SET_UINT64& setforbid)
{
}

bool NFChatMgr::IsVirForbid(uint32_t zid, uint64_t cid)
{
    return false;
}

void NFChatMgr::SendG2CChat(uint32_t cmd, std::vector<CharIDType>& playerIdList, const google::protobuf::Message& msg)
{
    for (uint32_t i = 0; i < playerIdList.size(); i++)
    {
        NFPlayer* pPlayer = NFPlayerMgr::Instance(m_pObjPluginManager)->GetPlayer(playerIdList[i]);
        if (nullptr == pPlayer)
        {
            NFLogErrorFmt(NF_LOG_SYSTEMLOG, 0, "[logic] ChatManager::SendG2CChat but Player is nullptr charId:%lu", playerIdList[i]);
            continue;
        }

        pPlayer->SendMsgToClient(cmd, msg);
    }
}
