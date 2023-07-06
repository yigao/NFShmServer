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
#include "ClientServerCmd.pb.h"
#include "CSLogin.pb.h"

DEFINE_BIND_RPC_SERVICE(proto_ff::NF_CS_MSG_AccountLoginReq, proto_ff::Proto_CSAccountLoginReq, proto_ff::Proto_SCAccountLoginRsp)
