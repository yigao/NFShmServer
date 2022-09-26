#include "occupation_s.h"

namespace proto_ff_s {

occupationoccupationattributeDesc_s::occupationoccupationattributeDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int occupationoccupationattributeDesc_s::CreateInit() {
	type = (int32_t)0;
	return 0;
}

int occupationoccupationattributeDesc_s::ResumeInit() {
	return 0;
}

void occupationoccupationattributeDesc_s::write_to_pbmsg(::proto_ff::occupationoccupationattributeDesc & msg) const {
	msg.set_type((int32_t)type);
}

void occupationoccupationattributeDesc_s::read_from_pbmsg(const ::proto_ff::occupationoccupationattributeDesc & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct occupationoccupationattributeDesc_s));
	type = msg.type();
}

occupationoccupationdelSkillDesc_s::occupationoccupationdelSkillDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int occupationoccupationdelSkillDesc_s::CreateInit() {
	id = (int64_t)0;
	return 0;
}

int occupationoccupationdelSkillDesc_s::ResumeInit() {
	return 0;
}

void occupationoccupationdelSkillDesc_s::write_to_pbmsg(::proto_ff::occupationoccupationdelSkillDesc & msg) const {
	msg.set_id((int64_t)id);
}

void occupationoccupationdelSkillDesc_s::read_from_pbmsg(const ::proto_ff::occupationoccupationdelSkillDesc & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct occupationoccupationdelSkillDesc_s));
	id = msg.id();
}

occupationoccupationskillDesc_s::occupationoccupationskillDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int occupationoccupationskillDesc_s::CreateInit() {
	id = (int64_t)0;
	return 0;
}

int occupationoccupationskillDesc_s::ResumeInit() {
	return 0;
}

void occupationoccupationskillDesc_s::write_to_pbmsg(::proto_ff::occupationoccupationskillDesc & msg) const {
	msg.set_id((int64_t)id);
}

void occupationoccupationskillDesc_s::read_from_pbmsg(const ::proto_ff::occupationoccupationskillDesc & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct occupationoccupationskillDesc_s));
	id = msg.id();
}

occupationoccupation_s::occupationoccupation_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int occupationoccupation_s::CreateInit() {
	occupationID = (int64_t)0;
	id = (int32_t)0;
	grade = (int32_t)0;
	level = (int32_t)0;
	aptitude = (int64_t)0;
	return 0;
}

int occupationoccupation_s::ResumeInit() {
	return 0;
}

void occupationoccupation_s::write_to_pbmsg(::proto_ff::occupationoccupation & msg) const {
	msg.set_occupationid((int64_t)occupationID);
	msg.set_id((int32_t)id);
	msg.set_grade((int32_t)grade);
	msg.set_activedesc((const char*)activeDesc.Get());
	msg.set_level((int32_t)level);
	msg.set_aptitude((int64_t)aptitude);
	msg.set_taskid((const char*)taskID.Get());
	msg.set_equip((const char*)equip.Get());
	msg.set_modelid((const char*)modelID.Get());
	for(int32_t i = 0; i < (int32_t)attribute.GetSize() && i < attribute.GetMaxSize(); ++i) {
		::proto_ff::occupationoccupationattributeDesc* temp_attribute = msg.add_attribute();
		attribute[i].write_to_pbmsg(*temp_attribute);
	}
	for(int32_t i = 0; i < (int32_t)delSkill.GetSize() && i < delSkill.GetMaxSize(); ++i) {
		::proto_ff::occupationoccupationdelSkillDesc* temp_delskill = msg.add_delskill();
		delSkill[i].write_to_pbmsg(*temp_delskill);
	}
	for(int32_t i = 0; i < (int32_t)skill.GetSize() && i < skill.GetMaxSize(); ++i) {
		::proto_ff::occupationoccupationskillDesc* temp_skill = msg.add_skill();
		skill[i].write_to_pbmsg(*temp_skill);
	}
}

void occupationoccupation_s::read_from_pbmsg(const ::proto_ff::occupationoccupation & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct occupationoccupation_s));
	occupationID = msg.occupationid();
	id = msg.id();
	grade = msg.grade();
	activeDesc.Copy(msg.activedesc());
	level = msg.level();
	aptitude = msg.aptitude();
	taskID.Copy(msg.taskid());
	equip.Copy(msg.equip());
	modelID.Copy(msg.modelid());
	attribute.SetSize(msg.attribute_size() > attribute.GetMaxSize() ? attribute.GetMaxSize() : msg.attribute_size());
	for(int32_t i = 0; i < (int32_t)attribute.GetSize(); ++i) {
		const ::proto_ff::occupationoccupationattributeDesc & temp_attribute = msg.attribute(i);
		attribute[i].read_from_pbmsg(temp_attribute);
	}
	delSkill.SetSize(msg.delskill_size() > delSkill.GetMaxSize() ? delSkill.GetMaxSize() : msg.delskill_size());
	for(int32_t i = 0; i < (int32_t)delSkill.GetSize(); ++i) {
		const ::proto_ff::occupationoccupationdelSkillDesc & temp_delskill = msg.delskill(i);
		delSkill[i].read_from_pbmsg(temp_delskill);
	}
	skill.SetSize(msg.skill_size() > skill.GetMaxSize() ? skill.GetMaxSize() : msg.skill_size());
	for(int32_t i = 0; i < (int32_t)skill.GetSize(); ++i) {
		const ::proto_ff::occupationoccupationskillDesc & temp_skill = msg.skill(i);
		skill[i].read_from_pbmsg(temp_skill);
	}
}

Sheet_occupationoccupation_s::Sheet_occupationoccupation_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_occupationoccupation_s::CreateInit() {
	return 0;
}

int Sheet_occupationoccupation_s::ResumeInit() {
	return 0;
}

void Sheet_occupationoccupation_s::write_to_pbmsg(::proto_ff::Sheet_occupationoccupation & msg) const {
	for(int32_t i = 0; i < (int32_t)occupationoccupation_List.GetSize() && i < occupationoccupation_List.GetMaxSize(); ++i) {
		::proto_ff::occupationoccupation* temp_occupationoccupation_list = msg.add_occupationoccupation_list();
		occupationoccupation_List[i].write_to_pbmsg(*temp_occupationoccupation_list);
	}
}

void Sheet_occupationoccupation_s::read_from_pbmsg(const ::proto_ff::Sheet_occupationoccupation & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_occupationoccupation_s));
	occupationoccupation_List.SetSize(msg.occupationoccupation_list_size() > occupationoccupation_List.GetMaxSize() ? occupationoccupation_List.GetMaxSize() : msg.occupationoccupation_list_size());
	for(int32_t i = 0; i < (int32_t)occupationoccupation_List.GetSize(); ++i) {
		const ::proto_ff::occupationoccupation & temp_occupationoccupation_list = msg.occupationoccupation_list(i);
		occupationoccupation_List[i].read_from_pbmsg(temp_occupationoccupation_list);
	}
}

occupationaptitudeattributeDesc_s::occupationaptitudeattributeDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int occupationaptitudeattributeDesc_s::CreateInit() {
	type = (int32_t)0;
	return 0;
}

int occupationaptitudeattributeDesc_s::ResumeInit() {
	return 0;
}

void occupationaptitudeattributeDesc_s::write_to_pbmsg(::proto_ff::occupationaptitudeattributeDesc & msg) const {
	msg.set_type((int32_t)type);
}

void occupationaptitudeattributeDesc_s::read_from_pbmsg(const ::proto_ff::occupationaptitudeattributeDesc & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct occupationaptitudeattributeDesc_s));
	type = msg.type();
}

occupationaptitude_s::occupationaptitude_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int occupationaptitude_s::CreateInit() {
	id = (int64_t)0;
	grade = (int32_t)0;
	level = (int32_t)0;
	requirement = (int64_t)0;
	material = (int64_t)0;
	num = (int32_t)0;
	return 0;
}

int occupationaptitude_s::ResumeInit() {
	return 0;
}

void occupationaptitude_s::write_to_pbmsg(::proto_ff::occupationaptitude & msg) const {
	msg.set_id((int64_t)id);
	msg.set_grade((int32_t)grade);
	msg.set_level((int32_t)level);
	msg.set_requirement((int64_t)requirement);
	msg.set_material((int64_t)material);
	msg.set_num((int32_t)num);
	msg.set_conditionid((const char*)conditionId.Get());
	for(int32_t i = 0; i < (int32_t)attribute.GetSize() && i < attribute.GetMaxSize(); ++i) {
		::proto_ff::occupationaptitudeattributeDesc* temp_attribute = msg.add_attribute();
		attribute[i].write_to_pbmsg(*temp_attribute);
	}
}

void occupationaptitude_s::read_from_pbmsg(const ::proto_ff::occupationaptitude & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct occupationaptitude_s));
	id = msg.id();
	grade = msg.grade();
	level = msg.level();
	requirement = msg.requirement();
	material = msg.material();
	num = msg.num();
	conditionId.Copy(msg.conditionid());
	attribute.SetSize(msg.attribute_size() > attribute.GetMaxSize() ? attribute.GetMaxSize() : msg.attribute_size());
	for(int32_t i = 0; i < (int32_t)attribute.GetSize(); ++i) {
		const ::proto_ff::occupationaptitudeattributeDesc & temp_attribute = msg.attribute(i);
		attribute[i].read_from_pbmsg(temp_attribute);
	}
}

Sheet_occupationaptitude_s::Sheet_occupationaptitude_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_occupationaptitude_s::CreateInit() {
	return 0;
}

int Sheet_occupationaptitude_s::ResumeInit() {
	return 0;
}

void Sheet_occupationaptitude_s::write_to_pbmsg(::proto_ff::Sheet_occupationaptitude & msg) const {
	for(int32_t i = 0; i < (int32_t)occupationaptitude_List.GetSize() && i < occupationaptitude_List.GetMaxSize(); ++i) {
		::proto_ff::occupationaptitude* temp_occupationaptitude_list = msg.add_occupationaptitude_list();
		occupationaptitude_List[i].write_to_pbmsg(*temp_occupationaptitude_list);
	}
}

void Sheet_occupationaptitude_s::read_from_pbmsg(const ::proto_ff::Sheet_occupationaptitude & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_occupationaptitude_s));
	occupationaptitude_List.SetSize(msg.occupationaptitude_list_size() > occupationaptitude_List.GetMaxSize() ? occupationaptitude_List.GetMaxSize() : msg.occupationaptitude_list_size());
	for(int32_t i = 0; i < (int32_t)occupationaptitude_List.GetSize(); ++i) {
		const ::proto_ff::occupationaptitude & temp_occupationaptitude_list = msg.occupationaptitude_list(i);
		occupationaptitude_List[i].read_from_pbmsg(temp_occupationaptitude_list);
	}
}

occupationconditionList_s::occupationconditionList_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int occupationconditionList_s::CreateInit() {
	ID = (int32_t)0;
	type = (int32_t)0;
	conditionValue = (int64_t)0;
	conditionNum = (int32_t)0;
	return 0;
}

int occupationconditionList_s::ResumeInit() {
	return 0;
}

void occupationconditionList_s::write_to_pbmsg(::proto_ff::occupationconditionList & msg) const {
	msg.set_id((int32_t)ID);
	msg.set_type((int32_t)type);
	msg.set_conditionvalue((int64_t)conditionValue);
	msg.set_conditionnum((int32_t)conditionNum);
}

void occupationconditionList_s::read_from_pbmsg(const ::proto_ff::occupationconditionList & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct occupationconditionList_s));
	ID = msg.id();
	type = msg.type();
	conditionValue = msg.conditionvalue();
	conditionNum = msg.conditionnum();
}

Sheet_occupationconditionList_s::Sheet_occupationconditionList_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_occupationconditionList_s::CreateInit() {
	return 0;
}

int Sheet_occupationconditionList_s::ResumeInit() {
	return 0;
}

void Sheet_occupationconditionList_s::write_to_pbmsg(::proto_ff::Sheet_occupationconditionList & msg) const {
	for(int32_t i = 0; i < (int32_t)occupationconditionList_List.GetSize() && i < occupationconditionList_List.GetMaxSize(); ++i) {
		::proto_ff::occupationconditionList* temp_occupationconditionlist_list = msg.add_occupationconditionlist_list();
		occupationconditionList_List[i].write_to_pbmsg(*temp_occupationconditionlist_list);
	}
}

void Sheet_occupationconditionList_s::read_from_pbmsg(const ::proto_ff::Sheet_occupationconditionList & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_occupationconditionList_s));
	occupationconditionList_List.SetSize(msg.occupationconditionlist_list_size() > occupationconditionList_List.GetMaxSize() ? occupationconditionList_List.GetMaxSize() : msg.occupationconditionlist_list_size());
	for(int32_t i = 0; i < (int32_t)occupationconditionList_List.GetSize(); ++i) {
		const ::proto_ff::occupationconditionList & temp_occupationconditionlist_list = msg.occupationconditionlist_list(i);
		occupationconditionList_List[i].read_from_pbmsg(temp_occupationconditionlist_list);
	}
}

}