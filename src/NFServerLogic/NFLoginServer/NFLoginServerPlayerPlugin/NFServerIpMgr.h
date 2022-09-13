// -------------------------------------------------------------------------
//    @FileName         :    NFServerInfoMgr.h
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFServerInfoMgr.h
//
// -------------------------------------------------------------------------

#pragma once

#include "NFComm/NFCore/NFSingleton.hpp"
#include "NFComm/NFKernelMessage/proto_kernel.pb.h"
#include "NFComm/NFCore/NFMapEx.hpp"
#include <vector>

class NFServerIpMgr : public NFSingleton<NFServerIpMgr>
{
public:
    NFServerIpMgr();
    virtual ~NFServerIpMgr();

    std::vector<NF_SHARE_PTR<proto_ff::ServerInfoReport>> GetServerList();

    NF_SHARE_PTR<proto_ff::ServerInfoReport> GetServer(uint32_t busId);
    void AddServer(const proto_ff::ServerInfoReport& reprt);
private:
    NFMapEx<uint32_t, proto_ff::ServerInfoReport> m_serverMap;
};