#include "point_s.h"

namespace proto_ff_s {

E_PointPoint_s::E_PointPoint_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_PointPoint_s::CreateInit() {
	m_id = (int64_t)0;
	m_belongtosceneid = (int64_t)0;
	return 0;
}

int E_PointPoint_s::ResumeInit() {
	return 0;
}

void E_PointPoint_s::write_to_pbmsg(::proto_ff::E_PointPoint & msg) const {
	msg.set_m_id((int64_t)m_id);
	msg.set_m_belongtosceneid((int64_t)m_belongtosceneid);
}

void E_PointPoint_s::read_from_pbmsg(const ::proto_ff::E_PointPoint & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct E_PointPoint_s));
	m_id = msg.m_id();
	m_belongtosceneid = msg.m_belongtosceneid();
}

Sheet_PointPoint_s::Sheet_PointPoint_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_PointPoint_s::CreateInit() {
	return 0;
}

int Sheet_PointPoint_s::ResumeInit() {
	return 0;
}

void Sheet_PointPoint_s::write_to_pbmsg(::proto_ff::Sheet_PointPoint & msg) const {
	for(int32_t i = 0; i < (int32_t)E_PointPoint_List.size(); ++i) {
		::proto_ff::E_PointPoint* temp_e_pointpoint_list = msg.add_e_pointpoint_list();
		E_PointPoint_List[i].write_to_pbmsg(*temp_e_pointpoint_list);
	}
}

void Sheet_PointPoint_s::read_from_pbmsg(const ::proto_ff::Sheet_PointPoint & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_PointPoint_s));
	E_PointPoint_List.resize((int)msg.e_pointpoint_list_size() > (int)E_PointPoint_List.max_size() ? E_PointPoint_List.max_size() : msg.e_pointpoint_list_size());
	for(int32_t i = 0; i < (int32_t)E_PointPoint_List.size(); ++i) {
		const ::proto_ff::E_PointPoint & temp_e_pointpoint_list = msg.e_pointpoint_list(i);
		E_PointPoint_List[i].read_from_pbmsg(temp_e_pointpoint_list);
	}
}

}