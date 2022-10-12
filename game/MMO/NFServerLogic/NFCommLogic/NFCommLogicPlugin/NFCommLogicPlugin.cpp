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
#include "DescStore/RoleWarriorDesc.h"
#include "DescStore/RoleMasterDesc.h"
#include "DescStore/RoleAssassinDesc.h"
#include "DescStore/RoleShooterDesc.h"
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
#include "DescStore/AreaAreaDesc.h"
#include "DescStore/AreaPathDesc.h"
#include "DescStore/SkillSkillDesc.h"
#include "DescStore/SkillBuffDesc.h"
#include "DescStore/ItemItemDesc.h"
#include "DescStore/EquipEquipDesc.h"
#include "DescStore/ConstantConstantDesc.h"


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

    REGISTER_DESCSTORE(MsgPhpmsgDesc, EOT_CONST_MSG_PHPMSG_DESC_ID);
    REGISTER_DESCSTORE(UiEffectDesc, EOT_CONST_UI_EFFECT_DESC_ID);
    REGISTER_DESCSTORE(RoleBornDesc, EOT_CONST_ROLE_BORN_DESC_ID);
    REGISTER_DESCSTORE(RoleWarriorDesc, EOT_CONST_ROLE_WARRIOR_DESC_ID);
    REGISTER_DESCSTORE(RoleMasterDesc, EOT_CONST_ROLE_MASTER_DESC_ID);
    REGISTER_DESCSTORE(RoleAssassinDesc, EOT_CONST_ROLE_ASSASSIN_DESC_ID);
    REGISTER_DESCSTORE(RoleShooterDesc, EOT_CONST_ROLE_SHOOTER_DESC_ID);
    REGISTER_DESCSTORE(RoleExpDesc, EOT_CONST_ROLE_EXP_DESC_ID);
    REGISTER_DESCSTORE(RoleSkilltypeDesc, EOT_CONST_ROLE_SKILLTYPE_DESC_ID);
    REGISTER_DESCSTORE(RoleAddskillDesc, EOT_CONST_ROLE_ADDSKILL_DESC_ID);
    REGISTER_DESCSTORE(RoleWorldexpDesc, EOT_CONST_ROLE_WORLDEXP_DESC_ID);
    REGISTER_DESCSTORE(RandomnameManfirstDesc, EOT_CONST_RANDOMNAME_MANFIRST_DESC_ID);
    REGISTER_DESCSTORE(RandomnameMansecondDesc, EOT_CONST_RANDOMNAME_MANSECOND_DESC_ID);
    REGISTER_DESCSTORE(RandomnameManthirdDesc, EOT_CONST_RANDOMNAME_MANTHIRD_DESC_ID);
    REGISTER_DESCSTORE(RandomnameWomanfirstDesc, EOT_CONST_RANDOMNAME_WOMANFIRST_DESC_ID);
    REGISTER_DESCSTORE(RandomnameWomansecondDesc, EOT_CONST_RANDOMNAME_WOMANSECOND_DESC_ID);
    REGISTER_DESCSTORE(RandomnameWomanthirdDesc, EOT_CONST_RANDOMNAME_WOMANTHIRD_DESC_ID);
    REGISTER_DESCSTORE(SensitivewordSensitive_wordDesc, EOT_CONST_SENSITIVEWORD_SENSITIVE_WORD_DESC_ID);
    REGISTER_DESCSTORE(SensitivewordRolesensitiveDesc, EOT_CONST_SENSITIVEWORD_ROLESENSITIVE_DESC_ID);
    REGISTER_DESCSTORE(MapMapDesc, EOT_CONST_MAP_MAP_DESC_ID);
    REGISTER_DESCSTORE(MapItemdropDesc, EOT_CONST_MAP_ITEMDROP_DESC_ID);
    REGISTER_DESCSTORE(MapDestroyitemDesc, EOT_CONST_MAP_DESTROYITEM_DESC_ID);
    REGISTER_DESCSTORE(MonsterMonsterDesc, EOT_CONST_MONSTER_MONSTER_DESC_ID);
    REGISTER_DESCSTORE(MonsterDisplayDesc, EOT_CONST_MONSTER_DISPLAY_DESC_ID);
    REGISTER_DESCSTORE(MonsterValueDesc, EOT_CONST_MONSTER_VALUE_DESC_ID);
    REGISTER_DESCSTORE(AreaAreaDesc, EOT_CONST_AREA_AREA_DESC_ID);
    REGISTER_DESCSTORE(AreaPathDesc, EOT_CONST_AREA_PATH_DESC_ID);
    REGISTER_DESCSTORE(SkillSkillDesc, EOT_CONST_SKILL_SKILL_DESC_ID);
    REGISTER_DESCSTORE(SkillBuffDesc, EOT_CONST_SKILL_BUFF_DESC_ID);
    REGISTER_DESCSTORE(ItemItemDesc, EOT_CONST_ITEM_ITEM_DESC_ID);
    REGISTER_DESCSTORE(EquipEquipDesc, EOT_CONST_EQUIP_EQUIP_DESC_ID);
    REGISTER_DESCSTORE(ConstantConstantDesc, EOT_CONST_CONSTANT_CONSTANT_DESC_ID);

	return true;
}
