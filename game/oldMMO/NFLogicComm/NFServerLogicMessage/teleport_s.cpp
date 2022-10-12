#include "teleport_s.h"

namespace proto_ff_s {

teleportborn_s::teleportborn_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int teleportborn_s::CreateInit() {
	id = (int64_t)0;
	type = (int32_t)0;
	scene = (int64_t)0;
	roleBornRange = (int32_t)0;
	return 0;
}

int teleportborn_s::ResumeInit() {
	return 0;
}

void teleportborn_s::write_to_pbmsg(::proto_ff::teleportborn & msg) const {
	msg.set_id((int64_t)id);
	msg.set_type((int32_t)type);
	msg.set_scene((int64_t)scene);
	msg.set_rolebornrange((int32_t)roleBornRange);
}

void teleportborn_s::read_from_pbmsg(const ::proto_ff::teleportborn & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct teleportborn_s));
	id = msg.id();
	type = msg.type();
	scene = msg.scene();
	roleBornRange = msg.rolebornrange();
}

Sheet_teleportborn_s::Sheet_teleportborn_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_teleportborn_s::CreateInit() {
	return 0;
}

int Sheet_teleportborn_s::ResumeInit() {
	return 0;
}

void Sheet_teleportborn_s::write_to_pbmsg(::proto_ff::Sheet_teleportborn & msg) const {
	for(int32_t i = 0; i < (int32_t)teleportborn_List.GetSize() && i < teleportborn_List.GetMaxSize(); ++i) {
		::proto_ff::teleportborn* temp_teleportborn_list = msg.add_teleportborn_list();
		teleportborn_List[i].write_to_pbmsg(*temp_teleportborn_list);
	}
}

void Sheet_teleportborn_s::read_from_pbmsg(const ::proto_ff::Sheet_teleportborn & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_teleportborn_s));
	teleportborn_List.SetSize(msg.teleportborn_list_size() > teleportborn_List.GetMaxSize() ? teleportborn_List.GetMaxSize() : msg.teleportborn_list_size());
	for(int32_t i = 0; i < (int32_t)teleportborn_List.GetSize(); ++i) {
		const ::proto_ff::teleportborn & temp_teleportborn_list = msg.teleportborn_list(i);
		teleportborn_List[i].read_from_pbmsg(temp_teleportborn_list);
	}
}

teleportteleport_s::teleportteleport_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int teleportteleport_s::CreateInit() {
	teleportID = (int64_t)0;
	teleportType = (int32_t)0;
	monsterId = (int64_t)0;
	showCondition = (int32_t)0;
	canEnter = (int32_t)0;
	showPathID = (int64_t)0;
	toPathID = (int64_t)0;
	toDuplicateId = (int64_t)0;
	trigRange = (int32_t)0;
	livingTime = (int32_t)0;
	openChatId = (int64_t)0;
	progressChatId = (int64_t)0;
	return 0;
}

int teleportteleport_s::ResumeInit() {
	return 0;
}

void teleportteleport_s::write_to_pbmsg(::proto_ff::teleportteleport & msg) const {
	msg.set_teleportid((int64_t)teleportID);
	msg.set_teleporttype((int32_t)teleportType);
	msg.set_name((const char*)name.Get());
	msg.set_monsterid((int64_t)monsterId);
	msg.set_showcondition((int32_t)showCondition);
	msg.set_conditionvalue((const char*)conditionValue.Get());
	msg.set_canenter((int32_t)canEnter);
	msg.set_showpathid((int64_t)showPathID);
	msg.set_topathid((int64_t)toPathID);
	msg.set_toduplicateid((int64_t)toDuplicateId);
	msg.set_entercost((const char*)enterCost.Get());
	msg.set_trigrange((int32_t)trigRange);
	msg.set_livingtime((int32_t)livingTime);
	msg.set_openchatid((int64_t)openChatId);
	msg.set_progresschatid((int64_t)progressChatId);
}

void teleportteleport_s::read_from_pbmsg(const ::proto_ff::teleportteleport & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct teleportteleport_s));
	teleportID = msg.teleportid();
	teleportType = msg.teleporttype();
	name.Copy(msg.name());
	monsterId = msg.monsterid();
	showCondition = msg.showcondition();
	conditionValue.Copy(msg.conditionvalue());
	canEnter = msg.canenter();
	showPathID = msg.showpathid();
	toPathID = msg.topathid();
	toDuplicateId = msg.toduplicateid();
	enterCost.Copy(msg.entercost());
	trigRange = msg.trigrange();
	livingTime = msg.livingtime();
	openChatId = msg.openchatid();
	progressChatId = msg.progresschatid();
}

Sheet_teleportteleport_s::Sheet_teleportteleport_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_teleportteleport_s::CreateInit() {
	return 0;
}

int Sheet_teleportteleport_s::ResumeInit() {
	return 0;
}

void Sheet_teleportteleport_s::write_to_pbmsg(::proto_ff::Sheet_teleportteleport & msg) const {
	for(int32_t i = 0; i < (int32_t)teleportteleport_List.GetSize() && i < teleportteleport_List.GetMaxSize(); ++i) {
		::proto_ff::teleportteleport* temp_teleportteleport_list = msg.add_teleportteleport_list();
		teleportteleport_List[i].write_to_pbmsg(*temp_teleportteleport_list);
	}
}

void Sheet_teleportteleport_s::read_from_pbmsg(const ::proto_ff::Sheet_teleportteleport & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_teleportteleport_s));
	teleportteleport_List.SetSize(msg.teleportteleport_list_size() > teleportteleport_List.GetMaxSize() ? teleportteleport_List.GetMaxSize() : msg.teleportteleport_list_size());
	for(int32_t i = 0; i < (int32_t)teleportteleport_List.GetSize(); ++i) {
		const ::proto_ff::teleportteleport & temp_teleportteleport_list = msg.teleportteleport_list(i);
		teleportteleport_List[i].read_from_pbmsg(temp_teleportteleport_list);
	}
}

}