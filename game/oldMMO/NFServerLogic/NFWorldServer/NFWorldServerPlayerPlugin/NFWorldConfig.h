// -------------------------------------------------------------------------
//    @FileName         :    NFWorldConfig.h
//    @Author           :    gaoyi
//    @Date             :    2022/10/12
//    @Email			:    445267987@qq.com
//    @Module           :    NFWorldConfig
//
// -------------------------------------------------------------------------

#pragma once


#include <common_logic_s.h>
#include "NFComm/NFCore/NFPlatform.h"
#include "NFComm/NFShmCore/NFShmObj.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFComm/NFShmCore/NFISharedMemModule.h"
#include "NFLogicCommon/NFServerFrameTypeDefines.h"
#include "NFLogicCommon/NFLogicCommonDefine.h"

class NFWorldConfig : public NFShmObj
{
public:
    NFWorldConfig();

    virtual ~NFWorldConfig();

    int CreateInit();

    int ResumeInit();

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
    int LoadConfig(NFILuaLoader luaMgr);

    /**
     * @brief 获取配置
     * @return
     */
    const proto_ff_s::WorldExternalConfig_s *GetConfig() const;

    bool IsWhiteAccount(uint64_t uid);
private:
    /**
     * @brief 世界服务器额外配置
     */
    proto_ff_s::WorldExternalConfig_s m_config;
DECLARE_IDCREATE(NFWorldConfig)
};