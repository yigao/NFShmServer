
NF_LOG_LEVEL_TRACE = 0 --    trace = 0,
NF_LOG_LEVEL_DEBUG = 1 --    debug = 1,
NF_LOG_LEVEL_INFO = 2  --    info = 2,
NF_LOG_LEVEL_WARN = 3  --    warn = 3,
NF_LOG_LEVEL_ERROR = 4 --    err = 4,


LogLevel = NF_LOG_LEVEL_INFO;				--log等级配置		当前日志输出级别，大于此等于级别的才会输出到console
LogFlushLevel = NF_LOG_LEVEL_INFO;			--log刷新等级配置, 当前日志输出级别，大于此等于级别的才会刷新到LOG文件里


NFLogId = {
	--0-100是基础框架层LOG
	NF_LOG_DEFAULT = 0,						--默认LOG
	NF_LOG_SYSTEMLOG = 1,					--系统LOG
	NF_LOG_RECV_MSG = 3,					--接受消息
	NF_LOG_RECV_MSG_JSON_PRINTF = 4,		--接受消息Json输出
	NF_LOG_LOAD_CONFIG = 5,				--加载配置
	NF_LOG_PROTOBUF_PARSE = 6,				--protobuf解析出错
	NF_LOG_PLUGIN_MANAGER = 7,			--引擎加载器
	NF_LOG_MAX_ID = 100, --最大LOGID
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
	{logid = NFLogId.NF_LOG_RECV_MSG, display=false, level=0, logname = "RecvMsg", guid = 0, desc = "接受消息LOG"},
	{logid = NFLogId.NF_LOG_RECV_MSG_JSON_PRINTF, display=false, level=0, logname = "RecvMsgJson", guid = 0, desc = "接受消息Json输出LOG"},
	{logid = NFLogId.NF_LOG_PLUGIN_MANAGER, display=true, level=0, logname = "PluginLog", guid = 0, desc = "引擎管理LOG"},
	{logid = NFLogId.NF_LOG_LOAD_CONFIG, display=true, level=0, logname = "LoadConfigLog", guid = 0, desc = "加载配置LOG"},
	{logid = NFLogId.NF_LOG_PROTOBUF_PARSE, display=true, level=0, logname = "ProtobufParse", guid = 0, desc = "protobuf解析出错LOG"},
}
