// -------------------------------------------------------------------------
//    @FileName         :    NFCRpcService.h
//    @Author           :    gaoyi
//    @Date             :    23-3-25
//    @Email			:    445267987@qq.com
//    @Module           :    NFCRpcService
//
// -------------------------------------------------------------------------

#pragma once

#include "NFIRpcService.h"
#include "NFServerDefine.h"
#include "NFIMessageModule.h"

class NFIDynamicModule;
class NFIMessageModule;

template<typename BaseType, typename RequestType, typename ResponeType>
class NFCRpcService : public NFIRpcService
{
    static_assert((TIsDerived<BaseType, NFIDynamicModule>::Result), "the class must inherit NFIDynamicModule");
    static_assert((TIsDerived<RequestType, google::protobuf::Message>::Result), "the class RequestType must is google::protobuf::Message");
    static_assert((TIsDerived<ResponeType, google::protobuf::Message>::Result), "the class ResponeType must is google::protobuf::Message");
public:
    NFCRpcService(NFIPluginManager* p, BaseType *pBase, int (BaseType::*handleRecieve)(uint64_t unLinkId, RequestType& request, ResponeType &respone)): NFIRpcService(p)
    {
        m_functionWithLink = std::bind(handleRecieve, pBase, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3);
    }

    NFCRpcService(NFIPluginManager* p, BaseType *pBase, int (BaseType::*handleRecieve)(RequestType& request, ResponeType &respone)): NFIRpcService(p)
    {
        m_function = std::bind(handleRecieve, pBase, std::placeholders::_1, std::placeholders::_2);
    }

    NFCRpcService(NFIPluginManager* p, BaseType *pBase, int (BaseType::*handleRecieve)(RequestType& request, ResponeType &respone, const std::function<void()>& cb)): NFIRpcService(p)
    {
        m_functionWithCallBack = std::bind(handleRecieve, pBase, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3);
    }

    virtual int run(uint64_t unLinkId, const proto_ff::Proto_SvrPkg& reqSvrPkg) override
    {
        RequestType req;
        ResponeType rsp;
        CHECK_EXPR(std::hash<std::string>()(req.GetTypeName()) == reqSvrPkg.rpc_info().req_rpc_hash(), proto_ff::ERR_CODE_RPC_DECODE_FAILED, "NFCRpcService reqHash Not Equal:{}, nMsgId:{}", req.GetTypeName(), reqSvrPkg.msg_id());
        CHECK_EXPR(std::hash<std::string>()(rsp.GetTypeName()) == reqSvrPkg.rpc_info().rsp_rpc_hash(), proto_ff::ERR_CODE_RPC_DECODE_FAILED, "NFCRpcService rspHash Not Equal:{}, nMsgId:{}", rsp.GetTypeName(), reqSvrPkg.msg_id());

        req.ParseFromString(reqSvrPkg.msg_data());

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
        svrPkg.mutable_rpc_info()->set_is_script_rpc(false);
        if (m_function || m_functionWithLink || m_functionWithCallBack)
        {
            if (m_function)
            {
                iRet = m_function(req, rsp);
            }
            else if (m_functionWithLink)
            {
                iRet = m_functionWithLink(unLinkId, req, rsp);
            }
            else if (m_functionWithCallBack)
            {
                iRet = m_functionWithCallBack(req, rsp, [eServerType, reqServerType, reqBusId, &svrPkg, &rsp, this](){
                    svrPkg.set_msg_data(rsp.SerializeAsString());
                    svrPkg.mutable_rpc_info()->set_rpc_ret_code(0);
                    FindModule<NFIMessageModule>()->SendMsgToServer((NF_SERVER_TYPES)eServerType, (NF_SERVER_TYPES)reqServerType, 0, reqBusId, proto_ff::NF_SERVER_TO_SERVER_RPC_CMD, svrPkg);
                });
            }
            svrPkg.set_msg_data(rsp.SerializeAsString());
            svrPkg.mutable_rpc_info()->set_rpc_ret_code(iRet);
        }
        else {
            svrPkg.mutable_rpc_info()->set_rpc_ret_code(proto_ff::ERR_CODE_RPC_MSG_FUNCTION_UNEXISTED);
        }

        FindModule<NFIMessageModule>()->SendMsgToServer((NF_SERVER_TYPES)eServerType, (NF_SERVER_TYPES)reqServerType, 0, reqBusId, proto_ff::NF_SERVER_TO_SERVER_RPC_CMD, svrPkg);

        return 0;
    }

    std::function<int(RequestType& request, ResponeType &respone)> m_function;
    std::function<int(uint64_t unLinkId, RequestType& request, ResponeType &respone)> m_functionWithLink;
    std::function<int(RequestType& request, ResponeType &respone, const std::function<void()>& cb)> m_functionWithCallBack;
};
