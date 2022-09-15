#include "proto_common_s.h"

namespace proto_ff_s {

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

}