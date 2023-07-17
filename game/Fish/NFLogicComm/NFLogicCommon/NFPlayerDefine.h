// -------------------------------------------------------------------------
//    @FileName         :    NFPlayerDefine.h
//    @Author           :    gaoyi
//    @Date             :    23-7-10
//    @Email			:    445267987@qq.com
//    @Module           :    NFPlayerDefine
//
// -------------------------------------------------------------------------

#pragma once

enum PartType
{
    PART_NONE = 0,
    PART_JETTON = 1,
    PART_MAX,
};

enum BattlePartType
{
    BATTLE_PART_NONE = 0,
    BATTLE_PART_MOVE,
    BATTLE_PART_MAX,
};

enum SnsPartType
{
    SNS_PART_NONE = 0,
    SNS_JETTON_PART = 1,
    SNS_PART_MAX,
};

typedef enum
{
    TRANS_SAVEROLEDETAIL_STATE_INIT = 0,
    TRANS_SAVEROLEDETAIL_STATE_SAVING_ROLE = 1,
    TRANS_SAVEROLEDETAIL_FIN_OK,
} TRANS_SAVEROLEDETAIL_STATE;

typedef enum
{
    TRANS_SAVEROLEDETAIL_NORMAL = 1,
    TRANS_SAVEROLEDETAIL_LOGOUT = 2,
} TRANS_SAVEROLEDETAIL_REASON;