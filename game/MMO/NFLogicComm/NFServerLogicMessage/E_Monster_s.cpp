#include "E_Monster_s.h"

namespace proto_ff_s {

E_MonsterMonster_s::E_MonsterMonster_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_MonsterMonster_s::CreateInit() {
	m_monsterID = (int64_t)0;
	m_functionType = (int32_t)0;
	m_functionValue = (int64_t)0;
	m_taskType = (int32_t)0;
	m_profession = (int32_t)0;
	m_subProfession = (int32_t)0;
	m_damageAddType = (int32_t)0;
	m_monsterLV = (int32_t)0;
	m_droplimit = (int32_t)0;
	m_displayID = (int64_t)0;
	m_bossID = (int32_t)0;
	m_valuetype = (int64_t)0;
	m_valueParam = (int32_t)0;
	m_aiId = (int64_t)0;
	m_hpSectionNum = (int32_t)0;
	m_breedProb = (int32_t)0;
	m_breedMonID = (int64_t)0;
	m_breedMonLive = (int32_t)0;
	m_isBornActionOn = (int32_t)0;
	m_belongshow = (int32_t)0;
	m_dropGroupID = (int32_t)0;
	m_harmdrop_type = (int32_t)0;
	m_joninper = (int32_t)0;
	m_btnRange = (int32_t)0;
	m_btnId = (int64_t)0;
	m_drivePoint = (int32_t)0;
	m_corpseID = (int32_t)0;
	m_battle = (int64_t)0;
	m_lvSupPve = (int32_t)0;
	m_powerSupPve = (int32_t)0;
	return 0;
}

int E_MonsterMonster_s::ResumeInit() {
	return 0;
}

void E_MonsterMonster_s::write_to_pbmsg(::proto_ff::E_MonsterMonster & msg) const {
	msg.set_m_monsterid((int64_t)m_monsterID);
	msg.set_m_monstername(m_monsterName.data());
	msg.set_m_mask(m_mask.data());
	msg.set_m_functiontype((int32_t)m_functionType);
	msg.set_m_functionvalue((int64_t)m_functionValue);
	msg.set_m_tasktype((int32_t)m_taskType);
	msg.set_m_profession((int32_t)m_profession);
	msg.set_m_subprofession((int32_t)m_subProfession);
	msg.set_m_damageaddtype((int32_t)m_damageAddType);
	msg.set_m_monsterlv((int32_t)m_monsterLV);
	msg.set_m_droplimit((int32_t)m_droplimit);
	msg.set_m_displayid((int64_t)m_displayID);
	msg.set_m_bossid((int32_t)m_bossID);
	msg.set_m_valuetype((int64_t)m_valuetype);
	msg.set_m_valueparam((int32_t)m_valueParam);
	msg.set_m_aiid((int64_t)m_aiId);
	msg.set_m_hpsectionnum((int32_t)m_hpSectionNum);
	msg.set_m_breedprob((int32_t)m_breedProb);
	msg.set_m_breedmonid((int64_t)m_breedMonID);
	msg.set_m_breedmonlive((int32_t)m_breedMonLive);
	msg.set_m_itemcost(m_itemCost.data());
	msg.set_m_isbornactionon((int32_t)m_isBornActionOn);
	msg.set_m_belongshow((int32_t)m_belongshow);
	msg.set_m_dropgroupid((int32_t)m_dropGroupID);
	msg.set_m_harmdrop_type((int32_t)m_harmdrop_type);
	msg.set_m_joninper((int32_t)m_joninper);
	msg.set_m_btnrange((int32_t)m_btnRange);
	msg.set_m_btnid((int64_t)m_btnId);
	msg.set_m_drivepoint((int32_t)m_drivePoint);
	msg.set_m_corpseid((int32_t)m_corpseID);
	msg.set_m_battle((int64_t)m_battle);
	msg.set_m_lvsuppve((int32_t)m_lvSupPve);
	msg.set_m_powersuppve((int32_t)m_powerSupPve);
}

void E_MonsterMonster_s::read_from_pbmsg(const ::proto_ff::E_MonsterMonster & msg) {
	m_monsterID = msg.m_monsterid();
	m_monsterName = msg.m_monstername();
	m_mask = msg.m_mask();
	m_functionType = msg.m_functiontype();
	m_functionValue = msg.m_functionvalue();
	m_taskType = msg.m_tasktype();
	m_profession = msg.m_profession();
	m_subProfession = msg.m_subprofession();
	m_damageAddType = msg.m_damageaddtype();
	m_monsterLV = msg.m_monsterlv();
	m_droplimit = msg.m_droplimit();
	m_displayID = msg.m_displayid();
	m_bossID = msg.m_bossid();
	m_valuetype = msg.m_valuetype();
	m_valueParam = msg.m_valueparam();
	m_aiId = msg.m_aiid();
	m_hpSectionNum = msg.m_hpsectionnum();
	m_breedProb = msg.m_breedprob();
	m_breedMonID = msg.m_breedmonid();
	m_breedMonLive = msg.m_breedmonlive();
	m_itemCost = msg.m_itemcost();
	m_isBornActionOn = msg.m_isbornactionon();
	m_belongshow = msg.m_belongshow();
	m_dropGroupID = msg.m_dropgroupid();
	m_harmdrop_type = msg.m_harmdrop_type();
	m_joninper = msg.m_joninper();
	m_btnRange = msg.m_btnrange();
	m_btnId = msg.m_btnid();
	m_drivePoint = msg.m_drivepoint();
	m_corpseID = msg.m_corpseid();
	m_battle = msg.m_battle();
	m_lvSupPve = msg.m_lvsuppve();
	m_powerSupPve = msg.m_powersuppve();
}

Sheet_MonsterMonster_s::Sheet_MonsterMonster_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_MonsterMonster_s::CreateInit() {
	return 0;
}

int Sheet_MonsterMonster_s::ResumeInit() {
	return 0;
}

void Sheet_MonsterMonster_s::write_to_pbmsg(::proto_ff::Sheet_MonsterMonster & msg) const {
	for(int32_t i = 0; i < (int32_t)E_MonsterMonster_List.size(); ++i) {
		::proto_ff::E_MonsterMonster* temp_e_monstermonster_list = msg.add_e_monstermonster_list();
		E_MonsterMonster_List[i].write_to_pbmsg(*temp_e_monstermonster_list);
	}
}

void Sheet_MonsterMonster_s::read_from_pbmsg(const ::proto_ff::Sheet_MonsterMonster & msg) {
	E_MonsterMonster_List.resize((int)msg.e_monstermonster_list_size() > (int)E_MonsterMonster_List.max_size() ? E_MonsterMonster_List.max_size() : msg.e_monstermonster_list_size());
	for(int32_t i = 0; i < (int32_t)E_MonsterMonster_List.size(); ++i) {
		const ::proto_ff::E_MonsterMonster & temp_e_monstermonster_list = msg.e_monstermonster_list(i);
		E_MonsterMonster_List[i].read_from_pbmsg(temp_e_monstermonster_list);
	}
}

E_MonsterDisplaySkillDesc_s::E_MonsterDisplaySkillDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_MonsterDisplaySkillDesc_s::CreateInit() {
	m_id = (int64_t)0;
	return 0;
}

int E_MonsterDisplaySkillDesc_s::ResumeInit() {
	return 0;
}

void E_MonsterDisplaySkillDesc_s::write_to_pbmsg(::proto_ff::E_MonsterDisplaySkillDesc & msg) const {
	msg.set_m_id((int64_t)m_id);
}

void E_MonsterDisplaySkillDesc_s::read_from_pbmsg(const ::proto_ff::E_MonsterDisplaySkillDesc & msg) {
	m_id = msg.m_id();
}

E_MonsterDisplay_s::E_MonsterDisplay_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_MonsterDisplay_s::CreateInit() {
	m_displayID = (int64_t)0;
	m_modelOffsetsX = (int32_t)0;
	m_modelOffsetsY = (int32_t)0;
	m_modelScale = (int32_t)0;
	m_modelRadius = (int32_t)0;
	m_pathRadius = (int32_t)0;
	m_collisionRadius = (int32_t)0;
	m_rSpeed = (int32_t)0;
	return 0;
}

int E_MonsterDisplay_s::ResumeInit() {
	return 0;
}

void E_MonsterDisplay_s::write_to_pbmsg(::proto_ff::E_MonsterDisplay & msg) const {
	msg.set_m_displayid((int64_t)m_displayID);
	msg.set_m_modeloffsetsx((int32_t)m_modelOffsetsX);
	msg.set_m_modeloffsetsy((int32_t)m_modelOffsetsY);
	msg.set_m_modelscale((int32_t)m_modelScale);
	msg.set_m_modelradius((int32_t)m_modelRadius);
	msg.set_m_pathradius((int32_t)m_pathRadius);
	msg.set_m_collisionradius((int32_t)m_collisionRadius);
	msg.set_m_rspeed((int32_t)m_rSpeed);
	for(int32_t i = 0; i < (int32_t)m_skill.size(); ++i) {
		::proto_ff::E_MonsterDisplaySkillDesc* temp_m_skill = msg.add_m_skill();
		m_skill[i].write_to_pbmsg(*temp_m_skill);
	}
}

void E_MonsterDisplay_s::read_from_pbmsg(const ::proto_ff::E_MonsterDisplay & msg) {
	m_displayID = msg.m_displayid();
	m_modelOffsetsX = msg.m_modeloffsetsx();
	m_modelOffsetsY = msg.m_modeloffsetsy();
	m_modelScale = msg.m_modelscale();
	m_modelRadius = msg.m_modelradius();
	m_pathRadius = msg.m_pathradius();
	m_collisionRadius = msg.m_collisionradius();
	m_rSpeed = msg.m_rspeed();
	m_skill.resize((int)msg.m_skill_size() > (int)m_skill.max_size() ? m_skill.max_size() : msg.m_skill_size());
	for(int32_t i = 0; i < (int32_t)m_skill.size(); ++i) {
		const ::proto_ff::E_MonsterDisplaySkillDesc & temp_m_skill = msg.m_skill(i);
		m_skill[i].read_from_pbmsg(temp_m_skill);
	}
}

Sheet_MonsterDisplay_s::Sheet_MonsterDisplay_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_MonsterDisplay_s::CreateInit() {
	return 0;
}

int Sheet_MonsterDisplay_s::ResumeInit() {
	return 0;
}

void Sheet_MonsterDisplay_s::write_to_pbmsg(::proto_ff::Sheet_MonsterDisplay & msg) const {
	for(int32_t i = 0; i < (int32_t)E_MonsterDisplay_List.size(); ++i) {
		::proto_ff::E_MonsterDisplay* temp_e_monsterdisplay_list = msg.add_e_monsterdisplay_list();
		E_MonsterDisplay_List[i].write_to_pbmsg(*temp_e_monsterdisplay_list);
	}
}

void Sheet_MonsterDisplay_s::read_from_pbmsg(const ::proto_ff::Sheet_MonsterDisplay & msg) {
	E_MonsterDisplay_List.resize((int)msg.e_monsterdisplay_list_size() > (int)E_MonsterDisplay_List.max_size() ? E_MonsterDisplay_List.max_size() : msg.e_monsterdisplay_list_size());
	for(int32_t i = 0; i < (int32_t)E_MonsterDisplay_List.size(); ++i) {
		const ::proto_ff::E_MonsterDisplay & temp_e_monsterdisplay_list = msg.e_monsterdisplay_list(i);
		E_MonsterDisplay_List[i].read_from_pbmsg(temp_e_monsterdisplay_list);
	}
}

E_MonsterValue_s::E_MonsterValue_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_MonsterValue_s::CreateInit() {
	m_ID = (int64_t)0;
	m_type = (int32_t)0;
	m_monsterLV = (int32_t)0;
	m_max_Hp = (int64_t)0;
	m_atk = (int64_t)0;
	m_def = (int64_t)0;
	m_brk_Armor = (int64_t)0;
	m_five_Dam = (int64_t)0;
	m_five_Armor = (int64_t)0;
	m_thump_Rate = (int64_t)0;
	m_thump_Resist = (int64_t)0;
	m_sky = (int64_t)0;
	m_sky_Dam = (int64_t)0;
	m_sky_Redu_Resist = (int64_t)0;
	m_sky_Resist = (int64_t)0;
	m_kill_God = (int64_t)0;
	m_god_Body = (int64_t)0;
	m_mortal_Rate = (int64_t)0;
	m_mortal_Resist = (int64_t)0;
	m_fairy_Rate = (int64_t)0;
	m_fairy_Resist = (int64_t)0;
	m_god_Rate = (int64_t)0;
	m_god_Resist = (int64_t)0;
	m_crit_Rate = (int64_t)0;
	m_crit_resit_Rate = (int64_t)0;
	m_crit_Dam = (int64_t)0;
	m_crit_Redu = (int64_t)0;
	m_batter_Rate = (int64_t)0;
	m_batter_Resist = (int64_t)0;
	m_batter_Dam = (int64_t)0;
	m_batter_Redu = (int64_t)0;
	m_brkdown_Rate = (int64_t)0;
	m_brkdown_Resist = (int64_t)0;
	m_dam_Add = (int64_t)0;
	m_dam_Redu = (int64_t)0;
	m_all_Add = (int64_t)0;
	m_all_Redu = (int64_t)0;
	m_skill_Add = (int64_t)0;
	m_skill_Redu = (int64_t)0;
	m_rebound_Dam = (int64_t)0;
	m_hp_Steal = (int64_t)0;
	m_dodge_Rate = (int64_t)0;
	m_hit_Rate = (int64_t)0;
	m_blk_Rate = (int64_t)0;
	m_brk_blk_Rate = (int64_t)0;
	m_blk_Free = (int64_t)0;
	m_blk_Pierce = (int64_t)0;
	m_rel_Armor = (int64_t)0;
	m_rel_Dam = (int64_t)0;
	m_five_Resist = (int64_t)0;
	m_five_resist_Redu = (int64_t)0;
	m_fire_Add = (int64_t)0;
	m_fire_Redu = (int64_t)0;
	m_ice_Add = (int64_t)0;
	m_ice_Redu = (int64_t)0;
	m_thunder_Add = (int64_t)0;
	m_thunder_Rdu = (int64_t)0;
	m_player_Add = (int64_t)0;
	m_player_Redu = (int64_t)0;
	m_leader_Add = (int64_t)0;
	m_leader_Redu = (int64_t)0;
	m_mon_Add = (int64_t)0;
	m_mon_Redu = (int64_t)0;
	m_var_Redu = (int64_t)0;
	m_var_Add = (int64_t)0;
	m_unusual_Resist = (int64_t)0;
	m_unusual_Hit = (int64_t)0;
	m_hp_Recover = (int64_t)0;
	m_unusual_Add = (int64_t)0;
	m_fix_Recover = (int64_t)0;
	m_high_hp_Add = (int64_t)0;
	m_recover_hp_Add = (int64_t)0;
	m_week_Add = (int64_t)0;
	m_shield = (int64_t)0;
	m_exp = (int64_t)0;
	return 0;
}

int E_MonsterValue_s::ResumeInit() {
	return 0;
}

void E_MonsterValue_s::write_to_pbmsg(::proto_ff::E_MonsterValue & msg) const {
	msg.set_m_id((int64_t)m_ID);
	msg.set_m_type((int32_t)m_type);
	msg.set_m_monsterlv((int32_t)m_monsterLV);
	msg.set_m_max_hp((int64_t)m_max_Hp);
	msg.set_m_atk((int64_t)m_atk);
	msg.set_m_def((int64_t)m_def);
	msg.set_m_brk_armor((int64_t)m_brk_Armor);
	msg.set_m_five_dam((int64_t)m_five_Dam);
	msg.set_m_five_armor((int64_t)m_five_Armor);
	msg.set_m_thump_rate((int64_t)m_thump_Rate);
	msg.set_m_thump_resist((int64_t)m_thump_Resist);
	msg.set_m_sky((int64_t)m_sky);
	msg.set_m_sky_dam((int64_t)m_sky_Dam);
	msg.set_m_sky_redu_resist((int64_t)m_sky_Redu_Resist);
	msg.set_m_sky_resist((int64_t)m_sky_Resist);
	msg.set_m_kill_god((int64_t)m_kill_God);
	msg.set_m_god_body((int64_t)m_god_Body);
	msg.set_m_mortal_rate((int64_t)m_mortal_Rate);
	msg.set_m_mortal_resist((int64_t)m_mortal_Resist);
	msg.set_m_fairy_rate((int64_t)m_fairy_Rate);
	msg.set_m_fairy_resist((int64_t)m_fairy_Resist);
	msg.set_m_god_rate((int64_t)m_god_Rate);
	msg.set_m_god_resist((int64_t)m_god_Resist);
	msg.set_m_crit_rate((int64_t)m_crit_Rate);
	msg.set_m_crit_resit_rate((int64_t)m_crit_resit_Rate);
	msg.set_m_crit_dam((int64_t)m_crit_Dam);
	msg.set_m_crit_redu((int64_t)m_crit_Redu);
	msg.set_m_batter_rate((int64_t)m_batter_Rate);
	msg.set_m_batter_resist((int64_t)m_batter_Resist);
	msg.set_m_batter_dam((int64_t)m_batter_Dam);
	msg.set_m_batter_redu((int64_t)m_batter_Redu);
	msg.set_m_brkdown_rate((int64_t)m_brkdown_Rate);
	msg.set_m_brkdown_resist((int64_t)m_brkdown_Resist);
	msg.set_m_dam_add((int64_t)m_dam_Add);
	msg.set_m_dam_redu((int64_t)m_dam_Redu);
	msg.set_m_all_add((int64_t)m_all_Add);
	msg.set_m_all_redu((int64_t)m_all_Redu);
	msg.set_m_skill_add((int64_t)m_skill_Add);
	msg.set_m_skill_redu((int64_t)m_skill_Redu);
	msg.set_m_rebound_dam((int64_t)m_rebound_Dam);
	msg.set_m_hp_steal((int64_t)m_hp_Steal);
	msg.set_m_dodge_rate((int64_t)m_dodge_Rate);
	msg.set_m_hit_rate((int64_t)m_hit_Rate);
	msg.set_m_blk_rate((int64_t)m_blk_Rate);
	msg.set_m_brk_blk_rate((int64_t)m_brk_blk_Rate);
	msg.set_m_blk_free((int64_t)m_blk_Free);
	msg.set_m_blk_pierce((int64_t)m_blk_Pierce);
	msg.set_m_rel_armor((int64_t)m_rel_Armor);
	msg.set_m_rel_dam((int64_t)m_rel_Dam);
	msg.set_m_five_resist((int64_t)m_five_Resist);
	msg.set_m_five_resist_redu((int64_t)m_five_resist_Redu);
	msg.set_m_fire_add((int64_t)m_fire_Add);
	msg.set_m_fire_redu((int64_t)m_fire_Redu);
	msg.set_m_ice_add((int64_t)m_ice_Add);
	msg.set_m_ice_redu((int64_t)m_ice_Redu);
	msg.set_m_thunder_add((int64_t)m_thunder_Add);
	msg.set_m_thunder_rdu((int64_t)m_thunder_Rdu);
	msg.set_m_player_add((int64_t)m_player_Add);
	msg.set_m_player_redu((int64_t)m_player_Redu);
	msg.set_m_leader_add((int64_t)m_leader_Add);
	msg.set_m_leader_redu((int64_t)m_leader_Redu);
	msg.set_m_mon_add((int64_t)m_mon_Add);
	msg.set_m_mon_redu((int64_t)m_mon_Redu);
	msg.set_m_var_redu((int64_t)m_var_Redu);
	msg.set_m_var_add((int64_t)m_var_Add);
	msg.set_m_unusual_resist((int64_t)m_unusual_Resist);
	msg.set_m_unusual_hit((int64_t)m_unusual_Hit);
	msg.set_m_hp_recover((int64_t)m_hp_Recover);
	msg.set_m_unusual_add((int64_t)m_unusual_Add);
	msg.set_m_fix_recover((int64_t)m_fix_Recover);
	msg.set_m_high_hp_add((int64_t)m_high_hp_Add);
	msg.set_m_recover_hp_add((int64_t)m_recover_hp_Add);
	msg.set_m_week_add((int64_t)m_week_Add);
	msg.set_m_shield((int64_t)m_shield);
	msg.set_m_exp((int64_t)m_exp);
}

void E_MonsterValue_s::read_from_pbmsg(const ::proto_ff::E_MonsterValue & msg) {
	m_ID = msg.m_id();
	m_type = msg.m_type();
	m_monsterLV = msg.m_monsterlv();
	m_max_Hp = msg.m_max_hp();
	m_atk = msg.m_atk();
	m_def = msg.m_def();
	m_brk_Armor = msg.m_brk_armor();
	m_five_Dam = msg.m_five_dam();
	m_five_Armor = msg.m_five_armor();
	m_thump_Rate = msg.m_thump_rate();
	m_thump_Resist = msg.m_thump_resist();
	m_sky = msg.m_sky();
	m_sky_Dam = msg.m_sky_dam();
	m_sky_Redu_Resist = msg.m_sky_redu_resist();
	m_sky_Resist = msg.m_sky_resist();
	m_kill_God = msg.m_kill_god();
	m_god_Body = msg.m_god_body();
	m_mortal_Rate = msg.m_mortal_rate();
	m_mortal_Resist = msg.m_mortal_resist();
	m_fairy_Rate = msg.m_fairy_rate();
	m_fairy_Resist = msg.m_fairy_resist();
	m_god_Rate = msg.m_god_rate();
	m_god_Resist = msg.m_god_resist();
	m_crit_Rate = msg.m_crit_rate();
	m_crit_resit_Rate = msg.m_crit_resit_rate();
	m_crit_Dam = msg.m_crit_dam();
	m_crit_Redu = msg.m_crit_redu();
	m_batter_Rate = msg.m_batter_rate();
	m_batter_Resist = msg.m_batter_resist();
	m_batter_Dam = msg.m_batter_dam();
	m_batter_Redu = msg.m_batter_redu();
	m_brkdown_Rate = msg.m_brkdown_rate();
	m_brkdown_Resist = msg.m_brkdown_resist();
	m_dam_Add = msg.m_dam_add();
	m_dam_Redu = msg.m_dam_redu();
	m_all_Add = msg.m_all_add();
	m_all_Redu = msg.m_all_redu();
	m_skill_Add = msg.m_skill_add();
	m_skill_Redu = msg.m_skill_redu();
	m_rebound_Dam = msg.m_rebound_dam();
	m_hp_Steal = msg.m_hp_steal();
	m_dodge_Rate = msg.m_dodge_rate();
	m_hit_Rate = msg.m_hit_rate();
	m_blk_Rate = msg.m_blk_rate();
	m_brk_blk_Rate = msg.m_brk_blk_rate();
	m_blk_Free = msg.m_blk_free();
	m_blk_Pierce = msg.m_blk_pierce();
	m_rel_Armor = msg.m_rel_armor();
	m_rel_Dam = msg.m_rel_dam();
	m_five_Resist = msg.m_five_resist();
	m_five_resist_Redu = msg.m_five_resist_redu();
	m_fire_Add = msg.m_fire_add();
	m_fire_Redu = msg.m_fire_redu();
	m_ice_Add = msg.m_ice_add();
	m_ice_Redu = msg.m_ice_redu();
	m_thunder_Add = msg.m_thunder_add();
	m_thunder_Rdu = msg.m_thunder_rdu();
	m_player_Add = msg.m_player_add();
	m_player_Redu = msg.m_player_redu();
	m_leader_Add = msg.m_leader_add();
	m_leader_Redu = msg.m_leader_redu();
	m_mon_Add = msg.m_mon_add();
	m_mon_Redu = msg.m_mon_redu();
	m_var_Redu = msg.m_var_redu();
	m_var_Add = msg.m_var_add();
	m_unusual_Resist = msg.m_unusual_resist();
	m_unusual_Hit = msg.m_unusual_hit();
	m_hp_Recover = msg.m_hp_recover();
	m_unusual_Add = msg.m_unusual_add();
	m_fix_Recover = msg.m_fix_recover();
	m_high_hp_Add = msg.m_high_hp_add();
	m_recover_hp_Add = msg.m_recover_hp_add();
	m_week_Add = msg.m_week_add();
	m_shield = msg.m_shield();
	m_exp = msg.m_exp();
}

Sheet_MonsterValue_s::Sheet_MonsterValue_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_MonsterValue_s::CreateInit() {
	return 0;
}

int Sheet_MonsterValue_s::ResumeInit() {
	return 0;
}

void Sheet_MonsterValue_s::write_to_pbmsg(::proto_ff::Sheet_MonsterValue & msg) const {
	for(int32_t i = 0; i < (int32_t)E_MonsterValue_List.size(); ++i) {
		::proto_ff::E_MonsterValue* temp_e_monstervalue_list = msg.add_e_monstervalue_list();
		E_MonsterValue_List[i].write_to_pbmsg(*temp_e_monstervalue_list);
	}
}

void Sheet_MonsterValue_s::read_from_pbmsg(const ::proto_ff::Sheet_MonsterValue & msg) {
	E_MonsterValue_List.resize((int)msg.e_monstervalue_list_size() > (int)E_MonsterValue_List.max_size() ? E_MonsterValue_List.max_size() : msg.e_monstervalue_list_size());
	for(int32_t i = 0; i < (int32_t)E_MonsterValue_List.size(); ++i) {
		const ::proto_ff::E_MonsterValue & temp_e_monstervalue_list = msg.e_monstervalue_list(i);
		E_MonsterValue_List[i].read_from_pbmsg(temp_e_monstervalue_list);
	}
}

E_MonsterValueparam_s::E_MonsterValueparam_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_MonsterValueparam_s::CreateInit() {
	m_id = (int32_t)0;
	m_P_max_Hp = (int32_t)0;
	m_P_atk = (int32_t)0;
	m_P_def = (int32_t)0;
	m_P_brk_Armor = (int32_t)0;
	m_P_five_Dam = (int32_t)0;
	m_P_five_Armor = (int32_t)0;
	m_P_thump_Rate = (int32_t)0;
	m_P_thump_Resist = (int32_t)0;
	m_P_sky = (int32_t)0;
	m_P_sky_Dam = (int32_t)0;
	m_P_sky_Redu_Resist = (int32_t)0;
	m_P_sky_Resist = (int32_t)0;
	m_P_kill_God = (int32_t)0;
	m_P_god_Body = (int32_t)0;
	m_P_mortal_Rate = (int32_t)0;
	m_P_mortal_Resist = (int32_t)0;
	m_P_fairy_Rate = (int32_t)0;
	m_P_fairy_Resist = (int32_t)0;
	m_P_god_Rate = (int32_t)0;
	m_P_god_Resist = (int32_t)0;
	m_P_crit_Rate = (int32_t)0;
	m_P_crit_resit_Rate = (int32_t)0;
	m_P_crit_Dam = (int32_t)0;
	m_P_crit_Redu = (int32_t)0;
	m_P_batter_Rate = (int32_t)0;
	m_P_batter_Resist = (int32_t)0;
	m_P_batter_Dam = (int32_t)0;
	m_P_batter_Redu = (int32_t)0;
	m_P_brkdown_Rate = (int32_t)0;
	m_P_brkdown_Resist = (int32_t)0;
	m_P_dam_Add = (int32_t)0;
	m_P_dam_Redu = (int32_t)0;
	m_P_all_Add = (int32_t)0;
	m_P_all_Redu = (int32_t)0;
	m_P_skill_Add = (int32_t)0;
	m_P_skill_Redu = (int32_t)0;
	m_P_rebound_Dam = (int32_t)0;
	m_P_hp_Steal = (int32_t)0;
	m_P_dodge_Rate = (int32_t)0;
	m_P_hit_Rate = (int32_t)0;
	m_P_blk_Rate = (int32_t)0;
	m_P_brk_blk_Rate = (int32_t)0;
	m_P_blk_Free = (int32_t)0;
	m_P_blk_Pierce = (int32_t)0;
	m_P_rel_Armor = (int32_t)0;
	m_P_rel_Dam = (int32_t)0;
	m_P_five_Resist = (int32_t)0;
	m_P_five_resist_Redu = (int32_t)0;
	m_P_fire_Add = (int32_t)0;
	m_P_fire_Redu = (int32_t)0;
	m_P_ice_Add = (int32_t)0;
	m_P_ice_Redu = (int32_t)0;
	m_P_thunder_Add = (int32_t)0;
	m_P_thunder_Rdu = (int32_t)0;
	m_P_player_Add = (int32_t)0;
	m_P_player_Redu = (int32_t)0;
	m_P_leader_Add = (int32_t)0;
	m_P_leader_Redu = (int32_t)0;
	m_P_mon_Add = (int32_t)0;
	m_P_mon_Redu = (int32_t)0;
	m_P_var_Redu = (int32_t)0;
	m_P_var_Add = (int32_t)0;
	m_P_unusual_Resist = (int32_t)0;
	m_P_unusual_Hit = (int32_t)0;
	m_P_hp_Recover = (int32_t)0;
	m_P_unusual_Add = (int32_t)0;
	m_P_fix_Recover = (int32_t)0;
	m_P_high_hp_Add = (int32_t)0;
	m_P_recover_hp_Add = (int32_t)0;
	m_P_week_Add = (int32_t)0;
	m_shield = (int64_t)0;
	m_exp = (int64_t)0;
	return 0;
}

int E_MonsterValueparam_s::ResumeInit() {
	return 0;
}

void E_MonsterValueparam_s::write_to_pbmsg(::proto_ff::E_MonsterValueparam & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_p_max_hp((int32_t)m_P_max_Hp);
	msg.set_m_p_atk((int32_t)m_P_atk);
	msg.set_m_p_def((int32_t)m_P_def);
	msg.set_m_p_brk_armor((int32_t)m_P_brk_Armor);
	msg.set_m_p_five_dam((int32_t)m_P_five_Dam);
	msg.set_m_p_five_armor((int32_t)m_P_five_Armor);
	msg.set_m_p_thump_rate((int32_t)m_P_thump_Rate);
	msg.set_m_p_thump_resist((int32_t)m_P_thump_Resist);
	msg.set_m_p_sky((int32_t)m_P_sky);
	msg.set_m_p_sky_dam((int32_t)m_P_sky_Dam);
	msg.set_m_p_sky_redu_resist((int32_t)m_P_sky_Redu_Resist);
	msg.set_m_p_sky_resist((int32_t)m_P_sky_Resist);
	msg.set_m_p_kill_god((int32_t)m_P_kill_God);
	msg.set_m_p_god_body((int32_t)m_P_god_Body);
	msg.set_m_p_mortal_rate((int32_t)m_P_mortal_Rate);
	msg.set_m_p_mortal_resist((int32_t)m_P_mortal_Resist);
	msg.set_m_p_fairy_rate((int32_t)m_P_fairy_Rate);
	msg.set_m_p_fairy_resist((int32_t)m_P_fairy_Resist);
	msg.set_m_p_god_rate((int32_t)m_P_god_Rate);
	msg.set_m_p_god_resist((int32_t)m_P_god_Resist);
	msg.set_m_p_crit_rate((int32_t)m_P_crit_Rate);
	msg.set_m_p_crit_resit_rate((int32_t)m_P_crit_resit_Rate);
	msg.set_m_p_crit_dam((int32_t)m_P_crit_Dam);
	msg.set_m_p_crit_redu((int32_t)m_P_crit_Redu);
	msg.set_m_p_batter_rate((int32_t)m_P_batter_Rate);
	msg.set_m_p_batter_resist((int32_t)m_P_batter_Resist);
	msg.set_m_p_batter_dam((int32_t)m_P_batter_Dam);
	msg.set_m_p_batter_redu((int32_t)m_P_batter_Redu);
	msg.set_m_p_brkdown_rate((int32_t)m_P_brkdown_Rate);
	msg.set_m_p_brkdown_resist((int32_t)m_P_brkdown_Resist);
	msg.set_m_p_dam_add((int32_t)m_P_dam_Add);
	msg.set_m_p_dam_redu((int32_t)m_P_dam_Redu);
	msg.set_m_p_all_add((int32_t)m_P_all_Add);
	msg.set_m_p_all_redu((int32_t)m_P_all_Redu);
	msg.set_m_p_skill_add((int32_t)m_P_skill_Add);
	msg.set_m_p_skill_redu((int32_t)m_P_skill_Redu);
	msg.set_m_p_rebound_dam((int32_t)m_P_rebound_Dam);
	msg.set_m_p_hp_steal((int32_t)m_P_hp_Steal);
	msg.set_m_p_dodge_rate((int32_t)m_P_dodge_Rate);
	msg.set_m_p_hit_rate((int32_t)m_P_hit_Rate);
	msg.set_m_p_blk_rate((int32_t)m_P_blk_Rate);
	msg.set_m_p_brk_blk_rate((int32_t)m_P_brk_blk_Rate);
	msg.set_m_p_blk_free((int32_t)m_P_blk_Free);
	msg.set_m_p_blk_pierce((int32_t)m_P_blk_Pierce);
	msg.set_m_p_rel_armor((int32_t)m_P_rel_Armor);
	msg.set_m_p_rel_dam((int32_t)m_P_rel_Dam);
	msg.set_m_p_five_resist((int32_t)m_P_five_Resist);
	msg.set_m_p_five_resist_redu((int32_t)m_P_five_resist_Redu);
	msg.set_m_p_fire_add((int32_t)m_P_fire_Add);
	msg.set_m_p_fire_redu((int32_t)m_P_fire_Redu);
	msg.set_m_p_ice_add((int32_t)m_P_ice_Add);
	msg.set_m_p_ice_redu((int32_t)m_P_ice_Redu);
	msg.set_m_p_thunder_add((int32_t)m_P_thunder_Add);
	msg.set_m_p_thunder_rdu((int32_t)m_P_thunder_Rdu);
	msg.set_m_p_player_add((int32_t)m_P_player_Add);
	msg.set_m_p_player_redu((int32_t)m_P_player_Redu);
	msg.set_m_p_leader_add((int32_t)m_P_leader_Add);
	msg.set_m_p_leader_redu((int32_t)m_P_leader_Redu);
	msg.set_m_p_mon_add((int32_t)m_P_mon_Add);
	msg.set_m_p_mon_redu((int32_t)m_P_mon_Redu);
	msg.set_m_p_var_redu((int32_t)m_P_var_Redu);
	msg.set_m_p_var_add((int32_t)m_P_var_Add);
	msg.set_m_p_unusual_resist((int32_t)m_P_unusual_Resist);
	msg.set_m_p_unusual_hit((int32_t)m_P_unusual_Hit);
	msg.set_m_p_hp_recover((int32_t)m_P_hp_Recover);
	msg.set_m_p_unusual_add((int32_t)m_P_unusual_Add);
	msg.set_m_p_fix_recover((int32_t)m_P_fix_Recover);
	msg.set_m_p_high_hp_add((int32_t)m_P_high_hp_Add);
	msg.set_m_p_recover_hp_add((int32_t)m_P_recover_hp_Add);
	msg.set_m_p_week_add((int32_t)m_P_week_Add);
	msg.set_m_shield((int64_t)m_shield);
	msg.set_m_exp((int64_t)m_exp);
}

void E_MonsterValueparam_s::read_from_pbmsg(const ::proto_ff::E_MonsterValueparam & msg) {
	m_id = msg.m_id();
	m_P_max_Hp = msg.m_p_max_hp();
	m_P_atk = msg.m_p_atk();
	m_P_def = msg.m_p_def();
	m_P_brk_Armor = msg.m_p_brk_armor();
	m_P_five_Dam = msg.m_p_five_dam();
	m_P_five_Armor = msg.m_p_five_armor();
	m_P_thump_Rate = msg.m_p_thump_rate();
	m_P_thump_Resist = msg.m_p_thump_resist();
	m_P_sky = msg.m_p_sky();
	m_P_sky_Dam = msg.m_p_sky_dam();
	m_P_sky_Redu_Resist = msg.m_p_sky_redu_resist();
	m_P_sky_Resist = msg.m_p_sky_resist();
	m_P_kill_God = msg.m_p_kill_god();
	m_P_god_Body = msg.m_p_god_body();
	m_P_mortal_Rate = msg.m_p_mortal_rate();
	m_P_mortal_Resist = msg.m_p_mortal_resist();
	m_P_fairy_Rate = msg.m_p_fairy_rate();
	m_P_fairy_Resist = msg.m_p_fairy_resist();
	m_P_god_Rate = msg.m_p_god_rate();
	m_P_god_Resist = msg.m_p_god_resist();
	m_P_crit_Rate = msg.m_p_crit_rate();
	m_P_crit_resit_Rate = msg.m_p_crit_resit_rate();
	m_P_crit_Dam = msg.m_p_crit_dam();
	m_P_crit_Redu = msg.m_p_crit_redu();
	m_P_batter_Rate = msg.m_p_batter_rate();
	m_P_batter_Resist = msg.m_p_batter_resist();
	m_P_batter_Dam = msg.m_p_batter_dam();
	m_P_batter_Redu = msg.m_p_batter_redu();
	m_P_brkdown_Rate = msg.m_p_brkdown_rate();
	m_P_brkdown_Resist = msg.m_p_brkdown_resist();
	m_P_dam_Add = msg.m_p_dam_add();
	m_P_dam_Redu = msg.m_p_dam_redu();
	m_P_all_Add = msg.m_p_all_add();
	m_P_all_Redu = msg.m_p_all_redu();
	m_P_skill_Add = msg.m_p_skill_add();
	m_P_skill_Redu = msg.m_p_skill_redu();
	m_P_rebound_Dam = msg.m_p_rebound_dam();
	m_P_hp_Steal = msg.m_p_hp_steal();
	m_P_dodge_Rate = msg.m_p_dodge_rate();
	m_P_hit_Rate = msg.m_p_hit_rate();
	m_P_blk_Rate = msg.m_p_blk_rate();
	m_P_brk_blk_Rate = msg.m_p_brk_blk_rate();
	m_P_blk_Free = msg.m_p_blk_free();
	m_P_blk_Pierce = msg.m_p_blk_pierce();
	m_P_rel_Armor = msg.m_p_rel_armor();
	m_P_rel_Dam = msg.m_p_rel_dam();
	m_P_five_Resist = msg.m_p_five_resist();
	m_P_five_resist_Redu = msg.m_p_five_resist_redu();
	m_P_fire_Add = msg.m_p_fire_add();
	m_P_fire_Redu = msg.m_p_fire_redu();
	m_P_ice_Add = msg.m_p_ice_add();
	m_P_ice_Redu = msg.m_p_ice_redu();
	m_P_thunder_Add = msg.m_p_thunder_add();
	m_P_thunder_Rdu = msg.m_p_thunder_rdu();
	m_P_player_Add = msg.m_p_player_add();
	m_P_player_Redu = msg.m_p_player_redu();
	m_P_leader_Add = msg.m_p_leader_add();
	m_P_leader_Redu = msg.m_p_leader_redu();
	m_P_mon_Add = msg.m_p_mon_add();
	m_P_mon_Redu = msg.m_p_mon_redu();
	m_P_var_Redu = msg.m_p_var_redu();
	m_P_var_Add = msg.m_p_var_add();
	m_P_unusual_Resist = msg.m_p_unusual_resist();
	m_P_unusual_Hit = msg.m_p_unusual_hit();
	m_P_hp_Recover = msg.m_p_hp_recover();
	m_P_unusual_Add = msg.m_p_unusual_add();
	m_P_fix_Recover = msg.m_p_fix_recover();
	m_P_high_hp_Add = msg.m_p_high_hp_add();
	m_P_recover_hp_Add = msg.m_p_recover_hp_add();
	m_P_week_Add = msg.m_p_week_add();
	m_shield = msg.m_shield();
	m_exp = msg.m_exp();
}

Sheet_MonsterValueparam_s::Sheet_MonsterValueparam_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_MonsterValueparam_s::CreateInit() {
	return 0;
}

int Sheet_MonsterValueparam_s::ResumeInit() {
	return 0;
}

void Sheet_MonsterValueparam_s::write_to_pbmsg(::proto_ff::Sheet_MonsterValueparam & msg) const {
	for(int32_t i = 0; i < (int32_t)E_MonsterValueparam_List.size(); ++i) {
		::proto_ff::E_MonsterValueparam* temp_e_monstervalueparam_list = msg.add_e_monstervalueparam_list();
		E_MonsterValueparam_List[i].write_to_pbmsg(*temp_e_monstervalueparam_list);
	}
}

void Sheet_MonsterValueparam_s::read_from_pbmsg(const ::proto_ff::Sheet_MonsterValueparam & msg) {
	E_MonsterValueparam_List.resize((int)msg.e_monstervalueparam_list_size() > (int)E_MonsterValueparam_List.max_size() ? E_MonsterValueparam_List.max_size() : msg.e_monstervalueparam_list_size());
	for(int32_t i = 0; i < (int32_t)E_MonsterValueparam_List.size(); ++i) {
		const ::proto_ff::E_MonsterValueparam & temp_e_monstervalueparam_list = msg.e_monstervalueparam_list(i);
		E_MonsterValueparam_List[i].read_from_pbmsg(temp_e_monstervalueparam_list);
	}
}

E_MonsterDrop_s::E_MonsterDrop_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_MonsterDrop_s::CreateInit() {
	m_id = (int32_t)0;
	m_group = (int32_t)0;
	m_own = (int32_t)0;
	m_ownProtect = (int32_t)0;
	m_type = (int32_t)0;
	return 0;
}

int E_MonsterDrop_s::ResumeInit() {
	return 0;
}

void E_MonsterDrop_s::write_to_pbmsg(::proto_ff::E_MonsterDrop & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_group((int32_t)m_group);
	msg.set_m_own((int32_t)m_own);
	msg.set_m_ownprotect((int32_t)m_ownProtect);
	msg.set_m_type((int32_t)m_type);
	for(int32_t i = 0; i < (int32_t)m_boxID.size(); ++i) {
		msg.add_m_boxid((int64_t)m_boxID[i]);
	}
}

void E_MonsterDrop_s::read_from_pbmsg(const ::proto_ff::E_MonsterDrop & msg) {
	m_id = msg.m_id();
	m_group = msg.m_group();
	m_own = msg.m_own();
	m_ownProtect = msg.m_ownprotect();
	m_type = msg.m_type();
	m_boxID.resize((int)msg.m_boxid_size() > (int)m_boxID.max_size() ? m_boxID.max_size() : msg.m_boxid_size());
	for(int32_t i = 0; i < (int32_t)m_boxID.size(); ++i) {
		m_boxID[i] = msg.m_boxid(i);
	}
}

Sheet_MonsterDrop_s::Sheet_MonsterDrop_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_MonsterDrop_s::CreateInit() {
	return 0;
}

int Sheet_MonsterDrop_s::ResumeInit() {
	return 0;
}

void Sheet_MonsterDrop_s::write_to_pbmsg(::proto_ff::Sheet_MonsterDrop & msg) const {
	for(int32_t i = 0; i < (int32_t)E_MonsterDrop_List.size(); ++i) {
		::proto_ff::E_MonsterDrop* temp_e_monsterdrop_list = msg.add_e_monsterdrop_list();
		E_MonsterDrop_List[i].write_to_pbmsg(*temp_e_monsterdrop_list);
	}
}

void Sheet_MonsterDrop_s::read_from_pbmsg(const ::proto_ff::Sheet_MonsterDrop & msg) {
	E_MonsterDrop_List.resize((int)msg.e_monsterdrop_list_size() > (int)E_MonsterDrop_List.max_size() ? E_MonsterDrop_List.max_size() : msg.e_monsterdrop_list_size());
	for(int32_t i = 0; i < (int32_t)E_MonsterDrop_List.size(); ++i) {
		const ::proto_ff::E_MonsterDrop & temp_e_monsterdrop_list = msg.e_monsterdrop_list(i);
		E_MonsterDrop_List[i].read_from_pbmsg(temp_e_monsterdrop_list);
	}
}

E_MonsterCollect_s::E_MonsterCollect_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_MonsterCollect_s::CreateInit() {
	m_ID = (int32_t)0;
	m_type = (int32_t)0;
	m_num = (int32_t)0;
	m_breakDown = (int32_t)0;
	m_dropGroupID = (int32_t)0;
	m_time = (int32_t)0;
	m_getType = (int32_t)0;
	m_skillTime = (int32_t)0;
	m_skillID = (int32_t)0;
	m_dupID = (int32_t)0;
	m_monsteID = (int32_t)0;
	return 0;
}

int E_MonsterCollect_s::ResumeInit() {
	return 0;
}

void E_MonsterCollect_s::write_to_pbmsg(::proto_ff::E_MonsterCollect & msg) const {
	msg.set_m_id((int32_t)m_ID);
	msg.set_m_type((int32_t)m_type);
	msg.set_m_num((int32_t)m_num);
	msg.set_m_breakdown((int32_t)m_breakDown);
	msg.set_m_dropgroupid((int32_t)m_dropGroupID);
	msg.set_m_time((int32_t)m_time);
	msg.set_m_gettype((int32_t)m_getType);
	msg.set_m_skilltime((int32_t)m_skillTime);
	msg.set_m_skillid((int32_t)m_skillID);
	msg.set_m_dupid((int32_t)m_dupID);
	msg.set_m_monsteid((int32_t)m_monsteID);
}

void E_MonsterCollect_s::read_from_pbmsg(const ::proto_ff::E_MonsterCollect & msg) {
	m_ID = msg.m_id();
	m_type = msg.m_type();
	m_num = msg.m_num();
	m_breakDown = msg.m_breakdown();
	m_dropGroupID = msg.m_dropgroupid();
	m_time = msg.m_time();
	m_getType = msg.m_gettype();
	m_skillTime = msg.m_skilltime();
	m_skillID = msg.m_skillid();
	m_dupID = msg.m_dupid();
	m_monsteID = msg.m_monsteid();
}

Sheet_MonsterCollect_s::Sheet_MonsterCollect_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_MonsterCollect_s::CreateInit() {
	return 0;
}

int Sheet_MonsterCollect_s::ResumeInit() {
	return 0;
}

void Sheet_MonsterCollect_s::write_to_pbmsg(::proto_ff::Sheet_MonsterCollect & msg) const {
	for(int32_t i = 0; i < (int32_t)E_MonsterCollect_List.size(); ++i) {
		::proto_ff::E_MonsterCollect* temp_e_monstercollect_list = msg.add_e_monstercollect_list();
		E_MonsterCollect_List[i].write_to_pbmsg(*temp_e_monstercollect_list);
	}
}

void Sheet_MonsterCollect_s::read_from_pbmsg(const ::proto_ff::Sheet_MonsterCollect & msg) {
	E_MonsterCollect_List.resize((int)msg.e_monstercollect_list_size() > (int)E_MonsterCollect_List.max_size() ? E_MonsterCollect_List.max_size() : msg.e_monstercollect_list_size());
	for(int32_t i = 0; i < (int32_t)E_MonsterCollect_List.size(); ++i) {
		const ::proto_ff::E_MonsterCollect & temp_e_monstercollect_list = msg.e_monstercollect_list(i);
		E_MonsterCollect_List[i].read_from_pbmsg(temp_e_monstercollect_list);
	}
}

}
