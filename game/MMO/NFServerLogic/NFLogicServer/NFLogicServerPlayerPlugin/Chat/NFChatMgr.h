// -------------------------------------------------------------------------
//    @FileName         :    NFChatMgr.h
//    @Author           :    gaoyi
//    @Date             :    23-11-15
//    @Email			:    445267987@qq.com
//    @Module           :    NFChatMgr
//
// -------------------------------------------------------------------------

#pragma once

#include <NFLogicCommon/NFCharactorDefine.h>
#include <NFLogicCommon/NFChatDefine.h>

#include "NFComm/NFCore/NFPlatform.h"
#include "NFLogicCommon/NFLogicShmTypeDefines.h"
#include "NFComm/NFShmCore/NFShmObjTemplate.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmCore/NFShmObj.h"
#include "ObService/NFLogicObService.h"

class NFPlayer;

class NFChatMgr : public NFShmObjTemplate<NFChatMgr, EOT_LOGIC_SERVICE_ID+LOGIC_OB_SERVICE_CLAN, NFLogicObService>
{
public:
    NFChatMgr();

    virtual ~NFChatMgr();

    int CreateInit();
    int ResumeInit();

public:
    //********************传闻或广播新接口***************************//

    /*
    * 函数功能：指定接收玩家广播接口
    * @param id   			传闻广播定义id
    * @param msgData 		传闻广播需填充数据
    * @param playerIdList	接收消息的玩家id列表
    *
    */
    void SendBroadcastChat(BROADCAST_TYPE id, SystemChatMsgData& msgData, std::vector<CharIDType>& playerIdList);

    //指定生物视野内广播
    void SendBroadcastChat(BROADCAST_TYPE id, SystemChatMsgData& msgData, NFPlayer* pPlayer);

    /*
    * 函数功能：请求世界服转发传闻或广播
    * @param id   			传闻广播定义id
    * @param msgData 		广播需填充数据
    * @param extraId 		额外id数据，例如工会id 队伍id 阵营id等等  用于世界服查询接收的玩家id列表
    *
    */
    void SendG2WBroadcast(BROADCAST_TYPE id, SystemChatMsgData& msgData, uint64_t extraId /*= 0*/, uint32_t zid /*= 0*/);

    /*
    * 函数功能：请求世界服转发指定频道消息
    * @param id   			传闻广播定义id
    * @param msgData 		广播需填充数据
    * @param chatType 		频道类型
    * @param extraId 		额外id数据，例如工会id 队伍id 阵营id等等  用于世界服查询接收的玩家id列表
    *
    */
    void SendG2WChannel(BROADCAST_TYPE id, SystemChatMsgData& msgData, proto_ff::CHAT_CHANNEL channelID, uint64_t extraId /*= 0*/, uint32_t zid /*= 0*/);

public:
    /***初始化SystemChatMsgData部分成员的接口***/
    static void InitPlayerMiniInfoStruct(NFPlayer* pPlayer, proto_ff::RolePlayerMiniInfo& info); //初始化Chat_PlayerMiniInfo结构体

public:
    //更新虚拟禁言角色cid列表
    void OnUpdateVirForbid(uint32_t zid, SET_UINT64& setforbid);
    //角色是否在虚拟禁言列表中
    bool IsVirForbid(uint32_t zid, uint64_t cid);

private:
    //向部分玩家发送消息
    void SendG2CChat(uint32_t cmd, std::vector<CharIDType>& playerIdList, const google::protobuf::Message& xData);
};
