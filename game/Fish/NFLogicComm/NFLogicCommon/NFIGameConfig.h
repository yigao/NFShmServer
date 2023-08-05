// -------------------------------------------------------------------------
//    @FileName         :    NFIGameConfig.h
//    @Author           :    gaoyi
//    @Date             :    23-8-5
//    @Email			:    445267987@qq.com
//    @Module           :    NFIGameConfig
//
// -------------------------------------------------------------------------

#pragma once

#include "NFFishDynamicModule.h"

class NFIGameConfig : public NFFishDynamicModule
{
public:
    explicit NFIGameConfig(NFIPluginManager *p):NFFishDynamicModule(p)
    {

    }

    virtual ~NFIGameConfig()
    {

    }
public:
    /**
     * @brief 获取配置
     * @return
     */
    virtual const proto_ff_s::GameExternalConfig_s *GetConfig() const = 0;

    virtual uint32_t GetRoomNum(uint32_t gameId) const = 0;

    virtual std::vector<uint32_t> GetRoomList(uint32_t gameId) const = 0;

    virtual uint32_t GetAllRoomNum() const = 0;

    virtual uint32_t GetRoomMaxDeskNum() const = 0;
};