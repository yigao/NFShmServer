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
	m_ID = (int32_t)0;
	m_scripID = (int32_t)0;
	m_scripType = (int32_t)0;
	m_dupLevel = (int32_t)0;
	m_scripMonType = (int32_t)0;
	m_groupID = (int32_t)0;
	m_subType = (int32_t)0;
	m_layer = (int32_t)0;
	m_recommendPower = (int32_t)0;
	m_duplicateType = (int32_t)0;
	m_mapID = (int64_t)0;
	m_levelLimit = (int32_t)0;
	m_functionID = (int32_t)0;
	m_pre = (int32_t)0;
	m_isAutoFight = (int32_t)0;
	m_reviveMaxTimes = (int32_t)0;
	m_TeamObjectID = (int32_t)0;
	m_sweepRewardBoxID = (int64_t)0;
	m_sweepRewardExp = (int32_t)0;
	m_sweepExpType = (int32_t)0;
	m_isPatrol = (int32_t)0;
	m_failureBox = (int32_t)0;
	m_planes = (int32_t)0;
	return 0;
}

int E_DupDup_s::ResumeInit() {
	return 0;
}

void E_DupDup_s::write_to_pbmsg(::proto_ff::E_DupDup & msg) const {
	msg.set_m_id((int32_t)m_ID);
	msg.set_m_scripid((int32_t)m_scripID);
	msg.set_m_scriptype((int32_t)m_scripType);
	msg.set_m_duplevel((int32_t)m_dupLevel);
	msg.set_m_scripmontype((int32_t)m_scripMonType);
	msg.set_m_scripmonid(m_scripMonID.data());
	msg.set_m_groupid((int32_t)m_groupID);
	msg.set_m_subtype((int32_t)m_subType);
	msg.set_m_layer((int32_t)m_layer);
	msg.set_m_recommendpower((int32_t)m_recommendPower);
	msg.set_m_duplicatetype((int32_t)m_duplicateType);
	msg.set_m_mapid((int64_t)m_mapID);
	msg.set_m_levellimit((int32_t)m_levelLimit);
	msg.set_m_functionid((int32_t)m_functionID);
	msg.set_m_pre((int32_t)m_pre);
	msg.set_m_isautofight((int32_t)m_isAutoFight);
	msg.set_m_condition(m_condition.data());
	msg.set_m_revivemaxtimes((int32_t)m_reviveMaxTimes);
	msg.set_m_teamobjectid((int32_t)m_TeamObjectID);
	msg.set_m_gradecondition(m_gradeCondition.data());
	msg.set_m_sweeprewardboxid((int64_t)m_sweepRewardBoxID);
	msg.set_m_sweeprewardexp((int32_t)m_sweepRewardExp);
	msg.set_m_sweepexptype((int32_t)m_sweepExpType);
	msg.set_m_trackpoint(m_trackpoint.data());
	msg.set_m_pathofmonster(m_pathOfmonster.data());
	msg.set_m_ispatrol((int32_t)m_isPatrol);
	msg.set_m_failurebox((int32_t)m_failureBox);
	msg.set_m_planes((int32_t)m_planes);
	for(int32_t i = 0; i < (int32_t)m_box.size(); ++i) {
		msg.add_m_box((int32_t)m_box[i]);
	}
}

void E_DupDup_s::read_from_pbmsg(const ::proto_ff::E_DupDup & msg) {
	m_ID = msg.m_id();
	m_scripID = msg.m_scripid();
	m_scripType = msg.m_scriptype();
	m_dupLevel = msg.m_duplevel();
	m_scripMonType = msg.m_scripmontype();
	m_scripMonID = msg.m_scripmonid();
	m_groupID = msg.m_groupid();
	m_subType = msg.m_subtype();
	m_layer = msg.m_layer();
	m_recommendPower = msg.m_recommendpower();
	m_duplicateType = msg.m_duplicatetype();
	m_mapID = msg.m_mapid();
	m_levelLimit = msg.m_levellimit();
	m_functionID = msg.m_functionid();
	m_pre = msg.m_pre();
	m_isAutoFight = msg.m_isautofight();
	m_condition = msg.m_condition();
	m_reviveMaxTimes = msg.m_revivemaxtimes();
	m_TeamObjectID = msg.m_teamobjectid();
	m_gradeCondition = msg.m_gradecondition();
	m_sweepRewardBoxID = msg.m_sweeprewardboxid();
	m_sweepRewardExp = msg.m_sweeprewardexp();
	m_sweepExpType = msg.m_sweepexptype();
	m_trackpoint = msg.m_trackpoint();
	m_pathOfmonster = msg.m_pathofmonster();
	m_isPatrol = msg.m_ispatrol();
	m_failureBox = msg.m_failurebox();
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
	for(int32_t i = 0; i < (int32_t)m_Bgdup.size(); ++i) {
		msg.add_m_bgdup((int64_t)m_Bgdup[i]);
	}
	for(int32_t i = 0; i < (int32_t)m_BgdupSweep.size(); ++i) {
		msg.add_m_bgdupsweep((int64_t)m_BgdupSweep[i]);
	}
}

void E_DupBplevel_s::read_from_pbmsg(const ::proto_ff::E_DupBplevel & msg) {
	m_lv = msg.m_lv();
	m_Bgdup.resize((int)msg.m_bgdup_size() > (int)m_Bgdup.max_size() ? m_Bgdup.max_size() : msg.m_bgdup_size());
	for(int32_t i = 0; i < (int32_t)m_Bgdup.size(); ++i) {
		m_Bgdup[i] = msg.m_bgdup(i);
	}
	m_BgdupSweep.resize((int)msg.m_bgdupsweep_size() > (int)m_BgdupSweep.max_size() ? m_BgdupSweep.max_size() : msg.m_bgdupsweep_size());
	for(int32_t i = 0; i < (int32_t)m_BgdupSweep.size(); ++i) {
		m_BgdupSweep[i] = msg.m_bgdupsweep(i);
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
	m_scripID = (int32_t)0;
	m_scripType = (int32_t)0;
	m_dupLevel = (int32_t)0;
	m_scripMonType = (int32_t)0;
	m_recommendPower = (int32_t)0;
	m_reward = (int32_t)0;
	m_firstPass = (int32_t)0;
	m_BP = (int32_t)0;
	return 0;
}

int E_DupTtowerwave_s::ResumeInit() {
	return 0;
}

void E_DupTtowerwave_s::write_to_pbmsg(::proto_ff::E_DupTtowerwave & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_scripid((int32_t)m_scripID);
	msg.set_m_scripgid(m_scripGid.data());
	msg.set_m_scriptype((int32_t)m_scripType);
	msg.set_m_duplevel((int32_t)m_dupLevel);
	msg.set_m_scripmontype((int32_t)m_scripMonType);
	msg.set_m_scripmonid(m_scripMonID.data());
	msg.set_m_recommendpower((int32_t)m_recommendPower);
	msg.set_m_reward((int32_t)m_reward);
	msg.set_m_firstpass((int32_t)m_firstPass);
	msg.set_m_bp((int32_t)m_BP);
	for(int32_t i = 0; i < (int32_t)m_clear.size(); ++i) {
		::proto_ff::E_DupTtowerwaveClearDesc* temp_m_clear = msg.add_m_clear();
		m_clear[i].write_to_pbmsg(*temp_m_clear);
	}
}

void E_DupTtowerwave_s::read_from_pbmsg(const ::proto_ff::E_DupTtowerwave & msg) {
	m_id = msg.m_id();
	m_scripID = msg.m_scripid();
	m_scripGid = msg.m_scripgid();
	m_scripType = msg.m_scriptype();
	m_dupLevel = msg.m_duplevel();
	m_scripMonType = msg.m_scripmontype();
	m_scripMonID = msg.m_scripmonid();
	m_recommendPower = msg.m_recommendpower();
	m_reward = msg.m_reward();
	m_firstPass = msg.m_firstpass();
	m_BP = msg.m_bp();
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
	m_boxID = (int32_t)0;
	return 0;
}

int E_DupTowerreward_s::ResumeInit() {
	return 0;
}

void E_DupTowerreward_s::write_to_pbmsg(::proto_ff::E_DupTowerreward & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_type((int32_t)m_type);
	msg.set_m_cond((int32_t)m_cond);
	msg.set_m_boxid((int32_t)m_boxID);
}

void E_DupTowerreward_s::read_from_pbmsg(const ::proto_ff::E_DupTowerreward & msg) {
	m_id = msg.m_id();
	m_type = msg.m_type();
	m_cond = msg.m_cond();
	m_boxID = msg.m_boxid();
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
	m_privilegeType = (int32_t)0;
	m_dynamiclevel = (int32_t)0;
	m_groupTimesType = (int32_t)0;
	m_resetCycle = (int32_t)0;
	m_groupTimes = (int32_t)0;
	m_enterItemID = (int32_t)0;
	m_sweepType = (int32_t)0;
	m_sweepCondition = (int32_t)0;
	m_mergeCondition = (int32_t)0;
	m_addItemID = (int32_t)0;
	m_buyType = (int32_t)0;
	m_buyItemId = (int32_t)0;
	m_countDown = (int32_t)0;
	m_endDown = (int32_t)0;
	m_accountDown = (int32_t)0;
	m_funcionID = (int32_t)0;
	m_closeFuncionID = (int32_t)0;
	m_link = (int64_t)0;
	m_festvialType = (int32_t)0;
	return 0;
}

int E_DupGroup_s::ResumeInit() {
	return 0;
}

void E_DupGroup_s::write_to_pbmsg(::proto_ff::E_DupGroup & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_name(m_name.data());
	msg.set_m_privilegetype((int32_t)m_privilegeType);
	msg.set_m_dynamiclevel((int32_t)m_dynamiclevel);
	msg.set_m_grouptimestype((int32_t)m_groupTimesType);
	msg.set_m_resetcycle((int32_t)m_resetCycle);
	msg.set_m_grouptimes((int32_t)m_groupTimes);
	msg.set_m_enteritemid((int32_t)m_enterItemID);
	msg.set_m_sweeptype((int32_t)m_sweepType);
	msg.set_m_sweepcondition((int32_t)m_sweepCondition);
	msg.set_m_mergecondition((int32_t)m_mergeCondition);
	msg.set_m_additemid((int32_t)m_addItemID);
	msg.set_m_buytype((int32_t)m_buyType);
	msg.set_m_buyitemid((int32_t)m_buyItemId);
	msg.set_m_buycost(m_buyCost.data());
	msg.set_m_countdown((int32_t)m_countDown);
	msg.set_m_enddown((int32_t)m_endDown);
	msg.set_m_accountdown((int32_t)m_accountDown);
	msg.set_m_funcionid((int32_t)m_funcionID);
	msg.set_m_closefuncionid((int32_t)m_closeFuncionID);
	msg.set_m_link((int64_t)m_link);
	msg.set_m_festvialtype((int32_t)m_festvialType);
}

void E_DupGroup_s::read_from_pbmsg(const ::proto_ff::E_DupGroup & msg) {
	m_id = msg.m_id();
	m_name = msg.m_name();
	m_privilegeType = msg.m_privilegetype();
	m_dynamiclevel = msg.m_dynamiclevel();
	m_groupTimesType = msg.m_grouptimestype();
	m_resetCycle = msg.m_resetcycle();
	m_groupTimes = msg.m_grouptimes();
	m_enterItemID = msg.m_enteritemid();
	m_sweepType = msg.m_sweeptype();
	m_sweepCondition = msg.m_sweepcondition();
	m_mergeCondition = msg.m_mergecondition();
	m_addItemID = msg.m_additemid();
	m_buyType = msg.m_buytype();
	m_buyItemId = msg.m_buyitemid();
	m_buyCost = msg.m_buycost();
	m_countDown = msg.m_countdown();
	m_endDown = msg.m_enddown();
	m_accountDown = msg.m_accountdown();
	m_funcionID = msg.m_funcionid();
	m_closeFuncionID = msg.m_closefuncionid();
	m_link = msg.m_link();
	m_festvialType = msg.m_festvialtype();
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
	m_ID = (int32_t)0;
	m_sweepExpType = (int32_t)0;
	m_minLevel = (int32_t)0;
	m_maxLevel = (int32_t)0;
	m_killNumber = (int32_t)0;
	m_monstervaluetype = (int32_t)0;
	return 0;
}

int E_DupSweepmonsternum_s::ResumeInit() {
	return 0;
}

void E_DupSweepmonsternum_s::write_to_pbmsg(::proto_ff::E_DupSweepmonsternum & msg) const {
	msg.set_m_id((int32_t)m_ID);
	msg.set_m_sweepexptype((int32_t)m_sweepExpType);
	msg.set_m_minlevel((int32_t)m_minLevel);
	msg.set_m_maxlevel((int32_t)m_maxLevel);
	msg.set_m_killnumber((int32_t)m_killNumber);
	msg.set_m_monstervaluetype((int32_t)m_monstervaluetype);
}

void E_DupSweepmonsternum_s::read_from_pbmsg(const ::proto_ff::E_DupSweepmonsternum & msg) {
	m_ID = msg.m_id();
	m_sweepExpType = msg.m_sweepexptype();
	m_minLevel = msg.m_minlevel();
	m_maxLevel = msg.m_maxlevel();
	m_killNumber = msg.m_killnumber();
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
	m_groupID = (int32_t)0;
	m_lvtype = (int32_t)0;
	m_lvMin = (int32_t)0;
	m_failureBox = (int32_t)0;
	return 0;
}

int E_DupWorldlvreward_s::ResumeInit() {
	return 0;
}

void E_DupWorldlvreward_s::write_to_pbmsg(::proto_ff::E_DupWorldlvreward & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_groupid((int32_t)m_groupID);
	msg.set_m_lvtype((int32_t)m_lvtype);
	msg.set_m_lvmin((int32_t)m_lvMin);
	msg.set_m_failurebox((int32_t)m_failureBox);
	for(int32_t i = 0; i < (int32_t)m_box.size(); ++i) {
		msg.add_m_box((int32_t)m_box[i]);
	}
}

void E_DupWorldlvreward_s::read_from_pbmsg(const ::proto_ff::E_DupWorldlvreward & msg) {
	m_id = msg.m_id();
	m_groupID = msg.m_groupid();
	m_lvtype = msg.m_lvtype();
	m_lvMin = msg.m_lvmin();
	m_failureBox = msg.m_failurebox();
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
	m_planesType = (int32_t)0;
	m_areaId = (int32_t)0;
	return 0;
}

int E_DupPlanes_s::ResumeInit() {
	return 0;
}

void E_DupPlanes_s::write_to_pbmsg(::proto_ff::E_DupPlanes & msg) const {
	msg.set_m_id((int64_t)m_id);
	msg.set_m_planestype((int32_t)m_planesType);
	msg.set_m_typeargs(m_typeArgs.data());
	msg.set_m_areaid((int32_t)m_areaId);
}

void E_DupPlanes_s::read_from_pbmsg(const ::proto_ff::E_DupPlanes & msg) {
	m_id = msg.m_id();
	m_planesType = msg.m_planestype();
	m_typeArgs = msg.m_typeargs();
	m_areaId = msg.m_areaid();
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
	m_recommendLv = (int32_t)0;
	m_recommendYK = (int32_t)0;
	m_reward = (int32_t)0;
	m_firstPass = (int32_t)0;
	m_overlordBox = (int32_t)0;
	m_overlordTime = (int32_t)0;
	return 0;
}

int E_DupYt_dup_s::ResumeInit() {
	return 0;
}

void E_DupYt_dup_s::write_to_pbmsg(::proto_ff::E_DupYt_dup & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_layer((int32_t)m_layer);
	msg.set_m_stage((int32_t)m_stage);
	msg.set_m_recommendlv((int32_t)m_recommendLv);
	msg.set_m_recommendyk((int32_t)m_recommendYK);
	msg.set_m_reward((int32_t)m_reward);
	msg.set_m_firstpass((int32_t)m_firstPass);
	msg.set_m_overlordbox((int32_t)m_overlordBox);
	msg.set_m_overlordtime((int32_t)m_overlordTime);
	for(int32_t i = 0; i < (int32_t)m_clear.size(); ++i) {
		::proto_ff::E_DupYt_dupClearDesc* temp_m_clear = msg.add_m_clear();
		m_clear[i].write_to_pbmsg(*temp_m_clear);
	}
}

void E_DupYt_dup_s::read_from_pbmsg(const ::proto_ff::E_DupYt_dup & msg) {
	m_id = msg.m_id();
	m_layer = msg.m_layer();
	m_stage = msg.m_stage();
	m_recommendLv = msg.m_recommendlv();
	m_recommendYK = msg.m_recommendyk();
	m_reward = msg.m_reward();
	m_firstPass = msg.m_firstpass();
	m_overlordBox = msg.m_overlordbox();
	m_overlordTime = msg.m_overlordtime();
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
