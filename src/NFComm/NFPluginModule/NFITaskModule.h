#pragma once

#include "NFIModule.h"

#include <vector>

class NFTaskActorMessage;
class NFTask;
class NFITaskComponent;

enum TaskModule_YieldStrategy
{
	TaskModule_YIELD_STRATEGY_CONDITION = 0,       ///< Threads wait on condition variables when no work is available.
	TaskModule_YIELD_STRATEGY_HYBRID,              ///< Threads spin for a while, then yield to other threads, when no work is available.
	TaskModule_YIELD_STRATEGY_SPIN,                ///< Threads busy-wait, without yielding, when no work is available.

	// Legacy section
	TaskModule_YIELD_STRATEGY_BLOCKING = 0,        ///< Deprecated - use YIELD_STRATEGY_CONDITION.
	TaskModule_YIELD_STRATEGY_POLITE = 0,          ///< Deprecated - use YIELD_STRATEGY_CONDITION.
	TaskModule_YIELD_STRATEGY_STRONG = 1,          ///< Deprecated - use YIELD_STRATEGY_HYBRID.
	TaskModule_YIELD_STRATEGY_AGGRESSIVE = 2       ///< Deprecated - use YIELD_STRATEGY_SPIN.
};

class NFITaskModule : public NFIModule
{
public:
	NFITaskModule(NFIPluginManager* p) :NFIModule(p)
	{

	}

	virtual ~NFITaskModule()
	{

	}
	/**
	* @brief 初始化actor系统, 配置线程个数
	*
	* @param thread_num	线程数目，至少为1
	* @return < 0 : Failed
	*/
	virtual int InitActorThread(int thread_num, int yieldstrategy = 0) = 0;

	/**
	* @brief 消息数据处理完后，如果有必要将数据返回给主线程，
	*		 在这个函数里，将消息数据推送给主线程，这个函数在actor线程中执行
	*
	* @param message	消息数据
	* @param from	发送消息的actor地址
	* @return 是否成功
	*/
	virtual bool HandlerEx(const NFTaskActorMessage& message, int from) = 0;

	/**
	* @brief 添加要异步处理的task
	*
	* @param pTask 要异步处理的task
	* @return
	*/
	virtual int AddTask(NFTask* pTask) = 0;

	/**
	* @brief 添加要异步处理的task
	*
	* @param pTask 要异步处理的task
	* @return
	*/
	template<typename NFTaskType>
	int AddTaskToEveryActor(const NFTaskType& task)
	{
		std::vector<int> vecActorId = GetAllActorId();
		for (size_t i = 0; i < vecActorId.size(); i++)
		{
			auto pTask = new NFTaskType();
			*pTask = task;
			SendMsgToActor(vecActorId[i], pTask);
		}
		return 0;
	}

	/**
	* @brief 主线程通过自己保存的actorIndex将发送数据给actor线程
	*
	* @param nActorIndex	actor唯一索引
	* @param pData			要发送的数据
	* @return 是否成功
	*/
	virtual int SendMsgToActor(int nActorIndex, NFTask* pData) = 0;

	/**
	* @brief 添加要异步处理的task
	*
	* @param pTask 要异步处理的task
	* @return
	*/
	virtual int AddTask(int actorId, NFTask* pTask) = 0;

	/**
	* @brief 向系统请求请求一个actor
	*
	* @return 返回actor的唯一索引
	*/
	virtual int RequireActor() = 0;

	/**
	* @brief 获得系统还没有处理完的任务数目
	*
	* @return 未完成的任务数目
	*/
	virtual int GetNumQueuedMessages() = 0;

	/**
	* @brief 添加一个Actor组件
	*
	* @return
	*/
	virtual int AddActorComponent(int nActorIndex, NFITaskComponent* pComonnet) = 0;

	/**
	* @brief 获得所有component
	*
	* @param
	* @return
	*/
	virtual NFITaskComponent* GetTaskComponent(int nActorIndex) = 0;

	/**
	* @brief 获得最大Actor Thread Num
	*
	* @return
	*/
	virtual int GetMaxThreads() = 0;

	/**
	* @brief 记录监控Task
	*
	* @return
	*/
	virtual void MonitorTask(NFTask* pTask) = 0;

	/**
	* @brief 获取所有ActorId
	*
	* @return
	*/
	virtual std::vector<int> GetAllActorId() const = 0;
};
