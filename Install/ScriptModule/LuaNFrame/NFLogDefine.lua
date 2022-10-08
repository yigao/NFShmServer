NF_LOG_LEVEL_TRACE = 0 --    trace = 0,
NF_LOG_LEVEL_DEBUG = 1 --    debug = 1,
NF_LOG_LEVEL_INFO = 2  --    info = 2,
NF_LOG_LEVEL_WARN = 3  --    warn = 3,
NF_LOG_LEVEL_ERROR = 4 --    err = 4,


NFLogId = {
	--0-100是基础框架层LOG
	NF_LOG_DEFAULT = 0,						--默认LOG
	NF_LOG_SYSTEMLOG = 1,					--系统LOG
	NF_LOG_ACTOR_PLUGIN = 2,				--Actor 引擎 
	NF_LOG_KERNEL_PLUGIN = 3,				--kernel 引擎
	NF_LOG_LUA_PLUGIN = 4,					--lua 引擎
	NF_LOG_MONGO_PLUGIN = 5,				--mongo 引擎
	NF_LOG_MONITOR_PLUGIN = 5,				--monitor 引擎
	NF_LOG_MYSQL_PLUGIN = 7,				--mysql 引擎
	NF_LOG_NET_PLUGIN = 8,					--net 引擎
	NF_LOG_SQLITE_PLUGIN = 9,				--sqlite 引擎
	NF_LOG_TEST_PLUGIN = 10,				--test 引擎


	NF_LOG_LOAD_CONFIG = 21,				--加载配置
	NF_LOG_PROTOBUF_PARSE = 22,				--protobuf解析出错
	NF_LOG_PLUGIN_MANAGER = 100,			--引擎加载器
	NF_LOG_MAX_SYSTEM_PLUGIN = 100,

	------------------------------------------------------------------------------------------
	NF_LOG_BEGIN_SERVER_LOG = 101,			--101-1000是系统框架层LOG

	NF_LOG_SERVER_CONNECT_SERVER = 101,		--服务器与服务器连接LOG
	NF_LOG_SERVER_NOT_HANDLE_MESSAGE = 102,		--服务器未处理消息的LOG

	NF_LOG_END_SERVER_LOG = 1000,			--

	-------------------------------------------------------------------------


	NF_LOG_BEGIN_LOGIC_LOG = 1001,			--1001以后是逻辑框架层
	NF_LOG_MAX_ID = 10240, --最大LOGID
}