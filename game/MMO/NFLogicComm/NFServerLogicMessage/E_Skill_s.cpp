#include "E_Skill_s.h"

namespace proto_ff_s {

E_SkillBuff_s::E_SkillBuff_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_SkillBuff_s::CreateInit() {
	m_buffID = (int64_t)0;
	m_showTpye = (int32_t)0;
	m_startProbability = (int32_t)0;
	m_Probability_up = (int32_t)0;
	m_startType = (int32_t)0;
	m_endType = (int32_t)0;
	m_endTypeA = (int32_t)0;
	m_endTypeB = (int32_t)0;
	m_group = (int32_t)0;
	m_buffCd = (int32_t)0;
	m_effect_Time = (int32_t)0;
	m_effect_Type = (int32_t)0;
	m_effect_up = (int32_t)0;
	return 0;
}

int E_SkillBuff_s::ResumeInit() {
	return 0;
}

void E_SkillBuff_s::write_to_pbmsg(::proto_ff::E_SkillBuff & msg) const {
	msg.set_m_buffid((int64_t)m_buffID);
	msg.set_m_buffname(m_buffName.data());
	msg.set_m_bufficon(m_buffIcon.data());
	msg.set_m_effectresources(m_effectResources.data());
	msg.set_m_showtpye((int32_t)m_showTpye);
	msg.set_m_startprobability((int32_t)m_startProbability);
	msg.set_m_probability_up((int32_t)m_Probability_up);
	msg.set_m_starttype((int32_t)m_startType);
	msg.set_m_starttypevalue(m_startTypeValue.data());
	msg.set_m_endtype((int32_t)m_endType);
	msg.set_m_endtypevalue(m_endTypeValue.data());
	msg.set_m_endtypea((int32_t)m_endTypeA);
	msg.set_m_endtypevaluea(m_endTypeValueA.data());
	msg.set_m_endtypeb((int32_t)m_endTypeB);
	msg.set_m_endtypevalueb(m_endTypeValueB.data());
	msg.set_m_group((int32_t)m_group);
	msg.set_m_buffrule(m_buffRule.data());
	msg.set_m_immune(m_immune.data());
	msg.set_m_dispel(m_dispel.data());
	msg.set_m_buffcd((int32_t)m_buffCd);
	msg.set_m_effect_time((int32_t)m_effect_Time);
	msg.set_m_effect_type((int32_t)m_effect_Type);
	msg.set_m_effect_param(m_effect_Param.data());
	msg.set_m_effect_up((int32_t)m_effect_up);
}

void E_SkillBuff_s::read_from_pbmsg(const ::proto_ff::E_SkillBuff & msg) {
	m_buffID = msg.m_buffid();
	m_buffName = msg.m_buffname();
	m_buffIcon = msg.m_bufficon();
	m_effectResources = msg.m_effectresources();
	m_showTpye = msg.m_showtpye();
	m_startProbability = msg.m_startprobability();
	m_Probability_up = msg.m_probability_up();
	m_startType = msg.m_starttype();
	m_startTypeValue = msg.m_starttypevalue();
	m_endType = msg.m_endtype();
	m_endTypeValue = msg.m_endtypevalue();
	m_endTypeA = msg.m_endtypea();
	m_endTypeValueA = msg.m_endtypevaluea();
	m_endTypeB = msg.m_endtypeb();
	m_endTypeValueB = msg.m_endtypevalueb();
	m_group = msg.m_group();
	m_buffRule = msg.m_buffrule();
	m_immune = msg.m_immune();
	m_dispel = msg.m_dispel();
	m_buffCd = msg.m_buffcd();
	m_effect_Time = msg.m_effect_time();
	m_effect_Type = msg.m_effect_type();
	m_effect_Param = msg.m_effect_param();
	m_effect_up = msg.m_effect_up();
}

Sheet_SkillBuff_s::Sheet_SkillBuff_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_SkillBuff_s::CreateInit() {
	return 0;
}

int Sheet_SkillBuff_s::ResumeInit() {
	return 0;
}

void Sheet_SkillBuff_s::write_to_pbmsg(::proto_ff::Sheet_SkillBuff & msg) const {
	for(int32_t i = 0; i < (int32_t)E_SkillBuff_List.size(); ++i) {
		::proto_ff::E_SkillBuff* temp_e_skillbuff_list = msg.add_e_skillbuff_list();
		E_SkillBuff_List[i].write_to_pbmsg(*temp_e_skillbuff_list);
	}
}

void Sheet_SkillBuff_s::read_from_pbmsg(const ::proto_ff::Sheet_SkillBuff & msg) {
	E_SkillBuff_List.resize((int)msg.e_skillbuff_list_size() > (int)E_SkillBuff_List.max_size() ? E_SkillBuff_List.max_size() : msg.e_skillbuff_list_size());
	for(int32_t i = 0; i < (int32_t)E_SkillBuff_List.size(); ++i) {
		const ::proto_ff::E_SkillBuff & temp_e_skillbuff_list = msg.e_skillbuff_list(i);
		E_SkillBuff_List[i].read_from_pbmsg(temp_e_skillbuff_list);
	}
}

E_SkillBuffup_s::E_SkillBuffup_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_SkillBuffup_s::CreateInit() {
	m_id = (int32_t)0;
	m_AddStartProbability = (int32_t)0;
	m_attributeId = (int32_t)0;
	m_parama = (int32_t)0;
	return 0;
}

int E_SkillBuffup_s::ResumeInit() {
	return 0;
}

void E_SkillBuffup_s::write_to_pbmsg(::proto_ff::E_SkillBuffup & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_addstartprobability((int32_t)m_AddStartProbability);
	msg.set_m_attributeid((int32_t)m_attributeId);
	msg.set_m_parama((int32_t)m_parama);
}

void E_SkillBuffup_s::read_from_pbmsg(const ::proto_ff::E_SkillBuffup & msg) {
	m_id = msg.m_id();
	m_AddStartProbability = msg.m_addstartprobability();
	m_attributeId = msg.m_attributeid();
	m_parama = msg.m_parama();
}

Sheet_SkillBuffup_s::Sheet_SkillBuffup_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_SkillBuffup_s::CreateInit() {
	return 0;
}

int Sheet_SkillBuffup_s::ResumeInit() {
	return 0;
}

void Sheet_SkillBuffup_s::write_to_pbmsg(::proto_ff::Sheet_SkillBuffup & msg) const {
	for(int32_t i = 0; i < (int32_t)E_SkillBuffup_List.size(); ++i) {
		::proto_ff::E_SkillBuffup* temp_e_skillbuffup_list = msg.add_e_skillbuffup_list();
		E_SkillBuffup_List[i].write_to_pbmsg(*temp_e_skillbuffup_list);
	}
}

void Sheet_SkillBuffup_s::read_from_pbmsg(const ::proto_ff::Sheet_SkillBuffup & msg) {
	E_SkillBuffup_List.resize((int)msg.e_skillbuffup_list_size() > (int)E_SkillBuffup_List.max_size() ? E_SkillBuffup_List.max_size() : msg.e_skillbuffup_list_size());
	for(int32_t i = 0; i < (int32_t)E_SkillBuffup_List.size(); ++i) {
		const ::proto_ff::E_SkillBuffup & temp_e_skillbuffup_list = msg.e_skillbuffup_list(i);
		E_SkillBuffup_List[i].read_from_pbmsg(temp_e_skillbuffup_list);
	}
}

E_SkillSkillBuffDesc_s::E_SkillSkillBuffDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_SkillSkillBuffDesc_s::CreateInit() {
	m_Target = (int32_t)0;
	m_Point = (int32_t)0;
	m_ID = (int64_t)0;
	return 0;
}

int E_SkillSkillBuffDesc_s::ResumeInit() {
	return 0;
}

void E_SkillSkillBuffDesc_s::write_to_pbmsg(::proto_ff::E_SkillSkillBuffDesc & msg) const {
	msg.set_m_target((int32_t)m_Target);
	msg.set_m_point((int32_t)m_Point);
	msg.set_m_id((int64_t)m_ID);
}

void E_SkillSkillBuffDesc_s::read_from_pbmsg(const ::proto_ff::E_SkillSkillBuffDesc & msg) {
	m_Target = msg.m_target();
	m_Point = msg.m_point();
	m_ID = msg.m_id();
}

E_SkillSkillAwakebuffDesc_s::E_SkillSkillAwakebuffDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_SkillSkillAwakebuffDesc_s::CreateInit() {
	m_ID = (int64_t)0;
	return 0;
}

int E_SkillSkillAwakebuffDesc_s::ResumeInit() {
	return 0;
}

void E_SkillSkillAwakebuffDesc_s::write_to_pbmsg(::proto_ff::E_SkillSkillAwakebuffDesc & msg) const {
	msg.set_m_id((int64_t)m_ID);
}

void E_SkillSkillAwakebuffDesc_s::read_from_pbmsg(const ::proto_ff::E_SkillSkillAwakebuffDesc & msg) {
	m_ID = msg.m_id();
}

E_SkillSkillAdvancetype1buffDesc_s::E_SkillSkillAdvancetype1buffDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_SkillSkillAdvancetype1buffDesc_s::CreateInit() {
	m_ID = (int64_t)0;
	return 0;
}

int E_SkillSkillAdvancetype1buffDesc_s::ResumeInit() {
	return 0;
}

void E_SkillSkillAdvancetype1buffDesc_s::write_to_pbmsg(::proto_ff::E_SkillSkillAdvancetype1buffDesc & msg) const {
	msg.set_m_id((int64_t)m_ID);
}

void E_SkillSkillAdvancetype1buffDesc_s::read_from_pbmsg(const ::proto_ff::E_SkillSkillAdvancetype1buffDesc & msg) {
	m_ID = msg.m_id();
}

E_SkillSkillAdvancetype2buffDesc_s::E_SkillSkillAdvancetype2buffDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_SkillSkillAdvancetype2buffDesc_s::CreateInit() {
	m_ID = (int64_t)0;
	return 0;
}

int E_SkillSkillAdvancetype2buffDesc_s::ResumeInit() {
	return 0;
}

void E_SkillSkillAdvancetype2buffDesc_s::write_to_pbmsg(::proto_ff::E_SkillSkillAdvancetype2buffDesc & msg) const {
	msg.set_m_id((int64_t)m_ID);
}

void E_SkillSkillAdvancetype2buffDesc_s::read_from_pbmsg(const ::proto_ff::E_SkillSkillAdvancetype2buffDesc & msg) {
	m_ID = msg.m_id();
}

E_SkillSkillAdvancetype3buffDesc_s::E_SkillSkillAdvancetype3buffDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_SkillSkillAdvancetype3buffDesc_s::CreateInit() {
	m_ID = (int64_t)0;
	return 0;
}

int E_SkillSkillAdvancetype3buffDesc_s::ResumeInit() {
	return 0;
}

void E_SkillSkillAdvancetype3buffDesc_s::write_to_pbmsg(::proto_ff::E_SkillSkillAdvancetype3buffDesc & msg) const {
	msg.set_m_id((int64_t)m_ID);
}

void E_SkillSkillAdvancetype3buffDesc_s::read_from_pbmsg(const ::proto_ff::E_SkillSkillAdvancetype3buffDesc & msg) {
	m_ID = msg.m_id();
}

E_SkillSkill_s::E_SkillSkill_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_SkillSkill_s::CreateInit() {
	m_skillID = (int64_t)0;
	m_skillType = (int32_t)0;
	m_group = (int32_t)0;
	m_position = (int32_t)0;
	m_displaceTime = (int32_t)0;
	m_displaceSign = (int32_t)0;
	m_targetDisplaceTime = (int32_t)0;
	m_targetDisplaceSign = (int32_t)0;
	m_breakType = (int32_t)0;
	m_cdSkill = (int32_t)0;
	m_Relation = (int64_t)0;
	m_type = (int32_t)0;
	m_cd = (int32_t)0;
	m_noLock = (int32_t)0;
	m_priority = (int32_t)0;
	m_fighting = (int32_t)0;
	m_fightingParama = (float)0;
	m_releaseType = (int32_t)0;
	m_processTypes = (int32_t)0;
	m_flySpeed = (int32_t)0;
	m_actTime = (int32_t)0;
	m_readyTime = (int32_t)0;
	m_readyTimeEx = (int32_t)0;
	m_attackTime = (int32_t)0;
	m_attackDistance = (int32_t)0;
	m_rangeType = (int32_t)0;
	m_rangeTypeEx = (int32_t)0;
	m_warn = (int32_t)0;
	m_dazeTime = (int32_t)0;
	m_warnTime = (int32_t)0;
	m_attackMinDistance = (int32_t)0;
	m_goalMaxNum = (int32_t)0;
	m_goalMaxNumMonster = (int32_t)0;
	m_damageType = (int32_t)0;
	m_damageRate = (int32_t)0;
	m_awakeDamageRate = (int32_t)0;
	m_advanceType1DamageRate = (int32_t)0;
	m_advanceType2DamageRate = (int32_t)0;
	m_advanceType3DamageRate = (int32_t)0;
	m_damageValue = (int32_t)0;
	m_damageParama = (float)0;
	m_damageRateParama = (float)0;
	m_addhitrate = (int32_t)0;
	m_attackBuff = (int64_t)0;
	m_behitBuff = (int64_t)0;
	return 0;
}

int E_SkillSkill_s::ResumeInit() {
	return 0;
}

void E_SkillSkill_s::write_to_pbmsg(::proto_ff::E_SkillSkill & msg) const {
	msg.set_m_skillid((int64_t)m_skillID);
	msg.set_m_name(m_name.data());
	msg.set_m_skilltype((int32_t)m_skillType);
	msg.set_m_group((int32_t)m_group);
	msg.set_m_position((int32_t)m_position);
	msg.set_m_displacetime((int32_t)m_displaceTime);
	msg.set_m_displacesign((int32_t)m_displaceSign);
	msg.set_m_displacespeed(m_displaceSpeed.data());
	msg.set_m_distimes(m_disTimes.data());
	msg.set_m_targetdisplacetime((int32_t)m_targetDisplaceTime);
	msg.set_m_targetdisplacesign((int32_t)m_targetDisplaceSign);
	msg.set_m_targetdisplacespeed(m_targetDisplaceSpeed.data());
	msg.set_m_targetdistimes(m_targetDisTimes.data());
	msg.set_m_breaktype((int32_t)m_breakType);
	msg.set_m_cdskill((int32_t)m_cdSkill);
	msg.set_m_relation((int64_t)m_Relation);
	msg.set_m_unlockcondition(m_unlockCondition.data());
	msg.set_m_type((int32_t)m_type);
	msg.set_m_cd((int32_t)m_cd);
	msg.set_m_nolock((int32_t)m_noLock);
	msg.set_m_priority((int32_t)m_priority);
	msg.set_m_fighting((int32_t)m_fighting);
	msg.set_m_fightingparama((float)m_fightingParama);
	msg.set_m_releasetype((int32_t)m_releaseType);
	msg.set_m_processtypes((int32_t)m_processTypes);
	msg.set_m_releasetime(m_releaseTime.data());
	msg.set_m_flyspeed((int32_t)m_flySpeed);
	msg.set_m_acttime((int32_t)m_actTime);
	msg.set_m_readytime((int32_t)m_readyTime);
	msg.set_m_readytimeex((int32_t)m_readyTimeEx);
	msg.set_m_attacktime((int32_t)m_attackTime);
	msg.set_m_damagetime(m_damageTime.data());
	msg.set_m_damagetimeex(m_damageTimeEx.data());
	msg.set_m_attackdistance((int32_t)m_attackDistance);
	msg.set_m_rangetype((int32_t)m_rangeType);
	msg.set_m_rangetypevalue(m_rangeTypeValue.data());
	msg.set_m_rangetypeex((int32_t)m_rangeTypeEx);
	msg.set_m_rangetypevalueex(m_rangeTypeValueEx.data());
	msg.set_m_warn((int32_t)m_warn);
	msg.set_m_dazetime((int32_t)m_dazeTime);
	msg.set_m_warntime((int32_t)m_warnTime);
	msg.set_m_infomationid(m_infomationId.data());
	msg.set_m_attackmindistance((int32_t)m_attackMinDistance);
	msg.set_m_goalmaxnum((int32_t)m_goalMaxNum);
	msg.set_m_goalmaxnummonster((int32_t)m_goalMaxNumMonster);
	msg.set_m_damagetype((int32_t)m_damageType);
	msg.set_m_damagerate((int32_t)m_damageRate);
	msg.set_m_awakedamagerate((int32_t)m_awakeDamageRate);
	msg.set_m_advancetype1damagerate((int32_t)m_advanceType1DamageRate);
	msg.set_m_advancetype2damagerate((int32_t)m_advanceType2DamageRate);
	msg.set_m_advancetype3damagerate((int32_t)m_advanceType3DamageRate);
	msg.set_m_damagevalue((int32_t)m_damageValue);
	msg.set_m_damageparama((float)m_damageParama);
	msg.set_m_damagerateparama((float)m_damageRateParama);
	msg.set_m_addhitrate((int32_t)m_addhitrate);
	msg.set_m_attackbuff((int64_t)m_attackBuff);
	msg.set_m_behitbuff((int64_t)m_behitBuff);
	for(int32_t i = 0; i < (int32_t)m_buff.size(); ++i) {
		::proto_ff::E_SkillSkillBuffDesc* temp_m_buff = msg.add_m_buff();
		m_buff[i].write_to_pbmsg(*temp_m_buff);
	}
	for(int32_t i = 0; i < (int32_t)m_awakebuff.size(); ++i) {
		::proto_ff::E_SkillSkillAwakebuffDesc* temp_m_awakebuff = msg.add_m_awakebuff();
		m_awakebuff[i].write_to_pbmsg(*temp_m_awakebuff);
	}
	for(int32_t i = 0; i < (int32_t)m_advanceType1buff.size(); ++i) {
		::proto_ff::E_SkillSkillAdvancetype1buffDesc* temp_m_advancetype1buff = msg.add_m_advancetype1buff();
		m_advanceType1buff[i].write_to_pbmsg(*temp_m_advancetype1buff);
	}
	for(int32_t i = 0; i < (int32_t)m_advanceType2buff.size(); ++i) {
		::proto_ff::E_SkillSkillAdvancetype2buffDesc* temp_m_advancetype2buff = msg.add_m_advancetype2buff();
		m_advanceType2buff[i].write_to_pbmsg(*temp_m_advancetype2buff);
	}
	for(int32_t i = 0; i < (int32_t)m_advanceType3buff.size(); ++i) {
		::proto_ff::E_SkillSkillAdvancetype3buffDesc* temp_m_advancetype3buff = msg.add_m_advancetype3buff();
		m_advanceType3buff[i].write_to_pbmsg(*temp_m_advancetype3buff);
	}
}

void E_SkillSkill_s::read_from_pbmsg(const ::proto_ff::E_SkillSkill & msg) {
	m_skillID = msg.m_skillid();
	m_name = msg.m_name();
	m_skillType = msg.m_skilltype();
	m_group = msg.m_group();
	m_position = msg.m_position();
	m_displaceTime = msg.m_displacetime();
	m_displaceSign = msg.m_displacesign();
	m_displaceSpeed = msg.m_displacespeed();
	m_disTimes = msg.m_distimes();
	m_targetDisplaceTime = msg.m_targetdisplacetime();
	m_targetDisplaceSign = msg.m_targetdisplacesign();
	m_targetDisplaceSpeed = msg.m_targetdisplacespeed();
	m_targetDisTimes = msg.m_targetdistimes();
	m_breakType = msg.m_breaktype();
	m_cdSkill = msg.m_cdskill();
	m_Relation = msg.m_relation();
	m_unlockCondition = msg.m_unlockcondition();
	m_type = msg.m_type();
	m_cd = msg.m_cd();
	m_noLock = msg.m_nolock();
	m_priority = msg.m_priority();
	m_fighting = msg.m_fighting();
	m_fightingParama = msg.m_fightingparama();
	m_releaseType = msg.m_releasetype();
	m_processTypes = msg.m_processtypes();
	m_releaseTime = msg.m_releasetime();
	m_flySpeed = msg.m_flyspeed();
	m_actTime = msg.m_acttime();
	m_readyTime = msg.m_readytime();
	m_readyTimeEx = msg.m_readytimeex();
	m_attackTime = msg.m_attacktime();
	m_damageTime = msg.m_damagetime();
	m_damageTimeEx = msg.m_damagetimeex();
	m_attackDistance = msg.m_attackdistance();
	m_rangeType = msg.m_rangetype();
	m_rangeTypeValue = msg.m_rangetypevalue();
	m_rangeTypeEx = msg.m_rangetypeex();
	m_rangeTypeValueEx = msg.m_rangetypevalueex();
	m_warn = msg.m_warn();
	m_dazeTime = msg.m_dazetime();
	m_warnTime = msg.m_warntime();
	m_infomationId = msg.m_infomationid();
	m_attackMinDistance = msg.m_attackmindistance();
	m_goalMaxNum = msg.m_goalmaxnum();
	m_goalMaxNumMonster = msg.m_goalmaxnummonster();
	m_damageType = msg.m_damagetype();
	m_damageRate = msg.m_damagerate();
	m_awakeDamageRate = msg.m_awakedamagerate();
	m_advanceType1DamageRate = msg.m_advancetype1damagerate();
	m_advanceType2DamageRate = msg.m_advancetype2damagerate();
	m_advanceType3DamageRate = msg.m_advancetype3damagerate();
	m_damageValue = msg.m_damagevalue();
	m_damageParama = msg.m_damageparama();
	m_damageRateParama = msg.m_damagerateparama();
	m_addhitrate = msg.m_addhitrate();
	m_attackBuff = msg.m_attackbuff();
	m_behitBuff = msg.m_behitbuff();
	m_buff.resize((int)msg.m_buff_size() > (int)m_buff.max_size() ? m_buff.max_size() : msg.m_buff_size());
	for(int32_t i = 0; i < (int32_t)m_buff.size(); ++i) {
		const ::proto_ff::E_SkillSkillBuffDesc & temp_m_buff = msg.m_buff(i);
		m_buff[i].read_from_pbmsg(temp_m_buff);
	}
	m_awakebuff.resize((int)msg.m_awakebuff_size() > (int)m_awakebuff.max_size() ? m_awakebuff.max_size() : msg.m_awakebuff_size());
	for(int32_t i = 0; i < (int32_t)m_awakebuff.size(); ++i) {
		const ::proto_ff::E_SkillSkillAwakebuffDesc & temp_m_awakebuff = msg.m_awakebuff(i);
		m_awakebuff[i].read_from_pbmsg(temp_m_awakebuff);
	}
	m_advanceType1buff.resize((int)msg.m_advancetype1buff_size() > (int)m_advanceType1buff.max_size() ? m_advanceType1buff.max_size() : msg.m_advancetype1buff_size());
	for(int32_t i = 0; i < (int32_t)m_advanceType1buff.size(); ++i) {
		const ::proto_ff::E_SkillSkillAdvancetype1buffDesc & temp_m_advancetype1buff = msg.m_advancetype1buff(i);
		m_advanceType1buff[i].read_from_pbmsg(temp_m_advancetype1buff);
	}
	m_advanceType2buff.resize((int)msg.m_advancetype2buff_size() > (int)m_advanceType2buff.max_size() ? m_advanceType2buff.max_size() : msg.m_advancetype2buff_size());
	for(int32_t i = 0; i < (int32_t)m_advanceType2buff.size(); ++i) {
		const ::proto_ff::E_SkillSkillAdvancetype2buffDesc & temp_m_advancetype2buff = msg.m_advancetype2buff(i);
		m_advanceType2buff[i].read_from_pbmsg(temp_m_advancetype2buff);
	}
	m_advanceType3buff.resize((int)msg.m_advancetype3buff_size() > (int)m_advanceType3buff.max_size() ? m_advanceType3buff.max_size() : msg.m_advancetype3buff_size());
	for(int32_t i = 0; i < (int32_t)m_advanceType3buff.size(); ++i) {
		const ::proto_ff::E_SkillSkillAdvancetype3buffDesc & temp_m_advancetype3buff = msg.m_advancetype3buff(i);
		m_advanceType3buff[i].read_from_pbmsg(temp_m_advancetype3buff);
	}
}

Sheet_SkillSkill_s::Sheet_SkillSkill_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_SkillSkill_s::CreateInit() {
	return 0;
}

int Sheet_SkillSkill_s::ResumeInit() {
	return 0;
}

void Sheet_SkillSkill_s::write_to_pbmsg(::proto_ff::Sheet_SkillSkill & msg) const {
	for(int32_t i = 0; i < (int32_t)E_SkillSkill_List.size(); ++i) {
		::proto_ff::E_SkillSkill* temp_e_skillskill_list = msg.add_e_skillskill_list();
		E_SkillSkill_List[i].write_to_pbmsg(*temp_e_skillskill_list);
	}
}

void Sheet_SkillSkill_s::read_from_pbmsg(const ::proto_ff::Sheet_SkillSkill & msg) {
	E_SkillSkill_List.resize((int)msg.e_skillskill_list_size() > (int)E_SkillSkill_List.max_size() ? E_SkillSkill_List.max_size() : msg.e_skillskill_list_size());
	for(int32_t i = 0; i < (int32_t)E_SkillSkill_List.size(); ++i) {
		const ::proto_ff::E_SkillSkill & temp_e_skillskill_list = msg.e_skillskill_list(i);
		E_SkillSkill_List[i].read_from_pbmsg(temp_e_skillskill_list);
	}
}

E_SkillSkilladvance_s::E_SkillSkilladvance_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_SkillSkilladvance_s::CreateInit() {
	m_id = (int32_t)0;
	m_profession = (int32_t)0;
	m_type = (int32_t)0;
	m_advanceLv = (int32_t)0;
	return 0;
}

int E_SkillSkilladvance_s::ResumeInit() {
	return 0;
}

void E_SkillSkilladvance_s::write_to_pbmsg(::proto_ff::E_SkillSkilladvance & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_profession((int32_t)m_profession);
	msg.set_m_type((int32_t)m_type);
	msg.set_m_advancelv((int32_t)m_advanceLv);
	msg.set_m_advancecondition(m_advanceCondition.data());
	msg.set_m_skillid(m_skillID.data());
}

void E_SkillSkilladvance_s::read_from_pbmsg(const ::proto_ff::E_SkillSkilladvance & msg) {
	m_id = msg.m_id();
	m_profession = msg.m_profession();
	m_type = msg.m_type();
	m_advanceLv = msg.m_advancelv();
	m_advanceCondition = msg.m_advancecondition();
	m_skillID = msg.m_skillid();
}

Sheet_SkillSkilladvance_s::Sheet_SkillSkilladvance_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_SkillSkilladvance_s::CreateInit() {
	return 0;
}

int Sheet_SkillSkilladvance_s::ResumeInit() {
	return 0;
}

void Sheet_SkillSkilladvance_s::write_to_pbmsg(::proto_ff::Sheet_SkillSkilladvance & msg) const {
	for(int32_t i = 0; i < (int32_t)E_SkillSkilladvance_List.size(); ++i) {
		::proto_ff::E_SkillSkilladvance* temp_e_skillskilladvance_list = msg.add_e_skillskilladvance_list();
		E_SkillSkilladvance_List[i].write_to_pbmsg(*temp_e_skillskilladvance_list);
	}
}

void Sheet_SkillSkilladvance_s::read_from_pbmsg(const ::proto_ff::Sheet_SkillSkilladvance & msg) {
	E_SkillSkilladvance_List.resize((int)msg.e_skillskilladvance_list_size() > (int)E_SkillSkilladvance_List.max_size() ? E_SkillSkilladvance_List.max_size() : msg.e_skillskilladvance_list_size());
	for(int32_t i = 0; i < (int32_t)E_SkillSkilladvance_List.size(); ++i) {
		const ::proto_ff::E_SkillSkilladvance & temp_e_skillskilladvance_list = msg.e_skillskilladvance_list(i);
		E_SkillSkilladvance_List[i].read_from_pbmsg(temp_e_skillskilladvance_list);
	}
}

E_SkillSkillup_s::E_SkillSkillup_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_SkillSkillup_s::CreateInit() {
	m_id = (int32_t)0;
	m_group = (int32_t)0;
	m_skillLv = (int32_t)0;
	m_roleLv = (int32_t)0;
	m_costItemId = (int64_t)0;
	m_costNum = (int32_t)0;
	return 0;
}

int E_SkillSkillup_s::ResumeInit() {
	return 0;
}

void E_SkillSkillup_s::write_to_pbmsg(::proto_ff::E_SkillSkillup & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_group((int32_t)m_group);
	msg.set_m_skilllv((int32_t)m_skillLv);
	msg.set_m_skillids(m_skillIds.data());
	msg.set_m_rolelv((int32_t)m_roleLv);
	msg.set_m_costitemid((int64_t)m_costItemId);
	msg.set_m_costnum((int32_t)m_costNum);
}

void E_SkillSkillup_s::read_from_pbmsg(const ::proto_ff::E_SkillSkillup & msg) {
	m_id = msg.m_id();
	m_group = msg.m_group();
	m_skillLv = msg.m_skilllv();
	m_skillIds = msg.m_skillids();
	m_roleLv = msg.m_rolelv();
	m_costItemId = msg.m_costitemid();
	m_costNum = msg.m_costnum();
}

Sheet_SkillSkillup_s::Sheet_SkillSkillup_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_SkillSkillup_s::CreateInit() {
	return 0;
}

int Sheet_SkillSkillup_s::ResumeInit() {
	return 0;
}

void Sheet_SkillSkillup_s::write_to_pbmsg(::proto_ff::Sheet_SkillSkillup & msg) const {
	for(int32_t i = 0; i < (int32_t)E_SkillSkillup_List.size(); ++i) {
		::proto_ff::E_SkillSkillup* temp_e_skillskillup_list = msg.add_e_skillskillup_list();
		E_SkillSkillup_List[i].write_to_pbmsg(*temp_e_skillskillup_list);
	}
}

void Sheet_SkillSkillup_s::read_from_pbmsg(const ::proto_ff::Sheet_SkillSkillup & msg) {
	E_SkillSkillup_List.resize((int)msg.e_skillskillup_list_size() > (int)E_SkillSkillup_List.max_size() ? E_SkillSkillup_List.max_size() : msg.e_skillskillup_list_size());
	for(int32_t i = 0; i < (int32_t)E_SkillSkillup_List.size(); ++i) {
		const ::proto_ff::E_SkillSkillup & temp_e_skillskillup_list = msg.e_skillskillup_list(i);
		E_SkillSkillup_List[i].read_from_pbmsg(temp_e_skillskillup_list);
	}
}

E_SkillSkillawake_s::E_SkillSkillawake_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_SkillSkillawake_s::CreateInit() {
	m_skillId = (int32_t)0;
	m_costItemId = (int32_t)0;
	m_costNum = (int32_t)0;
	return 0;
}

int E_SkillSkillawake_s::ResumeInit() {
	return 0;
}

void E_SkillSkillawake_s::write_to_pbmsg(::proto_ff::E_SkillSkillawake & msg) const {
	msg.set_m_skillid((int32_t)m_skillId);
	msg.set_m_costitemid((int32_t)m_costItemId);
	msg.set_m_costnum((int32_t)m_costNum);
}

void E_SkillSkillawake_s::read_from_pbmsg(const ::proto_ff::E_SkillSkillawake & msg) {
	m_skillId = msg.m_skillid();
	m_costItemId = msg.m_costitemid();
	m_costNum = msg.m_costnum();
}

Sheet_SkillSkillawake_s::Sheet_SkillSkillawake_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_SkillSkillawake_s::CreateInit() {
	return 0;
}

int Sheet_SkillSkillawake_s::ResumeInit() {
	return 0;
}

void Sheet_SkillSkillawake_s::write_to_pbmsg(::proto_ff::Sheet_SkillSkillawake & msg) const {
	for(int32_t i = 0; i < (int32_t)E_SkillSkillawake_List.size(); ++i) {
		::proto_ff::E_SkillSkillawake* temp_e_skillskillawake_list = msg.add_e_skillskillawake_list();
		E_SkillSkillawake_List[i].write_to_pbmsg(*temp_e_skillskillawake_list);
	}
}

void Sheet_SkillSkillawake_s::read_from_pbmsg(const ::proto_ff::Sheet_SkillSkillawake & msg) {
	E_SkillSkillawake_List.resize((int)msg.e_skillskillawake_list_size() > (int)E_SkillSkillawake_List.max_size() ? E_SkillSkillawake_List.max_size() : msg.e_skillskillawake_list_size());
	for(int32_t i = 0; i < (int32_t)E_SkillSkillawake_List.size(); ++i) {
		const ::proto_ff::E_SkillSkillawake & temp_e_skillskillawake_list = msg.e_skillskillawake_list(i);
		E_SkillSkillawake_List[i].read_from_pbmsg(temp_e_skillskillawake_list);
	}
}

E_SkillSkillgroupSkillDesc_s::E_SkillSkillgroupSkillDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_SkillSkillgroupSkillDesc_s::CreateInit() {
	m_position = (int32_t)0;
	m_Id = (int32_t)0;
	return 0;
}

int E_SkillSkillgroupSkillDesc_s::ResumeInit() {
	return 0;
}

void E_SkillSkillgroupSkillDesc_s::write_to_pbmsg(::proto_ff::E_SkillSkillgroupSkillDesc & msg) const {
	msg.set_m_position((int32_t)m_position);
	msg.set_m_id((int32_t)m_Id);
}

void E_SkillSkillgroupSkillDesc_s::read_from_pbmsg(const ::proto_ff::E_SkillSkillgroupSkillDesc & msg) {
	m_position = msg.m_position();
	m_Id = msg.m_id();
}

E_SkillSkillgroup_s::E_SkillSkillgroup_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_SkillSkillgroup_s::CreateInit() {
	m_skillGroup = (int32_t)0;
	return 0;
}

int E_SkillSkillgroup_s::ResumeInit() {
	return 0;
}

void E_SkillSkillgroup_s::write_to_pbmsg(::proto_ff::E_SkillSkillgroup & msg) const {
	msg.set_m_skillgroup((int32_t)m_skillGroup);
	msg.set_m_showskilltype(m_showSkillType.data());
	for(int32_t i = 0; i < (int32_t)m_skill.size(); ++i) {
		::proto_ff::E_SkillSkillgroupSkillDesc* temp_m_skill = msg.add_m_skill();
		m_skill[i].write_to_pbmsg(*temp_m_skill);
	}
}

void E_SkillSkillgroup_s::read_from_pbmsg(const ::proto_ff::E_SkillSkillgroup & msg) {
	m_skillGroup = msg.m_skillgroup();
	m_showSkillType = msg.m_showskilltype();
	m_skill.resize((int)msg.m_skill_size() > (int)m_skill.max_size() ? m_skill.max_size() : msg.m_skill_size());
	for(int32_t i = 0; i < (int32_t)m_skill.size(); ++i) {
		const ::proto_ff::E_SkillSkillgroupSkillDesc & temp_m_skill = msg.m_skill(i);
		m_skill[i].read_from_pbmsg(temp_m_skill);
	}
}

Sheet_SkillSkillgroup_s::Sheet_SkillSkillgroup_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_SkillSkillgroup_s::CreateInit() {
	return 0;
}

int Sheet_SkillSkillgroup_s::ResumeInit() {
	return 0;
}

void Sheet_SkillSkillgroup_s::write_to_pbmsg(::proto_ff::Sheet_SkillSkillgroup & msg) const {
	for(int32_t i = 0; i < (int32_t)E_SkillSkillgroup_List.size(); ++i) {
		::proto_ff::E_SkillSkillgroup* temp_e_skillskillgroup_list = msg.add_e_skillskillgroup_list();
		E_SkillSkillgroup_List[i].write_to_pbmsg(*temp_e_skillskillgroup_list);
	}
}

void Sheet_SkillSkillgroup_s::read_from_pbmsg(const ::proto_ff::Sheet_SkillSkillgroup & msg) {
	E_SkillSkillgroup_List.resize((int)msg.e_skillskillgroup_list_size() > (int)E_SkillSkillgroup_List.max_size() ? E_SkillSkillgroup_List.max_size() : msg.e_skillskillgroup_list_size());
	for(int32_t i = 0; i < (int32_t)E_SkillSkillgroup_List.size(); ++i) {
		const ::proto_ff::E_SkillSkillgroup & temp_e_skillskillgroup_list = msg.e_skillskillgroup_list(i);
		E_SkillSkillgroup_List[i].read_from_pbmsg(temp_e_skillskillgroup_list);
	}
}

E_SkillAttgroupAttributeDesc_s::E_SkillAttgroupAttributeDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_SkillAttgroupAttributeDesc_s::CreateInit() {
	m_value = (int64_t)0;
	m_type = (int32_t)0;
	return 0;
}

int E_SkillAttgroupAttributeDesc_s::ResumeInit() {
	return 0;
}

void E_SkillAttgroupAttributeDesc_s::write_to_pbmsg(::proto_ff::E_SkillAttgroupAttributeDesc & msg) const {
	msg.set_m_value((int64_t)m_value);
	msg.set_m_type((int32_t)m_type);
}

void E_SkillAttgroupAttributeDesc_s::read_from_pbmsg(const ::proto_ff::E_SkillAttgroupAttributeDesc & msg) {
	m_value = msg.m_value();
	m_type = msg.m_type();
}

E_SkillAttgroup_s::E_SkillAttgroup_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_SkillAttgroup_s::CreateInit() {
	m_id = (int32_t)0;
	return 0;
}

int E_SkillAttgroup_s::ResumeInit() {
	return 0;
}

void E_SkillAttgroup_s::write_to_pbmsg(::proto_ff::E_SkillAttgroup & msg) const {
	msg.set_m_id((int32_t)m_id);
	for(int32_t i = 0; i < (int32_t)m_attribute.size(); ++i) {
		::proto_ff::E_SkillAttgroupAttributeDesc* temp_m_attribute = msg.add_m_attribute();
		m_attribute[i].write_to_pbmsg(*temp_m_attribute);
	}
}

void E_SkillAttgroup_s::read_from_pbmsg(const ::proto_ff::E_SkillAttgroup & msg) {
	m_id = msg.m_id();
	m_attribute.resize((int)msg.m_attribute_size() > (int)m_attribute.max_size() ? m_attribute.max_size() : msg.m_attribute_size());
	for(int32_t i = 0; i < (int32_t)m_attribute.size(); ++i) {
		const ::proto_ff::E_SkillAttgroupAttributeDesc & temp_m_attribute = msg.m_attribute(i);
		m_attribute[i].read_from_pbmsg(temp_m_attribute);
	}
}

Sheet_SkillAttgroup_s::Sheet_SkillAttgroup_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_SkillAttgroup_s::CreateInit() {
	return 0;
}

int Sheet_SkillAttgroup_s::ResumeInit() {
	return 0;
}

void Sheet_SkillAttgroup_s::write_to_pbmsg(::proto_ff::Sheet_SkillAttgroup & msg) const {
	for(int32_t i = 0; i < (int32_t)E_SkillAttgroup_List.size(); ++i) {
		::proto_ff::E_SkillAttgroup* temp_e_skillattgroup_list = msg.add_e_skillattgroup_list();
		E_SkillAttgroup_List[i].write_to_pbmsg(*temp_e_skillattgroup_list);
	}
}

void Sheet_SkillAttgroup_s::read_from_pbmsg(const ::proto_ff::Sheet_SkillAttgroup & msg) {
	E_SkillAttgroup_List.resize((int)msg.e_skillattgroup_list_size() > (int)E_SkillAttgroup_List.max_size() ? E_SkillAttgroup_List.max_size() : msg.e_skillattgroup_list_size());
	for(int32_t i = 0; i < (int32_t)E_SkillAttgroup_List.size(); ++i) {
		const ::proto_ff::E_SkillAttgroup & temp_e_skillattgroup_list = msg.e_skillattgroup_list(i);
		E_SkillAttgroup_List[i].read_from_pbmsg(temp_e_skillattgroup_list);
	}
}

}
