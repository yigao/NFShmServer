// -------------------------------------------------------------------------
//    @FileName         :    NFRawAllocator.cpp
//    @Author           :    gaoyi
//    @Date             :    2022/10/10
//    @Email			:    445267987@qq.com
//    @Module           :    NFRawAllocator
//
// -------------------------------------------------------------------------

#include "NFRawAllocator.h"
#include "NFMemTracker.h"

RawAllocator::RawAllocator()
{}

RawAllocator::~RawAllocator()
{}

void* RawAllocator::Alloc(size_t size)
{
    return malloc(size);
}

void* RawAllocator::Realloc(void* ptr, size_t size)
{
    return realloc(ptr, size);
}

void  RawAllocator::Free(void* ptr)
{
    free(ptr);
}

void* RawAllocator::AllocTrack(size_t size,
                               const char* file,
                               const char* func,
                               uint32_t line)
{
    void* ret = NULL;
    ret = Alloc(size);

    if (ret)
    {
        MemTracker::Instance()->TrackMalloc(ret, file, func, line);
    }
    return ret;
}

void* RawAllocator::ReallocTrack(void* ptr,
                                 size_t size,
                                 const char* file,
                                 const char* func,
                                 uint32_t line)
{
    if (ptr == NULL)
    {
        return AllocTrack(size, file, func, line);
    }
    void* ret = realloc(ptr, size);
    if (ret != NULL && ret != ptr)
    {
        MemTracker::Instance()->TrackFree(ptr);
        MemTracker::Instance()->TrackMalloc(ret, file, func, line);
    }
    return ret;
}

void RawAllocator::FreeTrack(void* ptr)
{
    assert(ptr != NULL);
    MemTracker::Instance()->TrackFree(ptr);
    free(ptr);
}
