// -------------------------------------------------------------------------
//    @FileName         :    NFBusDefine.h
//    @Author           :    Yi.Gao
//    @Date             :   xxxx-xx-xx
//    @Module           :    NFBusPlugin
//    @Desc             :
// -------------------------------------------------------------------------

#pragma once

#include "NFComm/NFCore/NFPlatform.h"

typedef enum {
	EN_NFBUS_ERR_SUCCESS = 0,

	EN_NFBUS_ERR_PARAMS = -1,
	EN_NFBUS_ERR_INNER = -2,
	EN_NFBUS_ERR_NO_DATA = -3,  // 无数据
	EN_NFBUS_ERR_BUFF_LIMIT = -4,  // 缓冲区不足
	EN_NFBUS_ERR_MALLOC = -5,  // 分配失败
	EN_NFBUS_ERR_SCHEME = -6,  // 协议错误
	EN_NFBUS_ERR_BAD_DATA = -7,  // 数据校验不通过
	EN_NFBUS_ERR_INVALID_SIZE = -8,  // 数据大小异常
	EN_NFBUS_ERR_NOT_INITED = -9,  // 未初始化
	EN_NFBUS_ERR_ALREADY_INITED = -10, // 已填充初始数据
	EN_NFBUS_ERR_ACCESS_DENY = -11, // 不允许的操作
	EN_NFBUS_ERR_UNPACK = -12, // 解包失败
	EN_NFBUS_ERR_PACK = -13, // 打包失败

	EN_NFBUS_ERR_NFNODE_NOT_FOUND = -65, // 查找不到目标节点
	EN_NFBUS_ERR_NFNODE_INVALID_ID = -66, // 不可用的ID
	EN_NFBUS_ERR_NFNODE_NO_CONNECTION = -67, // 无可用连接
	EN_NFBUS_ERR_NFNODE_FAULT_TOLERANT = -68, // 超出容错值
	EN_NFBUS_ERR_NFNODE_INVALID_MSG = -69, // 错误的消息
	EN_NFBUS_ERR_NFNODE_BUS_ID_NOT_MNFCH = -70, // Bus ID不匹配
	EN_NFBUS_ERR_NFNODE_TTL = -71, // ttl限制
	EN_NFBUS_ERR_NFNODE_MASK_CONFLICT = -72, // 域范围错误或冲突
	EN_NFBUS_ERR_NFNODE_ID_CONFLICT = -73, // ID冲突
	EN_NFBUS_ERR_NFNODE_SRC_DST_IS_SAME = -75, // 发送源和发送目标不能相同

	EN_NFBUS_ERR_CHANNEL_SIZE_TOO_SMALL = -101,
	EN_NFBUS_ERR_CHANNEL_BUFFER_INVALID = -102, // 缓冲区错误（已被其他模块使用或检测冲突）
	EN_NFBUS_ERR_CHANNEL_ADDR_INVALID = -103, // 地址错误
	EN_NFBUS_ERR_CHANNEL_CLOSING = -104, // 正在关闭
	EN_NFBUS_ERR_CHANNEL_NOT_SUPPORT = -105, // 不支持的通道

	EN_NFBUS_ERR_NODE_BAD_BLOCK_NODE_NUM = -202, // 发现写坏的数据块 - 节点数量错误
	EN_NFBUS_ERR_NODE_BAD_BLOCK_BUFF_SIZE = -203, // 发现写坏的数据块 - 节点数量错误
	EN_NFBUS_ERR_NODE_BAD_BLOCK_WSEQ_ID = -204, // 发现写坏的数据块 - 写操作序列错误
	EN_NFBUS_ERR_NODE_BAD_BLOCK_CSEQ_ID = -205, // 发现写坏的数据块 - 检查操作序列错误

	EN_NFBUS_ERR_NODE_TIMEOUT = -211, // 操作超时

	EN_NFBUS_ERR_SHM_GET_FAILED = -301, // 连接共享内存出错，具体错误原因可以查看errno或类似的位置
	EN_NFBUS_ERR_SHM_NOT_FOUND = -302, // 共享内存未找到

	EN_NFBUS_ERR_SOCK_BIND_FAILED = -401, // 绑定地址或端口失败
	EN_NFBUS_ERR_SOCK_LISTEN_FAILED = -402, // 监听失败
	EN_NFBUS_ERR_SOCK_CONNECT_FAILED = -403, // 连接失败

	EN_NFBUS_ERR_PIPE_BIND_FAILED = -501, // 绑定地址或端口失败
	EN_NFBUS_ERR_PIPE_LISTEN_FAILED = -502, // 监听失败
	EN_NFBUS_ERR_PIPE_CONNECT_FAILED = -503, // 连接失败
	EN_NFBUS_ERR_PIPE_ADDR_TOO_LONG = -504, // 地址路径过长，绝对路径长度要小于 sizeof(sockaddr_un.sun_pNFh) - 1
	EN_NFBUS_ERR_PIPE_REMOVE_FAILED = -505, // 删除老socket失败

	EN_NFBUS_ERR_DNS_GETADDR_FAILED = -601, // DNS解析失败
	EN_NFBUS_ERR_CONNECTION_NOT_FOUND = -602, // 找不到连接
	EN_NFBUS_ERR_WRITE_FAILED = -603, // 底层API写失败
	EN_NFBUS_ERR_READ_FAILED = -604, // 底层API读失败
	EN_NFBUS_ERR_EV_RUN = -605, // 底层API事件循环失败
	EN_NFBUS_ERR_NO_LISTEN = -606, // 尚未监听（绑定）
	EN_NFBUS_ERR_CLOSING = -607, // 正在关闭或已关闭

	EN_NFBUS_ERR_MIN = -999,
} NFBUS_ERROR_TYPE;

typedef uint64_t NFDataAlignType;
#define NFBUS_MACRO_SRC_BUS_LIMIT 512     //bus连接方最大数目
#define NFBUS_MACRO_HUGETLB_SIZE 4194304
#define NFBUS_MACRO_MSG_LIMIT 65536
#define NFBUS_MACRO_CONNECTION_CONFIRM_TIMEOUT 30
#define NFBUS_MACRO_BUSID_TYPE uint64_t
#define NFBUS_MACRO_DATA_NODE_SIZE 128
#define NFBUS_MACRO_DATA_ALIGN_TYPE uint64_t
#define NFBUS_MACRO_DATA_MAX_PROTECT_SIZE 16384
#define SHM_CHANNEL_NAME "NFBUSMEM"
