#include "attribute_s.h"

namespace proto_ff_s {

attributeattribute_s::attributeattribute_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int attributeattribute_s::CreateInit() {
	id = (int32_t)0;
	percent = (int32_t)0;
	power = (float)0;
	return 0;
}

int attributeattribute_s::ResumeInit() {
	return 0;
}

void attributeattribute_s::write_to_pbmsg(::proto_ff::attributeattribute & msg) const {
	msg.set_id((int32_t)id);
	msg.set_percent((int32_t)percent);
	msg.set_power((float)power);
}

void attributeattribute_s::read_from_pbmsg(const ::proto_ff::attributeattribute & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct attributeattribute_s));
	id = msg.id();
	percent = msg.percent();
	power = msg.power();
}

Sheet_attributeattribute_s::Sheet_attributeattribute_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_attributeattribute_s::CreateInit() {
	return 0;
}

int Sheet_attributeattribute_s::ResumeInit() {
	return 0;
}

void Sheet_attributeattribute_s::write_to_pbmsg(::proto_ff::Sheet_attributeattribute & msg) const {
	for(int32_t i = 0; i < (int32_t)attributeattribute_List.GetSize() && i < attributeattribute_List.GetMaxSize(); ++i) {
		::proto_ff::attributeattribute* temp_attributeattribute_list = msg.add_attributeattribute_list();
		attributeattribute_List[i].write_to_pbmsg(*temp_attributeattribute_list);
	}
}

void Sheet_attributeattribute_s::read_from_pbmsg(const ::proto_ff::Sheet_attributeattribute & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_attributeattribute_s));
	attributeattribute_List.SetSize(msg.attributeattribute_list_size() > attributeattribute_List.GetMaxSize() ? attributeattribute_List.GetMaxSize() : msg.attributeattribute_list_size());
	for(int32_t i = 0; i < (int32_t)attributeattribute_List.GetSize(); ++i) {
		const ::proto_ff::attributeattribute & temp_attributeattribute_list = msg.attributeattribute_list(i);
		attributeattribute_List[i].read_from_pbmsg(temp_attributeattribute_list);
	}
}

attributesuppress_s::attributesuppress_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int attributesuppress_s::CreateInit() {
	lvlDiff = (int32_t)0;
	hitSupPve = (int32_t)0;
	critSupPve = (int32_t)0;
	killSupPve = (int32_t)0;
	stateSupPve = (int32_t)0;
	lvSupPve = (int32_t)0;
	hitSupPvp = (int32_t)0;
	critSupPvp = (int32_t)0;
	killSupPvp = (int32_t)0;
	stateSupPvp = (int32_t)0;
	lvSupPvp = (int32_t)0;
	return 0;
}

int attributesuppress_s::ResumeInit() {
	return 0;
}

void attributesuppress_s::write_to_pbmsg(::proto_ff::attributesuppress & msg) const {
	msg.set_lvldiff((int32_t)lvlDiff);
	msg.set_hitsuppve((int32_t)hitSupPve);
	msg.set_critsuppve((int32_t)critSupPve);
	msg.set_killsuppve((int32_t)killSupPve);
	msg.set_statesuppve((int32_t)stateSupPve);
	msg.set_lvsuppve((int32_t)lvSupPve);
	msg.set_hitsuppvp((int32_t)hitSupPvp);
	msg.set_critsuppvp((int32_t)critSupPvp);
	msg.set_killsuppvp((int32_t)killSupPvp);
	msg.set_statesuppvp((int32_t)stateSupPvp);
	msg.set_lvsuppvp((int32_t)lvSupPvp);
}

void attributesuppress_s::read_from_pbmsg(const ::proto_ff::attributesuppress & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct attributesuppress_s));
	lvlDiff = msg.lvldiff();
	hitSupPve = msg.hitsuppve();
	critSupPve = msg.critsuppve();
	killSupPve = msg.killsuppve();
	stateSupPve = msg.statesuppve();
	lvSupPve = msg.lvsuppve();
	hitSupPvp = msg.hitsuppvp();
	critSupPvp = msg.critsuppvp();
	killSupPvp = msg.killsuppvp();
	stateSupPvp = msg.statesuppvp();
	lvSupPvp = msg.lvsuppvp();
}

Sheet_attributesuppress_s::Sheet_attributesuppress_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_attributesuppress_s::CreateInit() {
	return 0;
}

int Sheet_attributesuppress_s::ResumeInit() {
	return 0;
}

void Sheet_attributesuppress_s::write_to_pbmsg(::proto_ff::Sheet_attributesuppress & msg) const {
	for(int32_t i = 0; i < (int32_t)attributesuppress_List.GetSize() && i < attributesuppress_List.GetMaxSize(); ++i) {
		::proto_ff::attributesuppress* temp_attributesuppress_list = msg.add_attributesuppress_list();
		attributesuppress_List[i].write_to_pbmsg(*temp_attributesuppress_list);
	}
}

void Sheet_attributesuppress_s::read_from_pbmsg(const ::proto_ff::Sheet_attributesuppress & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_attributesuppress_s));
	attributesuppress_List.SetSize(msg.attributesuppress_list_size() > attributesuppress_List.GetMaxSize() ? attributesuppress_List.GetMaxSize() : msg.attributesuppress_list_size());
	for(int32_t i = 0; i < (int32_t)attributesuppress_List.GetSize(); ++i) {
		const ::proto_ff::attributesuppress & temp_attributesuppress_list = msg.attributesuppress_list(i);
		attributesuppress_List[i].read_from_pbmsg(temp_attributesuppress_list);
	}
}

attributepowersup_s::attributepowersup_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int attributepowersup_s::CreateInit() {
	powerDiff = (int32_t)0;
	powerSupPve = (int32_t)0;
	powerSupPvp = (int32_t)0;
	return 0;
}

int attributepowersup_s::ResumeInit() {
	return 0;
}

void attributepowersup_s::write_to_pbmsg(::proto_ff::attributepowersup & msg) const {
	msg.set_powerdiff((int32_t)powerDiff);
	msg.set_powersuppve((int32_t)powerSupPve);
	msg.set_powersuppvp((int32_t)powerSupPvp);
}

void attributepowersup_s::read_from_pbmsg(const ::proto_ff::attributepowersup & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct attributepowersup_s));
	powerDiff = msg.powerdiff();
	powerSupPve = msg.powersuppve();
	powerSupPvp = msg.powersuppvp();
}

Sheet_attributepowersup_s::Sheet_attributepowersup_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_attributepowersup_s::CreateInit() {
	return 0;
}

int Sheet_attributepowersup_s::ResumeInit() {
	return 0;
}

void Sheet_attributepowersup_s::write_to_pbmsg(::proto_ff::Sheet_attributepowersup & msg) const {
	for(int32_t i = 0; i < (int32_t)attributepowersup_List.GetSize() && i < attributepowersup_List.GetMaxSize(); ++i) {
		::proto_ff::attributepowersup* temp_attributepowersup_list = msg.add_attributepowersup_list();
		attributepowersup_List[i].write_to_pbmsg(*temp_attributepowersup_list);
	}
}

void Sheet_attributepowersup_s::read_from_pbmsg(const ::proto_ff::Sheet_attributepowersup & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_attributepowersup_s));
	attributepowersup_List.SetSize(msg.attributepowersup_list_size() > attributepowersup_List.GetMaxSize() ? attributepowersup_List.GetMaxSize() : msg.attributepowersup_list_size());
	for(int32_t i = 0; i < (int32_t)attributepowersup_List.GetSize(); ++i) {
		const ::proto_ff::attributepowersup & temp_attributepowersup_list = msg.attributepowersup_list(i);
		attributepowersup_List[i].read_from_pbmsg(temp_attributepowersup_list);
	}
}

}