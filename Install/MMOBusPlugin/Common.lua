-- server type
NF_ST_NONE = 0;    		--NONE
NF_ST_MASTER_SERVER = 1;
NF_ST_ROUTE_SERVER = 2; --路由集群服务器 负责不同机子服务器数据之间的转发
NF_ST_ROUTE_AGENT_SERVER = 3; --路由代理服务器  负责同一台机子服务器数据之间的转发
NF_ST_PROXY_SERVER = 4;
NF_ST_PROXY_AGENT_SERVER = 5; --Proxy 路由代理服务器 负责同一台机子客户端与服务器数据之间的转发
NF_ST_STORE_SERVER = 6; --DB服务器
NF_ST_LOGIN_SERVER = 7;
NF_ST_WORLD_SERVER = 8;
NF_ST_LOGIC_SERVER = 9; --Logic服务器
NF_ST_GAME_SERVER = 10;
NF_ST_SNS_SERVER = 11; --SNS服务器
NF_ST_WEB_SERVER = 12; --Web服务器
NF_ST_MONITOR_SERVER = 13; ---Monitor服务器
NF_ST_CENTER_SERVER=14;
NF_ST_MAX = 50;

--大世界
NF_ST_WORLD_ID=1
--区分ID
NF_ST_ZONE_ID=13
--心跳包超时 正式服 30秒
NF_CLIENT_HEART_BEAT_TIME_OUT = 300
--外部客户端活跃超时 正式服 120秒
NF_CLIENT_KEEP_ALIVE_TIME_OUT = 1200

--内网服务器IP
NF_INTER_SERVER_IP="127.0.0.1"
--内网服务器端口
NF_INTER_SERVER_PORT=5000+NF_ST_ZONE_ID*300;
--内网服务器最大连接
NF_INTER_MAX_CONNECT=100

--外网服务器IP
--外网服务器端口
NF_EXTER_SERVER_IP="192.168.225.128" --"192.168.70.12"
NF_EXTER_PROXY_SERVER_PORT=6001;

--对外最大连接数
NF_EXTERN_MAX_CONNECT=5000
--外网服务器HTTP端口
NF_EXTER_WEB_SERVER_PORT=10000+NF_ST_ZONE_ID*10+4;

--BUS共享内存大小 20M共享内存
NF_COMMON_BUS_LENGTH=20971520

--当前服务器最大玩家数
NF_MAX_ONLINE_PLAYER_COUNT=100 --

NF_MASTER_IP=NF_EXTER_SERVER_IP
NF_MASTER_PORT=NF_INTER_SERVER_PORT+NF_ST_MASTER_SERVER*10+1
NF_ROUTE_AGENT_ID=NF_ST_WORLD_ID.."."..NF_ST_ZONE_ID.."."..NF_ST_ROUTE_AGENT_SERVER..".1"
NF_ROUTE_AGENT_ID2=NF_ST_WORLD_ID.."."..NF_ST_ZONE_ID.."."..NF_ST_ROUTE_AGENT_SERVER..".2"

--通信模式
NF_LINK_MODE="bus"
--NF_LINK_MODE="tcp"
NF_NORMAL_SERVER_HANDLE_MSG_COUNT=2000
NF_TRANS_SERVER_HANDLE_MSG_COUNT=10000
--

--数据库IP
NF_MYSQL_IP= "47.97.189.234"--"192.168.70.10" --"47.97.189.234"
--数据库端口
NF_MYSQL_PORT= 6060 --3306 --6060
--数据库名字
NF_MYSQL_DB_NAME="proto_ff_cgzone"..NF_ST_ZONE_ID
--数据库用户名
NF_MYSQL_USER="root"
--数据库密码
NF_MYSQL_PASSWORD= "root" --"cg2016" --"root"

NF_REDIS_IP="127.0.0.1"
NF_REDIS_PORT=6379
NF_REDIS_PASS="root"

----开服时间,单位秒
GlobalOpenTime = 1678204800

---客户端版本号
NF_CLIENT_VERSION = 0



