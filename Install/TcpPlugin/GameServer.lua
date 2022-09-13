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
NF_ST_MAX = 20;    		--

--GameServer 游戏服务器, 一般一个小区只有一个， 负责游戏非战斗的业务， 连接世界服务器
--ServerId = "15.100.4.1" 15是世界服务ID， 范围1-15
-- 100是区服务ID， 范围1-65536
-- 4是服务器类型ID， 必须跟serverType一样 范围1-255
-- 1服务器索引，范围1-255
GameServer = {
   GameFish_2001_4_1 = {
      ServerName = "GameFish_2001_4_1",
      ServerType = NF_ST_GAME_SERVER,
      ServerId = "15.2001.4.1",			--对每一个服务器来说都是唯一的， 应用程序需要通过这个ServerId才能知道需要加载的配置是他
      BusLength = 20971520,     --20M共享内存
      IdleSleepUS = 1000,
      RouteAgent = "15.100.6.1",
      ServerIp = "127.0.0.1",
      --ServerIp = "120.79.47.22",
      ServerPort = 6041,
      MaxConnectNum = 100,
      NetThreadNum = 1,
      WorkThreadNum = 1,
      Security = false,
      WebSocket = false,
      MysqlIp = "127.0.0.1",
      MysqlPort = 6060,
      MysqlDbName = "proto_ff",
      MysqlUser = "root",
      MysqlPassword = "root",
      GameId=2001,
      GameDbName = "GameConfig_2001",
      RoomId = 1,
      MaxOnlinePlayerNum = 100,
      MasterIp = "127.0.0.1",
      MasterPort = 6011,
   };
};