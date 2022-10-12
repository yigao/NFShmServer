#include "ai_s.h"

namespace proto_ff_s {

aiaihpDesc_s::aiaihpDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int aiaihpDesc_s::CreateInit() {
	skill = (int64_t)0;
	percent = (int32_t)0;
	chat = (int64_t)0;
	return 0;
}

int aiaihpDesc_s::ResumeInit() {
	return 0;
}

void aiaihpDesc_s::write_to_pbmsg(::proto_ff::aiaihpDesc & msg) const {
	msg.set_skill((int64_t)skill);
	msg.set_percent((int32_t)percent);
	msg.set_chat((int64_t)chat);
}

void aiaihpDesc_s::read_from_pbmsg(const ::proto_ff::aiaihpDesc & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct aiaihpDesc_s));
	skill = msg.skill();
	percent = msg.percent();
	chat = msg.chat();
}

aiai_s::aiai_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int aiai_s::CreateInit() {
	id = (int64_t)0;
	type = (int32_t)0;
	isActive = (int32_t)0;
	returnType = (int32_t)0;
	view = (int32_t)0;
	isAttackedShowOff = (int32_t)0;
	pursueRange = (int32_t)0;
	actionRange = (int32_t)0;
	wakeupRadius = (int32_t)0;
	isAIWorkWhenNobody = (int32_t)0;
	bornEffectAIDelay = (int32_t)0;
	return 0;
}

int aiai_s::ResumeInit() {
	return 0;
}

void aiai_s::write_to_pbmsg(::proto_ff::aiai & msg) const {
	msg.set_id((int64_t)id);
	msg.set_type((int32_t)type);
	msg.set_deadhateremain((const char*)deadHateRemain.Get());
	msg.set_invisibleremain((const char*)invisibleRemain.Get());
	msg.set_isactive((int32_t)isActive);
	msg.set_returntype((int32_t)returnType);
	msg.set_view((int32_t)view);
	msg.set_isattackedshowoff((int32_t)isAttackedShowOff);
	msg.set_pursuerange((int32_t)pursueRange);
	msg.set_actionrange((int32_t)actionRange);
	msg.set_wakeupradius((int32_t)wakeupRadius);
	msg.set_isaiworkwhennobody((int32_t)isAIWorkWhenNobody);
	msg.set_borneffectaidelay((int32_t)bornEffectAIDelay);
	msg.set_initskills((const char*)initSkills.Get());
	for(int32_t i = 0; i < (int32_t)hp.GetSize() && i < hp.GetMaxSize(); ++i) {
		::proto_ff::aiaihpDesc* temp_hp = msg.add_hp();
		hp[i].write_to_pbmsg(*temp_hp);
	}
}

void aiai_s::read_from_pbmsg(const ::proto_ff::aiai & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct aiai_s));
	id = msg.id();
	type = msg.type();
	deadHateRemain.Copy(msg.deadhateremain());
	invisibleRemain.Copy(msg.invisibleremain());
	isActive = msg.isactive();
	returnType = msg.returntype();
	view = msg.view();
	isAttackedShowOff = msg.isattackedshowoff();
	pursueRange = msg.pursuerange();
	actionRange = msg.actionrange();
	wakeupRadius = msg.wakeupradius();
	isAIWorkWhenNobody = msg.isaiworkwhennobody();
	bornEffectAIDelay = msg.borneffectaidelay();
	initSkills.Copy(msg.initskills());
	hp.SetSize(msg.hp_size() > hp.GetMaxSize() ? hp.GetMaxSize() : msg.hp_size());
	for(int32_t i = 0; i < (int32_t)hp.GetSize(); ++i) {
		const ::proto_ff::aiaihpDesc & temp_hp = msg.hp(i);
		hp[i].read_from_pbmsg(temp_hp);
	}
}

Sheet_aiai_s::Sheet_aiai_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_aiai_s::CreateInit() {
	return 0;
}

int Sheet_aiai_s::ResumeInit() {
	return 0;
}

void Sheet_aiai_s::write_to_pbmsg(::proto_ff::Sheet_aiai & msg) const {
	for(int32_t i = 0; i < (int32_t)aiai_List.GetSize() && i < aiai_List.GetMaxSize(); ++i) {
		::proto_ff::aiai* temp_aiai_list = msg.add_aiai_list();
		aiai_List[i].write_to_pbmsg(*temp_aiai_list);
	}
}

void Sheet_aiai_s::read_from_pbmsg(const ::proto_ff::Sheet_aiai & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_aiai_s));
	aiai_List.SetSize(msg.aiai_list_size() > aiai_List.GetMaxSize() ? aiai_List.GetMaxSize() : msg.aiai_list_size());
	for(int32_t i = 0; i < (int32_t)aiai_List.GetSize(); ++i) {
		const ::proto_ff::aiai & temp_aiai_list = msg.aiai_list(i);
		aiai_List[i].read_from_pbmsg(temp_aiai_list);
	}
}

}