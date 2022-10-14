#include "common_logic_s.h"

namespace proto_ff_s {

PacketMsg_s::PacketMsg_s() {
	CreateInit();
}

int PacketMsg_s::CreateInit() {
	cmd = (uint32_t)0;
	serverType = (uint32_t)0;
	upper_limit = (uint32_t)0;
	min_interval = (uint32_t)0;
	control_time = (uint32_t)0;
	return 0;
}

int PacketMsg_s::ResumeInit() {
	return 0;
}

void PacketMsg_s::write_to_pbmsg(::proto_ff::PacketMsg & msg) const {
	msg.set_cmd((uint32_t)cmd);
	msg.set_servertype((uint32_t)serverType);
	msg.set_upper_limit((uint32_t)upper_limit);
	msg.set_min_interval((uint32_t)min_interval);
	msg.set_control_time((uint32_t)control_time);
}

void PacketMsg_s::read_from_pbmsg(const ::proto_ff::PacketMsg & msg) {
	cmd = msg.cmd();
	serverType = msg.servertype();
	upper_limit = msg.upper_limit();
	min_interval = msg.min_interval();
	control_time = msg.control_time();
}

ServerPacketMsg_s::ServerPacketMsg_s() {
	CreateInit();
}

int ServerPacketMsg_s::CreateInit() {
	return 0;
}

int ServerPacketMsg_s::ResumeInit() {
	return 0;
}

void ServerPacketMsg_s::write_to_pbmsg(::proto_ff::ServerPacketMsg & msg) const {
	for(int32_t i = 0; i < (int32_t)PacketMsg.size(); ++i) {
		::proto_ff::PacketMsg* temp_packetmsg = msg.add_packetmsg();
		PacketMsg[i].write_to_pbmsg(*temp_packetmsg);
	}
}

void ServerPacketMsg_s::read_from_pbmsg(const ::proto_ff::ServerPacketMsg & msg) {
	PacketMsg.resize(msg.packetmsg_size());
	for(int32_t i = 0; i < (int32_t)PacketMsg.size(); ++i) {
		const ::proto_ff::PacketMsg & temp_packetmsg = msg.packetmsg(i);
		PacketMsg[i].read_from_pbmsg(temp_packetmsg);
	}
}

WorldExternalConfig_s::WorldExternalConfig_s() {
	CreateInit();
}

int WorldExternalConfig_s::CreateInit() {
	TokenTimeCheck = (bool)0;
	return 0;
}

int WorldExternalConfig_s::ResumeInit() {
	return 0;
}

void WorldExternalConfig_s::write_to_pbmsg(::proto_ff::WorldExternalConfig & msg) const {
	msg.set_tokentimecheck((bool)TokenTimeCheck);
}

void WorldExternalConfig_s::read_from_pbmsg(const ::proto_ff::WorldExternalConfig & msg) {
	TokenTimeCheck = msg.tokentimecheck();
}

CharFacadeProto_s::CharFacadeProto_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int CharFacadeProto_s::CreateInit() {
	cur_mount_id = (uint64_t)0;
	wing_id = (uint64_t)0;
	fashion_clothes_id = (uint64_t)0;
	fashion_weapon_id = (uint64_t)0;
	occupationId = (uint64_t)0;
	treasure_id = (uint64_t)0;
	treasure_type = (int32_t)0;
	artifact_id = (uint64_t)0;
	cur_select_mount_id = (uint64_t)0;
	partner_id = (uint64_t)0;
	head_id = (uint64_t)0;
	frame_id = (uint64_t)0;
	bubble_id = (uint64_t)0;
	return 0;
}

int CharFacadeProto_s::ResumeInit() {
	return 0;
}

void CharFacadeProto_s::write_to_pbmsg(::proto_ff::CharFacadeProto & msg) const {
	msg.set_cur_mount_id((uint64_t)cur_mount_id);
	msg.set_wing_id((uint64_t)wing_id);
	msg.set_fashion_clothes_id((uint64_t)fashion_clothes_id);
	msg.set_fashion_weapon_id((uint64_t)fashion_weapon_id);
	msg.set_occupationid((uint64_t)occupationId);
	msg.set_treasure_id((uint64_t)treasure_id);
	msg.set_treasure_type((int32_t)treasure_type);
	msg.set_artifact_id((uint64_t)artifact_id);
	msg.set_cur_select_mount_id((uint64_t)cur_select_mount_id);
	msg.set_partner_id((uint64_t)partner_id);
	msg.set_head_id((uint64_t)head_id);
	msg.set_frame_id((uint64_t)frame_id);
	msg.set_bubble_id((uint64_t)bubble_id);
}

void CharFacadeProto_s::read_from_pbmsg(const ::proto_ff::CharFacadeProto & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct CharFacadeProto_s));
	cur_mount_id = msg.cur_mount_id();
	wing_id = msg.wing_id();
	fashion_clothes_id = msg.fashion_clothes_id();
	fashion_weapon_id = msg.fashion_weapon_id();
	occupationId = msg.occupationid();
	treasure_id = msg.treasure_id();
	treasure_type = msg.treasure_type();
	artifact_id = msg.artifact_id();
	cur_select_mount_id = msg.cur_select_mount_id();
	partner_id = msg.partner_id();
	head_id = msg.head_id();
	frame_id = msg.frame_id();
	bubble_id = msg.bubble_id();
}

CharTrimProto_s::CharTrimProto_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int CharTrimProto_s::CreateInit() {
	trim_type = (int32_t)0;
	trim_level = (int32_t)0;
	return 0;
}

int CharTrimProto_s::ResumeInit() {
	return 0;
}

void CharTrimProto_s::write_to_pbmsg(::proto_ff::CharTrimProto & msg) const {
	msg.set_trim_type((int32_t)trim_type);
	msg.set_trim_level((int32_t)trim_level);
}

void CharTrimProto_s::read_from_pbmsg(const ::proto_ff::CharTrimProto & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct CharTrimProto_s));
	trim_type = msg.trim_type();
	trim_level = msg.trim_level();
}

ForceDupProto_s::ForceDupProto_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int ForceDupProto_s::CreateInit() {
	treasure_state = (int32_t)0;
	ladder_state = (int32_t)0;
	return 0;
}

int ForceDupProto_s::ResumeInit() {
	return 0;
}

void ForceDupProto_s::write_to_pbmsg(::proto_ff::ForceDupProto & msg) const {
	msg.set_treasure_state((int32_t)treasure_state);
	msg.set_ladder_state((int32_t)ladder_state);
}

void ForceDupProto_s::read_from_pbmsg(const ::proto_ff::ForceDupProto & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct ForceDupProto_s));
	treasure_state = msg.treasure_state();
	ladder_state = msg.ladder_state();
}

CharMultTrimProto_s::CharMultTrimProto_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int CharMultTrimProto_s::CreateInit() {
	return 0;
}

int CharMultTrimProto_s::ResumeInit() {
	return 0;
}

void CharMultTrimProto_s::write_to_pbmsg(::proto_ff::CharMultTrimProto & msg) const {
	for(int32_t i = 0; i < (int32_t)trim_lst.GetSize() && i < trim_lst.GetMaxSize(); ++i) {
		::proto_ff::CharTrimProto* temp_trim_lst = msg.add_trim_lst();
		trim_lst[i].write_to_pbmsg(*temp_trim_lst);
	}
}

void CharMultTrimProto_s::read_from_pbmsg(const ::proto_ff::CharMultTrimProto & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct CharMultTrimProto_s));
	trim_lst.SetSize(msg.trim_lst_size() > trim_lst.GetMaxSize() ? trim_lst.GetMaxSize() : msg.trim_lst_size());
	for(int32_t i = 0; i < (int32_t)trim_lst.GetSize(); ++i) {
		const ::proto_ff::CharTrimProto & temp_trim_lst = msg.trim_lst(i);
		trim_lst[i].read_from_pbmsg(temp_trim_lst);
	}
}

CharacterDBBaseInfo_s::CharacterDBBaseInfo_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int CharacterDBBaseInfo_s::CreateInit() {
	createTime = (uint64_t)0;
	lastSaveTime = (uint64_t)0;
	onlineTime = (uint64_t)0;
	loginTime = (uint64_t)0;
	logoutTime = (uint64_t)0;
	sex = (uint32_t)0;
	prof = (uint32_t)0;
	level = (uint32_t)0;
	exp = (int64_t)0;
	hp = (int64_t)0;
	fight = (int64_t)0;
	gold = (uint64_t)0;
	diamond = (uint64_t)0;
	binddiamond = (uint64_t)0;
	enter_scene_id = (uint64_t)0;
	enter_map_id = (uint64_t)0;
	enterPosX = (float)0;
	enterPosY = (float)0;
	enterPosZ = (float)0;
	lastSceneId = (uint64_t)0;
	lastMapId = (uint64_t)0;
	lastPosX = (float)0;
	lastPosY = (float)0;
	lastPosZ = (float)0;
	lastReviveTime = (uint64_t)0;
	curState = (uint32_t)0;
	clx = (float)0;
	cly = (float)0;
	clz = (float)0;
	occupation = (uint64_t)0;
	aptitude = (uint64_t)0;
	arenacoin = (int64_t)0;
	starEssence = (int64_t)0;
	starExp = (int64_t)0;
	starFragment = (int64_t)0;
	hangUpTime = (int64_t)0;
	active_num = (uint32_t)0;
	vipLevel = (int64_t)0;
	godhoodExp = (int64_t)0;
	smallSpirit = (int64_t)0;
	bigSpirit = (int64_t)0;
	finish_flag = (int32_t)0;
	useTitle = (int64_t)0;
	subpack_type = (int32_t)0;
	subpack_fetch = (int32_t)0;
	rechargeDiscountDate = (int32_t)0;
	friendNum = (int32_t)0;
	solo_score = (int32_t)0;
	solo_prv_score = (int32_t)0;
	dragons_num = (int32_t)0;
	total_login_day = (uint32_t)0;
	login_day_time = (uint64_t)0;
	login_gift = (int32_t)0;
	vipCardDiamond = (int64_t)0;
	holydia = (uint64_t)0;
	relive_num = (int32_t)0;
	last_relive_time = (int64_t)0;
	dead_static_map_id = (int64_t)0;
	dead_static_num = (int32_t)0;
	dead_static_cd = (int64_t)0;
	fushi_time = (int32_t)0;
	starStone = (int64_t)0;
	voucher = (int64_t)0;
	waiguan = (int64_t)0;
	gmpoint = (int64_t)0;
	gmpoint_limit = (int64_t)0;
	return 0;
}

int CharacterDBBaseInfo_s::ResumeInit() {
	return 0;
}

void CharacterDBBaseInfo_s::write_to_pbmsg(::proto_ff::CharacterDBBaseInfo & msg) const {
	msg.set_createtime((uint64_t)createTime);
	msg.set_lastsavetime((uint64_t)lastSaveTime);
	msg.set_onlinetime((uint64_t)onlineTime);
	msg.set_logintime((uint64_t)loginTime);
	msg.set_logouttime((uint64_t)logoutTime);
	msg.set_name((const char*)name.Get());
	msg.set_sex((uint32_t)sex);
	msg.set_prof((uint32_t)prof);
	msg.set_level((uint32_t)level);
	msg.set_exp((int64_t)exp);
	msg.set_hp((int64_t)hp);
	msg.set_fight((int64_t)fight);
	msg.set_gold((uint64_t)gold);
	msg.set_diamond((uint64_t)diamond);
	msg.set_binddiamond((uint64_t)binddiamond);
	msg.set_enter_scene_id((uint64_t)enter_scene_id);
	msg.set_enter_map_id((uint64_t)enter_map_id);
	msg.set_enterposx((float)enterPosX);
	msg.set_enterposy((float)enterPosY);
	msg.set_enterposz((float)enterPosZ);
	msg.set_lastsceneid((uint64_t)lastSceneId);
	msg.set_lastmapid((uint64_t)lastMapId);
	msg.set_lastposx((float)lastPosX);
	msg.set_lastposy((float)lastPosY);
	msg.set_lastposz((float)lastPosZ);
	msg.set_lastrevivetime((uint64_t)lastReviveTime);
	msg.set_curstate((uint32_t)curState);
	msg.set_clx((float)clx);
	msg.set_cly((float)cly);
	msg.set_clz((float)clz);
	msg.set_occupation((uint64_t)occupation);
	msg.set_aptitude((uint64_t)aptitude);
	::proto_ff::CharFacadeProto* temp_facade = msg.mutable_facade();
	facade.write_to_pbmsg(*temp_facade);
	msg.set_arenacoin((int64_t)arenacoin);
	msg.set_staressence((int64_t)starEssence);
	msg.set_starexp((int64_t)starExp);
	msg.set_starfragment((int64_t)starFragment);
	msg.set_hanguptime((int64_t)hangUpTime);
	msg.set_active_num((uint32_t)active_num);
	msg.set_viplevel((int64_t)vipLevel);
	msg.set_godhoodexp((int64_t)godhoodExp);
	msg.set_smallspirit((int64_t)smallSpirit);
	msg.set_bigspirit((int64_t)bigSpirit);
	::proto_ff::CharMultTrimProto* temp_trim = msg.mutable_trim();
	trim.write_to_pbmsg(*temp_trim);
	msg.set_finish_flag((int32_t)finish_flag);
	msg.set_guide((const char*)guide.Get());
	::proto_ff::ForceDupProto* temp_force = msg.mutable_force();
	force.write_to_pbmsg(*temp_force);
	msg.set_usetitle((int64_t)useTitle);
	msg.set_subpack_type((int32_t)subpack_type);
	msg.set_subpack_fetch((int32_t)subpack_fetch);
	msg.set_rechargediscountdate((int32_t)rechargeDiscountDate);
	msg.set_friendnum((int32_t)friendNum);
	msg.set_platid((const char*)platid.Get());
	msg.set_solo_score((int32_t)solo_score);
	msg.set_solo_prv_score((int32_t)solo_prv_score);
	msg.set_dragons_num((int32_t)dragons_num);
	msg.set_total_login_day((uint32_t)total_login_day);
	msg.set_login_day_time((uint64_t)login_day_time);
	msg.set_login_gift((int32_t)login_gift);
	msg.set_vipcarddiamond((int64_t)vipCardDiamond);
	msg.set_holydia((uint64_t)holydia);
	msg.set_relive_num((int32_t)relive_num);
	msg.set_last_relive_time((int64_t)last_relive_time);
	msg.set_dead_static_map_id((int64_t)dead_static_map_id);
	msg.set_dead_static_num((int32_t)dead_static_num);
	msg.set_dead_static_cd((int64_t)dead_static_cd);
	msg.set_fushi_time((int32_t)fushi_time);
	msg.set_starstone((int64_t)starStone);
	msg.set_voucher((int64_t)voucher);
	msg.set_waiguan((int64_t)waiguan);
	msg.set_gmpoint((int64_t)gmpoint);
	msg.set_gmpoint_limit((int64_t)gmpoint_limit);
}

void CharacterDBBaseInfo_s::read_from_pbmsg(const ::proto_ff::CharacterDBBaseInfo & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct CharacterDBBaseInfo_s));
	createTime = msg.createtime();
	lastSaveTime = msg.lastsavetime();
	onlineTime = msg.onlinetime();
	loginTime = msg.logintime();
	logoutTime = msg.logouttime();
	name.Copy(msg.name());
	sex = msg.sex();
	prof = msg.prof();
	level = msg.level();
	exp = msg.exp();
	hp = msg.hp();
	fight = msg.fight();
	gold = msg.gold();
	diamond = msg.diamond();
	binddiamond = msg.binddiamond();
	enter_scene_id = msg.enter_scene_id();
	enter_map_id = msg.enter_map_id();
	enterPosX = msg.enterposx();
	enterPosY = msg.enterposy();
	enterPosZ = msg.enterposz();
	lastSceneId = msg.lastsceneid();
	lastMapId = msg.lastmapid();
	lastPosX = msg.lastposx();
	lastPosY = msg.lastposy();
	lastPosZ = msg.lastposz();
	lastReviveTime = msg.lastrevivetime();
	curState = msg.curstate();
	clx = msg.clx();
	cly = msg.cly();
	clz = msg.clz();
	occupation = msg.occupation();
	aptitude = msg.aptitude();
	const ::proto_ff::CharFacadeProto & temp_facade = msg.facade();
	facade.read_from_pbmsg(temp_facade);
	arenacoin = msg.arenacoin();
	starEssence = msg.staressence();
	starExp = msg.starexp();
	starFragment = msg.starfragment();
	hangUpTime = msg.hanguptime();
	active_num = msg.active_num();
	vipLevel = msg.viplevel();
	godhoodExp = msg.godhoodexp();
	smallSpirit = msg.smallspirit();
	bigSpirit = msg.bigspirit();
	const ::proto_ff::CharMultTrimProto & temp_trim = msg.trim();
	trim.read_from_pbmsg(temp_trim);
	finish_flag = msg.finish_flag();
	guide.Copy(msg.guide());
	const ::proto_ff::ForceDupProto & temp_force = msg.force();
	force.read_from_pbmsg(temp_force);
	useTitle = msg.usetitle();
	subpack_type = msg.subpack_type();
	subpack_fetch = msg.subpack_fetch();
	rechargeDiscountDate = msg.rechargediscountdate();
	friendNum = msg.friendnum();
	platid.Copy(msg.platid());
	solo_score = msg.solo_score();
	solo_prv_score = msg.solo_prv_score();
	dragons_num = msg.dragons_num();
	total_login_day = msg.total_login_day();
	login_day_time = msg.login_day_time();
	login_gift = msg.login_gift();
	vipCardDiamond = msg.vipcarddiamond();
	holydia = msg.holydia();
	relive_num = msg.relive_num();
	last_relive_time = msg.last_relive_time();
	dead_static_map_id = msg.dead_static_map_id();
	dead_static_num = msg.dead_static_num();
	dead_static_cd = msg.dead_static_cd();
	fushi_time = msg.fushi_time();
	starStone = msg.starstone();
	voucher = msg.voucher();
	waiguan = msg.waiguan();
	gmpoint = msg.gmpoint();
	gmpoint_limit = msg.gmpoint_limit();
}

Attr_s::Attr_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Attr_s::CreateInit() {
	AttrNum = (uint32_t)0;
	Attrvalue = (uint32_t)0;
	return 0;
}

int Attr_s::ResumeInit() {
	return 0;
}

void Attr_s::write_to_pbmsg(::proto_ff::Attr & msg) const {
	msg.set_attrnum((uint32_t)AttrNum);
	msg.set_attrvalue((uint32_t)Attrvalue);
}

void Attr_s::read_from_pbmsg(const ::proto_ff::Attr & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Attr_s));
	AttrNum = msg.attrnum();
	Attrvalue = msg.attrvalue();
}

Attr64_s::Attr64_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Attr64_s::CreateInit() {
	AttrNum = (uint32_t)0;
	Attrvalue = (int64_t)0;
	return 0;
}

int Attr64_s::ResumeInit() {
	return 0;
}

void Attr64_s::write_to_pbmsg(::proto_ff::Attr64 & msg) const {
	msg.set_attrnum((uint32_t)AttrNum);
	msg.set_attrvalue((int64_t)Attrvalue);
}

void Attr64_s::read_from_pbmsg(const ::proto_ff::Attr64 & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Attr64_s));
	AttrNum = msg.attrnum();
	Attrvalue = msg.attrvalue();
}

FieldItemAttrInfo_s::FieldItemAttrInfo_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int FieldItemAttrInfo_s::CreateInit() {
	refine_level = (int32_t)0;
	return 0;
}

int FieldItemAttrInfo_s::ResumeInit() {
	return 0;
}

void FieldItemAttrInfo_s::write_to_pbmsg(::proto_ff::FieldItemAttrInfo & msg) const {
	for(int32_t i = 0; i < (int32_t)base_attr.GetSize() && i < base_attr.GetMaxSize(); ++i) {
		::proto_ff::Attr* temp_base_attr = msg.add_base_attr();
		base_attr[i].write_to_pbmsg(*temp_base_attr);
	}
	for(int32_t i = 0; i < (int32_t)star_attr.GetSize() && i < star_attr.GetMaxSize(); ++i) {
		::proto_ff::Attr* temp_star_attr = msg.add_star_attr();
		star_attr[i].write_to_pbmsg(*temp_star_attr);
	}
	for(int32_t i = 0; i < (int32_t)blue_star_attr.GetSize() && i < blue_star_attr.GetMaxSize(); ++i) {
		::proto_ff::Attr* temp_blue_star_attr = msg.add_blue_star_attr();
		blue_star_attr[i].write_to_pbmsg(*temp_blue_star_attr);
	}
	msg.set_refine_level((int32_t)refine_level);
}

void FieldItemAttrInfo_s::read_from_pbmsg(const ::proto_ff::FieldItemAttrInfo & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct FieldItemAttrInfo_s));
	base_attr.SetSize(msg.base_attr_size() > base_attr.GetMaxSize() ? base_attr.GetMaxSize() : msg.base_attr_size());
	for(int32_t i = 0; i < (int32_t)base_attr.GetSize(); ++i) {
		const ::proto_ff::Attr & temp_base_attr = msg.base_attr(i);
		base_attr[i].read_from_pbmsg(temp_base_attr);
	}
	star_attr.SetSize(msg.star_attr_size() > star_attr.GetMaxSize() ? star_attr.GetMaxSize() : msg.star_attr_size());
	for(int32_t i = 0; i < (int32_t)star_attr.GetSize(); ++i) {
		const ::proto_ff::Attr & temp_star_attr = msg.star_attr(i);
		star_attr[i].read_from_pbmsg(temp_star_attr);
	}
	blue_star_attr.SetSize(msg.blue_star_attr_size() > blue_star_attr.GetMaxSize() ? blue_star_attr.GetMaxSize() : msg.blue_star_attr_size());
	for(int32_t i = 0; i < (int32_t)blue_star_attr.GetSize(); ++i) {
		const ::proto_ff::Attr & temp_blue_star_attr = msg.blue_star_attr(i);
		blue_star_attr[i].read_from_pbmsg(temp_blue_star_attr);
	}
	refine_level = msg.refine_level();
}

MarryEquipInfo_s::MarryEquipInfo_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int MarryEquipInfo_s::CreateInit() {
	strong_lv = (int32_t)0;
	strong_exp = (int32_t)0;
	stage_lv = (int32_t)0;
	return 0;
}

int MarryEquipInfo_s::ResumeInit() {
	return 0;
}

void MarryEquipInfo_s::write_to_pbmsg(::proto_ff::MarryEquipInfo & msg) const {
	msg.set_strong_lv((int32_t)strong_lv);
	msg.set_strong_exp((int32_t)strong_exp);
	msg.set_stage_lv((int32_t)stage_lv);
}

void MarryEquipInfo_s::read_from_pbmsg(const ::proto_ff::MarryEquipInfo & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct MarryEquipInfo_s));
	strong_lv = msg.strong_lv();
	strong_exp = msg.strong_exp();
	stage_lv = msg.stage_lv();
}

ComposeSingleCostProto_s::ComposeSingleCostProto_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int ComposeSingleCostProto_s::CreateInit() {
	itemid = (uint64_t)0;
	bind = (int32_t)0;
	return 0;
}

int ComposeSingleCostProto_s::ResumeInit() {
	return 0;
}

void ComposeSingleCostProto_s::write_to_pbmsg(::proto_ff::ComposeSingleCostProto & msg) const {
	msg.set_itemid((uint64_t)itemid);
	msg.set_bind((int32_t)bind);
}

void ComposeSingleCostProto_s::read_from_pbmsg(const ::proto_ff::ComposeSingleCostProto & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct ComposeSingleCostProto_s));
	itemid = msg.itemid();
	bind = msg.bind();
}

ComposeCostProto_s::ComposeCostProto_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int ComposeCostProto_s::CreateInit() {
	return 0;
}

int ComposeCostProto_s::ResumeInit() {
	return 0;
}

void ComposeCostProto_s::write_to_pbmsg(::proto_ff::ComposeCostProto & msg) const {
	for(int32_t i = 0; i < (int32_t)info.GetSize() && i < info.GetMaxSize(); ++i) {
		::proto_ff::ComposeSingleCostProto* temp_info = msg.add_info();
		info[i].write_to_pbmsg(*temp_info);
	}
}

void ComposeCostProto_s::read_from_pbmsg(const ::proto_ff::ComposeCostProto & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct ComposeCostProto_s));
	info.SetSize(msg.info_size() > info.GetMaxSize() ? info.GetMaxSize() : msg.info_size());
	for(int32_t i = 0; i < (int32_t)info.GetSize(); ++i) {
		const ::proto_ff::ComposeSingleCostProto & temp_info = msg.info(i);
		info[i].read_from_pbmsg(temp_info);
	}
}

blustarAttr_s::blustarAttr_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int blustarAttr_s::CreateInit() {
	attrid = (uint32_t)0;
	levelinterval = (uint32_t)0;
	attrvalue = (uint32_t)0;
	return 0;
}

int blustarAttr_s::ResumeInit() {
	return 0;
}

void blustarAttr_s::write_to_pbmsg(::proto_ff::blustarAttr & msg) const {
	msg.set_attrid((uint32_t)attrid);
	msg.set_levelinterval((uint32_t)levelinterval);
	msg.set_attrvalue((uint32_t)attrvalue);
}

void blustarAttr_s::read_from_pbmsg(const ::proto_ff::blustarAttr & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct blustarAttr_s));
	attrid = msg.attrid();
	levelinterval = msg.levelinterval();
	attrvalue = msg.attrvalue();
}

ItemProtoInfo_s::ItemProtoInfo_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int ItemProtoInfo_s::CreateInit() {
	item_id = (uint64_t)0;
	item_num = (int64_t)0;
	bind = (int32_t)0;
	index = (int32_t)0;
	level = (int32_t)0;
	expireTime = (uint64_t)0;
	out_time = (uint64_t)0;
	return 0;
}

int ItemProtoInfo_s::ResumeInit() {
	return 0;
}

void ItemProtoInfo_s::write_to_pbmsg(::proto_ff::ItemProtoInfo & msg) const {
	msg.set_item_id((uint64_t)item_id);
	msg.set_item_num((int64_t)item_num);
	msg.set_bind((int32_t)bind);
	for(int32_t i = 0; i < (int32_t)baseattr.GetSize() && i < baseattr.GetMaxSize(); ++i) {
		::proto_ff::Attr* temp_baseattr = msg.add_baseattr();
		baseattr[i].write_to_pbmsg(*temp_baseattr);
	}
	msg.set_index((int32_t)index);
	msg.set_level((int32_t)level);
	for(int32_t i = 0; i < (int32_t)refineex.GetSize() && i < refineex.GetMaxSize(); ++i) {
		::proto_ff::Attr* temp_refineex = msg.add_refineex();
		refineex[i].write_to_pbmsg(*temp_refineex);
	}
	for(int32_t i = 0; i < (int32_t)con_attr.GetSize() && i < con_attr.GetMaxSize(); ++i) {
		::proto_ff::blustarAttr* temp_con_attr = msg.add_con_attr();
		con_attr[i].write_to_pbmsg(*temp_con_attr);
	}
	msg.set_expiretime((uint64_t)expireTime);
	::proto_ff::FieldItemAttrInfo* temp_field_data = msg.mutable_field_data();
	field_data.write_to_pbmsg(*temp_field_data);
	::proto_ff::MarryEquipInfo* temp_marry_equip_data = msg.mutable_marry_equip_data();
	marry_equip_data.write_to_pbmsg(*temp_marry_equip_data);
	::proto_ff::ComposeCostProto* temp_compose = msg.mutable_compose();
	compose.write_to_pbmsg(*temp_compose);
	msg.set_out_time((uint64_t)out_time);
}

void ItemProtoInfo_s::read_from_pbmsg(const ::proto_ff::ItemProtoInfo & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct ItemProtoInfo_s));
	item_id = msg.item_id();
	item_num = msg.item_num();
	bind = msg.bind();
	baseattr.SetSize(msg.baseattr_size() > baseattr.GetMaxSize() ? baseattr.GetMaxSize() : msg.baseattr_size());
	for(int32_t i = 0; i < (int32_t)baseattr.GetSize(); ++i) {
		const ::proto_ff::Attr & temp_baseattr = msg.baseattr(i);
		baseattr[i].read_from_pbmsg(temp_baseattr);
	}
	index = msg.index();
	level = msg.level();
	refineex.SetSize(msg.refineex_size() > refineex.GetMaxSize() ? refineex.GetMaxSize() : msg.refineex_size());
	for(int32_t i = 0; i < (int32_t)refineex.GetSize(); ++i) {
		const ::proto_ff::Attr & temp_refineex = msg.refineex(i);
		refineex[i].read_from_pbmsg(temp_refineex);
	}
	con_attr.SetSize(msg.con_attr_size() > con_attr.GetMaxSize() ? con_attr.GetMaxSize() : msg.con_attr_size());
	for(int32_t i = 0; i < (int32_t)con_attr.GetSize(); ++i) {
		const ::proto_ff::blustarAttr & temp_con_attr = msg.con_attr(i);
		con_attr[i].read_from_pbmsg(temp_con_attr);
	}
	expireTime = msg.expiretime();
	const ::proto_ff::FieldItemAttrInfo & temp_field_data = msg.field_data();
	field_data.read_from_pbmsg(temp_field_data);
	const ::proto_ff::MarryEquipInfo & temp_marry_equip_data = msg.marry_equip_data();
	marry_equip_data.read_from_pbmsg(temp_marry_equip_data);
	const ::proto_ff::ComposeCostProto & temp_compose = msg.compose();
	compose.read_from_pbmsg(temp_compose);
	out_time = msg.out_time();
}

CharacterDBPackageBag_s::CharacterDBPackageBag_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int CharacterDBPackageBag_s::CreateInit() {
	package_type = (uint32_t)0;
	expand_num = (uint32_t)0;
	offset = (int32_t)0;
	return 0;
}

int CharacterDBPackageBag_s::ResumeInit() {
	return 0;
}

void CharacterDBPackageBag_s::write_to_pbmsg(::proto_ff::CharacterDBPackageBag & msg) const {
	msg.set_package_type((uint32_t)package_type);
	msg.set_expand_num((uint32_t)expand_num);
	for(int32_t i = 0; i < (int32_t)items.GetSize() && i < items.GetMaxSize(); ++i) {
		::proto_ff::ItemProtoInfo* temp_items = msg.add_items();
		items[i].write_to_pbmsg(*temp_items);
	}
	msg.set_offset((int32_t)offset);
}

void CharacterDBPackageBag_s::read_from_pbmsg(const ::proto_ff::CharacterDBPackageBag & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct CharacterDBPackageBag_s));
	package_type = msg.package_type();
	expand_num = msg.expand_num();
	items.SetSize(msg.items_size() > items.GetMaxSize() ? items.GetMaxSize() : msg.items_size());
	for(int32_t i = 0; i < (int32_t)items.GetSize(); ++i) {
		const ::proto_ff::ItemProtoInfo & temp_items = msg.items(i);
		items[i].read_from_pbmsg(temp_items);
	}
	offset = msg.offset();
}

CharacterDBPackageData_s::CharacterDBPackageData_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int CharacterDBPackageData_s::CreateInit() {
	return 0;
}

int CharacterDBPackageData_s::ResumeInit() {
	return 0;
}

void CharacterDBPackageData_s::write_to_pbmsg(::proto_ff::CharacterDBPackageData & msg) const {
	for(int32_t i = 0; i < (int32_t)bags.GetSize() && i < bags.GetMaxSize(); ++i) {
		::proto_ff::CharacterDBPackageBag* temp_bags = msg.add_bags();
		bags[i].write_to_pbmsg(*temp_bags);
	}
}

void CharacterDBPackageData_s::read_from_pbmsg(const ::proto_ff::CharacterDBPackageData & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct CharacterDBPackageData_s));
	bags.SetSize(msg.bags_size() > bags.GetMaxSize() ? bags.GetMaxSize() : msg.bags_size());
	for(int32_t i = 0; i < (int32_t)bags.GetSize(); ++i) {
		const ::proto_ff::CharacterDBPackageBag & temp_bags = msg.bags(i);
		bags[i].read_from_pbmsg(temp_bags);
	}
}

tbRoleInfo_s::tbRoleInfo_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int tbRoleInfo_s::CreateInit() {
	charId = (uint64_t)0;
	playerId = (uint64_t)0;
	bornZoneId = (uint64_t)0;
	return 0;
}

int tbRoleInfo_s::ResumeInit() {
	return 0;
}

void tbRoleInfo_s::write_to_pbmsg(::proto_ff::tbRoleInfo & msg) const {
	msg.set_charid((uint64_t)charId);
	msg.set_playerid((uint64_t)playerId);
	msg.set_bornzoneid((uint64_t)bornZoneId);
	msg.set_charname((const char*)charName.Get());
	msg.set_platid((const char*)platId.Get());
	::proto_ff::CharacterDBBaseInfo* temp_basedata = msg.mutable_basedata();
	baseData.write_to_pbmsg(*temp_basedata);
	::proto_ff::CharacterDBPackageData* temp_itemdata = msg.mutable_itemdata();
	itemData.write_to_pbmsg(*temp_itemdata);
}

void tbRoleInfo_s::read_from_pbmsg(const ::proto_ff::tbRoleInfo & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct tbRoleInfo_s));
	charId = msg.charid();
	playerId = msg.playerid();
	bornZoneId = msg.bornzoneid();
	charName.Copy(msg.charname());
	platId.Copy(msg.platid());
	const ::proto_ff::CharacterDBBaseInfo & temp_basedata = msg.basedata();
	baseData.read_from_pbmsg(temp_basedata);
	const ::proto_ff::CharacterDBPackageData & temp_itemdata = msg.itemdata();
	itemData.read_from_pbmsg(temp_itemdata);
}

}