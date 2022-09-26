#include "getTreasure_s.h"

namespace proto_ff_s {

getTreasurerareItem_s::getTreasurerareItem_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int getTreasurerareItem_s::CreateInit() {
	itemID = (int64_t)0;
	top = (int32_t)0;
	return 0;
}

int getTreasurerareItem_s::ResumeInit() {
	return 0;
}

void getTreasurerareItem_s::write_to_pbmsg(::proto_ff::getTreasurerareItem & msg) const {
	msg.set_itemid((int64_t)itemID);
	msg.set_top((int32_t)top);
}

void getTreasurerareItem_s::read_from_pbmsg(const ::proto_ff::getTreasurerareItem & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct getTreasurerareItem_s));
	itemID = msg.itemid();
	top = msg.top();
}

Sheet_getTreasurerareItem_s::Sheet_getTreasurerareItem_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_getTreasurerareItem_s::CreateInit() {
	return 0;
}

int Sheet_getTreasurerareItem_s::ResumeInit() {
	return 0;
}

void Sheet_getTreasurerareItem_s::write_to_pbmsg(::proto_ff::Sheet_getTreasurerareItem & msg) const {
	for(int32_t i = 0; i < (int32_t)getTreasurerareItem_List.GetSize() && i < getTreasurerareItem_List.GetMaxSize(); ++i) {
		::proto_ff::getTreasurerareItem* temp_gettreasurerareitem_list = msg.add_gettreasurerareitem_list();
		getTreasurerareItem_List[i].write_to_pbmsg(*temp_gettreasurerareitem_list);
	}
}

void Sheet_getTreasurerareItem_s::read_from_pbmsg(const ::proto_ff::Sheet_getTreasurerareItem & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_getTreasurerareItem_s));
	getTreasurerareItem_List.SetSize(msg.gettreasurerareitem_list_size() > getTreasurerareItem_List.GetMaxSize() ? getTreasurerareItem_List.GetMaxSize() : msg.gettreasurerareitem_list_size());
	for(int32_t i = 0; i < (int32_t)getTreasurerareItem_List.GetSize(); ++i) {
		const ::proto_ff::getTreasurerareItem & temp_gettreasurerareitem_list = msg.gettreasurerareitem_list(i);
		getTreasurerareItem_List[i].read_from_pbmsg(temp_gettreasurerareitem_list);
	}
}

getTreasuretimesControlgroupDesc_s::getTreasuretimesControlgroupDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int getTreasuretimesControlgroupDesc_s::CreateInit() {
	type = (int32_t)0;
	times = (int32_t)0;
	return 0;
}

int getTreasuretimesControlgroupDesc_s::ResumeInit() {
	return 0;
}

void getTreasuretimesControlgroupDesc_s::write_to_pbmsg(::proto_ff::getTreasuretimesControlgroupDesc & msg) const {
	msg.set_type((int32_t)type);
	msg.set_times((int32_t)times);
}

void getTreasuretimesControlgroupDesc_s::read_from_pbmsg(const ::proto_ff::getTreasuretimesControlgroupDesc & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct getTreasuretimesControlgroupDesc_s));
	type = msg.type();
	times = msg.times();
}

getTreasuretimesControl_s::getTreasuretimesControl_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int getTreasuretimesControl_s::CreateInit() {
	bossType = (int32_t)0;
	mapType = (int32_t)0;
	functionId = (int32_t)0;
	duplicateGroupID = (int32_t)0;
	viptype = (int32_t)0;
	bossFlashItem = (int64_t)0;
	bossFlashItemNum = (int32_t)0;
	callingCardId = (int64_t)0;
	callingCardNum = (int32_t)0;
	times = (int32_t)0;
	costitem1 = (int64_t)0;
	costnum1 = (int32_t)0;
	canBuyFlag = (int32_t)0;
	canhelp = (int32_t)0;
	skill = (int32_t)0;
	return 0;
}

int getTreasuretimesControl_s::ResumeInit() {
	return 0;
}

void getTreasuretimesControl_s::write_to_pbmsg(::proto_ff::getTreasuretimesControl & msg) const {
	msg.set_bosstype((int32_t)bossType);
	msg.set_maptype((int32_t)mapType);
	msg.set_functionid((int32_t)functionId);
	msg.set_duplicategroupid((int32_t)duplicateGroupID);
	msg.set_viptype((int32_t)viptype);
	msg.set_bossflashitem((int64_t)bossFlashItem);
	msg.set_bossflashitemnum((int32_t)bossFlashItemNum);
	msg.set_callingcardid((int64_t)callingCardId);
	msg.set_callingcardnum((int32_t)callingCardNum);
	msg.set_times((int32_t)times);
	msg.set_costitem1((int64_t)costitem1);
	msg.set_costnum1((int32_t)costnum1);
	msg.set_canbuyflag((int32_t)canBuyFlag);
	msg.set_canhelp((int32_t)canhelp);
	msg.set_skill((int32_t)skill);
	for(int32_t i = 0; i < (int32_t)group.GetSize() && i < group.GetMaxSize(); ++i) {
		::proto_ff::getTreasuretimesControlgroupDesc* temp_group = msg.add_group();
		group[i].write_to_pbmsg(*temp_group);
	}
}

void getTreasuretimesControl_s::read_from_pbmsg(const ::proto_ff::getTreasuretimesControl & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct getTreasuretimesControl_s));
	bossType = msg.bosstype();
	mapType = msg.maptype();
	functionId = msg.functionid();
	duplicateGroupID = msg.duplicategroupid();
	viptype = msg.viptype();
	bossFlashItem = msg.bossflashitem();
	bossFlashItemNum = msg.bossflashitemnum();
	callingCardId = msg.callingcardid();
	callingCardNum = msg.callingcardnum();
	times = msg.times();
	costitem1 = msg.costitem1();
	costnum1 = msg.costnum1();
	canBuyFlag = msg.canbuyflag();
	canhelp = msg.canhelp();
	skill = msg.skill();
	group.SetSize(msg.group_size() > group.GetMaxSize() ? group.GetMaxSize() : msg.group_size());
	for(int32_t i = 0; i < (int32_t)group.GetSize(); ++i) {
		const ::proto_ff::getTreasuretimesControlgroupDesc & temp_group = msg.group(i);
		group[i].read_from_pbmsg(temp_group);
	}
}

Sheet_getTreasuretimesControl_s::Sheet_getTreasuretimesControl_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_getTreasuretimesControl_s::CreateInit() {
	return 0;
}

int Sheet_getTreasuretimesControl_s::ResumeInit() {
	return 0;
}

void Sheet_getTreasuretimesControl_s::write_to_pbmsg(::proto_ff::Sheet_getTreasuretimesControl & msg) const {
	for(int32_t i = 0; i < (int32_t)getTreasuretimesControl_List.GetSize() && i < getTreasuretimesControl_List.GetMaxSize(); ++i) {
		::proto_ff::getTreasuretimesControl* temp_gettreasuretimescontrol_list = msg.add_gettreasuretimescontrol_list();
		getTreasuretimesControl_List[i].write_to_pbmsg(*temp_gettreasuretimescontrol_list);
	}
}

void Sheet_getTreasuretimesControl_s::read_from_pbmsg(const ::proto_ff::Sheet_getTreasuretimesControl & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_getTreasuretimesControl_s));
	getTreasuretimesControl_List.SetSize(msg.gettreasuretimescontrol_list_size() > getTreasuretimesControl_List.GetMaxSize() ? getTreasuretimesControl_List.GetMaxSize() : msg.gettreasuretimescontrol_list_size());
	for(int32_t i = 0; i < (int32_t)getTreasuretimesControl_List.GetSize(); ++i) {
		const ::proto_ff::getTreasuretimesControl & temp_gettreasuretimescontrol_list = msg.gettreasuretimescontrol_list(i);
		getTreasuretimesControl_List[i].read_from_pbmsg(temp_gettreasuretimescontrol_list);
	}
}

getTreasureArrivalBossReward_s::getTreasureArrivalBossReward_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int getTreasureArrivalBossReward_s::CreateInit() {
	id = (int32_t)0;
	type = (int32_t)0;
	typeParam = (int32_t)0;
	boxID = (int64_t)0;
	return 0;
}

int getTreasureArrivalBossReward_s::ResumeInit() {
	return 0;
}

void getTreasureArrivalBossReward_s::write_to_pbmsg(::proto_ff::getTreasureArrivalBossReward & msg) const {
	msg.set_id((int32_t)id);
	msg.set_type((int32_t)type);
	msg.set_typeparam((int32_t)typeParam);
	msg.set_boxid((int64_t)boxID);
}

void getTreasureArrivalBossReward_s::read_from_pbmsg(const ::proto_ff::getTreasureArrivalBossReward & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct getTreasureArrivalBossReward_s));
	id = msg.id();
	type = msg.type();
	typeParam = msg.typeparam();
	boxID = msg.boxid();
}

Sheet_getTreasureArrivalBossReward_s::Sheet_getTreasureArrivalBossReward_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_getTreasureArrivalBossReward_s::CreateInit() {
	return 0;
}

int Sheet_getTreasureArrivalBossReward_s::ResumeInit() {
	return 0;
}

void Sheet_getTreasureArrivalBossReward_s::write_to_pbmsg(::proto_ff::Sheet_getTreasureArrivalBossReward & msg) const {
	for(int32_t i = 0; i < (int32_t)getTreasureArrivalBossReward_List.GetSize() && i < getTreasureArrivalBossReward_List.GetMaxSize(); ++i) {
		::proto_ff::getTreasureArrivalBossReward* temp_gettreasurearrivalbossreward_list = msg.add_gettreasurearrivalbossreward_list();
		getTreasureArrivalBossReward_List[i].write_to_pbmsg(*temp_gettreasurearrivalbossreward_list);
	}
}

void Sheet_getTreasureArrivalBossReward_s::read_from_pbmsg(const ::proto_ff::Sheet_getTreasureArrivalBossReward & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_getTreasureArrivalBossReward_s));
	getTreasureArrivalBossReward_List.SetSize(msg.gettreasurearrivalbossreward_list_size() > getTreasureArrivalBossReward_List.GetMaxSize() ? getTreasureArrivalBossReward_List.GetMaxSize() : msg.gettreasurearrivalbossreward_list_size());
	for(int32_t i = 0; i < (int32_t)getTreasureArrivalBossReward_List.GetSize(); ++i) {
		const ::proto_ff::getTreasureArrivalBossReward & temp_gettreasurearrivalbossreward_list = msg.gettreasurearrivalbossreward_list(i);
		getTreasureArrivalBossReward_List[i].read_from_pbmsg(temp_gettreasurearrivalbossreward_list);
	}
}

getTreasureArrivalBossControl_s::getTreasureArrivalBossControl_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int getTreasureArrivalBossControl_s::CreateInit() {
	id = (int32_t)0;
	Arrival = (int32_t)0;
	costid = (int64_t)0;
	rewardID = (int64_t)0;
	rewardNum = (int32_t)0;
	timesMax = (int32_t)0;
	recovery = (int32_t)0;
	duplicateGroup = (int64_t)0;
	bossid = (int64_t)0;
	pathID = (int64_t)0;
	return 0;
}

int getTreasureArrivalBossControl_s::ResumeInit() {
	return 0;
}

void getTreasureArrivalBossControl_s::write_to_pbmsg(::proto_ff::getTreasureArrivalBossControl & msg) const {
	msg.set_id((int32_t)id);
	msg.set_arrival((int32_t)Arrival);
	msg.set_costid((int64_t)costid);
	msg.set_rewardid((int64_t)rewardID);
	msg.set_rewardnum((int32_t)rewardNum);
	msg.set_timesmax((int32_t)timesMax);
	msg.set_recovery((int32_t)recovery);
	msg.set_duplicategroup((int64_t)duplicateGroup);
	msg.set_bossid((int64_t)bossid);
	msg.set_pathid((int64_t)pathID);
	msg.set_radio((const char*)radio.Get());
}

void getTreasureArrivalBossControl_s::read_from_pbmsg(const ::proto_ff::getTreasureArrivalBossControl & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct getTreasureArrivalBossControl_s));
	id = msg.id();
	Arrival = msg.arrival();
	costid = msg.costid();
	rewardID = msg.rewardid();
	rewardNum = msg.rewardnum();
	timesMax = msg.timesmax();
	recovery = msg.recovery();
	duplicateGroup = msg.duplicategroup();
	bossid = msg.bossid();
	pathID = msg.pathid();
	radio.Copy(msg.radio());
}

Sheet_getTreasureArrivalBossControl_s::Sheet_getTreasureArrivalBossControl_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_getTreasureArrivalBossControl_s::CreateInit() {
	return 0;
}

int Sheet_getTreasureArrivalBossControl_s::ResumeInit() {
	return 0;
}

void Sheet_getTreasureArrivalBossControl_s::write_to_pbmsg(::proto_ff::Sheet_getTreasureArrivalBossControl & msg) const {
	for(int32_t i = 0; i < (int32_t)getTreasureArrivalBossControl_List.GetSize() && i < getTreasureArrivalBossControl_List.GetMaxSize(); ++i) {
		::proto_ff::getTreasureArrivalBossControl* temp_gettreasurearrivalbosscontrol_list = msg.add_gettreasurearrivalbosscontrol_list();
		getTreasureArrivalBossControl_List[i].write_to_pbmsg(*temp_gettreasurearrivalbosscontrol_list);
	}
}

void Sheet_getTreasureArrivalBossControl_s::read_from_pbmsg(const ::proto_ff::Sheet_getTreasureArrivalBossControl & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_getTreasureArrivalBossControl_s));
	getTreasureArrivalBossControl_List.SetSize(msg.gettreasurearrivalbosscontrol_list_size() > getTreasureArrivalBossControl_List.GetMaxSize() ? getTreasureArrivalBossControl_List.GetMaxSize() : msg.gettreasurearrivalbosscontrol_list_size());
	for(int32_t i = 0; i < (int32_t)getTreasureArrivalBossControl_List.GetSize(); ++i) {
		const ::proto_ff::getTreasureArrivalBossControl & temp_gettreasurearrivalbosscontrol_list = msg.gettreasurearrivalbosscontrol_list(i);
		getTreasureArrivalBossControl_List[i].read_from_pbmsg(temp_gettreasurearrivalbosscontrol_list);
	}
}

getTreasurevipBossControl_s::getTreasurevipBossControl_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int getTreasurevipBossControl_s::CreateInit() {
	floor = (int32_t)0;
	minVipLvNeed = (int32_t)0;
	VipLvNeed = (int32_t)0;
	costnum = (int32_t)0;
	costid = (int64_t)0;
	return 0;
}

int getTreasurevipBossControl_s::ResumeInit() {
	return 0;
}

void getTreasurevipBossControl_s::write_to_pbmsg(::proto_ff::getTreasurevipBossControl & msg) const {
	msg.set_floor((int32_t)floor);
	msg.set_minviplvneed((int32_t)minVipLvNeed);
	msg.set_viplvneed((int32_t)VipLvNeed);
	msg.set_costnum((int32_t)costnum);
	msg.set_costid((int64_t)costid);
}

void getTreasurevipBossControl_s::read_from_pbmsg(const ::proto_ff::getTreasurevipBossControl & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct getTreasurevipBossControl_s));
	floor = msg.floor();
	minVipLvNeed = msg.minviplvneed();
	VipLvNeed = msg.viplvneed();
	costnum = msg.costnum();
	costid = msg.costid();
}

Sheet_getTreasurevipBossControl_s::Sheet_getTreasurevipBossControl_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_getTreasurevipBossControl_s::CreateInit() {
	return 0;
}

int Sheet_getTreasurevipBossControl_s::ResumeInit() {
	return 0;
}

void Sheet_getTreasurevipBossControl_s::write_to_pbmsg(::proto_ff::Sheet_getTreasurevipBossControl & msg) const {
	for(int32_t i = 0; i < (int32_t)getTreasurevipBossControl_List.GetSize() && i < getTreasurevipBossControl_List.GetMaxSize(); ++i) {
		::proto_ff::getTreasurevipBossControl* temp_gettreasurevipbosscontrol_list = msg.add_gettreasurevipbosscontrol_list();
		getTreasurevipBossControl_List[i].write_to_pbmsg(*temp_gettreasurevipbosscontrol_list);
	}
}

void Sheet_getTreasurevipBossControl_s::read_from_pbmsg(const ::proto_ff::Sheet_getTreasurevipBossControl & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_getTreasurevipBossControl_s));
	getTreasurevipBossControl_List.SetSize(msg.gettreasurevipbosscontrol_list_size() > getTreasurevipBossControl_List.GetMaxSize() ? getTreasurevipBossControl_List.GetMaxSize() : msg.gettreasurevipbosscontrol_list_size());
	for(int32_t i = 0; i < (int32_t)getTreasurevipBossControl_List.GetSize(); ++i) {
		const ::proto_ff::getTreasurevipBossControl & temp_gettreasurevipbosscontrol_list = msg.gettreasurevipbosscontrol_list(i);
		getTreasurevipBossControl_List[i].read_from_pbmsg(temp_gettreasurevipbosscontrol_list);
	}
}

getTreasureboss_s::getTreasureboss_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int getTreasureboss_s::CreateInit() {
	id = (int64_t)0;
	bossType = (int32_t)0;
	monsterID = (int64_t)0;
	classOrder = (int32_t)0;
	sceneOrder = (int32_t)0;
	duplicateID = (int64_t)0;
	pathID = (int64_t)0;
	group_type = (int32_t)0;
	flashTime = (int32_t)0;
	return 0;
}

int getTreasureboss_s::ResumeInit() {
	return 0;
}

void getTreasureboss_s::write_to_pbmsg(::proto_ff::getTreasureboss & msg) const {
	msg.set_id((int64_t)id);
	msg.set_bosstype((int32_t)bossType);
	msg.set_monsterid((int64_t)monsterID);
	msg.set_classorder((int32_t)classOrder);
	msg.set_sceneorder((int32_t)sceneOrder);
	msg.set_duplicateid((int64_t)duplicateID);
	msg.set_pathid((int64_t)pathID);
	msg.set_group_type((int32_t)group_type);
	msg.set_flashtime((int32_t)flashTime);
}

void getTreasureboss_s::read_from_pbmsg(const ::proto_ff::getTreasureboss & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct getTreasureboss_s));
	id = msg.id();
	bossType = msg.bosstype();
	monsterID = msg.monsterid();
	classOrder = msg.classorder();
	sceneOrder = msg.sceneorder();
	duplicateID = msg.duplicateid();
	pathID = msg.pathid();
	group_type = msg.group_type();
	flashTime = msg.flashtime();
}

Sheet_getTreasureboss_s::Sheet_getTreasureboss_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_getTreasureboss_s::CreateInit() {
	return 0;
}

int Sheet_getTreasureboss_s::ResumeInit() {
	return 0;
}

void Sheet_getTreasureboss_s::write_to_pbmsg(::proto_ff::Sheet_getTreasureboss & msg) const {
	for(int32_t i = 0; i < (int32_t)getTreasureboss_List.GetSize() && i < getTreasureboss_List.GetMaxSize(); ++i) {
		::proto_ff::getTreasureboss* temp_gettreasureboss_list = msg.add_gettreasureboss_list();
		getTreasureboss_List[i].write_to_pbmsg(*temp_gettreasureboss_list);
	}
}

void Sheet_getTreasureboss_s::read_from_pbmsg(const ::proto_ff::Sheet_getTreasureboss & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_getTreasureboss_s));
	getTreasureboss_List.SetSize(msg.gettreasureboss_list_size() > getTreasureboss_List.GetMaxSize() ? getTreasureboss_List.GetMaxSize() : msg.gettreasureboss_list_size());
	for(int32_t i = 0; i < (int32_t)getTreasureboss_List.GetSize(); ++i) {
		const ::proto_ff::getTreasureboss & temp_gettreasureboss_list = msg.gettreasureboss_list(i);
		getTreasureboss_List[i].read_from_pbmsg(temp_gettreasureboss_list);
	}
}

getTreasurehelp_s::getTreasurehelp_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int getTreasurehelp_s::CreateInit() {
	id = (int32_t)0;
	down = (int32_t)0;
	up = (int32_t)0;
	return 0;
}

int getTreasurehelp_s::ResumeInit() {
	return 0;
}

void getTreasurehelp_s::write_to_pbmsg(::proto_ff::getTreasurehelp & msg) const {
	msg.set_id((int32_t)id);
	msg.set_down((int32_t)down);
	msg.set_up((int32_t)up);
		msg.add_num((int64_t)num[i]);
	}
}

void getTreasurehelp_s::read_from_pbmsg(const ::proto_ff::getTreasurehelp & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct getTreasurehelp_s));
	id = msg.id();
	down = msg.down();
	up = msg.up();
		num[i] = msg.num(i);
	}
}

Sheet_getTreasurehelp_s::Sheet_getTreasurehelp_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_getTreasurehelp_s::CreateInit() {
	return 0;
}

int Sheet_getTreasurehelp_s::ResumeInit() {
	return 0;
}

void Sheet_getTreasurehelp_s::write_to_pbmsg(::proto_ff::Sheet_getTreasurehelp & msg) const {
	for(int32_t i = 0; i < (int32_t)getTreasurehelp_List.GetSize() && i < getTreasurehelp_List.GetMaxSize(); ++i) {
		::proto_ff::getTreasurehelp* temp_gettreasurehelp_list = msg.add_gettreasurehelp_list();
		getTreasurehelp_List[i].write_to_pbmsg(*temp_gettreasurehelp_list);
	}
}

void Sheet_getTreasurehelp_s::read_from_pbmsg(const ::proto_ff::Sheet_getTreasurehelp & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_getTreasurehelp_s));
	getTreasurehelp_List.SetSize(msg.gettreasurehelp_list_size() > getTreasurehelp_List.GetMaxSize() ? getTreasurehelp_List.GetMaxSize() : msg.gettreasurehelp_list_size());
	for(int32_t i = 0; i < (int32_t)getTreasurehelp_List.GetSize(); ++i) {
		const ::proto_ff::getTreasurehelp & temp_gettreasurehelp_list = msg.gettreasurehelp_list(i);
		getTreasurehelp_List[i].read_from_pbmsg(temp_gettreasurehelp_list);
	}
}

}