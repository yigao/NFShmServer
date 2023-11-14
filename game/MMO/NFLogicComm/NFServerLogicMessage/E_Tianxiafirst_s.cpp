#include "E_Tianxiafirst_s.h"

namespace proto_ff_s {

E_TianxiafirstActivateAttDesc_s::E_TianxiafirstActivateAttDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_TianxiafirstActivateAttDesc_s::CreateInit() {
	m_value = (int32_t)0;
	m_id = (int32_t)0;
	return 0;
}

int E_TianxiafirstActivateAttDesc_s::ResumeInit() {
	return 0;
}

void E_TianxiafirstActivateAttDesc_s::write_to_pbmsg(::proto_ff::E_TianxiafirstActivateAttDesc & msg) const {
	msg.set_m_value((int32_t)m_value);
	msg.set_m_id((int32_t)m_id);
}

void E_TianxiafirstActivateAttDesc_s::read_from_pbmsg(const ::proto_ff::E_TianxiafirstActivateAttDesc & msg) {
	m_value = msg.m_value();
	m_id = msg.m_id();
}

E_TianxiafirstActivateModelDesc_s::E_TianxiafirstActivateModelDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_TianxiafirstActivateModelDesc_s::CreateInit() {
	m_condition = (int32_t)0;
	m_id = (int32_t)0;
	return 0;
}

int E_TianxiafirstActivateModelDesc_s::ResumeInit() {
	return 0;
}

void E_TianxiafirstActivateModelDesc_s::write_to_pbmsg(::proto_ff::E_TianxiafirstActivateModelDesc & msg) const {
	msg.set_m_condition((int32_t)m_condition);
	msg.set_m_id((int32_t)m_id);
}

void E_TianxiafirstActivateModelDesc_s::read_from_pbmsg(const ::proto_ff::E_TianxiafirstActivateModelDesc & msg) {
	m_condition = msg.m_condition();
	m_id = msg.m_id();
}

E_TianxiafirstActivate_s::E_TianxiafirstActivate_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_TianxiafirstActivate_s::CreateInit() {
	m_artifactId = (int32_t)0;
	m_preId = (int32_t)0;
	m_condition = (int32_t)0;
	return 0;
}

int E_TianxiafirstActivate_s::ResumeInit() {
	return 0;
}

void E_TianxiafirstActivate_s::write_to_pbmsg(::proto_ff::E_TianxiafirstActivate & msg) const {
	msg.set_m_artifactid((int32_t)m_artifactId);
	msg.set_m_preid((int32_t)m_preId);
	msg.set_m_condition((int32_t)m_condition);
	for(int32_t i = 0; i < (int32_t)m_att.size(); ++i) {
		::proto_ff::E_TianxiafirstActivateAttDesc* temp_m_att = msg.add_m_att();
		m_att[i].write_to_pbmsg(*temp_m_att);
	}
	for(int32_t i = 0; i < (int32_t)m_model.size(); ++i) {
		::proto_ff::E_TianxiafirstActivateModelDesc* temp_m_model = msg.add_m_model();
		m_model[i].write_to_pbmsg(*temp_m_model);
	}
}

void E_TianxiafirstActivate_s::read_from_pbmsg(const ::proto_ff::E_TianxiafirstActivate & msg) {
	m_artifactId = msg.m_artifactid();
	m_preId = msg.m_preid();
	m_condition = msg.m_condition();
	m_att.resize((int)msg.m_att_size() > (int)m_att.max_size() ? m_att.max_size() : msg.m_att_size());
	for(int32_t i = 0; i < (int32_t)m_att.size(); ++i) {
		const ::proto_ff::E_TianxiafirstActivateAttDesc & temp_m_att = msg.m_att(i);
		m_att[i].read_from_pbmsg(temp_m_att);
	}
	m_model.resize((int)msg.m_model_size() > (int)m_model.max_size() ? m_model.max_size() : msg.m_model_size());
	for(int32_t i = 0; i < (int32_t)m_model.size(); ++i) {
		const ::proto_ff::E_TianxiafirstActivateModelDesc & temp_m_model = msg.m_model(i);
		m_model[i].read_from_pbmsg(temp_m_model);
	}
}

Sheet_TianxiafirstActivate_s::Sheet_TianxiafirstActivate_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_TianxiafirstActivate_s::CreateInit() {
	return 0;
}

int Sheet_TianxiafirstActivate_s::ResumeInit() {
	return 0;
}

void Sheet_TianxiafirstActivate_s::write_to_pbmsg(::proto_ff::Sheet_TianxiafirstActivate & msg) const {
	for(int32_t i = 0; i < (int32_t)E_TianxiafirstActivate_List.size(); ++i) {
		::proto_ff::E_TianxiafirstActivate* temp_e_tianxiafirstactivate_list = msg.add_e_tianxiafirstactivate_list();
		E_TianxiafirstActivate_List[i].write_to_pbmsg(*temp_e_tianxiafirstactivate_list);
	}
}

void Sheet_TianxiafirstActivate_s::read_from_pbmsg(const ::proto_ff::Sheet_TianxiafirstActivate & msg) {
	E_TianxiafirstActivate_List.resize((int)msg.e_tianxiafirstactivate_list_size() > (int)E_TianxiafirstActivate_List.max_size() ? E_TianxiafirstActivate_List.max_size() : msg.e_tianxiafirstactivate_list_size());
	for(int32_t i = 0; i < (int32_t)E_TianxiafirstActivate_List.size(); ++i) {
		const ::proto_ff::E_TianxiafirstActivate & temp_e_tianxiafirstactivate_list = msg.e_tianxiafirstactivate_list(i);
		E_TianxiafirstActivate_List[i].read_from_pbmsg(temp_e_tianxiafirstactivate_list);
	}
}

E_TianxiafirstStrongTypeDesc_s::E_TianxiafirstStrongTypeDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_TianxiafirstStrongTypeDesc_s::CreateInit() {
	m_id = (int32_t)0;
	return 0;
}

int E_TianxiafirstStrongTypeDesc_s::ResumeInit() {
	return 0;
}

void E_TianxiafirstStrongTypeDesc_s::write_to_pbmsg(::proto_ff::E_TianxiafirstStrongTypeDesc & msg) const {
	msg.set_m_num(m_num.data());
	msg.set_m_id((int32_t)m_id);
}

void E_TianxiafirstStrongTypeDesc_s::read_from_pbmsg(const ::proto_ff::E_TianxiafirstStrongTypeDesc & msg) {
	m_num = msg.m_num();
	m_id = msg.m_id();
}

E_TianxiafirstStrong_s::E_TianxiafirstStrong_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_TianxiafirstStrong_s::CreateInit() {
	m_artifactId = (int32_t)0;
	m_strongUp = (int32_t)0;
	return 0;
}

int E_TianxiafirstStrong_s::ResumeInit() {
	return 0;
}

void E_TianxiafirstStrong_s::write_to_pbmsg(::proto_ff::E_TianxiafirstStrong & msg) const {
	msg.set_m_artifactid((int32_t)m_artifactId);
	msg.set_m_strongup((int32_t)m_strongUp);
	msg.set_m_exp(m_exp.data());
	for(int32_t i = 0; i < (int32_t)m_type.size(); ++i) {
		::proto_ff::E_TianxiafirstStrongTypeDesc* temp_m_type = msg.add_m_type();
		m_type[i].write_to_pbmsg(*temp_m_type);
	}
}

void E_TianxiafirstStrong_s::read_from_pbmsg(const ::proto_ff::E_TianxiafirstStrong & msg) {
	m_artifactId = msg.m_artifactid();
	m_strongUp = msg.m_strongup();
	m_exp = msg.m_exp();
	m_type.resize((int)msg.m_type_size() > (int)m_type.max_size() ? m_type.max_size() : msg.m_type_size());
	for(int32_t i = 0; i < (int32_t)m_type.size(); ++i) {
		const ::proto_ff::E_TianxiafirstStrongTypeDesc & temp_m_type = msg.m_type(i);
		m_type[i].read_from_pbmsg(temp_m_type);
	}
}

Sheet_TianxiafirstStrong_s::Sheet_TianxiafirstStrong_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_TianxiafirstStrong_s::CreateInit() {
	return 0;
}

int Sheet_TianxiafirstStrong_s::ResumeInit() {
	return 0;
}

void Sheet_TianxiafirstStrong_s::write_to_pbmsg(::proto_ff::Sheet_TianxiafirstStrong & msg) const {
	for(int32_t i = 0; i < (int32_t)E_TianxiafirstStrong_List.size(); ++i) {
		::proto_ff::E_TianxiafirstStrong* temp_e_tianxiafirststrong_list = msg.add_e_tianxiafirststrong_list();
		E_TianxiafirstStrong_List[i].write_to_pbmsg(*temp_e_tianxiafirststrong_list);
	}
}

void Sheet_TianxiafirstStrong_s::read_from_pbmsg(const ::proto_ff::Sheet_TianxiafirstStrong & msg) {
	E_TianxiafirstStrong_List.resize((int)msg.e_tianxiafirststrong_list_size() > (int)E_TianxiafirstStrong_List.max_size() ? E_TianxiafirstStrong_List.max_size() : msg.e_tianxiafirststrong_list_size());
	for(int32_t i = 0; i < (int32_t)E_TianxiafirstStrong_List.size(); ++i) {
		const ::proto_ff::E_TianxiafirstStrong & temp_e_tianxiafirststrong_list = msg.e_tianxiafirststrong_list(i);
		E_TianxiafirstStrong_List[i].read_from_pbmsg(temp_e_tianxiafirststrong_list);
	}
}

E_TianxiafirstStrongitem_s::E_TianxiafirstStrongitem_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_TianxiafirstStrongitem_s::CreateInit() {
	m_id = (int32_t)0;
	m_addExp = (int32_t)0;
	return 0;
}

int E_TianxiafirstStrongitem_s::ResumeInit() {
	return 0;
}

void E_TianxiafirstStrongitem_s::write_to_pbmsg(::proto_ff::E_TianxiafirstStrongitem & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_addexp((int32_t)m_addExp);
}

void E_TianxiafirstStrongitem_s::read_from_pbmsg(const ::proto_ff::E_TianxiafirstStrongitem & msg) {
	m_id = msg.m_id();
	m_addExp = msg.m_addexp();
}

Sheet_TianxiafirstStrongitem_s::Sheet_TianxiafirstStrongitem_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_TianxiafirstStrongitem_s::CreateInit() {
	return 0;
}

int Sheet_TianxiafirstStrongitem_s::ResumeInit() {
	return 0;
}

void Sheet_TianxiafirstStrongitem_s::write_to_pbmsg(::proto_ff::Sheet_TianxiafirstStrongitem & msg) const {
	for(int32_t i = 0; i < (int32_t)E_TianxiafirstStrongitem_List.size(); ++i) {
		::proto_ff::E_TianxiafirstStrongitem* temp_e_tianxiafirststrongitem_list = msg.add_e_tianxiafirststrongitem_list();
		E_TianxiafirstStrongitem_List[i].write_to_pbmsg(*temp_e_tianxiafirststrongitem_list);
	}
}

void Sheet_TianxiafirstStrongitem_s::read_from_pbmsg(const ::proto_ff::Sheet_TianxiafirstStrongitem & msg) {
	E_TianxiafirstStrongitem_List.resize((int)msg.e_tianxiafirststrongitem_list_size() > (int)E_TianxiafirstStrongitem_List.max_size() ? E_TianxiafirstStrongitem_List.max_size() : msg.e_tianxiafirststrongitem_list_size());
	for(int32_t i = 0; i < (int32_t)E_TianxiafirstStrongitem_List.size(); ++i) {
		const ::proto_ff::E_TianxiafirstStrongitem & temp_e_tianxiafirststrongitem_list = msg.e_tianxiafirststrongitem_list(i);
		E_TianxiafirstStrongitem_List[i].read_from_pbmsg(temp_e_tianxiafirststrongitem_list);
	}
}

E_TianxiafirstRefineAttDesc_s::E_TianxiafirstRefineAttDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_TianxiafirstRefineAttDesc_s::CreateInit() {
	m_num = (int32_t)0;
	m_id = (int32_t)0;
	return 0;
}

int E_TianxiafirstRefineAttDesc_s::ResumeInit() {
	return 0;
}

void E_TianxiafirstRefineAttDesc_s::write_to_pbmsg(::proto_ff::E_TianxiafirstRefineAttDesc & msg) const {
	msg.set_m_num((int32_t)m_num);
	msg.set_m_id((int32_t)m_id);
}

void E_TianxiafirstRefineAttDesc_s::read_from_pbmsg(const ::proto_ff::E_TianxiafirstRefineAttDesc & msg) {
	m_num = msg.m_num();
	m_id = msg.m_id();
}

E_TianxiafirstRefine_s::E_TianxiafirstRefine_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_TianxiafirstRefine_s::CreateInit() {
	m_id = (int32_t)0;
	m_artifactId = (int32_t)0;
	m_stage = (int32_t)0;
	m_star = (int32_t)0;
	m_success = (int32_t)0;
	m_consumeItem = (int32_t)0;
	m_consumeNum = (int32_t)0;
	m_guarant = (int32_t)0;
	return 0;
}

int E_TianxiafirstRefine_s::ResumeInit() {
	return 0;
}

void E_TianxiafirstRefine_s::write_to_pbmsg(::proto_ff::E_TianxiafirstRefine & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_artifactid((int32_t)m_artifactId);
	msg.set_m_stage((int32_t)m_stage);
	msg.set_m_star((int32_t)m_star);
	msg.set_m_success((int32_t)m_success);
	msg.set_m_consumeitem((int32_t)m_consumeItem);
	msg.set_m_consumenum((int32_t)m_consumeNum);
	msg.set_m_guarant((int32_t)m_guarant);
	for(int32_t i = 0; i < (int32_t)m_att.size(); ++i) {
		::proto_ff::E_TianxiafirstRefineAttDesc* temp_m_att = msg.add_m_att();
		m_att[i].write_to_pbmsg(*temp_m_att);
	}
}

void E_TianxiafirstRefine_s::read_from_pbmsg(const ::proto_ff::E_TianxiafirstRefine & msg) {
	m_id = msg.m_id();
	m_artifactId = msg.m_artifactid();
	m_stage = msg.m_stage();
	m_star = msg.m_star();
	m_success = msg.m_success();
	m_consumeItem = msg.m_consumeitem();
	m_consumeNum = msg.m_consumenum();
	m_guarant = msg.m_guarant();
	m_att.resize((int)msg.m_att_size() > (int)m_att.max_size() ? m_att.max_size() : msg.m_att_size());
	for(int32_t i = 0; i < (int32_t)m_att.size(); ++i) {
		const ::proto_ff::E_TianxiafirstRefineAttDesc & temp_m_att = msg.m_att(i);
		m_att[i].read_from_pbmsg(temp_m_att);
	}
}

Sheet_TianxiafirstRefine_s::Sheet_TianxiafirstRefine_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_TianxiafirstRefine_s::CreateInit() {
	return 0;
}

int Sheet_TianxiafirstRefine_s::ResumeInit() {
	return 0;
}

void Sheet_TianxiafirstRefine_s::write_to_pbmsg(::proto_ff::Sheet_TianxiafirstRefine & msg) const {
	for(int32_t i = 0; i < (int32_t)E_TianxiafirstRefine_List.size(); ++i) {
		::proto_ff::E_TianxiafirstRefine* temp_e_tianxiafirstrefine_list = msg.add_e_tianxiafirstrefine_list();
		E_TianxiafirstRefine_List[i].write_to_pbmsg(*temp_e_tianxiafirstrefine_list);
	}
}

void Sheet_TianxiafirstRefine_s::read_from_pbmsg(const ::proto_ff::Sheet_TianxiafirstRefine & msg) {
	E_TianxiafirstRefine_List.resize((int)msg.e_tianxiafirstrefine_list_size() > (int)E_TianxiafirstRefine_List.max_size() ? E_TianxiafirstRefine_List.max_size() : msg.e_tianxiafirstrefine_list_size());
	for(int32_t i = 0; i < (int32_t)E_TianxiafirstRefine_List.size(); ++i) {
		const ::proto_ff::E_TianxiafirstRefine & temp_e_tianxiafirstrefine_list = msg.e_tianxiafirstrefine_list(i);
		E_TianxiafirstRefine_List[i].read_from_pbmsg(temp_e_tianxiafirstrefine_list);
	}
}

}
