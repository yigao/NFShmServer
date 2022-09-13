// -------------------------------------------------------------------------
//    @FileName         :    NFGameLogHandle.cpp
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFGameLogHandle.cpp
//
// -------------------------------------------------------------------------
#include "NFGameLogHandle.h"
#include "NFComm/NFPluginModule/NFLogMgr.h"
#include "NFComm/NFPluginModule/NFMessageMgr.h"
#include "NFComm/NFPluginModule/NFProtobufCommon.h"

NFGameLogHandle::NFGameLogHandle() {
    NFLogMgr::Instance()->AddLogBehaviorCB(NF_ST_GAME_SERVER, this, &NFGameLogHandle::GameLogCallBack);
}

NFGameLogHandle::~NFGameLogHandle() {

}

int NFGameLogHandle::LogGameRecord(uint64_t recordId, uint64_t playerId, const std::string& nickName, uint32_t gameId, uint32_t roomId, const google::protobuf::Message& betInfo, const google::protobuf::Message& resultInfo) {
    proto_ff::LogGameDetail detail;
    detail.set_record_id(recordId);
    detail.set_game_id(gameId);
    detail.set_room_id(roomId);
    std::string strBetInfo;
    NFProtobufCommon::ProtoMessageToJson(betInfo, &strBetInfo);
    detail.set_bet_info(strBetInfo);
    std::string strResultInfo;
    NFProtobufCommon::ProtoMessageToJson(resultInfo, &strResultInfo);
    detail.set_result_info(strResultInfo);
    detail.set_game_time(NFTime::Now().UnixSec());
    NFLogBehavior(NF_ST_GAME_SERVER, playerId, nickName, detail);
    return 0;
}

int NFGameLogHandle::GameLogCallBack(uint64_t userId, const google::protobuf::Message* message)
{
    const proto_ff::LogGameDetail* pDetail = dynamic_cast<const proto_ff::LogGameDetail*>(message);
    if (pDetail)
    {
        NFMessageMgr::Instance()->SendTransToStoreServer(NF_ST_GAME_SERVER,
                                                         proto_ff::E_STORESVR_C2S_INSERT, proto_ff::E_TABLE_NONE, NF_DEFAULT_MYSQL_DB_NAME, "LogGameDetail", *pDetail,
                                                         0, 0, userId);
    }
    return 0;
}

