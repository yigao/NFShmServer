#include "E_Shenti_s.h"

namespace proto_ff_s {

E_ShentiConstantTimeDesc_s::E_ShentiConstantTimeDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_ShentiConstantTimeDesc_s::CreateInit() {
	return 0;
}

int E_ShentiConstantTimeDesc_s::ResumeInit() {
	return 0;
}

void E_ShentiConstantTimeDesc_s::write_to_pbmsg(::proto_ff::E_ShentiConstantTimeDesc & msg) const {
	msg.set_m_close(m_close.data());
	msg.set_m_open(m_open.data());
}

void E_ShentiConstantTimeDesc_s::read_from_pbmsg(const ::proto_ff::E_ShentiConstantTimeDesc & msg) {
	m_close = msg.m_close();
	m_open = msg.m_open();
}

E_ShentiConstant_s::E_ShentiConstant_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_ShentiConstant_s::CreateInit() {
	m_id = (int32_t)0;
	m_lvLimit = (int32_t)0;
	m_remanieTimes = (int32_t)0;
	m_currencyId = (int32_t)0;
	m_currencyNum = (int32_t)0;
	m_currencyTimes = (int32_t)0;
	m_bagLimit = (int32_t)0;
	m_itemId = (int32_t)0;
	return 0;
}

int E_ShentiConstant_s::ResumeInit() {
	return 0;
}

void E_ShentiConstant_s::write_to_pbmsg(::proto_ff::E_ShentiConstant & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_lvlimit((int32_t)m_lvLimit);
	msg.set_m_remanietimes((int32_t)m_remanieTimes);
	msg.set_m_currencyid((int32_t)m_currencyId);
	msg.set_m_currencynum((int32_t)m_currencyNum);
	msg.set_m_currencytimes((int32_t)m_currencyTimes);
	msg.set_m_baglimit((int32_t)m_bagLimit);
	msg.set_m_itemid((int32_t)m_itemId);
	for(int32_t i = 0; i < (int32_t)m_time.size(); ++i) {
		::proto_ff::E_ShentiConstantTimeDesc* temp_m_time = msg.add_m_time();
		m_time[i].write_to_pbmsg(*temp_m_time);
	}
}

void E_ShentiConstant_s::read_from_pbmsg(const ::proto_ff::E_ShentiConstant & msg) {
	m_id = msg.m_id();
	m_lvLimit = msg.m_lvlimit();
	m_remanieTimes = msg.m_remanietimes();
	m_currencyId = msg.m_currencyid();
	m_currencyNum = msg.m_currencynum();
	m_currencyTimes = msg.m_currencytimes();
	m_bagLimit = msg.m_baglimit();
	m_itemId = msg.m_itemid();
	m_time.resize((int)msg.m_time_size() > (int)m_time.max_size() ? m_time.max_size() : msg.m_time_size());
	for(int32_t i = 0; i < (int32_t)m_time.size(); ++i) {
		const ::proto_ff::E_ShentiConstantTimeDesc & temp_m_time = msg.m_time(i);
		m_time[i].read_from_pbmsg(temp_m_time);
	}
}

Sheet_ShentiConstant_s::Sheet_ShentiConstant_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_ShentiConstant_s::CreateInit() {
	return 0;
}

int Sheet_ShentiConstant_s::ResumeInit() {
	return 0;
}

void Sheet_ShentiConstant_s::write_to_pbmsg(::proto_ff::Sheet_ShentiConstant & msg) const {
	for(int32_t i = 0; i < (int32_t)E_ShentiConstant_List.size(); ++i) {
		::proto_ff::E_ShentiConstant* temp_e_shenticonstant_list = msg.add_e_shenticonstant_list();
		E_ShentiConstant_List[i].write_to_pbmsg(*temp_e_shenticonstant_list);
	}
}

void Sheet_ShentiConstant_s::read_from_pbmsg(const ::proto_ff::Sheet_ShentiConstant & msg) {
	E_ShentiConstant_List.resize((int)msg.e_shenticonstant_list_size() > (int)E_ShentiConstant_List.max_size() ? E_ShentiConstant_List.max_size() : msg.e_shenticonstant_list_size());
	for(int32_t i = 0; i < (int32_t)E_ShentiConstant_List.size(); ++i) {
		const ::proto_ff::E_ShentiConstant & temp_e_shenticonstant_list = msg.e_shenticonstant_list(i);
		E_ShentiConstant_List[i].read_from_pbmsg(temp_e_shenticonstant_list);
	}
}

E_ShentiPreposeRewardDesc_s::E_ShentiPreposeRewardDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_ShentiPreposeRewardDesc_s::CreateInit() {
	m_num = (int32_t)0;
	m_item = (int32_t)0;
	return 0;
}

int E_ShentiPreposeRewardDesc_s::ResumeInit() {
	return 0;
}

void E_ShentiPreposeRewardDesc_s::write_to_pbmsg(::proto_ff::E_ShentiPreposeRewardDesc & msg) const {
	msg.set_m_num((int32_t)m_num);
	msg.set_m_item((int32_t)m_item);
}

void E_ShentiPreposeRewardDesc_s::read_from_pbmsg(const ::proto_ff::E_ShentiPreposeRewardDesc & msg) {
	m_num = msg.m_num();
	m_item = msg.m_item();
}

E_ShentiPrepose_s::E_ShentiPrepose_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_ShentiPrepose_s::CreateInit() {
	m_id = (int32_t)0;
	m_condition = (int32_t)0;
	m_value = (int32_t)0;
	return 0;
}

int E_ShentiPrepose_s::ResumeInit() {
	return 0;
}

void E_ShentiPrepose_s::write_to_pbmsg(::proto_ff::E_ShentiPrepose & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_condition((int32_t)m_condition);
	msg.set_m_value((int32_t)m_value);
	for(int32_t i = 0; i < (int32_t)m_reward.size(); ++i) {
		::proto_ff::E_ShentiPreposeRewardDesc* temp_m_reward = msg.add_m_reward();
		m_reward[i].write_to_pbmsg(*temp_m_reward);
	}
}

void E_ShentiPrepose_s::read_from_pbmsg(const ::proto_ff::E_ShentiPrepose & msg) {
	m_id = msg.m_id();
	m_condition = msg.m_condition();
	m_value = msg.m_value();
	m_reward.resize((int)msg.m_reward_size() > (int)m_reward.max_size() ? m_reward.max_size() : msg.m_reward_size());
	for(int32_t i = 0; i < (int32_t)m_reward.size(); ++i) {
		const ::proto_ff::E_ShentiPreposeRewardDesc & temp_m_reward = msg.m_reward(i);
		m_reward[i].read_from_pbmsg(temp_m_reward);
	}
}

Sheet_ShentiPrepose_s::Sheet_ShentiPrepose_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_ShentiPrepose_s::CreateInit() {
	return 0;
}

int Sheet_ShentiPrepose_s::ResumeInit() {
	return 0;
}

void Sheet_ShentiPrepose_s::write_to_pbmsg(::proto_ff::Sheet_ShentiPrepose & msg) const {
	for(int32_t i = 0; i < (int32_t)E_ShentiPrepose_List.size(); ++i) {
		::proto_ff::E_ShentiPrepose* temp_e_shentiprepose_list = msg.add_e_shentiprepose_list();
		E_ShentiPrepose_List[i].write_to_pbmsg(*temp_e_shentiprepose_list);
	}
}

void Sheet_ShentiPrepose_s::read_from_pbmsg(const ::proto_ff::Sheet_ShentiPrepose & msg) {
	E_ShentiPrepose_List.resize((int)msg.e_shentiprepose_list_size() > (int)E_ShentiPrepose_List.max_size() ? E_ShentiPrepose_List.max_size() : msg.e_shentiprepose_list_size());
	for(int32_t i = 0; i < (int32_t)E_ShentiPrepose_List.size(); ++i) {
		const ::proto_ff::E_ShentiPrepose & temp_e_shentiprepose_list = msg.e_shentiprepose_list(i);
		E_ShentiPrepose_List[i].read_from_pbmsg(temp_e_shentiprepose_list);
	}
}

E_ShentiUpgradeAttributeDesc_s::E_ShentiUpgradeAttributeDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_ShentiUpgradeAttributeDesc_s::CreateInit() {
	m_value = (int32_t)0;
	m_type = (int32_t)0;
	return 0;
}

int E_ShentiUpgradeAttributeDesc_s::ResumeInit() {
	return 0;
}

void E_ShentiUpgradeAttributeDesc_s::write_to_pbmsg(::proto_ff::E_ShentiUpgradeAttributeDesc & msg) const {
	msg.set_m_value((int32_t)m_value);
	msg.set_m_type((int32_t)m_type);
}

void E_ShentiUpgradeAttributeDesc_s::read_from_pbmsg(const ::proto_ff::E_ShentiUpgradeAttributeDesc & msg) {
	m_value = msg.m_value();
	m_type = msg.m_type();
}

E_ShentiUpgrade_s::E_ShentiUpgrade_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_ShentiUpgrade_s::CreateInit() {
	m_id = (int64_t)0;
	m_lv = (int32_t)0;
	m_changeLv = (int32_t)0;
	m_exp = (int64_t)0;
	m_expLimit = (int64_t)0;
	return 0;
}

int E_ShentiUpgrade_s::ResumeInit() {
	return 0;
}

void E_ShentiUpgrade_s::write_to_pbmsg(::proto_ff::E_ShentiUpgrade & msg) const {
	msg.set_m_id((int64_t)m_id);
	msg.set_m_lv((int32_t)m_lv);
	msg.set_m_changelv((int32_t)m_changeLv);
	msg.set_m_exp((int64_t)m_exp);
	msg.set_m_explimit((int64_t)m_expLimit);
	for(int32_t i = 0; i < (int32_t)m_attribute.size(); ++i) {
		::proto_ff::E_ShentiUpgradeAttributeDesc* temp_m_attribute = msg.add_m_attribute();
		m_attribute[i].write_to_pbmsg(*temp_m_attribute);
	}
}

void E_ShentiUpgrade_s::read_from_pbmsg(const ::proto_ff::E_ShentiUpgrade & msg) {
	m_id = msg.m_id();
	m_lv = msg.m_lv();
	m_changeLv = msg.m_changelv();
	m_exp = msg.m_exp();
	m_expLimit = msg.m_explimit();
	m_attribute.resize((int)msg.m_attribute_size() > (int)m_attribute.max_size() ? m_attribute.max_size() : msg.m_attribute_size());
	for(int32_t i = 0; i < (int32_t)m_attribute.size(); ++i) {
		const ::proto_ff::E_ShentiUpgradeAttributeDesc & temp_m_attribute = msg.m_attribute(i);
		m_attribute[i].read_from_pbmsg(temp_m_attribute);
	}
}

Sheet_ShentiUpgrade_s::Sheet_ShentiUpgrade_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_ShentiUpgrade_s::CreateInit() {
	return 0;
}

int Sheet_ShentiUpgrade_s::ResumeInit() {
	return 0;
}

void Sheet_ShentiUpgrade_s::write_to_pbmsg(::proto_ff::Sheet_ShentiUpgrade & msg) const {
	for(int32_t i = 0; i < (int32_t)E_ShentiUpgrade_List.size(); ++i) {
		::proto_ff::E_ShentiUpgrade* temp_e_shentiupgrade_list = msg.add_e_shentiupgrade_list();
		E_ShentiUpgrade_List[i].write_to_pbmsg(*temp_e_shentiupgrade_list);
	}
}

void Sheet_ShentiUpgrade_s::read_from_pbmsg(const ::proto_ff::Sheet_ShentiUpgrade & msg) {
	E_ShentiUpgrade_List.resize((int)msg.e_shentiupgrade_list_size() > (int)E_ShentiUpgrade_List.max_size() ? E_ShentiUpgrade_List.max_size() : msg.e_shentiupgrade_list_size());
	for(int32_t i = 0; i < (int32_t)E_ShentiUpgrade_List.size(); ++i) {
		const ::proto_ff::E_ShentiUpgrade & temp_e_shentiupgrade_list = msg.e_shentiupgrade_list(i);
		E_ShentiUpgrade_List[i].read_from_pbmsg(temp_e_shentiupgrade_list);
	}
}

E_ShentiRemanieAttrDesc_s::E_ShentiRemanieAttrDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_ShentiRemanieAttrDesc_s::CreateInit() {
	m_value = (int32_t)0;
	m_type = (int32_t)0;
	return 0;
}

int E_ShentiRemanieAttrDesc_s::ResumeInit() {
	return 0;
}

void E_ShentiRemanieAttrDesc_s::write_to_pbmsg(::proto_ff::E_ShentiRemanieAttrDesc & msg) const {
	msg.set_m_value((int32_t)m_value);
	msg.set_m_type((int32_t)m_type);
}

void E_ShentiRemanieAttrDesc_s::read_from_pbmsg(const ::proto_ff::E_ShentiRemanieAttrDesc & msg) {
	m_value = msg.m_value();
	m_type = msg.m_type();
}

E_ShentiRemanie_s::E_ShentiRemanie_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_ShentiRemanie_s::CreateInit() {
	m_id = (int32_t)0;
	m_remanieLv = (int32_t)0;
	m_lv = (int32_t)0;
	m_tianSuccess = (int32_t)0;
	m_diSuccess = (int32_t)0;
	m_loseSuccess = (int32_t)0;
	m_renSuccess = (int32_t)0;
	m_renSuccessLimit = (int32_t)0;
	m_reward = (int32_t)0;
	return 0;
}

int E_ShentiRemanie_s::ResumeInit() {
	return 0;
}

void E_ShentiRemanie_s::write_to_pbmsg(::proto_ff::E_ShentiRemanie & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_remanielv((int32_t)m_remanieLv);
	msg.set_m_lv((int32_t)m_lv);
	msg.set_m_tiansuccess((int32_t)m_tianSuccess);
	msg.set_m_disuccess((int32_t)m_diSuccess);
	msg.set_m_losesuccess((int32_t)m_loseSuccess);
	msg.set_m_rensuccess((int32_t)m_renSuccess);
	msg.set_m_rensuccesslimit((int32_t)m_renSuccessLimit);
	msg.set_m_reward((int32_t)m_reward);
	for(int32_t i = 0; i < (int32_t)m_attr.size(); ++i) {
		::proto_ff::E_ShentiRemanieAttrDesc* temp_m_attr = msg.add_m_attr();
		m_attr[i].write_to_pbmsg(*temp_m_attr);
	}
}

void E_ShentiRemanie_s::read_from_pbmsg(const ::proto_ff::E_ShentiRemanie & msg) {
	m_id = msg.m_id();
	m_remanieLv = msg.m_remanielv();
	m_lv = msg.m_lv();
	m_tianSuccess = msg.m_tiansuccess();
	m_diSuccess = msg.m_disuccess();
	m_loseSuccess = msg.m_losesuccess();
	m_renSuccess = msg.m_rensuccess();
	m_renSuccessLimit = msg.m_rensuccesslimit();
	m_reward = msg.m_reward();
	m_attr.resize((int)msg.m_attr_size() > (int)m_attr.max_size() ? m_attr.max_size() : msg.m_attr_size());
	for(int32_t i = 0; i < (int32_t)m_attr.size(); ++i) {
		const ::proto_ff::E_ShentiRemanieAttrDesc & temp_m_attr = msg.m_attr(i);
		m_attr[i].read_from_pbmsg(temp_m_attr);
	}
}

Sheet_ShentiRemanie_s::Sheet_ShentiRemanie_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_ShentiRemanie_s::CreateInit() {
	return 0;
}

int Sheet_ShentiRemanie_s::ResumeInit() {
	return 0;
}

void Sheet_ShentiRemanie_s::write_to_pbmsg(::proto_ff::Sheet_ShentiRemanie & msg) const {
	for(int32_t i = 0; i < (int32_t)E_ShentiRemanie_List.size(); ++i) {
		::proto_ff::E_ShentiRemanie* temp_e_shentiremanie_list = msg.add_e_shentiremanie_list();
		E_ShentiRemanie_List[i].write_to_pbmsg(*temp_e_shentiremanie_list);
	}
}

void Sheet_ShentiRemanie_s::read_from_pbmsg(const ::proto_ff::Sheet_ShentiRemanie & msg) {
	E_ShentiRemanie_List.resize((int)msg.e_shentiremanie_list_size() > (int)E_ShentiRemanie_List.max_size() ? E_ShentiRemanie_List.max_size() : msg.e_shentiremanie_list_size());
	for(int32_t i = 0; i < (int32_t)E_ShentiRemanie_List.size(); ++i) {
		const ::proto_ff::E_ShentiRemanie & temp_e_shentiremanie_list = msg.e_shentiremanie_list(i);
		E_ShentiRemanie_List[i].read_from_pbmsg(temp_e_shentiremanie_list);
	}
}

E_ShentiEquip_s::E_ShentiEquip_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_ShentiEquip_s::CreateInit() {
	m_id = (int64_t)0;
	m_type = (int32_t)0;
	m_remanieLv = (int32_t)0;
	m_position = (int32_t)0;
	m_professionLv = (int32_t)0;
	m_quality = (int32_t)0;
	m_attributeID = (int32_t)0;
	m_suitGroup = (int32_t)0;
	m_starGroup = (int32_t)0;
	m_isCanbind = (int32_t)0;
	m_isTradeBind = (int32_t)0;
	m_sellPrice = (int32_t)0;
	m_broadcast = (int32_t)0;
	return 0;
}

int E_ShentiEquip_s::ResumeInit() {
	return 0;
}

void E_ShentiEquip_s::write_to_pbmsg(::proto_ff::E_ShentiEquip & msg) const {
	msg.set_m_id((int64_t)m_id);
	msg.set_m_name(m_name.data());
	msg.set_m_type((int32_t)m_type);
	msg.set_m_remanielv((int32_t)m_remanieLv);
	msg.set_m_position((int32_t)m_position);
	msg.set_m_profession(m_profession.data());
	msg.set_m_professionlv((int32_t)m_professionLv);
	msg.set_m_quality((int32_t)m_quality);
	msg.set_m_attributeid((int32_t)m_attributeID);
	msg.set_m_suitgroup((int32_t)m_suitGroup);
	msg.set_m_stargroup((int32_t)m_starGroup);
	msg.set_m_iscanbind((int32_t)m_isCanbind);
	msg.set_m_istradebind((int32_t)m_isTradeBind);
	msg.set_m_sellprice((int32_t)m_sellPrice);
	msg.set_m_icon(m_icon.data());
	msg.set_m_broadcast((int32_t)m_broadcast);
}

void E_ShentiEquip_s::read_from_pbmsg(const ::proto_ff::E_ShentiEquip & msg) {
	m_id = msg.m_id();
	m_name = msg.m_name();
	m_type = msg.m_type();
	m_remanieLv = msg.m_remanielv();
	m_position = msg.m_position();
	m_profession = msg.m_profession();
	m_professionLv = msg.m_professionlv();
	m_quality = msg.m_quality();
	m_attributeID = msg.m_attributeid();
	m_suitGroup = msg.m_suitgroup();
	m_starGroup = msg.m_stargroup();
	m_isCanbind = msg.m_iscanbind();
	m_isTradeBind = msg.m_istradebind();
	m_sellPrice = msg.m_sellprice();
	m_icon = msg.m_icon();
	m_broadcast = msg.m_broadcast();
}

Sheet_ShentiEquip_s::Sheet_ShentiEquip_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_ShentiEquip_s::CreateInit() {
	return 0;
}

int Sheet_ShentiEquip_s::ResumeInit() {
	return 0;
}

void Sheet_ShentiEquip_s::write_to_pbmsg(::proto_ff::Sheet_ShentiEquip & msg) const {
	for(int32_t i = 0; i < (int32_t)E_ShentiEquip_List.size(); ++i) {
		::proto_ff::E_ShentiEquip* temp_e_shentiequip_list = msg.add_e_shentiequip_list();
		E_ShentiEquip_List[i].write_to_pbmsg(*temp_e_shentiequip_list);
	}
}

void Sheet_ShentiEquip_s::read_from_pbmsg(const ::proto_ff::Sheet_ShentiEquip & msg) {
	E_ShentiEquip_List.resize((int)msg.e_shentiequip_list_size() > (int)E_ShentiEquip_List.max_size() ? E_ShentiEquip_List.max_size() : msg.e_shentiequip_list_size());
	for(int32_t i = 0; i < (int32_t)E_ShentiEquip_List.size(); ++i) {
		const ::proto_ff::E_ShentiEquip & temp_e_shentiequip_list = msg.e_shentiequip_list(i);
		E_ShentiEquip_List[i].read_from_pbmsg(temp_e_shentiequip_list);
	}
}

E_ShentiAttributeAttributeDesc_s::E_ShentiAttributeAttributeDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_ShentiAttributeAttributeDesc_s::CreateInit() {
	m_value = (int32_t)0;
	m_type = (int32_t)0;
	return 0;
}

int E_ShentiAttributeAttributeDesc_s::ResumeInit() {
	return 0;
}

void E_ShentiAttributeAttributeDesc_s::write_to_pbmsg(::proto_ff::E_ShentiAttributeAttributeDesc & msg) const {
	msg.set_m_value((int32_t)m_value);
	msg.set_m_type((int32_t)m_type);
}

void E_ShentiAttributeAttributeDesc_s::read_from_pbmsg(const ::proto_ff::E_ShentiAttributeAttributeDesc & msg) {
	m_value = msg.m_value();
	m_type = msg.m_type();
}

E_ShentiAttributeXpcomDesc_s::E_ShentiAttributeXpcomDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_ShentiAttributeXpcomDesc_s::CreateInit() {
	m_value = (int32_t)0;
	m_type = (int32_t)0;
	return 0;
}

int E_ShentiAttributeXpcomDesc_s::ResumeInit() {
	return 0;
}

void E_ShentiAttributeXpcomDesc_s::write_to_pbmsg(::proto_ff::E_ShentiAttributeXpcomDesc & msg) const {
	msg.set_m_value((int32_t)m_value);
	msg.set_m_type((int32_t)m_type);
}

void E_ShentiAttributeXpcomDesc_s::read_from_pbmsg(const ::proto_ff::E_ShentiAttributeXpcomDesc & msg) {
	m_value = msg.m_value();
	m_type = msg.m_type();
}

E_ShentiAttributeXpstarDesc_s::E_ShentiAttributeXpstarDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_ShentiAttributeXpstarDesc_s::CreateInit() {
	m_value = (int32_t)0;
	m_type = (int32_t)0;
	return 0;
}

int E_ShentiAttributeXpstarDesc_s::ResumeInit() {
	return 0;
}

void E_ShentiAttributeXpstarDesc_s::write_to_pbmsg(::proto_ff::E_ShentiAttributeXpstarDesc & msg) const {
	msg.set_m_value((int32_t)m_value);
	msg.set_m_type((int32_t)m_type);
}

void E_ShentiAttributeXpstarDesc_s::read_from_pbmsg(const ::proto_ff::E_ShentiAttributeXpstarDesc & msg) {
	m_value = msg.m_value();
	m_type = msg.m_type();
}

E_ShentiAttributeGodDesc_s::E_ShentiAttributeGodDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_ShentiAttributeGodDesc_s::CreateInit() {
	m_value = (int32_t)0;
	m_type = (int32_t)0;
	return 0;
}

int E_ShentiAttributeGodDesc_s::ResumeInit() {
	return 0;
}

void E_ShentiAttributeGodDesc_s::write_to_pbmsg(::proto_ff::E_ShentiAttributeGodDesc & msg) const {
	msg.set_m_value((int32_t)m_value);
	msg.set_m_type((int32_t)m_type);
}

void E_ShentiAttributeGodDesc_s::read_from_pbmsg(const ::proto_ff::E_ShentiAttributeGodDesc & msg) {
	m_value = msg.m_value();
	m_type = msg.m_type();
}

E_ShentiAttributeSpecialDesc_s::E_ShentiAttributeSpecialDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_ShentiAttributeSpecialDesc_s::CreateInit() {
	m_value = (int32_t)0;
	m_type = (int32_t)0;
	return 0;
}

int E_ShentiAttributeSpecialDesc_s::ResumeInit() {
	return 0;
}

void E_ShentiAttributeSpecialDesc_s::write_to_pbmsg(::proto_ff::E_ShentiAttributeSpecialDesc & msg) const {
	msg.set_m_value((int32_t)m_value);
	msg.set_m_type((int32_t)m_type);
}

void E_ShentiAttributeSpecialDesc_s::read_from_pbmsg(const ::proto_ff::E_ShentiAttributeSpecialDesc & msg) {
	m_value = msg.m_value();
	m_type = msg.m_type();
}

E_ShentiAttribute_s::E_ShentiAttribute_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_ShentiAttribute_s::CreateInit() {
	m_id = (int32_t)0;
	return 0;
}

int E_ShentiAttribute_s::ResumeInit() {
	return 0;
}

void E_ShentiAttribute_s::write_to_pbmsg(::proto_ff::E_ShentiAttribute & msg) const {
	msg.set_m_id((int32_t)m_id);
	for(int32_t i = 0; i < (int32_t)m_attribute.size(); ++i) {
		::proto_ff::E_ShentiAttributeAttributeDesc* temp_m_attribute = msg.add_m_attribute();
		m_attribute[i].write_to_pbmsg(*temp_m_attribute);
	}
	for(int32_t i = 0; i < (int32_t)m_xpcom.size(); ++i) {
		::proto_ff::E_ShentiAttributeXpcomDesc* temp_m_xpcom = msg.add_m_xpcom();
		m_xpcom[i].write_to_pbmsg(*temp_m_xpcom);
	}
	for(int32_t i = 0; i < (int32_t)m_xpstar.size(); ++i) {
		::proto_ff::E_ShentiAttributeXpstarDesc* temp_m_xpstar = msg.add_m_xpstar();
		m_xpstar[i].write_to_pbmsg(*temp_m_xpstar);
	}
	for(int32_t i = 0; i < (int32_t)m_god.size(); ++i) {
		::proto_ff::E_ShentiAttributeGodDesc* temp_m_god = msg.add_m_god();
		m_god[i].write_to_pbmsg(*temp_m_god);
	}
	for(int32_t i = 0; i < (int32_t)m_special.size(); ++i) {
		::proto_ff::E_ShentiAttributeSpecialDesc* temp_m_special = msg.add_m_special();
		m_special[i].write_to_pbmsg(*temp_m_special);
	}
}

void E_ShentiAttribute_s::read_from_pbmsg(const ::proto_ff::E_ShentiAttribute & msg) {
	m_id = msg.m_id();
	m_attribute.resize((int)msg.m_attribute_size() > (int)m_attribute.max_size() ? m_attribute.max_size() : msg.m_attribute_size());
	for(int32_t i = 0; i < (int32_t)m_attribute.size(); ++i) {
		const ::proto_ff::E_ShentiAttributeAttributeDesc & temp_m_attribute = msg.m_attribute(i);
		m_attribute[i].read_from_pbmsg(temp_m_attribute);
	}
	m_xpcom.resize((int)msg.m_xpcom_size() > (int)m_xpcom.max_size() ? m_xpcom.max_size() : msg.m_xpcom_size());
	for(int32_t i = 0; i < (int32_t)m_xpcom.size(); ++i) {
		const ::proto_ff::E_ShentiAttributeXpcomDesc & temp_m_xpcom = msg.m_xpcom(i);
		m_xpcom[i].read_from_pbmsg(temp_m_xpcom);
	}
	m_xpstar.resize((int)msg.m_xpstar_size() > (int)m_xpstar.max_size() ? m_xpstar.max_size() : msg.m_xpstar_size());
	for(int32_t i = 0; i < (int32_t)m_xpstar.size(); ++i) {
		const ::proto_ff::E_ShentiAttributeXpstarDesc & temp_m_xpstar = msg.m_xpstar(i);
		m_xpstar[i].read_from_pbmsg(temp_m_xpstar);
	}
	m_god.resize((int)msg.m_god_size() > (int)m_god.max_size() ? m_god.max_size() : msg.m_god_size());
	for(int32_t i = 0; i < (int32_t)m_god.size(); ++i) {
		const ::proto_ff::E_ShentiAttributeGodDesc & temp_m_god = msg.m_god(i);
		m_god[i].read_from_pbmsg(temp_m_god);
	}
	m_special.resize((int)msg.m_special_size() > (int)m_special.max_size() ? m_special.max_size() : msg.m_special_size());
	for(int32_t i = 0; i < (int32_t)m_special.size(); ++i) {
		const ::proto_ff::E_ShentiAttributeSpecialDesc & temp_m_special = msg.m_special(i);
		m_special[i].read_from_pbmsg(temp_m_special);
	}
}

Sheet_ShentiAttribute_s::Sheet_ShentiAttribute_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_ShentiAttribute_s::CreateInit() {
	return 0;
}

int Sheet_ShentiAttribute_s::ResumeInit() {
	return 0;
}

void Sheet_ShentiAttribute_s::write_to_pbmsg(::proto_ff::Sheet_ShentiAttribute & msg) const {
	for(int32_t i = 0; i < (int32_t)E_ShentiAttribute_List.size(); ++i) {
		::proto_ff::E_ShentiAttribute* temp_e_shentiattribute_list = msg.add_e_shentiattribute_list();
		E_ShentiAttribute_List[i].write_to_pbmsg(*temp_e_shentiattribute_list);
	}
}

void Sheet_ShentiAttribute_s::read_from_pbmsg(const ::proto_ff::Sheet_ShentiAttribute & msg) {
	E_ShentiAttribute_List.resize((int)msg.e_shentiattribute_list_size() > (int)E_ShentiAttribute_List.max_size() ? E_ShentiAttribute_List.max_size() : msg.e_shentiattribute_list_size());
	for(int32_t i = 0; i < (int32_t)E_ShentiAttribute_List.size(); ++i) {
		const ::proto_ff::E_ShentiAttribute & temp_e_shentiattribute_list = msg.e_shentiattribute_list(i);
		E_ShentiAttribute_List[i].read_from_pbmsg(temp_e_shentiattribute_list);
	}
}

E_ShentiStrongMaterialDesc_s::E_ShentiStrongMaterialDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_ShentiStrongMaterialDesc_s::CreateInit() {
	m_num = (int32_t)0;
	m_id = (int32_t)0;
	return 0;
}

int E_ShentiStrongMaterialDesc_s::ResumeInit() {
	return 0;
}

void E_ShentiStrongMaterialDesc_s::write_to_pbmsg(::proto_ff::E_ShentiStrongMaterialDesc & msg) const {
	msg.set_m_num((int32_t)m_num);
	msg.set_m_id((int32_t)m_id);
}

void E_ShentiStrongMaterialDesc_s::read_from_pbmsg(const ::proto_ff::E_ShentiStrongMaterialDesc & msg) {
	m_num = msg.m_num();
	m_id = msg.m_id();
}

E_ShentiStrongAttributeDesc_s::E_ShentiStrongAttributeDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_ShentiStrongAttributeDesc_s::CreateInit() {
	m_value = (int32_t)0;
	return 0;
}

int E_ShentiStrongAttributeDesc_s::ResumeInit() {
	return 0;
}

void E_ShentiStrongAttributeDesc_s::write_to_pbmsg(::proto_ff::E_ShentiStrongAttributeDesc & msg) const {
	msg.set_m_value((int32_t)m_value);
}

void E_ShentiStrongAttributeDesc_s::read_from_pbmsg(const ::proto_ff::E_ShentiStrongAttributeDesc & msg) {
	m_value = msg.m_value();
}

E_ShentiStrong_s::E_ShentiStrong_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_ShentiStrong_s::CreateInit() {
	m_id = (int32_t)0;
	m_lv = (int32_t)0;
	m_remanieLv = (int32_t)0;
	return 0;
}

int E_ShentiStrong_s::ResumeInit() {
	return 0;
}

void E_ShentiStrong_s::write_to_pbmsg(::proto_ff::E_ShentiStrong & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_lv((int32_t)m_lv);
	msg.set_m_position(m_position.data());
	msg.set_m_remanielv((int32_t)m_remanieLv);
	for(int32_t i = 0; i < (int32_t)m_material.size(); ++i) {
		::proto_ff::E_ShentiStrongMaterialDesc* temp_m_material = msg.add_m_material();
		m_material[i].write_to_pbmsg(*temp_m_material);
	}
	for(int32_t i = 0; i < (int32_t)m_attribute.size(); ++i) {
		::proto_ff::E_ShentiStrongAttributeDesc* temp_m_attribute = msg.add_m_attribute();
		m_attribute[i].write_to_pbmsg(*temp_m_attribute);
	}
}

void E_ShentiStrong_s::read_from_pbmsg(const ::proto_ff::E_ShentiStrong & msg) {
	m_id = msg.m_id();
	m_lv = msg.m_lv();
	m_position = msg.m_position();
	m_remanieLv = msg.m_remanielv();
	m_material.resize((int)msg.m_material_size() > (int)m_material.max_size() ? m_material.max_size() : msg.m_material_size());
	for(int32_t i = 0; i < (int32_t)m_material.size(); ++i) {
		const ::proto_ff::E_ShentiStrongMaterialDesc & temp_m_material = msg.m_material(i);
		m_material[i].read_from_pbmsg(temp_m_material);
	}
	m_attribute.resize((int)msg.m_attribute_size() > (int)m_attribute.max_size() ? m_attribute.max_size() : msg.m_attribute_size());
	for(int32_t i = 0; i < (int32_t)m_attribute.size(); ++i) {
		const ::proto_ff::E_ShentiStrongAttributeDesc & temp_m_attribute = msg.m_attribute(i);
		m_attribute[i].read_from_pbmsg(temp_m_attribute);
	}
}

Sheet_ShentiStrong_s::Sheet_ShentiStrong_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_ShentiStrong_s::CreateInit() {
	return 0;
}

int Sheet_ShentiStrong_s::ResumeInit() {
	return 0;
}

void Sheet_ShentiStrong_s::write_to_pbmsg(::proto_ff::Sheet_ShentiStrong & msg) const {
	for(int32_t i = 0; i < (int32_t)E_ShentiStrong_List.size(); ++i) {
		::proto_ff::E_ShentiStrong* temp_e_shentistrong_list = msg.add_e_shentistrong_list();
		E_ShentiStrong_List[i].write_to_pbmsg(*temp_e_shentistrong_list);
	}
}

void Sheet_ShentiStrong_s::read_from_pbmsg(const ::proto_ff::Sheet_ShentiStrong & msg) {
	E_ShentiStrong_List.resize((int)msg.e_shentistrong_list_size() > (int)E_ShentiStrong_List.max_size() ? E_ShentiStrong_List.max_size() : msg.e_shentistrong_list_size());
	for(int32_t i = 0; i < (int32_t)E_ShentiStrong_List.size(); ++i) {
		const ::proto_ff::E_ShentiStrong & temp_e_shentistrong_list = msg.e_shentistrong_list(i);
		E_ShentiStrong_List[i].read_from_pbmsg(temp_e_shentistrong_list);
	}
}

E_ShentiEvolveAttributeDesc_s::E_ShentiEvolveAttributeDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_ShentiEvolveAttributeDesc_s::CreateInit() {
	m_value = (int32_t)0;
	m_type = (int32_t)0;
	return 0;
}

int E_ShentiEvolveAttributeDesc_s::ResumeInit() {
	return 0;
}

void E_ShentiEvolveAttributeDesc_s::write_to_pbmsg(::proto_ff::E_ShentiEvolveAttributeDesc & msg) const {
	msg.set_m_value((int32_t)m_value);
	msg.set_m_type((int32_t)m_type);
}

void E_ShentiEvolveAttributeDesc_s::read_from_pbmsg(const ::proto_ff::E_ShentiEvolveAttributeDesc & msg) {
	m_value = msg.m_value();
	m_type = msg.m_type();
}

E_ShentiEvolveXpcomDesc_s::E_ShentiEvolveXpcomDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_ShentiEvolveXpcomDesc_s::CreateInit() {
	m_weight = (int32_t)0;
	return 0;
}

int E_ShentiEvolveXpcomDesc_s::ResumeInit() {
	return 0;
}

void E_ShentiEvolveXpcomDesc_s::write_to_pbmsg(::proto_ff::E_ShentiEvolveXpcomDesc & msg) const {
	msg.set_m_weight((int32_t)m_weight);
}

void E_ShentiEvolveXpcomDesc_s::read_from_pbmsg(const ::proto_ff::E_ShentiEvolveXpcomDesc & msg) {
	m_weight = msg.m_weight();
}

E_ShentiEvolveXpstarDesc_s::E_ShentiEvolveXpstarDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_ShentiEvolveXpstarDesc_s::CreateInit() {
	m_weight = (int32_t)0;
	return 0;
}

int E_ShentiEvolveXpstarDesc_s::ResumeInit() {
	return 0;
}

void E_ShentiEvolveXpstarDesc_s::write_to_pbmsg(::proto_ff::E_ShentiEvolveXpstarDesc & msg) const {
	msg.set_m_weight((int32_t)m_weight);
}

void E_ShentiEvolveXpstarDesc_s::read_from_pbmsg(const ::proto_ff::E_ShentiEvolveXpstarDesc & msg) {
	m_weight = msg.m_weight();
}

E_ShentiEvolve_s::E_ShentiEvolve_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_ShentiEvolve_s::CreateInit() {
	m_id = (int32_t)0;
	m_evolveLv = (int32_t)0;
	m_remanieLv = (int32_t)0;
	m_need_quality = (int32_t)0;
	m_need_star = (int32_t)0;
	m_material_id = (int32_t)0;
	m_material_num = (int32_t)0;
	m_mallID = (int32_t)0;
	m_initialValue = (int32_t)0;
	m_specialStar = (int32_t)0;
	return 0;
}

int E_ShentiEvolve_s::ResumeInit() {
	return 0;
}

void E_ShentiEvolve_s::write_to_pbmsg(::proto_ff::E_ShentiEvolve & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_evolvelv((int32_t)m_evolveLv);
	msg.set_m_position(m_position.data());
	msg.set_m_remanielv((int32_t)m_remanieLv);
	msg.set_m_need_quality((int32_t)m_need_quality);
	msg.set_m_need_star((int32_t)m_need_star);
	msg.set_m_material_id((int32_t)m_material_id);
	msg.set_m_material_num((int32_t)m_material_num);
	msg.set_m_mallid((int32_t)m_mallID);
	msg.set_m_initialvalue((int32_t)m_initialValue);
	msg.set_m_specialstar((int32_t)m_specialStar);
	for(int32_t i = 0; i < (int32_t)m_attribute.size(); ++i) {
		::proto_ff::E_ShentiEvolveAttributeDesc* temp_m_attribute = msg.add_m_attribute();
		m_attribute[i].write_to_pbmsg(*temp_m_attribute);
	}
	for(int32_t i = 0; i < (int32_t)m_xpcom.size(); ++i) {
		::proto_ff::E_ShentiEvolveXpcomDesc* temp_m_xpcom = msg.add_m_xpcom();
		m_xpcom[i].write_to_pbmsg(*temp_m_xpcom);
	}
	for(int32_t i = 0; i < (int32_t)m_xpstar.size(); ++i) {
		::proto_ff::E_ShentiEvolveXpstarDesc* temp_m_xpstar = msg.add_m_xpstar();
		m_xpstar[i].write_to_pbmsg(*temp_m_xpstar);
	}
}

void E_ShentiEvolve_s::read_from_pbmsg(const ::proto_ff::E_ShentiEvolve & msg) {
	m_id = msg.m_id();
	m_evolveLv = msg.m_evolvelv();
	m_position = msg.m_position();
	m_remanieLv = msg.m_remanielv();
	m_need_quality = msg.m_need_quality();
	m_need_star = msg.m_need_star();
	m_material_id = msg.m_material_id();
	m_material_num = msg.m_material_num();
	m_mallID = msg.m_mallid();
	m_initialValue = msg.m_initialvalue();
	m_specialStar = msg.m_specialstar();
	m_attribute.resize((int)msg.m_attribute_size() > (int)m_attribute.max_size() ? m_attribute.max_size() : msg.m_attribute_size());
	for(int32_t i = 0; i < (int32_t)m_attribute.size(); ++i) {
		const ::proto_ff::E_ShentiEvolveAttributeDesc & temp_m_attribute = msg.m_attribute(i);
		m_attribute[i].read_from_pbmsg(temp_m_attribute);
	}
	m_xpcom.resize((int)msg.m_xpcom_size() > (int)m_xpcom.max_size() ? m_xpcom.max_size() : msg.m_xpcom_size());
	for(int32_t i = 0; i < (int32_t)m_xpcom.size(); ++i) {
		const ::proto_ff::E_ShentiEvolveXpcomDesc & temp_m_xpcom = msg.m_xpcom(i);
		m_xpcom[i].read_from_pbmsg(temp_m_xpcom);
	}
	m_xpstar.resize((int)msg.m_xpstar_size() > (int)m_xpstar.max_size() ? m_xpstar.max_size() : msg.m_xpstar_size());
	for(int32_t i = 0; i < (int32_t)m_xpstar.size(); ++i) {
		const ::proto_ff::E_ShentiEvolveXpstarDesc & temp_m_xpstar = msg.m_xpstar(i);
		m_xpstar[i].read_from_pbmsg(temp_m_xpstar);
	}
}

Sheet_ShentiEvolve_s::Sheet_ShentiEvolve_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_ShentiEvolve_s::CreateInit() {
	return 0;
}

int Sheet_ShentiEvolve_s::ResumeInit() {
	return 0;
}

void Sheet_ShentiEvolve_s::write_to_pbmsg(::proto_ff::Sheet_ShentiEvolve & msg) const {
	for(int32_t i = 0; i < (int32_t)E_ShentiEvolve_List.size(); ++i) {
		::proto_ff::E_ShentiEvolve* temp_e_shentievolve_list = msg.add_e_shentievolve_list();
		E_ShentiEvolve_List[i].write_to_pbmsg(*temp_e_shentievolve_list);
	}
}

void Sheet_ShentiEvolve_s::read_from_pbmsg(const ::proto_ff::Sheet_ShentiEvolve & msg) {
	E_ShentiEvolve_List.resize((int)msg.e_shentievolve_list_size() > (int)E_ShentiEvolve_List.max_size() ? E_ShentiEvolve_List.max_size() : msg.e_shentievolve_list_size());
	for(int32_t i = 0; i < (int32_t)E_ShentiEvolve_List.size(); ++i) {
		const ::proto_ff::E_ShentiEvolve & temp_e_shentievolve_list = msg.e_shentievolve_list(i);
		E_ShentiEvolve_List[i].read_from_pbmsg(temp_e_shentievolve_list);
	}
}

E_ShentiEvolveprogress_s::E_ShentiEvolveprogress_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_ShentiEvolveprogress_s::CreateInit() {
	m_id = (int32_t)0;
	m_evolveLv = (int32_t)0;
	m_remanieLv = (int32_t)0;
	m_equipQuality = (int32_t)0;
	m_equipStar = (int32_t)0;
	return 0;
}

int E_ShentiEvolveprogress_s::ResumeInit() {
	return 0;
}

void E_ShentiEvolveprogress_s::write_to_pbmsg(::proto_ff::E_ShentiEvolveprogress & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_evolvelv((int32_t)m_evolveLv);
	msg.set_m_remanielv((int32_t)m_remanieLv);
	msg.set_m_equipquality((int32_t)m_equipQuality);
	msg.set_m_equipstar((int32_t)m_equipStar);
	for(int32_t i = 0; i < (int32_t)m_evolve.size(); ++i) {
		msg.add_m_evolve((int32_t)m_evolve[i]);
	}
}

void E_ShentiEvolveprogress_s::read_from_pbmsg(const ::proto_ff::E_ShentiEvolveprogress & msg) {
	m_id = msg.m_id();
	m_evolveLv = msg.m_evolvelv();
	m_remanieLv = msg.m_remanielv();
	m_equipQuality = msg.m_equipquality();
	m_equipStar = msg.m_equipstar();
	m_evolve.resize((int)msg.m_evolve_size() > (int)m_evolve.max_size() ? m_evolve.max_size() : msg.m_evolve_size());
	for(int32_t i = 0; i < (int32_t)m_evolve.size(); ++i) {
		m_evolve[i] = msg.m_evolve(i);
	}
}

Sheet_ShentiEvolveprogress_s::Sheet_ShentiEvolveprogress_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_ShentiEvolveprogress_s::CreateInit() {
	return 0;
}

int Sheet_ShentiEvolveprogress_s::ResumeInit() {
	return 0;
}

void Sheet_ShentiEvolveprogress_s::write_to_pbmsg(::proto_ff::Sheet_ShentiEvolveprogress & msg) const {
	for(int32_t i = 0; i < (int32_t)E_ShentiEvolveprogress_List.size(); ++i) {
		::proto_ff::E_ShentiEvolveprogress* temp_e_shentievolveprogress_list = msg.add_e_shentievolveprogress_list();
		E_ShentiEvolveprogress_List[i].write_to_pbmsg(*temp_e_shentievolveprogress_list);
	}
}

void Sheet_ShentiEvolveprogress_s::read_from_pbmsg(const ::proto_ff::Sheet_ShentiEvolveprogress & msg) {
	E_ShentiEvolveprogress_List.resize((int)msg.e_shentievolveprogress_list_size() > (int)E_ShentiEvolveprogress_List.max_size() ? E_ShentiEvolveprogress_List.max_size() : msg.e_shentievolveprogress_list_size());
	for(int32_t i = 0; i < (int32_t)E_ShentiEvolveprogress_List.size(); ++i) {
		const ::proto_ff::E_ShentiEvolveprogress & temp_e_shentievolveprogress_list = msg.e_shentievolveprogress_list(i);
		E_ShentiEvolveprogress_List[i].read_from_pbmsg(temp_e_shentievolveprogress_list);
	}
}

E_ShentiStarlibraryXpcomDesc_s::E_ShentiStarlibraryXpcomDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_ShentiStarlibraryXpcomDesc_s::CreateInit() {
	m_value = (int32_t)0;
	m_type = (int32_t)0;
	return 0;
}

int E_ShentiStarlibraryXpcomDesc_s::ResumeInit() {
	return 0;
}

void E_ShentiStarlibraryXpcomDesc_s::write_to_pbmsg(::proto_ff::E_ShentiStarlibraryXpcomDesc & msg) const {
	msg.set_m_value((int32_t)m_value);
	msg.set_m_type((int32_t)m_type);
}

void E_ShentiStarlibraryXpcomDesc_s::read_from_pbmsg(const ::proto_ff::E_ShentiStarlibraryXpcomDesc & msg) {
	m_value = msg.m_value();
	m_type = msg.m_type();
}

E_ShentiStarlibraryXpstarDesc_s::E_ShentiStarlibraryXpstarDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_ShentiStarlibraryXpstarDesc_s::CreateInit() {
	m_value = (int32_t)0;
	m_type = (int32_t)0;
	return 0;
}

int E_ShentiStarlibraryXpstarDesc_s::ResumeInit() {
	return 0;
}

void E_ShentiStarlibraryXpstarDesc_s::write_to_pbmsg(::proto_ff::E_ShentiStarlibraryXpstarDesc & msg) const {
	msg.set_m_value((int32_t)m_value);
	msg.set_m_type((int32_t)m_type);
}

void E_ShentiStarlibraryXpstarDesc_s::read_from_pbmsg(const ::proto_ff::E_ShentiStarlibraryXpstarDesc & msg) {
	m_value = msg.m_value();
	m_type = msg.m_type();
}

E_ShentiStarlibrary_s::E_ShentiStarlibrary_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_ShentiStarlibrary_s::CreateInit() {
	m_starGroup = (int32_t)0;
	return 0;
}

int E_ShentiStarlibrary_s::ResumeInit() {
	return 0;
}

void E_ShentiStarlibrary_s::write_to_pbmsg(::proto_ff::E_ShentiStarlibrary & msg) const {
	msg.set_m_stargroup((int32_t)m_starGroup);
	for(int32_t i = 0; i < (int32_t)m_xpcom.size(); ++i) {
		::proto_ff::E_ShentiStarlibraryXpcomDesc* temp_m_xpcom = msg.add_m_xpcom();
		m_xpcom[i].write_to_pbmsg(*temp_m_xpcom);
	}
	for(int32_t i = 0; i < (int32_t)m_xpstar.size(); ++i) {
		::proto_ff::E_ShentiStarlibraryXpstarDesc* temp_m_xpstar = msg.add_m_xpstar();
		m_xpstar[i].write_to_pbmsg(*temp_m_xpstar);
	}
}

void E_ShentiStarlibrary_s::read_from_pbmsg(const ::proto_ff::E_ShentiStarlibrary & msg) {
	m_starGroup = msg.m_stargroup();
	m_xpcom.resize((int)msg.m_xpcom_size() > (int)m_xpcom.max_size() ? m_xpcom.max_size() : msg.m_xpcom_size());
	for(int32_t i = 0; i < (int32_t)m_xpcom.size(); ++i) {
		const ::proto_ff::E_ShentiStarlibraryXpcomDesc & temp_m_xpcom = msg.m_xpcom(i);
		m_xpcom[i].read_from_pbmsg(temp_m_xpcom);
	}
	m_xpstar.resize((int)msg.m_xpstar_size() > (int)m_xpstar.max_size() ? m_xpstar.max_size() : msg.m_xpstar_size());
	for(int32_t i = 0; i < (int32_t)m_xpstar.size(); ++i) {
		const ::proto_ff::E_ShentiStarlibraryXpstarDesc & temp_m_xpstar = msg.m_xpstar(i);
		m_xpstar[i].read_from_pbmsg(temp_m_xpstar);
	}
}

Sheet_ShentiStarlibrary_s::Sheet_ShentiStarlibrary_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_ShentiStarlibrary_s::CreateInit() {
	return 0;
}

int Sheet_ShentiStarlibrary_s::ResumeInit() {
	return 0;
}

void Sheet_ShentiStarlibrary_s::write_to_pbmsg(::proto_ff::Sheet_ShentiStarlibrary & msg) const {
	for(int32_t i = 0; i < (int32_t)E_ShentiStarlibrary_List.size(); ++i) {
		::proto_ff::E_ShentiStarlibrary* temp_e_shentistarlibrary_list = msg.add_e_shentistarlibrary_list();
		E_ShentiStarlibrary_List[i].write_to_pbmsg(*temp_e_shentistarlibrary_list);
	}
}

void Sheet_ShentiStarlibrary_s::read_from_pbmsg(const ::proto_ff::Sheet_ShentiStarlibrary & msg) {
	E_ShentiStarlibrary_List.resize((int)msg.e_shentistarlibrary_list_size() > (int)E_ShentiStarlibrary_List.max_size() ? E_ShentiStarlibrary_List.max_size() : msg.e_shentistarlibrary_list_size());
	for(int32_t i = 0; i < (int32_t)E_ShentiStarlibrary_List.size(); ++i) {
		const ::proto_ff::E_ShentiStarlibrary & temp_e_shentistarlibrary_list = msg.e_shentistarlibrary_list(i);
		E_ShentiStarlibrary_List[i].read_from_pbmsg(temp_e_shentistarlibrary_list);
	}
}

E_ShentiAwakenAttributeDesc_s::E_ShentiAwakenAttributeDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_ShentiAwakenAttributeDesc_s::CreateInit() {
	m_value = (int32_t)0;
	m_type = (int32_t)0;
	return 0;
}

int E_ShentiAwakenAttributeDesc_s::ResumeInit() {
	return 0;
}

void E_ShentiAwakenAttributeDesc_s::write_to_pbmsg(::proto_ff::E_ShentiAwakenAttributeDesc & msg) const {
	msg.set_m_value((int32_t)m_value);
	msg.set_m_type((int32_t)m_type);
}

void E_ShentiAwakenAttributeDesc_s::read_from_pbmsg(const ::proto_ff::E_ShentiAwakenAttributeDesc & msg) {
	m_value = msg.m_value();
	m_type = msg.m_type();
}

E_ShentiAwakenAfflatusattDesc_s::E_ShentiAwakenAfflatusattDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_ShentiAwakenAfflatusattDesc_s::CreateInit() {
	m_value = (int32_t)0;
	m_type = (int32_t)0;
	return 0;
}

int E_ShentiAwakenAfflatusattDesc_s::ResumeInit() {
	return 0;
}

void E_ShentiAwakenAfflatusattDesc_s::write_to_pbmsg(::proto_ff::E_ShentiAwakenAfflatusattDesc & msg) const {
	msg.set_m_value((int32_t)m_value);
	msg.set_m_type((int32_t)m_type);
}

void E_ShentiAwakenAfflatusattDesc_s::read_from_pbmsg(const ::proto_ff::E_ShentiAwakenAfflatusattDesc & msg) {
	m_value = msg.m_value();
	m_type = msg.m_type();
}

E_ShentiAwaken_s::E_ShentiAwaken_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_ShentiAwaken_s::CreateInit() {
	m_id = (int32_t)0;
	m_awakenLv = (int32_t)0;
	m_remanieLv = (int32_t)0;
	m_need_quality = (int32_t)0;
	m_need_star = (int32_t)0;
	m_material_id = (int32_t)0;
	m_material_num = (int32_t)0;
	m_mallID = (int32_t)0;
	m_initialValue = (int32_t)0;
	return 0;
}

int E_ShentiAwaken_s::ResumeInit() {
	return 0;
}

void E_ShentiAwaken_s::write_to_pbmsg(::proto_ff::E_ShentiAwaken & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_awakenlv((int32_t)m_awakenLv);
	msg.set_m_position(m_position.data());
	msg.set_m_remanielv((int32_t)m_remanieLv);
	msg.set_m_need_quality((int32_t)m_need_quality);
	msg.set_m_need_star((int32_t)m_need_star);
	msg.set_m_material_id((int32_t)m_material_id);
	msg.set_m_material_num((int32_t)m_material_num);
	msg.set_m_mallid((int32_t)m_mallID);
	msg.set_m_initialvalue((int32_t)m_initialValue);
	for(int32_t i = 0; i < (int32_t)m_attribute.size(); ++i) {
		::proto_ff::E_ShentiAwakenAttributeDesc* temp_m_attribute = msg.add_m_attribute();
		m_attribute[i].write_to_pbmsg(*temp_m_attribute);
	}
	for(int32_t i = 0; i < (int32_t)m_afflatusAtt.size(); ++i) {
		::proto_ff::E_ShentiAwakenAfflatusattDesc* temp_m_afflatusatt = msg.add_m_afflatusatt();
		m_afflatusAtt[i].write_to_pbmsg(*temp_m_afflatusatt);
	}
}

void E_ShentiAwaken_s::read_from_pbmsg(const ::proto_ff::E_ShentiAwaken & msg) {
	m_id = msg.m_id();
	m_awakenLv = msg.m_awakenlv();
	m_position = msg.m_position();
	m_remanieLv = msg.m_remanielv();
	m_need_quality = msg.m_need_quality();
	m_need_star = msg.m_need_star();
	m_material_id = msg.m_material_id();
	m_material_num = msg.m_material_num();
	m_mallID = msg.m_mallid();
	m_initialValue = msg.m_initialvalue();
	m_attribute.resize((int)msg.m_attribute_size() > (int)m_attribute.max_size() ? m_attribute.max_size() : msg.m_attribute_size());
	for(int32_t i = 0; i < (int32_t)m_attribute.size(); ++i) {
		const ::proto_ff::E_ShentiAwakenAttributeDesc & temp_m_attribute = msg.m_attribute(i);
		m_attribute[i].read_from_pbmsg(temp_m_attribute);
	}
	m_afflatusAtt.resize((int)msg.m_afflatusatt_size() > (int)m_afflatusAtt.max_size() ? m_afflatusAtt.max_size() : msg.m_afflatusatt_size());
	for(int32_t i = 0; i < (int32_t)m_afflatusAtt.size(); ++i) {
		const ::proto_ff::E_ShentiAwakenAfflatusattDesc & temp_m_afflatusatt = msg.m_afflatusatt(i);
		m_afflatusAtt[i].read_from_pbmsg(temp_m_afflatusatt);
	}
}

Sheet_ShentiAwaken_s::Sheet_ShentiAwaken_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_ShentiAwaken_s::CreateInit() {
	return 0;
}

int Sheet_ShentiAwaken_s::ResumeInit() {
	return 0;
}

void Sheet_ShentiAwaken_s::write_to_pbmsg(::proto_ff::Sheet_ShentiAwaken & msg) const {
	for(int32_t i = 0; i < (int32_t)E_ShentiAwaken_List.size(); ++i) {
		::proto_ff::E_ShentiAwaken* temp_e_shentiawaken_list = msg.add_e_shentiawaken_list();
		E_ShentiAwaken_List[i].write_to_pbmsg(*temp_e_shentiawaken_list);
	}
}

void Sheet_ShentiAwaken_s::read_from_pbmsg(const ::proto_ff::Sheet_ShentiAwaken & msg) {
	E_ShentiAwaken_List.resize((int)msg.e_shentiawaken_list_size() > (int)E_ShentiAwaken_List.max_size() ? E_ShentiAwaken_List.max_size() : msg.e_shentiawaken_list_size());
	for(int32_t i = 0; i < (int32_t)E_ShentiAwaken_List.size(); ++i) {
		const ::proto_ff::E_ShentiAwaken & temp_e_shentiawaken_list = msg.e_shentiawaken_list(i);
		E_ShentiAwaken_List[i].read_from_pbmsg(temp_e_shentiawaken_list);
	}
}

E_ShentiAwakenprogress_s::E_ShentiAwakenprogress_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_ShentiAwakenprogress_s::CreateInit() {
	m_id = (int32_t)0;
	m_awakenLv = (int32_t)0;
	m_remanieLv = (int32_t)0;
	m_equipQuality = (int32_t)0;
	m_equipStar = (int32_t)0;
	return 0;
}

int E_ShentiAwakenprogress_s::ResumeInit() {
	return 0;
}

void E_ShentiAwakenprogress_s::write_to_pbmsg(::proto_ff::E_ShentiAwakenprogress & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_awakenlv((int32_t)m_awakenLv);
	msg.set_m_remanielv((int32_t)m_remanieLv);
	msg.set_m_equipquality((int32_t)m_equipQuality);
	msg.set_m_equipstar((int32_t)m_equipStar);
	for(int32_t i = 0; i < (int32_t)m_awaken.size(); ++i) {
		msg.add_m_awaken((int32_t)m_awaken[i]);
	}
}

void E_ShentiAwakenprogress_s::read_from_pbmsg(const ::proto_ff::E_ShentiAwakenprogress & msg) {
	m_id = msg.m_id();
	m_awakenLv = msg.m_awakenlv();
	m_remanieLv = msg.m_remanielv();
	m_equipQuality = msg.m_equipquality();
	m_equipStar = msg.m_equipstar();
	m_awaken.resize((int)msg.m_awaken_size() > (int)m_awaken.max_size() ? m_awaken.max_size() : msg.m_awaken_size());
	for(int32_t i = 0; i < (int32_t)m_awaken.size(); ++i) {
		m_awaken[i] = msg.m_awaken(i);
	}
}

Sheet_ShentiAwakenprogress_s::Sheet_ShentiAwakenprogress_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_ShentiAwakenprogress_s::CreateInit() {
	return 0;
}

int Sheet_ShentiAwakenprogress_s::ResumeInit() {
	return 0;
}

void Sheet_ShentiAwakenprogress_s::write_to_pbmsg(::proto_ff::Sheet_ShentiAwakenprogress & msg) const {
	for(int32_t i = 0; i < (int32_t)E_ShentiAwakenprogress_List.size(); ++i) {
		::proto_ff::E_ShentiAwakenprogress* temp_e_shentiawakenprogress_list = msg.add_e_shentiawakenprogress_list();
		E_ShentiAwakenprogress_List[i].write_to_pbmsg(*temp_e_shentiawakenprogress_list);
	}
}

void Sheet_ShentiAwakenprogress_s::read_from_pbmsg(const ::proto_ff::Sheet_ShentiAwakenprogress & msg) {
	E_ShentiAwakenprogress_List.resize((int)msg.e_shentiawakenprogress_list_size() > (int)E_ShentiAwakenprogress_List.max_size() ? E_ShentiAwakenprogress_List.max_size() : msg.e_shentiawakenprogress_list_size());
	for(int32_t i = 0; i < (int32_t)E_ShentiAwakenprogress_List.size(); ++i) {
		const ::proto_ff::E_ShentiAwakenprogress & temp_e_shentiawakenprogress_list = msg.e_shentiawakenprogress_list(i);
		E_ShentiAwakenprogress_List[i].read_from_pbmsg(temp_e_shentiawakenprogress_list);
	}
}

E_ShentiSuitAttributeDesc_s::E_ShentiSuitAttributeDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_ShentiSuitAttributeDesc_s::CreateInit() {
	m_value = (int32_t)0;
	m_type = (int32_t)0;
	return 0;
}

int E_ShentiSuitAttributeDesc_s::ResumeInit() {
	return 0;
}

void E_ShentiSuitAttributeDesc_s::write_to_pbmsg(::proto_ff::E_ShentiSuitAttributeDesc & msg) const {
	msg.set_m_value((int32_t)m_value);
	msg.set_m_type((int32_t)m_type);
}

void E_ShentiSuitAttributeDesc_s::read_from_pbmsg(const ::proto_ff::E_ShentiSuitAttributeDesc & msg) {
	m_value = msg.m_value();
	m_type = msg.m_type();
}

E_ShentiSuit_s::E_ShentiSuit_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_ShentiSuit_s::CreateInit() {
	m_id = (int32_t)0;
	m_suitGroup = (int32_t)0;
	m_suitLv = (int32_t)0;
	m_num = (int32_t)0;
	m_skill = (int32_t)0;
	return 0;
}

int E_ShentiSuit_s::ResumeInit() {
	return 0;
}

void E_ShentiSuit_s::write_to_pbmsg(::proto_ff::E_ShentiSuit & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_suitgroup((int32_t)m_suitGroup);
	msg.set_m_suitlv((int32_t)m_suitLv);
	msg.set_m_num((int32_t)m_num);
	msg.set_m_name(m_name.data());
	msg.set_m_skill((int32_t)m_skill);
	for(int32_t i = 0; i < (int32_t)m_attribute.size(); ++i) {
		::proto_ff::E_ShentiSuitAttributeDesc* temp_m_attribute = msg.add_m_attribute();
		m_attribute[i].write_to_pbmsg(*temp_m_attribute);
	}
}

void E_ShentiSuit_s::read_from_pbmsg(const ::proto_ff::E_ShentiSuit & msg) {
	m_id = msg.m_id();
	m_suitGroup = msg.m_suitgroup();
	m_suitLv = msg.m_suitlv();
	m_num = msg.m_num();
	m_name = msg.m_name();
	m_skill = msg.m_skill();
	m_attribute.resize((int)msg.m_attribute_size() > (int)m_attribute.max_size() ? m_attribute.max_size() : msg.m_attribute_size());
	for(int32_t i = 0; i < (int32_t)m_attribute.size(); ++i) {
		const ::proto_ff::E_ShentiSuitAttributeDesc & temp_m_attribute = msg.m_attribute(i);
		m_attribute[i].read_from_pbmsg(temp_m_attribute);
	}
}

Sheet_ShentiSuit_s::Sheet_ShentiSuit_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_ShentiSuit_s::CreateInit() {
	return 0;
}

int Sheet_ShentiSuit_s::ResumeInit() {
	return 0;
}

void Sheet_ShentiSuit_s::write_to_pbmsg(::proto_ff::Sheet_ShentiSuit & msg) const {
	for(int32_t i = 0; i < (int32_t)E_ShentiSuit_List.size(); ++i) {
		::proto_ff::E_ShentiSuit* temp_e_shentisuit_list = msg.add_e_shentisuit_list();
		E_ShentiSuit_List[i].write_to_pbmsg(*temp_e_shentisuit_list);
	}
}

void Sheet_ShentiSuit_s::read_from_pbmsg(const ::proto_ff::Sheet_ShentiSuit & msg) {
	E_ShentiSuit_List.resize((int)msg.e_shentisuit_list_size() > (int)E_ShentiSuit_List.max_size() ? E_ShentiSuit_List.max_size() : msg.e_shentisuit_list_size());
	for(int32_t i = 0; i < (int32_t)E_ShentiSuit_List.size(); ++i) {
		const ::proto_ff::E_ShentiSuit & temp_e_shentisuit_list = msg.e_shentisuit_list(i);
		E_ShentiSuit_List[i].read_from_pbmsg(temp_e_shentisuit_list);
	}
}

E_ShentiCompose_s::E_ShentiCompose_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_ShentiCompose_s::CreateInit() {
	m_need_equip = (int32_t)0;
	m_target_equip = (int32_t)0;
	m_compose_tips = (int32_t)0;
	return 0;
}

int E_ShentiCompose_s::ResumeInit() {
	return 0;
}

void E_ShentiCompose_s::write_to_pbmsg(::proto_ff::E_ShentiCompose & msg) const {
	msg.set_m_need_equip((int32_t)m_need_equip);
	msg.set_m_target_equip((int32_t)m_target_equip);
	msg.set_m_compose_tips((int32_t)m_compose_tips);
}

void E_ShentiCompose_s::read_from_pbmsg(const ::proto_ff::E_ShentiCompose & msg) {
	m_need_equip = msg.m_need_equip();
	m_target_equip = msg.m_target_equip();
	m_compose_tips = msg.m_compose_tips();
}

Sheet_ShentiCompose_s::Sheet_ShentiCompose_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_ShentiCompose_s::CreateInit() {
	return 0;
}

int Sheet_ShentiCompose_s::ResumeInit() {
	return 0;
}

void Sheet_ShentiCompose_s::write_to_pbmsg(::proto_ff::Sheet_ShentiCompose & msg) const {
	for(int32_t i = 0; i < (int32_t)E_ShentiCompose_List.size(); ++i) {
		::proto_ff::E_ShentiCompose* temp_e_shenticompose_list = msg.add_e_shenticompose_list();
		E_ShentiCompose_List[i].write_to_pbmsg(*temp_e_shenticompose_list);
	}
}

void Sheet_ShentiCompose_s::read_from_pbmsg(const ::proto_ff::Sheet_ShentiCompose & msg) {
	E_ShentiCompose_List.resize((int)msg.e_shenticompose_list_size() > (int)E_ShentiCompose_List.max_size() ? E_ShentiCompose_List.max_size() : msg.e_shenticompose_list_size());
	for(int32_t i = 0; i < (int32_t)E_ShentiCompose_List.size(); ++i) {
		const ::proto_ff::E_ShentiCompose & temp_e_shenticompose_list = msg.e_shenticompose_list(i);
		E_ShentiCompose_List[i].read_from_pbmsg(temp_e_shenticompose_list);
	}
}

E_ShentiStar_upMaterialDesc_s::E_ShentiStar_upMaterialDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_ShentiStar_upMaterialDesc_s::CreateInit() {
	m_num = (int32_t)0;
	m_id = (int32_t)0;
	return 0;
}

int E_ShentiStar_upMaterialDesc_s::ResumeInit() {
	return 0;
}

void E_ShentiStar_upMaterialDesc_s::write_to_pbmsg(::proto_ff::E_ShentiStar_upMaterialDesc & msg) const {
	msg.set_m_num((int32_t)m_num);
	msg.set_m_id((int32_t)m_id);
}

void E_ShentiStar_upMaterialDesc_s::read_from_pbmsg(const ::proto_ff::E_ShentiStar_upMaterialDesc & msg) {
	m_num = msg.m_num();
	m_id = msg.m_id();
}

E_ShentiStar_upXpstarDesc_s::E_ShentiStar_upXpstarDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_ShentiStar_upXpstarDesc_s::CreateInit() {
	m_weight = (int32_t)0;
	return 0;
}

int E_ShentiStar_upXpstarDesc_s::ResumeInit() {
	return 0;
}

void E_ShentiStar_upXpstarDesc_s::write_to_pbmsg(::proto_ff::E_ShentiStar_upXpstarDesc & msg) const {
	msg.set_m_weight((int32_t)m_weight);
}

void E_ShentiStar_upXpstarDesc_s::read_from_pbmsg(const ::proto_ff::E_ShentiStar_upXpstarDesc & msg) {
	m_weight = msg.m_weight();
}

E_ShentiStar_up_s::E_ShentiStar_up_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_ShentiStar_up_s::CreateInit() {
	m_id = (int32_t)0;
	m_star = (int32_t)0;
	m_position = (int32_t)0;
	m_need_quality = (int32_t)0;
	return 0;
}

int E_ShentiStar_up_s::ResumeInit() {
	return 0;
}

void E_ShentiStar_up_s::write_to_pbmsg(::proto_ff::E_ShentiStar_up & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_star((int32_t)m_star);
	msg.set_m_position((int32_t)m_position);
	msg.set_m_need_quality((int32_t)m_need_quality);
	for(int32_t i = 0; i < (int32_t)m_material.size(); ++i) {
		::proto_ff::E_ShentiStar_upMaterialDesc* temp_m_material = msg.add_m_material();
		m_material[i].write_to_pbmsg(*temp_m_material);
	}
	for(int32_t i = 0; i < (int32_t)m_xpstar.size(); ++i) {
		::proto_ff::E_ShentiStar_upXpstarDesc* temp_m_xpstar = msg.add_m_xpstar();
		m_xpstar[i].write_to_pbmsg(*temp_m_xpstar);
	}
}

void E_ShentiStar_up_s::read_from_pbmsg(const ::proto_ff::E_ShentiStar_up & msg) {
	m_id = msg.m_id();
	m_star = msg.m_star();
	m_position = msg.m_position();
	m_need_quality = msg.m_need_quality();
	m_material.resize((int)msg.m_material_size() > (int)m_material.max_size() ? m_material.max_size() : msg.m_material_size());
	for(int32_t i = 0; i < (int32_t)m_material.size(); ++i) {
		const ::proto_ff::E_ShentiStar_upMaterialDesc & temp_m_material = msg.m_material(i);
		m_material[i].read_from_pbmsg(temp_m_material);
	}
	m_xpstar.resize((int)msg.m_xpstar_size() > (int)m_xpstar.max_size() ? m_xpstar.max_size() : msg.m_xpstar_size());
	for(int32_t i = 0; i < (int32_t)m_xpstar.size(); ++i) {
		const ::proto_ff::E_ShentiStar_upXpstarDesc & temp_m_xpstar = msg.m_xpstar(i);
		m_xpstar[i].read_from_pbmsg(temp_m_xpstar);
	}
}

Sheet_ShentiStar_up_s::Sheet_ShentiStar_up_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_ShentiStar_up_s::CreateInit() {
	return 0;
}

int Sheet_ShentiStar_up_s::ResumeInit() {
	return 0;
}

void Sheet_ShentiStar_up_s::write_to_pbmsg(::proto_ff::Sheet_ShentiStar_up & msg) const {
	for(int32_t i = 0; i < (int32_t)E_ShentiStar_up_List.size(); ++i) {
		::proto_ff::E_ShentiStar_up* temp_e_shentistar_up_list = msg.add_e_shentistar_up_list();
		E_ShentiStar_up_List[i].write_to_pbmsg(*temp_e_shentistar_up_list);
	}
}

void Sheet_ShentiStar_up_s::read_from_pbmsg(const ::proto_ff::Sheet_ShentiStar_up & msg) {
	E_ShentiStar_up_List.resize((int)msg.e_shentistar_up_list_size() > (int)E_ShentiStar_up_List.max_size() ? E_ShentiStar_up_List.max_size() : msg.e_shentistar_up_list_size());
	for(int32_t i = 0; i < (int32_t)E_ShentiStar_up_List.size(); ++i) {
		const ::proto_ff::E_ShentiStar_up & temp_e_shentistar_up_list = msg.e_shentistar_up_list(i);
		E_ShentiStar_up_List[i].read_from_pbmsg(temp_e_shentistar_up_list);
	}
}

E_ShentiStrengtitelAttributeDesc_s::E_ShentiStrengtitelAttributeDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_ShentiStrengtitelAttributeDesc_s::CreateInit() {
	m_value = (int32_t)0;
	m_type = (int32_t)0;
	return 0;
}

int E_ShentiStrengtitelAttributeDesc_s::ResumeInit() {
	return 0;
}

void E_ShentiStrengtitelAttributeDesc_s::write_to_pbmsg(::proto_ff::E_ShentiStrengtitelAttributeDesc & msg) const {
	msg.set_m_value((int32_t)m_value);
	msg.set_m_type((int32_t)m_type);
}

void E_ShentiStrengtitelAttributeDesc_s::read_from_pbmsg(const ::proto_ff::E_ShentiStrengtitelAttributeDesc & msg) {
	m_value = msg.m_value();
	m_type = msg.m_type();
}

E_ShentiStrengtitel_s::E_ShentiStrengtitel_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_ShentiStrengtitel_s::CreateInit() {
	m_id = (int32_t)0;
	m_remanieLv = (int32_t)0;
	m_strengLv = (int32_t)0;
	return 0;
}

int E_ShentiStrengtitel_s::ResumeInit() {
	return 0;
}

void E_ShentiStrengtitel_s::write_to_pbmsg(::proto_ff::E_ShentiStrengtitel & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_remanielv((int32_t)m_remanieLv);
	msg.set_m_strenglv((int32_t)m_strengLv);
	for(int32_t i = 0; i < (int32_t)m_attribute.size(); ++i) {
		::proto_ff::E_ShentiStrengtitelAttributeDesc* temp_m_attribute = msg.add_m_attribute();
		m_attribute[i].write_to_pbmsg(*temp_m_attribute);
	}
}

void E_ShentiStrengtitel_s::read_from_pbmsg(const ::proto_ff::E_ShentiStrengtitel & msg) {
	m_id = msg.m_id();
	m_remanieLv = msg.m_remanielv();
	m_strengLv = msg.m_strenglv();
	m_attribute.resize((int)msg.m_attribute_size() > (int)m_attribute.max_size() ? m_attribute.max_size() : msg.m_attribute_size());
	for(int32_t i = 0; i < (int32_t)m_attribute.size(); ++i) {
		const ::proto_ff::E_ShentiStrengtitelAttributeDesc & temp_m_attribute = msg.m_attribute(i);
		m_attribute[i].read_from_pbmsg(temp_m_attribute);
	}
}

Sheet_ShentiStrengtitel_s::Sheet_ShentiStrengtitel_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_ShentiStrengtitel_s::CreateInit() {
	return 0;
}

int Sheet_ShentiStrengtitel_s::ResumeInit() {
	return 0;
}

void Sheet_ShentiStrengtitel_s::write_to_pbmsg(::proto_ff::Sheet_ShentiStrengtitel & msg) const {
	for(int32_t i = 0; i < (int32_t)E_ShentiStrengtitel_List.size(); ++i) {
		::proto_ff::E_ShentiStrengtitel* temp_e_shentistrengtitel_list = msg.add_e_shentistrengtitel_list();
		E_ShentiStrengtitel_List[i].write_to_pbmsg(*temp_e_shentistrengtitel_list);
	}
}

void Sheet_ShentiStrengtitel_s::read_from_pbmsg(const ::proto_ff::Sheet_ShentiStrengtitel & msg) {
	E_ShentiStrengtitel_List.resize((int)msg.e_shentistrengtitel_list_size() > (int)E_ShentiStrengtitel_List.max_size() ? E_ShentiStrengtitel_List.max_size() : msg.e_shentistrengtitel_list_size());
	for(int32_t i = 0; i < (int32_t)E_ShentiStrengtitel_List.size(); ++i) {
		const ::proto_ff::E_ShentiStrengtitel & temp_e_shentistrengtitel_list = msg.e_shentistrengtitel_list(i);
		E_ShentiStrengtitel_List[i].read_from_pbmsg(temp_e_shentistrengtitel_list);
	}
}

E_ShentiStartitelAttributeDesc_s::E_ShentiStartitelAttributeDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_ShentiStartitelAttributeDesc_s::CreateInit() {
	m_value = (int32_t)0;
	m_type = (int32_t)0;
	return 0;
}

int E_ShentiStartitelAttributeDesc_s::ResumeInit() {
	return 0;
}

void E_ShentiStartitelAttributeDesc_s::write_to_pbmsg(::proto_ff::E_ShentiStartitelAttributeDesc & msg) const {
	msg.set_m_value((int32_t)m_value);
	msg.set_m_type((int32_t)m_type);
}

void E_ShentiStartitelAttributeDesc_s::read_from_pbmsg(const ::proto_ff::E_ShentiStartitelAttributeDesc & msg) {
	m_value = msg.m_value();
	m_type = msg.m_type();
}

E_ShentiStartitel_s::E_ShentiStartitel_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_ShentiStartitel_s::CreateInit() {
	m_id = (int32_t)0;
	m_num = (int32_t)0;
	return 0;
}

int E_ShentiStartitel_s::ResumeInit() {
	return 0;
}

void E_ShentiStartitel_s::write_to_pbmsg(::proto_ff::E_ShentiStartitel & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_num((int32_t)m_num);
	for(int32_t i = 0; i < (int32_t)m_attribute.size(); ++i) {
		::proto_ff::E_ShentiStartitelAttributeDesc* temp_m_attribute = msg.add_m_attribute();
		m_attribute[i].write_to_pbmsg(*temp_m_attribute);
	}
}

void E_ShentiStartitel_s::read_from_pbmsg(const ::proto_ff::E_ShentiStartitel & msg) {
	m_id = msg.m_id();
	m_num = msg.m_num();
	m_attribute.resize((int)msg.m_attribute_size() > (int)m_attribute.max_size() ? m_attribute.max_size() : msg.m_attribute_size());
	for(int32_t i = 0; i < (int32_t)m_attribute.size(); ++i) {
		const ::proto_ff::E_ShentiStartitelAttributeDesc & temp_m_attribute = msg.m_attribute(i);
		m_attribute[i].read_from_pbmsg(temp_m_attribute);
	}
}

Sheet_ShentiStartitel_s::Sheet_ShentiStartitel_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_ShentiStartitel_s::CreateInit() {
	return 0;
}

int Sheet_ShentiStartitel_s::ResumeInit() {
	return 0;
}

void Sheet_ShentiStartitel_s::write_to_pbmsg(::proto_ff::Sheet_ShentiStartitel & msg) const {
	for(int32_t i = 0; i < (int32_t)E_ShentiStartitel_List.size(); ++i) {
		::proto_ff::E_ShentiStartitel* temp_e_shentistartitel_list = msg.add_e_shentistartitel_list();
		E_ShentiStartitel_List[i].write_to_pbmsg(*temp_e_shentistartitel_list);
	}
}

void Sheet_ShentiStartitel_s::read_from_pbmsg(const ::proto_ff::Sheet_ShentiStartitel & msg) {
	E_ShentiStartitel_List.resize((int)msg.e_shentistartitel_list_size() > (int)E_ShentiStartitel_List.max_size() ? E_ShentiStartitel_List.max_size() : msg.e_shentistartitel_list_size());
	for(int32_t i = 0; i < (int32_t)E_ShentiStartitel_List.size(); ++i) {
		const ::proto_ff::E_ShentiStartitel & temp_e_shentistartitel_list = msg.e_shentistartitel_list(i);
		E_ShentiStartitel_List[i].read_from_pbmsg(temp_e_shentistartitel_list);
	}
}

}
