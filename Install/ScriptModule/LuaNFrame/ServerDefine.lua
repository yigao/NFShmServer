NF_SERVER_TYPES = {
	-- server type
	NF_ST_NONE = 0,    		--NONE
	NF_ST_MASTER_SERVER = 1,
	NF_ST_ROUTE_SERVER = 2, --路由集群服务器 负责不同机子服务器数据之间的转发
	NF_ST_ROUTE_AGENT_SERVER = 3, --路由代理服务器  负责同一台机子服务器数据之间的转发
	NF_ST_PROXY_SERVER = 4,
	NF_ST_PROXY_AGENT_SERVER = 5, --Proxy 路由代理服务器 负责同一台机子客户端与服务器数据之间的转发
	NF_ST_STORE_SERVER = 6, --DB服务器
	NF_ST_LOGIN_SERVER = 7,
	NF_ST_WORLD_SERVER = 8,
	NF_ST_LOGIC_SERVER = 9, --Logic服务器
	NF_ST_GAME_SERVER = 10,
	NF_ST_SNS_SERVER = 11, --SNS服务器
	NF_ST_WEB_SERVER = 12, --Web服务器
	NF_ST_MONITOR_SERVER = 19, ---Monitor服务器
	NF_ST_MAX = 50,
};

NF_MSG_TYPE = {
	eMsgType_Num = 0,
	eMsgType_CONNECTED = 1,
	eMsgType_DISCONNECTED = 2,
	eMsgType_RECIVEDATA = 3,
};

NF_ACCOUNT_EVENT_TYPE = {
	eAccountEventType_Num = 0,
	eAccountEventType_CONNECTED = 1,
	eAccountEventType_DISCONNECTED = 2,
	eAccountEventType_RECONNECTED = 3,
}