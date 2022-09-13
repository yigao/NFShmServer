// -------------------------------------------------------------------------
//    @FileName         :    NFGameConfigModule.cpp
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFGameConfigModule.cpp
//
// -------------------------------------------------------------------------

#include "NFGameConfigModule.h"
#include "NFComm/NFMessageDefine/proto_event.pb.h"
#include "NFComm/NFMessageDefine/proto_svr_common.pb.h"
#include "NFServer/NFCommHead/NFICommLogicModule.h"
#include "NFServer/NFCommHead/NFIGameServerModule.h"
#include "NFComm/NFPluginModule/NFMessageMgr.h"
#include "NFComm/NFMessageDefine/ResMeta.pb.h"
#include "NFComm/NFMessageDefine/ResMeta_s.h"
#include "NFComm/NFMessageDefine/proto_svr_game.pb.h"

#include <fstream>

NFCGameConfigModule::NFCGameConfigModule(NFIPluginManager* p) :NFIGameConfigModule(p)
{
	OnReloadPlugin();
}

NFCGameConfigModule::~NFCGameConfigModule()
{
}

void NFCGameConfigModule::UnRegisterRoomInfo()
{
	//这里没调用到？
    NFServerConfig* pConfig = NFConfigMgr::Instance()->GetAppConfig(NF_ST_GAME_SERVER);
    if (pConfig)
    {
		proto_ff::GameRoomUnRegReq xMsg;
		for(int i = 0; i < (int)pConfig->mRoomIdList.size(); i++)
        {
            auto pRoomInfo = xMsg.mutable_room_info();
            if (pRoomInfo)
            {
                pRoomInfo->set_room_id(pConfig->mRoomIdList[i]);
                pRoomInfo->set_game_id(pConfig->mGameId);
                pRoomInfo->set_online_count(0);

                NFLogTrace(NF_LOG_GAME_SERVER_PLUGIN, 0, "Game Server UnRegister Room Info To World Server, gameId:{}, roomId:{}", pRoomInfo->game_id(), pRoomInfo->room_id());
            }
        }


		NFMessageMgr::Instance()->SendMsgToWorldServer(NF_ST_GAME_SERVER, proto_ff::NF_GTW_ROOM_UNREGISTER_REQ, xMsg);
    }
}

void NFCGameConfigModule::UpdateRoomInfo(uint32_t onlinecount)
{
	//这里没调用到？
    NFServerConfig* pConfig = NFConfigMgr::Instance()->GetAppConfig(NF_ST_GAME_SERVER);
    if (pConfig)
    {
        proto_ff::GameRoomUnRegReq xMsg;
        auto pRoomInfo = xMsg.mutable_room_info();
        if (pRoomInfo)
        {
            pRoomInfo->set_room_id(1);
            pRoomInfo->set_game_id(101);
            pRoomInfo->set_bus_id(pConfig->mBusId);
            pRoomInfo->set_online_count(onlinecount);

            NFLogTrace(NF_LOG_GAME_SERVER_PLUGIN, 0, "Game Server Update Room Info To World Server, gameId:{}, roomId:{}", pRoomInfo->game_id(), pRoomInfo->room_id());
        }

        NFMessageMgr::Instance()->SendMsgToWorldServer(NF_ST_GAME_SERVER, proto_ff::NF_GTW_ROOM_UPDATE_ONLINE_COUNT_REQ, xMsg);
    }
}

