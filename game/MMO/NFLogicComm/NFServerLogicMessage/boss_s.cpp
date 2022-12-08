#include "boss_s.h"

namespace proto_ff_s {

bossrareItem_s::bossrareItem_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int bossrareItem_s::CreateInit() {
	itemID = (int64_t)0;
	top = (int32_t)0;
	return 0;
}

int bossrareItem_s::ResumeInit() {
	return 0;
}

void bossrareItem_s::write_to_pbmsg(::proto_ff::bossrareItem & msg) const {
	msg.set_itemid((int64_t)itemID);
	msg.set_top((int32_t)top);
}

void bossrareItem_s::read_from_pbmsg(const ::proto_ff::bossrareItem & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct bossrareItem_s));
	itemID = msg.itemid();
	top = msg.top();
}

Sheet_bossrareItem_s::Sheet_bossrareItem_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_bossrareItem_s::CreateInit() {
	return 0;
}

int Sheet_bossrareItem_s::ResumeInit() {
	return 0;
}

void Sheet_bossrareItem_s::write_to_pbmsg(::proto_ff::Sheet_bossrareItem & msg) const {
	for(int32_t i = 0; i < (int32_t)bossrareItem_List.GetSize() && i < bossrareItem_List.GetMaxSize(); ++i) {
		::proto_ff::bossrareItem* temp_bossrareitem_list = msg.add_bossrareitem_list();
		bossrareItem_List[i].write_to_pbmsg(*temp_bossrareitem_list);
	}
}

void Sheet_bossrareItem_s::read_from_pbmsg(const ::proto_ff::Sheet_bossrareItem & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_bossrareItem_s));
	bossrareItem_List.SetSize(msg.bossrareitem_list_size() > bossrareItem_List.GetMaxSize() ? bossrareItem_List.GetMaxSize() : msg.bossrareitem_list_size());
	for(int32_t i = 0; i < (int32_t)bossrareItem_List.GetSize(); ++i) {
		const ::proto_ff::bossrareItem & temp_bossrareitem_list = msg.bossrareitem_list(i);
		bossrareItem_List[i].read_from_pbmsg(temp_bossrareitem_list);
	}
}

bossboss_s::bossboss_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int bossboss_s::CreateInit() {
	id = (int32_t)0;
	bossType = (int32_t)0;
	monsterID = (int32_t)0;
	classOrder = (int32_t)0;
	sceneOrder = (int32_t)0;
	duplicateID = (int32_t)0;
	peaceMask = (int32_t)0;
	pointID = (int32_t)0;
	group_type = (int32_t)0;
	flashTime = (int32_t)0;
	retrieveGiftID = (int32_t)0;
	noTimes = (int32_t)0;
	return 0;
}

int bossboss_s::ResumeInit() {
	return 0;
}

void bossboss_s::write_to_pbmsg(::proto_ff::bossboss & msg) const {
	msg.set_id((int32_t)id);
	msg.set_bosstype((int32_t)bossType);
	msg.set_monsterid((int32_t)monsterID);
	msg.set_classorder((int32_t)classOrder);
	msg.set_sceneorder((int32_t)sceneOrder);
	msg.set_duplicateid((int32_t)duplicateID);
	msg.set_peacemask((int32_t)peaceMask);
	msg.set_pointid((int32_t)pointID);
	msg.set_group_type((int32_t)group_type);
	msg.set_flashtime((int32_t)flashTime);
	msg.set_retrievegiftid((int32_t)retrieveGiftID);
	msg.set_notimes((int32_t)noTimes);
}

void bossboss_s::read_from_pbmsg(const ::proto_ff::bossboss & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct bossboss_s));
	id = msg.id();
	bossType = msg.bosstype();
	monsterID = msg.monsterid();
	classOrder = msg.classorder();
	sceneOrder = msg.sceneorder();
	duplicateID = msg.duplicateid();
	peaceMask = msg.peacemask();
	pointID = msg.pointid();
	group_type = msg.group_type();
	flashTime = msg.flashtime();
	retrieveGiftID = msg.retrievegiftid();
	noTimes = msg.notimes();
}

Sheet_bossboss_s::Sheet_bossboss_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_bossboss_s::CreateInit() {
	return 0;
}

int Sheet_bossboss_s::ResumeInit() {
	return 0;
}

void Sheet_bossboss_s::write_to_pbmsg(::proto_ff::Sheet_bossboss & msg) const {
	for(int32_t i = 0; i < (int32_t)bossboss_List.GetSize() && i < bossboss_List.GetMaxSize(); ++i) {
		::proto_ff::bossboss* temp_bossboss_list = msg.add_bossboss_list();
		bossboss_List[i].write_to_pbmsg(*temp_bossboss_list);
	}
}

void Sheet_bossboss_s::read_from_pbmsg(const ::proto_ff::Sheet_bossboss & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_bossboss_s));
	bossboss_List.SetSize(msg.bossboss_list_size() > bossboss_List.GetMaxSize() ? bossboss_List.GetMaxSize() : msg.bossboss_list_size());
	for(int32_t i = 0; i < (int32_t)bossboss_List.GetSize(); ++i) {
		const ::proto_ff::bossboss & temp_bossboss_list = msg.bossboss_list(i);
		bossboss_List[i].read_from_pbmsg(temp_bossboss_list);
	}
}

bossbosstypegroupDesc_s::bossbosstypegroupDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int bossbosstypegroupDesc_s::CreateInit() {
	type = (int32_t)0;
	times = (int32_t)0;
	return 0;
}

int bossbosstypegroupDesc_s::ResumeInit() {
	return 0;
}

void bossbosstypegroupDesc_s::write_to_pbmsg(::proto_ff::bossbosstypegroupDesc & msg) const {
	msg.set_type((int32_t)type);
	msg.set_times((int32_t)times);
}

void bossbosstypegroupDesc_s::read_from_pbmsg(const ::proto_ff::bossbosstypegroupDesc & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct bossbosstypegroupDesc_s));
	type = msg.type();
	times = msg.times();
}

bossbosstype_s::bossbosstype_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int bossbosstype_s::CreateInit() {
	bossType = (int32_t)0;
	mapType = (int32_t)0;
	functionId = (int32_t)0;
	duplicateGroupID = (int32_t)0;
	privilegeType = (int32_t)0;
	callingCardId = (int64_t)0;
	enterTimes = (int32_t)0;
	costitem = (int32_t)0;
	bossTimes = (int32_t)0;
	addItemID = (int32_t)0;
	canhelp = (int32_t)0;
	qkill = (int32_t)0;
	retrievedDays = (int32_t)0;
	skill = (int32_t)0;
	return 0;
}

int bossbosstype_s::ResumeInit() {
	return 0;
}

void bossbosstype_s::write_to_pbmsg(::proto_ff::bossbosstype & msg) const {
	msg.set_bosstype((int32_t)bossType);
	msg.set_maptype((int32_t)mapType);
	msg.set_functionid((int32_t)functionId);
	msg.set_duplicategroupid((int32_t)duplicateGroupID);
	msg.set_privilegetype((int32_t)privilegeType);
	msg.set_callingcardid((int64_t)callingCardId);
	msg.set_entertimes((int32_t)enterTimes);
	msg.set_costitem((int32_t)costitem);
	msg.set_costnum((const char*)costnum.Get());
	msg.set_bosstimes((int32_t)bossTimes);
	msg.set_additemid((int32_t)addItemID);
	msg.set_canhelp((int32_t)canhelp);
	msg.set_qkill((int32_t)qkill);
	msg.set_retrieveddays((int32_t)retrievedDays);
	msg.set_skill((int32_t)skill);
	for(int32_t i = 0; i < (int32_t)group.GetSize() && i < group.GetMaxSize(); ++i) {
		::proto_ff::bossbosstypegroupDesc* temp_group = msg.add_group();
		group[i].write_to_pbmsg(*temp_group);
	}
}

void bossbosstype_s::read_from_pbmsg(const ::proto_ff::bossbosstype & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct bossbosstype_s));
	bossType = msg.bosstype();
	mapType = msg.maptype();
	functionId = msg.functionid();
	duplicateGroupID = msg.duplicategroupid();
	privilegeType = msg.privilegetype();
	callingCardId = msg.callingcardid();
	enterTimes = msg.entertimes();
	costitem = msg.costitem();
	costnum.Copy(msg.costnum());
	bossTimes = msg.bosstimes();
	addItemID = msg.additemid();
	canhelp = msg.canhelp();
	qkill = msg.qkill();
	retrievedDays = msg.retrieveddays();
	skill = msg.skill();
	group.SetSize(msg.group_size() > group.GetMaxSize() ? group.GetMaxSize() : msg.group_size());
	for(int32_t i = 0; i < (int32_t)group.GetSize(); ++i) {
		const ::proto_ff::bossbosstypegroupDesc & temp_group = msg.group(i);
		group[i].read_from_pbmsg(temp_group);
	}
}

Sheet_bossbosstype_s::Sheet_bossbosstype_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_bossbosstype_s::CreateInit() {
	return 0;
}

int Sheet_bossbosstype_s::ResumeInit() {
	return 0;
}

void Sheet_bossbosstype_s::write_to_pbmsg(::proto_ff::Sheet_bossbosstype & msg) const {
	for(int32_t i = 0; i < (int32_t)bossbosstype_List.GetSize() && i < bossbosstype_List.GetMaxSize(); ++i) {
		::proto_ff::bossbosstype* temp_bossbosstype_list = msg.add_bossbosstype_list();
		bossbosstype_List[i].write_to_pbmsg(*temp_bossbosstype_list);
	}
}

void Sheet_bossbosstype_s::read_from_pbmsg(const ::proto_ff::Sheet_bossbosstype & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_bossbosstype_s));
	bossbosstype_List.SetSize(msg.bossbosstype_list_size() > bossbosstype_List.GetMaxSize() ? bossbosstype_List.GetMaxSize() : msg.bossbosstype_list_size());
	for(int32_t i = 0; i < (int32_t)bossbosstype_List.GetSize(); ++i) {
		const ::proto_ff::bossbosstype & temp_bossbosstype_list = msg.bossbosstype_list(i);
		bossbosstype_List[i].read_from_pbmsg(temp_bossbosstype_list);
	}
}

bosslayer_s::bosslayer_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int bosslayer_s::CreateInit() {
	ID = (int32_t)0;
	bossType = (int32_t)0;
	order = (int32_t)0;
	mapID = (int32_t)0;
	return 0;
}

int bosslayer_s::ResumeInit() {
	return 0;
}

void bosslayer_s::write_to_pbmsg(::proto_ff::bosslayer & msg) const {
	msg.set_id((int32_t)ID);
	msg.set_bosstype((int32_t)bossType);
	msg.set_order((int32_t)order);
	msg.set_name((const char*)name.Get());
	msg.set_entercondition((const char*)enterCondition.Get());
	msg.set_unlockcondition((const char*)unlockCondition.Get());
	msg.set_mapid((int32_t)mapID);
}

void bosslayer_s::read_from_pbmsg(const ::proto_ff::bosslayer & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct bosslayer_s));
	ID = msg.id();
	bossType = msg.bosstype();
	order = msg.order();
	name.Copy(msg.name());
	enterCondition.Copy(msg.entercondition());
	unlockCondition.Copy(msg.unlockcondition());
	mapID = msg.mapid();
}

Sheet_bosslayer_s::Sheet_bosslayer_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_bosslayer_s::CreateInit() {
	return 0;
}

int Sheet_bosslayer_s::ResumeInit() {
	return 0;
}

void Sheet_bosslayer_s::write_to_pbmsg(::proto_ff::Sheet_bosslayer & msg) const {
	for(int32_t i = 0; i < (int32_t)bosslayer_List.GetSize() && i < bosslayer_List.GetMaxSize(); ++i) {
		::proto_ff::bosslayer* temp_bosslayer_list = msg.add_bosslayer_list();
		bosslayer_List[i].write_to_pbmsg(*temp_bosslayer_list);
	}
}

void Sheet_bosslayer_s::read_from_pbmsg(const ::proto_ff::Sheet_bosslayer & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_bosslayer_s));
	bosslayer_List.SetSize(msg.bosslayer_list_size() > bosslayer_List.GetMaxSize() ? bosslayer_List.GetMaxSize() : msg.bosslayer_list_size());
	for(int32_t i = 0; i < (int32_t)bosslayer_List.GetSize(); ++i) {
		const ::proto_ff::bosslayer & temp_bosslayer_list = msg.bosslayer_list(i);
		bosslayer_List[i].read_from_pbmsg(temp_bosslayer_list);
	}
}

}