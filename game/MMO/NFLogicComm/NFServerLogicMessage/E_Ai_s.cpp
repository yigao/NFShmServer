#include "E_Ai_s.h"

namespace proto_ff_s {

E_AiAiHpDesc_s::E_AiAiHpDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_AiAiHpDesc_s::CreateInit() {
	m_chat = (int64_t)0;
	m_skill = (int64_t)0;
	m_percent = (int32_t)0;
	return 0;
}

int E_AiAiHpDesc_s::ResumeInit() {
	return 0;
}

void E_AiAiHpDesc_s::write_to_pbmsg(::proto_ff::E_AiAiHpDesc & msg) const {
	msg.set_m_chat((int64_t)m_chat);
	msg.set_m_skill((int64_t)m_skill);
	msg.set_m_percent((int32_t)m_percent);
}

void E_AiAiHpDesc_s::read_from_pbmsg(const ::proto_ff::E_AiAiHpDesc & msg) {
	m_chat = msg.m_chat();
	m_skill = msg.m_skill();
	m_percent = msg.m_percent();
}

E_AiAi_s::E_AiAi_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_AiAi_s::CreateInit() {
	m_id = (int64_t)0;
	m_type = (int32_t)0;
	m_isActive = (int32_t)0;
	m_returnType = (int32_t)0;
	m_view = (int32_t)0;
	m_isAttackedShowOff = (int32_t)0;
	m_pursueRange = (int32_t)0;
	m_actionRange = (int32_t)0;
	m_wakeupRadius = (int32_t)0;
	m_isAIWorkWhenNobody = (int32_t)0;
	m_bornEffectAIDelay = (int32_t)0;
	return 0;
}

int E_AiAi_s::ResumeInit() {
	return 0;
}

void E_AiAi_s::write_to_pbmsg(::proto_ff::E_AiAi & msg) const {
	msg.set_m_id((int64_t)m_id);
	msg.set_m_type((int32_t)m_type);
	msg.set_m_deadhateremain(m_deadHateRemain.data());
	msg.set_m_invisibleremain(m_invisibleRemain.data());
	msg.set_m_isactive((int32_t)m_isActive);
	msg.set_m_returntype((int32_t)m_returnType);
	msg.set_m_view((int32_t)m_view);
	msg.set_m_isattackedshowoff((int32_t)m_isAttackedShowOff);
	msg.set_m_pursuerange((int32_t)m_pursueRange);
	msg.set_m_actionrange((int32_t)m_actionRange);
	msg.set_m_wakeupradius((int32_t)m_wakeupRadius);
	msg.set_m_isaiworkwhennobody((int32_t)m_isAIWorkWhenNobody);
	msg.set_m_borneffectaidelay((int32_t)m_bornEffectAIDelay);
	msg.set_m_initskills(m_initSkills.data());
	for(int32_t i = 0; i < (int32_t)m_hp.size(); ++i) {
		::proto_ff::E_AiAiHpDesc* temp_m_hp = msg.add_m_hp();
		m_hp[i].write_to_pbmsg(*temp_m_hp);
	}
}

void E_AiAi_s::read_from_pbmsg(const ::proto_ff::E_AiAi & msg) {
	m_id = msg.m_id();
	m_type = msg.m_type();
	m_deadHateRemain = msg.m_deadhateremain();
	m_invisibleRemain = msg.m_invisibleremain();
	m_isActive = msg.m_isactive();
	m_returnType = msg.m_returntype();
	m_view = msg.m_view();
	m_isAttackedShowOff = msg.m_isattackedshowoff();
	m_pursueRange = msg.m_pursuerange();
	m_actionRange = msg.m_actionrange();
	m_wakeupRadius = msg.m_wakeupradius();
	m_isAIWorkWhenNobody = msg.m_isaiworkwhennobody();
	m_bornEffectAIDelay = msg.m_borneffectaidelay();
	m_initSkills = msg.m_initskills();
	m_hp.resize((int)msg.m_hp_size() > (int)m_hp.max_size() ? m_hp.max_size() : msg.m_hp_size());
	for(int32_t i = 0; i < (int32_t)m_hp.size(); ++i) {
		const ::proto_ff::E_AiAiHpDesc & temp_m_hp = msg.m_hp(i);
		m_hp[i].read_from_pbmsg(temp_m_hp);
	}
}

Sheet_AiAi_s::Sheet_AiAi_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_AiAi_s::CreateInit() {
	return 0;
}

int Sheet_AiAi_s::ResumeInit() {
	return 0;
}

void Sheet_AiAi_s::write_to_pbmsg(::proto_ff::Sheet_AiAi & msg) const {
	for(int32_t i = 0; i < (int32_t)E_AiAi_List.size(); ++i) {
		::proto_ff::E_AiAi* temp_e_aiai_list = msg.add_e_aiai_list();
		E_AiAi_List[i].write_to_pbmsg(*temp_e_aiai_list);
	}
}

void Sheet_AiAi_s::read_from_pbmsg(const ::proto_ff::Sheet_AiAi & msg) {
	E_AiAi_List.resize((int)msg.e_aiai_list_size() > (int)E_AiAi_List.max_size() ? E_AiAi_List.max_size() : msg.e_aiai_list_size());
	for(int32_t i = 0; i < (int32_t)E_AiAi_List.size(); ++i) {
		const ::proto_ff::E_AiAi & temp_e_aiai_list = msg.e_aiai_list(i);
		E_AiAi_List[i].read_from_pbmsg(temp_e_aiai_list);
	}
}

}
