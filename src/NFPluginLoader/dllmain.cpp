// -------------------------------------------------------------------------
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

////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////
#pragma comment( lib, "libcurl.lib" )
#pragma comment( lib, "event.lib" )
#pragma comment( lib, "event_core.lib" )
#pragma comment( lib, "libprotobuf.lib" )
#pragma comment( lib, "Theron.lib" )
#pragma comment( lib, "mysqlclient.lib" )
//////////////////////////////////////////////////////////////////
#pragma comment( lib, "evpp.lib" )
#pragma comment( lib, "mysqlpp.lib" )

/////////////////////////////////////////////////////////////////
#pragma comment( lib, "NFCore.lib" )
#pragma comment( lib, "NFPluginModule.lib" )
#pragma comment( lib, "NFKernelMessage.lib" )
#pragma comment( lib, "NFShmCore.lib" )
#pragma comment( lib, "NFPluginManager.lib" )

#else
/////////////////////////////////////////////////////////////////
#endif
#endif