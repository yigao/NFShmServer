// -------------------------------------------------------------------------
//    @FileName         :    NFCoroutineSchedule.cpp
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFPluginModule
//
// -------------------------------------------------------------------------

#include "NFCoroutineTask.h"
#include "NFComm/NFPluginModule/NFICoroutineModule.h"


NFCoroutineTask::NFCoroutineTask(NFIPluginManager *pPluginManager) : NFObject(pPluginManager), id_(-1) {

}

NFCoroutineTask::~NFCoroutineTask() {
    FindModule<NFICoroutineModule>()->DeleteTask(this);
}

int64_t NFCoroutineTask::Start(bool is_immediately) {
    return FindModule<NFICoroutineModule>()->Start(this, is_immediately);
}

int32_t NFCoroutineTask::Yield(int32_t timeout_ms) {
    return FindModule<NFICoroutineModule>()->Yield(timeout_ms);
}





