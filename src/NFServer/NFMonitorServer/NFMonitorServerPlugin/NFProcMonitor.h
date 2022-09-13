// -------------------------------------------------------------------------
//    @FileName         :    NFProcInfo.h
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFProcInfo.h
//
// -------------------------------------------------------------------------

#pragma once

#include <string>
#include <fstream>
#include <map>
#include <vector>
#include <unistd.h>
#include <stdlib.h>
#include<sys/time.h>
#include <ctype.h>
#include <dirent.h>
#include <grp.h>
#include <pwd.h>
#include "NFComm/NFCore/NFStringUtility.h"
#include "NFComm/NFPluginModule/NFLogMgr.h"
#include "NFComm/NFCore/NFTimeUtil.h"
#include "common/sigar/sigar.h"
#include "NFComm/NFPluginModule/NFTimerObj.h"
#include "NFComm/NFPluginModule/NFTimerMgr.h"

enum {
    PROC_STATUS_NONE = 0,
    PROC_STATUS_RUN = 1,
    PROC_STATUS_SLEEP = 2, //可中断的睡眠状态TASK_INTERRUPTIBLE。含义：可中断的睡眠状态的进程会睡眠直到某个条件变为真
    PROC_STATUS_TASK_UNINTERRUPTIBLE = 3, //不可中断的睡眠状态
    PROC_STATUS_STOP = 4, //暂停状态或跟踪状态TASK_STOPPED
    PROC_STATUS_ZOMBIE = 5, //退出状态，进程成为僵尸进程TASK_DEAD – EXIT_ZOMBIE
    PROC_STATUS_EXIT_DEAD = 6, //退出状态，进程即将被销毁TASK_DEAD
};

//进程信息
class NFProcInfo {
public:
    NFProcInfo()
    {
        m_id = 0;
        m_pid = 0;
        m_strStartTime = "0";
        m_strEndTime = "0";
        m_strStatus = "None";
        m_startTime = 0;
        m_endTime = 0;
        mCpuUsed = 0.0;
        mMemUsed = 0;
        mThreads = 0;
        m_status = 0;
    }

    int m_id;            // 进程个数
    int m_pid;        // 进程号
    std::string m_strStatus;
    int m_status;
    std::string m_strStartTime;
    std::string m_strEndTime;
    uint64_t m_startTime;
    uint64_t m_endTime;
    double   mCpuUsed;
    uint64_t mMemUsed;
    uint32_t mThreads;
};

enum {
    NF_PROC_CMD_STATUS_NONE = 0,
    NF_PROC_CMD_STATUS_STOP = 1,
    NF_PROC_CMD_STATUS_START = 2,
    NF_PROC_CMD_STATUS_RESTART = 3,
    NF_PROC_CMD_STATUS_RELOAD = 4,
};

class NFServerProcInfo
{
public:
    NFServerProcInfo()
    {
        m_daemon = false;
        m_stop = false;
        m_start = false;
        m_restart = false;
        m_init = false;
        m_kill = false;
        m_quit = false;
        m_reload = false;
        m_cmdStatus = NF_PROC_CMD_STATUS_NONE;
        m_autoStopServer = false;
    }

    NFProcInfo* GetProcInfo(int pid)
    {
        for(int i = 0; i < (int)m_procInfo.size(); i++)
        {
            if (m_procInfo[i].m_pid == pid)
            {
                return &m_procInfo[i];
            }
        }
        return NULL;
    }

    NFProcInfo* AddProcInfo()
    {
        m_procInfo.push_back(NFProcInfo());
        NFProcInfo* pInfo = &m_procInfo[m_procInfo.size()-1];
        pInfo->m_id = m_procInfo.size();
        pInfo->m_strStartTime = DateTimeToStr((int)NFGetSecondTime());
        pInfo->m_startTime = NFGetSecondTime();
        return pInfo;
    }

    int PrintDebugInfo()
    {
        for(int i = 0; i < (int)m_procInfo.size(); i++)
        {
            NFLogInfo(NF_LOG_MONITOR_SERVER_PLUGIN, 0, "---------------------------------------------------------------");
            NFLogInfo(NF_LOG_MONITOR_SERVER_PLUGIN, 0, "pid:{} serverName:{} busName:{} cpu:{} mem:{}M startTime:{} endTime:{} status:{}", m_procInfo[i].m_pid,
                      m_serverName, m_busName, m_procInfo[i].mCpuUsed, ((double)m_procInfo[i].mMemUsed)/1024/1024, m_procInfo[i].m_strStartTime, m_procInfo[i].m_strEndTime, m_procInfo[i].m_strStatus);
            NFLogInfo(NF_LOG_MONITOR_SERVER_PLUGIN, 0, "---------------------------------------------------------------");
        }
        return 0;
    }

    void ClearCmdStats()
    {
        m_cmdStatus = NF_PROC_CMD_STATUS_NONE;
    }

    void SetCmdStatus(uint32_t status)
    {
        m_cmdStatus = status;
    }

    uint32_t GetCmdStatus() const
    {
        return m_cmdStatus;
    }

    std::string m_cmd;
    std::string m_serverName;
    std::string m_busName;
    std::string m_configPath;
    std::string m_pluginPath;
    bool m_daemon;
    bool m_stop;
    bool m_start;
    bool m_restart;
    bool m_reload;
    bool m_init;
    bool m_kill;
    bool m_quit;
    std::vector<NFProcInfo> m_procInfo;
    NFProcInfo m_curProc;
    uint32_t m_cmdStatus;
    bool m_autoStopServer;
};

class NFProcMonitor;
class NFProcCheck : public NFTimerObj
{
public:
    enum {
        NFProcCheck_TIMER = 1,
    };

    NFProcCheck(uint32_t id, uint64_t reqId, NFProcMonitor* pMon, sigar_t *sigar):m_id(id),m_httpReqId(reqId), m_pMonitor(pMon), m_sigar(sigar)
    {
        m_count = 0;
        SetTimer(NFProcCheck_TIMER, 100, 0);
    }

    virtual ~NFProcCheck()
    {

    }

    virtual void StopCheck();

    void OnTimer(uint32_t nTimerID)
    {
        m_count++;
        HandleProcCheck();
    }

    virtual int HandleProcCheck() = 0;

    uint32_t m_id;
    uint64_t m_httpReqId;
    NFProcMonitor* m_pMonitor;
    sigar_t *m_sigar;
    uint32_t m_count;
};

class NFProcStopCheck : public NFProcCheck
{
public:
    NFProcStopCheck(uint32_t id, uint64_t reqId, NFProcMonitor* pMon, sigar_t *sigar,  NFServerProcInfo* pInfo):NFProcCheck(id, reqId, pMon, sigar), m_pInfo(pInfo)
    {
    }

    virtual ~NFProcStopCheck()
    {
        m_pInfo->ClearCmdStats();
    }

    virtual int HandleProcCheck() override;

    NFServerProcInfo* m_pInfo;
};

class NFProcStartCheck : public NFProcCheck
{
public:
    NFProcStartCheck(uint32_t id, uint64_t reqId, NFProcMonitor* pMon, sigar_t *sigar, NFServerProcInfo* pInfo):NFProcCheck(id, reqId, pMon, sigar), m_pInfo(pInfo)
    {
    }

    virtual ~NFProcStartCheck()
    {
        m_pInfo->ClearCmdStats();
    }

    virtual int HandleProcCheck() override;

    NFServerProcInfo* m_pInfo;
};

class NFProcRestartCheck : public NFProcCheck
{
public:
    NFProcRestartCheck(uint32_t id, uint64_t reqId, NFProcMonitor* pMon, sigar_t *sigar, NFServerProcInfo* pInfo):NFProcCheck(id, reqId, pMon, sigar), m_pInfo(pInfo)
    {
    }

    virtual ~NFProcRestartCheck()
    {
        m_pInfo->ClearCmdStats();
    }

    virtual int HandleProcCheck() override;

    NFServerProcInfo* m_pInfo;
};

class NFProcReloadCheck : public NFProcCheck
{
public:
    NFProcReloadCheck(uint32_t id, uint64_t reqId, NFProcMonitor* pMon, sigar_t *sigar, NFServerProcInfo* pInfo):NFProcCheck(id, reqId, pMon, sigar), m_pInfo(pInfo)
    {
    }

    virtual ~NFProcReloadCheck()
    {
        m_pInfo->ClearCmdStats();
    }

    virtual int HandleProcCheck() override;

    NFServerProcInfo* m_pInfo;
};

class NFProcStopAllCheck : public NFProcCheck
{
public:
    NFProcStopAllCheck(uint32_t id, uint64_t reqId, NFProcMonitor* pMon, sigar_t *sigar):NFProcCheck(id, reqId, pMon, sigar)
    {
    }

    virtual ~NFProcStopAllCheck()
    {
        for(int i = 0; i < (int)m_pInfoList.size(); i++)
        {
            m_pInfoList[i]->ClearCmdStats();
        }
    }

    virtual int HandleProcCheck() override;

    std::vector<NFServerProcInfo*> m_pInfoList;
};

class NFProcStartAllCheck : public NFProcCheck
{
public:
    NFProcStartAllCheck(uint32_t id, uint64_t reqId, NFProcMonitor* pMon, sigar_t *sigar):NFProcCheck(id, reqId, pMon, sigar)
    {
    }

    virtual ~NFProcStartAllCheck()
    {
        for(int i = 0; i < (int)m_pInfoList.size(); i++)
        {
            m_pInfoList[i]->ClearCmdStats();
        }
    }

    virtual int HandleProcCheck() override;

    std::vector<NFServerProcInfo*> m_pInfoList;
};

class NFProcRestartAllCheck : public NFProcCheck
{
public:
    NFProcRestartAllCheck(uint32_t id, uint64_t reqId, NFProcMonitor* pMon, sigar_t *sigar):NFProcCheck(id, reqId, pMon, sigar)
    {
    }

    virtual ~NFProcRestartAllCheck()
    {
        for(int i = 0; i < (int)m_pInfoList.size(); i++)
        {
            m_pInfoList[i]->ClearCmdStats();
        }
    }

    virtual int HandleProcCheck() override;

    std::vector<NFServerProcInfo*> m_pInfoList;
};

class NFProcReloadAllCheck : public NFProcCheck
{
public:
    NFProcReloadAllCheck(uint32_t id, uint64_t reqId, NFProcMonitor* pMon, sigar_t *sigar):NFProcCheck(id, reqId, pMon, sigar)
    {

    }

    virtual ~NFProcReloadAllCheck()
    {
        for(int i = 0; i < (int)m_pInfoList.size(); i++)
        {
            m_pInfoList[i]->ClearCmdStats();
        }
    }

    virtual int HandleProcCheck() override;

    std::vector<NFServerProcInfo*> m_pInfoList;
};



class NFProcMonitor
{
public:
    NFProcMonitor();
    virtual ~NFProcMonitor();
public:
    static NFServerProcInfo* ParseCmd(const std::string& cmd, bool print = false);
    static NFServerProcInfo* ParseCmd(int argc, char** argv, bool print = false);
    //供命令行查找
    NFServerProcInfo* FindProc(const std::string &cmdline);
    NFServerProcInfo* FindProcByBusName(const std::string &busName);

    int GetProcessListBySh(const std::string& sfile);
    virtual int GetAllProcessInfo();
    int PrintDebugInfo();
    int HandleDeadProc();

    int StartProcess(NFServerProcInfo* pInfo, uint64_t param);
    int StopProcess(NFServerProcInfo* pInfo, uint64_t param);
    int RestartProcess(NFServerProcInfo* pInfo, uint64_t param);
    int ReloadProcess(NFServerProcInfo* pInfo, uint64_t param);

    int StartProcess(NFServerProcInfo* pInfo);
    int StopProcess(NFServerProcInfo* pInfo);
    int RestartProcess(NFServerProcInfo* pInfo);
    int ReloadProcess(NFServerProcInfo* pInfo);


    int StartAllProcess(uint64_t param);
    int StopAllProcess(uint64_t param);
    int RestartAllProcess(uint64_t param);
    int ReloadAllProcess(uint64_t param);

    virtual double CountProcessCpuPer(uint32_t pid);
    virtual uint64_t CountProcessMemPer(uint32_t pid);

    virtual void CountMemInfo();
    virtual void CountOsInfo();
    virtual uint32_t GetNewProcCheckIndex();
    virtual void RemoveProCheck(uint32_t id);
public:
    static int AddExe(const std::string& file);
    static int LoadExe(const std::string& file);
    static int DelExe(const std::string& file);
private:
    std::string m_exeFileName;
private:
    //进程列表
    uid_t userId;		//用户ID
    std::map<std::string, NFServerProcInfo*> m_allProcessList;		// 全部进程
    std::map<std::string, NFServerProcInfo*> m_busNameProcInfo;		// 全部进程
    sigar_t *m_sigar;
    NFMemInfo mMachineMemInfo; //当前物理机子的内存信息
    NFOsInfo mMachineOsInfo;
    uint32_t m_procCheckIndex;
    std::map<uint32_t, NFProcCheck*>  m_procCheckMap;
};