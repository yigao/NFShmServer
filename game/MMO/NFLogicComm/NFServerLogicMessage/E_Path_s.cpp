#include "E_Path_s.h"

namespace proto_ff_s {

E_PathPath_s::E_PathPath_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_PathPath_s::CreateInit() {
	m_id = (int64_t)0;
	m_belongtosceneid = (int64_t)0;
	return 0;
}

int E_PathPath_s::ResumeInit() {
	return 0;
}

void E_PathPath_s::write_to_pbmsg(::proto_ff::E_PathPath & msg) const {
	msg.set_m_id((int64_t)m_id);
	msg.set_m_belongtosceneid((int64_t)m_belongtosceneid);
}

void E_PathPath_s::read_from_pbmsg(const ::proto_ff::E_PathPath & msg) {
	m_id = msg.m_id();
	m_belongtosceneid = msg.m_belongtosceneid();
}

Sheet_PathPath_s::Sheet_PathPath_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_PathPath_s::CreateInit() {
	return 0;
}

int Sheet_PathPath_s::ResumeInit() {
	return 0;
}

void Sheet_PathPath_s::write_to_pbmsg(::proto_ff::Sheet_PathPath & msg) const {
	for(int32_t i = 0; i < (int32_t)E_PathPath_List.size(); ++i) {
		::proto_ff::E_PathPath* temp_e_pathpath_list = msg.add_e_pathpath_list();
		E_PathPath_List[i].write_to_pbmsg(*temp_e_pathpath_list);
	}
}

void Sheet_PathPath_s::read_from_pbmsg(const ::proto_ff::Sheet_PathPath & msg) {
	E_PathPath_List.resize((int)msg.e_pathpath_list_size() > (int)E_PathPath_List.max_size() ? E_PathPath_List.max_size() : msg.e_pathpath_list_size());
	for(int32_t i = 0; i < (int32_t)E_PathPath_List.size(); ++i) {
		const ::proto_ff::E_PathPath & temp_e_pathpath_list = msg.e_pathpath_list(i);
		E_PathPath_List[i].read_from_pbmsg(temp_e_pathpath_list);
	}
}

}
