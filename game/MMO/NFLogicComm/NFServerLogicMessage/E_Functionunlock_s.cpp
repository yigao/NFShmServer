#include "E_Functionunlock_s.h"

namespace proto_ff_s {

E_FunctionunlockFunctionunlock_s::E_FunctionunlockFunctionunlock_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_FunctionunlockFunctionunlock_s::CreateInit() {
	m_functionid = (int32_t)0;
	m_opendaily = (int32_t)0;
	m_opentype = (int32_t)0;
	m_openval = (int64_t)0;
	m_defaultclosed = (int32_t)0;
	m_iconopenval = (int32_t)0;
	m_icondisapearid = (int32_t)0;
	m_belong = (int32_t)0;
	return 0;
}

int E_FunctionunlockFunctionunlock_s::ResumeInit() {
	return 0;
}

void E_FunctionunlockFunctionunlock_s::write_to_pbmsg(::proto_ff::E_FunctionunlockFunctionunlock & msg) const {
	msg.set_m_functionid((int32_t)m_functionid);
	msg.set_m_opendaily((int32_t)m_opendaily);
	msg.set_m_opentype((int32_t)m_opentype);
	msg.set_m_openval((int64_t)m_openval);
	msg.set_m_defaultclosed((int32_t)m_defaultclosed);
	msg.set_m_iconopenval((int32_t)m_iconopenval);
	msg.set_m_icondisapearid((int32_t)m_icondisapearid);
	msg.set_m_belong((int32_t)m_belong);
}

void E_FunctionunlockFunctionunlock_s::read_from_pbmsg(const ::proto_ff::E_FunctionunlockFunctionunlock & msg) {
	m_functionid = msg.m_functionid();
	m_opendaily = msg.m_opendaily();
	m_opentype = msg.m_opentype();
	m_openval = msg.m_openval();
	m_defaultclosed = msg.m_defaultclosed();
	m_iconopenval = msg.m_iconopenval();
	m_icondisapearid = msg.m_icondisapearid();
	m_belong = msg.m_belong();
}

Sheet_FunctionunlockFunctionunlock_s::Sheet_FunctionunlockFunctionunlock_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_FunctionunlockFunctionunlock_s::CreateInit() {
	return 0;
}

int Sheet_FunctionunlockFunctionunlock_s::ResumeInit() {
	return 0;
}

void Sheet_FunctionunlockFunctionunlock_s::write_to_pbmsg(::proto_ff::Sheet_FunctionunlockFunctionunlock & msg) const {
	for(int32_t i = 0; i < (int32_t)E_FunctionunlockFunctionunlock_List.size(); ++i) {
		::proto_ff::E_FunctionunlockFunctionunlock* temp_e_functionunlockfunctionunlock_list = msg.add_e_functionunlockfunctionunlock_list();
		E_FunctionunlockFunctionunlock_List[i].write_to_pbmsg(*temp_e_functionunlockfunctionunlock_list);
	}
}

void Sheet_FunctionunlockFunctionunlock_s::read_from_pbmsg(const ::proto_ff::Sheet_FunctionunlockFunctionunlock & msg) {
	E_FunctionunlockFunctionunlock_List.resize((int)msg.e_functionunlockfunctionunlock_list_size() > (int)E_FunctionunlockFunctionunlock_List.max_size() ? E_FunctionunlockFunctionunlock_List.max_size() : msg.e_functionunlockfunctionunlock_list_size());
	for(int32_t i = 0; i < (int32_t)E_FunctionunlockFunctionunlock_List.size(); ++i) {
		const ::proto_ff::E_FunctionunlockFunctionunlock & temp_e_functionunlockfunctionunlock_list = msg.e_functionunlockfunctionunlock_list(i);
		E_FunctionunlockFunctionunlock_List[i].read_from_pbmsg(temp_e_functionunlockfunctionunlock_list);
	}
}

E_FunctionunlockPreview_s::E_FunctionunlockPreview_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_FunctionunlockPreview_s::CreateInit() {
	m_functionid = (int32_t)0;
	m_rewarditem = (int32_t)0;
	m_rewardnum = (int32_t)0;
	return 0;
}

int E_FunctionunlockPreview_s::ResumeInit() {
	return 0;
}

void E_FunctionunlockPreview_s::write_to_pbmsg(::proto_ff::E_FunctionunlockPreview & msg) const {
	msg.set_m_functionid((int32_t)m_functionid);
	msg.set_m_rewarditem((int32_t)m_rewarditem);
	msg.set_m_rewardnum((int32_t)m_rewardnum);
}

void E_FunctionunlockPreview_s::read_from_pbmsg(const ::proto_ff::E_FunctionunlockPreview & msg) {
	m_functionid = msg.m_functionid();
	m_rewarditem = msg.m_rewarditem();
	m_rewardnum = msg.m_rewardnum();
}

Sheet_FunctionunlockPreview_s::Sheet_FunctionunlockPreview_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_FunctionunlockPreview_s::CreateInit() {
	return 0;
}

int Sheet_FunctionunlockPreview_s::ResumeInit() {
	return 0;
}

void Sheet_FunctionunlockPreview_s::write_to_pbmsg(::proto_ff::Sheet_FunctionunlockPreview & msg) const {
	for(int32_t i = 0; i < (int32_t)E_FunctionunlockPreview_List.size(); ++i) {
		::proto_ff::E_FunctionunlockPreview* temp_e_functionunlockpreview_list = msg.add_e_functionunlockpreview_list();
		E_FunctionunlockPreview_List[i].write_to_pbmsg(*temp_e_functionunlockpreview_list);
	}
}

void Sheet_FunctionunlockPreview_s::read_from_pbmsg(const ::proto_ff::Sheet_FunctionunlockPreview & msg) {
	E_FunctionunlockPreview_List.resize((int)msg.e_functionunlockpreview_list_size() > (int)E_FunctionunlockPreview_List.max_size() ? E_FunctionunlockPreview_List.max_size() : msg.e_functionunlockpreview_list_size());
	for(int32_t i = 0; i < (int32_t)E_FunctionunlockPreview_List.size(); ++i) {
		const ::proto_ff::E_FunctionunlockPreview & temp_e_functionunlockpreview_list = msg.e_functionunlockpreview_list(i);
		E_FunctionunlockPreview_List[i].read_from_pbmsg(temp_e_functionunlockpreview_list);
	}
}

}
