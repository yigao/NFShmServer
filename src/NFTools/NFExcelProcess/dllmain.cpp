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
#pragma comment( lib, "libprotobuf.lib" )
#pragma comment( lib, "Dbghelp.lib" )
//////////////////////////////////////////////////////////////////
#pragma comment( lib, "common.lib" )
#pragma comment( lib, "LuaBind.lib" )

/////////////////////////////////////////////////////////////////
#pragma comment( lib, "NFCore.lib" )
#pragma comment( lib, "NFPluginModule.lib" )
#pragma comment( lib, "NFKernelMessage.lib" )
#else
/////////////////////////////////////////////////////////////////
#endif
#endif