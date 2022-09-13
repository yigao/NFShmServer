// -------------------------------------------------------------------------
//    @FileName         :    NFProcInfo.cpp
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFProcInfo.cpp
//
// -------------------------------------------------------------------------

#include "NFProcMonitor.h"
#include "NFComm/NFCore/NFFileUtility.h"
#include "NFComm/NFPluginModule/NFCheck.h"
#include "NFComm/NFCore/NFCmdLine.h"
#include "NFComm/NFPluginModule/NFMessageMgr.h"
#include "NFComm/NFMessageDefine/proto_svr_common.pb.h"
#include "NFComm/NFPluginModule/NFCDynLibMgr.h"
#include "NFComm/NFCore/NFMD5.h"
#include "NFComm/NFCore/NFTea.h"

NFProcMonitor::NFProcMonitor()
{
    userId = getuid();
    m_sigar = NULL;
    sigar_open(&m_sigar);
    m_procCheckIndex = 1;

    m_exeFileName = "./NFPluginLoader";
}

NFProcMonitor::~NFProcMonitor()
{
    sigar_close(m_sigar);
}

int NFProcMonitor::PrintDebugInfo()
{
    CountMemInfo();
    NFLogError(NF_LOG_MONITOR_SERVER_PLUGIN, 0, "###############################################################")
    for(auto iter = m_allProcessList.begin(); iter != m_allProcessList.end(); iter++)
    {
        NFServerProcInfo* pProcInfo = iter->second;
        NFLogInfo(NF_LOG_MONITOR_SERVER_PLUGIN, 0, "******************{} {}*********************", pProcInfo->m_serverName, pProcInfo->m_busName);
        pProcInfo->PrintDebugInfo();
        NFLogInfo(NF_LOG_MONITOR_SERVER_PLUGIN, 0, "******************{} {}*********************", pProcInfo->m_serverName, pProcInfo->m_busName);
    }
    NFLogError(NF_LOG_MONITOR_SERVER_PLUGIN, 0, "###############################################################")
    return 0;
}

NFServerProcInfo* NFProcMonitor::FindProc(const std::string &cmdline)
{
    auto iter = m_allProcessList.find(cmdline);
    if (m_allProcessList.end() != iter)
    {
        return iter->second;
    }

    return NULL;
}

NFServerProcInfo* NFProcMonitor::FindProcByBusName(const std::string &busName)
{
    auto iter = m_busNameProcInfo.find(busName);
    if (m_busNameProcInfo.end() != iter)
    {
        return iter->second;
    }

    return NULL;
}

NFServerProcInfo* NFProcMonitor::ParseCmd(int argc, char** argv, bool print)
{
    std::string buffer;
    for(int i = 0; i < argc; i++)
    {
        buffer += argv[i];
        buffer += " ";
    }
    NFStringUtility::Trim(buffer);
    return ParseCmd(buffer, print);
}

NFServerProcInfo* NFProcMonitor::ParseCmd(const std::string& buffer, bool print)
{
    try {
        NFCmdLine::NFParser cmdParser;

        cmdParser.Add<std::string>("Server", 0, "Server Name", true);
        cmdParser.Add<std::string>("ID", 0, "Server ID", true);
        cmdParser.Add<std::string>("Config", 0, "Config Path", true);
        cmdParser.Add<std::string>("Plugin", 0, "Config Path", true);
        cmdParser.Add("Daemon", 'd', "Run it as daemon mode, only on linux");
        cmdParser.Add("Stop", 0, "Stop the run server, only on linux");
        cmdParser.Add("Reload", 0, "Reload the run server, only on linux");
        cmdParser.Add("Quit", 0, "Quit the run server, only on linux");
        cmdParser.Add("Restart", 0, "close the run server, restart new proc, only on linux");
        cmdParser.Add("Start", 0, "Start the run server, only on linux");
        cmdParser.Add("Init", 0, "change shm mode to init, only on linux");
        cmdParser.Add("Kill", 0, "kill the run server, only on linux");

        bool ret = cmdParser.ParseConsoleCommand(buffer);
        if (ret == false)
        {
            if (print)
            {
                NFLogError(NF_LOG_SYSTEMLOG, 0, "cmdParser.ParseConsoleCommand:{} Failed", buffer);
            }
            return NULL;
        }

        if (!cmdParser.Exist("Stop") && !cmdParser.Exist("Reload") &&
                !cmdParser.Exist("Quit") && !cmdParser.Exist("Restart") &&
                !cmdParser.Exist("Start"))
        {
            if (print)
            {
                NFLogError(NF_LOG_SYSTEMLOG, 0, "ths cmd has no stop/reload/quit/restart/start, cmd:{}", buffer);
            }
            return NULL;
        }

        NFServerProcInfo* pProcInfo = NF_NEW NFServerProcInfo();

        pProcInfo->m_cmd = cmdParser.GetProgramName();
        pProcInfo->m_serverName = cmdParser.Get<std::string>("Server");
        pProcInfo->m_busName = cmdParser.Get<std::string>("ID");
        pProcInfo->m_configPath = cmdParser.Get<std::string>("Config");
        pProcInfo->m_pluginPath =  cmdParser.Get<std::string>("Plugin");

        if (cmdParser.Exist("Daemon"))
        {
            pProcInfo->m_daemon = true;
        }

        if (cmdParser.Exist("Stop"))
        {
            pProcInfo->m_stop = true;
        }

        if (cmdParser.Exist("Reload"))
        {
            pProcInfo->m_reload = true;
        }

        if (cmdParser.Exist("Quit"))
        {
            pProcInfo->m_quit = true;
        }

        if (cmdParser.Exist("Restart"))
        {
            pProcInfo->m_restart = true;
        }

        if (cmdParser.Exist("Start"))
        {
            pProcInfo->m_start = true;
        }

        if (cmdParser.Exist("Init"))
        {
            pProcInfo->m_init = true;
        }

        if (cmdParser.Exist("Kill"))
        {
            pProcInfo->m_kill = true;
        }

        return pProcInfo;
    }
    catch (NFCmdLine::NFCmdLine_Error& e)
    {
        if (print)
        {
            NFLogError(NF_LOG_SYSTEMLOG, 0, "cmd:{} error:{}", buffer, e.what());
        }
    }

    return NULL;
}

int NFProcMonitor::GetProcessListBySh(const std::string& sfile)
{
    AddExe(m_exeFileName);
    CountOsInfo();
    CountMemInfo();

    std::vector<std::string> vecLine;
    CHECK_EXPR(NFFileUtility::IsFileExist(sfile), -1, "file:{} not exist", sfile);
    CHECK_EXPR(NFFileUtility::IsReadable(sfile), -1, "file:{} not read", sfile);
    CHECK_EXPR(NFFileUtility::ReadFile(sfile, vecLine), -1, "file:{} read failed", sfile);

    for(int i = 0; i < (int)vecLine.size(); i++)
    {
        std::string& buffer = vecLine[i];
        NFStringUtility::Trim(buffer);
        if (buffer.length() > 0 && buffer[0] != '#' && buffer.substr(0,6) != "sleep ")
        {
            NFServerProcInfo* pProcInfo = ParseCmd(buffer, true);
            if (pProcInfo)
            {
                if (pProcInfo->m_serverName == "MasterServer" || pProcInfo->m_serverName == "MonitorServer")
                    continue;

                if (FindProc(pProcInfo->m_cmd) == NULL)
                {
                    m_allProcessList.emplace(pProcInfo->m_cmd, pProcInfo);
                    if (FindProcByBusName(pProcInfo->m_busName) == NULL)
                        m_busNameProcInfo.emplace(pProcInfo->m_busName, pProcInfo);
                    else
                    {
                        NFLogError(NF_LOG_SYSTEMLOG, 0, "repeated bus name:{}", buffer);
                    }
                }
                else
                {
                    NFLogError(NF_LOG_SYSTEMLOG, 0, "repeat cmd:{}", buffer);
                }
            }
            else
            {
                NFLogError(NF_LOG_SYSTEMLOG, 0, "parse cmd failed:{}", buffer);
            }
        }
    }
    return 0;
}

int NFProcMonitor::StartAllProcess(uint64_t param)
{
    NFProcStartAllCheck* pCheck = NF_NEW NFProcStartAllCheck(GetNewProcCheckIndex(), param, this, m_sigar);
    CHECK_NULL(pCheck);
    m_procCheckMap.emplace(pCheck->m_id, pCheck);

    for(auto iter = m_allProcessList.begin(); iter != m_allProcessList.end(); iter++)
    {
        StartProcess(iter->second);
        pCheck->m_pInfoList.push_back(iter->second);
        iter->second->SetCmdStatus(NF_PROC_CMD_STATUS_START);
    }

    return 0;
}

int NFProcMonitor::StopAllProcess(uint64_t param)
{
    NFProcStopAllCheck* pCheck = NF_NEW NFProcStopAllCheck(GetNewProcCheckIndex(), param, this, m_sigar);
    CHECK_NULL(pCheck);
    m_procCheckMap.emplace(pCheck->m_id, pCheck);

    for(auto iter = m_allProcessList.begin(); iter != m_allProcessList.end(); iter++)
    {
        NFServerProcInfo* pInfo = iter->second;
        if (pInfo->m_serverName == "MasterServer" || pInfo->m_serverName == "MonitorServer")
            continue;

        if (pInfo->m_procInfo.size() <= 0)
            continue;

        StopProcess(pInfo);
        pCheck->m_pInfoList.push_back(pInfo);
        pInfo->SetCmdStatus(NF_PROC_CMD_STATUS_STOP);
    }

    return 0;
}

int NFProcMonitor::RestartAllProcess(uint64_t param)
{
    NFProcRestartAllCheck* pCheck = NF_NEW NFProcRestartAllCheck(GetNewProcCheckIndex(), param, this, m_sigar);
    CHECK_NULL(pCheck);
    m_procCheckMap.emplace(pCheck->m_id, pCheck);

    for(auto iter = m_allProcessList.begin(); iter != m_allProcessList.end(); iter++)
    {
        RestartProcess(iter->second);
        pCheck->m_pInfoList.push_back(iter->second);
        iter->second->SetCmdStatus(NF_PROC_CMD_STATUS_RESTART);
    }

    return 0;
}

int NFProcMonitor::ReloadAllProcess(uint64_t param)
{
    NFProcReloadAllCheck* pCheck = NF_NEW NFProcReloadAllCheck(GetNewProcCheckIndex(), param, this, m_sigar);
    CHECK_NULL(pCheck);
    m_procCheckMap.emplace(pCheck->m_id, pCheck);

    for(auto iter = m_allProcessList.begin(); iter != m_allProcessList.end(); iter++)
    {
        ReloadProcess(iter->second);
        pCheck->m_pInfoList.push_back(iter->second);
        iter->second->SetCmdStatus(NF_PROC_CMD_STATUS_RELOAD);
    }

    return 0;
}

int NFProcMonitor::StartProcess(NFServerProcInfo* pInfo, uint64_t param)
{
    CHECK_NULL(pInfo);

    StartProcess(pInfo);

    NFProcStartCheck* pCheck = NF_NEW NFProcStartCheck(GetNewProcCheckIndex(), param, this, m_sigar, pInfo);
    CHECK_NULL(pCheck);
    m_procCheckMap.emplace(pCheck->m_id, pCheck);
    pInfo->SetCmdStatus(NF_PROC_CMD_STATUS_START);
    return 0;
}

int NFProcMonitor::StartProcess(NFServerProcInfo* pInfo)
{
    CHECK_NULL(pInfo);
    LoadExe(m_exeFileName);
    std::string cmd = NF_FORMAT("{} -d --Server={} --ID={} --Config={} --Plugin={} --{}\n", pInfo->m_cmd, pInfo->m_serverName,
                    pInfo->m_busName, pInfo->m_configPath, pInfo->m_pluginPath, "start");

    NFLogInfo(NF_LOG_MONITOR_SERVER_PLUGIN, 0, "Run Cmd:{}", cmd);

    popen(cmd.c_str(),"r");
    NFSLEEP(1000000);
    DelExe(m_exeFileName);

    return 0;
}

int NFProcMonitor::StopProcess(NFServerProcInfo* pInfo, uint64_t param)
{
    CHECK_NULL(pInfo);
    StopProcess(pInfo);

    NFProcStopCheck* pCheck = NF_NEW NFProcStopCheck(GetNewProcCheckIndex(), param, this, m_sigar, pInfo);
    CHECK_NULL(pCheck);
    m_procCheckMap.emplace(pCheck->m_id, pCheck);
    pInfo->SetCmdStatus(NF_PROC_CMD_STATUS_STOP);
    return 0;
}

int NFProcMonitor::StopProcess(NFServerProcInfo* pInfo)
{
    CHECK_NULL(pInfo);
    LoadExe(m_exeFileName);
    std::string cmd = NF_FORMAT("{} -d --Server={} --ID={} --Config={} --Plugin={} --{}\n", pInfo->m_cmd, pInfo->m_serverName,
                                pInfo->m_busName, pInfo->m_configPath, pInfo->m_pluginPath, "stop");

    NFLogInfo(NF_LOG_MONITOR_SERVER_PLUGIN, 0, "Run Cmd:{}", cmd);

    popen(cmd.c_str(),"r");
    NFSLEEP(1000000);
    DelExe(m_exeFileName);
    pInfo->m_autoStopServer = true;

    return 0;
}

int NFProcMonitor::RestartProcess(NFServerProcInfo* pInfo, uint64_t param)
{
    RestartProcess(pInfo);

    NFProcRestartCheck* pCheck = NF_NEW NFProcRestartCheck(GetNewProcCheckIndex(), param, this, m_sigar, pInfo);
    CHECK_NULL(pCheck);
    m_procCheckMap.emplace(pCheck->m_id, pCheck);
    pInfo->SetCmdStatus(NF_PROC_CMD_STATUS_RESTART);
    return 0;
}

int NFProcMonitor::RestartProcess(NFServerProcInfo* pInfo)
{
    CHECK_NULL(pInfo);
    LoadExe(m_exeFileName);

    std::string cmd = NF_FORMAT("{} -d --Server={} --ID={} --Config={} --Plugin={} --{} --kill\n", pInfo->m_cmd, pInfo->m_serverName,
                                pInfo->m_busName, pInfo->m_configPath, pInfo->m_pluginPath, "restart");

    NFLogInfo(NF_LOG_MONITOR_SERVER_PLUGIN, 0, "Run Cmd:{}", cmd);

    popen(cmd.c_str(),"r");
    NFSLEEP(1000000);
    DelExe(m_exeFileName);

    return -1;
}

int NFProcMonitor::ReloadProcess(NFServerProcInfo* pInfo, uint64_t param)
{
    ReloadProcess(pInfo);

    NFProcReloadCheck* pCheck = NF_NEW NFProcReloadCheck(GetNewProcCheckIndex(), param, this, m_sigar, pInfo);
    CHECK_NULL(pCheck);
    m_procCheckMap.emplace(pCheck->m_id, pCheck);
    pInfo->SetCmdStatus(NF_PROC_CMD_STATUS_RELOAD);
    return 0;
}

int NFProcMonitor::ReloadProcess(NFServerProcInfo* pInfo)
{
    CHECK_NULL(pInfo);
    LoadExe(m_exeFileName);
    std::string cmd = NF_FORMAT("{} -d --Server={} --ID={} --Config={} --Plugin={} --{}\n", pInfo->m_cmd, pInfo->m_serverName,
                                pInfo->m_busName, pInfo->m_configPath, pInfo->m_pluginPath, "reload");

    NFLogInfo(NF_LOG_MONITOR_SERVER_PLUGIN, 0, "Run Cmd:{}", cmd);

    popen(cmd.c_str(),"r");

    NFSLEEP(1000000);
    DelExe(m_exeFileName);

    int ret = 0;
    sigar_proc_state_t proc_state;
    ret = sigar_proc_state_get(m_sigar, pInfo->m_curProc.m_pid, &proc_state);
    if (ret != 0)
    {
        NFLogError(NF_LOG_MONITOR_SERVER_PLUGIN, 0, "proc not exist, reload faled..........");
        return ret;
    }

    sigar_proc_args_t proc_args;
    ret = sigar_proc_args_get(m_sigar, pInfo->m_curProc.m_pid, &proc_args);
    if (ret != 0)
    {
        return ret;
    }

    if (proc_args.number <= 0)
    {
        sigar_proc_args_destroy(m_sigar, &proc_args);
        return -1;
    }

    // command args
    std::string strCmdLine = proc_args.data[0];  //将启动命令赋值给strCmdLine
    if (strCmdLine.find("Server") == std::string::npos)
    {
        sigar_proc_args_destroy(m_sigar, &proc_args);
        return -1;
    }

    if (proc_state.tty != 0)
    {
        return -1;
    }

    // command args
    NFServerProcInfo* pCmdProcInfo = ParseCmd(proc_args.number, proc_args.data);
    if (pCmdProcInfo == NULL || pCmdProcInfo->m_stop == true || pCmdProcInfo->m_reload == true)
    {
        sigar_proc_args_destroy(m_sigar, &proc_args);
        return -1;
    }

    if (pCmdProcInfo->m_cmd == pInfo->m_cmd)
    {
        sigar_proc_args_destroy(m_sigar, &proc_args);
        return 0;
    }

    sigar_proc_args_destroy(m_sigar, &proc_args);
    return -1;
}

int NFProcMonitor::GetAllProcessInfo()
{
    sigar_proc_list_t procList;
    int ret = sigar_proc_list_get(m_sigar, &procList);
    if (ret != 0)
    {
        NFLogError(NF_LOG_SYSTEMLOG, 0, "sigar_proc_list_get error:{}", ret);
        return -1;
    }

    for(int i = 0; i < (int)procList.number; i++)
    {
        sigar_pid_t pid = procList.data[i];

        sigar_proc_cred_t cred;
        sigar_proc_cred_get(m_sigar, pid, &cred);

        if ((int)cred.uid != (int)userId)
            continue;

        sigar_proc_state_t proc_state;
        sigar_proc_state_get(m_sigar, pid, &proc_state);

        sigar_proc_args_t proc_args;
        sigar_proc_args_get(m_sigar, pid, &proc_args);
        if (proc_args.number <= 0)
        {
            sigar_proc_args_destroy(m_sigar, &proc_args);
            continue;
        }

        // command args
        std::string strCmdLine = proc_args.data[0];  //将启动命令赋值给strCmdLine
        if (strCmdLine.find("Server") == std::string::npos)
        {
            sigar_proc_args_destroy(m_sigar, &proc_args);
            continue;
        }

        if (proc_state.tty != 0)
        {
            continue;
        }

        // command args
        NFServerProcInfo* pCmdProcInfo = ParseCmd(proc_args.number, proc_args.data);
        if (pCmdProcInfo == NULL || pCmdProcInfo->m_stop == true || pCmdProcInfo->m_reload == true)
        {
            sigar_proc_args_destroy(m_sigar, &proc_args);
            continue;
        }

        NFServerProcInfo* pServerProcInfo = FindProc(pCmdProcInfo->m_cmd);
        if (!pServerProcInfo)
        {
            sigar_proc_args_destroy(m_sigar, &proc_args);
            continue;
        }

        if (pServerProcInfo->GetCmdStatus() != NF_PROC_CMD_STATUS_NONE)
        {
            continue;
        }

        NFProcInfo *pProcInfo = pServerProcInfo->GetProcInfo(pid);
        if (pProcInfo == NULL)
        {
            pProcInfo = pServerProcInfo->AddProcInfo();
            pProcInfo->m_pid = pid;
        }

        pProcInfo->mThreads = proc_state.threads;
        pProcInfo->mCpuUsed = CountProcessCpuPer(pid);
        pProcInfo->mMemUsed = CountProcessMemPer(pid);

        switch (proc_state.state)
        {
            case SIGAR_PROC_STATE_RUN:
                pProcInfo->m_strStatus = "RUN";
                pProcInfo->m_status = PROC_STATUS_RUN;
                break;
            case SIGAR_PROC_STATE_SLEEP:
                pProcInfo->m_strStatus = "RUN";//可中断的睡眠状态TASK_INTERRUPTIBLE。含义：可中断的睡眠状态的进程会睡眠直到某个条件变为真
                pProcInfo->m_status = PROC_STATUS_SLEEP;
                break;
            case SIGAR_PROC_STATE_IDLE:
                pProcInfo->m_strStatus = "RUN"; //不可中断的睡眠状态
                pProcInfo->m_status = PROC_STATUS_TASK_UNINTERRUPTIBLE;
                break;
            case SIGAR_PROC_STATE_STOP:
                pProcInfo->m_strStatus = "RUN"; //暂停状态或跟踪状态TASK_STOPPED
                pProcInfo->m_status = PROC_STATUS_STOP;
                break;
            case SIGAR_PROC_STATE_ZOMBIE:
                pProcInfo->m_strStatus = "RUN"; //退出状态，进程成为僵尸进程TASK_DEAD – EXIT_ZOMBIE
                pProcInfo->m_status = PROC_STATUS_ZOMBIE;
                break;
            default:
                pProcInfo->m_strStatus = "DEAD";
                pProcInfo->m_status = PROC_STATUS_NONE;
                break;
        }

        pServerProcInfo->m_curProc = *pProcInfo;

        sigar_proc_args_destroy(m_sigar, &proc_args);
    }

    HandleDeadProc();

    return 0;
}

int NFProcMonitor::HandleDeadProc()
{
    for(auto iter = m_allProcessList.begin(); iter != m_allProcessList.end(); iter++)
    {
        NFServerProcInfo* pServerInfo = iter->second;
        if (pServerInfo->GetCmdStatus() != NF_PROC_CMD_STATUS_NONE)
        {
            continue;
        }
        for(int i = 0; i < (int)pServerInfo->m_procInfo.size(); i++)
        {
            NFProcInfo* pProcInfo = &pServerInfo->m_procInfo[i];
            sigar_proc_state_t proc_state;
            int ret = sigar_proc_state_get(m_sigar, pProcInfo->m_pid, &proc_state);
            if (ret != 0)
            {
                if (pProcInfo->m_status != PROC_STATUS_NONE)
                {
                    pProcInfo->m_strStatus = "DEAD";
                    pProcInfo->m_status = PROC_STATUS_NONE;
                    NFLogError(NF_LOG_SYSTEMLOG, 0, "pid:{} cmd:{} dead", pProcInfo->m_pid, pServerInfo->m_cmd);

                    pProcInfo->m_endTime = NFGetSecondTime();
                    pProcInfo->m_strEndTime = DateTimeToStr(NFGetSecondTime());

                    if (pServerInfo->m_curProc.m_pid == pProcInfo->m_pid && !pServerInfo->m_autoStopServer)
                    {
                        NFLogInfo(NF_LOG_SYSTEMLOG, 0, "Restart Server:{}", pServerInfo->m_cmd);
                        RestartProcess(pServerInfo);
                    }
                }
            }
            else
            {
                switch (proc_state.state)
                {
                    case SIGAR_PROC_STATE_RUN:
                        pProcInfo->m_strStatus = "RUN";
                        pProcInfo->m_status = PROC_STATUS_RUN;
                        break;
                    case SIGAR_PROC_STATE_SLEEP:
                        pProcInfo->m_strStatus = "RUN";//可中断的睡眠状态TASK_INTERRUPTIBLE。含义：可中断的睡眠状态的进程会睡眠直到某个条件变为真
                        pProcInfo->m_status = PROC_STATUS_SLEEP;
                        break;
                    case SIGAR_PROC_STATE_IDLE:
                        pProcInfo->m_strStatus = "RUN"; //不可中断的睡眠状态
                        pProcInfo->m_status = PROC_STATUS_TASK_UNINTERRUPTIBLE;
                        break;
                    case SIGAR_PROC_STATE_STOP:
                        pProcInfo->m_strStatus = "RUN"; //暂停状态或跟踪状态TASK_STOPPED
                        pProcInfo->m_status = PROC_STATUS_STOP;
                        break;
                    case SIGAR_PROC_STATE_ZOMBIE:
                        pProcInfo->m_strStatus = "RUN"; //退出状态，进程成为僵尸进程TASK_DEAD – EXIT_ZOMBIE
                        pProcInfo->m_status = PROC_STATUS_ZOMBIE;
                        break;
                    default:
                        pProcInfo->m_strStatus = "DEAD";
                        pProcInfo->m_status = PROC_STATUS_NONE;
                        break;
                }
            }

            if (pServerInfo->m_curProc.m_pid == pProcInfo->m_pid)
            {
                pServerInfo->m_curProc = *pProcInfo;
            }
        }
    }
    return 0;
}

double NFProcMonitor::CountProcessCpuPer(uint32_t pid)
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

uint64_t NFProcMonitor::CountProcessMemPer(uint32_t pid)
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
        NFLogError(NF_LOG_SYSTEMLOG, 0, "sigar_proc_mem_get error, cur_pid:{}", pid);
    }
    return mem;
}

void NFProcMonitor::CountMemInfo()
{
    sigar_mem_t sigar_mem;
    sigar_mem_get(m_sigar, &sigar_mem);

    mMachineMemInfo.mTotalMem = sigar_mem.total;
    mMachineMemInfo.mFreeMem = sigar_mem.actual_free;
    mMachineMemInfo.mUsedMem = sigar_mem.actual_used;
    mMachineMemInfo.mUsedPercent = sigar_mem.used_percent;
    mMachineMemInfo.mFreePercent = sigar_mem.free_percent;
}

void NFProcMonitor::CountOsInfo()
{
    sigar_sys_info_t sysInfo;
    if (sigar_sys_info_get(m_sigar, &sysInfo) != SIGAR_OK)
    {
        NFLogError(NF_LOG_SYSTEMLOG, 0, "sigar_sys_info_get error");
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
}

int NFProcStartCheck::HandleProcCheck()
{
    if (m_count >= 300)
    {
        NFLogError(NF_LOG_MONITOR_SERVER_PLUGIN, 0, "can not find new proc...........");
        proto_ff::Proto_MonitorTMasterStartRsp rspMsg;
        rspMsg.set_result(-1);
        rspMsg.set_server_name(m_pInfo->m_serverName);
        rspMsg.set_server_id(m_pInfo->m_busName);
        NFMessageMgr::Instance()->SendMsgToMasterServer(NF_ST_MONITOR_SERVER, proto_ff::NF_MonitorTMaster_START_CMD_RSP, rspMsg, m_httpReqId);
        StopCheck();
        return -1;
    }

    int ret = 0;
    sigar_proc_state_t proc_state;
    ret = sigar_proc_state_get(m_sigar, m_pInfo->m_curProc.m_pid, &proc_state);
    if (ret == 0)
    {
        NFLogError(NF_LOG_MONITOR_SERVER_PLUGIN, 0, "old proc exist..........");
        if (m_count >= 150)
        {
            proto_ff::Proto_MonitorTMasterStartRsp rspMsg;
            rspMsg.set_result(-1);
            rspMsg.set_server_name(m_pInfo->m_serverName);
            rspMsg.set_server_id(m_pInfo->m_busName);
            NFMessageMgr::Instance()->SendMsgToMasterServer(NF_ST_MONITOR_SERVER, proto_ff::NF_MonitorTMaster_START_CMD_RSP, rspMsg, m_httpReqId);
            StopCheck();
            return -1;
        }
    }

    sigar_proc_list_t procList;
    ret = sigar_proc_list_get(m_sigar, &procList);
    if (ret != 0)
    {
        proto_ff::Proto_MonitorTMasterStartRsp rspMsg;
        rspMsg.set_result(-1);
        rspMsg.set_server_name(m_pInfo->m_serverName);
        rspMsg.set_server_id(m_pInfo->m_busName);
        NFMessageMgr::Instance()->SendMsgToMasterServer(NF_ST_MONITOR_SERVER, proto_ff::NF_MonitorTMaster_START_CMD_RSP, rspMsg, m_httpReqId);
        StopCheck();
        return -1;
    }

    for(int i = 0; i < (int)procList.number; i++) {
        sigar_pid_t pid = procList.data[i];

        sigar_proc_cred_t cred;
        sigar_proc_cred_get(m_sigar, pid, &cred);

        if ((int) cred.uid != (int) getuid())
            continue;

        sigar_proc_state_t proc_state;
        sigar_proc_state_get(m_sigar, pid, &proc_state);

        sigar_proc_args_t proc_args;
        sigar_proc_args_get(m_sigar, pid, &proc_args);
        if (proc_args.number <= 0) {
            sigar_proc_args_destroy(m_sigar, &proc_args);
            continue;
        }

        // command args
        std::string strCmdLine = proc_args.data[0];  //将启动命令赋值给strCmdLine
        if (strCmdLine.find("Server") == std::string::npos) {
            sigar_proc_args_destroy(m_sigar, &proc_args);
            continue;
        }

        if (proc_state.tty != 0) {
            continue;
        }

        // command args
        NFServerProcInfo *pCmdProcInfo = m_pMonitor->ParseCmd(proc_args.number, proc_args.data);
        if (pCmdProcInfo == NULL || pCmdProcInfo->m_stop == true || pCmdProcInfo->m_reload == true) {
            sigar_proc_args_destroy(m_sigar, &proc_args);
            continue;
        }

        if (pCmdProcInfo->m_cmd == m_pInfo->m_cmd && pCmdProcInfo->m_serverName == pCmdProcInfo->m_serverName && pCmdProcInfo->m_busName == pCmdProcInfo->m_busName && pCmdProcInfo->m_start)
        {
            proto_ff::Proto_MonitorTMasterStartRsp rspMsg;
            rspMsg.set_result(0);
            rspMsg.set_server_name(m_pInfo->m_serverName);
            rspMsg.set_server_id(m_pInfo->m_busName);
            NFMessageMgr::Instance()->SendMsgToMasterServer(NF_ST_MONITOR_SERVER, proto_ff::NF_MonitorTMaster_START_CMD_RSP, rspMsg, m_httpReqId);
            StopCheck();
            return 0;
        }
    }

    return 0;
}

int NFProcStopCheck::HandleProcCheck()
{
    if (m_count >= 300)
    {
        proto_ff::Proto_MonitorTMasterStopRsp rspMsg;
        rspMsg.set_result(-1);
        rspMsg.set_server_name(m_pInfo->m_serverName);
        rspMsg.set_server_id(m_pInfo->m_busName);
        NFMessageMgr::Instance()->SendMsgToMasterServer(NF_ST_MONITOR_SERVER, proto_ff::NF_MonitorTMaster_STOP_CMD_RSP, rspMsg, m_httpReqId);

        NFLogError(NF_LOG_MONITOR_SERVER_PLUGIN, 0, "stop server, waiting to nong..........");
        StopCheck();
        return -1;
    }

    int ret = 0;
    sigar_proc_state_t proc_state;
    ret = sigar_proc_state_get(m_sigar, m_pInfo->m_curProc.m_pid, &proc_state);
    if (ret != 0)
    {
        proto_ff::Proto_MonitorTMasterStopRsp rspMsg;
        rspMsg.set_result(0);
        rspMsg.set_server_name(m_pInfo->m_serverName);
        rspMsg.set_server_id(m_pInfo->m_busName);
        NFMessageMgr::Instance()->SendMsgToMasterServer(NF_ST_MONITOR_SERVER, proto_ff::NF_MonitorTMaster_STOP_CMD_RSP, rspMsg, m_httpReqId);
        StopCheck();
        return 0;
    }

    return 0;
}

uint32_t NFProcMonitor::GetNewProcCheckIndex()
{
    return m_procCheckIndex++;
}

void NFProcMonitor::RemoveProCheck(uint32_t id)
{
    m_procCheckMap.erase(id);
}

void NFProcCheck::StopCheck()
{
    KillTimer(NFProcCheck_TIMER);
    m_pMonitor->RemoveProCheck(m_id);
    delete this;
}

int NFProcRestartCheck::HandleProcCheck()
{
    if (m_count >= 300)
    {
        NFLogError(NF_LOG_MONITOR_SERVER_PLUGIN, 0, "can not find new proc...........");
        proto_ff::Proto_MonitorTMasterRestartRsp rspMsg;
        rspMsg.set_result(-1);
        rspMsg.set_server_name(m_pInfo->m_serverName);
        rspMsg.set_server_id(m_pInfo->m_busName);
        NFMessageMgr::Instance()->SendMsgToMasterServer(NF_ST_MONITOR_SERVER, proto_ff::NF_MonitorTMaster_RESTART_CMD_RSP, rspMsg, m_httpReqId);
        StopCheck();
        return -1;
    }

    int ret = 0;
    sigar_proc_state_t proc_state;
    ret = sigar_proc_state_get(m_sigar, m_pInfo->m_curProc.m_pid, &proc_state);
    if (ret == 0)
    {
        NFLogError(NF_LOG_MONITOR_SERVER_PLUGIN, 0, "old proc exist..........");
        if (m_count >= 150)
        {
            proto_ff::Proto_MonitorTMasterRestartRsp rspMsg;
            rspMsg.set_result(-1);
            rspMsg.set_server_name(m_pInfo->m_serverName);
            rspMsg.set_server_id(m_pInfo->m_busName);
            NFMessageMgr::Instance()->SendMsgToMasterServer(NF_ST_MONITOR_SERVER, proto_ff::NF_MonitorTMaster_RESTART_CMD_RSP, rspMsg, m_httpReqId);
            StopCheck();
            return -1;
        }
    }

    sigar_proc_list_t procList;
    ret = sigar_proc_list_get(m_sigar, &procList);
    if (ret != 0)
    {
        proto_ff::Proto_MonitorTMasterRestartRsp rspMsg;
        rspMsg.set_result(-1);
        rspMsg.set_server_name(m_pInfo->m_serverName);
        rspMsg.set_server_id(m_pInfo->m_busName);
        NFMessageMgr::Instance()->SendMsgToMasterServer(NF_ST_MONITOR_SERVER, proto_ff::NF_MonitorTMaster_RESTART_CMD_RSP, rspMsg, m_httpReqId);
        StopCheck();
        return -1;
    }

    for(int i = 0; i < (int)procList.number; i++) {
        sigar_pid_t pid = procList.data[i];

        sigar_proc_cred_t cred;
        sigar_proc_cred_get(m_sigar, pid, &cred);

        if ((int) cred.uid != (int) getuid())
            continue;

        sigar_proc_state_t proc_state;
        sigar_proc_state_get(m_sigar, pid, &proc_state);

        sigar_proc_args_t proc_args;
        sigar_proc_args_get(m_sigar, pid, &proc_args);
        if (proc_args.number <= 0) {
            sigar_proc_args_destroy(m_sigar, &proc_args);
            continue;
        }

        // command args
        std::string strCmdLine = proc_args.data[0];  //将启动命令赋值给strCmdLine
        if (strCmdLine.find("Server") == std::string::npos) {
            sigar_proc_args_destroy(m_sigar, &proc_args);
            continue;
        }

        if (proc_state.tty != 0) {
            continue;
        }

        // command args
        NFServerProcInfo *pCmdProcInfo = m_pMonitor->ParseCmd(proc_args.number, proc_args.data);
        if (pCmdProcInfo == NULL || pCmdProcInfo->m_stop == true || pCmdProcInfo->m_reload == true) {
            sigar_proc_args_destroy(m_sigar, &proc_args);
            continue;
        }

        if (pCmdProcInfo->m_cmd == m_pInfo->m_cmd && pCmdProcInfo->m_serverName == pCmdProcInfo->m_serverName && pCmdProcInfo->m_busName == pCmdProcInfo->m_busName && pCmdProcInfo->m_restart)
        {
            proto_ff::Proto_MonitorTMasterRestartRsp rspMsg;
            rspMsg.set_result(0);
            rspMsg.set_server_name(m_pInfo->m_serverName);
            rspMsg.set_server_id(m_pInfo->m_busName);
            NFMessageMgr::Instance()->SendMsgToMasterServer(NF_ST_MONITOR_SERVER, proto_ff::NF_MonitorTMaster_RESTART_CMD_RSP, rspMsg, m_httpReqId);
            StopCheck();
            return 0;
        }
    }

    return 0;
}


int NFProcReloadCheck::HandleProcCheck()
{
    if (m_count >= 50)
    {
        proto_ff::Proto_MonitorTMasterReloadRsp rspMsg;
        rspMsg.set_result(0);
        rspMsg.set_server_name(m_pInfo->m_serverName);
        rspMsg.set_server_id(m_pInfo->m_busName);
        NFMessageMgr::Instance()->SendMsgToMasterServer(NF_ST_MONITOR_SERVER, proto_ff::NF_MonitorTMaster_RELOAD_CMD_RSP, rspMsg, m_httpReqId);

        StopCheck();
        return 0;
    }

    int ret = 0;
    sigar_proc_state_t proc_state;
    ret = sigar_proc_state_get(m_sigar, m_pInfo->m_curProc.m_pid, &proc_state);
    if (ret != 0)
    {
        proto_ff::Proto_MonitorTMasterReloadRsp rspMsg;
        rspMsg.set_result(-1);
        rspMsg.set_server_name(m_pInfo->m_serverName);
        rspMsg.set_server_id(m_pInfo->m_busName);
        NFMessageMgr::Instance()->SendMsgToMasterServer(NF_ST_MONITOR_SERVER, proto_ff::NF_MonitorTMaster_RELOAD_CMD_RSP, rspMsg, m_httpReqId);
        StopCheck();
        return 0;
    }

    return 0;
}

int NFProcRestartAllCheck::HandleProcCheck()
{
    if (m_count >= 300)
    {
        NFLogError(NF_LOG_MONITOR_SERVER_PLUGIN, 0, "can not find new proc...........");
        proto_ff::Proto_MonitorTMasterRestartRsp rspMsg;
        rspMsg.set_result(-1);
        NFMessageMgr::Instance()->SendMsgToMasterServer(NF_ST_MONITOR_SERVER, proto_ff::NF_MonitorTMaster_RESTART_ALL_CMD_RSP, rspMsg, m_httpReqId);
        StopCheck();
        return -1;
    }

    int count = 0;
    for(int i = 0; i < (int)m_pInfoList.size(); i++) {
        NFServerProcInfo *pInfo = m_pInfoList[i];
        int ret = 0;
        sigar_proc_state_t proc_state;
        ret = sigar_proc_state_get(m_sigar, pInfo->m_curProc.m_pid, &proc_state);
        if (ret == 0)
        {
            if (m_count >= 150)
            {
                proto_ff::Proto_MonitorTMasterRestartRsp rspMsg;
                rspMsg.set_result(-1);
                NFMessageMgr::Instance()->SendMsgToMasterServer(NF_ST_MONITOR_SERVER, proto_ff::NF_MonitorTMaster_RESTART_ALL_CMD_RSP, rspMsg, m_httpReqId);
                StopCheck();
                return -1;
            }
        }
        else
        {
            count++;
        }
    }

    if (count != (int)m_pInfoList.size())
    {
        return 0;
    }

    sigar_proc_list_t procList;
    int ret = sigar_proc_list_get(m_sigar, &procList);
    if (ret != 0)
    {
        proto_ff::Proto_MonitorTMasterRestartRsp rspMsg;
        rspMsg.set_result(-1);
        NFMessageMgr::Instance()->SendMsgToMasterServer(NF_ST_MONITOR_SERVER, proto_ff::NF_MonitorTMaster_RESTART_ALL_CMD_RSP, rspMsg, m_httpReqId);
        StopCheck();
        return -1;
    }

    count = 0;
    for(int i = 0; i < (int)m_pInfoList.size(); i++) {
        NFServerProcInfo *pInfo = m_pInfoList[i];
        for(int i = 0; i < (int)procList.number; i++) {
            sigar_pid_t pid = procList.data[i];

            sigar_proc_cred_t cred;
            sigar_proc_cred_get(m_sigar, pid, &cred);

            if ((int) cred.uid != (int) getuid())
                continue;

            sigar_proc_state_t proc_state;
            sigar_proc_state_get(m_sigar, pid, &proc_state);

            sigar_proc_args_t proc_args;
            sigar_proc_args_get(m_sigar, pid, &proc_args);
            if (proc_args.number <= 0) {
                sigar_proc_args_destroy(m_sigar, &proc_args);
                continue;
            }

            // command args
            std::string strCmdLine = proc_args.data[0];  //将启动命令赋值给strCmdLine
            if (strCmdLine.find("Server") == std::string::npos) {
                sigar_proc_args_destroy(m_sigar, &proc_args);
                continue;
            }

            if (proc_state.tty != 0) {
                continue;
            }

            // command args
            NFServerProcInfo *pCmdProcInfo = m_pMonitor->ParseCmd(proc_args.number, proc_args.data);
            if (pCmdProcInfo == NULL || pCmdProcInfo->m_stop == true || pCmdProcInfo->m_reload == true) {
                sigar_proc_args_destroy(m_sigar, &proc_args);
                continue;
            }

            if (pCmdProcInfo->m_cmd == pInfo->m_cmd && pCmdProcInfo->m_serverName == pCmdProcInfo->m_serverName && pCmdProcInfo->m_busName == pCmdProcInfo->m_busName && pCmdProcInfo->m_restart)
            {
                count++;
            }
        }
    }

    if (count == (int)m_pInfoList.size())
    {
        proto_ff::Proto_MonitorTMasterRestartRsp rspMsg;
        rspMsg.set_result(0);
        NFMessageMgr::Instance()->SendMsgToMasterServer(NF_ST_MONITOR_SERVER, proto_ff::NF_MonitorTMaster_RESTART_ALL_CMD_RSP, rspMsg, m_httpReqId);
        StopCheck();
        return 0;
    }

    return 0;
}


int NFProcReloadAllCheck::HandleProcCheck()
{
    if (m_count >= 50)
    {
        proto_ff::Proto_MonitorTMasterReloadRsp rspMsg;
        rspMsg.set_result(0);
        NFMessageMgr::Instance()->SendMsgToMasterServer(NF_ST_MONITOR_SERVER, proto_ff::NF_MonitorTMaster_RELOAD_ALL_CMD_RSP, rspMsg, m_httpReqId);

        StopCheck();
        return 0;
    }

    for(int i = 0; i < (int)m_pInfoList.size(); i++) {
        NFServerProcInfo *pInfo = m_pInfoList[i];
        int ret = 0;
        sigar_proc_state_t proc_state;
        ret = sigar_proc_state_get(m_sigar, pInfo->m_curProc.m_pid, &proc_state);
        if (ret != 0)
        {
            proto_ff::Proto_MonitorTMasterReloadRsp rspMsg;
            rspMsg.set_result(-1);
            NFMessageMgr::Instance()->SendMsgToMasterServer(NF_ST_MONITOR_SERVER, proto_ff::NF_MonitorTMaster_RELOAD_ALL_CMD_RSP, rspMsg, m_httpReqId);
            StopCheck();
            return 0;
        }
    }

    return 0;
}

int NFProcStartAllCheck::HandleProcCheck()
{
    if (m_count >= 300)
    {
        NFLogError(NF_LOG_MONITOR_SERVER_PLUGIN, 0, "can not find new proc...........");
        proto_ff::Proto_MonitorTMasterStartRsp rspMsg;
        rspMsg.set_result(-1);
        NFMessageMgr::Instance()->SendMsgToMasterServer(NF_ST_MONITOR_SERVER, proto_ff::NF_MonitorTMaster_START_ALL_CMD_RSP, rspMsg, m_httpReqId);
        StopCheck();
        return -1;
    }

    int count = 0;
    for(int i = 0; i < (int)m_pInfoList.size(); i++) {
        NFServerProcInfo *pInfo = m_pInfoList[i];
        int ret = 0;
        sigar_proc_state_t proc_state;
        ret = sigar_proc_state_get(m_sigar, pInfo->m_curProc.m_pid, &proc_state);
        if (ret == 0)
        {
            if (m_count >= 150)
            {
                proto_ff::Proto_MonitorTMasterStartRsp rspMsg;
                rspMsg.set_result(-1);
                NFMessageMgr::Instance()->SendMsgToMasterServer(NF_ST_MONITOR_SERVER, proto_ff::NF_MonitorTMaster_START_ALL_CMD_RSP, rspMsg, m_httpReqId);
                StopCheck();
                return -1;
            }
        }
        else
        {
            count++;
        }
    }

    if (count != (int)m_pInfoList.size())
    {
        return 0;
    }

    sigar_proc_list_t procList;
    int ret = sigar_proc_list_get(m_sigar, &procList);
    if (ret != 0)
    {
        proto_ff::Proto_MonitorTMasterStartRsp rspMsg;
        rspMsg.set_result(-1);
        NFMessageMgr::Instance()->SendMsgToMasterServer(NF_ST_MONITOR_SERVER, proto_ff::NF_MonitorTMaster_START_ALL_CMD_RSP, rspMsg, m_httpReqId);
        StopCheck();
        return -1;
    }

    count = 0;
    for(int i = 0; i < (int)m_pInfoList.size(); i++) {
        NFServerProcInfo *pInfo = m_pInfoList[i];
        for(int i = 0; i < (int)procList.number; i++) {
            sigar_pid_t pid = procList.data[i];

            sigar_proc_cred_t cred;
            sigar_proc_cred_get(m_sigar, pid, &cred);

            if ((int) cred.uid != (int) getuid())
                continue;

            sigar_proc_state_t proc_state;
            sigar_proc_state_get(m_sigar, pid, &proc_state);

            sigar_proc_args_t proc_args;
            sigar_proc_args_get(m_sigar, pid, &proc_args);
            if (proc_args.number <= 0) {
                sigar_proc_args_destroy(m_sigar, &proc_args);
                continue;
            }

            // command args
            std::string strCmdLine = proc_args.data[0];  //将启动命令赋值给strCmdLine
            if (strCmdLine.find("Server") == std::string::npos) {
                sigar_proc_args_destroy(m_sigar, &proc_args);
                continue;
            }

            if (proc_state.tty != 0) {
                continue;
            }

            // command args
            NFServerProcInfo *pCmdProcInfo = m_pMonitor->ParseCmd(proc_args.number, proc_args.data);
            if (pCmdProcInfo == NULL || pCmdProcInfo->m_stop == true || pCmdProcInfo->m_reload == true) {
                sigar_proc_args_destroy(m_sigar, &proc_args);
                continue;
            }

            if (pCmdProcInfo->m_cmd == pInfo->m_cmd && pCmdProcInfo->m_serverName == pCmdProcInfo->m_serverName && pCmdProcInfo->m_busName == pCmdProcInfo->m_busName && pCmdProcInfo->m_start)
            {
                count++;
            }
        }
    }

    if (count == (int)m_pInfoList.size())
    {
        proto_ff::Proto_MonitorTMasterStartRsp rspMsg;
        rspMsg.set_result(0);
        NFMessageMgr::Instance()->SendMsgToMasterServer(NF_ST_MONITOR_SERVER, proto_ff::NF_MonitorTMaster_START_ALL_CMD_RSP, rspMsg, m_httpReqId);
        StopCheck();
        return 0;
    }

    return 0;
}

int NFProcStopAllCheck::HandleProcCheck()
{
    if (m_count >= 300)
    {
        proto_ff::Proto_MonitorTMasterStopRsp rspMsg;
        rspMsg.set_result(-1);
        NFMessageMgr::Instance()->SendMsgToMasterServer(NF_ST_MONITOR_SERVER, proto_ff::NF_MonitorTMaster_STOP_ALL_CMD_RSP, rspMsg, m_httpReqId);

        NFLogError(NF_LOG_MONITOR_SERVER_PLUGIN, 0, "stop server, waiting to nong..........");
        StopCheck();
        return -1;
    }

    int count = 0;
    for(int i = 0; i < (int)m_pInfoList.size(); i++)
    {
        NFServerProcInfo* pInfo = m_pInfoList[i];
        int ret = 0;
        sigar_proc_state_t proc_state;
        ret = sigar_proc_state_get(m_sigar, pInfo->m_curProc.m_pid, &proc_state);
        if (ret != 0)
        {
            count++;
        }
    }

    if (count == (int)m_pInfoList.size())
    {
        proto_ff::Proto_MonitorTMasterStopRsp rspMsg;
        rspMsg.set_result(0);
        NFMessageMgr::Instance()->SendMsgToMasterServer(NF_ST_MONITOR_SERVER, proto_ff::NF_MonitorTMaster_STOP_ALL_CMD_RSP, rspMsg, m_httpReqId);
        StopCheck();
        return 0;
    }

    return 0;
}

int NFProcMonitor::AddExe(const std::string& file)
{
    std::string fileNameMd5 = NFMD5::md5str(file);
    if (NFFileUtility::IsFileExist(file)) {
        std::string content;
        NFFileUtility::ReadFileContent(file, content);

        std::string key = NFMD5::md5str(file + "37du");
        std::vector<char> vec;
        NFTea::encrypt(key.data(), content.data(), content.length(), vec);

        int ret = NFCDynLibMgr::Instance()->AddLib(fileNameMd5, vec.size(), vec.data(), vec.size());
        CHECK_EXPR(ret == 0, -1, "NFCDynLibMgr::Instance()->AddLib file:{} Failed", file);
        DelExe(file);
    }
    else
    {
        return -1;
    }

    return 0;
}

int NFProcMonitor::LoadExe(const std::string& file)
{
    std::string fileNameMd5 = NFMD5::md5str(file);
    if (NFFileUtility::IsFileExist(file)) {
        AddExe(file);
        return 0;
    }

    int fileSize = NFCDynLibMgr::Instance()->GetLibSize(fileNameMd5);
    if (fileSize > 0)
    {
        std::string content;
        int ret = NFCDynLibMgr::Instance()->GetLib(fileNameMd5, fileSize, content);
        CHECK_EXPR(ret == 0, false, "NFCDynLibMgr::Instance()->GetLib file:{} Failed", file);

        std::string key = NFMD5::md5str(file + "37du");
        std::vector<char> vec;
        NFTea::decrypt(key.data(), content.data(), content.length(), vec);

        NFFileUtility::WriteFile(file, vec.data(), vec.size());
        NFFileUtility::ChmodFile(file, 777);
    }

    return 0;
}

int NFProcMonitor::DelExe(const std::string& file)
{
    if (NFFileUtility::IsFileExist(file)) {
        NFFileUtility::Remove(file);
    }

    return 0;
}



