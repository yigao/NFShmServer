// -------------------------------------------------------------------------
//    @FileName         :    NFTitlePart.cpp
//    @Author           :    gaoyi
//    @Date             :    23-2-21
//    @Email			:    445267987@qq.com
//    @Module           :    NFTitlePart
//
// -------------------------------------------------------------------------

#include "NFTitlePart.h"
#include "NFLogicCommon/NFRoleDefine.h"
#include "ClientServerCmd.pb.h"
#include "ClientServer.pb.h"
#include "Player/NFPlayer.h"
#include "NFPackagePart.h"
#include "NFComm/NFCore/NFCommonApi.h"

IMPLEMENT_IDCREATE_WITHTYPE(NFTitlePart, EOT_LOGIC_TITLE_PART_ID, NFShmObj)

NFTitlePart::NFTitlePart()
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

NFTitlePart::~NFTitlePart()
{
}

int NFTitlePart::CreateInit()
{
    m_curWearingTitle = 0;
    return 0;
}

int NFTitlePart::ResumeInit()
{
    return 0;
}

int NFTitlePart::RegisterClientMessage(NFIPluginManager *pPluginManager)
{
    RegisterClientPartMsg(pPluginManager, proto_ff::CLIENT_TO_LOGIC_TITLE_INFO_REQ, PART_TITLE);
    RegisterClientPartMsg(pPluginManager, proto_ff::CLIENT_TO_LOGIC_TITLE_ACTIVE_REQ, PART_TITLE);
    RegisterClientPartMsg(pPluginManager, proto_ff::CLIENT_TO_LOGIC_TITLE_STAR_LV_REQ, PART_TITLE);
    RegisterClientPartMsg(pPluginManager, proto_ff::CLIENT_TO_LOGIC_TITLE_DRESS_REQ, PART_TITLE);
    RegisterClientPartMsg(pPluginManager, proto_ff::CLIENT_TO_LOGIC_TITLE_UNDRESS_REQ, PART_TITLE);
    return 0;
}

int NFTitlePart::RegisterServerMessage(NFIPluginManager *pPluginManager)
{
    return 0;
}

int NFTitlePart::OnHandleClientMessage(uint32_t msgId, NFDataPackage &packet)
{
    switch (msgId)
    {
        case proto_ff::CLIENT_TO_LOGIC_TITLE_INFO_REQ:
            OnHandleTitleInfoReq(msgId, packet);
            break;
        case proto_ff::CLIENT_TO_LOGIC_TITLE_ACTIVE_REQ:
            OnHandleTitleActiveReq(msgId, packet);
            break;
        case proto_ff::CLIENT_TO_LOGIC_TITLE_STAR_LV_REQ:
            OnHandleTitleStarLvReq(msgId, packet);
            break;
        case proto_ff::CLIENT_TO_LOGIC_TITLE_DRESS_REQ:
            OnHandleTitleDressReq(msgId, packet);
            break;
        case proto_ff::CLIENT_TO_LOGIC_TITLE_UNDRESS_REQ:
            OnHandleTitleUnDressReq(msgId, packet);
            break;
        default: break;
    }
    return 0;
}

int NFTitlePart::OnHandleServerMessage(uint32_t msgId, NFDataPackage &packet)
{
    return 0;
}

proto_ff_s::TitleInfo_s *NFTitlePart::GetTitleInfo(uint64_t titleId)
{
    auto iter = m_titleMap.find(titleId);
    if (iter != m_titleMap.end())
    {
        return &iter->second;
    }
    return nullptr;
}

int NFTitlePart::OnHandleTitleInfoReq(uint32_t msgId, NFDataPackage &packet)
{
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "--- begin -- ");
    proto_ff::CGTitleInfoReq xData;
    CLIENT_MSG_PROCESS_WITH_PRINTF(packet, xData);

    proto_ff::GCTitleInfoRsp rsp;
    rsp.set_cur_wearing_title(m_curWearingTitle);
    for(auto iter = m_titleMap.begin(); iter != m_titleMap.end(); ++iter)
    {
        auto pData = rsp.add_data();
        iter->second.write_to_pbmsg(*pData);
    }

    m_pMaster->SendMsgToClient(proto_ff::LOGIC_TO_CLIENT_TITLE_INFO_RSP, rsp);
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "--- end -- ");
    return 0;
}

int NFTitlePart::OnHandleTitleActiveReq(uint32_t msgId, NFDataPackage &packet)
{
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "--- begin -- ");
    proto_ff::CGTitleInfoActiveReq xData;
    CLIENT_MSG_PROCESS_WITH_PRINTF(packet, xData);

    proto_ff::GCTitleInfoActiveRsp rsp;
    rsp.set_ret_code(proto_ff::RET_SUCCESS);

    proto_ff_s::TitleInfo_s* pInfo = GetTitleInfo(xData.title_id());
    if (pInfo == NULL)
    {
        rsp.set_ret_code(proto_ff::RET_CONFIG_ERROR);
        m_pMaster->SendMsgToClient(proto_ff::LOGIC_TO_CLIENT_TITLE_ACTIVE_RSP, rsp);
        return -1;
    }

    if (pInfo->status != proto_ff::E_TITLE_STATUS_CAN_ACTIVE)
    {
        rsp.set_ret_code(proto_ff::RET_CONFIG_ERROR);
        m_pMaster->SendMsgToClient(proto_ff::LOGIC_TO_CLIENT_TITLE_ACTIVE_RSP, rsp);
        return -1;
    }

    auto *pCfgInfo = TitleTitleDesc::Instance(m_pObjPluginManager)->GetDesc(xData.title_id());
    if (pCfgInfo == NULL)
    {
        rsp.set_ret_code(proto_ff::RET_CONFIG_ERROR);
        m_pMaster->SendMsgToClient(proto_ff::LOGIC_TO_CLIENT_TITLE_ACTIVE_RSP, rsp);
        return -1;
    }

    NFPackagePart* pPackagePart = dynamic_cast<NFPackagePart*>(m_pMaster->GetPart(PART_PACKAGE));
    if (pPackagePart == NULL)
    {
        rsp.set_ret_code(proto_ff::RET_CONFIG_ERROR);
        m_pMaster->SendMsgToClient(proto_ff::LOGIC_TO_CLIENT_TITLE_ACTIVE_RSP, rsp);
        return -1;
    }

    if (pCfgInfo->m_activationitem > 0 && pCfgInfo->m_activationnum > 0)
    {
        LIST_ITEM lstItem;
        lstItem.push_back(SItem(pCfgInfo->m_activationitem, pCfgInfo->m_activationnum, EBindState::EBindState_no));

        SCommonSource src;
        if (!pPackagePart->RemoveItem(lstItem, src))
        {
            rsp.set_ret_code(proto_ff::RET_PACKAGE_ITEM_NUM_LACK);
            m_pMaster->SendMsgToClient(proto_ff::LOGIC_TO_CLIENT_TITLE_ACTIVE_RSP, rsp);
            return -1;
        }
    }

    pInfo->status = proto_ff::E_TITLE_STATUS_ACTIVED;
    MarkDirty();

    pInfo->write_to_pbmsg(*rsp.mutable_data());

    m_pMaster->SendMsgToClient(proto_ff::LOGIC_TO_CLIENT_TITLE_ACTIVE_RSP, rsp);
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "--- end -- ");
    return 0;
}

int NFTitlePart::OnHandleTitleStarLvReq(uint32_t msgId, NFDataPackage &packet)
{
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "--- begin -- ");
    proto_ff::CGTitleStarLvReq xData;
    CLIENT_MSG_PROCESS_WITH_PRINTF(packet, xData);

    proto_ff::GCTitleStarLvRsp rsp;
    rsp.set_ret_code(proto_ff::RET_SUCCESS);

    proto_ff_s::TitleInfo_s* pInfo = GetTitleInfo(xData.title_id());
    if (pInfo == NULL)
    {
        rsp.set_ret_code(proto_ff::RET_CONFIG_ERROR);
        m_pMaster->SendMsgToClient(proto_ff::LOGIC_TO_CLIENT_TITLE_STAR_LV_RSP, rsp);
        return -1;
    }

    if (pInfo->status < proto_ff::E_TITLE_STATUS_ACTIVED)
    {
        rsp.set_ret_code(proto_ff::RET_CONFIG_ERROR);
        m_pMaster->SendMsgToClient(proto_ff::LOGIC_TO_CLIENT_TITLE_STAR_LV_RSP, rsp);
        return -1;
    }

    auto *pCfgInfo = TitleTitleDesc::Instance(m_pObjPluginManager)->GetDesc(xData.title_id());
    if (pCfgInfo == NULL)
    {
        rsp.set_ret_code(proto_ff::RET_CONFIG_ERROR);
        m_pMaster->SendMsgToClient(proto_ff::LOGIC_TO_CLIENT_TITLE_STAR_LV_RSP, rsp);
        return -1;
    }

    NFPackagePart* pPackagePart = dynamic_cast<NFPackagePart*>(m_pMaster->GetPart(PART_PACKAGE));
    if (pPackagePart == NULL)
    {
        rsp.set_ret_code(proto_ff::RET_CONFIG_ERROR);
        m_pMaster->SendMsgToClient(proto_ff::LOGIC_TO_CLIENT_TITLE_STAR_LV_RSP, rsp);
        return -1;
    }

    SCommonSource sourceParam;
    sourceParam.param1 = xData.title_id();
    sourceParam.param2 = pInfo->star;
    VEC_INT32 vecNum;
    NFCommonApi::SplitStrToVecInt(pCfgInfo->m_starnum.ToString(), ";", &vecNum);
    if ((int32_t) vecNum.size() < (int32_t)pCfgInfo->m_starup || (int32_t)pInfo->star >= (int32_t)vecNum.size())
    {
        rsp.set_ret_code(proto_ff::RET_CONFIG_ERROR);
        m_pMaster->SendMsgToClient(proto_ff::LOGIC_TO_CLIENT_TITLE_STAR_LV_RSP, rsp);
        return -1;
    }

    LIST_ITEM lstItem;
    SItem item;
    item.nItemID = pCfgInfo->m_starid;
    item.nNum = vecNum[pInfo->star];
    item.byBind = EBindState_all;
    lstItem.push_back(item);

    if (!pPackagePart->RemoveItem(lstItem, sourceParam))
    {
        rsp.set_ret_code(proto_ff::RET_PACKAGE_ITEM_NUM_LACK);
        m_pMaster->SendMsgToClient(proto_ff::LOGIC_TO_CLIENT_TITLE_STAR_LV_RSP, rsp);
        return -1;
    }

    ProcessStarAttr(xData.title_id(), pInfo->star, false, false);
    pInfo->star = pInfo->star + 1;
    ProcessStarAttr(xData.title_id(), pInfo->star, true, true);
    MarkDirty();

    m_pMaster->SendMsgToClient(proto_ff::LOGIC_TO_CLIENT_TITLE_STAR_LV_RSP, rsp);
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "--- end -- ");
    return 0;
}

int NFTitlePart::OnHandleTitleDressReq(uint32_t msgId, NFDataPackage &packet)
{
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "--- begin -- ");
    proto_ff::CGTitleDressReq xData;
    CLIENT_MSG_PROCESS_WITH_PRINTF(packet, xData);

    proto_ff::GCTitleDressRsp rsp;
    rsp.set_ret_code(proto_ff::RET_SUCCESS);

    auto pInfo = GetTitleInfo(xData.title_id());
    if (pInfo == NULL)
    {
        rsp.set_ret_code(proto_ff::RET_CONFIG_ERROR);
        m_pMaster->SendMsgToClient(proto_ff::LOGIC_TO_CLIENT_TITLE_DRESS_RSP, rsp);
        return -1;
    }

    if (pInfo->status != proto_ff::E_TITLE_STATUS_ACTIVED)
    {
        rsp.set_ret_code(proto_ff::RET_CONFIG_ERROR);
        m_pMaster->SendMsgToClient(proto_ff::LOGIC_TO_CLIENT_TITLE_DRESS_RSP, rsp);
        return -1;
    }

    if (m_curWearingTitle != 0)
    {
        UnDress(xData.title_id());
    }

    m_curWearingTitle = 0;
    MarkDirty();
    OnDress(xData.title_id());
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "--- end -- ");
    return 0;
}

int NFTitlePart::OnHandleTitleUnDressReq(uint32_t msgId, NFDataPackage &packet)
{
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "--- begin -- ");
    proto_ff::CGTitleUnDressReq xData;
    CLIENT_MSG_PROCESS_WITH_PRINTF(packet, xData);

    UnDress(xData.title_id());
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "--- end -- ");
    return 0;
}

void NFTitlePart::OnDress(uint64_t titleId)
{
    proto_ff::GCTitleDressRsp rsp;
    rsp.set_ret_code(proto_ff::RET_SUCCESS);

    auto pInfo = GetTitleInfo(titleId);
    if (pInfo == NULL)
    {
        rsp.set_ret_code(proto_ff::RET_CONFIG_ERROR);
        m_pMaster->SendMsgToClient(proto_ff::LOGIC_TO_CLIENT_TITLE_DRESS_RSP, rsp);
        return;
    }

    if (m_curWearingTitle != 0)
    {
        rsp.set_ret_code(proto_ff::RET_CONFIG_ERROR);
        m_pMaster->SendMsgToClient(proto_ff::LOGIC_TO_CLIENT_TITLE_DRESS_RSP, rsp);
        return;
    }

    m_curWearingTitle = titleId;
    pInfo->status = proto_ff::E_TITLE_STATUS_WEARING;
    MarkDirty();

    rsp.set_cur_wearing_title(m_curWearingTitle);
    pInfo->write_to_pbmsg(*rsp.mutable_data());
    m_pMaster->SendMsgToClient(proto_ff::LOGIC_TO_CLIENT_TITLE_DRESS_RSP, rsp);
}

void NFTitlePart::UnDress(uint64_t titleId)
{
    proto_ff::GCTitleUnDressRsp rsp;
    rsp.set_ret_code(proto_ff::RET_SUCCESS);

    if (m_curWearingTitle != titleId)
    {
        rsp.set_ret_code(proto_ff::RET_CONFIG_ERROR);
        m_pMaster->SendMsgToClient(proto_ff::LOGIC_TO_CLIENT_TITLE_UNDRESS_RSP, rsp);
        return;
    }

    auto pInfo = GetTitleInfo(titleId);
    if (pInfo == NULL)
    {
        rsp.set_ret_code(proto_ff::RET_CONFIG_ERROR);
        m_pMaster->SendMsgToClient(proto_ff::LOGIC_TO_CLIENT_TITLE_UNDRESS_RSP, rsp);
        return;
    }

    if (pInfo->status != proto_ff::E_TITLE_STATUS_WEARING)
    {
        rsp.set_ret_code(proto_ff::RET_CONFIG_ERROR);
        m_pMaster->SendMsgToClient(proto_ff::LOGIC_TO_CLIENT_TITLE_UNDRESS_RSP, rsp);
        return;
    }

    m_curWearingTitle = 0;
    pInfo->status = proto_ff::E_TITLE_STATUS_ACTIVED;
    MarkDirty();

    rsp.set_cur_wearing_title(m_curWearingTitle);
    pInfo->write_to_pbmsg(*rsp.mutable_data());
    m_pMaster->SendMsgToClient(proto_ff::LOGIC_TO_CLIENT_TITLE_UNDRESS_RSP, rsp);
}

int NFTitlePart::Init(NFPlayer *pMaster, uint32_t partType, const proto_ff::RoleDBData &dbData)
{
    NFPart::Init(pMaster, partType, dbData);
    if (dbData.has_title())
    {
        for(int i = 0; i < (int)dbData.title().data_size(); i++)
        {
            const ::proto_ff::TitleInfo& titleInfo = dbData.title().data(i);
            m_titleMap[titleInfo.title_id()].read_from_pbmsg(titleInfo);
        }

        m_curWearingTitle = dbData.title().cur_wearing_title();
    }
    else {
        LoadConfig();
    }
    return 0;
}

void NFTitlePart::LoadConfig()
{
    auto pTitleMap = TitleTitleDesc::Instance(m_pObjPluginManager)->GetResDescPtr();
    for(auto iter = pTitleMap->begin(); iter != pTitleMap->end(); ++iter)
    {
        auto *pTitleCfg = &(*iter);
        proto_ff_s::TitleInfo_s* pTitleInfo = &m_titleMap[pTitleCfg->m_id];
        pTitleInfo->title_id = pTitleCfg->m_id;
        pTitleInfo->status = proto_ff::E_TITLE_STATUS_CAN_ACTIVE;
        pTitleInfo->star = 0;
        pTitleInfo->start_time = 0;
        pTitleInfo->end_time = 0;
    }
}

int NFTitlePart::UnInit()
{
    return NFPart::UnInit();
}

int NFTitlePart::SaveDB(proto_ff::RoleDBData &dbData)
{
    return NFPart::SaveDB(dbData);
}

int NFTitlePart::OnLogin()
{
    return NFPart::OnLogin();
}

int NFTitlePart::OnLogin(proto_ff::PlayerInfoRsp &playerInfo)
{
    return NFPart::OnLogin(playerInfo);
}

bool NFTitlePart::ProcessStarAttr(int64_t titleId, int32_t star, bool bAdd, bool bSync)
{
    auto *pCfg = TitleTitleDesc::Instance(m_pObjPluginManager)->GetDesc(titleId);
    if (pCfg == nullptr || star <= 0)
    {
        return false;
    }

    int coefficient = bAdd ? 1 : -1;
    for (int i = 0; i < (int) pCfg->m_attribute.size(); i++)
    {
        int nAttrId = pCfg->m_attribute.at(i).m_type;
        if (nAttrId > 0)
        {
            m_mapTypeAttr[EAttrType_StarAttr][nAttrId] +=
                    coefficient * pCfg->m_attribute.at(i).m_value * (1 + pCfg->m_starber / F_TEN_THOUSAND * (star - 1));
        }
    }

    calcAttr(bSync);
    return true;
}

void NFTitlePart::calcAttr(MAP_INT32_INT64 &outAttr)
{
    MAP_INT32_FLOAT floatAttr;
    for (auto it = m_mapTypeAttr.begin(); it != m_mapTypeAttr.end(); it++)
    {
        for (auto iter = it->second.begin(); iter != it->second.end(); iter++)
        {
            int32_t attrId = iter->first;
            int64_t value = iter->second;
            floatAttr[attrId] += value;
        }
    }

    //算出每个模块加成属性，向下取整
    for (auto &e: floatAttr)
    {
        outAttr[e.first] = (int32_t) floor(e.second);
    }

    PrintAttr(outAttr);
}

void NFTitlePart::calcAttr(bool sync)
{
    MAP_INT32_INT64 allAttr;
    MAP_INT32_INT64 partAttr;

    calcAttr(partAttr);
    MergeAttr(partAttr, allAttr);
    partAttr.clear();

    PrintAttr(allAttr);

    for (auto &e: allAttr)
    {
        m_pMaster->SetAttrGroupCache(proto_ff::EAttrGroup_Title, e.first, e.second);
    }

    if (sync)
    {
        m_pMaster->SynAttrToClient();
    }
}

void NFTitlePart::PrintAttr(MAP_INT32_INT64 &attr)
{

}

void NFTitlePart::MergeAttr(MAP_INT32_INT64 &src, MAP_INT32_INT64 &dst)
{
    for (auto &e: src)
    {
        dst[e.first] += e.second;
    }
}