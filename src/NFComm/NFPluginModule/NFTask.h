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

#include <string>

/*
线程池的线程基类
*/

class NFTask
{
public:
	NFTask()
	{
		m_balanceId = 0;
		m_useTime = 0;
		m_needManThreadProcess = true;
        m_handleActorId = 0;
        m_handleStartTime = 0;
	}

	virtual ~NFTask()
	{
	}

	enum TPTaskState
	{
		/// 一个任务已经完成
		TPTASK_STATE_COMPLETED = 0,

		/// 继续在主线程执行
		TPTASK_STATE_CONTINUE_MAINTHREAD = 1,

		// 继续在子线程执行
		TPTASK_STATE_CONTINUE_CHILDTHREAD = 2,
	};

	virtual uint64_t GetBalanceId() const
	{
		return m_balanceId;
	}

	virtual bool IsNeedMainThreadProcess() const
	{
		return m_needManThreadProcess;
	}

	virtual void SetBalanceId(uint64_t balanceId)
	{
		m_balanceId = balanceId;
	}

	/**
	**  异步线程处理函数，将在另一个线程里运行
	*/
	virtual bool ThreadProcess() = 0;

	/**
	** 主线程处理函数，将在线程处理完后，提交给主先来处理，根据返回函数是否继续处理
		返回值： thread::TPTask::TPTaskState， 请参看TPTaskState
	*/
	virtual TPTaskState MainThreadProcess()
	{
		return TPTASK_STATE_COMPLETED;
	}
public:
	bool m_needManThreadProcess; //是否需要主线程处理
	uint64_t m_balanceId; //动态均衡ID, 如果是玩家就是玩家CharId, 如果不是一般填0
	uint32_t m_useTime; //处理过程使用时间
	std::string m_taskName; //异步任务名字
	uint32_t m_handleActorId;
	uint64_t m_handleStartTime;
};

