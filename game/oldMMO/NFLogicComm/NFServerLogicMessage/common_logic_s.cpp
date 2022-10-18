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

AttrEx64_s::AttrEx64_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int AttrEx64_s::CreateInit() {
	AttrNum = (uint32_t)0;
	Attrvalue = (uint64_t)0;
	AttrIndex = (uint32_t)0;
	return 0;
}

int AttrEx64_s::ResumeInit() {
	return 0;
}

void AttrEx64_s::write_to_pbmsg(::proto_ff::AttrEx64 & msg) const {
	msg.set_attrnum((uint32_t)AttrNum);
	msg.set_attrvalue((uint64_t)Attrvalue);
	msg.set_attrindex((uint32_t)AttrIndex);
}

void AttrEx64_s::read_from_pbmsg(const ::proto_ff::AttrEx64 & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct AttrEx64_s));
	AttrNum = msg.attrnum();
	Attrvalue = msg.attrvalue();
	AttrIndex = msg.attrindex();
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

CharacterDBSkillItem_s::CharacterDBSkillItem_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int CharacterDBSkillItem_s::CreateInit() {
	skillID = (int64_t)0;
	skillLevel = (int32_t)0;
	cd = (uint64_t)0;
	unlock = (int32_t)0;
	replace_skillid = (int64_t)0;
	return 0;
}

int CharacterDBSkillItem_s::ResumeInit() {
	return 0;
}

void CharacterDBSkillItem_s::write_to_pbmsg(::proto_ff::CharacterDBSkillItem & msg) const {
	msg.set_skillid((int64_t)skillID);
	msg.set_skilllevel((int32_t)skillLevel);
	msg.set_cd((uint64_t)cd);
	msg.set_unlock((int32_t)unlock);
	msg.set_replace_skillid((int64_t)replace_skillid);
}

void CharacterDBSkillItem_s::read_from_pbmsg(const ::proto_ff::CharacterDBSkillItem & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct CharacterDBSkillItem_s));
	skillID = msg.skillid();
	skillLevel = msg.skilllevel();
	cd = msg.cd();
	unlock = msg.unlock();
	replace_skillid = msg.replace_skillid();
}

CharacterDBSkillData_s::CharacterDBSkillData_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int CharacterDBSkillData_s::CreateInit() {
	return 0;
}

int CharacterDBSkillData_s::ResumeInit() {
	return 0;
}

void CharacterDBSkillData_s::write_to_pbmsg(::proto_ff::CharacterDBSkillData & msg) const {
	for(int32_t i = 0; i < (int32_t)skillList.GetSize() && i < skillList.GetMaxSize(); ++i) {
		::proto_ff::CharacterDBSkillItem* temp_skilllist = msg.add_skilllist();
		skillList[i].write_to_pbmsg(*temp_skilllist);
	}
	for(int32_t i = 0; i < (int32_t)skillAttrs.GetSize() && i < skillAttrs.GetMaxSize(); ++i) {
		msg.add_skillattrs((uint32_t)skillAttrs[i]);
	}
	for(int32_t i = 0; i < (int32_t)skillslot.GetSize() && i < skillslot.GetMaxSize(); ++i) {
		msg.add_skillslot((int64_t)skillslot[i]);
	}
}

void CharacterDBSkillData_s::read_from_pbmsg(const ::proto_ff::CharacterDBSkillData & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct CharacterDBSkillData_s));
	skillList.SetSize(msg.skilllist_size() > skillList.GetMaxSize() ? skillList.GetMaxSize() : msg.skilllist_size());
	for(int32_t i = 0; i < (int32_t)skillList.GetSize(); ++i) {
		const ::proto_ff::CharacterDBSkillItem & temp_skilllist = msg.skilllist(i);
		skillList[i].read_from_pbmsg(temp_skilllist);
	}
	skillAttrs.SetSize(msg.skillattrs_size() > skillAttrs.GetMaxSize() ? skillAttrs.GetMaxSize() : msg.skillattrs_size());
	for(int32_t i = 0; i < (int32_t)skillAttrs.GetSize(); ++i) {
		skillAttrs[i] = msg.skillattrs(i);
	}
	skillslot.SetSize(msg.skillslot_size() > skillslot.GetMaxSize() ? skillslot.GetMaxSize() : msg.skillslot_size());
	for(int32_t i = 0; i < (int32_t)skillslot.GetSize(); ++i) {
		skillslot[i] = msg.skillslot(i);
	}
}

CharacterDBAttrDetailInfo_s::CharacterDBAttrDetailInfo_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int CharacterDBAttrDetailInfo_s::CreateInit() {
	return 0;
}

int CharacterDBAttrDetailInfo_s::ResumeInit() {
	return 0;
}

void CharacterDBAttrDetailInfo_s::write_to_pbmsg(::proto_ff::CharacterDBAttrDetailInfo & msg) const {
	for(int32_t i = 0; i < (int32_t)attrs.GetSize() && i < attrs.GetMaxSize(); ++i) {
		::proto_ff::Attr64* temp_attrs = msg.add_attrs();
		attrs[i].write_to_pbmsg(*temp_attrs);
	}
	::proto_ff::Vector3PB* temp_cur_pos = msg.mutable_cur_pos();
	cur_pos.write_to_pbmsg(*temp_cur_pos);
}

void CharacterDBAttrDetailInfo_s::read_from_pbmsg(const ::proto_ff::CharacterDBAttrDetailInfo & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct CharacterDBAttrDetailInfo_s));
	attrs.SetSize(msg.attrs_size() > attrs.GetMaxSize() ? attrs.GetMaxSize() : msg.attrs_size());
	for(int32_t i = 0; i < (int32_t)attrs.GetSize(); ++i) {
		const ::proto_ff::Attr64 & temp_attrs = msg.attrs(i);
		attrs[i].read_from_pbmsg(temp_attrs);
	}
	const ::proto_ff::Vector3PB & temp_cur_pos = msg.cur_pos();
	cur_pos.read_from_pbmsg(temp_cur_pos);
}

CharacterDBExtendData_s::CharacterDBExtendData_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int CharacterDBExtendData_s::CreateInit() {
	return 0;
}

int CharacterDBExtendData_s::ResumeInit() {
	return 0;
}

void CharacterDBExtendData_s::write_to_pbmsg(::proto_ff::CharacterDBExtendData & msg) const {
	::proto_ff::CharacterDBAttrDetailInfo* temp_attr_detail = msg.mutable_attr_detail();
	attr_detail.write_to_pbmsg(*temp_attr_detail);
}

void CharacterDBExtendData_s::read_from_pbmsg(const ::proto_ff::CharacterDBExtendData & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct CharacterDBExtendData_s));
	const ::proto_ff::CharacterDBAttrDetailInfo & temp_attr_detail = msg.attr_detail();
	attr_detail.read_from_pbmsg(temp_attr_detail);
}

EquipSlotProto_s::EquipSlotProto_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int EquipSlotProto_s::CreateInit() {
	index = (int32_t)0;
	strenlv = (int32_t)0;
	refinelv = (int32_t)0;
	strenexp = (int32_t)0;
	refineexp = (int32_t)0;
	refinepecent = (int64_t)0;
	scrutinyTrepanningNum = (int32_t)0;
	clearStep = (int32_t)0;
	clearCombat = (int64_t)0;
	suitlv = (int32_t)0;
	suit_record_max_lv = (int32_t)0;
	awaklv = (int32_t)0;
	enchantinglv = (int32_t)0;
	return 0;
}

int EquipSlotProto_s::ResumeInit() {
	return 0;
}

void EquipSlotProto_s::write_to_pbmsg(::proto_ff::EquipSlotProto & msg) const {
	msg.set_index((int32_t)index);
	msg.set_strenlv((int32_t)strenlv);
	msg.set_refinelv((int32_t)refinelv);
	for(int32_t i = 0; i < (int32_t)inlay.GetSize() && i < inlay.GetMaxSize(); ++i) {
		msg.add_inlay((uint64_t)inlay[i]);
	}
	msg.set_strenexp((int32_t)strenexp);
	msg.set_refineexp((int32_t)refineexp);
	for(int32_t i = 0; i < (int32_t)strenAttr.GetSize() && i < strenAttr.GetMaxSize(); ++i) {
		::proto_ff::Attr* temp_strenattr = msg.add_strenattr();
		strenAttr[i].write_to_pbmsg(*temp_strenattr);
	}
	msg.set_refinepecent((int64_t)refinepecent);
	msg.set_scrutinytrepanningnum((int32_t)scrutinyTrepanningNum);
	for(int32_t i = 0; i < (int32_t)scrutinyAttr.GetSize() && i < scrutinyAttr.GetMaxSize(); ++i) {
		::proto_ff::AttrEx64* temp_scrutinyattr = msg.add_scrutinyattr();
		scrutinyAttr[i].write_to_pbmsg(*temp_scrutinyattr);
	}
	msg.set_clearstep((int32_t)clearStep);
	msg.set_clearcombat((int64_t)clearCombat);
	msg.set_suitlv((int32_t)suitlv);
	msg.set_suit_record_max_lv((int32_t)suit_record_max_lv);
	msg.set_awaklv((int32_t)awaklv);
	msg.set_enchantinglv((int32_t)enchantinglv);
}

void EquipSlotProto_s::read_from_pbmsg(const ::proto_ff::EquipSlotProto & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct EquipSlotProto_s));
	index = msg.index();
	strenlv = msg.strenlv();
	refinelv = msg.refinelv();
	inlay.SetSize(msg.inlay_size() > inlay.GetMaxSize() ? inlay.GetMaxSize() : msg.inlay_size());
	for(int32_t i = 0; i < (int32_t)inlay.GetSize(); ++i) {
		inlay[i] = msg.inlay(i);
	}
	strenexp = msg.strenexp();
	refineexp = msg.refineexp();
	strenAttr.SetSize(msg.strenattr_size() > strenAttr.GetMaxSize() ? strenAttr.GetMaxSize() : msg.strenattr_size());
	for(int32_t i = 0; i < (int32_t)strenAttr.GetSize(); ++i) {
		const ::proto_ff::Attr & temp_strenattr = msg.strenattr(i);
		strenAttr[i].read_from_pbmsg(temp_strenattr);
	}
	refinepecent = msg.refinepecent();
	scrutinyTrepanningNum = msg.scrutinytrepanningnum();
	scrutinyAttr.SetSize(msg.scrutinyattr_size() > scrutinyAttr.GetMaxSize() ? scrutinyAttr.GetMaxSize() : msg.scrutinyattr_size());
	for(int32_t i = 0; i < (int32_t)scrutinyAttr.GetSize(); ++i) {
		const ::proto_ff::AttrEx64 & temp_scrutinyattr = msg.scrutinyattr(i);
		scrutinyAttr[i].read_from_pbmsg(temp_scrutinyattr);
	}
	clearStep = msg.clearstep();
	clearCombat = msg.clearcombat();
	suitlv = msg.suitlv();
	suit_record_max_lv = msg.suit_record_max_lv();
	awaklv = msg.awaklv();
	enchantinglv = msg.enchantinglv();
}

CharacterDBEquipData_s::CharacterDBEquipData_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int CharacterDBEquipData_s::CreateInit() {
	return 0;
}

int CharacterDBEquipData_s::ResumeInit() {
	return 0;
}

void CharacterDBEquipData_s::write_to_pbmsg(::proto_ff::CharacterDBEquipData & msg) const {
	for(int32_t i = 0; i < (int32_t)equip.GetSize() && i < equip.GetMaxSize(); ++i) {
		::proto_ff::ItemProtoInfo* temp_equip = msg.add_equip();
		equip[i].write_to_pbmsg(*temp_equip);
	}
	for(int32_t i = 0; i < (int32_t)equip_slot.GetSize() && i < equip_slot.GetMaxSize(); ++i) {
		::proto_ff::EquipSlotProto* temp_equip_slot = msg.add_equip_slot();
		equip_slot[i].write_to_pbmsg(*temp_equip_slot);
	}
}

void CharacterDBEquipData_s::read_from_pbmsg(const ::proto_ff::CharacterDBEquipData & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct CharacterDBEquipData_s));
	equip.SetSize(msg.equip_size() > equip.GetMaxSize() ? equip.GetMaxSize() : msg.equip_size());
	for(int32_t i = 0; i < (int32_t)equip.GetSize(); ++i) {
		const ::proto_ff::ItemProtoInfo & temp_equip = msg.equip(i);
		equip[i].read_from_pbmsg(temp_equip);
	}
	equip_slot.SetSize(msg.equip_slot_size() > equip_slot.GetMaxSize() ? equip_slot.GetMaxSize() : msg.equip_slot_size());
	for(int32_t i = 0; i < (int32_t)equip_slot.GetSize(); ++i) {
		const ::proto_ff::EquipSlotProto & temp_equip_slot = msg.equip_slot(i);
		equip_slot[i].read_from_pbmsg(temp_equip_slot);
	}
}

DuplicateSingleProto_s::DuplicateSingleProto_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int DuplicateSingleProto_s::CreateInit() {
	duplicate_id = (uint64_t)0;
	star = (int32_t)0;
	cur_layer = (int32_t)0;
	return 0;
}

int DuplicateSingleProto_s::ResumeInit() {
	return 0;
}

void DuplicateSingleProto_s::write_to_pbmsg(::proto_ff::DuplicateSingleProto & msg) const {
	msg.set_duplicate_id((uint64_t)duplicate_id);
	msg.set_star((int32_t)star);
	msg.set_cur_layer((int32_t)cur_layer);
}

void DuplicateSingleProto_s::read_from_pbmsg(const ::proto_ff::DuplicateSingleProto & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct DuplicateSingleProto_s));
	duplicate_id = msg.duplicate_id();
	star = msg.star();
	cur_layer = msg.cur_layer();
}

DuplicateGroupProto_s::DuplicateGroupProto_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int DuplicateGroupProto_s::CreateInit() {
	group_id = (uint64_t)0;
	enter_num = (int32_t)0;
	total_num = (int32_t)0;
	buy_num = (int32_t)0;
	last_fresh = (uint64_t)0;
	return 0;
}

int DuplicateGroupProto_s::ResumeInit() {
	return 0;
}

void DuplicateGroupProto_s::write_to_pbmsg(::proto_ff::DuplicateGroupProto & msg) const {
	msg.set_group_id((uint64_t)group_id);
	msg.set_enter_num((int32_t)enter_num);
	msg.set_total_num((int32_t)total_num);
	msg.set_buy_num((int32_t)buy_num);
	msg.set_last_fresh((uint64_t)last_fresh);
}

void DuplicateGroupProto_s::read_from_pbmsg(const ::proto_ff::DuplicateGroupProto & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct DuplicateGroupProto_s));
	group_id = msg.group_id();
	enter_num = msg.enter_num();
	total_num = msg.total_num();
	buy_num = msg.buy_num();
	last_fresh = msg.last_fresh();
}

DuplicateLadderExProto_s::DuplicateLadderExProto_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int DuplicateLadderExProto_s::CreateInit() {
	cur_layer = (int32_t)0;
	last_mail_time = (uint64_t)0;
	return 0;
}

int DuplicateLadderExProto_s::ResumeInit() {
	return 0;
}

void DuplicateLadderExProto_s::write_to_pbmsg(::proto_ff::DuplicateLadderExProto & msg) const {
	msg.set_cur_layer((int32_t)cur_layer);
	msg.set_last_mail_time((uint64_t)last_mail_time);
}

void DuplicateLadderExProto_s::read_from_pbmsg(const ::proto_ff::DuplicateLadderExProto & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct DuplicateLadderExProto_s));
	cur_layer = msg.cur_layer();
	last_mail_time = msg.last_mail_time();
}

DupHistoryExpProto_s::DupHistoryExpProto_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int DupHistoryExpProto_s::CreateInit() {
	duplicate_id = (uint64_t)0;
	exp = (uint64_t)0;
	return 0;
}

int DupHistoryExpProto_s::ResumeInit() {
	return 0;
}

void DupHistoryExpProto_s::write_to_pbmsg(::proto_ff::DupHistoryExpProto & msg) const {
	msg.set_duplicate_id((uint64_t)duplicate_id);
	msg.set_exp((uint64_t)exp);
}

void DupHistoryExpProto_s::read_from_pbmsg(const ::proto_ff::DupHistoryExpProto & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct DupHistoryExpProto_s));
	duplicate_id = msg.duplicate_id();
	exp = msg.exp();
}

DupUnionBossDBProto_s::DupUnionBossDBProto_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int DupUnionBossDBProto_s::CreateInit() {
	last_pass = (uint64_t)0;
	last_fail = (uint64_t)0;
	return 0;
}

int DupUnionBossDBProto_s::ResumeInit() {
	return 0;
}

void DupUnionBossDBProto_s::write_to_pbmsg(::proto_ff::DupUnionBossDBProto & msg) const {
	for(int32_t i = 0; i < (int32_t)mutex_id.GetSize() && i < mutex_id.GetMaxSize(); ++i) {
		msg.add_mutex_id((uint64_t)mutex_id[i]);
	}
	msg.set_last_pass((uint64_t)last_pass);
	msg.set_last_fail((uint64_t)last_fail);
}

void DupUnionBossDBProto_s::read_from_pbmsg(const ::proto_ff::DupUnionBossDBProto & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct DupUnionBossDBProto_s));
	mutex_id.SetSize(msg.mutex_id_size() > mutex_id.GetMaxSize() ? mutex_id.GetMaxSize() : msg.mutex_id_size());
	for(int32_t i = 0; i < (int32_t)mutex_id.GetSize(); ++i) {
		mutex_id[i] = msg.mutex_id(i);
	}
	last_pass = msg.last_pass();
	last_fail = msg.last_fail();
}

DupPalaceFetchDBProto_s::DupPalaceFetchDBProto_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int DupPalaceFetchDBProto_s::CreateInit() {
	layer = (int32_t)0;
	pass_num = (int32_t)0;
	return 0;
}

int DupPalaceFetchDBProto_s::ResumeInit() {
	return 0;
}

void DupPalaceFetchDBProto_s::write_to_pbmsg(::proto_ff::DupPalaceFetchDBProto & msg) const {
	msg.set_layer((int32_t)layer);
	msg.set_pass_num((int32_t)pass_num);
	for(int32_t i = 0; i < (int32_t)num_lst.GetSize() && i < num_lst.GetMaxSize(); ++i) {
		msg.add_num_lst((uint32_t)num_lst[i]);
	}
}

void DupPalaceFetchDBProto_s::read_from_pbmsg(const ::proto_ff::DupPalaceFetchDBProto & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct DupPalaceFetchDBProto_s));
	layer = msg.layer();
	pass_num = msg.pass_num();
	num_lst.SetSize(msg.num_lst_size() > num_lst.GetMaxSize() ? num_lst.GetMaxSize() : msg.num_lst_size());
	for(int32_t i = 0; i < (int32_t)num_lst.GetSize(); ++i) {
		num_lst[i] = msg.num_lst(i);
	}
}

DupPalaceMultFetchDBProto_s::DupPalaceMultFetchDBProto_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int DupPalaceMultFetchDBProto_s::CreateInit() {
	return 0;
}

int DupPalaceMultFetchDBProto_s::ResumeInit() {
	return 0;
}

void DupPalaceMultFetchDBProto_s::write_to_pbmsg(::proto_ff::DupPalaceMultFetchDBProto & msg) const {
	for(int32_t i = 0; i < (int32_t)fetch_progress.GetSize() && i < fetch_progress.GetMaxSize(); ++i) {
		::proto_ff::DupPalaceFetchDBProto* temp_fetch_progress = msg.add_fetch_progress();
		fetch_progress[i].write_to_pbmsg(*temp_fetch_progress);
	}
}

void DupPalaceMultFetchDBProto_s::read_from_pbmsg(const ::proto_ff::DupPalaceMultFetchDBProto & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct DupPalaceMultFetchDBProto_s));
	fetch_progress.SetSize(msg.fetch_progress_size() > fetch_progress.GetMaxSize() ? fetch_progress.GetMaxSize() : msg.fetch_progress_size());
	for(int32_t i = 0; i < (int32_t)fetch_progress.GetSize(); ++i) {
		const ::proto_ff::DupPalaceFetchDBProto & temp_fetch_progress = msg.fetch_progress(i);
		fetch_progress[i].read_from_pbmsg(temp_fetch_progress);
	}
}

DupUnionPalaceDBProto_s::DupUnionPalaceDBProto_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int DupUnionPalaceDBProto_s::CreateInit() {
	layer = (int32_t)0;
	break_count = (int32_t)0;
	return 0;
}

int DupUnionPalaceDBProto_s::ResumeInit() {
	return 0;
}

void DupUnionPalaceDBProto_s::write_to_pbmsg(::proto_ff::DupUnionPalaceDBProto & msg) const {
	msg.set_layer((int32_t)layer);
	for(int32_t i = 0; i < (int32_t)fetched_lst.GetSize() && i < fetched_lst.GetMaxSize(); ++i) {
		msg.add_fetched_lst((int32_t)fetched_lst[i]);
	}
	::proto_ff::DupPalaceMultFetchDBProto* temp_fetch = msg.mutable_fetch();
	fetch.write_to_pbmsg(*temp_fetch);
	msg.set_break_count((int32_t)break_count);
}

void DupUnionPalaceDBProto_s::read_from_pbmsg(const ::proto_ff::DupUnionPalaceDBProto & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct DupUnionPalaceDBProto_s));
	layer = msg.layer();
	fetched_lst.SetSize(msg.fetched_lst_size() > fetched_lst.GetMaxSize() ? fetched_lst.GetMaxSize() : msg.fetched_lst_size());
	for(int32_t i = 0; i < (int32_t)fetched_lst.GetSize(); ++i) {
		fetched_lst[i] = msg.fetched_lst(i);
	}
	const ::proto_ff::DupPalaceMultFetchDBProto & temp_fetch = msg.fetch();
	fetch.read_from_pbmsg(temp_fetch);
	break_count = msg.break_count();
}

CharacterDBDuplicateData_s::CharacterDBDuplicateData_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int CharacterDBDuplicateData_s::CreateInit() {
	return 0;
}

int CharacterDBDuplicateData_s::ResumeInit() {
	return 0;
}

void CharacterDBDuplicateData_s::write_to_pbmsg(::proto_ff::CharacterDBDuplicateData & msg) const {
	for(int32_t i = 0; i < (int32_t)duplicate.GetSize() && i < duplicate.GetMaxSize(); ++i) {
		::proto_ff::DuplicateSingleProto* temp_duplicate = msg.add_duplicate();
		duplicate[i].write_to_pbmsg(*temp_duplicate);
	}
	for(int32_t i = 0; i < (int32_t)group.GetSize() && i < group.GetMaxSize(); ++i) {
		::proto_ff::DuplicateGroupProto* temp_group = msg.add_group();
		group[i].write_to_pbmsg(*temp_group);
	}
	for(int32_t i = 0; i < (int32_t)open_dup.GetSize() && i < open_dup.GetMaxSize(); ++i) {
		msg.add_open_dup((uint32_t)open_dup[i]);
	}
	::proto_ff::DuplicateLadderExProto* temp_ladder = msg.mutable_ladder();
	ladder.write_to_pbmsg(*temp_ladder);
	for(int32_t i = 0; i < (int32_t)dup_exp.GetSize() && i < dup_exp.GetMaxSize(); ++i) {
		::proto_ff::DupHistoryExpProto* temp_dup_exp = msg.add_dup_exp();
		dup_exp[i].write_to_pbmsg(*temp_dup_exp);
	}
	::proto_ff::DupUnionBossDBProto* temp_union_boss = msg.mutable_union_boss();
	union_boss.write_to_pbmsg(*temp_union_boss);
	::proto_ff::DupUnionPalaceDBProto* temp_palace = msg.mutable_palace();
	palace.write_to_pbmsg(*temp_palace);
}

void CharacterDBDuplicateData_s::read_from_pbmsg(const ::proto_ff::CharacterDBDuplicateData & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct CharacterDBDuplicateData_s));
	duplicate.SetSize(msg.duplicate_size() > duplicate.GetMaxSize() ? duplicate.GetMaxSize() : msg.duplicate_size());
	for(int32_t i = 0; i < (int32_t)duplicate.GetSize(); ++i) {
		const ::proto_ff::DuplicateSingleProto & temp_duplicate = msg.duplicate(i);
		duplicate[i].read_from_pbmsg(temp_duplicate);
	}
	group.SetSize(msg.group_size() > group.GetMaxSize() ? group.GetMaxSize() : msg.group_size());
	for(int32_t i = 0; i < (int32_t)group.GetSize(); ++i) {
		const ::proto_ff::DuplicateGroupProto & temp_group = msg.group(i);
		group[i].read_from_pbmsg(temp_group);
	}
	open_dup.SetSize(msg.open_dup_size() > open_dup.GetMaxSize() ? open_dup.GetMaxSize() : msg.open_dup_size());
	for(int32_t i = 0; i < (int32_t)open_dup.GetSize(); ++i) {
		open_dup[i] = msg.open_dup(i);
	}
	const ::proto_ff::DuplicateLadderExProto & temp_ladder = msg.ladder();
	ladder.read_from_pbmsg(temp_ladder);
	dup_exp.SetSize(msg.dup_exp_size() > dup_exp.GetMaxSize() ? dup_exp.GetMaxSize() : msg.dup_exp_size());
	for(int32_t i = 0; i < (int32_t)dup_exp.GetSize(); ++i) {
		const ::proto_ff::DupHistoryExpProto & temp_dup_exp = msg.dup_exp(i);
		dup_exp[i].read_from_pbmsg(temp_dup_exp);
	}
	const ::proto_ff::DupUnionBossDBProto & temp_union_boss = msg.union_boss();
	union_boss.read_from_pbmsg(temp_union_boss);
	const ::proto_ff::DupUnionPalaceDBProto & temp_palace = msg.palace();
	palace.read_from_pbmsg(temp_palace);
}

SingleAchievementDBData_s::SingleAchievementDBData_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int SingleAchievementDBData_s::CreateInit() {
	id = (uint64_t)0;
	status = (uint32_t)0;
	completeCount = (uint32_t)0;
	return 0;
}

int SingleAchievementDBData_s::ResumeInit() {
	return 0;
}

void SingleAchievementDBData_s::write_to_pbmsg(::proto_ff::SingleAchievementDBData & msg) const {
	msg.set_id((uint64_t)id);
	msg.set_status((uint32_t)status);
	msg.set_completecount((uint32_t)completeCount);
}

void SingleAchievementDBData_s::read_from_pbmsg(const ::proto_ff::SingleAchievementDBData & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct SingleAchievementDBData_s));
	id = msg.id();
	status = msg.status();
	completeCount = msg.completecount();
}

GroupAchievementDBData_s::GroupAchievementDBData_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int GroupAchievementDBData_s::CreateInit() {
	sortType = (uint32_t)0;
	achievementReward = (uint32_t)0;
	return 0;
}

int GroupAchievementDBData_s::ResumeInit() {
	return 0;
}

void GroupAchievementDBData_s::write_to_pbmsg(::proto_ff::GroupAchievementDBData & msg) const {
	msg.set_sorttype((uint32_t)sortType);
	for(int32_t i = 0; i < (int32_t)achievementInfoList.GetSize() && i < achievementInfoList.GetMaxSize(); ++i) {
		::proto_ff::SingleAchievementDBData* temp_achievementinfolist = msg.add_achievementinfolist();
		achievementInfoList[i].write_to_pbmsg(*temp_achievementinfolist);
	}
	msg.set_achievementreward((uint32_t)achievementReward);
}

void GroupAchievementDBData_s::read_from_pbmsg(const ::proto_ff::GroupAchievementDBData & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct GroupAchievementDBData_s));
	sortType = msg.sorttype();
	achievementInfoList.SetSize(msg.achievementinfolist_size() > achievementInfoList.GetMaxSize() ? achievementInfoList.GetMaxSize() : msg.achievementinfolist_size());
	for(int32_t i = 0; i < (int32_t)achievementInfoList.GetSize(); ++i) {
		const ::proto_ff::SingleAchievementDBData & temp_achievementinfolist = msg.achievementinfolist(i);
		achievementInfoList[i].read_from_pbmsg(temp_achievementinfolist);
	}
	achievementReward = msg.achievementreward();
}

CharacterAchievementDBData_s::CharacterAchievementDBData_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int CharacterAchievementDBData_s::CreateInit() {
	return 0;
}

int CharacterAchievementDBData_s::ResumeInit() {
	return 0;
}

void CharacterAchievementDBData_s::write_to_pbmsg(::proto_ff::CharacterAchievementDBData & msg) const {
	for(int32_t i = 0; i < (int32_t)groupAchievementData.GetSize() && i < groupAchievementData.GetMaxSize(); ++i) {
		::proto_ff::GroupAchievementDBData* temp_groupachievementdata = msg.add_groupachievementdata();
		groupAchievementData[i].write_to_pbmsg(*temp_groupachievementdata);
	}
}

void CharacterAchievementDBData_s::read_from_pbmsg(const ::proto_ff::CharacterAchievementDBData & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct CharacterAchievementDBData_s));
	groupAchievementData.SetSize(msg.groupachievementdata_size() > groupAchievementData.GetMaxSize() ? groupAchievementData.GetMaxSize() : msg.groupachievementdata_size());
	for(int32_t i = 0; i < (int32_t)groupAchievementData.GetSize(); ++i) {
		const ::proto_ff::GroupAchievementDBData & temp_groupachievementdata = msg.groupachievementdata(i);
		groupAchievementData[i].read_from_pbmsg(temp_groupachievementdata);
	}
}

EffectParamProto_s::EffectParamProto_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int EffectParamProto_s::CreateInit() {
	param1 = (int64_t)0;
	param2 = (int64_t)0;
	return 0;
}

int EffectParamProto_s::ResumeInit() {
	return 0;
}

void EffectParamProto_s::write_to_pbmsg(::proto_ff::EffectParamProto & msg) const {
	msg.set_param1((int64_t)param1);
	msg.set_param2((int64_t)param2);
}

void EffectParamProto_s::read_from_pbmsg(const ::proto_ff::EffectParamProto & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct EffectParamProto_s));
	param1 = msg.param1();
	param2 = msg.param2();
}

MultEffectParamProto_s::MultEffectParamProto_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int MultEffectParamProto_s::CreateInit() {
	return 0;
}

int MultEffectParamProto_s::ResumeInit() {
	return 0;
}

void MultEffectParamProto_s::write_to_pbmsg(::proto_ff::MultEffectParamProto & msg) const {
	for(int32_t i = 0; i < (int32_t)param_lst.GetSize() && i < param_lst.GetMaxSize(); ++i) {
		::proto_ff::EffectParamProto* temp_param_lst = msg.add_param_lst();
		param_lst[i].write_to_pbmsg(*temp_param_lst);
	}
}

void MultEffectParamProto_s::read_from_pbmsg(const ::proto_ff::MultEffectParamProto & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct MultEffectParamProto_s));
	param_lst.SetSize(msg.param_lst_size() > param_lst.GetMaxSize() ? param_lst.GetMaxSize() : msg.param_lst_size());
	for(int32_t i = 0; i < (int32_t)param_lst.GetSize(); ++i) {
		const ::proto_ff::EffectParamProto & temp_param_lst = msg.param_lst(i);
		param_lst[i].read_from_pbmsg(temp_param_lst);
	}
}

BuffBagInfo_s::BuffBagInfo_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int BuffBagInfo_s::CreateInit() {
	buffBagInstId = (uint32_t)0;
	stateBagId = (uint64_t)0;
	stateBagTime = (uint32_t)0;
	delayedTime = (uint32_t)0;
	isForever = (bool)0;
	skillId = (uint64_t)0;
	skillLevel = (uint32_t)0;
	senderCid = (uint64_t)0;
	status = (uint32_t)0;
	targettype = (uint32_t)0;
	startTime = (uint64_t)0;
	return 0;
}

int BuffBagInfo_s::ResumeInit() {
	return 0;
}

void BuffBagInfo_s::write_to_pbmsg(::proto_ff::BuffBagInfo & msg) const {
	msg.set_buffbaginstid((uint32_t)buffBagInstId);
	msg.set_statebagid((uint64_t)stateBagId);
	msg.set_statebagtime((uint32_t)stateBagTime);
	msg.set_delayedtime((uint32_t)delayedTime);
	msg.set_isforever((bool)isForever);
	msg.set_skillid((uint64_t)skillId);
	msg.set_skilllevel((uint32_t)skillLevel);
	msg.set_sendercid((uint64_t)senderCid);
	for(int32_t i = 0; i < (int32_t)params.GetSize() && i < params.GetMaxSize(); ++i) {
		msg.add_params((uint64_t)params[i]);
	}
	msg.set_status((uint32_t)status);
	msg.set_targettype((uint32_t)targettype);
	msg.set_starttime((uint64_t)startTime);
	::proto_ff::MultEffectParamProto* temp_eparam = msg.mutable_eparam();
	eparam.write_to_pbmsg(*temp_eparam);
}

void BuffBagInfo_s::read_from_pbmsg(const ::proto_ff::BuffBagInfo & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct BuffBagInfo_s));
	buffBagInstId = msg.buffbaginstid();
	stateBagId = msg.statebagid();
	stateBagTime = msg.statebagtime();
	delayedTime = msg.delayedtime();
	isForever = msg.isforever();
	skillId = msg.skillid();
	skillLevel = msg.skilllevel();
	senderCid = msg.sendercid();
	params.SetSize(msg.params_size() > params.GetMaxSize() ? params.GetMaxSize() : msg.params_size());
	for(int32_t i = 0; i < (int32_t)params.GetSize(); ++i) {
		params[i] = msg.params(i);
	}
	status = msg.status();
	targettype = msg.targettype();
	startTime = msg.starttime();
	const ::proto_ff::MultEffectParamProto & temp_eparam = msg.eparam();
	eparam.read_from_pbmsg(temp_eparam);
}

CharacterBuffData_s::CharacterBuffData_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int CharacterBuffData_s::CreateInit() {
	return 0;
}

int CharacterBuffData_s::ResumeInit() {
	return 0;
}

void CharacterBuffData_s::write_to_pbmsg(::proto_ff::CharacterBuffData & msg) const {
	for(int32_t i = 0; i < (int32_t)delayedBag.GetSize() && i < delayedBag.GetMaxSize(); ++i) {
		::proto_ff::BuffBagInfo* temp_delayedbag = msg.add_delayedbag();
		delayedBag[i].write_to_pbmsg(*temp_delayedbag);
	}
	for(int32_t i = 0; i < (int32_t)buffbagLst.GetSize() && i < buffbagLst.GetMaxSize(); ++i) {
		::proto_ff::BuffBagInfo* temp_buffbaglst = msg.add_buffbaglst();
		buffbagLst[i].write_to_pbmsg(*temp_buffbaglst);
	}
}

void CharacterBuffData_s::read_from_pbmsg(const ::proto_ff::CharacterBuffData & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct CharacterBuffData_s));
	delayedBag.SetSize(msg.delayedbag_size() > delayedBag.GetMaxSize() ? delayedBag.GetMaxSize() : msg.delayedbag_size());
	for(int32_t i = 0; i < (int32_t)delayedBag.GetSize(); ++i) {
		const ::proto_ff::BuffBagInfo & temp_delayedbag = msg.delayedbag(i);
		delayedBag[i].read_from_pbmsg(temp_delayedbag);
	}
	buffbagLst.SetSize(msg.buffbaglst_size() > buffbagLst.GetMaxSize() ? buffbagLst.GetMaxSize() : msg.buffbaglst_size());
	for(int32_t i = 0; i < (int32_t)buffbagLst.GetSize(); ++i) {
		const ::proto_ff::BuffBagInfo & temp_buffbaglst = msg.buffbaglst(i);
		buffbagLst[i].read_from_pbmsg(temp_buffbaglst);
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
}

void CharacterArenaData_s::read_from_pbmsg(const ::proto_ff::CharacterArenaData & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct CharacterArenaData_s));
	challengeTimes = msg.challengetimes();
	updateTime = msg.updatetime();
	historyRankId = msg.historyrankid();
	buyChallengeTimes = msg.buychallengetimes();
}

CharacterTitleInfo_s::CharacterTitleInfo_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int CharacterTitleInfo_s::CreateInit() {
	id = (uint64_t)0;
	param = (uint32_t)0;
	startTime = (uint64_t)0;
	return 0;
}

int CharacterTitleInfo_s::ResumeInit() {
	return 0;
}

void CharacterTitleInfo_s::write_to_pbmsg(::proto_ff::CharacterTitleInfo & msg) const {
	msg.set_id((uint64_t)id);
	msg.set_param((uint32_t)param);
	msg.set_starttime((uint64_t)startTime);
	msg.set_name((const char*)name.Get());
}

void CharacterTitleInfo_s::read_from_pbmsg(const ::proto_ff::CharacterTitleInfo & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct CharacterTitleInfo_s));
	id = msg.id();
	param = msg.param();
	startTime = msg.starttime();
	name.Copy(msg.name());
}

CharacterTitleSaveData_s::CharacterTitleSaveData_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int CharacterTitleSaveData_s::CreateInit() {
	return 0;
}

int CharacterTitleSaveData_s::ResumeInit() {
	return 0;
}

void CharacterTitleSaveData_s::write_to_pbmsg(::proto_ff::CharacterTitleSaveData & msg) const {
	for(int32_t i = 0; i < (int32_t)titelData.GetSize() && i < titelData.GetMaxSize(); ++i) {
		::proto_ff::CharacterTitleInfo* temp_titeldata = msg.add_titeldata();
		titelData[i].write_to_pbmsg(*temp_titeldata);
	}
}

void CharacterTitleSaveData_s::read_from_pbmsg(const ::proto_ff::CharacterTitleSaveData & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct CharacterTitleSaveData_s));
	titelData.SetSize(msg.titeldata_size() > titelData.GetMaxSize() ? titelData.GetMaxSize() : msg.titeldata_size());
	for(int32_t i = 0; i < (int32_t)titelData.GetSize(); ++i) {
		const ::proto_ff::CharacterTitleInfo & temp_titeldata = msg.titeldata(i);
		titelData[i].read_from_pbmsg(temp_titeldata);
	}
}

CharacterDBSingleOperateLimitInfo_s::CharacterDBSingleOperateLimitInfo_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int CharacterDBSingleOperateLimitInfo_s::CreateInit() {
	type = (uint32_t)0;
	value = (uint32_t)0;
	lastTime = (uint32_t)0;
	return 0;
}

int CharacterDBSingleOperateLimitInfo_s::ResumeInit() {
	return 0;
}

void CharacterDBSingleOperateLimitInfo_s::write_to_pbmsg(::proto_ff::CharacterDBSingleOperateLimitInfo & msg) const {
	msg.set_type((uint32_t)type);
	msg.set_value((uint32_t)value);
	msg.set_lasttime((uint32_t)lastTime);
}

void CharacterDBSingleOperateLimitInfo_s::read_from_pbmsg(const ::proto_ff::CharacterDBSingleOperateLimitInfo & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct CharacterDBSingleOperateLimitInfo_s));
	type = msg.type();
	value = msg.value();
	lastTime = msg.lasttime();
}

CharacterDBOperateProto_s::CharacterDBOperateProto_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int CharacterDBOperateProto_s::CreateInit() {
	id = (uint32_t)0;
	num = (uint64_t)0;
	return 0;
}

int CharacterDBOperateProto_s::ResumeInit() {
	return 0;
}

void CharacterDBOperateProto_s::write_to_pbmsg(::proto_ff::CharacterDBOperateProto & msg) const {
	msg.set_id((uint32_t)id);
	msg.set_num((uint64_t)num);
}

void CharacterDBOperateProto_s::read_from_pbmsg(const ::proto_ff::CharacterDBOperateProto & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct CharacterDBOperateProto_s));
	id = msg.id();
	num = msg.num();
}

CharacterDBOperateMutProto_s::CharacterDBOperateMutProto_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int CharacterDBOperateMutProto_s::CreateInit() {
	return 0;
}

int CharacterDBOperateMutProto_s::ResumeInit() {
	return 0;
}

void CharacterDBOperateMutProto_s::write_to_pbmsg(::proto_ff::CharacterDBOperateMutProto & msg) const {
	for(int32_t i = 0; i < (int32_t)operate_lst.GetSize() && i < operate_lst.GetMaxSize(); ++i) {
		::proto_ff::CharacterDBOperateProto* temp_operate_lst = msg.add_operate_lst();
		operate_lst[i].write_to_pbmsg(*temp_operate_lst);
	}
}

void CharacterDBOperateMutProto_s::read_from_pbmsg(const ::proto_ff::CharacterDBOperateMutProto & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct CharacterDBOperateMutProto_s));
	operate_lst.SetSize(msg.operate_lst_size() > operate_lst.GetMaxSize() ? operate_lst.GetMaxSize() : msg.operate_lst_size());
	for(int32_t i = 0; i < (int32_t)operate_lst.GetSize(); ++i) {
		const ::proto_ff::CharacterDBOperateProto & temp_operate_lst = msg.operate_lst(i);
		operate_lst[i].read_from_pbmsg(temp_operate_lst);
	}
}

CharacterDBOperateInfo_s::CharacterDBOperateInfo_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int CharacterDBOperateInfo_s::CreateInit() {
	make_gold_quip = (uint64_t)0;
	identify = (uint64_t)0;
	arena_success = (uint64_t)0;
	die = (uint64_t)0;
	kill_enemy = (uint64_t)0;
	kill_enemy_camp = (uint64_t)0;
	charge = (uint64_t)0;
	gold = (uint64_t)0;
	treasure = (uint64_t)0;
	pandos_trans = (uint64_t)0;
	world_chat = (uint64_t)0;
	refine_success = (uint64_t)0;
	refine_fail = (uint64_t)0;
	return 0;
}

int CharacterDBOperateInfo_s::ResumeInit() {
	return 0;
}

void CharacterDBOperateInfo_s::write_to_pbmsg(::proto_ff::CharacterDBOperateInfo & msg) const {
	::proto_ff::CharacterDBOperateMutProto* temp_kill_mons = msg.mutable_kill_mons();
	kill_mons.write_to_pbmsg(*temp_kill_mons);
	::proto_ff::CharacterDBOperateMutProto* temp_last_kill_mons = msg.mutable_last_kill_mons();
	last_kill_mons.write_to_pbmsg(*temp_last_kill_mons);
	::proto_ff::CharacterDBOperateMutProto* temp_attend_act = msg.mutable_attend_act();
	attend_act.write_to_pbmsg(*temp_attend_act);
	::proto_ff::CharacterDBOperateMutProto* temp_last_attend_act = msg.mutable_last_attend_act();
	last_attend_act.write_to_pbmsg(*temp_last_attend_act);
	::proto_ff::CharacterDBOperateMutProto* temp_finish_act = msg.mutable_finish_act();
	finish_act.write_to_pbmsg(*temp_finish_act);
	::proto_ff::CharacterDBOperateMutProto* temp_pass_dup = msg.mutable_pass_dup();
	pass_dup.write_to_pbmsg(*temp_pass_dup);
	::proto_ff::CharacterDBOperateMutProto* temp_coll_action = msg.mutable_coll_action();
	coll_action.write_to_pbmsg(*temp_coll_action);
	::proto_ff::CharacterDBOperateMutProto* temp_make_action = msg.mutable_make_action();
	make_action.write_to_pbmsg(*temp_make_action);
	::proto_ff::CharacterDBOperateMutProto* temp_collect = msg.mutable_collect();
	collect.write_to_pbmsg(*temp_collect);
	::proto_ff::CharacterDBOperateMutProto* temp_make = msg.mutable_make();
	make.write_to_pbmsg(*temp_make);
	msg.set_make_gold_quip((uint64_t)make_gold_quip);
	msg.set_identify((uint64_t)identify);
	msg.set_arena_success((uint64_t)arena_success);
	msg.set_die((uint64_t)die);
	msg.set_kill_enemy((uint64_t)kill_enemy);
	msg.set_kill_enemy_camp((uint64_t)kill_enemy_camp);
	msg.set_charge((uint64_t)charge);
	msg.set_gold((uint64_t)gold);
	msg.set_treasure((uint64_t)treasure);
	msg.set_pandos_trans((uint64_t)pandos_trans);
	msg.set_world_chat((uint64_t)world_chat);
	msg.set_refine_success((uint64_t)refine_success);
	msg.set_refine_fail((uint64_t)refine_fail);
}

void CharacterDBOperateInfo_s::read_from_pbmsg(const ::proto_ff::CharacterDBOperateInfo & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct CharacterDBOperateInfo_s));
	const ::proto_ff::CharacterDBOperateMutProto & temp_kill_mons = msg.kill_mons();
	kill_mons.read_from_pbmsg(temp_kill_mons);
	const ::proto_ff::CharacterDBOperateMutProto & temp_last_kill_mons = msg.last_kill_mons();
	last_kill_mons.read_from_pbmsg(temp_last_kill_mons);
	const ::proto_ff::CharacterDBOperateMutProto & temp_attend_act = msg.attend_act();
	attend_act.read_from_pbmsg(temp_attend_act);
	const ::proto_ff::CharacterDBOperateMutProto & temp_last_attend_act = msg.last_attend_act();
	last_attend_act.read_from_pbmsg(temp_last_attend_act);
	const ::proto_ff::CharacterDBOperateMutProto & temp_finish_act = msg.finish_act();
	finish_act.read_from_pbmsg(temp_finish_act);
	const ::proto_ff::CharacterDBOperateMutProto & temp_pass_dup = msg.pass_dup();
	pass_dup.read_from_pbmsg(temp_pass_dup);
	const ::proto_ff::CharacterDBOperateMutProto & temp_coll_action = msg.coll_action();
	coll_action.read_from_pbmsg(temp_coll_action);
	const ::proto_ff::CharacterDBOperateMutProto & temp_make_action = msg.make_action();
	make_action.read_from_pbmsg(temp_make_action);
	const ::proto_ff::CharacterDBOperateMutProto & temp_collect = msg.collect();
	collect.read_from_pbmsg(temp_collect);
	const ::proto_ff::CharacterDBOperateMutProto & temp_make = msg.make();
	make.read_from_pbmsg(temp_make);
	make_gold_quip = msg.make_gold_quip();
	identify = msg.identify();
	arena_success = msg.arena_success();
	die = msg.die();
	kill_enemy = msg.kill_enemy();
	kill_enemy_camp = msg.kill_enemy_camp();
	charge = msg.charge();
	gold = msg.gold();
	treasure = msg.treasure();
	pandos_trans = msg.pandos_trans();
	world_chat = msg.world_chat();
	refine_success = msg.refine_success();
	refine_fail = msg.refine_fail();
}

CharacterDBOperateLimitInfo_s::CharacterDBOperateLimitInfo_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int CharacterDBOperateLimitInfo_s::CreateInit() {
	return 0;
}

int CharacterDBOperateLimitInfo_s::ResumeInit() {
	return 0;
}

void CharacterDBOperateLimitInfo_s::write_to_pbmsg(::proto_ff::CharacterDBOperateLimitInfo & msg) const {
	for(int32_t i = 0; i < (int32_t)operateLimitInfo.GetSize() && i < operateLimitInfo.GetMaxSize(); ++i) {
		::proto_ff::CharacterDBSingleOperateLimitInfo* temp_operatelimitinfo = msg.add_operatelimitinfo();
		operateLimitInfo[i].write_to_pbmsg(*temp_operatelimitinfo);
	}
	::proto_ff::CharacterDBOperateInfo* temp_operate_data = msg.mutable_operate_data();
	operate_data.write_to_pbmsg(*temp_operate_data);
}

void CharacterDBOperateLimitInfo_s::read_from_pbmsg(const ::proto_ff::CharacterDBOperateLimitInfo & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct CharacterDBOperateLimitInfo_s));
	operateLimitInfo.SetSize(msg.operatelimitinfo_size() > operateLimitInfo.GetMaxSize() ? operateLimitInfo.GetMaxSize() : msg.operatelimitinfo_size());
	for(int32_t i = 0; i < (int32_t)operateLimitInfo.GetSize(); ++i) {
		const ::proto_ff::CharacterDBSingleOperateLimitInfo & temp_operatelimitinfo = msg.operatelimitinfo(i);
		operateLimitInfo[i].read_from_pbmsg(temp_operatelimitinfo);
	}
	const ::proto_ff::CharacterDBOperateInfo & temp_operate_data = msg.operate_data();
	operate_data.read_from_pbmsg(temp_operate_data);
}

CharacterDBSingleHuoYueDuInfoInfo_s::CharacterDBSingleHuoYueDuInfoInfo_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int CharacterDBSingleHuoYueDuInfoInfo_s::CreateInit() {
	type = (uint32_t)0;
	value = (uint32_t)0;
	time = (uint32_t)0;
	sin_process = (uint32_t)0;
	return 0;
}

int CharacterDBSingleHuoYueDuInfoInfo_s::ResumeInit() {
	return 0;
}

void CharacterDBSingleHuoYueDuInfoInfo_s::write_to_pbmsg(::proto_ff::CharacterDBSingleHuoYueDuInfoInfo & msg) const {
	msg.set_type((uint32_t)type);
	msg.set_value((uint32_t)value);
	msg.set_time((uint32_t)time);
	msg.set_sin_process((uint32_t)sin_process);
}

void CharacterDBSingleHuoYueDuInfoInfo_s::read_from_pbmsg(const ::proto_ff::CharacterDBSingleHuoYueDuInfoInfo & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct CharacterDBSingleHuoYueDuInfoInfo_s));
	type = msg.type();
	value = msg.value();
	time = msg.time();
	sin_process = msg.sin_process();
}

CharacterDBHuoYueDuInfo_s::CharacterDBHuoYueDuInfo_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int CharacterDBHuoYueDuInfo_s::CreateInit() {
	return 0;
}

int CharacterDBHuoYueDuInfo_s::ResumeInit() {
	return 0;
}

void CharacterDBHuoYueDuInfo_s::write_to_pbmsg(::proto_ff::CharacterDBHuoYueDuInfo & msg) const {
	for(int32_t i = 0; i < (int32_t)huoYueDuInfo.GetSize() && i < huoYueDuInfo.GetMaxSize(); ++i) {
		::proto_ff::CharacterDBSingleHuoYueDuInfoInfo* temp_huoyueduinfo = msg.add_huoyueduinfo();
		huoYueDuInfo[i].write_to_pbmsg(*temp_huoyueduinfo);
	}
}

void CharacterDBHuoYueDuInfo_s::read_from_pbmsg(const ::proto_ff::CharacterDBHuoYueDuInfo & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct CharacterDBHuoYueDuInfo_s));
	huoYueDuInfo.SetSize(msg.huoyueduinfo_size() > huoYueDuInfo.GetMaxSize() ? huoYueDuInfo.GetMaxSize() : msg.huoyueduinfo_size());
	for(int32_t i = 0; i < (int32_t)huoYueDuInfo.GetSize(); ++i) {
		const ::proto_ff::CharacterDBSingleHuoYueDuInfoInfo & temp_huoyueduinfo = msg.huoyueduinfo(i);
		huoYueDuInfo[i].read_from_pbmsg(temp_huoyueduinfo);
	}
}

IndultTaskEntry_s::IndultTaskEntry_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int IndultTaskEntry_s::CreateInit() {
	task_cfg_id = (uint64_t)0;
	cur_num = (int32_t)0;
	task_state = (int32_t)0;
	return 0;
}

int IndultTaskEntry_s::ResumeInit() {
	return 0;
}

void IndultTaskEntry_s::write_to_pbmsg(::proto_ff::IndultTaskEntry & msg) const {
	msg.set_task_cfg_id((uint64_t)task_cfg_id);
	msg.set_cur_num((int32_t)cur_num);
	msg.set_task_state((int32_t)task_state);
}

void IndultTaskEntry_s::read_from_pbmsg(const ::proto_ff::IndultTaskEntry & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct IndultTaskEntry_s));
	task_cfg_id = msg.task_cfg_id();
	cur_num = msg.cur_num();
	task_state = msg.task_state();
}

IndultTaskGroupEntry_s::IndultTaskGroupEntry_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int IndultTaskGroupEntry_s::CreateInit() {
	group_cfg_id = (uint64_t)0;
	normal_reward_state = (int32_t)0;
	return 0;
}

int IndultTaskGroupEntry_s::ResumeInit() {
	return 0;
}

void IndultTaskGroupEntry_s::write_to_pbmsg(::proto_ff::IndultTaskGroupEntry & msg) const {
	msg.set_group_cfg_id((uint64_t)group_cfg_id);
	for(int32_t i = 0; i < (int32_t)entrys.GetSize() && i < entrys.GetMaxSize(); ++i) {
		::proto_ff::IndultTaskEntry* temp_entrys = msg.add_entrys();
		entrys[i].write_to_pbmsg(*temp_entrys);
	}
	msg.set_normal_reward_state((int32_t)normal_reward_state);
}

void IndultTaskGroupEntry_s::read_from_pbmsg(const ::proto_ff::IndultTaskGroupEntry & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct IndultTaskGroupEntry_s));
	group_cfg_id = msg.group_cfg_id();
	entrys.SetSize(msg.entrys_size() > entrys.GetMaxSize() ? entrys.GetMaxSize() : msg.entrys_size());
	for(int32_t i = 0; i < (int32_t)entrys.GetSize(); ++i) {
		const ::proto_ff::IndultTaskEntry & temp_entrys = msg.entrys(i);
		entrys[i].read_from_pbmsg(temp_entrys);
	}
	normal_reward_state = msg.normal_reward_state();
}

ColPointsTaskEntry_s::ColPointsTaskEntry_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int ColPointsTaskEntry_s::CreateInit() {
	task_cfg_id = (uint64_t)0;
	cur_num = (int32_t)0;
	task_state = (int32_t)0;
	return 0;
}

int ColPointsTaskEntry_s::ResumeInit() {
	return 0;
}

void ColPointsTaskEntry_s::write_to_pbmsg(::proto_ff::ColPointsTaskEntry & msg) const {
	msg.set_task_cfg_id((uint64_t)task_cfg_id);
	msg.set_cur_num((int32_t)cur_num);
	msg.set_task_state((int32_t)task_state);
}

void ColPointsTaskEntry_s::read_from_pbmsg(const ::proto_ff::ColPointsTaskEntry & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct ColPointsTaskEntry_s));
	task_cfg_id = msg.task_cfg_id();
	cur_num = msg.cur_num();
	task_state = msg.task_state();
}

ColPointsTaskGroupEntry_s::ColPointsTaskGroupEntry_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int ColPointsTaskGroupEntry_s::CreateInit() {
	group_cfg_id = (uint64_t)0;
	normal_reward_state = (int32_t)0;
	cur_points = (int32_t)0;
	create_time = (uint64_t)0;
	return 0;
}

int ColPointsTaskGroupEntry_s::ResumeInit() {
	return 0;
}

void ColPointsTaskGroupEntry_s::write_to_pbmsg(::proto_ff::ColPointsTaskGroupEntry & msg) const {
	msg.set_group_cfg_id((uint64_t)group_cfg_id);
	for(int32_t i = 0; i < (int32_t)entrys.GetSize() && i < entrys.GetMaxSize(); ++i) {
		::proto_ff::ColPointsTaskEntry* temp_entrys = msg.add_entrys();
		entrys[i].write_to_pbmsg(*temp_entrys);
	}
	msg.set_normal_reward_state((int32_t)normal_reward_state);
	msg.set_cur_points((int32_t)cur_points);
	msg.set_create_time((uint64_t)create_time);
}

void ColPointsTaskGroupEntry_s::read_from_pbmsg(const ::proto_ff::ColPointsTaskGroupEntry & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct ColPointsTaskGroupEntry_s));
	group_cfg_id = msg.group_cfg_id();
	entrys.SetSize(msg.entrys_size() > entrys.GetMaxSize() ? entrys.GetMaxSize() : msg.entrys_size());
	for(int32_t i = 0; i < (int32_t)entrys.GetSize(); ++i) {
		const ::proto_ff::ColPointsTaskEntry & temp_entrys = msg.entrys(i);
		entrys[i].read_from_pbmsg(temp_entrys);
	}
	normal_reward_state = msg.normal_reward_state();
	cur_points = msg.cur_points();
	create_time = msg.create_time();
}

ColPointsTaskData_s::ColPointsTaskData_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int ColPointsTaskData_s::CreateInit() {
	last_refresh_time = (uint64_t)0;
	online_time = (uint64_t)0;
	return 0;
}

int ColPointsTaskData_s::ResumeInit() {
	return 0;
}

void ColPointsTaskData_s::write_to_pbmsg(::proto_ff::ColPointsTaskData & msg) const {
	::proto_ff::ColPointsTaskGroupEntry* temp_data = msg.mutable_data();
	data.write_to_pbmsg(*temp_data);
	msg.set_last_refresh_time((uint64_t)last_refresh_time);
	msg.set_online_time((uint64_t)online_time);
}

void ColPointsTaskData_s::read_from_pbmsg(const ::proto_ff::ColPointsTaskData & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct ColPointsTaskData_s));
	const ::proto_ff::ColPointsTaskGroupEntry & temp_data = msg.data();
	data.read_from_pbmsg(temp_data);
	last_refresh_time = msg.last_refresh_time();
	online_time = msg.online_time();
}

WelfareDailySignInDBData_s::WelfareDailySignInDBData_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int WelfareDailySignInDBData_s::CreateInit() {
	id = (uint64_t)0;
	dayIndex = (uint32_t)0;
	nState = (uint32_t)0;
	lastResetTime = (uint64_t)0;
	bRecharge = (bool)0;
	return 0;
}

int WelfareDailySignInDBData_s::ResumeInit() {
	return 0;
}

void WelfareDailySignInDBData_s::write_to_pbmsg(::proto_ff::WelfareDailySignInDBData & msg) const {
	msg.set_id((uint64_t)id);
	msg.set_dayindex((uint32_t)dayIndex);
	msg.set_nstate((uint32_t)nState);
	msg.set_lastresettime((uint64_t)lastResetTime);
	msg.set_brecharge((bool)bRecharge);
}

void WelfareDailySignInDBData_s::read_from_pbmsg(const ::proto_ff::WelfareDailySignInDBData & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct WelfareDailySignInDBData_s));
	id = msg.id();
	dayIndex = msg.dayindex();
	nState = msg.nstate();
	lastResetTime = msg.lastresettime();
	bRecharge = msg.brecharge();
}

WelfareLoginGiftDBData_s::WelfareLoginGiftDBData_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int WelfareLoginGiftDBData_s::CreateInit() {
	id = (uint64_t)0;
	LoninCount = (uint32_t)0;
	lastResetTime = (uint64_t)0;
	nState = (uint32_t)0;
	return 0;
}

int WelfareLoginGiftDBData_s::ResumeInit() {
	return 0;
}

void WelfareLoginGiftDBData_s::write_to_pbmsg(::proto_ff::WelfareLoginGiftDBData & msg) const {
	msg.set_id((uint64_t)id);
	msg.set_lonincount((uint32_t)LoninCount);
	msg.set_lastresettime((uint64_t)lastResetTime);
	for(int32_t i = 0; i < (int32_t)getState.GetSize() && i < getState.GetMaxSize(); ++i) {
		::proto_ff::ComPair* temp_getstate = msg.add_getstate();
		getState[i].write_to_pbmsg(*temp_getstate);
	}
	msg.set_nstate((uint32_t)nState);
}

void WelfareLoginGiftDBData_s::read_from_pbmsg(const ::proto_ff::WelfareLoginGiftDBData & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct WelfareLoginGiftDBData_s));
	id = msg.id();
	LoninCount = msg.lonincount();
	lastResetTime = msg.lastresettime();
	getState.SetSize(msg.getstate_size() > getState.GetMaxSize() ? getState.GetMaxSize() : msg.getstate_size());
	for(int32_t i = 0; i < (int32_t)getState.GetSize(); ++i) {
		const ::proto_ff::ComPair & temp_getstate = msg.getstate(i);
		getState[i].read_from_pbmsg(temp_getstate);
	}
	nState = msg.nstate();
}

WelfareLevelGiftDBData_s::WelfareLevelGiftDBData_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int WelfareLevelGiftDBData_s::CreateInit() {
	id = (uint64_t)0;
	return 0;
}

int WelfareLevelGiftDBData_s::ResumeInit() {
	return 0;
}

void WelfareLevelGiftDBData_s::write_to_pbmsg(::proto_ff::WelfareLevelGiftDBData & msg) const {
	msg.set_id((uint64_t)id);
	for(int32_t i = 0; i < (int32_t)getState.GetSize() && i < getState.GetMaxSize(); ++i) {
		::proto_ff::ComPair* temp_getstate = msg.add_getstate();
		getState[i].write_to_pbmsg(*temp_getstate);
	}
}

void WelfareLevelGiftDBData_s::read_from_pbmsg(const ::proto_ff::WelfareLevelGiftDBData & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct WelfareLevelGiftDBData_s));
	id = msg.id();
	getState.SetSize(msg.getstate_size() > getState.GetMaxSize() ? getState.GetMaxSize() : msg.getstate_size());
	for(int32_t i = 0; i < (int32_t)getState.GetSize(); ++i) {
		const ::proto_ff::ComPair & temp_getstate = msg.getstate(i);
		getState[i].read_from_pbmsg(temp_getstate);
	}
}

CommodityEntry_s::CommodityEntry_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int CommodityEntry_s::CreateInit() {
	commodity_id = (uint64_t)0;
	cur_buy_num = (int32_t)0;
	return 0;
}

int CommodityEntry_s::ResumeInit() {
	return 0;
}

void CommodityEntry_s::write_to_pbmsg(::proto_ff::CommodityEntry & msg) const {
	msg.set_commodity_id((uint64_t)commodity_id);
	msg.set_cur_buy_num((int32_t)cur_buy_num);
}

void CommodityEntry_s::read_from_pbmsg(const ::proto_ff::CommodityEntry & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct CommodityEntry_s));
	commodity_id = msg.commodity_id();
	cur_buy_num = msg.cur_buy_num();
}

LimitShopGroupEntry_s::LimitShopGroupEntry_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int LimitShopGroupEntry_s::CreateInit() {
	group_cfg_id = (uint64_t)0;
	open_time = (int32_t)0;
	return 0;
}

int LimitShopGroupEntry_s::ResumeInit() {
	return 0;
}

void LimitShopGroupEntry_s::write_to_pbmsg(::proto_ff::LimitShopGroupEntry & msg) const {
	msg.set_group_cfg_id((uint64_t)group_cfg_id);
	msg.set_open_time((int32_t)open_time);
	for(int32_t i = 0; i < (int32_t)entrys.GetSize() && i < entrys.GetMaxSize(); ++i) {
		::proto_ff::CommodityEntry* temp_entrys = msg.add_entrys();
		entrys[i].write_to_pbmsg(*temp_entrys);
	}
}

void LimitShopGroupEntry_s::read_from_pbmsg(const ::proto_ff::LimitShopGroupEntry & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct LimitShopGroupEntry_s));
	group_cfg_id = msg.group_cfg_id();
	open_time = msg.open_time();
	entrys.SetSize(msg.entrys_size() > entrys.GetMaxSize() ? entrys.GetMaxSize() : msg.entrys_size());
	for(int32_t i = 0; i < (int32_t)entrys.GetSize(); ++i) {
		const ::proto_ff::CommodityEntry & temp_entrys = msg.entrys(i);
		entrys[i].read_from_pbmsg(temp_entrys);
	}
}

LimitShopData_s::LimitShopData_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int LimitShopData_s::CreateInit() {
	id = (uint64_t)0;
	return 0;
}

int LimitShopData_s::ResumeInit() {
	return 0;
}

void LimitShopData_s::write_to_pbmsg(::proto_ff::LimitShopData & msg) const {
	msg.set_id((uint64_t)id);
	for(int32_t i = 0; i < (int32_t)groups.GetSize() && i < groups.GetMaxSize(); ++i) {
		::proto_ff::LimitShopGroupEntry* temp_groups = msg.add_groups();
		groups[i].write_to_pbmsg(*temp_groups);
	}
}

void LimitShopData_s::read_from_pbmsg(const ::proto_ff::LimitShopData & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct LimitShopData_s));
	id = msg.id();
	groups.SetSize(msg.groups_size() > groups.GetMaxSize() ? groups.GetMaxSize() : msg.groups_size());
	for(int32_t i = 0; i < (int32_t)groups.GetSize(); ++i) {
		const ::proto_ff::LimitShopGroupEntry & temp_groups = msg.groups(i);
		groups[i].read_from_pbmsg(temp_groups);
	}
}

LimitTaskEntry_s::LimitTaskEntry_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int LimitTaskEntry_s::CreateInit() {
	task_cfg_id = (uint64_t)0;
	cur_num = (int32_t)0;
	task_state = (int32_t)0;
	return 0;
}

int LimitTaskEntry_s::ResumeInit() {
	return 0;
}

void LimitTaskEntry_s::write_to_pbmsg(::proto_ff::LimitTaskEntry & msg) const {
	msg.set_task_cfg_id((uint64_t)task_cfg_id);
	msg.set_cur_num((int32_t)cur_num);
	msg.set_task_state((int32_t)task_state);
}

void LimitTaskEntry_s::read_from_pbmsg(const ::proto_ff::LimitTaskEntry & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct LimitTaskEntry_s));
	task_cfg_id = msg.task_cfg_id();
	cur_num = msg.cur_num();
	task_state = msg.task_state();
}

LimitTaskGroupEntry_s::LimitTaskGroupEntry_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int LimitTaskGroupEntry_s::CreateInit() {
	group_cfg_id = (uint64_t)0;
	open_time = (int32_t)0;
	normal_reward_state = (int32_t)0;
	senior_reward_state = (int32_t)0;
	return 0;
}

int LimitTaskGroupEntry_s::ResumeInit() {
	return 0;
}

void LimitTaskGroupEntry_s::write_to_pbmsg(::proto_ff::LimitTaskGroupEntry & msg) const {
	msg.set_group_cfg_id((uint64_t)group_cfg_id);
	msg.set_open_time((int32_t)open_time);
	for(int32_t i = 0; i < (int32_t)entrys.GetSize() && i < entrys.GetMaxSize(); ++i) {
		::proto_ff::LimitTaskEntry* temp_entrys = msg.add_entrys();
		entrys[i].write_to_pbmsg(*temp_entrys);
	}
	msg.set_normal_reward_state((int32_t)normal_reward_state);
	msg.set_senior_reward_state((int32_t)senior_reward_state);
}

void LimitTaskGroupEntry_s::read_from_pbmsg(const ::proto_ff::LimitTaskGroupEntry & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct LimitTaskGroupEntry_s));
	group_cfg_id = msg.group_cfg_id();
	open_time = msg.open_time();
	entrys.SetSize(msg.entrys_size() > entrys.GetMaxSize() ? entrys.GetMaxSize() : msg.entrys_size());
	for(int32_t i = 0; i < (int32_t)entrys.GetSize(); ++i) {
		const ::proto_ff::LimitTaskEntry & temp_entrys = msg.entrys(i);
		entrys[i].read_from_pbmsg(temp_entrys);
	}
	normal_reward_state = msg.normal_reward_state();
	senior_reward_state = msg.senior_reward_state();
}

LimitTaskData_s::LimitTaskData_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int LimitTaskData_s::CreateInit() {
	id = (uint64_t)0;
	return 0;
}

int LimitTaskData_s::ResumeInit() {
	return 0;
}

void LimitTaskData_s::write_to_pbmsg(::proto_ff::LimitTaskData & msg) const {
	msg.set_id((uint64_t)id);
	for(int32_t i = 0; i < (int32_t)groups.GetSize() && i < groups.GetMaxSize(); ++i) {
		::proto_ff::LimitTaskGroupEntry* temp_groups = msg.add_groups();
		groups[i].write_to_pbmsg(*temp_groups);
	}
}

void LimitTaskData_s::read_from_pbmsg(const ::proto_ff::LimitTaskData & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct LimitTaskData_s));
	id = msg.id();
	groups.SetSize(msg.groups_size() > groups.GetMaxSize() ? groups.GetMaxSize() : msg.groups_size());
	for(int32_t i = 0; i < (int32_t)groups.GetSize(); ++i) {
		const ::proto_ff::LimitTaskGroupEntry & temp_groups = msg.groups(i);
		groups[i].read_from_pbmsg(temp_groups);
	}
}

WishDBTypeEntry_s::WishDBTypeEntry_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int WishDBTypeEntry_s::CreateInit() {
	wish_type = (int32_t)0;
	wished_num = (int32_t)0;
	refresh_time = (uint64_t)0;
	last_time = (uint64_t)0;
	return 0;
}

int WishDBTypeEntry_s::ResumeInit() {
	return 0;
}

void WishDBTypeEntry_s::write_to_pbmsg(::proto_ff::WishDBTypeEntry & msg) const {
	msg.set_wish_type((int32_t)wish_type);
	msg.set_wished_num((int32_t)wished_num);
	msg.set_refresh_time((uint64_t)refresh_time);
	msg.set_last_time((uint64_t)last_time);
}

void WishDBTypeEntry_s::read_from_pbmsg(const ::proto_ff::WishDBTypeEntry & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct WishDBTypeEntry_s));
	wish_type = msg.wish_type();
	wished_num = msg.wished_num();
	refresh_time = msg.refresh_time();
	last_time = msg.last_time();
}

WishDBData_s::WishDBData_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int WishDBData_s::CreateInit() {
	id = (uint64_t)0;
	return 0;
}

int WishDBData_s::ResumeInit() {
	return 0;
}

void WishDBData_s::write_to_pbmsg(::proto_ff::WishDBData & msg) const {
	msg.set_id((uint64_t)id);
	for(int32_t i = 0; i < (int32_t)type_entry.GetSize() && i < type_entry.GetMaxSize(); ++i) {
		::proto_ff::WishDBTypeEntry* temp_type_entry = msg.add_type_entry();
		type_entry[i].write_to_pbmsg(*temp_type_entry);
	}
}

void WishDBData_s::read_from_pbmsg(const ::proto_ff::WishDBData & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct WishDBData_s));
	id = msg.id();
	type_entry.SetSize(msg.type_entry_size() > type_entry.GetMaxSize() ? type_entry.GetMaxSize() : msg.type_entry_size());
	for(int32_t i = 0; i < (int32_t)type_entry.GetSize(); ++i) {
		const ::proto_ff::WishDBTypeEntry & temp_type_entry = msg.type_entry(i);
		type_entry[i].read_from_pbmsg(temp_type_entry);
	}
}

FestivalInvestDBData_s::FestivalInvestDBData_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int FestivalInvestDBData_s::CreateInit() {
	nActiveId = (uint64_t)0;
	bInvest = (bool)0;
	nLastResetTime = (uint64_t)0;
	nLoninCount = (int32_t)0;
	investTime = (int64_t)0;
	return 0;
}

int FestivalInvestDBData_s::ResumeInit() {
	return 0;
}

void FestivalInvestDBData_s::write_to_pbmsg(::proto_ff::FestivalInvestDBData & msg) const {
	msg.set_nactiveid((uint64_t)nActiveId);
	msg.set_binvest((bool)bInvest);
	msg.set_nlastresettime((uint64_t)nLastResetTime);
	msg.set_nlonincount((int32_t)nLoninCount);
	for(int32_t i = 0; i < (int32_t)getState.GetSize() && i < getState.GetMaxSize(); ++i) {
		::proto_ff::ComPair* temp_getstate = msg.add_getstate();
		getState[i].write_to_pbmsg(*temp_getstate);
	}
	for(int32_t i = 0; i < (int32_t)params.GetSize() && i < params.GetMaxSize(); ++i) {
		::proto_ff::ComPair* temp_params = msg.add_params();
		params[i].write_to_pbmsg(*temp_params);
	}
	msg.set_investtime((int64_t)investTime);
}

void FestivalInvestDBData_s::read_from_pbmsg(const ::proto_ff::FestivalInvestDBData & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct FestivalInvestDBData_s));
	nActiveId = msg.nactiveid();
	bInvest = msg.binvest();
	nLastResetTime = msg.nlastresettime();
	nLoninCount = msg.nlonincount();
	getState.SetSize(msg.getstate_size() > getState.GetMaxSize() ? getState.GetMaxSize() : msg.getstate_size());
	for(int32_t i = 0; i < (int32_t)getState.GetSize(); ++i) {
		const ::proto_ff::ComPair & temp_getstate = msg.getstate(i);
		getState[i].read_from_pbmsg(temp_getstate);
	}
	params.SetSize(msg.params_size() > params.GetMaxSize() ? params.GetMaxSize() : msg.params_size());
	for(int32_t i = 0; i < (int32_t)params.GetSize(); ++i) {
		const ::proto_ff::ComPair & temp_params = msg.params(i);
		params[i].read_from_pbmsg(temp_params);
	}
	investTime = msg.investtime();
}

FestivalExchangeDBData_s::FestivalExchangeDBData_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int FestivalExchangeDBData_s::CreateInit() {
	nActiveId = (uint64_t)0;
	return 0;
}

int FestivalExchangeDBData_s::ResumeInit() {
	return 0;
}

void FestivalExchangeDBData_s::write_to_pbmsg(::proto_ff::FestivalExchangeDBData & msg) const {
	msg.set_nactiveid((uint64_t)nActiveId);
	for(int32_t i = 0; i < (int32_t)exchangeCount.GetSize() && i < exchangeCount.GetMaxSize(); ++i) {
		::proto_ff::ComPair* temp_exchangecount = msg.add_exchangecount();
		exchangeCount[i].write_to_pbmsg(*temp_exchangecount);
	}
}

void FestivalExchangeDBData_s::read_from_pbmsg(const ::proto_ff::FestivalExchangeDBData & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct FestivalExchangeDBData_s));
	nActiveId = msg.nactiveid();
	exchangeCount.SetSize(msg.exchangecount_size() > exchangeCount.GetMaxSize() ? exchangeCount.GetMaxSize() : msg.exchangecount_size());
	for(int32_t i = 0; i < (int32_t)exchangeCount.GetSize(); ++i) {
		const ::proto_ff::ComPair & temp_exchangecount = msg.exchangecount(i);
		exchangeCount[i].read_from_pbmsg(temp_exchangecount);
	}
}

FestivalLoginDBData_s::FestivalLoginDBData_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int FestivalLoginDBData_s::CreateInit() {
	activeId = (uint64_t)0;
	nLastResetTime = (uint64_t)0;
	nLoninCount = (uint32_t)0;
	return 0;
}

int FestivalLoginDBData_s::ResumeInit() {
	return 0;
}

void FestivalLoginDBData_s::write_to_pbmsg(::proto_ff::FestivalLoginDBData & msg) const {
	msg.set_activeid((uint64_t)activeId);
	msg.set_nlastresettime((uint64_t)nLastResetTime);
	msg.set_nlonincount((uint32_t)nLoninCount);
	for(int32_t i = 0; i < (int32_t)getState.GetSize() && i < getState.GetMaxSize(); ++i) {
		::proto_ff::ComPair* temp_getstate = msg.add_getstate();
		getState[i].write_to_pbmsg(*temp_getstate);
	}
}

void FestivalLoginDBData_s::read_from_pbmsg(const ::proto_ff::FestivalLoginDBData & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct FestivalLoginDBData_s));
	activeId = msg.activeid();
	nLastResetTime = msg.nlastresettime();
	nLoninCount = msg.nlonincount();
	getState.SetSize(msg.getstate_size() > getState.GetMaxSize() ? getState.GetMaxSize() : msg.getstate_size());
	for(int32_t i = 0; i < (int32_t)getState.GetSize(); ++i) {
		const ::proto_ff::ComPair & temp_getstate = msg.getstate(i);
		getState[i].read_from_pbmsg(temp_getstate);
	}
}

FestivalTotalRechargeDBData_s::FestivalTotalRechargeDBData_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int FestivalTotalRechargeDBData_s::CreateInit() {
	activeId = (uint64_t)0;
	nRechargeCount = (uint32_t)0;
	nRechargeHoly = (uint32_t)0;
	return 0;
}

int FestivalTotalRechargeDBData_s::ResumeInit() {
	return 0;
}

void FestivalTotalRechargeDBData_s::write_to_pbmsg(::proto_ff::FestivalTotalRechargeDBData & msg) const {
	msg.set_activeid((uint64_t)activeId);
	msg.set_nrechargecount((uint32_t)nRechargeCount);
	for(int32_t i = 0; i < (int32_t)getState.GetSize() && i < getState.GetMaxSize(); ++i) {
		::proto_ff::ComPair* temp_getstate = msg.add_getstate();
		getState[i].write_to_pbmsg(*temp_getstate);
	}
	msg.set_nrechargeholy((uint32_t)nRechargeHoly);
}

void FestivalTotalRechargeDBData_s::read_from_pbmsg(const ::proto_ff::FestivalTotalRechargeDBData & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct FestivalTotalRechargeDBData_s));
	activeId = msg.activeid();
	nRechargeCount = msg.nrechargecount();
	getState.SetSize(msg.getstate_size() > getState.GetMaxSize() ? getState.GetMaxSize() : msg.getstate_size());
	for(int32_t i = 0; i < (int32_t)getState.GetSize(); ++i) {
		const ::proto_ff::ComPair & temp_getstate = msg.getstate(i);
		getState[i].read_from_pbmsg(temp_getstate);
	}
	nRechargeHoly = msg.nrechargeholy();
}

FestivalConsumptionDBData_s::FestivalConsumptionDBData_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int FestivalConsumptionDBData_s::CreateInit() {
	activeId = (uint64_t)0;
	nConsumptionValue = (uint32_t)0;
	nConsumptionHoly = (uint32_t)0;
	nConsumptionVoucher = (uint32_t)0;
	return 0;
}

int FestivalConsumptionDBData_s::ResumeInit() {
	return 0;
}

void FestivalConsumptionDBData_s::write_to_pbmsg(::proto_ff::FestivalConsumptionDBData & msg) const {
	msg.set_activeid((uint64_t)activeId);
	msg.set_nconsumptionvalue((uint32_t)nConsumptionValue);
	for(int32_t i = 0; i < (int32_t)getState.GetSize() && i < getState.GetMaxSize(); ++i) {
		::proto_ff::ComPair* temp_getstate = msg.add_getstate();
		getState[i].write_to_pbmsg(*temp_getstate);
	}
	msg.set_nconsumptionholy((uint32_t)nConsumptionHoly);
	msg.set_nconsumptionvoucher((uint32_t)nConsumptionVoucher);
}

void FestivalConsumptionDBData_s::read_from_pbmsg(const ::proto_ff::FestivalConsumptionDBData & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct FestivalConsumptionDBData_s));
	activeId = msg.activeid();
	nConsumptionValue = msg.nconsumptionvalue();
	getState.SetSize(msg.getstate_size() > getState.GetMaxSize() ? getState.GetMaxSize() : msg.getstate_size());
	for(int32_t i = 0; i < (int32_t)getState.GetSize(); ++i) {
		const ::proto_ff::ComPair & temp_getstate = msg.getstate(i);
		getState[i].read_from_pbmsg(temp_getstate);
	}
	nConsumptionHoly = msg.nconsumptionholy();
	nConsumptionVoucher = msg.nconsumptionvoucher();
}

FestivalKillBossData_s::FestivalKillBossData_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int FestivalKillBossData_s::CreateInit() {
	activeId = (uint64_t)0;
	return 0;
}

int FestivalKillBossData_s::ResumeInit() {
	return 0;
}

void FestivalKillBossData_s::write_to_pbmsg(::proto_ff::FestivalKillBossData & msg) const {
	msg.set_activeid((uint64_t)activeId);
	for(int32_t i = 0; i < (int32_t)getState.GetSize() && i < getState.GetMaxSize(); ++i) {
		::proto_ff::ComPair* temp_getstate = msg.add_getstate();
		getState[i].write_to_pbmsg(*temp_getstate);
	}
}

void FestivalKillBossData_s::read_from_pbmsg(const ::proto_ff::FestivalKillBossData & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct FestivalKillBossData_s));
	activeId = msg.activeid();
	getState.SetSize(msg.getstate_size() > getState.GetMaxSize() ? getState.GetMaxSize() : msg.getstate_size());
	for(int32_t i = 0; i < (int32_t)getState.GetSize(); ++i) {
		const ::proto_ff::ComPair & temp_getstate = msg.getstate(i);
		getState[i].read_from_pbmsg(temp_getstate);
	}
}

FestivalZhiChongData_s::FestivalZhiChongData_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int FestivalZhiChongData_s::CreateInit() {
	activeId = (uint64_t)0;
	return 0;
}

int FestivalZhiChongData_s::ResumeInit() {
	return 0;
}

void FestivalZhiChongData_s::write_to_pbmsg(::proto_ff::FestivalZhiChongData & msg) const {
	msg.set_activeid((uint64_t)activeId);
	for(int32_t i = 0; i < (int32_t)getState.GetSize() && i < getState.GetMaxSize(); ++i) {
		::proto_ff::ComPair* temp_getstate = msg.add_getstate();
		getState[i].write_to_pbmsg(*temp_getstate);
	}
	for(int32_t i = 0; i < (int32_t)pointList.GetSize() && i < pointList.GetMaxSize(); ++i) {
		msg.add_pointlist((int64_t)pointList[i]);
	}
}

void FestivalZhiChongData_s::read_from_pbmsg(const ::proto_ff::FestivalZhiChongData & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct FestivalZhiChongData_s));
	activeId = msg.activeid();
	getState.SetSize(msg.getstate_size() > getState.GetMaxSize() ? getState.GetMaxSize() : msg.getstate_size());
	for(int32_t i = 0; i < (int32_t)getState.GetSize(); ++i) {
		const ::proto_ff::ComPair & temp_getstate = msg.getstate(i);
		getState[i].read_from_pbmsg(temp_getstate);
	}
	pointList.SetSize(msg.pointlist_size() > pointList.GetMaxSize() ? pointList.GetMaxSize() : msg.pointlist_size());
	for(int32_t i = 0; i < (int32_t)pointList.GetSize(); ++i) {
		pointList[i] = msg.pointlist(i);
	}
}

FestivalPreRechargeData_s::FestivalPreRechargeData_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int FestivalPreRechargeData_s::CreateInit() {
	activeId = (uint64_t)0;
	return 0;
}

int FestivalPreRechargeData_s::ResumeInit() {
	return 0;
}

void FestivalPreRechargeData_s::write_to_pbmsg(::proto_ff::FestivalPreRechargeData & msg) const {
	msg.set_activeid((uint64_t)activeId);
	for(int32_t i = 0; i < (int32_t)buy.GetSize() && i < buy.GetMaxSize(); ++i) {
		::proto_ff::ComPair* temp_buy = msg.add_buy();
		buy[i].write_to_pbmsg(*temp_buy);
	}
	for(int32_t i = 0; i < (int32_t)pointList.GetSize() && i < pointList.GetMaxSize(); ++i) {
		msg.add_pointlist((int64_t)pointList[i]);
	}
}

void FestivalPreRechargeData_s::read_from_pbmsg(const ::proto_ff::FestivalPreRechargeData & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct FestivalPreRechargeData_s));
	activeId = msg.activeid();
	buy.SetSize(msg.buy_size() > buy.GetMaxSize() ? buy.GetMaxSize() : msg.buy_size());
	for(int32_t i = 0; i < (int32_t)buy.GetSize(); ++i) {
		const ::proto_ff::ComPair & temp_buy = msg.buy(i);
		buy[i].read_from_pbmsg(temp_buy);
	}
	pointList.SetSize(msg.pointlist_size() > pointList.GetMaxSize() ? pointList.GetMaxSize() : msg.pointlist_size());
	for(int32_t i = 0; i < (int32_t)pointList.GetSize(); ++i) {
		pointList[i] = msg.pointlist(i);
	}
}

FestivalSuperDBData_s::FestivalSuperDBData_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int FestivalSuperDBData_s::CreateInit() {
	activeId = (uint64_t)0;
	nLastResetTime = (uint64_t)0;
	nLoninCount = (uint32_t)0;
	getId = (int32_t)0;
	active_state = (int32_t)0;
	return 0;
}

int FestivalSuperDBData_s::ResumeInit() {
	return 0;
}

void FestivalSuperDBData_s::write_to_pbmsg(::proto_ff::FestivalSuperDBData & msg) const {
	msg.set_activeid((uint64_t)activeId);
	msg.set_nlastresettime((uint64_t)nLastResetTime);
	msg.set_nlonincount((uint32_t)nLoninCount);
	msg.set_getid((int32_t)getId);
	msg.set_active_state((int32_t)active_state);
}

void FestivalSuperDBData_s::read_from_pbmsg(const ::proto_ff::FestivalSuperDBData & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct FestivalSuperDBData_s));
	activeId = msg.activeid();
	nLastResetTime = msg.nlastresettime();
	nLoninCount = msg.nlonincount();
	getId = msg.getid();
	active_state = msg.active_state();
}

FestivalSuperDoubleDBData_s::FestivalSuperDoubleDBData_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int FestivalSuperDoubleDBData_s::CreateInit() {
	activeId = (uint64_t)0;
	nLastResetTime = (uint64_t)0;
	curGiftId = (uint32_t)0;
	curGiftState = (int32_t)0;
	curDailyState = (int32_t)0;
	return 0;
}

int FestivalSuperDoubleDBData_s::ResumeInit() {
	return 0;
}

void FestivalSuperDoubleDBData_s::write_to_pbmsg(::proto_ff::FestivalSuperDoubleDBData & msg) const {
	msg.set_activeid((uint64_t)activeId);
	msg.set_nlastresettime((uint64_t)nLastResetTime);
	msg.set_curgiftid((uint32_t)curGiftId);
	msg.set_curgiftstate((int32_t)curGiftState);
	msg.set_curdailystate((int32_t)curDailyState);
}

void FestivalSuperDoubleDBData_s::read_from_pbmsg(const ::proto_ff::FestivalSuperDoubleDBData & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct FestivalSuperDoubleDBData_s));
	activeId = msg.activeid();
	nLastResetTime = msg.nlastresettime();
	curGiftId = msg.curgiftid();
	curGiftState = msg.curgiftstate();
	curDailyState = msg.curdailystate();
}

FestivalHuoYueDuDBData_s::FestivalHuoYueDuDBData_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int FestivalHuoYueDuDBData_s::CreateInit() {
	activeId = (uint64_t)0;
	nHuoYueDu = (uint32_t)0;
	return 0;
}

int FestivalHuoYueDuDBData_s::ResumeInit() {
	return 0;
}

void FestivalHuoYueDuDBData_s::write_to_pbmsg(::proto_ff::FestivalHuoYueDuDBData & msg) const {
	msg.set_activeid((uint64_t)activeId);
	msg.set_nhuoyuedu((uint32_t)nHuoYueDu);
	for(int32_t i = 0; i < (int32_t)getState.GetSize() && i < getState.GetMaxSize(); ++i) {
		::proto_ff::ComPair* temp_getstate = msg.add_getstate();
		getState[i].write_to_pbmsg(*temp_getstate);
	}
}

void FestivalHuoYueDuDBData_s::read_from_pbmsg(const ::proto_ff::FestivalHuoYueDuDBData & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct FestivalHuoYueDuDBData_s));
	activeId = msg.activeid();
	nHuoYueDu = msg.nhuoyuedu();
	getState.SetSize(msg.getstate_size() > getState.GetMaxSize() ? getState.GetMaxSize() : msg.getstate_size());
	for(int32_t i = 0; i < (int32_t)getState.GetSize(); ++i) {
		const ::proto_ff::ComPair & temp_getstate = msg.getstate(i);
		getState[i].read_from_pbmsg(temp_getstate);
	}
}

FestivalFirstRechargeDBData_s::FestivalFirstRechargeDBData_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int FestivalFirstRechargeDBData_s::CreateInit() {
	activeId = (uint64_t)0;
	rechargeTime = (uint32_t)0;
	return 0;
}

int FestivalFirstRechargeDBData_s::ResumeInit() {
	return 0;
}

void FestivalFirstRechargeDBData_s::write_to_pbmsg(::proto_ff::FestivalFirstRechargeDBData & msg) const {
	msg.set_activeid((uint64_t)activeId);
	msg.set_rechargetime((uint32_t)rechargeTime);
	for(int32_t i = 0; i < (int32_t)getState.GetSize() && i < getState.GetMaxSize(); ++i) {
		::proto_ff::ComPair* temp_getstate = msg.add_getstate();
		getState[i].write_to_pbmsg(*temp_getstate);
	}
}

void FestivalFirstRechargeDBData_s::read_from_pbmsg(const ::proto_ff::FestivalFirstRechargeDBData & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct FestivalFirstRechargeDBData_s));
	activeId = msg.activeid();
	rechargeTime = msg.rechargetime();
	getState.SetSize(msg.getstate_size() > getState.GetMaxSize() ? getState.GetMaxSize() : msg.getstate_size());
	for(int32_t i = 0; i < (int32_t)getState.GetSize(); ++i) {
		const ::proto_ff::ComPair & temp_getstate = msg.getstate(i);
		getState[i].read_from_pbmsg(temp_getstate);
	}
}

FestivalYanHuaDBData_s::FestivalYanHuaDBData_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int FestivalYanHuaDBData_s::CreateInit() {
	activeId = (uint64_t)0;
	return 0;
}

int FestivalYanHuaDBData_s::ResumeInit() {
	return 0;
}

void FestivalYanHuaDBData_s::write_to_pbmsg(::proto_ff::FestivalYanHuaDBData & msg) const {
	msg.set_activeid((uint64_t)activeId);
	for(int32_t i = 0; i < (int32_t)getItems.GetSize() && i < getItems.GetMaxSize(); ++i) {
		msg.add_getitems((uint64_t)getItems[i]);
	}
}

void FestivalYanHuaDBData_s::read_from_pbmsg(const ::proto_ff::FestivalYanHuaDBData & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct FestivalYanHuaDBData_s));
	activeId = msg.activeid();
	getItems.SetSize(msg.getitems_size() > getItems.GetMaxSize() ? getItems.GetMaxSize() : msg.getitems_size());
	for(int32_t i = 0; i < (int32_t)getItems.GetSize(); ++i) {
		getItems[i] = msg.getitems(i);
	}
}

FestivalBigYanHuaDBData_s::FestivalBigYanHuaDBData_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int FestivalBigYanHuaDBData_s::CreateInit() {
	activeId = (uint64_t)0;
	return 0;
}

int FestivalBigYanHuaDBData_s::ResumeInit() {
	return 0;
}

void FestivalBigYanHuaDBData_s::write_to_pbmsg(::proto_ff::FestivalBigYanHuaDBData & msg) const {
	msg.set_activeid((uint64_t)activeId);
	for(int32_t i = 0; i < (int32_t)getItems.GetSize() && i < getItems.GetMaxSize(); ++i) {
		msg.add_getitems((uint64_t)getItems[i]);
	}
}

void FestivalBigYanHuaDBData_s::read_from_pbmsg(const ::proto_ff::FestivalBigYanHuaDBData & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct FestivalBigYanHuaDBData_s));
	activeId = msg.activeid();
	getItems.SetSize(msg.getitems_size() > getItems.GetMaxSize() ? getItems.GetMaxSize() : msg.getitems_size());
	for(int32_t i = 0; i < (int32_t)getItems.GetSize(); ++i) {
		getItems[i] = msg.getitems(i);
	}
}

FestivalShopDBData_s::FestivalShopDBData_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int FestivalShopDBData_s::CreateInit() {
	activeId = (uint64_t)0;
	return 0;
}

int FestivalShopDBData_s::ResumeInit() {
	return 0;
}

void FestivalShopDBData_s::write_to_pbmsg(::proto_ff::FestivalShopDBData & msg) const {
	msg.set_activeid((uint64_t)activeId);
	for(int32_t i = 0; i < (int32_t)buyCount.GetSize() && i < buyCount.GetMaxSize(); ++i) {
		::proto_ff::ComPair64* temp_buycount = msg.add_buycount();
		buyCount[i].write_to_pbmsg(*temp_buycount);
	}
}

void FestivalShopDBData_s::read_from_pbmsg(const ::proto_ff::FestivalShopDBData & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct FestivalShopDBData_s));
	activeId = msg.activeid();
	buyCount.SetSize(msg.buycount_size() > buyCount.GetMaxSize() ? buyCount.GetMaxSize() : msg.buycount_size());
	for(int32_t i = 0; i < (int32_t)buyCount.GetSize(); ++i) {
		const ::proto_ff::ComPair64 & temp_buycount = msg.buycount(i);
		buyCount[i].read_from_pbmsg(temp_buycount);
	}
}

LimitGiftDBData_s::LimitGiftDBData_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int LimitGiftDBData_s::CreateInit() {
	giftId = (uint32_t)0;
	buyTime = (uint64_t)0;
	getState = (uint32_t)0;
	totalBack = (uint32_t)0;
	openTime = (uint32_t)0;
	lastResetTime = (uint64_t)0;
	return 0;
}

int LimitGiftDBData_s::ResumeInit() {
	return 0;
}

void LimitGiftDBData_s::write_to_pbmsg(::proto_ff::LimitGiftDBData & msg) const {
	msg.set_giftid((uint32_t)giftId);
	msg.set_buytime((uint64_t)buyTime);
	msg.set_getstate((uint32_t)getState);
	msg.set_totalback((uint32_t)totalBack);
	msg.set_opentime((uint32_t)openTime);
	msg.set_lastresettime((uint64_t)lastResetTime);
}

void LimitGiftDBData_s::read_from_pbmsg(const ::proto_ff::LimitGiftDBData & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct LimitGiftDBData_s));
	giftId = msg.giftid();
	buyTime = msg.buytime();
	getState = msg.getstate();
	totalBack = msg.totalback();
	openTime = msg.opentime();
	lastResetTime = msg.lastresettime();
}

LimitGiftActiveDBData_s::LimitGiftActiveDBData_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int LimitGiftActiveDBData_s::CreateInit() {
	activeId = (uint64_t)0;
	isFinish = (bool)0;
	return 0;
}

int LimitGiftActiveDBData_s::ResumeInit() {
	return 0;
}

void LimitGiftActiveDBData_s::write_to_pbmsg(::proto_ff::LimitGiftActiveDBData & msg) const {
	msg.set_activeid((uint64_t)activeId);
	msg.set_isfinish((bool)isFinish);
	for(int32_t i = 0; i < (int32_t)giftList.GetSize() && i < giftList.GetMaxSize(); ++i) {
		::proto_ff::LimitGiftDBData* temp_giftlist = msg.add_giftlist();
		giftList[i].write_to_pbmsg(*temp_giftlist);
	}
}

void LimitGiftActiveDBData_s::read_from_pbmsg(const ::proto_ff::LimitGiftActiveDBData & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct LimitGiftActiveDBData_s));
	activeId = msg.activeid();
	isFinish = msg.isfinish();
	giftList.SetSize(msg.giftlist_size() > giftList.GetMaxSize() ? giftList.GetMaxSize() : msg.giftlist_size());
	for(int32_t i = 0; i < (int32_t)giftList.GetSize(); ++i) {
		const ::proto_ff::LimitGiftDBData & temp_giftlist = msg.giftlist(i);
		giftList[i].read_from_pbmsg(temp_giftlist);
	}
}

FRechargeDBData_s::FRechargeDBData_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int FRechargeDBData_s::CreateInit() {
	pointId = (uint64_t)0;
	state = (uint32_t)0;
	return 0;
}

int FRechargeDBData_s::ResumeInit() {
	return 0;
}

void FRechargeDBData_s::write_to_pbmsg(::proto_ff::FRechargeDBData & msg) const {
	msg.set_pointid((uint64_t)pointId);
	msg.set_state((uint32_t)state);
}

void FRechargeDBData_s::read_from_pbmsg(const ::proto_ff::FRechargeDBData & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct FRechargeDBData_s));
	pointId = msg.pointid();
	state = msg.state();
}

FRechargeActiveDBData_s::FRechargeActiveDBData_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int FRechargeActiveDBData_s::CreateInit() {
	activeId = (uint64_t)0;
	return 0;
}

int FRechargeActiveDBData_s::ResumeInit() {
	return 0;
}

void FRechargeActiveDBData_s::write_to_pbmsg(::proto_ff::FRechargeActiveDBData & msg) const {
	msg.set_activeid((uint64_t)activeId);
	for(int32_t i = 0; i < (int32_t)dataList.GetSize() && i < dataList.GetMaxSize(); ++i) {
		::proto_ff::FRechargeDBData* temp_datalist = msg.add_datalist();
		dataList[i].write_to_pbmsg(*temp_datalist);
	}
}

void FRechargeActiveDBData_s::read_from_pbmsg(const ::proto_ff::FRechargeActiveDBData & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct FRechargeActiveDBData_s));
	activeId = msg.activeid();
	dataList.SetSize(msg.datalist_size() > dataList.GetMaxSize() ? dataList.GetMaxSize() : msg.datalist_size());
	for(int32_t i = 0; i < (int32_t)dataList.GetSize(); ++i) {
		const ::proto_ff::FRechargeDBData & temp_datalist = msg.datalist(i);
		dataList[i].read_from_pbmsg(temp_datalist);
	}
}

FSmashEggDBData_s::FSmashEggDBData_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int FSmashEggDBData_s::CreateInit() {
	itemId = (uint64_t)0;
	position = (uint32_t)0;
	quality = (uint32_t)0;
	itemNum = (uint32_t)0;
	return 0;
}

int FSmashEggDBData_s::ResumeInit() {
	return 0;
}

void FSmashEggDBData_s::write_to_pbmsg(::proto_ff::FSmashEggDBData & msg) const {
	msg.set_itemid((uint64_t)itemId);
	msg.set_position((uint32_t)position);
	msg.set_quality((uint32_t)quality);
	msg.set_itemnum((uint32_t)itemNum);
}

void FSmashEggDBData_s::read_from_pbmsg(const ::proto_ff::FSmashEggDBData & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct FSmashEggDBData_s));
	itemId = msg.itemid();
	position = msg.position();
	quality = msg.quality();
	itemNum = msg.itemnum();
}

FestivalSmashEggDBData_s::FestivalSmashEggDBData_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int FestivalSmashEggDBData_s::CreateInit() {
	activeId = (uint64_t)0;
	smashCount = (uint64_t)0;
	smashCountToday = (uint64_t)0;
	freeTimeDeadLine = (uint64_t)0;
	addRateCount = (uint32_t)0;
	resetRewardTime = (uint32_t)0;
	daynum = (int32_t)0;
	lastTime = (int64_t)0;
	return 0;
}

int FestivalSmashEggDBData_s::ResumeInit() {
	return 0;
}

void FestivalSmashEggDBData_s::write_to_pbmsg(::proto_ff::FestivalSmashEggDBData & msg) const {
	msg.set_activeid((uint64_t)activeId);
	msg.set_smashcount((uint64_t)smashCount);
	msg.set_smashcounttoday((uint64_t)smashCountToday);
	msg.set_freetimedeadline((uint64_t)freeTimeDeadLine);
	msg.set_addratecount((uint32_t)addRateCount);
	msg.set_resetrewardtime((uint32_t)resetRewardTime);
	for(int32_t i = 0; i < (int32_t)eggData.GetSize() && i < eggData.GetMaxSize(); ++i) {
		::proto_ff::FSmashEggDBData* temp_eggdata = msg.add_eggdata();
		eggData[i].write_to_pbmsg(*temp_eggdata);
	}
	for(int32_t i = 0; i < (int32_t)rewardGetState.GetSize() && i < rewardGetState.GetMaxSize(); ++i) {
		::proto_ff::ComPair* temp_rewardgetstate = msg.add_rewardgetstate();
		rewardGetState[i].write_to_pbmsg(*temp_rewardgetstate);
	}
	msg.set_daynum((int32_t)daynum);
	msg.set_lasttime((int64_t)lastTime);
}

void FestivalSmashEggDBData_s::read_from_pbmsg(const ::proto_ff::FestivalSmashEggDBData & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct FestivalSmashEggDBData_s));
	activeId = msg.activeid();
	smashCount = msg.smashcount();
	smashCountToday = msg.smashcounttoday();
	freeTimeDeadLine = msg.freetimedeadline();
	addRateCount = msg.addratecount();
	resetRewardTime = msg.resetrewardtime();
	eggData.SetSize(msg.eggdata_size() > eggData.GetMaxSize() ? eggData.GetMaxSize() : msg.eggdata_size());
	for(int32_t i = 0; i < (int32_t)eggData.GetSize(); ++i) {
		const ::proto_ff::FSmashEggDBData & temp_eggdata = msg.eggdata(i);
		eggData[i].read_from_pbmsg(temp_eggdata);
	}
	rewardGetState.SetSize(msg.rewardgetstate_size() > rewardGetState.GetMaxSize() ? rewardGetState.GetMaxSize() : msg.rewardgetstate_size());
	for(int32_t i = 0; i < (int32_t)rewardGetState.GetSize(); ++i) {
		const ::proto_ff::ComPair & temp_rewardgetstate = msg.rewardgetstate(i);
		rewardGetState[i].read_from_pbmsg(temp_rewardgetstate);
	}
	daynum = msg.daynum();
	lastTime = msg.lasttime();
}

OperateReward_s::OperateReward_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int OperateReward_s::CreateInit() {
	key_id = (uint64_t)0;
	isFinish = (bool)0;
	isReceiveReward = (bool)0;
	return 0;
}

int OperateReward_s::ResumeInit() {
	return 0;
}

void OperateReward_s::write_to_pbmsg(::proto_ff::OperateReward & msg) const {
	msg.set_key_id((uint64_t)key_id);
	msg.set_isfinish((bool)isFinish);
	msg.set_isreceivereward((bool)isReceiveReward);
	::proto_ff::ComPair* temp_rechargedays = msg.mutable_rechargedays();
	rechargeDays.write_to_pbmsg(*temp_rechargedays);
}

void OperateReward_s::read_from_pbmsg(const ::proto_ff::OperateReward & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct OperateReward_s));
	key_id = msg.key_id();
	isFinish = msg.isfinish();
	isReceiveReward = msg.isreceivereward();
	const ::proto_ff::ComPair & temp_rechargedays = msg.rechargedays();
	rechargeDays.read_from_pbmsg(temp_rechargedays);
}

OperateDailyRechargeData_s::OperateDailyRechargeData_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int OperateDailyRechargeData_s::CreateInit() {
	id = (uint64_t)0;
	rmbToday = (uint32_t)0;
	rmbTotal = (uint32_t)0;
	lastRechargeDate = (uint32_t)0;
	return 0;
}

int OperateDailyRechargeData_s::ResumeInit() {
	return 0;
}

void OperateDailyRechargeData_s::write_to_pbmsg(::proto_ff::OperateDailyRechargeData & msg) const {
	msg.set_id((uint64_t)id);
	msg.set_rmbtoday((uint32_t)rmbToday);
	msg.set_rmbtotal((uint32_t)rmbTotal);
	msg.set_lastrechargedate((uint32_t)lastRechargeDate);
	for(int32_t i = 0; i < (int32_t)list.GetSize() && i < list.GetMaxSize(); ++i) {
		::proto_ff::OperateReward* temp_list = msg.add_list();
		list[i].write_to_pbmsg(*temp_list);
	}
}

void OperateDailyRechargeData_s::read_from_pbmsg(const ::proto_ff::OperateDailyRechargeData & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct OperateDailyRechargeData_s));
	id = msg.id();
	rmbToday = msg.rmbtoday();
	rmbTotal = msg.rmbtotal();
	lastRechargeDate = msg.lastrechargedate();
	list.SetSize(msg.list_size() > list.GetMaxSize() ? list.GetMaxSize() : msg.list_size());
	for(int32_t i = 0; i < (int32_t)list.GetSize(); ++i) {
		const ::proto_ff::OperateReward & temp_list = msg.list(i);
		list[i].read_from_pbmsg(temp_list);
	}
}

OperateMoonCardData_s::OperateMoonCardData_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int OperateMoonCardData_s::CreateInit() {
	id = (uint64_t)0;
	buyDate = (uint32_t)0;
	return 0;
}

int OperateMoonCardData_s::ResumeInit() {
	return 0;
}

void OperateMoonCardData_s::write_to_pbmsg(::proto_ff::OperateMoonCardData & msg) const {
	msg.set_id((uint64_t)id);
	msg.set_buydate((uint32_t)buyDate);
	for(int32_t i = 0; i < (int32_t)list.GetSize() && i < list.GetMaxSize(); ++i) {
		::proto_ff::OperateReward* temp_list = msg.add_list();
		list[i].write_to_pbmsg(*temp_list);
	}
}

void OperateMoonCardData_s::read_from_pbmsg(const ::proto_ff::OperateMoonCardData & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct OperateMoonCardData_s));
	id = msg.id();
	buyDate = msg.buydate();
	list.SetSize(msg.list_size() > list.GetMaxSize() ? list.GetMaxSize() : msg.list_size());
	for(int32_t i = 0; i < (int32_t)list.GetSize(); ++i) {
		const ::proto_ff::OperateReward & temp_list = msg.list(i);
		list[i].read_from_pbmsg(temp_list);
	}
}

OperateFundData_s::OperateFundData_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int OperateFundData_s::CreateInit() {
	id = (uint64_t)0;
	level = (uint32_t)0;
	buyDate = (uint32_t)0;
	return 0;
}

int OperateFundData_s::ResumeInit() {
	return 0;
}

void OperateFundData_s::write_to_pbmsg(::proto_ff::OperateFundData & msg) const {
	msg.set_id((uint64_t)id);
	msg.set_level((uint32_t)level);
	msg.set_buydate((uint32_t)buyDate);
	for(int32_t i = 0; i < (int32_t)list.GetSize() && i < list.GetMaxSize(); ++i) {
		::proto_ff::OperateReward* temp_list = msg.add_list();
		list[i].write_to_pbmsg(*temp_list);
	}
}

void OperateFundData_s::read_from_pbmsg(const ::proto_ff::OperateFundData & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct OperateFundData_s));
	id = msg.id();
	level = msg.level();
	buyDate = msg.buydate();
	list.SetSize(msg.list_size() > list.GetMaxSize() ? list.GetMaxSize() : msg.list_size());
	for(int32_t i = 0; i < (int32_t)list.GetSize(); ++i) {
		const ::proto_ff::OperateReward & temp_list = msg.list(i);
		list[i].read_from_pbmsg(temp_list);
	}
}

OperateFirstRechargeType_s::OperateFirstRechargeType_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int OperateFirstRechargeType_s::CreateInit() {
	type = (int32_t)0;
	updateTime = (uint64_t)0;
	loginDay = (int32_t)0;
	return 0;
}

int OperateFirstRechargeType_s::ResumeInit() {
	return 0;
}

void OperateFirstRechargeType_s::write_to_pbmsg(::proto_ff::OperateFirstRechargeType & msg) const {
	msg.set_type((int32_t)type);
	msg.set_updatetime((uint64_t)updateTime);
	msg.set_loginday((int32_t)loginDay);
}

void OperateFirstRechargeType_s::read_from_pbmsg(const ::proto_ff::OperateFirstRechargeType & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct OperateFirstRechargeType_s));
	type = msg.type();
	updateTime = msg.updatetime();
	loginDay = msg.loginday();
}

OperateFirstRechargeData_s::OperateFirstRechargeData_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int OperateFirstRechargeData_s::CreateInit() {
	id = (uint64_t)0;
	rmb = (int32_t)0;
	return 0;
}

int OperateFirstRechargeData_s::ResumeInit() {
	return 0;
}

void OperateFirstRechargeData_s::write_to_pbmsg(::proto_ff::OperateFirstRechargeData & msg) const {
	msg.set_id((uint64_t)id);
	for(int32_t i = 0; i < (int32_t)list.GetSize() && i < list.GetMaxSize(); ++i) {
		::proto_ff::OperateReward* temp_list = msg.add_list();
		list[i].write_to_pbmsg(*temp_list);
	}
	for(int32_t i = 0; i < (int32_t)firstType.GetSize() && i < firstType.GetMaxSize(); ++i) {
		::proto_ff::OperateFirstRechargeType* temp_firsttype = msg.add_firsttype();
		firstType[i].write_to_pbmsg(*temp_firsttype);
	}
	msg.set_rmb((int32_t)rmb);
}

void OperateFirstRechargeData_s::read_from_pbmsg(const ::proto_ff::OperateFirstRechargeData & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct OperateFirstRechargeData_s));
	id = msg.id();
	list.SetSize(msg.list_size() > list.GetMaxSize() ? list.GetMaxSize() : msg.list_size());
	for(int32_t i = 0; i < (int32_t)list.GetSize(); ++i) {
		const ::proto_ff::OperateReward & temp_list = msg.list(i);
		list[i].read_from_pbmsg(temp_list);
	}
	firstType.SetSize(msg.firsttype_size() > firstType.GetMaxSize() ? firstType.GetMaxSize() : msg.firsttype_size());
	for(int32_t i = 0; i < (int32_t)firstType.GetSize(); ++i) {
		const ::proto_ff::OperateFirstRechargeType & temp_firsttype = msg.firsttype(i);
		firstType[i].read_from_pbmsg(temp_firsttype);
	}
	rmb = msg.rmb();
}

WelfareVipGiftDBData_s::WelfareVipGiftDBData_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int WelfareVipGiftDBData_s::CreateInit() {
	id = (uint64_t)0;
	return 0;
}

int WelfareVipGiftDBData_s::ResumeInit() {
	return 0;
}

void WelfareVipGiftDBData_s::write_to_pbmsg(::proto_ff::WelfareVipGiftDBData & msg) const {
	msg.set_id((uint64_t)id);
	for(int32_t i = 0; i < (int32_t)getState.GetSize() && i < getState.GetMaxSize(); ++i) {
		::proto_ff::ComPair* temp_getstate = msg.add_getstate();
		getState[i].write_to_pbmsg(*temp_getstate);
	}
}

void WelfareVipGiftDBData_s::read_from_pbmsg(const ::proto_ff::WelfareVipGiftDBData & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct WelfareVipGiftDBData_s));
	id = msg.id();
	getState.SetSize(msg.getstate_size() > getState.GetMaxSize() ? getState.GetMaxSize() : msg.getstate_size());
	for(int32_t i = 0; i < (int32_t)getState.GetSize(); ++i) {
		const ::proto_ff::ComPair & temp_getstate = msg.getstate(i);
		getState[i].read_from_pbmsg(temp_getstate);
	}
}

HoroscopeJackpotDBData_s::HoroscopeJackpotDBData_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int HoroscopeJackpotDBData_s::CreateInit() {
	id = (uint32_t)0;
	bOpen = (bool)0;
	nNeedLevel = (uint32_t)0;
	luckyValue = (uint32_t)0;
	welfareValue = (uint32_t)0;
	getLuckyCount = (uint32_t)0;
	lastTime = (int64_t)0;
	curNum = (int32_t)0;
	return 0;
}

int HoroscopeJackpotDBData_s::ResumeInit() {
	return 0;
}

void HoroscopeJackpotDBData_s::write_to_pbmsg(::proto_ff::HoroscopeJackpotDBData & msg) const {
	msg.set_id((uint32_t)id);
	msg.set_bopen((bool)bOpen);
	msg.set_nneedlevel((uint32_t)nNeedLevel);
	msg.set_luckyvalue((uint32_t)luckyValue);
	msg.set_welfarevalue((uint32_t)welfareValue);
	msg.set_getluckycount((uint32_t)getLuckyCount);
	for(int32_t i = 0; i < (int32_t)welfareGetState.GetSize() && i < welfareGetState.GetMaxSize(); ++i) {
		::proto_ff::ComPair* temp_welfaregetstate = msg.add_welfaregetstate();
		welfareGetState[i].write_to_pbmsg(*temp_welfaregetstate);
	}
	msg.set_lasttime((int64_t)lastTime);
	msg.set_curnum((int32_t)curNum);
}

void HoroscopeJackpotDBData_s::read_from_pbmsg(const ::proto_ff::HoroscopeJackpotDBData & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct HoroscopeJackpotDBData_s));
	id = msg.id();
	bOpen = msg.bopen();
	nNeedLevel = msg.nneedlevel();
	luckyValue = msg.luckyvalue();
	welfareValue = msg.welfarevalue();
	getLuckyCount = msg.getluckycount();
	welfareGetState.SetSize(msg.welfaregetstate_size() > welfareGetState.GetMaxSize() ? welfareGetState.GetMaxSize() : msg.welfaregetstate_size());
	for(int32_t i = 0; i < (int32_t)welfareGetState.GetSize(); ++i) {
		const ::proto_ff::ComPair & temp_welfaregetstate = msg.welfaregetstate(i);
		welfareGetState[i].read_from_pbmsg(temp_welfaregetstate);
	}
	lastTime = msg.lasttime();
	curNum = msg.curnum();
}

HoroscopeActiveDBData_s::HoroscopeActiveDBData_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int HoroscopeActiveDBData_s::CreateInit() {
	activeId = (uint64_t)0;
	drawCount = (uint64_t)0;
	freeOpId = (uint32_t)0;
	lastFreeGetTime = (uint64_t)0;
	return 0;
}

int HoroscopeActiveDBData_s::ResumeInit() {
	return 0;
}

void HoroscopeActiveDBData_s::write_to_pbmsg(::proto_ff::HoroscopeActiveDBData & msg) const {
	msg.set_activeid((uint64_t)activeId);
	msg.set_drawcount((uint64_t)drawCount);
	msg.set_freeopid((uint32_t)freeOpId);
	msg.set_lastfreegettime((uint64_t)lastFreeGetTime);
	for(int32_t i = 0; i < (int32_t)jackpotList.GetSize() && i < jackpotList.GetMaxSize(); ++i) {
		::proto_ff::HoroscopeJackpotDBData* temp_jackpotlist = msg.add_jackpotlist();
		jackpotList[i].write_to_pbmsg(*temp_jackpotlist);
	}
}

void HoroscopeActiveDBData_s::read_from_pbmsg(const ::proto_ff::HoroscopeActiveDBData & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct HoroscopeActiveDBData_s));
	activeId = msg.activeid();
	drawCount = msg.drawcount();
	freeOpId = msg.freeopid();
	lastFreeGetTime = msg.lastfreegettime();
	jackpotList.SetSize(msg.jackpotlist_size() > jackpotList.GetMaxSize() ? jackpotList.GetMaxSize() : msg.jackpotlist_size());
	for(int32_t i = 0; i < (int32_t)jackpotList.GetSize(); ++i) {
		const ::proto_ff::HoroscopeJackpotDBData & temp_jackpotlist = msg.jackpotlist(i);
		jackpotList[i].read_from_pbmsg(temp_jackpotlist);
	}
}

WelfareOnlineGiftDBData_s::WelfareOnlineGiftDBData_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int WelfareOnlineGiftDBData_s::CreateInit() {
	id = (uint64_t)0;
	lastRefreshTime = (uint64_t)0;
	OnlineTime = (uint64_t)0;
	return 0;
}

int WelfareOnlineGiftDBData_s::ResumeInit() {
	return 0;
}

void WelfareOnlineGiftDBData_s::write_to_pbmsg(::proto_ff::WelfareOnlineGiftDBData & msg) const {
	msg.set_id((uint64_t)id);
	msg.set_lastrefreshtime((uint64_t)lastRefreshTime);
	msg.set_onlinetime((uint64_t)OnlineTime);
	for(int32_t i = 0; i < (int32_t)getState.GetSize() && i < getState.GetMaxSize(); ++i) {
		::proto_ff::ComPair* temp_getstate = msg.add_getstate();
		getState[i].write_to_pbmsg(*temp_getstate);
	}
}

void WelfareOnlineGiftDBData_s::read_from_pbmsg(const ::proto_ff::WelfareOnlineGiftDBData & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct WelfareOnlineGiftDBData_s));
	id = msg.id();
	lastRefreshTime = msg.lastrefreshtime();
	OnlineTime = msg.onlinetime();
	getState.SetSize(msg.getstate_size() > getState.GetMaxSize() ? getState.GetMaxSize() : msg.getstate_size());
	for(int32_t i = 0; i < (int32_t)getState.GetSize(); ++i) {
		const ::proto_ff::ComPair & temp_getstate = msg.getstate(i);
		getState[i].read_from_pbmsg(temp_getstate);
	}
}

OperationTurntableTaskDBData_s::OperationTurntableTaskDBData_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int OperationTurntableTaskDBData_s::CreateInit() {
	taskId = (uint64_t)0;
	progress = (uint64_t)0;
	state = (uint32_t)0;
	return 0;
}

int OperationTurntableTaskDBData_s::ResumeInit() {
	return 0;
}

void OperationTurntableTaskDBData_s::write_to_pbmsg(::proto_ff::OperationTurntableTaskDBData & msg) const {
	msg.set_taskid((uint64_t)taskId);
	msg.set_progress((uint64_t)progress);
	msg.set_state((uint32_t)state);
}

void OperationTurntableTaskDBData_s::read_from_pbmsg(const ::proto_ff::OperationTurntableTaskDBData & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct OperationTurntableTaskDBData_s));
	taskId = msg.taskid();
	progress = msg.progress();
	state = msg.state();
}

OperationTurntableDBData_s::OperationTurntableDBData_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int OperationTurntableDBData_s::CreateInit() {
	activeId = (uint64_t)0;
	lastRefreshTime = (uint64_t)0;
	return 0;
}

int OperationTurntableDBData_s::ResumeInit() {
	return 0;
}

void OperationTurntableDBData_s::write_to_pbmsg(::proto_ff::OperationTurntableDBData & msg) const {
	msg.set_activeid((uint64_t)activeId);
	msg.set_lastrefreshtime((uint64_t)lastRefreshTime);
	for(int32_t i = 0; i < (int32_t)tasklist.GetSize() && i < tasklist.GetMaxSize(); ++i) {
		::proto_ff::OperationTurntableTaskDBData* temp_tasklist = msg.add_tasklist();
		tasklist[i].write_to_pbmsg(*temp_tasklist);
	}
}

void OperationTurntableDBData_s::read_from_pbmsg(const ::proto_ff::OperationTurntableDBData & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct OperationTurntableDBData_s));
	activeId = msg.activeid();
	lastRefreshTime = msg.lastrefreshtime();
	tasklist.SetSize(msg.tasklist_size() > tasklist.GetMaxSize() ? tasklist.GetMaxSize() : msg.tasklist_size());
	for(int32_t i = 0; i < (int32_t)tasklist.GetSize(); ++i) {
		const ::proto_ff::OperationTurntableTaskDBData & temp_tasklist = msg.tasklist(i);
		tasklist[i].read_from_pbmsg(temp_tasklist);
	}
}

OperationTutoraskDBData_s::OperationTutoraskDBData_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int OperationTutoraskDBData_s::CreateInit() {
	taskId = (uint64_t)0;
	progress = (uint64_t)0;
	state = (uint32_t)0;
	return 0;
}

int OperationTutoraskDBData_s::ResumeInit() {
	return 0;
}

void OperationTutoraskDBData_s::write_to_pbmsg(::proto_ff::OperationTutoraskDBData & msg) const {
	msg.set_taskid((uint64_t)taskId);
	msg.set_progress((uint64_t)progress);
	msg.set_state((uint32_t)state);
}

void OperationTutoraskDBData_s::read_from_pbmsg(const ::proto_ff::OperationTutoraskDBData & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct OperationTutoraskDBData_s));
	taskId = msg.taskid();
	progress = msg.progress();
	state = msg.state();
}

OperationTutorDBData_s::OperationTutorDBData_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int OperationTutorDBData_s::CreateInit() {
	activeId = (uint64_t)0;
	lastRefreshTime = (uint64_t)0;
	diligentValue = (uint64_t)0;
	return 0;
}

int OperationTutorDBData_s::ResumeInit() {
	return 0;
}

void OperationTutorDBData_s::write_to_pbmsg(::proto_ff::OperationTutorDBData & msg) const {
	msg.set_activeid((uint64_t)activeId);
	msg.set_lastrefreshtime((uint64_t)lastRefreshTime);
	msg.set_diligentvalue((uint64_t)diligentValue);
	for(int32_t i = 0; i < (int32_t)tasklist.GetSize() && i < tasklist.GetMaxSize(); ++i) {
		::proto_ff::OperationTutoraskDBData* temp_tasklist = msg.add_tasklist();
		tasklist[i].write_to_pbmsg(*temp_tasklist);
	}
}

void OperationTutorDBData_s::read_from_pbmsg(const ::proto_ff::OperationTutorDBData & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct OperationTutorDBData_s));
	activeId = msg.activeid();
	lastRefreshTime = msg.lastrefreshtime();
	diligentValue = msg.diligentvalue();
	tasklist.SetSize(msg.tasklist_size() > tasklist.GetMaxSize() ? tasklist.GetMaxSize() : msg.tasklist_size());
	for(int32_t i = 0; i < (int32_t)tasklist.GetSize(); ++i) {
		const ::proto_ff::OperationTutoraskDBData & temp_tasklist = msg.tasklist(i);
		tasklist[i].read_from_pbmsg(temp_tasklist);
	}
}

limitInfo_s::limitInfo_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int limitInfo_s::CreateInit() {
	id = (uint64_t)0;
	return 0;
}

int limitInfo_s::ResumeInit() {
	return 0;
}

void limitInfo_s::write_to_pbmsg(::proto_ff::limitInfo & msg) const {
	msg.set_id((uint64_t)id);
	for(int32_t i = 0; i < (int32_t)infos.GetSize() && i < infos.GetMaxSize(); ++i) {
		::proto_ff::ComPair64* temp_infos = msg.add_infos();
		infos[i].write_to_pbmsg(*temp_infos);
	}
}

void limitInfo_s::read_from_pbmsg(const ::proto_ff::limitInfo & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct limitInfo_s));
	id = msg.id();
	infos.SetSize(msg.infos_size() > infos.GetMaxSize() ? infos.GetMaxSize() : msg.infos_size());
	for(int32_t i = 0; i < (int32_t)infos.GetSize(); ++i) {
		const ::proto_ff::ComPair64 & temp_infos = msg.infos(i);
		infos[i].read_from_pbmsg(temp_infos);
	}
}

FestivalWorldBossData_s::FestivalWorldBossData_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int FestivalWorldBossData_s::CreateInit() {
	activeId = (uint64_t)0;
	return 0;
}

int FestivalWorldBossData_s::ResumeInit() {
	return 0;
}

void FestivalWorldBossData_s::write_to_pbmsg(::proto_ff::FestivalWorldBossData & msg) const {
	msg.set_activeid((uint64_t)activeId);
	for(int32_t i = 0; i < (int32_t)getState.GetSize() && i < getState.GetMaxSize(); ++i) {
		::proto_ff::ComPair* temp_getstate = msg.add_getstate();
		getState[i].write_to_pbmsg(*temp_getstate);
	}
}

void FestivalWorldBossData_s::read_from_pbmsg(const ::proto_ff::FestivalWorldBossData & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct FestivalWorldBossData_s));
	activeId = msg.activeid();
	getState.SetSize(msg.getstate_size() > getState.GetMaxSize() ? getState.GetMaxSize() : msg.getstate_size());
	for(int32_t i = 0; i < (int32_t)getState.GetSize(); ++i) {
		const ::proto_ff::ComPair & temp_getstate = msg.getstate(i);
		getState[i].read_from_pbmsg(temp_getstate);
	}
}

OperateCommonEntryData_s::OperateCommonEntryData_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int OperateCommonEntryData_s::CreateInit() {
	id = (uint64_t)0;
	state = (int32_t)0;
	value = (int64_t)0;
	return 0;
}

int OperateCommonEntryData_s::ResumeInit() {
	return 0;
}

void OperateCommonEntryData_s::write_to_pbmsg(::proto_ff::OperateCommonEntryData & msg) const {
	msg.set_id((uint64_t)id);
	msg.set_state((int32_t)state);
	msg.set_value((int64_t)value);
}

void OperateCommonEntryData_s::read_from_pbmsg(const ::proto_ff::OperateCommonEntryData & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct OperateCommonEntryData_s));
	id = msg.id();
	state = msg.state();
	value = msg.value();
}

OperateWingGiftData_s::OperateWingGiftData_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int OperateWingGiftData_s::CreateInit() {
	activeId = (uint64_t)0;
	refreshTime = (int64_t)0;
	loginDay = (int32_t)0;
	return 0;
}

int OperateWingGiftData_s::ResumeInit() {
	return 0;
}

void OperateWingGiftData_s::write_to_pbmsg(::proto_ff::OperateWingGiftData & msg) const {
	msg.set_activeid((uint64_t)activeId);
	for(int32_t i = 0; i < (int32_t)entrys.GetSize() && i < entrys.GetMaxSize(); ++i) {
		::proto_ff::OperateCommonEntryData* temp_entrys = msg.add_entrys();
		entrys[i].write_to_pbmsg(*temp_entrys);
	}
	msg.set_refreshtime((int64_t)refreshTime);
	msg.set_loginday((int32_t)loginDay);
}

void OperateWingGiftData_s::read_from_pbmsg(const ::proto_ff::OperateWingGiftData & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct OperateWingGiftData_s));
	activeId = msg.activeid();
	entrys.SetSize(msg.entrys_size() > entrys.GetMaxSize() ? entrys.GetMaxSize() : msg.entrys_size());
	for(int32_t i = 0; i < (int32_t)entrys.GetSize(); ++i) {
		const ::proto_ff::OperateCommonEntryData & temp_entrys = msg.entrys(i);
		entrys[i].read_from_pbmsg(temp_entrys);
	}
	refreshTime = msg.refreshtime();
	loginDay = msg.loginday();
}

OperateRechargeGiftData_s::OperateRechargeGiftData_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int OperateRechargeGiftData_s::CreateInit() {
	activeId = (uint64_t)0;
	rechargeRmb = (int32_t)0;
	return 0;
}

int OperateRechargeGiftData_s::ResumeInit() {
	return 0;
}

void OperateRechargeGiftData_s::write_to_pbmsg(::proto_ff::OperateRechargeGiftData & msg) const {
	msg.set_activeid((uint64_t)activeId);
	for(int32_t i = 0; i < (int32_t)entrys.GetSize() && i < entrys.GetMaxSize(); ++i) {
		::proto_ff::OperateCommonEntryData* temp_entrys = msg.add_entrys();
		entrys[i].write_to_pbmsg(*temp_entrys);
	}
	msg.set_rechargermb((int32_t)rechargeRmb);
}

void OperateRechargeGiftData_s::read_from_pbmsg(const ::proto_ff::OperateRechargeGiftData & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct OperateRechargeGiftData_s));
	activeId = msg.activeid();
	entrys.SetSize(msg.entrys_size() > entrys.GetMaxSize() ? entrys.GetMaxSize() : msg.entrys_size());
	for(int32_t i = 0; i < (int32_t)entrys.GetSize(); ++i) {
		const ::proto_ff::OperateCommonEntryData & temp_entrys = msg.entrys(i);
		entrys[i].read_from_pbmsg(temp_entrys);
	}
	rechargeRmb = msg.rechargermb();
}

CharacterDBOperateData_s::CharacterDBOperateData_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int CharacterDBOperateData_s::CreateInit() {
	return 0;
}

int CharacterDBOperateData_s::ResumeInit() {
	return 0;
}

void CharacterDBOperateData_s::write_to_pbmsg(::proto_ff::CharacterDBOperateData & msg) const {
	for(int32_t i = 0; i < (int32_t)signInData.GetSize() && i < signInData.GetMaxSize(); ++i) {
		::proto_ff::WelfareDailySignInDBData* temp_signindata = msg.add_signindata();
		signInData[i].write_to_pbmsg(*temp_signindata);
	}
	for(int32_t i = 0; i < (int32_t)loginGiftData.GetSize() && i < loginGiftData.GetMaxSize(); ++i) {
		::proto_ff::WelfareLoginGiftDBData* temp_logingiftdata = msg.add_logingiftdata();
		loginGiftData[i].write_to_pbmsg(*temp_logingiftdata);
	}
	for(int32_t i = 0; i < (int32_t)levelGiftData.GetSize() && i < levelGiftData.GetMaxSize(); ++i) {
		::proto_ff::WelfareLevelGiftDBData* temp_levelgiftdata = msg.add_levelgiftdata();
		levelGiftData[i].write_to_pbmsg(*temp_levelgiftdata);
	}
	for(int32_t i = 0; i < (int32_t)shopData.GetSize() && i < shopData.GetMaxSize(); ++i) {
		::proto_ff::LimitShopData* temp_shopdata = msg.add_shopdata();
		shopData[i].write_to_pbmsg(*temp_shopdata);
	}
	for(int32_t i = 0; i < (int32_t)taskData.GetSize() && i < taskData.GetMaxSize(); ++i) {
		::proto_ff::LimitTaskData* temp_taskdata = msg.add_taskdata();
		taskData[i].write_to_pbmsg(*temp_taskdata);
	}
	for(int32_t i = 0; i < (int32_t)wishData.GetSize() && i < wishData.GetMaxSize(); ++i) {
		::proto_ff::WishDBData* temp_wishdata = msg.add_wishdata();
		wishData[i].write_to_pbmsg(*temp_wishdata);
	}
	::proto_ff::OperateDailyRechargeData* temp_dailyrecharge = msg.mutable_dailyrecharge();
	dailyRecharge.write_to_pbmsg(*temp_dailyrecharge);
	::proto_ff::OperateFirstRechargeData* temp_firstrecharge = msg.mutable_firstrecharge();
	firstRecharge.write_to_pbmsg(*temp_firstrecharge);
	::proto_ff::OperateMoonCardData* temp_mooncard = msg.mutable_mooncard();
	moonCard.write_to_pbmsg(*temp_mooncard);
	::proto_ff::OperateFundData* temp_novicefund = msg.mutable_novicefund();
	noviceFund.write_to_pbmsg(*temp_novicefund);
	::proto_ff::OperateFundData* temp_growthfund = msg.mutable_growthfund();
	growthFund.write_to_pbmsg(*temp_growthfund);
	::proto_ff::OperateFundData* temp_dreamfund = msg.mutable_dreamfund();
	dreamFund.write_to_pbmsg(*temp_dreamfund);
	::proto_ff::OperateFundData* temp_novicefundhigh = msg.mutable_novicefundhigh();
	noviceFundHigh.write_to_pbmsg(*temp_novicefundhigh);
	::proto_ff::OperateFundData* temp_growthfundhigh = msg.mutable_growthfundhigh();
	growthFundHigh.write_to_pbmsg(*temp_growthfundhigh);
	::proto_ff::OperateFundData* temp_dreamfundhigh = msg.mutable_dreamfundhigh();
	dreamFundHigh.write_to_pbmsg(*temp_dreamfundhigh);
	for(int32_t i = 0; i < (int32_t)fInvestDBData.GetSize() && i < fInvestDBData.GetMaxSize(); ++i) {
		::proto_ff::FestivalInvestDBData* temp_finvestdbdata = msg.add_finvestdbdata();
		fInvestDBData[i].write_to_pbmsg(*temp_finvestdbdata);
	}
	for(int32_t i = 0; i < (int32_t)fExchangeDBData.GetSize() && i < fExchangeDBData.GetMaxSize(); ++i) {
		::proto_ff::FestivalExchangeDBData* temp_fexchangedbdata = msg.add_fexchangedbdata();
		fExchangeDBData[i].write_to_pbmsg(*temp_fexchangedbdata);
	}
	for(int32_t i = 0; i < (int32_t)fLoginDBData.GetSize() && i < fLoginDBData.GetMaxSize(); ++i) {
		::proto_ff::FestivalLoginDBData* temp_flogindbdata = msg.add_flogindbdata();
		fLoginDBData[i].write_to_pbmsg(*temp_flogindbdata);
	}
	for(int32_t i = 0; i < (int32_t)fRechargeDBData.GetSize() && i < fRechargeDBData.GetMaxSize(); ++i) {
		::proto_ff::FestivalTotalRechargeDBData* temp_frechargedbdata = msg.add_frechargedbdata();
		fRechargeDBData[i].write_to_pbmsg(*temp_frechargedbdata);
	}
	for(int32_t i = 0; i < (int32_t)fConsumptionDBData.GetSize() && i < fConsumptionDBData.GetMaxSize(); ++i) {
		::proto_ff::FestivalConsumptionDBData* temp_fconsumptiondbdata = msg.add_fconsumptiondbdata();
		fConsumptionDBData[i].write_to_pbmsg(*temp_fconsumptiondbdata);
	}
	for(int32_t i = 0; i < (int32_t)fFirstRechargeDBData.GetSize() && i < fFirstRechargeDBData.GetMaxSize(); ++i) {
		::proto_ff::FestivalFirstRechargeDBData* temp_ffirstrechargedbdata = msg.add_ffirstrechargedbdata();
		fFirstRechargeDBData[i].write_to_pbmsg(*temp_ffirstrechargedbdata);
	}
	for(int32_t i = 0; i < (int32_t)fYanHuaDBData.GetSize() && i < fYanHuaDBData.GetMaxSize(); ++i) {
		::proto_ff::FestivalYanHuaDBData* temp_fyanhuadbdata = msg.add_fyanhuadbdata();
		fYanHuaDBData[i].write_to_pbmsg(*temp_fyanhuadbdata);
	}
	for(int32_t i = 0; i < (int32_t)fShopDBData.GetSize() && i < fShopDBData.GetMaxSize(); ++i) {
		::proto_ff::FestivalShopDBData* temp_fshopdbdata = msg.add_fshopdbdata();
		fShopDBData[i].write_to_pbmsg(*temp_fshopdbdata);
	}
	for(int32_t i = 0; i < (int32_t)limitGiftDBData.GetSize() && i < limitGiftDBData.GetMaxSize(); ++i) {
		::proto_ff::LimitGiftActiveDBData* temp_limitgiftdbdata = msg.add_limitgiftdbdata();
		limitGiftDBData[i].write_to_pbmsg(*temp_limitgiftdbdata);
	}
	for(int32_t i = 0; i < (int32_t)horoscopeDBData.GetSize() && i < horoscopeDBData.GetMaxSize(); ++i) {
		::proto_ff::HoroscopeActiveDBData* temp_horoscopedbdata = msg.add_horoscopedbdata();
		horoscopeDBData[i].write_to_pbmsg(*temp_horoscopedbdata);
	}
	for(int32_t i = 0; i < (int32_t)festivalRechargeDBData.GetSize() && i < festivalRechargeDBData.GetMaxSize(); ++i) {
		::proto_ff::FRechargeActiveDBData* temp_festivalrechargedbdata = msg.add_festivalrechargedbdata();
		festivalRechargeDBData[i].write_to_pbmsg(*temp_festivalrechargedbdata);
	}
	for(int32_t i = 0; i < (int32_t)fSmashEggDBData.GetSize() && i < fSmashEggDBData.GetMaxSize(); ++i) {
		::proto_ff::FestivalSmashEggDBData* temp_fsmasheggdbdata = msg.add_fsmasheggdbdata();
		fSmashEggDBData[i].write_to_pbmsg(*temp_fsmasheggdbdata);
	}
	for(int32_t i = 0; i < (int32_t)redPointClickData.GetSize() && i < redPointClickData.GetMaxSize(); ++i) {
		::proto_ff::ComPair64* temp_redpointclickdata = msg.add_redpointclickdata();
		redPointClickData[i].write_to_pbmsg(*temp_redpointclickdata);
	}
	for(int32_t i = 0; i < (int32_t)wVipDBData.GetSize() && i < wVipDBData.GetMaxSize(); ++i) {
		::proto_ff::WelfareVipGiftDBData* temp_wvipdbdata = msg.add_wvipdbdata();
		wVipDBData[i].write_to_pbmsg(*temp_wvipdbdata);
	}
	for(int32_t i = 0; i < (int32_t)wOnlineDBData.GetSize() && i < wOnlineDBData.GetMaxSize(); ++i) {
		::proto_ff::WelfareOnlineGiftDBData* temp_wonlinedbdata = msg.add_wonlinedbdata();
		wOnlineDBData[i].write_to_pbmsg(*temp_wonlinedbdata);
	}
	for(int32_t i = 0; i < (int32_t)fBossDBData.GetSize() && i < fBossDBData.GetMaxSize(); ++i) {
		::proto_ff::FestivalKillBossData* temp_fbossdbdata = msg.add_fbossdbdata();
		fBossDBData[i].write_to_pbmsg(*temp_fbossdbdata);
	}
	for(int32_t i = 0; i < (int32_t)fHuoYueDuDBData.GetSize() && i < fHuoYueDuDBData.GetMaxSize(); ++i) {
		::proto_ff::FestivalHuoYueDuDBData* temp_fhuoyuedudbdata = msg.add_fhuoyuedudbdata();
		fHuoYueDuDBData[i].write_to_pbmsg(*temp_fhuoyuedudbdata);
	}
	for(int32_t i = 0; i < (int32_t)fTurntableDBData.GetSize() && i < fTurntableDBData.GetMaxSize(); ++i) {
		::proto_ff::OperationTurntableDBData* temp_fturntabledbdata = msg.add_fturntabledbdata();
		fTurntableDBData[i].write_to_pbmsg(*temp_fturntabledbdata);
	}
	for(int32_t i = 0; i < (int32_t)TutorDBData.GetSize() && i < TutorDBData.GetMaxSize(); ++i) {
		::proto_ff::OperationTutorDBData* temp_tutordbdata = msg.add_tutordbdata();
		TutorDBData[i].write_to_pbmsg(*temp_tutordbdata);
	}
	for(int32_t i = 0; i < (int32_t)zhiChongData.GetSize() && i < zhiChongData.GetMaxSize(); ++i) {
		::proto_ff::FestivalZhiChongData* temp_zhichongdata = msg.add_zhichongdata();
		zhiChongData[i].write_to_pbmsg(*temp_zhichongdata);
	}
	for(int32_t i = 0; i < (int32_t)limitData.GetSize() && i < limitData.GetMaxSize(); ++i) {
		::proto_ff::limitInfo* temp_limitdata = msg.add_limitdata();
		limitData[i].write_to_pbmsg(*temp_limitdata);
	}
	for(int32_t i = 0; i < (int32_t)superData.GetSize() && i < superData.GetMaxSize(); ++i) {
		::proto_ff::FestivalSuperDBData* temp_superdata = msg.add_superdata();
		superData[i].write_to_pbmsg(*temp_superdata);
	}
	for(int32_t i = 0; i < (int32_t)fBigYanHuaDBData.GetSize() && i < fBigYanHuaDBData.GetMaxSize(); ++i) {
		::proto_ff::FestivalBigYanHuaDBData* temp_fbigyanhuadbdata = msg.add_fbigyanhuadbdata();
		fBigYanHuaDBData[i].write_to_pbmsg(*temp_fbigyanhuadbdata);
	}
	for(int32_t i = 0; i < (int32_t)worldBossData.GetSize() && i < worldBossData.GetMaxSize(); ++i) {
		::proto_ff::FestivalWorldBossData* temp_worldbossdata = msg.add_worldbossdata();
		worldBossData[i].write_to_pbmsg(*temp_worldbossdata);
	}
	for(int32_t i = 0; i < (int32_t)prerechargedata.GetSize() && i < prerechargedata.GetMaxSize(); ++i) {
		::proto_ff::FestivalPreRechargeData* temp_prerechargedata = msg.add_prerechargedata();
		prerechargedata[i].write_to_pbmsg(*temp_prerechargedata);
	}
	::proto_ff::OperateWingGiftData* temp_winggiftdata = msg.mutable_winggiftdata();
	winggiftdata.write_to_pbmsg(*temp_winggiftdata);
	::proto_ff::OperateRechargeGiftData* temp_rechargegiftdata = msg.mutable_rechargegiftdata();
	rechargegiftdata.write_to_pbmsg(*temp_rechargegiftdata);
	for(int32_t i = 0; i < (int32_t)superDoubleData.GetSize() && i < superDoubleData.GetMaxSize(); ++i) {
		::proto_ff::FestivalSuperDoubleDBData* temp_superdoubledata = msg.add_superdoubledata();
		superDoubleData[i].write_to_pbmsg(*temp_superdoubledata);
	}
	for(int32_t i = 0; i < (int32_t)IndultTaskDBData.GetSize() && i < IndultTaskDBData.GetMaxSize(); ++i) {
		::proto_ff::IndultTaskGroupEntry* temp_indulttaskdbdata = msg.add_indulttaskdbdata();
		IndultTaskDBData[i].write_to_pbmsg(*temp_indulttaskdbdata);
	}
	::proto_ff::ColPointsTaskData* temp_colpointstaskdata = msg.mutable_colpointstaskdata();
	ColPointsTaskData.write_to_pbmsg(*temp_colpointstaskdata);
}

void CharacterDBOperateData_s::read_from_pbmsg(const ::proto_ff::CharacterDBOperateData & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct CharacterDBOperateData_s));
	signInData.SetSize(msg.signindata_size() > signInData.GetMaxSize() ? signInData.GetMaxSize() : msg.signindata_size());
	for(int32_t i = 0; i < (int32_t)signInData.GetSize(); ++i) {
		const ::proto_ff::WelfareDailySignInDBData & temp_signindata = msg.signindata(i);
		signInData[i].read_from_pbmsg(temp_signindata);
	}
	loginGiftData.SetSize(msg.logingiftdata_size() > loginGiftData.GetMaxSize() ? loginGiftData.GetMaxSize() : msg.logingiftdata_size());
	for(int32_t i = 0; i < (int32_t)loginGiftData.GetSize(); ++i) {
		const ::proto_ff::WelfareLoginGiftDBData & temp_logingiftdata = msg.logingiftdata(i);
		loginGiftData[i].read_from_pbmsg(temp_logingiftdata);
	}
	levelGiftData.SetSize(msg.levelgiftdata_size() > levelGiftData.GetMaxSize() ? levelGiftData.GetMaxSize() : msg.levelgiftdata_size());
	for(int32_t i = 0; i < (int32_t)levelGiftData.GetSize(); ++i) {
		const ::proto_ff::WelfareLevelGiftDBData & temp_levelgiftdata = msg.levelgiftdata(i);
		levelGiftData[i].read_from_pbmsg(temp_levelgiftdata);
	}
	shopData.SetSize(msg.shopdata_size() > shopData.GetMaxSize() ? shopData.GetMaxSize() : msg.shopdata_size());
	for(int32_t i = 0; i < (int32_t)shopData.GetSize(); ++i) {
		const ::proto_ff::LimitShopData & temp_shopdata = msg.shopdata(i);
		shopData[i].read_from_pbmsg(temp_shopdata);
	}
	taskData.SetSize(msg.taskdata_size() > taskData.GetMaxSize() ? taskData.GetMaxSize() : msg.taskdata_size());
	for(int32_t i = 0; i < (int32_t)taskData.GetSize(); ++i) {
		const ::proto_ff::LimitTaskData & temp_taskdata = msg.taskdata(i);
		taskData[i].read_from_pbmsg(temp_taskdata);
	}
	wishData.SetSize(msg.wishdata_size() > wishData.GetMaxSize() ? wishData.GetMaxSize() : msg.wishdata_size());
	for(int32_t i = 0; i < (int32_t)wishData.GetSize(); ++i) {
		const ::proto_ff::WishDBData & temp_wishdata = msg.wishdata(i);
		wishData[i].read_from_pbmsg(temp_wishdata);
	}
	const ::proto_ff::OperateDailyRechargeData & temp_dailyrecharge = msg.dailyrecharge();
	dailyRecharge.read_from_pbmsg(temp_dailyrecharge);
	const ::proto_ff::OperateFirstRechargeData & temp_firstrecharge = msg.firstrecharge();
	firstRecharge.read_from_pbmsg(temp_firstrecharge);
	const ::proto_ff::OperateMoonCardData & temp_mooncard = msg.mooncard();
	moonCard.read_from_pbmsg(temp_mooncard);
	const ::proto_ff::OperateFundData & temp_novicefund = msg.novicefund();
	noviceFund.read_from_pbmsg(temp_novicefund);
	const ::proto_ff::OperateFundData & temp_growthfund = msg.growthfund();
	growthFund.read_from_pbmsg(temp_growthfund);
	const ::proto_ff::OperateFundData & temp_dreamfund = msg.dreamfund();
	dreamFund.read_from_pbmsg(temp_dreamfund);
	const ::proto_ff::OperateFundData & temp_novicefundhigh = msg.novicefundhigh();
	noviceFundHigh.read_from_pbmsg(temp_novicefundhigh);
	const ::proto_ff::OperateFundData & temp_growthfundhigh = msg.growthfundhigh();
	growthFundHigh.read_from_pbmsg(temp_growthfundhigh);
	const ::proto_ff::OperateFundData & temp_dreamfundhigh = msg.dreamfundhigh();
	dreamFundHigh.read_from_pbmsg(temp_dreamfundhigh);
	fInvestDBData.SetSize(msg.finvestdbdata_size() > fInvestDBData.GetMaxSize() ? fInvestDBData.GetMaxSize() : msg.finvestdbdata_size());
	for(int32_t i = 0; i < (int32_t)fInvestDBData.GetSize(); ++i) {
		const ::proto_ff::FestivalInvestDBData & temp_finvestdbdata = msg.finvestdbdata(i);
		fInvestDBData[i].read_from_pbmsg(temp_finvestdbdata);
	}
	fExchangeDBData.SetSize(msg.fexchangedbdata_size() > fExchangeDBData.GetMaxSize() ? fExchangeDBData.GetMaxSize() : msg.fexchangedbdata_size());
	for(int32_t i = 0; i < (int32_t)fExchangeDBData.GetSize(); ++i) {
		const ::proto_ff::FestivalExchangeDBData & temp_fexchangedbdata = msg.fexchangedbdata(i);
		fExchangeDBData[i].read_from_pbmsg(temp_fexchangedbdata);
	}
	fLoginDBData.SetSize(msg.flogindbdata_size() > fLoginDBData.GetMaxSize() ? fLoginDBData.GetMaxSize() : msg.flogindbdata_size());
	for(int32_t i = 0; i < (int32_t)fLoginDBData.GetSize(); ++i) {
		const ::proto_ff::FestivalLoginDBData & temp_flogindbdata = msg.flogindbdata(i);
		fLoginDBData[i].read_from_pbmsg(temp_flogindbdata);
	}
	fRechargeDBData.SetSize(msg.frechargedbdata_size() > fRechargeDBData.GetMaxSize() ? fRechargeDBData.GetMaxSize() : msg.frechargedbdata_size());
	for(int32_t i = 0; i < (int32_t)fRechargeDBData.GetSize(); ++i) {
		const ::proto_ff::FestivalTotalRechargeDBData & temp_frechargedbdata = msg.frechargedbdata(i);
		fRechargeDBData[i].read_from_pbmsg(temp_frechargedbdata);
	}
	fConsumptionDBData.SetSize(msg.fconsumptiondbdata_size() > fConsumptionDBData.GetMaxSize() ? fConsumptionDBData.GetMaxSize() : msg.fconsumptiondbdata_size());
	for(int32_t i = 0; i < (int32_t)fConsumptionDBData.GetSize(); ++i) {
		const ::proto_ff::FestivalConsumptionDBData & temp_fconsumptiondbdata = msg.fconsumptiondbdata(i);
		fConsumptionDBData[i].read_from_pbmsg(temp_fconsumptiondbdata);
	}
	fFirstRechargeDBData.SetSize(msg.ffirstrechargedbdata_size() > fFirstRechargeDBData.GetMaxSize() ? fFirstRechargeDBData.GetMaxSize() : msg.ffirstrechargedbdata_size());
	for(int32_t i = 0; i < (int32_t)fFirstRechargeDBData.GetSize(); ++i) {
		const ::proto_ff::FestivalFirstRechargeDBData & temp_ffirstrechargedbdata = msg.ffirstrechargedbdata(i);
		fFirstRechargeDBData[i].read_from_pbmsg(temp_ffirstrechargedbdata);
	}
	fYanHuaDBData.SetSize(msg.fyanhuadbdata_size() > fYanHuaDBData.GetMaxSize() ? fYanHuaDBData.GetMaxSize() : msg.fyanhuadbdata_size());
	for(int32_t i = 0; i < (int32_t)fYanHuaDBData.GetSize(); ++i) {
		const ::proto_ff::FestivalYanHuaDBData & temp_fyanhuadbdata = msg.fyanhuadbdata(i);
		fYanHuaDBData[i].read_from_pbmsg(temp_fyanhuadbdata);
	}
	fShopDBData.SetSize(msg.fshopdbdata_size() > fShopDBData.GetMaxSize() ? fShopDBData.GetMaxSize() : msg.fshopdbdata_size());
	for(int32_t i = 0; i < (int32_t)fShopDBData.GetSize(); ++i) {
		const ::proto_ff::FestivalShopDBData & temp_fshopdbdata = msg.fshopdbdata(i);
		fShopDBData[i].read_from_pbmsg(temp_fshopdbdata);
	}
	limitGiftDBData.SetSize(msg.limitgiftdbdata_size() > limitGiftDBData.GetMaxSize() ? limitGiftDBData.GetMaxSize() : msg.limitgiftdbdata_size());
	for(int32_t i = 0; i < (int32_t)limitGiftDBData.GetSize(); ++i) {
		const ::proto_ff::LimitGiftActiveDBData & temp_limitgiftdbdata = msg.limitgiftdbdata(i);
		limitGiftDBData[i].read_from_pbmsg(temp_limitgiftdbdata);
	}
	horoscopeDBData.SetSize(msg.horoscopedbdata_size() > horoscopeDBData.GetMaxSize() ? horoscopeDBData.GetMaxSize() : msg.horoscopedbdata_size());
	for(int32_t i = 0; i < (int32_t)horoscopeDBData.GetSize(); ++i) {
		const ::proto_ff::HoroscopeActiveDBData & temp_horoscopedbdata = msg.horoscopedbdata(i);
		horoscopeDBData[i].read_from_pbmsg(temp_horoscopedbdata);
	}
	festivalRechargeDBData.SetSize(msg.festivalrechargedbdata_size() > festivalRechargeDBData.GetMaxSize() ? festivalRechargeDBData.GetMaxSize() : msg.festivalrechargedbdata_size());
	for(int32_t i = 0; i < (int32_t)festivalRechargeDBData.GetSize(); ++i) {
		const ::proto_ff::FRechargeActiveDBData & temp_festivalrechargedbdata = msg.festivalrechargedbdata(i);
		festivalRechargeDBData[i].read_from_pbmsg(temp_festivalrechargedbdata);
	}
	fSmashEggDBData.SetSize(msg.fsmasheggdbdata_size() > fSmashEggDBData.GetMaxSize() ? fSmashEggDBData.GetMaxSize() : msg.fsmasheggdbdata_size());
	for(int32_t i = 0; i < (int32_t)fSmashEggDBData.GetSize(); ++i) {
		const ::proto_ff::FestivalSmashEggDBData & temp_fsmasheggdbdata = msg.fsmasheggdbdata(i);
		fSmashEggDBData[i].read_from_pbmsg(temp_fsmasheggdbdata);
	}
	redPointClickData.SetSize(msg.redpointclickdata_size() > redPointClickData.GetMaxSize() ? redPointClickData.GetMaxSize() : msg.redpointclickdata_size());
	for(int32_t i = 0; i < (int32_t)redPointClickData.GetSize(); ++i) {
		const ::proto_ff::ComPair64 & temp_redpointclickdata = msg.redpointclickdata(i);
		redPointClickData[i].read_from_pbmsg(temp_redpointclickdata);
	}
	wVipDBData.SetSize(msg.wvipdbdata_size() > wVipDBData.GetMaxSize() ? wVipDBData.GetMaxSize() : msg.wvipdbdata_size());
	for(int32_t i = 0; i < (int32_t)wVipDBData.GetSize(); ++i) {
		const ::proto_ff::WelfareVipGiftDBData & temp_wvipdbdata = msg.wvipdbdata(i);
		wVipDBData[i].read_from_pbmsg(temp_wvipdbdata);
	}
	wOnlineDBData.SetSize(msg.wonlinedbdata_size() > wOnlineDBData.GetMaxSize() ? wOnlineDBData.GetMaxSize() : msg.wonlinedbdata_size());
	for(int32_t i = 0; i < (int32_t)wOnlineDBData.GetSize(); ++i) {
		const ::proto_ff::WelfareOnlineGiftDBData & temp_wonlinedbdata = msg.wonlinedbdata(i);
		wOnlineDBData[i].read_from_pbmsg(temp_wonlinedbdata);
	}
	fBossDBData.SetSize(msg.fbossdbdata_size() > fBossDBData.GetMaxSize() ? fBossDBData.GetMaxSize() : msg.fbossdbdata_size());
	for(int32_t i = 0; i < (int32_t)fBossDBData.GetSize(); ++i) {
		const ::proto_ff::FestivalKillBossData & temp_fbossdbdata = msg.fbossdbdata(i);
		fBossDBData[i].read_from_pbmsg(temp_fbossdbdata);
	}
	fHuoYueDuDBData.SetSize(msg.fhuoyuedudbdata_size() > fHuoYueDuDBData.GetMaxSize() ? fHuoYueDuDBData.GetMaxSize() : msg.fhuoyuedudbdata_size());
	for(int32_t i = 0; i < (int32_t)fHuoYueDuDBData.GetSize(); ++i) {
		const ::proto_ff::FestivalHuoYueDuDBData & temp_fhuoyuedudbdata = msg.fhuoyuedudbdata(i);
		fHuoYueDuDBData[i].read_from_pbmsg(temp_fhuoyuedudbdata);
	}
	fTurntableDBData.SetSize(msg.fturntabledbdata_size() > fTurntableDBData.GetMaxSize() ? fTurntableDBData.GetMaxSize() : msg.fturntabledbdata_size());
	for(int32_t i = 0; i < (int32_t)fTurntableDBData.GetSize(); ++i) {
		const ::proto_ff::OperationTurntableDBData & temp_fturntabledbdata = msg.fturntabledbdata(i);
		fTurntableDBData[i].read_from_pbmsg(temp_fturntabledbdata);
	}
	TutorDBData.SetSize(msg.tutordbdata_size() > TutorDBData.GetMaxSize() ? TutorDBData.GetMaxSize() : msg.tutordbdata_size());
	for(int32_t i = 0; i < (int32_t)TutorDBData.GetSize(); ++i) {
		const ::proto_ff::OperationTutorDBData & temp_tutordbdata = msg.tutordbdata(i);
		TutorDBData[i].read_from_pbmsg(temp_tutordbdata);
	}
	zhiChongData.SetSize(msg.zhichongdata_size() > zhiChongData.GetMaxSize() ? zhiChongData.GetMaxSize() : msg.zhichongdata_size());
	for(int32_t i = 0; i < (int32_t)zhiChongData.GetSize(); ++i) {
		const ::proto_ff::FestivalZhiChongData & temp_zhichongdata = msg.zhichongdata(i);
		zhiChongData[i].read_from_pbmsg(temp_zhichongdata);
	}
	limitData.SetSize(msg.limitdata_size() > limitData.GetMaxSize() ? limitData.GetMaxSize() : msg.limitdata_size());
	for(int32_t i = 0; i < (int32_t)limitData.GetSize(); ++i) {
		const ::proto_ff::limitInfo & temp_limitdata = msg.limitdata(i);
		limitData[i].read_from_pbmsg(temp_limitdata);
	}
	superData.SetSize(msg.superdata_size() > superData.GetMaxSize() ? superData.GetMaxSize() : msg.superdata_size());
	for(int32_t i = 0; i < (int32_t)superData.GetSize(); ++i) {
		const ::proto_ff::FestivalSuperDBData & temp_superdata = msg.superdata(i);
		superData[i].read_from_pbmsg(temp_superdata);
	}
	fBigYanHuaDBData.SetSize(msg.fbigyanhuadbdata_size() > fBigYanHuaDBData.GetMaxSize() ? fBigYanHuaDBData.GetMaxSize() : msg.fbigyanhuadbdata_size());
	for(int32_t i = 0; i < (int32_t)fBigYanHuaDBData.GetSize(); ++i) {
		const ::proto_ff::FestivalBigYanHuaDBData & temp_fbigyanhuadbdata = msg.fbigyanhuadbdata(i);
		fBigYanHuaDBData[i].read_from_pbmsg(temp_fbigyanhuadbdata);
	}
	worldBossData.SetSize(msg.worldbossdata_size() > worldBossData.GetMaxSize() ? worldBossData.GetMaxSize() : msg.worldbossdata_size());
	for(int32_t i = 0; i < (int32_t)worldBossData.GetSize(); ++i) {
		const ::proto_ff::FestivalWorldBossData & temp_worldbossdata = msg.worldbossdata(i);
		worldBossData[i].read_from_pbmsg(temp_worldbossdata);
	}
	prerechargedata.SetSize(msg.prerechargedata_size() > prerechargedata.GetMaxSize() ? prerechargedata.GetMaxSize() : msg.prerechargedata_size());
	for(int32_t i = 0; i < (int32_t)prerechargedata.GetSize(); ++i) {
		const ::proto_ff::FestivalPreRechargeData & temp_prerechargedata = msg.prerechargedata(i);
		prerechargedata[i].read_from_pbmsg(temp_prerechargedata);
	}
	const ::proto_ff::OperateWingGiftData & temp_winggiftdata = msg.winggiftdata();
	winggiftdata.read_from_pbmsg(temp_winggiftdata);
	const ::proto_ff::OperateRechargeGiftData & temp_rechargegiftdata = msg.rechargegiftdata();
	rechargegiftdata.read_from_pbmsg(temp_rechargegiftdata);
	superDoubleData.SetSize(msg.superdoubledata_size() > superDoubleData.GetMaxSize() ? superDoubleData.GetMaxSize() : msg.superdoubledata_size());
	for(int32_t i = 0; i < (int32_t)superDoubleData.GetSize(); ++i) {
		const ::proto_ff::FestivalSuperDoubleDBData & temp_superdoubledata = msg.superdoubledata(i);
		superDoubleData[i].read_from_pbmsg(temp_superdoubledata);
	}
	IndultTaskDBData.SetSize(msg.indulttaskdbdata_size() > IndultTaskDBData.GetMaxSize() ? IndultTaskDBData.GetMaxSize() : msg.indulttaskdbdata_size());
	for(int32_t i = 0; i < (int32_t)IndultTaskDBData.GetSize(); ++i) {
		const ::proto_ff::IndultTaskGroupEntry & temp_indulttaskdbdata = msg.indulttaskdbdata(i);
		IndultTaskDBData[i].read_from_pbmsg(temp_indulttaskdbdata);
	}
	const ::proto_ff::ColPointsTaskData & temp_colpointstaskdata = msg.colpointstaskdata();
	ColPointsTaskData.read_from_pbmsg(temp_colpointstaskdata);
}

PlayerActiveAnswerData_s::PlayerActiveAnswerData_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int PlayerActiveAnswerData_s::CreateInit() {
	answerIndex = (uint32_t)0;
	allexp = (uint32_t)0;
	allmoney = (uint32_t)0;
	correctnum = (uint32_t)0;
	isGetReward = (uint32_t)0;
	lastAnswerTime = (uint64_t)0;
	return 0;
}

int PlayerActiveAnswerData_s::ResumeInit() {
	return 0;
}

void PlayerActiveAnswerData_s::write_to_pbmsg(::proto_ff::PlayerActiveAnswerData & msg) const {
	msg.set_answerindex((uint32_t)answerIndex);
	for(int32_t i = 0; i < (int32_t)answerList.GetSize() && i < answerList.GetMaxSize(); ++i) {
		msg.add_answerlist((uint32_t)answerList[i]);
	}
	msg.set_allexp((uint32_t)allexp);
	msg.set_allmoney((uint32_t)allmoney);
	msg.set_correctnum((uint32_t)correctnum);
	msg.set_isgetreward((uint32_t)isGetReward);
	msg.set_lastanswertime((uint64_t)lastAnswerTime);
}

void PlayerActiveAnswerData_s::read_from_pbmsg(const ::proto_ff::PlayerActiveAnswerData & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct PlayerActiveAnswerData_s));
	answerIndex = msg.answerindex();
	answerList.SetSize(msg.answerlist_size() > answerList.GetMaxSize() ? answerList.GetMaxSize() : msg.answerlist_size());
	for(int32_t i = 0; i < (int32_t)answerList.GetSize(); ++i) {
		answerList[i] = msg.answerlist(i);
	}
	allexp = msg.allexp();
	allmoney = msg.allmoney();
	correctnum = msg.correctnum();
	isGetReward = msg.isgetreward();
	lastAnswerTime = msg.lastanswertime();
}

CharacterDBActiveInfo_s::CharacterDBActiveInfo_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int CharacterDBActiveInfo_s::CreateInit() {
	return 0;
}

int CharacterDBActiveInfo_s::ResumeInit() {
	return 0;
}

void CharacterDBActiveInfo_s::write_to_pbmsg(::proto_ff::CharacterDBActiveInfo & msg) const {
	::proto_ff::PlayerActiveAnswerData* temp_playeractiveanswerinfo = msg.mutable_playeractiveanswerinfo();
	playerActiveAnswerInfo.write_to_pbmsg(*temp_playeractiveanswerinfo);
	::proto_ff::PlayerActiveAnswerData* temp_playeractivedailyanswerinfo = msg.mutable_playeractivedailyanswerinfo();
	playerActiveDailyAnswerInfo.write_to_pbmsg(*temp_playeractivedailyanswerinfo);
}

void CharacterDBActiveInfo_s::read_from_pbmsg(const ::proto_ff::CharacterDBActiveInfo & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct CharacterDBActiveInfo_s));
	const ::proto_ff::PlayerActiveAnswerData & temp_playeractiveanswerinfo = msg.playeractiveanswerinfo();
	playerActiveAnswerInfo.read_from_pbmsg(temp_playeractiveanswerinfo);
	const ::proto_ff::PlayerActiveAnswerData & temp_playeractivedailyanswerinfo = msg.playeractivedailyanswerinfo();
	playerActiveDailyAnswerInfo.read_from_pbmsg(temp_playeractivedailyanswerinfo);
}

PayCountDBProto_s::PayCountDBProto_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int PayCountDBProto_s::CreateInit() {
	charge_id = (int32_t)0;
	count = (uint32_t)0;
	return 0;
}

int PayCountDBProto_s::ResumeInit() {
	return 0;
}

void PayCountDBProto_s::write_to_pbmsg(::proto_ff::PayCountDBProto & msg) const {
	msg.set_charge_id((int32_t)charge_id);
	msg.set_count((uint32_t)count);
}

void PayCountDBProto_s::read_from_pbmsg(const ::proto_ff::PayCountDBProto & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct PayCountDBProto_s));
	charge_id = msg.charge_id();
	count = msg.count();
}

OfflineRetDBProto_s::OfflineRetDBProto_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int OfflineRetDBProto_s::CreateInit() {
	diamond = (int64_t)0;
	time = (uint64_t)0;
	freshtime = (uint64_t)0;
	return 0;
}

int OfflineRetDBProto_s::ResumeInit() {
	return 0;
}

void OfflineRetDBProto_s::write_to_pbmsg(::proto_ff::OfflineRetDBProto & msg) const {
	msg.set_diamond((int64_t)diamond);
	msg.set_time((uint64_t)time);
	msg.set_freshtime((uint64_t)freshtime);
}

void OfflineRetDBProto_s::read_from_pbmsg(const ::proto_ff::OfflineRetDBProto & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct OfflineRetDBProto_s));
	diamond = msg.diamond();
	time = msg.time();
	freshtime = msg.freshtime();
}

CharacterPayData_s::CharacterPayData_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int CharacterPayData_s::CreateInit() {
	rmb = (uint32_t)0;
	maxPayId = (uint32_t)0;
	today_rmb = (uint32_t)0;
	last_time = (uint64_t)0;
	pay_count_time = (uint64_t)0;
	diamond = (int64_t)0;
	real_rmb = (uint64_t)0;
	freshtime = (int64_t)0;
	openwindow = (int32_t)0;
	return 0;
}

int CharacterPayData_s::ResumeInit() {
	return 0;
}

void CharacterPayData_s::write_to_pbmsg(::proto_ff::CharacterPayData & msg) const {
	msg.set_rmb((uint32_t)rmb);
	msg.set_maxpayid((uint32_t)maxPayId);
	for(int32_t i = 0; i < (int32_t)payedProducts.GetSize() && i < payedProducts.GetMaxSize(); ++i) {
		msg.add_payedproducts((const char*)payedProducts[i].Get());
	}
	msg.set_today_rmb((uint32_t)today_rmb);
	msg.set_last_time((uint64_t)last_time);
	for(int32_t i = 0; i < (int32_t)pay_count.GetSize() && i < pay_count.GetMaxSize(); ++i) {
		::proto_ff::PayCountDBProto* temp_pay_count = msg.add_pay_count();
		pay_count[i].write_to_pbmsg(*temp_pay_count);
	}
	msg.set_pay_count_time((uint64_t)pay_count_time);
	msg.set_diamond((int64_t)diamond);
	msg.set_real_rmb((uint64_t)real_rmb);
	msg.set_freshtime((int64_t)freshtime);
	msg.set_openwindow((int32_t)openwindow);
	::proto_ff::OfflineRetDBProto* temp_offline_ret = msg.mutable_offline_ret();
	offline_ret.write_to_pbmsg(*temp_offline_ret);
}

void CharacterPayData_s::read_from_pbmsg(const ::proto_ff::CharacterPayData & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct CharacterPayData_s));
	rmb = msg.rmb();
	maxPayId = msg.maxpayid();
	payedProducts.SetSize(msg.payedproducts_size() > payedProducts.GetMaxSize() ? payedProducts.GetMaxSize() : msg.payedproducts_size());
	for(int32_t i = 0; i < (int32_t)payedProducts.GetSize(); ++i) {
		payedProducts[i].Copy(msg.payedproducts(i));
	}
	today_rmb = msg.today_rmb();
	last_time = msg.last_time();
	pay_count.SetSize(msg.pay_count_size() > pay_count.GetMaxSize() ? pay_count.GetMaxSize() : msg.pay_count_size());
	for(int32_t i = 0; i < (int32_t)pay_count.GetSize(); ++i) {
		const ::proto_ff::PayCountDBProto & temp_pay_count = msg.pay_count(i);
		pay_count[i].read_from_pbmsg(temp_pay_count);
	}
	pay_count_time = msg.pay_count_time();
	diamond = msg.diamond();
	real_rmb = msg.real_rmb();
	freshtime = msg.freshtime();
	openwindow = msg.openwindow();
	const ::proto_ff::OfflineRetDBProto & temp_offline_ret = msg.offline_ret();
	offline_ret.read_from_pbmsg(temp_offline_ret);
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
	for(int32_t i = 0; i < (int32_t)unlockIds.GetSize() && i < unlockIds.GetMaxSize(); ++i) {
		msg.add_unlockids((uint64_t)unlockIds[i]);
	}
}

void FunctionUnlockInfo_s::read_from_pbmsg(const ::proto_ff::FunctionUnlockInfo & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct FunctionUnlockInfo_s));
	unlockIds.SetSize(msg.unlockids_size() > unlockIds.GetMaxSize() ? unlockIds.GetMaxSize() : msg.unlockids_size());
	for(int32_t i = 0; i < (int32_t)unlockIds.GetSize(); ++i) {
		unlockIds[i] = msg.unlockids(i);
	}
}

EmblemSlot_s::EmblemSlot_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int EmblemSlot_s::CreateInit() {
	slotId = (uint32_t)0;
	groupId = (uint32_t)0;
	posId = (uint32_t)0;
	attrType = (uint32_t)0;
	open = (bool)0;
	itemId = (uint64_t)0;
	bind = (uint32_t)0;
	return 0;
}

int EmblemSlot_s::ResumeInit() {
	return 0;
}

void EmblemSlot_s::write_to_pbmsg(::proto_ff::EmblemSlot & msg) const {
	msg.set_slotid((uint32_t)slotId);
	msg.set_groupid((uint32_t)groupId);
	msg.set_posid((uint32_t)posId);
	msg.set_attrtype((uint32_t)attrType);
	msg.set_open((bool)open);
	msg.set_itemid((uint64_t)itemId);
	msg.set_bind((uint32_t)bind);
}

void EmblemSlot_s::read_from_pbmsg(const ::proto_ff::EmblemSlot & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct EmblemSlot_s));
	slotId = msg.slotid();
	groupId = msg.groupid();
	posId = msg.posid();
	attrType = msg.attrtype();
	open = msg.open();
	itemId = msg.itemid();
	bind = msg.bind();
}

CharacterDBEmblemData_s::CharacterDBEmblemData_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int CharacterDBEmblemData_s::CreateInit() {
	return 0;
}

int CharacterDBEmblemData_s::ResumeInit() {
	return 0;
}

void CharacterDBEmblemData_s::write_to_pbmsg(::proto_ff::CharacterDBEmblemData & msg) const {
	for(int32_t i = 0; i < (int32_t)slots.GetSize() && i < slots.GetMaxSize(); ++i) {
		::proto_ff::EmblemSlot* temp_slots = msg.add_slots();
		slots[i].write_to_pbmsg(*temp_slots);
	}
	for(int32_t i = 0; i < (int32_t)groupSuitIds.GetSize() && i < groupSuitIds.GetMaxSize(); ++i) {
		::proto_ff::ComPair* temp_groupsuitids = msg.add_groupsuitids();
		groupSuitIds[i].write_to_pbmsg(*temp_groupsuitids);
	}
	for(int32_t i = 0; i < (int32_t)suitSkillId.GetSize() && i < suitSkillId.GetMaxSize(); ++i) {
		::proto_ff::ComPair* temp_suitskillid = msg.add_suitskillid();
		suitSkillId[i].write_to_pbmsg(*temp_suitskillid);
	}
}

void CharacterDBEmblemData_s::read_from_pbmsg(const ::proto_ff::CharacterDBEmblemData & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct CharacterDBEmblemData_s));
	slots.SetSize(msg.slots_size() > slots.GetMaxSize() ? slots.GetMaxSize() : msg.slots_size());
	for(int32_t i = 0; i < (int32_t)slots.GetSize(); ++i) {
		const ::proto_ff::EmblemSlot & temp_slots = msg.slots(i);
		slots[i].read_from_pbmsg(temp_slots);
	}
	groupSuitIds.SetSize(msg.groupsuitids_size() > groupSuitIds.GetMaxSize() ? groupSuitIds.GetMaxSize() : msg.groupsuitids_size());
	for(int32_t i = 0; i < (int32_t)groupSuitIds.GetSize(); ++i) {
		const ::proto_ff::ComPair & temp_groupsuitids = msg.groupsuitids(i);
		groupSuitIds[i].read_from_pbmsg(temp_groupsuitids);
	}
	suitSkillId.SetSize(msg.suitskillid_size() > suitSkillId.GetMaxSize() ? suitSkillId.GetMaxSize() : msg.suitskillid_size());
	for(int32_t i = 0; i < (int32_t)suitSkillId.GetSize(); ++i) {
		const ::proto_ff::ComPair & temp_suitskillid = msg.suitskillid(i);
		suitSkillId[i].read_from_pbmsg(temp_suitskillid);
	}
}

CharacterDBIdentifyData_s::CharacterDBIdentifyData_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int CharacterDBIdentifyData_s::CreateInit() {
	return 0;
}

int CharacterDBIdentifyData_s::ResumeInit() {
	return 0;
}

void CharacterDBIdentifyData_s::write_to_pbmsg(::proto_ff::CharacterDBIdentifyData & msg) const {
	for(int32_t i = 0; i < (int32_t)identifys.GetSize() && i < identifys.GetMaxSize(); ++i) {
		::proto_ff::ComPair64* temp_identifys = msg.add_identifys();
		identifys[i].write_to_pbmsg(*temp_identifys);
	}
	for(int32_t i = 0; i < (int32_t)identifyfates.GetSize() && i < identifyfates.GetMaxSize(); ++i) {
		::proto_ff::ComPair64* temp_identifyfates = msg.add_identifyfates();
		identifyfates[i].write_to_pbmsg(*temp_identifyfates);
	}
}

void CharacterDBIdentifyData_s::read_from_pbmsg(const ::proto_ff::CharacterDBIdentifyData & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct CharacterDBIdentifyData_s));
	identifys.SetSize(msg.identifys_size() > identifys.GetMaxSize() ? identifys.GetMaxSize() : msg.identifys_size());
	for(int32_t i = 0; i < (int32_t)identifys.GetSize(); ++i) {
		const ::proto_ff::ComPair64 & temp_identifys = msg.identifys(i);
		identifys[i].read_from_pbmsg(temp_identifys);
	}
	identifyfates.SetSize(msg.identifyfates_size() > identifyfates.GetMaxSize() ? identifyfates.GetMaxSize() : msg.identifyfates_size());
	for(int32_t i = 0; i < (int32_t)identifyfates.GetSize(); ++i) {
		const ::proto_ff::ComPair64 & temp_identifyfates = msg.identifyfates(i);
		identifyfates[i].read_from_pbmsg(temp_identifyfates);
	}
}

ElementInfoData_s::ElementInfoData_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int ElementInfoData_s::CreateInit() {
	type = (uint32_t)0;
	level = (uint32_t)0;
	exp = (uint64_t)0;
	return 0;
}

int ElementInfoData_s::ResumeInit() {
	return 0;
}

void ElementInfoData_s::write_to_pbmsg(::proto_ff::ElementInfoData & msg) const {
	msg.set_type((uint32_t)type);
	msg.set_level((uint32_t)level);
	msg.set_exp((uint64_t)exp);
}

void ElementInfoData_s::read_from_pbmsg(const ::proto_ff::ElementInfoData & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct ElementInfoData_s));
	type = msg.type();
	level = msg.level();
	exp = msg.exp();
}

CharacterDBElementData_s::CharacterDBElementData_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int CharacterDBElementData_s::CreateInit() {
	return 0;
}

int CharacterDBElementData_s::ResumeInit() {
	return 0;
}

void CharacterDBElementData_s::write_to_pbmsg(::proto_ff::CharacterDBElementData & msg) const {
	for(int32_t i = 0; i < (int32_t)elements.GetSize() && i < elements.GetMaxSize(); ++i) {
		::proto_ff::ElementInfoData* temp_elements = msg.add_elements();
		elements[i].write_to_pbmsg(*temp_elements);
	}
	for(int32_t i = 0; i < (int32_t)fragments.GetSize() && i < fragments.GetMaxSize(); ++i) {
		::proto_ff::ComPair64* temp_fragments = msg.add_fragments();
		fragments[i].write_to_pbmsg(*temp_fragments);
	}
}

void CharacterDBElementData_s::read_from_pbmsg(const ::proto_ff::CharacterDBElementData & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct CharacterDBElementData_s));
	elements.SetSize(msg.elements_size() > elements.GetMaxSize() ? elements.GetMaxSize() : msg.elements_size());
	for(int32_t i = 0; i < (int32_t)elements.GetSize(); ++i) {
		const ::proto_ff::ElementInfoData & temp_elements = msg.elements(i);
		elements[i].read_from_pbmsg(temp_elements);
	}
	fragments.SetSize(msg.fragments_size() > fragments.GetMaxSize() ? fragments.GetMaxSize() : msg.fragments_size());
	for(int32_t i = 0; i < (int32_t)fragments.GetSize(); ++i) {
		const ::proto_ff::ComPair64 & temp_fragments = msg.fragments(i);
		fragments[i].read_from_pbmsg(temp_fragments);
	}
}

CharacterDBFashionData_s::CharacterDBFashionData_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int CharacterDBFashionData_s::CreateInit() {
	dressClothesFashionID = (uint64_t)0;
	dressWeaponFashionID = (uint64_t)0;
	return 0;
}

int CharacterDBFashionData_s::ResumeInit() {
	return 0;
}

void CharacterDBFashionData_s::write_to_pbmsg(::proto_ff::CharacterDBFashionData & msg) const {
	for(int32_t i = 0; i < (int32_t)fashions.GetSize() && i < fashions.GetMaxSize(); ++i) {
		::proto_ff::ComPair64* temp_fashions = msg.add_fashions();
		fashions[i].write_to_pbmsg(*temp_fashions);
	}
	msg.set_dressclothesfashionid((uint64_t)dressClothesFashionID);
	msg.set_dressweaponfashionid((uint64_t)dressWeaponFashionID);
}

void CharacterDBFashionData_s::read_from_pbmsg(const ::proto_ff::CharacterDBFashionData & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct CharacterDBFashionData_s));
	fashions.SetSize(msg.fashions_size() > fashions.GetMaxSize() ? fashions.GetMaxSize() : msg.fashions_size());
	for(int32_t i = 0; i < (int32_t)fashions.GetSize(); ++i) {
		const ::proto_ff::ComPair64 & temp_fashions = msg.fashions(i);
		fashions[i].read_from_pbmsg(temp_fashions);
	}
	dressClothesFashionID = msg.dressclothesfashionid();
	dressWeaponFashionID = msg.dressweaponfashionid();
}

CharacterDBWingData_s::CharacterDBWingData_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int CharacterDBWingData_s::CreateInit() {
	advanceWingExp = (uint64_t)0;
	advanceWingLev = (uint32_t)0;
	equipWingID = (uint64_t)0;
	isbreak = (int32_t)0;
	return 0;
}

int CharacterDBWingData_s::ResumeInit() {
	return 0;
}

void CharacterDBWingData_s::write_to_pbmsg(::proto_ff::CharacterDBWingData & msg) const {
	msg.set_advancewingexp((uint64_t)advanceWingExp);
	msg.set_advancewinglev((uint32_t)advanceWingLev);
	msg.set_equipwingid((uint64_t)equipWingID);
	for(int32_t i = 0; i < (int32_t)fantasyWings.GetSize() && i < fantasyWings.GetMaxSize(); ++i) {
		::proto_ff::ComPair64* temp_fantasywings = msg.add_fantasywings();
		fantasyWings[i].write_to_pbmsg(*temp_fantasywings);
	}
	for(int32_t i = 0; i < (int32_t)fragments.GetSize() && i < fragments.GetMaxSize(); ++i) {
		::proto_ff::ComPair64* temp_fragments = msg.add_fragments();
		fragments[i].write_to_pbmsg(*temp_fragments);
	}
	msg.set_isbreak((int32_t)isbreak);
}

void CharacterDBWingData_s::read_from_pbmsg(const ::proto_ff::CharacterDBWingData & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct CharacterDBWingData_s));
	advanceWingExp = msg.advancewingexp();
	advanceWingLev = msg.advancewinglev();
	equipWingID = msg.equipwingid();
	fantasyWings.SetSize(msg.fantasywings_size() > fantasyWings.GetMaxSize() ? fantasyWings.GetMaxSize() : msg.fantasywings_size());
	for(int32_t i = 0; i < (int32_t)fantasyWings.GetSize(); ++i) {
		const ::proto_ff::ComPair64 & temp_fantasywings = msg.fantasywings(i);
		fantasyWings[i].read_from_pbmsg(temp_fantasywings);
	}
	fragments.SetSize(msg.fragments_size() > fragments.GetMaxSize() ? fragments.GetMaxSize() : msg.fragments_size());
	for(int32_t i = 0; i < (int32_t)fragments.GetSize(); ++i) {
		const ::proto_ff::ComPair64 & temp_fragments = msg.fragments(i);
		fragments[i].read_from_pbmsg(temp_fragments);
	}
	isbreak = msg.isbreak();
}

CharacterDBPartnerData_s::CharacterDBPartnerData_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int CharacterDBPartnerData_s::CreateInit() {
	advancePartnerExp = (uint64_t)0;
	advancePartnerLev = (uint32_t)0;
	equipPartnerID = (uint64_t)0;
	commonPartnerExp = (uint64_t)0;
	autoSwallowFlag = (uint32_t)0;
	autoSwallowClass = (uint64_t)0;
	isbreak = (int32_t)0;
	return 0;
}

int CharacterDBPartnerData_s::ResumeInit() {
	return 0;
}

void CharacterDBPartnerData_s::write_to_pbmsg(::proto_ff::CharacterDBPartnerData & msg) const {
	msg.set_advancepartnerexp((uint64_t)advancePartnerExp);
	msg.set_advancepartnerlev((uint32_t)advancePartnerLev);
	msg.set_equippartnerid((uint64_t)equipPartnerID);
	for(int32_t i = 0; i < (int32_t)fantasyPartners.GetSize() && i < fantasyPartners.GetMaxSize(); ++i) {
		::proto_ff::ComPair64* temp_fantasypartners = msg.add_fantasypartners();
		fantasyPartners[i].write_to_pbmsg(*temp_fantasypartners);
	}
	for(int32_t i = 0; i < (int32_t)fragments.GetSize() && i < fragments.GetMaxSize(); ++i) {
		::proto_ff::ComPair64* temp_fragments = msg.add_fragments();
		fragments[i].write_to_pbmsg(*temp_fragments);
	}
	msg.set_commonpartnerexp((uint64_t)commonPartnerExp);
	msg.set_autoswallowflag((uint32_t)autoSwallowFlag);
	msg.set_autoswallowclass((uint64_t)autoSwallowClass);
	msg.set_isbreak((int32_t)isbreak);
}

void CharacterDBPartnerData_s::read_from_pbmsg(const ::proto_ff::CharacterDBPartnerData & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct CharacterDBPartnerData_s));
	advancePartnerExp = msg.advancepartnerexp();
	advancePartnerLev = msg.advancepartnerlev();
	equipPartnerID = msg.equippartnerid();
	fantasyPartners.SetSize(msg.fantasypartners_size() > fantasyPartners.GetMaxSize() ? fantasyPartners.GetMaxSize() : msg.fantasypartners_size());
	for(int32_t i = 0; i < (int32_t)fantasyPartners.GetSize(); ++i) {
		const ::proto_ff::ComPair64 & temp_fantasypartners = msg.fantasypartners(i);
		fantasyPartners[i].read_from_pbmsg(temp_fantasypartners);
	}
	fragments.SetSize(msg.fragments_size() > fragments.GetMaxSize() ? fragments.GetMaxSize() : msg.fragments_size());
	for(int32_t i = 0; i < (int32_t)fragments.GetSize(); ++i) {
		const ::proto_ff::ComPair64 & temp_fragments = msg.fragments(i);
		fragments[i].read_from_pbmsg(temp_fragments);
	}
	commonPartnerExp = msg.commonpartnerexp();
	autoSwallowFlag = msg.autoswallowflag();
	autoSwallowClass = msg.autoswallowclass();
	isbreak = msg.isbreak();
}

CharacterDBMountData_s::CharacterDBMountData_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int CharacterDBMountData_s::CreateInit() {
	mountID = (uint64_t)0;
	rideState = (uint32_t)0;
	return 0;
}

int CharacterDBMountData_s::ResumeInit() {
	return 0;
}

void CharacterDBMountData_s::write_to_pbmsg(::proto_ff::CharacterDBMountData & msg) const {
	for(int32_t i = 0; i < (int32_t)mounts.GetSize() && i < mounts.GetMaxSize(); ++i) {
		::proto_ff::ComPair64* temp_mounts = msg.add_mounts();
		mounts[i].write_to_pbmsg(*temp_mounts);
	}
	msg.set_mountid((uint64_t)mountID);
	msg.set_ridestate((uint32_t)rideState);
}

void CharacterDBMountData_s::read_from_pbmsg(const ::proto_ff::CharacterDBMountData & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct CharacterDBMountData_s));
	mounts.SetSize(msg.mounts_size() > mounts.GetMaxSize() ? mounts.GetMaxSize() : msg.mounts_size());
	for(int32_t i = 0; i < (int32_t)mounts.GetSize(); ++i) {
		const ::proto_ff::ComPair64 & temp_mounts = msg.mounts(i);
		mounts[i].read_from_pbmsg(temp_mounts);
	}
	mountID = msg.mountid();
	rideState = msg.ridestate();
}

PlayerBossDataInfo_s::PlayerBossDataInfo_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int PlayerBossDataInfo_s::CreateInit() {
	group_type = (int32_t)0;
	cur_num = (int32_t)0;
	max_num = (int32_t)0;
	vip_buy_num = (int32_t)0;
	boss_type = (int32_t)0;
	return 0;
}

int PlayerBossDataInfo_s::ResumeInit() {
	return 0;
}

void PlayerBossDataInfo_s::write_to_pbmsg(::proto_ff::PlayerBossDataInfo & msg) const {
	msg.set_group_type((int32_t)group_type);
	msg.set_cur_num((int32_t)cur_num);
	msg.set_max_num((int32_t)max_num);
	msg.set_vip_buy_num((int32_t)vip_buy_num);
	msg.set_boss_type((int32_t)boss_type);
}

void PlayerBossDataInfo_s::read_from_pbmsg(const ::proto_ff::PlayerBossDataInfo & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct PlayerBossDataInfo_s));
	group_type = msg.group_type();
	cur_num = msg.cur_num();
	max_num = msg.max_num();
	vip_buy_num = msg.vip_buy_num();
	boss_type = msg.boss_type();
}

CharacterDBBossAttentInfo_s::CharacterDBBossAttentInfo_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int CharacterDBBossAttentInfo_s::CreateInit() {
	id = (uint64_t)0;
	type = (int32_t)0;
	return 0;
}

int CharacterDBBossAttentInfo_s::ResumeInit() {
	return 0;
}

void CharacterDBBossAttentInfo_s::write_to_pbmsg(::proto_ff::CharacterDBBossAttentInfo & msg) const {
	msg.set_id((uint64_t)id);
	msg.set_type((int32_t)type);
}

void CharacterDBBossAttentInfo_s::read_from_pbmsg(const ::proto_ff::CharacterDBBossAttentInfo & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct CharacterDBBossAttentInfo_s));
	id = msg.id();
	type = msg.type();
}

CharacterDBBossData_s::CharacterDBBossData_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int CharacterDBBossData_s::CreateInit() {
	lastTime = (uint64_t)0;
	return 0;
}

int CharacterDBBossData_s::ResumeInit() {
	return 0;
}

void CharacterDBBossData_s::write_to_pbmsg(::proto_ff::CharacterDBBossData & msg) const {
	for(int32_t i = 0; i < (int32_t)infos.GetSize() && i < infos.GetMaxSize(); ++i) {
		::proto_ff::PlayerBossDataInfo* temp_infos = msg.add_infos();
		infos[i].write_to_pbmsg(*temp_infos);
	}
	msg.set_lasttime((uint64_t)lastTime);
	for(int32_t i = 0; i < (int32_t)attent_list.GetSize() && i < attent_list.GetMaxSize(); ++i) {
		msg.add_attent_list((int64_t)attent_list[i]);
	}
}

void CharacterDBBossData_s::read_from_pbmsg(const ::proto_ff::CharacterDBBossData & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct CharacterDBBossData_s));
	infos.SetSize(msg.infos_size() > infos.GetMaxSize() ? infos.GetMaxSize() : msg.infos_size());
	for(int32_t i = 0; i < (int32_t)infos.GetSize(); ++i) {
		const ::proto_ff::PlayerBossDataInfo & temp_infos = msg.infos(i);
		infos[i].read_from_pbmsg(temp_infos);
	}
	lastTime = msg.lasttime();
	attent_list.SetSize(msg.attent_list_size() > attent_list.GetMaxSize() ? attent_list.GetMaxSize() : msg.attent_list_size());
	for(int32_t i = 0; i < (int32_t)attent_list.GetSize(); ++i) {
		attent_list[i] = msg.attent_list(i);
	}
}

RedPlayerInfo_s::RedPlayerInfo_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int RedPlayerInfo_s::CreateInit() {
	cid = (uint64_t)0;
	time = (uint64_t)0;
	return 0;
}

int RedPlayerInfo_s::ResumeInit() {
	return 0;
}

void RedPlayerInfo_s::write_to_pbmsg(::proto_ff::RedPlayerInfo & msg) const {
	msg.set_cid((uint64_t)cid);
	msg.set_time((uint64_t)time);
}

void RedPlayerInfo_s::read_from_pbmsg(const ::proto_ff::RedPlayerInfo & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct RedPlayerInfo_s));
	cid = msg.cid();
	time = msg.time();
}

CharacterDBPvpData_s::CharacterDBPvpData_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int CharacterDBPvpData_s::CreateInit() {
	pk_mode = (uint32_t)0;
	pk_killing_value = (uint32_t)0;
	online_time = (uint64_t)0;
	kill_num = (int32_t)0;
	be_kill_num = (int32_t)0;
	lastTime = (int64_t)0;
	return 0;
}

int CharacterDBPvpData_s::ResumeInit() {
	return 0;
}

void CharacterDBPvpData_s::write_to_pbmsg(::proto_ff::CharacterDBPvpData & msg) const {
	msg.set_pk_mode((uint32_t)pk_mode);
	msg.set_pk_killing_value((uint32_t)pk_killing_value);
	for(int32_t i = 0; i < (int32_t)red_player.GetSize() && i < red_player.GetMaxSize(); ++i) {
		::proto_ff::RedPlayerInfo* temp_red_player = msg.add_red_player();
		red_player[i].write_to_pbmsg(*temp_red_player);
	}
	msg.set_online_time((uint64_t)online_time);
	msg.set_kill_num((int32_t)kill_num);
	msg.set_be_kill_num((int32_t)be_kill_num);
	msg.set_lasttime((int64_t)lastTime);
	msg.set_be_kill_name((const char*)be_kill_name.Get());
}

void CharacterDBPvpData_s::read_from_pbmsg(const ::proto_ff::CharacterDBPvpData & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct CharacterDBPvpData_s));
	pk_mode = msg.pk_mode();
	pk_killing_value = msg.pk_killing_value();
	red_player.SetSize(msg.red_player_size() > red_player.GetMaxSize() ? red_player.GetMaxSize() : msg.red_player_size());
	for(int32_t i = 0; i < (int32_t)red_player.GetSize(); ++i) {
		const ::proto_ff::RedPlayerInfo & temp_red_player = msg.red_player(i);
		red_player[i].read_from_pbmsg(temp_red_player);
	}
	online_time = msg.online_time();
	kill_num = msg.kill_num();
	be_kill_num = msg.be_kill_num();
	lastTime = msg.lasttime();
	be_kill_name.Copy(msg.be_kill_name());
}

CharacterDBTreasureData_s::CharacterDBTreasureData_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int CharacterDBTreasureData_s::CreateInit() {
	advanceTreasureExp = (uint64_t)0;
	advanceTreasureLev = (uint32_t)0;
	equipTreasureID = (uint64_t)0;
	skillTreasureID = (uint64_t)0;
	isbreak = (int32_t)0;
	return 0;
}

int CharacterDBTreasureData_s::ResumeInit() {
	return 0;
}

void CharacterDBTreasureData_s::write_to_pbmsg(::proto_ff::CharacterDBTreasureData & msg) const {
	msg.set_advancetreasureexp((uint64_t)advanceTreasureExp);
	msg.set_advancetreasurelev((uint32_t)advanceTreasureLev);
	msg.set_equiptreasureid((uint64_t)equipTreasureID);
	for(int32_t i = 0; i < (int32_t)fantasyTreasures.GetSize() && i < fantasyTreasures.GetMaxSize(); ++i) {
		::proto_ff::ComPair64* temp_fantasytreasures = msg.add_fantasytreasures();
		fantasyTreasures[i].write_to_pbmsg(*temp_fantasytreasures);
	}
	for(int32_t i = 0; i < (int32_t)fragments.GetSize() && i < fragments.GetMaxSize(); ++i) {
		::proto_ff::ComPair64* temp_fragments = msg.add_fragments();
		fragments[i].write_to_pbmsg(*temp_fragments);
	}
	msg.set_skilltreasureid((uint64_t)skillTreasureID);
	msg.set_isbreak((int32_t)isbreak);
}

void CharacterDBTreasureData_s::read_from_pbmsg(const ::proto_ff::CharacterDBTreasureData & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct CharacterDBTreasureData_s));
	advanceTreasureExp = msg.advancetreasureexp();
	advanceTreasureLev = msg.advancetreasurelev();
	equipTreasureID = msg.equiptreasureid();
	fantasyTreasures.SetSize(msg.fantasytreasures_size() > fantasyTreasures.GetMaxSize() ? fantasyTreasures.GetMaxSize() : msg.fantasytreasures_size());
	for(int32_t i = 0; i < (int32_t)fantasyTreasures.GetSize(); ++i) {
		const ::proto_ff::ComPair64 & temp_fantasytreasures = msg.fantasytreasures(i);
		fantasyTreasures[i].read_from_pbmsg(temp_fantasytreasures);
	}
	fragments.SetSize(msg.fragments_size() > fragments.GetMaxSize() ? fragments.GetMaxSize() : msg.fragments_size());
	for(int32_t i = 0; i < (int32_t)fragments.GetSize(); ++i) {
		const ::proto_ff::ComPair64 & temp_fragments = msg.fragments(i);
		fragments[i].read_from_pbmsg(temp_fragments);
	}
	skillTreasureID = msg.skilltreasureid();
	isbreak = msg.isbreak();
}

ArtifactInfo_s::ArtifactInfo_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int ArtifactInfo_s::CreateInit() {
	id = (uint64_t)0;
	star_lv = (int32_t)0;
	return 0;
}

int ArtifactInfo_s::ResumeInit() {
	return 0;
}

void ArtifactInfo_s::write_to_pbmsg(::proto_ff::ArtifactInfo & msg) const {
	msg.set_id((uint64_t)id);
	msg.set_star_lv((int32_t)star_lv);
}

void ArtifactInfo_s::read_from_pbmsg(const ::proto_ff::ArtifactInfo & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct ArtifactInfo_s));
	id = msg.id();
	star_lv = msg.star_lv();
}

CharacterDBArtifactData_s::CharacterDBArtifactData_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int CharacterDBArtifactData_s::CreateInit() {
	dress_id = (uint64_t)0;
	return 0;
}

int CharacterDBArtifactData_s::ResumeInit() {
	return 0;
}

void CharacterDBArtifactData_s::write_to_pbmsg(::proto_ff::CharacterDBArtifactData & msg) const {
	for(int32_t i = 0; i < (int32_t)infos.GetSize() && i < infos.GetMaxSize(); ++i) {
		::proto_ff::ArtifactInfo* temp_infos = msg.add_infos();
		infos[i].write_to_pbmsg(*temp_infos);
	}
	msg.set_dress_id((uint64_t)dress_id);
}

void CharacterDBArtifactData_s::read_from_pbmsg(const ::proto_ff::CharacterDBArtifactData & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct CharacterDBArtifactData_s));
	infos.SetSize(msg.infos_size() > infos.GetMaxSize() ? infos.GetMaxSize() : msg.infos_size());
	for(int32_t i = 0; i < (int32_t)infos.GetSize(); ++i) {
		const ::proto_ff::ArtifactInfo & temp_infos = msg.infos(i);
		infos[i].read_from_pbmsg(temp_infos);
	}
	dress_id = msg.dress_id();
}

CharacterDBFateStarData_s::CharacterDBFateStarData_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int CharacterDBFateStarData_s::CreateInit() {
	freeTime = (uint64_t)0;
	towerLevel = (uint32_t)0;
	nbless = (uint32_t)0;
	curnum = (uint32_t)0;
	lasttime = (uint64_t)0;
	return 0;
}

int CharacterDBFateStarData_s::ResumeInit() {
	return 0;
}

void CharacterDBFateStarData_s::write_to_pbmsg(::proto_ff::CharacterDBFateStarData & msg) const {
	msg.set_freetime((uint64_t)freeTime);
	msg.set_towerlevel((uint32_t)towerLevel);
	msg.set_nbless((uint32_t)nbless);
	for(int32_t i = 0; i < (int32_t)soltData.GetSize() && i < soltData.GetMaxSize(); ++i) {
		::proto_ff::ComPair* temp_soltdata = msg.add_soltdata();
		soltData[i].write_to_pbmsg(*temp_soltdata);
	}
	for(int32_t i = 0; i < (int32_t)equipStars.GetSize() && i < equipStars.GetMaxSize(); ++i) {
		::proto_ff::ItemProtoInfo* temp_equipstars = msg.add_equipstars();
		equipStars[i].write_to_pbmsg(*temp_equipstars);
	}
	msg.set_curnum((uint32_t)curnum);
	msg.set_lasttime((uint64_t)lasttime);
}

void CharacterDBFateStarData_s::read_from_pbmsg(const ::proto_ff::CharacterDBFateStarData & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct CharacterDBFateStarData_s));
	freeTime = msg.freetime();
	towerLevel = msg.towerlevel();
	nbless = msg.nbless();
	soltData.SetSize(msg.soltdata_size() > soltData.GetMaxSize() ? soltData.GetMaxSize() : msg.soltdata_size());
	for(int32_t i = 0; i < (int32_t)soltData.GetSize(); ++i) {
		const ::proto_ff::ComPair & temp_soltdata = msg.soltdata(i);
		soltData[i].read_from_pbmsg(temp_soltdata);
	}
	equipStars.SetSize(msg.equipstars_size() > equipStars.GetMaxSize() ? equipStars.GetMaxSize() : msg.equipstars_size());
	for(int32_t i = 0; i < (int32_t)equipStars.GetSize(); ++i) {
		const ::proto_ff::ItemProtoInfo & temp_equipstars = msg.equipstars(i);
		equipStars[i].read_from_pbmsg(temp_equipstars);
	}
	curnum = msg.curnum();
	lasttime = msg.lasttime();
}

CharacterDBConvoyData_s::CharacterDBConvoyData_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int CharacterDBConvoyData_s::CreateInit() {
	doTimes = (uint32_t)0;
	convoyDate = (uint32_t)0;
	escortid = (uint64_t)0;
	acceptTime = (uint64_t)0;
	refreshTimes = (uint32_t)0;
	selectEscortId = (uint64_t)0;
	refreshTimeStamp = (uint64_t)0;
	LastResetTime = (uint64_t)0;
	return 0;
}

int CharacterDBConvoyData_s::ResumeInit() {
	return 0;
}

void CharacterDBConvoyData_s::write_to_pbmsg(::proto_ff::CharacterDBConvoyData & msg) const {
	msg.set_dotimes((uint32_t)doTimes);
	msg.set_convoydate((uint32_t)convoyDate);
	msg.set_escortid((uint64_t)escortid);
	msg.set_accepttime((uint64_t)acceptTime);
	msg.set_refreshtimes((uint32_t)refreshTimes);
	msg.set_selectescortid((uint64_t)selectEscortId);
	msg.set_refreshtimestamp((uint64_t)refreshTimeStamp);
	msg.set_lastresettime((uint64_t)LastResetTime);
}

void CharacterDBConvoyData_s::read_from_pbmsg(const ::proto_ff::CharacterDBConvoyData & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct CharacterDBConvoyData_s));
	doTimes = msg.dotimes();
	convoyDate = msg.convoydate();
	escortid = msg.escortid();
	acceptTime = msg.accepttime();
	refreshTimes = msg.refreshtimes();
	selectEscortId = msg.selectescortid();
	refreshTimeStamp = msg.refreshtimestamp();
	LastResetTime = msg.lastresettime();
}

CharacterDBDailyEntry_s::CharacterDBDailyEntry_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int CharacterDBDailyEntry_s::CreateInit() {
	cfg_id = (uint64_t)0;
	cur_num = (int32_t)0;
	return 0;
}

int CharacterDBDailyEntry_s::ResumeInit() {
	return 0;
}

void CharacterDBDailyEntry_s::write_to_pbmsg(::proto_ff::CharacterDBDailyEntry & msg) const {
	msg.set_cfg_id((uint64_t)cfg_id);
	msg.set_cur_num((int32_t)cur_num);
}

void CharacterDBDailyEntry_s::read_from_pbmsg(const ::proto_ff::CharacterDBDailyEntry & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct CharacterDBDailyEntry_s));
	cfg_id = msg.cfg_id();
	cur_num = msg.cur_num();
}

CharacterDBDailyData_s::CharacterDBDailyData_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int CharacterDBDailyData_s::CreateInit() {
	lasttime = (uint64_t)0;
	return 0;
}

int CharacterDBDailyData_s::ResumeInit() {
	return 0;
}

void CharacterDBDailyData_s::write_to_pbmsg(::proto_ff::CharacterDBDailyData & msg) const {
	for(int32_t i = 0; i < (int32_t)daily_entry.GetSize() && i < daily_entry.GetMaxSize(); ++i) {
		::proto_ff::CharacterDBDailyEntry* temp_daily_entry = msg.add_daily_entry();
		daily_entry[i].write_to_pbmsg(*temp_daily_entry);
	}
	for(int32_t i = 0; i < (int32_t)rewards.GetSize() && i < rewards.GetMaxSize(); ++i) {
		msg.add_rewards((uint64_t)rewards[i]);
	}
	msg.set_lasttime((uint64_t)lasttime);
}

void CharacterDBDailyData_s::read_from_pbmsg(const ::proto_ff::CharacterDBDailyData & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct CharacterDBDailyData_s));
	daily_entry.SetSize(msg.daily_entry_size() > daily_entry.GetMaxSize() ? daily_entry.GetMaxSize() : msg.daily_entry_size());
	for(int32_t i = 0; i < (int32_t)daily_entry.GetSize(); ++i) {
		const ::proto_ff::CharacterDBDailyEntry & temp_daily_entry = msg.daily_entry(i);
		daily_entry[i].read_from_pbmsg(temp_daily_entry);
	}
	rewards.SetSize(msg.rewards_size() > rewards.GetMaxSize() ? rewards.GetMaxSize() : msg.rewards_size());
	for(int32_t i = 0; i < (int32_t)rewards.GetSize(); ++i) {
		rewards[i] = msg.rewards(i);
	}
	lasttime = msg.lasttime();
}

FieldCylstalInfo_s::FieldCylstalInfo_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int FieldCylstalInfo_s::CreateInit() {
	slotIndex = (int32_t)0;
	itemid = (int64_t)0;
	return 0;
}

int FieldCylstalInfo_s::ResumeInit() {
	return 0;
}

void FieldCylstalInfo_s::write_to_pbmsg(::proto_ff::FieldCylstalInfo & msg) const {
	msg.set_slotindex((int32_t)slotIndex);
	msg.set_itemid((int64_t)itemid);
}

void FieldCylstalInfo_s::read_from_pbmsg(const ::proto_ff::FieldCylstalInfo & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct FieldCylstalInfo_s));
	slotIndex = msg.slotindex();
	itemid = msg.itemid();
}

FieldExInfo_s::FieldExInfo_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int FieldExInfo_s::CreateInit() {
	actived = (int32_t)0;
	fieldId = (uint64_t)0;
	fightNum = (uint64_t)0;
	first_active = (bool)0;
	return 0;
}

int FieldExInfo_s::ResumeInit() {
	return 0;
}

void FieldExInfo_s::write_to_pbmsg(::proto_ff::FieldExInfo & msg) const {
	msg.set_actived((int32_t)actived);
	for(int32_t i = 0; i < (int32_t)slotInfos.GetSize() && i < slotInfos.GetMaxSize(); ++i) {
		::proto_ff::ItemProtoInfo* temp_slotinfos = msg.add_slotinfos();
		slotInfos[i].write_to_pbmsg(*temp_slotinfos);
	}
	msg.set_fieldid((uint64_t)fieldId);
	msg.set_fightnum((uint64_t)fightNum);
	for(int32_t i = 0; i < (int32_t)cylstalInfos.GetSize() && i < cylstalInfos.GetMaxSize(); ++i) {
		::proto_ff::FieldCylstalInfo* temp_cylstalinfos = msg.add_cylstalinfos();
		cylstalInfos[i].write_to_pbmsg(*temp_cylstalinfos);
	}
	msg.set_first_active((bool)first_active);
}

void FieldExInfo_s::read_from_pbmsg(const ::proto_ff::FieldExInfo & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct FieldExInfo_s));
	actived = msg.actived();
	slotInfos.SetSize(msg.slotinfos_size() > slotInfos.GetMaxSize() ? slotInfos.GetMaxSize() : msg.slotinfos_size());
	for(int32_t i = 0; i < (int32_t)slotInfos.GetSize(); ++i) {
		const ::proto_ff::ItemProtoInfo & temp_slotinfos = msg.slotinfos(i);
		slotInfos[i].read_from_pbmsg(temp_slotinfos);
	}
	fieldId = msg.fieldid();
	fightNum = msg.fightnum();
	cylstalInfos.SetSize(msg.cylstalinfos_size() > cylstalInfos.GetMaxSize() ? cylstalInfos.GetMaxSize() : msg.cylstalinfos_size());
	for(int32_t i = 0; i < (int32_t)cylstalInfos.GetSize(); ++i) {
		const ::proto_ff::FieldCylstalInfo & temp_cylstalinfos = msg.cylstalinfos(i);
		cylstalInfos[i].read_from_pbmsg(temp_cylstalinfos);
	}
	first_active = msg.first_active();
}

CharacterDBFieldData_s::CharacterDBFieldData_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int CharacterDBFieldData_s::CreateInit() {
	curExp = (uint64_t)0;
	maxNum = (int32_t)0;
	return 0;
}

int CharacterDBFieldData_s::ResumeInit() {
	return 0;
}

void CharacterDBFieldData_s::write_to_pbmsg(::proto_ff::CharacterDBFieldData & msg) const {
	for(int32_t i = 0; i < (int32_t)fieldInfos.GetSize() && i < fieldInfos.GetMaxSize(); ++i) {
		::proto_ff::FieldExInfo* temp_fieldinfos = msg.add_fieldinfos();
		fieldInfos[i].write_to_pbmsg(*temp_fieldinfos);
	}
	msg.set_curexp((uint64_t)curExp);
	msg.set_maxnum((int32_t)maxNum);
}

void CharacterDBFieldData_s::read_from_pbmsg(const ::proto_ff::CharacterDBFieldData & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct CharacterDBFieldData_s));
	fieldInfos.SetSize(msg.fieldinfos_size() > fieldInfos.GetMaxSize() ? fieldInfos.GetMaxSize() : msg.fieldinfos_size());
	for(int32_t i = 0; i < (int32_t)fieldInfos.GetSize(); ++i) {
		const ::proto_ff::FieldExInfo & temp_fieldinfos = msg.fieldinfos(i);
		fieldInfos[i].read_from_pbmsg(temp_fieldinfos);
	}
	curExp = msg.curexp();
	maxNum = msg.maxnum();
}

vipGiftDBData_s::vipGiftDBData_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int vipGiftDBData_s::CreateInit() {
	giftId = (uint64_t)0;
	activeTime = (uint64_t)0;
	lastGetTime = (uint64_t)0;
	return 0;
}

int vipGiftDBData_s::ResumeInit() {
	return 0;
}

void vipGiftDBData_s::write_to_pbmsg(::proto_ff::vipGiftDBData & msg) const {
	msg.set_giftid((uint64_t)giftId);
	msg.set_activetime((uint64_t)activeTime);
	msg.set_lastgettime((uint64_t)lastGetTime);
}

void vipGiftDBData_s::read_from_pbmsg(const ::proto_ff::vipGiftDBData & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct vipGiftDBData_s));
	giftId = msg.giftid();
	activeTime = msg.activetime();
	lastGetTime = msg.lastgettime();
}

VipTCardInfo_s::VipTCardInfo_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int VipTCardInfo_s::CreateInit() {
	id = (int32_t)0;
	endTime = (int64_t)0;
	state = (int32_t)0;
	rewardState = (int32_t)0;
	return 0;
}

int VipTCardInfo_s::ResumeInit() {
	return 0;
}

void VipTCardInfo_s::write_to_pbmsg(::proto_ff::VipTCardInfo & msg) const {
	msg.set_id((int32_t)id);
	msg.set_endtime((int64_t)endTime);
	msg.set_state((int32_t)state);
	msg.set_rewardstate((int32_t)rewardState);
}

void VipTCardInfo_s::read_from_pbmsg(const ::proto_ff::VipTCardInfo & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct VipTCardInfo_s));
	id = msg.id();
	endTime = msg.endtime();
	state = msg.state();
	rewardState = msg.rewardstate();
}

VipTCardData_s::VipTCardData_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int VipTCardData_s::CreateInit() {
	giftState = (int32_t)0;
	point = (int32_t)0;
	return 0;
}

int VipTCardData_s::ResumeInit() {
	return 0;
}

void VipTCardData_s::write_to_pbmsg(::proto_ff::VipTCardData & msg) const {
	for(int32_t i = 0; i < (int32_t)cardInfo.GetSize() && i < cardInfo.GetMaxSize(); ++i) {
		::proto_ff::VipTCardInfo* temp_cardinfo = msg.add_cardinfo();
		cardInfo[i].write_to_pbmsg(*temp_cardinfo);
	}
	msg.set_giftstate((int32_t)giftState);
	msg.set_point((int32_t)point);
}

void VipTCardData_s::read_from_pbmsg(const ::proto_ff::VipTCardData & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct VipTCardData_s));
	cardInfo.SetSize(msg.cardinfo_size() > cardInfo.GetMaxSize() ? cardInfo.GetMaxSize() : msg.cardinfo_size());
	for(int32_t i = 0; i < (int32_t)cardInfo.GetSize(); ++i) {
		const ::proto_ff::VipTCardInfo & temp_cardinfo = msg.cardinfo(i);
		cardInfo[i].read_from_pbmsg(temp_cardinfo);
	}
	giftState = msg.giftstate();
	point = msg.point();
}

CharacterDBVipData_s::CharacterDBVipData_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int CharacterDBVipData_s::CreateInit() {
	vipState = (uint32_t)0;
	vipExp = (uint64_t)0;
	getRewardTime = (uint64_t)0;
	expDiamond = (uint64_t)0;
	cardLastTime = (int64_t)0;
	curAddVipExp = (int64_t)0;
	point = (int32_t)0;
	return 0;
}

int CharacterDBVipData_s::ResumeInit() {
	return 0;
}

void CharacterDBVipData_s::write_to_pbmsg(::proto_ff::CharacterDBVipData & msg) const {
	msg.set_vipstate((uint32_t)vipState);
	msg.set_vipexp((uint64_t)vipExp);
	msg.set_getrewardtime((uint64_t)getRewardTime);
	msg.set_expdiamond((uint64_t)expDiamond);
	for(int32_t i = 0; i < (int32_t)timeLimitExp.GetSize() && i < timeLimitExp.GetMaxSize(); ++i) {
		::proto_ff::ComPair64* temp_timelimitexp = msg.add_timelimitexp();
		timeLimitExp[i].write_to_pbmsg(*temp_timelimitexp);
	}
	for(int32_t i = 0; i < (int32_t)vipGift.GetSize() && i < vipGift.GetMaxSize(); ++i) {
		::proto_ff::vipGiftDBData* temp_vipgift = msg.add_vipgift();
		vipGift[i].write_to_pbmsg(*temp_vipgift);
	}
	::proto_ff::VipTCardData* temp_carddata = msg.mutable_carddata();
	cardData.write_to_pbmsg(*temp_carddata);
	msg.set_cardlasttime((int64_t)cardLastTime);
	msg.set_curaddvipexp((int64_t)curAddVipExp);
	msg.set_point((int32_t)point);
}

void CharacterDBVipData_s::read_from_pbmsg(const ::proto_ff::CharacterDBVipData & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct CharacterDBVipData_s));
	vipState = msg.vipstate();
	vipExp = msg.vipexp();
	getRewardTime = msg.getrewardtime();
	expDiamond = msg.expdiamond();
	timeLimitExp.SetSize(msg.timelimitexp_size() > timeLimitExp.GetMaxSize() ? timeLimitExp.GetMaxSize() : msg.timelimitexp_size());
	for(int32_t i = 0; i < (int32_t)timeLimitExp.GetSize(); ++i) {
		const ::proto_ff::ComPair64 & temp_timelimitexp = msg.timelimitexp(i);
		timeLimitExp[i].read_from_pbmsg(temp_timelimitexp);
	}
	vipGift.SetSize(msg.vipgift_size() > vipGift.GetMaxSize() ? vipGift.GetMaxSize() : msg.vipgift_size());
	for(int32_t i = 0; i < (int32_t)vipGift.GetSize(); ++i) {
		const ::proto_ff::vipGiftDBData & temp_vipgift = msg.vipgift(i);
		vipGift[i].read_from_pbmsg(temp_vipgift);
	}
	const ::proto_ff::VipTCardData & temp_carddata = msg.carddata();
	cardData.read_from_pbmsg(temp_carddata);
	cardLastTime = msg.cardlasttime();
	curAddVipExp = msg.curaddvipexp();
	point = msg.point();
}

CharacterDBMallData_s::CharacterDBMallData_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int CharacterDBMallData_s::CreateInit() {
	refreshTime = (uint64_t)0;
	dailyRefreshTime = (uint64_t)0;
	refreshNum = (int32_t)0;
	return 0;
}

int CharacterDBMallData_s::ResumeInit() {
	return 0;
}

void CharacterDBMallData_s::write_to_pbmsg(::proto_ff::CharacterDBMallData & msg) const {
	msg.set_refreshtime((uint64_t)refreshTime);
	for(int32_t i = 0; i < (int32_t)goodsInfo.GetSize() && i < goodsInfo.GetMaxSize(); ++i) {
		::proto_ff::ComPair64* temp_goodsinfo = msg.add_goodsinfo();
		goodsInfo[i].write_to_pbmsg(*temp_goodsinfo);
	}
	msg.set_dailyrefreshtime((uint64_t)dailyRefreshTime);
	msg.set_refreshnum((int32_t)refreshNum);
}

void CharacterDBMallData_s::read_from_pbmsg(const ::proto_ff::CharacterDBMallData & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct CharacterDBMallData_s));
	refreshTime = msg.refreshtime();
	goodsInfo.SetSize(msg.goodsinfo_size() > goodsInfo.GetMaxSize() ? goodsInfo.GetMaxSize() : msg.goodsinfo_size());
	for(int32_t i = 0; i < (int32_t)goodsInfo.GetSize(); ++i) {
		const ::proto_ff::ComPair64 & temp_goodsinfo = msg.goodsinfo(i);
		goodsInfo[i].read_from_pbmsg(temp_goodsinfo);
	}
	dailyRefreshTime = msg.dailyrefreshtime();
	refreshNum = msg.refreshnum();
}

GodhoodSlot_s::GodhoodSlot_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int GodhoodSlot_s::CreateInit() {
	idx = (uint32_t)0;
	open = (bool)0;
	return 0;
}

int GodhoodSlot_s::ResumeInit() {
	return 0;
}

void GodhoodSlot_s::write_to_pbmsg(::proto_ff::GodhoodSlot & msg) const {
	msg.set_idx((uint32_t)idx);
	msg.set_open((bool)open);
	::proto_ff::ItemProtoInfo* temp_item = msg.mutable_item();
	item.write_to_pbmsg(*temp_item);
}

void GodhoodSlot_s::read_from_pbmsg(const ::proto_ff::GodhoodSlot & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct GodhoodSlot_s));
	idx = msg.idx();
	open = msg.open();
	const ::proto_ff::ItemProtoInfo & temp_item = msg.item();
	item.read_from_pbmsg(temp_item);
}

CharacterDBGodhoodData_s::CharacterDBGodhoodData_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int CharacterDBGodhoodData_s::CreateInit() {
	return 0;
}

int CharacterDBGodhoodData_s::ResumeInit() {
	return 0;
}

void CharacterDBGodhoodData_s::write_to_pbmsg(::proto_ff::CharacterDBGodhoodData & msg) const {
	for(int32_t i = 0; i < (int32_t)godhoodSlot.GetSize() && i < godhoodSlot.GetMaxSize(); ++i) {
		::proto_ff::GodhoodSlot* temp_godhoodslot = msg.add_godhoodslot();
		godhoodSlot[i].write_to_pbmsg(*temp_godhoodslot);
	}
}

void CharacterDBGodhoodData_s::read_from_pbmsg(const ::proto_ff::CharacterDBGodhoodData & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct CharacterDBGodhoodData_s));
	godhoodSlot.SetSize(msg.godhoodslot_size() > godhoodSlot.GetMaxSize() ? godhoodSlot.GetMaxSize() : msg.godhoodslot_size());
	for(int32_t i = 0; i < (int32_t)godhoodSlot.GetSize(); ++i) {
		const ::proto_ff::GodhoodSlot & temp_godhoodslot = msg.godhoodslot(i);
		godhoodSlot[i].read_from_pbmsg(temp_godhoodslot);
	}
}

RecoveryCompleteDBData_s::RecoveryCompleteDBData_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int RecoveryCompleteDBData_s::CreateInit() {
	level = (uint32_t)0;
	vipLevel = (uint32_t)0;
	time = (uint64_t)0;
	return 0;
}

int RecoveryCompleteDBData_s::ResumeInit() {
	return 0;
}

void RecoveryCompleteDBData_s::write_to_pbmsg(::proto_ff::RecoveryCompleteDBData & msg) const {
	msg.set_level((uint32_t)level);
	msg.set_viplevel((uint32_t)vipLevel);
	msg.set_time((uint64_t)time);
	for(int32_t i = 0; i < (int32_t)completeList.GetSize() && i < completeList.GetMaxSize(); ++i) {
		::proto_ff::ComPair* temp_completelist = msg.add_completelist();
		completeList[i].write_to_pbmsg(*temp_completelist);
	}
	for(int32_t i = 0; i < (int32_t)funUnlock.GetSize() && i < funUnlock.GetMaxSize(); ++i) {
		::proto_ff::ComPairBool* temp_fununlock = msg.add_fununlock();
		funUnlock[i].write_to_pbmsg(*temp_fununlock);
	}
}

void RecoveryCompleteDBData_s::read_from_pbmsg(const ::proto_ff::RecoveryCompleteDBData & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct RecoveryCompleteDBData_s));
	level = msg.level();
	vipLevel = msg.viplevel();
	time = msg.time();
	completeList.SetSize(msg.completelist_size() > completeList.GetMaxSize() ? completeList.GetMaxSize() : msg.completelist_size());
	for(int32_t i = 0; i < (int32_t)completeList.GetSize(); ++i) {
		const ::proto_ff::ComPair & temp_completelist = msg.completelist(i);
		completeList[i].read_from_pbmsg(temp_completelist);
	}
	funUnlock.SetSize(msg.fununlock_size() > funUnlock.GetMaxSize() ? funUnlock.GetMaxSize() : msg.fununlock_size());
	for(int32_t i = 0; i < (int32_t)funUnlock.GetSize(); ++i) {
		const ::proto_ff::ComPairBool & temp_fununlock = msg.fununlock(i);
		funUnlock[i].read_from_pbmsg(temp_fununlock);
	}
}

RecoveryDBReward_s::RecoveryDBReward_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int RecoveryDBReward_s::CreateInit() {
	groupid = (uint32_t)0;
	day1CountMax = (uint32_t)0;
	day2CountMax = (uint32_t)0;
	day1VipCountMax = (uint32_t)0;
	day2VipCountMax = (uint32_t)0;
	commonCount = (uint32_t)0;
	vipCount = (uint32_t)0;
	goldExp = (uint32_t)0;
	diamondsExp = (uint32_t)0;
	goldItemCount = (uint32_t)0;
	diamondsItemCount = (uint32_t)0;
	needGold = (uint32_t)0;
	needDiamonds = (uint32_t)0;
	ItemId = (uint64_t)0;
	confid = (uint32_t)0;
	return 0;
}

int RecoveryDBReward_s::ResumeInit() {
	return 0;
}

void RecoveryDBReward_s::write_to_pbmsg(::proto_ff::RecoveryDBReward & msg) const {
	msg.set_groupid((uint32_t)groupid);
	msg.set_day1countmax((uint32_t)day1CountMax);
	msg.set_day2countmax((uint32_t)day2CountMax);
	msg.set_day1vipcountmax((uint32_t)day1VipCountMax);
	msg.set_day2vipcountmax((uint32_t)day2VipCountMax);
	msg.set_commoncount((uint32_t)commonCount);
	msg.set_vipcount((uint32_t)vipCount);
	msg.set_goldexp((uint32_t)goldExp);
	msg.set_diamondsexp((uint32_t)diamondsExp);
	msg.set_golditemcount((uint32_t)goldItemCount);
	msg.set_diamondsitemcount((uint32_t)diamondsItemCount);
	msg.set_needgold((uint32_t)needGold);
	msg.set_needdiamonds((uint32_t)needDiamonds);
	msg.set_itemid((uint64_t)ItemId);
	msg.set_confid((uint32_t)confid);
}

void RecoveryDBReward_s::read_from_pbmsg(const ::proto_ff::RecoveryDBReward & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct RecoveryDBReward_s));
	groupid = msg.groupid();
	day1CountMax = msg.day1countmax();
	day2CountMax = msg.day2countmax();
	day1VipCountMax = msg.day1vipcountmax();
	day2VipCountMax = msg.day2vipcountmax();
	commonCount = msg.commoncount();
	vipCount = msg.vipcount();
	goldExp = msg.goldexp();
	diamondsExp = msg.diamondsexp();
	goldItemCount = msg.golditemcount();
	diamondsItemCount = msg.diamondsitemcount();
	needGold = msg.needgold();
	needDiamonds = msg.needdiamonds();
	ItemId = msg.itemid();
	confid = msg.confid();
}

RecoveryDBData_s::RecoveryDBData_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int RecoveryDBData_s::CreateInit() {
	time = (uint64_t)0;
	return 0;
}

int RecoveryDBData_s::ResumeInit() {
	return 0;
}

void RecoveryDBData_s::write_to_pbmsg(::proto_ff::RecoveryDBData & msg) const {
	msg.set_time((uint64_t)time);
	for(int32_t i = 0; i < (int32_t)list.GetSize() && i < list.GetMaxSize(); ++i) {
		::proto_ff::RecoveryDBReward* temp_list = msg.add_list();
		list[i].write_to_pbmsg(*temp_list);
	}
}

void RecoveryDBData_s::read_from_pbmsg(const ::proto_ff::RecoveryDBData & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct RecoveryDBData_s));
	time = msg.time();
	list.SetSize(msg.list_size() > list.GetMaxSize() ? list.GetMaxSize() : msg.list_size());
	for(int32_t i = 0; i < (int32_t)list.GetSize(); ++i) {
		const ::proto_ff::RecoveryDBReward & temp_list = msg.list(i);
		list[i].read_from_pbmsg(temp_list);
	}
}

CharacterDBRecoveryData_s::CharacterDBRecoveryData_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int CharacterDBRecoveryData_s::CreateInit() {
	return 0;
}

int CharacterDBRecoveryData_s::ResumeInit() {
	return 0;
}

void CharacterDBRecoveryData_s::write_to_pbmsg(::proto_ff::CharacterDBRecoveryData & msg) const {
	for(int32_t i = 0; i < (int32_t)completeDBData.GetSize() && i < completeDBData.GetMaxSize(); ++i) {
		::proto_ff::RecoveryCompleteDBData* temp_completedbdata = msg.add_completedbdata();
		completeDBData[i].write_to_pbmsg(*temp_completedbdata);
	}
	::proto_ff::RecoveryDBData* temp_recoverydbdata = msg.mutable_recoverydbdata();
	recoveryDBData.write_to_pbmsg(*temp_recoverydbdata);
}

void CharacterDBRecoveryData_s::read_from_pbmsg(const ::proto_ff::CharacterDBRecoveryData & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct CharacterDBRecoveryData_s));
	completeDBData.SetSize(msg.completedbdata_size() > completeDBData.GetMaxSize() ? completeDBData.GetMaxSize() : msg.completedbdata_size());
	for(int32_t i = 0; i < (int32_t)completeDBData.GetSize(); ++i) {
		const ::proto_ff::RecoveryCompleteDBData & temp_completedbdata = msg.completedbdata(i);
		completeDBData[i].read_from_pbmsg(temp_completedbdata);
	}
	const ::proto_ff::RecoveryDBData & temp_recoverydbdata = msg.recoverydbdata();
	recoveryDBData.read_from_pbmsg(temp_recoverydbdata);
}

CharacterDBActivityScuffleData_s::CharacterDBActivityScuffleData_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int CharacterDBActivityScuffleData_s::CreateInit() {
	cur_cfg_id = (uint64_t)0;
	cur_points = (int32_t)0;
	activity_id = (uint64_t)0;
	before_map_id = (uint64_t)0;
	last_time = (int32_t)0;
	end_time = (int32_t)0;
	kill_num = (int32_t)0;
	last_kill_num = (int32_t)0;
	return 0;
}

int CharacterDBActivityScuffleData_s::ResumeInit() {
	return 0;
}

void CharacterDBActivityScuffleData_s::write_to_pbmsg(::proto_ff::CharacterDBActivityScuffleData & msg) const {
	msg.set_cur_cfg_id((uint64_t)cur_cfg_id);
	msg.set_cur_points((int32_t)cur_points);
	msg.set_activity_id((uint64_t)activity_id);
	msg.set_before_map_id((uint64_t)before_map_id);
	::proto_ff::Vector3PB* temp_before_map_point = msg.mutable_before_map_point();
	before_map_point.write_to_pbmsg(*temp_before_map_point);
	msg.set_last_time((int32_t)last_time);
	msg.set_end_time((int32_t)end_time);
	msg.set_kill_num((int32_t)kill_num);
	msg.set_last_kill_num((int32_t)last_kill_num);
}

void CharacterDBActivityScuffleData_s::read_from_pbmsg(const ::proto_ff::CharacterDBActivityScuffleData & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct CharacterDBActivityScuffleData_s));
	cur_cfg_id = msg.cur_cfg_id();
	cur_points = msg.cur_points();
	activity_id = msg.activity_id();
	before_map_id = msg.before_map_id();
	const ::proto_ff::Vector3PB & temp_before_map_point = msg.before_map_point();
	before_map_point.read_from_pbmsg(temp_before_map_point);
	last_time = msg.last_time();
	end_time = msg.end_time();
	kill_num = msg.kill_num();
	last_kill_num = msg.last_kill_num();
}

CharacterDBActivityChaosDragonsData_s::CharacterDBActivityChaosDragonsData_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int CharacterDBActivityChaosDragonsData_s::CreateInit() {
	before_map_id = (uint64_t)0;
	return 0;
}

int CharacterDBActivityChaosDragonsData_s::ResumeInit() {
	return 0;
}

void CharacterDBActivityChaosDragonsData_s::write_to_pbmsg(::proto_ff::CharacterDBActivityChaosDragonsData & msg) const {
	msg.set_before_map_id((uint64_t)before_map_id);
	::proto_ff::Vector3PB* temp_before_map_point = msg.mutable_before_map_point();
	before_map_point.write_to_pbmsg(*temp_before_map_point);
}

void CharacterDBActivityChaosDragonsData_s::read_from_pbmsg(const ::proto_ff::CharacterDBActivityChaosDragonsData & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct CharacterDBActivityChaosDragonsData_s));
	before_map_id = msg.before_map_id();
	const ::proto_ff::Vector3PB & temp_before_map_point = msg.before_map_point();
	before_map_point.read_from_pbmsg(temp_before_map_point);
}

CharacterDBActivityAsharmData_s::CharacterDBActivityAsharmData_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int CharacterDBActivityAsharmData_s::CreateInit() {
	step = (int32_t)0;
	end_time = (uint64_t)0;
	last_time = (uint64_t)0;
	cur_num = (int32_t)0;
	return 0;
}

int CharacterDBActivityAsharmData_s::ResumeInit() {
	return 0;
}

void CharacterDBActivityAsharmData_s::write_to_pbmsg(::proto_ff::CharacterDBActivityAsharmData & msg) const {
	msg.set_step((int32_t)step);
	msg.set_end_time((uint64_t)end_time);
	msg.set_last_time((uint64_t)last_time);
	msg.set_cur_num((int32_t)cur_num);
}

void CharacterDBActivityAsharmData_s::read_from_pbmsg(const ::proto_ff::CharacterDBActivityAsharmData & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct CharacterDBActivityAsharmData_s));
	step = msg.step();
	end_time = msg.end_time();
	last_time = msg.last_time();
	cur_num = msg.cur_num();
}

CharacterDBCombatTeamData_s::CharacterDBCombatTeamData_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int CharacterDBCombatTeamData_s::CreateInit() {
	team_id = (int32_t)0;
	team_end_time = (uint64_t)0;
	return 0;
}

int CharacterDBCombatTeamData_s::ResumeInit() {
	return 0;
}

void CharacterDBCombatTeamData_s::write_to_pbmsg(::proto_ff::CharacterDBCombatTeamData & msg) const {
	msg.set_team_id((int32_t)team_id);
	msg.set_team_end_time((uint64_t)team_end_time);
}

void CharacterDBCombatTeamData_s::read_from_pbmsg(const ::proto_ff::CharacterDBCombatTeamData & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct CharacterDBCombatTeamData_s));
	team_id = msg.team_id();
	team_end_time = msg.team_end_time();
}

CharacterDBSoloData_s::CharacterDBSoloData_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int CharacterDBSoloData_s::CreateInit() {
	my_solo_num = (int32_t)0;
	solo_time_end = (uint64_t)0;
	solo_season = (int32_t)0;
	cur_buy_num = (int32_t)0;
	last_time = (uint64_t)0;
	lose_num = (int32_t)0;
	return 0;
}

int CharacterDBSoloData_s::ResumeInit() {
	return 0;
}

void CharacterDBSoloData_s::write_to_pbmsg(::proto_ff::CharacterDBSoloData & msg) const {
	for(int32_t i = 0; i < (int32_t)rewarded_join_index.GetSize() && i < rewarded_join_index.GetMaxSize(); ++i) {
		msg.add_rewarded_join_index((int32_t)rewarded_join_index[i]);
	}
	msg.set_my_solo_num((int32_t)my_solo_num);
	for(int32_t i = 0; i < (int32_t)rewarded_stage_index.GetSize() && i < rewarded_stage_index.GetMaxSize(); ++i) {
		msg.add_rewarded_stage_index((int32_t)rewarded_stage_index[i]);
	}
	for(int32_t i = 0; i < (int32_t)rewarded_day_stage_index.GetSize() && i < rewarded_day_stage_index.GetMaxSize(); ++i) {
		msg.add_rewarded_day_stage_index((int32_t)rewarded_day_stage_index[i]);
	}
	msg.set_solo_time_end((uint64_t)solo_time_end);
	msg.set_solo_season((int32_t)solo_season);
	msg.set_cur_buy_num((int32_t)cur_buy_num);
	msg.set_last_time((uint64_t)last_time);
	msg.set_lose_num((int32_t)lose_num);
}

void CharacterDBSoloData_s::read_from_pbmsg(const ::proto_ff::CharacterDBSoloData & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct CharacterDBSoloData_s));
	rewarded_join_index.SetSize(msg.rewarded_join_index_size() > rewarded_join_index.GetMaxSize() ? rewarded_join_index.GetMaxSize() : msg.rewarded_join_index_size());
	for(int32_t i = 0; i < (int32_t)rewarded_join_index.GetSize(); ++i) {
		rewarded_join_index[i] = msg.rewarded_join_index(i);
	}
	my_solo_num = msg.my_solo_num();
	rewarded_stage_index.SetSize(msg.rewarded_stage_index_size() > rewarded_stage_index.GetMaxSize() ? rewarded_stage_index.GetMaxSize() : msg.rewarded_stage_index_size());
	for(int32_t i = 0; i < (int32_t)rewarded_stage_index.GetSize(); ++i) {
		rewarded_stage_index[i] = msg.rewarded_stage_index(i);
	}
	rewarded_day_stage_index.SetSize(msg.rewarded_day_stage_index_size() > rewarded_day_stage_index.GetMaxSize() ? rewarded_day_stage_index.GetMaxSize() : msg.rewarded_day_stage_index_size());
	for(int32_t i = 0; i < (int32_t)rewarded_day_stage_index.GetSize(); ++i) {
		rewarded_day_stage_index[i] = msg.rewarded_day_stage_index(i);
	}
	solo_time_end = msg.solo_time_end();
	solo_season = msg.solo_season();
	cur_buy_num = msg.cur_buy_num();
	last_time = msg.last_time();
	lose_num = msg.lose_num();
}

CharacterDBAtBoxData_s::CharacterDBAtBoxData_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int CharacterDBAtBoxData_s::CreateInit() {
	use_count = (int32_t)0;
	time = (uint64_t)0;
	return 0;
}

int CharacterDBAtBoxData_s::ResumeInit() {
	return 0;
}

void CharacterDBAtBoxData_s::write_to_pbmsg(::proto_ff::CharacterDBAtBoxData & msg) const {
	msg.set_use_count((int32_t)use_count);
	msg.set_time((uint64_t)time);
}

void CharacterDBAtBoxData_s::read_from_pbmsg(const ::proto_ff::CharacterDBAtBoxData & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct CharacterDBAtBoxData_s));
	use_count = msg.use_count();
	time = msg.time();
}

CharDBAncientShopProto_s::CharDBAncientShopProto_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int CharDBAncientShopProto_s::CreateInit() {
	idx = (int32_t)0;
	exchge = (int32_t)0;
	return 0;
}

int CharDBAncientShopProto_s::ResumeInit() {
	return 0;
}

void CharDBAncientShopProto_s::write_to_pbmsg(::proto_ff::CharDBAncientShopProto & msg) const {
	msg.set_idx((int32_t)idx);
	msg.set_exchge((int32_t)exchge);
}

void CharDBAncientShopProto_s::read_from_pbmsg(const ::proto_ff::CharDBAncientShopProto & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct CharDBAncientShopProto_s));
	idx = msg.idx();
	exchge = msg.exchge();
}

CharDBAncientShopData_s::CharDBAncientShopData_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int CharDBAncientShopData_s::CreateInit() {
	score = (int64_t)0;
	score_cnt = (int32_t)0;
	dia_cnt = (int32_t)0;
	free_cnt = (int32_t)0;
	fresh_time = (uint64_t)0;
	reset_time = (uint64_t)0;
	return 0;
}

int CharDBAncientShopData_s::ResumeInit() {
	return 0;
}

void CharDBAncientShopData_s::write_to_pbmsg(::proto_ff::CharDBAncientShopData & msg) const {
	for(int32_t i = 0; i < (int32_t)info.GetSize() && i < info.GetMaxSize(); ++i) {
		::proto_ff::CharDBAncientShopProto* temp_info = msg.add_info();
		info[i].write_to_pbmsg(*temp_info);
	}
	msg.set_score((int64_t)score);
	msg.set_score_cnt((int32_t)score_cnt);
	msg.set_dia_cnt((int32_t)dia_cnt);
	msg.set_free_cnt((int32_t)free_cnt);
	msg.set_fresh_time((uint64_t)fresh_time);
	msg.set_reset_time((uint64_t)reset_time);
}

void CharDBAncientShopData_s::read_from_pbmsg(const ::proto_ff::CharDBAncientShopData & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct CharDBAncientShopData_s));
	info.SetSize(msg.info_size() > info.GetMaxSize() ? info.GetMaxSize() : msg.info_size());
	for(int32_t i = 0; i < (int32_t)info.GetSize(); ++i) {
		const ::proto_ff::CharDBAncientShopProto & temp_info = msg.info(i);
		info[i].read_from_pbmsg(temp_info);
	}
	score = msg.score();
	score_cnt = msg.score_cnt();
	dia_cnt = msg.dia_cnt();
	free_cnt = msg.free_cnt();
	fresh_time = msg.fresh_time();
	reset_time = msg.reset_time();
}

CharacterDBAncientData_s::CharacterDBAncientData_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int CharacterDBAncientData_s::CreateInit() {
	bless_value = (int64_t)0;
	score_incr = (int64_t)0;
	bless_reset_time = (uint64_t)0;
	return 0;
}

int CharacterDBAncientData_s::ResumeInit() {
	return 0;
}

void CharacterDBAncientData_s::write_to_pbmsg(::proto_ff::CharacterDBAncientData & msg) const {
	msg.set_bless_value((int64_t)bless_value);
	msg.set_score_incr((int64_t)score_incr);
	::proto_ff::CharDBAncientShopData* temp_shop = msg.mutable_shop();
	shop.write_to_pbmsg(*temp_shop);
	msg.set_bless_reset_time((uint64_t)bless_reset_time);
}

void CharacterDBAncientData_s::read_from_pbmsg(const ::proto_ff::CharacterDBAncientData & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct CharacterDBAncientData_s));
	bless_value = msg.bless_value();
	score_incr = msg.score_incr();
	const ::proto_ff::CharDBAncientShopData & temp_shop = msg.shop();
	shop.read_from_pbmsg(temp_shop);
	bless_reset_time = msg.bless_reset_time();
}

ChooseGiftData_s::ChooseGiftData_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int ChooseGiftData_s::CreateInit() {
	activeTime = (uint64_t)0;
	headState = (int32_t)0;
	rechargeIndex = (int32_t)0;
	rechargeIndexState = (int32_t)0;
	return 0;
}

int ChooseGiftData_s::ResumeInit() {
	return 0;
}

void ChooseGiftData_s::write_to_pbmsg(::proto_ff::ChooseGiftData & msg) const {
	msg.set_activetime((uint64_t)activeTime);
	msg.set_headstate((int32_t)headState);
	msg.set_rechargeindex((int32_t)rechargeIndex);
	msg.set_rechargeindexstate((int32_t)rechargeIndexState);
}

void ChooseGiftData_s::read_from_pbmsg(const ::proto_ff::ChooseGiftData & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct ChooseGiftData_s));
	activeTime = msg.activetime();
	headState = msg.headstate();
	rechargeIndex = msg.rechargeindex();
	rechargeIndexState = msg.rechargeindexstate();
}

CharacterDBActivityData_s::CharacterDBActivityData_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int CharacterDBActivityData_s::CreateInit() {
	return 0;
}

int CharacterDBActivityData_s::ResumeInit() {
	return 0;
}

void CharacterDBActivityData_s::write_to_pbmsg(::proto_ff::CharacterDBActivityData & msg) const {
	::proto_ff::CharacterDBActivityScuffleData* temp_scuffle_cross_data = msg.mutable_scuffle_cross_data();
	scuffle_cross_data.write_to_pbmsg(*temp_scuffle_cross_data);
	::proto_ff::CharacterDBActivityScuffleData* temp_scuffle_local_data = msg.mutable_scuffle_local_data();
	scuffle_local_data.write_to_pbmsg(*temp_scuffle_local_data);
	::proto_ff::CharacterDBActivityChaosDragonsData* temp_chaos_dragons_data = msg.mutable_chaos_dragons_data();
	chaos_dragons_data.write_to_pbmsg(*temp_chaos_dragons_data);
	::proto_ff::CharacterDBActivityAsharmData* temp_asharm_data = msg.mutable_asharm_data();
	asharm_data.write_to_pbmsg(*temp_asharm_data);
	::proto_ff::CharacterDBSoloData* temp_solo_data = msg.mutable_solo_data();
	solo_data.write_to_pbmsg(*temp_solo_data);
	::proto_ff::CharacterDBAtBoxData* temp_box_data = msg.mutable_box_data();
	box_data.write_to_pbmsg(*temp_box_data);
	::proto_ff::CharacterDBAncientData* temp_ancient_data = msg.mutable_ancient_data();
	ancient_data.write_to_pbmsg(*temp_ancient_data);
	::proto_ff::ChooseGiftData* temp_choosegift_data = msg.mutable_choosegift_data();
	choosegift_data.write_to_pbmsg(*temp_choosegift_data);
}

void CharacterDBActivityData_s::read_from_pbmsg(const ::proto_ff::CharacterDBActivityData & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct CharacterDBActivityData_s));
	const ::proto_ff::CharacterDBActivityScuffleData & temp_scuffle_cross_data = msg.scuffle_cross_data();
	scuffle_cross_data.read_from_pbmsg(temp_scuffle_cross_data);
	const ::proto_ff::CharacterDBActivityScuffleData & temp_scuffle_local_data = msg.scuffle_local_data();
	scuffle_local_data.read_from_pbmsg(temp_scuffle_local_data);
	const ::proto_ff::CharacterDBActivityChaosDragonsData & temp_chaos_dragons_data = msg.chaos_dragons_data();
	chaos_dragons_data.read_from_pbmsg(temp_chaos_dragons_data);
	const ::proto_ff::CharacterDBActivityAsharmData & temp_asharm_data = msg.asharm_data();
	asharm_data.read_from_pbmsg(temp_asharm_data);
	const ::proto_ff::CharacterDBSoloData & temp_solo_data = msg.solo_data();
	solo_data.read_from_pbmsg(temp_solo_data);
	const ::proto_ff::CharacterDBAtBoxData & temp_box_data = msg.box_data();
	box_data.read_from_pbmsg(temp_box_data);
	const ::proto_ff::CharacterDBAncientData & temp_ancient_data = msg.ancient_data();
	ancient_data.read_from_pbmsg(temp_ancient_data);
	const ::proto_ff::ChooseGiftData & temp_choosegift_data = msg.choosegift_data();
	choosegift_data.read_from_pbmsg(temp_choosegift_data);
}

SOAcitveTotalRechargeData_s::SOAcitveTotalRechargeData_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int SOAcitveTotalRechargeData_s::CreateInit() {
	activeId = (uint64_t)0;
	pageId = (uint32_t)0;
	rechargeValue = (uint64_t)0;
	rechargeholy = (uint64_t)0;
	return 0;
}

int SOAcitveTotalRechargeData_s::ResumeInit() {
	return 0;
}

void SOAcitveTotalRechargeData_s::write_to_pbmsg(::proto_ff::SOAcitveTotalRechargeData & msg) const {
	msg.set_activeid((uint64_t)activeId);
	msg.set_pageid((uint32_t)pageId);
	msg.set_rechargevalue((uint64_t)rechargeValue);
	for(int32_t i = 0; i < (int32_t)getState.GetSize() && i < getState.GetMaxSize(); ++i) {
		::proto_ff::ComPair* temp_getstate = msg.add_getstate();
		getState[i].write_to_pbmsg(*temp_getstate);
	}
	msg.set_rechargeholy((uint64_t)rechargeholy);
}

void SOAcitveTotalRechargeData_s::read_from_pbmsg(const ::proto_ff::SOAcitveTotalRechargeData & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct SOAcitveTotalRechargeData_s));
	activeId = msg.activeid();
	pageId = msg.pageid();
	rechargeValue = msg.rechargevalue();
	getState.SetSize(msg.getstate_size() > getState.GetMaxSize() ? getState.GetMaxSize() : msg.getstate_size());
	for(int32_t i = 0; i < (int32_t)getState.GetSize(); ++i) {
		const ::proto_ff::ComPair & temp_getstate = msg.getstate(i);
		getState[i].read_from_pbmsg(temp_getstate);
	}
	rechargeholy = msg.rechargeholy();
}

SOAcitveAdvanceData_s::SOAcitveAdvanceData_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int SOAcitveAdvanceData_s::CreateInit() {
	activeId = (uint64_t)0;
	pageId = (uint32_t)0;
	advanceValue = (uint64_t)0;
	return 0;
}

int SOAcitveAdvanceData_s::ResumeInit() {
	return 0;
}

void SOAcitveAdvanceData_s::write_to_pbmsg(::proto_ff::SOAcitveAdvanceData & msg) const {
	msg.set_activeid((uint64_t)activeId);
	msg.set_pageid((uint32_t)pageId);
	msg.set_advancevalue((uint64_t)advanceValue);
	for(int32_t i = 0; i < (int32_t)getState.GetSize() && i < getState.GetMaxSize(); ++i) {
		::proto_ff::ComPair* temp_getstate = msg.add_getstate();
		getState[i].write_to_pbmsg(*temp_getstate);
	}
	for(int32_t i = 0; i < (int32_t)advanceValueMap.GetSize() && i < advanceValueMap.GetMaxSize(); ++i) {
		::proto_ff::ComPair64* temp_advancevaluemap = msg.add_advancevaluemap();
		advanceValueMap[i].write_to_pbmsg(*temp_advancevaluemap);
	}
}

void SOAcitveAdvanceData_s::read_from_pbmsg(const ::proto_ff::SOAcitveAdvanceData & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct SOAcitveAdvanceData_s));
	activeId = msg.activeid();
	pageId = msg.pageid();
	advanceValue = msg.advancevalue();
	getState.SetSize(msg.getstate_size() > getState.GetMaxSize() ? getState.GetMaxSize() : msg.getstate_size());
	for(int32_t i = 0; i < (int32_t)getState.GetSize(); ++i) {
		const ::proto_ff::ComPair & temp_getstate = msg.getstate(i);
		getState[i].read_from_pbmsg(temp_getstate);
	}
	advanceValueMap.SetSize(msg.advancevaluemap_size() > advanceValueMap.GetMaxSize() ? advanceValueMap.GetMaxSize() : msg.advancevaluemap_size());
	for(int32_t i = 0; i < (int32_t)advanceValueMap.GetSize(); ++i) {
		const ::proto_ff::ComPair64 & temp_advancevaluemap = msg.advancevaluemap(i);
		advanceValueMap[i].read_from_pbmsg(temp_advancevaluemap);
	}
}

SOAcitveGoodsData_s::SOAcitveGoodsData_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int SOAcitveGoodsData_s::CreateInit() {
	activeId = (uint64_t)0;
	pageId = (uint32_t)0;
	return 0;
}

int SOAcitveGoodsData_s::ResumeInit() {
	return 0;
}

void SOAcitveGoodsData_s::write_to_pbmsg(::proto_ff::SOAcitveGoodsData & msg) const {
	msg.set_activeid((uint64_t)activeId);
	msg.set_pageid((uint32_t)pageId);
	for(int32_t i = 0; i < (int32_t)buyCount.GetSize() && i < buyCount.GetMaxSize(); ++i) {
		::proto_ff::ComPair64* temp_buycount = msg.add_buycount();
		buyCount[i].write_to_pbmsg(*temp_buycount);
	}
}

void SOAcitveGoodsData_s::read_from_pbmsg(const ::proto_ff::SOAcitveGoodsData & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct SOAcitveGoodsData_s));
	activeId = msg.activeid();
	pageId = msg.pageid();
	buyCount.SetSize(msg.buycount_size() > buyCount.GetMaxSize() ? buyCount.GetMaxSize() : msg.buycount_size());
	for(int32_t i = 0; i < (int32_t)buyCount.GetSize(); ++i) {
		const ::proto_ff::ComPair64 & temp_buycount = msg.buycount(i);
		buyCount[i].read_from_pbmsg(temp_buycount);
	}
}

CharacterDBSOAcitveData_s::CharacterDBSOAcitveData_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int CharacterDBSOAcitveData_s::CreateInit() {
	return 0;
}

int CharacterDBSOAcitveData_s::ResumeInit() {
	return 0;
}

void CharacterDBSOAcitveData_s::write_to_pbmsg(::proto_ff::CharacterDBSOAcitveData & msg) const {
	for(int32_t i = 0; i < (int32_t)totalRecharge.GetSize() && i < totalRecharge.GetMaxSize(); ++i) {
		::proto_ff::SOAcitveTotalRechargeData* temp_totalrecharge = msg.add_totalrecharge();
		totalRecharge[i].write_to_pbmsg(*temp_totalrecharge);
	}
	for(int32_t i = 0; i < (int32_t)advance.GetSize() && i < advance.GetMaxSize(); ++i) {
		::proto_ff::SOAcitveAdvanceData* temp_advance = msg.add_advance();
		advance[i].write_to_pbmsg(*temp_advance);
	}
	for(int32_t i = 0; i < (int32_t)goods.GetSize() && i < goods.GetMaxSize(); ++i) {
		::proto_ff::SOAcitveGoodsData* temp_goods = msg.add_goods();
		goods[i].write_to_pbmsg(*temp_goods);
	}
	for(int32_t i = 0; i < (int32_t)redPointClickData.GetSize() && i < redPointClickData.GetMaxSize(); ++i) {
		::proto_ff::ComPair64* temp_redpointclickdata = msg.add_redpointclickdata();
		redPointClickData[i].write_to_pbmsg(*temp_redpointclickdata);
	}
}

void CharacterDBSOAcitveData_s::read_from_pbmsg(const ::proto_ff::CharacterDBSOAcitveData & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct CharacterDBSOAcitveData_s));
	totalRecharge.SetSize(msg.totalrecharge_size() > totalRecharge.GetMaxSize() ? totalRecharge.GetMaxSize() : msg.totalrecharge_size());
	for(int32_t i = 0; i < (int32_t)totalRecharge.GetSize(); ++i) {
		const ::proto_ff::SOAcitveTotalRechargeData & temp_totalrecharge = msg.totalrecharge(i);
		totalRecharge[i].read_from_pbmsg(temp_totalrecharge);
	}
	advance.SetSize(msg.advance_size() > advance.GetMaxSize() ? advance.GetMaxSize() : msg.advance_size());
	for(int32_t i = 0; i < (int32_t)advance.GetSize(); ++i) {
		const ::proto_ff::SOAcitveAdvanceData & temp_advance = msg.advance(i);
		advance[i].read_from_pbmsg(temp_advance);
	}
	goods.SetSize(msg.goods_size() > goods.GetMaxSize() ? goods.GetMaxSize() : msg.goods_size());
	for(int32_t i = 0; i < (int32_t)goods.GetSize(); ++i) {
		const ::proto_ff::SOAcitveGoodsData & temp_goods = msg.goods(i);
		goods[i].read_from_pbmsg(temp_goods);
	}
	redPointClickData.SetSize(msg.redpointclickdata_size() > redPointClickData.GetMaxSize() ? redPointClickData.GetMaxSize() : msg.redpointclickdata_size());
	for(int32_t i = 0; i < (int32_t)redPointClickData.GetSize(); ++i) {
		const ::proto_ff::ComPair64 & temp_redpointclickdata = msg.redpointclickdata(i);
		redPointClickData[i].read_from_pbmsg(temp_redpointclickdata);
	}
}

CharacterDBUseItemData_s::CharacterDBUseItemData_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int CharacterDBUseItemData_s::CreateInit() {
	return 0;
}

int CharacterDBUseItemData_s::ResumeInit() {
	return 0;
}

void CharacterDBUseItemData_s::write_to_pbmsg(::proto_ff::CharacterDBUseItemData & msg) const {
	for(int32_t i = 0; i < (int32_t)itemUseTimes.GetSize() && i < itemUseTimes.GetMaxSize(); ++i) {
		::proto_ff::ComPair64* temp_itemusetimes = msg.add_itemusetimes();
		itemUseTimes[i].write_to_pbmsg(*temp_itemusetimes);
	}
}

void CharacterDBUseItemData_s::read_from_pbmsg(const ::proto_ff::CharacterDBUseItemData & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct CharacterDBUseItemData_s));
	itemUseTimes.SetSize(msg.itemusetimes_size() > itemUseTimes.GetMaxSize() ? itemUseTimes.GetMaxSize() : msg.itemusetimes_size());
	for(int32_t i = 0; i < (int32_t)itemUseTimes.GetSize(); ++i) {
		const ::proto_ff::ComPair64 & temp_itemusetimes = msg.itemusetimes(i);
		itemUseTimes[i].read_from_pbmsg(temp_itemusetimes);
	}
}

CharacterDBDayUseItemData_s::CharacterDBDayUseItemData_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int CharacterDBDayUseItemData_s::CreateInit() {
	day = (uint64_t)0;
	return 0;
}

int CharacterDBDayUseItemData_s::ResumeInit() {
	return 0;
}

void CharacterDBDayUseItemData_s::write_to_pbmsg(::proto_ff::CharacterDBDayUseItemData & msg) const {
	msg.set_day((uint64_t)day);
	for(int32_t i = 0; i < (int32_t)itemUseTimes.GetSize() && i < itemUseTimes.GetMaxSize(); ++i) {
		::proto_ff::ComPair64* temp_itemusetimes = msg.add_itemusetimes();
		itemUseTimes[i].write_to_pbmsg(*temp_itemusetimes);
	}
}

void CharacterDBDayUseItemData_s::read_from_pbmsg(const ::proto_ff::CharacterDBDayUseItemData & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct CharacterDBDayUseItemData_s));
	day = msg.day();
	itemUseTimes.SetSize(msg.itemusetimes_size() > itemUseTimes.GetMaxSize() ? itemUseTimes.GetMaxSize() : msg.itemusetimes_size());
	for(int32_t i = 0; i < (int32_t)itemUseTimes.GetSize(); ++i) {
		const ::proto_ff::ComPair64 & temp_itemusetimes = msg.itemusetimes(i);
		itemUseTimes[i].read_from_pbmsg(temp_itemusetimes);
	}
}

MysteryShopDBData_s::MysteryShopDBData_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int MysteryShopDBData_s::CreateInit() {
	nId = (uint32_t)0;
	nStartTime = (uint64_t)0;
	nFinishTime = (uint64_t)0;
	nState = (uint32_t)0;
	return 0;
}

int MysteryShopDBData_s::ResumeInit() {
	return 0;
}

void MysteryShopDBData_s::write_to_pbmsg(::proto_ff::MysteryShopDBData & msg) const {
	msg.set_nid((uint32_t)nId);
	msg.set_nstarttime((uint64_t)nStartTime);
	msg.set_nfinishtime((uint64_t)nFinishTime);
	msg.set_nstate((uint32_t)nState);
}

void MysteryShopDBData_s::read_from_pbmsg(const ::proto_ff::MysteryShopDBData & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct MysteryShopDBData_s));
	nId = msg.nid();
	nStartTime = msg.nstarttime();
	nFinishTime = msg.nfinishtime();
	nState = msg.nstate();
}

CharacterDBMysteryShopData_s::CharacterDBMysteryShopData_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int CharacterDBMysteryShopData_s::CreateInit() {
	return 0;
}

int CharacterDBMysteryShopData_s::ResumeInit() {
	return 0;
}

void CharacterDBMysteryShopData_s::write_to_pbmsg(::proto_ff::CharacterDBMysteryShopData & msg) const {
	for(int32_t i = 0; i < (int32_t)dataList.GetSize() && i < dataList.GetMaxSize(); ++i) {
		::proto_ff::MysteryShopDBData* temp_datalist = msg.add_datalist();
		dataList[i].write_to_pbmsg(*temp_datalist);
	}
}

void CharacterDBMysteryShopData_s::read_from_pbmsg(const ::proto_ff::CharacterDBMysteryShopData & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct CharacterDBMysteryShopData_s));
	dataList.SetSize(msg.datalist_size() > dataList.GetMaxSize() ? dataList.GetMaxSize() : msg.datalist_size());
	for(int32_t i = 0; i < (int32_t)dataList.GetSize(); ++i) {
		const ::proto_ff::MysteryShopDBData & temp_datalist = msg.datalist(i);
		dataList[i].read_from_pbmsg(temp_datalist);
	}
}

CharacterDBPackageTestRebateData_s::CharacterDBPackageTestRebateData_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int CharacterDBPackageTestRebateData_s::CreateInit() {
	bChecked = (bool)0;
	state = (uint32_t)0;
	rechargeValue = (uint32_t)0;
	powerRank = (uint32_t)0;
	deadline = (uint64_t)0;
	return 0;
}

int CharacterDBPackageTestRebateData_s::ResumeInit() {
	return 0;
}

void CharacterDBPackageTestRebateData_s::write_to_pbmsg(::proto_ff::CharacterDBPackageTestRebateData & msg) const {
	msg.set_bchecked((bool)bChecked);
	msg.set_state((uint32_t)state);
	msg.set_rechargevalue((uint32_t)rechargeValue);
	msg.set_powerrank((uint32_t)powerRank);
	msg.set_deadline((uint64_t)deadline);
	for(int32_t i = 0; i < (int32_t)rewardStateMap.GetSize() && i < rewardStateMap.GetMaxSize(); ++i) {
		::proto_ff::ComPair64* temp_rewardstatemap = msg.add_rewardstatemap();
		rewardStateMap[i].write_to_pbmsg(*temp_rewardstatemap);
	}
	for(int32_t i = 0; i < (int32_t)backStateMap.GetSize() && i < backStateMap.GetMaxSize(); ++i) {
		::proto_ff::ComPair64* temp_backstatemap = msg.add_backstatemap();
		backStateMap[i].write_to_pbmsg(*temp_backstatemap);
	}
}

void CharacterDBPackageTestRebateData_s::read_from_pbmsg(const ::proto_ff::CharacterDBPackageTestRebateData & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct CharacterDBPackageTestRebateData_s));
	bChecked = msg.bchecked();
	state = msg.state();
	rechargeValue = msg.rechargevalue();
	powerRank = msg.powerrank();
	deadline = msg.deadline();
	rewardStateMap.SetSize(msg.rewardstatemap_size() > rewardStateMap.GetMaxSize() ? rewardStateMap.GetMaxSize() : msg.rewardstatemap_size());
	for(int32_t i = 0; i < (int32_t)rewardStateMap.GetSize(); ++i) {
		const ::proto_ff::ComPair64 & temp_rewardstatemap = msg.rewardstatemap(i);
		rewardStateMap[i].read_from_pbmsg(temp_rewardstatemap);
	}
	backStateMap.SetSize(msg.backstatemap_size() > backStateMap.GetMaxSize() ? backStateMap.GetMaxSize() : msg.backstatemap_size());
	for(int32_t i = 0; i < (int32_t)backStateMap.GetSize(); ++i) {
		const ::proto_ff::ComPair64 & temp_backstatemap = msg.backstatemap(i);
		backStateMap[i].read_from_pbmsg(temp_backstatemap);
	}
}

FuncFightDBData_s::FuncFightDBData_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int FuncFightDBData_s::CreateInit() {
	equip_total = (int64_t)0;
	equip_base = (int64_t)0;
	equip_strong = (int64_t)0;
	stone = (int64_t)0;
	equip_scrutiny = (int64_t)0;
	equip_suit = (int64_t)0;
	equip_awake = (int64_t)0;
	equip_enchant = (int64_t)0;
	fatestar = (int64_t)0;
	godhood = (int64_t)0;
	identify = (int64_t)0;
	partner = (int64_t)0;
	field = (int64_t)0;
	element = (int64_t)0;
	wing = (int64_t)0;
	treasure = (int64_t)0;
	fantasty_total = (int64_t)0;
	artifact_fantasty = (int64_t)0;
	horse_fantasty = (int64_t)0;
	wing_fantasty = (int64_t)0;
	fashion_fantasty = (int64_t)0;
	partner_fantasty = (int64_t)0;
	treasure_fantasty = (int64_t)0;
	return 0;
}

int FuncFightDBData_s::ResumeInit() {
	return 0;
}

void FuncFightDBData_s::write_to_pbmsg(::proto_ff::FuncFightDBData & msg) const {
	msg.set_equip_total((int64_t)equip_total);
	msg.set_equip_base((int64_t)equip_base);
	msg.set_equip_strong((int64_t)equip_strong);
	msg.set_stone((int64_t)stone);
	msg.set_equip_scrutiny((int64_t)equip_scrutiny);
	msg.set_equip_suit((int64_t)equip_suit);
	msg.set_equip_awake((int64_t)equip_awake);
	msg.set_equip_enchant((int64_t)equip_enchant);
	msg.set_fatestar((int64_t)fatestar);
	msg.set_godhood((int64_t)godhood);
	msg.set_identify((int64_t)identify);
	msg.set_partner((int64_t)partner);
	msg.set_field((int64_t)field);
	msg.set_element((int64_t)element);
	msg.set_wing((int64_t)wing);
	msg.set_treasure((int64_t)treasure);
	msg.set_fantasty_total((int64_t)fantasty_total);
	msg.set_artifact_fantasty((int64_t)artifact_fantasty);
	msg.set_horse_fantasty((int64_t)horse_fantasty);
	msg.set_wing_fantasty((int64_t)wing_fantasty);
	msg.set_fashion_fantasty((int64_t)fashion_fantasty);
	msg.set_partner_fantasty((int64_t)partner_fantasty);
	msg.set_treasure_fantasty((int64_t)treasure_fantasty);
}

void FuncFightDBData_s::read_from_pbmsg(const ::proto_ff::FuncFightDBData & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct FuncFightDBData_s));
	equip_total = msg.equip_total();
	equip_base = msg.equip_base();
	equip_strong = msg.equip_strong();
	stone = msg.stone();
	equip_scrutiny = msg.equip_scrutiny();
	equip_suit = msg.equip_suit();
	equip_awake = msg.equip_awake();
	equip_enchant = msg.equip_enchant();
	fatestar = msg.fatestar();
	godhood = msg.godhood();
	identify = msg.identify();
	partner = msg.partner();
	field = msg.field();
	element = msg.element();
	wing = msg.wing();
	treasure = msg.treasure();
	fantasty_total = msg.fantasty_total();
	artifact_fantasty = msg.artifact_fantasty();
	horse_fantasty = msg.horse_fantasty();
	wing_fantasty = msg.wing_fantasty();
	fashion_fantasty = msg.fashion_fantasty();
	partner_fantasty = msg.partner_fantasty();
	treasure_fantasty = msg.treasure_fantasty();
}

PowerInfo_s::PowerInfo_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int PowerInfo_s::CreateInit() {
	titleId = (int32_t)0;
	curBuyNum = (int32_t)0;
	skillUpdateId = (int32_t)0;
	return 0;
}

int PowerInfo_s::ResumeInit() {
	return 0;
}

void PowerInfo_s::write_to_pbmsg(::proto_ff::PowerInfo & msg) const {
	msg.set_titleid((int32_t)titleId);
	msg.set_curbuynum((int32_t)curBuyNum);
	msg.set_skillupdateid((int32_t)skillUpdateId);
}

void PowerInfo_s::read_from_pbmsg(const ::proto_ff::PowerInfo & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct PowerInfo_s));
	titleId = msg.titleid();
	curBuyNum = msg.curbuynum();
	skillUpdateId = msg.skillupdateid();
}

PowerInfoDBList_s::PowerInfoDBList_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int PowerInfoDBList_s::CreateInit() {
	return 0;
}

int PowerInfoDBList_s::ResumeInit() {
	return 0;
}

void PowerInfoDBList_s::write_to_pbmsg(::proto_ff::PowerInfoDBList & msg) const {
	for(int32_t i = 0; i < (int32_t)infos.GetSize() && i < infos.GetMaxSize(); ++i) {
		::proto_ff::PowerInfo* temp_infos = msg.add_infos();
		infos[i].write_to_pbmsg(*temp_infos);
	}
}

void PowerInfoDBList_s::read_from_pbmsg(const ::proto_ff::PowerInfoDBList & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct PowerInfoDBList_s));
	infos.SetSize(msg.infos_size() > infos.GetMaxSize() ? infos.GetMaxSize() : msg.infos_size());
	for(int32_t i = 0; i < (int32_t)infos.GetSize(); ++i) {
		const ::proto_ff::PowerInfo & temp_infos = msg.infos(i);
		infos[i].read_from_pbmsg(temp_infos);
	}
}

OccupationTaskInfo_s::OccupationTaskInfo_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int OccupationTaskInfo_s::CreateInit() {
	taskID = (int32_t)0;
	curValue = (int32_t)0;
	taskState = (int32_t)0;
	return 0;
}

int OccupationTaskInfo_s::ResumeInit() {
	return 0;
}

void OccupationTaskInfo_s::write_to_pbmsg(::proto_ff::OccupationTaskInfo & msg) const {
	msg.set_taskid((int32_t)taskID);
	msg.set_curvalue((int32_t)curValue);
	msg.set_taskstate((int32_t)taskState);
}

void OccupationTaskInfo_s::read_from_pbmsg(const ::proto_ff::OccupationTaskInfo & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct OccupationTaskInfo_s));
	taskID = msg.taskid();
	curValue = msg.curvalue();
	taskState = msg.taskstate();
}

OccupationTakeList_s::OccupationTakeList_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int OccupationTakeList_s::CreateInit() {
	return 0;
}

int OccupationTakeList_s::ResumeInit() {
	return 0;
}

void OccupationTakeList_s::write_to_pbmsg(::proto_ff::OccupationTakeList & msg) const {
	for(int32_t i = 0; i < (int32_t)tasks.GetSize() && i < tasks.GetMaxSize(); ++i) {
		::proto_ff::OccupationTaskInfo* temp_tasks = msg.add_tasks();
		tasks[i].write_to_pbmsg(*temp_tasks);
	}
}

void OccupationTakeList_s::read_from_pbmsg(const ::proto_ff::OccupationTakeList & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct OccupationTakeList_s));
	tasks.SetSize(msg.tasks_size() > tasks.GetMaxSize() ? tasks.GetMaxSize() : msg.tasks_size());
	for(int32_t i = 0; i < (int32_t)tasks.GetSize(); ++i) {
		const ::proto_ff::OccupationTaskInfo & temp_tasks = msg.tasks(i);
		tasks[i].read_from_pbmsg(temp_tasks);
	}
}

ComStarInfo_s::ComStarInfo_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int ComStarInfo_s::CreateInit() {
	id = (uint64_t)0;
	star_lv = (int32_t)0;
	return 0;
}

int ComStarInfo_s::ResumeInit() {
	return 0;
}

void ComStarInfo_s::write_to_pbmsg(::proto_ff::ComStarInfo & msg) const {
	msg.set_id((uint64_t)id);
	msg.set_star_lv((int32_t)star_lv);
}

void ComStarInfo_s::read_from_pbmsg(const ::proto_ff::ComStarInfo & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct ComStarInfo_s));
	id = msg.id();
	star_lv = msg.star_lv();
}

CharacterDBHeadSetData_s::CharacterDBHeadSetData_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int CharacterDBHeadSetData_s::CreateInit() {
	cur_head_id = (uint64_t)0;
	cur_frame_id = (uint64_t)0;
	cur_bubble_id = (uint64_t)0;
	return 0;
}

int CharacterDBHeadSetData_s::ResumeInit() {
	return 0;
}

void CharacterDBHeadSetData_s::write_to_pbmsg(::proto_ff::CharacterDBHeadSetData & msg) const {
	for(int32_t i = 0; i < (int32_t)headList.GetSize() && i < headList.GetMaxSize(); ++i) {
		::proto_ff::ComStarInfo* temp_headlist = msg.add_headlist();
		headList[i].write_to_pbmsg(*temp_headlist);
	}
	msg.set_cur_head_id((uint64_t)cur_head_id);
	for(int32_t i = 0; i < (int32_t)frameList.GetSize() && i < frameList.GetMaxSize(); ++i) {
		::proto_ff::ComStarInfo* temp_framelist = msg.add_framelist();
		frameList[i].write_to_pbmsg(*temp_framelist);
	}
	msg.set_cur_frame_id((uint64_t)cur_frame_id);
	for(int32_t i = 0; i < (int32_t)bubbleList.GetSize() && i < bubbleList.GetMaxSize(); ++i) {
		::proto_ff::ComStarInfo* temp_bubblelist = msg.add_bubblelist();
		bubbleList[i].write_to_pbmsg(*temp_bubblelist);
	}
	msg.set_cur_bubble_id((uint64_t)cur_bubble_id);
}

void CharacterDBHeadSetData_s::read_from_pbmsg(const ::proto_ff::CharacterDBHeadSetData & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct CharacterDBHeadSetData_s));
	headList.SetSize(msg.headlist_size() > headList.GetMaxSize() ? headList.GetMaxSize() : msg.headlist_size());
	for(int32_t i = 0; i < (int32_t)headList.GetSize(); ++i) {
		const ::proto_ff::ComStarInfo & temp_headlist = msg.headlist(i);
		headList[i].read_from_pbmsg(temp_headlist);
	}
	cur_head_id = msg.cur_head_id();
	frameList.SetSize(msg.framelist_size() > frameList.GetMaxSize() ? frameList.GetMaxSize() : msg.framelist_size());
	for(int32_t i = 0; i < (int32_t)frameList.GetSize(); ++i) {
		const ::proto_ff::ComStarInfo & temp_framelist = msg.framelist(i);
		frameList[i].read_from_pbmsg(temp_framelist);
	}
	cur_frame_id = msg.cur_frame_id();
	bubbleList.SetSize(msg.bubblelist_size() > bubbleList.GetMaxSize() ? bubbleList.GetMaxSize() : msg.bubblelist_size());
	for(int32_t i = 0; i < (int32_t)bubbleList.GetSize(); ++i) {
		const ::proto_ff::ComStarInfo & temp_bubblelist = msg.bubblelist(i);
		bubbleList[i].read_from_pbmsg(temp_bubblelist);
	}
	cur_bubble_id = msg.cur_bubble_id();
}

CharacterDBOnlineGiftInfo_s::CharacterDBOnlineGiftInfo_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int CharacterDBOnlineGiftInfo_s::CreateInit() {
	id = (int32_t)0;
	state = (int32_t)0;
	return 0;
}

int CharacterDBOnlineGiftInfo_s::ResumeInit() {
	return 0;
}

void CharacterDBOnlineGiftInfo_s::write_to_pbmsg(::proto_ff::CharacterDBOnlineGiftInfo & msg) const {
	msg.set_id((int32_t)id);
	msg.set_state((int32_t)state);
}

void CharacterDBOnlineGiftInfo_s::read_from_pbmsg(const ::proto_ff::CharacterDBOnlineGiftInfo & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct CharacterDBOnlineGiftInfo_s));
	id = msg.id();
	state = msg.state();
}

CharacterDBOnlineGiftData_s::CharacterDBOnlineGiftData_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int CharacterDBOnlineGiftData_s::CreateInit() {
	online_time = (int32_t)0;
	reset_day = (int32_t)0;
	lasttime = (int64_t)0;
	return 0;
}

int CharacterDBOnlineGiftData_s::ResumeInit() {
	return 0;
}

void CharacterDBOnlineGiftData_s::write_to_pbmsg(::proto_ff::CharacterDBOnlineGiftData & msg) const {
	msg.set_online_time((int32_t)online_time);
	for(int32_t i = 0; i < (int32_t)infos.GetSize() && i < infos.GetMaxSize(); ++i) {
		::proto_ff::CharacterDBOnlineGiftInfo* temp_infos = msg.add_infos();
		infos[i].write_to_pbmsg(*temp_infos);
	}
	msg.set_reset_day((int32_t)reset_day);
	msg.set_lasttime((int64_t)lasttime);
}

void CharacterDBOnlineGiftData_s::read_from_pbmsg(const ::proto_ff::CharacterDBOnlineGiftData & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct CharacterDBOnlineGiftData_s));
	online_time = msg.online_time();
	infos.SetSize(msg.infos_size() > infos.GetMaxSize() ? infos.GetMaxSize() : msg.infos_size());
	for(int32_t i = 0; i < (int32_t)infos.GetSize(); ++i) {
		const ::proto_ff::CharacterDBOnlineGiftInfo & temp_infos = msg.infos(i);
		infos[i].read_from_pbmsg(temp_infos);
	}
	reset_day = msg.reset_day();
	lasttime = msg.lasttime();
}

CharDropItemDBProto_s::CharDropItemDBProto_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int CharDropItemDBProto_s::CreateInit() {
	itemid = (uint64_t)0;
	num = (int64_t)0;
	return 0;
}

int CharDropItemDBProto_s::ResumeInit() {
	return 0;
}

void CharDropItemDBProto_s::write_to_pbmsg(::proto_ff::CharDropItemDBProto & msg) const {
	msg.set_itemid((uint64_t)itemid);
	msg.set_num((int64_t)num);
}

void CharDropItemDBProto_s::read_from_pbmsg(const ::proto_ff::CharDropItemDBProto & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct CharDropItemDBProto_s));
	itemid = msg.itemid();
	num = msg.num();
}

CharDropMultItemDBProto_s::CharDropMultItemDBProto_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int CharDropMultItemDBProto_s::CreateInit() {
	return 0;
}

int CharDropMultItemDBProto_s::ResumeInit() {
	return 0;
}

void CharDropMultItemDBProto_s::write_to_pbmsg(::proto_ff::CharDropMultItemDBProto & msg) const {
	for(int32_t i = 0; i < (int32_t)info.GetSize() && i < info.GetMaxSize(); ++i) {
		::proto_ff::CharDropItemDBProto* temp_info = msg.add_info();
		info[i].write_to_pbmsg(*temp_info);
	}
}

void CharDropMultItemDBProto_s::read_from_pbmsg(const ::proto_ff::CharDropMultItemDBProto & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct CharDropMultItemDBProto_s));
	info.SetSize(msg.info_size() > info.GetMaxSize() ? info.GetMaxSize() : msg.info_size());
	for(int32_t i = 0; i < (int32_t)info.GetSize(); ++i) {
		const ::proto_ff::CharDropItemDBProto & temp_info = msg.info(i);
		info[i].read_from_pbmsg(temp_info);
	}
}

CharDropLimitDBData_s::CharDropLimitDBData_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int CharDropLimitDBData_s::CreateInit() {
	fresh_time = (uint64_t)0;
	return 0;
}

int CharDropLimitDBData_s::ResumeInit() {
	return 0;
}

void CharDropLimitDBData_s::write_to_pbmsg(::proto_ff::CharDropLimitDBData & msg) const {
	::proto_ff::CharDropMultItemDBProto* temp_limit = msg.mutable_limit();
	limit.write_to_pbmsg(*temp_limit);
	msg.set_fresh_time((uint64_t)fresh_time);
}

void CharDropLimitDBData_s::read_from_pbmsg(const ::proto_ff::CharDropLimitDBData & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct CharDropLimitDBData_s));
	const ::proto_ff::CharDropMultItemDBProto & temp_limit = msg.limit();
	limit.read_from_pbmsg(temp_limit);
	fresh_time = msg.fresh_time();
}

CharacterDBGmHelpData_s::CharacterDBGmHelpData_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int CharacterDBGmHelpData_s::CreateInit() {
	timeEnd = (int64_t)0;
	helpTime = (int64_t)0;
	helpDay = (int32_t)0;
	applyTime = (int64_t)0;
	applyDay = (int32_t)0;
	helpcid = (int64_t)0;
	applyResult = (int32_t)0;
	return 0;
}

int CharacterDBGmHelpData_s::ResumeInit() {
	return 0;
}

void CharacterDBGmHelpData_s::write_to_pbmsg(::proto_ff::CharacterDBGmHelpData & msg) const {
	msg.set_timeend((int64_t)timeEnd);
	msg.set_helptime((int64_t)helpTime);
	msg.set_helpday((int32_t)helpDay);
	msg.set_applytime((int64_t)applyTime);
	msg.set_applyday((int32_t)applyDay);
	msg.set_helpcid((int64_t)helpcid);
	for(int32_t i = 0; i < (int32_t)helpState.GetSize() && i < helpState.GetMaxSize(); ++i) {
		::proto_ff::ComPair* temp_helpstate = msg.add_helpstate();
		helpState[i].write_to_pbmsg(*temp_helpstate);
	}
	msg.set_applyresult((int32_t)applyResult);
}

void CharacterDBGmHelpData_s::read_from_pbmsg(const ::proto_ff::CharacterDBGmHelpData & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct CharacterDBGmHelpData_s));
	timeEnd = msg.timeend();
	helpTime = msg.helptime();
	helpDay = msg.helpday();
	applyTime = msg.applytime();
	applyDay = msg.applyday();
	helpcid = msg.helpcid();
	helpState.SetSize(msg.helpstate_size() > helpState.GetMaxSize() ? helpState.GetMaxSize() : msg.helpstate_size());
	for(int32_t i = 0; i < (int32_t)helpState.GetSize(); ++i) {
		const ::proto_ff::ComPair & temp_helpstate = msg.helpstate(i);
		helpState[i].read_from_pbmsg(temp_helpstate);
	}
	applyResult = msg.applyresult();
}

GMToolsDB_s::GMToolsDB_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int GMToolsDB_s::CreateInit() {
	refresh_time = (uint64_t)0;
	cur_use = (uint64_t)0;
	return 0;
}

int GMToolsDB_s::ResumeInit() {
	return 0;
}

void GMToolsDB_s::write_to_pbmsg(::proto_ff::GMToolsDB & msg) const {
	for(int32_t i = 0; i < (int32_t)gifts.GetSize() && i < gifts.GetMaxSize(); ++i) {
		msg.add_gifts((int32_t)gifts[i]);
	}
	for(int32_t i = 0; i < (int32_t)unlimits.GetSize() && i < unlimits.GetMaxSize(); ++i) {
		::proto_ff::ComPair* temp_unlimits = msg.add_unlimits();
		unlimits[i].write_to_pbmsg(*temp_unlimits);
	}
	msg.set_refresh_time((uint64_t)refresh_time);
	msg.set_cur_use((uint64_t)cur_use);
}

void GMToolsDB_s::read_from_pbmsg(const ::proto_ff::GMToolsDB & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct GMToolsDB_s));
	gifts.SetSize(msg.gifts_size() > gifts.GetMaxSize() ? gifts.GetMaxSize() : msg.gifts_size());
	for(int32_t i = 0; i < (int32_t)gifts.GetSize(); ++i) {
		gifts[i] = msg.gifts(i);
	}
	unlimits.SetSize(msg.unlimits_size() > unlimits.GetMaxSize() ? unlimits.GetMaxSize() : msg.unlimits_size());
	for(int32_t i = 0; i < (int32_t)unlimits.GetSize(); ++i) {
		const ::proto_ff::ComPair & temp_unlimits = msg.unlimits(i);
		unlimits[i].read_from_pbmsg(temp_unlimits);
	}
	refresh_time = msg.refresh_time();
	cur_use = msg.cur_use();
}

CharacterDBGodGMData_s::CharacterDBGodGMData_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int CharacterDBGodGMData_s::CreateInit() {
	curType = (int32_t)0;
	timeEnd = (int64_t)0;
	curExchangeNum = (int32_t)0;
	normalGiftState = (int32_t)0;
	seniorGiftState = (int32_t)0;
	lastTime = (int64_t)0;
	unlock = (int32_t)0;
	return 0;
}

int CharacterDBGodGMData_s::ResumeInit() {
	return 0;
}

void CharacterDBGodGMData_s::write_to_pbmsg(::proto_ff::CharacterDBGodGMData & msg) const {
	msg.set_curtype((int32_t)curType);
	msg.set_timeend((int64_t)timeEnd);
	msg.set_curexchangenum((int32_t)curExchangeNum);
	msg.set_normalgiftstate((int32_t)normalGiftState);
	msg.set_seniorgiftstate((int32_t)seniorGiftState);
	msg.set_lasttime((int64_t)lastTime);
	msg.set_unlock((int32_t)unlock);
	::proto_ff::GMToolsDB* temp_gmtool = msg.mutable_gmtool();
	gmtool.write_to_pbmsg(*temp_gmtool);
}

void CharacterDBGodGMData_s::read_from_pbmsg(const ::proto_ff::CharacterDBGodGMData & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct CharacterDBGodGMData_s));
	curType = msg.curtype();
	timeEnd = msg.timeend();
	curExchangeNum = msg.curexchangenum();
	normalGiftState = msg.normalgiftstate();
	seniorGiftState = msg.seniorgiftstate();
	lastTime = msg.lasttime();
	unlock = msg.unlock();
	const ::proto_ff::GMToolsDB & temp_gmtool = msg.gmtool();
	gmtool.read_from_pbmsg(temp_gmtool);
}

BowlDBRewardProto_s::BowlDBRewardProto_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int BowlDBRewardProto_s::CreateInit() {
	recharge_id = (uint32_t)0;
	count = (uint32_t)0;
	return 0;
}

int BowlDBRewardProto_s::ResumeInit() {
	return 0;
}

void BowlDBRewardProto_s::write_to_pbmsg(::proto_ff::BowlDBRewardProto & msg) const {
	msg.set_recharge_id((uint32_t)recharge_id);
	msg.set_count((uint32_t)count);
}

void BowlDBRewardProto_s::read_from_pbmsg(const ::proto_ff::BowlDBRewardProto & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct BowlDBRewardProto_s));
	recharge_id = msg.recharge_id();
	count = msg.count();
}

BowlDBData_s::BowlDBData_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int BowlDBData_s::CreateInit() {
	level = (uint32_t)0;
	active = (int32_t)0;
	return 0;
}

int BowlDBData_s::ResumeInit() {
	return 0;
}

void BowlDBData_s::write_to_pbmsg(::proto_ff::BowlDBData & msg) const {
	msg.set_level((uint32_t)level);
	msg.set_active((int32_t)active);
	for(int32_t i = 0; i < (int32_t)info.GetSize() && i < info.GetMaxSize(); ++i) {
		::proto_ff::BowlDBRewardProto* temp_info = msg.add_info();
		info[i].write_to_pbmsg(*temp_info);
	}
}

void BowlDBData_s::read_from_pbmsg(const ::proto_ff::BowlDBData & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct BowlDBData_s));
	level = msg.level();
	active = msg.active();
	info.SetSize(msg.info_size() > info.GetMaxSize() ? info.GetMaxSize() : msg.info_size());
	for(int32_t i = 0; i < (int32_t)info.GetSize(); ++i) {
		const ::proto_ff::BowlDBRewardProto & temp_info = msg.info(i);
		info[i].read_from_pbmsg(temp_info);
	}
}

HidePeriodDBProto_s::HidePeriodDBProto_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int HidePeriodDBProto_s::CreateInit() {
	id = (int32_t)0;
	total = (uint64_t)0;
	reward = (int32_t)0;
	lasttime = (uint64_t)0;
	return 0;
}

int HidePeriodDBProto_s::ResumeInit() {
	return 0;
}

void HidePeriodDBProto_s::write_to_pbmsg(::proto_ff::HidePeriodDBProto & msg) const {
	msg.set_id((int32_t)id);
	msg.set_total((uint64_t)total);
	msg.set_reward((int32_t)reward);
	msg.set_lasttime((uint64_t)lasttime);
}

void HidePeriodDBProto_s::read_from_pbmsg(const ::proto_ff::HidePeriodDBProto & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct HidePeriodDBProto_s));
	id = msg.id();
	total = msg.total();
	reward = msg.reward();
	lasttime = msg.lasttime();
}

CharacterDBHideData_s::CharacterDBHideData_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int CharacterDBHideData_s::CreateInit() {
	forever_quota = (int32_t)0;
	lastTime = (int64_t)0;
	unit_quota = (int32_t)0;
	ctime = (int64_t)0;
	days = (int32_t)0;
	return 0;
}

int CharacterDBHideData_s::ResumeInit() {
	return 0;
}

void CharacterDBHideData_s::write_to_pbmsg(::proto_ff::CharacterDBHideData & msg) const {
	msg.set_forever_quota((int32_t)forever_quota);
	msg.set_lasttime((int64_t)lastTime);
	msg.set_unit_quota((int32_t)unit_quota);
	for(int32_t i = 0; i < (int32_t)unit_ids.GetSize() && i < unit_ids.GetMaxSize(); ++i) {
		msg.add_unit_ids((int32_t)unit_ids[i]);
	}
	for(int32_t i = 0; i < (int32_t)unit_once_ids.GetSize() && i < unit_once_ids.GetMaxSize(); ++i) {
		msg.add_unit_once_ids((int32_t)unit_once_ids[i]);
	}
	for(int32_t i = 0; i < (int32_t)f_ids.GetSize() && i < f_ids.GetMaxSize(); ++i) {
		msg.add_f_ids((int32_t)f_ids[i]);
	}
	msg.set_ctime((int64_t)ctime);
	msg.set_days((int32_t)days);
	for(int32_t i = 0; i < (int32_t)period.GetSize() && i < period.GetMaxSize(); ++i) {
		::proto_ff::HidePeriodDBProto* temp_period = msg.add_period();
		period[i].write_to_pbmsg(*temp_period);
	}
}

void CharacterDBHideData_s::read_from_pbmsg(const ::proto_ff::CharacterDBHideData & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct CharacterDBHideData_s));
	forever_quota = msg.forever_quota();
	lastTime = msg.lasttime();
	unit_quota = msg.unit_quota();
	unit_ids.SetSize(msg.unit_ids_size() > unit_ids.GetMaxSize() ? unit_ids.GetMaxSize() : msg.unit_ids_size());
	for(int32_t i = 0; i < (int32_t)unit_ids.GetSize(); ++i) {
		unit_ids[i] = msg.unit_ids(i);
	}
	unit_once_ids.SetSize(msg.unit_once_ids_size() > unit_once_ids.GetMaxSize() ? unit_once_ids.GetMaxSize() : msg.unit_once_ids_size());
	for(int32_t i = 0; i < (int32_t)unit_once_ids.GetSize(); ++i) {
		unit_once_ids[i] = msg.unit_once_ids(i);
	}
	f_ids.SetSize(msg.f_ids_size() > f_ids.GetMaxSize() ? f_ids.GetMaxSize() : msg.f_ids_size());
	for(int32_t i = 0; i < (int32_t)f_ids.GetSize(); ++i) {
		f_ids[i] = msg.f_ids(i);
	}
	ctime = msg.ctime();
	days = msg.days();
	period.SetSize(msg.period_size() > period.GetMaxSize() ? period.GetMaxSize() : msg.period_size());
	for(int32_t i = 0; i < (int32_t)period.GetSize(); ++i) {
		const ::proto_ff::HidePeriodDBProto & temp_period = msg.period(i);
		period[i].read_from_pbmsg(temp_period);
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
	deletechartime = (uint64_t)0;
	dirty = (int32_t)0;
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
	msg.set_deletechartime((uint64_t)deletechartime);
	msg.set_dirty((int32_t)dirty);
	::proto_ff::CharacterDBBaseInfo* temp_basedata = msg.mutable_basedata();
	baseData.write_to_pbmsg(*temp_basedata);
	::proto_ff::CharacterDBPackageData* temp_itemdata = msg.mutable_itemdata();
	itemData.write_to_pbmsg(*temp_itemdata);
	::proto_ff::CharacterDBTaskData* temp_taskdata = msg.mutable_taskdata();
	taskData.write_to_pbmsg(*temp_taskdata);
	::proto_ff::CharacterDBSkillData* temp_skilldata = msg.mutable_skilldata();
	skillData.write_to_pbmsg(*temp_skilldata);
	::proto_ff::CharacterDBExtendData* temp_extenddata = msg.mutable_extenddata();
	extendData.write_to_pbmsg(*temp_extenddata);
	::proto_ff::CharacterDBEquipData* temp_equipdata = msg.mutable_equipdata();
	equipData.write_to_pbmsg(*temp_equipdata);
	::proto_ff::CharacterDBDuplicateData* temp_duplicatedata = msg.mutable_duplicatedata();
	duplicateData.write_to_pbmsg(*temp_duplicatedata);
	::proto_ff::CharacterAchievementDBData* temp_achievementdata = msg.mutable_achievementdata();
	achievementData.write_to_pbmsg(*temp_achievementdata);
	::proto_ff::CharacterBuffData* temp_buffdata = msg.mutable_buffdata();
	buffData.write_to_pbmsg(*temp_buffdata);
	::proto_ff::CharacterArenaData* temp_arenadata = msg.mutable_arenadata();
	arenaData.write_to_pbmsg(*temp_arenadata);
	::proto_ff::CharacterTitleSaveData* temp_titledata = msg.mutable_titledata();
	titleData.write_to_pbmsg(*temp_titledata);
	::proto_ff::CharacterDBOperateLimitInfo* temp_operatelimitdata = msg.mutable_operatelimitdata();
	operateLimitData.write_to_pbmsg(*temp_operatelimitdata);
	::proto_ff::CharacterDBHuoYueDuInfo* temp_huoyuedudata = msg.mutable_huoyuedudata();
	huoYueDuData.write_to_pbmsg(*temp_huoyuedudata);
	::proto_ff::CharacterDBOperateData* temp_operatedata = msg.mutable_operatedata();
	operateData.write_to_pbmsg(*temp_operatedata);
	::proto_ff::CharacterDBActiveInfo* temp_playeractiveinfo = msg.mutable_playeractiveinfo();
	playerActiveInfo.write_to_pbmsg(*temp_playeractiveinfo);
	::proto_ff::CharacterPayData* temp_cpaydata = msg.mutable_cpaydata();
	cPayData.write_to_pbmsg(*temp_cpaydata);
	::proto_ff::FunctionUnlockInfo* temp_unlockinfo = msg.mutable_unlockinfo();
	unlockInfo.write_to_pbmsg(*temp_unlockinfo);
	::proto_ff::CharacterDBEmblemData* temp_emblemdata = msg.mutable_emblemdata();
	emblemData.write_to_pbmsg(*temp_emblemdata);
	::proto_ff::CharacterDBIdentifyData* temp_identifydata = msg.mutable_identifydata();
	identifyData.write_to_pbmsg(*temp_identifydata);
	::proto_ff::CharacterDBElementData* temp_elementdata = msg.mutable_elementdata();
	elementData.write_to_pbmsg(*temp_elementdata);
	::proto_ff::CharacterDBFashionData* temp_fashiondata = msg.mutable_fashiondata();
	fashionData.write_to_pbmsg(*temp_fashiondata);
	::proto_ff::CharacterDBWingData* temp_wingdata = msg.mutable_wingdata();
	wingData.write_to_pbmsg(*temp_wingdata);
	::proto_ff::CharacterDBMountData* temp_mountdata = msg.mutable_mountdata();
	mountData.write_to_pbmsg(*temp_mountdata);
	::proto_ff::CharacterDBBossData* temp_bossdata = msg.mutable_bossdata();
	bossData.write_to_pbmsg(*temp_bossdata);
	::proto_ff::CharacterDBPvpData* temp_pvpdata = msg.mutable_pvpdata();
	pvpData.write_to_pbmsg(*temp_pvpdata);
	::proto_ff::CharacterDBTreasureData* temp_treasure_data = msg.mutable_treasure_data();
	treasure_data.write_to_pbmsg(*temp_treasure_data);
	::proto_ff::CharacterDBArtifactData* temp_artifact_data = msg.mutable_artifact_data();
	artifact_data.write_to_pbmsg(*temp_artifact_data);
	::proto_ff::CharacterDBFateStarData* temp_fatestardata = msg.mutable_fatestardata();
	fateStarData.write_to_pbmsg(*temp_fatestardata);
	::proto_ff::CharacterDBConvoyData* temp_convoydata = msg.mutable_convoydata();
	convoyData.write_to_pbmsg(*temp_convoydata);
	::proto_ff::CharacterDBDailyData* temp_daily_data = msg.mutable_daily_data();
	daily_data.write_to_pbmsg(*temp_daily_data);
	::proto_ff::CharacterDBFieldData* temp_field_data = msg.mutable_field_data();
	field_data.write_to_pbmsg(*temp_field_data);
	::proto_ff::CharacterDBVipData* temp_vipdata = msg.mutable_vipdata();
	vipData.write_to_pbmsg(*temp_vipdata);
	::proto_ff::CharacterDBPartnerData* temp_partnerdata = msg.mutable_partnerdata();
	partnerData.write_to_pbmsg(*temp_partnerdata);
	::proto_ff::CharacterDBMallData* temp_malldata = msg.mutable_malldata();
	mallData.write_to_pbmsg(*temp_malldata);
	::proto_ff::CharacterDBGodhoodData* temp_godhooddata = msg.mutable_godhooddata();
	godhoodData.write_to_pbmsg(*temp_godhooddata);
	::proto_ff::CharacterDBRecoveryData* temp_recoverydata = msg.mutable_recoverydata();
	recoveryData.write_to_pbmsg(*temp_recoverydata);
	::proto_ff::CharacterDBActivityData* temp_activitydata = msg.mutable_activitydata();
	activityData.write_to_pbmsg(*temp_activitydata);
	::proto_ff::CharacterDBSOAcitveData* temp_soactivitydata = msg.mutable_soactivitydata();
	soActivityData.write_to_pbmsg(*temp_soactivitydata);
	::proto_ff::CharacterDBUseItemData* temp_useitemdata = msg.mutable_useitemdata();
	useitemData.write_to_pbmsg(*temp_useitemdata);
	::proto_ff::CharacterDBDayUseItemData* temp_dayuseitemdata = msg.mutable_dayuseitemdata();
	dayUseItemData.write_to_pbmsg(*temp_dayuseitemdata);
	::proto_ff::CharacterDBMysteryShopData* temp_mysteryshop_data = msg.mutable_mysteryshop_data();
	mysteryshop_data.write_to_pbmsg(*temp_mysteryshop_data);
	::proto_ff::CharacterDBPackageTestRebateData* temp_packagetestrebate_data = msg.mutable_packagetestrebate_data();
	packagetestrebate_data.write_to_pbmsg(*temp_packagetestrebate_data);
	::proto_ff::FuncFightDBData* temp_fight_data = msg.mutable_fight_data();
	fight_data.write_to_pbmsg(*temp_fight_data);
	::proto_ff::PowerInfoDBList* temp_power_data = msg.mutable_power_data();
	power_data.write_to_pbmsg(*temp_power_data);
	::proto_ff::OccupationTakeList* temp_occupation_data = msg.mutable_occupation_data();
	occupation_data.write_to_pbmsg(*temp_occupation_data);
	::proto_ff::CharacterDBHeadSetData* temp_headset_data = msg.mutable_headset_data();
	headset_data.write_to_pbmsg(*temp_headset_data);
	::proto_ff::CharacterDBOnlineGiftData* temp_online_gift_data = msg.mutable_online_gift_data();
	online_gift_data.write_to_pbmsg(*temp_online_gift_data);
	::proto_ff::CharDropLimitDBData* temp_droplimit_data = msg.mutable_droplimit_data();
	droplimit_data.write_to_pbmsg(*temp_droplimit_data);
	::proto_ff::CharacterDBGmHelpData* temp_gmhelp_data = msg.mutable_gmhelp_data();
	gmhelp_data.write_to_pbmsg(*temp_gmhelp_data);
	::proto_ff::CharacterDBGodGMData* temp_godgm_data = msg.mutable_godgm_data();
	godgm_data.write_to_pbmsg(*temp_godgm_data);
	::proto_ff::BowlDBData* temp_bowl_data = msg.mutable_bowl_data();
	bowl_data.write_to_pbmsg(*temp_bowl_data);
	::proto_ff::CharacterDBPackageData* temp_bagitemdata = msg.mutable_bagitemdata();
	bagitemData.write_to_pbmsg(*temp_bagitemdata);
	::proto_ff::CharacterDBHideData* temp_hide_data = msg.mutable_hide_data();
	hide_data.write_to_pbmsg(*temp_hide_data);
}

void tbRoleInfo_s::read_from_pbmsg(const ::proto_ff::tbRoleInfo & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct tbRoleInfo_s));
	charId = msg.charid();
	playerId = msg.playerid();
	bornZoneId = msg.bornzoneid();
	charName.Copy(msg.charname());
	platId.Copy(msg.platid());
	deletechartime = msg.deletechartime();
	dirty = msg.dirty();
	const ::proto_ff::CharacterDBBaseInfo & temp_basedata = msg.basedata();
	baseData.read_from_pbmsg(temp_basedata);
	const ::proto_ff::CharacterDBPackageData & temp_itemdata = msg.itemdata();
	itemData.read_from_pbmsg(temp_itemdata);
	const ::proto_ff::CharacterDBTaskData & temp_taskdata = msg.taskdata();
	taskData.read_from_pbmsg(temp_taskdata);
	const ::proto_ff::CharacterDBSkillData & temp_skilldata = msg.skilldata();
	skillData.read_from_pbmsg(temp_skilldata);
	const ::proto_ff::CharacterDBExtendData & temp_extenddata = msg.extenddata();
	extendData.read_from_pbmsg(temp_extenddata);
	const ::proto_ff::CharacterDBEquipData & temp_equipdata = msg.equipdata();
	equipData.read_from_pbmsg(temp_equipdata);
	const ::proto_ff::CharacterDBDuplicateData & temp_duplicatedata = msg.duplicatedata();
	duplicateData.read_from_pbmsg(temp_duplicatedata);
	const ::proto_ff::CharacterAchievementDBData & temp_achievementdata = msg.achievementdata();
	achievementData.read_from_pbmsg(temp_achievementdata);
	const ::proto_ff::CharacterBuffData & temp_buffdata = msg.buffdata();
	buffData.read_from_pbmsg(temp_buffdata);
	const ::proto_ff::CharacterArenaData & temp_arenadata = msg.arenadata();
	arenaData.read_from_pbmsg(temp_arenadata);
	const ::proto_ff::CharacterTitleSaveData & temp_titledata = msg.titledata();
	titleData.read_from_pbmsg(temp_titledata);
	const ::proto_ff::CharacterDBOperateLimitInfo & temp_operatelimitdata = msg.operatelimitdata();
	operateLimitData.read_from_pbmsg(temp_operatelimitdata);
	const ::proto_ff::CharacterDBHuoYueDuInfo & temp_huoyuedudata = msg.huoyuedudata();
	huoYueDuData.read_from_pbmsg(temp_huoyuedudata);
	const ::proto_ff::CharacterDBOperateData & temp_operatedata = msg.operatedata();
	operateData.read_from_pbmsg(temp_operatedata);
	const ::proto_ff::CharacterDBActiveInfo & temp_playeractiveinfo = msg.playeractiveinfo();
	playerActiveInfo.read_from_pbmsg(temp_playeractiveinfo);
	const ::proto_ff::CharacterPayData & temp_cpaydata = msg.cpaydata();
	cPayData.read_from_pbmsg(temp_cpaydata);
	const ::proto_ff::FunctionUnlockInfo & temp_unlockinfo = msg.unlockinfo();
	unlockInfo.read_from_pbmsg(temp_unlockinfo);
	const ::proto_ff::CharacterDBEmblemData & temp_emblemdata = msg.emblemdata();
	emblemData.read_from_pbmsg(temp_emblemdata);
	const ::proto_ff::CharacterDBIdentifyData & temp_identifydata = msg.identifydata();
	identifyData.read_from_pbmsg(temp_identifydata);
	const ::proto_ff::CharacterDBElementData & temp_elementdata = msg.elementdata();
	elementData.read_from_pbmsg(temp_elementdata);
	const ::proto_ff::CharacterDBFashionData & temp_fashiondata = msg.fashiondata();
	fashionData.read_from_pbmsg(temp_fashiondata);
	const ::proto_ff::CharacterDBWingData & temp_wingdata = msg.wingdata();
	wingData.read_from_pbmsg(temp_wingdata);
	const ::proto_ff::CharacterDBMountData & temp_mountdata = msg.mountdata();
	mountData.read_from_pbmsg(temp_mountdata);
	const ::proto_ff::CharacterDBBossData & temp_bossdata = msg.bossdata();
	bossData.read_from_pbmsg(temp_bossdata);
	const ::proto_ff::CharacterDBPvpData & temp_pvpdata = msg.pvpdata();
	pvpData.read_from_pbmsg(temp_pvpdata);
	const ::proto_ff::CharacterDBTreasureData & temp_treasure_data = msg.treasure_data();
	treasure_data.read_from_pbmsg(temp_treasure_data);
	const ::proto_ff::CharacterDBArtifactData & temp_artifact_data = msg.artifact_data();
	artifact_data.read_from_pbmsg(temp_artifact_data);
	const ::proto_ff::CharacterDBFateStarData & temp_fatestardata = msg.fatestardata();
	fateStarData.read_from_pbmsg(temp_fatestardata);
	const ::proto_ff::CharacterDBConvoyData & temp_convoydata = msg.convoydata();
	convoyData.read_from_pbmsg(temp_convoydata);
	const ::proto_ff::CharacterDBDailyData & temp_daily_data = msg.daily_data();
	daily_data.read_from_pbmsg(temp_daily_data);
	const ::proto_ff::CharacterDBFieldData & temp_field_data = msg.field_data();
	field_data.read_from_pbmsg(temp_field_data);
	const ::proto_ff::CharacterDBVipData & temp_vipdata = msg.vipdata();
	vipData.read_from_pbmsg(temp_vipdata);
	const ::proto_ff::CharacterDBPartnerData & temp_partnerdata = msg.partnerdata();
	partnerData.read_from_pbmsg(temp_partnerdata);
	const ::proto_ff::CharacterDBMallData & temp_malldata = msg.malldata();
	mallData.read_from_pbmsg(temp_malldata);
	const ::proto_ff::CharacterDBGodhoodData & temp_godhooddata = msg.godhooddata();
	godhoodData.read_from_pbmsg(temp_godhooddata);
	const ::proto_ff::CharacterDBRecoveryData & temp_recoverydata = msg.recoverydata();
	recoveryData.read_from_pbmsg(temp_recoverydata);
	const ::proto_ff::CharacterDBActivityData & temp_activitydata = msg.activitydata();
	activityData.read_from_pbmsg(temp_activitydata);
	const ::proto_ff::CharacterDBSOAcitveData & temp_soactivitydata = msg.soactivitydata();
	soActivityData.read_from_pbmsg(temp_soactivitydata);
	const ::proto_ff::CharacterDBUseItemData & temp_useitemdata = msg.useitemdata();
	useitemData.read_from_pbmsg(temp_useitemdata);
	const ::proto_ff::CharacterDBDayUseItemData & temp_dayuseitemdata = msg.dayuseitemdata();
	dayUseItemData.read_from_pbmsg(temp_dayuseitemdata);
	const ::proto_ff::CharacterDBMysteryShopData & temp_mysteryshop_data = msg.mysteryshop_data();
	mysteryshop_data.read_from_pbmsg(temp_mysteryshop_data);
	const ::proto_ff::CharacterDBPackageTestRebateData & temp_packagetestrebate_data = msg.packagetestrebate_data();
	packagetestrebate_data.read_from_pbmsg(temp_packagetestrebate_data);
	const ::proto_ff::FuncFightDBData & temp_fight_data = msg.fight_data();
	fight_data.read_from_pbmsg(temp_fight_data);
	const ::proto_ff::PowerInfoDBList & temp_power_data = msg.power_data();
	power_data.read_from_pbmsg(temp_power_data);
	const ::proto_ff::OccupationTakeList & temp_occupation_data = msg.occupation_data();
	occupation_data.read_from_pbmsg(temp_occupation_data);
	const ::proto_ff::CharacterDBHeadSetData & temp_headset_data = msg.headset_data();
	headset_data.read_from_pbmsg(temp_headset_data);
	const ::proto_ff::CharacterDBOnlineGiftData & temp_online_gift_data = msg.online_gift_data();
	online_gift_data.read_from_pbmsg(temp_online_gift_data);
	const ::proto_ff::CharDropLimitDBData & temp_droplimit_data = msg.droplimit_data();
	droplimit_data.read_from_pbmsg(temp_droplimit_data);
	const ::proto_ff::CharacterDBGmHelpData & temp_gmhelp_data = msg.gmhelp_data();
	gmhelp_data.read_from_pbmsg(temp_gmhelp_data);
	const ::proto_ff::CharacterDBGodGMData & temp_godgm_data = msg.godgm_data();
	godgm_data.read_from_pbmsg(temp_godgm_data);
	const ::proto_ff::BowlDBData & temp_bowl_data = msg.bowl_data();
	bowl_data.read_from_pbmsg(temp_bowl_data);
	const ::proto_ff::CharacterDBPackageData & temp_bagitemdata = msg.bagitemdata();
	bagitemData.read_from_pbmsg(temp_bagitemdata);
	const ::proto_ff::CharacterDBHideData & temp_hide_data = msg.hide_data();
	hide_data.read_from_pbmsg(temp_hide_data);
}

CharacterDBSimpleInfo_s::CharacterDBSimpleInfo_s() {
	CreateInit();
}

int CharacterDBSimpleInfo_s::CreateInit() {
	charId = (uint64_t)0;
	sex = (uint32_t)0;
	prof = (uint32_t)0;
	level = (uint32_t)0;
	exp = (int64_t)0;
	hp = (uint64_t)0;
	fightPower = (uint64_t)0;
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
	curstate = (int32_t)0;
	deletechartime = (uint64_t)0;
	createTime = (uint64_t)0;
	totalpay = (uint32_t)0;
	clx = (float)0;
	cly = (float)0;
	clz = (float)0;
	occupation = (uint64_t)0;
	aptitude = (uint64_t)0;
	finish_flag = (int32_t)0;
	palace_layer = (int32_t)0;
	palace_break_count = (int32_t)0;
	dirty = (int32_t)0;
	return 0;
}

int CharacterDBSimpleInfo_s::ResumeInit() {
	return 0;
}

void CharacterDBSimpleInfo_s::write_to_pbmsg(::proto_ff::CharacterDBSimpleInfo & msg) const {
	msg.set_charid((uint64_t)charId);
	msg.set_name(name);
	msg.set_sex((uint32_t)sex);
	msg.set_prof((uint32_t)prof);
	msg.set_level((uint32_t)level);
	msg.set_exp((int64_t)exp);
	msg.set_hp((uint64_t)hp);
	msg.set_fightpower((uint64_t)fightPower);
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
	::proto_ff::CharFacadeProto* temp_facade = msg.mutable_facade();
	facade.write_to_pbmsg(*temp_facade);
	msg.set_curstate((int32_t)curstate);
	msg.set_deletechartime((uint64_t)deletechartime);
	msg.set_createtime((uint64_t)createTime);
	msg.set_totalpay((uint32_t)totalpay);
	msg.set_clx((float)clx);
	msg.set_cly((float)cly);
	msg.set_clz((float)clz);
	msg.set_occupation((uint64_t)occupation);
	msg.set_aptitude((uint64_t)aptitude);
	msg.set_finish_flag((int32_t)finish_flag);
	msg.set_platid(platid);
	msg.set_palace_layer((int32_t)palace_layer);
	msg.set_palace_break_count((int32_t)palace_break_count);
	msg.set_dirty((int32_t)dirty);
}

void CharacterDBSimpleInfo_s::read_from_pbmsg(const ::proto_ff::CharacterDBSimpleInfo & msg) {
	charId = msg.charid();
	name = msg.name();
	sex = msg.sex();
	prof = msg.prof();
	level = msg.level();
	exp = msg.exp();
	hp = msg.hp();
	fightPower = msg.fightpower();
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
	const ::proto_ff::CharFacadeProto & temp_facade = msg.facade();
	facade.read_from_pbmsg(temp_facade);
	curstate = msg.curstate();
	deletechartime = msg.deletechartime();
	createTime = msg.createtime();
	totalpay = msg.totalpay();
	clx = msg.clx();
	cly = msg.cly();
	clz = msg.clz();
	occupation = msg.occupation();
	aptitude = msg.aptitude();
	finish_flag = msg.finish_flag();
	platid = msg.platid();
	palace_layer = msg.palace_layer();
	palace_break_count = msg.palace_break_count();
	dirty = msg.dirty();
}

}