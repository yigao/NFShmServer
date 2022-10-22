//
// Created by gaoyi on 2022/9/18.
//

#include "NFServerCommonDefine.h"

void NFServerCommon::WriteServerInfo(proto_ff::ServerInfoReport* pData, NFServerConfig* pConfig)
{
    pData->set_bus_id(pConfig->BusId);
    pData->set_server_id(pConfig->ServerId);
    pData->set_server_type(pConfig->ServerType);
    pData->set_server_name(pConfig->ServerName);

    pData->set_bus_length(pConfig->BusLength);
    pData->set_link_mode(pConfig->LinkMode);
    pData->set_url(pConfig->Url);
    pData->set_server_ip(pConfig->ServerIp);
    pData->set_server_port(pConfig->ServerPort);
    pData->set_route_svr(pConfig->RouteConfig.RouteAgent);
    pData->set_external_server_ip(pConfig->ExternalServerIp);
    pData->set_external_server_port(pConfig->ExternalServerPort);
    return;
}

void NFServerCommon::WriteServerInfo(proto_ff::ServerInfoReport* pData, const NFSystemInfo& systemInfo)
{
    pData->set_system_info(systemInfo.GetOsInfo().mOsDescription);
    pData->set_total_mem(systemInfo.GetMemInfo().mTotalMem);
    pData->set_free_mem(systemInfo.GetMemInfo().mFreeMem);
    pData->set_used_mem(systemInfo.GetMemInfo().mUsedMem);

    pData->set_proc_cpu(systemInfo.GetProcessInfo().mCpuUsed);
    pData->set_proc_mem(systemInfo.GetProcessInfo().mMemUsed);
    pData->set_proc_thread(systemInfo.GetProcessInfo().mThreads);
    pData->set_proc_name(systemInfo.GetProcessInfo().mName);
    pData->set_proc_cwd(systemInfo.GetProcessInfo().mCwd);
    pData->set_proc_pid(systemInfo.GetProcessInfo().mPid);
    pData->set_server_cur_online(systemInfo.GetUserCount());
    return;
}

