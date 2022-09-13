#pragma once

#define THERON_USE_STD_THREADS 1

#include <vector>
#include <Theron/Theron.h>
#include <atomic>
#include "NFComm/NFCore/NFMutex.h"
class NFTask;
class NFITaskModule;
class NFITaskComponent;

/**
* @brief actor消息数据
*
*/
class NFTaskActorMessage
{
public:
	/**
	* @brief 消息类型
	*
	*/
	enum MessageType
	{
		/**
		* @brief 要处理的消息
		*
		*/
		ACTOR_MSG_TYPE_COMPONENT,

		/**
		* @brief 已经被处理的消息，等待返回主线程处理
		*
		*/
		ACTOR_MSG_TYPE_END_FUNC,
	};

	/**
	* @brief 构造函数
	*
	*/
	NFTaskActorMessage()
	{
		nFromActor = 0;
		pData = nullptr;
		nMsgType = ACTOR_MSG_TYPE_COMPONENT;
	}

	virtual ~NFTaskActorMessage()
	{
		nFromActor = 0;
		pData = nullptr;
		nMsgType = ACTOR_MSG_TYPE_COMPONENT;
	}

public:
	/**
	* @brief 消息类型
	*
	*/
	int nMsgType;

	/**
	* @brief 发送消息的actor索引
	*
	*/
	int nFromActor;

	/**
	* @brief 消息数据
	*
	*/
	NFTask* pData;
};

/**
* @brief actor基类
*
*/
class NFTaskActor : public Theron::Actor
{
public:
	/**
	* @brief 构造函数
	*        必须调用RegisterHandler，注册异步过程中用来处理的函数
	*/
	NFTaskActor(Theron::Framework& framework, NFITaskModule* pActorMgr);

	/**
	* @brief 析构函数
	*
	*/
	virtual ~NFTaskActor();

	/**
	* @brief 初始化
	*
	* @param
	* @return
	*/
	virtual bool Init();

	/**
	* @brief 向另外一个actor发送消息
	*
	* @param address 接受消息的actor的地址
	* @param message 发现的消息
	* @return 返回发送是否成功
	*/
	virtual bool SendMsg(const Theron::Address& address, const NFTaskActorMessage& message);

	/**
	* @brief 添加component
	*
	* @param
	* @return
	*/
	virtual bool AddComponnet(NFITaskComponent* pComponnet);

	/**
	* @brief 获得所有component
	*
	* @param
	* @return
	*/
	virtual NFITaskComponent* GetTaskComponent();

	/**
	* @brief 获得ActorId
	*
	* @param
	* @return
	*/
	virtual int GetActorId() const;
protected:
	/**
	* @brief 处理已经被处理过的消息
	*
	* @param message 要处理的消息
	* @param from	 发送消息的actor地址
	* @return 返回发送是否成功
	*/
	virtual void HandlerEx(const NFTaskActorMessage& message, Theron::Address from);

	/**
	* @brief 处理发送的数据
	*
	* @param message 要处理的消息
	* @param from	 发送消息的actor地址
	* @return
	*/
	virtual void Handler(const NFTaskActorMessage& message, Theron::Address from);
public:
	/**
	* @brief 处理task前的处理
	*
	* @param pTask 要处理的任务
	* @return
	*/
	virtual void ProcessTaskStart(NFTask* pTask);

	/**
	* @brief task处理后的处理
	*
	* @param pTask 要处理的任务
	* @return
	*/
	virtual void ProcessTaskEnd(NFTask* pTask);

	/**
	* @brief 异步处理任务系统
	*
	* @param pTask 要处理的任务
	* @return
	*/
	virtual void ProcessTask(NFTask* pTask);

	/**
	* @brief 检查超时task, 在主线程处理
	*
	* @param 
	* @return
	*/
	virtual void CheckTimeoutTask();
protected:
	/**
	* @brief 异步处理的过程
	*
	* @param message 要处理的消息
	* @param from	 发送消息的actor地址
	* @return
	*/
	virtual void DefaultHandler(const NFTaskActorMessage& message, Theron::Address from);
protected:
	/**
	* @brief actor管理基类
	*/
	NFITaskModule* m_pTaskModule;

	/**
	* @brief component管理
	*/
	NFITaskComponent* m_pComponent;
};
