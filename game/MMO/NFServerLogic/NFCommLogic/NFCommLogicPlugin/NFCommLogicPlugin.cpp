// -------------------------------------------------------------------------
//    @FileName         :    NFCommLogicPlugin.cpp
//    @Author           :    Gao.Yi
//    @Date             :   2022-09-18
//    @Email			:    445267987@qq.com
//    @Module           :    NFCommLogicPlugin
//
// -------------------------------------------------------------------------

#include "NFCommLogicPlugin.h"
#include "NFCommLogicModule.h"
#include "NFComm/NFPluginModule/NFIPluginManager.h"
#include "NFComm/NFPluginModule/NFIConfigModule.h"
#include "NFComm/NFPluginModule/NFCheck.h"
#include "DescStore/MsgPhpmsgDesc.h"
#include "DescStore/UiEffectDesc.h"
#include "DescStore/RoleBornDesc.h"
#include "DescStore/RoleMastermaleDesc.h"
#include "DescStore/RoleMasterfemaleDesc.h"
#include "DescStore/RoleSicklemaleDesc.h"
#include "DescStore/RoleSicklefemaleDesc.h"
#include "DescStore/RoleSwordmaleDesc.h"
#include "DescStore/RoleSwordfemaleDesc.h"
#include "DescStore/RoleTaidaomaleDesc.h"
#include "DescStore/RoleTaidaofemaleDesc.h"
#include "DescStore/RoleExpDesc.h"
#include "DescStore/RoleSkilltypeDesc.h"
#include "DescStore/RoleAddskillDesc.h"
#include "DescStore/RoleWorldexpDesc.h"
#include "DescStore/RandomnameManfirstDesc.h"
#include "DescStore/RandomnameMansecondDesc.h"
#include "DescStore/RandomnameManthirdDesc.h"
#include "DescStore/RandomnameWomanfirstDesc.h"
#include "DescStore/RandomnameWomansecondDesc.h"
#include "DescStore/RandomnameWomanthirdDesc.h"
#include "DescStore/SensitivewordSensitive_wordDesc.h"
#include "DescStore/SensitivewordRolesensitiveDesc.h"
#include "DescStore/MapMapDesc.h"
#include "DescStore/MapItemdropDesc.h"
#include "DescStore/MapDestroyitemDesc.h"
#include "DescStore/MonsterMonsterDesc.h"
#include "DescStore/MonsterDisplayDesc.h"
#include "DescStore/MonsterValueDesc.h"
#include "DescStore/MonsterValueparamDesc.h"
#include "DescStore/MonsterDropDesc.h"
#include "DescStore/AreaAreaDesc.h"
#include "DescStore/SkillBuffDesc.h"
#include "DescStore/SkillSkillDesc.h"
#include "DescStore/SkillBuffupDesc.h"
#include "DescStore/SkillSkillupDesc.h"
#include "DescStore/SkillSkillawakeDesc.h"
#include "DescStore/ItemItemDesc.h"
#include "DescStore/EquipEquipDesc.h"
#include "DescStore/EquipStrongDesc.h"
#include "DescStore/EquipStrongexpDesc.h"
#include "DescStore/EquipStrongtotalDesc.h"
#include "DescStore/EquipGemDesc.h"
#include "DescStore/EquipStoveattDesc.h"
#include "DescStore/EquipStoveexpDesc.h"
#include "DescStore/EquipGradeDesc.h"
#include "DescStore/ConstantConstantDesc.h"
#include "DescStore/AttributeAttributeDesc.h"
#include "DescStore/AttributeSuppressDesc.h"
#include "DescStore/AttributePowersupDesc.h"
#include "DescStore/FashionFashionDesc.h"
#include "DescStore/DecorateDecorateDesc.h"
#include "DescStore/FootprintFootprintDesc.h"
#include "DescStore/HaloHaloDesc.h"
#include "DescStore/HeadportraitHeadDesc.h"
#include "DescStore/MeditationMeditationDesc.h"
#include "DescStore/FunctionunlockFunctionunlockDesc.h"
#include "DescStore/FunctionunlockPreviewDesc.h"
#include "DescStore/GmcommandGmcommandDesc.h"
#include "DescStore/LinkLinkDesc.h"
#include "DescStore/ChatChatDesc.h"
#include "DescStore/ChatSpecialchatDesc.h"
#include "DescStore/PathPathDesc.h"
#include "DescStore/IntimacyIntimacyDesc.h"
#include "DescStore/IntimacyGiftDesc.h"
#include "DescStore/AiAiDesc.h"
#include "DescStore/BossRareitemDesc.h"
#include "DescStore/BossBossDesc.h"
#include "DescStore/BossBosstypeDesc.h"
#include "DescStore/BossLayerDesc.h"
#include "DescStore/PointPointDesc.h"
#include "DescStore/FacadeDisplayDesc.h"
#include "DescStore/FacadeValueDesc.h"
#include "DescStore/FacadeTypeDesc.h"
#include "DescStore/FacadeFragmentDesc.h"
#include "DescStore/FacadeChangeDesc.h"
#include "DescStore/FacadeStarupDesc.h"
#include "DescStore/FacadeSoulDesc.h"
#include "DescStore/FacadeSoulactiveDesc.h"
#include "DescStore/FacadeSoullvDesc.h"
#include "DescStore/FacadeSoulachievementDesc.h"
#include "DescStore/DupBplevelDesc.h"
#include "DescStore/DupDupDesc.h"
#include "DescStore/DupTowerrewardDesc.h"
#include "DescStore/DupGroupDesc.h"
#include "DescStore/OfflineOfflineDesc.h"
#include "DescStore/OfflineItemlistDesc.h"
#include "DescStore/GodrelicsGodrelicsDesc.h"
#include "DescStore/GodrelicsConditionDesc.h"
#include "DescStore/ConditionConditionDesc.h"
#include "DescStore/PeractivityPeractivityDesc.h"
#include "DescStore/PeractivityWeekDesc.h"
#include "DescStore/DailyDailyDesc.h"
#include "DescStore/DailyRewardDesc.h"
#include "DescStore/DailyCultivateDesc.h"
#include "DescStore/BackBackDesc.h"
#include "DescStore/TeamTeamDesc.h"
#include "DescStore/BoxBoxDesc.h"
#include "DescStore/BoxBoxdataDesc.h"
#include "DescStore/TaskTaskDesc.h"
#include "DescStore/TaskdynamicTaskdynamicDesc.h"
#include "DescStore/TaskdynamicTaskcomcondDesc.h"
#include "DescStore/TaskdynamicTasktextDesc.h"
#include "DescStore/TaskrewardTaskrewardDesc.h"
#include "DescStore/TaskrewardTasktypeDesc.h"
#include "DescStore/TasktrackerTasktrackerDesc.h"
#include "DescStore/FlashFlashDesc.h"
#include "DescStore/FlashItemflashDesc.h"
#include "DescStore/ButtonButtonDesc.h"
#include "DescStore/VipVipDesc.h"
#include "DescStore/VipPrivilegeDesc.h"
#include "DescStore/ArenaRobotDesc.h"
#include "DescStore/ArenaArenawardDesc.h"
#include "DescStore/ArenaRankawardDesc.h"
#include "DescStore/ArenaFirstrankDesc.h"
#include "DescStore/ArenaBuychallengeDesc.h"



#include "DescStoreEx/NFMapDescStoreEx.h"
#include "NFLogicCommon/NFAttrMgr.h"
#include "DescStoreEx/NFRoleDescStoreEx.h"
#include "DescStoreEx/NFFuncUnLockDescStoreEx.h"
#include "DescStoreEx/NFItemDescStoreEx.h"


#ifdef NF_DYNAMIC_PLUGIN

NF_EXPORT void DllStartPlugin(NFIPluginManager* pm)
{
    CREATE_PLUGIN(pm, NFCommLogicPlugin)

};

NF_EXPORT void DllStopPlugin(NFIPluginManager* pm)
{
    DESTROY_PLUGIN(pm, NFCommLogicPlugin)
};

#endif


//////////////////////////////////////////////////////////////////////////

int NFCommLogicPlugin::GetPluginVersion()
{
	return 0;
}

std::string NFCommLogicPlugin::GetPluginName()
{
	return GET_CLASS_NAME(NFCommLogicPlugin);
}

void NFCommLogicPlugin::Install()
{
	REGISTER_MODULE(m_pObjPluginManager, NFICommLogicModule, NFCommLogicModule)
}

void NFCommLogicPlugin::Uninstall()
{
	UNREGISTER_MODULE(m_pObjPluginManager, NFICommLogicModule, NFCommLogicModule)
}

bool NFCommLogicPlugin::InitShmObjectRegister()
{
    NFServerConfig* pConfig = FindModule<NFIConfigModule>()->GetAppConfig(NF_ST_NONE);
    CHECK_EXPR(pConfig, false, "pConfig == NULL");
    CHECK_EXPR(!pConfig->DefaultDBName.empty(), false, "pConfig->DefaultDBName.empty()");

    REGISTER_DESCSTORE(MsgPhpmsgDesc);
    REGISTER_DESCSTORE(UiEffectDesc);
    REGISTER_DESCSTORE(RoleBornDesc);
    REGISTER_DESCSTORE(RoleMastermaleDesc);
    REGISTER_DESCSTORE(RoleMasterfemaleDesc);
    REGISTER_DESCSTORE(RoleSicklemaleDesc);
    REGISTER_DESCSTORE(RoleSicklefemaleDesc);
    REGISTER_DESCSTORE(RoleSwordmaleDesc);
    REGISTER_DESCSTORE(RoleSwordfemaleDesc);
    REGISTER_DESCSTORE(RoleTaidaomaleDesc);
    REGISTER_DESCSTORE(RoleTaidaofemaleDesc);
    REGISTER_DESCSTORE(RoleExpDesc);
    REGISTER_DESCSTORE(RoleSkilltypeDesc);
    REGISTER_DESCSTORE(RoleAddskillDesc);
    REGISTER_DESCSTORE(RoleWorldexpDesc);
    REGISTER_DESCSTORE(RandomnameManfirstDesc);
    REGISTER_DESCSTORE(RandomnameMansecondDesc);
    REGISTER_DESCSTORE(RandomnameManthirdDesc);
    REGISTER_DESCSTORE(RandomnameWomanfirstDesc);
    REGISTER_DESCSTORE(RandomnameWomansecondDesc);
    REGISTER_DESCSTORE(RandomnameWomanthirdDesc);
    REGISTER_DESCSTORE(SensitivewordSensitive_wordDesc);
    REGISTER_DESCSTORE(SensitivewordRolesensitiveDesc);
    REGISTER_DESCSTORE(MapMapDesc);
    REGISTER_DESCSTORE(MapItemdropDesc);
    REGISTER_DESCSTORE(MapDestroyitemDesc);
    REGISTER_DESCSTORE(MonsterMonsterDesc);
    REGISTER_DESCSTORE(MonsterDisplayDesc);
    REGISTER_DESCSTORE(MonsterValueDesc);
    REGISTER_DESCSTORE(MonsterValueparamDesc);
    REGISTER_DESCSTORE(MonsterDropDesc);
    REGISTER_DESCSTORE(AreaAreaDesc);
    REGISTER_DESCSTORE(SkillBuffDesc);
    REGISTER_DESCSTORE(SkillSkillDesc);
    REGISTER_DESCSTORE(SkillBuffupDesc);
    REGISTER_DESCSTORE(SkillSkillupDesc);
    REGISTER_DESCSTORE(SkillSkillawakeDesc);
    REGISTER_DESCSTORE(ItemItemDesc);
    REGISTER_DESCSTORE(EquipEquipDesc);
    REGISTER_DESCSTORE(EquipStrongDesc);
    REGISTER_DESCSTORE(EquipStrongexpDesc);
    REGISTER_DESCSTORE(EquipStrongtotalDesc);
    REGISTER_DESCSTORE(EquipGemDesc);
    REGISTER_DESCSTORE(EquipStoveattDesc);
    REGISTER_DESCSTORE(EquipStoveexpDesc);
    REGISTER_DESCSTORE(EquipGradeDesc);
    REGISTER_DESCSTORE(ConstantConstantDesc);
    REGISTER_DESCSTORE(AttributeAttributeDesc);
    REGISTER_DESCSTORE(AttributeSuppressDesc);
    REGISTER_DESCSTORE(AttributePowersupDesc);
    REGISTER_DESCSTORE(FashionFashionDesc);
    REGISTER_DESCSTORE(DecorateDecorateDesc);
    REGISTER_DESCSTORE(FootprintFootprintDesc);
    REGISTER_DESCSTORE(HaloHaloDesc);
    REGISTER_DESCSTORE(HeadportraitHeadDesc);
    REGISTER_DESCSTORE(MeditationMeditationDesc);
    REGISTER_DESCSTORE(FunctionunlockFunctionunlockDesc);
    REGISTER_DESCSTORE(FunctionunlockPreviewDesc);
    REGISTER_DESCSTORE(GmcommandGmcommandDesc);
    REGISTER_DESCSTORE(LinkLinkDesc);
    REGISTER_DESCSTORE(ChatChatDesc);
    REGISTER_DESCSTORE(ChatSpecialchatDesc);
    REGISTER_DESCSTORE(PathPathDesc);
    REGISTER_DESCSTORE(IntimacyIntimacyDesc);
    REGISTER_DESCSTORE(IntimacyGiftDesc);
    REGISTER_DESCSTORE(AiAiDesc);
    REGISTER_DESCSTORE(BossRareitemDesc);
    REGISTER_DESCSTORE(BossBossDesc);
    REGISTER_DESCSTORE(BossBosstypeDesc);
    REGISTER_DESCSTORE(BossLayerDesc);
    REGISTER_DESCSTORE(PointPointDesc);
    REGISTER_DESCSTORE(FacadeDisplayDesc);
    REGISTER_DESCSTORE(FacadeValueDesc);
    REGISTER_DESCSTORE(FacadeTypeDesc);
    REGISTER_DESCSTORE(FacadeFragmentDesc);
    REGISTER_DESCSTORE(FacadeChangeDesc);
    REGISTER_DESCSTORE(FacadeStarupDesc);
    REGISTER_DESCSTORE(FacadeSoulDesc);
    REGISTER_DESCSTORE(FacadeSoulactiveDesc);
    REGISTER_DESCSTORE(FacadeSoullvDesc);
    REGISTER_DESCSTORE(FacadeSoulachievementDesc);
    REGISTER_DESCSTORE(DupBplevelDesc);
    REGISTER_DESCSTORE(DupDupDesc);
    REGISTER_DESCSTORE(DupTowerrewardDesc);
    REGISTER_DESCSTORE(DupGroupDesc);
    REGISTER_DESCSTORE(OfflineOfflineDesc);
    REGISTER_DESCSTORE(OfflineItemlistDesc);
    REGISTER_DESCSTORE(GodrelicsGodrelicsDesc);
    REGISTER_DESCSTORE(GodrelicsConditionDesc);
    REGISTER_DESCSTORE(ConditionConditionDesc);
    REGISTER_DESCSTORE(PeractivityPeractivityDesc);
    REGISTER_DESCSTORE(PeractivityWeekDesc);
    REGISTER_DESCSTORE(DailyDailyDesc);
    REGISTER_DESCSTORE(DailyRewardDesc);
    REGISTER_DESCSTORE(DailyCultivateDesc);
    REGISTER_DESCSTORE(BackBackDesc);
    REGISTER_DESCSTORE(TeamTeamDesc);
    REGISTER_DESCSTORE(BoxBoxDesc);
    REGISTER_DESCSTORE(BoxBoxdataDesc);
    REGISTER_DESCSTORE(TaskTaskDesc);
    REGISTER_DESCSTORE(TaskdynamicTaskdynamicDesc);
    REGISTER_DESCSTORE(TaskdynamicTaskcomcondDesc);
    REGISTER_DESCSTORE(TaskdynamicTasktextDesc);
    REGISTER_DESCSTORE(TaskrewardTaskrewardDesc);
    REGISTER_DESCSTORE(TaskrewardTasktypeDesc);
    REGISTER_DESCSTORE(TasktrackerTasktrackerDesc);
    REGISTER_DESCSTORE(FlashFlashDesc);
    REGISTER_DESCSTORE(FlashItemflashDesc);
    REGISTER_DESCSTORE(ButtonButtonDesc);
    REGISTER_DESCSTORE(VipVipDesc);
    REGISTER_DESCSTORE(VipPrivilegeDesc);
    REGISTER_DESCSTORE(ArenaRobotDesc);
    REGISTER_DESCSTORE(ArenaArenawardDesc);
    REGISTER_DESCSTORE(ArenaRankawardDesc);
    REGISTER_DESCSTORE(ArenaFirstrankDesc);
    REGISTER_DESCSTORE(ArenaBuychallengeDesc);


    /////////////////////////////////////////Register DescStroeEx//////////////////////////////////
    REGISTER_DESCSTORE(NFMapDescStoreEx);
    REGISTER_DESCSTORE(NFRoleDescStoreEx);
    REGISTER_DESCSTORE(NFFuncUnLockDescStoreEx);
    REGISTER_DESCSTORE(NFItemDescStoreEx);

    /////////////////////////////////////Server Common////////////////////////////////////////////
    REGISTER_SINGLETON_SHM_OBJ(NFAttrMgr);
    /////////////////////////////////////Server Common////////////////////////////////////////////
	return true;
}
