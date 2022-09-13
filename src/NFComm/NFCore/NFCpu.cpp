// -------------------------------------------------------------------------
//    @FileName         :    NFCpu.cpp
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFCore
//
// -------------------------------------------------------------------------

#include <errno.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>

#include "NFPlatform.h"

#if NF_PLATFORM == NF_PLATFORM_LINUX
#include <linux/limits.h>
#include <unistd.h>
#endif

#include "NFCpu.h"

// /proc/pid/stat字段定义
struct pid_stat_fields
{
	int64_t pid;
	char comm[1024];
	char state;
	int64_t ppid;
	int64_t pgrp;
	int64_t session;
	int64_t tty_nr;
	int64_t tpgid;
	int64_t flags;
	int64_t minflt;
	int64_t cminflt;
	int64_t majflt;
	int64_t cmajflt;
	int64_t utime;
	int64_t stime;
	int64_t cutime;
	int64_t cstime;
	// ...
};

// /proc/stat/cpu信息字段定义
struct cpu_stat_fields
{
	char cpu_label[16];
	int64_t user;
	int64_t nice;
	int64_t system;
	int64_t idle;
	int64_t iowait;
	int64_t irq;
	int64_t softirq;
	// ...
};

long long NFCpu::GetCurCpuTime()
{
#if NF_PLATFORM == NF_PLATFORM_LINUX
	char file_name[64] = { 0 };
	snprintf(file_name, sizeof(file_name), "/proc/%d/stat", getpid());

	FILE* pid_stat = fopen(file_name, "r");
	if (!pid_stat)
	{
		return -1;
	}

	pid_stat_fields result;
	int ret = fscanf(pid_stat, "%ld %s %c %ld %ld %ld %ld %ld %ld %ld %ld %ld %ld %ld %ld %ld %ld",
		&result.pid, result.comm, &result.state, &result.ppid, &result.pgrp, &result.session,
		&result.tty_nr, &result.tpgid, &result.flags, &result.minflt, &result.cminflt,
		&result.majflt, &result.cmajflt, &result.utime, &result.stime, &result.cutime, &result.cstime);

	fclose(pid_stat);

	if (ret <= 0)
	{
		return -1;
	}

	return result.utime + result.stime + result.cutime + result.cstime;
#else
	return 0;
#endif
}

long long NFCpu::GetTotalCpuTime()
{
#if NF_PLATFORM == NF_PLATFORM_LINUX
	char file_name[] = "/proc/stat";
	FILE* stat = fopen(file_name, "r");
	if (!stat)
	{
		return -1;
	}

	cpu_stat_fields result;
	int ret = fscanf(stat, "%s %ld %ld %ld %ld %ld %ld %ld",
		result.cpu_label, &result.user, &result.nice, &result.system, &result.idle,
		&result.iowait, &result.irq, &result.softirq);

	fclose(stat);

	if (ret <= 0)
	{
		return -1;
	}

	return result.user + result.nice + result.system + result.idle +
		result.iowait + result.irq + result.softirq;
#else
	return 0;
#endif
}

float NFCpu::CalculateCurCpuUseage(long long cur_cpu_time_start, long long cur_cpu_time_stop,
                                   long long total_cpu_time_start, long long total_cpu_time_stop)
{
#if NF_PLATFORM == NF_PLATFORM_LINUX
	long long cpu_result = total_cpu_time_stop - total_cpu_time_start;
	if (cpu_result <= 0)
	{
		return 0;
	}

	return (sysconf(_SC_NPROCESSORS_ONLN) * 100.0f * (cur_cpu_time_stop - cur_cpu_time_start)) / cpu_result;
#else
	return 0;
#endif
}

#if NF_PLATFORM == NF_PLATFORM_WIN

typedef LONG (WINAPI* PROCNTQSI)(UINT, PVOID, ULONG, PULONG);
PROCNTQSI NtQuerySystemInformation;

#endif

/// @brief 计算进程的cpu使用率
int NFCpu::GetCurCpuUseage()
{
#if NF_PLATFORM == NF_PLATFORM_WIN
	CpuUsage objCpu;

	return objCpu.GetUsage();
#else
	return 0;
#endif
}

/// @brief 获取进程当前内存使用情况
int NFCpu::GetCurMemorySize()
{
#if NF_PLATFORM == NF_PLATFORM_WIN
	PROCESS_MEMORY_COUNTERS pmc;

	if (::GetProcessMemoryInfo(::GetCurrentProcess(), &pmc, sizeof(pmc)))
	{
		int nWorkSize = static_cast<int>(pmc.WorkingSetSize);
		int nPageSize = static_cast<int>(pmc.PagefileUsage);
		return nWorkSize + nPageSize;
	}

	return -1;
#else
	return 0;
#endif
}

int NFCpu::GetCurMemoryUsage(int* vm_size_kb, int* rss_size_kb)
{
#if NF_PLATFORM == NF_PLATFORM_LINUX
	if (!vm_size_kb || !rss_size_kb)
	{
		return -1;
	}

	char file_name[64] = { 0 };
	snprintf(file_name, sizeof(file_name), "/proc/%d/status", getpid());

	FILE* pid_status = fopen(file_name, "r");
	if (!pid_status)
	{
		return -1;
	}

	int ret = 0;
	char line[256] = { 0 };
	char tmp[32] = { 0 };
	fseek(pid_status, 0, SEEK_SET);
	for (int i = 0; i < 16; i++)
	{
		if (fgets(line, sizeof(line), pid_status) == NULL)
		{
			ret = -2;
			break;
		}

		if (strstr(line, "VmSize") != NULL)
		{
			sscanf(line, "%s %d", tmp, vm_size_kb);
		}
		else if (strstr(line, "VmRSS") != NULL)
		{
			sscanf(line, "%s %d", tmp, rss_size_kb);
		}
	}

	fclose(pid_status);

	return ret;
#else
	return 0;
#endif
}

