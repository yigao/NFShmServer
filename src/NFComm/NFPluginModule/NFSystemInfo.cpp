// -------------------------------------------------------------------------
//    @FileName         :    NFSystemInfo.cpp
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Module           :    NFSystemInfo
//    @Desc             :
// -------------------------------------------------------------------------

#include "NFSystemInfo.h"
#include <iostream>
#include "NFComm/NFPluginModule/NFLogMgr.h"
#include "NFComm/NFCore/NFMD5.h"

#ifdef __cplusplus
extern "C"
{
#endif
int sigar_net_address_to_string(sigar_t *sigar,
                                               sigar_net_address_t *address,
                                               char *addr_str);
#ifdef __cplusplus
}
#endif

NFSystemInfo::NFSystemInfo()
{
    m_sigar = NULL;
	mCpuCount = 1;
}

void NFSystemInfo::Init()
{
	sigar_open(&m_sigar);

	CountCpu();
	CountOsInfo();
	CountCurProcessBaseInfo();
}

NFSystemInfo::~NFSystemInfo()
{
	sigar_close(m_sigar);
}

uint32_t NFSystemInfo::GetProcessPid()
{
	return (uint32_t)getpid();
}

void NFSystemInfo::CountCurProcessBaseInfo()
{
	mCurProcessInfo.mPid = GetProcessPid();

	sigar_proc_exe_t exestate;
	if (sigar_proc_exe_get(m_sigar, mCurProcessInfo.mPid, &exestate) != SIGAR_OK)
	{
		//NFLogError("sigar_proc_state_get error, cur_pid:{}", mCurProcessInfo.mPid);
	}

	mCurProcessInfo.mName = exestate.name;
	mCurProcessInfo.mCwd = exestate.cwd;
}

void NFSystemInfo::CountCpu()
{
	int status = SIGAR_OK;

	sigar_cpu_list_t cpulist;

	status = sigar_cpu_list_get(m_sigar, &cpulist);

	if (status != SIGAR_OK)
	{
		mCpuCount = 1;
	}
	else
	{
		mCpuCount = cpulist.number;
		sigar_cpu_list_destroy(m_sigar, &cpulist);
	}
}

uint32_t NFSystemInfo::GetCpuCount() const
{
	return mCpuCount;
}

float NFSystemInfo::GetCurCpuPer() const
{
	return mCurProcessInfo.mCpuUsed;
}

uint64_t NFSystemInfo::GetCurMemPer() const
{
	return mCurProcessInfo.mMemUsed;
}

double NFSystemInfo::CountProcessCpuPer(uint32_t pid)
{
	sigar_proc_cpu_t cpu;
	double percent = 0;

	int status = sigar_proc_cpu_get(m_sigar, pid, &cpu);
	if (status == SIGAR_OK)
	{
		percent = double(cpu.percent) * 100.f;

#if NF_PLATFORM == NF_PLATFORM_WIN
		percent /= double(mCpuCount);
#endif
	}
	else
	{
		//NFLogError("sigar_proc_cpu_get cpu error, cur_pid:{}", pid);
	}

	return percent;
}

uint64_t NFSystemInfo::CountProcessMemPer(uint32_t pid)
{
	int status;
	uint64_t mem = 0;

	sigar_proc_mem_t proc_mem;
	status = sigar_proc_mem_get(m_sigar, pid, &proc_mem);

	if (status == SIGAR_OK)
	{
		mem = proc_mem.resident;
	}
	else
	{
		//NFLogError("sigar_proc_mem_get error, cur_pid:{}", pid);
	}
	return mem;
}

const NFMemInfo& NFSystemInfo::GetMemInfo() const
{
	return mMachineMemInfo;
}

const NFProcessInfo& NFSystemInfo::GetProcessInfo() const
{
	return mCurProcessInfo;
}

const NFOsInfo& NFSystemInfo::GetOsInfo() const
{
	return mMachineOsInfo;
}

void NFSystemInfo::CountOsInfo()
{
	sigar_sys_info_t sysInfo;
	if (sigar_sys_info_get(m_sigar, &sysInfo) != SIGAR_OK)
	{
		//NFLogError("sigar_sys_info_get error");
	}

	mMachineOsInfo.mOsName = sysInfo.name;
	mMachineOsInfo.mOsVersion = sysInfo.version;
	mMachineOsInfo.mOsArch = sysInfo.arch;
	mMachineOsInfo.mOsMachine = sysInfo.machine;
	mMachineOsInfo.mOsDescription = sysInfo.description;
	mMachineOsInfo.mPatchLevel = sysInfo.patch_level;
	mMachineOsInfo.mVendor = sysInfo.vendor;
	mMachineOsInfo.mVendorVersion = sysInfo.vendor_version;
	mMachineOsInfo.mVerdorName = sysInfo.vendor_name;
	mMachineOsInfo.mVendorCodeName = sysInfo.vendor_code_name;
    mMachineOsInfo.mLocalIp = GetLocalIp();
    mMachineOsInfo.mMacAddress = GetMacAddress();

    return;
}

std::string NFSystemInfo::GetMacAddress()
{
    sigar_net_interface_config_t netConfig;
    if (sigar_net_interface_config_get(m_sigar, NULL, &netConfig) != SIGAR_OK)
    {
        return std::string();
    }

    char name[SIGAR_FQDN_LEN];
    sigar_net_address_to_string(m_sigar, &netConfig.hwaddr, name);
    return std::string(name);
}

std::string NFSystemInfo::GetLocalIp()
{
    char name[SIGAR_FQDN_LEN];
    sigar_fqdn_get(m_sigar, name, SIGAR_FQDN_LEN);
    return std::string(name);
}

void NFSystemInfo::CountSystemInfo()
{
	CountMemInfo();
	CountCurProcessInfo();
}

void NFSystemInfo::CountCurProcessInfo()
{
	mCurProcessInfo.mCpuUsed = CountProcessCpuPer(mCurProcessInfo.mPid);
	mCurProcessInfo.mMemUsed = CountProcessMemPer(mCurProcessInfo.mPid);

	sigar_proc_state_t procstate;
	if (sigar_proc_state_get(m_sigar, mCurProcessInfo.mPid, &procstate) != SIGAR_OK)
	{
		//NFLogError("sigar_proc_state_get error, cur_pid:{}", mCurProcessInfo.mPid);
	}

	mCurProcessInfo.mThreads = (uint32_t)procstate.threads;
}

void NFSystemInfo::CountMemInfo()
{
	sigar_mem_t sigar_mem;
	sigar_mem_get(m_sigar, &sigar_mem);

	mMachineMemInfo.mTotalMem = sigar_mem.total;
	mMachineMemInfo.mFreeMem = sigar_mem.actual_free;
	mMachineMemInfo.mUsedMem = sigar_mem.actual_used;
	mMachineMemInfo.mUsedPercent = sigar_mem.used_percent;
	mMachineMemInfo.mFreePercent = sigar_mem.free_percent;
}

uint32_t NFSystemInfo::GetUserCount() const
{
	return mUserCount;
}

void NFSystemInfo::SetUserCount(uint32_t userCount)
{
	mUserCount = userCount;
}

