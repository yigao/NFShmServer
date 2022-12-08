#include "skill_s.h"

namespace proto_ff_s {

skillbuff_s::skillbuff_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int skillbuff_s::CreateInit() {
	buffID = (int64_t)0;
	showTpye = (int32_t)0;
	startProbability = (int32_t)0;
	Probability_up = (int32_t)0;
	startType = (int32_t)0;
	endType = (int32_t)0;
	group = (int32_t)0;
	buffCd = (int32_t)0;
	effect_Time = (int32_t)0;
	effect_Type = (int32_t)0;
	effect_up = (int32_t)0;
	return 0;
}

int skillbuff_s::ResumeInit() {
	return 0;
}

void skillbuff_s::write_to_pbmsg(::proto_ff::skillbuff & msg) const {
	msg.set_buffid((int64_t)buffID);
	msg.set_buffname((const char*)buffName.Get());
	msg.set_bufficon((const char*)buffIcon.Get());
	msg.set_effectresources((const char*)effectResources.Get());
	msg.set_showtpye((int32_t)showTpye);
	msg.set_startprobability((int32_t)startProbability);
	msg.set_probability_up((int32_t)Probability_up);
	msg.set_starttype((int32_t)startType);
	msg.set_starttypevalue((const char*)startTypeValue.Get());
	msg.set_endtype((int32_t)endType);
	msg.set_endtypevalue((const char*)endTypeValue.Get());
	msg.set_group((int32_t)group);
	msg.set_buffrule((const char*)buffRule.Get());
	msg.set_immune((const char*)immune.Get());
	msg.set_dispel((const char*)dispel.Get());
	msg.set_buffcd((int32_t)buffCd);
	msg.set_effect_time((int32_t)effect_Time);
	msg.set_effect_type((int32_t)effect_Type);
	msg.set_effect_param((const char*)effect_Param.Get());
	msg.set_effect_up((int32_t)effect_up);
}

void skillbuff_s::read_from_pbmsg(const ::proto_ff::skillbuff & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct skillbuff_s));
	buffID = msg.buffid();
	buffName.Copy(msg.buffname());
	buffIcon.Copy(msg.bufficon());
	effectResources.Copy(msg.effectresources());
	showTpye = msg.showtpye();
	startProbability = msg.startprobability();
	Probability_up = msg.probability_up();
	startType = msg.starttype();
	startTypeValue.Copy(msg.starttypevalue());
	endType = msg.endtype();
	endTypeValue.Copy(msg.endtypevalue());
	group = msg.group();
	buffRule.Copy(msg.buffrule());
	immune.Copy(msg.immune());
	dispel.Copy(msg.dispel());
	buffCd = msg.buffcd();
	effect_Time = msg.effect_time();
	effect_Type = msg.effect_type();
	effect_Param.Copy(msg.effect_param());
	effect_up = msg.effect_up();
}

Sheet_skillbuff_s::Sheet_skillbuff_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_skillbuff_s::CreateInit() {
	return 0;
}

int Sheet_skillbuff_s::ResumeInit() {
	return 0;
}

void Sheet_skillbuff_s::write_to_pbmsg(::proto_ff::Sheet_skillbuff & msg) const {
	for(int32_t i = 0; i < (int32_t)skillbuff_List.GetSize() && i < skillbuff_List.GetMaxSize(); ++i) {
		::proto_ff::skillbuff* temp_skillbuff_list = msg.add_skillbuff_list();
		skillbuff_List[i].write_to_pbmsg(*temp_skillbuff_list);
	}
}

void Sheet_skillbuff_s::read_from_pbmsg(const ::proto_ff::Sheet_skillbuff & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_skillbuff_s));
	skillbuff_List.SetSize(msg.skillbuff_list_size() > skillbuff_List.GetMaxSize() ? skillbuff_List.GetMaxSize() : msg.skillbuff_list_size());
	for(int32_t i = 0; i < (int32_t)skillbuff_List.GetSize(); ++i) {
		const ::proto_ff::skillbuff & temp_skillbuff_list = msg.skillbuff_list(i);
		skillbuff_List[i].read_from_pbmsg(temp_skillbuff_list);
	}
}

skillskilladvanceType1buffDesc_s::skillskilladvanceType1buffDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int skillskilladvanceType1buffDesc_s::CreateInit() {
	ID = (int64_t)0;
	return 0;
}

int skillskilladvanceType1buffDesc_s::ResumeInit() {
	return 0;
}

void skillskilladvanceType1buffDesc_s::write_to_pbmsg(::proto_ff::skillskilladvanceType1buffDesc & msg) const {
	msg.set_id((int64_t)ID);
}

void skillskilladvanceType1buffDesc_s::read_from_pbmsg(const ::proto_ff::skillskilladvanceType1buffDesc & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct skillskilladvanceType1buffDesc_s));
	ID = msg.id();
}

skillskilladvanceType2buffDesc_s::skillskilladvanceType2buffDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int skillskilladvanceType2buffDesc_s::CreateInit() {
	ID = (int64_t)0;
	return 0;
}

int skillskilladvanceType2buffDesc_s::ResumeInit() {
	return 0;
}

void skillskilladvanceType2buffDesc_s::write_to_pbmsg(::proto_ff::skillskilladvanceType2buffDesc & msg) const {
	msg.set_id((int64_t)ID);
}

void skillskilladvanceType2buffDesc_s::read_from_pbmsg(const ::proto_ff::skillskilladvanceType2buffDesc & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct skillskilladvanceType2buffDesc_s));
	ID = msg.id();
}

skillskillawakebuffDesc_s::skillskillawakebuffDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int skillskillawakebuffDesc_s::CreateInit() {
	ID = (int64_t)0;
	return 0;
}

int skillskillawakebuffDesc_s::ResumeInit() {
	return 0;
}

void skillskillawakebuffDesc_s::write_to_pbmsg(::proto_ff::skillskillawakebuffDesc & msg) const {
	msg.set_id((int64_t)ID);
}

void skillskillawakebuffDesc_s::read_from_pbmsg(const ::proto_ff::skillskillawakebuffDesc & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct skillskillawakebuffDesc_s));
	ID = msg.id();
}

skillskilladvanceType3buffDesc_s::skillskilladvanceType3buffDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int skillskilladvanceType3buffDesc_s::CreateInit() {
	ID = (int64_t)0;
	return 0;
}

int skillskilladvanceType3buffDesc_s::ResumeInit() {
	return 0;
}

void skillskilladvanceType3buffDesc_s::write_to_pbmsg(::proto_ff::skillskilladvanceType3buffDesc & msg) const {
	msg.set_id((int64_t)ID);
}

void skillskilladvanceType3buffDesc_s::read_from_pbmsg(const ::proto_ff::skillskilladvanceType3buffDesc & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct skillskilladvanceType3buffDesc_s));
	ID = msg.id();
}

skillskillbuffDesc_s::skillskillbuffDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int skillskillbuffDesc_s::CreateInit() {
	Target = (int32_t)0;
	ID = (int64_t)0;
	Point = (int32_t)0;
	return 0;
}

int skillskillbuffDesc_s::ResumeInit() {
	return 0;
}

void skillskillbuffDesc_s::write_to_pbmsg(::proto_ff::skillskillbuffDesc & msg) const {
	msg.set_target((int32_t)Target);
	msg.set_id((int64_t)ID);
	msg.set_point((int32_t)Point);
}

void skillskillbuffDesc_s::read_from_pbmsg(const ::proto_ff::skillskillbuffDesc & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct skillskillbuffDesc_s));
	Target = msg.target();
	ID = msg.id();
	Point = msg.point();
}

skillskill_s::skillskill_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int skillskill_s::CreateInit() {
	skillID = (int64_t)0;
	skillType = (int32_t)0;
	group = (int32_t)0;
	position = (int32_t)0;
	displaceTime = (int32_t)0;
	displaceSign = (int32_t)0;
	breakType = (int32_t)0;
	cdSkill = (int32_t)0;
	Relation = (int64_t)0;
	type = (int32_t)0;
	cd = (int32_t)0;
	noLock = (int32_t)0;
	priority = (int32_t)0;
	fightingParama = (float)0;
	releaseType = (int32_t)0;
	processTypes = (int32_t)0;
	flySpeed = (int32_t)0;
	actTime = (int32_t)0;
	readyTime = (int32_t)0;
	attackTime = (int32_t)0;
	attackDistance = (int32_t)0;
	rangeType = (int32_t)0;
	warn = (int32_t)0;
	dazeTime = (int32_t)0;
	warnTime = (int32_t)0;
	attackMinDistance = (int32_t)0;
	goalMaxNum = (int32_t)0;
	goalMaxNumMonster = (int32_t)0;
	damageType = (int32_t)0;
	damageRate = (int32_t)0;
	awakeDamageRate = (int32_t)0;
	advanceType1DamageRate = (int32_t)0;
	advanceType2DamageRate = (int32_t)0;
	advanceType3DamageRate = (int32_t)0;
	damageValue = (int32_t)0;
	damageParama = (float)0;
	addhitrate = (int32_t)0;
	awakeItemId = (int32_t)0;
	awakeCostNum = (int32_t)0;
	return 0;
}

int skillskill_s::ResumeInit() {
	return 0;
}

void skillskill_s::write_to_pbmsg(::proto_ff::skillskill & msg) const {
	msg.set_skillid((int64_t)skillID);
	msg.set_name((const char*)name.Get());
	msg.set_skilltype((int32_t)skillType);
	msg.set_group((int32_t)group);
	msg.set_position((int32_t)position);
	msg.set_displacetime((int32_t)displaceTime);
	msg.set_displacesign((int32_t)displaceSign);
	msg.set_displacespeed((const char*)displaceSpeed.Get());
	msg.set_distimes((const char*)disTimes.Get());
	msg.set_breaktype((int32_t)breakType);
	msg.set_cdskill((int32_t)cdSkill);
	msg.set_relation((int64_t)Relation);
	msg.set_unlockcondition((const char*)unlockCondition.Get());
	msg.set_type((int32_t)type);
	msg.set_cd((int32_t)cd);
	msg.set_nolock((int32_t)noLock);
	msg.set_priority((int32_t)priority);
	msg.set_fighting((const char*)fighting.Get());
	msg.set_fightingparama((float)fightingParama);
	msg.set_releasetype((int32_t)releaseType);
	msg.set_processtypes((int32_t)processTypes);
	msg.set_flyspeed((int32_t)flySpeed);
	msg.set_acttime((int32_t)actTime);
	msg.set_readytime((int32_t)readyTime);
	msg.set_attacktime((int32_t)attackTime);
	msg.set_damagetime((const char*)damageTime.Get());
	msg.set_attackdistance((int32_t)attackDistance);
	msg.set_rangetype((int32_t)rangeType);
	msg.set_rangetypevalue((const char*)rangeTypeValue.Get());
	msg.set_warn((int32_t)warn);
	msg.set_dazetime((int32_t)dazeTime);
	msg.set_warntime((int32_t)warnTime);
	msg.set_infomationid((const char*)infomationId.Get());
	msg.set_attackmindistance((int32_t)attackMinDistance);
	msg.set_goalmaxnum((int32_t)goalMaxNum);
	msg.set_goalmaxnummonster((int32_t)goalMaxNumMonster);
	msg.set_damagetype((int32_t)damageType);
	msg.set_damagerate((int32_t)damageRate);
	msg.set_awakedamagerate((int32_t)awakeDamageRate);
	msg.set_advancetype1damagerate((int32_t)advanceType1DamageRate);
	msg.set_advancetype2damagerate((int32_t)advanceType2DamageRate);
	msg.set_advancetype3damagerate((int32_t)advanceType3DamageRate);
	msg.set_damagevalue((int32_t)damageValue);
	msg.set_damageparama((float)damageParama);
	msg.set_addhitrate((int32_t)addhitrate);
	msg.set_awakeitemid((int32_t)awakeItemId);
	msg.set_awakecostnum((int32_t)awakeCostNum);
	for(int32_t i = 0; i < (int32_t)advanceType1buff.GetSize() && i < advanceType1buff.GetMaxSize(); ++i) {
		::proto_ff::skillskilladvanceType1buffDesc* temp_advancetype1buff = msg.add_advancetype1buff();
		advanceType1buff[i].write_to_pbmsg(*temp_advancetype1buff);
	}
	for(int32_t i = 0; i < (int32_t)advanceType2buff.GetSize() && i < advanceType2buff.GetMaxSize(); ++i) {
		::proto_ff::skillskilladvanceType2buffDesc* temp_advancetype2buff = msg.add_advancetype2buff();
		advanceType2buff[i].write_to_pbmsg(*temp_advancetype2buff);
	}
	for(int32_t i = 0; i < (int32_t)awakebuff.GetSize() && i < awakebuff.GetMaxSize(); ++i) {
		::proto_ff::skillskillawakebuffDesc* temp_awakebuff = msg.add_awakebuff();
		awakebuff[i].write_to_pbmsg(*temp_awakebuff);
	}
	for(int32_t i = 0; i < (int32_t)advanceType3buff.GetSize() && i < advanceType3buff.GetMaxSize(); ++i) {
		::proto_ff::skillskilladvanceType3buffDesc* temp_advancetype3buff = msg.add_advancetype3buff();
		advanceType3buff[i].write_to_pbmsg(*temp_advancetype3buff);
	}
	for(int32_t i = 0; i < (int32_t)buff.GetSize() && i < buff.GetMaxSize(); ++i) {
		::proto_ff::skillskillbuffDesc* temp_buff = msg.add_buff();
		buff[i].write_to_pbmsg(*temp_buff);
	}
}

void skillskill_s::read_from_pbmsg(const ::proto_ff::skillskill & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct skillskill_s));
	skillID = msg.skillid();
	name.Copy(msg.name());
	skillType = msg.skilltype();
	group = msg.group();
	position = msg.position();
	displaceTime = msg.displacetime();
	displaceSign = msg.displacesign();
	displaceSpeed.Copy(msg.displacespeed());
	disTimes.Copy(msg.distimes());
	breakType = msg.breaktype();
	cdSkill = msg.cdskill();
	Relation = msg.relation();
	unlockCondition.Copy(msg.unlockcondition());
	type = msg.type();
	cd = msg.cd();
	noLock = msg.nolock();
	priority = msg.priority();
	fighting.Copy(msg.fighting());
	fightingParama = msg.fightingparama();
	releaseType = msg.releasetype();
	processTypes = msg.processtypes();
	flySpeed = msg.flyspeed();
	actTime = msg.acttime();
	readyTime = msg.readytime();
	attackTime = msg.attacktime();
	damageTime.Copy(msg.damagetime());
	attackDistance = msg.attackdistance();
	rangeType = msg.rangetype();
	rangeTypeValue.Copy(msg.rangetypevalue());
	warn = msg.warn();
	dazeTime = msg.dazetime();
	warnTime = msg.warntime();
	infomationId.Copy(msg.infomationid());
	attackMinDistance = msg.attackmindistance();
	goalMaxNum = msg.goalmaxnum();
	goalMaxNumMonster = msg.goalmaxnummonster();
	damageType = msg.damagetype();
	damageRate = msg.damagerate();
	awakeDamageRate = msg.awakedamagerate();
	advanceType1DamageRate = msg.advancetype1damagerate();
	advanceType2DamageRate = msg.advancetype2damagerate();
	advanceType3DamageRate = msg.advancetype3damagerate();
	damageValue = msg.damagevalue();
	damageParama = msg.damageparama();
	addhitrate = msg.addhitrate();
	awakeItemId = msg.awakeitemid();
	awakeCostNum = msg.awakecostnum();
	advanceType1buff.SetSize(msg.advancetype1buff_size() > advanceType1buff.GetMaxSize() ? advanceType1buff.GetMaxSize() : msg.advancetype1buff_size());
	for(int32_t i = 0; i < (int32_t)advanceType1buff.GetSize(); ++i) {
		const ::proto_ff::skillskilladvanceType1buffDesc & temp_advancetype1buff = msg.advancetype1buff(i);
		advanceType1buff[i].read_from_pbmsg(temp_advancetype1buff);
	}
	advanceType2buff.SetSize(msg.advancetype2buff_size() > advanceType2buff.GetMaxSize() ? advanceType2buff.GetMaxSize() : msg.advancetype2buff_size());
	for(int32_t i = 0; i < (int32_t)advanceType2buff.GetSize(); ++i) {
		const ::proto_ff::skillskilladvanceType2buffDesc & temp_advancetype2buff = msg.advancetype2buff(i);
		advanceType2buff[i].read_from_pbmsg(temp_advancetype2buff);
	}
	awakebuff.SetSize(msg.awakebuff_size() > awakebuff.GetMaxSize() ? awakebuff.GetMaxSize() : msg.awakebuff_size());
	for(int32_t i = 0; i < (int32_t)awakebuff.GetSize(); ++i) {
		const ::proto_ff::skillskillawakebuffDesc & temp_awakebuff = msg.awakebuff(i);
		awakebuff[i].read_from_pbmsg(temp_awakebuff);
	}
	advanceType3buff.SetSize(msg.advancetype3buff_size() > advanceType3buff.GetMaxSize() ? advanceType3buff.GetMaxSize() : msg.advancetype3buff_size());
	for(int32_t i = 0; i < (int32_t)advanceType3buff.GetSize(); ++i) {
		const ::proto_ff::skillskilladvanceType3buffDesc & temp_advancetype3buff = msg.advancetype3buff(i);
		advanceType3buff[i].read_from_pbmsg(temp_advancetype3buff);
	}
	buff.SetSize(msg.buff_size() > buff.GetMaxSize() ? buff.GetMaxSize() : msg.buff_size());
	for(int32_t i = 0; i < (int32_t)buff.GetSize(); ++i) {
		const ::proto_ff::skillskillbuffDesc & temp_buff = msg.buff(i);
		buff[i].read_from_pbmsg(temp_buff);
	}
}

Sheet_skillskill_s::Sheet_skillskill_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_skillskill_s::CreateInit() {
	return 0;
}

int Sheet_skillskill_s::ResumeInit() {
	return 0;
}

void Sheet_skillskill_s::write_to_pbmsg(::proto_ff::Sheet_skillskill & msg) const {
	for(int32_t i = 0; i < (int32_t)skillskill_List.GetSize() && i < skillskill_List.GetMaxSize(); ++i) {
		::proto_ff::skillskill* temp_skillskill_list = msg.add_skillskill_list();
		skillskill_List[i].write_to_pbmsg(*temp_skillskill_list);
	}
}

void Sheet_skillskill_s::read_from_pbmsg(const ::proto_ff::Sheet_skillskill & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_skillskill_s));
	skillskill_List.SetSize(msg.skillskill_list_size() > skillskill_List.GetMaxSize() ? skillskill_List.GetMaxSize() : msg.skillskill_list_size());
	for(int32_t i = 0; i < (int32_t)skillskill_List.GetSize(); ++i) {
		const ::proto_ff::skillskill & temp_skillskill_list = msg.skillskill_list(i);
		skillskill_List[i].read_from_pbmsg(temp_skillskill_list);
	}
}

skillbuffUp_s::skillbuffUp_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int skillbuffUp_s::CreateInit() {
	id = (int32_t)0;
	AddStartProbability = (int32_t)0;
	attributeId = (int32_t)0;
	parama = (int32_t)0;
	return 0;
}

int skillbuffUp_s::ResumeInit() {
	return 0;
}

void skillbuffUp_s::write_to_pbmsg(::proto_ff::skillbuffUp & msg) const {
	msg.set_id((int32_t)id);
	msg.set_addstartprobability((int32_t)AddStartProbability);
	msg.set_attributeid((int32_t)attributeId);
	msg.set_parama((int32_t)parama);
}

void skillbuffUp_s::read_from_pbmsg(const ::proto_ff::skillbuffUp & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct skillbuffUp_s));
	id = msg.id();
	AddStartProbability = msg.addstartprobability();
	attributeId = msg.attributeid();
	parama = msg.parama();
}

Sheet_skillbuffUp_s::Sheet_skillbuffUp_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_skillbuffUp_s::CreateInit() {
	return 0;
}

int Sheet_skillbuffUp_s::ResumeInit() {
	return 0;
}

void Sheet_skillbuffUp_s::write_to_pbmsg(::proto_ff::Sheet_skillbuffUp & msg) const {
	for(int32_t i = 0; i < (int32_t)skillbuffUp_List.GetSize() && i < skillbuffUp_List.GetMaxSize(); ++i) {
		::proto_ff::skillbuffUp* temp_skillbuffup_list = msg.add_skillbuffup_list();
		skillbuffUp_List[i].write_to_pbmsg(*temp_skillbuffup_list);
	}
}

void Sheet_skillbuffUp_s::read_from_pbmsg(const ::proto_ff::Sheet_skillbuffUp & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_skillbuffUp_s));
	skillbuffUp_List.SetSize(msg.skillbuffup_list_size() > skillbuffUp_List.GetMaxSize() ? skillbuffUp_List.GetMaxSize() : msg.skillbuffup_list_size());
	for(int32_t i = 0; i < (int32_t)skillbuffUp_List.GetSize(); ++i) {
		const ::proto_ff::skillbuffUp & temp_skillbuffup_list = msg.skillbuffup_list(i);
		skillbuffUp_List[i].read_from_pbmsg(temp_skillbuffup_list);
	}
}

skillskillUp_s::skillskillUp_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int skillskillUp_s::CreateInit() {
	id = (int32_t)0;
	group = (int32_t)0;
	skillLv = (int32_t)0;
	roleLv = (int32_t)0;
	costItemId = (int64_t)0;
	costNum = (int32_t)0;
	return 0;
}

int skillskillUp_s::ResumeInit() {
	return 0;
}

void skillskillUp_s::write_to_pbmsg(::proto_ff::skillskillUp & msg) const {
	msg.set_id((int32_t)id);
	msg.set_group((int32_t)group);
	msg.set_skilllv((int32_t)skillLv);
	msg.set_skillids((const char*)skillIds.Get());
	msg.set_rolelv((int32_t)roleLv);
	msg.set_costitemid((int64_t)costItemId);
	msg.set_costnum((int32_t)costNum);
}

void skillskillUp_s::read_from_pbmsg(const ::proto_ff::skillskillUp & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct skillskillUp_s));
	id = msg.id();
	group = msg.group();
	skillLv = msg.skilllv();
	skillIds.Copy(msg.skillids());
	roleLv = msg.rolelv();
	costItemId = msg.costitemid();
	costNum = msg.costnum();
}

Sheet_skillskillUp_s::Sheet_skillskillUp_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_skillskillUp_s::CreateInit() {
	return 0;
}

int Sheet_skillskillUp_s::ResumeInit() {
	return 0;
}

void Sheet_skillskillUp_s::write_to_pbmsg(::proto_ff::Sheet_skillskillUp & msg) const {
	for(int32_t i = 0; i < (int32_t)skillskillUp_List.GetSize() && i < skillskillUp_List.GetMaxSize(); ++i) {
		::proto_ff::skillskillUp* temp_skillskillup_list = msg.add_skillskillup_list();
		skillskillUp_List[i].write_to_pbmsg(*temp_skillskillup_list);
	}
}

void Sheet_skillskillUp_s::read_from_pbmsg(const ::proto_ff::Sheet_skillskillUp & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_skillskillUp_s));
	skillskillUp_List.SetSize(msg.skillskillup_list_size() > skillskillUp_List.GetMaxSize() ? skillskillUp_List.GetMaxSize() : msg.skillskillup_list_size());
	for(int32_t i = 0; i < (int32_t)skillskillUp_List.GetSize(); ++i) {
		const ::proto_ff::skillskillUp & temp_skillskillup_list = msg.skillskillup_list(i);
		skillskillUp_List[i].read_from_pbmsg(temp_skillskillup_list);
	}
}

skillskillAwake_s::skillskillAwake_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int skillskillAwake_s::CreateInit() {
	skillId = (int32_t)0;
	costItemId = (int32_t)0;
	costNum = (int32_t)0;
	return 0;
}

int skillskillAwake_s::ResumeInit() {
	return 0;
}

void skillskillAwake_s::write_to_pbmsg(::proto_ff::skillskillAwake & msg) const {
	msg.set_skillid((int32_t)skillId);
	msg.set_costitemid((int32_t)costItemId);
	msg.set_costnum((int32_t)costNum);
}

void skillskillAwake_s::read_from_pbmsg(const ::proto_ff::skillskillAwake & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct skillskillAwake_s));
	skillId = msg.skillid();
	costItemId = msg.costitemid();
	costNum = msg.costnum();
}

Sheet_skillskillAwake_s::Sheet_skillskillAwake_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_skillskillAwake_s::CreateInit() {
	return 0;
}

int Sheet_skillskillAwake_s::ResumeInit() {
	return 0;
}

void Sheet_skillskillAwake_s::write_to_pbmsg(::proto_ff::Sheet_skillskillAwake & msg) const {
	for(int32_t i = 0; i < (int32_t)skillskillAwake_List.GetSize() && i < skillskillAwake_List.GetMaxSize(); ++i) {
		::proto_ff::skillskillAwake* temp_skillskillawake_list = msg.add_skillskillawake_list();
		skillskillAwake_List[i].write_to_pbmsg(*temp_skillskillawake_list);
	}
}

void Sheet_skillskillAwake_s::read_from_pbmsg(const ::proto_ff::Sheet_skillskillAwake & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_skillskillAwake_s));
	skillskillAwake_List.SetSize(msg.skillskillawake_list_size() > skillskillAwake_List.GetMaxSize() ? skillskillAwake_List.GetMaxSize() : msg.skillskillawake_list_size());
	for(int32_t i = 0; i < (int32_t)skillskillAwake_List.GetSize(); ++i) {
		const ::proto_ff::skillskillAwake & temp_skillskillawake_list = msg.skillskillawake_list(i);
		skillskillAwake_List[i].read_from_pbmsg(temp_skillskillawake_list);
	}
}

}