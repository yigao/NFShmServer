#include "monster_s.h"

namespace proto_ff_s {

E_MonsterMonster_s::E_MonsterMonster_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_MonsterMonster_s::CreateInit() {
	m_monsterid = (int64_t)0;
	m_functiontype = (int32_t)0;
	m_functionvalue = (int64_t)0;
	m_profession = (int32_t)0;
	m_damageaddtype = (int32_t)0;
	m_monsterlv = (int32_t)0;
	m_droplimit = (int32_t)0;
	m_displayid = (int64_t)0;
	m_valuetype = (int64_t)0;
	m_valueparam = (int32_t)0;
	m_aiid = (int64_t)0;
	m_hpsectionnum = (int32_t)0;
	m_breedprob = (int32_t)0;
	m_breedmonid = (int64_t)0;
	m_breedmonlive = (int32_t)0;
	m_isbornactionon = (int32_t)0;
	m_belongshow = (int32_t)0;
	m_dropgroupid = (int32_t)0;
	m_harmdrop_type = (int32_t)0;
	m_joninper = (int32_t)0;
	m_btnrange = (int32_t)0;
	m_btnid = (int64_t)0;
	m_drivepoint = (int32_t)0;
	m_corpseid = (int32_t)0;
	return 0;
}

int E_MonsterMonster_s::ResumeInit() {
	return 0;
}

void E_MonsterMonster_s::write_to_pbmsg(::proto_ff::E_MonsterMonster & msg) const {
	msg.set_m_monsterid((int64_t)m_monsterid);
	msg.set_m_monstername((const char*)m_monstername.data());
	msg.set_m_functiontype((int32_t)m_functiontype);
	msg.set_m_functionvalue((int64_t)m_functionvalue);
	msg.set_m_profession((int32_t)m_profession);
	msg.set_m_damageaddtype((int32_t)m_damageaddtype);
	msg.set_m_monsterlv((int32_t)m_monsterlv);
	msg.set_m_droplimit((int32_t)m_droplimit);
	msg.set_m_displayid((int64_t)m_displayid);
	msg.set_m_valuetype((int64_t)m_valuetype);
	msg.set_m_valueparam((int32_t)m_valueparam);
	msg.set_m_aiid((int64_t)m_aiid);
	msg.set_m_hpsectionnum((int32_t)m_hpsectionnum);
	msg.set_m_breedprob((int32_t)m_breedprob);
	msg.set_m_breedmonid((int64_t)m_breedmonid);
	msg.set_m_breedmonlive((int32_t)m_breedmonlive);
	msg.set_m_itemcost((const char*)m_itemcost.data());
	msg.set_m_isbornactionon((int32_t)m_isbornactionon);
	msg.set_m_belongshow((int32_t)m_belongshow);
	msg.set_m_dropgroupid((int32_t)m_dropgroupid);
	msg.set_m_harmdrop_type((int32_t)m_harmdrop_type);
	msg.set_m_joninper((int32_t)m_joninper);
	msg.set_m_btnrange((int32_t)m_btnrange);
	msg.set_m_btnid((int64_t)m_btnid);
	msg.set_m_drivepoint((int32_t)m_drivepoint);
	msg.set_m_corpseid((int32_t)m_corpseid);
}

void E_MonsterMonster_s::read_from_pbmsg(const ::proto_ff::E_MonsterMonster & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct E_MonsterMonster_s));
	m_monsterid = msg.m_monsterid();
	m_monstername = msg.m_monstername();
	m_functiontype = msg.m_functiontype();
	m_functionvalue = msg.m_functionvalue();
	m_profession = msg.m_profession();
	m_damageaddtype = msg.m_damageaddtype();
	m_monsterlv = msg.m_monsterlv();
	m_droplimit = msg.m_droplimit();
	m_displayid = msg.m_displayid();
	m_valuetype = msg.m_valuetype();
	m_valueparam = msg.m_valueparam();
	m_aiid = msg.m_aiid();
	m_hpsectionnum = msg.m_hpsectionnum();
	m_breedprob = msg.m_breedprob();
	m_breedmonid = msg.m_breedmonid();
	m_breedmonlive = msg.m_breedmonlive();
	m_itemcost = msg.m_itemcost();
	m_isbornactionon = msg.m_isbornactionon();
	m_belongshow = msg.m_belongshow();
	m_dropgroupid = msg.m_dropgroupid();
	m_harmdrop_type = msg.m_harmdrop_type();
	m_joninper = msg.m_joninper();
	m_btnrange = msg.m_btnrange();
	m_btnid = msg.m_btnid();
	m_drivepoint = msg.m_drivepoint();
	m_corpseid = msg.m_corpseid();
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
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_MonsterMonster_s));
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
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct E_MonsterDisplaySkillDesc_s));
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
	m_displayid = (int64_t)0;
	m_modeloffsetsx = (int32_t)0;
	m_modeloffsetsy = (int32_t)0;
	m_modelscale = (int32_t)0;
	m_modelradius = (int32_t)0;
	m_pathradius = (int32_t)0;
	m_collisionradius = (int32_t)0;
	m_rspeed = (int32_t)0;
	return 0;
}

int E_MonsterDisplay_s::ResumeInit() {
	return 0;
}

void E_MonsterDisplay_s::write_to_pbmsg(::proto_ff::E_MonsterDisplay & msg) const {
	msg.set_m_displayid((int64_t)m_displayid);
	msg.set_m_modeloffsetsx((int32_t)m_modeloffsetsx);
	msg.set_m_modeloffsetsy((int32_t)m_modeloffsetsy);
	msg.set_m_modelscale((int32_t)m_modelscale);
	msg.set_m_modelradius((int32_t)m_modelradius);
	msg.set_m_pathradius((int32_t)m_pathradius);
	msg.set_m_collisionradius((int32_t)m_collisionradius);
	msg.set_m_rspeed((int32_t)m_rspeed);
	for(int32_t i = 0; i < (int32_t)m_skill.size(); ++i) {
		::proto_ff::E_MonsterDisplaySkillDesc* temp_m_skill = msg.add_m_skill();
		m_skill[i].write_to_pbmsg(*temp_m_skill);
	}
}

void E_MonsterDisplay_s::read_from_pbmsg(const ::proto_ff::E_MonsterDisplay & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct E_MonsterDisplay_s));
	m_displayid = msg.m_displayid();
	m_modeloffsetsx = msg.m_modeloffsetsx();
	m_modeloffsetsy = msg.m_modeloffsetsy();
	m_modelscale = msg.m_modelscale();
	m_modelradius = msg.m_modelradius();
	m_pathradius = msg.m_pathradius();
	m_collisionradius = msg.m_collisionradius();
	m_rspeed = msg.m_rspeed();
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
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_MonsterDisplay_s));
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
	m_id = (int64_t)0;
	m_type = (int32_t)0;
	m_monsterlv = (int32_t)0;
	m_max_hp = (int64_t)0;
	m_atk = (int64_t)0;
	m_def = (int64_t)0;
	m_brk_armor = (int64_t)0;
	m_five_dam = (int64_t)0;
	m_five_armor = (int64_t)0;
	m_thump_rate = (int64_t)0;
	m_thump_resist = (int64_t)0;
	m_sky = (int64_t)0;
	m_sky_dam = (int64_t)0;
	m_sky_redu_resist = (int64_t)0;
	m_sky_resist = (int64_t)0;
	m_kill_god = (int64_t)0;
	m_god_body = (int64_t)0;
	m_mortal_rate = (int64_t)0;
	m_mortal_resist = (int64_t)0;
	m_fairy_rate = (int64_t)0;
	m_fairy_resist = (int64_t)0;
	m_god_rate = (int64_t)0;
	m_god_resist = (int64_t)0;
	m_crit_rate = (int64_t)0;
	m_crit_resit_rate = (int64_t)0;
	m_crit_dam = (int64_t)0;
	m_crit_redu = (int64_t)0;
	m_batter_rate = (int64_t)0;
	m_batter_resist = (int64_t)0;
	m_batter_dam = (int64_t)0;
	m_batter_redu = (int64_t)0;
	m_brkdown_rate = (int64_t)0;
	m_brkdown_resist = (int64_t)0;
	m_dam_add = (int64_t)0;
	m_dam_redu = (int64_t)0;
	m_all_add = (int64_t)0;
	m_all_redu = (int64_t)0;
	m_skill_add = (int64_t)0;
	m_skill_redu = (int64_t)0;
	m_rebound_dam = (int64_t)0;
	m_hp_steal = (int64_t)0;
	m_dodge_rate = (int64_t)0;
	m_hit_rate = (int64_t)0;
	m_blk_rate = (int64_t)0;
	m_brk_blk_rate = (int64_t)0;
	m_blk_free = (int64_t)0;
	m_blk_pierce = (int64_t)0;
	m_rel_armor = (int64_t)0;
	m_rel_dam = (int64_t)0;
	m_five_resist = (int64_t)0;
	m_five_resist_redu = (int64_t)0;
	m_fire_add = (int64_t)0;
	m_fire_redu = (int64_t)0;
	m_ice_add = (int64_t)0;
	m_ice_redu = (int64_t)0;
	m_thunder_add = (int64_t)0;
	m_thunder_rdu = (int64_t)0;
	m_player_add = (int64_t)0;
	m_player_redu = (int64_t)0;
	m_leader_add = (int64_t)0;
	m_leader_redu = (int64_t)0;
	m_mon_add = (int64_t)0;
	m_mon_redu = (int64_t)0;
	m_var_redu = (int64_t)0;
	m_var_add = (int64_t)0;
	m_unusual_resist = (int64_t)0;
	m_unusual_hit = (int64_t)0;
	m_hp_recover = (int64_t)0;
	m_unusual_add = (int64_t)0;
	m_fix_recover = (int64_t)0;
	m_high_hp_add = (int64_t)0;
	m_recover_hp_add = (int64_t)0;
	m_week_add = (int64_t)0;
	m_shield = (int64_t)0;
	m_exp = (int64_t)0;
	return 0;
}

int E_MonsterValue_s::ResumeInit() {
	return 0;
}

void E_MonsterValue_s::write_to_pbmsg(::proto_ff::E_MonsterValue & msg) const {
	msg.set_m_id((int64_t)m_id);
	msg.set_m_type((int32_t)m_type);
	msg.set_m_monsterlv((int32_t)m_monsterlv);
	msg.set_m_max_hp((int64_t)m_max_hp);
	msg.set_m_atk((int64_t)m_atk);
	msg.set_m_def((int64_t)m_def);
	msg.set_m_brk_armor((int64_t)m_brk_armor);
	msg.set_m_five_dam((int64_t)m_five_dam);
	msg.set_m_five_armor((int64_t)m_five_armor);
	msg.set_m_thump_rate((int64_t)m_thump_rate);
	msg.set_m_thump_resist((int64_t)m_thump_resist);
	msg.set_m_sky((int64_t)m_sky);
	msg.set_m_sky_dam((int64_t)m_sky_dam);
	msg.set_m_sky_redu_resist((int64_t)m_sky_redu_resist);
	msg.set_m_sky_resist((int64_t)m_sky_resist);
	msg.set_m_kill_god((int64_t)m_kill_god);
	msg.set_m_god_body((int64_t)m_god_body);
	msg.set_m_mortal_rate((int64_t)m_mortal_rate);
	msg.set_m_mortal_resist((int64_t)m_mortal_resist);
	msg.set_m_fairy_rate((int64_t)m_fairy_rate);
	msg.set_m_fairy_resist((int64_t)m_fairy_resist);
	msg.set_m_god_rate((int64_t)m_god_rate);
	msg.set_m_god_resist((int64_t)m_god_resist);
	msg.set_m_crit_rate((int64_t)m_crit_rate);
	msg.set_m_crit_resit_rate((int64_t)m_crit_resit_rate);
	msg.set_m_crit_dam((int64_t)m_crit_dam);
	msg.set_m_crit_redu((int64_t)m_crit_redu);
	msg.set_m_batter_rate((int64_t)m_batter_rate);
	msg.set_m_batter_resist((int64_t)m_batter_resist);
	msg.set_m_batter_dam((int64_t)m_batter_dam);
	msg.set_m_batter_redu((int64_t)m_batter_redu);
	msg.set_m_brkdown_rate((int64_t)m_brkdown_rate);
	msg.set_m_brkdown_resist((int64_t)m_brkdown_resist);
	msg.set_m_dam_add((int64_t)m_dam_add);
	msg.set_m_dam_redu((int64_t)m_dam_redu);
	msg.set_m_all_add((int64_t)m_all_add);
	msg.set_m_all_redu((int64_t)m_all_redu);
	msg.set_m_skill_add((int64_t)m_skill_add);
	msg.set_m_skill_redu((int64_t)m_skill_redu);
	msg.set_m_rebound_dam((int64_t)m_rebound_dam);
	msg.set_m_hp_steal((int64_t)m_hp_steal);
	msg.set_m_dodge_rate((int64_t)m_dodge_rate);
	msg.set_m_hit_rate((int64_t)m_hit_rate);
	msg.set_m_blk_rate((int64_t)m_blk_rate);
	msg.set_m_brk_blk_rate((int64_t)m_brk_blk_rate);
	msg.set_m_blk_free((int64_t)m_blk_free);
	msg.set_m_blk_pierce((int64_t)m_blk_pierce);
	msg.set_m_rel_armor((int64_t)m_rel_armor);
	msg.set_m_rel_dam((int64_t)m_rel_dam);
	msg.set_m_five_resist((int64_t)m_five_resist);
	msg.set_m_five_resist_redu((int64_t)m_five_resist_redu);
	msg.set_m_fire_add((int64_t)m_fire_add);
	msg.set_m_fire_redu((int64_t)m_fire_redu);
	msg.set_m_ice_add((int64_t)m_ice_add);
	msg.set_m_ice_redu((int64_t)m_ice_redu);
	msg.set_m_thunder_add((int64_t)m_thunder_add);
	msg.set_m_thunder_rdu((int64_t)m_thunder_rdu);
	msg.set_m_player_add((int64_t)m_player_add);
	msg.set_m_player_redu((int64_t)m_player_redu);
	msg.set_m_leader_add((int64_t)m_leader_add);
	msg.set_m_leader_redu((int64_t)m_leader_redu);
	msg.set_m_mon_add((int64_t)m_mon_add);
	msg.set_m_mon_redu((int64_t)m_mon_redu);
	msg.set_m_var_redu((int64_t)m_var_redu);
	msg.set_m_var_add((int64_t)m_var_add);
	msg.set_m_unusual_resist((int64_t)m_unusual_resist);
	msg.set_m_unusual_hit((int64_t)m_unusual_hit);
	msg.set_m_hp_recover((int64_t)m_hp_recover);
	msg.set_m_unusual_add((int64_t)m_unusual_add);
	msg.set_m_fix_recover((int64_t)m_fix_recover);
	msg.set_m_high_hp_add((int64_t)m_high_hp_add);
	msg.set_m_recover_hp_add((int64_t)m_recover_hp_add);
	msg.set_m_week_add((int64_t)m_week_add);
	msg.set_m_shield((int64_t)m_shield);
	msg.set_m_exp((int64_t)m_exp);
}

void E_MonsterValue_s::read_from_pbmsg(const ::proto_ff::E_MonsterValue & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct E_MonsterValue_s));
	m_id = msg.m_id();
	m_type = msg.m_type();
	m_monsterlv = msg.m_monsterlv();
	m_max_hp = msg.m_max_hp();
	m_atk = msg.m_atk();
	m_def = msg.m_def();
	m_brk_armor = msg.m_brk_armor();
	m_five_dam = msg.m_five_dam();
	m_five_armor = msg.m_five_armor();
	m_thump_rate = msg.m_thump_rate();
	m_thump_resist = msg.m_thump_resist();
	m_sky = msg.m_sky();
	m_sky_dam = msg.m_sky_dam();
	m_sky_redu_resist = msg.m_sky_redu_resist();
	m_sky_resist = msg.m_sky_resist();
	m_kill_god = msg.m_kill_god();
	m_god_body = msg.m_god_body();
	m_mortal_rate = msg.m_mortal_rate();
	m_mortal_resist = msg.m_mortal_resist();
	m_fairy_rate = msg.m_fairy_rate();
	m_fairy_resist = msg.m_fairy_resist();
	m_god_rate = msg.m_god_rate();
	m_god_resist = msg.m_god_resist();
	m_crit_rate = msg.m_crit_rate();
	m_crit_resit_rate = msg.m_crit_resit_rate();
	m_crit_dam = msg.m_crit_dam();
	m_crit_redu = msg.m_crit_redu();
	m_batter_rate = msg.m_batter_rate();
	m_batter_resist = msg.m_batter_resist();
	m_batter_dam = msg.m_batter_dam();
	m_batter_redu = msg.m_batter_redu();
	m_brkdown_rate = msg.m_brkdown_rate();
	m_brkdown_resist = msg.m_brkdown_resist();
	m_dam_add = msg.m_dam_add();
	m_dam_redu = msg.m_dam_redu();
	m_all_add = msg.m_all_add();
	m_all_redu = msg.m_all_redu();
	m_skill_add = msg.m_skill_add();
	m_skill_redu = msg.m_skill_redu();
	m_rebound_dam = msg.m_rebound_dam();
	m_hp_steal = msg.m_hp_steal();
	m_dodge_rate = msg.m_dodge_rate();
	m_hit_rate = msg.m_hit_rate();
	m_blk_rate = msg.m_blk_rate();
	m_brk_blk_rate = msg.m_brk_blk_rate();
	m_blk_free = msg.m_blk_free();
	m_blk_pierce = msg.m_blk_pierce();
	m_rel_armor = msg.m_rel_armor();
	m_rel_dam = msg.m_rel_dam();
	m_five_resist = msg.m_five_resist();
	m_five_resist_redu = msg.m_five_resist_redu();
	m_fire_add = msg.m_fire_add();
	m_fire_redu = msg.m_fire_redu();
	m_ice_add = msg.m_ice_add();
	m_ice_redu = msg.m_ice_redu();
	m_thunder_add = msg.m_thunder_add();
	m_thunder_rdu = msg.m_thunder_rdu();
	m_player_add = msg.m_player_add();
	m_player_redu = msg.m_player_redu();
	m_leader_add = msg.m_leader_add();
	m_leader_redu = msg.m_leader_redu();
	m_mon_add = msg.m_mon_add();
	m_mon_redu = msg.m_mon_redu();
	m_var_redu = msg.m_var_redu();
	m_var_add = msg.m_var_add();
	m_unusual_resist = msg.m_unusual_resist();
	m_unusual_hit = msg.m_unusual_hit();
	m_hp_recover = msg.m_hp_recover();
	m_unusual_add = msg.m_unusual_add();
	m_fix_recover = msg.m_fix_recover();
	m_high_hp_add = msg.m_high_hp_add();
	m_recover_hp_add = msg.m_recover_hp_add();
	m_week_add = msg.m_week_add();
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
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_MonsterValue_s));
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
	m_p_max_hp = (int32_t)0;
	m_p_atk = (int32_t)0;
	m_p_def = (int32_t)0;
	m_p_brk_armor = (int32_t)0;
	m_p_five_dam = (int32_t)0;
	m_p_five_armor = (int32_t)0;
	m_p_thump_rate = (int32_t)0;
	m_p_thump_resist = (int32_t)0;
	m_p_sky = (int32_t)0;
	m_p_sky_dam = (int32_t)0;
	m_p_sky_redu_resist = (int32_t)0;
	m_p_sky_resist = (int32_t)0;
	m_p_kill_god = (int32_t)0;
	m_p_god_body = (int32_t)0;
	m_p_mortal_rate = (int32_t)0;
	m_p_mortal_resist = (int32_t)0;
	m_p_fairy_rate = (int32_t)0;
	m_p_fairy_resist = (int32_t)0;
	m_p_god_rate = (int32_t)0;
	m_p_god_resist = (int32_t)0;
	m_p_crit_rate = (int32_t)0;
	m_p_crit_resit_rate = (int32_t)0;
	m_p_crit_dam = (int32_t)0;
	m_p_crit_redu = (int32_t)0;
	m_p_batter_rate = (int32_t)0;
	m_p_batter_resist = (int32_t)0;
	m_p_batter_dam = (int32_t)0;
	m_p_batter_redu = (int32_t)0;
	m_p_brkdown_rate = (int32_t)0;
	m_p_brkdown_resist = (int32_t)0;
	m_p_dam_add = (int32_t)0;
	m_p_dam_redu = (int32_t)0;
	m_p_all_add = (int32_t)0;
	m_p_all_redu = (int32_t)0;
	m_p_skill_add = (int32_t)0;
	m_p_skill_redu = (int32_t)0;
	m_p_rebound_dam = (int32_t)0;
	m_p_hp_steal = (int32_t)0;
	m_p_dodge_rate = (int32_t)0;
	m_p_hit_rate = (int32_t)0;
	m_p_blk_rate = (int32_t)0;
	m_p_brk_blk_rate = (int32_t)0;
	m_p_blk_free = (int32_t)0;
	m_p_blk_pierce = (int32_t)0;
	m_p_rel_armor = (int32_t)0;
	m_p_rel_dam = (int32_t)0;
	m_p_five_resist = (int32_t)0;
	m_p_five_resist_redu = (int32_t)0;
	m_p_fire_add = (int32_t)0;
	m_p_fire_redu = (int32_t)0;
	m_p_ice_add = (int32_t)0;
	m_p_ice_redu = (int32_t)0;
	m_p_thunder_add = (int32_t)0;
	m_p_thunder_rdu = (int32_t)0;
	m_p_player_add = (int32_t)0;
	m_p_player_redu = (int32_t)0;
	m_p_leader_add = (int32_t)0;
	m_p_leader_redu = (int32_t)0;
	m_p_mon_add = (int32_t)0;
	m_p_mon_redu = (int32_t)0;
	m_p_var_redu = (int32_t)0;
	m_p_var_add = (int32_t)0;
	m_p_unusual_resist = (int32_t)0;
	m_p_unusual_hit = (int32_t)0;
	m_p_hp_recover = (int32_t)0;
	m_p_unusual_add = (int32_t)0;
	m_p_fix_recover = (int32_t)0;
	m_p_high_hp_add = (int32_t)0;
	m_p_recover_hp_add = (int32_t)0;
	m_p_week_add = (int32_t)0;
	m_shield = (int64_t)0;
	return 0;
}

int E_MonsterValueparam_s::ResumeInit() {
	return 0;
}

void E_MonsterValueparam_s::write_to_pbmsg(::proto_ff::E_MonsterValueparam & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_p_max_hp((int32_t)m_p_max_hp);
	msg.set_m_p_atk((int32_t)m_p_atk);
	msg.set_m_p_def((int32_t)m_p_def);
	msg.set_m_p_brk_armor((int32_t)m_p_brk_armor);
	msg.set_m_p_five_dam((int32_t)m_p_five_dam);
	msg.set_m_p_five_armor((int32_t)m_p_five_armor);
	msg.set_m_p_thump_rate((int32_t)m_p_thump_rate);
	msg.set_m_p_thump_resist((int32_t)m_p_thump_resist);
	msg.set_m_p_sky((int32_t)m_p_sky);
	msg.set_m_p_sky_dam((int32_t)m_p_sky_dam);
	msg.set_m_p_sky_redu_resist((int32_t)m_p_sky_redu_resist);
	msg.set_m_p_sky_resist((int32_t)m_p_sky_resist);
	msg.set_m_p_kill_god((int32_t)m_p_kill_god);
	msg.set_m_p_god_body((int32_t)m_p_god_body);
	msg.set_m_p_mortal_rate((int32_t)m_p_mortal_rate);
	msg.set_m_p_mortal_resist((int32_t)m_p_mortal_resist);
	msg.set_m_p_fairy_rate((int32_t)m_p_fairy_rate);
	msg.set_m_p_fairy_resist((int32_t)m_p_fairy_resist);
	msg.set_m_p_god_rate((int32_t)m_p_god_rate);
	msg.set_m_p_god_resist((int32_t)m_p_god_resist);
	msg.set_m_p_crit_rate((int32_t)m_p_crit_rate);
	msg.set_m_p_crit_resit_rate((int32_t)m_p_crit_resit_rate);
	msg.set_m_p_crit_dam((int32_t)m_p_crit_dam);
	msg.set_m_p_crit_redu((int32_t)m_p_crit_redu);
	msg.set_m_p_batter_rate((int32_t)m_p_batter_rate);
	msg.set_m_p_batter_resist((int32_t)m_p_batter_resist);
	msg.set_m_p_batter_dam((int32_t)m_p_batter_dam);
	msg.set_m_p_batter_redu((int32_t)m_p_batter_redu);
	msg.set_m_p_brkdown_rate((int32_t)m_p_brkdown_rate);
	msg.set_m_p_brkdown_resist((int32_t)m_p_brkdown_resist);
	msg.set_m_p_dam_add((int32_t)m_p_dam_add);
	msg.set_m_p_dam_redu((int32_t)m_p_dam_redu);
	msg.set_m_p_all_add((int32_t)m_p_all_add);
	msg.set_m_p_all_redu((int32_t)m_p_all_redu);
	msg.set_m_p_skill_add((int32_t)m_p_skill_add);
	msg.set_m_p_skill_redu((int32_t)m_p_skill_redu);
	msg.set_m_p_rebound_dam((int32_t)m_p_rebound_dam);
	msg.set_m_p_hp_steal((int32_t)m_p_hp_steal);
	msg.set_m_p_dodge_rate((int32_t)m_p_dodge_rate);
	msg.set_m_p_hit_rate((int32_t)m_p_hit_rate);
	msg.set_m_p_blk_rate((int32_t)m_p_blk_rate);
	msg.set_m_p_brk_blk_rate((int32_t)m_p_brk_blk_rate);
	msg.set_m_p_blk_free((int32_t)m_p_blk_free);
	msg.set_m_p_blk_pierce((int32_t)m_p_blk_pierce);
	msg.set_m_p_rel_armor((int32_t)m_p_rel_armor);
	msg.set_m_p_rel_dam((int32_t)m_p_rel_dam);
	msg.set_m_p_five_resist((int32_t)m_p_five_resist);
	msg.set_m_p_five_resist_redu((int32_t)m_p_five_resist_redu);
	msg.set_m_p_fire_add((int32_t)m_p_fire_add);
	msg.set_m_p_fire_redu((int32_t)m_p_fire_redu);
	msg.set_m_p_ice_add((int32_t)m_p_ice_add);
	msg.set_m_p_ice_redu((int32_t)m_p_ice_redu);
	msg.set_m_p_thunder_add((int32_t)m_p_thunder_add);
	msg.set_m_p_thunder_rdu((int32_t)m_p_thunder_rdu);
	msg.set_m_p_player_add((int32_t)m_p_player_add);
	msg.set_m_p_player_redu((int32_t)m_p_player_redu);
	msg.set_m_p_leader_add((int32_t)m_p_leader_add);
	msg.set_m_p_leader_redu((int32_t)m_p_leader_redu);
	msg.set_m_p_mon_add((int32_t)m_p_mon_add);
	msg.set_m_p_mon_redu((int32_t)m_p_mon_redu);
	msg.set_m_p_var_redu((int32_t)m_p_var_redu);
	msg.set_m_p_var_add((int32_t)m_p_var_add);
	msg.set_m_p_unusual_resist((int32_t)m_p_unusual_resist);
	msg.set_m_p_unusual_hit((int32_t)m_p_unusual_hit);
	msg.set_m_p_hp_recover((int32_t)m_p_hp_recover);
	msg.set_m_p_unusual_add((int32_t)m_p_unusual_add);
	msg.set_m_p_fix_recover((int32_t)m_p_fix_recover);
	msg.set_m_p_high_hp_add((int32_t)m_p_high_hp_add);
	msg.set_m_p_recover_hp_add((int32_t)m_p_recover_hp_add);
	msg.set_m_p_week_add((int32_t)m_p_week_add);
	msg.set_m_shield((int64_t)m_shield);
}

void E_MonsterValueparam_s::read_from_pbmsg(const ::proto_ff::E_MonsterValueparam & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct E_MonsterValueparam_s));
	m_id = msg.m_id();
	m_p_max_hp = msg.m_p_max_hp();
	m_p_atk = msg.m_p_atk();
	m_p_def = msg.m_p_def();
	m_p_brk_armor = msg.m_p_brk_armor();
	m_p_five_dam = msg.m_p_five_dam();
	m_p_five_armor = msg.m_p_five_armor();
	m_p_thump_rate = msg.m_p_thump_rate();
	m_p_thump_resist = msg.m_p_thump_resist();
	m_p_sky = msg.m_p_sky();
	m_p_sky_dam = msg.m_p_sky_dam();
	m_p_sky_redu_resist = msg.m_p_sky_redu_resist();
	m_p_sky_resist = msg.m_p_sky_resist();
	m_p_kill_god = msg.m_p_kill_god();
	m_p_god_body = msg.m_p_god_body();
	m_p_mortal_rate = msg.m_p_mortal_rate();
	m_p_mortal_resist = msg.m_p_mortal_resist();
	m_p_fairy_rate = msg.m_p_fairy_rate();
	m_p_fairy_resist = msg.m_p_fairy_resist();
	m_p_god_rate = msg.m_p_god_rate();
	m_p_god_resist = msg.m_p_god_resist();
	m_p_crit_rate = msg.m_p_crit_rate();
	m_p_crit_resit_rate = msg.m_p_crit_resit_rate();
	m_p_crit_dam = msg.m_p_crit_dam();
	m_p_crit_redu = msg.m_p_crit_redu();
	m_p_batter_rate = msg.m_p_batter_rate();
	m_p_batter_resist = msg.m_p_batter_resist();
	m_p_batter_dam = msg.m_p_batter_dam();
	m_p_batter_redu = msg.m_p_batter_redu();
	m_p_brkdown_rate = msg.m_p_brkdown_rate();
	m_p_brkdown_resist = msg.m_p_brkdown_resist();
	m_p_dam_add = msg.m_p_dam_add();
	m_p_dam_redu = msg.m_p_dam_redu();
	m_p_all_add = msg.m_p_all_add();
	m_p_all_redu = msg.m_p_all_redu();
	m_p_skill_add = msg.m_p_skill_add();
	m_p_skill_redu = msg.m_p_skill_redu();
	m_p_rebound_dam = msg.m_p_rebound_dam();
	m_p_hp_steal = msg.m_p_hp_steal();
	m_p_dodge_rate = msg.m_p_dodge_rate();
	m_p_hit_rate = msg.m_p_hit_rate();
	m_p_blk_rate = msg.m_p_blk_rate();
	m_p_brk_blk_rate = msg.m_p_brk_blk_rate();
	m_p_blk_free = msg.m_p_blk_free();
	m_p_blk_pierce = msg.m_p_blk_pierce();
	m_p_rel_armor = msg.m_p_rel_armor();
	m_p_rel_dam = msg.m_p_rel_dam();
	m_p_five_resist = msg.m_p_five_resist();
	m_p_five_resist_redu = msg.m_p_five_resist_redu();
	m_p_fire_add = msg.m_p_fire_add();
	m_p_fire_redu = msg.m_p_fire_redu();
	m_p_ice_add = msg.m_p_ice_add();
	m_p_ice_redu = msg.m_p_ice_redu();
	m_p_thunder_add = msg.m_p_thunder_add();
	m_p_thunder_rdu = msg.m_p_thunder_rdu();
	m_p_player_add = msg.m_p_player_add();
	m_p_player_redu = msg.m_p_player_redu();
	m_p_leader_add = msg.m_p_leader_add();
	m_p_leader_redu = msg.m_p_leader_redu();
	m_p_mon_add = msg.m_p_mon_add();
	m_p_mon_redu = msg.m_p_mon_redu();
	m_p_var_redu = msg.m_p_var_redu();
	m_p_var_add = msg.m_p_var_add();
	m_p_unusual_resist = msg.m_p_unusual_resist();
	m_p_unusual_hit = msg.m_p_unusual_hit();
	m_p_hp_recover = msg.m_p_hp_recover();
	m_p_unusual_add = msg.m_p_unusual_add();
	m_p_fix_recover = msg.m_p_fix_recover();
	m_p_high_hp_add = msg.m_p_high_hp_add();
	m_p_recover_hp_add = msg.m_p_recover_hp_add();
	m_p_week_add = msg.m_p_week_add();
	m_shield = msg.m_shield();
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
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_MonsterValueparam_s));
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
	msg.set_m_type((int32_t)m_type);
	for(int32_t i = 0; i < (int32_t)m_boxid.size(); ++i) {
		msg.add_m_boxid((int64_t)m_boxid[i]);
	}
}

void E_MonsterDrop_s::read_from_pbmsg(const ::proto_ff::E_MonsterDrop & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct E_MonsterDrop_s));
	m_id = msg.m_id();
	m_group = msg.m_group();
	m_own = msg.m_own();
	m_type = msg.m_type();
	m_boxid.resize((int)msg.m_boxid_size() > (int)m_boxid.max_size() ? m_boxid.max_size() : msg.m_boxid_size());
	for(int32_t i = 0; i < (int32_t)m_boxid.size(); ++i) {
		m_boxid[i] = msg.m_boxid(i);
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
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_MonsterDrop_s));
	E_MonsterDrop_List.resize((int)msg.e_monsterdrop_list_size() > (int)E_MonsterDrop_List.max_size() ? E_MonsterDrop_List.max_size() : msg.e_monsterdrop_list_size());
	for(int32_t i = 0; i < (int32_t)E_MonsterDrop_List.size(); ++i) {
		const ::proto_ff::E_MonsterDrop & temp_e_monsterdrop_list = msg.e_monsterdrop_list(i);
		E_MonsterDrop_List[i].read_from_pbmsg(temp_e_monsterdrop_list);
	}
}

}