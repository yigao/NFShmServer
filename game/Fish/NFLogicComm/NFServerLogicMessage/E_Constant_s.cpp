#include "E_Constant_s.h"

namespace proto_ff_s {

E_ConstantConstant_s::E_ConstantConstant_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_ConstantConstant_s::CreateInit() {
	m_constantid = (int32_t)0;
	m_constantdata = (int64_t)0;
	return 0;
}

int E_ConstantConstant_s::ResumeInit() {
	return 0;
}

void E_ConstantConstant_s::write_to_pbmsg(::proto_ff::E_ConstantConstant & msg) const {
	msg.set_m_constantid((int32_t)m_constantid);
	msg.set_m_constantdata((int64_t)m_constantdata);
	msg.set_m_stringdata(m_stringdata.data());
}

void E_ConstantConstant_s::read_from_pbmsg(const ::proto_ff::E_ConstantConstant & msg) {
	m_constantid = msg.m_constantid();
	m_constantdata = msg.m_constantdata();
	m_stringdata = msg.m_stringdata();
}

Sheet_ConstantConstant_s::Sheet_ConstantConstant_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_ConstantConstant_s::CreateInit() {
	return 0;
}

int Sheet_ConstantConstant_s::ResumeInit() {
	return 0;
}

void Sheet_ConstantConstant_s::write_to_pbmsg(::proto_ff::Sheet_ConstantConstant & msg) const {
	for(int32_t i = 0; i < (int32_t)E_ConstantConstant_List.size(); ++i) {
		::proto_ff::E_ConstantConstant* temp_e_constantconstant_list = msg.add_e_constantconstant_list();
		E_ConstantConstant_List[i].write_to_pbmsg(*temp_e_constantconstant_list);
	}
}

void Sheet_ConstantConstant_s::read_from_pbmsg(const ::proto_ff::Sheet_ConstantConstant & msg) {
	E_ConstantConstant_List.resize((int)msg.e_constantconstant_list_size() > (int)E_ConstantConstant_List.max_size() ? E_ConstantConstant_List.max_size() : msg.e_constantconstant_list_size());
	for(int32_t i = 0; i < (int32_t)E_ConstantConstant_List.size(); ++i) {
		const ::proto_ff::E_ConstantConstant & temp_e_constantconstant_list = msg.e_constantconstant_list(i);
		E_ConstantConstant_List[i].read_from_pbmsg(temp_e_constantconstant_list);
	}
}

}
