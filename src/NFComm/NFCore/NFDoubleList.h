// -------------------------------------------------------------------------
//    @FileName         :    NFDoubleList.h
//    @Author           :    gaoyi
//    @Date             :    2022/10/10
//    @Email			:    445267987@qq.com
//    @Module           :    NFDoubleList
//
// -------------------------------------------------------------------------

#pragma once

#include "NFPlatform.h"

struct DoubleNode
{
    void*       host;
    DoubleNode* prev;
    DoubleNode* next;
    DoubleNode()
    {
        Reset();
    }

    ~DoubleNode()
    {
        Reset();
    }

    explicit DoubleNode(void* h)
    {
        host = h;
        ResetNode();
    }

    void Reset()
    {
        prev = NULL;
        next = NULL;
        host = NULL;
    }

    bool ResetNode()
    {
        prev = NULL;
        next = NULL;
        return true;
    }

    void* GetHost()
    {
        return host;
    }

    void SetHost(void* h)
    {
        host = h;
    }
};

class DoubleList
{
private:
    uint32_t    count_;
    DoubleNode* head_;
    DoubleNode* tail_;

public:
    DoubleList()
    {
        count_ = 0;
        head_  = NULL;
        tail_  = NULL;
    }
    ~DoubleList() {}

    void Clear()
    {
        count_ = 0;
        head_  = NULL;
        tail_  = NULL;
    }

    uint32_t Count()
    {
        return count_;
    }

    void InsertTail(DoubleNode* elem)
    {
        NF_ASSERT(elem);
        if (likely(tail_ != NULL))
        {
            Insert(tail_, elem);
            tail_ = elem;
        }
        else
        {
            head_ = tail_ = elem;
            elem->next = nullptr;
        }
        ++count_;
    }

    void InsertHead(DoubleNode* elem)
    {
        NF_ASSERT(elem);
        if (likely(head_ != NULL))
        {
            elem->next = head_;
            head_->prev = elem;
            head_ = elem;
        }
        else
        {
            head_ = tail_ = elem;
        }
        ++count_;
    }

    bool Delete(DoubleNode* elem);
    bool IsEmpty() {return head_ == NULL;}

    DoubleNode* Head() {return head_;}
    DoubleNode* Tail() {return tail_;}
    DoubleNode* Prev(DoubleNode* cur)
    {
        NF_ASSERT(cur);
        if (cur)
        {
            return cur->prev;
        }
        else
        {
            return NULL;
        }
    }
    DoubleNode* Next(DoubleNode* cur)
    {
        NF_ASSERT(cur);
        if (cur)
        {
            return cur->next;
        }
        else
        {
            return NULL;
        }
    }

protected:
    void Insert(DoubleNode* prev, DoubleNode* elem);
};


