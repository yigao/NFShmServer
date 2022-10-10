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
#include "NFLikely.h"

struct NFDoubleNode
{
    void*       host;
    NFDoubleNode* prev;
    NFDoubleNode* next;
    NFDoubleNode()
    {
        Reset();
    }

    ~NFDoubleNode()
    {
        Reset();
    }

    explicit NFDoubleNode(void* h)
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

class NFDoubleList
{
private:
    uint32_t    count_;
    NFDoubleNode* head_;
    NFDoubleNode* tail_;

public:
    NFDoubleList()
    {
        count_ = 0;
        head_  = NULL;
        tail_  = NULL;
    }
    ~NFDoubleList() {}

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

    void InsertTail(NFDoubleNode* elem)
    {
        NF_ASSERT(elem);
        if (LIKELY(tail_ != NULL))
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

    void InsertHead(NFDoubleNode* elem)
    {
        NF_ASSERT(elem);
        if (LIKELY(head_ != NULL))
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

    bool Delete(NFDoubleNode* elem);
    bool IsEmpty() {return head_ == NULL;}

    NFDoubleNode* Head() {return head_;}
    NFDoubleNode* Tail() {return tail_;}
    NFDoubleNode* Prev(NFDoubleNode* cur)
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
    NFDoubleNode* Next(NFDoubleNode* cur)
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
    void Insert(NFDoubleNode* prev, NFDoubleNode* elem);
};


