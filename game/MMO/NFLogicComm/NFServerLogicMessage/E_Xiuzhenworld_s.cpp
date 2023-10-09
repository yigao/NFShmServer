#include "E_Xiuzhenworld_s.h"

namespace proto_ff_s {

E_XiuzhenworldConstantTimeitemDesc_s::E_XiuzhenworldConstantTimeitemDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_XiuzhenworldConstantTimeitemDesc_s::CreateInit() {
	m_time = (int32_t)0;
	m_id = (int32_t)0;
	return 0;
}

int E_XiuzhenworldConstantTimeitemDesc_s::ResumeInit() {
	return 0;
}

void E_XiuzhenworldConstantTimeitemDesc_s::write_to_pbmsg(::proto_ff::E_XiuzhenworldConstantTimeitemDesc & msg) const {
	msg.set_m_time((int32_t)m_time);
	msg.set_m_id((int32_t)m_id);
}

void E_XiuzhenworldConstantTimeitemDesc_s::read_from_pbmsg(const ::proto_ff::E_XiuzhenworldConstantTimeitemDesc & msg) {
	m_time = msg.m_time();
	m_id = msg.m_id();
}

E_XiuzhenworldConstantTypeDesc_s::E_XiuzhenworldConstantTypeDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_XiuzhenworldConstantTypeDesc_s::CreateInit() {
	m_id = (int32_t)0;
	return 0;
}

int E_XiuzhenworldConstantTypeDesc_s::ResumeInit() {
	return 0;
}

void E_XiuzhenworldConstantTypeDesc_s::write_to_pbmsg(::proto_ff::E_XiuzhenworldConstantTypeDesc & msg) const {
	msg.set_m_num(m_num.data());
	msg.set_m_id((int32_t)m_id);
}

void E_XiuzhenworldConstantTypeDesc_s::read_from_pbmsg(const ::proto_ff::E_XiuzhenworldConstantTypeDesc & msg) {
	m_num = msg.m_num();
	m_id = msg.m_id();
}

E_XiuzhenworldConstant_s::E_XiuzhenworldConstant_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_XiuzhenworldConstant_s::CreateInit() {
	m_id = (int32_t)0;
	m_freetime = (int32_t)0;
	m_freetimemax = (int32_t)0;
	m_helpid = (int32_t)0;
	m_addgexpmax = (int32_t)0;
	m_pripricetype = (int32_t)0;
	m_pricevalue = (int32_t)0;
	m_gexppribonus = (int32_t)0;
	m_gexpgroupbonus = (int32_t)0;
	m_mapstart = (int32_t)0;
	m_mapend = (int32_t)0;
	m_expitemid = (int32_t)0;
	return 0;
}

int E_XiuzhenworldConstant_s::ResumeInit() {
	return 0;
}

void E_XiuzhenworldConstant_s::write_to_pbmsg(::proto_ff::E_XiuzhenworldConstant & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_freetimemoment(m_freetimemoment.data());
	msg.set_m_freetime((int32_t)m_freetime);
	msg.set_m_freetimemax((int32_t)m_freetimemax);
	msg.set_m_helpid((int32_t)m_helpid);
	msg.set_m_addgexpmax((int32_t)m_addgexpmax);
	msg.set_m_pripricetype((int32_t)m_pripricetype);
	msg.set_m_pricevalue((int32_t)m_pricevalue);
	msg.set_m_gexppribonus((int32_t)m_gexppribonus);
	msg.set_m_gexpgroupbonus((int32_t)m_gexpgroupbonus);
	msg.set_m_mapstart((int32_t)m_mapstart);
	msg.set_m_mapend((int32_t)m_mapend);
	msg.set_m_expitemid((int32_t)m_expitemid);
	for(int32_t i = 0; i < (int32_t)m_timeitem.size(); ++i) {
		::proto_ff::E_XiuzhenworldConstantTimeitemDesc* temp_m_timeitem = msg.add_m_timeitem();
		m_timeitem[i].write_to_pbmsg(*temp_m_timeitem);
	}
	for(int32_t i = 0; i < (int32_t)m_type.size(); ++i) {
		::proto_ff::E_XiuzhenworldConstantTypeDesc* temp_m_type = msg.add_m_type();
		m_type[i].write_to_pbmsg(*temp_m_type);
	}
}

void E_XiuzhenworldConstant_s::read_from_pbmsg(const ::proto_ff::E_XiuzhenworldConstant & msg) {
	m_id = msg.m_id();
	m_freetimemoment = msg.m_freetimemoment();
	m_freetime = msg.m_freetime();
	m_freetimemax = msg.m_freetimemax();
	m_helpid = msg.m_helpid();
	m_addgexpmax = msg.m_addgexpmax();
	m_pripricetype = msg.m_pripricetype();
	m_pricevalue = msg.m_pricevalue();
	m_gexppribonus = msg.m_gexppribonus();
	m_gexpgroupbonus = msg.m_gexpgroupbonus();
	m_mapstart = msg.m_mapstart();
	m_mapend = msg.m_mapend();
	m_expitemid = msg.m_expitemid();
	m_timeitem.resize((int)msg.m_timeitem_size() > (int)m_timeitem.max_size() ? m_timeitem.max_size() : msg.m_timeitem_size());
	for(int32_t i = 0; i < (int32_t)m_timeitem.size(); ++i) {
		const ::proto_ff::E_XiuzhenworldConstantTimeitemDesc & temp_m_timeitem = msg.m_timeitem(i);
		m_timeitem[i].read_from_pbmsg(temp_m_timeitem);
	}
	m_type.resize((int)msg.m_type_size() > (int)m_type.max_size() ? m_type.max_size() : msg.m_type_size());
	for(int32_t i = 0; i < (int32_t)m_type.size(); ++i) {
		const ::proto_ff::E_XiuzhenworldConstantTypeDesc & temp_m_type = msg.m_type(i);
		m_type[i].read_from_pbmsg(temp_m_type);
	}
}

Sheet_XiuzhenworldConstant_s::Sheet_XiuzhenworldConstant_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_XiuzhenworldConstant_s::CreateInit() {
	return 0;
}

int Sheet_XiuzhenworldConstant_s::ResumeInit() {
	return 0;
}

void Sheet_XiuzhenworldConstant_s::write_to_pbmsg(::proto_ff::Sheet_XiuzhenworldConstant & msg) const {
	for(int32_t i = 0; i < (int32_t)E_XiuzhenworldConstant_List.size(); ++i) {
		::proto_ff::E_XiuzhenworldConstant* temp_e_xiuzhenworldconstant_list = msg.add_e_xiuzhenworldconstant_list();
		E_XiuzhenworldConstant_List[i].write_to_pbmsg(*temp_e_xiuzhenworldconstant_list);
	}
}

void Sheet_XiuzhenworldConstant_s::read_from_pbmsg(const ::proto_ff::Sheet_XiuzhenworldConstant & msg) {
	E_XiuzhenworldConstant_List.resize((int)msg.e_xiuzhenworldconstant_list_size() > (int)E_XiuzhenworldConstant_List.max_size() ? E_XiuzhenworldConstant_List.max_size() : msg.e_xiuzhenworldconstant_list_size());
	for(int32_t i = 0; i < (int32_t)E_XiuzhenworldConstant_List.size(); ++i) {
		const ::proto_ff::E_XiuzhenworldConstant & temp_e_xiuzhenworldconstant_list = msg.e_xiuzhenworldconstant_list(i);
		E_XiuzhenworldConstant_List[i].read_from_pbmsg(temp_e_xiuzhenworldconstant_list);
	}
}

E_XiuzhenworldExpmap_s::E_XiuzhenworldExpmap_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_XiuzhenworldExpmap_s::CreateInit() {
	m_id = (int32_t)0;
	m_conditionglv = (int32_t)0;
	m_mapid = (int32_t)0;
	return 0;
}

int E_XiuzhenworldExpmap_s::ResumeInit() {
	return 0;
}

void E_XiuzhenworldExpmap_s::write_to_pbmsg(::proto_ff::E_XiuzhenworldExpmap & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_conditionglv((int32_t)m_conditionglv);
	msg.set_m_mapid((int32_t)m_mapid);
}

void E_XiuzhenworldExpmap_s::read_from_pbmsg(const ::proto_ff::E_XiuzhenworldExpmap & msg) {
	m_id = msg.m_id();
	m_conditionglv = msg.m_conditionglv();
	m_mapid = msg.m_mapid();
}

Sheet_XiuzhenworldExpmap_s::Sheet_XiuzhenworldExpmap_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_XiuzhenworldExpmap_s::CreateInit() {
	return 0;
}

int Sheet_XiuzhenworldExpmap_s::ResumeInit() {
	return 0;
}

void Sheet_XiuzhenworldExpmap_s::write_to_pbmsg(::proto_ff::Sheet_XiuzhenworldExpmap & msg) const {
	for(int32_t i = 0; i < (int32_t)E_XiuzhenworldExpmap_List.size(); ++i) {
		::proto_ff::E_XiuzhenworldExpmap* temp_e_xiuzhenworldexpmap_list = msg.add_e_xiuzhenworldexpmap_list();
		E_XiuzhenworldExpmap_List[i].write_to_pbmsg(*temp_e_xiuzhenworldexpmap_list);
	}
}

void Sheet_XiuzhenworldExpmap_s::read_from_pbmsg(const ::proto_ff::Sheet_XiuzhenworldExpmap & msg) {
	E_XiuzhenworldExpmap_List.resize((int)msg.e_xiuzhenworldexpmap_list_size() > (int)E_XiuzhenworldExpmap_List.max_size() ? E_XiuzhenworldExpmap_List.max_size() : msg.e_xiuzhenworldexpmap_list_size());
	for(int32_t i = 0; i < (int32_t)E_XiuzhenworldExpmap_List.size(); ++i) {
		const ::proto_ff::E_XiuzhenworldExpmap & temp_e_xiuzhenworldexpmap_list = msg.e_xiuzhenworldexpmap_list(i);
		E_XiuzhenworldExpmap_List[i].read_from_pbmsg(temp_e_xiuzhenworldexpmap_list);
	}
}

}
