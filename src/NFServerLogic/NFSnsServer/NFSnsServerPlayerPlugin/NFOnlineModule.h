// -------------------------------------------------------------------------
//    @FileName         :    NFOnlineModule.h
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFOnlineModule
//
// -------------------------------------------------------------------------

#pragma once

#include "NFComm/NFPluginModule/NFServerDefine.h"
#include "NFComm/NFPluginModule/NFIDynamicModule.h"
#include "NFServer/NFCommHead/NFCommLogicHead.h"
#include "NFComm/NFMessageDefine/proto_svr_login.pb.h"

class NFSnsUserSimple;
class NFOnlineUser;
class NFCOnlineModule : public NFIDynamicModule
{
public:
	explicit NFCOnlineModule(NFIPluginManager *p);

	virtual ~NFCOnlineModule();

	virtual bool Awake() override;

	virtual bool Init() override;

	virtual bool Execute() override;

	virtual bool OnDynamicPlugin() override;

    virtual int OnExecute(uint32_t nEventID, uint64_t nSrcID, uint32_t bySrcType, const google::protobuf::Message& message);
public:
	int OnHandlePlayerLogin(uint64_t unLinkId, uint64_t value, uint64_t value2, uint32_t nMsgId, const char* msg, uint32_t nLen);
	int OnHandlePlayerLogout(uint64_t unLinkId, uint64_t value, uint64_t value2, uint32_t nMsgId, const char* msg, uint32_t nLen);

	int OnHandlePlayerDisConnect(uint64_t unLinkId, uint64_t value, uint64_t value2, uint32_t nMsgId, const char* msg, uint32_t nLen);
    int OnHandlePlayerReconnect(uint64_t unLinkId, uint64_t value, uint64_t value2, uint32_t nMsgId, const char* msg, uint32_t nLen);

    int OnHandleQueryUser(uint64_t unLinkId, uint64_t destLinkId, uint64_t req_trans_id, uint32_t nMsgId, const char* msg, uint32_t nLen);

    int OnHandleChangeFace(uint64_t unLinkId, uint64_t destLinkId, uint64_t req_trans_id, uint32_t nMsgId, const char* msg, uint32_t nLen);
    int OnHandleChangeNickName(uint64_t unLinkId, uint64_t destLinkId, uint64_t req_trans_id, uint32_t nMsgId, const char* msg, uint32_t nLen);
    int OnHandleChangeUserId(uint64_t unLinkId, uint64_t destLinkId, uint64_t req_trans_id, uint32_t nMsgId, const char* msg, uint32_t nLen);
    int OnHandleChangeVipLevel(uint64_t unLinkId, uint64_t destLinkId, uint64_t req_trans_id, uint32_t nMsgId, const char* msg, uint32_t nLen);

    int OnHandleRouteToSuitLogicServer(uint64_t unLinkId, uint64_t playerId, uint64_t value2, uint32_t nMsgId, const char* msg, uint32_t nLen);
public:
    int OnPlayerLogin(NFSnsUserSimple* pSimple, NFOnlineUser* pUser);
    int OnNewPlayer(NFSnsUserSimple* pSimple, NFOnlineUser* pUser);
    int OnPlayerLogout(NFSnsUserSimple* pSimple, NFOnlineUser* pUser);
};
