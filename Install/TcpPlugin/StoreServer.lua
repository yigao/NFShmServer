require "Common"		--

--StoreServer DB代理服务器， 负责从数据库取数据
--ServerId = "15.100.8.1" 15是世界服务ID， 范围1-15
-- 100是区服务ID， 范围1-65536
-- 8是服务器类型ID， 必须跟serverType一样 范围1-255
-- 1服务器索引，范围1-255
StoreServer = {
   StoreServer_7_1 = {
        ServerName = "StoreServer_7_1",
        ServerType = NF_ST_STORE_SERVER,
        ServerId = NF_ST_WORLD_ID.."."..NF_ST_ZONE_ID.."."..NF_ST_STORE_SERVER..".1",			--对每一个服务器来说都是唯一的， 应用程序需要通过这个ServerId才能知道需要加载的配置是他
        LinkMode = NF_LINK_MODE,
        BusLength = NF_COMMON_BUS_LENGTH,     --20M共享内存
        IdleSleepUS = 1000,
        MaxConnectNum = NF_INTER_MAX_CONNECT,
        NetThreadNum = 1,
        WorkThreadNum = 8,
        MaxOnlinePlayerNum = NF_MAX_ONLINE_PLAYER_COUNT,
        ServerIp = NF_INTER_SERVER_IP,
        ServerPort = NF_INTER_SERVER_PORT+NF_ST_STORE_SERVER*10+1,
        HandleMsgNumPerFrame = NF_TRANS_SERVER_HANDLE_MSG_COUNT,
        LoadProtoDs = "Sql/CommonLogic.proto.ds",
        MysqlConfig = {
             MysqlIp = NF_MYSQL_IP,
             MysqlPort = NF_MYSQL_PORT,
             MysqlDbName = NF_MYSQL_DB_NAME,
             MysqlUser = NF_MYSQL_USER,
             MysqlPassword = NF_MYSQL_PASSWORD,
             TBConfList = {
                  {TableName="RoleDBData", TableCount=1},
                  {TableName="RoleDBSnsDetail", TableCount=1},
                  {TableName="dbServerMgr", TableCount=1},
                  {TableName="tbServerMgr", TableCount=1},
             },
        },
        RouteConfig = {
             RouteAgent = NF_ROUTE_AGENT_ID,
             --NamingHost = NF_NAMING_HOST,
             --NamingPath = NF_NAMING_PATH,
             MasterIp = NF_MASTER_IP,
             MasterPort = NF_MASTER_PORT,
        },
   };
   StoreServer_7_2 = {
        ServerName = "StoreServer_7_2",
        ServerType = NF_ST_STORE_SERVER,
        ServerId = NF_ST_WORLD_ID.."."..NF_ST_ZONE_ID.."."..NF_ST_STORE_SERVER..".2",			--对每一个服务器来说都是唯一的， 应用程序需要通过这个ServerId才能知道需要加载的配置是他
        LinkMode = NF_LINK_MODE,
        BusLength = NF_COMMON_BUS_LENGTH,     --20M共享内存
        IdleSleepUS = 1000,
        MaxConnectNum = NF_INTER_MAX_CONNECT,
        NetThreadNum = 1,
        WorkThreadNum = 8,
        MaxOnlinePlayerNum = NF_MAX_ONLINE_PLAYER_COUNT,
        ServerIp = NF_INTER_SERVER_IP,
        ServerPort = NF_INTER_SERVER_PORT+NF_ST_STORE_SERVER*10+2,
        HandleMsgNumPerFrame = NF_TRANS_SERVER_HANDLE_MSG_COUNT,
        LoadProtoDs = "Sql/CommonLogic.proto.ds",
        MysqlConfig = {
             MysqlIp = NF_MYSQL_IP,
             MysqlPort = NF_MYSQL_PORT,
             MysqlDbName = NF_MYSQL_DB_NAME,
             MysqlUser = NF_MYSQL_USER,
             MysqlPassword = NF_MYSQL_PASSWORD,
        },
        RouteConfig = {
             RouteAgent = NF_ROUTE_AGENT_ID2,
             --NamingHost = NF_NAMING_HOST,
             --NamingPath = NF_NAMING_PATH,
             MasterIp = NF_MASTER_IP,
             MasterPort = NF_MASTER_PORT,
        },
   };
};