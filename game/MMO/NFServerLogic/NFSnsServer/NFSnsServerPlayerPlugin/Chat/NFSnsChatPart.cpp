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
    RegisterServerMessage(proto_ff::CENTER_SERVER_PROTOCOL_CHAT_REQ);
    return 0;
}

int NFSnsChatPart::OnHandleClientMessage(uint32_t msgId, NFDataPackage& packet)
{
    return NFSnsPart::OnHandleClientMessage(msgId, packet);
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

    /*if (!CHAT_CHANNEL_IsValid(channelID))
    {
        LogErrFmtPrint("[center] OnGCChatMsgRsp..CHAT_CHANNEL_IsValid..cid:%lu,channelID:%d", charID, channelID);
        return false;
    }
    bool virForbidFlag = IsVirForbid(charID);

    proto_ff::RolePlayerMiniInfo* playerMiniInfo = chatMsgRsp.mutable_fromplayerinfo();
    playerMiniInfo->set_playerid(charID);
    playerMiniInfo->set_playername(pFromOnline->Name());
    playerMiniInfo->set_level(pFromOnline->Level());
    playerMiniInfo->set_prof(pFromOnline->Prof());
    playerMiniInfo->set_viplevel(pFromOnline->VipLevel());

    playerMiniInfo->mutable_facade()->CopyFrom(pFromOnline->Facade());
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
        case CHAT_CHANNEL_WORLD:
        case CHAT_CHANNEL_HORN:   //大喇叭
        case CHAT_CHANNEL_ENLIST: //组队喊话
        {
            if (CHAT_CHANNEL_WORLD == channelID && virForbidFlag)
            {
                SET_UINT64 setCid;
                setCid.insert(charID);
                SendW2C(LOGIC_TO_CLIENT_CHAT_MSG_RSP, setCid, &chatMsgRsp);
            }
            else
            {
                SendWorldMsg(LOGIC_TO_CLIENT_CHAT_MSG_RSP, &chatMsgRsp);
            }

            CenterToLogicAchCommonAdd addAch;
            addAch.set_cid(charID);
            addAch.set_add_num(1);
            addAch.set_type(XIUZHENROAD_EVENT_WORLD_CHAT);
            g_GetCenterService()->SendLogicByCid(charID, CENTER_TO_LOGIC_ACH_COMMON_ADD, &addAch);
            break;
        }
        case CHAT_CHANNEL_GUILD:
        {
            chatMsgRsp.set_right(chatMsgReq.right());
            uint32_t factionId = g_GetFactionMgr()->RoleFactionId(charID);
            if (factionId > 0)
            {
                if (virForbidFlag)
                {
                    SET_UINT64 setCid;
                    setCid.insert(charID);
                    SendW2C(LOGIC_TO_CLIENT_CHAT_MSG_RSP, setCid, &chatMsgRsp);
                }
                else
                {
                    SendUnionMsg(LOGIC_TO_CLIENT_CHAT_MSG_RSP, factionId, &chatMsgRsp);
                    //
                    if (chatMsgReq.has_right() && chatMsgReq.has_curnum())
                    {
                        //LogDebugFmtPrint("[center] ChatCenter::OnServerChatReq...cid:%lu, isfirst:%d, curnum:%d ",charID, chatMsgReq.right(), chatMsgReq.curnum());
                        CL_FactionAnswerQuestionRsp logicrsp;
                        logicrsp.set_cid(charID);
                        logicrsp.set_first(chatMsgReq.right());
                        logicrsp.set_curnum(chatMsgReq.curnum());
                        logicrsp.set_content(chatMsgReq.chatcontent().describes());
                        g_GetCenterService()->SendLogicByCid(charID, FACTION_CL_ANSWER_QUESTION_RSP, &logicrsp);
                    }
                }

                CenterToLogicAchCommonAdd addAch;
                addAch.set_cid(charID);
                addAch.set_add_num(1);
                addAch.set_type(XIUZHENROAD_EVENT_FACTION_CHAT);
                g_GetCenterService()->SendLogicByCid(charID, CENTER_TO_LOGIC_ACH_COMMON_ADD, &addAch);
            }
            break;
        }
        case CHAT_CHANNEL_CLAN3:
        {
            const stClanInfo* pInfo = g_GetCClanMgr()->GetClan3Info(charID);
            if (pInfo)
            {
                SendW2C(LOGIC_TO_CLIENT_CHAT_MSG_RSP, const_cast<stClanInfo *>(pInfo)->members, &chatMsgRsp);
            }
        }
        break;
        case CHAT_CHANNEL_CLAN5:
        {
            const stClanInfo* pInfo = g_GetCClanMgr()->GetClan5Info(charID);
            if (pInfo)
            {
                SendW2C(LOGIC_TO_CLIENT_CHAT_MSG_RSP, const_cast<stClanInfo *>(pInfo)->members, &chatMsgRsp);
            }
        }
        break;
        case CHAT_CHANNEL_POKERROOM:
        {
            SendPokerMsg(LOGIC_TO_CLIENT_CHAT_MSG_RSP, &chatMsgRsp);
            break;
        }
        case CHAT_CHANNEL_TEAM: //组队频道
        {
            //g_GetTeamMgr()->BroadcastTeam(charID, EMODULE_ID_CHAT, LOGIC_TO_CLIENT_CHAT_MSG_RSP, &chatMsgRsp, false, false);
            break;
        }
        case CHAT_CHANNEL_SYSTEM:
            break;
        /*case CHAT_CHANNEL_ENLIST:
        {
            int8_t campID = pFromOffline->GetCampID();
            SendEnlistMsg(LOGIC_TO_CLIENT_CHAT_MSG_RSP, campID, &chatMsgRsp);
            break;
        }#1#
        case CHAT_CHANNEL_PRIVATE:
        {
            //自己无法跟自己聊天
            if (charID == targetID)
            {
                chatMsgRsp.Clear();
                chatMsgRsp.set_ret(RET_CHAT_NOT_MYSELF);
                SendW2C(LOGIC_TO_CLIENT_CHAT_MSG_RSP, charID, &chatMsgRsp);
                return false;
            }

            //判断是否可以进行私聊
            if (ValidatePrivateChat(charID, targetID))
            {
                chatMsgRsp.Clear();
                chatMsgRsp.set_ret(RET_CHAT_TARGET_IN_BLACK);
                SendW2C(LOGIC_TO_CLIENT_CHAT_MSG_RSP, charID, &chatMsgRsp);
                return false;
            }

            //如果对方在线
            auto pDstOnline = g_GetCacheMgr()->GetRoleSimple(targetID);
            if (nullptr == pDstOnline || !pDstOnline->IsOnline())
            {
                //好友可以进行离线聊天，非好友关系只能是在线聊天
                if (g_GetRelationMgr()->IsFriendRelation(charID, targetID))
                {
                    SendOfflineMsg(charID, targetID, chatMsgReq.chatcontent());
                    g_GetRelationMgr()->UpdateRecentList(charID, targetID, RELATION_RECENT_CHAT);
                    return true;
                }
                else
                {
                    chatMsgRsp.Clear();
                    chatMsgRsp.set_ret(RET_CHAT_TARGET_NOT_ONLINE);
                    SendW2C(LOGIC_TO_CLIENT_CHAT_MSG_RSP, charID, &chatMsgRsp);
                    return false;
                }
            }
            else
            {
                chatMsgRsp.set_ret(RET_SUCCESS);
                SendW2C(LOGIC_TO_CLIENT_CHAT_MSG_RSP, targetID, &chatMsgRsp);
                g_GetRelationMgr()->UpdateRecentList(charID, targetID, RELATION_RECENT_CHAT);
            }
        }
        break;
        default:
            break;
    }
    //日志
    if (CHAT_CHANNEL_WORLD == channelID
        || CHAT_CHANNEL_GUILD == channelID
        || CHAT_CHANNEL_PRIVATE == channelID
    )
    {
        CAoLogMgr::Chat(pFromOnline, strcontent, (int32_t)channelID);
    }*/

    return 0;
}
