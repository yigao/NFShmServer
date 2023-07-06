#include "DBProto_s.h"

namespace proto_ff_s {

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
	return 0;
}

int tbAccountTable_s::ResumeInit() {
	return 0;
}

void tbAccountTable_s::write_to_pbmsg(::proto_ff::tbAccountTable & msg) const {
	msg.set_player_id((uint64_t)player_id);
	msg.set_account((const char*)account.data());
	msg.set_password((const char*)password.data());
	msg.set_account_type((uint32_t)account_type);
	msg.set_device_id((const char*)device_id.data());
	msg.set_phonenum((uint64_t)phonenum);
}

void tbAccountTable_s::read_from_pbmsg(const ::proto_ff::tbAccountTable & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct tbAccountTable_s));
	player_id = msg.player_id();
	account = msg.account();
	password = msg.password();
	account_type = msg.account_type();
	device_id = msg.device_id();
	phonenum = msg.phonenum();
}

}