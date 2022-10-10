// -------------------------------------------------------------------------
//    @FileName         :    NFMemTracker.h
//    @Author           :    gaoyi
//    @Date             :    2022/10/10
//    @Email			:    445267987@qq.com
//    @Module           :    NFMemTracker
//
// -------------------------------------------------------------------------

#pragma once

#include "NFComm/NFCore/NFPlatform.h"
#include "NFComm/NFCore/NFMutex.h"
#include "NFComm/NFCore/NFSingleton.hpp"
#include <unordered_map>

struct TrackData
{
    uint32_t line_no_;
    std::string file_name_;
    std::string func_name_;

    TrackData(uint32_t line_no,
              const char *file_name,
              const char *func_name);
};

class MemTracker : public NFSingleton<MemTracker>
{
public:
    void PrintMemLink(const std::string& output_filename);

    bool TrackMalloc(void *ptr, const char *file_path, const char *func_num, uint32_t line_no);

    void TrackFree(void *ptr);

protected:
    typedef NFMutex TMutexLock;
    typedef std::unordered_map<void *, TrackData> PtrTrackMap;

    TMutexLock mutex_lock_;
    PtrTrackMap ptr_track_map_;

public:
    MemTracker();
    virtual ~MemTracker();
};


