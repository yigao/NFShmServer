#include "E_Tianxiafirst_s.h"

namespace proto_ff_s {

E_TianxiafirstConstant_s::E_TianxiafirstConstant_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_TianxiafirstConstant_s::CreateInit() {
	m_id = (int32_t)0;
	m_teamMember = (int32_t)0;
	m_cedeTime = (int32_t)0;
	m_punishTime = (int32_t)0;
	m_breakTime = (int32_t)0;
	m_unitName = (int32_t)0;
	m_unitCost = (int32_t)0;
	m_entrTimes = (int32_t)0;
	m_mvpReward = (int32_t)0;
	m_matchTime = (int32_t)0;
	m_autoMatchTime = (int32_t)0;
	m_endTipsTime = (int32_t)0;
	m_readyTime = (int32_t)0;
	m_summonItem = (int32_t)0;
	m_summonNum = (int32_t)0;
	m_showReward = (int32_t)0;
	m_mateTime = (int32_t)0;
	m_addTime = (int32_t)0;
	m_freeTime = (int32_t)0;
	m_expendItem = (int32_t)0;
	m_addServe = (int32_t)0;
	m_serveTitle = (int32_t)0;
	m_guessLimit = (int32_t)0;
	return 0;
}

int E_TianxiafirstConstant_s::ResumeInit() {
	return 0;
}

void E_TianxiafirstConstant_s::write_to_pbmsg(::proto_ff::E_TianxiafirstConstant & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_teammember((int32_t)m_teamMember);
	msg.set_m_cedetime((int32_t)m_cedeTime);
	msg.set_m_punishtime((int32_t)m_punishTime);
	msg.set_m_breaktime((int32_t)m_breakTime);
	msg.set_m_unitname((int32_t)m_unitName);
	msg.set_m_unitcost((int32_t)m_unitCost);
	msg.set_m_entrtimes((int32_t)m_entrTimes);
	msg.set_m_mvpreward((int32_t)m_mvpReward);
	msg.set_m_matchtime((int32_t)m_matchTime);
	msg.set_m_automatchtime((int32_t)m_autoMatchTime);
	msg.set_m_endtipstime((int32_t)m_endTipsTime);
	msg.set_m_readytime((int32_t)m_readyTime);
	msg.set_m_summonitem((int32_t)m_summonItem);
	msg.set_m_summonnum((int32_t)m_summonNum);
	msg.set_m_showreward((int32_t)m_showReward);
	msg.set_m_robotname(m_robotName.data());
	msg.set_m_matetime((int32_t)m_mateTime);
	msg.set_m_addtime((int32_t)m_addTime);
	msg.set_m_initialnotice(m_initialNotice.data());
	msg.set_m_freetime((int32_t)m_freeTime);
	msg.set_m_expenditem((int32_t)m_expendItem);
	msg.set_m_addserve((int32_t)m_addServe);
	msg.set_m_servetitle((int32_t)m_serveTitle);
	msg.set_m_guesslimit((int32_t)m_guessLimit);
	msg.set_m_exchangeratio(m_exchangeRatio.data());
	for(int32_t i = 0; i < (int32_t)m_group.size(); ++i) {
		msg.add_m_group(m_group[i].data());
	}
}

void E_TianxiafirstConstant_s::read_from_pbmsg(const ::proto_ff::E_TianxiafirstConstant & msg) {
	m_id = msg.m_id();
	m_teamMember = msg.m_teammember();
	m_cedeTime = msg.m_cedetime();
	m_punishTime = msg.m_punishtime();
	m_breakTime = msg.m_breaktime();
	m_unitName = msg.m_unitname();
	m_unitCost = msg.m_unitcost();
	m_entrTimes = msg.m_entrtimes();
	m_mvpReward = msg.m_mvpreward();
	m_matchTime = msg.m_matchtime();
	m_autoMatchTime = msg.m_automatchtime();
	m_endTipsTime = msg.m_endtipstime();
	m_readyTime = msg.m_readytime();
	m_summonItem = msg.m_summonitem();
	m_summonNum = msg.m_summonnum();
	m_showReward = msg.m_showreward();
	m_robotName = msg.m_robotname();
	m_mateTime = msg.m_matetime();
	m_addTime = msg.m_addtime();
	m_initialNotice = msg.m_initialnotice();
	m_freeTime = msg.m_freetime();
	m_expendItem = msg.m_expenditem();
	m_addServe = msg.m_addserve();
	m_serveTitle = msg.m_servetitle();
	m_guessLimit = msg.m_guesslimit();
	m_exchangeRatio = msg.m_exchangeratio();
	m_group.resize((int)msg.m_group_size() > (int)m_group.max_size() ? m_group.max_size() : msg.m_group_size());
	for(int32_t i = 0; i < (int32_t)m_group.size(); ++i) {
		m_group[i] = msg.m_group(i);
	}
}

Sheet_TianxiafirstConstant_s::Sheet_TianxiafirstConstant_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_TianxiafirstConstant_s::CreateInit() {
	return 0;
}

int Sheet_TianxiafirstConstant_s::ResumeInit() {
	return 0;
}

void Sheet_TianxiafirstConstant_s::write_to_pbmsg(::proto_ff::Sheet_TianxiafirstConstant & msg) const {
	for(int32_t i = 0; i < (int32_t)E_TianxiafirstConstant_List.size(); ++i) {
		::proto_ff::E_TianxiafirstConstant* temp_e_tianxiafirstconstant_list = msg.add_e_tianxiafirstconstant_list();
		E_TianxiafirstConstant_List[i].write_to_pbmsg(*temp_e_tianxiafirstconstant_list);
	}
}

void Sheet_TianxiafirstConstant_s::read_from_pbmsg(const ::proto_ff::Sheet_TianxiafirstConstant & msg) {
	E_TianxiafirstConstant_List.resize((int)msg.e_tianxiafirstconstant_list_size() > (int)E_TianxiafirstConstant_List.max_size() ? E_TianxiafirstConstant_List.max_size() : msg.e_tianxiafirstconstant_list_size());
	for(int32_t i = 0; i < (int32_t)E_TianxiafirstConstant_List.size(); ++i) {
		const ::proto_ff::E_TianxiafirstConstant & temp_e_tianxiafirstconstant_list = msg.e_tianxiafirstconstant_list(i);
		E_TianxiafirstConstant_List[i].read_from_pbmsg(temp_e_tianxiafirstconstant_list);
	}
}

E_TianxiafirstBattle_s::E_TianxiafirstBattle_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_TianxiafirstBattle_s::CreateInit() {
	m_id = (int32_t)0;
	m_gamemod = (int32_t)0;
	m_matchTime = (int32_t)0;
	m_revive = (int32_t)0;
	return 0;
}

int E_TianxiafirstBattle_s::ResumeInit() {
	return 0;
}

void E_TianxiafirstBattle_s::write_to_pbmsg(::proto_ff::E_TianxiafirstBattle & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_gamemod((int32_t)m_gamemod);
	msg.set_m_matchtime((int32_t)m_matchTime);
	msg.set_m_revive((int32_t)m_revive);
}

void E_TianxiafirstBattle_s::read_from_pbmsg(const ::proto_ff::E_TianxiafirstBattle & msg) {
	m_id = msg.m_id();
	m_gamemod = msg.m_gamemod();
	m_matchTime = msg.m_matchtime();
	m_revive = msg.m_revive();
}

Sheet_TianxiafirstBattle_s::Sheet_TianxiafirstBattle_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_TianxiafirstBattle_s::CreateInit() {
	return 0;
}

int Sheet_TianxiafirstBattle_s::ResumeInit() {
	return 0;
}

void Sheet_TianxiafirstBattle_s::write_to_pbmsg(::proto_ff::Sheet_TianxiafirstBattle & msg) const {
	for(int32_t i = 0; i < (int32_t)E_TianxiafirstBattle_List.size(); ++i) {
		::proto_ff::E_TianxiafirstBattle* temp_e_tianxiafirstbattle_list = msg.add_e_tianxiafirstbattle_list();
		E_TianxiafirstBattle_List[i].write_to_pbmsg(*temp_e_tianxiafirstbattle_list);
	}
}

void Sheet_TianxiafirstBattle_s::read_from_pbmsg(const ::proto_ff::Sheet_TianxiafirstBattle & msg) {
	E_TianxiafirstBattle_List.resize((int)msg.e_tianxiafirstbattle_list_size() > (int)E_TianxiafirstBattle_List.max_size() ? E_TianxiafirstBattle_List.max_size() : msg.e_tianxiafirstbattle_list_size());
	for(int32_t i = 0; i < (int32_t)E_TianxiafirstBattle_List.size(); ++i) {
		const ::proto_ff::E_TianxiafirstBattle & temp_e_tianxiafirstbattle_list = msg.e_tianxiafirstbattle_list(i);
		E_TianxiafirstBattle_List[i].read_from_pbmsg(temp_e_tianxiafirstbattle_list);
	}
}

E_TianxiafirstArtifactAttDesc_s::E_TianxiafirstArtifactAttDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_TianxiafirstArtifactAttDesc_s::CreateInit() {
	m_value = (int32_t)0;
	m_id = (int32_t)0;
	return 0;
}

int E_TianxiafirstArtifactAttDesc_s::ResumeInit() {
	return 0;
}

void E_TianxiafirstArtifactAttDesc_s::write_to_pbmsg(::proto_ff::E_TianxiafirstArtifactAttDesc & msg) const {
	msg.set_m_value((int32_t)m_value);
	msg.set_m_id((int32_t)m_id);
}

void E_TianxiafirstArtifactAttDesc_s::read_from_pbmsg(const ::proto_ff::E_TianxiafirstArtifactAttDesc & msg) {
	m_value = msg.m_value();
	m_id = msg.m_id();
}

E_TianxiafirstArtifact_s::E_TianxiafirstArtifact_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_TianxiafirstArtifact_s::CreateInit() {
	m_artifactId = (int32_t)0;
	m_preId = (int32_t)0;
	m_condition = (int32_t)0;
	return 0;
}

int E_TianxiafirstArtifact_s::ResumeInit() {
	return 0;
}

void E_TianxiafirstArtifact_s::write_to_pbmsg(::proto_ff::E_TianxiafirstArtifact & msg) const {
	msg.set_m_artifactid((int32_t)m_artifactId);
	msg.set_m_preid((int32_t)m_preId);
	msg.set_m_condition((int32_t)m_condition);
	for(int32_t i = 0; i < (int32_t)m_att.size(); ++i) {
		::proto_ff::E_TianxiafirstArtifactAttDesc* temp_m_att = msg.add_m_att();
		m_att[i].write_to_pbmsg(*temp_m_att);
	}
}

void E_TianxiafirstArtifact_s::read_from_pbmsg(const ::proto_ff::E_TianxiafirstArtifact & msg) {
	m_artifactId = msg.m_artifactid();
	m_preId = msg.m_preid();
	m_condition = msg.m_condition();
	m_att.resize((int)msg.m_att_size() > (int)m_att.max_size() ? m_att.max_size() : msg.m_att_size());
	for(int32_t i = 0; i < (int32_t)m_att.size(); ++i) {
		const ::proto_ff::E_TianxiafirstArtifactAttDesc & temp_m_att = msg.m_att(i);
		m_att[i].read_from_pbmsg(temp_m_att);
	}
}

Sheet_TianxiafirstArtifact_s::Sheet_TianxiafirstArtifact_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_TianxiafirstArtifact_s::CreateInit() {
	return 0;
}

int Sheet_TianxiafirstArtifact_s::ResumeInit() {
	return 0;
}

void Sheet_TianxiafirstArtifact_s::write_to_pbmsg(::proto_ff::Sheet_TianxiafirstArtifact & msg) const {
	for(int32_t i = 0; i < (int32_t)E_TianxiafirstArtifact_List.size(); ++i) {
		::proto_ff::E_TianxiafirstArtifact* temp_e_tianxiafirstartifact_list = msg.add_e_tianxiafirstartifact_list();
		E_TianxiafirstArtifact_List[i].write_to_pbmsg(*temp_e_tianxiafirstartifact_list);
	}
}

void Sheet_TianxiafirstArtifact_s::read_from_pbmsg(const ::proto_ff::Sheet_TianxiafirstArtifact & msg) {
	E_TianxiafirstArtifact_List.resize((int)msg.e_tianxiafirstartifact_list_size() > (int)E_TianxiafirstArtifact_List.max_size() ? E_TianxiafirstArtifact_List.max_size() : msg.e_tianxiafirstartifact_list_size());
	for(int32_t i = 0; i < (int32_t)E_TianxiafirstArtifact_List.size(); ++i) {
		const ::proto_ff::E_TianxiafirstArtifact & temp_e_tianxiafirstartifact_list = msg.e_tianxiafirstartifact_list(i);
		E_TianxiafirstArtifact_List[i].read_from_pbmsg(temp_e_tianxiafirstartifact_list);
	}
}

E_TianxiafirstStrongTypeDesc_s::E_TianxiafirstStrongTypeDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_TianxiafirstStrongTypeDesc_s::CreateInit() {
	m_id = (int32_t)0;
	return 0;
}

int E_TianxiafirstStrongTypeDesc_s::ResumeInit() {
	return 0;
}

void E_TianxiafirstStrongTypeDesc_s::write_to_pbmsg(::proto_ff::E_TianxiafirstStrongTypeDesc & msg) const {
	msg.set_m_num(m_num.data());
	msg.set_m_id((int32_t)m_id);
}

void E_TianxiafirstStrongTypeDesc_s::read_from_pbmsg(const ::proto_ff::E_TianxiafirstStrongTypeDesc & msg) {
	m_num = msg.m_num();
	m_id = msg.m_id();
}

E_TianxiafirstStrong_s::E_TianxiafirstStrong_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_TianxiafirstStrong_s::CreateInit() {
	m_artifactId = (int32_t)0;
	m_strongUp = (int32_t)0;
	return 0;
}

int E_TianxiafirstStrong_s::ResumeInit() {
	return 0;
}

void E_TianxiafirstStrong_s::write_to_pbmsg(::proto_ff::E_TianxiafirstStrong & msg) const {
	msg.set_m_artifactid((int32_t)m_artifactId);
	msg.set_m_strongup((int32_t)m_strongUp);
	msg.set_m_exp(m_exp.data());
	for(int32_t i = 0; i < (int32_t)m_type.size(); ++i) {
		::proto_ff::E_TianxiafirstStrongTypeDesc* temp_m_type = msg.add_m_type();
		m_type[i].write_to_pbmsg(*temp_m_type);
	}
}

void E_TianxiafirstStrong_s::read_from_pbmsg(const ::proto_ff::E_TianxiafirstStrong & msg) {
	m_artifactId = msg.m_artifactid();
	m_strongUp = msg.m_strongup();
	m_exp = msg.m_exp();
	m_type.resize((int)msg.m_type_size() > (int)m_type.max_size() ? m_type.max_size() : msg.m_type_size());
	for(int32_t i = 0; i < (int32_t)m_type.size(); ++i) {
		const ::proto_ff::E_TianxiafirstStrongTypeDesc & temp_m_type = msg.m_type(i);
		m_type[i].read_from_pbmsg(temp_m_type);
	}
}

Sheet_TianxiafirstStrong_s::Sheet_TianxiafirstStrong_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_TianxiafirstStrong_s::CreateInit() {
	return 0;
}

int Sheet_TianxiafirstStrong_s::ResumeInit() {
	return 0;
}

void Sheet_TianxiafirstStrong_s::write_to_pbmsg(::proto_ff::Sheet_TianxiafirstStrong & msg) const {
	for(int32_t i = 0; i < (int32_t)E_TianxiafirstStrong_List.size(); ++i) {
		::proto_ff::E_TianxiafirstStrong* temp_e_tianxiafirststrong_list = msg.add_e_tianxiafirststrong_list();
		E_TianxiafirstStrong_List[i].write_to_pbmsg(*temp_e_tianxiafirststrong_list);
	}
}

void Sheet_TianxiafirstStrong_s::read_from_pbmsg(const ::proto_ff::Sheet_TianxiafirstStrong & msg) {
	E_TianxiafirstStrong_List.resize((int)msg.e_tianxiafirststrong_list_size() > (int)E_TianxiafirstStrong_List.max_size() ? E_TianxiafirstStrong_List.max_size() : msg.e_tianxiafirststrong_list_size());
	for(int32_t i = 0; i < (int32_t)E_TianxiafirstStrong_List.size(); ++i) {
		const ::proto_ff::E_TianxiafirstStrong & temp_e_tianxiafirststrong_list = msg.e_tianxiafirststrong_list(i);
		E_TianxiafirstStrong_List[i].read_from_pbmsg(temp_e_tianxiafirststrong_list);
	}
}

E_TianxiafirstStrongitem_s::E_TianxiafirstStrongitem_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_TianxiafirstStrongitem_s::CreateInit() {
	m_id = (int32_t)0;
	m_addExp = (int32_t)0;
	return 0;
}

int E_TianxiafirstStrongitem_s::ResumeInit() {
	return 0;
}

void E_TianxiafirstStrongitem_s::write_to_pbmsg(::proto_ff::E_TianxiafirstStrongitem & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_addexp((int32_t)m_addExp);
}

void E_TianxiafirstStrongitem_s::read_from_pbmsg(const ::proto_ff::E_TianxiafirstStrongitem & msg) {
	m_id = msg.m_id();
	m_addExp = msg.m_addexp();
}

Sheet_TianxiafirstStrongitem_s::Sheet_TianxiafirstStrongitem_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_TianxiafirstStrongitem_s::CreateInit() {
	return 0;
}

int Sheet_TianxiafirstStrongitem_s::ResumeInit() {
	return 0;
}

void Sheet_TianxiafirstStrongitem_s::write_to_pbmsg(::proto_ff::Sheet_TianxiafirstStrongitem & msg) const {
	for(int32_t i = 0; i < (int32_t)E_TianxiafirstStrongitem_List.size(); ++i) {
		::proto_ff::E_TianxiafirstStrongitem* temp_e_tianxiafirststrongitem_list = msg.add_e_tianxiafirststrongitem_list();
		E_TianxiafirstStrongitem_List[i].write_to_pbmsg(*temp_e_tianxiafirststrongitem_list);
	}
}

void Sheet_TianxiafirstStrongitem_s::read_from_pbmsg(const ::proto_ff::Sheet_TianxiafirstStrongitem & msg) {
	E_TianxiafirstStrongitem_List.resize((int)msg.e_tianxiafirststrongitem_list_size() > (int)E_TianxiafirstStrongitem_List.max_size() ? E_TianxiafirstStrongitem_List.max_size() : msg.e_tianxiafirststrongitem_list_size());
	for(int32_t i = 0; i < (int32_t)E_TianxiafirstStrongitem_List.size(); ++i) {
		const ::proto_ff::E_TianxiafirstStrongitem & temp_e_tianxiafirststrongitem_list = msg.e_tianxiafirststrongitem_list(i);
		E_TianxiafirstStrongitem_List[i].read_from_pbmsg(temp_e_tianxiafirststrongitem_list);
	}
}

E_TianxiafirstRefineAttDesc_s::E_TianxiafirstRefineAttDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_TianxiafirstRefineAttDesc_s::CreateInit() {
	m_num = (int32_t)0;
	m_id = (int32_t)0;
	return 0;
}

int E_TianxiafirstRefineAttDesc_s::ResumeInit() {
	return 0;
}

void E_TianxiafirstRefineAttDesc_s::write_to_pbmsg(::proto_ff::E_TianxiafirstRefineAttDesc & msg) const {
	msg.set_m_num((int32_t)m_num);
	msg.set_m_id((int32_t)m_id);
}

void E_TianxiafirstRefineAttDesc_s::read_from_pbmsg(const ::proto_ff::E_TianxiafirstRefineAttDesc & msg) {
	m_num = msg.m_num();
	m_id = msg.m_id();
}

E_TianxiafirstRefine_s::E_TianxiafirstRefine_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_TianxiafirstRefine_s::CreateInit() {
	m_id = (int32_t)0;
	m_artifactId = (int32_t)0;
	m_stage = (int32_t)0;
	m_star = (int32_t)0;
	m_success = (int32_t)0;
	m_consumeItem = (int32_t)0;
	m_consumeNum = (int32_t)0;
	m_guarant = (int32_t)0;
	return 0;
}

int E_TianxiafirstRefine_s::ResumeInit() {
	return 0;
}

void E_TianxiafirstRefine_s::write_to_pbmsg(::proto_ff::E_TianxiafirstRefine & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_artifactid((int32_t)m_artifactId);
	msg.set_m_stage((int32_t)m_stage);
	msg.set_m_star((int32_t)m_star);
	msg.set_m_success((int32_t)m_success);
	msg.set_m_consumeitem((int32_t)m_consumeItem);
	msg.set_m_consumenum((int32_t)m_consumeNum);
	msg.set_m_guarant((int32_t)m_guarant);
	for(int32_t i = 0; i < (int32_t)m_att.size(); ++i) {
		::proto_ff::E_TianxiafirstRefineAttDesc* temp_m_att = msg.add_m_att();
		m_att[i].write_to_pbmsg(*temp_m_att);
	}
}

void E_TianxiafirstRefine_s::read_from_pbmsg(const ::proto_ff::E_TianxiafirstRefine & msg) {
	m_id = msg.m_id();
	m_artifactId = msg.m_artifactid();
	m_stage = msg.m_stage();
	m_star = msg.m_star();
	m_success = msg.m_success();
	m_consumeItem = msg.m_consumeitem();
	m_consumeNum = msg.m_consumenum();
	m_guarant = msg.m_guarant();
	m_att.resize((int)msg.m_att_size() > (int)m_att.max_size() ? m_att.max_size() : msg.m_att_size());
	for(int32_t i = 0; i < (int32_t)m_att.size(); ++i) {
		const ::proto_ff::E_TianxiafirstRefineAttDesc & temp_m_att = msg.m_att(i);
		m_att[i].read_from_pbmsg(temp_m_att);
	}
}

Sheet_TianxiafirstRefine_s::Sheet_TianxiafirstRefine_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_TianxiafirstRefine_s::CreateInit() {
	return 0;
}

int Sheet_TianxiafirstRefine_s::ResumeInit() {
	return 0;
}

void Sheet_TianxiafirstRefine_s::write_to_pbmsg(::proto_ff::Sheet_TianxiafirstRefine & msg) const {
	for(int32_t i = 0; i < (int32_t)E_TianxiafirstRefine_List.size(); ++i) {
		::proto_ff::E_TianxiafirstRefine* temp_e_tianxiafirstrefine_list = msg.add_e_tianxiafirstrefine_list();
		E_TianxiafirstRefine_List[i].write_to_pbmsg(*temp_e_tianxiafirstrefine_list);
	}
}

void Sheet_TianxiafirstRefine_s::read_from_pbmsg(const ::proto_ff::Sheet_TianxiafirstRefine & msg) {
	E_TianxiafirstRefine_List.resize((int)msg.e_tianxiafirstrefine_list_size() > (int)E_TianxiafirstRefine_List.max_size() ? E_TianxiafirstRefine_List.max_size() : msg.e_tianxiafirstrefine_list_size());
	for(int32_t i = 0; i < (int32_t)E_TianxiafirstRefine_List.size(); ++i) {
		const ::proto_ff::E_TianxiafirstRefine & temp_e_tianxiafirstrefine_list = msg.e_tianxiafirstrefine_list(i);
		E_TianxiafirstRefine_List[i].read_from_pbmsg(temp_e_tianxiafirstrefine_list);
	}
}

E_TianxiafirstSqskill_s::E_TianxiafirstSqskill_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_TianxiafirstSqskill_s::CreateInit() {
	m_id = (int32_t)0;
	m_artifactId = (int32_t)0;
	m_skillId = (int32_t)0;
	m_level = (int32_t)0;
	m_condition = (int32_t)0;
	m_score = (int32_t)0;
	return 0;
}

int E_TianxiafirstSqskill_s::ResumeInit() {
	return 0;
}

void E_TianxiafirstSqskill_s::write_to_pbmsg(::proto_ff::E_TianxiafirstSqskill & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_artifactid((int32_t)m_artifactId);
	msg.set_m_skillid((int32_t)m_skillId);
	msg.set_m_level((int32_t)m_level);
	msg.set_m_condition((int32_t)m_condition);
	msg.set_m_score((int32_t)m_score);
}

void E_TianxiafirstSqskill_s::read_from_pbmsg(const ::proto_ff::E_TianxiafirstSqskill & msg) {
	m_id = msg.m_id();
	m_artifactId = msg.m_artifactid();
	m_skillId = msg.m_skillid();
	m_level = msg.m_level();
	m_condition = msg.m_condition();
	m_score = msg.m_score();
}

Sheet_TianxiafirstSqskill_s::Sheet_TianxiafirstSqskill_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_TianxiafirstSqskill_s::CreateInit() {
	return 0;
}

int Sheet_TianxiafirstSqskill_s::ResumeInit() {
	return 0;
}

void Sheet_TianxiafirstSqskill_s::write_to_pbmsg(::proto_ff::Sheet_TianxiafirstSqskill & msg) const {
	for(int32_t i = 0; i < (int32_t)E_TianxiafirstSqskill_List.size(); ++i) {
		::proto_ff::E_TianxiafirstSqskill* temp_e_tianxiafirstsqskill_list = msg.add_e_tianxiafirstsqskill_list();
		E_TianxiafirstSqskill_List[i].write_to_pbmsg(*temp_e_tianxiafirstsqskill_list);
	}
}

void Sheet_TianxiafirstSqskill_s::read_from_pbmsg(const ::proto_ff::Sheet_TianxiafirstSqskill & msg) {
	E_TianxiafirstSqskill_List.resize((int)msg.e_tianxiafirstsqskill_list_size() > (int)E_TianxiafirstSqskill_List.max_size() ? E_TianxiafirstSqskill_List.max_size() : msg.e_tianxiafirstsqskill_list_size());
	for(int32_t i = 0; i < (int32_t)E_TianxiafirstSqskill_List.size(); ++i) {
		const ::proto_ff::E_TianxiafirstSqskill & temp_e_tianxiafirstsqskill_list = msg.e_tianxiafirstsqskill_list(i);
		E_TianxiafirstSqskill_List[i].read_from_pbmsg(temp_e_tianxiafirstsqskill_list);
	}
}

E_TianxiafirstGrade_s::E_TianxiafirstGrade_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_TianxiafirstGrade_s::CreateInit() {
	m_id = (int32_t)0;
	m_grade = (int32_t)0;
	m_star = (int32_t)0;
	m_score = (int32_t)0;
	m_scoreAdd = (int32_t)0;
	m_scoringSub = (int32_t)0;
	m_Time = (int32_t)0;
	m_downLimit = (int32_t)0;
	m_upLimit = (int32_t)0;
	m_substituteTime = (int32_t)0;
	return 0;
}

int E_TianxiafirstGrade_s::ResumeInit() {
	return 0;
}

void E_TianxiafirstGrade_s::write_to_pbmsg(::proto_ff::E_TianxiafirstGrade & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_grade((int32_t)m_grade);
	msg.set_m_name(m_name.data());
	msg.set_m_star((int32_t)m_star);
	msg.set_m_score((int32_t)m_score);
	msg.set_m_scoreadd((int32_t)m_scoreAdd);
	msg.set_m_scoringsub((int32_t)m_scoringSub);
	msg.set_m_time((int32_t)m_Time);
	msg.set_m_downlimit((int32_t)m_downLimit);
	msg.set_m_uplimit((int32_t)m_upLimit);
	msg.set_m_substitutetime((int32_t)m_substituteTime);
}

void E_TianxiafirstGrade_s::read_from_pbmsg(const ::proto_ff::E_TianxiafirstGrade & msg) {
	m_id = msg.m_id();
	m_grade = msg.m_grade();
	m_name = msg.m_name();
	m_star = msg.m_star();
	m_score = msg.m_score();
	m_scoreAdd = msg.m_scoreadd();
	m_scoringSub = msg.m_scoringsub();
	m_Time = msg.m_time();
	m_downLimit = msg.m_downlimit();
	m_upLimit = msg.m_uplimit();
	m_substituteTime = msg.m_substitutetime();
}

Sheet_TianxiafirstGrade_s::Sheet_TianxiafirstGrade_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_TianxiafirstGrade_s::CreateInit() {
	return 0;
}

int Sheet_TianxiafirstGrade_s::ResumeInit() {
	return 0;
}

void Sheet_TianxiafirstGrade_s::write_to_pbmsg(::proto_ff::Sheet_TianxiafirstGrade & msg) const {
	for(int32_t i = 0; i < (int32_t)E_TianxiafirstGrade_List.size(); ++i) {
		::proto_ff::E_TianxiafirstGrade* temp_e_tianxiafirstgrade_list = msg.add_e_tianxiafirstgrade_list();
		E_TianxiafirstGrade_List[i].write_to_pbmsg(*temp_e_tianxiafirstgrade_list);
	}
}

void Sheet_TianxiafirstGrade_s::read_from_pbmsg(const ::proto_ff::Sheet_TianxiafirstGrade & msg) {
	E_TianxiafirstGrade_List.resize((int)msg.e_tianxiafirstgrade_list_size() > (int)E_TianxiafirstGrade_List.max_size() ? E_TianxiafirstGrade_List.max_size() : msg.e_tianxiafirstgrade_list_size());
	for(int32_t i = 0; i < (int32_t)E_TianxiafirstGrade_List.size(); ++i) {
		const ::proto_ff::E_TianxiafirstGrade & temp_e_tianxiafirstgrade_list = msg.e_tianxiafirstgrade_list(i);
		E_TianxiafirstGrade_List[i].read_from_pbmsg(temp_e_tianxiafirstgrade_list);
	}
}

E_TianxiafirstGraderewardRewardDesc_s::E_TianxiafirstGraderewardRewardDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_TianxiafirstGraderewardRewardDesc_s::CreateInit() {
	m_Num = (int32_t)0;
	m_ID = (int64_t)0;
	return 0;
}

int E_TianxiafirstGraderewardRewardDesc_s::ResumeInit() {
	return 0;
}

void E_TianxiafirstGraderewardRewardDesc_s::write_to_pbmsg(::proto_ff::E_TianxiafirstGraderewardRewardDesc & msg) const {
	msg.set_m_num((int32_t)m_Num);
	msg.set_m_id((int64_t)m_ID);
}

void E_TianxiafirstGraderewardRewardDesc_s::read_from_pbmsg(const ::proto_ff::E_TianxiafirstGraderewardRewardDesc & msg) {
	m_Num = msg.m_num();
	m_ID = msg.m_id();
}

E_TianxiafirstGradereward_s::E_TianxiafirstGradereward_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_TianxiafirstGradereward_s::CreateInit() {
	m_id = (int32_t)0;
	m_scoreMin = (int32_t)0;
	m_matchTimes = (int32_t)0;
	return 0;
}

int E_TianxiafirstGradereward_s::ResumeInit() {
	return 0;
}

void E_TianxiafirstGradereward_s::write_to_pbmsg(::proto_ff::E_TianxiafirstGradereward & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_scoremin((int32_t)m_scoreMin);
	msg.set_m_matchtimes((int32_t)m_matchTimes);
	for(int32_t i = 0; i < (int32_t)m_reward.size(); ++i) {
		::proto_ff::E_TianxiafirstGraderewardRewardDesc* temp_m_reward = msg.add_m_reward();
		m_reward[i].write_to_pbmsg(*temp_m_reward);
	}
}

void E_TianxiafirstGradereward_s::read_from_pbmsg(const ::proto_ff::E_TianxiafirstGradereward & msg) {
	m_id = msg.m_id();
	m_scoreMin = msg.m_scoremin();
	m_matchTimes = msg.m_matchtimes();
	m_reward.resize((int)msg.m_reward_size() > (int)m_reward.max_size() ? m_reward.max_size() : msg.m_reward_size());
	for(int32_t i = 0; i < (int32_t)m_reward.size(); ++i) {
		const ::proto_ff::E_TianxiafirstGraderewardRewardDesc & temp_m_reward = msg.m_reward(i);
		m_reward[i].read_from_pbmsg(temp_m_reward);
	}
}

Sheet_TianxiafirstGradereward_s::Sheet_TianxiafirstGradereward_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_TianxiafirstGradereward_s::CreateInit() {
	return 0;
}

int Sheet_TianxiafirstGradereward_s::ResumeInit() {
	return 0;
}

void Sheet_TianxiafirstGradereward_s::write_to_pbmsg(::proto_ff::Sheet_TianxiafirstGradereward & msg) const {
	for(int32_t i = 0; i < (int32_t)E_TianxiafirstGradereward_List.size(); ++i) {
		::proto_ff::E_TianxiafirstGradereward* temp_e_tianxiafirstgradereward_list = msg.add_e_tianxiafirstgradereward_list();
		E_TianxiafirstGradereward_List[i].write_to_pbmsg(*temp_e_tianxiafirstgradereward_list);
	}
}

void Sheet_TianxiafirstGradereward_s::read_from_pbmsg(const ::proto_ff::Sheet_TianxiafirstGradereward & msg) {
	E_TianxiafirstGradereward_List.resize((int)msg.e_tianxiafirstgradereward_list_size() > (int)E_TianxiafirstGradereward_List.max_size() ? E_TianxiafirstGradereward_List.max_size() : msg.e_tianxiafirstgradereward_list_size());
	for(int32_t i = 0; i < (int32_t)E_TianxiafirstGradereward_List.size(); ++i) {
		const ::proto_ff::E_TianxiafirstGradereward & temp_e_tianxiafirstgradereward_list = msg.e_tianxiafirstgradereward_list(i);
		E_TianxiafirstGradereward_List[i].read_from_pbmsg(temp_e_tianxiafirstgradereward_list);
	}
}

E_TianxiafirstRankrewardRewardDesc_s::E_TianxiafirstRankrewardRewardDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_TianxiafirstRankrewardRewardDesc_s::CreateInit() {
	m_Num = (int32_t)0;
	m_ID = (int64_t)0;
	return 0;
}

int E_TianxiafirstRankrewardRewardDesc_s::ResumeInit() {
	return 0;
}

void E_TianxiafirstRankrewardRewardDesc_s::write_to_pbmsg(::proto_ff::E_TianxiafirstRankrewardRewardDesc & msg) const {
	msg.set_m_num((int32_t)m_Num);
	msg.set_m_id((int64_t)m_ID);
}

void E_TianxiafirstRankrewardRewardDesc_s::read_from_pbmsg(const ::proto_ff::E_TianxiafirstRankrewardRewardDesc & msg) {
	m_Num = msg.m_num();
	m_ID = msg.m_id();
}

E_TianxiafirstRankreward_s::E_TianxiafirstRankreward_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_TianxiafirstRankreward_s::CreateInit() {
	m_id = (int32_t)0;
	m_rank = (int32_t)0;
	return 0;
}

int E_TianxiafirstRankreward_s::ResumeInit() {
	return 0;
}

void E_TianxiafirstRankreward_s::write_to_pbmsg(::proto_ff::E_TianxiafirstRankreward & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_rank((int32_t)m_rank);
	for(int32_t i = 0; i < (int32_t)m_reward.size(); ++i) {
		::proto_ff::E_TianxiafirstRankrewardRewardDesc* temp_m_reward = msg.add_m_reward();
		m_reward[i].write_to_pbmsg(*temp_m_reward);
	}
}

void E_TianxiafirstRankreward_s::read_from_pbmsg(const ::proto_ff::E_TianxiafirstRankreward & msg) {
	m_id = msg.m_id();
	m_rank = msg.m_rank();
	m_reward.resize((int)msg.m_reward_size() > (int)m_reward.max_size() ? m_reward.max_size() : msg.m_reward_size());
	for(int32_t i = 0; i < (int32_t)m_reward.size(); ++i) {
		const ::proto_ff::E_TianxiafirstRankrewardRewardDesc & temp_m_reward = msg.m_reward(i);
		m_reward[i].read_from_pbmsg(temp_m_reward);
	}
}

Sheet_TianxiafirstRankreward_s::Sheet_TianxiafirstRankreward_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_TianxiafirstRankreward_s::CreateInit() {
	return 0;
}

int Sheet_TianxiafirstRankreward_s::ResumeInit() {
	return 0;
}

void Sheet_TianxiafirstRankreward_s::write_to_pbmsg(::proto_ff::Sheet_TianxiafirstRankreward & msg) const {
	for(int32_t i = 0; i < (int32_t)E_TianxiafirstRankreward_List.size(); ++i) {
		::proto_ff::E_TianxiafirstRankreward* temp_e_tianxiafirstrankreward_list = msg.add_e_tianxiafirstrankreward_list();
		E_TianxiafirstRankreward_List[i].write_to_pbmsg(*temp_e_tianxiafirstrankreward_list);
	}
}

void Sheet_TianxiafirstRankreward_s::read_from_pbmsg(const ::proto_ff::Sheet_TianxiafirstRankreward & msg) {
	E_TianxiafirstRankreward_List.resize((int)msg.e_tianxiafirstrankreward_list_size() > (int)E_TianxiafirstRankreward_List.max_size() ? E_TianxiafirstRankreward_List.max_size() : msg.e_tianxiafirstrankreward_list_size());
	for(int32_t i = 0; i < (int32_t)E_TianxiafirstRankreward_List.size(); ++i) {
		const ::proto_ff::E_TianxiafirstRankreward & temp_e_tianxiafirstrankreward_list = msg.e_tianxiafirstrankreward_list(i);
		E_TianxiafirstRankreward_List[i].read_from_pbmsg(temp_e_tianxiafirstrankreward_list);
	}
}

E_TianxiafirstWatchrewardRewardDesc_s::E_TianxiafirstWatchrewardRewardDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_TianxiafirstWatchrewardRewardDesc_s::CreateInit() {
	m_Num = (int32_t)0;
	m_ID = (int64_t)0;
	return 0;
}

int E_TianxiafirstWatchrewardRewardDesc_s::ResumeInit() {
	return 0;
}

void E_TianxiafirstWatchrewardRewardDesc_s::write_to_pbmsg(::proto_ff::E_TianxiafirstWatchrewardRewardDesc & msg) const {
	msg.set_m_num((int32_t)m_Num);
	msg.set_m_id((int64_t)m_ID);
}

void E_TianxiafirstWatchrewardRewardDesc_s::read_from_pbmsg(const ::proto_ff::E_TianxiafirstWatchrewardRewardDesc & msg) {
	m_Num = msg.m_num();
	m_ID = msg.m_id();
}

E_TianxiafirstWatchreward_s::E_TianxiafirstWatchreward_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_TianxiafirstWatchreward_s::CreateInit() {
	m_id = (int32_t)0;
	m_matchState = (int32_t)0;
	return 0;
}

int E_TianxiafirstWatchreward_s::ResumeInit() {
	return 0;
}

void E_TianxiafirstWatchreward_s::write_to_pbmsg(::proto_ff::E_TianxiafirstWatchreward & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_matchstate((int32_t)m_matchState);
	for(int32_t i = 0; i < (int32_t)m_reward.size(); ++i) {
		::proto_ff::E_TianxiafirstWatchrewardRewardDesc* temp_m_reward = msg.add_m_reward();
		m_reward[i].write_to_pbmsg(*temp_m_reward);
	}
}

void E_TianxiafirstWatchreward_s::read_from_pbmsg(const ::proto_ff::E_TianxiafirstWatchreward & msg) {
	m_id = msg.m_id();
	m_matchState = msg.m_matchstate();
	m_reward.resize((int)msg.m_reward_size() > (int)m_reward.max_size() ? m_reward.max_size() : msg.m_reward_size());
	for(int32_t i = 0; i < (int32_t)m_reward.size(); ++i) {
		const ::proto_ff::E_TianxiafirstWatchrewardRewardDesc & temp_m_reward = msg.m_reward(i);
		m_reward[i].read_from_pbmsg(temp_m_reward);
	}
}

Sheet_TianxiafirstWatchreward_s::Sheet_TianxiafirstWatchreward_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_TianxiafirstWatchreward_s::CreateInit() {
	return 0;
}

int Sheet_TianxiafirstWatchreward_s::ResumeInit() {
	return 0;
}

void Sheet_TianxiafirstWatchreward_s::write_to_pbmsg(::proto_ff::Sheet_TianxiafirstWatchreward & msg) const {
	for(int32_t i = 0; i < (int32_t)E_TianxiafirstWatchreward_List.size(); ++i) {
		::proto_ff::E_TianxiafirstWatchreward* temp_e_tianxiafirstwatchreward_list = msg.add_e_tianxiafirstwatchreward_list();
		E_TianxiafirstWatchreward_List[i].write_to_pbmsg(*temp_e_tianxiafirstwatchreward_list);
	}
}

void Sheet_TianxiafirstWatchreward_s::read_from_pbmsg(const ::proto_ff::Sheet_TianxiafirstWatchreward & msg) {
	E_TianxiafirstWatchreward_List.resize((int)msg.e_tianxiafirstwatchreward_list_size() > (int)E_TianxiafirstWatchreward_List.max_size() ? E_TianxiafirstWatchreward_List.max_size() : msg.e_tianxiafirstwatchreward_list_size());
	for(int32_t i = 0; i < (int32_t)E_TianxiafirstWatchreward_List.size(); ++i) {
		const ::proto_ff::E_TianxiafirstWatchreward & temp_e_tianxiafirstwatchreward_list = msg.e_tianxiafirstwatchreward_list(i);
		E_TianxiafirstWatchreward_List[i].read_from_pbmsg(temp_e_tianxiafirstwatchreward_list);
	}
}

E_TianxiafirstLuckyrewardRewardDesc_s::E_TianxiafirstLuckyrewardRewardDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_TianxiafirstLuckyrewardRewardDesc_s::CreateInit() {
	m_Num = (int32_t)0;
	m_ID = (int64_t)0;
	return 0;
}

int E_TianxiafirstLuckyrewardRewardDesc_s::ResumeInit() {
	return 0;
}

void E_TianxiafirstLuckyrewardRewardDesc_s::write_to_pbmsg(::proto_ff::E_TianxiafirstLuckyrewardRewardDesc & msg) const {
	msg.set_m_num((int32_t)m_Num);
	msg.set_m_id((int64_t)m_ID);
}

void E_TianxiafirstLuckyrewardRewardDesc_s::read_from_pbmsg(const ::proto_ff::E_TianxiafirstLuckyrewardRewardDesc & msg) {
	m_Num = msg.m_num();
	m_ID = msg.m_id();
}

E_TianxiafirstLuckyreward_s::E_TianxiafirstLuckyreward_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_TianxiafirstLuckyreward_s::CreateInit() {
	m_id = (int32_t)0;
	m_numMin = (int32_t)0;
	m_numMax = (int32_t)0;
	return 0;
}

int E_TianxiafirstLuckyreward_s::ResumeInit() {
	return 0;
}

void E_TianxiafirstLuckyreward_s::write_to_pbmsg(::proto_ff::E_TianxiafirstLuckyreward & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_nummin((int32_t)m_numMin);
	msg.set_m_nummax((int32_t)m_numMax);
	for(int32_t i = 0; i < (int32_t)m_reward.size(); ++i) {
		::proto_ff::E_TianxiafirstLuckyrewardRewardDesc* temp_m_reward = msg.add_m_reward();
		m_reward[i].write_to_pbmsg(*temp_m_reward);
	}
}

void E_TianxiafirstLuckyreward_s::read_from_pbmsg(const ::proto_ff::E_TianxiafirstLuckyreward & msg) {
	m_id = msg.m_id();
	m_numMin = msg.m_nummin();
	m_numMax = msg.m_nummax();
	m_reward.resize((int)msg.m_reward_size() > (int)m_reward.max_size() ? m_reward.max_size() : msg.m_reward_size());
	for(int32_t i = 0; i < (int32_t)m_reward.size(); ++i) {
		const ::proto_ff::E_TianxiafirstLuckyrewardRewardDesc & temp_m_reward = msg.m_reward(i);
		m_reward[i].read_from_pbmsg(temp_m_reward);
	}
}

Sheet_TianxiafirstLuckyreward_s::Sheet_TianxiafirstLuckyreward_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_TianxiafirstLuckyreward_s::CreateInit() {
	return 0;
}

int Sheet_TianxiafirstLuckyreward_s::ResumeInit() {
	return 0;
}

void Sheet_TianxiafirstLuckyreward_s::write_to_pbmsg(::proto_ff::Sheet_TianxiafirstLuckyreward & msg) const {
	for(int32_t i = 0; i < (int32_t)E_TianxiafirstLuckyreward_List.size(); ++i) {
		::proto_ff::E_TianxiafirstLuckyreward* temp_e_tianxiafirstluckyreward_list = msg.add_e_tianxiafirstluckyreward_list();
		E_TianxiafirstLuckyreward_List[i].write_to_pbmsg(*temp_e_tianxiafirstluckyreward_list);
	}
}

void Sheet_TianxiafirstLuckyreward_s::read_from_pbmsg(const ::proto_ff::Sheet_TianxiafirstLuckyreward & msg) {
	E_TianxiafirstLuckyreward_List.resize((int)msg.e_tianxiafirstluckyreward_list_size() > (int)E_TianxiafirstLuckyreward_List.max_size() ? E_TianxiafirstLuckyreward_List.max_size() : msg.e_tianxiafirstluckyreward_list_size());
	for(int32_t i = 0; i < (int32_t)E_TianxiafirstLuckyreward_List.size(); ++i) {
		const ::proto_ff::E_TianxiafirstLuckyreward & temp_e_tianxiafirstluckyreward_list = msg.e_tianxiafirstluckyreward_list(i);
		E_TianxiafirstLuckyreward_List[i].read_from_pbmsg(temp_e_tianxiafirstluckyreward_list);
	}
}

E_TianxiafirstMatchtimesrewardRewardDesc_s::E_TianxiafirstMatchtimesrewardRewardDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_TianxiafirstMatchtimesrewardRewardDesc_s::CreateInit() {
	m_Num = (int32_t)0;
	m_ID = (int64_t)0;
	return 0;
}

int E_TianxiafirstMatchtimesrewardRewardDesc_s::ResumeInit() {
	return 0;
}

void E_TianxiafirstMatchtimesrewardRewardDesc_s::write_to_pbmsg(::proto_ff::E_TianxiafirstMatchtimesrewardRewardDesc & msg) const {
	msg.set_m_num((int32_t)m_Num);
	msg.set_m_id((int64_t)m_ID);
}

void E_TianxiafirstMatchtimesrewardRewardDesc_s::read_from_pbmsg(const ::proto_ff::E_TianxiafirstMatchtimesrewardRewardDesc & msg) {
	m_Num = msg.m_num();
	m_ID = msg.m_id();
}

E_TianxiafirstMatchtimesreward_s::E_TianxiafirstMatchtimesreward_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_TianxiafirstMatchtimesreward_s::CreateInit() {
	m_id = (int32_t)0;
	m_matchTimes = (int32_t)0;
	return 0;
}

int E_TianxiafirstMatchtimesreward_s::ResumeInit() {
	return 0;
}

void E_TianxiafirstMatchtimesreward_s::write_to_pbmsg(::proto_ff::E_TianxiafirstMatchtimesreward & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_matchtimes((int32_t)m_matchTimes);
	for(int32_t i = 0; i < (int32_t)m_reward.size(); ++i) {
		::proto_ff::E_TianxiafirstMatchtimesrewardRewardDesc* temp_m_reward = msg.add_m_reward();
		m_reward[i].write_to_pbmsg(*temp_m_reward);
	}
}

void E_TianxiafirstMatchtimesreward_s::read_from_pbmsg(const ::proto_ff::E_TianxiafirstMatchtimesreward & msg) {
	m_id = msg.m_id();
	m_matchTimes = msg.m_matchtimes();
	m_reward.resize((int)msg.m_reward_size() > (int)m_reward.max_size() ? m_reward.max_size() : msg.m_reward_size());
	for(int32_t i = 0; i < (int32_t)m_reward.size(); ++i) {
		const ::proto_ff::E_TianxiafirstMatchtimesrewardRewardDesc & temp_m_reward = msg.m_reward(i);
		m_reward[i].read_from_pbmsg(temp_m_reward);
	}
}

Sheet_TianxiafirstMatchtimesreward_s::Sheet_TianxiafirstMatchtimesreward_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_TianxiafirstMatchtimesreward_s::CreateInit() {
	return 0;
}

int Sheet_TianxiafirstMatchtimesreward_s::ResumeInit() {
	return 0;
}

void Sheet_TianxiafirstMatchtimesreward_s::write_to_pbmsg(::proto_ff::Sheet_TianxiafirstMatchtimesreward & msg) const {
	for(int32_t i = 0; i < (int32_t)E_TianxiafirstMatchtimesreward_List.size(); ++i) {
		::proto_ff::E_TianxiafirstMatchtimesreward* temp_e_tianxiafirstmatchtimesreward_list = msg.add_e_tianxiafirstmatchtimesreward_list();
		E_TianxiafirstMatchtimesreward_List[i].write_to_pbmsg(*temp_e_tianxiafirstmatchtimesreward_list);
	}
}

void Sheet_TianxiafirstMatchtimesreward_s::read_from_pbmsg(const ::proto_ff::Sheet_TianxiafirstMatchtimesreward & msg) {
	E_TianxiafirstMatchtimesreward_List.resize((int)msg.e_tianxiafirstmatchtimesreward_list_size() > (int)E_TianxiafirstMatchtimesreward_List.max_size() ? E_TianxiafirstMatchtimesreward_List.max_size() : msg.e_tianxiafirstmatchtimesreward_list_size());
	for(int32_t i = 0; i < (int32_t)E_TianxiafirstMatchtimesreward_List.size(); ++i) {
		const ::proto_ff::E_TianxiafirstMatchtimesreward & temp_e_tianxiafirstmatchtimesreward_list = msg.e_tianxiafirstmatchtimesreward_list(i);
		E_TianxiafirstMatchtimesreward_List[i].read_from_pbmsg(temp_e_tianxiafirstmatchtimesreward_list);
	}
}

E_TianxiafirstMatchresultrewardRewardDesc_s::E_TianxiafirstMatchresultrewardRewardDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_TianxiafirstMatchresultrewardRewardDesc_s::CreateInit() {
	m_Num = (int32_t)0;
	m_ID = (int64_t)0;
	return 0;
}

int E_TianxiafirstMatchresultrewardRewardDesc_s::ResumeInit() {
	return 0;
}

void E_TianxiafirstMatchresultrewardRewardDesc_s::write_to_pbmsg(::proto_ff::E_TianxiafirstMatchresultrewardRewardDesc & msg) const {
	msg.set_m_num((int32_t)m_Num);
	msg.set_m_id((int64_t)m_ID);
}

void E_TianxiafirstMatchresultrewardRewardDesc_s::read_from_pbmsg(const ::proto_ff::E_TianxiafirstMatchresultrewardRewardDesc & msg) {
	m_Num = msg.m_num();
	m_ID = msg.m_id();
}

E_TianxiafirstMatchresultreward_s::E_TianxiafirstMatchresultreward_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_TianxiafirstMatchresultreward_s::CreateInit() {
	m_id = (int32_t)0;
	m_matchState = (int32_t)0;
	m_result = (int32_t)0;
	return 0;
}

int E_TianxiafirstMatchresultreward_s::ResumeInit() {
	return 0;
}

void E_TianxiafirstMatchresultreward_s::write_to_pbmsg(::proto_ff::E_TianxiafirstMatchresultreward & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_matchstate((int32_t)m_matchState);
	msg.set_m_result((int32_t)m_result);
	for(int32_t i = 0; i < (int32_t)m_reward.size(); ++i) {
		::proto_ff::E_TianxiafirstMatchresultrewardRewardDesc* temp_m_reward = msg.add_m_reward();
		m_reward[i].write_to_pbmsg(*temp_m_reward);
	}
}

void E_TianxiafirstMatchresultreward_s::read_from_pbmsg(const ::proto_ff::E_TianxiafirstMatchresultreward & msg) {
	m_id = msg.m_id();
	m_matchState = msg.m_matchstate();
	m_result = msg.m_result();
	m_reward.resize((int)msg.m_reward_size() > (int)m_reward.max_size() ? m_reward.max_size() : msg.m_reward_size());
	for(int32_t i = 0; i < (int32_t)m_reward.size(); ++i) {
		const ::proto_ff::E_TianxiafirstMatchresultrewardRewardDesc & temp_m_reward = msg.m_reward(i);
		m_reward[i].read_from_pbmsg(temp_m_reward);
	}
}

Sheet_TianxiafirstMatchresultreward_s::Sheet_TianxiafirstMatchresultreward_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_TianxiafirstMatchresultreward_s::CreateInit() {
	return 0;
}

int Sheet_TianxiafirstMatchresultreward_s::ResumeInit() {
	return 0;
}

void Sheet_TianxiafirstMatchresultreward_s::write_to_pbmsg(::proto_ff::Sheet_TianxiafirstMatchresultreward & msg) const {
	for(int32_t i = 0; i < (int32_t)E_TianxiafirstMatchresultreward_List.size(); ++i) {
		::proto_ff::E_TianxiafirstMatchresultreward* temp_e_tianxiafirstmatchresultreward_list = msg.add_e_tianxiafirstmatchresultreward_list();
		E_TianxiafirstMatchresultreward_List[i].write_to_pbmsg(*temp_e_tianxiafirstmatchresultreward_list);
	}
}

void Sheet_TianxiafirstMatchresultreward_s::read_from_pbmsg(const ::proto_ff::Sheet_TianxiafirstMatchresultreward & msg) {
	E_TianxiafirstMatchresultreward_List.resize((int)msg.e_tianxiafirstmatchresultreward_list_size() > (int)E_TianxiafirstMatchresultreward_List.max_size() ? E_TianxiafirstMatchresultreward_List.max_size() : msg.e_tianxiafirstmatchresultreward_list_size());
	for(int32_t i = 0; i < (int32_t)E_TianxiafirstMatchresultreward_List.size(); ++i) {
		const ::proto_ff::E_TianxiafirstMatchresultreward & temp_e_tianxiafirstmatchresultreward_list = msg.e_tianxiafirstmatchresultreward_list(i);
		E_TianxiafirstMatchresultreward_List[i].read_from_pbmsg(temp_e_tianxiafirstmatchresultreward_list);
	}
}

E_TianxiafirstExtraaddattrAttributeDesc_s::E_TianxiafirstExtraaddattrAttributeDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_TianxiafirstExtraaddattrAttributeDesc_s::CreateInit() {
	m_value = (int32_t)0;
	m_type = (int32_t)0;
	return 0;
}

int E_TianxiafirstExtraaddattrAttributeDesc_s::ResumeInit() {
	return 0;
}

void E_TianxiafirstExtraaddattrAttributeDesc_s::write_to_pbmsg(::proto_ff::E_TianxiafirstExtraaddattrAttributeDesc & msg) const {
	msg.set_m_value((int32_t)m_value);
	msg.set_m_type((int32_t)m_type);
}

void E_TianxiafirstExtraaddattrAttributeDesc_s::read_from_pbmsg(const ::proto_ff::E_TianxiafirstExtraaddattrAttributeDesc & msg) {
	m_value = msg.m_value();
	m_type = msg.m_type();
}

E_TianxiafirstExtraaddattr_s::E_TianxiafirstExtraaddattr_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_TianxiafirstExtraaddattr_s::CreateInit() {
	m_id = (int32_t)0;
	m_value = (int32_t)0;
	return 0;
}

int E_TianxiafirstExtraaddattr_s::ResumeInit() {
	return 0;
}

void E_TianxiafirstExtraaddattr_s::write_to_pbmsg(::proto_ff::E_TianxiafirstExtraaddattr & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_value((int32_t)m_value);
	for(int32_t i = 0; i < (int32_t)m_attribute.size(); ++i) {
		::proto_ff::E_TianxiafirstExtraaddattrAttributeDesc* temp_m_attribute = msg.add_m_attribute();
		m_attribute[i].write_to_pbmsg(*temp_m_attribute);
	}
}

void E_TianxiafirstExtraaddattr_s::read_from_pbmsg(const ::proto_ff::E_TianxiafirstExtraaddattr & msg) {
	m_id = msg.m_id();
	m_value = msg.m_value();
	m_attribute.resize((int)msg.m_attribute_size() > (int)m_attribute.max_size() ? m_attribute.max_size() : msg.m_attribute_size());
	for(int32_t i = 0; i < (int32_t)m_attribute.size(); ++i) {
		const ::proto_ff::E_TianxiafirstExtraaddattrAttributeDesc & temp_m_attribute = msg.m_attribute(i);
		m_attribute[i].read_from_pbmsg(temp_m_attribute);
	}
}

Sheet_TianxiafirstExtraaddattr_s::Sheet_TianxiafirstExtraaddattr_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_TianxiafirstExtraaddattr_s::CreateInit() {
	return 0;
}

int Sheet_TianxiafirstExtraaddattr_s::ResumeInit() {
	return 0;
}

void Sheet_TianxiafirstExtraaddattr_s::write_to_pbmsg(::proto_ff::Sheet_TianxiafirstExtraaddattr & msg) const {
	for(int32_t i = 0; i < (int32_t)E_TianxiafirstExtraaddattr_List.size(); ++i) {
		::proto_ff::E_TianxiafirstExtraaddattr* temp_e_tianxiafirstextraaddattr_list = msg.add_e_tianxiafirstextraaddattr_list();
		E_TianxiafirstExtraaddattr_List[i].write_to_pbmsg(*temp_e_tianxiafirstextraaddattr_list);
	}
}

void Sheet_TianxiafirstExtraaddattr_s::read_from_pbmsg(const ::proto_ff::Sheet_TianxiafirstExtraaddattr & msg) {
	E_TianxiafirstExtraaddattr_List.resize((int)msg.e_tianxiafirstextraaddattr_list_size() > (int)E_TianxiafirstExtraaddattr_List.max_size() ? E_TianxiafirstExtraaddattr_List.max_size() : msg.e_tianxiafirstextraaddattr_list_size());
	for(int32_t i = 0; i < (int32_t)E_TianxiafirstExtraaddattr_List.size(); ++i) {
		const ::proto_ff::E_TianxiafirstExtraaddattr & temp_e_tianxiafirstextraaddattr_list = msg.e_tianxiafirstextraaddattr_list(i);
		E_TianxiafirstExtraaddattr_List[i].read_from_pbmsg(temp_e_tianxiafirstextraaddattr_list);
	}
}

E_TianxiafirstFirstaddattrAttributeDesc_s::E_TianxiafirstFirstaddattrAttributeDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_TianxiafirstFirstaddattrAttributeDesc_s::CreateInit() {
	m_value = (int32_t)0;
	m_type = (int32_t)0;
	return 0;
}

int E_TianxiafirstFirstaddattrAttributeDesc_s::ResumeInit() {
	return 0;
}

void E_TianxiafirstFirstaddattrAttributeDesc_s::write_to_pbmsg(::proto_ff::E_TianxiafirstFirstaddattrAttributeDesc & msg) const {
	msg.set_m_value((int32_t)m_value);
	msg.set_m_type((int32_t)m_type);
}

void E_TianxiafirstFirstaddattrAttributeDesc_s::read_from_pbmsg(const ::proto_ff::E_TianxiafirstFirstaddattrAttributeDesc & msg) {
	m_value = msg.m_value();
	m_type = msg.m_type();
}

E_TianxiafirstFirstaddattr_s::E_TianxiafirstFirstaddattr_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_TianxiafirstFirstaddattr_s::CreateInit() {
	m_id = (int32_t)0;
	m_value = (int32_t)0;
	return 0;
}

int E_TianxiafirstFirstaddattr_s::ResumeInit() {
	return 0;
}

void E_TianxiafirstFirstaddattr_s::write_to_pbmsg(::proto_ff::E_TianxiafirstFirstaddattr & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_value((int32_t)m_value);
	for(int32_t i = 0; i < (int32_t)m_attribute.size(); ++i) {
		::proto_ff::E_TianxiafirstFirstaddattrAttributeDesc* temp_m_attribute = msg.add_m_attribute();
		m_attribute[i].write_to_pbmsg(*temp_m_attribute);
	}
}

void E_TianxiafirstFirstaddattr_s::read_from_pbmsg(const ::proto_ff::E_TianxiafirstFirstaddattr & msg) {
	m_id = msg.m_id();
	m_value = msg.m_value();
	m_attribute.resize((int)msg.m_attribute_size() > (int)m_attribute.max_size() ? m_attribute.max_size() : msg.m_attribute_size());
	for(int32_t i = 0; i < (int32_t)m_attribute.size(); ++i) {
		const ::proto_ff::E_TianxiafirstFirstaddattrAttributeDesc & temp_m_attribute = msg.m_attribute(i);
		m_attribute[i].read_from_pbmsg(temp_m_attribute);
	}
}

Sheet_TianxiafirstFirstaddattr_s::Sheet_TianxiafirstFirstaddattr_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_TianxiafirstFirstaddattr_s::CreateInit() {
	return 0;
}

int Sheet_TianxiafirstFirstaddattr_s::ResumeInit() {
	return 0;
}

void Sheet_TianxiafirstFirstaddattr_s::write_to_pbmsg(::proto_ff::Sheet_TianxiafirstFirstaddattr & msg) const {
	for(int32_t i = 0; i < (int32_t)E_TianxiafirstFirstaddattr_List.size(); ++i) {
		::proto_ff::E_TianxiafirstFirstaddattr* temp_e_tianxiafirstfirstaddattr_list = msg.add_e_tianxiafirstfirstaddattr_list();
		E_TianxiafirstFirstaddattr_List[i].write_to_pbmsg(*temp_e_tianxiafirstfirstaddattr_list);
	}
}

void Sheet_TianxiafirstFirstaddattr_s::read_from_pbmsg(const ::proto_ff::Sheet_TianxiafirstFirstaddattr & msg) {
	E_TianxiafirstFirstaddattr_List.resize((int)msg.e_tianxiafirstfirstaddattr_list_size() > (int)E_TianxiafirstFirstaddattr_List.max_size() ? E_TianxiafirstFirstaddattr_List.max_size() : msg.e_tianxiafirstfirstaddattr_list_size());
	for(int32_t i = 0; i < (int32_t)E_TianxiafirstFirstaddattr_List.size(); ++i) {
		const ::proto_ff::E_TianxiafirstFirstaddattr & temp_e_tianxiafirstfirstaddattr_list = msg.e_tianxiafirstfirstaddattr_list(i);
		E_TianxiafirstFirstaddattr_List[i].read_from_pbmsg(temp_e_tianxiafirstfirstaddattr_list);
	}
}

E_TianxiafirstShop_s::E_TianxiafirstShop_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_TianxiafirstShop_s::CreateInit() {
	m_id = (int32_t)0;
	m_itemId = (int32_t)0;
	m_costItem = (int32_t)0;
	m_costNum = (int32_t)0;
	m_count = (int32_t)0;
	m_limitType = (int32_t)0;
	m_condition = (int32_t)0;
	m_conditionParam = (int32_t)0;
	return 0;
}

int E_TianxiafirstShop_s::ResumeInit() {
	return 0;
}

void E_TianxiafirstShop_s::write_to_pbmsg(::proto_ff::E_TianxiafirstShop & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_itemid((int32_t)m_itemId);
	msg.set_m_costitem((int32_t)m_costItem);
	msg.set_m_costnum((int32_t)m_costNum);
	msg.set_m_count((int32_t)m_count);
	msg.set_m_limittype((int32_t)m_limitType);
	msg.set_m_condition((int32_t)m_condition);
	msg.set_m_conditionparam((int32_t)m_conditionParam);
}

void E_TianxiafirstShop_s::read_from_pbmsg(const ::proto_ff::E_TianxiafirstShop & msg) {
	m_id = msg.m_id();
	m_itemId = msg.m_itemid();
	m_costItem = msg.m_costitem();
	m_costNum = msg.m_costnum();
	m_count = msg.m_count();
	m_limitType = msg.m_limittype();
	m_condition = msg.m_condition();
	m_conditionParam = msg.m_conditionparam();
}

Sheet_TianxiafirstShop_s::Sheet_TianxiafirstShop_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_TianxiafirstShop_s::CreateInit() {
	return 0;
}

int Sheet_TianxiafirstShop_s::ResumeInit() {
	return 0;
}

void Sheet_TianxiafirstShop_s::write_to_pbmsg(::proto_ff::Sheet_TianxiafirstShop & msg) const {
	for(int32_t i = 0; i < (int32_t)E_TianxiafirstShop_List.size(); ++i) {
		::proto_ff::E_TianxiafirstShop* temp_e_tianxiafirstshop_list = msg.add_e_tianxiafirstshop_list();
		E_TianxiafirstShop_List[i].write_to_pbmsg(*temp_e_tianxiafirstshop_list);
	}
}

void Sheet_TianxiafirstShop_s::read_from_pbmsg(const ::proto_ff::Sheet_TianxiafirstShop & msg) {
	E_TianxiafirstShop_List.resize((int)msg.e_tianxiafirstshop_list_size() > (int)E_TianxiafirstShop_List.max_size() ? E_TianxiafirstShop_List.max_size() : msg.e_tianxiafirstshop_list_size());
	for(int32_t i = 0; i < (int32_t)E_TianxiafirstShop_List.size(); ++i) {
		const ::proto_ff::E_TianxiafirstShop & temp_e_tianxiafirstshop_list = msg.e_tianxiafirstshop_list(i);
		E_TianxiafirstShop_List[i].read_from_pbmsg(temp_e_tianxiafirstshop_list);
	}
}

E_TianxiafirstDanmaku_s::E_TianxiafirstDanmaku_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_TianxiafirstDanmaku_s::CreateInit() {
	m_id = (int32_t)0;
	m_type = (int32_t)0;
	return 0;
}

int E_TianxiafirstDanmaku_s::ResumeInit() {
	return 0;
}

void E_TianxiafirstDanmaku_s::write_to_pbmsg(::proto_ff::E_TianxiafirstDanmaku & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_type((int32_t)m_type);
	msg.set_m_danmaku(m_danmaku.data());
}

void E_TianxiafirstDanmaku_s::read_from_pbmsg(const ::proto_ff::E_TianxiafirstDanmaku & msg) {
	m_id = msg.m_id();
	m_type = msg.m_type();
	m_danmaku = msg.m_danmaku();
}

Sheet_TianxiafirstDanmaku_s::Sheet_TianxiafirstDanmaku_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_TianxiafirstDanmaku_s::CreateInit() {
	return 0;
}

int Sheet_TianxiafirstDanmaku_s::ResumeInit() {
	return 0;
}

void Sheet_TianxiafirstDanmaku_s::write_to_pbmsg(::proto_ff::Sheet_TianxiafirstDanmaku & msg) const {
	for(int32_t i = 0; i < (int32_t)E_TianxiafirstDanmaku_List.size(); ++i) {
		::proto_ff::E_TianxiafirstDanmaku* temp_e_tianxiafirstdanmaku_list = msg.add_e_tianxiafirstdanmaku_list();
		E_TianxiafirstDanmaku_List[i].write_to_pbmsg(*temp_e_tianxiafirstdanmaku_list);
	}
}

void Sheet_TianxiafirstDanmaku_s::read_from_pbmsg(const ::proto_ff::Sheet_TianxiafirstDanmaku & msg) {
	E_TianxiafirstDanmaku_List.resize((int)msg.e_tianxiafirstdanmaku_list_size() > (int)E_TianxiafirstDanmaku_List.max_size() ? E_TianxiafirstDanmaku_List.max_size() : msg.e_tianxiafirstdanmaku_list_size());
	for(int32_t i = 0; i < (int32_t)E_TianxiafirstDanmaku_List.size(); ++i) {
		const ::proto_ff::E_TianxiafirstDanmaku & temp_e_tianxiafirstdanmaku_list = msg.e_tianxiafirstdanmaku_list(i);
		E_TianxiafirstDanmaku_List[i].read_from_pbmsg(temp_e_tianxiafirstdanmaku_list);
	}
}

}
