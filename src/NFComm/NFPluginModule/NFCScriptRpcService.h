// -------------------------------------------------------------------------
//    @FileName         :    NFCScriptRpcService.h
//    @Author           :    gaoyi
//    @Date             :    23-4-12
//    @Email			:    445267987@qq.com
//    @Module           :    NFCScriptRpcService
//
// -------------------------------------------------------------------------

#pragma once

#include "NFIRpcService.h"
#include "NFServerDefine.h"
#include "NFCheck.h"
#include "NFIMessageModule.h"

class NFIDynamicModule;
class NFIMessageModule;

template<typename BaseType>
class NFCScriptRpcService : public NFIRpcService
{
    static_assert((TIsDerived<BaseType, NFIDynamicModule>::Result), "the class must inherit NFIDynamicModule");
public:
    NFCScriptRpcService(NFIPluginManager* p, const std::string& reqType, const std::string& rspType, BaseType *pBase, int (BaseType::*handleRecieve)(uint64_t unLinkId, const std::string& reqType, const std::string& request, const std::string& rspType, std::string &respone)): NFIRpcService(p)
    {
        m_reqType = reqType;
        m_rspType = rspType;
        m_functionWithLink = std::bind(handleRecieve, pBase, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4, std::placeholders::_5);
    }

    NFCScriptRpcService(NFIPluginManager* p, const std::string& reqType, const std::string& rspType, BaseType *pBase, int (BaseType::*handleRecieve)(const std::string& reqType, const std::string& request, const std::string& rspType, std::string &respone)): NFIRpcService(p)
    {
        m_reqType = reqType;
        m_rspType = rspType;
        m_function = std::bind(handleRecieve, pBase, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4);
    }

    NFCScriptRpcService(NFIPluginManager* p, const std::string& reqType, const std::string& rspType, BaseType *pBase, int (BaseType::*handleRecieve)(const std::string& reqType, const std::string& request, const std::string& rspType, std::string &respone, const std::function<void()>& cb)): NFIRpcService(p)
    {
        m_reqType = reqType;
        m_rspType = rspType;
        m_functionWithCallBack = std::bind(handleRecieve, pBase, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4, std::placeholders::_5);
    }

    virtual int run(uint64_t unLinkId, const proto_ff::Proto_SvrPkg& reqSvrPkg) override
    {
        std::string rsp;
        CHECK_EXPR(std::hash<std::string>()(m_reqType) == reqSvrPkg.rpc_info().req_rpc_hash(), proto_ff::ERR_CODE_RPC_DECODE_FAILED, "NFCRpcService reqHash Not Equal:{}, nMsgId:{}", m_reqType, reqSvrPkg.msg_id());
        CHECK_EXPR(std::hash<std::string>()(m_rspType) == reqSvrPkg.rpc_info().rsp_rpc_hash(), proto_ff::ERR_CODE_RPC_DECODE_FAILED, "NFCRpcService rspHash Not Equal:{}, nMsgId:{}", m_rspType, reqSvrPkg.msg_id());

        uint32_t eServerType = GetServerTypeFromUnlinkId(unLinkId);
        uint32_t reqBusId = reqSvrPkg.rpc_info().req_bus_id();
        uint32_t reqServerType = reqSvrPkg.rpc_info().req_server_type();

        int iRet = 0;
        proto_ff::Proto_SvrPkg svrPkg;
        svrPkg.set_msg_id(reqSvrPkg.msg_id());
        svrPkg.mutable_rpc_info()->set_req_rpc_id(0);
        svrPkg.mutable_rpc_info()->set_rsp_rpc_id(reqSvrPkg.rpc_info().req_rpc_id());
        svrPkg.mutable_rpc_info()->set_req_rpc_hash(reqSvrPkg.rpc_info().req_rpc_hash());
        svrPkg.mutable_rpc_info()->set_rsp_rpc_hash(reqSvrPkg.rpc_info().rsp_rpc_hash());
        svrPkg.mutable_rpc_info()->set_is_script_rpc(true);
        if (m_function || m_functionWithLink || m_functionWithCallBack)
        {
            if (m_function)
            {
                iRet = m_function(m_reqType, reqSvrPkg.msg_data(), m_rspType, rsp);
            }
            else if (m_functionWithLink)
            {
                iRet = m_functionWithLink(unLinkId, m_reqType, reqSvrPkg.msg_data(), m_rspType, rsp);
            }
            else if (m_functionWithCallBack)
            {
                iRet = m_functionWithCallBack(m_reqType, reqSvrPkg.msg_data(), m_rspType, rsp, [eServerType, reqServerType, reqBusId, &svrPkg, &rsp, this](){
                    svrPkg.set_msg_data(rsp);
                    svrPkg.mutable_rpc_info()->set_rpc_ret_code(0);
                    FindModule<NFIMessageModule>()->SendMsgToServer((NF_SERVER_TYPES)eServerType, (NF_SERVER_TYPES)reqServerType, 0, reqBusId, proto_ff::NF_SERVER_TO_SERVER_RPC_CMD, svrPkg);
                });
            }
            svrPkg.set_msg_data(rsp);
            svrPkg.mutable_rpc_info()->set_rpc_ret_code(iRet);
        }
        else {
            svrPkg.mutable_rpc_info()->set_rpc_ret_code(proto_ff::ERR_CODE_RPC_MSG_FUNCTION_UNEXISTED);
        }

        FindModule<NFIMessageModule>()->SendMsgToServer((NF_SERVER_TYPES)eServerType, (NF_SERVER_TYPES)reqServerType, 0, reqBusId, proto_ff::NF_SERVER_TO_SERVER_RPC_CMD, svrPkg);

        return 0;
    }

    std::string m_reqType;
    std::string m_rspType;
    std::function<int(const std::string& reqType, const std::string& request, const std::string& rspType, std::string &respone)> m_function;
    std::function<int(uint64_t unLinkId, const std::string& reqType, const std::string& request, const std::string& rspType, std::string &respone)> m_functionWithLink;
    std::function<int(const std::string& reqType, const std::string& request, const std::string& rspType, std::string &respone, const std::function<void()>& cb)> m_functionWithCallBack;
};

