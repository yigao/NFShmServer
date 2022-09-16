// -------------------------------------------------------------------------
//    @FileName         :    NFServerDefine.h
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFPluginModule
//
// -------------------------------------------------------------------------
#pragma once

#include <stdint.h>
#include <functional>
#include <string>
#include <vector>

#include "NFComm/NFCore/NFPlatform.h"
#include "NFComm/NFCore/NFSlice.hpp"
#include "NFComm/NFCore/NFSimpleBuffer.h"
#include "NFComm/NFKernelMessage/proto_kernel.pb.h"
#include "NFComm/NFKernelMessage/storesvr_sqldata.pb.h"

//定义服务器引擎模块
enum NF_PLUGIN_SERVER_MODULE_TYPE {
    NF_PLUGIN_SERVER_BEGIN_TYPE = 100,
    /////////////NFMasterServer////////////////
    NF_MASTER_SERVER_MODULE_ID = 101,
    //////////////////NFProxyServer//////////////////
    NF_PROXY_SERVER_MODULE_ID = 102,
    NF_PROXY_CLIENT_MODULE_ID = 103,
    NF_PLUGIN_SERVER_MDOULE_MAX = 200,
};