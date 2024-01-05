require "Common"

--WebServer Web代理服务器， 负责Web
--ServerId = "15.100.11.1" 15是世界服务ID， 范围1-15
-- 100是区服务ID， 范围1-65536
-- 11是服务器类型ID， 必须跟serverType一样 范围1-255
-- 1服务器索引，范围1-255
WebServer = {
 WebServer_1 = {
    ServerName = "WebServer_1",
    ServerType = NF_ST_WEB_SERVER,
    ServerId = NF_ST_WORLD_ID.."."..NF_ST_ZONE_ID.."."..NF_ST_WEB_SERVER..".1",			--对每一个服务器来说都是唯一的， 应用程序需要通过这个ServerId才能知道需要加载的配置是他
    BusLength = NF_COMMON_BUS_LENGTH,     --20M共享内存
    LinkMode = NF_LINK_MODE,
    IdleSleepUS = 1000,
    MaxConnectNum = NF_INTER_MAX_CONNECT,
    NetThreadNum = 5,
    WorkThreadNum = 1,
    ServerIp = NF_INTER_SERVER_IP,
    ServerPort = NF_INTER_SERVER_PORT+NF_ST_WEB_SERVER*10+1,
    HttpPort = NF_EXTER_WEB_SERVER_PORT,
    MaxOnlinePlayerNum = NF_MAX_ONLINE_PLAYER_COUNT,
    HandleMsgNumPerFrame = NF_NORMAL_SERVER_HANDLE_MSG_COUNT,
    RouteConfig = {
       RouteAgent = NF_ROUTE_AGENT_ID,
       MasterIp = NF_MASTER_IP,
       MasterPort = NF_MASTER_PORT,
    },
    DefaultDBName = NF_MYSQL_DB_NAME,
 }
};
