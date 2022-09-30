require "Common"

--发包上限  upper_limit
--统计时间间隔 control_time  毫秒统计
--两个消息最小间隔  min_interval 毫秒统计

CLIENT_TO_CENTER_LOGIN_BEGIN = 18;
CLIENT_TO_CENTER_LOGIN = 19;       --登陆网关请求
CLIENT_TO_CENTER_CREATE_CHARACTER = 20;    --请求创建角色请求
CLIENT_TO_CENTER_DEL_CHARACTER = 21;       --删角色请求

ProxyServer = {
    PacketMsg = {
        {cmd = CLIENT_TO_CENTER_LOGIN, serverType = NF_ST_WORLD_SERVER, upper_limit = 100, min_interval = 0,  control_time = 10000}
        {cmd = CLIENT_TO_CENTER_CREATE_CHARACTER, serverType = NF_ST_WORLD_SERVER, upper_limit = 100, min_interval = 0,  control_time = 10000}
        {cmd = CLIENT_TO_CENTER_DEL_CHARACTER, serverType = NF_ST_WORLD_SERVER, upper_limit = 100, min_interval = 0,  control_time = 10000}
    },
};