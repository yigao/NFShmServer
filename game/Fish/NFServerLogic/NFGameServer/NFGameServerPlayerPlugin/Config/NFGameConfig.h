// -------------------------------------------------------------------------
//    @FileName         :    NFGameConfig.h
//    @Author           :    gaoyi
//    @Date             :    23-7-28
//    @Email			:    445267987@qq.com
//    @Module           :    NFGameConfig
//
// -------------------------------------------------------------------------

#pragma once


#include "NFComm/NFCore/NFPlatform.h"
#include "NFLogicCommon/NFIGameConfig.h"

class NFGameConfig : public NFIGameConfig
{
public:
    NFGameConfig(NFIPluginManager* pPluginManager);

    virtual ~NFGameConfig();

public:
    /**
     * @brief 加载Server/WorldServer.lua中的WolrdServer配置，
     *        通过common_logic.proto中的protobuf结构WorldServerConfig来解析，注意field要与lua的自动大小写完全一致
     *        lua:                                   proto:
     *        WorldServer = {                        message WorldExternalConfig {
                    TokenTimeCheck = True;   ====>      optional bool TokenTimeCheck = 1[(yd_fieldoptions.field_use_stl)=true];
              };                                    };
     *
     * @param luaMgr
     * @return
     */
    int LoadConfig();

    /**
     * @brief 获取配置
     * @return
     */
    virtual const proto_ff_s::GameExternalConfig_s *GetConfig() const;

    virtual uint32_t GetRoomNum(uint32_t gameId) const;

    virtual std::vector<uint32_t> GetRoomList(uint32_t gameId) const;

    virtual std::unordered_map<uint32_t, std::vector<uint32_t>> GetGameRoomList() const;

    virtual uint32_t GetAllRoomNum() const;

    virtual uint32_t GetRoomMaxDeskNum() const;
private:
    proto_ff_s::GameExternalConfig_s m_config;
    /**
     * @brief NFILuaModule
     */
    NFILuaLoader m_luaModule;
};