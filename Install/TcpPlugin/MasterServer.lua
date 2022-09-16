require "Common"

--MasterServer 服务器，管理多个登录服务器， 一个或多个世界服务器 MasterServer部分区分，所有服务器共享
--ServerId = "1.1.1.1" 1是世界服务ID， 范围1-15
-- 100是区服务ID， 范围1-65536
-- 1是服务器类型ID， 必须跟serverType一样 范围1-255
-- 1服务器索引，范围1-255
MasterServer = {
    MasterServer_1 = {
        ServerName = "MasterServer_1",
        ServerType = NF_ST_MASTER_SERVER,
        ServerId = "1.1.1.1",		--对每一个服务器来说都是唯一的， 应用程序需要通过这个ServerId才能知道需要加载的配置是他
        BusLength = 20971520,     --20M共享内存
        IdleSleepUS = 1000,
        ServerIp = "127.0.0.1",
        ServerPort = 6011,
        MaxConnectNum = 100,
        NetThreadNum = 1,
        WorkThreadNum = 1,
        HttpPort = 6012,
        MaxOnlinePlayerNum = 100,
        --NamingHost = "127.0.0.1:2181,127.0.0.1:2182",
        --NamingPath = "99Puke",
        --WWW="http://192.168.0.62",
        WWW="http://192.168.0.11",
        Email="445267987@qq.com",
    };
};
