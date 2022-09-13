// -------------------------------------------------------------------------
//    @FileName         :    NFGameRoomModule.h
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFGameRoomModule.h
//
// -------------------------------------------------------------------------

#pragma once

#include "NFServer/NFCommHead/NFIGameRoomModule.h"
#include "NFGameRoomMgr.h"
#include "NFComm/NFPluginModule/NFMessageMgr.h"
#include "NFGameSessionMgr.h"
#include "NFComm/NFMessageDefine/NFGameConfig.h"
#include <unordered_map>

class NFCGameRoomModule : public NFIGameRoomModule {
    enum NFTimerType {
        NF_TIMER_TYPE_REG_ROOM_INFO = 1,
		NF_TIMER_TYPE_ROBOT_MGR_START = 2,
		NF_TIMER_TYPE_ROBOT_MGR = 3,
        NF_TIMER_TYPE_UPDATE_ROOM_INFO = 4,
    };
public:
    explicit NFCGameRoomModule(NFIPluginManager *p);

    virtual ~NFCGameRoomModule();

    virtual bool Awake() override;

    virtual bool ReadyExecute() override;

    virtual bool Execute() override;

    virtual bool OnDynamicPlugin() override;

    virtual void OnTimer(uint32_t nTimerID) override;

    virtual int OnExecute(uint32_t nEventID, uint64_t nSrcID, uint32_t bySrcType, const google::protobuf::Message &message);

    virtual int OnHandleRegisterResp(uint64_t unLinkId, uint64_t playerId, uint64_t value2, uint32_t nMsgId, const char *msg, uint32_t nLen);

	virtual int CreateGameRoom();
    virtual int RegisterGameRoom();
    virtual int UpdateGameRoom();
public:
    virtual int SendMsgToClientByPlayerId(uint64_t playerId, uint32_t nMsgId, const google::protobuf::Message &xData) override;

    virtual int SendMsgToClientByPlayerId(uint64_t playerId, uint16_t nMainMsgId, uint16_t nSubMsgId,
                                          const google::protobuf::Message &xData) override;

	virtual int SendRobotMsgToServer(uint64_t playerId, uint32_t nMsgId, const google::protobuf::Message &xData) override;
	virtual int SendRobotMsgToServer(uint64_t playerId, uint32_t nMsgId, const char *msg, uint32_t nLen) override;


    virtual bool AddMessageCallBack(uint16_t gameId, uint16_t subMsgId) override;

    virtual NFIGameDeskHandle *CreateGameDeskHandle(uint32_t gameId) override;
	virtual NFIGameRobotHandle *CreateGameRobotHandle(uint32_t gameId) override;
	virtual const proto_ff_s::GameRoomDesc_s*  GetRoomConfig(uint32_t gameId, uint32_t roomId) override;

    virtual int RegisterGameDeskCreator(uint32_t gameId, NFISubGameModule *pGameModule) override;

    virtual void ClearGameDeskCreator(NFISubGameModule *pGameModule) override;


public:
    /////////////handle all room msg//////////////////////
    virtual int OnHandleRoomMsg(uint64_t unLinkId, uint64_t playerId, uint64_t value2, uint32_t nMsgId, const char *msg, uint32_t nLen);

public:
    //int OnHandleEnterGameAutoJoin(uint64_t unLinkId, uint64_t playerId, uint32_t nMsgId, const char *msg, uint32_t nLen);
	
	int OnHandleReqDeskListFromClient(uint64_t unLinkId, uint64_t playerId, uint64_t value2, uint32_t nMsgId, const char* msg, uint32_t nLen);
	int OnHandleReqChairCheckFromClient(uint64_t unLinkId, uint64_t playerId, uint64_t value2, uint32_t nMsgId, const char* msg, uint32_t nLen);
	int OnHandleEnterGameReqFromClient(uint64_t unLinkId, uint64_t playerId, uint64_t value2, uint32_t nMsgId, const char* msg, uint32_t nLen);
	int OnHandleReComeReqFromClient(uint64_t unLinkId, uint64_t playerId, uint64_t value2, uint32_t nMsgId, const char* msg, uint32_t nLen);
	int OnHandleExitRoomReqFromClient(uint64_t unLinkId, uint64_t playerId, uint64_t value2, uint32_t nMsgId, const char* msg, uint32_t nLen);
	int OnHandleExitGameReqFromClient(uint64_t unLinkId, uint64_t playerId, uint64_t value2, uint32_t nMsgId, const char* msg, uint32_t nLen);


    int OnHandleReconnectFromClient(uint64_t unLinkId, uint64_t value, uint64_t value2, uint32_t nMsgId, const char *msg, uint32_t nLen);
    int OnHandlePlayerDisConnect(uint64_t unLinkId, uint64_t value, uint64_t value2, uint32_t nMsgId, const char* msg, uint32_t nLen);

    int OnHandleClearAllGamePlayerNotify(uint64_t unLinkId, uint64_t value, uint64_t value2, uint32_t nMsgId, const char* msg, uint32_t nLen);
    int OnHandleSetUserManagerInfo(uint64_t unLinkId, uint64_t value, uint64_t value2, uint32_t nMsgId, const char* msg, uint32_t nLen);
    int OnHandleSetGmCtrlGiveData(uint64_t unLinkId, uint64_t value, uint64_t value2, uint32_t nMsgId, const char* msg, uint32_t nLen);

    int OnHandleUpdateUserInfo(uint64_t unLinkId, uint64_t value, uint64_t value2, uint32_t nMsgId, const char* msg, uint32_t nLen);
private:
	int GameRobotMgrPolling();

private:
    std::unordered_map<uint32_t, NFISubGameModule*> m_createDeskMaps;

};