// -------------------------------------------------------------------------
//    @FileName         :    NFLinearQueue.h
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFLinearQueue.h
//
// -------------------------------------------------------------------------

#pragma once

template <typename DATA_TYPE, int MAX_NODE_NUM>
class NFLinearQueue
{
public:
    NFLinearQueue();
    ~NFLinearQueue();

public:
    //!获取队列首部数据
    const DATA_TYPE* GetHeadData() const;

    //!获取队列尾部数据
    const DATA_TYPE* GetTailData() const;

    //!获取队列长度
    int GetQueueLength() const;

    //!获取队列首部数据，并将其Pop出队列
    DATA_TYPE* PopHeadData();

    //!清空队列
    int Clear();

    //!向队列中Push数据
    int PushData(const DATA_TYPE& rstData);

    //在队首插入元素 earnestwu
    int InsertDataToHead(const DATA_TYPE& rstData);

private:
    DATA_TYPE m_astData[MAX_NODE_NUM]; //!<数据数组
    int m_iHeadIdx; //!<队列首部索引
    int m_iTailIdx; //!<队列尾部索引
};

template <typename DATA_TYPE, int MAX_NODE_NUM>
NFLinearQueue<DATA_TYPE, MAX_NODE_NUM>::NFLinearQueue()
{
    m_iHeadIdx = -1;
    m_iTailIdx = -1;
}

template <typename DATA_TYPE, int MAX_NODE_NUM>
NFLinearQueue<DATA_TYPE, MAX_NODE_NUM>::~NFLinearQueue()
{

}

template <typename DATA_TYPE, int MAX_NODE_NUM>
int NFLinearQueue<DATA_TYPE, MAX_NODE_NUM>::Clear()
{
    m_iHeadIdx = -1;
    m_iTailIdx = -1;

    return 0;
}

template <typename DATA_TYPE, int MAX_NODE_NUM>
const DATA_TYPE* NFLinearQueue<DATA_TYPE, MAX_NODE_NUM>::GetHeadData() const
{
    //不存在头节点
    if(m_iHeadIdx < 0 || m_iHeadIdx >= MAX_NODE_NUM)
    {
        return NULL;
    }

    return &m_astData[m_iHeadIdx];
}

template <typename DATA_TYPE, int MAX_NODE_NUM>
const DATA_TYPE* NFLinearQueue<DATA_TYPE, MAX_NODE_NUM>::GetTailData() const
{
    //不存在尾节点
    if(m_iTailIdx < 0 || m_iTailIdx >= MAX_NODE_NUM)
    {
        return NULL;
    }

    return &m_astData[m_iTailIdx];
}

template <typename DATA_TYPE, int MAX_NODE_NUM>
int NFLinearQueue<DATA_TYPE, MAX_NODE_NUM>::GetQueueLength() const
{
    if(m_iHeadIdx == -1)
    {
        return 0;
    }

    if(m_iHeadIdx <= m_iTailIdx)
    {
        return (m_iTailIdx - m_iHeadIdx) + 1;
    }
    else
    {
        return MAX_NODE_NUM - (m_iHeadIdx - m_iTailIdx) + 1;
    }
}


template <typename DATA_TYPE, int MAX_NODE_NUM>
DATA_TYPE* NFLinearQueue<DATA_TYPE, MAX_NODE_NUM>::PopHeadData()
{
    //不存在头节点
    if(m_iHeadIdx < 0 || m_iHeadIdx >= MAX_NODE_NUM)
    {
        return NULL;
    }

    DATA_TYPE* pstHeadData = &m_astData[m_iHeadIdx];

    //队列只有一个节点了
    if(m_iHeadIdx == m_iTailIdx)
    {
        m_iHeadIdx = -1;
        m_iTailIdx = -1;
    }
    else
    {
        m_iHeadIdx = (m_iHeadIdx + 1) % MAX_NODE_NUM;
    }

    return pstHeadData;
}

template <typename DATA_TYPE, int MAX_NODE_NUM>
int NFLinearQueue<DATA_TYPE, MAX_NODE_NUM>::PushData(const DATA_TYPE& rstData)
{
    if((m_iTailIdx + 1) % MAX_NODE_NUM == m_iHeadIdx)
    {
        return -1;
    }

    //队列中没有数据
    if(m_iTailIdx == -1)
    {
        m_iHeadIdx = m_iTailIdx = 0;
        m_astData[m_iTailIdx] = rstData;
    }
    else
    {
        m_iTailIdx = (m_iTailIdx + 1) % MAX_NODE_NUM;
        m_astData[m_iTailIdx] = rstData;
    }

    return 0;
}

template <typename DATA_TYPE, int MAX_NODE_NUM>
int NFLinearQueue<DATA_TYPE, MAX_NODE_NUM>::InsertDataToHead(const DATA_TYPE& rstData)
{
    if((m_iTailIdx + 1) % MAX_NODE_NUM == m_iHeadIdx)
    {
        return -1;
    }

    //队列中没有数据
    if(m_iTailIdx == -1)
    {
        m_iHeadIdx = m_iTailIdx = 0;
        m_astData[m_iTailIdx] = rstData;
    }
    else
    {
        m_iHeadIdx = m_iHeadIdx ? (m_iHeadIdx - 1) : (MAX_NODE_NUM - 1);
        m_astData[m_iHeadIdx] = rstData;
    }

    return 0;
}
