require "Common"		--

--LogicServer 游戏服务器, 一般一个小区只有一个， 负责游戏非战斗的业务， 连接世界服务器
--ServerId = "15.100.4.1" 15是世界服务ID， 范围1-15
-- 100是区服务ID， 范围1-65536
-- 4是服务器类型ID， 必须跟serverType一样 范围1-255
-- 1服务器索引，范围1-255
LogicServer = {
   LogicServer_1 = {
      ServerName = "LogicServer_1",
      ServerType = NF_ST_LOGIC_SERVER,
      ServerId = NF_ST_WORLD_ID.."."..NF_ST_ZONE_ID.."."..NF_ST_LOGIC_SERVER..".1",			--对每一个服务器来说都是唯一的， 应用程序需要通过这个ServerId才能知道需要加载的配置是他
      BusLength = NF_COMMON_BUS_LENGTH,     --20M共享内存
      IdleSleepUS = 1000,
      RouteAgent = NF_ROUTE_AGENT_ID,
      ServerIp = NF_INTER_SERVER_IP,
      ServerPort = NF_INTER_SERVER_PORT+NF_ST_LOGIC_SERVER*10+1,
      MaxConnectNum = NF_INTER_MAX_CONNECT,
      NetThreadNum = 1,
      WorkThreadNum = 1,
      Security = false,
      WebSocket = false,
      MaxOnlinePlayerNum = NF_MAX_ONLINE_PLAYER_COUNT,
      MasterIp = NF_MASTER_IP,
      MasterPort = NF_MASTER_PORT,
   };
};