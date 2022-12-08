// -------------------------------------------------------------------------
//    @FileName         :    NFLogicGMModule.cpp
//    @Author           :    gaoyi
//    @Date             :    22-11-30
//    @Email			:    445267987@qq.com
//    @Module           :    NFLogicGMModule
//
// -------------------------------------------------------------------------

#include "NFLogicGMModule.h"
#include "ClientServerCmd.pb.h"
#include "Gm.pb.h"
#include "NFLogicCommon/NFComTypeDefine.h"
#include "NFComm/NFPluginModule/NFCheck.h"
#include "NFComm/NFCore/NFCommon.h"
#include "DescStore/GmcommandGmcommandDesc.h"
#include "ServerInternalCmd.pb.h"
#include "Player/NFPlayerMgr.h"
#include "Part/NFPackagePart.h"
#include "DescStore/RoleExpDesc.h"

NFLogicGMModule::NFLogicGMModule(NFIPluginManager *p) : NFIDynamicModule(p)
{

}

NFLogicGMModule::~NFLogicGMModule()
{
}

bool NFLogicGMModule::Awake()
{
    ////////////proxy msg////player login,disconnect,reconnet/////////////////////
    RegisterServerMessage(NF_ST_LOGIC_SERVER, proto_ff::NOTIFY_SERVER_GM_RSP);
    return true;
}

int NFLogicGMModule::OnHandleClientMessage(uint32_t msgId, NFDataPackage &packet, uint64_t param1, uint64_t param2)
{
    return 0;
}

int NFLogicGMModule::OnHandleClientGMMsg(uint32_t msgId, NFDataPackage &packet, uint64_t uid, uint64_t roleId)
{
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "-- begin --");
    proto_ff::NotifyGmRsp rsp;
    CLIENT_MSG_PROCESS_WITH_PRINTF(packet, rsp);

    uint64_t cid = rsp.cid();
    VEC_STRING vecstr;
    string strargs;
    for (int32_t i = 0; i < rsp.arg_size(); ++i)
    {
        vecstr.push_back(rsp.arg(i));
        strargs += rsp.arg(i);
        strargs += ",";
    }

    NFPlayer *pPlayer = NFPlayerMgr::Instance(m_pObjPluginManager)->GetPlayer(cid);
    CHECK_NULL(pPlayer);

    if (rsp.cmd() == "get")
    {
        GetItem(pPlayer, vecstr);
    }
    else if (rsp.cmd() == "lev")
    {
        UpgradeLevel(pPlayer, vecstr);
    }
    else if (rsp.cmd() == "exp")
    {
        AddExp(pPlayer, vecstr);
    }
    else if (rsp.cmd() == "gold")
    {
        AddGold(pPlayer, vecstr);
    }
    else if (rsp.cmd() == "dia")
    {
        AddDia(pPlayer, vecstr);
    }
    else if (rsp.cmd() == "bd_dia")
    {
        AddBdDia(pPlayer, vecstr);
    }
    else if (rsp.cmd() == "magic")
    {
        AddMagic(pPlayer, vecstr);
    }
    else if (rsp.cmd() == "gotomap")
    {

    }
    else if (rsp.cmd() == "monster")
    {

    }
    else if (rsp.cmd() == "enterdup")
    {

    }
    else if (rsp.cmd() == "addskill")
    {

    }
    else if (rsp.cmd() == "delskill")
    {

    }
    else if (rsp.cmd() == "addbox")
    {

    }
    else if (rsp.cmd() == "adddrop")
    {

    }
    else if (rsp.cmd() == "relive")
    {

    }

    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "-- end --");
    return 0;
}

int NFLogicGMModule::OnHandleServerMessage(uint32_t msgId, NFDataPackage &packet, uint64_t param1, uint64_t param2)
{
    if (!m_pObjPluginManager->IsInited())
    {
        NFLogError(NF_LOG_SYSTEMLOG, packet.nParam1, "World Server not inited, drop client msg:{}", packet.ToString());
        return -1;
    }

    if (m_pObjPluginManager->IsServerStopping())
    {
        NFLogError(NF_LOG_SYSTEMLOG, packet.nParam1, "World Server is Stopping, drop client msg:{}", packet.ToString());
        return -1;
    }

    switch (msgId)
    {
        case proto_ff::NOTIFY_SERVER_GM_RSP:
        {
            OnHandleClientGMMsg(msgId, packet, param1, param2);
            break;
        }
    }
    return 0;
}

int NFLogicGMModule::GetItem(NFPlayer *pPlayer, const vector<std::string> &args)
{
    CHECK_NULL(pPlayer);
    CHECK_EXPR(args.size() >= 2, -1, "args error:{}", NFCommon::tostr(args));

    uint64_t itemId = std::atoll(args[0].c_str());//lexical_cast<uint64_t>(args[0]);
    uint32_t itemNum = std::atoll(args[1].c_str());

    NFPackagePart *pPart = dynamic_cast<NFPackagePart *>(pPlayer->GetPart(PART_PACKAGE));
    CHECK_NULL(pPart);

    SCommonSource sourceParam;
    sourceParam.src = S_GM;
    NFLogInfo(NF_LOG_SYSTEMLOG, pPlayer->GetRoleId(), "[logic] GmMgr::GetItem 111...cid:{}, itemid:{}, num:{}", pPlayer->GetRoleId(), itemId,
              itemNum);
    pPart->AddItem(itemId, itemNum, sourceParam);
    return 0;
}

int NFLogicGMModule::UpgradeLevel(NFPlayer *pPlayer, const vector<std::string> &args)
{
    CHECK_NULL(pPlayer);
    CHECK_EXPR(args.size() >= 1, -1, "args error:{}", NFCommon::tostr(args));

    uint32_t level = std::atoi(args[0].c_str());
    uint32_t curlevel = pPlayer->GetAttr(proto_ff::A_LEVEL);
    if (curlevel >= level)
    {
        NFLogError(NF_LOG_SYSTEMLOG, pPlayer->GetRoleId(), "[logic] GmMgr::UpgradeLevel....curlevel >= level...cid:{} curlevel:{}, level:{} ",
                   pPlayer->GetRoleId(), curlevel, level);
        return 0;
    }
    int64_t curexp = pPlayer->GetAttr(proto_ff::A_EXP);
    int64_t neeexp = 0;
    auto pCruLevelCfg = RoleExpDesc::Instance(m_pObjPluginManager)->GetDesc(curlevel);
    if (nullptr != pCruLevelCfg)
    {
        if (curexp < pCruLevelCfg->exp)
        {
            neeexp = pCruLevelCfg->exp - curexp;
        }
    }
    //
    for (uint32_t i = curlevel + 1; i < level; ++i)
    {
        auto pCfg = RoleExpDesc::Instance(m_pObjPluginManager)->GetDesc(i);
        if (nullptr != pCfg)
        {
            neeexp += pCfg->exp;
        }
        else
        {
            break;
        }
    }
    //
    SCommonSource src;
    src.src = S_GM;
    pPlayer->AddAttr(proto_ff::A_EXP, neeexp, &src, true);
    return 0;
}

int NFLogicGMModule::AddExp(NFPlayer *pPlayer, const vector<std::string> &args)
{
    CHECK_NULL(pPlayer);
    CHECK_EXPR(args.size() >= 1, -1, "");
    uint64_t exp = std::atoll(args[0].c_str());
    SCommonSource src;
    src.src = S_GM;
    pPlayer->AddAttr(proto_ff::A_EXP, exp, &src, true);
    NFLogInfo(NF_LOG_SYSTEMLOG, pPlayer->GetRoleId(), "GM AddExp:{}", exp);
    return 0;
}

int NFLogicGMModule::AddGold(NFPlayer *pPlayer, const vector<std::string> &args)
{
    CHECK_NULL(pPlayer);
    CHECK_EXPR(args.size() >= 1, -1, "");
    uint64_t val = std::atoll(args[0].c_str());
    SCommonSource src;
    src.src = S_GM;
    pPlayer->AddAttr(proto_ff::A_GOLD, val, &src, true);
    NFLogInfo(NF_LOG_SYSTEMLOG, pPlayer->GetRoleId(), "GM AddGold:{}", val);
    return 0;
}

int NFLogicGMModule::AddDia(NFPlayer *pPlayer, const vector<std::string> &args)
{
    CHECK_NULL(pPlayer);
    CHECK_EXPR(args.size() >= 1, -1, "");
    uint64_t val = std::atoll(args[0].c_str());
    SCommonSource src;
    src.src = S_GM;
    pPlayer->AddAttr(proto_ff::A_DIA, val, &src, true);
    NFLogInfo(NF_LOG_SYSTEMLOG, pPlayer->GetRoleId(), "GM AddDia:{}", val);
    return 0;
}

int NFLogicGMModule::AddBdDia(NFPlayer *pPlayer, const vector<std::string> &args)
{
    CHECK_NULL(pPlayer);
    CHECK_EXPR(args.size() >= 1, -1, "");
    uint64_t val = std::atoll(args[0].c_str());
    SCommonSource src;
    src.src = S_GM;
    pPlayer->AddAttr(proto_ff::A_BD_DIA, val, &src, true);
    NFLogInfo(NF_LOG_SYSTEMLOG, pPlayer->GetRoleId(), "GM AddBdDia:{}", val);
    return 0;
}

int NFLogicGMModule::AddMagic(NFPlayer *pPlayer, const vector<std::string> &args)
{
    CHECK_NULL(pPlayer);
    CHECK_EXPR(args.size() >= 1, -1, "");
    uint64_t val = std::atoll(args[0].c_str());
    SCommonSource src;
    src.src = S_GM;
    pPlayer->AddAttr(proto_ff::A_MAGIC, val, &src, true);
    NFLogInfo(NF_LOG_SYSTEMLOG, pPlayer->GetRoleId(), "GM AddMagic:{}", val);
    return 0;
}


