#include "ResMeta_s.h"

namespace proto_ff_s {

MailDesc_s::MailDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int MailDesc_s::CreateInit() {
	id = (int32_t)0;
	type = (int32_t)0;
	start_time = (uint64_t)0;
	end_time = (uint64_t)0;
	add_gold = (int32_t)0;
	return 0;
}

int MailDesc_s::ResumeInit() {
	return 0;
}

void MailDesc_s::write_to_pbmsg(const struct MailDesc_s & obj, ::proto_ff::MailDesc & msg) {
	msg.set_id((int32_t)obj.id);
	msg.set_title((const char*)obj.title.Get());
	msg.set_type((int32_t)obj.type);
	msg.set_content((const char*)obj.content.Get());
	msg.set_send_name((const char*)obj.send_name.Get());
	msg.set_start_time_str((const char*)obj.start_time_str.Get());
	msg.set_end_time_str((const char*)obj.end_time_str.Get());
	msg.set_start_time((uint64_t)obj.start_time);
	msg.set_end_time((uint64_t)obj.end_time);
	msg.set_add_gold((int32_t)obj.add_gold);
}

void MailDesc_s::read_from_pbmsg(const ::proto_ff::MailDesc & msg, struct MailDesc_s & obj) {
	memset(&obj, 0, sizeof(struct MailDesc_s));
	obj.id = msg.id();
	obj.title.Copy(msg.title());
	obj.type = msg.type();
	obj.content.Copy(msg.content());
	obj.send_name.Copy(msg.send_name());
	obj.start_time_str.Copy(msg.start_time_str());
	obj.end_time_str.Copy(msg.end_time_str());
	obj.start_time = msg.start_time();
	obj.end_time = msg.end_time();
	obj.add_gold = msg.add_gold();
}

Sheet_MailDesc_s::Sheet_MailDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_MailDesc_s::CreateInit() {
	return 0;
}

int Sheet_MailDesc_s::ResumeInit() {
	return 0;
}

void Sheet_MailDesc_s::write_to_pbmsg(const struct Sheet_MailDesc_s & obj, ::proto_ff::Sheet_MailDesc & msg) {
	for(int32_t i = 0; i < obj.MailDesc_List.GetSize() && i < obj.MailDesc_List.GetMaxSize(); ++i) {
		::proto_ff::MailDesc* temp_maildesc_list = msg.add_maildesc_list();
		MailDesc_s::write_to_pbmsg(obj.MailDesc_List[i], *temp_maildesc_list);
	}
}

void Sheet_MailDesc_s::read_from_pbmsg(const ::proto_ff::Sheet_MailDesc & msg, struct Sheet_MailDesc_s & obj) {
	memset(&obj, 0, sizeof(struct Sheet_MailDesc_s));
	obj.MailDesc_List.SetSize(msg.maildesc_list_size() > obj.MailDesc_List.GetMaxSize() ? obj.MailDesc_List.GetMaxSize() : msg.maildesc_list_size());
	for(int32_t i = 0; i < obj.MailDesc_List.GetSize(); ++i) {
		const ::proto_ff::MailDesc & temp_maildesc_list = msg.maildesc_list(i);
		MailDesc_s::read_from_pbmsg(temp_maildesc_list, obj.MailDesc_List[i]);
	}
}

ConstDesc_s::ConstDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int ConstDesc_s::CreateInit() {
	id = (int32_t)0;
	return 0;
}

int ConstDesc_s::ResumeInit() {
	return 0;
}

void ConstDesc_s::write_to_pbmsg(const struct ConstDesc_s & obj, ::proto_ff::ConstDesc & msg) {
	msg.set_id((int32_t)obj.id);
	msg.set_value((const char*)obj.value.Get());
}

void ConstDesc_s::read_from_pbmsg(const ::proto_ff::ConstDesc & msg, struct ConstDesc_s & obj) {
	memset(&obj, 0, sizeof(struct ConstDesc_s));
	obj.id = msg.id();
	obj.value.Copy(msg.value());
}

Sheet_ConstDesc_s::Sheet_ConstDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_ConstDesc_s::CreateInit() {
	return 0;
}

int Sheet_ConstDesc_s::ResumeInit() {
	return 0;
}

void Sheet_ConstDesc_s::write_to_pbmsg(const struct Sheet_ConstDesc_s & obj, ::proto_ff::Sheet_ConstDesc & msg) {
	for(int32_t i = 0; i < obj.ConstDesc_List.GetSize() && i < obj.ConstDesc_List.GetMaxSize(); ++i) {
		::proto_ff::ConstDesc* temp_constdesc_list = msg.add_constdesc_list();
		ConstDesc_s::write_to_pbmsg(obj.ConstDesc_List[i], *temp_constdesc_list);
	}
}

void Sheet_ConstDesc_s::read_from_pbmsg(const ::proto_ff::Sheet_ConstDesc & msg, struct Sheet_ConstDesc_s & obj) {
	memset(&obj, 0, sizeof(struct Sheet_ConstDesc_s));
	obj.ConstDesc_List.SetSize(msg.constdesc_list_size() > obj.ConstDesc_List.GetMaxSize() ? obj.ConstDesc_List.GetMaxSize() : msg.constdesc_list_size());
	for(int32_t i = 0; i < obj.ConstDesc_List.GetSize(); ++i) {
		const ::proto_ff::ConstDesc & temp_constdesc_list = msg.constdesc_list(i);
		ConstDesc_s::read_from_pbmsg(temp_constdesc_list, obj.ConstDesc_List[i]);
	}
}

NameDesc_s::NameDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int NameDesc_s::CreateInit() {
	id = (uint64_t)0;
	return 0;
}

int NameDesc_s::ResumeInit() {
	return 0;
}

void NameDesc_s::write_to_pbmsg(const struct NameDesc_s & obj, ::proto_ff::NameDesc & msg) {
	msg.set_id((uint64_t)obj.id);
	msg.set_name((const char*)obj.name.Get());
}

void NameDesc_s::read_from_pbmsg(const ::proto_ff::NameDesc & msg, struct NameDesc_s & obj) {
	memset(&obj, 0, sizeof(struct NameDesc_s));
	obj.id = msg.id();
	obj.name.Copy(msg.name());
}

Sheet_NameDesc_s::Sheet_NameDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_NameDesc_s::CreateInit() {
	return 0;
}

int Sheet_NameDesc_s::ResumeInit() {
	return 0;
}

void Sheet_NameDesc_s::write_to_pbmsg(const struct Sheet_NameDesc_s & obj, ::proto_ff::Sheet_NameDesc & msg) {
	for(int32_t i = 0; i < obj.NameDesc_List.GetSize() && i < obj.NameDesc_List.GetMaxSize(); ++i) {
		::proto_ff::NameDesc* temp_namedesc_list = msg.add_namedesc_list();
		NameDesc_s::write_to_pbmsg(obj.NameDesc_List[i], *temp_namedesc_list);
	}
}

void Sheet_NameDesc_s::read_from_pbmsg(const ::proto_ff::Sheet_NameDesc & msg, struct Sheet_NameDesc_s & obj) {
	memset(&obj, 0, sizeof(struct Sheet_NameDesc_s));
	obj.NameDesc_List.SetSize(msg.namedesc_list_size() > obj.NameDesc_List.GetMaxSize() ? obj.NameDesc_List.GetMaxSize() : msg.namedesc_list_size());
	for(int32_t i = 0; i < obj.NameDesc_List.GetSize(); ++i) {
		const ::proto_ff::NameDesc & temp_namedesc_list = msg.namedesc_list(i);
		NameDesc_s::read_from_pbmsg(temp_namedesc_list, obj.NameDesc_List[i]);
	}
}

GameRoomDesc_s::GameRoomDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int GameRoomDesc_s::CreateInit() {
	RoomID = (int32_t)0;
	GameID = (int32_t)0;
	RoomType = (int32_t)0;
	SiteNum = (int32_t)0;
	DeskCount = (int32_t)0;
	MaxPeople = (int32_t)0;
	enter_min = (int64_t)0;
	enter_max = (int64_t)0;
	auto_chair = (int32_t)0;
	is_exp_scene = (int32_t)0;
	exp_scene_gold = (int64_t)0;
	robot_num = (int32_t)0;
	status = (int32_t)0;
	RoomLevel = (int32_t)0;
	Tax = (int32_t)0;
	StartTime = (int32_t)0;
	return 0;
}

int GameRoomDesc_s::ResumeInit() {
	return 0;
}

void GameRoomDesc_s::write_to_pbmsg(const struct GameRoomDesc_s & obj, ::proto_ff::GameRoomDesc & msg) {
	msg.set_roomid((int32_t)obj.RoomID);
	msg.set_gameid((int32_t)obj.GameID);
	msg.set_gamename((const char*)obj.GameName.Get());
	msg.set_roomtype((int32_t)obj.RoomType);
	msg.set_roomname((const char*)obj.RoomName.Get());
	msg.set_sitenum((int32_t)obj.SiteNum);
	msg.set_deskcount((int32_t)obj.DeskCount);
	msg.set_maxpeople((int32_t)obj.MaxPeople);
	msg.set_enter_min((int64_t)obj.enter_min);
	msg.set_enter_max((int64_t)obj.enter_max);
	msg.set_auto_chair((int32_t)obj.auto_chair);
	msg.set_is_exp_scene((int32_t)obj.is_exp_scene);
	msg.set_exp_scene_gold((int64_t)obj.exp_scene_gold);
	msg.set_robot_num((int32_t)obj.robot_num);
	msg.set_status((int32_t)obj.status);
	msg.set_roomlevel((int32_t)obj.RoomLevel);
	msg.set_tax((int32_t)obj.Tax);
	msg.set_starttime((int32_t)obj.StartTime);
}

void GameRoomDesc_s::read_from_pbmsg(const ::proto_ff::GameRoomDesc & msg, struct GameRoomDesc_s & obj) {
	memset(&obj, 0, sizeof(struct GameRoomDesc_s));
	obj.RoomID = msg.roomid();
	obj.GameID = msg.gameid();
	obj.GameName.Copy(msg.gamename());
	obj.RoomType = msg.roomtype();
	obj.RoomName.Copy(msg.roomname());
	obj.SiteNum = msg.sitenum();
	obj.DeskCount = msg.deskcount();
	obj.MaxPeople = msg.maxpeople();
	obj.enter_min = msg.enter_min();
	obj.enter_max = msg.enter_max();
	obj.auto_chair = msg.auto_chair();
	obj.is_exp_scene = msg.is_exp_scene();
	obj.exp_scene_gold = msg.exp_scene_gold();
	obj.robot_num = msg.robot_num();
	obj.status = msg.status();
	obj.RoomLevel = msg.roomlevel();
	obj.Tax = msg.tax();
	obj.StartTime = msg.starttime();
}

Sheet_GameRoomDesc_s::Sheet_GameRoomDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_GameRoomDesc_s::CreateInit() {
	return 0;
}

int Sheet_GameRoomDesc_s::ResumeInit() {
	return 0;
}

void Sheet_GameRoomDesc_s::write_to_pbmsg(const struct Sheet_GameRoomDesc_s & obj, ::proto_ff::Sheet_GameRoomDesc & msg) {
	for(int32_t i = 0; i < obj.GameRoomDesc_List.GetSize() && i < obj.GameRoomDesc_List.GetMaxSize(); ++i) {
		::proto_ff::GameRoomDesc* temp_gameroomdesc_list = msg.add_gameroomdesc_list();
		GameRoomDesc_s::write_to_pbmsg(obj.GameRoomDesc_List[i], *temp_gameroomdesc_list);
	}
}

void Sheet_GameRoomDesc_s::read_from_pbmsg(const ::proto_ff::Sheet_GameRoomDesc & msg, struct Sheet_GameRoomDesc_s & obj) {
	memset(&obj, 0, sizeof(struct Sheet_GameRoomDesc_s));
	obj.GameRoomDesc_List.SetSize(msg.gameroomdesc_list_size() > obj.GameRoomDesc_List.GetMaxSize() ? obj.GameRoomDesc_List.GetMaxSize() : msg.gameroomdesc_list_size());
	for(int32_t i = 0; i < obj.GameRoomDesc_List.GetSize(); ++i) {
		const ::proto_ff::GameRoomDesc & temp_gameroomdesc_list = msg.gameroomdesc_list(i);
		GameRoomDesc_s::read_from_pbmsg(temp_gameroomdesc_list, obj.GameRoomDesc_List[i]);
	}
}

}