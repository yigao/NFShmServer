#include "duplicate_s.h"

namespace proto_ff_s {

duplicateduplicate_s::duplicateduplicate_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int duplicateduplicate_s::CreateInit() {
	duplicateID = (int64_t)0;
	groupID = (int64_t)0;
	duplicateType = (int32_t)0;
	playType = (int32_t)0;
	sceneResource = (int64_t)0;
	levelLimit = (int32_t)0;
	linkDuplicateRequest = (int64_t)0;
	isAutoFight = (int32_t)0;
	reviveMaxTimes = (int32_t)0;
	dropNormalMonster = (int64_t)0;
	dropEliteMonster = (int64_t)0;
	dropBossMonster = (int64_t)0;
	TeamObjectID = (int32_t)0;
	sweepRewardBoxID = (int64_t)0;
	sweepRewardExp = (int32_t)0;
	isPatrol = (int32_t)0;
	sweepType = (int32_t)0;
	return 0;
}

int duplicateduplicate_s::ResumeInit() {
	return 0;
}

void duplicateduplicate_s::write_to_pbmsg(::proto_ff::duplicateduplicate & msg) const {
	msg.set_duplicateid((int64_t)duplicateID);
	msg.set_duplicatename((const char*)duplicateName.Get());
	msg.set_duplicatetitlepic((const char*)duplicateTitlePic.Get());
	msg.set_groupid((int64_t)groupID);
	msg.set_duplicatetype((int32_t)duplicateType);
	msg.set_playtype((int32_t)playType);
	msg.set_sceneresource((int64_t)sceneResource);
	msg.set_levellimit((int32_t)levelLimit);
	msg.set_linkduplicaterequest((int64_t)linkDuplicateRequest);
	msg.set_isautofight((int32_t)isAutoFight);
	msg.set_duplicateconditiontype((const char*)duplicateConditionType.Get());
	msg.set_revivemaxtimes((int32_t)reviveMaxTimes);
	msg.set_dropnormalmonster((int64_t)dropNormalMonster);
	msg.set_dropelitemonster((int64_t)dropEliteMonster);
	msg.set_dropbossmonster((int64_t)dropBossMonster);
	msg.set_sceneaiscript((const char*)sceneAIScript.Get());
	msg.set_bossdesc((const char*)bossDesc.Get());
	msg.set_teamobjectid((int32_t)TeamObjectID);
	msg.set_gradecondition((const char*)gradeCondition.Get());
	msg.set_sweeprewardboxid((int64_t)sweepRewardBoxID);
	msg.set_sweeprewardexp((int32_t)sweepRewardExp);
	msg.set_trackpath((const char*)trackpath.Get());
	msg.set_pathofmonster((const char*)pathOfmonster.Get());
	msg.set_ispatrol((int32_t)isPatrol);
	msg.set_sweeptype((int32_t)sweepType);
}

void duplicateduplicate_s::read_from_pbmsg(const ::proto_ff::duplicateduplicate & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct duplicateduplicate_s));
	duplicateID = msg.duplicateid();
	duplicateName.Copy(msg.duplicatename());
	duplicateTitlePic.Copy(msg.duplicatetitlepic());
	groupID = msg.groupid();
	duplicateType = msg.duplicatetype();
	playType = msg.playtype();
	sceneResource = msg.sceneresource();
	levelLimit = msg.levellimit();
	linkDuplicateRequest = msg.linkduplicaterequest();
	isAutoFight = msg.isautofight();
	duplicateConditionType.Copy(msg.duplicateconditiontype());
	reviveMaxTimes = msg.revivemaxtimes();
	dropNormalMonster = msg.dropnormalmonster();
	dropEliteMonster = msg.dropelitemonster();
	dropBossMonster = msg.dropbossmonster();
	sceneAIScript.Copy(msg.sceneaiscript());
	bossDesc.Copy(msg.bossdesc());
	TeamObjectID = msg.teamobjectid();
	gradeCondition.Copy(msg.gradecondition());
	sweepRewardBoxID = msg.sweeprewardboxid();
	sweepRewardExp = msg.sweeprewardexp();
	trackpath.Copy(msg.trackpath());
	pathOfmonster.Copy(msg.pathofmonster());
	isPatrol = msg.ispatrol();
	sweepType = msg.sweeptype();
}

Sheet_duplicateduplicate_s::Sheet_duplicateduplicate_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_duplicateduplicate_s::CreateInit() {
	return 0;
}

int Sheet_duplicateduplicate_s::ResumeInit() {
	return 0;
}

void Sheet_duplicateduplicate_s::write_to_pbmsg(::proto_ff::Sheet_duplicateduplicate & msg) const {
	for(int32_t i = 0; i < (int32_t)duplicateduplicate_List.GetSize() && i < duplicateduplicate_List.GetMaxSize(); ++i) {
		::proto_ff::duplicateduplicate* temp_duplicateduplicate_list = msg.add_duplicateduplicate_list();
		duplicateduplicate_List[i].write_to_pbmsg(*temp_duplicateduplicate_list);
	}
}

void Sheet_duplicateduplicate_s::read_from_pbmsg(const ::proto_ff::Sheet_duplicateduplicate & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_duplicateduplicate_s));
	duplicateduplicate_List.SetSize(msg.duplicateduplicate_list_size() > duplicateduplicate_List.GetMaxSize() ? duplicateduplicate_List.GetMaxSize() : msg.duplicateduplicate_list_size());
	for(int32_t i = 0; i < (int32_t)duplicateduplicate_List.GetSize(); ++i) {
		const ::proto_ff::duplicateduplicate & temp_duplicateduplicate_list = msg.duplicateduplicate_list(i);
		duplicateduplicate_List[i].read_from_pbmsg(temp_duplicateduplicate_list);
	}
}

duplicateconstant_s::duplicateconstant_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int duplicateconstant_s::CreateInit() {
	constantid = (int64_t)0;
	constantdata = (int64_t)0;
	return 0;
}

int duplicateconstant_s::ResumeInit() {
	return 0;
}

void duplicateconstant_s::write_to_pbmsg(::proto_ff::duplicateconstant & msg) const {
	msg.set_constantid((int64_t)constantid);
	msg.set_constantdata((int64_t)constantdata);
	msg.set_stringdata((const char*)stringdata.Get());
}

void duplicateconstant_s::read_from_pbmsg(const ::proto_ff::duplicateconstant & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct duplicateconstant_s));
	constantid = msg.constantid();
	constantdata = msg.constantdata();
	stringdata.Copy(msg.stringdata());
}

Sheet_duplicateconstant_s::Sheet_duplicateconstant_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_duplicateconstant_s::CreateInit() {
	return 0;
}

int Sheet_duplicateconstant_s::ResumeInit() {
	return 0;
}

void Sheet_duplicateconstant_s::write_to_pbmsg(::proto_ff::Sheet_duplicateconstant & msg) const {
	for(int32_t i = 0; i < (int32_t)duplicateconstant_List.GetSize() && i < duplicateconstant_List.GetMaxSize(); ++i) {
		::proto_ff::duplicateconstant* temp_duplicateconstant_list = msg.add_duplicateconstant_list();
		duplicateconstant_List[i].write_to_pbmsg(*temp_duplicateconstant_list);
	}
}

void Sheet_duplicateconstant_s::read_from_pbmsg(const ::proto_ff::Sheet_duplicateconstant & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_duplicateconstant_s));
	duplicateconstant_List.SetSize(msg.duplicateconstant_list_size() > duplicateconstant_List.GetMaxSize() ? duplicateconstant_List.GetMaxSize() : msg.duplicateconstant_list_size());
	for(int32_t i = 0; i < (int32_t)duplicateconstant_List.GetSize(); ++i) {
		const ::proto_ff::duplicateconstant & temp_duplicateconstant_list = msg.duplicateconstant_list(i);
		duplicateconstant_List[i].read_from_pbmsg(temp_duplicateconstant_list);
	}
}

duplicateendlessMaze_s::duplicateendlessMaze_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int duplicateendlessMaze_s::CreateInit() {
	id = (int32_t)0;
	level = (int32_t)0;
	CreateRate = (int32_t)0;
	rewardID = (int64_t)0;
	return 0;
}

int duplicateendlessMaze_s::ResumeInit() {
	return 0;
}

void duplicateendlessMaze_s::write_to_pbmsg(::proto_ff::duplicateendlessMaze & msg) const {
	msg.set_id((int32_t)id);
	msg.set_level((int32_t)level);
	msg.set_duplicateid((const char*)duplicateID.Get());
	msg.set_createrate((int32_t)CreateRate);
	msg.set_rewardid((int64_t)rewardID);
}

void duplicateendlessMaze_s::read_from_pbmsg(const ::proto_ff::duplicateendlessMaze & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct duplicateendlessMaze_s));
	id = msg.id();
	level = msg.level();
	duplicateID.Copy(msg.duplicateid());
	CreateRate = msg.createrate();
	rewardID = msg.rewardid();
}

Sheet_duplicateendlessMaze_s::Sheet_duplicateendlessMaze_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_duplicateendlessMaze_s::CreateInit() {
	return 0;
}

int Sheet_duplicateendlessMaze_s::ResumeInit() {
	return 0;
}

void Sheet_duplicateendlessMaze_s::write_to_pbmsg(::proto_ff::Sheet_duplicateendlessMaze & msg) const {
	for(int32_t i = 0; i < (int32_t)duplicateendlessMaze_List.GetSize() && i < duplicateendlessMaze_List.GetMaxSize(); ++i) {
		::proto_ff::duplicateendlessMaze* temp_duplicateendlessmaze_list = msg.add_duplicateendlessmaze_list();
		duplicateendlessMaze_List[i].write_to_pbmsg(*temp_duplicateendlessmaze_list);
	}
}

void Sheet_duplicateendlessMaze_s::read_from_pbmsg(const ::proto_ff::Sheet_duplicateendlessMaze & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_duplicateendlessMaze_s));
	duplicateendlessMaze_List.SetSize(msg.duplicateendlessmaze_list_size() > duplicateendlessMaze_List.GetMaxSize() ? duplicateendlessMaze_List.GetMaxSize() : msg.duplicateendlessmaze_list_size());
	for(int32_t i = 0; i < (int32_t)duplicateendlessMaze_List.GetSize(); ++i) {
		const ::proto_ff::duplicateendlessMaze & temp_duplicateendlessmaze_list = msg.duplicateendlessmaze_list(i);
		duplicateendlessMaze_List[i].read_from_pbmsg(temp_duplicateendlessmaze_list);
	}
}

duplicatetowerReward_s::duplicatetowerReward_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int duplicatetowerReward_s::CreateInit() {
	floorMin = (int64_t)0;
	floormax = (int64_t)0;
	BOXID = (int64_t)0;
	itemId = (int64_t)0;
	itemNum = (int32_t)0;
	return 0;
}

int duplicatetowerReward_s::ResumeInit() {
	return 0;
}

void duplicatetowerReward_s::write_to_pbmsg(::proto_ff::duplicatetowerReward & msg) const {
	msg.set_floormin((int64_t)floorMin);
	msg.set_floormax((int64_t)floormax);
	msg.set_boxid((int64_t)BOXID);
	msg.set_itemid((int64_t)itemId);
	msg.set_itemnum((int32_t)itemNum);
}

void duplicatetowerReward_s::read_from_pbmsg(const ::proto_ff::duplicatetowerReward & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct duplicatetowerReward_s));
	floorMin = msg.floormin();
	floormax = msg.floormax();
	BOXID = msg.boxid();
	itemId = msg.itemid();
	itemNum = msg.itemnum();
}

Sheet_duplicatetowerReward_s::Sheet_duplicatetowerReward_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_duplicatetowerReward_s::CreateInit() {
	return 0;
}

int Sheet_duplicatetowerReward_s::ResumeInit() {
	return 0;
}

void Sheet_duplicatetowerReward_s::write_to_pbmsg(::proto_ff::Sheet_duplicatetowerReward & msg) const {
	for(int32_t i = 0; i < (int32_t)duplicatetowerReward_List.GetSize() && i < duplicatetowerReward_List.GetMaxSize(); ++i) {
		::proto_ff::duplicatetowerReward* temp_duplicatetowerreward_list = msg.add_duplicatetowerreward_list();
		duplicatetowerReward_List[i].write_to_pbmsg(*temp_duplicatetowerreward_list);
	}
}

void Sheet_duplicatetowerReward_s::read_from_pbmsg(const ::proto_ff::Sheet_duplicatetowerReward & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_duplicatetowerReward_s));
	duplicatetowerReward_List.SetSize(msg.duplicatetowerreward_list_size() > duplicatetowerReward_List.GetMaxSize() ? duplicatetowerReward_List.GetMaxSize() : msg.duplicatetowerreward_list_size());
	for(int32_t i = 0; i < (int32_t)duplicatetowerReward_List.GetSize(); ++i) {
		const ::proto_ff::duplicatetowerReward & temp_duplicatetowerreward_list = msg.duplicatetowerreward_list(i);
		duplicatetowerReward_List[i].read_from_pbmsg(temp_duplicatetowerreward_list);
	}
}

duplicatedungeonRewardrewardDesc_s::duplicatedungeonRewardrewardDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int duplicatedungeonRewardrewardDesc_s::CreateInit() {
	ItemNum = (int32_t)0;
	Item = (int64_t)0;
	Num = (int32_t)0;
	return 0;
}

int duplicatedungeonRewardrewardDesc_s::ResumeInit() {
	return 0;
}

void duplicatedungeonRewardrewardDesc_s::write_to_pbmsg(::proto_ff::duplicatedungeonRewardrewardDesc & msg) const {
	msg.set_itemnum((int32_t)ItemNum);
	msg.set_item((int64_t)Item);
	msg.set_num((int32_t)Num);
}

void duplicatedungeonRewardrewardDesc_s::read_from_pbmsg(const ::proto_ff::duplicatedungeonRewardrewardDesc & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct duplicatedungeonRewardrewardDesc_s));
	ItemNum = msg.itemnum();
	Item = msg.item();
	Num = msg.num();
}

duplicatedungeonReward_s::duplicatedungeonReward_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int duplicatedungeonReward_s::CreateInit() {
	levelID = (int32_t)0;
	rewardTime = (int32_t)0;
	passReceiveTime = (int32_t)0;
	return 0;
}

int duplicatedungeonReward_s::ResumeInit() {
	return 0;
}

void duplicatedungeonReward_s::write_to_pbmsg(::proto_ff::duplicatedungeonReward & msg) const {
	msg.set_levelid((int32_t)levelID);
	msg.set_rewardtime((int32_t)rewardTime);
	msg.set_passreceivetime((int32_t)passReceiveTime);
	for(int32_t i = 0; i < (int32_t)reward.GetSize() && i < reward.GetMaxSize(); ++i) {
		::proto_ff::duplicatedungeonRewardrewardDesc* temp_reward = msg.add_reward();
		reward[i].write_to_pbmsg(*temp_reward);
	}
}

void duplicatedungeonReward_s::read_from_pbmsg(const ::proto_ff::duplicatedungeonReward & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct duplicatedungeonReward_s));
	levelID = msg.levelid();
	rewardTime = msg.rewardtime();
	passReceiveTime = msg.passreceivetime();
	reward.SetSize(msg.reward_size() > reward.GetMaxSize() ? reward.GetMaxSize() : msg.reward_size());
	for(int32_t i = 0; i < (int32_t)reward.GetSize(); ++i) {
		const ::proto_ff::duplicatedungeonRewardrewardDesc & temp_reward = msg.reward(i);
		reward[i].read_from_pbmsg(temp_reward);
	}
}

Sheet_duplicatedungeonReward_s::Sheet_duplicatedungeonReward_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_duplicatedungeonReward_s::CreateInit() {
	return 0;
}

int Sheet_duplicatedungeonReward_s::ResumeInit() {
	return 0;
}

void Sheet_duplicatedungeonReward_s::write_to_pbmsg(::proto_ff::Sheet_duplicatedungeonReward & msg) const {
	for(int32_t i = 0; i < (int32_t)duplicatedungeonReward_List.GetSize() && i < duplicatedungeonReward_List.GetMaxSize(); ++i) {
		::proto_ff::duplicatedungeonReward* temp_duplicatedungeonreward_list = msg.add_duplicatedungeonreward_list();
		duplicatedungeonReward_List[i].write_to_pbmsg(*temp_duplicatedungeonreward_list);
	}
}

void Sheet_duplicatedungeonReward_s::read_from_pbmsg(const ::proto_ff::Sheet_duplicatedungeonReward & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_duplicatedungeonReward_s));
	duplicatedungeonReward_List.SetSize(msg.duplicatedungeonreward_list_size() > duplicatedungeonReward_List.GetMaxSize() ? duplicatedungeonReward_List.GetMaxSize() : msg.duplicatedungeonreward_list_size());
	for(int32_t i = 0; i < (int32_t)duplicatedungeonReward_List.GetSize(); ++i) {
		const ::proto_ff::duplicatedungeonReward & temp_duplicatedungeonreward_list = msg.duplicatedungeonreward_list(i);
		duplicatedungeonReward_List[i].read_from_pbmsg(temp_duplicatedungeonreward_list);
	}
}

duplicategroup_s::duplicategroup_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int duplicategroup_s::CreateInit() {
	id = (int64_t)0;
	unlockLevel = (int32_t)0;
	belongToType = (int32_t)0;
	viptype = (int32_t)0;
	dynamiclevel = (int32_t)0;
	groupTimesType = (int32_t)0;
	groupTimes = (int32_t)0;
	refreshType = (int32_t)0;
	enterItemID = (int64_t)0;
	reliveTpye = (int32_t)0;
	buyEnterTimesCostType = (int32_t)0;
	buyEnterTimesCost = (int32_t)0;
	countDown = (int32_t)0;
	pathfindingtype = (int32_t)0;
	return 0;
}

int duplicategroup_s::ResumeInit() {
	return 0;
}

void duplicategroup_s::write_to_pbmsg(::proto_ff::duplicategroup & msg) const {
	msg.set_id((int64_t)id);
	msg.set_name((const char*)name.Get());
	msg.set_duplicatetitlepic((const char*)duplicateTitlePic.Get());
	msg.set_unlocklevel((int32_t)unlockLevel);
	msg.set_belongtotype((int32_t)belongToType);
	msg.set_viptype((int32_t)viptype);
	msg.set_dynamiclevel((int32_t)dynamiclevel);
	msg.set_timesres((const char*)timesRes.Get());
	msg.set_grouptimestype((int32_t)groupTimesType);
	msg.set_grouptimes((int32_t)groupTimes);
	msg.set_refreshtype((int32_t)refreshType);
	msg.set_enteritemid((int64_t)enterItemID);
	msg.set_relivetpye((int32_t)reliveTpye);
	msg.set_sweepcondition((const char*)sweepCondition.Get());
	msg.set_buyentertimescosttype((int32_t)buyEnterTimesCostType);
	msg.set_buyentertimescost((int32_t)buyEnterTimesCost);
	msg.set_countdown((int32_t)countDown);
	msg.set_pathfindingtype((int32_t)pathfindingtype);
}

void duplicategroup_s::read_from_pbmsg(const ::proto_ff::duplicategroup & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct duplicategroup_s));
	id = msg.id();
	name.Copy(msg.name());
	duplicateTitlePic.Copy(msg.duplicatetitlepic());
	unlockLevel = msg.unlocklevel();
	belongToType = msg.belongtotype();
	viptype = msg.viptype();
	dynamiclevel = msg.dynamiclevel();
	timesRes.Copy(msg.timesres());
	groupTimesType = msg.grouptimestype();
	groupTimes = msg.grouptimes();
	refreshType = msg.refreshtype();
	enterItemID = msg.enteritemid();
	reliveTpye = msg.relivetpye();
	sweepCondition.Copy(msg.sweepcondition());
	buyEnterTimesCostType = msg.buyentertimescosttype();
	buyEnterTimesCost = msg.buyentertimescost();
	countDown = msg.countdown();
	pathfindingtype = msg.pathfindingtype();
}

Sheet_duplicategroup_s::Sheet_duplicategroup_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_duplicategroup_s::CreateInit() {
	return 0;
}

int Sheet_duplicategroup_s::ResumeInit() {
	return 0;
}

void Sheet_duplicategroup_s::write_to_pbmsg(::proto_ff::Sheet_duplicategroup & msg) const {
	for(int32_t i = 0; i < (int32_t)duplicategroup_List.GetSize() && i < duplicategroup_List.GetMaxSize(); ++i) {
		::proto_ff::duplicategroup* temp_duplicategroup_list = msg.add_duplicategroup_list();
		duplicategroup_List[i].write_to_pbmsg(*temp_duplicategroup_list);
	}
}

void Sheet_duplicategroup_s::read_from_pbmsg(const ::proto_ff::Sheet_duplicategroup & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_duplicategroup_s));
	duplicategroup_List.SetSize(msg.duplicategroup_list_size() > duplicategroup_List.GetMaxSize() ? duplicategroup_List.GetMaxSize() : msg.duplicategroup_list_size());
	for(int32_t i = 0; i < (int32_t)duplicategroup_List.GetSize(); ++i) {
		const ::proto_ff::duplicategroup & temp_duplicategroup_list = msg.duplicategroup_list(i);
		duplicategroup_List[i].read_from_pbmsg(temp_duplicategroup_list);
	}
}

duplicatesweepmonsterNum_s::duplicatesweepmonsterNum_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int duplicatesweepmonsterNum_s::CreateInit() {
	ID = (int32_t)0;
	sweepType = (int32_t)0;
	minLevel = (int32_t)0;
	maxLevel = (int32_t)0;
	killNumber = (int32_t)0;
	monstervaluetype = (int32_t)0;
	return 0;
}

int duplicatesweepmonsterNum_s::ResumeInit() {
	return 0;
}

void duplicatesweepmonsterNum_s::write_to_pbmsg(::proto_ff::duplicatesweepmonsterNum & msg) const {
	msg.set_id((int32_t)ID);
	msg.set_sweeptype((int32_t)sweepType);
	msg.set_minlevel((int32_t)minLevel);
	msg.set_maxlevel((int32_t)maxLevel);
	msg.set_killnumber((int32_t)killNumber);
	msg.set_monstervaluetype((int32_t)monstervaluetype);
}

void duplicatesweepmonsterNum_s::read_from_pbmsg(const ::proto_ff::duplicatesweepmonsterNum & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct duplicatesweepmonsterNum_s));
	ID = msg.id();
	sweepType = msg.sweeptype();
	minLevel = msg.minlevel();
	maxLevel = msg.maxlevel();
	killNumber = msg.killnumber();
	monstervaluetype = msg.monstervaluetype();
}

Sheet_duplicatesweepmonsterNum_s::Sheet_duplicatesweepmonsterNum_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_duplicatesweepmonsterNum_s::CreateInit() {
	return 0;
}

int Sheet_duplicatesweepmonsterNum_s::ResumeInit() {
	return 0;
}

void Sheet_duplicatesweepmonsterNum_s::write_to_pbmsg(::proto_ff::Sheet_duplicatesweepmonsterNum & msg) const {
	for(int32_t i = 0; i < (int32_t)duplicatesweepmonsterNum_List.GetSize() && i < duplicatesweepmonsterNum_List.GetMaxSize(); ++i) {
		::proto_ff::duplicatesweepmonsterNum* temp_duplicatesweepmonsternum_list = msg.add_duplicatesweepmonsternum_list();
		duplicatesweepmonsterNum_List[i].write_to_pbmsg(*temp_duplicatesweepmonsternum_list);
	}
}

void Sheet_duplicatesweepmonsterNum_s::read_from_pbmsg(const ::proto_ff::Sheet_duplicatesweepmonsterNum & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_duplicatesweepmonsterNum_s));
	duplicatesweepmonsterNum_List.SetSize(msg.duplicatesweepmonsternum_list_size() > duplicatesweepmonsterNum_List.GetMaxSize() ? duplicatesweepmonsterNum_List.GetMaxSize() : msg.duplicatesweepmonsternum_list_size());
	for(int32_t i = 0; i < (int32_t)duplicatesweepmonsterNum_List.GetSize(); ++i) {
		const ::proto_ff::duplicatesweepmonsterNum & temp_duplicatesweepmonsternum_list = msg.duplicatesweepmonsternum_list(i);
		duplicatesweepmonsterNum_List[i].read_from_pbmsg(temp_duplicatesweepmonsternum_list);
	}
}

duplicateGuildbosstime_s::duplicateGuildbosstime_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int duplicateGuildbosstime_s::CreateInit() {
	duplicateID = (int64_t)0;
	openCycle = (int32_t)0;
	bossGroup = (int32_t)0;
	relevance = (int32_t)0;
	return 0;
}

int duplicateGuildbosstime_s::ResumeInit() {
	return 0;
}

void duplicateGuildbosstime_s::write_to_pbmsg(::proto_ff::duplicateGuildbosstime & msg) const {
	msg.set_duplicateid((int64_t)duplicateID);
	msg.set_opencycle((int32_t)openCycle);
	msg.set_opentime((const char*)openTime.Get());
	msg.set_bossgroup((int32_t)bossGroup);
	msg.set_relevance((int32_t)relevance);
}

void duplicateGuildbosstime_s::read_from_pbmsg(const ::proto_ff::duplicateGuildbosstime & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct duplicateGuildbosstime_s));
	duplicateID = msg.duplicateid();
	openCycle = msg.opencycle();
	openTime.Copy(msg.opentime());
	bossGroup = msg.bossgroup();
	relevance = msg.relevance();
}

Sheet_duplicateGuildbosstime_s::Sheet_duplicateGuildbosstime_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_duplicateGuildbosstime_s::CreateInit() {
	return 0;
}

int Sheet_duplicateGuildbosstime_s::ResumeInit() {
	return 0;
}

void Sheet_duplicateGuildbosstime_s::write_to_pbmsg(::proto_ff::Sheet_duplicateGuildbosstime & msg) const {
	for(int32_t i = 0; i < (int32_t)duplicateGuildbosstime_List.GetSize() && i < duplicateGuildbosstime_List.GetMaxSize(); ++i) {
		::proto_ff::duplicateGuildbosstime* temp_duplicateguildbosstime_list = msg.add_duplicateguildbosstime_list();
		duplicateGuildbosstime_List[i].write_to_pbmsg(*temp_duplicateguildbosstime_list);
	}
}

void Sheet_duplicateGuildbosstime_s::read_from_pbmsg(const ::proto_ff::Sheet_duplicateGuildbosstime & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_duplicateGuildbosstime_s));
	duplicateGuildbosstime_List.SetSize(msg.duplicateguildbosstime_list_size() > duplicateGuildbosstime_List.GetMaxSize() ? duplicateGuildbosstime_List.GetMaxSize() : msg.duplicateguildbosstime_list_size());
	for(int32_t i = 0; i < (int32_t)duplicateGuildbosstime_List.GetSize(); ++i) {
		const ::proto_ff::duplicateGuildbosstime & temp_duplicateguildbosstime_list = msg.duplicateguildbosstime_list(i);
		duplicateGuildbosstime_List[i].read_from_pbmsg(temp_duplicateguildbosstime_list);
	}
}

duplicateGuildbosskillDesc_s::duplicateGuildbosskillDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int duplicateGuildbosskillDesc_s::CreateInit() {
	small = (int32_t)0;
	large = (int32_t)0;
	weaken = (int32_t)0;
	return 0;
}

int duplicateGuildbosskillDesc_s::ResumeInit() {
	return 0;
}

void duplicateGuildbosskillDesc_s::write_to_pbmsg(::proto_ff::duplicateGuildbosskillDesc & msg) const {
	msg.set_small((int32_t)small);
	msg.set_large((int32_t)large);
	msg.set_weaken((int32_t)weaken);
}

void duplicateGuildbosskillDesc_s::read_from_pbmsg(const ::proto_ff::duplicateGuildbosskillDesc & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct duplicateGuildbosskillDesc_s));
	small = msg.small();
	large = msg.large();
	weaken = msg.weaken();
}

duplicateGuildboss_s::duplicateGuildboss_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int duplicateGuildboss_s::CreateInit() {
	duplicateID = (int64_t)0;
	rewardId = (int64_t)0;
	return 0;
}

int duplicateGuildboss_s::ResumeInit() {
	return 0;
}

void duplicateGuildboss_s::write_to_pbmsg(::proto_ff::duplicateGuildboss & msg) const {
	msg.set_duplicateid((int64_t)duplicateID);
	msg.set_rewardid((int64_t)rewardId);
	for(int32_t i = 0; i < (int32_t)kill.GetSize() && i < kill.GetMaxSize(); ++i) {
		::proto_ff::duplicateGuildbosskillDesc* temp_kill = msg.add_kill();
		kill[i].write_to_pbmsg(*temp_kill);
	}
}

void duplicateGuildboss_s::read_from_pbmsg(const ::proto_ff::duplicateGuildboss & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct duplicateGuildboss_s));
	duplicateID = msg.duplicateid();
	rewardId = msg.rewardid();
	kill.SetSize(msg.kill_size() > kill.GetMaxSize() ? kill.GetMaxSize() : msg.kill_size());
	for(int32_t i = 0; i < (int32_t)kill.GetSize(); ++i) {
		const ::proto_ff::duplicateGuildbosskillDesc & temp_kill = msg.kill(i);
		kill[i].read_from_pbmsg(temp_kill);
	}
}

Sheet_duplicateGuildboss_s::Sheet_duplicateGuildboss_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_duplicateGuildboss_s::CreateInit() {
	return 0;
}

int Sheet_duplicateGuildboss_s::ResumeInit() {
	return 0;
}

void Sheet_duplicateGuildboss_s::write_to_pbmsg(::proto_ff::Sheet_duplicateGuildboss & msg) const {
	for(int32_t i = 0; i < (int32_t)duplicateGuildboss_List.GetSize() && i < duplicateGuildboss_List.GetMaxSize(); ++i) {
		::proto_ff::duplicateGuildboss* temp_duplicateguildboss_list = msg.add_duplicateguildboss_list();
		duplicateGuildboss_List[i].write_to_pbmsg(*temp_duplicateguildboss_list);
	}
}

void Sheet_duplicateGuildboss_s::read_from_pbmsg(const ::proto_ff::Sheet_duplicateGuildboss & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_duplicateGuildboss_s));
	duplicateGuildboss_List.SetSize(msg.duplicateguildboss_list_size() > duplicateGuildboss_List.GetMaxSize() ? duplicateGuildboss_List.GetMaxSize() : msg.duplicateguildboss_list_size());
	for(int32_t i = 0; i < (int32_t)duplicateGuildboss_List.GetSize(); ++i) {
		const ::proto_ff::duplicateGuildboss & temp_duplicateguildboss_list = msg.duplicateguildboss_list(i);
		duplicateGuildboss_List[i].read_from_pbmsg(temp_duplicateguildboss_list);
	}
}

duplicateGuildDuplicate_s::duplicateGuildDuplicate_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int duplicateGuildDuplicate_s::CreateInit() {
	level = (int32_t)0;
	monsterExp = (int64_t)0;
	bossExp = (int64_t)0;
	return 0;
}

int duplicateGuildDuplicate_s::ResumeInit() {
	return 0;
}

void duplicateGuildDuplicate_s::write_to_pbmsg(::proto_ff::duplicateGuildDuplicate & msg) const {
	msg.set_level((int32_t)level);
	msg.set_monsterexp((int64_t)monsterExp);
	msg.set_bossexp((int64_t)bossExp);
}

void duplicateGuildDuplicate_s::read_from_pbmsg(const ::proto_ff::duplicateGuildDuplicate & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct duplicateGuildDuplicate_s));
	level = msg.level();
	monsterExp = msg.monsterexp();
	bossExp = msg.bossexp();
}

Sheet_duplicateGuildDuplicate_s::Sheet_duplicateGuildDuplicate_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_duplicateGuildDuplicate_s::CreateInit() {
	return 0;
}

int Sheet_duplicateGuildDuplicate_s::ResumeInit() {
	return 0;
}

void Sheet_duplicateGuildDuplicate_s::write_to_pbmsg(::proto_ff::Sheet_duplicateGuildDuplicate & msg) const {
	for(int32_t i = 0; i < (int32_t)duplicateGuildDuplicate_List.GetSize() && i < duplicateGuildDuplicate_List.GetMaxSize(); ++i) {
		::proto_ff::duplicateGuildDuplicate* temp_duplicateguildduplicate_list = msg.add_duplicateguildduplicate_list();
		duplicateGuildDuplicate_List[i].write_to_pbmsg(*temp_duplicateguildduplicate_list);
	}
}

void Sheet_duplicateGuildDuplicate_s::read_from_pbmsg(const ::proto_ff::Sheet_duplicateGuildDuplicate & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_duplicateGuildDuplicate_s));
	duplicateGuildDuplicate_List.SetSize(msg.duplicateguildduplicate_list_size() > duplicateGuildDuplicate_List.GetMaxSize() ? duplicateGuildDuplicate_List.GetMaxSize() : msg.duplicateguildduplicate_list_size());
	for(int32_t i = 0; i < (int32_t)duplicateGuildDuplicate_List.GetSize(); ++i) {
		const ::proto_ff::duplicateGuildDuplicate & temp_duplicateguildduplicate_list = msg.duplicateguildduplicate_list(i);
		duplicateGuildDuplicate_List[i].read_from_pbmsg(temp_duplicateguildduplicate_list);
	}
}

}