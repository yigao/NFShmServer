#include "E_Facade_s.h"

namespace proto_ff_s {

E_FacadeDisplayMaterialDesc_s::E_FacadeDisplayMaterialDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_FacadeDisplayMaterialDesc_s::CreateInit() {
	m_exp = (int32_t)0;
	m_id = (int64_t)0;
	return 0;
}

int E_FacadeDisplayMaterialDesc_s::ResumeInit() {
	return 0;
}

void E_FacadeDisplayMaterialDesc_s::write_to_pbmsg(::proto_ff::E_FacadeDisplayMaterialDesc & msg) const {
	msg.set_m_exp((int32_t)m_exp);
	msg.set_m_id((int64_t)m_id);
}

void E_FacadeDisplayMaterialDesc_s::read_from_pbmsg(const ::proto_ff::E_FacadeDisplayMaterialDesc & msg) {
	m_exp = msg.m_exp();
	m_id = msg.m_id();
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
	m_soulIID = (int32_t)0;
	return 0;
}

int E_FacadeDisplay_s::ResumeInit() {
	return 0;
}

void E_FacadeDisplay_s::write_to_pbmsg(::proto_ff::E_FacadeDisplay & msg) const {
	msg.set_m_id((int64_t)m_id);
	msg.set_m_type((int32_t)m_type);
	msg.set_m_resource(m_resource.data());
	msg.set_m_name(m_name.data());
	msg.set_m_activedesc(m_activeDesc.data());
	msg.set_m_professionid(m_professionID.data());
	msg.set_m_skillid(m_skillID.data());
	msg.set_m_souliid((int32_t)m_soulIID);
	for(int32_t i = 0; i < (int32_t)m_material.size(); ++i) {
		::proto_ff::E_FacadeDisplayMaterialDesc* temp_m_material = msg.add_m_material();
		m_material[i].write_to_pbmsg(*temp_m_material);
	}
	for(int32_t i = 0; i < (int32_t)m_fragmentID.size(); ++i) {
		msg.add_m_fragmentid((int64_t)m_fragmentID[i]);
	}
}

void E_FacadeDisplay_s::read_from_pbmsg(const ::proto_ff::E_FacadeDisplay & msg) {
	m_id = msg.m_id();
	m_type = msg.m_type();
	m_resource = msg.m_resource();
	m_name = msg.m_name();
	m_activeDesc = msg.m_activedesc();
	m_professionID = msg.m_professionid();
	m_skillID = msg.m_skillid();
	m_soulIID = msg.m_souliid();
	m_material.resize((int)msg.m_material_size() > (int)m_material.max_size() ? m_material.max_size() : msg.m_material_size());
	for(int32_t i = 0; i < (int32_t)m_material.size(); ++i) {
		const ::proto_ff::E_FacadeDisplayMaterialDesc & temp_m_material = msg.m_material(i);
		m_material[i].read_from_pbmsg(temp_m_material);
	}
	m_fragmentID.resize((int)msg.m_fragmentid_size() > (int)m_fragmentID.max_size() ? m_fragmentID.max_size() : msg.m_fragmentid_size());
	for(int32_t i = 0; i < (int32_t)m_fragmentID.size(); ++i) {
		m_fragmentID[i] = msg.m_fragmentid(i);
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
	E_FacadeDisplay_List.resize((int)msg.e_facadedisplay_list_size() > (int)E_FacadeDisplay_List.max_size() ? E_FacadeDisplay_List.max_size() : msg.e_facadedisplay_list_size());
	for(int32_t i = 0; i < (int32_t)E_FacadeDisplay_List.size(); ++i) {
		const ::proto_ff::E_FacadeDisplay & temp_e_facadedisplay_list = msg.e_facadedisplay_list(i);
		E_FacadeDisplay_List[i].read_from_pbmsg(temp_e_facadedisplay_list);
	}
}

E_FacadeValueWingattributeDesc_s::E_FacadeValueWingattributeDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_FacadeValueWingattributeDesc_s::CreateInit() {
	m_value = (int32_t)0;
	m_type = (int32_t)0;
	return 0;
}

int E_FacadeValueWingattributeDesc_s::ResumeInit() {
	return 0;
}

void E_FacadeValueWingattributeDesc_s::write_to_pbmsg(::proto_ff::E_FacadeValueWingattributeDesc & msg) const {
	msg.set_m_value((int32_t)m_value);
	msg.set_m_type((int32_t)m_type);
}

void E_FacadeValueWingattributeDesc_s::read_from_pbmsg(const ::proto_ff::E_FacadeValueWingattributeDesc & msg) {
	m_value = msg.m_value();
	m_type = msg.m_type();
}

E_FacadeValueTreasureattributeDesc_s::E_FacadeValueTreasureattributeDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_FacadeValueTreasureattributeDesc_s::CreateInit() {
	m_value = (int32_t)0;
	m_type = (int32_t)0;
	return 0;
}

int E_FacadeValueTreasureattributeDesc_s::ResumeInit() {
	return 0;
}

void E_FacadeValueTreasureattributeDesc_s::write_to_pbmsg(::proto_ff::E_FacadeValueTreasureattributeDesc & msg) const {
	msg.set_m_value((int32_t)m_value);
	msg.set_m_type((int32_t)m_type);
}

void E_FacadeValueTreasureattributeDesc_s::read_from_pbmsg(const ::proto_ff::E_FacadeValueTreasureattributeDesc & msg) {
	m_value = msg.m_value();
	m_type = msg.m_type();
}

E_FacadeValueArtifactattributeDesc_s::E_FacadeValueArtifactattributeDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_FacadeValueArtifactattributeDesc_s::CreateInit() {
	m_value = (int32_t)0;
	m_type = (int32_t)0;
	return 0;
}

int E_FacadeValueArtifactattributeDesc_s::ResumeInit() {
	return 0;
}

void E_FacadeValueArtifactattributeDesc_s::write_to_pbmsg(::proto_ff::E_FacadeValueArtifactattributeDesc & msg) const {
	msg.set_m_value((int32_t)m_value);
	msg.set_m_type((int32_t)m_type);
}

void E_FacadeValueArtifactattributeDesc_s::read_from_pbmsg(const ::proto_ff::E_FacadeValueArtifactattributeDesc & msg) {
	m_value = msg.m_value();
	m_type = msg.m_type();
}

E_FacadeValueBladeattributeDesc_s::E_FacadeValueBladeattributeDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_FacadeValueBladeattributeDesc_s::CreateInit() {
	m_value = (int32_t)0;
	m_type = (int32_t)0;
	return 0;
}

int E_FacadeValueBladeattributeDesc_s::ResumeInit() {
	return 0;
}

void E_FacadeValueBladeattributeDesc_s::write_to_pbmsg(::proto_ff::E_FacadeValueBladeattributeDesc & msg) const {
	msg.set_m_value((int32_t)m_value);
	msg.set_m_type((int32_t)m_type);
}

void E_FacadeValueBladeattributeDesc_s::read_from_pbmsg(const ::proto_ff::E_FacadeValueBladeattributeDesc & msg) {
	m_value = msg.m_value();
	m_type = msg.m_type();
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
	m_wingExp = (int64_t)0;
	m_treasureExp = (int64_t)0;
	m_ArtifactExp = (int64_t)0;
	m_BladeExp = (int64_t)0;
	return 0;
}

int E_FacadeValue_s::ResumeInit() {
	return 0;
}

void E_FacadeValue_s::write_to_pbmsg(::proto_ff::E_FacadeValue & msg) const {
	msg.set_m_lv((int32_t)m_lv);
	msg.set_m_wingexp((int64_t)m_wingExp);
	msg.set_m_treasureexp((int64_t)m_treasureExp);
	msg.set_m_artifactexp((int64_t)m_ArtifactExp);
	msg.set_m_bladeexp((int64_t)m_BladeExp);
	for(int32_t i = 0; i < (int32_t)m_wingAttribute.size(); ++i) {
		::proto_ff::E_FacadeValueWingattributeDesc* temp_m_wingattribute = msg.add_m_wingattribute();
		m_wingAttribute[i].write_to_pbmsg(*temp_m_wingattribute);
	}
	for(int32_t i = 0; i < (int32_t)m_treasureAttribute.size(); ++i) {
		::proto_ff::E_FacadeValueTreasureattributeDesc* temp_m_treasureattribute = msg.add_m_treasureattribute();
		m_treasureAttribute[i].write_to_pbmsg(*temp_m_treasureattribute);
	}
	for(int32_t i = 0; i < (int32_t)m_ArtifactAttribute.size(); ++i) {
		::proto_ff::E_FacadeValueArtifactattributeDesc* temp_m_artifactattribute = msg.add_m_artifactattribute();
		m_ArtifactAttribute[i].write_to_pbmsg(*temp_m_artifactattribute);
	}
	for(int32_t i = 0; i < (int32_t)m_BladeAttribute.size(); ++i) {
		::proto_ff::E_FacadeValueBladeattributeDesc* temp_m_bladeattribute = msg.add_m_bladeattribute();
		m_BladeAttribute[i].write_to_pbmsg(*temp_m_bladeattribute);
	}
}

void E_FacadeValue_s::read_from_pbmsg(const ::proto_ff::E_FacadeValue & msg) {
	m_lv = msg.m_lv();
	m_wingExp = msg.m_wingexp();
	m_treasureExp = msg.m_treasureexp();
	m_ArtifactExp = msg.m_artifactexp();
	m_BladeExp = msg.m_bladeexp();
	m_wingAttribute.resize((int)msg.m_wingattribute_size() > (int)m_wingAttribute.max_size() ? m_wingAttribute.max_size() : msg.m_wingattribute_size());
	for(int32_t i = 0; i < (int32_t)m_wingAttribute.size(); ++i) {
		const ::proto_ff::E_FacadeValueWingattributeDesc & temp_m_wingattribute = msg.m_wingattribute(i);
		m_wingAttribute[i].read_from_pbmsg(temp_m_wingattribute);
	}
	m_treasureAttribute.resize((int)msg.m_treasureattribute_size() > (int)m_treasureAttribute.max_size() ? m_treasureAttribute.max_size() : msg.m_treasureattribute_size());
	for(int32_t i = 0; i < (int32_t)m_treasureAttribute.size(); ++i) {
		const ::proto_ff::E_FacadeValueTreasureattributeDesc & temp_m_treasureattribute = msg.m_treasureattribute(i);
		m_treasureAttribute[i].read_from_pbmsg(temp_m_treasureattribute);
	}
	m_ArtifactAttribute.resize((int)msg.m_artifactattribute_size() > (int)m_ArtifactAttribute.max_size() ? m_ArtifactAttribute.max_size() : msg.m_artifactattribute_size());
	for(int32_t i = 0; i < (int32_t)m_ArtifactAttribute.size(); ++i) {
		const ::proto_ff::E_FacadeValueArtifactattributeDesc & temp_m_artifactattribute = msg.m_artifactattribute(i);
		m_ArtifactAttribute[i].read_from_pbmsg(temp_m_artifactattribute);
	}
	m_BladeAttribute.resize((int)msg.m_bladeattribute_size() > (int)m_BladeAttribute.max_size() ? m_BladeAttribute.max_size() : msg.m_bladeattribute_size());
	for(int32_t i = 0; i < (int32_t)m_BladeAttribute.size(); ++i) {
		const ::proto_ff::E_FacadeValueBladeattributeDesc & temp_m_bladeattribute = msg.m_bladeattribute(i);
		m_BladeAttribute[i].read_from_pbmsg(temp_m_bladeattribute);
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
	msg.set_m_soucename(m_souceName.data());
}

void E_FacadeType_s::read_from_pbmsg(const ::proto_ff::E_FacadeType & msg) {
	m_id = msg.m_id();
	m_souceName = msg.m_soucename();
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
	m_value = (int32_t)0;
	m_type = (int32_t)0;
	return 0;
}

int E_FacadeFragmentAttributeDesc_s::ResumeInit() {
	return 0;
}

void E_FacadeFragmentAttributeDesc_s::write_to_pbmsg(::proto_ff::E_FacadeFragmentAttributeDesc & msg) const {
	msg.set_m_value((int32_t)m_value);
	msg.set_m_type((int32_t)m_type);
}

void E_FacadeFragmentAttributeDesc_s::read_from_pbmsg(const ::proto_ff::E_FacadeFragmentAttributeDesc & msg) {
	m_value = msg.m_value();
	m_type = msg.m_type();
}

E_FacadeFragment_s::E_FacadeFragment_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_FacadeFragment_s::CreateInit() {
	m_fragmentID = (int64_t)0;
	m_item = (int64_t)0;
	m_itemNum = (int32_t)0;
	return 0;
}

int E_FacadeFragment_s::ResumeInit() {
	return 0;
}

void E_FacadeFragment_s::write_to_pbmsg(::proto_ff::E_FacadeFragment & msg) const {
	msg.set_m_fragmentid((int64_t)m_fragmentID);
	msg.set_m_item((int64_t)m_item);
	msg.set_m_itemnum((int32_t)m_itemNum);
	for(int32_t i = 0; i < (int32_t)m_attribute.size(); ++i) {
		::proto_ff::E_FacadeFragmentAttributeDesc* temp_m_attribute = msg.add_m_attribute();
		m_attribute[i].write_to_pbmsg(*temp_m_attribute);
	}
}

void E_FacadeFragment_s::read_from_pbmsg(const ::proto_ff::E_FacadeFragment & msg) {
	m_fragmentID = msg.m_fragmentid();
	m_item = msg.m_item();
	m_itemNum = msg.m_itemnum();
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
	m_value = (int32_t)0;
	m_type = (int32_t)0;
	return 0;
}

int E_FacadeChangeAttributeDesc_s::ResumeInit() {
	return 0;
}

void E_FacadeChangeAttributeDesc_s::write_to_pbmsg(::proto_ff::E_FacadeChangeAttributeDesc & msg) const {
	msg.set_m_value((int32_t)m_value);
	msg.set_m_type((int32_t)m_type);
}

void E_FacadeChangeAttributeDesc_s::read_from_pbmsg(const ::proto_ff::E_FacadeChangeAttributeDesc & msg) {
	m_value = msg.m_value();
	m_type = msg.m_type();
}

E_FacadeChangeActiveattributeDesc_s::E_FacadeChangeActiveattributeDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_FacadeChangeActiveattributeDesc_s::CreateInit() {
	m_value = (int32_t)0;
	m_type = (int32_t)0;
	return 0;
}

int E_FacadeChangeActiveattributeDesc_s::ResumeInit() {
	return 0;
}

void E_FacadeChangeActiveattributeDesc_s::write_to_pbmsg(::proto_ff::E_FacadeChangeActiveattributeDesc & msg) const {
	msg.set_m_value((int32_t)m_value);
	msg.set_m_type((int32_t)m_type);
}

void E_FacadeChangeActiveattributeDesc_s::read_from_pbmsg(const ::proto_ff::E_FacadeChangeActiveattributeDesc & msg) {
	m_value = msg.m_value();
	m_type = msg.m_type();
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
	m_activationItem = (int64_t)0;
	m_activationNum = (int32_t)0;
	m_starId = (int64_t)0;
	m_starUp = (int32_t)0;
	m_starBer = (int32_t)0;
	m_upAttributeId = (int64_t)0;
	m_activeSkill = (int32_t)0;
	return 0;
}

int E_FacadeChange_s::ResumeInit() {
	return 0;
}

void E_FacadeChange_s::write_to_pbmsg(::proto_ff::E_FacadeChange & msg) const {
	msg.set_m_id((int64_t)m_id);
	msg.set_m_type((int32_t)m_type);
	msg.set_m_resource(m_resource.data());
	msg.set_m_professionid(m_professionID.data());
	msg.set_m_name(m_name.data());
	msg.set_m_activedesc(m_activeDesc.data());
	msg.set_m_quality((int32_t)m_quality);
	msg.set_m_activationitem((int64_t)m_activationItem);
	msg.set_m_activationnum((int32_t)m_activationNum);
	msg.set_m_starid((int64_t)m_starId);
	msg.set_m_starnum(m_starNum.data());
	msg.set_m_starup((int32_t)m_starUp);
	msg.set_m_starber((int32_t)m_starBer);
	msg.set_m_upattributeid((int64_t)m_upAttributeId);
	msg.set_m_activeskill((int32_t)m_activeSkill);
	for(int32_t i = 0; i < (int32_t)m_attribute.size(); ++i) {
		::proto_ff::E_FacadeChangeAttributeDesc* temp_m_attribute = msg.add_m_attribute();
		m_attribute[i].write_to_pbmsg(*temp_m_attribute);
	}
	for(int32_t i = 0; i < (int32_t)m_ActiveAttribute.size(); ++i) {
		::proto_ff::E_FacadeChangeActiveattributeDesc* temp_m_activeattribute = msg.add_m_activeattribute();
		m_ActiveAttribute[i].write_to_pbmsg(*temp_m_activeattribute);
	}
}

void E_FacadeChange_s::read_from_pbmsg(const ::proto_ff::E_FacadeChange & msg) {
	m_id = msg.m_id();
	m_type = msg.m_type();
	m_resource = msg.m_resource();
	m_professionID = msg.m_professionid();
	m_name = msg.m_name();
	m_activeDesc = msg.m_activedesc();
	m_quality = msg.m_quality();
	m_activationItem = msg.m_activationitem();
	m_activationNum = msg.m_activationnum();
	m_starId = msg.m_starid();
	m_starNum = msg.m_starnum();
	m_starUp = msg.m_starup();
	m_starBer = msg.m_starber();
	m_upAttributeId = msg.m_upattributeid();
	m_activeSkill = msg.m_activeskill();
	m_attribute.resize((int)msg.m_attribute_size() > (int)m_attribute.max_size() ? m_attribute.max_size() : msg.m_attribute_size());
	for(int32_t i = 0; i < (int32_t)m_attribute.size(); ++i) {
		const ::proto_ff::E_FacadeChangeAttributeDesc & temp_m_attribute = msg.m_attribute(i);
		m_attribute[i].read_from_pbmsg(temp_m_attribute);
	}
	m_ActiveAttribute.resize((int)msg.m_activeattribute_size() > (int)m_ActiveAttribute.max_size() ? m_ActiveAttribute.max_size() : msg.m_activeattribute_size());
	for(int32_t i = 0; i < (int32_t)m_ActiveAttribute.size(); ++i) {
		const ::proto_ff::E_FacadeChangeActiveattributeDesc & temp_m_activeattribute = msg.m_activeattribute(i);
		m_ActiveAttribute[i].read_from_pbmsg(temp_m_activeattribute);
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
	m_value = (int32_t)0;
	m_type = (int32_t)0;
	return 0;
}

int E_FacadeStarupUpattributeDesc_s::ResumeInit() {
	return 0;
}

void E_FacadeStarupUpattributeDesc_s::write_to_pbmsg(::proto_ff::E_FacadeStarupUpattributeDesc & msg) const {
	msg.set_m_value((int32_t)m_value);
	msg.set_m_type((int32_t)m_type);
}

void E_FacadeStarupUpattributeDesc_s::read_from_pbmsg(const ::proto_ff::E_FacadeStarupUpattributeDesc & msg) {
	m_value = msg.m_value();
	m_type = msg.m_type();
}

E_FacadeStarup_s::E_FacadeStarup_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_FacadeStarup_s::CreateInit() {
	m_ID = (int32_t)0;
	m_upAttributeId = (int64_t)0;
	m_starID = (int32_t)0;
	m_skillID = (int32_t)0;
	return 0;
}

int E_FacadeStarup_s::ResumeInit() {
	return 0;
}

void E_FacadeStarup_s::write_to_pbmsg(::proto_ff::E_FacadeStarup & msg) const {
	msg.set_m_id((int32_t)m_ID);
	msg.set_m_upattributeid((int64_t)m_upAttributeId);
	msg.set_m_starid((int32_t)m_starID);
	msg.set_m_skillid((int32_t)m_skillID);
	for(int32_t i = 0; i < (int32_t)m_upAttribute.size(); ++i) {
		::proto_ff::E_FacadeStarupUpattributeDesc* temp_m_upattribute = msg.add_m_upattribute();
		m_upAttribute[i].write_to_pbmsg(*temp_m_upattribute);
	}
}

void E_FacadeStarup_s::read_from_pbmsg(const ::proto_ff::E_FacadeStarup & msg) {
	m_ID = msg.m_id();
	m_upAttributeId = msg.m_upattributeid();
	m_starID = msg.m_starid();
	m_skillID = msg.m_skillid();
	m_upAttribute.resize((int)msg.m_upattribute_size() > (int)m_upAttribute.max_size() ? m_upAttribute.max_size() : msg.m_upattribute_size());
	for(int32_t i = 0; i < (int32_t)m_upAttribute.size(); ++i) {
		const ::proto_ff::E_FacadeStarupUpattributeDesc & temp_m_upattribute = msg.m_upattribute(i);
		m_upAttribute[i].read_from_pbmsg(temp_m_upattribute);
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
	m_value = (int32_t)0;
	m_type = (int32_t)0;
	return 0;
}

int E_FacadeSoulAttributeDesc_s::ResumeInit() {
	return 0;
}

void E_FacadeSoulAttributeDesc_s::write_to_pbmsg(::proto_ff::E_FacadeSoulAttributeDesc & msg) const {
	msg.set_m_value((int32_t)m_value);
	msg.set_m_type((int32_t)m_type);
}

void E_FacadeSoulAttributeDesc_s::read_from_pbmsg(const ::proto_ff::E_FacadeSoulAttributeDesc & msg) {
	m_value = msg.m_value();
	m_type = msg.m_type();
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
	m_rechargeID = (int32_t)0;
	m_mainSkill = (int32_t)0;
	return 0;
}

int E_FacadeSoul_s::ResumeInit() {
	return 0;
}

void E_FacadeSoul_s::write_to_pbmsg(::proto_ff::E_FacadeSoul & msg) const {
	msg.set_m_id((int64_t)m_id);
	msg.set_m_rechargeid((int32_t)m_rechargeID);
	msg.set_m_mainskill((int32_t)m_mainSkill);
	msg.set_m_attributetype(m_attributeType.data());
	for(int32_t i = 0; i < (int32_t)m_minorSkill.size(); ++i) {
		msg.add_m_minorskill((int32_t)m_minorSkill[i]);
	}
	for(int32_t i = 0; i < (int32_t)m_attribute.size(); ++i) {
		::proto_ff::E_FacadeSoulAttributeDesc* temp_m_attribute = msg.add_m_attribute();
		m_attribute[i].write_to_pbmsg(*temp_m_attribute);
	}
}

void E_FacadeSoul_s::read_from_pbmsg(const ::proto_ff::E_FacadeSoul & msg) {
	m_id = msg.m_id();
	m_rechargeID = msg.m_rechargeid();
	m_mainSkill = msg.m_mainskill();
	m_attributeType = msg.m_attributetype();
	m_minorSkill.resize((int)msg.m_minorskill_size() > (int)m_minorSkill.max_size() ? m_minorSkill.max_size() : msg.m_minorskill_size());
	for(int32_t i = 0; i < (int32_t)m_minorSkill.size(); ++i) {
		m_minorSkill[i] = msg.m_minorskill(i);
	}
	m_attribute.resize((int)msg.m_attribute_size() > (int)m_attribute.max_size() ? m_attribute.max_size() : msg.m_attribute_size());
	for(int32_t i = 0; i < (int32_t)m_attribute.size(); ++i) {
		const ::proto_ff::E_FacadeSoulAttributeDesc & temp_m_attribute = msg.m_attribute(i);
		m_attribute[i].read_from_pbmsg(temp_m_attribute);
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
	msg.set_m_parama(m_parama.data());
	msg.set_m_condition((int32_t)m_condition);
}

void E_FacadeSoulactiveUnlockDesc_s::read_from_pbmsg(const ::proto_ff::E_FacadeSoulactiveUnlockDesc & msg) {
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
	m_value = (int32_t)0;
	m_type = (int32_t)0;
	return 0;
}

int E_FacadeSoullvAttributeDesc_s::ResumeInit() {
	return 0;
}

void E_FacadeSoullvAttributeDesc_s::write_to_pbmsg(::proto_ff::E_FacadeSoullvAttributeDesc & msg) const {
	msg.set_m_value((int32_t)m_value);
	msg.set_m_type((int32_t)m_type);
}

void E_FacadeSoullvAttributeDesc_s::read_from_pbmsg(const ::proto_ff::E_FacadeSoullvAttributeDesc & msg) {
	m_value = msg.m_value();
	m_type = msg.m_type();
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
	m_soullLv = (int32_t)0;
	m_soulID = (int32_t)0;
	m_itemID = (int32_t)0;
	m_num = (int32_t)0;
	m_successRate = (int32_t)0;
	m_downLv = (int32_t)0;
	return 0;
}

int E_FacadeSoullv_s::ResumeInit() {
	return 0;
}

void E_FacadeSoullv_s::write_to_pbmsg(::proto_ff::E_FacadeSoullv & msg) const {
	msg.set_m_id((int64_t)m_id);
	msg.set_m_soulllv((int32_t)m_soullLv);
	msg.set_m_soulid((int32_t)m_soulID);
	msg.set_m_itemid((int32_t)m_itemID);
	msg.set_m_num((int32_t)m_num);
	msg.set_m_successrate((int32_t)m_successRate);
	msg.set_m_downlv((int32_t)m_downLv);
	for(int32_t i = 0; i < (int32_t)m_attribute.size(); ++i) {
		::proto_ff::E_FacadeSoullvAttributeDesc* temp_m_attribute = msg.add_m_attribute();
		m_attribute[i].write_to_pbmsg(*temp_m_attribute);
	}
}

void E_FacadeSoullv_s::read_from_pbmsg(const ::proto_ff::E_FacadeSoullv & msg) {
	m_id = msg.m_id();
	m_soullLv = msg.m_soulllv();
	m_soulID = msg.m_soulid();
	m_itemID = msg.m_itemid();
	m_num = msg.m_num();
	m_successRate = msg.m_successrate();
	m_downLv = msg.m_downlv();
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
	m_soulID = (int32_t)0;
	m_type = (int32_t)0;
	m_parama = (int32_t)0;
	m_itemID = (int32_t)0;
	m_num = (int32_t)0;
	return 0;
}

int E_FacadeSoulachievement_s::ResumeInit() {
	return 0;
}

void E_FacadeSoulachievement_s::write_to_pbmsg(::proto_ff::E_FacadeSoulachievement & msg) const {
	msg.set_m_id((int64_t)m_id);
	msg.set_m_soulid((int32_t)m_soulID);
	msg.set_m_type((int32_t)m_type);
	msg.set_m_parama((int32_t)m_parama);
	msg.set_m_itemid((int32_t)m_itemID);
	msg.set_m_num((int32_t)m_num);
}

void E_FacadeSoulachievement_s::read_from_pbmsg(const ::proto_ff::E_FacadeSoulachievement & msg) {
	m_id = msg.m_id();
	m_soulID = msg.m_soulid();
	m_type = msg.m_type();
	m_parama = msg.m_parama();
	m_itemID = msg.m_itemid();
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
	E_FacadeSoulachievement_List.resize((int)msg.e_facadesoulachievement_list_size() > (int)E_FacadeSoulachievement_List.max_size() ? E_FacadeSoulachievement_List.max_size() : msg.e_facadesoulachievement_list_size());
	for(int32_t i = 0; i < (int32_t)E_FacadeSoulachievement_List.size(); ++i) {
		const ::proto_ff::E_FacadeSoulachievement & temp_e_facadesoulachievement_list = msg.e_facadesoulachievement_list(i);
		E_FacadeSoulachievement_List[i].read_from_pbmsg(temp_e_facadesoulachievement_list);
	}
}

}
