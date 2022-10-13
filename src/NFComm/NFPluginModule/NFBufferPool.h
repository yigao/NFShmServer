// -------------------------------------------------------------------------
//    @FileName         :    NFBufferPool.h
//    @Author           :    gaoyi
//    @Date             :    2022/10/10
//    @Email			:    445267987@qq.com
//    @Module           :    NFBufferPool
//
// -------------------------------------------------------------------------

#pragma once

#include "NFComm/NFCore/NFPlatform.h"
#include "NFComm/NFPluginModule/NFChunkPool.h"
#include "NFComm/NFCore/NFSingleton.hpp"

#ifdef _MSC_VER
#pragma warning(disable : 4201)
#endif

class BufferPool
{
public:
    explicit BufferPool(uint32_t block_size = 1024*1024,
                        uint32_t max_size   = 32*1024);
    ~BufferPool();

    void* Alloc(size_t size);
    void* Realloc(void* ptr, size_t size);
    void  Free(void* ptr);

public:
    void* AllocTrack(size_t size,
                     const char* file,
                     const char* func,
                     uint32_t line);
    void* ReallocTrack(void* ptr,
                       size_t size,
                       const char* file,
                       const char* func,
                       uint32_t line);
    void  FreeTrack(void* ptr);

private:
    void   AllocChunkPool();
    void   ReleaseChunkPool();
    size_t GetBufferLength(void* ptr);

public:
    typedef uint16_t IndexType;

private:
    IndexType   array_num_;
    size_t      max_size_;
    uint32_t    block_size_;
    NFChunkPool** mini_mem_alloc_;
};

#ifdef CHECK_MEM_LEAK
#define  MallocBuf(SIZET)         AllocTrack(SIZET, __FILE__, __FUNCTION__, __LINE__)
#define  ReallocBuf(PTRT, SIZET)  ReallocTrack(PTRT, SIZET, __FILE__, __FUNCTION__, __LINE__)
#define  FreeBuf                  FreeTrack
#else
#define  MallocBuf(SIZET)         Alloc(SIZET)
#define  ReallocBuf(PTRT, SIZET)  Realloc(PTRT, SIZET)
#define  FreeBuf                  Free
#endif  // CHECK_MEM_LEAK


