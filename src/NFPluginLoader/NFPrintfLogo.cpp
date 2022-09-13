// -------------------------------------------------------------------------
//    @FileName         :    NFPrintfLogo.h
//    @Author           :    Yi.Gao
//    @Date             :   xxxx-xx-xx
//    @Module           :    NFPluginLoader
//
// -------------------------------------------------------------------------

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

std::string PrintfLogo()
{
	std::stringstream ios;
	ios << "\n" << std::endl;
	ios << "************************************************" << std::endl;
	ios << "**                                            **" << std::endl;
	ios << "**                NFShmFrame                  **" << std::endl;
	ios << "**          Copyright (c) 2018, gao.yi        **" << std::endl;
	ios << "**             All rights reserved.           **" << std::endl;
	ios << "**                                            **" << std::endl;
	ios << "************************************************" << std::endl;
	ios << "\n" << std::endl;
	ios << "--Daemon or -d Run it as daemon mode, only on linux" << std::endl;
	ios << "--XButton or -x Close the 'X' button, only on windows" << std::endl;
	ios << "--Server=AllServer Load the AllServer plugin when programs be launched" << std::endl;
	ios << "--ID=number(0) Load the number Server when programs be launched" << std::endl;
	ios << "--PATH=../Config Load the Config Path when programs be launched" << std::endl;
	ios << "--LuaScript=../ScriptModule Load the Config Path when programs be launched" << std::endl;
	ios << "--LogPath=./spdlog Load the Config Path when programs be launched" << std::endl;
	ios << "Input '--Exit' Programs will exit when it runs" << std::endl;
	ios << "Input '--Reload' Programs will reload plugin config when it runs" << std::endl;
	ios << "Input '--Profiler' Programs will open/close profiler when it runs" << std::endl;
#ifdef NF_DYNAMIC_PLUGIN
	ios << "Input '--Dynamic=xxplugin' Programs will dynamic load plugin when it runs" << std::endl;
#endif
	ios << "\n" << std::endl;

	return ios.str();
}
