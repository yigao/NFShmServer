-- server type
NF_ST_NONE = 0;    		--NONE
NF_ST_MASTER_SERVER = 1;
NF_ST_ROUTE_AGENT_SERVER = 2; --路由代理服务器  负责同一台机子服务器数据之间的转发
NF_ST_ROUTE_SERVER = 3; --路由集群服务器 负责不同机子服务器数据之间的转发
NF_ST_PROXY_SERVER = 4;
NF_ST_PROXY_SERVER_FOR_CLIENT = 5; --网关服务器对客户端的端口
NF_ST_PROXY_AGENT_SERVER = 6; --Proxy 路由代理服务器 负责同一台机子客户端与服务器数据之间的转发
NF_ST_STORE_SERVER = 7; --DB服务器
NF_ST_LOGIN_SERVER = 8;
NF_ST_WORLD_SERVER = 9;
NF_ST_LOGIC_SERVER = 10; --Logic服务器
NF_ST_GAME_SERVER = 11;
NF_ST_SNS_SERVER = 12; --SNS服务器
NF_ST_WEB_SERVER = 13; --Web服务器
NF_ST_MONITOR_SERVER = 14; --Monitor服务器
NF_ST_MAX = 20;


NF_COMMON_BUS_LENGTH=20971520;--20M共享内存