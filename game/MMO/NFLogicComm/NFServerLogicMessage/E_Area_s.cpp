#include "E_Area_s.h"

namespace proto_ff_s {

E_AreaArea_s::E_AreaArea_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_AreaArea_s::CreateInit() {
	m_id = (int64_t)0;
	m_subType = (int32_t)0;
	m_belongToSceneID = (int64_t)0;
	m_shapeType = (int32_t)0;
	m_isNotice = (int32_t)0;
	return 0;
}

int E_AreaArea_s::ResumeInit() {
	return 0;
}

void E_AreaArea_s::write_to_pbmsg(::proto_ff::E_AreaArea & msg) const {
	msg.set_m_id((int64_t)m_id);
	msg.set_m_subtype((int32_t)m_subType);
	msg.set_m_belongtosceneid((int64_t)m_belongToSceneID);
	msg.set_m_shapetype((int32_t)m_shapeType);
	msg.set_m_isnotice((int32_t)m_isNotice);
}

void E_AreaArea_s::read_from_pbmsg(const ::proto_ff::E_AreaArea & msg) {
	m_id = msg.m_id();
	m_subType = msg.m_subtype();
	m_belongToSceneID = msg.m_belongtosceneid();
	m_shapeType = msg.m_shapetype();
	m_isNotice = msg.m_isnotice();
}

Sheet_AreaArea_s::Sheet_AreaArea_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_AreaArea_s::CreateInit() {
	return 0;
}

int Sheet_AreaArea_s::ResumeInit() {
	return 0;
}

void Sheet_AreaArea_s::write_to_pbmsg(::proto_ff::Sheet_AreaArea & msg) const {
	for(int32_t i = 0; i < (int32_t)E_AreaArea_List.size(); ++i) {
		::proto_ff::E_AreaArea* temp_e_areaarea_list = msg.add_e_areaarea_list();
		E_AreaArea_List[i].write_to_pbmsg(*temp_e_areaarea_list);
	}
}

void Sheet_AreaArea_s::read_from_pbmsg(const ::proto_ff::Sheet_AreaArea & msg) {
	E_AreaArea_List.resize((int)msg.e_areaarea_list_size() > (int)E_AreaArea_List.max_size() ? E_AreaArea_List.max_size() : msg.e_areaarea_list_size());
	for(int32_t i = 0; i < (int32_t)E_AreaArea_List.size(); ++i) {
		const ::proto_ff::E_AreaArea & temp_e_areaarea_list = msg.e_areaarea_list(i);
		E_AreaArea_List[i].read_from_pbmsg(temp_e_areaarea_list);
	}
}

}
