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

/**
 * @brief 账号登录rpc, proxy server to login server
 */
DEFINE_BIND_RPC_SERVICE(proto_ff::NF_CS_MSG_AccountLoginReq, proto_ff::Proto_CSAccountLoginReq, proto_ff::Proto_SCAccountLoginRsp)

/**
 * @brief 账号注册rpc, proxy server to login server
 */
DEFINE_BIND_RPC_SERVICE(proto_ff::NF_CS_MSG_RegisterAccountReq, proto_ff::Proto_CSRegisterAccountReq, proto_ff::Proto_SCRegisterAccountRsp)

/**
 * @brief 玩家登录rpc, proxy server to world server
 */
DEFINE_BIND_RPC_SERVICE(proto_ff::NF_PTW_PLAYER_LOGIN_REQ, proto_ff::Proto_PTWUserLoginReq, proto_ff::Proto_WTPPlayerLoginRsp)

/**
 * @brief 玩家登录rpc, world server to logic server
 */
DEFINE_BIND_RPC_SERVICE(proto_ff::NF_WTL_PLAYER_LOGIN_REQ, proto_ff::Proto_WorldToLogicLoginReq, proto_ff::Proto_LogicToWorldLoginRsp)

/**
 * @brief 玩家登录rpc, world server to sns server
 */
DEFINE_BIND_RPC_SERVICE(proto_ff::NF_WTS_PLAYER_LOGIN_REQ, proto_ff::Proto_WTSLoginReq, proto_ff::Proto_STWLoginRsp)

/**
 * @brief 玩家重连rpc, proxy server to world server
 */
DEFINE_BIND_RPC_SERVICE(proto_ff::NF_PTW_PLAYER_RECONNECT_MSG_REQ, proto_ff::PTWPlayerReconnectReq, proto_ff::WTPPlayerReconnctRsp)

/**
 * @brief 玩家重连rpc, world server to logic server
 */
DEFINE_BIND_RPC_SERVICE(proto_ff::NF_WTL_PLAYER_RECONNECT_MSG_REQ, proto_ff::WTLPlayerReconnectReq, proto_ff::LTWPlayerReconnectRsp)

/**
 * @brief 玩家重连rpc, world server to sns server
 */
DEFINE_BIND_RPC_SERVICE(proto_ff::NF_WTS_PLAYER_RECONNECT_MSG_REQ, proto_ff::WTSPlayerReconnectReq, proto_ff::STWPlayerReconnectRsp)

/**
 * @brief 玩家重连rpc, world server to game server
 */
DEFINE_BIND_RPC_SERVICE(proto_ff::NF_WTG_PLAYER_RECONNECT_MSG_REQ, proto_ff::WTGPlayerReconnectReq, proto_ff::GTWPlayerReconnectRsp)

/**
 * @brief logic减少sns银行筹码, logic server to sns server
 */
DEFINE_BIND_RPC_SERVICE(proto_ff::NF_LTS_PLAYER_ADD_BANK_JETTON_RPC, proto_ff::Proto_LTS_PlayerAddBankJettonReq, proto_ff::Proto_STL_PlayerAddBankJettonRsp)