﻿// -------------------------------------------------------------------------
//    @FileName         :    dllmain.cpp
//    @Author           :    GaoYi
//    @Date             :    2018/05/25
//    @Email			:    445267987@qq.com
//    @Module           :    NFPluginLoader
//
// -------------------------------------------------------------------------
#include "NFComm/NFCore/NFPlatform.h"

#if NF_PLATFORM == NF_PLATFORM_WIN

#ifndef NF_DYNAMIC_PLUGIN

#pragma comment(lib,"msvcrtd.lib")
#pragma comment(lib, "libssl.lib")
#pragma comment(lib, "libcrypto.lib")
#pragma comment(lib, "version.lib")
#pragma comment(lib, "netapi32.lib")

////////////////////////////////////////////////////////////////
#pragma comment(lib, "ws2_32.lib")
#pragma comment(lib, "Secur32.lib")
#pragma comment( lib, "Crypt32.lib" )
#pragma comment( lib, "BCrypt.lib" )
#pragma comment( lib, "Dnsapi.lib" )
#pragma comment( lib, "Wldap32.lib" )
#pragma comment( lib, "advapi32.lib" )

////////////////////////////////////////////////////////////////

#pragma comment( lib, "event.lib" )
#pragma comment( lib, "event_core.lib" )
#pragma comment( lib, "libprotobuf.lib" )
#pragma comment( lib, "Theron.lib" )
#pragma comment( lib, "user32.lib")
#pragma comment( lib, "Dbghelp.lib" )
#pragma comment( lib, "mysqlclient.lib" )
#pragma comment( lib, "libcurl.lib" )
//////////////////////////////////////////////////////////////////
#pragma comment( lib, "common.lib" )
#pragma comment( lib, "evpp.lib" )
#pragma comment( lib, "LuaBind.lib" )
#pragma comment( lib, "mysqlpp.lib" )

/////////////////////////////////////////////////////////////////
#pragma comment( lib, "NFCore.lib" )
#pragma comment( lib, "NFPluginModule.lib" )
#pragma comment( lib, "NFKernelMessage.lib" )
#pragma comment( lib, "NFShmCore.lib" )
#pragma comment( lib, "NFPluginManager.lib" )


////////////////////////////////////////////////////////////////
#pragma comment( lib, "NFKernelPlugin.lib" )
#pragma comment( lib, "NFNetPlugin.lib" )
#pragma comment( lib, "NFShmPlugin.lib" )
#else
/////////////////////////////////////////////////////////////////
#endif
#endif