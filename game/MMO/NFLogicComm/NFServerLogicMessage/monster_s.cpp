#include "monster_s.h"

namespace proto_ff_s {

monstermonster_s::monstermonster_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int monstermonster_s::CreateInit() {
	monsterID = (int64_t)0;
	functionType = (int32_t)0;
	functionValue = (int64_t)0;
	profession = (int32_t)0;
	damageAddType = (int32_t)0;
	monsterLV = (int32_t)0;
	droplimit = (int32_t)0;
	displayID = (int64_t)0;
	valuetype = (int64_t)0;
	valueParam = (int32_t)0;
	aiId = (int64_t)0;
	hpSectionNum = (int32_t)0;
	breedProb = (int32_t)0;
	breedMonID = (int64_t)0;
	breedMonLive = (int32_t)0;
	isBornActionOn = (int32_t)0;
	belongshow = (int32_t)0;
	dropGroupID = (int32_t)0;
	harmdrop_type = (int32_t)0;
	joninper = (int32_t)0;
	btnRange = (int32_t)0;
	btnId = (int64_t)0;
	drivePoint = (int32_t)0;
	corpseID = (int32_t)0;
	return 0;
}

int monstermonster_s::ResumeInit() {
	return 0;
}

void monstermonster_s::write_to_pbmsg(::proto_ff::monstermonster & msg) const {
	msg.set_monsterid((int64_t)monsterID);
	msg.set_monstername((const char*)monsterName.Get());
	msg.set_functiontype((int32_t)functionType);
	msg.set_functionvalue((int64_t)functionValue);
	msg.set_profession((int32_t)profession);
	msg.set_damageaddtype((int32_t)damageAddType);
	msg.set_monsterlv((int32_t)monsterLV);
	msg.set_droplimit((int32_t)droplimit);
	msg.set_displayid((int64_t)displayID);
	msg.set_valuetype((int64_t)valuetype);
	msg.set_valueparam((int32_t)valueParam);
	msg.set_aiid((int64_t)aiId);
	msg.set_hpsectionnum((int32_t)hpSectionNum);
	msg.set_breedprob((int32_t)breedProb);
	msg.set_breedmonid((int64_t)breedMonID);
	msg.set_breedmonlive((int32_t)breedMonLive);
	msg.set_itemcost((const char*)itemCost.Get());
	msg.set_isbornactionon((int32_t)isBornActionOn);
	msg.set_belongshow((int32_t)belongshow);
	msg.set_dropgroupid((int32_t)dropGroupID);
	msg.set_harmdrop_type((int32_t)harmdrop_type);
	msg.set_joninper((int32_t)joninper);
	msg.set_btnrange((int32_t)btnRange);
	msg.set_btnid((int64_t)btnId);
	msg.set_drivepoint((int32_t)drivePoint);
	msg.set_corpseid((int32_t)corpseID);
}

void monstermonster_s::read_from_pbmsg(const ::proto_ff::monstermonster & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct monstermonster_s));
	monsterID = msg.monsterid();
	monsterName.Copy(msg.monstername());
	functionType = msg.functiontype();
	functionValue = msg.functionvalue();
	profession = msg.profession();
	damageAddType = msg.damageaddtype();
	monsterLV = msg.monsterlv();
	droplimit = msg.droplimit();
	displayID = msg.displayid();
	valuetype = msg.valuetype();
	valueParam = msg.valueparam();
	aiId = msg.aiid();
	hpSectionNum = msg.hpsectionnum();
	breedProb = msg.breedprob();
	breedMonID = msg.breedmonid();
	breedMonLive = msg.breedmonlive();
	itemCost.Copy(msg.itemcost());
	isBornActionOn = msg.isbornactionon();
	belongshow = msg.belongshow();
	dropGroupID = msg.dropgroupid();
	harmdrop_type = msg.harmdrop_type();
	joninper = msg.joninper();
	btnRange = msg.btnrange();
	btnId = msg.btnid();
	drivePoint = msg.drivepoint();
	corpseID = msg.corpseid();
}

Sheet_monstermonster_s::Sheet_monstermonster_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_monstermonster_s::CreateInit() {
	return 0;
}

int Sheet_monstermonster_s::ResumeInit() {
	return 0;
}

void Sheet_monstermonster_s::write_to_pbmsg(::proto_ff::Sheet_monstermonster & msg) const {
	for(int32_t i = 0; i < (int32_t)monstermonster_List.GetSize() && i < monstermonster_List.GetMaxSize(); ++i) {
		::proto_ff::monstermonster* temp_monstermonster_list = msg.add_monstermonster_list();
		monstermonster_List[i].write_to_pbmsg(*temp_monstermonster_list);
	}
}

void Sheet_monstermonster_s::read_from_pbmsg(const ::proto_ff::Sheet_monstermonster & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_monstermonster_s));
	monstermonster_List.SetSize(msg.monstermonster_list_size() > monstermonster_List.GetMaxSize() ? monstermonster_List.GetMaxSize() : msg.monstermonster_list_size());
	for(int32_t i = 0; i < (int32_t)monstermonster_List.GetSize(); ++i) {
		const ::proto_ff::monstermonster & temp_monstermonster_list = msg.monstermonster_list(i);
		monstermonster_List[i].read_from_pbmsg(temp_monstermonster_list);
	}
}

monsterdisplayskillDesc_s::monsterdisplayskillDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int monsterdisplayskillDesc_s::CreateInit() {
	id = (int64_t)0;
	return 0;
}

int monsterdisplayskillDesc_s::ResumeInit() {
	return 0;
}

void monsterdisplayskillDesc_s::write_to_pbmsg(::proto_ff::monsterdisplayskillDesc & msg) const {
	msg.set_id((int64_t)id);
}

void monsterdisplayskillDesc_s::read_from_pbmsg(const ::proto_ff::monsterdisplayskillDesc & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct monsterdisplayskillDesc_s));
	id = msg.id();
}

monsterdisplay_s::monsterdisplay_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int monsterdisplay_s::CreateInit() {
	displayID = (int64_t)0;
	modelOffsetsX = (int32_t)0;
	modelOffsetsY = (int32_t)0;
	modelScale = (int32_t)0;
	modelRadius = (int32_t)0;
	pathRadius = (int32_t)0;
	collisionRadius = (int32_t)0;
	rSpeed = (int32_t)0;
	return 0;
}

int monsterdisplay_s::ResumeInit() {
	return 0;
}

void monsterdisplay_s::write_to_pbmsg(::proto_ff::monsterdisplay & msg) const {
	msg.set_displayid((int64_t)displayID);
	msg.set_modeloffsetsx((int32_t)modelOffsetsX);
	msg.set_modeloffsetsy((int32_t)modelOffsetsY);
	msg.set_modelscale((int32_t)modelScale);
	msg.set_modelradius((int32_t)modelRadius);
	msg.set_pathradius((int32_t)pathRadius);
	msg.set_collisionradius((int32_t)collisionRadius);
	msg.set_rspeed((int32_t)rSpeed);
	for(int32_t i = 0; i < (int32_t)skill.GetSize() && i < skill.GetMaxSize(); ++i) {
		::proto_ff::monsterdisplayskillDesc* temp_skill = msg.add_skill();
		skill[i].write_to_pbmsg(*temp_skill);
	}
}

void monsterdisplay_s::read_from_pbmsg(const ::proto_ff::monsterdisplay & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct monsterdisplay_s));
	displayID = msg.displayid();
	modelOffsetsX = msg.modeloffsetsx();
	modelOffsetsY = msg.modeloffsetsy();
	modelScale = msg.modelscale();
	modelRadius = msg.modelradius();
	pathRadius = msg.pathradius();
	collisionRadius = msg.collisionradius();
	rSpeed = msg.rspeed();
	skill.SetSize(msg.skill_size() > skill.GetMaxSize() ? skill.GetMaxSize() : msg.skill_size());
	for(int32_t i = 0; i < (int32_t)skill.GetSize(); ++i) {
		const ::proto_ff::monsterdisplayskillDesc & temp_skill = msg.skill(i);
		skill[i].read_from_pbmsg(temp_skill);
	}
}

Sheet_monsterdisplay_s::Sheet_monsterdisplay_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_monsterdisplay_s::CreateInit() {
	return 0;
}

int Sheet_monsterdisplay_s::ResumeInit() {
	return 0;
}

void Sheet_monsterdisplay_s::write_to_pbmsg(::proto_ff::Sheet_monsterdisplay & msg) const {
	for(int32_t i = 0; i < (int32_t)monsterdisplay_List.GetSize() && i < monsterdisplay_List.GetMaxSize(); ++i) {
		::proto_ff::monsterdisplay* temp_monsterdisplay_list = msg.add_monsterdisplay_list();
		monsterdisplay_List[i].write_to_pbmsg(*temp_monsterdisplay_list);
	}
}

void Sheet_monsterdisplay_s::read_from_pbmsg(const ::proto_ff::Sheet_monsterdisplay & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_monsterdisplay_s));
	monsterdisplay_List.SetSize(msg.monsterdisplay_list_size() > monsterdisplay_List.GetMaxSize() ? monsterdisplay_List.GetMaxSize() : msg.monsterdisplay_list_size());
	for(int32_t i = 0; i < (int32_t)monsterdisplay_List.GetSize(); ++i) {
		const ::proto_ff::monsterdisplay & temp_monsterdisplay_list = msg.monsterdisplay_list(i);
		monsterdisplay_List[i].read_from_pbmsg(temp_monsterdisplay_list);
	}
}

monstervalue_s::monstervalue_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int monstervalue_s::CreateInit() {
	ID = (int64_t)0;
	type = (int32_t)0;
	monsterLV = (int32_t)0;
	max_Hp = (int64_t)0;
	atk = (int64_t)0;
	def = (int64_t)0;
	brk_Armor = (int64_t)0;
	five_Dam = (int64_t)0;
	five_Armor = (int64_t)0;
	thump_Rate = (int64_t)0;
	thump_Resist = (int64_t)0;
	sky = (int64_t)0;
	sky_Dam = (int64_t)0;
	sky_Redu_Resist = (int64_t)0;
	sky_Resist = (int64_t)0;
	kill_God = (int64_t)0;
	god_Body = (int64_t)0;
	mortal_Rate = (int64_t)0;
	mortal_Resist = (int64_t)0;
	fairy_Rate = (int64_t)0;
	fairy_Resist = (int64_t)0;
	god_Rate = (int64_t)0;
	god_Resist = (int64_t)0;
	crit_Rate = (int64_t)0;
	crit_resit_Rate = (int64_t)0;
	crit_Dam = (int64_t)0;
	crit_Redu = (int64_t)0;
	batter_Rate = (int64_t)0;
	batter_Resist = (int64_t)0;
	batter_Dam = (int64_t)0;
	batter_Redu = (int64_t)0;
	brkdown_Rate = (int64_t)0;
	brkdown_Resist = (int64_t)0;
	dam_Add = (int64_t)0;
	dam_Redu = (int64_t)0;
	all_Add = (int64_t)0;
	all_Redu = (int64_t)0;
	skill_Add = (int64_t)0;
	skill_Redu = (int64_t)0;
	rebound_Dam = (int64_t)0;
	hp_Steal = (int64_t)0;
	dodge_Rate = (int64_t)0;
	hit_Rate = (int64_t)0;
	blk_Rate = (int64_t)0;
	brk_blk_Rate = (int64_t)0;
	blk_Free = (int64_t)0;
	blk_Pierce = (int64_t)0;
	rel_Armor = (int64_t)0;
	rel_Dam = (int64_t)0;
	five_Resist = (int64_t)0;
	five_resist_Redu = (int64_t)0;
	fire_Add = (int64_t)0;
	fire_Redu = (int64_t)0;
	ice_Add = (int64_t)0;
	ice_Redu = (int64_t)0;
	thunder_Add = (int64_t)0;
	thunder_Rdu = (int64_t)0;
	player_Add = (int64_t)0;
	player_Redu = (int64_t)0;
	leader_Add = (int64_t)0;
	leader_Redu = (int64_t)0;
	mon_Add = (int64_t)0;
	mon_Redu = (int64_t)0;
	var_Redu = (int64_t)0;
	var_Add = (int64_t)0;
	unusual_Resist = (int64_t)0;
	unusual_Hit = (int64_t)0;
	hp_Recover = (int64_t)0;
	unusual_Add = (int64_t)0;
	fix_Recover = (int64_t)0;
	high_hp_Add = (int64_t)0;
	recover_hp_Add = (int64_t)0;
	week_Add = (int64_t)0;
	shield = (int64_t)0;
	return 0;
}

int monstervalue_s::ResumeInit() {
	return 0;
}

void monstervalue_s::write_to_pbmsg(::proto_ff::monstervalue & msg) const {
	msg.set_id((int64_t)ID);
	msg.set_type((int32_t)type);
	msg.set_monsterlv((int32_t)monsterLV);
	msg.set_max_hp((int64_t)max_Hp);
	msg.set_atk((int64_t)atk);
	msg.set_def((int64_t)def);
	msg.set_brk_armor((int64_t)brk_Armor);
	msg.set_five_dam((int64_t)five_Dam);
	msg.set_five_armor((int64_t)five_Armor);
	msg.set_thump_rate((int64_t)thump_Rate);
	msg.set_thump_resist((int64_t)thump_Resist);
	msg.set_sky((int64_t)sky);
	msg.set_sky_dam((int64_t)sky_Dam);
	msg.set_sky_redu_resist((int64_t)sky_Redu_Resist);
	msg.set_sky_resist((int64_t)sky_Resist);
	msg.set_kill_god((int64_t)kill_God);
	msg.set_god_body((int64_t)god_Body);
	msg.set_mortal_rate((int64_t)mortal_Rate);
	msg.set_mortal_resist((int64_t)mortal_Resist);
	msg.set_fairy_rate((int64_t)fairy_Rate);
	msg.set_fairy_resist((int64_t)fairy_Resist);
	msg.set_god_rate((int64_t)god_Rate);
	msg.set_god_resist((int64_t)god_Resist);
	msg.set_crit_rate((int64_t)crit_Rate);
	msg.set_crit_resit_rate((int64_t)crit_resit_Rate);
	msg.set_crit_dam((int64_t)crit_Dam);
	msg.set_crit_redu((int64_t)crit_Redu);
	msg.set_batter_rate((int64_t)batter_Rate);
	msg.set_batter_resist((int64_t)batter_Resist);
	msg.set_batter_dam((int64_t)batter_Dam);
	msg.set_batter_redu((int64_t)batter_Redu);
	msg.set_brkdown_rate((int64_t)brkdown_Rate);
	msg.set_brkdown_resist((int64_t)brkdown_Resist);
	msg.set_dam_add((int64_t)dam_Add);
	msg.set_dam_redu((int64_t)dam_Redu);
	msg.set_all_add((int64_t)all_Add);
	msg.set_all_redu((int64_t)all_Redu);
	msg.set_skill_add((int64_t)skill_Add);
	msg.set_skill_redu((int64_t)skill_Redu);
	msg.set_rebound_dam((int64_t)rebound_Dam);
	msg.set_hp_steal((int64_t)hp_Steal);
	msg.set_dodge_rate((int64_t)dodge_Rate);
	msg.set_hit_rate((int64_t)hit_Rate);
	msg.set_blk_rate((int64_t)blk_Rate);
	msg.set_brk_blk_rate((int64_t)brk_blk_Rate);
	msg.set_blk_free((int64_t)blk_Free);
	msg.set_blk_pierce((int64_t)blk_Pierce);
	msg.set_rel_armor((int64_t)rel_Armor);
	msg.set_rel_dam((int64_t)rel_Dam);
	msg.set_five_resist((int64_t)five_Resist);
	msg.set_five_resist_redu((int64_t)five_resist_Redu);
	msg.set_fire_add((int64_t)fire_Add);
	msg.set_fire_redu((int64_t)fire_Redu);
	msg.set_ice_add((int64_t)ice_Add);
	msg.set_ice_redu((int64_t)ice_Redu);
	msg.set_thunder_add((int64_t)thunder_Add);
	msg.set_thunder_rdu((int64_t)thunder_Rdu);
	msg.set_player_add((int64_t)player_Add);
	msg.set_player_redu((int64_t)player_Redu);
	msg.set_leader_add((int64_t)leader_Add);
	msg.set_leader_redu((int64_t)leader_Redu);
	msg.set_mon_add((int64_t)mon_Add);
	msg.set_mon_redu((int64_t)mon_Redu);
	msg.set_var_redu((int64_t)var_Redu);
	msg.set_var_add((int64_t)var_Add);
	msg.set_unusual_resist((int64_t)unusual_Resist);
	msg.set_unusual_hit((int64_t)unusual_Hit);
	msg.set_hp_recover((int64_t)hp_Recover);
	msg.set_unusual_add((int64_t)unusual_Add);
	msg.set_fix_recover((int64_t)fix_Recover);
	msg.set_high_hp_add((int64_t)high_hp_Add);
	msg.set_recover_hp_add((int64_t)recover_hp_Add);
	msg.set_week_add((int64_t)week_Add);
	msg.set_shield((int64_t)shield);
}

void monstervalue_s::read_from_pbmsg(const ::proto_ff::monstervalue & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct monstervalue_s));
	ID = msg.id();
	type = msg.type();
	monsterLV = msg.monsterlv();
	max_Hp = msg.max_hp();
	atk = msg.atk();
	def = msg.def();
	brk_Armor = msg.brk_armor();
	five_Dam = msg.five_dam();
	five_Armor = msg.five_armor();
	thump_Rate = msg.thump_rate();
	thump_Resist = msg.thump_resist();
	sky = msg.sky();
	sky_Dam = msg.sky_dam();
	sky_Redu_Resist = msg.sky_redu_resist();
	sky_Resist = msg.sky_resist();
	kill_God = msg.kill_god();
	god_Body = msg.god_body();
	mortal_Rate = msg.mortal_rate();
	mortal_Resist = msg.mortal_resist();
	fairy_Rate = msg.fairy_rate();
	fairy_Resist = msg.fairy_resist();
	god_Rate = msg.god_rate();
	god_Resist = msg.god_resist();
	crit_Rate = msg.crit_rate();
	crit_resit_Rate = msg.crit_resit_rate();
	crit_Dam = msg.crit_dam();
	crit_Redu = msg.crit_redu();
	batter_Rate = msg.batter_rate();
	batter_Resist = msg.batter_resist();
	batter_Dam = msg.batter_dam();
	batter_Redu = msg.batter_redu();
	brkdown_Rate = msg.brkdown_rate();
	brkdown_Resist = msg.brkdown_resist();
	dam_Add = msg.dam_add();
	dam_Redu = msg.dam_redu();
	all_Add = msg.all_add();
	all_Redu = msg.all_redu();
	skill_Add = msg.skill_add();
	skill_Redu = msg.skill_redu();
	rebound_Dam = msg.rebound_dam();
	hp_Steal = msg.hp_steal();
	dodge_Rate = msg.dodge_rate();
	hit_Rate = msg.hit_rate();
	blk_Rate = msg.blk_rate();
	brk_blk_Rate = msg.brk_blk_rate();
	blk_Free = msg.blk_free();
	blk_Pierce = msg.blk_pierce();
	rel_Armor = msg.rel_armor();
	rel_Dam = msg.rel_dam();
	five_Resist = msg.five_resist();
	five_resist_Redu = msg.five_resist_redu();
	fire_Add = msg.fire_add();
	fire_Redu = msg.fire_redu();
	ice_Add = msg.ice_add();
	ice_Redu = msg.ice_redu();
	thunder_Add = msg.thunder_add();
	thunder_Rdu = msg.thunder_rdu();
	player_Add = msg.player_add();
	player_Redu = msg.player_redu();
	leader_Add = msg.leader_add();
	leader_Redu = msg.leader_redu();
	mon_Add = msg.mon_add();
	mon_Redu = msg.mon_redu();
	var_Redu = msg.var_redu();
	var_Add = msg.var_add();
	unusual_Resist = msg.unusual_resist();
	unusual_Hit = msg.unusual_hit();
	hp_Recover = msg.hp_recover();
	unusual_Add = msg.unusual_add();
	fix_Recover = msg.fix_recover();
	high_hp_Add = msg.high_hp_add();
	recover_hp_Add = msg.recover_hp_add();
	week_Add = msg.week_add();
	shield = msg.shield();
}

Sheet_monstervalue_s::Sheet_monstervalue_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_monstervalue_s::CreateInit() {
	return 0;
}

int Sheet_monstervalue_s::ResumeInit() {
	return 0;
}

void Sheet_monstervalue_s::write_to_pbmsg(::proto_ff::Sheet_monstervalue & msg) const {
	for(int32_t i = 0; i < (int32_t)monstervalue_List.GetSize() && i < monstervalue_List.GetMaxSize(); ++i) {
		::proto_ff::monstervalue* temp_monstervalue_list = msg.add_monstervalue_list();
		monstervalue_List[i].write_to_pbmsg(*temp_monstervalue_list);
	}
}

void Sheet_monstervalue_s::read_from_pbmsg(const ::proto_ff::Sheet_monstervalue & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_monstervalue_s));
	monstervalue_List.SetSize(msg.monstervalue_list_size() > monstervalue_List.GetMaxSize() ? monstervalue_List.GetMaxSize() : msg.monstervalue_list_size());
	for(int32_t i = 0; i < (int32_t)monstervalue_List.GetSize(); ++i) {
		const ::proto_ff::monstervalue & temp_monstervalue_list = msg.monstervalue_list(i);
		monstervalue_List[i].read_from_pbmsg(temp_monstervalue_list);
	}
}

monstervalueParam_s::monstervalueParam_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int monstervalueParam_s::CreateInit() {
	id = (int32_t)0;
	P_max_Hp = (int32_t)0;
	P_atk = (int32_t)0;
	P_def = (int32_t)0;
	P_brk_Armor = (int32_t)0;
	P_five_Dam = (int32_t)0;
	P_five_Armor = (int32_t)0;
	P_thump_Rate = (int32_t)0;
	P_thump_Resist = (int32_t)0;
	P_sky = (int32_t)0;
	P_sky_Dam = (int32_t)0;
	P_sky_Redu_Resist = (int32_t)0;
	P_sky_Resist = (int32_t)0;
	P_kill_God = (int32_t)0;
	P_god_Body = (int32_t)0;
	P_mortal_Rate = (int32_t)0;
	P_mortal_Resist = (int32_t)0;
	P_fairy_Rate = (int32_t)0;
	P_fairy_Resist = (int32_t)0;
	P_god_Rate = (int32_t)0;
	P_god_Resist = (int32_t)0;
	P_crit_Rate = (int32_t)0;
	P_crit_resit_Rate = (int32_t)0;
	P_crit_Dam = (int32_t)0;
	P_crit_Redu = (int32_t)0;
	P_batter_Rate = (int32_t)0;
	P_batter_Resist = (int32_t)0;
	P_batter_Dam = (int32_t)0;
	P_batter_Redu = (int32_t)0;
	P_brkdown_Rate = (int32_t)0;
	P_brkdown_Resist = (int32_t)0;
	P_dam_Add = (int32_t)0;
	P_dam_Redu = (int32_t)0;
	P_all_Add = (int32_t)0;
	P_all_Redu = (int32_t)0;
	P_skill_Add = (int32_t)0;
	P_skill_Redu = (int32_t)0;
	P_rebound_Dam = (int32_t)0;
	P_hp_Steal = (int32_t)0;
	P_dodge_Rate = (int32_t)0;
	P_hit_Rate = (int32_t)0;
	P_blk_Rate = (int32_t)0;
	P_brk_blk_Rate = (int32_t)0;
	P_blk_Free = (int32_t)0;
	P_blk_Pierce = (int32_t)0;
	P_rel_Armor = (int32_t)0;
	P_rel_Dam = (int32_t)0;
	P_five_Resist = (int32_t)0;
	P_five_resist_Redu = (int32_t)0;
	P_fire_Add = (int32_t)0;
	P_fire_Redu = (int32_t)0;
	P_ice_Add = (int32_t)0;
	P_ice_Redu = (int32_t)0;
	P_thunder_Add = (int32_t)0;
	P_thunder_Rdu = (int32_t)0;
	P_player_Add = (int32_t)0;
	P_player_Redu = (int32_t)0;
	P_leader_Add = (int32_t)0;
	P_leader_Redu = (int32_t)0;
	P_mon_Add = (int32_t)0;
	P_mon_Redu = (int32_t)0;
	P_var_Redu = (int32_t)0;
	P_var_Add = (int32_t)0;
	P_unusual_Resist = (int32_t)0;
	P_unusual_Hit = (int32_t)0;
	P_hp_Recover = (int32_t)0;
	P_unusual_Add = (int32_t)0;
	P_fix_Recover = (int32_t)0;
	P_high_hp_Add = (int32_t)0;
	P_recover_hp_Add = (int32_t)0;
	P_week_Add = (int32_t)0;
	shield = (int64_t)0;
	return 0;
}

int monstervalueParam_s::ResumeInit() {
	return 0;
}

void monstervalueParam_s::write_to_pbmsg(::proto_ff::monstervalueParam & msg) const {
	msg.set_id((int32_t)id);
	msg.set_p_max_hp((int32_t)P_max_Hp);
	msg.set_p_atk((int32_t)P_atk);
	msg.set_p_def((int32_t)P_def);
	msg.set_p_brk_armor((int32_t)P_brk_Armor);
	msg.set_p_five_dam((int32_t)P_five_Dam);
	msg.set_p_five_armor((int32_t)P_five_Armor);
	msg.set_p_thump_rate((int32_t)P_thump_Rate);
	msg.set_p_thump_resist((int32_t)P_thump_Resist);
	msg.set_p_sky((int32_t)P_sky);
	msg.set_p_sky_dam((int32_t)P_sky_Dam);
	msg.set_p_sky_redu_resist((int32_t)P_sky_Redu_Resist);
	msg.set_p_sky_resist((int32_t)P_sky_Resist);
	msg.set_p_kill_god((int32_t)P_kill_God);
	msg.set_p_god_body((int32_t)P_god_Body);
	msg.set_p_mortal_rate((int32_t)P_mortal_Rate);
	msg.set_p_mortal_resist((int32_t)P_mortal_Resist);
	msg.set_p_fairy_rate((int32_t)P_fairy_Rate);
	msg.set_p_fairy_resist((int32_t)P_fairy_Resist);
	msg.set_p_god_rate((int32_t)P_god_Rate);
	msg.set_p_god_resist((int32_t)P_god_Resist);
	msg.set_p_crit_rate((int32_t)P_crit_Rate);
	msg.set_p_crit_resit_rate((int32_t)P_crit_resit_Rate);
	msg.set_p_crit_dam((int32_t)P_crit_Dam);
	msg.set_p_crit_redu((int32_t)P_crit_Redu);
	msg.set_p_batter_rate((int32_t)P_batter_Rate);
	msg.set_p_batter_resist((int32_t)P_batter_Resist);
	msg.set_p_batter_dam((int32_t)P_batter_Dam);
	msg.set_p_batter_redu((int32_t)P_batter_Redu);
	msg.set_p_brkdown_rate((int32_t)P_brkdown_Rate);
	msg.set_p_brkdown_resist((int32_t)P_brkdown_Resist);
	msg.set_p_dam_add((int32_t)P_dam_Add);
	msg.set_p_dam_redu((int32_t)P_dam_Redu);
	msg.set_p_all_add((int32_t)P_all_Add);
	msg.set_p_all_redu((int32_t)P_all_Redu);
	msg.set_p_skill_add((int32_t)P_skill_Add);
	msg.set_p_skill_redu((int32_t)P_skill_Redu);
	msg.set_p_rebound_dam((int32_t)P_rebound_Dam);
	msg.set_p_hp_steal((int32_t)P_hp_Steal);
	msg.set_p_dodge_rate((int32_t)P_dodge_Rate);
	msg.set_p_hit_rate((int32_t)P_hit_Rate);
	msg.set_p_blk_rate((int32_t)P_blk_Rate);
	msg.set_p_brk_blk_rate((int32_t)P_brk_blk_Rate);
	msg.set_p_blk_free((int32_t)P_blk_Free);
	msg.set_p_blk_pierce((int32_t)P_blk_Pierce);
	msg.set_p_rel_armor((int32_t)P_rel_Armor);
	msg.set_p_rel_dam((int32_t)P_rel_Dam);
	msg.set_p_five_resist((int32_t)P_five_Resist);
	msg.set_p_five_resist_redu((int32_t)P_five_resist_Redu);
	msg.set_p_fire_add((int32_t)P_fire_Add);
	msg.set_p_fire_redu((int32_t)P_fire_Redu);
	msg.set_p_ice_add((int32_t)P_ice_Add);
	msg.set_p_ice_redu((int32_t)P_ice_Redu);
	msg.set_p_thunder_add((int32_t)P_thunder_Add);
	msg.set_p_thunder_rdu((int32_t)P_thunder_Rdu);
	msg.set_p_player_add((int32_t)P_player_Add);
	msg.set_p_player_redu((int32_t)P_player_Redu);
	msg.set_p_leader_add((int32_t)P_leader_Add);
	msg.set_p_leader_redu((int32_t)P_leader_Redu);
	msg.set_p_mon_add((int32_t)P_mon_Add);
	msg.set_p_mon_redu((int32_t)P_mon_Redu);
	msg.set_p_var_redu((int32_t)P_var_Redu);
	msg.set_p_var_add((int32_t)P_var_Add);
	msg.set_p_unusual_resist((int32_t)P_unusual_Resist);
	msg.set_p_unusual_hit((int32_t)P_unusual_Hit);
	msg.set_p_hp_recover((int32_t)P_hp_Recover);
	msg.set_p_unusual_add((int32_t)P_unusual_Add);
	msg.set_p_fix_recover((int32_t)P_fix_Recover);
	msg.set_p_high_hp_add((int32_t)P_high_hp_Add);
	msg.set_p_recover_hp_add((int32_t)P_recover_hp_Add);
	msg.set_p_week_add((int32_t)P_week_Add);
	msg.set_shield((int64_t)shield);
}

void monstervalueParam_s::read_from_pbmsg(const ::proto_ff::monstervalueParam & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct monstervalueParam_s));
	id = msg.id();
	P_max_Hp = msg.p_max_hp();
	P_atk = msg.p_atk();
	P_def = msg.p_def();
	P_brk_Armor = msg.p_brk_armor();
	P_five_Dam = msg.p_five_dam();
	P_five_Armor = msg.p_five_armor();
	P_thump_Rate = msg.p_thump_rate();
	P_thump_Resist = msg.p_thump_resist();
	P_sky = msg.p_sky();
	P_sky_Dam = msg.p_sky_dam();
	P_sky_Redu_Resist = msg.p_sky_redu_resist();
	P_sky_Resist = msg.p_sky_resist();
	P_kill_God = msg.p_kill_god();
	P_god_Body = msg.p_god_body();
	P_mortal_Rate = msg.p_mortal_rate();
	P_mortal_Resist = msg.p_mortal_resist();
	P_fairy_Rate = msg.p_fairy_rate();
	P_fairy_Resist = msg.p_fairy_resist();
	P_god_Rate = msg.p_god_rate();
	P_god_Resist = msg.p_god_resist();
	P_crit_Rate = msg.p_crit_rate();
	P_crit_resit_Rate = msg.p_crit_resit_rate();
	P_crit_Dam = msg.p_crit_dam();
	P_crit_Redu = msg.p_crit_redu();
	P_batter_Rate = msg.p_batter_rate();
	P_batter_Resist = msg.p_batter_resist();
	P_batter_Dam = msg.p_batter_dam();
	P_batter_Redu = msg.p_batter_redu();
	P_brkdown_Rate = msg.p_brkdown_rate();
	P_brkdown_Resist = msg.p_brkdown_resist();
	P_dam_Add = msg.p_dam_add();
	P_dam_Redu = msg.p_dam_redu();
	P_all_Add = msg.p_all_add();
	P_all_Redu = msg.p_all_redu();
	P_skill_Add = msg.p_skill_add();
	P_skill_Redu = msg.p_skill_redu();
	P_rebound_Dam = msg.p_rebound_dam();
	P_hp_Steal = msg.p_hp_steal();
	P_dodge_Rate = msg.p_dodge_rate();
	P_hit_Rate = msg.p_hit_rate();
	P_blk_Rate = msg.p_blk_rate();
	P_brk_blk_Rate = msg.p_brk_blk_rate();
	P_blk_Free = msg.p_blk_free();
	P_blk_Pierce = msg.p_blk_pierce();
	P_rel_Armor = msg.p_rel_armor();
	P_rel_Dam = msg.p_rel_dam();
	P_five_Resist = msg.p_five_resist();
	P_five_resist_Redu = msg.p_five_resist_redu();
	P_fire_Add = msg.p_fire_add();
	P_fire_Redu = msg.p_fire_redu();
	P_ice_Add = msg.p_ice_add();
	P_ice_Redu = msg.p_ice_redu();
	P_thunder_Add = msg.p_thunder_add();
	P_thunder_Rdu = msg.p_thunder_rdu();
	P_player_Add = msg.p_player_add();
	P_player_Redu = msg.p_player_redu();
	P_leader_Add = msg.p_leader_add();
	P_leader_Redu = msg.p_leader_redu();
	P_mon_Add = msg.p_mon_add();
	P_mon_Redu = msg.p_mon_redu();
	P_var_Redu = msg.p_var_redu();
	P_var_Add = msg.p_var_add();
	P_unusual_Resist = msg.p_unusual_resist();
	P_unusual_Hit = msg.p_unusual_hit();
	P_hp_Recover = msg.p_hp_recover();
	P_unusual_Add = msg.p_unusual_add();
	P_fix_Recover = msg.p_fix_recover();
	P_high_hp_Add = msg.p_high_hp_add();
	P_recover_hp_Add = msg.p_recover_hp_add();
	P_week_Add = msg.p_week_add();
	shield = msg.shield();
}

Sheet_monstervalueParam_s::Sheet_monstervalueParam_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_monstervalueParam_s::CreateInit() {
	return 0;
}

int Sheet_monstervalueParam_s::ResumeInit() {
	return 0;
}

void Sheet_monstervalueParam_s::write_to_pbmsg(::proto_ff::Sheet_monstervalueParam & msg) const {
	for(int32_t i = 0; i < (int32_t)monstervalueParam_List.GetSize() && i < monstervalueParam_List.GetMaxSize(); ++i) {
		::proto_ff::monstervalueParam* temp_monstervalueparam_list = msg.add_monstervalueparam_list();
		monstervalueParam_List[i].write_to_pbmsg(*temp_monstervalueparam_list);
	}
}

void Sheet_monstervalueParam_s::read_from_pbmsg(const ::proto_ff::Sheet_monstervalueParam & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_monstervalueParam_s));
	monstervalueParam_List.SetSize(msg.monstervalueparam_list_size() > monstervalueParam_List.GetMaxSize() ? monstervalueParam_List.GetMaxSize() : msg.monstervalueparam_list_size());
	for(int32_t i = 0; i < (int32_t)monstervalueParam_List.GetSize(); ++i) {
		const ::proto_ff::monstervalueParam & temp_monstervalueparam_list = msg.monstervalueparam_list(i);
		monstervalueParam_List[i].read_from_pbmsg(temp_monstervalueparam_list);
	}
}

monsterdrop_s::monsterdrop_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int monsterdrop_s::CreateInit() {
	id = (int32_t)0;
	group = (int32_t)0;
	own = (int32_t)0;
	type = (int32_t)0;
	return 0;
}

int monsterdrop_s::ResumeInit() {
	return 0;
}

void monsterdrop_s::write_to_pbmsg(::proto_ff::monsterdrop & msg) const {
	msg.set_id((int32_t)id);
	msg.set_group((int32_t)group);
	msg.set_own((int32_t)own);
	msg.set_type((int32_t)type);
	for(int32_t i = 0; i < (int32_t)boxID.GetSize() && i < boxID.GetMaxSize(); ++i) {
		msg.add_boxid((int64_t)boxID[i]);
	}
}

void monsterdrop_s::read_from_pbmsg(const ::proto_ff::monsterdrop & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct monsterdrop_s));
	id = msg.id();
	group = msg.group();
	own = msg.own();
	type = msg.type();
	boxID.SetSize(msg.boxid_size() > boxID.GetMaxSize() ? boxID.GetMaxSize() : msg.boxid_size());
	for(int32_t i = 0; i < (int32_t)boxID.GetSize(); ++i) {
		boxID[i] = msg.boxid(i);
	}
}

Sheet_monsterdrop_s::Sheet_monsterdrop_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_monsterdrop_s::CreateInit() {
	return 0;
}

int Sheet_monsterdrop_s::ResumeInit() {
	return 0;
}

void Sheet_monsterdrop_s::write_to_pbmsg(::proto_ff::Sheet_monsterdrop & msg) const {
	for(int32_t i = 0; i < (int32_t)monsterdrop_List.GetSize() && i < monsterdrop_List.GetMaxSize(); ++i) {
		::proto_ff::monsterdrop* temp_monsterdrop_list = msg.add_monsterdrop_list();
		monsterdrop_List[i].write_to_pbmsg(*temp_monsterdrop_list);
	}
}

void Sheet_monsterdrop_s::read_from_pbmsg(const ::proto_ff::Sheet_monsterdrop & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_monsterdrop_s));
	monsterdrop_List.SetSize(msg.monsterdrop_list_size() > monsterdrop_List.GetMaxSize() ? monsterdrop_List.GetMaxSize() : msg.monsterdrop_list_size());
	for(int32_t i = 0; i < (int32_t)monsterdrop_List.GetSize(); ++i) {
		const ::proto_ff::monsterdrop & temp_monsterdrop_list = msg.monsterdrop_list(i);
		monsterdrop_List[i].read_from_pbmsg(temp_monsterdrop_list);
	}
}

}