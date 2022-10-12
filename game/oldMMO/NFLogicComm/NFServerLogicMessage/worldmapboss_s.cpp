#include "worldmapboss_s.h"

namespace proto_ff_s {

worldmapbossworldboss_s::worldmapbossworldboss_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int worldmapbossworldboss_s::CreateInit() {
	id = (int32_t)0;
	bossId = (int64_t)0;
	miniLevel = (int32_t)0;
	unLockLevel = (int32_t)0;
	levelCheck = (int32_t)0;
	specNoticeHP = (int32_t)0;
	bornSpaceTime = (int32_t)0;
	return 0;
}

int worldmapbossworldboss_s::ResumeInit() {
	return 0;
}

void worldmapbossworldboss_s::write_to_pbmsg(::proto_ff::worldmapbossworldboss & msg) const {
	msg.set_id((int32_t)id);
	msg.set_bossid((int64_t)bossId);
	msg.set_minilevel((int32_t)miniLevel);
	msg.set_unlocklevel((int32_t)unLockLevel);
	msg.set_levelcheck((int32_t)levelCheck);
	msg.set_pathid((const char*)pathId.Get());
	msg.set_specnoticehp((int32_t)specNoticeHP);
	msg.set_bornspacetime((int32_t)bornSpaceTime);
	for(int32_t i = 0; i < (int32_t)born_Time.GetSize() && i < born_Time.GetMaxSize(); ++i) {
		msg.add_born_time((const char*)born_Time[i].Get());
	}
}

void worldmapbossworldboss_s::read_from_pbmsg(const ::proto_ff::worldmapbossworldboss & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct worldmapbossworldboss_s));
	id = msg.id();
	bossId = msg.bossid();
	miniLevel = msg.minilevel();
	unLockLevel = msg.unlocklevel();
	levelCheck = msg.levelcheck();
	pathId.Copy(msg.pathid());
	specNoticeHP = msg.specnoticehp();
	bornSpaceTime = msg.bornspacetime();
	born_Time.SetSize(msg.born_time_size() > born_Time.GetMaxSize() ? born_Time.GetMaxSize() : msg.born_time_size());
	for(int32_t i = 0; i < (int32_t)born_Time.GetSize(); ++i) {
		born_Time[i].Copy(msg.born_time(i));
	}
}

Sheet_worldmapbossworldboss_s::Sheet_worldmapbossworldboss_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_worldmapbossworldboss_s::CreateInit() {
	return 0;
}

int Sheet_worldmapbossworldboss_s::ResumeInit() {
	return 0;
}

void Sheet_worldmapbossworldboss_s::write_to_pbmsg(::proto_ff::Sheet_worldmapbossworldboss & msg) const {
	for(int32_t i = 0; i < (int32_t)worldmapbossworldboss_List.GetSize() && i < worldmapbossworldboss_List.GetMaxSize(); ++i) {
		::proto_ff::worldmapbossworldboss* temp_worldmapbossworldboss_list = msg.add_worldmapbossworldboss_list();
		worldmapbossworldboss_List[i].write_to_pbmsg(*temp_worldmapbossworldboss_list);
	}
}

void Sheet_worldmapbossworldboss_s::read_from_pbmsg(const ::proto_ff::Sheet_worldmapbossworldboss & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_worldmapbossworldboss_s));
	worldmapbossworldboss_List.SetSize(msg.worldmapbossworldboss_list_size() > worldmapbossworldboss_List.GetMaxSize() ? worldmapbossworldboss_List.GetMaxSize() : msg.worldmapbossworldboss_list_size());
	for(int32_t i = 0; i < (int32_t)worldmapbossworldboss_List.GetSize(); ++i) {
		const ::proto_ff::worldmapbossworldboss & temp_worldmapbossworldboss_list = msg.worldmapbossworldboss_list(i);
		worldmapbossworldboss_List[i].read_from_pbmsg(temp_worldmapbossworldboss_list);
	}
}

worldmapbossdroplist_s::worldmapbossdroplist_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int worldmapbossdroplist_s::CreateInit() {
	id = (int32_t)0;
	monsterId = (int64_t)0;
	bossLevel = (int32_t)0;
	dropId = (int64_t)0;
	return 0;
}

int worldmapbossdroplist_s::ResumeInit() {
	return 0;
}

void worldmapbossdroplist_s::write_to_pbmsg(::proto_ff::worldmapbossdroplist & msg) const {
	msg.set_id((int32_t)id);
	msg.set_monsterid((int64_t)monsterId);
	msg.set_bosslevel((int32_t)bossLevel);
	msg.set_dropid((int64_t)dropId);
}

void worldmapbossdroplist_s::read_from_pbmsg(const ::proto_ff::worldmapbossdroplist & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct worldmapbossdroplist_s));
	id = msg.id();
	monsterId = msg.monsterid();
	bossLevel = msg.bosslevel();
	dropId = msg.dropid();
}

Sheet_worldmapbossdroplist_s::Sheet_worldmapbossdroplist_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_worldmapbossdroplist_s::CreateInit() {
	return 0;
}

int Sheet_worldmapbossdroplist_s::ResumeInit() {
	return 0;
}

void Sheet_worldmapbossdroplist_s::write_to_pbmsg(::proto_ff::Sheet_worldmapbossdroplist & msg) const {
	for(int32_t i = 0; i < (int32_t)worldmapbossdroplist_List.GetSize() && i < worldmapbossdroplist_List.GetMaxSize(); ++i) {
		::proto_ff::worldmapbossdroplist* temp_worldmapbossdroplist_list = msg.add_worldmapbossdroplist_list();
		worldmapbossdroplist_List[i].write_to_pbmsg(*temp_worldmapbossdroplist_list);
	}
}

void Sheet_worldmapbossdroplist_s::read_from_pbmsg(const ::proto_ff::Sheet_worldmapbossdroplist & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_worldmapbossdroplist_s));
	worldmapbossdroplist_List.SetSize(msg.worldmapbossdroplist_list_size() > worldmapbossdroplist_List.GetMaxSize() ? worldmapbossdroplist_List.GetMaxSize() : msg.worldmapbossdroplist_list_size());
	for(int32_t i = 0; i < (int32_t)worldmapbossdroplist_List.GetSize(); ++i) {
		const ::proto_ff::worldmapbossdroplist & temp_worldmapbossdroplist_list = msg.worldmapbossdroplist_list(i);
		worldmapbossdroplist_List[i].read_from_pbmsg(temp_worldmapbossdroplist_list);
	}
}

worldmapbossfestival_s::worldmapbossfestival_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int worldmapbossfestival_s::CreateInit() {
	id = (int32_t)0;
	bossId = (int64_t)0;
	across = (int32_t)0;
	return 0;
}

int worldmapbossfestival_s::ResumeInit() {
	return 0;
}

void worldmapbossfestival_s::write_to_pbmsg(::proto_ff::worldmapbossfestival & msg) const {
	msg.set_id((int32_t)id);
	msg.set_bossid((int64_t)bossId);
	msg.set_across((int32_t)across);
}

void worldmapbossfestival_s::read_from_pbmsg(const ::proto_ff::worldmapbossfestival & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct worldmapbossfestival_s));
	id = msg.id();
	bossId = msg.bossid();
	across = msg.across();
}

Sheet_worldmapbossfestival_s::Sheet_worldmapbossfestival_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_worldmapbossfestival_s::CreateInit() {
	return 0;
}

int Sheet_worldmapbossfestival_s::ResumeInit() {
	return 0;
}

void Sheet_worldmapbossfestival_s::write_to_pbmsg(::proto_ff::Sheet_worldmapbossfestival & msg) const {
	for(int32_t i = 0; i < (int32_t)worldmapbossfestival_List.GetSize() && i < worldmapbossfestival_List.GetMaxSize(); ++i) {
		::proto_ff::worldmapbossfestival* temp_worldmapbossfestival_list = msg.add_worldmapbossfestival_list();
		worldmapbossfestival_List[i].write_to_pbmsg(*temp_worldmapbossfestival_list);
	}
}

void Sheet_worldmapbossfestival_s::read_from_pbmsg(const ::proto_ff::Sheet_worldmapbossfestival & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_worldmapbossfestival_s));
	worldmapbossfestival_List.SetSize(msg.worldmapbossfestival_list_size() > worldmapbossfestival_List.GetMaxSize() ? worldmapbossfestival_List.GetMaxSize() : msg.worldmapbossfestival_list_size());
	for(int32_t i = 0; i < (int32_t)worldmapbossfestival_List.GetSize(); ++i) {
		const ::proto_ff::worldmapbossfestival & temp_worldmapbossfestival_list = msg.worldmapbossfestival_list(i);
		worldmapbossfestival_List[i].read_from_pbmsg(temp_worldmapbossfestival_list);
	}
}

}