// -------------------------------------------------------------------------
//    @FileName         :    NFPluginLoader.cpp
//    @Author           :    LvSheng.Huang
//    @Date             :   xxxx-xx-xx
//    @Module           :    NFPluginLoader
//
// -------------------------------------------------------------------------

//#include <crtdbg.h>
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

#include "NFCrashHandlerMgr.h"
#include "NFProcessParameter.h"

int main(int argc, char* argv[])
{
#if NF_PLATFORM == NF_PLATFORM_WIN
	//SetConsoleOutputCP(CP_UTF8);
	SetUnhandledExceptionFilter((LPTOP_LEVEL_EXCEPTION_FILTER)ApplicationCrashHandler);
#elif NF_PLATFORM == NF_PLATFORM_LINUX
#endif

	ProcessParameter(argc, argv);

	NFCPluginManager::GetSingletonPtr()->Begin();

	uint64_t nIndex = 0;
	bool bExitApp = false;
	while (!bExitApp)
	{
		while (true)
		{
			nIndex++;

			if (bExitApp)
			{
				break;
			}

#if NF_PLATFORM == NF_PLATFORM_WIN
			__try
			{
#endif
				NFCPluginManager::GetSingletonPtr()->Execute();
				if (NFCPluginManager::GetSingletonPtr()->GetReloadApp())
				{
					NFCPluginManager::GetSingletonPtr()->SetReloadApp(false);
					NFCPluginManager::GetSingletonPtr()->OnReloadPlugin();
				}

				if (NFCPluginManager::GetSingletonPtr()->GetChangeProfileApp())
				{
					NFCPluginManager::GetSingletonPtr()->SetChangeProfileApp(false);
					NFCPluginManager::GetSingletonPtr()->SetOpenProfiler(!NFCPluginManager::GetSingletonPtr()->IsOpenProfiler());
				}

				if (NFCPluginManager::GetSingletonPtr()->GetShutDownApp())
				{
				    NFCPluginManager::GetSingletonPtr()->ShutDownApp();
					NFSLEEP(1000);
					exit(0);
				}

				bExitApp = NFCPluginManager::GetSingletonPtr()->GetExitApp();
#if NF_PLATFORM == NF_PLATFORM_WIN
			}
			__except (ApplicationCrashHandler(GetExceptionInformation()))
			{
			}
#endif
		}
	}

	NFCPluginManager::GetSingletonPtr()->End();

	return 0;
}