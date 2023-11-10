require "Common"

--ProxyServer 网管服务器， 负责与外部的客户端连接, 转发数据
--ServerId = "15.100.5.1" 15是世界服务ID， 范围1-15
-- 100是区服务ID， 范围1-65536
-- 5是服务器类型ID， 必须跟serverType一样 范围1-255
-- 1服务器索引，范围1-255
ProxyServer = {
    ProxyServer_1 = {
        ServerName = "ProxyServer_1",
        ServerType = NF_ST_PROXY_SERVER,
        ServerId = NF_ST_WORLD_ID.."."..NF_ST_ZONE_ID.."."..NF_ST_PROXY_SERVER..".1",			--对每一个服务器来说都是唯一的， 应用程序需要通过这个ServerId才能知道需要加载的配置是他
        IdleSleepUS = 1000,
        BusLength = NF_COMMON_BUS_LENGTH,     --20M共享内存
        MaxConnectNum = NF_EXTERN_MAX_CONNECT,
        NetThreadNum = 5,
        WorkThreadNum = 1,
        ParseType = 1, --0是内网协议，1是MMO外网协议
        ServerIp = NF_EXTER_SERVER_IP,
        ServerPort = 8013, --NF_INTER_SERVER_PORT+NF_ST_PROXY_SERVER*10+1,
	    ExternalServerIp = NF_EXTER_SERVER_IP,
	    ExternalServerPort = NF_EXTER_PROXY_SERVER_PORT,
        MaxOnlinePlayerNum = NF_MAX_ONLINE_PLAYER_COUNT,
        HeartBeatTimeout = NF_CLIENT_HEART_BEAT_TIME_OUT,
        ClientKeepAliveTimeout = NF_CLIENT_KEEP_ALIVE_TIME_OUT,
        HandleMsgNumPerFrame = NF_TRANS_SERVER_HANDLE_MSG_COUNT,
        RouteConfig = {
            MasterIp = NF_MASTER_IP,
            MasterPort = NF_MASTER_PORT,
        },
        Security = true,
	};

    ProxyServer_4_2 = {
        ServerName = "ProxyServer_4_2",
        ServerType = NF_ST_PROXY_SERVER,
        ServerId = NF_ST_WORLD_ID.."."..NF_ST_ZONE_ID.."."..NF_ST_PROXY_SERVER..".2",			--对每一个服务器来说都是唯一的， 应用程序需要通过这个ServerId才能知道需要加载的配置是他
        IdleSleepUS = 1000,
        BusLength = NF_COMMON_BUS_LENGTH,     --20M共享内存
        MaxConnectNum = NF_EXTERN_MAX_CONNECT,
        NetThreadNum = 5,
        WorkThreadNum = 1,
        ParseType = 1, --0是内网协议，1是外网协议
        ServerIp = NF_EXTER_SERVER_IP,
        ServerPort = NF_INTER_SERVER_PORT+NF_ST_PROXY_SERVER*10+2,
        ExternalServerIp = NF_EXTER_SERVER_IP,
        ExternalServerPort = NF_EXTER_PROXY_SERVER_PORT+1,
        MaxOnlinePlayerNum = NF_MAX_ONLINE_PLAYER_COUNT,
        HeartBeatTimeout = NF_CLIENT_HEART_BEAT_TIME_OUT,
        ClientKeepAliveTimeout = NF_CLIENT_KEEP_ALIVE_TIME_OUT,
        RouteConfig = {
            MasterIp = NF_MASTER_IP,
            MasterPort = NF_MASTER_PORT,
        },
        Security = false,
    };
};
