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
    EOT_NFTestMgr_ID,
    EOT_SERVER_COMMON_ATTR_MGR_ID,
    EOT_SERVER_COMMON_COMFIGHT_ATTR_ID,
    EOT_SERVER_COMMON_ROLEFIGHT_ATTR_ID,
    EOT_SERVER_COMMON_COM_ATTR_ID,
    EOT_SERVER_COMMON_ROLE_ATTR_ID,
    ////////////////////////////server common////////////////////////////////////////////////

	////////////////////////////sns server/////////////////////////////
	EOT_SNS_ROLE_SIMPLE_ID,
    EOT_SNS_ROLE_DETAIL_ID,
    EOT_SNS_CACHE_MGR_ID,
    EOT_SNS_LOAD_CACHE_MGR_ID,
    ////////////////////////////sns trans server/////////////////////////////
    EOT_SNS_TRANS_CACHE_BASE_ID,
    EOT_SNS_TRANS_GET_ROLE_SIMPLE_ID,
    EOT_SNS_TRANS_GET_ROLE_DETAIL_ID,
    EOT_SNS_TRANS_ROLE_LOGIN_ID,
    ////////////////////////////sns server/////////////////////////////
	////////////////////////////sns server/////////////////////////////

	////////////////////////////logic server/////////////////////////////
    EOT_LOGIC_PLAYER_ID,
    EOT_LOGIC_PLAYER_MGR_ID,
    EOT_LOGIC_ITEM_MGR_ID,
    //////////////////////////logic part////////////////////////
    EOT_LOGIC_PART_ID,
    EOT_LOGIC_PACKAGE_PART_ID,
    EOT_LOGIC_FUNCTIONUNLOCK_PART_ID,
    EOT_LOGIC_GROW_PART_ID,
    EOT_LOGIC_MINI_PART_ID,
    EOT_LOGIC_CHAT_PART_ID,
    EOT_LOGIC_EQUIP_PART_ID,
    EOT_LOGIC_MISSION_PART_ID,
    EOT_LOGIC_TITLE_PART_ID,
    //////////////////////////logic trans////////////////////////
    EOT_TRANS_LOGIC_PLAYER_BASE,
    EOT_TRANS_LOGIC_GET_ROLE_LIST,
    EOT_TRANS_LOGIC_CREATE_ROLE,
    EOT_TRANS_LOGIC_GET_ROLE,
    EOT_TRANS_LOGIC_SAVE_ROLE,
    EOT_TRANS_LOGIC_ENTER_SCENE,
	////////////////////////////logic server/////////////////////////////

	////////////////////////////login server/////////////////////////////
	////////////////////////////login server/////////////////////////////
	////////////////////////////world server/////////////////////////////
	EOT_WORLD_CONFIG_ID,
	EOT_WORLD_PLAYER_ID,
	EOT_WORLD_PLAYER_MGR_ID,
    EOT_WORLD_SESSION_ID,
    EOT_WORLD_SESSION_MGR_ID,
    EOT_WORLD_SCENE_MGR_ID,
    ////////////////////////////world server trans/////////////////////////////
    EOT_NFTransWorldSendGetRoleList_ID,
    EOT_NFTransWorldCreateRole_ID,
    EOT_NFTransWorldEnterGame_ID,
    EOT_NFTransWorldTransScene_ID,
    ////////////////////////////world server trans/////////////////////////////
	////////////////////////////world server/////////////////////////////

	////////////////////////////game server/////////////////////////////
    EOT_GAME_MAP_ID,
    EOT_GAME_MAP_MGR_ID,
    EOT_GAME_CREATURE_MGR_ID,
    EOT_GAME_GRID_ID,
    EOT_GAME_SCENE_ID,
    EOT_GAME_SCENE_MGR_ID,
    EOT_GAME_CONFIG_ID,
    /////////////////////////game creature server/////////////////////
    EOT_GAME_CREATURE_ID,
    EOT_GAME_NFBattlePlayer_ID,
    ////////////////////////////game server/////////////////////////////
    ////////////////////////////game battle part /////////////////////////////
    EOT_NFBattlePart_ID,
    EOT_NFMovePart_ID,
    ////////////////////////////game battle part /////////////////////////////
	///////////////////////////////////////////////////////////
	EOT_SF_END_ID = EOT_SERVER_FRAME_END_ID,
} EN_SERVERFRAME_SHMOBJ_TYPE;
