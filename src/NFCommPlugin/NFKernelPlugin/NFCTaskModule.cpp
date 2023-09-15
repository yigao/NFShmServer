// -------------------------------------------------------------------------
//    @FileName         :    NFCTaskModule.cpp
//    @Author           :    Gao.Yi
//    @Date             :   2022-09-18
//    @Email			:    445267987@qq.com
//    @Module           :    NFActorPlugin
//
// -------------------------------------------------------------------------

#include "NFCTaskModule.h"
#include "NFComm/NFCore/NFPlatform.h"
#include "NFComm/NFPluginModule/NFTask.h"
#include "NFComm/NFPluginModule/NFLogMgr.h"
#include "NFComm/NFPluginModule/NFCheck.h"
#include "NFComm/NFPluginModule/NFITaskComponent.h"
#include "NFComm/NFCore/NFDateTime.hpp"
#include "NFTaskGroup.h"

NFCTaskModule::NFCTaskModule(NFIPluginManager* p):NFITaskModule(p)
{
}

NFCTaskModule::~NFCTaskModule()
{
    for(int i = 0; i < (int)m_taskGroups.size(); i++)
    {
        if (m_taskGroups[i])
        {
            delete m_taskGroups[i];
        }
    }
}

bool NFCTaskModule::Awake()
{
	return true;
}

bool NFCTaskModule::Init()
{
	return true;
}

bool NFCTaskModule::BeforeShut()
{
	return true;
}

bool NFCTaskModule::Shut()
{
    for(int i = 0; i < (int)m_taskGroups.size(); i++)
    {
        m_taskGroups[i]->Shut();
    }
	return true;
}

bool NFCTaskModule::Finalize()
{
    for(int i = 0; i < (int)m_taskGroups.size(); i++)
    {
        m_taskGroups[i]->Finalize();
    }
    return true;
}

bool NFCTaskModule::Execute()
{
    for(int i = 0; i < (int)m_taskGroups.size(); i++)
    {
        m_taskGroups[i]->Execute();
    }
    return true;
}

/**
* @brief 初始化actor系统, 配置线程个数
*
* @param thread_num	线程数目，至少为1
* @return < 0 : Failed
*/
int NFCTaskModule::InitActorThread(int actorGroup, int thread_num, int yieldstrategy)
{
    if (actorGroup > (int)m_taskGroups.size())
    {
        m_taskGroups.resize(actorGroup);
    }

    for(int i = 0; i < (int)m_taskGroups.size(); i++)
    {
        if (m_taskGroups[i] == NULL)
        {
            m_taskGroups[i] = new NFTaskGroup(m_pObjPluginManager);
            m_taskGroups[i]->InitActorThread(thread_num, yieldstrategy);
        }
    }

    return 0;
}

/**
* @brief 向系统请求请求一个actor
*
* @return 返回actor的唯一索引
*/
int NFCTaskModule::RequireActor(int actorGroup)
{
    CHECK_EXPR(actorGroup >= 0 && actorGroup < (int)m_taskGroups.size() && m_taskGroups[actorGroup], -1, "actorGroup:{} not exist", actorGroup);
	return m_taskGroups[actorGroup]->RequireActor();
}

/**
* @brief 通过自己保存的actorIndex将发送数据给actor线程
*
* @param nActorIndex	actor唯一索引
* @param pData			要发送的数据
* @return 是否成功
*/
int NFCTaskModule::SendMsgToActor(int actorGroup, const int nActorIndex, NFTask* pData)
{
    CHECK_EXPR(actorGroup >= 0 && actorGroup < (int)m_taskGroups.size() && m_taskGroups[actorGroup], -1, "actorGroup:{} not exist", actorGroup);
    CHECK_NULL(m_taskGroups[actorGroup]);
    CHECK_NULL(pData);
    pData->m_runActorGroup = actorGroup;
    pData->m_nextActorGroup = actorGroup;
    return m_taskGroups[actorGroup]->SendMsgToActor(nActorIndex, pData);
}

/**
* @brief 主线程通过自己保存的actorIndex将发送数据给actor线程
*
* @param nActorIndex	actor唯一索引
* @param pData			要发送的数据
* @return 是否成功
*/
int NFCTaskModule::SendMsgToActor(int actorGroup, NFTaskActor* pActor, NFTask* pData)
{
    CHECK_EXPR(actorGroup >= 0 && actorGroup < (int)m_taskGroups.size() && m_taskGroups[actorGroup], -1, "actorGroup:{} not exist", actorGroup);
    CHECK_NULL(m_taskGroups[actorGroup]);
    CHECK_NULL(pActor);
    CHECK_NULL(pData);
    pData->m_runActorGroup = actorGroup;
    pData->m_nextActorGroup = actorGroup;
    return m_taskGroups[actorGroup]->SendMsgToActor(pActor, pData);
}

/**
* @brief 释放actor资源
*
* @return
*/
void NFCTaskModule::ReleaseActor()
{
    for(int i = 0; i < (int)m_taskGroups.size(); i++)
    {
        m_taskGroups[i]->ReleaseActor();
    }
}

/**
* @brief 通过actorIndex获得一个actor
*
* @param nActorIndex	actor索引地址
* @return 返回获得的actor, 若没有，为NULL
*/
NFTaskActor* NFCTaskModule::GetActor(int actorGroup, const int nActorIndex)
{
    CHECK_EXPR(actorGroup >= 0 && actorGroup < (int)m_taskGroups.size() && m_taskGroups[actorGroup], NULL, "actorGroup:{} not exist", actorGroup);
    return m_taskGroups[actorGroup]->GetActor(nActorIndex);
}

/**
* @brief 添加一个Actor组件
*
* @return
*/
int NFCTaskModule::AddActorComponent(int actorGroup, const int nActorIndex, NFITaskComponent* pComonnet)
{
    CHECK_EXPR(actorGroup >= 0 && actorGroup < (int)m_taskGroups.size(), -1, "actorGroup:{} not exist", actorGroup);
    CHECK_NULL(pComonnet);
    CHECK_NULL(m_taskGroups[actorGroup]);
    return m_taskGroups[actorGroup]->AddActorComponent(nActorIndex, pComonnet);
}

/**
* @brief 获得所有component
*
* @param
* @return
*/
NFITaskComponent* NFCTaskModule::GetTaskComponent(int actorGroup, int nActorIndex)
{
    CHECK_EXPR(actorGroup >= 0 && actorGroup < (int)m_taskGroups.size(), NULL, "actorGroup:{} not exist", actorGroup);
    CHECK_EXPR(m_taskGroups[actorGroup], NULL, "");
    return m_taskGroups[actorGroup]->GetTaskComponent(nActorIndex);
}

int NFCTaskModule::GetNumQueuedMessages()
{
	int count = 0;
    for(int i = 0; i < (int)m_taskGroups.size(); i++)
    {
        count += m_taskGroups[i]->GetNumQueuedMessages();
    }
	return count;
}

int NFCTaskModule::CloseActorPool()
{
    for(int i = 0; i < (int)m_taskGroups.size(); i++)
    {
        m_taskGroups[i]->CloseActorPool();
    }
	return 0;
}

int NFCTaskModule::AddTask(int actorGroup, NFTask* pTask)
{
    CHECK_EXPR(actorGroup >= 0 && actorGroup < (int)m_taskGroups.size(), -1, "actorGroup:{} not exist", actorGroup);
    CHECK_NULL(pTask);
    CHECK_NULL(m_taskGroups[actorGroup]);
    pTask->m_runActorGroup = actorGroup;
    pTask->m_nextActorGroup = actorGroup;
    return m_taskGroups[actorGroup]->AddTask(pTask);
}

int NFCTaskModule::AddTask(int actorGroup, int actorId, NFTask* pTask)
{
    CHECK_EXPR(actorGroup >= 0 && actorGroup < (int)m_taskGroups.size(), -1, "actorGroup:{} not exist", actorGroup);
    CHECK_NULL(pTask);
    CHECK_NULL(m_taskGroups[actorGroup]);
    pTask->m_runActorGroup = actorGroup;
    pTask->m_nextActorGroup = actorGroup;
    return m_taskGroups[actorGroup]->AddTask(actorId, pTask);
}

/**
* @brief 获得最大Actor Thread Num
*
* @return
*/
int NFCTaskModule::GetMaxThreads(int actorGroup)
{
    CHECK_EXPR(actorGroup >= 0 && actorGroup < (int)m_taskGroups.size() && m_taskGroups[actorGroup], 0, "actorGroup:{} not exist", actorGroup);
    return m_taskGroups[actorGroup]->GetMaxThreads();
}

int NFCTaskModule::GetBalanceActor(int actorGroup, uint64_t balanceId)
{
    CHECK_EXPR(actorGroup >= 0 && actorGroup < (int)m_taskGroups.size() && m_taskGroups[actorGroup], -1, "actorGroup:{} not exist", actorGroup);
    return m_taskGroups[actorGroup]->GetBalanceActor(balanceId);
}

int NFCTaskModule::GetRandActor(int actorGroup)
{
    CHECK_EXPR(actorGroup >= 0 && actorGroup < (int)m_taskGroups.size() && m_taskGroups[actorGroup], -1, "actorGroup:{} not exist", actorGroup);
    return m_taskGroups[actorGroup]->GetRandActor();
}

/**
* @brief 获取所有ActorId
*
* @return
*/
std::vector<int> NFCTaskModule::GetAllActorId(int actorGroup) const
{
    CHECK_EXPR(actorGroup >= 0 && actorGroup < (int)m_taskGroups.size() && m_taskGroups[actorGroup], std::vector<int>(), "actorGroup:{} not exist", actorGroup);
    return m_taskGroups[actorGroup]->GetAllActorId();
}

