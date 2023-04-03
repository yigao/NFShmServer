require "Common"		--

--RouteServer 路由代理服务器， 负责不同机子服务器数据之间的转发, 一个世界服只有一个
--ServerId = "15.100.7.1" 15是世界服务ID， 范围1-15
-- 100是区服务ID， 范围1-65536
-- 7是服务器类型ID， 必须跟serverType一样 范围1-255
-- 1服务器索引，范围1-255
RouteServer = {
  RouteServer_1 = {
    ServerName = "RouteServer_1",
    ServerType = NF_ST_ROUTE_SERVER,
    ServerId = NF_ST_WORLD_ID.."."..NF_ST_ZONE_ID.."."..NF_ST_ROUTE_SERVER..".1",			--对每一个服务器来说都是唯一的， 应用程序需要通过这个ServerId才能知道需要加载的配置是他
    IdleSleepUS = 1000,
    ServerIp = NF_EXTER_SERVER_IP,
    ServerPort = NF_INTER_SERVER_PORT+NF_ST_ROUTE_SERVER*10+1,
    MaxConnectNum = NF_INTER_MAX_CONNECT,
    NetThreadNum = 5,
    WorkThreadNum = 1,
    MaxOnlinePlayerNum = NF_MAX_ONLINE_PLAYER_COUNT,
    HandleMsgNumPerFrame = NF_TRANS_SERVER_HANDLE_MSG_COUNT,
    RouteConfig = {
      --NamingHost = NF_NAMING_HOST,
      --NamingPath = NF_NAMING_PATH,
      MasterIp = NF_MASTER_IP,
      MasterPort = NF_MASTER_PORT,
    },
  };
};