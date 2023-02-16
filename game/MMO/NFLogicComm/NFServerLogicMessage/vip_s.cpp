#include "vip_s.h"

namespace proto_ff_s {

E_VipVip_s::E_VipVip_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_VipVip_s::CreateInit() {
	m_id = (int32_t)0;
	m_level = (int32_t)0;
	m_exp = (int32_t)0;
	m_privilege_group = (int32_t)0;
	return 0;
}

int E_VipVip_s::ResumeInit() {
	return 0;
}

void E_VipVip_s::write_to_pbmsg(::proto_ff::E_VipVip & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_level((int32_t)m_level);
	msg.set_m_exp((int32_t)m_exp);
	msg.set_m_privilege_group((int32_t)m_privilege_group);
}

void E_VipVip_s::read_from_pbmsg(const ::proto_ff::E_VipVip & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct E_VipVip_s));
	m_id = msg.m_id();
	m_level = msg.m_level();
	m_exp = msg.m_exp();
	m_privilege_group = msg.m_privilege_group();
}

Sheet_VipVip_s::Sheet_VipVip_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_VipVip_s::CreateInit() {
	return 0;
}

int Sheet_VipVip_s::ResumeInit() {
	return 0;
}

void Sheet_VipVip_s::write_to_pbmsg(::proto_ff::Sheet_VipVip & msg) const {
	for(int32_t i = 0; i < (int32_t)E_VipVip_List.size(); ++i) {
		::proto_ff::E_VipVip* temp_e_vipvip_list = msg.add_e_vipvip_list();
		E_VipVip_List[i].write_to_pbmsg(*temp_e_vipvip_list);
	}
}

void Sheet_VipVip_s::read_from_pbmsg(const ::proto_ff::Sheet_VipVip & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_VipVip_s));
	E_VipVip_List.resize((int)msg.e_vipvip_list_size() > (int)E_VipVip_List.max_size() ? E_VipVip_List.max_size() : msg.e_vipvip_list_size());
	for(int32_t i = 0; i < (int32_t)E_VipVip_List.size(); ++i) {
		const ::proto_ff::E_VipVip & temp_e_vipvip_list = msg.e_vipvip_list(i);
		E_VipVip_List[i].read_from_pbmsg(temp_e_vipvip_list);
	}
}

E_VipPrivilege_s::E_VipPrivilege_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_VipPrivilege_s::CreateInit() {
	m_id = (int32_t)0;
	m_group = (int32_t)0;
	m_type = (int32_t)0;
	m_arg = (int32_t)0;
	return 0;
}

int E_VipPrivilege_s::ResumeInit() {
	return 0;
}

void E_VipPrivilege_s::write_to_pbmsg(::proto_ff::E_VipPrivilege & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_group((int32_t)m_group);
	msg.set_m_type((int32_t)m_type);
	msg.set_m_arg((int32_t)m_arg);
	msg.set_m_args((const char*)m_args.data());
}

void E_VipPrivilege_s::read_from_pbmsg(const ::proto_ff::E_VipPrivilege & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct E_VipPrivilege_s));
	m_id = msg.m_id();
	m_group = msg.m_group();
	m_type = msg.m_type();
	m_arg = msg.m_arg();
	m_args = msg.m_args();
}

Sheet_VipPrivilege_s::Sheet_VipPrivilege_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_VipPrivilege_s::CreateInit() {
	return 0;
}

int Sheet_VipPrivilege_s::ResumeInit() {
	return 0;
}

void Sheet_VipPrivilege_s::write_to_pbmsg(::proto_ff::Sheet_VipPrivilege & msg) const {
	for(int32_t i = 0; i < (int32_t)E_VipPrivilege_List.size(); ++i) {
		::proto_ff::E_VipPrivilege* temp_e_vipprivilege_list = msg.add_e_vipprivilege_list();
		E_VipPrivilege_List[i].write_to_pbmsg(*temp_e_vipprivilege_list);
	}
}

void Sheet_VipPrivilege_s::read_from_pbmsg(const ::proto_ff::Sheet_VipPrivilege & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_VipPrivilege_s));
	E_VipPrivilege_List.resize((int)msg.e_vipprivilege_list_size() > (int)E_VipPrivilege_List.max_size() ? E_VipPrivilege_List.max_size() : msg.e_vipprivilege_list_size());
	for(int32_t i = 0; i < (int32_t)E_VipPrivilege_List.size(); ++i) {
		const ::proto_ff::E_VipPrivilege & temp_e_vipprivilege_list = msg.e_vipprivilege_list(i);
		E_VipPrivilege_List[i].read_from_pbmsg(temp_e_vipprivilege_list);
	}
}

}