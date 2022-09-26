#include "chat_s.h"

namespace proto_ff_s {

chatchat_s::chatchat_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int chatchat_s::CreateInit() {
	chatId = (int64_t)0;
	chatType = (int32_t)0;
	showTime = (int32_t)0;
	channel = (int32_t)0;
	CrossService = (int32_t)0;
	return 0;
}

int chatchat_s::ResumeInit() {
	return 0;
}

void chatchat_s::write_to_pbmsg(::proto_ff::chatchat & msg) const {
	msg.set_chatid((int64_t)chatId);
	msg.set_chattype((int32_t)chatType);
	msg.set_showtime((int32_t)showTime);
	msg.set_chatcontent((const char*)chatContent.Get());
	msg.set_channel((int32_t)channel);
	msg.set_crossservice((int32_t)CrossService);
}

void chatchat_s::read_from_pbmsg(const ::proto_ff::chatchat & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct chatchat_s));
	chatId = msg.chatid();
	chatType = msg.chattype();
	showTime = msg.showtime();
	chatContent.Copy(msg.chatcontent());
	channel = msg.channel();
	CrossService = msg.crossservice();
}

Sheet_chatchat_s::Sheet_chatchat_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_chatchat_s::CreateInit() {
	return 0;
}

int Sheet_chatchat_s::ResumeInit() {
	return 0;
}

void Sheet_chatchat_s::write_to_pbmsg(::proto_ff::Sheet_chatchat & msg) const {
	for(int32_t i = 0; i < (int32_t)chatchat_List.GetSize() && i < chatchat_List.GetMaxSize(); ++i) {
		::proto_ff::chatchat* temp_chatchat_list = msg.add_chatchat_list();
		chatchat_List[i].write_to_pbmsg(*temp_chatchat_list);
	}
}

void Sheet_chatchat_s::read_from_pbmsg(const ::proto_ff::Sheet_chatchat & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_chatchat_s));
	chatchat_List.SetSize(msg.chatchat_list_size() > chatchat_List.GetMaxSize() ? chatchat_List.GetMaxSize() : msg.chatchat_list_size());
	for(int32_t i = 0; i < (int32_t)chatchat_List.GetSize(); ++i) {
		const ::proto_ff::chatchat & temp_chatchat_list = msg.chatchat_list(i);
		chatchat_List[i].read_from_pbmsg(temp_chatchat_list);
	}
}

chatspecialchat_s::chatspecialchat_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int chatspecialchat_s::CreateInit() {
	type = (int32_t)0;
	chat_Id = (int64_t)0;
	return 0;
}

int chatspecialchat_s::ResumeInit() {
	return 0;
}

void chatspecialchat_s::write_to_pbmsg(::proto_ff::chatspecialchat & msg) const {
	msg.set_type((int32_t)type);
	msg.set_parama((const char*)parama.Get());
	msg.set_paramb((const char*)paramb.Get());
	msg.set_chat_id((int64_t)chat_Id);
}

void chatspecialchat_s::read_from_pbmsg(const ::proto_ff::chatspecialchat & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct chatspecialchat_s));
	type = msg.type();
	parama.Copy(msg.parama());
	paramb.Copy(msg.paramb());
	chat_Id = msg.chat_id();
}

Sheet_chatspecialchat_s::Sheet_chatspecialchat_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_chatspecialchat_s::CreateInit() {
	return 0;
}

int Sheet_chatspecialchat_s::ResumeInit() {
	return 0;
}

void Sheet_chatspecialchat_s::write_to_pbmsg(::proto_ff::Sheet_chatspecialchat & msg) const {
	for(int32_t i = 0; i < (int32_t)chatspecialchat_List.GetSize() && i < chatspecialchat_List.GetMaxSize(); ++i) {
		::proto_ff::chatspecialchat* temp_chatspecialchat_list = msg.add_chatspecialchat_list();
		chatspecialchat_List[i].write_to_pbmsg(*temp_chatspecialchat_list);
	}
}

void Sheet_chatspecialchat_s::read_from_pbmsg(const ::proto_ff::Sheet_chatspecialchat & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_chatspecialchat_s));
	chatspecialchat_List.SetSize(msg.chatspecialchat_list_size() > chatspecialchat_List.GetMaxSize() ? chatspecialchat_List.GetMaxSize() : msg.chatspecialchat_list_size());
	for(int32_t i = 0; i < (int32_t)chatspecialchat_List.GetSize(); ++i) {
		const ::proto_ff::chatspecialchat & temp_chatspecialchat_list = msg.chatspecialchat_list(i);
		chatspecialchat_List[i].read_from_pbmsg(temp_chatspecialchat_list);
	}
}

}