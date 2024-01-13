// -------------------------------------------------------------------------
//    @FileName         :    NFILogModule.h
//    @Author           :    LvSheng.Huang
//    @Date             :   2022-09-18
//    @Module           :    NFILogModule
//
// -------------------------------------------------------------------------

#ifndef NFI_LOG_MODULE_H
#define NFI_LOG_MODULE_H

#include "NFIModule.h"
#include "common/spdlog/fmt/fmt.h"
#include "google/protobuf/message.h"
#include "NFComm/NFKernelMessage/proto_kernel.pb.h"

// Get the basename of __FILE__ (at compile time if possible)
#if FMT_HAS_FEATURE(__builtin_strrchr)
#define NFLOG_STRRCHR(str, sep) __builtin_strrchr(str, sep)
#else
#define NFLOG_STRRCHR(str, sep) strrchr(str, sep)
#endif //__builtin_strrchr not defined

#ifdef _WIN32
#define NFLOG_FILE_BASENAME(file) NFLOG_STRRCHR("\\" file, '\\') + 1
#else
#define NFLOG_FILE_BASENAME(file) NFLOG_STRRCHR("/" file, '/') + 1
#endif

struct NFSourceLoc
{
	NFSourceLoc()
		: filename{""}
		, line{0}
		, funcname{""}
	{
	}
	NFSourceLoc(const char *filename, int line, const char *funcname)
		: filename{filename}
		, line{static_cast<uint32_t>(line)}
		, funcname{funcname}
	{
	}

	 bool empty() const
	{
		return line == 0;
	}
	const char *filename;
	uint32_t line;
	const char *funcname;
};


class LogInfoConfig;

enum NF_LOG_LEVEL
{
	NLL_TRACE_NORMAL = 0,
	NLL_DEBUG_NORMAL = 1,
	NLL_INFO_NORMAL = 2,
	NLL_WARING_NORMAL = 3,
	NLL_ERROR_NORMAL = 4,
	NLL_CRITICAL_NORMAL = 5,
	NLL_OFF_NORMAL = 6,
};

/**
* @brief 服务器分层架构，这里只能填写系统引擎的LOG
*
*/
enum NF_LOG_ID
{
	//0-100是基础框架层LOG
	NF_LOG_DEFAULT = 0,						//默认LOG
	NF_LOG_SYSTEMLOG = 1,					//系统LOG
	NF_LOG_RECV_MSG = 3,					//接受消息
	NF_LOG_RECV_MSG_JSON_PRINTF = 4,		//接受消息Json输出
	NF_LOG_LOAD_CONFIG = 5,				//加载配置
	NF_LOG_PROTOBUF_PARSE = 6,				//protobuf解析出错
	NF_LOG_PLUGIN_MANAGER = 7,			//引擎加载器
	NF_LOG_MAX_ID = 100, //最大LOGID
};

class NFILogModule
	: public NFIModule
{
public:
	NFILogModule(NFIPluginManager* p) :NFIModule(p)
	{

	}

	virtual ~NFILogModule()
	{

	}
	/**
	* @brief 初始化log系统
	*/
	virtual void InitLogSystem() = 0;

	/**
	* @brief 对外接口输出默认的LOG
	*
	* @param  log_level log等级
	* @param  function log所在函数
	* @param  line log所在文件行
	* @return bool
	*/
	template<typename... ARGS>
	void Log(NF_LOG_LEVEL log_level, const NFSourceLoc& loc, uint32_t logId, uint64_t guid, const char* my_fmt, const ARGS& ... args)
	{
		std::string str = fmt::format(my_fmt, args...);
		LogDefault(log_level, loc, logId, guid, str);
	}

	/**
	* @brief 对外接口输出默认的LOG
	*
	* @param  log_level log等级
	* @param  function
	* @param  line
	* @param  logId LOG选项ID，可以配置输出
	* @param  guid 一般是玩家ID，某些情况下，只想输出一个玩家的LOG
	* @param  log
	* @return bool
	*/
	virtual void LogDefault(NF_LOG_LEVEL log_level, const NFSourceLoc& loc, uint32_t logId, uint64_t guid, const std::string& log) = 0;

    /**
    * @brief 行为日志LOG
    *
    * @param  message
    * @return bool
    */
    virtual void LogBehavior(NF_SERVER_TYPES eType, proto_ff::BehaviorLogHeader& header, google::protobuf::Message& message) = 0;

	/**
	* @brief 对外接口输出默认的LOG
	*
	* @param  log_level log等级
	* @param  logId LOG选项ID，可以配置输出
	* @param  guid 一般是玩家ID，某些情况下，只想输出一个玩家的LOG
	* @param  log
	* @return bool
	*/
	virtual void LogDefault(NF_LOG_LEVEL log_level, uint32_t logId, uint64_t guid, const std::string& log) = 0;

	/**
	* @brief 是否输出对应等级的logId的log
	*
	* @param  log_level log等级
	* @param  logId LOG选项ID，可以配置输出
	* @param  guid 一般是玩家ID，某些情况下，只想输出一个玩家的LOG
	* @return bool
	*/
	virtual bool IsLogIdEnable(NF_LOG_LEVEL log_level, uint32_t logId, uint64_t guid) = 0;

	/**
	* @brief 设置默认的LOG的输出等级
	*
	* @param  log_level log等级
	* @return bool
	*/
	virtual void SetDefaultLevel(NF_LOG_LEVEL log_level) = 0;

	/**
	* @brief 设置默认的LOG的刷新等级
	*
	* @param  log_level log等级
	* @return bool
	*/
	virtual void SetDefaultFlush(NF_LOG_LEVEL log_level) = 0;

	/**
	* @brief 设置log的配置
	*
	* @param  vecLogConfig
	* @return
	*/
	virtual void SetDefaultLogConfig() = 0;

	/**
	* @brief 创建别的LOG系统
	*
	* @param  logNameId log文件唯一的ID
	* @param  logName log文件名
	* @param  async 是否异步，多线程
	* @return bool
	*/
	virtual void CreateOthersLogger(uint32_t logNameId, const std::string& logName, bool async) = 0;
	
	/**
	* @brief 通过logNameId，输出LOG
	*
	* @param  logNameId log文件唯一的ID
	* @param  log_level log等级
	* @param  log
	* @return bool
	*/
	virtual void LogOthers(uint32_t logNameId, NF_LOG_LEVEL log_level, uint32_t logId, uint64_t guid, const std::string& log) = 0;

	/**
	* @brief 用于LUA系统的LOG
	*
	* @param  logId LOG选项ID，可以配置输出
	* @param  guid 一般是玩家ID，某些情况下，只想输出一个玩家的LOG
	* @param  log
	* @return bool
	*/
	virtual void LuaDebug(uint32_t logId, uint64_t guid, const std::string& str)
	{
		std::string strInfo = fmt::format("[Lua] | {}", str);
		LogDefault(NLL_DEBUG_NORMAL, logId, guid, strInfo);
	}

	/**
	* @brief 用于LUA系统的LOG
	*
	* @param  logId LOG选项ID，可以配置输出
	* @param  guid 一般是玩家ID，某些情况下，只想输出一个玩家的LOG
	* @param  log
	* @return bool
	*/
	virtual void LuaInfo(uint32_t logId, uint64_t guid, const std::string& str)
	{
		std::string strInfo = fmt::format("[Lua] | {}", str);
		LogDefault(NLL_INFO_NORMAL, logId, guid, strInfo);
	}

	/**
	* @brief 用于LUA系统的LOG
	*
	* @param  logId LOG选项ID，可以配置输出
	* @param  guid 一般是玩家ID，某些情况下，只想输出一个玩家的LOG
	* @param  log
	* @return bool
	*/
	virtual void LuaWarn(uint32_t logId, uint64_t guid, const std::string& str)
	{
		std::string strInfo = fmt::format("[Lua] | {}", str);
		LogDefault(NLL_WARING_NORMAL, logId, guid, strInfo);
	}

	/**
	* @brief 用于LUA系统的LOG
	*
	* @param  logId LOG选项ID，可以配置输出
	* @param  guid 一般是玩家ID，某些情况下，只想输出一个玩家的LOG
	* @param  log
	* @return bool
	*/
	virtual void LuaError(uint32_t logId, uint64_t guid, const std::string& str)
	{
		std::string strInfo = fmt::format("[Lua] | {}", str);
		LogDefault(NLL_ERROR_NORMAL, logId, guid, strInfo);
	}

	virtual int AddLogBehaviorCB(NF_SERVER_TYPES eType, const LOG_BEHAVIOR_CALLBAK_FUNCTOR& callbak) = 0;
};

#endif

