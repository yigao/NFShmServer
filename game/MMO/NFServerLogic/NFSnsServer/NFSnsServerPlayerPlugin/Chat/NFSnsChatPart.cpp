// -------------------------------------------------------------------------
//    @FileName         :    NFSnsChatPart.cpp
//    @Author           :    gaoyi
//    @Date             :    23-11-15
//    @Email			:    445267987@qq.com
//    @Module           :    NFSnsChatPart
//
// -------------------------------------------------------------------------

#include "NFSnsChatPart.h"
#include <Chat.pb.h>
#include <Faction.pb.h>
#include <Cache/NFCacheMgr.h>
#include <Clan/NFSnsClanMgr.h>
#include <DescStoreEx/AchievementDescEx.h>
#include <Faction/NFFactionMgr.h>
#include <Relation/NFSnsRelationMgr.h>
#include "NFLogicCommon/RelationDefine.h"
#include "NFSnsChatMgr.h"

NFSnsChatPart::NFSnsChatPart()
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

NFSnsChatPart::~NFSnsChatPart()
{
}

int NFSnsChatPart::CreateInit()
{
    return 0;
}

int NFSnsChatPart::ResumeInit()
{
    return 0;
}

int NFSnsChatPart::Init(NFPlayerDetail* pMaster, uint32_t partType, const proto_ff::RoleDBSnsDetail& data)
{
    return NFSnsPart::Init(pMaster, partType, data);
}

int NFSnsChatPart::UnInit()
{
    return NFSnsPart::UnInit();
}

int NFSnsChatPart::LoadFromDB(const proto_ff::RoleDBSnsDetail& data)
{
    return NFSnsPart::LoadFromDB(data);
}

int NFSnsChatPart::InitConfig(const proto_ff::RoleDBSnsDetail& data)
{
    return NFSnsPart::InitConfig(data);
}

int NFSnsChatPart::SaveDB(proto_ff::RoleDBSnsDetail& dbData)
{
    return NFSnsPart::SaveDB(dbData);
}

int NFSnsChatPart::RegisterMessage()
{
    RegisterClientMessage(proto_ff::CLIENT_TO_CENTER_ASK_OFFLINE_MSG_REQ);
    RegisterClientMessage(proto_ff::CLIENT_TO_CENTER_INTRVAL_ASK_OFFLINE_MSG_REQ, true);

    RegisterServerMessage(proto_ff::CENTER_SERVER_PROTOCOL_CHAT_REQ, true);
    RegisterServerMessage(proto_ff::CENTER_SERVER_PROTOCOL_GWSYSCHATMSGNOTIFY);
    RegisterServerMessage(proto_ff::SERVER_TO_SERVER_CROSS_CHAT);

    return 0;
}

int NFSnsChatPart::OnHandleClientMessage(uint32_t msgId, NFDataPackage& packet)
{
    switch (msgId)
    {
        case proto_ff::CLIENT_TO_CENTER_ASK_OFFLINE_MSG_REQ:
        {
            OnHandleAskOfflineMsgReq(msgId, packet);
            break;
        }
        case proto_ff::CLIENT_TO_CENTER_INTRVAL_ASK_OFFLINE_MSG_REQ:
        {
            OnHandleIntrvalAskOfflineMsgReq(msgId, packet);
            break;
        }
        default:
            break;
    }
    return 0;
}

int NFSnsChatPart::OnHandleServerMessage(uint32_t msgId, NFDataPackage& packet)
{
    switch (msgId)
    {
        case proto_ff::CENTER_SERVER_PROTOCOL_CHAT_REQ:
        {
            OnHandleChatReq(msgId, packet);
            break;
        }
        case proto_ff::CENTER_SERVER_PROTOCOL_GWSYSCHATMSGNOTIFY:
        {
            OnHandleSysChatMsgNotify(msgId, packet);
            break;
        }
        case proto_ff::SERVER_TO_SERVER_CROSS_CHAT:
        {
            OnHandleCrossChat(msgId, packet);
            break;
        }
        default:
            break;
    }
    return 0;
}

int NFSnsChatPart::OnHandleChatReq(uint32_t msgId, NFDataPackage& packet)
{
    proto_ff::GWChatMsgReq chatMsgReq;
    CLIENT_MSG_PROCESS_WITH_PRINTF(packet, chatMsgReq);

    proto_ff::GCChatMsgRsp chatMsgRsp;

    CharIDType charID = chatMsgReq.fromid();
    CharIDType targetID = chatMsgReq.targetid();
    proto_ff::CHAT_CHANNEL channelID = chatMsgReq.channel();

    auto pSimple = NFCacheMgr::Instance(m_pObjPluginManager)->GetPlayerSimple(m_pMaster->GetCid());
    CHECK_NULL(pSimple);

    if (!CHAT_CHANNEL_IsValid(channelID))
    {
        NFLogErrorFmt(NF_LOG_SYSTEMLOG, m_pMaster->Cid(), "[center] OnGCChatMsgRsp..CHAT_CHANNEL_IsValid..cid:%lu,channelID:%d", charID, channelID);
        return 0;
    }

    bool virForbidFlag = NFSnsChatMgr::Instance(m_pObjPluginManager)->IsVirForbid(charID);

    proto_ff::RolePlayerMiniInfo* playerMiniInfo = chatMsgRsp.mutable_fromplayerinfo();
    pSimple->FillPlayerProto(playerMiniInfo);

    chatMsgRsp.set_channel(channelID);
    chatMsgRsp.set_msgtype(chatMsgReq.msgtype());
    chatMsgRsp.set_msgval(chatMsgReq.msgval());
    chatMsgRsp.mutable_chatcontent()->CopyFrom(chatMsgReq.chatcontent());

    //聊天内容
    string strcontent;
    if (chatMsgReq.has_chatcontent())
    {
        strcontent = chatMsgReq.chatcontent().describes();
    }

    switch (channelID)
    {
        case proto_ff::CHAT_CHANNEL_WORLD:
        case proto_ff::CHAT_CHANNEL_HORN:   //大喇叭
        case proto_ff::CHAT_CHANNEL_ENLIST: //组队喊话
        {
            if (proto_ff::CHAT_CHANNEL_WORLD == channelID && virForbidFlag)
            {
                NFSnsChatMgr::Instance(m_pObjPluginManager)->SendW2C(proto_ff::LOGIC_TO_CLIENT_CHAT_MSG_RSP, charID, chatMsgRsp);
            }
            else
            {
                NFSnsChatMgr::Instance(m_pObjPluginManager)->SendWorldMsg(proto_ff::LOGIC_TO_CLIENT_CHAT_MSG_RSP, chatMsgRsp);
            }

            break;
        }
        case proto_ff::CHAT_CHANNEL_GUILD:
        {
            chatMsgRsp.set_right(chatMsgReq.right());
            uint32_t factionId = NFSnsFactionMgr::Instance(m_pObjPluginManager)->RoleFactionId(charID);
            if (factionId > 0)
            {
                if (virForbidFlag)
                {
                    SET_UINT64 setCid;
                    setCid.insert(charID);
                    NFSnsChatMgr::Instance(m_pObjPluginManager)->SendW2C(proto_ff::LOGIC_TO_CLIENT_CHAT_MSG_RSP, setCid, chatMsgRsp);
                }
                else
                {
                    NFSnsChatMgr::Instance(m_pObjPluginManager)->SendUnionMsg(proto_ff::LOGIC_TO_CLIENT_CHAT_MSG_RSP, factionId, chatMsgRsp);
                    //
                    if (chatMsgReq.has_right() && chatMsgReq.has_curnum())
                    {
                        //LogDebugFmtPrint("[center] ChatCenter::OnServerChatReq...cid:%lu, isfirst:%d, curnum:%d ",charID, chatMsgReq.right(), chatMsgReq.curnum());
                        proto_ff::CL_FactionAnswerQuestionRsp logicrsp;
                        logicrsp.set_cid(charID);
                        logicrsp.set_first(chatMsgReq.right());
                        logicrsp.set_curnum(chatMsgReq.curnum());
                        logicrsp.set_content(chatMsgReq.chatcontent().describes());

                        SendMsgToLogicServer(proto_ff::FACTION_CL_ANSWER_QUESTION_RSP, logicrsp);
                    }
                }
            }
            break;
        }
        case proto_ff::CHAT_CHANNEL_CLAN3:
        {
            const stClanInfo* pInfo = NFSnsClanMgr::Instance(m_pObjPluginManager)->GetClan3Info(charID);
            if (pInfo)
            {
                NFSnsChatMgr::Instance(m_pObjPluginManager)->SendW2C(proto_ff::LOGIC_TO_CLIENT_CHAT_MSG_RSP, const_cast<stClanInfo *>(pInfo)->members, chatMsgRsp);
            }
        }
        break;
        case proto_ff::CHAT_CHANNEL_CLAN5:
        {
            const stClanInfo* pInfo = NFSnsClanMgr::Instance(m_pObjPluginManager)->GetClan5Info(charID);
            if (pInfo)
            {
                NFSnsChatMgr::Instance(m_pObjPluginManager)->SendW2C(proto_ff::LOGIC_TO_CLIENT_CHAT_MSG_RSP, const_cast<stClanInfo *>(pInfo)->members, chatMsgRsp);
            }
        }
        break;
        case proto_ff::CHAT_CHANNEL_POKERROOM:
        {
            NFSnsChatMgr::Instance(m_pObjPluginManager)->SendPokerMsg(proto_ff::LOGIC_TO_CLIENT_CHAT_MSG_RSP, chatMsgRsp);
            break;
        }
        case proto_ff::CHAT_CHANNEL_TEAM: //组队频道
        {
            //g_GetTeamMgr()->BroadcastTeam(charID, EMODULE_ID_CHAT, LOGIC_TO_CLIENT_CHAT_MSG_RSP, &chatMsgRsp, false, false);
            break;
        }
        case proto_ff::CHAT_CHANNEL_SYSTEM:
            break;
        case proto_ff::CHAT_CHANNEL_PRIVATE:
        {
            //自己无法跟自己聊天
            if (charID == targetID)
            {
                chatMsgRsp.Clear();
                chatMsgRsp.set_ret(proto_ff::RET_CHAT_NOT_MYSELF);
                NFSnsChatMgr::Instance(m_pObjPluginManager)->SendW2C(proto_ff::LOGIC_TO_CLIENT_CHAT_MSG_RSP, charID, chatMsgRsp);
                return false;
            }

            //判断是否可以进行私聊
            if (NFSnsChatMgr::Instance(m_pObjPluginManager)->ValidatePrivateChat(charID, targetID))
            {
                chatMsgRsp.Clear();
                chatMsgRsp.set_ret(proto_ff::RET_CHAT_TARGET_IN_BLACK);
                NFSnsChatMgr::Instance(m_pObjPluginManager)->SendW2C(proto_ff::LOGIC_TO_CLIENT_CHAT_MSG_RSP, charID, chatMsgRsp);
                return false;
            }

            //如果对方在线
            auto pDstOnline = NFCacheMgr::Instance(m_pObjPluginManager)->GetPlayerSimple(targetID);
            if (nullptr == pDstOnline || !pDstOnline->IsOnline())
            {
                //好友可以进行离线聊天，非好友关系只能是在线聊天
                if (NFSnsRelationMgr::Instance(m_pObjPluginManager)->IsFriendRelation(charID, targetID))
                {
                    NFSnsChatMgr::Instance(m_pObjPluginManager)->SendOfflineMsgByRpc(charID, targetID, chatMsgReq.chatcontent());
                    NFSnsRelationMgr::Instance(m_pObjPluginManager)->UpdateRecentList(charID, targetID, RELATION_RECENT_CHAT);
                    return true;
                }
                else
                {
                    chatMsgRsp.Clear();
                    chatMsgRsp.set_ret(proto_ff::RET_CHAT_TARGET_NOT_ONLINE);
                    NFSnsChatMgr::Instance(m_pObjPluginManager)->SendW2C(proto_ff::LOGIC_TO_CLIENT_CHAT_MSG_RSP, charID, chatMsgRsp);
                    return false;
                }
            }
            else
            {
                chatMsgRsp.set_ret(proto_ff::RET_SUCCESS);
                NFSnsChatMgr::Instance(m_pObjPluginManager)->SendW2C(proto_ff::LOGIC_TO_CLIENT_CHAT_MSG_RSP, targetID, chatMsgRsp);
                NFSnsRelationMgr::Instance(m_pObjPluginManager)->UpdateRecentList(charID, targetID, RELATION_RECENT_CHAT);
            }
        }
        break;
        default:
            break;
    }

    return 0;
}

int NFSnsChatPart::AddOfflineMsg(uint64_t sendCid, const proto_ff::ChatContentInfo& chatContent)
{
    if (m_msgList.size() >= MAX_OFFLINE_MSG)
    {
        m_msgList.erase(m_msgList.begin());
    }

    OffLinePrivateMsg msg;
    msg.chatContent = chatContent;
    msg.fromPlayerID = sendCid;
    msg.sendTime = NFTime::Now().UnixSec();
    m_msgList.push_back(msg);
    return 0;
}

/**
 * \brief 请求离线消息
 * \param msgId
 * \param packet
 * \return
 */
int NFSnsChatPart::OnHandleAskOfflineMsgReq(uint32_t msgId, NFDataPackage& packet)
{
    proto_ff::CWAskOfflineMsgReq askOfflineMsgReq;
    CLIENT_MSG_PROCESS_WITH_PRINTF(packet, askOfflineMsgReq);

    proto_ff::WCAskOfflineMsgRsp askOfflineMsgRsp;

    //离线私人聊天消息
    askOfflineMsgRsp.set_msgsize(m_msgList.size());

    SendMsgToClient(proto_ff::CENTER_TO_CLIENT_ASK_OFFLINE_MSG_RSP, askOfflineMsgRsp);

    return 0;
}

/**
 * \brief 分段请求聊天离线数据
 * \param msgId
 * \param packet
 * \return
 */
int NFSnsChatPart::OnHandleIntrvalAskOfflineMsgReq(uint32_t msgId, NFDataPackage& packet)
{
    proto_ff::CWIntrvalAskOfflineMsgReq IntrvalaskOfflineMsgReq;
    CLIENT_MSG_PROCESS_WITH_PRINTF(packet, IntrvalaskOfflineMsgReq);
    uint32_t size = IntrvalaskOfflineMsgReq.size();
    proto_ff::WCIntrvalAskOfflineMsgRsp intravlAskOfflineMsgRsp;
    //离线私人聊天消息

    uint32_t msgSize = m_msgList.size();
    if (msgSize > size)
    {
        msgSize = size;
    }

    uint32_t count = 0;
    for(auto iter = m_msgList.begin(); iter != m_msgList.end() && count < msgSize;)
    {
        proto_ff::OfflineMsg* offlineMsg = intravlAskOfflineMsgRsp.add_offlinemsglist();
        CharIDType chatID = iter->fromPlayerID;
        NFPlayerSimple* playerSimple = NFCacheMgr::Instance(m_pObjPluginManager)->QueryPlayerSimpleByRpc(m_pMaster->Cid(), chatID);
        if (playerSimple)
        {
            playerSimple->FillPlayerProto(offlineMsg->mutable_playerinfo());
            proto_ff::ChatContentInfo* chatContentInfo = offlineMsg->mutable_chatcontent();
            chatContentInfo->CopyFrom(iter->chatContent);
            offlineMsg->set_sendtime(iter->sendTime);
        }
        else
        {
            NFLogError(NF_LOG_SYSTEMLOG, 0, "QueryPlayerSimpleByRpc failed, cid:{}", chatID);
        }

        iter = m_msgList.erase(iter);
        count++;
    }

    SendMsgToClient(proto_ff::CENTER_TO_CLIENT_INTRVAL_ASK_OFFLINE_MSG_RSP, intravlAskOfflineMsgRsp);
    return 0;
}

/**
 * \brief 逻辑服通知世界服转发传闻或广播
 * \param msgId
 * \param packet
 * \return
 */
int NFSnsChatPart::OnHandleSysChatMsgNotify(uint32_t msgId, NFDataPackage& packet)
{
    proto_ff::GWSysChatMsgNotify notifyMsg;
    CLIENT_MSG_PROCESS_WITH_PRINTF(packet, notifyMsg);

    return 0;
}

/**
 * \brief 跨服聊天消息
 * \param msgId
 * \param packet
 * \return
 */
int NFSnsChatPart::OnHandleCrossChat(uint32_t msgId, NFDataPackage& packet)
{
    proto_ff::CWAskOfflineMsgReq askOfflineMsgReq;
    CLIENT_MSG_PROCESS_WITH_PRINTF(packet, askOfflineMsgReq);

    proto_ff::WCAskOfflineMsgRsp askOfflineMsgRsp;

    //离线私人聊天消息
    askOfflineMsgRsp.set_msgsize(m_msgList.size());

    SendMsgToClient(proto_ff::CENTER_TO_CLIENT_ASK_OFFLINE_MSG_RSP, askOfflineMsgRsp);

    return 0;
}