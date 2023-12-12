#include "E_Xiuzhenworld_s.h"

namespace proto_ff_s {

E_XiuzhenworldWorld_s::E_XiuzhenworldWorld_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_XiuzhenworldWorld_s::CreateInit() {
	m_id = (int32_t)0;
	m_type = (int32_t)0;
	m_order = (int32_t)0;
	m_landDup = (int32_t)0;
	return 0;
}

int E_XiuzhenworldWorld_s::ResumeInit() {
	return 0;
}

void E_XiuzhenworldWorld_s::write_to_pbmsg(::proto_ff::E_XiuzhenworldWorld & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_type((int32_t)m_type);
	msg.set_m_order((int32_t)m_order);
	msg.set_m_landdup((int32_t)m_landDup);
}

void E_XiuzhenworldWorld_s::read_from_pbmsg(const ::proto_ff::E_XiuzhenworldWorld & msg) {
	m_id = msg.m_id();
	m_type = msg.m_type();
	m_order = msg.m_order();
	m_landDup = msg.m_landdup();
}

Sheet_XiuzhenworldWorld_s::Sheet_XiuzhenworldWorld_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_XiuzhenworldWorld_s::CreateInit() {
	return 0;
}

int Sheet_XiuzhenworldWorld_s::ResumeInit() {
	return 0;
}

void Sheet_XiuzhenworldWorld_s::write_to_pbmsg(::proto_ff::Sheet_XiuzhenworldWorld & msg) const {
	for(int32_t i = 0; i < (int32_t)E_XiuzhenworldWorld_List.size(); ++i) {
		::proto_ff::E_XiuzhenworldWorld* temp_e_xiuzhenworldworld_list = msg.add_e_xiuzhenworldworld_list();
		E_XiuzhenworldWorld_List[i].write_to_pbmsg(*temp_e_xiuzhenworldworld_list);
	}
}

void Sheet_XiuzhenworldWorld_s::read_from_pbmsg(const ::proto_ff::Sheet_XiuzhenworldWorld & msg) {
	E_XiuzhenworldWorld_List.resize((int)msg.e_xiuzhenworldworld_list_size() > (int)E_XiuzhenworldWorld_List.max_size() ? E_XiuzhenworldWorld_List.max_size() : msg.e_xiuzhenworldworld_list_size());
	for(int32_t i = 0; i < (int32_t)E_XiuzhenworldWorld_List.size(); ++i) {
		const ::proto_ff::E_XiuzhenworldWorld & temp_e_xiuzhenworldworld_list = msg.e_xiuzhenworldworld_list(i);
		E_XiuzhenworldWorld_List[i].read_from_pbmsg(temp_e_xiuzhenworldworld_list);
	}
}

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
	m_ID = (int32_t)0;
	m_starFreeTime = (int32_t)0;
	m_freeTime = (int32_t)0;
	m_freeTimeMax = (int32_t)0;
	m_helpid = (int32_t)0;
	m_addGExpMax = (int32_t)0;
	m_priPriceType = (int32_t)0;
	m_priceValue = (int32_t)0;
	m_GExpPriBonus = (int32_t)0;
	m_GExpGroupBonus = (int32_t)0;
	m_mapStart = (int32_t)0;
	m_mapEnd = (int32_t)0;
	m_expItemId = (int32_t)0;
	return 0;
}

int E_XiuzhenworldConstant_s::ResumeInit() {
	return 0;
}

void E_XiuzhenworldConstant_s::write_to_pbmsg(::proto_ff::E_XiuzhenworldConstant & msg) const {
	msg.set_m_id((int32_t)m_ID);
	msg.set_m_starfreetime((int32_t)m_starFreeTime);
	msg.set_m_freetimemoment(m_freeTimeMoment.data());
	msg.set_m_freetime((int32_t)m_freeTime);
	msg.set_m_freetimemax((int32_t)m_freeTimeMax);
	msg.set_m_helpid((int32_t)m_helpid);
	msg.set_m_addgexpmax((int32_t)m_addGExpMax);
	msg.set_m_pripricetype((int32_t)m_priPriceType);
	msg.set_m_pricevalue((int32_t)m_priceValue);
	msg.set_m_gexppribonus((int32_t)m_GExpPriBonus);
	msg.set_m_gexpgroupbonus((int32_t)m_GExpGroupBonus);
	msg.set_m_mapstart((int32_t)m_mapStart);
	msg.set_m_mapend((int32_t)m_mapEnd);
	msg.set_m_expitemid((int32_t)m_expItemId);
	for(int32_t i = 0; i < (int32_t)m_timeItem.size(); ++i) {
		::proto_ff::E_XiuzhenworldConstantTimeitemDesc* temp_m_timeitem = msg.add_m_timeitem();
		m_timeItem[i].write_to_pbmsg(*temp_m_timeitem);
	}
	for(int32_t i = 0; i < (int32_t)m_type.size(); ++i) {
		::proto_ff::E_XiuzhenworldConstantTypeDesc* temp_m_type = msg.add_m_type();
		m_type[i].write_to_pbmsg(*temp_m_type);
	}
}

void E_XiuzhenworldConstant_s::read_from_pbmsg(const ::proto_ff::E_XiuzhenworldConstant & msg) {
	m_ID = msg.m_id();
	m_starFreeTime = msg.m_starfreetime();
	m_freeTimeMoment = msg.m_freetimemoment();
	m_freeTime = msg.m_freetime();
	m_freeTimeMax = msg.m_freetimemax();
	m_helpid = msg.m_helpid();
	m_addGExpMax = msg.m_addgexpmax();
	m_priPriceType = msg.m_pripricetype();
	m_priceValue = msg.m_pricevalue();
	m_GExpPriBonus = msg.m_gexppribonus();
	m_GExpGroupBonus = msg.m_gexpgroupbonus();
	m_mapStart = msg.m_mapstart();
	m_mapEnd = msg.m_mapend();
	m_expItemId = msg.m_expitemid();
	m_timeItem.resize((int)msg.m_timeitem_size() > (int)m_timeItem.max_size() ? m_timeItem.max_size() : msg.m_timeitem_size());
	for(int32_t i = 0; i < (int32_t)m_timeItem.size(); ++i) {
		const ::proto_ff::E_XiuzhenworldConstantTimeitemDesc & temp_m_timeitem = msg.m_timeitem(i);
		m_timeItem[i].read_from_pbmsg(temp_m_timeitem);
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
	m_conditionGlv = (int32_t)0;
	m_mapid = (int32_t)0;
	return 0;
}

int E_XiuzhenworldExpmap_s::ResumeInit() {
	return 0;
}

void E_XiuzhenworldExpmap_s::write_to_pbmsg(::proto_ff::E_XiuzhenworldExpmap & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_conditionglv((int32_t)m_conditionGlv);
	msg.set_m_mapid((int32_t)m_mapid);
}

void E_XiuzhenworldExpmap_s::read_from_pbmsg(const ::proto_ff::E_XiuzhenworldExpmap & msg) {
	m_id = msg.m_id();
	m_conditionGlv = msg.m_conditionglv();
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
