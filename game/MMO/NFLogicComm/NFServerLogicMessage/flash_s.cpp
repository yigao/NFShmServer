#include "flash_s.h"

namespace proto_ff_s {

flashflashmonsterDesc_s::flashflashmonsterDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int flashflashmonsterDesc_s::CreateInit() {
	Num = (int32_t)0;
	ID = (int64_t)0;
	return 0;
}

int flashflashmonsterDesc_s::ResumeInit() {
	return 0;
}

void flashflashmonsterDesc_s::write_to_pbmsg(::proto_ff::flashflashmonsterDesc & msg) const {
	msg.set_num((int32_t)Num);
	msg.set_id((int64_t)ID);
}

void flashflashmonsterDesc_s::read_from_pbmsg(const ::proto_ff::flashflashmonsterDesc & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct flashflashmonsterDesc_s));
	Num = msg.num();
	ID = msg.id();
}

flashflash_s::flashflash_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int flashflash_s::CreateInit() {
	id = (int64_t)0;
	typeID = (int64_t)0;
	monster_Type = (int32_t)0;
	isLevelDynamic = (int32_t)0;
	miniLevel = (int32_t)0;
	levelCheck = (int32_t)0;
	monsterRefreshTime = (int32_t)0;
	facePath = (int64_t)0;
	return 0;
}

int flashflash_s::ResumeInit() {
	return 0;
}

void flashflash_s::write_to_pbmsg(::proto_ff::flashflash & msg) const {
	msg.set_id((int64_t)id);
	msg.set_typeid((int64_t)typeID);
	msg.set_monster_type((int32_t)monster_Type);
	msg.set_isleveldynamic((int32_t)isLevelDynamic);
	msg.set_minilevel((int32_t)miniLevel);
	msg.set_levelcheck((int32_t)levelCheck);
	msg.set_monsterrefreshtime((int32_t)monsterRefreshTime);
	msg.set_facepath((int64_t)facePath);
	for(int32_t i = 0; i < (int32_t)monster.GetSize() && i < monster.GetMaxSize(); ++i) {
		::proto_ff::flashflashmonsterDesc* temp_monster = msg.add_monster();
		monster[i].write_to_pbmsg(*temp_monster);
	}
}

void flashflash_s::read_from_pbmsg(const ::proto_ff::flashflash & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct flashflash_s));
	id = msg.id();
	typeID = msg.typeid();
	monster_Type = msg.monster_type();
	isLevelDynamic = msg.isleveldynamic();
	miniLevel = msg.minilevel();
	levelCheck = msg.levelcheck();
	monsterRefreshTime = msg.monsterrefreshtime();
	facePath = msg.facepath();
	monster.SetSize(msg.monster_size() > monster.GetMaxSize() ? monster.GetMaxSize() : msg.monster_size());
	for(int32_t i = 0; i < (int32_t)monster.GetSize(); ++i) {
		const ::proto_ff::flashflashmonsterDesc & temp_monster = msg.monster(i);
		monster[i].read_from_pbmsg(temp_monster);
	}
}

Sheet_flashflash_s::Sheet_flashflash_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_flashflash_s::CreateInit() {
	return 0;
}

int Sheet_flashflash_s::ResumeInit() {
	return 0;
}

void Sheet_flashflash_s::write_to_pbmsg(::proto_ff::Sheet_flashflash & msg) const {
	for(int32_t i = 0; i < (int32_t)flashflash_List.GetSize() && i < flashflash_List.GetMaxSize(); ++i) {
		::proto_ff::flashflash* temp_flashflash_list = msg.add_flashflash_list();
		flashflash_List[i].write_to_pbmsg(*temp_flashflash_list);
	}
}

void Sheet_flashflash_s::read_from_pbmsg(const ::proto_ff::Sheet_flashflash & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_flashflash_s));
	flashflash_List.SetSize(msg.flashflash_list_size() > flashflash_List.GetMaxSize() ? flashflash_List.GetMaxSize() : msg.flashflash_list_size());
	for(int32_t i = 0; i < (int32_t)flashflash_List.GetSize(); ++i) {
		const ::proto_ff::flashflash & temp_flashflash_list = msg.flashflash_list(i);
		flashflash_List[i].read_from_pbmsg(temp_flashflash_list);
	}
}

flashitemFlashmonsterDesc_s::flashitemFlashmonsterDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int flashitemFlashmonsterDesc_s::CreateInit() {
	Id = (int64_t)0;
	weight = (int32_t)0;
	return 0;
}

int flashitemFlashmonsterDesc_s::ResumeInit() {
	return 0;
}

void flashitemFlashmonsterDesc_s::write_to_pbmsg(::proto_ff::flashitemFlashmonsterDesc & msg) const {
	msg.set_id((int64_t)Id);
	msg.set_weight((int32_t)weight);
}

void flashitemFlashmonsterDesc_s::read_from_pbmsg(const ::proto_ff::flashitemFlashmonsterDesc & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct flashitemFlashmonsterDesc_s));
	Id = msg.id();
	weight = msg.weight();
}

flashitemFlash_s::flashitemFlash_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int flashitemFlash_s::CreateInit() {
	id = (int64_t)0;
	live = (int32_t)0;
	levelwave = (int32_t)0;
	flashNum = (int32_t)0;
	return 0;
}

int flashitemFlash_s::ResumeInit() {
	return 0;
}

void flashitemFlash_s::write_to_pbmsg(::proto_ff::flashitemFlash & msg) const {
	msg.set_id((int64_t)id);
	msg.set_usemap((const char*)useMap.Get());
	msg.set_live((int32_t)live);
	msg.set_levelwave((int32_t)levelwave);
	msg.set_flashnum((int32_t)flashNum);
	for(int32_t i = 0; i < (int32_t)monster.GetSize() && i < monster.GetMaxSize(); ++i) {
		::proto_ff::flashitemFlashmonsterDesc* temp_monster = msg.add_monster();
		monster[i].write_to_pbmsg(*temp_monster);
	}
}

void flashitemFlash_s::read_from_pbmsg(const ::proto_ff::flashitemFlash & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct flashitemFlash_s));
	id = msg.id();
	useMap.Copy(msg.usemap());
	live = msg.live();
	levelwave = msg.levelwave();
	flashNum = msg.flashnum();
	monster.SetSize(msg.monster_size() > monster.GetMaxSize() ? monster.GetMaxSize() : msg.monster_size());
	for(int32_t i = 0; i < (int32_t)monster.GetSize(); ++i) {
		const ::proto_ff::flashitemFlashmonsterDesc & temp_monster = msg.monster(i);
		monster[i].read_from_pbmsg(temp_monster);
	}
}

Sheet_flashitemFlash_s::Sheet_flashitemFlash_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_flashitemFlash_s::CreateInit() {
	return 0;
}

int Sheet_flashitemFlash_s::ResumeInit() {
	return 0;
}

void Sheet_flashitemFlash_s::write_to_pbmsg(::proto_ff::Sheet_flashitemFlash & msg) const {
	for(int32_t i = 0; i < (int32_t)flashitemFlash_List.GetSize() && i < flashitemFlash_List.GetMaxSize(); ++i) {
		::proto_ff::flashitemFlash* temp_flashitemflash_list = msg.add_flashitemflash_list();
		flashitemFlash_List[i].write_to_pbmsg(*temp_flashitemflash_list);
	}
}

void Sheet_flashitemFlash_s::read_from_pbmsg(const ::proto_ff::Sheet_flashitemFlash & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_flashitemFlash_s));
	flashitemFlash_List.SetSize(msg.flashitemflash_list_size() > flashitemFlash_List.GetMaxSize() ? flashitemFlash_List.GetMaxSize() : msg.flashitemflash_list_size());
	for(int32_t i = 0; i < (int32_t)flashitemFlash_List.GetSize(); ++i) {
		const ::proto_ff::flashitemFlash & temp_flashitemflash_list = msg.flashitemflash_list(i);
		flashitemFlash_List[i].read_from_pbmsg(temp_flashitemflash_list);
	}
}

}