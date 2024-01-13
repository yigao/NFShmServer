// -------------------------------------------------------------------------
//    @FileName         :    NFCTaskGroup.h
//    @Author           :    gaoyi
//    @Date             :    23-9-14
//    @Email			:    445267987@qq.com
//    @Module           :    NFCTaskGroup
//
// -------------------------------------------------------------------------

#pragma once

#include "NFComm/NFCore/NFPlatform.h"
#include "NFComm/NFCore/NFAtomic.h"
#include "NFComm/NFCore/NFQueue.hpp"
#include "NFComm/NFPluginModule/NFIModule.h"
#include <Theron/Theron.h>

class NFTask;
class NFTaskActor;
class NFITaskComponent;
class NFTaskActorMessage;
class NFTaskGroup : public NFIModule
{
public:
    NFTaskGroup(NFIPluginManager *p);

    virtual ~NFTaskGroup();
public:
    bool Awake() override;

    bool Init() override;

    bool BeforeShut() override;

    bool Shut() override;

    bool Finalize() override;

    bool Execute() override;
public:
    /**
    * @brief 初始化actor系统, 配置线程个数
    *
    * @param thread_num	线程数目，至少为1
    * @return < 0 : Failed
    */
    virtual int InitActorThread(int taskGroup, int thread_num, int yieldstrategy = 0);

    /**
    * @brief 向系统请求请求一个actor
    *
    * @return 返回actor的唯一索引
    */
    virtual int RequireActor();

    /**
    * @brief 添加一个Actor组件
    *
    * @return
    */
    virtual int AddActorComponent(int nActorIndex, NFITaskComponent* pComonnet);

    /**
    * @brief 获得所有component
    *
    * @param
    * @return
    */
    virtual NFITaskComponent* GetTaskComponent(int nActorIndex);

    /**
    * @brief 主线程通过自己保存的actorIndex将发送数据给actor线程
    *
    * @param nActorIndex	actor唯一索引
    * @param pData			要发送的数据
    * @return 是否成功
    */
    virtual int SendMsgToActor(int nActorIndex, NFTask* pData);

    /**
    * @brief 主线程通过自己保存的actorIndex将发送数据给actor线程
    *
    * @param nActorIndex	actor唯一索引
    * @param pData			要发送的数据
    * @return 是否成功
    */
    virtual int SendMsgToActor(NFTaskActor* pActor, NFTask* pData);

    /**
    * @brief 释放actor资源
    *
    * @return
    */
    virtual void ReleaseActor();

    /**
    * @brief 通过actorIndex获得一个actor
    *
    * @param nActorIndex	actor索引地址
    * @return 返回获得的actor, 若没有，为NULL
    */
    virtual NFTaskActor* GetActor(int nActorIndex);

    /**
    * @brief 获得系统还没有处理完的任务数目
    *
    * @return 未完成的任务数目
    */
    virtual int GetNumQueuedMessages();

    /**
    * @brief 释放申请的actor数据，关闭actor池
    *
    * @return 是否成功
    */
    virtual int CloseActorPool();

    /**
    * @brief 消息数据处理完后，如果有必要将数据返回给主线程，
    *		 在这个函数里，将消息数据推送给主线程，这个函数在actor线程中执行
    *
    * @param message	消息数据
    * @param from	发送消息的actor地址
    * @return 是否成功
    */
    virtual bool HandlerEx(const NFTaskActorMessage& message, int from);

    /**
    * @brief 通过任务的动态均衡id，获得actor
    *		 为了防止数据库错乱，防止同时对数据库表中的一条数据，读取写入，
    *		 使用动态均衡id, 使得在某个时候只有一条线程对表中的一条数据，读取或写入
    * @param balanceId 动态均衡id
    * @return	一个actor索引
    */
    int GetBalanceActor(uint64_t balanceId);

    /**
    * @brief 随机获得一个actor
    *
    * @return actor索引
    */
    int GetRandActor();

    /**
    * @brief 添加要异步处理的task
    *
    * @param pTask 要异步处理的task
    * @return
    */
    virtual int AddTask(NFTask* pTask);

    /**
    * @brief 添加要异步处理的task
    *
    * @param pTask 要异步处理的task
    * @return
    */
    virtual int AddTask(int actorId, NFTask* pTask);

    /**
    * @brief 主线程处理actor返回的任务
    *
    * @return
    */
    void OnMainThreadTick();

    /**
    * @brief 获得最大Actor Thread Num
    *
    * @return
    */
    virtual int GetMaxThreads();

    /**
    * @brief 记录监控Task
    *
    * @return
    */
    virtual void MonitorTask(NFTask* pTask);


    /**
    * @brief 检查超时
    *
    * @return
    */
    virtual void CheckTimeOutTask();

    /**
    * @brief 获取所有ActorId
    *
    * @return
    */
    virtual std::vector<int> GetAllActorId() const;
protected:
    Theron::Framework* m_pFramework;
    NFTaskActor* m_pMainActor;
protected:
    /**
    * @brief actor索引数组
    */
    std::vector<NFTaskActor*> m_vecActorPool;

    /**
    * @brief 用来平衡随机获得actor
    */
    std::atomic<uint32_t> mnSuitIndex;

    /**
    * @brief 返回的消息队列，线程安全,
    * actor线程将数据放入队列， 主线程从队列里取数据处理
    */
    NFQueueVector<NFTaskActorMessage> m_mQueue;

    /**
     * @brief 任务组ID
     */
    uint32_t m_taskGroupId;
};