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

tbFishSnsPlayerSimpleData_s::tbFishSnsPlayerSimpleData_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int tbFishSnsPlayerSimpleData_s::CreateInit() {
	player_id = (uint64_t)0;
	faceid = (uint32_t)0;
	last_login_time = (uint64_t)0;
	last_logout_time = (uint64_t)0;
	agent = (uint64_t)0;
	return 0;
}

int tbFishSnsPlayerSimpleData_s::ResumeInit() {
	return 0;
}

void tbFishSnsPlayerSimpleData_s::write_to_pbmsg(::proto_ff::tbFishSnsPlayerSimpleData & msg) const {
	msg.set_player_id((uint64_t)player_id);
	msg.set_nickname((const char*)nickname.data());
	msg.set_faceid((uint32_t)faceid);
	msg.set_last_login_time((uint64_t)last_login_time);
	msg.set_last_logout_time((uint64_t)last_logout_time);
	msg.set_agent((uint64_t)agent);
}

void tbFishSnsPlayerSimpleData_s::read_from_pbmsg(const ::proto_ff::tbFishSnsPlayerSimpleData & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct tbFishSnsPlayerSimpleData_s));
	player_id = msg.player_id();
	nickname = msg.nickname();
	faceid = msg.faceid();
	last_login_time = msg.last_login_time();
	last_logout_time = msg.last_logout_time();
	agent = msg.agent();
}

tbFishSnsPlayerDetailData_s::tbFishSnsPlayerDetailData_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int tbFishSnsPlayerDetailData_s::CreateInit() {
	player_id = (uint64_t)0;
	bank_jetton = (uint64_t)0;
	return 0;
}

int tbFishSnsPlayerDetailData_s::ResumeInit() {
	return 0;
}

void tbFishSnsPlayerDetailData_s::write_to_pbmsg(::proto_ff::tbFishSnsPlayerDetailData & msg) const {
	msg.set_player_id((uint64_t)player_id);
	msg.set_bank_jetton((uint64_t)bank_jetton);
	msg.set_bank_password((const char*)bank_password.data());
}

void tbFishSnsPlayerDetailData_s::read_from_pbmsg(const ::proto_ff::tbFishSnsPlayerDetailData & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct tbFishSnsPlayerDetailData_s));
	player_id = msg.player_id();
	bank_jetton = msg.bank_jetton();
	bank_password = msg.bank_password();
}

}