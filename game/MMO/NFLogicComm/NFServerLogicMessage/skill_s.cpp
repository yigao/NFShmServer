#include "skill_s.h"

namespace proto_ff_s {

E_SkillBuff_s::E_SkillBuff_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_SkillBuff_s::CreateInit() {
	m_buffid = (int64_t)0;
	m_showtpye = (int32_t)0;
	m_startprobability = (int32_t)0;
	m_probability_up = (int32_t)0;
	m_starttype = (int32_t)0;
	m_endtype = (int32_t)0;
	m_group = (int32_t)0;
	m_buffcd = (int32_t)0;
	m_effect_time = (int32_t)0;
	m_effect_type = (int32_t)0;
	m_effect_up = (int32_t)0;
	return 0;
}

int E_SkillBuff_s::ResumeInit() {
	return 0;
}

void E_SkillBuff_s::write_to_pbmsg(::proto_ff::E_SkillBuff & msg) const {
	msg.set_m_buffid((int64_t)m_buffid);
	msg.set_m_buffname((const char*)m_buffname.data());
	msg.set_m_bufficon((const char*)m_bufficon.data());
	msg.set_m_effectresources((const char*)m_effectresources.data());
	msg.set_m_showtpye((int32_t)m_showtpye);
	msg.set_m_startprobability((int32_t)m_startprobability);
	msg.set_m_probability_up((int32_t)m_probability_up);
	msg.set_m_starttype((int32_t)m_starttype);
	msg.set_m_starttypevalue((const char*)m_starttypevalue.data());
	msg.set_m_endtype((int32_t)m_endtype);
	msg.set_m_endtypevalue((const char*)m_endtypevalue.data());
	msg.set_m_group((int32_t)m_group);
	msg.set_m_buffrule((const char*)m_buffrule.data());
	msg.set_m_immune((const char*)m_immune.data());
	msg.set_m_dispel((const char*)m_dispel.data());
	msg.set_m_buffcd((int32_t)m_buffcd);
	msg.set_m_effect_time((int32_t)m_effect_time);
	msg.set_m_effect_type((int32_t)m_effect_type);
	msg.set_m_effect_param((const char*)m_effect_param.data());
	msg.set_m_effect_up((int32_t)m_effect_up);
}

void E_SkillBuff_s::read_from_pbmsg(const ::proto_ff::E_SkillBuff & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct E_SkillBuff_s));
	m_buffid = msg.m_buffid();
	m_buffname = msg.m_buffname();
	m_bufficon = msg.m_bufficon();
	m_effectresources = msg.m_effectresources();
	m_showtpye = msg.m_showtpye();
	m_startprobability = msg.m_startprobability();
	m_probability_up = msg.m_probability_up();
	m_starttype = msg.m_starttype();
	m_starttypevalue = msg.m_starttypevalue();
	m_endtype = msg.m_endtype();
	m_endtypevalue = msg.m_endtypevalue();
	m_group = msg.m_group();
	m_buffrule = msg.m_buffrule();
	m_immune = msg.m_immune();
	m_dispel = msg.m_dispel();
	m_buffcd = msg.m_buffcd();
	m_effect_time = msg.m_effect_time();
	m_effect_type = msg.m_effect_type();
	m_effect_param = msg.m_effect_param();
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
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_SkillBuff_s));
	E_SkillBuff_List.resize((int)msg.e_skillbuff_list_size() > (int)E_SkillBuff_List.max_size() ? E_SkillBuff_List.max_size() : msg.e_skillbuff_list_size());
	for(int32_t i = 0; i < (int32_t)E_SkillBuff_List.size(); ++i) {
		const ::proto_ff::E_SkillBuff & temp_e_skillbuff_list = msg.e_skillbuff_list(i);
		E_SkillBuff_List[i].read_from_pbmsg(temp_e_skillbuff_list);
	}
}

E_SkillSkillAdvancetype1buffDesc_s::E_SkillSkillAdvancetype1buffDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_SkillSkillAdvancetype1buffDesc_s::CreateInit() {
	m_id = (int64_t)0;
	return 0;
}

int E_SkillSkillAdvancetype1buffDesc_s::ResumeInit() {
	return 0;
}

void E_SkillSkillAdvancetype1buffDesc_s::write_to_pbmsg(::proto_ff::E_SkillSkillAdvancetype1buffDesc & msg) const {
	msg.set_m_id((int64_t)m_id);
}

void E_SkillSkillAdvancetype1buffDesc_s::read_from_pbmsg(const ::proto_ff::E_SkillSkillAdvancetype1buffDesc & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct E_SkillSkillAdvancetype1buffDesc_s));
	m_id = msg.m_id();
}

E_SkillSkillAdvancetype2buffDesc_s::E_SkillSkillAdvancetype2buffDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_SkillSkillAdvancetype2buffDesc_s::CreateInit() {
	m_id = (int64_t)0;
	return 0;
}

int E_SkillSkillAdvancetype2buffDesc_s::ResumeInit() {
	return 0;
}

void E_SkillSkillAdvancetype2buffDesc_s::write_to_pbmsg(::proto_ff::E_SkillSkillAdvancetype2buffDesc & msg) const {
	msg.set_m_id((int64_t)m_id);
}

void E_SkillSkillAdvancetype2buffDesc_s::read_from_pbmsg(const ::proto_ff::E_SkillSkillAdvancetype2buffDesc & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct E_SkillSkillAdvancetype2buffDesc_s));
	m_id = msg.m_id();
}

E_SkillSkillAwakebuffDesc_s::E_SkillSkillAwakebuffDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_SkillSkillAwakebuffDesc_s::CreateInit() {
	m_id = (int64_t)0;
	return 0;
}

int E_SkillSkillAwakebuffDesc_s::ResumeInit() {
	return 0;
}

void E_SkillSkillAwakebuffDesc_s::write_to_pbmsg(::proto_ff::E_SkillSkillAwakebuffDesc & msg) const {
	msg.set_m_id((int64_t)m_id);
}

void E_SkillSkillAwakebuffDesc_s::read_from_pbmsg(const ::proto_ff::E_SkillSkillAwakebuffDesc & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct E_SkillSkillAwakebuffDesc_s));
	m_id = msg.m_id();
}

E_SkillSkillAdvancetype3buffDesc_s::E_SkillSkillAdvancetype3buffDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_SkillSkillAdvancetype3buffDesc_s::CreateInit() {
	m_id = (int64_t)0;
	return 0;
}

int E_SkillSkillAdvancetype3buffDesc_s::ResumeInit() {
	return 0;
}

void E_SkillSkillAdvancetype3buffDesc_s::write_to_pbmsg(::proto_ff::E_SkillSkillAdvancetype3buffDesc & msg) const {
	msg.set_m_id((int64_t)m_id);
}

void E_SkillSkillAdvancetype3buffDesc_s::read_from_pbmsg(const ::proto_ff::E_SkillSkillAdvancetype3buffDesc & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct E_SkillSkillAdvancetype3buffDesc_s));
	m_id = msg.m_id();
}

E_SkillSkillBuffDesc_s::E_SkillSkillBuffDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_SkillSkillBuffDesc_s::CreateInit() {
	m_target = (int32_t)0;
	m_id = (int64_t)0;
	m_point = (int32_t)0;
	return 0;
}

int E_SkillSkillBuffDesc_s::ResumeInit() {
	return 0;
}

void E_SkillSkillBuffDesc_s::write_to_pbmsg(::proto_ff::E_SkillSkillBuffDesc & msg) const {
	msg.set_m_target((int32_t)m_target);
	msg.set_m_id((int64_t)m_id);
	msg.set_m_point((int32_t)m_point);
}

void E_SkillSkillBuffDesc_s::read_from_pbmsg(const ::proto_ff::E_SkillSkillBuffDesc & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct E_SkillSkillBuffDesc_s));
	m_target = msg.m_target();
	m_id = msg.m_id();
	m_point = msg.m_point();
}

E_SkillSkill_s::E_SkillSkill_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_SkillSkill_s::CreateInit() {
	m_skillid = (int64_t)0;
	m_skilltype = (int32_t)0;
	m_group = (int32_t)0;
	m_position = (int32_t)0;
	m_displacetime = (int32_t)0;
	m_displacesign = (int32_t)0;
	m_breaktype = (int32_t)0;
	m_cdskill = (int32_t)0;
	m_relation = (int64_t)0;
	m_type = (int32_t)0;
	m_cd = (int32_t)0;
	m_nolock = (int32_t)0;
	m_priority = (int32_t)0;
	m_fightingparama = (float)0;
	m_releasetype = (int32_t)0;
	m_processtypes = (int32_t)0;
	m_flyspeed = (int32_t)0;
	m_acttime = (int32_t)0;
	m_readytime = (int32_t)0;
	m_attacktime = (int32_t)0;
	m_attackdistance = (int32_t)0;
	m_rangetype = (int32_t)0;
	m_warn = (int32_t)0;
	m_dazetime = (int32_t)0;
	m_warntime = (int32_t)0;
	m_attackmindistance = (int32_t)0;
	m_goalmaxnum = (int32_t)0;
	m_goalmaxnummonster = (int32_t)0;
	m_damagetype = (int32_t)0;
	m_damagerate = (int32_t)0;
	m_awakedamagerate = (int32_t)0;
	m_advancetype1damagerate = (int32_t)0;
	m_advancetype2damagerate = (int32_t)0;
	m_advancetype3damagerate = (int32_t)0;
	m_damagevalue = (int32_t)0;
	m_damageparama = (float)0;
	m_addhitrate = (int32_t)0;
	m_awakeitemid = (int32_t)0;
	m_awakecostnum = (int32_t)0;
	return 0;
}

int E_SkillSkill_s::ResumeInit() {
	return 0;
}

void E_SkillSkill_s::write_to_pbmsg(::proto_ff::E_SkillSkill & msg) const {
	msg.set_m_skillid((int64_t)m_skillid);
	msg.set_m_name((const char*)m_name.data());
	msg.set_m_skilltype((int32_t)m_skilltype);
	msg.set_m_group((int32_t)m_group);
	msg.set_m_position((int32_t)m_position);
	msg.set_m_displacetime((int32_t)m_displacetime);
	msg.set_m_displacesign((int32_t)m_displacesign);
	msg.set_m_displacespeed((const char*)m_displacespeed.data());
	msg.set_m_distimes((const char*)m_distimes.data());
	msg.set_m_breaktype((int32_t)m_breaktype);
	msg.set_m_cdskill((int32_t)m_cdskill);
	msg.set_m_relation((int64_t)m_relation);
	msg.set_m_unlockcondition((const char*)m_unlockcondition.data());
	msg.set_m_type((int32_t)m_type);
	msg.set_m_cd((int32_t)m_cd);
	msg.set_m_nolock((int32_t)m_nolock);
	msg.set_m_priority((int32_t)m_priority);
	msg.set_m_fighting((const char*)m_fighting.data());
	msg.set_m_fightingparama((float)m_fightingparama);
	msg.set_m_releasetype((int32_t)m_releasetype);
	msg.set_m_processtypes((int32_t)m_processtypes);
	msg.set_m_flyspeed((int32_t)m_flyspeed);
	msg.set_m_acttime((int32_t)m_acttime);
	msg.set_m_readytime((int32_t)m_readytime);
	msg.set_m_attacktime((int32_t)m_attacktime);
	msg.set_m_damagetime((const char*)m_damagetime.data());
	msg.set_m_attackdistance((int32_t)m_attackdistance);
	msg.set_m_rangetype((int32_t)m_rangetype);
	msg.set_m_rangetypevalue((const char*)m_rangetypevalue.data());
	msg.set_m_warn((int32_t)m_warn);
	msg.set_m_dazetime((int32_t)m_dazetime);
	msg.set_m_warntime((int32_t)m_warntime);
	msg.set_m_infomationid((const char*)m_infomationid.data());
	msg.set_m_attackmindistance((int32_t)m_attackmindistance);
	msg.set_m_goalmaxnum((int32_t)m_goalmaxnum);
	msg.set_m_goalmaxnummonster((int32_t)m_goalmaxnummonster);
	msg.set_m_damagetype((int32_t)m_damagetype);
	msg.set_m_damagerate((int32_t)m_damagerate);
	msg.set_m_awakedamagerate((int32_t)m_awakedamagerate);
	msg.set_m_advancetype1damagerate((int32_t)m_advancetype1damagerate);
	msg.set_m_advancetype2damagerate((int32_t)m_advancetype2damagerate);
	msg.set_m_advancetype3damagerate((int32_t)m_advancetype3damagerate);
	msg.set_m_damagevalue((int32_t)m_damagevalue);
	msg.set_m_damageparama((float)m_damageparama);
	msg.set_m_addhitrate((int32_t)m_addhitrate);
	msg.set_m_awakeitemid((int32_t)m_awakeitemid);
	msg.set_m_awakecostnum((int32_t)m_awakecostnum);
	for(int32_t i = 0; i < (int32_t)m_advancetype1buff.size(); ++i) {
		::proto_ff::E_SkillSkillAdvancetype1buffDesc* temp_m_advancetype1buff = msg.add_m_advancetype1buff();
		m_advancetype1buff[i].write_to_pbmsg(*temp_m_advancetype1buff);
	}
	for(int32_t i = 0; i < (int32_t)m_advancetype2buff.size(); ++i) {
		::proto_ff::E_SkillSkillAdvancetype2buffDesc* temp_m_advancetype2buff = msg.add_m_advancetype2buff();
		m_advancetype2buff[i].write_to_pbmsg(*temp_m_advancetype2buff);
	}
	for(int32_t i = 0; i < (int32_t)m_awakebuff.size(); ++i) {
		::proto_ff::E_SkillSkillAwakebuffDesc* temp_m_awakebuff = msg.add_m_awakebuff();
		m_awakebuff[i].write_to_pbmsg(*temp_m_awakebuff);
	}
	for(int32_t i = 0; i < (int32_t)m_advancetype3buff.size(); ++i) {
		::proto_ff::E_SkillSkillAdvancetype3buffDesc* temp_m_advancetype3buff = msg.add_m_advancetype3buff();
		m_advancetype3buff[i].write_to_pbmsg(*temp_m_advancetype3buff);
	}
	for(int32_t i = 0; i < (int32_t)m_buff.size(); ++i) {
		::proto_ff::E_SkillSkillBuffDesc* temp_m_buff = msg.add_m_buff();
		m_buff[i].write_to_pbmsg(*temp_m_buff);
	}
}

void E_SkillSkill_s::read_from_pbmsg(const ::proto_ff::E_SkillSkill & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct E_SkillSkill_s));
	m_skillid = msg.m_skillid();
	m_name = msg.m_name();
	m_skilltype = msg.m_skilltype();
	m_group = msg.m_group();
	m_position = msg.m_position();
	m_displacetime = msg.m_displacetime();
	m_displacesign = msg.m_displacesign();
	m_displacespeed = msg.m_displacespeed();
	m_distimes = msg.m_distimes();
	m_breaktype = msg.m_breaktype();
	m_cdskill = msg.m_cdskill();
	m_relation = msg.m_relation();
	m_unlockcondition = msg.m_unlockcondition();
	m_type = msg.m_type();
	m_cd = msg.m_cd();
	m_nolock = msg.m_nolock();
	m_priority = msg.m_priority();
	m_fighting = msg.m_fighting();
	m_fightingparama = msg.m_fightingparama();
	m_releasetype = msg.m_releasetype();
	m_processtypes = msg.m_processtypes();
	m_flyspeed = msg.m_flyspeed();
	m_acttime = msg.m_acttime();
	m_readytime = msg.m_readytime();
	m_attacktime = msg.m_attacktime();
	m_damagetime = msg.m_damagetime();
	m_attackdistance = msg.m_attackdistance();
	m_rangetype = msg.m_rangetype();
	m_rangetypevalue = msg.m_rangetypevalue();
	m_warn = msg.m_warn();
	m_dazetime = msg.m_dazetime();
	m_warntime = msg.m_warntime();
	m_infomationid = msg.m_infomationid();
	m_attackmindistance = msg.m_attackmindistance();
	m_goalmaxnum = msg.m_goalmaxnum();
	m_goalmaxnummonster = msg.m_goalmaxnummonster();
	m_damagetype = msg.m_damagetype();
	m_damagerate = msg.m_damagerate();
	m_awakedamagerate = msg.m_awakedamagerate();
	m_advancetype1damagerate = msg.m_advancetype1damagerate();
	m_advancetype2damagerate = msg.m_advancetype2damagerate();
	m_advancetype3damagerate = msg.m_advancetype3damagerate();
	m_damagevalue = msg.m_damagevalue();
	m_damageparama = msg.m_damageparama();
	m_addhitrate = msg.m_addhitrate();
	m_awakeitemid = msg.m_awakeitemid();
	m_awakecostnum = msg.m_awakecostnum();
	m_advancetype1buff.resize((int)msg.m_advancetype1buff_size() > (int)m_advancetype1buff.max_size() ? m_advancetype1buff.max_size() : msg.m_advancetype1buff_size());
	for(int32_t i = 0; i < (int32_t)m_advancetype1buff.size(); ++i) {
		const ::proto_ff::E_SkillSkillAdvancetype1buffDesc & temp_m_advancetype1buff = msg.m_advancetype1buff(i);
		m_advancetype1buff[i].read_from_pbmsg(temp_m_advancetype1buff);
	}
	m_advancetype2buff.resize((int)msg.m_advancetype2buff_size() > (int)m_advancetype2buff.max_size() ? m_advancetype2buff.max_size() : msg.m_advancetype2buff_size());
	for(int32_t i = 0; i < (int32_t)m_advancetype2buff.size(); ++i) {
		const ::proto_ff::E_SkillSkillAdvancetype2buffDesc & temp_m_advancetype2buff = msg.m_advancetype2buff(i);
		m_advancetype2buff[i].read_from_pbmsg(temp_m_advancetype2buff);
	}
	m_awakebuff.resize((int)msg.m_awakebuff_size() > (int)m_awakebuff.max_size() ? m_awakebuff.max_size() : msg.m_awakebuff_size());
	for(int32_t i = 0; i < (int32_t)m_awakebuff.size(); ++i) {
		const ::proto_ff::E_SkillSkillAwakebuffDesc & temp_m_awakebuff = msg.m_awakebuff(i);
		m_awakebuff[i].read_from_pbmsg(temp_m_awakebuff);
	}
	m_advancetype3buff.resize((int)msg.m_advancetype3buff_size() > (int)m_advancetype3buff.max_size() ? m_advancetype3buff.max_size() : msg.m_advancetype3buff_size());
	for(int32_t i = 0; i < (int32_t)m_advancetype3buff.size(); ++i) {
		const ::proto_ff::E_SkillSkillAdvancetype3buffDesc & temp_m_advancetype3buff = msg.m_advancetype3buff(i);
		m_advancetype3buff[i].read_from_pbmsg(temp_m_advancetype3buff);
	}
	m_buff.resize((int)msg.m_buff_size() > (int)m_buff.max_size() ? m_buff.max_size() : msg.m_buff_size());
	for(int32_t i = 0; i < (int32_t)m_buff.size(); ++i) {
		const ::proto_ff::E_SkillSkillBuffDesc & temp_m_buff = msg.m_buff(i);
		m_buff[i].read_from_pbmsg(temp_m_buff);
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
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_SkillSkill_s));
	E_SkillSkill_List.resize((int)msg.e_skillskill_list_size() > (int)E_SkillSkill_List.max_size() ? E_SkillSkill_List.max_size() : msg.e_skillskill_list_size());
	for(int32_t i = 0; i < (int32_t)E_SkillSkill_List.size(); ++i) {
		const ::proto_ff::E_SkillSkill & temp_e_skillskill_list = msg.e_skillskill_list(i);
		E_SkillSkill_List[i].read_from_pbmsg(temp_e_skillskill_list);
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
	m_addstartprobability = (int32_t)0;
	m_attributeid = (int32_t)0;
	m_parama = (int32_t)0;
	return 0;
}

int E_SkillBuffup_s::ResumeInit() {
	return 0;
}

void E_SkillBuffup_s::write_to_pbmsg(::proto_ff::E_SkillBuffup & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_addstartprobability((int32_t)m_addstartprobability);
	msg.set_m_attributeid((int32_t)m_attributeid);
	msg.set_m_parama((int32_t)m_parama);
}

void E_SkillBuffup_s::read_from_pbmsg(const ::proto_ff::E_SkillBuffup & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct E_SkillBuffup_s));
	m_id = msg.m_id();
	m_addstartprobability = msg.m_addstartprobability();
	m_attributeid = msg.m_attributeid();
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
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_SkillBuffup_s));
	E_SkillBuffup_List.resize((int)msg.e_skillbuffup_list_size() > (int)E_SkillBuffup_List.max_size() ? E_SkillBuffup_List.max_size() : msg.e_skillbuffup_list_size());
	for(int32_t i = 0; i < (int32_t)E_SkillBuffup_List.size(); ++i) {
		const ::proto_ff::E_SkillBuffup & temp_e_skillbuffup_list = msg.e_skillbuffup_list(i);
		E_SkillBuffup_List[i].read_from_pbmsg(temp_e_skillbuffup_list);
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
	m_skilllv = (int32_t)0;
	m_rolelv = (int32_t)0;
	m_costitemid = (int64_t)0;
	m_costnum = (int32_t)0;
	return 0;
}

int E_SkillSkillup_s::ResumeInit() {
	return 0;
}

void E_SkillSkillup_s::write_to_pbmsg(::proto_ff::E_SkillSkillup & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_group((int32_t)m_group);
	msg.set_m_skilllv((int32_t)m_skilllv);
	msg.set_m_skillids((const char*)m_skillids.data());
	msg.set_m_rolelv((int32_t)m_rolelv);
	msg.set_m_costitemid((int64_t)m_costitemid);
	msg.set_m_costnum((int32_t)m_costnum);
}

void E_SkillSkillup_s::read_from_pbmsg(const ::proto_ff::E_SkillSkillup & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct E_SkillSkillup_s));
	m_id = msg.m_id();
	m_group = msg.m_group();
	m_skilllv = msg.m_skilllv();
	m_skillids = msg.m_skillids();
	m_rolelv = msg.m_rolelv();
	m_costitemid = msg.m_costitemid();
	m_costnum = msg.m_costnum();
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
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_SkillSkillup_s));
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
	m_skillid = (int32_t)0;
	m_costitemid = (int32_t)0;
	m_costnum = (int32_t)0;
	return 0;
}

int E_SkillSkillawake_s::ResumeInit() {
	return 0;
}

void E_SkillSkillawake_s::write_to_pbmsg(::proto_ff::E_SkillSkillawake & msg) const {
	msg.set_m_skillid((int32_t)m_skillid);
	msg.set_m_costitemid((int32_t)m_costitemid);
	msg.set_m_costnum((int32_t)m_costnum);
}

void E_SkillSkillawake_s::read_from_pbmsg(const ::proto_ff::E_SkillSkillawake & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct E_SkillSkillawake_s));
	m_skillid = msg.m_skillid();
	m_costitemid = msg.m_costitemid();
	m_costnum = msg.m_costnum();
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
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_SkillSkillawake_s));
	E_SkillSkillawake_List.resize((int)msg.e_skillskillawake_list_size() > (int)E_SkillSkillawake_List.max_size() ? E_SkillSkillawake_List.max_size() : msg.e_skillskillawake_list_size());
	for(int32_t i = 0; i < (int32_t)E_SkillSkillawake_List.size(); ++i) {
		const ::proto_ff::E_SkillSkillawake & temp_e_skillskillawake_list = msg.e_skillskillawake_list(i);
		E_SkillSkillawake_List[i].read_from_pbmsg(temp_e_skillskillawake_list);
	}
}

}