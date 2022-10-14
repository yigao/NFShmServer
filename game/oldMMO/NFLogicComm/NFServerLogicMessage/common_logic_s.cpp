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
}

}