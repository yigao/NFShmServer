#include "notice_s.h"

namespace proto_ff_s {

noticenotice_s::noticenotice_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int noticenotice_s::CreateInit() {
	noticeId = (int32_t)0;
	noitceOnoff = (int32_t)0;
	noticeType = (int32_t)0;
	levelRequire = (int32_t)0;
	return 0;
}

int noticenotice_s::ResumeInit() {
	return 0;
}

void noticenotice_s::write_to_pbmsg(::proto_ff::noticenotice & msg) const {
	msg.set_noticeid((int32_t)noticeId);
	msg.set_noitceonoff((int32_t)noitceOnoff);
	msg.set_noticetype((int32_t)noticeType);
	msg.set_opencycle((const char*)openCycle.Get());
	msg.set_time((const char*)time.Get());
	msg.set_levelrequire((int32_t)levelRequire);
	msg.set_endday((const char*)endDay.Get());
	msg.set_startday((const char*)startDay.Get());
	msg.set_noticetitle((const char*)noticeTitle.Get());
	msg.set_noticecontent((const char*)noticeContent.Get());
}

void noticenotice_s::read_from_pbmsg(const ::proto_ff::noticenotice & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct noticenotice_s));
	noticeId = msg.noticeid();
	noitceOnoff = msg.noitceonoff();
	noticeType = msg.noticetype();
	openCycle.Copy(msg.opencycle());
	time.Copy(msg.time());
	levelRequire = msg.levelrequire();
	endDay.Copy(msg.endday());
	startDay.Copy(msg.startday());
	noticeTitle.Copy(msg.noticetitle());
	noticeContent.Copy(msg.noticecontent());
}

Sheet_noticenotice_s::Sheet_noticenotice_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_noticenotice_s::CreateInit() {
	return 0;
}

int Sheet_noticenotice_s::ResumeInit() {
	return 0;
}

void Sheet_noticenotice_s::write_to_pbmsg(::proto_ff::Sheet_noticenotice & msg) const {
	for(int32_t i = 0; i < (int32_t)noticenotice_List.GetSize() && i < noticenotice_List.GetMaxSize(); ++i) {
		::proto_ff::noticenotice* temp_noticenotice_list = msg.add_noticenotice_list();
		noticenotice_List[i].write_to_pbmsg(*temp_noticenotice_list);
	}
}

void Sheet_noticenotice_s::read_from_pbmsg(const ::proto_ff::Sheet_noticenotice & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_noticenotice_s));
	noticenotice_List.SetSize(msg.noticenotice_list_size() > noticenotice_List.GetMaxSize() ? noticenotice_List.GetMaxSize() : msg.noticenotice_list_size());
	for(int32_t i = 0; i < (int32_t)noticenotice_List.GetSize(); ++i) {
		const ::proto_ff::noticenotice & temp_noticenotice_list = msg.noticenotice_list(i);
		noticenotice_List[i].read_from_pbmsg(temp_noticenotice_list);
	}
}

}