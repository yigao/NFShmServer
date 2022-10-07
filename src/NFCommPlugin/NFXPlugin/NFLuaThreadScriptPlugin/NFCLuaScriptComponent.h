// -------------------------------------------------------------------------
//    @FileName         :    NFCLuaScriptComponent.h
//    @Author           :    GaoYi
//    @Date             :    2018/08/26
//    @Email			:    445267987@qq.com
//    @Module           :    NFPluginModule
//
// -------------------------------------------------------------------------

#pragma once

#include "NFComm/NFPluginModule/NFITaskComponent.h"
#include "NFComm/NFPluginModule/NFILuaModule.h"
#include "NFComm/NFPluginModule/NFIPluginManager.h"

#include "NFComm/NFPluginModule/NFIKernelModule.h"
#include "NFComm/NFPluginModule/NFILuaScriptModule.h"
#include "NFComm/NFPluginModule/NFIScriptModule.h"

#include "NFComm/NFPluginModule/NFILuaModule.h"
#include "NFComm/NFCore/NFFileUtility.h"
#include "NFComm/NFCore/NFHash.hpp"
#include "NFComm/NFCore/NFStringUtility.h"
#include "NFComm/NFCore/NFCommon.h"
#include "NFComm/NFPluginModule/NFIHttpClientModule.h"
#include "NFComm/NFPluginModule/NFIHttpServerModule.h"
#include "NFComm/NFPluginModule/NFIServerNetEventModule.h"
#include "NFComm/NFPluginModule/NFLogMgr.h"
#include "NFCLuaThreadModule.h"

class NFCLuaThreadModule;
class NFCLuaScriptComponent;

enum EnumLuaThreadModule
{
	EnumLuaThreadModule_NULL = 0,
	EnumLuaThreadModule_LOAD = 1,
	EnumLuaThreadModule_Init = 2,
	EnumLuaThreadModule_WaitFinishInit = 3,
	EnumLuaThreadModule_Loop = 4,
	EnumLuaThreadModule_Work = 5,
	EnumLuaThreadModule_SEC = 6,
	EnumLuaThreadModule_MIN = 7,
	EnumLuaThreadModule_5MIN = 8,
	EnumLuaThreadModule_10MIN = 9,
	EnumLuaThreadModule_30MIN = 10,
	EnumLuaThreadModule_HOUR = 11,
	EnumLuaThreadModule_DAY = 12,
	EnumLuaThreadModule_WEEK = 13,
	EnumLuaThreadModule_MONTH = 14,
};

class NFLuaThreadTask : public NFTask
{
public:
	NFLuaThreadTask()
	{
		m_taskType = EnumLuaThreadModule_NULL;
		m_pLuaThreadModule = nullptr;
		m_pComponent = nullptr;
	}

	uint32_t m_taskType;
	NFCLuaThreadModule* m_pLuaThreadModule;
	NFCLuaScriptComponent* m_pComponent;
};

class NFWorkActorLoadTask : public NFLuaThreadTask
{
public:
	NFWorkActorLoadTask(NFCLuaThreadModule* pLuaThreadModule = nullptr, const std::string& luaFunc = "", const std::string& param = "")
	{
		m_pLuaThreadModule = pLuaThreadModule;
		m_luaFunc = luaFunc;
		m_param = param;
		m_taskName = "WorkTask_Load";
	}
	/**
	**  异步线程处理函数，将在另一个线程里运行
	*/
	virtual bool ThreadProcess();

	/**
	** 主线程处理函数，将在线程处理完后，提交给主先来处理，根据返回函数是否继续处理
		返回值： thread::TPTask::TPTaskState， 请参看TPTaskState
	*/
	virtual TPTaskState MainThreadProcess()
	{
		m_pLuaThreadModule->AddFinishLoad();
		return TPTASK_STATE_COMPLETED;
	}
public:
	std::string m_param;
	std::string m_luaFunc;
};

class NFWorkActorTask : public NFLuaThreadTask
{
public:
	NFWorkActorTask(NFCLuaThreadModule* pLuaThreadModule = nullptr, const std::string& luaFunc = "", const std::string& param = "")
	{
		m_pLuaThreadModule = pLuaThreadModule;
		m_luaFunc = luaFunc;
		m_param = param;
		m_taskName = "WorkTask_" + luaFunc;
		if (!param.empty())
		{
			m_balanceId = (uint64_t)NFHash::hash_string(param.c_str());
		}
		m_needManThreadProcess = false;
	}
	/**
	**  异步线程处理函数，将在另一个线程里运行
	*/
	virtual bool ThreadProcess();

	/**
	** 主线程处理函数，将在线程处理完后，提交给主先来处理，根据返回函数是否继续处理
		返回值： thread::TPTask::TPTaskState， 请参看TPTaskState
	*/
	virtual TPTaskState MainThreadProcess()
	{
		return TPTASK_STATE_COMPLETED;
	}
public:
	std::string m_param;
	std::string m_luaFunc;
};

class NFServerLoopLoadTask : public NFLuaThreadTask
{
public:
	NFServerLoopLoadTask(NFCLuaThreadModule* pLuaThreadModule = nullptr, const std::string& param = "")
	{
		m_pLuaThreadModule = pLuaThreadModule;
		m_param = param;

		m_taskName = "ServerLoopTask_Load";
	}
	/**
	**  异步线程处理函数，将在另一个线程里运行
	*/
	virtual bool ThreadProcess();

	/**
	** 主线程处理函数，将在线程处理完后，提交给主先来处理，根据返回函数是否继续处理
		返回值： thread::TPTask::TPTaskState， 请参看TPTaskState
	*/
	virtual TPTaskState MainThreadProcess();
public:
	std::string m_param;
};

class NFServerLoopInitTask : public NFLuaThreadTask
{
public:
	NFServerLoopInitTask(NFCLuaThreadModule* pLuaThreadModule = nullptr, const std::string& param = "")
	{
		m_pLuaThreadModule = pLuaThreadModule;
		m_param = param;
		m_taskName = "ServerLoopTask_init";
	}
	/**
	**  异步线程处理函数，将在另一个线程里运行
	*/
	virtual bool ThreadProcess();

	/**
	** 主线程处理函数，将在线程处理完后，提交给主先来处理，根据返回函数是否继续处理
		返回值： thread::TPTask::TPTaskState， 请参看TPTaskState
	*/
	virtual TPTaskState MainThreadProcess();
public:
	std::string m_param;
};

class NFServerLoopTask : public NFLuaThreadTask
{
public:
	NFServerLoopTask(NFCLuaThreadModule* pLuaThreadModule = nullptr, const std::string& param = "")
	{
		m_pLuaThreadModule = pLuaThreadModule;
		m_param = param;
		m_taskName = "ServerLoopTask_" + param;
		m_needManThreadProcess = false;
	}
	/**
	**  异步线程处理函数，将在另一个线程里运行
	*/
	virtual bool ThreadProcess();

	/**
	** 主线程处理函数，将在线程处理完后，提交给主先来处理，根据返回函数是否继续处理
		返回值： thread::TPTask::TPTaskState， 请参看TPTaskState
	*/
	virtual TPTaskState MainThreadProcess();
public:
	std::string m_param;
};

class NFProcessRealTimerActorTask : public NFLuaThreadTask
{
public:
	NFProcessRealTimerActorTask(NFCLuaThreadModule* pLuaThreadModule = nullptr, const std::string& luaFunc = "", const std::string& param = "")
	{
		m_pLuaThreadModule = pLuaThreadModule;
		m_luaFunc = luaFunc;
		m_param = param;
		m_taskName = "NFProcessRealTimer_" + luaFunc;
		if (!param.empty())
		{
			m_balanceId = (uint64_t)NFHash::hash_string(param.c_str());
		}
		m_needManThreadProcess = false;
	}
	/**
	**  异步线程处理函数，将在另一个线程里运行
	*/
	virtual bool ThreadProcess();

	/**
	** 主线程处理函数，将在线程处理完后，提交给主先来处理，根据返回函数是否继续处理
		返回值： thread::TPTask::TPTaskState， 请参看TPTaskState
	*/
	virtual TPTaskState MainThreadProcess()
	{
		return TPTASK_STATE_COMPLETED;
	}
public:
	std::string m_param;
	std::string m_luaFunc;
};

class NFProcessTimerActorTask : public NFLuaThreadTask
{
public:
	NFProcessTimerActorTask(NFCLuaThreadModule* pLuaThreadModule = nullptr, const std::string& luaFunc = "", const std::string& param = "")
	{
		m_pLuaThreadModule = pLuaThreadModule;
		m_luaFunc = luaFunc;
		m_param = param;
		m_taskName = "ProcessTimerTask_" + luaFunc;
		if (!param.empty())
		{
			m_balanceId = (uint64_t)NFHash::hash_string(param.c_str());
		}
		m_needManThreadProcess = false;
	}
	/**
	**  异步线程处理函数，将在另一个线程里运行
	*/
	virtual bool ThreadProcess();

	/**
	** 主线程处理函数，将在线程处理完后，提交给主先来处理，根据返回函数是否继续处理
		返回值： thread::TPTask::TPTaskState， 请参看TPTaskState
	*/
	virtual TPTaskState MainThreadProcess()
	{
		return TPTASK_STATE_COMPLETED;
	}
public:
	std::string m_param;
	std::string m_luaFunc;
};

class NFProcessLoopTimerActorTask : public NFLuaThreadTask
{
public:
	NFProcessLoopTimerActorTask(NFCLuaThreadModule* pLuaThreadModule = nullptr, const std::string& luaFunc = "", const std::string& param = "")
	{
		m_pLuaThreadModule = pLuaThreadModule;
		m_luaFunc = luaFunc;
		m_param = param;
		m_taskName = "ProcessLoopTimerTask_" + luaFunc;
		m_needManThreadProcess = false;
	}
	/**
	**  异步线程处理函数，将在另一个线程里运行
	*/
	virtual bool ThreadProcess();

	/**
	** 主线程处理函数，将在线程处理完后，提交给主先来处理，根据返回函数是否继续处理
		返回值： thread::TPTask::TPTaskState， 请参看TPTaskState
	*/
	virtual TPTaskState MainThreadProcess()
	{
		return TPTASK_STATE_COMPLETED;
	}
public:
	std::string m_param;
	std::string m_luaFunc;
};

class NFTcpMsgActorLoadTask : public NFLuaThreadTask
{
public:
	NFTcpMsgActorLoadTask(NFCLuaThreadModule* pLuaThreadModule = nullptr, const std::string& luaFunc = "", const uint32_t unLinkId = 0, const uint64_t valueId = 0, const uint32_t nMsgId = 0, const std::string& strMsg = "")
	{
		m_balanceId = valueId;
		m_pLuaThreadModule = pLuaThreadModule;
		m_luaFunc = luaFunc;
		m_unLinkId = unLinkId;
		m_valueId = valueId;
		m_msgId = nMsgId;
		m_strMsg = strMsg;

		m_taskName = "TcpMsgTask_Load";
	}

	/**
	**  异步线程处理函数，将在另一个线程里运行
	*/
	virtual bool ThreadProcess();

	/**
	** 主线程处理函数，将在线程处理完后，提交给主先来处理，根据返回函数是否继续处理
		返回值： thread::TPTask::TPTaskState， 请参看TPTaskState
	*/
	virtual TPTaskState MainThreadProcess()
	{
		m_pLuaThreadModule->AddFinishLoad();
		return TPTASK_STATE_COMPLETED;
	}
public:
	std::string m_luaFunc;
	uint32_t m_unLinkId;
	uint64_t m_valueId;
	uint32_t m_msgId;
	std::string m_strMsg;
};

class NFTcpMsgActorTask : public NFLuaThreadTask
{
public:
	NFTcpMsgActorTask(NFCLuaThreadModule* pLuaThreadModule = nullptr, const std::string& luaFunc = "", const uint32_t unLinkId = 0, const uint64_t valueId = 0, const uint32_t operateId = 0, const uint32_t nMsgId = 0, const std::string& strMsg = "")
	{
		m_balanceId = valueId;
		m_pLuaThreadModule = pLuaThreadModule;
		m_luaFunc = luaFunc;
		m_unLinkId = unLinkId;
		m_valueId = valueId;
		m_msgId = nMsgId;
		m_strMsg = strMsg;
		m_operateId = operateId;

		m_taskName = "TcpMsgTask_" + luaFunc + "_" + NFCommon::tostr(nMsgId);
		m_needManThreadProcess = false;
	}

	/**
	**  异步线程处理函数，将在另一个线程里运行
	*/
	virtual bool ThreadProcess();

	/**
	** 主线程处理函数，将在线程处理完后，提交给主先来处理，根据返回函数是否继续处理
		返回值： thread::TPTask::TPTaskState， 请参看TPTaskState
	*/
	virtual TPTaskState MainThreadProcess()
	{
		return TPTASK_STATE_COMPLETED;
	}
public:
	std::string m_luaFunc;
	uint32_t m_unLinkId;
	uint64_t m_valueId;
	uint32_t m_msgId;
	std::string m_strMsg;
	uint32_t m_operateId;
};

class NFTcpMainSubMsgActorTask : public NFLuaThreadTask
{
public:
	NFTcpMainSubMsgActorTask(NFCLuaThreadModule* pLuaThreadModule = nullptr, const std::string& luaFunc = "", const uint32_t unLinkId = 0, const uint64_t valueId = 0, const uint32_t operateId = 0, const uint16_t mainMsgId = 0, const uint16_t subMsgId = 0, const std::string& strMsg = "")
	{
		m_balanceId = valueId;
		m_pLuaThreadModule = pLuaThreadModule;
		m_luaFunc = luaFunc;
		m_unLinkId = unLinkId;
		m_valueId = valueId;
		m_mainMsgId = mainMsgId;
		m_subMsgId = subMsgId;
		m_strMsg = strMsg;
		m_operateId = operateId;

		m_taskName = "NFTcpMainSubMsg_" + luaFunc + "_" + NFCommon::tostr(mainMsgId) + "_" + NFCommon::tostr(subMsgId);
		m_needManThreadProcess = false;
	}

	/**
	**  异步线程处理函数，将在另一个线程里运行
	*/
	virtual bool ThreadProcess();

	/**
	** 主线程处理函数，将在线程处理完后，提交给主先来处理，根据返回函数是否继续处理
		返回值： thread::TPTask::TPTaskState， 请参看TPTaskState
	*/
	virtual TPTaskState MainThreadProcess()
	{
		return TPTASK_STATE_COMPLETED;
	}
public:
	std::string m_luaFunc;
	uint32_t m_unLinkId;
	uint64_t m_valueId;
	uint16_t m_mainMsgId;
	uint16_t m_subMsgId;
	std::string m_strMsg;
	uint32_t m_operateId;
};

class NFHttpMsgActorTask : public NFLuaThreadTask
{
public:
	NFHttpMsgActorTask(NFCLuaThreadModule* pLuaThreadModule = nullptr, const std::string& luaFunc = "", const uint32_t unLinkId = 0, const uint32_t requestId = 0, const std::string& firstPath = "", const std::string& secondPath = "", const std::string& strMsg = "")
	{
		m_pLuaThreadModule = pLuaThreadModule;
		m_luaFunc = luaFunc;
		m_unLinkId = unLinkId;
		m_requestId = requestId;
		m_firstPath = firstPath;
		m_secondPath = secondPath;
		m_strMsg = strMsg;
		m_taskName = "HttpMsgTask_" + luaFunc + "_" + firstPath + "_" + secondPath;
		m_needManThreadProcess = false;
	}
	/**
	**  异步线程处理函数，将在另一个线程里运行
	*/
	virtual bool ThreadProcess();

	/**
	** 主线程处理函数，将在线程处理完后，提交给主先来处理，根据返回函数是否继续处理
		返回值： thread::TPTask::TPTaskState， 请参看TPTaskState
	*/
	virtual TPTaskState MainThreadProcess()
	{
		return TPTASK_STATE_COMPLETED;
	}
public:
	std::string m_luaFunc;
	uint32_t m_unLinkId;
	std::string m_strMsg;
	uint32_t m_requestId;
	std::string m_firstPath;
	std::string m_secondPath;
};

class NFHotfixAllLuaActorTask : public NFLuaThreadTask
{
public:
	NFHotfixAllLuaActorTask(NFCLuaThreadModule* pLuaThreadModule = nullptr, const std::vector<std::string>& vecStr = std::vector<std::string>())
	{
		m_pLuaThreadModule = pLuaThreadModule;
		m_vecLuaFile = vecStr;
		m_taskName = "HotfixAllLua";
	}

	/**
	**  异步线程处理函数，将在另一个线程里运行
	*/
	virtual bool ThreadProcess();

	/**
	** 主线程处理函数，将在线程处理完后，提交给主先来处理，根据返回函数是否继续处理
		返回值： thread::TPTask::TPTaskState， 请参看TPTaskState
	*/
	virtual TPTaskState MainThreadProcess();
public:
	std::vector<std::string> m_vecLuaFile;
};

class NFHotfixLuaFilesActorTask : public NFLuaThreadTask
{
public:
	NFHotfixLuaFilesActorTask(NFCLuaThreadModule* pLuaThreadModule = nullptr, const std::vector<std::string>& vecStr = std::vector<std::string>())
	{
		m_pLuaThreadModule = pLuaThreadModule;
		m_vecLuaFile = vecStr;
		m_taskName = "HotfixLuaFiles";
		m_needManThreadProcess = false;
	}

	/**
	**  异步线程处理函数，将在另一个线程里运行
	*/
	virtual bool ThreadProcess();

	/**
	** 主线程处理函数，将在线程处理完后，提交给主先来处理，根据返回函数是否继续处理
		返回值： thread::TPTask::TPTaskState， 请参看TPTaskState
	*/
	virtual TPTaskState MainThreadProcess()
	{
		return TPTASK_STATE_COMPLETED;
	}
public:
	std::vector<std::string> m_vecLuaFile;
};

class NFLuaGcActorTask : public NFLuaThreadTask
{
public:
	NFLuaGcActorTask(NFCLuaThreadModule* pLuaThreadModule = nullptr)
	{
		m_pLuaThreadModule = pLuaThreadModule;
		m_taskName = "LuaGC";
		m_needManThreadProcess = false;
	}
	/**
	**  异步线程处理函数，将在另一个线程里运行
	*/
	virtual bool ThreadProcess();

	/**
	** 主线程处理函数，将在线程处理完后，提交给主先来处理，根据返回函数是否继续处理
		返回值： thread::TPTask::TPTaskState， 请参看TPTaskState
	*/
	virtual TPTaskState MainThreadProcess()
	{
		return TPTASK_STATE_COMPLETED;
	}
};

/**
**  主线程执行，每一分钟执行一次这个任务
*/
class NFLuaMinActorTask : public NFLuaThreadTask
{
public:
	NFLuaMinActorTask(NFCLuaThreadModule* pLuaThreadModule = nullptr)
	{
		m_pLuaThreadModule = pLuaThreadModule;
		m_taskName = "LuaMinTask";
		m_needManThreadProcess = false;
	}
	/**
	**  异步线程处理函数，将在另一个线程里运行
	*/
	virtual bool ThreadProcess();

	/**
	** 主线程处理函数，将在线程处理完后，提交给主先来处理，根据返回函数是否继续处理
		返回值： thread::TPTask::TPTaskState， 请参看TPTaskState
	*/
	virtual TPTaskState MainThreadProcess()
	{
		return TPTASK_STATE_COMPLETED;
	}
};

/**
**  主线程执行，每5分钟执行一次这个任务
*/
class NFLua5MinActorTask : public NFLuaThreadTask
{
public:
	NFLua5MinActorTask(NFCLuaThreadModule* pLuaThreadModule = nullptr)
	{
		m_pLuaThreadModule = pLuaThreadModule;
		m_taskName = "Lua5MinTask";
		m_needManThreadProcess = false;
	}
	/**
	**  异步线程处理函数，将在另一个线程里运行
	*/
	virtual bool ThreadProcess();

	/**
	** 主线程处理函数，将在线程处理完后，提交给主先来处理，根据返回函数是否继续处理
		返回值： thread::TPTask::TPTaskState， 请参看TPTaskState
	*/
	virtual TPTaskState MainThreadProcess()
	{
		return TPTASK_STATE_COMPLETED;
	}
};

/**
**  主线程执行，每10分钟执行一次这个任务
*/
class NFLua10MinActorTask : public NFLuaThreadTask
{
public:
	NFLua10MinActorTask(NFCLuaThreadModule* pLuaThreadModule = nullptr)
	{
		m_pLuaThreadModule = pLuaThreadModule;
		m_taskName = "Lua10MinTask";
		m_needManThreadProcess = false;
	}
	/**
	**  异步线程处理函数，将在另一个线程里运行
	*/
	virtual bool ThreadProcess();

	/**
	** 主线程处理函数，将在线程处理完后，提交给主先来处理，根据返回函数是否继续处理
		返回值： thread::TPTask::TPTaskState， 请参看TPTaskState
	*/
	virtual TPTaskState MainThreadProcess()
	{
		return TPTASK_STATE_COMPLETED;
	}
};

/**
**  主线程执行，每30分钟执行一次这个任务
*/
class NFLua30MinActorTask : public NFLuaThreadTask
{
public:
	NFLua30MinActorTask(NFCLuaThreadModule* pLuaThreadModule = nullptr)
	{
		m_pLuaThreadModule = pLuaThreadModule;
		m_taskName = "Lua30MinTask";
		m_needManThreadProcess = false;
	}
	/**
	**  异步线程处理函数，将在另一个线程里运行
	*/
	virtual bool ThreadProcess();

	/**
	** 主线程处理函数，将在线程处理完后，提交给主先来处理，根据返回函数是否继续处理
		返回值： thread::TPTask::TPTaskState， 请参看TPTaskState
	*/
	virtual TPTaskState MainThreadProcess()
	{
		return TPTASK_STATE_COMPLETED;
	}
};

/**
**  主线程执行，每一小时执行一次这个任务
*/
class NFLuaHourActorTask : public NFLuaThreadTask
{
public:
	NFLuaHourActorTask(NFCLuaThreadModule* pLuaThreadModule = nullptr)
	{
		m_pLuaThreadModule = pLuaThreadModule;
		m_taskName = "LuaHourTask";
		m_needManThreadProcess = false;
	}
	/**
	**  异步线程处理函数，将在另一个线程里运行
	*/
	virtual bool ThreadProcess();

	/**
	** 主线程处理函数，将在线程处理完后，提交给主先来处理，根据返回函数是否继续处理
		返回值： thread::TPTask::TPTaskState， 请参看TPTaskState
	*/
	virtual TPTaskState MainThreadProcess()
	{
		return TPTASK_STATE_COMPLETED;
	}
};

/**
**  主线程执行，每一天执行一次这个任务
*/
class NFLuaDayActorTask : public NFLuaThreadTask
{
public:
	NFLuaDayActorTask(NFCLuaThreadModule* pLuaThreadModule = nullptr)
	{
		m_pLuaThreadModule = pLuaThreadModule;
		m_taskName = "LuaDayTask";
		m_needManThreadProcess = false;
	}
	/**
	**  异步线程处理函数，将在另一个线程里运行
	*/
	virtual bool ThreadProcess();

	/**
	** 主线程处理函数，将在线程处理完后，提交给主先来处理，根据返回函数是否继续处理
		返回值： thread::TPTask::TPTaskState， 请参看TPTaskState
	*/
	virtual TPTaskState MainThreadProcess()
	{
		return TPTASK_STATE_COMPLETED;
	}
};

/**
**  主线程执行，每一周执行一次这个任务
*/
class NFLuaWeekActorTask : public NFLuaThreadTask
{
public:
	NFLuaWeekActorTask(NFCLuaThreadModule* pLuaThreadModule = nullptr)
	{
		m_pLuaThreadModule = pLuaThreadModule;
		m_taskName = "LuaWeekTask";
		m_needManThreadProcess = false;
	}
	/**
	**  异步线程处理函数，将在另一个线程里运行
	*/
	virtual bool ThreadProcess();

	/**
	** 主线程处理函数，将在线程处理完后，提交给主先来处理，根据返回函数是否继续处理
		返回值： thread::TPTask::TPTaskState， 请参看TPTaskState
	*/
	virtual TPTaskState MainThreadProcess()
	{
		return TPTASK_STATE_COMPLETED;
	}
};

/**
**   主线程执行，每一月执行一次这个任务
*/
class NFLuaMonthActorTask : public NFLuaThreadTask
{
public:
	NFLuaMonthActorTask(NFCLuaThreadModule* pLuaThreadModule = nullptr)
	{
		m_pLuaThreadModule = pLuaThreadModule;
		m_taskName = "LuaMonthTask";
		m_needManThreadProcess = false;
	}
	/**
	**  异步线程处理函数，将在另一个线程里运行
	*/
	virtual bool ThreadProcess();

	/**
	** 主线程处理函数，将在线程处理完后，提交给主先来处理，根据返回函数是否继续处理
		返回值： thread::TPTask::TPTaskState， 请参看TPTaskState
	*/
	virtual TPTaskState MainThreadProcess()
	{
		return TPTASK_STATE_COMPLETED;
	}
};

class NFTcpSessionCloseActorTask : public NFLuaThreadTask
{
public:
	NFTcpSessionCloseActorTask(NFCLuaThreadModule* pLuaThreadModule = nullptr, uint64_t playerId = 0)
	{
		m_pLuaThreadModule = pLuaThreadModule;
		m_taskName = "TcpSessionClose";
		m_playerId = playerId;
		m_needManThreadProcess = false;
	}
	/**
	**  异步线程处理函数，将在另一个线程里运行
	*/
	virtual bool ThreadProcess();

	/**
	** 主线程处理函数，将在线程处理完后，提交给主先来处理，根据返回函数是否继续处理
		返回值： thread::TPTask::TPTaskState， 请参看TPTaskState
	*/
	virtual TPTaskState MainThreadProcess()
	{
		return TPTASK_STATE_COMPLETED;
	}

	uint64_t m_playerId;
};

class NFTcpSessionReportActorTask : public NFLuaThreadTask
{
public:
	NFTcpSessionReportActorTask(NFCLuaThreadModule* pLuaThreadModule = nullptr, uint64_t playerId = 0, const std::string& ip = "")
	{
		m_pLuaThreadModule = pLuaThreadModule;
		m_taskName = "TcpSessionReport";
		m_playerId = playerId;
		m_ip = ip;
		m_needManThreadProcess = false;
	}
	/**
	**  异步线程处理函数，将在另一个线程里运行
	*/
	virtual bool ThreadProcess();

	/**
	** 主线程处理函数，将在线程处理完后，提交给主先来处理，根据返回函数是否继续处理
		返回值： thread::TPTask::TPTaskState， 请参看TPTaskState
	*/
	virtual TPTaskState MainThreadProcess()
	{
		return TPTASK_STATE_COMPLETED;
	}
	uint64_t m_playerId;
	std::string m_ip;
};

class NFRunGmFunctionActorTask : public NFLuaThreadTask
{
public:
	NFRunGmFunctionActorTask(NFCLuaThreadModule* pLuaThreadModule = nullptr, const std::string& luaFunction = "", const std::vector<std::string>& vecParams = std::vector<std::string>())
	{
		m_pLuaThreadModule = pLuaThreadModule;
		m_taskName = "RunGmFunction";
		m_needManThreadProcess = false;
		m_luaFunction = luaFunction;
		m_vecParams = vecParams;
	}
	/**
	**  异步线程处理函数，将在另一个线程里运行
	*/
	virtual bool ThreadProcess();

	/**
	** 主线程处理函数，将在线程处理完后，提交给主先来处理，根据返回函数是否继续处理
		返回值： thread::TPTask::TPTaskState， 请参看TPTaskState
	*/
	virtual TPTaskState MainThreadProcess()
	{
		return TPTASK_STATE_COMPLETED;
	}
	std::string m_luaFunction;
	std::vector<std::string> m_vecParams;
};

class NFCLuaScriptComponent : public NFITaskComponent, public NFILuaModule, public NFIModule
{
public:
	NFCLuaScriptComponent(NFCLuaThreadModule* pLuaThreadModule, NFIPluginManager* p);

	virtual ~NFCLuaScriptComponent();

	bool IsDeadCycle() { return m_deadCycle.load(); }
	void SetDeadCycle() { m_deadCycle.store(true); }
	void ClearDeadCycle() { m_deadCycle.store(false); }

	void ProcessTaskStart(NFTask* pTask) override
	{
		NFLuaThreadTask* pLuaTask = dynamic_cast<NFLuaThreadTask*>(pTask);
		if (pLuaTask)
		{
			pLuaTask->m_pComponent = this;
		}
		else
		{
			assert(false);
		}
	}

	void ProcessTask(NFTask* pTask) override
	{
		if (pTask)
		{
			pTask->ThreadProcess();
			//lua_gc(GetLuaState(), LUA_GCCOLLECT, 0);
		}
	}

	void ProcessTaskEnd(NFTask* pTask) override
	{
		NFLuaThreadTask* pLuaTask = dynamic_cast<NFLuaThreadTask*>(pTask);
		if (pLuaTask)
		{
			if (pLuaTask->m_pComponent)
			{
				if (pLuaTask->m_pComponent->IsDeadCycle())
				{
					pLuaTask->m_pComponent->ClearDeadCycle();
					NFLogError(NF_LOG_SYSTEMLOG, 0, "the actor will start new lua state in the actor:{} actorId:{}, the system will kill the lua func", pLuaTask->m_pComponent->GetComponentName(), pLuaTask->m_pComponent->GetActorId());
					pLuaTask->m_pComponent->CreateLuaContext();
					pLuaTask->m_pComponent->Register();
					pLuaTask->m_pComponent->LoadScript();
				}
			}
			pLuaTask->m_pComponent = nullptr;
		}
	}

	/*
	actor线程执行
	*/
	static void TimeOutBreak(lua_State* L, lua_Debug* ar)
	{
		lua_sethook(L, NULL, 0, 0);
		luaL_error(L, "script timeout.");
	}

	/*
	主线程执行
	*/
	virtual void HandleTaskDeadCycle(const std::string& taskName, uint64_t useTime)
	{
		if (!m_pPluginManager->IsLoadAllServer() && useTime > 120000)
		{
			if (taskName == "WorkTask_Load" || taskName == "ServerLoopTask_Load" || taskName == "ServerLoopTask_init" || taskName == "TcpMsgTask_Load")
			{
				return;
			}
			SetDeadCycle();
			NFLogError(NF_LOG_SYSTEMLOG, 0, "asyc task:{} use time:{}, DEAD CYCLE in the actor:{} actorId:{}, the system will kill the lua func", taskName, useTime, GetComponentName(), GetActorId());
			int mask = LUA_MASKCALL | LUA_MASKRET | LUA_MASKLINE | LUA_MASKCOUNT;
			lua_sethook(GetLuaState(), TimeOutBreak, mask, 1);
		}
	}

	/*
		主线程执行
	*/
	virtual void HandleTaskTimeOut(const std::string& taskName, uint64_t useTime)
	{
		if (!m_pPluginManager->IsLoadAllServer() && useTime > 5000)
		{
			if (taskName == "WorkTask_Load" || taskName == "ServerLoopTask_Load" || taskName == "ServerLoopTask_init" || taskName == "TcpMsgTask_Load")
			{
				return;
			}
			NFLogWarning(NF_LOG_SYSTEMLOG, 0, "asyc task:{} use time:{}, may be dead cycle in the actor:{} actorId:{}", taskName, useTime, GetComponentName(), GetActorId());
		}
	}
public:
	virtual uint32_t AddTimer(const std::string& luaFunc, uint64_t nInterVal, uint32_t nCallCount, const NFLuaRef& dataStr);
	virtual uint32_t AddClocker(const std::string& luaFunc, uint64_t nStartTime, uint32_t nInterDays, uint32_t nCallCount, const NFLuaRef& dataStr);
	virtual void StopTimer(uint32_t nTimerID);
	virtual void StopClocker(uint32_t nTimerID);

	virtual void RunNetRecvLuaFunc(const std::string& luaFunc, const uint32_t unLinkId, const uint64_t valueId, const uint32_t nMsgId, const std::string& strMsg);
	virtual void RunHttpRecvLuaFunc(const std::string& luaFunc, const uint32_t unLinkId, const uint32_t requestId, const std::string& firstPath, const std::string& secondPath, const std::string& strMsg);
public:
	virtual const std::string& GetAppName() const;
	virtual int GetAppID() const;
	virtual uint64_t GetInitTime() const;
	virtual uint64_t GetNowTime() const;
	virtual uint64_t GetMsecTime() const;
	virtual uint64_t GetSecTime() const;
	virtual std::string GetMD5(const std::string& str);
	virtual uint32_t GetCRC32(const std::string& s);
	virtual uint16_t GetCRC16(const std::string& s);
	virtual std::string Base64Encode(const std::string& s);
	virtual std::string Base64Decode(const std::string& s);
	virtual std::string Sha256(const std::string& s);
	virtual std::string Platfrom();
	virtual bool IsThreadModule();

	virtual void SendMsgToPlayer(uint32_t usLinkId, const uint64_t nPlayerID, const uint32_t nMsgID, const uint32_t nLen, const std::string& strData);
	virtual void SendMsgToManyPlayer(const std::vector<uint64_t>& nPlayerID, const uint32_t nMsgID, const uint32_t nLen, const std::string& strData);
	virtual void SendMsgToAllPlayer(const uint32_t nMsgID, const uint32_t nLen, const std::string& strData);
	virtual void SendMsgToMaster(uint32_t usLinkId, const uint64_t nPlayerID, const uint32_t nMsgID, const uint32_t nLen, const std::string& strData);

	virtual void SendMsgToPlayer_MainSub(uint32_t usLinkId, const uint64_t nPlayerID, const uint16_t nMainMsgID, const uint16_t nSubMsgID, const uint32_t nLen, const std::string& strData);
	virtual void SendMsgToManyPlayer_MainSub(const std::vector<uint64_t>& nPlayerID, const uint16_t nMainMsgID, const uint16_t nSubMsgID, const uint32_t nLen, const std::string& strData);
	virtual void SendMsgToAllPlayer_MainSub(const uint16_t nMainMsgID, const uint16_t nSubMsgID, const uint32_t nLen, const std::string& strData);
	virtual void SendMsgToMaster_MainSub(uint32_t usLinkId, const uint64_t nPlayerID, const uint16_t nMainMsgID, const uint16_t nSubMsgID, const uint32_t nLen, const std::string& strData);

	virtual void SendMsgToHttpServer(uint32_t servertype, const uint32_t requestId, const std::string& strMsg);

	virtual void SetDefaultLevel(uint32_t log_level);

	virtual void SetDefaultFlush(uint32_t log_level);

	virtual void LuaDebug(uint32_t logId, uint64_t guid, const std::string& str);

	virtual void LuaInfo(uint32_t logId, uint64_t guid, const std::string& str);

	virtual void LuaWarn(uint32_t logId, uint64_t guid, const std::string& str);

	virtual void LuaError(uint32_t logId, uint64_t guid, const std::string& str);

	virtual void ProcessLoop(const std::string& dataStr);

	virtual void ProcessInit(const std::string& dataStr);

	/*
		这个函数是给LUA使用的， 发送一个work给actor处理，处理可能在别的线程里
	*/
	virtual void ProcessWork(const std::string& luaFunc, const NFLuaRef& dataStr);

	virtual void ProcessTimer(uint32_t timeSec, const std::string& luaFunc, const NFLuaRef& dataStr);

	virtual void ProcessLoopTimer(uint32_t timeSec, const std::string& luaFunc, const NFLuaRef& dataStr);

	/*
		处理process work发送过来的任务
	*/
	virtual void Do_ProcessWork(const std::string& luaFunc, const std::string& dataStr);

	virtual void Do_ProcessTimer(const std::string& luaFunc, const std::string& dataStr);
	virtual void Do_ProcessRealTimer(const std::string& luaFunc, const std::string& dataStr);

	virtual void Do_ProcessLoopTimer(const std::string& luaFunc, const std::string& dataStr);

	virtual void BeginProfiler(const std::string& luaFunc);
	virtual uint64_t EndProfiler();//return this time cost time(us) 微妙

	virtual void GcStep();

	virtual void TcpSessionClose(uint64_t playerId);
	virtual void TcpSessionReport(uint64_t playerId, const std::string& ip);

	virtual void SendErrorLog(uint64_t playerId, const std::string& func_log, const std::string& errorLog, uint32_t count);

	virtual std::string HttpGet(const std::string& url);

	virtual std::string HttpGetWithHead(const std::string& url, const std::map<std::string, std::string>& xHeaders);

	virtual std::string HttpPost(const std::string& url, const std::string& postContent);

	virtual std::string HttpPostWithHead(const std::string& url, const std::string& postContent, const std::map<std::string, std::string>& xHeaders);
public:
	bool Register();
	void LoadScript();
protected:
	NFILogModule* m_pLogModule;
	NFCLuaThreadModule* m_pLuaThreadModule;
	atomic_bool m_deadCycle;
};