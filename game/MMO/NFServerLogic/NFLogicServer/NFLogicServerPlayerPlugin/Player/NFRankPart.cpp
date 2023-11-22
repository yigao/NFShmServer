// -------------------------------------------------------------------------
//    @FileName         :    NFRankPart.cpp
//    @Author           :    gaoyi
//    @Date             :    23-10-20
//    @Email			:    445267987@qq.com
//    @Module           :    NFRankPart
//
// -------------------------------------------------------------------------

#include "NFRankPart.h"

#include <proto_svr_event.pb.h>
#include <Rank.pb.h>
#include <DescStore/DupDupDesc.h>
#include <Facade/NFEquipPart.h>
#include <NFLogicCommon/NFDupDefine.h>
#include <NFLogicCommon/NFEventDefine.h>

NFRankPart::NFRankPart()
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

NFRankPart::~NFRankPart()
{
}

int NFRankPart::CreateInit()
{
    return 0;
}

int NFRankPart::ResumeInit()
{
    return 0;
}

int NFRankPart::Init(NFPlayer* pMaster, uint32_t partType, const proto_ff::RoleDBData& dbData)
{
    NFPart::Init(pMaster, partType, dbData);
    Subscribe(NF_ST_LOGIC_SERVER, EVENT_EQUIP_SCORE_CHANGE, CREATURE_PLAYER, m_pMaster->Cid(), "RankPart");
    Subscribe(NF_ST_LOGIC_SERVER, EVENT_PASS_DUPLICATE, CREATURE_PLAYER, m_pMaster->Cid(), "RankPart");
    Subscribe(NF_ST_LOGIC_SERVER, EVENT_STONE_INLAY, CREATURE_PLAYER, m_pMaster->Cid(), "RankPart");
    Subscribe(NF_ST_LOGIC_SERVER, EVENT_WING_FIGHT_CHANGE, CREATURE_PLAYER, m_pMaster->Cid(), "RankPart");
    Subscribe(NF_ST_LOGIC_SERVER, EVENT_MOUNT_FIGHT_CHANGE, CREATURE_PLAYER, m_pMaster->Cid(), "RankPart");
    Subscribe(NF_ST_LOGIC_SERVER, EVENT_MAGIC_SUM_CHANGE, CREATURE_PLAYER, m_pMaster->Cid(), "RankPart");
    Subscribe(NF_ST_LOGIC_SERVER, EVENT_BATTLE_PASS_XIAN_CE, CREATURE_PLAYER, m_pMaster->Cid(), "RankPart");
    Subscribe(NF_ST_LOGIC_SERVER, EVENT_BATTLE_PASS_PASS_BAODING, CREATURE_PLAYER, m_pMaster->Cid(), "RankPart");
    Subscribe(NF_ST_LOGIC_SERVER, EVENT_BEAST_FIGHT_CHANGE, CREATURE_PLAYER, m_pMaster->Cid(), "RankPart");
    Subscribe(NF_ST_LOGIC_SERVER, EVENT_MARRY_EXPRESS_EXP, CREATURE_PLAYER, m_pMaster->Cid(), "RankPart");

    return 0;
}

int NFRankPart::UnInit()
{
    return 0;
}

int NFRankPart::OnExecute(uint32_t serverType, uint32_t nEventID, uint32_t bySrcType, uint64_t nSrcID, const google::protobuf::Message* pMessage)
{
    switch (nEventID)
    {
        case EVENT_EQUIP_SCORE_CHANGE:
        {
            const proto_ff::EquipScoreChangeEvent *pEvent = dynamic_cast<const proto_ff::EquipScoreChangeEvent *>(pMessage);
            if (pEvent)
            {
                UpdateRank(RANK_TYPE_EQUIP, pEvent->all_score());
            }
            break;
        }
        case EVENT_PASS_DUPLICATE:
        {
            const proto_ff::PassDupEvent *pPass = dynamic_cast<const proto_ff::PassDupEvent *>(pMessage);
            if (pPass)
            {
                //101 凡人修仙
                if (pPass->groupid() == EDupGroupID_tower)
                {
                    auto pCfgInfo = DupDupDesc::Instance()->GetDesc(pPass->dupid());
                    if (pCfgInfo)
                    {
                        UpdateRank(RANK_TYPE_FANGREN_XIUZHEN, pCfgInfo->m_layer);
                    }
                }
            }
            break;
        }
        case EVENT_STONE_INLAY:
        {
            const proto_ff::StoneInlayEvent *pEvent = dynamic_cast<const proto_ff::StoneInlayEvent *>(pMessage);
            if (pEvent)
            {
                UpdateRank(RANK_TYPE_BAOSHI_LEVEL, pEvent->total_level());
            }
            break;
        }
        case EVENT_WING_FIGHT_CHANGE:
        {
            const proto_ff::WingFightChgEvent *pEvent = dynamic_cast<const proto_ff::WingFightChgEvent *>(pMessage);
            if (pEvent)
            {
                UpdateRank(RANK_TYPE_WING_FIGHT, pEvent->fight());
            }
            break;
        }
        case EVENT_MOUNT_FIGHT_CHANGE:
        {
            const proto_ff::MountFightChgEvent *pEvent = dynamic_cast<const proto_ff::MountFightChgEvent *>(pMessage);
            if (pEvent)
            {
                UpdateRank(RANK_TYPE_MOUNT_FIGHT, pEvent->fight());
            }
            break;
        }
        case EVENT_MAGIC_SUM_CHANGE:
        {
            const proto_ff::MagicSumChangeEvent *pEvent = dynamic_cast<const proto_ff::MagicSumChangeEvent *>(pMessage);
            if (pEvent)
            {
                UpdateRank(RANK_TYPE_MOUNT_FIGHT, pEvent->sum());
            }
            break;
        }
        case EVENT_BATTLE_PASS_XIAN_CE:
        {
            const proto_ff::BattlePassXianCe *pEvent = dynamic_cast<const proto_ff::BattlePassXianCe *>(pMessage);
            if (pEvent)
            {
                UpdateRank(RANK_TYPE_BATTLE_PASS_XIANCE, pEvent->buy_status() + pEvent->lv() * 10000);
            }
            break;
        }
        case EVENT_BATTLE_PASS_PASS_BAODING:
        {
            const proto_ff::BattlePassBaoDing *pEvent = dynamic_cast<const proto_ff::BattlePassBaoDing *>(pMessage);
            if (pEvent)
            {
                UpdateRank(RANK_TYPE_BATTLE_PASS_BAODING, pEvent->buy_status() + pEvent->lv() * 10000);
            }
            break;
        }
        case EVENT_DEITY_FIGHT_CHANGE:
        {
            const proto_ff::DeityFightChgEvent *pEvent = dynamic_cast<const proto_ff::DeityFightChgEvent *>(pMessage);
            if (pEvent)
            {
                UpdateRank(RANK_TYPE_DEITY_FIGHT, pEvent->fight());
            }
            break;
        }
        case EVENT_BEAST_FIGHT_CHANGE:
        {
            const proto_ff::BeastFightChgEvent *pEvent = dynamic_cast<const proto_ff::BeastFightChgEvent *>(pMessage);
            if (pEvent)
            {
                UpdateRank(RANK_TYPE_BEAST_FIGHT, pEvent->fight());
            }
            break;
        }
        case EVENT_MARRY_EXPRESS_EXP:
        {
            const proto_ff::MarryExpressExpEvent *pEvent = dynamic_cast<const proto_ff::MarryExpressExpEvent *>(pMessage);
            if (pEvent)
            {
                UpdateRank(RANK_TYPE_BIAOBAI_VALUE, pEvent->exp());
            }
            break;
        }
        default:
            break;
    }
    return 0;
}

int NFRankPart::RegisterMessage()
{
    RegisterClientMessage(proto_ff::CLIENT_TO_LOGIC_RANK_DATA_REQ, true);
    return 0;
}

int NFRankPart::OnHandleClientMessage(uint32_t msgId, NFDataPackage &packet)
{
    switch (msgId) {
        case proto_ff::CLIENT_TO_LOGIC_RANK_DATA_REQ:
        {
            OnGetRankDataRequest(msgId, packet);
            break;
        }
        default:
            break;
    }
    return 0;
}

void NFRankPart::UpdateRank(enRankType rankType, uint64_t value, int64_t param1)
{
    proto_ff::GWUpdateRankReq req;
    req.set_ranktype(rankType);
    req.set_charid(m_pMaster->Cid());
    req.set_value(value);
    if (param1 > 0)
    {
        req.add_paramint(param1);
    }
    m_pMaster->SendMsgToSnsServer(proto_ff::LOGIC_TO_CENTER_UPDATERANK, req);
}

uint64_t NFRankPart::GetPlayerRankValue(uint32_t rankType)
{
    switch (rankType)
    {
        case RANK_TYPE_POWER:
        {
            return m_pMaster->GetAttr(proto_ff::A_FIGHT);
        }
        case RANK_TYPE_LEVEL:
        {
            return m_pMaster->GetAttr(proto_ff::A_LEVEL);
        }
        default:
            return 0;
    }
    return 0;
}

int NFRankPart::OnGetRankDataRequest(uint32_t msgId, NFDataPackage &packet)
{
    proto_ff::RankDataRequest req;
    CLIENT_MSG_PROCESS_WITH_PRINTF(packet, req);

    uint32_t rankType = req.ranktype();

    //发送请求到中心服
    proto_ff::GWRankDataReq rankDataReq;
    rankDataReq.set_ranktype(rankType);
    rankDataReq.set_charid(m_pMaster->Cid());
    rankDataReq.set_value(GetPlayerRankValue(rankType));
    m_pMaster->SendMsgToSnsServer(proto_ff::LOGIC_TO_CENTER_RANKDATA, rankDataReq);

    return true;
}
