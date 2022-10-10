// -------------------------------------------------------------------------
//    @FileName         :    NFObjectPool.h
//    @Author           :    gaoyi
//    @Date             :    2022/10/10
//    @Email			:    445267987@qq.com
//    @Module           :    NFObjectPool
//
// -------------------------------------------------------------------------

#pragma once

#include "NFChunkPool.h"
#include "NFMemTracker.h"

template<class TYPE>
class ObjectPool : private ChunkPool
{
public:
    ObjectPool(uint32_t count_in_block = 0, bool auto_free = true);
    virtual ~ObjectPool();

    TYPE* Alloc();
    bool  Free(TYPE* obj);
public:
    TYPE* AllocTrack(const char* file,
                     const char* func,
                     uint32_t line);
    bool  FreeTrack(TYPE* obj);

    uint32_t MemSize()
    {
        return mem_size_;
    }
};

#ifdef CHECK_MEM_LEAK
#define  MallocObj()        AllocTrack(__FILE__, __FUNCTION__, __LINE__)
#define  FreeObj            FreeTrack
#else
#define  MallocObj()        Alloc()
#define  FreeObj            Free
#endif  // CHECK_MEM_LEAK

template<class TYPE> inline
ObjectPool<TYPE>::ObjectPool(uint32_t count_in_block,
                             bool auto_free /*= true*/)
        :ChunkPool(0, sizeof(TYPE), count_in_block, auto_free) {}

template<class TYPE> inline ObjectPool<TYPE>::~ObjectPool(void)
{}

template<class TYPE> inline TYPE* ObjectPool<TYPE>::Alloc()
{
    TYPE* obj = (TYPE*)AllocChunk();
    if (obj)
    {
        new (obj) TYPE();
    }
    return obj;
}

template<class TYPE> inline bool ObjectPool<TYPE>::Free(TYPE* obj)
{
    MMO_ASSERT(obj);
    obj->~TYPE();
    return FreeChunk(obj);
}

template<class TYPE> inline TYPE* ObjectPool<TYPE>::AllocTrack(const char* file,
                                                               const char* func,
                                                               uint32_t line)
{
    TYPE* obj = (TYPE*)AllocChunk();
    if (obj)
    {
        new (obj) TYPE();
        g_MemTracker().TrackMalloc(obj, file, func, line);
    }
    return obj;
}

template<class TYPE> inline bool ObjectPool<TYPE>::FreeTrack(TYPE* obj)
{
    MMO_ASSERT(obj);
    obj->~TYPE();
    g_MemTracker().TrackFree(obj);
    return FreeChunk(obj);
}



