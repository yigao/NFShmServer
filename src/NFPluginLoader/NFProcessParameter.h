// -------------------------------------------------------------------------
//    @FileName         :    NFPrintfLogo.h
//    @Author           :    Yi.Gao
//    @Date             :   xxxx-xx-xx
//    @Module           :    NFPluginLoader
//
// -------------------------------------------------------------------------

#pragma once

#include <time.h>
#include <stdio.h>
#include <iostream>
#include <utility>
#include <thread>
#include <chrono>
#include <future>
#include <functional>
#include <atomic>

#include "NFCPluginManager.h"
#include "NFComm/NFCore/NFPlatform.h"
#include "NFComm/NFCore/NFCmdLine.h"
#include "NFComm/NFCore/NFCommon.h"
#include "NFComm/NFCore/NFFileUtility.h"
#include "NFComm/NFCore/NFSocketLibFunction.h"
#include "NFCrashHandlerMgr.h"
#include "NFSignalHandleMgr.h"
#include "NFPrintfLogo.h"
#include "NFComm/NFCore/NFServerIDUtil.h"

#if NF_PLATFORM == NF_PLATFORM_LINUX
#include <unistd.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <signal.h>
#include <sys/prctl.h>
#endif

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

		NFCPluginManager::GetSingletonPtr()->SetFullPath(argv[0]);

        std::string strParam = cmdParser.Get<std::string>("Param");
        NFCPluginManager::GetSingletonPtr()->SetStrParam(strParam);

		std::string strAppName = cmdParser.Get<std::string>("Server");
		NFCPluginManager::GetSingletonPtr()->SetAppName(strAppName);

		if (strAppName == ALL_SERVER || strAppName == "TestServer" || strAppName == "RobotServer")
		{
            NFCPluginManager::GetSingletonPtr()->SetLoadAllServer(true);
        }

		std::string strBusName = cmdParser.Get<std::string>("ID");

		uint32_t mBusId = NFServerIDUtil::GetBusID(strBusName);

		if (mBusId <= 0)
		{
			std::cerr << "ID:" << strBusName << std::endl;
			std::cerr << cmdParser.Usage() << std::endl;
			exit(0);
		}

		NFCPluginManager::GetSingletonPtr()->SetBusName(strBusName);
		NFCPluginManager::GetSingletonPtr()->SetAppID(mBusId);
		if (cmdParser.Exist("Config"))
		{
			std::string strDataPath = cmdParser.Get<std::string>("Config");
			NFCPluginManager::GetSingletonPtr()->SetConfigPath(strDataPath);
		}
		else if (cmdParser.Exist("Path"))
		{
			std::string strDataPath = cmdParser.Get<std::string>("Path");
			NFCPluginManager::GetSingletonPtr()->SetConfigPath(strDataPath);
		}
		else
		{
			std::string strDataPath = cmdParser.Get<std::string>("Config");
			NFCPluginManager::GetSingletonPtr()->SetConfigPath(strDataPath);
		}

		std::string strPlugin = cmdParser.Get<std::string>("Plugin");
		NFCPluginManager::GetSingletonPtr()->SetPluginPath(strPlugin);

		std::string luaScript = cmdParser.Get<std::string>("LuaScript");
		NFCPluginManager::GetSingletonPtr()->SetLuaScriptPath(luaScript);
		std::string logPath = cmdParser.Get<std::string>("LogPath");
		NFCPluginManager::GetSingletonPtr()->SetLogPath(logPath);

		NFCPluginManager::GetSingletonPtr()->SetPidFileName();
#if NF_PLATFORM == NF_PLATFORM_WIN
		if (cmdParser.Exist("XButton"))
		{
			CloseXButton();
		}
#else
		if (cmdParser.Exist("Init"))
		{
			NFCPluginManager::GetSingletonPtr()->SetInitShm();
		}

		if (cmdParser.Exist("Kill"))
		{
			NFCPluginManager::GetSingletonPtr()->SetKillPreApp(true);
		}

		if (cmdParser.Exist("Stop"))
		{
			NFCPluginManager::GetSingletonPtr()->KillApp();
			exit(0);
		}
		else if (cmdParser.Exist("Reload"))
		{
			NFCPluginManager::GetSingletonPtr()->ReloadApp();
			exit(0);
		}

		else if (cmdParser.Exist("Quit"))
		{
			NFCPluginManager::GetSingletonPtr()->QuitApp();
			exit(0);
		}
		else if (cmdParser.Exist("Restart"))
		{
			//run it as a daemon process
			if (cmdParser.Exist("Daemon"))
			{
				NFCPluginManager::GetSingletonPtr()->SetDaemon();
				InitDaemon();
			}

			InitSignal();

			if (NFCPluginManager::GetSingletonPtr()->KillPreApp() < 0)
			{
				std::cout << "kill pre app failed!" << std::endl;
				exit(0);
			}

			if (NFCPluginManager::GetSingletonPtr()->CreatePidFile() < 0)
			{
				std::cout << "create " << NFCPluginManager::GetSingletonPtr()->GetFullPath() << " pid " << NFCPluginManager::GetSingletonPtr()->GetPidFileName() << "failed!" << std::endl;
				exit(0);
			}
		}
		else if (cmdParser.Exist("Start"))
		{
			//run it as a daemon process
			if (cmdParser.Exist("Daemon"))
			{
				NFCPluginManager::GetSingletonPtr()->SetDaemon();
				InitDaemon();
			}

			InitSignal();

			if (NFCPluginManager::GetSingletonPtr()->GetKillPreApp())
			{
				if (NFCPluginManager::GetSingletonPtr()->KillPreApp() < 0)
				{
					std::cout << "kill pre app failed!" << std::endl;
					exit(0);
				}
			}

			if (NFCPluginManager::GetSingletonPtr()->CheckPidFile() < 0)
			{
				std::cout << "check " << NFCPluginManager::GetSingletonPtr()->GetFullPath() << " pid " << NFCPluginManager::GetSingletonPtr()->GetPidFileName() << " failed!" << std::endl;
				exit(0);
			}

			if (NFCPluginManager::GetSingletonPtr()->CreatePidFile() < 0)
			{
				std::cout << "create " << NFCPluginManager::GetSingletonPtr()->GetFullPath() << " pid " << NFCPluginManager::GetSingletonPtr()->GetPidFileName() << " failed!" << std::endl;
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
