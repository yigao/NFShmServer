// -------------------------------------------------------------------------
//    @FileName         :    NFConcurrentQueue.h
//    @Author           :    Gao.Yi
//    @Date             :   2022-09-18
//    @Email			:    445267987@qq.com
//    @Module           :    NFConcurrentQueue.h
//
// -------------------------------------------------------------------------

#pragma once

#include "common/concurrentqueue/concurrentqueue.h"

template<typename T>
class NFConcurrentQueue
{
public:
    NFConcurrentQueue() { }
    virtual ~NFConcurrentQueue() { }
public:
    //malloc more mem
    inline bool Enqueue(const T& item)
    {
        return m_queue.enqueue(item);
    }

    //no malloc, return false
    inline bool TryEnqueue(T const& item)
    {
        return m_queue.try_enqueue(item);
    }

    template<typename It>
    bool EnqueueBulk(It itemFirst, size_t count)
    {
        return m_queue.enqueue_bulk(itemFirst, count);
    }

    bool EnqueueBulk(const std::vector<T>& vec)
    {
        return m_queue.enqueue_bulk(vec.data(), vec.size());
    }

    template<typename U>
    bool TryDequeue(U& item)
    {
        return m_queue.try_dequeue(item);
    }

    template<typename It>
    size_t TryDequeueBulk(It itemFirst, size_t max)
    {
        return m_queue.try_dequeue_bulk(itemFirst, max);
    }

    size_t TryDequeueBulk(std::vector<T>& vec)
    {
        size_t size = m_queue.try_dequeue_bulk(vec.data(), vec.size());
        vec.resize(size);
        return size;
    }

    size_t GetQueueSize() {
        return m_queue.size_approx();
    }

    bool IsQueueEmpty() {
        return m_queue.size_approx() == 0;
    }
private:
    moodycamel::ConcurrentQueue<T> m_queue;
};

template<typename TYPE>
class NFConcurrentQueuePool
{
public:
    NFConcurrentQueuePool(int maxPoolSize = 1000): m_maxPoolSize(maxPoolSize)
    {

    }

    virtual ~NFConcurrentQueuePool()
    {
        while(!m_msgQueue.IsQueueEmpty())
        {
            std::vector<TYPE*> vec;
            vec.resize(200);
            if (m_msgQueue.TryDequeueBulk(vec))
            {
                for(int i = 0; i < (int)vec.size(); i++)
                {
                    if (vec[i])
                    {
                        NF_SAFE_DELETE(vec[i]);
                    }
                }
            }
        }
    }
public:
    TYPE* Alloc()
    {
        TYPE* pType = NULL;
        if (!m_msgQueue.TryDequeue(pType))
        {
            pType = new TYPE();
        }
        return pType;
    }

    bool Free(TYPE* pType)
    {
        if (m_msgQueue.GetQueueSize() > m_maxPoolSize)
        {
            NF_SAFE_DELETE(pType);
        }
        else {
            if (!m_msgQueue.Enqueue(pType))
            {
                NF_SAFE_DELETE(pType);
            }
        }
        return true;
    }
private:
    NFConcurrentQueue<TYPE*> m_msgQueue;
    std::atomic<int> m_maxPoolSize;
};

