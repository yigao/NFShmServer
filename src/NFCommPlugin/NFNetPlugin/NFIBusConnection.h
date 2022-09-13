// -------------------------------------------------------------------------
//    @FileName         :    NFIBusConnect.h
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFIBusConnect.h
//
// -------------------------------------------------------------------------

#pragma once

#include "NFComm/NFPluginModule/NFIBusModule.h"
#include "NFComm/NFCore/NFSpinLock.h"
#include "NFBusHash.h"
#include "NFBusDefine.h"
#include "NFBusShm.h"
#include "NFINetMessage.h"
#include "NFNetDefine.h"
#include "NFComm/NFCore/NFBuffer.h"
#include "NFIConnection.h"
#include <map>

typedef std::function<void(eMsgType type, const uint64_t conntionLinkId, const uint64_t objectLinkId, const char* pBuf, uint32_t sz, uint32_t nMsgId, uint64_t nSendValue, uint64_t nSendId)> BusMsgPeerCallback;

struct MsgFromBusInfo
{
    MsgFromBusInfo()
    {
        nType = eMsgType_Num;
        nMsgId = 0;
        nSendValue = 0;
        nSendId = 0;
        nLinkId = 0;
    }

    MsgFromBusInfo(uint64_t linkId) : nLinkId(linkId)
    {
        nType = eMsgType_Num;
        nMsgId = 0;
        nSendValue = 0;
        nSendId = 0;
    }

    eMsgType nType;
    std::string strMsg;
    uint32_t nMsgId;
    uint64_t nSendValue;
    uint64_t nSendId;
    uint64_t nLinkId;
};

class NFIBusConnection : public NFIConnection
{
public:
    NFIBusConnection(NFIPluginManager *p, NF_SERVER_TYPES serverType, const NFMessageFlag &flag) : NFIConnection(p, serverType, flag)
    {
        m_pShmRecord = NULL;
        m_nLastActionChannelPtr = NULL;
        mxBuffer.AssureSpace(4 * 1024 * 1024);
    }

    ~NFIBusConnection()
    {
        if (m_pShmRecord)
        {
            NF_SAFE_DELETE(m_pShmRecord);
        }
    }

public:
    const NFMessageFlag& GetBindFlag() const;

    int SendBusConnectMsg(uint64_t busId, uint64_t busLength);
    int SendBusConnectRspMsg(uint64_t busId, uint64_t busLength);

    /**
     * @brief 获得连接IP
     *
     * @param  usLinkId
     * @return std::string
     */
    virtual std::string GetLinkIp();

    /**
    * @brief 关闭连接
    *
    * @param  usLinkId
    * @return
    */
    virtual void CloseLinkId();

    /**
    * @brief 通过key找到相应的共享内存
    */
    virtual NFShmChannel *GetShmChannel();

    /**
     * @brief 通过key找到相应的共享内存
     */
    virtual NFShmRecordType *GetShmRecord();

    /**
     * @brief 关闭一块共享内存
     * @param shm_key 共享内存Key
     * @return int
     */
    int CloseShmBuffer();

    /**
     * @brief 创建一块共享内存
     * @param shm_key 共享内存Key
     * @param len 共享内存长度
     * @param channel 获得共享内存结构体
     * @param conf 设置的共享内存配置
     * @return int
     */
    int OpenShmBuffer(key_t shm_key, size_t len, void **data, size_t *real_size, bool create);

    /**
     * @brief attach上一块共享内存
     * @param shm_key 共享内存Key
     * @param len 共享内存长度
     * @param channel 获得共享内存结构体
     * @param conf 设置的共享内存配置
     * @return int
     */
    virtual int AttachShm(key_t shm_key, size_t len, NFShmChannel **channel, const NFShmConf *conf);

    /**
     * @brief 初始化上一块共享内存
     * @param shm_key 共享内存Key
     * @param len 共享内存长度
     * @param channel 获得共享内存结构体
     * @param conf 设置的共享内存配置
     * @return int
     */
    virtual int InitShm(key_t shm_key, size_t len, NFShmChannel **channel, const NFShmConf *conf);

    /**
     * @brief 关闭一块共享内存
     * @param shm_key 共享内存Key
     * @return int
     */
    virtual int CloseShm();

    virtual void SetMsgPeerCallback(const BusMsgPeerCallback& cb);

    /**
     * @brief	发送数据
     *
     * @param pData		发送的数据, 这里的数据已经包含了数据头
     * @param unSize	数据的大小
     * @return
     */
    virtual bool Send(const char* pData, uint32_t unSize) = 0;

    /**
     * @brief	发送数据 不包含数据头
     *
     * @param pData		发送的数据,
     * @param unSize	数据的大小
     * @return
     */
    virtual bool Send(uint32_t nMsgID, const char* msg, uint32_t nLen, uint64_t nSendValue, uint64_t nSendId) = 0;

protected:
    /**
     * @brief 发送数据
     * @return int
     */
    int ShmSend(const void *buf, size_t len);

    /**
     * @brief 接受数据
     * @return int
     */
    int ShmRecv(void *buf, size_t len, size_t *recv_size);

    /**
     * @brief 发送数据
     * @return int
     */
    int ShmSend(NFShmChannel *channel, const void *buf, size_t len);

    /**
     * @brief 接受数据
     * @return int
     */
    int ShmRecv(NFShmChannel *channel, void *buf, size_t len, size_t *recv_size);

    /**
     * @brief 发送数据
     * @return int
     */
    int ShmRealSend(NFShmChannel *channel, const void *buf, size_t len);

protected:

    std::pair<size_t, size_t> LastAction();

    /**
     * @brief 获取共享内存状态
     * @return int
     */
    void ShowShmChannel(NFShmChannel *channel, std::ostream &out, bool need_node_status, size_t need_node_data);

    /**
     * @brief 获取共享内存状态
     * @return int
     */
    void GetShmStats(NFShmChannel *channel, NFShmStatsBlockError &out);

protected:
    /**
     * @brief 设置写超时
     */
    static int SetWriteTimeout(NFShmChannel *channel, uint64_t ms);

    /*shm_key*
     * @brief 获取写超时
     */
    static uint64_t GetWriteTimeout(NFShmChannel *channel);

    /**
     * @brief 写重复次数
     */
    static int SetWriteRetryTimes(NFShmChannel *channel, size_t times);

    /**
     * @brief 获取写重复次数
     */
    static size_t GetWriteRetryTimes(NFShmChannel *channel);

    /**
     * @brief 配置
     * @param conf
     */
    static void CopyConf(NFShmConf &dst, const NFShmConf &src);

    /**
     * @brief 检查标记位
     * @param flag 待操作的flag
     * @param checked 检查项
     * @return 检查结果flag
     */
    static bool CheckFlag(uint32_t flag, NFShmFlag checked) { return !!(flag & checked); }

    /**
     * @brief 设置标记位
     * @param flag 待操作的flag
     * @param checked 设置项flag
     * @return 设置结果flag
     */
    static uint32_t SetFlag(uint32_t flag, NFShmFlag checked) { return flag | checked; }

    /**
     * @brief 生存默认配置
     * @param conf
     */
    static void CreateDefaultConf(NFShmChannel *channel);

    /**
     * @brief 获取数据节点head
     * @param channel 内存通道
     * @param index 节点索引
     * @param data 数据区起始地址
     * @param data_len 到缓冲区末尾的长度
     * @return 节点head指针
     */
    static volatile NFShmNodeHead *GetNodeHead(NFShmChannel *channel, size_t index, void **data, size_t *data_len);

    /**
     * @brief 获取数据块head
     * @param channel 内存通道
     * @param index 节点索引
     * @return 数据块head指针
     */
    static NFShmBlockHead *GetBlockHead(NFShmChannel *channel, size_t index, void **data, size_t *data_len);

    /**
     * @brief 获取后面的数据块index
     * @param channel 内存通道
     * @param index 节点索引
     * @param offset 索引偏移
     * @return 数据块head指针
     */
    static size_t GetNextIndex(NFShmChannel *channel, size_t index, size_t offset);

    /**
     * @brief 获取可用的数据节点数量
     * @param channel 内存通道
     * @param read_cur 当前读游标
     * @param write_cur 当前写游标
     * @return 可用的节点数量
     */
    static size_t GetAvailableNodeCount(NFShmChannel *channel, size_t read_cur, size_t write_cur);

    /**
     * @brief 获取使用的数据节点数量
     * @param channel 内存通道
     * @param begin_cur 起始游标
     * @param end_cur 结束游标
     * @return 使用的数据节点数量
     */
    static size_t GetNodeRangeCount(NFShmChannel *channel, size_t begin_cur, size_t end_cur);

    /**
     * @brief 获取前面的的数据块index
     * @param channel 内存通道
     * @param index 节点索引
     * @param offset 索引偏移
     * @return 数据块head指针
     */
    // static inline size_t mem_previous_index(mem_channel* channel, size_t index, size_t offset) {
    //    assert(channel);
    //    return (index + channel->node_count - offset) % channel->node_count;
    //}

    static uint32_t FetchOperationSeq(NFShmChannel *channel);

    /**
     * @brief 计算一定长度数据需要的数据node数量
     * @param len 数据长度
     * @return 数据长度需要的数据块数量
     */
    static size_t CalcNodeNum(NFShmChannel *channel, size_t len);

    /**
     * @brief 生成校验码
     * @param src 源数据
     * @param len 数据长度
     * @note Hash 快速校验
     */
    static NFDataAlignType FastCheck(const void *src, size_t len);

    // 对齐单位的大小必须是2的N次方
    static_assert(0 == (sizeof(NFDataAlignType) & (sizeof(NFDataAlignType) - 1)), "data align size must be 2^N");
    // 节点大小必须是2的N次
    static_assert(0 == ((NFShmBlock::node_data_size - 1) & NFShmBlock::node_data_size), "node size must be 2^N");
    // 节点大小必须是对齐单位的2的N次方倍
    static_assert(0 == (NFShmBlock::node_data_size & (NFShmBlock::node_data_size - sizeof(NFDataAlignType))),
                  "node size must be [data align size] * 2^N");
protected:
    NFShmRecordType *m_pShmRecord = NULL;
    NFBuffer mxBuffer;
    NFMessageFlag m_bindFlag;
    BusMsgPeerCallback m_busMsgPeerCb;

    /**
     * @brief 调试辅助信息
     * @note 不再使用tls记录调试信息，以防跨线程dump拿不到数据
     */
    size_t m_nLastActionChannelEndNodeIndex = 0;
    size_t m_nLastActionChannelBeginNodeIndex = 0;
    NFShmChannel *m_nLastActionChannelPtr = NULL;
};
