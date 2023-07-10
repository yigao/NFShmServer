#include "DBProto_s.h"

namespace proto_ff_s {

tbFishAccountTable_s::tbFishAccountTable_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int tbFishAccountTable_s::CreateInit() {
	player_id = (uint64_t)0;
	account_type = (uint32_t)0;
	phonenum = (uint64_t)0;
	return 0;
}

int tbFishAccountTable_s::ResumeInit() {
	return 0;
}

void tbFishAccountTable_s::write_to_pbmsg(::proto_ff::tbFishAccountTable & msg) const {
	msg.set_player_id((uint64_t)player_id);
	msg.set_account((const char*)account.data());
	msg.set_password((const char*)password.data());
	msg.set_account_type((uint32_t)account_type);
	msg.set_device_id((const char*)device_id.data());
	msg.set_phonenum((uint64_t)phonenum);
}

void tbFishAccountTable_s::read_from_pbmsg(const ::proto_ff::tbFishAccountTable & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct tbFishAccountTable_s));
	player_id = msg.player_id();
	account = msg.account();
	password = msg.password();
	account_type = msg.account_type();
	device_id = msg.device_id();
	phonenum = msg.phonenum();
}

tbFishPlayerData_s::tbFishPlayerData_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int tbFishPlayerData_s::CreateInit() {
	player_id = (uint64_t)0;
	faceid = (uint32_t)0;
	regdate = (uint64_t)0;
	gender = (uint32_t)0;
	age = (uint32_t)0;
	phonenum = (uint64_t)0;
	jetton = (uint64_t)0;
	last_login_time = (uint64_t)0;
	last_logout_time = (uint64_t)0;
	channel_id = (uint32_t)0;
	first_recharge = (bool)0;
	vip_level = (uint32_t)0;
	game_id = (uint32_t)0;
	room_id = (uint32_t)0;
	is_ban = (uint32_t)0;
	no_transfer = (uint32_t)0;
	return 0;
}

int tbFishPlayerData_s::ResumeInit() {
	return 0;
}

void tbFishPlayerData_s::write_to_pbmsg(::proto_ff::tbFishPlayerData & msg) const {
	msg.set_player_id((uint64_t)player_id);
	msg.set_nickname((const char*)nickname.data());
	msg.set_faceid((uint32_t)faceid);
	msg.set_regdate((uint64_t)regdate);
	msg.set_gender((uint32_t)gender);
	msg.set_age((uint32_t)age);
	msg.set_email((const char*)email.data());
	msg.set_phonenum((uint64_t)phonenum);
	msg.set_jetton((uint64_t)jetton);
	msg.set_ip((const char*)ip.data());
	msg.set_last_login_time((uint64_t)last_login_time);
	msg.set_last_logout_time((uint64_t)last_logout_time);
	msg.set_channel_id((uint32_t)channel_id);
	msg.set_platform_os((const char*)platform_os.data());
	msg.set_phone_model((const char*)phone_model.data());
	msg.set_first_recharge((bool)first_recharge);
	msg.set_vip_level((uint32_t)vip_level);
	msg.set_game_id((uint32_t)game_id);
	msg.set_room_id((uint32_t)room_id);
	msg.set_is_ban((uint32_t)is_ban);
	msg.set_no_transfer((uint32_t)no_transfer);
	msg.set_reg_ip((const char*)reg_ip.data());
	msg.set_device_id((const char*)device_id.data());
	msg.set_reg_device_id((const char*)reg_device_id.data());
}

void tbFishPlayerData_s::read_from_pbmsg(const ::proto_ff::tbFishPlayerData & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct tbFishPlayerData_s));
	player_id = msg.player_id();
	nickname = msg.nickname();
	faceid = msg.faceid();
	regdate = msg.regdate();
	gender = msg.gender();
	age = msg.age();
	email = msg.email();
	phonenum = msg.phonenum();
	jetton = msg.jetton();
	ip = msg.ip();
	last_login_time = msg.last_login_time();
	last_logout_time = msg.last_logout_time();
	channel_id = msg.channel_id();
	platform_os = msg.platform_os();
	phone_model = msg.phone_model();
	first_recharge = msg.first_recharge();
	vip_level = msg.vip_level();
	game_id = msg.game_id();
	room_id = msg.room_id();
	is_ban = msg.is_ban();
	no_transfer = msg.no_transfer();
	reg_ip = msg.reg_ip();
	device_id = msg.device_id();
	reg_device_id = msg.reg_device_id();
}

}