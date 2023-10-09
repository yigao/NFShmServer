#include "DBProto_s.h"

namespace proto_ff_s {

RoleReliveProto_s::RoleReliveProto_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int RoleReliveProto_s::CreateInit() {
	tired_time = (uint64_t)0;
	relive_num = (int32_t)0;
	is_tired = (int32_t)0;
	mapid = (uint64_t)0;
	map_relive_num = (int32_t)0;
	return 0;
}

int RoleReliveProto_s::ResumeInit() {
	return 0;
}

void RoleReliveProto_s::write_to_pbmsg(::proto_ff::RoleReliveProto & msg) const {
	msg.set_tired_time((uint64_t)tired_time);
	msg.set_relive_num((int32_t)relive_num);
	msg.set_is_tired((int32_t)is_tired);
	msg.set_mapid((uint64_t)mapid);
	msg.set_map_relive_num((int32_t)map_relive_num);
}

void RoleReliveProto_s::read_from_pbmsg(const ::proto_ff::RoleReliveProto & msg) {
	tired_time = msg.tired_time();
	relive_num = msg.relive_num();
	is_tired = msg.is_tired();
	mapid = msg.mapid();
	map_relive_num = msg.map_relive_num();
}

RoleDBBaseData_s::RoleDBBaseData_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int RoleDBBaseData_s::CreateInit() {
	prof = (uint32_t)0;
	level = (uint32_t)0;
	exp = (int64_t)0;
	hp = (int64_t)0;
	fight = (int64_t)0;
	createTime = (uint64_t)0;
	loginTime = (uint64_t)0;
	logoutTime = (uint64_t)0;
	enter_scene_id = (uint64_t)0;
	enter_map_id = (uint64_t)0;
	enterposx = (float)0;
	enterposy = (float)0;
	enterposz = (float)0;
	lastsceneid = (uint64_t)0;
	lastmapid = (uint64_t)0;
	lastposx = (float)0;
	lastposy = (float)0;
	lastposz = (float)0;
	vip_level = (uint32_t)0;
	state = (int32_t)0;
	hanguptime = (uint64_t)0;
	gold = (int64_t)0;
	dia = (int64_t)0;
	bdia = (int64_t)0;
	magic = (int64_t)0;
	prestige = (int64_t)0;
	vipLv = (int32_t)0;
	arenacoin = (int64_t)0;
	godevil_exp = (int64_t)0;
	godevil_level = (int32_t)0;
	login_day = (uint32_t)0;
	login_day_time = (uint64_t)0;
	best_aq = (int64_t)0;
	best_lj = (int64_t)0;
	return 0;
}

int RoleDBBaseData_s::ResumeInit() {
	return 0;
}

void RoleDBBaseData_s::write_to_pbmsg(::proto_ff::RoleDBBaseData & msg) const {
	msg.set_name(name.data());
	msg.set_prof((uint32_t)prof);
	msg.set_level((uint32_t)level);
	msg.set_exp((int64_t)exp);
	msg.set_hp((int64_t)hp);
	msg.set_fight((int64_t)fight);
	msg.set_createtime((uint64_t)createTime);
	msg.set_logintime((uint64_t)loginTime);
	msg.set_logouttime((uint64_t)logoutTime);
	msg.set_enter_scene_id((uint64_t)enter_scene_id);
	msg.set_enter_map_id((uint64_t)enter_map_id);
	msg.set_enterposx((float)enterposx);
	msg.set_enterposy((float)enterposy);
	msg.set_enterposz((float)enterposz);
	msg.set_lastsceneid((uint64_t)lastsceneid);
	msg.set_lastmapid((uint64_t)lastmapid);
	msg.set_lastposx((float)lastposx);
	msg.set_lastposy((float)lastposy);
	msg.set_lastposz((float)lastposz);
	::proto_ff::RoleFacadeProto* temp_facade = msg.mutable_facade();
	facade.write_to_pbmsg(*temp_facade);
	msg.set_vip_level((uint32_t)vip_level);
	msg.set_state((int32_t)state);
	msg.set_hanguptime((uint64_t)hanguptime);
	::proto_ff::RoleReliveProto* temp_relive = msg.mutable_relive();
	relive.write_to_pbmsg(*temp_relive);
	msg.set_gold((int64_t)gold);
	msg.set_dia((int64_t)dia);
	msg.set_bdia((int64_t)bdia);
	msg.set_magic((int64_t)magic);
	msg.set_prestige((int64_t)prestige);
	msg.set_viplv((int32_t)vipLv);
	msg.set_arenacoin((int64_t)arenacoin);
	msg.set_godevil_exp((int64_t)godevil_exp);
	msg.set_godevil_level((int32_t)godevil_level);
	msg.set_login_day((uint32_t)login_day);
	msg.set_login_day_time((uint64_t)login_day_time);
	msg.set_best_aq((int64_t)best_aq);
	msg.set_best_lj((int64_t)best_lj);
}

void RoleDBBaseData_s::read_from_pbmsg(const ::proto_ff::RoleDBBaseData & msg) {
	name = msg.name();
	prof = msg.prof();
	level = msg.level();
	exp = msg.exp();
	hp = msg.hp();
	fight = msg.fight();
	createTime = msg.createtime();
	loginTime = msg.logintime();
	logoutTime = msg.logouttime();
	enter_scene_id = msg.enter_scene_id();
	enter_map_id = msg.enter_map_id();
	enterposx = msg.enterposx();
	enterposy = msg.enterposy();
	enterposz = msg.enterposz();
	lastsceneid = msg.lastsceneid();
	lastmapid = msg.lastmapid();
	lastposx = msg.lastposx();
	lastposy = msg.lastposy();
	lastposz = msg.lastposz();
	const ::proto_ff::RoleFacadeProto & temp_facade = msg.facade();
	facade.read_from_pbmsg(temp_facade);
	vip_level = msg.vip_level();
	state = msg.state();
	hanguptime = msg.hanguptime();
	const ::proto_ff::RoleReliveProto & temp_relive = msg.relive();
	relive.read_from_pbmsg(temp_relive);
	gold = msg.gold();
	dia = msg.dia();
	bdia = msg.bdia();
	magic = msg.magic();
	prestige = msg.prestige();
	vipLv = msg.viplv();
	arenacoin = msg.arenacoin();
	godevil_exp = msg.godevil_exp();
	godevil_level = msg.godevil_level();
	login_day = msg.login_day();
	login_day_time = msg.login_day_time();
	best_aq = msg.best_aq();
	best_lj = msg.best_lj();
}

BagItemsDBData_s::BagItemsDBData_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int BagItemsDBData_s::CreateInit() {
	offset = (int32_t)0;
	return 0;
}

int BagItemsDBData_s::ResumeInit() {
	return 0;
}

void BagItemsDBData_s::write_to_pbmsg(::proto_ff::BagItemsDBData & msg) const {
	for(int32_t i = 0; i < (int32_t)data.size(); ++i) {
		::proto_ff::ItemProtoInfo* temp_data = msg.add_data();
		data[i].write_to_pbmsg(*temp_data);
	}
	msg.set_offset((int32_t)offset);
}

void BagItemsDBData_s::read_from_pbmsg(const ::proto_ff::BagItemsDBData & msg) {
	data.resize((int)msg.data_size() > (int)data.max_size() ? data.max_size() : msg.data_size());
	for(int32_t i = 0; i < (int32_t)data.size(); ++i) {
		const ::proto_ff::ItemProtoInfo & temp_data = msg.data(i);
		data[i].read_from_pbmsg(temp_data);
	}
	offset = msg.offset();
}

BagDBSimpleData_s::BagDBSimpleData_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int BagDBSimpleData_s::CreateInit() {
	package_type = (uint32_t)0;
	expand_num = (uint32_t)0;
	return 0;
}

int BagDBSimpleData_s::ResumeInit() {
	return 0;
}

void BagDBSimpleData_s::write_to_pbmsg(::proto_ff::BagDBSimpleData & msg) const {
	msg.set_package_type((uint32_t)package_type);
	msg.set_expand_num((uint32_t)expand_num);
}

void BagDBSimpleData_s::read_from_pbmsg(const ::proto_ff::BagDBSimpleData & msg) {
	package_type = msg.package_type();
	expand_num = msg.expand_num();
}

RoleDBUnitBagData_s::RoleDBUnitBagData_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int RoleDBUnitBagData_s::CreateInit() {
	return 0;
}

int RoleDBUnitBagData_s::ResumeInit() {
	return 0;
}

void RoleDBUnitBagData_s::write_to_pbmsg(::proto_ff::RoleDBUnitBagData & msg) const {
	msg.set_table_name(table_name.data());
	::proto_ff::BagDBSimpleData* temp_simple = msg.mutable_simple();
	simple.write_to_pbmsg(*temp_simple);
	for(int32_t i = 0; i < (int32_t)parts.size(); ++i) {
		::proto_ff::BagItemsDBData* temp_parts = msg.add_parts();
		parts[i].write_to_pbmsg(*temp_parts);
	}
}

void RoleDBUnitBagData_s::read_from_pbmsg(const ::proto_ff::RoleDBUnitBagData & msg) {
	table_name = msg.table_name();
	const ::proto_ff::BagDBSimpleData & temp_simple = msg.simple();
	simple.read_from_pbmsg(temp_simple);
	parts.resize((int)msg.parts_size() > (int)parts.max_size() ? parts.max_size() : msg.parts_size());
	for(int32_t i = 0; i < (int32_t)parts.size(); ++i) {
		const ::proto_ff::BagItemsDBData & temp_parts = msg.parts(i);
		parts[i].read_from_pbmsg(temp_parts);
	}
}

RoleDBBagData_s::RoleDBBagData_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int RoleDBBagData_s::CreateInit() {
	return 0;
}

int RoleDBBagData_s::ResumeInit() {
	return 0;
}

void RoleDBBagData_s::write_to_pbmsg(::proto_ff::RoleDBBagData & msg) const {
	for(int32_t i = 0; i < (int32_t)bags.size(); ++i) {
		::proto_ff::RoleDBUnitBagData* temp_bags = msg.add_bags();
		bags[i].write_to_pbmsg(*temp_bags);
	}
}

void RoleDBBagData_s::read_from_pbmsg(const ::proto_ff::RoleDBBagData & msg) {
	bags.resize((int)msg.bags_size() > (int)bags.max_size() ? bags.max_size() : msg.bags_size());
	for(int32_t i = 0; i < (int32_t)bags.size(); ++i) {
		const ::proto_ff::RoleDBUnitBagData & temp_bags = msg.bags(i);
		bags[i].read_from_pbmsg(temp_bags);
	}
}

RoleDBEquipData_s::RoleDBEquipData_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int RoleDBEquipData_s::CreateInit() {
	stove_level = (uint32_t)0;
	stove_exp = (uint64_t)0;
	return 0;
}

int RoleDBEquipData_s::ResumeInit() {
	return 0;
}

void RoleDBEquipData_s::write_to_pbmsg(::proto_ff::RoleDBEquipData & msg) const {
	for(int32_t i = 0; i < (int32_t)infos.size(); ++i) {
		::proto_ff::EquipInfo* temp_infos = msg.add_infos();
		infos[i].write_to_pbmsg(*temp_infos);
	}
	for(int32_t i = 0; i < (int32_t)lv_attr.size(); ++i) {
		::proto_ff::EquipLvAttrInfo* temp_lv_attr = msg.add_lv_attr();
		lv_attr[i].write_to_pbmsg(*temp_lv_attr);
	}
	msg.set_stove_level((uint32_t)stove_level);
	msg.set_stove_exp((uint64_t)stove_exp);
}

void RoleDBEquipData_s::read_from_pbmsg(const ::proto_ff::RoleDBEquipData & msg) {
	infos.resize((int)msg.infos_size() > (int)infos.max_size() ? infos.max_size() : msg.infos_size());
	for(int32_t i = 0; i < (int32_t)infos.size(); ++i) {
		const ::proto_ff::EquipInfo & temp_infos = msg.infos(i);
		infos[i].read_from_pbmsg(temp_infos);
	}
	lv_attr.resize((int)msg.lv_attr_size() > (int)lv_attr.max_size() ? lv_attr.max_size() : msg.lv_attr_size());
	for(int32_t i = 0; i < (int32_t)lv_attr.size(); ++i) {
		const ::proto_ff::EquipLvAttrInfo & temp_lv_attr = msg.lv_attr(i);
		lv_attr[i].read_from_pbmsg(temp_lv_attr);
	}
	stove_level = msg.stove_level();
	stove_exp = msg.stove_exp();
}

RoleDBTaskData_s::RoleDBTaskData_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int RoleDBTaskData_s::CreateInit() {
	return 0;
}

int RoleDBTaskData_s::ResumeInit() {
	return 0;
}

void RoleDBTaskData_s::write_to_pbmsg(::proto_ff::RoleDBTaskData & msg) const {
}

void RoleDBTaskData_s::read_from_pbmsg(const ::proto_ff::RoleDBTaskData & msg) {
}

GrowPartEntryDBInfo_s::GrowPartEntryDBInfo_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int GrowPartEntryDBInfo_s::CreateInit() {
	id = (int64_t)0;
	lv = (int32_t)0;
	return 0;
}

int GrowPartEntryDBInfo_s::ResumeInit() {
	return 0;
}

void GrowPartEntryDBInfo_s::write_to_pbmsg(::proto_ff::GrowPartEntryDBInfo & msg) const {
	msg.set_id((int64_t)id);
	msg.set_lv((int32_t)lv);
}

void GrowPartEntryDBInfo_s::read_from_pbmsg(const ::proto_ff::GrowPartEntryDBInfo & msg) {
	id = msg.id();
	lv = msg.lv();
}

GrowPartDBData_s::GrowPartDBData_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int GrowPartDBData_s::CreateInit() {
	type = (int32_t)0;
	curId = (int64_t)0;
	return 0;
}

int GrowPartDBData_s::ResumeInit() {
	return 0;
}

void GrowPartDBData_s::write_to_pbmsg(::proto_ff::GrowPartDBData & msg) const {
	msg.set_type((int32_t)type);
	for(int32_t i = 0; i < (int32_t)entrys.size(); ++i) {
		::proto_ff::GrowPartEntryDBInfo* temp_entrys = msg.add_entrys();
		entrys[i].write_to_pbmsg(*temp_entrys);
	}
	msg.set_curid((int64_t)curId);
}

void GrowPartDBData_s::read_from_pbmsg(const ::proto_ff::GrowPartDBData & msg) {
	type = msg.type();
	entrys.resize((int)msg.entrys_size() > (int)entrys.max_size() ? entrys.max_size() : msg.entrys_size());
	for(int32_t i = 0; i < (int32_t)entrys.size(); ++i) {
		const ::proto_ff::GrowPartEntryDBInfo & temp_entrys = msg.entrys(i);
		entrys[i].read_from_pbmsg(temp_entrys);
	}
	curId = msg.curid();
}

GrowDBData_s::GrowDBData_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int GrowDBData_s::CreateInit() {
	return 0;
}

int GrowDBData_s::ResumeInit() {
	return 0;
}

void GrowDBData_s::write_to_pbmsg(::proto_ff::GrowDBData & msg) const {
	for(int32_t i = 0; i < (int32_t)parts.size(); ++i) {
		::proto_ff::GrowPartDBData* temp_parts = msg.add_parts();
		parts[i].write_to_pbmsg(*temp_parts);
	}
}

void GrowDBData_s::read_from_pbmsg(const ::proto_ff::GrowDBData & msg) {
	parts.resize((int)msg.parts_size() > (int)parts.max_size() ? parts.max_size() : msg.parts_size());
	for(int32_t i = 0; i < (int32_t)parts.size(); ++i) {
		const ::proto_ff::GrowPartDBData & temp_parts = msg.parts(i);
		parts[i].read_from_pbmsg(temp_parts);
	}
}

DayUseItemData_s::DayUseItemData_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int DayUseItemData_s::CreateInit() {
	return 0;
}

int DayUseItemData_s::ResumeInit() {
	return 0;
}

void DayUseItemData_s::write_to_pbmsg(::proto_ff::DayUseItemData & msg) const {
	for(int32_t i = 0; i < (int32_t)info.size(); ++i) {
		::proto_ff::ComPair64* temp_info = msg.add_info();
		info[i].write_to_pbmsg(*temp_info);
	}
}

void DayUseItemData_s::read_from_pbmsg(const ::proto_ff::DayUseItemData & msg) {
	info.resize((int)msg.info_size() > (int)info.max_size() ? info.max_size() : msg.info_size());
	for(int32_t i = 0; i < (int32_t)info.size(); ++i) {
		const ::proto_ff::ComPair64 & temp_info = msg.info(i);
		info[i].read_from_pbmsg(temp_info);
	}
}

CharacterArenaData_s::CharacterArenaData_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int CharacterArenaData_s::CreateInit() {
	challengeTimes = (uint32_t)0;
	updateTime = (uint64_t)0;
	historyRankId = (uint32_t)0;
	buyChallengeTimes = (uint32_t)0;
	allChallengeTimes = (int32_t)0;
	rank_id = (int32_t)0;
	return 0;
}

int CharacterArenaData_s::ResumeInit() {
	return 0;
}

void CharacterArenaData_s::write_to_pbmsg(::proto_ff::CharacterArenaData & msg) const {
	msg.set_challengetimes((uint32_t)challengeTimes);
	msg.set_updatetime((uint64_t)updateTime);
	msg.set_historyrankid((uint32_t)historyRankId);
	msg.set_buychallengetimes((uint32_t)buyChallengeTimes);
	for(int32_t i = 0; i < (int32_t)result.size(); ++i) {
		::proto_ff::ArenaChallResult* temp_result = msg.add_result();
		result[i].write_to_pbmsg(*temp_result);
	}
	for(int32_t i = 0; i < (int32_t)chall_reward.size(); ++i) {
		::proto_ff::ChallArenaReward* temp_chall_reward = msg.add_chall_reward();
		chall_reward[i].write_to_pbmsg(*temp_chall_reward);
	}
	msg.set_allchallengetimes((int32_t)allChallengeTimes);
	msg.set_rank_id((int32_t)rank_id);
}

void CharacterArenaData_s::read_from_pbmsg(const ::proto_ff::CharacterArenaData & msg) {
	challengeTimes = msg.challengetimes();
	updateTime = msg.updatetime();
	historyRankId = msg.historyrankid();
	buyChallengeTimes = msg.buychallengetimes();
	result.resize((int)msg.result_size() > (int)result.max_size() ? result.max_size() : msg.result_size());
	for(int32_t i = 0; i < (int32_t)result.size(); ++i) {
		const ::proto_ff::ArenaChallResult & temp_result = msg.result(i);
		result[i].read_from_pbmsg(temp_result);
	}
	chall_reward.resize((int)msg.chall_reward_size() > (int)chall_reward.max_size() ? chall_reward.max_size() : msg.chall_reward_size());
	for(int32_t i = 0; i < (int32_t)chall_reward.size(); ++i) {
		const ::proto_ff::ChallArenaReward & temp_chall_reward = msg.chall_reward(i);
		chall_reward[i].read_from_pbmsg(temp_chall_reward);
	}
	allChallengeTimes = msg.allchallengetimes();
	rank_id = msg.rank_id();
}

MiniDBData_s::MiniDBData_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int MiniDBData_s::CreateInit() {
	lastTime = (uint64_t)0;
	return 0;
}

int MiniDBData_s::ResumeInit() {
	return 0;
}

void MiniDBData_s::write_to_pbmsg(::proto_ff::MiniDBData & msg) const {
	msg.set_lasttime((uint64_t)lastTime);
	::proto_ff::DayUseItemData* temp_useitem = msg.mutable_useitem();
	useItem.write_to_pbmsg(*temp_useitem);
	::proto_ff::CharacterArenaData* temp_arena_data = msg.mutable_arena_data();
	arena_data.write_to_pbmsg(*temp_arena_data);
}

void MiniDBData_s::read_from_pbmsg(const ::proto_ff::MiniDBData & msg) {
	lastTime = msg.lasttime();
	const ::proto_ff::DayUseItemData & temp_useitem = msg.useitem();
	useItem.read_from_pbmsg(temp_useitem);
	const ::proto_ff::CharacterArenaData & temp_arena_data = msg.arena_data();
	arena_data.read_from_pbmsg(temp_arena_data);
}

FacadeDataInfo_s::FacadeDataInfo_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int FacadeDataInfo_s::CreateInit() {
	facade_type = (uint32_t)0;
	facade_id = (uint64_t)0;
	facade_lev = (uint32_t)0;
	facade_exp = (uint64_t)0;
	use_soul_item = (bool)0;
	use_facade = (bool)0;
	equip_fantasy_id = (uint64_t)0;
	return 0;
}

int FacadeDataInfo_s::ResumeInit() {
	return 0;
}

void FacadeDataInfo_s::write_to_pbmsg(::proto_ff::FacadeDataInfo & msg) const {
	msg.set_facade_type((uint32_t)facade_type);
	msg.set_facade_id((uint64_t)facade_id);
	msg.set_facade_lev((uint32_t)facade_lev);
	msg.set_facade_exp((uint64_t)facade_exp);
	msg.set_use_soul_item((bool)use_soul_item);
	msg.set_use_facade((bool)use_facade);
	msg.set_equip_fantasy_id((uint64_t)equip_fantasy_id);
	for(int32_t i = 0; i < (int32_t)fantasy_map.size(); ++i) {
		::proto_ff::FacadeFantasyData* temp_fantasy_map = msg.add_fantasy_map();
		fantasy_map[i].write_to_pbmsg(*temp_fantasy_map);
	}
	for(int32_t i = 0; i < (int32_t)fragment_map.size(); ++i) {
		::proto_ff::FacadeFragmentData* temp_fragment_map = msg.add_fragment_map();
		fragment_map[i].write_to_pbmsg(*temp_fragment_map);
	}
	for(int32_t i = 0; i < (int32_t)skill_data.size(); ++i) {
		::proto_ff::FacadeSkillData* temp_skill_data = msg.add_skill_data();
		skill_data[i].write_to_pbmsg(*temp_skill_data);
	}
	::proto_ff::FacadeSoulData* temp_soul_data = msg.mutable_soul_data();
	soul_data.write_to_pbmsg(*temp_soul_data);
}

void FacadeDataInfo_s::read_from_pbmsg(const ::proto_ff::FacadeDataInfo & msg) {
	facade_type = msg.facade_type();
	facade_id = msg.facade_id();
	facade_lev = msg.facade_lev();
	facade_exp = msg.facade_exp();
	use_soul_item = msg.use_soul_item();
	use_facade = msg.use_facade();
	equip_fantasy_id = msg.equip_fantasy_id();
	fantasy_map.resize((int)msg.fantasy_map_size() > (int)fantasy_map.max_size() ? fantasy_map.max_size() : msg.fantasy_map_size());
	for(int32_t i = 0; i < (int32_t)fantasy_map.size(); ++i) {
		const ::proto_ff::FacadeFantasyData & temp_fantasy_map = msg.fantasy_map(i);
		fantasy_map[i].read_from_pbmsg(temp_fantasy_map);
	}
	fragment_map.resize((int)msg.fragment_map_size() > (int)fragment_map.max_size() ? fragment_map.max_size() : msg.fragment_map_size());
	for(int32_t i = 0; i < (int32_t)fragment_map.size(); ++i) {
		const ::proto_ff::FacadeFragmentData & temp_fragment_map = msg.fragment_map(i);
		fragment_map[i].read_from_pbmsg(temp_fragment_map);
	}
	skill_data.resize((int)msg.skill_data_size() > (int)skill_data.max_size() ? skill_data.max_size() : msg.skill_data_size());
	for(int32_t i = 0; i < (int32_t)skill_data.size(); ++i) {
		const ::proto_ff::FacadeSkillData & temp_skill_data = msg.skill_data(i);
		skill_data[i].read_from_pbmsg(temp_skill_data);
	}
	const ::proto_ff::FacadeSoulData & temp_soul_data = msg.soul_data();
	soul_data.read_from_pbmsg(temp_soul_data);
}

MountDataInfo_s::MountDataInfo_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int MountDataInfo_s::CreateInit() {
	mount_id = (uint64_t)0;
	mount_lev = (uint32_t)0;
	mount_exp = (uint64_t)0;
	use_facade = (bool)0;
	equip_fantasy_id = (uint64_t)0;
	ride_state = (uint32_t)0;
	mount_model_id = (uint64_t)0;
	last_mount_model_id = (uint64_t)0;
	return 0;
}

int MountDataInfo_s::ResumeInit() {
	return 0;
}

void MountDataInfo_s::write_to_pbmsg(::proto_ff::MountDataInfo & msg) const {
	msg.set_mount_id((uint64_t)mount_id);
	msg.set_mount_lev((uint32_t)mount_lev);
	msg.set_mount_exp((uint64_t)mount_exp);
	msg.set_use_facade((bool)use_facade);
	msg.set_equip_fantasy_id((uint64_t)equip_fantasy_id);
	for(int32_t i = 0; i < (int32_t)fantasy_map.size(); ++i) {
		::proto_ff::MountFantasyData* temp_fantasy_map = msg.add_fantasy_map();
		fantasy_map[i].write_to_pbmsg(*temp_fantasy_map);
	}
	for(int32_t i = 0; i < (int32_t)fragment_map.size(); ++i) {
		::proto_ff::MountFragmentData* temp_fragment_map = msg.add_fragment_map();
		fragment_map[i].write_to_pbmsg(*temp_fragment_map);
	}
	for(int32_t i = 0; i < (int32_t)skill_data.size(); ++i) {
		::proto_ff::MountSkillData* temp_skill_data = msg.add_skill_data();
		skill_data[i].write_to_pbmsg(*temp_skill_data);
	}
	for(int32_t i = 0; i < (int32_t)kun_data.size(); ++i) {
		::proto_ff::MountKunData* temp_kun_data = msg.add_kun_data();
		kun_data[i].write_to_pbmsg(*temp_kun_data);
	}
	for(int32_t i = 0; i < (int32_t)blood_data.size(); ++i) {
		::proto_ff::MountBloodData* temp_blood_data = msg.add_blood_data();
		blood_data[i].write_to_pbmsg(*temp_blood_data);
	}
	for(int32_t i = 0; i < (int32_t)baby_slot_data.size(); ++i) {
		::proto_ff::MountBabySlotData* temp_baby_slot_data = msg.add_baby_slot_data();
		baby_slot_data[i].write_to_pbmsg(*temp_baby_slot_data);
	}
	msg.set_ride_state((uint32_t)ride_state);
	msg.set_mount_model_id((uint64_t)mount_model_id);
	msg.set_last_mount_model_id((uint64_t)last_mount_model_id);
}

void MountDataInfo_s::read_from_pbmsg(const ::proto_ff::MountDataInfo & msg) {
	mount_id = msg.mount_id();
	mount_lev = msg.mount_lev();
	mount_exp = msg.mount_exp();
	use_facade = msg.use_facade();
	equip_fantasy_id = msg.equip_fantasy_id();
	fantasy_map.resize((int)msg.fantasy_map_size() > (int)fantasy_map.max_size() ? fantasy_map.max_size() : msg.fantasy_map_size());
	for(int32_t i = 0; i < (int32_t)fantasy_map.size(); ++i) {
		const ::proto_ff::MountFantasyData & temp_fantasy_map = msg.fantasy_map(i);
		fantasy_map[i].read_from_pbmsg(temp_fantasy_map);
	}
	fragment_map.resize((int)msg.fragment_map_size() > (int)fragment_map.max_size() ? fragment_map.max_size() : msg.fragment_map_size());
	for(int32_t i = 0; i < (int32_t)fragment_map.size(); ++i) {
		const ::proto_ff::MountFragmentData & temp_fragment_map = msg.fragment_map(i);
		fragment_map[i].read_from_pbmsg(temp_fragment_map);
	}
	skill_data.resize((int)msg.skill_data_size() > (int)skill_data.max_size() ? skill_data.max_size() : msg.skill_data_size());
	for(int32_t i = 0; i < (int32_t)skill_data.size(); ++i) {
		const ::proto_ff::MountSkillData & temp_skill_data = msg.skill_data(i);
		skill_data[i].read_from_pbmsg(temp_skill_data);
	}
	kun_data.resize((int)msg.kun_data_size() > (int)kun_data.max_size() ? kun_data.max_size() : msg.kun_data_size());
	for(int32_t i = 0; i < (int32_t)kun_data.size(); ++i) {
		const ::proto_ff::MountKunData & temp_kun_data = msg.kun_data(i);
		kun_data[i].read_from_pbmsg(temp_kun_data);
	}
	blood_data.resize((int)msg.blood_data_size() > (int)blood_data.max_size() ? blood_data.max_size() : msg.blood_data_size());
	for(int32_t i = 0; i < (int32_t)blood_data.size(); ++i) {
		const ::proto_ff::MountBloodData & temp_blood_data = msg.blood_data(i);
		blood_data[i].read_from_pbmsg(temp_blood_data);
	}
	baby_slot_data.resize((int)msg.baby_slot_data_size() > (int)baby_slot_data.max_size() ? baby_slot_data.max_size() : msg.baby_slot_data_size());
	for(int32_t i = 0; i < (int32_t)baby_slot_data.size(); ++i) {
		const ::proto_ff::MountBabySlotData & temp_baby_slot_data = msg.baby_slot_data(i);
		baby_slot_data[i].read_from_pbmsg(temp_baby_slot_data);
	}
	ride_state = msg.ride_state();
	mount_model_id = msg.mount_model_id();
	last_mount_model_id = msg.last_mount_model_id();
}

DeityDataInfo_s::DeityDataInfo_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int DeityDataInfo_s::CreateInit() {
	deity_id = (uint64_t)0;
	deity_lev = (uint32_t)0;
	deity_exp = (uint64_t)0;
	return 0;
}

int DeityDataInfo_s::ResumeInit() {
	return 0;
}

void DeityDataInfo_s::write_to_pbmsg(::proto_ff::DeityDataInfo & msg) const {
	msg.set_deity_id((uint64_t)deity_id);
	msg.set_deity_lev((uint32_t)deity_lev);
	msg.set_deity_exp((uint64_t)deity_exp);
	for(int32_t i = 0; i < (int32_t)fantasy_map.size(); ++i) {
		::proto_ff::DeityFantasyData* temp_fantasy_map = msg.add_fantasy_map();
		fantasy_map[i].write_to_pbmsg(*temp_fantasy_map);
	}
	for(int32_t i = 0; i < (int32_t)fragment_map.size(); ++i) {
		::proto_ff::DeityFragmentData* temp_fragment_map = msg.add_fragment_map();
		fragment_map[i].write_to_pbmsg(*temp_fragment_map);
	}
	for(int32_t i = 0; i < (int32_t)skill_data.size(); ++i) {
		::proto_ff::DeitySkillData* temp_skill_data = msg.add_skill_data();
		skill_data[i].write_to_pbmsg(*temp_skill_data);
	}
	for(int32_t i = 0; i < (int32_t)battle_data.size(); ++i) {
		::proto_ff::DeityBattleSlotData* temp_battle_data = msg.add_battle_data();
		battle_data[i].write_to_pbmsg(*temp_battle_data);
	}
}

void DeityDataInfo_s::read_from_pbmsg(const ::proto_ff::DeityDataInfo & msg) {
	deity_id = msg.deity_id();
	deity_lev = msg.deity_lev();
	deity_exp = msg.deity_exp();
	fantasy_map.resize((int)msg.fantasy_map_size() > (int)fantasy_map.max_size() ? fantasy_map.max_size() : msg.fantasy_map_size());
	for(int32_t i = 0; i < (int32_t)fantasy_map.size(); ++i) {
		const ::proto_ff::DeityFantasyData & temp_fantasy_map = msg.fantasy_map(i);
		fantasy_map[i].read_from_pbmsg(temp_fantasy_map);
	}
	fragment_map.resize((int)msg.fragment_map_size() > (int)fragment_map.max_size() ? fragment_map.max_size() : msg.fragment_map_size());
	for(int32_t i = 0; i < (int32_t)fragment_map.size(); ++i) {
		const ::proto_ff::DeityFragmentData & temp_fragment_map = msg.fragment_map(i);
		fragment_map[i].read_from_pbmsg(temp_fragment_map);
	}
	skill_data.resize((int)msg.skill_data_size() > (int)skill_data.max_size() ? skill_data.max_size() : msg.skill_data_size());
	for(int32_t i = 0; i < (int32_t)skill_data.size(); ++i) {
		const ::proto_ff::DeitySkillData & temp_skill_data = msg.skill_data(i);
		skill_data[i].read_from_pbmsg(temp_skill_data);
	}
	battle_data.resize((int)msg.battle_data_size() > (int)battle_data.max_size() ? battle_data.max_size() : msg.battle_data_size());
	for(int32_t i = 0; i < (int32_t)battle_data.size(); ++i) {
		const ::proto_ff::DeityBattleSlotData & temp_battle_data = msg.battle_data(i);
		battle_data[i].read_from_pbmsg(temp_battle_data);
	}
}

FacadeDBData_s::FacadeDBData_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int FacadeDBData_s::CreateInit() {
	return 0;
}

int FacadeDBData_s::ResumeInit() {
	return 0;
}

void FacadeDBData_s::write_to_pbmsg(::proto_ff::FacadeDBData & msg) const {
	for(int32_t i = 0; i < (int32_t)data.size(); ++i) {
		::proto_ff::FacadeDataInfo* temp_data = msg.add_data();
		data[i].write_to_pbmsg(*temp_data);
	}
}

void FacadeDBData_s::read_from_pbmsg(const ::proto_ff::FacadeDBData & msg) {
	data.resize((int)msg.data_size() > (int)data.max_size() ? data.max_size() : msg.data_size());
	for(int32_t i = 0; i < (int32_t)data.size(); ++i) {
		const ::proto_ff::FacadeDataInfo & temp_data = msg.data(i);
		data[i].read_from_pbmsg(temp_data);
	}
}

SkillDBInfo_s::SkillDBInfo_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int SkillDBInfo_s::CreateInit() {
	skill_id = (uint64_t)0;
	level = (int32_t)0;
	wakeup = (int32_t)0;
	use_msc = (int64_t)0;
	return 0;
}

int SkillDBInfo_s::ResumeInit() {
	return 0;
}

void SkillDBInfo_s::write_to_pbmsg(::proto_ff::SkillDBInfo & msg) const {
	msg.set_skill_id((uint64_t)skill_id);
	msg.set_level((int32_t)level);
	msg.set_wakeup((int32_t)wakeup);
	msg.set_use_msc((int64_t)use_msc);
}

void SkillDBInfo_s::read_from_pbmsg(const ::proto_ff::SkillDBInfo & msg) {
	skill_id = msg.skill_id();
	level = msg.level();
	wakeup = msg.wakeup();
	use_msc = msg.use_msc();
}

SkillDBPos_s::SkillDBPos_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int SkillDBPos_s::CreateInit() {
	skill_id = (uint64_t)0;
	pos = (uint32_t)0;
	use = (int32_t)0;
	return 0;
}

int SkillDBPos_s::ResumeInit() {
	return 0;
}

void SkillDBPos_s::write_to_pbmsg(::proto_ff::SkillDBPos & msg) const {
	msg.set_skill_id((uint64_t)skill_id);
	msg.set_pos((uint32_t)pos);
	msg.set_use((int32_t)use);
}

void SkillDBPos_s::read_from_pbmsg(const ::proto_ff::SkillDBPos & msg) {
	skill_id = msg.skill_id();
	pos = msg.pos();
	use = msg.use();
}

SkillDBAdvPos_s::SkillDBAdvPos_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int SkillDBAdvPos_s::CreateInit() {
	pos = (uint32_t)0;
	advance = (uint32_t)0;
	unlock = (uint32_t)0;
	return 0;
}

int SkillDBAdvPos_s::ResumeInit() {
	return 0;
}

void SkillDBAdvPos_s::write_to_pbmsg(::proto_ff::SkillDBAdvPos & msg) const {
	msg.set_pos((uint32_t)pos);
	msg.set_advance((uint32_t)advance);
	msg.set_unlock((uint32_t)unlock);
}

void SkillDBAdvPos_s::read_from_pbmsg(const ::proto_ff::SkillDBAdvPos & msg) {
	pos = msg.pos();
	advance = msg.advance();
	unlock = msg.unlock();
}

SkillDBAdvInfo_s::SkillDBAdvInfo_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int SkillDBAdvInfo_s::CreateInit() {
	advance = (int32_t)0;
	level = (int32_t)0;
	return 0;
}

int SkillDBAdvInfo_s::ResumeInit() {
	return 0;
}

void SkillDBAdvInfo_s::write_to_pbmsg(::proto_ff::SkillDBAdvInfo & msg) const {
	msg.set_advance((int32_t)advance);
	msg.set_level((int32_t)level);
}

void SkillDBAdvInfo_s::read_from_pbmsg(const ::proto_ff::SkillDBAdvInfo & msg) {
	advance = msg.advance();
	level = msg.level();
}

SkillDBGroup_s::SkillDBGroup_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int SkillDBGroup_s::CreateInit() {
	group = (uint32_t)0;
	chg = (int32_t)0;
	return 0;
}

int SkillDBGroup_s::ResumeInit() {
	return 0;
}

void SkillDBGroup_s::write_to_pbmsg(::proto_ff::SkillDBGroup & msg) const {
	msg.set_group((uint32_t)group);
	msg.set_chg((int32_t)chg);
	for(int32_t i = 0; i < (int32_t)pos_lst.size(); ++i) {
		::proto_ff::SkillDBPos* temp_pos_lst = msg.add_pos_lst();
		pos_lst[i].write_to_pbmsg(*temp_pos_lst);
	}
}

void SkillDBGroup_s::read_from_pbmsg(const ::proto_ff::SkillDBGroup & msg) {
	group = msg.group();
	chg = msg.chg();
	pos_lst.resize((int)msg.pos_lst_size() > (int)pos_lst.max_size() ? pos_lst.max_size() : msg.pos_lst_size());
	for(int32_t i = 0; i < (int32_t)pos_lst.size(); ++i) {
		const ::proto_ff::SkillDBPos & temp_pos_lst = msg.pos_lst(i);
		pos_lst[i].read_from_pbmsg(temp_pos_lst);
	}
}

PetSkillCdDB_s::PetSkillCdDB_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int PetSkillCdDB_s::CreateInit() {
	skill_id = (uint64_t)0;
	use_msec = (uint64_t)0;
	pet_instid = (int64_t)0;
	return 0;
}

int PetSkillCdDB_s::ResumeInit() {
	return 0;
}

void PetSkillCdDB_s::write_to_pbmsg(::proto_ff::PetSkillCdDB & msg) const {
	msg.set_skill_id((uint64_t)skill_id);
	msg.set_use_msec((uint64_t)use_msec);
	msg.set_pet_instid((int64_t)pet_instid);
}

void PetSkillCdDB_s::read_from_pbmsg(const ::proto_ff::PetSkillCdDB & msg) {
	skill_id = msg.skill_id();
	use_msec = msg.use_msec();
	pet_instid = msg.pet_instid();
}

SkillDBData_s::SkillDBData_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int SkillDBData_s::CreateInit() {
	group = (uint32_t)0;
	last_group = (uint64_t)0;
	cur_advpos = (uint32_t)0;
	return 0;
}

int SkillDBData_s::ResumeInit() {
	return 0;
}

void SkillDBData_s::write_to_pbmsg(::proto_ff::SkillDBData & msg) const {
	for(int32_t i = 0; i < (int32_t)info_lst.size(); ++i) {
		::proto_ff::SkillDBInfo* temp_info_lst = msg.add_info_lst();
		info_lst[i].write_to_pbmsg(*temp_info_lst);
	}
	for(int32_t i = 0; i < (int32_t)group_lst.size(); ++i) {
		::proto_ff::SkillDBGroup* temp_group_lst = msg.add_group_lst();
		group_lst[i].write_to_pbmsg(*temp_group_lst);
	}
	msg.set_group((uint32_t)group);
	msg.set_last_group((uint64_t)last_group);
	for(int32_t i = 0; i < (int32_t)adv_pos.size(); ++i) {
		::proto_ff::SkillDBAdvPos* temp_adv_pos = msg.add_adv_pos();
		adv_pos[i].write_to_pbmsg(*temp_adv_pos);
	}
	for(int32_t i = 0; i < (int32_t)adv_info.size(); ++i) {
		::proto_ff::SkillDBAdvInfo* temp_adv_info = msg.add_adv_info();
		adv_info[i].write_to_pbmsg(*temp_adv_info);
	}
	msg.set_cur_advpos((uint32_t)cur_advpos);
	for(int32_t i = 0; i < (int32_t)pet_cd.size(); ++i) {
		::proto_ff::PetSkillCdDB* temp_pet_cd = msg.add_pet_cd();
		pet_cd[i].write_to_pbmsg(*temp_pet_cd);
	}
}

void SkillDBData_s::read_from_pbmsg(const ::proto_ff::SkillDBData & msg) {
	info_lst.resize((int)msg.info_lst_size() > (int)info_lst.max_size() ? info_lst.max_size() : msg.info_lst_size());
	for(int32_t i = 0; i < (int32_t)info_lst.size(); ++i) {
		const ::proto_ff::SkillDBInfo & temp_info_lst = msg.info_lst(i);
		info_lst[i].read_from_pbmsg(temp_info_lst);
	}
	group_lst.resize((int)msg.group_lst_size() > (int)group_lst.max_size() ? group_lst.max_size() : msg.group_lst_size());
	for(int32_t i = 0; i < (int32_t)group_lst.size(); ++i) {
		const ::proto_ff::SkillDBGroup & temp_group_lst = msg.group_lst(i);
		group_lst[i].read_from_pbmsg(temp_group_lst);
	}
	group = msg.group();
	last_group = msg.last_group();
	adv_pos.resize((int)msg.adv_pos_size() > (int)adv_pos.max_size() ? adv_pos.max_size() : msg.adv_pos_size());
	for(int32_t i = 0; i < (int32_t)adv_pos.size(); ++i) {
		const ::proto_ff::SkillDBAdvPos & temp_adv_pos = msg.adv_pos(i);
		adv_pos[i].read_from_pbmsg(temp_adv_pos);
	}
	adv_info.resize((int)msg.adv_info_size() > (int)adv_info.max_size() ? adv_info.max_size() : msg.adv_info_size());
	for(int32_t i = 0; i < (int32_t)adv_info.size(); ++i) {
		const ::proto_ff::SkillDBAdvInfo & temp_adv_info = msg.adv_info(i);
		adv_info[i].read_from_pbmsg(temp_adv_info);
	}
	cur_advpos = msg.cur_advpos();
	pet_cd.resize((int)msg.pet_cd_size() > (int)pet_cd.max_size() ? pet_cd.max_size() : msg.pet_cd_size());
	for(int32_t i = 0; i < (int32_t)pet_cd.size(); ++i) {
		const ::proto_ff::PetSkillCdDB & temp_pet_cd = msg.pet_cd(i);
		pet_cd[i].read_from_pbmsg(temp_pet_cd);
	}
}

GodRelicsActivityData_s::GodRelicsActivityData_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int GodRelicsActivityData_s::CreateInit() {
	cur_group_id = (int64_t)0;
	return 0;
}

int GodRelicsActivityData_s::ResumeInit() {
	return 0;
}

void GodRelicsActivityData_s::write_to_pbmsg(::proto_ff::GodRelicsActivityData & msg) const {
	for(int32_t i = 0; i < (int32_t)group_data.size(); ++i) {
		::proto_ff::GodRelicsTaskGroupEntry* temp_group_data = msg.add_group_data();
		group_data[i].write_to_pbmsg(*temp_group_data);
	}
	msg.set_cur_group_id((int64_t)cur_group_id);
}

void GodRelicsActivityData_s::read_from_pbmsg(const ::proto_ff::GodRelicsActivityData & msg) {
	group_data.resize((int)msg.group_data_size() > (int)group_data.max_size() ? group_data.max_size() : msg.group_data_size());
	for(int32_t i = 0; i < (int32_t)group_data.size(); ++i) {
		const ::proto_ff::GodRelicsTaskGroupEntry & temp_group_data = msg.group_data(i);
		group_data[i].read_from_pbmsg(temp_group_data);
	}
	cur_group_id = msg.cur_group_id();
}

MiniActivityDBData_s::MiniActivityDBData_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int MiniActivityDBData_s::CreateInit() {
	return 0;
}

int MiniActivityDBData_s::ResumeInit() {
	return 0;
}

void MiniActivityDBData_s::write_to_pbmsg(::proto_ff::MiniActivityDBData & msg) const {
	::proto_ff::GodRelicsActivityData* temp_god_relics_data = msg.mutable_god_relics_data();
	god_relics_data.write_to_pbmsg(*temp_god_relics_data);
	::proto_ff::DailyTaskAllData* temp_daily_data = msg.mutable_daily_data();
	daily_data.write_to_pbmsg(*temp_daily_data);
}

void MiniActivityDBData_s::read_from_pbmsg(const ::proto_ff::MiniActivityDBData & msg) {
	const ::proto_ff::GodRelicsActivityData & temp_god_relics_data = msg.god_relics_data();
	god_relics_data.read_from_pbmsg(temp_god_relics_data);
	const ::proto_ff::DailyTaskAllData & temp_daily_data = msg.daily_data();
	daily_data.read_from_pbmsg(temp_daily_data);
}

DupRecord_s::DupRecord_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int DupRecord_s::CreateInit() {
	dupId = (uint64_t)0;
	star = (int32_t)0;
	return 0;
}

int DupRecord_s::ResumeInit() {
	return 0;
}

void DupRecord_s::write_to_pbmsg(::proto_ff::DupRecord & msg) const {
	msg.set_dupid((uint64_t)dupId);
	msg.set_star((int32_t)star);
}

void DupRecord_s::read_from_pbmsg(const ::proto_ff::DupRecord & msg) {
	dupId = msg.dupid();
	star = msg.star();
}

DupGroupData_s::DupGroupData_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int DupGroupData_s::CreateInit() {
	group = (int32_t)0;
	enterNum = (int32_t)0;
	buyNum = (int32_t)0;
	useNum = (int32_t)0;
	lastFresh = (uint64_t)0;
	return 0;
}

int DupGroupData_s::ResumeInit() {
	return 0;
}

void DupGroupData_s::write_to_pbmsg(::proto_ff::DupGroupData & msg) const {
	msg.set_group((int32_t)group);
	msg.set_enternum((int32_t)enterNum);
	msg.set_buynum((int32_t)buyNum);
	msg.set_usenum((int32_t)useNum);
	msg.set_lastfresh((uint64_t)lastFresh);
}

void DupGroupData_s::read_from_pbmsg(const ::proto_ff::DupGroupData & msg) {
	group = msg.group();
	enterNum = msg.enternum();
	buyNum = msg.buynum();
	useNum = msg.usenum();
	lastFresh = msg.lastfresh();
}

DupTowerDBRecordEntry_s::DupTowerDBRecordEntry_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int DupTowerDBRecordEntry_s::CreateInit() {
	time = (uint64_t)0;
	cid = (uint64_t)0;
	return 0;
}

int DupTowerDBRecordEntry_s::ResumeInit() {
	return 0;
}

void DupTowerDBRecordEntry_s::write_to_pbmsg(::proto_ff::DupTowerDBRecordEntry & msg) const {
	msg.set_name(name.data());
	msg.set_time((uint64_t)time);
	msg.set_cid((uint64_t)cid);
}

void DupTowerDBRecordEntry_s::read_from_pbmsg(const ::proto_ff::DupTowerDBRecordEntry & msg) {
	name = msg.name();
	time = msg.time();
	cid = msg.cid();
}

DupTowerDBRecord_s::DupTowerDBRecord_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int DupTowerDBRecord_s::CreateInit() {
	id = (uint64_t)0;
	return 0;
}

int DupTowerDBRecord_s::ResumeInit() {
	return 0;
}

void DupTowerDBRecord_s::write_to_pbmsg(::proto_ff::DupTowerDBRecord & msg) const {
	msg.set_id((uint64_t)id);
	for(int32_t i = 0; i < (int32_t)entrys.size(); ++i) {
		::proto_ff::DupTowerDBRecordEntry* temp_entrys = msg.add_entrys();
		entrys[i].write_to_pbmsg(*temp_entrys);
	}
}

void DupTowerDBRecord_s::read_from_pbmsg(const ::proto_ff::DupTowerDBRecord & msg) {
	id = msg.id();
	entrys.resize((int)msg.entrys_size() > (int)entrys.max_size() ? entrys.max_size() : msg.entrys_size());
	for(int32_t i = 0; i < (int32_t)entrys.size(); ++i) {
		const ::proto_ff::DupTowerDBRecordEntry & temp_entrys = msg.entrys(i);
		entrys[i].read_from_pbmsg(temp_entrys);
	}
}

DupTowerDBData_s::DupTowerDBData_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int DupTowerDBData_s::CreateInit() {
	return 0;
}

int DupTowerDBData_s::ResumeInit() {
	return 0;
}

void DupTowerDBData_s::write_to_pbmsg(::proto_ff::DupTowerDBData & msg) const {
	for(int32_t i = 0; i < (int32_t)ids.size(); ++i) {
		msg.add_ids((uint64_t)ids[i]);
	}
}

void DupTowerDBData_s::read_from_pbmsg(const ::proto_ff::DupTowerDBData & msg) {
	ids.resize((int)msg.ids_size() > (int)ids.max_size() ? ids.max_size() : msg.ids_size());
	for(int32_t i = 0; i < (int32_t)ids.size(); ++i) {
		ids[i] = msg.ids(i);
	}
}

DupDBData_s::DupDBData_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int DupDBData_s::CreateInit() {
	return 0;
}

int DupDBData_s::ResumeInit() {
	return 0;
}

void DupDBData_s::write_to_pbmsg(::proto_ff::DupDBData & msg) const {
	for(int32_t i = 0; i < (int32_t)record.size(); ++i) {
		::proto_ff::DupRecord* temp_record = msg.add_record();
		record[i].write_to_pbmsg(*temp_record);
	}
	for(int32_t i = 0; i < (int32_t)groups.size(); ++i) {
		::proto_ff::DupGroupData* temp_groups = msg.add_groups();
		groups[i].write_to_pbmsg(*temp_groups);
	}
	::proto_ff::DupTowerDBData* temp_tower = msg.mutable_tower();
	tower.write_to_pbmsg(*temp_tower);
}

void DupDBData_s::read_from_pbmsg(const ::proto_ff::DupDBData & msg) {
	record.resize((int)msg.record_size() > (int)record.max_size() ? record.max_size() : msg.record_size());
	for(int32_t i = 0; i < (int32_t)record.size(); ++i) {
		const ::proto_ff::DupRecord & temp_record = msg.record(i);
		record[i].read_from_pbmsg(temp_record);
	}
	groups.resize((int)msg.groups_size() > (int)groups.max_size() ? groups.max_size() : msg.groups_size());
	for(int32_t i = 0; i < (int32_t)groups.size(); ++i) {
		const ::proto_ff::DupGroupData & temp_groups = msg.groups(i);
		groups[i].read_from_pbmsg(temp_groups);
	}
	const ::proto_ff::DupTowerDBData & temp_tower = msg.tower();
	tower.read_from_pbmsg(temp_tower);
}

BuffDBInfo_s::BuffDBInfo_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int BuffDBInfo_s::CreateInit() {
	buffid = (uint64_t)0;
	index = (uint64_t)0;
	skillid = (uint64_t)0;
	skilllev = (uint32_t)0;
	is_forever = (bool)0;
	startmsec = (int64_t)0;
	is_effect = (bool)0;
	param1 = (int64_t)0;
	param2 = (int64_t)0;
	extramsec = (int64_t)0;
	is_end = (int32_t)0;
	return 0;
}

int BuffDBInfo_s::ResumeInit() {
	return 0;
}

void BuffDBInfo_s::write_to_pbmsg(::proto_ff::BuffDBInfo & msg) const {
	msg.set_buffid((uint64_t)buffid);
	msg.set_index((uint64_t)index);
	msg.set_skillid((uint64_t)skillid);
	msg.set_skilllev((uint32_t)skilllev);
	msg.set_is_forever((bool)is_forever);
	msg.set_startmsec((int64_t)startmsec);
	msg.set_is_effect((bool)is_effect);
	msg.set_param1((int64_t)param1);
	msg.set_param2((int64_t)param2);
	msg.set_extramsec((int64_t)extramsec);
	msg.set_is_end((int32_t)is_end);
}

void BuffDBInfo_s::read_from_pbmsg(const ::proto_ff::BuffDBInfo & msg) {
	buffid = msg.buffid();
	index = msg.index();
	skillid = msg.skillid();
	skilllev = msg.skilllev();
	is_forever = msg.is_forever();
	startmsec = msg.startmsec();
	is_effect = msg.is_effect();
	param1 = msg.param1();
	param2 = msg.param2();
	extramsec = msg.extramsec();
	is_end = msg.is_end();
}

BuffDBCdInfo_s::BuffDBCdInfo_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int BuffDBCdInfo_s::CreateInit() {
	buffid = (uint64_t)0;
	lastmsec = (uint64_t)0;
	return 0;
}

int BuffDBCdInfo_s::ResumeInit() {
	return 0;
}

void BuffDBCdInfo_s::write_to_pbmsg(::proto_ff::BuffDBCdInfo & msg) const {
	msg.set_buffid((uint64_t)buffid);
	msg.set_lastmsec((uint64_t)lastmsec);
}

void BuffDBCdInfo_s::read_from_pbmsg(const ::proto_ff::BuffDBCdInfo & msg) {
	buffid = msg.buffid();
	lastmsec = msg.lastmsec();
}

BuffDBData_s::BuffDBData_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int BuffDBData_s::CreateInit() {
	return 0;
}

int BuffDBData_s::ResumeInit() {
	return 0;
}

void BuffDBData_s::write_to_pbmsg(::proto_ff::BuffDBData & msg) const {
	for(int32_t i = 0; i < (int32_t)info_lst.size(); ++i) {
		::proto_ff::BuffDBInfo* temp_info_lst = msg.add_info_lst();
		info_lst[i].write_to_pbmsg(*temp_info_lst);
	}
	for(int32_t i = 0; i < (int32_t)cd_lst.size(); ++i) {
		::proto_ff::BuffDBCdInfo* temp_cd_lst = msg.add_cd_lst();
		cd_lst[i].write_to_pbmsg(*temp_cd_lst);
	}
}

void BuffDBData_s::read_from_pbmsg(const ::proto_ff::BuffDBData & msg) {
	info_lst.resize((int)msg.info_lst_size() > (int)info_lst.max_size() ? info_lst.max_size() : msg.info_lst_size());
	for(int32_t i = 0; i < (int32_t)info_lst.size(); ++i) {
		const ::proto_ff::BuffDBInfo & temp_info_lst = msg.info_lst(i);
		info_lst[i].read_from_pbmsg(temp_info_lst);
	}
	cd_lst.resize((int)msg.cd_lst_size() > (int)cd_lst.max_size() ? cd_lst.max_size() : msg.cd_lst_size());
	for(int32_t i = 0; i < (int32_t)cd_lst.size(); ++i) {
		const ::proto_ff::BuffDBCdInfo & temp_cd_lst = msg.cd_lst(i);
		cd_lst[i].read_from_pbmsg(temp_cd_lst);
	}
}

BossSimpleInfoDB_s::BossSimpleInfoDB_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int BossSimpleInfoDB_s::CreateInit() {
	boss_type = (int32_t)0;
	cur_num = (int32_t)0;
	back_num = (int32_t)0;
	back_max_num = (int32_t)0;
	enter_num = (int32_t)0;
	use_item_num = (int32_t)0;
	return 0;
}

int BossSimpleInfoDB_s::ResumeInit() {
	return 0;
}

void BossSimpleInfoDB_s::write_to_pbmsg(::proto_ff::BossSimpleInfoDB & msg) const {
	msg.set_boss_type((int32_t)boss_type);
	msg.set_cur_num((int32_t)cur_num);
	msg.set_back_num((int32_t)back_num);
	msg.set_back_max_num((int32_t)back_max_num);
	msg.set_enter_num((int32_t)enter_num);
	msg.set_use_item_num((int32_t)use_item_num);
}

void BossSimpleInfoDB_s::read_from_pbmsg(const ::proto_ff::BossSimpleInfoDB & msg) {
	boss_type = msg.boss_type();
	cur_num = msg.cur_num();
	back_num = msg.back_num();
	back_max_num = msg.back_max_num();
	enter_num = msg.enter_num();
	use_item_num = msg.use_item_num();
}

BossDBData_s::BossDBData_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int BossDBData_s::CreateInit() {
	lastTime = (uint64_t)0;
	return 0;
}

int BossDBData_s::ResumeInit() {
	return 0;
}

void BossDBData_s::write_to_pbmsg(::proto_ff::BossDBData & msg) const {
	for(int32_t i = 0; i < (int32_t)infos.size(); ++i) {
		::proto_ff::BossSimpleInfoDB* temp_infos = msg.add_infos();
		infos[i].write_to_pbmsg(*temp_infos);
	}
	msg.set_lasttime((uint64_t)lastTime);
	for(int32_t i = 0; i < (int32_t)attents.size(); ++i) {
		msg.add_attents((int64_t)attents[i]);
	}
}

void BossDBData_s::read_from_pbmsg(const ::proto_ff::BossDBData & msg) {
	infos.resize((int)msg.infos_size() > (int)infos.max_size() ? infos.max_size() : msg.infos_size());
	for(int32_t i = 0; i < (int32_t)infos.size(); ++i) {
		const ::proto_ff::BossSimpleInfoDB & temp_infos = msg.infos(i);
		infos[i].read_from_pbmsg(temp_infos);
	}
	lastTime = msg.lasttime();
	attents.resize((int)msg.attents_size() > (int)attents.max_size() ? attents.max_size() : msg.attents_size());
	for(int32_t i = 0; i < (int32_t)attents.size(); ++i) {
		attents[i] = msg.attents(i);
	}
}

VipDBData_s::VipDBData_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int VipDBData_s::CreateInit() {
	vipExp = (int32_t)0;
	expDiamond = (int32_t)0;
	return 0;
}

int VipDBData_s::ResumeInit() {
	return 0;
}

void VipDBData_s::write_to_pbmsg(::proto_ff::VipDBData & msg) const {
	msg.set_vipexp((int32_t)vipExp);
	msg.set_expdiamond((int32_t)expDiamond);
}

void VipDBData_s::read_from_pbmsg(const ::proto_ff::VipDBData & msg) {
	vipExp = msg.vipexp();
	expDiamond = msg.expdiamond();
}

AttrDBData_s::AttrDBData_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int AttrDBData_s::CreateInit() {
	return 0;
}

int AttrDBData_s::ResumeInit() {
	return 0;
}

void AttrDBData_s::write_to_pbmsg(::proto_ff::AttrDBData & msg) const {
	for(int32_t i = 0; i < (int32_t)attr_lst.size(); ++i) {
		::proto_ff::Attr64* temp_attr_lst = msg.add_attr_lst();
		attr_lst[i].write_to_pbmsg(*temp_attr_lst);
	}
}

void AttrDBData_s::read_from_pbmsg(const ::proto_ff::AttrDBData & msg) {
	attr_lst.resize((int)msg.attr_lst_size() > (int)attr_lst.max_size() ? attr_lst.max_size() : msg.attr_lst_size());
	for(int32_t i = 0; i < (int32_t)attr_lst.size(); ++i) {
		const ::proto_ff::Attr64 & temp_attr_lst = msg.attr_lst(i);
		attr_lst[i].read_from_pbmsg(temp_attr_lst);
	}
}

PetDBRecord_s::PetDBRecord_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int PetDBRecord_s::CreateInit() {
	instId = (int32_t)0;
	return 0;
}

int PetDBRecord_s::ResumeInit() {
	return 0;
}

void PetDBRecord_s::write_to_pbmsg(::proto_ff::PetDBRecord & msg) const {
	msg.set_instid((int32_t)instId);
	for(int32_t i = 0; i < (int32_t)costItem.size(); ++i) {
		::proto_ff::ComPair64* temp_costitem = msg.add_costitem();
		costItem[i].write_to_pbmsg(*temp_costitem);
	}
	for(int32_t i = 0; i < (int32_t)costPet.size(); ++i) {
		::proto_ff::ComPair64* temp_costpet = msg.add_costpet();
		costPet[i].write_to_pbmsg(*temp_costpet);
	}
}

void PetDBRecord_s::read_from_pbmsg(const ::proto_ff::PetDBRecord & msg) {
	instId = msg.instid();
	costItem.resize((int)msg.costitem_size() > (int)costItem.max_size() ? costItem.max_size() : msg.costitem_size());
	for(int32_t i = 0; i < (int32_t)costItem.size(); ++i) {
		const ::proto_ff::ComPair64 & temp_costitem = msg.costitem(i);
		costItem[i].read_from_pbmsg(temp_costitem);
	}
	costPet.resize((int)msg.costpet_size() > (int)costPet.max_size() ? costPet.max_size() : msg.costpet_size());
	for(int32_t i = 0; i < (int32_t)costPet.size(); ++i) {
		const ::proto_ff::ComPair64 & temp_costpet = msg.costpet(i);
		costPet[i].read_from_pbmsg(temp_costpet);
	}
}

PetDBData_s::PetDBData_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int PetDBData_s::CreateInit() {
	return 0;
}

int PetDBData_s::ResumeInit() {
	return 0;
}

void PetDBData_s::write_to_pbmsg(::proto_ff::PetDBData & msg) const {
	for(int32_t i = 0; i < (int32_t)fetter.size(); ++i) {
		msg.add_fetter((int32_t)fetter[i]);
	}
	for(int32_t i = 0; i < (int32_t)pets.size(); ++i) {
		::proto_ff::PetInfo* temp_pets = msg.add_pets();
		pets[i].write_to_pbmsg(*temp_pets);
	}
	for(int32_t i = 0; i < (int32_t)hatchs.size(); ++i) {
		::proto_ff::PetHatchInfo* temp_hatchs = msg.add_hatchs();
		hatchs[i].write_to_pbmsg(*temp_hatchs);
	}
	for(int32_t i = 0; i < (int32_t)records.size(); ++i) {
		::proto_ff::PetDBRecord* temp_records = msg.add_records();
		records[i].write_to_pbmsg(*temp_records);
	}
	for(int32_t i = 0; i < (int32_t)cfgids.size(); ++i) {
		msg.add_cfgids((int64_t)cfgids[i]);
	}
}

void PetDBData_s::read_from_pbmsg(const ::proto_ff::PetDBData & msg) {
	fetter.resize((int)msg.fetter_size() > (int)fetter.max_size() ? fetter.max_size() : msg.fetter_size());
	for(int32_t i = 0; i < (int32_t)fetter.size(); ++i) {
		fetter[i] = msg.fetter(i);
	}
	pets.resize((int)msg.pets_size() > (int)pets.max_size() ? pets.max_size() : msg.pets_size());
	for(int32_t i = 0; i < (int32_t)pets.size(); ++i) {
		const ::proto_ff::PetInfo & temp_pets = msg.pets(i);
		pets[i].read_from_pbmsg(temp_pets);
	}
	hatchs.resize((int)msg.hatchs_size() > (int)hatchs.max_size() ? hatchs.max_size() : msg.hatchs_size());
	for(int32_t i = 0; i < (int32_t)hatchs.size(); ++i) {
		const ::proto_ff::PetHatchInfo & temp_hatchs = msg.hatchs(i);
		hatchs[i].read_from_pbmsg(temp_hatchs);
	}
	records.resize((int)msg.records_size() > (int)records.max_size() ? records.max_size() : msg.records_size());
	for(int32_t i = 0; i < (int32_t)records.size(); ++i) {
		const ::proto_ff::PetDBRecord & temp_records = msg.records(i);
		records[i].read_from_pbmsg(temp_records);
	}
	cfgids.resize((int)msg.cfgids_size() > (int)cfgids.max_size() ? cfgids.max_size() : msg.cfgids_size());
	for(int32_t i = 0; i < (int32_t)cfgids.size(); ++i) {
		cfgids[i] = msg.cfgids(i);
	}
}

MallDBInfo_s::MallDBInfo_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int MallDBInfo_s::CreateInit() {
	id = (int64_t)0;
	num = (uint32_t)0;
	time = (uint64_t)0;
	return 0;
}

int MallDBInfo_s::ResumeInit() {
	return 0;
}

void MallDBInfo_s::write_to_pbmsg(::proto_ff::MallDBInfo & msg) const {
	msg.set_id((int64_t)id);
	msg.set_num((uint32_t)num);
	msg.set_time((uint64_t)time);
}

void MallDBInfo_s::read_from_pbmsg(const ::proto_ff::MallDBInfo & msg) {
	id = msg.id();
	num = msg.num();
	time = msg.time();
}

MallDBData_s::MallDBData_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int MallDBData_s::CreateInit() {
	return 0;
}

int MallDBData_s::ResumeInit() {
	return 0;
}

void MallDBData_s::write_to_pbmsg(::proto_ff::MallDBData & msg) const {
	for(int32_t i = 0; i < (int32_t)day.size(); ++i) {
		::proto_ff::MallDBInfo* temp_day = msg.add_day();
		day[i].write_to_pbmsg(*temp_day);
	}
	for(int32_t i = 0; i < (int32_t)week.size(); ++i) {
		::proto_ff::MallDBInfo* temp_week = msg.add_week();
		week[i].write_to_pbmsg(*temp_week);
	}
	for(int32_t i = 0; i < (int32_t)forever.size(); ++i) {
		::proto_ff::MallDBInfo* temp_forever = msg.add_forever();
		forever[i].write_to_pbmsg(*temp_forever);
	}
}

void MallDBData_s::read_from_pbmsg(const ::proto_ff::MallDBData & msg) {
	day.resize((int)msg.day_size() > (int)day.max_size() ? day.max_size() : msg.day_size());
	for(int32_t i = 0; i < (int32_t)day.size(); ++i) {
		const ::proto_ff::MallDBInfo & temp_day = msg.day(i);
		day[i].read_from_pbmsg(temp_day);
	}
	week.resize((int)msg.week_size() > (int)week.max_size() ? week.max_size() : msg.week_size());
	for(int32_t i = 0; i < (int32_t)week.size(); ++i) {
		const ::proto_ff::MallDBInfo & temp_week = msg.week(i);
		week[i].read_from_pbmsg(temp_week);
	}
	forever.resize((int)msg.forever_size() > (int)forever.max_size() ? forever.max_size() : msg.forever_size());
	for(int32_t i = 0; i < (int32_t)forever.size(); ++i) {
		const ::proto_ff::MallDBInfo & temp_forever = msg.forever(i);
		forever[i].read_from_pbmsg(temp_forever);
	}
}

ConvoyData_s::ConvoyData_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int ConvoyData_s::CreateInit() {
	daynum = (int32_t)0;
	escortid = (int32_t)0;
	endTime = (uint64_t)0;
	freeNum = (int32_t)0;
	genEscortId = (int32_t)0;
	resetTime = (uint64_t)0;
	return 0;
}

int ConvoyData_s::ResumeInit() {
	return 0;
}

void ConvoyData_s::write_to_pbmsg(::proto_ff::ConvoyData & msg) const {
	msg.set_daynum((int32_t)daynum);
	msg.set_escortid((int32_t)escortid);
	msg.set_endtime((uint64_t)endTime);
	msg.set_freenum((int32_t)freeNum);
	msg.set_genescortid((int32_t)genEscortId);
	msg.set_resettime((uint64_t)resetTime);
}

void ConvoyData_s::read_from_pbmsg(const ::proto_ff::ConvoyData & msg) {
	daynum = msg.daynum();
	escortid = msg.escortid();
	endTime = msg.endtime();
	freeNum = msg.freenum();
	genEscortId = msg.genescortid();
	resetTime = msg.resettime();
}

ArmorDBData_s::ArmorDBData_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int ArmorDBData_s::CreateInit() {
	return 0;
}

int ArmorDBData_s::ResumeInit() {
	return 0;
}

void ArmorDBData_s::write_to_pbmsg(::proto_ff::ArmorDBData & msg) const {
	for(int32_t i = 0; i < (int32_t)infos.size(); ++i) {
		::proto_ff::ArmorInfo* temp_infos = msg.add_infos();
		infos[i].write_to_pbmsg(*temp_infos);
	}
}

void ArmorDBData_s::read_from_pbmsg(const ::proto_ff::ArmorDBData & msg) {
	infos.resize((int)msg.infos_size() > (int)infos.max_size() ? infos.max_size() : msg.infos_size());
	for(int32_t i = 0; i < (int32_t)infos.size(); ++i) {
		const ::proto_ff::ArmorInfo & temp_infos = msg.infos(i);
		infos[i].read_from_pbmsg(temp_infos);
	}
}

AssistDBData_s::AssistDBData_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int AssistDBData_s::CreateInit() {
	resetTime = (uint64_t)0;
	dayPrestige = (int32_t)0;
	sendNum = (int32_t)0;
	helpNum = (int32_t)0;
	allSendNum = (int32_t)0;
	allHelpNum = (int32_t)0;
	recvSendGiftNum = (int32_t)0;
	recvHelpGiftNum = (int32_t)0;
	return 0;
}

int AssistDBData_s::ResumeInit() {
	return 0;
}

void AssistDBData_s::write_to_pbmsg(::proto_ff::AssistDBData & msg) const {
	msg.set_resettime((uint64_t)resetTime);
	msg.set_dayprestige((int32_t)dayPrestige);
	msg.set_sendnum((int32_t)sendNum);
	msg.set_helpnum((int32_t)helpNum);
	msg.set_allsendnum((int32_t)allSendNum);
	msg.set_allhelpnum((int32_t)allHelpNum);
	msg.set_recvsendgiftnum((int32_t)recvSendGiftNum);
	msg.set_recvhelpgiftnum((int32_t)recvHelpGiftNum);
	for(int32_t i = 0; i < (int32_t)rewardIds.size(); ++i) {
		msg.add_rewardids((int32_t)rewardIds[i]);
	}
	for(int32_t i = 0; i < (int32_t)thanksInfo.size(); ++i) {
		::proto_ff::ComPair64* temp_thanksinfo = msg.add_thanksinfo();
		thanksInfo[i].write_to_pbmsg(*temp_thanksinfo);
	}
}

void AssistDBData_s::read_from_pbmsg(const ::proto_ff::AssistDBData & msg) {
	resetTime = msg.resettime();
	dayPrestige = msg.dayprestige();
	sendNum = msg.sendnum();
	helpNum = msg.helpnum();
	allSendNum = msg.allsendnum();
	allHelpNum = msg.allhelpnum();
	recvSendGiftNum = msg.recvsendgiftnum();
	recvHelpGiftNum = msg.recvhelpgiftnum();
	rewardIds.resize((int)msg.rewardids_size() > (int)rewardIds.max_size() ? rewardIds.max_size() : msg.rewardids_size());
	for(int32_t i = 0; i < (int32_t)rewardIds.size(); ++i) {
		rewardIds[i] = msg.rewardids(i);
	}
	thanksInfo.resize((int)msg.thanksinfo_size() > (int)thanksInfo.max_size() ? thanksInfo.max_size() : msg.thanksinfo_size());
	for(int32_t i = 0; i < (int32_t)thanksInfo.size(); ++i) {
		const ::proto_ff::ComPair64 & temp_thanksinfo = msg.thanksinfo(i);
		thanksInfo[i].read_from_pbmsg(temp_thanksinfo);
	}
}

TitleDBData_s::TitleDBData_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int TitleDBData_s::CreateInit() {
	cur_wearing_title = (uint64_t)0;
	return 0;
}

int TitleDBData_s::ResumeInit() {
	return 0;
}

void TitleDBData_s::write_to_pbmsg(::proto_ff::TitleDBData & msg) const {
	msg.set_cur_wearing_title((uint64_t)cur_wearing_title);
	for(int32_t i = 0; i < (int32_t)data.size(); ++i) {
		::proto_ff::TitleInfo* temp_data = msg.add_data();
		data[i].write_to_pbmsg(*temp_data);
	}
}

void TitleDBData_s::read_from_pbmsg(const ::proto_ff::TitleDBData & msg) {
	cur_wearing_title = msg.cur_wearing_title();
	data.resize((int)msg.data_size() > (int)data.max_size() ? data.max_size() : msg.data_size());
	for(int32_t i = 0; i < (int32_t)data.size(); ++i) {
		const ::proto_ff::TitleInfo & temp_data = msg.data(i);
		data[i].read_from_pbmsg(temp_data);
	}
}

GodEvilCondDBProto_s::GodEvilCondDBProto_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int GodEvilCondDBProto_s::CreateInit() {
	id = (int32_t)0;
	state = (int32_t)0;
	cur = (int32_t)0;
	return 0;
}

int GodEvilCondDBProto_s::ResumeInit() {
	return 0;
}

void GodEvilCondDBProto_s::write_to_pbmsg(::proto_ff::GodEvilCondDBProto & msg) const {
	msg.set_id((int32_t)id);
	msg.set_state((int32_t)state);
	msg.set_cur((int32_t)cur);
}

void GodEvilCondDBProto_s::read_from_pbmsg(const ::proto_ff::GodEvilCondDBProto & msg) {
	id = msg.id();
	state = msg.state();
	cur = msg.cur();
}

GodEvilMultCondDBProto_s::GodEvilMultCondDBProto_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int GodEvilMultCondDBProto_s::CreateInit() {
	return 0;
}

int GodEvilMultCondDBProto_s::ResumeInit() {
	return 0;
}

void GodEvilMultCondDBProto_s::write_to_pbmsg(::proto_ff::GodEvilMultCondDBProto & msg) const {
	for(int32_t i = 0; i < (int32_t)lst.size(); ++i) {
		::proto_ff::GodEvilCondDBProto* temp_lst = msg.add_lst();
		lst[i].write_to_pbmsg(*temp_lst);
	}
}

void GodEvilMultCondDBProto_s::read_from_pbmsg(const ::proto_ff::GodEvilMultCondDBProto & msg) {
	lst.resize((int)msg.lst_size() > (int)lst.max_size() ? lst.max_size() : msg.lst_size());
	for(int32_t i = 0; i < (int32_t)lst.size(); ++i) {
		const ::proto_ff::GodEvilCondDBProto & temp_lst = msg.lst(i);
		lst[i].read_from_pbmsg(temp_lst);
	}
}

GodEvilTaskDBProto_s::GodEvilTaskDBProto_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int GodEvilTaskDBProto_s::CreateInit() {
	stage = (int32_t)0;
	finish = (int32_t)0;
	accept = (int32_t)0;
	return 0;
}

int GodEvilTaskDBProto_s::ResumeInit() {
	return 0;
}

void GodEvilTaskDBProto_s::write_to_pbmsg(::proto_ff::GodEvilTaskDBProto & msg) const {
	msg.set_stage((int32_t)stage);
	::proto_ff::GodEvilMultCondDBProto* temp_cond = msg.mutable_cond();
	cond.write_to_pbmsg(*temp_cond);
	msg.set_finish((int32_t)finish);
	msg.set_accept((int32_t)accept);
}

void GodEvilTaskDBProto_s::read_from_pbmsg(const ::proto_ff::GodEvilTaskDBProto & msg) {
	stage = msg.stage();
	const ::proto_ff::GodEvilMultCondDBProto & temp_cond = msg.cond();
	cond.read_from_pbmsg(temp_cond);
	finish = msg.finish();
	accept = msg.accept();
}

GodEvilDBData_s::GodEvilDBData_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int GodEvilDBData_s::CreateInit() {
	fetch = (int32_t)0;
	type = (int32_t)0;
	last_time = (uint64_t)0;
	vessel_lev = (int32_t)0;
	mirror_lev = (int32_t)0;
	extra_exp = (int64_t)0;
	return 0;
}

int GodEvilDBData_s::ResumeInit() {
	return 0;
}

void GodEvilDBData_s::write_to_pbmsg(::proto_ff::GodEvilDBData & msg) const {
	msg.set_fetch((int32_t)fetch);
	::proto_ff::GodEvilTaskDBProto* temp_task = msg.mutable_task();
	task.write_to_pbmsg(*temp_task);
	msg.set_type((int32_t)type);
	msg.set_last_time((uint64_t)last_time);
	msg.set_vessel_lev((int32_t)vessel_lev);
	msg.set_mirror_lev((int32_t)mirror_lev);
	msg.set_extra_exp((int64_t)extra_exp);
}

void GodEvilDBData_s::read_from_pbmsg(const ::proto_ff::GodEvilDBData & msg) {
	fetch = msg.fetch();
	const ::proto_ff::GodEvilTaskDBProto & temp_task = msg.task();
	task.read_from_pbmsg(temp_task);
	type = msg.type();
	last_time = msg.last_time();
	vessel_lev = msg.vessel_lev();
	mirror_lev = msg.mirror_lev();
	extra_exp = msg.extra_exp();
}

PayDBData_s::PayDBData_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int PayDBData_s::CreateInit() {
	relrmb = (uint32_t)0;
	rmb = (uint32_t)0;
	fakermb = (uint32_t)0;
	todayrmb = (uint32_t)0;
	todaytime = (uint64_t)0;
	return 0;
}

int PayDBData_s::ResumeInit() {
	return 0;
}

void PayDBData_s::write_to_pbmsg(::proto_ff::PayDBData & msg) const {
	for(int32_t i = 0; i < (int32_t)db_id.size(); ++i) {
		msg.add_db_id((uint32_t)db_id[i]);
	}
	for(int32_t i = 0; i < (int32_t)product.size(); ++i) {
		msg.add_product(product[i].data());
	}
	msg.set_relrmb((uint32_t)relrmb);
	msg.set_rmb((uint32_t)rmb);
	msg.set_fakermb((uint32_t)fakermb);
	msg.set_todayrmb((uint32_t)todayrmb);
	msg.set_todaytime((uint64_t)todaytime);
}

void PayDBData_s::read_from_pbmsg(const ::proto_ff::PayDBData & msg) {
	db_id.resize((int)msg.db_id_size() > (int)db_id.max_size() ? db_id.max_size() : msg.db_id_size());
	for(int32_t i = 0; i < (int32_t)db_id.size(); ++i) {
		db_id[i] = msg.db_id(i);
	}
	product.resize((int)msg.product_size() > (int)product.max_size() ? product.max_size() : msg.product_size());
	for(int32_t i = 0; i < (int32_t)product.size(); ++i) {
		product[i] = msg.product(i);
	}
	relrmb = msg.relrmb();
	rmb = msg.rmb();
	fakermb = msg.fakermb();
	todayrmb = msg.todayrmb();
	todaytime = msg.todaytime();
}

FactionDBSalary_s::FactionDBSalary_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int FactionDBSalary_s::CreateInit() {
	id = (int32_t)0;
	cur = (int32_t)0;
	fetch = (int32_t)0;
	return 0;
}

int FactionDBSalary_s::ResumeInit() {
	return 0;
}

void FactionDBSalary_s::write_to_pbmsg(::proto_ff::FactionDBSalary & msg) const {
	msg.set_id((int32_t)id);
	msg.set_cur((int32_t)cur);
	msg.set_fetch((int32_t)fetch);
}

void FactionDBSalary_s::read_from_pbmsg(const ::proto_ff::FactionDBSalary & msg) {
	id = msg.id();
	cur = msg.cur();
	fetch = msg.fetch();
}

RoleFactionDBData_s::RoleFactionDBData_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int RoleFactionDBData_s::CreateInit() {
	donate_num = (int32_t)0;
	donate_fresh = (uint64_t)0;
	salary_fresh = (uint64_t)0;
	return 0;
}

int RoleFactionDBData_s::ResumeInit() {
	return 0;
}

void RoleFactionDBData_s::write_to_pbmsg(::proto_ff::RoleFactionDBData & msg) const {
	msg.set_donate_num((int32_t)donate_num);
	msg.set_donate_fresh((uint64_t)donate_fresh);
	for(int32_t i = 0; i < (int32_t)salary.size(); ++i) {
		::proto_ff::FactionDBSalary* temp_salary = msg.add_salary();
		salary[i].write_to_pbmsg(*temp_salary);
	}
	msg.set_salary_fresh((uint64_t)salary_fresh);
}

void RoleFactionDBData_s::read_from_pbmsg(const ::proto_ff::RoleFactionDBData & msg) {
	donate_num = msg.donate_num();
	donate_fresh = msg.donate_fresh();
	salary.resize((int)msg.salary_size() > (int)salary.max_size() ? salary.max_size() : msg.salary_size());
	for(int32_t i = 0; i < (int32_t)salary.size(); ++i) {
		const ::proto_ff::FactionDBSalary & temp_salary = msg.salary(i);
		salary[i].read_from_pbmsg(temp_salary);
	}
	salary_fresh = msg.salary_fresh();
}

RoleBestEQDBData_s::RoleBestEQDBData_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int RoleBestEQDBData_s::CreateInit() {
	return 0;
}

int RoleBestEQDBData_s::ResumeInit() {
	return 0;
}

void RoleBestEQDBData_s::write_to_pbmsg(::proto_ff::RoleBestEQDBData & msg) const {
	for(int32_t i = 0; i < (int32_t)equips.size(); ++i) {
		::proto_ff::BestEQEquipInfo* temp_equips = msg.add_equips();
		equips[i].write_to_pbmsg(*temp_equips);
	}
	for(int32_t i = 0; i < (int32_t)slots.size(); ++i) {
		::proto_ff::BestEQSlotInfo* temp_slots = msg.add_slots();
		slots[i].write_to_pbmsg(*temp_slots);
	}
	for(int32_t i = 0; i < (int32_t)tasks.size(); ++i) {
		::proto_ff::BestEQTask* temp_tasks = msg.add_tasks();
		tasks[i].write_to_pbmsg(*temp_tasks);
	}
}

void RoleBestEQDBData_s::read_from_pbmsg(const ::proto_ff::RoleBestEQDBData & msg) {
	equips.resize((int)msg.equips_size() > (int)equips.max_size() ? equips.max_size() : msg.equips_size());
	for(int32_t i = 0; i < (int32_t)equips.size(); ++i) {
		const ::proto_ff::BestEQEquipInfo & temp_equips = msg.equips(i);
		equips[i].read_from_pbmsg(temp_equips);
	}
	slots.resize((int)msg.slots_size() > (int)slots.max_size() ? slots.max_size() : msg.slots_size());
	for(int32_t i = 0; i < (int32_t)slots.size(); ++i) {
		const ::proto_ff::BestEQSlotInfo & temp_slots = msg.slots(i);
		slots[i].read_from_pbmsg(temp_slots);
	}
	tasks.resize((int)msg.tasks_size() > (int)tasks.max_size() ? tasks.max_size() : msg.tasks_size());
	for(int32_t i = 0; i < (int32_t)tasks.size(); ++i) {
		const ::proto_ff::BestEQTask & temp_tasks = msg.tasks(i);
		tasks[i].read_from_pbmsg(temp_tasks);
	}
}

RoleDBData_s::RoleDBData_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int RoleDBData_s::CreateInit() {
	cid = (uint64_t)0;
	zid = (uint32_t)0;
	uid = (uint32_t)0;
	return 0;
}

int RoleDBData_s::ResumeInit() {
	return 0;
}

void RoleDBData_s::write_to_pbmsg(::proto_ff::RoleDBData & msg) const {
	msg.set_cid((uint64_t)cid);
	msg.set_zid((uint32_t)zid);
	msg.set_uid((uint32_t)uid);
	::proto_ff::RoleDBBaseData* temp_base = msg.mutable_base();
	base.write_to_pbmsg(*temp_base);
	::proto_ff::RoleDBBagData* temp_bag = msg.mutable_bag();
	bag.write_to_pbmsg(*temp_bag);
	::proto_ff::RoleDBEquipData* temp_equip = msg.mutable_equip();
	equip.write_to_pbmsg(*temp_equip);
	::proto_ff::CharacterDBTaskData* temp_task = msg.mutable_task();
	task.write_to_pbmsg(*temp_task);
	::proto_ff::FunctionUnlockInfo* temp_unlockinfo = msg.mutable_unlockinfo();
	unlockinfo.write_to_pbmsg(*temp_unlockinfo);
	::proto_ff::GrowDBData* temp_grow = msg.mutable_grow();
	grow.write_to_pbmsg(*temp_grow);
	::proto_ff::MiniDBData* temp_mini = msg.mutable_mini();
	mini.write_to_pbmsg(*temp_mini);
	::proto_ff::FacadeDBData* temp_facade = msg.mutable_facade();
	facade.write_to_pbmsg(*temp_facade);
	::proto_ff::SkillDBData* temp_skill = msg.mutable_skill();
	skill.write_to_pbmsg(*temp_skill);
	::proto_ff::MiniActivityDBData* temp_mini_activity = msg.mutable_mini_activity();
	mini_activity.write_to_pbmsg(*temp_mini_activity);
	::proto_ff::DupDBData* temp_dup = msg.mutable_dup();
	dup.write_to_pbmsg(*temp_dup);
	::proto_ff::BuffDBData* temp_buff = msg.mutable_buff();
	buff.write_to_pbmsg(*temp_buff);
	::proto_ff::BossDBData* temp_boss = msg.mutable_boss();
	boss.write_to_pbmsg(*temp_boss);
	::proto_ff::VipDBData* temp_vip = msg.mutable_vip();
	vip.write_to_pbmsg(*temp_vip);
	::proto_ff::AttrDBData* temp_attr = msg.mutable_attr();
	attr.write_to_pbmsg(*temp_attr);
	::proto_ff::MountDataInfo* temp_mount = msg.mutable_mount();
	mount.write_to_pbmsg(*temp_mount);
	::proto_ff::DeityDataInfo* temp_deity = msg.mutable_deity();
	deity.write_to_pbmsg(*temp_deity);
	::proto_ff::PetDBData* temp_pet = msg.mutable_pet();
	pet.write_to_pbmsg(*temp_pet);
	::proto_ff::MallDBData* temp_mall = msg.mutable_mall();
	mall.write_to_pbmsg(*temp_mall);
	::proto_ff::ConvoyData* temp_convoy = msg.mutable_convoy();
	convoy.write_to_pbmsg(*temp_convoy);
	::proto_ff::ArmorDBData* temp_armor = msg.mutable_armor();
	armor.write_to_pbmsg(*temp_armor);
	::proto_ff::AssistDBData* temp_assist = msg.mutable_assist();
	assist.write_to_pbmsg(*temp_assist);
	::proto_ff::TitleDBData* temp_title = msg.mutable_title();
	title.write_to_pbmsg(*temp_title);
	::proto_ff::GodEvilDBData* temp_godevil = msg.mutable_godevil();
	godevil.write_to_pbmsg(*temp_godevil);
	::proto_ff::OccupationMissionData* temp_occupatoin = msg.mutable_occupatoin();
	occupatoin.write_to_pbmsg(*temp_occupatoin);
	::proto_ff::PayDBData* temp_pay = msg.mutable_pay();
	pay.write_to_pbmsg(*temp_pay);
	::proto_ff::RoleFactionDBData* temp_role_faction = msg.mutable_role_faction();
	role_faction.write_to_pbmsg(*temp_role_faction);
	::proto_ff::RoleBestEQDBData* temp_best_equip = msg.mutable_best_equip();
	best_equip.write_to_pbmsg(*temp_best_equip);
}

void RoleDBData_s::read_from_pbmsg(const ::proto_ff::RoleDBData & msg) {
	cid = msg.cid();
	zid = msg.zid();
	uid = msg.uid();
	const ::proto_ff::RoleDBBaseData & temp_base = msg.base();
	base.read_from_pbmsg(temp_base);
	const ::proto_ff::RoleDBBagData & temp_bag = msg.bag();
	bag.read_from_pbmsg(temp_bag);
	const ::proto_ff::RoleDBEquipData & temp_equip = msg.equip();
	equip.read_from_pbmsg(temp_equip);
	const ::proto_ff::CharacterDBTaskData & temp_task = msg.task();
	task.read_from_pbmsg(temp_task);
	const ::proto_ff::FunctionUnlockInfo & temp_unlockinfo = msg.unlockinfo();
	unlockinfo.read_from_pbmsg(temp_unlockinfo);
	const ::proto_ff::GrowDBData & temp_grow = msg.grow();
	grow.read_from_pbmsg(temp_grow);
	const ::proto_ff::MiniDBData & temp_mini = msg.mini();
	mini.read_from_pbmsg(temp_mini);
	const ::proto_ff::FacadeDBData & temp_facade = msg.facade();
	facade.read_from_pbmsg(temp_facade);
	const ::proto_ff::SkillDBData & temp_skill = msg.skill();
	skill.read_from_pbmsg(temp_skill);
	const ::proto_ff::MiniActivityDBData & temp_mini_activity = msg.mini_activity();
	mini_activity.read_from_pbmsg(temp_mini_activity);
	const ::proto_ff::DupDBData & temp_dup = msg.dup();
	dup.read_from_pbmsg(temp_dup);
	const ::proto_ff::BuffDBData & temp_buff = msg.buff();
	buff.read_from_pbmsg(temp_buff);
	const ::proto_ff::BossDBData & temp_boss = msg.boss();
	boss.read_from_pbmsg(temp_boss);
	const ::proto_ff::VipDBData & temp_vip = msg.vip();
	vip.read_from_pbmsg(temp_vip);
	const ::proto_ff::AttrDBData & temp_attr = msg.attr();
	attr.read_from_pbmsg(temp_attr);
	const ::proto_ff::MountDataInfo & temp_mount = msg.mount();
	mount.read_from_pbmsg(temp_mount);
	const ::proto_ff::DeityDataInfo & temp_deity = msg.deity();
	deity.read_from_pbmsg(temp_deity);
	const ::proto_ff::PetDBData & temp_pet = msg.pet();
	pet.read_from_pbmsg(temp_pet);
	const ::proto_ff::MallDBData & temp_mall = msg.mall();
	mall.read_from_pbmsg(temp_mall);
	const ::proto_ff::ConvoyData & temp_convoy = msg.convoy();
	convoy.read_from_pbmsg(temp_convoy);
	const ::proto_ff::ArmorDBData & temp_armor = msg.armor();
	armor.read_from_pbmsg(temp_armor);
	const ::proto_ff::AssistDBData & temp_assist = msg.assist();
	assist.read_from_pbmsg(temp_assist);
	const ::proto_ff::TitleDBData & temp_title = msg.title();
	title.read_from_pbmsg(temp_title);
	const ::proto_ff::GodEvilDBData & temp_godevil = msg.godevil();
	godevil.read_from_pbmsg(temp_godevil);
	const ::proto_ff::OccupationMissionData & temp_occupatoin = msg.occupatoin();
	occupatoin.read_from_pbmsg(temp_occupatoin);
	const ::proto_ff::PayDBData & temp_pay = msg.pay();
	pay.read_from_pbmsg(temp_pay);
	const ::proto_ff::RoleFactionDBData & temp_role_faction = msg.role_faction();
	role_faction.read_from_pbmsg(temp_role_faction);
	const ::proto_ff::RoleBestEQDBData & temp_best_equip = msg.best_equip();
	best_equip.read_from_pbmsg(temp_best_equip);
}

RedWaitDBProto_s::RedWaitDBProto_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int RedWaitDBProto_s::CreateInit() {
	idx = (uint32_t)0;
	cfgid = (int32_t)0;
	time = (uint64_t)0;
	return 0;
}

int RedWaitDBProto_s::ResumeInit() {
	return 0;
}

void RedWaitDBProto_s::write_to_pbmsg(::proto_ff::RedWaitDBProto & msg) const {
	msg.set_idx((uint32_t)idx);
	msg.set_cfgid((int32_t)cfgid);
	msg.set_time((uint64_t)time);
}

void RedWaitDBProto_s::read_from_pbmsg(const ::proto_ff::RedWaitDBProto & msg) {
	idx = msg.idx();
	cfgid = msg.cfgid();
	time = msg.time();
}

RedTriggerDBProto_s::RedTriggerDBProto_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int RedTriggerDBProto_s::CreateInit() {
	cfgid = (int32_t)0;
	count = (int32_t)0;
	return 0;
}

int RedTriggerDBProto_s::ResumeInit() {
	return 0;
}

void RedTriggerDBProto_s::write_to_pbmsg(::proto_ff::RedTriggerDBProto & msg) const {
	msg.set_cfgid((int32_t)cfgid);
	msg.set_count((int32_t)count);
}

void RedTriggerDBProto_s::read_from_pbmsg(const ::proto_ff::RedTriggerDBProto & msg) {
	cfgid = msg.cfgid();
	count = msg.count();
}

RoleRedDBData_s::RoleRedDBData_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int RoleRedDBData_s::CreateInit() {
	bdia = (uint32_t)0;
	magic = (uint32_t)0;
	todaynum = (uint32_t)0;
	todaymagic = (uint32_t)0;
	todaybdia = (uint32_t)0;
	freshtime = (uint64_t)0;
	cid = (uint64_t)0;
	return 0;
}

int RoleRedDBData_s::ResumeInit() {
	return 0;
}

void RoleRedDBData_s::write_to_pbmsg(::proto_ff::RoleRedDBData & msg) const {
	msg.set_bdia((uint32_t)bdia);
	msg.set_magic((uint32_t)magic);
	msg.set_todaynum((uint32_t)todaynum);
	msg.set_todaymagic((uint32_t)todaymagic);
	msg.set_todaybdia((uint32_t)todaybdia);
	msg.set_freshtime((uint64_t)freshtime);
	for(int32_t i = 0; i < (int32_t)send_lst.size(); ++i) {
		msg.add_send_lst((int32_t)send_lst[i]);
	}
	for(int32_t i = 0; i < (int32_t)wait_lst.size(); ++i) {
		::proto_ff::RedWaitDBProto* temp_wait_lst = msg.add_wait_lst();
		wait_lst[i].write_to_pbmsg(*temp_wait_lst);
	}
	msg.set_cid((uint64_t)cid);
	for(int32_t i = 0; i < (int32_t)trigger_lst.size(); ++i) {
		::proto_ff::RedTriggerDBProto* temp_trigger_lst = msg.add_trigger_lst();
		trigger_lst[i].write_to_pbmsg(*temp_trigger_lst);
	}
}

void RoleRedDBData_s::read_from_pbmsg(const ::proto_ff::RoleRedDBData & msg) {
	bdia = msg.bdia();
	magic = msg.magic();
	todaynum = msg.todaynum();
	todaymagic = msg.todaymagic();
	todaybdia = msg.todaybdia();
	freshtime = msg.freshtime();
	send_lst.resize((int)msg.send_lst_size() > (int)send_lst.max_size() ? send_lst.max_size() : msg.send_lst_size());
	for(int32_t i = 0; i < (int32_t)send_lst.size(); ++i) {
		send_lst[i] = msg.send_lst(i);
	}
	wait_lst.resize((int)msg.wait_lst_size() > (int)wait_lst.max_size() ? wait_lst.max_size() : msg.wait_lst_size());
	for(int32_t i = 0; i < (int32_t)wait_lst.size(); ++i) {
		const ::proto_ff::RedWaitDBProto & temp_wait_lst = msg.wait_lst(i);
		wait_lst[i].read_from_pbmsg(temp_wait_lst);
	}
	cid = msg.cid();
	trigger_lst.resize((int)msg.trigger_lst_size() > (int)trigger_lst.max_size() ? trigger_lst.max_size() : msg.trigger_lst_size());
	for(int32_t i = 0; i < (int32_t)trigger_lst.size(); ++i) {
		const ::proto_ff::RedTriggerDBProto & temp_trigger_lst = msg.trigger_lst(i);
		trigger_lst[i].read_from_pbmsg(temp_trigger_lst);
	}
}

RedFetchDBProto_s::RedFetchDBProto_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int RedFetchDBProto_s::CreateInit() {
	cid = (uint64_t)0;
	val = (uint32_t)0;
	time = (uint64_t)0;
	return 0;
}

int RedFetchDBProto_s::ResumeInit() {
	return 0;
}

void RedFetchDBProto_s::write_to_pbmsg(::proto_ff::RedFetchDBProto & msg) const {
	msg.set_cid((uint64_t)cid);
	msg.set_val((uint32_t)val);
	msg.set_time((uint64_t)time);
}

void RedFetchDBProto_s::read_from_pbmsg(const ::proto_ff::RedFetchDBProto & msg) {
	cid = msg.cid();
	val = msg.val();
	time = msg.time();
}

RedFetchListDBProto_s::RedFetchListDBProto_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int RedFetchListDBProto_s::CreateInit() {
	return 0;
}

int RedFetchListDBProto_s::ResumeInit() {
	return 0;
}

void RedFetchListDBProto_s::write_to_pbmsg(::proto_ff::RedFetchListDBProto & msg) const {
	for(int32_t i = 0; i < (int32_t)info.size(); ++i) {
		::proto_ff::RedFetchDBProto* temp_info = msg.add_info();
		info[i].write_to_pbmsg(*temp_info);
	}
}

void RedFetchListDBProto_s::read_from_pbmsg(const ::proto_ff::RedFetchListDBProto & msg) {
	info.resize((int)msg.info_size() > (int)info.max_size() ? info.max_size() : msg.info_size());
	for(int32_t i = 0; i < (int32_t)info.size(); ++i) {
		const ::proto_ff::RedFetchDBProto & temp_info = msg.info(i);
		info[i].read_from_pbmsg(temp_info);
	}
}

RedSendDBProto_s::RedSendDBProto_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int RedSendDBProto_s::CreateInit() {
	idx = (uint32_t)0;
	cfgid = (int32_t)0;
	sender = (uint64_t)0;
	sendtime = (uint64_t)0;
	finish = (int32_t)0;
	return 0;
}

int RedSendDBProto_s::ResumeInit() {
	return 0;
}

void RedSendDBProto_s::write_to_pbmsg(::proto_ff::RedSendDBProto & msg) const {
	msg.set_idx((uint32_t)idx);
	msg.set_cfgid((int32_t)cfgid);
	msg.set_sender((uint64_t)sender);
	msg.set_sendtime((uint64_t)sendtime);
	msg.set_word(word.data());
	msg.set_finish((int32_t)finish);
	::proto_ff::RedFetchListDBProto* temp_fetch = msg.mutable_fetch();
	fetch.write_to_pbmsg(*temp_fetch);
}

void RedSendDBProto_s::read_from_pbmsg(const ::proto_ff::RedSendDBProto & msg) {
	idx = msg.idx();
	cfgid = msg.cfgid();
	sender = msg.sender();
	sendtime = msg.sendtime();
	word = msg.word();
	finish = msg.finish();
	const ::proto_ff::RedFetchListDBProto & temp_fetch = msg.fetch();
	fetch.read_from_pbmsg(temp_fetch);
}

RedDBData_s::RedDBData_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int RedDBData_s::CreateInit() {
	freshtime = (uint64_t)0;
	faction_id = (uint32_t)0;
	return 0;
}

int RedDBData_s::ResumeInit() {
	return 0;
}

void RedDBData_s::write_to_pbmsg(::proto_ff::RedDBData & msg) const {
	for(int32_t i = 0; i < (int32_t)wait.size(); ++i) {
		::proto_ff::RedWaitDBProto* temp_wait = msg.add_wait();
		wait[i].write_to_pbmsg(*temp_wait);
	}
	for(int32_t i = 0; i < (int32_t)trigger_lst.size(); ++i) {
		::proto_ff::RedTriggerDBProto* temp_trigger_lst = msg.add_trigger_lst();
		trigger_lst[i].write_to_pbmsg(*temp_trigger_lst);
	}
	msg.set_freshtime((uint64_t)freshtime);
	for(int32_t i = 0; i < (int32_t)send.size(); ++i) {
		::proto_ff::RedSendDBProto* temp_send = msg.add_send();
		send[i].write_to_pbmsg(*temp_send);
	}
	msg.set_faction_id((uint32_t)faction_id);
}

void RedDBData_s::read_from_pbmsg(const ::proto_ff::RedDBData & msg) {
	wait.resize((int)msg.wait_size() > (int)wait.max_size() ? wait.max_size() : msg.wait_size());
	for(int32_t i = 0; i < (int32_t)wait.size(); ++i) {
		const ::proto_ff::RedWaitDBProto & temp_wait = msg.wait(i);
		wait[i].read_from_pbmsg(temp_wait);
	}
	trigger_lst.resize((int)msg.trigger_lst_size() > (int)trigger_lst.max_size() ? trigger_lst.max_size() : msg.trigger_lst_size());
	for(int32_t i = 0; i < (int32_t)trigger_lst.size(); ++i) {
		const ::proto_ff::RedTriggerDBProto & temp_trigger_lst = msg.trigger_lst(i);
		trigger_lst[i].read_from_pbmsg(temp_trigger_lst);
	}
	freshtime = msg.freshtime();
	send.resize((int)msg.send_size() > (int)send.max_size() ? send.max_size() : msg.send_size());
	for(int32_t i = 0; i < (int32_t)send.size(); ++i) {
		const ::proto_ff::RedSendDBProto & temp_send = msg.send(i);
		send[i].read_from_pbmsg(temp_send);
	}
	faction_id = msg.faction_id();
}

RoleMirrorData_s::RoleMirrorData_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int RoleMirrorData_s::CreateInit() {
	cid = (uint64_t)0;
	type = (int32_t)0;
	teamid = (uint32_t)0;
	zid = (uint32_t)0;
	return 0;
}

int RoleMirrorData_s::ResumeInit() {
	return 0;
}

void RoleMirrorData_s::write_to_pbmsg(::proto_ff::RoleMirrorData & msg) const {
	msg.set_cid((uint64_t)cid);
	msg.set_type((int32_t)type);
	msg.set_teamid((uint32_t)teamid);
	msg.set_zid((uint32_t)zid);
	::proto_ff::AttrDBData* temp_attr = msg.mutable_attr();
	attr.write_to_pbmsg(*temp_attr);
	::proto_ff::SkillDBData* temp_skill = msg.mutable_skill();
	skill.write_to_pbmsg(*temp_skill);
	::proto_ff::RoleDBBaseData* temp_base = msg.mutable_base();
	base.write_to_pbmsg(*temp_base);
}

void RoleMirrorData_s::read_from_pbmsg(const ::proto_ff::RoleMirrorData & msg) {
	cid = msg.cid();
	type = msg.type();
	teamid = msg.teamid();
	zid = msg.zid();
	const ::proto_ff::AttrDBData & temp_attr = msg.attr();
	attr.read_from_pbmsg(temp_attr);
	const ::proto_ff::SkillDBData & temp_skill = msg.skill();
	skill.read_from_pbmsg(temp_skill);
	const ::proto_ff::RoleDBBaseData & temp_base = msg.base();
	base.read_from_pbmsg(temp_base);
}

FactionMemDBProto_s::FactionMemDBProto_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int FactionMemDBProto_s::CreateInit() {
	cid = (uint64_t)0;
	duty = (int32_t)0;
	join_time = (uint64_t)0;
	total_contri = (uint32_t)0;
	return 0;
}

int FactionMemDBProto_s::ResumeInit() {
	return 0;
}

void FactionMemDBProto_s::write_to_pbmsg(::proto_ff::FactionMemDBProto & msg) const {
	msg.set_cid((uint64_t)cid);
	msg.set_duty((int32_t)duty);
	msg.set_join_time((uint64_t)join_time);
	msg.set_total_contri((uint32_t)total_contri);
}

void FactionMemDBProto_s::read_from_pbmsg(const ::proto_ff::FactionMemDBProto & msg) {
	cid = msg.cid();
	duty = msg.duty();
	join_time = msg.join_time();
	total_contri = msg.total_contri();
}

FactionMultMemDBProto_s::FactionMultMemDBProto_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int FactionMultMemDBProto_s::CreateInit() {
	return 0;
}

int FactionMultMemDBProto_s::ResumeInit() {
	return 0;
}

void FactionMultMemDBProto_s::write_to_pbmsg(::proto_ff::FactionMultMemDBProto & msg) const {
	for(int32_t i = 0; i < (int32_t)mem_lst.size(); ++i) {
		::proto_ff::FactionMemDBProto* temp_mem_lst = msg.add_mem_lst();
		mem_lst[i].write_to_pbmsg(*temp_mem_lst);
	}
}

void FactionMultMemDBProto_s::read_from_pbmsg(const ::proto_ff::FactionMultMemDBProto & msg) {
	mem_lst.resize((int)msg.mem_lst_size() > (int)mem_lst.max_size() ? mem_lst.max_size() : msg.mem_lst_size());
	for(int32_t i = 0; i < (int32_t)mem_lst.size(); ++i) {
		const ::proto_ff::FactionMemDBProto & temp_mem_lst = msg.mem_lst(i);
		mem_lst[i].read_from_pbmsg(temp_mem_lst);
	}
}

FactionApplyDBProto_s::FactionApplyDBProto_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int FactionApplyDBProto_s::CreateInit() {
	cid = (uint64_t)0;
	time = (uint64_t)0;
	return 0;
}

int FactionApplyDBProto_s::ResumeInit() {
	return 0;
}

void FactionApplyDBProto_s::write_to_pbmsg(::proto_ff::FactionApplyDBProto & msg) const {
	msg.set_cid((uint64_t)cid);
	msg.set_time((uint64_t)time);
}

void FactionApplyDBProto_s::read_from_pbmsg(const ::proto_ff::FactionApplyDBProto & msg) {
	cid = msg.cid();
	time = msg.time();
}

FactionMultApplyDBProto_s::FactionMultApplyDBProto_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int FactionMultApplyDBProto_s::CreateInit() {
	return 0;
}

int FactionMultApplyDBProto_s::ResumeInit() {
	return 0;
}

void FactionMultApplyDBProto_s::write_to_pbmsg(::proto_ff::FactionMultApplyDBProto & msg) const {
	for(int32_t i = 0; i < (int32_t)apply_lst.size(); ++i) {
		::proto_ff::FactionApplyDBProto* temp_apply_lst = msg.add_apply_lst();
		apply_lst[i].write_to_pbmsg(*temp_apply_lst);
	}
}

void FactionMultApplyDBProto_s::read_from_pbmsg(const ::proto_ff::FactionMultApplyDBProto & msg) {
	apply_lst.resize((int)msg.apply_lst_size() > (int)apply_lst.max_size() ? apply_lst.max_size() : msg.apply_lst_size());
	for(int32_t i = 0; i < (int32_t)apply_lst.size(); ++i) {
		const ::proto_ff::FactionApplyDBProto & temp_apply_lst = msg.apply_lst(i);
		apply_lst[i].read_from_pbmsg(temp_apply_lst);
	}
}

FactionRecordDBProto_s::FactionRecordDBProto_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int FactionRecordDBProto_s::CreateInit() {
	cid = (uint64_t)0;
	time = (uint64_t)0;
	op = (int32_t)0;
	param1 = (int64_t)0;
	return 0;
}

int FactionRecordDBProto_s::ResumeInit() {
	return 0;
}

void FactionRecordDBProto_s::write_to_pbmsg(::proto_ff::FactionRecordDBProto & msg) const {
	msg.set_cid((uint64_t)cid);
	msg.set_time((uint64_t)time);
	msg.set_op((int32_t)op);
	msg.set_param1((int64_t)param1);
}

void FactionRecordDBProto_s::read_from_pbmsg(const ::proto_ff::FactionRecordDBProto & msg) {
	cid = msg.cid();
	time = msg.time();
	op = msg.op();
	param1 = msg.param1();
}

FactionMutRecordDBProto_s::FactionMutRecordDBProto_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int FactionMutRecordDBProto_s::CreateInit() {
	return 0;
}

int FactionMutRecordDBProto_s::ResumeInit() {
	return 0;
}

void FactionMutRecordDBProto_s::write_to_pbmsg(::proto_ff::FactionMutRecordDBProto & msg) const {
	for(int32_t i = 0; i < (int32_t)record_lst.size(); ++i) {
		::proto_ff::FactionRecordDBProto* temp_record_lst = msg.add_record_lst();
		record_lst[i].write_to_pbmsg(*temp_record_lst);
	}
}

void FactionMutRecordDBProto_s::read_from_pbmsg(const ::proto_ff::FactionMutRecordDBProto & msg) {
	record_lst.resize((int)msg.record_lst_size() > (int)record_lst.max_size() ? record_lst.max_size() : msg.record_lst_size());
	for(int32_t i = 0; i < (int32_t)record_lst.size(); ++i) {
		const ::proto_ff::FactionRecordDBProto & temp_record_lst = msg.record_lst(i);
		record_lst[i].read_from_pbmsg(temp_record_lst);
	}
}

FactionDBBase_s::FactionDBBase_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int FactionDBBase_s::CreateInit() {
	faction_id = (uint32_t)0;
	leader_id = (uint64_t)0;
	fight = (uint64_t)0;
	last_notice_time = (uint64_t)0;
	level = (uint32_t)0;
	exp = (uint64_t)0;
	create_time = (uint64_t)0;
	proxy_id = (uint64_t)0;
	proxy_time = (uint64_t)0;
	grade = (int32_t)0;
	return 0;
}

int FactionDBBase_s::ResumeInit() {
	return 0;
}

void FactionDBBase_s::write_to_pbmsg(::proto_ff::FactionDBBase & msg) const {
	msg.set_faction_id((uint32_t)faction_id);
	msg.set_name(name.data());
	msg.set_leader_id((uint64_t)leader_id);
	msg.set_fight((uint64_t)fight);
	msg.set_notice(notice.data());
	msg.set_last_notice_time((uint64_t)last_notice_time);
	msg.set_level((uint32_t)level);
	msg.set_exp((uint64_t)exp);
	msg.set_create_time((uint64_t)create_time);
	msg.set_proxy_id((uint64_t)proxy_id);
	msg.set_proxy_time((uint64_t)proxy_time);
	msg.set_grade((int32_t)grade);
	::proto_ff::FactionMultMemDBProto* temp_member = msg.mutable_member();
	member.write_to_pbmsg(*temp_member);
	::proto_ff::FactionMultApplyDBProto* temp_apply = msg.mutable_apply();
	apply.write_to_pbmsg(*temp_apply);
	::proto_ff::FactionMutRecordDBProto* temp_record = msg.mutable_record();
	record.write_to_pbmsg(*temp_record);
}

void FactionDBBase_s::read_from_pbmsg(const ::proto_ff::FactionDBBase & msg) {
	faction_id = msg.faction_id();
	name = msg.name();
	leader_id = msg.leader_id();
	fight = msg.fight();
	notice = msg.notice();
	last_notice_time = msg.last_notice_time();
	level = msg.level();
	exp = msg.exp();
	create_time = msg.create_time();
	proxy_id = msg.proxy_id();
	proxy_time = msg.proxy_time();
	grade = msg.grade();
	const ::proto_ff::FactionMultMemDBProto & temp_member = msg.member();
	member.read_from_pbmsg(temp_member);
	const ::proto_ff::FactionMultApplyDBProto & temp_apply = msg.apply();
	apply.read_from_pbmsg(temp_apply);
	const ::proto_ff::FactionMutRecordDBProto & temp_record = msg.record();
	record.read_from_pbmsg(temp_record);
}

FactionDBData_s::FactionDBData_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int FactionDBData_s::CreateInit() {
	return 0;
}

int FactionDBData_s::ResumeInit() {
	return 0;
}

void FactionDBData_s::write_to_pbmsg(::proto_ff::FactionDBData & msg) const {
}

void FactionDBData_s::read_from_pbmsg(const ::proto_ff::FactionDBData & msg) {
}

FactionAllDBData_s::FactionAllDBData_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int FactionAllDBData_s::CreateInit() {
	faction_id = (uint32_t)0;
	return 0;
}

int FactionAllDBData_s::ResumeInit() {
	return 0;
}

void FactionAllDBData_s::write_to_pbmsg(::proto_ff::FactionAllDBData & msg) const {
	msg.set_faction_id((uint32_t)faction_id);
	::proto_ff::FactionDBBase* temp_base = msg.mutable_base();
	base.write_to_pbmsg(*temp_base);
	::proto_ff::FactionDBData* temp_data = msg.mutable_data();
	data.write_to_pbmsg(*temp_data);
}

void FactionAllDBData_s::read_from_pbmsg(const ::proto_ff::FactionAllDBData & msg) {
	faction_id = msg.faction_id();
	const ::proto_ff::FactionDBBase & temp_base = msg.base();
	base.read_from_pbmsg(temp_base);
	const ::proto_ff::FactionDBData & temp_data = msg.data();
	data.read_from_pbmsg(temp_data);
}

RoleListDBReq_s::RoleListDBReq_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int RoleListDBReq_s::CreateInit() {
	reqid = (uint64_t)0;
	uid = (uint32_t)0;
	gateid = (uint32_t)0;
	born_zid = (uint32_t)0;
	return 0;
}

int RoleListDBReq_s::ResumeInit() {
	return 0;
}

void RoleListDBReq_s::write_to_pbmsg(::proto_ff::RoleListDBReq & msg) const {
	msg.set_reqid((uint64_t)reqid);
	msg.set_uid((uint32_t)uid);
	msg.set_gateid((uint32_t)gateid);
	msg.set_born_zid((uint32_t)born_zid);
}

void RoleListDBReq_s::read_from_pbmsg(const ::proto_ff::RoleListDBReq & msg) {
	reqid = msg.reqid();
	uid = msg.uid();
	gateid = msg.gateid();
	born_zid = msg.born_zid();
}

RoleListDBRsp_s::RoleListDBRsp_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int RoleListDBRsp_s::CreateInit() {
	ret = (int32_t)0;
	reqid = (uint64_t)0;
	uid = (uint32_t)0;
	gateid = (uint32_t)0;
	regnum = (uint32_t)0;
	return 0;
}

int RoleListDBRsp_s::ResumeInit() {
	return 0;
}

void RoleListDBRsp_s::write_to_pbmsg(::proto_ff::RoleListDBRsp & msg) const {
	msg.set_ret((int32_t)ret);
	msg.set_reqid((uint64_t)reqid);
	msg.set_uid((uint32_t)uid);
	msg.set_gateid((uint32_t)gateid);
	for(int32_t i = 0; i < (int32_t)role_lst.size(); ++i) {
		::proto_ff::RoleListDBProto* temp_role_lst = msg.add_role_lst();
		role_lst[i].write_to_pbmsg(*temp_role_lst);
	}
	msg.set_regnum((uint32_t)regnum);
}

void RoleListDBRsp_s::read_from_pbmsg(const ::proto_ff::RoleListDBRsp & msg) {
	ret = msg.ret();
	reqid = msg.reqid();
	uid = msg.uid();
	gateid = msg.gateid();
	role_lst.resize((int)msg.role_lst_size() > (int)role_lst.max_size() ? role_lst.max_size() : msg.role_lst_size());
	for(int32_t i = 0; i < (int32_t)role_lst.size(); ++i) {
		const ::proto_ff::RoleListDBProto & temp_role_lst = msg.role_lst(i);
		role_lst[i].read_from_pbmsg(temp_role_lst);
	}
	regnum = msg.regnum();
}

CreateRoleDBReq_s::CreateRoleDBReq_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int CreateRoleDBReq_s::CreateInit() {
	reqid = (uint64_t)0;
	zid = (uint32_t)0;
	gateid = (uint32_t)0;
	uid = (uint32_t)0;
	channel_id = (uint32_t)0;
	zone_mid = (uint32_t)0;
	born_zid = (uint32_t)0;
	return 0;
}

int CreateRoleDBReq_s::ResumeInit() {
	return 0;
}

void CreateRoleDBReq_s::write_to_pbmsg(::proto_ff::CreateRoleDBReq & msg) const {
	msg.set_reqid((uint64_t)reqid);
	msg.set_zid((uint32_t)zid);
	msg.set_gateid((uint32_t)gateid);
	::proto_ff::RoleDBData* temp_data = msg.mutable_data();
	data.write_to_pbmsg(*temp_data);
	msg.set_uid((uint32_t)uid);
	msg.set_channel_id((uint32_t)channel_id);
	msg.set_zone_mid((uint32_t)zone_mid);
	msg.set_born_zid((uint32_t)born_zid);
}

void CreateRoleDBReq_s::read_from_pbmsg(const ::proto_ff::CreateRoleDBReq & msg) {
	reqid = msg.reqid();
	zid = msg.zid();
	gateid = msg.gateid();
	const ::proto_ff::RoleDBData & temp_data = msg.data();
	data.read_from_pbmsg(temp_data);
	uid = msg.uid();
	channel_id = msg.channel_id();
	zone_mid = msg.zone_mid();
	born_zid = msg.born_zid();
}

CreateRoleDBRsp_s::CreateRoleDBRsp_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int CreateRoleDBRsp_s::CreateInit() {
	ret = (int32_t)0;
	reqid = (uint64_t)0;
	uid = (uint32_t)0;
	gateid = (uint32_t)0;
	born_zid = (uint32_t)0;
	return 0;
}

int CreateRoleDBRsp_s::ResumeInit() {
	return 0;
}

void CreateRoleDBRsp_s::write_to_pbmsg(::proto_ff::CreateRoleDBRsp & msg) const {
	msg.set_ret((int32_t)ret);
	msg.set_reqid((uint64_t)reqid);
	msg.set_uid((uint32_t)uid);
	msg.set_gateid((uint32_t)gateid);
	::proto_ff::RoleListDBProto* temp_info = msg.mutable_info();
	info.write_to_pbmsg(*temp_info);
	msg.set_born_zid((uint32_t)born_zid);
	::proto_ff::CenterRoleProto* temp_simple = msg.mutable_simple();
	simple.write_to_pbmsg(*temp_simple);
}

void CreateRoleDBRsp_s::read_from_pbmsg(const ::proto_ff::CreateRoleDBRsp & msg) {
	ret = msg.ret();
	reqid = msg.reqid();
	uid = msg.uid();
	gateid = msg.gateid();
	const ::proto_ff::RoleListDBProto & temp_info = msg.info();
	info.read_from_pbmsg(temp_info);
	born_zid = msg.born_zid();
	const ::proto_ff::CenterRoleProto & temp_simple = msg.simple();
	simple.read_from_pbmsg(temp_simple);
}

RoleInfoDBReq_s::RoleInfoDBReq_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int RoleInfoDBReq_s::CreateInit() {
	reqid = (uint64_t)0;
	cid = (uint64_t)0;
	change = (int32_t)0;
	return 0;
}

int RoleInfoDBReq_s::ResumeInit() {
	return 0;
}

void RoleInfoDBReq_s::write_to_pbmsg(::proto_ff::RoleInfoDBReq & msg) const {
	msg.set_reqid((uint64_t)reqid);
	msg.set_cid((uint64_t)cid);
	msg.set_change((int32_t)change);
}

void RoleInfoDBReq_s::read_from_pbmsg(const ::proto_ff::RoleInfoDBReq & msg) {
	reqid = msg.reqid();
	cid = msg.cid();
	change = msg.change();
}

RoleInfoDBRsp_s::RoleInfoDBRsp_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int RoleInfoDBRsp_s::CreateInit() {
	ret = (int32_t)0;
	reqid = (uint64_t)0;
	cid = (uint64_t)0;
	change = (int32_t)0;
	return 0;
}

int RoleInfoDBRsp_s::ResumeInit() {
	return 0;
}

void RoleInfoDBRsp_s::write_to_pbmsg(::proto_ff::RoleInfoDBRsp & msg) const {
	msg.set_ret((int32_t)ret);
	msg.set_reqid((uint64_t)reqid);
	msg.set_cid((uint64_t)cid);
	msg.set_change((int32_t)change);
	::proto_ff::RoleDBData* temp_info = msg.mutable_info();
	info.write_to_pbmsg(*temp_info);
}

void RoleInfoDBRsp_s::read_from_pbmsg(const ::proto_ff::RoleInfoDBRsp & msg) {
	ret = msg.ret();
	reqid = msg.reqid();
	cid = msg.cid();
	change = msg.change();
	const ::proto_ff::RoleDBData & temp_info = msg.info();
	info.read_from_pbmsg(temp_info);
}

RoleInfoUpdateDBReq_s::RoleInfoUpdateDBReq_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int RoleInfoUpdateDBReq_s::CreateInit() {
	cid = (uint64_t)0;
	uid = (uint32_t)0;
	return 0;
}

int RoleInfoUpdateDBReq_s::ResumeInit() {
	return 0;
}

void RoleInfoUpdateDBReq_s::write_to_pbmsg(::proto_ff::RoleInfoUpdateDBReq & msg) const {
	msg.set_cid((uint64_t)cid);
	msg.set_uid((uint32_t)uid);
	::proto_ff::RoleDBData* temp_info = msg.mutable_info();
	info.write_to_pbmsg(*temp_info);
}

void RoleInfoUpdateDBReq_s::read_from_pbmsg(const ::proto_ff::RoleInfoUpdateDBReq & msg) {
	cid = msg.cid();
	uid = msg.uid();
	const ::proto_ff::RoleDBData & temp_info = msg.info();
	info.read_from_pbmsg(temp_info);
}

RoleChgNameDBReq_s::RoleChgNameDBReq_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int RoleChgNameDBReq_s::CreateInit() {
	cid = (uint64_t)0;
	return 0;
}

int RoleChgNameDBReq_s::ResumeInit() {
	return 0;
}

void RoleChgNameDBReq_s::write_to_pbmsg(::proto_ff::RoleChgNameDBReq & msg) const {
	msg.set_cid((uint64_t)cid);
	msg.set_name(name.data());
}

void RoleChgNameDBReq_s::read_from_pbmsg(const ::proto_ff::RoleChgNameDBReq & msg) {
	cid = msg.cid();
	name = msg.name();
}

RoleChgNameDBRsp_s::RoleChgNameDBRsp_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int RoleChgNameDBRsp_s::CreateInit() {
	ret = (int32_t)0;
	cid = (uint64_t)0;
	return 0;
}

int RoleChgNameDBRsp_s::ResumeInit() {
	return 0;
}

void RoleChgNameDBRsp_s::write_to_pbmsg(::proto_ff::RoleChgNameDBRsp & msg) const {
	msg.set_ret((int32_t)ret);
	msg.set_cid((uint64_t)cid);
	msg.set_name(name.data());
}

void RoleChgNameDBRsp_s::read_from_pbmsg(const ::proto_ff::RoleChgNameDBRsp & msg) {
	ret = msg.ret();
	cid = msg.cid();
	name = msg.name();
}

RoleSimpleListDBReq_s::RoleSimpleListDBReq_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int RoleSimpleListDBReq_s::CreateInit() {
	return 0;
}

int RoleSimpleListDBReq_s::ResumeInit() {
	return 0;
}

void RoleSimpleListDBReq_s::write_to_pbmsg(::proto_ff::RoleSimpleListDBReq & msg) const {
}

void RoleSimpleListDBReq_s::read_from_pbmsg(const ::proto_ff::RoleSimpleListDBReq & msg) {
}

RoleSimpleListDBRsp_s::RoleSimpleListDBRsp_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int RoleSimpleListDBRsp_s::CreateInit() {
	ret = (int32_t)0;
	finish_flag = (int32_t)0;
	return 0;
}

int RoleSimpleListDBRsp_s::ResumeInit() {
	return 0;
}

void RoleSimpleListDBRsp_s::write_to_pbmsg(::proto_ff::RoleSimpleListDBRsp & msg) const {
	msg.set_ret((int32_t)ret);
	for(int32_t i = 0; i < (int32_t)info.size(); ++i) {
		::proto_ff::CenterRoleProto* temp_info = msg.add_info();
		info[i].write_to_pbmsg(*temp_info);
	}
	msg.set_finish_flag((int32_t)finish_flag);
}

void RoleSimpleListDBRsp_s::read_from_pbmsg(const ::proto_ff::RoleSimpleListDBRsp & msg) {
	ret = msg.ret();
	info.resize((int)msg.info_size() > (int)info.max_size() ? info.max_size() : msg.info_size());
	for(int32_t i = 0; i < (int32_t)info.size(); ++i) {
		const ::proto_ff::CenterRoleProto & temp_info = msg.info(i);
		info[i].read_from_pbmsg(temp_info);
	}
	finish_flag = msg.finish_flag();
}

CreatureTransLogicDBReq_s::CreatureTransLogicDBReq_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int CreatureTransLogicDBReq_s::CreateInit() {
	return 0;
}

int CreatureTransLogicDBReq_s::ResumeInit() {
	return 0;
}

void CreatureTransLogicDBReq_s::write_to_pbmsg(::proto_ff::CreatureTransLogicDBReq & msg) const {
	msg.set_trans_data(trans_data.data());
}

void CreatureTransLogicDBReq_s::read_from_pbmsg(const ::proto_ff::CreatureTransLogicDBReq & msg) {
	trans_data = msg.trans_data();
}

CreatureTransLogicDBRsp_s::CreatureTransLogicDBRsp_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int CreatureTransLogicDBRsp_s::CreateInit() {
	retcode = (int32_t)0;
	cid = (uint64_t)0;
	return 0;
}

int CreatureTransLogicDBRsp_s::ResumeInit() {
	return 0;
}

void CreatureTransLogicDBRsp_s::write_to_pbmsg(::proto_ff::CreatureTransLogicDBRsp & msg) const {
	msg.set_retcode((int32_t)retcode);
	msg.set_cid((uint64_t)cid);
}

void CreatureTransLogicDBRsp_s::read_from_pbmsg(const ::proto_ff::CreatureTransLogicDBRsp & msg) {
	retcode = msg.retcode();
	cid = msg.cid();
}

NewMailDBInfo_s::NewMailDBInfo_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int NewMailDBInfo_s::CreateInit() {
	result = (int32_t)0;
	return 0;
}

int NewMailDBInfo_s::ResumeInit() {
	return 0;
}

void NewMailDBInfo_s::write_to_pbmsg(::proto_ff::NewMailDBInfo & msg) const {
	for(int32_t i = 0; i < (int32_t)data.size(); ++i) {
		::proto_ff::MailInfo* temp_data = msg.add_data();
		data[i].write_to_pbmsg(*temp_data);
	}
	msg.set_result((int32_t)result);
}

void NewMailDBInfo_s::read_from_pbmsg(const ::proto_ff::NewMailDBInfo & msg) {
	data.resize((int)msg.data_size() > (int)data.max_size() ? data.max_size() : msg.data_size());
	for(int32_t i = 0; i < (int32_t)data.size(); ++i) {
		const ::proto_ff::MailInfo & temp_data = msg.data(i);
		data[i].read_from_pbmsg(temp_data);
	}
	result = msg.result();
}

MailDBOperateInfo_s::MailDBOperateInfo_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int MailDBOperateInfo_s::CreateInit() {
	result = (int32_t)0;
	return 0;
}

int MailDBOperateInfo_s::ResumeInit() {
	return 0;
}

void MailDBOperateInfo_s::write_to_pbmsg(::proto_ff::MailDBOperateInfo & msg) const {
	for(int32_t i = 0; i < (int32_t)mid_lst.size(); ++i) {
		msg.add_mid_lst((uint32_t)mid_lst[i]);
	}
	msg.set_result((int32_t)result);
}

void MailDBOperateInfo_s::read_from_pbmsg(const ::proto_ff::MailDBOperateInfo & msg) {
	mid_lst.resize((int)msg.mid_lst_size() > (int)mid_lst.max_size() ? mid_lst.max_size() : msg.mid_lst_size());
	for(int32_t i = 0; i < (int32_t)mid_lst.size(); ++i) {
		mid_lst[i] = msg.mid_lst(i);
	}
	result = msg.result();
}

SaveMailDBReq_s::SaveMailDBReq_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int SaveMailDBReq_s::CreateInit() {
	charid = (uint64_t)0;
	notify = (int32_t)0;
	return 0;
}

int SaveMailDBReq_s::ResumeInit() {
	return 0;
}

void SaveMailDBReq_s::write_to_pbmsg(::proto_ff::SaveMailDBReq & msg) const {
	msg.set_charid((uint64_t)charid);
	::proto_ff::NewMailDBInfo* temp_info = msg.mutable_info();
	info.write_to_pbmsg(*temp_info);
	::proto_ff::MailDBOperateInfo* temp_del = msg.mutable_del();
	del.write_to_pbmsg(*temp_del);
	::proto_ff::MailDBOperateInfo* temp_fetch = msg.mutable_fetch();
	fetch.write_to_pbmsg(*temp_fetch);
	::proto_ff::MailDBOperateInfo* temp_read = msg.mutable_read();
	read.write_to_pbmsg(*temp_read);
	msg.set_notify((int32_t)notify);
}

void SaveMailDBReq_s::read_from_pbmsg(const ::proto_ff::SaveMailDBReq & msg) {
	charid = msg.charid();
	const ::proto_ff::NewMailDBInfo & temp_info = msg.info();
	info.read_from_pbmsg(temp_info);
	const ::proto_ff::MailDBOperateInfo & temp_del = msg.del();
	del.read_from_pbmsg(temp_del);
	const ::proto_ff::MailDBOperateInfo & temp_fetch = msg.fetch();
	fetch.read_from_pbmsg(temp_fetch);
	const ::proto_ff::MailDBOperateInfo & temp_read = msg.read();
	read.read_from_pbmsg(temp_read);
	notify = msg.notify();
}

SaveMailDBRsp_s::SaveMailDBRsp_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int SaveMailDBRsp_s::CreateInit() {
	charid = (uint64_t)0;
	notify = (int32_t)0;
	return 0;
}

int SaveMailDBRsp_s::ResumeInit() {
	return 0;
}

void SaveMailDBRsp_s::write_to_pbmsg(::proto_ff::SaveMailDBRsp & msg) const {
	msg.set_charid((uint64_t)charid);
	::proto_ff::NewMailDBInfo* temp_info = msg.mutable_info();
	info.write_to_pbmsg(*temp_info);
	::proto_ff::MailDBOperateInfo* temp_del = msg.mutable_del();
	del.write_to_pbmsg(*temp_del);
	::proto_ff::MailDBOperateInfo* temp_fetch = msg.mutable_fetch();
	fetch.write_to_pbmsg(*temp_fetch);
	::proto_ff::MailDBOperateInfo* temp_read = msg.mutable_read();
	read.write_to_pbmsg(*temp_read);
	msg.set_notify((int32_t)notify);
}

void SaveMailDBRsp_s::read_from_pbmsg(const ::proto_ff::SaveMailDBRsp & msg) {
	charid = msg.charid();
	const ::proto_ff::NewMailDBInfo & temp_info = msg.info();
	info.read_from_pbmsg(temp_info);
	const ::proto_ff::MailDBOperateInfo & temp_del = msg.del();
	del.read_from_pbmsg(temp_del);
	const ::proto_ff::MailDBOperateInfo & temp_fetch = msg.fetch();
	fetch.read_from_pbmsg(temp_fetch);
	const ::proto_ff::MailDBOperateInfo & temp_read = msg.read();
	read.read_from_pbmsg(temp_read);
	notify = msg.notify();
}

CharacterMailDBRequest_s::CharacterMailDBRequest_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int CharacterMailDBRequest_s::CreateInit() {
	charID = (uint64_t)0;
	zone_mail_flag = (uint32_t)0;
	offset = (int32_t)0;
	reqid = (uint32_t)0;
	return 0;
}

int CharacterMailDBRequest_s::ResumeInit() {
	return 0;
}

void CharacterMailDBRequest_s::write_to_pbmsg(::proto_ff::CharacterMailDBRequest & msg) const {
	msg.set_charid((uint64_t)charID);
	msg.set_zone_mail_flag((uint32_t)zone_mail_flag);
	msg.set_offset((int32_t)offset);
	msg.set_reqid((uint32_t)reqid);
}

void CharacterMailDBRequest_s::read_from_pbmsg(const ::proto_ff::CharacterMailDBRequest & msg) {
	charID = msg.charid();
	zone_mail_flag = msg.zone_mail_flag();
	offset = msg.offset();
	reqid = msg.reqid();
}

CharacterMailDBResponse_s::CharacterMailDBResponse_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int CharacterMailDBResponse_s::CreateInit() {
	charID = (uint64_t)0;
	zoneMailId = (uint32_t)0;
	offset = (int32_t)0;
	reqid = (uint32_t)0;
	return 0;
}

int CharacterMailDBResponse_s::ResumeInit() {
	return 0;
}

void CharacterMailDBResponse_s::write_to_pbmsg(::proto_ff::CharacterMailDBResponse & msg) const {
	msg.set_charid((uint64_t)charID);
	for(int32_t i = 0; i < (int32_t)info.size(); ++i) {
		::proto_ff::MailInfo* temp_info = msg.add_info();
		info[i].write_to_pbmsg(*temp_info);
	}
	msg.set_zonemailid((uint32_t)zoneMailId);
	msg.set_offset((int32_t)offset);
	msg.set_reqid((uint32_t)reqid);
}

void CharacterMailDBResponse_s::read_from_pbmsg(const ::proto_ff::CharacterMailDBResponse & msg) {
	charID = msg.charid();
	info.resize((int)msg.info_size() > (int)info.max_size() ? info.max_size() : msg.info_size());
	for(int32_t i = 0; i < (int32_t)info.size(); ++i) {
		const ::proto_ff::MailInfo & temp_info = msg.info(i);
		info[i].read_from_pbmsg(temp_info);
	}
	zoneMailId = msg.zonemailid();
	offset = msg.offset();
	reqid = msg.reqid();
}

MaxMailIDRequest_s::MaxMailIDRequest_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int MaxMailIDRequest_s::CreateInit() {
	return 0;
}

int MaxMailIDRequest_s::ResumeInit() {
	return 0;
}

void MaxMailIDRequest_s::write_to_pbmsg(::proto_ff::MaxMailIDRequest & msg) const {
}

void MaxMailIDRequest_s::read_from_pbmsg(const ::proto_ff::MaxMailIDRequest & msg) {
}

MaxMailIDResponse_s::MaxMailIDResponse_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int MaxMailIDResponse_s::CreateInit() {
	maxZoneMailId = (uint32_t)0;
	maxMailId = (uint32_t)0;
	return 0;
}

int MaxMailIDResponse_s::ResumeInit() {
	return 0;
}

void MaxMailIDResponse_s::write_to_pbmsg(::proto_ff::MaxMailIDResponse & msg) const {
	msg.set_maxzonemailid((uint32_t)maxZoneMailId);
	msg.set_maxmailid((uint32_t)maxMailId);
}

void MaxMailIDResponse_s::read_from_pbmsg(const ::proto_ff::MaxMailIDResponse & msg) {
	maxZoneMailId = msg.maxzonemailid();
	maxMailId = msg.maxmailid();
}

DeleteCharacterMail_s::DeleteCharacterMail_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int DeleteCharacterMail_s::CreateInit() {
	charID = (uint64_t)0;
	return 0;
}

int DeleteCharacterMail_s::ResumeInit() {
	return 0;
}

void DeleteCharacterMail_s::write_to_pbmsg(::proto_ff::DeleteCharacterMail & msg) const {
	msg.set_charid((uint64_t)charID);
}

void DeleteCharacterMail_s::read_from_pbmsg(const ::proto_ff::DeleteCharacterMail & msg) {
	charID = msg.charid();
}

ZoneMailSaveRsp_s::ZoneMailSaveRsp_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int ZoneMailSaveRsp_s::CreateInit() {
	mailId = (uint32_t)0;
	return 0;
}

int ZoneMailSaveRsp_s::ResumeInit() {
	return 0;
}

void ZoneMailSaveRsp_s::write_to_pbmsg(::proto_ff::ZoneMailSaveRsp & msg) const {
	msg.set_mailid((uint32_t)mailId);
}

void ZoneMailSaveRsp_s::read_from_pbmsg(const ::proto_ff::ZoneMailSaveRsp & msg) {
	mailId = msg.mailid();
}

ZoneMailTransCharacterMailReq_s::ZoneMailTransCharacterMailReq_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int ZoneMailTransCharacterMailReq_s::CreateInit() {
	mailId = (uint32_t)0;
	cid = (uint64_t)0;
	return 0;
}

int ZoneMailTransCharacterMailReq_s::ResumeInit() {
	return 0;
}

void ZoneMailTransCharacterMailReq_s::write_to_pbmsg(::proto_ff::ZoneMailTransCharacterMailReq & msg) const {
	msg.set_mailid((uint32_t)mailId);
	msg.set_cid((uint64_t)cid);
}

void ZoneMailTransCharacterMailReq_s::read_from_pbmsg(const ::proto_ff::ZoneMailTransCharacterMailReq & msg) {
	mailId = msg.mailid();
	cid = msg.cid();
}

ZoneMailTransCharacterMailRsp_s::ZoneMailTransCharacterMailRsp_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int ZoneMailTransCharacterMailRsp_s::CreateInit() {
	cid = (uint64_t)0;
	return 0;
}

int ZoneMailTransCharacterMailRsp_s::ResumeInit() {
	return 0;
}

void ZoneMailTransCharacterMailRsp_s::write_to_pbmsg(::proto_ff::ZoneMailTransCharacterMailRsp & msg) const {
	msg.set_cid((uint64_t)cid);
	for(int32_t i = 0; i < (int32_t)data.size(); ++i) {
		::proto_ff::MailInfo* temp_data = msg.add_data();
		data[i].write_to_pbmsg(*temp_data);
	}
}

void ZoneMailTransCharacterMailRsp_s::read_from_pbmsg(const ::proto_ff::ZoneMailTransCharacterMailRsp & msg) {
	cid = msg.cid();
	data.resize((int)msg.data_size() > (int)data.max_size() ? data.max_size() : msg.data_size());
	for(int32_t i = 0; i < (int32_t)data.size(); ++i) {
		const ::proto_ff::MailInfo & temp_data = msg.data(i);
		data[i].read_from_pbmsg(temp_data);
	}
}

WebMailDBDataReq_s::WebMailDBDataReq_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int WebMailDBDataReq_s::CreateInit() {
	op_type = (int32_t)0;
	cid = (uint64_t)0;
	pernum = (uint32_t)0;
	curpage = (uint32_t)0;
	return 0;
}

int WebMailDBDataReq_s::ResumeInit() {
	return 0;
}

void WebMailDBDataReq_s::write_to_pbmsg(::proto_ff::WebMailDBDataReq & msg) const {
	msg.set_op_type((int32_t)op_type);
	msg.set_cid((uint64_t)cid);
	msg.set_pernum((uint32_t)pernum);
	msg.set_curpage((uint32_t)curpage);
	for(int32_t i = 0; i < (int32_t)id_lst.size(); ++i) {
		msg.add_id_lst((uint32_t)id_lst[i]);
	}
	msg.set_webid(webId.data());
}

void WebMailDBDataReq_s::read_from_pbmsg(const ::proto_ff::WebMailDBDataReq & msg) {
	op_type = msg.op_type();
	cid = msg.cid();
	pernum = msg.pernum();
	curpage = msg.curpage();
	id_lst.resize((int)msg.id_lst_size() > (int)id_lst.max_size() ? id_lst.max_size() : msg.id_lst_size());
	for(int32_t i = 0; i < (int32_t)id_lst.size(); ++i) {
		id_lst[i] = msg.id_lst(i);
	}
	webId = msg.webid();
}

WebMailDBDataRsp_s::WebMailDBDataRsp_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int WebMailDBDataRsp_s::CreateInit() {
	op_type = (int32_t)0;
	cid = (uint64_t)0;
	curpage = (uint32_t)0;
	totalcount = (uint32_t)0;
	return 0;
}

int WebMailDBDataRsp_s::ResumeInit() {
	return 0;
}

void WebMailDBDataRsp_s::write_to_pbmsg(::proto_ff::WebMailDBDataRsp & msg) const {
	msg.set_op_type((int32_t)op_type);
	msg.set_cid((uint64_t)cid);
	msg.set_curpage((uint32_t)curpage);
	msg.set_totalcount((uint32_t)totalcount);
	for(int32_t i = 0; i < (int32_t)id_lst.size(); ++i) {
		msg.add_id_lst((uint32_t)id_lst[i]);
	}
	for(int32_t i = 0; i < (int32_t)info_lst.size(); ++i) {
		::proto_ff::WebMailDataProto* temp_info_lst = msg.add_info_lst();
		info_lst[i].write_to_pbmsg(*temp_info_lst);
	}
	msg.set_webid(webId.data());
}

void WebMailDBDataRsp_s::read_from_pbmsg(const ::proto_ff::WebMailDBDataRsp & msg) {
	op_type = msg.op_type();
	cid = msg.cid();
	curpage = msg.curpage();
	totalcount = msg.totalcount();
	id_lst.resize((int)msg.id_lst_size() > (int)id_lst.max_size() ? id_lst.max_size() : msg.id_lst_size());
	for(int32_t i = 0; i < (int32_t)id_lst.size(); ++i) {
		id_lst[i] = msg.id_lst(i);
	}
	info_lst.resize((int)msg.info_lst_size() > (int)info_lst.max_size() ? info_lst.max_size() : msg.info_lst_size());
	for(int32_t i = 0; i < (int32_t)info_lst.size(); ++i) {
		const ::proto_ff::WebMailDataProto & temp_info_lst = msg.info_lst(i);
		info_lst[i].read_from_pbmsg(temp_info_lst);
	}
	webId = msg.webid();
}

FriendDBInfo_s::FriendDBInfo_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int FriendDBInfo_s::CreateInit() {
	charID = (uint64_t)0;
	return 0;
}

int FriendDBInfo_s::ResumeInit() {
	return 0;
}

void FriendDBInfo_s::write_to_pbmsg(::proto_ff::FriendDBInfo & msg) const {
	msg.set_charid((uint64_t)charID);
	::proto_ff::RelationDBInfo* temp_data = msg.mutable_data();
	data.write_to_pbmsg(*temp_data);
}

void FriendDBInfo_s::read_from_pbmsg(const ::proto_ff::FriendDBInfo & msg) {
	charID = msg.charid();
	const ::proto_ff::RelationDBInfo & temp_data = msg.data();
	data.read_from_pbmsg(temp_data);
}

FriendDBRequest_s::FriendDBRequest_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int FriendDBRequest_s::CreateInit() {
	charid = (uint64_t)0;
	operate_type = (uint32_t)0;
	query_times = (uint32_t)0;
	return 0;
}

int FriendDBRequest_s::ResumeInit() {
	return 0;
}

void FriendDBRequest_s::write_to_pbmsg(::proto_ff::FriendDBRequest & msg) const {
	msg.set_charid((uint64_t)charid);
	for(int32_t i = 0; i < (int32_t)dstid_lst.size(); ++i) {
		msg.add_dstid_lst((uint64_t)dstid_lst[i]);
	}
	msg.set_operate_type((uint32_t)operate_type);
	msg.set_data(data.data());
	msg.set_query_times((uint32_t)query_times);
}

void FriendDBRequest_s::read_from_pbmsg(const ::proto_ff::FriendDBRequest & msg) {
	charid = msg.charid();
	dstid_lst.resize((int)msg.dstid_lst_size() > (int)dstid_lst.max_size() ? dstid_lst.max_size() : msg.dstid_lst_size());
	for(int32_t i = 0; i < (int32_t)dstid_lst.size(); ++i) {
		dstid_lst[i] = msg.dstid_lst(i);
	}
	operate_type = msg.operate_type();
	data = msg.data();
	query_times = msg.query_times();
}

FriendDBResponse_s::FriendDBResponse_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int FriendDBResponse_s::CreateInit() {
	retcode = (int32_t)0;
	charid = (uint64_t)0;
	operate_type = (uint32_t)0;
	query_times = (uint32_t)0;
	return 0;
}

int FriendDBResponse_s::ResumeInit() {
	return 0;
}

void FriendDBResponse_s::write_to_pbmsg(::proto_ff::FriendDBResponse & msg) const {
	msg.set_retcode((int32_t)retcode);
	msg.set_charid((uint64_t)charid);
	msg.set_operate_type((uint32_t)operate_type);
	for(int32_t i = 0; i < (int32_t)info_lst.size(); ++i) {
		::proto_ff::FriendDBInfo* temp_info_lst = msg.add_info_lst();
		info_lst[i].write_to_pbmsg(*temp_info_lst);
	}
	for(int32_t i = 0; i < (int32_t)last_lst.size(); ++i) {
		msg.add_last_lst((uint64_t)last_lst[i]);
	}
	msg.set_data(data.data());
	msg.set_query_times((uint32_t)query_times);
}

void FriendDBResponse_s::read_from_pbmsg(const ::proto_ff::FriendDBResponse & msg) {
	retcode = msg.retcode();
	charid = msg.charid();
	operate_type = msg.operate_type();
	info_lst.resize((int)msg.info_lst_size() > (int)info_lst.max_size() ? info_lst.max_size() : msg.info_lst_size());
	for(int32_t i = 0; i < (int32_t)info_lst.size(); ++i) {
		const ::proto_ff::FriendDBInfo & temp_info_lst = msg.info_lst(i);
		info_lst[i].read_from_pbmsg(temp_info_lst);
	}
	last_lst.resize((int)msg.last_lst_size() > (int)last_lst.max_size() ? last_lst.max_size() : msg.last_lst_size());
	for(int32_t i = 0; i < (int32_t)last_lst.size(); ++i) {
		last_lst[i] = msg.last_lst(i);
	}
	data = msg.data();
	query_times = msg.query_times();
}

AllFriendDBRequest_s::AllFriendDBRequest_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int AllFriendDBRequest_s::CreateInit() {
	offset = (int32_t)0;
	return 0;
}

int AllFriendDBRequest_s::ResumeInit() {
	return 0;
}

void AllFriendDBRequest_s::write_to_pbmsg(::proto_ff::AllFriendDBRequest & msg) const {
	msg.set_offset((int32_t)offset);
}

void AllFriendDBRequest_s::read_from_pbmsg(const ::proto_ff::AllFriendDBRequest & msg) {
	offset = msg.offset();
}

AllFriendDBResponse_s::AllFriendDBResponse_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int AllFriendDBResponse_s::CreateInit() {
	retcode = (int32_t)0;
	offset = (int32_t)0;
	return 0;
}

int AllFriendDBResponse_s::ResumeInit() {
	return 0;
}

void AllFriendDBResponse_s::write_to_pbmsg(::proto_ff::AllFriendDBResponse & msg) const {
	msg.set_retcode((int32_t)retcode);
	msg.set_offset((int32_t)offset);
	for(int32_t i = 0; i < (int32_t)info.size(); ++i) {
		::proto_ff::FriendDBInfo* temp_info = msg.add_info();
		info[i].write_to_pbmsg(*temp_info);
	}
}

void AllFriendDBResponse_s::read_from_pbmsg(const ::proto_ff::AllFriendDBResponse & msg) {
	retcode = msg.retcode();
	offset = msg.offset();
	info.resize((int)msg.info_size() > (int)info.max_size() ? info.max_size() : msg.info_size());
	for(int32_t i = 0; i < (int32_t)info.size(); ++i) {
		const ::proto_ff::FriendDBInfo & temp_info = msg.info(i);
		info[i].read_from_pbmsg(temp_info);
	}
}

SaveFriendDBRequest_s::SaveFriendDBRequest_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int SaveFriendDBRequest_s::CreateInit() {
	return 0;
}

int SaveFriendDBRequest_s::ResumeInit() {
	return 0;
}

void SaveFriendDBRequest_s::write_to_pbmsg(::proto_ff::SaveFriendDBRequest & msg) const {
	for(int32_t i = 0; i < (int32_t)info.size(); ++i) {
		::proto_ff::FriendDBInfo* temp_info = msg.add_info();
		info[i].write_to_pbmsg(*temp_info);
	}
}

void SaveFriendDBRequest_s::read_from_pbmsg(const ::proto_ff::SaveFriendDBRequest & msg) {
	info.resize((int)msg.info_size() > (int)info.max_size() ? info.max_size() : msg.info_size());
	for(int32_t i = 0; i < (int32_t)info.size(); ++i) {
		const ::proto_ff::FriendDBInfo & temp_info = msg.info(i);
		info[i].read_from_pbmsg(temp_info);
	}
}

DelteFriendDBRequest_s::DelteFriendDBRequest_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int DelteFriendDBRequest_s::CreateInit() {
	charId = (uint64_t)0;
	return 0;
}

int DelteFriendDBRequest_s::ResumeInit() {
	return 0;
}

void DelteFriendDBRequest_s::write_to_pbmsg(::proto_ff::DelteFriendDBRequest & msg) const {
	msg.set_charid((uint64_t)charId);
}

void DelteFriendDBRequest_s::read_from_pbmsg(const ::proto_ff::DelteFriendDBRequest & msg) {
	charId = msg.charid();
}

GlobalDBRequst_s::GlobalDBRequst_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int GlobalDBRequst_s::CreateInit() {
	return 0;
}

int GlobalDBRequst_s::ResumeInit() {
	return 0;
}

void GlobalDBRequst_s::write_to_pbmsg(::proto_ff::GlobalDBRequst & msg) const {
}

void GlobalDBRequst_s::read_from_pbmsg(const ::proto_ff::GlobalDBRequst & msg) {
}

GlobalDBEntry_s::GlobalDBEntry_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int GlobalDBEntry_s::CreateInit() {
	type_id = (int32_t)0;
	return 0;
}

int GlobalDBEntry_s::ResumeInit() {
	return 0;
}

void GlobalDBEntry_s::write_to_pbmsg(::proto_ff::GlobalDBEntry & msg) const {
	msg.set_type_id((int32_t)type_id);
	msg.set_data(data.data());
}

void GlobalDBEntry_s::read_from_pbmsg(const ::proto_ff::GlobalDBEntry & msg) {
	type_id = msg.type_id();
	data = msg.data();
}

GlobalDBResponse_s::GlobalDBResponse_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int GlobalDBResponse_s::CreateInit() {
	isfinish = (int32_t)0;
	return 0;
}

int GlobalDBResponse_s::ResumeInit() {
	return 0;
}

void GlobalDBResponse_s::write_to_pbmsg(::proto_ff::GlobalDBResponse & msg) const {
	for(int32_t i = 0; i < (int32_t)entry.size(); ++i) {
		::proto_ff::GlobalDBEntry* temp_entry = msg.add_entry();
		entry[i].write_to_pbmsg(*temp_entry);
	}
	msg.set_isfinish((int32_t)isfinish);
}

void GlobalDBResponse_s::read_from_pbmsg(const ::proto_ff::GlobalDBResponse & msg) {
	entry.resize((int)msg.entry_size() > (int)entry.max_size() ? entry.max_size() : msg.entry_size());
	for(int32_t i = 0; i < (int32_t)entry.size(); ++i) {
		const ::proto_ff::GlobalDBEntry & temp_entry = msg.entry(i);
		entry[i].read_from_pbmsg(temp_entry);
	}
	isfinish = msg.isfinish();
}

GlobalDBSetRequest_s::GlobalDBSetRequest_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int GlobalDBSetRequest_s::CreateInit() {
	type_id = (int32_t)0;
	return 0;
}

int GlobalDBSetRequest_s::ResumeInit() {
	return 0;
}

void GlobalDBSetRequest_s::write_to_pbmsg(::proto_ff::GlobalDBSetRequest & msg) const {
	msg.set_type_id((int32_t)type_id);
	msg.set_data(data.data());
}

void GlobalDBSetRequest_s::read_from_pbmsg(const ::proto_ff::GlobalDBSetRequest & msg) {
	type_id = msg.type_id();
	data = msg.data();
}

GlobalDBSetResponse_s::GlobalDBSetResponse_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int GlobalDBSetResponse_s::CreateInit() {
	retcode = (int32_t)0;
	type_id = (int32_t)0;
	return 0;
}

int GlobalDBSetResponse_s::ResumeInit() {
	return 0;
}

void GlobalDBSetResponse_s::write_to_pbmsg(::proto_ff::GlobalDBSetResponse & msg) const {
	msg.set_retcode((int32_t)retcode);
	msg.set_type_id((int32_t)type_id);
}

void GlobalDBSetResponse_s::read_from_pbmsg(const ::proto_ff::GlobalDBSetResponse & msg) {
	retcode = msg.retcode();
	type_id = msg.type_id();
}

GlobalComData_s::GlobalComData_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int GlobalComData_s::CreateInit() {
	return 0;
}

int GlobalComData_s::ResumeInit() {
	return 0;
}

void GlobalComData_s::write_to_pbmsg(::proto_ff::GlobalComData & msg) const {
	for(int32_t i = 0; i < (int32_t)towerDupReward.size(); ++i) {
		::proto_ff::DupTowerDBRecord* temp_towerdupreward = msg.add_towerdupreward();
		towerDupReward[i].write_to_pbmsg(*temp_towerdupreward);
	}
}

void GlobalComData_s::read_from_pbmsg(const ::proto_ff::GlobalComData & msg) {
	towerDupReward.resize((int)msg.towerdupreward_size() > (int)towerDupReward.max_size() ? towerDupReward.max_size() : msg.towerdupreward_size());
	for(int32_t i = 0; i < (int32_t)towerDupReward.size(); ++i) {
		const ::proto_ff::DupTowerDBRecord & temp_towerdupreward = msg.towerdupreward(i);
		towerDupReward[i].read_from_pbmsg(temp_towerdupreward);
	}
}

ActDBProto_s::ActDBProto_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int ActDBProto_s::CreateInit() {
	actid = (uint64_t)0;
	zid = (uint32_t)0;
	finishtime = (uint64_t)0;
	return 0;
}

int ActDBProto_s::ResumeInit() {
	return 0;
}

void ActDBProto_s::write_to_pbmsg(::proto_ff::ActDBProto & msg) const {
	msg.set_actid((uint64_t)actid);
	msg.set_zid((uint32_t)zid);
	msg.set_finishtime((uint64_t)finishtime);
}

void ActDBProto_s::read_from_pbmsg(const ::proto_ff::ActDBProto & msg) {
	actid = msg.actid();
	zid = msg.zid();
	finishtime = msg.finishtime();
}

ActDBReq_s::ActDBReq_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int ActDBReq_s::CreateInit() {
	return 0;
}

int ActDBReq_s::ResumeInit() {
	return 0;
}

void ActDBReq_s::write_to_pbmsg(::proto_ff::ActDBReq & msg) const {
}

void ActDBReq_s::read_from_pbmsg(const ::proto_ff::ActDBReq & msg) {
}

ActDBRsp_s::ActDBRsp_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int ActDBRsp_s::CreateInit() {
	return 0;
}

int ActDBRsp_s::ResumeInit() {
	return 0;
}

void ActDBRsp_s::write_to_pbmsg(::proto_ff::ActDBRsp & msg) const {
	for(int32_t i = 0; i < (int32_t)lst.size(); ++i) {
		::proto_ff::ActDBProto* temp_lst = msg.add_lst();
		lst[i].write_to_pbmsg(*temp_lst);
	}
}

void ActDBRsp_s::read_from_pbmsg(const ::proto_ff::ActDBRsp & msg) {
	lst.resize((int)msg.lst_size() > (int)lst.max_size() ? lst.max_size() : msg.lst_size());
	for(int32_t i = 0; i < (int32_t)lst.size(); ++i) {
		const ::proto_ff::ActDBProto & temp_lst = msg.lst(i);
		lst[i].read_from_pbmsg(temp_lst);
	}
}

ActSaveDBReq_s::ActSaveDBReq_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int ActSaveDBReq_s::CreateInit() {
	return 0;
}

int ActSaveDBReq_s::ResumeInit() {
	return 0;
}

void ActSaveDBReq_s::write_to_pbmsg(::proto_ff::ActSaveDBReq & msg) const {
	for(int32_t i = 0; i < (int32_t)lst.size(); ++i) {
		::proto_ff::ActDBProto* temp_lst = msg.add_lst();
		lst[i].write_to_pbmsg(*temp_lst);
	}
}

void ActSaveDBReq_s::read_from_pbmsg(const ::proto_ff::ActSaveDBReq & msg) {
	lst.resize((int)msg.lst_size() > (int)lst.max_size() ? lst.max_size() : msg.lst_size());
	for(int32_t i = 0; i < (int32_t)lst.size(); ++i) {
		const ::proto_ff::ActDBProto & temp_lst = msg.lst(i);
		lst[i].read_from_pbmsg(temp_lst);
	}
}

AllArenaDBRequest_s::AllArenaDBRequest_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int AllArenaDBRequest_s::CreateInit() {
	offset = (int32_t)0;
	retnum = (int32_t)0;
	return 0;
}

int AllArenaDBRequest_s::ResumeInit() {
	return 0;
}

void AllArenaDBRequest_s::write_to_pbmsg(::proto_ff::AllArenaDBRequest & msg) const {
	msg.set_offset((int32_t)offset);
	msg.set_retnum((int32_t)retnum);
}

void AllArenaDBRequest_s::read_from_pbmsg(const ::proto_ff::AllArenaDBRequest & msg) {
	offset = msg.offset();
	retnum = msg.retnum();
}

ArenaDBInfo_s::ArenaDBInfo_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int ArenaDBInfo_s::CreateInit() {
	charID = (uint64_t)0;
	rankId = (uint32_t)0;
	return 0;
}

int ArenaDBInfo_s::ResumeInit() {
	return 0;
}

void ArenaDBInfo_s::write_to_pbmsg(::proto_ff::ArenaDBInfo & msg) const {
	msg.set_charid((uint64_t)charID);
	msg.set_rankid((uint32_t)rankId);
}

void ArenaDBInfo_s::read_from_pbmsg(const ::proto_ff::ArenaDBInfo & msg) {
	charID = msg.charid();
	rankId = msg.rankid();
}

ArenaMoreDBInfo_s::ArenaMoreDBInfo_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int ArenaMoreDBInfo_s::CreateInit() {
	day = (uint32_t)0;
	giveReward = (uint32_t)0;
	max_rank = (uint32_t)0;
	return 0;
}

int ArenaMoreDBInfo_s::ResumeInit() {
	return 0;
}

void ArenaMoreDBInfo_s::write_to_pbmsg(::proto_ff::ArenaMoreDBInfo & msg) const {
	for(int32_t i = 0; i < (int32_t)info.size(); ++i) {
		::proto_ff::ArenaDBInfo* temp_info = msg.add_info();
		info[i].write_to_pbmsg(*temp_info);
	}
	msg.set_day((uint32_t)day);
	msg.set_givereward((uint32_t)giveReward);
	msg.set_max_rank((uint32_t)max_rank);
}

void ArenaMoreDBInfo_s::read_from_pbmsg(const ::proto_ff::ArenaMoreDBInfo & msg) {
	info.resize((int)msg.info_size() > (int)info.max_size() ? info.max_size() : msg.info_size());
	for(int32_t i = 0; i < (int32_t)info.size(); ++i) {
		const ::proto_ff::ArenaDBInfo & temp_info = msg.info(i);
		info[i].read_from_pbmsg(temp_info);
	}
	day = msg.day();
	giveReward = msg.givereward();
	max_rank = msg.max_rank();
}

AllArenaDBResponse_s::AllArenaDBResponse_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int AllArenaDBResponse_s::CreateInit() {
	retcode = (int32_t)0;
	offset = (int32_t)0;
	return 0;
}

int AllArenaDBResponse_s::ResumeInit() {
	return 0;
}

void AllArenaDBResponse_s::write_to_pbmsg(::proto_ff::AllArenaDBResponse & msg) const {
	msg.set_retcode((int32_t)retcode);
	msg.set_offset((int32_t)offset);
	for(int32_t i = 0; i < (int32_t)info.size(); ++i) {
		::proto_ff::ArenaDBInfo* temp_info = msg.add_info();
		info[i].write_to_pbmsg(*temp_info);
	}
}

void AllArenaDBResponse_s::read_from_pbmsg(const ::proto_ff::AllArenaDBResponse & msg) {
	retcode = msg.retcode();
	offset = msg.offset();
	info.resize((int)msg.info_size() > (int)info.max_size() ? info.max_size() : msg.info_size());
	for(int32_t i = 0; i < (int32_t)info.size(); ++i) {
		const ::proto_ff::ArenaDBInfo & temp_info = msg.info(i);
		info[i].read_from_pbmsg(temp_info);
	}
}

SaveArenaDBRequest_s::SaveArenaDBRequest_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int SaveArenaDBRequest_s::CreateInit() {
	return 0;
}

int SaveArenaDBRequest_s::ResumeInit() {
	return 0;
}

void SaveArenaDBRequest_s::write_to_pbmsg(::proto_ff::SaveArenaDBRequest & msg) const {
	for(int32_t i = 0; i < (int32_t)info.size(); ++i) {
		::proto_ff::ArenaDBInfo* temp_info = msg.add_info();
		info[i].write_to_pbmsg(*temp_info);
	}
}

void SaveArenaDBRequest_s::read_from_pbmsg(const ::proto_ff::SaveArenaDBRequest & msg) {
	info.resize((int)msg.info_size() > (int)info.max_size() ? info.max_size() : msg.info_size());
	for(int32_t i = 0; i < (int32_t)info.size(); ++i) {
		const ::proto_ff::ArenaDBInfo & temp_info = msg.info(i);
		info[i].read_from_pbmsg(temp_info);
	}
}

DeleteArenaDBRequest_s::DeleteArenaDBRequest_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int DeleteArenaDBRequest_s::CreateInit() {
	charId = (uint64_t)0;
	return 0;
}

int DeleteArenaDBRequest_s::ResumeInit() {
	return 0;
}

void DeleteArenaDBRequest_s::write_to_pbmsg(::proto_ff::DeleteArenaDBRequest & msg) const {
	msg.set_charid((uint64_t)charId);
}

void DeleteArenaDBRequest_s::read_from_pbmsg(const ::proto_ff::DeleteArenaDBRequest & msg) {
	charId = msg.charid();
}

RoleMirrorDBReq_s::RoleMirrorDBReq_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int RoleMirrorDBReq_s::CreateInit() {
	cid = (uint64_t)0;
	int_param = (int64_t)0;
	reqtype = (uint32_t)0;
	return 0;
}

int RoleMirrorDBReq_s::ResumeInit() {
	return 0;
}

void RoleMirrorDBReq_s::write_to_pbmsg(::proto_ff::RoleMirrorDBReq & msg) const {
	msg.set_cid((uint64_t)cid);
	msg.set_int_param((int64_t)int_param);
	msg.set_str_param(str_param.data());
	msg.set_reqtype((uint32_t)reqtype);
}

void RoleMirrorDBReq_s::read_from_pbmsg(const ::proto_ff::RoleMirrorDBReq & msg) {
	cid = msg.cid();
	int_param = msg.int_param();
	str_param = msg.str_param();
	reqtype = msg.reqtype();
}

RoleMirrorDBRsp_s::RoleMirrorDBRsp_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int RoleMirrorDBRsp_s::CreateInit() {
	ret = (int32_t)0;
	cid = (uint64_t)0;
	int_param = (int64_t)0;
	reqtype = (uint32_t)0;
	return 0;
}

int RoleMirrorDBRsp_s::ResumeInit() {
	return 0;
}

void RoleMirrorDBRsp_s::write_to_pbmsg(::proto_ff::RoleMirrorDBRsp & msg) const {
	msg.set_ret((int32_t)ret);
	msg.set_cid((uint64_t)cid);
	msg.set_int_param((int64_t)int_param);
	msg.set_str_param(str_param.data());
	msg.set_reqtype((uint32_t)reqtype);
	::proto_ff::RoleMirrorData* temp_data = msg.mutable_data();
	data.write_to_pbmsg(*temp_data);
}

void RoleMirrorDBRsp_s::read_from_pbmsg(const ::proto_ff::RoleMirrorDBRsp & msg) {
	ret = msg.ret();
	cid = msg.cid();
	int_param = msg.int_param();
	str_param = msg.str_param();
	reqtype = msg.reqtype();
	const ::proto_ff::RoleMirrorData & temp_data = msg.data();
	data.read_from_pbmsg(temp_data);
}

FactionDataDBReq_s::FactionDataDBReq_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int FactionDataDBReq_s::CreateInit() {
	return 0;
}

int FactionDataDBReq_s::ResumeInit() {
	return 0;
}

void FactionDataDBReq_s::write_to_pbmsg(::proto_ff::FactionDataDBReq & msg) const {
}

void FactionDataDBReq_s::read_from_pbmsg(const ::proto_ff::FactionDataDBReq & msg) {
}

FactionDataDBRsp_s::FactionDataDBRsp_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int FactionDataDBRsp_s::CreateInit() {
	finish = (int32_t)0;
	return 0;
}

int FactionDataDBRsp_s::ResumeInit() {
	return 0;
}

void FactionDataDBRsp_s::write_to_pbmsg(::proto_ff::FactionDataDBRsp & msg) const {
	for(int32_t i = 0; i < (int32_t)data_lst.size(); ++i) {
		::proto_ff::FactionAllDBData* temp_data_lst = msg.add_data_lst();
		data_lst[i].write_to_pbmsg(*temp_data_lst);
	}
	msg.set_finish((int32_t)finish);
}

void FactionDataDBRsp_s::read_from_pbmsg(const ::proto_ff::FactionDataDBRsp & msg) {
	data_lst.resize((int)msg.data_lst_size() > (int)data_lst.max_size() ? data_lst.max_size() : msg.data_lst_size());
	for(int32_t i = 0; i < (int32_t)data_lst.size(); ++i) {
		const ::proto_ff::FactionAllDBData & temp_data_lst = msg.data_lst(i);
		data_lst[i].read_from_pbmsg(temp_data_lst);
	}
	finish = msg.finish();
}

FactionSaveDBReq_s::FactionSaveDBReq_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int FactionSaveDBReq_s::CreateInit() {
	return 0;
}

int FactionSaveDBReq_s::ResumeInit() {
	return 0;
}

void FactionSaveDBReq_s::write_to_pbmsg(::proto_ff::FactionSaveDBReq & msg) const {
	::proto_ff::FactionAllDBData* temp_data = msg.mutable_data();
	data.write_to_pbmsg(*temp_data);
}

void FactionSaveDBReq_s::read_from_pbmsg(const ::proto_ff::FactionSaveDBReq & msg) {
	const ::proto_ff::FactionAllDBData & temp_data = msg.data();
	data.read_from_pbmsg(temp_data);
}

FactionDelDBReq_s::FactionDelDBReq_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int FactionDelDBReq_s::CreateInit() {
	faction_id = (uint32_t)0;
	return 0;
}

int FactionDelDBReq_s::ResumeInit() {
	return 0;
}

void FactionDelDBReq_s::write_to_pbmsg(::proto_ff::FactionDelDBReq & msg) const {
	msg.set_faction_id((uint32_t)faction_id);
}

void FactionDelDBReq_s::read_from_pbmsg(const ::proto_ff::FactionDelDBReq & msg) {
	faction_id = msg.faction_id();
}

FactionRedDBReq_s::FactionRedDBReq_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int FactionRedDBReq_s::CreateInit() {
	return 0;
}

int FactionRedDBReq_s::ResumeInit() {
	return 0;
}

void FactionRedDBReq_s::write_to_pbmsg(::proto_ff::FactionRedDBReq & msg) const {
}

void FactionRedDBReq_s::read_from_pbmsg(const ::proto_ff::FactionRedDBReq & msg) {
}

FactionRedDBRsp_s::FactionRedDBRsp_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int FactionRedDBRsp_s::CreateInit() {
	finish = (int32_t)0;
	return 0;
}

int FactionRedDBRsp_s::ResumeInit() {
	return 0;
}

void FactionRedDBRsp_s::write_to_pbmsg(::proto_ff::FactionRedDBRsp & msg) const {
	for(int32_t i = 0; i < (int32_t)data_lst.size(); ++i) {
		::proto_ff::RedDBData* temp_data_lst = msg.add_data_lst();
		data_lst[i].write_to_pbmsg(*temp_data_lst);
	}
	msg.set_finish((int32_t)finish);
}

void FactionRedDBRsp_s::read_from_pbmsg(const ::proto_ff::FactionRedDBRsp & msg) {
	data_lst.resize((int)msg.data_lst_size() > (int)data_lst.max_size() ? data_lst.max_size() : msg.data_lst_size());
	for(int32_t i = 0; i < (int32_t)data_lst.size(); ++i) {
		const ::proto_ff::RedDBData & temp_data_lst = msg.data_lst(i);
		data_lst[i].read_from_pbmsg(temp_data_lst);
	}
	finish = msg.finish();
}

FactionRedSaveDBReq_s::FactionRedSaveDBReq_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int FactionRedSaveDBReq_s::CreateInit() {
	faction_id = (uint32_t)0;
	return 0;
}

int FactionRedSaveDBReq_s::ResumeInit() {
	return 0;
}

void FactionRedSaveDBReq_s::write_to_pbmsg(::proto_ff::FactionRedSaveDBReq & msg) const {
	msg.set_faction_id((uint32_t)faction_id);
	::proto_ff::RedDBData* temp_data0 = msg.mutable_data0();
	data0.write_to_pbmsg(*temp_data0);
	::proto_ff::RedDBData* temp_data1 = msg.mutable_data1();
	data1.write_to_pbmsg(*temp_data1);
	::proto_ff::RedDBData* temp_data2 = msg.mutable_data2();
	data2.write_to_pbmsg(*temp_data2);
}

void FactionRedSaveDBReq_s::read_from_pbmsg(const ::proto_ff::FactionRedSaveDBReq & msg) {
	faction_id = msg.faction_id();
	const ::proto_ff::RedDBData & temp_data0 = msg.data0();
	data0.read_from_pbmsg(temp_data0);
	const ::proto_ff::RedDBData & temp_data1 = msg.data1();
	data1.read_from_pbmsg(temp_data1);
	const ::proto_ff::RedDBData & temp_data2 = msg.data2();
	data2.read_from_pbmsg(temp_data2);
}

FactionRedDelDBReq_s::FactionRedDelDBReq_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int FactionRedDelDBReq_s::CreateInit() {
	faction_id = (uint32_t)0;
	return 0;
}

int FactionRedDelDBReq_s::ResumeInit() {
	return 0;
}

void FactionRedDelDBReq_s::write_to_pbmsg(::proto_ff::FactionRedDelDBReq & msg) const {
	msg.set_faction_id((uint32_t)faction_id);
}

void FactionRedDelDBReq_s::read_from_pbmsg(const ::proto_ff::FactionRedDelDBReq & msg) {
	faction_id = msg.faction_id();
}

RoleRedDBReq_s::RoleRedDBReq_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int RoleRedDBReq_s::CreateInit() {
	return 0;
}

int RoleRedDBReq_s::ResumeInit() {
	return 0;
}

void RoleRedDBReq_s::write_to_pbmsg(::proto_ff::RoleRedDBReq & msg) const {
}

void RoleRedDBReq_s::read_from_pbmsg(const ::proto_ff::RoleRedDBReq & msg) {
}

RoleRedDBRsp_s::RoleRedDBRsp_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int RoleRedDBRsp_s::CreateInit() {
	finish = (int32_t)0;
	return 0;
}

int RoleRedDBRsp_s::ResumeInit() {
	return 0;
}

void RoleRedDBRsp_s::write_to_pbmsg(::proto_ff::RoleRedDBRsp & msg) const {
	for(int32_t i = 0; i < (int32_t)data_lst.size(); ++i) {
		::proto_ff::RoleRedDBData* temp_data_lst = msg.add_data_lst();
		data_lst[i].write_to_pbmsg(*temp_data_lst);
	}
	msg.set_finish((int32_t)finish);
}

void RoleRedDBRsp_s::read_from_pbmsg(const ::proto_ff::RoleRedDBRsp & msg) {
	data_lst.resize((int)msg.data_lst_size() > (int)data_lst.max_size() ? data_lst.max_size() : msg.data_lst_size());
	for(int32_t i = 0; i < (int32_t)data_lst.size(); ++i) {
		const ::proto_ff::RoleRedDBData & temp_data_lst = msg.data_lst(i);
		data_lst[i].read_from_pbmsg(temp_data_lst);
	}
	finish = msg.finish();
}

CenterLoadRoleDBReq_s::CenterLoadRoleDBReq_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int CenterLoadRoleDBReq_s::CreateInit() {
	cid = (uint64_t)0;
	cmd = (uint32_t)0;
	return 0;
}

int CenterLoadRoleDBReq_s::ResumeInit() {
	return 0;
}

void CenterLoadRoleDBReq_s::write_to_pbmsg(::proto_ff::CenterLoadRoleDBReq & msg) const {
	msg.set_cid((uint64_t)cid);
	msg.set_table_name(table_name.data());
	msg.set_cmd((uint32_t)cmd);
}

void CenterLoadRoleDBReq_s::read_from_pbmsg(const ::proto_ff::CenterLoadRoleDBReq & msg) {
	cid = msg.cid();
	table_name = msg.table_name();
	cmd = msg.cmd();
}

CenterLoadRoleDBRsp_s::CenterLoadRoleDBRsp_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int CenterLoadRoleDBRsp_s::CreateInit() {
	cid = (uint64_t)0;
	return 0;
}

int CenterLoadRoleDBRsp_s::ResumeInit() {
	return 0;
}

void CenterLoadRoleDBRsp_s::write_to_pbmsg(::proto_ff::CenterLoadRoleDBRsp & msg) const {
	msg.set_cid((uint64_t)cid);
	msg.set_data(data.data());
}

void CenterLoadRoleDBRsp_s::read_from_pbmsg(const ::proto_ff::CenterLoadRoleDBRsp & msg) {
	cid = msg.cid();
	data = msg.data();
}

CenterSaveRoleDBReq_s::CenterSaveRoleDBReq_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int CenterSaveRoleDBReq_s::CreateInit() {
	cid = (uint64_t)0;
	return 0;
}

int CenterSaveRoleDBReq_s::ResumeInit() {
	return 0;
}

void CenterSaveRoleDBReq_s::write_to_pbmsg(::proto_ff::CenterSaveRoleDBReq & msg) const {
	msg.set_cid((uint64_t)cid);
	msg.set_data(data.data());
	msg.set_table_name(table_name.data());
}

void CenterSaveRoleDBReq_s::read_from_pbmsg(const ::proto_ff::CenterSaveRoleDBReq & msg) {
	cid = msg.cid();
	data = msg.data();
	table_name = msg.table_name();
}

}
