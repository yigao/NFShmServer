// -------------------------------------------------------------------------
//    @FileName         :    NFGmPart.h
//    @Author           :    gaoyi
//    @Date             :    23-12-12
//    @Email			:    445267987@qq.com
//    @Module           :    NFGmPart
//
// -------------------------------------------------------------------------

#pragma once

#include "NFComm/NFCore/NFPlatform.h"
#include "NFLogicCommon/NFLogicShmTypeDefines.h"
#include "NFComm/NFShmCore/NFShmObjTemplate.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmCore/NFShmObj.h"
#include "Part/NFPart.h"

class NFGmPart : public NFShmObjTemplate<NFGmPart, EOT_LOGIC_PART_ID + PART_GM, NFPart>
{
public:
    NFGmPart();
    
    virtual ~NFGmPart();
    
    int CreateInit();
    
    int ResumeInit();

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
     * @brief 处理服务器的gm消息
     * @param msgId
     * @param packet
     * @return
     */
    int OnHandleServerGmRsp(uint32_t msgId, NFDataPackage& packet);
    
    /**
     * @brief 处理gm命令
     * @param cmd
     * @param vecarg
     * @return
     */
    int HandleGMCommand(const string& cmd, const VEC_STRING& vecarg);

public:
    /**
     * @brief 获取道具
     * @param vecarg
     * @return
     */
    int GetItem(const VEC_STRING& vecarg);
    
    /**
     * @brief 升级等级
     * @param vecarg
     * @return
     */
    int UpgradeLevel(const VEC_STRING& vecarg);
    
    /**
     * @brief 增加经验
     * @param vecarg
     * @return
     */
    int AddExp(const VEC_STRING& vecarg);
    
    /**
     * @brief 增加金币
     * @param vecarg
     * @return
     */
    int AddGold(const VEC_STRING& vecarg);
    
    /**
     * @brief 增加钻石
     * @param vecarg
     * @return
     */
    int AddDia(const VEC_STRING& vecarg);
    
    /**
     * @brief 增加绑钻
     * @param vecarg
     * @return
     */
    int AddBdDia(const VEC_STRING& vecarg);
    
    /**
     * @brief
     * @param vecarg
     * @return
     */
    int AddMagic(const VEC_STRING& vecarg);
    
    /**
     * @brief
     * @param vecarg
     * @return
     */
    int AddHunLing(const VEC_STRING& vecarg);
    
    /**
     * @brief 增加声望
     * @param vecarg
     * @return
     */
    int AddPrestige(const VEC_STRING& vecarg);
    
    /**
     * @brief 增加贡献值
     * @param vecarg
     * @return
     */
    int AddContri(const VEC_STRING& vecarg);
    
    /**
     * @brief 传送
     * @param vecarg
     * @return
     */
    int GotoMapId(const VEC_STRING& vecarg);
    
    /**
     * @brief 创建怪物
     * @param vecarg
     * @return
     */
    int CreateMonster(const VEC_STRING& vecarg);
    
    /**
     * @brief 添加技能
     * @param vecarg
     * @return
     */
    int AddSkill(const VEC_STRING& vecarg);
};