// -------------------------------------------------------------------------
//    @FileName         :    NFLogMgr.h
//    @Author           :    Gao.Yi
//    @Date             :   2022-09-18
//    @Email			:    445267987@qq.com
//    @Module           :    NFPluginModule
//
// -------------------------------------------------------------------------
#pragma once

#include "NFComm/NFCore/NFSingleton.hpp"
#include "NFComm/NFCore/NFPlatform.h"
#include "common/spdlog/fmt/fmt.h"
#include "NFILogModule.h"
#include "NFComm/NFCore/NFSnprintf.h"
#include "NFComm/NFCore/NFTime.h"

namespace spdlog
{
    class logger;
}

class NFLogMgr : public NFSingleton<NFLogMgr>
{
public:
	NFLogMgr();
	virtual ~NFLogMgr();
public:
	bool Init(NFILogModule* pSpdlogModule = nullptr);
	void UnInit();
public:
	/**
	* @brief 对外接口输出默认的LOG
	*
	* @param  log_level log等级
	* @param  function log所在函数
	* @param  line log所在文件行
	* @return bool
	*/
	template<typename... ARGS>
	void Log(uint32_t log_level, const NFSourceLoc& loc, uint32_t logId, uint64_t guid, const char* my_fmt, const ARGS& ... args)
	{
		if (m_pLogModule)
		{
            try {
                std::string str = fmt::format(my_fmt, args...);
                m_pLogModule->LogDefault((NF_LOG_LEVEL)log_level, loc, logId, guid, str);
            }
            catch (fmt::v5::format_error& error) {
                std::string str = fmt::format("log format error------------{} error:{}", my_fmt, error.what());
                m_pLogModule->LogDefault((NF_LOG_LEVEL)NLL_ERROR_NORMAL, loc, logId, guid, str);
            }
		}
		else
        {
            CreateNoLog();
            try {
                std::string str = fmt::format(my_fmt, args...);
                NoLog((NF_LOG_LEVEL)log_level, loc, logId, guid, str);
            }
            catch (fmt::v5::format_error& error) {
                std::string str = fmt::format("log format error------------{} error:{}", my_fmt, error.what());
                NoLog((NF_LOG_LEVEL)NLL_ERROR_NORMAL, loc, logId, guid, str);
            }
        }
	}

    virtual void LogDefault(NF_LOG_LEVEL log_level, const NFSourceLoc& loc, uint32_t logId, uint64_t guid, const std::string& log)
    {
        m_pLogModule->LogDefault((NF_LOG_LEVEL)log_level, loc, logId, guid, log);
    }

    virtual void LogFormat(NF_LOG_LEVEL log_level, const NFSourceLoc& loc, uint32_t logId, uint64_t guid, const char *fmt, ...)
    {
        va_list ap;
        va_start(ap, fmt);
        NFSafeVsnprintf(m_format, sizeof(m_format), fmt, ap);  // 调用 NFSafeVsnprintf
        va_end(ap);
        m_pLogModule->LogDefault((NF_LOG_LEVEL)log_level, loc, logId, guid, m_format);
    }

    /**
    * @brief 行为日志LOG
    *
    * @param  message
    * @return bool
    */
    virtual void LogBehavior(NF_SERVER_TYPES eType, uint64_t userId, const std::string& userName, google::protobuf::Message& message)
    {
        if (m_pLogModule)
        {
            proto_ff::BehaviorLogHeader header;
            header.set_user_id(userId);
            header.set_user_name(userName);
            return m_pLogModule->LogBehavior(eType, header, message);
        }
    }

    /**
    * @brief 行为日志LOG
    *
    * @param  message
    * @return bool
    */
    virtual void LogBehavior(NF_SERVER_TYPES eType, proto_ff::BehaviorLogHeader& header, google::protobuf::Message& message)
    {
        if (m_pLogModule)
        {
            return m_pLogModule->LogBehavior(eType, header, message);
        }
    }

	virtual bool IsLogIdEnable(NF_LOG_LEVEL log_level, uint32_t logId, uint64_t guid)
	{
		if (m_pLogModule)
		{
			return m_pLogModule->IsLogIdEnable(log_level, logId, guid);
		}
		return false;
	}

	/**
	* @brief 设置默认的LOG的输出等级
	*
	* @param  log_level log等级
	* @return bool
	*/
	void SetDefaultLevel(NF_LOG_LEVEL log_level);

	/**
	* @brief 设置默认的LOG的刷新等级
	*
	* @param  log_level log等级
	* @return bool
	*/
	void SetDefaultFlush(NF_LOG_LEVEL log_level);

    template<typename BaseType>
    bool AddLogBehaviorCB(NF_SERVER_TYPES eType, BaseType* pBase, int (BaseType::*handleRecieve)(uint64_t userId, const google::protobuf::Message* message))
    {
        if (m_pLogModule)
        {
            LOG_BEHAVIOR_CALLBAK_FUNCTOR functor = std::bind(handleRecieve, pBase, std::placeholders::_1, std::placeholders::_2);
            m_pLogModule->AddLogBehaviorCB(eType, functor);
        }
        return true;
    }

    void CreateNoLog();
    void NoLog(NF_LOG_LEVEL log_level, const NFSourceLoc& loc, uint32_t logId, uint64_t guid, const std::string& log);
protected:
    char m_format[1024];
	NFILogModule* m_pLogModule;
    std::shared_ptr<spdlog::logger> m_noLogger;
};

#define NFLogTrace(logID, guid, format, ...) NFLogMgr::Instance()->Log(NLL_TRACE_NORMAL, NFSourceLoc{NFLOG_FILE_BASENAME(__FILE__), __LINE__, NF_MACRO_FUNCTION}, logID, guid, format, ##__VA_ARGS__);
#define NFLogDebug(logID, guid, format, ...) NFLogMgr::Instance()->Log(NLL_DEBUG_NORMAL, NFSourceLoc{NFLOG_FILE_BASENAME(__FILE__), __LINE__, NF_MACRO_FUNCTION}, logID, guid, format, ##__VA_ARGS__);
#define NFLogInfo(logID, guid, format, ...) NFLogMgr::Instance()->Log(NLL_INFO_NORMAL, NFSourceLoc{NFLOG_FILE_BASENAME(__FILE__), __LINE__, NF_MACRO_FUNCTION}, logID, guid, format, ##__VA_ARGS__);
#define NFLogWarning(logID, guid, format, ...) NFLogMgr::Instance()->Log(NLL_WARING_NORMAL, NFSourceLoc{NFLOG_FILE_BASENAME(__FILE__), __LINE__, NF_MACRO_FUNCTION}, logID, guid, format, ##__VA_ARGS__);
#define NFLogError(logID, guid, format, ...) NFLogMgr::Instance()->Log(NLL_ERROR_NORMAL, NFSourceLoc{NFLOG_FILE_BASENAME(__FILE__), __LINE__, NF_MACRO_FUNCTION}, logID, guid, format, ##__VA_ARGS__);
#define NFLogFatal(logID, guid, format, ...) NFLogMgr::Instance()->Log(NLL_CRITICAL_NORMAL, NFSourceLoc{NFLOG_FILE_BASENAME(__FILE__), __LINE__, NF_MACRO_FUNCTION}, logID, guid, format, ##__VA_ARGS__);

#define NFLogTraceFmt(logID, guid, format, ...) NFLogMgr::Instance()->LogFormat(NLL_TRACE_NORMAL, NFSourceLoc{NFLOG_FILE_BASENAME(__FILE__), __LINE__, NF_MACRO_FUNCTION}, logID, guid, format, ##__VA_ARGS__);
#define NFLogDebugFmt(logID, guid, format, ...) NFLogMgr::Instance()->LogFormat(NLL_DEBUG_NORMAL, NFSourceLoc{NFLOG_FILE_BASENAME(__FILE__), __LINE__, NF_MACRO_FUNCTION}, logID, guid, format, ##__VA_ARGS__);
#define NFLogInfoFmt(logID, guid, format, ...) NFLogMgr::Instance()->LogFormat(NLL_INFO_NORMAL, NFSourceLoc{NFLOG_FILE_BASENAME(__FILE__), __LINE__, NF_MACRO_FUNCTION}, logID, guid, format, ##__VA_ARGS__);
#define NFLogWarningFmt(logID, guid, format, ...) NFLogMgr::Instance()->LogFormat(NLL_WARING_NORMAL, NFSourceLoc{NFLOG_FILE_BASENAME(__FILE__), __LINE__, NF_MACRO_FUNCTION}, logID, guid, format, ##__VA_ARGS__);
#define NFLogErrorFmt(logID, guid, format, ...) NFLogMgr::Instance()->LogFormat(NLL_ERROR_NORMAL, NFSourceLoc{NFLOG_FILE_BASENAME(__FILE__), __LINE__, NF_MACRO_FUNCTION}, logID, guid, format, ##__VA_ARGS__);
#define NFLogFatalFmt(logID, guid, format, ...) NFLogMgr::Instance()->LogFormat(NLL_CRITICAL_NORMAL, NFSourceLoc{NFLOG_FILE_BASENAME(__FILE__), __LINE__, NF_MACRO_FUNCTION}, logID, guid, format, ##__VA_ARGS__);

#define NFLogTraceEnable(logID, guid) NFLogMgr::Instance()->IsLogIdEnable(NLL_TRACE_NORMAL, logID, guid)
#define NFLogDebugEnable(logID, guid) NFLogMgr::Instance()->IsLogIdEnable(NLL_DEBUG_NORMAL, logID, guid)
#define NFLogInfoEnable(logID, guid) NFLogMgr::Instance()->IsLogIdEnable(NLL_INFO_NORMAL, logID, guid)
#define NFLogWarningEnable(logID, guid) NFLogMgr::Instance()->IsLogIdEnable(NLL_WARING_NORMAL, logID, guid)
#define NFLogErrorEnable(logID, guid) NFLogMgr::Instance()->IsLogIdEnable(NLL_ERROR_NORMAL, logID, guid)
#define NFLogFatalEnable(logID, guid) NFLogMgr::Instance()->IsLogIdEnable(NLL_CRITICAL_NORMAL, logID, guid)

#define NFLogTraceIf(CONDITION, logID, guid, format, ...) 		if(CONDITION) NFLogTrace(logID, guid, format, ##__VA_ARGS__)
#define NFLogDebugIf(CONDITION, logID, guid, format, ...) 		if(CONDITION) NFLogDebug(logID, guid, format, ##__VA_ARGS__)
#define NFLogInfoIf(CONDITION, logID, guid, format, ...) 		if(CONDITION) NFLogInfo(logID, guid, format, ##__VA_ARGS__)
#define NFLogWarningIf(CONDITION, logID, guid, format, ...) 	if(CONDITION) NFLogWarning(logID, guid, format, ##__VA_ARGS__)
#define NFLogErrorIf(CONDITION, logID, guid, format, ...) 		if(CONDITION) NFLogError(logID, guid, format, ##__VA_ARGS__)
#define NFLogFatalIf(CONDITION, logID, guid, format, ...) 		if(CONDITION) NFLogFatal(logID, guid, format, ##__VA_ARGS__)

#define NFLogBehavior(serverType, userId, userName, message) NFLogMgr::Instance()->LogBehavior(serverType, userId, userName, message);

