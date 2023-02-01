// -------------------------------------------------------------------------
//    @FileName         :    NFMemTracker.cpp
//    @Author           :    gaoyi
//    @Date             :    2022/10/10
//    @Email			:    445267987@qq.com
//    @Module           :    NFMemTracker
//
// -------------------------------------------------------------------------

#include <NFComm/NFCore/NFLock.h>
#include <NFComm/NFCore/NFTime.h>
#include "NFMemTracker.h"
#include "NFComm/NFPluginModule/NFLogMgr.h"
#include "NFComm/NFCore/NFFileUtility.h"
#include "NFComm/NFPluginModule/NFCheck.h"

NFTrackData::NFTrackData(uint32_t line_no,
                         const char* file_name,
                         const char* func_name)
{
    line_no_   = line_no;
    file_name_ = std::string(file_name);
    func_name_ = std::string(func_name);
}

NFMemTracker::NFMemTracker() {}

NFMemTracker::~NFMemTracker() {}

bool NFMemTracker::TrackMalloc(void* ptr,
                               const char* file_path,
                               const char* func_name,
                               uint32_t line_no)
{
    NF_ASSERT(ptr != NULL);
    if (ptr == NULL)
    {
        return false;
    }
    std::string file_name = NFFileUtility::GetFileName(file_path);
    NFLock temp_lock(mutex_lock_);

    if (ptr_track_map_.find(ptr) != ptr_track_map_.end())
    {
        NF_ASSERT(false);
        return false;
    }
    ptr_track_map_.insert(
            PtrTrackMap::value_type(ptr, NFTrackData(line_no, file_name.c_str(), func_name)));
    return true;
}

void NFMemTracker::TrackFree(void* ptr)
{
    NF_ASSERT(ptr != NULL);
    if (ptr == NULL)
    {
        return;
    }
    NFLock temp_lock(mutex_lock_);
    size_t num = ptr_track_map_.erase(ptr);
    if (num != 1)
    {
        NFLogError(NF_LOG_SYSTEMLOG, 0, "error, num:%lu\n", num);
    }
    NF_ASSERT(num == 1);
}

void NFMemTracker::PrintMemLink(const std::string& output_filename)
{
    NFLock temp_lock(mutex_lock_);
    std::string content;
    if (!output_filename.empty())
    {
        char DateTiemBuf[64];
        NFTime::Now().LocalDateTime(DateTiemBuf, sizeof(DateTiemBuf));
        std::string contentHead = std::string("---------------------")
                                  + DateTiemBuf
                                  + std::string("---------------------\n");
        content += contentHead;
    }
    if (ptr_track_map_.empty())
    {
        std::string no_link_mem("OK, No Memory Link\n");
        content += no_link_mem;
        NFLogInfo(NF_LOG_SYSTEMLOG, 0, no_link_mem.c_str());
    }
    else
    {

        PtrTrackMap::iterator iter = ptr_track_map_.begin();
        PtrTrackMap::iterator iterEnd = ptr_track_map_.end();
        for (; iter != iterEnd; ++iter)
        {
            NFTrackData& trackData = iter->second;
            std::string temp = NF_FORMAT("{}({}) {} link memory\n", trackData.file_name_.c_str(), trackData.line_no_, trackData.func_name_.c_str());
            content += temp;
            NFLogError(NF_LOG_SYSTEMLOG, 0, "{}", temp);
        }
    }

    if (!output_filename.empty())
    {
        NFFileUtility::AWriteFile(output_filename, content);
    }
}