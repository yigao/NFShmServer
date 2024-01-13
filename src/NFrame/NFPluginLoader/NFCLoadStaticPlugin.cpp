// -------------------------------------------------------------------------
//    @FileName         :    NFCLoadStaticPlugin.cpp
//    @Author           :    Gao.Yi
//    @Date             :   2022-09-18
//    @Email			:    445267987@qq.com
//    @Module           :    NFPluginManager
//
// -------------------------------------------------------------------------
#include "NFPluginManager/NFCPluginManager.h"
#include "NFComm/NFCore/NFPlatform.h"

#include "NFComm/NFPluginModule/NFIEventModule.h"
#include "NFComm/NFPluginModule/NFITimerModule.h"
#include "NFComm/NFPluginModule/NFIConfigModule.h"
#include "NFComm/NFPluginModule/NFILogModule.h"
#include "NFComm/NFPluginModule/NFITaskModule.h"

#include "NFComm/NFPluginModule/NFEventObj.h"
#include "NFComm/NFPluginModule/NFTimerObj.h"
#include "NFComm/NFPluginModule/NFLogMgr.h"
#include "NFComm/NFPluginModule/NFIConfigModule.h"

#ifndef NF_DYNAMIC_PLUGIN

#include "NFCommPlugin/NFKernelPlugin/NFKernelPlugin.h"
#include "NFCommPlugin/NFNetPlugin/NFNetPlugin.h"
#include "NFCommPlugin/NFShmPlugin/NFShmPlugin.h"
#include "NFCommPlugin/NFDBPlugin/NFDBPlugin.h"
#include "NFCommPlugin/NFXPlugin/NFLuaScriptPlugin/NFLuaScriptPlugin.h"
#include "NFServerComm/NFServerCommonPlugin/NFServerCommonPlugin.h"
#include "NFServerComm/NFDescStorePlugin/NFDescStorePlugin.h"
#include "NFTest/NFTestPlugin/NFTestPlugin.h"

//////////////////////////////CommLogic Plugin/////////////////////////////////
//////////////////////////////CommLogic Plugin/////////////////////////////////

//////////////////////////////MasterServer Plugin/////////////////////////////////
#include "NFServer/NFMasterServer/NFMasterServerPlugin/NFMasterServerPlugin.h"
//////////////////////////////MasterServer Plugin/////////////////////////////////
//////////////////////////////ProxyAgentServer Plugin/////////////////////////////////
#include "NFServer/NFProxyAgentServer/NFProxyAgentServerPlugin.h"
//////////////////////////////ProxyAgentServer Plugin/////////////////////////////////
//////////////////////////////ProxyServer Plugin/////////////////////////////////
#include "NFServer/NFProxyServer/NFProxyServerPlugin/NFProxyServerPlugin.h"
#include "NFServer/NFProxyServer/NFProxyClientPlugin/NFProxyClientPlugin.h"
//////////////////////////////ProxyServer Plugin/////////////////////////////////
//////////////////////////////GameServer Plugin/////////////////////////////////
#include "NFServer/NFGameServer/NFGameServerPlugin/NFGameServerPlugin.h"
//////////////////////////////GameServer Plugin/////////////////////////////////
//////////////////////////////LoginServer Plugin/////////////////////////////////
#include "NFServer/NFLoginServer/NFLoginServerPlugin/NFLoginServerPlugin.h"
//////////////////////////////LoginServer Plugin/////////////////////////////////
//////////////////////////////WorldServer Plugin/////////////////////////////////
#include "NFServer/NFWorldServer/NFWorldServerPlugin/NFWorldServerPlugin.h"
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
//////////////////////////////SnsServer Plugin/////////////////////////////////
//////////////////////////////LogicServer Plugin/////////////////////////////////
#include "NFServer/NFLogicServer/NFLogicServerPlugin/NFLogicServerPlugin.h"
//////////////////////////////LogicServer Plugin/////////////////////////////////
//////////////////////////////WebServer Plugin/////////////////////////////////
#include "NFServer/NFWebServer/NFWebServerPlugin/NFWebServerPlugin.h"
//////////////////////////////WebServer Plugin/////////////////////////////////
#endif



bool NFCPluginManager::RegisterStaticPlugin()
{
#ifndef NF_DYNAMIC_PLUGIN
	////////////////////////////////////////////////////////////////
#pragma comment( lib, "NFKernelPlugin.lib" )
#pragma comment( lib, "NFNetPlugin.lib" )
#pragma comment( lib, "NFShmPlugin.lib" )
#pragma comment( lib, "NFLuaScriptPlugin.lib" )
#pragma comment( lib, "NFServerCommon.lib" )
#pragma comment( lib, "NFServerCommonPlugin.lib" )
#pragma comment( lib, "NFDescStorePlugin.lib" )
#pragma comment( lib, "NFServerMessage.lib" )
	REGISTER_STATIC_PLUGIN(this, NFKernelPlugin);
	REGISTER_STATIC_PLUGIN(this, NFNetPlugin);
	REGISTER_STATIC_PLUGIN(this, NFShmPlugin);
	REGISTER_STATIC_PLUGIN(this, NFLuaScriptPlugin);
	REGISTER_STATIC_PLUGIN(this, NFServerCommonPlugin);
	REGISTER_STATIC_PLUGIN(this, NFDescStorePlugin);

//////////////////////////////CommLogic Plugin/////////////////////////////////
//////////////////////////////CommLogic Plugin/////////////////////////////////

//////////////////////////////MasterServer Plugin/////////////////////////////////
#pragma comment( lib, "NFMasterServerPlugin.lib" )
	REGISTER_STATIC_PLUGIN(this, NFMasterServerPlugin);
//////////////////////////////MasterServer Plugin/////////////////////////////////
		//////////////////////////////ProxyAgentServer Plugin/////////////////////////////////
#pragma comment( lib, "NFProxyAgentServerPlugin.lib" )
	REGISTER_STATIC_PLUGIN(this, NFProxyAgentServerPlugin);

	//////////////////////////////ProxyAgentServer Plugin/////////////////////////////////
	//////////////////////////////ProxyServer Plugin/////////////////////////////////
#pragma comment( lib, "NFProxyServerPlugin.lib" )
	REGISTER_STATIC_PLUGIN(this, NFProxyServerPlugin);
#pragma comment( lib, "NFProxyClientPlugin.lib" )
	REGISTER_STATIC_PLUGIN(this, NFProxyClientPlugin);
	
	//////////////////////////////ProxyServer Plugin/////////////////////////////////
//////////////////////////////GameServer Plugin/////////////////////////////////
#pragma comment( lib, "NFGameServerPlugin.lib" )
	REGISTER_STATIC_PLUGIN(this, NFGameServerPlugin);

//////////////////////////////GameServer Plugin/////////////////////////////////
//////////////////////////////LoginServer Plugin/////////////////////////////////
#pragma comment( lib, "NFLoginServerPlugin.lib" )
	REGISTER_STATIC_PLUGIN(this, NFLoginServerPlugin);
//////////////////////////////LoginServer Plugin/////////////////////////////////
//////////////////////////////WorldServer Plugin/////////////////////////////////
#pragma comment( lib, "NFWorldServerPlugin.lib" )
	REGISTER_STATIC_PLUGIN(this, NFWorldServerPlugin);
//////////////////////////////WorldServer Plugin/////////////////////////////////
//////////////////////////////RouteAgentServer Plugin/////////////////////////////////
#pragma comment( lib, "NFRouteAgentServerPlugin.lib" )
	REGISTER_STATIC_PLUGIN(this, NFRouteAgentServerPlugin);
//////////////////////////////RouteAgentServer Plugin/////////////////////////////////
//////////////////////////////RouteServer Plugin/////////////////////////////////
#pragma comment( lib, "NFRouteServerPlugin.lib" )
	REGISTER_STATIC_PLUGIN(this, NFRouteServerPlugin);
//////////////////////////////RouteServer Plugin/////////////////////////////////
//////////////////////////////StoreServer Plugin/////////////////////////////////
#pragma comment( lib, "NFStoreServerPlugin.lib" )
	REGISTER_STATIC_PLUGIN(this, NFStoreServerPlugin);
//////////////////////////////StoreServer Plugin/////////////////////////////////
//////////////////////////////SnsServer Plugin/////////////////////////////////
#pragma comment( lib, "NFSnsServerPlugin.lib" )
	REGISTER_STATIC_PLUGIN(this, NFSnsServerPlugin);
//////////////////////////////SnsServer Plugin/////////////////////////////////
//////////////////////////////LogicServer Plugin/////////////////////////////////
#pragma comment( lib, "NFLogicServerPlugin.lib" )
	REGISTER_STATIC_PLUGIN(this, NFLogicServerPlugin);
//////////////////////////////LogicServer Plugin/////////////////////////////////
	//////////////////////////////WebServer Plugin/////////////////////////////////
#pragma comment( lib, "NFWebServerPlugin.lib" )
	REGISTER_STATIC_PLUGIN(this, NFWebServerPlugin);
//////////////////////////////WebServer Plugin/////////////////////////////////
#endif
	return true;
}
