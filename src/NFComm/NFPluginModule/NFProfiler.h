// -------------------------------------------------------------------------
//    @FileName         :    NFProfiler.h
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFCore
//
// -------------------------------------------------------------------------

#ifndef NF_PROFILER_H
#define NF_PROFILER_H

#include <time.h>
#include <string.h>
#include <string>
#include <vector>
#include "NFComm/NFCore/NFPlatform.h"
#include <map>
#include <atomic>

#ifdef _MSC_VER
#include <windows.h>
#endif

const unsigned PROFILER_MAX_TIMER_COUNT = 4096;
const unsigned PROFILER_MAX_STACK_LEVEL = 20;
const unsigned PROFILER_MAX_TIMER_NAME_LEN = 64;

const int PROFILER_NO_PARENT = -1;
const int PROFILER_MULTI_PARENT = -2;

struct PROFILE_TIMER
{
	int index;
	int parentIndex;
	int level;
	unsigned sampleCount;
	long long beginTime;
	long long sampleTime; // in nanosecond
	char name[PROFILER_MAX_TIMER_NAME_LEN];

	PROFILE_TIMER(const char* _name)
	{
		Clear();
		strncpy(name, _name, sizeof(name));
		name[sizeof(name) - 1] = '\0';
	}

	PROFILE_TIMER() : PROFILE_TIMER("")
	{
	}

	void SetName(const char* _name)
	{
		strncpy(name, _name, sizeof(name));
		name[sizeof(name) - 1] = '\0';
	}

	void Clear()
	{
		index = -1;
		parentIndex = PROFILER_NO_PARENT;
		level = -1;

		memset(&beginTime, 0, sizeof(beginTime));
		sampleCount = 0;
		sampleTime = 0;
	}
};

struct CALL_TREE_NODE
{
	const char* name;
	int parentIndex;
	unsigned sampleCount;
	long long sampleTime;

	CALL_TREE_NODE* firstChild;
	CALL_TREE_NODE* nextBrather;
};

class NFProfiler
{
public:
	NFProfiler()
	{
		mTimerCount = 0;
		mStackLevel = 0;
		mIsOpenProfiler = true;
		mProfileThreadID = 0;
		for (int i = 0; i < static_cast<int>(PROFILER_MAX_TIMER_COUNT); i++)
		{
			mTimers[i] = nullptr;
		}
		for (int i = 0; i < static_cast<int>(PROFILER_MAX_STACK_LEVEL); i++)
		{
			mStacks[i] = nullptr;
		}
	}

	virtual ~NFProfiler()
	{
		for (auto iter = m_funcNameProfiler.begin(); iter != m_funcNameProfiler.end(); iter++)
		{
			NF_SAFE_DELETE(iter->second);
		}
		m_funcNameProfiler.clear();
	}

public:
	// pointer to timer must keep always valid, normally should be a static variable.
	void BeginProfiler(PROFILE_TIMER* timer);
	void BeginProfiler(const std::string& luaFunc);
	uint64_t EndProfiler(); //return this time cost time(us) ОўГо
	void SetOpenProfiler(bool b) { mIsOpenProfiler = b; }
	bool IsOpenProfiler() const { return mIsOpenProfiler; }
public:
	// for support profile main thread in multi thread program(ignore another, only main thread)
	void SetProfilerThreadID();
	void BeginProfilerWithThreadCheck(PROFILE_TIMER* timer);
	void EndProfilerWithThreadCheck();
	void ResetAllProfilerTimer();
public:
	std::string OutputTopProfilerTimer();
protected:
	void AddChildWithSort(CALL_TREE_NODE* parent, CALL_TREE_NODE* child);
	bool BuildCallTree(CALL_TREE_NODE* head, std::vector<CALL_TREE_NODE>* callTree);
	void OutputNode(const CALL_TREE_NODE& node, bool showSplitLine, long long totalTime, int level, std::string& report);
	void OutputCallTree(const CALL_TREE_NODE& node, long long totalTime, long long minShowTime, int level, std::string& report);
private:
	atomic_bool mIsOpenProfiler;
	NF_THREAD_ID mProfileThreadID;
private:
	unsigned mTimerCount;
	PROFILE_TIMER* mTimers[PROFILER_MAX_TIMER_COUNT];

	unsigned mStackLevel;
	PROFILE_TIMER* mStacks[PROFILER_MAX_STACK_LEVEL];

	std::map<std::string, PROFILE_TIMER*> m_funcNameProfiler;
};

#endif // NF_PROFILER_H


