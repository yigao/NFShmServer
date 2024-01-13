// -------------------------------------------------------------------------
//    @FileName         :    NFChunkPool.h
//    @Author           :    gaoyi
//    @Date             :    2022/10/10
//    @Email			:    445267987@qq.com
//    @Module           :    NFChunkPool
//
// -------------------------------------------------------------------------

#pragma once

#include "NFComm/NFCore/NFPlatform.h"
#include "NFComm/NFCore/NFDoubleList.h"

struct NFMemBlock
{
    uint32_t   free_idx;
    uint32_t   free_num;
    void*      free_list;
    NFDoubleNode block_list;

    NFMemBlock()
            : free_idx(0),
              free_num(0),
              free_list(NULL),
              block_list(reinterpret_cast<void*>(this))
    {}
};

class NFChunkPool
{
public:
    NFChunkPool(uint32_t reserve_size,
                uint32_t chunk_size,
                uint32_t chunk_count,
                bool free_to_sys);
    virtual ~NFChunkPool();

    void* AllocChunk();
    bool  FreeChunk(void* chunk);

    uint32_t ChunkSize()
    {
        return chunk_size_;
    }

protected:
    NFMemBlock* AllocBlock();
    void*  AllocChunk(NFMemBlock* block);
    bool   FreeChunk(NFMemBlock* block, void* chunk);
    void   FreeBlockList(NFDoubleList& list);
    void*& NextOf(void* const chunk);

protected:
    bool        free_to_sys_;
    uint32_t    reserve_size_;
    uint32_t    chunk_size_;
    uint32_t    chunk_count_;
    uint32_t    free_count_;
    uint32_t    free_threshold_;
    size_t      mem_size_;
    NFDoubleList  block_list_;
    NFDoubleList  empty_list_;
    NFDoubleList  full_list_;
};

#ifndef  CHECK_MEM_LEAK
#define  CHECK_MEM_LEAK
#endif // CHECK_MEM_LEAK

