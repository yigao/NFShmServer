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

ComItemBind_s::ComItemBind_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int ComItemBind_s::CreateInit() {
	item_id = (uint64_t)0;
	item_num = (uint64_t)0;
	bind = (int32_t)0;
	return 0;
}

int ComItemBind_s::ResumeInit() {
	return 0;
}

void ComItemBind_s::write_to_pbmsg(::proto_ff::ComItemBind & msg) const {
	msg.set_item_id((uint64_t)item_id);
	msg.set_item_num((uint64_t)item_num);
	msg.set_bind((int32_t)bind);
}

void ComItemBind_s::read_from_pbmsg(const ::proto_ff::ComItemBind & msg) {
	item_id = msg.item_id();
	item_num = msg.item_num();
	bind = msg.bind();
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

RoleHeadPicProto_s::RoleHeadPicProto_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int RoleHeadPicProto_s::CreateInit() {
	prof = (int32_t)0;
	frame = (int64_t)0;
	head = (int64_t)0;
	return 0;
}

int RoleHeadPicProto_s::ResumeInit() {
	return 0;
}

void RoleHeadPicProto_s::write_to_pbmsg(::proto_ff::RoleHeadPicProto & msg) const {
	msg.set_prof((int32_t)prof);
	msg.set_frame((int64_t)frame);
	msg.set_head((int64_t)head);
}

void RoleHeadPicProto_s::read_from_pbmsg(const ::proto_ff::RoleHeadPicProto & msg) {
	prof = msg.prof();
	frame = msg.frame();
	head = msg.head();
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

MarryBrief_s::MarryBrief_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int MarryBrief_s::CreateInit() {
	cid = (uint64_t)0;
	child_id = (int32_t)0;
	card_buy_time = (uint64_t)0;
	express_lv = (int32_t)0;
	buy_dup_num = (int32_t)0;
	marry_flag = (int32_t)0;
	dst_recv_day = (int32_t)0;
	dst_give_dup_num = (int32_t)0;
	card_surplus_day = (int32_t)0;
	return 0;
}

int MarryBrief_s::ResumeInit() {
	return 0;
}

void MarryBrief_s::write_to_pbmsg(::proto_ff::MarryBrief & msg) const {
	msg.set_cid((uint64_t)cid);
	msg.set_child_id((int32_t)child_id);
	msg.set_card_buy_time((uint64_t)card_buy_time);
	msg.set_express_lv((int32_t)express_lv);
	for(int32_t i = 0; i < (int32_t)gears.size(); ++i) {
		msg.add_gears((int32_t)gears[i]);
	}
	msg.set_buy_dup_num((int32_t)buy_dup_num);
	msg.set_marry_flag((int32_t)marry_flag);
	for(int32_t i = 0; i < (int32_t)recved_gears.size(); ++i) {
		msg.add_recved_gears((int32_t)recved_gears[i]);
	}
	msg.set_dst_recv_day((int32_t)dst_recv_day);
	msg.set_dst_give_dup_num((int32_t)dst_give_dup_num);
	msg.set_card_surplus_day((int32_t)card_surplus_day);
}

void MarryBrief_s::read_from_pbmsg(const ::proto_ff::MarryBrief & msg) {
	cid = msg.cid();
	child_id = msg.child_id();
	card_buy_time = msg.card_buy_time();
	express_lv = msg.express_lv();
	gears.resize((int)msg.gears_size() > (int)gears.max_size() ? gears.max_size() : msg.gears_size());
	for(int32_t i = 0; i < (int32_t)gears.size(); ++i) {
		gears[i] = msg.gears(i);
	}
	buy_dup_num = msg.buy_dup_num();
	marry_flag = msg.marry_flag();
	recved_gears.resize((int)msg.recved_gears_size() > (int)recved_gears.max_size() ? recved_gears.max_size() : msg.recved_gears_size());
	for(int32_t i = 0; i < (int32_t)recved_gears.size(); ++i) {
		recved_gears[i] = msg.recved_gears(i);
	}
	dst_recv_day = msg.dst_recv_day();
	dst_give_dup_num = msg.dst_give_dup_num();
	card_surplus_day = msg.card_surplus_day();
}

LoginSynMarry_s::LoginSynMarry_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int LoginSynMarry_s::CreateInit() {
	my_dst_recv_day = (int32_t)0;
	dst_give_dup_num = (int32_t)0;
	marry_id = (int32_t)0;
	return 0;
}

int LoginSynMarry_s::ResumeInit() {
	return 0;
}

void LoginSynMarry_s::write_to_pbmsg(::proto_ff::LoginSynMarry & msg) const {
	msg.set_my_dst_recv_day((int32_t)my_dst_recv_day);
	msg.set_dst_give_dup_num((int32_t)dst_give_dup_num);
	msg.set_marry_id((int32_t)marry_id);
	::proto_ff::MarryBrief* temp_brief = msg.mutable_brief();
	brief.write_to_pbmsg(*temp_brief);
	msg.set_dst_name(dst_name.data());
}

void LoginSynMarry_s::read_from_pbmsg(const ::proto_ff::LoginSynMarry & msg) {
	my_dst_recv_day = msg.my_dst_recv_day();
	dst_give_dup_num = msg.dst_give_dup_num();
	marry_id = msg.marry_id();
	const ::proto_ff::MarryBrief & temp_brief = msg.brief();
	brief.read_from_pbmsg(temp_brief);
	dst_name = msg.dst_name();
}

AoPlatProto_s::AoPlatProto_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int AoPlatProto_s::CreateInit() {
	group_id = (int32_t)0;
	is_emulator = (int32_t)0;
	screen_length = (int32_t)0;
	screen_width = (int32_t)0;
	channel_id = (int32_t)0;
	sub_channel_id = (int32_t)0;
	port = (int32_t)0;
	timezone_offset = (int32_t)0;
	return 0;
}

int AoPlatProto_s::ResumeInit() {
	return 0;
}

void AoPlatProto_s::write_to_pbmsg(::proto_ff::AoPlatProto & msg) const {
	msg.set_udid(udid.data());
	msg.set_imei(imei.data());
	msg.set_idfa(idfa.data());
	msg.set_oaid(oaid.data());
	msg.set_caid(caid.data());
	msg.set_android_id(android_id.data());
	msg.set_group_id((int32_t)group_id);
	msg.set_brand(brand.data());
	msg.set_device_model(device_model.data());
	msg.set_is_emulator((int32_t)is_emulator);
	msg.set_screen_length((int32_t)screen_length);
	msg.set_screen_width((int32_t)screen_width);
	msg.set_os_version(os_version.data());
	msg.set_network_type(network_type.data());
	msg.set_app_channel(app_channel.data());
	msg.set_app_version(app_version.data());
	msg.set_channel_id((int32_t)channel_id);
	msg.set_sub_channel_id((int32_t)sub_channel_id);
	msg.set_account_id(account_id.data());
	msg.set_ip(ip.data());
	msg.set_port((int32_t)port);
	msg.set_timezone_offset((int32_t)timezone_offset);
	msg.set_platform_tag(platform_tag.data());
}

void AoPlatProto_s::read_from_pbmsg(const ::proto_ff::AoPlatProto & msg) {
	udid = msg.udid();
	imei = msg.imei();
	idfa = msg.idfa();
	oaid = msg.oaid();
	caid = msg.caid();
	android_id = msg.android_id();
	group_id = msg.group_id();
	brand = msg.brand();
	device_model = msg.device_model();
	is_emulator = msg.is_emulator();
	screen_length = msg.screen_length();
	screen_width = msg.screen_width();
	os_version = msg.os_version();
	network_type = msg.network_type();
	app_channel = msg.app_channel();
	app_version = msg.app_version();
	channel_id = msg.channel_id();
	sub_channel_id = msg.sub_channel_id();
	account_id = msg.account_id();
	ip = msg.ip();
	port = msg.port();
	timezone_offset = msg.timezone_offset();
	platform_tag = msg.platform_tag();
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
	::proto_ff::LoginSynMarry* temp_marry = msg.mutable_marry();
	marry.write_to_pbmsg(*temp_marry);
	::proto_ff::AoPlatProto* temp_plat = msg.mutable_plat();
	plat.write_to_pbmsg(*temp_plat);
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
	const ::proto_ff::LoginSynMarry & temp_marry = msg.marry();
	marry.read_from_pbmsg(temp_marry);
	const ::proto_ff::AoPlatProto & temp_plat = msg.plat();
	plat.read_from_pbmsg(temp_plat);
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
	pt_stage = (uint32_t)0;
	active = (uint32_t)0;
	create_time = (uint64_t)0;
	sdkrmb = (uint32_t)0;
	yaota_dupid = (int32_t)0;
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
	msg.set_pt_stage((uint32_t)pt_stage);
	msg.set_active((uint32_t)active);
	msg.set_create_time((uint64_t)create_time);
	msg.set_sdkrmb((uint32_t)sdkrmb);
	msg.set_yaota_dupid((int32_t)yaota_dupid);
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
	pt_stage = msg.pt_stage();
	active = msg.active();
	create_time = msg.create_time();
	sdkrmb = msg.sdkrmb();
	yaota_dupid = msg.yaota_dupid();
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
	scenezid = (uint32_t)0;
	factionid = (uint32_t)0;
	yaota_dupid = (int32_t)0;
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
	msg.set_scenezid((uint32_t)scenezid);
	msg.set_factionid((uint32_t)factionid);
	msg.set_yaota_dupid((int32_t)yaota_dupid);
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
	scenezid = msg.scenezid();
	factionid = msg.factionid();
	yaota_dupid = msg.yaota_dupid();
}

ClanView_s::ClanView_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int ClanView_s::CreateInit() {
	clan_id = (uint64_t)0;
	cid = (uint64_t)0;
	clan_type = (int32_t)0;
	badge_id = (int32_t)0;
	return 0;
}

int ClanView_s::ResumeInit() {
	return 0;
}

void ClanView_s::write_to_pbmsg(::proto_ff::ClanView & msg) const {
	msg.set_clan_id((uint64_t)clan_id);
	msg.set_cid((uint64_t)cid);
	msg.set_clan_type((int32_t)clan_type);
	msg.set_clan_name(clan_name.data());
	msg.set_badge_id((int32_t)badge_id);
	msg.set_badge_name(badge_name.data());
}

void ClanView_s::read_from_pbmsg(const ::proto_ff::ClanView & msg) {
	clan_id = msg.clan_id();
	cid = msg.cid();
	clan_type = msg.clan_type();
	clan_name = msg.clan_name();
	badge_id = msg.badge_id();
	badge_name = msg.badge_name();
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

TurnAttr_s::TurnAttr_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int TurnAttr_s::CreateInit() {
	return 0;
}

int TurnAttr_s::ResumeInit() {
	return 0;
}

void TurnAttr_s::write_to_pbmsg(::proto_ff::TurnAttr & msg) const {
	for(int32_t i = 0; i < (int32_t)com_pos.size(); ++i) {
		msg.add_com_pos((int32_t)com_pos[i]);
	}
	for(int32_t i = 0; i < (int32_t)star_pos.size(); ++i) {
		msg.add_star_pos((int32_t)star_pos[i]);
	}
}

void TurnAttr_s::read_from_pbmsg(const ::proto_ff::TurnAttr & msg) {
	com_pos.resize((int)msg.com_pos_size() > (int)com_pos.max_size() ? com_pos.max_size() : msg.com_pos_size());
	for(int32_t i = 0; i < (int32_t)com_pos.size(); ++i) {
		com_pos[i] = msg.com_pos(i);
	}
	star_pos.resize((int)msg.star_pos_size() > (int)star_pos.max_size() ? star_pos.max_size() : msg.star_pos_size());
	for(int32_t i = 0; i < (int32_t)star_pos.size(); ++i) {
		star_pos[i] = msg.star_pos(i);
	}
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
	strong_exp = (int32_t)0;
	spec_lv = (int32_t)0;
	strong_wear_quality_exp = (int32_t)0;
	makeId = (int32_t)0;
	state = (int32_t)0;
	make_time = (uint64_t)0;
	savvy = (int32_t)0;
	evolve_lv = (int32_t)0;
	awaken_lv = (int32_t)0;
	item_chg_count = (int64_t)0;
	base_attr_percent = (uint32_t)0;
	star_attr_percent = (uint32_t)0;
	god_attr_percent = (uint32_t)0;
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
	msg.set_expiretime((uint64_t)expireTime);
	msg.set_strong_lv((int32_t)strong_lv);
	msg.set_strong_wear_quality((int32_t)strong_wear_quality);
	msg.set_strong_exp((int32_t)strong_exp);
	msg.set_spec_lv((int32_t)spec_lv);
	msg.set_strong_wear_quality_exp((int32_t)strong_wear_quality_exp);
	for(int32_t i = 0; i < (int32_t)misc.size(); ++i) {
		::proto_ff::Attr* temp_misc = msg.add_misc();
		misc[i].write_to_pbmsg(*temp_misc);
	}
	msg.set_makeid((int32_t)makeId);
	msg.set_state((int32_t)state);
	for(int32_t i = 0; i < (int32_t)gold_star.size(); ++i) {
		msg.add_gold_star((int32_t)gold_star[i]);
	}
	for(int32_t i = 0; i < (int32_t)silver_star.size(); ++i) {
		msg.add_silver_star((int32_t)silver_star[i]);
	}
	msg.set_make_time((uint64_t)make_time);
	msg.set_make_name(make_name.data());
	msg.set_savvy((int32_t)savvy);
	for(int32_t i = 0; i < (int32_t)skill.size(); ++i) {
		::proto_ff::ComPair64* temp_skill = msg.add_skill();
		skill[i].write_to_pbmsg(*temp_skill);
	}
	msg.set_evolve_lv((int32_t)evolve_lv);
	msg.set_awaken_lv((int32_t)awaken_lv);
	::proto_ff::TurnAttr* temp_turn_attr = msg.mutable_turn_attr();
	turn_attr.write_to_pbmsg(*temp_turn_attr);
	msg.set_item_chg_count((int64_t)item_chg_count);
	for(int32_t i = 0; i < (int32_t)unlock_attr_index.size(); ++i) {
		msg.add_unlock_attr_index((int32_t)unlock_attr_index[i]);
	}
	msg.set_base_attr_percent((uint32_t)base_attr_percent);
	msg.set_star_attr_percent((uint32_t)star_attr_percent);
	msg.set_god_attr_percent((uint32_t)god_attr_percent);
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
	expireTime = msg.expiretime();
	strong_lv = msg.strong_lv();
	strong_wear_quality = msg.strong_wear_quality();
	strong_exp = msg.strong_exp();
	spec_lv = msg.spec_lv();
	strong_wear_quality_exp = msg.strong_wear_quality_exp();
	misc.resize((int)msg.misc_size() > (int)misc.max_size() ? misc.max_size() : msg.misc_size());
	for(int32_t i = 0; i < (int32_t)misc.size(); ++i) {
		const ::proto_ff::Attr & temp_misc = msg.misc(i);
		misc[i].read_from_pbmsg(temp_misc);
	}
	makeId = msg.makeid();
	state = msg.state();
	gold_star.resize((int)msg.gold_star_size() > (int)gold_star.max_size() ? gold_star.max_size() : msg.gold_star_size());
	for(int32_t i = 0; i < (int32_t)gold_star.size(); ++i) {
		gold_star[i] = msg.gold_star(i);
	}
	silver_star.resize((int)msg.silver_star_size() > (int)silver_star.max_size() ? silver_star.max_size() : msg.silver_star_size());
	for(int32_t i = 0; i < (int32_t)silver_star.size(); ++i) {
		silver_star[i] = msg.silver_star(i);
	}
	make_time = msg.make_time();
	make_name = msg.make_name();
	savvy = msg.savvy();
	skill.resize((int)msg.skill_size() > (int)skill.max_size() ? skill.max_size() : msg.skill_size());
	for(int32_t i = 0; i < (int32_t)skill.size(); ++i) {
		const ::proto_ff::ComPair64 & temp_skill = msg.skill(i);
		skill[i].read_from_pbmsg(temp_skill);
	}
	evolve_lv = msg.evolve_lv();
	awaken_lv = msg.awaken_lv();
	const ::proto_ff::TurnAttr & temp_turn_attr = msg.turn_attr();
	turn_attr.read_from_pbmsg(temp_turn_attr);
	item_chg_count = msg.item_chg_count();
	unlock_attr_index.resize((int)msg.unlock_attr_index_size() > (int)unlock_attr_index.max_size() ? unlock_attr_index.max_size() : msg.unlock_attr_index_size());
	for(int32_t i = 0; i < (int32_t)unlock_attr_index.size(); ++i) {
		unlock_attr_index[i] = msg.unlock_attr_index(i);
	}
	base_attr_percent = msg.base_attr_percent();
	star_attr_percent = msg.star_attr_percent();
	god_attr_percent = msg.god_attr_percent();
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

RefineSlotInfo_s::RefineSlotInfo_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int RefineSlotInfo_s::CreateInit() {
	refine_lv = (int32_t)0;
	gm_lv = (int32_t)0;
	return 0;
}

int RefineSlotInfo_s::ResumeInit() {
	return 0;
}

void RefineSlotInfo_s::write_to_pbmsg(::proto_ff::RefineSlotInfo & msg) const {
	msg.set_refine_lv((int32_t)refine_lv);
	for(int32_t i = 0; i < (int32_t)unlocks.size(); ++i) {
		::proto_ff::ComPair* temp_unlocks = msg.add_unlocks();
		unlocks[i].write_to_pbmsg(*temp_unlocks);
	}
	msg.set_gm_lv((int32_t)gm_lv);
	for(int32_t i = 0; i < (int32_t)lock_pos.size(); ++i) {
		msg.add_lock_pos((int32_t)lock_pos[i]);
	}
}

void RefineSlotInfo_s::read_from_pbmsg(const ::proto_ff::RefineSlotInfo & msg) {
	refine_lv = msg.refine_lv();
	unlocks.resize((int)msg.unlocks_size() > (int)unlocks.max_size() ? unlocks.max_size() : msg.unlocks_size());
	for(int32_t i = 0; i < (int32_t)unlocks.size(); ++i) {
		const ::proto_ff::ComPair & temp_unlocks = msg.unlocks(i);
		unlocks[i].read_from_pbmsg(temp_unlocks);
	}
	gm_lv = msg.gm_lv();
	lock_pos.resize((int)msg.lock_pos_size() > (int)lock_pos.max_size() ? lock_pos.max_size() : msg.lock_pos_size());
	for(int32_t i = 0; i < (int32_t)lock_pos.size(); ++i) {
		lock_pos[i] = msg.lock_pos(i);
	}
}

SealSlotInfo_s::SealSlotInfo_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int SealSlotInfo_s::CreateInit() {
	slot = (int32_t)0;
	itemid = (int32_t)0;
	return 0;
}

int SealSlotInfo_s::ResumeInit() {
	return 0;
}

void SealSlotInfo_s::write_to_pbmsg(::proto_ff::SealSlotInfo & msg) const {
	msg.set_slot((int32_t)slot);
	msg.set_itemid((int32_t)itemid);
}

void SealSlotInfo_s::read_from_pbmsg(const ::proto_ff::SealSlotInfo & msg) {
	slot = msg.slot();
	itemid = msg.itemid();
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
	awaken_lv = (int32_t)0;
	awaken_break_flag = (int32_t)0;
	soaring_lv = (int32_t)0;
	quality_lv = (int32_t)0;
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
	::proto_ff::RefineSlotInfo* temp_refine = msg.mutable_refine();
	refine.write_to_pbmsg(*temp_refine);
	msg.set_awaken_lv((int32_t)awaken_lv);
	msg.set_awaken_break_flag((int32_t)awaken_break_flag);
	msg.set_soaring_lv((int32_t)soaring_lv);
	msg.set_quality_lv((int32_t)quality_lv);
	for(int32_t i = 0; i < (int32_t)seal_slots.size(); ++i) {
		::proto_ff::SealSlotInfo* temp_seal_slots = msg.add_seal_slots();
		seal_slots[i].write_to_pbmsg(*temp_seal_slots);
	}
	for(int32_t i = 0; i < (int32_t)active_seal_ids.size(); ++i) {
		msg.add_active_seal_ids((int32_t)active_seal_ids[i]);
	}
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
	const ::proto_ff::RefineSlotInfo & temp_refine = msg.refine();
	refine.read_from_pbmsg(temp_refine);
	awaken_lv = msg.awaken_lv();
	awaken_break_flag = msg.awaken_break_flag();
	soaring_lv = msg.soaring_lv();
	quality_lv = msg.quality_lv();
	seal_slots.resize((int)msg.seal_slots_size() > (int)seal_slots.max_size() ? seal_slots.max_size() : msg.seal_slots_size());
	for(int32_t i = 0; i < (int32_t)seal_slots.size(); ++i) {
		const ::proto_ff::SealSlotInfo & temp_seal_slots = msg.seal_slots(i);
		seal_slots[i].read_from_pbmsg(temp_seal_slots);
	}
	active_seal_ids.resize((int)msg.active_seal_ids_size() > (int)active_seal_ids.max_size() ? active_seal_ids.max_size() : msg.active_seal_ids_size());
	for(int32_t i = 0; i < (int32_t)active_seal_ids.size(); ++i) {
		active_seal_ids[i] = msg.active_seal_ids(i);
	}
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

PetGrow_s::PetGrow_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int PetGrow_s::CreateInit() {
	cfgid = (int32_t)0;
	stronglv = (int32_t)0;
	starlv = (int32_t)0;
	starindex = (int32_t)0;
	return 0;
}

int PetGrow_s::ResumeInit() {
	return 0;
}

void PetGrow_s::write_to_pbmsg(::proto_ff::PetGrow & msg) const {
	msg.set_cfgid((int32_t)cfgid);
	msg.set_stronglv((int32_t)stronglv);
	msg.set_starlv((int32_t)starlv);
	msg.set_starindex((int32_t)starindex);
}

void PetGrow_s::read_from_pbmsg(const ::proto_ff::PetGrow & msg) {
	cfgid = msg.cfgid();
	stronglv = msg.stronglv();
	starlv = msg.starlv();
	starindex = msg.starindex();
}

PetYaoHunSlot_s::PetYaoHunSlot_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int PetYaoHunSlot_s::CreateInit() {
	slot_pos = (int32_t)0;
	lv = (int32_t)0;
	exp = (int32_t)0;
	step = (int32_t)0;
	return 0;
}

int PetYaoHunSlot_s::ResumeInit() {
	return 0;
}

void PetYaoHunSlot_s::write_to_pbmsg(::proto_ff::PetYaoHunSlot & msg) const {
	msg.set_slot_pos((int32_t)slot_pos);
	msg.set_lv((int32_t)lv);
	msg.set_exp((int32_t)exp);
	msg.set_step((int32_t)step);
	::proto_ff::ItemProtoInfo* temp_equip = msg.mutable_equip();
	equip.write_to_pbmsg(*temp_equip);
}

void PetYaoHunSlot_s::read_from_pbmsg(const ::proto_ff::PetYaoHunSlot & msg) {
	slot_pos = msg.slot_pos();
	lv = msg.lv();
	exp = msg.exp();
	step = msg.step();
	const ::proto_ff::ItemProtoInfo & temp_equip = msg.equip();
	equip.read_from_pbmsg(temp_equip);
}

PetYaoHunEntry_s::PetYaoHunEntry_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int PetYaoHunEntry_s::CreateInit() {
	fight_pos = (int32_t)0;
	is_unlock = (int32_t)0;
	return 0;
}

int PetYaoHunEntry_s::ResumeInit() {
	return 0;
}

void PetYaoHunEntry_s::write_to_pbmsg(::proto_ff::PetYaoHunEntry & msg) const {
	msg.set_fight_pos((int32_t)fight_pos);
	msg.set_is_unlock((int32_t)is_unlock);
	for(int32_t i = 0; i < (int32_t)infos.size(); ++i) {
		::proto_ff::PetYaoHunSlot* temp_infos = msg.add_infos();
		infos[i].write_to_pbmsg(*temp_infos);
	}
	for(int32_t i = 0; i < (int32_t)suitids.size(); ++i) {
		msg.add_suitids((int32_t)suitids[i]);
	}
}

void PetYaoHunEntry_s::read_from_pbmsg(const ::proto_ff::PetYaoHunEntry & msg) {
	fight_pos = msg.fight_pos();
	is_unlock = msg.is_unlock();
	infos.resize((int)msg.infos_size() > (int)infos.max_size() ? infos.max_size() : msg.infos_size());
	for(int32_t i = 0; i < (int32_t)infos.size(); ++i) {
		const ::proto_ff::PetYaoHunSlot & temp_infos = msg.infos(i);
		infos[i].read_from_pbmsg(temp_infos);
	}
	suitids.resize((int)msg.suitids_size() > (int)suitids.max_size() ? suitids.max_size() : msg.suitids_size());
	for(int32_t i = 0; i < (int32_t)suitids.size(); ++i) {
		suitids[i] = msg.suitids(i);
	}
}

PetYaoHunModule_s::PetYaoHunModule_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int PetYaoHunModule_s::CreateInit() {
	lianyao_tq_flag = (int32_t)0;
	yaolu_lv = (int32_t)0;
	yaolu_exp = (int32_t)0;
	yaoqi = (int32_t)0;
	return 0;
}

int PetYaoHunModule_s::ResumeInit() {
	return 0;
}

void PetYaoHunModule_s::write_to_pbmsg(::proto_ff::PetYaoHunModule & msg) const {
	for(int32_t i = 0; i < (int32_t)entrys.size(); ++i) {
		::proto_ff::PetYaoHunEntry* temp_entrys = msg.add_entrys();
		entrys[i].write_to_pbmsg(*temp_entrys);
	}
	msg.set_lianyao_tq_flag((int32_t)lianyao_tq_flag);
	msg.set_yaolu_lv((int32_t)yaolu_lv);
	msg.set_yaolu_exp((int32_t)yaolu_exp);
	msg.set_yaoqi((int32_t)yaoqi);
}

void PetYaoHunModule_s::read_from_pbmsg(const ::proto_ff::PetYaoHunModule & msg) {
	entrys.resize((int)msg.entrys_size() > (int)entrys.max_size() ? entrys.max_size() : msg.entrys_size());
	for(int32_t i = 0; i < (int32_t)entrys.size(); ++i) {
		const ::proto_ff::PetYaoHunEntry & temp_entrys = msg.entrys(i);
		entrys[i].read_from_pbmsg(temp_entrys);
	}
	lianyao_tq_flag = msg.lianyao_tq_flag();
	yaolu_lv = msg.yaolu_lv();
	yaolu_exp = msg.yaolu_exp();
	yaoqi = msg.yaoqi();
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
	clan3_id = (uint64_t)0;
	clan5_id = (uint64_t)0;
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
	msg.set_clan3_id((uint64_t)clan3_id);
	msg.set_clan5_id((uint64_t)clan5_id);
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
	clan3_id = msg.clan3_id();
	clan5_id = msg.clan5_id();
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
	itemNum = (uint32_t)0;
	return 0;
}

int RelationGiftRecord_s::ResumeInit() {
	return 0;
}

void RelationGiftRecord_s::write_to_pbmsg(::proto_ff::RelationGiftRecord & msg) const {
	msg.set_friendid((uint64_t)friendId);
	msg.set_itemid((uint64_t)itemId);
	msg.set_isthanks((uint32_t)isThanks);
	msg.set_itemnum((uint32_t)itemNum);
}

void RelationGiftRecord_s::read_from_pbmsg(const ::proto_ff::RelationGiftRecord & msg) {
	friendId = msg.friendid();
	itemId = msg.itemid();
	isThanks = msg.isthanks();
	itemNum = msg.itemnum();
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
	for(int32_t i = 0; i < (int32_t)arena_result.size(); ++i) {
		::proto_ff::ArenaChallResult* temp_arena_result = msg.add_arena_result();
		arena_result[i].write_to_pbmsg(*temp_arena_result);
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
	arena_result.resize((int)msg.arena_result_size() > (int)arena_result.max_size() ? arena_result.max_size() : msg.arena_result_size());
	for(int32_t i = 0; i < (int32_t)arena_result.size(); ++i) {
		const ::proto_ff::ArenaChallResult & temp_arena_result = msg.arena_result(i);
		arena_result[i].read_from_pbmsg(temp_arena_result);
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
	param1 = (int64_t)0;
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
	msg.set_param1((int64_t)param1);
}

void BuffProto_s::read_from_pbmsg(const ::proto_ff::BuffProto & msg) {
	buff_index = msg.buff_index();
	buff_id = msg.buff_id();
	recver_cid = msg.recver_cid();
	left_msec = msg.left_msec();
	skill_id = msg.skill_id();
	skill_lev = msg.skill_lev();
	is_effect = msg.is_effect();
	param1 = msg.param1();
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
	for(int32_t i = 0; i < (int32_t)equip.size(); ++i) {
		::proto_ff::ItemProtoInfo* temp_equip = msg.add_equip();
		equip[i].write_to_pbmsg(*temp_equip);
	}
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
	equip.resize((int)msg.equip_size() > (int)equip.max_size() ? equip.max_size() : msg.equip_size());
	for(int32_t i = 0; i < (int32_t)equip.size(); ++i) {
		const ::proto_ff::ItemProtoInfo & temp_equip = msg.equip(i);
		equip[i].read_from_pbmsg(temp_equip);
	}
}

RechargeProto_s::RechargeProto_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int RechargeProto_s::CreateInit() {
	return 0;
}

int RechargeProto_s::ResumeInit() {
	return 0;
}

void RechargeProto_s::write_to_pbmsg(::proto_ff::RechargeProto & msg) const {
	for(int32_t i = 0; i < (int32_t)product.size(); ++i) {
		msg.add_product(product[i].data());
	}
}

void RechargeProto_s::read_from_pbmsg(const ::proto_ff::RechargeProto & msg) {
	product.resize((int)msg.product_size() > (int)product.max_size() ? product.max_size() : msg.product_size());
	for(int32_t i = 0; i < (int32_t)product.size(); ++i) {
		product[i] = msg.product(i);
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

MountKunEquipData_s::MountKunEquipData_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int MountKunEquipData_s::CreateInit() {
	return 0;
}

int MountKunEquipData_s::ResumeInit() {
	return 0;
}

void MountKunEquipData_s::write_to_pbmsg(::proto_ff::MountKunEquipData & msg) const {
	for(int32_t i = 0; i < (int32_t)infos.size(); ++i) {
		::proto_ff::EquipInfo* temp_infos = msg.add_infos();
		infos[i].write_to_pbmsg(*temp_infos);
	}
	for(int32_t i = 0; i < (int32_t)slot_status.size(); ++i) {
		msg.add_slot_status((uint32_t)slot_status[i]);
	}
}

void MountKunEquipData_s::read_from_pbmsg(const ::proto_ff::MountKunEquipData & msg) {
	infos.resize((int)msg.infos_size() > (int)infos.max_size() ? infos.max_size() : msg.infos_size());
	for(int32_t i = 0; i < (int32_t)infos.size(); ++i) {
		const ::proto_ff::EquipInfo & temp_infos = msg.infos(i);
		infos[i].read_from_pbmsg(temp_infos);
	}
	slot_status.resize((int)msg.slot_status_size() > (int)slot_status.max_size() ? slot_status.max_size() : msg.slot_status_size());
	for(int32_t i = 0; i < (int32_t)slot_status.size(); ++i) {
		slot_status[i] = msg.slot_status(i);
	}
}

MountKunEquipSuitData_s::MountKunEquipSuitData_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int MountKunEquipSuitData_s::CreateInit() {
	id = (int64_t)0;
	state = (uint32_t)0;
	return 0;
}

int MountKunEquipSuitData_s::ResumeInit() {
	return 0;
}

void MountKunEquipSuitData_s::write_to_pbmsg(::proto_ff::MountKunEquipSuitData & msg) const {
	msg.set_id((int64_t)id);
	msg.set_state((uint32_t)state);
}

void MountKunEquipSuitData_s::read_from_pbmsg(const ::proto_ff::MountKunEquipSuitData & msg) {
	id = msg.id();
	state = msg.state();
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
	kun_advance_lev = (uint32_t)0;
	fight = (uint64_t)0;
	kun_tiwu_quality = (bool)0;
	kun_tiwu_level = (uint32_t)0;
	kun_change_id = (uint32_t)0;
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
	msg.set_kun_advance_lev((uint32_t)kun_advance_lev);
	msg.set_fight((uint64_t)fight);
	::proto_ff::MountKunEquipData* temp_equip_data = msg.mutable_equip_data();
	equip_data.write_to_pbmsg(*temp_equip_data);
	for(int32_t i = 0; i < (int32_t)equip_suit_data.size(); ++i) {
		::proto_ff::MountKunEquipSuitData* temp_equip_suit_data = msg.add_equip_suit_data();
		equip_suit_data[i].write_to_pbmsg(*temp_equip_suit_data);
	}
	msg.set_kun_tiwu_quality((bool)kun_tiwu_quality);
	msg.set_kun_tiwu_level((uint32_t)kun_tiwu_level);
	msg.set_kun_change_id((uint32_t)kun_change_id);
}

void MountKunData_s::read_from_pbmsg(const ::proto_ff::MountKunData & msg) {
	kun_id = msg.kun_id();
	kun_lev = msg.kun_lev();
	kun_lev_exp = msg.kun_lev_exp();
	kun_star = msg.kun_star();
	kun_advance_lev = msg.kun_advance_lev();
	fight = msg.fight();
	const ::proto_ff::MountKunEquipData & temp_equip_data = msg.equip_data();
	equip_data.read_from_pbmsg(temp_equip_data);
	equip_suit_data.resize((int)msg.equip_suit_data_size() > (int)equip_suit_data.max_size() ? equip_suit_data.max_size() : msg.equip_suit_data_size());
	for(int32_t i = 0; i < (int32_t)equip_suit_data.size(); ++i) {
		const ::proto_ff::MountKunEquipSuitData & temp_equip_suit_data = msg.equip_suit_data(i);
		equip_suit_data[i].read_from_pbmsg(temp_equip_suit_data);
	}
	kun_tiwu_quality = msg.kun_tiwu_quality();
	kun_tiwu_level = msg.kun_tiwu_level();
	kun_change_id = msg.kun_change_id();
}

MountKunChangeData_s::MountKunChangeData_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int MountKunChangeData_s::CreateInit() {
	kun_change_id = (uint64_t)0;
	kun_change_star = (uint32_t)0;
	kun_change_quality = (bool)0;
	return 0;
}

int MountKunChangeData_s::ResumeInit() {
	return 0;
}

void MountKunChangeData_s::write_to_pbmsg(::proto_ff::MountKunChangeData & msg) const {
	msg.set_kun_change_id((uint64_t)kun_change_id);
	msg.set_kun_change_star((uint32_t)kun_change_star);
	msg.set_kun_change_quality((bool)kun_change_quality);
}

void MountKunChangeData_s::read_from_pbmsg(const ::proto_ff::MountKunChangeData & msg) {
	kun_change_id = msg.kun_change_id();
	kun_change_star = msg.kun_change_star();
	kun_change_quality = msg.kun_change_quality();
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
	::proto_ff::ComPair64* temp_select_attr = msg.mutable_select_attr();
	select_attr.write_to_pbmsg(*temp_select_attr);
}

void MountBloodData_s::read_from_pbmsg(const ::proto_ff::MountBloodData & msg) {
	blood_id = msg.blood_id();
	blood_state = msg.blood_state();
	const ::proto_ff::ComPair64 & temp_select_attr = msg.select_attr();
	select_attr.read_from_pbmsg(temp_select_attr);
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

MountFairyLandTour_s::MountFairyLandTour_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int MountFairyLandTour_s::CreateInit() {
	tour_id = (int64_t)0;
	active_state = (uint32_t)0;
	return 0;
}

int MountFairyLandTour_s::ResumeInit() {
	return 0;
}

void MountFairyLandTour_s::write_to_pbmsg(::proto_ff::MountFairyLandTour & msg) const {
	msg.set_tour_id((int64_t)tour_id);
	msg.set_active_state((uint32_t)active_state);
}

void MountFairyLandTour_s::read_from_pbmsg(const ::proto_ff::MountFairyLandTour & msg) {
	tour_id = msg.tour_id();
	active_state = msg.active_state();
}

MountFairyLand_s::MountFairyLand_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int MountFairyLand_s::CreateInit() {
	fairy_id = (int64_t)0;
	active = (bool)0;
	cur_active_tour_id = (int64_t)0;
	return 0;
}

int MountFairyLand_s::ResumeInit() {
	return 0;
}

void MountFairyLand_s::write_to_pbmsg(::proto_ff::MountFairyLand & msg) const {
	msg.set_fairy_id((int64_t)fairy_id);
	for(int32_t i = 0; i < (int32_t)tour.size(); ++i) {
		::proto_ff::MountFairyLandTour* temp_tour = msg.add_tour();
		tour[i].write_to_pbmsg(*temp_tour);
	}
	msg.set_active((bool)active);
	msg.set_cur_active_tour_id((int64_t)cur_active_tour_id);
}

void MountFairyLand_s::read_from_pbmsg(const ::proto_ff::MountFairyLand & msg) {
	fairy_id = msg.fairy_id();
	tour.resize((int)msg.tour_size() > (int)tour.max_size() ? tour.max_size() : msg.tour_size());
	for(int32_t i = 0; i < (int32_t)tour.size(); ++i) {
		const ::proto_ff::MountFairyLandTour & temp_tour = msg.tour(i);
		tour[i].read_from_pbmsg(temp_tour);
	}
	active = msg.active();
	cur_active_tour_id = msg.cur_active_tour_id();
}

MountFairySlotRecord_s::MountFairySlotRecord_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int MountFairySlotRecord_s::CreateInit() {
	cur_fairy_id = (int64_t)0;
	event_id = (int64_t)0;
	create_time = (int64_t)0;
	finish = (bool)0;
	return 0;
}

int MountFairySlotRecord_s::ResumeInit() {
	return 0;
}

void MountFairySlotRecord_s::write_to_pbmsg(::proto_ff::MountFairySlotRecord & msg) const {
	msg.set_cur_fairy_id((int64_t)cur_fairy_id);
	msg.set_event_id((int64_t)event_id);
	msg.set_create_time((int64_t)create_time);
	msg.set_finish((bool)finish);
	::proto_ff::ComItem* temp_reward_item = msg.mutable_reward_item();
	reward_item.write_to_pbmsg(*temp_reward_item);
}

void MountFairySlotRecord_s::read_from_pbmsg(const ::proto_ff::MountFairySlotRecord & msg) {
	cur_fairy_id = msg.cur_fairy_id();
	event_id = msg.event_id();
	create_time = msg.create_time();
	finish = msg.finish();
	const ::proto_ff::ComItem & temp_reward_item = msg.reward_item();
	reward_item.read_from_pbmsg(temp_reward_item);
}

MountFairySlot_s::MountFairySlot_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int MountFairySlot_s::CreateInit() {
	slot_id = (int64_t)0;
	cur_kun_id = (uint32_t)0;
	cur_dissociate_level = (uint32_t)0;
	cur_dissociate_time = (uint32_t)0;
	cur_end_time = (uint32_t)0;
	status = (uint32_t)0;
	can_get_reward = (bool)0;
	reward_gold = (uint64_t)0;
	reward_dia = (uint64_t)0;
	reward_bdia = (uint64_t)0;
	return 0;
}

int MountFairySlot_s::ResumeInit() {
	return 0;
}

void MountFairySlot_s::write_to_pbmsg(::proto_ff::MountFairySlot & msg) const {
	msg.set_slot_id((int64_t)slot_id);
	msg.set_cur_kun_id((uint32_t)cur_kun_id);
	msg.set_cur_dissociate_level((uint32_t)cur_dissociate_level);
	msg.set_cur_dissociate_time((uint32_t)cur_dissociate_time);
	msg.set_cur_end_time((uint32_t)cur_end_time);
	msg.set_status((uint32_t)status);
	msg.set_can_get_reward((bool)can_get_reward);
	for(int32_t i = 0; i < (int32_t)reward_item.size(); ++i) {
		::proto_ff::ComItem* temp_reward_item = msg.add_reward_item();
		reward_item[i].write_to_pbmsg(*temp_reward_item);
	}
	msg.set_reward_gold((uint64_t)reward_gold);
	msg.set_reward_dia((uint64_t)reward_dia);
	msg.set_reward_bdia((uint64_t)reward_bdia);
	for(int32_t i = 0; i < (int32_t)record.size(); ++i) {
		::proto_ff::MountFairySlotRecord* temp_record = msg.add_record();
		record[i].write_to_pbmsg(*temp_record);
	}
}

void MountFairySlot_s::read_from_pbmsg(const ::proto_ff::MountFairySlot & msg) {
	slot_id = msg.slot_id();
	cur_kun_id = msg.cur_kun_id();
	cur_dissociate_level = msg.cur_dissociate_level();
	cur_dissociate_time = msg.cur_dissociate_time();
	cur_end_time = msg.cur_end_time();
	status = msg.status();
	can_get_reward = msg.can_get_reward();
	reward_item.resize((int)msg.reward_item_size() > (int)reward_item.max_size() ? reward_item.max_size() : msg.reward_item_size());
	for(int32_t i = 0; i < (int32_t)reward_item.size(); ++i) {
		const ::proto_ff::ComItem & temp_reward_item = msg.reward_item(i);
		reward_item[i].read_from_pbmsg(temp_reward_item);
	}
	reward_gold = msg.reward_gold();
	reward_dia = msg.reward_dia();
	reward_bdia = msg.reward_bdia();
	record.resize((int)msg.record_size() > (int)record.max_size() ? record.max_size() : msg.record_size());
	for(int32_t i = 0; i < (int32_t)record.size(); ++i) {
		const ::proto_ff::MountFairySlotRecord & temp_record = msg.record(i);
		record[i].read_from_pbmsg(temp_record);
	}
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
	all_num = (int32_t)0;
	return 0;
}

int GodRelicsTaskEntry_s::ResumeInit() {
	return 0;
}

void GodRelicsTaskEntry_s::write_to_pbmsg(::proto_ff::GodRelicsTaskEntry & msg) const {
	msg.set_task_cfg_id((uint64_t)task_cfg_id);
	msg.set_cur_num((int32_t)cur_num);
	msg.set_task_state((int32_t)task_state);
	msg.set_all_num((int32_t)all_num);
}

void GodRelicsTaskEntry_s::read_from_pbmsg(const ::proto_ff::GodRelicsTaskEntry & msg) {
	task_cfg_id = msg.task_cfg_id();
	cur_num = msg.cur_num();
	task_state = msg.task_state();
	all_num = msg.all_num();
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
	ready_add_time = (uint64_t)0;
	is_fest_open = (bool)0;
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
	msg.set_ready_add_time((uint64_t)ready_add_time);
	msg.set_is_fest_open((bool)is_fest_open);
}

void DailyTaskLimitEntry_s::read_from_pbmsg(const ::proto_ff::DailyTaskLimitEntry & msg) {
	task_cfg_id = msg.task_cfg_id();
	cur_num = msg.cur_num();
	task_state = msg.task_state();
	last_time = msg.last_time();
	buy_num = msg.buy_num();
	ready_add = msg.ready_add();
	is_open = msg.is_open();
	ready_add_time = msg.ready_add_time();
	is_fest_open = msg.is_fest_open();
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
	missiontype = (uint32_t)0;
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
	msg.set_missiontype((uint32_t)missiontype);
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
	missiontype = msg.missiontype();
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
	vip_hide = (int32_t)0;
	active_type = (int32_t)0;
	outtime = (uint64_t)0;
	can_recv_day_gift = (int32_t)0;
	day_recv = (int32_t)0;
	zero_state = (int32_t)0;
	recv_zero = (int32_t)0;
	add_exp = (uint64_t)0;
	recv_exp = (int32_t)0;
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
	msg.set_vip_hide((int32_t)vip_hide);
	msg.set_active_type((int32_t)active_type);
	msg.set_outtime((uint64_t)outtime);
	msg.set_can_recv_day_gift((int32_t)can_recv_day_gift);
	msg.set_day_recv((int32_t)day_recv);
	for(int32_t i = 0; i < (int32_t)lv_gift.size(); ++i) {
		msg.add_lv_gift((int32_t)lv_gift[i]);
	}
	msg.set_zero_state((int32_t)zero_state);
	msg.set_recv_zero((int32_t)recv_zero);
	msg.set_add_exp((uint64_t)add_exp);
	msg.set_recv_exp((int32_t)recv_exp);
}

void NotifyVipDataRsp_s::read_from_pbmsg(const ::proto_ff::NotifyVipDataRsp & msg) {
	exp = msg.exp();
	ids.resize((int)msg.ids_size() > (int)ids.max_size() ? ids.max_size() : msg.ids_size());
	for(int32_t i = 0; i < (int32_t)ids.size(); ++i) {
		ids[i] = msg.ids(i);
	}
	vip_hide = msg.vip_hide();
	active_type = msg.active_type();
	outtime = msg.outtime();
	can_recv_day_gift = msg.can_recv_day_gift();
	day_recv = msg.day_recv();
	lv_gift.resize((int)msg.lv_gift_size() > (int)lv_gift.max_size() ? lv_gift.max_size() : msg.lv_gift_size());
	for(int32_t i = 0; i < (int32_t)lv_gift.size(); ++i) {
		lv_gift[i] = msg.lv_gift(i);
	}
	zero_state = msg.zero_state();
	recv_zero = msg.recv_zero();
	add_exp = msg.add_exp();
	recv_exp = msg.recv_exp();
}

NotifyPrivilegeOpt_s::NotifyPrivilegeOpt_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int NotifyPrivilegeOpt_s::CreateInit() {
	opt = (int32_t)0;
	return 0;
}

int NotifyPrivilegeOpt_s::ResumeInit() {
	return 0;
}

void NotifyPrivilegeOpt_s::write_to_pbmsg(::proto_ff::NotifyPrivilegeOpt & msg) const {
	msg.set_opt((int32_t)opt);
	for(int32_t i = 0; i < (int32_t)ids.size(); ++i) {
		msg.add_ids((int32_t)ids[i]);
	}
}

void NotifyPrivilegeOpt_s::read_from_pbmsg(const ::proto_ff::NotifyPrivilegeOpt & msg) {
	opt = msg.opt();
	ids.resize((int)msg.ids_size() > (int)ids.max_size() ? ids.max_size() : msg.ids_size());
	for(int32_t i = 0; i < (int32_t)ids.size(); ++i) {
		ids[i] = msg.ids(i);
	}
}

BuyVipGiftReq_s::BuyVipGiftReq_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int BuyVipGiftReq_s::CreateInit() {
	opt = (int32_t)0;
	lv = (int32_t)0;
	return 0;
}

int BuyVipGiftReq_s::ResumeInit() {
	return 0;
}

void BuyVipGiftReq_s::write_to_pbmsg(::proto_ff::BuyVipGiftReq & msg) const {
	msg.set_opt((int32_t)opt);
	msg.set_lv((int32_t)lv);
}

void BuyVipGiftReq_s::read_from_pbmsg(const ::proto_ff::BuyVipGiftReq & msg) {
	opt = msg.opt();
	lv = msg.lv();
}

BuyVipGiftRsp_s::BuyVipGiftRsp_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int BuyVipGiftRsp_s::CreateInit() {
	opt = (int32_t)0;
	lv = (int32_t)0;
	ret = (int32_t)0;
	return 0;
}

int BuyVipGiftRsp_s::ResumeInit() {
	return 0;
}

void BuyVipGiftRsp_s::write_to_pbmsg(::proto_ff::BuyVipGiftRsp & msg) const {
	msg.set_opt((int32_t)opt);
	msg.set_lv((int32_t)lv);
	msg.set_ret((int32_t)ret);
}

void BuyVipGiftRsp_s::read_from_pbmsg(const ::proto_ff::BuyVipGiftRsp & msg) {
	opt = msg.opt();
	lv = msg.lv();
	ret = msg.ret();
}

RcveVipRewardReq_s::RcveVipRewardReq_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int RcveVipRewardReq_s::CreateInit() {
	opt = (int32_t)0;
	return 0;
}

int RcveVipRewardReq_s::ResumeInit() {
	return 0;
}

void RcveVipRewardReq_s::write_to_pbmsg(::proto_ff::RcveVipRewardReq & msg) const {
	msg.set_opt((int32_t)opt);
}

void RcveVipRewardReq_s::read_from_pbmsg(const ::proto_ff::RcveVipRewardReq & msg) {
	opt = msg.opt();
}

RcveVipRewardRsp_s::RcveVipRewardRsp_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int RcveVipRewardRsp_s::CreateInit() {
	opt = (int32_t)0;
	ret = (int32_t)0;
	return 0;
}

int RcveVipRewardRsp_s::ResumeInit() {
	return 0;
}

void RcveVipRewardRsp_s::write_to_pbmsg(::proto_ff::RcveVipRewardRsp & msg) const {
	msg.set_opt((int32_t)opt);
	msg.set_ret((int32_t)ret);
}

void RcveVipRewardRsp_s::read_from_pbmsg(const ::proto_ff::RcveVipRewardRsp & msg) {
	opt = msg.opt();
	ret = msg.ret();
}

VipHideReq_s::VipHideReq_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int VipHideReq_s::CreateInit() {
	hide = (int32_t)0;
	return 0;
}

int VipHideReq_s::ResumeInit() {
	return 0;
}

void VipHideReq_s::write_to_pbmsg(::proto_ff::VipHideReq & msg) const {
	msg.set_hide((int32_t)hide);
}

void VipHideReq_s::read_from_pbmsg(const ::proto_ff::VipHideReq & msg) {
	hide = msg.hide();
}

VipHideRsp_s::VipHideRsp_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int VipHideRsp_s::CreateInit() {
	hide = (int32_t)0;
	ret = (int32_t)0;
	return 0;
}

int VipHideRsp_s::ResumeInit() {
	return 0;
}

void VipHideRsp_s::write_to_pbmsg(::proto_ff::VipHideRsp & msg) const {
	msg.set_hide((int32_t)hide);
	msg.set_ret((int32_t)ret);
}

void VipHideRsp_s::read_from_pbmsg(const ::proto_ff::VipHideRsp & msg) {
	hide = msg.hide();
	ret = msg.ret();
}

NotifyVipEvent_s::NotifyVipEvent_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int NotifyVipEvent_s::CreateInit() {
	type = (int32_t)0;
	return 0;
}

int NotifyVipEvent_s::ResumeInit() {
	return 0;
}

void NotifyVipEvent_s::write_to_pbmsg(::proto_ff::NotifyVipEvent & msg) const {
	msg.set_type((int32_t)type);
}

void NotifyVipEvent_s::read_from_pbmsg(const ::proto_ff::NotifyVipEvent & msg) {
	type = msg.type();
}

RecvVipCacheExpReq_s::RecvVipCacheExpReq_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int RecvVipCacheExpReq_s::CreateInit() {
	return 0;
}

int RecvVipCacheExpReq_s::ResumeInit() {
	return 0;
}

void RecvVipCacheExpReq_s::write_to_pbmsg(::proto_ff::RecvVipCacheExpReq & msg) const {
}

void RecvVipCacheExpReq_s::read_from_pbmsg(const ::proto_ff::RecvVipCacheExpReq & msg) {
}

RecvVipCacheExpRsp_s::RecvVipCacheExpRsp_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int RecvVipCacheExpRsp_s::CreateInit() {
	ret = (int32_t)0;
	return 0;
}

int RecvVipCacheExpRsp_s::ResumeInit() {
	return 0;
}

void RecvVipCacheExpRsp_s::write_to_pbmsg(::proto_ff::RecvVipCacheExpRsp & msg) const {
	msg.set_ret((int32_t)ret);
}

void RecvVipCacheExpRsp_s::read_from_pbmsg(const ::proto_ff::RecvVipCacheExpRsp & msg) {
	ret = msg.ret();
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
	return 0;
}

int BestEQEquipInfo_s::ResumeInit() {
	return 0;
}

void BestEQEquipInfo_s::write_to_pbmsg(::proto_ff::BestEQEquipInfo & msg) const {
}

void BestEQEquipInfo_s::read_from_pbmsg(const ::proto_ff::BestEQEquipInfo & msg) {
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
	msg.set_pourid((int32_t)pourId);
	msg.set_pourexp((int32_t)pourExp);
	msg.set_pourunlock((int32_t)pourUnLock);
	::proto_ff::BestEQBreak* temp_breakinfo = msg.mutable_breakinfo();
	breakInfo.write_to_pbmsg(*temp_breakinfo);
	msg.set_awakenlv((int32_t)awakenLv);
	::proto_ff::ItemProtoInfo* temp_dressequip = msg.mutable_dressequip();
	dressEquip.write_to_pbmsg(*temp_dressequip);
}

void BestEQSlotInfo_s::read_from_pbmsg(const ::proto_ff::BestEQSlotInfo & msg) {
	slot = msg.slot();
	pourId = msg.pourid();
	pourExp = msg.pourexp();
	pourUnLock = msg.pourunlock();
	const ::proto_ff::BestEQBreak & temp_breakinfo = msg.breakinfo();
	breakInfo.read_from_pbmsg(temp_breakinfo);
	awakenLv = msg.awakenlv();
	const ::proto_ff::ItemProtoInfo & temp_dressequip = msg.dressequip();
	dressEquip.read_from_pbmsg(temp_dressequip);
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

OneAchievementData_s::OneAchievementData_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int OneAchievementData_s::CreateInit() {
	id = (int64_t)0;
	status = (int32_t)0;
	all_num = (int32_t)0;
	cur_num = (int32_t)0;
	return 0;
}

int OneAchievementData_s::ResumeInit() {
	return 0;
}

void OneAchievementData_s::write_to_pbmsg(::proto_ff::OneAchievementData & msg) const {
	msg.set_id((int64_t)id);
	msg.set_status((int32_t)status);
	msg.set_all_num((int32_t)all_num);
	msg.set_cur_num((int32_t)cur_num);
}

void OneAchievementData_s::read_from_pbmsg(const ::proto_ff::OneAchievementData & msg) {
	id = msg.id();
	status = msg.status();
	all_num = msg.all_num();
	cur_num = msg.cur_num();
}

OneXiuZhenRoadTaskData_s::OneXiuZhenRoadTaskData_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int OneXiuZhenRoadTaskData_s::CreateInit() {
	id = (int64_t)0;
	status = (int32_t)0;
	all_num = (int32_t)0;
	cur_num = (int32_t)0;
	return 0;
}

int OneXiuZhenRoadTaskData_s::ResumeInit() {
	return 0;
}

void OneXiuZhenRoadTaskData_s::write_to_pbmsg(::proto_ff::OneXiuZhenRoadTaskData & msg) const {
	msg.set_id((int64_t)id);
	msg.set_status((int32_t)status);
	msg.set_all_num((int32_t)all_num);
	msg.set_cur_num((int32_t)cur_num);
}

void OneXiuZhenRoadTaskData_s::read_from_pbmsg(const ::proto_ff::OneXiuZhenRoadTaskData & msg) {
	id = msg.id();
	status = msg.status();
	all_num = msg.all_num();
	cur_num = msg.cur_num();
}

OneXiuZhenRoadPointsData_s::OneXiuZhenRoadPointsData_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int OneXiuZhenRoadPointsData_s::CreateInit() {
	id = (int64_t)0;
	status = (int32_t)0;
	return 0;
}

int OneXiuZhenRoadPointsData_s::ResumeInit() {
	return 0;
}

void OneXiuZhenRoadPointsData_s::write_to_pbmsg(::proto_ff::OneXiuZhenRoadPointsData & msg) const {
	msg.set_id((int64_t)id);
	msg.set_status((int32_t)status);
}

void OneXiuZhenRoadPointsData_s::read_from_pbmsg(const ::proto_ff::OneXiuZhenRoadPointsData & msg) {
	id = msg.id();
	status = msg.status();
}

OneXiuZhenRoadRechargeData_s::OneXiuZhenRoadRechargeData_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int OneXiuZhenRoadRechargeData_s::CreateInit() {
	id = (int64_t)0;
	status = (int32_t)0;
	return 0;
}

int OneXiuZhenRoadRechargeData_s::ResumeInit() {
	return 0;
}

void OneXiuZhenRoadRechargeData_s::write_to_pbmsg(::proto_ff::OneXiuZhenRoadRechargeData & msg) const {
	msg.set_id((int64_t)id);
	msg.set_status((int32_t)status);
}

void OneXiuZhenRoadRechargeData_s::read_from_pbmsg(const ::proto_ff::OneXiuZhenRoadRechargeData & msg) {
	id = msg.id();
	status = msg.status();
}

OneGoalTaskData_s::OneGoalTaskData_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int OneGoalTaskData_s::CreateInit() {
	task_id = (int64_t)0;
	group_id = (int32_t)0;
	task_status = (int32_t)0;
	all_num = (int32_t)0;
	cur_num = (int32_t)0;
	return 0;
}

int OneGoalTaskData_s::ResumeInit() {
	return 0;
}

void OneGoalTaskData_s::write_to_pbmsg(::proto_ff::OneGoalTaskData & msg) const {
	msg.set_task_id((int64_t)task_id);
	msg.set_group_id((int32_t)group_id);
	msg.set_task_status((int32_t)task_status);
	msg.set_all_num((int32_t)all_num);
	msg.set_cur_num((int32_t)cur_num);
}

void OneGoalTaskData_s::read_from_pbmsg(const ::proto_ff::OneGoalTaskData & msg) {
	task_id = msg.task_id();
	group_id = msg.group_id();
	task_status = msg.task_status();
	all_num = msg.all_num();
	cur_num = msg.cur_num();
}

OneGoalData_s::OneGoalData_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int OneGoalData_s::CreateInit() {
	group_id = (int64_t)0;
	group_status = (int32_t)0;
	return 0;
}

int OneGoalData_s::ResumeInit() {
	return 0;
}

void OneGoalData_s::write_to_pbmsg(::proto_ff::OneGoalData & msg) const {
	msg.set_group_id((int64_t)group_id);
	msg.set_group_status((int32_t)group_status);
	for(int32_t i = 0; i < (int32_t)data.size(); ++i) {
		::proto_ff::OneGoalTaskData* temp_data = msg.add_data();
		data[i].write_to_pbmsg(*temp_data);
	}
}

void OneGoalData_s::read_from_pbmsg(const ::proto_ff::OneGoalData & msg) {
	group_id = msg.group_id();
	group_status = msg.group_status();
	data.resize((int)msg.data_size() > (int)data.max_size() ? data.max_size() : msg.data_size());
	for(int32_t i = 0; i < (int32_t)data.size(); ++i) {
		const ::proto_ff::OneGoalTaskData & temp_data = msg.data(i);
		data[i].read_from_pbmsg(temp_data);
	}
}

OneBattlePassRewardData_s::OneBattlePassRewardData_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int OneBattlePassRewardData_s::CreateInit() {
	id = (int32_t)0;
	status = (int32_t)0;
	super_status = (int32_t)0;
	return 0;
}

int OneBattlePassRewardData_s::ResumeInit() {
	return 0;
}

void OneBattlePassRewardData_s::write_to_pbmsg(::proto_ff::OneBattlePassRewardData & msg) const {
	msg.set_id((int32_t)id);
	msg.set_status((int32_t)status);
	msg.set_super_status((int32_t)super_status);
}

void OneBattlePassRewardData_s::read_from_pbmsg(const ::proto_ff::OneBattlePassRewardData & msg) {
	id = msg.id();
	status = msg.status();
	super_status = msg.super_status();
}

OneBattlePassTaskData_s::OneBattlePassTaskData_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int OneBattlePassTaskData_s::CreateInit() {
	task_id = (int64_t)0;
	task_status = (int32_t)0;
	cur_num = (int32_t)0;
	all_num = (int32_t)0;
	return 0;
}

int OneBattlePassTaskData_s::ResumeInit() {
	return 0;
}

void OneBattlePassTaskData_s::write_to_pbmsg(::proto_ff::OneBattlePassTaskData & msg) const {
	msg.set_task_id((int64_t)task_id);
	msg.set_task_status((int32_t)task_status);
	msg.set_cur_num((int32_t)cur_num);
	msg.set_all_num((int32_t)all_num);
}

void OneBattlePassTaskData_s::read_from_pbmsg(const ::proto_ff::OneBattlePassTaskData & msg) {
	task_id = msg.task_id();
	task_status = msg.task_status();
	cur_num = msg.cur_num();
	all_num = msg.all_num();
}

OneBattlePassShopData_s::OneBattlePassShopData_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int OneBattlePassShopData_s::CreateInit() {
	id = (int32_t)0;
	cur_num = (int32_t)0;
	all_num = (int32_t)0;
	return 0;
}

int OneBattlePassShopData_s::ResumeInit() {
	return 0;
}

void OneBattlePassShopData_s::write_to_pbmsg(::proto_ff::OneBattlePassShopData & msg) const {
	msg.set_id((int32_t)id);
	msg.set_cur_num((int32_t)cur_num);
	msg.set_all_num((int32_t)all_num);
}

void OneBattlePassShopData_s::read_from_pbmsg(const ::proto_ff::OneBattlePassShopData & msg) {
	id = msg.id();
	cur_num = msg.cur_num();
	all_num = msg.all_num();
}

OneBattlePassData_s::OneBattlePassData_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int OneBattlePassData_s::CreateInit() {
	id = (int32_t)0;
	buy_status = (int32_t)0;
	exp = (int32_t)0;
	lv = (int32_t)0;
	return 0;
}

int OneBattlePassData_s::ResumeInit() {
	return 0;
}

void OneBattlePassData_s::write_to_pbmsg(::proto_ff::OneBattlePassData & msg) const {
	msg.set_id((int32_t)id);
	msg.set_buy_status((int32_t)buy_status);
	msg.set_exp((int32_t)exp);
	msg.set_lv((int32_t)lv);
	for(int32_t i = 0; i < (int32_t)reward.size(); ++i) {
		::proto_ff::OneBattlePassRewardData* temp_reward = msg.add_reward();
		reward[i].write_to_pbmsg(*temp_reward);
	}
	for(int32_t i = 0; i < (int32_t)task.size(); ++i) {
		::proto_ff::OneBattlePassTaskData* temp_task = msg.add_task();
		task[i].write_to_pbmsg(*temp_task);
	}
	for(int32_t i = 0; i < (int32_t)shop.size(); ++i) {
		::proto_ff::OneBattlePassShopData* temp_shop = msg.add_shop();
		shop[i].write_to_pbmsg(*temp_shop);
	}
}

void OneBattlePassData_s::read_from_pbmsg(const ::proto_ff::OneBattlePassData & msg) {
	id = msg.id();
	buy_status = msg.buy_status();
	exp = msg.exp();
	lv = msg.lv();
	reward.resize((int)msg.reward_size() > (int)reward.max_size() ? reward.max_size() : msg.reward_size());
	for(int32_t i = 0; i < (int32_t)reward.size(); ++i) {
		const ::proto_ff::OneBattlePassRewardData & temp_reward = msg.reward(i);
		reward[i].read_from_pbmsg(temp_reward);
	}
	task.resize((int)msg.task_size() > (int)task.max_size() ? task.max_size() : msg.task_size());
	for(int32_t i = 0; i < (int32_t)task.size(); ++i) {
		const ::proto_ff::OneBattlePassTaskData & temp_task = msg.task(i);
		task[i].read_from_pbmsg(temp_task);
	}
	shop.resize((int)msg.shop_size() > (int)shop.max_size() ? shop.max_size() : msg.shop_size());
	for(int32_t i = 0; i < (int32_t)shop.size(); ++i) {
		const ::proto_ff::OneBattlePassShopData & temp_shop = msg.shop(i);
		shop[i].read_from_pbmsg(temp_shop);
	}
}

BattlePassData_s::BattlePassData_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int BattlePassData_s::CreateInit() {
	flush_time = (uint64_t)0;
	return 0;
}

int BattlePassData_s::ResumeInit() {
	return 0;
}

void BattlePassData_s::write_to_pbmsg(::proto_ff::BattlePassData & msg) const {
	::proto_ff::OneBattlePassData* temp_xian_ce = msg.mutable_xian_ce();
	xian_ce.write_to_pbmsg(*temp_xian_ce);
	::proto_ff::OneBattlePassData* temp_bao_ding = msg.mutable_bao_ding();
	bao_ding.write_to_pbmsg(*temp_bao_ding);
	msg.set_flush_time((uint64_t)flush_time);
}

void BattlePassData_s::read_from_pbmsg(const ::proto_ff::BattlePassData & msg) {
	const ::proto_ff::OneBattlePassData & temp_xian_ce = msg.xian_ce();
	xian_ce.read_from_pbmsg(temp_xian_ce);
	const ::proto_ff::OneBattlePassData & temp_bao_ding = msg.bao_ding();
	bao_ding.read_from_pbmsg(temp_bao_ding);
	flush_time = msg.flush_time();
}

AchievementData_s::AchievementData_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int AchievementData_s::CreateInit() {
	ach_point = (uint64_t)0;
	xiuezhenroad_point = (uint64_t)0;
	xiuzhenroad_open_time = (uint64_t)0;
	xiuzhenroad_back_status = (uint32_t)0;
	return 0;
}

int AchievementData_s::ResumeInit() {
	return 0;
}

void AchievementData_s::write_to_pbmsg(::proto_ff::AchievementData & msg) const {
	msg.set_ach_point((uint64_t)ach_point);
	for(int32_t i = 0; i < (int32_t)ach_data.size(); ++i) {
		::proto_ff::OneAchievementData* temp_ach_data = msg.add_ach_data();
		ach_data[i].write_to_pbmsg(*temp_ach_data);
	}
	for(int32_t i = 0; i < (int32_t)ach_total_data.size(); ++i) {
		::proto_ff::OneAchievementData* temp_ach_total_data = msg.add_ach_total_data();
		ach_total_data[i].write_to_pbmsg(*temp_ach_total_data);
	}
	for(int32_t i = 0; i < (int32_t)xiuzhenroad_data.size(); ++i) {
		::proto_ff::OneXiuZhenRoadTaskData* temp_xiuzhenroad_data = msg.add_xiuzhenroad_data();
		xiuzhenroad_data[i].write_to_pbmsg(*temp_xiuzhenroad_data);
	}
	msg.set_xiuezhenroad_point((uint64_t)xiuezhenroad_point);
	for(int32_t i = 0; i < (int32_t)xiuzhenroad_points_data.size(); ++i) {
		::proto_ff::OneXiuZhenRoadPointsData* temp_xiuzhenroad_points_data = msg.add_xiuzhenroad_points_data();
		xiuzhenroad_points_data[i].write_to_pbmsg(*temp_xiuzhenroad_points_data);
	}
	for(int32_t i = 0; i < (int32_t)xiuzheroad_recharge_data.size(); ++i) {
		::proto_ff::OneXiuZhenRoadRechargeData* temp_xiuzheroad_recharge_data = msg.add_xiuzheroad_recharge_data();
		xiuzheroad_recharge_data[i].write_to_pbmsg(*temp_xiuzheroad_recharge_data);
	}
	msg.set_xiuzhenroad_open_time((uint64_t)xiuzhenroad_open_time);
	msg.set_xiuzhenroad_back_status((uint32_t)xiuzhenroad_back_status);
	for(int32_t i = 0; i < (int32_t)goal_data.size(); ++i) {
		::proto_ff::OneGoalData* temp_goal_data = msg.add_goal_data();
		goal_data[i].write_to_pbmsg(*temp_goal_data);
	}
	::proto_ff::BattlePassData* temp_battle_pass = msg.mutable_battle_pass();
	battle_pass.write_to_pbmsg(*temp_battle_pass);
}

void AchievementData_s::read_from_pbmsg(const ::proto_ff::AchievementData & msg) {
	ach_point = msg.ach_point();
	ach_data.resize((int)msg.ach_data_size() > (int)ach_data.max_size() ? ach_data.max_size() : msg.ach_data_size());
	for(int32_t i = 0; i < (int32_t)ach_data.size(); ++i) {
		const ::proto_ff::OneAchievementData & temp_ach_data = msg.ach_data(i);
		ach_data[i].read_from_pbmsg(temp_ach_data);
	}
	ach_total_data.resize((int)msg.ach_total_data_size() > (int)ach_total_data.max_size() ? ach_total_data.max_size() : msg.ach_total_data_size());
	for(int32_t i = 0; i < (int32_t)ach_total_data.size(); ++i) {
		const ::proto_ff::OneAchievementData & temp_ach_total_data = msg.ach_total_data(i);
		ach_total_data[i].read_from_pbmsg(temp_ach_total_data);
	}
	xiuzhenroad_data.resize((int)msg.xiuzhenroad_data_size() > (int)xiuzhenroad_data.max_size() ? xiuzhenroad_data.max_size() : msg.xiuzhenroad_data_size());
	for(int32_t i = 0; i < (int32_t)xiuzhenroad_data.size(); ++i) {
		const ::proto_ff::OneXiuZhenRoadTaskData & temp_xiuzhenroad_data = msg.xiuzhenroad_data(i);
		xiuzhenroad_data[i].read_from_pbmsg(temp_xiuzhenroad_data);
	}
	xiuezhenroad_point = msg.xiuezhenroad_point();
	xiuzhenroad_points_data.resize((int)msg.xiuzhenroad_points_data_size() > (int)xiuzhenroad_points_data.max_size() ? xiuzhenroad_points_data.max_size() : msg.xiuzhenroad_points_data_size());
	for(int32_t i = 0; i < (int32_t)xiuzhenroad_points_data.size(); ++i) {
		const ::proto_ff::OneXiuZhenRoadPointsData & temp_xiuzhenroad_points_data = msg.xiuzhenroad_points_data(i);
		xiuzhenroad_points_data[i].read_from_pbmsg(temp_xiuzhenroad_points_data);
	}
	xiuzheroad_recharge_data.resize((int)msg.xiuzheroad_recharge_data_size() > (int)xiuzheroad_recharge_data.max_size() ? xiuzheroad_recharge_data.max_size() : msg.xiuzheroad_recharge_data_size());
	for(int32_t i = 0; i < (int32_t)xiuzheroad_recharge_data.size(); ++i) {
		const ::proto_ff::OneXiuZhenRoadRechargeData & temp_xiuzheroad_recharge_data = msg.xiuzheroad_recharge_data(i);
		xiuzheroad_recharge_data[i].read_from_pbmsg(temp_xiuzheroad_recharge_data);
	}
	xiuzhenroad_open_time = msg.xiuzhenroad_open_time();
	xiuzhenroad_back_status = msg.xiuzhenroad_back_status();
	goal_data.resize((int)msg.goal_data_size() > (int)goal_data.max_size() ? goal_data.max_size() : msg.goal_data_size());
	for(int32_t i = 0; i < (int32_t)goal_data.size(); ++i) {
		const ::proto_ff::OneGoalData & temp_goal_data = msg.goal_data(i);
		goal_data[i].read_from_pbmsg(temp_goal_data);
	}
	const ::proto_ff::BattlePassData & temp_battle_pass = msg.battle_pass();
	battle_pass.read_from_pbmsg(temp_battle_pass);
}

PTGBEventItem_s::PTGBEventItem_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int PTGBEventItem_s::CreateInit() {
	id = (uint64_t)0;
	num = (uint64_t)0;
	return 0;
}

int PTGBEventItem_s::ResumeInit() {
	return 0;
}

void PTGBEventItem_s::write_to_pbmsg(::proto_ff::PTGBEventItem & msg) const {
	msg.set_id((uint64_t)id);
	msg.set_num((uint64_t)num);
}

void PTGBEventItem_s::read_from_pbmsg(const ::proto_ff::PTGBEventItem & msg) {
	id = msg.id();
	num = msg.num();
}

PTGBEventLog_s::PTGBEventLog_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int PTGBEventLog_s::CreateInit() {
	evtId = (uint64_t)0;
	time = (uint64_t)0;
	energyAdd = (uint64_t)0;
	return 0;
}

int PTGBEventLog_s::ResumeInit() {
	return 0;
}

void PTGBEventLog_s::write_to_pbmsg(::proto_ff::PTGBEventLog & msg) const {
	msg.set_evtid((uint64_t)evtId);
	msg.set_time((uint64_t)time);
	msg.set_energyadd((uint64_t)energyAdd);
	for(int32_t i = 0; i < (int32_t)items.size(); ++i) {
		::proto_ff::PTGBEventItem* temp_items = msg.add_items();
		items[i].write_to_pbmsg(*temp_items);
	}
}

void PTGBEventLog_s::read_from_pbmsg(const ::proto_ff::PTGBEventLog & msg) {
	evtId = msg.evtid();
	time = msg.time();
	energyAdd = msg.energyadd();
	items.resize((int)msg.items_size() > (int)items.max_size() ? items.max_size() : msg.items_size());
	for(int32_t i = 0; i < (int32_t)items.size(); ++i) {
		const ::proto_ff::PTGBEventItem & temp_items = msg.items(i);
		items[i].read_from_pbmsg(temp_items);
	}
}

PTFuncMagic_s::PTFuncMagic_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int PTFuncMagic_s::CreateInit() {
	actived = (bool)0;
	lvl = (uint32_t)0;
	stage = (uint32_t)0;
	return 0;
}

int PTFuncMagic_s::ResumeInit() {
	return 0;
}

void PTFuncMagic_s::write_to_pbmsg(::proto_ff::PTFuncMagic & msg) const {
	msg.set_actived((bool)actived);
	msg.set_lvl((uint32_t)lvl);
	msg.set_stage((uint32_t)stage);
}

void PTFuncMagic_s::read_from_pbmsg(const ::proto_ff::PTFuncMagic & msg) {
	actived = msg.actived();
	lvl = msg.lvl();
	stage = msg.stage();
}

PTlg_s::PTlg_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int PTlg_s::CreateInit() {
	lvl = (uint32_t)0;
	points = (uint32_t)0;
	return 0;
}

int PTlg_s::ResumeInit() {
	return 0;
}

void PTlg_s::write_to_pbmsg(::proto_ff::PTlg & msg) const {
	msg.set_lvl((uint32_t)lvl);
	msg.set_points((uint32_t)points);
}

void PTlg_s::read_from_pbmsg(const ::proto_ff::PTlg & msg) {
	lvl = msg.lvl();
	points = msg.points();
}

PTlgPotion_s::PTlgPotion_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int PTlgPotion_s::CreateInit() {
	id = (uint32_t)0;
	eatCount = (uint32_t)0;
	return 0;
}

int PTlgPotion_s::ResumeInit() {
	return 0;
}

void PTlgPotion_s::write_to_pbmsg(::proto_ff::PTlgPotion & msg) const {
	msg.set_id((uint32_t)id);
	msg.set_eatcount((uint32_t)eatCount);
}

void PTlgPotion_s::read_from_pbmsg(const ::proto_ff::PTlgPotion & msg) {
	id = msg.id();
	eatCount = msg.eatcount();
}

PTjm_s::PTjm_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int PTjm_s::CreateInit() {
	lvl = (uint32_t)0;
	stage = (uint32_t)0;
	return 0;
}

int PTjm_s::ResumeInit() {
	return 0;
}

void PTjm_s::write_to_pbmsg(::proto_ff::PTjm & msg) const {
	msg.set_lvl((uint32_t)lvl);
	msg.set_stage((uint32_t)stage);
}

void PTjm_s::read_from_pbmsg(const ::proto_ff::PTjm & msg) {
	lvl = msg.lvl();
	stage = msg.stage();
}

PTPurchaseRecord_s::PTPurchaseRecord_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int PTPurchaseRecord_s::CreateInit() {
	id = (uint32_t)0;
	time = (uint64_t)0;
	return 0;
}

int PTPurchaseRecord_s::ResumeInit() {
	return 0;
}

void PTPurchaseRecord_s::write_to_pbmsg(::proto_ff::PTPurchaseRecord & msg) const {
	msg.set_id((uint32_t)id);
	msg.set_time((uint64_t)time);
}

void PTPurchaseRecord_s::read_from_pbmsg(const ::proto_ff::PTPurchaseRecord & msg) {
	id = msg.id();
	time = msg.time();
}

PracticeTrueDBData_s::PracticeTrueDBData_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int PracticeTrueDBData_s::CreateInit() {
	level = (uint32_t)0;
	djRateAdd = (uint32_t)0;
	djFailInvigoration = (uint32_t)0;
	gbEnergy = (uint64_t)0;
	gbEventRate = (uint32_t)0;
	gbEnergyCritRate = (uint32_t)0;
	gbLevel = (uint32_t)0;
	gbArea = (uint32_t)0;
	gbXLRemainTime = (uint64_t)0;
	ebLevel = (uint32_t)0;
	ebLvlUpRate = (uint32_t)0;
	ebFlyRateAdd = (uint32_t)0;
	ebFlyFailInvigoration = (uint32_t)0;
	jmLvlUpRateAdd = (uint32_t)0;
	jmStageUpRateAdd = (uint32_t)0;
	jmStageUpFailInvigoration = (uint32_t)0;
	jmMergeLvl = (uint32_t)0;
	gbXLForever = (uint32_t)0;
	gbXWPAdd = (uint32_t)0;
	gbXLEventGetItemRate = (uint32_t)0;
	gbXLEventXWPAdd = (uint32_t)0;
	ebFlyFailInvigorationAdd = (uint32_t)0;
	return 0;
}

int PracticeTrueDBData_s::ResumeInit() {
	return 0;
}

void PracticeTrueDBData_s::write_to_pbmsg(::proto_ff::PracticeTrueDBData & msg) const {
	msg.set_level((uint32_t)level);
	msg.set_djrateadd((uint32_t)djRateAdd);
	msg.set_djfailinvigoration((uint32_t)djFailInvigoration);
	msg.set_gbenergy((uint64_t)gbEnergy);
	msg.set_gbeventrate((uint32_t)gbEventRate);
	msg.set_gbenergycritrate((uint32_t)gbEnergyCritRate);
	msg.set_gblevel((uint32_t)gbLevel);
	msg.set_gbarea((uint32_t)gbArea);
	for(int32_t i = 0; i < (int32_t)gbEventsLog.size(); ++i) {
		::proto_ff::PTGBEventLog* temp_gbeventslog = msg.add_gbeventslog();
		gbEventsLog[i].write_to_pbmsg(*temp_gbeventslog);
	}
	for(int32_t i = 0; i < (int32_t)gbEventItems.size(); ++i) {
		::proto_ff::PTGBEventItem* temp_gbeventitems = msg.add_gbeventitems();
		gbEventItems[i].write_to_pbmsg(*temp_gbeventitems);
	}
	msg.set_gbxlremaintime((uint64_t)gbXLRemainTime);
	msg.set_eblevel((uint32_t)ebLevel);
	msg.set_eblvluprate((uint32_t)ebLvlUpRate);
	for(int32_t i = 0; i < (int32_t)gfList.size(); ++i) {
		::proto_ff::PTFuncMagic* temp_gflist = msg.add_gflist();
		gfList[i].write_to_pbmsg(*temp_gflist);
	}
	msg.set_ebflyrateadd((uint32_t)ebFlyRateAdd);
	msg.set_ebflyfailinvigoration((uint32_t)ebFlyFailInvigoration);
	for(int32_t i = 0; i < (int32_t)lgList.size(); ++i) {
		::proto_ff::PTlg* temp_lglist = msg.add_lglist();
		lgList[i].write_to_pbmsg(*temp_lglist);
	}
	for(int32_t i = 0; i < (int32_t)lgPotions.size(); ++i) {
		::proto_ff::PTlgPotion* temp_lgpotions = msg.add_lgpotions();
		lgPotions[i].write_to_pbmsg(*temp_lgpotions);
	}
	for(int32_t i = 0; i < (int32_t)jmList.size(); ++i) {
		::proto_ff::PTjm* temp_jmlist = msg.add_jmlist();
		jmList[i].write_to_pbmsg(*temp_jmlist);
	}
	msg.set_jmlvluprateadd((uint32_t)jmLvlUpRateAdd);
	msg.set_jmstageuprateadd((uint32_t)jmStageUpRateAdd);
	msg.set_jmstageupfailinvigoration((uint32_t)jmStageUpFailInvigoration);
	msg.set_jmmergelvl((uint32_t)jmMergeLvl);
	for(int32_t i = 0; i < (int32_t)purchasedList.size(); ++i) {
		::proto_ff::PTPurchaseRecord* temp_purchasedlist = msg.add_purchasedlist();
		purchasedList[i].write_to_pbmsg(*temp_purchasedlist);
	}
	msg.set_gbxlforever((uint32_t)gbXLForever);
	msg.set_gbxwpadd((uint32_t)gbXWPAdd);
	msg.set_gbxleventgetitemrate((uint32_t)gbXLEventGetItemRate);
	msg.set_gbxleventxwpadd((uint32_t)gbXLEventXWPAdd);
	msg.set_ebflyfailinvigorationadd((uint32_t)ebFlyFailInvigorationAdd);
	for(int32_t i = 0; i < (int32_t)gfBookPurchasedList.size(); ++i) {
		::proto_ff::PTPurchaseRecord* temp_gfbookpurchasedlist = msg.add_gfbookpurchasedlist();
		gfBookPurchasedList[i].write_to_pbmsg(*temp_gfbookpurchasedlist);
	}
}

void PracticeTrueDBData_s::read_from_pbmsg(const ::proto_ff::PracticeTrueDBData & msg) {
	level = msg.level();
	djRateAdd = msg.djrateadd();
	djFailInvigoration = msg.djfailinvigoration();
	gbEnergy = msg.gbenergy();
	gbEventRate = msg.gbeventrate();
	gbEnergyCritRate = msg.gbenergycritrate();
	gbLevel = msg.gblevel();
	gbArea = msg.gbarea();
	gbEventsLog.resize((int)msg.gbeventslog_size() > (int)gbEventsLog.max_size() ? gbEventsLog.max_size() : msg.gbeventslog_size());
	for(int32_t i = 0; i < (int32_t)gbEventsLog.size(); ++i) {
		const ::proto_ff::PTGBEventLog & temp_gbeventslog = msg.gbeventslog(i);
		gbEventsLog[i].read_from_pbmsg(temp_gbeventslog);
	}
	gbEventItems.resize((int)msg.gbeventitems_size() > (int)gbEventItems.max_size() ? gbEventItems.max_size() : msg.gbeventitems_size());
	for(int32_t i = 0; i < (int32_t)gbEventItems.size(); ++i) {
		const ::proto_ff::PTGBEventItem & temp_gbeventitems = msg.gbeventitems(i);
		gbEventItems[i].read_from_pbmsg(temp_gbeventitems);
	}
	gbXLRemainTime = msg.gbxlremaintime();
	ebLevel = msg.eblevel();
	ebLvlUpRate = msg.eblvluprate();
	gfList.resize((int)msg.gflist_size() > (int)gfList.max_size() ? gfList.max_size() : msg.gflist_size());
	for(int32_t i = 0; i < (int32_t)gfList.size(); ++i) {
		const ::proto_ff::PTFuncMagic & temp_gflist = msg.gflist(i);
		gfList[i].read_from_pbmsg(temp_gflist);
	}
	ebFlyRateAdd = msg.ebflyrateadd();
	ebFlyFailInvigoration = msg.ebflyfailinvigoration();
	lgList.resize((int)msg.lglist_size() > (int)lgList.max_size() ? lgList.max_size() : msg.lglist_size());
	for(int32_t i = 0; i < (int32_t)lgList.size(); ++i) {
		const ::proto_ff::PTlg & temp_lglist = msg.lglist(i);
		lgList[i].read_from_pbmsg(temp_lglist);
	}
	lgPotions.resize((int)msg.lgpotions_size() > (int)lgPotions.max_size() ? lgPotions.max_size() : msg.lgpotions_size());
	for(int32_t i = 0; i < (int32_t)lgPotions.size(); ++i) {
		const ::proto_ff::PTlgPotion & temp_lgpotions = msg.lgpotions(i);
		lgPotions[i].read_from_pbmsg(temp_lgpotions);
	}
	jmList.resize((int)msg.jmlist_size() > (int)jmList.max_size() ? jmList.max_size() : msg.jmlist_size());
	for(int32_t i = 0; i < (int32_t)jmList.size(); ++i) {
		const ::proto_ff::PTjm & temp_jmlist = msg.jmlist(i);
		jmList[i].read_from_pbmsg(temp_jmlist);
	}
	jmLvlUpRateAdd = msg.jmlvluprateadd();
	jmStageUpRateAdd = msg.jmstageuprateadd();
	jmStageUpFailInvigoration = msg.jmstageupfailinvigoration();
	jmMergeLvl = msg.jmmergelvl();
	purchasedList.resize((int)msg.purchasedlist_size() > (int)purchasedList.max_size() ? purchasedList.max_size() : msg.purchasedlist_size());
	for(int32_t i = 0; i < (int32_t)purchasedList.size(); ++i) {
		const ::proto_ff::PTPurchaseRecord & temp_purchasedlist = msg.purchasedlist(i);
		purchasedList[i].read_from_pbmsg(temp_purchasedlist);
	}
	gbXLForever = msg.gbxlforever();
	gbXWPAdd = msg.gbxwpadd();
	gbXLEventGetItemRate = msg.gbxleventgetitemrate();
	gbXLEventXWPAdd = msg.gbxleventxwpadd();
	ebFlyFailInvigorationAdd = msg.ebflyfailinvigorationadd();
	gfBookPurchasedList.resize((int)msg.gfbookpurchasedlist_size() > (int)gfBookPurchasedList.max_size() ? gfBookPurchasedList.max_size() : msg.gfbookpurchasedlist_size());
	for(int32_t i = 0; i < (int32_t)gfBookPurchasedList.size(); ++i) {
		const ::proto_ff::PTPurchaseRecord & temp_gfbookpurchasedlist = msg.gfbookpurchasedlist(i);
		gfBookPurchasedList[i].read_from_pbmsg(temp_gfbookpurchasedlist);
	}
}

AncientSlotInfo_s::AncientSlotInfo_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int AncientSlotInfo_s::CreateInit() {
	slot = (int32_t)0;
	step = (int32_t)0;
	step_value = (int32_t)0;
	bless = (int32_t)0;
	return 0;
}

int AncientSlotInfo_s::ResumeInit() {
	return 0;
}

void AncientSlotInfo_s::write_to_pbmsg(::proto_ff::AncientSlotInfo & msg) const {
	msg.set_slot((int32_t)slot);
	msg.set_step((int32_t)step);
	msg.set_step_value((int32_t)step_value);
	msg.set_bless((int32_t)bless);
	for(int32_t i = 0; i < (int32_t)attr_index.size(); ++i) {
		msg.add_attr_index((int32_t)attr_index[i]);
	}
}

void AncientSlotInfo_s::read_from_pbmsg(const ::proto_ff::AncientSlotInfo & msg) {
	slot = msg.slot();
	step = msg.step();
	step_value = msg.step_value();
	bless = msg.bless();
	attr_index.resize((int)msg.attr_index_size() > (int)attr_index.max_size() ? attr_index.max_size() : msg.attr_index_size());
	for(int32_t i = 0; i < (int32_t)attr_index.size(); ++i) {
		attr_index[i] = msg.attr_index(i);
	}
}

AncientInfo_s::AncientInfo_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int AncientInfo_s::CreateInit() {
	id = (int32_t)0;
	lock = (int32_t)0;
	return 0;
}

int AncientInfo_s::ResumeInit() {
	return 0;
}

void AncientInfo_s::write_to_pbmsg(::proto_ff::AncientInfo & msg) const {
	msg.set_id((int32_t)id);
	for(int32_t i = 0; i < (int32_t)unlock_num.size(); ++i) {
		msg.add_unlock_num((int32_t)unlock_num[i]);
	}
	msg.set_lock((int32_t)lock);
	for(int32_t i = 0; i < (int32_t)slots.size(); ++i) {
		::proto_ff::AncientSlotInfo* temp_slots = msg.add_slots();
		slots[i].write_to_pbmsg(*temp_slots);
	}
}

void AncientInfo_s::read_from_pbmsg(const ::proto_ff::AncientInfo & msg) {
	id = msg.id();
	unlock_num.resize((int)msg.unlock_num_size() > (int)unlock_num.max_size() ? unlock_num.max_size() : msg.unlock_num_size());
	for(int32_t i = 0; i < (int32_t)unlock_num.size(); ++i) {
		unlock_num[i] = msg.unlock_num(i);
	}
	lock = msg.lock();
	slots.resize((int)msg.slots_size() > (int)slots.max_size() ? slots.max_size() : msg.slots_size());
	for(int32_t i = 0; i < (int32_t)slots.size(); ++i) {
		const ::proto_ff::AncientSlotInfo & temp_slots = msg.slots(i);
		slots[i].read_from_pbmsg(temp_slots);
	}
}

MarryChild_s::MarryChild_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int MarryChild_s::CreateInit() {
	id = (int32_t)0;
	lv = (int32_t)0;
	exp = (int32_t)0;
	star = (int32_t)0;
	return 0;
}

int MarryChild_s::ResumeInit() {
	return 0;
}

void MarryChild_s::write_to_pbmsg(::proto_ff::MarryChild & msg) const {
	msg.set_id((int32_t)id);
	msg.set_lv((int32_t)lv);
	msg.set_exp((int32_t)exp);
	msg.set_star((int32_t)star);
}

void MarryChild_s::read_from_pbmsg(const ::proto_ff::MarryChild & msg) {
	id = msg.id();
	lv = msg.lv();
	exp = msg.exp();
	star = msg.star();
}

MarrySelfInfo_s::MarrySelfInfo_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int MarrySelfInfo_s::CreateInit() {
	marry_flag = (int32_t)0;
	lock_lv = (int32_t)0;
	lock_exp = (int32_t)0;
	card_buy_time = (uint64_t)0;
	child_id = (int32_t)0;
	express_lv = (int32_t)0;
	express_exp = (int32_t)0;
	child_hatch_time = (uint64_t)0;
	buy_dup_num = (int32_t)0;
	dst_give_dup_num = (int32_t)0;
	enter_marry_dup_num = (int32_t)0;
	marry_id = (int32_t)0;
	cur_can_recv_gear = (int32_t)0;
	recv_child = (int32_t)0;
	buy_card_reward_state = (int32_t)0;
	card_reward_state = (int32_t)0;
	dst_card_reward_state = (int32_t)0;
	card_surplus_day = (int32_t)0;
	recv_self_box_days = (int32_t)0;
	task_state = (int32_t)0;
	return 0;
}

int MarrySelfInfo_s::ResumeInit() {
	return 0;
}

void MarrySelfInfo_s::write_to_pbmsg(::proto_ff::MarrySelfInfo & msg) const {
	msg.set_marry_flag((int32_t)marry_flag);
	msg.set_lock_lv((int32_t)lock_lv);
	msg.set_lock_exp((int32_t)lock_exp);
	msg.set_card_buy_time((uint64_t)card_buy_time);
	msg.set_child_id((int32_t)child_id);
	for(int32_t i = 0; i < (int32_t)childs.size(); ++i) {
		::proto_ff::MarryChild* temp_childs = msg.add_childs();
		childs[i].write_to_pbmsg(*temp_childs);
	}
	msg.set_express_lv((int32_t)express_lv);
	msg.set_express_exp((int32_t)express_exp);
	for(int32_t i = 0; i < (int32_t)gears.size(); ++i) {
		msg.add_gears((int32_t)gears[i]);
	}
	msg.set_child_hatch_time((uint64_t)child_hatch_time);
	msg.set_buy_dup_num((int32_t)buy_dup_num);
	msg.set_dst_give_dup_num((int32_t)dst_give_dup_num);
	msg.set_enter_marry_dup_num((int32_t)enter_marry_dup_num);
	msg.set_marry_id((int32_t)marry_id);
	for(int32_t i = 0; i < (int32_t)recved_gears.size(); ++i) {
		msg.add_recved_gears((int32_t)recved_gears[i]);
	}
	msg.set_cur_can_recv_gear((int32_t)cur_can_recv_gear);
	msg.set_recv_child((int32_t)recv_child);
	msg.set_buy_card_reward_state((int32_t)buy_card_reward_state);
	msg.set_card_reward_state((int32_t)card_reward_state);
	msg.set_dst_card_reward_state((int32_t)dst_card_reward_state);
	msg.set_card_surplus_day((int32_t)card_surplus_day);
	msg.set_recv_self_box_days((int32_t)recv_self_box_days);
	msg.set_task_state((int32_t)task_state);
}

void MarrySelfInfo_s::read_from_pbmsg(const ::proto_ff::MarrySelfInfo & msg) {
	marry_flag = msg.marry_flag();
	lock_lv = msg.lock_lv();
	lock_exp = msg.lock_exp();
	card_buy_time = msg.card_buy_time();
	child_id = msg.child_id();
	childs.resize((int)msg.childs_size() > (int)childs.max_size() ? childs.max_size() : msg.childs_size());
	for(int32_t i = 0; i < (int32_t)childs.size(); ++i) {
		const ::proto_ff::MarryChild & temp_childs = msg.childs(i);
		childs[i].read_from_pbmsg(temp_childs);
	}
	express_lv = msg.express_lv();
	express_exp = msg.express_exp();
	gears.resize((int)msg.gears_size() > (int)gears.max_size() ? gears.max_size() : msg.gears_size());
	for(int32_t i = 0; i < (int32_t)gears.size(); ++i) {
		gears[i] = msg.gears(i);
	}
	child_hatch_time = msg.child_hatch_time();
	buy_dup_num = msg.buy_dup_num();
	dst_give_dup_num = msg.dst_give_dup_num();
	enter_marry_dup_num = msg.enter_marry_dup_num();
	marry_id = msg.marry_id();
	recved_gears.resize((int)msg.recved_gears_size() > (int)recved_gears.max_size() ? recved_gears.max_size() : msg.recved_gears_size());
	for(int32_t i = 0; i < (int32_t)recved_gears.size(); ++i) {
		recved_gears[i] = msg.recved_gears(i);
	}
	cur_can_recv_gear = msg.cur_can_recv_gear();
	recv_child = msg.recv_child();
	buy_card_reward_state = msg.buy_card_reward_state();
	card_reward_state = msg.card_reward_state();
	dst_card_reward_state = msg.dst_card_reward_state();
	card_surplus_day = msg.card_surplus_day();
	recv_self_box_days = msg.recv_self_box_days();
	task_state = msg.task_state();
}

MarryWeddingInfo_s::MarryWeddingInfo_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int MarryWeddingInfo_s::CreateInit() {
	id = (int32_t)0;
	start_time = (uint64_t)0;
	end_time = (uint64_t)0;
	return 0;
}

int MarryWeddingInfo_s::ResumeInit() {
	return 0;
}

void MarryWeddingInfo_s::write_to_pbmsg(::proto_ff::MarryWeddingInfo & msg) const {
	msg.set_id((int32_t)id);
	msg.set_start_time((uint64_t)start_time);
	msg.set_end_time((uint64_t)end_time);
	for(int32_t i = 0; i < (int32_t)mini.size(); ++i) {
		::proto_ff::RolePlayerMiniInfo* temp_mini = msg.add_mini();
		mini[i].write_to_pbmsg(*temp_mini);
	}
	for(int32_t i = 0; i < (int32_t)invite_list.size(); ++i) {
		msg.add_invite_list((uint64_t)invite_list[i]);
	}
}

void MarryWeddingInfo_s::read_from_pbmsg(const ::proto_ff::MarryWeddingInfo & msg) {
	id = msg.id();
	start_time = msg.start_time();
	end_time = msg.end_time();
	mini.resize((int)msg.mini_size() > (int)mini.max_size() ? mini.max_size() : msg.mini_size());
	for(int32_t i = 0; i < (int32_t)mini.size(); ++i) {
		const ::proto_ff::RolePlayerMiniInfo & temp_mini = msg.mini(i);
		mini[i].read_from_pbmsg(temp_mini);
	}
	invite_list.resize((int)msg.invite_list_size() > (int)invite_list.max_size() ? invite_list.max_size() : msg.invite_list_size());
	for(int32_t i = 0; i < (int32_t)invite_list.size(); ++i) {
		invite_list[i] = msg.invite_list(i);
	}
}

ExpressLog_s::ExpressLog_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int ExpressLog_s::CreateInit() {
	src_id = (uint64_t)0;
	dst_id = (uint64_t)0;
	text_id = (int32_t)0;
	item = (uint64_t)0;
	return 0;
}

int ExpressLog_s::ResumeInit() {
	return 0;
}

void ExpressLog_s::write_to_pbmsg(::proto_ff::ExpressLog & msg) const {
	msg.set_src_name(src_name.data());
	msg.set_src_id((uint64_t)src_id);
	msg.set_dst_name(dst_name.data());
	msg.set_dst_id((uint64_t)dst_id);
	msg.set_text_id((int32_t)text_id);
	msg.set_item((uint64_t)item);
}

void ExpressLog_s::read_from_pbmsg(const ::proto_ff::ExpressLog & msg) {
	src_name = msg.src_name();
	src_id = msg.src_id();
	dst_name = msg.dst_name();
	dst_id = msg.dst_id();
	text_id = msg.text_id();
	item = msg.item();
}

WeddingDBInfo_s::WeddingDBInfo_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int WeddingDBInfo_s::CreateInit() {
	wedding_id = (int32_t)0;
	wedding_gear = (int32_t)0;
	src_cid = (uint64_t)0;
	dst_cid = (uint64_t)0;
	marry_id = (int32_t)0;
	add_num = (int32_t)0;
	return 0;
}

int WeddingDBInfo_s::ResumeInit() {
	return 0;
}

void WeddingDBInfo_s::write_to_pbmsg(::proto_ff::WeddingDBInfo & msg) const {
	msg.set_wedding_id((int32_t)wedding_id);
	msg.set_wedding_gear((int32_t)wedding_gear);
	msg.set_src_cid((uint64_t)src_cid);
	msg.set_dst_cid((uint64_t)dst_cid);
	msg.set_marry_id((int32_t)marry_id);
	for(int32_t i = 0; i < (int32_t)invite_list.size(); ++i) {
		msg.add_invite_list((int32_t)invite_list[i]);
	}
	for(int32_t i = 0; i < (int32_t)apply_list.size(); ++i) {
		msg.add_apply_list((int32_t)apply_list[i]);
	}
	msg.set_add_num((int32_t)add_num);
}

void WeddingDBInfo_s::read_from_pbmsg(const ::proto_ff::WeddingDBInfo & msg) {
	wedding_id = msg.wedding_id();
	wedding_gear = msg.wedding_gear();
	src_cid = msg.src_cid();
	dst_cid = msg.dst_cid();
	marry_id = msg.marry_id();
	invite_list.resize((int)msg.invite_list_size() > (int)invite_list.max_size() ? invite_list.max_size() : msg.invite_list_size());
	for(int32_t i = 0; i < (int32_t)invite_list.size(); ++i) {
		invite_list[i] = msg.invite_list(i);
	}
	apply_list.resize((int)msg.apply_list_size() > (int)apply_list.max_size() ? apply_list.max_size() : msg.apply_list_size());
	for(int32_t i = 0; i < (int32_t)apply_list.size(); ++i) {
		apply_list[i] = msg.apply_list(i);
	}
	add_num = msg.add_num();
}

WeddingDBList_s::WeddingDBList_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int WeddingDBList_s::CreateInit() {
	last_times = (uint64_t)0;
	return 0;
}

int WeddingDBList_s::ResumeInit() {
	return 0;
}

void WeddingDBList_s::write_to_pbmsg(::proto_ff::WeddingDBList & msg) const {
	for(int32_t i = 0; i < (int32_t)infos.size(); ++i) {
		::proto_ff::WeddingDBInfo* temp_infos = msg.add_infos();
		infos[i].write_to_pbmsg(*temp_infos);
	}
	msg.set_last_times((uint64_t)last_times);
}

void WeddingDBList_s::read_from_pbmsg(const ::proto_ff::WeddingDBList & msg) {
	infos.resize((int)msg.infos_size() > (int)infos.max_size() ? infos.max_size() : msg.infos_size());
	for(int32_t i = 0; i < (int32_t)infos.size(); ++i) {
		const ::proto_ff::WeddingDBInfo & temp_infos = msg.infos(i);
		infos[i].read_from_pbmsg(temp_infos);
	}
	last_times = msg.last_times();
}

WeddingSimpleInfo_s::WeddingSimpleInfo_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int WeddingSimpleInfo_s::CreateInit() {
	wedding_id = (int32_t)0;
	wedding_gear = (int32_t)0;
	marry_id = (int32_t)0;
	apply_end_time = (uint64_t)0;
	tour_start_time = (uint64_t)0;
	start_time = (uint64_t)0;
	end_time = (uint64_t)0;
	step = (int32_t)0;
	return 0;
}

int WeddingSimpleInfo_s::ResumeInit() {
	return 0;
}

void WeddingSimpleInfo_s::write_to_pbmsg(::proto_ff::WeddingSimpleInfo & msg) const {
	msg.set_wedding_id((int32_t)wedding_id);
	msg.set_wedding_gear((int32_t)wedding_gear);
	::proto_ff::RolePlayerMiniInfo* temp_src = msg.mutable_src();
	src.write_to_pbmsg(*temp_src);
	::proto_ff::RolePlayerMiniInfo* temp_dst = msg.mutable_dst();
	dst.write_to_pbmsg(*temp_dst);
	msg.set_marry_id((int32_t)marry_id);
	msg.set_apply_end_time((uint64_t)apply_end_time);
	msg.set_tour_start_time((uint64_t)tour_start_time);
	msg.set_start_time((uint64_t)start_time);
	msg.set_end_time((uint64_t)end_time);
	msg.set_step((int32_t)step);
}

void WeddingSimpleInfo_s::read_from_pbmsg(const ::proto_ff::WeddingSimpleInfo & msg) {
	wedding_id = msg.wedding_id();
	wedding_gear = msg.wedding_gear();
	const ::proto_ff::RolePlayerMiniInfo & temp_src = msg.src();
	src.read_from_pbmsg(temp_src);
	const ::proto_ff::RolePlayerMiniInfo & temp_dst = msg.dst();
	dst.read_from_pbmsg(temp_dst);
	marry_id = msg.marry_id();
	apply_end_time = msg.apply_end_time();
	tour_start_time = msg.tour_start_time();
	start_time = msg.start_time();
	end_time = msg.end_time();
	step = msg.step();
}

WeddingDetail_s::WeddingDetail_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int WeddingDetail_s::CreateInit() {
	wedding_id = (int32_t)0;
	wedding_gear = (int32_t)0;
	add_num = (int32_t)0;
	return 0;
}

int WeddingDetail_s::ResumeInit() {
	return 0;
}

void WeddingDetail_s::write_to_pbmsg(::proto_ff::WeddingDetail & msg) const {
	msg.set_wedding_id((int32_t)wedding_id);
	msg.set_wedding_gear((int32_t)wedding_gear);
	for(int32_t i = 0; i < (int32_t)invite_list.size(); ++i) {
		::proto_ff::RolePlayerMiniInfo* temp_invite_list = msg.add_invite_list();
		invite_list[i].write_to_pbmsg(*temp_invite_list);
	}
	for(int32_t i = 0; i < (int32_t)apply_list.size(); ++i) {
		::proto_ff::RolePlayerMiniInfo* temp_apply_list = msg.add_apply_list();
		apply_list[i].write_to_pbmsg(*temp_apply_list);
	}
	msg.set_add_num((int32_t)add_num);
}

void WeddingDetail_s::read_from_pbmsg(const ::proto_ff::WeddingDetail & msg) {
	wedding_id = msg.wedding_id();
	wedding_gear = msg.wedding_gear();
	invite_list.resize((int)msg.invite_list_size() > (int)invite_list.max_size() ? invite_list.max_size() : msg.invite_list_size());
	for(int32_t i = 0; i < (int32_t)invite_list.size(); ++i) {
		const ::proto_ff::RolePlayerMiniInfo & temp_invite_list = msg.invite_list(i);
		invite_list[i].read_from_pbmsg(temp_invite_list);
	}
	apply_list.resize((int)msg.apply_list_size() > (int)apply_list.max_size() ? apply_list.max_size() : msg.apply_list_size());
	for(int32_t i = 0; i < (int32_t)apply_list.size(); ++i) {
		const ::proto_ff::RolePlayerMiniInfo & temp_apply_list = msg.apply_list(i);
		apply_list[i].read_from_pbmsg(temp_apply_list);
	}
	add_num = msg.add_num();
}

WeddingDupRoleInfo_s::WeddingDupRoleInfo_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int WeddingDupRoleInfo_s::CreateInit() {
	sign_num = (int32_t)0;
	cake_reward_num = (int32_t)0;
	kill_monster_reward_num = (int32_t)0;
	add_exp = (uint64_t)0;
	return 0;
}

int WeddingDupRoleInfo_s::ResumeInit() {
	return 0;
}

void WeddingDupRoleInfo_s::write_to_pbmsg(::proto_ff::WeddingDupRoleInfo & msg) const {
	msg.set_sign_num((int32_t)sign_num);
	msg.set_cake_reward_num((int32_t)cake_reward_num);
	msg.set_kill_monster_reward_num((int32_t)kill_monster_reward_num);
	msg.set_add_exp((uint64_t)add_exp);
}

void WeddingDupRoleInfo_s::read_from_pbmsg(const ::proto_ff::WeddingDupRoleInfo & msg) {
	sign_num = msg.sign_num();
	cake_reward_num = msg.cake_reward_num();
	kill_monster_reward_num = msg.kill_monster_reward_num();
	add_exp = msg.add_exp();
}

GlobalExpressLog_s::GlobalExpressLog_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int GlobalExpressLog_s::CreateInit() {
	return 0;
}

int GlobalExpressLog_s::ResumeInit() {
	return 0;
}

void GlobalExpressLog_s::write_to_pbmsg(::proto_ff::GlobalExpressLog & msg) const {
	for(int32_t i = 0; i < (int32_t)logs.size(); ++i) {
		::proto_ff::ExpressLog* temp_logs = msg.add_logs();
		logs[i].write_to_pbmsg(*temp_logs);
	}
}

void GlobalExpressLog_s::read_from_pbmsg(const ::proto_ff::GlobalExpressLog & msg) {
	logs.resize((int)msg.logs_size() > (int)logs.max_size() ? logs.max_size() : msg.logs_size());
	for(int32_t i = 0; i < (int32_t)logs.size(); ++i) {
		const ::proto_ff::ExpressLog & temp_logs = msg.logs(i);
		logs[i].read_from_pbmsg(temp_logs);
	}
}

SceneProto_s::SceneProto_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int SceneProto_s::CreateInit() {
	zid = (uint32_t)0;
	sceneid = (uint64_t)0;
	mapid = (uint64_t)0;
	return 0;
}

int SceneProto_s::ResumeInit() {
	return 0;
}

void SceneProto_s::write_to_pbmsg(::proto_ff::SceneProto & msg) const {
	msg.set_zid((uint32_t)zid);
	msg.set_sceneid((uint64_t)sceneid);
	msg.set_mapid((uint64_t)mapid);
}

void SceneProto_s::read_from_pbmsg(const ::proto_ff::SceneProto & msg) {
	zid = msg.zid();
	sceneid = msg.sceneid();
	mapid = msg.mapid();
}

HandBookPBInfo_s::HandBookPBInfo_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int HandBookPBInfo_s::CreateInit() {
	id = (uint64_t)0;
	level = (uint32_t)0;
	star = (uint32_t)0;
	return 0;
}

int HandBookPBInfo_s::ResumeInit() {
	return 0;
}

void HandBookPBInfo_s::write_to_pbmsg(::proto_ff::HandBookPBInfo & msg) const {
	msg.set_id((uint64_t)id);
	msg.set_level((uint32_t)level);
	msg.set_star((uint32_t)star);
	for(int32_t i = 0; i < (int32_t)skills.size(); ++i) {
		msg.add_skills((uint64_t)skills[i]);
	}
}

void HandBookPBInfo_s::read_from_pbmsg(const ::proto_ff::HandBookPBInfo & msg) {
	id = msg.id();
	level = msg.level();
	star = msg.star();
	skills.resize((int)msg.skills_size() > (int)skills.max_size() ? skills.max_size() : msg.skills_size());
	for(int32_t i = 0; i < (int32_t)skills.size(); ++i) {
		skills[i] = msg.skills(i);
	}
}

HandBookEmployPBInfo_s::HandBookEmployPBInfo_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int HandBookEmployPBInfo_s::CreateInit() {
	id = (uint64_t)0;
	status = (uint32_t)0;
	return 0;
}

int HandBookEmployPBInfo_s::ResumeInit() {
	return 0;
}

void HandBookEmployPBInfo_s::write_to_pbmsg(::proto_ff::HandBookEmployPBInfo & msg) const {
	msg.set_id((uint64_t)id);
	msg.set_status((uint32_t)status);
}

void HandBookEmployPBInfo_s::read_from_pbmsg(const ::proto_ff::HandBookEmployPBInfo & msg) {
	id = msg.id();
	status = msg.status();
}

HandBookTablePBInfo_s::HandBookTablePBInfo_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int HandBookTablePBInfo_s::CreateInit() {
	id = (uint64_t)0;
	status = (uint32_t)0;
	return 0;
}

int HandBookTablePBInfo_s::ResumeInit() {
	return 0;
}

void HandBookTablePBInfo_s::write_to_pbmsg(::proto_ff::HandBookTablePBInfo & msg) const {
	msg.set_id((uint64_t)id);
	msg.set_status((uint32_t)status);
}

void HandBookTablePBInfo_s::read_from_pbmsg(const ::proto_ff::HandBookTablePBInfo & msg) {
	id = msg.id();
	status = msg.status();
}

HandBookBeastEquipData_s::HandBookBeastEquipData_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int HandBookBeastEquipData_s::CreateInit() {
	return 0;
}

int HandBookBeastEquipData_s::ResumeInit() {
	return 0;
}

void HandBookBeastEquipData_s::write_to_pbmsg(::proto_ff::HandBookBeastEquipData & msg) const {
	for(int32_t i = 0; i < (int32_t)infos.size(); ++i) {
		::proto_ff::EquipInfo* temp_infos = msg.add_infos();
		infos[i].write_to_pbmsg(*temp_infos);
	}
	for(int32_t i = 0; i < (int32_t)lv_attr.size(); ++i) {
		::proto_ff::EquipLvAttrInfo* temp_lv_attr = msg.add_lv_attr();
		lv_attr[i].write_to_pbmsg(*temp_lv_attr);
	}
}

void HandBookBeastEquipData_s::read_from_pbmsg(const ::proto_ff::HandBookBeastEquipData & msg) {
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

HandBookBeastPBData_s::HandBookBeastPBData_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int HandBookBeastPBData_s::CreateInit() {
	id = (uint64_t)0;
	status = (uint32_t)0;
	return 0;
}

int HandBookBeastPBData_s::ResumeInit() {
	return 0;
}

void HandBookBeastPBData_s::write_to_pbmsg(::proto_ff::HandBookBeastPBData & msg) const {
	msg.set_id((uint64_t)id);
	msg.set_status((uint32_t)status);
	::proto_ff::HandBookBeastEquipData* temp_equip_data = msg.mutable_equip_data();
	equip_data.write_to_pbmsg(*temp_equip_data);
}

void HandBookBeastPBData_s::read_from_pbmsg(const ::proto_ff::HandBookBeastPBData & msg) {
	id = msg.id();
	status = msg.status();
	const ::proto_ff::HandBookBeastEquipData & temp_equip_data = msg.equip_data();
	equip_data.read_from_pbmsg(temp_equip_data);
}

HandBookBeastBattleSlotData_s::HandBookBeastBattleSlotData_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int HandBookBeastBattleSlotData_s::CreateInit() {
	id = (uint32_t)0;
	cur_state = (uint32_t)0;
	beast_id = (int64_t)0;
	return 0;
}

int HandBookBeastBattleSlotData_s::ResumeInit() {
	return 0;
}

void HandBookBeastBattleSlotData_s::write_to_pbmsg(::proto_ff::HandBookBeastBattleSlotData & msg) const {
	msg.set_id((uint32_t)id);
	msg.set_cur_state((uint32_t)cur_state);
	msg.set_beast_id((int64_t)beast_id);
}

void HandBookBeastBattleSlotData_s::read_from_pbmsg(const ::proto_ff::HandBookBeastBattleSlotData & msg) {
	id = msg.id();
	cur_state = msg.cur_state();
	beast_id = msg.beast_id();
}

HandBookPBData_s::HandBookPBData_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int HandBookPBData_s::CreateInit() {
	beast_priv_id = (uint64_t)0;
	return 0;
}

int HandBookPBData_s::ResumeInit() {
	return 0;
}

void HandBookPBData_s::write_to_pbmsg(::proto_ff::HandBookPBData & msg) const {
	for(int32_t i = 0; i < (int32_t)data.size(); ++i) {
		::proto_ff::HandBookPBInfo* temp_data = msg.add_data();
		data[i].write_to_pbmsg(*temp_data);
	}
	for(int32_t i = 0; i < (int32_t)fetters.size(); ++i) {
		msg.add_fetters((uint64_t)fetters[i]);
	}
	for(int32_t i = 0; i < (int32_t)employs.size(); ++i) {
		::proto_ff::HandBookEmployPBInfo* temp_employs = msg.add_employs();
		employs[i].write_to_pbmsg(*temp_employs);
	}
	for(int32_t i = 0; i < (int32_t)tables.size(); ++i) {
		::proto_ff::HandBookTablePBInfo* temp_tables = msg.add_tables();
		tables[i].write_to_pbmsg(*temp_tables);
	}
	for(int32_t i = 0; i < (int32_t)beasts.size(); ++i) {
		::proto_ff::HandBookBeastPBData* temp_beasts = msg.add_beasts();
		beasts[i].write_to_pbmsg(*temp_beasts);
	}
	for(int32_t i = 0; i < (int32_t)slots.size(); ++i) {
		::proto_ff::HandBookBeastBattleSlotData* temp_slots = msg.add_slots();
		slots[i].write_to_pbmsg(*temp_slots);
	}
	msg.set_beast_priv_id((uint64_t)beast_priv_id);
}

void HandBookPBData_s::read_from_pbmsg(const ::proto_ff::HandBookPBData & msg) {
	data.resize((int)msg.data_size() > (int)data.max_size() ? data.max_size() : msg.data_size());
	for(int32_t i = 0; i < (int32_t)data.size(); ++i) {
		const ::proto_ff::HandBookPBInfo & temp_data = msg.data(i);
		data[i].read_from_pbmsg(temp_data);
	}
	fetters.resize((int)msg.fetters_size() > (int)fetters.max_size() ? fetters.max_size() : msg.fetters_size());
	for(int32_t i = 0; i < (int32_t)fetters.size(); ++i) {
		fetters[i] = msg.fetters(i);
	}
	employs.resize((int)msg.employs_size() > (int)employs.max_size() ? employs.max_size() : msg.employs_size());
	for(int32_t i = 0; i < (int32_t)employs.size(); ++i) {
		const ::proto_ff::HandBookEmployPBInfo & temp_employs = msg.employs(i);
		employs[i].read_from_pbmsg(temp_employs);
	}
	tables.resize((int)msg.tables_size() > (int)tables.max_size() ? tables.max_size() : msg.tables_size());
	for(int32_t i = 0; i < (int32_t)tables.size(); ++i) {
		const ::proto_ff::HandBookTablePBInfo & temp_tables = msg.tables(i);
		tables[i].read_from_pbmsg(temp_tables);
	}
	beasts.resize((int)msg.beasts_size() > (int)beasts.max_size() ? beasts.max_size() : msg.beasts_size());
	for(int32_t i = 0; i < (int32_t)beasts.size(); ++i) {
		const ::proto_ff::HandBookBeastPBData & temp_beasts = msg.beasts(i);
		beasts[i].read_from_pbmsg(temp_beasts);
	}
	slots.resize((int)msg.slots_size() > (int)slots.max_size() ? slots.max_size() : msg.slots_size());
	for(int32_t i = 0; i < (int32_t)slots.size(); ++i) {
		const ::proto_ff::HandBookBeastBattleSlotData & temp_slots = msg.slots(i);
		slots[i].read_from_pbmsg(temp_slots);
	}
	beast_priv_id = msg.beast_priv_id();
}

RankNodeDBData_s::RankNodeDBData_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int RankNodeDBData_s::CreateInit() {
	cid = (uint64_t)0;
	value = (uint64_t)0;
	return 0;
}

int RankNodeDBData_s::ResumeInit() {
	return 0;
}

void RankNodeDBData_s::write_to_pbmsg(::proto_ff::RankNodeDBData & msg) const {
	msg.set_cid((uint64_t)cid);
	msg.set_value((uint64_t)value);
	for(int32_t i = 0; i < (int32_t)paramInt.size(); ++i) {
		msg.add_paramint((int64_t)paramInt[i]);
	}
	for(int32_t i = 0; i < (int32_t)paramStr.size(); ++i) {
		msg.add_paramstr(paramStr[i].data());
	}
}

void RankNodeDBData_s::read_from_pbmsg(const ::proto_ff::RankNodeDBData & msg) {
	cid = msg.cid();
	value = msg.value();
	paramInt.resize((int)msg.paramint_size() > (int)paramInt.max_size() ? paramInt.max_size() : msg.paramint_size());
	for(int32_t i = 0; i < (int32_t)paramInt.size(); ++i) {
		paramInt[i] = msg.paramint(i);
	}
	paramStr.resize((int)msg.paramstr_size() > (int)paramStr.max_size() ? paramStr.max_size() : msg.paramstr_size());
	for(int32_t i = 0; i < (int32_t)paramStr.size(); ++i) {
		paramStr[i] = msg.paramstr(i);
	}
}

RankTypeDBData_s::RankTypeDBData_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int RankTypeDBData_s::CreateInit() {
	rankType = (int32_t)0;
	lastTime = (int64_t)0;
	lastKillTopCid = (int64_t)0;
	newKillTopCid = (int64_t)0;
	return 0;
}

int RankTypeDBData_s::ResumeInit() {
	return 0;
}

void RankTypeDBData_s::write_to_pbmsg(::proto_ff::RankTypeDBData & msg) const {
	msg.set_ranktype((int32_t)rankType);
	for(int32_t i = 0; i < (int32_t)nodeList.size(); ++i) {
		::proto_ff::RankNodeDBData* temp_nodelist = msg.add_nodelist();
		nodeList[i].write_to_pbmsg(*temp_nodelist);
	}
	msg.set_lasttime((int64_t)lastTime);
	msg.set_lastkilltopcid((int64_t)lastKillTopCid);
	msg.set_newkilltopcid((int64_t)newKillTopCid);
}

void RankTypeDBData_s::read_from_pbmsg(const ::proto_ff::RankTypeDBData & msg) {
	rankType = msg.ranktype();
	nodeList.resize((int)msg.nodelist_size() > (int)nodeList.max_size() ? nodeList.max_size() : msg.nodelist_size());
	for(int32_t i = 0; i < (int32_t)nodeList.size(); ++i) {
		const ::proto_ff::RankNodeDBData & temp_nodelist = msg.nodelist(i);
		nodeList[i].read_from_pbmsg(temp_nodelist);
	}
	lastTime = msg.lasttime();
	lastKillTopCid = msg.lastkilltopcid();
	newKillTopCid = msg.newkilltopcid();
}

RankNodeData_s::RankNodeData_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int RankNodeData_s::CreateInit() {
	cid = (uint64_t)0;
	vipLevel = (uint32_t)0;
	online = (bool)0;
	fight = (uint64_t)0;
	return 0;
}

int RankNodeData_s::ResumeInit() {
	return 0;
}

void RankNodeData_s::write_to_pbmsg(::proto_ff::RankNodeData & msg) const {
	msg.set_cid((uint64_t)cid);
	msg.set_viplevel((uint32_t)vipLevel);
	for(int32_t i = 0; i < (int32_t)sParam.size(); ++i) {
		msg.add_sparam(sParam[i].data());
	}
	msg.set_online((bool)online);
	msg.set_fight((uint64_t)fight);
	msg.set_name(name.data());
	::proto_ff::RoleFacadeProto* temp_facade = msg.mutable_facade();
	facade.write_to_pbmsg(*temp_facade);
}

void RankNodeData_s::read_from_pbmsg(const ::proto_ff::RankNodeData & msg) {
	cid = msg.cid();
	vipLevel = msg.viplevel();
	sParam.resize((int)msg.sparam_size() > (int)sParam.max_size() ? sParam.max_size() : msg.sparam_size());
	for(int32_t i = 0; i < (int32_t)sParam.size(); ++i) {
		sParam[i] = msg.sparam(i);
	}
	online = msg.online();
	fight = msg.fight();
	name = msg.name();
	const ::proto_ff::RoleFacadeProto & temp_facade = msg.facade();
	facade.read_from_pbmsg(temp_facade);
}

RankDataInfo_s::RankDataInfo_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int RankDataInfo_s::CreateInit() {
	rankType = (uint32_t)0;
	selfRank = (uint32_t)0;
	return 0;
}

int RankDataInfo_s::ResumeInit() {
	return 0;
}

void RankDataInfo_s::write_to_pbmsg(::proto_ff::RankDataInfo & msg) const {
	msg.set_ranktype((uint32_t)rankType);
	msg.set_selfrank((uint32_t)selfRank);
	::proto_ff::RankNodeData* temp_selfdata = msg.mutable_selfdata();
	selfData.write_to_pbmsg(*temp_selfdata);
	for(int32_t i = 0; i < (int32_t)rankList.size(); ++i) {
		::proto_ff::RankNodeData* temp_ranklist = msg.add_ranklist();
		rankList[i].write_to_pbmsg(*temp_ranklist);
	}
}

void RankDataInfo_s::read_from_pbmsg(const ::proto_ff::RankDataInfo & msg) {
	rankType = msg.ranktype();
	selfRank = msg.selfrank();
	const ::proto_ff::RankNodeData & temp_selfdata = msg.selfdata();
	selfData.read_from_pbmsg(temp_selfdata);
	rankList.resize((int)msg.ranklist_size() > (int)rankList.max_size() ? rankList.max_size() : msg.ranklist_size());
	for(int32_t i = 0; i < (int32_t)rankList.size(); ++i) {
		const ::proto_ff::RankNodeData & temp_ranklist = msg.ranklist(i);
		rankList[i].read_from_pbmsg(temp_ranklist);
	}
}

MergeReq_s::MergeReq_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int MergeReq_s::CreateInit() {
	type = (int32_t)0;
	id = (int32_t)0;
	num = (int32_t)0;
	target_pos = (int32_t)0;
	return 0;
}

int MergeReq_s::ResumeInit() {
	return 0;
}

void MergeReq_s::write_to_pbmsg(::proto_ff::MergeReq & msg) const {
	msg.set_type((int32_t)type);
	msg.set_id((int32_t)id);
	for(int32_t i = 0; i < (int32_t)index_list.size(); ++i) {
		msg.add_index_list((int32_t)index_list[i]);
	}
	msg.set_num((int32_t)num);
	msg.set_target_pos((int32_t)target_pos);
}

void MergeReq_s::read_from_pbmsg(const ::proto_ff::MergeReq & msg) {
	type = msg.type();
	id = msg.id();
	index_list.resize((int)msg.index_list_size() > (int)index_list.max_size() ? index_list.max_size() : msg.index_list_size());
	for(int32_t i = 0; i < (int32_t)index_list.size(); ++i) {
		index_list[i] = msg.index_list(i);
	}
	num = msg.num();
	target_pos = msg.target_pos();
}

MergeRsp_s::MergeRsp_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int MergeRsp_s::CreateInit() {
	ret = (int32_t)0;
	type = (int32_t)0;
	id = (int32_t)0;
	itemId = (int64_t)0;
	num = (int32_t)0;
	result = (int32_t)0;
	return 0;
}

int MergeRsp_s::ResumeInit() {
	return 0;
}

void MergeRsp_s::write_to_pbmsg(::proto_ff::MergeRsp & msg) const {
	msg.set_ret((int32_t)ret);
	msg.set_type((int32_t)type);
	msg.set_id((int32_t)id);
	msg.set_itemid((int64_t)itemId);
	msg.set_num((int32_t)num);
	msg.set_result((int32_t)result);
}

void MergeRsp_s::read_from_pbmsg(const ::proto_ff::MergeRsp & msg) {
	ret = msg.ret();
	type = msg.type();
	id = msg.id();
	itemId = msg.itemid();
	num = msg.num();
	result = msg.result();
}

PSDGoods_s::PSDGoods_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int PSDGoods_s::CreateInit() {
	id = (uint32_t)0;
	amount = (uint32_t)0;
	return 0;
}

int PSDGoods_s::ResumeInit() {
	return 0;
}

void PSDGoods_s::write_to_pbmsg(::proto_ff::PSDGoods & msg) const {
	msg.set_id((uint32_t)id);
	msg.set_amount((uint32_t)amount);
}

void PSDGoods_s::read_from_pbmsg(const ::proto_ff::PSDGoods & msg) {
	id = msg.id();
	amount = msg.amount();
}

PSDPurchaseRecord_s::PSDPurchaseRecord_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int PSDPurchaseRecord_s::CreateInit() {
	goodsId = (uint32_t)0;
	time = (uint64_t)0;
	return 0;
}

int PSDPurchaseRecord_s::ResumeInit() {
	return 0;
}

void PSDPurchaseRecord_s::write_to_pbmsg(::proto_ff::PSDPurchaseRecord & msg) const {
	msg.set_goodsid((uint32_t)goodsId);
	msg.set_time((uint64_t)time);
}

void PSDPurchaseRecord_s::read_from_pbmsg(const ::proto_ff::PSDPurchaseRecord & msg) {
	goodsId = msg.goodsid();
	time = msg.time();
}

PSDShop_s::PSDShop_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int PSDShop_s::CreateInit() {
	shopId = (uint32_t)0;
	freeRefreshCount = (uint32_t)0;
	openTime = (uint64_t)0;
	return 0;
}

int PSDShop_s::ResumeInit() {
	return 0;
}

void PSDShop_s::write_to_pbmsg(::proto_ff::PSDShop & msg) const {
	msg.set_shopid((uint32_t)shopId);
	msg.set_freerefreshcount((uint32_t)freeRefreshCount);
	msg.set_opentime((uint64_t)openTime);
	for(int32_t i = 0; i < (int32_t)saleList.size(); ++i) {
		::proto_ff::PSDGoods* temp_salelist = msg.add_salelist();
		saleList[i].write_to_pbmsg(*temp_salelist);
	}
	for(int32_t i = 0; i < (int32_t)purchasedList.size(); ++i) {
		::proto_ff::PSDPurchaseRecord* temp_purchasedlist = msg.add_purchasedlist();
		purchasedList[i].write_to_pbmsg(*temp_purchasedlist);
	}
}

void PSDShop_s::read_from_pbmsg(const ::proto_ff::PSDShop & msg) {
	shopId = msg.shopid();
	freeRefreshCount = msg.freerefreshcount();
	openTime = msg.opentime();
	saleList.resize((int)msg.salelist_size() > (int)saleList.max_size() ? saleList.max_size() : msg.salelist_size());
	for(int32_t i = 0; i < (int32_t)saleList.size(); ++i) {
		const ::proto_ff::PSDGoods & temp_salelist = msg.salelist(i);
		saleList[i].read_from_pbmsg(temp_salelist);
	}
	purchasedList.resize((int)msg.purchasedlist_size() > (int)purchasedList.max_size() ? purchasedList.max_size() : msg.purchasedlist_size());
	for(int32_t i = 0; i < (int32_t)purchasedList.size(); ++i) {
		const ::proto_ff::PSDPurchaseRecord & temp_purchasedlist = msg.purchasedlist(i);
		purchasedList[i].read_from_pbmsg(temp_purchasedlist);
	}
}

PSDatas_s::PSDatas_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int PSDatas_s::CreateInit() {
	return 0;
}

int PSDatas_s::ResumeInit() {
	return 0;
}

void PSDatas_s::write_to_pbmsg(::proto_ff::PSDatas & msg) const {
	for(int32_t i = 0; i < (int32_t)shopList.size(); ++i) {
		::proto_ff::PSDShop* temp_shoplist = msg.add_shoplist();
		shopList[i].write_to_pbmsg(*temp_shoplist);
	}
}

void PSDatas_s::read_from_pbmsg(const ::proto_ff::PSDatas & msg) {
	shopList.resize((int)msg.shoplist_size() > (int)shopList.max_size() ? shopList.max_size() : msg.shoplist_size());
	for(int32_t i = 0; i < (int32_t)shopList.size(); ++i) {
		const ::proto_ff::PSDShop & temp_shoplist = msg.shoplist(i);
		shopList[i].read_from_pbmsg(temp_shoplist);
	}
}

DragonSoulHoleData_s::DragonSoulHoleData_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int DragonSoulHoleData_s::CreateInit() {
	status = (int32_t)0;
	id = (int32_t)0;
	wake_lv = (int32_t)0;
	return 0;
}

int DragonSoulHoleData_s::ResumeInit() {
	return 0;
}

void DragonSoulHoleData_s::write_to_pbmsg(::proto_ff::DragonSoulHoleData & msg) const {
	::proto_ff::EquipInfo* temp_equip_info = msg.mutable_equip_info();
	equip_info.write_to_pbmsg(*temp_equip_info);
	msg.set_status((int32_t)status);
	msg.set_id((int32_t)id);
	msg.set_wake_lv((int32_t)wake_lv);
}

void DragonSoulHoleData_s::read_from_pbmsg(const ::proto_ff::DragonSoulHoleData & msg) {
	const ::proto_ff::EquipInfo & temp_equip_info = msg.equip_info();
	equip_info.read_from_pbmsg(temp_equip_info);
	status = msg.status();
	id = msg.id();
	wake_lv = msg.wake_lv();
}

DragonSoulStar_s::DragonSoulStar_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int DragonSoulStar_s::CreateInit() {
	id = (int32_t)0;
	status = (int32_t)0;
	return 0;
}

int DragonSoulStar_s::ResumeInit() {
	return 0;
}

void DragonSoulStar_s::write_to_pbmsg(::proto_ff::DragonSoulStar & msg) const {
	msg.set_id((int32_t)id);
	msg.set_status((int32_t)status);
}

void DragonSoulStar_s::read_from_pbmsg(const ::proto_ff::DragonSoulStar & msg) {
	id = msg.id();
	status = msg.status();
}

DragonSoulData_s::DragonSoulData_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int DragonSoulData_s::CreateInit() {
	return 0;
}

int DragonSoulData_s::ResumeInit() {
	return 0;
}

void DragonSoulData_s::write_to_pbmsg(::proto_ff::DragonSoulData & msg) const {
	for(int32_t i = 0; i < (int32_t)hole_data.size(); ++i) {
		::proto_ff::DragonSoulHoleData* temp_hole_data = msg.add_hole_data();
		hole_data[i].write_to_pbmsg(*temp_hole_data);
	}
	for(int32_t i = 0; i < (int32_t)star.size(); ++i) {
		::proto_ff::DragonSoulStar* temp_star = msg.add_star();
		star[i].write_to_pbmsg(*temp_star);
	}
}

void DragonSoulData_s::read_from_pbmsg(const ::proto_ff::DragonSoulData & msg) {
	hole_data.resize((int)msg.hole_data_size() > (int)hole_data.max_size() ? hole_data.max_size() : msg.hole_data_size());
	for(int32_t i = 0; i < (int32_t)hole_data.size(); ++i) {
		const ::proto_ff::DragonSoulHoleData & temp_hole_data = msg.hole_data(i);
		hole_data[i].read_from_pbmsg(temp_hole_data);
	}
	star.resize((int)msg.star_size() > (int)star.max_size() ? star.max_size() : msg.star_size());
	for(int32_t i = 0; i < (int32_t)star.size(); ++i) {
		const ::proto_ff::DragonSoulStar & temp_star = msg.star(i);
		star[i].read_from_pbmsg(temp_star);
	}
}

EnterQyActReq_s::EnterQyActReq_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int EnterQyActReq_s::CreateInit() {
	return 0;
}

int EnterQyActReq_s::ResumeInit() {
	return 0;
}

void EnterQyActReq_s::write_to_pbmsg(::proto_ff::EnterQyActReq & msg) const {
}

void EnterQyActReq_s::read_from_pbmsg(const ::proto_ff::EnterQyActReq & msg) {
}

EnterQyActRsp_s::EnterQyActRsp_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int EnterQyActRsp_s::CreateInit() {
	ret = (int32_t)0;
	return 0;
}

int EnterQyActRsp_s::ResumeInit() {
	return 0;
}

void EnterQyActRsp_s::write_to_pbmsg(::proto_ff::EnterQyActRsp & msg) const {
	msg.set_ret((int32_t)ret);
}

void EnterQyActRsp_s::read_from_pbmsg(const ::proto_ff::EnterQyActRsp & msg) {
	ret = msg.ret();
}

NotifyQyActDupData_s::NotifyQyActDupData_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int NotifyQyActDupData_s::CreateInit() {
	layer = (int32_t)0;
	num = (int32_t)0;
	return 0;
}

int NotifyQyActDupData_s::ResumeInit() {
	return 0;
}

void NotifyQyActDupData_s::write_to_pbmsg(::proto_ff::NotifyQyActDupData & msg) const {
	msg.set_layer((int32_t)layer);
	msg.set_num((int32_t)num);
}

void NotifyQyActDupData_s::read_from_pbmsg(const ::proto_ff::NotifyQyActDupData & msg) {
	layer = msg.layer();
	num = msg.num();
}

QyRankInfo_s::QyRankInfo_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int QyRankInfo_s::CreateInit() {
	cid = (uint64_t)0;
	layer = (int32_t)0;
	zid = (int32_t)0;
	rank = (int32_t)0;
	passtime = (int32_t)0;
	return 0;
}

int QyRankInfo_s::ResumeInit() {
	return 0;
}

void QyRankInfo_s::write_to_pbmsg(::proto_ff::QyRankInfo & msg) const {
	msg.set_cid((uint64_t)cid);
	msg.set_name(name.data());
	msg.set_layer((int32_t)layer);
	msg.set_zid((int32_t)zid);
	msg.set_rank((int32_t)rank);
	msg.set_passtime((int32_t)passtime);
}

void QyRankInfo_s::read_from_pbmsg(const ::proto_ff::QyRankInfo & msg) {
	cid = msg.cid();
	name = msg.name();
	layer = msg.layer();
	zid = msg.zid();
	rank = msg.rank();
	passtime = msg.passtime();
}

NotifyQyPassLayer_s::NotifyQyPassLayer_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int NotifyQyPassLayer_s::CreateInit() {
	layer = (int32_t)0;
	return 0;
}

int NotifyQyPassLayer_s::ResumeInit() {
	return 0;
}

void NotifyQyPassLayer_s::write_to_pbmsg(::proto_ff::NotifyQyPassLayer & msg) const {
	msg.set_layer((int32_t)layer);
}

void NotifyQyPassLayer_s::read_from_pbmsg(const ::proto_ff::NotifyQyPassLayer & msg) {
	layer = msg.layer();
}

NotifyQyActRank_s::NotifyQyActRank_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int NotifyQyActRank_s::CreateInit() {
	return 0;
}

int NotifyQyActRank_s::ResumeInit() {
	return 0;
}

void NotifyQyActRank_s::write_to_pbmsg(::proto_ff::NotifyQyActRank & msg) const {
	for(int32_t i = 0; i < (int32_t)rank.size(); ++i) {
		::proto_ff::QyRankInfo* temp_rank = msg.add_rank();
		rank[i].write_to_pbmsg(*temp_rank);
	}
}

void NotifyQyActRank_s::read_from_pbmsg(const ::proto_ff::NotifyQyActRank & msg) {
	rank.resize((int)msg.rank_size() > (int)rank.max_size() ? rank.max_size() : msg.rank_size());
	for(int32_t i = 0; i < (int32_t)rank.size(); ++i) {
		const ::proto_ff::QyRankInfo & temp_rank = msg.rank(i);
		rank[i].read_from_pbmsg(temp_rank);
	}
}

L2CEnterActReq_s::L2CEnterActReq_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int L2CEnterActReq_s::CreateInit() {
	cid = (uint64_t)0;
	zid = (int32_t)0;
	acttype = (int32_t)0;
	return 0;
}

int L2CEnterActReq_s::ResumeInit() {
	return 0;
}

void L2CEnterActReq_s::write_to_pbmsg(::proto_ff::L2CEnterActReq & msg) const {
	msg.set_cid((uint64_t)cid);
	msg.set_zid((int32_t)zid);
	msg.set_acttype((int32_t)acttype);
}

void L2CEnterActReq_s::read_from_pbmsg(const ::proto_ff::L2CEnterActReq & msg) {
	cid = msg.cid();
	zid = msg.zid();
	acttype = msg.acttype();
}

C2LEnterActReq_s::C2LEnterActReq_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int C2LEnterActReq_s::CreateInit() {
	cid = (uint64_t)0;
	zid = (int32_t)0;
	acttype = (int32_t)0;
	return 0;
}

int C2LEnterActReq_s::ResumeInit() {
	return 0;
}

void C2LEnterActReq_s::write_to_pbmsg(::proto_ff::C2LEnterActReq & msg) const {
	msg.set_cid((uint64_t)cid);
	msg.set_zid((int32_t)zid);
	msg.set_acttype((int32_t)acttype);
}

void C2LEnterActReq_s::read_from_pbmsg(const ::proto_ff::C2LEnterActReq & msg) {
	cid = msg.cid();
	zid = msg.zid();
	acttype = msg.acttype();
}

L2CEnterActRsp_s::L2CEnterActRsp_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int L2CEnterActRsp_s::CreateInit() {
	ret = (int32_t)0;
	cid = (uint64_t)0;
	zid = (int32_t)0;
	acttype = (int32_t)0;
	return 0;
}

int L2CEnterActRsp_s::ResumeInit() {
	return 0;
}

void L2CEnterActRsp_s::write_to_pbmsg(::proto_ff::L2CEnterActRsp & msg) const {
	msg.set_ret((int32_t)ret);
	msg.set_cid((uint64_t)cid);
	msg.set_zid((int32_t)zid);
	msg.set_acttype((int32_t)acttype);
}

void L2CEnterActRsp_s::read_from_pbmsg(const ::proto_ff::L2CEnterActRsp & msg) {
	ret = msg.ret();
	cid = msg.cid();
	zid = msg.zid();
	acttype = msg.acttype();
}

NotifyEnterActRsp_s::NotifyEnterActRsp_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int NotifyEnterActRsp_s::CreateInit() {
	ret = (int32_t)0;
	cid = (uint64_t)0;
	zid = (uint64_t)0;
	acttype = (int32_t)0;
	return 0;
}

int NotifyEnterActRsp_s::ResumeInit() {
	return 0;
}

void NotifyEnterActRsp_s::write_to_pbmsg(::proto_ff::NotifyEnterActRsp & msg) const {
	msg.set_ret((int32_t)ret);
	msg.set_cid((uint64_t)cid);
	msg.set_zid((uint64_t)zid);
	msg.set_acttype((int32_t)acttype);
}

void NotifyEnterActRsp_s::read_from_pbmsg(const ::proto_ff::NotifyEnterActRsp & msg) {
	ret = msg.ret();
	cid = msg.cid();
	zid = msg.zid();
	acttype = msg.acttype();
}

WelfareSignPBData_s::WelfareSignPBData_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int WelfareSignPBData_s::CreateInit() {
	id = (int32_t)0;
	status = (int32_t)0;
	return 0;
}

int WelfareSignPBData_s::ResumeInit() {
	return 0;
}

void WelfareSignPBData_s::write_to_pbmsg(::proto_ff::WelfareSignPBData & msg) const {
	msg.set_id((int32_t)id);
	msg.set_status((int32_t)status);
}

void WelfareSignPBData_s::read_from_pbmsg(const ::proto_ff::WelfareSignPBData & msg) {
	id = msg.id();
	status = msg.status();
}

WelfareAccrueRewardPBData_s::WelfareAccrueRewardPBData_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int WelfareAccrueRewardPBData_s::CreateInit() {
	id = (int32_t)0;
	status = (int32_t)0;
	return 0;
}

int WelfareAccrueRewardPBData_s::ResumeInit() {
	return 0;
}

void WelfareAccrueRewardPBData_s::write_to_pbmsg(::proto_ff::WelfareAccrueRewardPBData & msg) const {
	msg.set_id((int32_t)id);
	msg.set_status((int32_t)status);
}

void WelfareAccrueRewardPBData_s::read_from_pbmsg(const ::proto_ff::WelfareAccrueRewardPBData & msg) {
	id = msg.id();
	status = msg.status();
}

WelfareLvRewardPBData_s::WelfareLvRewardPBData_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int WelfareLvRewardPBData_s::CreateInit() {
	id = (int32_t)0;
	status = (int32_t)0;
	vip_status = (int32_t)0;
	return 0;
}

int WelfareLvRewardPBData_s::ResumeInit() {
	return 0;
}

void WelfareLvRewardPBData_s::write_to_pbmsg(::proto_ff::WelfareLvRewardPBData & msg) const {
	msg.set_id((int32_t)id);
	msg.set_status((int32_t)status);
	msg.set_vip_status((int32_t)vip_status);
}

void WelfareLvRewardPBData_s::read_from_pbmsg(const ::proto_ff::WelfareLvRewardPBData & msg) {
	id = msg.id();
	status = msg.status();
	vip_status = msg.vip_status();
}

WelfareOnlineRewardPBData_s::WelfareOnlineRewardPBData_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int WelfareOnlineRewardPBData_s::CreateInit() {
	id = (int32_t)0;
	status = (int32_t)0;
	return 0;
}

int WelfareOnlineRewardPBData_s::ResumeInit() {
	return 0;
}

void WelfareOnlineRewardPBData_s::write_to_pbmsg(::proto_ff::WelfareOnlineRewardPBData & msg) const {
	msg.set_id((int32_t)id);
	msg.set_status((int32_t)status);
}

void WelfareOnlineRewardPBData_s::read_from_pbmsg(const ::proto_ff::WelfareOnlineRewardPBData & msg) {
	id = msg.id();
	status = msg.status();
}

WelfareFraudRewardPBData_s::WelfareFraudRewardPBData_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int WelfareFraudRewardPBData_s::CreateInit() {
	status = (int32_t)0;
	return 0;
}

int WelfareFraudRewardPBData_s::ResumeInit() {
	return 0;
}

void WelfareFraudRewardPBData_s::write_to_pbmsg(::proto_ff::WelfareFraudRewardPBData & msg) const {
	msg.set_status((int32_t)status);
	for(int32_t i = 0; i < (int32_t)id.size(); ++i) {
		msg.add_id((int32_t)id[i]);
	}
}

void WelfareFraudRewardPBData_s::read_from_pbmsg(const ::proto_ff::WelfareFraudRewardPBData & msg) {
	status = msg.status();
	id.resize((int)msg.id_size() > (int)id.max_size() ? id.max_size() : msg.id_size());
	for(int32_t i = 0; i < (int32_t)id.size(); ++i) {
		id[i] = msg.id(i);
	}
}

WelfareNotifyRewardPBData_s::WelfareNotifyRewardPBData_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int WelfareNotifyRewardPBData_s::CreateInit() {
	status = (int32_t)0;
	version_id = (int32_t)0;
	return 0;
}

int WelfareNotifyRewardPBData_s::ResumeInit() {
	return 0;
}

void WelfareNotifyRewardPBData_s::write_to_pbmsg(::proto_ff::WelfareNotifyRewardPBData & msg) const {
	msg.set_status((int32_t)status);
	msg.set_version_id((int32_t)version_id);
}

void WelfareNotifyRewardPBData_s::read_from_pbmsg(const ::proto_ff::WelfareNotifyRewardPBData & msg) {
	status = msg.status();
	version_id = msg.version_id();
}

WelfareWeekEndRewardPBData_s::WelfareWeekEndRewardPBData_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int WelfareWeekEndRewardPBData_s::CreateInit() {
	id = (int32_t)0;
	status = (int32_t)0;
	return 0;
}

int WelfareWeekEndRewardPBData_s::ResumeInit() {
	return 0;
}

void WelfareWeekEndRewardPBData_s::write_to_pbmsg(::proto_ff::WelfareWeekEndRewardPBData & msg) const {
	msg.set_id((int32_t)id);
	msg.set_status((int32_t)status);
}

void WelfareWeekEndRewardPBData_s::read_from_pbmsg(const ::proto_ff::WelfareWeekEndRewardPBData & msg) {
	id = msg.id();
	status = msg.status();
}

WelfareQiFuData_s::WelfareQiFuData_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int WelfareQiFuData_s::CreateInit() {
	last_free_qifu_time = (int64_t)0;
	free_qifu_status = (int32_t)0;
	max_gold_qifu_buy_num = (int32_t)0;
	left_gold_qifu_buy_num = (int32_t)0;
	max_exp_qifu_buy_num = (int32_t)0;
	left_exp_qifu_buy_num = (int32_t)0;
	save_money = (int32_t)0;
	last_save_money_time = (int32_t)0;
	last_get_money_time = (int32_t)0;
	get_money_day = (int32_t)0;
	all_get_money = (int32_t)0;
	return 0;
}

int WelfareQiFuData_s::ResumeInit() {
	return 0;
}

void WelfareQiFuData_s::write_to_pbmsg(::proto_ff::WelfareQiFuData & msg) const {
	msg.set_last_free_qifu_time((int64_t)last_free_qifu_time);
	msg.set_free_qifu_status((int32_t)free_qifu_status);
	msg.set_max_gold_qifu_buy_num((int32_t)max_gold_qifu_buy_num);
	msg.set_left_gold_qifu_buy_num((int32_t)left_gold_qifu_buy_num);
	msg.set_max_exp_qifu_buy_num((int32_t)max_exp_qifu_buy_num);
	msg.set_left_exp_qifu_buy_num((int32_t)left_exp_qifu_buy_num);
	msg.set_save_money((int32_t)save_money);
	msg.set_last_save_money_time((int32_t)last_save_money_time);
	msg.set_last_get_money_time((int32_t)last_get_money_time);
	msg.set_get_money_day((int32_t)get_money_day);
	msg.set_all_get_money((int32_t)all_get_money);
}

void WelfareQiFuData_s::read_from_pbmsg(const ::proto_ff::WelfareQiFuData & msg) {
	last_free_qifu_time = msg.last_free_qifu_time();
	free_qifu_status = msg.free_qifu_status();
	max_gold_qifu_buy_num = msg.max_gold_qifu_buy_num();
	left_gold_qifu_buy_num = msg.left_gold_qifu_buy_num();
	max_exp_qifu_buy_num = msg.max_exp_qifu_buy_num();
	left_exp_qifu_buy_num = msg.left_exp_qifu_buy_num();
	save_money = msg.save_money();
	last_save_money_time = msg.last_save_money_time();
	last_get_money_time = msg.last_get_money_time();
	get_money_day = msg.get_money_day();
	all_get_money = msg.all_get_money();
}

WelfareLogonData_s::WelfareLogonData_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int WelfareLogonData_s::CreateInit() {
	id = (int32_t)0;
	status = (int32_t)0;
	return 0;
}

int WelfareLogonData_s::ResumeInit() {
	return 0;
}

void WelfareLogonData_s::write_to_pbmsg(::proto_ff::WelfareLogonData & msg) const {
	msg.set_id((int32_t)id);
	msg.set_status((int32_t)status);
}

void WelfareLogonData_s::read_from_pbmsg(const ::proto_ff::WelfareLogonData & msg) {
	id = msg.id();
	status = msg.status();
}

WelfarePBData_s::WelfarePBData_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int WelfarePBData_s::CreateInit() {
	create_time = (int64_t)0;
	flush_time = (int64_t)0;
	online_time = (int64_t)0;
	last_week_end_flush_time = (int64_t)0;
	cur_logon_day = (int32_t)0;
	return 0;
}

int WelfarePBData_s::ResumeInit() {
	return 0;
}

void WelfarePBData_s::write_to_pbmsg(::proto_ff::WelfarePBData & msg) const {
	msg.set_create_time((int64_t)create_time);
	msg.set_flush_time((int64_t)flush_time);
	msg.set_online_time((int64_t)online_time);
	for(int32_t i = 0; i < (int32_t)sign.size(); ++i) {
		::proto_ff::WelfareSignPBData* temp_sign = msg.add_sign();
		sign[i].write_to_pbmsg(*temp_sign);
	}
	for(int32_t i = 0; i < (int32_t)accure.size(); ++i) {
		::proto_ff::WelfareAccrueRewardPBData* temp_accure = msg.add_accure();
		accure[i].write_to_pbmsg(*temp_accure);
	}
	for(int32_t i = 0; i < (int32_t)lv.size(); ++i) {
		::proto_ff::WelfareLvRewardPBData* temp_lv = msg.add_lv();
		lv[i].write_to_pbmsg(*temp_lv);
	}
	for(int32_t i = 0; i < (int32_t)online.size(); ++i) {
		::proto_ff::WelfareOnlineRewardPBData* temp_online = msg.add_online();
		online[i].write_to_pbmsg(*temp_online);
	}
	::proto_ff::WelfareNotifyRewardPBData* temp_notify = msg.mutable_notify();
	notify.write_to_pbmsg(*temp_notify);
	::proto_ff::WelfareFraudRewardPBData* temp_fraud = msg.mutable_fraud();
	fraud.write_to_pbmsg(*temp_fraud);
	for(int32_t i = 0; i < (int32_t)weekend.size(); ++i) {
		::proto_ff::WelfareWeekEndRewardPBData* temp_weekend = msg.add_weekend();
		weekend[i].write_to_pbmsg(*temp_weekend);
	}
	msg.set_last_week_end_flush_time((int64_t)last_week_end_flush_time);
	::proto_ff::WelfareQiFuData* temp_pray = msg.mutable_pray();
	pray.write_to_pbmsg(*temp_pray);
	for(int32_t i = 0; i < (int32_t)logon.size(); ++i) {
		::proto_ff::WelfareLogonData* temp_logon = msg.add_logon();
		logon[i].write_to_pbmsg(*temp_logon);
	}
	msg.set_cur_logon_day((int32_t)cur_logon_day);
}

void WelfarePBData_s::read_from_pbmsg(const ::proto_ff::WelfarePBData & msg) {
	create_time = msg.create_time();
	flush_time = msg.flush_time();
	online_time = msg.online_time();
	sign.resize((int)msg.sign_size() > (int)sign.max_size() ? sign.max_size() : msg.sign_size());
	for(int32_t i = 0; i < (int32_t)sign.size(); ++i) {
		const ::proto_ff::WelfareSignPBData & temp_sign = msg.sign(i);
		sign[i].read_from_pbmsg(temp_sign);
	}
	accure.resize((int)msg.accure_size() > (int)accure.max_size() ? accure.max_size() : msg.accure_size());
	for(int32_t i = 0; i < (int32_t)accure.size(); ++i) {
		const ::proto_ff::WelfareAccrueRewardPBData & temp_accure = msg.accure(i);
		accure[i].read_from_pbmsg(temp_accure);
	}
	lv.resize((int)msg.lv_size() > (int)lv.max_size() ? lv.max_size() : msg.lv_size());
	for(int32_t i = 0; i < (int32_t)lv.size(); ++i) {
		const ::proto_ff::WelfareLvRewardPBData & temp_lv = msg.lv(i);
		lv[i].read_from_pbmsg(temp_lv);
	}
	online.resize((int)msg.online_size() > (int)online.max_size() ? online.max_size() : msg.online_size());
	for(int32_t i = 0; i < (int32_t)online.size(); ++i) {
		const ::proto_ff::WelfareOnlineRewardPBData & temp_online = msg.online(i);
		online[i].read_from_pbmsg(temp_online);
	}
	const ::proto_ff::WelfareNotifyRewardPBData & temp_notify = msg.notify();
	notify.read_from_pbmsg(temp_notify);
	const ::proto_ff::WelfareFraudRewardPBData & temp_fraud = msg.fraud();
	fraud.read_from_pbmsg(temp_fraud);
	weekend.resize((int)msg.weekend_size() > (int)weekend.max_size() ? weekend.max_size() : msg.weekend_size());
	for(int32_t i = 0; i < (int32_t)weekend.size(); ++i) {
		const ::proto_ff::WelfareWeekEndRewardPBData & temp_weekend = msg.weekend(i);
		weekend[i].read_from_pbmsg(temp_weekend);
	}
	last_week_end_flush_time = msg.last_week_end_flush_time();
	const ::proto_ff::WelfareQiFuData & temp_pray = msg.pray();
	pray.read_from_pbmsg(temp_pray);
	logon.resize((int)msg.logon_size() > (int)logon.max_size() ? logon.max_size() : msg.logon_size());
	for(int32_t i = 0; i < (int32_t)logon.size(); ++i) {
		const ::proto_ff::WelfareLogonData & temp_logon = msg.logon(i);
		logon[i].read_from_pbmsg(temp_logon);
	}
	cur_logon_day = msg.cur_logon_day();
}

WPPState_s::WPPState_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int WPPState_s::CreateInit() {
	type = (uint32_t)0;
	return 0;
}

int WPPState_s::ResumeInit() {
	return 0;
}

void WPPState_s::write_to_pbmsg(::proto_ff::WPPState & msg) const {
	msg.set_type((uint32_t)type);
	::proto_ff::Vector3PB* temp_dir = msg.mutable_dir();
	dir.write_to_pbmsg(*temp_dir);
}

void WPPState_s::read_from_pbmsg(const ::proto_ff::WPPState & msg) {
	type = msg.type();
	const ::proto_ff::Vector3PB & temp_dir = msg.dir();
	dir.read_from_pbmsg(temp_dir);
}

XingYunMiShiPBData_s::XingYunMiShiPBData_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int XingYunMiShiPBData_s::CreateInit() {
	id = (int32_t)0;
	status = (int32_t)0;
	return 0;
}

int XingYunMiShiPBData_s::ResumeInit() {
	return 0;
}

void XingYunMiShiPBData_s::write_to_pbmsg(::proto_ff::XingYunMiShiPBData & msg) const {
	msg.set_id((int32_t)id);
	msg.set_status((int32_t)status);
}

void XingYunMiShiPBData_s::read_from_pbmsg(const ::proto_ff::XingYunMiShiPBData & msg) {
	id = msg.id();
	status = msg.status();
}

XingYunMiShiPBRecord_s::XingYunMiShiPBRecord_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int XingYunMiShiPBRecord_s::CreateInit() {
	cid = (uint64_t)0;
	id = (int32_t)0;
	time = (int64_t)0;
	return 0;
}

int XingYunMiShiPBRecord_s::ResumeInit() {
	return 0;
}

void XingYunMiShiPBRecord_s::write_to_pbmsg(::proto_ff::XingYunMiShiPBRecord & msg) const {
	msg.set_cid((uint64_t)cid);
	msg.set_name(name.data());
	msg.set_id((int32_t)id);
	msg.set_time((int64_t)time);
}

void XingYunMiShiPBRecord_s::read_from_pbmsg(const ::proto_ff::XingYunMiShiPBRecord & msg) {
	cid = msg.cid();
	name = msg.name();
	id = msg.id();
	time = msg.time();
}

DailyGiftPBData_s::DailyGiftPBData_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int DailyGiftPBData_s::CreateInit() {
	id = (int32_t)0;
	status = (int32_t)0;
	return 0;
}

int DailyGiftPBData_s::ResumeInit() {
	return 0;
}

void DailyGiftPBData_s::write_to_pbmsg(::proto_ff::DailyGiftPBData & msg) const {
	msg.set_id((int32_t)id);
	msg.set_status((int32_t)status);
}

void DailyGiftPBData_s::read_from_pbmsg(const ::proto_ff::DailyGiftPBData & msg) {
	id = msg.id();
	status = msg.status();
}

DailyGiftPBDataRecord_s::DailyGiftPBDataRecord_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int DailyGiftPBDataRecord_s::CreateInit() {
	cid = (uint64_t)0;
	id = (int32_t)0;
	time = (int64_t)0;
	return 0;
}

int DailyGiftPBDataRecord_s::ResumeInit() {
	return 0;
}

void DailyGiftPBDataRecord_s::write_to_pbmsg(::proto_ff::DailyGiftPBDataRecord & msg) const {
	msg.set_cid((uint64_t)cid);
	msg.set_name(name.data());
	msg.set_id((int32_t)id);
	msg.set_time((int64_t)time);
}

void DailyGiftPBDataRecord_s::read_from_pbmsg(const ::proto_ff::DailyGiftPBDataRecord & msg) {
	cid = msg.cid();
	name = msg.name();
	id = msg.id();
	time = msg.time();
}

LianChongTodayPBData_s::LianChongTodayPBData_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int LianChongTodayPBData_s::CreateInit() {
	id = (int32_t)0;
	status = (int32_t)0;
	return 0;
}

int LianChongTodayPBData_s::ResumeInit() {
	return 0;
}

void LianChongTodayPBData_s::write_to_pbmsg(::proto_ff::LianChongTodayPBData & msg) const {
	msg.set_id((int32_t)id);
	msg.set_status((int32_t)status);
}

void LianChongTodayPBData_s::read_from_pbmsg(const ::proto_ff::LianChongTodayPBData & msg) {
	id = msg.id();
	status = msg.status();
}

LianChongTodayPBDataRecord_s::LianChongTodayPBDataRecord_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int LianChongTodayPBDataRecord_s::CreateInit() {
	cid = (uint64_t)0;
	id = (int32_t)0;
	time = (int64_t)0;
	return 0;
}

int LianChongTodayPBDataRecord_s::ResumeInit() {
	return 0;
}

void LianChongTodayPBDataRecord_s::write_to_pbmsg(::proto_ff::LianChongTodayPBDataRecord & msg) const {
	msg.set_cid((uint64_t)cid);
	msg.set_name(name.data());
	msg.set_id((int32_t)id);
	msg.set_time((int64_t)time);
}

void LianChongTodayPBDataRecord_s::read_from_pbmsg(const ::proto_ff::LianChongTodayPBDataRecord & msg) {
	cid = msg.cid();
	name = msg.name();
	id = msg.id();
	time = msg.time();
}

LianChongAccPBData_s::LianChongAccPBData_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int LianChongAccPBData_s::CreateInit() {
	id = (int32_t)0;
	status = (int32_t)0;
	days = (int32_t)0;
	cur_flag = (bool)0;
	return 0;
}

int LianChongAccPBData_s::ResumeInit() {
	return 0;
}

void LianChongAccPBData_s::write_to_pbmsg(::proto_ff::LianChongAccPBData & msg) const {
	msg.set_id((int32_t)id);
	msg.set_status((int32_t)status);
	msg.set_days((int32_t)days);
	msg.set_cur_flag((bool)cur_flag);
}

void LianChongAccPBData_s::read_from_pbmsg(const ::proto_ff::LianChongAccPBData & msg) {
	id = msg.id();
	status = msg.status();
	days = msg.days();
	cur_flag = msg.cur_flag();
}

LianChongAccPBDataRecord_s::LianChongAccPBDataRecord_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int LianChongAccPBDataRecord_s::CreateInit() {
	cid = (uint64_t)0;
	id = (int32_t)0;
	time = (int64_t)0;
	return 0;
}

int LianChongAccPBDataRecord_s::ResumeInit() {
	return 0;
}

void LianChongAccPBDataRecord_s::write_to_pbmsg(::proto_ff::LianChongAccPBDataRecord & msg) const {
	msg.set_cid((uint64_t)cid);
	msg.set_name(name.data());
	msg.set_id((int32_t)id);
	msg.set_time((int64_t)time);
}

void LianChongAccPBDataRecord_s::read_from_pbmsg(const ::proto_ff::LianChongAccPBDataRecord & msg) {
	cid = msg.cid();
	name = msg.name();
	id = msg.id();
	time = msg.time();
}

MonthCardPBData_s::MonthCardPBData_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int MonthCardPBData_s::CreateInit() {
	id = (int32_t)0;
	status = (int32_t)0;
	buy_time = (uint64_t)0;
	last_get_reward = (uint64_t)0;
	last_buy_time = (uint64_t)0;
	return 0;
}

int MonthCardPBData_s::ResumeInit() {
	return 0;
}

void MonthCardPBData_s::write_to_pbmsg(::proto_ff::MonthCardPBData & msg) const {
	msg.set_id((int32_t)id);
	msg.set_status((int32_t)status);
	msg.set_buy_time((uint64_t)buy_time);
	msg.set_last_get_reward((uint64_t)last_get_reward);
	msg.set_last_buy_time((uint64_t)last_buy_time);
}

void MonthCardPBData_s::read_from_pbmsg(const ::proto_ff::MonthCardPBData & msg) {
	id = msg.id();
	status = msg.status();
	buy_time = msg.buy_time();
	last_get_reward = msg.last_get_reward();
	last_buy_time = msg.last_buy_time();
}

MonthCardPBDataRecord_s::MonthCardPBDataRecord_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int MonthCardPBDataRecord_s::CreateInit() {
	cid = (uint64_t)0;
	id = (int32_t)0;
	time = (int64_t)0;
	return 0;
}

int MonthCardPBDataRecord_s::ResumeInit() {
	return 0;
}

void MonthCardPBDataRecord_s::write_to_pbmsg(::proto_ff::MonthCardPBDataRecord & msg) const {
	msg.set_cid((uint64_t)cid);
	msg.set_name(name.data());
	msg.set_id((int32_t)id);
	msg.set_time((int64_t)time);
}

void MonthCardPBDataRecord_s::read_from_pbmsg(const ::proto_ff::MonthCardPBDataRecord & msg) {
	cid = msg.cid();
	name = msg.name();
	id = msg.id();
	time = msg.time();
}

TurntableAccPBData_s::TurntableAccPBData_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int TurntableAccPBData_s::CreateInit() {
	id = (int32_t)0;
	status = (int32_t)0;
	cur_num = (int32_t)0;
	return 0;
}

int TurntableAccPBData_s::ResumeInit() {
	return 0;
}

void TurntableAccPBData_s::write_to_pbmsg(::proto_ff::TurntableAccPBData & msg) const {
	msg.set_id((int32_t)id);
	msg.set_status((int32_t)status);
	msg.set_cur_num((int32_t)cur_num);
}

void TurntableAccPBData_s::read_from_pbmsg(const ::proto_ff::TurntableAccPBData & msg) {
	id = msg.id();
	status = msg.status();
	cur_num = msg.cur_num();
}

TurntablePBData_s::TurntablePBData_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int TurntablePBData_s::CreateInit() {
	id = (int32_t)0;
	cur_num = (int32_t)0;
	acc_num = (int32_t)0;
	return 0;
}

int TurntablePBData_s::ResumeInit() {
	return 0;
}

void TurntablePBData_s::write_to_pbmsg(::proto_ff::TurntablePBData & msg) const {
	msg.set_id((int32_t)id);
	msg.set_cur_num((int32_t)cur_num);
	msg.set_acc_num((int32_t)acc_num);
}

void TurntablePBData_s::read_from_pbmsg(const ::proto_ff::TurntablePBData & msg) {
	id = msg.id();
	cur_num = msg.cur_num();
	acc_num = msg.acc_num();
}

TurntablePBDataRecord_s::TurntablePBDataRecord_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int TurntablePBDataRecord_s::CreateInit() {
	cid = (uint64_t)0;
	id = (int32_t)0;
	time = (int64_t)0;
	return 0;
}

int TurntablePBDataRecord_s::ResumeInit() {
	return 0;
}

void TurntablePBDataRecord_s::write_to_pbmsg(::proto_ff::TurntablePBDataRecord & msg) const {
	msg.set_cid((uint64_t)cid);
	msg.set_name(name.data());
	msg.set_id((int32_t)id);
	msg.set_time((int64_t)time);
}

void TurntablePBDataRecord_s::read_from_pbmsg(const ::proto_ff::TurntablePBDataRecord & msg) {
	cid = msg.cid();
	name = msg.name();
	id = msg.id();
	time = msg.time();
}

OneSuperGiftBuy_s::OneSuperGiftBuy_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int OneSuperGiftBuy_s::CreateInit() {
	id = (int32_t)0;
	cur_num = (int32_t)0;
	max_num = (int32_t)0;
	return 0;
}

int OneSuperGiftBuy_s::ResumeInit() {
	return 0;
}

void OneSuperGiftBuy_s::write_to_pbmsg(::proto_ff::OneSuperGiftBuy & msg) const {
	msg.set_id((int32_t)id);
	msg.set_cur_num((int32_t)cur_num);
	msg.set_max_num((int32_t)max_num);
}

void OneSuperGiftBuy_s::read_from_pbmsg(const ::proto_ff::OneSuperGiftBuy & msg) {
	id = msg.id();
	cur_num = msg.cur_num();
	max_num = msg.max_num();
}

OnWelfareInvestRewardData_s::OnWelfareInvestRewardData_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int OnWelfareInvestRewardData_s::CreateInit() {
	id = (int32_t)0;
	status = (int32_t)0;
	return 0;
}

int OnWelfareInvestRewardData_s::ResumeInit() {
	return 0;
}

void OnWelfareInvestRewardData_s::write_to_pbmsg(::proto_ff::OnWelfareInvestRewardData & msg) const {
	msg.set_id((int32_t)id);
	msg.set_status((int32_t)status);
}

void OnWelfareInvestRewardData_s::read_from_pbmsg(const ::proto_ff::OnWelfareInvestRewardData & msg) {
	id = msg.id();
	status = msg.status();
}

OneWelfareInvestData_s::OneWelfareInvestData_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int OneWelfareInvestData_s::CreateInit() {
	invest_id = (int32_t)0;
	status = (int32_t)0;
	return 0;
}

int OneWelfareInvestData_s::ResumeInit() {
	return 0;
}

void OneWelfareInvestData_s::write_to_pbmsg(::proto_ff::OneWelfareInvestData & msg) const {
	msg.set_invest_id((int32_t)invest_id);
	msg.set_status((int32_t)status);
	for(int32_t i = 0; i < (int32_t)data.size(); ++i) {
		::proto_ff::OnWelfareInvestRewardData* temp_data = msg.add_data();
		data[i].write_to_pbmsg(*temp_data);
	}
}

void OneWelfareInvestData_s::read_from_pbmsg(const ::proto_ff::OneWelfareInvestData & msg) {
	invest_id = msg.invest_id();
	status = msg.status();
	data.resize((int)msg.data_size() > (int)data.max_size() ? data.max_size() : msg.data_size());
	for(int32_t i = 0; i < (int32_t)data.size(); ++i) {
		const ::proto_ff::OnWelfareInvestRewardData & temp_data = msg.data(i);
		data[i].read_from_pbmsg(temp_data);
	}
}

OneYTTLGift_s::OneYTTLGift_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int OneYTTLGift_s::CreateInit() {
	id = (int32_t)0;
	buyed = (int32_t)0;
	return 0;
}

int OneYTTLGift_s::ResumeInit() {
	return 0;
}

void OneYTTLGift_s::write_to_pbmsg(::proto_ff::OneYTTLGift & msg) const {
	msg.set_id((int32_t)id);
	msg.set_buyed((int32_t)buyed);
}

void OneYTTLGift_s::read_from_pbmsg(const ::proto_ff::OneYTTLGift & msg) {
	id = msg.id();
	buyed = msg.buyed();
}

DailyWelfarePBData_s::DailyWelfarePBData_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int DailyWelfarePBData_s::CreateInit() {
	flush_time = (int64_t)0;
	xing_yun_super_gift_status = (int32_t)0;
	cur_recharge_num = (int32_t)0;
	return 0;
}

int DailyWelfarePBData_s::ResumeInit() {
	return 0;
}

void DailyWelfarePBData_s::write_to_pbmsg(::proto_ff::DailyWelfarePBData & msg) const {
	msg.set_flush_time((int64_t)flush_time);
	for(int32_t i = 0; i < (int32_t)xing_yun_mi_shi.size(); ++i) {
		::proto_ff::XingYunMiShiPBData* temp_xing_yun_mi_shi = msg.add_xing_yun_mi_shi();
		xing_yun_mi_shi[i].write_to_pbmsg(*temp_xing_yun_mi_shi);
	}
	msg.set_xing_yun_super_gift_status((int32_t)xing_yun_super_gift_status);
	for(int32_t i = 0; i < (int32_t)daily_gift.size(); ++i) {
		::proto_ff::DailyGiftPBData* temp_daily_gift = msg.add_daily_gift();
		daily_gift[i].write_to_pbmsg(*temp_daily_gift);
	}
	for(int32_t i = 0; i < (int32_t)today_recharge.size(); ++i) {
		::proto_ff::LianChongTodayPBData* temp_today_recharge = msg.add_today_recharge();
		today_recharge[i].write_to_pbmsg(*temp_today_recharge);
	}
	for(int32_t i = 0; i < (int32_t)acc_recharge.size(); ++i) {
		::proto_ff::LianChongAccPBData* temp_acc_recharge = msg.add_acc_recharge();
		acc_recharge[i].write_to_pbmsg(*temp_acc_recharge);
	}
	msg.set_cur_recharge_num((int32_t)cur_recharge_num);
	for(int32_t i = 0; i < (int32_t)month_card.size(); ++i) {
		::proto_ff::MonthCardPBData* temp_month_card = msg.add_month_card();
		month_card[i].write_to_pbmsg(*temp_month_card);
	}
	for(int32_t i = 0; i < (int32_t)turntable_acc.size(); ++i) {
		::proto_ff::TurntableAccPBData* temp_turntable_acc = msg.add_turntable_acc();
		turntable_acc[i].write_to_pbmsg(*temp_turntable_acc);
	}
	for(int32_t i = 0; i < (int32_t)turntable.size(); ++i) {
		::proto_ff::TurntablePBData* temp_turntable = msg.add_turntable();
		turntable[i].write_to_pbmsg(*temp_turntable);
	}
	for(int32_t i = 0; i < (int32_t)turntable_record.size(); ++i) {
		::proto_ff::TurntablePBDataRecord* temp_turntable_record = msg.add_turntable_record();
		turntable_record[i].write_to_pbmsg(*temp_turntable_record);
	}
	for(int32_t i = 0; i < (int32_t)super_buy.size(); ++i) {
		::proto_ff::OneSuperGiftBuy* temp_super_buy = msg.add_super_buy();
		super_buy[i].write_to_pbmsg(*temp_super_buy);
	}
	for(int32_t i = 0; i < (int32_t)invest.size(); ++i) {
		::proto_ff::OneWelfareInvestData* temp_invest = msg.add_invest();
		invest[i].write_to_pbmsg(*temp_invest);
	}
	for(int32_t i = 0; i < (int32_t)yttl_gift.size(); ++i) {
		::proto_ff::OneYTTLGift* temp_yttl_gift = msg.add_yttl_gift();
		yttl_gift[i].write_to_pbmsg(*temp_yttl_gift);
	}
}

void DailyWelfarePBData_s::read_from_pbmsg(const ::proto_ff::DailyWelfarePBData & msg) {
	flush_time = msg.flush_time();
	xing_yun_mi_shi.resize((int)msg.xing_yun_mi_shi_size() > (int)xing_yun_mi_shi.max_size() ? xing_yun_mi_shi.max_size() : msg.xing_yun_mi_shi_size());
	for(int32_t i = 0; i < (int32_t)xing_yun_mi_shi.size(); ++i) {
		const ::proto_ff::XingYunMiShiPBData & temp_xing_yun_mi_shi = msg.xing_yun_mi_shi(i);
		xing_yun_mi_shi[i].read_from_pbmsg(temp_xing_yun_mi_shi);
	}
	xing_yun_super_gift_status = msg.xing_yun_super_gift_status();
	daily_gift.resize((int)msg.daily_gift_size() > (int)daily_gift.max_size() ? daily_gift.max_size() : msg.daily_gift_size());
	for(int32_t i = 0; i < (int32_t)daily_gift.size(); ++i) {
		const ::proto_ff::DailyGiftPBData & temp_daily_gift = msg.daily_gift(i);
		daily_gift[i].read_from_pbmsg(temp_daily_gift);
	}
	today_recharge.resize((int)msg.today_recharge_size() > (int)today_recharge.max_size() ? today_recharge.max_size() : msg.today_recharge_size());
	for(int32_t i = 0; i < (int32_t)today_recharge.size(); ++i) {
		const ::proto_ff::LianChongTodayPBData & temp_today_recharge = msg.today_recharge(i);
		today_recharge[i].read_from_pbmsg(temp_today_recharge);
	}
	acc_recharge.resize((int)msg.acc_recharge_size() > (int)acc_recharge.max_size() ? acc_recharge.max_size() : msg.acc_recharge_size());
	for(int32_t i = 0; i < (int32_t)acc_recharge.size(); ++i) {
		const ::proto_ff::LianChongAccPBData & temp_acc_recharge = msg.acc_recharge(i);
		acc_recharge[i].read_from_pbmsg(temp_acc_recharge);
	}
	cur_recharge_num = msg.cur_recharge_num();
	month_card.resize((int)msg.month_card_size() > (int)month_card.max_size() ? month_card.max_size() : msg.month_card_size());
	for(int32_t i = 0; i < (int32_t)month_card.size(); ++i) {
		const ::proto_ff::MonthCardPBData & temp_month_card = msg.month_card(i);
		month_card[i].read_from_pbmsg(temp_month_card);
	}
	turntable_acc.resize((int)msg.turntable_acc_size() > (int)turntable_acc.max_size() ? turntable_acc.max_size() : msg.turntable_acc_size());
	for(int32_t i = 0; i < (int32_t)turntable_acc.size(); ++i) {
		const ::proto_ff::TurntableAccPBData & temp_turntable_acc = msg.turntable_acc(i);
		turntable_acc[i].read_from_pbmsg(temp_turntable_acc);
	}
	turntable.resize((int)msg.turntable_size() > (int)turntable.max_size() ? turntable.max_size() : msg.turntable_size());
	for(int32_t i = 0; i < (int32_t)turntable.size(); ++i) {
		const ::proto_ff::TurntablePBData & temp_turntable = msg.turntable(i);
		turntable[i].read_from_pbmsg(temp_turntable);
	}
	turntable_record.resize((int)msg.turntable_record_size() > (int)turntable_record.max_size() ? turntable_record.max_size() : msg.turntable_record_size());
	for(int32_t i = 0; i < (int32_t)turntable_record.size(); ++i) {
		const ::proto_ff::TurntablePBDataRecord & temp_turntable_record = msg.turntable_record(i);
		turntable_record[i].read_from_pbmsg(temp_turntable_record);
	}
	super_buy.resize((int)msg.super_buy_size() > (int)super_buy.max_size() ? super_buy.max_size() : msg.super_buy_size());
	for(int32_t i = 0; i < (int32_t)super_buy.size(); ++i) {
		const ::proto_ff::OneSuperGiftBuy & temp_super_buy = msg.super_buy(i);
		super_buy[i].read_from_pbmsg(temp_super_buy);
	}
	invest.resize((int)msg.invest_size() > (int)invest.max_size() ? invest.max_size() : msg.invest_size());
	for(int32_t i = 0; i < (int32_t)invest.size(); ++i) {
		const ::proto_ff::OneWelfareInvestData & temp_invest = msg.invest(i);
		invest[i].read_from_pbmsg(temp_invest);
	}
	yttl_gift.resize((int)msg.yttl_gift_size() > (int)yttl_gift.max_size() ? yttl_gift.max_size() : msg.yttl_gift_size());
	for(int32_t i = 0; i < (int32_t)yttl_gift.size(); ++i) {
		const ::proto_ff::OneYTTLGift & temp_yttl_gift = msg.yttl_gift(i);
		yttl_gift[i].read_from_pbmsg(temp_yttl_gift);
	}
}

SynRankEntry_s::SynRankEntry_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int SynRankEntry_s::CreateInit() {
	cid = (uint64_t)0;
	fight = (uint64_t)0;
	zid = (int32_t)0;
	return 0;
}

int SynRankEntry_s::ResumeInit() {
	return 0;
}

void SynRankEntry_s::write_to_pbmsg(::proto_ff::SynRankEntry & msg) const {
	msg.set_cid((uint64_t)cid);
	msg.set_fight((uint64_t)fight);
	msg.set_zid((int32_t)zid);
}

void SynRankEntry_s::read_from_pbmsg(const ::proto_ff::SynRankEntry & msg) {
	cid = msg.cid();
	fight = msg.fight();
	zid = msg.zid();
}

C2SSynInitRankReq_s::C2SSynInitRankReq_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int C2SSynInitRankReq_s::CreateInit() {
	return 0;
}

int C2SSynInitRankReq_s::ResumeInit() {
	return 0;
}

void C2SSynInitRankReq_s::write_to_pbmsg(::proto_ff::C2SSynInitRankReq & msg) const {
	for(int32_t i = 0; i < (int32_t)infos.size(); ++i) {
		::proto_ff::SynRankEntry* temp_infos = msg.add_infos();
		infos[i].write_to_pbmsg(*temp_infos);
	}
}

void C2SSynInitRankReq_s::read_from_pbmsg(const ::proto_ff::C2SSynInitRankReq & msg) {
	infos.resize((int)msg.infos_size() > (int)infos.max_size() ? infos.max_size() : msg.infos_size());
	for(int32_t i = 0; i < (int32_t)infos.size(); ++i) {
		const ::proto_ff::SynRankEntry & temp_infos = msg.infos(i);
		infos[i].read_from_pbmsg(temp_infos);
	}
}

FindTreasureRewardRecord_s::FindTreasureRewardRecord_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int FindTreasureRewardRecord_s::CreateInit() {
	cid = (uint64_t)0;
	id = (uint32_t)0;
	time = (uint32_t)0;
	return 0;
}

int FindTreasureRewardRecord_s::ResumeInit() {
	return 0;
}

void FindTreasureRewardRecord_s::write_to_pbmsg(::proto_ff::FindTreasureRewardRecord & msg) const {
	msg.set_cid((uint64_t)cid);
	msg.set_name(name.data());
	msg.set_id((uint32_t)id);
	msg.set_time((uint32_t)time);
}

void FindTreasureRewardRecord_s::read_from_pbmsg(const ::proto_ff::FindTreasureRewardRecord & msg) {
	cid = msg.cid();
	name = msg.name();
	id = msg.id();
	time = msg.time();
}

FindTreasureRewardRecordDBData_s::FindTreasureRewardRecordDBData_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int FindTreasureRewardRecordDBData_s::CreateInit() {
	id = (uint32_t)0;
	num = (uint32_t)0;
	return 0;
}

int FindTreasureRewardRecordDBData_s::ResumeInit() {
	return 0;
}

void FindTreasureRewardRecordDBData_s::write_to_pbmsg(::proto_ff::FindTreasureRewardRecordDBData & msg) const {
	msg.set_id((uint32_t)id);
	msg.set_num((uint32_t)num);
	for(int32_t i = 0; i < (int32_t)record.size(); ++i) {
		::proto_ff::FindTreasureRewardRecord* temp_record = msg.add_record();
		record[i].write_to_pbmsg(*temp_record);
	}
}

void FindTreasureRewardRecordDBData_s::read_from_pbmsg(const ::proto_ff::FindTreasureRewardRecordDBData & msg) {
	id = msg.id();
	num = msg.num();
	record.resize((int)msg.record_size() > (int)record.max_size() ? record.max_size() : msg.record_size());
	for(int32_t i = 0; i < (int32_t)record.size(); ++i) {
		const ::proto_ff::FindTreasureRewardRecord & temp_record = msg.record(i);
		record[i].read_from_pbmsg(temp_record);
	}
}

FindTreasureBigDragonRewardData_s::FindTreasureBigDragonRewardData_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int FindTreasureBigDragonRewardData_s::CreateInit() {
	id = (uint32_t)0;
	status = (uint32_t)0;
	return 0;
}

int FindTreasureBigDragonRewardData_s::ResumeInit() {
	return 0;
}

void FindTreasureBigDragonRewardData_s::write_to_pbmsg(::proto_ff::FindTreasureBigDragonRewardData & msg) const {
	msg.set_id((uint32_t)id);
	msg.set_status((uint32_t)status);
}

void FindTreasureBigDragonRewardData_s::read_from_pbmsg(const ::proto_ff::FindTreasureBigDragonRewardData & msg) {
	id = msg.id();
	status = msg.status();
}

FindTreasureBigDragonData_s::FindTreasureBigDragonData_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int FindTreasureBigDragonData_s::CreateInit() {
	id = (uint32_t)0;
	all_num = (uint32_t)0;
	pool_id = (uint32_t)0;
	pool_time = (uint64_t)0;
	return 0;
}

int FindTreasureBigDragonData_s::ResumeInit() {
	return 0;
}

void FindTreasureBigDragonData_s::write_to_pbmsg(::proto_ff::FindTreasureBigDragonData & msg) const {
	msg.set_id((uint32_t)id);
	msg.set_all_num((uint32_t)all_num);
	for(int32_t i = 0; i < (int32_t)reward.size(); ++i) {
		::proto_ff::FindTreasureBigDragonRewardData* temp_reward = msg.add_reward();
		reward[i].write_to_pbmsg(*temp_reward);
	}
	msg.set_pool_id((uint32_t)pool_id);
	msg.set_pool_time((uint64_t)pool_time);
}

void FindTreasureBigDragonData_s::read_from_pbmsg(const ::proto_ff::FindTreasureBigDragonData & msg) {
	id = msg.id();
	all_num = msg.all_num();
	reward.resize((int)msg.reward_size() > (int)reward.max_size() ? reward.max_size() : msg.reward_size());
	for(int32_t i = 0; i < (int32_t)reward.size(); ++i) {
		const ::proto_ff::FindTreasureBigDragonRewardData & temp_reward = msg.reward(i);
		reward[i].read_from_pbmsg(temp_reward);
	}
	pool_id = msg.pool_id();
	pool_time = msg.pool_time();
}

FindTreasureBaiLianShopData_s::FindTreasureBaiLianShopData_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int FindTreasureBaiLianShopData_s::CreateInit() {
	id = (uint32_t)0;
	left_num = (uint32_t)0;
	all_num = (uint32_t)0;
	return 0;
}

int FindTreasureBaiLianShopData_s::ResumeInit() {
	return 0;
}

void FindTreasureBaiLianShopData_s::write_to_pbmsg(::proto_ff::FindTreasureBaiLianShopData & msg) const {
	msg.set_id((uint32_t)id);
	msg.set_left_num((uint32_t)left_num);
	msg.set_all_num((uint32_t)all_num);
}

void FindTreasureBaiLianShopData_s::read_from_pbmsg(const ::proto_ff::FindTreasureBaiLianShopData & msg) {
	id = msg.id();
	left_num = msg.left_num();
	all_num = msg.all_num();
}

FindTreasureBaiLianActiveData_s::FindTreasureBaiLianActiveData_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int FindTreasureBaiLianActiveData_s::CreateInit() {
	id = (uint32_t)0;
	type = (uint32_t)0;
	buy_status = (uint32_t)0;
	open_status = (int32_t)0;
	last_time = (uint64_t)0;
	return 0;
}

int FindTreasureBaiLianActiveData_s::ResumeInit() {
	return 0;
}

void FindTreasureBaiLianActiveData_s::write_to_pbmsg(::proto_ff::FindTreasureBaiLianActiveData & msg) const {
	msg.set_id((uint32_t)id);
	msg.set_type((uint32_t)type);
	msg.set_buy_status((uint32_t)buy_status);
	for(int32_t i = 0; i < (int32_t)shop_data.size(); ++i) {
		::proto_ff::FindTreasureBaiLianShopData* temp_shop_data = msg.add_shop_data();
		shop_data[i].write_to_pbmsg(*temp_shop_data);
	}
	msg.set_open_status((int32_t)open_status);
	msg.set_last_time((uint64_t)last_time);
}

void FindTreasureBaiLianActiveData_s::read_from_pbmsg(const ::proto_ff::FindTreasureBaiLianActiveData & msg) {
	id = msg.id();
	type = msg.type();
	buy_status = msg.buy_status();
	shop_data.resize((int)msg.shop_data_size() > (int)shop_data.max_size() ? shop_data.max_size() : msg.shop_data_size());
	for(int32_t i = 0; i < (int32_t)shop_data.size(); ++i) {
		const ::proto_ff::FindTreasureBaiLianShopData & temp_shop_data = msg.shop_data(i);
		shop_data[i].read_from_pbmsg(temp_shop_data);
	}
	open_status = msg.open_status();
	last_time = msg.last_time();
}

FindTreasureBaiLianData_s::FindTreasureBaiLianData_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int FindTreasureBaiLianData_s::CreateInit() {
	id = (uint32_t)0;
	pool_id = (uint32_t)0;
	pool_time = (uint64_t)0;
	return 0;
}

int FindTreasureBaiLianData_s::ResumeInit() {
	return 0;
}

void FindTreasureBaiLianData_s::write_to_pbmsg(::proto_ff::FindTreasureBaiLianData & msg) const {
	msg.set_id((uint32_t)id);
	for(int32_t i = 0; i < (int32_t)record.size(); ++i) {
		::proto_ff::FindTreasureRewardRecord* temp_record = msg.add_record();
		record[i].write_to_pbmsg(*temp_record);
	}
	for(int32_t i = 0; i < (int32_t)active.size(); ++i) {
		::proto_ff::FindTreasureBaiLianActiveData* temp_active = msg.add_active();
		active[i].write_to_pbmsg(*temp_active);
	}
	msg.set_pool_id((uint32_t)pool_id);
	msg.set_pool_time((uint64_t)pool_time);
}

void FindTreasureBaiLianData_s::read_from_pbmsg(const ::proto_ff::FindTreasureBaiLianData & msg) {
	id = msg.id();
	record.resize((int)msg.record_size() > (int)record.max_size() ? record.max_size() : msg.record_size());
	for(int32_t i = 0; i < (int32_t)record.size(); ++i) {
		const ::proto_ff::FindTreasureRewardRecord & temp_record = msg.record(i);
		record[i].read_from_pbmsg(temp_record);
	}
	active.resize((int)msg.active_size() > (int)active.max_size() ? active.max_size() : msg.active_size());
	for(int32_t i = 0; i < (int32_t)active.size(); ++i) {
		const ::proto_ff::FindTreasureBaiLianActiveData & temp_active = msg.active(i);
		active[i].read_from_pbmsg(temp_active);
	}
	pool_id = msg.pool_id();
	pool_time = msg.pool_time();
}

FindTreasureSiShengRewardData_s::FindTreasureSiShengRewardData_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int FindTreasureSiShengRewardData_s::CreateInit() {
	id = (uint32_t)0;
	status = (uint32_t)0;
	return 0;
}

int FindTreasureSiShengRewardData_s::ResumeInit() {
	return 0;
}

void FindTreasureSiShengRewardData_s::write_to_pbmsg(::proto_ff::FindTreasureSiShengRewardData & msg) const {
	msg.set_id((uint32_t)id);
	msg.set_status((uint32_t)status);
}

void FindTreasureSiShengRewardData_s::read_from_pbmsg(const ::proto_ff::FindTreasureSiShengRewardData & msg) {
	id = msg.id();
	status = msg.status();
}

FindTreasureSiShengData_s::FindTreasureSiShengData_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int FindTreasureSiShengData_s::CreateInit() {
	id = (uint32_t)0;
	all_num = (uint32_t)0;
	pool_id = (uint32_t)0;
	pool_time = (uint64_t)0;
	return 0;
}

int FindTreasureSiShengData_s::ResumeInit() {
	return 0;
}

void FindTreasureSiShengData_s::write_to_pbmsg(::proto_ff::FindTreasureSiShengData & msg) const {
	msg.set_id((uint32_t)id);
	for(int32_t i = 0; i < (int32_t)person_total_reward.size(); ++i) {
		::proto_ff::FindTreasureSiShengRewardData* temp_person_total_reward = msg.add_person_total_reward();
		person_total_reward[i].write_to_pbmsg(*temp_person_total_reward);
	}
	for(int32_t i = 0; i < (int32_t)server_total_reward.size(); ++i) {
		::proto_ff::FindTreasureSiShengRewardData* temp_server_total_reward = msg.add_server_total_reward();
		server_total_reward[i].write_to_pbmsg(*temp_server_total_reward);
	}
	msg.set_all_num((uint32_t)all_num);
	for(int32_t i = 0; i < (int32_t)record.size(); ++i) {
		::proto_ff::FindTreasureRewardRecord* temp_record = msg.add_record();
		record[i].write_to_pbmsg(*temp_record);
	}
	msg.set_pool_id((uint32_t)pool_id);
	msg.set_pool_time((uint64_t)pool_time);
}

void FindTreasureSiShengData_s::read_from_pbmsg(const ::proto_ff::FindTreasureSiShengData & msg) {
	id = msg.id();
	person_total_reward.resize((int)msg.person_total_reward_size() > (int)person_total_reward.max_size() ? person_total_reward.max_size() : msg.person_total_reward_size());
	for(int32_t i = 0; i < (int32_t)person_total_reward.size(); ++i) {
		const ::proto_ff::FindTreasureSiShengRewardData & temp_person_total_reward = msg.person_total_reward(i);
		person_total_reward[i].read_from_pbmsg(temp_person_total_reward);
	}
	server_total_reward.resize((int)msg.server_total_reward_size() > (int)server_total_reward.max_size() ? server_total_reward.max_size() : msg.server_total_reward_size());
	for(int32_t i = 0; i < (int32_t)server_total_reward.size(); ++i) {
		const ::proto_ff::FindTreasureSiShengRewardData & temp_server_total_reward = msg.server_total_reward(i);
		server_total_reward[i].read_from_pbmsg(temp_server_total_reward);
	}
	all_num = msg.all_num();
	record.resize((int)msg.record_size() > (int)record.max_size() ? record.max_size() : msg.record_size());
	for(int32_t i = 0; i < (int32_t)record.size(); ++i) {
		const ::proto_ff::FindTreasureRewardRecord & temp_record = msg.record(i);
		record[i].read_from_pbmsg(temp_record);
	}
	pool_id = msg.pool_id();
	pool_time = msg.pool_time();
}

FindTreatureDBData_s::FindTreatureDBData_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int FindTreatureDBData_s::CreateInit() {
	return 0;
}

int FindTreatureDBData_s::ResumeInit() {
	return 0;
}

void FindTreatureDBData_s::write_to_pbmsg(::proto_ff::FindTreatureDBData & msg) const {
	for(int32_t i = 0; i < (int32_t)big_dragon.size(); ++i) {
		::proto_ff::FindTreasureBigDragonData* temp_big_dragon = msg.add_big_dragon();
		big_dragon[i].write_to_pbmsg(*temp_big_dragon);
	}
	for(int32_t i = 0; i < (int32_t)bai_lian.size(); ++i) {
		::proto_ff::FindTreasureBaiLianData* temp_bai_lian = msg.add_bai_lian();
		bai_lian[i].write_to_pbmsg(*temp_bai_lian);
	}
	for(int32_t i = 0; i < (int32_t)si_sheng.size(); ++i) {
		::proto_ff::FindTreasureSiShengData* temp_si_sheng = msg.add_si_sheng();
		si_sheng[i].write_to_pbmsg(*temp_si_sheng);
	}
}

void FindTreatureDBData_s::read_from_pbmsg(const ::proto_ff::FindTreatureDBData & msg) {
	big_dragon.resize((int)msg.big_dragon_size() > (int)big_dragon.max_size() ? big_dragon.max_size() : msg.big_dragon_size());
	for(int32_t i = 0; i < (int32_t)big_dragon.size(); ++i) {
		const ::proto_ff::FindTreasureBigDragonData & temp_big_dragon = msg.big_dragon(i);
		big_dragon[i].read_from_pbmsg(temp_big_dragon);
	}
	bai_lian.resize((int)msg.bai_lian_size() > (int)bai_lian.max_size() ? bai_lian.max_size() : msg.bai_lian_size());
	for(int32_t i = 0; i < (int32_t)bai_lian.size(); ++i) {
		const ::proto_ff::FindTreasureBaiLianData & temp_bai_lian = msg.bai_lian(i);
		bai_lian[i].read_from_pbmsg(temp_bai_lian);
	}
	si_sheng.resize((int)msg.si_sheng_size() > (int)si_sheng.max_size() ? si_sheng.max_size() : msg.si_sheng_size());
	for(int32_t i = 0; i < (int32_t)si_sheng.size(); ++i) {
		const ::proto_ff::FindTreasureSiShengData & temp_si_sheng = msg.si_sheng(i);
		si_sheng[i].read_from_pbmsg(temp_si_sheng);
	}
}

FestDailyTotalRechargeOneProto_s::FestDailyTotalRechargeOneProto_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int FestDailyTotalRechargeOneProto_s::CreateInit() {
	id = (int32_t)0;
	status = (int32_t)0;
	return 0;
}

int FestDailyTotalRechargeOneProto_s::ResumeInit() {
	return 0;
}

void FestDailyTotalRechargeOneProto_s::write_to_pbmsg(::proto_ff::FestDailyTotalRechargeOneProto & msg) const {
	msg.set_id((int32_t)id);
	msg.set_status((int32_t)status);
}

void FestDailyTotalRechargeOneProto_s::read_from_pbmsg(const ::proto_ff::FestDailyTotalRechargeOneProto & msg) {
	id = msg.id();
	status = msg.status();
}

FestRTurnableRechargeOneProto_s::FestRTurnableRechargeOneProto_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int FestRTurnableRechargeOneProto_s::CreateInit() {
	id = (int32_t)0;
	cur_num = (int32_t)0;
	all_num = (int32_t)0;
	turable_num = (int32_t)0;
	return 0;
}

int FestRTurnableRechargeOneProto_s::ResumeInit() {
	return 0;
}

void FestRTurnableRechargeOneProto_s::write_to_pbmsg(::proto_ff::FestRTurnableRechargeOneProto & msg) const {
	msg.set_id((int32_t)id);
	msg.set_cur_num((int32_t)cur_num);
	msg.set_all_num((int32_t)all_num);
	msg.set_turable_num((int32_t)turable_num);
}

void FestRTurnableRechargeOneProto_s::read_from_pbmsg(const ::proto_ff::FestRTurnableRechargeOneProto & msg) {
	id = msg.id();
	cur_num = msg.cur_num();
	all_num = msg.all_num();
	turable_num = msg.turable_num();
}

RTurnableLogDBProto_s::RTurnableLogDBProto_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int RTurnableLogDBProto_s::CreateInit() {
	id = (int32_t)0;
	diamod = (int32_t)0;
	time = (uint64_t)0;
	return 0;
}

int RTurnableLogDBProto_s::ResumeInit() {
	return 0;
}

void RTurnableLogDBProto_s::write_to_pbmsg(::proto_ff::RTurnableLogDBProto & msg) const {
	msg.set_name(name.data());
	msg.set_id((int32_t)id);
	msg.set_diamod((int32_t)diamod);
	msg.set_time((uint64_t)time);
}

void RTurnableLogDBProto_s::read_from_pbmsg(const ::proto_ff::RTurnableLogDBProto & msg) {
	name = msg.name();
	id = msg.id();
	diamod = msg.diamod();
	time = msg.time();
}

FestRTurnableLogDBProto_s::FestRTurnableLogDBProto_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int FestRTurnableLogDBProto_s::CreateInit() {
	template_id = (int32_t)0;
	return 0;
}

int FestRTurnableLogDBProto_s::ResumeInit() {
	return 0;
}

void FestRTurnableLogDBProto_s::write_to_pbmsg(::proto_ff::FestRTurnableLogDBProto & msg) const {
	msg.set_template_id((int32_t)template_id);
	for(int32_t i = 0; i < (int32_t)info.size(); ++i) {
		::proto_ff::RTurnableLogDBProto* temp_info = msg.add_info();
		info[i].write_to_pbmsg(*temp_info);
	}
}

void FestRTurnableLogDBProto_s::read_from_pbmsg(const ::proto_ff::FestRTurnableLogDBProto & msg) {
	template_id = msg.template_id();
	info.resize((int)msg.info_size() > (int)info.max_size() ? info.max_size() : msg.info_size());
	for(int32_t i = 0; i < (int32_t)info.size(); ++i) {
		const ::proto_ff::RTurnableLogDBProto & temp_info = msg.info(i);
		info[i].read_from_pbmsg(temp_info);
	}
}

FestTurnableTaskProto_s::FestTurnableTaskProto_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int FestTurnableTaskProto_s::CreateInit() {
	id = (int32_t)0;
	status = (int32_t)0;
	cur_num = (int32_t)0;
	all_num = (int32_t)0;
	return 0;
}

int FestTurnableTaskProto_s::ResumeInit() {
	return 0;
}

void FestTurnableTaskProto_s::write_to_pbmsg(::proto_ff::FestTurnableTaskProto & msg) const {
	msg.set_id((int32_t)id);
	msg.set_status((int32_t)status);
	msg.set_cur_num((int32_t)cur_num);
	msg.set_all_num((int32_t)all_num);
}

void FestTurnableTaskProto_s::read_from_pbmsg(const ::proto_ff::FestTurnableTaskProto & msg) {
	id = msg.id();
	status = msg.status();
	cur_num = msg.cur_num();
	all_num = msg.all_num();
}

FestDonateTaskProto_s::FestDonateTaskProto_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int FestDonateTaskProto_s::CreateInit() {
	id = (int32_t)0;
	status = (int32_t)0;
	cur_num = (int32_t)0;
	all_num = (int32_t)0;
	return 0;
}

int FestDonateTaskProto_s::ResumeInit() {
	return 0;
}

void FestDonateTaskProto_s::write_to_pbmsg(::proto_ff::FestDonateTaskProto & msg) const {
	msg.set_id((int32_t)id);
	msg.set_status((int32_t)status);
	msg.set_cur_num((int32_t)cur_num);
	msg.set_all_num((int32_t)all_num);
}

void FestDonateTaskProto_s::read_from_pbmsg(const ::proto_ff::FestDonateTaskProto & msg) {
	id = msg.id();
	status = msg.status();
	cur_num = msg.cur_num();
	all_num = msg.all_num();
}

FestDonateSingleProto_s::FestDonateSingleProto_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int FestDonateSingleProto_s::CreateInit() {
	id = (int32_t)0;
	status = (int32_t)0;
	return 0;
}

int FestDonateSingleProto_s::ResumeInit() {
	return 0;
}

void FestDonateSingleProto_s::write_to_pbmsg(::proto_ff::FestDonateSingleProto & msg) const {
	msg.set_id((int32_t)id);
	msg.set_status((int32_t)status);
}

void FestDonateSingleProto_s::read_from_pbmsg(const ::proto_ff::FestDonateSingleProto & msg) {
	id = msg.id();
	status = msg.status();
}

FestDonateServerProto_s::FestDonateServerProto_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int FestDonateServerProto_s::CreateInit() {
	id = (int32_t)0;
	status = (int32_t)0;
	return 0;
}

int FestDonateServerProto_s::ResumeInit() {
	return 0;
}

void FestDonateServerProto_s::write_to_pbmsg(::proto_ff::FestDonateServerProto & msg) const {
	msg.set_id((int32_t)id);
	msg.set_status((int32_t)status);
}

void FestDonateServerProto_s::read_from_pbmsg(const ::proto_ff::FestDonateServerProto & msg) {
	id = msg.id();
	status = msg.status();
}

FestOnlineOneProto_s::FestOnlineOneProto_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int FestOnlineOneProto_s::CreateInit() {
	id = (int32_t)0;
	status = (int32_t)0;
	start_time = (uint64_t)0;
	end_time = (uint64_t)0;
	return 0;
}

int FestOnlineOneProto_s::ResumeInit() {
	return 0;
}

void FestOnlineOneProto_s::write_to_pbmsg(::proto_ff::FestOnlineOneProto & msg) const {
	msg.set_id((int32_t)id);
	msg.set_status((int32_t)status);
	msg.set_start_time((uint64_t)start_time);
	msg.set_end_time((uint64_t)end_time);
}

void FestOnlineOneProto_s::read_from_pbmsg(const ::proto_ff::FestOnlineOneProto & msg) {
	id = msg.id();
	status = msg.status();
	start_time = msg.start_time();
	end_time = msg.end_time();
}

FestCollectWordOneProto_s::FestCollectWordOneProto_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int FestCollectWordOneProto_s::CreateInit() {
	id = (int32_t)0;
	left_num = (uint32_t)0;
	return 0;
}

int FestCollectWordOneProto_s::ResumeInit() {
	return 0;
}

void FestCollectWordOneProto_s::write_to_pbmsg(::proto_ff::FestCollectWordOneProto & msg) const {
	msg.set_id((int32_t)id);
	msg.set_left_num((uint32_t)left_num);
}

void FestCollectWordOneProto_s::read_from_pbmsg(const ::proto_ff::FestCollectWordOneProto & msg) {
	id = msg.id();
	left_num = msg.left_num();
}

DonateServerDBProto_s::DonateServerDBProto_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int DonateServerDBProto_s::CreateInit() {
	template_id = (int32_t)0;
	server_num = (uint32_t)0;
	return 0;
}

int DonateServerDBProto_s::ResumeInit() {
	return 0;
}

void DonateServerDBProto_s::write_to_pbmsg(::proto_ff::DonateServerDBProto & msg) const {
	msg.set_template_id((int32_t)template_id);
	msg.set_server_num((uint32_t)server_num);
}

void DonateServerDBProto_s::read_from_pbmsg(const ::proto_ff::DonateServerDBProto & msg) {
	template_id = msg.template_id();
	server_num = msg.server_num();
}

DrawPizeTaskProto_s::DrawPizeTaskProto_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int DrawPizeTaskProto_s::CreateInit() {
	id = (int32_t)0;
	status = (uint32_t)0;
	return 0;
}

int DrawPizeTaskProto_s::ResumeInit() {
	return 0;
}

void DrawPizeTaskProto_s::write_to_pbmsg(::proto_ff::DrawPizeTaskProto & msg) const {
	msg.set_id((int32_t)id);
	msg.set_status((uint32_t)status);
}

void DrawPizeTaskProto_s::read_from_pbmsg(const ::proto_ff::DrawPizeTaskProto & msg) {
	id = msg.id();
	status = msg.status();
}

DrawPizeProto_s::DrawPizeProto_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int DrawPizeProto_s::CreateInit() {
	choujiang_num = (uint32_t)0;
	return 0;
}

int DrawPizeProto_s::ResumeInit() {
	return 0;
}

void DrawPizeProto_s::write_to_pbmsg(::proto_ff::DrawPizeProto & msg) const {
	for(int32_t i = 0; i < (int32_t)task.size(); ++i) {
		::proto_ff::DrawPizeTaskProto* temp_task = msg.add_task();
		task[i].write_to_pbmsg(*temp_task);
	}
	msg.set_choujiang_num((uint32_t)choujiang_num);
}

void DrawPizeProto_s::read_from_pbmsg(const ::proto_ff::DrawPizeProto & msg) {
	task.resize((int)msg.task_size() > (int)task.max_size() ? task.max_size() : msg.task_size());
	for(int32_t i = 0; i < (int32_t)task.size(); ++i) {
		const ::proto_ff::DrawPizeTaskProto & temp_task = msg.task(i);
		task[i].read_from_pbmsg(temp_task);
	}
	choujiang_num = msg.choujiang_num();
}

DrawPizeLogDBProto_s::DrawPizeLogDBProto_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int DrawPizeLogDBProto_s::CreateInit() {
	id = (int32_t)0;
	time = (uint64_t)0;
	return 0;
}

int DrawPizeLogDBProto_s::ResumeInit() {
	return 0;
}

void DrawPizeLogDBProto_s::write_to_pbmsg(::proto_ff::DrawPizeLogDBProto & msg) const {
	msg.set_name(name.data());
	msg.set_id((int32_t)id);
	msg.set_time((uint64_t)time);
}

void DrawPizeLogDBProto_s::read_from_pbmsg(const ::proto_ff::DrawPizeLogDBProto & msg) {
	name = msg.name();
	id = msg.id();
	time = msg.time();
}

FestDrawPizeLogDBProto_s::FestDrawPizeLogDBProto_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int FestDrawPizeLogDBProto_s::CreateInit() {
	template_id = (int32_t)0;
	server_num = (uint32_t)0;
	return 0;
}

int FestDrawPizeLogDBProto_s::ResumeInit() {
	return 0;
}

void FestDrawPizeLogDBProto_s::write_to_pbmsg(::proto_ff::FestDrawPizeLogDBProto & msg) const {
	msg.set_template_id((int32_t)template_id);
	for(int32_t i = 0; i < (int32_t)info.size(); ++i) {
		::proto_ff::DrawPizeLogDBProto* temp_info = msg.add_info();
		info[i].write_to_pbmsg(*temp_info);
	}
	msg.set_server_num((uint32_t)server_num);
}

void FestDrawPizeLogDBProto_s::read_from_pbmsg(const ::proto_ff::FestDrawPizeLogDBProto & msg) {
	template_id = msg.template_id();
	info.resize((int)msg.info_size() > (int)info.max_size() ? info.max_size() : msg.info_size());
	for(int32_t i = 0; i < (int32_t)info.size(); ++i) {
		const ::proto_ff::DrawPizeLogDBProto & temp_info = msg.info(i);
		info[i].read_from_pbmsg(temp_info);
	}
	server_num = msg.server_num();
}

FestRankRewardData_s::FestRankRewardData_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int FestRankRewardData_s::CreateInit() {
	id = (int32_t)0;
	status = (uint32_t)0;
	return 0;
}

int FestRankRewardData_s::ResumeInit() {
	return 0;
}

void FestRankRewardData_s::write_to_pbmsg(::proto_ff::FestRankRewardData & msg) const {
	msg.set_id((int32_t)id);
	msg.set_status((uint32_t)status);
}

void FestRankRewardData_s::read_from_pbmsg(const ::proto_ff::FestRankRewardData & msg) {
	id = msg.id();
	status = msg.status();
}

FestRankData_s::FestRankData_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int FestRankData_s::CreateInit() {
	rank_id = (int32_t)0;
	active_status = (uint32_t)0;
	red_point_status = (uint32_t)0;
	gift_status = (uint32_t)0;
	return 0;
}

int FestRankData_s::ResumeInit() {
	return 0;
}

void FestRankData_s::write_to_pbmsg(::proto_ff::FestRankData & msg) const {
	msg.set_rank_id((int32_t)rank_id);
	for(int32_t i = 0; i < (int32_t)data.size(); ++i) {
		::proto_ff::FestRankRewardData* temp_data = msg.add_data();
		data[i].write_to_pbmsg(*temp_data);
	}
	msg.set_active_status((uint32_t)active_status);
	msg.set_red_point_status((uint32_t)red_point_status);
	msg.set_gift_status((uint32_t)gift_status);
}

void FestRankData_s::read_from_pbmsg(const ::proto_ff::FestRankData & msg) {
	rank_id = msg.rank_id();
	data.resize((int)msg.data_size() > (int)data.max_size() ? data.max_size() : msg.data_size());
	for(int32_t i = 0; i < (int32_t)data.size(); ++i) {
		const ::proto_ff::FestRankRewardData & temp_data = msg.data(i);
		data[i].read_from_pbmsg(temp_data);
	}
	active_status = msg.active_status();
	red_point_status = msg.red_point_status();
	gift_status = msg.gift_status();
}

FestRankDBData_s::FestRankDBData_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int FestRankDBData_s::CreateInit() {
	return 0;
}

int FestRankDBData_s::ResumeInit() {
	return 0;
}

void FestRankDBData_s::write_to_pbmsg(::proto_ff::FestRankDBData & msg) const {
	for(int32_t i = 0; i < (int32_t)data.size(); ++i) {
		::proto_ff::FestRankData* temp_data = msg.add_data();
		data[i].write_to_pbmsg(*temp_data);
	}
}

void FestRankDBData_s::read_from_pbmsg(const ::proto_ff::FestRankDBData & msg) {
	data.resize((int)msg.data_size() > (int)data.max_size() ? data.max_size() : msg.data_size());
	for(int32_t i = 0; i < (int32_t)data.size(); ++i) {
		const ::proto_ff::FestRankData & temp_data = msg.data(i);
		data[i].read_from_pbmsg(temp_data);
	}
}

NotifyWorldInfo_s::NotifyWorldInfo_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int NotifyWorldInfo_s::CreateInit() {
	world_lv = (int32_t)0;
	world_lv_4 = (int32_t)0;
	world_lv_8 = (int32_t)0;
	world_lv_16 = (int32_t)0;
	return 0;
}

int NotifyWorldInfo_s::ResumeInit() {
	return 0;
}

void NotifyWorldInfo_s::write_to_pbmsg(::proto_ff::NotifyWorldInfo & msg) const {
	msg.set_world_lv((int32_t)world_lv);
	msg.set_world_lv_4((int32_t)world_lv_4);
	msg.set_world_lv_8((int32_t)world_lv_8);
	msg.set_world_lv_16((int32_t)world_lv_16);
}

void NotifyWorldInfo_s::read_from_pbmsg(const ::proto_ff::NotifyWorldInfo & msg) {
	world_lv = msg.world_lv();
	world_lv_4 = msg.world_lv_4();
	world_lv_8 = msg.world_lv_8();
	world_lv_16 = msg.world_lv_16();
}

SynWorldInfoReq_s::SynWorldInfoReq_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int SynWorldInfoReq_s::CreateInit() {
	return 0;
}

int SynWorldInfoReq_s::ResumeInit() {
	return 0;
}

void SynWorldInfoReq_s::write_to_pbmsg(::proto_ff::SynWorldInfoReq & msg) const {
	for(int32_t i = 0; i < (int32_t)infos.size(); ++i) {
		::proto_ff::ComPair* temp_infos = msg.add_infos();
		infos[i].write_to_pbmsg(*temp_infos);
	}
}

void SynWorldInfoReq_s::read_from_pbmsg(const ::proto_ff::SynWorldInfoReq & msg) {
	infos.resize((int)msg.infos_size() > (int)infos.max_size() ? infos.max_size() : msg.infos_size());
	for(int32_t i = 0; i < (int32_t)infos.size(); ++i) {
		const ::proto_ff::ComPair & temp_infos = msg.infos(i);
		infos[i].read_from_pbmsg(temp_infos);
	}
}

SceneTransParam_s::SceneTransParam_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int SceneTransParam_s::CreateInit() {
	src_map = (uint64_t)0;
	trans_type = (int32_t)0;
	param1 = (int64_t)0;
	param2 = (int64_t)0;
	param3 = (int64_t)0;
	forceTP = (bool)0;
	ret = (int32_t)0;
	return 0;
}

int SceneTransParam_s::ResumeInit() {
	return 0;
}

void SceneTransParam_s::write_to_pbmsg(::proto_ff::SceneTransParam & msg) const {
	msg.set_src_map((uint64_t)src_map);
	msg.set_src_param(src_param.data());
	msg.set_trans_type((int32_t)trans_type);
	msg.set_param1((int64_t)param1);
	msg.set_param2((int64_t)param2);
	msg.set_param3((int64_t)param3);
	msg.set_str_param(str_param.data());
	msg.set_forcetp((bool)forceTP);
	msg.set_ret((int32_t)ret);
}

void SceneTransParam_s::read_from_pbmsg(const ::proto_ff::SceneTransParam & msg) {
	src_map = msg.src_map();
	src_param = msg.src_param();
	trans_type = msg.trans_type();
	param1 = msg.param1();
	param2 = msg.param2();
	param3 = msg.param3();
	str_param = msg.str_param();
	forceTP = msg.forcetp();
	ret = msg.ret();
}

FestHuiMengXiYouReward_s::FestHuiMengXiYouReward_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int FestHuiMengXiYouReward_s::CreateInit() {
	id = (int32_t)0;
	status = (int32_t)0;
	return 0;
}

int FestHuiMengXiYouReward_s::ResumeInit() {
	return 0;
}

void FestHuiMengXiYouReward_s::write_to_pbmsg(::proto_ff::FestHuiMengXiYouReward & msg) const {
	msg.set_id((int32_t)id);
	msg.set_status((int32_t)status);
}

void FestHuiMengXiYouReward_s::read_from_pbmsg(const ::proto_ff::FestHuiMengXiYouReward & msg) {
	id = msg.id();
	status = msg.status();
}

FestHuiMengXiYouGame_s::FestHuiMengXiYouGame_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int FestHuiMengXiYouGame_s::CreateInit() {
	id = (int32_t)0;
	cur_points = (int32_t)0;
	finish = (bool)0;
	cur_prestige = (int32_t)0;
	return 0;
}

int FestHuiMengXiYouGame_s::ResumeInit() {
	return 0;
}

void FestHuiMengXiYouGame_s::write_to_pbmsg(::proto_ff::FestHuiMengXiYouGame & msg) const {
	msg.set_id((int32_t)id);
	msg.set_cur_points((int32_t)cur_points);
	msg.set_finish((bool)finish);
	msg.set_cur_prestige((int32_t)cur_prestige);
}

void FestHuiMengXiYouGame_s::read_from_pbmsg(const ::proto_ff::FestHuiMengXiYouGame & msg) {
	id = msg.id();
	cur_points = msg.cur_points();
	finish = msg.finish();
	cur_prestige = msg.cur_prestige();
}

FestHuiMengXiYouData_s::FestHuiMengXiYouData_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int FestHuiMengXiYouData_s::CreateInit() {
	cur_points = (int32_t)0;
	prestige = (int32_t)0;
	flush_time = (uint64_t)0;
	cur_game_id = (int32_t)0;
	return 0;
}

int FestHuiMengXiYouData_s::ResumeInit() {
	return 0;
}

void FestHuiMengXiYouData_s::write_to_pbmsg(::proto_ff::FestHuiMengXiYouData & msg) const {
	for(int32_t i = 0; i < (int32_t)reward.size(); ++i) {
		::proto_ff::FestHuiMengXiYouReward* temp_reward = msg.add_reward();
		reward[i].write_to_pbmsg(*temp_reward);
	}
	msg.set_cur_points((int32_t)cur_points);
	for(int32_t i = 0; i < (int32_t)game.size(); ++i) {
		::proto_ff::FestHuiMengXiYouGame* temp_game = msg.add_game();
		game[i].write_to_pbmsg(*temp_game);
	}
	msg.set_prestige((int32_t)prestige);
	msg.set_flush_time((uint64_t)flush_time);
	msg.set_cur_game_id((int32_t)cur_game_id);
}

void FestHuiMengXiYouData_s::read_from_pbmsg(const ::proto_ff::FestHuiMengXiYouData & msg) {
	reward.resize((int)msg.reward_size() > (int)reward.max_size() ? reward.max_size() : msg.reward_size());
	for(int32_t i = 0; i < (int32_t)reward.size(); ++i) {
		const ::proto_ff::FestHuiMengXiYouReward & temp_reward = msg.reward(i);
		reward[i].read_from_pbmsg(temp_reward);
	}
	cur_points = msg.cur_points();
	game.resize((int)msg.game_size() > (int)game.max_size() ? game.max_size() : msg.game_size());
	for(int32_t i = 0; i < (int32_t)game.size(); ++i) {
		const ::proto_ff::FestHuiMengXiYouGame & temp_game = msg.game(i);
		game[i].read_from_pbmsg(temp_game);
	}
	prestige = msg.prestige();
	flush_time = msg.flush_time();
	cur_game_id = msg.cur_game_id();
}

GHostDupRankInfo_s::GHostDupRankInfo_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int GHostDupRankInfo_s::CreateInit() {
	rank = (int32_t)0;
	cid = (uint64_t)0;
	wave = (int32_t)0;
	time = (int32_t)0;
	update_time = (uint64_t)0;
	return 0;
}

int GHostDupRankInfo_s::ResumeInit() {
	return 0;
}

void GHostDupRankInfo_s::write_to_pbmsg(::proto_ff::GHostDupRankInfo & msg) const {
	msg.set_rank((int32_t)rank);
	msg.set_name(name.data());
	msg.set_cid((uint64_t)cid);
	msg.set_wave((int32_t)wave);
	msg.set_time((int32_t)time);
	msg.set_update_time((uint64_t)update_time);
}

void GHostDupRankInfo_s::read_from_pbmsg(const ::proto_ff::GHostDupRankInfo & msg) {
	rank = msg.rank();
	name = msg.name();
	cid = msg.cid();
	wave = msg.wave();
	time = msg.time();
	update_time = msg.update_time();
}

StarFantasyData_s::StarFantasyData_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int StarFantasyData_s::CreateInit() {
	id = (uint32_t)0;
	status = (uint32_t)0;
	level = (uint32_t)0;
	advance_level = (uint32_t)0;
	return 0;
}

int StarFantasyData_s::ResumeInit() {
	return 0;
}

void StarFantasyData_s::write_to_pbmsg(::proto_ff::StarFantasyData & msg) const {
	msg.set_id((uint32_t)id);
	msg.set_status((uint32_t)status);
	msg.set_level((uint32_t)level);
	msg.set_advance_level((uint32_t)advance_level);
}

void StarFantasyData_s::read_from_pbmsg(const ::proto_ff::StarFantasyData & msg) {
	id = msg.id();
	status = msg.status();
	level = msg.level();
	advance_level = msg.advance_level();
}

StarSetupHoleData_s::StarSetupHoleData_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int StarSetupHoleData_s::CreateInit() {
	id = (uint32_t)0;
	score = (uint64_t)0;
	return 0;
}

int StarSetupHoleData_s::ResumeInit() {
	return 0;
}

void StarSetupHoleData_s::write_to_pbmsg(::proto_ff::StarSetupHoleData & msg) const {
	::proto_ff::EquipInfo* temp_equip_info = msg.mutable_equip_info();
	equip_info.write_to_pbmsg(*temp_equip_info);
	msg.set_id((uint32_t)id);
	msg.set_score((uint64_t)score);
}

void StarSetupHoleData_s::read_from_pbmsg(const ::proto_ff::StarSetupHoleData & msg) {
	const ::proto_ff::EquipInfo & temp_equip_info = msg.equip_info();
	equip_info.read_from_pbmsg(temp_equip_info);
	id = msg.id();
	score = msg.score();
}

StarSetupStarAttrData_s::StarSetupStarAttrData_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int StarSetupStarAttrData_s::CreateInit() {
	id = (uint32_t)0;
	status = (uint32_t)0;
	return 0;
}

int StarSetupStarAttrData_s::ResumeInit() {
	return 0;
}

void StarSetupStarAttrData_s::write_to_pbmsg(::proto_ff::StarSetupStarAttrData & msg) const {
	msg.set_id((uint32_t)id);
	msg.set_status((uint32_t)status);
}

void StarSetupStarAttrData_s::read_from_pbmsg(const ::proto_ff::StarSetupStarAttrData & msg) {
	id = msg.id();
	status = msg.status();
}

StarSetupData_s::StarSetupData_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int StarSetupData_s::CreateInit() {
	id = (uint32_t)0;
	status = (uint32_t)0;
	unlock_time = (uint64_t)0;
	guizhen_id = (uint32_t)0;
	guizhen_status = (uint32_t)0;
	star_num = (uint32_t)0;
	return 0;
}

int StarSetupData_s::ResumeInit() {
	return 0;
}

void StarSetupData_s::write_to_pbmsg(::proto_ff::StarSetupData & msg) const {
	msg.set_id((uint32_t)id);
	msg.set_status((uint32_t)status);
	msg.set_unlock_time((uint64_t)unlock_time);
	for(int32_t i = 0; i < (int32_t)hole_data.size(); ++i) {
		::proto_ff::StarSetupHoleData* temp_hole_data = msg.add_hole_data();
		hole_data[i].write_to_pbmsg(*temp_hole_data);
	}
	msg.set_guizhen_id((uint32_t)guizhen_id);
	msg.set_guizhen_status((uint32_t)guizhen_status);
	msg.set_star_num((uint32_t)star_num);
	for(int32_t i = 0; i < (int32_t)star_attr.size(); ++i) {
		::proto_ff::StarSetupStarAttrData* temp_star_attr = msg.add_star_attr();
		star_attr[i].write_to_pbmsg(*temp_star_attr);
	}
}

void StarSetupData_s::read_from_pbmsg(const ::proto_ff::StarSetupData & msg) {
	id = msg.id();
	status = msg.status();
	unlock_time = msg.unlock_time();
	hole_data.resize((int)msg.hole_data_size() > (int)hole_data.max_size() ? hole_data.max_size() : msg.hole_data_size());
	for(int32_t i = 0; i < (int32_t)hole_data.size(); ++i) {
		const ::proto_ff::StarSetupHoleData & temp_hole_data = msg.hole_data(i);
		hole_data[i].read_from_pbmsg(temp_hole_data);
	}
	guizhen_id = msg.guizhen_id();
	guizhen_status = msg.guizhen_status();
	star_num = msg.star_num();
	star_attr.resize((int)msg.star_attr_size() > (int)star_attr.max_size() ? star_attr.max_size() : msg.star_attr_size());
	for(int32_t i = 0; i < (int32_t)star_attr.size(); ++i) {
		const ::proto_ff::StarSetupStarAttrData & temp_star_attr = msg.star_attr(i);
		star_attr[i].read_from_pbmsg(temp_star_attr);
	}
}

StarSkillData_s::StarSkillData_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int StarSkillData_s::CreateInit() {
	id = (uint32_t)0;
	level = (uint32_t)0;
	finish = (bool)0;
	return 0;
}

int StarSkillData_s::ResumeInit() {
	return 0;
}

void StarSkillData_s::write_to_pbmsg(::proto_ff::StarSkillData & msg) const {
	msg.set_id((uint32_t)id);
	msg.set_level((uint32_t)level);
	msg.set_finish((bool)finish);
}

void StarSkillData_s::read_from_pbmsg(const ::proto_ff::StarSkillData & msg) {
	id = msg.id();
	level = msg.level();
	finish = msg.finish();
}

StarSkillSlotData_s::StarSkillSlotData_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int StarSkillSlotData_s::CreateInit() {
	slot_id = (uint32_t)0;
	status = (uint32_t)0;
	cur_id = (uint32_t)0;
	cur_end_time = (uint32_t)0;
	return 0;
}

int StarSkillSlotData_s::ResumeInit() {
	return 0;
}

void StarSkillSlotData_s::write_to_pbmsg(::proto_ff::StarSkillSlotData & msg) const {
	msg.set_slot_id((uint32_t)slot_id);
	msg.set_status((uint32_t)status);
	msg.set_cur_id((uint32_t)cur_id);
	msg.set_cur_end_time((uint32_t)cur_end_time);
}

void StarSkillSlotData_s::read_from_pbmsg(const ::proto_ff::StarSkillSlotData & msg) {
	slot_id = msg.slot_id();
	status = msg.status();
	cur_id = msg.cur_id();
	cur_end_time = msg.cur_end_time();
}

StarShopData_s::StarShopData_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int StarShopData_s::CreateInit() {
	id = (uint32_t)0;
	buy_num = (uint32_t)0;
	return 0;
}

int StarShopData_s::ResumeInit() {
	return 0;
}

void StarShopData_s::write_to_pbmsg(::proto_ff::StarShopData & msg) const {
	msg.set_id((uint32_t)id);
	msg.set_buy_num((uint32_t)buy_num);
}

void StarShopData_s::read_from_pbmsg(const ::proto_ff::StarShopData & msg) {
	id = msg.id();
	buy_num = msg.buy_num();
}

StarData_s::StarData_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int StarData_s::CreateInit() {
	cur_fantasy_id = (uint32_t)0;
	last_shop_refresh_time = (uint64_t)0;
	return 0;
}

int StarData_s::ResumeInit() {
	return 0;
}

void StarData_s::write_to_pbmsg(::proto_ff::StarData & msg) const {
	for(int32_t i = 0; i < (int32_t)setup_data.size(); ++i) {
		::proto_ff::StarSetupData* temp_setup_data = msg.add_setup_data();
		setup_data[i].write_to_pbmsg(*temp_setup_data);
	}
	for(int32_t i = 0; i < (int32_t)fantasy_data.size(); ++i) {
		::proto_ff::StarFantasyData* temp_fantasy_data = msg.add_fantasy_data();
		fantasy_data[i].write_to_pbmsg(*temp_fantasy_data);
	}
	msg.set_cur_fantasy_id((uint32_t)cur_fantasy_id);
	for(int32_t i = 0; i < (int32_t)skill_data.size(); ++i) {
		::proto_ff::StarSkillData* temp_skill_data = msg.add_skill_data();
		skill_data[i].write_to_pbmsg(*temp_skill_data);
	}
	for(int32_t i = 0; i < (int32_t)skill_slot_data.size(); ++i) {
		::proto_ff::StarSkillSlotData* temp_skill_slot_data = msg.add_skill_slot_data();
		skill_slot_data[i].write_to_pbmsg(*temp_skill_slot_data);
	}
	for(int32_t i = 0; i < (int32_t)shop_data.size(); ++i) {
		::proto_ff::StarShopData* temp_shop_data = msg.add_shop_data();
		shop_data[i].write_to_pbmsg(*temp_shop_data);
	}
	msg.set_last_shop_refresh_time((uint64_t)last_shop_refresh_time);
}

void StarData_s::read_from_pbmsg(const ::proto_ff::StarData & msg) {
	setup_data.resize((int)msg.setup_data_size() > (int)setup_data.max_size() ? setup_data.max_size() : msg.setup_data_size());
	for(int32_t i = 0; i < (int32_t)setup_data.size(); ++i) {
		const ::proto_ff::StarSetupData & temp_setup_data = msg.setup_data(i);
		setup_data[i].read_from_pbmsg(temp_setup_data);
	}
	fantasy_data.resize((int)msg.fantasy_data_size() > (int)fantasy_data.max_size() ? fantasy_data.max_size() : msg.fantasy_data_size());
	for(int32_t i = 0; i < (int32_t)fantasy_data.size(); ++i) {
		const ::proto_ff::StarFantasyData & temp_fantasy_data = msg.fantasy_data(i);
		fantasy_data[i].read_from_pbmsg(temp_fantasy_data);
	}
	cur_fantasy_id = msg.cur_fantasy_id();
	skill_data.resize((int)msg.skill_data_size() > (int)skill_data.max_size() ? skill_data.max_size() : msg.skill_data_size());
	for(int32_t i = 0; i < (int32_t)skill_data.size(); ++i) {
		const ::proto_ff::StarSkillData & temp_skill_data = msg.skill_data(i);
		skill_data[i].read_from_pbmsg(temp_skill_data);
	}
	skill_slot_data.resize((int)msg.skill_slot_data_size() > (int)skill_slot_data.max_size() ? skill_slot_data.max_size() : msg.skill_slot_data_size());
	for(int32_t i = 0; i < (int32_t)skill_slot_data.size(); ++i) {
		const ::proto_ff::StarSkillSlotData & temp_skill_slot_data = msg.skill_slot_data(i);
		skill_slot_data[i].read_from_pbmsg(temp_skill_slot_data);
	}
	shop_data.resize((int)msg.shop_data_size() > (int)shop_data.max_size() ? shop_data.max_size() : msg.shop_data_size());
	for(int32_t i = 0; i < (int32_t)shop_data.size(); ++i) {
		const ::proto_ff::StarShopData & temp_shop_data = msg.shop_data(i);
		shop_data[i].read_from_pbmsg(temp_shop_data);
	}
	last_shop_refresh_time = msg.last_shop_refresh_time();
}

TurnSlot_s::TurnSlot_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int TurnSlot_s::CreateInit() {
	stronglv = (int32_t)0;
	return 0;
}

int TurnSlot_s::ResumeInit() {
	return 0;
}

void TurnSlot_s::write_to_pbmsg(::proto_ff::TurnSlot & msg) const {
	msg.set_stronglv((int32_t)stronglv);
}

void TurnSlot_s::read_from_pbmsg(const ::proto_ff::TurnSlot & msg) {
	stronglv = msg.stronglv();
}

TurnGrow_s::TurnGrow_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int TurnGrow_s::CreateInit() {
	pos = (int32_t)0;
	return 0;
}

int TurnGrow_s::ResumeInit() {
	return 0;
}

void TurnGrow_s::write_to_pbmsg(::proto_ff::TurnGrow & msg) const {
	msg.set_pos((int32_t)pos);
	::proto_ff::ItemProtoInfo* temp_equip = msg.mutable_equip();
	equip.write_to_pbmsg(*temp_equip);
	::proto_ff::TurnSlot* temp_slot = msg.mutable_slot();
	slot.write_to_pbmsg(*temp_slot);
}

void TurnGrow_s::read_from_pbmsg(const ::proto_ff::TurnGrow & msg) {
	pos = msg.pos();
	const ::proto_ff::ItemProtoInfo & temp_equip = msg.equip();
	equip.read_from_pbmsg(temp_equip);
	const ::proto_ff::TurnSlot & temp_slot = msg.slot();
	slot.read_from_pbmsg(temp_slot);
}

TurnEntry_s::TurnEntry_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int TurnEntry_s::CreateInit() {
	lv = (int32_t)0;
	return 0;
}

int TurnEntry_s::ResumeInit() {
	return 0;
}

void TurnEntry_s::write_to_pbmsg(::proto_ff::TurnEntry & msg) const {
	msg.set_lv((int32_t)lv);
	for(int32_t i = 0; i < (int32_t)infos.size(); ++i) {
		::proto_ff::TurnGrow* temp_infos = msg.add_infos();
		infos[i].write_to_pbmsg(*temp_infos);
	}
	for(int32_t i = 0; i < (int32_t)strong_ids.size(); ++i) {
		msg.add_strong_ids((int32_t)strong_ids[i]);
	}
}

void TurnEntry_s::read_from_pbmsg(const ::proto_ff::TurnEntry & msg) {
	lv = msg.lv();
	infos.resize((int)msg.infos_size() > (int)infos.max_size() ? infos.max_size() : msg.infos_size());
	for(int32_t i = 0; i < (int32_t)infos.size(); ++i) {
		const ::proto_ff::TurnGrow & temp_infos = msg.infos(i);
		infos[i].read_from_pbmsg(temp_infos);
	}
	strong_ids.resize((int)msg.strong_ids_size() > (int)strong_ids.max_size() ? strong_ids.max_size() : msg.strong_ids_size());
	for(int32_t i = 0; i < (int32_t)strong_ids.size(); ++i) {
		strong_ids[i] = msg.strong_ids(i);
	}
}

TurnSimple_s::TurnSimple_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int TurnSimple_s::CreateInit() {
	turn_lv = (int32_t)0;
	cur_lv = (int32_t)0;
	cur_exp = (uint64_t)0;
	failed_add = (int32_t)0;
	day_turn_num = (int32_t)0;
	active_all_star_id = (int32_t)0;
	return 0;
}

int TurnSimple_s::ResumeInit() {
	return 0;
}

void TurnSimple_s::write_to_pbmsg(::proto_ff::TurnSimple & msg) const {
	msg.set_turn_lv((int32_t)turn_lv);
	msg.set_cur_lv((int32_t)cur_lv);
	msg.set_cur_exp((uint64_t)cur_exp);
	msg.set_failed_add((int32_t)failed_add);
	msg.set_day_turn_num((int32_t)day_turn_num);
	msg.set_active_all_star_id((int32_t)active_all_star_id);
}

void TurnSimple_s::read_from_pbmsg(const ::proto_ff::TurnSimple & msg) {
	turn_lv = msg.turn_lv();
	cur_lv = msg.cur_lv();
	cur_exp = msg.cur_exp();
	failed_add = msg.failed_add();
	day_turn_num = msg.day_turn_num();
	active_all_star_id = msg.active_all_star_id();
}

TurnHelper_s::TurnHelper_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int TurnHelper_s::CreateInit() {
	cid = (uint64_t)0;
	time = (uint64_t)0;
	return 0;
}

int TurnHelper_s::ResumeInit() {
	return 0;
}

void TurnHelper_s::write_to_pbmsg(::proto_ff::TurnHelper & msg) const {
	msg.set_cid((uint64_t)cid);
	msg.set_name(name.data());
	msg.set_time((uint64_t)time);
}

void TurnHelper_s::read_from_pbmsg(const ::proto_ff::TurnHelper & msg) {
	cid = msg.cid();
	name = msg.name();
	time = msg.time();
}

TurnTask_s::TurnTask_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int TurnTask_s::CreateInit() {
	id = (int32_t)0;
	state = (int32_t)0;
	return 0;
}

int TurnTask_s::ResumeInit() {
	return 0;
}

void TurnTask_s::write_to_pbmsg(::proto_ff::TurnTask & msg) const {
	msg.set_id((int32_t)id);
	msg.set_state((int32_t)state);
}

void TurnTask_s::read_from_pbmsg(const ::proto_ff::TurnTask & msg) {
	id = msg.id();
	state = msg.state();
}

FMarryTask_s::FMarryTask_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int FMarryTask_s::CreateInit() {
	id = (int32_t)0;
	val = (int32_t)0;
	state = (int32_t)0;
	return 0;
}

int FMarryTask_s::ResumeInit() {
	return 0;
}

void FMarryTask_s::write_to_pbmsg(::proto_ff::FMarryTask & msg) const {
	msg.set_id((int32_t)id);
	msg.set_val((int32_t)val);
	msg.set_state((int32_t)state);
}

void FMarryTask_s::read_from_pbmsg(const ::proto_ff::FMarryTask & msg) {
	id = msg.id();
	val = msg.val();
	state = msg.state();
}

SoulEntry_s::SoulEntry_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int SoulEntry_s::CreateInit() {
	id = (int32_t)0;
	lv = (int32_t)0;
	steplv = (int32_t)0;
	return 0;
}

int SoulEntry_s::ResumeInit() {
	return 0;
}

void SoulEntry_s::write_to_pbmsg(::proto_ff::SoulEntry & msg) const {
	msg.set_id((int32_t)id);
	msg.set_lv((int32_t)lv);
	msg.set_steplv((int32_t)steplv);
}

void SoulEntry_s::read_from_pbmsg(const ::proto_ff::SoulEntry & msg) {
	id = msg.id();
	lv = msg.lv();
	steplv = msg.steplv();
}

SoulPool_s::SoulPool_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int SoulPool_s::CreateInit() {
	poolBlessLv = (int32_t)0;
	poolPgLv = (int32_t)0;
	return 0;
}

int SoulPool_s::ResumeInit() {
	return 0;
}

void SoulPool_s::write_to_pbmsg(::proto_ff::SoulPool & msg) const {
	msg.set_poolblesslv((int32_t)poolBlessLv);
	msg.set_poolpglv((int32_t)poolPgLv);
}

void SoulPool_s::read_from_pbmsg(const ::proto_ff::SoulPool & msg) {
	poolBlessLv = msg.poolblesslv();
	poolPgLv = msg.poolpglv();
}

}
