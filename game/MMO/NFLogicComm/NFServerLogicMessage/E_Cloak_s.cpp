#include "E_Cloak_s.h"

namespace proto_ff_s {

E_CloakActivate_s::E_CloakActivate_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_CloakActivate_s::CreateInit() {
	m_cloakId = (int32_t)0;
	m_show = (int32_t)0;
	m_quality = (int32_t)0;
	m_facade = (int32_t)0;
	m_activateItem = (int32_t)0;
	m_activateNum = (int32_t)0;
	return 0;
}

int E_CloakActivate_s::ResumeInit() {
	return 0;
}

void E_CloakActivate_s::write_to_pbmsg(::proto_ff::E_CloakActivate & msg) const {
	msg.set_m_cloakid((int32_t)m_cloakId);
	msg.set_m_show((int32_t)m_show);
	msg.set_m_quality((int32_t)m_quality);
	msg.set_m_facade((int32_t)m_facade);
	msg.set_m_activateitem((int32_t)m_activateItem);
	msg.set_m_activatenum((int32_t)m_activateNum);
}

void E_CloakActivate_s::read_from_pbmsg(const ::proto_ff::E_CloakActivate & msg) {
	m_cloakId = msg.m_cloakid();
	m_show = msg.m_show();
	m_quality = msg.m_quality();
	m_facade = msg.m_facade();
	m_activateItem = msg.m_activateitem();
	m_activateNum = msg.m_activatenum();
}

Sheet_CloakActivate_s::Sheet_CloakActivate_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_CloakActivate_s::CreateInit() {
	return 0;
}

int Sheet_CloakActivate_s::ResumeInit() {
	return 0;
}

void Sheet_CloakActivate_s::write_to_pbmsg(::proto_ff::Sheet_CloakActivate & msg) const {
	for(int32_t i = 0; i < (int32_t)E_CloakActivate_List.size(); ++i) {
		::proto_ff::E_CloakActivate* temp_e_cloakactivate_list = msg.add_e_cloakactivate_list();
		E_CloakActivate_List[i].write_to_pbmsg(*temp_e_cloakactivate_list);
	}
}

void Sheet_CloakActivate_s::read_from_pbmsg(const ::proto_ff::Sheet_CloakActivate & msg) {
	E_CloakActivate_List.resize((int)msg.e_cloakactivate_list_size() > (int)E_CloakActivate_List.max_size() ? E_CloakActivate_List.max_size() : msg.e_cloakactivate_list_size());
	for(int32_t i = 0; i < (int32_t)E_CloakActivate_List.size(); ++i) {
		const ::proto_ff::E_CloakActivate & temp_e_cloakactivate_list = msg.e_cloakactivate_list(i);
		E_CloakActivate_List[i].read_from_pbmsg(temp_e_cloakactivate_list);
	}
}

E_CloakValueCloakattributeDesc_s::E_CloakValueCloakattributeDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_CloakValueCloakattributeDesc_s::CreateInit() {
	m_value = (int32_t)0;
	m_type = (int32_t)0;
	return 0;
}

int E_CloakValueCloakattributeDesc_s::ResumeInit() {
	return 0;
}

void E_CloakValueCloakattributeDesc_s::write_to_pbmsg(::proto_ff::E_CloakValueCloakattributeDesc & msg) const {
	msg.set_m_value((int32_t)m_value);
	msg.set_m_type((int32_t)m_type);
}

void E_CloakValueCloakattributeDesc_s::read_from_pbmsg(const ::proto_ff::E_CloakValueCloakattributeDesc & msg) {
	m_value = msg.m_value();
	m_type = msg.m_type();
}

E_CloakValue_s::E_CloakValue_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_CloakValue_s::CreateInit() {
	m_lv = (int32_t)0;
	m_cloakExp = (int64_t)0;
	return 0;
}

int E_CloakValue_s::ResumeInit() {
	return 0;
}

void E_CloakValue_s::write_to_pbmsg(::proto_ff::E_CloakValue & msg) const {
	msg.set_m_lv((int32_t)m_lv);
	msg.set_m_cloakexp((int64_t)m_cloakExp);
	for(int32_t i = 0; i < (int32_t)m_cloakAttribute.size(); ++i) {
		::proto_ff::E_CloakValueCloakattributeDesc* temp_m_cloakattribute = msg.add_m_cloakattribute();
		m_cloakAttribute[i].write_to_pbmsg(*temp_m_cloakattribute);
	}
}

void E_CloakValue_s::read_from_pbmsg(const ::proto_ff::E_CloakValue & msg) {
	m_lv = msg.m_lv();
	m_cloakExp = msg.m_cloakexp();
	m_cloakAttribute.resize((int)msg.m_cloakattribute_size() > (int)m_cloakAttribute.max_size() ? m_cloakAttribute.max_size() : msg.m_cloakattribute_size());
	for(int32_t i = 0; i < (int32_t)m_cloakAttribute.size(); ++i) {
		const ::proto_ff::E_CloakValueCloakattributeDesc & temp_m_cloakattribute = msg.m_cloakattribute(i);
		m_cloakAttribute[i].read_from_pbmsg(temp_m_cloakattribute);
	}
}

Sheet_CloakValue_s::Sheet_CloakValue_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_CloakValue_s::CreateInit() {
	return 0;
}

int Sheet_CloakValue_s::ResumeInit() {
	return 0;
}

void Sheet_CloakValue_s::write_to_pbmsg(::proto_ff::Sheet_CloakValue & msg) const {
	for(int32_t i = 0; i < (int32_t)E_CloakValue_List.size(); ++i) {
		::proto_ff::E_CloakValue* temp_e_cloakvalue_list = msg.add_e_cloakvalue_list();
		E_CloakValue_List[i].write_to_pbmsg(*temp_e_cloakvalue_list);
	}
}

void Sheet_CloakValue_s::read_from_pbmsg(const ::proto_ff::Sheet_CloakValue & msg) {
	E_CloakValue_List.resize((int)msg.e_cloakvalue_list_size() > (int)E_CloakValue_List.max_size() ? E_CloakValue_List.max_size() : msg.e_cloakvalue_list_size());
	for(int32_t i = 0; i < (int32_t)E_CloakValue_List.size(); ++i) {
		const ::proto_ff::E_CloakValue & temp_e_cloakvalue_list = msg.e_cloakvalue_list(i);
		E_CloakValue_List[i].read_from_pbmsg(temp_e_cloakvalue_list);
	}
}

E_CloakIntensifyitem_s::E_CloakIntensifyitem_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_CloakIntensifyitem_s::CreateInit() {
	m_id = (int32_t)0;
	m_addExp = (int32_t)0;
	return 0;
}

int E_CloakIntensifyitem_s::ResumeInit() {
	return 0;
}

void E_CloakIntensifyitem_s::write_to_pbmsg(::proto_ff::E_CloakIntensifyitem & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_addexp((int32_t)m_addExp);
}

void E_CloakIntensifyitem_s::read_from_pbmsg(const ::proto_ff::E_CloakIntensifyitem & msg) {
	m_id = msg.m_id();
	m_addExp = msg.m_addexp();
}

Sheet_CloakIntensifyitem_s::Sheet_CloakIntensifyitem_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_CloakIntensifyitem_s::CreateInit() {
	return 0;
}

int Sheet_CloakIntensifyitem_s::ResumeInit() {
	return 0;
}

void Sheet_CloakIntensifyitem_s::write_to_pbmsg(::proto_ff::Sheet_CloakIntensifyitem & msg) const {
	for(int32_t i = 0; i < (int32_t)E_CloakIntensifyitem_List.size(); ++i) {
		::proto_ff::E_CloakIntensifyitem* temp_e_cloakintensifyitem_list = msg.add_e_cloakintensifyitem_list();
		E_CloakIntensifyitem_List[i].write_to_pbmsg(*temp_e_cloakintensifyitem_list);
	}
}

void Sheet_CloakIntensifyitem_s::read_from_pbmsg(const ::proto_ff::Sheet_CloakIntensifyitem & msg) {
	E_CloakIntensifyitem_List.resize((int)msg.e_cloakintensifyitem_list_size() > (int)E_CloakIntensifyitem_List.max_size() ? E_CloakIntensifyitem_List.max_size() : msg.e_cloakintensifyitem_list_size());
	for(int32_t i = 0; i < (int32_t)E_CloakIntensifyitem_List.size(); ++i) {
		const ::proto_ff::E_CloakIntensifyitem & temp_e_cloakintensifyitem_list = msg.e_cloakintensifyitem_list(i);
		E_CloakIntensifyitem_List[i].read_from_pbmsg(temp_e_cloakintensifyitem_list);
	}
}

E_CloakRefineItemDesc_s::E_CloakRefineItemDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_CloakRefineItemDesc_s::CreateInit() {
	m_num = (int32_t)0;
	m_id = (int32_t)0;
	return 0;
}

int E_CloakRefineItemDesc_s::ResumeInit() {
	return 0;
}

void E_CloakRefineItemDesc_s::write_to_pbmsg(::proto_ff::E_CloakRefineItemDesc & msg) const {
	msg.set_m_num((int32_t)m_num);
	msg.set_m_id((int32_t)m_id);
}

void E_CloakRefineItemDesc_s::read_from_pbmsg(const ::proto_ff::E_CloakRefineItemDesc & msg) {
	m_num = msg.m_num();
	m_id = msg.m_id();
}

E_CloakRefineAttDesc_s::E_CloakRefineAttDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_CloakRefineAttDesc_s::CreateInit() {
	m_vlue = (int32_t)0;
	m_id = (int32_t)0;
	return 0;
}

int E_CloakRefineAttDesc_s::ResumeInit() {
	return 0;
}

void E_CloakRefineAttDesc_s::write_to_pbmsg(::proto_ff::E_CloakRefineAttDesc & msg) const {
	msg.set_m_vlue((int32_t)m_vlue);
	msg.set_m_id((int32_t)m_id);
}

void E_CloakRefineAttDesc_s::read_from_pbmsg(const ::proto_ff::E_CloakRefineAttDesc & msg) {
	m_vlue = msg.m_vlue();
	m_id = msg.m_id();
}

E_CloakRefine_s::E_CloakRefine_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_CloakRefine_s::CreateInit() {
	m_id = (int32_t)0;
	m_cloakId = (int32_t)0;
	m_refineLv = (int32_t)0;
	m_success = (int32_t)0;
	m_guarant = (int32_t)0;
	return 0;
}

int E_CloakRefine_s::ResumeInit() {
	return 0;
}

void E_CloakRefine_s::write_to_pbmsg(::proto_ff::E_CloakRefine & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_cloakid((int32_t)m_cloakId);
	msg.set_m_refinelv((int32_t)m_refineLv);
	msg.set_m_success((int32_t)m_success);
	msg.set_m_guarant((int32_t)m_guarant);
	for(int32_t i = 0; i < (int32_t)m_item.size(); ++i) {
		::proto_ff::E_CloakRefineItemDesc* temp_m_item = msg.add_m_item();
		m_item[i].write_to_pbmsg(*temp_m_item);
	}
	for(int32_t i = 0; i < (int32_t)m_att.size(); ++i) {
		::proto_ff::E_CloakRefineAttDesc* temp_m_att = msg.add_m_att();
		m_att[i].write_to_pbmsg(*temp_m_att);
	}
}

void E_CloakRefine_s::read_from_pbmsg(const ::proto_ff::E_CloakRefine & msg) {
	m_id = msg.m_id();
	m_cloakId = msg.m_cloakid();
	m_refineLv = msg.m_refinelv();
	m_success = msg.m_success();
	m_guarant = msg.m_guarant();
	m_item.resize((int)msg.m_item_size() > (int)m_item.max_size() ? m_item.max_size() : msg.m_item_size());
	for(int32_t i = 0; i < (int32_t)m_item.size(); ++i) {
		const ::proto_ff::E_CloakRefineItemDesc & temp_m_item = msg.m_item(i);
		m_item[i].read_from_pbmsg(temp_m_item);
	}
	m_att.resize((int)msg.m_att_size() > (int)m_att.max_size() ? m_att.max_size() : msg.m_att_size());
	for(int32_t i = 0; i < (int32_t)m_att.size(); ++i) {
		const ::proto_ff::E_CloakRefineAttDesc & temp_m_att = msg.m_att(i);
		m_att[i].read_from_pbmsg(temp_m_att);
	}
}

Sheet_CloakRefine_s::Sheet_CloakRefine_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_CloakRefine_s::CreateInit() {
	return 0;
}

int Sheet_CloakRefine_s::ResumeInit() {
	return 0;
}

void Sheet_CloakRefine_s::write_to_pbmsg(::proto_ff::Sheet_CloakRefine & msg) const {
	for(int32_t i = 0; i < (int32_t)E_CloakRefine_List.size(); ++i) {
		::proto_ff::E_CloakRefine* temp_e_cloakrefine_list = msg.add_e_cloakrefine_list();
		E_CloakRefine_List[i].write_to_pbmsg(*temp_e_cloakrefine_list);
	}
}

void Sheet_CloakRefine_s::read_from_pbmsg(const ::proto_ff::Sheet_CloakRefine & msg) {
	E_CloakRefine_List.resize((int)msg.e_cloakrefine_list_size() > (int)E_CloakRefine_List.max_size() ? E_CloakRefine_List.max_size() : msg.e_cloakrefine_list_size());
	for(int32_t i = 0; i < (int32_t)E_CloakRefine_List.size(); ++i) {
		const ::proto_ff::E_CloakRefine & temp_e_cloakrefine_list = msg.e_cloakrefine_list(i);
		E_CloakRefine_List[i].read_from_pbmsg(temp_e_cloakrefine_list);
	}
}

E_CloakRefineunlock_s::E_CloakRefineunlock_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_CloakRefineunlock_s::CreateInit() {
	m_id = (int32_t)0;
	m_cloakId = (int32_t)0;
	m_refineLv = (int32_t)0;
	m_unlockAtt = (int32_t)0;
	m_unlockVlue = (int32_t)0;
	m_skill = (int32_t)0;
	return 0;
}

int E_CloakRefineunlock_s::ResumeInit() {
	return 0;
}

void E_CloakRefineunlock_s::write_to_pbmsg(::proto_ff::E_CloakRefineunlock & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_cloakid((int32_t)m_cloakId);
	msg.set_m_refinelv((int32_t)m_refineLv);
	msg.set_m_unlockatt((int32_t)m_unlockAtt);
	msg.set_m_unlockvlue((int32_t)m_unlockVlue);
	msg.set_m_skill((int32_t)m_skill);
}

void E_CloakRefineunlock_s::read_from_pbmsg(const ::proto_ff::E_CloakRefineunlock & msg) {
	m_id = msg.m_id();
	m_cloakId = msg.m_cloakid();
	m_refineLv = msg.m_refinelv();
	m_unlockAtt = msg.m_unlockatt();
	m_unlockVlue = msg.m_unlockvlue();
	m_skill = msg.m_skill();
}

Sheet_CloakRefineunlock_s::Sheet_CloakRefineunlock_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_CloakRefineunlock_s::CreateInit() {
	return 0;
}

int Sheet_CloakRefineunlock_s::ResumeInit() {
	return 0;
}

void Sheet_CloakRefineunlock_s::write_to_pbmsg(::proto_ff::Sheet_CloakRefineunlock & msg) const {
	for(int32_t i = 0; i < (int32_t)E_CloakRefineunlock_List.size(); ++i) {
		::proto_ff::E_CloakRefineunlock* temp_e_cloakrefineunlock_list = msg.add_e_cloakrefineunlock_list();
		E_CloakRefineunlock_List[i].write_to_pbmsg(*temp_e_cloakrefineunlock_list);
	}
}

void Sheet_CloakRefineunlock_s::read_from_pbmsg(const ::proto_ff::Sheet_CloakRefineunlock & msg) {
	E_CloakRefineunlock_List.resize((int)msg.e_cloakrefineunlock_list_size() > (int)E_CloakRefineunlock_List.max_size() ? E_CloakRefineunlock_List.max_size() : msg.e_cloakrefineunlock_list_size());
	for(int32_t i = 0; i < (int32_t)E_CloakRefineunlock_List.size(); ++i) {
		const ::proto_ff::E_CloakRefineunlock & temp_e_cloakrefineunlock_list = msg.e_cloakrefineunlock_list(i);
		E_CloakRefineunlock_List[i].read_from_pbmsg(temp_e_cloakrefineunlock_list);
	}
}

E_CloakGradeItemDesc_s::E_CloakGradeItemDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_CloakGradeItemDesc_s::CreateInit() {
	m_num = (int32_t)0;
	m_id = (int32_t)0;
	return 0;
}

int E_CloakGradeItemDesc_s::ResumeInit() {
	return 0;
}

void E_CloakGradeItemDesc_s::write_to_pbmsg(::proto_ff::E_CloakGradeItemDesc & msg) const {
	msg.set_m_num((int32_t)m_num);
	msg.set_m_id((int32_t)m_id);
}

void E_CloakGradeItemDesc_s::read_from_pbmsg(const ::proto_ff::E_CloakGradeItemDesc & msg) {
	m_num = msg.m_num();
	m_id = msg.m_id();
}

E_CloakGradeAttributeDesc_s::E_CloakGradeAttributeDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_CloakGradeAttributeDesc_s::CreateInit() {
	m_vlue = (int32_t)0;
	m_id = (int32_t)0;
	return 0;
}

int E_CloakGradeAttributeDesc_s::ResumeInit() {
	return 0;
}

void E_CloakGradeAttributeDesc_s::write_to_pbmsg(::proto_ff::E_CloakGradeAttributeDesc & msg) const {
	msg.set_m_vlue((int32_t)m_vlue);
	msg.set_m_id((int32_t)m_id);
}

void E_CloakGradeAttributeDesc_s::read_from_pbmsg(const ::proto_ff::E_CloakGradeAttributeDesc & msg) {
	m_vlue = msg.m_vlue();
	m_id = msg.m_id();
}

E_CloakGrade_s::E_CloakGrade_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_CloakGrade_s::CreateInit() {
	m_id = (int32_t)0;
	m_cloakId = (int32_t)0;
	m_quality = (int32_t)0;
	return 0;
}

int E_CloakGrade_s::ResumeInit() {
	return 0;
}

void E_CloakGrade_s::write_to_pbmsg(::proto_ff::E_CloakGrade & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_cloakid((int32_t)m_cloakId);
	msg.set_m_quality((int32_t)m_quality);
	for(int32_t i = 0; i < (int32_t)m_item.size(); ++i) {
		::proto_ff::E_CloakGradeItemDesc* temp_m_item = msg.add_m_item();
		m_item[i].write_to_pbmsg(*temp_m_item);
	}
	for(int32_t i = 0; i < (int32_t)m_attribute.size(); ++i) {
		::proto_ff::E_CloakGradeAttributeDesc* temp_m_attribute = msg.add_m_attribute();
		m_attribute[i].write_to_pbmsg(*temp_m_attribute);
	}
}

void E_CloakGrade_s::read_from_pbmsg(const ::proto_ff::E_CloakGrade & msg) {
	m_id = msg.m_id();
	m_cloakId = msg.m_cloakid();
	m_quality = msg.m_quality();
	m_item.resize((int)msg.m_item_size() > (int)m_item.max_size() ? m_item.max_size() : msg.m_item_size());
	for(int32_t i = 0; i < (int32_t)m_item.size(); ++i) {
		const ::proto_ff::E_CloakGradeItemDesc & temp_m_item = msg.m_item(i);
		m_item[i].read_from_pbmsg(temp_m_item);
	}
	m_attribute.resize((int)msg.m_attribute_size() > (int)m_attribute.max_size() ? m_attribute.max_size() : msg.m_attribute_size());
	for(int32_t i = 0; i < (int32_t)m_attribute.size(); ++i) {
		const ::proto_ff::E_CloakGradeAttributeDesc & temp_m_attribute = msg.m_attribute(i);
		m_attribute[i].read_from_pbmsg(temp_m_attribute);
	}
}

Sheet_CloakGrade_s::Sheet_CloakGrade_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_CloakGrade_s::CreateInit() {
	return 0;
}

int Sheet_CloakGrade_s::ResumeInit() {
	return 0;
}

void Sheet_CloakGrade_s::write_to_pbmsg(::proto_ff::Sheet_CloakGrade & msg) const {
	for(int32_t i = 0; i < (int32_t)E_CloakGrade_List.size(); ++i) {
		::proto_ff::E_CloakGrade* temp_e_cloakgrade_list = msg.add_e_cloakgrade_list();
		E_CloakGrade_List[i].write_to_pbmsg(*temp_e_cloakgrade_list);
	}
}

void Sheet_CloakGrade_s::read_from_pbmsg(const ::proto_ff::Sheet_CloakGrade & msg) {
	E_CloakGrade_List.resize((int)msg.e_cloakgrade_list_size() > (int)E_CloakGrade_List.max_size() ? E_CloakGrade_List.max_size() : msg.e_cloakgrade_list_size());
	for(int32_t i = 0; i < (int32_t)E_CloakGrade_List.size(); ++i) {
		const ::proto_ff::E_CloakGrade & temp_e_cloakgrade_list = msg.e_cloakgrade_list(i);
		E_CloakGrade_List[i].read_from_pbmsg(temp_e_cloakgrade_list);
	}
}

E_CloakGodItemDesc_s::E_CloakGodItemDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_CloakGodItemDesc_s::CreateInit() {
	m_num = (int32_t)0;
	m_id = (int32_t)0;
	return 0;
}

int E_CloakGodItemDesc_s::ResumeInit() {
	return 0;
}

void E_CloakGodItemDesc_s::write_to_pbmsg(::proto_ff::E_CloakGodItemDesc & msg) const {
	msg.set_m_num((int32_t)m_num);
	msg.set_m_id((int32_t)m_id);
}

void E_CloakGodItemDesc_s::read_from_pbmsg(const ::proto_ff::E_CloakGodItemDesc & msg) {
	m_num = msg.m_num();
	m_id = msg.m_id();
}

E_CloakGodAttributeDesc_s::E_CloakGodAttributeDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_CloakGodAttributeDesc_s::CreateInit() {
	m_vlue = (int32_t)0;
	m_id = (int32_t)0;
	return 0;
}

int E_CloakGodAttributeDesc_s::ResumeInit() {
	return 0;
}

void E_CloakGodAttributeDesc_s::write_to_pbmsg(::proto_ff::E_CloakGodAttributeDesc & msg) const {
	msg.set_m_vlue((int32_t)m_vlue);
	msg.set_m_id((int32_t)m_id);
}

void E_CloakGodAttributeDesc_s::read_from_pbmsg(const ::proto_ff::E_CloakGodAttributeDesc & msg) {
	m_vlue = msg.m_vlue();
	m_id = msg.m_id();
}

E_CloakGod_s::E_CloakGod_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_CloakGod_s::CreateInit() {
	m_cloakId = (int32_t)0;
	m_skill = (int32_t)0;
	return 0;
}

int E_CloakGod_s::ResumeInit() {
	return 0;
}

void E_CloakGod_s::write_to_pbmsg(::proto_ff::E_CloakGod & msg) const {
	msg.set_m_cloakid((int32_t)m_cloakId);
	msg.set_m_skill((int32_t)m_skill);
	for(int32_t i = 0; i < (int32_t)m_item.size(); ++i) {
		::proto_ff::E_CloakGodItemDesc* temp_m_item = msg.add_m_item();
		m_item[i].write_to_pbmsg(*temp_m_item);
	}
	for(int32_t i = 0; i < (int32_t)m_attribute.size(); ++i) {
		::proto_ff::E_CloakGodAttributeDesc* temp_m_attribute = msg.add_m_attribute();
		m_attribute[i].write_to_pbmsg(*temp_m_attribute);
	}
}

void E_CloakGod_s::read_from_pbmsg(const ::proto_ff::E_CloakGod & msg) {
	m_cloakId = msg.m_cloakid();
	m_skill = msg.m_skill();
	m_item.resize((int)msg.m_item_size() > (int)m_item.max_size() ? m_item.max_size() : msg.m_item_size());
	for(int32_t i = 0; i < (int32_t)m_item.size(); ++i) {
		const ::proto_ff::E_CloakGodItemDesc & temp_m_item = msg.m_item(i);
		m_item[i].read_from_pbmsg(temp_m_item);
	}
	m_attribute.resize((int)msg.m_attribute_size() > (int)m_attribute.max_size() ? m_attribute.max_size() : msg.m_attribute_size());
	for(int32_t i = 0; i < (int32_t)m_attribute.size(); ++i) {
		const ::proto_ff::E_CloakGodAttributeDesc & temp_m_attribute = msg.m_attribute(i);
		m_attribute[i].read_from_pbmsg(temp_m_attribute);
	}
}

Sheet_CloakGod_s::Sheet_CloakGod_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_CloakGod_s::CreateInit() {
	return 0;
}

int Sheet_CloakGod_s::ResumeInit() {
	return 0;
}

void Sheet_CloakGod_s::write_to_pbmsg(::proto_ff::Sheet_CloakGod & msg) const {
	for(int32_t i = 0; i < (int32_t)E_CloakGod_List.size(); ++i) {
		::proto_ff::E_CloakGod* temp_e_cloakgod_list = msg.add_e_cloakgod_list();
		E_CloakGod_List[i].write_to_pbmsg(*temp_e_cloakgod_list);
	}
}

void Sheet_CloakGod_s::read_from_pbmsg(const ::proto_ff::Sheet_CloakGod & msg) {
	E_CloakGod_List.resize((int)msg.e_cloakgod_list_size() > (int)E_CloakGod_List.max_size() ? E_CloakGod_List.max_size() : msg.e_cloakgod_list_size());
	for(int32_t i = 0; i < (int32_t)E_CloakGod_List.size(); ++i) {
		const ::proto_ff::E_CloakGod & temp_e_cloakgod_list = msg.e_cloakgod_list(i);
		E_CloakGod_List[i].read_from_pbmsg(temp_e_cloakgod_list);
	}
}

E_CloakSoulAttributeDesc_s::E_CloakSoulAttributeDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_CloakSoulAttributeDesc_s::CreateInit() {
	m_value = (int32_t)0;
	m_type = (int32_t)0;
	return 0;
}

int E_CloakSoulAttributeDesc_s::ResumeInit() {
	return 0;
}

void E_CloakSoulAttributeDesc_s::write_to_pbmsg(::proto_ff::E_CloakSoulAttributeDesc & msg) const {
	msg.set_m_value((int32_t)m_value);
	msg.set_m_type((int32_t)m_type);
}

void E_CloakSoulAttributeDesc_s::read_from_pbmsg(const ::proto_ff::E_CloakSoulAttributeDesc & msg) {
	m_value = msg.m_value();
	m_type = msg.m_type();
}

E_CloakSoul_s::E_CloakSoul_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_CloakSoul_s::CreateInit() {
	m_id = (int64_t)0;
	m_rechargeID = (int32_t)0;
	m_mainSkill = (int32_t)0;
	m_itemId = (int32_t)0;
	m_itemNum = (int32_t)0;
	return 0;
}

int E_CloakSoul_s::ResumeInit() {
	return 0;
}

void E_CloakSoul_s::write_to_pbmsg(::proto_ff::E_CloakSoul & msg) const {
	msg.set_m_id((int64_t)m_id);
	msg.set_m_rechargeid((int32_t)m_rechargeID);
	msg.set_m_mainskill((int32_t)m_mainSkill);
	msg.set_m_attributetype(m_attributeType.data());
	msg.set_m_itemid((int32_t)m_itemId);
	msg.set_m_itemnum((int32_t)m_itemNum);
	for(int32_t i = 0; i < (int32_t)m_minorSkill.size(); ++i) {
		msg.add_m_minorskill((int32_t)m_minorSkill[i]);
	}
	for(int32_t i = 0; i < (int32_t)m_attribute.size(); ++i) {
		::proto_ff::E_CloakSoulAttributeDesc* temp_m_attribute = msg.add_m_attribute();
		m_attribute[i].write_to_pbmsg(*temp_m_attribute);
	}
}

void E_CloakSoul_s::read_from_pbmsg(const ::proto_ff::E_CloakSoul & msg) {
	m_id = msg.m_id();
	m_rechargeID = msg.m_rechargeid();
	m_mainSkill = msg.m_mainskill();
	m_attributeType = msg.m_attributetype();
	m_itemId = msg.m_itemid();
	m_itemNum = msg.m_itemnum();
	m_minorSkill.resize((int)msg.m_minorskill_size() > (int)m_minorSkill.max_size() ? m_minorSkill.max_size() : msg.m_minorskill_size());
	for(int32_t i = 0; i < (int32_t)m_minorSkill.size(); ++i) {
		m_minorSkill[i] = msg.m_minorskill(i);
	}
	m_attribute.resize((int)msg.m_attribute_size() > (int)m_attribute.max_size() ? m_attribute.max_size() : msg.m_attribute_size());
	for(int32_t i = 0; i < (int32_t)m_attribute.size(); ++i) {
		const ::proto_ff::E_CloakSoulAttributeDesc & temp_m_attribute = msg.m_attribute(i);
		m_attribute[i].read_from_pbmsg(temp_m_attribute);
	}
}

Sheet_CloakSoul_s::Sheet_CloakSoul_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_CloakSoul_s::CreateInit() {
	return 0;
}

int Sheet_CloakSoul_s::ResumeInit() {
	return 0;
}

void Sheet_CloakSoul_s::write_to_pbmsg(::proto_ff::Sheet_CloakSoul & msg) const {
	for(int32_t i = 0; i < (int32_t)E_CloakSoul_List.size(); ++i) {
		::proto_ff::E_CloakSoul* temp_e_cloaksoul_list = msg.add_e_cloaksoul_list();
		E_CloakSoul_List[i].write_to_pbmsg(*temp_e_cloaksoul_list);
	}
}

void Sheet_CloakSoul_s::read_from_pbmsg(const ::proto_ff::Sheet_CloakSoul & msg) {
	E_CloakSoul_List.resize((int)msg.e_cloaksoul_list_size() > (int)E_CloakSoul_List.max_size() ? E_CloakSoul_List.max_size() : msg.e_cloaksoul_list_size());
	for(int32_t i = 0; i < (int32_t)E_CloakSoul_List.size(); ++i) {
		const ::proto_ff::E_CloakSoul & temp_e_cloaksoul_list = msg.e_cloaksoul_list(i);
		E_CloakSoul_List[i].read_from_pbmsg(temp_e_cloaksoul_list);
	}
}

E_CloakSoulactiveUnlockDesc_s::E_CloakSoulactiveUnlockDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_CloakSoulactiveUnlockDesc_s::CreateInit() {
	m_condition = (int32_t)0;
	return 0;
}

int E_CloakSoulactiveUnlockDesc_s::ResumeInit() {
	return 0;
}

void E_CloakSoulactiveUnlockDesc_s::write_to_pbmsg(::proto_ff::E_CloakSoulactiveUnlockDesc & msg) const {
	msg.set_m_parama(m_parama.data());
	msg.set_m_condition((int32_t)m_condition);
}

void E_CloakSoulactiveUnlockDesc_s::read_from_pbmsg(const ::proto_ff::E_CloakSoulactiveUnlockDesc & msg) {
	m_parama = msg.m_parama();
	m_condition = msg.m_condition();
}

E_CloakSoulactive_s::E_CloakSoulactive_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_CloakSoulactive_s::CreateInit() {
	m_id = (int64_t)0;
	return 0;
}

int E_CloakSoulactive_s::ResumeInit() {
	return 0;
}

void E_CloakSoulactive_s::write_to_pbmsg(::proto_ff::E_CloakSoulactive & msg) const {
	msg.set_m_id((int64_t)m_id);
	for(int32_t i = 0; i < (int32_t)m_unlock.size(); ++i) {
		::proto_ff::E_CloakSoulactiveUnlockDesc* temp_m_unlock = msg.add_m_unlock();
		m_unlock[i].write_to_pbmsg(*temp_m_unlock);
	}
}

void E_CloakSoulactive_s::read_from_pbmsg(const ::proto_ff::E_CloakSoulactive & msg) {
	m_id = msg.m_id();
	m_unlock.resize((int)msg.m_unlock_size() > (int)m_unlock.max_size() ? m_unlock.max_size() : msg.m_unlock_size());
	for(int32_t i = 0; i < (int32_t)m_unlock.size(); ++i) {
		const ::proto_ff::E_CloakSoulactiveUnlockDesc & temp_m_unlock = msg.m_unlock(i);
		m_unlock[i].read_from_pbmsg(temp_m_unlock);
	}
}

Sheet_CloakSoulactive_s::Sheet_CloakSoulactive_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_CloakSoulactive_s::CreateInit() {
	return 0;
}

int Sheet_CloakSoulactive_s::ResumeInit() {
	return 0;
}

void Sheet_CloakSoulactive_s::write_to_pbmsg(::proto_ff::Sheet_CloakSoulactive & msg) const {
	for(int32_t i = 0; i < (int32_t)E_CloakSoulactive_List.size(); ++i) {
		::proto_ff::E_CloakSoulactive* temp_e_cloaksoulactive_list = msg.add_e_cloaksoulactive_list();
		E_CloakSoulactive_List[i].write_to_pbmsg(*temp_e_cloaksoulactive_list);
	}
}

void Sheet_CloakSoulactive_s::read_from_pbmsg(const ::proto_ff::Sheet_CloakSoulactive & msg) {
	E_CloakSoulactive_List.resize((int)msg.e_cloaksoulactive_list_size() > (int)E_CloakSoulactive_List.max_size() ? E_CloakSoulactive_List.max_size() : msg.e_cloaksoulactive_list_size());
	for(int32_t i = 0; i < (int32_t)E_CloakSoulactive_List.size(); ++i) {
		const ::proto_ff::E_CloakSoulactive & temp_e_cloaksoulactive_list = msg.e_cloaksoulactive_list(i);
		E_CloakSoulactive_List[i].read_from_pbmsg(temp_e_cloaksoulactive_list);
	}
}

E_CloakSoullvAttributeDesc_s::E_CloakSoullvAttributeDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_CloakSoullvAttributeDesc_s::CreateInit() {
	m_value = (int32_t)0;
	m_type = (int32_t)0;
	return 0;
}

int E_CloakSoullvAttributeDesc_s::ResumeInit() {
	return 0;
}

void E_CloakSoullvAttributeDesc_s::write_to_pbmsg(::proto_ff::E_CloakSoullvAttributeDesc & msg) const {
	msg.set_m_value((int32_t)m_value);
	msg.set_m_type((int32_t)m_type);
}

void E_CloakSoullvAttributeDesc_s::read_from_pbmsg(const ::proto_ff::E_CloakSoullvAttributeDesc & msg) {
	m_value = msg.m_value();
	m_type = msg.m_type();
}

E_CloakSoullv_s::E_CloakSoullv_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_CloakSoullv_s::CreateInit() {
	m_soullLv = (int32_t)0;
	m_itemID = (int32_t)0;
	m_num = (int32_t)0;
	m_successRate = (int32_t)0;
	m_downLv = (int32_t)0;
	return 0;
}

int E_CloakSoullv_s::ResumeInit() {
	return 0;
}

void E_CloakSoullv_s::write_to_pbmsg(::proto_ff::E_CloakSoullv & msg) const {
	msg.set_m_soulllv((int32_t)m_soullLv);
	msg.set_m_itemid((int32_t)m_itemID);
	msg.set_m_num((int32_t)m_num);
	msg.set_m_successrate((int32_t)m_successRate);
	msg.set_m_downlv((int32_t)m_downLv);
	for(int32_t i = 0; i < (int32_t)m_attribute.size(); ++i) {
		::proto_ff::E_CloakSoullvAttributeDesc* temp_m_attribute = msg.add_m_attribute();
		m_attribute[i].write_to_pbmsg(*temp_m_attribute);
	}
}

void E_CloakSoullv_s::read_from_pbmsg(const ::proto_ff::E_CloakSoullv & msg) {
	m_soullLv = msg.m_soulllv();
	m_itemID = msg.m_itemid();
	m_num = msg.m_num();
	m_successRate = msg.m_successrate();
	m_downLv = msg.m_downlv();
	m_attribute.resize((int)msg.m_attribute_size() > (int)m_attribute.max_size() ? m_attribute.max_size() : msg.m_attribute_size());
	for(int32_t i = 0; i < (int32_t)m_attribute.size(); ++i) {
		const ::proto_ff::E_CloakSoullvAttributeDesc & temp_m_attribute = msg.m_attribute(i);
		m_attribute[i].read_from_pbmsg(temp_m_attribute);
	}
}

Sheet_CloakSoullv_s::Sheet_CloakSoullv_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_CloakSoullv_s::CreateInit() {
	return 0;
}

int Sheet_CloakSoullv_s::ResumeInit() {
	return 0;
}

void Sheet_CloakSoullv_s::write_to_pbmsg(::proto_ff::Sheet_CloakSoullv & msg) const {
	for(int32_t i = 0; i < (int32_t)E_CloakSoullv_List.size(); ++i) {
		::proto_ff::E_CloakSoullv* temp_e_cloaksoullv_list = msg.add_e_cloaksoullv_list();
		E_CloakSoullv_List[i].write_to_pbmsg(*temp_e_cloaksoullv_list);
	}
}

void Sheet_CloakSoullv_s::read_from_pbmsg(const ::proto_ff::Sheet_CloakSoullv & msg) {
	E_CloakSoullv_List.resize((int)msg.e_cloaksoullv_list_size() > (int)E_CloakSoullv_List.max_size() ? E_CloakSoullv_List.max_size() : msg.e_cloaksoullv_list_size());
	for(int32_t i = 0; i < (int32_t)E_CloakSoullv_List.size(); ++i) {
		const ::proto_ff::E_CloakSoullv & temp_e_cloaksoullv_list = msg.e_cloaksoullv_list(i);
		E_CloakSoullv_List[i].read_from_pbmsg(temp_e_cloaksoullv_list);
	}
}

E_CloakSoulclear_s::E_CloakSoulclear_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_CloakSoulclear_s::CreateInit() {
	m_soullLv = (int32_t)0;
	return 0;
}

int E_CloakSoulclear_s::ResumeInit() {
	return 0;
}

void E_CloakSoulclear_s::write_to_pbmsg(::proto_ff::E_CloakSoulclear & msg) const {
	msg.set_m_soulllv((int32_t)m_soullLv);
	for(int32_t i = 0; i < (int32_t)m_clearAtt.size(); ++i) {
		msg.add_m_clearatt((int32_t)m_clearAtt[i]);
	}
}

void E_CloakSoulclear_s::read_from_pbmsg(const ::proto_ff::E_CloakSoulclear & msg) {
	m_soullLv = msg.m_soulllv();
	m_clearAtt.resize((int)msg.m_clearatt_size() > (int)m_clearAtt.max_size() ? m_clearAtt.max_size() : msg.m_clearatt_size());
	for(int32_t i = 0; i < (int32_t)m_clearAtt.size(); ++i) {
		m_clearAtt[i] = msg.m_clearatt(i);
	}
}

Sheet_CloakSoulclear_s::Sheet_CloakSoulclear_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_CloakSoulclear_s::CreateInit() {
	return 0;
}

int Sheet_CloakSoulclear_s::ResumeInit() {
	return 0;
}

void Sheet_CloakSoulclear_s::write_to_pbmsg(::proto_ff::Sheet_CloakSoulclear & msg) const {
	for(int32_t i = 0; i < (int32_t)E_CloakSoulclear_List.size(); ++i) {
		::proto_ff::E_CloakSoulclear* temp_e_cloaksoulclear_list = msg.add_e_cloaksoulclear_list();
		E_CloakSoulclear_List[i].write_to_pbmsg(*temp_e_cloaksoulclear_list);
	}
}

void Sheet_CloakSoulclear_s::read_from_pbmsg(const ::proto_ff::Sheet_CloakSoulclear & msg) {
	E_CloakSoulclear_List.resize((int)msg.e_cloaksoulclear_list_size() > (int)E_CloakSoulclear_List.max_size() ? E_CloakSoulclear_List.max_size() : msg.e_cloaksoulclear_list_size());
	for(int32_t i = 0; i < (int32_t)E_CloakSoulclear_List.size(); ++i) {
		const ::proto_ff::E_CloakSoulclear & temp_e_cloaksoulclear_list = msg.e_cloaksoulclear_list(i);
		E_CloakSoulclear_List[i].read_from_pbmsg(temp_e_cloaksoulclear_list);
	}
}

E_CloakSoulachievement_s::E_CloakSoulachievement_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_CloakSoulachievement_s::CreateInit() {
	m_id = (int64_t)0;
	m_type = (int32_t)0;
	m_parama = (int32_t)0;
	m_itemID = (int32_t)0;
	m_num = (int32_t)0;
	return 0;
}

int E_CloakSoulachievement_s::ResumeInit() {
	return 0;
}

void E_CloakSoulachievement_s::write_to_pbmsg(::proto_ff::E_CloakSoulachievement & msg) const {
	msg.set_m_id((int64_t)m_id);
	msg.set_m_type((int32_t)m_type);
	msg.set_m_parama((int32_t)m_parama);
	msg.set_m_itemid((int32_t)m_itemID);
	msg.set_m_num((int32_t)m_num);
}

void E_CloakSoulachievement_s::read_from_pbmsg(const ::proto_ff::E_CloakSoulachievement & msg) {
	m_id = msg.m_id();
	m_type = msg.m_type();
	m_parama = msg.m_parama();
	m_itemID = msg.m_itemid();
	m_num = msg.m_num();
}

Sheet_CloakSoulachievement_s::Sheet_CloakSoulachievement_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_CloakSoulachievement_s::CreateInit() {
	return 0;
}

int Sheet_CloakSoulachievement_s::ResumeInit() {
	return 0;
}

void Sheet_CloakSoulachievement_s::write_to_pbmsg(::proto_ff::Sheet_CloakSoulachievement & msg) const {
	for(int32_t i = 0; i < (int32_t)E_CloakSoulachievement_List.size(); ++i) {
		::proto_ff::E_CloakSoulachievement* temp_e_cloaksoulachievement_list = msg.add_e_cloaksoulachievement_list();
		E_CloakSoulachievement_List[i].write_to_pbmsg(*temp_e_cloaksoulachievement_list);
	}
}

void Sheet_CloakSoulachievement_s::read_from_pbmsg(const ::proto_ff::Sheet_CloakSoulachievement & msg) {
	E_CloakSoulachievement_List.resize((int)msg.e_cloaksoulachievement_list_size() > (int)E_CloakSoulachievement_List.max_size() ? E_CloakSoulachievement_List.max_size() : msg.e_cloaksoulachievement_list_size());
	for(int32_t i = 0; i < (int32_t)E_CloakSoulachievement_List.size(); ++i) {
		const ::proto_ff::E_CloakSoulachievement & temp_e_cloaksoulachievement_list = msg.e_cloaksoulachievement_list(i);
		E_CloakSoulachievement_List[i].read_from_pbmsg(temp_e_cloaksoulachievement_list);
	}
}

}
