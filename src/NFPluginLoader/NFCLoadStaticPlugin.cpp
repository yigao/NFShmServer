// -------------------------------------------------------------------------
//    @FileName         :    NFCLoadStaticPlugin.cpp
//    @Author           :    xxxxx
//    @Date             :   xxxx-xx-xx
//    @Email			:    xxxxxxxxx@xxx.xxx
//    @Module           :    NFPluginLoader
//
// -------------------------------------------------------------------------
#include "NFCPluginManager.h"
#include "NFComm/NFCore/NFPlatform.h"

#include "NFComm/NFPluginModule/NFIEventModule.h"
#include "NFComm/NFPluginModule/NFITimerModule.h"
#include "NFComm/NFPluginModule/NFIConfigModule.h"
#include "NFComm/NFPluginModule/NFILogModule.h"
#include "NFComm/NFPluginModule/NFITaskModule.h"

#include "NFComm/NFPluginModule/NFEventMgr.h"
#include "NFComm/NFPluginModule/NFTimerMgr.h"
#include "NFComm/NFPluginModule/NFLogMgr.h"
#include "NFComm/NFPluginModule/NFConfigMgr.h"

#ifndef NF_DYNAMIC_PLUGIN

#include "NFCommPlugin/NFKernelPlugin/NFKernelPlugin.h"
#include "NFCommPlugin/NFNetPlugin/NFNetPlugin.h"
#include "NFCommPlugin/NFShmPlugin/NFShmPlugin.h"
#include "NFTest/NFTestPlugin/NFTestPlugin.h"
#include "NFTest/NFRobotPlugin/NFRobotPlugin.h"

	//////////////////////////////CommLogic Plugin/////////////////////////////////
#include "NFServer/NFCommLogic/NFCommLogicPlugin/NFCommLogicPlugin.h"
//////////////////////////////CommLogic Plugin/////////////////////////////////

//////////////////////////////MasterServer Plugin/////////////////////////////////
#include "NFServer/NFMasterServer/NFMasterServerPlugin/NFMasterServerPlugin.h"
//////////////////////////////MasterServer Plugin/////////////////////////////////
//////////////////////////////ProxyAgentServer Plugin/////////////////////////////////
#include "NFServer/NFProxyAgentServer/NFProxyAgentServerPlugin.h"
//////////////////////////////ProxyAgentServer Plugin/////////////////////////////////
//////////////////////////////ProxyServer Plugin/////////////////////////////////
#include "NFServer/NFProxyServer/NFProxyServerPlugin/NFProxyServerPlugin.h"
#include "NFServerLogic/NFProxyServer/NFProxyClientPlugin/NFProxyClientPlugin.h"
//////////////////////////////ProxyServer Plugin/////////////////////////////////
//////////////////////////////GameServer Plugin/////////////////////////////////
#include "NFServer/NFGameServer/NFGameServerPlugin/NFGameServerPlugin.h"

//////////////////////////////GameServer Plugin/////////////////////////////////
//////////////////////////////LoginServer Plugin/////////////////////////////////
#include "NFServer/NFLoginServer/NFLoginServerPlugin/NFLoginServerPlugin.h"
#include "NFServerLogic/NFLoginServer/NFLoginServerPlayerPlugin/NFLoginServerPlayerPlugin.h"
//////////////////////////////LoginServer Plugin/////////////////////////////////
//////////////////////////////WorldServer Plugin/////////////////////////////////
#include "NFServer/NFWorldServer/NFWorldServerPlugin/NFWorldServerPlugin.h"
#include "NFServerLogic/NFWorldServer/NFWorldServerPlayerPlugin/NFWorldServerPlayerPlugin.h"
//////////////////////////////WorldServer Plugin/////////////////////////////////
//////////////////////////////RouteAgentServer Plugin/////////////////////////////////
#include "NFServer/NFRouteAgentServer/NFRouteAgentServerPlugin/NFRouteAgentServerPlugin.h"
//////////////////////////////RouteAgentServer Plugin/////////////////////////////////
//////////////////////////////RouteServer Plugin/////////////////////////////////
#include "NFServer/NFRouteServer/NFRouteServerPlugin/NFRouteServerPlugin.h"
//////////////////////////////RouteServer Plugin/////////////////////////////////
//////////////////////////////StoreServer Plugin/////////////////////////////////
#include "NFServer/NFStoreServer/NFStoreServerPlugin/NFStoreServerPlugin.h"
//////////////////////////////StoreServer Plugin/////////////////////////////////
//////////////////////////////SnsServer Plugin/////////////////////////////////
#include "NFServer/NFSnsServer/NFSnsServerPlugin/NFSnsServerPlugin.h"
#include "NFServerLogic/NFSnsServer/NFSnsServerPlayerPlugin/NFSnsServerPlayerPlugin.h"
//////////////////////////////SnsServer Plugin/////////////////////////////////
//////////////////////////////LogicServer Plugin/////////////////////////////////
#include "NFServer/NFLogicServer/NFLogicServerPlugin/NFLogicServerPlugin.h"
#include "NFServerLogic/NFLogicServer/NFLogicServerPlayerPlugin/NFLogicServerPlayerPlugin.h"
//////////////////////////////LogicServer Plugin/////////////////////////////////
//////////////////////////////WebServer Plugin/////////////////////////////////
#include "NFServer/NFWebServer/NFWebServerPlugin/NFWebServerPlugin.h"
#include "NFServerLogic/NFWebServer/NFWebServerLogicPlugin/NFWebServerLogicPlugin.h"
//////////////////////////////WebServer Plugin/////////////////////////////////
#endif

bool NFCPluginManager::LoadKernelPlugin()
{
#ifndef NF_DYNAMIC_PLUGIN
	m_nPluginNameVec.push_back("NFKernelPlugin");
	LoadStaticPlugin("NFKernelPlugin");
#else
	m_nPluginNameVec.push_back("NFKernelPlugin");
	LoadPluginLibrary("NFKernelPlugin");
#endif

	/*
		log 系统第一个启动，然后是配置
	*/
	((NFIPluginManager*)this)->FindModule<NFILogModule>()->InitLogSystem();
	/*
		加载服务器配置
	*/
	((NFIPluginManager*)this)->FindModule<NFIConfigModule>()->LoadConfig();
	/*
		log 加载配置
	*/
	((NFIPluginManager*)this)->FindModule<NFILogModule>()->SetDefaultLogConfig();

    /*
        启动多线程任务系统
    */
    if (IsLoadAllServer())
    {
        ((NFIPluginManager*)this)->FindModule<NFITaskModule>()->InitActorThread(1);
    }
    else
    {
        NFServerConfig* pConfig = NFConfigMgr::Instance()->GetAppConfig(NF_ST_NONE);
        NF_ASSERT(pConfig);

        ((NFIPluginManager*)this)->FindModule<NFITaskModule>()->InitActorThread(pConfig->mWorkThreadNum);
    }
	return true;
}

bool NFCPluginManager::RegisterStaticPlugin()
{
#ifndef NF_DYNAMIC_PLUGIN
	REGISTER_STATIC_PLUGIN(this, NFKernelPlugin);
	#pragma comment( lib, "NFKernelPlugin.lib" )

	REGISTER_STATIC_PLUGIN(this, NFNetPlugin);
	#pragma comment( lib, "NFNetPlugin.lib" )

	REGISTER_STATIC_PLUGIN(this, NFShmPlugin);
	#pragma comment( lib, "NFShmPlugin.lib" )

	REGISTER_STATIC_PLUGIN(this, NFTestPlugin);
	#pragma comment( lib, "NFTestPlugin.lib" )

	REGISTER_STATIC_PLUGIN(this, NFRobotPlugin);
	#pragma comment( lib, "NFRobotPlugin.lib" )

	//////////////////////////////CommLogic Plugin/////////////////////////////////
	REGISTER_STATIC_PLUGIN(this, NFCommLogicPlugin);
	#pragma comment( lib, "NFCommLogicPlugin.lib" )
//////////////////////////////CommLogic Plugin/////////////////////////////////

//////////////////////////////MasterServer Plugin/////////////////////////////////
	REGISTER_STATIC_PLUGIN(this, NFMasterServerPlugin);
	#pragma comment( lib, "NFMasterServerPlugin.lib" )
//////////////////////////////MasterServer Plugin/////////////////////////////////
		//////////////////////////////ProxyAgentServer Plugin/////////////////////////////////
	REGISTER_STATIC_PLUGIN(this, NFProxyAgentServerPlugin);
	#pragma comment( lib, "NFProxyAgentServerPlugin.lib" )

	//////////////////////////////ProxyAgentServer Plugin/////////////////////////////////
	//////////////////////////////ProxyServer Plugin/////////////////////////////////
	REGISTER_STATIC_PLUGIN(this, NFProxyServerPlugin);
	#pragma comment( lib, "NFProxyServerPlugin.lib" )
	REGISTER_STATIC_PLUGIN(this, NFProxyClientPlugin);
	#pragma comment( lib, "NFProxyClientPlugin.lib" )
	//////////////////////////////ProxyServer Plugin/////////////////////////////////
//////////////////////////////GameServer Plugin/////////////////////////////////
	REGISTER_STATIC_PLUGIN(this, NFGameServerPlugin);
	#pragma comment( lib, "NFGameServerPlugin.lib" )

//////////////////////////////GameServer Plugin/////////////////////////////////
//////////////////////////////LoginServer Plugin/////////////////////////////////
	REGISTER_STATIC_PLUGIN(this, NFLoginServerPlugin);
	#pragma comment( lib, "NFLoginServerPlugin.lib" )
	REGISTER_STATIC_PLUGIN(this, NFLoginServerPlayerPlugin);
#pragma comment( lib, "NFLoginServerPlayerPlugin.lib" )
//////////////////////////////LoginServer Plugin/////////////////////////////////
//////////////////////////////WorldServer Plugin/////////////////////////////////
	REGISTER_STATIC_PLUGIN(this, NFWorldServerPlugin); 
	#pragma comment(lib, "NFWorldServerPlugin.lib")
	REGISTER_STATIC_PLUGIN(this, NFWorldServerPlayerPlugin);
	#pragma comment(lib, "NFWorldServerPlayerPlugin.lib")
//////////////////////////////WorldServer Plugin/////////////////////////////////
//////////////////////////////RouteAgentServer Plugin/////////////////////////////////
	REGISTER_STATIC_PLUGIN(this, NFRouteAgentServerPlugin);
	#pragma comment( lib, "NFRouteAgentServerPlugin.lib" )
//////////////////////////////RouteAgentServer Plugin/////////////////////////////////
//////////////////////////////RouteServer Plugin/////////////////////////////////
	REGISTER_STATIC_PLUGIN(this, NFRouteServerPlugin);
	#pragma comment( lib, "NFRouteServerPlugin.lib" )
//////////////////////////////RouteServer Plugin/////////////////////////////////
//////////////////////////////StoreServer Plugin/////////////////////////////////
	REGISTER_STATIC_PLUGIN(this, NFStoreServerPlugin);
	#pragma comment( lib, "NFStoreServerPlugin.lib" )
//////////////////////////////StoreServer Plugin/////////////////////////////////
//////////////////////////////SnsServer Plugin/////////////////////////////////
	REGISTER_STATIC_PLUGIN(this, NFSnsServerPlugin);
	#pragma comment( lib, "NFSnsServerPlugin.lib" )
	REGISTER_STATIC_PLUGIN(this, NFSnsServerPlayerPlugin);
	#pragma comment( lib, "NFSnsServerPlayerPlugin.lib" )
//////////////////////////////SnsServer Plugin/////////////////////////////////
//////////////////////////////LogicServer Plugin/////////////////////////////////
	REGISTER_STATIC_PLUGIN(this, NFLogicServerPlugin);
	#pragma comment( lib, "NFLogicServerPlugin.lib" )
	REGISTER_STATIC_PLUGIN(this, NFLogicServerPlayerPlugin);
	#pragma comment( lib, "NFLogicServerPlayerPlugin.lib" )
//////////////////////////////LogicServer Plugin/////////////////////////////////
	//////////////////////////////WebServer Plugin/////////////////////////////////
	REGISTER_STATIC_PLUGIN(this, NFWebServerPlugin);
	#pragma comment( lib, "NFWebServerPlugin.lib" )
	REGISTER_STATIC_PLUGIN(this, NFWebServerLogicPlugin);
	#pragma comment( lib, "NFWebServerLogicPlugin.lib" )
//////////////////////////////WebServer Plugin/////////////////////////////////
#endif
	return true;
}
