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

extern std::string PrintfLogo();
