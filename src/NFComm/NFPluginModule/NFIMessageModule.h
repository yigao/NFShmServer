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
#include "google/protobuf/message.h"
#include "NFComm/NFKernelMessage/storesvr_sqldata.pb.h"
#include "NFIDynamicModule.h"

#include <map>
#include <unordered_map>
#include <list>
#include <string>
#include <map>
#include <functional>


#define MAX_CLIENT_INDEX 1000000                    //客户端掩码 一百万
#define MAX_CLIENT_MASK 0xffffffff                    //客户端掩码32位
#define MAX_SERVER_TYPE_MASK 0xff00000000                    //服务器类型
#define MAX_IS_SERVER_MASK 0xf0000000000                    //是什么类型的，服务器， 客户端

#define NF_IS_NONE 0
#define NF_IS_NET 1
#define NF_IS_BUS 2

#define GetUnLinkId(linkMode, serverType, serverIndex)    ((((uint64_t)serverIndex) & MAX_CLIENT_MASK) | ((((uint64_t)serverType) << 32) & MAX_SERVER_TYPE_MASK) | ((((uint64_t)linkMode << 40) & MAX_IS_SERVER_MASK)));
#define GetServerTypeFromUnlinkId(UnlinkId)        ((((uint64_t)UnlinkId) & MAX_SERVER_TYPE_MASK) >> 32);
#define GetServerLinkModeFromUnlinkId(UnlinkId)        ((((uint64_t)UnlinkId) & MAX_IS_SERVER_MASK) >> 40);
#define GetServerIndexFromUnlinkId(UnlinkId)    (((uint64_t)UnlinkId) & MAX_CLIENT_MASK);

#define CLIENT_MSG_PROCESS_NO_PRINTF(xPacket, xMsg)                 \
    if (!xMsg.ParseFromArray(xPacket.mBufferMsg.WriteAddr(), xPacket.mBufferMsg.WritableSize()))                \
    {                                                    \
        NFLogError(NF_LOG_PROTOBUF_PARSE, 0, "Protobuf Parse Message Failed, packet:{}", xPacket.ToString()); \
        return -1;                                        \
    }

#define CLIENT_MSG_PROCESS_WITH_PRINTF(xPacket, xMsg)                 \
    if (!xMsg.ParseFromArray(xPacket.mBufferMsg.WriteAddr(), xPacket.mBufferMsg.WritableSize()))                \
    {                                                    \
        NFLogError(NF_LOG_PROTOBUF_PARSE, 0, "Protobuf Parse Message Failed, packet:{}", xPacket.ToString()); \
        return -1;                                        \
    }\
    if (NFLogTraceEnable(NF_LOG_RECV_MSG_JSON_PRINTF, xPacket.nParam1))\
    {\
        NFLogTrace(NF_LOG_RECV_MSG_JSON_PRINTF, xPacket.nParam1, "recv packet:{}, json:{}", xPacket.ToString(), xMsg.Utf8DebugString()); \
    }\

#define WEB_MSG_PROCESS_WITH_PRINTF(xMsg, reqHandle) \
            \
    if (reqHandle.GetType() == NF_HTTP_REQ_GET)      \
    {                                                \
        if (NFProtobufCommon::GetMessageFromGetHttp(&xMsg, reqHandle) != 0)\
        {                                            \
            data.set_request_id(req.GetRequestId());                                          \
            NFLogError(NF_LOG_PROTOBUF_PARSE, 0, "Protobuf Parse Message Failed Fromn Http Get, get uri:{}", req.GetOriginalUri()); \
            return false;                               \
        }                                            \
        data.set_request_id(req.GetRequestId());                                              \
        if (NFLogTraceEnable(NF_LOG_RECV_MSG_JSON_PRINTF, 0))\
        {\
            NFLogInfo(NF_LOG_RECV_MSG_JSON_PRINTF, 0, "url:{}", reqHandle.GetOriginalUri()); \
        }\
    }                                                \
    else                                             \
    {                                                \
        std::string error;                                                 \
        if (!NFProtobufCommon::JsonToProtoMessage(reqHandle.GetBody(), &xMsg, &error))                \
        {                                            \
            data.set_request_id(req.GetRequestId());                                          \
            NFLogError(NF_LOG_PROTOBUF_PARSE, 0, "Protobuf Parse Message Failed Fromn Http Post Json, json:{}, error:{}", reqHandle.GetBody(), error); \
            return false;                                        \
        }                                            \
        data.set_request_id(req.GetRequestId());                                              \
        if (NFLogTraceEnable(NF_LOG_RECV_MSG_JSON_PRINTF, 0))\
        {\
            NFLogInfo(NF_LOG_RECV_MSG_JSON_PRINTF, 0, "json:{}", reqHandle.GetBody()); \
        }                                                        \
    }\


/// @brief 基于消息的通讯接口类
class NFIMessageModule : public NFIModule
{
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
                            int (BaseType::*handleRecieve)(uint64_t unLinkId, NFDataPackage &packet))
    {
        NF_ASSERT_MSG((TIsDerived<BaseType, NFIDynamicModule>::Result), "the class must inherit NFIDynamicModule");
        NET_RECEIVE_FUNCTOR functor = std::bind(handleRecieve, pBase, std::placeholders::_1, std::placeholders::_2);
        return AddMessageCallBack(eType, nMsgID, pBase, functor);
    }

    template<typename BaseType>
    bool AddMessageCallBack(NF_SERVER_TYPES eType, uint32_t nModuleId, uint32_t nMsgID, BaseType *pBase,
                            int (BaseType::*handleRecieve)(uint64_t unLinkId, NFDataPackage &packet))
    {
        NF_ASSERT_MSG((TIsDerived<BaseType, NFIDynamicModule>::Result), "the class must inherit NFIDynamicModule");
        NET_RECEIVE_FUNCTOR functor = std::bind(handleRecieve, pBase, std::placeholders::_1, std::placeholders::_2);
        return AddMessageCallBack(eType, nModuleId, nMsgID, pBase, functor);
    }

    template<typename BaseType>
    bool AddOtherCallBack(NF_SERVER_TYPES eType, uint64_t linkId, BaseType *pBase,
                          int (BaseType::*handleRecieve)(uint64_t unLinkId, NFDataPackage &packet))
    {
        NF_ASSERT_MSG((TIsDerived<BaseType, NFIDynamicModule>::Result), "the class must inherit NFIDynamicModule");
        NET_RECEIVE_FUNCTOR functor = std::bind(handleRecieve, pBase, std::placeholders::_1, std::placeholders::_2);

        return AddOtherCallBack(eType, linkId, pBase, functor);
    }

    template<typename BaseType>
    bool AddEventCallBack(NF_SERVER_TYPES eType, uint64_t linkId, BaseType *pBase, int (BaseType::*handler)(eMsgType nEvent, uint64_t unLinkId))
    {
        NF_ASSERT_MSG((TIsDerived<BaseType, NFIDynamicModule>::Result), "the class must inherit NFIMessageProcessor");
        NET_EVENT_FUNCTOR functor = std::bind(handler, pBase, std::placeholders::_1, std::placeholders::_2);
        return AddEventCallBack(eType, linkId, pBase, functor);
    }

    /*
    * 对所有的消息添加一个统一的回调， 同过判断返回, 0表示将处理这个消息，!=0将不处理这个消息
    * */
    template<typename BaseType>
    bool AddAllMsgCallBack(NF_SERVER_TYPES eType, uint64_t linkId, BaseType *pBase,
                           int (BaseType::*handleRecieve)(uint64_t unLinkId, NFDataPackage &packet))
    {
        NF_ASSERT_MSG((TIsDerived<BaseType, NFIDynamicModule>::Result), "the class must inherit NFIDynamicModule");
        NET_RECEIVE_FUNCTOR functor = std::bind(handleRecieve, pBase, std::placeholders::_1, std::placeholders::_2);

        return AddAllMsgCallBack(eType, linkId, pBase, functor);
    }

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
    virtual int64_t BindServer(NF_SERVER_TYPES eServerType, const std::string &url, uint32_t nNetThreadNum = 1, uint32_t nMaxConnectNum = 100,
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
    virtual int64_t ConnectServer(NF_SERVER_TYPES eServerType, const std::string &url, uint32_t nPacketParseType = 0, bool bSecurity = false) = 0;

    virtual int ResumeConnect(NF_SERVER_TYPES eServerType) = 0;

    virtual std::string GetLinkIp(uint64_t usLinkId) = 0;

    virtual uint32_t GetPort(uint64_t usLinkId) = 0;

    virtual void CloseLinkId(uint64_t usLinkId) = 0;

    virtual void CloseServer(NF_SERVER_TYPES eServerType, NF_SERVER_TYPES destServer, uint32_t busId, uint64_t usLinkId) = 0;

    virtual void Send(uint64_t usLinkId, NFDataPackage& packet) = 0;

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
        Send(usLinkId, NF_MODULE_NONE, nMsgID, strData, param1, param2);
    }

    virtual void Send(uint64_t usLinkId, uint32_t nMsgID, const char *msg, uint32_t nLen, uint64_t param1 = 0, uint64_t param2 = 0)
    {
        Send(usLinkId, NF_MODULE_NONE, nMsgID, msg, nLen, param1, param2);
    }

    virtual void Send(uint64_t usLinkId, uint32_t nMsgID, const google::protobuf::Message &xData, uint64_t param1 = 0, uint64_t param2 = 0)
    {
        Send(usLinkId, NF_MODULE_NONE, nMsgID, xData, param1, param2);
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
    SendMsgByBusId(NF_SERVER_TYPES eType, uint32_t busId, uint32_t nModuleId, uint32_t nMsgId, const google::protobuf::Message &xData,
                   uint64_t param1, uint64_t param2 = 0) = 0;

    virtual int
    SendMsgByBusId(NF_SERVER_TYPES eType, uint32_t busId, uint32_t nModuleId, uint32_t nMsgId, const char *msg, uint32_t nLen,
                   uint64_t param1, uint64_t param2 = 0) = 0;

    virtual int
    SendMsgToServer(NF_SERVER_TYPES eSendType, NF_SERVER_TYPES recvType, uint32_t srcBusId, uint32_t dstBusId, uint32_t nModuleId, uint32_t nMsgId,
                    const google::protobuf::Message &xData, uint64_t param1 = 0, uint64_t param2 = 0) = 0;

    virtual int
    SendMsgByBusId(NF_SERVER_TYPES eType, uint32_t busId, uint32_t nMsgId, const google::protobuf::Message &xData,
                   uint64_t param1, uint64_t param2 = 0)
    {
        return SendMsgByBusId(eType, NF_MODULE_NONE, busId, nMsgId, xData, param1, param2);
    }

    virtual int
    SendMsgByBusId(NF_SERVER_TYPES eType, uint32_t busId, uint32_t nMsgId, const char *msg, uint32_t nLen,
                   uint64_t param1, uint64_t param2 = 0)
    {
        return SendMsgByBusId(eType, NF_MODULE_NONE, busId, nMsgId, msg, nLen, param1, param2);
    }

    virtual int SendMsgToServer(NF_SERVER_TYPES eSendType, NF_SERVER_TYPES recvType, uint32_t srcBusId, uint32_t dstBusId, uint32_t nMsgId,
                                const google::protobuf::Message &xData, uint64_t param1 = 0, uint64_t param2 = 0)
    {
        return SendMsgToServer(eSendType, recvType, srcBusId, dstBusId, NF_MODULE_NONE, nMsgId, xData, param1, param2);
    }

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

    virtual std::vector<NF_SHARE_PTR<NFServerData>>
    GetServerByServerType(NF_SERVER_TYPES eSendType, NF_SERVER_TYPES serverTypes) = 0;

    virtual NF_SHARE_PTR<NFServerData>
    GetFirstServerByServerType(NF_SERVER_TYPES eSendType, NF_SERVER_TYPES serverTypes) = 0;

    virtual NF_SHARE_PTR<NFServerData>
    GetRandomServerByServerType(NF_SERVER_TYPES eSendType, NF_SERVER_TYPES serverTypes) = 0;

    virtual NF_SHARE_PTR<NFServerData>
    GetSuitServerByServerType(NF_SERVER_TYPES eSendType, NF_SERVER_TYPES serverTypes, uint64_t value) = 0;

    virtual NF_SHARE_PTR<NFServerData>
    GetSuitServerByServerType(NF_SERVER_TYPES eSendType, NF_SERVER_TYPES serverTypes, const std::string &value) = 0;

    virtual std::vector<NF_SHARE_PTR<NFServerData>> GetAllServer(NF_SERVER_TYPES eSendType) = 0;

    virtual std::vector<NF_SHARE_PTR<NFServerData>> GetAllServer(NF_SERVER_TYPES eSendType, NF_SERVER_TYPES serverTypes) = 0;

    virtual std::vector<std::string> GetDBNames(NF_SERVER_TYPES eSendType) = 0;

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

    virtual int SendEmail(NF_SERVER_TYPES serverType, const std::string& title, const std::string& subject, const string &content) = 0;

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
    virtual bool DelAllCallBack(void *pTarget) = 0;

    /*
     * 删除一个连接的所有回调
     * */
    virtual bool DelAllCallBack(NF_SERVER_TYPES eType, uint64_t unLinkId) = 0;

    /*
     * 添加模块0, 消息ID的回调, 一个消息只能有一个处理函数
     * */
    virtual bool AddMessageCallBack(NF_SERVER_TYPES eType, uint32_t nMsgID, void *pTarget, const NET_RECEIVE_FUNCTOR &cb) = 0;

    /*
     * 添加模块moduleId, 消息ID的回调, 一个消息只能有一个处理函数
     * */
    virtual bool AddMessageCallBack(NF_SERVER_TYPES eType, uint32_t nModuleId, uint32_t nMsgID, void *pTarget,
                                    const NET_RECEIVE_FUNCTOR &cb) = 0;

    /*
     * 未没有注册过的消息，添加一个统一处理的回调函数
     * */
    virtual bool AddOtherCallBack(NF_SERVER_TYPES eType, uint64_t linkId, void *pTarget, const NET_RECEIVE_FUNCTOR &cb) = 0;

    /*
    * 对所有的消息添加一个统一的回调， 同过判断返回, 0表示将处理这个消息，!=0将不处理这个消息
    * */
    virtual bool AddAllMsgCallBack(NF_SERVER_TYPES eType, uint64_t linkId, void *pTarget, const NET_RECEIVE_FUNCTOR &cb) = 0;

    /*
     * 添加连接事件，掉线事件的处理函数
     * */
    virtual bool AddEventCallBack(NF_SERVER_TYPES eType, uint64_t linkId, void *pTarget, const NET_EVENT_FUNCTOR &cb) = 0;
};
