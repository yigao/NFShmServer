// -------------------------------------------------------------------------
//    @FileName         :    NFServerBindRpcService.h
//    @Author           :    gaoyi
//    @Date             :    23-3-25
//    @Email			:    445267987@qq.com
//    @Module           :    NFServerBindRpcService
//
// -------------------------------------------------------------------------

#pragma once

#include "NFComm/NFPluginModule/NFIRpcService.h"
#include "NFServerComm/NFServerMessage/proto_svr_common.pb.h"

DEFINE_BIND_RPC_SERVICE(proto_ff::NF_RPC_SERVICE_GET_SERVER_INFO_REQ, proto_ff::RpcRequestGetServerInfo, proto_ff::ServerInfoReport)

/**
 * @brief 服务器与服务器直接的注册返回RPC
 */
DEFINE_BIND_RPC_SERVICE(proto_ff::NF_SERVER_TO_SERVER_REGISTER, proto_ff::ServerInfoReportList, proto_ff::ServerInfoReportListRespne)
