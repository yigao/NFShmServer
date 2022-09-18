//
// Created by gaoyi on 2022/9/18.
//

#include "NFProcessParameter.h"
#include "NFCPluginManager.h"
#include "NFComm/NFPluginModule/NFGlobalSystem.h"

void CloseXButton()
{
#if NF_PLATFORM == NF_PLATFORM_WIN
    HWND hWnd = GetConsoleWindow();
	if (hWnd)
	{
		HMENU hMenu = GetSystemMenu(hWnd, FALSE);
		EnableMenuItem(hMenu, SC_CLOSE, MF_DISABLED | MF_BYCOMMAND);
	}
#endif
}

void ignore_pipe_new()
{
#if	NF_PLATFORM == NF_PLATFORM_LINUX
    struct sigaction sig;

    sig.sa_handler = SIG_IGN;
    sig.sa_flags = 0;
    sigemptyset(&sig.sa_mask);
    sigaction(SIGPIPE,&sig,NULL);
#endif
}

//转变成守护进程后，会新建一个进程
void InitDaemon()
{
#if	NF_PLATFORM == NF_PLATFORM_LINUX
    pid_t pid;

    if ((pid = fork()) != 0)
    {
        exit(0);
    }

    setsid();

    signal(SIGINT,  SIG_IGN);
    signal(SIGHUP,  SIG_IGN);
    signal(SIGQUIT, SIG_IGN);
    signal(SIGPIPE, SIG_IGN);
    signal(SIGTTOU, SIG_IGN);
    signal(SIGTTIN, SIG_IGN);
    signal(SIGCHLD, SIG_IGN);
    signal(SIGTERM, SIG_IGN);
    signal(SIGHUP,  SIG_IGN);
    ignore_pipe_new();

    if ((pid = fork()) != 0)
    {
        exit(0);
    }

    umask(0);
#endif
}

void ProcessParameter(int argc, char* argv[])
{
    try
    {
        NFCmdLine::NFParser cmdParser;

        cmdParser.Add("AllMoreServer", 0, "more server, must use different loaded server");
        cmdParser.Add<std::string>("Server", 0, "Server Name", false, "AllServer");
        cmdParser.Add<std::string>("ID", 0, "Server ID", false, "1.1.1.1");
        cmdParser.Add<std::string>("Config", 0, "Config Path", false, "../../Config");
        cmdParser.Add<std::string>("Path", 0, "Config Path", false, "../../Config");
        cmdParser.Add<std::string>("Plugin", 0, "Config Path", false, "../../Plugin");
        cmdParser.Add<std::string>("LogPath", 0, "Log Path", false, "logs");
        cmdParser.Add<std::string>("LuaScript", 0, "Lua Script Path", false, "../ScriptModule");
        cmdParser.Add("XButton", 'x', "Close the 'X' button, only on windows");
        cmdParser.Add("Daemon", 'd', "Run it as daemon mode, only on linux");
        cmdParser.Add("Stop", 0, "Stop the run server, only on linux");
        cmdParser.Add("Reload", 0, "Reload the run server, only on linux");
        cmdParser.Add("Quit", 0, "Quit the run server, only on linux");
        cmdParser.Add("Restart", 0, "close the run server, restart new proc, only on linux");
        cmdParser.Add("Start", 0, "Start the run server, only on linux");
        cmdParser.Add("Init", 0, "change shm mode to init, only on linux");
        cmdParser.Add("Kill", 0, "kill the run server, only on linux");
        cmdParser.Add<std::string>("Param", 0, "Temp Param, You love to use it", false, "Param");

        cmdParser.Usage();

        cmdParser.ParseCheck(argc, argv);

        std::string strAppName = cmdParser.Get<std::string>("Server");
        if (cmdParser.Exist("AllMoreServer") && strAppName == "AllServer")
        {
            NFGlobalSystem::Instance()->SetMoreServer(true);
            std::string strBusName = cmdParser.Get<std::string>("ID");
            std::string strConfigPath = cmdParser.Get<std::string>("Config");
            std::string strPlugin = cmdParser.Get<std::string>("Plugin");
            NFGlobalSystem::Instance()->LoadConfig(strPlugin);
            const proto_ff::pbPluginConfig* pPlugConfig = NFGlobalSystem::Instance()->GetAllMoreServerConfig();
            for(int i = 0; i < (int)pPlugConfig->serverlist_size(); i++) {
                const ::proto_ff::pbAllServerConfig& serverConfig = pPlugConfig->serverlist(i);
                std::vector<std::string> vecParam;
                vecParam.push_back(argv[0]);
                vecParam.push_back("--Server="+serverConfig.server());
                vecParam.push_back("--ID="+serverConfig.id());
                vecParam.push_back("--Config="+strConfigPath);
                vecParam.push_back("--Plugin="+strPlugin);
                vecParam.push_back("--restart");
                NFIPluginManager* pPluginManager = (NFIPluginManager*)(new NFCPluginManager());
                ProcessParameter(pPluginManager, vecParam);
                NFGlobalSystem::Instance()->SetGlobalPluginManager(pPluginManager);
                NFGlobalSystem::Instance()->AddPluginManager(pPluginManager);
            }
        }
        else {
            std::vector<std::string> vecParam;
            for(int i = 0; i < argc; i++) {
                vecParam.push_back(argv[i]);
            }
            NFIPluginManager* pPluginManager = (NFIPluginManager*)(new NFCPluginManager());
            ProcessParameter(pPluginManager, vecParam);
            NFGlobalSystem::Instance()->SetGlobalPluginManager(pPluginManager);
            NFGlobalSystem::Instance()->AddPluginManager(pPluginManager);
        }
    }
    catch (NFCmdLine::NFCmdLine_Error& e)
    {
        std::cout << e.what() << std::endl;
        NFSLEEP(1000);
        exit(0);
    }
}

void ProcessParameter(NFIPluginManager* pPluginManager, const std::vector<std::string>& vecParam)
{
    try
    {
        NFCmdLine::NFParser cmdParser;

        cmdParser.Add<std::string>("Server", 0, "Server Name", false, "AllServer");
        cmdParser.Add<std::string>("ID", 0, "Server ID", false, "1.1.1.1");
        cmdParser.Add<std::string>("Config", 0, "Config Path", false, "../../Config");
        cmdParser.Add<std::string>("Path", 0, "Config Path", false, "../../Config");
        cmdParser.Add<std::string>("Plugin", 0, "Config Path", false, "../../Plugin");
        cmdParser.Add<std::string>("LogPath", 0, "Log Path", false, "logs");
        cmdParser.Add<std::string>("LuaScript", 0, "Lua Script Path", false, "../ScriptModule");
        cmdParser.Add("XButton", 'x', "Close the 'X' button, only on windows");
        cmdParser.Add("Daemon", 'd', "Run it as daemon mode, only on linux");
        cmdParser.Add("Stop", 0, "Stop the run server, only on linux");
        cmdParser.Add("Reload", 0, "Reload the run server, only on linux");
        cmdParser.Add("Quit", 0, "Quit the run server, only on linux");
        cmdParser.Add("Restart", 0, "close the run server, restart new proc, only on linux");
        cmdParser.Add("Start", 0, "Start the run server, only on linux");
        cmdParser.Add("Init", 0, "change shm mode to init, only on linux");
        cmdParser.Add("Kill", 0, "kill the run server, only on linux");
        cmdParser.Add<std::string>("Param", 0, "Temp Param, You love to use it", false, "Param");

        cmdParser.Usage();

        cmdParser.ParseCheck(vecParam);

        pPluginManager->SetFullPath(vecParam[0]);

        std::string strParam = cmdParser.Get<std::string>("Param");
        pPluginManager->SetStrParam(strParam);

        std::string strAppName = cmdParser.Get<std::string>("Server");
        pPluginManager->SetAppName(strAppName);

        if (strAppName == ALL_SERVER || strAppName == "TestServer" || strAppName == "RobotServer")
        {
            pPluginManager->SetLoadAllServer(true);
        }

        std::string strBusName = cmdParser.Get<std::string>("ID");

        uint32_t mBusId = NFServerIDUtil::GetBusID(strBusName);

        if (mBusId <= 0)
        {
            std::cerr << "ID:" << strBusName << std::endl;
            std::cerr << cmdParser.Usage() << std::endl;
            exit(0);
        }

        pPluginManager->SetBusName(strBusName);
        pPluginManager->SetAppID(mBusId);
        if (cmdParser.Exist("Config"))
        {
            std::string strDataPath = cmdParser.Get<std::string>("Config");
            pPluginManager->SetConfigPath(strDataPath);
        }
        else if (cmdParser.Exist("Path"))
        {
            std::string strDataPath = cmdParser.Get<std::string>("Path");
            pPluginManager->SetConfigPath(strDataPath);
        }
        else
        {
            std::string strDataPath = cmdParser.Get<std::string>("Config");
            pPluginManager->SetConfigPath(strDataPath);
        }

        std::string strPlugin = cmdParser.Get<std::string>("Plugin");
        pPluginManager->SetPluginPath(strPlugin);

        std::string luaScript = cmdParser.Get<std::string>("LuaScript");
        pPluginManager->SetLuaScriptPath(luaScript);
        std::string logPath = cmdParser.Get<std::string>("LogPath");
        pPluginManager->SetLogPath(logPath);

        pPluginManager->SetPidFileName();
#if NF_PLATFORM == NF_PLATFORM_WIN
        if (cmdParser.Exist("XButton"))
		{
			CloseXButton();
		}
#else
        if (cmdParser.Exist("Init"))
        {
            pPluginManager->SetInitShm();
        }

        if (cmdParser.Exist("Kill"))
        {
            pPluginManager->SetKillPreApp(true);
        }

        if (cmdParser.Exist("Stop"))
        {
            pPluginManager->KillApp();
            exit(0);
        }
        else if (cmdParser.Exist("Reload"))
        {
            pPluginManager->ReloadApp();
            exit(0);
        }

        else if (cmdParser.Exist("Quit"))
        {
            pPluginManager->QuitApp();
            exit(0);
        }
        else if (cmdParser.Exist("Restart"))
        {
            //run it as a daemon process
            if (cmdParser.Exist("Daemon"))
            {
                pPluginManager->SetDaemon();
                InitDaemon();
            }

            InitSignal();

            if (pPluginManager->KillPreApp() < 0)
            {
                std::cout << "kill pre app failed!" << std::endl;
                exit(0);
            }

            if (pPluginManager->CreatePidFile() < 0)
            {
                std::cout << "create " << pPluginManager->GetFullPath() << " pid " << pPluginManager->GetPidFileName() << "failed!" << std::endl;
                exit(0);
            }
        }
        else if (cmdParser.Exist("Start"))
        {
            //run it as a daemon process
            if (cmdParser.Exist("Daemon"))
            {
                pPluginManager->SetDaemon();
                InitDaemon();
            }

            InitSignal();

            if (pPluginManager->GetKillPreApp())
            {
                if (pPluginManager->KillPreApp() < 0)
                {
                    std::cout << "kill pre app failed!" << std::endl;
                    exit(0);
                }
            }

            if (pPluginManager->CheckPidFile() < 0)
            {
                std::cout << "check " << pPluginManager->GetFullPath() << " pid " << pPluginManager->GetPidFileName() << " failed!" << std::endl;
                exit(0);
            }

            if (pPluginManager->CreatePidFile() < 0)
            {
                std::cout << "create " << pPluginManager->GetFullPath() << " pid " << pPluginManager->GetPidFileName() << " failed!" << std::endl;
                exit(0);
            }
        }

#endif

        std::string strTitleName = "NF" + strAppName + NFCommon::tostr(strBusName);// +" PID" + NFGetPID();
#if NF_PLATFORM == NF_PLATFORM_WIN
        SetConsoleTitle(strTitleName.c_str());
#elif NF_PLATFORM == NF_PLATFORM_LINUX
        prctl(PR_SET_NAME, strTitleName.c_str());
        //setproctitle(strTitleName.c_str());
#endif
    }
    catch (NFCmdLine::NFCmdLine_Error& e)
    {
        std::cout << e.what() << std::endl;
        NFSLEEP(1000);
        exit(0);
    }
}