// -------------------------------------------------------------------------
//    @FileName         :    NFIGameRoomModule.h
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFIGameRoomModule.h
//
// -------------------------------------------------------------------------

#pragma once

#include <NFComm/NFPluginModule/NFServerDefine.h>
#include "NFComm/NFPluginModule/NFIDynamicModule.h"
#include "NFComm/NFMessageDefine/ResMeta_s.h"

class NFISubGameModule;
class NFIGameDeskHandle;
class NFIGameRobotHandle;
class NFIGameRoomModule : public NFIDynamicModule
{
public:
    NFIGameRoomModule(NFIPluginManager* p):NFIDynamicModule(p)
    {

    }

    virtual ~NFIGameRoomModule() {

    }

    virtual int
    SendMsgToClientByPlayerId(uint64_t playerId, uint32_t nMsgId, const google::protobuf::Message &xData) = 0;

    virtual int SendMsgToClientByPlayerId(uint64_t playerId, uint16_t nMainMsgId, uint16_t nSubMsgId,
                                          const google::protobuf::Message &xData) = 0;

	virtual int SendRobotMsgToServer(uint64_t playerId, uint32_t nMsgId, const google::protobuf::Message &xData) = 0;
	virtual int SendRobotMsgToServer(uint64_t playerId, uint32_t nMsgId, const char *msg, uint32_t nLen) = 0;

    virtual bool AddMessageCallBack(uint16_t gameId, uint16_t subMsgId) = 0;

    virtual NFIGameDeskHandle *CreateGameDeskHandle(uint32_t gameId) = 0;
	virtual NFIGameRobotHandle *CreateGameRobotHandle(uint32_t gameId) = 0;
	virtual const proto_ff_s::GameRoomDesc_s*  GetRoomConfig(uint32_t gameId, uint32_t roomId) = 0;
    virtual int RegisterGameDeskCreator(uint32_t gameKind, NFISubGameModule *pGameModule) = 0;
    virtual void ClearGameDeskCreator(NFISubGameModule *pGameModule) = 0;
};