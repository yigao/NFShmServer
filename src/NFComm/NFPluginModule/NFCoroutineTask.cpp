// -------------------------------------------------------------------------
//    @FileName         :    NFCoroutineSchedule.cpp
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFPluginModule
//
// -------------------------------------------------------------------------

#include "NFCoroutineTask.h"
#include "NFCoMgr.h"


NFCoroutineTask::NFCoroutineTask() : id_(-1) {

}

NFCoroutineTask::~NFCoroutineTask() {
    NFCoMgr::Instance()->DeleteTask(this);
}

int64_t NFCoroutineTask::Start(bool is_immediately) {
    return NFCoMgr::Instance()->Start(this, is_immediately);
}

int32_t NFCoroutineTask::Yield(int32_t timeout_ms) {
    return NFCoMgr::Instance()->Yield(timeout_ms);
}





