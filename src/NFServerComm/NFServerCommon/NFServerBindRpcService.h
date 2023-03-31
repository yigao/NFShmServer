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

/**
 * @brief StoreServer Rpc Service
 */
DEFINE_BIND_RPC_SERVICE(proto_ff::NF_STORESVR_C2S_SELECTOBJ, storesvr_sqldata::storesvr_selobj, storesvr_sqldata::storesvr_selobj_res)
DEFINE_BIND_RPC_SERVICE(proto_ff::NF_STORESVR_C2S_SELECT, storesvr_sqldata::storesvr_sel, storesvr_sqldata::storesvr_sel_res)
DEFINE_BIND_RPC_SERVICE(proto_ff::NF_STORESVR_C2S_INSERTOBJ, storesvr_sqldata::storesvr_insertobj, storesvr_sqldata::storesvr_insertobj_res)
DEFINE_BIND_RPC_SERVICE(proto_ff::NF_STORESVR_C2S_MODIFYOBJ, storesvr_sqldata::storesvr_modobj, storesvr_sqldata::storesvr_modobj_res)
DEFINE_BIND_RPC_SERVICE(proto_ff::NF_STORESVR_C2S_MODIFY, storesvr_sqldata::storesvr_mod, storesvr_sqldata::storesvr_mod_res)
DEFINE_BIND_RPC_SERVICE(proto_ff::NF_STORESVR_C2S_UPDATE, storesvr_sqldata::storesvr_update, storesvr_sqldata::storesvr_update_res)
DEFINE_BIND_RPC_SERVICE(proto_ff::NF_STORESVR_C2S_UPDATEOBJ, storesvr_sqldata::storesvr_updateobj, storesvr_sqldata::storesvr_updateobj_res)
DEFINE_BIND_RPC_SERVICE(proto_ff::NF_STORESVR_C2S_EXECUTE, storesvr_sqldata::storesvr_execute, storesvr_sqldata::storesvr_execute_res)
DEFINE_BIND_RPC_SERVICE(proto_ff::NF_STORESVR_C2S_EXECUTE_MORE, storesvr_sqldata::storesvr_execute_more, storesvr_sqldata::storesvr_execute_more_res);
DEFINE_BIND_RPC_SERVICE(proto_ff::NF_STORESVR_C2S_DELETE, storesvr_sqldata::storesvr_del, storesvr_sqldata::storesvr_del_res)
DEFINE_BIND_RPC_SERVICE(proto_ff::NF_STORESVR_C2S_DELETEOBJ, storesvr_sqldata::storesvr_delobj, storesvr_sqldata::storesvr_delobj_res)
