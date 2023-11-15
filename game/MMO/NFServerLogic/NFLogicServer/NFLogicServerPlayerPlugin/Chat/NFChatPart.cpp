// -------------------------------------------------------------------------
//    @FileName         :    NFChatPart.cpp
//    @Author           :    gaoyi
//    @Date             :    23-10-20
//    @Email			:    445267987@qq.com
//    @Module           :    NFChatPart
//
// -------------------------------------------------------------------------

#include "NFChatPart.h"

#include <Chat.pb.h>
#include <proto_svr_event.pb.h>
#include <Clan/NFClanMgr.h>
#include <DescStoreEx/ChatDescEx.h>
#include <NFLogicCommon/NFEventDefine.h>
#include <Player/NFPayPart.h>
#include "NFChatMgr.h"
#include "NFLogicCommon/NFActivityDefine.h"

NFChatPart::NFChatPart()
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

NFChatPart::~NFChatPart()
{
}

int NFChatPart::CreateInit()
{
    worldCdTime = 0;  //
    guildCdTime = 0;  //
    teamCdTime = 0;   //
    sceneCdTime = 0;  //
    crossCdTime = 0;  //
    enlistCdTime = 0; //
    return 0;
}

int NFChatPart::ResumeInit()
{
    return 0;
}

int NFChatPart::Init(NFPlayer* pMaster, uint32_t partType, const proto_ff::RoleDBData& dbData)
{
    return NFPart::Init(pMaster, partType, dbData);
}

int NFChatPart::UnInit()
{
    return NFPart::UnInit();
}

int NFChatPart::LoadFromDB(const proto_ff::RoleDBData& data)
{
    return NFPart::LoadFromDB(data);
}

int NFChatPart::InitConfig(const proto_ff::RoleDBData& data)
{
    return NFPart::InitConfig(data);
}

int NFChatPart::SaveDB(proto_ff::RoleDBData& dbData)
{
    return NFPart::SaveDB(dbData);
}

int NFChatPart::RegisterMessage()
{
    RegisterClientMessage(proto_ff::CLIENT_TO_LOGIC_CHAT_MSG_REQ);
    return 0;
}

int NFChatPart::OnHandleClientMessage(uint32_t msgId, NFDataPackage& packet)
{
    switch (msgId)
    {
        case proto_ff::CLIENT_TO_LOGIC_CHAT_MSG_REQ:
        {
            HandleChatMsgReq(msgId, packet);
            break;
        }
        default:
            break;
    }
    return 0;
}

int NFChatPart::OnHandleServerMessage(uint32_t msgId, NFDataPackage& packet)
{
    return NFPart::OnHandleServerMessage(msgId, packet);
}

int NFChatPart::HandleChatMsgReq(uint32_t msgId, NFDataPackage& packet)
{
    proto_ff::CGChatMsgReq c2gChatMsg;
    CLIENT_MSG_PROCESS_WITH_PRINTF(packet, c2gChatMsg);

    proto_ff::GCChatMsgRsp chatMsgRsp;

    CharIDType fromID = m_pMaster->Cid();
    uint32_t fromZid = m_pMaster->GetZid();
    CharIDType targetID = c2gChatMsg.targetid();
    //
    proto_ff::CHAT_CHANNEL channelID = (proto_ff::CHAT_CHANNEL)c2gChatMsg.channel();

    if (!CHAT_CHANNEL_IsValid(channelID))
    {
        NFLogErrorFmt(NF_LOG_SYSTEMLOG, m_pMaster->Cid(), "[logic] ChatPart::HandleChatMsgReq...CHAT_CHANNEL_IsValid fromID:%lu,targetID:%lu,channelID:%d", fromID, targetID, channelID);
        return 0;
    }

    int64_t hornId = 0;
    //    bool rmvHornFlag = false;
    if (c2gChatMsg.has_chatcontent())
    {
        hornId = c2gChatMsg.chatcontent().hornid();
    }
    //
    chatMsgRsp.mutable_chatcontent()->CopyFrom(c2gChatMsg.chatcontent());
    bool virForbidFlag = NFChatMgr::Instance(m_pObjPluginManager)->IsVirForbid(fromZid, fromID);
    //
    SCommonSource sourceParam;
    sourceParam.src = S_Chat;
    sourceParam.param1 = channelID;

    switch (channelID)
    {
        case proto_ff::CHAT_CHANNEL_WORLD:
        {
            bool condFlag = true;
            if (m_pMaster->GetAttr(proto_ff::A_LEVEL) < ChatDescEx::Instance()->WorldLevLimit())
            {
                condFlag = false;
            }
            if (!condFlag)
            {
                //是否开启
                condFlag = true;
                NFPayPart* pPayPart = dynamic_cast<NFPayPart *>(m_pMaster->GetPart(PART_PAY));
                if (nullptr != pPayPart)
                {
                    if (!ChatDescEx::Instance()->IsMeetPayRmbCond(pPayPart->RealRmb()))
                    {
                        condFlag = false;
                    }
                }
            }
            if (!condFlag)
            {
                chatMsgRsp.set_ret(proto_ff::RET_CHAT_COND_LIMIT);
                m_pMaster->SendMsgToClient(proto_ff::LOGIC_TO_CLIENT_CHAT_MSG_RSP, chatMsgRsp);
                return 0;
            }

            if (!InChannelCdTime(channelID))
            {
                chatMsgRsp.set_ret(proto_ff::RET_CHAT_CD_TIME_LIMIT);
                m_pMaster->SendMsgToClient(proto_ff::LOGIC_TO_CLIENT_CHAT_MSG_RSP, chatMsgRsp);
                return 0;
            }

            break;
        }
        case proto_ff::CHAT_CHANNEL_CROSS:
        {
            if (hornId > 0)
            {
                //跨服喇叭
                /*const ServerHornServerHornCfgInfo *pHornCfg = g_GetServerHornServerHornCfgTable()->GetServerHornServerHornCfgInfo(hornId);
                if (nullptr == pHornCfg)
                {
                    NFLogErrorFmt(NF_LOG_SYSTEMLOG, m_pMaster->Cid(), "[logic] ChatPart::HandleChatMsgReq....nullptr == pHornCfg...cid:%lu, hornid:%ld", fromID,hornId);
                    return;
                }

                if (pHornCfg->itemid > 0)
                {
                    PackagePart *pPackagePart = dynamic_cast<PackagePart*>(m_pMaster->GetPart(PART_PACKAGE));
                    if (nullptr == pPackagePart)
                    {
                        NFLogErrorFmt(NF_LOG_SYSTEMLOG, m_pMaster->Cid(), "[logic] ChatPart::HandleChatMsgReq....nullptr == pPackagePart...cid:%lu, hornid:%ld", fromID, hornId);
                        return;
                    }
                    LIST_ITEM lstItem;
                    SItem item;
                    item.nItemID = pHornCfg->itemid;
                    item.nNum = 1;
                    item.byBind = (uint8_t)EBindState::EBindState_all;
                    lstItem.push_back(item);
                    if (pPackagePart->HasItem(lstItem))
                    {
                        rmvHornFlag = true;
                    }
                }
                if (!rmvHornFlag && pHornCfg->currencyCost > 0)
                {
                    //1-?????2-????
                    if (1 == pHornCfg->currencyType && m_pMaster->GetAttr(A_DIA) < pHornCfg->currencyCost)
                    {
                        chatMsgRsp.set_ret(RET_DIAMOND_LACK);
                        m_pMaster->SendMsgToClient(proto_ff::LOGIC_TO_CLIENT_CHAT_MSG_RSP, chatMsgRsp);
                        return;
                    }
                    else if (2 == pHornCfg->currencyType && m_pMaster->GetAttr(A_BD_DIA) < pHornCfg->currencyCost)
                    {
                        chatMsgRsp.set_ret(RET_BIND_DIAMOND_LACK);
                        m_pMaster->SendMsgToClient(proto_ff::LOGIC_TO_CLIENT_CHAT_MSG_RSP, chatMsgRsp);
                        return;
                    }
                }*/
            }
            else
            {
                //跨服聊天
                if (ChatDescEx::Instance()->CrossChatCostBDia() > 0 && m_pMaster->GetAttr(proto_ff::A_BD_DIA) < ChatDescEx::Instance()->CrossChatCostBDia())
                {
                    chatMsgRsp.set_ret(proto_ff::RET_BIND_DIAMOND_LACK);
                    m_pMaster->SendMsgToClient(proto_ff::LOGIC_TO_CLIENT_CHAT_MSG_RSP, chatMsgRsp);
                    return 0;
                }

                bool condFlag = true;
                if (m_pMaster->GetAttr(proto_ff::A_LEVEL) < ChatDescEx::Instance()->CrossLevLimit())
                {
                    condFlag = false;
                }
                if (!condFlag)
                {
                    //是否开启
                    condFlag = true;
                    NFPayPart* pPayPart = dynamic_cast<NFPayPart *>(m_pMaster->GetPart(PART_PAY));
                    if (nullptr != pPayPart)
                    {
                        if (!ChatDescEx::Instance()->IsMeetPayRmbCond(pPayPart->RealRmb()))
                        {
                            condFlag = false;
                        }
                    }
                }

                if (!condFlag)
                {
                    chatMsgRsp.set_ret(proto_ff::RET_CHAT_COND_LIMIT);
                    m_pMaster->SendMsgToClient(proto_ff::LOGIC_TO_CLIENT_CHAT_MSG_RSP, chatMsgRsp);
                    return 0;
                }

                if (!InChannelCdTime(channelID))
                {
                    chatMsgRsp.set_ret(proto_ff::RET_CHAT_CD_TIME_LIMIT);
                    m_pMaster->SendMsgToClient(proto_ff::LOGIC_TO_CLIENT_CHAT_MSG_RSP, chatMsgRsp);
                    return 0;
                }
            }
            break;
        }
        case proto_ff::CHAT_CHANNEL_GUILD:
        case proto_ff::CHAT_CHANNEL_TEAM:
        case proto_ff::CHAT_CHANNEL_ENLIST:
        case proto_ff::CHAT_CHANNEL_SCENE:
        case proto_ff::CHAT_CHANNEL_CLAN3:
        case proto_ff::CHAT_CHANNEL_CLAN5:
        {
            if (proto_ff::CHAT_CHANNEL_GUILD == channelID)
            {
                if (m_pMaster->GetAttr(proto_ff::A_FACTION_ID) <= 0)
                {
                    chatMsgRsp.set_ret(proto_ff::RET_FACTION_NOT_JOIN);
                    m_pMaster->SendMsgToClient(proto_ff::LOGIC_TO_CLIENT_CHAT_MSG_RSP, chatMsgRsp);
                    return 0;
                }
            }
            else if (proto_ff::CHAT_CHANNEL_TEAM == channelID)
            {
                ///放到社交服上去校验
                if (m_pMaster->GetAttr(proto_ff::A_TEAM_ID) <= 0)
                {
                    chatMsgRsp.set_ret(proto_ff::RET_TEAM_NOT_MEMBER);
                    m_pMaster->SendMsgToClient(proto_ff::LOGIC_TO_CLIENT_CHAT_MSG_RSP, chatMsgRsp);
                    return 0;
                }
            }
            else if (proto_ff::CHAT_CHANNEL_ENLIST == channelID)
            {
                if (ChatDescEx::Instance()->TeamEnlistCostBindDia() > 0 && m_pMaster->GetAttr(proto_ff::A_BD_DIA) < ChatDescEx::Instance()->TeamEnlistCostBindDia())
                {
                    chatMsgRsp.set_ret(proto_ff::RET_BIND_DIAMOND_LACK);
                    m_pMaster->SendMsgToClient(proto_ff::LOGIC_TO_CLIENT_CHAT_MSG_RSP, chatMsgRsp);
                    return 0;
                }
            }
            else if (proto_ff::CHAT_CHANNEL_SCENE == channelID)
            {
                if (m_pMaster->GetAttr(proto_ff::A_LEVEL) < ChatDescEx::Instance()->SceneLevLimit())
                {
                    chatMsgRsp.set_ret(proto_ff::RET_LEVEL_LACK);
                    m_pMaster->SendMsgToClient(proto_ff::LOGIC_TO_CLIENT_CHAT_MSG_RSP, chatMsgRsp);
                    return 0;
                }
            }
            else if (proto_ff::CHAT_CHANNEL_CLAN3 == channelID)
            {
                if (NFClanMgr::Instance(m_pObjPluginManager)->GetClan3Id(m_pMaster->Cid()) <= 0)
                {
                    chatMsgRsp.set_ret(proto_ff::RET_CLAN_NO_CLAN3);
                    m_pMaster->SendMsgToClient(proto_ff::LOGIC_TO_CLIENT_CHAT_MSG_RSP, chatMsgRsp);
                    return 0;
                }
            }
            else if (proto_ff::CHAT_CHANNEL_CLAN5 == channelID)
            {
                if (NFClanMgr::Instance(m_pObjPluginManager)->GetClan5Id(m_pMaster->Cid()) <= 0)
                {
                    chatMsgRsp.set_ret(proto_ff::RET_CLAN_NO_CLAN5);
                    m_pMaster->SendMsgToClient(proto_ff::LOGIC_TO_CLIENT_CHAT_MSG_RSP, chatMsgRsp);
                    return 0;
                }
            }
            //
            if (!InChannelCdTime(channelID))
            {
                chatMsgRsp.set_ret(proto_ff::RET_CHAT_CD_TIME_LIMIT);
                m_pMaster->SendMsgToClient(proto_ff::LOGIC_TO_CLIENT_CHAT_MSG_RSP, chatMsgRsp);
                return 0;
            }
            break;
        }
        default:
            break;
    }

    proto_ff::GCChatMsgRsp a2cChatMsg; //直接发送给客户端
    proto_ff::GWChatMsgReq g2wChatMsg; //向中心服请求

    proto_ff::RolePlayerMiniInfo* playerMiniInfo = a2cChatMsg.mutable_fromplayerinfo();
    if (nullptr == playerMiniInfo)
    {
        NFLogErrorFmt(NF_LOG_SYSTEMLOG, m_pMaster->Cid(), "[logic] ChatPart::HandleChatMsgReq..nullptr == playerMiniInfo..cid:%lu,channel:%u", fromID, (uint32_t)channelID);
        return 0;
    }

    NFChatMgr::InitPlayerMiniInfoStruct(m_pMaster, *playerMiniInfo);

    a2cChatMsg.set_channel(channelID);
    a2cChatMsg.mutable_chatcontent()->CopyFrom(c2gChatMsg.chatcontent());
    a2cChatMsg.set_msgtype(c2gChatMsg.msgtype());

    g2wChatMsg.set_channel(channelID);
    g2wChatMsg.set_msgtype(c2gChatMsg.msgtype());
    g2wChatMsg.mutable_chatcontent()->CopyFrom(c2gChatMsg.chatcontent());
    g2wChatMsg.set_fromid(fromID);
    g2wChatMsg.set_targetid(targetID);

    switch (channelID)
    {
        case proto_ff::CHAT_CHANNEL_ENLIST: //组队招募的
        case proto_ff::CHAT_CHANNEL_TEAM:   //队伍频道
        case proto_ff::CHAT_CHANNEL_CROSS:  //跨服频道
        {
            if (proto_ff::CHAT_CHANNEL_CROSS == channelID)
            {
                //todo:need ServerHornServerHornCfgInfo
                if (hornId > 0)
                {
                    /*const ServerHornServerHornCfgInfo *pHornCfg = g_GetServerHornServerHornCfgTable()->GetServerHornServerHornCfgInfo(hornId);
                    if (nullptr == pHornCfg)
                    {
                        NFLogErrorFmt(NF_LOG_SYSTEMLOG, m_pMaster->Cid(), "[logic] ChatPart::HandleChatMsgReq....nullptr == pHornCfg and hornid > 0...cid:%lu,hornid:%ld",fromID,hornId);
                        return;
                    }
                    if (rmvHornFlag)
                    {
                        PackagePart *pPackagePart = dynamic_cast<PackagePart*>(m_pMaster->GetPart(PART_PACKAGE));
                        if (nullptr == pPackagePart)
                        {
                            NFLogErrorFmt(NF_LOG_SYSTEMLOG, m_pMaster->Cid(), "[logic] ChatPart::HandleChatMsgReq....nullptr == pPackagePart111...cid:%lu, hornid:%ld", fromID, hornId);
                            return;
                        }
                        LIST_ITEM lstItem;
                        SItem item;
                        item.nItemID = pHornCfg->itemid;
                        item.nNum = 1;
                        item.byBind = (uint8_t)EBindState::EBindState_all;
                        lstItem.push_back(item);
                        pPackagePart->RemoveItem(lstItem, sourceParam);
                    }
                    else if (pHornCfg->currencyCost > 0)
                    {
                        //1-?????2-????
                        if (1 == pHornCfg->currencyType)
                        {
                            m_pMaster->AddAttr(A_DIA, -pHornCfg->currencyCost, &sourceParam,true);
                        }
                        else if (2 == pHornCfg->currencyType)
                        {
                            m_pMaster->AddAttr(A_BD_DIA, -pHornCfg->currencyCost, &sourceParam, true);
                        }
                    }*/
                }
                else
                {
                    //面已经校验过条件，这里直接扣除
                    if (ChatDescEx::Instance()->CrossChatCostBDia() > 0)
                    {
                        int64_t cost = -1 * ChatDescEx::Instance()->CrossChatCostBDia();
                        m_pMaster->AddAttr(proto_ff::A_BD_DIA, cost, &sourceParam, true);
                    }
                }
            }
            else if (proto_ff::CHAT_CHANNEL_ENLIST == channelID)
            {
                //上面已经校验过条件，这里直接扣除
                if (ChatDescEx::Instance()->TeamEnlistCostBindDia() > 0)
                {
                    int64_t cost = -1 * ChatDescEx::Instance()->TeamEnlistCostBindDia();
                    m_pMaster->AddAttr(proto_ff::A_BD_DIA, cost, &sourceParam, true);
                }
            }

            if (proto_ff::CHAT_CHANNEL_TEAM == channelID
                || (proto_ff::CHAT_CHANNEL_CROSS == channelID && hornId <= 0)
            )
            {
                if (virForbidFlag)
                {
                    m_pMaster->SendMsgToClient(proto_ff::LOGIC_TO_CLIENT_CHAT_MSG_RSP, a2cChatMsg);
                    break;
                }
            }

            proto_ff::TransChatCrossServerProto proto;
            playerMiniInfo = proto.mutable_fromplayerinfo();
            proto.set_channel(channelID);
            NFChatMgr::InitPlayerMiniInfoStruct(m_pMaster, *playerMiniInfo);
            proto.mutable_chatcontent()->CopyFrom(c2gChatMsg.chatcontent());
            m_pMaster->SendMsgToSnsServer(proto_ff::SERVER_TO_SERVER_CROSS_CHAT, proto);
            break;
        }
        case proto_ff::CHAT_CHANNEL_WORLD: //世界频道
        {
            //世界聊天发言一次触发成就
            proto_ff::ChatWorldEvent chatWorldEvent;
            FireExecute(NF_ST_LOGIC_SERVER, EVENT_CHAT, CREATURE_PLAYER, m_pMaster->Cid(), chatWorldEvent);
            if (virForbidFlag)
            {
                m_pMaster->SendMsgToClient(proto_ff::LOGIC_TO_CLIENT_CHAT_MSG_RSP, a2cChatMsg);
                break;
            }
            m_pMaster->SendMsgToSnsServer(proto_ff::CENTER_SERVER_PROTOCOL_CHAT_REQ, g2wChatMsg);
            break;
        }
        case proto_ff::CHAT_CHANNEL_GUILD:
        case proto_ff::CHAT_CHANNEL_POKERROOM:
        {
            if (proto_ff::CHAT_CHANNEL_GUILD == channelID)
            {
                bool rightflag = false; //
                /*if (m_pMaster->GetAttr(proto_ff::A_DUP_ID) == (int64_t)g_GetDupCfgMgr()->GetLandDupId() &&
                    g_GetLActMgr()->IsOpenByType((int32_t)EActType::dinner, m_pMaster->GetZid())
                )
                {
                    LandDup* pdup = dynamic_cast<LandDup *>(g_GetDupMgr()->GetDup(m_pMaster->GetSceneId()));
                    if (nullptr != pdup)
                    {
                        bool cananswer = false; //
                        int32_t curnum = 0;
                        rightflag = pdup->IsFirstAnswer(m_pMaster->Cid(), c2gChatMsg.chatcontent().describes(), curnum, cananswer);
                        //LogDebugFmtPrint("[logic] ChatPart::HandleChatMsgReq...cid:%lu,curnum:%d,cananswer:%d", m_pMaster->Cid(), curnum, cananswer);
                        if (cananswer)
                            g2wChatMsg.set_curnum(curnum);
                    }
                }*/
                a2cChatMsg.set_right(rightflag);
                g2wChatMsg.set_right(rightflag);
                if (virForbidFlag)
                {
                    m_pMaster->SendMsgToClient(proto_ff::LOGIC_TO_CLIENT_CHAT_MSG_RSP, a2cChatMsg);
                    break;
                }
            }
            m_pMaster->SendMsgToSnsServer(proto_ff::CENTER_SERVER_PROTOCOL_CHAT_REQ, g2wChatMsg);
            break;
        }
        case proto_ff::CHAT_CHANNEL_CLAN3:
        case proto_ff::CHAT_CHANNEL_CLAN5:
        {
            if (virForbidFlag)
            {
                a2cChatMsg.set_ret(proto_ff::RET_CHAT_CD_NoSpeakIng);
                m_pMaster->SendMsgToClient(proto_ff::LOGIC_TO_CLIENT_CHAT_MSG_RSP, a2cChatMsg);
                break;
            }
            m_pMaster->SendMsgToSnsServer(proto_ff::CENTER_SERVER_PROTOCOL_CHAT_REQ, g2wChatMsg);
        }
        break;
        case proto_ff::CHAT_CHANNEL_SCENE: ///场景聊天
        {
            if (virForbidFlag)
            {
                a2cChatMsg.set_ret(proto_ff::RET_CHAT_CD_NoSpeakIng);
                m_pMaster->SendMsgToClient(proto_ff::LOGIC_TO_CLIENT_CHAT_MSG_RSP, a2cChatMsg);
                break;
            }
            m_pMaster->SendMsgToGameServer(proto_ff::CENTER_SERVER_PROTOCOL_CHAT_REQ, g2wChatMsg);
        }
        break;
        case proto_ff::CHAT_CHANNEL_PRIVATE: //私聊
        {
            m_pMaster->SendMsgToSnsServer(proto_ff::CENTER_SERVER_PROTOCOL_CHAT_REQ, g2wChatMsg);
            break;
        }
        default:
            break;
    }
    return 0;
}

bool NFChatPart::InChannelCdTime(uint32_t channelID)
{
    uint64_t nowTime = NFTime::Now().UnixSec();
    if (channelID == proto_ff::CHAT_CHANNEL_WORLD)
    {
        //?????????????????CD?ж????????????????в???????CD????2??
        if (nowTime - worldCdTime >= (CHAT_WORLD_CD_TIME - 2))
        {
            worldCdTime = nowTime;
            return true;
        }
    }
    else if (channelID == proto_ff::CHAT_CHANNEL_CROSS)
    {
        if (nowTime - crossCdTime >= (CHAT_OTHER_CD_TIME - 2))
        {
            crossCdTime = nowTime;
            return true;
        }
    }
    else if (channelID == proto_ff::CHAT_CHANNEL_GUILD)
    {
        if (nowTime - guildCdTime >= CHAT_OTHER_CD_TIME)
        {
            guildCdTime = nowTime;
            return true;
        }
    }
    else if (channelID == proto_ff::CHAT_CHANNEL_TEAM)
    {
        if (nowTime - teamCdTime >= CHAT_OTHER_CD_TIME)
        {
            teamCdTime = nowTime;
            return true;
        }
    }
    else if (channelID == proto_ff::CHAT_CHANNEL_ENLIST)
    {
        if (nowTime - enlistCdTime >= (CHAT_OTHER_CD_TIME - 2))
        {
            enlistCdTime = nowTime;
            return true;
        }
    }
    else if (channelID == proto_ff::CHAT_CHANNEL_SCENE)
    {
        if (nowTime - sceneCdTime >= CHAT_OTHER_CD_TIME)
        {
            sceneCdTime = nowTime;
            return true;
        }
    }

    return false;
}
