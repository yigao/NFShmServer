#include "E_Dup_s.h"

namespace proto_ff_s {

E_DupDup_s::E_DupDup_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_DupDup_s::CreateInit() {
	m_id = (int32_t)0;
	m_scripid = (int32_t)0;
	m_scriptype = (int32_t)0;
	m_duplevel = (int32_t)0;
	m_scripmontype = (int32_t)0;
	m_groupid = (int32_t)0;
	m_subtype = (int32_t)0;
	m_layer = (int32_t)0;
	m_recommendpower = (int32_t)0;
	m_duplicatetype = (int32_t)0;
	m_mapid = (int64_t)0;
	m_levellimit = (int32_t)0;
	m_functionid = (int32_t)0;
	m_pre = (int32_t)0;
	m_isautofight = (int32_t)0;
	m_revivemaxtimes = (int32_t)0;
	m_teamobjectid = (int32_t)0;
	m_sweeprewardboxid = (int64_t)0;
	m_sweeprewardexp = (int32_t)0;
	m_sweepexptype = (int32_t)0;
	m_ispatrol = (int32_t)0;
	m_failurebox = (int32_t)0;
	m_planes = (int32_t)0;
	return 0;
}

int E_DupDup_s::ResumeInit() {
	return 0;
}

void E_DupDup_s::write_to_pbmsg(::proto_ff::E_DupDup & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_scripid((int32_t)m_scripid);
	msg.set_m_scriptype((int32_t)m_scriptype);
	msg.set_m_duplevel((int32_t)m_duplevel);
	msg.set_m_scripmontype((int32_t)m_scripmontype);
	msg.set_m_scripmonid(m_scripmonid.data());
	msg.set_m_groupid((int32_t)m_groupid);
	msg.set_m_subtype((int32_t)m_subtype);
	msg.set_m_layer((int32_t)m_layer);
	msg.set_m_recommendpower((int32_t)m_recommendpower);
	msg.set_m_duplicatetype((int32_t)m_duplicatetype);
	msg.set_m_mapid((int64_t)m_mapid);
	msg.set_m_levellimit((int32_t)m_levellimit);
	msg.set_m_functionid((int32_t)m_functionid);
	msg.set_m_pre((int32_t)m_pre);
	msg.set_m_isautofight((int32_t)m_isautofight);
	msg.set_m_condition(m_condition.data());
	msg.set_m_revivemaxtimes((int32_t)m_revivemaxtimes);
	msg.set_m_teamobjectid((int32_t)m_teamobjectid);
	msg.set_m_gradecondition(m_gradecondition.data());
	msg.set_m_sweeprewardboxid((int64_t)m_sweeprewardboxid);
	msg.set_m_sweeprewardexp((int32_t)m_sweeprewardexp);
	msg.set_m_sweepexptype((int32_t)m_sweepexptype);
	msg.set_m_trackpoint(m_trackpoint.data());
	msg.set_m_pathofmonster(m_pathofmonster.data());
	msg.set_m_ispatrol((int32_t)m_ispatrol);
	msg.set_m_failurebox((int32_t)m_failurebox);
	msg.set_m_planes((int32_t)m_planes);
	for(int32_t i = 0; i < (int32_t)m_box.size(); ++i) {
		msg.add_m_box((int32_t)m_box[i]);
	}
}

void E_DupDup_s::read_from_pbmsg(const ::proto_ff::E_DupDup & msg) {
	m_id = msg.m_id();
	m_scripid = msg.m_scripid();
	m_scriptype = msg.m_scriptype();
	m_duplevel = msg.m_duplevel();
	m_scripmontype = msg.m_scripmontype();
	m_scripmonid = msg.m_scripmonid();
	m_groupid = msg.m_groupid();
	m_subtype = msg.m_subtype();
	m_layer = msg.m_layer();
	m_recommendpower = msg.m_recommendpower();
	m_duplicatetype = msg.m_duplicatetype();
	m_mapid = msg.m_mapid();
	m_levellimit = msg.m_levellimit();
	m_functionid = msg.m_functionid();
	m_pre = msg.m_pre();
	m_isautofight = msg.m_isautofight();
	m_condition = msg.m_condition();
	m_revivemaxtimes = msg.m_revivemaxtimes();
	m_teamobjectid = msg.m_teamobjectid();
	m_gradecondition = msg.m_gradecondition();
	m_sweeprewardboxid = msg.m_sweeprewardboxid();
	m_sweeprewardexp = msg.m_sweeprewardexp();
	m_sweepexptype = msg.m_sweepexptype();
	m_trackpoint = msg.m_trackpoint();
	m_pathofmonster = msg.m_pathofmonster();
	m_ispatrol = msg.m_ispatrol();
	m_failurebox = msg.m_failurebox();
	m_planes = msg.m_planes();
	m_box.resize((int)msg.m_box_size() > (int)m_box.max_size() ? m_box.max_size() : msg.m_box_size());
	for(int32_t i = 0; i < (int32_t)m_box.size(); ++i) {
		m_box[i] = msg.m_box(i);
	}
}

Sheet_DupDup_s::Sheet_DupDup_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_DupDup_s::CreateInit() {
	return 0;
}

int Sheet_DupDup_s::ResumeInit() {
	return 0;
}

void Sheet_DupDup_s::write_to_pbmsg(::proto_ff::Sheet_DupDup & msg) const {
	for(int32_t i = 0; i < (int32_t)E_DupDup_List.size(); ++i) {
		::proto_ff::E_DupDup* temp_e_dupdup_list = msg.add_e_dupdup_list();
		E_DupDup_List[i].write_to_pbmsg(*temp_e_dupdup_list);
	}
}

void Sheet_DupDup_s::read_from_pbmsg(const ::proto_ff::Sheet_DupDup & msg) {
	E_DupDup_List.resize((int)msg.e_dupdup_list_size() > (int)E_DupDup_List.max_size() ? E_DupDup_List.max_size() : msg.e_dupdup_list_size());
	for(int32_t i = 0; i < (int32_t)E_DupDup_List.size(); ++i) {
		const ::proto_ff::E_DupDup & temp_e_dupdup_list = msg.e_dupdup_list(i);
		E_DupDup_List[i].read_from_pbmsg(temp_e_dupdup_list);
	}
}

E_DupBplevel_s::E_DupBplevel_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_DupBplevel_s::CreateInit() {
	m_lv = (int32_t)0;
	return 0;
}

int E_DupBplevel_s::ResumeInit() {
	return 0;
}

void E_DupBplevel_s::write_to_pbmsg(::proto_ff::E_DupBplevel & msg) const {
	msg.set_m_lv((int32_t)m_lv);
	for(int32_t i = 0; i < (int32_t)m_bgdup.size(); ++i) {
		msg.add_m_bgdup((int64_t)m_bgdup[i]);
	}
	for(int32_t i = 0; i < (int32_t)m_bgdupsweep.size(); ++i) {
		msg.add_m_bgdupsweep((int64_t)m_bgdupsweep[i]);
	}
}

void E_DupBplevel_s::read_from_pbmsg(const ::proto_ff::E_DupBplevel & msg) {
	m_lv = msg.m_lv();
	m_bgdup.resize((int)msg.m_bgdup_size() > (int)m_bgdup.max_size() ? m_bgdup.max_size() : msg.m_bgdup_size());
	for(int32_t i = 0; i < (int32_t)m_bgdup.size(); ++i) {
		m_bgdup[i] = msg.m_bgdup(i);
	}
	m_bgdupsweep.resize((int)msg.m_bgdupsweep_size() > (int)m_bgdupsweep.max_size() ? m_bgdupsweep.max_size() : msg.m_bgdupsweep_size());
	for(int32_t i = 0; i < (int32_t)m_bgdupsweep.size(); ++i) {
		m_bgdupsweep[i] = msg.m_bgdupsweep(i);
	}
}

Sheet_DupBplevel_s::Sheet_DupBplevel_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_DupBplevel_s::CreateInit() {
	return 0;
}

int Sheet_DupBplevel_s::ResumeInit() {
	return 0;
}

void Sheet_DupBplevel_s::write_to_pbmsg(::proto_ff::Sheet_DupBplevel & msg) const {
	for(int32_t i = 0; i < (int32_t)E_DupBplevel_List.size(); ++i) {
		::proto_ff::E_DupBplevel* temp_e_dupbplevel_list = msg.add_e_dupbplevel_list();
		E_DupBplevel_List[i].write_to_pbmsg(*temp_e_dupbplevel_list);
	}
}

void Sheet_DupBplevel_s::read_from_pbmsg(const ::proto_ff::Sheet_DupBplevel & msg) {
	E_DupBplevel_List.resize((int)msg.e_dupbplevel_list_size() > (int)E_DupBplevel_List.max_size() ? E_DupBplevel_List.max_size() : msg.e_dupbplevel_list_size());
	for(int32_t i = 0; i < (int32_t)E_DupBplevel_List.size(); ++i) {
		const ::proto_ff::E_DupBplevel & temp_e_dupbplevel_list = msg.e_dupbplevel_list(i);
		E_DupBplevel_List[i].read_from_pbmsg(temp_e_dupbplevel_list);
	}
}

E_DupTtowerwaveClearDesc_s::E_DupTtowerwaveClearDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_DupTtowerwaveClearDesc_s::CreateInit() {
	m_add = (int32_t)0;
	m_time = (int32_t)0;
	return 0;
}

int E_DupTtowerwaveClearDesc_s::ResumeInit() {
	return 0;
}

void E_DupTtowerwaveClearDesc_s::write_to_pbmsg(::proto_ff::E_DupTtowerwaveClearDesc & msg) const {
	msg.set_m_add((int32_t)m_add);
	msg.set_m_time((int32_t)m_time);
}

void E_DupTtowerwaveClearDesc_s::read_from_pbmsg(const ::proto_ff::E_DupTtowerwaveClearDesc & msg) {
	m_add = msg.m_add();
	m_time = msg.m_time();
}

E_DupTtowerwave_s::E_DupTtowerwave_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_DupTtowerwave_s::CreateInit() {
	m_id = (int32_t)0;
	m_scripid = (int32_t)0;
	m_scriptype = (int32_t)0;
	m_duplevel = (int32_t)0;
	m_scripmontype = (int32_t)0;
	m_recommendpower = (int32_t)0;
	m_reward = (int32_t)0;
	m_firstpass = (int32_t)0;
	m_bp = (int32_t)0;
	return 0;
}

int E_DupTtowerwave_s::ResumeInit() {
	return 0;
}

void E_DupTtowerwave_s::write_to_pbmsg(::proto_ff::E_DupTtowerwave & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_scripid((int32_t)m_scripid);
	msg.set_m_scripgid(m_scripgid.data());
	msg.set_m_scriptype((int32_t)m_scriptype);
	msg.set_m_duplevel((int32_t)m_duplevel);
	msg.set_m_scripmontype((int32_t)m_scripmontype);
	msg.set_m_scripmonid(m_scripmonid.data());
	msg.set_m_recommendpower((int32_t)m_recommendpower);
	msg.set_m_reward((int32_t)m_reward);
	msg.set_m_firstpass((int32_t)m_firstpass);
	msg.set_m_bp((int32_t)m_bp);
	for(int32_t i = 0; i < (int32_t)m_clear.size(); ++i) {
		::proto_ff::E_DupTtowerwaveClearDesc* temp_m_clear = msg.add_m_clear();
		m_clear[i].write_to_pbmsg(*temp_m_clear);
	}
}

void E_DupTtowerwave_s::read_from_pbmsg(const ::proto_ff::E_DupTtowerwave & msg) {
	m_id = msg.m_id();
	m_scripid = msg.m_scripid();
	m_scripgid = msg.m_scripgid();
	m_scriptype = msg.m_scriptype();
	m_duplevel = msg.m_duplevel();
	m_scripmontype = msg.m_scripmontype();
	m_scripmonid = msg.m_scripmonid();
	m_recommendpower = msg.m_recommendpower();
	m_reward = msg.m_reward();
	m_firstpass = msg.m_firstpass();
	m_bp = msg.m_bp();
	m_clear.resize((int)msg.m_clear_size() > (int)m_clear.max_size() ? m_clear.max_size() : msg.m_clear_size());
	for(int32_t i = 0; i < (int32_t)m_clear.size(); ++i) {
		const ::proto_ff::E_DupTtowerwaveClearDesc & temp_m_clear = msg.m_clear(i);
		m_clear[i].read_from_pbmsg(temp_m_clear);
	}
}

Sheet_DupTtowerwave_s::Sheet_DupTtowerwave_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_DupTtowerwave_s::CreateInit() {
	return 0;
}

int Sheet_DupTtowerwave_s::ResumeInit() {
	return 0;
}

void Sheet_DupTtowerwave_s::write_to_pbmsg(::proto_ff::Sheet_DupTtowerwave & msg) const {
	for(int32_t i = 0; i < (int32_t)E_DupTtowerwave_List.size(); ++i) {
		::proto_ff::E_DupTtowerwave* temp_e_dupttowerwave_list = msg.add_e_dupttowerwave_list();
		E_DupTtowerwave_List[i].write_to_pbmsg(*temp_e_dupttowerwave_list);
	}
}

void Sheet_DupTtowerwave_s::read_from_pbmsg(const ::proto_ff::Sheet_DupTtowerwave & msg) {
	E_DupTtowerwave_List.resize((int)msg.e_dupttowerwave_list_size() > (int)E_DupTtowerwave_List.max_size() ? E_DupTtowerwave_List.max_size() : msg.e_dupttowerwave_list_size());
	for(int32_t i = 0; i < (int32_t)E_DupTtowerwave_List.size(); ++i) {
		const ::proto_ff::E_DupTtowerwave & temp_e_dupttowerwave_list = msg.e_dupttowerwave_list(i);
		E_DupTtowerwave_List[i].read_from_pbmsg(temp_e_dupttowerwave_list);
	}
}

E_DupTowerreward_s::E_DupTowerreward_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_DupTowerreward_s::CreateInit() {
	m_id = (int32_t)0;
	m_type = (int32_t)0;
	m_cond = (int32_t)0;
	m_boxid = (int32_t)0;
	return 0;
}

int E_DupTowerreward_s::ResumeInit() {
	return 0;
}

void E_DupTowerreward_s::write_to_pbmsg(::proto_ff::E_DupTowerreward & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_type((int32_t)m_type);
	msg.set_m_cond((int32_t)m_cond);
	msg.set_m_boxid((int32_t)m_boxid);
}

void E_DupTowerreward_s::read_from_pbmsg(const ::proto_ff::E_DupTowerreward & msg) {
	m_id = msg.m_id();
	m_type = msg.m_type();
	m_cond = msg.m_cond();
	m_boxid = msg.m_boxid();
}

Sheet_DupTowerreward_s::Sheet_DupTowerreward_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_DupTowerreward_s::CreateInit() {
	return 0;
}

int Sheet_DupTowerreward_s::ResumeInit() {
	return 0;
}

void Sheet_DupTowerreward_s::write_to_pbmsg(::proto_ff::Sheet_DupTowerreward & msg) const {
	for(int32_t i = 0; i < (int32_t)E_DupTowerreward_List.size(); ++i) {
		::proto_ff::E_DupTowerreward* temp_e_duptowerreward_list = msg.add_e_duptowerreward_list();
		E_DupTowerreward_List[i].write_to_pbmsg(*temp_e_duptowerreward_list);
	}
}

void Sheet_DupTowerreward_s::read_from_pbmsg(const ::proto_ff::Sheet_DupTowerreward & msg) {
	E_DupTowerreward_List.resize((int)msg.e_duptowerreward_list_size() > (int)E_DupTowerreward_List.max_size() ? E_DupTowerreward_List.max_size() : msg.e_duptowerreward_list_size());
	for(int32_t i = 0; i < (int32_t)E_DupTowerreward_List.size(); ++i) {
		const ::proto_ff::E_DupTowerreward & temp_e_duptowerreward_list = msg.e_duptowerreward_list(i);
		E_DupTowerreward_List[i].read_from_pbmsg(temp_e_duptowerreward_list);
	}
}

E_DupGroup_s::E_DupGroup_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_DupGroup_s::CreateInit() {
	m_id = (int32_t)0;
	m_privilegetype = (int32_t)0;
	m_dynamiclevel = (int32_t)0;
	m_grouptimestype = (int32_t)0;
	m_resetcycle = (int32_t)0;
	m_grouptimes = (int32_t)0;
	m_enteritemid = (int32_t)0;
	m_sweeptype = (int32_t)0;
	m_sweepcondition = (int32_t)0;
	m_mergecondition = (int32_t)0;
	m_additemid = (int32_t)0;
	m_buytype = (int32_t)0;
	m_buyitemid = (int32_t)0;
	m_countdown = (int32_t)0;
	m_enddown = (int32_t)0;
	m_accountdown = (int32_t)0;
	m_funcionid = (int32_t)0;
	m_closefuncionid = (int32_t)0;
	m_link = (int64_t)0;
	m_festvialtype = (int32_t)0;
	return 0;
}

int E_DupGroup_s::ResumeInit() {
	return 0;
}

void E_DupGroup_s::write_to_pbmsg(::proto_ff::E_DupGroup & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_name(m_name.data());
	msg.set_m_privilegetype((int32_t)m_privilegetype);
	msg.set_m_dynamiclevel((int32_t)m_dynamiclevel);
	msg.set_m_grouptimestype((int32_t)m_grouptimestype);
	msg.set_m_resetcycle((int32_t)m_resetcycle);
	msg.set_m_grouptimes((int32_t)m_grouptimes);
	msg.set_m_enteritemid((int32_t)m_enteritemid);
	msg.set_m_sweeptype((int32_t)m_sweeptype);
	msg.set_m_sweepcondition((int32_t)m_sweepcondition);
	msg.set_m_mergecondition((int32_t)m_mergecondition);
	msg.set_m_additemid((int32_t)m_additemid);
	msg.set_m_buytype((int32_t)m_buytype);
	msg.set_m_buyitemid((int32_t)m_buyitemid);
	msg.set_m_buycost(m_buycost.data());
	msg.set_m_countdown((int32_t)m_countdown);
	msg.set_m_enddown((int32_t)m_enddown);
	msg.set_m_accountdown((int32_t)m_accountdown);
	msg.set_m_funcionid((int32_t)m_funcionid);
	msg.set_m_closefuncionid((int32_t)m_closefuncionid);
	msg.set_m_link((int64_t)m_link);
	msg.set_m_festvialtype((int32_t)m_festvialtype);
}

void E_DupGroup_s::read_from_pbmsg(const ::proto_ff::E_DupGroup & msg) {
	m_id = msg.m_id();
	m_name = msg.m_name();
	m_privilegetype = msg.m_privilegetype();
	m_dynamiclevel = msg.m_dynamiclevel();
	m_grouptimestype = msg.m_grouptimestype();
	m_resetcycle = msg.m_resetcycle();
	m_grouptimes = msg.m_grouptimes();
	m_enteritemid = msg.m_enteritemid();
	m_sweeptype = msg.m_sweeptype();
	m_sweepcondition = msg.m_sweepcondition();
	m_mergecondition = msg.m_mergecondition();
	m_additemid = msg.m_additemid();
	m_buytype = msg.m_buytype();
	m_buyitemid = msg.m_buyitemid();
	m_buycost = msg.m_buycost();
	m_countdown = msg.m_countdown();
	m_enddown = msg.m_enddown();
	m_accountdown = msg.m_accountdown();
	m_funcionid = msg.m_funcionid();
	m_closefuncionid = msg.m_closefuncionid();
	m_link = msg.m_link();
	m_festvialtype = msg.m_festvialtype();
}

Sheet_DupGroup_s::Sheet_DupGroup_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_DupGroup_s::CreateInit() {
	return 0;
}

int Sheet_DupGroup_s::ResumeInit() {
	return 0;
}

void Sheet_DupGroup_s::write_to_pbmsg(::proto_ff::Sheet_DupGroup & msg) const {
	for(int32_t i = 0; i < (int32_t)E_DupGroup_List.size(); ++i) {
		::proto_ff::E_DupGroup* temp_e_dupgroup_list = msg.add_e_dupgroup_list();
		E_DupGroup_List[i].write_to_pbmsg(*temp_e_dupgroup_list);
	}
}

void Sheet_DupGroup_s::read_from_pbmsg(const ::proto_ff::Sheet_DupGroup & msg) {
	E_DupGroup_List.resize((int)msg.e_dupgroup_list_size() > (int)E_DupGroup_List.max_size() ? E_DupGroup_List.max_size() : msg.e_dupgroup_list_size());
	for(int32_t i = 0; i < (int32_t)E_DupGroup_List.size(); ++i) {
		const ::proto_ff::E_DupGroup & temp_e_dupgroup_list = msg.e_dupgroup_list(i);
		E_DupGroup_List[i].read_from_pbmsg(temp_e_dupgroup_list);
	}
}

E_DupSweepmonsternum_s::E_DupSweepmonsternum_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_DupSweepmonsternum_s::CreateInit() {
	m_id = (int32_t)0;
	m_sweepexptype = (int32_t)0;
	m_minlevel = (int32_t)0;
	m_maxlevel = (int32_t)0;
	m_killnumber = (int32_t)0;
	m_monstervaluetype = (int32_t)0;
	return 0;
}

int E_DupSweepmonsternum_s::ResumeInit() {
	return 0;
}

void E_DupSweepmonsternum_s::write_to_pbmsg(::proto_ff::E_DupSweepmonsternum & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_sweepexptype((int32_t)m_sweepexptype);
	msg.set_m_minlevel((int32_t)m_minlevel);
	msg.set_m_maxlevel((int32_t)m_maxlevel);
	msg.set_m_killnumber((int32_t)m_killnumber);
	msg.set_m_monstervaluetype((int32_t)m_monstervaluetype);
}

void E_DupSweepmonsternum_s::read_from_pbmsg(const ::proto_ff::E_DupSweepmonsternum & msg) {
	m_id = msg.m_id();
	m_sweepexptype = msg.m_sweepexptype();
	m_minlevel = msg.m_minlevel();
	m_maxlevel = msg.m_maxlevel();
	m_killnumber = msg.m_killnumber();
	m_monstervaluetype = msg.m_monstervaluetype();
}

Sheet_DupSweepmonsternum_s::Sheet_DupSweepmonsternum_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_DupSweepmonsternum_s::CreateInit() {
	return 0;
}

int Sheet_DupSweepmonsternum_s::ResumeInit() {
	return 0;
}

void Sheet_DupSweepmonsternum_s::write_to_pbmsg(::proto_ff::Sheet_DupSweepmonsternum & msg) const {
	for(int32_t i = 0; i < (int32_t)E_DupSweepmonsternum_List.size(); ++i) {
		::proto_ff::E_DupSweepmonsternum* temp_e_dupsweepmonsternum_list = msg.add_e_dupsweepmonsternum_list();
		E_DupSweepmonsternum_List[i].write_to_pbmsg(*temp_e_dupsweepmonsternum_list);
	}
}

void Sheet_DupSweepmonsternum_s::read_from_pbmsg(const ::proto_ff::Sheet_DupSweepmonsternum & msg) {
	E_DupSweepmonsternum_List.resize((int)msg.e_dupsweepmonsternum_list_size() > (int)E_DupSweepmonsternum_List.max_size() ? E_DupSweepmonsternum_List.max_size() : msg.e_dupsweepmonsternum_list_size());
	for(int32_t i = 0; i < (int32_t)E_DupSweepmonsternum_List.size(); ++i) {
		const ::proto_ff::E_DupSweepmonsternum & temp_e_dupsweepmonsternum_list = msg.e_dupsweepmonsternum_list(i);
		E_DupSweepmonsternum_List[i].read_from_pbmsg(temp_e_dupsweepmonsternum_list);
	}
}

E_DupWorldlvreward_s::E_DupWorldlvreward_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_DupWorldlvreward_s::CreateInit() {
	m_id = (int32_t)0;
	m_groupid = (int32_t)0;
	m_lvtype = (int32_t)0;
	m_lvmin = (int32_t)0;
	m_failurebox = (int32_t)0;
	return 0;
}

int E_DupWorldlvreward_s::ResumeInit() {
	return 0;
}

void E_DupWorldlvreward_s::write_to_pbmsg(::proto_ff::E_DupWorldlvreward & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_groupid((int32_t)m_groupid);
	msg.set_m_lvtype((int32_t)m_lvtype);
	msg.set_m_lvmin((int32_t)m_lvmin);
	msg.set_m_failurebox((int32_t)m_failurebox);
	for(int32_t i = 0; i < (int32_t)m_box.size(); ++i) {
		msg.add_m_box((int32_t)m_box[i]);
	}
}

void E_DupWorldlvreward_s::read_from_pbmsg(const ::proto_ff::E_DupWorldlvreward & msg) {
	m_id = msg.m_id();
	m_groupid = msg.m_groupid();
	m_lvtype = msg.m_lvtype();
	m_lvmin = msg.m_lvmin();
	m_failurebox = msg.m_failurebox();
	m_box.resize((int)msg.m_box_size() > (int)m_box.max_size() ? m_box.max_size() : msg.m_box_size());
	for(int32_t i = 0; i < (int32_t)m_box.size(); ++i) {
		m_box[i] = msg.m_box(i);
	}
}

Sheet_DupWorldlvreward_s::Sheet_DupWorldlvreward_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_DupWorldlvreward_s::CreateInit() {
	return 0;
}

int Sheet_DupWorldlvreward_s::ResumeInit() {
	return 0;
}

void Sheet_DupWorldlvreward_s::write_to_pbmsg(::proto_ff::Sheet_DupWorldlvreward & msg) const {
	for(int32_t i = 0; i < (int32_t)E_DupWorldlvreward_List.size(); ++i) {
		::proto_ff::E_DupWorldlvreward* temp_e_dupworldlvreward_list = msg.add_e_dupworldlvreward_list();
		E_DupWorldlvreward_List[i].write_to_pbmsg(*temp_e_dupworldlvreward_list);
	}
}

void Sheet_DupWorldlvreward_s::read_from_pbmsg(const ::proto_ff::Sheet_DupWorldlvreward & msg) {
	E_DupWorldlvreward_List.resize((int)msg.e_dupworldlvreward_list_size() > (int)E_DupWorldlvreward_List.max_size() ? E_DupWorldlvreward_List.max_size() : msg.e_dupworldlvreward_list_size());
	for(int32_t i = 0; i < (int32_t)E_DupWorldlvreward_List.size(); ++i) {
		const ::proto_ff::E_DupWorldlvreward & temp_e_dupworldlvreward_list = msg.e_dupworldlvreward_list(i);
		E_DupWorldlvreward_List[i].read_from_pbmsg(temp_e_dupworldlvreward_list);
	}
}

E_DupPlanes_s::E_DupPlanes_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_DupPlanes_s::CreateInit() {
	m_id = (int64_t)0;
	m_planestype = (int32_t)0;
	m_areaid = (int32_t)0;
	return 0;
}

int E_DupPlanes_s::ResumeInit() {
	return 0;
}

void E_DupPlanes_s::write_to_pbmsg(::proto_ff::E_DupPlanes & msg) const {
	msg.set_m_id((int64_t)m_id);
	msg.set_m_planestype((int32_t)m_planestype);
	msg.set_m_typeargs(m_typeargs.data());
	msg.set_m_areaid((int32_t)m_areaid);
}

void E_DupPlanes_s::read_from_pbmsg(const ::proto_ff::E_DupPlanes & msg) {
	m_id = msg.m_id();
	m_planestype = msg.m_planestype();
	m_typeargs = msg.m_typeargs();
	m_areaid = msg.m_areaid();
}

Sheet_DupPlanes_s::Sheet_DupPlanes_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_DupPlanes_s::CreateInit() {
	return 0;
}

int Sheet_DupPlanes_s::ResumeInit() {
	return 0;
}

void Sheet_DupPlanes_s::write_to_pbmsg(::proto_ff::Sheet_DupPlanes & msg) const {
	for(int32_t i = 0; i < (int32_t)E_DupPlanes_List.size(); ++i) {
		::proto_ff::E_DupPlanes* temp_e_dupplanes_list = msg.add_e_dupplanes_list();
		E_DupPlanes_List[i].write_to_pbmsg(*temp_e_dupplanes_list);
	}
}

void Sheet_DupPlanes_s::read_from_pbmsg(const ::proto_ff::Sheet_DupPlanes & msg) {
	E_DupPlanes_List.resize((int)msg.e_dupplanes_list_size() > (int)E_DupPlanes_List.max_size() ? E_DupPlanes_List.max_size() : msg.e_dupplanes_list_size());
	for(int32_t i = 0; i < (int32_t)E_DupPlanes_List.size(); ++i) {
		const ::proto_ff::E_DupPlanes & temp_e_dupplanes_list = msg.e_dupplanes_list(i);
		E_DupPlanes_List[i].read_from_pbmsg(temp_e_dupplanes_list);
	}
}

E_DupYt_dupClearDesc_s::E_DupYt_dupClearDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_DupYt_dupClearDesc_s::CreateInit() {
	m_add = (int32_t)0;
	m_time = (int32_t)0;
	return 0;
}

int E_DupYt_dupClearDesc_s::ResumeInit() {
	return 0;
}

void E_DupYt_dupClearDesc_s::write_to_pbmsg(::proto_ff::E_DupYt_dupClearDesc & msg) const {
	msg.set_m_add((int32_t)m_add);
	msg.set_m_time((int32_t)m_time);
}

void E_DupYt_dupClearDesc_s::read_from_pbmsg(const ::proto_ff::E_DupYt_dupClearDesc & msg) {
	m_add = msg.m_add();
	m_time = msg.m_time();
}

E_DupYt_dup_s::E_DupYt_dup_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_DupYt_dup_s::CreateInit() {
	m_id = (int32_t)0;
	m_layer = (int32_t)0;
	m_stage = (int32_t)0;
	m_recommendlv = (int32_t)0;
	m_recommendyk = (int32_t)0;
	m_reward = (int32_t)0;
	m_firstpass = (int32_t)0;
	m_overlordbox = (int32_t)0;
	m_overlordtime = (int32_t)0;
	return 0;
}

int E_DupYt_dup_s::ResumeInit() {
	return 0;
}

void E_DupYt_dup_s::write_to_pbmsg(::proto_ff::E_DupYt_dup & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_layer((int32_t)m_layer);
	msg.set_m_stage((int32_t)m_stage);
	msg.set_m_recommendlv((int32_t)m_recommendlv);
	msg.set_m_recommendyk((int32_t)m_recommendyk);
	msg.set_m_reward((int32_t)m_reward);
	msg.set_m_firstpass((int32_t)m_firstpass);
	msg.set_m_overlordbox((int32_t)m_overlordbox);
	msg.set_m_overlordtime((int32_t)m_overlordtime);
	for(int32_t i = 0; i < (int32_t)m_clear.size(); ++i) {
		::proto_ff::E_DupYt_dupClearDesc* temp_m_clear = msg.add_m_clear();
		m_clear[i].write_to_pbmsg(*temp_m_clear);
	}
}

void E_DupYt_dup_s::read_from_pbmsg(const ::proto_ff::E_DupYt_dup & msg) {
	m_id = msg.m_id();
	m_layer = msg.m_layer();
	m_stage = msg.m_stage();
	m_recommendlv = msg.m_recommendlv();
	m_recommendyk = msg.m_recommendyk();
	m_reward = msg.m_reward();
	m_firstpass = msg.m_firstpass();
	m_overlordbox = msg.m_overlordbox();
	m_overlordtime = msg.m_overlordtime();
	m_clear.resize((int)msg.m_clear_size() > (int)m_clear.max_size() ? m_clear.max_size() : msg.m_clear_size());
	for(int32_t i = 0; i < (int32_t)m_clear.size(); ++i) {
		const ::proto_ff::E_DupYt_dupClearDesc & temp_m_clear = msg.m_clear(i);
		m_clear[i].read_from_pbmsg(temp_m_clear);
	}
}

Sheet_DupYt_dup_s::Sheet_DupYt_dup_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_DupYt_dup_s::CreateInit() {
	return 0;
}

int Sheet_DupYt_dup_s::ResumeInit() {
	return 0;
}

void Sheet_DupYt_dup_s::write_to_pbmsg(::proto_ff::Sheet_DupYt_dup & msg) const {
	for(int32_t i = 0; i < (int32_t)E_DupYt_dup_List.size(); ++i) {
		::proto_ff::E_DupYt_dup* temp_e_dupyt_dup_list = msg.add_e_dupyt_dup_list();
		E_DupYt_dup_List[i].write_to_pbmsg(*temp_e_dupyt_dup_list);
	}
}

void Sheet_DupYt_dup_s::read_from_pbmsg(const ::proto_ff::Sheet_DupYt_dup & msg) {
	E_DupYt_dup_List.resize((int)msg.e_dupyt_dup_list_size() > (int)E_DupYt_dup_List.max_size() ? E_DupYt_dup_List.max_size() : msg.e_dupyt_dup_list_size());
	for(int32_t i = 0; i < (int32_t)E_DupYt_dup_List.size(); ++i) {
		const ::proto_ff::E_DupYt_dup & temp_e_dupyt_dup_list = msg.e_dupyt_dup_list(i);
		E_DupYt_dup_List[i].read_from_pbmsg(temp_e_dupyt_dup_list);
	}
}

}
