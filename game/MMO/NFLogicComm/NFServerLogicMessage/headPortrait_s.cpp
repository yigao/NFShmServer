#include "headPortrait_s.h"

namespace proto_ff_s {

headPortraitheadattributeDesc_s::headPortraitheadattributeDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int headPortraitheadattributeDesc_s::CreateInit() {
	type = (int32_t)0;
	value = (int32_t)0;
	return 0;
}

int headPortraitheadattributeDesc_s::ResumeInit() {
	return 0;
}

void headPortraitheadattributeDesc_s::write_to_pbmsg(::proto_ff::headPortraitheadattributeDesc & msg) const {
	msg.set_type((int32_t)type);
	msg.set_value((int32_t)value);
}

void headPortraitheadattributeDesc_s::read_from_pbmsg(const ::proto_ff::headPortraitheadattributeDesc & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct headPortraitheadattributeDesc_s));
	type = msg.type();
	value = msg.value();
}

headPortraithead_s::headPortraithead_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int headPortraithead_s::CreateInit() {
	ID = (int64_t)0;
	quality = (int32_t)0;
	activationItem = (int64_t)0;
	activationNum = (int32_t)0;
	starId = (int64_t)0;
	starUp = (int32_t)0;
	starBer = (int32_t)0;
	return 0;
}

int headPortraithead_s::ResumeInit() {
	return 0;
}

void headPortraithead_s::write_to_pbmsg(::proto_ff::headPortraithead & msg) const {
	msg.set_id((int64_t)ID);
	msg.set_name((const char*)name.Get());
	msg.set_quality((int32_t)quality);
	msg.set_professionlimit((const char*)professionLimit.Get());
	msg.set_activationitem((int64_t)activationItem);
	msg.set_activationnum((int32_t)activationNum);
	msg.set_starid((int64_t)starId);
	msg.set_starnum((const char*)starNum.Get());
	msg.set_starup((int32_t)starUp);
	msg.set_starber((int32_t)starBer);
	for(int32_t i = 0; i < (int32_t)attribute.GetSize() && i < attribute.GetMaxSize(); ++i) {
		::proto_ff::headPortraitheadattributeDesc* temp_attribute = msg.add_attribute();
		attribute[i].write_to_pbmsg(*temp_attribute);
	}
}

void headPortraithead_s::read_from_pbmsg(const ::proto_ff::headPortraithead & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct headPortraithead_s));
	ID = msg.id();
	name.Copy(msg.name());
	quality = msg.quality();
	professionLimit.Copy(msg.professionlimit());
	activationItem = msg.activationitem();
	activationNum = msg.activationnum();
	starId = msg.starid();
	starNum.Copy(msg.starnum());
	starUp = msg.starup();
	starBer = msg.starber();
	attribute.SetSize(msg.attribute_size() > attribute.GetMaxSize() ? attribute.GetMaxSize() : msg.attribute_size());
	for(int32_t i = 0; i < (int32_t)attribute.GetSize(); ++i) {
		const ::proto_ff::headPortraitheadattributeDesc & temp_attribute = msg.attribute(i);
		attribute[i].read_from_pbmsg(temp_attribute);
	}
}

Sheet_headPortraithead_s::Sheet_headPortraithead_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_headPortraithead_s::CreateInit() {
	return 0;
}

int Sheet_headPortraithead_s::ResumeInit() {
	return 0;
}

void Sheet_headPortraithead_s::write_to_pbmsg(::proto_ff::Sheet_headPortraithead & msg) const {
	for(int32_t i = 0; i < (int32_t)headPortraithead_List.GetSize() && i < headPortraithead_List.GetMaxSize(); ++i) {
		::proto_ff::headPortraithead* temp_headportraithead_list = msg.add_headportraithead_list();
		headPortraithead_List[i].write_to_pbmsg(*temp_headportraithead_list);
	}
}

void Sheet_headPortraithead_s::read_from_pbmsg(const ::proto_ff::Sheet_headPortraithead & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_headPortraithead_s));
	headPortraithead_List.SetSize(msg.headportraithead_list_size() > headPortraithead_List.GetMaxSize() ? headPortraithead_List.GetMaxSize() : msg.headportraithead_list_size());
	for(int32_t i = 0; i < (int32_t)headPortraithead_List.GetSize(); ++i) {
		const ::proto_ff::headPortraithead & temp_headportraithead_list = msg.headportraithead_list(i);
		headPortraithead_List[i].read_from_pbmsg(temp_headportraithead_list);
	}
}

headPortraitframeattributeDesc_s::headPortraitframeattributeDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int headPortraitframeattributeDesc_s::CreateInit() {
	type = (int32_t)0;
	value = (int32_t)0;
	return 0;
}

int headPortraitframeattributeDesc_s::ResumeInit() {
	return 0;
}

void headPortraitframeattributeDesc_s::write_to_pbmsg(::proto_ff::headPortraitframeattributeDesc & msg) const {
	msg.set_type((int32_t)type);
	msg.set_value((int32_t)value);
}

void headPortraitframeattributeDesc_s::read_from_pbmsg(const ::proto_ff::headPortraitframeattributeDesc & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct headPortraitframeattributeDesc_s));
	type = msg.type();
	value = msg.value();
}

headPortraitframe_s::headPortraitframe_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int headPortraitframe_s::CreateInit() {
	ID = (int64_t)0;
	quality = (int32_t)0;
	activationItem = (int64_t)0;
	activationNum = (int32_t)0;
	starId = (int64_t)0;
	starUp = (int32_t)0;
	starBer = (int32_t)0;
	return 0;
}

int headPortraitframe_s::ResumeInit() {
	return 0;
}

void headPortraitframe_s::write_to_pbmsg(::proto_ff::headPortraitframe & msg) const {
	msg.set_id((int64_t)ID);
	msg.set_name((const char*)name.Get());
	msg.set_quality((int32_t)quality);
	msg.set_professionlimit((const char*)professionLimit.Get());
	msg.set_activationitem((int64_t)activationItem);
	msg.set_activationnum((int32_t)activationNum);
	msg.set_starid((int64_t)starId);
	msg.set_starnum((const char*)starNum.Get());
	msg.set_starup((int32_t)starUp);
	msg.set_starber((int32_t)starBer);
	for(int32_t i = 0; i < (int32_t)attribute.GetSize() && i < attribute.GetMaxSize(); ++i) {
		::proto_ff::headPortraitframeattributeDesc* temp_attribute = msg.add_attribute();
		attribute[i].write_to_pbmsg(*temp_attribute);
	}
}

void headPortraitframe_s::read_from_pbmsg(const ::proto_ff::headPortraitframe & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct headPortraitframe_s));
	ID = msg.id();
	name.Copy(msg.name());
	quality = msg.quality();
	professionLimit.Copy(msg.professionlimit());
	activationItem = msg.activationitem();
	activationNum = msg.activationnum();
	starId = msg.starid();
	starNum.Copy(msg.starnum());
	starUp = msg.starup();
	starBer = msg.starber();
	attribute.SetSize(msg.attribute_size() > attribute.GetMaxSize() ? attribute.GetMaxSize() : msg.attribute_size());
	for(int32_t i = 0; i < (int32_t)attribute.GetSize(); ++i) {
		const ::proto_ff::headPortraitframeattributeDesc & temp_attribute = msg.attribute(i);
		attribute[i].read_from_pbmsg(temp_attribute);
	}
}

Sheet_headPortraitframe_s::Sheet_headPortraitframe_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_headPortraitframe_s::CreateInit() {
	return 0;
}

int Sheet_headPortraitframe_s::ResumeInit() {
	return 0;
}

void Sheet_headPortraitframe_s::write_to_pbmsg(::proto_ff::Sheet_headPortraitframe & msg) const {
	for(int32_t i = 0; i < (int32_t)headPortraitframe_List.GetSize() && i < headPortraitframe_List.GetMaxSize(); ++i) {
		::proto_ff::headPortraitframe* temp_headportraitframe_list = msg.add_headportraitframe_list();
		headPortraitframe_List[i].write_to_pbmsg(*temp_headportraitframe_list);
	}
}

void Sheet_headPortraitframe_s::read_from_pbmsg(const ::proto_ff::Sheet_headPortraitframe & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_headPortraitframe_s));
	headPortraitframe_List.SetSize(msg.headportraitframe_list_size() > headPortraitframe_List.GetMaxSize() ? headPortraitframe_List.GetMaxSize() : msg.headportraitframe_list_size());
	for(int32_t i = 0; i < (int32_t)headPortraitframe_List.GetSize(); ++i) {
		const ::proto_ff::headPortraitframe & temp_headportraitframe_list = msg.headportraitframe_list(i);
		headPortraitframe_List[i].read_from_pbmsg(temp_headportraitframe_list);
	}
}

headPortraitbubbleattributeDesc_s::headPortraitbubbleattributeDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int headPortraitbubbleattributeDesc_s::CreateInit() {
	type = (int32_t)0;
	value = (int32_t)0;
	return 0;
}

int headPortraitbubbleattributeDesc_s::ResumeInit() {
	return 0;
}

void headPortraitbubbleattributeDesc_s::write_to_pbmsg(::proto_ff::headPortraitbubbleattributeDesc & msg) const {
	msg.set_type((int32_t)type);
	msg.set_value((int32_t)value);
}

void headPortraitbubbleattributeDesc_s::read_from_pbmsg(const ::proto_ff::headPortraitbubbleattributeDesc & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct headPortraitbubbleattributeDesc_s));
	type = msg.type();
	value = msg.value();
}

headPortraitbubble_s::headPortraitbubble_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int headPortraitbubble_s::CreateInit() {
	ID = (int64_t)0;
	quality = (int32_t)0;
	activationItem = (int64_t)0;
	activationNum = (int32_t)0;
	starId = (int64_t)0;
	starUp = (int32_t)0;
	starBer = (int32_t)0;
	return 0;
}

int headPortraitbubble_s::ResumeInit() {
	return 0;
}

void headPortraitbubble_s::write_to_pbmsg(::proto_ff::headPortraitbubble & msg) const {
	msg.set_id((int64_t)ID);
	msg.set_name((const char*)name.Get());
	msg.set_quality((int32_t)quality);
	msg.set_professionlimit((const char*)professionLimit.Get());
	msg.set_activationitem((int64_t)activationItem);
	msg.set_activationnum((int32_t)activationNum);
	msg.set_starid((int64_t)starId);
	msg.set_starnum((const char*)starNum.Get());
	msg.set_starup((int32_t)starUp);
	msg.set_starber((int32_t)starBer);
	for(int32_t i = 0; i < (int32_t)attribute.GetSize() && i < attribute.GetMaxSize(); ++i) {
		::proto_ff::headPortraitbubbleattributeDesc* temp_attribute = msg.add_attribute();
		attribute[i].write_to_pbmsg(*temp_attribute);
	}
}

void headPortraitbubble_s::read_from_pbmsg(const ::proto_ff::headPortraitbubble & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct headPortraitbubble_s));
	ID = msg.id();
	name.Copy(msg.name());
	quality = msg.quality();
	professionLimit.Copy(msg.professionlimit());
	activationItem = msg.activationitem();
	activationNum = msg.activationnum();
	starId = msg.starid();
	starNum.Copy(msg.starnum());
	starUp = msg.starup();
	starBer = msg.starber();
	attribute.SetSize(msg.attribute_size() > attribute.GetMaxSize() ? attribute.GetMaxSize() : msg.attribute_size());
	for(int32_t i = 0; i < (int32_t)attribute.GetSize(); ++i) {
		const ::proto_ff::headPortraitbubbleattributeDesc & temp_attribute = msg.attribute(i);
		attribute[i].read_from_pbmsg(temp_attribute);
	}
}

Sheet_headPortraitbubble_s::Sheet_headPortraitbubble_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_headPortraitbubble_s::CreateInit() {
	return 0;
}

int Sheet_headPortraitbubble_s::ResumeInit() {
	return 0;
}

void Sheet_headPortraitbubble_s::write_to_pbmsg(::proto_ff::Sheet_headPortraitbubble & msg) const {
	for(int32_t i = 0; i < (int32_t)headPortraitbubble_List.GetSize() && i < headPortraitbubble_List.GetMaxSize(); ++i) {
		::proto_ff::headPortraitbubble* temp_headportraitbubble_list = msg.add_headportraitbubble_list();
		headPortraitbubble_List[i].write_to_pbmsg(*temp_headportraitbubble_list);
	}
}

void Sheet_headPortraitbubble_s::read_from_pbmsg(const ::proto_ff::Sheet_headPortraitbubble & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_headPortraitbubble_s));
	headPortraitbubble_List.SetSize(msg.headportraitbubble_list_size() > headPortraitbubble_List.GetMaxSize() ? headPortraitbubble_List.GetMaxSize() : msg.headportraitbubble_list_size());
	for(int32_t i = 0; i < (int32_t)headPortraitbubble_List.GetSize(); ++i) {
		const ::proto_ff::headPortraitbubble & temp_headportraitbubble_list = msg.headportraitbubble_list(i);
		headPortraitbubble_List[i].read_from_pbmsg(temp_headportraitbubble_list);
	}
}

}