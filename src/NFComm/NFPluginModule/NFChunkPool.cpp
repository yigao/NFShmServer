// -------------------------------------------------------------------------
//    @FileName         :    NFChunkPool.cpp
//    @Author           :    gaoyi
//    @Date             :    2022/10/10
//    @Email			:    445267987@qq.com
//    @Module           :    NFChunkPool
//
// -------------------------------------------------------------------------

#include "NFChunkPool.h"

ChunkPool::ChunkPool(uint32_t reserve_size,
                     uint32_t chunk_size,
                     uint32_t chunk_count,
                     bool free_to_sys)
        : block_list_(),
          empty_list_(),
          full_list_()
{
    reserve_size_ = reserve_size;
    free_count_   = 0;
    chunk_size_   = (chunk_size < sizeof(void*)) ? sizeof(void*) : chunk_size;
    chunk_count_  = (chunk_count < 2) ? 2 : chunk_count;
    free_to_sys_  = free_to_sys;
    free_threshold_ = (chunk_count_ * 2);
    mem_size_ = (size_t)(chunk_size_ + reserve_size_) * chunk_count_;
}

ChunkPool::~ChunkPool()
{
    FreeBlockList(block_list_);
    FreeBlockList(full_list_);
    FreeBlockList(empty_list_);
}

void* ChunkPool::AllocChunk()
{
    void*     chunk = NULL;
    MemBlock* block = NULL;
    if (!block_list_.IsEmpty())
    {
        block = reinterpret_cast<MemBlock*>(block_list_.Head()->GetHost());
        chunk = AllocChunk(block);
        NF_ASSERT(chunk);
        if (block->free_num == 0)
        {
            block_list_.Delete(&block->block_list);
            full_list_.InsertHead(&block->block_list);
        }
    }
    else if (!empty_list_.IsEmpty())
    {
        block = reinterpret_cast<MemBlock*>(empty_list_.Head()->GetHost());
        chunk = AllocChunk(block);
        NF_ASSERT(chunk);
        empty_list_.Delete(&block->block_list);
        block_list_.InsertHead(&block->block_list);
    }
    else
    {
        block = AllocBlock();
        if (block)
        {
            chunk = AllocChunk(block);
            NF_ASSERT(chunk);
            block_list_.InsertHead(&block->block_list);
        }
    }
    if (chunk)
    {
        free_count_--;
    }
    return chunk;
}

bool ChunkPool::FreeChunk(void* chunk)
{
    DoubleNode* curr;
    curr = block_list_.Head();
    while (curr)
    {
        MemBlock* block = reinterpret_cast<MemBlock*>(curr->GetHost());
        if (FreeChunk(block, chunk))
        {
            free_count_++;
            if (unlikely(block->free_num == chunk_count_))
            {
                if (free_to_sys_ && (free_count_ > free_threshold_))
                {
                    // free one block to system
                    block_list_.Delete(curr);
                    free(block);
                    free_count_ -= chunk_count_;
                }
                else
                {
                    block_list_.Delete(curr);
                    empty_list_.InsertHead(curr);
                }
            }
            return true;
        }
        else
        {
            curr = block_list_.Next(curr);
        }
    }
    curr = full_list_.Head();
    while (curr)
    {
        MemBlock* block = reinterpret_cast<MemBlock*>(curr->GetHost());
        if (FreeChunk(block, chunk))
        {
            free_count_++;
            full_list_.Delete(curr);
            block_list_.InsertHead(curr);
            return true;
        }
        else
        {
            curr = full_list_.Next(curr);
        }
    }
    return false;
}

MemBlock* ChunkPool::AllocBlock()
{
    void* ptr = malloc(mem_size_ + sizeof(MemBlock));
    MemBlock* block = reinterpret_cast<MemBlock*>(ptr);
    if (block)
    {
        block->free_idx   = 0;
        block->free_list  = NULL;
        block->free_num   = chunk_count_;
        block->block_list.Reset();
        block->block_list.SetHost(block);
        free_count_      += chunk_count_;
    }
    return block;
}

void* ChunkPool::AllocChunk(MemBlock* block)
{
    NF_ASSERT(block);
    void* chunk = NULL;
    char* start = (reinterpret_cast<char*>(block)) + sizeof(MemBlock);
    // free list first
    if (block->free_list)
    {
        chunk = block->free_list;
        block->free_list = NextOf(block->free_list);
    }
        // unused chunk
    else if (block->free_idx < chunk_count_)
    {
        chunk = (start + block->free_idx * (chunk_size_+reserve_size_));
        block->free_idx++;
    }
    else
    {
        chunk = NULL;
    }
    if (chunk)
    {
        NF_ASSERT(block->free_num > 0);
        block->free_num--;
    }
    return chunk;
}

bool ChunkPool::FreeChunk(MemBlock* block, void* chunk)
{
    NF_ASSERT(block);
    NF_ASSERT(chunk);
    size_t pos   = reinterpret_cast<size_t>(chunk);
    size_t start = reinterpret_cast<size_t>(block) + sizeof(MemBlock);
    if ((pos < start) || (pos > (start + mem_size_ - chunk_size_ - reserve_size_)))
    {
        return false;
    }
    NextOf(chunk) = block->free_list;
    block->free_list  = chunk;
    block->free_num++;
    NF_ASSERT(block->free_num <= chunk_count_);
    return true;
}

void ChunkPool::FreeBlockList(DoubleList& list)
{
    DoubleNode* curr  = NULL;
    MemBlock*   block = NULL;
    curr = list.Head();
    while (curr)
    {
        block = reinterpret_cast<MemBlock*>(curr->GetHost());
        curr = list.Next(curr);
        free(block);
    }
}

void*& ChunkPool::NextOf(void* const chunk)
{
    return *(static_cast<void**>(chunk));
}
