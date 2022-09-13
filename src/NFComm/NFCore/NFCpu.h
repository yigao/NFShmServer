// -------------------------------------------------------------------------
//    @FileName         :    NFCpu.h
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFCore
//
// -------------------------------------------------------------------------

#pragma once

#include "NFPlatform.h"

#if NF_PLATFORM == NF_PLATFORM_WIN
#include <windows.h>
#include <Psapi.h>
#include <conio.h>
#include <stdio.h>

//在windows下获得CPU使用率的方法
class CpuUsage
{
public:
	CpuUsage() : IsFirstRun(true), m_nCpuUsage(-1), m_lRunCount(0)
	{
		ZeroMemory(&m_ftPrevSysKernel, sizeof(FILETIME));
		ZeroMemory(&m_ftPrevSysUser, sizeof(FILETIME));

		ZeroMemory(&m_ftPrevProcKernel, sizeof(FILETIME));
		ZeroMemory(&m_ftPrevProcUser, sizeof(FILETIME));
	}

	short GetUsage()
	{
		short nCpuCopy = m_nCpuUsage;

		if (::InterlockedIncrement(&m_lRunCount) == 1)
		{
			FILETIME ftSysIdle, ftSysKernel, ftSysUser;
			FILETIME ftProcCreation, ftProcExit, ftProcKernel, ftProcUser;

			if (!GetSystemTimes(&ftSysIdle, &ftSysKernel, &ftSysUser) ||
				!GetProcessTimes(GetCurrentProcess(), &ftProcCreation, &ftProcExit, &ftProcKernel, &ftProcUser))
			{
				::InterlockedDecrement(&m_lRunCount);
				return nCpuCopy;
			}

			if (!IsFirstRun)
			{
				/*
				CPU usage is calculated by getting the total amount of time the system has operated
				since the last measurement (made up of kernel + user) and the total
				amount of time the process has run (kernel + user).
				*/
				ULONGLONG ftSysKernelDiff = SubtractTimes(ftSysKernel, m_ftPrevSysKernel);
				ULONGLONG ftSysUserDiff = SubtractTimes(ftSysUser, m_ftPrevSysUser);

				ULONGLONG ftProcKernelDiff = SubtractTimes(ftProcKernel, m_ftPrevProcKernel);
				ULONGLONG ftProcUserDiff = SubtractTimes(ftProcUser, m_ftPrevProcUser);

				ULONGLONG nTotalSys = ftSysKernelDiff + ftSysUserDiff;
				ULONGLONG nTotalProc = ftProcKernelDiff + ftProcUserDiff;

				if (nTotalSys > 0)
				{
					m_nCpuUsage = static_cast<short>((100.0 * nTotalProc) / nTotalSys);
				}
			}

			m_ftPrevSysKernel = ftSysKernel;
			m_ftPrevSysUser = ftSysUser;
			m_ftPrevProcKernel = ftProcKernel;
			m_ftPrevProcUser = ftProcUser;

			nCpuCopy = m_nCpuUsage;
		}

		IsFirstRun = false;
		::InterlockedDecrement(&m_lRunCount);

		return nCpuCopy;
	}

private:
	static ULONGLONG SubtractTimes(const FILETIME& ftA, const FILETIME& ftB)
	{
		LARGE_INTEGER a, b;
		a.LowPart = ftA.dwLowDateTime;
		a.HighPart = ftA.dwHighDateTime;

		b.LowPart = ftB.dwLowDateTime;
		b.HighPart = ftB.dwHighDateTime;

		return a.QuadPart - b.QuadPart;
	}

	bool IsFirstRun;
	short m_nCpuUsage;

	//system total times
	FILETIME m_ftPrevSysKernel;
	FILETIME m_ftPrevSysUser;

	//process times
	FILETIME m_ftPrevProcKernel;
	FILETIME m_ftPrevProcUser;

	volatile LONG m_lRunCount;
};
#endif

class NFCpu
{
public:
	/// @brief 获取当前进程的cpu使用时间
	static long long GetCurCpuTime();

	/// @brief 获取整个系统的cpu使用时间
	static long long GetTotalCpuTime();

	/// @brief 计算进程的cpu使用率
	/// @param cur_cpu_time_start 当前进程cpu使用时间段-start
	/// @param cur_cpu_time_stop 当前进程cpu使用时间段-stop
	/// @param total_cpu_time_start 整个系统cpu使用时间段-start
	/// @param total_cpu_time_start 整个系统cpu使用时间段-stop
	static float CalculateCurCpuUseage(long long cur_cpu_time_start, long long cur_cpu_time_stop,
	                                   long long total_cpu_time_start, long long total_cpu_time_stop);

	/// @brief 获取进程当前内存使用情况
	/// @param vm_size_kb 输出参数，虚存，单位为K
	/// @param rss_size_kb 输出参数，物理内存，单位为K
	static int GetCurMemoryUsage(int* vm_size_kb, int* rss_size_kb);

	/// @brief 计算进程的cpu使用率
	static int GetCurCpuUseage();

	/// @brief 获取进程当前内存使用情况
	static int GetCurMemorySize();
};

