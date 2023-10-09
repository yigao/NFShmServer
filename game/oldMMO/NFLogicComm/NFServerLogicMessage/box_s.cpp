#include "box_s.h"

namespace proto_ff_s {

E_BoxBoxBoxdataDesc_s::E_BoxBoxBoxdataDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_BoxBoxBoxdataDesc_s::CreateInit() {
	m_maxtimes = (int32_t)0;
	m_id = (int64_t)0;
	m_weight = (int32_t)0;
	m_mintimes = (int32_t)0;
	return 0;
}

int E_BoxBoxBoxdataDesc_s::ResumeInit() {
	return 0;
}

void E_BoxBoxBoxdataDesc_s::write_to_pbmsg(::proto_ff::E_BoxBoxBoxdataDesc & msg) const {
	msg.set_m_maxtimes((int32_t)m_maxtimes);
	msg.set_m_id((int64_t)m_id);
	msg.set_m_weight((int32_t)m_weight);
	msg.set_m_mintimes((int32_t)m_mintimes);
}

void E_BoxBoxBoxdataDesc_s::read_from_pbmsg(const ::proto_ff::E_BoxBoxBoxdataDesc & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct E_BoxBoxBoxdataDesc_s));
	m_maxtimes = msg.m_maxtimes();
	m_id = msg.m_id();
	m_weight = msg.m_weight();
	m_mintimes = msg.m_mintimes();
}

E_BoxBox_s::E_BoxBox_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_BoxBox_s::CreateInit() {
	m_id = (int64_t)0;
	m_type = (int32_t)0;
	m_rate = (int32_t)0;
	m_mask = (int32_t)0;
	m_mintimes = (int32_t)0;
	m_maxtimes = (int32_t)0;
	return 0;
}

int E_BoxBox_s::ResumeInit() {
	return 0;
}

void E_BoxBox_s::write_to_pbmsg(::proto_ff::E_BoxBox & msg) const {
	msg.set_m_id((int64_t)m_id);
	msg.set_m_type((int32_t)m_type);
	msg.set_m_rate((int32_t)m_rate);
	msg.set_m_mask((int32_t)m_mask);
	msg.set_m_mintimes((int32_t)m_mintimes);
	msg.set_m_maxtimes((int32_t)m_maxtimes);
	for(int32_t i = 0; i < (int32_t)m_boxdata.size(); ++i) {
		::proto_ff::E_BoxBoxBoxdataDesc* temp_m_boxdata = msg.add_m_boxdata();
		m_boxdata[i].write_to_pbmsg(*temp_m_boxdata);
	}
}

void E_BoxBox_s::read_from_pbmsg(const ::proto_ff::E_BoxBox & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct E_BoxBox_s));
	m_id = msg.m_id();
	m_type = msg.m_type();
	m_rate = msg.m_rate();
	m_mask = msg.m_mask();
	m_mintimes = msg.m_mintimes();
	m_maxtimes = msg.m_maxtimes();
	m_boxdata.resize((int)msg.m_boxdata_size() > (int)m_boxdata.max_size() ? m_boxdata.max_size() : msg.m_boxdata_size());
	for(int32_t i = 0; i < (int32_t)m_boxdata.size(); ++i) {
		const ::proto_ff::E_BoxBoxBoxdataDesc & temp_m_boxdata = msg.m_boxdata(i);
		m_boxdata[i].read_from_pbmsg(temp_m_boxdata);
	}
}

Sheet_BoxBox_s::Sheet_BoxBox_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_BoxBox_s::CreateInit() {
	return 0;
}

int Sheet_BoxBox_s::ResumeInit() {
	return 0;
}

void Sheet_BoxBox_s::write_to_pbmsg(::proto_ff::Sheet_BoxBox & msg) const {
	for(int32_t i = 0; i < (int32_t)E_BoxBox_List.size(); ++i) {
		::proto_ff::E_BoxBox* temp_e_boxbox_list = msg.add_e_boxbox_list();
		E_BoxBox_List[i].write_to_pbmsg(*temp_e_boxbox_list);
	}
}

void Sheet_BoxBox_s::read_from_pbmsg(const ::proto_ff::Sheet_BoxBox & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_BoxBox_s));
	E_BoxBox_List.resize((int)msg.e_boxbox_list_size() > (int)E_BoxBox_List.max_size() ? E_BoxBox_List.max_size() : msg.e_boxbox_list_size());
	for(int32_t i = 0; i < (int32_t)E_BoxBox_List.size(); ++i) {
		const ::proto_ff::E_BoxBox & temp_e_boxbox_list = msg.e_boxbox_list(i);
		E_BoxBox_List[i].read_from_pbmsg(temp_e_boxbox_list);
	}
}

E_BoxBoxdataEquipDesc_s::E_BoxBoxdataEquipDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_BoxBoxdataEquipDesc_s::CreateInit() {
	m_rand = (int32_t)0;
	m_minnum = (int32_t)0;
	m_isbind = (int32_t)0;
	m_maxnum = (int32_t)0;
	return 0;
}

int E_BoxBoxdataEquipDesc_s::ResumeInit() {
	return 0;
}

void E_BoxBoxdataEquipDesc_s::write_to_pbmsg(::proto_ff::E_BoxBoxdataEquipDesc & msg) const {
	msg.set_m_rand((int32_t)m_rand);
	msg.set_m_minnum((int32_t)m_minnum);
	msg.set_m_isbind((int32_t)m_isbind);
	msg.set_m_maxnum((int32_t)m_maxnum);
	msg.set_m_id((const char*)m_id.data());
}

void E_BoxBoxdataEquipDesc_s::read_from_pbmsg(const ::proto_ff::E_BoxBoxdataEquipDesc & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct E_BoxBoxdataEquipDesc_s));
	m_rand = msg.m_rand();
	m_minnum = msg.m_minnum();
	m_isbind = msg.m_isbind();
	m_maxnum = msg.m_maxnum();
	m_id = msg.m_id();
}

E_BoxBoxdataItemDesc_s::E_BoxBoxdataItemDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_BoxBoxdataItemDesc_s::CreateInit() {
	m_maxnum = (int32_t)0;
	m_rarerand = (int32_t)0;
	m_minnum = (int32_t)0;
	return 0;
}

int E_BoxBoxdataItemDesc_s::ResumeInit() {
	return 0;
}

void E_BoxBoxdataItemDesc_s::write_to_pbmsg(::proto_ff::E_BoxBoxdataItemDesc & msg) const {
	msg.set_m_rand((const char*)m_rand.data());
	msg.set_m_maxnum((int32_t)m_maxnum);
	msg.set_m_rarerand((int32_t)m_rarerand);
	msg.set_m_minnum((int32_t)m_minnum);
	msg.set_m_isbind((const char*)m_isbind.data());
	msg.set_m_id((const char*)m_id.data());
}

void E_BoxBoxdataItemDesc_s::read_from_pbmsg(const ::proto_ff::E_BoxBoxdataItemDesc & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct E_BoxBoxdataItemDesc_s));
	m_rand = msg.m_rand();
	m_maxnum = msg.m_maxnum();
	m_rarerand = msg.m_rarerand();
	m_minnum = msg.m_minnum();
	m_isbind = msg.m_isbind();
	m_id = msg.m_id();
}

E_BoxBoxdata_s::E_BoxBoxdata_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_BoxBoxdata_s::CreateInit() {
	m_id = (int64_t)0;
	m_drop_type = (int32_t)0;
	m_goldminnum = (int32_t)0;
	m_goldmaxnum = (int32_t)0;
	m_goldrand = (int32_t)0;
	m_bindjewelminnum = (int32_t)0;
	m_bindjewelmaxnum = (int32_t)0;
	m_bindjewelrand = (int32_t)0;
	m_jewelminnum = (int32_t)0;
	m_jewelmaxnum = (int32_t)0;
	m_jewelrand = (int32_t)0;
	return 0;
}

int E_BoxBoxdata_s::ResumeInit() {
	return 0;
}

void E_BoxBoxdata_s::write_to_pbmsg(::proto_ff::E_BoxBoxdata & msg) const {
	msg.set_m_id((int64_t)m_id);
	msg.set_m_drop_type((int32_t)m_drop_type);
	msg.set_m_goldminnum((int32_t)m_goldminnum);
	msg.set_m_goldmaxnum((int32_t)m_goldmaxnum);
	msg.set_m_goldrand((int32_t)m_goldrand);
	msg.set_m_bindjewelminnum((int32_t)m_bindjewelminnum);
	msg.set_m_bindjewelmaxnum((int32_t)m_bindjewelmaxnum);
	msg.set_m_bindjewelrand((int32_t)m_bindjewelrand);
	msg.set_m_jewelminnum((int32_t)m_jewelminnum);
	msg.set_m_jewelmaxnum((int32_t)m_jewelmaxnum);
	msg.set_m_jewelrand((int32_t)m_jewelrand);
	msg.set_m_eq_profession((const char*)m_eq_profession.data());
	for(int32_t i = 0; i < (int32_t)m_equip.size(); ++i) {
		::proto_ff::E_BoxBoxdataEquipDesc* temp_m_equip = msg.add_m_equip();
		m_equip[i].write_to_pbmsg(*temp_m_equip);
	}
	for(int32_t i = 0; i < (int32_t)m_item.size(); ++i) {
		::proto_ff::E_BoxBoxdataItemDesc* temp_m_item = msg.add_m_item();
		m_item[i].write_to_pbmsg(*temp_m_item);
	}
}

void E_BoxBoxdata_s::read_from_pbmsg(const ::proto_ff::E_BoxBoxdata & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct E_BoxBoxdata_s));
	m_id = msg.m_id();
	m_drop_type = msg.m_drop_type();
	m_goldminnum = msg.m_goldminnum();
	m_goldmaxnum = msg.m_goldmaxnum();
	m_goldrand = msg.m_goldrand();
	m_bindjewelminnum = msg.m_bindjewelminnum();
	m_bindjewelmaxnum = msg.m_bindjewelmaxnum();
	m_bindjewelrand = msg.m_bindjewelrand();
	m_jewelminnum = msg.m_jewelminnum();
	m_jewelmaxnum = msg.m_jewelmaxnum();
	m_jewelrand = msg.m_jewelrand();
	m_eq_profession = msg.m_eq_profession();
	m_equip.resize((int)msg.m_equip_size() > (int)m_equip.max_size() ? m_equip.max_size() : msg.m_equip_size());
	for(int32_t i = 0; i < (int32_t)m_equip.size(); ++i) {
		const ::proto_ff::E_BoxBoxdataEquipDesc & temp_m_equip = msg.m_equip(i);
		m_equip[i].read_from_pbmsg(temp_m_equip);
	}
	m_item.resize((int)msg.m_item_size() > (int)m_item.max_size() ? m_item.max_size() : msg.m_item_size());
	for(int32_t i = 0; i < (int32_t)m_item.size(); ++i) {
		const ::proto_ff::E_BoxBoxdataItemDesc & temp_m_item = msg.m_item(i);
		m_item[i].read_from_pbmsg(temp_m_item);
	}
}

Sheet_BoxBoxdata_s::Sheet_BoxBoxdata_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_BoxBoxdata_s::CreateInit() {
	return 0;
}

int Sheet_BoxBoxdata_s::ResumeInit() {
	return 0;
}

void Sheet_BoxBoxdata_s::write_to_pbmsg(::proto_ff::Sheet_BoxBoxdata & msg) const {
	for(int32_t i = 0; i < (int32_t)E_BoxBoxdata_List.size(); ++i) {
		::proto_ff::E_BoxBoxdata* temp_e_boxboxdata_list = msg.add_e_boxboxdata_list();
		E_BoxBoxdata_List[i].write_to_pbmsg(*temp_e_boxboxdata_list);
	}
}

void Sheet_BoxBoxdata_s::read_from_pbmsg(const ::proto_ff::Sheet_BoxBoxdata & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_BoxBoxdata_s));
	E_BoxBoxdata_List.resize((int)msg.e_boxboxdata_list_size() > (int)E_BoxBoxdata_List.max_size() ? E_BoxBoxdata_List.max_size() : msg.e_boxboxdata_list_size());
	for(int32_t i = 0; i < (int32_t)E_BoxBoxdata_List.size(); ++i) {
		const ::proto_ff::E_BoxBoxdata & temp_e_boxboxdata_list = msg.e_boxboxdata_list(i);
		E_BoxBoxdata_List[i].read_from_pbmsg(temp_e_boxboxdata_list);
	}
}

}