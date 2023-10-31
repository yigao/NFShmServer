#include "E_Role_s.h"

namespace proto_ff_s {

E_RoleBornItemDesc_s::E_RoleBornItemDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_RoleBornItemDesc_s::CreateInit() {
	m_num = (int32_t)0;
	m_name = (int64_t)0;
	return 0;
}

int E_RoleBornItemDesc_s::ResumeInit() {
	return 0;
}

void E_RoleBornItemDesc_s::write_to_pbmsg(::proto_ff::E_RoleBornItemDesc & msg) const {
	msg.set_m_num((int32_t)m_num);
	msg.set_m_name((int64_t)m_name);
}

void E_RoleBornItemDesc_s::read_from_pbmsg(const ::proto_ff::E_RoleBornItemDesc & msg) {
	m_num = msg.m_num();
	m_name = msg.m_name();
}

E_RoleBornMailDesc_s::E_RoleBornMailDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_RoleBornMailDesc_s::CreateInit() {
	m_num = (int32_t)0;
	m_name = (int64_t)0;
	return 0;
}

int E_RoleBornMailDesc_s::ResumeInit() {
	return 0;
}

void E_RoleBornMailDesc_s::write_to_pbmsg(::proto_ff::E_RoleBornMailDesc & msg) const {
	msg.set_m_num((int32_t)m_num);
	msg.set_m_name((int64_t)m_name);
}

void E_RoleBornMailDesc_s::read_from_pbmsg(const ::proto_ff::E_RoleBornMailDesc & msg) {
	m_num = msg.m_num();
	m_name = msg.m_name();
}

E_RoleBorn_s::E_RoleBorn_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_RoleBorn_s::CreateInit() {
	m_bornID = (int64_t)0;
	m_professionID = (int32_t)0;
	m_gender = (int32_t)0;
	m_bornLevel = (int32_t)0;
	m_bornTitle = (int32_t)0;
	m_diamond = (int64_t)0;
	m_bindDiamond = (int64_t)0;
	m_gold = (int64_t)0;
	m_mapID = (int64_t)0;
	m_birthFace = (int32_t)0;
	m_hairColor = (int32_t)0;
	m_clothesColor = (int32_t)0;
	m_skinColor = (int32_t)0;
	m_carryWeapons = (int64_t)0;
	m_carryArmor = (int64_t)0;
	m_carryCloak = (int64_t)0;
	m_carryShoes = (int64_t)0;
	m_carryNecklace = (int64_t)0;
	m_carryAmulet = (int64_t)0;
	m_carryBracer = (int64_t)0;
	m_carryRing = (int64_t)0;
	m_carryFashionWeapons = (int64_t)0;
	m_carryFashionArmor = (int64_t)0;
	m_carryWings = (int64_t)0;
	m_mSpeed = (int32_t)0;
	m_view = (int32_t)0;
	m_radius = (int32_t)0;
	m_group = (int32_t)0;
	m_sheny = (int64_t)0;
	m_shenw = (int64_t)0;
	return 0;
}

int E_RoleBorn_s::ResumeInit() {
	return 0;
}

void E_RoleBorn_s::write_to_pbmsg(::proto_ff::E_RoleBorn & msg) const {
	msg.set_m_bornid((int64_t)m_bornID);
	msg.set_m_professionid((int32_t)m_professionID);
	msg.set_m_professionname(m_professionName.data());
	msg.set_m_placement(m_placement.data());
	msg.set_m_gender((int32_t)m_gender);
	msg.set_m_bornlevel((int32_t)m_bornLevel);
	msg.set_m_borntitle((int32_t)m_bornTitle);
	msg.set_m_diamond((int64_t)m_diamond);
	msg.set_m_binddiamond((int64_t)m_bindDiamond);
	msg.set_m_gold((int64_t)m_gold);
	msg.set_m_mapid((int64_t)m_mapID);
	msg.set_m_birthface((int32_t)m_birthFace);
	msg.set_m_icons(m_icons.data());
	msg.set_m_loginavata(m_loginAvata.data());
	msg.set_m_newweapon(m_newweapon.data());
	msg.set_m_newclothing(m_newclothing.data());
	msg.set_m_weaponavata(m_weaponAvata.data());
	msg.set_m_roleavata(m_roleAvata.data());
	msg.set_m_marryavata(m_marryAvata.data());
	msg.set_m_haircolor((int32_t)m_hairColor);
	msg.set_m_clothescolor((int32_t)m_clothesColor);
	msg.set_m_skincolor((int32_t)m_skinColor);
	msg.set_m_carryweapons((int64_t)m_carryWeapons);
	msg.set_m_carryarmor((int64_t)m_carryArmor);
	msg.set_m_carrycloak((int64_t)m_carryCloak);
	msg.set_m_carryshoes((int64_t)m_carryShoes);
	msg.set_m_carrynecklace((int64_t)m_carryNecklace);
	msg.set_m_carryamulet((int64_t)m_carryAmulet);
	msg.set_m_carrybracer((int64_t)m_carryBracer);
	msg.set_m_carryring((int64_t)m_carryRing);
	msg.set_m_carryfashionweapons((int64_t)m_carryFashionWeapons);
	msg.set_m_carryfashionarmor((int64_t)m_carryFashionArmor);
	msg.set_m_carrywings((int64_t)m_carryWings);
	msg.set_m_mspeed((int32_t)m_mSpeed);
	msg.set_m_view((int32_t)m_view);
	msg.set_m_radius((int32_t)m_radius);
	msg.set_m_group((int32_t)m_group);
	msg.set_m_sheny((int64_t)m_sheny);
	msg.set_m_shenw((int64_t)m_shenw);
	for(int32_t i = 0; i < (int32_t)m_actBuff.size(); ++i) {
		msg.add_m_actbuff((int32_t)m_actBuff[i]);
	}
	for(int32_t i = 0; i < (int32_t)m_actSkill.size(); ++i) {
		msg.add_m_actskill((int64_t)m_actSkill[i]);
	}
	for(int32_t i = 0; i < (int32_t)m_item.size(); ++i) {
		::proto_ff::E_RoleBornItemDesc* temp_m_item = msg.add_m_item();
		m_item[i].write_to_pbmsg(*temp_m_item);
	}
	for(int32_t i = 0; i < (int32_t)m_mail.size(); ++i) {
		::proto_ff::E_RoleBornMailDesc* temp_m_mail = msg.add_m_mail();
		m_mail[i].write_to_pbmsg(*temp_m_mail);
	}
}

void E_RoleBorn_s::read_from_pbmsg(const ::proto_ff::E_RoleBorn & msg) {
	m_bornID = msg.m_bornid();
	m_professionID = msg.m_professionid();
	m_professionName = msg.m_professionname();
	m_placement = msg.m_placement();
	m_gender = msg.m_gender();
	m_bornLevel = msg.m_bornlevel();
	m_bornTitle = msg.m_borntitle();
	m_diamond = msg.m_diamond();
	m_bindDiamond = msg.m_binddiamond();
	m_gold = msg.m_gold();
	m_mapID = msg.m_mapid();
	m_birthFace = msg.m_birthface();
	m_icons = msg.m_icons();
	m_loginAvata = msg.m_loginavata();
	m_newweapon = msg.m_newweapon();
	m_newclothing = msg.m_newclothing();
	m_weaponAvata = msg.m_weaponavata();
	m_roleAvata = msg.m_roleavata();
	m_marryAvata = msg.m_marryavata();
	m_hairColor = msg.m_haircolor();
	m_clothesColor = msg.m_clothescolor();
	m_skinColor = msg.m_skincolor();
	m_carryWeapons = msg.m_carryweapons();
	m_carryArmor = msg.m_carryarmor();
	m_carryCloak = msg.m_carrycloak();
	m_carryShoes = msg.m_carryshoes();
	m_carryNecklace = msg.m_carrynecklace();
	m_carryAmulet = msg.m_carryamulet();
	m_carryBracer = msg.m_carrybracer();
	m_carryRing = msg.m_carryring();
	m_carryFashionWeapons = msg.m_carryfashionweapons();
	m_carryFashionArmor = msg.m_carryfashionarmor();
	m_carryWings = msg.m_carrywings();
	m_mSpeed = msg.m_mspeed();
	m_view = msg.m_view();
	m_radius = msg.m_radius();
	m_group = msg.m_group();
	m_sheny = msg.m_sheny();
	m_shenw = msg.m_shenw();
	m_actBuff.resize((int)msg.m_actbuff_size() > (int)m_actBuff.max_size() ? m_actBuff.max_size() : msg.m_actbuff_size());
	for(int32_t i = 0; i < (int32_t)m_actBuff.size(); ++i) {
		m_actBuff[i] = msg.m_actbuff(i);
	}
	m_actSkill.resize((int)msg.m_actskill_size() > (int)m_actSkill.max_size() ? m_actSkill.max_size() : msg.m_actskill_size());
	for(int32_t i = 0; i < (int32_t)m_actSkill.size(); ++i) {
		m_actSkill[i] = msg.m_actskill(i);
	}
	m_item.resize((int)msg.m_item_size() > (int)m_item.max_size() ? m_item.max_size() : msg.m_item_size());
	for(int32_t i = 0; i < (int32_t)m_item.size(); ++i) {
		const ::proto_ff::E_RoleBornItemDesc & temp_m_item = msg.m_item(i);
		m_item[i].read_from_pbmsg(temp_m_item);
	}
	m_mail.resize((int)msg.m_mail_size() > (int)m_mail.max_size() ? m_mail.max_size() : msg.m_mail_size());
	for(int32_t i = 0; i < (int32_t)m_mail.size(); ++i) {
		const ::proto_ff::E_RoleBornMailDesc & temp_m_mail = msg.m_mail(i);
		m_mail[i].read_from_pbmsg(temp_m_mail);
	}
}

Sheet_RoleBorn_s::Sheet_RoleBorn_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_RoleBorn_s::CreateInit() {
	return 0;
}

int Sheet_RoleBorn_s::ResumeInit() {
	return 0;
}

void Sheet_RoleBorn_s::write_to_pbmsg(::proto_ff::Sheet_RoleBorn & msg) const {
	for(int32_t i = 0; i < (int32_t)E_RoleBorn_List.size(); ++i) {
		::proto_ff::E_RoleBorn* temp_e_roleborn_list = msg.add_e_roleborn_list();
		E_RoleBorn_List[i].write_to_pbmsg(*temp_e_roleborn_list);
	}
}

void Sheet_RoleBorn_s::read_from_pbmsg(const ::proto_ff::Sheet_RoleBorn & msg) {
	E_RoleBorn_List.resize((int)msg.e_roleborn_list_size() > (int)E_RoleBorn_List.max_size() ? E_RoleBorn_List.max_size() : msg.e_roleborn_list_size());
	for(int32_t i = 0; i < (int32_t)E_RoleBorn_List.size(); ++i) {
		const ::proto_ff::E_RoleBorn & temp_e_roleborn_list = msg.e_roleborn_list(i);
		E_RoleBorn_List[i].read_from_pbmsg(temp_e_roleborn_list);
	}
}

E_RoleMastermaleAttributeDesc_s::E_RoleMastermaleAttributeDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_RoleMastermaleAttributeDesc_s::CreateInit() {
	m_Value = (int32_t)0;
	m_Type = (int32_t)0;
	return 0;
}

int E_RoleMastermaleAttributeDesc_s::ResumeInit() {
	return 0;
}

void E_RoleMastermaleAttributeDesc_s::write_to_pbmsg(::proto_ff::E_RoleMastermaleAttributeDesc & msg) const {
	msg.set_m_value((int32_t)m_Value);
	msg.set_m_type((int32_t)m_Type);
}

void E_RoleMastermaleAttributeDesc_s::read_from_pbmsg(const ::proto_ff::E_RoleMastermaleAttributeDesc & msg) {
	m_Value = msg.m_value();
	m_Type = msg.m_type();
}

E_RoleMastermale_s::E_RoleMastermale_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_RoleMastermale_s::CreateInit() {
	m_lv = (int32_t)0;
	m_upgradePoint = (int32_t)0;
	return 0;
}

int E_RoleMastermale_s::ResumeInit() {
	return 0;
}

void E_RoleMastermale_s::write_to_pbmsg(::proto_ff::E_RoleMastermale & msg) const {
	msg.set_m_lv((int32_t)m_lv);
	msg.set_m_upgradepoint((int32_t)m_upgradePoint);
	for(int32_t i = 0; i < (int32_t)m_attribute.size(); ++i) {
		::proto_ff::E_RoleMastermaleAttributeDesc* temp_m_attribute = msg.add_m_attribute();
		m_attribute[i].write_to_pbmsg(*temp_m_attribute);
	}
}

void E_RoleMastermale_s::read_from_pbmsg(const ::proto_ff::E_RoleMastermale & msg) {
	m_lv = msg.m_lv();
	m_upgradePoint = msg.m_upgradepoint();
	m_attribute.resize((int)msg.m_attribute_size() > (int)m_attribute.max_size() ? m_attribute.max_size() : msg.m_attribute_size());
	for(int32_t i = 0; i < (int32_t)m_attribute.size(); ++i) {
		const ::proto_ff::E_RoleMastermaleAttributeDesc & temp_m_attribute = msg.m_attribute(i);
		m_attribute[i].read_from_pbmsg(temp_m_attribute);
	}
}

Sheet_RoleMastermale_s::Sheet_RoleMastermale_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_RoleMastermale_s::CreateInit() {
	return 0;
}

int Sheet_RoleMastermale_s::ResumeInit() {
	return 0;
}

void Sheet_RoleMastermale_s::write_to_pbmsg(::proto_ff::Sheet_RoleMastermale & msg) const {
	for(int32_t i = 0; i < (int32_t)E_RoleMastermale_List.size(); ++i) {
		::proto_ff::E_RoleMastermale* temp_e_rolemastermale_list = msg.add_e_rolemastermale_list();
		E_RoleMastermale_List[i].write_to_pbmsg(*temp_e_rolemastermale_list);
	}
}

void Sheet_RoleMastermale_s::read_from_pbmsg(const ::proto_ff::Sheet_RoleMastermale & msg) {
	E_RoleMastermale_List.resize((int)msg.e_rolemastermale_list_size() > (int)E_RoleMastermale_List.max_size() ? E_RoleMastermale_List.max_size() : msg.e_rolemastermale_list_size());
	for(int32_t i = 0; i < (int32_t)E_RoleMastermale_List.size(); ++i) {
		const ::proto_ff::E_RoleMastermale & temp_e_rolemastermale_list = msg.e_rolemastermale_list(i);
		E_RoleMastermale_List[i].read_from_pbmsg(temp_e_rolemastermale_list);
	}
}

E_RoleMasterfemaleAttributeDesc_s::E_RoleMasterfemaleAttributeDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_RoleMasterfemaleAttributeDesc_s::CreateInit() {
	m_Value = (int32_t)0;
	m_Type = (int32_t)0;
	return 0;
}

int E_RoleMasterfemaleAttributeDesc_s::ResumeInit() {
	return 0;
}

void E_RoleMasterfemaleAttributeDesc_s::write_to_pbmsg(::proto_ff::E_RoleMasterfemaleAttributeDesc & msg) const {
	msg.set_m_value((int32_t)m_Value);
	msg.set_m_type((int32_t)m_Type);
}

void E_RoleMasterfemaleAttributeDesc_s::read_from_pbmsg(const ::proto_ff::E_RoleMasterfemaleAttributeDesc & msg) {
	m_Value = msg.m_value();
	m_Type = msg.m_type();
}

E_RoleMasterfemale_s::E_RoleMasterfemale_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_RoleMasterfemale_s::CreateInit() {
	m_lv = (int32_t)0;
	m_upgradePoint = (int32_t)0;
	return 0;
}

int E_RoleMasterfemale_s::ResumeInit() {
	return 0;
}

void E_RoleMasterfemale_s::write_to_pbmsg(::proto_ff::E_RoleMasterfemale & msg) const {
	msg.set_m_lv((int32_t)m_lv);
	msg.set_m_upgradepoint((int32_t)m_upgradePoint);
	for(int32_t i = 0; i < (int32_t)m_attribute.size(); ++i) {
		::proto_ff::E_RoleMasterfemaleAttributeDesc* temp_m_attribute = msg.add_m_attribute();
		m_attribute[i].write_to_pbmsg(*temp_m_attribute);
	}
}

void E_RoleMasterfemale_s::read_from_pbmsg(const ::proto_ff::E_RoleMasterfemale & msg) {
	m_lv = msg.m_lv();
	m_upgradePoint = msg.m_upgradepoint();
	m_attribute.resize((int)msg.m_attribute_size() > (int)m_attribute.max_size() ? m_attribute.max_size() : msg.m_attribute_size());
	for(int32_t i = 0; i < (int32_t)m_attribute.size(); ++i) {
		const ::proto_ff::E_RoleMasterfemaleAttributeDesc & temp_m_attribute = msg.m_attribute(i);
		m_attribute[i].read_from_pbmsg(temp_m_attribute);
	}
}

Sheet_RoleMasterfemale_s::Sheet_RoleMasterfemale_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_RoleMasterfemale_s::CreateInit() {
	return 0;
}

int Sheet_RoleMasterfemale_s::ResumeInit() {
	return 0;
}

void Sheet_RoleMasterfemale_s::write_to_pbmsg(::proto_ff::Sheet_RoleMasterfemale & msg) const {
	for(int32_t i = 0; i < (int32_t)E_RoleMasterfemale_List.size(); ++i) {
		::proto_ff::E_RoleMasterfemale* temp_e_rolemasterfemale_list = msg.add_e_rolemasterfemale_list();
		E_RoleMasterfemale_List[i].write_to_pbmsg(*temp_e_rolemasterfemale_list);
	}
}

void Sheet_RoleMasterfemale_s::read_from_pbmsg(const ::proto_ff::Sheet_RoleMasterfemale & msg) {
	E_RoleMasterfemale_List.resize((int)msg.e_rolemasterfemale_list_size() > (int)E_RoleMasterfemale_List.max_size() ? E_RoleMasterfemale_List.max_size() : msg.e_rolemasterfemale_list_size());
	for(int32_t i = 0; i < (int32_t)E_RoleMasterfemale_List.size(); ++i) {
		const ::proto_ff::E_RoleMasterfemale & temp_e_rolemasterfemale_list = msg.e_rolemasterfemale_list(i);
		E_RoleMasterfemale_List[i].read_from_pbmsg(temp_e_rolemasterfemale_list);
	}
}

E_RoleSicklemaleAttributeDesc_s::E_RoleSicklemaleAttributeDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_RoleSicklemaleAttributeDesc_s::CreateInit() {
	m_Value = (int32_t)0;
	m_Type = (int32_t)0;
	return 0;
}

int E_RoleSicklemaleAttributeDesc_s::ResumeInit() {
	return 0;
}

void E_RoleSicklemaleAttributeDesc_s::write_to_pbmsg(::proto_ff::E_RoleSicklemaleAttributeDesc & msg) const {
	msg.set_m_value((int32_t)m_Value);
	msg.set_m_type((int32_t)m_Type);
}

void E_RoleSicklemaleAttributeDesc_s::read_from_pbmsg(const ::proto_ff::E_RoleSicklemaleAttributeDesc & msg) {
	m_Value = msg.m_value();
	m_Type = msg.m_type();
}

E_RoleSicklemale_s::E_RoleSicklemale_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_RoleSicklemale_s::CreateInit() {
	m_lv = (int32_t)0;
	m_upgradePoint = (int32_t)0;
	return 0;
}

int E_RoleSicklemale_s::ResumeInit() {
	return 0;
}

void E_RoleSicklemale_s::write_to_pbmsg(::proto_ff::E_RoleSicklemale & msg) const {
	msg.set_m_lv((int32_t)m_lv);
	msg.set_m_upgradepoint((int32_t)m_upgradePoint);
	for(int32_t i = 0; i < (int32_t)m_attribute.size(); ++i) {
		::proto_ff::E_RoleSicklemaleAttributeDesc* temp_m_attribute = msg.add_m_attribute();
		m_attribute[i].write_to_pbmsg(*temp_m_attribute);
	}
}

void E_RoleSicklemale_s::read_from_pbmsg(const ::proto_ff::E_RoleSicklemale & msg) {
	m_lv = msg.m_lv();
	m_upgradePoint = msg.m_upgradepoint();
	m_attribute.resize((int)msg.m_attribute_size() > (int)m_attribute.max_size() ? m_attribute.max_size() : msg.m_attribute_size());
	for(int32_t i = 0; i < (int32_t)m_attribute.size(); ++i) {
		const ::proto_ff::E_RoleSicklemaleAttributeDesc & temp_m_attribute = msg.m_attribute(i);
		m_attribute[i].read_from_pbmsg(temp_m_attribute);
	}
}

Sheet_RoleSicklemale_s::Sheet_RoleSicklemale_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_RoleSicklemale_s::CreateInit() {
	return 0;
}

int Sheet_RoleSicklemale_s::ResumeInit() {
	return 0;
}

void Sheet_RoleSicklemale_s::write_to_pbmsg(::proto_ff::Sheet_RoleSicklemale & msg) const {
	for(int32_t i = 0; i < (int32_t)E_RoleSicklemale_List.size(); ++i) {
		::proto_ff::E_RoleSicklemale* temp_e_rolesicklemale_list = msg.add_e_rolesicklemale_list();
		E_RoleSicklemale_List[i].write_to_pbmsg(*temp_e_rolesicklemale_list);
	}
}

void Sheet_RoleSicklemale_s::read_from_pbmsg(const ::proto_ff::Sheet_RoleSicklemale & msg) {
	E_RoleSicklemale_List.resize((int)msg.e_rolesicklemale_list_size() > (int)E_RoleSicklemale_List.max_size() ? E_RoleSicklemale_List.max_size() : msg.e_rolesicklemale_list_size());
	for(int32_t i = 0; i < (int32_t)E_RoleSicklemale_List.size(); ++i) {
		const ::proto_ff::E_RoleSicklemale & temp_e_rolesicklemale_list = msg.e_rolesicklemale_list(i);
		E_RoleSicklemale_List[i].read_from_pbmsg(temp_e_rolesicklemale_list);
	}
}

E_RoleSicklefemaleAttributeDesc_s::E_RoleSicklefemaleAttributeDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_RoleSicklefemaleAttributeDesc_s::CreateInit() {
	m_Value = (int32_t)0;
	m_Type = (int32_t)0;
	return 0;
}

int E_RoleSicklefemaleAttributeDesc_s::ResumeInit() {
	return 0;
}

void E_RoleSicklefemaleAttributeDesc_s::write_to_pbmsg(::proto_ff::E_RoleSicklefemaleAttributeDesc & msg) const {
	msg.set_m_value((int32_t)m_Value);
	msg.set_m_type((int32_t)m_Type);
}

void E_RoleSicklefemaleAttributeDesc_s::read_from_pbmsg(const ::proto_ff::E_RoleSicklefemaleAttributeDesc & msg) {
	m_Value = msg.m_value();
	m_Type = msg.m_type();
}

E_RoleSicklefemale_s::E_RoleSicklefemale_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_RoleSicklefemale_s::CreateInit() {
	m_lv = (int32_t)0;
	m_upgradePoint = (int32_t)0;
	return 0;
}

int E_RoleSicklefemale_s::ResumeInit() {
	return 0;
}

void E_RoleSicklefemale_s::write_to_pbmsg(::proto_ff::E_RoleSicklefemale & msg) const {
	msg.set_m_lv((int32_t)m_lv);
	msg.set_m_upgradepoint((int32_t)m_upgradePoint);
	for(int32_t i = 0; i < (int32_t)m_attribute.size(); ++i) {
		::proto_ff::E_RoleSicklefemaleAttributeDesc* temp_m_attribute = msg.add_m_attribute();
		m_attribute[i].write_to_pbmsg(*temp_m_attribute);
	}
}

void E_RoleSicklefemale_s::read_from_pbmsg(const ::proto_ff::E_RoleSicklefemale & msg) {
	m_lv = msg.m_lv();
	m_upgradePoint = msg.m_upgradepoint();
	m_attribute.resize((int)msg.m_attribute_size() > (int)m_attribute.max_size() ? m_attribute.max_size() : msg.m_attribute_size());
	for(int32_t i = 0; i < (int32_t)m_attribute.size(); ++i) {
		const ::proto_ff::E_RoleSicklefemaleAttributeDesc & temp_m_attribute = msg.m_attribute(i);
		m_attribute[i].read_from_pbmsg(temp_m_attribute);
	}
}

Sheet_RoleSicklefemale_s::Sheet_RoleSicklefemale_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_RoleSicklefemale_s::CreateInit() {
	return 0;
}

int Sheet_RoleSicklefemale_s::ResumeInit() {
	return 0;
}

void Sheet_RoleSicklefemale_s::write_to_pbmsg(::proto_ff::Sheet_RoleSicklefemale & msg) const {
	for(int32_t i = 0; i < (int32_t)E_RoleSicklefemale_List.size(); ++i) {
		::proto_ff::E_RoleSicklefemale* temp_e_rolesicklefemale_list = msg.add_e_rolesicklefemale_list();
		E_RoleSicklefemale_List[i].write_to_pbmsg(*temp_e_rolesicklefemale_list);
	}
}

void Sheet_RoleSicklefemale_s::read_from_pbmsg(const ::proto_ff::Sheet_RoleSicklefemale & msg) {
	E_RoleSicklefemale_List.resize((int)msg.e_rolesicklefemale_list_size() > (int)E_RoleSicklefemale_List.max_size() ? E_RoleSicklefemale_List.max_size() : msg.e_rolesicklefemale_list_size());
	for(int32_t i = 0; i < (int32_t)E_RoleSicklefemale_List.size(); ++i) {
		const ::proto_ff::E_RoleSicklefemale & temp_e_rolesicklefemale_list = msg.e_rolesicklefemale_list(i);
		E_RoleSicklefemale_List[i].read_from_pbmsg(temp_e_rolesicklefemale_list);
	}
}

E_RoleSwordmaleAttributeDesc_s::E_RoleSwordmaleAttributeDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_RoleSwordmaleAttributeDesc_s::CreateInit() {
	m_Value = (int32_t)0;
	m_Type = (int32_t)0;
	return 0;
}

int E_RoleSwordmaleAttributeDesc_s::ResumeInit() {
	return 0;
}

void E_RoleSwordmaleAttributeDesc_s::write_to_pbmsg(::proto_ff::E_RoleSwordmaleAttributeDesc & msg) const {
	msg.set_m_value((int32_t)m_Value);
	msg.set_m_type((int32_t)m_Type);
}

void E_RoleSwordmaleAttributeDesc_s::read_from_pbmsg(const ::proto_ff::E_RoleSwordmaleAttributeDesc & msg) {
	m_Value = msg.m_value();
	m_Type = msg.m_type();
}

E_RoleSwordmale_s::E_RoleSwordmale_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_RoleSwordmale_s::CreateInit() {
	m_lv = (int32_t)0;
	m_upgradePoint = (int32_t)0;
	return 0;
}

int E_RoleSwordmale_s::ResumeInit() {
	return 0;
}

void E_RoleSwordmale_s::write_to_pbmsg(::proto_ff::E_RoleSwordmale & msg) const {
	msg.set_m_lv((int32_t)m_lv);
	msg.set_m_upgradepoint((int32_t)m_upgradePoint);
	for(int32_t i = 0; i < (int32_t)m_attribute.size(); ++i) {
		::proto_ff::E_RoleSwordmaleAttributeDesc* temp_m_attribute = msg.add_m_attribute();
		m_attribute[i].write_to_pbmsg(*temp_m_attribute);
	}
}

void E_RoleSwordmale_s::read_from_pbmsg(const ::proto_ff::E_RoleSwordmale & msg) {
	m_lv = msg.m_lv();
	m_upgradePoint = msg.m_upgradepoint();
	m_attribute.resize((int)msg.m_attribute_size() > (int)m_attribute.max_size() ? m_attribute.max_size() : msg.m_attribute_size());
	for(int32_t i = 0; i < (int32_t)m_attribute.size(); ++i) {
		const ::proto_ff::E_RoleSwordmaleAttributeDesc & temp_m_attribute = msg.m_attribute(i);
		m_attribute[i].read_from_pbmsg(temp_m_attribute);
	}
}

Sheet_RoleSwordmale_s::Sheet_RoleSwordmale_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_RoleSwordmale_s::CreateInit() {
	return 0;
}

int Sheet_RoleSwordmale_s::ResumeInit() {
	return 0;
}

void Sheet_RoleSwordmale_s::write_to_pbmsg(::proto_ff::Sheet_RoleSwordmale & msg) const {
	for(int32_t i = 0; i < (int32_t)E_RoleSwordmale_List.size(); ++i) {
		::proto_ff::E_RoleSwordmale* temp_e_roleswordmale_list = msg.add_e_roleswordmale_list();
		E_RoleSwordmale_List[i].write_to_pbmsg(*temp_e_roleswordmale_list);
	}
}

void Sheet_RoleSwordmale_s::read_from_pbmsg(const ::proto_ff::Sheet_RoleSwordmale & msg) {
	E_RoleSwordmale_List.resize((int)msg.e_roleswordmale_list_size() > (int)E_RoleSwordmale_List.max_size() ? E_RoleSwordmale_List.max_size() : msg.e_roleswordmale_list_size());
	for(int32_t i = 0; i < (int32_t)E_RoleSwordmale_List.size(); ++i) {
		const ::proto_ff::E_RoleSwordmale & temp_e_roleswordmale_list = msg.e_roleswordmale_list(i);
		E_RoleSwordmale_List[i].read_from_pbmsg(temp_e_roleswordmale_list);
	}
}

E_RoleSwordfemaleAttributeDesc_s::E_RoleSwordfemaleAttributeDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_RoleSwordfemaleAttributeDesc_s::CreateInit() {
	m_Value = (int32_t)0;
	m_Type = (int32_t)0;
	return 0;
}

int E_RoleSwordfemaleAttributeDesc_s::ResumeInit() {
	return 0;
}

void E_RoleSwordfemaleAttributeDesc_s::write_to_pbmsg(::proto_ff::E_RoleSwordfemaleAttributeDesc & msg) const {
	msg.set_m_value((int32_t)m_Value);
	msg.set_m_type((int32_t)m_Type);
}

void E_RoleSwordfemaleAttributeDesc_s::read_from_pbmsg(const ::proto_ff::E_RoleSwordfemaleAttributeDesc & msg) {
	m_Value = msg.m_value();
	m_Type = msg.m_type();
}

E_RoleSwordfemale_s::E_RoleSwordfemale_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_RoleSwordfemale_s::CreateInit() {
	m_lv = (int32_t)0;
	m_upgradePoint = (int32_t)0;
	return 0;
}

int E_RoleSwordfemale_s::ResumeInit() {
	return 0;
}

void E_RoleSwordfemale_s::write_to_pbmsg(::proto_ff::E_RoleSwordfemale & msg) const {
	msg.set_m_lv((int32_t)m_lv);
	msg.set_m_upgradepoint((int32_t)m_upgradePoint);
	for(int32_t i = 0; i < (int32_t)m_attribute.size(); ++i) {
		::proto_ff::E_RoleSwordfemaleAttributeDesc* temp_m_attribute = msg.add_m_attribute();
		m_attribute[i].write_to_pbmsg(*temp_m_attribute);
	}
}

void E_RoleSwordfemale_s::read_from_pbmsg(const ::proto_ff::E_RoleSwordfemale & msg) {
	m_lv = msg.m_lv();
	m_upgradePoint = msg.m_upgradepoint();
	m_attribute.resize((int)msg.m_attribute_size() > (int)m_attribute.max_size() ? m_attribute.max_size() : msg.m_attribute_size());
	for(int32_t i = 0; i < (int32_t)m_attribute.size(); ++i) {
		const ::proto_ff::E_RoleSwordfemaleAttributeDesc & temp_m_attribute = msg.m_attribute(i);
		m_attribute[i].read_from_pbmsg(temp_m_attribute);
	}
}

Sheet_RoleSwordfemale_s::Sheet_RoleSwordfemale_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_RoleSwordfemale_s::CreateInit() {
	return 0;
}

int Sheet_RoleSwordfemale_s::ResumeInit() {
	return 0;
}

void Sheet_RoleSwordfemale_s::write_to_pbmsg(::proto_ff::Sheet_RoleSwordfemale & msg) const {
	for(int32_t i = 0; i < (int32_t)E_RoleSwordfemale_List.size(); ++i) {
		::proto_ff::E_RoleSwordfemale* temp_e_roleswordfemale_list = msg.add_e_roleswordfemale_list();
		E_RoleSwordfemale_List[i].write_to_pbmsg(*temp_e_roleswordfemale_list);
	}
}

void Sheet_RoleSwordfemale_s::read_from_pbmsg(const ::proto_ff::Sheet_RoleSwordfemale & msg) {
	E_RoleSwordfemale_List.resize((int)msg.e_roleswordfemale_list_size() > (int)E_RoleSwordfemale_List.max_size() ? E_RoleSwordfemale_List.max_size() : msg.e_roleswordfemale_list_size());
	for(int32_t i = 0; i < (int32_t)E_RoleSwordfemale_List.size(); ++i) {
		const ::proto_ff::E_RoleSwordfemale & temp_e_roleswordfemale_list = msg.e_roleswordfemale_list(i);
		E_RoleSwordfemale_List[i].read_from_pbmsg(temp_e_roleswordfemale_list);
	}
}

E_RoleTaidaomaleAttributeDesc_s::E_RoleTaidaomaleAttributeDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_RoleTaidaomaleAttributeDesc_s::CreateInit() {
	m_Value = (int32_t)0;
	m_Type = (int32_t)0;
	return 0;
}

int E_RoleTaidaomaleAttributeDesc_s::ResumeInit() {
	return 0;
}

void E_RoleTaidaomaleAttributeDesc_s::write_to_pbmsg(::proto_ff::E_RoleTaidaomaleAttributeDesc & msg) const {
	msg.set_m_value((int32_t)m_Value);
	msg.set_m_type((int32_t)m_Type);
}

void E_RoleTaidaomaleAttributeDesc_s::read_from_pbmsg(const ::proto_ff::E_RoleTaidaomaleAttributeDesc & msg) {
	m_Value = msg.m_value();
	m_Type = msg.m_type();
}

E_RoleTaidaomale_s::E_RoleTaidaomale_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_RoleTaidaomale_s::CreateInit() {
	m_lv = (int32_t)0;
	m_upgradePoint = (int32_t)0;
	return 0;
}

int E_RoleTaidaomale_s::ResumeInit() {
	return 0;
}

void E_RoleTaidaomale_s::write_to_pbmsg(::proto_ff::E_RoleTaidaomale & msg) const {
	msg.set_m_lv((int32_t)m_lv);
	msg.set_m_upgradepoint((int32_t)m_upgradePoint);
	for(int32_t i = 0; i < (int32_t)m_attribute.size(); ++i) {
		::proto_ff::E_RoleTaidaomaleAttributeDesc* temp_m_attribute = msg.add_m_attribute();
		m_attribute[i].write_to_pbmsg(*temp_m_attribute);
	}
}

void E_RoleTaidaomale_s::read_from_pbmsg(const ::proto_ff::E_RoleTaidaomale & msg) {
	m_lv = msg.m_lv();
	m_upgradePoint = msg.m_upgradepoint();
	m_attribute.resize((int)msg.m_attribute_size() > (int)m_attribute.max_size() ? m_attribute.max_size() : msg.m_attribute_size());
	for(int32_t i = 0; i < (int32_t)m_attribute.size(); ++i) {
		const ::proto_ff::E_RoleTaidaomaleAttributeDesc & temp_m_attribute = msg.m_attribute(i);
		m_attribute[i].read_from_pbmsg(temp_m_attribute);
	}
}

Sheet_RoleTaidaomale_s::Sheet_RoleTaidaomale_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_RoleTaidaomale_s::CreateInit() {
	return 0;
}

int Sheet_RoleTaidaomale_s::ResumeInit() {
	return 0;
}

void Sheet_RoleTaidaomale_s::write_to_pbmsg(::proto_ff::Sheet_RoleTaidaomale & msg) const {
	for(int32_t i = 0; i < (int32_t)E_RoleTaidaomale_List.size(); ++i) {
		::proto_ff::E_RoleTaidaomale* temp_e_roletaidaomale_list = msg.add_e_roletaidaomale_list();
		E_RoleTaidaomale_List[i].write_to_pbmsg(*temp_e_roletaidaomale_list);
	}
}

void Sheet_RoleTaidaomale_s::read_from_pbmsg(const ::proto_ff::Sheet_RoleTaidaomale & msg) {
	E_RoleTaidaomale_List.resize((int)msg.e_roletaidaomale_list_size() > (int)E_RoleTaidaomale_List.max_size() ? E_RoleTaidaomale_List.max_size() : msg.e_roletaidaomale_list_size());
	for(int32_t i = 0; i < (int32_t)E_RoleTaidaomale_List.size(); ++i) {
		const ::proto_ff::E_RoleTaidaomale & temp_e_roletaidaomale_list = msg.e_roletaidaomale_list(i);
		E_RoleTaidaomale_List[i].read_from_pbmsg(temp_e_roletaidaomale_list);
	}
}

E_RoleTaidaofemaleAttributeDesc_s::E_RoleTaidaofemaleAttributeDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_RoleTaidaofemaleAttributeDesc_s::CreateInit() {
	m_Value = (int32_t)0;
	m_Type = (int32_t)0;
	return 0;
}

int E_RoleTaidaofemaleAttributeDesc_s::ResumeInit() {
	return 0;
}

void E_RoleTaidaofemaleAttributeDesc_s::write_to_pbmsg(::proto_ff::E_RoleTaidaofemaleAttributeDesc & msg) const {
	msg.set_m_value((int32_t)m_Value);
	msg.set_m_type((int32_t)m_Type);
}

void E_RoleTaidaofemaleAttributeDesc_s::read_from_pbmsg(const ::proto_ff::E_RoleTaidaofemaleAttributeDesc & msg) {
	m_Value = msg.m_value();
	m_Type = msg.m_type();
}

E_RoleTaidaofemale_s::E_RoleTaidaofemale_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_RoleTaidaofemale_s::CreateInit() {
	m_lv = (int32_t)0;
	m_upgradePoint = (int32_t)0;
	return 0;
}

int E_RoleTaidaofemale_s::ResumeInit() {
	return 0;
}

void E_RoleTaidaofemale_s::write_to_pbmsg(::proto_ff::E_RoleTaidaofemale & msg) const {
	msg.set_m_lv((int32_t)m_lv);
	msg.set_m_upgradepoint((int32_t)m_upgradePoint);
	for(int32_t i = 0; i < (int32_t)m_attribute.size(); ++i) {
		::proto_ff::E_RoleTaidaofemaleAttributeDesc* temp_m_attribute = msg.add_m_attribute();
		m_attribute[i].write_to_pbmsg(*temp_m_attribute);
	}
}

void E_RoleTaidaofemale_s::read_from_pbmsg(const ::proto_ff::E_RoleTaidaofemale & msg) {
	m_lv = msg.m_lv();
	m_upgradePoint = msg.m_upgradepoint();
	m_attribute.resize((int)msg.m_attribute_size() > (int)m_attribute.max_size() ? m_attribute.max_size() : msg.m_attribute_size());
	for(int32_t i = 0; i < (int32_t)m_attribute.size(); ++i) {
		const ::proto_ff::E_RoleTaidaofemaleAttributeDesc & temp_m_attribute = msg.m_attribute(i);
		m_attribute[i].read_from_pbmsg(temp_m_attribute);
	}
}

Sheet_RoleTaidaofemale_s::Sheet_RoleTaidaofemale_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_RoleTaidaofemale_s::CreateInit() {
	return 0;
}

int Sheet_RoleTaidaofemale_s::ResumeInit() {
	return 0;
}

void Sheet_RoleTaidaofemale_s::write_to_pbmsg(::proto_ff::Sheet_RoleTaidaofemale & msg) const {
	for(int32_t i = 0; i < (int32_t)E_RoleTaidaofemale_List.size(); ++i) {
		::proto_ff::E_RoleTaidaofemale* temp_e_roletaidaofemale_list = msg.add_e_roletaidaofemale_list();
		E_RoleTaidaofemale_List[i].write_to_pbmsg(*temp_e_roletaidaofemale_list);
	}
}

void Sheet_RoleTaidaofemale_s::read_from_pbmsg(const ::proto_ff::Sheet_RoleTaidaofemale & msg) {
	E_RoleTaidaofemale_List.resize((int)msg.e_roletaidaofemale_list_size() > (int)E_RoleTaidaofemale_List.max_size() ? E_RoleTaidaofemale_List.max_size() : msg.e_roletaidaofemale_list_size());
	for(int32_t i = 0; i < (int32_t)E_RoleTaidaofemale_List.size(); ++i) {
		const ::proto_ff::E_RoleTaidaofemale & temp_e_roletaidaofemale_list = msg.e_roletaidaofemale_list(i);
		E_RoleTaidaofemale_List[i].read_from_pbmsg(temp_e_roletaidaofemale_list);
	}
}

E_RoleExp_s::E_RoleExp_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_RoleExp_s::CreateInit() {
	m_lv = (int32_t)0;
	m_exp = (int64_t)0;
	m_skillPoint = (int32_t)0;
	m_prepareModeDexp = (int32_t)0;
	m_fengshen = (int32_t)0;
	m_pet = (int32_t)0;
	m_dragon = (int32_t)0;
	m_equip = (int32_t)0;
	m_arena = (int32_t)0;
	m_solo = (int32_t)0;
	m_multiBattle = (int32_t)0;
	m_qingyun = (int32_t)0;
	m_yaochi = (int32_t)0;
	m_wedding = (int32_t)0;
	m_bagua = (int32_t)0;
	return 0;
}

int E_RoleExp_s::ResumeInit() {
	return 0;
}

void E_RoleExp_s::write_to_pbmsg(::proto_ff::E_RoleExp & msg) const {
	msg.set_m_lv((int32_t)m_lv);
	msg.set_m_exp((int64_t)m_exp);
	msg.set_m_skillpoint((int32_t)m_skillPoint);
	msg.set_m_preparemodedexp((int32_t)m_prepareModeDexp);
	msg.set_m_fengshen((int32_t)m_fengshen);
	msg.set_m_pet((int32_t)m_pet);
	msg.set_m_dragon((int32_t)m_dragon);
	msg.set_m_equip((int32_t)m_equip);
	msg.set_m_arena((int32_t)m_arena);
	msg.set_m_solo((int32_t)m_solo);
	msg.set_m_multibattle((int32_t)m_multiBattle);
	msg.set_m_qingyun((int32_t)m_qingyun);
	msg.set_m_yaochi((int32_t)m_yaochi);
	msg.set_m_wedding((int32_t)m_wedding);
	msg.set_m_bagua((int32_t)m_bagua);
}

void E_RoleExp_s::read_from_pbmsg(const ::proto_ff::E_RoleExp & msg) {
	m_lv = msg.m_lv();
	m_exp = msg.m_exp();
	m_skillPoint = msg.m_skillpoint();
	m_prepareModeDexp = msg.m_preparemodedexp();
	m_fengshen = msg.m_fengshen();
	m_pet = msg.m_pet();
	m_dragon = msg.m_dragon();
	m_equip = msg.m_equip();
	m_arena = msg.m_arena();
	m_solo = msg.m_solo();
	m_multiBattle = msg.m_multibattle();
	m_qingyun = msg.m_qingyun();
	m_yaochi = msg.m_yaochi();
	m_wedding = msg.m_wedding();
	m_bagua = msg.m_bagua();
}

Sheet_RoleExp_s::Sheet_RoleExp_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_RoleExp_s::CreateInit() {
	return 0;
}

int Sheet_RoleExp_s::ResumeInit() {
	return 0;
}

void Sheet_RoleExp_s::write_to_pbmsg(::proto_ff::Sheet_RoleExp & msg) const {
	for(int32_t i = 0; i < (int32_t)E_RoleExp_List.size(); ++i) {
		::proto_ff::E_RoleExp* temp_e_roleexp_list = msg.add_e_roleexp_list();
		E_RoleExp_List[i].write_to_pbmsg(*temp_e_roleexp_list);
	}
}

void Sheet_RoleExp_s::read_from_pbmsg(const ::proto_ff::Sheet_RoleExp & msg) {
	E_RoleExp_List.resize((int)msg.e_roleexp_list_size() > (int)E_RoleExp_List.max_size() ? E_RoleExp_List.max_size() : msg.e_roleexp_list_size());
	for(int32_t i = 0; i < (int32_t)E_RoleExp_List.size(); ++i) {
		const ::proto_ff::E_RoleExp & temp_e_roleexp_list = msg.e_roleexp_list(i);
		E_RoleExp_List[i].read_from_pbmsg(temp_e_roleexp_list);
	}
}

E_RoleSkilltype_s::E_RoleSkilltype_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_RoleSkilltype_s::CreateInit() {
	m_skillId = (int64_t)0;
	m_skillType = (int32_t)0;
	return 0;
}

int E_RoleSkilltype_s::ResumeInit() {
	return 0;
}

void E_RoleSkilltype_s::write_to_pbmsg(::proto_ff::E_RoleSkilltype & msg) const {
	msg.set_m_skillid((int64_t)m_skillId);
	msg.set_m_skilltype((int32_t)m_skillType);
}

void E_RoleSkilltype_s::read_from_pbmsg(const ::proto_ff::E_RoleSkilltype & msg) {
	m_skillId = msg.m_skillid();
	m_skillType = msg.m_skilltype();
}

Sheet_RoleSkilltype_s::Sheet_RoleSkilltype_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_RoleSkilltype_s::CreateInit() {
	return 0;
}

int Sheet_RoleSkilltype_s::ResumeInit() {
	return 0;
}

void Sheet_RoleSkilltype_s::write_to_pbmsg(::proto_ff::Sheet_RoleSkilltype & msg) const {
	for(int32_t i = 0; i < (int32_t)E_RoleSkilltype_List.size(); ++i) {
		::proto_ff::E_RoleSkilltype* temp_e_roleskilltype_list = msg.add_e_roleskilltype_list();
		E_RoleSkilltype_List[i].write_to_pbmsg(*temp_e_roleskilltype_list);
	}
}

void Sheet_RoleSkilltype_s::read_from_pbmsg(const ::proto_ff::Sheet_RoleSkilltype & msg) {
	E_RoleSkilltype_List.resize((int)msg.e_roleskilltype_list_size() > (int)E_RoleSkilltype_List.max_size() ? E_RoleSkilltype_List.max_size() : msg.e_roleskilltype_list_size());
	for(int32_t i = 0; i < (int32_t)E_RoleSkilltype_List.size(); ++i) {
		const ::proto_ff::E_RoleSkilltype & temp_e_roleskilltype_list = msg.e_roleskilltype_list(i);
		E_RoleSkilltype_List[i].read_from_pbmsg(temp_e_roleskilltype_list);
	}
}

E_RoleAddskill_s::E_RoleAddskill_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_RoleAddskill_s::CreateInit() {
	m_Id = (int32_t)0;
	m_skillId = (int64_t)0;
	return 0;
}

int E_RoleAddskill_s::ResumeInit() {
	return 0;
}

void E_RoleAddskill_s::write_to_pbmsg(::proto_ff::E_RoleAddskill & msg) const {
	msg.set_m_id((int32_t)m_Id);
	msg.set_m_skillid((int64_t)m_skillId);
}

void E_RoleAddskill_s::read_from_pbmsg(const ::proto_ff::E_RoleAddskill & msg) {
	m_Id = msg.m_id();
	m_skillId = msg.m_skillid();
}

Sheet_RoleAddskill_s::Sheet_RoleAddskill_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_RoleAddskill_s::CreateInit() {
	return 0;
}

int Sheet_RoleAddskill_s::ResumeInit() {
	return 0;
}

void Sheet_RoleAddskill_s::write_to_pbmsg(::proto_ff::Sheet_RoleAddskill & msg) const {
	for(int32_t i = 0; i < (int32_t)E_RoleAddskill_List.size(); ++i) {
		::proto_ff::E_RoleAddskill* temp_e_roleaddskill_list = msg.add_e_roleaddskill_list();
		E_RoleAddskill_List[i].write_to_pbmsg(*temp_e_roleaddskill_list);
	}
}

void Sheet_RoleAddskill_s::read_from_pbmsg(const ::proto_ff::Sheet_RoleAddskill & msg) {
	E_RoleAddskill_List.resize((int)msg.e_roleaddskill_list_size() > (int)E_RoleAddskill_List.max_size() ? E_RoleAddskill_List.max_size() : msg.e_roleaddskill_list_size());
	for(int32_t i = 0; i < (int32_t)E_RoleAddskill_List.size(); ++i) {
		const ::proto_ff::E_RoleAddskill & temp_e_roleaddskill_list = msg.e_roleaddskill_list(i);
		E_RoleAddskill_List[i].read_from_pbmsg(temp_e_roleaddskill_list);
	}
}

E_RoleWorldexp_s::E_RoleWorldexp_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_RoleWorldexp_s::CreateInit() {
	m_lv = (int64_t)0;
	m_worldExp = (int32_t)0;
	return 0;
}

int E_RoleWorldexp_s::ResumeInit() {
	return 0;
}

void E_RoleWorldexp_s::write_to_pbmsg(::proto_ff::E_RoleWorldexp & msg) const {
	msg.set_m_lv((int64_t)m_lv);
	msg.set_m_worldexp((int32_t)m_worldExp);
}

void E_RoleWorldexp_s::read_from_pbmsg(const ::proto_ff::E_RoleWorldexp & msg) {
	m_lv = msg.m_lv();
	m_worldExp = msg.m_worldexp();
}

Sheet_RoleWorldexp_s::Sheet_RoleWorldexp_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_RoleWorldexp_s::CreateInit() {
	return 0;
}

int Sheet_RoleWorldexp_s::ResumeInit() {
	return 0;
}

void Sheet_RoleWorldexp_s::write_to_pbmsg(::proto_ff::Sheet_RoleWorldexp & msg) const {
	for(int32_t i = 0; i < (int32_t)E_RoleWorldexp_List.size(); ++i) {
		::proto_ff::E_RoleWorldexp* temp_e_roleworldexp_list = msg.add_e_roleworldexp_list();
		E_RoleWorldexp_List[i].write_to_pbmsg(*temp_e_roleworldexp_list);
	}
}

void Sheet_RoleWorldexp_s::read_from_pbmsg(const ::proto_ff::Sheet_RoleWorldexp & msg) {
	E_RoleWorldexp_List.resize((int)msg.e_roleworldexp_list_size() > (int)E_RoleWorldexp_List.max_size() ? E_RoleWorldexp_List.max_size() : msg.e_roleworldexp_list_size());
	for(int32_t i = 0; i < (int32_t)E_RoleWorldexp_List.size(); ++i) {
		const ::proto_ff::E_RoleWorldexp & temp_e_roleworldexp_list = msg.e_roleworldexp_list(i);
		E_RoleWorldexp_List[i].read_from_pbmsg(temp_e_roleworldexp_list);
	}
}

}
