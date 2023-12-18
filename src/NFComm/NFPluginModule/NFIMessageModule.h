// -------------------------------------------------------------------------
//    @FileName         :    NFIMsgModule.h
//    @Author           :    Gao.Yi
//    @Date             :   2022-09-18
//    @Email			:    445267987@qq.com
//    @Module           :    NFPluginModule
//
// -------------------------------------------------------------------------

#pragma once

#include "NFComm/NFCore/NFPlatform.h"
#include "NFComm/NFPluginModule/NFIModule.h"
#include "NFComm/NFPluginModule/NFIHttpHandle.h"
#include "NFComm/NFPluginModule/NFCheck.h"
#include "NFComm/NFCore/NFCRC32.h"
#include "google/protobuf/message.h"
#include "NFComm/NFKernelMessage/storesvr_sqldata.pb.h"
#include "NFICoroutineModule.h"
#include "NFServerDefine.h"
#include "NFComm/NFCore/NFCommon.h"
#include "NFIConfigModule.h"
#include "NFError.h"
#include "NFRoute.h"

#include <map>
#include <unordered_map>
#include <list>
#include <string>
#include <set>
#include <functional>

class NFIDynamicModule;

/// @brief 基于消息的通讯接口类
class NFIMessageModule : public NFIModule
{
public:
    template<typename BaseType, typename RequestType, typename ResponeType>
    class NFCRpcService : public NFIRpcService
    {
        static_assert((TIsDerived<BaseType, NFIDynamicModule>::Result), "the class must inherit NFIDynamicModule");
        static_assert((TIsDerived<RequestType, google::protobuf::Message>::Result), "the class RequestType must is google::protobuf::Message");
        static_assert((TIsDerived<ResponeType, google::protobuf::Message>::Result), "the class ResponeType must is google::protobuf::Message");
    public:
        NFCRpcService(NFIPluginManager *p, BaseType *pBase,
                      int (BaseType::*handleRecieve)(uint64_t unLinkId, RequestType &request, ResponeType &respone)) : NFIRpcService(p)
        {
            m_functionWithLink = std::bind(handleRecieve, pBase, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3);
        }

        NFCRpcService(NFIPluginManager *p, BaseType *pBase, int (BaseType::*handleRecieve)(RequestType &request, ResponeType &respone))
                : NFIRpcService(p)
        {
            m_function = std::bind(handleRecieve, pBase, std::placeholders::_1, std::placeholders::_2);
        }

        NFCRpcService(NFIPluginManager *p, BaseType *pBase,
                      int (BaseType::*handleRecieve)(RequestType &request, ResponeType &respone, const std::function<void()> &cb)) : NFIRpcService(p)
        {
            m_functionWithCallBack = std::bind(handleRecieve, pBase, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3);
        }

        NFCRpcService(NFIPluginManager *p, BaseType *pBase,
                      int (BaseType::*handleRecieve)(uint32_t msgId, google::protobuf::Message& request, google::protobuf::Message& respone,
                                                     uint64_t param1, uint64_t param2)) : NFIRpcService(p)
        {
            m_functionCommonWithParam = std::bind(handleRecieve, pBase, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3,
                                                  std::placeholders::_4, std::placeholders::_5);
        }

        NFCRpcService(NFIPluginManager *p, BaseType *pBase,
                      int (BaseType::*handleRecieve)(RequestType &request, ResponeType &respone, uint64_t param1, uint64_t param2)) : NFIRpcService(p)
        {
            m_functionWithParam = std::bind(handleRecieve, pBase, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3,
                                            std::placeholders::_4);
        }

        virtual int run(uint64_t unLinkId, const proto_ff::Proto_SvrPkg &reqSvrPkg, uint64_t param1, uint64_t param2) override
        {
            RequestType req;
            ResponeType rsp;
            CHECK_EXPR(NFHash::hash<std::string>()(req.GetTypeName()) == reqSvrPkg.rpc_info().req_rpc_hash(), proto_ff::ERR_CODE_RPC_DECODE_FAILED,
                       "NFCRpcService reqHash Not Equal:{}, nMsgId:{}", req.GetTypeName(), reqSvrPkg.msg_id());
            CHECK_EXPR(NFHash::hash<std::string>()(rsp.GetTypeName()) == reqSvrPkg.rpc_info().rsp_rpc_hash(), proto_ff::ERR_CODE_RPC_DECODE_FAILED,
                       "NFCRpcService rspHash Not Equal:{}, nMsgId:{}", rsp.GetTypeName(), reqSvrPkg.msg_id());

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
            svrPkg.mutable_rpc_info()->set_is_script_rpc(reqSvrPkg.rpc_info().is_script_rpc());
            if (m_function || m_functionWithParam || m_functionCommonWithParam || m_functionWithLink || m_functionWithCallBack)
            {
                if (m_function)
                {
                    iRet = m_function(req, rsp);
                }
                else if (m_functionCommonWithParam)
                {
                    iRet = m_functionCommonWithParam(reqSvrPkg.msg_id(), req, rsp, param1, param2);
                }
                else if (m_functionWithParam)
                {
                    iRet = m_functionWithParam(req, rsp, param1, param2);
                }
                else if (m_functionWithLink)
                {
                    iRet = m_functionWithLink(unLinkId, req, rsp);
                }
                else if (m_functionWithCallBack)
                {
                    iRet = m_functionWithCallBack(req, rsp, [eServerType, reqServerType, reqBusId, &svrPkg, &rsp, this]()
                    {
                        svrPkg.set_msg_data(rsp.SerializeAsString());
                        svrPkg.mutable_rpc_info()->set_rpc_ret_code(0);
                        FindModule<NFIMessageModule>()->SendMsgToServer((NF_SERVER_TYPES) eServerType, (NF_SERVER_TYPES) reqServerType, 0, reqBusId,
                                                                        proto_ff::NF_SERVER_TO_SERVER_RPC_CMD, svrPkg);
                    });
                }
                svrPkg.set_msg_data(rsp.SerializeAsString());
                svrPkg.mutable_rpc_info()->set_rpc_ret_code(iRet);
            }
            else
            {
                svrPkg.mutable_rpc_info()->set_rpc_ret_code(proto_ff::ERR_CODE_RPC_MSG_FUNCTION_UNEXISTED);
            }

            FindModule<NFIMessageModule>()->SendMsgToServer((NF_SERVER_TYPES) eServerType, (NF_SERVER_TYPES) reqServerType, 0, reqBusId,
                                                            proto_ff::NF_SERVER_TO_SERVER_RPC_CMD, svrPkg);

            return 0;
        }

        std::function<int(RequestType &request, ResponeType &respone)> m_function;
        std::function<int(uint32_t msgId, google::protobuf::Message& request, google::protobuf::Message& respone, uint64_t param1,
                          uint64_t param2)> m_functionCommonWithParam;
        std::function<int(RequestType &request, ResponeType &respone, uint64_t param1, uint64_t param2)> m_functionWithParam;
        std::function<int(uint64_t unLinkId, RequestType &request, ResponeType &respone)> m_functionWithLink;
        std::function<int(RequestType &request, ResponeType &respone, const std::function<void()> &cb)> m_functionWithCallBack;
    };

public:
    template<typename BaseType>
    class NFCScriptRpcService : public NFIRpcService
    {
        static_assert((TIsDerived<BaseType, NFIDynamicModule>::Result), "the class must inherit NFIDynamicModule");
    public:
        NFCScriptRpcService(NFIPluginManager *p, const std::string &reqType, const std::string &rspType, BaseType *pBase,
                            int (BaseType::*handleRecieve)(uint64_t unLinkId, uint32_t msgId, const std::string &reqType, const std::string &request,
                                                           const std::string &rspType, std::string &respone)) : NFIRpcService(p)
        {
            m_reqType = reqType;
            m_rspType = rspType;
            m_functionWithLink = std::bind(handleRecieve, pBase, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3,
                                           std::placeholders::_4, std::placeholders::_5, std::placeholders::_6);
        }

        NFCScriptRpcService(NFIPluginManager *p, const std::string &reqType, const std::string &rspType, BaseType *pBase,
                            int (BaseType::*handleRecieve)(uint32_t msgId, const std::string &reqType, const std::string &request,
                                                           const std::string &rspType, std::string &respone)) : NFIRpcService(p)
        {
            m_reqType = reqType;
            m_rspType = rspType;
            m_function = std::bind(handleRecieve, pBase, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4,
                                   std::placeholders::_5);
        }

        NFCScriptRpcService(NFIPluginManager *p, const std::string &reqType, const std::string &rspType, BaseType *pBase,
                            int (BaseType::*handleRecieve)(uint32_t msgId, const std::string &reqType, const std::string &request,
                                                           const std::string &rspType, std::string &respone, const std::function<void()> &cb))
                : NFIRpcService(p)
        {
            m_reqType = reqType;
            m_rspType = rspType;
            m_functionWithCallBack = std::bind(handleRecieve, pBase, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3,
                                               std::placeholders::_4, std::placeholders::_5, std::placeholders::_6);
        }

        virtual int run(uint64_t unLinkId, const proto_ff::Proto_SvrPkg &reqSvrPkg, uint64_t param1, uint64_t param2) override
        {
            std::string rsp;
            CHECK_EXPR(NFHash::hash<std::string>()(m_reqType) == reqSvrPkg.rpc_info().req_rpc_hash(), proto_ff::ERR_CODE_RPC_DECODE_FAILED,
                       "NFCScriptRpcService reqHash Not Equal:{}, nMsgId:{}", m_reqType, reqSvrPkg.msg_id());
            CHECK_EXPR(NFHash::hash<std::string>()(m_rspType) == reqSvrPkg.rpc_info().rsp_rpc_hash(), proto_ff::ERR_CODE_RPC_DECODE_FAILED,
                       "NFCScriptRpcService rspHash Not Equal:{}, nMsgId:{}", m_rspType, reqSvrPkg.msg_id());

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
            svrPkg.mutable_rpc_info()->set_is_script_rpc(reqSvrPkg.rpc_info().is_script_rpc());
            if (m_function || m_functionWithLink || m_functionWithCallBack)
            {
                if (m_function)
                {
                    iRet = m_function(reqSvrPkg.msg_id(), m_reqType, reqSvrPkg.msg_data(), m_rspType, rsp);
                }
                else if (m_functionWithLink)
                {
                    iRet = m_functionWithLink(unLinkId, reqSvrPkg.msg_id(), m_reqType, reqSvrPkg.msg_data(), m_rspType, rsp);
                }
                else if (m_functionWithCallBack)
                {
                    iRet = m_functionWithCallBack(reqSvrPkg.msg_id(), m_reqType, reqSvrPkg.msg_data(), m_rspType, rsp,
                                                  [eServerType, reqServerType, reqBusId, &svrPkg, &rsp, this]()
                                                  {
                                                      svrPkg.set_msg_data(rsp);
                                                      svrPkg.mutable_rpc_info()->set_rpc_ret_code(0);
                                                      FindModule<NFIMessageModule>()->SendMsgToServer((NF_SERVER_TYPES) eServerType,
                                                                                                      (NF_SERVER_TYPES) reqServerType, 0, reqBusId,
                                                                                                      proto_ff::NF_SERVER_TO_SERVER_RPC_CMD, svrPkg);
                                                  });
                }
                svrPkg.set_msg_data(rsp);
                svrPkg.mutable_rpc_info()->set_rpc_ret_code(iRet);
            }
            else
            {
                svrPkg.mutable_rpc_info()->set_rpc_ret_code(proto_ff::ERR_CODE_RPC_MSG_FUNCTION_UNEXISTED);
            }

            FindModule<NFIMessageModule>()->SendMsgToServer((NF_SERVER_TYPES) eServerType, (NF_SERVER_TYPES) reqServerType, 0, reqBusId,
                                                            proto_ff::NF_SERVER_TO_SERVER_RPC_CMD, svrPkg);

            return 0;
        }

        std::string m_reqType;
        std::string m_rspType;
        std::function<int(uint32_t msgId, const std::string &reqType, const std::string &request, const std::string &rspType,
                          std::string &respone)> m_function;
        std::function<int(uint64_t unLinkId, uint32_t msgId, const std::string &reqType, const std::string &request, const std::string &rspType,
                          std::string &respone)> m_functionWithLink;
        std::function<int(uint32_t msgId, const std::string &reqType, const std::string &request, const std::string &rspType, std::string &respone,
                          const std::function<void()> &cb)> m_functionWithCallBack;
    };

public:
    NFIMessageModule(NFIPluginManager *p) : NFIModule(p)
    {

    }

    virtual ~NFIMessageModule()
    {

    }

public:
    // register msg callback
    template<typename BaseType>
    bool AddHttpRequestHandler(NF_SERVER_TYPES serverType, const std::string &strPath, const NFHttpType eRequestType,
                               BaseType *pBase, bool (BaseType::*handleRecieve)(uint32_t, const NFIHttpHandle &req))
    {
        HTTP_RECEIVE_FUNCTOR functor = std::bind(handleRecieve, pBase, std::placeholders::_1, std::placeholders::_2);
        return AddHttpMsgCB(serverType, strPath, eRequestType, functor);
    }

    template<typename BaseType>
    bool AddHttpRequestHandler(NF_SERVER_TYPES serverType, const NFHttpType eRequestType, BaseType *pBase,
                               bool (BaseType::*handleRecieve)(uint32_t, const NFIHttpHandle &req))
    {
        HTTP_RECEIVE_FUNCTOR functor = std::bind(handleRecieve, pBase, std::placeholders::_1, std::placeholders::_2);
        return AddHttpOtherMsgCB(serverType, eRequestType, functor);
    }

    template<typename BaseType>
    bool AddHttpNetFilter(NF_SERVER_TYPES serverType, const std::string &strPath, BaseType *pBase,
                          NFWebStatus(BaseType::*handleFilter)(uint32_t, const NFIHttpHandle &req))
    {
        HTTP_FILTER_FUNCTOR functor = std::bind(handleFilter, pBase, std::placeholders::_1, std::placeholders::_2);

        return AddHttpFilterCB(serverType, strPath, functor);
    }

public:
    template<typename BaseType>
    bool AddMessageCallBack(NF_SERVER_TYPES eType, uint32_t nMsgID, BaseType *pBase,
                            int (BaseType::*handleRecieve)(uint64_t unLinkId, NFDataPackage &packet), bool createCo = false)
    {
        NF_ASSERT_MSG((TIsDerived<BaseType, NFIDynamicModule>::Result), "the class must inherit NFIDynamicModule");
        NET_RECEIVE_FUNCTOR functor = std::bind(handleRecieve, pBase, std::placeholders::_1, std::placeholders::_2);
        return AddMessageCallBack(eType, nMsgID, pBase, functor, createCo);
    }

    template<typename BaseType>
    bool AddMessageCallBack(NF_SERVER_TYPES eType, uint32_t nModuleId, uint32_t nMsgID, BaseType *pBase,
                            int (BaseType::*handleRecieve)(uint64_t unLinkId, NFDataPackage &packet), bool createCo = false)
    {
        NF_ASSERT_MSG((TIsDerived<BaseType, NFIDynamicModule>::Result), "the class must inherit NFIDynamicModule");
        NET_RECEIVE_FUNCTOR functor = std::bind(handleRecieve, pBase, std::placeholders::_1, std::placeholders::_2);
        return AddMessageCallBack(eType, nModuleId, nMsgID, pBase, functor, createCo);
    }

    template<typename BaseType>
    bool AddOtherCallBack(NF_SERVER_TYPES eType, uint64_t linkId, BaseType *pBase,
                          int (BaseType::*handleRecieve)(uint64_t unLinkId, NFDataPackage &packet), bool createCo = false)
    {
        NF_ASSERT_MSG((TIsDerived<BaseType, NFIDynamicModule>::Result), "the class must inherit NFIDynamicModule");
        NET_RECEIVE_FUNCTOR functor = std::bind(handleRecieve, pBase, std::placeholders::_1, std::placeholders::_2);

        return AddOtherCallBack(eType, linkId, pBase, functor, createCo);
    }

    template<typename BaseType>
    bool AddEventCallBack(NF_SERVER_TYPES eType, uint64_t linkId, BaseType *pBase, int (BaseType::*handler)(eMsgType nEvent, uint64_t unLinkId),
                          bool createCo = false)
    {
        NF_ASSERT_MSG((TIsDerived<BaseType, NFIDynamicModule>::Result), "the class must inherit NFIMessageProcessor");
        NET_EVENT_FUNCTOR functor = std::bind(handler, pBase, std::placeholders::_1, std::placeholders::_2);
        return AddEventCallBack(eType, linkId, pBase, functor, createCo);
    }

    /*
    * 对所有的消息添加一个统一的回调， 同过判断返回, 0表示将处理这个消息，!=0将不处理这个消息
    * */
    template<typename BaseType>
    bool AddAllMsgCallBack(NF_SERVER_TYPES eType, BaseType *pBase,
                           int (BaseType::*handleRecieve)(uint64_t unLinkId, NFDataPackage &packet), bool createCo = false)
    {
        NF_ASSERT_MSG((TIsDerived<BaseType, NFIDynamicModule>::Result), "the class must inherit NFIDynamicModule");
        NET_RECEIVE_FUNCTOR functor = std::bind(handleRecieve, pBase, std::placeholders::_1, std::placeholders::_2);

        return AddAllMsgCallBack(eType, pBase, functor, createCo);
    }

public:
    /**
     * @brief 添加rpc服务
     * @tparam BaseType
     * @tparam recvDataType
     * @tparam returnDataType
     * @param serverType
     * @param handleRecieve
     * @return
     */
    template<size_t msgId, typename BaseType, typename RequestType, typename ResponeType>
    bool AddRpcService(NF_SERVER_TYPES serverType, BaseType *pBase,
                       int (BaseType::*handleRecieve)(uint64_t unLinkId, RequestType &request, ResponeType &respone), bool createCo = false)
    {
        STATIC_ASSERT_BIND_RPC_SERVICE(msgId, RequestType, ResponeType);
        NF_ASSERT_MSG((TIsDerived<BaseType, NFIDynamicModule>::Result), "the class must inherit NFIDynamicModule");
        NFIRpcService *pRpcService = new NFCRpcService<BaseType, RequestType, ResponeType>(m_pObjPluginManager, pBase, handleRecieve);
        return AddRpcService(serverType, msgId, pBase, pRpcService, createCo);
    }

    template<size_t msgId, typename BaseType, typename RequestType, typename ResponeType>
    bool AddRpcService(NF_SERVER_TYPES serverType, BaseType *pBase, int (BaseType::*handleRecieve)(RequestType &request, ResponeType &respone),
                       bool createCo = false)
    {
        STATIC_ASSERT_BIND_RPC_SERVICE(msgId, RequestType, ResponeType);
        NF_ASSERT_MSG((TIsDerived<BaseType, NFIDynamicModule>::Result), "the class must inherit NFIDynamicModule");
        NFIRpcService *pRpcService = new NFCRpcService<BaseType, RequestType, ResponeType>(m_pObjPluginManager, pBase, handleRecieve);
        return AddRpcService(serverType, msgId, pBase, pRpcService, createCo);
    }

    template<size_t msgId, typename BaseType, typename RequestType, typename ResponeType>
    bool AddRpcService(NF_SERVER_TYPES serverType, BaseType *pBase,
                       int (BaseType::*handleRecieve)(uint32_t msg, google::protobuf::Message &request, google::protobuf::Message &respone,
                                                      uint64_t param1, uint64_t param2),
                       bool createCo = false)
    {
        STATIC_ASSERT_BIND_RPC_SERVICE(msgId, RequestType, ResponeType);
        NF_ASSERT_MSG((TIsDerived<BaseType, NFIDynamicModule>::Result), "the class must inherit NFIDynamicModule");
        NFIRpcService *pRpcService = new NFCRpcService<BaseType, RequestType, ResponeType>(m_pObjPluginManager, pBase, handleRecieve);
        return AddRpcService(serverType, msgId, pBase, pRpcService, createCo);
    }

    template<size_t msgId, typename BaseType, typename RequestType, typename ResponeType>
    bool AddRpcService(NF_SERVER_TYPES serverType, BaseType *pBase,
                       int (BaseType::*handleRecieve)(RequestType &request, ResponeType &respone, uint64_t param1, uint64_t param2),
                       bool createCo = false)
    {
        STATIC_ASSERT_BIND_RPC_SERVICE(msgId, RequestType, ResponeType);
        NF_ASSERT_MSG((TIsDerived<BaseType, NFIDynamicModule>::Result), "the class must inherit NFIDynamicModule");
        NFIRpcService *pRpcService = new NFCRpcService<BaseType, RequestType, ResponeType>(m_pObjPluginManager, pBase, handleRecieve);
        return AddRpcService(serverType, msgId, pBase, pRpcService, createCo);
    }

    template<size_t msgId, typename BaseType, typename RequestType, typename ResponeType>
    bool AddRpcService(NF_SERVER_TYPES serverType, BaseType *pBase,
                       int (BaseType::*handleRecieve)(RequestType &request, ResponeType &respone, const std::function<void()> &cb),
                       bool createCo = false)
    {
        STATIC_ASSERT_BIND_RPC_SERVICE(msgId, RequestType, ResponeType);
        NF_ASSERT_MSG((TIsDerived<BaseType, NFIDynamicModule>::Result), "the class must inherit NFIDynamicModule");
        NFIRpcService *pRpcService = new NFCRpcService<BaseType, RequestType, ResponeType>(m_pObjPluginManager, pBase, handleRecieve);
        return AddRpcService(serverType, msgId, pBase, pRpcService, createCo);
    }

    template<typename BaseType>
    bool AddScriptRpcService(NF_SERVER_TYPES serverType, uint32_t nMsgId, const std::string &reqType, const std::string &rspType, BaseType *pBase,
                             int (BaseType::*handleRecieve)(uint64_t unLinkId, uint32_t msgId, const std::string &reqType, const std::string &request,
                                                            const std::string &rspType, std::string &respone), bool createCo = false)
    {
        NF_ASSERT_MSG((TIsDerived<BaseType, NFIDynamicModule>::Result), "the class must inherit NFIDynamicModule");
        NFIRpcService *pRpcService = new NFCScriptRpcService<BaseType>(m_pObjPluginManager, reqType, rspType, pBase, handleRecieve);
        return AddRpcService(serverType, nMsgId, pBase, pRpcService, createCo);
    }

    template<typename BaseType>
    bool AddScriptRpcService(NF_SERVER_TYPES serverType, uint32_t nMsgId, const std::string &reqType, const std::string &rspType, BaseType *pBase,
                             int (BaseType::*handleRecieve)(uint32_t msgId, const std::string &reqType, const std::string &request,
                                                            const std::string &rspType,
                                                            std::string &respone), bool createCo = false)
    {
        NF_ASSERT_MSG((TIsDerived<BaseType, NFIDynamicModule>::Result), "the class must inherit NFIDynamicModule");
        NFIRpcService *pRpcService = new NFCScriptRpcService<BaseType>(m_pObjPluginManager, reqType, rspType, pBase, handleRecieve);
        return AddRpcService(serverType, nMsgId, pBase, pRpcService, createCo);
    }

    template<typename BaseType>
    bool AddScriptRpcService(NF_SERVER_TYPES serverType, uint32_t nMsgId, const std::string &reqType, const std::string &rspType, BaseType *pBase,
                             int (BaseType::*handleRecieve)(uint32_t msgId, const std::string &reqType, const std::string &request,
                                                            const std::string &rspType,
                                                            std::string &respone, const std::function<void()> &cb), bool createCo = false)
    {
        NF_ASSERT_MSG((TIsDerived<BaseType, NFIDynamicModule>::Result), "the class must inherit NFIDynamicModule");
        NFIRpcService *pRpcService = new NFCScriptRpcService<BaseType>(m_pObjPluginManager, reqType, rspType, pBase, handleRecieve);
        return AddRpcService(serverType, nMsgId, pBase, pRpcService, createCo);
    }

    /**
     * @brief 在协程里获取远程服务器的rpc服务, 这个程序必须在协程里调用，需要先创建协程
     *        如果你在player或part的函数里，请优先调用player/part GetRpcService系统函数函数，而不是调用FindModule<NFIMessageModule>()->GetRpcService系统函数，
     *        因为玩家的生命周期是不确定的
     * @tparam RequestType
     * @tparam ResponeType
     * @param serverType
     * @param dstServerType
     * @param dstBusId
     * @param nMsgId
     * @param request
     * @param respone
     * @return
     */
    template<size_t msgId, typename RequestType, typename ResponeType>
    int GetRpcService(NF_SERVER_TYPES serverType, NF_SERVER_TYPES dstServerType, uint32_t dstBusId, const RequestType &request, ResponeType &respone,
                      uint64_t param1 = 0, uint64_t param2 = 0)
    {
        STATIC_ASSERT_BIND_RPC_SERVICE(msgId, RequestType, ResponeType);
        static_assert((TIsDerived<RequestType, google::protobuf::Message>::Result), "the class RequestType must is google::protobuf::Message");
        static_assert((TIsDerived<ResponeType, google::protobuf::Message>::Result), "the class ResponeType must is google::protobuf::Message");
        NF_ASSERT_MSG(FindModule<NFICoroutineModule>()->IsInCoroutine(), "Call GetRpcService Must Int the Coroutine");
        NFServerConfig *pConfig = FindModule<NFIConfigModule>()->GetAppConfig(serverType);
        CHECK_EXPR(pConfig, -1, "can't find server config! servertype:{}", GetServerName(serverType));

        proto_ff::Proto_SvrPkg svrPkg;
        svrPkg.set_msg_id(msgId);
        svrPkg.set_msg_data(request.SerializeAsString());
        svrPkg.mutable_rpc_info()->set_req_rpc_id(FindModule<NFICoroutineModule>()->CurrentTaskId());
        svrPkg.mutable_rpc_info()->set_req_rpc_hash(NFHash::hash<std::string>()(request.GetTypeName()));
        svrPkg.mutable_rpc_info()->set_rsp_rpc_hash(NFHash::hash<std::string>()(respone.GetTypeName()));
        svrPkg.mutable_rpc_info()->set_req_server_type(serverType);
        svrPkg.mutable_rpc_info()->set_req_bus_id(pConfig->BusId);
        svrPkg.mutable_rpc_info()->set_is_script_rpc(false);

        SendMsgToServer(serverType, dstServerType, pConfig->BusId, dstBusId, proto_ff::NF_SERVER_TO_SERVER_RPC_CMD, svrPkg, param1, param2);

        int32_t iRet = FindModule<NFICoroutineModule>()->SetUserData(&respone);
        CHECK_EXPR(iRet == 0, iRet, "Yield Failed, Error:{}", GetErrorStr(iRet));

        iRet = FindModule<NFICoroutineModule>()->Yield(DEFINE_RPC_SERVICE_TIME_OUT_MS);

        FindModule<NFICoroutineModule>()->SetUserData(NULL);

        CHECK_EXPR(iRet == 0, iRet, "Yield Failed, Error:{} rpc Msg Id:{} request:{} respone:{}", GetErrorStr(iRet), msgId, request.GetTypeName(),
                   respone.GetTypeName());
        return iRet;
    }

    /**
     * @brief 这个函数会先创建一个协程， 获取远程服务器的rpc服务，不能在别的协程里调用这个函数
     * @tparam RequestType
     * @tparam ResponeType
     * @param serverType
     * @param dstServerType
     * @param dstBusId
     * @param nMsgId
     * @param request
     * @param rpcCb
     * @return
     */
    template<size_t msgId, typename RequestType, typename ResponFunc>
    int64_t
    GetRpcService(NF_SERVER_TYPES serverType, NF_SERVER_TYPES dstServerType, uint32_t dstBusId, const RequestType &request, const ResponFunc &rpcCb,
                  uint64_t param1 = 0, uint64_t param2 = 0, bool is_immediately = true)
    {
        return GetRpcServiceInner<msgId>(serverType, dstServerType, dstBusId, request, rpcCb, &ResponFunc::operator(), param1, param2, is_immediately);
    }

    int GetScriptRpcService(NF_SERVER_TYPES serverType, NF_SERVER_TYPES dstServerType, uint32_t dstBusId, uint32_t msgId, const std::string &reqType,
                            const std::string &request, const std::string &rspType, std::string &respone)
    {
        NF_ASSERT_MSG(FindModule<NFICoroutineModule>()->IsInCoroutine(), "Call GetScriptRpcService Must Int the Coroutine");
        NFServerConfig *pConfig = FindModule<NFIConfigModule>()->GetAppConfig(serverType);
        CHECK_EXPR(pConfig, -1, "can't find server config! servertype:{}", GetServerName(serverType));

        proto_ff::Proto_SvrPkg svrPkg;
        svrPkg.set_msg_id(msgId);
        svrPkg.set_msg_data(request);
        svrPkg.mutable_rpc_info()->set_req_rpc_id(FindModule<NFICoroutineModule>()->CurrentTaskId());
        svrPkg.mutable_rpc_info()->set_req_rpc_hash(NFHash::hash<std::string>()(reqType));
        svrPkg.mutable_rpc_info()->set_rsp_rpc_hash(NFHash::hash<std::string>()(rspType));
        svrPkg.mutable_rpc_info()->set_req_server_type(serverType);
        svrPkg.mutable_rpc_info()->set_req_bus_id(pConfig->BusId);
        svrPkg.mutable_rpc_info()->set_is_script_rpc(true);

        SendMsgToServer(serverType, dstServerType, pConfig->BusId, dstBusId, proto_ff::NF_SERVER_TO_SERVER_RPC_CMD, svrPkg);
        proto_ff::Proto_ScriptRpcResult result;
        result.set_req_type(reqType);
        result.set_rsp_type(rspType);
        int32_t iRet = FindModule<NFICoroutineModule>()->SetUserData(&result);
        CHECK_EXPR(iRet == 0, iRet, "Yield Failed, Error:{}", GetErrorStr(iRet));

        iRet = FindModule<NFICoroutineModule>()->Yield(DEFINE_RPC_SERVICE_TIME_OUT_MS);

        respone = result.respone();
        FindModule<NFICoroutineModule>()->SetUserData(NULL);

        CHECK_EXPR(iRet == 0, iRet, "Yield Failed, Error:{}", GetErrorStr(iRet));
        return iRet;
    }

    int64_t
    GetScriptRpcService(NF_SERVER_TYPES serverType, NF_SERVER_TYPES dstServerType, uint32_t dstBusId, uint32_t msgId, const std::string &reqType,
                        const std::string &request, const std::string &rspType,
                        const std::function<void(int rpcRetCode, const std::string &rspType, std::string &respone)> &func)
    {
        return FindModule<NFICoroutineModule>()->MakeCoroutine(
                [=]()
                {
                    std::string respone;
                    int iRet = FindModule<NFIMessageModule>()->GetScriptRpcService(serverType, dstServerType, dstBusId, msgId, reqType, request,
                                                                                   rspType, respone);
                    if (func)
                    {
                        func(iRet, rspType, respone);
                    }
                });
    }

private:

    /**
     * @brief 这个函数会先创建一个协程， 获取远程服务器的rpc服务，不能在别的协程里调用这个函数
     * @tparam RequestType
     * @tparam ResponeType
     * @param serverType
     * @param dstServerType
     * @param dstBusId
     * @param nMsgId
     * @param request
     * @param rpcCb
     * @return
     */
    template<size_t msgId, typename RequestType, typename ResponFunc, typename ResponeType>
    int64_t GetRpcServiceInner(NF_SERVER_TYPES serverType, NF_SERVER_TYPES dstServerType, uint32_t dstBusId, const RequestType &request,
                               const ResponFunc &responFunc, void (ResponFunc::*pf)(int rpcRetCode, ResponeType &respone) const, uint64_t param1 = 0,
                               uint64_t param2 = 0, bool is_immediately = true)
    {
        return FindModule<NFICoroutineModule>()->MakeCoroutine(
                [=]()
                {
                    ResponeType respone;
                    int iRet = FindModule<NFIMessageModule>()->GetRpcService<msgId>(serverType,
                                                                                    dstServerType,
                                                                                    dstBusId, request,
                                                                                    respone, param1, param2);
                    (responFunc.*pf)(iRet, respone);
                }, is_immediately);
    }

public:
    /**
     * @brief 添加rpc服务
     * @param serverType
     * @param pBase
     * @param pRpcService
     * @return
     */
    virtual bool
    AddRpcService(NF_SERVER_TYPES serverType, uint32_t nMsgID, NFIDynamicModule *pBase, NFIRpcService *pRpcService, bool createCo = false) = 0;

public:
    /**
     * @brief 添加服务器
     *
     * @param  eType		服务器类型
     * @param  nServerID	服务器ID
     * @param  nMaxClient	服务器最大连接客户端数
     * @param  nPort		服务器监听端口
     * @return int			返回0错误
     */
    virtual uint64_t BindServer(NF_SERVER_TYPES eServerType, const std::string &url, uint32_t nNetThreadNum = 1, uint32_t nMaxConnectNum = 100,
                                uint32_t nPacketParseType = PACKET_PARSE_TYPE_INTERNAL, bool bSecurity = false) = 0;

    /**
     * @brief 添加服务器
     *
     * @param  eType		服务器类型
     * @param  nServerID	服务器ID
     * @param  nMaxClient	服务器最大连接客户端数
     * @param  nPort		服务器监听端口
     * @return int			返回0错误
     */
    virtual uint64_t ConnectServer(NF_SERVER_TYPES eServerType, const std::string &url, uint32_t nPacketParseType = 0, bool bSecurity = false) = 0;

    virtual int ResumeConnect(NF_SERVER_TYPES eServerType) = 0;

    virtual std::string GetLinkIp(uint64_t usLinkId) = 0;

    virtual uint32_t GetPort(uint64_t usLinkId) = 0;

    virtual void CloseLinkId(uint64_t usLinkId) = 0;

    virtual void CloseServer(NF_SERVER_TYPES eServerType, NF_SERVER_TYPES destServer, uint32_t busId, uint64_t usLinkId) = 0;

    virtual void TransPackage(uint64_t usLinkId, NFDataPackage &packet) = 0;

    virtual void Send(uint64_t usLinkId, uint32_t nModuleId, uint32_t nMsgID, const std::string &strData, uint64_t param1 = 0, uint64_t param2 = 0,
                      uint64_t srcId = 0, uint64_t dstId = 0) = 0;

    virtual void
    Send(uint64_t usLinkId, uint32_t nModuleId, uint32_t nMsgID, const char *msg, uint32_t nLen, uint64_t param1 = 0, uint64_t param2 = 0,
         uint64_t srcId = 0, uint64_t dstId = 0) = 0;

    virtual void
    Send(uint64_t usLinkId, uint32_t nModuleId, uint32_t nMsgID, const google::protobuf::Message &xData, uint64_t param1 = 0, uint64_t param2 = 0,
         uint64_t srcId = 0, uint64_t dstId = 0) = 0;

    virtual void Send(uint64_t usLinkId, uint32_t nMsgID, const std::string &strData, uint64_t param1 = 0, uint64_t param2 = 0)
    {
        Send(usLinkId, NF_MODULE_SERVER, nMsgID, strData, param1, param2);
    }

    virtual void Send(uint64_t usLinkId, uint32_t nMsgID, const char *msg, uint32_t nLen, uint64_t param1 = 0, uint64_t param2 = 0)
    {
        Send(usLinkId, NF_MODULE_SERVER, nMsgID, msg, nLen, param1, param2);
    }

    virtual void Send(uint64_t usLinkId, uint32_t nMsgID, const google::protobuf::Message &xData, uint64_t param1 = 0, uint64_t param2 = 0)
    {
        Send(usLinkId, NF_MODULE_SERVER, nMsgID, xData, param1, param2);
    }

    virtual void
    SendServer(uint64_t usLinkId, uint32_t nModuleId, uint32_t nMsgID, const std::string &strData, uint64_t param1 = 0, uint64_t param2 = 0,
               uint64_t srcId = 0, uint64_t dstId = 0) = 0;

    virtual void
    SendServer(uint64_t usLinkId, uint32_t nModuleId, uint32_t nMsgID, const char *msg, uint32_t nLen, uint64_t param1 = 0, uint64_t param2 = 0,
               uint64_t srcId = 0, uint64_t dstId = 0) = 0;

    virtual void SendServer(uint64_t usLinkId, uint32_t nModuleId, uint32_t nMsgID, const google::protobuf::Message &xData, uint64_t param1 = 0,
                            uint64_t param2 = 0, uint64_t srcId = 0, uint64_t dstId = 0) = 0;

    virtual int
    SendMsgToServer(NF_SERVER_TYPES eSendType, NF_SERVER_TYPES recvType, uint32_t srcBusId, uint32_t dstBusId, uint32_t nModuleId, uint32_t nMsgId,
                    const google::protobuf::Message &xData, uint64_t param1 = 0, uint64_t param2 = 0) = 0;

    virtual int
    SendMsgToServer(NF_SERVER_TYPES eSendType, NF_SERVER_TYPES recvType, uint32_t srcBusId, uint32_t dstBusId, uint32_t nModuleId, uint32_t nMsgId,
                    const std::string &xData, uint64_t param1 = 0, uint64_t param2 = 0) = 0;

    virtual int SendMsgToServer(NF_SERVER_TYPES eSendType, NF_SERVER_TYPES recvType, uint32_t srcBusId, uint32_t dstBusId, uint32_t nMsgId,
                                const google::protobuf::Message &xData, uint64_t param1 = 0, uint64_t param2 = 0)
    {
        return SendMsgToServer(eSendType, recvType, srcBusId, dstBusId, NF_MODULE_SERVER, nMsgId, xData, param1, param2);
    }

    virtual int SendTrans(NF_SERVER_TYPES eSendType, NF_SERVER_TYPES recvType, uint32_t srcBusId, uint32_t dstBusId, uint32_t nMsgID,
                          const google::protobuf::Message &xData, uint32_t req_trans_id = 0, uint32_t rsp_trans_id = 0) = 0;

    virtual int SendTrans(NF_SERVER_TYPES eSendType, NF_SERVER_TYPES recvType, uint32_t srcBusId, uint32_t dstBusId, uint32_t nMsgID,
                          const std::string &xData, uint32_t req_trans_id = 0, uint32_t rsp_trans_id = 0) = 0;

    virtual NF_SHARE_PTR<NFServerData> GetServerByServerId(NF_SERVER_TYPES eSendType, uint32_t busId) = 0;

    virtual NF_SHARE_PTR<NFServerData> GetServerByUnlinkId(NF_SERVER_TYPES eSendType, uint64_t unlinkId) = 0;


    virtual NF_SHARE_PTR<NFServerData> CreateServerByServerId(NF_SERVER_TYPES eSendType, uint32_t busId, NF_SERVER_TYPES busServerType,
                                                              const proto_ff::ServerInfoReport &data) = 0;

    virtual void CreateLinkToServer(NF_SERVER_TYPES eSendType, uint32_t busId,
                                    uint64_t linkId) = 0;

    virtual void DelServerLink(NF_SERVER_TYPES eSendType, uint64_t linkId) = 0;

    virtual NFServerData *GetRouteData(NF_SERVER_TYPES eSendType) = 0;

    virtual const NFServerData *GetRouteData(NF_SERVER_TYPES eSendType) const = 0;

    virtual NFServerData *GetMasterData(NF_SERVER_TYPES eSendType) = 0;

    virtual const NFServerData *GetMasterData(NF_SERVER_TYPES eSendType) const = 0;

    virtual void CloseAllLink(NF_SERVER_TYPES eSendType) = 0;

    virtual uint64_t GetServerLinkId(NF_SERVER_TYPES eSendType) const = 0;

    virtual void SetServerLinkId(NF_SERVER_TYPES eSendType, uint64_t linkId) = 0;

    virtual uint64_t GetClientLinkId(NF_SERVER_TYPES eSendType) const = 0;

    virtual void SetClientLinkId(NF_SERVER_TYPES eSendType, uint64_t linkId) = 0;

    virtual std::vector<NF_SHARE_PTR<NFServerData>>
    GetServerByServerType(NF_SERVER_TYPES eSendType, NF_SERVER_TYPES serverTypes) = 0;

    virtual NF_SHARE_PTR<NFServerData>
    GetFirstServerByServerType(NF_SERVER_TYPES eSendType, NF_SERVER_TYPES serverTypes) = 0;

    virtual NF_SHARE_PTR<NFServerData>
    GetFirstServerByServerType(NF_SERVER_TYPES eSendType, NF_SERVER_TYPES serverTypes, bool crossServer) = 0;

    virtual NF_SHARE_PTR<NFServerData>
    GetRandomServerByServerType(NF_SERVER_TYPES eSendType, NF_SERVER_TYPES serverTypes) = 0;
    
    virtual NF_SHARE_PTR<NFServerData>
    GetRandomServerByServerType(NF_SERVER_TYPES eSendType, NF_SERVER_TYPES serverTypes, bool crossServer) = 0;

    virtual NF_SHARE_PTR<NFServerData>
    GetSuitServerByServerType(NF_SERVER_TYPES eSendType, NF_SERVER_TYPES serverTypes, uint64_t value) = 0;
    
    virtual NF_SHARE_PTR<NFServerData>
    GetSuitServerByServerType(NF_SERVER_TYPES eSendType, NF_SERVER_TYPES serverTypes, uint64_t value, bool crossServer) = 0;

    virtual NF_SHARE_PTR<NFServerData>
    GetSuitServerByServerType(NF_SERVER_TYPES eSendType, NF_SERVER_TYPES serverTypes, const std::string &value) = 0;
    
    virtual NF_SHARE_PTR<NFServerData>
    GetSuitServerByServerType(NF_SERVER_TYPES eSendType, NF_SERVER_TYPES serverTypes, const std::string &value, bool crossServer) = 0;

    virtual std::vector<NF_SHARE_PTR<NFServerData>> GetAllServer(NF_SERVER_TYPES eSendType) = 0;

    virtual std::vector<NF_SHARE_PTR<NFServerData>> GetAllServer(NF_SERVER_TYPES eSendType, NF_SERVER_TYPES serverTypes) = 0;

    virtual std::vector<NF_SHARE_PTR<NFServerData>> GetAllServer(NF_SERVER_TYPES eSendType, NF_SERVER_TYPES serverTypes, bool isCrossServer) = 0;

    virtual std::vector<std::string> GetDBNames(NF_SERVER_TYPES eSendType) = 0;

    virtual std::set<uint32_t> GetAllMsg(NF_SERVER_TYPES eSendType, uint32_t moduleId) = 0;

public:
    virtual int
    BroadcastEventToServer(NF_SERVER_TYPES eType, NF_SERVER_TYPES recvType, uint32_t dstBusId, uint32_t nEventID, uint32_t bySrcType, uint64_t nSrcID,
                           const google::protobuf::Message &message) = 0;

    virtual int BroadcastEventToServer(NF_SERVER_TYPES eType, NF_SERVER_TYPES recvType, uint32_t nEventID, uint32_t bySrcType, uint64_t nSrcID,
                                       const google::protobuf::Message &message) = 0;

    virtual int BroadcastEventToServer(NF_SERVER_TYPES eType, uint32_t nEventID, uint32_t bySrcType, uint64_t nSrcID,
                                       const google::protobuf::Message &message) = 0;

public:
    virtual bool ResponseHttpMsg(NF_SERVER_TYPES serverType, const NFIHttpHandle &req, const std::string &strMsg,
                                 NFWebStatus code = NFWebStatus::WEB_OK, const std::string &reason = "OK") = 0;

    virtual bool ResponseHttpMsg(NF_SERVER_TYPES serverType, uint64_t requestId, const std::string &strMsg,
                                 NFWebStatus code = NFWebStatus::WEB_OK,
                                 const std::string &reason = "OK") = 0;

    virtual int HttpGet(NF_SERVER_TYPES serverType, const std::string &strUri,
                        const HTTP_CLIENT_RESPONE &respone,
                        const std::map<std::string, std::string> &xHeaders = std::map<std::string, std::string>(),
                        int timeout = 3) = 0;

    virtual int HttpPost(NF_SERVER_TYPES serverType, const std::string &strUri, const std::string &strPostData, const HTTP_CLIENT_RESPONE &respone,
                         const std::map<std::string, std::string> &xHeaders = std::map<std::string, std::string>(),
                         int timeout = 3) = 0;

    virtual int SendEmail(NF_SERVER_TYPES serverType, const std::string &title, const std::string &subject, const string &content) = 0;

    virtual int SendWxWork(NF_SERVER_TYPES serverType, const string &content) = 0;

public:
    virtual bool AddHttpMsgCB(NF_SERVER_TYPES serverType, const std::string &strCommand, const NFHttpType eRequestType,
                              const HTTP_RECEIVE_FUNCTOR &cb) = 0;

    virtual bool AddHttpOtherMsgCB(NF_SERVER_TYPES serverType, const NFHttpType eRequestType,
                                   const HTTP_RECEIVE_FUNCTOR &cb) = 0;

    virtual bool AddHttpFilterCB(NF_SERVER_TYPES serverType, const std::string &strCommand,
                                 const HTTP_FILTER_FUNCTOR &cb) = 0;

public:
    /*
     * 删除目标的所有注册的回调
     * */
    virtual bool DelAllCallBack(NFIDynamicModule *pTarget) = 0;

    /*
     * 删除一个连接的所有回调
     * */
    virtual bool DelAllCallBack(NF_SERVER_TYPES eType, uint64_t unLinkId) = 0;

    /*
     * 添加模块0, 消息ID的回调, 一个消息只能有一个处理函数
     * */
    virtual bool
    AddMessageCallBack(NF_SERVER_TYPES eType, uint32_t nMsgID, NFIDynamicModule *pTarget, const NET_RECEIVE_FUNCTOR &cb, bool createCo) = 0;

    /*
     * 添加模块moduleId, 消息ID的回调, 一个消息只能有一个处理函数
     * */
    virtual bool AddMessageCallBack(NF_SERVER_TYPES eType, uint32_t nModuleId, uint32_t nMsgID, NFIDynamicModule *pTarget,
                                    const NET_RECEIVE_FUNCTOR &cb, bool createCo) = 0;

    /*
     * 未没有注册过的消息，添加一个统一处理的回调函数
     * */
    virtual bool
    AddOtherCallBack(NF_SERVER_TYPES eType, uint64_t linkId, NFIDynamicModule *pTarget, const NET_RECEIVE_FUNCTOR &cb, bool createCo) = 0;

    /*
    * 对所有的消息添加一个统一的回调， 同过判断返回, 0表示将处理这个消息，!=0将不处理这个消息
    * */
    virtual bool AddAllMsgCallBack(NF_SERVER_TYPES eType, NFIDynamicModule *pTarget, const NET_RECEIVE_FUNCTOR &cb, bool createCo) = 0;

    /*
     * 添加连接事件，掉线事件的处理函数
     * */
    virtual bool AddEventCallBack(NF_SERVER_TYPES eType, uint64_t linkId, NFIDynamicModule *pTarget, const NET_EVENT_FUNCTOR &cb, bool createCo) = 0;
};
