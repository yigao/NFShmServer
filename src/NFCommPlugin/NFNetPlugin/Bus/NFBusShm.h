// -------------------------------------------------------------------------
//    @FileName         :    NFBusShm.h
//    @Author           :    Yi.Gao
//    @Date             :   2022-09-18
//    @Module           :    NFBusPlugin
//    @Desc             :
// -------------------------------------------------------------------------

#pragma once

#include "NFBusDefine.h"
#include <atomic>

#if NF_PLATFORM == NF_PLATFORM_WIN
#include <Windows.h>
typedef long key_t;
#else
#include <sys/ipc.h>
#include <sys/shm.h>
#endif


struct NFShmStatsBlockError {
	// 统计信息
	size_t m_nWriteCheckSequenceFailedCount; // 写完后校验操作序号错误
	size_t m_nWriteRetryCount;                 // 写操作内部重试次数

	size_t m_nReadBadNodeCount;                // 读到的错误数据节点数量
	size_t m_nReadBadBlockCount;               // 读到的错误数据块数量
	size_t m_nReadWriteTimeoutCount;           // 读到的写超时保护数量
	size_t m_nReadCheckBlockSizeFailedCount; // 读到的数据块长度检查错误数量
	size_t m_ReadCheckNodeSizeFailedCount;  // 读到的数据节点和长度检查错误数量
	size_t m_ReadCheckHashFailedCount;       // 读到的数据hash值检查错误数量
};

#if NF_PLATFORM == NF_PLATFORM_WIN
struct NFShmRecordType {
    NFShmRecordType()
    {
        memset(this, 0, sizeof(NFShmRecordType));
    }
	HANDLE m_nHandle;
	LPCTSTR m_nBuffer;
	size_t m_nSize;
	size_t m_ReferenceCount;
	bool m_nOwner;
	uint64_t m_nBusId;
	uint64_t m_nBusLenth;
	uint64_t m_nUnLinkId;
	uint32_t mPacketParseType; //解码消息类型
};
#else
struct NFShmRecordType{
    NFShmRecordType()
    {
        m_nShmFd = 0;
        m_nShmId = 0;
        m_nBuffer = NULL;
        m_nSize = 0;
        m_ReferenceCount = 0;
        m_nOwner = false;
        m_nBusId = 0;
        m_nBusLenth = 0;
        m_nUnLinkId = 0;
        mPacketParseType = 0;
    }
    int m_nShmFd;
    std::string m_nShmPath;
	int m_nShmId;
	void *m_nBuffer;
	size_t m_nSize;
	size_t m_ReferenceCount;
	bool m_nOwner;
	uint64_t m_nBusId;
    uint64_t m_nBusLenth;
	uint64_t m_nUnLinkId;
	uint32_t mPacketParseType; //解码消息类型
};
#endif

#if NF_PLATFORM == NF_PLATFORM_WIN
__pragma(pack(push, 1))
#  define NFBUS_MACRO_PACK_ATTR
#else
#  define NFBUS_MACRO_PACK_ATTR
// #define NFBUS_MACRO_PACK_ATTR __attribute__((packed))
#endif

// 配置数据结构
struct NFShmConf {
	size_t m_nProtectNodeCount;
	size_t m_nProtectMemorySize;
	uint64_t m_nConfSendTimeoutMs;

	size_t m_nWriteRetryTimes;
	// TODO 接收端校验号(用于保证只有一个接收者)
	volatile std::atomic<size_t> m_nAtomicRecverIdentify;
} NFBUS_MACRO_PACK_ATTR;

// 通道头
struct NFShmChannel {
	char m_nNodeMagic[8]; // 魔术串，用于标识数据类型
    uint16_t m_channelVersion;
    uint16_t m_channelAlignSize;
    uint16_t m_channelHostSize;

	// 数据节点
	size_t m_nNodeSize;
	size_t m_nNodeSizeBinPower; // (用于优化算法) node_size = 1 << node_size_bin_power
	size_t m_nNodeCount;

	// [atomic_read_cur, atomic_write_cur) 内的数据块都是已使用的数据块
	// atomic_write_cur指向的数据块一定是空块，故而必然有一个node的空洞
	// c11的stdatomic.h在很多编译器不支持并且还有些潜规则(gcc 不能使用-fno-builtin 和 -march=xxx)，故而使用c++版本
	volatile std::atomic<size_t> m_nAtomicReadCur;  //
	volatile std::atomic<size_t> m_nAtomicWriteCur; //

	// 第一次读到正在写入数据的时间
	uint64_t m_nFirstFailedWritingTime;

	volatile std::atomic<uint32_t> m_nAtomicOperationSeq; // 操作序列号(用于保证只有一个接收者)

	// 配置
	NFShmConf m_nConf;
	size_t m_nAreaChannelOffset;
	size_t m_nAreaHeadOffset;
	size_t m_nAreaDataOffset;
	size_t m_nAreaEndOffset;

	// 统计信息
	size_t m_nWriteCheckSequenceFailedCount; // 写完后校验操作序号错误
	size_t m_nWriteRetryCount;                 // 写操作内部重试次数

	size_t m_nReadBadNodeCount;                // 读到的错误数据节点数量
	size_t m_nReadBadBlockCount;               // 读到的错误数据块数量
	size_t m_nReadWriteTimeoutCount;           // 读到的写超时保护数量
	size_t m_nReadCheckBlockSizeFailedCount; // 读到的数据块长度检查错误数量
	size_t m_nReadCheckNodeSizeFailedCount;  // 读到的数据节点和长度检查错误数量
	size_t m_nReadCheckHashFailedCount;       // 读到的数据节点和长度检查错误数量
} NFBUS_MACRO_PACK_ATTR;

#if NF_PLATFORM == NF_PLATFORM_WIN
__pragma(pack(pop))
#endif


static_assert(std::is_standard_layout<NFShmChannel>::value, "shm_channel must be a standard layout");

struct NFShmAddr
{
    volatile std::atomic<uint64_t> mDstLinkId;
    volatile std::atomic<uint64_t> mSrcLinkId[NFBUS_MACRO_SRC_BUS_LIMIT];
    volatile std::atomic<uint64_t> mSrcBusLength[NFBUS_MACRO_SRC_BUS_LIMIT];
    volatile std::atomic<uint32_t> mSrcParseType[NFBUS_MACRO_SRC_BUS_LIMIT];
    volatile std::atomic<bool>  bActiveConnect[NFBUS_MACRO_SRC_BUS_LIMIT];
};

// 对齐头
typedef struct {
    NFShmChannel m_nConnectChannel;
	NFShmChannel m_nShmChannel;
	NFShmAddr m_nShmAddr;
	char m_nAlign[12 * 1024 - sizeof(NFShmChannel) - sizeof(NFShmChannel) - sizeof(NFShmAddr)]; // 对齐到12KB,用于以后拓展
} NFShmChannelHead;


/**
 * @brief 数据节点头
 * @note 暂时忽略伪共享造成的cache line失效问题。否则head的内存浪费太大了
 * @see https://en.wikipedia.org/wiki/False_sharing
 */
typedef struct {
	uint32_t m_nFlag;
	uint32_t m_nOperationSeq;
} NFShmNodeHead;

// 数据头
typedef struct {
	size_t m_nBufferSize;
    uint64_t m_nFastCheck;
} NFShmBlockHead;


typedef enum {
	NF_WRITEN = 0x00000001,
	MF_START_NODE = 0x00000002,
} NFShmFlag;

/**
 * @brief 内存通道常量
 * @note 为了压缩内存占用空间，这里使用手动对齐，不直接用 #pragma pack(sizoef(long))
 */
struct NFShmBlock {
	enum size_def {
		channel_head_size = sizeof(NFShmChannelHead),
		block_head_size = ((sizeof(NFShmBlockHead) + NFBUS_MACRO_DATA_ALIGN_SIZE - 1) / NFBUS_MACRO_DATA_ALIGN_SIZE) * NFBUS_MACRO_DATA_ALIGN_SIZE,
		node_head_size = ((sizeof(NFShmNodeHead) + NFBUS_MACRO_DATA_ALIGN_SIZE - 1) / NFBUS_MACRO_DATA_ALIGN_SIZE) * NFBUS_MACRO_DATA_ALIGN_SIZE,

		node_data_size = NFBUS_MACRO_DATA_NODE_SIZE,
		node_head_data_size = node_data_size - block_head_size,
        connect_shm_size = (node_head_size+node_data_size)*100,
	};
};

/**
 * @brief 检测数字是2的几次幂
 */
template <size_t S>
struct NFShmBinPowerCheck {
	static_assert(0 == (S & (S - 1)), "not 2^N"); // 必须是2的N次幂
	static_assert(S, "must not be 0");            // 必须大于0

	enum { value = NFShmBinPowerCheck<(S >> 1)>::value + 1 };
};

template <>
struct NFShmBinPowerCheck<1> {
	enum { value = 0 };
};
