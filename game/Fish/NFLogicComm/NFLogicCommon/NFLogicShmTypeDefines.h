// -------------------------------------------------------------------------
//    @FileName         :    NFServerFrameTypeDefines.h
//    @Author           :    Gao.Yi
//    @Date             :   2022-09-18
//    @Email			:    445267987@qq.com
//    @Module           :    NFPluginModule
//
// -------------------------------------------------------------------------

#pragma once

#include "NFComm/NFShmCore/NFTypeDefines.h"


typedef enum
{
	EOT_SF_BEGIN_ID = EOT_SERVER_FRAME_BEGIN_ID,
    ////////////////////////////server common////////////////////////////////////////////////

    ////////////////////////////server common////////////////////////////////////////////////

	////////////////////////////sns server/////////////////////////////
    EOT_SNS_ROLE_SIMPLE_ID,
    EOT_SNS_ROLE_DETAIL_ID,
    EOT_PLAYER_ONLINE_ID,
    EOT_SNS_CACHE_MGR_ID,
    EOT_SNS_LOAD_CACHE_MGR_ID,
    ////////////////////////////sns trans server/////////////////////////////
    EOT_SNS_TRANS_CACHE_BASE_ID,
    EOT_SNS_TRANS_GET_ROLE_SIMPLE_ID,
    EOT_SNS_TRANS_GET_ROLE_DETAIL_ID,
    EOT_SNS_TRANS_SAVE_PLAYER_SIMPLE,
    EOT_SNS_TRANS_SAVE_PLAYER_DETAIL,
    ////////////////////////////sns part server/////////////////////////////
    EOT_SNS_PART_ID,
    EOT_NFSnsJettonPart_ID,
	////////////////////////////sns server/////////////////////////////

	////////////////////////////logic server/////////////////////////////

    //////////////////////////logic part////////////////////////
    EOT_LOGIC_PART_ID,
    EOT_NFJettonPart_ID,
    EOT_NFRoomPart_ID,
    //////////////////////////logic trans////////////////////////
    EOT_TRANS_LOGIC_USER_BASE,
    EOT_TRANS_SAVE_PLAYER,
	////////////////////////////logic server/////////////////////////////
    EOT_LOGIC_PLAYER_MGR_ID,
    EOT_LOGIC_PLAYER_ID,
	////////////////////////////login server/////////////////////////////
    EOT_ACCOUNTLOGIN_HASHTABLE_ID,
	////////////////////////////login server/////////////////////////////
	////////////////////////////world server/////////////////////////////
    EOT_WORLD_PLAYER_MGR_ID,
    EOT_WORLD_PLAYER_ID,
    EOT_NFWorldRoom_ID,
    EOT_NFWorldRoomMgr_ID,
    ////////////////////////////world server trans/////////////////////////////

    ////////////////////////////world server trans/////////////////////////////
	////////////////////////////world server/////////////////////////////

	////////////////////////////game server/////////////////////////////
    EOT_NFGamePlayer_ID,
    EOT_NFGamePlayerMgr_ID,
    EOT_NFGameRoom_ID,
    EOT_NFGameRoomMgr_ID,
    EOT_NFGameDesc_ID,
    EOT_NFGameConfig_ID,
    EOT_FISH_GROUP_MGR_2004_ID,
    EOT_FISH2004_TRACE_MGR_ID,
    ////////////////////////////game server/////////////////////////////
	///////////////////////////////////////////////////////////
	EOT_SF_END_ID = EOT_SERVER_FRAME_END_ID,
} EN_SERVERFRAME_SHMOBJ_TYPE;
