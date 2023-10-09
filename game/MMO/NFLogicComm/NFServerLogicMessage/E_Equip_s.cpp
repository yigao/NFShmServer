#include "E_Equip_s.h"

namespace proto_ff_s {

E_EquipEquip_s::E_EquipEquip_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_EquipEquip_s::CreateInit() {
	m_id = (int64_t)0;
	m_type = (int32_t)0;
	m_wearquality = (int32_t)0;
	m_position = (int32_t)0;
	m_professionlv = (int32_t)0;
	m_level = (int32_t)0;
	m_quality = (int32_t)0;
	m_attributeid = (int32_t)0;
	m_star = (int32_t)0;
	m_notcompose = (int32_t)0;
	m_iscanbind = (int32_t)0;
	m_istradebind = (int32_t)0;
	m_sellprice = (int32_t)0;
	m_time = (int32_t)0;
	m_broadcast = (int32_t)0;
	m_privilegegroupid = (int32_t)0;
	return 0;
}

int E_EquipEquip_s::ResumeInit() {
	return 0;
}

void E_EquipEquip_s::write_to_pbmsg(::proto_ff::E_EquipEquip & msg) const {
	msg.set_m_id((int64_t)m_id);
	msg.set_m_name(m_name.data());
	msg.set_m_type((int32_t)m_type);
	msg.set_m_wearquality((int32_t)m_wearquality);
	msg.set_m_position((int32_t)m_position);
	msg.set_m_profession(m_profession.data());
	msg.set_m_professionlv((int32_t)m_professionlv);
	msg.set_m_level((int32_t)m_level);
	msg.set_m_quality((int32_t)m_quality);
	msg.set_m_attributeid((int32_t)m_attributeid);
	msg.set_m_star((int32_t)m_star);
	msg.set_m_notcompose((int32_t)m_notcompose);
	msg.set_m_iscanbind((int32_t)m_iscanbind);
	msg.set_m_istradebind((int32_t)m_istradebind);
	msg.set_m_sellprice((int32_t)m_sellprice);
	msg.set_m_icon(m_icon.data());
	msg.set_m_time((int32_t)m_time);
	msg.set_m_broadcast((int32_t)m_broadcast);
	msg.set_m_meltingresult(m_meltingresult.data());
	msg.set_m_skillid(m_skillid.data());
	msg.set_m_privilegegroupid((int32_t)m_privilegegroupid);
}

void E_EquipEquip_s::read_from_pbmsg(const ::proto_ff::E_EquipEquip & msg) {
	m_id = msg.m_id();
	m_name = msg.m_name();
	m_type = msg.m_type();
	m_wearquality = msg.m_wearquality();
	m_position = msg.m_position();
	m_profession = msg.m_profession();
	m_professionlv = msg.m_professionlv();
	m_level = msg.m_level();
	m_quality = msg.m_quality();
	m_attributeid = msg.m_attributeid();
	m_star = msg.m_star();
	m_notcompose = msg.m_notcompose();
	m_iscanbind = msg.m_iscanbind();
	m_istradebind = msg.m_istradebind();
	m_sellprice = msg.m_sellprice();
	m_icon = msg.m_icon();
	m_time = msg.m_time();
	m_broadcast = msg.m_broadcast();
	m_meltingresult = msg.m_meltingresult();
	m_skillid = msg.m_skillid();
	m_privilegegroupid = msg.m_privilegegroupid();
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
	E_EquipEquip_List.resize((int)msg.e_equipequip_list_size() > (int)E_EquipEquip_List.max_size() ? E_EquipEquip_List.max_size() : msg.e_equipequip_list_size());
	for(int32_t i = 0; i < (int32_t)E_EquipEquip_List.size(); ++i) {
		const ::proto_ff::E_EquipEquip & temp_e_equipequip_list = msg.e_equipequip_list(i);
		E_EquipEquip_List[i].read_from_pbmsg(temp_e_equipequip_list);
	}
}

E_EquipAttributeAttributeDesc_s::E_EquipAttributeAttributeDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_EquipAttributeAttributeDesc_s::CreateInit() {
	m_valuemax = (int32_t)0;
	m_valuemin = (int32_t)0;
	m_type = (int32_t)0;
	return 0;
}

int E_EquipAttributeAttributeDesc_s::ResumeInit() {
	return 0;
}

void E_EquipAttributeAttributeDesc_s::write_to_pbmsg(::proto_ff::E_EquipAttributeAttributeDesc & msg) const {
	msg.set_m_valuemax((int32_t)m_valuemax);
	msg.set_m_valuemin((int32_t)m_valuemin);
	msg.set_m_type((int32_t)m_type);
}

void E_EquipAttributeAttributeDesc_s::read_from_pbmsg(const ::proto_ff::E_EquipAttributeAttributeDesc & msg) {
	m_valuemax = msg.m_valuemax();
	m_valuemin = msg.m_valuemin();
	m_type = msg.m_type();
}

E_EquipAttribute_s::E_EquipAttribute_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_EquipAttribute_s::CreateInit() {
	m_id = (int32_t)0;
	m_bluestarnum = (int32_t)0;
	m_specid = (int32_t)0;
	m_specialattributedown = (int32_t)0;
	m_specialattributeup = (int32_t)0;
	return 0;
}

int E_EquipAttribute_s::ResumeInit() {
	return 0;
}

void E_EquipAttribute_s::write_to_pbmsg(::proto_ff::E_EquipAttribute & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_bluestarnum((int32_t)m_bluestarnum);
	msg.set_m_bluestar_type(m_bluestar_type.data());
	msg.set_m_bluestar_lv(m_bluestar_lv.data());
	msg.set_m_bluestar_number(m_bluestar_number.data());
	msg.set_m_specid((int32_t)m_specid);
	msg.set_m_specialattributedown((int32_t)m_specialattributedown);
	msg.set_m_specialattributeup((int32_t)m_specialattributeup);
	msg.set_m_specialattribute_typelibrary(m_specialattribute_typelibrary.data());
	msg.set_m_specialattribute_valuemin(m_specialattribute_valuemin.data());
	msg.set_m_specialattribute_valuemax(m_specialattribute_valuemax.data());
	msg.set_m_godattribute_type(m_godattribute_type.data());
	msg.set_m_godattribute_valuemin(m_godattribute_valuemin.data());
	msg.set_m_godattribute_valuemax(m_godattribute_valuemax.data());
	msg.set_m_silverstarlib(m_silverstarlib.data());
	msg.set_m_silverstarvalue(m_silverstarvalue.data());
	msg.set_m_goldstarlib(m_goldstarlib.data());
	msg.set_m_goldstarvalue(m_goldstarvalue.data());
	msg.set_m_godeviatt(m_godeviatt.data());
	msg.set_m_godeviattvalue(m_godeviattvalue.data());
	msg.set_m_godevilskill(m_godevilskill.data());
	for(int32_t i = 0; i < (int32_t)m_attribute.size(); ++i) {
		::proto_ff::E_EquipAttributeAttributeDesc* temp_m_attribute = msg.add_m_attribute();
		m_attribute[i].write_to_pbmsg(*temp_m_attribute);
	}
	for(int32_t i = 0; i < (int32_t)m_star_library.size(); ++i) {
		msg.add_m_star_library(m_star_library[i].data());
	}
	for(int32_t i = 0; i < (int32_t)m_beaststarlib.size(); ++i) {
		msg.add_m_beaststarlib(m_beaststarlib[i].data());
	}
}

void E_EquipAttribute_s::read_from_pbmsg(const ::proto_ff::E_EquipAttribute & msg) {
	m_id = msg.m_id();
	m_bluestarnum = msg.m_bluestarnum();
	m_bluestar_type = msg.m_bluestar_type();
	m_bluestar_lv = msg.m_bluestar_lv();
	m_bluestar_number = msg.m_bluestar_number();
	m_specid = msg.m_specid();
	m_specialattributedown = msg.m_specialattributedown();
	m_specialattributeup = msg.m_specialattributeup();
	m_specialattribute_typelibrary = msg.m_specialattribute_typelibrary();
	m_specialattribute_valuemin = msg.m_specialattribute_valuemin();
	m_specialattribute_valuemax = msg.m_specialattribute_valuemax();
	m_godattribute_type = msg.m_godattribute_type();
	m_godattribute_valuemin = msg.m_godattribute_valuemin();
	m_godattribute_valuemax = msg.m_godattribute_valuemax();
	m_silverstarlib = msg.m_silverstarlib();
	m_silverstarvalue = msg.m_silverstarvalue();
	m_goldstarlib = msg.m_goldstarlib();
	m_goldstarvalue = msg.m_goldstarvalue();
	m_godeviatt = msg.m_godeviatt();
	m_godeviattvalue = msg.m_godeviattvalue();
	m_godevilskill = msg.m_godevilskill();
	m_attribute.resize((int)msg.m_attribute_size() > (int)m_attribute.max_size() ? m_attribute.max_size() : msg.m_attribute_size());
	for(int32_t i = 0; i < (int32_t)m_attribute.size(); ++i) {
		const ::proto_ff::E_EquipAttributeAttributeDesc & temp_m_attribute = msg.m_attribute(i);
		m_attribute[i].read_from_pbmsg(temp_m_attribute);
	}
	m_star_library.resize((int)msg.m_star_library_size() > (int)m_star_library.max_size() ? m_star_library.max_size() : msg.m_star_library_size());
	for(int32_t i = 0; i < (int32_t)m_star_library.size(); ++i) {
		m_star_library[i] = msg.m_star_library(i);
	}
	m_beaststarlib.resize((int)msg.m_beaststarlib_size() > (int)m_beaststarlib.max_size() ? m_beaststarlib.max_size() : msg.m_beaststarlib_size());
	for(int32_t i = 0; i < (int32_t)m_beaststarlib.size(); ++i) {
		m_beaststarlib[i] = msg.m_beaststarlib(i);
	}
}

Sheet_EquipAttribute_s::Sheet_EquipAttribute_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_EquipAttribute_s::CreateInit() {
	return 0;
}

int Sheet_EquipAttribute_s::ResumeInit() {
	return 0;
}

void Sheet_EquipAttribute_s::write_to_pbmsg(::proto_ff::Sheet_EquipAttribute & msg) const {
	for(int32_t i = 0; i < (int32_t)E_EquipAttribute_List.size(); ++i) {
		::proto_ff::E_EquipAttribute* temp_e_equipattribute_list = msg.add_e_equipattribute_list();
		E_EquipAttribute_List[i].write_to_pbmsg(*temp_e_equipattribute_list);
	}
}

void Sheet_EquipAttribute_s::read_from_pbmsg(const ::proto_ff::Sheet_EquipAttribute & msg) {
	E_EquipAttribute_List.resize((int)msg.e_equipattribute_list_size() > (int)E_EquipAttribute_List.max_size() ? E_EquipAttribute_List.max_size() : msg.e_equipattribute_list_size());
	for(int32_t i = 0; i < (int32_t)E_EquipAttribute_List.size(); ++i) {
		const ::proto_ff::E_EquipAttribute & temp_e_equipattribute_list = msg.e_equipattribute_list(i);
		E_EquipAttribute_List[i].read_from_pbmsg(temp_e_equipattribute_list);
	}
}

E_EquipSpecattAttributeDesc_s::E_EquipSpecattAttributeDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_EquipSpecattAttributeDesc_s::CreateInit() {
	m_value = (int32_t)0;
	m_type = (int32_t)0;
	return 0;
}

int E_EquipSpecattAttributeDesc_s::ResumeInit() {
	return 0;
}

void E_EquipSpecattAttributeDesc_s::write_to_pbmsg(::proto_ff::E_EquipSpecattAttributeDesc & msg) const {
	msg.set_m_value((int32_t)m_value);
	msg.set_m_type((int32_t)m_type);
}

void E_EquipSpecattAttributeDesc_s::read_from_pbmsg(const ::proto_ff::E_EquipSpecattAttributeDesc & msg) {
	m_value = msg.m_value();
	m_type = msg.m_type();
}

E_EquipSpecatt_s::E_EquipSpecatt_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_EquipSpecatt_s::CreateInit() {
	m_id = (int32_t)0;
	m_groupid = (int32_t)0;
	m_lv = (int32_t)0;
	return 0;
}

int E_EquipSpecatt_s::ResumeInit() {
	return 0;
}

void E_EquipSpecatt_s::write_to_pbmsg(::proto_ff::E_EquipSpecatt & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_groupid((int32_t)m_groupid);
	msg.set_m_lv((int32_t)m_lv);
	msg.set_m_zlname(m_zlname.data());
	for(int32_t i = 0; i < (int32_t)m_attribute.size(); ++i) {
		::proto_ff::E_EquipSpecattAttributeDesc* temp_m_attribute = msg.add_m_attribute();
		m_attribute[i].write_to_pbmsg(*temp_m_attribute);
	}
}

void E_EquipSpecatt_s::read_from_pbmsg(const ::proto_ff::E_EquipSpecatt & msg) {
	m_id = msg.m_id();
	m_groupid = msg.m_groupid();
	m_lv = msg.m_lv();
	m_zlname = msg.m_zlname();
	m_attribute.resize((int)msg.m_attribute_size() > (int)m_attribute.max_size() ? m_attribute.max_size() : msg.m_attribute_size());
	for(int32_t i = 0; i < (int32_t)m_attribute.size(); ++i) {
		const ::proto_ff::E_EquipSpecattAttributeDesc & temp_m_attribute = msg.m_attribute(i);
		m_attribute[i].read_from_pbmsg(temp_m_attribute);
	}
}

Sheet_EquipSpecatt_s::Sheet_EquipSpecatt_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_EquipSpecatt_s::CreateInit() {
	return 0;
}

int Sheet_EquipSpecatt_s::ResumeInit() {
	return 0;
}

void Sheet_EquipSpecatt_s::write_to_pbmsg(::proto_ff::Sheet_EquipSpecatt & msg) const {
	for(int32_t i = 0; i < (int32_t)E_EquipSpecatt_List.size(); ++i) {
		::proto_ff::E_EquipSpecatt* temp_e_equipspecatt_list = msg.add_e_equipspecatt_list();
		E_EquipSpecatt_List[i].write_to_pbmsg(*temp_e_equipspecatt_list);
	}
}

void Sheet_EquipSpecatt_s::read_from_pbmsg(const ::proto_ff::Sheet_EquipSpecatt & msg) {
	E_EquipSpecatt_List.resize((int)msg.e_equipspecatt_list_size() > (int)E_EquipSpecatt_List.max_size() ? E_EquipSpecatt_List.max_size() : msg.e_equipspecatt_list_size());
	for(int32_t i = 0; i < (int32_t)E_EquipSpecatt_List.size(); ++i) {
		const ::proto_ff::E_EquipSpecatt & temp_e_equipspecatt_list = msg.e_equipspecatt_list(i);
		E_EquipSpecatt_List[i].read_from_pbmsg(temp_e_equipspecatt_list);
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
	msg.set_m_num(m_num.data());
	msg.set_m_id((int32_t)m_id);
}

void E_EquipStrongTypeDesc_s::read_from_pbmsg(const ::proto_ff::E_EquipStrongTypeDesc & msg) {
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
	E_EquipStrong_List.resize((int)msg.e_equipstrong_list_size() > (int)E_EquipStrong_List.max_size() ? E_EquipStrong_List.max_size() : msg.e_equipstrong_list_size());
	for(int32_t i = 0; i < (int32_t)E_EquipStrong_List.size(); ++i) {
		const ::proto_ff::E_EquipStrong & temp_e_equipstrong_list = msg.e_equipstrong_list(i);
		E_EquipStrong_List[i].read_from_pbmsg(temp_e_equipstrong_list);
	}
}

E_EquipStrongexpCostDesc_s::E_EquipStrongexpCostDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_EquipStrongexpCostDesc_s::CreateInit() {
	m_num = (int32_t)0;
	m_item = (int32_t)0;
	return 0;
}

int E_EquipStrongexpCostDesc_s::ResumeInit() {
	return 0;
}

void E_EquipStrongexpCostDesc_s::write_to_pbmsg(::proto_ff::E_EquipStrongexpCostDesc & msg) const {
	msg.set_m_num((int32_t)m_num);
	msg.set_m_item((int32_t)m_item);
}

void E_EquipStrongexpCostDesc_s::read_from_pbmsg(const ::proto_ff::E_EquipStrongexpCostDesc & msg) {
	m_num = msg.m_num();
	m_item = msg.m_item();
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
	for(int32_t i = 0; i < (int32_t)m_positiontype.size(); ++i) {
		msg.add_m_positiontype(m_positiontype[i].data());
	}
	for(int32_t i = 0; i < (int32_t)m_cost.size(); ++i) {
		::proto_ff::E_EquipStrongexpCostDesc* temp_m_cost = msg.add_m_cost();
		m_cost[i].write_to_pbmsg(*temp_m_cost);
	}
}

void E_EquipStrongexp_s::read_from_pbmsg(const ::proto_ff::E_EquipStrongexp & msg) {
	m_lv = msg.m_lv();
	m_gold = msg.m_gold();
	m_positiontype.resize((int)msg.m_positiontype_size() > (int)m_positiontype.max_size() ? m_positiontype.max_size() : msg.m_positiontype_size());
	for(int32_t i = 0; i < (int32_t)m_positiontype.size(); ++i) {
		m_positiontype[i] = msg.m_positiontype(i);
	}
	m_cost.resize((int)msg.m_cost_size() > (int)m_cost.max_size() ? m_cost.max_size() : msg.m_cost_size());
	for(int32_t i = 0; i < (int32_t)m_cost.size(); ++i) {
		const ::proto_ff::E_EquipStrongexpCostDesc & temp_m_cost = msg.m_cost(i);
		m_cost[i].read_from_pbmsg(temp_m_cost);
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
	E_EquipStrongexp_List.resize((int)msg.e_equipstrongexp_list_size() > (int)E_EquipStrongexp_List.max_size() ? E_EquipStrongexp_List.max_size() : msg.e_equipstrongexp_list_size());
	for(int32_t i = 0; i < (int32_t)E_EquipStrongexp_List.size(); ++i) {
		const ::proto_ff::E_EquipStrongexp & temp_e_equipstrongexp_list = msg.e_equipstrongexp_list(i);
		E_EquipStrongexp_List[i].read_from_pbmsg(temp_e_equipstrongexp_list);
	}
}

E_EquipBeaststrongTypeDesc_s::E_EquipBeaststrongTypeDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_EquipBeaststrongTypeDesc_s::CreateInit() {
	m_id = (int32_t)0;
	return 0;
}

int E_EquipBeaststrongTypeDesc_s::ResumeInit() {
	return 0;
}

void E_EquipBeaststrongTypeDesc_s::write_to_pbmsg(::proto_ff::E_EquipBeaststrongTypeDesc & msg) const {
	msg.set_m_num(m_num.data());
	msg.set_m_id((int32_t)m_id);
}

void E_EquipBeaststrongTypeDesc_s::read_from_pbmsg(const ::proto_ff::E_EquipBeaststrongTypeDesc & msg) {
	m_num = msg.m_num();
	m_id = msg.m_id();
}

E_EquipBeaststrong_s::E_EquipBeaststrong_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_EquipBeaststrong_s::CreateInit() {
	m_id = (int64_t)0;
	m_position = (int32_t)0;
	m_wearquality = (int32_t)0;
	m_srtongup = (int32_t)0;
	return 0;
}

int E_EquipBeaststrong_s::ResumeInit() {
	return 0;
}

void E_EquipBeaststrong_s::write_to_pbmsg(::proto_ff::E_EquipBeaststrong & msg) const {
	msg.set_m_id((int64_t)m_id);
	msg.set_m_position((int32_t)m_position);
	msg.set_m_wearquality((int32_t)m_wearquality);
	msg.set_m_srtongup((int32_t)m_srtongup);
	for(int32_t i = 0; i < (int32_t)m_type.size(); ++i) {
		::proto_ff::E_EquipBeaststrongTypeDesc* temp_m_type = msg.add_m_type();
		m_type[i].write_to_pbmsg(*temp_m_type);
	}
}

void E_EquipBeaststrong_s::read_from_pbmsg(const ::proto_ff::E_EquipBeaststrong & msg) {
	m_id = msg.m_id();
	m_position = msg.m_position();
	m_wearquality = msg.m_wearquality();
	m_srtongup = msg.m_srtongup();
	m_type.resize((int)msg.m_type_size() > (int)m_type.max_size() ? m_type.max_size() : msg.m_type_size());
	for(int32_t i = 0; i < (int32_t)m_type.size(); ++i) {
		const ::proto_ff::E_EquipBeaststrongTypeDesc & temp_m_type = msg.m_type(i);
		m_type[i].read_from_pbmsg(temp_m_type);
	}
}

Sheet_EquipBeaststrong_s::Sheet_EquipBeaststrong_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_EquipBeaststrong_s::CreateInit() {
	return 0;
}

int Sheet_EquipBeaststrong_s::ResumeInit() {
	return 0;
}

void Sheet_EquipBeaststrong_s::write_to_pbmsg(::proto_ff::Sheet_EquipBeaststrong & msg) const {
	for(int32_t i = 0; i < (int32_t)E_EquipBeaststrong_List.size(); ++i) {
		::proto_ff::E_EquipBeaststrong* temp_e_equipbeaststrong_list = msg.add_e_equipbeaststrong_list();
		E_EquipBeaststrong_List[i].write_to_pbmsg(*temp_e_equipbeaststrong_list);
	}
}

void Sheet_EquipBeaststrong_s::read_from_pbmsg(const ::proto_ff::Sheet_EquipBeaststrong & msg) {
	E_EquipBeaststrong_List.resize((int)msg.e_equipbeaststrong_list_size() > (int)E_EquipBeaststrong_List.max_size() ? E_EquipBeaststrong_List.max_size() : msg.e_equipbeaststrong_list_size());
	for(int32_t i = 0; i < (int32_t)E_EquipBeaststrong_List.size(); ++i) {
		const ::proto_ff::E_EquipBeaststrong & temp_e_equipbeaststrong_list = msg.e_equipbeaststrong_list(i);
		E_EquipBeaststrong_List[i].read_from_pbmsg(temp_e_equipbeaststrong_list);
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
	m_value = (int32_t)0;
	m_type = (int32_t)0;
	return 0;
}

int E_EquipStrongtotalAttributeDesc_s::ResumeInit() {
	return 0;
}

void E_EquipStrongtotalAttributeDesc_s::write_to_pbmsg(::proto_ff::E_EquipStrongtotalAttributeDesc & msg) const {
	msg.set_m_value((int32_t)m_value);
	msg.set_m_type((int32_t)m_type);
}

void E_EquipStrongtotalAttributeDesc_s::read_from_pbmsg(const ::proto_ff::E_EquipStrongtotalAttributeDesc & msg) {
	m_value = msg.m_value();
	m_type = msg.m_type();
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
	msg.set_m_gemtype(m_gemtype.data());
	msg.set_m_speciallygemtype((int32_t)m_speciallygemtype);
	msg.set_m_payunlockitem((int32_t)m_payunlockitem);
	msg.set_m_payunlocknnm((int32_t)m_payunlocknnm);
	msg.set_m_commongembuy(m_commongembuy.data());
	msg.set_m_speciallygembuy(m_speciallygembuy.data());
	for(int32_t i = 0; i < (int32_t)m_gemunlock.size(); ++i) {
		msg.add_m_gemunlock((int32_t)m_gemunlock[i]);
	}
}

void E_EquipGem_s::read_from_pbmsg(const ::proto_ff::E_EquipGem & msg) {
	m_position = msg.m_position();
	m_gemtype = msg.m_gemtype();
	m_speciallygemtype = msg.m_speciallygemtype();
	m_payunlockitem = msg.m_payunlockitem();
	m_payunlocknnm = msg.m_payunlocknnm();
	m_commongembuy = msg.m_commongembuy();
	m_speciallygembuy = msg.m_speciallygembuy();
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
	E_EquipGem_List.resize((int)msg.e_equipgem_list_size() > (int)E_EquipGem_List.max_size() ? E_EquipGem_List.max_size() : msg.e_equipgem_list_size());
	for(int32_t i = 0; i < (int32_t)E_EquipGem_List.size(); ++i) {
		const ::proto_ff::E_EquipGem & temp_e_equipgem_list = msg.e_equipgem_list(i);
		E_EquipGem_List[i].read_from_pbmsg(temp_e_equipgem_list);
	}
}

E_EquipGemlv_s::E_EquipGemlv_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_EquipGemlv_s::CreateInit() {
	m_id = (int32_t)0;
	m_preid = (int32_t)0;
	m_nextid = (int32_t)0;
	m_nextvalue = (int32_t)0;
	m_costgold = (int32_t)0;
	m_mallid = (int32_t)0;
	return 0;
}

int E_EquipGemlv_s::ResumeInit() {
	return 0;
}

void E_EquipGemlv_s::write_to_pbmsg(::proto_ff::E_EquipGemlv & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_preid((int32_t)m_preid);
	msg.set_m_nextid((int32_t)m_nextid);
	msg.set_m_numb(m_numb.data());
	msg.set_m_nextvalue((int32_t)m_nextvalue);
	msg.set_m_costgold((int32_t)m_costgold);
	msg.set_m_mallid((int32_t)m_mallid);
}

void E_EquipGemlv_s::read_from_pbmsg(const ::proto_ff::E_EquipGemlv & msg) {
	m_id = msg.m_id();
	m_preid = msg.m_preid();
	m_nextid = msg.m_nextid();
	m_numb = msg.m_numb();
	m_nextvalue = msg.m_nextvalue();
	m_costgold = msg.m_costgold();
	m_mallid = msg.m_mallid();
}

Sheet_EquipGemlv_s::Sheet_EquipGemlv_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_EquipGemlv_s::CreateInit() {
	return 0;
}

int Sheet_EquipGemlv_s::ResumeInit() {
	return 0;
}

void Sheet_EquipGemlv_s::write_to_pbmsg(::proto_ff::Sheet_EquipGemlv & msg) const {
	for(int32_t i = 0; i < (int32_t)E_EquipGemlv_List.size(); ++i) {
		::proto_ff::E_EquipGemlv* temp_e_equipgemlv_list = msg.add_e_equipgemlv_list();
		E_EquipGemlv_List[i].write_to_pbmsg(*temp_e_equipgemlv_list);
	}
}

void Sheet_EquipGemlv_s::read_from_pbmsg(const ::proto_ff::Sheet_EquipGemlv & msg) {
	E_EquipGemlv_List.resize((int)msg.e_equipgemlv_list_size() > (int)E_EquipGemlv_List.max_size() ? E_EquipGemlv_List.max_size() : msg.e_equipgemlv_list_size());
	for(int32_t i = 0; i < (int32_t)E_EquipGemlv_List.size(); ++i) {
		const ::proto_ff::E_EquipGemlv & temp_e_equipgemlv_list = msg.e_equipgemlv_list(i);
		E_EquipGemlv_List[i].read_from_pbmsg(temp_e_equipgemlv_list);
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
	m_value = (int32_t)0;
	m_type = (int32_t)0;
	return 0;
}

int E_EquipStoveattAttributeDesc_s::ResumeInit() {
	return 0;
}

void E_EquipStoveattAttributeDesc_s::write_to_pbmsg(::proto_ff::E_EquipStoveattAttributeDesc & msg) const {
	msg.set_m_value((int32_t)m_value);
	msg.set_m_type((int32_t)m_type);
}

void E_EquipStoveattAttributeDesc_s::read_from_pbmsg(const ::proto_ff::E_EquipStoveattAttributeDesc & msg) {
	m_value = msg.m_value();
	m_type = msg.m_type();
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
	E_EquipGrade_List.resize((int)msg.e_equipgrade_list_size() > (int)E_EquipGrade_List.max_size() ? E_EquipGrade_List.max_size() : msg.e_equipgrade_list_size());
	for(int32_t i = 0; i < (int32_t)E_EquipGrade_List.size(); ++i) {
		const ::proto_ff::E_EquipGrade & temp_e_equipgrade_list = msg.e_equipgrade_list(i);
		E_EquipGrade_List[i].read_from_pbmsg(temp_e_equipgrade_list);
	}
}

E_EquipClearAttributeDesc_s::E_EquipClearAttributeDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_EquipClearAttributeDesc_s::CreateInit() {
	return 0;
}

int E_EquipClearAttributeDesc_s::ResumeInit() {
	return 0;
}

void E_EquipClearAttributeDesc_s::write_to_pbmsg(::proto_ff::E_EquipClearAttributeDesc & msg) const {
	msg.set_m_value(m_value.data());
}

void E_EquipClearAttributeDesc_s::read_from_pbmsg(const ::proto_ff::E_EquipClearAttributeDesc & msg) {
	m_value = msg.m_value();
}

E_EquipClearSectionDesc_s::E_EquipClearSectionDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_EquipClearSectionDesc_s::CreateInit() {
	m_p = (int32_t)0;
	return 0;
}

int E_EquipClearSectionDesc_s::ResumeInit() {
	return 0;
}

void E_EquipClearSectionDesc_s::write_to_pbmsg(::proto_ff::E_EquipClearSectionDesc & msg) const {
	msg.set_m_up(m_up.data());
	msg.set_m_down(m_down.data());
	msg.set_m_type(m_type.data());
	msg.set_m_g(m_g.data());
	msg.set_m_p((int32_t)m_p);
}

void E_EquipClearSectionDesc_s::read_from_pbmsg(const ::proto_ff::E_EquipClearSectionDesc & msg) {
	m_up = msg.m_up();
	m_down = msg.m_down();
	m_type = msg.m_type();
	m_g = msg.m_g();
	m_p = msg.m_p();
}

E_EquipClear_s::E_EquipClear_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_EquipClear_s::CreateInit() {
	m_id = (int32_t)0;
	m_unlockitem = (int32_t)0;
	m_consumeid = (int64_t)0;
	return 0;
}

int E_EquipClear_s::ResumeInit() {
	return 0;
}

void E_EquipClear_s::write_to_pbmsg(::proto_ff::E_EquipClear & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_value(m_value.data());
	msg.set_m_unlockitem((int32_t)m_unlockitem);
	msg.set_m_unlocknum(m_unlocknum.data());
	msg.set_m_consumeid((int64_t)m_consumeid);
	msg.set_m_consumenum(m_consumenum.data());
	msg.set_m_lockingid(m_lockingid.data());
	msg.set_m_lockingnum(m_lockingnum.data());
	for(int32_t i = 0; i < (int32_t)m_attribute.size(); ++i) {
		::proto_ff::E_EquipClearAttributeDesc* temp_m_attribute = msg.add_m_attribute();
		m_attribute[i].write_to_pbmsg(*temp_m_attribute);
	}
	for(int32_t i = 0; i < (int32_t)m_section.size(); ++i) {
		::proto_ff::E_EquipClearSectionDesc* temp_m_section = msg.add_m_section();
		m_section[i].write_to_pbmsg(*temp_m_section);
	}
}

void E_EquipClear_s::read_from_pbmsg(const ::proto_ff::E_EquipClear & msg) {
	m_id = msg.m_id();
	m_value = msg.m_value();
	m_unlockitem = msg.m_unlockitem();
	m_unlocknum = msg.m_unlocknum();
	m_consumeid = msg.m_consumeid();
	m_consumenum = msg.m_consumenum();
	m_lockingid = msg.m_lockingid();
	m_lockingnum = msg.m_lockingnum();
	m_attribute.resize((int)msg.m_attribute_size() > (int)m_attribute.max_size() ? m_attribute.max_size() : msg.m_attribute_size());
	for(int32_t i = 0; i < (int32_t)m_attribute.size(); ++i) {
		const ::proto_ff::E_EquipClearAttributeDesc & temp_m_attribute = msg.m_attribute(i);
		m_attribute[i].read_from_pbmsg(temp_m_attribute);
	}
	m_section.resize((int)msg.m_section_size() > (int)m_section.max_size() ? m_section.max_size() : msg.m_section_size());
	for(int32_t i = 0; i < (int32_t)m_section.size(); ++i) {
		const ::proto_ff::E_EquipClearSectionDesc & temp_m_section = msg.m_section(i);
		m_section[i].read_from_pbmsg(temp_m_section);
	}
}

Sheet_EquipClear_s::Sheet_EquipClear_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_EquipClear_s::CreateInit() {
	return 0;
}

int Sheet_EquipClear_s::ResumeInit() {
	return 0;
}

void Sheet_EquipClear_s::write_to_pbmsg(::proto_ff::Sheet_EquipClear & msg) const {
	for(int32_t i = 0; i < (int32_t)E_EquipClear_List.size(); ++i) {
		::proto_ff::E_EquipClear* temp_e_equipclear_list = msg.add_e_equipclear_list();
		E_EquipClear_List[i].write_to_pbmsg(*temp_e_equipclear_list);
	}
}

void Sheet_EquipClear_s::read_from_pbmsg(const ::proto_ff::Sheet_EquipClear & msg) {
	E_EquipClear_List.resize((int)msg.e_equipclear_list_size() > (int)E_EquipClear_List.max_size() ? E_EquipClear_List.max_size() : msg.e_equipclear_list_size());
	for(int32_t i = 0; i < (int32_t)E_EquipClear_List.size(); ++i) {
		const ::proto_ff::E_EquipClear & temp_e_equipclear_list = msg.e_equipclear_list(i);
		E_EquipClear_List[i].read_from_pbmsg(temp_e_equipclear_list);
	}
}

E_EquipSuitAttributeDesc_s::E_EquipSuitAttributeDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_EquipSuitAttributeDesc_s::CreateInit() {
	m_sctivation = (int32_t)0;
	return 0;
}

int E_EquipSuitAttributeDesc_s::ResumeInit() {
	return 0;
}

void E_EquipSuitAttributeDesc_s::write_to_pbmsg(::proto_ff::E_EquipSuitAttributeDesc & msg) const {
	msg.set_m_value(m_value.data());
	msg.set_m_sctivation((int32_t)m_sctivation);
}

void E_EquipSuitAttributeDesc_s::read_from_pbmsg(const ::proto_ff::E_EquipSuitAttributeDesc & msg) {
	m_value = msg.m_value();
	m_sctivation = msg.m_sctivation();
}

E_EquipSuit_s::E_EquipSuit_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_EquipSuit_s::CreateInit() {
	m_id = (int64_t)0;
	m_type = (int32_t)0;
	m_suitlv = (int32_t)0;
	m_wearquality = (int32_t)0;
	m_colour = (int32_t)0;
	m_suitevalue = (int32_t)0;
	return 0;
}

int E_EquipSuit_s::ResumeInit() {
	return 0;
}

void E_EquipSuit_s::write_to_pbmsg(::proto_ff::E_EquipSuit & msg) const {
	msg.set_m_id((int64_t)m_id);
	msg.set_m_type((int32_t)m_type);
	msg.set_m_suitlv((int32_t)m_suitlv);
	msg.set_m_wearquality((int32_t)m_wearquality);
	msg.set_m_colour((int32_t)m_colour);
	msg.set_m_aftername(m_aftername.data());
	msg.set_m_suitevalue((int32_t)m_suitevalue);
	for(int32_t i = 0; i < (int32_t)m_attribute.size(); ++i) {
		::proto_ff::E_EquipSuitAttributeDesc* temp_m_attribute = msg.add_m_attribute();
		m_attribute[i].write_to_pbmsg(*temp_m_attribute);
	}
	for(int32_t i = 0; i < (int32_t)m_maleposition.size(); ++i) {
		msg.add_m_maleposition(m_maleposition[i].data());
	}
	for(int32_t i = 0; i < (int32_t)m_femaleposition.size(); ++i) {
		msg.add_m_femaleposition(m_femaleposition[i].data());
	}
}

void E_EquipSuit_s::read_from_pbmsg(const ::proto_ff::E_EquipSuit & msg) {
	m_id = msg.m_id();
	m_type = msg.m_type();
	m_suitlv = msg.m_suitlv();
	m_wearquality = msg.m_wearquality();
	m_colour = msg.m_colour();
	m_aftername = msg.m_aftername();
	m_suitevalue = msg.m_suitevalue();
	m_attribute.resize((int)msg.m_attribute_size() > (int)m_attribute.max_size() ? m_attribute.max_size() : msg.m_attribute_size());
	for(int32_t i = 0; i < (int32_t)m_attribute.size(); ++i) {
		const ::proto_ff::E_EquipSuitAttributeDesc & temp_m_attribute = msg.m_attribute(i);
		m_attribute[i].read_from_pbmsg(temp_m_attribute);
	}
	m_maleposition.resize((int)msg.m_maleposition_size() > (int)m_maleposition.max_size() ? m_maleposition.max_size() : msg.m_maleposition_size());
	for(int32_t i = 0; i < (int32_t)m_maleposition.size(); ++i) {
		m_maleposition[i] = msg.m_maleposition(i);
	}
	m_femaleposition.resize((int)msg.m_femaleposition_size() > (int)m_femaleposition.max_size() ? m_femaleposition.max_size() : msg.m_femaleposition_size());
	for(int32_t i = 0; i < (int32_t)m_femaleposition.size(); ++i) {
		m_femaleposition[i] = msg.m_femaleposition(i);
	}
}

Sheet_EquipSuit_s::Sheet_EquipSuit_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_EquipSuit_s::CreateInit() {
	return 0;
}

int Sheet_EquipSuit_s::ResumeInit() {
	return 0;
}

void Sheet_EquipSuit_s::write_to_pbmsg(::proto_ff::Sheet_EquipSuit & msg) const {
	for(int32_t i = 0; i < (int32_t)E_EquipSuit_List.size(); ++i) {
		::proto_ff::E_EquipSuit* temp_e_equipsuit_list = msg.add_e_equipsuit_list();
		E_EquipSuit_List[i].write_to_pbmsg(*temp_e_equipsuit_list);
	}
}

void Sheet_EquipSuit_s::read_from_pbmsg(const ::proto_ff::Sheet_EquipSuit & msg) {
	E_EquipSuit_List.resize((int)msg.e_equipsuit_list_size() > (int)E_EquipSuit_List.max_size() ? E_EquipSuit_List.max_size() : msg.e_equipsuit_list_size());
	for(int32_t i = 0; i < (int32_t)E_EquipSuit_List.size(); ++i) {
		const ::proto_ff::E_EquipSuit & temp_e_equipsuit_list = msg.e_equipsuit_list(i);
		E_EquipSuit_List[i].read_from_pbmsg(temp_e_equipsuit_list);
	}
}

E_EquipBreakBreakDesc_s::E_EquipBreakBreakDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_EquipBreakBreakDesc_s::CreateInit() {
	m_num = (int32_t)0;
	m_item = (int32_t)0;
	return 0;
}

int E_EquipBreakBreakDesc_s::ResumeInit() {
	return 0;
}

void E_EquipBreakBreakDesc_s::write_to_pbmsg(::proto_ff::E_EquipBreakBreakDesc & msg) const {
	msg.set_m_num((int32_t)m_num);
	msg.set_m_item((int32_t)m_item);
}

void E_EquipBreakBreakDesc_s::read_from_pbmsg(const ::proto_ff::E_EquipBreakBreakDesc & msg) {
	m_num = msg.m_num();
	m_item = msg.m_item();
}

E_EquipBreak_s::E_EquipBreak_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_EquipBreak_s::CreateInit() {
	m_lv = (int32_t)0;
	m_step = (int32_t)0;
	m_basic = (int32_t)0;
	m_star = (int32_t)0;
	return 0;
}

int E_EquipBreak_s::ResumeInit() {
	return 0;
}

void E_EquipBreak_s::write_to_pbmsg(::proto_ff::E_EquipBreak & msg) const {
	msg.set_m_lv((int32_t)m_lv);
	msg.set_m_step((int32_t)m_step);
	msg.set_m_positiontype(m_positiontype.data());
	msg.set_m_basic((int32_t)m_basic);
	msg.set_m_star((int32_t)m_star);
	for(int32_t i = 0; i < (int32_t)m_break.size(); ++i) {
		::proto_ff::E_EquipBreakBreakDesc* temp_m_break = msg.add_m_break();
		m_break[i].write_to_pbmsg(*temp_m_break);
	}
}

void E_EquipBreak_s::read_from_pbmsg(const ::proto_ff::E_EquipBreak & msg) {
	m_lv = msg.m_lv();
	m_step = msg.m_step();
	m_positiontype = msg.m_positiontype();
	m_basic = msg.m_basic();
	m_star = msg.m_star();
	m_break.resize((int)msg.m_break_size() > (int)m_break.max_size() ? m_break.max_size() : msg.m_break_size());
	for(int32_t i = 0; i < (int32_t)m_break.size(); ++i) {
		const ::proto_ff::E_EquipBreakBreakDesc & temp_m_break = msg.m_break(i);
		m_break[i].read_from_pbmsg(temp_m_break);
	}
}

Sheet_EquipBreak_s::Sheet_EquipBreak_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_EquipBreak_s::CreateInit() {
	return 0;
}

int Sheet_EquipBreak_s::ResumeInit() {
	return 0;
}

void Sheet_EquipBreak_s::write_to_pbmsg(::proto_ff::Sheet_EquipBreak & msg) const {
	for(int32_t i = 0; i < (int32_t)E_EquipBreak_List.size(); ++i) {
		::proto_ff::E_EquipBreak* temp_e_equipbreak_list = msg.add_e_equipbreak_list();
		E_EquipBreak_List[i].write_to_pbmsg(*temp_e_equipbreak_list);
	}
}

void Sheet_EquipBreak_s::read_from_pbmsg(const ::proto_ff::Sheet_EquipBreak & msg) {
	E_EquipBreak_List.resize((int)msg.e_equipbreak_list_size() > (int)E_EquipBreak_List.max_size() ? E_EquipBreak_List.max_size() : msg.e_equipbreak_list_size());
	for(int32_t i = 0; i < (int32_t)E_EquipBreak_List.size(); ++i) {
		const ::proto_ff::E_EquipBreak & temp_e_equipbreak_list = msg.e_equipbreak_list(i);
		E_EquipBreak_List[i].read_from_pbmsg(temp_e_equipbreak_list);
	}
}

}
