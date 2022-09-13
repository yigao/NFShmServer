// -------------------------------------------------------------------------
//    @FileName         :    NFConcurrentQueue.h
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
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
        return m_queue.try_dequeue(item);
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

