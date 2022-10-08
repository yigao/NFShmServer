NF_SERVER_TYPES = {
	-- server type
	NF_ST_NONE = 0,    		-- NONE
	NF_ST_MASTER = 1,    	--
	NF_ST_LOGIN = 2,    	--
	NF_ST_WORLD = 3,    	--
	NF_ST_GAME = 4,    		--
	NF_ST_PROXY = 5,    	--
	NF_ST_WEB = 6,			-- WEB SERVER
	NF_ST_LOCATION = 7, 	--LOCATION SERVER
	NF_ST_LOG = 8, 			--日志采集服务器 
	NF_ST_REBOT = 15,		--机器人模拟客户端
	NF_ST_MAX = 20,    		--
};

NF_MSG_TYPE = {
	eMsgType_Num = 0,
	eMsgType_CONNECTED = 1,
	eMsgType_DISCONNECTED = 2,
	eMsgType_RECIVEDATA = 3,
};

NF_ACCOUNT_EVENT_TYPE = {
	eAccountEventType_Num = 0,
	eAccountEventType_CONNECTED = 1,
	eAccountEventType_DISCONNECTED = 2,
	eAccountEventType_RECONNECTED = 3,
}