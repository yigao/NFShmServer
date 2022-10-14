// -------------------------------------------------------------------------
//    @FileName         :    NFNFObjectPool.h
//    @Author           :    gaoyi
//    @Date             :    2022/10/10
//    @Email			:    445267987@qq.com
//    @Module           :    NFNFObjectPool
//
// -------------------------------------------------------------------------

#pragma once

#include "NFChunkPool.h"
#include "NFMemTracker.h"

template<class TYPE>
class NFObjectPool : public NFChunkPool
{
public:
    NFObjectPool(uint32_t count_in_block = 0, bool auto_free = true);

    virtual ~NFObjectPool();

    TYPE *Alloc();

    bool Free(TYPE *obj);

    template<class U, class... Args>
    void Construct(U *p, Args &&... args);

public:
    template<class... Args>
    TYPE *AllocTrack(const char *file,
                     const char *func,
                     uint32_t line, Args &&... args);

    bool FreeTrack(TYPE *obj);

    uint32_t MemSize()
    {
        return mem_size_;
    }
};

#ifdef CHECK_MEM_LEAK
#define  MallocObj()        AllocTrack(__FILE__, __FUNCTION__, __LINE__)
#define  MallocObjWithArgs(...)        AllocTrack(__FILE__, __FUNCTION__, __LINE__, ##__VA_ARGS__)
#define  FreeObj            FreeTrack
#else
#define  MallocObj()        Alloc()
#define  FreeObj            Free
#endif  // CHECK_MEM_LEAK

template<class TYPE>
inline
NFObjectPool<TYPE>::NFObjectPool(uint32_t count_in_block,
                             bool auto_free /*= true*/)
        :NFChunkPool(0, sizeof(TYPE), count_in_block, auto_free)
{

}

template<class TYPE>
inline NFObjectPool<TYPE>::~NFObjectPool(void) {}

template<class TYPE>
inline TYPE *NFObjectPool<TYPE>::Alloc()
{
    TYPE *obj = (TYPE *) AllocChunk();
    if (obj)
    {
        new(obj) TYPE();
    }
    return obj;
}

template<class TYPE>
inline bool NFObjectPool<TYPE>::Free(TYPE *obj)
{
    MMO_ASSERT(obj);
    obj->~TYPE();
    return FreeChunk(obj);
}

template<typename T>
template<class U, class... Args>
inline void
NFObjectPool<T>::Construct(U *p, Args &&... args)
{
    new(p) U(std::forward<Args>(args)...);
}

template<class TYPE>
template<class... Args>
inline TYPE *NFObjectPool<TYPE>::AllocTrack(const char *file,
                                          const char *func,
                                          uint32_t line, Args &&... args)
{
    TYPE *obj = (TYPE *) AllocChunk();
    if (obj)
    {
        Construct<TYPE>(obj, std::forward<Args>(args)...);
        NFMemTracker::Instance()->TrackMalloc(obj, file, func, line);
    }
    return obj;
}

template<class TYPE>
inline bool NFObjectPool<TYPE>::FreeTrack(TYPE *obj)
{
    NF_ASSERT(obj);
    obj->~TYPE();
    NFMemTracker::Instance()->TrackFree(obj);
    return FreeChunk(obj);
}



