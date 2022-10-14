require "Common"		--

--RouteAgentServer 路由代理服务器， 负责同一台机子服务器数据之间的转发 一台物理集只有一个
--ServerId = "15.100.6.1" 15是世界服务ID， 范围1-15
-- 100是区服务ID， 范围1-65536
-- 6是服务器类型ID， 必须跟serverType一样 范围1-255
-- 1服务器索引，范围1-255
RouteAgentServer = {
  RouteAgentServer_1 = {
    ServerName = "RouteAgentServer_1",
    ServerType = NF_ST_ROUTE_AGENT_SERVER,
    ServerId = NF_ROUTE_AGENT_ID,			--对每一个服务器来说都是唯一的， 应用程序需要通过这个ServerId才能知道需要加载的配置是他
    LinkMode = "bus",
    BusLength = 20971520,     --20M共享内存
    IdleSleepUS = 1000,
    ServerIp = NF_INTER_SERVER_IP,
    ServerPort = NF_INTER_SERVER_PORT+NF_ST_ROUTE_AGENT_SERVER*10+1,
    MaxConnectNum = NF_INTER_MAX_CONNECT,
    NetThreadNum = 5,
    WorkThreadNum = 1,
    MaxOnlinePlayerNum = NF_MAX_ONLINE_PLAYER_COUNT,
    --NamingHost = NF_NAMING_HOST,
    --NamingPath = NF_NAMING_PATH,
    MasterIp = NF_MASTER_IP,
    MasterPort = NF_MASTER_PORT,
   };

  RouteAgentServer_2 = {
    ServerName = "RouteAgentServer_2",
    ServerType = NF_ST_ROUTE_AGENT_SERVER,
    ServerId = NF_ROUTE_AGENT_ID2,			--对每一个服务器来说都是唯一的， 应用程序需要通过这个ServerId才能知道需要加载的配置是他
    --LinkMode = "bus",
    BusLength = 20971520,     --20M共享内存
    IdleSleepUS = 1000,
    ServerIp = NF_INTER_SERVER_IP,
    ServerPort = NF_INTER_SERVER_PORT+NF_ST_ROUTE_AGENT_SERVER*10+2,
    MaxConnectNum = NF_INTER_MAX_CONNECT,
    NetThreadNum = 5,
    WorkThreadNum = 1,
    MaxOnlinePlayerNum = NF_MAX_ONLINE_PLAYER_COUNT,
    --NamingHost = NF_NAMING_HOST,
    --NamingPath = NF_NAMING_PATH,
    MasterIp = NF_MASTER_IP,
    MasterPort = NF_MASTER_PORT,
  };
};