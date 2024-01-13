// -------------------------------------------------------------------------
//    @FileName         :    NFCTaskModule.h
//    @Author           :    Gao.Yi
//    @Date             :   2022-09-18
//    @Email			:    445267987@qq.com
//    @Module           :    NFActorPlugin
//
// -------------------------------------------------------------------------

#pragma once

#include "NFComm/NFPluginModule/NFITaskModule.h"
#include "NFComm/NFCore/NFQueue.hpp"
#include "NFTaskActor.h"

#include "NFComm/NFCore/NFMutex.h"
#include "NFComm/NFCore/NFLock.h"
#include "NFComm/NFCore/NFAtomic.h"
#include <map>

class NFTaskGroup;
class NFCTaskModule final : public NFITaskModule
{
public:
	explicit NFCTaskModule(NFIPluginManager* p);
	virtual ~NFCTaskModule();

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
	virtual int InitActorThread(int actorGroup, int thread_num, int yieldstrategy = 0);

	/**
	* @brief 向系统请求请求一个actor
	*
	* @return 返回actor的唯一索引
	*/
	virtual int RequireActor(int actorGroup) override;

	/**
	* @brief 添加一个Actor组件
	*
	* @return 
	*/
	virtual int AddActorComponent(int actorGroup, int nActorIndex, NFITaskComponent* pComonnet) override;

	/**
	* @brief 获得所有component
	*
	* @param
	* @return
	*/
	virtual NFITaskComponent* GetTaskComponent(int actorGroup, int nActorIndex) override;

	/**
	* @brief 主线程通过自己保存的actorIndex将发送数据给actor线程
	*
	* @param nActorIndex	actor唯一索引
	* @param pData			要发送的数据
	* @return 是否成功
	*/
	virtual int SendMsgToActor(int actorGroup, int nActorIndex, NFTask* pData);

	/**
	* @brief 主线程通过自己保存的actorIndex将发送数据给actor线程
	*
	* @param nActorIndex	actor唯一索引
	* @param pData			要发送的数据
	* @return 是否成功
	*/
	virtual int SendMsgToActor(int actorGroup, NFTaskActor* pActor, NFTask* pData);

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
	virtual NFTaskActor* GetActor(int actorGroup, int nActorIndex);

	/**
	* @brief 获得系统还没有处理完的任务数目
	*
	* @return 未完成的任务数目
	*/
	virtual int GetNumQueuedMessages() override;

	/**
	* @brief 释放申请的actor数据，关闭actor池
	*
	* @return 是否成功
	*/
	virtual int CloseActorPool();

	/**
	* @brief 通过任务的动态均衡id，获得actor
	*		 为了防止数据库错乱，防止同时对数据库表中的一条数据，读取写入，
	*		 使用动态均衡id, 使得在某个时候只有一条线程对表中的一条数据，读取或写入
	* @param balanceId 动态均衡id
	* @return	一个actor索引
	*/
	int GetBalanceActor(int actorGroup, uint64_t balanceId);

	/**
	* @brief 随机获得一个actor
	*
	* @return actor索引
	*/
	int GetRandActor(int actorGroup);

	/**
	* @brief 添加要异步处理的task
	*
	* @param pTask 要异步处理的task
	* @return
	*/
	virtual int AddTask(int actorGroup, NFTask* pTask) override;

	/**
	* @brief 添加要异步处理的task
	*
	* @param pTask 要异步处理的task
	* @return
	*/
	virtual int AddTask(int actorGroup, int actorId, NFTask* pTask) override;

	/**
	* @brief 获得最大Actor Thread Num
	*
	* @return
	*/
	virtual int GetMaxThreads(int actorGroup) override;

	/**
	* @brief 获取所有ActorId
	*
	* @return
	*/
	virtual std::vector<int> GetAllActorId(int actorGroup) const override;
protected:
    std::vector<NFTaskGroup*> m_taskGroups;
};
