// -------------------------------------------------------------------------
//    @FileName         :    NFGameConfig.h
//    @Author           :    gaoyi
//    @Date             :    22-11-14
//    @Email			:    445267987@qq.com
//    @Module           :    NFGameConfig
//
// -------------------------------------------------------------------------

#pragma once


#include "NFComm/NFCore/NFPlatform.h"
#include "NFComm/NFShmCore/NFShmObj.h"
#include "NFComm/NFShmCore/NFShmMgr.h"
#include "NFLogicCommon/NFServerFrameTypeDefines.h"
#include "NFComm/NFShmCore/NFISharedMemModule.h"
#include "common_logic_s.h"

class NFGameConfig : public NFShmObj
{
public:
    NFGameConfig();

    virtual ~NFGameConfig();

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
    const proto_ff_s::GameExternalConfig_s *GetConfig() const;

private:
    proto_ff_s::GameExternalConfig_s m_config;
DECLARE_IDCREATE(NFGameConfig)
};