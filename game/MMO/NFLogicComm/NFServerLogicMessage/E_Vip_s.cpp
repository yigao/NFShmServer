#include "E_Vip_s.h"

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
	m_dailybox = (int32_t)0;
	m_vipgift = (int32_t)0;
	m_pricetype = (int32_t)0;
	m_originalprice = (int32_t)0;
	m_price = (int32_t)0;
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
	msg.set_m_dailybox((int32_t)m_dailybox);
	msg.set_m_vipgift((int32_t)m_vipgift);
	msg.set_m_pricetype((int32_t)m_pricetype);
	msg.set_m_originalprice((int32_t)m_originalprice);
	msg.set_m_price((int32_t)m_price);
}

void E_VipVip_s::read_from_pbmsg(const ::proto_ff::E_VipVip & msg) {
	m_id = msg.m_id();
	m_level = msg.m_level();
	m_exp = msg.m_exp();
	m_privilege_group = msg.m_privilege_group();
	m_dailybox = msg.m_dailybox();
	m_vipgift = msg.m_vipgift();
	m_pricetype = msg.m_pricetype();
	m_originalprice = msg.m_originalprice();
	m_price = msg.m_price();
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
	msg.set_m_args(m_args.data());
}

void E_VipPrivilege_s::read_from_pbmsg(const ::proto_ff::E_VipPrivilege & msg) {
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
	E_VipPrivilege_List.resize((int)msg.e_vipprivilege_list_size() > (int)E_VipPrivilege_List.max_size() ? E_VipPrivilege_List.max_size() : msg.e_vipprivilege_list_size());
	for(int32_t i = 0; i < (int32_t)E_VipPrivilege_List.size(); ++i) {
		const ::proto_ff::E_VipPrivilege & temp_e_vipprivilege_list = msg.e_vipprivilege_list(i);
		E_VipPrivilege_List[i].read_from_pbmsg(temp_e_vipprivilege_list);
	}
}

E_VipChat_s::E_VipChat_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_VipChat_s::CreateInit() {
	m_id = (int32_t)0;
	return 0;
}

int E_VipChat_s::ResumeInit() {
	return 0;
}

void E_VipChat_s::write_to_pbmsg(::proto_ff::E_VipChat & msg) const {
	msg.set_m_id((int32_t)m_id);
}

void E_VipChat_s::read_from_pbmsg(const ::proto_ff::E_VipChat & msg) {
	m_id = msg.m_id();
}

Sheet_VipChat_s::Sheet_VipChat_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_VipChat_s::CreateInit() {
	return 0;
}

int Sheet_VipChat_s::ResumeInit() {
	return 0;
}

void Sheet_VipChat_s::write_to_pbmsg(::proto_ff::Sheet_VipChat & msg) const {
	for(int32_t i = 0; i < (int32_t)E_VipChat_List.size(); ++i) {
		::proto_ff::E_VipChat* temp_e_vipchat_list = msg.add_e_vipchat_list();
		E_VipChat_List[i].write_to_pbmsg(*temp_e_vipchat_list);
	}
}

void Sheet_VipChat_s::read_from_pbmsg(const ::proto_ff::Sheet_VipChat & msg) {
	E_VipChat_List.resize((int)msg.e_vipchat_list_size() > (int)E_VipChat_List.max_size() ? E_VipChat_List.max_size() : msg.e_vipchat_list_size());
	for(int32_t i = 0; i < (int32_t)E_VipChat_List.size(); ++i) {
		const ::proto_ff::E_VipChat & temp_e_vipchat_list = msg.e_vipchat_list(i);
		E_VipChat_List[i].read_from_pbmsg(temp_e_vipchat_list);
	}
}

E_VipCosntant_s::E_VipCosntant_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_VipCosntant_s::CreateInit() {
	m_id = (int32_t)0;
	m_fvipprice = (int32_t)0;
	m_fviprtime = (int32_t)0;
	m_fvipprivage = (int32_t)0;
	m_fviplv = (int32_t)0;
	m_fvipexp = (int32_t)0;
	m_vipitemicon = (int32_t)0;
	m_foreverguide = (int32_t)0;
	m_unactiveguide = (int32_t)0;
	m_vipexp = (int32_t)0;
	return 0;
}

int E_VipCosntant_s::ResumeInit() {
	return 0;
}

void E_VipCosntant_s::write_to_pbmsg(::proto_ff::E_VipCosntant & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_fvipprice((int32_t)m_fvipprice);
	msg.set_m_fviprtime((int32_t)m_fviprtime);
	msg.set_m_fvipprivage((int32_t)m_fvipprivage);
	msg.set_m_fviplv((int32_t)m_fviplv);
	msg.set_m_fvipexp((int32_t)m_fvipexp);
	msg.set_m_vipitemicon((int32_t)m_vipitemicon);
	msg.set_m_foreverguide((int32_t)m_foreverguide);
	msg.set_m_unactiveguide((int32_t)m_unactiveguide);
	msg.set_m_vipexp((int32_t)m_vipexp);
}

void E_VipCosntant_s::read_from_pbmsg(const ::proto_ff::E_VipCosntant & msg) {
	m_id = msg.m_id();
	m_fvipprice = msg.m_fvipprice();
	m_fviprtime = msg.m_fviprtime();
	m_fvipprivage = msg.m_fvipprivage();
	m_fviplv = msg.m_fviplv();
	m_fvipexp = msg.m_fvipexp();
	m_vipitemicon = msg.m_vipitemicon();
	m_foreverguide = msg.m_foreverguide();
	m_unactiveguide = msg.m_unactiveguide();
	m_vipexp = msg.m_vipexp();
}

Sheet_VipCosntant_s::Sheet_VipCosntant_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_VipCosntant_s::CreateInit() {
	return 0;
}

int Sheet_VipCosntant_s::ResumeInit() {
	return 0;
}

void Sheet_VipCosntant_s::write_to_pbmsg(::proto_ff::Sheet_VipCosntant & msg) const {
	for(int32_t i = 0; i < (int32_t)E_VipCosntant_List.size(); ++i) {
		::proto_ff::E_VipCosntant* temp_e_vipcosntant_list = msg.add_e_vipcosntant_list();
		E_VipCosntant_List[i].write_to_pbmsg(*temp_e_vipcosntant_list);
	}
}

void Sheet_VipCosntant_s::read_from_pbmsg(const ::proto_ff::Sheet_VipCosntant & msg) {
	E_VipCosntant_List.resize((int)msg.e_vipcosntant_list_size() > (int)E_VipCosntant_List.max_size() ? E_VipCosntant_List.max_size() : msg.e_vipcosntant_list_size());
	for(int32_t i = 0; i < (int32_t)E_VipCosntant_List.size(); ++i) {
		const ::proto_ff::E_VipCosntant & temp_e_vipcosntant_list = msg.e_vipcosntant_list(i);
		E_VipCosntant_List[i].read_from_pbmsg(temp_e_vipcosntant_list);
	}
}

E_VipExplimit_s::E_VipExplimit_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_VipExplimit_s::CreateInit() {
	m_lv = (int32_t)0;
	m_limit = (int64_t)0;
	return 0;
}

int E_VipExplimit_s::ResumeInit() {
	return 0;
}

void E_VipExplimit_s::write_to_pbmsg(::proto_ff::E_VipExplimit & msg) const {
	msg.set_m_lv((int32_t)m_lv);
	msg.set_m_limit((int64_t)m_limit);
}

void E_VipExplimit_s::read_from_pbmsg(const ::proto_ff::E_VipExplimit & msg) {
	m_lv = msg.m_lv();
	m_limit = msg.m_limit();
}

Sheet_VipExplimit_s::Sheet_VipExplimit_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_VipExplimit_s::CreateInit() {
	return 0;
}

int Sheet_VipExplimit_s::ResumeInit() {
	return 0;
}

void Sheet_VipExplimit_s::write_to_pbmsg(::proto_ff::Sheet_VipExplimit & msg) const {
	for(int32_t i = 0; i < (int32_t)E_VipExplimit_List.size(); ++i) {
		::proto_ff::E_VipExplimit* temp_e_vipexplimit_list = msg.add_e_vipexplimit_list();
		E_VipExplimit_List[i].write_to_pbmsg(*temp_e_vipexplimit_list);
	}
}

void Sheet_VipExplimit_s::read_from_pbmsg(const ::proto_ff::Sheet_VipExplimit & msg) {
	E_VipExplimit_List.resize((int)msg.e_vipexplimit_list_size() > (int)E_VipExplimit_List.max_size() ? E_VipExplimit_List.max_size() : msg.e_vipexplimit_list_size());
	for(int32_t i = 0; i < (int32_t)E_VipExplimit_List.size(); ++i) {
		const ::proto_ff::E_VipExplimit & temp_e_vipexplimit_list = msg.e_vipexplimit_list(i);
		E_VipExplimit_List[i].read_from_pbmsg(temp_e_vipexplimit_list);
	}
}

}
