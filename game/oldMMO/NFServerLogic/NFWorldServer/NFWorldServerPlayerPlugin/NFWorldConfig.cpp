// -------------------------------------------------------------------------
//    @FileName         :    NFWorldConfig.cpp
//    @Author           :    gaoyi
//    @Date             :    2022/10/12
//    @Email			:    445267987@qq.com
//    @Module           :    NFWorldConfig
//
// -------------------------------------------------------------------------

#include <NFComm/NFCore/NFFileUtility.h>
#include <NFComm/NFPluginModule/NFProtobufCommon.h>
#include "NFWorldConfig.h"
#include "NFComm/NFShmCore/NFShmMgr.h"

IMPLEMENT_IDCREATE_WITHTYPE(NFWorldConfig, EOT_WOLRD_CONFIG_ID, NFShmObj)

NFWorldConfig::NFWorldConfig(NFIPluginManager* pPluginManager):NFShmObj(pPluginManager)
{
    if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode())
    {
        CreateInit();
    } else
    {
        ResumeInit();
    }
}

NFWorldConfig::~NFWorldConfig()
{
}

int NFWorldConfig::CreateInit()
{
    return 0;
}

int NFWorldConfig::ResumeInit()
{
    return 0;
}

int NFWorldConfig::LoadConfig(NFILuaModule luaMgr)
{
    std::string path = m_pObjPluginManager->GetConfigPath() + "/Server";
    std::string server = "WorldServer";

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

    proto_ff::WorldExternalConfig serverMsg;
    NFProtobufCommon::LuaToProtoMessage(serverRef, &serverMsg);
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "load world server config:\n{}", serverMsg.DebugString());

    //check

    //to struct
    m_config.read_from_pbmsg(serverMsg);
    return 0;
}

const proto_ff_s::WorldExternalConfig_s* NFWorldConfig::GetConfig() const
{
    return &m_config;
}
