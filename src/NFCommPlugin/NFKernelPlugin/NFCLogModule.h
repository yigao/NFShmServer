// -------------------------------------------------------------------------
//    @FileName         :    NFCLogModule.h
//    @Author           :    Yi.Gao
//    @Date             :   xxxx-xx-xx
//    @Module           :    NFCLogModule
//    @Desc             :
// -------------------------------------------------------------------------
#pragma once

#include "NFComm/NFPluginModule/NFILogModule.h"
#include "NFComm/NFCore/NFPlatform.h"

#include "common/spdlog/spdlog.h"
#include "common/spdlog/fmt/fmt.h"
#include <unordered_map>
#include <unordered_set>
#include <vector>


class NFCLogModule : public NFILogModule
{
public:
	NFCLogModule(NFIPluginManager* p);

	virtual ~NFCLogModule();

	virtual bool Shut() override;
	virtual bool OnReloadPlugin() override;

	/**
	* @brief 初始化log系统
	*/
	virtual void InitLogSystem() override;
	/**
	* @brief 对外接口输出默认的LOG
	*
	* @param  log_level log等级
	* @param  function 
	* @param  line
	* @param  logId LOG选项ID，可以配置输出
	* @param  guid 一般是玩家ID，某些情况下，只想输出一个玩家的LOG
	* @param  log
	* @return void
	*/
	virtual void LogDefault(NF_LOG_LEVEL log_level, const NFSourceLoc& loc, uint32_t logId, uint64_t guid, const std::string& log);

	/**
	* @brief 是否输出对应等级的logId的log
	*
	* @param  log_level log等级
	* @param  logId LOG选项ID，可以配置输出
	* @param  guid 一般是玩家ID，某些情况下，只想输出一个玩家的LOG
	* @return bool
	*/
	virtual bool IsLogIdEnable(NF_LOG_LEVEL log_level, uint32_t logId, uint64_t guid);

	/**
	* @brief 对外接口输出默认的LOG
	*
	* @param  log_level log等级
	* @param  logId LOG选项ID，可以配置输出
	* @param  guid 一般是玩家ID，某些情况下，只想输出一个玩家的LOG
	* @param  log
	* @return bool
	*/
	virtual void LogDefault(NF_LOG_LEVEL log_level, uint32_t logId, uint64_t guid, const std::string& log);


    /**
    * @brief 行为日志LOG
    *
    * @param  message
    * @return bool
    */
	virtual void LogBehavior(NF_SERVER_TYPES eType, proto_ff::BehaviorLogHeader& header, google::protobuf::Message& message);

	/**
	* @brief 设置默认的LOG的输出等级
	*
	* @param  log_level log等级
	* @return bool
	*/
	virtual void SetDefaultLevel(NF_LOG_LEVEL log_level);

	/**
	* @brief 设置默认的LOG的刷新等级
	*
	* @param  log_level log等级
	* @return bool
	*/
	virtual void SetDefaultFlush(NF_LOG_LEVEL log_level);

	/**
	* @brief 设置log的配置
	*
	* @param  vecLogConfig
	* @return
	*/
	virtual void SetDefaultLogConfig() override;

	/**
	* @brief 创建别的LOG系统
	*
	* @param  logNameId log文件唯一的ID
	* @param  logName log文件名
	* @param  async 是否异步，多线程
	* @return bool
	*/
	virtual void CreateOthersLogger(uint32_t logNameId, const std::string& logName, bool async);

    /**
    * @brief 模仿腾讯tlog系统, 用来存取特殊的数据流，比如金币日志，行为日志
    * @return bool
    */
    virtual void CreateBehaviorLogger();

	/**
	* @brief 通过logNameId，输出LOG
	*
	* @param  logNameId log文件唯一的ID
	* @param  log_level log等级
	* @param  log
	* @return bool
	*/
	virtual void LogOthers(uint32_t logNameId, NF_LOG_LEVEL log_level, uint32_t logId, uint64_t guid, const std::string& log);

    virtual int AddLogBehaviorCB(NF_SERVER_TYPES eType, const LOG_BEHAVIOR_CALLBAK_FUNCTOR& callbak) override;
protected:
	/*创建默认系统LOG系统*/
	void CreateDefaultLogger();
private:
	std::shared_ptr<spdlog::logger> m_defaultLogger;
    std::shared_ptr<spdlog::logger> m_behaviorLogger;
	std::unordered_map<uint32_t, std::shared_ptr<spdlog::logger>> m_loggerMap;
	std::vector<LogInfoConfig> m_logInfoConfig;
	NF_SHARE_PTR<spdlog::details::thread_pool> m_logThreadPool;
	std::string m_pid;
	uint64_t m_behaviorId;
    std::vector<std::vector<LOG_BEHAVIOR_CALLBAK_FUNCTOR>> m_logBehaviorCb;
};


