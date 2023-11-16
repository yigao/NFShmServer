// -------------------------------------------------------------------------
//    @FileName         :    NFSnsChatMgr.h
//    @Author           :    gaoyi
//    @Date             :    23-11-15
//    @Email			:    445267987@qq.com
//    @Module           :    NFSnsChatMgr
//
// -------------------------------------------------------------------------

#pragma once

#include <Chat.pb.h>
#include <NFComm/NFShmStl/NFShmHashSet.h>
#include <NFGameCommon/NFComTypeDefine.h>
#include <NFLogicCommon/NFCharactorDefine.h>
#include <NFLogicCommon/NFChatDefine.h>

#include "NFComm/NFCore/NFPlatform.h"
#include "NFLogicCommon/NFLogicShmTypeDefines.h"
#include "NFComm/NFShmCore/NFShmObjTemplate.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmCore/NFShmObj.h"

#define MAX_VIRFORBID_PLAYER_NUM 20000

class NFSnsChatMgr : public NFShmObjTemplate<NFSnsChatMgr, EOT_NFSnsChatMgr_ID, NFShmObj>
{
public:
    NFSnsChatMgr();

    virtual ~NFSnsChatMgr();

    int CreateInit();
    int ResumeInit();

public:
    //*****************传闻接口***************************
    void SendWorldBroadcastChat(BROADCAST_TYPE id, SystemChatMsgData& msgData);
    void SendBroadcastChat(BROADCAST_TYPE id, SystemChatMsgData& msgData, SET_UINT64& playerIdList);
    bool GetSystemChatMsg(BROADCAST_TYPE id, SystemChatMsgData& msgData, proto_ff::GCSystemChatMsgNotify& chatMsg);

public:
    //初始化玩家的Chat_PlayerMiniInfo结构体
    void InitPlayerMiniInfoStruct(CharIDType playerId, proto_ff::RolePlayerMiniInfo& info);
    void InitPlayerMiniInfoStruct(const std::string& szPlayerName, proto_ff::RolePlayerMiniInfo& info);

    /***初始化SystemChatMsgData部分成员的接口***/

public:
    //*****************广播接口****************************
    //广播给整个世界
    bool SendWorldMsg(uint32_t cmd, const google::protobuf::Message& xData);
    //发送给某个客户端
    bool SendW2C(uint32_t cmd, CharIDType playerId, const google::protobuf::Message& xData);
    //发送给某组客户端
    bool SendW2C(uint32_t cmd, SET_UINT64& playerIdList, const google::protobuf::Message& xData);
    //广播给同阵营
    bool SendCampMsg(uint32_t cmd, int8_t campID, const google::protobuf::Message& xData);
    //广播给招募频道
    bool SendEnlistMsg(uint32_t cmd, int8_t campID, const google::protobuf::Message& xData);
    //广播给工会的玩家
    bool SendUnionMsg(uint32_t cmd, uint32_t unionId, const google::protobuf::Message& xData);
    //广播给扑克聊天室的玩家
    bool SendPokerMsg(uint32_t cmd, const google::protobuf::Message& xData);

public:
    //是否处于虚拟禁言中
    bool IsVirForbid(uint64_t cid);
    //是否可以接收私聊
    bool ValidatePrivateChat(CharIDType srcID, CharIDType dstID);
    //离线私聊
    int SendOfflineMsgByRpc(CharIDType srcID, CharIDType dstID, const proto_ff::ChatContentInfo& chatContent);
    //运营后台跑马灯
    bool ChatBackEndRumor(const std::string& content, uint32_t loopCount);

private:
    bool m_virForbidFlag;                                               //web端是否有返回虚拟禁言列表
    NFShmHashSet<uint64_t, MAX_VIRFORBID_PLAYER_NUM> m_setVirForbidCid; //虚拟禁言的cid列表
};
