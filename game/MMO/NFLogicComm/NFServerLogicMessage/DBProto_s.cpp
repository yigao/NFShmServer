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
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct RoleReliveProto_s));
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
	return 0;
}

int RoleDBBaseData_s::ResumeInit() {
	return 0;
}

void RoleDBBaseData_s::write_to_pbmsg(::proto_ff::RoleDBBaseData & msg) const {
	msg.set_name((const char*)name.data());
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
}

void RoleDBBaseData_s::read_from_pbmsg(const ::proto_ff::RoleDBBaseData & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct RoleDBBaseData_s));
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
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct BagItemsDBData_s));
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
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct BagDBSimpleData_s));
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
	msg.set_table_name((const char*)table_name.data());
	::proto_ff::BagDBSimpleData* temp_simple = msg.mutable_simple();
	simple.write_to_pbmsg(*temp_simple);
	for(int32_t i = 0; i < (int32_t)parts.size(); ++i) {
		::proto_ff::BagItemsDBData* temp_parts = msg.add_parts();
		parts[i].write_to_pbmsg(*temp_parts);
	}
}

void RoleDBUnitBagData_s::read_from_pbmsg(const ::proto_ff::RoleDBUnitBagData & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct RoleDBUnitBagData_s));
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
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct RoleDBBagData_s));
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
}

void RoleDBEquipData_s::read_from_pbmsg(const ::proto_ff::RoleDBEquipData & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct RoleDBEquipData_s));
	infos.resize((int)msg.infos_size() > (int)infos.max_size() ? infos.max_size() : msg.infos_size());
	for(int32_t i = 0; i < (int32_t)infos.size(); ++i) {
		const ::proto_ff::EquipInfo & temp_infos = msg.infos(i);
		infos[i].read_from_pbmsg(temp_infos);
	}
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
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct RoleDBTaskData_s));
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
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct GrowPartEntryDBInfo_s));
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
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct GrowPartDBData_s));
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
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct GrowDBData_s));
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
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct DayUseItemData_s));
	info.resize((int)msg.info_size() > (int)info.max_size() ? info.max_size() : msg.info_size());
	for(int32_t i = 0; i < (int32_t)info.size(); ++i) {
		const ::proto_ff::ComPair64 & temp_info = msg.info(i);
		info[i].read_from_pbmsg(temp_info);
	}
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
}

void MiniDBData_s::read_from_pbmsg(const ::proto_ff::MiniDBData & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct MiniDBData_s));
	lastTime = msg.lasttime();
	const ::proto_ff::DayUseItemData & temp_useitem = msg.useitem();
	useItem.read_from_pbmsg(temp_useitem);
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
}

void FacadeDataInfo_s::read_from_pbmsg(const ::proto_ff::FacadeDataInfo & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct FacadeDataInfo_s));
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
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct FacadeDBData_s));
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
	advance = (int32_t)0;
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
	msg.set_advance((int32_t)advance);
	msg.set_use_msc((int64_t)use_msc);
}

void SkillDBInfo_s::read_from_pbmsg(const ::proto_ff::SkillDBInfo & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct SkillDBInfo_s));
	skill_id = msg.skill_id();
	level = msg.level();
	wakeup = msg.wakeup();
	advance = msg.advance();
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
	return 0;
}

int SkillDBPos_s::ResumeInit() {
	return 0;
}

void SkillDBPos_s::write_to_pbmsg(::proto_ff::SkillDBPos & msg) const {
	msg.set_skill_id((uint64_t)skill_id);
	msg.set_pos((uint32_t)pos);
}

void SkillDBPos_s::read_from_pbmsg(const ::proto_ff::SkillDBPos & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct SkillDBPos_s));
	skill_id = msg.skill_id();
	pos = msg.pos();
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
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct SkillDBGroup_s));
	group = msg.group();
	chg = msg.chg();
	pos_lst.resize((int)msg.pos_lst_size() > (int)pos_lst.max_size() ? pos_lst.max_size() : msg.pos_lst_size());
	for(int32_t i = 0; i < (int32_t)pos_lst.size(); ++i) {
		const ::proto_ff::SkillDBPos & temp_pos_lst = msg.pos_lst(i);
		pos_lst[i].read_from_pbmsg(temp_pos_lst);
	}
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
}

void SkillDBData_s::read_from_pbmsg(const ::proto_ff::SkillDBData & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct SkillDBData_s));
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
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct GodRelicsActivityData_s));
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
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct MiniActivityDBData_s));
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
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct DupRecord_s));
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
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct DupGroupData_s));
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
	msg.set_name((const char*)name.data());
	msg.set_time((uint64_t)time);
	msg.set_cid((uint64_t)cid);
}

void DupTowerDBRecordEntry_s::read_from_pbmsg(const ::proto_ff::DupTowerDBRecordEntry & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct DupTowerDBRecordEntry_s));
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
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct DupTowerDBRecord_s));
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
	pass_dupId = (uint64_t)0;
	return 0;
}

int DupTowerDBData_s::ResumeInit() {
	return 0;
}

void DupTowerDBData_s::write_to_pbmsg(::proto_ff::DupTowerDBData & msg) const {
	msg.set_pass_dupid((uint64_t)pass_dupId);
	for(int32_t i = 0; i < (int32_t)ids.size(); ++i) {
		msg.add_ids((uint64_t)ids[i]);
	}
}

void DupTowerDBData_s::read_from_pbmsg(const ::proto_ff::DupTowerDBData & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct DupTowerDBData_s));
	pass_dupId = msg.pass_dupid();
	ids.resize((int)msg.ids_size() > (int)ids.max_size() ? ids.max_size() : msg.ids_size());
	for(int32_t i = 0; i < (int32_t)ids.size(); ++i) {
		ids[i] = msg.ids(i);
	}
}

ComDupDBData_s::ComDupDBData_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int ComDupDBData_s::CreateInit() {
	pass_dupId = (uint64_t)0;
	star = (int32_t)0;
	return 0;
}

int ComDupDBData_s::ResumeInit() {
	return 0;
}

void ComDupDBData_s::write_to_pbmsg(::proto_ff::ComDupDBData & msg) const {
	msg.set_pass_dupid((uint64_t)pass_dupId);
	msg.set_star((int32_t)star);
}

void ComDupDBData_s::read_from_pbmsg(const ::proto_ff::ComDupDBData & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct ComDupDBData_s));
	pass_dupId = msg.pass_dupid();
	star = msg.star();
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
	::proto_ff::ComDupDBData* temp_level = msg.mutable_level();
	level.write_to_pbmsg(*temp_level);
}

void DupDBData_s::read_from_pbmsg(const ::proto_ff::DupDBData & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct DupDBData_s));
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
	const ::proto_ff::ComDupDBData & temp_level = msg.level();
	level.read_from_pbmsg(temp_level);
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
}

void BuffDBInfo_s::read_from_pbmsg(const ::proto_ff::BuffDBInfo & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct BuffDBInfo_s));
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
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct BuffDBCdInfo_s));
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
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct BuffDBData_s));
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
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct BossSimpleInfoDB_s));
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
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct BossDBData_s));
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
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct VipDBData_s));
	vipExp = msg.vipexp();
	expDiamond = msg.expdiamond();
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
}

void RoleDBData_s::read_from_pbmsg(const ::proto_ff::RoleDBData & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct RoleDBData_s));
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
}

LoginRoleDBProto_s::LoginRoleDBProto_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int LoginRoleDBProto_s::CreateInit() {
	return 0;
}

int LoginRoleDBProto_s::ResumeInit() {
	return 0;
}

void LoginRoleDBProto_s::write_to_pbmsg(::proto_ff::LoginRoleDBProto & msg) const {
}

void LoginRoleDBProto_s::read_from_pbmsg(const ::proto_ff::LoginRoleDBProto & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct LoginRoleDBProto_s));
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
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct RoleListDBReq_s));
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
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct RoleListDBRsp_s));
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
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct CreateRoleDBReq_s));
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
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct CreateRoleDBRsp_s));
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
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct RoleInfoDBReq_s));
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
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct RoleInfoDBRsp_s));
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
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct RoleInfoUpdateDBReq_s));
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
	msg.set_name((const char*)name.data());
}

void RoleChgNameDBReq_s::read_from_pbmsg(const ::proto_ff::RoleChgNameDBReq & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct RoleChgNameDBReq_s));
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
	msg.set_name((const char*)name.data());
}

void RoleChgNameDBRsp_s::read_from_pbmsg(const ::proto_ff::RoleChgNameDBRsp & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct RoleChgNameDBRsp_s));
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
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct RoleSimpleListDBReq_s));
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
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct RoleSimpleListDBRsp_s));
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
	msg.set_trans_data((const char*)trans_data.data());
}

void CreatureTransLogicDBReq_s::read_from_pbmsg(const ::proto_ff::CreatureTransLogicDBReq & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct CreatureTransLogicDBReq_s));
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
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct CreatureTransLogicDBRsp_s));
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
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct NewMailDBInfo_s));
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
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct MailDBOperateInfo_s));
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
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct SaveMailDBReq_s));
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
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct SaveMailDBRsp_s));
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
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct CharacterMailDBRequest_s));
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
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct CharacterMailDBResponse_s));
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
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct MaxMailIDRequest_s));
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
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct MaxMailIDResponse_s));
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
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct DeleteCharacterMail_s));
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
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct ZoneMailSaveRsp_s));
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
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct ZoneMailTransCharacterMailReq_s));
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
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct ZoneMailTransCharacterMailRsp_s));
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
	msg.set_webid((const char*)webId.data());
}

void WebMailDBDataReq_s::read_from_pbmsg(const ::proto_ff::WebMailDBDataReq & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct WebMailDBDataReq_s));
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
	msg.set_webid((const char*)webId.data());
}

void WebMailDBDataRsp_s::read_from_pbmsg(const ::proto_ff::WebMailDBDataRsp & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct WebMailDBDataRsp_s));
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
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct FriendDBInfo_s));
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
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct FriendDBRequest_s));
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
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct FriendDBResponse_s));
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
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct AllFriendDBRequest_s));
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
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct AllFriendDBResponse_s));
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
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct SaveFriendDBRequest_s));
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
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct DelteFriendDBRequest_s));
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
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct GlobalDBRequst_s));
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
}

void GlobalDBEntry_s::read_from_pbmsg(const ::proto_ff::GlobalDBEntry & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct GlobalDBEntry_s));
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
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct GlobalDBResponse_s));
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
}

void GlobalDBSetRequest_s::read_from_pbmsg(const ::proto_ff::GlobalDBSetRequest & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct GlobalDBSetRequest_s));
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
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct GlobalDBSetResponse_s));
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
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct GlobalComData_s));
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
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct ActDBProto_s));
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
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct ActDBReq_s));
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
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct ActDBRsp_s));
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
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct ActSaveDBReq_s));
	lst.resize((int)msg.lst_size() > (int)lst.max_size() ? lst.max_size() : msg.lst_size());
	for(int32_t i = 0; i < (int32_t)lst.size(); ++i) {
		const ::proto_ff::ActDBProto & temp_lst = msg.lst(i);
		lst[i].read_from_pbmsg(temp_lst);
	}
}

}