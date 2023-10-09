#include "godevil_s.h"

namespace proto_ff_s {

E_GodevilPreposetask_s::E_GodevilPreposetask_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_GodevilPreposetask_s::CreateInit() {
	m_id = (int32_t)0;
	m_type = (int32_t)0;
	m_modeltype = (int32_t)0;
	m_starttask = (int32_t)0;
	m_endtask = (int32_t)0;
	m_condition = (int32_t)0;
	m_value = (int32_t)0;
	m_rewardid = (int32_t)0;
	return 0;
}

int E_GodevilPreposetask_s::ResumeInit() {
	return 0;
}

void E_GodevilPreposetask_s::write_to_pbmsg(::proto_ff::E_GodevilPreposetask & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_type((int32_t)m_type);
	msg.set_m_modeltype((int32_t)m_modeltype);
	msg.set_m_starttask((int32_t)m_starttask);
	msg.set_m_endtask((int32_t)m_endtask);
	msg.set_m_condition((int32_t)m_condition);
	msg.set_m_value((int32_t)m_value);
	msg.set_m_rewardid((int32_t)m_rewardid);
}

void E_GodevilPreposetask_s::read_from_pbmsg(const ::proto_ff::E_GodevilPreposetask & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct E_GodevilPreposetask_s));
	m_id = msg.m_id();
	m_type = msg.m_type();
	m_modeltype = msg.m_modeltype();
	m_starttask = msg.m_starttask();
	m_endtask = msg.m_endtask();
	m_condition = msg.m_condition();
	m_value = msg.m_value();
	m_rewardid = msg.m_rewardid();
}

Sheet_GodevilPreposetask_s::Sheet_GodevilPreposetask_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_GodevilPreposetask_s::CreateInit() {
	return 0;
}

int Sheet_GodevilPreposetask_s::ResumeInit() {
	return 0;
}

void Sheet_GodevilPreposetask_s::write_to_pbmsg(::proto_ff::Sheet_GodevilPreposetask & msg) const {
	for(int32_t i = 0; i < (int32_t)E_GodevilPreposetask_List.size(); ++i) {
		::proto_ff::E_GodevilPreposetask* temp_e_godevilpreposetask_list = msg.add_e_godevilpreposetask_list();
		E_GodevilPreposetask_List[i].write_to_pbmsg(*temp_e_godevilpreposetask_list);
	}
}

void Sheet_GodevilPreposetask_s::read_from_pbmsg(const ::proto_ff::Sheet_GodevilPreposetask & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_GodevilPreposetask_s));
	E_GodevilPreposetask_List.resize((int)msg.e_godevilpreposetask_list_size() > (int)E_GodevilPreposetask_List.max_size() ? E_GodevilPreposetask_List.max_size() : msg.e_godevilpreposetask_list_size());
	for(int32_t i = 0; i < (int32_t)E_GodevilPreposetask_List.size(); ++i) {
		const ::proto_ff::E_GodevilPreposetask & temp_e_godevilpreposetask_list = msg.e_godevilpreposetask_list(i);
		E_GodevilPreposetask_List[i].read_from_pbmsg(temp_e_godevilpreposetask_list);
	}
}

E_GodevilGodevillvAttributeDesc_s::E_GodevilGodevillvAttributeDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_GodevilGodevillvAttributeDesc_s::CreateInit() {
	m_type = (int32_t)0;
	m_value = (int32_t)0;
	return 0;
}

int E_GodevilGodevillvAttributeDesc_s::ResumeInit() {
	return 0;
}

void E_GodevilGodevillvAttributeDesc_s::write_to_pbmsg(::proto_ff::E_GodevilGodevillvAttributeDesc & msg) const {
	msg.set_m_type((int32_t)m_type);
	msg.set_m_value((int32_t)m_value);
}

void E_GodevilGodevillvAttributeDesc_s::read_from_pbmsg(const ::proto_ff::E_GodevilGodevillvAttributeDesc & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct E_GodevilGodevillvAttributeDesc_s));
	m_type = msg.m_type();
	m_value = msg.m_value();
}

E_GodevilGodevillv_s::E_GodevilGodevillv_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_GodevilGodevillv_s::CreateInit() {
	m_id = (int64_t)0;
	m_exp = (int64_t)0;
	m_explimit = (int64_t)0;
	m_itemid = (int32_t)0;
	m_num = (int32_t)0;
	return 0;
}

int E_GodevilGodevillv_s::ResumeInit() {
	return 0;
}

void E_GodevilGodevillv_s::write_to_pbmsg(::proto_ff::E_GodevilGodevillv & msg) const {
	msg.set_m_id((int64_t)m_id);
	msg.set_m_exp((int64_t)m_exp);
	msg.set_m_explimit((int64_t)m_explimit);
	msg.set_m_itemid((int32_t)m_itemid);
	msg.set_m_num((int32_t)m_num);
	for(int32_t i = 0; i < (int32_t)m_attribute.size(); ++i) {
		::proto_ff::E_GodevilGodevillvAttributeDesc* temp_m_attribute = msg.add_m_attribute();
		m_attribute[i].write_to_pbmsg(*temp_m_attribute);
	}
}

void E_GodevilGodevillv_s::read_from_pbmsg(const ::proto_ff::E_GodevilGodevillv & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct E_GodevilGodevillv_s));
	m_id = msg.m_id();
	m_exp = msg.m_exp();
	m_explimit = msg.m_explimit();
	m_itemid = msg.m_itemid();
	m_num = msg.m_num();
	m_attribute.resize((int)msg.m_attribute_size() > (int)m_attribute.max_size() ? m_attribute.max_size() : msg.m_attribute_size());
	for(int32_t i = 0; i < (int32_t)m_attribute.size(); ++i) {
		const ::proto_ff::E_GodevilGodevillvAttributeDesc & temp_m_attribute = msg.m_attribute(i);
		m_attribute[i].read_from_pbmsg(temp_m_attribute);
	}
}

Sheet_GodevilGodevillv_s::Sheet_GodevilGodevillv_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_GodevilGodevillv_s::CreateInit() {
	return 0;
}

int Sheet_GodevilGodevillv_s::ResumeInit() {
	return 0;
}

void Sheet_GodevilGodevillv_s::write_to_pbmsg(::proto_ff::Sheet_GodevilGodevillv & msg) const {
	for(int32_t i = 0; i < (int32_t)E_GodevilGodevillv_List.size(); ++i) {
		::proto_ff::E_GodevilGodevillv* temp_e_godevilgodevillv_list = msg.add_e_godevilgodevillv_list();
		E_GodevilGodevillv_List[i].write_to_pbmsg(*temp_e_godevilgodevillv_list);
	}
}

void Sheet_GodevilGodevillv_s::read_from_pbmsg(const ::proto_ff::Sheet_GodevilGodevillv & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_GodevilGodevillv_s));
	E_GodevilGodevillv_List.resize((int)msg.e_godevilgodevillv_list_size() > (int)E_GodevilGodevillv_List.max_size() ? E_GodevilGodevillv_List.max_size() : msg.e_godevilgodevillv_list_size());
	for(int32_t i = 0; i < (int32_t)E_GodevilGodevillv_List.size(); ++i) {
		const ::proto_ff::E_GodevilGodevillv & temp_e_godevilgodevillv_list = msg.e_godevilgodevillv_list(i);
		E_GodevilGodevillv_List[i].read_from_pbmsg(temp_e_godevilgodevillv_list);
	}
}

E_GodevilGodevilprivilege_s::E_GodevilGodevilprivilege_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_GodevilGodevilprivilege_s::CreateInit() {
	m_id = (int64_t)0;
	m_oldprice = (int32_t)0;
	m_newprice = (int32_t)0;
	m_rechargid = (int32_t)0;
	m_type = (int32_t)0;
	m_lv = (int32_t)0;
	m_functiontype = (int32_t)0;
	m_parama = (int32_t)0;
	m_equipmentid = (int32_t)0;
	return 0;
}

int E_GodevilGodevilprivilege_s::ResumeInit() {
	return 0;
}

void E_GodevilGodevilprivilege_s::write_to_pbmsg(::proto_ff::E_GodevilGodevilprivilege & msg) const {
	msg.set_m_id((int64_t)m_id);
	msg.set_m_oldprice((int32_t)m_oldprice);
	msg.set_m_newprice((int32_t)m_newprice);
	msg.set_m_rechargid((int32_t)m_rechargid);
	msg.set_m_type((int32_t)m_type);
	msg.set_m_lv((int32_t)m_lv);
	msg.set_m_functiontype((int32_t)m_functiontype);
	msg.set_m_parama((int32_t)m_parama);
	msg.set_m_equipmentid((int32_t)m_equipmentid);
}

void E_GodevilGodevilprivilege_s::read_from_pbmsg(const ::proto_ff::E_GodevilGodevilprivilege & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct E_GodevilGodevilprivilege_s));
	m_id = msg.m_id();
	m_oldprice = msg.m_oldprice();
	m_newprice = msg.m_newprice();
	m_rechargid = msg.m_rechargid();
	m_type = msg.m_type();
	m_lv = msg.m_lv();
	m_functiontype = msg.m_functiontype();
	m_parama = msg.m_parama();
	m_equipmentid = msg.m_equipmentid();
}

Sheet_GodevilGodevilprivilege_s::Sheet_GodevilGodevilprivilege_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_GodevilGodevilprivilege_s::CreateInit() {
	return 0;
}

int Sheet_GodevilGodevilprivilege_s::ResumeInit() {
	return 0;
}

void Sheet_GodevilGodevilprivilege_s::write_to_pbmsg(::proto_ff::Sheet_GodevilGodevilprivilege & msg) const {
	for(int32_t i = 0; i < (int32_t)E_GodevilGodevilprivilege_List.size(); ++i) {
		::proto_ff::E_GodevilGodevilprivilege* temp_e_godevilgodevilprivilege_list = msg.add_e_godevilgodevilprivilege_list();
		E_GodevilGodevilprivilege_List[i].write_to_pbmsg(*temp_e_godevilgodevilprivilege_list);
	}
}

void Sheet_GodevilGodevilprivilege_s::read_from_pbmsg(const ::proto_ff::Sheet_GodevilGodevilprivilege & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_GodevilGodevilprivilege_s));
	E_GodevilGodevilprivilege_List.resize((int)msg.e_godevilgodevilprivilege_list_size() > (int)E_GodevilGodevilprivilege_List.max_size() ? E_GodevilGodevilprivilege_List.max_size() : msg.e_godevilgodevilprivilege_list_size());
	for(int32_t i = 0; i < (int32_t)E_GodevilGodevilprivilege_List.size(); ++i) {
		const ::proto_ff::E_GodevilGodevilprivilege & temp_e_godevilgodevilprivilege_list = msg.e_godevilgodevilprivilege_list(i);
		E_GodevilGodevilprivilege_List[i].read_from_pbmsg(temp_e_godevilgodevilprivilege_list);
	}
}

}