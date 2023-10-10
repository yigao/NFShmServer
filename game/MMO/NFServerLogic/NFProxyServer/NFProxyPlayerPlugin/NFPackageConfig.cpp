// -------------------------------------------------------------------------
//    @FileName         :    NFPackageConfig.cpp
//    @Author           :    gaoyi
//    @Date             :    2022/9/30
//    @Email			:    445267987@qq.com
//    @Module           :    NFPackageConfig
//
// -------------------------------------------------------------------------

#include "NFPackageConfig.h"
#include "NFComm/NFCore/NFFileUtility.h"
#include "NFComm/NFPluginModule/NFProtobufCommon.h"
#include "NFComm/NFPluginModule/NFCheck.h"

NFPackageConfig::NFPackageConfig()
{
    m_packetMsgConfig.resize(NF_NET_MAX_MSG_ID);
}

NFPackageConfig::~NFPackageConfig()
{
}

int NFPackageConfig::LoadConfig(const string &path, const string &server)
{
    TryAddPackagePath(path); //Add Search Path to Lua

    std::list<std::string> fileList;
    NFFileUtility::GetFiles(path, fileList, true, "*.lua");

    for (auto it = fileList.begin(); it != fileList.end(); ++it)
    {
        if (TryLoadScriptFile(*it) == false)
        {
            NFLogError(NF_LOG_SYSTEMLOG, 0, "Load {} Failed!", *it);
            assert(0);
        }
    }

    NFLuaRef serverRef = GetGlobal(server);
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

    proto_ff::ServerPacketMsg serverMsg;
    NFProtobufCommon::LuaToProtoMessage(serverRef, &serverMsg);
    NFLogTrace(NF_LOG_SYSTEMLOG, 0, "load server packet config:\n{}", serverMsg.DebugString());

    for (int i = 0; i < (int) serverMsg.packetmsg_size(); ++i)
    {
        const ::proto_ff::PacketMsg &msg = serverMsg.packetmsg(i);
        CHECK_EXPR_ASSERT((msg.cmd() > 0 && msg.cmd() < NF_NET_MAX_MSG_ID), -1, "invalid msg:{}", msg.cmd());
        m_packetMsgConfig[msg.cmd()] = msg;
    }
    return 0;
}

const proto_ff::PacketMsg* NFPackageConfig::GetPacketConfig(uint32_t iMsgID)
{
    CHECK_EXPR((iMsgID > 0 && iMsgID < NF_NET_MAX_MSG_ID), NULL, "invalid msg:{}", iMsgID);

    if (m_packetMsgConfig[iMsgID].has_cmd())
    {
        return &m_packetMsgConfig[iMsgID];
    }

    return NULL;
}

