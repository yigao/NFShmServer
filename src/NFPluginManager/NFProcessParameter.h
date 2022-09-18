// -------------------------------------------------------------------------
//    @FileName         :    NFPrintfLogo.h
//    @Author           :    Yi.Gao
//    @Date             :   2022-09-18
//    @Module           :    NFPluginManager
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

#include "NFPluginManager/NFCPluginManager.h"
#include "NFComm/NFCore/NFPlatform.h"
#include "NFComm/NFCore/NFCmdLine.h"
#include "NFComm/NFCore/NFCommon.h"
#include "NFComm/NFCore/NFFileUtility.h"
#include "NFComm/NFCore/NFSocketLibFunction.h"
#include "NFPluginManager/NFCrashHandlerMgr.h"
#include "NFPluginManager/NFSignalHandleMgr.h"
#include "NFPluginManager/NFPrintfLogo.h"
#include "NFComm/NFCore/NFServerIDUtil.h"

#if NF_PLATFORM == NF_PLATFORM_LINUX
#include <unistd.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <signal.h>
#include <sys/prctl.h>
#endif

void CloseXButton();
void ignore_pipe_new();

//转变成守护进程后，会新建一个进程
void InitDaemon();
void ProcessParameter(int argc, char* argv[]);
void ProcessParameter(NFIPluginManager* pPluginManager, const std::vector<std::string>& vecParam);