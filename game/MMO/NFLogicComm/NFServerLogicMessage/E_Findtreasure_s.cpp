#include "E_Findtreasure_s.h"

namespace proto_ff_s {

E_FindtreasureFindtreasure_s::E_FindtreasureFindtreasure_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_FindtreasureFindtreasure_s::CreateInit() {
	m_id = (int32_t)0;
	m_type = (int32_t)0;
	m_functionunlock = (int32_t)0;
	m_costid = (int64_t)0;
	m_contitem = (int32_t)0;
	m_loop = (int32_t)0;
	m_pooltime = (int32_t)0;
	m_totalgroupid = (int32_t)0;
	m_activegroupid = (int32_t)0;
	m_protecttime = (int32_t)0;
	m_additem = (int32_t)0;
	m_addnum = (int32_t)0;
	m_shopid = (int32_t)0;
	m_storehousetype = (int32_t)0;
	return 0;
}

int E_FindtreasureFindtreasure_s::ResumeInit() {
	return 0;
}

void E_FindtreasureFindtreasure_s::write_to_pbmsg(::proto_ff::E_FindtreasureFindtreasure & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_type((int32_t)m_type);
	msg.set_m_functionunlock((int32_t)m_functionunlock);
	msg.set_m_costid((int64_t)m_costid);
	msg.set_m_costnum(m_costnum.data());
	msg.set_m_contitem((int32_t)m_contitem);
	msg.set_m_poolgroupid(m_poolgroupid.data());
	msg.set_m_loop((int32_t)m_loop);
	msg.set_m_pooltime((int32_t)m_pooltime);
	msg.set_m_totalgroupid((int32_t)m_totalgroupid);
	msg.set_m_activegroupid((int32_t)m_activegroupid);
	msg.set_m_protecttime((int32_t)m_protecttime);
	msg.set_m_additem((int32_t)m_additem);
	msg.set_m_addnum((int32_t)m_addnum);
	msg.set_m_shopid((int32_t)m_shopid);
	msg.set_m_storehousetype((int32_t)m_storehousetype);
}

void E_FindtreasureFindtreasure_s::read_from_pbmsg(const ::proto_ff::E_FindtreasureFindtreasure & msg) {
	m_id = msg.m_id();
	m_type = msg.m_type();
	m_functionunlock = msg.m_functionunlock();
	m_costid = msg.m_costid();
	m_costnum = msg.m_costnum();
	m_contitem = msg.m_contitem();
	m_poolgroupid = msg.m_poolgroupid();
	m_loop = msg.m_loop();
	m_pooltime = msg.m_pooltime();
	m_totalgroupid = msg.m_totalgroupid();
	m_activegroupid = msg.m_activegroupid();
	m_protecttime = msg.m_protecttime();
	m_additem = msg.m_additem();
	m_addnum = msg.m_addnum();
	m_shopid = msg.m_shopid();
	m_storehousetype = msg.m_storehousetype();
}

Sheet_FindtreasureFindtreasure_s::Sheet_FindtreasureFindtreasure_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_FindtreasureFindtreasure_s::CreateInit() {
	return 0;
}

int Sheet_FindtreasureFindtreasure_s::ResumeInit() {
	return 0;
}

void Sheet_FindtreasureFindtreasure_s::write_to_pbmsg(::proto_ff::Sheet_FindtreasureFindtreasure & msg) const {
	for(int32_t i = 0; i < (int32_t)E_FindtreasureFindtreasure_List.size(); ++i) {
		::proto_ff::E_FindtreasureFindtreasure* temp_e_findtreasurefindtreasure_list = msg.add_e_findtreasurefindtreasure_list();
		E_FindtreasureFindtreasure_List[i].write_to_pbmsg(*temp_e_findtreasurefindtreasure_list);
	}
}

void Sheet_FindtreasureFindtreasure_s::read_from_pbmsg(const ::proto_ff::Sheet_FindtreasureFindtreasure & msg) {
	E_FindtreasureFindtreasure_List.resize((int)msg.e_findtreasurefindtreasure_list_size() > (int)E_FindtreasureFindtreasure_List.max_size() ? E_FindtreasureFindtreasure_List.max_size() : msg.e_findtreasurefindtreasure_list_size());
	for(int32_t i = 0; i < (int32_t)E_FindtreasureFindtreasure_List.size(); ++i) {
		const ::proto_ff::E_FindtreasureFindtreasure & temp_e_findtreasurefindtreasure_list = msg.e_findtreasurefindtreasure_list(i);
		E_FindtreasureFindtreasure_List[i].read_from_pbmsg(temp_e_findtreasurefindtreasure_list);
	}
}

E_FindtreasureFindpool_s::E_FindtreasureFindpool_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_FindtreasureFindpool_s::CreateInit() {
	m_id = (int32_t)0;
	m_groupid = (int32_t)0;
	m_showorder = (int32_t)0;
	m_itemid = (int64_t)0;
	m_num = (int32_t)0;
	m_prof = (int32_t)0;
	m_weights = (int32_t)0;
	m_proweights = (int32_t)0;
	m_record = (int32_t)0;
	return 0;
}

int E_FindtreasureFindpool_s::ResumeInit() {
	return 0;
}

void E_FindtreasureFindpool_s::write_to_pbmsg(::proto_ff::E_FindtreasureFindpool & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_groupid((int32_t)m_groupid);
	msg.set_m_showorder((int32_t)m_showorder);
	msg.set_m_itemid((int64_t)m_itemid);
	msg.set_m_num((int32_t)m_num);
	msg.set_m_prof((int32_t)m_prof);
	msg.set_m_weights((int32_t)m_weights);
	msg.set_m_proweights((int32_t)m_proweights);
	msg.set_m_record((int32_t)m_record);
}

void E_FindtreasureFindpool_s::read_from_pbmsg(const ::proto_ff::E_FindtreasureFindpool & msg) {
	m_id = msg.m_id();
	m_groupid = msg.m_groupid();
	m_showorder = msg.m_showorder();
	m_itemid = msg.m_itemid();
	m_num = msg.m_num();
	m_prof = msg.m_prof();
	m_weights = msg.m_weights();
	m_proweights = msg.m_proweights();
	m_record = msg.m_record();
}

Sheet_FindtreasureFindpool_s::Sheet_FindtreasureFindpool_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_FindtreasureFindpool_s::CreateInit() {
	return 0;
}

int Sheet_FindtreasureFindpool_s::ResumeInit() {
	return 0;
}

void Sheet_FindtreasureFindpool_s::write_to_pbmsg(::proto_ff::Sheet_FindtreasureFindpool & msg) const {
	for(int32_t i = 0; i < (int32_t)E_FindtreasureFindpool_List.size(); ++i) {
		::proto_ff::E_FindtreasureFindpool* temp_e_findtreasurefindpool_list = msg.add_e_findtreasurefindpool_list();
		E_FindtreasureFindpool_List[i].write_to_pbmsg(*temp_e_findtreasurefindpool_list);
	}
}

void Sheet_FindtreasureFindpool_s::read_from_pbmsg(const ::proto_ff::Sheet_FindtreasureFindpool & msg) {
	E_FindtreasureFindpool_List.resize((int)msg.e_findtreasurefindpool_list_size() > (int)E_FindtreasureFindpool_List.max_size() ? E_FindtreasureFindpool_List.max_size() : msg.e_findtreasurefindpool_list_size());
	for(int32_t i = 0; i < (int32_t)E_FindtreasureFindpool_List.size(); ++i) {
		const ::proto_ff::E_FindtreasureFindpool & temp_e_findtreasurefindpool_list = msg.e_findtreasurefindpool_list(i);
		E_FindtreasureFindpool_List[i].read_from_pbmsg(temp_e_findtreasurefindpool_list);
	}
}

E_FindtreasureConstant_s::E_FindtreasureConstant_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_FindtreasureConstant_s::CreateInit() {
	m_id = (int32_t)0;
	m_dragonsevertime = (int32_t)0;
	m_godsevertime = (int32_t)0;
	return 0;
}

int E_FindtreasureConstant_s::ResumeInit() {
	return 0;
}

void E_FindtreasureConstant_s::write_to_pbmsg(::proto_ff::E_FindtreasureConstant & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_dragonsevertime((int32_t)m_dragonsevertime);
	msg.set_m_godsevertime((int32_t)m_godsevertime);
}

void E_FindtreasureConstant_s::read_from_pbmsg(const ::proto_ff::E_FindtreasureConstant & msg) {
	m_id = msg.m_id();
	m_dragonsevertime = msg.m_dragonsevertime();
	m_godsevertime = msg.m_godsevertime();
}

Sheet_FindtreasureConstant_s::Sheet_FindtreasureConstant_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_FindtreasureConstant_s::CreateInit() {
	return 0;
}

int Sheet_FindtreasureConstant_s::ResumeInit() {
	return 0;
}

void Sheet_FindtreasureConstant_s::write_to_pbmsg(::proto_ff::Sheet_FindtreasureConstant & msg) const {
	for(int32_t i = 0; i < (int32_t)E_FindtreasureConstant_List.size(); ++i) {
		::proto_ff::E_FindtreasureConstant* temp_e_findtreasureconstant_list = msg.add_e_findtreasureconstant_list();
		E_FindtreasureConstant_List[i].write_to_pbmsg(*temp_e_findtreasureconstant_list);
	}
}

void Sheet_FindtreasureConstant_s::read_from_pbmsg(const ::proto_ff::Sheet_FindtreasureConstant & msg) {
	E_FindtreasureConstant_List.resize((int)msg.e_findtreasureconstant_list_size() > (int)E_FindtreasureConstant_List.max_size() ? E_FindtreasureConstant_List.max_size() : msg.e_findtreasureconstant_list_size());
	for(int32_t i = 0; i < (int32_t)E_FindtreasureConstant_List.size(); ++i) {
		const ::proto_ff::E_FindtreasureConstant & temp_e_findtreasureconstant_list = msg.e_findtreasureconstant_list(i);
		E_FindtreasureConstant_List[i].read_from_pbmsg(temp_e_findtreasureconstant_list);
	}
}

E_FindtreasureTotal_s::E_FindtreasureTotal_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_FindtreasureTotal_s::CreateInit() {
	m_id = (int32_t)0;
	m_groupid = (int32_t)0;
	m_type = (int32_t)0;
	m_itemid = (int32_t)0;
	m_num = (int32_t)0;
	return 0;
}

int E_FindtreasureTotal_s::ResumeInit() {
	return 0;
}

void E_FindtreasureTotal_s::write_to_pbmsg(::proto_ff::E_FindtreasureTotal & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_groupid((int32_t)m_groupid);
	msg.set_m_type((int32_t)m_type);
	msg.set_m_itemid((int32_t)m_itemid);
	msg.set_m_num((int32_t)m_num);
	for(int32_t i = 0; i < (int32_t)m_arg.size(); ++i) {
		msg.add_m_arg((int32_t)m_arg[i]);
	}
}

void E_FindtreasureTotal_s::read_from_pbmsg(const ::proto_ff::E_FindtreasureTotal & msg) {
	m_id = msg.m_id();
	m_groupid = msg.m_groupid();
	m_type = msg.m_type();
	m_itemid = msg.m_itemid();
	m_num = msg.m_num();
	m_arg.resize((int)msg.m_arg_size() > (int)m_arg.max_size() ? m_arg.max_size() : msg.m_arg_size());
	for(int32_t i = 0; i < (int32_t)m_arg.size(); ++i) {
		m_arg[i] = msg.m_arg(i);
	}
}

Sheet_FindtreasureTotal_s::Sheet_FindtreasureTotal_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_FindtreasureTotal_s::CreateInit() {
	return 0;
}

int Sheet_FindtreasureTotal_s::ResumeInit() {
	return 0;
}

void Sheet_FindtreasureTotal_s::write_to_pbmsg(::proto_ff::Sheet_FindtreasureTotal & msg) const {
	for(int32_t i = 0; i < (int32_t)E_FindtreasureTotal_List.size(); ++i) {
		::proto_ff::E_FindtreasureTotal* temp_e_findtreasuretotal_list = msg.add_e_findtreasuretotal_list();
		E_FindtreasureTotal_List[i].write_to_pbmsg(*temp_e_findtreasuretotal_list);
	}
}

void Sheet_FindtreasureTotal_s::read_from_pbmsg(const ::proto_ff::Sheet_FindtreasureTotal & msg) {
	E_FindtreasureTotal_List.resize((int)msg.e_findtreasuretotal_list_size() > (int)E_FindtreasureTotal_List.max_size() ? E_FindtreasureTotal_List.max_size() : msg.e_findtreasuretotal_list_size());
	for(int32_t i = 0; i < (int32_t)E_FindtreasureTotal_List.size(); ++i) {
		const ::proto_ff::E_FindtreasureTotal & temp_e_findtreasuretotal_list = msg.e_findtreasuretotal_list(i);
		E_FindtreasureTotal_List[i].read_from_pbmsg(temp_e_findtreasuretotal_list);
	}
}

E_FindtreasureActive_s::E_FindtreasureActive_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_FindtreasureActive_s::CreateInit() {
	m_id = (int32_t)0;
	m_groupid = (int32_t)0;
	m_opentime = (int32_t)0;
	m_durtime = (int32_t)0;
	m_closetime = (int32_t)0;
	m_type = (int32_t)0;
	m_typegroupid = (int32_t)0;
	return 0;
}

int E_FindtreasureActive_s::ResumeInit() {
	return 0;
}

void E_FindtreasureActive_s::write_to_pbmsg(::proto_ff::E_FindtreasureActive & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_groupid((int32_t)m_groupid);
	msg.set_m_opentime((int32_t)m_opentime);
	msg.set_m_durtime((int32_t)m_durtime);
	msg.set_m_closetime((int32_t)m_closetime);
	msg.set_m_type((int32_t)m_type);
	msg.set_m_typegroupid((int32_t)m_typegroupid);
}

void E_FindtreasureActive_s::read_from_pbmsg(const ::proto_ff::E_FindtreasureActive & msg) {
	m_id = msg.m_id();
	m_groupid = msg.m_groupid();
	m_opentime = msg.m_opentime();
	m_durtime = msg.m_durtime();
	m_closetime = msg.m_closetime();
	m_type = msg.m_type();
	m_typegroupid = msg.m_typegroupid();
}

Sheet_FindtreasureActive_s::Sheet_FindtreasureActive_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_FindtreasureActive_s::CreateInit() {
	return 0;
}

int Sheet_FindtreasureActive_s::ResumeInit() {
	return 0;
}

void Sheet_FindtreasureActive_s::write_to_pbmsg(::proto_ff::Sheet_FindtreasureActive & msg) const {
	for(int32_t i = 0; i < (int32_t)E_FindtreasureActive_List.size(); ++i) {
		::proto_ff::E_FindtreasureActive* temp_e_findtreasureactive_list = msg.add_e_findtreasureactive_list();
		E_FindtreasureActive_List[i].write_to_pbmsg(*temp_e_findtreasureactive_list);
	}
}

void Sheet_FindtreasureActive_s::read_from_pbmsg(const ::proto_ff::Sheet_FindtreasureActive & msg) {
	E_FindtreasureActive_List.resize((int)msg.e_findtreasureactive_list_size() > (int)E_FindtreasureActive_List.max_size() ? E_FindtreasureActive_List.max_size() : msg.e_findtreasureactive_list_size());
	for(int32_t i = 0; i < (int32_t)E_FindtreasureActive_List.size(); ++i) {
		const ::proto_ff::E_FindtreasureActive & temp_e_findtreasureactive_list = msg.e_findtreasureactive_list(i);
		E_FindtreasureActive_List[i].read_from_pbmsg(temp_e_findtreasureactive_list);
	}
}

E_FindtreasureActiveup_s::E_FindtreasureActiveup_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_FindtreasureActiveup_s::CreateInit() {
	m_id = (int32_t)0;
	m_groupid = (int32_t)0;
	m_type = (int32_t)0;
	m_itemid = (int32_t)0;
	m_proarg = (int32_t)0;
	return 0;
}

int E_FindtreasureActiveup_s::ResumeInit() {
	return 0;
}

void E_FindtreasureActiveup_s::write_to_pbmsg(::proto_ff::E_FindtreasureActiveup & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_groupid((int32_t)m_groupid);
	msg.set_m_type((int32_t)m_type);
	msg.set_m_itemid((int32_t)m_itemid);
	msg.set_m_proarg((int32_t)m_proarg);
}

void E_FindtreasureActiveup_s::read_from_pbmsg(const ::proto_ff::E_FindtreasureActiveup & msg) {
	m_id = msg.m_id();
	m_groupid = msg.m_groupid();
	m_type = msg.m_type();
	m_itemid = msg.m_itemid();
	m_proarg = msg.m_proarg();
}

Sheet_FindtreasureActiveup_s::Sheet_FindtreasureActiveup_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_FindtreasureActiveup_s::CreateInit() {
	return 0;
}

int Sheet_FindtreasureActiveup_s::ResumeInit() {
	return 0;
}

void Sheet_FindtreasureActiveup_s::write_to_pbmsg(::proto_ff::Sheet_FindtreasureActiveup & msg) const {
	for(int32_t i = 0; i < (int32_t)E_FindtreasureActiveup_List.size(); ++i) {
		::proto_ff::E_FindtreasureActiveup* temp_e_findtreasureactiveup_list = msg.add_e_findtreasureactiveup_list();
		E_FindtreasureActiveup_List[i].write_to_pbmsg(*temp_e_findtreasureactiveup_list);
	}
}

void Sheet_FindtreasureActiveup_s::read_from_pbmsg(const ::proto_ff::Sheet_FindtreasureActiveup & msg) {
	E_FindtreasureActiveup_List.resize((int)msg.e_findtreasureactiveup_list_size() > (int)E_FindtreasureActiveup_List.max_size() ? E_FindtreasureActiveup_List.max_size() : msg.e_findtreasureactiveup_list_size());
	for(int32_t i = 0; i < (int32_t)E_FindtreasureActiveup_List.size(); ++i) {
		const ::proto_ff::E_FindtreasureActiveup & temp_e_findtreasureactiveup_list = msg.e_findtreasureactiveup_list(i);
		E_FindtreasureActiveup_List[i].read_from_pbmsg(temp_e_findtreasureactiveup_list);
	}
}

E_FindtreasureActivegoods_s::E_FindtreasureActivegoods_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_FindtreasureActivegoods_s::CreateInit() {
	m_groupid = (int32_t)0;
	m_itemid = (int32_t)0;
	m_type = (int32_t)0;
	m_price = (int32_t)0;
	m_itemnum = (int32_t)0;
	return 0;
}

int E_FindtreasureActivegoods_s::ResumeInit() {
	return 0;
}

void E_FindtreasureActivegoods_s::write_to_pbmsg(::proto_ff::E_FindtreasureActivegoods & msg) const {
	msg.set_m_groupid((int32_t)m_groupid);
	msg.set_m_itemid((int32_t)m_itemid);
	msg.set_m_type((int32_t)m_type);
	msg.set_m_price((int32_t)m_price);
	msg.set_m_itemnum((int32_t)m_itemnum);
}

void E_FindtreasureActivegoods_s::read_from_pbmsg(const ::proto_ff::E_FindtreasureActivegoods & msg) {
	m_groupid = msg.m_groupid();
	m_itemid = msg.m_itemid();
	m_type = msg.m_type();
	m_price = msg.m_price();
	m_itemnum = msg.m_itemnum();
}

Sheet_FindtreasureActivegoods_s::Sheet_FindtreasureActivegoods_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_FindtreasureActivegoods_s::CreateInit() {
	return 0;
}

int Sheet_FindtreasureActivegoods_s::ResumeInit() {
	return 0;
}

void Sheet_FindtreasureActivegoods_s::write_to_pbmsg(::proto_ff::Sheet_FindtreasureActivegoods & msg) const {
	for(int32_t i = 0; i < (int32_t)E_FindtreasureActivegoods_List.size(); ++i) {
		::proto_ff::E_FindtreasureActivegoods* temp_e_findtreasureactivegoods_list = msg.add_e_findtreasureactivegoods_list();
		E_FindtreasureActivegoods_List[i].write_to_pbmsg(*temp_e_findtreasureactivegoods_list);
	}
}

void Sheet_FindtreasureActivegoods_s::read_from_pbmsg(const ::proto_ff::Sheet_FindtreasureActivegoods & msg) {
	E_FindtreasureActivegoods_List.resize((int)msg.e_findtreasureactivegoods_list_size() > (int)E_FindtreasureActivegoods_List.max_size() ? E_FindtreasureActivegoods_List.max_size() : msg.e_findtreasureactivegoods_list_size());
	for(int32_t i = 0; i < (int32_t)E_FindtreasureActivegoods_List.size(); ++i) {
		const ::proto_ff::E_FindtreasureActivegoods & temp_e_findtreasureactivegoods_list = msg.e_findtreasureactivegoods_list(i);
		E_FindtreasureActivegoods_List[i].read_from_pbmsg(temp_e_findtreasureactivegoods_list);
	}
}

E_FindtreasureActiveshopGoodDesc_s::E_FindtreasureActiveshopGoodDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_FindtreasureActiveshopGoodDesc_s::CreateInit() {
	m_num = (int32_t)0;
	m_id = (int32_t)0;
	return 0;
}

int E_FindtreasureActiveshopGoodDesc_s::ResumeInit() {
	return 0;
}

void E_FindtreasureActiveshopGoodDesc_s::write_to_pbmsg(::proto_ff::E_FindtreasureActiveshopGoodDesc & msg) const {
	msg.set_m_num((int32_t)m_num);
	msg.set_m_id((int32_t)m_id);
}

void E_FindtreasureActiveshopGoodDesc_s::read_from_pbmsg(const ::proto_ff::E_FindtreasureActiveshopGoodDesc & msg) {
	m_num = msg.m_num();
	m_id = msg.m_id();
}

E_FindtreasureActiveshop_s::E_FindtreasureActiveshop_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_FindtreasureActiveshop_s::CreateInit() {
	m_id = (int32_t)0;
	m_groupid = (int32_t)0;
	m_type = (int32_t)0;
	m_price = (int32_t)0;
	m_times = (int32_t)0;
	return 0;
}

int E_FindtreasureActiveshop_s::ResumeInit() {
	return 0;
}

void E_FindtreasureActiveshop_s::write_to_pbmsg(::proto_ff::E_FindtreasureActiveshop & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_groupid((int32_t)m_groupid);
	msg.set_m_type((int32_t)m_type);
	msg.set_m_price((int32_t)m_price);
	msg.set_m_times((int32_t)m_times);
	for(int32_t i = 0; i < (int32_t)m_good.size(); ++i) {
		::proto_ff::E_FindtreasureActiveshopGoodDesc* temp_m_good = msg.add_m_good();
		m_good[i].write_to_pbmsg(*temp_m_good);
	}
}

void E_FindtreasureActiveshop_s::read_from_pbmsg(const ::proto_ff::E_FindtreasureActiveshop & msg) {
	m_id = msg.m_id();
	m_groupid = msg.m_groupid();
	m_type = msg.m_type();
	m_price = msg.m_price();
	m_times = msg.m_times();
	m_good.resize((int)msg.m_good_size() > (int)m_good.max_size() ? m_good.max_size() : msg.m_good_size());
	for(int32_t i = 0; i < (int32_t)m_good.size(); ++i) {
		const ::proto_ff::E_FindtreasureActiveshopGoodDesc & temp_m_good = msg.m_good(i);
		m_good[i].read_from_pbmsg(temp_m_good);
	}
}

Sheet_FindtreasureActiveshop_s::Sheet_FindtreasureActiveshop_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_FindtreasureActiveshop_s::CreateInit() {
	return 0;
}

int Sheet_FindtreasureActiveshop_s::ResumeInit() {
	return 0;
}

void Sheet_FindtreasureActiveshop_s::write_to_pbmsg(::proto_ff::Sheet_FindtreasureActiveshop & msg) const {
	for(int32_t i = 0; i < (int32_t)E_FindtreasureActiveshop_List.size(); ++i) {
		::proto_ff::E_FindtreasureActiveshop* temp_e_findtreasureactiveshop_list = msg.add_e_findtreasureactiveshop_list();
		E_FindtreasureActiveshop_List[i].write_to_pbmsg(*temp_e_findtreasureactiveshop_list);
	}
}

void Sheet_FindtreasureActiveshop_s::read_from_pbmsg(const ::proto_ff::Sheet_FindtreasureActiveshop & msg) {
	E_FindtreasureActiveshop_List.resize((int)msg.e_findtreasureactiveshop_list_size() > (int)E_FindtreasureActiveshop_List.max_size() ? E_FindtreasureActiveshop_List.max_size() : msg.e_findtreasureactiveshop_list_size());
	for(int32_t i = 0; i < (int32_t)E_FindtreasureActiveshop_List.size(); ++i) {
		const ::proto_ff::E_FindtreasureActiveshop & temp_e_findtreasureactiveshop_list = msg.e_findtreasureactiveshop_list(i);
		E_FindtreasureActiveshop_List[i].read_from_pbmsg(temp_e_findtreasureactiveshop_list);
	}
}

E_FindtreasureShop_s::E_FindtreasureShop_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_FindtreasureShop_s::CreateInit() {
	m_id = (int32_t)0;
	m_groupid = (int32_t)0;
	m_goodsid = (int32_t)0;
	m_goodsnum = (int32_t)0;
	m_costid = (int32_t)0;
	m_num = (int32_t)0;
	return 0;
}

int E_FindtreasureShop_s::ResumeInit() {
	return 0;
}

void E_FindtreasureShop_s::write_to_pbmsg(::proto_ff::E_FindtreasureShop & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_groupid((int32_t)m_groupid);
	msg.set_m_goodsid((int32_t)m_goodsid);
	msg.set_m_goodsnum((int32_t)m_goodsnum);
	msg.set_m_costid((int32_t)m_costid);
	msg.set_m_num((int32_t)m_num);
}

void E_FindtreasureShop_s::read_from_pbmsg(const ::proto_ff::E_FindtreasureShop & msg) {
	m_id = msg.m_id();
	m_groupid = msg.m_groupid();
	m_goodsid = msg.m_goodsid();
	m_goodsnum = msg.m_goodsnum();
	m_costid = msg.m_costid();
	m_num = msg.m_num();
}

Sheet_FindtreasureShop_s::Sheet_FindtreasureShop_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_FindtreasureShop_s::CreateInit() {
	return 0;
}

int Sheet_FindtreasureShop_s::ResumeInit() {
	return 0;
}

void Sheet_FindtreasureShop_s::write_to_pbmsg(::proto_ff::Sheet_FindtreasureShop & msg) const {
	for(int32_t i = 0; i < (int32_t)E_FindtreasureShop_List.size(); ++i) {
		::proto_ff::E_FindtreasureShop* temp_e_findtreasureshop_list = msg.add_e_findtreasureshop_list();
		E_FindtreasureShop_List[i].write_to_pbmsg(*temp_e_findtreasureshop_list);
	}
}

void Sheet_FindtreasureShop_s::read_from_pbmsg(const ::proto_ff::Sheet_FindtreasureShop & msg) {
	E_FindtreasureShop_List.resize((int)msg.e_findtreasureshop_list_size() > (int)E_FindtreasureShop_List.max_size() ? E_FindtreasureShop_List.max_size() : msg.e_findtreasureshop_list_size());
	for(int32_t i = 0; i < (int32_t)E_FindtreasureShop_List.size(); ++i) {
		const ::proto_ff::E_FindtreasureShop & temp_e_findtreasureshop_list = msg.e_findtreasureshop_list(i);
		E_FindtreasureShop_List[i].read_from_pbmsg(temp_e_findtreasureshop_list);
	}
}

}
