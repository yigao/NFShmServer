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

NFRawAllocator::NFRawAllocator()
{}

NFRawAllocator::~NFRawAllocator()
{}

void* NFRawAllocator::Alloc(size_t size)
{
    return malloc(size);
}

void* NFRawAllocator::Realloc(void* ptr, size_t size)
{
    return realloc(ptr, size);
}

void  NFRawAllocator::Free(void* ptr)
{
    free(ptr);
}

void* NFRawAllocator::AllocTrack(size_t size,
                                 const char* file,
                                 const char* func,
                                 uint32_t line)
{
    void* ret = NULL;
    ret = Alloc(size);

    if (ret)
    {
        NFMemTracker::Instance()->TrackMalloc(ret, file, func, line);
    }
    return ret;
}

void* NFRawAllocator::ReallocTrack(void* ptr,
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
        NFMemTracker::Instance()->TrackFree(ptr);
        NFMemTracker::Instance()->TrackMalloc(ret, file, func, line);
    }
    return ret;
}

void NFRawAllocator::FreeTrack(void* ptr)
{
    assert(ptr != NULL);
    NFMemTracker::Instance()->TrackFree(ptr);
    free(ptr);
}
