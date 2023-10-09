#include "flash_s.h"

namespace proto_ff_s {

E_FlashFlashMonsterDesc_s::E_FlashFlashMonsterDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_FlashFlashMonsterDesc_s::CreateInit() {
	m_num = (int32_t)0;
	m_id = (int64_t)0;
	return 0;
}

int E_FlashFlashMonsterDesc_s::ResumeInit() {
	return 0;
}

void E_FlashFlashMonsterDesc_s::write_to_pbmsg(::proto_ff::E_FlashFlashMonsterDesc & msg) const {
	msg.set_m_num((int32_t)m_num);
	msg.set_m_id((int64_t)m_id);
}

void E_FlashFlashMonsterDesc_s::read_from_pbmsg(const ::proto_ff::E_FlashFlashMonsterDesc & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct E_FlashFlashMonsterDesc_s));
	m_num = msg.m_num();
	m_id = msg.m_id();
}

E_FlashFlash_s::E_FlashFlash_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_FlashFlash_s::CreateInit() {
	m_id = (int64_t)0;
	m_isleveldynamic = (int32_t)0;
	m_minilevel = (int32_t)0;
	m_levelcheck = (int32_t)0;
	m_pointid = (int64_t)0;
	m_monster_type = (int32_t)0;
	m_monsterrefreshtime = (int32_t)0;
	return 0;
}

int E_FlashFlash_s::ResumeInit() {
	return 0;
}

void E_FlashFlash_s::write_to_pbmsg(::proto_ff::E_FlashFlash & msg) const {
	msg.set_m_id((int64_t)m_id);
	msg.set_m_isleveldynamic((int32_t)m_isleveldynamic);
	msg.set_m_minilevel((int32_t)m_minilevel);
	msg.set_m_levelcheck((int32_t)m_levelcheck);
	msg.set_m_pointid((int64_t)m_pointid);
	msg.set_m_monster_type((int32_t)m_monster_type);
	msg.set_m_monsterrefreshtime((int32_t)m_monsterrefreshtime);
	for(int32_t i = 0; i < (int32_t)m_monster.size(); ++i) {
		::proto_ff::E_FlashFlashMonsterDesc* temp_m_monster = msg.add_m_monster();
		m_monster[i].write_to_pbmsg(*temp_m_monster);
	}
}

void E_FlashFlash_s::read_from_pbmsg(const ::proto_ff::E_FlashFlash & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct E_FlashFlash_s));
	m_id = msg.m_id();
	m_isleveldynamic = msg.m_isleveldynamic();
	m_minilevel = msg.m_minilevel();
	m_levelcheck = msg.m_levelcheck();
	m_pointid = msg.m_pointid();
	m_monster_type = msg.m_monster_type();
	m_monsterrefreshtime = msg.m_monsterrefreshtime();
	m_monster.resize((int)msg.m_monster_size() > (int)m_monster.max_size() ? m_monster.max_size() : msg.m_monster_size());
	for(int32_t i = 0; i < (int32_t)m_monster.size(); ++i) {
		const ::proto_ff::E_FlashFlashMonsterDesc & temp_m_monster = msg.m_monster(i);
		m_monster[i].read_from_pbmsg(temp_m_monster);
	}
}

Sheet_FlashFlash_s::Sheet_FlashFlash_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_FlashFlash_s::CreateInit() {
	return 0;
}

int Sheet_FlashFlash_s::ResumeInit() {
	return 0;
}

void Sheet_FlashFlash_s::write_to_pbmsg(::proto_ff::Sheet_FlashFlash & msg) const {
	for(int32_t i = 0; i < (int32_t)E_FlashFlash_List.size(); ++i) {
		::proto_ff::E_FlashFlash* temp_e_flashflash_list = msg.add_e_flashflash_list();
		E_FlashFlash_List[i].write_to_pbmsg(*temp_e_flashflash_list);
	}
}

void Sheet_FlashFlash_s::read_from_pbmsg(const ::proto_ff::Sheet_FlashFlash & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_FlashFlash_s));
	E_FlashFlash_List.resize((int)msg.e_flashflash_list_size() > (int)E_FlashFlash_List.max_size() ? E_FlashFlash_List.max_size() : msg.e_flashflash_list_size());
	for(int32_t i = 0; i < (int32_t)E_FlashFlash_List.size(); ++i) {
		const ::proto_ff::E_FlashFlash & temp_e_flashflash_list = msg.e_flashflash_list(i);
		E_FlashFlash_List[i].read_from_pbmsg(temp_e_flashflash_list);
	}
}

E_FlashItemflashMonsterDesc_s::E_FlashItemflashMonsterDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_FlashItemflashMonsterDesc_s::CreateInit() {
	m_id = (int64_t)0;
	m_weight = (int32_t)0;
	return 0;
}

int E_FlashItemflashMonsterDesc_s::ResumeInit() {
	return 0;
}

void E_FlashItemflashMonsterDesc_s::write_to_pbmsg(::proto_ff::E_FlashItemflashMonsterDesc & msg) const {
	msg.set_m_id((int64_t)m_id);
	msg.set_m_weight((int32_t)m_weight);
}

void E_FlashItemflashMonsterDesc_s::read_from_pbmsg(const ::proto_ff::E_FlashItemflashMonsterDesc & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct E_FlashItemflashMonsterDesc_s));
	m_id = msg.m_id();
	m_weight = msg.m_weight();
}

E_FlashItemflash_s::E_FlashItemflash_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_FlashItemflash_s::CreateInit() {
	m_id = (int64_t)0;
	m_live = (int32_t)0;
	m_levelwave = (int32_t)0;
	m_flashnum = (int32_t)0;
	return 0;
}

int E_FlashItemflash_s::ResumeInit() {
	return 0;
}

void E_FlashItemflash_s::write_to_pbmsg(::proto_ff::E_FlashItemflash & msg) const {
	msg.set_m_id((int64_t)m_id);
	msg.set_m_usemap((const char*)m_usemap.data());
	msg.set_m_live((int32_t)m_live);
	msg.set_m_levelwave((int32_t)m_levelwave);
	msg.set_m_flashnum((int32_t)m_flashnum);
	for(int32_t i = 0; i < (int32_t)m_monster.size(); ++i) {
		::proto_ff::E_FlashItemflashMonsterDesc* temp_m_monster = msg.add_m_monster();
		m_monster[i].write_to_pbmsg(*temp_m_monster);
	}
}

void E_FlashItemflash_s::read_from_pbmsg(const ::proto_ff::E_FlashItemflash & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct E_FlashItemflash_s));
	m_id = msg.m_id();
	m_usemap = msg.m_usemap();
	m_live = msg.m_live();
	m_levelwave = msg.m_levelwave();
	m_flashnum = msg.m_flashnum();
	m_monster.resize((int)msg.m_monster_size() > (int)m_monster.max_size() ? m_monster.max_size() : msg.m_monster_size());
	for(int32_t i = 0; i < (int32_t)m_monster.size(); ++i) {
		const ::proto_ff::E_FlashItemflashMonsterDesc & temp_m_monster = msg.m_monster(i);
		m_monster[i].read_from_pbmsg(temp_m_monster);
	}
}

Sheet_FlashItemflash_s::Sheet_FlashItemflash_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_FlashItemflash_s::CreateInit() {
	return 0;
}

int Sheet_FlashItemflash_s::ResumeInit() {
	return 0;
}

void Sheet_FlashItemflash_s::write_to_pbmsg(::proto_ff::Sheet_FlashItemflash & msg) const {
	for(int32_t i = 0; i < (int32_t)E_FlashItemflash_List.size(); ++i) {
		::proto_ff::E_FlashItemflash* temp_e_flashitemflash_list = msg.add_e_flashitemflash_list();
		E_FlashItemflash_List[i].write_to_pbmsg(*temp_e_flashitemflash_list);
	}
}

void Sheet_FlashItemflash_s::read_from_pbmsg(const ::proto_ff::Sheet_FlashItemflash & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_FlashItemflash_s));
	E_FlashItemflash_List.resize((int)msg.e_flashitemflash_list_size() > (int)E_FlashItemflash_List.max_size() ? E_FlashItemflash_List.max_size() : msg.e_flashitemflash_list_size());
	for(int32_t i = 0; i < (int32_t)E_FlashItemflash_List.size(); ++i) {
		const ::proto_ff::E_FlashItemflash & temp_e_flashitemflash_list = msg.e_flashitemflash_list(i);
		E_FlashItemflash_List[i].read_from_pbmsg(temp_e_flashitemflash_list);
	}
}

}