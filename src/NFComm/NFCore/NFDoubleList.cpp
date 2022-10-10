// -------------------------------------------------------------------------
//    @FileName         :    NFDoubleList.cpp
//    @Author           :    gaoyi
//    @Date             :    2022/10/10
//    @Email			:    445267987@qq.com
//    @Module           :    NFDoubleList
//
// -------------------------------------------------------------------------

#include "NFDoubleList.h"

void NFDoubleList::Insert(NFDoubleNode* prev, NFDoubleNode* elem)
{
    NF_ASSERT(prev);
    NF_ASSERT(elem);
    NFDoubleNode* next = prev->next;
    prev->next = elem;
    elem->prev = prev;
    elem->next = next;
    if (next)
    {
        next->prev = elem;
    }
}

bool NFDoubleList::Delete(NFDoubleNode* elem)
{
    bool result = false;

    if (elem == NULL)
    {
        goto Exit0;
    }

    if (head_ == NULL)
    {
        goto Exit1;
    }

    if (head_ == elem)
    {
        head_ = head_->next;
        if (head_ == NULL)
        {
            tail_ = NULL;
        }
        else
        {
            head_->prev = NULL;
        }
        NF_ASSERT(count_ > 0);
        --count_;
        elem->ResetNode();
    }
    else if (tail_ == elem)
    {
        tail_ = tail_->prev;
        tail_->next = NULL;
        NF_ASSERT(count_ > 0);
        --count_;
        elem->ResetNode();
    }
    else if (elem->prev != NULL && elem->next != NULL)
    {
        elem->prev->next = elem->next;
        elem->next->prev = elem->prev;
        NF_ASSERT(count_ > 0);
        --count_;
        elem->ResetNode();
    }

Exit1:
    result = true;
Exit0:
    return result;
}


