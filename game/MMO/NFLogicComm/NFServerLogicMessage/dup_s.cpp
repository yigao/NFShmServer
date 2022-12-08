#include "dup_s.h"

namespace proto_ff_s {

dupBPlevel_s::dupBPlevel_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int dupBPlevel_s::CreateInit() {
	lv = (int32_t)0;
	return 0;
}

int dupBPlevel_s::ResumeInit() {
	return 0;
}

void dupBPlevel_s::write_to_pbmsg(::proto_ff::dupBPlevel & msg) const {
	msg.set_lv((int32_t)lv);
	for(int32_t i = 0; i < (int32_t)Bgdup.GetSize() && i < Bgdup.GetMaxSize(); ++i) {
		msg.add_bgdup((int64_t)Bgdup[i]);
	}
}

void dupBPlevel_s::read_from_pbmsg(const ::proto_ff::dupBPlevel & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct dupBPlevel_s));
	lv = msg.lv();
	Bgdup.SetSize(msg.bgdup_size() > Bgdup.GetMaxSize() ? Bgdup.GetMaxSize() : msg.bgdup_size());
	for(int32_t i = 0; i < (int32_t)Bgdup.GetSize(); ++i) {
		Bgdup[i] = msg.bgdup(i);
	}
}

Sheet_dupBPlevel_s::Sheet_dupBPlevel_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_dupBPlevel_s::CreateInit() {
	return 0;
}

int Sheet_dupBPlevel_s::ResumeInit() {
	return 0;
}

void Sheet_dupBPlevel_s::write_to_pbmsg(::proto_ff::Sheet_dupBPlevel & msg) const {
	for(int32_t i = 0; i < (int32_t)dupBPlevel_List.GetSize() && i < dupBPlevel_List.GetMaxSize(); ++i) {
		::proto_ff::dupBPlevel* temp_dupbplevel_list = msg.add_dupbplevel_list();
		dupBPlevel_List[i].write_to_pbmsg(*temp_dupbplevel_list);
	}
}

void Sheet_dupBPlevel_s::read_from_pbmsg(const ::proto_ff::Sheet_dupBPlevel & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_dupBPlevel_s));
	dupBPlevel_List.SetSize(msg.dupbplevel_list_size() > dupBPlevel_List.GetMaxSize() ? dupBPlevel_List.GetMaxSize() : msg.dupbplevel_list_size());
	for(int32_t i = 0; i < (int32_t)dupBPlevel_List.GetSize(); ++i) {
		const ::proto_ff::dupBPlevel & temp_dupbplevel_list = msg.dupbplevel_list(i);
		dupBPlevel_List[i].read_from_pbmsg(temp_dupbplevel_list);
	}
}

dupdup_s::dupdup_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int dupdup_s::CreateInit() {
	ID = (int32_t)0;
	scripID = (int32_t)0;
	scripType = (int32_t)0;
	dupLevel = (int32_t)0;
	groupID = (int32_t)0;
	layer = (int32_t)0;
	duplicateType = (int32_t)0;
	mapID = (int64_t)0;
	levelLimit = (int32_t)0;
	pre = (int32_t)0;
	isAutoFight = (int32_t)0;
	reviveMaxTimes = (int32_t)0;
	TeamObjectID = (int32_t)0;
	sweepRewardBoxID = (int64_t)0;
	sweepRewardExp = (int32_t)0;
	isPatrol = (int32_t)0;
	sweepType = (int32_t)0;
	return 0;
}

int dupdup_s::ResumeInit() {
	return 0;
}

void dupdup_s::write_to_pbmsg(::proto_ff::dupdup & msg) const {
	msg.set_id((int32_t)ID);
	msg.set_scripid((int32_t)scripID);
	msg.set_scriptype((int32_t)scripType);
	msg.set_duplevel((int32_t)dupLevel);
	msg.set_groupid((int32_t)groupID);
	msg.set_layer((int32_t)layer);
	msg.set_duplicatetype((int32_t)duplicateType);
	msg.set_mapid((int64_t)mapID);
	msg.set_levellimit((int32_t)levelLimit);
	msg.set_pre((int32_t)pre);
	msg.set_isautofight((int32_t)isAutoFight);
	msg.set_condition((const char*)condition.Get());
	msg.set_revivemaxtimes((int32_t)reviveMaxTimes);
	msg.set_teamobjectid((int32_t)TeamObjectID);
	msg.set_gradecondition((const char*)gradeCondition.Get());
	msg.set_sweeprewardboxid((int64_t)sweepRewardBoxID);
	msg.set_sweeprewardexp((int32_t)sweepRewardExp);
	msg.set_trackpoint((const char*)trackpoint.Get());
	msg.set_pathofmonster((const char*)pathOfmonster.Get());
	msg.set_ispatrol((int32_t)isPatrol);
	msg.set_sweeptype((int32_t)sweepType);
	for(int32_t i = 0; i < (int32_t)box.GetSize() && i < box.GetMaxSize(); ++i) {
		msg.add_box((int32_t)box[i]);
	}
}

void dupdup_s::read_from_pbmsg(const ::proto_ff::dupdup & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct dupdup_s));
	ID = msg.id();
	scripID = msg.scripid();
	scripType = msg.scriptype();
	dupLevel = msg.duplevel();
	groupID = msg.groupid();
	layer = msg.layer();
	duplicateType = msg.duplicatetype();
	mapID = msg.mapid();
	levelLimit = msg.levellimit();
	pre = msg.pre();
	isAutoFight = msg.isautofight();
	condition.Copy(msg.condition());
	reviveMaxTimes = msg.revivemaxtimes();
	TeamObjectID = msg.teamobjectid();
	gradeCondition.Copy(msg.gradecondition());
	sweepRewardBoxID = msg.sweeprewardboxid();
	sweepRewardExp = msg.sweeprewardexp();
	trackpoint.Copy(msg.trackpoint());
	pathOfmonster.Copy(msg.pathofmonster());
	isPatrol = msg.ispatrol();
	sweepType = msg.sweeptype();
	box.SetSize(msg.box_size() > box.GetMaxSize() ? box.GetMaxSize() : msg.box_size());
	for(int32_t i = 0; i < (int32_t)box.GetSize(); ++i) {
		box[i] = msg.box(i);
	}
}

Sheet_dupdup_s::Sheet_dupdup_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_dupdup_s::CreateInit() {
	return 0;
}

int Sheet_dupdup_s::ResumeInit() {
	return 0;
}

void Sheet_dupdup_s::write_to_pbmsg(::proto_ff::Sheet_dupdup & msg) const {
	for(int32_t i = 0; i < (int32_t)dupdup_List.GetSize() && i < dupdup_List.GetMaxSize(); ++i) {
		::proto_ff::dupdup* temp_dupdup_list = msg.add_dupdup_list();
		dupdup_List[i].write_to_pbmsg(*temp_dupdup_list);
	}
}

void Sheet_dupdup_s::read_from_pbmsg(const ::proto_ff::Sheet_dupdup & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_dupdup_s));
	dupdup_List.SetSize(msg.dupdup_list_size() > dupdup_List.GetMaxSize() ? dupdup_List.GetMaxSize() : msg.dupdup_list_size());
	for(int32_t i = 0; i < (int32_t)dupdup_List.GetSize(); ++i) {
		const ::proto_ff::dupdup & temp_dupdup_list = msg.dupdup_list(i);
		dupdup_List[i].read_from_pbmsg(temp_dupdup_list);
	}
}

duptowerReward_s::duptowerReward_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int duptowerReward_s::CreateInit() {
	id = (int32_t)0;
	type = (int32_t)0;
	cond = (int32_t)0;
	boxID = (int32_t)0;
	return 0;
}

int duptowerReward_s::ResumeInit() {
	return 0;
}

void duptowerReward_s::write_to_pbmsg(::proto_ff::duptowerReward & msg) const {
	msg.set_id((int32_t)id);
	msg.set_type((int32_t)type);
	msg.set_cond((int32_t)cond);
	msg.set_boxid((int32_t)boxID);
}

void duptowerReward_s::read_from_pbmsg(const ::proto_ff::duptowerReward & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct duptowerReward_s));
	id = msg.id();
	type = msg.type();
	cond = msg.cond();
	boxID = msg.boxid();
}

Sheet_duptowerReward_s::Sheet_duptowerReward_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_duptowerReward_s::CreateInit() {
	return 0;
}

int Sheet_duptowerReward_s::ResumeInit() {
	return 0;
}

void Sheet_duptowerReward_s::write_to_pbmsg(::proto_ff::Sheet_duptowerReward & msg) const {
	for(int32_t i = 0; i < (int32_t)duptowerReward_List.GetSize() && i < duptowerReward_List.GetMaxSize(); ++i) {
		::proto_ff::duptowerReward* temp_duptowerreward_list = msg.add_duptowerreward_list();
		duptowerReward_List[i].write_to_pbmsg(*temp_duptowerreward_list);
	}
}

void Sheet_duptowerReward_s::read_from_pbmsg(const ::proto_ff::Sheet_duptowerReward & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_duptowerReward_s));
	duptowerReward_List.SetSize(msg.duptowerreward_list_size() > duptowerReward_List.GetMaxSize() ? duptowerReward_List.GetMaxSize() : msg.duptowerreward_list_size());
	for(int32_t i = 0; i < (int32_t)duptowerReward_List.GetSize(); ++i) {
		const ::proto_ff::duptowerReward & temp_duptowerreward_list = msg.duptowerreward_list(i);
		duptowerReward_List[i].read_from_pbmsg(temp_duptowerreward_list);
	}
}

dupgroup_s::dupgroup_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int dupgroup_s::CreateInit() {
	id = (int32_t)0;
	privilegeType = (int32_t)0;
	dynamiclevel = (int32_t)0;
	groupTimesType = (int32_t)0;
	groupTimes = (int32_t)0;
	enterItemID = (int32_t)0;
	sweepCondition = (int32_t)0;
	mergeCondition = (int32_t)0;
	addItemID = (int32_t)0;
	buyType = (int32_t)0;
	buyItemId = (int32_t)0;
	countDown = (int32_t)0;
	endDown = (int32_t)0;
	accountDown = (int32_t)0;
	funcionID = (int32_t)0;
	return 0;
}

int dupgroup_s::ResumeInit() {
	return 0;
}

void dupgroup_s::write_to_pbmsg(::proto_ff::dupgroup & msg) const {
	msg.set_id((int32_t)id);
	msg.set_name((const char*)name.Get());
	msg.set_privilegetype((int32_t)privilegeType);
	msg.set_dynamiclevel((int32_t)dynamiclevel);
	msg.set_grouptimestype((int32_t)groupTimesType);
	msg.set_grouptimes((int32_t)groupTimes);
	msg.set_enteritemid((int32_t)enterItemID);
	msg.set_sweepcondition((int32_t)sweepCondition);
	msg.set_mergecondition((int32_t)mergeCondition);
	msg.set_additemid((int32_t)addItemID);
	msg.set_buytype((int32_t)buyType);
	msg.set_buyitemid((int32_t)buyItemId);
	msg.set_buycost((const char*)buyCost.Get());
	msg.set_countdown((int32_t)countDown);
	msg.set_enddown((int32_t)endDown);
	msg.set_accountdown((int32_t)accountDown);
	msg.set_funcionid((int32_t)funcionID);
}

void dupgroup_s::read_from_pbmsg(const ::proto_ff::dupgroup & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct dupgroup_s));
	id = msg.id();
	name.Copy(msg.name());
	privilegeType = msg.privilegetype();
	dynamiclevel = msg.dynamiclevel();
	groupTimesType = msg.grouptimestype();
	groupTimes = msg.grouptimes();
	enterItemID = msg.enteritemid();
	sweepCondition = msg.sweepcondition();
	mergeCondition = msg.mergecondition();
	addItemID = msg.additemid();
	buyType = msg.buytype();
	buyItemId = msg.buyitemid();
	buyCost.Copy(msg.buycost());
	countDown = msg.countdown();
	endDown = msg.enddown();
	accountDown = msg.accountdown();
	funcionID = msg.funcionid();
}

Sheet_dupgroup_s::Sheet_dupgroup_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_dupgroup_s::CreateInit() {
	return 0;
}

int Sheet_dupgroup_s::ResumeInit() {
	return 0;
}

void Sheet_dupgroup_s::write_to_pbmsg(::proto_ff::Sheet_dupgroup & msg) const {
	for(int32_t i = 0; i < (int32_t)dupgroup_List.GetSize() && i < dupgroup_List.GetMaxSize(); ++i) {
		::proto_ff::dupgroup* temp_dupgroup_list = msg.add_dupgroup_list();
		dupgroup_List[i].write_to_pbmsg(*temp_dupgroup_list);
	}
}

void Sheet_dupgroup_s::read_from_pbmsg(const ::proto_ff::Sheet_dupgroup & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_dupgroup_s));
	dupgroup_List.SetSize(msg.dupgroup_list_size() > dupgroup_List.GetMaxSize() ? dupgroup_List.GetMaxSize() : msg.dupgroup_list_size());
	for(int32_t i = 0; i < (int32_t)dupgroup_List.GetSize(); ++i) {
		const ::proto_ff::dupgroup & temp_dupgroup_list = msg.dupgroup_list(i);
		dupgroup_List[i].read_from_pbmsg(temp_dupgroup_list);
	}
}

}