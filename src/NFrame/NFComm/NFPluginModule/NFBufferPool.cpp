// -------------------------------------------------------------------------
//    @FileName         :    NFBufferPool.cpp
//    @Author           :    gaoyi
//    @Date             :    2022/10/10
//    @Email			:    445267987@qq.com
//    @Module           :    NFBufferPool
//
// -------------------------------------------------------------------------

#include "NFBufferPool.h"
#include "NFMemTracker.h"
#include "NFCheck.h"

namespace
{
    static const size_t STEP_32B_SIZE_MAX   = 256;   // slot_num=8
    static const size_t STEP_64B_SIZE_MAX   = 1024;  // slot_num=12
    static const size_t STEP_128B_SIZE_MAX  = 2048;  // slot_num=8
    static const size_t STEP_256B_SIZE_MAX  = 4096;  // slot_num=8
    static const size_t EXT_SIZE_BYTE = sizeof(NFBufferPool::IndexType);
    static const NFBufferPool::IndexType INVALID_MAX_INDEX = 0xFFFF;
}

NFBufferPool::NFBufferPool(uint32_t block_size, uint32_t max_size /*= 4096*/)
        : array_num_(0),
          max_size_(max_size),
          block_size_(block_size),
          mini_mem_alloc_(NULL)
{
    AllocChunkPool();
}

NFBufferPool::~NFBufferPool()
{
    ReleaseChunkPool();
}

NFBufferPool::IndexType GetArrayIdx(size_t size)
{
    NFBufferPool::IndexType idx = 0;
    if (size <= STEP_32B_SIZE_MAX)
    {
        idx = (NFBufferPool::IndexType)((size - 1) / 32);
    }
    else if (size <= STEP_64B_SIZE_MAX)
    {
        idx = GetArrayIdx(STEP_32B_SIZE_MAX) + 1;
        idx += (NFBufferPool::IndexType)((size - STEP_32B_SIZE_MAX - 1) / 64);
    }
    else if (size <= STEP_128B_SIZE_MAX)
    {
        idx = GetArrayIdx(STEP_64B_SIZE_MAX) + 1;
        idx += (NFBufferPool::IndexType)((size - STEP_64B_SIZE_MAX - 1) / 128);
    }
    else if (size <= STEP_256B_SIZE_MAX)
    {
        idx = GetArrayIdx(STEP_128B_SIZE_MAX) + 1;
        idx += (NFBufferPool::IndexType)((size - STEP_128B_SIZE_MAX - 1) / 256);
    }
    else
    {
        idx = GetArrayIdx(STEP_256B_SIZE_MAX) + 1;
        idx += (NFBufferPool::IndexType)((size - STEP_256B_SIZE_MAX - 1) / 512);
    }
    return idx;
}

void NFBufferPool::ReleaseChunkPool()
{
    if (mini_mem_alloc_)
    {
        for (IndexType i = 0; i < array_num_; i++)
        {
            delete mini_mem_alloc_[i];
        }
        delete [] mini_mem_alloc_;
    }
}

size_t NFBufferPool::GetBufferLength(void* ptr)
{
    IndexType* buf_idx = static_cast<IndexType*>(ptr);
    IndexType  idx = *(--buf_idx);
    if (idx < array_num_)
    {
        return mini_mem_alloc_[idx]->ChunkSize();
    }
    else
    {
        size_t* buf_len = reinterpret_cast<size_t*>(buf_idx);
        return *(--buf_len);
    }
}

void NFBufferPool::AllocChunkPool()
{
    array_num_ = GetArrayIdx(max_size_) + 1;
    mini_mem_alloc_ = new NFChunkPool*[array_num_];
    uint32_t chunk_size = 0;
    uint32_t chunk_count = 0;
    for (IndexType i = 0; i < array_num_; i++)
    {
        if (chunk_size < STEP_32B_SIZE_MAX)
        {
            chunk_size += 32;
        }
        else if (chunk_size < STEP_64B_SIZE_MAX)
        {
            chunk_size += 64;
        }
        else if (chunk_size < STEP_128B_SIZE_MAX)
        {
            chunk_size += 128;
        }
        else if (chunk_size < STEP_256B_SIZE_MAX)
        {
            chunk_size += 256;
        }
        else
        {
            chunk_size += 512;
        }
        chunk_count = block_size_/chunk_size;
        mini_mem_alloc_[i] = new NFChunkPool(EXT_SIZE_BYTE, chunk_size, chunk_count, true);
    }
}

void* NFBufferPool::Alloc(size_t size)
{
    size_t need_size = size;
    if (need_size > max_size_)
    {
        need_size += (sizeof(size_t) + EXT_SIZE_BYTE);
        size_t* buf_len = static_cast<size_t*>(malloc(need_size));
        *(buf_len) = size;
        IndexType* buf_idx = reinterpret_cast<IndexType*>(buf_len + 1);
        *(buf_idx) = INVALID_MAX_INDEX;
        return static_cast<void*>(buf_idx + 1);
    }
    else
    {
        IndexType idx = GetArrayIdx(need_size);
        NFChunkPool* chunk_pool = mini_mem_alloc_[idx];
        IndexType* all_buf = static_cast<IndexType*>(chunk_pool->AllocChunk());
        *(all_buf) = idx;
        return static_cast<void*>(all_buf + 1);
    }
}

void* NFBufferPool::Realloc(void* ptr, size_t size)
{
    if (ptr == NULL)
    {
        return Alloc(size);
    }
    size_t buf_len = GetBufferLength(ptr);
    if (buf_len >= size)
    {
        return ptr;
    }
    else
    {
        void* new_ptr = Alloc(size);
        if (new_ptr == NULL)
        {
            return NULL;
        }
        memcpy(new_ptr, ptr, buf_len);
        Free(ptr);
        return new_ptr;
    }
}

void NFBufferPool::Free(void* ptr)
{
    IndexType* all_buf = static_cast<IndexType*>(ptr);
    IndexType idx = *(--all_buf);
    if (idx == INVALID_MAX_INDEX)
    {
        size_t* buf_len = reinterpret_cast<size_t*>(all_buf);
        free(--buf_len);
    }
    else
    {
        NFChunkPool* chunk_pool = mini_mem_alloc_[idx];
        void* free_p = static_cast<void*>(all_buf);
        chunk_pool->FreeChunk(free_p);
    }
}

void* NFBufferPool::AllocTrack(size_t size,
                               const char* file,
                               const char* func,
                               uint32_t line)
{
    void* ret = Alloc(size);
    if (ret)
    {
        NFMemTracker::Instance()->TrackMalloc(ret, file, func, line);
    }
    return ret;
}

void* NFBufferPool::ReallocTrack(void* ptr,
                                 size_t size,
                                 const char* file,
                                 const char* func,
                                 uint32_t line)
{
    if (ptr == NULL)
    {
        return AllocTrack(size, file, func, line);
    }

    size_t buf_len = GetBufferLength(ptr);
    if (buf_len >= size)
    {
        return ptr;
    }
    else
    {
        void* new_ptr = AllocTrack(size, file, func, line);
        if (new_ptr == NULL)
        {
            return NULL;
        }
        memcpy(new_ptr, ptr, buf_len);
        FreeTrack(ptr);
        return new_ptr;
    }
}

void  NFBufferPool::FreeTrack(void* ptr)
{
    assert(ptr);
    NFMemTracker::Instance()->TrackFree(ptr);
    Free(ptr);
}