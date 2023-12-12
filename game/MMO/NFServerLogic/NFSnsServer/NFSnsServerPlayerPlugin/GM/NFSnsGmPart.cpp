// -------------------------------------------------------------------------
//    @FileName         :    NFSnsGmMgr.cpp
//    @Author           :    gaoyi
//    @Date             :    23-12-12
//    @Email			:    445267987@qq.com
//    @Module           :    NFSnsGmMgr
//
// -------------------------------------------------------------------------

#include "NFSnsGmPart.h"
#include "AllProtocol.h"
#include "Gm.pb.h"
#include "NFComm/NFCore/NFCommonApi.h"
#include "DescStore/GmcommandGmcommandDesc.h"

NFSnsGmPart::NFSnsGmPart()
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

NFSnsGmPart::~NFSnsGmPart()
{
}

int NFSnsGmPart::CreateInit()
{
    return 0;
}

int NFSnsGmPart::ResumeInit()
{
    return 0;
}

int NFSnsGmPart::RegisterMessage()
{
    RegisterClientMessage(proto_ff::CLIENT_GM_REQ, true);
    return 0;
}

int NFSnsGmPart::OnHandleClientMessage(uint32_t msgId, NFDataPackage& packet)
{
    switch (msgId)
    {
        case proto_ff::CLIENT_GM_REQ:
        {
            OnHandleGmReq(packet);
            break;
        }
        default:break;
    }
    return 0;
}

int NFSnsGmPart::OnHandleServerMessage(uint32_t msgId, NFDataPackage& packet)
{
    return 0;
}

int NFSnsGmPart::OnHandleGmReq(NFDataPackage& packet)
{
    proto_ff::GmReq gm;
    CLIENT_MSG_PROCESS_WITH_PRINTF(packet, gm);
    VEC_STRING vecstr;
    std::string strargs;
    int32_t isize = gm.arg_size();
    for (int32_t i = 0; i < isize; ++i)
    {
        vecstr.push_back(gm.arg(i));
        strargs += gm.arg(i);
        strargs += ",";
    }
    
    NFLogInfo(NF_LOG_SYSTEMLOG, m_pMaster->Cid(), "cid:{}, cmd:{}, agrs:{}", m_pMaster->Cid(), gm.cmd(), strargs);
    
    ParseGmHandle(gm.cmd(), vecstr);
    return 0;
}

int NFSnsGmPart::ParseGmHandle(const std::string& cmd, const VEC_STRING& vecarg)
{
    string strcmd = cmd;
    int32_t argcount = 0;
    int32_t cmdid = NFCommonApi::StrToInt(strcmd);
    if (cmdid > 0)
    {
        auto pcfg = GmcommandGmcommandDesc::Instance()->GetDesc(cmdid);
        if (nullptr != pcfg)
        {
            strcmd = pcfg->m_Key.data();
            argcount = pcfg->m_ParamCount;
        }
    }
    else
    {
        auto pmap = GmcommandGmcommandDesc::Instance()->GetResDescPtr();
        if (nullptr != pmap)
        {
            for (auto& iter : *pmap)
            {
                if (strcmd == iter.second.m_Key.ToString())
                {
                    argcount = iter.second.m_ParamCount;
                }
            }
        }
    }
    if (strcmd.empty())
    {
        proto_ff::GmRsp rsp;
        rsp.set_retcode(proto_ff::RET_GM_NOT_KEY);
        SendMsgToClient(proto_ff::CLIENT_GM_RSP, rsp);
        NFLogError(NF_LOG_SYSTEMLOG, m_pMaster->Cid(), "gm cmd not found....id:{}, cmd:%s", m_pMaster->Cid(), strcmd.c_str());
        return 0;
    }
    if (argcount > 0 && argcount > (int32_t)vecarg.size())
    {
        proto_ff::GmRsp rsp;
        rsp.set_retcode(proto_ff::RET_GM_PRAMA_COUNT_ERROR);
        SendMsgToClient(proto_ff::CLIENT_GM_RSP, rsp);
        
        NFLogError(NF_LOG_SYSTEMLOG, m_pMaster->Cid(), "gm arg count error....id:%lu, cmd:%s, argcount:{}, relcount:{}", m_pMaster->Cid(), strcmd.c_str(), argcount, (int32_t)vecarg.size());
        return false;
    }
    
    //
    int iRet = HandleGmCommand(strcmd, vecarg);
    if (iRet > 0)
    {
        proto_ff::NotifyGmRsp notify;
        notify.set_cid(m_pMaster->Cid());
        notify.set_cmd(strcmd);
        for (auto& iterarg : vecarg)
        {
            notify.add_arg(iterarg);
        }
        
        SendMsgToLogicServer(proto_ff::NOTIFY_SERVER_GM_RSP, notify);
    }

    return 0;
}

int NFSnsGmPart::HandleGmCommand(const string& cmd, const VEC_STRING& vecarg)
{
    proto_ff::GmRsp rsp;
    int iRet = 0;
    if (cmd == "settime")
    {
        iRet = GmSetTime(vecarg);
    }
    else {
        return 1;
    }
    rsp.set_retcode(iRet);
    SendMsgToClient(proto_ff::CLIENT_GM_RSP, rsp);
    return 0;
}

int NFSnsGmPart::GmSetTime(const VEC_STRING& args)
{
    int32_t isize = (int32_t)args.size();
    if (isize < 6)
    {
        NFLogErrorFmt(NF_LOG_SYSTEMLOG, m_pMaster->Cid(), "[center] CenterGmMgr::SetTime....isize < 6...isize:%d", isize);
        return false;
    }
    
    uint64_t nowTime = NFTime::Now().UnixMSec();
    uint32_t year = NFCommonApi::StrToInt(args.at(0));;
    uint32_t month = NFCommonApi::StrToInt(args.at(1));
    uint32_t day = NFCommonApi::StrToInt(args.at(2));
    uint32_t hour = NFCommonApi::StrToInt(args.at(3));
    uint32_t minute = NFCommonApi::StrToInt(args.at(4));
    uint32_t sec = NFCommonApi::StrToInt(args.at(5));
    NFLogInfoFmt(NF_LOG_SYSTEMLOG, m_pMaster->Cid(), "[center] CenterGmMgr::SetTime...cid:%lu,year:%u,month:%u,day:%u,hour:%u,minite:%u,sec:%u ", m_pMaster->Cid(), year, month, day, hour, minute, sec);
    NFTime::GmSetTime(year, month, day, hour, minute, sec);
    if (NFTime::Now().UnixMSec() <= nowTime)
    {
        NFLogErrorFmt(NF_LOG_SYSTEMLOG, m_pMaster->Cid(), "SetTime...time less than current time  error...cid:%lu,curmsec:%lu", m_pMaster->Cid(), nowTime);
        return false;
    }
    
/*    proto_ff::NotifyGmRsp nt;
    nt.set_cid(0);
    nt.set_cmd("settime");
    for (auto& e : args)
    {
        nt.add_arg(e);
    }*/

    return 0;
}
