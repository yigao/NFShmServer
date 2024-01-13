// -------------------------------------------------------------------------
//    @FileName         :    NFBusDefine.h
//    @Author           :    Yi.Gao
//    @Date             :   2022-09-18
//    @Module           :    NFBusPlugin
//    @Desc             :
// -------------------------------------------------------------------------

#pragma once

#include "NFComm/NFCore/NFPlatform.h"
#include "NFComm/NFKernelMessage/proto_kernel.pb.h"

typedef uint64_t NFDataAlignType;
#define NFBUS_MACRO_SRC_BUS_LIMIT 512     //bus连接方最大数目
#define NFBUS_MACRO_HUGETLB_SIZE 4194304
#define NFBUS_MACRO_MSG_LIMIT 65536
#define NFBUS_MACRO_CONNECTION_CONFIRM_TIMEOUT 30
#define NFBUS_MACRO_BUSID_TYPE uint64_t
#define NFBUS_MACRO_DATA_NODE_SIZE 128
#define NFBUS_MACRO_DATA_ALIGN_SIZE 16
#define NFBUS_MACRO_DATA_ALIGN_TYPE uint64_t
#define NFBUS_MACRO_DATA_MAX_PROTECT_SIZE 16384
#define SHM_CHANNEL_NAME "NFBUSMEM"
#define SHM_CHANNEL_VERSION 2
