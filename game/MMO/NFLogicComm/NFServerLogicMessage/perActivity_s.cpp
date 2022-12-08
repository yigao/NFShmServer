#include "perActivity_s.h"

namespace proto_ff_s {

perActivityperActivity_s::perActivityperActivity_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int perActivityperActivity_s::CreateInit() {
	activeId = (int64_t)0;
	typeId = (int32_t)0;
	functionID = (int32_t)0;
	serverdelayTime = (int32_t)0;
	serverTime = (int32_t)0;
	openingTime = (int32_t)0;
	advanceTime = (int32_t)0;
	intervalTime = (int32_t)0;
	isCross = (int32_t)0;
	return 0;
}

int perActivityperActivity_s::ResumeInit() {
	return 0;
}

void perActivityperActivity_s::write_to_pbmsg(::proto_ff::perActivityperActivity & msg) const {
	msg.set_activeid((int64_t)activeId);
	msg.set_activename((const char*)activeName.Get());
	msg.set_typeid_((int32_t)typeId);
	msg.set_functionid((int32_t)functionID);
	msg.set_opeday((const char*)opeDay.Get());
	msg.set_closeday((const char*)closeDay.Get());
	msg.set_serverdelaytime((int32_t)serverdelayTime);
	msg.set_servertime((int32_t)serverTime);
	msg.set_openingtime((int32_t)openingTime);
	msg.set_advancetime((int32_t)advanceTime);
	msg.set_intervaltime((int32_t)intervalTime);
	msg.set_iscross((int32_t)isCross);
}

void perActivityperActivity_s::read_from_pbmsg(const ::proto_ff::perActivityperActivity & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct perActivityperActivity_s));
	activeId = msg.activeid();
	activeName.Copy(msg.activename());
	typeId = msg.typeid_();
	functionID = msg.functionid();
	opeDay.Copy(msg.opeday());
	closeDay.Copy(msg.closeday());
	serverdelayTime = msg.serverdelaytime();
	serverTime = msg.servertime();
	openingTime = msg.openingtime();
	advanceTime = msg.advancetime();
	intervalTime = msg.intervaltime();
	isCross = msg.iscross();
}

Sheet_perActivityperActivity_s::Sheet_perActivityperActivity_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_perActivityperActivity_s::CreateInit() {
	return 0;
}

int Sheet_perActivityperActivity_s::ResumeInit() {
	return 0;
}

void Sheet_perActivityperActivity_s::write_to_pbmsg(::proto_ff::Sheet_perActivityperActivity & msg) const {
	for(int32_t i = 0; i < (int32_t)perActivityperActivity_List.GetSize() && i < perActivityperActivity_List.GetMaxSize(); ++i) {
		::proto_ff::perActivityperActivity* temp_peractivityperactivity_list = msg.add_peractivityperactivity_list();
		perActivityperActivity_List[i].write_to_pbmsg(*temp_peractivityperactivity_list);
	}
}

void Sheet_perActivityperActivity_s::read_from_pbmsg(const ::proto_ff::Sheet_perActivityperActivity & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_perActivityperActivity_s));
	perActivityperActivity_List.SetSize(msg.peractivityperactivity_list_size() > perActivityperActivity_List.GetMaxSize() ? perActivityperActivity_List.GetMaxSize() : msg.peractivityperactivity_list_size());
	for(int32_t i = 0; i < (int32_t)perActivityperActivity_List.GetSize(); ++i) {
		const ::proto_ff::perActivityperActivity & temp_peractivityperactivity_list = msg.peractivityperactivity_list(i);
		perActivityperActivity_List[i].read_from_pbmsg(temp_peractivityperactivity_list);
	}
}

perActivityweek_s::perActivityweek_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int perActivityweek_s::CreateInit() {
	id = (int32_t)0;
	return 0;
}

int perActivityweek_s::ResumeInit() {
	return 0;
}

void perActivityweek_s::write_to_pbmsg(::proto_ff::perActivityweek & msg) const {
	msg.set_id((int32_t)id);
	msg.set_time((const char*)time.Get());
	for(int32_t i = 0; i < (int32_t)week.GetSize() && i < week.GetMaxSize(); ++i) {
		msg.add_week((const char*)week[i].Get());
	}
}

void perActivityweek_s::read_from_pbmsg(const ::proto_ff::perActivityweek & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct perActivityweek_s));
	id = msg.id();
	time.Copy(msg.time());
	week.SetSize(msg.week_size() > week.GetMaxSize() ? week.GetMaxSize() : msg.week_size());
	for(int32_t i = 0; i < (int32_t)week.GetSize(); ++i) {
		week[i].Copy(msg.week(i));
	}
}

Sheet_perActivityweek_s::Sheet_perActivityweek_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_perActivityweek_s::CreateInit() {
	return 0;
}

int Sheet_perActivityweek_s::ResumeInit() {
	return 0;
}

void Sheet_perActivityweek_s::write_to_pbmsg(::proto_ff::Sheet_perActivityweek & msg) const {
	for(int32_t i = 0; i < (int32_t)perActivityweek_List.GetSize() && i < perActivityweek_List.GetMaxSize(); ++i) {
		::proto_ff::perActivityweek* temp_peractivityweek_list = msg.add_peractivityweek_list();
		perActivityweek_List[i].write_to_pbmsg(*temp_peractivityweek_list);
	}
}

void Sheet_perActivityweek_s::read_from_pbmsg(const ::proto_ff::Sheet_perActivityweek & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_perActivityweek_s));
	perActivityweek_List.SetSize(msg.peractivityweek_list_size() > perActivityweek_List.GetMaxSize() ? perActivityweek_List.GetMaxSize() : msg.peractivityweek_list_size());
	for(int32_t i = 0; i < (int32_t)perActivityweek_List.GetSize(); ++i) {
		const ::proto_ff::perActivityweek & temp_peractivityweek_list = msg.peractivityweek_list(i);
		perActivityweek_List[i].read_from_pbmsg(temp_peractivityweek_list);
	}
}

}