#include "skill_s.h"

namespace proto_ff_s {

skillskillstateBagDesc_s::skillskillstateBagDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int skillskillstateBagDesc_s::CreateInit() {
	Target = (int32_t)0;
	Point = (int32_t)0;
	Type = (int32_t)0;
	ID = (int64_t)0;
	return 0;
}

int skillskillstateBagDesc_s::ResumeInit() {
	return 0;
}

void skillskillstateBagDesc_s::write_to_pbmsg(::proto_ff::skillskillstateBagDesc & msg) const {
	msg.set_target((int32_t)Target);
	msg.set_point((int32_t)Point);
	msg.set_parameter((const char*)Parameter.Get());
	msg.set_rate((const char*)Rate.Get());
	msg.set_time((const char*)Time.Get());
	msg.set_type((int32_t)Type);
	msg.set_id((int64_t)ID);
}

void skillskillstateBagDesc_s::read_from_pbmsg(const ::proto_ff::skillskillstateBagDesc & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct skillskillstateBagDesc_s));
	Target = msg.target();
	Point = msg.point();
	Parameter.Copy(msg.parameter());
	Rate.Copy(msg.rate());
	Time.Copy(msg.time());
	Type = msg.type();
	ID = msg.id();
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
	specialSkill = (int32_t)0;
	cdSkill = (int32_t)0;
	Relation = (int64_t)0;
	AddSkill = (int64_t)0;
	AddSkillTime = (int32_t)0;
	unlockLevel = (int32_t)0;
	type = (int32_t)0;
	cd = (int32_t)0;
	priority = (int32_t)0;
	releaseType = (int32_t)0;
	processTypes = (int32_t)0;
	flySpeed = (int32_t)0;
	readyTime = (int32_t)0;
	attackTime = (int32_t)0;
	displaceTime = (int32_t)0;
	displaceSign = (int32_t)0;
	attackDistance = (int32_t)0;
	rangeType = (int32_t)0;
	warn = (int32_t)0;
	dazeTime = (int32_t)0;
	warnTime = (int32_t)0;
	summonType = (int32_t)0;
	attackMinDistance = (int32_t)0;
	goalMaxNum = (int32_t)0;
	damageType = (int32_t)0;
	addhitrate = (int32_t)0;
	return 0;
}

int skillskill_s::ResumeInit() {
	return 0;
}

void skillskill_s::write_to_pbmsg(::proto_ff::skillskill & msg) const {
	msg.set_skillid((int64_t)skillID);
	msg.set_name((const char*)name.Get());
	msg.set_skilltype((int32_t)skillType);
	msg.set_specialskill((int32_t)specialSkill);
	msg.set_cdskill((int32_t)cdSkill);
	msg.set_relation((int64_t)Relation);
	msg.set_addskill((int64_t)AddSkill);
	msg.set_addskilltime((int32_t)AddSkillTime);
	msg.set_unlocklevel((int32_t)unlockLevel);
	msg.set_type((int32_t)type);
	msg.set_cd((int32_t)cd);
	msg.set_priority((int32_t)priority);
	msg.set_fighting((const char*)fighting.Get());
	msg.set_releasetype((int32_t)releaseType);
	msg.set_processtypes((int32_t)processTypes);
	msg.set_flyspeed((int32_t)flySpeed);
	msg.set_readytime((int32_t)readyTime);
	msg.set_attacktime((int32_t)attackTime);
	msg.set_damagetime((const char*)damageTime.Get());
	msg.set_displacetime((int32_t)displaceTime);
	msg.set_displacesign((int32_t)displaceSign);
	msg.set_displacespeed((const char*)displaceSpeed.Get());
	msg.set_distimes((const char*)disTimes.Get());
	msg.set_attackdistance((int32_t)attackDistance);
	msg.set_rangetype((int32_t)rangeType);
	msg.set_rangetypevalue((const char*)rangeTypeValue.Get());
	msg.set_warn((int32_t)warn);
	msg.set_dazetime((int32_t)dazeTime);
	msg.set_warntime((int32_t)warnTime);
	msg.set_infomationid((const char*)infomationId.Get());
	msg.set_summontype((int32_t)summonType);
	msg.set_summonvalue((const char*)summonValue.Get());
	msg.set_attackmindistance((int32_t)attackMinDistance);
	msg.set_goalmaxnum((int32_t)goalMaxNum);
	msg.set_damagetype((int32_t)damageType);
	msg.set_attackvalue((const char*)attackValue.Get());
	msg.set_attackrate((const char*)attackRate.Get());
	msg.set_damagevalue((const char*)damageValue.Get());
	msg.set_damagerate((const char*)damageRate.Get());
	msg.set_addhitrate((int32_t)addhitrate);
	for(int32_t i = 0; i < (int32_t)stateBag.GetSize() && i < stateBag.GetMaxSize(); ++i) {
		::proto_ff::skillskillstateBagDesc* temp_statebag = msg.add_statebag();
		stateBag[i].write_to_pbmsg(*temp_statebag);
	}
}

void skillskill_s::read_from_pbmsg(const ::proto_ff::skillskill & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct skillskill_s));
	skillID = msg.skillid();
	name.Copy(msg.name());
	skillType = msg.skilltype();
	specialSkill = msg.specialskill();
	cdSkill = msg.cdskill();
	Relation = msg.relation();
	AddSkill = msg.addskill();
	AddSkillTime = msg.addskilltime();
	unlockLevel = msg.unlocklevel();
	type = msg.type();
	cd = msg.cd();
	priority = msg.priority();
	fighting.Copy(msg.fighting());
	releaseType = msg.releasetype();
	processTypes = msg.processtypes();
	flySpeed = msg.flyspeed();
	readyTime = msg.readytime();
	attackTime = msg.attacktime();
	damageTime.Copy(msg.damagetime());
	displaceTime = msg.displacetime();
	displaceSign = msg.displacesign();
	displaceSpeed.Copy(msg.displacespeed());
	disTimes.Copy(msg.distimes());
	attackDistance = msg.attackdistance();
	rangeType = msg.rangetype();
	rangeTypeValue.Copy(msg.rangetypevalue());
	warn = msg.warn();
	dazeTime = msg.dazetime();
	warnTime = msg.warntime();
	infomationId.Copy(msg.infomationid());
	summonType = msg.summontype();
	summonValue.Copy(msg.summonvalue());
	attackMinDistance = msg.attackmindistance();
	goalMaxNum = msg.goalmaxnum();
	damageType = msg.damagetype();
	attackValue.Copy(msg.attackvalue());
	attackRate.Copy(msg.attackrate());
	damageValue.Copy(msg.damagevalue());
	damageRate.Copy(msg.damagerate());
	addhitrate = msg.addhitrate();
	stateBag.SetSize(msg.statebag_size() > stateBag.GetMaxSize() ? stateBag.GetMaxSize() : msg.statebag_size());
	for(int32_t i = 0; i < (int32_t)stateBag.GetSize(); ++i) {
		const ::proto_ff::skillskillstateBagDesc & temp_statebag = msg.statebag(i);
		stateBag[i].read_from_pbmsg(temp_statebag);
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

skillbuffeffectDesc_s::skillbuffeffectDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int skillbuffeffectDesc_s::CreateInit() {
	Type = (int32_t)0;
	return 0;
}

int skillbuffeffectDesc_s::ResumeInit() {
	return 0;
}

void skillbuffeffectDesc_s::write_to_pbmsg(::proto_ff::skillbuffeffectDesc & msg) const {
	msg.set_type((int32_t)Type);
	msg.set_param((const char*)Param.Get());
}

void skillbuffeffectDesc_s::read_from_pbmsg(const ::proto_ff::skillbuffeffectDesc & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct skillbuffeffectDesc_s));
	Type = msg.type();
	Param.Copy(msg.param());
}

skillbuff_s::skillbuff_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int skillbuff_s::CreateInit() {
	stateBagID = (int64_t)0;
	startType = (int32_t)0;
	startProbability = (int32_t)0;
	save = (int32_t)0;
	label = (int32_t)0;
	mask = (int32_t)0;
	return 0;
}

int skillbuff_s::ResumeInit() {
	return 0;
}

void skillbuff_s::write_to_pbmsg(::proto_ff::skillbuff & msg) const {
	msg.set_statebagid((int64_t)stateBagID);
	msg.set_statebagname((const char*)stateBagName.Get());
	msg.set_statebagicon((const char*)stateBagIcon.Get());
	msg.set_effectresources((const char*)effectResources.Get());
	msg.set_starttype((int32_t)startType);
	msg.set_startprobability((int32_t)startProbability);
	msg.set_starttypevalue((const char*)startTypeValue.Get());
	msg.set_endtype((const char*)endType.Get());
	msg.set_save((int32_t)save);
	msg.set_statebagrule((const char*)stateBagRule.Get());
	msg.set_label((int32_t)label);
	msg.set_mask((int32_t)mask);
	msg.set_statebagcd((const char*)stateBagCd.Get());
	for(int32_t i = 0; i < (int32_t)effect.GetSize() && i < effect.GetMaxSize(); ++i) {
		::proto_ff::skillbuffeffectDesc* temp_effect = msg.add_effect();
		effect[i].write_to_pbmsg(*temp_effect);
	}
}

void skillbuff_s::read_from_pbmsg(const ::proto_ff::skillbuff & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct skillbuff_s));
	stateBagID = msg.statebagid();
	stateBagName.Copy(msg.statebagname());
	stateBagIcon.Copy(msg.statebagicon());
	effectResources.Copy(msg.effectresources());
	startType = msg.starttype();
	startProbability = msg.startprobability();
	startTypeValue.Copy(msg.starttypevalue());
	endType.Copy(msg.endtype());
	save = msg.save();
	stateBagRule.Copy(msg.statebagrule());
	label = msg.label();
	mask = msg.mask();
	stateBagCd.Copy(msg.statebagcd());
	effect.SetSize(msg.effect_size() > effect.GetMaxSize() ? effect.GetMaxSize() : msg.effect_size());
	for(int32_t i = 0; i < (int32_t)effect.GetSize(); ++i) {
		const ::proto_ff::skillbuffeffectDesc & temp_effect = msg.effect(i);
		effect[i].read_from_pbmsg(temp_effect);
	}
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

}