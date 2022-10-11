// -------------------------------------------------------------------------
//    @FileName         :    NFNetInfoQueue.h
//    @Author           :    gaoyi
//    @Date             :    2022/10/11
//    @Email			:    445267987@qq.com
//    @Module           :    NFNetInfoQueue
//
// -------------------------------------------------------------------------

#pragma once

#include "NFComm/NFCore/NFConcurrentQueue.h"
#include "NFComm/NFCore/NFSingleton.hpp"

template <typename TYPE>
class NFNetInfoPool : public NFSingleton<NFNetInfoPool<TYPE>>
{
public:
    NFNetInfoPool(int maxPoolSize = 1000):m_maxPoolSize(maxPoolSize)
    {

    }

    virtual ~NFNetInfoPool()
    {

    }
public:
    TYPE* Alloc(size_t buffer_size)
    {
        TYPE* pType = NULL;
        if (buffer_size <= 128)
        {
           if (!m_218MsgQueue.TryDequeue(pType))
           {
               pType = new TYPE();
           }
           return pType;
        }
        else if (buffer_size <= 256)
        {
            if (!m_256MsgQueue.TryDequeue(pType))
            {
                pType = new TYPE();
            }
            return pType;
        }
        else if (buffer_size <= 512)
        {
            if (!m_512MsgQueue.TryDequeue(pType))
            {
                pType = new TYPE();
            }
            return pType;
        }
        else if (buffer_size <= 1024)
        {
            if (!m_1024MsgQueue.TryDequeue(pType))
            {
                pType = new TYPE();
            }
            return pType;
        }
        else if (buffer_size <= 2048)
        {
            if (!m_2048MsgQueue.TryDequeue(pType))
            {
                pType = new TYPE();
            }
            return pType;
        }
        else if (buffer_size <= 4096)
        {
            if (!m_4096MsgQueue.TryDequeue(pType))
            {
                pType = new TYPE();
            }
            return pType;
        }
        else
        {
            if (!m_moreMsgQueue.TryDequeue(pType))
            {
                pType = new TYPE();
            }
            return pType;
        }
    }

    bool Free(TYPE* pType, size_t buffer_size)
    {
        if (buffer_size <= 128)
        {
            if (m_218MsgQueue.GetQueueSize() > m_maxPoolSize)
            {
                NF_SAFE_DELETE(pType);
            }
            else {
                if (!m_218MsgQueue.Enqueue(pType))
                {
                    NF_SAFE_DELETE(pType);
                }
            }
        }
        else if (buffer_size <= 256)
        {
            if (m_256MsgQueue.GetQueueSize() > m_maxPoolSize)
            {
                NF_SAFE_DELETE(pType);
            }
            else {
                if (!m_256MsgQueue.Enqueue(pType))
                {
                    NF_SAFE_DELETE(pType);
                }
            }
        }
        else if (buffer_size <= 512)
        {
            if (m_512MsgQueue.GetQueueSize() > m_maxPoolSize)
            {
                NF_SAFE_DELETE(pType);
            }
            else {
                if (!m_512MsgQueue.Enqueue(pType))
                {
                    NF_SAFE_DELETE(pType);
                }
            }
        }
        else if (buffer_size <= 1024)
        {
            if (m_1024MsgQueue.GetQueueSize() > m_maxPoolSize)
            {
                NF_SAFE_DELETE(pType);
            }
            else {
                if (!m_1024MsgQueue.Enqueue(pType))
                {
                    NF_SAFE_DELETE(pType);
                }
            }
        }
        else if (buffer_size <= 2048)
        {
            if (m_2048MsgQueue.GetQueueSize() > m_maxPoolSize)
            {
                NF_SAFE_DELETE(pType);
            }
            else {
                if (!m_2048MsgQueue.Enqueue(pType))
                {
                    NF_SAFE_DELETE(pType);
                }
            }
        }
        else if (buffer_size <= 4096)
        {
            if (m_4096MsgQueue.GetQueueSize() > m_maxPoolSize)
            {
                NF_SAFE_DELETE(pType);
            }
            else {
                if (!m_4096MsgQueue.Enqueue(pType))
                {
                    NF_SAFE_DELETE(pType);
                }
            }
        }
        else
        {
            if (m_moreMsgQueue.GetQueueSize() > m_maxPoolSize)
            {
                NF_SAFE_DELETE(pType);
            }
            else {
                if (!m_moreMsgQueue.Enqueue(pType))
                {
                    NF_SAFE_DELETE(pType);
                }
            }
        }
        return true;
    }
private:
    NFConcurrentQueue<TYPE*> m_218MsgQueue;
    NFConcurrentQueue<TYPE*> m_256MsgQueue;
    NFConcurrentQueue<TYPE*> m_512MsgQueue;
    NFConcurrentQueue<TYPE*> m_1024MsgQueue;
    NFConcurrentQueue<TYPE*> m_2048MsgQueue;
    NFConcurrentQueue<TYPE*> m_4096MsgQueue;
    NFConcurrentQueue<TYPE*> m_moreMsgQueue;
    std::atomic<int> m_maxPoolSize;
};

