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
    EOT_NFSnsRelationPart_ID,
	////////////////////////////sns server/////////////////////////////

	////////////////////////////logic server/////////////////////////////

    //////////////////////////logic part////////////////////////
    EOT_LOGIC_PART_ID,
    EOT_NFAchievementPart_ID,
    EOT_NFAncientPart_ID,
    EOT_NFAssistPart_ID,
    EOT_NFBestEQPart_ID,
    EOT_NFBossPart_ID,
    EOT_NFBuffPart_ID,
    EOT_NFChatPart_ID,
    EOT_NFCollectPart_ID,
    EOT_NFConvoyPart_ID,
    EOT_NFDailyWelfarePart_ID,
    EOT_NFDeityPart_ID,
    EOT_NFDragonPart_ID,
    EOT_NFDragonSoulPart_ID,
    EOT_NFDupPart_ID,
    EOT_NFEncylopediaPart_ID,
    EOT_NFEquipPart_ID,
    EOT_NFFacadePart_ID,
    EOT_NFFactionPart_ID,
    EOT_NFFestPart_ID,
    EOT_NFFindTreasurePart_ID,
    EOT_NFFunctionUnlockPart_ID,
    EOT_NFGiftPart_ID,
    EOT_NFGmaPart_ID,
    EOT_NFGodevilPart_ID,
    EOT_NFGrowPart_ID,
    EOT_NFGVBPDataPart_ID,
    EOT_NFMallPart_ID,
    EOT_NFMarryPart_ID,
    EOT_NFMIniActivity_ID,
    EOT_NFMiniPart_ID,
    EOT_NFMissionPart_ID,
    EOT_NFMountPart_ID,
    EOT_NFMovePart_ID,
    EOT_NFOccupationPart_ID,
    EOT_NFPackagePart_ID,
    EOT_NFPartStar_ID,
    EOT_NFPayPart_ID,
    EOT_NFPersonalShopPart_ID,
    EOT_NFPetPart_ID,
    EOT_NFPracticeTrue_ID,
    EOT_NFRankPart_ID,
    EOT_NFSkillPart_ID,
    EOT_NFTitlePart_ID,
    EOT_NFTurnPart_ID,
    EOT_NFVipPart_ID,
    EOT_NFWelfarePart_ID,
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
    EOT_WORLD_ACCOUNT_MGR_ID,
    EOT_WORLD_ACCOUNT_ID,
    EOT_WORLD_SESSION_ID,
    EOT_WORLD_SESSION_MGR_ID,
    EOT_WORLD_ROLE_ID,
    EOT_WORLD_ROLE_MGR_ID,
    ////////////////////////////world server trans/////////////////////////////

    ////////////////////////////world server trans/////////////////////////////
	////////////////////////////world server/////////////////////////////

	////////////////////////////game server/////////////////////////////
    EOT_NFGamePlayer_ID,
    EOT_NFGamePlayerMgr_ID,
	///////////////////////////////////////////////////////////
	EOT_SF_END_ID = EOT_SERVER_FRAME_END_ID,
} EN_SERVERFRAME_SHMOBJ_TYPE;
