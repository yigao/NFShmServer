#include "facade_s.h"

namespace proto_ff_s {

E_FacadeDisplayMaterialDesc_s::E_FacadeDisplayMaterialDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_FacadeDisplayMaterialDesc_s::CreateInit() {
	m_id = (int64_t)0;
	m_exp = (int32_t)0;
	return 0;
}

int E_FacadeDisplayMaterialDesc_s::ResumeInit() {
	return 0;
}

void E_FacadeDisplayMaterialDesc_s::write_to_pbmsg(::proto_ff::E_FacadeDisplayMaterialDesc & msg) const {
	msg.set_m_id((int64_t)m_id);
	msg.set_m_exp((int32_t)m_exp);
}

void E_FacadeDisplayMaterialDesc_s::read_from_pbmsg(const ::proto_ff::E_FacadeDisplayMaterialDesc & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct E_FacadeDisplayMaterialDesc_s));
	m_id = msg.m_id();
	m_exp = msg.m_exp();
}

E_FacadeDisplay_s::E_FacadeDisplay_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_FacadeDisplay_s::CreateInit() {
	m_id = (int64_t)0;
	m_type = (int32_t)0;
	m_souliid = (int32_t)0;
	return 0;
}

int E_FacadeDisplay_s::ResumeInit() {
	return 0;
}

void E_FacadeDisplay_s::write_to_pbmsg(::proto_ff::E_FacadeDisplay & msg) const {
	msg.set_m_id((int64_t)m_id);
	msg.set_m_type((int32_t)m_type);
	msg.set_m_resource((const char*)m_resource.data());
	msg.set_m_name((const char*)m_name.data());
	msg.set_m_activedesc((const char*)m_activedesc.data());
	msg.set_m_professionid((const char*)m_professionid.data());
	msg.set_m_skillid((const char*)m_skillid.data());
	msg.set_m_souliid((int32_t)m_souliid);
	for(int32_t i = 0; i < (int32_t)m_material.size(); ++i) {
		::proto_ff::E_FacadeDisplayMaterialDesc* temp_m_material = msg.add_m_material();
		m_material[i].write_to_pbmsg(*temp_m_material);
	}
	for(int32_t i = 0; i < (int32_t)m_fragmentid.size(); ++i) {
		msg.add_m_fragmentid((int64_t)m_fragmentid[i]);
	}
}

void E_FacadeDisplay_s::read_from_pbmsg(const ::proto_ff::E_FacadeDisplay & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct E_FacadeDisplay_s));
	m_id = msg.m_id();
	m_type = msg.m_type();
	m_resource = msg.m_resource();
	m_name = msg.m_name();
	m_activedesc = msg.m_activedesc();
	m_professionid = msg.m_professionid();
	m_skillid = msg.m_skillid();
	m_souliid = msg.m_souliid();
	m_material.resize((int)msg.m_material_size() > (int)m_material.max_size() ? m_material.max_size() : msg.m_material_size());
	for(int32_t i = 0; i < (int32_t)m_material.size(); ++i) {
		const ::proto_ff::E_FacadeDisplayMaterialDesc & temp_m_material = msg.m_material(i);
		m_material[i].read_from_pbmsg(temp_m_material);
	}
	m_fragmentid.resize((int)msg.m_fragmentid_size() > (int)m_fragmentid.max_size() ? m_fragmentid.max_size() : msg.m_fragmentid_size());
	for(int32_t i = 0; i < (int32_t)m_fragmentid.size(); ++i) {
		m_fragmentid[i] = msg.m_fragmentid(i);
	}
}

Sheet_FacadeDisplay_s::Sheet_FacadeDisplay_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_FacadeDisplay_s::CreateInit() {
	return 0;
}

int Sheet_FacadeDisplay_s::ResumeInit() {
	return 0;
}

void Sheet_FacadeDisplay_s::write_to_pbmsg(::proto_ff::Sheet_FacadeDisplay & msg) const {
	for(int32_t i = 0; i < (int32_t)E_FacadeDisplay_List.size(); ++i) {
		::proto_ff::E_FacadeDisplay* temp_e_facadedisplay_list = msg.add_e_facadedisplay_list();
		E_FacadeDisplay_List[i].write_to_pbmsg(*temp_e_facadedisplay_list);
	}
}

void Sheet_FacadeDisplay_s::read_from_pbmsg(const ::proto_ff::Sheet_FacadeDisplay & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_FacadeDisplay_s));
	E_FacadeDisplay_List.resize((int)msg.e_facadedisplay_list_size() > (int)E_FacadeDisplay_List.max_size() ? E_FacadeDisplay_List.max_size() : msg.e_facadedisplay_list_size());
	for(int32_t i = 0; i < (int32_t)E_FacadeDisplay_List.size(); ++i) {
		const ::proto_ff::E_FacadeDisplay & temp_e_facadedisplay_list = msg.e_facadedisplay_list(i);
		E_FacadeDisplay_List[i].read_from_pbmsg(temp_e_facadedisplay_list);
	}
}

E_FacadeValueTreasureattributeDesc_s::E_FacadeValueTreasureattributeDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_FacadeValueTreasureattributeDesc_s::CreateInit() {
	m_type = (int32_t)0;
	m_value = (int32_t)0;
	return 0;
}

int E_FacadeValueTreasureattributeDesc_s::ResumeInit() {
	return 0;
}

void E_FacadeValueTreasureattributeDesc_s::write_to_pbmsg(::proto_ff::E_FacadeValueTreasureattributeDesc & msg) const {
	msg.set_m_type((int32_t)m_type);
	msg.set_m_value((int32_t)m_value);
}

void E_FacadeValueTreasureattributeDesc_s::read_from_pbmsg(const ::proto_ff::E_FacadeValueTreasureattributeDesc & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct E_FacadeValueTreasureattributeDesc_s));
	m_type = msg.m_type();
	m_value = msg.m_value();
}

E_FacadeValueArtifactattributeDesc_s::E_FacadeValueArtifactattributeDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_FacadeValueArtifactattributeDesc_s::CreateInit() {
	m_type = (int32_t)0;
	m_value = (int32_t)0;
	return 0;
}

int E_FacadeValueArtifactattributeDesc_s::ResumeInit() {
	return 0;
}

void E_FacadeValueArtifactattributeDesc_s::write_to_pbmsg(::proto_ff::E_FacadeValueArtifactattributeDesc & msg) const {
	msg.set_m_type((int32_t)m_type);
	msg.set_m_value((int32_t)m_value);
}

void E_FacadeValueArtifactattributeDesc_s::read_from_pbmsg(const ::proto_ff::E_FacadeValueArtifactattributeDesc & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct E_FacadeValueArtifactattributeDesc_s));
	m_type = msg.m_type();
	m_value = msg.m_value();
}

E_FacadeValueBladeattributeDesc_s::E_FacadeValueBladeattributeDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_FacadeValueBladeattributeDesc_s::CreateInit() {
	m_type = (int32_t)0;
	m_value = (int32_t)0;
	return 0;
}

int E_FacadeValueBladeattributeDesc_s::ResumeInit() {
	return 0;
}

void E_FacadeValueBladeattributeDesc_s::write_to_pbmsg(::proto_ff::E_FacadeValueBladeattributeDesc & msg) const {
	msg.set_m_type((int32_t)m_type);
	msg.set_m_value((int32_t)m_value);
}

void E_FacadeValueBladeattributeDesc_s::read_from_pbmsg(const ::proto_ff::E_FacadeValueBladeattributeDesc & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct E_FacadeValueBladeattributeDesc_s));
	m_type = msg.m_type();
	m_value = msg.m_value();
}

E_FacadeValueWingattributeDesc_s::E_FacadeValueWingattributeDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_FacadeValueWingattributeDesc_s::CreateInit() {
	m_type = (int32_t)0;
	m_value = (int32_t)0;
	return 0;
}

int E_FacadeValueWingattributeDesc_s::ResumeInit() {
	return 0;
}

void E_FacadeValueWingattributeDesc_s::write_to_pbmsg(::proto_ff::E_FacadeValueWingattributeDesc & msg) const {
	msg.set_m_type((int32_t)m_type);
	msg.set_m_value((int32_t)m_value);
}

void E_FacadeValueWingattributeDesc_s::read_from_pbmsg(const ::proto_ff::E_FacadeValueWingattributeDesc & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct E_FacadeValueWingattributeDesc_s));
	m_type = msg.m_type();
	m_value = msg.m_value();
}

E_FacadeValue_s::E_FacadeValue_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_FacadeValue_s::CreateInit() {
	m_lv = (int32_t)0;
	m_wingexp = (int64_t)0;
	m_treasureexp = (int64_t)0;
	m_artifactexp = (int64_t)0;
	m_bladeexp = (int64_t)0;
	return 0;
}

int E_FacadeValue_s::ResumeInit() {
	return 0;
}

void E_FacadeValue_s::write_to_pbmsg(::proto_ff::E_FacadeValue & msg) const {
	msg.set_m_lv((int32_t)m_lv);
	msg.set_m_wingexp((int64_t)m_wingexp);
	msg.set_m_treasureexp((int64_t)m_treasureexp);
	msg.set_m_artifactexp((int64_t)m_artifactexp);
	msg.set_m_bladeexp((int64_t)m_bladeexp);
	for(int32_t i = 0; i < (int32_t)m_treasureattribute.size(); ++i) {
		::proto_ff::E_FacadeValueTreasureattributeDesc* temp_m_treasureattribute = msg.add_m_treasureattribute();
		m_treasureattribute[i].write_to_pbmsg(*temp_m_treasureattribute);
	}
	for(int32_t i = 0; i < (int32_t)m_artifactattribute.size(); ++i) {
		::proto_ff::E_FacadeValueArtifactattributeDesc* temp_m_artifactattribute = msg.add_m_artifactattribute();
		m_artifactattribute[i].write_to_pbmsg(*temp_m_artifactattribute);
	}
	for(int32_t i = 0; i < (int32_t)m_bladeattribute.size(); ++i) {
		::proto_ff::E_FacadeValueBladeattributeDesc* temp_m_bladeattribute = msg.add_m_bladeattribute();
		m_bladeattribute[i].write_to_pbmsg(*temp_m_bladeattribute);
	}
	for(int32_t i = 0; i < (int32_t)m_wingattribute.size(); ++i) {
		::proto_ff::E_FacadeValueWingattributeDesc* temp_m_wingattribute = msg.add_m_wingattribute();
		m_wingattribute[i].write_to_pbmsg(*temp_m_wingattribute);
	}
}

void E_FacadeValue_s::read_from_pbmsg(const ::proto_ff::E_FacadeValue & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct E_FacadeValue_s));
	m_lv = msg.m_lv();
	m_wingexp = msg.m_wingexp();
	m_treasureexp = msg.m_treasureexp();
	m_artifactexp = msg.m_artifactexp();
	m_bladeexp = msg.m_bladeexp();
	m_treasureattribute.resize((int)msg.m_treasureattribute_size() > (int)m_treasureattribute.max_size() ? m_treasureattribute.max_size() : msg.m_treasureattribute_size());
	for(int32_t i = 0; i < (int32_t)m_treasureattribute.size(); ++i) {
		const ::proto_ff::E_FacadeValueTreasureattributeDesc & temp_m_treasureattribute = msg.m_treasureattribute(i);
		m_treasureattribute[i].read_from_pbmsg(temp_m_treasureattribute);
	}
	m_artifactattribute.resize((int)msg.m_artifactattribute_size() > (int)m_artifactattribute.max_size() ? m_artifactattribute.max_size() : msg.m_artifactattribute_size());
	for(int32_t i = 0; i < (int32_t)m_artifactattribute.size(); ++i) {
		const ::proto_ff::E_FacadeValueArtifactattributeDesc & temp_m_artifactattribute = msg.m_artifactattribute(i);
		m_artifactattribute[i].read_from_pbmsg(temp_m_artifactattribute);
	}
	m_bladeattribute.resize((int)msg.m_bladeattribute_size() > (int)m_bladeattribute.max_size() ? m_bladeattribute.max_size() : msg.m_bladeattribute_size());
	for(int32_t i = 0; i < (int32_t)m_bladeattribute.size(); ++i) {
		const ::proto_ff::E_FacadeValueBladeattributeDesc & temp_m_bladeattribute = msg.m_bladeattribute(i);
		m_bladeattribute[i].read_from_pbmsg(temp_m_bladeattribute);
	}
	m_wingattribute.resize((int)msg.m_wingattribute_size() > (int)m_wingattribute.max_size() ? m_wingattribute.max_size() : msg.m_wingattribute_size());
	for(int32_t i = 0; i < (int32_t)m_wingattribute.size(); ++i) {
		const ::proto_ff::E_FacadeValueWingattributeDesc & temp_m_wingattribute = msg.m_wingattribute(i);
		m_wingattribute[i].read_from_pbmsg(temp_m_wingattribute);
	}
}

Sheet_FacadeValue_s::Sheet_FacadeValue_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_FacadeValue_s::CreateInit() {
	return 0;
}

int Sheet_FacadeValue_s::ResumeInit() {
	return 0;
}

void Sheet_FacadeValue_s::write_to_pbmsg(::proto_ff::Sheet_FacadeValue & msg) const {
	for(int32_t i = 0; i < (int32_t)E_FacadeValue_List.size(); ++i) {
		::proto_ff::E_FacadeValue* temp_e_facadevalue_list = msg.add_e_facadevalue_list();
		E_FacadeValue_List[i].write_to_pbmsg(*temp_e_facadevalue_list);
	}
}

void Sheet_FacadeValue_s::read_from_pbmsg(const ::proto_ff::Sheet_FacadeValue & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_FacadeValue_s));
	E_FacadeValue_List.resize((int)msg.e_facadevalue_list_size() > (int)E_FacadeValue_List.max_size() ? E_FacadeValue_List.max_size() : msg.e_facadevalue_list_size());
	for(int32_t i = 0; i < (int32_t)E_FacadeValue_List.size(); ++i) {
		const ::proto_ff::E_FacadeValue & temp_e_facadevalue_list = msg.e_facadevalue_list(i);
		E_FacadeValue_List[i].read_from_pbmsg(temp_e_facadevalue_list);
	}
}

E_FacadeType_s::E_FacadeType_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_FacadeType_s::CreateInit() {
	m_id = (int32_t)0;
	return 0;
}

int E_FacadeType_s::ResumeInit() {
	return 0;
}

void E_FacadeType_s::write_to_pbmsg(::proto_ff::E_FacadeType & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_soucename((const char*)m_soucename.data());
}

void E_FacadeType_s::read_from_pbmsg(const ::proto_ff::E_FacadeType & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct E_FacadeType_s));
	m_id = msg.m_id();
	m_soucename = msg.m_soucename();
}

Sheet_FacadeType_s::Sheet_FacadeType_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_FacadeType_s::CreateInit() {
	return 0;
}

int Sheet_FacadeType_s::ResumeInit() {
	return 0;
}

void Sheet_FacadeType_s::write_to_pbmsg(::proto_ff::Sheet_FacadeType & msg) const {
	for(int32_t i = 0; i < (int32_t)E_FacadeType_List.size(); ++i) {
		::proto_ff::E_FacadeType* temp_e_facadetype_list = msg.add_e_facadetype_list();
		E_FacadeType_List[i].write_to_pbmsg(*temp_e_facadetype_list);
	}
}

void Sheet_FacadeType_s::read_from_pbmsg(const ::proto_ff::Sheet_FacadeType & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_FacadeType_s));
	E_FacadeType_List.resize((int)msg.e_facadetype_list_size() > (int)E_FacadeType_List.max_size() ? E_FacadeType_List.max_size() : msg.e_facadetype_list_size());
	for(int32_t i = 0; i < (int32_t)E_FacadeType_List.size(); ++i) {
		const ::proto_ff::E_FacadeType & temp_e_facadetype_list = msg.e_facadetype_list(i);
		E_FacadeType_List[i].read_from_pbmsg(temp_e_facadetype_list);
	}
}

E_FacadeFragmentAttributeDesc_s::E_FacadeFragmentAttributeDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_FacadeFragmentAttributeDesc_s::CreateInit() {
	m_type = (int32_t)0;
	m_value = (int32_t)0;
	return 0;
}

int E_FacadeFragmentAttributeDesc_s::ResumeInit() {
	return 0;
}

void E_FacadeFragmentAttributeDesc_s::write_to_pbmsg(::proto_ff::E_FacadeFragmentAttributeDesc & msg) const {
	msg.set_m_type((int32_t)m_type);
	msg.set_m_value((int32_t)m_value);
}

void E_FacadeFragmentAttributeDesc_s::read_from_pbmsg(const ::proto_ff::E_FacadeFragmentAttributeDesc & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct E_FacadeFragmentAttributeDesc_s));
	m_type = msg.m_type();
	m_value = msg.m_value();
}

E_FacadeFragment_s::E_FacadeFragment_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_FacadeFragment_s::CreateInit() {
	m_fragmentid = (int64_t)0;
	m_item = (int64_t)0;
	m_itemnum = (int32_t)0;
	return 0;
}

int E_FacadeFragment_s::ResumeInit() {
	return 0;
}

void E_FacadeFragment_s::write_to_pbmsg(::proto_ff::E_FacadeFragment & msg) const {
	msg.set_m_fragmentid((int64_t)m_fragmentid);
	msg.set_m_item((int64_t)m_item);
	msg.set_m_itemnum((int32_t)m_itemnum);
	for(int32_t i = 0; i < (int32_t)m_attribute.size(); ++i) {
		::proto_ff::E_FacadeFragmentAttributeDesc* temp_m_attribute = msg.add_m_attribute();
		m_attribute[i].write_to_pbmsg(*temp_m_attribute);
	}
}

void E_FacadeFragment_s::read_from_pbmsg(const ::proto_ff::E_FacadeFragment & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct E_FacadeFragment_s));
	m_fragmentid = msg.m_fragmentid();
	m_item = msg.m_item();
	m_itemnum = msg.m_itemnum();
	m_attribute.resize((int)msg.m_attribute_size() > (int)m_attribute.max_size() ? m_attribute.max_size() : msg.m_attribute_size());
	for(int32_t i = 0; i < (int32_t)m_attribute.size(); ++i) {
		const ::proto_ff::E_FacadeFragmentAttributeDesc & temp_m_attribute = msg.m_attribute(i);
		m_attribute[i].read_from_pbmsg(temp_m_attribute);
	}
}

Sheet_FacadeFragment_s::Sheet_FacadeFragment_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_FacadeFragment_s::CreateInit() {
	return 0;
}

int Sheet_FacadeFragment_s::ResumeInit() {
	return 0;
}

void Sheet_FacadeFragment_s::write_to_pbmsg(::proto_ff::Sheet_FacadeFragment & msg) const {
	for(int32_t i = 0; i < (int32_t)E_FacadeFragment_List.size(); ++i) {
		::proto_ff::E_FacadeFragment* temp_e_facadefragment_list = msg.add_e_facadefragment_list();
		E_FacadeFragment_List[i].write_to_pbmsg(*temp_e_facadefragment_list);
	}
}

void Sheet_FacadeFragment_s::read_from_pbmsg(const ::proto_ff::Sheet_FacadeFragment & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_FacadeFragment_s));
	E_FacadeFragment_List.resize((int)msg.e_facadefragment_list_size() > (int)E_FacadeFragment_List.max_size() ? E_FacadeFragment_List.max_size() : msg.e_facadefragment_list_size());
	for(int32_t i = 0; i < (int32_t)E_FacadeFragment_List.size(); ++i) {
		const ::proto_ff::E_FacadeFragment & temp_e_facadefragment_list = msg.e_facadefragment_list(i);
		E_FacadeFragment_List[i].read_from_pbmsg(temp_e_facadefragment_list);
	}
}

E_FacadeChangeAttributeDesc_s::E_FacadeChangeAttributeDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_FacadeChangeAttributeDesc_s::CreateInit() {
	m_type = (int32_t)0;
	m_value = (int32_t)0;
	return 0;
}

int E_FacadeChangeAttributeDesc_s::ResumeInit() {
	return 0;
}

void E_FacadeChangeAttributeDesc_s::write_to_pbmsg(::proto_ff::E_FacadeChangeAttributeDesc & msg) const {
	msg.set_m_type((int32_t)m_type);
	msg.set_m_value((int32_t)m_value);
}

void E_FacadeChangeAttributeDesc_s::read_from_pbmsg(const ::proto_ff::E_FacadeChangeAttributeDesc & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct E_FacadeChangeAttributeDesc_s));
	m_type = msg.m_type();
	m_value = msg.m_value();
}

E_FacadeChangeActiveattributeDesc_s::E_FacadeChangeActiveattributeDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_FacadeChangeActiveattributeDesc_s::CreateInit() {
	m_type = (int32_t)0;
	m_value = (int32_t)0;
	return 0;
}

int E_FacadeChangeActiveattributeDesc_s::ResumeInit() {
	return 0;
}

void E_FacadeChangeActiveattributeDesc_s::write_to_pbmsg(::proto_ff::E_FacadeChangeActiveattributeDesc & msg) const {
	msg.set_m_type((int32_t)m_type);
	msg.set_m_value((int32_t)m_value);
}

void E_FacadeChangeActiveattributeDesc_s::read_from_pbmsg(const ::proto_ff::E_FacadeChangeActiveattributeDesc & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct E_FacadeChangeActiveattributeDesc_s));
	m_type = msg.m_type();
	m_value = msg.m_value();
}

E_FacadeChange_s::E_FacadeChange_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_FacadeChange_s::CreateInit() {
	m_id = (int64_t)0;
	m_type = (int32_t)0;
	m_quality = (int32_t)0;
	m_activationitem = (int64_t)0;
	m_activationnum = (int32_t)0;
	m_starid = (int64_t)0;
	m_starup = (int32_t)0;
	m_starber = (int32_t)0;
	m_upattributeid = (int64_t)0;
	m_activeskill = (int32_t)0;
	return 0;
}

int E_FacadeChange_s::ResumeInit() {
	return 0;
}

void E_FacadeChange_s::write_to_pbmsg(::proto_ff::E_FacadeChange & msg) const {
	msg.set_m_id((int64_t)m_id);
	msg.set_m_type((int32_t)m_type);
	msg.set_m_resource((const char*)m_resource.data());
	msg.set_m_professionid((const char*)m_professionid.data());
	msg.set_m_name((const char*)m_name.data());
	msg.set_m_activedesc((const char*)m_activedesc.data());
	msg.set_m_quality((int32_t)m_quality);
	msg.set_m_activationitem((int64_t)m_activationitem);
	msg.set_m_activationnum((int32_t)m_activationnum);
	msg.set_m_starid((int64_t)m_starid);
	msg.set_m_starnum((const char*)m_starnum.data());
	msg.set_m_starup((int32_t)m_starup);
	msg.set_m_starber((int32_t)m_starber);
	msg.set_m_upattributeid((int64_t)m_upattributeid);
	msg.set_m_activeskill((int32_t)m_activeskill);
	for(int32_t i = 0; i < (int32_t)m_attribute.size(); ++i) {
		::proto_ff::E_FacadeChangeAttributeDesc* temp_m_attribute = msg.add_m_attribute();
		m_attribute[i].write_to_pbmsg(*temp_m_attribute);
	}
	for(int32_t i = 0; i < (int32_t)m_activeattribute.size(); ++i) {
		::proto_ff::E_FacadeChangeActiveattributeDesc* temp_m_activeattribute = msg.add_m_activeattribute();
		m_activeattribute[i].write_to_pbmsg(*temp_m_activeattribute);
	}
}

void E_FacadeChange_s::read_from_pbmsg(const ::proto_ff::E_FacadeChange & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct E_FacadeChange_s));
	m_id = msg.m_id();
	m_type = msg.m_type();
	m_resource = msg.m_resource();
	m_professionid = msg.m_professionid();
	m_name = msg.m_name();
	m_activedesc = msg.m_activedesc();
	m_quality = msg.m_quality();
	m_activationitem = msg.m_activationitem();
	m_activationnum = msg.m_activationnum();
	m_starid = msg.m_starid();
	m_starnum = msg.m_starnum();
	m_starup = msg.m_starup();
	m_starber = msg.m_starber();
	m_upattributeid = msg.m_upattributeid();
	m_activeskill = msg.m_activeskill();
	m_attribute.resize((int)msg.m_attribute_size() > (int)m_attribute.max_size() ? m_attribute.max_size() : msg.m_attribute_size());
	for(int32_t i = 0; i < (int32_t)m_attribute.size(); ++i) {
		const ::proto_ff::E_FacadeChangeAttributeDesc & temp_m_attribute = msg.m_attribute(i);
		m_attribute[i].read_from_pbmsg(temp_m_attribute);
	}
	m_activeattribute.resize((int)msg.m_activeattribute_size() > (int)m_activeattribute.max_size() ? m_activeattribute.max_size() : msg.m_activeattribute_size());
	for(int32_t i = 0; i < (int32_t)m_activeattribute.size(); ++i) {
		const ::proto_ff::E_FacadeChangeActiveattributeDesc & temp_m_activeattribute = msg.m_activeattribute(i);
		m_activeattribute[i].read_from_pbmsg(temp_m_activeattribute);
	}
}

Sheet_FacadeChange_s::Sheet_FacadeChange_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_FacadeChange_s::CreateInit() {
	return 0;
}

int Sheet_FacadeChange_s::ResumeInit() {
	return 0;
}

void Sheet_FacadeChange_s::write_to_pbmsg(::proto_ff::Sheet_FacadeChange & msg) const {
	for(int32_t i = 0; i < (int32_t)E_FacadeChange_List.size(); ++i) {
		::proto_ff::E_FacadeChange* temp_e_facadechange_list = msg.add_e_facadechange_list();
		E_FacadeChange_List[i].write_to_pbmsg(*temp_e_facadechange_list);
	}
}

void Sheet_FacadeChange_s::read_from_pbmsg(const ::proto_ff::Sheet_FacadeChange & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_FacadeChange_s));
	E_FacadeChange_List.resize((int)msg.e_facadechange_list_size() > (int)E_FacadeChange_List.max_size() ? E_FacadeChange_List.max_size() : msg.e_facadechange_list_size());
	for(int32_t i = 0; i < (int32_t)E_FacadeChange_List.size(); ++i) {
		const ::proto_ff::E_FacadeChange & temp_e_facadechange_list = msg.e_facadechange_list(i);
		E_FacadeChange_List[i].read_from_pbmsg(temp_e_facadechange_list);
	}
}

E_FacadeStarupUpattributeDesc_s::E_FacadeStarupUpattributeDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_FacadeStarupUpattributeDesc_s::CreateInit() {
	m_type = (int32_t)0;
	m_value = (int32_t)0;
	return 0;
}

int E_FacadeStarupUpattributeDesc_s::ResumeInit() {
	return 0;
}

void E_FacadeStarupUpattributeDesc_s::write_to_pbmsg(::proto_ff::E_FacadeStarupUpattributeDesc & msg) const {
	msg.set_m_type((int32_t)m_type);
	msg.set_m_value((int32_t)m_value);
}

void E_FacadeStarupUpattributeDesc_s::read_from_pbmsg(const ::proto_ff::E_FacadeStarupUpattributeDesc & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct E_FacadeStarupUpattributeDesc_s));
	m_type = msg.m_type();
	m_value = msg.m_value();
}

E_FacadeStarup_s::E_FacadeStarup_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_FacadeStarup_s::CreateInit() {
	m_id = (int32_t)0;
	m_upattributeid = (int64_t)0;
	m_starid = (int32_t)0;
	m_skillid = (int32_t)0;
	return 0;
}

int E_FacadeStarup_s::ResumeInit() {
	return 0;
}

void E_FacadeStarup_s::write_to_pbmsg(::proto_ff::E_FacadeStarup & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_upattributeid((int64_t)m_upattributeid);
	msg.set_m_starid((int32_t)m_starid);
	msg.set_m_skillid((int32_t)m_skillid);
	for(int32_t i = 0; i < (int32_t)m_upattribute.size(); ++i) {
		::proto_ff::E_FacadeStarupUpattributeDesc* temp_m_upattribute = msg.add_m_upattribute();
		m_upattribute[i].write_to_pbmsg(*temp_m_upattribute);
	}
}

void E_FacadeStarup_s::read_from_pbmsg(const ::proto_ff::E_FacadeStarup & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct E_FacadeStarup_s));
	m_id = msg.m_id();
	m_upattributeid = msg.m_upattributeid();
	m_starid = msg.m_starid();
	m_skillid = msg.m_skillid();
	m_upattribute.resize((int)msg.m_upattribute_size() > (int)m_upattribute.max_size() ? m_upattribute.max_size() : msg.m_upattribute_size());
	for(int32_t i = 0; i < (int32_t)m_upattribute.size(); ++i) {
		const ::proto_ff::E_FacadeStarupUpattributeDesc & temp_m_upattribute = msg.m_upattribute(i);
		m_upattribute[i].read_from_pbmsg(temp_m_upattribute);
	}
}

Sheet_FacadeStarup_s::Sheet_FacadeStarup_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_FacadeStarup_s::CreateInit() {
	return 0;
}

int Sheet_FacadeStarup_s::ResumeInit() {
	return 0;
}

void Sheet_FacadeStarup_s::write_to_pbmsg(::proto_ff::Sheet_FacadeStarup & msg) const {
	for(int32_t i = 0; i < (int32_t)E_FacadeStarup_List.size(); ++i) {
		::proto_ff::E_FacadeStarup* temp_e_facadestarup_list = msg.add_e_facadestarup_list();
		E_FacadeStarup_List[i].write_to_pbmsg(*temp_e_facadestarup_list);
	}
}

void Sheet_FacadeStarup_s::read_from_pbmsg(const ::proto_ff::Sheet_FacadeStarup & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_FacadeStarup_s));
	E_FacadeStarup_List.resize((int)msg.e_facadestarup_list_size() > (int)E_FacadeStarup_List.max_size() ? E_FacadeStarup_List.max_size() : msg.e_facadestarup_list_size());
	for(int32_t i = 0; i < (int32_t)E_FacadeStarup_List.size(); ++i) {
		const ::proto_ff::E_FacadeStarup & temp_e_facadestarup_list = msg.e_facadestarup_list(i);
		E_FacadeStarup_List[i].read_from_pbmsg(temp_e_facadestarup_list);
	}
}

E_FacadeSoulAttributeDesc_s::E_FacadeSoulAttributeDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_FacadeSoulAttributeDesc_s::CreateInit() {
	m_type = (int32_t)0;
	m_value = (int32_t)0;
	return 0;
}

int E_FacadeSoulAttributeDesc_s::ResumeInit() {
	return 0;
}

void E_FacadeSoulAttributeDesc_s::write_to_pbmsg(::proto_ff::E_FacadeSoulAttributeDesc & msg) const {
	msg.set_m_type((int32_t)m_type);
	msg.set_m_value((int32_t)m_value);
}

void E_FacadeSoulAttributeDesc_s::read_from_pbmsg(const ::proto_ff::E_FacadeSoulAttributeDesc & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct E_FacadeSoulAttributeDesc_s));
	m_type = msg.m_type();
	m_value = msg.m_value();
}

E_FacadeSoul_s::E_FacadeSoul_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_FacadeSoul_s::CreateInit() {
	m_id = (int64_t)0;
	m_rechargeid = (int32_t)0;
	m_mainskill = (int32_t)0;
	return 0;
}

int E_FacadeSoul_s::ResumeInit() {
	return 0;
}

void E_FacadeSoul_s::write_to_pbmsg(::proto_ff::E_FacadeSoul & msg) const {
	msg.set_m_id((int64_t)m_id);
	msg.set_m_rechargeid((int32_t)m_rechargeid);
	msg.set_m_mainskill((int32_t)m_mainskill);
	msg.set_m_attributetype((const char*)m_attributetype.data());
	for(int32_t i = 0; i < (int32_t)m_attribute.size(); ++i) {
		::proto_ff::E_FacadeSoulAttributeDesc* temp_m_attribute = msg.add_m_attribute();
		m_attribute[i].write_to_pbmsg(*temp_m_attribute);
	}
	for(int32_t i = 0; i < (int32_t)m_minorskill.size(); ++i) {
		msg.add_m_minorskill((int32_t)m_minorskill[i]);
	}
}

void E_FacadeSoul_s::read_from_pbmsg(const ::proto_ff::E_FacadeSoul & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct E_FacadeSoul_s));
	m_id = msg.m_id();
	m_rechargeid = msg.m_rechargeid();
	m_mainskill = msg.m_mainskill();
	m_attributetype = msg.m_attributetype();
	m_attribute.resize((int)msg.m_attribute_size() > (int)m_attribute.max_size() ? m_attribute.max_size() : msg.m_attribute_size());
	for(int32_t i = 0; i < (int32_t)m_attribute.size(); ++i) {
		const ::proto_ff::E_FacadeSoulAttributeDesc & temp_m_attribute = msg.m_attribute(i);
		m_attribute[i].read_from_pbmsg(temp_m_attribute);
	}
	m_minorskill.resize((int)msg.m_minorskill_size() > (int)m_minorskill.max_size() ? m_minorskill.max_size() : msg.m_minorskill_size());
	for(int32_t i = 0; i < (int32_t)m_minorskill.size(); ++i) {
		m_minorskill[i] = msg.m_minorskill(i);
	}
}

Sheet_FacadeSoul_s::Sheet_FacadeSoul_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_FacadeSoul_s::CreateInit() {
	return 0;
}

int Sheet_FacadeSoul_s::ResumeInit() {
	return 0;
}

void Sheet_FacadeSoul_s::write_to_pbmsg(::proto_ff::Sheet_FacadeSoul & msg) const {
	for(int32_t i = 0; i < (int32_t)E_FacadeSoul_List.size(); ++i) {
		::proto_ff::E_FacadeSoul* temp_e_facadesoul_list = msg.add_e_facadesoul_list();
		E_FacadeSoul_List[i].write_to_pbmsg(*temp_e_facadesoul_list);
	}
}

void Sheet_FacadeSoul_s::read_from_pbmsg(const ::proto_ff::Sheet_FacadeSoul & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_FacadeSoul_s));
	E_FacadeSoul_List.resize((int)msg.e_facadesoul_list_size() > (int)E_FacadeSoul_List.max_size() ? E_FacadeSoul_List.max_size() : msg.e_facadesoul_list_size());
	for(int32_t i = 0; i < (int32_t)E_FacadeSoul_List.size(); ++i) {
		const ::proto_ff::E_FacadeSoul & temp_e_facadesoul_list = msg.e_facadesoul_list(i);
		E_FacadeSoul_List[i].read_from_pbmsg(temp_e_facadesoul_list);
	}
}

E_FacadeSoulactiveUnlockDesc_s::E_FacadeSoulactiveUnlockDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_FacadeSoulactiveUnlockDesc_s::CreateInit() {
	m_condition = (int32_t)0;
	return 0;
}

int E_FacadeSoulactiveUnlockDesc_s::ResumeInit() {
	return 0;
}

void E_FacadeSoulactiveUnlockDesc_s::write_to_pbmsg(::proto_ff::E_FacadeSoulactiveUnlockDesc & msg) const {
	msg.set_m_parama((const char*)m_parama.data());
	msg.set_m_condition((int32_t)m_condition);
}

void E_FacadeSoulactiveUnlockDesc_s::read_from_pbmsg(const ::proto_ff::E_FacadeSoulactiveUnlockDesc & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct E_FacadeSoulactiveUnlockDesc_s));
	m_parama = msg.m_parama();
	m_condition = msg.m_condition();
}

E_FacadeSoulactive_s::E_FacadeSoulactive_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_FacadeSoulactive_s::CreateInit() {
	m_id = (int64_t)0;
	return 0;
}

int E_FacadeSoulactive_s::ResumeInit() {
	return 0;
}

void E_FacadeSoulactive_s::write_to_pbmsg(::proto_ff::E_FacadeSoulactive & msg) const {
	msg.set_m_id((int64_t)m_id);
	for(int32_t i = 0; i < (int32_t)m_unlock.size(); ++i) {
		::proto_ff::E_FacadeSoulactiveUnlockDesc* temp_m_unlock = msg.add_m_unlock();
		m_unlock[i].write_to_pbmsg(*temp_m_unlock);
	}
}

void E_FacadeSoulactive_s::read_from_pbmsg(const ::proto_ff::E_FacadeSoulactive & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct E_FacadeSoulactive_s));
	m_id = msg.m_id();
	m_unlock.resize((int)msg.m_unlock_size() > (int)m_unlock.max_size() ? m_unlock.max_size() : msg.m_unlock_size());
	for(int32_t i = 0; i < (int32_t)m_unlock.size(); ++i) {
		const ::proto_ff::E_FacadeSoulactiveUnlockDesc & temp_m_unlock = msg.m_unlock(i);
		m_unlock[i].read_from_pbmsg(temp_m_unlock);
	}
}

Sheet_FacadeSoulactive_s::Sheet_FacadeSoulactive_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_FacadeSoulactive_s::CreateInit() {
	return 0;
}

int Sheet_FacadeSoulactive_s::ResumeInit() {
	return 0;
}

void Sheet_FacadeSoulactive_s::write_to_pbmsg(::proto_ff::Sheet_FacadeSoulactive & msg) const {
	for(int32_t i = 0; i < (int32_t)E_FacadeSoulactive_List.size(); ++i) {
		::proto_ff::E_FacadeSoulactive* temp_e_facadesoulactive_list = msg.add_e_facadesoulactive_list();
		E_FacadeSoulactive_List[i].write_to_pbmsg(*temp_e_facadesoulactive_list);
	}
}

void Sheet_FacadeSoulactive_s::read_from_pbmsg(const ::proto_ff::Sheet_FacadeSoulactive & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_FacadeSoulactive_s));
	E_FacadeSoulactive_List.resize((int)msg.e_facadesoulactive_list_size() > (int)E_FacadeSoulactive_List.max_size() ? E_FacadeSoulactive_List.max_size() : msg.e_facadesoulactive_list_size());
	for(int32_t i = 0; i < (int32_t)E_FacadeSoulactive_List.size(); ++i) {
		const ::proto_ff::E_FacadeSoulactive & temp_e_facadesoulactive_list = msg.e_facadesoulactive_list(i);
		E_FacadeSoulactive_List[i].read_from_pbmsg(temp_e_facadesoulactive_list);
	}
}

E_FacadeSoullvAttributeDesc_s::E_FacadeSoullvAttributeDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_FacadeSoullvAttributeDesc_s::CreateInit() {
	m_type = (int32_t)0;
	m_value = (int32_t)0;
	return 0;
}

int E_FacadeSoullvAttributeDesc_s::ResumeInit() {
	return 0;
}

void E_FacadeSoullvAttributeDesc_s::write_to_pbmsg(::proto_ff::E_FacadeSoullvAttributeDesc & msg) const {
	msg.set_m_type((int32_t)m_type);
	msg.set_m_value((int32_t)m_value);
}

void E_FacadeSoullvAttributeDesc_s::read_from_pbmsg(const ::proto_ff::E_FacadeSoullvAttributeDesc & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct E_FacadeSoullvAttributeDesc_s));
	m_type = msg.m_type();
	m_value = msg.m_value();
}

E_FacadeSoullv_s::E_FacadeSoullv_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_FacadeSoullv_s::CreateInit() {
	m_id = (int64_t)0;
	m_soulllv = (int32_t)0;
	m_soulid = (int32_t)0;
	m_itemid = (int32_t)0;
	m_num = (int32_t)0;
	m_successrate = (int32_t)0;
	m_downlv = (int32_t)0;
	return 0;
}

int E_FacadeSoullv_s::ResumeInit() {
	return 0;
}

void E_FacadeSoullv_s::write_to_pbmsg(::proto_ff::E_FacadeSoullv & msg) const {
	msg.set_m_id((int64_t)m_id);
	msg.set_m_soulllv((int32_t)m_soulllv);
	msg.set_m_soulid((int32_t)m_soulid);
	msg.set_m_itemid((int32_t)m_itemid);
	msg.set_m_num((int32_t)m_num);
	msg.set_m_successrate((int32_t)m_successrate);
	msg.set_m_downlv((int32_t)m_downlv);
	for(int32_t i = 0; i < (int32_t)m_attribute.size(); ++i) {
		::proto_ff::E_FacadeSoullvAttributeDesc* temp_m_attribute = msg.add_m_attribute();
		m_attribute[i].write_to_pbmsg(*temp_m_attribute);
	}
}

void E_FacadeSoullv_s::read_from_pbmsg(const ::proto_ff::E_FacadeSoullv & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct E_FacadeSoullv_s));
	m_id = msg.m_id();
	m_soulllv = msg.m_soulllv();
	m_soulid = msg.m_soulid();
	m_itemid = msg.m_itemid();
	m_num = msg.m_num();
	m_successrate = msg.m_successrate();
	m_downlv = msg.m_downlv();
	m_attribute.resize((int)msg.m_attribute_size() > (int)m_attribute.max_size() ? m_attribute.max_size() : msg.m_attribute_size());
	for(int32_t i = 0; i < (int32_t)m_attribute.size(); ++i) {
		const ::proto_ff::E_FacadeSoullvAttributeDesc & temp_m_attribute = msg.m_attribute(i);
		m_attribute[i].read_from_pbmsg(temp_m_attribute);
	}
}

Sheet_FacadeSoullv_s::Sheet_FacadeSoullv_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_FacadeSoullv_s::CreateInit() {
	return 0;
}

int Sheet_FacadeSoullv_s::ResumeInit() {
	return 0;
}

void Sheet_FacadeSoullv_s::write_to_pbmsg(::proto_ff::Sheet_FacadeSoullv & msg) const {
	for(int32_t i = 0; i < (int32_t)E_FacadeSoullv_List.size(); ++i) {
		::proto_ff::E_FacadeSoullv* temp_e_facadesoullv_list = msg.add_e_facadesoullv_list();
		E_FacadeSoullv_List[i].write_to_pbmsg(*temp_e_facadesoullv_list);
	}
}

void Sheet_FacadeSoullv_s::read_from_pbmsg(const ::proto_ff::Sheet_FacadeSoullv & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_FacadeSoullv_s));
	E_FacadeSoullv_List.resize((int)msg.e_facadesoullv_list_size() > (int)E_FacadeSoullv_List.max_size() ? E_FacadeSoullv_List.max_size() : msg.e_facadesoullv_list_size());
	for(int32_t i = 0; i < (int32_t)E_FacadeSoullv_List.size(); ++i) {
		const ::proto_ff::E_FacadeSoullv & temp_e_facadesoullv_list = msg.e_facadesoullv_list(i);
		E_FacadeSoullv_List[i].read_from_pbmsg(temp_e_facadesoullv_list);
	}
}

E_FacadeSoulachievement_s::E_FacadeSoulachievement_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_FacadeSoulachievement_s::CreateInit() {
	m_id = (int64_t)0;
	m_soulid = (int32_t)0;
	m_type = (int32_t)0;
	m_parama = (int32_t)0;
	m_itemid = (int32_t)0;
	m_num = (int32_t)0;
	return 0;
}

int E_FacadeSoulachievement_s::ResumeInit() {
	return 0;
}

void E_FacadeSoulachievement_s::write_to_pbmsg(::proto_ff::E_FacadeSoulachievement & msg) const {
	msg.set_m_id((int64_t)m_id);
	msg.set_m_soulid((int32_t)m_soulid);
	msg.set_m_type((int32_t)m_type);
	msg.set_m_parama((int32_t)m_parama);
	msg.set_m_itemid((int32_t)m_itemid);
	msg.set_m_num((int32_t)m_num);
}

void E_FacadeSoulachievement_s::read_from_pbmsg(const ::proto_ff::E_FacadeSoulachievement & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct E_FacadeSoulachievement_s));
	m_id = msg.m_id();
	m_soulid = msg.m_soulid();
	m_type = msg.m_type();
	m_parama = msg.m_parama();
	m_itemid = msg.m_itemid();
	m_num = msg.m_num();
}

Sheet_FacadeSoulachievement_s::Sheet_FacadeSoulachievement_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_FacadeSoulachievement_s::CreateInit() {
	return 0;
}

int Sheet_FacadeSoulachievement_s::ResumeInit() {
	return 0;
}

void Sheet_FacadeSoulachievement_s::write_to_pbmsg(::proto_ff::Sheet_FacadeSoulachievement & msg) const {
	for(int32_t i = 0; i < (int32_t)E_FacadeSoulachievement_List.size(); ++i) {
		::proto_ff::E_FacadeSoulachievement* temp_e_facadesoulachievement_list = msg.add_e_facadesoulachievement_list();
		E_FacadeSoulachievement_List[i].write_to_pbmsg(*temp_e_facadesoulachievement_list);
	}
}

void Sheet_FacadeSoulachievement_s::read_from_pbmsg(const ::proto_ff::Sheet_FacadeSoulachievement & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_FacadeSoulachievement_s));
	E_FacadeSoulachievement_List.resize((int)msg.e_facadesoulachievement_list_size() > (int)E_FacadeSoulachievement_List.max_size() ? E_FacadeSoulachievement_List.max_size() : msg.e_facadesoulachievement_list_size());
	for(int32_t i = 0; i < (int32_t)E_FacadeSoulachievement_List.size(); ++i) {
		const ::proto_ff::E_FacadeSoulachievement & temp_e_facadesoulachievement_list = msg.e_facadesoulachievement_list(i);
		E_FacadeSoulachievement_List[i].read_from_pbmsg(temp_e_facadesoulachievement_list);
	}
}

}