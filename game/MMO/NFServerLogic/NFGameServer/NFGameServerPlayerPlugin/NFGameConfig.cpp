// -------------------------------------------------------------------------
//    @FileName         :    NFGameConfig.cpp
//    @Author           :    gaoyi
//    @Date             :    22-11-14
//    @Email			:    445267987@qq.com
//    @Module           :    NFGameConfig
//
// -------------------------------------------------------------------------

#include "NFGameConfig.h"
#include "NFComm/NFCore/NFFileUtility.h"
#include "NFComm/NFPluginModule/NFIConfigModule.h"
#include "NFComm/NFPluginModule/NFCheck.h"
#include "NFComm/NFCore/NFServerIDUtil.h"
#include "NFComm/NFCore/NFCommon.h"
#include "NFComm/NFPluginModule/NFProtobufCommon.h"
#include "NFLogicCommon/NFLogicShmTypeDefines.h"

NFGameConfig::NFGameConfig()
{

}

NFGameConfig::~NFGameConfig()
{
}

int NFGameConfig::LoadConfig(NFIPluginManager* pPluginManager)
{
    auto pConfig = pPluginManager->FindModule<NFIConfigModule>()->GetAppConfig(NF_ST_GAME_SERVER);
    CHECK_NULL(pConfig);

    std::string path = pPluginManager->GetConfigPath() + "/Server";
    std::string server = "GameServer_" + NFCommon::tostr(NFServerIDUtil::GetInstID(pConfig->BusId));

    m_luaModule.TryAddPackagePath(path); //Add Search Path to Lua

    std::list<std::string> fileList;
    NFFileUtility::GetFiles(path, fileList, true, "*.lua");

    for (auto it = fileList.begin(); it != fileList.end(); ++it)
    {
        if (m_luaModule.TryLoadScriptFile(*it) == false)
        {
            NFLogError(NF_LOG_SYSTEMLOG, 0, "Load {} Failed!", *it);
            assert(0);
        }
    }

    NFLuaRef serverRef = m_luaModule.GetGlobal(server);
    if (!serverRef.isValid())
    {
        NFLogError(NF_LOG_SYSTEMLOG, 0, "can't find ({})", server);
        assert(0);
    }

    if (!serverRef.isTable())
    {
        NFLogError(NF_LOG_SYSTEMLOG, 0, "{} is not table", server);
        assert(0);
    }

    proto_ff::GameExternalConfig serverMsg;
    NFProtobufCommon::LuaToProtoMessage(serverRef, &serverMsg);
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "load game server config:\n{}", serverMsg.DebugString());

    //check

    //to struct
    m_config.read_from_pbmsg(serverMsg);
    return 0;
}

const proto_ff_s::GameExternalConfig_s* NFGameConfig::GetConfig() const
{
    return &m_config;
}
