#include "E_Xingchen_s.h"

namespace proto_ff_s {

E_XingchenXcsetup_s::E_XingchenXcsetup_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_XingchenXcsetup_s::CreateInit() {
	m_xsid = (int32_t)0;
	m_unlockdj = (int32_t)0;
	m_unlockpf = (int32_t)0;
	m_xstype = (int32_t)0;
	m_xssubtype = (int32_t)0;
	return 0;
}

int E_XingchenXcsetup_s::ResumeInit() {
	return 0;
}

void E_XingchenXcsetup_s::write_to_pbmsg(::proto_ff::E_XingchenXcsetup & msg) const {
	msg.set_m_xsid((int32_t)m_xsid);
	msg.set_m_unlockdj((int32_t)m_unlockdj);
	msg.set_m_unlockpf((int32_t)m_unlockpf);
	msg.set_m_xstype((int32_t)m_xstype);
	msg.set_m_xssubtype((int32_t)m_xssubtype);
}

void E_XingchenXcsetup_s::read_from_pbmsg(const ::proto_ff::E_XingchenXcsetup & msg) {
	m_xsid = msg.m_xsid();
	m_unlockdj = msg.m_unlockdj();
	m_unlockpf = msg.m_unlockpf();
	m_xstype = msg.m_xstype();
	m_xssubtype = msg.m_xssubtype();
}

Sheet_XingchenXcsetup_s::Sheet_XingchenXcsetup_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_XingchenXcsetup_s::CreateInit() {
	return 0;
}

int Sheet_XingchenXcsetup_s::ResumeInit() {
	return 0;
}

void Sheet_XingchenXcsetup_s::write_to_pbmsg(::proto_ff::Sheet_XingchenXcsetup & msg) const {
	for(int32_t i = 0; i < (int32_t)E_XingchenXcsetup_List.size(); ++i) {
		::proto_ff::E_XingchenXcsetup* temp_e_xingchenxcsetup_list = msg.add_e_xingchenxcsetup_list();
		E_XingchenXcsetup_List[i].write_to_pbmsg(*temp_e_xingchenxcsetup_list);
	}
}

void Sheet_XingchenXcsetup_s::read_from_pbmsg(const ::proto_ff::Sheet_XingchenXcsetup & msg) {
	E_XingchenXcsetup_List.resize((int)msg.e_xingchenxcsetup_list_size() > (int)E_XingchenXcsetup_List.max_size() ? E_XingchenXcsetup_List.max_size() : msg.e_xingchenxcsetup_list_size());
	for(int32_t i = 0; i < (int32_t)E_XingchenXcsetup_List.size(); ++i) {
		const ::proto_ff::E_XingchenXcsetup & temp_e_xingchenxcsetup_list = msg.e_xingchenxcsetup_list(i);
		E_XingchenXcsetup_List[i].read_from_pbmsg(temp_e_xingchenxcsetup_list);
	}
}

E_XingchenXcmosaic_s::E_XingchenXcmosaic_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_XingchenXcmosaic_s::CreateInit() {
	m_positionnum = (int32_t)0;
	m_positionid = (int32_t)0;
	m_posx = (int32_t)0;
	m_posy = (int32_t)0;
	m_next_posx = (int32_t)0;
	m_next_posy = (int32_t)0;
	return 0;
}

int E_XingchenXcmosaic_s::ResumeInit() {
	return 0;
}

void E_XingchenXcmosaic_s::write_to_pbmsg(::proto_ff::E_XingchenXcmosaic & msg) const {
	msg.set_m_positionnum((int32_t)m_positionnum);
	msg.set_m_positionid((int32_t)m_positionid);
	msg.set_m_posx((int32_t)m_posx);
	msg.set_m_posy((int32_t)m_posy);
	msg.set_m_next_posx((int32_t)m_next_posx);
	msg.set_m_next_posy((int32_t)m_next_posy);
}

void E_XingchenXcmosaic_s::read_from_pbmsg(const ::proto_ff::E_XingchenXcmosaic & msg) {
	m_positionnum = msg.m_positionnum();
	m_positionid = msg.m_positionid();
	m_posx = msg.m_posx();
	m_posy = msg.m_posy();
	m_next_posx = msg.m_next_posx();
	m_next_posy = msg.m_next_posy();
}

Sheet_XingchenXcmosaic_s::Sheet_XingchenXcmosaic_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_XingchenXcmosaic_s::CreateInit() {
	return 0;
}

int Sheet_XingchenXcmosaic_s::ResumeInit() {
	return 0;
}

void Sheet_XingchenXcmosaic_s::write_to_pbmsg(::proto_ff::Sheet_XingchenXcmosaic & msg) const {
	for(int32_t i = 0; i < (int32_t)E_XingchenXcmosaic_List.size(); ++i) {
		::proto_ff::E_XingchenXcmosaic* temp_e_xingchenxcmosaic_list = msg.add_e_xingchenxcmosaic_list();
		E_XingchenXcmosaic_List[i].write_to_pbmsg(*temp_e_xingchenxcmosaic_list);
	}
}

void Sheet_XingchenXcmosaic_s::read_from_pbmsg(const ::proto_ff::Sheet_XingchenXcmosaic & msg) {
	E_XingchenXcmosaic_List.resize((int)msg.e_xingchenxcmosaic_list_size() > (int)E_XingchenXcmosaic_List.max_size() ? E_XingchenXcmosaic_List.max_size() : msg.e_xingchenxcmosaic_list_size());
	for(int32_t i = 0; i < (int32_t)E_XingchenXcmosaic_List.size(); ++i) {
		const ::proto_ff::E_XingchenXcmosaic & temp_e_xingchenxcmosaic_list = msg.e_xingchenxcmosaic_list(i);
		E_XingchenXcmosaic_List[i].read_from_pbmsg(temp_e_xingchenxcmosaic_list);
	}
}

E_XingchenXcmaterialQualityDesc_s::E_XingchenXcmaterialQualityDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_XingchenXcmaterialQualityDesc_s::CreateInit() {
	m_exp = (int32_t)0;
	m_type = (int32_t)0;
	return 0;
}

int E_XingchenXcmaterialQualityDesc_s::ResumeInit() {
	return 0;
}

void E_XingchenXcmaterialQualityDesc_s::write_to_pbmsg(::proto_ff::E_XingchenXcmaterialQualityDesc & msg) const {
	msg.set_m_exp((int32_t)m_exp);
	msg.set_m_type((int32_t)m_type);
}

void E_XingchenXcmaterialQualityDesc_s::read_from_pbmsg(const ::proto_ff::E_XingchenXcmaterialQualityDesc & msg) {
	m_exp = msg.m_exp();
	m_type = msg.m_type();
}

E_XingchenXcmaterial_s::E_XingchenXcmaterial_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_XingchenXcmaterial_s::CreateInit() {
	m_id = (int32_t)0;
	m_materialtype = (int32_t)0;
	m_functiontype = (int32_t)0;
	m_itemid = (int32_t)0;
	m_itemexp = (int32_t)0;
	return 0;
}

int E_XingchenXcmaterial_s::ResumeInit() {
	return 0;
}

void E_XingchenXcmaterial_s::write_to_pbmsg(::proto_ff::E_XingchenXcmaterial & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_materialtype((int32_t)m_materialtype);
	msg.set_m_functiontype((int32_t)m_functiontype);
	msg.set_m_xcposition(m_xcposition.data());
	msg.set_m_itemid((int32_t)m_itemid);
	msg.set_m_itemexp((int32_t)m_itemexp);
	for(int32_t i = 0; i < (int32_t)m_quality.size(); ++i) {
		::proto_ff::E_XingchenXcmaterialQualityDesc* temp_m_quality = msg.add_m_quality();
		m_quality[i].write_to_pbmsg(*temp_m_quality);
	}
}

void E_XingchenXcmaterial_s::read_from_pbmsg(const ::proto_ff::E_XingchenXcmaterial & msg) {
	m_id = msg.m_id();
	m_materialtype = msg.m_materialtype();
	m_functiontype = msg.m_functiontype();
	m_xcposition = msg.m_xcposition();
	m_itemid = msg.m_itemid();
	m_itemexp = msg.m_itemexp();
	m_quality.resize((int)msg.m_quality_size() > (int)m_quality.max_size() ? m_quality.max_size() : msg.m_quality_size());
	for(int32_t i = 0; i < (int32_t)m_quality.size(); ++i) {
		const ::proto_ff::E_XingchenXcmaterialQualityDesc & temp_m_quality = msg.m_quality(i);
		m_quality[i].read_from_pbmsg(temp_m_quality);
	}
}

Sheet_XingchenXcmaterial_s::Sheet_XingchenXcmaterial_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_XingchenXcmaterial_s::CreateInit() {
	return 0;
}

int Sheet_XingchenXcmaterial_s::ResumeInit() {
	return 0;
}

void Sheet_XingchenXcmaterial_s::write_to_pbmsg(::proto_ff::Sheet_XingchenXcmaterial & msg) const {
	for(int32_t i = 0; i < (int32_t)E_XingchenXcmaterial_List.size(); ++i) {
		::proto_ff::E_XingchenXcmaterial* temp_e_xingchenxcmaterial_list = msg.add_e_xingchenxcmaterial_list();
		E_XingchenXcmaterial_List[i].write_to_pbmsg(*temp_e_xingchenxcmaterial_list);
	}
}

void Sheet_XingchenXcmaterial_s::read_from_pbmsg(const ::proto_ff::Sheet_XingchenXcmaterial & msg) {
	E_XingchenXcmaterial_List.resize((int)msg.e_xingchenxcmaterial_list_size() > (int)E_XingchenXcmaterial_List.max_size() ? E_XingchenXcmaterial_List.max_size() : msg.e_xingchenxcmaterial_list_size());
	for(int32_t i = 0; i < (int32_t)E_XingchenXcmaterial_List.size(); ++i) {
		const ::proto_ff::E_XingchenXcmaterial & temp_e_xingchenxcmaterial_list = msg.e_xingchenxcmaterial_list(i);
		E_XingchenXcmaterial_List[i].read_from_pbmsg(temp_e_xingchenxcmaterial_list);
	}
}

E_XingchenXinchenAttributeDesc_s::E_XingchenXinchenAttributeDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_XingchenXinchenAttributeDesc_s::CreateInit() {
	m_value = (int32_t)0;
	m_type = (int32_t)0;
	return 0;
}

int E_XingchenXinchenAttributeDesc_s::ResumeInit() {
	return 0;
}

void E_XingchenXinchenAttributeDesc_s::write_to_pbmsg(::proto_ff::E_XingchenXinchenAttributeDesc & msg) const {
	msg.set_m_value((int32_t)m_value);
	msg.set_m_type((int32_t)m_type);
}

void E_XingchenXinchenAttributeDesc_s::read_from_pbmsg(const ::proto_ff::E_XingchenXinchenAttributeDesc & msg) {
	m_value = msg.m_value();
	m_type = msg.m_type();
}

E_XingchenXinchen_s::E_XingchenXinchen_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_XingchenXinchen_s::CreateInit() {
	m_xcequip = (int32_t)0;
	return 0;
}

int E_XingchenXinchen_s::ResumeInit() {
	return 0;
}

void E_XingchenXinchen_s::write_to_pbmsg(::proto_ff::E_XingchenXinchen & msg) const {
	msg.set_m_xcequip((int32_t)m_xcequip);
	for(int32_t i = 0; i < (int32_t)m_attribute.size(); ++i) {
		::proto_ff::E_XingchenXinchenAttributeDesc* temp_m_attribute = msg.add_m_attribute();
		m_attribute[i].write_to_pbmsg(*temp_m_attribute);
	}
}

void E_XingchenXinchen_s::read_from_pbmsg(const ::proto_ff::E_XingchenXinchen & msg) {
	m_xcequip = msg.m_xcequip();
	m_attribute.resize((int)msg.m_attribute_size() > (int)m_attribute.max_size() ? m_attribute.max_size() : msg.m_attribute_size());
	for(int32_t i = 0; i < (int32_t)m_attribute.size(); ++i) {
		const ::proto_ff::E_XingchenXinchenAttributeDesc & temp_m_attribute = msg.m_attribute(i);
		m_attribute[i].read_from_pbmsg(temp_m_attribute);
	}
}

Sheet_XingchenXinchen_s::Sheet_XingchenXinchen_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_XingchenXinchen_s::CreateInit() {
	return 0;
}

int Sheet_XingchenXinchen_s::ResumeInit() {
	return 0;
}

void Sheet_XingchenXinchen_s::write_to_pbmsg(::proto_ff::Sheet_XingchenXinchen & msg) const {
	for(int32_t i = 0; i < (int32_t)E_XingchenXinchen_List.size(); ++i) {
		::proto_ff::E_XingchenXinchen* temp_e_xingchenxinchen_list = msg.add_e_xingchenxinchen_list();
		E_XingchenXinchen_List[i].write_to_pbmsg(*temp_e_xingchenxinchen_list);
	}
}

void Sheet_XingchenXinchen_s::read_from_pbmsg(const ::proto_ff::Sheet_XingchenXinchen & msg) {
	E_XingchenXinchen_List.resize((int)msg.e_xingchenxinchen_list_size() > (int)E_XingchenXinchen_List.max_size() ? E_XingchenXinchen_List.max_size() : msg.e_xingchenxinchen_list_size());
	for(int32_t i = 0; i < (int32_t)E_XingchenXinchen_List.size(); ++i) {
		const ::proto_ff::E_XingchenXinchen & temp_e_xingchenxinchen_list = msg.e_xingchenxinchen_list(i);
		E_XingchenXinchen_List[i].read_from_pbmsg(temp_e_xingchenxinchen_list);
	}
}

E_XingchenXclvatt_s::E_XingchenXclvatt_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_XingchenXclvatt_s::CreateInit() {
	m_attid = (int64_t)0;
	return 0;
}

int E_XingchenXclvatt_s::ResumeInit() {
	return 0;
}

void E_XingchenXclvatt_s::write_to_pbmsg(::proto_ff::E_XingchenXclvatt & msg) const {
	msg.set_m_attid((int64_t)m_attid);
	for(int32_t i = 0; i < (int32_t)m_att.size(); ++i) {
		msg.add_m_att((int32_t)m_att[i]);
	}
}

void E_XingchenXclvatt_s::read_from_pbmsg(const ::proto_ff::E_XingchenXclvatt & msg) {
	m_attid = msg.m_attid();
	m_att.resize((int)msg.m_att_size() > (int)m_att.max_size() ? m_att.max_size() : msg.m_att_size());
	for(int32_t i = 0; i < (int32_t)m_att.size(); ++i) {
		m_att[i] = msg.m_att(i);
	}
}

Sheet_XingchenXclvatt_s::Sheet_XingchenXclvatt_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_XingchenXclvatt_s::CreateInit() {
	return 0;
}

int Sheet_XingchenXclvatt_s::ResumeInit() {
	return 0;
}

void Sheet_XingchenXclvatt_s::write_to_pbmsg(::proto_ff::Sheet_XingchenXclvatt & msg) const {
	for(int32_t i = 0; i < (int32_t)E_XingchenXclvatt_List.size(); ++i) {
		::proto_ff::E_XingchenXclvatt* temp_e_xingchenxclvatt_list = msg.add_e_xingchenxclvatt_list();
		E_XingchenXclvatt_List[i].write_to_pbmsg(*temp_e_xingchenxclvatt_list);
	}
}

void Sheet_XingchenXclvatt_s::read_from_pbmsg(const ::proto_ff::Sheet_XingchenXclvatt & msg) {
	E_XingchenXclvatt_List.resize((int)msg.e_xingchenxclvatt_list_size() > (int)E_XingchenXclvatt_List.max_size() ? E_XingchenXclvatt_List.max_size() : msg.e_xingchenxclvatt_list_size());
	for(int32_t i = 0; i < (int32_t)E_XingchenXclvatt_List.size(); ++i) {
		const ::proto_ff::E_XingchenXclvatt & temp_e_xingchenxclvatt_list = msg.e_xingchenxclvatt_list(i);
		E_XingchenXclvatt_List[i].read_from_pbmsg(temp_e_xingchenxclvatt_list);
	}
}

E_XingchenXclvexp_s::E_XingchenXclvexp_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_XingchenXclvexp_s::CreateInit() {
	m_lv = (int32_t)0;
	m_exp = (int32_t)0;
	return 0;
}

int E_XingchenXclvexp_s::ResumeInit() {
	return 0;
}

void E_XingchenXclvexp_s::write_to_pbmsg(::proto_ff::E_XingchenXclvexp & msg) const {
	msg.set_m_lv((int32_t)m_lv);
	msg.set_m_exp((int32_t)m_exp);
}

void E_XingchenXclvexp_s::read_from_pbmsg(const ::proto_ff::E_XingchenXclvexp & msg) {
	m_lv = msg.m_lv();
	m_exp = msg.m_exp();
}

Sheet_XingchenXclvexp_s::Sheet_XingchenXclvexp_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_XingchenXclvexp_s::CreateInit() {
	return 0;
}

int Sheet_XingchenXclvexp_s::ResumeInit() {
	return 0;
}

void Sheet_XingchenXclvexp_s::write_to_pbmsg(::proto_ff::Sheet_XingchenXclvexp & msg) const {
	for(int32_t i = 0; i < (int32_t)E_XingchenXclvexp_List.size(); ++i) {
		::proto_ff::E_XingchenXclvexp* temp_e_xingchenxclvexp_list = msg.add_e_xingchenxclvexp_list();
		E_XingchenXclvexp_List[i].write_to_pbmsg(*temp_e_xingchenxclvexp_list);
	}
}

void Sheet_XingchenXclvexp_s::read_from_pbmsg(const ::proto_ff::Sheet_XingchenXclvexp & msg) {
	E_XingchenXclvexp_List.resize((int)msg.e_xingchenxclvexp_list_size() > (int)E_XingchenXclvexp_List.max_size() ? E_XingchenXclvexp_List.max_size() : msg.e_xingchenxclvexp_list_size());
	for(int32_t i = 0; i < (int32_t)E_XingchenXclvexp_List.size(); ++i) {
		const ::proto_ff::E_XingchenXclvexp & temp_e_xingchenxclvexp_list = msg.e_xingchenxclvexp_list(i);
		E_XingchenXclvexp_List[i].read_from_pbmsg(temp_e_xingchenxclvexp_list);
	}
}

E_XingchenXctpTpDesc_s::E_XingchenXctpTpDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_XingchenXctpTpDesc_s::CreateInit() {
	m_value = (int32_t)0;
	m_type = (int32_t)0;
	return 0;
}

int E_XingchenXctpTpDesc_s::ResumeInit() {
	return 0;
}

void E_XingchenXctpTpDesc_s::write_to_pbmsg(::proto_ff::E_XingchenXctpTpDesc & msg) const {
	msg.set_m_value((int32_t)m_value);
	msg.set_m_type((int32_t)m_type);
}

void E_XingchenXctpTpDesc_s::read_from_pbmsg(const ::proto_ff::E_XingchenXctpTpDesc & msg) {
	m_value = msg.m_value();
	m_type = msg.m_type();
}

E_XingchenXctp_s::E_XingchenXctp_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_XingchenXctp_s::CreateInit() {
	m_id = (int32_t)0;
	m_positionid = (int32_t)0;
	m_xcquality = (int32_t)0;
	m_xclvmax = (int32_t)0;
	return 0;
}

int E_XingchenXctp_s::ResumeInit() {
	return 0;
}

void E_XingchenXctp_s::write_to_pbmsg(::proto_ff::E_XingchenXctp & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_positionid((int32_t)m_positionid);
	msg.set_m_xcquality((int32_t)m_xcquality);
	msg.set_m_xclvmax((int32_t)m_xclvmax);
	for(int32_t i = 0; i < (int32_t)m_tp.size(); ++i) {
		::proto_ff::E_XingchenXctpTpDesc* temp_m_tp = msg.add_m_tp();
		m_tp[i].write_to_pbmsg(*temp_m_tp);
	}
	for(int32_t i = 0; i < (int32_t)m_attr.size(); ++i) {
		msg.add_m_attr((int32_t)m_attr[i]);
	}
}

void E_XingchenXctp_s::read_from_pbmsg(const ::proto_ff::E_XingchenXctp & msg) {
	m_id = msg.m_id();
	m_positionid = msg.m_positionid();
	m_xcquality = msg.m_xcquality();
	m_xclvmax = msg.m_xclvmax();
	m_tp.resize((int)msg.m_tp_size() > (int)m_tp.max_size() ? m_tp.max_size() : msg.m_tp_size());
	for(int32_t i = 0; i < (int32_t)m_tp.size(); ++i) {
		const ::proto_ff::E_XingchenXctpTpDesc & temp_m_tp = msg.m_tp(i);
		m_tp[i].read_from_pbmsg(temp_m_tp);
	}
	m_attr.resize((int)msg.m_attr_size() > (int)m_attr.max_size() ? m_attr.max_size() : msg.m_attr_size());
	for(int32_t i = 0; i < (int32_t)m_attr.size(); ++i) {
		m_attr[i] = msg.m_attr(i);
	}
}

Sheet_XingchenXctp_s::Sheet_XingchenXctp_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_XingchenXctp_s::CreateInit() {
	return 0;
}

int Sheet_XingchenXctp_s::ResumeInit() {
	return 0;
}

void Sheet_XingchenXctp_s::write_to_pbmsg(::proto_ff::Sheet_XingchenXctp & msg) const {
	for(int32_t i = 0; i < (int32_t)E_XingchenXctp_List.size(); ++i) {
		::proto_ff::E_XingchenXctp* temp_e_xingchenxctp_list = msg.add_e_xingchenxctp_list();
		E_XingchenXctp_List[i].write_to_pbmsg(*temp_e_xingchenxctp_list);
	}
}

void Sheet_XingchenXctp_s::read_from_pbmsg(const ::proto_ff::Sheet_XingchenXctp & msg) {
	E_XingchenXctp_List.resize((int)msg.e_xingchenxctp_list_size() > (int)E_XingchenXctp_List.max_size() ? E_XingchenXctp_List.max_size() : msg.e_xingchenxctp_list_size());
	for(int32_t i = 0; i < (int32_t)E_XingchenXctp_List.size(); ++i) {
		const ::proto_ff::E_XingchenXctp & temp_e_xingchenxctp_list = msg.e_xingchenxctp_list(i);
		E_XingchenXctp_List[i].read_from_pbmsg(temp_e_xingchenxctp_list);
	}
}

E_XingchenXctpexp_s::E_XingchenXctpexp_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_XingchenXctpexp_s::CreateInit() {
	m_lv = (int32_t)0;
	m_exp = (int32_t)0;
	return 0;
}

int E_XingchenXctpexp_s::ResumeInit() {
	return 0;
}

void E_XingchenXctpexp_s::write_to_pbmsg(::proto_ff::E_XingchenXctpexp & msg) const {
	msg.set_m_lv((int32_t)m_lv);
	msg.set_m_lvdisplay(m_lvdisplay.data());
	msg.set_m_exp((int32_t)m_exp);
}

void E_XingchenXctpexp_s::read_from_pbmsg(const ::proto_ff::E_XingchenXctpexp & msg) {
	m_lv = msg.m_lv();
	m_lvdisplay = msg.m_lvdisplay();
	m_exp = msg.m_exp();
}

Sheet_XingchenXctpexp_s::Sheet_XingchenXctpexp_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_XingchenXctpexp_s::CreateInit() {
	return 0;
}

int Sheet_XingchenXctpexp_s::ResumeInit() {
	return 0;
}

void Sheet_XingchenXctpexp_s::write_to_pbmsg(::proto_ff::Sheet_XingchenXctpexp & msg) const {
	for(int32_t i = 0; i < (int32_t)E_XingchenXctpexp_List.size(); ++i) {
		::proto_ff::E_XingchenXctpexp* temp_e_xingchenxctpexp_list = msg.add_e_xingchenxctpexp_list();
		E_XingchenXctpexp_List[i].write_to_pbmsg(*temp_e_xingchenxctpexp_list);
	}
}

void Sheet_XingchenXctpexp_s::read_from_pbmsg(const ::proto_ff::Sheet_XingchenXctpexp & msg) {
	E_XingchenXctpexp_List.resize((int)msg.e_xingchenxctpexp_list_size() > (int)E_XingchenXctpexp_List.max_size() ? E_XingchenXctpexp_List.max_size() : msg.e_xingchenxctpexp_list_size());
	for(int32_t i = 0; i < (int32_t)E_XingchenXctpexp_List.size(); ++i) {
		const ::proto_ff::E_XingchenXctpexp & temp_e_xingchenxctpexp_list = msg.e_xingchenxctpexp_list(i);
		E_XingchenXctpexp_List[i].read_from_pbmsg(temp_e_xingchenxctpexp_list);
	}
}

E_XingchenXctpaddi_s::E_XingchenXctpaddi_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_XingchenXctpaddi_s::CreateInit() {
	m_id = (int64_t)0;
	m_attid = (int64_t)0;
	m_count = (int32_t)0;
	m_atttype = (int32_t)0;
	m_att = (int32_t)0;
	return 0;
}

int E_XingchenXctpaddi_s::ResumeInit() {
	return 0;
}

void E_XingchenXctpaddi_s::write_to_pbmsg(::proto_ff::E_XingchenXctpaddi & msg) const {
	msg.set_m_id((int64_t)m_id);
	msg.set_m_attid((int64_t)m_attid);
	msg.set_m_count((int32_t)m_count);
	msg.set_m_atttype((int32_t)m_atttype);
	msg.set_m_att((int32_t)m_att);
}

void E_XingchenXctpaddi_s::read_from_pbmsg(const ::proto_ff::E_XingchenXctpaddi & msg) {
	m_id = msg.m_id();
	m_attid = msg.m_attid();
	m_count = msg.m_count();
	m_atttype = msg.m_atttype();
	m_att = msg.m_att();
}

Sheet_XingchenXctpaddi_s::Sheet_XingchenXctpaddi_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_XingchenXctpaddi_s::CreateInit() {
	return 0;
}

int Sheet_XingchenXctpaddi_s::ResumeInit() {
	return 0;
}

void Sheet_XingchenXctpaddi_s::write_to_pbmsg(::proto_ff::Sheet_XingchenXctpaddi & msg) const {
	for(int32_t i = 0; i < (int32_t)E_XingchenXctpaddi_List.size(); ++i) {
		::proto_ff::E_XingchenXctpaddi* temp_e_xingchenxctpaddi_list = msg.add_e_xingchenxctpaddi_list();
		E_XingchenXctpaddi_List[i].write_to_pbmsg(*temp_e_xingchenxctpaddi_list);
	}
}

void Sheet_XingchenXctpaddi_s::read_from_pbmsg(const ::proto_ff::Sheet_XingchenXctpaddi & msg) {
	E_XingchenXctpaddi_List.resize((int)msg.e_xingchenxctpaddi_list_size() > (int)E_XingchenXctpaddi_List.max_size() ? E_XingchenXctpaddi_List.max_size() : msg.e_xingchenxctpaddi_list_size());
	for(int32_t i = 0; i < (int32_t)E_XingchenXctpaddi_List.size(); ++i) {
		const ::proto_ff::E_XingchenXctpaddi & temp_e_xingchenxctpaddi_list = msg.e_xingchenxctpaddi_list(i);
		E_XingchenXctpaddi_List[i].read_from_pbmsg(temp_e_xingchenxctpaddi_list);
	}
}

E_XingchenXctpatt_s::E_XingchenXctpatt_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_XingchenXctpatt_s::CreateInit() {
	m_attid = (int64_t)0;
	return 0;
}

int E_XingchenXctpatt_s::ResumeInit() {
	return 0;
}

void E_XingchenXctpatt_s::write_to_pbmsg(::proto_ff::E_XingchenXctpatt & msg) const {
	msg.set_m_attid((int64_t)m_attid);
	for(int32_t i = 0; i < (int32_t)m_att.size(); ++i) {
		msg.add_m_att((int32_t)m_att[i]);
	}
}

void E_XingchenXctpatt_s::read_from_pbmsg(const ::proto_ff::E_XingchenXctpatt & msg) {
	m_attid = msg.m_attid();
	m_att.resize((int)msg.m_att_size() > (int)m_att.max_size() ? m_att.max_size() : msg.m_att_size());
	for(int32_t i = 0; i < (int32_t)m_att.size(); ++i) {
		m_att[i] = msg.m_att(i);
	}
}

Sheet_XingchenXctpatt_s::Sheet_XingchenXctpatt_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_XingchenXctpatt_s::CreateInit() {
	return 0;
}

int Sheet_XingchenXctpatt_s::ResumeInit() {
	return 0;
}

void Sheet_XingchenXctpatt_s::write_to_pbmsg(::proto_ff::Sheet_XingchenXctpatt & msg) const {
	for(int32_t i = 0; i < (int32_t)E_XingchenXctpatt_List.size(); ++i) {
		::proto_ff::E_XingchenXctpatt* temp_e_xingchenxctpatt_list = msg.add_e_xingchenxctpatt_list();
		E_XingchenXctpatt_List[i].write_to_pbmsg(*temp_e_xingchenxctpatt_list);
	}
}

void Sheet_XingchenXctpatt_s::read_from_pbmsg(const ::proto_ff::Sheet_XingchenXctpatt & msg) {
	E_XingchenXctpatt_List.resize((int)msg.e_xingchenxctpatt_list_size() > (int)E_XingchenXctpatt_List.max_size() ? E_XingchenXctpatt_List.max_size() : msg.e_xingchenxctpatt_list_size());
	for(int32_t i = 0; i < (int32_t)E_XingchenXctpatt_List.size(); ++i) {
		const ::proto_ff::E_XingchenXctpatt & temp_e_xingchenxctpatt_list = msg.e_xingchenxctpatt_list(i);
		E_XingchenXctpatt_List[i].read_from_pbmsg(temp_e_xingchenxctpatt_list);
	}
}

E_XingchenXcstarAttributeDesc_s::E_XingchenXcstarAttributeDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_XingchenXcstarAttributeDesc_s::CreateInit() {
	m_value = (int32_t)0;
	m_type = (int32_t)0;
	return 0;
}

int E_XingchenXcstarAttributeDesc_s::ResumeInit() {
	return 0;
}

void E_XingchenXcstarAttributeDesc_s::write_to_pbmsg(::proto_ff::E_XingchenXcstarAttributeDesc & msg) const {
	msg.set_m_value((int32_t)m_value);
	msg.set_m_type((int32_t)m_type);
}

void E_XingchenXcstarAttributeDesc_s::read_from_pbmsg(const ::proto_ff::E_XingchenXcstarAttributeDesc & msg) {
	m_value = msg.m_value();
	m_type = msg.m_type();
}

E_XingchenXcstar_s::E_XingchenXcstar_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_XingchenXcstar_s::CreateInit() {
	m_starlv = (int32_t)0;
	m_id = (int32_t)0;
	return 0;
}

int E_XingchenXcstar_s::ResumeInit() {
	return 0;
}

void E_XingchenXcstar_s::write_to_pbmsg(::proto_ff::E_XingchenXcstar & msg) const {
	msg.set_m_starlv((int32_t)m_starlv);
	msg.set_m_id((int32_t)m_id);
	for(int32_t i = 0; i < (int32_t)m_attribute.size(); ++i) {
		::proto_ff::E_XingchenXcstarAttributeDesc* temp_m_attribute = msg.add_m_attribute();
		m_attribute[i].write_to_pbmsg(*temp_m_attribute);
	}
}

void E_XingchenXcstar_s::read_from_pbmsg(const ::proto_ff::E_XingchenXcstar & msg) {
	m_starlv = msg.m_starlv();
	m_id = msg.m_id();
	m_attribute.resize((int)msg.m_attribute_size() > (int)m_attribute.max_size() ? m_attribute.max_size() : msg.m_attribute_size());
	for(int32_t i = 0; i < (int32_t)m_attribute.size(); ++i) {
		const ::proto_ff::E_XingchenXcstarAttributeDesc & temp_m_attribute = msg.m_attribute(i);
		m_attribute[i].read_from_pbmsg(temp_m_attribute);
	}
}

Sheet_XingchenXcstar_s::Sheet_XingchenXcstar_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_XingchenXcstar_s::CreateInit() {
	return 0;
}

int Sheet_XingchenXcstar_s::ResumeInit() {
	return 0;
}

void Sheet_XingchenXcstar_s::write_to_pbmsg(::proto_ff::Sheet_XingchenXcstar & msg) const {
	for(int32_t i = 0; i < (int32_t)E_XingchenXcstar_List.size(); ++i) {
		::proto_ff::E_XingchenXcstar* temp_e_xingchenxcstar_list = msg.add_e_xingchenxcstar_list();
		E_XingchenXcstar_List[i].write_to_pbmsg(*temp_e_xingchenxcstar_list);
	}
}

void Sheet_XingchenXcstar_s::read_from_pbmsg(const ::proto_ff::Sheet_XingchenXcstar & msg) {
	E_XingchenXcstar_List.resize((int)msg.e_xingchenxcstar_list_size() > (int)E_XingchenXcstar_List.max_size() ? E_XingchenXcstar_List.max_size() : msg.e_xingchenxcstar_list_size());
	for(int32_t i = 0; i < (int32_t)E_XingchenXcstar_List.size(); ++i) {
		const ::proto_ff::E_XingchenXcstar & temp_e_xingchenxcstar_list = msg.e_xingchenxcstar_list(i);
		E_XingchenXcstar_List[i].read_from_pbmsg(temp_e_xingchenxcstar_list);
	}
}

E_XingchenXcawakenAwakenDesc_s::E_XingchenXcawakenAwakenDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_XingchenXcawakenAwakenDesc_s::CreateInit() {
	m_tpaddratio = (int32_t)0;
	m_lvaddratio = (int32_t)0;
	m_num = (int32_t)0;
	return 0;
}

int E_XingchenXcawakenAwakenDesc_s::ResumeInit() {
	return 0;
}

void E_XingchenXcawakenAwakenDesc_s::write_to_pbmsg(::proto_ff::E_XingchenXcawakenAwakenDesc & msg) const {
	msg.set_m_tpaddratio((int32_t)m_tpaddratio);
	msg.set_m_lvaddratio((int32_t)m_lvaddratio);
	msg.set_m_num((int32_t)m_num);
}

void E_XingchenXcawakenAwakenDesc_s::read_from_pbmsg(const ::proto_ff::E_XingchenXcawakenAwakenDesc & msg) {
	m_tpaddratio = msg.m_tpaddratio();
	m_lvaddratio = msg.m_lvaddratio();
	m_num = msg.m_num();
}

E_XingchenXcawaken_s::E_XingchenXcawaken_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_XingchenXcawaken_s::CreateInit() {
	m_positionnum = (int32_t)0;
	m_positionid = (int32_t)0;
	m_awaken_quality = (int32_t)0;
	m_awaken_lvmax = (int32_t)0;
	m_awaken_item = (int32_t)0;
	return 0;
}

int E_XingchenXcawaken_s::ResumeInit() {
	return 0;
}

void E_XingchenXcawaken_s::write_to_pbmsg(::proto_ff::E_XingchenXcawaken & msg) const {
	msg.set_m_positionnum((int32_t)m_positionnum);
	msg.set_m_positionid((int32_t)m_positionid);
	msg.set_m_awaken_quality((int32_t)m_awaken_quality);
	msg.set_m_awaken_lvmax((int32_t)m_awaken_lvmax);
	msg.set_m_awaken_item((int32_t)m_awaken_item);
	for(int32_t i = 0; i < (int32_t)m_awaken.size(); ++i) {
		::proto_ff::E_XingchenXcawakenAwakenDesc* temp_m_awaken = msg.add_m_awaken();
		m_awaken[i].write_to_pbmsg(*temp_m_awaken);
	}
}

void E_XingchenXcawaken_s::read_from_pbmsg(const ::proto_ff::E_XingchenXcawaken & msg) {
	m_positionnum = msg.m_positionnum();
	m_positionid = msg.m_positionid();
	m_awaken_quality = msg.m_awaken_quality();
	m_awaken_lvmax = msg.m_awaken_lvmax();
	m_awaken_item = msg.m_awaken_item();
	m_awaken.resize((int)msg.m_awaken_size() > (int)m_awaken.max_size() ? m_awaken.max_size() : msg.m_awaken_size());
	for(int32_t i = 0; i < (int32_t)m_awaken.size(); ++i) {
		const ::proto_ff::E_XingchenXcawakenAwakenDesc & temp_m_awaken = msg.m_awaken(i);
		m_awaken[i].read_from_pbmsg(temp_m_awaken);
	}
}

Sheet_XingchenXcawaken_s::Sheet_XingchenXcawaken_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_XingchenXcawaken_s::CreateInit() {
	return 0;
}

int Sheet_XingchenXcawaken_s::ResumeInit() {
	return 0;
}

void Sheet_XingchenXcawaken_s::write_to_pbmsg(::proto_ff::Sheet_XingchenXcawaken & msg) const {
	for(int32_t i = 0; i < (int32_t)E_XingchenXcawaken_List.size(); ++i) {
		::proto_ff::E_XingchenXcawaken* temp_e_xingchenxcawaken_list = msg.add_e_xingchenxcawaken_list();
		E_XingchenXcawaken_List[i].write_to_pbmsg(*temp_e_xingchenxcawaken_list);
	}
}

void Sheet_XingchenXcawaken_s::read_from_pbmsg(const ::proto_ff::Sheet_XingchenXcawaken & msg) {
	E_XingchenXcawaken_List.resize((int)msg.e_xingchenxcawaken_list_size() > (int)E_XingchenXcawaken_List.max_size() ? E_XingchenXcawaken_List.max_size() : msg.e_xingchenxcawaken_list_size());
	for(int32_t i = 0; i < (int32_t)E_XingchenXcawaken_List.size(); ++i) {
		const ::proto_ff::E_XingchenXcawaken & temp_e_xingchenxcawaken_list = msg.e_xingchenxcawaken_list(i);
		E_XingchenXcawaken_List[i].read_from_pbmsg(temp_e_xingchenxcawaken_list);
	}
}

E_XingchenXcmagicalHhDesc_s::E_XingchenXcmagicalHhDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_XingchenXcmagicalHhDesc_s::CreateInit() {
	m_value = (int32_t)0;
	m_type = (int32_t)0;
	return 0;
}

int E_XingchenXcmagicalHhDesc_s::ResumeInit() {
	return 0;
}

void E_XingchenXcmagicalHhDesc_s::write_to_pbmsg(::proto_ff::E_XingchenXcmagicalHhDesc & msg) const {
	msg.set_m_value((int32_t)m_value);
	msg.set_m_type((int32_t)m_type);
}

void E_XingchenXcmagicalHhDesc_s::read_from_pbmsg(const ::proto_ff::E_XingchenXcmagicalHhDesc & msg) {
	m_value = msg.m_value();
	m_type = msg.m_type();
}

E_XingchenXcmagical_s::E_XingchenXcmagical_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_XingchenXcmagical_s::CreateInit() {
	m_id = (int32_t)0;
	m_hhquality = (int32_t)0;
	m_isadvanced = (int32_t)0;
	m_hhact = (int32_t)0;
	m_hhstar = (int32_t)0;
	m_advskill = (int32_t)0;
	return 0;
}

int E_XingchenXcmagical_s::ResumeInit() {
	return 0;
}

void E_XingchenXcmagical_s::write_to_pbmsg(::proto_ff::E_XingchenXcmagical & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_hhquality((int32_t)m_hhquality);
	msg.set_m_isadvanced((int32_t)m_isadvanced);
	msg.set_m_hhact((int32_t)m_hhact);
	msg.set_m_hhstar((int32_t)m_hhstar);
	msg.set_m_advskill((int32_t)m_advskill);
	for(int32_t i = 0; i < (int32_t)m_hh.size(); ++i) {
		::proto_ff::E_XingchenXcmagicalHhDesc* temp_m_hh = msg.add_m_hh();
		m_hh[i].write_to_pbmsg(*temp_m_hh);
	}
}

void E_XingchenXcmagical_s::read_from_pbmsg(const ::proto_ff::E_XingchenXcmagical & msg) {
	m_id = msg.m_id();
	m_hhquality = msg.m_hhquality();
	m_isadvanced = msg.m_isadvanced();
	m_hhact = msg.m_hhact();
	m_hhstar = msg.m_hhstar();
	m_advskill = msg.m_advskill();
	m_hh.resize((int)msg.m_hh_size() > (int)m_hh.max_size() ? m_hh.max_size() : msg.m_hh_size());
	for(int32_t i = 0; i < (int32_t)m_hh.size(); ++i) {
		const ::proto_ff::E_XingchenXcmagicalHhDesc & temp_m_hh = msg.m_hh(i);
		m_hh[i].read_from_pbmsg(temp_m_hh);
	}
}

Sheet_XingchenXcmagical_s::Sheet_XingchenXcmagical_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_XingchenXcmagical_s::CreateInit() {
	return 0;
}

int Sheet_XingchenXcmagical_s::ResumeInit() {
	return 0;
}

void Sheet_XingchenXcmagical_s::write_to_pbmsg(::proto_ff::Sheet_XingchenXcmagical & msg) const {
	for(int32_t i = 0; i < (int32_t)E_XingchenXcmagical_List.size(); ++i) {
		::proto_ff::E_XingchenXcmagical* temp_e_xingchenxcmagical_list = msg.add_e_xingchenxcmagical_list();
		E_XingchenXcmagical_List[i].write_to_pbmsg(*temp_e_xingchenxcmagical_list);
	}
}

void Sheet_XingchenXcmagical_s::read_from_pbmsg(const ::proto_ff::Sheet_XingchenXcmagical & msg) {
	E_XingchenXcmagical_List.resize((int)msg.e_xingchenxcmagical_list_size() > (int)E_XingchenXcmagical_List.max_size() ? E_XingchenXcmagical_List.max_size() : msg.e_xingchenxcmagical_list_size());
	for(int32_t i = 0; i < (int32_t)E_XingchenXcmagical_List.size(); ++i) {
		const ::proto_ff::E_XingchenXcmagical & temp_e_xingchenxcmagical_list = msg.e_xingchenxcmagical_list(i);
		E_XingchenXcmagical_List[i].read_from_pbmsg(temp_e_xingchenxcmagical_list);
	}
}

E_XingchenXcmagatt_s::E_XingchenXcmagatt_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_XingchenXcmagatt_s::CreateInit() {
	m_attid = (int64_t)0;
	return 0;
}

int E_XingchenXcmagatt_s::ResumeInit() {
	return 0;
}

void E_XingchenXcmagatt_s::write_to_pbmsg(::proto_ff::E_XingchenXcmagatt & msg) const {
	msg.set_m_attid((int64_t)m_attid);
	for(int32_t i = 0; i < (int32_t)m_att.size(); ++i) {
		msg.add_m_att((int32_t)m_att[i]);
	}
}

void E_XingchenXcmagatt_s::read_from_pbmsg(const ::proto_ff::E_XingchenXcmagatt & msg) {
	m_attid = msg.m_attid();
	m_att.resize((int)msg.m_att_size() > (int)m_att.max_size() ? m_att.max_size() : msg.m_att_size());
	for(int32_t i = 0; i < (int32_t)m_att.size(); ++i) {
		m_att[i] = msg.m_att(i);
	}
}

Sheet_XingchenXcmagatt_s::Sheet_XingchenXcmagatt_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_XingchenXcmagatt_s::CreateInit() {
	return 0;
}

int Sheet_XingchenXcmagatt_s::ResumeInit() {
	return 0;
}

void Sheet_XingchenXcmagatt_s::write_to_pbmsg(::proto_ff::Sheet_XingchenXcmagatt & msg) const {
	for(int32_t i = 0; i < (int32_t)E_XingchenXcmagatt_List.size(); ++i) {
		::proto_ff::E_XingchenXcmagatt* temp_e_xingchenxcmagatt_list = msg.add_e_xingchenxcmagatt_list();
		E_XingchenXcmagatt_List[i].write_to_pbmsg(*temp_e_xingchenxcmagatt_list);
	}
}

void Sheet_XingchenXcmagatt_s::read_from_pbmsg(const ::proto_ff::Sheet_XingchenXcmagatt & msg) {
	E_XingchenXcmagatt_List.resize((int)msg.e_xingchenxcmagatt_list_size() > (int)E_XingchenXcmagatt_List.max_size() ? E_XingchenXcmagatt_List.max_size() : msg.e_xingchenxcmagatt_list_size());
	for(int32_t i = 0; i < (int32_t)E_XingchenXcmagatt_List.size(); ++i) {
		const ::proto_ff::E_XingchenXcmagatt & temp_e_xingchenxcmagatt_list = msg.e_xingchenxcmagatt_list(i);
		E_XingchenXcmagatt_List[i].read_from_pbmsg(temp_e_xingchenxcmagatt_list);
	}
}

E_XingchenXcadvattUpattributeDesc_s::E_XingchenXcadvattUpattributeDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_XingchenXcadvattUpattributeDesc_s::CreateInit() {
	m_value = (int32_t)0;
	m_type = (int32_t)0;
	return 0;
}

int E_XingchenXcadvattUpattributeDesc_s::ResumeInit() {
	return 0;
}

void E_XingchenXcadvattUpattributeDesc_s::write_to_pbmsg(::proto_ff::E_XingchenXcadvattUpattributeDesc & msg) const {
	msg.set_m_value((int32_t)m_value);
	msg.set_m_type((int32_t)m_type);
}

void E_XingchenXcadvattUpattributeDesc_s::read_from_pbmsg(const ::proto_ff::E_XingchenXcadvattUpattributeDesc & msg) {
	m_value = msg.m_value();
	m_type = msg.m_type();
}

E_XingchenXcadvatt_s::E_XingchenXcadvatt_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_XingchenXcadvatt_s::CreateInit() {
	m_id = (int32_t)0;
	m_upattributeid = (int64_t)0;
	m_classlv = (int32_t)0;
	m_starid = (int32_t)0;
	m_skillid = (int32_t)0;
	m_activeskillidlv = (int32_t)0;
	return 0;
}

int E_XingchenXcadvatt_s::ResumeInit() {
	return 0;
}

void E_XingchenXcadvatt_s::write_to_pbmsg(::proto_ff::E_XingchenXcadvatt & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_upattributeid((int64_t)m_upattributeid);
	msg.set_m_classlv((int32_t)m_classlv);
	msg.set_m_starid((int32_t)m_starid);
	msg.set_m_skillid((int32_t)m_skillid);
	msg.set_m_activeskillidlv((int32_t)m_activeskillidlv);
	for(int32_t i = 0; i < (int32_t)m_upattribute.size(); ++i) {
		::proto_ff::E_XingchenXcadvattUpattributeDesc* temp_m_upattribute = msg.add_m_upattribute();
		m_upattribute[i].write_to_pbmsg(*temp_m_upattribute);
	}
}

void E_XingchenXcadvatt_s::read_from_pbmsg(const ::proto_ff::E_XingchenXcadvatt & msg) {
	m_id = msg.m_id();
	m_upattributeid = msg.m_upattributeid();
	m_classlv = msg.m_classlv();
	m_starid = msg.m_starid();
	m_skillid = msg.m_skillid();
	m_activeskillidlv = msg.m_activeskillidlv();
	m_upattribute.resize((int)msg.m_upattribute_size() > (int)m_upattribute.max_size() ? m_upattribute.max_size() : msg.m_upattribute_size());
	for(int32_t i = 0; i < (int32_t)m_upattribute.size(); ++i) {
		const ::proto_ff::E_XingchenXcadvattUpattributeDesc & temp_m_upattribute = msg.m_upattribute(i);
		m_upattribute[i].read_from_pbmsg(temp_m_upattribute);
	}
}

Sheet_XingchenXcadvatt_s::Sheet_XingchenXcadvatt_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_XingchenXcadvatt_s::CreateInit() {
	return 0;
}

int Sheet_XingchenXcadvatt_s::ResumeInit() {
	return 0;
}

void Sheet_XingchenXcadvatt_s::write_to_pbmsg(::proto_ff::Sheet_XingchenXcadvatt & msg) const {
	for(int32_t i = 0; i < (int32_t)E_XingchenXcadvatt_List.size(); ++i) {
		::proto_ff::E_XingchenXcadvatt* temp_e_xingchenxcadvatt_list = msg.add_e_xingchenxcadvatt_list();
		E_XingchenXcadvatt_List[i].write_to_pbmsg(*temp_e_xingchenxcadvatt_list);
	}
}

void Sheet_XingchenXcadvatt_s::read_from_pbmsg(const ::proto_ff::Sheet_XingchenXcadvatt & msg) {
	E_XingchenXcadvatt_List.resize((int)msg.e_xingchenxcadvatt_list_size() > (int)E_XingchenXcadvatt_List.max_size() ? E_XingchenXcadvatt_List.max_size() : msg.e_xingchenxcadvatt_list_size());
	for(int32_t i = 0; i < (int32_t)E_XingchenXcadvatt_List.size(); ++i) {
		const ::proto_ff::E_XingchenXcadvatt & temp_e_xingchenxcadvatt_list = msg.e_xingchenxcadvatt_list(i);
		E_XingchenXcadvatt_List[i].read_from_pbmsg(temp_e_xingchenxcadvatt_list);
	}
}

E_XingchenXcguizhenXxDesc_s::E_XingchenXcguizhenXxDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_XingchenXcguizhenXxDesc_s::CreateInit() {
	m_value = (int32_t)0;
	m_type = (int32_t)0;
	return 0;
}

int E_XingchenXcguizhenXxDesc_s::ResumeInit() {
	return 0;
}

void E_XingchenXcguizhenXxDesc_s::write_to_pbmsg(::proto_ff::E_XingchenXcguizhenXxDesc & msg) const {
	msg.set_m_value((int32_t)m_value);
	msg.set_m_type((int32_t)m_type);
}

void E_XingchenXcguizhenXxDesc_s::read_from_pbmsg(const ::proto_ff::E_XingchenXcguizhenXxDesc & msg) {
	m_value = msg.m_value();
	m_type = msg.m_type();
}

E_XingchenXcguizhenGzDesc_s::E_XingchenXcguizhenGzDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_XingchenXcguizhenGzDesc_s::CreateInit() {
	m_value = (int32_t)0;
	m_type = (int32_t)0;
	return 0;
}

int E_XingchenXcguizhenGzDesc_s::ResumeInit() {
	return 0;
}

void E_XingchenXcguizhenGzDesc_s::write_to_pbmsg(::proto_ff::E_XingchenXcguizhenGzDesc & msg) const {
	msg.set_m_value((int32_t)m_value);
	msg.set_m_type((int32_t)m_type);
}

void E_XingchenXcguizhenGzDesc_s::read_from_pbmsg(const ::proto_ff::E_XingchenXcguizhenGzDesc & msg) {
	m_value = msg.m_value();
	m_type = msg.m_type();
}

E_XingchenXcguizhen_s::E_XingchenXcguizhen_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_XingchenXcguizhen_s::CreateInit() {
	m_id = (int32_t)0;
	m_xsid = (int32_t)0;
	m_gzquality = (int32_t)0;
	m_gznum = (int32_t)0;
	m_gzxh = (int32_t)0;
	return 0;
}

int E_XingchenXcguizhen_s::ResumeInit() {
	return 0;
}

void E_XingchenXcguizhen_s::write_to_pbmsg(::proto_ff::E_XingchenXcguizhen & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_xsid((int32_t)m_xsid);
	msg.set_m_gzquality((int32_t)m_gzquality);
	msg.set_m_gznum((int32_t)m_gznum);
	msg.set_m_gzxh((int32_t)m_gzxh);
	for(int32_t i = 0; i < (int32_t)m_xx.size(); ++i) {
		::proto_ff::E_XingchenXcguizhenXxDesc* temp_m_xx = msg.add_m_xx();
		m_xx[i].write_to_pbmsg(*temp_m_xx);
	}
	for(int32_t i = 0; i < (int32_t)m_gz.size(); ++i) {
		::proto_ff::E_XingchenXcguizhenGzDesc* temp_m_gz = msg.add_m_gz();
		m_gz[i].write_to_pbmsg(*temp_m_gz);
	}
}

void E_XingchenXcguizhen_s::read_from_pbmsg(const ::proto_ff::E_XingchenXcguizhen & msg) {
	m_id = msg.m_id();
	m_xsid = msg.m_xsid();
	m_gzquality = msg.m_gzquality();
	m_gznum = msg.m_gznum();
	m_gzxh = msg.m_gzxh();
	m_xx.resize((int)msg.m_xx_size() > (int)m_xx.max_size() ? m_xx.max_size() : msg.m_xx_size());
	for(int32_t i = 0; i < (int32_t)m_xx.size(); ++i) {
		const ::proto_ff::E_XingchenXcguizhenXxDesc & temp_m_xx = msg.m_xx(i);
		m_xx[i].read_from_pbmsg(temp_m_xx);
	}
	m_gz.resize((int)msg.m_gz_size() > (int)m_gz.max_size() ? m_gz.max_size() : msg.m_gz_size());
	for(int32_t i = 0; i < (int32_t)m_gz.size(); ++i) {
		const ::proto_ff::E_XingchenXcguizhenGzDesc & temp_m_gz = msg.m_gz(i);
		m_gz[i].read_from_pbmsg(temp_m_gz);
	}
}

Sheet_XingchenXcguizhen_s::Sheet_XingchenXcguizhen_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_XingchenXcguizhen_s::CreateInit() {
	return 0;
}

int Sheet_XingchenXcguizhen_s::ResumeInit() {
	return 0;
}

void Sheet_XingchenXcguizhen_s::write_to_pbmsg(::proto_ff::Sheet_XingchenXcguizhen & msg) const {
	for(int32_t i = 0; i < (int32_t)E_XingchenXcguizhen_List.size(); ++i) {
		::proto_ff::E_XingchenXcguizhen* temp_e_xingchenxcguizhen_list = msg.add_e_xingchenxcguizhen_list();
		E_XingchenXcguizhen_List[i].write_to_pbmsg(*temp_e_xingchenxcguizhen_list);
	}
}

void Sheet_XingchenXcguizhen_s::read_from_pbmsg(const ::proto_ff::Sheet_XingchenXcguizhen & msg) {
	E_XingchenXcguizhen_List.resize((int)msg.e_xingchenxcguizhen_list_size() > (int)E_XingchenXcguizhen_List.max_size() ? E_XingchenXcguizhen_List.max_size() : msg.e_xingchenxcguizhen_list_size());
	for(int32_t i = 0; i < (int32_t)E_XingchenXcguizhen_List.size(); ++i) {
		const ::proto_ff::E_XingchenXcguizhen & temp_e_xingchenxcguizhen_list = msg.e_xingchenxcguizhen_list(i);
		E_XingchenXcguizhen_List[i].read_from_pbmsg(temp_e_xingchenxcguizhen_list);
	}
}

E_XingchenXingjunActDesc_s::E_XingchenXingjunActDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_XingchenXingjunActDesc_s::CreateInit() {
	m_id = (int32_t)0;
	m_num = (int32_t)0;
	return 0;
}

int E_XingchenXingjunActDesc_s::ResumeInit() {
	return 0;
}

void E_XingchenXingjunActDesc_s::write_to_pbmsg(::proto_ff::E_XingchenXingjunActDesc & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_num((int32_t)m_num);
}

void E_XingchenXingjunActDesc_s::read_from_pbmsg(const ::proto_ff::E_XingchenXingjunActDesc & msg) {
	m_id = msg.m_id();
	m_num = msg.m_num();
}

E_XingchenXingjun_s::E_XingchenXingjun_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_XingchenXingjun_s::CreateInit() {
	m_id = (int32_t)0;
	m_xstype = (int32_t)0;
	m_xjquality = (int32_t)0;
	return 0;
}

int E_XingchenXingjun_s::ResumeInit() {
	return 0;
}

void E_XingchenXingjun_s::write_to_pbmsg(::proto_ff::E_XingchenXingjun & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_xstype((int32_t)m_xstype);
	msg.set_m_xjquality((int32_t)m_xjquality);
	for(int32_t i = 0; i < (int32_t)m_act.size(); ++i) {
		::proto_ff::E_XingchenXingjunActDesc* temp_m_act = msg.add_m_act();
		m_act[i].write_to_pbmsg(*temp_m_act);
	}
}

void E_XingchenXingjun_s::read_from_pbmsg(const ::proto_ff::E_XingchenXingjun & msg) {
	m_id = msg.m_id();
	m_xstype = msg.m_xstype();
	m_xjquality = msg.m_xjquality();
	m_act.resize((int)msg.m_act_size() > (int)m_act.max_size() ? m_act.max_size() : msg.m_act_size());
	for(int32_t i = 0; i < (int32_t)m_act.size(); ++i) {
		const ::proto_ff::E_XingchenXingjunActDesc & temp_m_act = msg.m_act(i);
		m_act[i].read_from_pbmsg(temp_m_act);
	}
}

Sheet_XingchenXingjun_s::Sheet_XingchenXingjun_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_XingchenXingjun_s::CreateInit() {
	return 0;
}

int Sheet_XingchenXingjun_s::ResumeInit() {
	return 0;
}

void Sheet_XingchenXingjun_s::write_to_pbmsg(::proto_ff::Sheet_XingchenXingjun & msg) const {
	for(int32_t i = 0; i < (int32_t)E_XingchenXingjun_List.size(); ++i) {
		::proto_ff::E_XingchenXingjun* temp_e_xingchenxingjun_list = msg.add_e_xingchenxingjun_list();
		E_XingchenXingjun_List[i].write_to_pbmsg(*temp_e_xingchenxingjun_list);
	}
}

void Sheet_XingchenXingjun_s::read_from_pbmsg(const ::proto_ff::Sheet_XingchenXingjun & msg) {
	E_XingchenXingjun_List.resize((int)msg.e_xingchenxingjun_list_size() > (int)E_XingchenXingjun_List.max_size() ? E_XingchenXingjun_List.max_size() : msg.e_xingchenxingjun_list_size());
	for(int32_t i = 0; i < (int32_t)E_XingchenXingjun_List.size(); ++i) {
		const ::proto_ff::E_XingchenXingjun & temp_e_xingchenxingjun_list = msg.e_xingchenxingjun_list(i);
		E_XingchenXingjun_List[i].read_from_pbmsg(temp_e_xingchenxingjun_list);
	}
}

E_XingchenXjattXjDesc_s::E_XingchenXjattXjDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_XingchenXjattXjDesc_s::CreateInit() {
	m_value = (int32_t)0;
	m_type = (int32_t)0;
	return 0;
}

int E_XingchenXjattXjDesc_s::ResumeInit() {
	return 0;
}

void E_XingchenXjattXjDesc_s::write_to_pbmsg(::proto_ff::E_XingchenXjattXjDesc & msg) const {
	msg.set_m_value((int32_t)m_value);
	msg.set_m_type((int32_t)m_type);
}

void E_XingchenXjattXjDesc_s::read_from_pbmsg(const ::proto_ff::E_XingchenXjattXjDesc & msg) {
	m_value = msg.m_value();
	m_type = msg.m_type();
}

E_XingchenXjatt_s::E_XingchenXjatt_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_XingchenXjatt_s::CreateInit() {
	m_attid = (int64_t)0;
	return 0;
}

int E_XingchenXjatt_s::ResumeInit() {
	return 0;
}

void E_XingchenXjatt_s::write_to_pbmsg(::proto_ff::E_XingchenXjatt & msg) const {
	msg.set_m_attid((int64_t)m_attid);
	for(int32_t i = 0; i < (int32_t)m_xj.size(); ++i) {
		::proto_ff::E_XingchenXjattXjDesc* temp_m_xj = msg.add_m_xj();
		m_xj[i].write_to_pbmsg(*temp_m_xj);
	}
}

void E_XingchenXjatt_s::read_from_pbmsg(const ::proto_ff::E_XingchenXjatt & msg) {
	m_attid = msg.m_attid();
	m_xj.resize((int)msg.m_xj_size() > (int)m_xj.max_size() ? m_xj.max_size() : msg.m_xj_size());
	for(int32_t i = 0; i < (int32_t)m_xj.size(); ++i) {
		const ::proto_ff::E_XingchenXjattXjDesc & temp_m_xj = msg.m_xj(i);
		m_xj[i].read_from_pbmsg(temp_m_xj);
	}
}

Sheet_XingchenXjatt_s::Sheet_XingchenXjatt_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_XingchenXjatt_s::CreateInit() {
	return 0;
}

int Sheet_XingchenXjatt_s::ResumeInit() {
	return 0;
}

void Sheet_XingchenXjatt_s::write_to_pbmsg(::proto_ff::Sheet_XingchenXjatt & msg) const {
	for(int32_t i = 0; i < (int32_t)E_XingchenXjatt_List.size(); ++i) {
		::proto_ff::E_XingchenXjatt* temp_e_xingchenxjatt_list = msg.add_e_xingchenxjatt_list();
		E_XingchenXjatt_List[i].write_to_pbmsg(*temp_e_xingchenxjatt_list);
	}
}

void Sheet_XingchenXjatt_s::read_from_pbmsg(const ::proto_ff::Sheet_XingchenXjatt & msg) {
	E_XingchenXjatt_List.resize((int)msg.e_xingchenxjatt_list_size() > (int)E_XingchenXjatt_List.max_size() ? E_XingchenXjatt_List.max_size() : msg.e_xingchenxjatt_list_size());
	for(int32_t i = 0; i < (int32_t)E_XingchenXjatt_List.size(); ++i) {
		const ::proto_ff::E_XingchenXjatt & temp_e_xingchenxjatt_list = msg.e_xingchenxjatt_list(i);
		E_XingchenXjatt_List[i].read_from_pbmsg(temp_e_xingchenxjatt_list);
	}
}

E_XingchenXingji_s::E_XingchenXingji_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_XingchenXingji_s::CreateInit() {
	m_xjid = (int32_t)0;
	m_xjclass = (int32_t)0;
	m_xjskill = (int32_t)0;
	m_skillid = (int32_t)0;
	return 0;
}

int E_XingchenXingji_s::ResumeInit() {
	return 0;
}

void E_XingchenXingji_s::write_to_pbmsg(::proto_ff::E_XingchenXingji & msg) const {
	msg.set_m_xjid((int32_t)m_xjid);
	msg.set_m_xjclass((int32_t)m_xjclass);
	msg.set_m_xjskill((int32_t)m_xjskill);
	msg.set_m_skillid((int32_t)m_skillid);
	for(int32_t i = 0; i < (int32_t)m_unlock.size(); ++i) {
		msg.add_m_unlock((int32_t)m_unlock[i]);
	}
	for(int32_t i = 0; i < (int32_t)m_unlocklv.size(); ++i) {
		msg.add_m_unlocklv((int32_t)m_unlocklv[i]);
	}
}

void E_XingchenXingji_s::read_from_pbmsg(const ::proto_ff::E_XingchenXingji & msg) {
	m_xjid = msg.m_xjid();
	m_xjclass = msg.m_xjclass();
	m_xjskill = msg.m_xjskill();
	m_skillid = msg.m_skillid();
	m_unlock.resize((int)msg.m_unlock_size() > (int)m_unlock.max_size() ? m_unlock.max_size() : msg.m_unlock_size());
	for(int32_t i = 0; i < (int32_t)m_unlock.size(); ++i) {
		m_unlock[i] = msg.m_unlock(i);
	}
	m_unlocklv.resize((int)msg.m_unlocklv_size() > (int)m_unlocklv.max_size() ? m_unlocklv.max_size() : msg.m_unlocklv_size());
	for(int32_t i = 0; i < (int32_t)m_unlocklv.size(); ++i) {
		m_unlocklv[i] = msg.m_unlocklv(i);
	}
}

Sheet_XingchenXingji_s::Sheet_XingchenXingji_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_XingchenXingji_s::CreateInit() {
	return 0;
}

int Sheet_XingchenXingji_s::ResumeInit() {
	return 0;
}

void Sheet_XingchenXingji_s::write_to_pbmsg(::proto_ff::Sheet_XingchenXingji & msg) const {
	for(int32_t i = 0; i < (int32_t)E_XingchenXingji_List.size(); ++i) {
		::proto_ff::E_XingchenXingji* temp_e_xingchenxingji_list = msg.add_e_xingchenxingji_list();
		E_XingchenXingji_List[i].write_to_pbmsg(*temp_e_xingchenxingji_list);
	}
}

void Sheet_XingchenXingji_s::read_from_pbmsg(const ::proto_ff::Sheet_XingchenXingji & msg) {
	E_XingchenXingji_List.resize((int)msg.e_xingchenxingji_list_size() > (int)E_XingchenXingji_List.max_size() ? E_XingchenXingji_List.max_size() : msg.e_xingchenxingji_list_size());
	for(int32_t i = 0; i < (int32_t)E_XingchenXingji_List.size(); ++i) {
		const ::proto_ff::E_XingchenXingji & temp_e_xingchenxingji_list = msg.e_xingchenxingji_list(i);
		E_XingchenXingji_List[i].read_from_pbmsg(temp_e_xingchenxingji_list);
	}
}

E_XingchenXjcw_s::E_XingchenXjcw_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_XingchenXjcw_s::CreateInit() {
	m_xjslot = (int32_t)0;
	m_unlock = (int32_t)0;
	m_num = (int32_t)0;
	return 0;
}

int E_XingchenXjcw_s::ResumeInit() {
	return 0;
}

void E_XingchenXjcw_s::write_to_pbmsg(::proto_ff::E_XingchenXjcw & msg) const {
	msg.set_m_xjslot((int32_t)m_xjslot);
	msg.set_m_unlock((int32_t)m_unlock);
	msg.set_m_num((int32_t)m_num);
}

void E_XingchenXjcw_s::read_from_pbmsg(const ::proto_ff::E_XingchenXjcw & msg) {
	m_xjslot = msg.m_xjslot();
	m_unlock = msg.m_unlock();
	m_num = msg.m_num();
}

Sheet_XingchenXjcw_s::Sheet_XingchenXjcw_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_XingchenXjcw_s::CreateInit() {
	return 0;
}

int Sheet_XingchenXjcw_s::ResumeInit() {
	return 0;
}

void Sheet_XingchenXjcw_s::write_to_pbmsg(::proto_ff::Sheet_XingchenXjcw & msg) const {
	for(int32_t i = 0; i < (int32_t)E_XingchenXjcw_List.size(); ++i) {
		::proto_ff::E_XingchenXjcw* temp_e_xingchenxjcw_list = msg.add_e_xingchenxjcw_list();
		E_XingchenXjcw_List[i].write_to_pbmsg(*temp_e_xingchenxjcw_list);
	}
}

void Sheet_XingchenXjcw_s::read_from_pbmsg(const ::proto_ff::Sheet_XingchenXjcw & msg) {
	E_XingchenXjcw_List.resize((int)msg.e_xingchenxjcw_list_size() > (int)E_XingchenXjcw_List.max_size() ? E_XingchenXjcw_List.max_size() : msg.e_xingchenxjcw_list_size());
	for(int32_t i = 0; i < (int32_t)E_XingchenXjcw_List.size(); ++i) {
		const ::proto_ff::E_XingchenXjcw & temp_e_xingchenxjcw_list = msg.e_xingchenxjcw_list(i);
		E_XingchenXjcw_List[i].read_from_pbmsg(temp_e_xingchenxjcw_list);
	}
}

E_XingchenXjlvexp_s::E_XingchenXjlvexp_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_XingchenXjlvexp_s::CreateInit() {
	m_lv = (int32_t)0;
	m_exp = (int32_t)0;
	m_time = (int32_t)0;
	return 0;
}

int E_XingchenXjlvexp_s::ResumeInit() {
	return 0;
}

void E_XingchenXjlvexp_s::write_to_pbmsg(::proto_ff::E_XingchenXjlvexp & msg) const {
	msg.set_m_lv((int32_t)m_lv);
	msg.set_m_exp((int32_t)m_exp);
	msg.set_m_time((int32_t)m_time);
}

void E_XingchenXjlvexp_s::read_from_pbmsg(const ::proto_ff::E_XingchenXjlvexp & msg) {
	m_lv = msg.m_lv();
	m_exp = msg.m_exp();
	m_time = msg.m_time();
}

Sheet_XingchenXjlvexp_s::Sheet_XingchenXjlvexp_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_XingchenXjlvexp_s::CreateInit() {
	return 0;
}

int Sheet_XingchenXjlvexp_s::ResumeInit() {
	return 0;
}

void Sheet_XingchenXjlvexp_s::write_to_pbmsg(::proto_ff::Sheet_XingchenXjlvexp & msg) const {
	for(int32_t i = 0; i < (int32_t)E_XingchenXjlvexp_List.size(); ++i) {
		::proto_ff::E_XingchenXjlvexp* temp_e_xingchenxjlvexp_list = msg.add_e_xingchenxjlvexp_list();
		E_XingchenXjlvexp_List[i].write_to_pbmsg(*temp_e_xingchenxjlvexp_list);
	}
}

void Sheet_XingchenXjlvexp_s::read_from_pbmsg(const ::proto_ff::Sheet_XingchenXjlvexp & msg) {
	E_XingchenXjlvexp_List.resize((int)msg.e_xingchenxjlvexp_list_size() > (int)E_XingchenXjlvexp_List.max_size() ? E_XingchenXjlvexp_List.max_size() : msg.e_xingchenxjlvexp_list_size());
	for(int32_t i = 0; i < (int32_t)E_XingchenXjlvexp_List.size(); ++i) {
		const ::proto_ff::E_XingchenXjlvexp & temp_e_xingchenxjlvexp_list = msg.e_xingchenxjlvexp_list(i);
		E_XingchenXjlvexp_List[i].read_from_pbmsg(temp_e_xingchenxjlvexp_list);
	}
}

E_XingchenZbshop_s::E_XingchenZbshop_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_XingchenZbshop_s::CreateInit() {
	m_shopid = (int32_t)0;
	m_shopitem = (int32_t)0;
	m_shopquota = (int32_t)0;
	m_shopnum = (int32_t)0;
	m_buyconsume = (int32_t)0;
	m_buynum = (int32_t)0;
	return 0;
}

int E_XingchenZbshop_s::ResumeInit() {
	return 0;
}

void E_XingchenZbshop_s::write_to_pbmsg(::proto_ff::E_XingchenZbshop & msg) const {
	msg.set_m_shopid((int32_t)m_shopid);
	msg.set_m_shopitem((int32_t)m_shopitem);
	msg.set_m_shopquota((int32_t)m_shopquota);
	msg.set_m_shopnum((int32_t)m_shopnum);
	msg.set_m_buyconsume((int32_t)m_buyconsume);
	msg.set_m_buynum((int32_t)m_buynum);
}

void E_XingchenZbshop_s::read_from_pbmsg(const ::proto_ff::E_XingchenZbshop & msg) {
	m_shopid = msg.m_shopid();
	m_shopitem = msg.m_shopitem();
	m_shopquota = msg.m_shopquota();
	m_shopnum = msg.m_shopnum();
	m_buyconsume = msg.m_buyconsume();
	m_buynum = msg.m_buynum();
}

Sheet_XingchenZbshop_s::Sheet_XingchenZbshop_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_XingchenZbshop_s::CreateInit() {
	return 0;
}

int Sheet_XingchenZbshop_s::ResumeInit() {
	return 0;
}

void Sheet_XingchenZbshop_s::write_to_pbmsg(::proto_ff::Sheet_XingchenZbshop & msg) const {
	for(int32_t i = 0; i < (int32_t)E_XingchenZbshop_List.size(); ++i) {
		::proto_ff::E_XingchenZbshop* temp_e_xingchenzbshop_list = msg.add_e_xingchenzbshop_list();
		E_XingchenZbshop_List[i].write_to_pbmsg(*temp_e_xingchenzbshop_list);
	}
}

void Sheet_XingchenZbshop_s::read_from_pbmsg(const ::proto_ff::Sheet_XingchenZbshop & msg) {
	E_XingchenZbshop_List.resize((int)msg.e_xingchenzbshop_list_size() > (int)E_XingchenZbshop_List.max_size() ? E_XingchenZbshop_List.max_size() : msg.e_xingchenzbshop_list_size());
	for(int32_t i = 0; i < (int32_t)E_XingchenZbshop_List.size(); ++i) {
		const ::proto_ff::E_XingchenZbshop & temp_e_xingchenzbshop_list = msg.e_xingchenzbshop_list(i);
		E_XingchenZbshop_List[i].read_from_pbmsg(temp_e_xingchenzbshop_list);
	}
}

}
