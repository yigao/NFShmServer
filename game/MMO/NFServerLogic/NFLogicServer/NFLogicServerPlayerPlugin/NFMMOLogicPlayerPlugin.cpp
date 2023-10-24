// -------------------------------------------------------------------------
//    @FileName         :    NFLogicServerPlayerPlugin.cpp
//    @Author           :    gaoyi
//    @Date             :   2023-07-10
//    @Email			:    445267987@qq.com
//    @Module           :    NFLogicServerPlayerPlugin
//
// -------------------------------------------------------------------------

#include "NFMMOLogicPlayerPlugin.h"
#include "NFComm/NFPluginModule/NFIPluginManager.h"
#include "NFComm/NFPluginModule/NFConfigDefine.h"
#include "NFComm/NFPluginModule/NFIConfigModule.h"
#include "NFLogicPlayerModule.h"
#include "Player/NFPlayerMgr.h"
#include "Player/NFPlayer.h"
#include "Part/NFPartModule.h"
#include "Player/NFAchievementPart.h"
#include "Player/NFAncientPart.h"
#include "Player/NFAssistPart.h"
#include "Player/NFBestEQPart.h"
#include "Player/NFBossPart.h"
#include "Player/NFBuffPart.h"
#include "Player/NFChatPart.h"
#include "Player/NFCollectPart.h"
#include "Player/NFConvoyPart.h"
#include "Player/NFDeityPart.h"
#include "Player/NFDailyWelfarePart.h"
#include "Player/NFDragonPart.h"
#include "Player/NFDragonSoulPart.h"
#include "Player/NFDupPart.h"
#include "Player/NFEncylopediaPart.h"
#include "Player/NFFacadePart.h"
#include "Player/NFEquipPart.h"
#include "Player/NFFactionPart.h"
#include "Player/NFFestPart.h"
#include "Player/NFFindTreasurePart.h"
#include "Player/NFFunctionUnlockPart.h"
#include "Player/NFGiftPart.h"
#include "Player/NFGmaPart.h"
#include "Player/NFGodEvilPart.h"
#include "Player/NFGVBPDataPart.h"
#include "Player/NFGrowPart.h"
#include "Player/NFMallPart.h"
#include "Player/NFMarryPart.h"
#include "Player/NFMIniActivity.h"
#include "Player/NFMiniPart.h"
#include "Player/NFMissionPart.h"
#include "Player/NFMountPart.h"
#include "Player/NFMovePart.h"
#include "Player/NFOccupationPart.h"
#include "Player/NFPackagePart.h"
#include "Player/NFStarPart.h"
#include "Player/NFPayPart.h"
#include "Player/NFPetPart.h"
#include "Player/NFPracticeTrue.h"
#include "Player/NFRankPart.h"
#include "Player/NFSkillPart.h"
#include "Player/NFTitlePart.h"
#include "Player/NFTurnPart.h"
#include "Player/NFVipPart.h"
#include "Player/NFWelfarePart.h"
#include "Player/NFPersonalShopPart.h"
#include "Player/NFArmorPart.h"
#include "Player/NFPvpPart.h"


#ifdef NF_DYNAMIC_PLUGIN

NF_EXPORT void DllStartPlugin(NFIPluginManager* pm)
{
    CREATE_PLUGIN(pm, NFMMOLogicPlayerPlugin)

};

NF_EXPORT void DllStopPlugin(NFIPluginManager* pm)
{
    DESTROY_PLUGIN(pm, NFMMOLogicPlayerPlugin)
};

#endif


//////////////////////////////////////////////////////////////////////////

int NFMMOLogicPlayerPlugin::GetPluginVersion()
{
	return 0;
}

std::string NFMMOLogicPlayerPlugin::GetPluginName()
{
	return GET_CLASS_NAME(NFMMOLogicPlayerPlugin);
}

void NFMMOLogicPlayerPlugin::Install()
{
    REGISTER_MODULE(m_pObjPluginManager, NFCLogicPlayerModule, NFCLogicPlayerModule);
    REGISTER_MODULE(m_pObjPluginManager, NFPartModule, NFPartModule);
}

void NFMMOLogicPlayerPlugin::Uninstall()
{
    UNREGISTER_MODULE(m_pObjPluginManager, NFCLogicPlayerModule, NFCLogicPlayerModule);
    UNREGISTER_MODULE(m_pObjPluginManager, NFPartModule, NFPartModule);
}

bool NFMMOLogicPlayerPlugin::InitShmObjectRegister()
{
    NFServerConfig* pConfig = FindModule<NFIConfigModule>()->GetAppConfig(NF_ST_LOGIC_SERVER);
    NF_ASSERT(pConfig);

    uint32_t maxOnlinePlayerNum = pConfig->GetMaxOnlinePlayerNum() * 1.2;

    REGISTER_SHM_OBJ_WITH_HASH(NFPlayer, maxOnlinePlayerNum);
    REGISTER_SINGLETON_SHM_OBJ(NFPlayerMgr);//


    ////////////////////////////part////////////////////////////
    REGISTER_SHM_OBJ(NFAchievementPart, maxOnlinePlayerNum);
    REGISTER_SHM_OBJ(NFAncientPart, maxOnlinePlayerNum);
    REGISTER_SHM_OBJ(NFAssistPart, maxOnlinePlayerNum);
    REGISTER_SHM_OBJ(NFBestEQPart, maxOnlinePlayerNum);
    REGISTER_SHM_OBJ(NFBossPart, maxOnlinePlayerNum);
    REGISTER_SHM_OBJ(NFBuffPart, maxOnlinePlayerNum);
    REGISTER_SHM_OBJ(NFChatPart, maxOnlinePlayerNum);
    REGISTER_SHM_OBJ(NFCollectPart, maxOnlinePlayerNum);
    REGISTER_SHM_OBJ(NFConvoyPart, maxOnlinePlayerNum);
    REGISTER_SHM_OBJ(NFDailyWelfarePart, maxOnlinePlayerNum);
    REGISTER_SHM_OBJ(NFDeityPart, maxOnlinePlayerNum);
    REGISTER_SHM_OBJ(NFDragonPart, maxOnlinePlayerNum);
    REGISTER_SHM_OBJ(NFDragonSoulPart, maxOnlinePlayerNum);
    REGISTER_SHM_OBJ(NFDupPart, maxOnlinePlayerNum);
    REGISTER_SHM_OBJ(NFEncylopediaPart, maxOnlinePlayerNum);
    REGISTER_SHM_OBJ(NFEquipPart, maxOnlinePlayerNum);
    REGISTER_SHM_OBJ(NFFacadePart, maxOnlinePlayerNum);
    REGISTER_SHM_OBJ(NFFactionPart, maxOnlinePlayerNum);
    REGISTER_SHM_OBJ(NFFestPart, maxOnlinePlayerNum);
    REGISTER_SHM_OBJ(NFFindTreasurePart, maxOnlinePlayerNum);
    REGISTER_SHM_OBJ(NFFunctionUnlockPart, maxOnlinePlayerNum);
    REGISTER_SHM_OBJ(NFGiftPart, maxOnlinePlayerNum);
    REGISTER_SHM_OBJ(NFGmaPart, maxOnlinePlayerNum);
    REGISTER_SHM_OBJ(NFGodEvilPart, maxOnlinePlayerNum);
    REGISTER_SHM_OBJ(NFGrowPart, maxOnlinePlayerNum);
    REGISTER_SHM_OBJ(NFGVBPDataPart, maxOnlinePlayerNum);
    REGISTER_SHM_OBJ(NFMallPart, maxOnlinePlayerNum);
    REGISTER_SHM_OBJ(NFMarryPart, maxOnlinePlayerNum);
    REGISTER_SHM_OBJ(NFMIniActivity, maxOnlinePlayerNum);
    REGISTER_SHM_OBJ(NFMiniPart, maxOnlinePlayerNum);
    REGISTER_SHM_OBJ(NFMissionPart, maxOnlinePlayerNum);
    REGISTER_SHM_OBJ(NFMountPart, maxOnlinePlayerNum);
    REGISTER_SHM_OBJ(NFMovePart, maxOnlinePlayerNum);
    REGISTER_SHM_OBJ(NFOccupationPart, maxOnlinePlayerNum);
    REGISTER_SHM_OBJ(NFPackagePart, maxOnlinePlayerNum);
    REGISTER_SHM_OBJ(NFStarPart, maxOnlinePlayerNum);
    REGISTER_SHM_OBJ(NFPayPart, maxOnlinePlayerNum);
    REGISTER_SHM_OBJ(NFPersonalShopPart, maxOnlinePlayerNum);
    REGISTER_SHM_OBJ(NFPetPart, maxOnlinePlayerNum);
    REGISTER_SHM_OBJ(NFPracticeTrue, maxOnlinePlayerNum);
    REGISTER_SHM_OBJ(NFRankPart, maxOnlinePlayerNum);
    REGISTER_SHM_OBJ(NFSkillPart, maxOnlinePlayerNum);
    REGISTER_SHM_OBJ(NFTitlePart, maxOnlinePlayerNum);
    REGISTER_SHM_OBJ(NFTurnPart, maxOnlinePlayerNum);
    REGISTER_SHM_OBJ(NFVipPart, maxOnlinePlayerNum);
    REGISTER_SHM_OBJ(NFWelfarePart, maxOnlinePlayerNum);
    REGISTER_SHM_OBJ(NFArmorPart, maxOnlinePlayerNum);
    REGISTER_SHM_OBJ(NFPvpPart, maxOnlinePlayerNum);
    ////////////////////////////part////////////////////////////

    REGISTER_SHM_OBJ(NFTransPlayerBase, 1);
    REGISTER_SHM_OBJ(NFTransSaveDB, maxOnlinePlayerNum);
    return true;
}