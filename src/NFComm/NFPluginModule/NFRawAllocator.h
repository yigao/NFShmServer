// -------------------------------------------------------------------------
//    @FileName         :    NFRawAllocator.h
//    @Author           :    gaoyi
//    @Date             :    2022/10/10
//    @Email			:    445267987@qq.com
//    @Module           :    NFRawAllocator
//
// -------------------------------------------------------------------------

#pragma once

#include "NFComm/NFCore/NFPlatform.h"
#include "NFComm/NFCore/NFSingleton.hpp"

class NFRawAllocator : public NFSingleton<NFRawAllocator>
{
public:
    NFRawAllocator();
    ~NFRawAllocator();

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

