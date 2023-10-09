#include "E_Godevil_s.h"

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
	m_value = (int32_t)0;
	m_type = (int32_t)0;
	return 0;
}

int E_GodevilGodevillvAttributeDesc_s::ResumeInit() {
	return 0;
}

void E_GodevilGodevillvAttributeDesc_s::write_to_pbmsg(::proto_ff::E_GodevilGodevillvAttributeDesc & msg) const {
	msg.set_m_value((int32_t)m_value);
	msg.set_m_type((int32_t)m_type);
}

void E_GodevilGodevillvAttributeDesc_s::read_from_pbmsg(const ::proto_ff::E_GodevilGodevillvAttributeDesc & msg) {
	m_value = msg.m_value();
	m_type = msg.m_type();
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
	m_itemid = (int32_t)0;
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
	msg.set_m_itemid((int32_t)m_itemid);
}

void E_GodevilGodevilprivilege_s::read_from_pbmsg(const ::proto_ff::E_GodevilGodevilprivilege & msg) {
	m_id = msg.m_id();
	m_oldprice = msg.m_oldprice();
	m_newprice = msg.m_newprice();
	m_rechargid = msg.m_rechargid();
	m_type = msg.m_type();
	m_lv = msg.m_lv();
	m_functiontype = msg.m_functiontype();
	m_parama = msg.m_parama();
	m_equipmentid = msg.m_equipmentid();
	m_itemid = msg.m_itemid();
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
	E_GodevilGodevilprivilege_List.resize((int)msg.e_godevilgodevilprivilege_list_size() > (int)E_GodevilGodevilprivilege_List.max_size() ? E_GodevilGodevilprivilege_List.max_size() : msg.e_godevilgodevilprivilege_list_size());
	for(int32_t i = 0; i < (int32_t)E_GodevilGodevilprivilege_List.size(); ++i) {
		const ::proto_ff::E_GodevilGodevilprivilege & temp_e_godevilgodevilprivilege_list = msg.e_godevilgodevilprivilege_list(i);
		E_GodevilGodevilprivilege_List[i].read_from_pbmsg(temp_e_godevilgodevilprivilege_list);
	}
}

E_GodevilStrongStDesc_s::E_GodevilStrongStDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_GodevilStrongStDesc_s::CreateInit() {
	return 0;
}

int E_GodevilStrongStDesc_s::ResumeInit() {
	return 0;
}

void E_GodevilStrongStDesc_s::write_to_pbmsg(::proto_ff::E_GodevilStrongStDesc & msg) const {
	msg.set_m_typeid(m_typeid.data());
	msg.set_m_quality(m_quality.data());
	msg.set_m_position(m_position.data());
}

void E_GodevilStrongStDesc_s::read_from_pbmsg(const ::proto_ff::E_GodevilStrongStDesc & msg) {
	m_typeid = msg.m_typeid();
	m_quality = msg.m_quality();
	m_position = msg.m_position();
}

E_GodevilStrong_s::E_GodevilStrong_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_GodevilStrong_s::CreateInit() {
	m_lv = (int32_t)0;
	m_exp = (int32_t)0;
	m_type_num = (int32_t)0;
	m_godevillv = (int32_t)0;
	return 0;
}

int E_GodevilStrong_s::ResumeInit() {
	return 0;
}

void E_GodevilStrong_s::write_to_pbmsg(::proto_ff::E_GodevilStrong & msg) const {
	msg.set_m_lv((int32_t)m_lv);
	msg.set_m_exp((int32_t)m_exp);
	msg.set_m_type_num((int32_t)m_type_num);
	msg.set_m_godevillv((int32_t)m_godevillv);
	for(int32_t i = 0; i < (int32_t)m_st.size(); ++i) {
		::proto_ff::E_GodevilStrongStDesc* temp_m_st = msg.add_m_st();
		m_st[i].write_to_pbmsg(*temp_m_st);
	}
}

void E_GodevilStrong_s::read_from_pbmsg(const ::proto_ff::E_GodevilStrong & msg) {
	m_lv = msg.m_lv();
	m_exp = msg.m_exp();
	m_type_num = msg.m_type_num();
	m_godevillv = msg.m_godevillv();
	m_st.resize((int)msg.m_st_size() > (int)m_st.max_size() ? m_st.max_size() : msg.m_st_size());
	for(int32_t i = 0; i < (int32_t)m_st.size(); ++i) {
		const ::proto_ff::E_GodevilStrongStDesc & temp_m_st = msg.m_st(i);
		m_st[i].read_from_pbmsg(temp_m_st);
	}
}

Sheet_GodevilStrong_s::Sheet_GodevilStrong_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_GodevilStrong_s::CreateInit() {
	return 0;
}

int Sheet_GodevilStrong_s::ResumeInit() {
	return 0;
}

void Sheet_GodevilStrong_s::write_to_pbmsg(::proto_ff::Sheet_GodevilStrong & msg) const {
	for(int32_t i = 0; i < (int32_t)E_GodevilStrong_List.size(); ++i) {
		::proto_ff::E_GodevilStrong* temp_e_godevilstrong_list = msg.add_e_godevilstrong_list();
		E_GodevilStrong_List[i].write_to_pbmsg(*temp_e_godevilstrong_list);
	}
}

void Sheet_GodevilStrong_s::read_from_pbmsg(const ::proto_ff::Sheet_GodevilStrong & msg) {
	E_GodevilStrong_List.resize((int)msg.e_godevilstrong_list_size() > (int)E_GodevilStrong_List.max_size() ? E_GodevilStrong_List.max_size() : msg.e_godevilstrong_list_size());
	for(int32_t i = 0; i < (int32_t)E_GodevilStrong_List.size(); ++i) {
		const ::proto_ff::E_GodevilStrong & temp_e_godevilstrong_list = msg.e_godevilstrong_list(i);
		E_GodevilStrong_List[i].read_from_pbmsg(temp_e_godevilstrong_list);
	}
}

E_GodevilStrongexp_s::E_GodevilStrongexp_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_GodevilStrongexp_s::CreateInit() {
	m_id = (int32_t)0;
	m_type = (int32_t)0;
	m_parama = (int32_t)0;
	m_strongexp = (int32_t)0;
	return 0;
}

int E_GodevilStrongexp_s::ResumeInit() {
	return 0;
}

void E_GodevilStrongexp_s::write_to_pbmsg(::proto_ff::E_GodevilStrongexp & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_type((int32_t)m_type);
	msg.set_m_parama((int32_t)m_parama);
	msg.set_m_strongexp((int32_t)m_strongexp);
}

void E_GodevilStrongexp_s::read_from_pbmsg(const ::proto_ff::E_GodevilStrongexp & msg) {
	m_id = msg.m_id();
	m_type = msg.m_type();
	m_parama = msg.m_parama();
	m_strongexp = msg.m_strongexp();
}

Sheet_GodevilStrongexp_s::Sheet_GodevilStrongexp_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_GodevilStrongexp_s::CreateInit() {
	return 0;
}

int Sheet_GodevilStrongexp_s::ResumeInit() {
	return 0;
}

void Sheet_GodevilStrongexp_s::write_to_pbmsg(::proto_ff::Sheet_GodevilStrongexp & msg) const {
	for(int32_t i = 0; i < (int32_t)E_GodevilStrongexp_List.size(); ++i) {
		::proto_ff::E_GodevilStrongexp* temp_e_godevilstrongexp_list = msg.add_e_godevilstrongexp_list();
		E_GodevilStrongexp_List[i].write_to_pbmsg(*temp_e_godevilstrongexp_list);
	}
}

void Sheet_GodevilStrongexp_s::read_from_pbmsg(const ::proto_ff::Sheet_GodevilStrongexp & msg) {
	E_GodevilStrongexp_List.resize((int)msg.e_godevilstrongexp_list_size() > (int)E_GodevilStrongexp_List.max_size() ? E_GodevilStrongexp_List.max_size() : msg.e_godevilstrongexp_list_size());
	for(int32_t i = 0; i < (int32_t)E_GodevilStrongexp_List.size(); ++i) {
		const ::proto_ff::E_GodevilStrongexp & temp_e_godevilstrongexp_list = msg.e_godevilstrongexp_list(i);
		E_GodevilStrongexp_List[i].read_from_pbmsg(temp_e_godevilstrongexp_list);
	}
}

E_GodevilAdvancelvAdDesc_s::E_GodevilAdvancelvAdDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_GodevilAdvancelvAdDesc_s::CreateInit() {
	m_godevillv = (int32_t)0;
	m_exp = (int32_t)0;
	return 0;
}

int E_GodevilAdvancelvAdDesc_s::ResumeInit() {
	return 0;
}

void E_GodevilAdvancelvAdDesc_s::write_to_pbmsg(::proto_ff::E_GodevilAdvancelvAdDesc & msg) const {
	msg.set_m_godevillv((int32_t)m_godevillv);
	msg.set_m_exp((int32_t)m_exp);
	msg.set_m_position(m_position.data());
}

void E_GodevilAdvancelvAdDesc_s::read_from_pbmsg(const ::proto_ff::E_GodevilAdvancelvAdDesc & msg) {
	m_godevillv = msg.m_godevillv();
	m_exp = msg.m_exp();
	m_position = msg.m_position();
}

E_GodevilAdvancelv_s::E_GodevilAdvancelv_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_GodevilAdvancelv_s::CreateInit() {
	m_wearlv = (int32_t)0;
	return 0;
}

int E_GodevilAdvancelv_s::ResumeInit() {
	return 0;
}

void E_GodevilAdvancelv_s::write_to_pbmsg(::proto_ff::E_GodevilAdvancelv & msg) const {
	msg.set_m_wearlv((int32_t)m_wearlv);
	for(int32_t i = 0; i < (int32_t)m_ad.size(); ++i) {
		::proto_ff::E_GodevilAdvancelvAdDesc* temp_m_ad = msg.add_m_ad();
		m_ad[i].write_to_pbmsg(*temp_m_ad);
	}
}

void E_GodevilAdvancelv_s::read_from_pbmsg(const ::proto_ff::E_GodevilAdvancelv & msg) {
	m_wearlv = msg.m_wearlv();
	m_ad.resize((int)msg.m_ad_size() > (int)m_ad.max_size() ? m_ad.max_size() : msg.m_ad_size());
	for(int32_t i = 0; i < (int32_t)m_ad.size(); ++i) {
		const ::proto_ff::E_GodevilAdvancelvAdDesc & temp_m_ad = msg.m_ad(i);
		m_ad[i].read_from_pbmsg(temp_m_ad);
	}
}

Sheet_GodevilAdvancelv_s::Sheet_GodevilAdvancelv_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_GodevilAdvancelv_s::CreateInit() {
	return 0;
}

int Sheet_GodevilAdvancelv_s::ResumeInit() {
	return 0;
}

void Sheet_GodevilAdvancelv_s::write_to_pbmsg(::proto_ff::Sheet_GodevilAdvancelv & msg) const {
	for(int32_t i = 0; i < (int32_t)E_GodevilAdvancelv_List.size(); ++i) {
		::proto_ff::E_GodevilAdvancelv* temp_e_godeviladvancelv_list = msg.add_e_godeviladvancelv_list();
		E_GodevilAdvancelv_List[i].write_to_pbmsg(*temp_e_godeviladvancelv_list);
	}
}

void Sheet_GodevilAdvancelv_s::read_from_pbmsg(const ::proto_ff::Sheet_GodevilAdvancelv & msg) {
	E_GodevilAdvancelv_List.resize((int)msg.e_godeviladvancelv_list_size() > (int)E_GodevilAdvancelv_List.max_size() ? E_GodevilAdvancelv_List.max_size() : msg.e_godeviladvancelv_list_size());
	for(int32_t i = 0; i < (int32_t)E_GodevilAdvancelv_List.size(); ++i) {
		const ::proto_ff::E_GodevilAdvancelv & temp_e_godeviladvancelv_list = msg.e_godeviladvancelv_list(i);
		E_GodevilAdvancelv_List[i].read_from_pbmsg(temp_e_godeviladvancelv_list);
	}
}

E_GodevilAdvanceexp_s::E_GodevilAdvanceexp_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_GodevilAdvanceexp_s::CreateInit() {
	m_id = (int32_t)0;
	m_wearlv = (int32_t)0;
	m_lvparama = (int32_t)0;
	m_goldparama = (int32_t)0;
	m_silverparama = (int32_t)0;
	m_quality6 = (int32_t)0;
	m_quality7 = (int32_t)0;
	m_quality8 = (int32_t)0;
	m_quality9 = (int32_t)0;
	m_quality10 = (int32_t)0;
	return 0;
}

int E_GodevilAdvanceexp_s::ResumeInit() {
	return 0;
}

void E_GodevilAdvanceexp_s::write_to_pbmsg(::proto_ff::E_GodevilAdvanceexp & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_wearlv((int32_t)m_wearlv);
	msg.set_m_position(m_position.data());
	msg.set_m_lvparama((int32_t)m_lvparama);
	msg.set_m_goldparama((int32_t)m_goldparama);
	msg.set_m_silverparama((int32_t)m_silverparama);
	msg.set_m_quality6((int32_t)m_quality6);
	msg.set_m_quality7((int32_t)m_quality7);
	msg.set_m_quality8((int32_t)m_quality8);
	msg.set_m_quality9((int32_t)m_quality9);
	msg.set_m_quality10((int32_t)m_quality10);
}

void E_GodevilAdvanceexp_s::read_from_pbmsg(const ::proto_ff::E_GodevilAdvanceexp & msg) {
	m_id = msg.m_id();
	m_wearlv = msg.m_wearlv();
	m_position = msg.m_position();
	m_lvparama = msg.m_lvparama();
	m_goldparama = msg.m_goldparama();
	m_silverparama = msg.m_silverparama();
	m_quality6 = msg.m_quality6();
	m_quality7 = msg.m_quality7();
	m_quality8 = msg.m_quality8();
	m_quality9 = msg.m_quality9();
	m_quality10 = msg.m_quality10();
}

Sheet_GodevilAdvanceexp_s::Sheet_GodevilAdvanceexp_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_GodevilAdvanceexp_s::CreateInit() {
	return 0;
}

int Sheet_GodevilAdvanceexp_s::ResumeInit() {
	return 0;
}

void Sheet_GodevilAdvanceexp_s::write_to_pbmsg(::proto_ff::Sheet_GodevilAdvanceexp & msg) const {
	for(int32_t i = 0; i < (int32_t)E_GodevilAdvanceexp_List.size(); ++i) {
		::proto_ff::E_GodevilAdvanceexp* temp_e_godeviladvanceexp_list = msg.add_e_godeviladvanceexp_list();
		E_GodevilAdvanceexp_List[i].write_to_pbmsg(*temp_e_godeviladvanceexp_list);
	}
}

void Sheet_GodevilAdvanceexp_s::read_from_pbmsg(const ::proto_ff::Sheet_GodevilAdvanceexp & msg) {
	E_GodevilAdvanceexp_List.resize((int)msg.e_godeviladvanceexp_list_size() > (int)E_GodevilAdvanceexp_List.max_size() ? E_GodevilAdvanceexp_List.max_size() : msg.e_godeviladvanceexp_list_size());
	for(int32_t i = 0; i < (int32_t)E_GodevilAdvanceexp_List.size(); ++i) {
		const ::proto_ff::E_GodevilAdvanceexp & temp_e_godeviladvanceexp_list = msg.e_godeviladvanceexp_list(i);
		E_GodevilAdvanceexp_List[i].read_from_pbmsg(temp_e_godeviladvanceexp_list);
	}
}

E_GodevilQualitylvItemDesc_s::E_GodevilQualitylvItemDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_GodevilQualitylvItemDesc_s::CreateInit() {
	m_num = (int32_t)0;
	m_id = (int32_t)0;
	return 0;
}

int E_GodevilQualitylvItemDesc_s::ResumeInit() {
	return 0;
}

void E_GodevilQualitylvItemDesc_s::write_to_pbmsg(::proto_ff::E_GodevilQualitylvItemDesc & msg) const {
	msg.set_m_num((int32_t)m_num);
	msg.set_m_id((int32_t)m_id);
}

void E_GodevilQualitylvItemDesc_s::read_from_pbmsg(const ::proto_ff::E_GodevilQualitylvItemDesc & msg) {
	m_num = msg.m_num();
	m_id = msg.m_id();
}

E_GodevilQualitylv_s::E_GodevilQualitylv_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_GodevilQualitylv_s::CreateInit() {
	m_id = (int32_t)0;
	m_quality = (int32_t)0;
	m_wearlv = (int32_t)0;
	m_percent = (int32_t)0;
	m_costwuxiongitem = (int32_t)0;
	m_costnumber = (int32_t)0;
	return 0;
}

int E_GodevilQualitylv_s::ResumeInit() {
	return 0;
}

void E_GodevilQualitylv_s::write_to_pbmsg(::proto_ff::E_GodevilQualitylv & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_quality((int32_t)m_quality);
	msg.set_m_wearlv((int32_t)m_wearlv);
	msg.set_m_percent((int32_t)m_percent);
	msg.set_m_position(m_position.data());
	msg.set_m_costwuxiongitem((int32_t)m_costwuxiongitem);
	msg.set_m_costnumber((int32_t)m_costnumber);
	for(int32_t i = 0; i < (int32_t)m_item.size(); ++i) {
		::proto_ff::E_GodevilQualitylvItemDesc* temp_m_item = msg.add_m_item();
		m_item[i].write_to_pbmsg(*temp_m_item);
	}
}

void E_GodevilQualitylv_s::read_from_pbmsg(const ::proto_ff::E_GodevilQualitylv & msg) {
	m_id = msg.m_id();
	m_quality = msg.m_quality();
	m_wearlv = msg.m_wearlv();
	m_percent = msg.m_percent();
	m_position = msg.m_position();
	m_costwuxiongitem = msg.m_costwuxiongitem();
	m_costnumber = msg.m_costnumber();
	m_item.resize((int)msg.m_item_size() > (int)m_item.max_size() ? m_item.max_size() : msg.m_item_size());
	for(int32_t i = 0; i < (int32_t)m_item.size(); ++i) {
		const ::proto_ff::E_GodevilQualitylvItemDesc & temp_m_item = msg.m_item(i);
		m_item[i].read_from_pbmsg(temp_m_item);
	}
}

Sheet_GodevilQualitylv_s::Sheet_GodevilQualitylv_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_GodevilQualitylv_s::CreateInit() {
	return 0;
}

int Sheet_GodevilQualitylv_s::ResumeInit() {
	return 0;
}

void Sheet_GodevilQualitylv_s::write_to_pbmsg(::proto_ff::Sheet_GodevilQualitylv & msg) const {
	for(int32_t i = 0; i < (int32_t)E_GodevilQualitylv_List.size(); ++i) {
		::proto_ff::E_GodevilQualitylv* temp_e_godevilqualitylv_list = msg.add_e_godevilqualitylv_list();
		E_GodevilQualitylv_List[i].write_to_pbmsg(*temp_e_godevilqualitylv_list);
	}
}

void Sheet_GodevilQualitylv_s::read_from_pbmsg(const ::proto_ff::Sheet_GodevilQualitylv & msg) {
	E_GodevilQualitylv_List.resize((int)msg.e_godevilqualitylv_list_size() > (int)E_GodevilQualitylv_List.max_size() ? E_GodevilQualitylv_List.max_size() : msg.e_godevilqualitylv_list_size());
	for(int32_t i = 0; i < (int32_t)E_GodevilQualitylv_List.size(); ++i) {
		const ::proto_ff::E_GodevilQualitylv & temp_e_godevilqualitylv_list = msg.e_godevilqualitylv_list(i);
		E_GodevilQualitylv_List[i].read_from_pbmsg(temp_e_godevilqualitylv_list);
	}
}

E_GodevilPositionunlock_s::E_GodevilPositionunlock_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_GodevilPositionunlock_s::CreateInit() {
	m_position = (int32_t)0;
	m_day = (int32_t)0;
	m_godevillv = (int32_t)0;
	return 0;
}

int E_GodevilPositionunlock_s::ResumeInit() {
	return 0;
}

void E_GodevilPositionunlock_s::write_to_pbmsg(::proto_ff::E_GodevilPositionunlock & msg) const {
	msg.set_m_position((int32_t)m_position);
	msg.set_m_day((int32_t)m_day);
	msg.set_m_godevillv((int32_t)m_godevillv);
}

void E_GodevilPositionunlock_s::read_from_pbmsg(const ::proto_ff::E_GodevilPositionunlock & msg) {
	m_position = msg.m_position();
	m_day = msg.m_day();
	m_godevillv = msg.m_godevillv();
}

Sheet_GodevilPositionunlock_s::Sheet_GodevilPositionunlock_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_GodevilPositionunlock_s::CreateInit() {
	return 0;
}

int Sheet_GodevilPositionunlock_s::ResumeInit() {
	return 0;
}

void Sheet_GodevilPositionunlock_s::write_to_pbmsg(::proto_ff::Sheet_GodevilPositionunlock & msg) const {
	for(int32_t i = 0; i < (int32_t)E_GodevilPositionunlock_List.size(); ++i) {
		::proto_ff::E_GodevilPositionunlock* temp_e_godevilpositionunlock_list = msg.add_e_godevilpositionunlock_list();
		E_GodevilPositionunlock_List[i].write_to_pbmsg(*temp_e_godevilpositionunlock_list);
	}
}

void Sheet_GodevilPositionunlock_s::read_from_pbmsg(const ::proto_ff::Sheet_GodevilPositionunlock & msg) {
	E_GodevilPositionunlock_List.resize((int)msg.e_godevilpositionunlock_list_size() > (int)E_GodevilPositionunlock_List.max_size() ? E_GodevilPositionunlock_List.max_size() : msg.e_godevilpositionunlock_list_size());
	for(int32_t i = 0; i < (int32_t)E_GodevilPositionunlock_List.size(); ++i) {
		const ::proto_ff::E_GodevilPositionunlock & temp_e_godevilpositionunlock_list = msg.e_godevilpositionunlock_list(i);
		E_GodevilPositionunlock_List[i].read_from_pbmsg(temp_e_godevilpositionunlock_list);
	}
}

E_GodevilBlacksmithItemDesc_s::E_GodevilBlacksmithItemDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_GodevilBlacksmithItemDesc_s::CreateInit() {
	m_num = (int32_t)0;
	m_id = (int32_t)0;
	return 0;
}

int E_GodevilBlacksmithItemDesc_s::ResumeInit() {
	return 0;
}

void E_GodevilBlacksmithItemDesc_s::write_to_pbmsg(::proto_ff::E_GodevilBlacksmithItemDesc & msg) const {
	msg.set_m_num((int32_t)m_num);
	msg.set_m_id((int32_t)m_id);
}

void E_GodevilBlacksmithItemDesc_s::read_from_pbmsg(const ::proto_ff::E_GodevilBlacksmithItemDesc & msg) {
	m_num = msg.m_num();
	m_id = msg.m_id();
}

E_GodevilBlacksmithSkillDesc_s::E_GodevilBlacksmithSkillDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_GodevilBlacksmithSkillDesc_s::CreateInit() {
	m_probability = (int32_t)0;
	m_id = (int32_t)0;
	return 0;
}

int E_GodevilBlacksmithSkillDesc_s::ResumeInit() {
	return 0;
}

void E_GodevilBlacksmithSkillDesc_s::write_to_pbmsg(::proto_ff::E_GodevilBlacksmithSkillDesc & msg) const {
	msg.set_m_probability((int32_t)m_probability);
	msg.set_m_id((int32_t)m_id);
}

void E_GodevilBlacksmithSkillDesc_s::read_from_pbmsg(const ::proto_ff::E_GodevilBlacksmithSkillDesc & msg) {
	m_probability = msg.m_probability();
	m_id = msg.m_id();
}

E_GodevilBlacksmith_s::E_GodevilBlacksmith_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_GodevilBlacksmith_s::CreateInit() {
	m_id = (int32_t)0;
	m_type = (int32_t)0;
	m_position = (int32_t)0;
	m_quality = (int32_t)0;
	m_probability = (int32_t)0;
	m_gold = (int32_t)0;
	m_silver = (int32_t)0;
	m_paperid = (int32_t)0;
	m_papernum = (int32_t)0;
	m_substituteitem = (int32_t)0;
	m_number = (int32_t)0;
	m_godevilskill = (int32_t)0;
	return 0;
}

int E_GodevilBlacksmith_s::ResumeInit() {
	return 0;
}

void E_GodevilBlacksmith_s::write_to_pbmsg(::proto_ff::E_GodevilBlacksmith & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_type((int32_t)m_type);
	msg.set_m_position((int32_t)m_position);
	msg.set_m_quality((int32_t)m_quality);
	msg.set_m_probability((int32_t)m_probability);
	msg.set_m_godpoint(m_godpoint.data());
	msg.set_m_starsprobability(m_starsprobability.data());
	msg.set_m_gold((int32_t)m_gold);
	msg.set_m_silver((int32_t)m_silver);
	msg.set_m_paperid((int32_t)m_paperid);
	msg.set_m_papernum((int32_t)m_papernum);
	msg.set_m_substituteitem((int32_t)m_substituteitem);
	msg.set_m_number((int32_t)m_number);
	msg.set_m_godevilskill((int32_t)m_godevilskill);
	msg.set_m_skillset(m_skillset.data());
	for(int32_t i = 0; i < (int32_t)m_item.size(); ++i) {
		::proto_ff::E_GodevilBlacksmithItemDesc* temp_m_item = msg.add_m_item();
		m_item[i].write_to_pbmsg(*temp_m_item);
	}
	for(int32_t i = 0; i < (int32_t)m_skill.size(); ++i) {
		::proto_ff::E_GodevilBlacksmithSkillDesc* temp_m_skill = msg.add_m_skill();
		m_skill[i].write_to_pbmsg(*temp_m_skill);
	}
}

void E_GodevilBlacksmith_s::read_from_pbmsg(const ::proto_ff::E_GodevilBlacksmith & msg) {
	m_id = msg.m_id();
	m_type = msg.m_type();
	m_position = msg.m_position();
	m_quality = msg.m_quality();
	m_probability = msg.m_probability();
	m_godpoint = msg.m_godpoint();
	m_starsprobability = msg.m_starsprobability();
	m_gold = msg.m_gold();
	m_silver = msg.m_silver();
	m_paperid = msg.m_paperid();
	m_papernum = msg.m_papernum();
	m_substituteitem = msg.m_substituteitem();
	m_number = msg.m_number();
	m_godevilskill = msg.m_godevilskill();
	m_skillset = msg.m_skillset();
	m_item.resize((int)msg.m_item_size() > (int)m_item.max_size() ? m_item.max_size() : msg.m_item_size());
	for(int32_t i = 0; i < (int32_t)m_item.size(); ++i) {
		const ::proto_ff::E_GodevilBlacksmithItemDesc & temp_m_item = msg.m_item(i);
		m_item[i].read_from_pbmsg(temp_m_item);
	}
	m_skill.resize((int)msg.m_skill_size() > (int)m_skill.max_size() ? m_skill.max_size() : msg.m_skill_size());
	for(int32_t i = 0; i < (int32_t)m_skill.size(); ++i) {
		const ::proto_ff::E_GodevilBlacksmithSkillDesc & temp_m_skill = msg.m_skill(i);
		m_skill[i].read_from_pbmsg(temp_m_skill);
	}
}

Sheet_GodevilBlacksmith_s::Sheet_GodevilBlacksmith_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_GodevilBlacksmith_s::CreateInit() {
	return 0;
}

int Sheet_GodevilBlacksmith_s::ResumeInit() {
	return 0;
}

void Sheet_GodevilBlacksmith_s::write_to_pbmsg(::proto_ff::Sheet_GodevilBlacksmith & msg) const {
	for(int32_t i = 0; i < (int32_t)E_GodevilBlacksmith_List.size(); ++i) {
		::proto_ff::E_GodevilBlacksmith* temp_e_godevilblacksmith_list = msg.add_e_godevilblacksmith_list();
		E_GodevilBlacksmith_List[i].write_to_pbmsg(*temp_e_godevilblacksmith_list);
	}
}

void Sheet_GodevilBlacksmith_s::read_from_pbmsg(const ::proto_ff::Sheet_GodevilBlacksmith & msg) {
	E_GodevilBlacksmith_List.resize((int)msg.e_godevilblacksmith_list_size() > (int)E_GodevilBlacksmith_List.max_size() ? E_GodevilBlacksmith_List.max_size() : msg.e_godevilblacksmith_list_size());
	for(int32_t i = 0; i < (int32_t)E_GodevilBlacksmith_List.size(); ++i) {
		const ::proto_ff::E_GodevilBlacksmith & temp_e_godevilblacksmith_list = msg.e_godevilblacksmith_list(i);
		E_GodevilBlacksmith_List[i].read_from_pbmsg(temp_e_godevilblacksmith_list);
	}
}

E_GodevilGodevilskill_s::E_GodevilGodevilskill_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_GodevilGodevilskill_s::CreateInit() {
	m_godevilskill = (int32_t)0;
	m_goldstars = (int32_t)0;
	return 0;
}

int E_GodevilGodevilskill_s::ResumeInit() {
	return 0;
}

void E_GodevilGodevilskill_s::write_to_pbmsg(::proto_ff::E_GodevilGodevilskill & msg) const {
	msg.set_m_godevilskill((int32_t)m_godevilskill);
	msg.set_m_goldstars((int32_t)m_goldstars);
}

void E_GodevilGodevilskill_s::read_from_pbmsg(const ::proto_ff::E_GodevilGodevilskill & msg) {
	m_godevilskill = msg.m_godevilskill();
	m_goldstars = msg.m_goldstars();
}

Sheet_GodevilGodevilskill_s::Sheet_GodevilGodevilskill_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_GodevilGodevilskill_s::CreateInit() {
	return 0;
}

int Sheet_GodevilGodevilskill_s::ResumeInit() {
	return 0;
}

void Sheet_GodevilGodevilskill_s::write_to_pbmsg(::proto_ff::Sheet_GodevilGodevilskill & msg) const {
	for(int32_t i = 0; i < (int32_t)E_GodevilGodevilskill_List.size(); ++i) {
		::proto_ff::E_GodevilGodevilskill* temp_e_godevilgodevilskill_list = msg.add_e_godevilgodevilskill_list();
		E_GodevilGodevilskill_List[i].write_to_pbmsg(*temp_e_godevilgodevilskill_list);
	}
}

void Sheet_GodevilGodevilskill_s::read_from_pbmsg(const ::proto_ff::Sheet_GodevilGodevilskill & msg) {
	E_GodevilGodevilskill_List.resize((int)msg.e_godevilgodevilskill_list_size() > (int)E_GodevilGodevilskill_List.max_size() ? E_GodevilGodevilskill_List.max_size() : msg.e_godevilgodevilskill_list_size());
	for(int32_t i = 0; i < (int32_t)E_GodevilGodevilskill_List.size(); ++i) {
		const ::proto_ff::E_GodevilGodevilskill & temp_e_godevilgodevilskill_list = msg.e_godevilgodevilskill_list(i);
		E_GodevilGodevilskill_List[i].read_from_pbmsg(temp_e_godevilgodevilskill_list);
	}
}

E_GodevilPrefixname_s::E_GodevilPrefixname_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_GodevilPrefixname_s::CreateInit() {
	m_id = (int32_t)0;
	m_type = (int32_t)0;
	m_number = (int32_t)0;
	return 0;
}

int E_GodevilPrefixname_s::ResumeInit() {
	return 0;
}

void E_GodevilPrefixname_s::write_to_pbmsg(::proto_ff::E_GodevilPrefixname & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_type((int32_t)m_type);
	msg.set_m_number((int32_t)m_number);
}

void E_GodevilPrefixname_s::read_from_pbmsg(const ::proto_ff::E_GodevilPrefixname & msg) {
	m_id = msg.m_id();
	m_type = msg.m_type();
	m_number = msg.m_number();
}

Sheet_GodevilPrefixname_s::Sheet_GodevilPrefixname_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_GodevilPrefixname_s::CreateInit() {
	return 0;
}

int Sheet_GodevilPrefixname_s::ResumeInit() {
	return 0;
}

void Sheet_GodevilPrefixname_s::write_to_pbmsg(::proto_ff::Sheet_GodevilPrefixname & msg) const {
	for(int32_t i = 0; i < (int32_t)E_GodevilPrefixname_List.size(); ++i) {
		::proto_ff::E_GodevilPrefixname* temp_e_godevilprefixname_list = msg.add_e_godevilprefixname_list();
		E_GodevilPrefixname_List[i].write_to_pbmsg(*temp_e_godevilprefixname_list);
	}
}

void Sheet_GodevilPrefixname_s::read_from_pbmsg(const ::proto_ff::Sheet_GodevilPrefixname & msg) {
	E_GodevilPrefixname_List.resize((int)msg.e_godevilprefixname_list_size() > (int)E_GodevilPrefixname_List.max_size() ? E_GodevilPrefixname_List.max_size() : msg.e_godevilprefixname_list_size());
	for(int32_t i = 0; i < (int32_t)E_GodevilPrefixname_List.size(); ++i) {
		const ::proto_ff::E_GodevilPrefixname & temp_e_godevilprefixname_list = msg.e_godevilprefixname_list(i);
		E_GodevilPrefixname_List[i].read_from_pbmsg(temp_e_godevilprefixname_list);
	}
}

}
