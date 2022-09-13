// -------------------------------------------------------------------------
//    @FileName         :    dllmain.cpp
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFPluginLoader
//
// -------------------------------------------------------------------------
#include "NFComm/NFCore/NFPlatform.h"

#if NF_PLATFORM == NF_PLATFORM_WIN

#ifndef NF_DYNAMIC_PLUGIN

#pragma comment( lib, "user32.lib")
#pragma comment( lib, "Dbghelp.lib" )
#pragma comment(lib,"msvcrtd.lib")
#pragma comment(lib, "version.lib")
#pragma comment(lib, "netapi32.lib")

////////////////////////////////////////////////////////////////
#pragma comment(lib, "common.lib")
#pragma comment( lib, "luaBind.lib" )
#pragma comment( lib, "libprotobuf.lib" )
#pragma comment( lib, "event.lib" )
#pragma comment( lib, "event_core.lib" )
#pragma comment( lib, "evpp.lib" )
#pragma comment( lib, "mysqlclient.lib" )
#pragma comment( lib, "mysqlpp.lib" )
#pragma comment( lib, "Theron.lib" )
/////////////////////////////////////////////////////////////////
#pragma comment( lib, "NFCore.lib" )
#pragma comment( lib, "NFPluginModule.lib" )
#pragma comment( lib, "NFMessageDefine.lib" )
#pragma comment( lib, "NFKernelMessage.lib" )
#pragma comment( lib, "NFShmCore.lib" )
#else
#pragma comment( lib, "user32.lib")
#pragma comment( lib, "Dbghelp.lib" )
#pragma comment(lib,"msvcrtd.lib")
#pragma comment(lib, "version.lib")
#pragma comment(lib, "netapi32.lib")

////////////////////////////////////////////////////////////////
#pragma comment(lib, "common.lib")
#pragma comment( lib, "luaBind.lib" )
#pragma comment( lib, "protobuf.lib" )


/////////////////////////////////////////////////////////////////
#pragma comment( lib, "NFCore.lib" )
#pragma comment( lib, "NFPluginModule.lib" )
#pragma comment( lib, "NFMessageDefine.lib" )
#endif
#endif