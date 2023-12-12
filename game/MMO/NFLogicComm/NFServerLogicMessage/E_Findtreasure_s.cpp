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
	m_functionUnlock = (int32_t)0;
	m_costID = (int64_t)0;
	m_ContItem = (int32_t)0;
	m_loop = (int32_t)0;
	m_poolTime = (int32_t)0;
	m_totalGroupID = (int32_t)0;
	m_activeGroupID = (int32_t)0;
	m_protectTime = (int32_t)0;
	m_addItem = (int32_t)0;
	m_addNum = (int32_t)0;
	m_shopID = (int32_t)0;
	m_storehouseType = (int32_t)0;
	return 0;
}

int E_FindtreasureFindtreasure_s::ResumeInit() {
	return 0;
}

void E_FindtreasureFindtreasure_s::write_to_pbmsg(::proto_ff::E_FindtreasureFindtreasure & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_type((int32_t)m_type);
	msg.set_m_functionunlock((int32_t)m_functionUnlock);
	msg.set_m_costid((int64_t)m_costID);
	msg.set_m_costnum(m_costNum.data());
	msg.set_m_contitem((int32_t)m_ContItem);
	msg.set_m_poolgroupid(m_poolGroupId.data());
	msg.set_m_loop((int32_t)m_loop);
	msg.set_m_pooltime((int32_t)m_poolTime);
	msg.set_m_totalgroupid((int32_t)m_totalGroupID);
	msg.set_m_activegroupid((int32_t)m_activeGroupID);
	msg.set_m_protecttime((int32_t)m_protectTime);
	msg.set_m_additem((int32_t)m_addItem);
	msg.set_m_addnum((int32_t)m_addNum);
	msg.set_m_shopid((int32_t)m_shopID);
	msg.set_m_storehousetype((int32_t)m_storehouseType);
}

void E_FindtreasureFindtreasure_s::read_from_pbmsg(const ::proto_ff::E_FindtreasureFindtreasure & msg) {
	m_id = msg.m_id();
	m_type = msg.m_type();
	m_functionUnlock = msg.m_functionunlock();
	m_costID = msg.m_costid();
	m_costNum = msg.m_costnum();
	m_ContItem = msg.m_contitem();
	m_poolGroupId = msg.m_poolgroupid();
	m_loop = msg.m_loop();
	m_poolTime = msg.m_pooltime();
	m_totalGroupID = msg.m_totalgroupid();
	m_activeGroupID = msg.m_activegroupid();
	m_protectTime = msg.m_protecttime();
	m_addItem = msg.m_additem();
	m_addNum = msg.m_addnum();
	m_shopID = msg.m_shopid();
	m_storehouseType = msg.m_storehousetype();
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
	m_groupID = (int32_t)0;
	m_showOrder = (int32_t)0;
	m_itemid = (int64_t)0;
	m_num = (int32_t)0;
	m_prof = (int32_t)0;
	m_weights = (int32_t)0;
	m_proWeights = (int32_t)0;
	m_poolLV = (int32_t)0;
	m_Record = (int32_t)0;
	return 0;
}

int E_FindtreasureFindpool_s::ResumeInit() {
	return 0;
}

void E_FindtreasureFindpool_s::write_to_pbmsg(::proto_ff::E_FindtreasureFindpool & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_groupid((int32_t)m_groupID);
	msg.set_m_showorder((int32_t)m_showOrder);
	msg.set_m_itemid((int64_t)m_itemid);
	msg.set_m_num((int32_t)m_num);
	msg.set_m_prof((int32_t)m_prof);
	msg.set_m_weights((int32_t)m_weights);
	msg.set_m_proweights((int32_t)m_proWeights);
	msg.set_m_poollv((int32_t)m_poolLV);
	msg.set_m_record((int32_t)m_Record);
}

void E_FindtreasureFindpool_s::read_from_pbmsg(const ::proto_ff::E_FindtreasureFindpool & msg) {
	m_id = msg.m_id();
	m_groupID = msg.m_groupid();
	m_showOrder = msg.m_showorder();
	m_itemid = msg.m_itemid();
	m_num = msg.m_num();
	m_prof = msg.m_prof();
	m_weights = msg.m_weights();
	m_proWeights = msg.m_proweights();
	m_poolLV = msg.m_poollv();
	m_Record = msg.m_record();
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
	m_dragonSeverTime = (int32_t)0;
	m_godSeverTime = (int32_t)0;
	return 0;
}

int E_FindtreasureConstant_s::ResumeInit() {
	return 0;
}

void E_FindtreasureConstant_s::write_to_pbmsg(::proto_ff::E_FindtreasureConstant & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_dragonsevertime((int32_t)m_dragonSeverTime);
	msg.set_m_godsevertime((int32_t)m_godSeverTime);
	msg.set_m_alchemysucces(m_alchemySucces.data());
}

void E_FindtreasureConstant_s::read_from_pbmsg(const ::proto_ff::E_FindtreasureConstant & msg) {
	m_id = msg.m_id();
	m_dragonSeverTime = msg.m_dragonsevertime();
	m_godSeverTime = msg.m_godsevertime();
	m_alchemySucces = msg.m_alchemysucces();
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
	m_itemID = (int32_t)0;
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
	msg.set_m_itemid((int32_t)m_itemID);
	msg.set_m_num((int32_t)m_num);
	for(int32_t i = 0; i < (int32_t)m_arg.size(); ++i) {
		msg.add_m_arg((int32_t)m_arg[i]);
	}
}

void E_FindtreasureTotal_s::read_from_pbmsg(const ::proto_ff::E_FindtreasureTotal & msg) {
	m_id = msg.m_id();
	m_groupid = msg.m_groupid();
	m_type = msg.m_type();
	m_itemID = msg.m_itemid();
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
	m_durTime = (int32_t)0;
	m_closeTime = (int32_t)0;
	m_type = (int32_t)0;
	m_typeGroupId = (int32_t)0;
	return 0;
}

int E_FindtreasureActive_s::ResumeInit() {
	return 0;
}

void E_FindtreasureActive_s::write_to_pbmsg(::proto_ff::E_FindtreasureActive & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_groupid((int32_t)m_groupid);
	msg.set_m_opentime((int32_t)m_opentime);
	msg.set_m_durtime((int32_t)m_durTime);
	msg.set_m_closetime((int32_t)m_closeTime);
	msg.set_m_type((int32_t)m_type);
	msg.set_m_typegroupid((int32_t)m_typeGroupId);
}

void E_FindtreasureActive_s::read_from_pbmsg(const ::proto_ff::E_FindtreasureActive & msg) {
	m_id = msg.m_id();
	m_groupid = msg.m_groupid();
	m_opentime = msg.m_opentime();
	m_durTime = msg.m_durtime();
	m_closeTime = msg.m_closetime();
	m_type = msg.m_type();
	m_typeGroupId = msg.m_typegroupid();
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
	m_groupID = (int32_t)0;
	m_type = (int32_t)0;
	m_itemid = (int32_t)0;
	m_proArg = (int32_t)0;
	return 0;
}

int E_FindtreasureActiveup_s::ResumeInit() {
	return 0;
}

void E_FindtreasureActiveup_s::write_to_pbmsg(::proto_ff::E_FindtreasureActiveup & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_groupid((int32_t)m_groupID);
	msg.set_m_type((int32_t)m_type);
	msg.set_m_itemid((int32_t)m_itemid);
	msg.set_m_proarg((int32_t)m_proArg);
}

void E_FindtreasureActiveup_s::read_from_pbmsg(const ::proto_ff::E_FindtreasureActiveup & msg) {
	m_id = msg.m_id();
	m_groupID = msg.m_groupid();
	m_type = msg.m_type();
	m_itemid = msg.m_itemid();
	m_proArg = msg.m_proarg();
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
	m_itemID = (int32_t)0;
	m_type = (int32_t)0;
	m_price = (int32_t)0;
	m_itemNum = (int32_t)0;
	return 0;
}

int E_FindtreasureActivegoods_s::ResumeInit() {
	return 0;
}

void E_FindtreasureActivegoods_s::write_to_pbmsg(::proto_ff::E_FindtreasureActivegoods & msg) const {
	msg.set_m_groupid((int32_t)m_groupid);
	msg.set_m_itemid((int32_t)m_itemID);
	msg.set_m_type((int32_t)m_type);
	msg.set_m_price((int32_t)m_price);
	msg.set_m_itemnum((int32_t)m_itemNum);
}

void E_FindtreasureActivegoods_s::read_from_pbmsg(const ::proto_ff::E_FindtreasureActivegoods & msg) {
	m_groupid = msg.m_groupid();
	m_itemID = msg.m_itemid();
	m_type = msg.m_type();
	m_price = msg.m_price();
	m_itemNum = msg.m_itemnum();
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
	m_goodsID = (int32_t)0;
	m_goodsNum = (int32_t)0;
	m_costID = (int32_t)0;
	m_num = (int32_t)0;
	return 0;
}

int E_FindtreasureShop_s::ResumeInit() {
	return 0;
}

void E_FindtreasureShop_s::write_to_pbmsg(::proto_ff::E_FindtreasureShop & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_groupid((int32_t)m_groupid);
	msg.set_m_goodsid((int32_t)m_goodsID);
	msg.set_m_goodsnum((int32_t)m_goodsNum);
	msg.set_m_costid((int32_t)m_costID);
	msg.set_m_num((int32_t)m_num);
}

void E_FindtreasureShop_s::read_from_pbmsg(const ::proto_ff::E_FindtreasureShop & msg) {
	m_id = msg.m_id();
	m_groupid = msg.m_groupid();
	m_goodsID = msg.m_goodsid();
	m_goodsNum = msg.m_goodsnum();
	m_costID = msg.m_costid();
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
