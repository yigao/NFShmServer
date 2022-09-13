-- server type
NF_ST_NONE = 0;    		-- NONE
NF_ST_MASTER_SERVER = 1;    	--
NF_ST_LOGIN_SERVER = 2;    	--
NF_ST_WORLD_SERVER = 3;    	--
NF_ST_GAME_SERVER = 4;    		--
NF_ST_PROXY_SERVER = 5;    	--
NF_ST_ROUTE_AGENT_SERVER = 6; --路由代理服务器  负责同一台机子服务器数据之间的转发
NF_ST_ROUTE_SERVER = 7; --路由集群服务器 负责不同机子服务器数据之间的转发
NF_ST_STORE_SERVER = 8; --DB服务器
NF_ST_SNS_SERVER = 9; --SNS服务器
NF_ST_LOGIC_SERVER = 10; --Logic服务器
NF_ST_WEB_SERVER = 11; --Web服务器
NF_ST_MONITOR_SERVER = 12; --Monitor服务器
NF_ST_PROXY_AGENT_SERVER = 13; --
NF_ST_MAX = 20;    		--

LoadPlugin =
{
	TestServer = {
		ServerPlugins = {
			-------------------------
			-----基础框架引擎-------------
			"NFKernelPlugin",
			"NFTestPlugin",
			--"NFRobotPlugin",
			"NFNetPlugin",
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
			"NFShmPlugin",
			"NFCommLogicPlugin",

			"NFMasterServerPlugin",
			"NFRouteServerPlugin",
			"NFRouteAgentServerPlugin",

			"NFStoreServerPlugin",

			"NFProxyServerPlugin",
			"NFProxyClientPlugin",
			"NFProxyAgentServerPlugin",

			"NFLoginServerPlugin",
			"NFLoginServerPlayerPlugin",

			"NFGameServerPlugin",

			"NFWorldServerPlugin",
			"NFWorldServerPlayerPlugin",

			"NFSnsServerPlugin",
			"NFSnsServerPlayerPlugin",

			"NFLogicServerPlugin",
			"NFLogicServerPlayerPlugin",

			"NFWebServerPlugin",
			"NFWebServerLogicPlugin",

			--"NFMonitorServerPlugin",
		};
		ServerType = NF_ST_NONE;
	},
	MasterServer = {
		ServerPlugins = {
			-------------------------
			-----基础框架引擎-------------
			"NFKernelPlugin",
			--"NFTestPlugin",
			"NFNetPlugin",
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

			"NFProxyServerPlugin",
			"NFProxyClientPlugin",
		};
		ServerType = NF_ST_PROXY_SERVER;
	},

	ProxyAgentServer = {
		ServerPlugins = {
			-------------------------
			-----基础框架引擎-------------
			"NFKernelPlugin",
			"NFNetPlugin",

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

			"NFGameServerPlugin",
			"NFGameFishPlugin",
			"NFFishAlgoPlugin",
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
			--"NFTestPlugin",
			"NFNetPlugin",

			"NFRouteAgentServerPlugin",
		};
		ServerType = NF_ST_ROUTE_AGENT_SERVER;
	},

	RouteServer = {
		ServerPlugins = {
			-------------------------
			-----基础框架引擎-------------
			"NFKernelPlugin",
			--"NFTestPlugin",
			"NFNetPlugin",

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
			"NFMonitorServerPlugin",
		};
		ServerType = NF_ST_MONITOR_SERVER;
	},
}
