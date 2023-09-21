// -------------------------------------------------------------------------
//    @FileName         :    NFIGameRoomModule.h
//    @Author           :    gaoyi
//    @Date             :    23-8-4
//    @Email			:    445267987@qq.com
//    @Module           :    NFIGameRoomModule
//
// -------------------------------------------------------------------------

#pragma once

#include "NFFishDynamicModule.h"
#include "NFIGameDeskImpl.h"

typedef NFIGameDeskImpl*(*CreateDeskFunction)(NFIPluginManager* pPluginManager, uint32_t gameId);

class NFIGameRoomModule : public NFFishDynamicModule
{
public:
    explicit NFIGameRoomModule(NFIPluginManager *p):NFFishDynamicModule(p)
    {

    }

    virtual ~NFIGameRoomModule()
    {

    }

public:
    /**
     * @brief 注册创建桌子具体业务的函数
     * @param gameId
     * @param createFunc
     * @return
     */
    virtual int RegisterCreateDeskFunction(uint32_t gameId, const CreateDeskFunction& createFunc) = 0;

    /**
     * @brief 根据具体的游戏ID，创建游戏桌子
     * @param gameId
     * @return
     */
    virtual NFIGameDeskImpl* CreateDesk(uint32_t gameId) = 0;

    /**
     * @brief 游戏注册客户端协议
     * @return
     */
    virtual bool RegisterClientMessage(uint32_t msgId) = 0;

    /**
     * @brief 游戏注册服务器协议
     * @param msgId
     * @return
     */
    virtual bool RegisterServerMessage(uint32_t msgId) = 0;
};
