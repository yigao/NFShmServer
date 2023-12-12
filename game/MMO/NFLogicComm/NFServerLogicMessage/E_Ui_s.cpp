#include "E_Ui_s.h"

namespace proto_ff_s {

E_UiEffect_s::E_UiEffect_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_UiEffect_s::CreateInit() {
	m_id = (int64_t)0;
	return 0;
}

int E_UiEffect_s::ResumeInit() {
	return 0;
}

void E_UiEffect_s::write_to_pbmsg(::proto_ff::E_UiEffect & msg) const {
	msg.set_m_id((int64_t)m_id);
}

void E_UiEffect_s::read_from_pbmsg(const ::proto_ff::E_UiEffect & msg) {
	m_id = msg.m_id();
}

Sheet_UiEffect_s::Sheet_UiEffect_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_UiEffect_s::CreateInit() {
	return 0;
}

int Sheet_UiEffect_s::ResumeInit() {
	return 0;
}

void Sheet_UiEffect_s::write_to_pbmsg(::proto_ff::Sheet_UiEffect & msg) const {
	for(int32_t i = 0; i < (int32_t)E_UiEffect_List.size(); ++i) {
		::proto_ff::E_UiEffect* temp_e_uieffect_list = msg.add_e_uieffect_list();
		E_UiEffect_List[i].write_to_pbmsg(*temp_e_uieffect_list);
	}
}

void Sheet_UiEffect_s::read_from_pbmsg(const ::proto_ff::Sheet_UiEffect & msg) {
	E_UiEffect_List.resize((int)msg.e_uieffect_list_size() > (int)E_UiEffect_List.max_size() ? E_UiEffect_List.max_size() : msg.e_uieffect_list_size());
	for(int32_t i = 0; i < (int32_t)E_UiEffect_List.size(); ++i) {
		const ::proto_ff::E_UiEffect & temp_e_uieffect_list = msg.e_uieffect_list(i);
		E_UiEffect_List[i].read_from_pbmsg(temp_e_uieffect_list);
	}
}

}
