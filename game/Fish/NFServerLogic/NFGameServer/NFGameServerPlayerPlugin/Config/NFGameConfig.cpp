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

IMPLEMENT_IDCREATE_WITHTYPE(NFGameConfig, EOT_NFGameConfig_ID, NFShmObj)

NFGameConfig::NFGameConfig()
{
    if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode())
    {
        CreateInit();
    }
    else
    {
        ResumeInit();
    }
}

NFGameConfig::~NFGameConfig()
{
}

int NFGameConfig::CreateInit()
{
    return 0;
}

int NFGameConfig::ResumeInit()
{
    return 0;
}

int NFGameConfig::LoadConfig(NFILuaLoader luaMgr)
{
    auto pConfig = FindModule<NFIConfigModule>()->GetAppConfig(NF_ST_GAME_SERVER);
    CHECK_NULL(pConfig);

    std::string path = m_pObjPluginManager->GetConfigPath() + "/Server";
    std::string server = "GameServer_" + NFCommon::tostr(NFServerIDUtil::GetInstID(pConfig->BusId));

    luaMgr.TryAddPackagePath(path); //Add Search Path to Lua

    std::list<std::string> fileList;
    NFFileUtility::GetFiles(path, fileList, true, "*.lua");

    for (auto it = fileList.begin(); it != fileList.end(); ++it)
    {
        if (luaMgr.TryLoadScriptFile(*it) == false)
        {
            NFLogError(NF_LOG_SYSTEMLOG, 0, "Load {} Failed!", *it);
            assert(0);
        }
    }

    NFLuaRef serverRef = luaMgr.GetGlobal(server);
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
