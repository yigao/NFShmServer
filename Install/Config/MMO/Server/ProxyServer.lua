require "Common"

--发包上限  upper_limit
--统计时间间隔 control_time  毫秒统计
--两个消息最小间隔  min_interval 毫秒统计

CLIENT_LOGIN_REQ = 1;
CLIENT_CREATE_ROLE_REQ = 3;
CLIENT_RECONNECT_REQ = 9;

ProxyServer = {
    PacketMsg = {
        {cmd = CLIENT_LOGIN_REQ, upper_limit = 100, min_interval = 3000,  control_time = 10000},
        {cmd = CLIENT_RECONNECT_REQ, upper_limit = 100, min_interval = 3000,  control_time = 10000},
        {cmd = CLIENT_CREATE_ROLE_REQ, upper_limit = 100, min_interval = 3000,  control_time = 10000},
    },
};