require "Common"

--发包上限  upper_limit
--统计时间间隔 control_time  毫秒统计
--两个消息最小间隔  min_interval 毫秒统计

NF_CS_MSG_AccountLoginReq = 1101;
NF_CS_MSG_RegisterAccountReq = 1105;
NF_CS_MSG_UserLoginReq = 1103;
NF_CS_Msg_ReConnect_REQ = 1005;
NF_CS_Msg_Get_Room_Info_Req = 1011;
NF_CS_MSG_EnterGame_AUTO_JOIN_Req = 1013;
NF_CS_MSG_DeskListReq = 1015;
F_CS_MSG_ChairCheckReq = 1017;
NF_CS_MSG_EnterGameReq = 1019;

ProxyServer = {
    PacketMsg = {
        {cmd = NF_CS_MSG_AccountLoginReq, upper_limit = 100, min_interval = 30000,  control_time = 10000},
        {cmd = NF_CS_MSG_RegisterAccountReq,  upper_limit = 100, min_interval = 30000,  control_time = 10000},
        {cmd = NF_CS_MSG_UserLoginReq,  upper_limit = 100, min_interval = 30000,  control_time = 10000},
        {cmd = NF_CS_Msg_ReConnect_REQ,  upper_limit = 100, min_interval = 30000,  control_time = 10000},
        {cmd = NF_CS_Msg_Get_Room_Info_Req,  upper_limit = 100, min_interval = 30000,  control_time = 10000},
        {cmd = NF_CS_MSG_EnterGame_AUTO_JOIN_Req,  upper_limit = 100, min_interval = 30000,  control_time = 10000},
        {cmd = NF_CS_MSG_DeskListReq,  upper_limit = 100, min_interval = 30000,  control_time = 10000},
        {cmd = F_CS_MSG_ChairCheckReq,  upper_limit = 100, min_interval = 30000,  control_time = 10000},
        {cmd = NF_CS_MSG_EnterGameReq,  upper_limit = 100, min_interval = 30000,  control_time = 10000},
    },
};