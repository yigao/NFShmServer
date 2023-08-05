// -------------------------------------------------------------------------
//    @FileName         :    NFGameConfig.cpp
//    @Author           :    gaoyi
//    @Date             :    23-7-28
//    @Email			:    445267987@qq.com
//    @Module           :    NFGameConfig
//
// -------------------------------------------------------------------------

#include "NFGameConfig.h"
#include "NFLogicCommon/NFLogicShmTypeDefines.h"
#include "NFComm/NFPluginModule/NFIConfigModule.h"
#include "NFComm/NFCore/NFServerIDUtil.h"
#include "NFComm/NFCore/NFCommon.h"
#include "NFComm/NFCore/NFFileUtility.h"
#include "NFComm/NFPluginModule/NFProtobufCommon.h"

NFGameConfig::NFGameConfig(NFIPluginManager *pPluginManager) : NFIGameConfig(pPluginManager)
{
    LoadConfig();
}

NFGameConfig::~NFGameConfig()
{
}

int NFGameConfig::LoadConfig()
{
    auto pConfig = FindModule<NFIConfigModule>()->GetAppConfig(NF_ST_GAME_SERVER);
    CHECK_NULL(pConfig);

    std::string path = m_pObjPluginManager->GetConfigPath() + "/Server";
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
    NFLogInfo(NF_LOG_SYSTEMLOG, 0, "load game server config:\n{}", serverMsg.DebugString());

    //check

    //to struct
    m_config.read_from_pbmsg(serverMsg);
    return 0;
}

const proto_ff_s::GameExternalConfig_s *NFGameConfig::GetConfig() const
{
    return &m_config;
}

uint32_t NFGameConfig::GetRoomNum(uint32_t gameId) const
{
    for (int i = 0; i < (int) m_config.Game.size(); i++)
    {
        if (m_config.Game[i].GameId == gameId)
        {
            return m_config.Game[i].RoomId.size();
        }
    }
    return 0;
}

std::vector<uint32_t> NFGameConfig::GetRoomList(uint32_t gameId) const
{
    for (int i = 0; i < (int) m_config.Game.size(); i++)
    {
        if (m_config.Game[i].GameId == gameId)
        {
            return m_config.Game[i].RoomId.to_vector();
        }
    }
    return std::vector<uint32_t>();
}

uint32_t NFGameConfig::GetAllRoomNum() const
{
    uint32_t num = 0;
    for (int i = 0; i < (int) m_config.Game.size(); i++)
    {
        num += m_config.Game[i].RoomId.size();
    }
    return num;
}

uint32_t NFGameConfig::GetRoomMaxDeskNum() const
{
    return m_config.MaxDeskNunOneRoom;
}
