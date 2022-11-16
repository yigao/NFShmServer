// -------------------------------------------------------------------------
//    @FileName         :    NFITimerEventModule.cpp
//    @Author           :    gaoyi
//    @Date             :    22-11-15
//    @Email			:    445267987@qq.com
//    @Module           :    NFITimerEventModule
//
// -------------------------------------------------------------------------

#include "NFITimerEventModule.h"
#include "NFIEventModule.h"
#include "NFITimerModule.h"
#include "NFComm/NFShmCore/NFISharedMemModule.h"

NFITimerEventModule::NFITimerEventModule(NFIPluginManager* pPluginManager):NFIModule(pPluginManager)
{

}

NFITimerEventModule::~NFITimerEventModule()
{
    UnSubscribeAll();
    m_pObjPluginManager->FindModule<NFITimerModule>()->KillAllTimer(this);
}

//发送执行事件
void NFITimerEventModule::FireExecute(uint32_t nEventID, uint64_t nSrcID, uint32_t bySrcType, const google::protobuf::Message& message)
{
    m_pObjPluginManager->FindModule<NFIEventModule>()->FireExecute(nEventID, nSrcID, bySrcType, message);

    auto pModule = m_pObjPluginManager->FindModule<NFISharedMemModule>();
    if (pModule)
    {
        pModule->FireExecute(nEventID, nSrcID, bySrcType, message);
    }
}

//订阅执行事件
bool NFITimerEventModule::Subscribe(uint32_t nEventID, uint64_t nSrcID, uint32_t bySrcType, const std::string& desc)
{
    return m_pObjPluginManager->FindModule<NFIEventModule>()->Subscribe(this, nEventID, nSrcID, bySrcType, desc);
}

//取消订阅执行事件
bool NFITimerEventModule::UnSubscribe(uint32_t nEventID, uint64_t nSrcID, uint32_t bySrcType)
{
    return m_pObjPluginManager->FindModule<NFIEventModule>()->UnSubscribe(this, nEventID, nSrcID, bySrcType);
}

//取消所有执行事件的订阅
bool NFITimerEventModule::UnSubscribeAll()
{
    return m_pObjPluginManager->FindModule<NFIEventModule>()->UnSubscribeAll(this);
}

//设置定时器
bool NFITimerEventModule::SetTimer(uint32_t nTimerID, uint64_t nInterVal, uint32_t nCallCount)
{
    return m_pObjPluginManager->FindModule<NFITimerModule>()->SetTimer(nTimerID, nInterVal, this, nCallCount);
}

//关闭定时器
bool NFITimerEventModule::KillTimer(uint32_t nTimerID)
{
    return m_pObjPluginManager->FindModule<NFITimerModule>()->KillTimer(nTimerID, this);
}

//关闭所有定时器
bool NFITimerEventModule::KillAllTimer()
{
    return m_pObjPluginManager->FindModule<NFITimerModule>()->KillAllTimer(this);
}

//设置固定时间的定时器
bool NFITimerEventModule::SetFixTimer(uint32_t nTimerID, uint64_t nStartTime, uint32_t nInterSec, uint32_t nCallCount)
{
    return m_pObjPluginManager->FindModule<NFITimerModule>()->SetClocker(nTimerID, nStartTime, nInterSec, this, nCallCount);
}