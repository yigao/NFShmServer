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
			"NFFishRobotPlugin",
			"NFNetPlugin",
		};
		ServerType = NF_ST_NONE;
	},

	AllServer = {
		FramePlugins = {
			-------------------------
			-----基础框架引擎-------------
			"NFKernelPlugin",
			"NFNetPlugin",
			"NFShmPlugin",

			"NFServerCommonPlugin",
			"NFDescStorePlugin",
			"NFDBPlugin",
		};


		ServerPlugins = {
			"NFMasterServerPlugin",
			"NFRouteServerPlugin",
			"NFRouteAgentServerPlugin",
			"NFStoreServerPlugin",
			"NFProxyServerPlugin",
			"NFProxyClientPlugin",
			"NFProxyAgentServerPlugin",
			"NFLoginServerPlugin",
			"NFGameServerPlugin",
			"NFWorldServerPlugin",
			"NFSnsServerPlugin",
			"NFLogicServerPlugin",
			"NFWebServerPlugin",
			"NFCenterServerPlugin",
		};

		WorkPlugins = {
			"NFMMOCommonPlugin",
			"NFMMOProxyPlayerPlugin",
			"NFMMOWorldPlayerPlugin",
			"NFMMOLogicPlayerPlugin",
			"NFMMOSnsPlayerPlugin",
			"NFMMOCenterPlayerPlugin",
			"NFMMOGamePlayerPlugin",
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
			{Server="CenterServer", ID=NF_ST_WORLD_ID.."."..NF_ST_ZONE_ID.."."..NF_ST_CENTER_SERVER..".1", ServerType=NF_ST_CENTER_SERVER},
			--{Server="MonitorServer", ID=NF_ST_WORLD_ID.."."..NF_ST_ZONE_ID.."."..NF_ST_MONITOR_SERVER..".1", ServerType=NF_ST_MONITOR_SERVER},
		};
	},
	MasterServer = {
		FramePlugins = {
			-------------------------
			-----基础框架引擎-------------
			"NFKernelPlugin",
			"NFNetPlugin",
			"NFServerCommonPlugin",
		};


		ServerPlugins = {
			"NFMasterServerPlugin",
		};

		WorkPlugins = {
		};
		ServerType = NF_ST_MASTER_SERVER;
	},

	ProxyServer = {
		FramePlugins = {
			-------------------------
			-----基础框架引擎-------------
			"NFKernelPlugin",
			"NFNetPlugin",

			"NFServerCommonPlugin",
		};


		ServerPlugins = {
			"NFProxyServerPlugin",
			"NFProxyClientPlugin",
		};

		WorkPlugins = {
			"NFMMOProxyPlayerPlugin",
		};
		ServerType = NF_ST_PROXY_SERVER;
	},

	ProxyAgentServer = {
		FramePlugins = {
			-------------------------
			-----基础框架引擎-------------
			"NFKernelPlugin",
			"NFNetPlugin",

			"NFServerCommonPlugin",
		};


		ServerPlugins = {
			"NFProxyAgentServerPlugin",
		};

		WorkPlugins = {
		};
		ServerType = NF_ST_PROXY_AGENT_SERVER;
	},

	GameServer = {
		FramePlugins = {
			-------------------------
			-----基础框架引擎-------------
			"NFKernelPlugin",
			"NFNetPlugin",
			"NFShmPlugin",

			"NFServerCommonPlugin",
			"NFDescStorePlugin",
		};

		ServerPlugins = {
			"NFGameServerPlugin",
		};

		WorkPlugins = {
			"NFMMOCommonPlugin",
			"NFMMOGamePlayerPlugin",
		};
		ServerType = NF_ST_GAME_SERVER;
	},

	LoginServer = {
		FramePlugins = {
			-------------------------
			-----基础框架引擎-------------
			"NFKernelPlugin",
			"NFNetPlugin",
			"NFShmPlugin",

			"NFServerCommonPlugin",
			"NFDescStorePlugin",
		};


		ServerPlugins = {
			"NFLoginServerPlugin",
		};

		WorkPlugins = {
		};
		ServerType = NF_ST_LOGIN_SERVER;
	},

	WorldServer = {
		FramePlugins = {
			-------------------------
			-----基础框架引擎-------------
			"NFKernelPlugin",
			"NFNetPlugin",
			"NFShmPlugin",

			"NFServerCommonPlugin",
			"NFDescStorePlugin",
		};


		ServerPlugins = {
			"NFWorldServerPlugin",
		};

		WorkPlugins = {
			"NFMMOCommonPlugin",
			"NFMMOWorldPlayerPlugin",
		};
		ServerType = NF_ST_WORLD_SERVER;
	},

	StoreServer = {
		FramePlugins = {
			-------------------------
			-----基础框架引擎-------------
			"NFKernelPlugin",
			"NFNetPlugin",
			"NFDBPlugin",
			"NFServerCommonPlugin",
		};


		ServerPlugins = {
			"NFStoreServerPlugin",
		};

		WorkPlugins = {
		};
		ServerType = NF_ST_STORE_SERVER;
	},

	LogicServer = {
		FramePlugins = {
			-------------------------
			-----基础框架引擎-------------
			"NFKernelPlugin",
			"NFNetPlugin",
			"NFShmPlugin",

			"NFServerCommonPlugin",
			"NFDescStorePlugin",
		};


		ServerPlugins = {
			"NFLogicServerPlugin",
		};

		WorkPlugins = {
			"NFMMOCommonPlugin",
			"NFMMOLogicPlayerPlugin",
		};
		ServerType = NF_ST_LOGIC_SERVER;
	},

	SnsServer = {
		FramePlugins = {
			-------------------------
			-----基础框架引擎-------------
			"NFKernelPlugin",
			"NFNetPlugin",
			"NFShmPlugin",

			"NFServerCommonPlugin",
			"NFDescStorePlugin",
		};


		ServerPlugins = {
			"NFSnsServerPlugin",
		};

		WorkPlugins = {
			"NFMMOCommonPlugin",
			"NFMMOSnsPlayerPlugin",
		};
		ServerType = NF_ST_SNS_SERVER;
	},

	WebServer = {
		FramePlugins = {
			-------------------------
			-----基础框架引擎-------------
			"NFKernelPlugin",
			"NFNetPlugin",
			"NFServerCommonPlugin",
		};


		ServerPlugins = {
			"NFWebServerPlugin",
		};

		WorkPlugins = {
		};
		ServerType = NF_ST_WEB_SERVER;
	},

	RouteAgentServer = {
		FramePlugins = {
			-------------------------
			-----基础框架引擎-------------
			"NFKernelPlugin",
			"NFNetPlugin",
			"NFServerCommonPlugin",
		};


		ServerPlugins = {
			"NFRouteAgentServerPlugin",
		};

		WorkPlugins = {
		};
		ServerType = NF_ST_ROUTE_AGENT_SERVER;
	},

	RouteServer = {
		FramePlugins = {
			-------------------------
			-----基础框架引擎-------------
			"NFKernelPlugin",
			"NFNetPlugin",
			"NFServerCommonPlugin",
		};


		ServerPlugins = {
			"NFRouteServerPlugin",
		};

		WorkPlugins = {
		};
		ServerType = NF_ST_ROUTE_SERVER;
	},

	MonitorServer = {
		FramePlugins = {
			-------------------------
			-----基础框架引擎-------------
			"NFKernelPlugin",
			"NFNetPlugin",
			"NFServerCommonPlugin",
		};


		ServerPlugins = {
			"NFMonitorServerPlugin",
		};

		WorkPlugins = {
		};
		ServerType = NF_ST_MONITOR_SERVER;
	},

	CenterServer = {
		FramePlugins = {
			-------------------------
			-----基础框架引擎-------------
			"NFKernelPlugin",
			"NFNetPlugin",
			"NFShmPlugin",

			"NFServerCommonPlugin",
			"NFDescStorePlugin",
		};


		ServerPlugins = {
			"NFCenterServerPlugin",
		};

		WorkPlugins = {
		    "NFMMOCenterPlayerPlugin",
		};
		ServerType = NF_ST_SNS_SERVER;
	},
}
