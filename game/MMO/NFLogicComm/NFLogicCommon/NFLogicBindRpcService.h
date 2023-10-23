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
 * @brief 创建角色rpc, proxy server to world server
 */
DEFINE_BIND_RPC_SERVICE(proto_ff::CLIENT_CREATE_ROLE_REQ, proto_ff::ClientCreateRoleReq, proto_ff::ClientCreateRoleRsp)

/**
 * @brief 玩家登录rpc, world server to proxy server
 */
DEFINE_BIND_RPC_SERVICE(proto_ff::NOTIFY_GATE_LEAVE_GAME, proto_ff::NotifyGateLeaveGame2, proto_ff::EmptyMessage)

/**
 * @brief 角色进游戏RPC
 */
DEFINE_BIND_RPC_SERVICE(proto_ff::CLIENT_ENTER_GAME_REQ, proto_ff::ClientEnterGameReq, proto_ff::ClientEnterGameRsp)

/**
 * @brief 逻辑服登录社交服务RPC
 */
DEFINE_BIND_RPC_SERVICE(proto_ff::LTS_LOGIN_RPC, proto_ff::LTSLoginReq, proto_ff::STLLoginRsp)

/**
 * @brief 地图注册RPC
 */
DEFINE_BIND_RPC_SERVICE(proto_ff::STS_MAP_REG_RPC, proto_ff::RegisterMapInfoReq, proto_ff::ReigsterMapInfoRsp)

