// -------------------------------------------------------------------------
//    @FileName         :    NFEquipPart.cpp
//    @Author           :    gaoyi
//    @Date             :    22-10-31
//    @Email			:    445267987@qq.com
//    @Module           :    NFEquipPart
//
// -------------------------------------------------------------------------

#include "NFEquipPart.h"
#include "CSEquip.pb.h"
#include "ClientServerCmd.pb.h"
#include "Player/NFPlayer.h"
#include "DescStore/EquipStoveattDesc.h"
#include "NFLogicCommon/NFAttrUtility.h"
#include "DescStore/AttributeAttributeDesc.h"
#include "DescStore/EquipGemDesc.h"
#include "DescStore/ItemItemDesc.h"
#include "NFComm/NFCore/NFCommonApi.h"
#include "DescStore/EquipClearDesc.h"

IMPLEMENT_IDCREATE_WITHTYPE(NFEquipPart, EOT_LOGIC_EQUIP_PART_ID, NFPart)

NFEquipPart::NFEquipPart() : NFPart()
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

NFEquipPart::~NFEquipPart()
{
}

int NFEquipPart::CreateInit()
{
    m_stoveLevel = 1;
    m_stoveExp = 0;
    m_equips.resize(m_equips.max_size());
    for (int32_t i = proto_ff::EEquipPos_none + 1; i < proto_ff::EEquipPos_limit; i++)
    {
        m_equips[i].slot.slot_pos = i;
        m_equips[i].pos = i;
        m_equips[i].slot.initStone();
        m_equips[i].slot.initWash();
        m_equips[i].slot.suitLv = 0;
    }
    return 0;
}

int NFEquipPart::ResumeInit()
{
    return 0;
}

int NFEquipPart::Init(NFPlayer *pMaster, uint32_t partType, const proto_ff::RoleDBData &dbData)
{
    NFPart::Init(pMaster, partType, dbData);

    const proto_ff::RoleDBEquipData &equipDB = dbData.equip();
    int32_t equipSize = equipDB.infos_size();

    for (int32_t i = 0; i < equipSize; i++)
    {
        const proto_ff::EquipInfo &equipProto = equipDB.infos(i);
        int32_t pos = equipProto.pos();
        CHECK_EXPR(ValidPos(pos), -1, "EquipPart::Init pos:{} error", pos);
        stDressEquipInfo *pDressEquip = GetEquip(pos);
        CHECK_EXPR(pDressEquip, false, "EquipPart::Init pos:%d not find equip", pos);
        pDressEquip->unpack(equipProto);
    }
    m_lvAttr.clear();

    for (int32_t i = 0; i < equipDB.lv_attr().size(); i++)
    {
        const proto_ff::EquipLvAttrInfo &ai = equipDB.lv_attr(i);
        stEquipLvAttrInfo t;
        t.type = ai.type();
        t.id = ai.id();
        m_lvAttr[t.type] = t;
    }

    if (equipDB.has_stove_level())
    {
        m_stoveLevel = equipDB.stove_level();
        m_stoveExp = equipDB.stove_exp();
        ProcessStoveAttr(m_stoveLevel, true, false);
    }
    else
    {
        m_stoveLevel = 1;
        m_stoveExp = 0;
        ProcessStoveAttr(m_stoveLevel, true, false);
    }

    calcAttr(false);
    return 0;
}

int NFEquipPart::UnInit()
{
    return NFPart::UnInit();
}

int NFEquipPart::SaveDB(proto_ff::RoleDBData &dbData)
{
    proto_ff::RoleDBEquipData *pProtoEquip = dbData.mutable_equip();
    CHECK_NULL(pProtoEquip);

    for (int32_t i = proto_ff::EEquipPos_none + 1; i < proto_ff::EEquipPos_limit; i++)
    {
        stDressEquipInfo *pDressEquip = GetEquip(i);
        CHECK_NULL(pDressEquip);
        pDressEquip->pack(pProtoEquip->add_infos());
    }

    for (auto &e: m_lvAttr)
    {
        proto_ff::EquipLvAttrInfo *pLvAttrProto = pProtoEquip->add_lv_attr();
        if (pLvAttrProto)
        {
            pLvAttrProto->set_type(e.second.type);
            pLvAttrProto->set_id(e.second.id);
        }

    }

    pProtoEquip->set_stove_level(m_stoveLevel);
    pProtoEquip->set_stove_exp(m_stoveExp);

    return 0;
}

int NFEquipPart::OnLogin()
{
    SendAllEquip();
    SendLvAttr();
    return 0;
}

void NFEquipPart::SetFacadeProto(proto_ff::RoleFacadeProto &outproto)
{
    NFPart::SetFacadeProto(outproto);
}

void NFEquipPart::SetEnterSceneProto(proto_ff::RoleEnterSceneData &outproto)
{
    NFPart::SetEnterSceneProto(outproto);
}

int NFEquipPart::OnHandleClientMessage(uint32_t msgId, NFDataPackage &packet)
{
    return NFPart::OnHandleClientMessage(msgId, packet);
}

int NFEquipPart::OnHandleServerMessage(uint32_t msgId, NFDataPackage &packet)
{
    return NFPart::OnHandleServerMessage(msgId, packet);
}

int NFEquipPart::RegisterClientMessage(NFIPluginManager *pPluginManager)
{
    return 0;
}

int NFEquipPart::RegisterServerMessage(NFIPluginManager *pPluginManager)
{
    return 0;
}

bool NFEquipPart::ValidPos(int32_t pos)
{
    if (pos > proto_ff::EEquipPos_none && pos < proto_ff::EEquipPos_limit)
    {
        return true;
    }
    return false;
}

stDressEquipInfo *NFEquipPart::GetEquip(int32_t pos)
{
    CHECK_EXPR(ValidPos(pos), nullptr, "pos:{}", pos);
    return &m_equips[pos];
}

int NFEquipPart::SendAllEquip()
{
    proto_ff::NotifyEquipInfoRsp rsp;
    rsp.set_type(0);
    for (int32_t i = proto_ff::EEquipPos_none + 1; i < proto_ff::EEquipPos_limit; i++)
    {
        stDressEquipInfo *pDressEquip = GetEquip(i);
        CHECK_EXPR_CONTINUE(pDressEquip, "");
        pDressEquip->pack(rsp.add_infos(), true);
    }
    m_pMaster->SendMsgToClient(proto_ff::NOTIFY_EQUIP_INFO_RSP, rsp);
    return 0;
}

int NFEquipPart::SendLvAttr()
{
    proto_ff::NotifyEquipLvAttrRsp rsp;
    for (auto &e: m_lvAttr)
    {
        proto_ff::EquipLvAttrInfo *pProto = rsp.add_lv_attr();
        if (pProto)
        {
            pProto->set_type(e.second.type);
            pProto->set_id(e.second.id);
        }
    }

    m_pMaster->SendMsgToClient(proto_ff::NOTIFY_EQUIP_LV_ATTR_RSP, rsp);
    return 0;
}

int NFEquipPart::ProcessStoveAttr(int32_t level, bool bAdd, bool bSync/* = true*/)
{
    CHECK_EXPR(level > 0, -1, "level:{}", level);
    auto pCfg = EquipStoveattDesc::GetDescStore()->GetDesc(level);
    CHECK_NULL(pCfg);

    int coefficient = bAdd ? 1 : -1;
    for (int i = 0; i < (int) pCfg->m_attribute.size(); i++)
    {
        int nAttrId = pCfg->m_attribute.at(i).m_type;
        m_mapStoveAttr[nAttrId] += pCfg->m_attribute.at(i).m_value * coefficient;
    }

    calcAttr(bSync);
    return true;
}

int NFEquipPart::calcAttr(bool sync)
{
    //计算身上装备属性
    MAP_INT32_INT64 allAttr;

    //计算身上的装备属性
    MAP_INT32_INT64 dressAttr;
    calcDressAttr(dressAttr);
    AttrOpt::MergeAttr(dressAttr, allAttr);

    //计算强化加成
    MAP_INT32_INT64 strongAttr;
    calcStrongAttr(strongAttr);
    AttrOpt::MergeAttr(strongAttr, allAttr);

    //计算宝石加成
    MAP_INT32_INT64 stoneAttr;
    calcStoneAttr(strongAttr);
    AttrOpt::MergeAttr(stoneAttr, allAttr);


    //计算总等级加成
    MAP_INT32_INT64 totalAttr;
    calcTotalAttr(totalAttr);
    AttrOpt::MergeAttr(totalAttr, allAttr);

    //计算熔炉属性
    MAP_INT32_INT64 stoveAttr;
    calcStoveAttr(stoveAttr);
    AttrOpt::MergeAttr(stoveAttr, allAttr);

    //计算洗练属性
    MAP_INT32_INT64 washAttr;
    calcWashAttr(washAttr);
    AttrOpt::MergeAttr(washAttr, allAttr);

    //计算套装属性
    MAP_INT32_INT64 suitAttr;
    calcSuitAttr(suitAttr);
    AttrOpt::MergeAttr(suitAttr, allAttr);

    for (auto &e: allAttr)
    {
        m_pMaster->SetAttrGroupCache(proto_ff::EAttrGroup_Equip, e.first, e.second);
    }

    AttrOpt::PrintAttr(allAttr, "allattr");
    if (sync)
    {
        m_pMaster->SynAttrToClient();
    }

    return 0;
}

int NFEquipPart::SendEquip(int32_t pos)
{
    proto_ff::NotifyEquipInfoRsp rsp;
    rsp.set_type(1);

    stDressEquipInfo *pDressEquip = GetEquip(pos);
    CHECK_NULL(pDressEquip);
    pDressEquip->pack(rsp.add_infos(), true);

    m_pMaster->SendMsgToClient(proto_ff::NOTIFY_EQUIP_INFO_RSP, rsp);
    return 0;
}

int NFEquipPart::SendEquip(VEC_INT16 vec_pos)
{
    proto_ff::NotifyEquipInfoRsp rsp;
    rsp.set_type(1);
    for (auto &e: vec_pos)
    {
        stDressEquipInfo *pDressEquip = GetEquip(e);
        CHECK_NULL(pDressEquip);
        pDressEquip->pack(rsp.add_infos());
    }

    m_pMaster->SendMsgToClient(proto_ff::NOTIFY_EQUIP_INFO_RSP, rsp);
    return 0;
}

int NFEquipPart::calcEquipScore(int32_t pos)
{
    stDressEquipInfo *pDressEquip = GetEquip(pos);
    CHECK_NULL(pDressEquip);
    if (!pDressEquip->m_equip.IsEquip())
    {
        pDressEquip->slot.total_score = 0;
        MarkDirty();
        return -1;
    }

    MAP_INT32_INT32 atts;
    pDressEquip->m_equip.GetAllAttr(atts, m_pMaster->GetAttr(proto_ff::A_LEVEL));

    float floatTotalScore = 0;
    for (auto &e: atts)
    {
        auto pAttrCfg = AttributeAttributeDesc::GetDescStore()->GetDesc(e.first);
        CHECK_EXPR_CONTINUE(pAttrCfg, "id:{}", e.first);
        floatTotalScore += pAttrCfg->m_power * e.second;
    }

    int32_t intTotalScore = floor(floatTotalScore);

    if (pDressEquip->slot.total_score != intTotalScore)
    {
        pDressEquip->slot.total_score = intTotalScore;
        MarkDirty();
    }

    return 0;
}

int NFEquipPart::calcDressAttr(MAP_INT32_INT64 &outAttr)
{
    int32_t lv = m_pMaster->GetAttr(proto_ff::A_LEVEL);
    MAP_INT32_INT32 partAttr;
    for (auto &e: m_equips)
    {
        e.m_equip.GetAllAttr(partAttr, lv);

        for (auto &e1: partAttr)
        {
            outAttr[e1.first] += e1.second;
        }
        partAttr.clear();
    }

    return 0;
}

int NFEquipPart::calcStrongAttr(MAP_INT32_INT64 &outAttr)
{
/*    for (auto &e: m_equips)
    {
        int32_t slotLv = e.slot.stronglv;
        if (slotLv == 0) continue;

        auto pEquipCfg = e.m_equip.GetEquipCfg();
        CHECK_EXPR_CONTINUE(pEquipCfg, "");

        int32_t pos = pEquipCfg->m_position;
        int32_t wearQuality = pEquipCfg->m_wearquality;
        stEquipStrongCfg *pEquipStrongCfg = g_GetEquipCfg()->GetStrongCfg(EQUIP_STRONG_ID(pos, wearQuality));
        CHECK_EXPR_CONTINUE(pEquipStrongCfg, "pos:{} wearQuality:{}", pos, wearQuality);

        for (auto &e1: pEquipStrongCfg->attr)
        {
            outAttr[e1.attrId] += e1.vec.at(0) * slotLv * slotLv + e1.vec.at(1) * slotLv + e1.vec.at(2);
        }
    }*/

    return 0;
}

int NFEquipPart::calcStoneAttr(MAP_INT32_INT64 &outAttr)
{
    for (auto &e: m_equips)
    {
        if (e.m_equip.GetItemID() <= 0)
            continue;

        auto pEquipCfg = e.m_equip.GetEquipCfg();
        CHECK_EXPR_CONTINUE(pEquipCfg, "");

        int32_t wearQ = pEquipCfg->m_wearquality;

        auto pGemCfg = EquipGemDesc::GetDescStore()->GetDesc(e.pos);
        CHECK_EXPR_CONTINUE(pGemCfg, "");

        for (auto &ie: e.slot.vec_stone)
        {
            CHECK_EXPR_CONTINUE(ie.stone_id > 0, "");

            auto pStoneCfg = ItemItemDesc::GetDescStore()->GetDesc(ie.stone_id);
            CHECK_EXPR_CONTINUE(pStoneCfg, "stone id:{}", ie.stone_id);

            if (ie.pos < MAX_STONE_SLOT - 1 && wearQ < pGemCfg->m_gemunlock.at(ie.pos))
            {
                continue;
            }
            else
            {
                if (e.slot.stone_pay_slot_open == 0)
                    continue;
            }

            VEC_INT64 v;
            NFCommonApi::SplitStrToVecInt(pStoneCfg->m_functionvalue.ToString(), ";", &v);
            if (v.size() % 2 != 0)
            {
                NFLogError(NF_LOG_SYSTEMLOG, m_pMaster->GetRoleId(), "EquipPart::calcStoneAttr stoneid:{} function value error", ie.stone_id);
                continue;
            }

            for (auto iter = v.begin(); iter != v.end(); iter += 2)
            {
                outAttr[*iter] += *(iter + 1);
            }
        }
    }

    return 0;
}

int NFEquipPart::calcTotalAttr(MAP_INT32_INT64 &outAttr)
{
    return 0;
}

int NFEquipPart::calcStoveAttr(MAP_INT32_INT64 &outAttr)
{
    return 0;
}

int NFEquipPart::calcWashAttr(MAP_INT32_INT64 &outAttr)
{
    for (auto &e: m_equips)
    {
        for (auto &ie: e.slot.vec_wash)
        {
            if (ie.id > 0)
            {
                outAttr[ie.id] += ie.value;
            }
        }

        int32_t reachQulity = e.slot.GetWashReachQulity();
        auto pClearCfg = EquipClearDesc::GetDescStore()->GetDesc(e.slot.slot_pos);
        CHECK_EXPR_CONTINUE(pClearCfg, "slot pos:{}", e.slot.slot_pos);

        for (uint32_t i = 0; i < pClearCfg->m_attribute.size(); i++)
        {
            VEC_INT32 va;
            NFCommonApi::SplitStrToVecInt(pClearCfg->m_attribute.at(i).m_value.ToString(), ";", &va);

            CHECK_EXPR(va.size() == 3, -1, "");
            if (va.at(0) == reachQulity)
            {
                outAttr[va.at(1)] += va.at(2);
                NFLogError(NF_LOG_SYSTEMLOG, m_pMaster->GetRoleId(), "EquipPart::calcWashAttr equip_pos:{} reachQulity:{}", e.slot.slot_pos,
                           reachQulity);
            }
        }
    }

    return 0;
}

int NFEquipPart::calcSuitAttr(MAP_INT32_INT64 &outAttr)
{
/*    MAP_INT32_INT64 suit1AttrMap;
    MAP_INT32_INT64 suit2AttrMap;
    //计算普通套装
    CalcSuitAttrEx(suit1AttrMap, GetComEquipVecPos(), 1);
    //计算仙器套装
    CalcSuitAttrEx(suit2AttrMap, GetXQEquipVecPos(), 2);
    AttrOpt::MergeAttr(suit1AttrMap, outAttr);
    AttrOpt::MergeAttr(suit2AttrMap, outAttr);*/

    return 0;
}

int NFEquipPart::CalcSuitAttrEx(MAP_INT32_INT64 &outAttr, const VEC_INT32 &vecPos, int32_t type)
{
/*    int32_t minSuitLv = GetSuitMinLv(vecPos);
    int32_t maxSuitLv = GetSuitMaxLv(vecPos);

    if (minSuitLv == maxSuitLv && minSuitLv == 0)return;

    int32_t minVaildSuitNum = VaildSuitNum(vecPos, minSuitLv);
    int32_t maxVaildSuitNum = VaildSuitNum(vecPos, maxSuitLv);

    //高级套装激活数量
    VEC_INT32 maxSuitVaildNumVec;

    const EquipSuitCfgInfo *pMaxSuitCfg = g_GetEquipCfg()->GetSuitCfgInfo(type, maxSuitLv);
    if (pMaxSuitCfg)
    {
        const VecEquipSuitAttributeCfg &maxEquipSuitCfg = pMaxSuitCfg->vecEquipSuitAttributeCfg;
        for (auto iter = maxEquipSuitCfg.begin(); iter != maxEquipSuitCfg.end(); iter++)
        {
            if (maxVaildSuitNum >= iter->sctivation)
            {
                maxSuitVaildNumVec.push_back(iter->sctivation);
                //加成高级套装属性

                std::vector<std::string> strResult;
                CommonApi::SplitStr(iter->value, "|", &strResult);
                for (uint32_t i = 0; i < strResult.size(); ++i)
                {
                    std::vector<int32_t> result;
                    CommonApi::SplitStrToVecInt(strResult[i], ";", &result);
                    if (result.size() == 2)
                    {
                        outAttr[result[0]] += result[1];
                    }

                }
            }
        }
    }

    //低级套装激活属性加成
    const EquipSuitCfgInfo *pMinSuitCfg = g_GetEquipCfg()->GetSuitCfgInfo(type, minSuitLv);
    if (pMinSuitCfg)
    {
        const VecEquipSuitAttributeCfg &minEquipSuitCfg = pMinSuitCfg->vecEquipSuitAttributeCfg;
        for (auto iter = minEquipSuitCfg.begin(); iter != minEquipSuitCfg.end(); iter++)
        {
            if (minVaildSuitNum >= iter->sctivation)
            {
                auto f_iter = std::find(maxSuitVaildNumVec.begin(), maxSuitVaildNumVec.end(), iter->sctivation);
                if (f_iter == maxSuitVaildNumVec.end())
                {
                    //加成低级套装属性
                    std::vector<std::string> strResult;
                    CommonApi::SplitStr(iter->value, "|", &strResult);
                    for (uint32_t i = 0; i < strResult.size(); ++i)
                    {
                        std::vector<int32_t> result;
                        CommonApi::SplitStrToVecInt(strResult[i], ";", &result);
                        if (result.size() == 2)
                        {
                            outAttr[result[0]] += result[1];
                        }
                    }
                }
            }
        }
    }*/

    return 0;
}
