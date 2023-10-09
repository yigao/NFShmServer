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
	m_isactive = (int32_t)0;
	m_returntype = (int32_t)0;
	m_view = (int32_t)0;
	m_isattackedshowoff = (int32_t)0;
	m_pursuerange = (int32_t)0;
	m_actionrange = (int32_t)0;
	m_wakeupradius = (int32_t)0;
	m_isaiworkwhennobody = (int32_t)0;
	m_borneffectaidelay = (int32_t)0;
	return 0;
}

int E_AiAi_s::ResumeInit() {
	return 0;
}

void E_AiAi_s::write_to_pbmsg(::proto_ff::E_AiAi & msg) const {
	msg.set_m_id((int64_t)m_id);
	msg.set_m_type((int32_t)m_type);
	msg.set_m_deadhateremain(m_deadhateremain.data());
	msg.set_m_invisibleremain(m_invisibleremain.data());
	msg.set_m_isactive((int32_t)m_isactive);
	msg.set_m_returntype((int32_t)m_returntype);
	msg.set_m_view((int32_t)m_view);
	msg.set_m_isattackedshowoff((int32_t)m_isattackedshowoff);
	msg.set_m_pursuerange((int32_t)m_pursuerange);
	msg.set_m_actionrange((int32_t)m_actionrange);
	msg.set_m_wakeupradius((int32_t)m_wakeupradius);
	msg.set_m_isaiworkwhennobody((int32_t)m_isaiworkwhennobody);
	msg.set_m_borneffectaidelay((int32_t)m_borneffectaidelay);
	msg.set_m_initskills(m_initskills.data());
	for(int32_t i = 0; i < (int32_t)m_hp.size(); ++i) {
		::proto_ff::E_AiAiHpDesc* temp_m_hp = msg.add_m_hp();
		m_hp[i].write_to_pbmsg(*temp_m_hp);
	}
}

void E_AiAi_s::read_from_pbmsg(const ::proto_ff::E_AiAi & msg) {
	m_id = msg.m_id();
	m_type = msg.m_type();
	m_deadhateremain = msg.m_deadhateremain();
	m_invisibleremain = msg.m_invisibleremain();
	m_isactive = msg.m_isactive();
	m_returntype = msg.m_returntype();
	m_view = msg.m_view();
	m_isattackedshowoff = msg.m_isattackedshowoff();
	m_pursuerange = msg.m_pursuerange();
	m_actionrange = msg.m_actionrange();
	m_wakeupradius = msg.m_wakeupradius();
	m_isaiworkwhennobody = msg.m_isaiworkwhennobody();
	m_borneffectaidelay = msg.m_borneffectaidelay();
	m_initskills = msg.m_initskills();
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
