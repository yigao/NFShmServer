#pragma once

#include "evpp/platform_config.h"

#ifdef __cplusplus
#define GOOGLE_GLOG_DLL_DECL           // 使用静态glog库时，必须定义这个
#define GLOG_NO_ABBREVIATED_SEVERITIES // 没这个编译会出错,传说因为和Windows.h冲突

//#include <glog/logging.h>

class EvppLog
{
public:
	EvppLog()
	{
		m_pInstance = static_cast<EvppLog*>(this);
	}

	static EvppLog* GetSingletonPtr()
	{
		if (nullptr == m_pInstance)
		{
			m_pInstance = new EvppLog;
		}

		return m_pInstance;
	}

	static EvppLog& GetSingletonRef()
	{
		return *GetSingletonPtr();
	}

	template<typename T>
	EvppLog& operator<<(const T& str)
	{
		return *this;
	}
public:
	static EvppLog* m_pInstance;
};

#ifdef GOOGLE_STRIP_LOG

#if GOOGLE_STRIP_LOG == 0
#define LOG_TRACE LOG(INFO)
#define LOG_DEBUG LOG(INFO)
#define LOG_INFO  LOG(INFO)
#define DLOG_TRACE LOG(INFO) << __PRETTY_FUNCTION__ << " this=" << this << " "
#else
#define LOG_TRACE if (false) LOG(INFO)
#define LOG_DEBUG if (false) LOG(INFO)
#define LOG_INFO  if (false) LOG(INFO)
#define DLOG_TRACE if (false) LOG(INFO)
#endif

#if GOOGLE_STRIP_LOG <= 1
#define LOG_WARN  LOG(WARNING)
#define DLOG_WARN LOG(WARNING) << __PRETTY_FUNCTION__ << " this=" << this << " "
#else
#define LOG_WARN  if (false) LOG(WARNING)
#define DLOG_WARN if (false) LOG(WARNING)
#endif

#define LOG_ERROR LOG(ERROR)
#define LOG_FATAL LOG(FATAL)

#else
#define LOG_TRACE EvppLog::GetSingletonRef()
#define LOG_DEBUG EvppLog::GetSingletonRef()
#define LOG_INFO  EvppLog::GetSingletonRef()
#define LOG_WARN  EvppLog::GetSingletonRef()
#define LOG_ERROR EvppLog::GetSingletonRef()
#define LOG_FATAL EvppLog::GetSingletonRef()
#define DLOG_TRACE EvppLog::GetSingletonRef()
#define DLOG_WARN EvppLog::GetSingletonRef()
#define CHECK_NOTnullptr(val) LOG_ERROR << "'" #val "' Must be non nullptr";
#endif
#endif // end of define __cplusplus

//#ifdef _DEBUG
//#ifdef assert
//#undef assert
//#endif
//#define assert(expr)  { if (!(expr)) { LOG_FATAL << #expr ;} }
//#endif