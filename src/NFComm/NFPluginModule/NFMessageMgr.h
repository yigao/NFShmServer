// -------------------------------------------------------------------------
//    @FileName         :    NFMessageMgr.h
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFMessageMgr.h
//
// -------------------------------------------------------------------------

#pragma once
#include "NFComm/NFCore/NFSingleton.hpp"
#include "NFComm/NFCore/NFPlatform.h"
#include "common/spdlog/fmt/fmt.h"
#include "NFIMessageModule.h"

class NFMessageMgr : public NFSingleton<NFMessageMgr>
{
public:
    NFMessageMgr();
    virtual ~NFMessageMgr();
public:
    bool Init(NFIMessageModule* pMessageModule = nullptr);
    void UnInit();
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
    //virtual int64_t BindServer(NF_SERVER_TYPES eServerType, const std::string& url, uint32_t netThreadNum = 1, uint32_t nMaxConnectNum = 100, uint32_t nPacketParseType = PACKET_PARSE_TYPE_INTERNAL);
    virtual int64_t BindServer(NF_SERVER_TYPES eServerType, const std::string& url, uint32_t netThreadNum, uint32_t nMaxConnectNum, uint32_t nPacketParseType);

    /**
     * @brief 添加服务器
     *
     * @param  eType		服务器类型
     * @param  nServerID	服务器ID
     * @param  nMaxClient	服务器最大连接客户端数
     * @param  nPort		服务器监听端口
     * @return int			返回0错误
     */
    virtual int64_t ConnectServer(NF_SERVER_TYPES eServerType, const std::string& url, uint32_t nPacketParseType = 0);

    virtual int ResumeConnect(NF_SERVER_TYPES eServerType);

    virtual std::string GetLinkIp(uint64_t usLinkId);

    virtual void CloseLinkId(uint64_t usLinkId);

    virtual void CloseServer(NF_SERVER_TYPES eServerType, NF_SERVER_TYPES destServer, uint32_t busId, uint64_t usLinkId);

    virtual void Send(uint64_t usLinkId, uint32_t nMsgID, const std::string& strData, uint64_t nSendValue = 0, uint64_t nSendId = 0);

    virtual void Send(uint64_t usLinkId, uint32_t nMsgID, const char* msg, uint32_t nLen, uint64_t nSendValue = 0, uint64_t nSendId = 0);

    virtual void Send(uint64_t usLinkId, uint32_t nMsgID, const google::protobuf::Message& xData, uint64_t nSendValue = 0, uint64_t nSendId = 0);

    virtual void Send(uint64_t usLinkId, uint16_t nMainMsgID, uint16_t nSubMsgID, const std::string& strData, uint64_t nSendValue = 0, uint64_t nSendId = 0);

    virtual void Send(uint64_t usLinkId, uint16_t nMainMsgID, uint16_t nSubMsgID, const char *msg, uint32_t nLen,
                      uint64_t nSendValue = 0, uint64_t nSendId = 0);

    virtual void
    Send(uint64_t usLinkId, uint16_t nMainMsgID, uint16_t nSubMsgID, const google::protobuf::Message &xData,
         uint64_t nSendValue = 0, uint64_t nSendId = 0);

    virtual void
    SendTrans(uint64_t usLinkId, uint32_t nMsgID, const google::protobuf::Message &xData, uint64_t nSendValue = 0,
              uint64_t nSendId = 0, uint32_t req_trans_id = 0, uint32_t rsp_trans_id = 0);

    virtual void
    SendStore(uint64_t usLinkId, uint32_t cmd, uint32_t table_id, uint64_t sendLinkId, uint64_t destLinkId,
              const std::string &dbname, const std::string &table_name, const google::protobuf::Message &xData, int trans_id = 0, uint32_t seq = 0,
              uint64_t mod_key = 0, uint8_t packet_type = proto_ff::E_DISP_TYPE_BY_TRANSACTION, const std::string& cls_name = "");

    virtual void
    SendStore(uint64_t usLinkId, uint32_t cmd, uint32_t table_id, uint64_t sendLinkId, uint64_t destLinkId,
              const std::string &dbname, const std::string &table_name, std::vector<storesvr_sqldata::storesvr_vk> vk_list,
              const std::string &where_addtional_conds, int trans_id = 0, uint32_t seq = 0,
              uint64_t mod_key = 0, uint8_t packet_type = proto_ff::E_DISP_TYPE_BY_TRANSACTION, const std::string& cls_name = "");

    virtual int
    SendMsgByBusId(NF_SERVER_TYPES eType, uint32_t busId, uint32_t nMsgId, const google::protobuf::Message &xData,
                   uint64_t valueId);

    virtual int SendMsgByBusId(NF_SERVER_TYPES eType, uint32_t busId, uint16_t nMainMsgId, uint16_t nSubMsgId,
                               const google::protobuf::Message &xData, uint64_t valueId);

    virtual int
    SendMsgByBusId(NF_SERVER_TYPES eType, uint32_t busId, uint32_t nMsgId, const char *msg, uint32_t nLen,
                   uint64_t valueId);

    virtual int SendMsgByBusId(NF_SERVER_TYPES eType, uint32_t busId, uint16_t nMainMsgId, uint16_t nSubMsgId,
                               const char *msg, uint32_t nLen, uint64_t valueId);

    virtual int
    SendProxyMsgByBusId(NF_SERVER_TYPES eType, uint32_t busId, uint32_t nMsgId, const google::protobuf::Message &xData,
                   uint64_t valueId);

    virtual int SendProxyMsgByBusId(NF_SERVER_TYPES eType, uint32_t busId, uint16_t nMainMsgId, uint16_t nSubMsgId,
                               const google::protobuf::Message &xData, uint64_t valueId);

    virtual int
    SendProxyMsgByBusId(NF_SERVER_TYPES eType, uint32_t busId, uint32_t nMsgId, const char *msg, uint32_t nLen,
                   uint64_t valueId);

    virtual int SendProxyMsgByBusId(NF_SERVER_TYPES eType, uint32_t busId, uint16_t nMainMsgId, uint16_t nSubMsgId,
                               const char *msg, uint32_t nLen, uint64_t valueId);

    virtual int
    SendMsgToProxyServer(NF_SERVER_TYPES eType, uint32_t busId, uint32_t nMsgId, const google::protobuf::Message &xData,
                         uint64_t valueId);

    virtual int SendMsgToProxyServer(NF_SERVER_TYPES eType, uint32_t busId, uint16_t nMainMsgId, uint16_t nSubMsgId,
                                     const google::protobuf::Message &xData, uint64_t valueId);

    virtual int
    SendMsgToProxyServer(NF_SERVER_TYPES eType, uint32_t busId, uint32_t nMsgId, const char *msg, uint32_t nLen,
                         uint64_t valueId);

    virtual int SendMsgToProxyServer(NF_SERVER_TYPES eType, uint32_t busId, uint16_t nMainMsgId, uint16_t nSubMsgId,
                                     const char *msg, uint32_t nLen, uint64_t valueId);

    virtual int
    BroadMsgToProxyServer(NF_SERVER_TYPES eType, uint32_t nMsgId, const google::protobuf::Message &xData,
                          const std::map<uint32_t, std::vector<uint64_t>>& map);

    virtual int BroadMsgToProxyServer(NF_SERVER_TYPES eType, uint16_t nMainMsgId, uint16_t nSubMsgId,
                                     const google::protobuf::Message &xData, const std::map<uint32_t, std::vector<uint64_t>>& map);

    virtual int
    BroadMsgToProxyServer(NF_SERVER_TYPES eType, uint32_t nMsgId, const char *msg, uint32_t nLen,
                          const std::map<uint32_t, std::vector<uint64_t>>& map);

    virtual int BroadMsgToProxyServer(NF_SERVER_TYPES eType, uint16_t nMainMsgId, uint16_t nSubMsgId,
                                     const char *msg, uint32_t nLen, const std::map<uint32_t, std::vector<uint64_t>>& map);

    virtual int
    SendMsgToWebServer(NF_SERVER_TYPES eType, uint64_t requestId, int32_t result, const std::string& err_msg = "");

    virtual int
    SendMsgToWebServer(NF_SERVER_TYPES eType, uint32_t nMsgId, const google::protobuf::Message &xData, uint64_t valueId = 0);

    virtual int
    SendMsgToWorldServer(NF_SERVER_TYPES eType, uint32_t nMsgId, const google::protobuf::Message &xData, uint64_t valueId = 0);

    virtual int
    SendMsgToGameServer(NF_SERVER_TYPES eType, uint32_t busId, uint32_t nMsgId, const google::protobuf::Message &xData, uint64_t valueId = 0);

    virtual int
    SendMsgToLoginServer(NF_SERVER_TYPES eType, uint32_t busId, uint32_t nMsgId, const google::protobuf::Message &xData, uint64_t valueId = 0);

    virtual int
    SendMsgToLogicServer(NF_SERVER_TYPES eType, uint32_t busId, uint32_t nMsgId, const google::protobuf::Message &xData, uint64_t valueId = 0);

    virtual int
    SendMsgToLogicServer(NF_SERVER_TYPES eType, uint32_t busId, uint32_t nMsgId, const char* msg, int msgLen, uint64_t valueId = 0);

    virtual int
    SendMsgToSuitLogicServer(NF_SERVER_TYPES eType, uint64_t userId, uint32_t nMsgId, const google::protobuf::Message &xData, bool online = false);

    virtual int
    SendMsgToSnsServer(NF_SERVER_TYPES eType, uint32_t nMsgId, const google::protobuf::Message &xData, uint64_t valueId = 0);

    virtual int SendTransToWebServer(NF_SERVER_TYPES eType, uint32_t nMsgId, const google::protobuf::Message &xData,
                                     uint32_t req_trans_id = 0, uint32_t rsp_trans_id = 0);

    virtual int SendTransToWorldServer(NF_SERVER_TYPES eType, uint32_t nMsgId, const google::protobuf::Message &xData,
                                       uint32_t req_trans_id = 0, uint32_t rsp_trans_id = 0);

    virtual int SendTransToLoginServer(NF_SERVER_TYPES eType, uint32_t busId, uint32_t nMsgId, const google::protobuf::Message &xData,
                                       uint32_t req_trans_id = 0, uint32_t rsp_trans_id = 0);

    virtual int SendTransToLogicServer(NF_SERVER_TYPES eType, uint32_t busId, uint32_t nMsgId, const google::protobuf::Message &xData,
                                       uint32_t req_trans_id = 0, uint32_t rsp_trans_id = 0);

    virtual int SendTransToSnsServer(NF_SERVER_TYPES eType, uint32_t nMsgId, const google::protobuf::Message &xData,
                                     uint32_t req_trans_id = 0, uint32_t rsp_trans_id = 0);

    virtual int SendTransToGameServer(NF_SERVER_TYPES eType, uint32_t nMsgId, uint32_t gameBusId, const google::protobuf::Message &xData,
                                      uint32_t req_trans_id = 0, uint32_t rsp_trans_id = 0);

    virtual int SendTransToStoreServer(NF_SERVER_TYPES eType,
                                       uint32_t cmd, uint32_t table_id,
                                       const std::string &dbname, const std::string &table_name, const std::string &xData,
                                       int trans_id = 0, uint32_t seq = 0,
                                       uint64_t mod_key = 0);

    virtual int SendTransToStoreServer(NF_SERVER_TYPES eType, uint32_t cmd, uint32_t table_id,
                                       const std::string &dbname, const std::string &table_name, const google::protobuf::Message &xData,
                                       int trans_id = 0, uint32_t seq = 0,
                                       uint64_t mod_key = 0, const std::string& cls_name = "");

    virtual int SendTransToStoreServer(NF_SERVER_TYPES eType, uint32_t cmd, uint32_t table_id,
                                       const std::string &dbname, const std::string &table_name,
                                       std::vector<storesvr_sqldata::storesvr_vk> vk_list,
                                       const std::string &where_addtional_conds, int trans_id = 0, uint32_t seq = 0,
                                       uint64_t mod_key = 0, const std::string& cls_name = "");

    virtual int SendTransToStoreServer(NF_SERVER_TYPES eType, uint32_t cmd, uint32_t table_id,
                                       const std::string &dbname, const std::string &table_name, const google::protobuf::Message &xData,
                                       std::vector<storesvr_sqldata::storesvr_vk> vk_list,
                                       const std::string &where_addtional_conds, int trans_id = 0, uint32_t seq = 0,
                                       uint64_t mod_key = 0, const std::string& cls_name = "");

    virtual int SendDescStoreToStoreServer(NF_SERVER_TYPES eType, const std::string& dbName, const std::string &table_name, const google::protobuf::Message *pMessage, const QueryDescStore_CB& cb);

    virtual int SendMsgToServer(NF_SERVER_TYPES eSendType, NF_SERVER_TYPES recvType, uint32_t nMsgId,
                                const google::protobuf::Message &xData, uint64_t valueId = 0);

    virtual int SendMsgToServer(NF_SERVER_TYPES eSendType, NF_SERVER_TYPES recvType, uint32_t busId, uint32_t nMsgId,
                                const google::protobuf::Message &xData, uint64_t valueId = 0);

    virtual int
    SendMsgToMasterServer(NF_SERVER_TYPES eSendTyp, uint32_t nMsgId, const google::protobuf::Message &xData, uint64_t valueId = 0);

    virtual NF_SHARE_PTR<NFServerData> GetServerByServerId(NF_SERVER_TYPES eSendType, uint32_t busId);

    virtual NF_SHARE_PTR<NFServerData> GetServerByUnlinkId(NF_SERVER_TYPES eSendType, uint64_t unlinkId);


    virtual NF_SHARE_PTR<NFServerData> CreateServerByServerId(NF_SERVER_TYPES eSendType, uint32_t busId, NF_SERVER_TYPES busServerType,
                                                              const proto_ff::ServerInfoReport &data);

    virtual void CreateLinkToServer(NF_SERVER_TYPES eSendType, uint32_t busId,
                                    uint64_t linkId);

    virtual void DelServerLink(NF_SERVER_TYPES eSendType, uint64_t linkId);

    virtual NFServerData *GetRouteData(NF_SERVER_TYPES eSendType);

    virtual const NFServerData *GetRouteData(NF_SERVER_TYPES eSendType) const;

    virtual NFServerData *GetMasterData(NF_SERVER_TYPES eSendType);

    virtual const NFServerData *GetMasterData(NF_SERVER_TYPES eSendType) const;

    virtual void CloseAllLink(NF_SERVER_TYPES eSendType);

    virtual uint64_t GetServerLinkId(NF_SERVER_TYPES eSendType) const;

    virtual void SetServerLinkId(NF_SERVER_TYPES eSendType, uint64_t linkId);

    virtual std::vector<NF_SHARE_PTR<NFServerData>>
    GetServerByServerType(NF_SERVER_TYPES eSendType, NF_SERVER_TYPES serverTypes);

    virtual NF_SHARE_PTR<NFServerData>
    GetFirstServerByServerType(NF_SERVER_TYPES eSendType, NF_SERVER_TYPES serverTypes);

    virtual NF_SHARE_PTR<NFServerData>
    GetRandomServerByServerType(NF_SERVER_TYPES eSendType, NF_SERVER_TYPES serverTypes);

    virtual NF_SHARE_PTR<NFServerData>
    GetSuitServerByServerType(NF_SERVER_TYPES eSendType, NF_SERVER_TYPES serverTypes, uint64_t value);

    virtual NF_SHARE_PTR<NFServerData>
    GetSuitServerByServerType(NF_SERVER_TYPES eSendType, NF_SERVER_TYPES serverTypes, const std::string& value);

    virtual std::vector<NF_SHARE_PTR<NFServerData>> GetAllServer(NF_SERVER_TYPES eSendType);

    virtual std::vector<NF_SHARE_PTR<NFServerData>> GetAllServer(NF_SERVER_TYPES eSendType, NF_SERVER_TYPES serverTypes);

    virtual std::vector<std::string> GetDBNames(NF_SERVER_TYPES eSendType);
public:
    template<typename BaseType>
    bool AddHttpRequestHandler(NF_SERVER_TYPES serverType, const std::string &strPath, const NFHttpType eRequestType,
                               BaseType *pBase, bool (BaseType::*handleRecieve)(uint32_t, const NFIHttpHandle &req)) {
        HTTP_RECEIVE_FUNCTOR functor = std::bind(handleRecieve, pBase, std::placeholders::_1, std::placeholders::_2);
        return m_pMessageModule->AddHttpMsgCB(serverType, strPath, eRequestType, functor);
    }

    template<typename BaseType>
    bool AddHttpRequestHandler(NF_SERVER_TYPES serverType, const NFHttpType eRequestType, BaseType *pBase,
                               bool (BaseType::*handleRecieve)(uint32_t, const NFIHttpHandle &req)) {
        HTTP_RECEIVE_FUNCTOR functor = std::bind(handleRecieve, pBase, std::placeholders::_1, std::placeholders::_2);
        return m_pMessageModule->AddHttpOtherMsgCB(serverType, eRequestType, functor);
    }

    template<typename BaseType>
    bool AddHttpNetFilter(NF_SERVER_TYPES serverType, const std::string &strPath, BaseType *pBase,
                          NFWebStatus(BaseType::*handleFilter)(uint32_t, const NFIHttpHandle &req)) {
        HTTP_FILTER_FUNCTOR functor = std::bind(handleFilter, pBase, std::placeholders::_1, std::placeholders::_2);

        return m_pMessageModule->AddHttpFilterCB(serverType, strPath, functor);
    }

    virtual bool ResponseHttpMsg(NF_SERVER_TYPES serverType, const NFIHttpHandle &req, const std::string &strMsg,
                                 NFWebStatus code = NFWebStatus::WEB_OK, const std::string &reason = "OK");

    virtual bool ResponseHttpMsg(NF_SERVER_TYPES serverType, uint64_t requestId, const std::string &strMsg,
                                 NFWebStatus code = NFWebStatus::WEB_OK,
                                 const std::string &reason = "OK");

    virtual int HttpGet(NF_SERVER_TYPES serverType, const std::string &strUri,
                        const HTTP_CLIENT_RESPONE &respone,
                        const std::map<std::string, std::string> &xHeaders = std::map<std::string, std::string>(),
                        int timeout = 3);

    virtual int HttpPost(NF_SERVER_TYPES serverType, const std::string &strUri, const std::string &strPostData, const HTTP_CLIENT_RESPONE &respone,
                         const std::map<std::string, std::string> &xHeaders = std::map<std::string, std::string>(),
                         int timeout = 3);
public:
    template<typename BaseType>
    bool AddMessageCallBack(NF_SERVER_TYPES eType, uint32_t nMsgID, BaseType* pBase, int (BaseType::*handleRecieve)(uint64_t unLinkId, uint64_t valueId, uint64_t value2, uint32_t nMsgId, const char* msg, uint32_t nLen))
    {
        NF_ASSERT_MSG((TIsDerived<BaseType, NFIDynamicModule>::Result), "the class must inherit NFIDynamicModule");
        NET_RECEIVE_FUNCTOR functor = std::bind(handleRecieve, pBase, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4, std::placeholders::_5, std::placeholders::_6);
        return AddMessageCallBack(eType, nMsgID, pBase, functor);
    }

    template <typename BaseType>
    bool AddOtherCallBack(NF_SERVER_TYPES eType, uint64_t linkId, BaseType* pBase, int (BaseType::*handleRecieve)(uint64_t unLinkId, uint64_t valueId, uint64_t value2, uint32_t nMsgId, const char* msg, uint32_t nLen))
    {
        NF_ASSERT_MSG((TIsDerived<BaseType, NFIDynamicModule>::Result), "the class must inherit NFIDynamicModule");
        NET_RECEIVE_FUNCTOR functor = std::bind(handleRecieve, pBase, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4, std::placeholders::_5, std::placeholders::_6);

        return AddOtherCallBack(eType, linkId, pBase, functor);
    }

    template <typename BaseType>
    bool AddEventCallBack(NF_SERVER_TYPES eType, uint64_t linkId, BaseType* pBase, int (BaseType::*handler)(eMsgType nEvent, uint64_t unLinkId))
    {
        NF_ASSERT_MSG((TIsDerived<BaseType, NFIDynamicModule>::Result), "the class must inherit NFIMessageProcessor");
        NET_EVENT_FUNCTOR functor = std::bind(handler, pBase, std::placeholders::_1, std::placeholders::_2);
        return AddEventCallBack(eType, linkId, pBase, functor);
    }

public:
    virtual bool DelAllCallBack(void *pTarget);

    virtual bool AddMessageCallBack(NF_SERVER_TYPES eType, uint32_t nMsgID, void* pTaraget, const NET_RECEIVE_FUNCTOR & cb);

    virtual bool AddOtherCallBack(NF_SERVER_TYPES eType, uint64_t linkId, void* pTaraget, const NET_RECEIVE_FUNCTOR & cb);

    virtual bool AddEventCallBack(NF_SERVER_TYPES eType, uint64_t linkId, void* pTaraget, const NET_EVENT_FUNCTOR& cb);
protected:
    NFIMessageModule* m_pMessageModule;
};
