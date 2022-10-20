
NF_LOG_LEVEL_TRACE = 0 --    trace = 0,
NF_LOG_LEVEL_DEBUG = 1 --    debug = 1,
NF_LOG_LEVEL_INFO = 2  --    info = 2,
NF_LOG_LEVEL_WARN = 3  --    warn = 3,
NF_LOG_LEVEL_ERROR = 4 --    err = 4,


LogLevel = NF_LOG_LEVEL_TRACE;				--log等级配置		当前日志输出级别，大于此等于级别的才会输出到console
LogFlushLevel = NF_LOG_LEVEL_TRACE;			--log刷新等级配置, 当前日志输出级别，大于此等于级别的才会刷新到LOG文件里


NFLogId = {
	--0-100是基础框架层LOG
	NF_LOG_DEFAULT = 0,						--默认LOG
	NF_LOG_SYSTEMLOG = 1,					--系统LOG
	NF_LOG_RECV_MSG = 3,					--接受消息
	NF_LOG_RECV_MSG_JSON_PRINTF = 4,		--接受消息Json输出
	NF_LOG_LOAD_CONFIG = 5,				--加载配置
	NF_LOG_PROTOBUF_PARSE = 6,				--protobuf解析出错
	NF_LOG_PLUGIN_MANAGER = 7,			--引擎加载器
	---------------------------系统公共引擎----------------------------------
	NF_LOG_ACTOR_PLUGIN = 100,				--Actor 引擎
	NF_LOG_KERNEL_PLUGIN = 101,				--kernel 引擎
	NF_LOG_MYSQL_PLUGIN = 102,				--mysql 引擎
	NF_LOG_NET_PLUGIN = 103,					--net 引擎
	NF_LOG_TEST_PLUGIN = 104,				--test 引擎
	-----------------------------服务器架构引擎--------------------------------
	NF_LOG_COMM_LOGIC_PLUGIN = 200,				--NFCommLogicPlugin
	NF_LOG_GAME_SERVER_PLUGIN = 201,				--NFGameServerPlugin
	NF_LOG_MASTER_SERVER_PLUGIN = 202,			--NFMasterServerPlugin
	NF_LOG_PROXY_CLIENT_PLUGIN = 203,			--NFProxyClientPlugin
	NF_LOG_PROXY_SERVER_PLUGIN = 204,			--NFProxyServerPlugin
	NF_LOG_ROUTE_AGENT_SERVER_PLUGIN = 205,	--NFRouteAgentServerPlugin
	NF_LOG_ROUTE_SERVER_PLUGIN = 206,			--NFRouteServerPlugin
	NF_LOG_STORE_SERVER_PLUGIN = 207,			--NFStoreServerPlugin
	NF_LOG_WORLD_SERVER_PLUGIN = 208,			--NFWorldServerPlugin
	NF_LOG_LOGIN_SERVER_PLUGIN = 209,			--NFLoginServerPlugin
	NF_LOG_USER_MAIL_PLUGIN = 210,			    --NFUserMailPlugin
	NF_LOG_SNS_SERVER_PLUGIN = 211,			    	--NFSnsServerPlugin
	NF_LOG_LOGIC_SERVER_PLUGIN = 212,			    --NFLogicServerPlugin
	NF_LOG_WEB_SERVER_PLUGIN = 213,			    --NFWebServerPlugin
	NF_LOG_MONITOR_SERVER_PLUGIN = 214,			   --NFMonitorServerPlugin
	NF_LOG_MAX_SYSTEM_PLUGIN = 1000,
    ---------------------------game 引擎--------------------------------
    NF_LOG_GAME_FISH_PLUGIN = 1001,
	NF_LOG_MAX_ID = 10240, --最大LOGID
}

--	配置要打印的LOG
--	display 是否打印log
--	level 打印log最低等级
--  logname 打印时显示的名字
--  guid 只打印一个或几个玩家的LOG 打印几个玩家的LOG系统guid={guid1, guid2}
LogInfo = {
	--0-100是基础框架层LOG
	{logid = NFLogId.NF_LOG_DEFAULT, display=true, level=0, logname = "DefaultLog", guid = {0}, desc = "默认LOG"},
	{logid = NFLogId.NF_LOG_SYSTEMLOG, display=true, level=0, logname = "SystemLog", guid = 0, desc = "系统LOG"},
	{logid = NFLogId.NF_LOG_RECV_MSG, display=true, level=0, logname = "RecvMsg", guid = 0, desc = "接受消息LOG"},
	{logid = NFLogId.NF_LOG_RECV_MSG_JSON_PRINTF, display=true, level=0, logname = "RecvMsgJson", guid = 0, desc = "接受消息Json输出LOG"},
	{logid = NFLogId.NF_LOG_PLUGIN_MANAGER, display=true, level=0, logname = "PluginLog", guid = 0, desc = "引擎管理LOG"},
	{logid = NFLogId.NF_LOG_LOAD_CONFIG, display=true, level=0, logname = "LoadConfigLog", guid = 0, desc = "加载配置LOG"},
	{logid = NFLogId.NF_LOG_PROTOBUF_PARSE, display=true, level=0, logname = "ProtobufParse", guid = 0, desc = "protobuf解析出错LOG"},
---------------------------系统公共引擎----------------------------------
	{logid = NFLogId.NF_LOG_ACTOR_PLUGIN, display=true, level=0, logname = "NFActorPlugin", guid = 0, desc = "Actor引擎LOG"},
	{logid = NFLogId.NF_LOG_KERNEL_PLUGIN, display=true, level=0, logname = "NFKernelPlugin", guid = 0, desc = "Kernel引擎LOG"},
	{logid = NFLogId.NF_LOG_MYSQL_PLUGIN, display=true, level=0, logname = "NFMysqlPlugin", guid = 0, desc = "Mysql引擎LOG"},
	{logid = NFLogId.NF_LOG_NET_PLUGIN, display=true, level=0, logname = "NFNetPlugin", guid = 0, desc = "Net引擎LOG"},
	{logid = NFLogId.NF_LOG_TEST_PLUGIN, display=true, level=0, logname = "NFTestPlugin", guid = 0, desc = "test引擎LOG"},
	-----------------------------服务器架构引擎--------------------------------
	{logid = NFLogId.NF_LOG_COMM_LOGIC_PLUGIN, display=true, level=0, logname = "NFCommLogicPlugin", guid = 0, desc = "NFCommLogicPlugin"},
	{logid = NFLogId.NF_LOG_GAME_SERVER_PLUGIN, display=true, level=0, logname = "NFGameServerPlugin", guid = 0, desc = "NFGameServerPlugin"},
	{logid = NFLogId.NF_LOG_MASTER_SERVER_PLUGIN, display=true, level=0, logname = "NFMasterServerPlugin", guid = 0, desc = "NFMasterServerPlugin"},
	{logid = NFLogId.NF_LOG_PROXY_CLIENT_PLUGIN, display=true, level=0, logname = "NFProxyClientPlugin", guid = 0, desc = "NFProxyClientPlugin"},
	{logid = NFLogId.NF_LOG_PROXY_SERVER_PLUGIN, display=true, level=0, logname = "NFProxyServerPlugin", guid = 0, desc = "NFProxyServerPlugin"},
	{logid = NFLogId.NF_LOG_ROUTE_AGENT_SERVER_PLUGIN, display=true, level=0, logname = "NFRouteAgentServerPlugin", guid = 0, desc = "NFRouteAgentServerPlugin"},
	{logid = NFLogId.NF_LOG_ROUTE_SERVER_PLUGIN, display=true, level=0, logname = "NFRouteServerPlugin", guid = 0, desc = "tNFRouteServerPlugin"},
	{logid = NFLogId.NF_LOG_STORE_SERVER_PLUGIN, display=true, level=0, logname = "NFStoreServerPlugin", guid = 0, desc = "NFStoreServerPlugin"},
	{logid = NFLogId.NF_LOG_WORLD_SERVER_PLUGIN, display=true, level=0, logname = "NFWorldServerPlugin", guid = 0, desc = "NFWorldServerPlugin"},
	{logid = NFLogId.NF_LOG_LOGIN_SERVER_PLUGIN, display=true, level=0, logname = "NFLoginServerPlugin", guid = 0, desc = "NFLoginServerPlugin"},

	{logid = NFLogId.NF_LOG_USER_MAIL_PLUGIN, display=true, level=0, logname = "NFUserMailPlugin", guid = 0, desc = "NFUserMailPlugin"},
	{logid = NFLogId.NF_LOG_SNS_SERVER_PLUGIN, display=true, level=0, logname = "NFSnsServerPlugin", guid = 0, desc = "NFSnsServerPlugin"},
	{logid = NFLogId.NF_LOG_LOGIC_SERVER_PLUGIN, display=true, level=0, logname = "NFLogicServerPlugin", guid = 0, desc = "NFLogicServerPlugin"},
	{logid = NFLogId.NF_LOG_WEB_SERVER_PLUGIN, display=true, level=0, logname = "NFWebServerPlugin", guid = 0, desc = "NFWebServerPlugin"},
	{logid = NFLogId.NF_LOG_MONITOR_SERVER_PLUGIN, display=true, level=0, logname = "NFMonitorServerPlugin", guid = 0, desc = "NFMonitorServerPlugin"},
	---------------------------game 引擎--------------------------------
	{logid = NFLogId.NF_LOG_GAME_FISH_PLUGIN, display=true, level=0, logname = "NFGameFishPlugin", guid = 0, desc = "NFGameFishPlugin"},
}
