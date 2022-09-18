require "Common"

--ProxyServer 网管服务器， 负责与外部的客户端连接, 转发数据
--ServerId = "15.100.5.1" 15是世界服务ID， 范围1-15
-- 100是区服务ID， 范围1-65536
-- 5是服务器类型ID， 必须跟serverType一样 范围1-255
-- 1服务器索引，范围1-255
ProxyServer = {
    ProxyServer_4_1 = {
        ServerName = "ProxyServer_4_1",
        ServerType = NF_ST_PROXY_SERVER,
        ServerId = "15.100.4.1",			--对每一个服务器来说都是唯一的， 应用程序需要通过这个ServerId才能知道需要加载的配置是他
        IdleSleepUS = 1000,
        BusLength = NF_COMMON_BUS_LENGTH,     --20M共享内存
        MaxConnectNum = 1000000,
        NetThreadNum = 5,
        WorkThreadNum = 1,
        ParseType = 1, --0是内网协议，1是外网协议
        ServerIp = "127.0.0.1",
        ServerPort = 6041,
	    ExternalServerIp = "192.168.50.180",
	    ExternalServerPort = 10092,
        MaxOnlinePlayerNum = 100,
        --NamingHost = "127.0.0.1:2181,127.0.0.1:2182",
        --NamingPath = "99Puke",
        MasterIp = "127.0.0.1",
        MasterPort = 6011,
        Security = true,
	};

    ProxyServer_4_2 = {
        ServerName = "ProxyServer_4_2",
        ServerType = NF_ST_PROXY_SERVER,
        ServerId = "15.100.4.2",			--对每一个服务器来说都是唯一的， 应用程序需要通过这个ServerId才能知道需要加载的配置是他
        IdleSleepUS = 1000,
        BusLength = NF_COMMON_BUS_LENGTH,     --20M共享内存
        MaxConnectNum = 1000000,
        NetThreadNum = 5,
        WorkThreadNum = 1,
        ParseType = 1, --0是内网协议，1是外网协议
        ServerIp = "127.0.0.1",
        ServerPort = 6042,
        ExternalServerIp = "192.168.50.180",
        ExternalServerPort = 10093,
        MaxOnlinePlayerNum = 100,
        --NamingHost = "127.0.0.1:2181,127.0.0.1:2182",
        --NamingPath = "99Puke",
        MasterIp = "127.0.0.1",
        MasterPort = 6011,
        Security = true,
    };
};
