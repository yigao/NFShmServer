// -------------------------------------------------------------------------
//    @FileName         :    NFISubGameModule.h
//    @Author           :    gaoyi
//    @Date             :    23-8-5
//    @Email			:    445267987@qq.com
//    @Module           :    NFISubGameModule
//
// -------------------------------------------------------------------------

#pragma once

#include "NFComm/NFPluginModule/NFIDynamicModule.h"
#include "NFIGameRoomModule.h"

class NFISubGameModule : public NFIDynamicModule
{
public:
    NFISubGameModule(NFIPluginManager* p):NFIDynamicModule(p)
    {

    }

    virtual ~NFISubGameModule()
    {

    }

    /**
     * @brief 游戏注册客户端协议
     * @return
     */
    virtual bool RegisterClientMessage(uint32_t msgId)
    {
        return FindModule<NFIGameRoomModule>()->RegisterClientMessage(msgId);
    }

    /**
     * @brief 游戏注册服务器协议
     * @param msgId
     * @return
     */
    virtual bool RegisterServerMessage(uint32_t msgId)
    {
        return FindModule<NFIGameRoomModule>()->RegisterServerMessage(msgId);
    }
};
