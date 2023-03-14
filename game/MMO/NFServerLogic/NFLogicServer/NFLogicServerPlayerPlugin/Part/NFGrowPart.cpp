// -------------------------------------------------------------------------
//    @FileName         :    NFGrowPart.cpp
//    @Author           :    gaoyi
//    @Date             :    22-10-31
//    @Email			:    445267987@qq.com
//    @Module           :    NFGrowPart
//
// -------------------------------------------------------------------------

#include "NFGrowPart.h"
#include "Player/NFPlayer.h"
#include "ClientServerCmd.pb.h"

IMPLEMENT_IDCREATE_WITHTYPE(NFGrowPart, EOT_LOGIC_GROW_PART_ID, NFPart)

NFGrowPart::NFGrowPart() : NFPart()
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

NFGrowPart::~NFGrowPart()
{
}

int NFGrowPart::CreateInit()
{
    return 0;
}

int NFGrowPart::ResumeInit()
{
    return 0;
}

int NFGrowPart::Init(NFPlayer *pMaster, uint32_t partType, const proto_ff::RoleDBData &dbData)
{
    NFPart::Init(pMaster, partType, dbData);
    initParts();

    const proto_ff::GrowDBData &growDB = dbData.grow();
    int32_t partSize = growDB.parts_size();

    for (int32_t i = 0; i < partSize; i++)
    {
        const proto_ff::GrowPartDBData &partdb = growDB.parts(i);
        int32_t partEntrySize = partdb.entrys_size();
        GrowPartData tp;
        tp.type = partdb.type();
        tp.curId = partdb.curid();
        for (int32_t j = 0; j < partEntrySize; j++)
        {
            GrowPartEntry entry;
            entry.id = partdb.entrys(j).id();
            entry.lv = partdb.entrys(j).lv();
            tp.entryMap[entry.id] = entry;
        }
        m_partsMap[tp.type] = tp;
    }

    calcAttr(false);

    return 0;
}

int NFGrowPart::UnInit()
{
    return NFPart::UnInit();
}

int NFGrowPart::OnHandleClientMessage(uint32_t msgId, NFDataPackage &packet)
{
    return NFPart::OnHandleClientMessage(msgId, packet);
}

int NFGrowPart::OnHandleServerMessage(uint32_t msgId, NFDataPackage &packet)
{
    return NFPart::OnHandleServerMessage(msgId, packet);
}

int NFGrowPart::RegisterClientPartMsg(NFIPluginManager *pPluginManager, uint32_t nMsgID, uint32_t partType)
{
    return 0;
}

int NFGrowPart::RegisterServerPartMsg(NFIPluginManager *pPluginManager, uint32_t nMsgID, uint32_t partType)
{
    return 0;
}

void NFGrowPart::initParts()
{
    for (int32_t i = proto_ff::GrowType_MIN; i < proto_ff::GrowType_head; i++)
    {
        GrowPartData part;
        part.type = i;
        m_partsMap[i] = part;
    }
}

int NFGrowPart::SaveDB(proto_ff::RoleDBData &dbData)
{
    proto_ff::GrowDBData *pGrow = dbData.mutable_grow();
    CHECK_NULL(pGrow);
    for (auto &e: m_partsMap)
    {
        const GrowPartData &part = e.second;
        proto_ff::GrowPartDBData *pPartProto = pGrow->add_parts();

        pPartProto->set_type(part.type);
        pPartProto->set_curid(part.curId);

        for (auto &ie: part.entryMap)
        {
            proto_ff::GrowPartEntryDBInfo *pPartEntry = pPartProto->add_entrys();
            CHECK_NULL(pPartEntry);
            pPartEntry->set_id(ie.second.id);
            pPartEntry->set_lv(ie.second.lv);
        }
    }

    return 0;
}

int NFGrowPart::OnLogin()
{
    SendAllGrowData();
    return 0;
}

void NFGrowPart::calcAttr(bool sync)
{
    MAP_INT32_INT64 allAttr;
    MAP_INT32_INT64 partAttr;

    for (auto& e : m_partsMap)
    {
        calcAttr(e.first, partAttr);
        MergeAttr(partAttr, allAttr);
        partAttr.clear();
    }
    PrintAttr(0, allAttr);

    for (auto& e : allAttr)
    {
        m_pMaster->SetAttrGroupCache(proto_ff::EAttrGroup_Grow, e.first, e.second);
    }

    if (sync)
    {
        m_pMaster->SynAttrToClient();
    }
}



void NFGrowPart::calcAttr(int32_t type, MAP_INT32_INT64& outAttr)
{

}

void NFGrowPart::PrintAttr(int32_t type, MAP_INT32_INT64& attr)
{
}

void NFGrowPart::MergeAttr(MAP_INT32_INT64& src, MAP_INT32_INT64& dst)
{
    for (auto& e : src)
    {
        dst[e.first] += e.second;
    }
}

void NFGrowPart::SetFacadeProto(proto_ff::RoleFacadeProto& proto)
{
    for (auto& e : m_partsMap)
    {
        proto_ff::Attr64* at = proto.add_growfacade();
        if (at)
        {
            at->set_id(e.second.type);
            at->set_value(e.second.curId);
        }
    }
}

void NFGrowPart::SetEnterSceneProto(proto_ff::RoleEnterSceneData &outproto)
{
    NFPart::SetEnterSceneProto(outproto);
}

int NFGrowPart::FillProto(const NFGrowPart::GrowPartData &part, proto_ff::GrowSubInfo &proto)
{
    proto.set_type(part.type);

    for (auto& e : part.entryMap)
    {
        const GrowPartEntry& entry = e.second;
        proto_ff::GrowStarInfo* pStarProto = proto.add_subs();
        pStarProto->set_id(entry.id);
        pStarProto->set_lv(entry.lv);
        pStarProto->set_state(part.curId == entry.id ? 1 : 0);
    }
    return 0;
}

NFGrowPart::GrowPartData *NFGrowPart::getPart(int32_t type)
{
    auto iter = m_partsMap.find(type);
    return iter != m_partsMap.end() ? &(iter->second) : nullptr;
}

int NFGrowPart::SendAllGrowData()
{
    proto_ff::NotifyGrowRsp rsp;
    for (auto& e : m_partsMap)
    {
        const GrowPartData& part = e.second;
        proto_ff::GrowSubInfo* pSub = rsp.add_subs();
        CHECK_NULL(pSub);
        FillProto(part, *pSub);
    }
    m_pMaster->SendMsgToClient(proto_ff::NOTIFY_GROW_RSP, rsp);
    return 0;
}

int NFGrowPart::SendGrowPartData(int32_t type)
{
    GrowPartData* pPart = getPart(type);
    CHECK_NULL(pPart);

    proto_ff::NotifyGrowRsp rsp;
    proto_ff::GrowSubInfo* pSubProto = rsp.add_subs();
    CHECK_NULL(pSubProto);

    FillProto(*pPart, *pSubProto);
    m_pMaster->SendMsgToClient(proto_ff::NOTIFY_GROW_RSP, rsp);
    return 0;
}
