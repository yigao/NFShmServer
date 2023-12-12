#include "E_Xiuzhenroad_s.h"

namespace proto_ff_s {

E_XiuzhenroadTask_s::E_XiuzhenroadTask_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_XiuzhenroadTask_s::CreateInit() {
	m_taskId = (int64_t)0;
	m_taskType = (int32_t)0;
	m_eventType = (int32_t)0;
	m_reachPrice = (int32_t)0;
	m_reward = (int32_t)0;
	m_reward_Value = (int32_t)0;
	m_boxID = (int32_t)0;
	m_integral = (int32_t)0;
	m_linkid = (int32_t)0;
	return 0;
}

int E_XiuzhenroadTask_s::ResumeInit() {
	return 0;
}

void E_XiuzhenroadTask_s::write_to_pbmsg(::proto_ff::E_XiuzhenroadTask & msg) const {
	msg.set_m_taskid((int64_t)m_taskId);
	msg.set_m_tasktype((int32_t)m_taskType);
	msg.set_m_eventtype((int32_t)m_eventType);
	msg.set_m_reachprice((int32_t)m_reachPrice);
	msg.set_m_reward((int32_t)m_reward);
	msg.set_m_reward_value((int32_t)m_reward_Value);
	msg.set_m_boxid((int32_t)m_boxID);
	msg.set_m_integral((int32_t)m_integral);
	msg.set_m_linkid((int32_t)m_linkid);
	for(int32_t i = 0; i < (int32_t)m_param.size(); ++i) {
		msg.add_m_param((int32_t)m_param[i]);
	}
}

void E_XiuzhenroadTask_s::read_from_pbmsg(const ::proto_ff::E_XiuzhenroadTask & msg) {
	m_taskId = msg.m_taskid();
	m_taskType = msg.m_tasktype();
	m_eventType = msg.m_eventtype();
	m_reachPrice = msg.m_reachprice();
	m_reward = msg.m_reward();
	m_reward_Value = msg.m_reward_value();
	m_boxID = msg.m_boxid();
	m_integral = msg.m_integral();
	m_linkid = msg.m_linkid();
	m_param.resize((int)msg.m_param_size() > (int)m_param.max_size() ? m_param.max_size() : msg.m_param_size());
	for(int32_t i = 0; i < (int32_t)m_param.size(); ++i) {
		m_param[i] = msg.m_param(i);
	}
}

Sheet_XiuzhenroadTask_s::Sheet_XiuzhenroadTask_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_XiuzhenroadTask_s::CreateInit() {
	return 0;
}

int Sheet_XiuzhenroadTask_s::ResumeInit() {
	return 0;
}

void Sheet_XiuzhenroadTask_s::write_to_pbmsg(::proto_ff::Sheet_XiuzhenroadTask & msg) const {
	for(int32_t i = 0; i < (int32_t)E_XiuzhenroadTask_List.size(); ++i) {
		::proto_ff::E_XiuzhenroadTask* temp_e_xiuzhenroadtask_list = msg.add_e_xiuzhenroadtask_list();
		E_XiuzhenroadTask_List[i].write_to_pbmsg(*temp_e_xiuzhenroadtask_list);
	}
}

void Sheet_XiuzhenroadTask_s::read_from_pbmsg(const ::proto_ff::Sheet_XiuzhenroadTask & msg) {
	E_XiuzhenroadTask_List.resize((int)msg.e_xiuzhenroadtask_list_size() > (int)E_XiuzhenroadTask_List.max_size() ? E_XiuzhenroadTask_List.max_size() : msg.e_xiuzhenroadtask_list_size());
	for(int32_t i = 0; i < (int32_t)E_XiuzhenroadTask_List.size(); ++i) {
		const ::proto_ff::E_XiuzhenroadTask & temp_e_xiuzhenroadtask_list = msg.e_xiuzhenroadtask_list(i);
		E_XiuzhenroadTask_List[i].read_from_pbmsg(temp_e_xiuzhenroadtask_list);
	}
}

E_XiuzhenroadBonuspointsTotalitemsDesc_s::E_XiuzhenroadBonuspointsTotalitemsDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_XiuzhenroadBonuspointsTotalitemsDesc_s::CreateInit() {
	m_Value = (int32_t)0;
	m_ID = (int32_t)0;
	return 0;
}

int E_XiuzhenroadBonuspointsTotalitemsDesc_s::ResumeInit() {
	return 0;
}

void E_XiuzhenroadBonuspointsTotalitemsDesc_s::write_to_pbmsg(::proto_ff::E_XiuzhenroadBonuspointsTotalitemsDesc & msg) const {
	msg.set_m_value((int32_t)m_Value);
	msg.set_m_id((int32_t)m_ID);
}

void E_XiuzhenroadBonuspointsTotalitemsDesc_s::read_from_pbmsg(const ::proto_ff::E_XiuzhenroadBonuspointsTotalitemsDesc & msg) {
	m_Value = msg.m_value();
	m_ID = msg.m_id();
}

E_XiuzhenroadBonuspoints_s::E_XiuzhenroadBonuspoints_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_XiuzhenroadBonuspoints_s::CreateInit() {
	m_totalRewardsID = (int32_t)0;
	m_achievedPoints = (int32_t)0;
	return 0;
}

int E_XiuzhenroadBonuspoints_s::ResumeInit() {
	return 0;
}

void E_XiuzhenroadBonuspoints_s::write_to_pbmsg(::proto_ff::E_XiuzhenroadBonuspoints & msg) const {
	msg.set_m_totalrewardsid((int32_t)m_totalRewardsID);
	msg.set_m_achievedpoints((int32_t)m_achievedPoints);
	for(int32_t i = 0; i < (int32_t)m_totalItems.size(); ++i) {
		::proto_ff::E_XiuzhenroadBonuspointsTotalitemsDesc* temp_m_totalitems = msg.add_m_totalitems();
		m_totalItems[i].write_to_pbmsg(*temp_m_totalitems);
	}
}

void E_XiuzhenroadBonuspoints_s::read_from_pbmsg(const ::proto_ff::E_XiuzhenroadBonuspoints & msg) {
	m_totalRewardsID = msg.m_totalrewardsid();
	m_achievedPoints = msg.m_achievedpoints();
	m_totalItems.resize((int)msg.m_totalitems_size() > (int)m_totalItems.max_size() ? m_totalItems.max_size() : msg.m_totalitems_size());
	for(int32_t i = 0; i < (int32_t)m_totalItems.size(); ++i) {
		const ::proto_ff::E_XiuzhenroadBonuspointsTotalitemsDesc & temp_m_totalitems = msg.m_totalitems(i);
		m_totalItems[i].read_from_pbmsg(temp_m_totalitems);
	}
}

Sheet_XiuzhenroadBonuspoints_s::Sheet_XiuzhenroadBonuspoints_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_XiuzhenroadBonuspoints_s::CreateInit() {
	return 0;
}

int Sheet_XiuzhenroadBonuspoints_s::ResumeInit() {
	return 0;
}

void Sheet_XiuzhenroadBonuspoints_s::write_to_pbmsg(::proto_ff::Sheet_XiuzhenroadBonuspoints & msg) const {
	for(int32_t i = 0; i < (int32_t)E_XiuzhenroadBonuspoints_List.size(); ++i) {
		::proto_ff::E_XiuzhenroadBonuspoints* temp_e_xiuzhenroadbonuspoints_list = msg.add_e_xiuzhenroadbonuspoints_list();
		E_XiuzhenroadBonuspoints_List[i].write_to_pbmsg(*temp_e_xiuzhenroadbonuspoints_list);
	}
}

void Sheet_XiuzhenroadBonuspoints_s::read_from_pbmsg(const ::proto_ff::Sheet_XiuzhenroadBonuspoints & msg) {
	E_XiuzhenroadBonuspoints_List.resize((int)msg.e_xiuzhenroadbonuspoints_list_size() > (int)E_XiuzhenroadBonuspoints_List.max_size() ? E_XiuzhenroadBonuspoints_List.max_size() : msg.e_xiuzhenroadbonuspoints_list_size());
	for(int32_t i = 0; i < (int32_t)E_XiuzhenroadBonuspoints_List.size(); ++i) {
		const ::proto_ff::E_XiuzhenroadBonuspoints & temp_e_xiuzhenroadbonuspoints_list = msg.e_xiuzhenroadbonuspoints_list(i);
		E_XiuzhenroadBonuspoints_List[i].read_from_pbmsg(temp_e_xiuzhenroadbonuspoints_list);
	}
}

E_XiuzhenroadSkill_s::E_XiuzhenroadSkill_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_XiuzhenroadSkill_s::CreateInit() {
	m_activitySkills = (int32_t)0;
	m_skillID = (int32_t)0;
	m_itenmID = (int32_t)0;
	m_attribute = (int32_t)0;
	return 0;
}

int E_XiuzhenroadSkill_s::ResumeInit() {
	return 0;
}

void E_XiuzhenroadSkill_s::write_to_pbmsg(::proto_ff::E_XiuzhenroadSkill & msg) const {
	msg.set_m_activityskills((int32_t)m_activitySkills);
	msg.set_m_skillid((int32_t)m_skillID);
	msg.set_m_itenmid((int32_t)m_itenmID);
	msg.set_m_attribute((int32_t)m_attribute);
}

void E_XiuzhenroadSkill_s::read_from_pbmsg(const ::proto_ff::E_XiuzhenroadSkill & msg) {
	m_activitySkills = msg.m_activityskills();
	m_skillID = msg.m_skillid();
	m_itenmID = msg.m_itenmid();
	m_attribute = msg.m_attribute();
}

Sheet_XiuzhenroadSkill_s::Sheet_XiuzhenroadSkill_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_XiuzhenroadSkill_s::CreateInit() {
	return 0;
}

int Sheet_XiuzhenroadSkill_s::ResumeInit() {
	return 0;
}

void Sheet_XiuzhenroadSkill_s::write_to_pbmsg(::proto_ff::Sheet_XiuzhenroadSkill & msg) const {
	for(int32_t i = 0; i < (int32_t)E_XiuzhenroadSkill_List.size(); ++i) {
		::proto_ff::E_XiuzhenroadSkill* temp_e_xiuzhenroadskill_list = msg.add_e_xiuzhenroadskill_list();
		E_XiuzhenroadSkill_List[i].write_to_pbmsg(*temp_e_xiuzhenroadskill_list);
	}
}

void Sheet_XiuzhenroadSkill_s::read_from_pbmsg(const ::proto_ff::Sheet_XiuzhenroadSkill & msg) {
	E_XiuzhenroadSkill_List.resize((int)msg.e_xiuzhenroadskill_list_size() > (int)E_XiuzhenroadSkill_List.max_size() ? E_XiuzhenroadSkill_List.max_size() : msg.e_xiuzhenroadskill_list_size());
	for(int32_t i = 0; i < (int32_t)E_XiuzhenroadSkill_List.size(); ++i) {
		const ::proto_ff::E_XiuzhenroadSkill & temp_e_xiuzhenroadskill_list = msg.e_xiuzhenroadskill_list(i);
		E_XiuzhenroadSkill_List[i].read_from_pbmsg(temp_e_xiuzhenroadskill_list);
	}
}

E_XiuzhenroadClassify_s::E_XiuzhenroadClassify_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_XiuzhenroadClassify_s::CreateInit() {
	m_typeID = (int32_t)0;
	m_giftID = (int32_t)0;
	m_rechargeID = (int32_t)0;
	return 0;
}

int E_XiuzhenroadClassify_s::ResumeInit() {
	return 0;
}

void E_XiuzhenroadClassify_s::write_to_pbmsg(::proto_ff::E_XiuzhenroadClassify & msg) const {
	msg.set_m_typeid((int32_t)m_typeID);
	msg.set_m_gift(m_gift.data());
	msg.set_m_giftid((int32_t)m_giftID);
	msg.set_m_rechargeid((int32_t)m_rechargeID);
}

void E_XiuzhenroadClassify_s::read_from_pbmsg(const ::proto_ff::E_XiuzhenroadClassify & msg) {
	m_typeID = msg.m_typeid();
	m_gift = msg.m_gift();
	m_giftID = msg.m_giftid();
	m_rechargeID = msg.m_rechargeid();
}

Sheet_XiuzhenroadClassify_s::Sheet_XiuzhenroadClassify_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_XiuzhenroadClassify_s::CreateInit() {
	return 0;
}

int Sheet_XiuzhenroadClassify_s::ResumeInit() {
	return 0;
}

void Sheet_XiuzhenroadClassify_s::write_to_pbmsg(::proto_ff::Sheet_XiuzhenroadClassify & msg) const {
	for(int32_t i = 0; i < (int32_t)E_XiuzhenroadClassify_List.size(); ++i) {
		::proto_ff::E_XiuzhenroadClassify* temp_e_xiuzhenroadclassify_list = msg.add_e_xiuzhenroadclassify_list();
		E_XiuzhenroadClassify_List[i].write_to_pbmsg(*temp_e_xiuzhenroadclassify_list);
	}
}

void Sheet_XiuzhenroadClassify_s::read_from_pbmsg(const ::proto_ff::Sheet_XiuzhenroadClassify & msg) {
	E_XiuzhenroadClassify_List.resize((int)msg.e_xiuzhenroadclassify_list_size() > (int)E_XiuzhenroadClassify_List.max_size() ? E_XiuzhenroadClassify_List.max_size() : msg.e_xiuzhenroadclassify_list_size());
	for(int32_t i = 0; i < (int32_t)E_XiuzhenroadClassify_List.size(); ++i) {
		const ::proto_ff::E_XiuzhenroadClassify & temp_e_xiuzhenroadclassify_list = msg.e_xiuzhenroadclassify_list(i);
		E_XiuzhenroadClassify_List[i].read_from_pbmsg(temp_e_xiuzhenroadclassify_list);
	}
}

}
