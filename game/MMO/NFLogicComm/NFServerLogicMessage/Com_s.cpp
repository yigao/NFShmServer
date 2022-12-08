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
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct EmptyMessage_s));
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
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct ComPair_s));
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
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct ComPair64_s));
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
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct ComPairBool_s));
	key = msg.key();
	value = msg.value();
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
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Vector3PB_s));
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
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Vector2PB_s));
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
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Attr64_s));
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
	return 0;
}

int RoleFacadeProto_s::ResumeInit() {
	return 0;
}

void RoleFacadeProto_s::write_to_pbmsg(::proto_ff::RoleFacadeProto & msg) const {
	for(int32_t i = 0; i < (int32_t)growFacade.GetSize() && i < growFacade.GetMaxSize(); ++i) {
		::proto_ff::Attr64* temp_growfacade = msg.add_growfacade();
		growFacade[i].write_to_pbmsg(*temp_growfacade);
	}
	msg.set_color((int32_t)color);
}

void RoleFacadeProto_s::read_from_pbmsg(const ::proto_ff::RoleFacadeProto & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct RoleFacadeProto_s));
	growFacade.SetSize(msg.growfacade_size() > growFacade.GetMaxSize() ? growFacade.GetMaxSize() : msg.growfacade_size());
	for(int32_t i = 0; i < (int32_t)growFacade.GetSize(); ++i) {
		const ::proto_ff::Attr64 & temp_growfacade = msg.growfacade(i);
		growFacade[i].read_from_pbmsg(temp_growfacade);
	}
	color = msg.color();
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
	msg.set_name((const char*)name.Get());
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
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct RoleListDBProto_s));
	cid = msg.cid();
	name.Copy(msg.name());
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
	msg.set_name((const char*)name.Get());
	msg.set_prof((uint32_t)prof);
	msg.set_level((uint32_t)level);
	msg.set_fight((uint64_t)fight);
	msg.set_createtime((uint64_t)createtime);
	::proto_ff::RoleFacadeProto* temp_facade = msg.mutable_facade();
	facade.write_to_pbmsg(*temp_facade);
}

void LoginRoleProto_s::read_from_pbmsg(const ::proto_ff::LoginRoleProto & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct LoginRoleProto_s));
	cid = msg.cid();
	name.Copy(msg.name());
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
	guild_id = (uint32_t)0;
	guild_duty = (int32_t)0;
	guild_leader = (uint64_t)0;
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
	msg.set_guild_id((uint32_t)guild_id);
	msg.set_guild_name((const char*)guild_name.Get());
	msg.set_guild_duty((int32_t)guild_duty);
	msg.set_guild_leader((uint64_t)guild_leader);
	msg.set_team_id((uint32_t)team_id);
	msg.set_leader((uint64_t)leader);
	msg.set_mem_count((int32_t)mem_count);
	msg.set_cloness_lev((int32_t)cloness_lev);
}

void LoginSyncProto_s::read_from_pbmsg(const ::proto_ff::LoginSyncProto & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct LoginSyncProto_s));
	guild_id = msg.guild_id();
	guild_name.Copy(msg.guild_name());
	guild_duty = msg.guild_duty();
	guild_leader = msg.guild_leader();
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
	prof = (uint32_t)0;
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
	msg.set_prof((uint32_t)prof);
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
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct CenterRoleProto_s));
	cid = msg.cid();
	uid = msg.uid();
	prof = msg.prof();
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
	return 0;
}

int SocialRoleProto_s::ResumeInit() {
	return 0;
}

void SocialRoleProto_s::write_to_pbmsg(::proto_ff::SocialRoleProto & msg) const {
	msg.set_cid((uint64_t)cid);
	msg.set_uid((uint32_t)uid);
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
}

void SocialRoleProto_s::read_from_pbmsg(const ::proto_ff::SocialRoleProto & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct SocialRoleProto_s));
	cid = msg.cid();
	uid = msg.uid();
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
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Attr_s));
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
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct BlueStarAttr_s));
	id = msg.id();
	value = msg.value();
	lv_part = msg.lv_part();
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
	for(int32_t i = 0; i < (int32_t)base.GetSize() && i < base.GetMaxSize(); ++i) {
		::proto_ff::Attr* temp_base = msg.add_base();
		base[i].write_to_pbmsg(*temp_base);
	}
	for(int32_t i = 0; i < (int32_t)refine.GetSize() && i < refine.GetMaxSize(); ++i) {
		::proto_ff::Attr* temp_refine = msg.add_refine();
		refine[i].write_to_pbmsg(*temp_refine);
	}
	for(int32_t i = 0; i < (int32_t)blue.GetSize() && i < blue.GetMaxSize(); ++i) {
		::proto_ff::BlueStarAttr* temp_blue = msg.add_blue();
		blue[i].write_to_pbmsg(*temp_blue);
	}
	for(int32_t i = 0; i < (int32_t)god.GetSize() && i < god.GetMaxSize(); ++i) {
		::proto_ff::Attr* temp_god = msg.add_god();
		god[i].write_to_pbmsg(*temp_god);
	}
	for(int32_t i = 0; i < (int32_t)special.GetSize() && i < special.GetMaxSize(); ++i) {
		::proto_ff::Attr* temp_special = msg.add_special();
		special[i].write_to_pbmsg(*temp_special);
	}
	msg.set_expiretime((uint64_t)expireTime);
}

void ItemProtoInfo_s::read_from_pbmsg(const ::proto_ff::ItemProtoInfo & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct ItemProtoInfo_s));
	index = msg.index();
	item_id = msg.item_id();
	item_num = msg.item_num();
	bind = msg.bind();
	level = msg.level();
	base.SetSize(msg.base_size() > base.GetMaxSize() ? base.GetMaxSize() : msg.base_size());
	for(int32_t i = 0; i < (int32_t)base.GetSize(); ++i) {
		const ::proto_ff::Attr & temp_base = msg.base(i);
		base[i].read_from_pbmsg(temp_base);
	}
	refine.SetSize(msg.refine_size() > refine.GetMaxSize() ? refine.GetMaxSize() : msg.refine_size());
	for(int32_t i = 0; i < (int32_t)refine.GetSize(); ++i) {
		const ::proto_ff::Attr & temp_refine = msg.refine(i);
		refine[i].read_from_pbmsg(temp_refine);
	}
	blue.SetSize(msg.blue_size() > blue.GetMaxSize() ? blue.GetMaxSize() : msg.blue_size());
	for(int32_t i = 0; i < (int32_t)blue.GetSize(); ++i) {
		const ::proto_ff::BlueStarAttr & temp_blue = msg.blue(i);
		blue[i].read_from_pbmsg(temp_blue);
	}
	god.SetSize(msg.god_size() > god.GetMaxSize() ? god.GetMaxSize() : msg.god_size());
	for(int32_t i = 0; i < (int32_t)god.GetSize(); ++i) {
		const ::proto_ff::Attr & temp_god = msg.god(i);
		god[i].read_from_pbmsg(temp_god);
	}
	special.SetSize(msg.special_size() > special.GetMaxSize() ? special.GetMaxSize() : msg.special_size());
	for(int32_t i = 0; i < (int32_t)special.GetSize(); ++i) {
		const ::proto_ff::Attr & temp_special = msg.special(i);
		special[i].read_from_pbmsg(temp_special);
	}
	expireTime = msg.expiretime();
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
	return 0;
}

int EquipSlotInfo_s::ResumeInit() {
	return 0;
}

void EquipSlotInfo_s::write_to_pbmsg(::proto_ff::EquipSlotInfo & msg) const {
	msg.set_slot_pos((int32_t)slot_pos);
	msg.set_total_score((int64_t)total_score);
}

void EquipSlotInfo_s::read_from_pbmsg(const ::proto_ff::EquipSlotInfo & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct EquipSlotInfo_s));
	slot_pos = msg.slot_pos();
	total_score = msg.total_score();
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
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct EquipInfo_s));
	pos = msg.pos();
	const ::proto_ff::ItemProtoInfo & temp_equip = msg.equip();
	equip.read_from_pbmsg(temp_equip);
	const ::proto_ff::EquipSlotInfo & temp_slot = msg.slot();
	slot.read_from_pbmsg(temp_slot);
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
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct ItemSimpleProto_s));
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
	for(int32_t i = 0; i < (int32_t)info.GetSize() && i < info.GetMaxSize(); ++i) {
		::proto_ff::ItemSimpleProto* temp_info = msg.add_info();
		info[i].write_to_pbmsg(*temp_info);
	}
}

void MultItemSimpleProto_s::read_from_pbmsg(const ::proto_ff::MultItemSimpleProto & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct MultItemSimpleProto_s));
	info.SetSize(msg.info_size() > info.GetMaxSize() ? info.GetMaxSize() : msg.info_size());
	for(int32_t i = 0; i < (int32_t)info.GetSize(); ++i) {
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
	for(int32_t i = 0; i < (int32_t)str_param.GetSize() && i < str_param.GetMaxSize(); ++i) {
		msg.add_str_param(str_param[i].Get());
	}
	for(int32_t i = 0; i < (int32_t)int_param.GetSize() && i < int_param.GetMaxSize(); ++i) {
		msg.add_int_param((uint64_t)int_param[i]);
	}
}

void MailParamProto_s::read_from_pbmsg(const ::proto_ff::MailParamProto & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct MailParamProto_s));
	cfgid = msg.cfgid();
	str_param.SetSize(msg.str_param_size() > str_param.GetMaxSize() ? str_param.GetMaxSize() : msg.str_param_size());
	for(int32_t i = 0; i < (int32_t)str_param.GetSize(); ++i) {
		str_param[i].Copy(msg.str_param(i));
	}
	int_param.SetSize(msg.int_param_size() > int_param.GetMaxSize() ? int_param.GetMaxSize() : msg.int_param_size());
	for(int32_t i = 0; i < (int32_t)int_param.GetSize(); ++i) {
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
	::proto_ff::MailParamProto* temp_param = msg.mutable_param();
	param.write_to_pbmsg(*temp_param);
}

void MailStrProto_s::read_from_pbmsg(const ::proto_ff::MailStrProto & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct MailStrProto_s));
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
	for(int32_t i = 0; i < (int32_t)itemInfo.GetSize() && i < itemInfo.GetMaxSize(); ++i) {
		::proto_ff::ItemProtoInfo* temp_iteminfo = msg.add_iteminfo();
		itemInfo[i].write_to_pbmsg(*temp_iteminfo);
	}
}

void MailAttachmentList_s::read_from_pbmsg(const ::proto_ff::MailAttachmentList & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct MailAttachmentList_s));
	itemInfo.SetSize(msg.iteminfo_size() > itemInfo.GetMaxSize() ? itemInfo.GetMaxSize() : msg.iteminfo_size());
	for(int32_t i = 0; i < (int32_t)itemInfo.GetSize(); ++i) {
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
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct MailHead_s));
	mailId = msg.mailid();
	type = msg.type();
	sendPlayerId = msg.sendplayerid();
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
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct MailInfo_s));
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
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct WebMailItemProto_s));
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
	for(int32_t i = 0; i < (int32_t)itemList.GetSize() && i < itemList.GetMaxSize(); ++i) {
		::proto_ff::WebMailItemProto* temp_itemlist = msg.add_itemlist();
		itemList[i].write_to_pbmsg(*temp_itemlist);
	}
}

void WebMailDataProto_s::read_from_pbmsg(const ::proto_ff::WebMailDataProto & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct WebMailDataProto_s));
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
	itemList.SetSize(msg.itemlist_size() > itemList.GetMaxSize() ? itemList.GetMaxSize() : msg.itemlist_size());
	for(int32_t i = 0; i < (int32_t)itemList.GetSize(); ++i) {
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
	for(int32_t i = 0; i < (int32_t)item_lst.GetSize() && i < item_lst.GetMaxSize(); ++i) {
		msg.add_item_lst((uint64_t)item_lst[i]);
	}
}

void UseItemArgProto_s::read_from_pbmsg(const ::proto_ff::UseItemArgProto & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct UseItemArgProto_s));
	int_param = msg.int_param();
	item_lst.SetSize(msg.item_lst_size() > item_lst.GetMaxSize() ? item_lst.GetMaxSize() : msg.item_lst_size());
	for(int32_t i = 0; i < (int32_t)item_lst.GetSize(); ++i) {
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
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct NotifyRoleFacadeCastRsp_s));
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
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct FunctionUnlockInfoData_s));
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
	for(int32_t i = 0; i < (int32_t)data.GetSize() && i < data.GetMaxSize(); ++i) {
		::proto_ff::FunctionUnlockInfoData* temp_data = msg.add_data();
		data[i].write_to_pbmsg(*temp_data);
	}
}

void FunctionUnlockInfo_s::read_from_pbmsg(const ::proto_ff::FunctionUnlockInfo & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct FunctionUnlockInfo_s));
	data.SetSize(msg.data_size() > data.GetMaxSize() ? data.GetMaxSize() : msg.data_size());
	for(int32_t i = 0; i < (int32_t)data.GetSize(); ++i) {
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
	msg.set_playername((const char*)playerName.Get());
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
	msg.set_connect((const char*)connect.Get());
	msg.set_online((bool)online);
	msg.set_viplevel((uint32_t)vipLevel);
	::proto_ff::RoleFacadeProto* temp_facade = msg.mutable_facade();
	facade.write_to_pbmsg(*temp_facade);
	msg.set_marry((uint32_t)marry);
}

void RolePlayerMiniInfo_s::read_from_pbmsg(const ::proto_ff::RolePlayerMiniInfo & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct RolePlayerMiniInfo_s));
	playerId = msg.playerid();
	playerName.Copy(msg.playername());
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
	connect.Copy(msg.connect());
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
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct FriendInfo_s));
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
	msg.set_connect((const char*)connect.Get());
}

void FriendApplyInfo_s::read_from_pbmsg(const ::proto_ff::FriendApplyInfo & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct FriendApplyInfo_s));
	id = msg.id();
	connect.Copy(msg.connect());
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
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct RelationHateInfo_s));
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
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct RelationGiftRecord_s));
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
	for(int32_t i = 0; i < (int32_t)friendList.GetSize() && i < friendList.GetMaxSize(); ++i) {
		::proto_ff::FriendInfo* temp_friendlist = msg.add_friendlist();
		friendList[i].write_to_pbmsg(*temp_friendlist);
	}
	for(int32_t i = 0; i < (int32_t)blackList.GetSize() && i < blackList.GetMaxSize(); ++i) {
		msg.add_blacklist((uint64_t)blackList[i]);
	}
	for(int32_t i = 0; i < (int32_t)hateList.GetSize() && i < hateList.GetMaxSize(); ++i) {
		::proto_ff::RelationHateInfo* temp_hatelist = msg.add_hatelist();
		hateList[i].write_to_pbmsg(*temp_hatelist);
	}
	for(int32_t i = 0; i < (int32_t)applyList.GetSize() && i < applyList.GetMaxSize(); ++i) {
		::proto_ff::FriendApplyInfo* temp_applylist = msg.add_applylist();
		applyList[i].write_to_pbmsg(*temp_applylist);
	}
	msg.set_friends_add((uint32_t)friends_add);
	for(int32_t i = 0; i < (int32_t)giftRecords.GetSize() && i < giftRecords.GetMaxSize(); ++i) {
		::proto_ff::RelationGiftRecord* temp_giftrecords = msg.add_giftrecords();
		giftRecords[i].write_to_pbmsg(*temp_giftrecords);
	}
}

void RelationDBInfo_s::read_from_pbmsg(const ::proto_ff::RelationDBInfo & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct RelationDBInfo_s));
	friendList.SetSize(msg.friendlist_size() > friendList.GetMaxSize() ? friendList.GetMaxSize() : msg.friendlist_size());
	for(int32_t i = 0; i < (int32_t)friendList.GetSize(); ++i) {
		const ::proto_ff::FriendInfo & temp_friendlist = msg.friendlist(i);
		friendList[i].read_from_pbmsg(temp_friendlist);
	}
	blackList.SetSize(msg.blacklist_size() > blackList.GetMaxSize() ? blackList.GetMaxSize() : msg.blacklist_size());
	for(int32_t i = 0; i < (int32_t)blackList.GetSize(); ++i) {
		blackList[i] = msg.blacklist(i);
	}
	hateList.SetSize(msg.hatelist_size() > hateList.GetMaxSize() ? hateList.GetMaxSize() : msg.hatelist_size());
	for(int32_t i = 0; i < (int32_t)hateList.GetSize(); ++i) {
		const ::proto_ff::RelationHateInfo & temp_hatelist = msg.hatelist(i);
		hateList[i].read_from_pbmsg(temp_hatelist);
	}
	applyList.SetSize(msg.applylist_size() > applyList.GetMaxSize() ? applyList.GetMaxSize() : msg.applylist_size());
	for(int32_t i = 0; i < (int32_t)applyList.GetSize(); ++i) {
		const ::proto_ff::FriendApplyInfo & temp_applylist = msg.applylist(i);
		applyList[i].read_from_pbmsg(temp_applylist);
	}
	friends_add = msg.friends_add();
	giftRecords.SetSize(msg.giftrecords_size() > giftRecords.GetMaxSize() ? giftRecords.GetMaxSize() : msg.giftrecords_size());
	for(int32_t i = 0; i < (int32_t)giftRecords.GetSize(); ++i) {
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
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct DigPerfor_s));
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
	left_msec = (int32_t)0;
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
	msg.set_left_msec((int32_t)left_msec);
	msg.set_skill_id((uint64_t)skill_id);
	msg.set_skill_lev((int32_t)skill_lev);
	msg.set_is_effect((int32_t)is_effect);
}

void BuffProto_s::read_from_pbmsg(const ::proto_ff::BuffProto & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct BuffProto_s));
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
	for(int32_t i = 0; i < (int32_t)info.GetSize() && i < info.GetMaxSize(); ++i) {
		::proto_ff::BuffProto* temp_info = msg.add_info();
		info[i].write_to_pbmsg(*temp_info);
	}
}

void BuffListProto_s::read_from_pbmsg(const ::proto_ff::BuffListProto & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct BuffListProto_s));
	cid = msg.cid();
	info.SetSize(msg.info_size() > info.GetMaxSize() ? info.GetMaxSize() : msg.info_size());
	for(int32_t i = 0; i < (int32_t)info.GetSize(); ++i) {
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
	return 0;
}

int SkillPosProto_s::ResumeInit() {
	return 0;
}

void SkillPosProto_s::write_to_pbmsg(::proto_ff::SkillPosProto & msg) const {
	msg.set_skill_id((uint64_t)skill_id);
	msg.set_pos((uint32_t)pos);
	msg.set_cd((int32_t)cd);
}

void SkillPosProto_s::read_from_pbmsg(const ::proto_ff::SkillPosProto & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct SkillPosProto_s));
	skill_id = msg.skill_id();
	pos = msg.pos();
	cd = msg.cd();
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
	cd = (int32_t)0;
	return 0;
}

int SkillGroupProto_s::ResumeInit() {
	return 0;
}

void SkillGroupProto_s::write_to_pbmsg(::proto_ff::SkillGroupProto & msg) const {
	msg.set_group((uint32_t)group);
	msg.set_cd((int32_t)cd);
	for(int32_t i = 0; i < (int32_t)lst.GetSize() && i < lst.GetMaxSize(); ++i) {
		::proto_ff::SkillPosProto* temp_lst = msg.add_lst();
		lst[i].write_to_pbmsg(*temp_lst);
	}
}

void SkillGroupProto_s::read_from_pbmsg(const ::proto_ff::SkillGroupProto & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct SkillGroupProto_s));
	group = msg.group();
	cd = msg.cd();
	lst.SetSize(msg.lst_size() > lst.GetMaxSize() ? lst.GetMaxSize() : msg.lst_size());
	for(int32_t i = 0; i < (int32_t)lst.GetSize(); ++i) {
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
	return 0;
}

int SkillGroupListProto_s::ResumeInit() {
	return 0;
}

void SkillGroupListProto_s::write_to_pbmsg(::proto_ff::SkillGroupListProto & msg) const {
	for(int32_t i = 0; i < (int32_t)info.GetSize() && i < info.GetMaxSize(); ++i) {
		::proto_ff::SkillGroupProto* temp_info = msg.add_info();
		info[i].write_to_pbmsg(*temp_info);
	}
}

void SkillGroupListProto_s::read_from_pbmsg(const ::proto_ff::SkillGroupListProto & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct SkillGroupListProto_s));
	info.SetSize(msg.info_size() > info.GetMaxSize() ? info.GetMaxSize() : msg.info_size());
	for(int32_t i = 0; i < (int32_t)info.GetSize(); ++i) {
		const ::proto_ff::SkillGroupProto & temp_info = msg.info(i);
		info[i].read_from_pbmsg(temp_info);
	}
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
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct FacadeFantasyData_s));
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
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct FacadeFragmentData_s));
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
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct FacadeSkillData_s));
	skill_id = msg.skill_id();
	skill_lev = msg.skill_lev();
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
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct StatisticDataProto_s));
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
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct GodRelicsTaskEntry_s));
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
	for(int32_t i = 0; i < (int32_t)entrys.GetSize() && i < entrys.GetMaxSize(); ++i) {
		::proto_ff::GodRelicsTaskEntry* temp_entrys = msg.add_entrys();
		entrys[i].write_to_pbmsg(*temp_entrys);
	}
	msg.set_normal_reward_state((int32_t)normal_reward_state);
	msg.set_create_time((uint64_t)create_time);
}

void GodRelicsTaskGroupEntry_s::read_from_pbmsg(const ::proto_ff::GodRelicsTaskGroupEntry & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct GodRelicsTaskGroupEntry_s));
	group_cfg_id = msg.group_cfg_id();
	entrys.SetSize(msg.entrys_size() > entrys.GetMaxSize() ? entrys.GetMaxSize() : msg.entrys_size());
	for(int32_t i = 0; i < (int32_t)entrys.GetSize(); ++i) {
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
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct DailyTaskEntry_s));
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
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct DailyTaskLimitEntry_s));
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
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct DailyTaskBackDayEntry_s));
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
	for(int32_t i = 0; i < (int32_t)day_data.GetSize() && i < day_data.GetMaxSize(); ++i) {
		::proto_ff::DailyTaskBackDayEntry* temp_day_data = msg.add_day_data();
		day_data[i].write_to_pbmsg(*temp_day_data);
	}
	msg.set_left_num((int32_t)left_num);
	msg.set_external_left_num((int32_t)external_left_num);
}

void DailyTaskBackEntry_s::read_from_pbmsg(const ::proto_ff::DailyTaskBackEntry & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct DailyTaskBackEntry_s));
	task_cfg_id = msg.task_cfg_id();
	task_state = msg.task_state();
	day_data.SetSize(msg.day_data_size() > day_data.GetMaxSize() ? day_data.GetMaxSize() : msg.day_data_size());
	for(int32_t i = 0; i < (int32_t)day_data.GetSize(); ++i) {
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
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct DailyTaskRewardEntry_s));
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
	for(int32_t i = 0; i < (int32_t)task_data.GetSize() && i < task_data.GetMaxSize(); ++i) {
		::proto_ff::DailyTaskEntry* temp_task_data = msg.add_task_data();
		task_data[i].write_to_pbmsg(*temp_task_data);
	}
	for(int32_t i = 0; i < (int32_t)task_limit_data.GetSize() && i < task_limit_data.GetMaxSize(); ++i) {
		::proto_ff::DailyTaskLimitEntry* temp_task_limit_data = msg.add_task_limit_data();
		task_limit_data[i].write_to_pbmsg(*temp_task_limit_data);
	}
	for(int32_t i = 0; i < (int32_t)back_data.GetSize() && i < back_data.GetMaxSize(); ++i) {
		::proto_ff::DailyTaskBackEntry* temp_back_data = msg.add_back_data();
		back_data[i].write_to_pbmsg(*temp_back_data);
	}
	for(int32_t i = 0; i < (int32_t)reward_data.GetSize() && i < reward_data.GetMaxSize(); ++i) {
		::proto_ff::DailyTaskRewardEntry* temp_reward_data = msg.add_reward_data();
		reward_data[i].write_to_pbmsg(*temp_reward_data);
	}
	msg.set_daily_score((uint32_t)daily_score);
	msg.set_daily_level((uint32_t)daily_level);
	msg.set_create_time((uint64_t)create_time);
	msg.set_daily_exp((uint64_t)daily_exp);
}

void DailyTaskAllData_s::read_from_pbmsg(const ::proto_ff::DailyTaskAllData & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct DailyTaskAllData_s));
	task_data.SetSize(msg.task_data_size() > task_data.GetMaxSize() ? task_data.GetMaxSize() : msg.task_data_size());
	for(int32_t i = 0; i < (int32_t)task_data.GetSize(); ++i) {
		const ::proto_ff::DailyTaskEntry & temp_task_data = msg.task_data(i);
		task_data[i].read_from_pbmsg(temp_task_data);
	}
	task_limit_data.SetSize(msg.task_limit_data_size() > task_limit_data.GetMaxSize() ? task_limit_data.GetMaxSize() : msg.task_limit_data_size());
	for(int32_t i = 0; i < (int32_t)task_limit_data.GetSize(); ++i) {
		const ::proto_ff::DailyTaskLimitEntry & temp_task_limit_data = msg.task_limit_data(i);
		task_limit_data[i].read_from_pbmsg(temp_task_limit_data);
	}
	back_data.SetSize(msg.back_data_size() > back_data.GetMaxSize() ? back_data.GetMaxSize() : msg.back_data_size());
	for(int32_t i = 0; i < (int32_t)back_data.GetSize(); ++i) {
		const ::proto_ff::DailyTaskBackEntry & temp_back_data = msg.back_data(i);
		back_data[i].read_from_pbmsg(temp_back_data);
	}
	reward_data.SetSize(msg.reward_data_size() > reward_data.GetMaxSize() ? reward_data.GetMaxSize() : msg.reward_data_size());
	for(int32_t i = 0; i < (int32_t)reward_data.GetSize(); ++i) {
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
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct CharacterDBRecentSubmitMission_s));
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
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct CharacterDBMissionItemInfo_s));
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
	for(int32_t i = 0; i < (int32_t)itemInfo.GetSize() && i < itemInfo.GetMaxSize(); ++i) {
		::proto_ff::CharacterDBMissionItemInfo* temp_iteminfo = msg.add_iteminfo();
		itemInfo[i].write_to_pbmsg(*temp_iteminfo);
	}
	msg.set_textid((uint64_t)textid);
}

void CharacterDBMissionTrack_s::read_from_pbmsg(const ::proto_ff::CharacterDBMissionTrack & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct CharacterDBMissionTrack_s));
	missionId = msg.missionid();
	dynamicid = msg.dynamicid();
	status = msg.status();
	acceptMissionTime = msg.acceptmissiontime();
	itemInfo.SetSize(msg.iteminfo_size() > itemInfo.GetMaxSize() ? itemInfo.GetMaxSize() : msg.iteminfo_size());
	for(int32_t i = 0; i < (int32_t)itemInfo.GetSize(); ++i) {
		const ::proto_ff::CharacterDBMissionItemInfo & temp_iteminfo = msg.iteminfo(i);
		itemInfo[i].read_from_pbmsg(temp_iteminfo);
	}
	textid = msg.textid();
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
}

void CharacterDBDyMissionInfo_s::read_from_pbmsg(const ::proto_ff::CharacterDBDyMissionInfo & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct CharacterDBDyMissionInfo_s));
	mission_type = msg.mission_type();
	lastfresh = msg.lastfresh();
	accept_num = msg.accept_num();
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
	for(int32_t i = 0; i < (int32_t)missionTrack.GetSize() && i < missionTrack.GetMaxSize(); ++i) {
		::proto_ff::CharacterDBMissionTrack* temp_missiontrack = msg.add_missiontrack();
		missionTrack[i].write_to_pbmsg(*temp_missiontrack);
	}
	for(int32_t i = 0; i < (int32_t)dyinfo.GetSize() && i < dyinfo.GetMaxSize(); ++i) {
		::proto_ff::CharacterDBDyMissionInfo* temp_dyinfo = msg.add_dyinfo();
		dyinfo[i].write_to_pbmsg(*temp_dyinfo);
	}
	for(int32_t i = 0; i < (int32_t)already_submit.GetSize() && i < already_submit.GetMaxSize(); ++i) {
		msg.add_already_submit((uint64_t)already_submit[i]);
	}
	for(int32_t i = 0; i < (int32_t)recent_submit.GetSize() && i < recent_submit.GetMaxSize(); ++i) {
		::proto_ff::CharacterDBRecentSubmitMission* temp_recent_submit = msg.add_recent_submit();
		recent_submit[i].write_to_pbmsg(*temp_recent_submit);
	}
}

void CharacterDBTaskData_s::read_from_pbmsg(const ::proto_ff::CharacterDBTaskData & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct CharacterDBTaskData_s));
	missionTrack.SetSize(msg.missiontrack_size() > missionTrack.GetMaxSize() ? missionTrack.GetMaxSize() : msg.missiontrack_size());
	for(int32_t i = 0; i < (int32_t)missionTrack.GetSize(); ++i) {
		const ::proto_ff::CharacterDBMissionTrack & temp_missiontrack = msg.missiontrack(i);
		missionTrack[i].read_from_pbmsg(temp_missiontrack);
	}
	dyinfo.SetSize(msg.dyinfo_size() > dyinfo.GetMaxSize() ? dyinfo.GetMaxSize() : msg.dyinfo_size());
	for(int32_t i = 0; i < (int32_t)dyinfo.GetSize(); ++i) {
		const ::proto_ff::CharacterDBDyMissionInfo & temp_dyinfo = msg.dyinfo(i);
		dyinfo[i].read_from_pbmsg(temp_dyinfo);
	}
	already_submit.SetSize(msg.already_submit_size() > already_submit.GetMaxSize() ? already_submit.GetMaxSize() : msg.already_submit_size());
	for(int32_t i = 0; i < (int32_t)already_submit.GetSize(); ++i) {
		already_submit[i] = msg.already_submit(i);
	}
	recent_submit.SetSize(msg.recent_submit_size() > recent_submit.GetMaxSize() ? recent_submit.GetMaxSize() : msg.recent_submit_size());
	for(int32_t i = 0; i < (int32_t)recent_submit.GetSize(); ++i) {
		const ::proto_ff::CharacterDBRecentSubmitMission & temp_recent_submit = msg.recent_submit(i);
		recent_submit[i].read_from_pbmsg(temp_recent_submit);
	}
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
	for(int32_t i = 0; i < (int32_t)ids.GetSize() && i < ids.GetMaxSize(); ++i) {
		msg.add_ids((int32_t)ids[i]);
	}
}

void NotifyVipDataRsp_s::read_from_pbmsg(const ::proto_ff::NotifyVipDataRsp & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct NotifyVipDataRsp_s));
	exp = msg.exp();
	ids.SetSize(msg.ids_size() > ids.GetMaxSize() ? ids.GetMaxSize() : msg.ids_size());
	for(int32_t i = 0; i < (int32_t)ids.GetSize(); ++i) {
		ids[i] = msg.ids(i);
	}
}

}