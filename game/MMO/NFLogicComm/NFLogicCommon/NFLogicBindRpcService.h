// -------------------------------------------------------------------------
//    @FileName         :    NFLogicBindRpcService.h
//    @Author           :    gaoyi
//    @Date             :    23-7-6
//    @Email			:    445267987@qq.com
//    @Module           :    NFLogicBindRpcService
//
// -------------------------------------------------------------------------

#pragma once

#include "NFComm/NFPluginModule/NFIRpcService.h"
#include "AllProtocol.h"
#include "Login.pb.h"




/**
 * @brief 玩家登录rpc, proxy server to world server
 */
DEFINE_BIND_RPC_SERVICE(proto_ff::CLIENT_LOGIN_REQ, proto_ff::ClientLoginReq, proto_ff::ClientLoginRsp)

/**
 * @brief 玩家登录rpc, world server to proxy server
 */
DEFINE_BIND_RPC_SERVICE(proto_ff::NOTIFY_GATE_LEAVE_GAME, proto_ff::NotifyGateLeaveGame2, proto_ff::EmptyMessage)
