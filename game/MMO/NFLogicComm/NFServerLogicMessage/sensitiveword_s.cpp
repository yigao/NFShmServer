#include "sensitiveword_s.h"

namespace proto_ff_s {

sensitivewordsensitive_word_s::sensitivewordsensitive_word_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int sensitivewordsensitive_word_s::CreateInit() {
	id = (int32_t)0;
	return 0;
}

int sensitivewordsensitive_word_s::ResumeInit() {
	return 0;
}

void sensitivewordsensitive_word_s::write_to_pbmsg(::proto_ff::sensitivewordsensitive_word & msg) const {
	msg.set_id((int32_t)id);
	msg.set_sensitiveword((const char*)sensitiveWord.Get());
}

void sensitivewordsensitive_word_s::read_from_pbmsg(const ::proto_ff::sensitivewordsensitive_word & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct sensitivewordsensitive_word_s));
	id = msg.id();
	sensitiveWord.Copy(msg.sensitiveword());
}

Sheet_sensitivewordsensitive_word_s::Sheet_sensitivewordsensitive_word_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_sensitivewordsensitive_word_s::CreateInit() {
	return 0;
}

int Sheet_sensitivewordsensitive_word_s::ResumeInit() {
	return 0;
}

void Sheet_sensitivewordsensitive_word_s::write_to_pbmsg(::proto_ff::Sheet_sensitivewordsensitive_word & msg) const {
	for(int32_t i = 0; i < (int32_t)sensitivewordsensitive_word_List.GetSize() && i < sensitivewordsensitive_word_List.GetMaxSize(); ++i) {
		::proto_ff::sensitivewordsensitive_word* temp_sensitivewordsensitive_word_list = msg.add_sensitivewordsensitive_word_list();
		sensitivewordsensitive_word_List[i].write_to_pbmsg(*temp_sensitivewordsensitive_word_list);
	}
}

void Sheet_sensitivewordsensitive_word_s::read_from_pbmsg(const ::proto_ff::Sheet_sensitivewordsensitive_word & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_sensitivewordsensitive_word_s));
	sensitivewordsensitive_word_List.SetSize(msg.sensitivewordsensitive_word_list_size() > sensitivewordsensitive_word_List.GetMaxSize() ? sensitivewordsensitive_word_List.GetMaxSize() : msg.sensitivewordsensitive_word_list_size());
	for(int32_t i = 0; i < (int32_t)sensitivewordsensitive_word_List.GetSize(); ++i) {
		const ::proto_ff::sensitivewordsensitive_word & temp_sensitivewordsensitive_word_list = msg.sensitivewordsensitive_word_list(i);
		sensitivewordsensitive_word_List[i].read_from_pbmsg(temp_sensitivewordsensitive_word_list);
	}
}

sensitivewordrolesensitive_s::sensitivewordrolesensitive_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int sensitivewordrolesensitive_s::CreateInit() {
	id = (int32_t)0;
	return 0;
}

int sensitivewordrolesensitive_s::ResumeInit() {
	return 0;
}

void sensitivewordrolesensitive_s::write_to_pbmsg(::proto_ff::sensitivewordrolesensitive & msg) const {
	msg.set_id((int32_t)id);
	msg.set_sensitiveword((const char*)sensitiveWord.Get());
}

void sensitivewordrolesensitive_s::read_from_pbmsg(const ::proto_ff::sensitivewordrolesensitive & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct sensitivewordrolesensitive_s));
	id = msg.id();
	sensitiveWord.Copy(msg.sensitiveword());
}

Sheet_sensitivewordrolesensitive_s::Sheet_sensitivewordrolesensitive_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_sensitivewordrolesensitive_s::CreateInit() {
	return 0;
}

int Sheet_sensitivewordrolesensitive_s::ResumeInit() {
	return 0;
}

void Sheet_sensitivewordrolesensitive_s::write_to_pbmsg(::proto_ff::Sheet_sensitivewordrolesensitive & msg) const {
	for(int32_t i = 0; i < (int32_t)sensitivewordrolesensitive_List.GetSize() && i < sensitivewordrolesensitive_List.GetMaxSize(); ++i) {
		::proto_ff::sensitivewordrolesensitive* temp_sensitivewordrolesensitive_list = msg.add_sensitivewordrolesensitive_list();
		sensitivewordrolesensitive_List[i].write_to_pbmsg(*temp_sensitivewordrolesensitive_list);
	}
}

void Sheet_sensitivewordrolesensitive_s::read_from_pbmsg(const ::proto_ff::Sheet_sensitivewordrolesensitive & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_sensitivewordrolesensitive_s));
	sensitivewordrolesensitive_List.SetSize(msg.sensitivewordrolesensitive_list_size() > sensitivewordrolesensitive_List.GetMaxSize() ? sensitivewordrolesensitive_List.GetMaxSize() : msg.sensitivewordrolesensitive_list_size());
	for(int32_t i = 0; i < (int32_t)sensitivewordrolesensitive_List.GetSize(); ++i) {
		const ::proto_ff::sensitivewordrolesensitive & temp_sensitivewordrolesensitive_list = msg.sensitivewordrolesensitive_list(i);
		sensitivewordrolesensitive_List[i].read_from_pbmsg(temp_sensitivewordrolesensitive_list);
	}
}

}