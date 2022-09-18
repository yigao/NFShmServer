// -------------------------------------------------------------------------
//    @FileName         :    NFPluginManager.cpp
//    @Author           :    LvSheng.Huang
//    @Date             :   2022-09-18
//    @Module           :    NFPluginManager
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

#include "NFPluginManager/NFCPluginManager.h"
#include "NFComm/NFCore/NFPlatform.h"
#include "NFComm/NFCore/NFCmdLine.h"
#include "NFComm/NFCore/NFCommon.h"
#include "NFComm/NFCore/NFFileUtility.h"

#include "NFPluginManager/NFCrashHandlerMgr.h"
#include "NFPluginManager/NFProcessParameter.h"
#include "NFComm/NFPluginModule/NFGlobalSystem.h"

int main(int argc, char* argv[])
{
#if NF_PLATFORM == NF_PLATFORM_WIN
	//SetConsoleOutputCP(CP_UTF8);
	SetUnhandledExceptionFilter((LPTOP_LEVEL_EXCEPTION_FILTER)ApplicationCrashHandler);
#elif NF_PLATFORM == NF_PLATFORM_LINUX
#endif

	ProcessParameter(argc, argv);

	std::vector<NFIPluginManager*> vecPluginManager = NFGlobalSystem::Instance()->GetPluginManagerList();

	for(int i = 0; i < (int)vecPluginManager.size(); i++)
    {
        NFIPluginManager* pPluginManager = vecPluginManager[i];
        pPluginManager->Begin();
    }

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
            for(int i = 0; i < (int)vecPluginManager.size(); i++)
            {
                NFIPluginManager* pPluginManager = vecPluginManager[i];
                pPluginManager->Execute();
                if (pPluginManager->GetReloadApp())
                {
                    pPluginManager->SetReloadApp(false);
                    pPluginManager->OnReloadPlugin();
                }

                if (pPluginManager->GetChangeProfileApp())
                {
                    pPluginManager->SetChangeProfileApp(false);
                    pPluginManager->SetOpenProfiler(!pPluginManager->IsOpenProfiler());
                }

                if (pPluginManager->GetShutDownApp())
                {
                    pPluginManager->ShutDownApp();
                    NFSLEEP(1000);
                    exit(0);
                }

                bExitApp = pPluginManager->GetExitApp();
            }

#if NF_PLATFORM == NF_PLATFORM_WIN
			}
			__except (ApplicationCrashHandler(GetExceptionInformation()))
			{
			}
#endif
		}
	}

    for(int i = 0; i < (int)vecPluginManager.size(); i++)
    {
        NFIPluginManager* pPluginManager = vecPluginManager[i];
        pPluginManager->End();
    }

	return 0;
}