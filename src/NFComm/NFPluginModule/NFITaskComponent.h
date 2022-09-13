// -------------------------------------------------------------------------
//    @FileName         :    NFITaskComponent.h
//    @Author           :    Gao.Yi
//    @Date             :   xxxx-xx-xx
//    @Module           :    NFITaskComponent
//
//
//                    .::::.
//                  .::::::::.
//                 :::::::::::  FUCK YOU
//             ..:::::::::::'
//           '::::::::::::'
//             .::::::::::
//        '::::::::::::::..
//             ..::::::::::::.
//           ``::::::::::::::::
//            ::::``:::::::::'        .:::.
//           ::::'   ':::::'       .::::::::.
//         .::::'      ::::     .:::::::'::::.
//        .:::'       :::::  .:::::::::' ':::::.
//       .::'        :::::.:::::::::'      ':::::.
//      .::'         ::::::::::::::'         ``::::.
//  ...:::           ::::::::::::'              ``::.
// ```` ':.          ':::::::::'                  ::::..
//                    '.:::::'                    ':'````..
//
// -------------------------------------------------------------------------

#pragma once

#include "NFComm/NFCore/NFPlatform.h"
#include "NFTask.h"

class NFTaskActor;

class NFITaskComponent
{
public:
	NFITaskComponent()
	{
		mActorId = -1;
	}

	virtual ~NFITaskComponent()
	{
	}

	virtual void ProcessTaskStart(NFTask* pTask)
	{
	}

	virtual void ProcessTask(NFTask* pTask)
	{
		if (pTask)
		{
			//NFLogError("actor id:{}, threadid:{}", this->GetAddress().AsInteger(), ThreadId());
			pTask->ThreadProcess();
		}
	}

	virtual void ProcessTaskEnd(NFTask* pTask)
	{

	}

	virtual int GetActorId() const
	{
		return mActorId;
	}

	virtual void SetActorId(int actorId)
	{
		mActorId = actorId;
	}

	virtual const std::string GetComponentName() const
	{
		return m_componentName;
	}

	virtual void SetComponentName(const std::string& name)
	{
		m_componentName = name;
	}

	virtual void HandleTaskDeadCycle(const std::string& taskName, uint64_t useTime)
	{

	}

	virtual void HandleTaskTimeOut(const std::string& taskName, uint64_t useTime)
	{

	}
private:
	int mActorId;
	std::string m_componentName;
};


