// -------------------------------------------------------------------------
//    @FileName         :    NFServerInfoMgr.cpp
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFServerInfoMgr.cpp
//
// -------------------------------------------------------------------------

#include "NFServerIpMgr.h"

NFServerIpMgr::NFServerIpMgr()
{

}

NFServerIpMgr::~NFServerIpMgr()
{

}

std::vector<NF_SHARE_PTR<proto_ff::ServerInfoReport>> NFServerIpMgr::GetServerList()
{
    std::vector<NF_SHARE_PTR<proto_ff::ServerInfoReport>> vec;
    NF_SHARE_PTR<proto_ff::ServerInfoReport> pServer = m_serverMap.First();
    while(pServer)
    {
        vec.push_back(pServer);
        pServer = m_serverMap.Next();
    }
    return vec;
}

NF_SHARE_PTR<proto_ff::ServerInfoReport> NFServerIpMgr::GetServer(uint32_t busId)
{
    return m_serverMap.GetElement(busId);
}

void NFServerIpMgr::AddServer(const proto_ff::ServerInfoReport& report)
{
    NF_SHARE_PTR<proto_ff::ServerInfoReport> pServer = GetServer(report.bus_id());
    if (pServer == NULL)
    {
        pServer = NF_SHARE_PTR<proto_ff::ServerInfoReport>(NF_NEW proto_ff::ServerInfoReport());
        m_serverMap.AddElement(report.bus_id(), pServer);
    }

    pServer->CopyFrom(report);
}
