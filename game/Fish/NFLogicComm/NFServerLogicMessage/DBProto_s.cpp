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
	msg.set_phonenum((uint64_t)phonenum);
	msg.set_jetton((uint64_t)jetton);
	msg.set_ip((const char*)ip.data());
	msg.set_last_login_time((uint64_t)last_login_time);
	msg.set_last_logout_time((uint64_t)last_logout_time);
}

void tbFishPlayerData_s::read_from_pbmsg(const ::proto_ff::tbFishPlayerData & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct tbFishPlayerData_s));
	player_id = msg.player_id();
	nickname = msg.nickname();
	faceid = msg.faceid();
	regdate = msg.regdate();
	gender = msg.gender();
	age = msg.age();
	phonenum = msg.phonenum();
	jetton = msg.jetton();
	ip = msg.ip();
	last_login_time = msg.last_login_time();
	last_logout_time = msg.last_logout_time();
}

}