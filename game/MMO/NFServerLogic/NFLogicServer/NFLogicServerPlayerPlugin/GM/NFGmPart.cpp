// -------------------------------------------------------------------------
//    @FileName         :    NFGmPart.cpp
//    @Author           :    gaoyi
//    @Date             :    23-12-12
//    @Email			:    445267987@qq.com
//    @Module           :    NFGmPart
//
// -------------------------------------------------------------------------

#include "NFGmPart.h"
#include "Gm.pb.h"
#include "Package/NFPackagePart.h"
#include "DescStore/RoleExpDesc.h"
#include "DescStore/MapMapDesc.h"
#include "NFLogicCommon/NFSceneDefine.h"
#include "DescStoreEx/MapDescEx.h"
#include "Player/NFMovePart.h"

NFGmPart::NFGmPart()
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

NFGmPart::~NFGmPart()
{
}

int NFGmPart::CreateInit()
{
    return 0;
}

int NFGmPart::ResumeInit()
{
    return 0;
}

int NFGmPart::RegisterMessage()
{
    RegisterServerMessage(proto_ff::NOTIFY_SERVER_GM_RSP, true);
    return 0;
}

int NFGmPart::OnHandleClientMessage(uint32_t msgId, NFDataPackage& packet)
{
    return NFPart::OnHandleClientMessage(msgId, packet);
}

int NFGmPart::OnHandleServerMessage(uint32_t msgId, NFDataPackage& packet)
{
    switch (msgId)
    {
        case proto_ff::NOTIFY_SERVER_GM_RSP:
        {
            OnHandleServerGmRsp(msgId, packet);
            break;
        }
        default:break;
    }
    return 0;
}

int NFGmPart::OnHandleServerGmRsp(uint32_t msgId, NFDataPackage& packet)
{
    proto_ff::NotifyGmRsp rsp;
    CLIENT_MSG_PROCESS_WITH_PRINTF(packet, rsp);
    VEC_STRING vecstr;
    string strargs;
    for (int32_t i = 0; i < rsp.arg_size(); ++i)
    {
        vecstr.push_back(rsp.arg(i));
        strargs += rsp.arg(i);
        strargs += ",";
    }
    
    NFLogInfoFmt(NF_LOG_SYSTEMLOG, m_pMaster->Cid(), "cid:%lu, cmd:%s, arg:%s ", m_pMaster->Cid(), rsp.cmd().c_str(), strargs.c_str());
    HandleGMCommand(rsp.cmd(), vecstr);
    return 0;
}

int NFGmPart::HandleGMCommand(const string& cmd, const VEC_STRING& vecarg)
{
    int iRet = 0;
    if (cmd == "get")
    {
        iRet = GetItem(vecarg);
    }
    else if (cmd == "lev")
    {
        iRet = UpgradeLevel(vecarg);
    }
    else if (cmd == "exp")
    {
        iRet = AddExp(vecarg);
    }
    else if (cmd == "gold")
    {
        iRet = AddGold(vecarg);
    }
    else if (cmd == "dia")
    {
        iRet = AddDia(vecarg);
    }
    else if (cmd == "bd_dia")
    {
        iRet = AddBdDia(vecarg);
    }
    else if (cmd == "magic")
    {
        iRet = AddMagic(vecarg);
    }
    else if (cmd == "hunling")
    {
        iRet = AddHunLing(vecarg);
    }
    else if (cmd == "prestige")
    {
        iRet = AddPrestige(vecarg);
    }
    else if (cmd == "contri")
    {
        iRet = AddContri(vecarg);
    }
    else if (cmd == "gotomap")
    {
        iRet = GotoMapId(vecarg);
    }
    else if (cmd == "monster")
    {
        iRet = CreateMonster(vecarg);
    }
    else if (cmd == "addskill")
    {
        iRet = AddSkill(vecarg);
    }
    
    proto_ff::GmRsp rsp;
    rsp.set_retcode(iRet);
    m_pMaster->SendMsgToClient(proto_ff::CLIENT_GM_RSP, rsp);
    return 0;
}

int NFGmPart::GetItem(const VEC_STRING& args)
{
    CHECK_EXPR(args.size() >= 2, -1, "args:{}", NFCommon::tostr(args));
    
    uint64_t itemId = std::atoll(args[0].c_str());//lexical_cast<uint64_t>(args[0]);
    uint32_t itemNum = std::atoll(args[1].c_str());
    
    NFPackagePart* pPart = dynamic_cast<NFPackagePart*>(m_pMaster->GetPart(PART_PACKAGE));
    CHECK_NULL(pPart);
    
    SCommonSource sourceParam;
    sourceParam.src = S_GM;
    pPart->AddItem(itemId, itemNum, sourceParam);
    NFLogInfo(NF_LOG_SYSTEMLOG, m_pMaster->Cid(), "addItem itemId:{} itemNum:{}", itemId, itemNum);
    return 0;
}

int NFGmPart::UpgradeLevel(const VEC_STRING& args)
{
    CHECK_EXPR(args.size() >= 1, -1, "args:{}", NFCommon::tostr(args));
    
    uint32_t level = std::atoi(args[0].c_str());
    uint32_t curlevel = m_pMaster->GetAttr(proto_ff::A_LEVEL);
    if (curlevel >= level)
    {
        NFLogError(NF_LOG_SYSTEMLOG, m_pMaster->Cid(), "UpgradeLevel....curlevel >= level...curlevel:{}, level:{} ", curlevel, level);
        return 0;
    }
    
    int64_t curexp = m_pMaster->GetAttr(proto_ff::A_EXP);
    int64_t neeexp = 0;
    auto pcfg = RoleExpDesc::Instance()->GetDesc(curlevel);
    if (nullptr != pcfg)
    {
        if (curexp < pcfg->m_exp)
        {
            neeexp = pcfg->m_exp - curexp;
        }
    }
    //
    for (uint32_t i = curlevel + 1; i < level; ++i)
    {
        auto pcfg = RoleExpDesc::Instance()->GetDesc(i);
        if (nullptr != pcfg)
        {
            neeexp += pcfg->m_exp;
        }
        else
        {
            break;
        }
    }
    //
    SCommonSource src;
    src.src = S_GM;
    m_pMaster->AddAttr(proto_ff::A_EXP, neeexp, &src, true);
    NFLogInfo(NF_LOG_SYSTEMLOG, m_pMaster->Cid(), "UpgradeLevel curLevel:{} level:{}", curlevel, level);
    return 0;
}

int NFGmPart::AddExp(const VEC_STRING& args)
{
    CHECK_EXPR(args.size() >= 1, -1, "args:{}", NFCommon::tostr(args));
    
    uint64_t val = std::atoll(args[0].c_str());
    SCommonSource src;
    src.src = S_GM;
    m_pMaster->AddAttr(proto_ff::A_EXP, val, &src, true);
    NFLogInfo(NF_LOG_SYSTEMLOG, m_pMaster->Cid(), "AddExp val:{}", val);
    return 0;
}

int NFGmPart::AddGold(const VEC_STRING& args)
{
    CHECK_EXPR(args.size() >= 1, -1, "args:{}", NFCommon::tostr(args));
    
    uint64_t val = std::atoll(args[0].c_str());
    SCommonSource src;
    src.src = S_GM;
    m_pMaster->AddAttr(proto_ff::A_GOLD, val, &src, true);
    NFLogInfo(NF_LOG_SYSTEMLOG, m_pMaster->Cid(), "AddGold val:{}", val);
    return 0;
}

int NFGmPart::AddDia(const VEC_STRING& args)
{
    CHECK_EXPR(args.size() >= 1, -1, "args:{}", NFCommon::tostr(args));
    
    uint64_t val = std::atoll(args[0].c_str());
    SCommonSource src;
    src.src = S_GM;
    m_pMaster->AddAttr(proto_ff::A_DIA, val, &src, true);
    NFLogInfo(NF_LOG_SYSTEMLOG, m_pMaster->Cid(), "AddDia val:{}", val);
    return 0;
}

int NFGmPart::AddBdDia(const VEC_STRING& args)
{
    CHECK_EXPR(args.size() >= 1, -1, "args:{}", NFCommon::tostr(args));
    
    uint64_t val = std::atoll(args[0].c_str());
    SCommonSource src;
    src.src = S_GM;
    m_pMaster->AddAttr(proto_ff::A_BD_DIA, val, &src, true);
    NFLogInfo(NF_LOG_SYSTEMLOG, m_pMaster->Cid(), "AddBdDia val:{}", val);
    return 0;
}

int NFGmPart::AddMagic(const VEC_STRING& args)
{
    CHECK_EXPR(args.size() >= 1, -1, "args:{}", NFCommon::tostr(args));
    
    uint64_t val = std::atoll(args[0].c_str());
    SCommonSource src;
    src.src = S_GM;
    m_pMaster->AddAttr(proto_ff::A_MAGIC, val, &src, true);
    NFLogInfo(NF_LOG_SYSTEMLOG, m_pMaster->Cid(), "AddMagic val:{}", val);
    return 0;
}

int NFGmPart::AddHunLing(const VEC_STRING& args)
{
    CHECK_EXPR(args.size() >= 1, -1, "args:{}", NFCommon::tostr(args));
    
    uint64_t val = std::atoll(args[0].c_str());
    SCommonSource src;
    src.src = S_GM;
    m_pMaster->AddAttr(proto_ff::A_HUN_LING, val, &src, true);
    NFLogInfo(NF_LOG_SYSTEMLOG, m_pMaster->Cid(), "AddHunLing val:{}", val);
    return 0;
}

int NFGmPart::AddPrestige(const VEC_STRING& args)
{
    CHECK_EXPR(args.size() >= 1, -1, "args:{}", NFCommon::tostr(args));
    
    uint64_t val = std::atoll(args[0].c_str());
    SCommonSource src;
    src.src = S_GM;
    m_pMaster->AddAttr(proto_ff::A_HUN_LING, val, &src, true);
    NFLogInfo(NF_LOG_SYSTEMLOG, m_pMaster->Cid(), "AddPrestige val:{}", val);
    return 0;
}

int NFGmPart::AddContri(const VEC_STRING& args)
{
    CHECK_EXPR(args.size() >= 1, -1, "args:{}", NFCommon::tostr(args));
    
    uint64_t val = std::atoll(args[0].c_str());
    SCommonSource src;
    src.src = S_GM;
    m_pMaster->AddAttr(proto_ff::A_CONTRI, val, &src, true);
    NFLogInfo(NF_LOG_SYSTEMLOG, m_pMaster->Cid(), "AddContri val:{}", val);
    return 0;
}

int NFGmPart::GotoMapId(const VEC_STRING& args)
{
    CHECK_EXPR(args.size() >= 1, -1, "args:{}", NFCommon::tostr(args));
    
    uint64_t dstMapId = NFCommonApi::StrToInt64(args[0]);
    auto pMapCfg = MapMapDesc::Instance()->GetDesc(dstMapId);
    if (nullptr == pMapCfg)
    {
        NFLogError(NF_LOG_SYSTEMLOG, m_pMaster->Cid(), "GmMgr::GotoMapId..nullptr == pMapCfg...mapid:{} ", dstMapId);
        return 0;
    }
    
    uint32_t zid = m_pMaster->GetZid();
    if (args.size() >= 2)
    {
        zid = NFCommonApi::StrToInt(args[1]);
    }
    //动态地图不允许用这个协议传送
    if (MapDescEx::Instance()->IsDynamic(dstMapId))
    {
        NFLogError(NF_LOG_SYSTEMLOG, m_pMaster->Cid(), "[logic] GmMgr::GotoMapId..dstmap is dynamic...mapid:{} ", dstMapId);
        return 0;
    }
    //随机出生点
    const NFPoint3<float>* pBornCfg = MapDescEx::Instance()->RandBornPoint(dstMapId);
    if (nullptr == pBornCfg)
    {
        NFLogError(NF_LOG_SYSTEMLOG, m_pMaster->Cid(), "[logic] GmMgr::GotoMapId..RandBornPoint failed...mapid:{}", dstMapId);
        return 0;
    }
    
    NFPoint3<float> pos(pBornCfg->x, pBornCfg->y, pBornCfg->z);
    
    //切换场景的时候打印下日志，便于后面查找定位问题
    proto_ff::SceneTransParam transParam;
    transParam.set_trans_type(ETransType_GM);
    uint64_t dstSceneId = dstMapId;
    int iRet = m_pMaster->TransScene(dstMapId, dstSceneId, pos, transParam);
    NFLogInfo(NF_LOG_SYSTEMLOG, m_pMaster->Cid(), "[logic] GmMgr::GotoMapId...mapid:{}, sceneid:{}, zid:{}, pos:{}", dstMapId, dstSceneId, zid, pos.ToString());
    return iRet;
}

int NFGmPart::CreateMonster(const VEC_STRING& vecarg)
{
    return 0;
}

int NFGmPart::AddSkill(const VEC_STRING& vecarg)
{
    return 0;
}
