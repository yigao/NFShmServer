// -------------------------------------------------------------------------
//    @FileName         :    NFGMModule.cpp
//    @Author           :    gaoyi
//    @Date             :    22-11-30
//    @Email			:    445267987@qq.com
//    @Module           :    NFGMModule
//
// -------------------------------------------------------------------------

#include "NFWorldGMModule.h"
#include "ClientServerCmd.pb.h"
#include "Gm.pb.h"
#include "NFLogicCommon/NFComTypeDefine.h"
#include "NFWorldPlayerMgr.h"
#include "NFWorldPlayer.h"
#include "NFComm/NFPluginModule/NFCheck.h"
#include "NFComm/NFCore/NFCommon.h"
#include "DescStore/GmcommandGmcommandDesc.h"
#include "ServerInternalCmd.pb.h"

NFWorldGMModule::NFWorldGMModule(NFIPluginManager *p): NFIDynamicModule(p)
{

}

NFWorldGMModule::~NFWorldGMModule()
{
}

bool NFWorldGMModule::Awake()
{
    ////////////proxy msg////player login,disconnect,reconnet/////////////////////
    RegisterClientMessage(NF_ST_WORLD_SERVER, proto_ff::CLIENT_GM_REQ);
    return true;
}

int NFWorldGMModule::OnHandleClientMessage(uint32_t msgId, NFDataPackage &packet, uint64_t param1, uint64_t param2)
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

    switch(msgId)
    {
        case proto_ff::CLIENT_GM_REQ:
        {
            OnHandleClientGMMsg(msgId, packet, param1, param2);
            break;
        }
    }
    return 0;
}

int NFWorldGMModule::OnHandleClientGMMsg(uint32_t msgId, NFDataPackage &packet, uint64_t uid, uint64_t roleId)
{
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "---------------------------------- begin ---------------------------------- ");
    proto_ff::GmReq gm;
    CLIENT_MSG_PROCESS_WITH_PRINTF(packet, gm);

    //
    VEC_STRING vecstr;
    string strargs;
    int32_t isize = gm.arg_size();
    for (int32_t i = 0; i < isize; ++i)
    {
        vecstr.push_back(gm.arg(i));
        strargs += gm.arg(i);
        strargs += ",";
    }
    //
    NFLogInfo(NF_LOG_SYSTEMLOG, roleId, "[logic] cid:{}, cmd:{},agrs:{} ", roleId, gm.cmd().c_str(), strargs.c_str());
    //
    GMMsgHandler(uid, roleId, gm.cmd(), vecstr);

    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "---------------------------------- end ---------------------------------- ");
    return 0;
}

int NFWorldGMModule::OnHandleServerMessage(uint32_t msgId, NFDataPackage &packet, uint64_t param1, uint64_t param2)
{
    return NFIDynamicModule::OnHandleServerMessage(msgId, packet, param1, param2);
}

int NFWorldGMModule::GMMsgHandler(uint64_t uid, uint64_t roleId, const string &cmd, const VEC_STRING &vecarg)
{
    NFWorldPlayer *pPlayer = NFWorldPlayerMgr::Instance(m_pObjPluginManager)->GetPlayerByUid(uid);
    CHECK_EXPR(pPlayer, -1, "can't find player info, uid:{}", uid);

    string strcmd = cmd;
    int32_t argcount = 0;
    int32_t cmdid = NFCommon::strto<int32_t>(strcmd);
    if (cmdid > 0)
    {
        auto pcfg = GmcommandGmcommandDesc::Instance(m_pObjPluginManager)->GetDesc(cmdid);
        if (nullptr != pcfg)
        {
            strcmd = pcfg->m_key.ToString();
            argcount = pcfg->m_paramcount;
        }
    }
    else
    {
        auto pmap = GmcommandGmcommandDesc::Instance(m_pObjPluginManager)->GetResDescPtr();
        if (nullptr != pmap)
        {
            for (int i = 0; i < (int)pmap->size(); i++)
            {
                auto pInfo = &pmap->at(i);
                if (strcmd == pInfo->m_key.ToString())
                {
                    argcount = pInfo->m_paramcount;
                }
            }
        }
    }

    if (strcmd.empty())
    {
        proto_ff::GmRsp rsp;
        rsp.set_retcode(proto_ff::RET_GM_NOT_KEY);
        pPlayer->SendMsgToClient(proto_ff::CLIENT_GM_RSP, rsp);
        NFLogError(NF_LOG_SYSTEMLOG, roleId, "gm cmd not found....id:{}, cmd:{}", roleId, strcmd.c_str());
        return 0;
    }

    if (argcount > 0 && argcount != (int32_t)vecarg.size())
    {
        proto_ff::GmRsp rsp;
        rsp.set_retcode(proto_ff::RET_GM_PRAMA_COUNT_ERROR);
        pPlayer->SendMsgToClient(proto_ff::CLIENT_GM_RSP, rsp);

        NFLogError(NF_LOG_SYSTEMLOG, roleId, "gm arg count error....id:{}, cmd:{}, argcount:{}, relcount:{} ", roleId, strcmd.c_str(),argcount, (int32_t)vecarg.size());
        return 0;
    }

    //
    bool result = true;
    {
        proto_ff::NotifyGmRsp notify;
        notify.set_cid(roleId);
        notify.set_cmd(strcmd);
        for (auto &iterarg: vecarg)
        {
            notify.add_arg(iterarg);
        }

        pPlayer->SendMsgToLogicServer(proto_ff::NOTIFY_SERVER_GM_RSP, notify);
    }

    proto_ff::GmRsp rsp;
    rsp.set_retcode(proto_ff::RET_FAIL);
    if (result)
    {
        rsp.set_retcode(proto_ff::RET_SUCCESS);
    }
    pPlayer->SendMsgToClient(proto_ff::CLIENT_GM_RSP, rsp);
    return 0;
}
