#include "Com_s.h"

namespace proto_ff_s {

EmptyMessage_s::EmptyMessage_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int EmptyMessage_s::CreateInit() {
	return 0;
}

int EmptyMessage_s::ResumeInit() {
	return 0;
}

void EmptyMessage_s::write_to_pbmsg(::proto_ff::EmptyMessage & msg) const {
}

void EmptyMessage_s::read_from_pbmsg(const ::proto_ff::EmptyMessage & msg) {
}

ComPair_s::ComPair_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int ComPair_s::CreateInit() {
	key = (uint32_t)0;
	value = (uint32_t)0;
	return 0;
}

int ComPair_s::ResumeInit() {
	return 0;
}

void ComPair_s::write_to_pbmsg(::proto_ff::ComPair & msg) const {
	msg.set_key((uint32_t)key);
	msg.set_value((uint32_t)value);
}

void ComPair_s::read_from_pbmsg(const ::proto_ff::ComPair & msg) {
	key = msg.key();
	value = msg.value();
}

ComPair64_s::ComPair64_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int ComPair64_s::CreateInit() {
	key = (uint64_t)0;
	value = (uint64_t)0;
	return 0;
}

int ComPair64_s::ResumeInit() {
	return 0;
}

void ComPair64_s::write_to_pbmsg(::proto_ff::ComPair64 & msg) const {
	msg.set_key((uint64_t)key);
	msg.set_value((uint64_t)value);
}

void ComPair64_s::read_from_pbmsg(const ::proto_ff::ComPair64 & msg) {
	key = msg.key();
	value = msg.value();
}

ComPairBool_s::ComPairBool_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int ComPairBool_s::CreateInit() {
	key = (uint32_t)0;
	value = (bool)0;
	return 0;
}

int ComPairBool_s::ResumeInit() {
	return 0;
}

void ComPairBool_s::write_to_pbmsg(::proto_ff::ComPairBool & msg) const {
	msg.set_key((uint32_t)key);
	msg.set_value((bool)value);
}

void ComPairBool_s::read_from_pbmsg(const ::proto_ff::ComPairBool & msg) {
	key = msg.key();
	value = msg.value();
}

ComItem_s::ComItem_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int ComItem_s::CreateInit() {
	item_id = (uint64_t)0;
	item_num = (uint64_t)0;
	return 0;
}

int ComItem_s::ResumeInit() {
	return 0;
}

void ComItem_s::write_to_pbmsg(::proto_ff::ComItem & msg) const {
	msg.set_item_id((uint64_t)item_id);
	msg.set_item_num((uint64_t)item_num);
}

void ComItem_s::read_from_pbmsg(const ::proto_ff::ComItem & msg) {
	item_id = msg.item_id();
	item_num = msg.item_num();
}

ComItemWithType_s::ComItemWithType_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int ComItemWithType_s::CreateInit() {
	item_id = (uint64_t)0;
	item_num = (uint64_t)0;
	type = (uint32_t)0;
	return 0;
}

int ComItemWithType_s::ResumeInit() {
	return 0;
}

void ComItemWithType_s::write_to_pbmsg(::proto_ff::ComItemWithType & msg) const {
	msg.set_item_id((uint64_t)item_id);
	msg.set_item_num((uint64_t)item_num);
	msg.set_type((uint32_t)type);
}

void ComItemWithType_s::read_from_pbmsg(const ::proto_ff::ComItemWithType & msg) {
	item_id = msg.item_id();
	item_num = msg.item_num();
	type = msg.type();
}

Vector3PB_s::Vector3PB_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Vector3PB_s::CreateInit() {
	x = (float)0;
	y = (float)0;
	z = (float)0;
	return 0;
}

int Vector3PB_s::ResumeInit() {
	return 0;
}

void Vector3PB_s::write_to_pbmsg(::proto_ff::Vector3PB & msg) const {
	msg.set_x((float)x);
	msg.set_y((float)y);
	msg.set_z((float)z);
}

void Vector3PB_s::read_from_pbmsg(const ::proto_ff::Vector3PB & msg) {
	x = msg.x();
	y = msg.y();
	z = msg.z();
}

Vector2PB_s::Vector2PB_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Vector2PB_s::CreateInit() {
	x = (float)0;
	y = (float)0;
	return 0;
}

int Vector2PB_s::ResumeInit() {
	return 0;
}

void Vector2PB_s::write_to_pbmsg(::proto_ff::Vector2PB & msg) const {
	msg.set_x((float)x);
	msg.set_y((float)y);
}

void Vector2PB_s::read_from_pbmsg(const ::proto_ff::Vector2PB & msg) {
	x = msg.x();
	y = msg.y();
}

Attr64_s::Attr64_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Attr64_s::CreateInit() {
	id = (uint32_t)0;
	value = (int64_t)0;
	return 0;
}

int Attr64_s::ResumeInit() {
	return 0;
}

void Attr64_s::write_to_pbmsg(::proto_ff::Attr64 & msg) const {
	msg.set_id((uint32_t)id);
	msg.set_value((int64_t)value);
}

void Attr64_s::read_from_pbmsg(const ::proto_ff::Attr64 & msg) {
	id = msg.id();
	value = msg.value();
}

RoleFacadeProto_s::RoleFacadeProto_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int RoleFacadeProto_s::CreateInit() {
	color = (int32_t)0;
	prof = (int32_t)0;
	return 0;
}

int RoleFacadeProto_s::ResumeInit() {
	return 0;
}

void RoleFacadeProto_s::write_to_pbmsg(::proto_ff::RoleFacadeProto & msg) const {
	for(int32_t i = 0; i < (int32_t)growFacade.size(); ++i) {
		::proto_ff::Attr64* temp_growfacade = msg.add_growfacade();
		growFacade[i].write_to_pbmsg(*temp_growfacade);
	}
	msg.set_color((int32_t)color);
	msg.set_prof((int32_t)prof);
}

void RoleFacadeProto_s::read_from_pbmsg(const ::proto_ff::RoleFacadeProto & msg) {
	growFacade.resize((int)msg.growfacade_size() > (int)growFacade.max_size() ? growFacade.max_size() : msg.growfacade_size());
	for(int32_t i = 0; i < (int32_t)growFacade.size(); ++i) {
		const ::proto_ff::Attr64 & temp_growfacade = msg.growfacade(i);
		growFacade[i].read_from_pbmsg(temp_growfacade);
	}
	color = msg.color();
	prof = msg.prof();
}

RoleListDBProto_s::RoleListDBProto_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int RoleListDBProto_s::CreateInit() {
	cid = (uint64_t)0;
	prof = (uint32_t)0;
	level = (uint32_t)0;
	fight = (uint64_t)0;
	createtime = (uint64_t)0;
	sceneid = (uint64_t)0;
	mapid = (uint64_t)0;
	lastsceneid = (uint64_t)0;
	lastmapid = (uint64_t)0;
	return 0;
}

int RoleListDBProto_s::ResumeInit() {
	return 0;
}

void RoleListDBProto_s::write_to_pbmsg(::proto_ff::RoleListDBProto & msg) const {
	msg.set_cid((uint64_t)cid);
	msg.set_name(name.data());
	msg.set_prof((uint32_t)prof);
	msg.set_level((uint32_t)level);
	msg.set_fight((uint64_t)fight);
	msg.set_createtime((uint64_t)createtime);
	::proto_ff::RoleFacadeProto* temp_facade = msg.mutable_facade();
	facade.write_to_pbmsg(*temp_facade);
	msg.set_sceneid((uint64_t)sceneid);
	msg.set_mapid((uint64_t)mapid);
	::proto_ff::Vector3PB* temp_pos = msg.mutable_pos();
	pos.write_to_pbmsg(*temp_pos);
	msg.set_lastsceneid((uint64_t)lastsceneid);
	msg.set_lastmapid((uint64_t)lastmapid);
	::proto_ff::Vector3PB* temp_lastpos = msg.mutable_lastpos();
	lastpos.write_to_pbmsg(*temp_lastpos);
}

void RoleListDBProto_s::read_from_pbmsg(const ::proto_ff::RoleListDBProto & msg) {
	cid = msg.cid();
	name = msg.name();
	prof = msg.prof();
	level = msg.level();
	fight = msg.fight();
	createtime = msg.createtime();
	const ::proto_ff::RoleFacadeProto & temp_facade = msg.facade();
	facade.read_from_pbmsg(temp_facade);
	sceneid = msg.sceneid();
	mapid = msg.mapid();
	const ::proto_ff::Vector3PB & temp_pos = msg.pos();
	pos.read_from_pbmsg(temp_pos);
	lastsceneid = msg.lastsceneid();
	lastmapid = msg.lastmapid();
	const ::proto_ff::Vector3PB & temp_lastpos = msg.lastpos();
	lastpos.read_from_pbmsg(temp_lastpos);
}

LoginRoleProto_s::LoginRoleProto_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int LoginRoleProto_s::CreateInit() {
	cid = (uint64_t)0;
	prof = (uint32_t)0;
	level = (uint32_t)0;
	fight = (uint64_t)0;
	createtime = (uint64_t)0;
	return 0;
}

int LoginRoleProto_s::ResumeInit() {
	return 0;
}

void LoginRoleProto_s::write_to_pbmsg(::proto_ff::LoginRoleProto & msg) const {
	msg.set_cid((uint64_t)cid);
	msg.set_name(name.data());
	msg.set_prof((uint32_t)prof);
	msg.set_level((uint32_t)level);
	msg.set_fight((uint64_t)fight);
	msg.set_createtime((uint64_t)createtime);
	::proto_ff::RoleFacadeProto* temp_facade = msg.mutable_facade();
	facade.write_to_pbmsg(*temp_facade);
}

void LoginRoleProto_s::read_from_pbmsg(const ::proto_ff::LoginRoleProto & msg) {
	cid = msg.cid();
	name = msg.name();
	prof = msg.prof();
	level = msg.level();
	fight = msg.fight();
	createtime = msg.createtime();
	const ::proto_ff::RoleFacadeProto & temp_facade = msg.facade();
	facade.read_from_pbmsg(temp_facade);
}

LoginSyncProto_s::LoginSyncProto_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int LoginSyncProto_s::CreateInit() {
	faction_id = (uint32_t)0;
	duty = (int32_t)0;
	faction_leader = (uint64_t)0;
	faction_level = (int32_t)0;
	team_id = (uint32_t)0;
	leader = (uint64_t)0;
	mem_count = (int32_t)0;
	cloness_lev = (int32_t)0;
	return 0;
}

int LoginSyncProto_s::ResumeInit() {
	return 0;
}

void LoginSyncProto_s::write_to_pbmsg(::proto_ff::LoginSyncProto & msg) const {
	msg.set_faction_id((uint32_t)faction_id);
	msg.set_faction_name(faction_name.data());
	msg.set_duty((int32_t)duty);
	msg.set_faction_leader((uint64_t)faction_leader);
	msg.set_faction_level((int32_t)faction_level);
	msg.set_team_id((uint32_t)team_id);
	msg.set_leader((uint64_t)leader);
	msg.set_mem_count((int32_t)mem_count);
	msg.set_cloness_lev((int32_t)cloness_lev);
}

void LoginSyncProto_s::read_from_pbmsg(const ::proto_ff::LoginSyncProto & msg) {
	faction_id = msg.faction_id();
	faction_name = msg.faction_name();
	duty = msg.duty();
	faction_leader = msg.faction_leader();
	faction_level = msg.faction_level();
	team_id = msg.team_id();
	leader = msg.leader();
	mem_count = msg.mem_count();
	cloness_lev = msg.cloness_lev();
}

CenterRoleProto_s::CenterRoleProto_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int CenterRoleProto_s::CreateInit() {
	cid = (uint64_t)0;
	uid = (uint32_t)0;
	level = (uint32_t)0;
	fight = (uint64_t)0;
	lastlogout = (uint64_t)0;
	vip_level = (uint32_t)0;
	hp = (int64_t)0;
	max_hp = (int64_t)0;
	return 0;
}

int CenterRoleProto_s::ResumeInit() {
	return 0;
}

void CenterRoleProto_s::write_to_pbmsg(::proto_ff::CenterRoleProto & msg) const {
	msg.set_cid((uint64_t)cid);
	msg.set_uid((uint32_t)uid);
	msg.set_name(name.data());
	msg.set_level((uint32_t)level);
	msg.set_fight((uint64_t)fight);
	msg.set_lastlogout((uint64_t)lastlogout);
	::proto_ff::RoleFacadeProto* temp_facade = msg.mutable_facade();
	facade.write_to_pbmsg(*temp_facade);
	msg.set_vip_level((uint32_t)vip_level);
	msg.set_hp((int64_t)hp);
	msg.set_max_hp((int64_t)max_hp);
}

void CenterRoleProto_s::read_from_pbmsg(const ::proto_ff::CenterRoleProto & msg) {
	cid = msg.cid();
	uid = msg.uid();
	name = msg.name();
	level = msg.level();
	fight = msg.fight();
	lastlogout = msg.lastlogout();
	const ::proto_ff::RoleFacadeProto & temp_facade = msg.facade();
	facade.read_from_pbmsg(temp_facade);
	vip_level = msg.vip_level();
	hp = msg.hp();
	max_hp = msg.max_hp();
}

SocialRoleProto_s::SocialRoleProto_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int SocialRoleProto_s::CreateInit() {
	cid = (uint64_t)0;
	uid = (uint32_t)0;
	prof = (uint32_t)0;
	level = (uint32_t)0;
	fight = (uint64_t)0;
	lastlogout = (uint64_t)0;
	vip_level = (uint32_t)0;
	zid = (uint32_t)0;
	isonline = (bool)0;
	hp = (int64_t)0;
	max_hp = (int64_t)0;
	sceneid = (uint64_t)0;
	mapid = (uint64_t)0;
	return 0;
}

int SocialRoleProto_s::ResumeInit() {
	return 0;
}

void SocialRoleProto_s::write_to_pbmsg(::proto_ff::SocialRoleProto & msg) const {
	msg.set_cid((uint64_t)cid);
	msg.set_uid((uint32_t)uid);
	msg.set_name(name.data());
	msg.set_prof((uint32_t)prof);
	msg.set_level((uint32_t)level);
	msg.set_fight((uint64_t)fight);
	msg.set_lastlogout((uint64_t)lastlogout);
	::proto_ff::RoleFacadeProto* temp_facade = msg.mutable_facade();
	facade.write_to_pbmsg(*temp_facade);
	msg.set_vip_level((uint32_t)vip_level);
	msg.set_zid((uint32_t)zid);
	msg.set_isonline((bool)isonline);
	msg.set_hp((int64_t)hp);
	msg.set_max_hp((int64_t)max_hp);
	msg.set_sceneid((uint64_t)sceneid);
	msg.set_mapid((uint64_t)mapid);
}

void SocialRoleProto_s::read_from_pbmsg(const ::proto_ff::SocialRoleProto & msg) {
	cid = msg.cid();
	uid = msg.uid();
	name = msg.name();
	prof = msg.prof();
	level = msg.level();
	fight = msg.fight();
	lastlogout = msg.lastlogout();
	const ::proto_ff::RoleFacadeProto & temp_facade = msg.facade();
	facade.read_from_pbmsg(temp_facade);
	vip_level = msg.vip_level();
	zid = msg.zid();
	isonline = msg.isonline();
	hp = msg.hp();
	max_hp = msg.max_hp();
	sceneid = msg.sceneid();
	mapid = msg.mapid();
}

Attr_s::Attr_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Attr_s::CreateInit() {
	id = (uint32_t)0;
	value = (uint32_t)0;
	return 0;
}

int Attr_s::ResumeInit() {
	return 0;
}

void Attr_s::write_to_pbmsg(::proto_ff::Attr & msg) const {
	msg.set_id((uint32_t)id);
	msg.set_value((uint32_t)value);
}

void Attr_s::read_from_pbmsg(const ::proto_ff::Attr & msg) {
	id = msg.id();
	value = msg.value();
}

BlueStarAttr_s::BlueStarAttr_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int BlueStarAttr_s::CreateInit() {
	id = (uint32_t)0;
	value = (int64_t)0;
	lv_part = (int32_t)0;
	return 0;
}

int BlueStarAttr_s::ResumeInit() {
	return 0;
}

void BlueStarAttr_s::write_to_pbmsg(::proto_ff::BlueStarAttr & msg) const {
	msg.set_id((uint32_t)id);
	msg.set_value((int64_t)value);
	msg.set_lv_part((int32_t)lv_part);
}

void BlueStarAttr_s::read_from_pbmsg(const ::proto_ff::BlueStarAttr & msg) {
	id = msg.id();
	value = msg.value();
	lv_part = msg.lv_part();
}

PetInfo_s::PetInfo_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int PetInfo_s::CreateInit() {
	instId = (int32_t)0;
	cfgid = (int64_t)0;
	lv = (int32_t)0;
	steplv = (int32_t)0;
	starlv = (int32_t)0;
	activeSkillLv = (int32_t)0;
	initgrow = (float)0;
	slot = (int32_t)0;
	lvexp = (int32_t)0;
	return 0;
}

int PetInfo_s::ResumeInit() {
	return 0;
}

void PetInfo_s::write_to_pbmsg(::proto_ff::PetInfo & msg) const {
	msg.set_instid((int32_t)instId);
	msg.set_cfgid((int64_t)cfgid);
	msg.set_lv((int32_t)lv);
	msg.set_steplv((int32_t)steplv);
	msg.set_starlv((int32_t)starlv);
	msg.set_activeskilllv((int32_t)activeSkillLv);
	for(int32_t i = 0; i < (int32_t)exclusiveSkillLvVec.size(); ++i) {
		msg.add_exclusiveskilllvvec((int32_t)exclusiveSkillLvVec[i]);
	}
	for(int32_t i = 0; i < (int32_t)passiveSkillLvVec.size(); ++i) {
		msg.add_passiveskilllvvec((int32_t)passiveSkillLvVec[i]);
	}
	msg.set_initgrow((float)initgrow);
	msg.set_slot((int32_t)slot);
	msg.set_lvexp((int32_t)lvexp);
}

void PetInfo_s::read_from_pbmsg(const ::proto_ff::PetInfo & msg) {
	instId = msg.instid();
	cfgid = msg.cfgid();
	lv = msg.lv();
	steplv = msg.steplv();
	starlv = msg.starlv();
	activeSkillLv = msg.activeskilllv();
	exclusiveSkillLvVec.resize((int)msg.exclusiveskilllvvec_size() > (int)exclusiveSkillLvVec.max_size() ? exclusiveSkillLvVec.max_size() : msg.exclusiveskilllvvec_size());
	for(int32_t i = 0; i < (int32_t)exclusiveSkillLvVec.size(); ++i) {
		exclusiveSkillLvVec[i] = msg.exclusiveskilllvvec(i);
	}
	passiveSkillLvVec.resize((int)msg.passiveskilllvvec_size() > (int)passiveSkillLvVec.max_size() ? passiveSkillLvVec.max_size() : msg.passiveskilllvvec_size());
	for(int32_t i = 0; i < (int32_t)passiveSkillLvVec.size(); ++i) {
		passiveSkillLvVec[i] = msg.passiveskilllvvec(i);
	}
	initgrow = msg.initgrow();
	slot = msg.slot();
	lvexp = msg.lvexp();
}

PetHatchInfo_s::PetHatchInfo_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int PetHatchInfo_s::CreateInit() {
	slot = (int32_t)0;
	unlock = (int32_t)0;
	eggid = (int64_t)0;
	time = (int64_t)0;
	return 0;
}

int PetHatchInfo_s::ResumeInit() {
	return 0;
}

void PetHatchInfo_s::write_to_pbmsg(::proto_ff::PetHatchInfo & msg) const {
	msg.set_slot((int32_t)slot);
	msg.set_unlock((int32_t)unlock);
	msg.set_eggid((int64_t)eggid);
	msg.set_time((int64_t)time);
}

void PetHatchInfo_s::read_from_pbmsg(const ::proto_ff::PetHatchInfo & msg) {
	slot = msg.slot();
	unlock = msg.unlock();
	eggid = msg.eggid();
	time = msg.time();
}

ItemProtoInfo_s::ItemProtoInfo_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int ItemProtoInfo_s::CreateInit() {
	index = (int32_t)0;
	item_id = (uint64_t)0;
	item_num = (int64_t)0;
	bind = (int32_t)0;
	level = (int32_t)0;
	expireTime = (uint64_t)0;
	strong_lv = (int32_t)0;
	strong_wear_quality = (int32_t)0;
	return 0;
}

int ItemProtoInfo_s::ResumeInit() {
	return 0;
}

void ItemProtoInfo_s::write_to_pbmsg(::proto_ff::ItemProtoInfo & msg) const {
	msg.set_index((int32_t)index);
	msg.set_item_id((uint64_t)item_id);
	msg.set_item_num((int64_t)item_num);
	msg.set_bind((int32_t)bind);
	msg.set_level((int32_t)level);
	for(int32_t i = 0; i < (int32_t)base.size(); ++i) {
		::proto_ff::Attr* temp_base = msg.add_base();
		base[i].write_to_pbmsg(*temp_base);
	}
	for(int32_t i = 0; i < (int32_t)refine.size(); ++i) {
		::proto_ff::Attr* temp_refine = msg.add_refine();
		refine[i].write_to_pbmsg(*temp_refine);
	}
	for(int32_t i = 0; i < (int32_t)blue.size(); ++i) {
		::proto_ff::BlueStarAttr* temp_blue = msg.add_blue();
		blue[i].write_to_pbmsg(*temp_blue);
	}
	for(int32_t i = 0; i < (int32_t)god.size(); ++i) {
		::proto_ff::Attr* temp_god = msg.add_god();
		god[i].write_to_pbmsg(*temp_god);
	}
	for(int32_t i = 0; i < (int32_t)special.size(); ++i) {
		::proto_ff::Attr* temp_special = msg.add_special();
		special[i].write_to_pbmsg(*temp_special);
	}
	msg.set_expiretime((uint64_t)expireTime);
	msg.set_strong_lv((int32_t)strong_lv);
	msg.set_strong_wear_quality((int32_t)strong_wear_quality);
}

void ItemProtoInfo_s::read_from_pbmsg(const ::proto_ff::ItemProtoInfo & msg) {
	index = msg.index();
	item_id = msg.item_id();
	item_num = msg.item_num();
	bind = msg.bind();
	level = msg.level();
	base.resize((int)msg.base_size() > (int)base.max_size() ? base.max_size() : msg.base_size());
	for(int32_t i = 0; i < (int32_t)base.size(); ++i) {
		const ::proto_ff::Attr & temp_base = msg.base(i);
		base[i].read_from_pbmsg(temp_base);
	}
	refine.resize((int)msg.refine_size() > (int)refine.max_size() ? refine.max_size() : msg.refine_size());
	for(int32_t i = 0; i < (int32_t)refine.size(); ++i) {
		const ::proto_ff::Attr & temp_refine = msg.refine(i);
		refine[i].read_from_pbmsg(temp_refine);
	}
	blue.resize((int)msg.blue_size() > (int)blue.max_size() ? blue.max_size() : msg.blue_size());
	for(int32_t i = 0; i < (int32_t)blue.size(); ++i) {
		const ::proto_ff::BlueStarAttr & temp_blue = msg.blue(i);
		blue[i].read_from_pbmsg(temp_blue);
	}
	god.resize((int)msg.god_size() > (int)god.max_size() ? god.max_size() : msg.god_size());
	for(int32_t i = 0; i < (int32_t)god.size(); ++i) {
		const ::proto_ff::Attr & temp_god = msg.god(i);
		god[i].read_from_pbmsg(temp_god);
	}
	special.resize((int)msg.special_size() > (int)special.max_size() ? special.max_size() : msg.special_size());
	for(int32_t i = 0; i < (int32_t)special.size(); ++i) {
		const ::proto_ff::Attr & temp_special = msg.special(i);
		special[i].read_from_pbmsg(temp_special);
	}
	expireTime = msg.expiretime();
	strong_lv = msg.strong_lv();
	strong_wear_quality = msg.strong_wear_quality();
}

StoneSlotInfo_s::StoneSlotInfo_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int StoneSlotInfo_s::CreateInit() {
	stone_pos = (int32_t)0;
	stoneid = (int64_t)0;
	return 0;
}

int StoneSlotInfo_s::ResumeInit() {
	return 0;
}

void StoneSlotInfo_s::write_to_pbmsg(::proto_ff::StoneSlotInfo & msg) const {
	msg.set_stone_pos((int32_t)stone_pos);
	msg.set_stoneid((int64_t)stoneid);
}

void StoneSlotInfo_s::read_from_pbmsg(const ::proto_ff::StoneSlotInfo & msg) {
	stone_pos = msg.stone_pos();
	stoneid = msg.stoneid();
}

WashSlotInfo_s::WashSlotInfo_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int WashSlotInfo_s::CreateInit() {
	slot = (int32_t)0;
	quality = (int32_t)0;
	lock = (int32_t)0;
	id = (int32_t)0;
	value = (int32_t)0;
	return 0;
}

int WashSlotInfo_s::ResumeInit() {
	return 0;
}

void WashSlotInfo_s::write_to_pbmsg(::proto_ff::WashSlotInfo & msg) const {
	msg.set_slot((int32_t)slot);
	msg.set_quality((int32_t)quality);
	msg.set_lock((int32_t)lock);
	msg.set_id((int32_t)id);
	msg.set_value((int32_t)value);
}

void WashSlotInfo_s::read_from_pbmsg(const ::proto_ff::WashSlotInfo & msg) {
	slot = msg.slot();
	quality = msg.quality();
	lock = msg.lock();
	id = msg.id();
	value = msg.value();
}

EquipSlotInfo_s::EquipSlotInfo_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int EquipSlotInfo_s::CreateInit() {
	slot_pos = (int32_t)0;
	total_score = (int64_t)0;
	stronglv = (int32_t)0;
	stone_pay_slot_open = (int32_t)0;
	suitlv = (int32_t)0;
	return 0;
}

int EquipSlotInfo_s::ResumeInit() {
	return 0;
}

void EquipSlotInfo_s::write_to_pbmsg(::proto_ff::EquipSlotInfo & msg) const {
	msg.set_slot_pos((int32_t)slot_pos);
	msg.set_total_score((int64_t)total_score);
	msg.set_stronglv((int32_t)stronglv);
	for(int32_t i = 0; i < (int32_t)stones.size(); ++i) {
		::proto_ff::StoneSlotInfo* temp_stones = msg.add_stones();
		stones[i].write_to_pbmsg(*temp_stones);
	}
	msg.set_stone_pay_slot_open((int32_t)stone_pay_slot_open);
	for(int32_t i = 0; i < (int32_t)washs.size(); ++i) {
		::proto_ff::WashSlotInfo* temp_washs = msg.add_washs();
		washs[i].write_to_pbmsg(*temp_washs);
	}
	msg.set_suitlv((int32_t)suitlv);
}

void EquipSlotInfo_s::read_from_pbmsg(const ::proto_ff::EquipSlotInfo & msg) {
	slot_pos = msg.slot_pos();
	total_score = msg.total_score();
	stronglv = msg.stronglv();
	stones.resize((int)msg.stones_size() > (int)stones.max_size() ? stones.max_size() : msg.stones_size());
	for(int32_t i = 0; i < (int32_t)stones.size(); ++i) {
		const ::proto_ff::StoneSlotInfo & temp_stones = msg.stones(i);
		stones[i].read_from_pbmsg(temp_stones);
	}
	stone_pay_slot_open = msg.stone_pay_slot_open();
	washs.resize((int)msg.washs_size() > (int)washs.max_size() ? washs.max_size() : msg.washs_size());
	for(int32_t i = 0; i < (int32_t)washs.size(); ++i) {
		const ::proto_ff::WashSlotInfo & temp_washs = msg.washs(i);
		washs[i].read_from_pbmsg(temp_washs);
	}
	suitlv = msg.suitlv();
}

EquipInfo_s::EquipInfo_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int EquipInfo_s::CreateInit() {
	pos = (int32_t)0;
	return 0;
}

int EquipInfo_s::ResumeInit() {
	return 0;
}

void EquipInfo_s::write_to_pbmsg(::proto_ff::EquipInfo & msg) const {
	msg.set_pos((int32_t)pos);
	::proto_ff::ItemProtoInfo* temp_equip = msg.mutable_equip();
	equip.write_to_pbmsg(*temp_equip);
	::proto_ff::EquipSlotInfo* temp_slot = msg.mutable_slot();
	slot.write_to_pbmsg(*temp_slot);
}

void EquipInfo_s::read_from_pbmsg(const ::proto_ff::EquipInfo & msg) {
	pos = msg.pos();
	const ::proto_ff::ItemProtoInfo & temp_equip = msg.equip();
	equip.read_from_pbmsg(temp_equip);
	const ::proto_ff::EquipSlotInfo & temp_slot = msg.slot();
	slot.read_from_pbmsg(temp_slot);
}

EquipLvAttrInfo_s::EquipLvAttrInfo_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int EquipLvAttrInfo_s::CreateInit() {
	type = (int32_t)0;
	id = (int32_t)0;
	return 0;
}

int EquipLvAttrInfo_s::ResumeInit() {
	return 0;
}

void EquipLvAttrInfo_s::write_to_pbmsg(::proto_ff::EquipLvAttrInfo & msg) const {
	msg.set_type((int32_t)type);
	msg.set_id((int32_t)id);
}

void EquipLvAttrInfo_s::read_from_pbmsg(const ::proto_ff::EquipLvAttrInfo & msg) {
	type = msg.type();
	id = msg.id();
}

ItemSimpleProto_s::ItemSimpleProto_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int ItemSimpleProto_s::CreateInit() {
	itemid = (uint64_t)0;
	num = (int64_t)0;
	bind = (int32_t)0;
	return 0;
}

int ItemSimpleProto_s::ResumeInit() {
	return 0;
}

void ItemSimpleProto_s::write_to_pbmsg(::proto_ff::ItemSimpleProto & msg) const {
	msg.set_itemid((uint64_t)itemid);
	msg.set_num((int64_t)num);
	msg.set_bind((int32_t)bind);
}

void ItemSimpleProto_s::read_from_pbmsg(const ::proto_ff::ItemSimpleProto & msg) {
	itemid = msg.itemid();
	num = msg.num();
	bind = msg.bind();
}

MultItemSimpleProto_s::MultItemSimpleProto_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int MultItemSimpleProto_s::CreateInit() {
	return 0;
}

int MultItemSimpleProto_s::ResumeInit() {
	return 0;
}

void MultItemSimpleProto_s::write_to_pbmsg(::proto_ff::MultItemSimpleProto & msg) const {
	for(int32_t i = 0; i < (int32_t)info.size(); ++i) {
		::proto_ff::ItemSimpleProto* temp_info = msg.add_info();
		info[i].write_to_pbmsg(*temp_info);
	}
}

void MultItemSimpleProto_s::read_from_pbmsg(const ::proto_ff::MultItemSimpleProto & msg) {
	info.resize((int)msg.info_size() > (int)info.max_size() ? info.max_size() : msg.info_size());
	for(int32_t i = 0; i < (int32_t)info.size(); ++i) {
		const ::proto_ff::ItemSimpleProto & temp_info = msg.info(i);
		info[i].read_from_pbmsg(temp_info);
	}
}

MailParamProto_s::MailParamProto_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int MailParamProto_s::CreateInit() {
	cfgid = (uint64_t)0;
	return 0;
}

int MailParamProto_s::ResumeInit() {
	return 0;
}

void MailParamProto_s::write_to_pbmsg(::proto_ff::MailParamProto & msg) const {
	msg.set_cfgid((uint64_t)cfgid);
	for(int32_t i = 0; i < (int32_t)str_param.size(); ++i) {
		msg.add_str_param(str_param[i].data());
	}
	for(int32_t i = 0; i < (int32_t)int_param.size(); ++i) {
		msg.add_int_param((uint64_t)int_param[i]);
	}
}

void MailParamProto_s::read_from_pbmsg(const ::proto_ff::MailParamProto & msg) {
	cfgid = msg.cfgid();
	str_param.resize((int)msg.str_param_size() > (int)str_param.max_size() ? str_param.max_size() : msg.str_param_size());
	for(int32_t i = 0; i < (int32_t)str_param.size(); ++i) {
		str_param[i] = msg.str_param(i);
	}
	int_param.resize((int)msg.int_param_size() > (int)int_param.max_size() ? int_param.max_size() : msg.int_param_size());
	for(int32_t i = 0; i < (int32_t)int_param.size(); ++i) {
		int_param[i] = msg.int_param(i);
	}
}

MailStrProto_s::MailStrProto_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int MailStrProto_s::CreateInit() {
	return 0;
}

int MailStrProto_s::ResumeInit() {
	return 0;
}

void MailStrProto_s::write_to_pbmsg(::proto_ff::MailStrProto & msg) const {
	msg.set_str(str.data());
	::proto_ff::MailParamProto* temp_param = msg.mutable_param();
	param.write_to_pbmsg(*temp_param);
}

void MailStrProto_s::read_from_pbmsg(const ::proto_ff::MailStrProto & msg) {
	str = msg.str();
	const ::proto_ff::MailParamProto & temp_param = msg.param();
	param.read_from_pbmsg(temp_param);
}

MailAttachmentList_s::MailAttachmentList_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int MailAttachmentList_s::CreateInit() {
	return 0;
}

int MailAttachmentList_s::ResumeInit() {
	return 0;
}

void MailAttachmentList_s::write_to_pbmsg(::proto_ff::MailAttachmentList & msg) const {
	for(int32_t i = 0; i < (int32_t)itemInfo.size(); ++i) {
		::proto_ff::ItemProtoInfo* temp_iteminfo = msg.add_iteminfo();
		itemInfo[i].write_to_pbmsg(*temp_iteminfo);
	}
}

void MailAttachmentList_s::read_from_pbmsg(const ::proto_ff::MailAttachmentList & msg) {
	itemInfo.resize((int)msg.iteminfo_size() > (int)itemInfo.max_size() ? itemInfo.max_size() : msg.iteminfo_size());
	for(int32_t i = 0; i < (int32_t)itemInfo.size(); ++i) {
		const ::proto_ff::ItemProtoInfo & temp_iteminfo = msg.iteminfo(i);
		itemInfo[i].read_from_pbmsg(temp_iteminfo);
	}
}

MailHead_s::MailHead_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int MailHead_s::CreateInit() {
	mailId = (uint64_t)0;
	type = (uint32_t)0;
	sendPlayerId = (uint64_t)0;
	destPlayerId = (uint64_t)0;
	createTime = (uint64_t)0;
	status = (uint32_t)0;
	fetch = (int32_t)0;
	has_attach = (int32_t)0;
	begin_time = (uint64_t)0;
	end_time = (uint64_t)0;
	return 0;
}

int MailHead_s::ResumeInit() {
	return 0;
}

void MailHead_s::write_to_pbmsg(::proto_ff::MailHead & msg) const {
	msg.set_mailid((uint64_t)mailId);
	msg.set_type((uint32_t)type);
	msg.set_sendplayerid((uint64_t)sendPlayerId);
	msg.set_sendplayername(sendPlayerName.data());
	msg.set_destplayerid((uint64_t)destPlayerId);
	::proto_ff::MailStrProto* temp_topic = msg.mutable_topic();
	topic.write_to_pbmsg(*temp_topic);
	msg.set_createtime((uint64_t)createTime);
	msg.set_status((uint32_t)status);
	msg.set_fetch((int32_t)fetch);
	msg.set_has_attach((int32_t)has_attach);
	msg.set_begin_time((uint64_t)begin_time);
	msg.set_end_time((uint64_t)end_time);
}

void MailHead_s::read_from_pbmsg(const ::proto_ff::MailHead & msg) {
	mailId = msg.mailid();
	type = msg.type();
	sendPlayerId = msg.sendplayerid();
	sendPlayerName = msg.sendplayername();
	destPlayerId = msg.destplayerid();
	const ::proto_ff::MailStrProto & temp_topic = msg.topic();
	topic.read_from_pbmsg(temp_topic);
	createTime = msg.createtime();
	status = msg.status();
	fetch = msg.fetch();
	has_attach = msg.has_attach();
	begin_time = msg.begin_time();
	end_time = msg.end_time();
}

MailInfo_s::MailInfo_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int MailInfo_s::CreateInit() {
	gold = (uint64_t)0;
	diamond = (uint64_t)0;
	bindDiamond = (uint64_t)0;
	magiccrystal = (uint64_t)0;
	prestige = (uint64_t)0;
	source = (int32_t)0;
	sourceVal = (int64_t)0;
	return 0;
}

int MailInfo_s::ResumeInit() {
	return 0;
}

void MailInfo_s::write_to_pbmsg(::proto_ff::MailInfo & msg) const {
	::proto_ff::MailHead* temp_mailhead = msg.mutable_mailhead();
	mailHead.write_to_pbmsg(*temp_mailhead);
	::proto_ff::MailStrProto* temp_content = msg.mutable_content();
	content.write_to_pbmsg(*temp_content);
	msg.set_gold((uint64_t)gold);
	msg.set_diamond((uint64_t)diamond);
	msg.set_binddiamond((uint64_t)bindDiamond);
	msg.set_magiccrystal((uint64_t)magiccrystal);
	msg.set_prestige((uint64_t)prestige);
	::proto_ff::MailAttachmentList* temp_attachmentlist = msg.mutable_attachmentlist();
	attachmentList.write_to_pbmsg(*temp_attachmentlist);
	msg.set_source((int32_t)source);
	msg.set_sourceval((int64_t)sourceVal);
}

void MailInfo_s::read_from_pbmsg(const ::proto_ff::MailInfo & msg) {
	const ::proto_ff::MailHead & temp_mailhead = msg.mailhead();
	mailHead.read_from_pbmsg(temp_mailhead);
	const ::proto_ff::MailStrProto & temp_content = msg.content();
	content.read_from_pbmsg(temp_content);
	gold = msg.gold();
	diamond = msg.diamond();
	bindDiamond = msg.binddiamond();
	magiccrystal = msg.magiccrystal();
	prestige = msg.prestige();
	const ::proto_ff::MailAttachmentList & temp_attachmentlist = msg.attachmentlist();
	attachmentList.read_from_pbmsg(temp_attachmentlist);
	source = msg.source();
	sourceVal = msg.sourceval();
}

WebMailItemProto_s::WebMailItemProto_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int WebMailItemProto_s::CreateInit() {
	id = (uint64_t)0;
	num = (uint64_t)0;
	return 0;
}

int WebMailItemProto_s::ResumeInit() {
	return 0;
}

void WebMailItemProto_s::write_to_pbmsg(::proto_ff::WebMailItemProto & msg) const {
	msg.set_id((uint64_t)id);
	msg.set_num((uint64_t)num);
}

void WebMailItemProto_s::read_from_pbmsg(const ::proto_ff::WebMailItemProto & msg) {
	id = msg.id();
	num = msg.num();
}

WebMailDataProto_s::WebMailDataProto_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int WebMailDataProto_s::CreateInit() {
	mailId = (uint64_t)0;
	createTime = (uint64_t)0;
	fetch = (int32_t)0;
	gold = (uint64_t)0;
	diamond = (uint64_t)0;
	bindDiamond = (uint64_t)0;
	arenaScore = (uint64_t)0;
	magiccrystal = (uint64_t)0;
	prestige = (uint64_t)0;
	return 0;
}

int WebMailDataProto_s::ResumeInit() {
	return 0;
}

void WebMailDataProto_s::write_to_pbmsg(::proto_ff::WebMailDataProto & msg) const {
	msg.set_mailid((uint64_t)mailId);
	msg.set_createtime((uint64_t)createTime);
	::proto_ff::MailStrProto* temp_topic = msg.mutable_topic();
	topic.write_to_pbmsg(*temp_topic);
	msg.set_fetch((int32_t)fetch);
	::proto_ff::MailStrProto* temp_content = msg.mutable_content();
	content.write_to_pbmsg(*temp_content);
	msg.set_gold((uint64_t)gold);
	msg.set_diamond((uint64_t)diamond);
	msg.set_binddiamond((uint64_t)bindDiamond);
	msg.set_arenascore((uint64_t)arenaScore);
	msg.set_magiccrystal((uint64_t)magiccrystal);
	msg.set_prestige((uint64_t)prestige);
	for(int32_t i = 0; i < (int32_t)itemList.size(); ++i) {
		::proto_ff::WebMailItemProto* temp_itemlist = msg.add_itemlist();
		itemList[i].write_to_pbmsg(*temp_itemlist);
	}
}

void WebMailDataProto_s::read_from_pbmsg(const ::proto_ff::WebMailDataProto & msg) {
	mailId = msg.mailid();
	createTime = msg.createtime();
	const ::proto_ff::MailStrProto & temp_topic = msg.topic();
	topic.read_from_pbmsg(temp_topic);
	fetch = msg.fetch();
	const ::proto_ff::MailStrProto & temp_content = msg.content();
	content.read_from_pbmsg(temp_content);
	gold = msg.gold();
	diamond = msg.diamond();
	bindDiamond = msg.binddiamond();
	arenaScore = msg.arenascore();
	magiccrystal = msg.magiccrystal();
	prestige = msg.prestige();
	itemList.resize((int)msg.itemlist_size() > (int)itemList.max_size() ? itemList.max_size() : msg.itemlist_size());
	for(int32_t i = 0; i < (int32_t)itemList.size(); ++i) {
		const ::proto_ff::WebMailItemProto & temp_itemlist = msg.itemlist(i);
		itemList[i].read_from_pbmsg(temp_itemlist);
	}
}

UseItemArgProto_s::UseItemArgProto_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int UseItemArgProto_s::CreateInit() {
	int_param = (int64_t)0;
	return 0;
}

int UseItemArgProto_s::ResumeInit() {
	return 0;
}

void UseItemArgProto_s::write_to_pbmsg(::proto_ff::UseItemArgProto & msg) const {
	msg.set_int_param((int64_t)int_param);
	msg.set_str_param(str_param.data());
	for(int32_t i = 0; i < (int32_t)item_lst.size(); ++i) {
		msg.add_item_lst((uint64_t)item_lst[i]);
	}
}

void UseItemArgProto_s::read_from_pbmsg(const ::proto_ff::UseItemArgProto & msg) {
	int_param = msg.int_param();
	str_param = msg.str_param();
	item_lst.resize((int)msg.item_lst_size() > (int)item_lst.max_size() ? item_lst.max_size() : msg.item_lst_size());
	for(int32_t i = 0; i < (int32_t)item_lst.size(); ++i) {
		item_lst[i] = msg.item_lst(i);
	}
}

NotifyRoleFacadeCastRsp_s::NotifyRoleFacadeCastRsp_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int NotifyRoleFacadeCastRsp_s::CreateInit() {
	roleid = (uint64_t)0;
	return 0;
}

int NotifyRoleFacadeCastRsp_s::ResumeInit() {
	return 0;
}

void NotifyRoleFacadeCastRsp_s::write_to_pbmsg(::proto_ff::NotifyRoleFacadeCastRsp & msg) const {
	msg.set_roleid((uint64_t)roleid);
	::proto_ff::RoleFacadeProto* temp_facade = msg.mutable_facade();
	facade.write_to_pbmsg(*temp_facade);
}

void NotifyRoleFacadeCastRsp_s::read_from_pbmsg(const ::proto_ff::NotifyRoleFacadeCastRsp & msg) {
	roleid = msg.roleid();
	const ::proto_ff::RoleFacadeProto & temp_facade = msg.facade();
	facade.read_from_pbmsg(temp_facade);
}

FunctionUnlockInfoData_s::FunctionUnlockInfoData_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int FunctionUnlockInfoData_s::CreateInit() {
	unlockId = (uint64_t)0;
	get_reward = (bool)0;
	return 0;
}

int FunctionUnlockInfoData_s::ResumeInit() {
	return 0;
}

void FunctionUnlockInfoData_s::write_to_pbmsg(::proto_ff::FunctionUnlockInfoData & msg) const {
	msg.set_unlockid((uint64_t)unlockId);
	msg.set_get_reward((bool)get_reward);
}

void FunctionUnlockInfoData_s::read_from_pbmsg(const ::proto_ff::FunctionUnlockInfoData & msg) {
	unlockId = msg.unlockid();
	get_reward = msg.get_reward();
}

FunctionUnlockInfo_s::FunctionUnlockInfo_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int FunctionUnlockInfo_s::CreateInit() {
	return 0;
}

int FunctionUnlockInfo_s::ResumeInit() {
	return 0;
}

void FunctionUnlockInfo_s::write_to_pbmsg(::proto_ff::FunctionUnlockInfo & msg) const {
	for(int32_t i = 0; i < (int32_t)data.size(); ++i) {
		::proto_ff::FunctionUnlockInfoData* temp_data = msg.add_data();
		data[i].write_to_pbmsg(*temp_data);
	}
}

void FunctionUnlockInfo_s::read_from_pbmsg(const ::proto_ff::FunctionUnlockInfo & msg) {
	data.resize((int)msg.data_size() > (int)data.max_size() ? data.max_size() : msg.data_size());
	for(int32_t i = 0; i < (int32_t)data.size(); ++i) {
		const ::proto_ff::FunctionUnlockInfoData & temp_data = msg.data(i);
		data[i].read_from_pbmsg(temp_data);
	}
}

RolePlayerMiniInfo_s::RolePlayerMiniInfo_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int RolePlayerMiniInfo_s::CreateInit() {
	playerId = (uint64_t)0;
	zid = (uint32_t)0;
	level = (uint32_t)0;
	closeness = (uint32_t)0;
	recentType = (uint32_t)0;
	recentTime = (uint64_t)0;
	prof = (uint32_t)0;
	teamId = (uint32_t)0;
	unionId = (uint32_t)0;
	fightPower = (uint64_t)0;
	killMeTimes = (uint32_t)0;
	offlineTime = (uint64_t)0;
	online = (bool)0;
	vipLevel = (uint32_t)0;
	marry = (uint32_t)0;
	return 0;
}

int RolePlayerMiniInfo_s::ResumeInit() {
	return 0;
}

void RolePlayerMiniInfo_s::write_to_pbmsg(::proto_ff::RolePlayerMiniInfo & msg) const {
	msg.set_playerid((uint64_t)playerId);
	msg.set_playername(playerName.data());
	msg.set_zid((uint32_t)zid);
	msg.set_level((uint32_t)level);
	msg.set_closeness((uint32_t)closeness);
	msg.set_recenttype((uint32_t)recentType);
	msg.set_recenttime((uint64_t)recentTime);
	msg.set_prof((uint32_t)prof);
	msg.set_teamid((uint32_t)teamId);
	msg.set_unionid((uint32_t)unionId);
	msg.set_fightpower((uint64_t)fightPower);
	msg.set_killmetimes((uint32_t)killMeTimes);
	msg.set_offlinetime((uint64_t)offlineTime);
	msg.set_connect(connect.data());
	msg.set_online((bool)online);
	msg.set_viplevel((uint32_t)vipLevel);
	::proto_ff::RoleFacadeProto* temp_facade = msg.mutable_facade();
	facade.write_to_pbmsg(*temp_facade);
	msg.set_marry((uint32_t)marry);
}

void RolePlayerMiniInfo_s::read_from_pbmsg(const ::proto_ff::RolePlayerMiniInfo & msg) {
	playerId = msg.playerid();
	playerName = msg.playername();
	zid = msg.zid();
	level = msg.level();
	closeness = msg.closeness();
	recentType = msg.recenttype();
	recentTime = msg.recenttime();
	prof = msg.prof();
	teamId = msg.teamid();
	unionId = msg.unionid();
	fightPower = msg.fightpower();
	killMeTimes = msg.killmetimes();
	offlineTime = msg.offlinetime();
	connect = msg.connect();
	online = msg.online();
	vipLevel = msg.viplevel();
	const ::proto_ff::RoleFacadeProto & temp_facade = msg.facade();
	facade.read_from_pbmsg(temp_facade);
	marry = msg.marry();
}

FriendInfo_s::FriendInfo_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int FriendInfo_s::CreateInit() {
	id = (uint64_t)0;
	closeness = (uint32_t)0;
	todayCloseness = (uint32_t)0;
	updateTime = (uint64_t)0;
	return 0;
}

int FriendInfo_s::ResumeInit() {
	return 0;
}

void FriendInfo_s::write_to_pbmsg(::proto_ff::FriendInfo & msg) const {
	msg.set_id((uint64_t)id);
	msg.set_closeness((uint32_t)closeness);
	msg.set_todaycloseness((uint32_t)todayCloseness);
	msg.set_updatetime((uint64_t)updateTime);
}

void FriendInfo_s::read_from_pbmsg(const ::proto_ff::FriendInfo & msg) {
	id = msg.id();
	closeness = msg.closeness();
	todayCloseness = msg.todaycloseness();
	updateTime = msg.updatetime();
}

FriendApplyInfo_s::FriendApplyInfo_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int FriendApplyInfo_s::CreateInit() {
	id = (uint64_t)0;
	return 0;
}

int FriendApplyInfo_s::ResumeInit() {
	return 0;
}

void FriendApplyInfo_s::write_to_pbmsg(::proto_ff::FriendApplyInfo & msg) const {
	msg.set_id((uint64_t)id);
	msg.set_connect(connect.data());
}

void FriendApplyInfo_s::read_from_pbmsg(const ::proto_ff::FriendApplyInfo & msg) {
	id = msg.id();
	connect = msg.connect();
}

RelationHateInfo_s::RelationHateInfo_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int RelationHateInfo_s::CreateInit() {
	id = (uint64_t)0;
	killMeTimes = (uint32_t)0;
	return 0;
}

int RelationHateInfo_s::ResumeInit() {
	return 0;
}

void RelationHateInfo_s::write_to_pbmsg(::proto_ff::RelationHateInfo & msg) const {
	msg.set_id((uint64_t)id);
	msg.set_killmetimes((uint32_t)killMeTimes);
}

void RelationHateInfo_s::read_from_pbmsg(const ::proto_ff::RelationHateInfo & msg) {
	id = msg.id();
	killMeTimes = msg.killmetimes();
}

RelationGiftRecord_s::RelationGiftRecord_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int RelationGiftRecord_s::CreateInit() {
	friendId = (uint64_t)0;
	itemId = (uint64_t)0;
	isThanks = (uint32_t)0;
	return 0;
}

int RelationGiftRecord_s::ResumeInit() {
	return 0;
}

void RelationGiftRecord_s::write_to_pbmsg(::proto_ff::RelationGiftRecord & msg) const {
	msg.set_friendid((uint64_t)friendId);
	msg.set_itemid((uint64_t)itemId);
	msg.set_isthanks((uint32_t)isThanks);
}

void RelationGiftRecord_s::read_from_pbmsg(const ::proto_ff::RelationGiftRecord & msg) {
	friendId = msg.friendid();
	itemId = msg.itemid();
	isThanks = msg.isthanks();
}

RelationDBInfo_s::RelationDBInfo_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int RelationDBInfo_s::CreateInit() {
	friends_add = (uint32_t)0;
	return 0;
}

int RelationDBInfo_s::ResumeInit() {
	return 0;
}

void RelationDBInfo_s::write_to_pbmsg(::proto_ff::RelationDBInfo & msg) const {
	for(int32_t i = 0; i < (int32_t)friendList.size(); ++i) {
		::proto_ff::FriendInfo* temp_friendlist = msg.add_friendlist();
		friendList[i].write_to_pbmsg(*temp_friendlist);
	}
	for(int32_t i = 0; i < (int32_t)blackList.size(); ++i) {
		msg.add_blacklist((uint64_t)blackList[i]);
	}
	for(int32_t i = 0; i < (int32_t)hateList.size(); ++i) {
		::proto_ff::RelationHateInfo* temp_hatelist = msg.add_hatelist();
		hateList[i].write_to_pbmsg(*temp_hatelist);
	}
	for(int32_t i = 0; i < (int32_t)applyList.size(); ++i) {
		::proto_ff::FriendApplyInfo* temp_applylist = msg.add_applylist();
		applyList[i].write_to_pbmsg(*temp_applylist);
	}
	msg.set_friends_add((uint32_t)friends_add);
	for(int32_t i = 0; i < (int32_t)giftRecords.size(); ++i) {
		::proto_ff::RelationGiftRecord* temp_giftrecords = msg.add_giftrecords();
		giftRecords[i].write_to_pbmsg(*temp_giftrecords);
	}
}

void RelationDBInfo_s::read_from_pbmsg(const ::proto_ff::RelationDBInfo & msg) {
	friendList.resize((int)msg.friendlist_size() > (int)friendList.max_size() ? friendList.max_size() : msg.friendlist_size());
	for(int32_t i = 0; i < (int32_t)friendList.size(); ++i) {
		const ::proto_ff::FriendInfo & temp_friendlist = msg.friendlist(i);
		friendList[i].read_from_pbmsg(temp_friendlist);
	}
	blackList.resize((int)msg.blacklist_size() > (int)blackList.max_size() ? blackList.max_size() : msg.blacklist_size());
	for(int32_t i = 0; i < (int32_t)blackList.size(); ++i) {
		blackList[i] = msg.blacklist(i);
	}
	hateList.resize((int)msg.hatelist_size() > (int)hateList.max_size() ? hateList.max_size() : msg.hatelist_size());
	for(int32_t i = 0; i < (int32_t)hateList.size(); ++i) {
		const ::proto_ff::RelationHateInfo & temp_hatelist = msg.hatelist(i);
		hateList[i].read_from_pbmsg(temp_hatelist);
	}
	applyList.resize((int)msg.applylist_size() > (int)applyList.max_size() ? applyList.max_size() : msg.applylist_size());
	for(int32_t i = 0; i < (int32_t)applyList.size(); ++i) {
		const ::proto_ff::FriendApplyInfo & temp_applylist = msg.applylist(i);
		applyList[i].read_from_pbmsg(temp_applylist);
	}
	friends_add = msg.friends_add();
	giftRecords.resize((int)msg.giftrecords_size() > (int)giftRecords.max_size() ? giftRecords.max_size() : msg.giftrecords_size());
	for(int32_t i = 0; i < (int32_t)giftRecords.size(); ++i) {
		const ::proto_ff::RelationGiftRecord & temp_giftrecords = msg.giftrecords(i);
		giftRecords[i].read_from_pbmsg(temp_giftrecords);
	}
}

DigPerfor_s::DigPerfor_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int DigPerfor_s::CreateInit() {
	type = (uint32_t)0;
	value = (int64_t)0;
	return 0;
}

int DigPerfor_s::ResumeInit() {
	return 0;
}

void DigPerfor_s::write_to_pbmsg(::proto_ff::DigPerfor & msg) const {
	msg.set_type((uint32_t)type);
	msg.set_value((int64_t)value);
}

void DigPerfor_s::read_from_pbmsg(const ::proto_ff::DigPerfor & msg) {
	type = msg.type();
	value = msg.value();
}

BuffProto_s::BuffProto_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int BuffProto_s::CreateInit() {
	buff_index = (uint64_t)0;
	buff_id = (uint64_t)0;
	recver_cid = (uint64_t)0;
	left_msec = (int64_t)0;
	skill_id = (uint64_t)0;
	skill_lev = (int32_t)0;
	is_effect = (int32_t)0;
	return 0;
}

int BuffProto_s::ResumeInit() {
	return 0;
}

void BuffProto_s::write_to_pbmsg(::proto_ff::BuffProto & msg) const {
	msg.set_buff_index((uint64_t)buff_index);
	msg.set_buff_id((uint64_t)buff_id);
	msg.set_recver_cid((uint64_t)recver_cid);
	msg.set_left_msec((int64_t)left_msec);
	msg.set_skill_id((uint64_t)skill_id);
	msg.set_skill_lev((int32_t)skill_lev);
	msg.set_is_effect((int32_t)is_effect);
}

void BuffProto_s::read_from_pbmsg(const ::proto_ff::BuffProto & msg) {
	buff_index = msg.buff_index();
	buff_id = msg.buff_id();
	recver_cid = msg.recver_cid();
	left_msec = msg.left_msec();
	skill_id = msg.skill_id();
	skill_lev = msg.skill_lev();
	is_effect = msg.is_effect();
}

BuffListProto_s::BuffListProto_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int BuffListProto_s::CreateInit() {
	cid = (uint64_t)0;
	return 0;
}

int BuffListProto_s::ResumeInit() {
	return 0;
}

void BuffListProto_s::write_to_pbmsg(::proto_ff::BuffListProto & msg) const {
	msg.set_cid((uint64_t)cid);
	for(int32_t i = 0; i < (int32_t)info.size(); ++i) {
		::proto_ff::BuffProto* temp_info = msg.add_info();
		info[i].write_to_pbmsg(*temp_info);
	}
}

void BuffListProto_s::read_from_pbmsg(const ::proto_ff::BuffListProto & msg) {
	cid = msg.cid();
	info.resize((int)msg.info_size() > (int)info.max_size() ? info.max_size() : msg.info_size());
	for(int32_t i = 0; i < (int32_t)info.size(); ++i) {
		const ::proto_ff::BuffProto & temp_info = msg.info(i);
		info[i].read_from_pbmsg(temp_info);
	}
}

SkillPosProto_s::SkillPosProto_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int SkillPosProto_s::CreateInit() {
	skill_id = (uint64_t)0;
	pos = (uint32_t)0;
	cd = (int32_t)0;
	use = (int32_t)0;
	return 0;
}

int SkillPosProto_s::ResumeInit() {
	return 0;
}

void SkillPosProto_s::write_to_pbmsg(::proto_ff::SkillPosProto & msg) const {
	msg.set_skill_id((uint64_t)skill_id);
	msg.set_pos((uint32_t)pos);
	msg.set_cd((int32_t)cd);
	msg.set_use((int32_t)use);
}

void SkillPosProto_s::read_from_pbmsg(const ::proto_ff::SkillPosProto & msg) {
	skill_id = msg.skill_id();
	pos = msg.pos();
	cd = msg.cd();
	use = msg.use();
}

SkillGroupProto_s::SkillGroupProto_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int SkillGroupProto_s::CreateInit() {
	group = (uint32_t)0;
	return 0;
}

int SkillGroupProto_s::ResumeInit() {
	return 0;
}

void SkillGroupProto_s::write_to_pbmsg(::proto_ff::SkillGroupProto & msg) const {
	msg.set_group((uint32_t)group);
	for(int32_t i = 0; i < (int32_t)lst.size(); ++i) {
		::proto_ff::SkillPosProto* temp_lst = msg.add_lst();
		lst[i].write_to_pbmsg(*temp_lst);
	}
}

void SkillGroupProto_s::read_from_pbmsg(const ::proto_ff::SkillGroupProto & msg) {
	group = msg.group();
	lst.resize((int)msg.lst_size() > (int)lst.max_size() ? lst.max_size() : msg.lst_size());
	for(int32_t i = 0; i < (int32_t)lst.size(); ++i) {
		const ::proto_ff::SkillPosProto & temp_lst = msg.lst(i);
		lst[i].read_from_pbmsg(temp_lst);
	}
}

SkillGroupListProto_s::SkillGroupListProto_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int SkillGroupListProto_s::CreateInit() {
	cur_skill_group = (uint32_t)0;
	return 0;
}

int SkillGroupListProto_s::ResumeInit() {
	return 0;
}

void SkillGroupListProto_s::write_to_pbmsg(::proto_ff::SkillGroupListProto & msg) const {
	for(int32_t i = 0; i < (int32_t)info.size(); ++i) {
		::proto_ff::SkillGroupProto* temp_info = msg.add_info();
		info[i].write_to_pbmsg(*temp_info);
	}
	msg.set_cur_skill_group((uint32_t)cur_skill_group);
}

void SkillGroupListProto_s::read_from_pbmsg(const ::proto_ff::SkillGroupListProto & msg) {
	info.resize((int)msg.info_size() > (int)info.max_size() ? info.max_size() : msg.info_size());
	for(int32_t i = 0; i < (int32_t)info.size(); ++i) {
		const ::proto_ff::SkillGroupProto & temp_info = msg.info(i);
		info[i].read_from_pbmsg(temp_info);
	}
	cur_skill_group = msg.cur_skill_group();
}

GodEvilTaskProto_s::GodEvilTaskProto_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int GodEvilTaskProto_s::CreateInit() {
	id = (int32_t)0;
	cur = (int32_t)0;
	state = (int32_t)0;
	return 0;
}

int GodEvilTaskProto_s::ResumeInit() {
	return 0;
}

void GodEvilTaskProto_s::write_to_pbmsg(::proto_ff::GodEvilTaskProto & msg) const {
	msg.set_id((int32_t)id);
	msg.set_cur((int32_t)cur);
	msg.set_state((int32_t)state);
}

void GodEvilTaskProto_s::read_from_pbmsg(const ::proto_ff::GodEvilTaskProto & msg) {
	id = msg.id();
	cur = msg.cur();
	state = msg.state();
}

GodEvilTaskListProto_s::GodEvilTaskListProto_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int GodEvilTaskListProto_s::CreateInit() {
	return 0;
}

int GodEvilTaskListProto_s::ResumeInit() {
	return 0;
}

void GodEvilTaskListProto_s::write_to_pbmsg(::proto_ff::GodEvilTaskListProto & msg) const {
	for(int32_t i = 0; i < (int32_t)lst.size(); ++i) {
		::proto_ff::GodEvilTaskProto* temp_lst = msg.add_lst();
		lst[i].write_to_pbmsg(*temp_lst);
	}
}

void GodEvilTaskListProto_s::read_from_pbmsg(const ::proto_ff::GodEvilTaskListProto & msg) {
	lst.resize((int)msg.lst_size() > (int)lst.max_size() ? lst.max_size() : msg.lst_size());
	for(int32_t i = 0; i < (int32_t)lst.size(); ++i) {
		const ::proto_ff::GodEvilTaskProto & temp_lst = msg.lst(i);
		lst[i].read_from_pbmsg(temp_lst);
	}
}

GodEvilStageProto_s::GodEvilStageProto_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int GodEvilStageProto_s::CreateInit() {
	stage = (int32_t)0;
	finish = (int32_t)0;
	return 0;
}

int GodEvilStageProto_s::ResumeInit() {
	return 0;
}

void GodEvilStageProto_s::write_to_pbmsg(::proto_ff::GodEvilStageProto & msg) const {
	msg.set_stage((int32_t)stage);
	::proto_ff::GodEvilTaskListProto* temp_task = msg.mutable_task();
	task.write_to_pbmsg(*temp_task);
	msg.set_finish((int32_t)finish);
}

void GodEvilStageProto_s::read_from_pbmsg(const ::proto_ff::GodEvilStageProto & msg) {
	stage = msg.stage();
	const ::proto_ff::GodEvilTaskListProto & temp_task = msg.task();
	task.read_from_pbmsg(temp_task);
	finish = msg.finish();
}

GodEvilProto_s::GodEvilProto_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int GodEvilProto_s::CreateInit() {
	fetch = (int32_t)0;
	type = (int32_t)0;
	cd = (int32_t)0;
	vessel_lev = (int32_t)0;
	mirror_lev = (int32_t)0;
	extra_exp = (int64_t)0;
	return 0;
}

int GodEvilProto_s::ResumeInit() {
	return 0;
}

void GodEvilProto_s::write_to_pbmsg(::proto_ff::GodEvilProto & msg) const {
	msg.set_fetch((int32_t)fetch);
	::proto_ff::GodEvilStageProto* temp_stage = msg.mutable_stage();
	stage.write_to_pbmsg(*temp_stage);
	msg.set_type((int32_t)type);
	msg.set_cd((int32_t)cd);
	msg.set_vessel_lev((int32_t)vessel_lev);
	msg.set_mirror_lev((int32_t)mirror_lev);
	msg.set_extra_exp((int64_t)extra_exp);
}

void GodEvilProto_s::read_from_pbmsg(const ::proto_ff::GodEvilProto & msg) {
	fetch = msg.fetch();
	const ::proto_ff::GodEvilStageProto & temp_stage = msg.stage();
	stage.read_from_pbmsg(temp_stage);
	type = msg.type();
	cd = msg.cd();
	vessel_lev = msg.vessel_lev();
	mirror_lev = msg.mirror_lev();
	extra_exp = msg.extra_exp();
}

FacadeFantasyData_s::FacadeFantasyData_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int FacadeFantasyData_s::CreateInit() {
	fantasy_id = (uint64_t)0;
	fantasy_lev = (uint32_t)0;
	return 0;
}

int FacadeFantasyData_s::ResumeInit() {
	return 0;
}

void FacadeFantasyData_s::write_to_pbmsg(::proto_ff::FacadeFantasyData & msg) const {
	msg.set_fantasy_id((uint64_t)fantasy_id);
	msg.set_fantasy_lev((uint32_t)fantasy_lev);
}

void FacadeFantasyData_s::read_from_pbmsg(const ::proto_ff::FacadeFantasyData & msg) {
	fantasy_id = msg.fantasy_id();
	fantasy_lev = msg.fantasy_lev();
}

FacadeFragmentData_s::FacadeFragmentData_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int FacadeFragmentData_s::CreateInit() {
	fragment_id = (uint64_t)0;
	use_times = (uint32_t)0;
	return 0;
}

int FacadeFragmentData_s::ResumeInit() {
	return 0;
}

void FacadeFragmentData_s::write_to_pbmsg(::proto_ff::FacadeFragmentData & msg) const {
	msg.set_fragment_id((uint64_t)fragment_id);
	msg.set_use_times((uint32_t)use_times);
}

void FacadeFragmentData_s::read_from_pbmsg(const ::proto_ff::FacadeFragmentData & msg) {
	fragment_id = msg.fragment_id();
	use_times = msg.use_times();
}

FacadeSkillData_s::FacadeSkillData_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int FacadeSkillData_s::CreateInit() {
	skill_id = (uint64_t)0;
	skill_lev = (uint32_t)0;
	return 0;
}

int FacadeSkillData_s::ResumeInit() {
	return 0;
}

void FacadeSkillData_s::write_to_pbmsg(::proto_ff::FacadeSkillData & msg) const {
	msg.set_skill_id((uint64_t)skill_id);
	msg.set_skill_lev((uint32_t)skill_lev);
}

void FacadeSkillData_s::read_from_pbmsg(const ::proto_ff::FacadeSkillData & msg) {
	skill_id = msg.skill_id();
	skill_lev = msg.skill_lev();
}

MountFantasyData_s::MountFantasyData_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int MountFantasyData_s::CreateInit() {
	fantasy_id = (uint64_t)0;
	fantasy_lev = (uint32_t)0;
	fantasy_lev_exp = (uint64_t)0;
	fantasy_star = (uint32_t)0;
	return 0;
}

int MountFantasyData_s::ResumeInit() {
	return 0;
}

void MountFantasyData_s::write_to_pbmsg(::proto_ff::MountFantasyData & msg) const {
	msg.set_fantasy_id((uint64_t)fantasy_id);
	msg.set_fantasy_lev((uint32_t)fantasy_lev);
	msg.set_fantasy_lev_exp((uint64_t)fantasy_lev_exp);
	msg.set_fantasy_star((uint32_t)fantasy_star);
}

void MountFantasyData_s::read_from_pbmsg(const ::proto_ff::MountFantasyData & msg) {
	fantasy_id = msg.fantasy_id();
	fantasy_lev = msg.fantasy_lev();
	fantasy_lev_exp = msg.fantasy_lev_exp();
	fantasy_star = msg.fantasy_star();
}

MountFragmentData_s::MountFragmentData_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int MountFragmentData_s::CreateInit() {
	fragment_id = (uint64_t)0;
	use_times = (uint32_t)0;
	return 0;
}

int MountFragmentData_s::ResumeInit() {
	return 0;
}

void MountFragmentData_s::write_to_pbmsg(::proto_ff::MountFragmentData & msg) const {
	msg.set_fragment_id((uint64_t)fragment_id);
	msg.set_use_times((uint32_t)use_times);
}

void MountFragmentData_s::read_from_pbmsg(const ::proto_ff::MountFragmentData & msg) {
	fragment_id = msg.fragment_id();
	use_times = msg.use_times();
}

MountSkillData_s::MountSkillData_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int MountSkillData_s::CreateInit() {
	skill_id = (uint64_t)0;
	skill_lev = (uint32_t)0;
	return 0;
}

int MountSkillData_s::ResumeInit() {
	return 0;
}

void MountSkillData_s::write_to_pbmsg(::proto_ff::MountSkillData & msg) const {
	msg.set_skill_id((uint64_t)skill_id);
	msg.set_skill_lev((uint32_t)skill_lev);
}

void MountSkillData_s::read_from_pbmsg(const ::proto_ff::MountSkillData & msg) {
	skill_id = msg.skill_id();
	skill_lev = msg.skill_lev();
}

MountKunData_s::MountKunData_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int MountKunData_s::CreateInit() {
	kun_id = (uint64_t)0;
	kun_lev = (uint32_t)0;
	kun_lev_exp = (uint64_t)0;
	kun_star = (uint32_t)0;
	return 0;
}

int MountKunData_s::ResumeInit() {
	return 0;
}

void MountKunData_s::write_to_pbmsg(::proto_ff::MountKunData & msg) const {
	msg.set_kun_id((uint64_t)kun_id);
	msg.set_kun_lev((uint32_t)kun_lev);
	msg.set_kun_lev_exp((uint64_t)kun_lev_exp);
	msg.set_kun_star((uint32_t)kun_star);
}

void MountKunData_s::read_from_pbmsg(const ::proto_ff::MountKunData & msg) {
	kun_id = msg.kun_id();
	kun_lev = msg.kun_lev();
	kun_lev_exp = msg.kun_lev_exp();
	kun_star = msg.kun_star();
}

MountBloodData_s::MountBloodData_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int MountBloodData_s::CreateInit() {
	blood_id = (uint64_t)0;
	blood_state = (uint32_t)0;
	return 0;
}

int MountBloodData_s::ResumeInit() {
	return 0;
}

void MountBloodData_s::write_to_pbmsg(::proto_ff::MountBloodData & msg) const {
	msg.set_blood_id((uint64_t)blood_id);
	msg.set_blood_state((uint32_t)blood_state);
}

void MountBloodData_s::read_from_pbmsg(const ::proto_ff::MountBloodData & msg) {
	blood_id = msg.blood_id();
	blood_state = msg.blood_state();
}

MountBabySlotData_s::MountBabySlotData_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int MountBabySlotData_s::CreateInit() {
	slot = (uint32_t)0;
	cur_state = (uint32_t)0;
	cur_baby_eggid = (int64_t)0;
	cur_baby_create_time = (int64_t)0;
	return 0;
}

int MountBabySlotData_s::ResumeInit() {
	return 0;
}

void MountBabySlotData_s::write_to_pbmsg(::proto_ff::MountBabySlotData & msg) const {
	msg.set_slot((uint32_t)slot);
	msg.set_cur_state((uint32_t)cur_state);
	msg.set_cur_baby_eggid((int64_t)cur_baby_eggid);
	msg.set_cur_baby_create_time((int64_t)cur_baby_create_time);
}

void MountBabySlotData_s::read_from_pbmsg(const ::proto_ff::MountBabySlotData & msg) {
	slot = msg.slot();
	cur_state = msg.cur_state();
	cur_baby_eggid = msg.cur_baby_eggid();
	cur_baby_create_time = msg.cur_baby_create_time();
}

StatisticDataProto_s::StatisticDataProto_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int StatisticDataProto_s::CreateInit() {
	level = (int32_t)0;
	total_login_day = (uint32_t)0;
	total_rmb = (uint32_t)0;
	today_rmb = (uint32_t)0;
	total_activityCount = (uint32_t)0;
	return 0;
}

int StatisticDataProto_s::ResumeInit() {
	return 0;
}

void StatisticDataProto_s::write_to_pbmsg(::proto_ff::StatisticDataProto & msg) const {
	msg.set_level((int32_t)level);
	msg.set_total_login_day((uint32_t)total_login_day);
	msg.set_total_rmb((uint32_t)total_rmb);
	msg.set_today_rmb((uint32_t)today_rmb);
	msg.set_total_activitycount((uint32_t)total_activityCount);
}

void StatisticDataProto_s::read_from_pbmsg(const ::proto_ff::StatisticDataProto & msg) {
	level = msg.level();
	total_login_day = msg.total_login_day();
	total_rmb = msg.total_rmb();
	today_rmb = msg.today_rmb();
	total_activityCount = msg.total_activitycount();
}

GodRelicsTaskEntry_s::GodRelicsTaskEntry_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int GodRelicsTaskEntry_s::CreateInit() {
	task_cfg_id = (uint64_t)0;
	cur_num = (int32_t)0;
	task_state = (int32_t)0;
	return 0;
}

int GodRelicsTaskEntry_s::ResumeInit() {
	return 0;
}

void GodRelicsTaskEntry_s::write_to_pbmsg(::proto_ff::GodRelicsTaskEntry & msg) const {
	msg.set_task_cfg_id((uint64_t)task_cfg_id);
	msg.set_cur_num((int32_t)cur_num);
	msg.set_task_state((int32_t)task_state);
}

void GodRelicsTaskEntry_s::read_from_pbmsg(const ::proto_ff::GodRelicsTaskEntry & msg) {
	task_cfg_id = msg.task_cfg_id();
	cur_num = msg.cur_num();
	task_state = msg.task_state();
}

GodRelicsTaskGroupEntry_s::GodRelicsTaskGroupEntry_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int GodRelicsTaskGroupEntry_s::CreateInit() {
	group_cfg_id = (uint64_t)0;
	normal_reward_state = (int32_t)0;
	create_time = (uint64_t)0;
	return 0;
}

int GodRelicsTaskGroupEntry_s::ResumeInit() {
	return 0;
}

void GodRelicsTaskGroupEntry_s::write_to_pbmsg(::proto_ff::GodRelicsTaskGroupEntry & msg) const {
	msg.set_group_cfg_id((uint64_t)group_cfg_id);
	for(int32_t i = 0; i < (int32_t)entrys.size(); ++i) {
		::proto_ff::GodRelicsTaskEntry* temp_entrys = msg.add_entrys();
		entrys[i].write_to_pbmsg(*temp_entrys);
	}
	msg.set_normal_reward_state((int32_t)normal_reward_state);
	msg.set_create_time((uint64_t)create_time);
}

void GodRelicsTaskGroupEntry_s::read_from_pbmsg(const ::proto_ff::GodRelicsTaskGroupEntry & msg) {
	group_cfg_id = msg.group_cfg_id();
	entrys.resize((int)msg.entrys_size() > (int)entrys.max_size() ? entrys.max_size() : msg.entrys_size());
	for(int32_t i = 0; i < (int32_t)entrys.size(); ++i) {
		const ::proto_ff::GodRelicsTaskEntry & temp_entrys = msg.entrys(i);
		entrys[i].read_from_pbmsg(temp_entrys);
	}
	normal_reward_state = msg.normal_reward_state();
	create_time = msg.create_time();
}

DailyTaskEntry_s::DailyTaskEntry_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int DailyTaskEntry_s::CreateInit() {
	task_cfg_id = (uint64_t)0;
	cur_num = (int32_t)0;
	task_state = (int32_t)0;
	last_time = (uint64_t)0;
	buy_num = (int32_t)0;
	return 0;
}

int DailyTaskEntry_s::ResumeInit() {
	return 0;
}

void DailyTaskEntry_s::write_to_pbmsg(::proto_ff::DailyTaskEntry & msg) const {
	msg.set_task_cfg_id((uint64_t)task_cfg_id);
	msg.set_cur_num((int32_t)cur_num);
	msg.set_task_state((int32_t)task_state);
	msg.set_last_time((uint64_t)last_time);
	msg.set_buy_num((int32_t)buy_num);
}

void DailyTaskEntry_s::read_from_pbmsg(const ::proto_ff::DailyTaskEntry & msg) {
	task_cfg_id = msg.task_cfg_id();
	cur_num = msg.cur_num();
	task_state = msg.task_state();
	last_time = msg.last_time();
	buy_num = msg.buy_num();
}

DailyTaskLimitEntry_s::DailyTaskLimitEntry_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int DailyTaskLimitEntry_s::CreateInit() {
	task_cfg_id = (uint64_t)0;
	cur_num = (int32_t)0;
	task_state = (int32_t)0;
	last_time = (uint64_t)0;
	buy_num = (int32_t)0;
	ready_add = (bool)0;
	is_open = (bool)0;
	return 0;
}

int DailyTaskLimitEntry_s::ResumeInit() {
	return 0;
}

void DailyTaskLimitEntry_s::write_to_pbmsg(::proto_ff::DailyTaskLimitEntry & msg) const {
	msg.set_task_cfg_id((uint64_t)task_cfg_id);
	msg.set_cur_num((int32_t)cur_num);
	msg.set_task_state((int32_t)task_state);
	msg.set_last_time((uint64_t)last_time);
	msg.set_buy_num((int32_t)buy_num);
	msg.set_ready_add((bool)ready_add);
	msg.set_is_open((bool)is_open);
}

void DailyTaskLimitEntry_s::read_from_pbmsg(const ::proto_ff::DailyTaskLimitEntry & msg) {
	task_cfg_id = msg.task_cfg_id();
	cur_num = msg.cur_num();
	task_state = msg.task_state();
	last_time = msg.last_time();
	buy_num = msg.buy_num();
	ready_add = msg.ready_add();
	is_open = msg.is_open();
}

DailyTaskBackDayEntry_s::DailyTaskBackDayEntry_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int DailyTaskBackDayEntry_s::CreateInit() {
	left_num = (int32_t)0;
	external_left_num = (int32_t)0;
	last_time = (int64_t)0;
	return 0;
}

int DailyTaskBackDayEntry_s::ResumeInit() {
	return 0;
}

void DailyTaskBackDayEntry_s::write_to_pbmsg(::proto_ff::DailyTaskBackDayEntry & msg) const {
	msg.set_left_num((int32_t)left_num);
	msg.set_external_left_num((int32_t)external_left_num);
	msg.set_last_time((int64_t)last_time);
}

void DailyTaskBackDayEntry_s::read_from_pbmsg(const ::proto_ff::DailyTaskBackDayEntry & msg) {
	left_num = msg.left_num();
	external_left_num = msg.external_left_num();
	last_time = msg.last_time();
}

DailyTaskBackEntry_s::DailyTaskBackEntry_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int DailyTaskBackEntry_s::CreateInit() {
	task_cfg_id = (uint64_t)0;
	task_state = (int32_t)0;
	left_num = (int32_t)0;
	external_left_num = (int32_t)0;
	return 0;
}

int DailyTaskBackEntry_s::ResumeInit() {
	return 0;
}

void DailyTaskBackEntry_s::write_to_pbmsg(::proto_ff::DailyTaskBackEntry & msg) const {
	msg.set_task_cfg_id((uint64_t)task_cfg_id);
	msg.set_task_state((int32_t)task_state);
	for(int32_t i = 0; i < (int32_t)day_data.size(); ++i) {
		::proto_ff::DailyTaskBackDayEntry* temp_day_data = msg.add_day_data();
		day_data[i].write_to_pbmsg(*temp_day_data);
	}
	msg.set_left_num((int32_t)left_num);
	msg.set_external_left_num((int32_t)external_left_num);
}

void DailyTaskBackEntry_s::read_from_pbmsg(const ::proto_ff::DailyTaskBackEntry & msg) {
	task_cfg_id = msg.task_cfg_id();
	task_state = msg.task_state();
	day_data.resize((int)msg.day_data_size() > (int)day_data.max_size() ? day_data.max_size() : msg.day_data_size());
	for(int32_t i = 0; i < (int32_t)day_data.size(); ++i) {
		const ::proto_ff::DailyTaskBackDayEntry & temp_day_data = msg.day_data(i);
		day_data[i].read_from_pbmsg(temp_day_data);
	}
	left_num = msg.left_num();
	external_left_num = msg.external_left_num();
}

DailyTaskRewardEntry_s::DailyTaskRewardEntry_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int DailyTaskRewardEntry_s::CreateInit() {
	reward_id = (uint64_t)0;
	state = (int32_t)0;
	return 0;
}

int DailyTaskRewardEntry_s::ResumeInit() {
	return 0;
}

void DailyTaskRewardEntry_s::write_to_pbmsg(::proto_ff::DailyTaskRewardEntry & msg) const {
	msg.set_reward_id((uint64_t)reward_id);
	msg.set_state((int32_t)state);
}

void DailyTaskRewardEntry_s::read_from_pbmsg(const ::proto_ff::DailyTaskRewardEntry & msg) {
	reward_id = msg.reward_id();
	state = msg.state();
}

DailyTaskAllData_s::DailyTaskAllData_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int DailyTaskAllData_s::CreateInit() {
	daily_score = (uint32_t)0;
	daily_level = (uint32_t)0;
	create_time = (uint64_t)0;
	daily_exp = (uint64_t)0;
	return 0;
}

int DailyTaskAllData_s::ResumeInit() {
	return 0;
}

void DailyTaskAllData_s::write_to_pbmsg(::proto_ff::DailyTaskAllData & msg) const {
	for(int32_t i = 0; i < (int32_t)task_data.size(); ++i) {
		::proto_ff::DailyTaskEntry* temp_task_data = msg.add_task_data();
		task_data[i].write_to_pbmsg(*temp_task_data);
	}
	for(int32_t i = 0; i < (int32_t)task_limit_data.size(); ++i) {
		::proto_ff::DailyTaskLimitEntry* temp_task_limit_data = msg.add_task_limit_data();
		task_limit_data[i].write_to_pbmsg(*temp_task_limit_data);
	}
	for(int32_t i = 0; i < (int32_t)back_data.size(); ++i) {
		::proto_ff::DailyTaskBackEntry* temp_back_data = msg.add_back_data();
		back_data[i].write_to_pbmsg(*temp_back_data);
	}
	for(int32_t i = 0; i < (int32_t)reward_data.size(); ++i) {
		::proto_ff::DailyTaskRewardEntry* temp_reward_data = msg.add_reward_data();
		reward_data[i].write_to_pbmsg(*temp_reward_data);
	}
	msg.set_daily_score((uint32_t)daily_score);
	msg.set_daily_level((uint32_t)daily_level);
	msg.set_create_time((uint64_t)create_time);
	msg.set_daily_exp((uint64_t)daily_exp);
}

void DailyTaskAllData_s::read_from_pbmsg(const ::proto_ff::DailyTaskAllData & msg) {
	task_data.resize((int)msg.task_data_size() > (int)task_data.max_size() ? task_data.max_size() : msg.task_data_size());
	for(int32_t i = 0; i < (int32_t)task_data.size(); ++i) {
		const ::proto_ff::DailyTaskEntry & temp_task_data = msg.task_data(i);
		task_data[i].read_from_pbmsg(temp_task_data);
	}
	task_limit_data.resize((int)msg.task_limit_data_size() > (int)task_limit_data.max_size() ? task_limit_data.max_size() : msg.task_limit_data_size());
	for(int32_t i = 0; i < (int32_t)task_limit_data.size(); ++i) {
		const ::proto_ff::DailyTaskLimitEntry & temp_task_limit_data = msg.task_limit_data(i);
		task_limit_data[i].read_from_pbmsg(temp_task_limit_data);
	}
	back_data.resize((int)msg.back_data_size() > (int)back_data.max_size() ? back_data.max_size() : msg.back_data_size());
	for(int32_t i = 0; i < (int32_t)back_data.size(); ++i) {
		const ::proto_ff::DailyTaskBackEntry & temp_back_data = msg.back_data(i);
		back_data[i].read_from_pbmsg(temp_back_data);
	}
	reward_data.resize((int)msg.reward_data_size() > (int)reward_data.max_size() ? reward_data.max_size() : msg.reward_data_size());
	for(int32_t i = 0; i < (int32_t)reward_data.size(); ++i) {
		const ::proto_ff::DailyTaskRewardEntry & temp_reward_data = msg.reward_data(i);
		reward_data[i].read_from_pbmsg(temp_reward_data);
	}
	daily_score = msg.daily_score();
	daily_level = msg.daily_level();
	create_time = msg.create_time();
	daily_exp = msg.daily_exp();
}

CharacterDBRecentSubmitMission_s::CharacterDBRecentSubmitMission_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int CharacterDBRecentSubmitMission_s::CreateInit() {
	mission_type = (int32_t)0;
	mission_id = (uint64_t)0;
	return 0;
}

int CharacterDBRecentSubmitMission_s::ResumeInit() {
	return 0;
}

void CharacterDBRecentSubmitMission_s::write_to_pbmsg(::proto_ff::CharacterDBRecentSubmitMission & msg) const {
	msg.set_mission_type((int32_t)mission_type);
	msg.set_mission_id((uint64_t)mission_id);
}

void CharacterDBRecentSubmitMission_s::read_from_pbmsg(const ::proto_ff::CharacterDBRecentSubmitMission & msg) {
	mission_type = msg.mission_type();
	mission_id = msg.mission_id();
}

CharacterDBMissionItemInfo_s::CharacterDBMissionItemInfo_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int CharacterDBMissionItemInfo_s::CreateInit() {
	type = (uint32_t)0;
	id = (uint64_t)0;
	currentValue = (uint32_t)0;
	finalValue = (uint32_t)0;
	completedFlag = (bool)0;
	parma1 = (uint64_t)0;
	parma2 = (uint64_t)0;
	parma3 = (uint64_t)0;
	return 0;
}

int CharacterDBMissionItemInfo_s::ResumeInit() {
	return 0;
}

void CharacterDBMissionItemInfo_s::write_to_pbmsg(::proto_ff::CharacterDBMissionItemInfo & msg) const {
	msg.set_type((uint32_t)type);
	msg.set_id((uint64_t)id);
	msg.set_currentvalue((uint32_t)currentValue);
	msg.set_finalvalue((uint32_t)finalValue);
	msg.set_completedflag((bool)completedFlag);
	msg.set_parma1((uint64_t)parma1);
	msg.set_parma2((uint64_t)parma2);
	msg.set_parma3((uint64_t)parma3);
}

void CharacterDBMissionItemInfo_s::read_from_pbmsg(const ::proto_ff::CharacterDBMissionItemInfo & msg) {
	type = msg.type();
	id = msg.id();
	currentValue = msg.currentvalue();
	finalValue = msg.finalvalue();
	completedFlag = msg.completedflag();
	parma1 = msg.parma1();
	parma2 = msg.parma2();
	parma3 = msg.parma3();
}

CharacterDBMissionTrack_s::CharacterDBMissionTrack_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int CharacterDBMissionTrack_s::CreateInit() {
	missionId = (uint64_t)0;
	dynamicid = (uint64_t)0;
	status = (uint32_t)0;
	acceptMissionTime = (uint64_t)0;
	textid = (uint64_t)0;
	missionType = (uint32_t)0;
	return 0;
}

int CharacterDBMissionTrack_s::ResumeInit() {
	return 0;
}

void CharacterDBMissionTrack_s::write_to_pbmsg(::proto_ff::CharacterDBMissionTrack & msg) const {
	msg.set_missionid((uint64_t)missionId);
	msg.set_dynamicid((uint64_t)dynamicid);
	msg.set_status((uint32_t)status);
	msg.set_acceptmissiontime((uint64_t)acceptMissionTime);
	for(int32_t i = 0; i < (int32_t)itemInfo.size(); ++i) {
		::proto_ff::CharacterDBMissionItemInfo* temp_iteminfo = msg.add_iteminfo();
		itemInfo[i].write_to_pbmsg(*temp_iteminfo);
	}
	msg.set_textid((uint64_t)textid);
	msg.set_missiontype((uint32_t)missionType);
}

void CharacterDBMissionTrack_s::read_from_pbmsg(const ::proto_ff::CharacterDBMissionTrack & msg) {
	missionId = msg.missionid();
	dynamicid = msg.dynamicid();
	status = msg.status();
	acceptMissionTime = msg.acceptmissiontime();
	itemInfo.resize((int)msg.iteminfo_size() > (int)itemInfo.max_size() ? itemInfo.max_size() : msg.iteminfo_size());
	for(int32_t i = 0; i < (int32_t)itemInfo.size(); ++i) {
		const ::proto_ff::CharacterDBMissionItemInfo & temp_iteminfo = msg.iteminfo(i);
		itemInfo[i].read_from_pbmsg(temp_iteminfo);
	}
	textid = msg.textid();
	missionType = msg.missiontype();
}

CharacterDBDyMissionBountyParam_s::CharacterDBDyMissionBountyParam_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int CharacterDBDyMissionBountyParam_s::CreateInit() {
	ten_state = (uint32_t)0;
	twenty_state = (uint32_t)0;
	return 0;
}

int CharacterDBDyMissionBountyParam_s::ResumeInit() {
	return 0;
}

void CharacterDBDyMissionBountyParam_s::write_to_pbmsg(::proto_ff::CharacterDBDyMissionBountyParam & msg) const {
	msg.set_ten_state((uint32_t)ten_state);
	msg.set_twenty_state((uint32_t)twenty_state);
}

void CharacterDBDyMissionBountyParam_s::read_from_pbmsg(const ::proto_ff::CharacterDBDyMissionBountyParam & msg) {
	ten_state = msg.ten_state();
	twenty_state = msg.twenty_state();
}

CharacterDBDyMissionInfo_s::CharacterDBDyMissionInfo_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int CharacterDBDyMissionInfo_s::CreateInit() {
	mission_type = (int32_t)0;
	lastfresh = (uint64_t)0;
	accept_num = (int32_t)0;
	return 0;
}

int CharacterDBDyMissionInfo_s::ResumeInit() {
	return 0;
}

void CharacterDBDyMissionInfo_s::write_to_pbmsg(::proto_ff::CharacterDBDyMissionInfo & msg) const {
	msg.set_mission_type((int32_t)mission_type);
	msg.set_lastfresh((uint64_t)lastfresh);
	msg.set_accept_num((int32_t)accept_num);
	::proto_ff::CharacterDBDyMissionBountyParam* temp_bounty_param = msg.mutable_bounty_param();
	bounty_param.write_to_pbmsg(*temp_bounty_param);
}

void CharacterDBDyMissionInfo_s::read_from_pbmsg(const ::proto_ff::CharacterDBDyMissionInfo & msg) {
	mission_type = msg.mission_type();
	lastfresh = msg.lastfresh();
	accept_num = msg.accept_num();
	const ::proto_ff::CharacterDBDyMissionBountyParam & temp_bounty_param = msg.bounty_param();
	bounty_param.read_from_pbmsg(temp_bounty_param);
}

GuildPrestigeMissionDBData_s::GuildPrestigeMissionDBData_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int GuildPrestigeMissionDBData_s::CreateInit() {
	prestige_id = (int64_t)0;
	task_id = (int64_t)0;
	task_state = (int32_t)0;
	index = (int32_t)0;
	return 0;
}

int GuildPrestigeMissionDBData_s::ResumeInit() {
	return 0;
}

void GuildPrestigeMissionDBData_s::write_to_pbmsg(::proto_ff::GuildPrestigeMissionDBData & msg) const {
	msg.set_prestige_id((int64_t)prestige_id);
	msg.set_task_id((int64_t)task_id);
	msg.set_task_state((int32_t)task_state);
	msg.set_index((int32_t)index);
	::proto_ff::CharacterDBMissionTrack* temp_track = msg.mutable_track();
	track.write_to_pbmsg(*temp_track);
}

void GuildPrestigeMissionDBData_s::read_from_pbmsg(const ::proto_ff::GuildPrestigeMissionDBData & msg) {
	prestige_id = msg.prestige_id();
	task_id = msg.task_id();
	task_state = msg.task_state();
	index = msg.index();
	const ::proto_ff::CharacterDBMissionTrack & temp_track = msg.track();
	track.read_from_pbmsg(temp_track);
}

GuildPrestigeMissionDB_s::GuildPrestigeMissionDB_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int GuildPrestigeMissionDB_s::CreateInit() {
	refresh_num = (int32_t)0;
	all_refresh_num = (int32_t)0;
	accept_num = (int32_t)0;
	all_accept_num = (int32_t)0;
	last_refresh_time = (int64_t)0;
	return 0;
}

int GuildPrestigeMissionDB_s::ResumeInit() {
	return 0;
}

void GuildPrestigeMissionDB_s::write_to_pbmsg(::proto_ff::GuildPrestigeMissionDB & msg) const {
	msg.set_refresh_num((int32_t)refresh_num);
	msg.set_all_refresh_num((int32_t)all_refresh_num);
	msg.set_accept_num((int32_t)accept_num);
	msg.set_all_accept_num((int32_t)all_accept_num);
	for(int32_t i = 0; i < (int32_t)task_pool.size(); ++i) {
		::proto_ff::GuildPrestigeMissionDBData* temp_task_pool = msg.add_task_pool();
		task_pool[i].write_to_pbmsg(*temp_task_pool);
	}
	msg.set_last_refresh_time((int64_t)last_refresh_time);
}

void GuildPrestigeMissionDB_s::read_from_pbmsg(const ::proto_ff::GuildPrestigeMissionDB & msg) {
	refresh_num = msg.refresh_num();
	all_refresh_num = msg.all_refresh_num();
	accept_num = msg.accept_num();
	all_accept_num = msg.all_accept_num();
	task_pool.resize((int)msg.task_pool_size() > (int)task_pool.max_size() ? task_pool.max_size() : msg.task_pool_size());
	for(int32_t i = 0; i < (int32_t)task_pool.size(); ++i) {
		const ::proto_ff::GuildPrestigeMissionDBData & temp_task_pool = msg.task_pool(i);
		task_pool[i].read_from_pbmsg(temp_task_pool);
	}
	last_refresh_time = msg.last_refresh_time();
}

CharacterDBTaskData_s::CharacterDBTaskData_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int CharacterDBTaskData_s::CreateInit() {
	return 0;
}

int CharacterDBTaskData_s::ResumeInit() {
	return 0;
}

void CharacterDBTaskData_s::write_to_pbmsg(::proto_ff::CharacterDBTaskData & msg) const {
	for(int32_t i = 0; i < (int32_t)missionTrack.size(); ++i) {
		::proto_ff::CharacterDBMissionTrack* temp_missiontrack = msg.add_missiontrack();
		missionTrack[i].write_to_pbmsg(*temp_missiontrack);
	}
	for(int32_t i = 0; i < (int32_t)dyinfo.size(); ++i) {
		::proto_ff::CharacterDBDyMissionInfo* temp_dyinfo = msg.add_dyinfo();
		dyinfo[i].write_to_pbmsg(*temp_dyinfo);
	}
	for(int32_t i = 0; i < (int32_t)already_submit.size(); ++i) {
		msg.add_already_submit((uint64_t)already_submit[i]);
	}
	for(int32_t i = 0; i < (int32_t)recent_submit.size(); ++i) {
		::proto_ff::CharacterDBRecentSubmitMission* temp_recent_submit = msg.add_recent_submit();
		recent_submit[i].write_to_pbmsg(*temp_recent_submit);
	}
	::proto_ff::GuildPrestigeMissionDB* temp_prestige_mission = msg.mutable_prestige_mission();
	prestige_mission.write_to_pbmsg(*temp_prestige_mission);
}

void CharacterDBTaskData_s::read_from_pbmsg(const ::proto_ff::CharacterDBTaskData & msg) {
	missionTrack.resize((int)msg.missiontrack_size() > (int)missionTrack.max_size() ? missionTrack.max_size() : msg.missiontrack_size());
	for(int32_t i = 0; i < (int32_t)missionTrack.size(); ++i) {
		const ::proto_ff::CharacterDBMissionTrack & temp_missiontrack = msg.missiontrack(i);
		missionTrack[i].read_from_pbmsg(temp_missiontrack);
	}
	dyinfo.resize((int)msg.dyinfo_size() > (int)dyinfo.max_size() ? dyinfo.max_size() : msg.dyinfo_size());
	for(int32_t i = 0; i < (int32_t)dyinfo.size(); ++i) {
		const ::proto_ff::CharacterDBDyMissionInfo & temp_dyinfo = msg.dyinfo(i);
		dyinfo[i].read_from_pbmsg(temp_dyinfo);
	}
	already_submit.resize((int)msg.already_submit_size() > (int)already_submit.max_size() ? already_submit.max_size() : msg.already_submit_size());
	for(int32_t i = 0; i < (int32_t)already_submit.size(); ++i) {
		already_submit[i] = msg.already_submit(i);
	}
	recent_submit.resize((int)msg.recent_submit_size() > (int)recent_submit.max_size() ? recent_submit.max_size() : msg.recent_submit_size());
	for(int32_t i = 0; i < (int32_t)recent_submit.size(); ++i) {
		const ::proto_ff::CharacterDBRecentSubmitMission & temp_recent_submit = msg.recent_submit(i);
		recent_submit[i].read_from_pbmsg(temp_recent_submit);
	}
	const ::proto_ff::GuildPrestigeMissionDB & temp_prestige_mission = msg.prestige_mission();
	prestige_mission.read_from_pbmsg(temp_prestige_mission);
}

NotifyVipDataRsp_s::NotifyVipDataRsp_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int NotifyVipDataRsp_s::CreateInit() {
	exp = (int32_t)0;
	return 0;
}

int NotifyVipDataRsp_s::ResumeInit() {
	return 0;
}

void NotifyVipDataRsp_s::write_to_pbmsg(::proto_ff::NotifyVipDataRsp & msg) const {
	msg.set_exp((int32_t)exp);
	for(int32_t i = 0; i < (int32_t)ids.size(); ++i) {
		msg.add_ids((int32_t)ids[i]);
	}
}

void NotifyVipDataRsp_s::read_from_pbmsg(const ::proto_ff::NotifyVipDataRsp & msg) {
	exp = msg.exp();
	ids.resize((int)msg.ids_size() > (int)ids.max_size() ? ids.max_size() : msg.ids_size());
	for(int32_t i = 0; i < (int32_t)ids.size(); ++i) {
		ids[i] = msg.ids(i);
	}
}

ArenaChallResult_s::ArenaChallResult_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int ArenaChallResult_s::CreateInit() {
	result = (int32_t)0;
	chall = (bool)0;
	time = (int64_t)0;
	src_rank_id = (int32_t)0;
	dst_rank_id = (int32_t)0;
	dup_id = (int64_t)0;
	return 0;
}

int ArenaChallResult_s::ResumeInit() {
	return 0;
}

void ArenaChallResult_s::write_to_pbmsg(::proto_ff::ArenaChallResult & msg) const {
	msg.set_result((int32_t)result);
	msg.set_chall((bool)chall);
	msg.set_time((int64_t)time);
	msg.set_dst_name(dst_name.data());
	msg.set_src_rank_id((int32_t)src_rank_id);
	msg.set_dst_rank_id((int32_t)dst_rank_id);
	for(int32_t i = 0; i < (int32_t)items.size(); ++i) {
		::proto_ff::ComItem* temp_items = msg.add_items();
		items[i].write_to_pbmsg(*temp_items);
	}
	msg.set_dup_id((int64_t)dup_id);
}

void ArenaChallResult_s::read_from_pbmsg(const ::proto_ff::ArenaChallResult & msg) {
	result = msg.result();
	chall = msg.chall();
	time = msg.time();
	dst_name = msg.dst_name();
	src_rank_id = msg.src_rank_id();
	dst_rank_id = msg.dst_rank_id();
	items.resize((int)msg.items_size() > (int)items.max_size() ? items.max_size() : msg.items_size());
	for(int32_t i = 0; i < (int32_t)items.size(); ++i) {
		const ::proto_ff::ComItem & temp_items = msg.items(i);
		items[i].read_from_pbmsg(temp_items);
	}
	dup_id = msg.dup_id();
}

DailyArenaReward_s::DailyArenaReward_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int DailyArenaReward_s::CreateInit() {
	cfg_id = (int32_t)0;
	state = (int32_t)0;
	return 0;
}

int DailyArenaReward_s::ResumeInit() {
	return 0;
}

void DailyArenaReward_s::write_to_pbmsg(::proto_ff::DailyArenaReward & msg) const {
	msg.set_cfg_id((int32_t)cfg_id);
	msg.set_state((int32_t)state);
}

void DailyArenaReward_s::read_from_pbmsg(const ::proto_ff::DailyArenaReward & msg) {
	cfg_id = msg.cfg_id();
	state = msg.state();
}

ChallArenaReward_s::ChallArenaReward_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int ChallArenaReward_s::CreateInit() {
	cfg_id = (int32_t)0;
	state = (int32_t)0;
	return 0;
}

int ChallArenaReward_s::ResumeInit() {
	return 0;
}

void ChallArenaReward_s::write_to_pbmsg(::proto_ff::ChallArenaReward & msg) const {
	msg.set_cfg_id((int32_t)cfg_id);
	msg.set_state((int32_t)state);
}

void ChallArenaReward_s::read_from_pbmsg(const ::proto_ff::ChallArenaReward & msg) {
	cfg_id = msg.cfg_id();
	state = msg.state();
}

NotifyServerFlag_s::NotifyServerFlag_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int NotifyServerFlag_s::CreateInit() {
	bt_dup = (int32_t)0;
	return 0;
}

int NotifyServerFlag_s::ResumeInit() {
	return 0;
}

void NotifyServerFlag_s::write_to_pbmsg(::proto_ff::NotifyServerFlag & msg) const {
	msg.set_bt_dup((int32_t)bt_dup);
}

void NotifyServerFlag_s::read_from_pbmsg(const ::proto_ff::NotifyServerFlag & msg) {
	bt_dup = msg.bt_dup();
}

FacadeSoulSkillData_s::FacadeSoulSkillData_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int FacadeSoulSkillData_s::CreateInit() {
	skill_id = (int64_t)0;
	status = (uint32_t)0;
	return 0;
}

int FacadeSoulSkillData_s::ResumeInit() {
	return 0;
}

void FacadeSoulSkillData_s::write_to_pbmsg(::proto_ff::FacadeSoulSkillData & msg) const {
	msg.set_skill_id((int64_t)skill_id);
	msg.set_status((uint32_t)status);
}

void FacadeSoulSkillData_s::read_from_pbmsg(const ::proto_ff::FacadeSoulSkillData & msg) {
	skill_id = msg.skill_id();
	status = msg.status();
}

FacadeSoulActivityData_s::FacadeSoulActivityData_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int FacadeSoulActivityData_s::CreateInit() {
	activity_id = (int64_t)0;
	status = (uint32_t)0;
	return 0;
}

int FacadeSoulActivityData_s::ResumeInit() {
	return 0;
}

void FacadeSoulActivityData_s::write_to_pbmsg(::proto_ff::FacadeSoulActivityData & msg) const {
	msg.set_activity_id((int64_t)activity_id);
	msg.set_status((uint32_t)status);
}

void FacadeSoulActivityData_s::read_from_pbmsg(const ::proto_ff::FacadeSoulActivityData & msg) {
	activity_id = msg.activity_id();
	status = msg.status();
}

FacadeSoulData_s::FacadeSoulData_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int FacadeSoulData_s::CreateInit() {
	soul_id = (uint32_t)0;
	soul_active = (bool)0;
	soul_level = (uint32_t)0;
	return 0;
}

int FacadeSoulData_s::ResumeInit() {
	return 0;
}

void FacadeSoulData_s::write_to_pbmsg(::proto_ff::FacadeSoulData & msg) const {
	msg.set_soul_id((uint32_t)soul_id);
	msg.set_soul_active((bool)soul_active);
	msg.set_soul_level((uint32_t)soul_level);
	for(int32_t i = 0; i < (int32_t)skill_data.size(); ++i) {
		::proto_ff::FacadeSoulSkillData* temp_skill_data = msg.add_skill_data();
		skill_data[i].write_to_pbmsg(*temp_skill_data);
	}
	for(int32_t i = 0; i < (int32_t)acviity_data.size(); ++i) {
		::proto_ff::FacadeSoulActivityData* temp_acviity_data = msg.add_acviity_data();
		acviity_data[i].write_to_pbmsg(*temp_acviity_data);
	}
}

void FacadeSoulData_s::read_from_pbmsg(const ::proto_ff::FacadeSoulData & msg) {
	soul_id = msg.soul_id();
	soul_active = msg.soul_active();
	soul_level = msg.soul_level();
	skill_data.resize((int)msg.skill_data_size() > (int)skill_data.max_size() ? skill_data.max_size() : msg.skill_data_size());
	for(int32_t i = 0; i < (int32_t)skill_data.size(); ++i) {
		const ::proto_ff::FacadeSoulSkillData & temp_skill_data = msg.skill_data(i);
		skill_data[i].read_from_pbmsg(temp_skill_data);
	}
	acviity_data.resize((int)msg.acviity_data_size() > (int)acviity_data.max_size() ? acviity_data.max_size() : msg.acviity_data_size());
	for(int32_t i = 0; i < (int32_t)acviity_data.size(); ++i) {
		const ::proto_ff::FacadeSoulActivityData & temp_acviity_data = msg.acviity_data(i);
		acviity_data[i].read_from_pbmsg(temp_acviity_data);
	}
}

ItemSellProto_s::ItemSellProto_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int ItemSellProto_s::CreateInit() {
	index = (uint32_t)0;
	num = (int32_t)0;
	return 0;
}

int ItemSellProto_s::ResumeInit() {
	return 0;
}

void ItemSellProto_s::write_to_pbmsg(::proto_ff::ItemSellProto & msg) const {
	msg.set_index((uint32_t)index);
	msg.set_num((int32_t)num);
}

void ItemSellProto_s::read_from_pbmsg(const ::proto_ff::ItemSellProto & msg) {
	index = msg.index();
	num = msg.num();
}

DeityFantasySkillData_s::DeityFantasySkillData_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int DeityFantasySkillData_s::CreateInit() {
	skill_id = (uint64_t)0;
	skill_state = (uint32_t)0;
	return 0;
}

int DeityFantasySkillData_s::ResumeInit() {
	return 0;
}

void DeityFantasySkillData_s::write_to_pbmsg(::proto_ff::DeityFantasySkillData & msg) const {
	msg.set_skill_id((uint64_t)skill_id);
	msg.set_skill_state((uint32_t)skill_state);
}

void DeityFantasySkillData_s::read_from_pbmsg(const ::proto_ff::DeityFantasySkillData & msg) {
	skill_id = msg.skill_id();
	skill_state = msg.skill_state();
}

DeityEquipData_s::DeityEquipData_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int DeityEquipData_s::CreateInit() {
	return 0;
}

int DeityEquipData_s::ResumeInit() {
	return 0;
}

void DeityEquipData_s::write_to_pbmsg(::proto_ff::DeityEquipData & msg) const {
	for(int32_t i = 0; i < (int32_t)infos.size(); ++i) {
		::proto_ff::EquipInfo* temp_infos = msg.add_infos();
		infos[i].write_to_pbmsg(*temp_infos);
	}
	for(int32_t i = 0; i < (int32_t)lv_attr.size(); ++i) {
		::proto_ff::EquipLvAttrInfo* temp_lv_attr = msg.add_lv_attr();
		lv_attr[i].write_to_pbmsg(*temp_lv_attr);
	}
}

void DeityEquipData_s::read_from_pbmsg(const ::proto_ff::DeityEquipData & msg) {
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
}

DeityEquipSuitData_s::DeityEquipSuitData_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int DeityEquipSuitData_s::CreateInit() {
	id = (int64_t)0;
	state = (uint32_t)0;
	return 0;
}

int DeityEquipSuitData_s::ResumeInit() {
	return 0;
}

void DeityEquipSuitData_s::write_to_pbmsg(::proto_ff::DeityEquipSuitData & msg) const {
	msg.set_id((int64_t)id);
	msg.set_state((uint32_t)state);
}

void DeityEquipSuitData_s::read_from_pbmsg(const ::proto_ff::DeityEquipSuitData & msg) {
	id = msg.id();
	state = msg.state();
}

DeityFantasyData_s::DeityFantasyData_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int DeityFantasyData_s::CreateInit() {
	fantasy_id = (uint64_t)0;
	fantasy_lev = (uint32_t)0;
	fantasy_lev_exp = (uint64_t)0;
	fantasy_star = (uint32_t)0;
	fantasy_fight = (uint64_t)0;
	return 0;
}

int DeityFantasyData_s::ResumeInit() {
	return 0;
}

void DeityFantasyData_s::write_to_pbmsg(::proto_ff::DeityFantasyData & msg) const {
	msg.set_fantasy_id((uint64_t)fantasy_id);
	msg.set_fantasy_lev((uint32_t)fantasy_lev);
	msg.set_fantasy_lev_exp((uint64_t)fantasy_lev_exp);
	msg.set_fantasy_star((uint32_t)fantasy_star);
	for(int32_t i = 0; i < (int32_t)skill_data.size(); ++i) {
		::proto_ff::DeityFantasySkillData* temp_skill_data = msg.add_skill_data();
		skill_data[i].write_to_pbmsg(*temp_skill_data);
	}
	msg.set_fantasy_fight((uint64_t)fantasy_fight);
	::proto_ff::DeityEquipData* temp_equip_data = msg.mutable_equip_data();
	equip_data.write_to_pbmsg(*temp_equip_data);
	for(int32_t i = 0; i < (int32_t)equip_suit_data.size(); ++i) {
		::proto_ff::DeityEquipSuitData* temp_equip_suit_data = msg.add_equip_suit_data();
		equip_suit_data[i].write_to_pbmsg(*temp_equip_suit_data);
	}
}

void DeityFantasyData_s::read_from_pbmsg(const ::proto_ff::DeityFantasyData & msg) {
	fantasy_id = msg.fantasy_id();
	fantasy_lev = msg.fantasy_lev();
	fantasy_lev_exp = msg.fantasy_lev_exp();
	fantasy_star = msg.fantasy_star();
	skill_data.resize((int)msg.skill_data_size() > (int)skill_data.max_size() ? skill_data.max_size() : msg.skill_data_size());
	for(int32_t i = 0; i < (int32_t)skill_data.size(); ++i) {
		const ::proto_ff::DeityFantasySkillData & temp_skill_data = msg.skill_data(i);
		skill_data[i].read_from_pbmsg(temp_skill_data);
	}
	fantasy_fight = msg.fantasy_fight();
	const ::proto_ff::DeityEquipData & temp_equip_data = msg.equip_data();
	equip_data.read_from_pbmsg(temp_equip_data);
	equip_suit_data.resize((int)msg.equip_suit_data_size() > (int)equip_suit_data.max_size() ? equip_suit_data.max_size() : msg.equip_suit_data_size());
	for(int32_t i = 0; i < (int32_t)equip_suit_data.size(); ++i) {
		const ::proto_ff::DeityEquipSuitData & temp_equip_suit_data = msg.equip_suit_data(i);
		equip_suit_data[i].read_from_pbmsg(temp_equip_suit_data);
	}
}

DeityFragmentData_s::DeityFragmentData_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int DeityFragmentData_s::CreateInit() {
	fragment_id = (uint64_t)0;
	use_times = (uint32_t)0;
	return 0;
}

int DeityFragmentData_s::ResumeInit() {
	return 0;
}

void DeityFragmentData_s::write_to_pbmsg(::proto_ff::DeityFragmentData & msg) const {
	msg.set_fragment_id((uint64_t)fragment_id);
	msg.set_use_times((uint32_t)use_times);
}

void DeityFragmentData_s::read_from_pbmsg(const ::proto_ff::DeityFragmentData & msg) {
	fragment_id = msg.fragment_id();
	use_times = msg.use_times();
}

DeitySkillData_s::DeitySkillData_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int DeitySkillData_s::CreateInit() {
	skill_id = (uint64_t)0;
	skill_lev = (uint32_t)0;
	return 0;
}

int DeitySkillData_s::ResumeInit() {
	return 0;
}

void DeitySkillData_s::write_to_pbmsg(::proto_ff::DeitySkillData & msg) const {
	msg.set_skill_id((uint64_t)skill_id);
	msg.set_skill_lev((uint32_t)skill_lev);
}

void DeitySkillData_s::read_from_pbmsg(const ::proto_ff::DeitySkillData & msg) {
	skill_id = msg.skill_id();
	skill_lev = msg.skill_lev();
}

DeityBattleSlotData_s::DeityBattleSlotData_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int DeityBattleSlotData_s::CreateInit() {
	id = (uint32_t)0;
	cur_state = (uint32_t)0;
	deity_id = (int64_t)0;
	enter_war_time = (int64_t)0;
	return 0;
}

int DeityBattleSlotData_s::ResumeInit() {
	return 0;
}

void DeityBattleSlotData_s::write_to_pbmsg(::proto_ff::DeityBattleSlotData & msg) const {
	msg.set_id((uint32_t)id);
	msg.set_cur_state((uint32_t)cur_state);
	msg.set_deity_id((int64_t)deity_id);
	msg.set_enter_war_time((int64_t)enter_war_time);
}

void DeityBattleSlotData_s::read_from_pbmsg(const ::proto_ff::DeityBattleSlotData & msg) {
	id = msg.id();
	cur_state = msg.cur_state();
	deity_id = msg.deity_id();
	enter_war_time = msg.enter_war_time();
}

ArmorSuitState_s::ArmorSuitState_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int ArmorSuitState_s::CreateInit() {
	index = (int32_t)0;
	state = (int32_t)0;
	return 0;
}

int ArmorSuitState_s::ResumeInit() {
	return 0;
}

void ArmorSuitState_s::write_to_pbmsg(::proto_ff::ArmorSuitState & msg) const {
	msg.set_index((int32_t)index);
	msg.set_state((int32_t)state);
}

void ArmorSuitState_s::read_from_pbmsg(const ::proto_ff::ArmorSuitState & msg) {
	index = msg.index();
	state = msg.state();
}

ArmorInfo_s::ArmorInfo_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int ArmorInfo_s::CreateInit() {
	id = (int32_t)0;
	allstate = (int32_t)0;
	return 0;
}

int ArmorInfo_s::ResumeInit() {
	return 0;
}

void ArmorInfo_s::write_to_pbmsg(::proto_ff::ArmorInfo & msg) const {
	msg.set_id((int32_t)id);
	for(int32_t i = 0; i < (int32_t)suits.size(); ++i) {
		::proto_ff::ArmorSuitState* temp_suits = msg.add_suits();
		suits[i].write_to_pbmsg(*temp_suits);
	}
	msg.set_allstate((int32_t)allstate);
	for(int32_t i = 0; i < (int32_t)pos.size(); ++i) {
		msg.add_pos((int32_t)pos[i]);
	}
}

void ArmorInfo_s::read_from_pbmsg(const ::proto_ff::ArmorInfo & msg) {
	id = msg.id();
	suits.resize((int)msg.suits_size() > (int)suits.max_size() ? suits.max_size() : msg.suits_size());
	for(int32_t i = 0; i < (int32_t)suits.size(); ++i) {
		const ::proto_ff::ArmorSuitState & temp_suits = msg.suits(i);
		suits[i].read_from_pbmsg(temp_suits);
	}
	allstate = msg.allstate();
	pos.resize((int)msg.pos_size() > (int)pos.max_size() ? pos.max_size() : msg.pos_size());
	for(int32_t i = 0; i < (int32_t)pos.size(); ++i) {
		pos[i] = msg.pos(i);
	}
}

TitleInfo_s::TitleInfo_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int TitleInfo_s::CreateInit() {
	title_id = (int64_t)0;
	status = (int32_t)0;
	start_time = (int64_t)0;
	end_time = (int64_t)0;
	star = (int32_t)0;
	return 0;
}

int TitleInfo_s::ResumeInit() {
	return 0;
}

void TitleInfo_s::write_to_pbmsg(::proto_ff::TitleInfo & msg) const {
	msg.set_title_id((int64_t)title_id);
	msg.set_status((int32_t)status);
	msg.set_start_time((int64_t)start_time);
	msg.set_end_time((int64_t)end_time);
	msg.set_star((int32_t)star);
}

void TitleInfo_s::read_from_pbmsg(const ::proto_ff::TitleInfo & msg) {
	title_id = msg.title_id();
	status = msg.status();
	start_time = msg.start_time();
	end_time = msg.end_time();
	star = msg.star();
}

OccupationMissionSoulData_s::OccupationMissionSoulData_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int OccupationMissionSoulData_s::CreateInit() {
	soul_type = (int32_t)0;
	soul_pos = (int32_t)0;
	status = (int32_t)0;
	return 0;
}

int OccupationMissionSoulData_s::ResumeInit() {
	return 0;
}

void OccupationMissionSoulData_s::write_to_pbmsg(::proto_ff::OccupationMissionSoulData & msg) const {
	msg.set_soul_type((int32_t)soul_type);
	msg.set_soul_pos((int32_t)soul_pos);
	msg.set_status((int32_t)status);
}

void OccupationMissionSoulData_s::read_from_pbmsg(const ::proto_ff::OccupationMissionSoulData & msg) {
	soul_type = msg.soul_type();
	soul_pos = msg.soul_pos();
	status = msg.status();
}

OccupationMissionStageData_s::OccupationMissionStageData_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int OccupationMissionStageData_s::CreateInit() {
	stage = (int32_t)0;
	status = (int32_t)0;
	return 0;
}

int OccupationMissionStageData_s::ResumeInit() {
	return 0;
}

void OccupationMissionStageData_s::write_to_pbmsg(::proto_ff::OccupationMissionStageData & msg) const {
	msg.set_stage((int32_t)stage);
	msg.set_status((int32_t)status);
	for(int32_t i = 0; i < (int32_t)soul_data.size(); ++i) {
		::proto_ff::OccupationMissionSoulData* temp_soul_data = msg.add_soul_data();
		soul_data[i].write_to_pbmsg(*temp_soul_data);
	}
}

void OccupationMissionStageData_s::read_from_pbmsg(const ::proto_ff::OccupationMissionStageData & msg) {
	stage = msg.stage();
	status = msg.status();
	soul_data.resize((int)msg.soul_data_size() > (int)soul_data.max_size() ? soul_data.max_size() : msg.soul_data_size());
	for(int32_t i = 0; i < (int32_t)soul_data.size(); ++i) {
		const ::proto_ff::OccupationMissionSoulData & temp_soul_data = msg.soul_data(i);
		soul_data[i].read_from_pbmsg(temp_soul_data);
	}
}

OccupationMissionGradeData_s::OccupationMissionGradeData_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int OccupationMissionGradeData_s::CreateInit() {
	grade = (int32_t)0;
	status = (int32_t)0;
	return 0;
}

int OccupationMissionGradeData_s::ResumeInit() {
	return 0;
}

void OccupationMissionGradeData_s::write_to_pbmsg(::proto_ff::OccupationMissionGradeData & msg) const {
	msg.set_grade((int32_t)grade);
	msg.set_status((int32_t)status);
	for(int32_t i = 0; i < (int32_t)stage_data.size(); ++i) {
		::proto_ff::OccupationMissionStageData* temp_stage_data = msg.add_stage_data();
		stage_data[i].write_to_pbmsg(*temp_stage_data);
	}
}

void OccupationMissionGradeData_s::read_from_pbmsg(const ::proto_ff::OccupationMissionGradeData & msg) {
	grade = msg.grade();
	status = msg.status();
	stage_data.resize((int)msg.stage_data_size() > (int)stage_data.max_size() ? stage_data.max_size() : msg.stage_data_size());
	for(int32_t i = 0; i < (int32_t)stage_data.size(); ++i) {
		const ::proto_ff::OccupationMissionStageData & temp_stage_data = msg.stage_data(i);
		stage_data[i].read_from_pbmsg(temp_stage_data);
	}
}

OccupationMissionData_s::OccupationMissionData_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int OccupationMissionData_s::CreateInit() {
	return 0;
}

int OccupationMissionData_s::ResumeInit() {
	return 0;
}

void OccupationMissionData_s::write_to_pbmsg(::proto_ff::OccupationMissionData & msg) const {
	for(int32_t i = 0; i < (int32_t)grade_data.size(); ++i) {
		::proto_ff::OccupationMissionGradeData* temp_grade_data = msg.add_grade_data();
		grade_data[i].write_to_pbmsg(*temp_grade_data);
	}
}

void OccupationMissionData_s::read_from_pbmsg(const ::proto_ff::OccupationMissionData & msg) {
	grade_data.resize((int)msg.grade_data_size() > (int)grade_data.max_size() ? grade_data.max_size() : msg.grade_data_size());
	for(int32_t i = 0; i < (int32_t)grade_data.size(); ++i) {
		const ::proto_ff::OccupationMissionGradeData & temp_grade_data = msg.grade_data(i);
		grade_data[i].read_from_pbmsg(temp_grade_data);
	}
}

BestEQEquipInfo_s::BestEQEquipInfo_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int BestEQEquipInfo_s::CreateInit() {
	instId = (int32_t)0;
	cfgId = (int32_t)0;
	makeId = (int32_t)0;
	return 0;
}

int BestEQEquipInfo_s::ResumeInit() {
	return 0;
}

void BestEQEquipInfo_s::write_to_pbmsg(::proto_ff::BestEQEquipInfo & msg) const {
	msg.set_instid((int32_t)instId);
	msg.set_cfgid((int32_t)cfgId);
	msg.set_makeid((int32_t)makeId);
	for(int32_t i = 0; i < (int32_t)skills.size(); ++i) {
		::proto_ff::ComPair* temp_skills = msg.add_skills();
		skills[i].write_to_pbmsg(*temp_skills);
	}
}

void BestEQEquipInfo_s::read_from_pbmsg(const ::proto_ff::BestEQEquipInfo & msg) {
	instId = msg.instid();
	cfgId = msg.cfgid();
	makeId = msg.makeid();
	skills.resize((int)msg.skills_size() > (int)skills.max_size() ? skills.max_size() : msg.skills_size());
	for(int32_t i = 0; i < (int32_t)skills.size(); ++i) {
		const ::proto_ff::ComPair & temp_skills = msg.skills(i);
		skills[i].read_from_pbmsg(temp_skills);
	}
}

BestEQBreak_s::BestEQBreak_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int BestEQBreak_s::CreateInit() {
	lv = (int32_t)0;
	return 0;
}

int BestEQBreak_s::ResumeInit() {
	return 0;
}

void BestEQBreak_s::write_to_pbmsg(::proto_ff::BestEQBreak & msg) const {
	msg.set_lv((int32_t)lv);
	for(int32_t i = 0; i < (int32_t)exps.size(); ++i) {
		msg.add_exps((int32_t)exps[i]);
	}
	for(int32_t i = 0; i < (int32_t)genAttr.size(); ++i) {
		::proto_ff::ComPair* temp_genattr = msg.add_genattr();
		genAttr[i].write_to_pbmsg(*temp_genattr);
	}
}

void BestEQBreak_s::read_from_pbmsg(const ::proto_ff::BestEQBreak & msg) {
	lv = msg.lv();
	exps.resize((int)msg.exps_size() > (int)exps.max_size() ? exps.max_size() : msg.exps_size());
	for(int32_t i = 0; i < (int32_t)exps.size(); ++i) {
		exps[i] = msg.exps(i);
	}
	genAttr.resize((int)msg.genattr_size() > (int)genAttr.max_size() ? genAttr.max_size() : msg.genattr_size());
	for(int32_t i = 0; i < (int32_t)genAttr.size(); ++i) {
		const ::proto_ff::ComPair & temp_genattr = msg.genattr(i);
		genAttr[i].read_from_pbmsg(temp_genattr);
	}
}

BestEQSlotInfo_s::BestEQSlotInfo_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int BestEQSlotInfo_s::CreateInit() {
	slot = (int32_t)0;
	instId = (int32_t)0;
	pourId = (int32_t)0;
	pourExp = (int32_t)0;
	pourUnLock = (int32_t)0;
	awakenLv = (int32_t)0;
	return 0;
}

int BestEQSlotInfo_s::ResumeInit() {
	return 0;
}

void BestEQSlotInfo_s::write_to_pbmsg(::proto_ff::BestEQSlotInfo & msg) const {
	msg.set_slot((int32_t)slot);
	msg.set_instid((int32_t)instId);
	msg.set_pourid((int32_t)pourId);
	msg.set_pourexp((int32_t)pourExp);
	msg.set_pourunlock((int32_t)pourUnLock);
	::proto_ff::BestEQBreak* temp_breakinfo = msg.mutable_breakinfo();
	breakInfo.write_to_pbmsg(*temp_breakinfo);
	msg.set_awakenlv((int32_t)awakenLv);
}

void BestEQSlotInfo_s::read_from_pbmsg(const ::proto_ff::BestEQSlotInfo & msg) {
	slot = msg.slot();
	instId = msg.instid();
	pourId = msg.pourid();
	pourExp = msg.pourexp();
	pourUnLock = msg.pourunlock();
	const ::proto_ff::BestEQBreak & temp_breakinfo = msg.breakinfo();
	breakInfo.read_from_pbmsg(temp_breakinfo);
	awakenLv = msg.awakenlv();
}

BestEQTask_s::BestEQTask_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int BestEQTask_s::CreateInit() {
	id = (int32_t)0;
	state = (int32_t)0;
	return 0;
}

int BestEQTask_s::ResumeInit() {
	return 0;
}

void BestEQTask_s::write_to_pbmsg(::proto_ff::BestEQTask & msg) const {
	msg.set_id((int32_t)id);
	msg.set_state((int32_t)state);
}

void BestEQTask_s::read_from_pbmsg(const ::proto_ff::BestEQTask & msg) {
	id = msg.id();
	state = msg.state();
}

}
