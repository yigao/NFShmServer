require "Common"

--发包上限  upper_limit
--统计时间间隔 control_time  毫秒统计
--两个消息最小间隔  min_interval 毫秒统计

NF_CS_MSG_AccountLoginReq = 1101;
NF_CS_MSG_RegisterAccountReq = 1105;
NF_CS_MSG_UserLoginReq = 1103;
NF_CS_Msg_ReConnect_REQ = 1005;

ProxyServer = {
    PacketMsg = {
        {cmd = NF_CS_MSG_AccountLoginReq, upper_limit = 100, min_interval = 3000,  control_time = 10000},
        {cmd = NF_CS_MSG_RegisterAccountReq,  upper_limit = 100, min_interval = 3000,  control_time = 10000},
        {cmd = NF_CS_MSG_UserLoginReq,  upper_limit = 100, min_interval = 3000,  control_time = 10000},
        {cmd = NF_CS_Msg_ReConnect_REQ,  upper_limit = 100, min_interval = 3000,  control_time = 10000},
    },
};