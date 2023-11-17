// -------------------------------------------------------------------------
//    @FileName         :    NFSnsChatPart.h
//    @Author           :    gaoyi
//    @Date             :    23-11-15
//    @Email			:    445267987@qq.com
//    @Module           :    NFSnsChatPart
//
// -------------------------------------------------------------------------

#pragma once

#include <Chat.pb.h>
#include <Part/NFSnsPart.h>

#include "NFComm/NFCore/NFPlatform.h"
#include "NFLogicCommon/NFLogicShmTypeDefines.h"
#include "NFComm/NFShmCore/NFShmObjTemplate.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmCore/NFShmObj.h"

//离线消息
struct OffLinePrivateMsg
{
    proto_ff::ChatContentInfo chatContent; //聊天内容
    CharIDType fromPlayerID;               //发送者ID
    uint64_t sendTime;                     //发送时间

    OffLinePrivateMsg() : fromPlayerID(0),
                          sendTime(0)
    {
        chatContent.Clear();
    }
};

typedef std::list<OffLinePrivateMsg> PrivateMsgList;

class NFSnsChatPart : public NFShmObjTemplate<NFSnsChatPart, EOT_SNS_PART_ID + SNS_PART_CHAT, NFSnsPart>
{
public:
    NFSnsChatPart();

    virtual ~NFSnsChatPart();

    int CreateInit();
    int ResumeInit();

public:
    /**
     * @brief
     * @param pMaster
     * @param partType
     * @param data
     * @param bCreatePlayer
     * @return
     */
    virtual int Init(NFPlayerDetail* pMaster, uint32_t partType, const proto_ff::RoleDBSnsDetail& data);

    /**
     * @brief
     * @return
     */
    virtual int UnInit();

public:
    /**
     * @brief
     * @param data
     * @return
     */
    virtual int LoadFromDB(const proto_ff::RoleDBSnsDetail& data);

    /**
     * @brief
     * @return
     */
    virtual int InitConfig(const proto_ff::RoleDBSnsDetail& data);

    /**
     * @brief 存储DB部件入口
     * @param proto
     * @return
     */
    virtual int SaveDB(proto_ff::RoleDBSnsDetail& dbData);

    /**
     * @brief 登陆入口
     * @return
     */
    virtual int OnLogin() { return 0; }

    /**
     * @brief 登出入口
     * @return
     */
    virtual int OnLogout() { return 0; }

    /**
     * @brief 掉线入口
     * @return
     */
    virtual int OnDisconnect() { return 0; }

    /**
     * @brief 重连入口
     * @return
     */
    virtual int OnReconnect() { return 0; }

public:
    ////////////////////////////////// 每日零点 每周一零点 刷新接口 ///////////////////////////////////
    /**
     * @brief 每日零点 刷新接口
     * @return
     */
    virtual int DailyZeroUpdate() { return 0; }

    /**
     * @brief 每日零点 刷新接口
     * @return
     */
    virtual int WeekZeroUpdate() { return 0; }

    /**
     * @brief 每月刷新接口
     * @return
     */
    virtual int MonthZeroUpdate() { return 0; }

public:
    /**
     * @brief update
     */
    virtual int Update() { return 0; }

public:
    /**
     * @brief 注册要处理的消息
     * @return
     */
    virtual int RegisterMessage();

public:
    /**
     * @brief 处理客户端消息
     * @param unLinkId
     * @param packet
     * @return
     */
    virtual int OnHandleClientMessage(uint32_t msgId, NFDataPackage& packet);

    /**
     * @brief 处理来自服务器的信息
     * @param unLinkId
     * @param packet
     * @return
     */
    virtual int OnHandleServerMessage(uint32_t msgId, NFDataPackage& packet);

public:
    /**
     * \brief 请求聊天
     * \param msgId
     * \param packet
     * \return
     */
    int OnHandleChatReq(uint32_t msgId, NFDataPackage& packet);

public:
    /**
     * \brief 请求离线消息
     * \param msgId
     * \param packet
     * \return
     */
    int OnHandleAskOfflineMsgReq(uint32_t msgId, NFDataPackage& packet);

    /**
     * \brief 分段请求聊天离线数据
     * \param msgId
     * \param packet
     * \return
     */
    int OnHandleIntrvalAskOfflineMsgReq(uint32_t msgId, NFDataPackage& packet);
public:
    int AddOfflineMsg(uint64_t sendCid, const proto_ff::ChatContentInfo& chatContent);
private:
    PrivateMsgList m_msgList;
};
