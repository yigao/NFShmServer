// -------------------------------------------------------------------------
//    @FileName         :    NFCLogModule.cpp
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Module           :    NFCLogModule
//    @Desc             :
// -------------------------------------------------------------------------

#include "NFComm/NFCore/NFPlatform.h"

#include "NFCLogModule.h"

#include "NFComm/NFPluginModule/NFIPluginManager.h"
#include "NFComm/NFPluginModule/NFConfigMgr.h"
#include "my_date_and_hour_file_sink.h"
#include "NFComm/NFPluginModule/NFLogMgr.h"
#include <iostream>
#include "common/spdlog/async_logger.h"
#include "common/spdlog/sinks/ansicolor_sink.h"
#include "NFComm/NFCore/NFCommon.h"
#include "NFComm/NFPluginModule/NFProtobufCommon.h"
#include "NFComm/NFPluginModule/NFIKernelModule.h"
#include "NFComm/NFCore/NFServerIDUtil.h"
#include "NFComm/NFCore/NFTime.h"


NFCLogModule::NFCLogModule(NFIPluginManager* p):NFILogModule(p)
{
	NFLogMgr::Instance()->Init(this);
#if NF_PLATFORM == NF_PLATFORM_WIN
	int proc_id = NFGetPID();
#else
    pid_t proc_id = NFGetPID();
#endif
    m_pid = NFCommon::tostr(proc_id);
    m_behaviorId = 0;

    m_logBehaviorCb.resize(NF_ST_MAX);
}

/**
* @brief 初始化log系统
*/
void NFCLogModule::InitLogSystem()
{
	//只要是为了效率，浪费点内存
	m_logInfoConfig.resize(NF_LOG_MAX_ID);
	m_logInfoConfig[NF_LOG_SYSTEMLOG].mDisplay = true;
	m_logInfoConfig[NF_LOG_SYSTEMLOG].mLogId = NF_LOG_SYSTEMLOG;
	m_logInfoConfig[NF_LOG_SYSTEMLOG].mLogName = "SystemLog";
	//Create spdlog
	try
	{
        m_logThreadPool = NF_SHARE_PTR<spdlog::details::thread_pool>(NF_NEW spdlog::details::thread_pool(1024, 1));

		CreateDefaultLogger();
        CreateBehaviorLogger();
	}
	catch (std::system_error& error)
	{
		std::cout << "Create logger failed, error = " << error.what() << std::endl;
		assert(false);
	}
}

NFCLogModule::~NFCLogModule()
{
	NFLogMgr::Instance()->UnInit();
	spdlog::drop_all();
}

bool NFCLogModule::Shut()
{
    m_logBehaviorCb.clear();
	return true;
}

bool NFCLogModule::OnReloadPlugin()
{
	SetDefaultLogConfig();
	return true;
}

void NFCLogModule::LogDefault(NF_LOG_LEVEL log_level, const NFSourceLoc& loc, uint32_t logId, uint64_t guid, const std::string& log)
{
	if (IsLogIdEnable(log_level, logId, guid))
	{
		std::string str = fmt::format("[{}:{}:{}] | [{}:{}] | {}", loc.filename, loc.line, loc.funcname, m_logInfoConfig[logId].mLogName, guid, log);
		m_defaultLogger->log((spdlog::level::level_enum)log_level, str.c_str());
	}
}

void NFCLogModule::LogBehavior(NF_SERVER_TYPES eType, proto_ff::BehaviorLogHeader& header, google::protobuf::Message& message)
{
    const google::protobuf::Descriptor *pDesc = message.GetDescriptor();
    if (pDesc == NULL) return;
    m_behaviorId++;
    header.set_bus_name(m_pPluginManager->GetBusName());
    header.set_event_id(m_pPluginManager->FindModule<NFIKernelModule>()->Get64UUID());
    header.set_sequence(m_behaviorId);
    header.set_event_time(NFTime::Now().GetFormatTime());

    NFProtobufCommon::CopyMessageByFields(&message, &header);

    std::string str = fmt::format("proc:{} msg:{}", m_pid, pDesc->name());
    NFProtobufCommon::GetMapFieldsStringFromMessage(message, str);
    m_behaviorLogger->log(spdlog::level::level_enum::err, str.c_str());

    if (eType >= 0 && eType < m_logBehaviorCb.size())
    {
        for(int i = 0; i < (int)m_logBehaviorCb[eType].size(); i++)
        {
            LOG_BEHAVIOR_CALLBAK_FUNCTOR& fun = m_logBehaviorCb[eType][i];
            if (fun)
            {
                fun(header.user_id(), &message);
            }
        }
    }
}

bool NFCLogModule::IsLogIdEnable(NF_LOG_LEVEL log_level, uint32_t logId, uint64_t guid)
{
	if (logId < m_logInfoConfig.size() && m_logInfoConfig[logId].mDisplay && m_logInfoConfig[logId].mLevel <= (uint32_t)log_level)
	{
		if (m_logInfoConfig[logId].mVecGuid.empty() || m_logInfoConfig[logId].Exist(guid))
		{
			return true;
		}
	}
	return false;
}

/**
* @brief 对外接口输出默认的LOG
*
* @param  log_level log等级
* @param  logId LOG选项ID，可以配置输出
* @param  guid 一般是玩家ID，某些情况下，只想输出一个玩家的LOG
* @param  log
* @return bool
*/
void NFCLogModule::LogDefault(NF_LOG_LEVEL log_level, uint32_t logId, uint64_t guid, const std::string& log)
{
	if (IsLogIdEnable(log_level, logId, guid))
	{
		std::string str = fmt::format("| [{}:{}] | {}", m_logInfoConfig[logId].mLogName, guid, log);
		m_defaultLogger->log((spdlog::level::level_enum)log_level, str.c_str());
	}
}

void NFCLogModule::LogOthers(uint32_t logNameId, NF_LOG_LEVEL log_level, uint32_t logId, uint64_t guid, const std::string& log)
{
	if (IsLogIdEnable(log_level, logId, guid))
	{
		auto iter = m_loggerMap.find(logNameId);
		if (iter != m_loggerMap.end())
		{
			std::string str = fmt::format("| [{}:{}] | {}", m_logInfoConfig[logId].mLogName, guid, log);
			iter->second->log((spdlog::level::level_enum)log_level, str.c_str());
		}
	}
}

void NFCLogModule::SetDefaultLevel(NF_LOG_LEVEL log_level)
{
	m_defaultLogger->set_level((spdlog::level::level_enum)(log_level));
}

void NFCLogModule::SetDefaultFlush(NF_LOG_LEVEL log_level)
{
	m_defaultLogger->flush_on((spdlog::level::level_enum)(log_level));
}

/**
* @brief 设置log的配置
*
* @param  vecLogConfig
* @return
*/
void NFCLogModule::SetDefaultLogConfig()
{
	NFLogConfig* pLogConfig = NFConfigMgr::Instance()->GetLogConfig();

	SetDefaultLevel((NF_LOG_LEVEL)pLogConfig->mLogLevel);
	SetDefaultFlush((NF_LOG_LEVEL)pLogConfig->mLogFlushLevel);

	for(size_t i = 0; i < pLogConfig->mLineConfigList.size(); i++)
	{
		LogInfoConfig& config = pLogConfig->mLineConfigList[i];
		if (config.mLogId < m_logInfoConfig.size())
		{
			m_logInfoConfig[config.mLogId] = config;
		}
	}
}

void NFCLogModule::CreateDefaultLogger()
{
	std::vector<spdlog::sink_ptr> sinks_vec;
	std::string log_name = NF_FORMAT("{}{}{}{}{}.log", m_pPluginManager->GetLogPath(), spdlog::details::os::folder_sep, m_pPluginManager->GetAppName() + "_" + m_pPluginManager->GetBusName(), spdlog::details::os::folder_sep, m_pPluginManager->GetAppName());
	auto date_and_hour_sink = std::make_shared<spdlog::sinks::my_date_and_hour_file_sink_mt>(log_name);

#if NF_PLATFORM == NF_PLATFORM_WIN
	auto color_sink = std::make_shared<spdlog::sinks::wincolor_stdout_sink_mt>();
	sinks_vec.push_back(color_sink);
#else
	if (m_pPluginManager->IsDaemon() == false)
	{
		auto color_sink = std::make_shared<spdlog::sinks::ansicolor_stdout_sink_mt>();
		sinks_vec.push_back(color_sink);
	}
#endif

	sinks_vec.push_back(date_and_hour_sink);
#ifdef NF_DEBUG_MODE
	m_defaultLogger = std::make_shared<spdlog::logger>(m_pPluginManager->GetAppName(), std::begin(sinks_vec), std::end(sinks_vec));
	//m_defaultLogger = std::make_shared<spdlog::async_logger>(m_pPluginManager->GetAppName(), std::begin(sinks_vec), std::end(sinks_vec), m_logThreadPool);
#else
	m_defaultLogger = std::make_shared<spdlog::async_logger>(m_pPluginManager->GetAppName(), std::begin(sinks_vec), std::end(sinks_vec), m_logThreadPool);
#endif

	m_defaultLogger->set_level(spdlog::level::level_enum::trace);

	m_defaultLogger->set_pattern("%^[%l | %Y-%m-%d %H:%M:%S.%e] | %v%$");

	m_defaultLogger->flush_on(spdlog::level::debug);

	spdlog::register_logger(m_defaultLogger);
}

/*创建同步LOG系统*/
void NFCLogModule::CreateOthersLogger(uint32_t logNameId, const std::string& logName, bool async)
{
	std::vector<spdlog::sink_ptr> sinks_vec;
	std::string log_name = NF_FORMAT("{}{}{}{}{}.log", m_pPluginManager->GetLogPath(), spdlog::details::os::folder_sep, m_pPluginManager->GetAppName() + "_" + m_pPluginManager->GetBusName() + "_" + logName, spdlog::details::os::folder_sep, logName);
	auto date_and_hour_sink = std::make_shared<spdlog::sinks::my_date_and_hour_file_sink_mt>(log_name);

#if NF_PLATFORM == NF_PLATFORM_WIN
	auto color_sink = std::make_shared<spdlog::sinks::wincolor_stdout_sink_mt>();
	sinks_vec.push_back(color_sink);
#else
	if (m_pPluginManager->IsDaemon() == false)
	{
		auto color_sink = std::make_shared<spdlog::sinks::ansicolor_stdout_sink_mt>();
		sinks_vec.push_back(color_sink);
	}
#endif

	sinks_vec.push_back(date_and_hour_sink);

	std::shared_ptr<spdlog::logger> pLogger;
	if (async)
	{
		pLogger = std::make_shared<spdlog::async_logger>(m_pPluginManager->GetAppName() + "_" + logName, std::begin(sinks_vec), std::end(sinks_vec), m_logThreadPool);
	}
	else
	{
		pLogger = std::make_shared<spdlog::logger>(m_pPluginManager->GetAppName() + "_" + logName, std::begin(sinks_vec), std::end(sinks_vec));
	}

	pLogger->set_level(spdlog::level::level_enum::trace);

	pLogger->set_pattern("%^[%l | %Y-%m-%d %H:%M:%S.%e] | %v%$");

	pLogger->flush_on(spdlog::level::debug);

	spdlog::register_logger(pLogger);
	m_loggerMap.emplace(logNameId, pLogger);
}

void NFCLogModule::CreateBehaviorLogger()
{
    std::vector<spdlog::sink_ptr> sinks_vec;
    std::string log_name = NF_FORMAT("{}{}{}{}Behavior_{}.log", m_pPluginManager->GetLogPath(), spdlog::details::os::folder_sep, m_pPluginManager->GetAppName() + "_" + m_pPluginManager->GetBusName(), spdlog::details::os::folder_sep, m_pPluginManager->GetAppName());
    auto date_and_hour_sink = std::make_shared<spdlog::sinks::my_date_and_hour_file_sink_mt>(log_name);

#if NF_PLATFORM == NF_PLATFORM_WIN
    auto color_sink = std::make_shared<spdlog::sinks::wincolor_stdout_sink_mt>();
	sinks_vec.push_back(color_sink);
#else
    if (m_pPluginManager->IsDaemon() == false)
    {
        auto color_sink = std::make_shared<spdlog::sinks::ansicolor_stdout_sink_mt>();
        sinks_vec.push_back(color_sink);
    }
#endif

    sinks_vec.push_back(date_and_hour_sink);
    std::shared_ptr<spdlog::logger> pLogger;
    pLogger = std::make_shared<spdlog::logger>(m_pPluginManager->GetAppName() + "_behavior", std::begin(sinks_vec), std::end(sinks_vec));

#ifdef NF_DEBUG_MODE
    pLogger = std::make_shared<spdlog::logger>(m_pPluginManager->GetAppName() + "_behavior", std::begin(sinks_vec), std::end(sinks_vec));
#else
    pLogger = std::make_shared<spdlog::async_logger>(m_pPluginManager->GetAppName() + "_behavior", std::begin(sinks_vec), std::end(sinks_vec), m_logThreadPool);
#endif

    pLogger->set_level(spdlog::level::level_enum::err);

    pLogger->set_pattern("%^[%Y%m%d %H:%M:%S] %v%$");

    pLogger->flush_on(spdlog::level::err);

    spdlog::register_logger(pLogger);

    m_behaviorLogger = pLogger;
}

int NFCLogModule::AddLogBehaviorCB(NF_SERVER_TYPES eType, const LOG_BEHAVIOR_CALLBAK_FUNCTOR& callbak)
{
    if (eType >= 0 && eType < m_logBehaviorCb.size())
    {
        m_logBehaviorCb[eType].push_back(callbak);
    }
    return 0;
}