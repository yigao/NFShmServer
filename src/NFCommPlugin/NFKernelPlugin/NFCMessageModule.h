// -------------------------------------------------------------------------
//    @FileName         :    NFCMsgModule.h
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFPluginModule
//
// -------------------------------------------------------------------------

#pragma once

#include "NFComm/NFPluginModule/NFIMessageModule.h"
#include "NFComm/NFPluginModule/NFIMessageDriver.h"
#include "NFComm/NFPluginModule/NFIHttpHandle.h"
#include "NFComm/NFCore/NFMapEx.hpp"
#include <stdint.h>

struct NetReceiveFunctor
{
    NetReceiveFunctor()
    {
        m_pTarget = NULL;
        m_pFunctor = NULL;
        m_iCount = 0;
        m_iAllUseTime = 0;
        m_iMinTime = 1000000000;
        m_iMaxTime = 0;
    }

    NetReceiveFunctor(void *pTarget, const NET_RECEIVE_FUNCTOR& functor):m_pTarget(pTarget),m_pFunctor(functor)
    {
        m_iCount = 0;
        m_iAllUseTime = 0;
        m_iMinTime = 1000000000;
        m_iMaxTime = 0;
    }

    NetReceiveFunctor(const NetReceiveFunctor& functor)
    {
        if (this != &functor)
        {
            m_pTarget = functor.m_pTarget;
            m_pFunctor = functor.m_pFunctor;
            m_iCount = functor.m_iCount;;
            m_iAllUseTime = functor.m_iAllUseTime;
            m_iMinTime = functor.m_iMinTime;
            m_iMaxTime = functor.m_iMaxTime;
        }
    }

    NetReceiveFunctor& operator=(const NetReceiveFunctor& functor)
    {
        if (this != &functor)
        {
            m_pTarget = functor.m_pTarget;
            m_pFunctor = functor.m_pFunctor;
            m_iCount = functor.m_iCount;;
            m_iAllUseTime = functor.m_iAllUseTime;
            m_iMinTime = functor.m_iMinTime;
            m_iMaxTime = functor.m_iMaxTime;
        }

        return *this;
    }

    void* m_pTarget;
    NET_RECEIVE_FUNCTOR m_pFunctor;
    uint64_t m_iCount;
    uint64_t m_iAllUseTime;
    uint64_t m_iMinTime;
    uint64_t m_iMaxTime;
};

struct NetEventFunctor
{
    NetEventFunctor()
    {
        m_pTarget = NULL;
        m_pFunctor = NULL;
    }

    NetEventFunctor(void *pTarget, const NET_EVENT_FUNCTOR& functor):m_pTarget(pTarget),m_pFunctor(functor)
    {
    }

    NetEventFunctor(const NetEventFunctor& functor)
    {
        if (this != &functor)
        {
            m_pTarget = functor.m_pTarget;
            m_pFunctor = functor.m_pFunctor;
        }
    }

    NetEventFunctor& operator=(const NetEventFunctor& functor)
    {
        if (this != &functor)
        {
            m_pTarget = functor.m_pTarget;
            m_pFunctor = functor.m_pFunctor;
        }

        return *this;
    }

    void* m_pTarget;
    NET_EVENT_FUNCTOR m_pFunctor;
};

struct CallBack {
    //call back
    std::unordered_map<uint32_t, NetReceiveFunctor> mxReceiveCallBack;
    std::unordered_map<uint64_t, NetEventFunctor> mxEventCallBack;
    std::unordered_map<uint64_t, NetReceiveFunctor> mxCallBackList;
    std::map<NFHttpType, map<std::string, HTTP_RECEIVE_FUNCTOR>> mxHttpMsgCBMap;
    std::map<NFHttpType, std::vector<HTTP_RECEIVE_FUNCTOR>> mxHttpOtherMsgCBMap;
    std::unordered_map<std::string, HTTP_FILTER_FUNCTOR> mxHttpMsgFliterMap;
};

struct ServerLinkData {
    ServerLinkData() {
        mServerType = NF_ST_NONE;
        m_serverLinkId = 0;
        mServerList.resize(NF_ST_MAX);
        mServerListMap.resize(NF_ST_MAX);
    }

    NFMapEx<uint32_t, NFServerData> mServerMap;
    std::vector<std::vector<NF_SHARE_PTR<NFServerData>>> mServerList;
    std::vector<NFConsistentHashMapEx<uint32_t, NFServerData>> mServerListMap;
    NFMapEx<std::string, NFConsistentHashMapEx<uint32_t, NFServerData>> mDBStoreServerMap;
    std::map<uint64_t, uint32_t> mLinkIdToBusIdMap; //linkid -- busid
    NFServerData m_routeData;
    NFServerData m_masterServerData;
    NF_SERVER_TYPES mServerType;
    uint64_t m_serverLinkId;

    uint64_t GetServerLinkId() const;

    void SetServerLinkId(uint64_t linkId);

    NF_SHARE_PTR<NFServerData> GetServerByServerId(uint32_t busId);

    NF_SHARE_PTR<NFServerData> GetServerByUnlinkId(uint64_t unlinkId);

    NF_SHARE_PTR<NFServerData> CreateServerByServerId(uint32_t busId, NF_SERVER_TYPES busServerType, const proto_ff::ServerInfoReport &data);

    virtual void CloseServer(NF_SERVER_TYPES destServer, uint32_t busId, uint64_t usLinkId);

    virtual void CreateLinkToServer(uint32_t busId, uint64_t linkId);

    void DelServerLink(uint64_t linkId);

    NFServerData *GetRouteData() { return &m_routeData; }

    const NFServerData *GetRouteData() const { return &m_routeData; }

    NFServerData *GetMasterData() { return &m_masterServerData; }

    const NFServerData *GetMasterData() const { return &m_masterServerData; }

    virtual int SendMsgByBusId(NFIMessageModule *pMessageModule, uint32_t busId, uint32_t nMsgId,
                               const google::protobuf::Message &xData, uint64_t valueId);

    virtual int
    SendMsgByBusId(NFIMessageModule *pMessageModule, uint32_t busId, uint16_t nMainMsgId, uint16_t nSubMsgId,
                   const google::protobuf::Message &xData, uint64_t valueId);

    virtual int SendMsgByBusId(NFIMessageModule *pMessageModule, uint32_t busId, uint32_t nMsgId,
                               const char *msg, uint32_t nLen, uint64_t valueId);

    virtual int
    SendMsgByBusId(NFIMessageModule *pMessageModule, uint32_t busId, uint16_t nMainMsgId, uint16_t nSubMsgId,
                   const char *msg, uint32_t nLen, uint64_t valueId);

    virtual int SendProxyMsgByBusId(NFIMessageModule *pMessageModule, uint32_t busId, uint32_t nMsgId,
                               const google::protobuf::Message &xData, uint64_t valueId);

    virtual int
    SendProxyMsgByBusId(NFIMessageModule *pMessageModule, uint32_t busId, uint16_t nMainMsgId, uint16_t nSubMsgId,
                   const google::protobuf::Message &xData, uint64_t valueId);

    virtual int SendProxyMsgByBusId(NFIMessageModule *pMessageModule, uint32_t busId, uint32_t nMsgId,
                               const char *msg, uint32_t nLen, uint64_t valueId);

    virtual int
    SendProxyMsgByBusId(NFIMessageModule *pMessageModule, uint32_t busId, uint16_t nMainMsgId, uint16_t nSubMsgId,
                   const char *msg, uint32_t nLen, uint64_t valueId);

    virtual int
    SendMsgToWebServer(NFIMessageModule *pMessageModule, uint32_t nMsgId, const google::protobuf::Message &xData,
                         uint64_t valueId);

    virtual int
    SendMsgToWorldServer(NFIMessageModule *pMessageModule, uint32_t nMsgId, const google::protobuf::Message &xData,
                         uint64_t valueId);

    virtual int
    SendMsgToGameServer(NFIMessageModule *pMessageModule, uint32_t busId, uint32_t nMsgId, const google::protobuf::Message &xData,
                         uint64_t valueId);

    virtual int
    SendMsgToLoginServer(NFIMessageModule *pMessageModule, uint32_t busId, uint32_t nMsgId, const google::protobuf::Message &xData,
                         uint64_t valueId);

	virtual int
		SendMsgToLogicServer(NFIMessageModule *pMessageModule, uint32_t busId, uint32_t nMsgId, const google::protobuf::Message &xData,
			uint64_t valueId);

    virtual int
    SendMsgToLogicServer(NFIMessageModule *pMessageModule, uint32_t busId, uint32_t nMsgId, const char* msg, int msgLen,
                         uint64_t valueId);

    virtual int
    SendMsgToSuitLogicServer(NFIMessageModule *pMessageModule, uint64_t userId, uint32_t nMsgId, const google::protobuf::Message &xData, bool online = false);

	virtual int
		SendMsgToSnsServer(NFIMessageModule *pMessageModule, uint32_t nMsgId, const google::protobuf::Message &xData,
			uint64_t valueId);

    virtual int SendTransToWebServer(NFIMessageModule *pMessageModule, uint32_t nMsgId, const google::protobuf::Message &xData,
                                       uint32_t req_trans_id = 0, uint32_t rsp_trans_id = 0);

    virtual int SendTransToWorldServer(NFIMessageModule *pMessageModule, uint32_t nMsgId, const google::protobuf::Message &xData,
                           uint32_t req_trans_id = 0, uint32_t rsp_trans_id = 0);

    virtual int SendTransToLoginServer(NFIMessageModule *pMessageModule, uint32_t busId, uint32_t nMsgId, const google::protobuf::Message &xData,
                                       uint32_t req_trans_id = 0, uint32_t rsp_trans_id = 0);

	virtual int SendTransToLogicServer(NFIMessageModule *pMessageModule, uint32_t busId, uint32_t nMsgId, const google::protobuf::Message &xData,
			uint32_t req_trans_id = 0, uint32_t rsp_trans_id = 0);

	virtual int SendTransToSnsServer(NFIMessageModule *pMessageModule, uint32_t nMsgId, const google::protobuf::Message &xData,
		uint32_t req_trans_id = 0, uint32_t rsp_trans_id = 0);

	virtual int SendTransToGameServer(NFIMessageModule *pMessageModule, uint32_t nMsgId, uint32_t gameBusId, const google::protobuf::Message &xData,
		uint32_t req_trans_id = 0, uint32_t rsp_trans_id = 0);

    virtual int SendTransToStoreServer(NFIMessageModule *pMessageModule, uint32_t cmd, uint32_t table_id,
                                       const std::string &dbname, const std::string &table_name, const std::string &xData,
                                       int trans_id = 0, uint32_t seq = 0,
                                       uint64_t mod_key = 0);

    virtual int SendTransToStoreServer(NFIMessageModule *pMessageModule, uint32_t cmd, uint32_t table_id,
									   const std::string &dbname, const std::string &table_name, const google::protobuf::Message &xData,
                                       int trans_id = 0, uint32_t seq = 0,
                                       uint64_t mod_key = 0, const std::string& cls_name = "");

    virtual int SendTransToStoreServer(NFIMessageModule *pMessageModule, uint32_t cmd, uint32_t table_id,
										const std::string &dbname, const std::string &table_name,
                                        std::vector<storesvr_sqldata::storesvr_vk> vk_list,
                                        const std::string &where_addtional_conds, int trans_id = 0, uint32_t seq = 0,
                                        uint64_t mod_key = 0, const std::string& cls_name = "");

    virtual int SendTransToStoreServer(NFIMessageModule *pMessageModule, uint32_t cmd, uint32_t table_id,
                                       const std::string &dbname, const std::string &table_name, const google::protobuf::Message &xData,
                                       std::vector<storesvr_sqldata::storesvr_vk> vk_list,
                                       const std::string &where_addtional_conds, int trans_id = 0, uint32_t seq = 0,
                                       uint64_t mod_key = 0, const std::string& cls_name = "");

    virtual int SendMsgToServer(NFIMessageModule *pMessageModule, NF_SERVER_TYPES recvType, uint32_t nMsgId,
                                const google::protobuf::Message &xData, uint64_t valueId);

    virtual int
    SendMsgToServer(NFIMessageModule *pMessageModule, NF_SERVER_TYPES recvType, uint16_t nMainMsgId, uint16_t nSubMsgId,
                    const google::protobuf::Message &xData, uint64_t valueId);

    virtual int
    SendMsgToServer(NFIMessageModule *pMessageModule, NF_SERVER_TYPES recvType, uint32_t busId, uint32_t nMsgId,
                    const google::protobuf::Message &xData, uint64_t valueId);

    virtual int
    SendMsgToServer(NFIMessageModule *pMessageModule, NF_SERVER_TYPES recvType, uint32_t busId, uint16_t nMainMsgId,
                    uint16_t nSubMsgId, const google::protobuf::Message &xData, uint64_t valueId);

    void CloseAllLink(NFIMessageModule *pMessageModule);

    virtual int
    SendMsgToMasterServer(NFIMessageModule *pMessageModule, uint32_t nMsgId, const google::protobuf::Message &xData, uint64_t valueId = 0);

    std::vector<NF_SHARE_PTR<NFServerData>> GetServerByServerType(NF_SERVER_TYPES serverTypes);

    NF_SHARE_PTR<NFServerData> GetFirstServerByServerType(NF_SERVER_TYPES serverTypes);

    NF_SHARE_PTR<NFServerData> GetRandomServerByServerType(NF_SERVER_TYPES serverTypes);

    NF_SHARE_PTR<NFServerData> GetSuitServerByServerType(NF_SERVER_TYPES serverTypes, uint64_t value);

    NF_SHARE_PTR<NFServerData> GetSuitServerByServerType(NF_SERVER_TYPES serverTypes, const std::string& value);

    std::vector<NF_SHARE_PTR<NFServerData>> GetAllServer();

    std::vector<NF_SHARE_PTR<NFServerData>> GetAllServer(NF_SERVER_TYPES serverTypes);

    std::vector<std::string> GetDBNames();
};

class NFCMessageModule : public NFIMessageModule {
public:
    explicit NFCMessageModule(NFIPluginManager *p);

    virtual ~NFCMessageModule();

    virtual bool Awake() override;

    virtual bool Finalize() override;

    virtual bool Execute() override;

    virtual bool OnReloadPlugin() override;

    /**
     * @brief 添加服务器
     *
     * @param  eType		服务器类型
     * @param  nServerID	服务器ID
     * @param  nMaxClient	服务器最大连接客户端数
     * @param  nPort		服务器监听端口
     * @return int			返回0错误
     */
    virtual int64_t
    BindServer(NF_SERVER_TYPES eServerType, const std::string &url, uint32_t nNetThreadNum = 1, uint32_t nMaxConnectNum = 100, uint32_t nPacketParseType = PACKET_PARSE_TYPE_INTERNAL) override;

    /**
     * @brief 添加服务器
     *
     * @param  eType		服务器类型
     * @param  nServerID	服务器ID
     * @param  nMaxClient	服务器最大连接客户端数
     * @param  nPort		服务器监听端口
     * @return int			返回0错误
     */
	virtual int64_t ConnectServer(NF_SERVER_TYPES eServerType, const std::string& url, uint32_t nPacketParseType = 0) override;

    virtual int ResumeConnect(NF_SERVER_TYPES eServerType) override;

	virtual std::string GetLinkIp(uint64_t usLinkId) override;

	virtual void CloseLinkId(uint64_t usLinkId) override;

    virtual void CloseServer(NF_SERVER_TYPES eServerType, NF_SERVER_TYPES destServer, uint32_t busId, uint64_t usLinkId) override;

    virtual void Send(uint64_t usLinkId, uint32_t nMsgID, const std::string& strData, uint64_t nSendValue = 0, uint64_t nSendId = 0) override;

    virtual void Send(uint64_t usLinkId, uint32_t nMsgID, const char* msg, uint32_t nLen, uint64_t nSendValue = 0, uint64_t nSendId = 0) override;

    virtual void Send(uint64_t usLinkId, uint32_t nMsgID, const google::protobuf::Message& xData, uint64_t nSendValue = 0, uint64_t nSendId = 0) override;

    virtual void Send(uint64_t usLinkId, uint16_t nMainMsgID, uint16_t nSubMsgID, const std::string& strData, uint64_t nSendValue = 0, uint64_t nSendId = 0) override;

    virtual void Send(uint64_t usLinkId, uint16_t nMainMsgID, uint16_t nSubMsgID, const char *msg, uint32_t nLen,
                      uint64_t nSendValue = 0, uint64_t nSendId = 0) override;

    virtual void
    Send(uint64_t usLinkId, uint16_t nMainMsgID, uint16_t nSubMsgID, const google::protobuf::Message &xData,
         uint64_t nSendValue = 0, uint64_t nSendId = 0) override;

    virtual void
    SendTrans(uint64_t usLinkId, uint32_t nMsgID, const google::protobuf::Message &xData, uint64_t nSendValue = 0,
              uint64_t nSendId = 0, uint32_t req_trans_id = 0, uint32_t rsp_trans_id = 0) override;

    virtual void
    SendStore(uint64_t usLinkId, uint32_t cmd, uint32_t table_id, uint64_t sendLinkId, uint64_t destLinkId,
              const std::string &dbname, const std::string &table_name, const std::string &xData, int trans_id = 0, uint32_t seq = 0,
              uint64_t mod_key = 0, uint8_t packet_type = proto_ff::E_DISP_TYPE_BY_TRANSACTION) override;

    virtual void
    SendStore(uint64_t usLinkId, uint32_t cmd, uint32_t table_id, uint64_t sendLinkId, uint64_t destLinkId,
			  const std::string &dbname, const std::string &table_name, const google::protobuf::Message &xData, int trans_id = 0, uint32_t seq = 0,
              uint64_t mod_key = 0, uint8_t packet_type = proto_ff::E_DISP_TYPE_BY_TRANSACTION, const std::string& cls_name = "") override;

    virtual void
    SendStore(uint64_t usLinkId, uint32_t cmd, uint32_t table_id, uint64_t sendLinkId, uint64_t destLinkId,
		      const std::string &dbname, const std::string &table_name, std::vector<storesvr_sqldata::storesvr_vk> vk_list,
              const std::string &where_addtional_conds, int trans_id = 0, uint32_t seq = 0,
              uint64_t mod_key = 0, uint8_t packet_type = proto_ff::E_DISP_TYPE_BY_TRANSACTION, const std::string& cls_name = "") override;

    virtual void
    SendStore(uint64_t usLinkId, uint32_t cmd, uint32_t table_id, uint64_t sendLinkId, uint64_t destLinkId,
              const std::string &dbname, const std::string &table_name, const google::protobuf::Message &xData, std::vector<storesvr_sqldata::storesvr_vk> vk_list,
              const std::string &where_addtional_conds, int trans_id = 0, uint32_t seq = 0,
              uint64_t mod_key = 0, uint8_t packet_type = proto_ff::E_DISP_TYPE_BY_TRANSACTION, const std::string& cls_name = "") override;

    virtual int
    SendMsgByBusId(NF_SERVER_TYPES eType, uint32_t busId, uint32_t nMsgId, const google::protobuf::Message &xData,
                   uint64_t valueId) override;

    virtual int SendMsgByBusId(NF_SERVER_TYPES eType, uint32_t busId, uint16_t nMainMsgId, uint16_t nSubMsgId,
                               const google::protobuf::Message &xData, uint64_t valueId) override;

    virtual int
    SendMsgByBusId(NF_SERVER_TYPES eType, uint32_t busId, uint32_t nMsgId, const char *msg, uint32_t nLen,
                   uint64_t valueId) override;

    virtual int SendMsgByBusId(NF_SERVER_TYPES eType, uint32_t busId, uint16_t nMainMsgId, uint16_t nSubMsgId,
                               const char *msg, uint32_t nLen, uint64_t valueId) override;

    virtual int
    SendProxyMsgByBusId(NF_SERVER_TYPES eType, uint32_t busId, uint32_t nMsgId, const google::protobuf::Message &xData,
                   uint64_t valueId) override;

    virtual int SendProxyMsgByBusId(NF_SERVER_TYPES eType, uint32_t busId, uint16_t nMainMsgId, uint16_t nSubMsgId,
                               const google::protobuf::Message &xData, uint64_t valueId) override;

    virtual int
    SendProxyMsgByBusId(NF_SERVER_TYPES eType, uint32_t busId, uint32_t nMsgId, const char *msg, uint32_t nLen,
                   uint64_t valueId) override;

    virtual int SendProxyMsgByBusId(NF_SERVER_TYPES eType, uint32_t busId, uint16_t nMainMsgId, uint16_t nSubMsgId,
                               const char *msg, uint32_t nLen, uint64_t valueId) override;

    virtual int
    SendMsgToProxyServer(NF_SERVER_TYPES eType, uint32_t busId, uint32_t nMsgId, const google::protobuf::Message &xData,
                         uint64_t valueId) override;

    virtual int SendMsgToProxyServer(NF_SERVER_TYPES eType, uint32_t busId, uint16_t nMainMsgId, uint16_t nSubMsgId,
                                     const google::protobuf::Message &xData, uint64_t valueId) override;

    virtual int
    SendMsgToProxyServer(NF_SERVER_TYPES eType, uint32_t busId, uint32_t nMsgId, const char *msg, uint32_t nLen,
                         uint64_t valueId) override;

    virtual int SendMsgToProxyServer(NF_SERVER_TYPES eType, uint32_t busId, uint16_t nMainMsgId, uint16_t nSubMsgId,
                                     const char *msg, uint32_t nLen, uint64_t valueId) override;

    virtual int
    SendMsgToWebServer(NF_SERVER_TYPES eType, uint64_t requestId, int32_t result, const std::string& err_msg) override;

    virtual int SendMsgToWebServer(NF_SERVER_TYPES eType, uint32_t nMsgId, const google::protobuf::Message &xData,
                                     uint64_t valueId = 0) override;


    virtual int SendMsgToWorldServer(NF_SERVER_TYPES eType, uint32_t nMsgId, const google::protobuf::Message &xData,
                                     uint64_t valueId = 0) override;

    virtual int
    SendMsgToGameServer(NF_SERVER_TYPES eType, uint32_t busId, uint32_t nMsgId, const google::protobuf::Message &xData, uint64_t valueId = 0) override;

    virtual int SendMsgToLoginServer(NF_SERVER_TYPES eType, uint32_t busId, uint32_t nMsgId, const google::protobuf::Message &xData,
                                     uint64_t valueId = 0) override;

	virtual int SendMsgToLogicServer(NF_SERVER_TYPES eType, uint32_t busId, uint32_t nMsgId, const google::protobuf::Message &xData,
		uint64_t valueId = 0) override;

    virtual int SendMsgToLogicServer(NF_SERVER_TYPES eType, uint32_t busId, uint32_t nMsgId, const char* msg, int nLen,
                                     uint64_t valueId = 0) override;

    virtual int SendMsgToSuitLogicServer(NF_SERVER_TYPES eType, uint64_t userId, uint32_t nMsgId, const google::protobuf::Message &xData, bool online = false) override;

	virtual int SendMsgToSnsServer(NF_SERVER_TYPES eType, uint32_t nMsgId, const google::protobuf::Message &xData,
		uint64_t valueId = 0) override;

    virtual int SendTransToWebServer(NF_SERVER_TYPES eType, uint32_t nMsgId, const google::protobuf::Message &xData,
                                       uint32_t req_trans_id = 0, uint32_t rsp_trans_id = 0) override;


    virtual int SendTransToWorldServer(NF_SERVER_TYPES eType, uint32_t nMsgId, const google::protobuf::Message &xData,
                                       uint32_t req_trans_id = 0, uint32_t rsp_trans_id = 0) override;

    virtual int SendTransToLoginServer(NF_SERVER_TYPES eType, uint32_t busId, uint32_t nMsgId, const google::protobuf::Message &xData,
                                       uint32_t req_trans_id = 0, uint32_t rsp_trans_id = 0) override;

	virtual int SendTransToLogicServer(NF_SERVER_TYPES eType, uint32_t busId, uint32_t nMsgId, const google::protobuf::Message &xData,
		uint32_t req_trans_id = 0, uint32_t rsp_trans_id = 0) override;


	virtual int SendTransToSnsServer(NF_SERVER_TYPES eType, uint32_t nMsgId, const google::protobuf::Message &xData,
		uint32_t req_trans_id = 0, uint32_t rsp_trans_id = 0) override;

	virtual int SendTransToGameServer(NF_SERVER_TYPES eType, uint32_t nMsgId, uint32_t gameBusId, const google::protobuf::Message &xData,
		uint32_t req_trans_id = 0, uint32_t rsp_trans_id = 0) override;

    virtual int SendTransToStoreServer(NF_SERVER_TYPES eType, uint32_t cmd, uint32_t table_id,
                                       const std::string &dbname, const std::string &table_name, const std::string &xData,
                                       int trans_id = 0, uint32_t seq = 0,
                                       uint64_t mod_key = 0) override;

    virtual int SendTransToStoreServer(NF_SERVER_TYPES eType, uint32_t cmd, uint32_t table_id,
										const std::string &dbname, const std::string &table_name, const google::protobuf::Message &xData,
                                       int trans_id = 0, uint32_t seq = 0,
                                       uint64_t mod_key = 0, const std::string& cls_name = "") override;

    virtual int SendTransToStoreServer(NF_SERVER_TYPES eType, uint32_t cmd, uint32_t table_id,
										const std::string &dbname, const std::string &table_name,
                                        std::vector<storesvr_sqldata::storesvr_vk> vk_list,
                                        const std::string &where_addtional_conds, int trans_id = 0, uint32_t seq = 0,
                                        uint64_t mod_key = 0, const std::string& cls_name = "") override;

    virtual int SendTransToStoreServer(NF_SERVER_TYPES eType, uint32_t cmd, uint32_t table_id,
                                       const std::string &dbname, const std::string &table_name, const google::protobuf::Message &xData,
                                       std::vector<storesvr_sqldata::storesvr_vk> vk_list,
                                       const std::string &where_addtional_conds, int trans_id = 0, uint32_t seq = 0,
                                       uint64_t mod_key = 0, const std::string& cls_name = "") override;

    virtual int SendDescStoreToStoreServer(NF_SERVER_TYPES eType, const std::string& dbName, const std::string &table_name, const google::protobuf::Message *pMessage, const RPC_TRANS_DESC_STORE_CB& cb) override;

    virtual int SendMsgToServer(NF_SERVER_TYPES eSendType, NF_SERVER_TYPES recvType, uint32_t nMsgId,
                                const google::protobuf::Message &xData, uint64_t valueId = 0) override;

    virtual int SendMsgToServer(NF_SERVER_TYPES eSendType, NF_SERVER_TYPES recvType, uint32_t busId, uint32_t nMsgId,
                                const google::protobuf::Message &xData, uint64_t valueId = 0) override;

    virtual int
    SendMsgToMasterServer(NF_SERVER_TYPES eSendTyp, uint32_t nMsgId, const google::protobuf::Message &xData, uint64_t valueId = 0) override;

    virtual NF_SHARE_PTR<NFServerData> GetServerByServerId(NF_SERVER_TYPES eSendType, uint32_t busId) override;

    virtual NF_SHARE_PTR<NFServerData> GetServerByUnlinkId(NF_SERVER_TYPES eSendType, uint64_t unlinkId) override;


    virtual NF_SHARE_PTR<NFServerData> CreateServerByServerId(NF_SERVER_TYPES eSendType, uint32_t busId, NF_SERVER_TYPES busServerType, const proto_ff::ServerInfoReport &data) override;

    virtual void CreateLinkToServer(NF_SERVER_TYPES eSendType, uint32_t busId,
                                                          uint64_t linkId) override;

    virtual void DelServerLink(NF_SERVER_TYPES eSendType, uint64_t linkId) override;

    virtual NFServerData* GetRouteData(NF_SERVER_TYPES eSendType) override;
    virtual const NFServerData* GetRouteData(NF_SERVER_TYPES eSendType) const override;

    virtual NFServerData* GetMasterData(NF_SERVER_TYPES eSendType) override;
    virtual const NFServerData* GetMasterData(NF_SERVER_TYPES eSendType) const override;

    virtual void CloseAllLink(NF_SERVER_TYPES eSendType) override;

    virtual uint64_t GetServerLinkId(NF_SERVER_TYPES eSendType) const override;

    virtual void SetServerLinkId(NF_SERVER_TYPES eSendType, uint64_t linkId) override;

    virtual std::vector<NF_SHARE_PTR<NFServerData>> GetServerByServerType(NF_SERVER_TYPES eSendType, NF_SERVER_TYPES serverTypes) override;

    virtual NF_SHARE_PTR<NFServerData> GetFirstServerByServerType(NF_SERVER_TYPES eSendType, NF_SERVER_TYPES serverTypes) override;

    virtual NF_SHARE_PTR<NFServerData>
    GetRandomServerByServerType(NF_SERVER_TYPES eSendType, NF_SERVER_TYPES serverTypes) override;

    virtual NF_SHARE_PTR<NFServerData>
    GetSuitServerByServerType(NF_SERVER_TYPES eSendType, NF_SERVER_TYPES serverTypes, uint64_t value) override;

    virtual NF_SHARE_PTR<NFServerData>
    GetSuitServerByServerType(NF_SERVER_TYPES eSendType, NF_SERVER_TYPES serverTypes, const std::string& value) override;

    virtual std::vector<NF_SHARE_PTR<NFServerData>> GetAllServer(NF_SERVER_TYPES eSendType) override;

    virtual std::vector<NF_SHARE_PTR<NFServerData>> GetAllServer(NF_SERVER_TYPES eSendType, NF_SERVER_TYPES serverTypes) override;

    virtual std::vector<std::string> GetDBNames(NF_SERVER_TYPES eSendType) override;
public:
    /// @brief 设置通信驱动(通信库)，运行时只支持一种通信驱动，如rawudp，tbuspp或第3方网络库
    /// @param driver 对MessageDriver接口实现的网络库
    /// @return 0 表示成功
    /// @return -1 表示失败
    void SetMessageDriver(NFIMessageDriver *driver);

public:
    virtual bool DelAllCallBack(void *pTarget) override;

    virtual bool DelAllCallBack(NF_SERVER_TYPES eType, uint64_t unLinkId) override;

    virtual bool AddMessageCallBack(NF_SERVER_TYPES eType, uint32_t nMsgID, void *pTaraget,
                                    const NET_RECEIVE_FUNCTOR &cb) override;

    virtual bool AddOtherCallBack(NF_SERVER_TYPES eType, uint64_t linkId, void *pTaraget,
                                  const NET_RECEIVE_FUNCTOR &cb) override;

    virtual bool
    AddEventCallBack(NF_SERVER_TYPES eType, uint64_t linkId, void *pTaraget, const NET_EVENT_FUNCTOR &cb) override;

    int OnReceiveNetPack(uint64_t connectionLink, uint64_t objectLinkId, uint64_t nSendValue, uint64_t nOtherValue,
                         uint32_t nMsgId, const char *msg, uint32_t nLen);

	int OnHandleReceiveNetPack(uint64_t connectionLink, uint64_t objectLinkId, uint64_t nSendValue, uint64_t nOtherValue,
		uint32_t nMsgId, const char *msg, uint32_t nLen);

    int OnSocketNetEvent(eMsgType nEvent, uint64_t connectionLink, uint64_t objectLinkId);

public:
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
protected:
    virtual bool AddHttpMsgCB(NF_SERVER_TYPES serverType, const std::string &strCommand, const NFHttpType eRequestType,
                              const HTTP_RECEIVE_FUNCTOR &cb);

    virtual bool AddHttpOtherMsgCB(NF_SERVER_TYPES serverType, const NFHttpType eRequestType, const HTTP_RECEIVE_FUNCTOR &cb);

    virtual bool AddHttpFilterCB(NF_SERVER_TYPES serverType, const std::string &strCommand, const HTTP_FILTER_FUNCTOR &cb);

    virtual bool OnHttpReceiveNetPack(uint32_t serverType, const NFIHttpHandle& req);
    virtual NFWebStatus OnHttpFilterPack(uint32_t serverType, const NFIHttpHandle& req);
protected:
    NFIMessageDriver *m_driver;

    std::vector<CallBack> mxCallBack;

    std::vector<ServerLinkData> mServerLinkData;
};
