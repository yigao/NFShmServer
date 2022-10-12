// -------------------------------------------------------------------------
//    @FileName         :    NFPackageConfig.h
//    @Author           :    gaoyi
//    @Date             :    2022/9/30
//    @Email			:    445267987@qq.com
//    @Module           :    NFPackageConfig
//
// -------------------------------------------------------------------------

#pragma once


#include "NFComm/NFCore/NFPlatform.h"
#include "NFComm/NFPluginModule/NFILuaModule.h"
#include <common_logic.pb.h>
#include "NFServerLogicMessage/ClientServerCmd.pb.h"

class NFPackageConfig : public NFILuaModule
{
public:
    NFPackageConfig();
    virtual ~NFPackageConfig();
public:
    int LoadConfig(const std::string &path, const std::string &server);
    const proto_ff::PacketMsg* GetPacketConfig(uint32_t cmd);
public:
    std::vector<proto_ff::PacketMsg> m_packetMsgConfig;
};