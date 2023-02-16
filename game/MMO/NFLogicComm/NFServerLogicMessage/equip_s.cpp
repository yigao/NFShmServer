#include "equip_s.h"

namespace proto_ff_s {

E_EquipEquipAttributeDesc_s::E_EquipEquipAttributeDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_EquipEquipAttributeDesc_s::CreateInit() {
	m_valuemin = (int32_t)0;
	m_type = (int32_t)0;
	m_valuemax = (int32_t)0;
	return 0;
}

int E_EquipEquipAttributeDesc_s::ResumeInit() {
	return 0;
}

void E_EquipEquipAttributeDesc_s::write_to_pbmsg(::proto_ff::E_EquipEquipAttributeDesc & msg) const {
	msg.set_m_valuemin((int32_t)m_valuemin);
	msg.set_m_type((int32_t)m_type);
	msg.set_m_valuemax((int32_t)m_valuemax);
}

void E_EquipEquipAttributeDesc_s::read_from_pbmsg(const ::proto_ff::E_EquipEquipAttributeDesc & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct E_EquipEquipAttributeDesc_s));
	m_valuemin = msg.m_valuemin();
	m_type = msg.m_type();
	m_valuemax = msg.m_valuemax();
}

E_EquipEquipGodattributeDesc_s::E_EquipEquipGodattributeDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_EquipEquipGodattributeDesc_s::CreateInit() {
	m_valuemin = (int32_t)0;
	m_type = (int32_t)0;
	m_valuemax = (int32_t)0;
	return 0;
}

int E_EquipEquipGodattributeDesc_s::ResumeInit() {
	return 0;
}

void E_EquipEquipGodattributeDesc_s::write_to_pbmsg(::proto_ff::E_EquipEquipGodattributeDesc & msg) const {
	msg.set_m_valuemin((int32_t)m_valuemin);
	msg.set_m_type((int32_t)m_type);
	msg.set_m_valuemax((int32_t)m_valuemax);
}

void E_EquipEquipGodattributeDesc_s::read_from_pbmsg(const ::proto_ff::E_EquipEquipGodattributeDesc & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct E_EquipEquipGodattributeDesc_s));
	m_valuemin = msg.m_valuemin();
	m_type = msg.m_type();
	m_valuemax = msg.m_valuemax();
}

E_EquipEquip_s::E_EquipEquip_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_EquipEquip_s::CreateInit() {
	m_id = (int64_t)0;
	m_wearquality = (int32_t)0;
	m_position = (int32_t)0;
	m_professionlv = (int32_t)0;
	m_level = (int32_t)0;
	m_quality = (int32_t)0;
	m_star = (int32_t)0;
	m_refineattributedown = (int32_t)0;
	m_refineattributeup = (int32_t)0;
	m_bluestarnum = (int32_t)0;
	m_iscanbind = (int32_t)0;
	m_istradebind = (int32_t)0;
	m_sellprice = (int32_t)0;
	m_time = (int32_t)0;
	m_broadcast = (int32_t)0;
	m_specialattributedown = (int32_t)0;
	m_specialattributeup = (int32_t)0;
	return 0;
}

int E_EquipEquip_s::ResumeInit() {
	return 0;
}

void E_EquipEquip_s::write_to_pbmsg(::proto_ff::E_EquipEquip & msg) const {
	msg.set_m_id((int64_t)m_id);
	msg.set_m_name((const char*)m_name.data());
	msg.set_m_wearquality((int32_t)m_wearquality);
	msg.set_m_position((int32_t)m_position);
	msg.set_m_profession((const char*)m_profession.data());
	msg.set_m_professionlv((int32_t)m_professionlv);
	msg.set_m_level((int32_t)m_level);
	msg.set_m_quality((int32_t)m_quality);
	msg.set_m_star((int32_t)m_star);
	msg.set_m_refineattributedown((int32_t)m_refineattributedown);
	msg.set_m_refineattributeup((int32_t)m_refineattributeup);
	msg.set_m_refineattribute_typelibrary((const char*)m_refineattribute_typelibrary.data());
	msg.set_m_refineattribute_valuemin((const char*)m_refineattribute_valuemin.data());
	msg.set_m_refineattribute_valuemax((const char*)m_refineattribute_valuemax.data());
	msg.set_m_bluestarnum((int32_t)m_bluestarnum);
	msg.set_m_bluestar_type((const char*)m_bluestar_type.data());
	msg.set_m_bluestar_lv((const char*)m_bluestar_lv.data());
	msg.set_m_bluestar_number((const char*)m_bluestar_number.data());
	msg.set_m_iscanbind((int32_t)m_iscanbind);
	msg.set_m_istradebind((int32_t)m_istradebind);
	msg.set_m_sellprice((int32_t)m_sellprice);
	msg.set_m_icon((const char*)m_icon.data());
	msg.set_m_time((int32_t)m_time);
	msg.set_m_broadcast((int32_t)m_broadcast);
	msg.set_m_meltingresult((const char*)m_meltingresult.data());
	msg.set_m_specialattributedown((int32_t)m_specialattributedown);
	msg.set_m_specialattributeup((int32_t)m_specialattributeup);
	msg.set_m_specialattribute_typelibrary((const char*)m_specialattribute_typelibrary.data());
	msg.set_m_specialattribute_valuemin((const char*)m_specialattribute_valuemin.data());
	msg.set_m_specialattribute_valuemax((const char*)m_specialattribute_valuemax.data());
	msg.set_m_skillid((const char*)m_skillid.data());
	for(int32_t i = 0; i < (int32_t)m_attribute.size(); ++i) {
		::proto_ff::E_EquipEquipAttributeDesc* temp_m_attribute = msg.add_m_attribute();
		m_attribute[i].write_to_pbmsg(*temp_m_attribute);
	}
	for(int32_t i = 0; i < (int32_t)m_godattribute.size(); ++i) {
		::proto_ff::E_EquipEquipGodattributeDesc* temp_m_godattribute = msg.add_m_godattribute();
		m_godattribute[i].write_to_pbmsg(*temp_m_godattribute);
	}
}

void E_EquipEquip_s::read_from_pbmsg(const ::proto_ff::E_EquipEquip & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct E_EquipEquip_s));
	m_id = msg.m_id();
	m_name = msg.m_name();
	m_wearquality = msg.m_wearquality();
	m_position = msg.m_position();
	m_profession = msg.m_profession();
	m_professionlv = msg.m_professionlv();
	m_level = msg.m_level();
	m_quality = msg.m_quality();
	m_star = msg.m_star();
	m_refineattributedown = msg.m_refineattributedown();
	m_refineattributeup = msg.m_refineattributeup();
	m_refineattribute_typelibrary = msg.m_refineattribute_typelibrary();
	m_refineattribute_valuemin = msg.m_refineattribute_valuemin();
	m_refineattribute_valuemax = msg.m_refineattribute_valuemax();
	m_bluestarnum = msg.m_bluestarnum();
	m_bluestar_type = msg.m_bluestar_type();
	m_bluestar_lv = msg.m_bluestar_lv();
	m_bluestar_number = msg.m_bluestar_number();
	m_iscanbind = msg.m_iscanbind();
	m_istradebind = msg.m_istradebind();
	m_sellprice = msg.m_sellprice();
	m_icon = msg.m_icon();
	m_time = msg.m_time();
	m_broadcast = msg.m_broadcast();
	m_meltingresult = msg.m_meltingresult();
	m_specialattributedown = msg.m_specialattributedown();
	m_specialattributeup = msg.m_specialattributeup();
	m_specialattribute_typelibrary = msg.m_specialattribute_typelibrary();
	m_specialattribute_valuemin = msg.m_specialattribute_valuemin();
	m_specialattribute_valuemax = msg.m_specialattribute_valuemax();
	m_skillid = msg.m_skillid();
	m_attribute.resize((int)msg.m_attribute_size() > (int)m_attribute.max_size() ? m_attribute.max_size() : msg.m_attribute_size());
	for(int32_t i = 0; i < (int32_t)m_attribute.size(); ++i) {
		const ::proto_ff::E_EquipEquipAttributeDesc & temp_m_attribute = msg.m_attribute(i);
		m_attribute[i].read_from_pbmsg(temp_m_attribute);
	}
	m_godattribute.resize((int)msg.m_godattribute_size() > (int)m_godattribute.max_size() ? m_godattribute.max_size() : msg.m_godattribute_size());
	for(int32_t i = 0; i < (int32_t)m_godattribute.size(); ++i) {
		const ::proto_ff::E_EquipEquipGodattributeDesc & temp_m_godattribute = msg.m_godattribute(i);
		m_godattribute[i].read_from_pbmsg(temp_m_godattribute);
	}
}

Sheet_EquipEquip_s::Sheet_EquipEquip_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_EquipEquip_s::CreateInit() {
	return 0;
}

int Sheet_EquipEquip_s::ResumeInit() {
	return 0;
}

void Sheet_EquipEquip_s::write_to_pbmsg(::proto_ff::Sheet_EquipEquip & msg) const {
	for(int32_t i = 0; i < (int32_t)E_EquipEquip_List.size(); ++i) {
		::proto_ff::E_EquipEquip* temp_e_equipequip_list = msg.add_e_equipequip_list();
		E_EquipEquip_List[i].write_to_pbmsg(*temp_e_equipequip_list);
	}
}

void Sheet_EquipEquip_s::read_from_pbmsg(const ::proto_ff::Sheet_EquipEquip & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_EquipEquip_s));
	E_EquipEquip_List.resize((int)msg.e_equipequip_list_size() > (int)E_EquipEquip_List.max_size() ? E_EquipEquip_List.max_size() : msg.e_equipequip_list_size());
	for(int32_t i = 0; i < (int32_t)E_EquipEquip_List.size(); ++i) {
		const ::proto_ff::E_EquipEquip & temp_e_equipequip_list = msg.e_equipequip_list(i);
		E_EquipEquip_List[i].read_from_pbmsg(temp_e_equipequip_list);
	}
}

E_EquipStrongTypeDesc_s::E_EquipStrongTypeDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_EquipStrongTypeDesc_s::CreateInit() {
	m_id = (int32_t)0;
	return 0;
}

int E_EquipStrongTypeDesc_s::ResumeInit() {
	return 0;
}

void E_EquipStrongTypeDesc_s::write_to_pbmsg(::proto_ff::E_EquipStrongTypeDesc & msg) const {
	msg.set_m_num((const char*)m_num.data());
	msg.set_m_id((int32_t)m_id);
}

void E_EquipStrongTypeDesc_s::read_from_pbmsg(const ::proto_ff::E_EquipStrongTypeDesc & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct E_EquipStrongTypeDesc_s));
	m_num = msg.m_num();
	m_id = msg.m_id();
}

E_EquipStrong_s::E_EquipStrong_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_EquipStrong_s::CreateInit() {
	m_id = (int64_t)0;
	m_position = (int32_t)0;
	m_wearquality = (int32_t)0;
	m_srtongup = (int32_t)0;
	return 0;
}

int E_EquipStrong_s::ResumeInit() {
	return 0;
}

void E_EquipStrong_s::write_to_pbmsg(::proto_ff::E_EquipStrong & msg) const {
	msg.set_m_id((int64_t)m_id);
	msg.set_m_position((int32_t)m_position);
	msg.set_m_wearquality((int32_t)m_wearquality);
	msg.set_m_srtongup((int32_t)m_srtongup);
	for(int32_t i = 0; i < (int32_t)m_type.size(); ++i) {
		::proto_ff::E_EquipStrongTypeDesc* temp_m_type = msg.add_m_type();
		m_type[i].write_to_pbmsg(*temp_m_type);
	}
}

void E_EquipStrong_s::read_from_pbmsg(const ::proto_ff::E_EquipStrong & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct E_EquipStrong_s));
	m_id = msg.m_id();
	m_position = msg.m_position();
	m_wearquality = msg.m_wearquality();
	m_srtongup = msg.m_srtongup();
	m_type.resize((int)msg.m_type_size() > (int)m_type.max_size() ? m_type.max_size() : msg.m_type_size());
	for(int32_t i = 0; i < (int32_t)m_type.size(); ++i) {
		const ::proto_ff::E_EquipStrongTypeDesc & temp_m_type = msg.m_type(i);
		m_type[i].read_from_pbmsg(temp_m_type);
	}
}

Sheet_EquipStrong_s::Sheet_EquipStrong_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_EquipStrong_s::CreateInit() {
	return 0;
}

int Sheet_EquipStrong_s::ResumeInit() {
	return 0;
}

void Sheet_EquipStrong_s::write_to_pbmsg(::proto_ff::Sheet_EquipStrong & msg) const {
	for(int32_t i = 0; i < (int32_t)E_EquipStrong_List.size(); ++i) {
		::proto_ff::E_EquipStrong* temp_e_equipstrong_list = msg.add_e_equipstrong_list();
		E_EquipStrong_List[i].write_to_pbmsg(*temp_e_equipstrong_list);
	}
}

void Sheet_EquipStrong_s::read_from_pbmsg(const ::proto_ff::Sheet_EquipStrong & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_EquipStrong_s));
	E_EquipStrong_List.resize((int)msg.e_equipstrong_list_size() > (int)E_EquipStrong_List.max_size() ? E_EquipStrong_List.max_size() : msg.e_equipstrong_list_size());
	for(int32_t i = 0; i < (int32_t)E_EquipStrong_List.size(); ++i) {
		const ::proto_ff::E_EquipStrong & temp_e_equipstrong_list = msg.e_equipstrong_list(i);
		E_EquipStrong_List[i].read_from_pbmsg(temp_e_equipstrong_list);
	}
}

E_EquipStrongexp_s::E_EquipStrongexp_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_EquipStrongexp_s::CreateInit() {
	m_lv = (int32_t)0;
	m_gold = (int32_t)0;
	return 0;
}

int E_EquipStrongexp_s::ResumeInit() {
	return 0;
}

void E_EquipStrongexp_s::write_to_pbmsg(::proto_ff::E_EquipStrongexp & msg) const {
	msg.set_m_lv((int32_t)m_lv);
	msg.set_m_gold((int32_t)m_gold);
	for(int32_t i = 0; i < (int32_t)m_costitem.size(); ++i) {
		msg.add_m_costitem((int32_t)m_costitem[i]);
	}
	for(int32_t i = 0; i < (int32_t)m_positiontype.size(); ++i) {
		msg.add_m_positiontype((const char*)m_positiontype[i].data());
	}
	for(int32_t i = 0; i < (int32_t)m_costnum.size(); ++i) {
		msg.add_m_costnum((int32_t)m_costnum[i]);
	}
}

void E_EquipStrongexp_s::read_from_pbmsg(const ::proto_ff::E_EquipStrongexp & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct E_EquipStrongexp_s));
	m_lv = msg.m_lv();
	m_gold = msg.m_gold();
	m_costitem.resize((int)msg.m_costitem_size() > (int)m_costitem.max_size() ? m_costitem.max_size() : msg.m_costitem_size());
	for(int32_t i = 0; i < (int32_t)m_costitem.size(); ++i) {
		m_costitem[i] = msg.m_costitem(i);
	}
	m_positiontype.resize((int)msg.m_positiontype_size() > (int)m_positiontype.max_size() ? m_positiontype.max_size() : msg.m_positiontype_size());
	for(int32_t i = 0; i < (int32_t)m_positiontype.size(); ++i) {
		m_positiontype[i] = msg.m_positiontype(i);
	}
	m_costnum.resize((int)msg.m_costnum_size() > (int)m_costnum.max_size() ? m_costnum.max_size() : msg.m_costnum_size());
	for(int32_t i = 0; i < (int32_t)m_costnum.size(); ++i) {
		m_costnum[i] = msg.m_costnum(i);
	}
}

Sheet_EquipStrongexp_s::Sheet_EquipStrongexp_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_EquipStrongexp_s::CreateInit() {
	return 0;
}

int Sheet_EquipStrongexp_s::ResumeInit() {
	return 0;
}

void Sheet_EquipStrongexp_s::write_to_pbmsg(::proto_ff::Sheet_EquipStrongexp & msg) const {
	for(int32_t i = 0; i < (int32_t)E_EquipStrongexp_List.size(); ++i) {
		::proto_ff::E_EquipStrongexp* temp_e_equipstrongexp_list = msg.add_e_equipstrongexp_list();
		E_EquipStrongexp_List[i].write_to_pbmsg(*temp_e_equipstrongexp_list);
	}
}

void Sheet_EquipStrongexp_s::read_from_pbmsg(const ::proto_ff::Sheet_EquipStrongexp & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_EquipStrongexp_s));
	E_EquipStrongexp_List.resize((int)msg.e_equipstrongexp_list_size() > (int)E_EquipStrongexp_List.max_size() ? E_EquipStrongexp_List.max_size() : msg.e_equipstrongexp_list_size());
	for(int32_t i = 0; i < (int32_t)E_EquipStrongexp_List.size(); ++i) {
		const ::proto_ff::E_EquipStrongexp & temp_e_equipstrongexp_list = msg.e_equipstrongexp_list(i);
		E_EquipStrongexp_List[i].read_from_pbmsg(temp_e_equipstrongexp_list);
	}
}

E_EquipStrongtotalAttributeDesc_s::E_EquipStrongtotalAttributeDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_EquipStrongtotalAttributeDesc_s::CreateInit() {
	m_type = (int32_t)0;
	m_value = (int32_t)0;
	return 0;
}

int E_EquipStrongtotalAttributeDesc_s::ResumeInit() {
	return 0;
}

void E_EquipStrongtotalAttributeDesc_s::write_to_pbmsg(::proto_ff::E_EquipStrongtotalAttributeDesc & msg) const {
	msg.set_m_type((int32_t)m_type);
	msg.set_m_value((int32_t)m_value);
}

void E_EquipStrongtotalAttributeDesc_s::read_from_pbmsg(const ::proto_ff::E_EquipStrongtotalAttributeDesc & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct E_EquipStrongtotalAttributeDesc_s));
	m_type = msg.m_type();
	m_value = msg.m_value();
}

E_EquipStrongtotal_s::E_EquipStrongtotal_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_EquipStrongtotal_s::CreateInit() {
	m_id = (int64_t)0;
	m_idtype = (int32_t)0;
	m_idnum = (int32_t)0;
	return 0;
}

int E_EquipStrongtotal_s::ResumeInit() {
	return 0;
}

void E_EquipStrongtotal_s::write_to_pbmsg(::proto_ff::E_EquipStrongtotal & msg) const {
	msg.set_m_id((int64_t)m_id);
	msg.set_m_idtype((int32_t)m_idtype);
	msg.set_m_idnum((int32_t)m_idnum);
	for(int32_t i = 0; i < (int32_t)m_attribute.size(); ++i) {
		::proto_ff::E_EquipStrongtotalAttributeDesc* temp_m_attribute = msg.add_m_attribute();
		m_attribute[i].write_to_pbmsg(*temp_m_attribute);
	}
}

void E_EquipStrongtotal_s::read_from_pbmsg(const ::proto_ff::E_EquipStrongtotal & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct E_EquipStrongtotal_s));
	m_id = msg.m_id();
	m_idtype = msg.m_idtype();
	m_idnum = msg.m_idnum();
	m_attribute.resize((int)msg.m_attribute_size() > (int)m_attribute.max_size() ? m_attribute.max_size() : msg.m_attribute_size());
	for(int32_t i = 0; i < (int32_t)m_attribute.size(); ++i) {
		const ::proto_ff::E_EquipStrongtotalAttributeDesc & temp_m_attribute = msg.m_attribute(i);
		m_attribute[i].read_from_pbmsg(temp_m_attribute);
	}
}

Sheet_EquipStrongtotal_s::Sheet_EquipStrongtotal_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_EquipStrongtotal_s::CreateInit() {
	return 0;
}

int Sheet_EquipStrongtotal_s::ResumeInit() {
	return 0;
}

void Sheet_EquipStrongtotal_s::write_to_pbmsg(::proto_ff::Sheet_EquipStrongtotal & msg) const {
	for(int32_t i = 0; i < (int32_t)E_EquipStrongtotal_List.size(); ++i) {
		::proto_ff::E_EquipStrongtotal* temp_e_equipstrongtotal_list = msg.add_e_equipstrongtotal_list();
		E_EquipStrongtotal_List[i].write_to_pbmsg(*temp_e_equipstrongtotal_list);
	}
}

void Sheet_EquipStrongtotal_s::read_from_pbmsg(const ::proto_ff::Sheet_EquipStrongtotal & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_EquipStrongtotal_s));
	E_EquipStrongtotal_List.resize((int)msg.e_equipstrongtotal_list_size() > (int)E_EquipStrongtotal_List.max_size() ? E_EquipStrongtotal_List.max_size() : msg.e_equipstrongtotal_list_size());
	for(int32_t i = 0; i < (int32_t)E_EquipStrongtotal_List.size(); ++i) {
		const ::proto_ff::E_EquipStrongtotal & temp_e_equipstrongtotal_list = msg.e_equipstrongtotal_list(i);
		E_EquipStrongtotal_List[i].read_from_pbmsg(temp_e_equipstrongtotal_list);
	}
}

E_EquipGem_s::E_EquipGem_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_EquipGem_s::CreateInit() {
	m_position = (int32_t)0;
	m_speciallygemtype = (int32_t)0;
	m_payunlockitem = (int32_t)0;
	m_payunlocknnm = (int32_t)0;
	return 0;
}

int E_EquipGem_s::ResumeInit() {
	return 0;
}

void E_EquipGem_s::write_to_pbmsg(::proto_ff::E_EquipGem & msg) const {
	msg.set_m_position((int32_t)m_position);
	msg.set_m_gemtype((const char*)m_gemtype.data());
	msg.set_m_speciallygemtype((int32_t)m_speciallygemtype);
	msg.set_m_payunlockitem((int32_t)m_payunlockitem);
	msg.set_m_payunlocknnm((int32_t)m_payunlocknnm);
	for(int32_t i = 0; i < (int32_t)m_gemunlock.size(); ++i) {
		msg.add_m_gemunlock((int32_t)m_gemunlock[i]);
	}
}

void E_EquipGem_s::read_from_pbmsg(const ::proto_ff::E_EquipGem & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct E_EquipGem_s));
	m_position = msg.m_position();
	m_gemtype = msg.m_gemtype();
	m_speciallygemtype = msg.m_speciallygemtype();
	m_payunlockitem = msg.m_payunlockitem();
	m_payunlocknnm = msg.m_payunlocknnm();
	m_gemunlock.resize((int)msg.m_gemunlock_size() > (int)m_gemunlock.max_size() ? m_gemunlock.max_size() : msg.m_gemunlock_size());
	for(int32_t i = 0; i < (int32_t)m_gemunlock.size(); ++i) {
		m_gemunlock[i] = msg.m_gemunlock(i);
	}
}

Sheet_EquipGem_s::Sheet_EquipGem_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_EquipGem_s::CreateInit() {
	return 0;
}

int Sheet_EquipGem_s::ResumeInit() {
	return 0;
}

void Sheet_EquipGem_s::write_to_pbmsg(::proto_ff::Sheet_EquipGem & msg) const {
	for(int32_t i = 0; i < (int32_t)E_EquipGem_List.size(); ++i) {
		::proto_ff::E_EquipGem* temp_e_equipgem_list = msg.add_e_equipgem_list();
		E_EquipGem_List[i].write_to_pbmsg(*temp_e_equipgem_list);
	}
}

void Sheet_EquipGem_s::read_from_pbmsg(const ::proto_ff::Sheet_EquipGem & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_EquipGem_s));
	E_EquipGem_List.resize((int)msg.e_equipgem_list_size() > (int)E_EquipGem_List.max_size() ? E_EquipGem_List.max_size() : msg.e_equipgem_list_size());
	for(int32_t i = 0; i < (int32_t)E_EquipGem_List.size(); ++i) {
		const ::proto_ff::E_EquipGem & temp_e_equipgem_list = msg.e_equipgem_list(i);
		E_EquipGem_List[i].read_from_pbmsg(temp_e_equipgem_list);
	}
}

E_EquipStoveattAttributeDesc_s::E_EquipStoveattAttributeDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_EquipStoveattAttributeDesc_s::CreateInit() {
	m_type = (int32_t)0;
	m_value = (int32_t)0;
	return 0;
}

int E_EquipStoveattAttributeDesc_s::ResumeInit() {
	return 0;
}

void E_EquipStoveattAttributeDesc_s::write_to_pbmsg(::proto_ff::E_EquipStoveattAttributeDesc & msg) const {
	msg.set_m_type((int32_t)m_type);
	msg.set_m_value((int32_t)m_value);
}

void E_EquipStoveattAttributeDesc_s::read_from_pbmsg(const ::proto_ff::E_EquipStoveattAttributeDesc & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct E_EquipStoveattAttributeDesc_s));
	m_type = msg.m_type();
	m_value = msg.m_value();
}

E_EquipStoveatt_s::E_EquipStoveatt_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_EquipStoveatt_s::CreateInit() {
	m_lv = (int32_t)0;
	m_exp = (int64_t)0;
	return 0;
}

int E_EquipStoveatt_s::ResumeInit() {
	return 0;
}

void E_EquipStoveatt_s::write_to_pbmsg(::proto_ff::E_EquipStoveatt & msg) const {
	msg.set_m_lv((int32_t)m_lv);
	msg.set_m_exp((int64_t)m_exp);
	for(int32_t i = 0; i < (int32_t)m_attribute.size(); ++i) {
		::proto_ff::E_EquipStoveattAttributeDesc* temp_m_attribute = msg.add_m_attribute();
		m_attribute[i].write_to_pbmsg(*temp_m_attribute);
	}
}

void E_EquipStoveatt_s::read_from_pbmsg(const ::proto_ff::E_EquipStoveatt & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct E_EquipStoveatt_s));
	m_lv = msg.m_lv();
	m_exp = msg.m_exp();
	m_attribute.resize((int)msg.m_attribute_size() > (int)m_attribute.max_size() ? m_attribute.max_size() : msg.m_attribute_size());
	for(int32_t i = 0; i < (int32_t)m_attribute.size(); ++i) {
		const ::proto_ff::E_EquipStoveattAttributeDesc & temp_m_attribute = msg.m_attribute(i);
		m_attribute[i].read_from_pbmsg(temp_m_attribute);
	}
}

Sheet_EquipStoveatt_s::Sheet_EquipStoveatt_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_EquipStoveatt_s::CreateInit() {
	return 0;
}

int Sheet_EquipStoveatt_s::ResumeInit() {
	return 0;
}

void Sheet_EquipStoveatt_s::write_to_pbmsg(::proto_ff::Sheet_EquipStoveatt & msg) const {
	for(int32_t i = 0; i < (int32_t)E_EquipStoveatt_List.size(); ++i) {
		::proto_ff::E_EquipStoveatt* temp_e_equipstoveatt_list = msg.add_e_equipstoveatt_list();
		E_EquipStoveatt_List[i].write_to_pbmsg(*temp_e_equipstoveatt_list);
	}
}

void Sheet_EquipStoveatt_s::read_from_pbmsg(const ::proto_ff::Sheet_EquipStoveatt & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_EquipStoveatt_s));
	E_EquipStoveatt_List.resize((int)msg.e_equipstoveatt_list_size() > (int)E_EquipStoveatt_List.max_size() ? E_EquipStoveatt_List.max_size() : msg.e_equipstoveatt_list_size());
	for(int32_t i = 0; i < (int32_t)E_EquipStoveatt_List.size(); ++i) {
		const ::proto_ff::E_EquipStoveatt & temp_e_equipstoveatt_list = msg.e_equipstoveatt_list(i);
		E_EquipStoveatt_List[i].read_from_pbmsg(temp_e_equipstoveatt_list);
	}
}

E_EquipStoveexp_s::E_EquipStoveexp_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_EquipStoveexp_s::CreateInit() {
	m_id = (int32_t)0;
	m_exp = (int32_t)0;
	m_wearquality = (int32_t)0;
	m_quality = (int32_t)0;
	return 0;
}

int E_EquipStoveexp_s::ResumeInit() {
	return 0;
}

void E_EquipStoveexp_s::write_to_pbmsg(::proto_ff::E_EquipStoveexp & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_exp((int32_t)m_exp);
	msg.set_m_wearquality((int32_t)m_wearquality);
	msg.set_m_quality((int32_t)m_quality);
}

void E_EquipStoveexp_s::read_from_pbmsg(const ::proto_ff::E_EquipStoveexp & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct E_EquipStoveexp_s));
	m_id = msg.m_id();
	m_exp = msg.m_exp();
	m_wearquality = msg.m_wearquality();
	m_quality = msg.m_quality();
}

Sheet_EquipStoveexp_s::Sheet_EquipStoveexp_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_EquipStoveexp_s::CreateInit() {
	return 0;
}

int Sheet_EquipStoveexp_s::ResumeInit() {
	return 0;
}

void Sheet_EquipStoveexp_s::write_to_pbmsg(::proto_ff::Sheet_EquipStoveexp & msg) const {
	for(int32_t i = 0; i < (int32_t)E_EquipStoveexp_List.size(); ++i) {
		::proto_ff::E_EquipStoveexp* temp_e_equipstoveexp_list = msg.add_e_equipstoveexp_list();
		E_EquipStoveexp_List[i].write_to_pbmsg(*temp_e_equipstoveexp_list);
	}
}

void Sheet_EquipStoveexp_s::read_from_pbmsg(const ::proto_ff::Sheet_EquipStoveexp & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_EquipStoveexp_s));
	E_EquipStoveexp_List.resize((int)msg.e_equipstoveexp_list_size() > (int)E_EquipStoveexp_List.max_size() ? E_EquipStoveexp_List.max_size() : msg.e_equipstoveexp_list_size());
	for(int32_t i = 0; i < (int32_t)E_EquipStoveexp_List.size(); ++i) {
		const ::proto_ff::E_EquipStoveexp & temp_e_equipstoveexp_list = msg.e_equipstoveexp_list(i);
		E_EquipStoveexp_List[i].read_from_pbmsg(temp_e_equipstoveexp_list);
	}
}

E_EquipGrade_s::E_EquipGrade_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_EquipGrade_s::CreateInit() {
	m_id = (int32_t)0;
	return 0;
}

int E_EquipGrade_s::ResumeInit() {
	return 0;
}

void E_EquipGrade_s::write_to_pbmsg(::proto_ff::E_EquipGrade & msg) const {
	msg.set_m_id((int32_t)m_id);
}

void E_EquipGrade_s::read_from_pbmsg(const ::proto_ff::E_EquipGrade & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct E_EquipGrade_s));
	m_id = msg.m_id();
}

Sheet_EquipGrade_s::Sheet_EquipGrade_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_EquipGrade_s::CreateInit() {
	return 0;
}

int Sheet_EquipGrade_s::ResumeInit() {
	return 0;
}

void Sheet_EquipGrade_s::write_to_pbmsg(::proto_ff::Sheet_EquipGrade & msg) const {
	for(int32_t i = 0; i < (int32_t)E_EquipGrade_List.size(); ++i) {
		::proto_ff::E_EquipGrade* temp_e_equipgrade_list = msg.add_e_equipgrade_list();
		E_EquipGrade_List[i].write_to_pbmsg(*temp_e_equipgrade_list);
	}
}

void Sheet_EquipGrade_s::read_from_pbmsg(const ::proto_ff::Sheet_EquipGrade & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_EquipGrade_s));
	E_EquipGrade_List.resize((int)msg.e_equipgrade_list_size() > (int)E_EquipGrade_List.max_size() ? E_EquipGrade_List.max_size() : msg.e_equipgrade_list_size());
	for(int32_t i = 0; i < (int32_t)E_EquipGrade_List.size(); ++i) {
		const ::proto_ff::E_EquipGrade & temp_e_equipgrade_list = msg.e_equipgrade_list(i);
		E_EquipGrade_List[i].read_from_pbmsg(temp_e_equipgrade_list);
	}
}

}