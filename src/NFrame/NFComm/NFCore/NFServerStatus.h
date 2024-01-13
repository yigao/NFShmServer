// -------------------------------------------------------------------------
//    @FileName         :    NFServerStatus.h
//    @Author           :    Gao.Yi
//    @Date             :   2022-09-18
//    @Email			:    445267987@qq.com
//    @Module           :    NFServerStatus
//
// -------------------------------------------------------------------------

#pragma once

#include <atomic>
#include <string>
#include "NFComm/NFCore/NFPlatform.h"

class _NFExport NFServerStatus {
public:
	enum Status {
		kNull = 0,
		kInitializing = 1,
		kInitialized = 2,
		kStarting = 3,
		kRunning = 4,
		kStopping = 5,
		kStopped = 6,
	};

	enum SubStatus {
		kSubStatusNull = 0,
		kStoppingListener = 1,
		kStoppingThreadPool = 2,
	};

	bool IsRunning() const {
		return m_playerStatus.load() == kRunning;
	}

	bool IsStopped() const {
		return m_playerStatus.load() == kStopped;
	}

	bool IsStopping() const {
		return m_playerStatus.load() == kStopping;
	}

protected:
	std::atomic<Status> m_playerStatus = { kNull };
	std::atomic<SubStatus> m_substatus = { kSubStatusNull };
};
