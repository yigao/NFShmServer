// -------------------------------------------------------------------------
//    @FileName         :    NFWebHandleModule.cpp
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFCUserWebHandleModule.cpp
//
// -------------------------------------------------------------------------

#include "NFGameWebHandleModule.h"
#include "NFComm/NFPluginModule/NFMessageMgr.h"
#include "NFComm/NFMessageDefine/proto_cs.pb.h"
#include "NFComm/NFMessageDefine/proto_common.pb.h"
#include "NFComm/NFMessageDefine/proto_svr_common.pb.h"
#include "NFComm/NFMessageDefine/proto_svr_web.pb.h"
#include "NFComm/NFShmCore/NFServerFrameTypeDefines.h"
#include "NFGameRoomMgr.h"
#include "NFGameRoom.h"

NFCGameWebHandleModule::NFCGameWebHandleModule(NFIPluginManager *p) : NFIDynamicModule(p) {

}

NFCGameWebHandleModule::~NFCGameWebHandleModule() {

}

bool NFCGameWebHandleModule::Awake() {
    NFMessageMgr::Instance()->AddMessageCallBack(NF_ST_GAME_SERVER, proto_ff::NF_WebToWorld_ClearJiangChi_Req, this,
                                                 &NFCGameWebHandleModule::OnHandleClearJiangChi);

    NFMessageMgr::Instance()->AddMessageCallBack(NF_ST_GAME_SERVER, proto_ff::NF_WebToWorld_SetJiangChi_Req, this,
                                                 &NFCGameWebHandleModule::OnHandleSetJiangChi);
    return true;
}

int NFCGameWebHandleModule::OnHandleClearJiangChi(uint64_t unLinkId, uint64_t value, uint64_t value2, uint32_t nMsgId, const char* msg, uint32_t nLen)
{
    NFLogTrace(NF_LOG_GAME_SERVER_PLUGIN, 0, "-- begin --");
    proto_ff::Proto_Web_ClearJiangChiReq xMsg;
    CLIENT_MSG_PROCESS_WITH_PRINTF(nMsgId, value, msg, nLen, xMsg);

    NFGameRoom* pRoomInfo = NFGameRoomMgr::Instance()->GetGameRoom(xMsg.game_id(), xMsg.room_id());
    if (pRoomInfo)
    {
        int iRet = pRoomInfo->ClearJiangChi();
        if (iRet == 0)
        {
            NFLogInfo(NF_LOG_SYSTEMLOG, 0, "GameID:{} RoomID:{} ClearJiangChi Success..........", xMsg.game_id(), xMsg.room_id());
            NFMessageMgr::Instance()->SendMsgToWebServer(NF_ST_GAME_SERVER, xMsg.request_id(), 0);
            return 0;
        }
    }

    NFLogInfo(NF_LOG_SYSTEMLOG, 0, "GameID:{} RoomID:{} ClearJiangChi Failed..........", xMsg.game_id(), xMsg.room_id());
    NFMessageMgr::Instance()->SendMsgToWebServer(NF_ST_GAME_SERVER, xMsg.request_id(), -1);
    NFLogTrace(NF_LOG_GAME_SERVER_PLUGIN, 0, "-- end --");
    return 0;
}

int NFCGameWebHandleModule::OnHandleSetJiangChi(uint64_t unLinkId, uint64_t value, uint64_t value2, uint32_t nMsgId, const char* msg, uint32_t nLen)
{
    NFLogTrace(NF_LOG_GAME_SERVER_PLUGIN, 0, "-- begin --");
    proto_ff::Proto_Web_SetJiangChiReq xMsg;
    CLIENT_MSG_PROCESS_WITH_PRINTF(nMsgId, value, msg, nLen, xMsg);
    NFGameRoom* pRoomInfo = NFGameRoomMgr::Instance()->GetGameRoom(xMsg.game_id(), xMsg.room_id());
    if (pRoomInfo)
    {
        int iRet = pRoomInfo->ChangeJiangChi(xMsg.jiang_chi());
        if (iRet == 0)
        {
            NFLogInfo(NF_LOG_SYSTEMLOG, 0, "GameID:{} RoomID:{} SetJiangChi Success..........", xMsg.game_id(), xMsg.room_id());
            NFMessageMgr::Instance()->SendMsgToWebServer(NF_ST_GAME_SERVER, xMsg.request_id(), 0);
            return 0;
        }
    }

    NFLogInfo(NF_LOG_SYSTEMLOG, 0, "GameID:{} RoomID:{} SetJiangChi Failed..........", xMsg.game_id(), xMsg.room_id());
    NFMessageMgr::Instance()->SendMsgToWebServer(NF_ST_GAME_SERVER, xMsg.request_id(), -1);
    NFLogTrace(NF_LOG_GAME_SERVER_PLUGIN, 0, "-- end --");
    return 0;
}