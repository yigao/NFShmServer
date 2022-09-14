// -------------------------------------------------------------------------
//    @FileName         :    NFProxyClientModule.h
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFProxyClientModule
//
// -------------------------------------------------------------------------

#pragma once

#include "NFServer/NFCommHead/NFIProxyClientModule.h"
#include "NFComm/NFPluginModule/NFServerDefine.h"
#include "NFComm/NFCore/NFMap.hpp"
#include "NFComm/NFMessageDefine/proto_cs_login.pb.h"
#include "NFComm/NFMessageDefine/proto_svr_login.pb.h"

struct NFProxySession
{
	NFProxySession()
	{
		mLinkId = 0;
		mPlayerId = 0;
        mLastHeartBeatTime = 0;
	}

	uint64_t mLinkId;
	uint64_t mPlayerId;
	std::string mIPAddr;
	uint64_t mLastHeartBeatTime;
};

struct NFProxyPlayerInfo
{
	NFProxyPlayerInfo()
	{
		mLinkId = 0;
		mIsLogin = false;
		mPlayerId = 0;
        mWorldBusId = 0;
        mGameBusId = 0;
        mLogicBusId = 0;
        mGameId = 0;
        mRoomId = 0;
        mDisconnectTime = 0;
        mOnline = true;
	}
	uint64_t mLinkId;
	uint32_t mWorldBusId;
    uint32_t mGameBusId;
    uint32_t mLogicBusId;
    uint32_t mGameId;
    uint32_t mRoomId;
    uint64_t mDisconnectTime;
    bool mOnline;
	bool mIsLogin;
	uint64_t mPlayerId;
	std::string mAccount;
	std::string mIPAddr;
};

class NFCProxyClientModule : public NFIProxyClientModule
{
public:
public:
	explicit NFCProxyClientModule(NFIPluginManager* p);
	virtual ~NFCProxyClientModule();

	virtual bool Awake() override;

	virtual bool Init() override;

	virtual bool Execute() override;

	virtual bool OnDynamicPlugin() override;

    virtual void OnTimer(uint32_t nTimerID) override;

	virtual int OnHandleOtherServerOtherMessage(uint64_t unLinkId, const NFDataPackage& packet) override;
public:
	/*
		处理客户端链接事件和未注册消息
	*/
	int OnProxyClientSocketEvent(eMsgType nEvent, uint64_t unLinkId);
	int OnHandleProxyClientOtherMessage(uint64_t unLinkId, const NFDataPackage& packet);
	int OnHandleClientDisconnect(uint64_t unLinkId);
private:
	/*
		对外部客户端监听唯一ID
	*/
	uint64_t m_proxyClientLinkId;
	NFMapEx<uint64_t, NFProxySession> mClientLinkInfo; //unlink -- NFProxySession
	NFMapEx<uint64_t, NFProxyPlayerInfo> mPlayerLinkInfo; //playerId -- NFProxyPlayerInfo
};
