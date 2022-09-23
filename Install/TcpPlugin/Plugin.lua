require "Common"

LoadPlugin =
{
	TestServer = {
		ServerPlugins = {
			-------------------------
			-----基础框架引擎-------------
			"NFKernelPlugin",
			"NFTestPlugin",
		};
		ServerType = NF_ST_NONE;
	},

	RobotServer = {
		ServerPlugins = {
			-------------------------
			-----基础框架引擎-------------
			"NFKernelPlugin",
			"NFRobotPlugin",
			"NFNetPlugin",
		};
		ServerType = NF_ST_NONE;
	},

	AllServer = {
		ServerPlugins = {
			-------------------------
			-----基础框架引擎-------------
			"NFKernelPlugin",
			--"NFTestPlugin",
			--"NFRobotPlugin",
			"NFNetPlugin",
			--"NFShmPlugin",

			--"NFServerCommonPlugin",
			--"NFCommLogicPlugin",

			--"NFMasterServerPlugin",
			--"NFRouteServerPlugin",
			--"NFRouteAgentServerPlugin",

			--"NFStoreServerPlugin",

			--"NFProxyServerPlugin",
			"NFProxyClientPlugin",
			--"NFProxyAgentServerPlugin",

			--"NFLoginServerPlugin",
			--"NFLoginServerPlayerPlugin",

			--"NFGameServerPlugin",

			--"NFWorldServerPlugin",
			--"NFWorldServerPlayerPlugin",

			--"NFSnsServerPlugin",
			--"NFSnsServerPlayerPlugin",

			--"NFLogicServerPlugin",
			--"NFLogicServerPlayerPlugin",

			--"NFWebServerPlugin",
			--"NFWebServerLogicPlugin",

			--"NFMonitorServerPlugin",
		};
		ServerType = NF_ST_NONE;
		ServerList = {
			{Server="MasterServer", ID=NF_ST_WORLD_ID.."."..NF_ST_ZONE_ID.."."..NF_ST_MASTER_SERVER..".1", ServerType=NF_ST_MASTER_SERVER},
			{Server="ProxyServer", ID=NF_ST_WORLD_ID.."."..NF_ST_ZONE_ID.."."..NF_ST_PROXY_SERVER..".1", ServerType=NF_ST_PROXY_SERVER},
			{Server="ProxyAgentServer", ID=NF_ST_WORLD_ID.."."..NF_ST_ZONE_ID.."."..NF_ST_PROXY_AGENT_SERVER..".1", ServerType=NF_ST_PROXY_AGENT_SERVER},
			{Server="RouteAgentServer", ID=NF_ST_WORLD_ID.."."..NF_ST_ZONE_ID.."."..NF_ST_ROUTE_AGENT_SERVER..".1", ServerType=NF_ST_ROUTE_AGENT_SERVER},
			{Server="RouteServer", ID=NF_ST_WORLD_ID.."."..NF_ST_ZONE_ID.."."..NF_ST_ROUTE_SERVER..".1", ServerType=NF_ST_ROUTE_SERVER},
			{Server="GameServer", ID=NF_ST_WORLD_ID.."."..NF_ST_ZONE_ID.."."..NF_ST_GAME_SERVER..".1", ServerType=NF_ST_GAME_SERVER},
			{Server="StoreServer", ID=NF_ST_WORLD_ID.."."..NF_ST_ZONE_ID.."."..NF_ST_STORE_SERVER..".1", ServerType=NF_ST_STORE_SERVER},
			{Server="WorldServer", ID=NF_ST_WORLD_ID.."."..NF_ST_ZONE_ID.."."..NF_ST_WORLD_SERVER..".1", ServerType=NF_ST_WORLD_SERVER},
			{Server="LoginServer", ID=NF_ST_WORLD_ID.."."..NF_ST_ZONE_ID.."."..NF_ST_LOGIN_SERVER..".1", ServerType=NF_ST_LOGIN_SERVER},
			{Server="LogicServer", ID=NF_ST_WORLD_ID.."."..NF_ST_ZONE_ID.."."..NF_ST_LOGIC_SERVER..".1", ServerType=NF_ST_LOGIC_SERVER},
			{Server="SnsServer", ID=NF_ST_WORLD_ID.."."..NF_ST_ZONE_ID.."."..NF_ST_SNS_SERVER..".1", ServerType=NF_ST_SNS_SERVER},
			{Server="WebServer", ID=NF_ST_WORLD_ID.."."..NF_ST_ZONE_ID.."."..NF_ST_WEB_SERVER..".1", ServerType=NF_ST_WEB_SERVER},
			--{Server="MonitorServer", ID=NF_ST_WORLD_ID.."."..NF_ST_ZONE_ID.."."..NF_ST_MONITOR_SERVER..".1", ServerType=NF_ST_MONITOR_SERVER},
		};
	},
	MasterServer = {
		ServerPlugins = {
			-------------------------
			-----基础框架引擎-------------
			"NFKernelPlugin",
			"NFNetPlugin",
			"NFServerCommonPlugin",
			"NFMasterServerPlugin",
		};
		ServerType = NF_ST_MASTER_SERVER;
	},

	ProxyServer = {
		ServerPlugins = {
			-------------------------
			-----基础框架引擎-------------
			"NFKernelPlugin",
			"NFNetPlugin",
			"NFShmPlugin",
			"NFServerCommonPlugin",

			"NFProxyServerPlugin",
			--"NFProxyClientPlugin",
		};
		ServerType = NF_ST_PROXY_SERVER;
	},

	ProxyAgentServer = {
		ServerPlugins = {
			-------------------------
			-----基础框架引擎-------------
			"NFKernelPlugin",
			"NFNetPlugin",
			"NFServerCommonPlugin",

			"NFProxyAgentServerPlugin",
		};
		ServerType = NF_ST_PROXY_AGENT_SERVER;
	},

	GameServer = {
		ServerPlugins = {
			-------------------------
			-----基础框架引擎-------------
			"NFKernelPlugin",
			"NFNetPlugin",
			"NFShmPlugin",
			"NFServerCommonPlugin",

			"NFGameServerPlugin",
		};
		ServerType = NF_ST_GAME_SERVER;
	},

	LoginServer = {
		ServerPlugins = {
			-------------------------
			-----基础框架引擎-------------
			"NFKernelPlugin",
			"NFNetPlugin",
			"NFShmPlugin",
			"NFServerCommonPlugin",

			"NFLoginServerPlugin",
			"NFLoginServerPlayerPlugin",
		};
		ServerType = NF_ST_LOGIN_SERVER;
	},

	WorldServer = {
		ServerPlugins = {
			-------------------------
			-----基础框架引擎-------------
			"NFKernelPlugin",
			"NFNetPlugin",
			"NFShmPlugin",
			"NFServerCommonPlugin",

			"NFWorldServerPlugin",
			"NFWorldServerPlayerPlugin",
		};
		ServerType = NF_ST_WORLD_SERVER;
	},

	StoreServer = {
		ServerPlugins = {
			-------------------------
			-----基础框架引擎-------------
			"NFKernelPlugin",
			"NFNetPlugin",
			"NFServerCommonPlugin",

			"NFStoreServerPlugin",
		};
		ServerType = NF_ST_STORE_SERVER;
	},

	LogicServer = {
		ServerPlugins = {
			-------------------------
			-----基础框架引擎-------------
			"NFKernelPlugin",
			"NFNetPlugin",
			"NFShmPlugin",
			"NFServerCommonPlugin",
			"NFCommLogicPlugin",

			"NFLogicServerPlugin",
			"NFLogicServerPlayerPlugin",
		};
		ServerType = NF_ST_LOGIC_SERVER;
	},

	SnsServer = {
		ServerPlugins = {
			-------------------------
			-----基础框架引擎-------------
			"NFKernelPlugin",
			"NFNetPlugin",
			"NFShmPlugin",
			"NFServerCommonPlugin",

			"NFSnsServerPlugin",
			"NFSnsServerPlayerPlugin",
		};
		ServerType = NF_ST_SNS_SERVER;
	},

	WebServer = {
		ServerPlugins = {
			-------------------------
			-----基础框架引擎-------------
			"NFKernelPlugin",
			"NFNetPlugin",
			"NFServerCommonPlugin",

			"NFWebServerPlugin",
			"NFWebServerLogicPlugin",
		};
		ServerType = NF_ST_WEB_SERVER;
	},

	RouteAgentServer = {
		ServerPlugins = {
			-------------------------
			-----基础框架引擎-------------
			"NFKernelPlugin",
			"NFNetPlugin",
			"NFServerCommonPlugin",

			"NFRouteAgentServerPlugin",
		};
		ServerType = NF_ST_ROUTE_AGENT_SERVER;
	},

	RouteServer = {
		ServerPlugins = {
			-------------------------
			-----基础框架引擎-------------
			"NFKernelPlugin",
			"NFNetPlugin",
			"NFServerCommonPlugin",

			"NFRouteServerPlugin",
		};
		ServerType = NF_ST_ROUTE_SERVER;
	},

	MonitorServer = {
		ServerPlugins = {
			-------------------------
			-----基础框架引擎-------------
			"NFKernelPlugin",
			"NFNetPlugin",
			"NFServerCommonPlugin",
			"NFMonitorServerPlugin",
		};
		ServerType = NF_ST_MONITOR_SERVER;
	},
}
