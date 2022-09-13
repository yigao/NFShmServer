// -------------------------------------------------------------------------
//    @FileName         :    NFSignalHandleMgr.h
//    @Author           :    Yi.Gao
//    @Date             :   xxxx-xx-xx
//    @Module           :    NFPluginLoader
//
// -------------------------------------------------------------------------

#pragma once

#include "NFComm/NFCore/NFPlatform.h"

#if NF_PLATFORM == NF_PLATFORM_LINUX
#include <unistd.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <signal.h>
#include <sys/prctl.h>
#endif

void InitSignal();

void HandleSignal(int signo);
