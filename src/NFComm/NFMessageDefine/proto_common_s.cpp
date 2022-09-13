#include "proto_common_s.h"

namespace proto_ff_s {

GameServerRoomInfo_s::GameServerRoomInfo_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int GameServerRoomInfo_s::CreateInit() {
	game_id = (uint32_t)0;
	room_id = (uint32_t)0;
	enter_min = (uint64_t)0;
	enter_max = (uint64_t)0;
	online_count = (uint32_t)0;
	bus_id = (uint32_t)0;
	status = (uint32_t)0;
	return 0;
}

int GameServerRoomInfo_s::ResumeInit() {
	return 0;
}

void GameServerRoomInfo_s::write_to_pbmsg(const struct GameServerRoomInfo_s & obj, ::proto_ff::GameServerRoomInfo & msg) {
	msg.set_game_id((uint32_t)obj.game_id);
	msg.set_room_id((uint32_t)obj.room_id);
	msg.set_room_name((const char*)obj.room_name.Get());
	msg.set_enter_min((uint64_t)obj.enter_min);
	msg.set_enter_max((uint64_t)obj.enter_max);
	msg.set_online_count((uint32_t)obj.online_count);
	msg.set_bus_id((uint32_t)obj.bus_id);
	msg.set_status((uint32_t)obj.status);
}

void GameServerRoomInfo_s::read_from_pbmsg(const ::proto_ff::GameServerRoomInfo & msg, struct GameServerRoomInfo_s & obj) {
	memset(&obj, 0, sizeof(struct GameServerRoomInfo_s));
	obj.game_id = msg.game_id();
	obj.room_id = msg.room_id();
	obj.room_name.Copy(msg.room_name());
	obj.enter_min = msg.enter_min();
	obj.enter_max = msg.enter_max();
	obj.online_count = msg.online_count();
	obj.bus_id = msg.bus_id();
	obj.status = msg.status();
}

tbServerMgr_s::tbServerMgr_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int tbServerMgr_s::CreateInit() {
	id = (uint64_t)0;
	cur_count = (uint32_t)0;
	last_login_time = (uint64_t)0;
	last_logout_time = (uint64_t)0;
	create_time = (uint64_t)0;
	return 0;
}

int tbServerMgr_s::ResumeInit() {
	return 0;
}

void tbServerMgr_s::write_to_pbmsg(const struct tbServerMgr_s & obj, ::proto_ff::tbServerMgr & msg) {
	msg.set_id((uint64_t)obj.id);
	msg.set_contract((const char*)obj.contract.Get());
	msg.set_machine_addr((const char*)obj.machine_addr.Get());
	msg.set_ip((const char*)obj.ip.Get());
	msg.set_bus_name((const char*)obj.bus_name.Get());
	msg.set_server_desc((const char*)obj.server_desc.Get());
	msg.set_cur_count((uint32_t)obj.cur_count);
	msg.set_last_login_time((uint64_t)obj.last_login_time);
	msg.set_last_logout_time((uint64_t)obj.last_logout_time);
	msg.set_create_time((uint64_t)obj.create_time);
}

void tbServerMgr_s::read_from_pbmsg(const ::proto_ff::tbServerMgr & msg, struct tbServerMgr_s & obj) {
	memset(&obj, 0, sizeof(struct tbServerMgr_s));
	obj.id = msg.id();
	obj.contract.Copy(msg.contract());
	obj.machine_addr.Copy(msg.machine_addr());
	obj.ip.Copy(msg.ip());
	obj.bus_name.Copy(msg.bus_name());
	obj.server_desc.Copy(msg.server_desc());
	obj.cur_count = msg.cur_count();
	obj.last_login_time = msg.last_login_time();
	obj.last_logout_time = msg.last_logout_time();
	obj.create_time = msg.create_time();
}

tbContractMgr_s::tbContractMgr_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int tbContractMgr_s::CreateInit() {
	id = (uint64_t)0;
	return 0;
}

int tbContractMgr_s::ResumeInit() {
	return 0;
}

void tbContractMgr_s::write_to_pbmsg(const struct tbContractMgr_s & obj, ::proto_ff::tbContractMgr & msg) {
	msg.set_id((uint64_t)obj.id);
	msg.set_contract((const char*)obj.contract.Get());
	msg.set_machine_addr((const char*)obj.machine_addr.Get());
	msg.set_ip((const char*)obj.ip.Get());
	msg.set_server_desc((const char*)obj.server_desc.Get());
}

void tbContractMgr_s::read_from_pbmsg(const ::proto_ff::tbContractMgr & msg, struct tbContractMgr_s & obj) {
	memset(&obj, 0, sizeof(struct tbContractMgr_s));
	obj.id = msg.id();
	obj.contract.Copy(msg.contract());
	obj.machine_addr.Copy(msg.machine_addr());
	obj.ip.Copy(msg.ip());
	obj.server_desc.Copy(msg.server_desc());
}

tbAccountTable_s::tbAccountTable_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int tbAccountTable_s::CreateInit() {
	player_id = (uint64_t)0;
	account_type = (uint32_t)0;
	phonenum = (uint64_t)0;
	real_player_id = (uint64_t)0;
	return 0;
}

int tbAccountTable_s::ResumeInit() {
	return 0;
}

void tbAccountTable_s::write_to_pbmsg(const struct tbAccountTable_s & obj, ::proto_ff::tbAccountTable & msg) {
	msg.set_player_id((uint64_t)obj.player_id);
	msg.set_account((const char*)obj.account.Get());
	msg.set_password((const char*)obj.password.Get());
	msg.set_account_type((uint32_t)obj.account_type);
	msg.set_device_id((const char*)obj.device_id.Get());
	msg.set_phonenum((uint64_t)obj.phonenum);
	msg.set_real_player_id((uint64_t)obj.real_player_id);
}

void tbAccountTable_s::read_from_pbmsg(const ::proto_ff::tbAccountTable & msg, struct tbAccountTable_s & obj) {
	memset(&obj, 0, sizeof(struct tbAccountTable_s));
	obj.player_id = msg.player_id();
	obj.account.Copy(msg.account());
	obj.password.Copy(msg.password());
	obj.account_type = msg.account_type();
	obj.device_id.Copy(msg.device_id());
	obj.phonenum = msg.phonenum();
	obj.real_player_id = msg.real_player_id();
}

ItemData_s::ItemData_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int ItemData_s::CreateInit() {
	item_id = (int32_t)0;
	item_num = (int32_t)0;
	return 0;
}

int ItemData_s::ResumeInit() {
	return 0;
}

void ItemData_s::write_to_pbmsg(const struct ItemData_s & obj, ::proto_ff::ItemData & msg) {
	msg.set_item_id((int32_t)obj.item_id);
	msg.set_item_num((int32_t)obj.item_num);
}

void ItemData_s::read_from_pbmsg(const ::proto_ff::ItemData & msg, struct ItemData_s & obj) {
	memset(&obj, 0, sizeof(struct ItemData_s));
	obj.item_id = msg.item_id();
	obj.item_num = msg.item_num();
}

SingleMailInfo_s::SingleMailInfo_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int SingleMailInfo_s::CreateInit() {
	id = (uint64_t)0;
	status = (uint32_t)0;
	return 0;
}

int SingleMailInfo_s::ResumeInit() {
	return 0;
}

void SingleMailInfo_s::write_to_pbmsg(const struct SingleMailInfo_s & obj, ::proto_ff::SingleMailInfo & msg) {
	msg.set_id((uint64_t)obj.id);
	msg.set_status((uint32_t)obj.status);
}

void SingleMailInfo_s::read_from_pbmsg(const ::proto_ff::SingleMailInfo & msg, struct SingleMailInfo_s & obj) {
	memset(&obj, 0, sizeof(struct SingleMailInfo_s));
	obj.id = msg.id();
	obj.status = msg.status();
}

UserSpecialMailData_s::UserSpecialMailData_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int UserSpecialMailData_s::CreateInit() {
	static_id = (int32_t)0;
	time = (uint64_t)0;
	return 0;
}

int UserSpecialMailData_s::ResumeInit() {
	return 0;
}

void UserSpecialMailData_s::write_to_pbmsg(const struct UserSpecialMailData_s & obj, ::proto_ff::UserSpecialMailData & msg) {
	msg.set_static_id((int32_t)obj.static_id);
	msg.set_time((uint64_t)obj.time);
}

void UserSpecialMailData_s::read_from_pbmsg(const ::proto_ff::UserSpecialMailData & msg, struct UserSpecialMailData_s & obj) {
	memset(&obj, 0, sizeof(struct UserSpecialMailData_s));
	obj.static_id = msg.static_id();
	obj.time = msg.time();
}

UserMailInfo_s::UserMailInfo_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int UserMailInfo_s::CreateInit() {
	return 0;
}

int UserMailInfo_s::ResumeInit() {
	return 0;
}

void UserMailInfo_s::write_to_pbmsg(const struct UserMailInfo_s & obj, ::proto_ff::UserMailInfo & msg) {
	for(int32_t i = 0; i < obj.simple_mail.GetSize() && i < obj.simple_mail.GetMaxSize(); ++i) {
		::proto_ff::SingleMailInfo* temp_simple_mail = msg.add_simple_mail();
		SingleMailInfo_s::write_to_pbmsg(obj.simple_mail[i], *temp_simple_mail);
	}
	for(int32_t i = 0; i < obj.receive_data.GetSize() && i < obj.receive_data.GetMaxSize(); ++i) {
		::proto_ff::UserSpecialMailData* temp_receive_data = msg.add_receive_data();
		UserSpecialMailData_s::write_to_pbmsg(obj.receive_data[i], *temp_receive_data);
	}
	for(int32_t i = 0; i < obj.del_role_mail.GetSize() && i < obj.del_role_mail.GetMaxSize(); ++i) {
		msg.add_del_role_mail((uint64_t)obj.del_role_mail[i]);
	}
}

void UserMailInfo_s::read_from_pbmsg(const ::proto_ff::UserMailInfo & msg, struct UserMailInfo_s & obj) {
	memset(&obj, 0, sizeof(struct UserMailInfo_s));
	obj.simple_mail.SetSize(msg.simple_mail_size() > obj.simple_mail.GetMaxSize() ? obj.simple_mail.GetMaxSize() : msg.simple_mail_size());
	for(int32_t i = 0; i < obj.simple_mail.GetSize(); ++i) {
		const ::proto_ff::SingleMailInfo & temp_simple_mail = msg.simple_mail(i);
		SingleMailInfo_s::read_from_pbmsg(temp_simple_mail, obj.simple_mail[i]);
	}
	obj.receive_data.SetSize(msg.receive_data_size() > obj.receive_data.GetMaxSize() ? obj.receive_data.GetMaxSize() : msg.receive_data_size());
	for(int32_t i = 0; i < obj.receive_data.GetSize(); ++i) {
		const ::proto_ff::UserSpecialMailData & temp_receive_data = msg.receive_data(i);
		UserSpecialMailData_s::read_from_pbmsg(temp_receive_data, obj.receive_data[i]);
	}
	obj.del_role_mail.SetSize(msg.del_role_mail_size() > obj.del_role_mail.GetMaxSize() ? obj.del_role_mail.GetMaxSize() : msg.del_role_mail_size());
	for(int32_t i = 0; i < obj.del_role_mail.GetSize(); ++i) {
		obj.del_role_mail[i] = msg.del_role_mail(i);
	}
}

tbUserMailInfo_s::tbUserMailInfo_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int tbUserMailInfo_s::CreateInit() {
	user_id = (uint64_t)0;
	return 0;
}

int tbUserMailInfo_s::ResumeInit() {
	return 0;
}

void tbUserMailInfo_s::write_to_pbmsg(const struct tbUserMailInfo_s & obj, ::proto_ff::tbUserMailInfo & msg) {
	msg.set_user_id((uint64_t)obj.user_id);
	::proto_ff::UserMailInfo* temp_base_info = msg.mutable_base_info();
	UserMailInfo_s::write_to_pbmsg(obj.base_info, *temp_base_info);
}

void tbUserMailInfo_s::read_from_pbmsg(const ::proto_ff::tbUserMailInfo & msg, struct tbUserMailInfo_s & obj) {
	memset(&obj, 0, sizeof(struct tbUserMailInfo_s));
	obj.user_id = msg.user_id();
	const ::proto_ff::UserMailInfo & temp_base_info = msg.base_info();
	UserMailInfo_s::read_from_pbmsg(temp_base_info, obj.base_info);
}

tbUserMailDetail_s::tbUserMailDetail_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int tbUserMailDetail_s::CreateInit() {
	id = (uint64_t)0;
	user_id = (uint64_t)0;
	static_id = (int32_t)0;
	send_time = (uint64_t)0;
	add_gold = (int64_t)0;
	return 0;
}

int tbUserMailDetail_s::ResumeInit() {
	return 0;
}

void tbUserMailDetail_s::write_to_pbmsg(const struct tbUserMailDetail_s & obj, ::proto_ff::tbUserMailDetail & msg) {
	msg.set_id((uint64_t)obj.id);
	msg.set_user_id((uint64_t)obj.user_id);
	msg.set_send_name((const char*)obj.send_name.Get());
	msg.set_static_id((int32_t)obj.static_id);
	msg.set_content((const char*)obj.content.Get());
	msg.set_title((const char*)obj.title.Get());
	msg.set_send_time((uint64_t)obj.send_time);
	msg.set_add_gold((int64_t)obj.add_gold);
}

void tbUserMailDetail_s::read_from_pbmsg(const ::proto_ff::tbUserMailDetail & msg, struct tbUserMailDetail_s & obj) {
	memset(&obj, 0, sizeof(struct tbUserMailDetail_s));
	obj.id = msg.id();
	obj.user_id = msg.user_id();
	obj.send_name.Copy(msg.send_name());
	obj.static_id = msg.static_id();
	obj.content.Copy(msg.content());
	obj.title.Copy(msg.title());
	obj.send_time = msg.send_time();
	obj.add_gold = msg.add_gold();
}

UserMailDetailInfo_s::UserMailDetailInfo_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int UserMailDetailInfo_s::CreateInit() {
	return 0;
}

int UserMailDetailInfo_s::ResumeInit() {
	return 0;
}

void UserMailDetailInfo_s::write_to_pbmsg(const struct UserMailDetailInfo_s & obj, ::proto_ff::UserMailDetailInfo & msg) {
	for(int32_t i = 0; i < obj.simple_mail.GetSize() && i < obj.simple_mail.GetMaxSize(); ++i) {
		::proto_ff::tbUserMailDetail* temp_simple_mail = msg.add_simple_mail();
		tbUserMailDetail_s::write_to_pbmsg(obj.simple_mail[i], *temp_simple_mail);
	}
}

void UserMailDetailInfo_s::read_from_pbmsg(const ::proto_ff::UserMailDetailInfo & msg, struct UserMailDetailInfo_s & obj) {
	memset(&obj, 0, sizeof(struct UserMailDetailInfo_s));
	obj.simple_mail.SetSize(msg.simple_mail_size() > obj.simple_mail.GetMaxSize() ? obj.simple_mail.GetMaxSize() : msg.simple_mail_size());
	for(int32_t i = 0; i < obj.simple_mail.GetSize(); ++i) {
		const ::proto_ff::tbUserMailDetail & temp_simple_mail = msg.simple_mail(i);
		tbUserMailDetail_s::read_from_pbmsg(temp_simple_mail, obj.simple_mail[i]);
	}
}

tbGiveBankJetton_s::tbGiveBankJetton_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int tbGiveBankJetton_s::CreateInit() {
	id = (uint64_t)0;
	user_id = (uint64_t)0;
	user_vip_level = (uint64_t)0;
	give_user_id = (uint64_t)0;
	give_jetton = (uint64_t)0;
	give_user_vip_level = (uint32_t)0;
	status = (uint32_t)0;
	create_time = (uint64_t)0;
	return 0;
}

int tbGiveBankJetton_s::ResumeInit() {
	return 0;
}

void tbGiveBankJetton_s::write_to_pbmsg(const struct tbGiveBankJetton_s & obj, ::proto_ff::tbGiveBankJetton & msg) {
	msg.set_id((uint64_t)obj.id);
	msg.set_user_id((uint64_t)obj.user_id);
	msg.set_user_name((const char*)obj.user_name.Get());
	msg.set_user_vip_level((uint64_t)obj.user_vip_level);
	msg.set_give_user_id((uint64_t)obj.give_user_id);
	msg.set_give_user_name((const char*)obj.give_user_name.Get());
	msg.set_give_jetton((uint64_t)obj.give_jetton);
	msg.set_give_user_vip_level((uint32_t)obj.give_user_vip_level);
	msg.set_status((uint32_t)obj.status);
	msg.set_create_time((uint64_t)obj.create_time);
}

void tbGiveBankJetton_s::read_from_pbmsg(const ::proto_ff::tbGiveBankJetton & msg, struct tbGiveBankJetton_s & obj) {
	memset(&obj, 0, sizeof(struct tbGiveBankJetton_s));
	obj.id = msg.id();
	obj.user_id = msg.user_id();
	obj.user_name.Copy(msg.user_name());
	obj.user_vip_level = msg.user_vip_level();
	obj.give_user_id = msg.give_user_id();
	obj.give_user_name.Copy(msg.give_user_name());
	obj.give_jetton = msg.give_jetton();
	obj.give_user_vip_level = msg.give_user_vip_level();
	obj.status = msg.status();
	obj.create_time = msg.create_time();
}

UserMiscData_s::UserMiscData_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int UserMiscData_s::CreateInit() {
	tmp_phone_num = (uint64_t)0;
	tmp_auth_code = (uint32_t)0;
	auth_code_stamp = (uint64_t)0;
	tmp_code_type = (int32_t)0;
	tmp_code_success = (bool)0;
	tmp_redeemcard_recharge_count = (int32_t)0;
	return 0;
}

int UserMiscData_s::ResumeInit() {
	return 0;
}

void UserMiscData_s::write_to_pbmsg(const struct UserMiscData_s & obj, ::proto_ff::UserMiscData & msg) {
	msg.set_tmp_phone_num((uint64_t)obj.tmp_phone_num);
	msg.set_tmp_auth_code((uint32_t)obj.tmp_auth_code);
	msg.set_auth_code_stamp((uint64_t)obj.auth_code_stamp);
	msg.set_tmp_code_type((int32_t)obj.tmp_code_type);
	msg.set_tmp_code_success((bool)obj.tmp_code_success);
	msg.set_tmp_redeemcard_recharge_count((int32_t)obj.tmp_redeemcard_recharge_count);
}

void UserMiscData_s::read_from_pbmsg(const ::proto_ff::UserMiscData & msg, struct UserMiscData_s & obj) {
	memset(&obj, 0, sizeof(struct UserMiscData_s));
	obj.tmp_phone_num = msg.tmp_phone_num();
	obj.tmp_auth_code = msg.tmp_auth_code();
	obj.auth_code_stamp = msg.auth_code_stamp();
	obj.tmp_code_type = msg.tmp_code_type();
	obj.tmp_code_success = msg.tmp_code_success();
	obj.tmp_redeemcard_recharge_count = msg.tmp_redeemcard_recharge_count();
}

tbUserDetailData_s::tbUserDetailData_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int tbUserDetailData_s::CreateInit() {
	userid = (uint64_t)0;
	faceid = (uint32_t)0;
	regdate = (uint64_t)0;
	gender = (uint32_t)0;
	age = (uint32_t)0;
	phonenum = (uint64_t)0;
	jetton = (uint64_t)0;
	isrobot = (bool)0;
	bank_jetton = (uint64_t)0;
	last_login_time = (uint64_t)0;
	last_logout_time = (uint64_t)0;
	aread_id = (uint32_t)0;
	channel_id = (uint32_t)0;
	first_recharge = (bool)0;
	agent_id = (uint64_t)0;
	referrer_id = (uint64_t)0;
	vip_level = (uint32_t)0;
	online = (bool)0;
	game_id = (uint32_t)0;
	room_id = (uint32_t)0;
	all_win = (int64_t)0;
	all_recharge = (uint64_t)0;
	all_give = (uint64_t)0;
	all_draw = (uint64_t)0;
	today_win = (int64_t)0;
	today_recharge = (uint64_t)0;
	today_give = (uint64_t)0;
	today_draw = (uint64_t)0;
	week_win = (int64_t)0;
	week_recharge = (uint64_t)0;
	week_give = (uint64_t)0;
	week_draw = (uint64_t)0;
	month_win = (int64_t)0;
	month_recharge = (uint64_t)0;
	month_give = (uint64_t)0;
	month_draw = (uint64_t)0;
	is_ban = (uint32_t)0;
	no_transfer = (uint32_t)0;
	show_userid = (uint64_t)0;
	all_vip_zhuanru = (uint64_t)0;
	today_vip_zhuanru = (uint64_t)0;
	week_vip_zhuanru = (uint64_t)0;
	month_vip_zhuanru = (uint64_t)0;
	all_vip_zhuanchu = (uint64_t)0;
	today_vip_zhuanchu = (uint64_t)0;
	week_vip_zhuanchu = (uint64_t)0;
	month_vip_zhuanchu = (uint64_t)0;
	return 0;
}

int tbUserDetailData_s::ResumeInit() {
	return 0;
}

void tbUserDetailData_s::write_to_pbmsg(const struct tbUserDetailData_s & obj, ::proto_ff::tbUserDetailData & msg) {
	msg.set_userid((uint64_t)obj.userid);
	msg.set_nickname((const char*)obj.nickname.Get());
	msg.set_faceid((uint32_t)obj.faceid);
	msg.set_regdate((uint64_t)obj.regdate);
	msg.set_gender((uint32_t)obj.gender);
	msg.set_age((uint32_t)obj.age);
	msg.set_email((const char*)obj.email.Get());
	msg.set_phonenum((uint64_t)obj.phonenum);
	msg.set_jetton((uint64_t)obj.jetton);
	msg.set_country((const char*)obj.country.Get());
	msg.set_province((const char*)obj.province.Get());
	msg.set_city((const char*)obj.city.Get());
	msg.set_isrobot((bool)obj.isrobot);
	msg.set_bank_password((const char*)obj.bank_password.Get());
	msg.set_bank_jetton((uint64_t)obj.bank_jetton);
	msg.set_ip((const char*)obj.ip.Get());
	msg.set_last_login_time((uint64_t)obj.last_login_time);
	msg.set_last_logout_time((uint64_t)obj.last_logout_time);
	msg.set_aread_id((uint32_t)obj.aread_id);
	msg.set_channel_id((uint32_t)obj.channel_id);
	msg.set_platform_os((const char*)obj.platform_os.Get());
	msg.set_phone_model((const char*)obj.phone_model.Get());
	msg.set_first_recharge((bool)obj.first_recharge);
	msg.set_agent_id((uint64_t)obj.agent_id);
	msg.set_referrer_id((uint64_t)obj.referrer_id);
	msg.set_vip_level((uint32_t)obj.vip_level);
	::proto_ff::UserMiscData* temp_misc_data = msg.mutable_misc_data();
	UserMiscData_s::write_to_pbmsg(obj.misc_data, *temp_misc_data);
	msg.set_online((bool)obj.online);
	msg.set_game_id((uint32_t)obj.game_id);
	msg.set_room_id((uint32_t)obj.room_id);
	msg.set_all_win((int64_t)obj.all_win);
	msg.set_all_recharge((uint64_t)obj.all_recharge);
	msg.set_all_give((uint64_t)obj.all_give);
	msg.set_all_draw((uint64_t)obj.all_draw);
	msg.set_today_win((int64_t)obj.today_win);
	msg.set_today_recharge((uint64_t)obj.today_recharge);
	msg.set_today_give((uint64_t)obj.today_give);
	msg.set_today_draw((uint64_t)obj.today_draw);
	msg.set_week_win((int64_t)obj.week_win);
	msg.set_week_recharge((uint64_t)obj.week_recharge);
	msg.set_week_give((uint64_t)obj.week_give);
	msg.set_week_draw((uint64_t)obj.week_draw);
	msg.set_month_win((int64_t)obj.month_win);
	msg.set_month_recharge((uint64_t)obj.month_recharge);
	msg.set_month_give((uint64_t)obj.month_give);
	msg.set_month_draw((uint64_t)obj.month_draw);
	msg.set_is_ban((uint32_t)obj.is_ban);
	msg.set_no_transfer((uint32_t)obj.no_transfer);
	msg.set_reg_ip((const char*)obj.reg_ip.Get());
	msg.set_device_id((const char*)obj.device_id.Get());
	msg.set_reg_device_id((const char*)obj.reg_device_id.Get());
	msg.set_show_userid((uint64_t)obj.show_userid);
	msg.set_all_vip_zhuanru((uint64_t)obj.all_vip_zhuanru);
	msg.set_today_vip_zhuanru((uint64_t)obj.today_vip_zhuanru);
	msg.set_week_vip_zhuanru((uint64_t)obj.week_vip_zhuanru);
	msg.set_month_vip_zhuanru((uint64_t)obj.month_vip_zhuanru);
	msg.set_all_vip_zhuanchu((uint64_t)obj.all_vip_zhuanchu);
	msg.set_today_vip_zhuanchu((uint64_t)obj.today_vip_zhuanchu);
	msg.set_week_vip_zhuanchu((uint64_t)obj.week_vip_zhuanchu);
	msg.set_month_vip_zhuanchu((uint64_t)obj.month_vip_zhuanchu);
}

void tbUserDetailData_s::read_from_pbmsg(const ::proto_ff::tbUserDetailData & msg, struct tbUserDetailData_s & obj) {
	memset(&obj, 0, sizeof(struct tbUserDetailData_s));
	obj.userid = msg.userid();
	obj.nickname.Copy(msg.nickname());
	obj.faceid = msg.faceid();
	obj.regdate = msg.regdate();
	obj.gender = msg.gender();
	obj.age = msg.age();
	obj.email.Copy(msg.email());
	obj.phonenum = msg.phonenum();
	obj.jetton = msg.jetton();
	obj.country.Copy(msg.country());
	obj.province.Copy(msg.province());
	obj.city.Copy(msg.city());
	obj.isrobot = msg.isrobot();
	obj.bank_password.Copy(msg.bank_password());
	obj.bank_jetton = msg.bank_jetton();
	obj.ip.Copy(msg.ip());
	obj.last_login_time = msg.last_login_time();
	obj.last_logout_time = msg.last_logout_time();
	obj.aread_id = msg.aread_id();
	obj.channel_id = msg.channel_id();
	obj.platform_os.Copy(msg.platform_os());
	obj.phone_model.Copy(msg.phone_model());
	obj.first_recharge = msg.first_recharge();
	obj.agent_id = msg.agent_id();
	obj.referrer_id = msg.referrer_id();
	obj.vip_level = msg.vip_level();
	const ::proto_ff::UserMiscData & temp_misc_data = msg.misc_data();
	UserMiscData_s::read_from_pbmsg(temp_misc_data, obj.misc_data);
	obj.online = msg.online();
	obj.game_id = msg.game_id();
	obj.room_id = msg.room_id();
	obj.all_win = msg.all_win();
	obj.all_recharge = msg.all_recharge();
	obj.all_give = msg.all_give();
	obj.all_draw = msg.all_draw();
	obj.today_win = msg.today_win();
	obj.today_recharge = msg.today_recharge();
	obj.today_give = msg.today_give();
	obj.today_draw = msg.today_draw();
	obj.week_win = msg.week_win();
	obj.week_recharge = msg.week_recharge();
	obj.week_give = msg.week_give();
	obj.week_draw = msg.week_draw();
	obj.month_win = msg.month_win();
	obj.month_recharge = msg.month_recharge();
	obj.month_give = msg.month_give();
	obj.month_draw = msg.month_draw();
	obj.is_ban = msg.is_ban();
	obj.no_transfer = msg.no_transfer();
	obj.reg_ip.Copy(msg.reg_ip());
	obj.device_id.Copy(msg.device_id());
	obj.reg_device_id.Copy(msg.reg_device_id());
	obj.show_userid = msg.show_userid();
	obj.all_vip_zhuanru = msg.all_vip_zhuanru();
	obj.today_vip_zhuanru = msg.today_vip_zhuanru();
	obj.week_vip_zhuanru = msg.week_vip_zhuanru();
	obj.month_vip_zhuanru = msg.month_vip_zhuanru();
	obj.all_vip_zhuanchu = msg.all_vip_zhuanchu();
	obj.today_vip_zhuanchu = msg.today_vip_zhuanchu();
	obj.week_vip_zhuanchu = msg.week_vip_zhuanchu();
	obj.month_vip_zhuanchu = msg.month_vip_zhuanchu();
}

UserSimpleMiscData_s::UserSimpleMiscData_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int UserSimpleMiscData_s::CreateInit() {
	last_valid_player_time = (uint64_t)0;
	last_pay_player_time = (uint64_t)0;
	return 0;
}

int UserSimpleMiscData_s::ResumeInit() {
	return 0;
}

void UserSimpleMiscData_s::write_to_pbmsg(const struct UserSimpleMiscData_s & obj, ::proto_ff::UserSimpleMiscData & msg) {
	msg.set_last_valid_player_time((uint64_t)obj.last_valid_player_time);
	msg.set_last_pay_player_time((uint64_t)obj.last_pay_player_time);
}

void UserSimpleMiscData_s::read_from_pbmsg(const ::proto_ff::UserSimpleMiscData & msg, struct UserSimpleMiscData_s & obj) {
	memset(&obj, 0, sizeof(struct UserSimpleMiscData_s));
	obj.last_valid_player_time = msg.last_valid_player_time();
	obj.last_pay_player_time = msg.last_pay_player_time();
}

tbUserSimpleData_s::tbUserSimpleData_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int tbUserSimpleData_s::CreateInit() {
	userid = (uint64_t)0;
	face = (uint32_t)0;
	gender = (uint32_t)0;
	age = (uint32_t)0;
	agentid = (uint64_t)0;
	create_time = (uint64_t)0;
	is_robot = (bool)0;
	agent_level = (uint32_t)0;
	ach_day = (uint64_t)0;
	ach_week = (uint64_t)0;
	ach_month = (uint64_t)0;
	ach_all = (uint64_t)0;
	ach_team_day = (uint64_t)0;
	ach_team_week = (uint64_t)0;
	ach_team_month = (uint64_t)0;
	ach_team_all = (uint64_t)0;
	team_user_num = (uint64_t)0;
	new_user_day = (uint64_t)0;
	activity_user_day = (uint64_t)0;
	getrate = (uint32_t)0;
	tax_getrate = (uint32_t)0;
	takemoney = (uint32_t)0;
	tax_takemoney = (uint32_t)0;
	all_takemoney = (uint64_t)0;
	all_fee = (uint64_t)0;
	show_userid = (uint64_t)0;
	vip_level = (uint64_t)0;
	return 0;
}

int tbUserSimpleData_s::ResumeInit() {
	return 0;
}

void tbUserSimpleData_s::write_to_pbmsg(const struct tbUserSimpleData_s & obj, ::proto_ff::tbUserSimpleData & msg) {
	msg.set_userid((uint64_t)obj.userid);
	msg.set_nickname((const char*)obj.nickname.Get());
	msg.set_face((uint32_t)obj.face);
	msg.set_gender((uint32_t)obj.gender);
	msg.set_age((uint32_t)obj.age);
	msg.set_agentid((uint64_t)obj.agentid);
	msg.set_create_time((uint64_t)obj.create_time);
	msg.set_is_robot((bool)obj.is_robot);
	msg.set_agent_level((uint32_t)obj.agent_level);
	msg.set_ach_day((uint64_t)obj.ach_day);
	msg.set_ach_week((uint64_t)obj.ach_week);
	msg.set_ach_month((uint64_t)obj.ach_month);
	msg.set_ach_all((uint64_t)obj.ach_all);
	msg.set_ach_team_day((uint64_t)obj.ach_team_day);
	msg.set_ach_team_week((uint64_t)obj.ach_team_week);
	msg.set_ach_team_month((uint64_t)obj.ach_team_month);
	msg.set_ach_team_all((uint64_t)obj.ach_team_all);
	msg.set_team_user_num((uint64_t)obj.team_user_num);
	msg.set_new_user_day((uint64_t)obj.new_user_day);
	msg.set_activity_user_day((uint64_t)obj.activity_user_day);
	msg.set_getrate((uint32_t)obj.getrate);
	msg.set_tax_getrate((uint32_t)obj.tax_getrate);
	msg.set_takemoney((uint32_t)obj.takemoney);
	msg.set_tax_takemoney((uint32_t)obj.tax_takemoney);
	msg.set_all_takemoney((uint64_t)obj.all_takemoney);
	msg.set_all_fee((uint64_t)obj.all_fee);
	msg.set_show_userid((uint64_t)obj.show_userid);
	msg.set_vip_level((uint64_t)obj.vip_level);
	::proto_ff::UserSimpleMiscData* temp_misc_data = msg.mutable_misc_data();
	UserSimpleMiscData_s::write_to_pbmsg(obj.misc_data, *temp_misc_data);
}

void tbUserSimpleData_s::read_from_pbmsg(const ::proto_ff::tbUserSimpleData & msg, struct tbUserSimpleData_s & obj) {
	memset(&obj, 0, sizeof(struct tbUserSimpleData_s));
	obj.userid = msg.userid();
	obj.nickname.Copy(msg.nickname());
	obj.face = msg.face();
	obj.gender = msg.gender();
	obj.age = msg.age();
	obj.agentid = msg.agentid();
	obj.create_time = msg.create_time();
	obj.is_robot = msg.is_robot();
	obj.agent_level = msg.agent_level();
	obj.ach_day = msg.ach_day();
	obj.ach_week = msg.ach_week();
	obj.ach_month = msg.ach_month();
	obj.ach_all = msg.ach_all();
	obj.ach_team_day = msg.ach_team_day();
	obj.ach_team_week = msg.ach_team_week();
	obj.ach_team_month = msg.ach_team_month();
	obj.ach_team_all = msg.ach_team_all();
	obj.team_user_num = msg.team_user_num();
	obj.new_user_day = msg.new_user_day();
	obj.activity_user_day = msg.activity_user_day();
	obj.getrate = msg.getrate();
	obj.tax_getrate = msg.tax_getrate();
	obj.takemoney = msg.takemoney();
	obj.tax_takemoney = msg.tax_takemoney();
	obj.all_takemoney = msg.all_takemoney();
	obj.all_fee = msg.all_fee();
	obj.show_userid = msg.show_userid();
	obj.vip_level = msg.vip_level();
	const ::proto_ff::UserSimpleMiscData & temp_misc_data = msg.misc_data();
	UserSimpleMiscData_s::read_from_pbmsg(temp_misc_data, obj.misc_data);
}

GamePlayerWealthData_s::GamePlayerWealthData_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int GamePlayerWealthData_s::CreateInit() {
	player_id = (uint64_t)0;
	recharge = (int64_t)0;
	total_lost = (int64_t)0;
	total_win = (int64_t)0;
	this_game_lost = (int64_t)0;
	this_game_win = (int64_t)0;
	return 0;
}

int GamePlayerWealthData_s::ResumeInit() {
	return 0;
}

void GamePlayerWealthData_s::write_to_pbmsg(const struct GamePlayerWealthData_s & obj, ::proto_ff::GamePlayerWealthData & msg) {
	msg.set_player_id((uint64_t)obj.player_id);
	msg.set_recharge((int64_t)obj.recharge);
	msg.set_total_lost((int64_t)obj.total_lost);
	msg.set_total_win((int64_t)obj.total_win);
	msg.set_this_game_lost((int64_t)obj.this_game_lost);
	msg.set_this_game_win((int64_t)obj.this_game_win);
}

void GamePlayerWealthData_s::read_from_pbmsg(const ::proto_ff::GamePlayerWealthData & msg, struct GamePlayerWealthData_s & obj) {
	memset(&obj, 0, sizeof(struct GamePlayerWealthData_s));
	obj.player_id = msg.player_id();
	obj.recharge = msg.recharge();
	obj.total_lost = msg.total_lost();
	obj.total_win = msg.total_win();
	obj.this_game_lost = msg.this_game_lost();
	obj.this_game_win = msg.this_game_win();
}

GamePlayerDetailData_s::GamePlayerDetailData_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int GamePlayerDetailData_s::CreateInit() {
	player_id = (uint64_t)0;
	cur_money = (int64_t)0;
	vip_level = (uint32_t)0;
	sex = (uint32_t)0;
	chair_id = (int32_t)0;
	face = (uint32_t)0;
	isRobot = (bool)0;
	return 0;
}

int GamePlayerDetailData_s::ResumeInit() {
	return 0;
}

void GamePlayerDetailData_s::write_to_pbmsg(const struct GamePlayerDetailData_s & obj, ::proto_ff::GamePlayerDetailData & msg) {
	msg.set_player_id((uint64_t)obj.player_id);
	msg.set_cur_money((int64_t)obj.cur_money);
	msg.set_vip_level((uint32_t)obj.vip_level);
	msg.set_sex((uint32_t)obj.sex);
	msg.set_chair_id((int32_t)obj.chair_id);
	msg.set_nick_name((const char*)obj.nick_name.Get());
	msg.set_face((uint32_t)obj.face);
	msg.set_isrobot((bool)obj.isRobot);
}

void GamePlayerDetailData_s::read_from_pbmsg(const ::proto_ff::GamePlayerDetailData & msg, struct GamePlayerDetailData_s & obj) {
	memset(&obj, 0, sizeof(struct GamePlayerDetailData_s));
	obj.player_id = msg.player_id();
	obj.cur_money = msg.cur_money();
	obj.vip_level = msg.vip_level();
	obj.sex = msg.sex();
	obj.chair_id = msg.chair_id();
	obj.nick_name.Copy(msg.nick_name());
	obj.face = msg.face();
	obj.isRobot = msg.isrobot();
}

GamePlayerAchievementData_s::GamePlayerAchievementData_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int GamePlayerAchievementData_s::CreateInit() {
	cur_ach = (uint64_t)0;
	cur_fee = (uint64_t)0;
	return 0;
}

int GamePlayerAchievementData_s::ResumeInit() {
	return 0;
}

void GamePlayerAchievementData_s::write_to_pbmsg(const struct GamePlayerAchievementData_s & obj, ::proto_ff::GamePlayerAchievementData & msg) {
	msg.set_cur_ach((uint64_t)obj.cur_ach);
	msg.set_cur_fee((uint64_t)obj.cur_fee);
}

void GamePlayerAchievementData_s::read_from_pbmsg(const ::proto_ff::GamePlayerAchievementData & msg, struct GamePlayerAchievementData_s & obj) {
	memset(&obj, 0, sizeof(struct GamePlayerAchievementData_s));
	obj.cur_ach = msg.cur_ach();
	obj.cur_fee = msg.cur_fee();
}

UserSimpleData_s::UserSimpleData_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int UserSimpleData_s::CreateInit() {
	userid = (uint64_t)0;
	face = (uint32_t)0;
	gender = (uint32_t)0;
	age = (uint32_t)0;
	show_userid = (uint64_t)0;
	vip_level = (uint32_t)0;
	return 0;
}

int UserSimpleData_s::ResumeInit() {
	return 0;
}

void UserSimpleData_s::write_to_pbmsg(const struct UserSimpleData_s & obj, ::proto_ff::UserSimpleData & msg) {
	msg.set_userid((uint64_t)obj.userid);
	msg.set_nickname((const char*)obj.nickname.Get());
	msg.set_face((uint32_t)obj.face);
	msg.set_gender((uint32_t)obj.gender);
	msg.set_age((uint32_t)obj.age);
	msg.set_show_userid((uint64_t)obj.show_userid);
	msg.set_vip_level((uint32_t)obj.vip_level);
}

void UserSimpleData_s::read_from_pbmsg(const ::proto_ff::UserSimpleData & msg, struct UserSimpleData_s & obj) {
	memset(&obj, 0, sizeof(struct UserSimpleData_s));
	obj.userid = msg.userid();
	obj.nickname.Copy(msg.nickname());
	obj.face = msg.face();
	obj.gender = msg.gender();
	obj.age = msg.age();
	obj.show_userid = msg.show_userid();
	obj.vip_level = msg.vip_level();
}

UserBankInfo_s::UserBankInfo_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int UserBankInfo_s::CreateInit() {
	return 0;
}

int UserBankInfo_s::ResumeInit() {
	return 0;
}

void UserBankInfo_s::write_to_pbmsg(const struct UserBankInfo_s & obj, ::proto_ff::UserBankInfo & msg) {
	for(int32_t i = 0; i < obj.record_id.GetSize() && i < obj.record_id.GetMaxSize(); ++i) {
		msg.add_record_id((uint64_t)obj.record_id[i]);
	}
}

void UserBankInfo_s::read_from_pbmsg(const ::proto_ff::UserBankInfo & msg, struct UserBankInfo_s & obj) {
	memset(&obj, 0, sizeof(struct UserBankInfo_s));
	obj.record_id.SetSize(msg.record_id_size() > obj.record_id.GetMaxSize() ? obj.record_id.GetMaxSize() : msg.record_id_size());
	for(int32_t i = 0; i < obj.record_id.GetSize(); ++i) {
		obj.record_id[i] = msg.record_id(i);
	}
}

tbUserMiscInfo_s::tbUserMiscInfo_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int tbUserMiscInfo_s::CreateInit() {
	user_id = (uint64_t)0;
	return 0;
}

int tbUserMiscInfo_s::ResumeInit() {
	return 0;
}

void tbUserMiscInfo_s::write_to_pbmsg(const struct tbUserMiscInfo_s & obj, ::proto_ff::tbUserMiscInfo & msg) {
	msg.set_user_id((uint64_t)obj.user_id);
	::proto_ff::UserBankInfo* temp_bank_info = msg.mutable_bank_info();
	UserBankInfo_s::write_to_pbmsg(obj.bank_info, *temp_bank_info);
}

void tbUserMiscInfo_s::read_from_pbmsg(const ::proto_ff::tbUserMiscInfo & msg, struct tbUserMiscInfo_s & obj) {
	memset(&obj, 0, sizeof(struct tbUserMiscInfo_s));
	obj.user_id = msg.user_id();
	const ::proto_ff::UserBankInfo & temp_bank_info = msg.bank_info();
	UserBankInfo_s::read_from_pbmsg(temp_bank_info, obj.bank_info);
}

RankCommonInfo_s::RankCommonInfo_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int RankCommonInfo_s::CreateInit() {
	id = (uint64_t)0;
	rank = (int32_t)0;
	return 0;
}

int RankCommonInfo_s::ResumeInit() {
	return 0;
}

void RankCommonInfo_s::write_to_pbmsg(const struct RankCommonInfo_s & obj, ::proto_ff::RankCommonInfo & msg) {
	msg.set_id((uint64_t)obj.id);
	msg.set_rank((int32_t)obj.rank);
}

void RankCommonInfo_s::read_from_pbmsg(const ::proto_ff::RankCommonInfo & msg, struct RankCommonInfo_s & obj) {
	memset(&obj, 0, sizeof(struct RankCommonInfo_s));
	obj.id = msg.id();
	obj.rank = msg.rank();
}

RankCommonScore_s::RankCommonScore_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int RankCommonScore_s::CreateInit() {
	id = (uint64_t)0;
	score = (uint64_t)0;
	return 0;
}

int RankCommonScore_s::ResumeInit() {
	return 0;
}

void RankCommonScore_s::write_to_pbmsg(const struct RankCommonScore_s & obj, ::proto_ff::RankCommonScore & msg) {
	msg.set_id((uint64_t)obj.id);
	msg.set_score((uint64_t)obj.score);
}

void RankCommonScore_s::read_from_pbmsg(const ::proto_ff::RankCommonScore & msg, struct RankCommonScore_s & obj) {
	memset(&obj, 0, sizeof(struct RankCommonScore_s));
	obj.id = msg.id();
	obj.score = msg.score();
}

RankCommonBody_s::RankCommonBody_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int RankCommonBody_s::CreateInit() {
	return 0;
}

int RankCommonBody_s::ResumeInit() {
	return 0;
}

void RankCommonBody_s::write_to_pbmsg(const struct RankCommonBody_s & obj, ::proto_ff::RankCommonBody & msg) {
	for(int32_t i = 0; i < obj.score_list.GetSize() && i < obj.score_list.GetMaxSize(); ++i) {
		::proto_ff::RankCommonScore* temp_score_list = msg.add_score_list();
		RankCommonScore_s::write_to_pbmsg(obj.score_list[i], *temp_score_list);
	}
	for(int32_t i = 0; i < obj.info_list.GetSize() && i < obj.info_list.GetMaxSize(); ++i) {
		::proto_ff::RankCommonInfo* temp_info_list = msg.add_info_list();
		RankCommonInfo_s::write_to_pbmsg(obj.info_list[i], *temp_info_list);
	}
}

void RankCommonBody_s::read_from_pbmsg(const ::proto_ff::RankCommonBody & msg, struct RankCommonBody_s & obj) {
	memset(&obj, 0, sizeof(struct RankCommonBody_s));
	obj.score_list.SetSize(msg.score_list_size() > obj.score_list.GetMaxSize() ? obj.score_list.GetMaxSize() : msg.score_list_size());
	for(int32_t i = 0; i < obj.score_list.GetSize(); ++i) {
		const ::proto_ff::RankCommonScore & temp_score_list = msg.score_list(i);
		RankCommonScore_s::read_from_pbmsg(temp_score_list, obj.score_list[i]);
	}
	obj.info_list.SetSize(msg.info_list_size() > obj.info_list.GetMaxSize() ? obj.info_list.GetMaxSize() : msg.info_list_size());
	for(int32_t i = 0; i < obj.info_list.GetSize(); ++i) {
		const ::proto_ff::RankCommonInfo & temp_info_list = msg.info_list(i);
		RankCommonInfo_s::read_from_pbmsg(temp_info_list, obj.info_list[i]);
	}
}

tbRankCommon_s::tbRankCommon_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int tbRankCommon_s::CreateInit() {
	id4db = (int32_t)0;
	return 0;
}

int tbRankCommon_s::ResumeInit() {
	return 0;
}

void tbRankCommon_s::write_to_pbmsg(const struct tbRankCommon_s & obj, ::proto_ff::tbRankCommon & msg) {
	msg.set_id4db((int32_t)obj.id4db);
	::proto_ff::RankCommonBody* temp_body = msg.mutable_body();
	RankCommonBody_s::write_to_pbmsg(obj.body, *temp_body);
}

void tbRankCommon_s::read_from_pbmsg(const ::proto_ff::tbRankCommon & msg, struct tbRankCommon_s & obj) {
	memset(&obj, 0, sizeof(struct tbRankCommon_s));
	obj.id4db = msg.id4db();
	const ::proto_ff::RankCommonBody & temp_body = msg.body();
	RankCommonBody_s::read_from_pbmsg(temp_body, obj.body);
}

RobotCommonData_s::RobotCommonData_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int RobotCommonData_s::CreateInit() {
	robot_id = (uint64_t)0;
	face_id = (uint32_t)0;
	age = (uint32_t)0;
	gender = (uint32_t)0;
	jetton = (uint64_t)0;
	is_use = (bool)0;
	return 0;
}

int RobotCommonData_s::ResumeInit() {
	return 0;
}

void RobotCommonData_s::write_to_pbmsg(const struct RobotCommonData_s & obj, ::proto_ff::RobotCommonData & msg) {
	msg.set_robot_id((uint64_t)obj.robot_id);
	msg.set_nickname((const char*)obj.nickname.Get());
	msg.set_face_id((uint32_t)obj.face_id);
	msg.set_age((uint32_t)obj.age);
	msg.set_gender((uint32_t)obj.gender);
	msg.set_jetton((uint64_t)obj.jetton);
	msg.set_is_use((bool)obj.is_use);
}

void RobotCommonData_s::read_from_pbmsg(const ::proto_ff::RobotCommonData & msg, struct RobotCommonData_s & obj) {
	memset(&obj, 0, sizeof(struct RobotCommonData_s));
	obj.robot_id = msg.robot_id();
	obj.nickname.Copy(msg.nickname());
	obj.face_id = msg.face_id();
	obj.age = msg.age();
	obj.gender = msg.gender();
	obj.jetton = msg.jetton();
	obj.is_use = msg.is_use();
}

RobotCommonBody_s::RobotCommonBody_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int RobotCommonBody_s::CreateInit() {
	return 0;
}

int RobotCommonBody_s::ResumeInit() {
	return 0;
}

void RobotCommonBody_s::write_to_pbmsg(const struct RobotCommonBody_s & obj, ::proto_ff::RobotCommonBody & msg) {
	for(int32_t i = 0; i < obj.robot_data.GetSize() && i < obj.robot_data.GetMaxSize(); ++i) {
		::proto_ff::RobotCommonData* temp_robot_data = msg.add_robot_data();
		RobotCommonData_s::write_to_pbmsg(obj.robot_data[i], *temp_robot_data);
	}
}

void RobotCommonBody_s::read_from_pbmsg(const ::proto_ff::RobotCommonBody & msg, struct RobotCommonBody_s & obj) {
	memset(&obj, 0, sizeof(struct RobotCommonBody_s));
	obj.robot_data.SetSize(msg.robot_data_size() > obj.robot_data.GetMaxSize() ? obj.robot_data.GetMaxSize() : msg.robot_data_size());
	for(int32_t i = 0; i < obj.robot_data.GetSize(); ++i) {
		const ::proto_ff::RobotCommonData & temp_robot_data = msg.robot_data(i);
		RobotCommonData_s::read_from_pbmsg(temp_robot_data, obj.robot_data[i]);
	}
}

tbGameRobot_s::tbGameRobot_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int tbGameRobot_s::CreateInit() {
	id4db = (int32_t)0;
	return 0;
}

int tbGameRobot_s::ResumeInit() {
	return 0;
}

void tbGameRobot_s::write_to_pbmsg(const struct tbGameRobot_s & obj, ::proto_ff::tbGameRobot & msg) {
	msg.set_id4db((int32_t)obj.id4db);
	::proto_ff::RobotCommonBody* temp_body = msg.mutable_body();
	RobotCommonBody_s::write_to_pbmsg(obj.body, *temp_body);
}

void tbGameRobot_s::read_from_pbmsg(const ::proto_ff::tbGameRobot & msg, struct tbGameRobot_s & obj) {
	memset(&obj, 0, sizeof(struct tbGameRobot_s));
	obj.id4db = msg.id4db();
	const ::proto_ff::RobotCommonBody & temp_body = msg.body();
	RobotCommonBody_s::read_from_pbmsg(temp_body, obj.body);
}

EventLogData_s::EventLogData_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int EventLogData_s::CreateInit() {
	event_type = (::proto_ff::EventLogType)0;
	return 0;
}

int EventLogData_s::ResumeInit() {
	return 0;
}

void EventLogData_s::write_to_pbmsg(const struct EventLogData_s & obj, ::proto_ff::EventLogData & msg) {
	msg.set_event_type((::proto_ff::EventLogType)obj.event_type);
}

void EventLogData_s::read_from_pbmsg(const ::proto_ff::EventLogData & msg, struct EventLogData_s & obj) {
	memset(&obj, 0, sizeof(struct EventLogData_s));
	obj.event_type = msg.event_type();
}

tbEventLog_s::tbEventLog_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int tbEventLog_s::CreateInit() {
	user_id = (uint64_t)0;
	event_id = (uint64_t)0;
	create_time = (int32_t)0;
	expire_time = (int32_t)0;
	return 0;
}

int tbEventLog_s::ResumeInit() {
	return 0;
}

void tbEventLog_s::write_to_pbmsg(const struct tbEventLog_s & obj, ::proto_ff::tbEventLog & msg) {
	msg.set_user_id((uint64_t)obj.user_id);
	msg.set_event_id((uint64_t)obj.event_id);
	msg.set_create_time((int32_t)obj.create_time);
	msg.set_expire_time((int32_t)obj.expire_time);
	::proto_ff::EventLogData* temp_data = msg.mutable_data();
	EventLogData_s::write_to_pbmsg(obj.data, *temp_data);
}

void tbEventLog_s::read_from_pbmsg(const ::proto_ff::tbEventLog & msg, struct tbEventLog_s & obj) {
	memset(&obj, 0, sizeof(struct tbEventLog_s));
	obj.user_id = msg.user_id();
	obj.event_id = msg.event_id();
	obj.create_time = msg.create_time();
	obj.expire_time = msg.expire_time();
	const ::proto_ff::EventLogData & temp_data = msg.data();
	EventLogData_s::read_from_pbmsg(temp_data, obj.data);
}

LoginCommonData_s::LoginCommonData_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int LoginCommonData_s::CreateInit() {
	aread_id = (uint32_t)0;
	agent_id = (uint64_t)0;
	channel_id = (uint32_t)0;
	referral_code = (uint32_t)0;
	return 0;
}

int LoginCommonData_s::ResumeInit() {
	return 0;
}

void LoginCommonData_s::write_to_pbmsg(const struct LoginCommonData_s & obj, ::proto_ff::LoginCommonData & msg) {
	msg.set_aread_id((uint32_t)obj.aread_id);
	msg.set_agent_id((uint64_t)obj.agent_id);
	msg.set_channel_id((uint32_t)obj.channel_id);
	msg.set_referral_code((uint32_t)obj.referral_code);
	msg.set_platform_os((const char*)obj.platform_os.Get());
	msg.set_country((const char*)obj.country.Get());
	msg.set_province((const char*)obj.province.Get());
	msg.set_city((const char*)obj.city.Get());
	msg.set_ip((const char*)obj.ip.Get());
	msg.set_phone_mode((const char*)obj.phone_mode.Get());
	msg.set_device_id((const char*)obj.device_id.Get());
}

void LoginCommonData_s::read_from_pbmsg(const ::proto_ff::LoginCommonData & msg, struct LoginCommonData_s & obj) {
	memset(&obj, 0, sizeof(struct LoginCommonData_s));
	obj.aread_id = msg.aread_id();
	obj.agent_id = msg.agent_id();
	obj.channel_id = msg.channel_id();
	obj.referral_code = msg.referral_code();
	obj.platform_os.Copy(msg.platform_os());
	obj.country.Copy(msg.country());
	obj.province.Copy(msg.province());
	obj.city.Copy(msg.city());
	obj.ip.Copy(msg.ip());
	obj.phone_mode.Copy(msg.phone_mode());
	obj.device_id.Copy(msg.device_id());
}

LogMoneyDetail_s::LogMoneyDetail_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int LogMoneyDetail_s::CreateInit() {
	event_id = (uint64_t)0;
	sequence = (uint32_t)0;
	user_id = (uint64_t)0;
	game_id = (uint32_t)0;
	room_id = (uint32_t)0;
	desk_id = (uint32_t)0;
	chair_id = (uint32_t)0;
	account_type = (uint32_t)0;
	opt_type = (uint32_t)0;
	opt_reason = (uint32_t)0;
	all_jetton = (uint64_t)0;
	jetton = (uint64_t)0;
	bank_jetton = (uint64_t)0;
	change_count = (uint64_t)0;
	agent_id = (uint64_t)0;
	record_id = (uint64_t)0;
	return 0;
}

int LogMoneyDetail_s::ResumeInit() {
	return 0;
}

void LogMoneyDetail_s::write_to_pbmsg(const struct LogMoneyDetail_s & obj, ::proto_ff::LogMoneyDetail & msg) {
	msg.set_event_id((uint64_t)obj.event_id);
	msg.set_sequence((uint32_t)obj.sequence);
	msg.set_bus_name((const char*)obj.bus_name.Get());
	msg.set_event_time((const char*)obj.event_time.Get());
	msg.set_user_id((uint64_t)obj.user_id);
	msg.set_user_name((const char*)obj.user_name.Get());
	msg.set_game_id((uint32_t)obj.game_id);
	msg.set_room_id((uint32_t)obj.room_id);
	msg.set_desk_id((uint32_t)obj.desk_id);
	msg.set_chair_id((uint32_t)obj.chair_id);
	msg.set_account_type((uint32_t)obj.account_type);
	msg.set_opt_type((uint32_t)obj.opt_type);
	msg.set_opt_reason((uint32_t)obj.opt_reason);
	msg.set_all_jetton((uint64_t)obj.all_jetton);
	msg.set_jetton((uint64_t)obj.jetton);
	msg.set_bank_jetton((uint64_t)obj.bank_jetton);
	msg.set_change_count((uint64_t)obj.change_count);
	msg.set_agent_id((uint64_t)obj.agent_id);
	msg.set_ip((const char*)obj.ip.Get());
	msg.set_record_id((uint64_t)obj.record_id);
}

void LogMoneyDetail_s::read_from_pbmsg(const ::proto_ff::LogMoneyDetail & msg, struct LogMoneyDetail_s & obj) {
	memset(&obj, 0, sizeof(struct LogMoneyDetail_s));
	obj.event_id = msg.event_id();
	obj.sequence = msg.sequence();
	obj.bus_name.Copy(msg.bus_name());
	obj.event_time.Copy(msg.event_time());
	obj.user_id = msg.user_id();
	obj.user_name.Copy(msg.user_name());
	obj.game_id = msg.game_id();
	obj.room_id = msg.room_id();
	obj.desk_id = msg.desk_id();
	obj.chair_id = msg.chair_id();
	obj.account_type = msg.account_type();
	obj.opt_type = msg.opt_type();
	obj.opt_reason = msg.opt_reason();
	obj.all_jetton = msg.all_jetton();
	obj.jetton = msg.jetton();
	obj.bank_jetton = msg.bank_jetton();
	obj.change_count = msg.change_count();
	obj.agent_id = msg.agent_id();
	obj.ip.Copy(msg.ip());
	obj.record_id = msg.record_id();
}

LogGameRecordDetail_s::LogGameRecordDetail_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int LogGameRecordDetail_s::CreateInit() {
	event_id = (uint64_t)0;
	sequence = (uint32_t)0;
	user_id = (uint64_t)0;
	record_id = (uint64_t)0;
	game_id = (uint32_t)0;
	room_id = (uint32_t)0;
	desk_id = (uint32_t)0;
	chair_id = (uint32_t)0;
	pour_jetton = (uint64_t)0;
	win_jetton = (int64_t)0;
	tax_jetton = (uint64_t)0;
	return 0;
}

int LogGameRecordDetail_s::ResumeInit() {
	return 0;
}

void LogGameRecordDetail_s::write_to_pbmsg(const struct LogGameRecordDetail_s & obj, ::proto_ff::LogGameRecordDetail & msg) {
	msg.set_event_id((uint64_t)obj.event_id);
	msg.set_sequence((uint32_t)obj.sequence);
	msg.set_bus_name((const char*)obj.bus_name.Get());
	msg.set_event_time((const char*)obj.event_time.Get());
	msg.set_user_id((uint64_t)obj.user_id);
	msg.set_user_name((const char*)obj.user_name.Get());
	msg.set_record_id((uint64_t)obj.record_id);
	msg.set_game_id((uint32_t)obj.game_id);
	msg.set_room_id((uint32_t)obj.room_id);
	msg.set_desk_id((uint32_t)obj.desk_id);
	msg.set_chair_id((uint32_t)obj.chair_id);
	msg.set_result_info((const char*)obj.result_info.Get());
	msg.set_pour_jetton((uint64_t)obj.pour_jetton);
	msg.set_win_jetton((int64_t)obj.win_jetton);
	msg.set_tax_jetton((uint64_t)obj.tax_jetton);
	msg.set_win_list((const char*)obj.win_list.Get());
	msg.set_lost_list((const char*)obj.lost_list.Get());
}

void LogGameRecordDetail_s::read_from_pbmsg(const ::proto_ff::LogGameRecordDetail & msg, struct LogGameRecordDetail_s & obj) {
	memset(&obj, 0, sizeof(struct LogGameRecordDetail_s));
	obj.event_id = msg.event_id();
	obj.sequence = msg.sequence();
	obj.bus_name.Copy(msg.bus_name());
	obj.event_time.Copy(msg.event_time());
	obj.user_id = msg.user_id();
	obj.user_name.Copy(msg.user_name());
	obj.record_id = msg.record_id();
	obj.game_id = msg.game_id();
	obj.room_id = msg.room_id();
	obj.desk_id = msg.desk_id();
	obj.chair_id = msg.chair_id();
	obj.result_info.Copy(msg.result_info());
	obj.pour_jetton = msg.pour_jetton();
	obj.win_jetton = msg.win_jetton();
	obj.tax_jetton = msg.tax_jetton();
	obj.win_list.Copy(msg.win_list());
	obj.lost_list.Copy(msg.lost_list());
}

LogGameDetail_s::LogGameDetail_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int LogGameDetail_s::CreateInit() {
	event_id = (uint64_t)0;
	sequence = (uint32_t)0;
	user_id = (uint64_t)0;
	record_id = (uint64_t)0;
	game_id = (uint32_t)0;
	room_id = (uint32_t)0;
	desk_id = (uint32_t)0;
	game_time = (uint64_t)0;
	return 0;
}

int LogGameDetail_s::ResumeInit() {
	return 0;
}

void LogGameDetail_s::write_to_pbmsg(const struct LogGameDetail_s & obj, ::proto_ff::LogGameDetail & msg) {
	msg.set_event_id((uint64_t)obj.event_id);
	msg.set_sequence((uint32_t)obj.sequence);
	msg.set_bus_name((const char*)obj.bus_name.Get());
	msg.set_event_time((const char*)obj.event_time.Get());
	msg.set_user_id((uint64_t)obj.user_id);
	msg.set_user_name((const char*)obj.user_name.Get());
	msg.set_record_id((uint64_t)obj.record_id);
	msg.set_game_id((uint32_t)obj.game_id);
	msg.set_room_id((uint32_t)obj.room_id);
	msg.set_desk_id((uint32_t)obj.desk_id);
	msg.set_bet_info((const char*)obj.bet_info.Get());
	msg.set_result_info((const char*)obj.result_info.Get());
	msg.set_game_time((uint64_t)obj.game_time);
}

void LogGameDetail_s::read_from_pbmsg(const ::proto_ff::LogGameDetail & msg, struct LogGameDetail_s & obj) {
	memset(&obj, 0, sizeof(struct LogGameDetail_s));
	obj.event_id = msg.event_id();
	obj.sequence = msg.sequence();
	obj.bus_name.Copy(msg.bus_name());
	obj.event_time.Copy(msg.event_time());
	obj.user_id = msg.user_id();
	obj.user_name.Copy(msg.user_name());
	obj.record_id = msg.record_id();
	obj.game_id = msg.game_id();
	obj.room_id = msg.room_id();
	obj.desk_id = msg.desk_id();
	obj.bet_info.Copy(msg.bet_info());
	obj.result_info.Copy(msg.result_info());
	obj.game_time = msg.game_time();
}

tbLogGameDay_s::tbLogGameDay_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int tbLogGameDay_s::CreateInit() {
	game_id = (uint32_t)0;
	room_id = (uint32_t)0;
	all_pour = (uint64_t)0;
	pour_day = (uint64_t)0;
	pour_week = (uint64_t)0;
	pour_month = (uint64_t)0;
	all_win = (int64_t)0;
	win_day = (int64_t)0;
	win_week = (int64_t)0;
	win_month = (int64_t)0;
	all_fee = (uint64_t)0;
	fee_day = (uint64_t)0;
	fee_week = (uint64_t)0;
	fee_month = (uint64_t)0;
	return 0;
}

int tbLogGameDay_s::ResumeInit() {
	return 0;
}

void tbLogGameDay_s::write_to_pbmsg(const struct tbLogGameDay_s & obj, ::proto_ff::tbLogGameDay & msg) {
	msg.set_date_id((const char*)obj.date_id.Get());
	msg.set_game_id((uint32_t)obj.game_id);
	msg.set_room_id((uint32_t)obj.room_id);
	msg.set_all_pour((uint64_t)obj.all_pour);
	msg.set_pour_day((uint64_t)obj.pour_day);
	msg.set_pour_week((uint64_t)obj.pour_week);
	msg.set_pour_month((uint64_t)obj.pour_month);
	msg.set_all_win((int64_t)obj.all_win);
	msg.set_win_day((int64_t)obj.win_day);
	msg.set_win_week((int64_t)obj.win_week);
	msg.set_win_month((int64_t)obj.win_month);
	msg.set_all_fee((uint64_t)obj.all_fee);
	msg.set_fee_day((uint64_t)obj.fee_day);
	msg.set_fee_week((uint64_t)obj.fee_week);
	msg.set_fee_month((uint64_t)obj.fee_month);
	msg.set_stat_time((const char*)obj.stat_time.Get());
}

void tbLogGameDay_s::read_from_pbmsg(const ::proto_ff::tbLogGameDay & msg, struct tbLogGameDay_s & obj) {
	memset(&obj, 0, sizeof(struct tbLogGameDay_s));
	obj.date_id.Copy(msg.date_id());
	obj.game_id = msg.game_id();
	obj.room_id = msg.room_id();
	obj.all_pour = msg.all_pour();
	obj.pour_day = msg.pour_day();
	obj.pour_week = msg.pour_week();
	obj.pour_month = msg.pour_month();
	obj.all_win = msg.all_win();
	obj.win_day = msg.win_day();
	obj.win_week = msg.win_week();
	obj.win_month = msg.win_month();
	obj.all_fee = msg.all_fee();
	obj.fee_day = msg.fee_day();
	obj.fee_week = msg.fee_week();
	obj.fee_month = msg.fee_month();
	obj.stat_time.Copy(msg.stat_time());
}

tbGameUserManagerData_s::tbGameUserManagerData_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int tbGameUserManagerData_s::CreateInit() {
	id = (uint64_t)0;
	user_id = (uint64_t)0;
	roster_type = (uint32_t)0;
	start_time = (uint64_t)0;
	end_time = (uint64_t)0;
	game_id = (uint32_t)0;
	room_id = (uint32_t)0;
	state = (uint32_t)0;
	opt_mark = (int64_t)0;
	rate_mark = (float)0;
	control_level = (int32_t)0;
	max_win_jetton = (uint64_t)0;
	cur_win = (int64_t)0;
	return 0;
}

int tbGameUserManagerData_s::ResumeInit() {
	return 0;
}

void tbGameUserManagerData_s::write_to_pbmsg(const struct tbGameUserManagerData_s & obj, ::proto_ff::tbGameUserManagerData & msg) {
	msg.set_id((uint64_t)obj.id);
	msg.set_user_id((uint64_t)obj.user_id);
	msg.set_user_name((const char*)obj.user_name.Get());
	msg.set_create_date((const char*)obj.create_date.Get());
	msg.set_roster_type((uint32_t)obj.roster_type);
	msg.set_start_time((uint64_t)obj.start_time);
	msg.set_end_time((uint64_t)obj.end_time);
	msg.set_game_id((uint32_t)obj.game_id);
	msg.set_room_id((uint32_t)obj.room_id);
	msg.set_state((uint32_t)obj.state);
	msg.set_opt_mark((int64_t)obj.opt_mark);
	msg.set_rate_mark((float)obj.rate_mark);
	msg.set_control_level((int32_t)obj.control_level);
	msg.set_max_win_jetton((uint64_t)obj.max_win_jetton);
	msg.set_cur_win((int64_t)obj.cur_win);
}

void tbGameUserManagerData_s::read_from_pbmsg(const ::proto_ff::tbGameUserManagerData & msg, struct tbGameUserManagerData_s & obj) {
	memset(&obj, 0, sizeof(struct tbGameUserManagerData_s));
	obj.id = msg.id();
	obj.user_id = msg.user_id();
	obj.user_name.Copy(msg.user_name());
	obj.create_date.Copy(msg.create_date());
	obj.roster_type = msg.roster_type();
	obj.start_time = msg.start_time();
	obj.end_time = msg.end_time();
	obj.game_id = msg.game_id();
	obj.room_id = msg.room_id();
	obj.state = msg.state();
	obj.opt_mark = msg.opt_mark();
	obj.rate_mark = msg.rate_mark();
	obj.control_level = msg.control_level();
	obj.max_win_jetton = msg.max_win_jetton();
	obj.cur_win = msg.cur_win();
}

tbMachineManagerData_s::tbMachineManagerData_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int tbMachineManagerData_s::CreateInit() {
	id = (uint64_t)0;
	roster_type = (uint32_t)0;
	start_time = (uint64_t)0;
	end_time = (uint64_t)0;
	game_id = (uint32_t)0;
	room_id = (uint32_t)0;
	state = (uint32_t)0;
	opt_mark = (int64_t)0;
	rate_mark = (float)0;
	control_level = (int32_t)0;
	max_win_jetton = (uint64_t)0;
	cur_win = (int64_t)0;
	return 0;
}

int tbMachineManagerData_s::ResumeInit() {
	return 0;
}

void tbMachineManagerData_s::write_to_pbmsg(const struct tbMachineManagerData_s & obj, ::proto_ff::tbMachineManagerData & msg) {
	msg.set_id((uint64_t)obj.id);
	msg.set_device_id((const char*)obj.device_id.Get());
	msg.set_create_date((const char*)obj.create_date.Get());
	msg.set_roster_type((uint32_t)obj.roster_type);
	msg.set_start_time((uint64_t)obj.start_time);
	msg.set_end_time((uint64_t)obj.end_time);
	msg.set_game_id((uint32_t)obj.game_id);
	msg.set_room_id((uint32_t)obj.room_id);
	msg.set_state((uint32_t)obj.state);
	msg.set_opt_mark((int64_t)obj.opt_mark);
	msg.set_rate_mark((float)obj.rate_mark);
	msg.set_control_level((int32_t)obj.control_level);
	msg.set_max_win_jetton((uint64_t)obj.max_win_jetton);
	msg.set_cur_win((int64_t)obj.cur_win);
}

void tbMachineManagerData_s::read_from_pbmsg(const ::proto_ff::tbMachineManagerData & msg, struct tbMachineManagerData_s & obj) {
	memset(&obj, 0, sizeof(struct tbMachineManagerData_s));
	obj.id = msg.id();
	obj.device_id.Copy(msg.device_id());
	obj.create_date.Copy(msg.create_date());
	obj.roster_type = msg.roster_type();
	obj.start_time = msg.start_time();
	obj.end_time = msg.end_time();
	obj.game_id = msg.game_id();
	obj.room_id = msg.room_id();
	obj.state = msg.state();
	obj.opt_mark = msg.opt_mark();
	obj.rate_mark = msg.rate_mark();
	obj.control_level = msg.control_level();
	obj.max_win_jetton = msg.max_win_jetton();
	obj.cur_win = msg.cur_win();
}

Sheet_tbGameUserManagerData_s::Sheet_tbGameUserManagerData_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_tbGameUserManagerData_s::CreateInit() {
	return 0;
}

int Sheet_tbGameUserManagerData_s::ResumeInit() {
	return 0;
}

void Sheet_tbGameUserManagerData_s::write_to_pbmsg(const struct Sheet_tbGameUserManagerData_s & obj, ::proto_ff::Sheet_tbGameUserManagerData & msg) {
	for(int32_t i = 0; i < obj.tbGameUserManagerData_List.GetSize() && i < obj.tbGameUserManagerData_List.GetMaxSize(); ++i) {
		::proto_ff::tbGameUserManagerData* temp_tbgameusermanagerdata_list = msg.add_tbgameusermanagerdata_list();
		tbGameUserManagerData_s::write_to_pbmsg(obj.tbGameUserManagerData_List[i], *temp_tbgameusermanagerdata_list);
	}
}

void Sheet_tbGameUserManagerData_s::read_from_pbmsg(const ::proto_ff::Sheet_tbGameUserManagerData & msg, struct Sheet_tbGameUserManagerData_s & obj) {
	memset(&obj, 0, sizeof(struct Sheet_tbGameUserManagerData_s));
	obj.tbGameUserManagerData_List.SetSize(msg.tbgameusermanagerdata_list_size() > obj.tbGameUserManagerData_List.GetMaxSize() ? obj.tbGameUserManagerData_List.GetMaxSize() : msg.tbgameusermanagerdata_list_size());
	for(int32_t i = 0; i < obj.tbGameUserManagerData_List.GetSize(); ++i) {
		const ::proto_ff::tbGameUserManagerData & temp_tbgameusermanagerdata_list = msg.tbgameusermanagerdata_list(i);
		tbGameUserManagerData_s::read_from_pbmsg(temp_tbgameusermanagerdata_list, obj.tbGameUserManagerData_List[i]);
	}
}

tbGmCtrlGiveCtrlData_s::tbGmCtrlGiveCtrlData_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int tbGmCtrlGiveCtrlData_s::CreateInit() {
	id = (uint64_t)0;
	user_id = (uint64_t)0;
	control_type = (uint32_t)0;
	start_time = (uint64_t)0;
	end_time = (uint64_t)0;
	game_id = (uint32_t)0;
	state = (uint32_t)0;
	jackpot_type = (int32_t)0;
	jackpot_rate = (float)0;
	jackpot_jetton = (uint64_t)0;
	return 0;
}

int tbGmCtrlGiveCtrlData_s::ResumeInit() {
	return 0;
}

void tbGmCtrlGiveCtrlData_s::write_to_pbmsg(const struct tbGmCtrlGiveCtrlData_s & obj, ::proto_ff::tbGmCtrlGiveCtrlData & msg) {
	msg.set_id((uint64_t)obj.id);
	msg.set_user_id((uint64_t)obj.user_id);
	msg.set_user_name((const char*)obj.user_name.Get());
	msg.set_create_date((const char*)obj.create_date.Get());
	msg.set_control_type((uint32_t)obj.control_type);
	msg.set_start_time((uint64_t)obj.start_time);
	msg.set_end_time((uint64_t)obj.end_time);
	msg.set_game_id((uint32_t)obj.game_id);
	msg.set_state((uint32_t)obj.state);
	msg.set_jackpot_type((int32_t)obj.jackpot_type);
	msg.set_jackpot_rate((float)obj.jackpot_rate);
	msg.set_jackpot_jetton((uint64_t)obj.jackpot_jetton);
}

void tbGmCtrlGiveCtrlData_s::read_from_pbmsg(const ::proto_ff::tbGmCtrlGiveCtrlData & msg, struct tbGmCtrlGiveCtrlData_s & obj) {
	memset(&obj, 0, sizeof(struct tbGmCtrlGiveCtrlData_s));
	obj.id = msg.id();
	obj.user_id = msg.user_id();
	obj.user_name.Copy(msg.user_name());
	obj.create_date.Copy(msg.create_date());
	obj.control_type = msg.control_type();
	obj.start_time = msg.start_time();
	obj.end_time = msg.end_time();
	obj.game_id = msg.game_id();
	obj.state = msg.state();
	obj.jackpot_type = msg.jackpot_type();
	obj.jackpot_rate = msg.jackpot_rate();
	obj.jackpot_jetton = msg.jackpot_jetton();
}

Sheet_tbGmCtrlGiveCtrlData_s::Sheet_tbGmCtrlGiveCtrlData_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_tbGmCtrlGiveCtrlData_s::CreateInit() {
	return 0;
}

int Sheet_tbGmCtrlGiveCtrlData_s::ResumeInit() {
	return 0;
}

void Sheet_tbGmCtrlGiveCtrlData_s::write_to_pbmsg(const struct Sheet_tbGmCtrlGiveCtrlData_s & obj, ::proto_ff::Sheet_tbGmCtrlGiveCtrlData & msg) {
	for(int32_t i = 0; i < obj.tbGmCtrlGiveCtrlData_List.GetSize() && i < obj.tbGmCtrlGiveCtrlData_List.GetMaxSize(); ++i) {
		::proto_ff::tbGmCtrlGiveCtrlData* temp_tbgmctrlgivectrldata_list = msg.add_tbgmctrlgivectrldata_list();
		tbGmCtrlGiveCtrlData_s::write_to_pbmsg(obj.tbGmCtrlGiveCtrlData_List[i], *temp_tbgmctrlgivectrldata_list);
	}
}

void Sheet_tbGmCtrlGiveCtrlData_s::read_from_pbmsg(const ::proto_ff::Sheet_tbGmCtrlGiveCtrlData & msg, struct Sheet_tbGmCtrlGiveCtrlData_s & obj) {
	memset(&obj, 0, sizeof(struct Sheet_tbGmCtrlGiveCtrlData_s));
	obj.tbGmCtrlGiveCtrlData_List.SetSize(msg.tbgmctrlgivectrldata_list_size() > obj.tbGmCtrlGiveCtrlData_List.GetMaxSize() ? obj.tbGmCtrlGiveCtrlData_List.GetMaxSize() : msg.tbgmctrlgivectrldata_list_size());
	for(int32_t i = 0; i < obj.tbGmCtrlGiveCtrlData_List.GetSize(); ++i) {
		const ::proto_ff::tbGmCtrlGiveCtrlData & temp_tbgmctrlgivectrldata_list = msg.tbgmctrlgivectrldata_list(i);
		tbGmCtrlGiveCtrlData_s::read_from_pbmsg(temp_tbgmctrlgivectrldata_list, obj.tbGmCtrlGiveCtrlData_List[i]);
	}
}

LogVipRechargeRecord_s::LogVipRechargeRecord_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int LogVipRechargeRecord_s::CreateInit() {
	event_id = (uint64_t)0;
	sequence = (uint32_t)0;
	user_id = (uint64_t)0;
	amount = (uint64_t)0;
	recharge_id = (uint32_t)0;
	status = (uint64_t)0;
	return 0;
}

int LogVipRechargeRecord_s::ResumeInit() {
	return 0;
}

void LogVipRechargeRecord_s::write_to_pbmsg(const struct LogVipRechargeRecord_s & obj, ::proto_ff::LogVipRechargeRecord & msg) {
	msg.set_event_id((uint64_t)obj.event_id);
	msg.set_sequence((uint32_t)obj.sequence);
	msg.set_bus_name((const char*)obj.bus_name.Get());
	msg.set_event_time((const char*)obj.event_time.Get());
	msg.set_user_id((uint64_t)obj.user_id);
	msg.set_user_name((const char*)obj.user_name.Get());
	msg.set_amount((uint64_t)obj.amount);
	msg.set_recharge_id((uint32_t)obj.recharge_id);
	msg.set_recharge_name((const char*)obj.recharge_name.Get());
	msg.set_status((uint64_t)obj.status);
}

void LogVipRechargeRecord_s::read_from_pbmsg(const ::proto_ff::LogVipRechargeRecord & msg, struct LogVipRechargeRecord_s & obj) {
	memset(&obj, 0, sizeof(struct LogVipRechargeRecord_s));
	obj.event_id = msg.event_id();
	obj.sequence = msg.sequence();
	obj.bus_name.Copy(msg.bus_name());
	obj.event_time.Copy(msg.event_time());
	obj.user_id = msg.user_id();
	obj.user_name.Copy(msg.user_name());
	obj.amount = msg.amount();
	obj.recharge_id = msg.recharge_id();
	obj.recharge_name.Copy(msg.recharge_name());
	obj.status = msg.status();
}

LogZhuangRecord_s::LogZhuangRecord_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int LogZhuangRecord_s::CreateInit() {
	event_id = (uint64_t)0;
	sequence = (uint32_t)0;
	user_id = (uint64_t)0;
	amount = (int64_t)0;
	status = (uint64_t)0;
	return 0;
}

int LogZhuangRecord_s::ResumeInit() {
	return 0;
}

void LogZhuangRecord_s::write_to_pbmsg(const struct LogZhuangRecord_s & obj, ::proto_ff::LogZhuangRecord & msg) {
	msg.set_event_id((uint64_t)obj.event_id);
	msg.set_sequence((uint32_t)obj.sequence);
	msg.set_bus_name((const char*)obj.bus_name.Get());
	msg.set_event_time((const char*)obj.event_time.Get());
	msg.set_user_id((uint64_t)obj.user_id);
	msg.set_user_name((const char*)obj.user_name.Get());
	msg.set_amount((int64_t)obj.amount);
	msg.set_status((uint64_t)obj.status);
}

void LogZhuangRecord_s::read_from_pbmsg(const ::proto_ff::LogZhuangRecord & msg, struct LogZhuangRecord_s & obj) {
	memset(&obj, 0, sizeof(struct LogZhuangRecord_s));
	obj.event_id = msg.event_id();
	obj.sequence = msg.sequence();
	obj.bus_name.Copy(msg.bus_name());
	obj.event_time.Copy(msg.event_time());
	obj.user_id = msg.user_id();
	obj.user_name.Copy(msg.user_name());
	obj.amount = msg.amount();
	obj.status = msg.status();
}

LogRechargeOrder_s::LogRechargeOrder_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int LogRechargeOrder_s::CreateInit() {
	event_id = (uint64_t)0;
	sequence = (uint32_t)0;
	user_id = (uint64_t)0;
	pay_id = (uint32_t)0;
	pay_type = (uint32_t)0;
	state = (uint32_t)0;
	return 0;
}

int LogRechargeOrder_s::ResumeInit() {
	return 0;
}

void LogRechargeOrder_s::write_to_pbmsg(const struct LogRechargeOrder_s & obj, ::proto_ff::LogRechargeOrder & msg) {
	msg.set_event_id((uint64_t)obj.event_id);
	msg.set_sequence((uint32_t)obj.sequence);
	msg.set_bus_name((const char*)obj.bus_name.Get());
	msg.set_event_time((const char*)obj.event_time.Get());
	msg.set_user_id((uint64_t)obj.user_id);
	msg.set_user_name((const char*)obj.user_name.Get());
	msg.set_order_id((const char*)obj.order_id.Get());
	msg.set_pay_id((uint32_t)obj.pay_id);
	msg.set_pay_channel((const char*)obj.pay_channel.Get());
	msg.set_pay_type((uint32_t)obj.pay_type);
	msg.set_ch_order_id((const char*)obj.ch_order_id.Get());
	msg.set_state((uint32_t)obj.state);
}

void LogRechargeOrder_s::read_from_pbmsg(const ::proto_ff::LogRechargeOrder & msg, struct LogRechargeOrder_s & obj) {
	memset(&obj, 0, sizeof(struct LogRechargeOrder_s));
	obj.event_id = msg.event_id();
	obj.sequence = msg.sequence();
	obj.bus_name.Copy(msg.bus_name());
	obj.event_time.Copy(msg.event_time());
	obj.user_id = msg.user_id();
	obj.user_name.Copy(msg.user_name());
	obj.order_id.Copy(msg.order_id());
	obj.pay_id = msg.pay_id();
	obj.pay_channel.Copy(msg.pay_channel());
	obj.pay_type = msg.pay_type();
	obj.ch_order_id.Copy(msg.ch_order_id());
	obj.state = msg.state();
}

LogGiveMoneyRecord_s::LogGiveMoneyRecord_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int LogGiveMoneyRecord_s::CreateInit() {
	event_id = (uint64_t)0;
	sequence = (uint32_t)0;
	user_id = (uint64_t)0;
	type = (uint32_t)0;
	amount = (uint64_t)0;
	status = (uint64_t)0;
	return 0;
}

int LogGiveMoneyRecord_s::ResumeInit() {
	return 0;
}

void LogGiveMoneyRecord_s::write_to_pbmsg(const struct LogGiveMoneyRecord_s & obj, ::proto_ff::LogGiveMoneyRecord & msg) {
	msg.set_event_id((uint64_t)obj.event_id);
	msg.set_sequence((uint32_t)obj.sequence);
	msg.set_bus_name((const char*)obj.bus_name.Get());
	msg.set_event_time((const char*)obj.event_time.Get());
	msg.set_user_id((uint64_t)obj.user_id);
	msg.set_user_name((const char*)obj.user_name.Get());
	msg.set_type((uint32_t)obj.type);
	msg.set_amount((uint64_t)obj.amount);
	msg.set_status((uint64_t)obj.status);
}

void LogGiveMoneyRecord_s::read_from_pbmsg(const ::proto_ff::LogGiveMoneyRecord & msg, struct LogGiveMoneyRecord_s & obj) {
	memset(&obj, 0, sizeof(struct LogGiveMoneyRecord_s));
	obj.event_id = msg.event_id();
	obj.sequence = msg.sequence();
	obj.bus_name.Copy(msg.bus_name());
	obj.event_time.Copy(msg.event_time());
	obj.user_id = msg.user_id();
	obj.user_name.Copy(msg.user_name());
	obj.type = msg.type();
	obj.amount = msg.amount();
	obj.status = msg.status();
}

tbLogSystemDay_s::tbLogSystemDay_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int tbLogSystemDay_s::CreateInit() {
	active_player = (uint32_t)0;
	login_count = (uint32_t)0;
	valid_player = (uint32_t)0;
	new_player = (uint32_t)0;
	pay_player = (uint32_t)0;
	pay_times = (uint32_t)0;
	pay_all = (uint64_t)0;
	new_pay_player = (uint32_t)0;
	new_pay_all = (uint32_t)0;
	commission_all = (uint64_t)0;
	all_fee = (uint64_t)0;
	all_pour = (uint64_t)0;
	all_win = (int64_t)0;
	jetton_init = (uint64_t)0;
	all_draw = (uint64_t)0;
	jetton_in = (uint64_t)0;
	jetton_out = (uint64_t)0;
	sys_award = (uint64_t)0;
	player_jetton = (uint64_t)0;
	trd_pay_all = (uint64_t)0;
	vip_pay_all = (uint64_t)0;
	zhuangzhang_all = (uint64_t)0;
	activity_award = (uint64_t)0;
	all_bank_jetton = (uint64_t)0;
	freeze_jetton = (uint64_t)0;
	all_jetton = (uint64_t)0;
	all_player = (uint64_t)0;
	active_seven = (uint64_t)0;
	active_thirty = (uint64_t)0;
	pour_day_all = (uint64_t)0;
	pour_week_all = (uint64_t)0;
	pour_month_all = (uint64_t)0;
	sys_win_day = (int64_t)0;
	sys_win_week = (int64_t)0;
	sys_win_month = (int64_t)0;
	fee_day = (uint64_t)0;
	fee_week = (uint64_t)0;
	fee_month = (uint64_t)0;
	commision_all = (uint64_t)0;
	commision_take = (uint64_t)0;
	commision_day = (uint64_t)0;
	commision_week = (uint64_t)0;
	commision_month = (uint64_t)0;
	max_online = (uint64_t)0;
	win_cost_value = (uint64_t)0;
	day_money_value = (uint64_t)0;
	pay_day = (uint64_t)0;
	pay_week = (uint64_t)0;
	pay_month = (uint64_t)0;
	draw_day = (uint64_t)0;
	draw_week = (uint64_t)0;
	draw_month = (uint64_t)0;
	trd_pay_day = (uint64_t)0;
	trd_pay_week = (uint64_t)0;
	trd_pay_month = (uint64_t)0;
	vip_pay_day = (uint64_t)0;
	vip_pay_week = (uint64_t)0;
	vip_pay_month = (uint64_t)0;
	zhuangzhang_day = (uint64_t)0;
	zhuangzhang_week = (uint64_t)0;
	zhuangzhang_month = (uint64_t)0;
	give_day = (uint64_t)0;
	give_week = (uint64_t)0;
	give_month = (uint64_t)0;
	all_give = (uint64_t)0;
	all_vip_zhuanru = (uint64_t)0;
	today_vip_zhuanru = (uint64_t)0;
	week_vip_zhuanru = (uint64_t)0;
	month_vip_zhuanru = (uint64_t)0;
	all_vip_zhuanchu = (uint64_t)0;
	today_vip_zhuanchu = (uint64_t)0;
	week_vip_zhuanchu = (uint64_t)0;
	month_vip_zhuanchu = (uint64_t)0;
	return 0;
}

int tbLogSystemDay_s::ResumeInit() {
	return 0;
}

void tbLogSystemDay_s::write_to_pbmsg(const struct tbLogSystemDay_s & obj, ::proto_ff::tbLogSystemDay & msg) {
	msg.set_date_id((const char*)obj.date_id.Get());
	msg.set_active_player((uint32_t)obj.active_player);
	msg.set_login_count((uint32_t)obj.login_count);
	msg.set_valid_player((uint32_t)obj.valid_player);
	msg.set_new_player((uint32_t)obj.new_player);
	msg.set_pay_player((uint32_t)obj.pay_player);
	msg.set_pay_times((uint32_t)obj.pay_times);
	msg.set_pay_all((uint64_t)obj.pay_all);
	msg.set_new_pay_player((uint32_t)obj.new_pay_player);
	msg.set_new_pay_all((uint32_t)obj.new_pay_all);
	msg.set_commission_all((uint64_t)obj.commission_all);
	msg.set_all_fee((uint64_t)obj.all_fee);
	msg.set_all_pour((uint64_t)obj.all_pour);
	msg.set_all_win((int64_t)obj.all_win);
	msg.set_jetton_init((uint64_t)obj.jetton_init);
	msg.set_all_draw((uint64_t)obj.all_draw);
	msg.set_jetton_in((uint64_t)obj.jetton_in);
	msg.set_jetton_out((uint64_t)obj.jetton_out);
	msg.set_sys_award((uint64_t)obj.sys_award);
	msg.set_player_jetton((uint64_t)obj.player_jetton);
	msg.set_trd_pay_all((uint64_t)obj.trd_pay_all);
	msg.set_vip_pay_all((uint64_t)obj.vip_pay_all);
	msg.set_zhuangzhang_all((uint64_t)obj.zhuangzhang_all);
	msg.set_activity_award((uint64_t)obj.activity_award);
	msg.set_all_bank_jetton((uint64_t)obj.all_bank_jetton);
	msg.set_freeze_jetton((uint64_t)obj.freeze_jetton);
	msg.set_all_jetton((uint64_t)obj.all_jetton);
	msg.set_all_player((uint64_t)obj.all_player);
	msg.set_active_seven((uint64_t)obj.active_seven);
	msg.set_active_thirty((uint64_t)obj.active_thirty);
	msg.set_pour_day_all((uint64_t)obj.pour_day_all);
	msg.set_pour_week_all((uint64_t)obj.pour_week_all);
	msg.set_pour_month_all((uint64_t)obj.pour_month_all);
	msg.set_sys_win_day((int64_t)obj.sys_win_day);
	msg.set_sys_win_week((int64_t)obj.sys_win_week);
	msg.set_sys_win_month((int64_t)obj.sys_win_month);
	msg.set_fee_day((uint64_t)obj.fee_day);
	msg.set_fee_week((uint64_t)obj.fee_week);
	msg.set_fee_month((uint64_t)obj.fee_month);
	msg.set_commision_all((uint64_t)obj.commision_all);
	msg.set_commision_take((uint64_t)obj.commision_take);
	msg.set_commision_day((uint64_t)obj.commision_day);
	msg.set_commision_week((uint64_t)obj.commision_week);
	msg.set_commision_month((uint64_t)obj.commision_month);
	msg.set_max_online((uint64_t)obj.max_online);
	msg.set_win_cost_value((uint64_t)obj.win_cost_value);
	msg.set_day_money_value((uint64_t)obj.day_money_value);
	msg.set_pay_day((uint64_t)obj.pay_day);
	msg.set_pay_week((uint64_t)obj.pay_week);
	msg.set_pay_month((uint64_t)obj.pay_month);
	msg.set_draw_day((uint64_t)obj.draw_day);
	msg.set_draw_week((uint64_t)obj.draw_week);
	msg.set_draw_month((uint64_t)obj.draw_month);
	msg.set_trd_pay_day((uint64_t)obj.trd_pay_day);
	msg.set_trd_pay_week((uint64_t)obj.trd_pay_week);
	msg.set_trd_pay_month((uint64_t)obj.trd_pay_month);
	msg.set_vip_pay_day((uint64_t)obj.vip_pay_day);
	msg.set_vip_pay_week((uint64_t)obj.vip_pay_week);
	msg.set_vip_pay_month((uint64_t)obj.vip_pay_month);
	msg.set_zhuangzhang_day((uint64_t)obj.zhuangzhang_day);
	msg.set_zhuangzhang_week((uint64_t)obj.zhuangzhang_week);
	msg.set_zhuangzhang_month((uint64_t)obj.zhuangzhang_month);
	msg.set_give_day((uint64_t)obj.give_day);
	msg.set_give_week((uint64_t)obj.give_week);
	msg.set_give_month((uint64_t)obj.give_month);
	msg.set_all_give((uint64_t)obj.all_give);
	msg.set_all_vip_zhuanru((uint64_t)obj.all_vip_zhuanru);
	msg.set_today_vip_zhuanru((uint64_t)obj.today_vip_zhuanru);
	msg.set_week_vip_zhuanru((uint64_t)obj.week_vip_zhuanru);
	msg.set_month_vip_zhuanru((uint64_t)obj.month_vip_zhuanru);
	msg.set_all_vip_zhuanchu((uint64_t)obj.all_vip_zhuanchu);
	msg.set_today_vip_zhuanchu((uint64_t)obj.today_vip_zhuanchu);
	msg.set_week_vip_zhuanchu((uint64_t)obj.week_vip_zhuanchu);
	msg.set_month_vip_zhuanchu((uint64_t)obj.month_vip_zhuanchu);
}

void tbLogSystemDay_s::read_from_pbmsg(const ::proto_ff::tbLogSystemDay & msg, struct tbLogSystemDay_s & obj) {
	memset(&obj, 0, sizeof(struct tbLogSystemDay_s));
	obj.date_id.Copy(msg.date_id());
	obj.active_player = msg.active_player();
	obj.login_count = msg.login_count();
	obj.valid_player = msg.valid_player();
	obj.new_player = msg.new_player();
	obj.pay_player = msg.pay_player();
	obj.pay_times = msg.pay_times();
	obj.pay_all = msg.pay_all();
	obj.new_pay_player = msg.new_pay_player();
	obj.new_pay_all = msg.new_pay_all();
	obj.commission_all = msg.commission_all();
	obj.all_fee = msg.all_fee();
	obj.all_pour = msg.all_pour();
	obj.all_win = msg.all_win();
	obj.jetton_init = msg.jetton_init();
	obj.all_draw = msg.all_draw();
	obj.jetton_in = msg.jetton_in();
	obj.jetton_out = msg.jetton_out();
	obj.sys_award = msg.sys_award();
	obj.player_jetton = msg.player_jetton();
	obj.trd_pay_all = msg.trd_pay_all();
	obj.vip_pay_all = msg.vip_pay_all();
	obj.zhuangzhang_all = msg.zhuangzhang_all();
	obj.activity_award = msg.activity_award();
	obj.all_bank_jetton = msg.all_bank_jetton();
	obj.freeze_jetton = msg.freeze_jetton();
	obj.all_jetton = msg.all_jetton();
	obj.all_player = msg.all_player();
	obj.active_seven = msg.active_seven();
	obj.active_thirty = msg.active_thirty();
	obj.pour_day_all = msg.pour_day_all();
	obj.pour_week_all = msg.pour_week_all();
	obj.pour_month_all = msg.pour_month_all();
	obj.sys_win_day = msg.sys_win_day();
	obj.sys_win_week = msg.sys_win_week();
	obj.sys_win_month = msg.sys_win_month();
	obj.fee_day = msg.fee_day();
	obj.fee_week = msg.fee_week();
	obj.fee_month = msg.fee_month();
	obj.commision_all = msg.commision_all();
	obj.commision_take = msg.commision_take();
	obj.commision_day = msg.commision_day();
	obj.commision_week = msg.commision_week();
	obj.commision_month = msg.commision_month();
	obj.max_online = msg.max_online();
	obj.win_cost_value = msg.win_cost_value();
	obj.day_money_value = msg.day_money_value();
	obj.pay_day = msg.pay_day();
	obj.pay_week = msg.pay_week();
	obj.pay_month = msg.pay_month();
	obj.draw_day = msg.draw_day();
	obj.draw_week = msg.draw_week();
	obj.draw_month = msg.draw_month();
	obj.trd_pay_day = msg.trd_pay_day();
	obj.trd_pay_week = msg.trd_pay_week();
	obj.trd_pay_month = msg.trd_pay_month();
	obj.vip_pay_day = msg.vip_pay_day();
	obj.vip_pay_week = msg.vip_pay_week();
	obj.vip_pay_month = msg.vip_pay_month();
	obj.zhuangzhang_day = msg.zhuangzhang_day();
	obj.zhuangzhang_week = msg.zhuangzhang_week();
	obj.zhuangzhang_month = msg.zhuangzhang_month();
	obj.give_day = msg.give_day();
	obj.give_week = msg.give_week();
	obj.give_month = msg.give_month();
	obj.all_give = msg.all_give();
	obj.all_vip_zhuanru = msg.all_vip_zhuanru();
	obj.today_vip_zhuanru = msg.today_vip_zhuanru();
	obj.week_vip_zhuanru = msg.week_vip_zhuanru();
	obj.month_vip_zhuanru = msg.month_vip_zhuanru();
	obj.all_vip_zhuanchu = msg.all_vip_zhuanchu();
	obj.today_vip_zhuanchu = msg.today_vip_zhuanchu();
	obj.week_vip_zhuanchu = msg.week_vip_zhuanchu();
	obj.month_vip_zhuanchu = msg.month_vip_zhuanchu();
}

tbRedeemCode_s::tbRedeemCode_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int tbRedeemCode_s::CreateInit() {
	gold = (uint64_t)0;
	create_time = (uint64_t)0;
	state = (uint32_t)0;
	user_id = (uint64_t)0;
	use_time = (uint64_t)0;
	return 0;
}

int tbRedeemCode_s::ResumeInit() {
	return 0;
}

void tbRedeemCode_s::write_to_pbmsg(const struct tbRedeemCode_s & obj, ::proto_ff::tbRedeemCode & msg) {
	msg.set_id((const char*)obj.id.Get());
	msg.set_gold((uint64_t)obj.gold);
	msg.set_create_time((uint64_t)obj.create_time);
	msg.set_code_name((const char*)obj.code_name.Get());
	msg.set_state((uint32_t)obj.state);
	msg.set_user_id((uint64_t)obj.user_id);
	msg.set_use_time((uint64_t)obj.use_time);
}

void tbRedeemCode_s::read_from_pbmsg(const ::proto_ff::tbRedeemCode & msg, struct tbRedeemCode_s & obj) {
	memset(&obj, 0, sizeof(struct tbRedeemCode_s));
	obj.id.Copy(msg.id());
	obj.gold = msg.gold();
	obj.create_time = msg.create_time();
	obj.code_name.Copy(msg.code_name());
	obj.state = msg.state();
	obj.user_id = msg.user_id();
	obj.use_time = msg.use_time();
}

LogRedeemCodeRechargeRecord_s::LogRedeemCodeRechargeRecord_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int LogRedeemCodeRechargeRecord_s::CreateInit() {
	event_id = (uint64_t)0;
	sequence = (uint32_t)0;
	user_id = (uint64_t)0;
	amount = (uint64_t)0;
	status = (uint64_t)0;
	return 0;
}

int LogRedeemCodeRechargeRecord_s::ResumeInit() {
	return 0;
}

void LogRedeemCodeRechargeRecord_s::write_to_pbmsg(const struct LogRedeemCodeRechargeRecord_s & obj, ::proto_ff::LogRedeemCodeRechargeRecord & msg) {
	msg.set_event_id((uint64_t)obj.event_id);
	msg.set_sequence((uint32_t)obj.sequence);
	msg.set_bus_name((const char*)obj.bus_name.Get());
	msg.set_event_time((const char*)obj.event_time.Get());
	msg.set_user_id((uint64_t)obj.user_id);
	msg.set_user_name((const char*)obj.user_name.Get());
	msg.set_amount((uint64_t)obj.amount);
	msg.set_status((uint64_t)obj.status);
}

void LogRedeemCodeRechargeRecord_s::read_from_pbmsg(const ::proto_ff::LogRedeemCodeRechargeRecord & msg, struct LogRedeemCodeRechargeRecord_s & obj) {
	memset(&obj, 0, sizeof(struct LogRedeemCodeRechargeRecord_s));
	obj.event_id = msg.event_id();
	obj.sequence = msg.sequence();
	obj.bus_name.Copy(msg.bus_name());
	obj.event_time.Copy(msg.event_time());
	obj.user_id = msg.user_id();
	obj.user_name.Copy(msg.user_name());
	obj.amount = msg.amount();
	obj.status = msg.status();
}

GameRoomStat_s::GameRoomStat_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int GameRoomStat_s::CreateInit() {
	cur_fee = (uint64_t)0;
	cur_pour = (uint64_t)0;
	cur_win = (int64_t)0;
	return 0;
}

int GameRoomStat_s::ResumeInit() {
	return 0;
}

void GameRoomStat_s::write_to_pbmsg(const struct GameRoomStat_s & obj, ::proto_ff::GameRoomStat & msg) {
	msg.set_cur_fee((uint64_t)obj.cur_fee);
	msg.set_cur_pour((uint64_t)obj.cur_pour);
	msg.set_cur_win((int64_t)obj.cur_win);
}

void GameRoomStat_s::read_from_pbmsg(const ::proto_ff::GameRoomStat & msg, struct GameRoomStat_s & obj) {
	memset(&obj, 0, sizeof(struct GameRoomStat_s));
	obj.cur_fee = msg.cur_fee();
	obj.cur_pour = msg.cur_pour();
	obj.cur_win = msg.cur_win();
}

GamePlayerPourInfo_s::GamePlayerPourInfo_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int GamePlayerPourInfo_s::CreateInit() {
	user_id = (uint64_t)0;
	pour = (int64_t)0;
	return 0;
}

int GamePlayerPourInfo_s::ResumeInit() {
	return 0;
}

void GamePlayerPourInfo_s::write_to_pbmsg(const struct GamePlayerPourInfo_s & obj, ::proto_ff::GamePlayerPourInfo & msg) {
	msg.set_user_id((uint64_t)obj.user_id);
	msg.set_pour((int64_t)obj.pour);
}

void GamePlayerPourInfo_s::read_from_pbmsg(const ::proto_ff::GamePlayerPourInfo & msg, struct GamePlayerPourInfo_s & obj) {
	memset(&obj, 0, sizeof(struct GamePlayerPourInfo_s));
	obj.user_id = msg.user_id();
	obj.pour = msg.pour();
}

GameTablePourInfo_s::GameTablePourInfo_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int GameTablePourInfo_s::CreateInit() {
	return 0;
}

int GameTablePourInfo_s::ResumeInit() {
	return 0;
}

void GameTablePourInfo_s::write_to_pbmsg(const struct GameTablePourInfo_s & obj, ::proto_ff::GameTablePourInfo & msg) {
}

void GameTablePourInfo_s::read_from_pbmsg(const ::proto_ff::GameTablePourInfo & msg, struct GameTablePourInfo_s & obj) {
	memset(&obj, 0, sizeof(struct GameTablePourInfo_s));
}

}