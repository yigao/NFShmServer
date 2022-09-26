#include "lightAndShadow_s.h"

namespace proto_ff_s {

lightAndShadowcons_s::lightAndShadowcons_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int lightAndShadowcons_s::CreateInit() {
	ID = (int32_t)0;
	valuedata = (int64_t)0;
	return 0;
}

int lightAndShadowcons_s::ResumeInit() {
	return 0;
}

void lightAndShadowcons_s::write_to_pbmsg(::proto_ff::lightAndShadowcons & msg) const {
	msg.set_id((int32_t)ID);
	msg.set_valuedata((int64_t)valuedata);
	msg.set_stringdata((const char*)stringdata.Get());
}

void lightAndShadowcons_s::read_from_pbmsg(const ::proto_ff::lightAndShadowcons & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct lightAndShadowcons_s));
	ID = msg.id();
	valuedata = msg.valuedata();
	stringdata.Copy(msg.stringdata());
}

Sheet_lightAndShadowcons_s::Sheet_lightAndShadowcons_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_lightAndShadowcons_s::CreateInit() {
	return 0;
}

int Sheet_lightAndShadowcons_s::ResumeInit() {
	return 0;
}

void Sheet_lightAndShadowcons_s::write_to_pbmsg(::proto_ff::Sheet_lightAndShadowcons & msg) const {
	for(int32_t i = 0; i < (int32_t)lightAndShadowcons_List.GetSize() && i < lightAndShadowcons_List.GetMaxSize(); ++i) {
		::proto_ff::lightAndShadowcons* temp_lightandshadowcons_list = msg.add_lightandshadowcons_list();
		lightAndShadowcons_List[i].write_to_pbmsg(*temp_lightandshadowcons_list);
	}
}

void Sheet_lightAndShadowcons_s::read_from_pbmsg(const ::proto_ff::Sheet_lightAndShadowcons & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_lightAndShadowcons_s));
	lightAndShadowcons_List.SetSize(msg.lightandshadowcons_list_size() > lightAndShadowcons_List.GetMaxSize() ? lightAndShadowcons_List.GetMaxSize() : msg.lightandshadowcons_list_size());
	for(int32_t i = 0; i < (int32_t)lightAndShadowcons_List.GetSize(); ++i) {
		const ::proto_ff::lightAndShadowcons & temp_lightandshadowcons_list = msg.lightandshadowcons_list(i);
		lightAndShadowcons_List[i].read_from_pbmsg(temp_lightandshadowcons_list);
	}
}

lightAndShadowreward_s::lightAndShadowreward_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int lightAndShadowreward_s::CreateInit() {
	ID = (int32_t)0;
	goldMin = (int32_t)0;
	goldMax = (int32_t)0;
	winReward = (int64_t)0;
	winRewardNum = (int32_t)0;
	loseReward = (int64_t)0;
	loseRewardNum = (int32_t)0;
	return 0;
}

int lightAndShadowreward_s::ResumeInit() {
	return 0;
}

void lightAndShadowreward_s::write_to_pbmsg(::proto_ff::lightAndShadowreward & msg) const {
	msg.set_id((int32_t)ID);
	msg.set_goldmin((int32_t)goldMin);
	msg.set_goldmax((int32_t)goldMax);
	msg.set_winreward((int64_t)winReward);
	msg.set_winrewardnum((int32_t)winRewardNum);
	msg.set_losereward((int64_t)loseReward);
	msg.set_loserewardnum((int32_t)loseRewardNum);
}

void lightAndShadowreward_s::read_from_pbmsg(const ::proto_ff::lightAndShadowreward & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct lightAndShadowreward_s));
	ID = msg.id();
	goldMin = msg.goldmin();
	goldMax = msg.goldmax();
	winReward = msg.winreward();
	winRewardNum = msg.winrewardnum();
	loseReward = msg.losereward();
	loseRewardNum = msg.loserewardnum();
}

Sheet_lightAndShadowreward_s::Sheet_lightAndShadowreward_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_lightAndShadowreward_s::CreateInit() {
	return 0;
}

int Sheet_lightAndShadowreward_s::ResumeInit() {
	return 0;
}

void Sheet_lightAndShadowreward_s::write_to_pbmsg(::proto_ff::Sheet_lightAndShadowreward & msg) const {
	for(int32_t i = 0; i < (int32_t)lightAndShadowreward_List.GetSize() && i < lightAndShadowreward_List.GetMaxSize(); ++i) {
		::proto_ff::lightAndShadowreward* temp_lightandshadowreward_list = msg.add_lightandshadowreward_list();
		lightAndShadowreward_List[i].write_to_pbmsg(*temp_lightandshadowreward_list);
	}
}

void Sheet_lightAndShadowreward_s::read_from_pbmsg(const ::proto_ff::Sheet_lightAndShadowreward & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_lightAndShadowreward_s));
	lightAndShadowreward_List.SetSize(msg.lightandshadowreward_list_size() > lightAndShadowreward_List.GetMaxSize() ? lightAndShadowreward_List.GetMaxSize() : msg.lightandshadowreward_list_size());
	for(int32_t i = 0; i < (int32_t)lightAndShadowreward_List.GetSize(); ++i) {
		const ::proto_ff::lightAndShadowreward & temp_lightandshadowreward_list = msg.lightandshadowreward_list(i);
		lightAndShadowreward_List[i].read_from_pbmsg(temp_lightandshadowreward_list);
	}
}

}