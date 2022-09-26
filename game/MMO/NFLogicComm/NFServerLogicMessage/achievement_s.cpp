#include "achievement_s.h"

namespace proto_ff_s {

achievementitemRewardDesc_s::achievementitemRewardDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int achievementitemRewardDesc_s::CreateInit() {
	ID = (int64_t)0;
	Value = (int32_t)0;
	return 0;
}

int achievementitemRewardDesc_s::ResumeInit() {
	return 0;
}

void achievementitemRewardDesc_s::write_to_pbmsg(::proto_ff::achievementitemRewardDesc & msg) const {
	msg.set_id((int64_t)ID);
	msg.set_value((int32_t)Value);
}

void achievementitemRewardDesc_s::read_from_pbmsg(const ::proto_ff::achievementitemRewardDesc & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct achievementitemRewardDesc_s));
	ID = msg.id();
	Value = msg.value();
}

achievementachievement_s::achievementachievement_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int achievementachievement_s::CreateInit() {
	achievementId = (int64_t)0;
	achievementLevel = (int32_t)0;
	achievementDTP = (int32_t)0;
	achievementType = (int32_t)0;
	achievementSubType = (int32_t)0;
	achievementObjectID = (int64_t)0;
	achievementObjectValue = (int32_t)0;
	achievementDia = (int32_t)0;
	achievementGod = (int32_t)0;
	achievementPoint = (int32_t)0;
	linkID = (int32_t)0;
	return 0;
}

int achievementachievement_s::ResumeInit() {
	return 0;
}

void achievementachievement_s::write_to_pbmsg(::proto_ff::achievementachievement & msg) const {
	msg.set_achievementid((int64_t)achievementId);
	msg.set_achievementlevel((int32_t)achievementLevel);
	msg.set_achievementdtp((int32_t)achievementDTP);
	msg.set_achievementtype((int32_t)achievementType);
	msg.set_achievementsubtype((int32_t)achievementSubType);
	msg.set_achievementobjectid((int64_t)achievementObjectID);
	msg.set_achievementobjectidstring((const char*)achievementObjectIDString.Get());
	msg.set_achievementobjectvalue((int32_t)achievementObjectValue);
	msg.set_achievementdia((int32_t)achievementDia);
	msg.set_achievementgod((int32_t)achievementGod);
	msg.set_achievementpoint((int32_t)achievementPoint);
	msg.set_linkid((int32_t)linkID);
	for(int32_t i = 0; i < (int32_t)itemReward.GetSize() && i < itemReward.GetMaxSize(); ++i) {
		::proto_ff::achievementitemRewardDesc* temp_itemreward = msg.add_itemreward();
		itemReward[i].write_to_pbmsg(*temp_itemreward);
	}
}

void achievementachievement_s::read_from_pbmsg(const ::proto_ff::achievementachievement & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct achievementachievement_s));
	achievementId = msg.achievementid();
	achievementLevel = msg.achievementlevel();
	achievementDTP = msg.achievementdtp();
	achievementType = msg.achievementtype();
	achievementSubType = msg.achievementsubtype();
	achievementObjectID = msg.achievementobjectid();
	achievementObjectIDString.Copy(msg.achievementobjectidstring());
	achievementObjectValue = msg.achievementobjectvalue();
	achievementDia = msg.achievementdia();
	achievementGod = msg.achievementgod();
	achievementPoint = msg.achievementpoint();
	linkID = msg.linkid();
	itemReward.SetSize(msg.itemreward_size() > itemReward.GetMaxSize() ? itemReward.GetMaxSize() : msg.itemreward_size());
	for(int32_t i = 0; i < (int32_t)itemReward.GetSize(); ++i) {
		const ::proto_ff::achievementitemRewardDesc & temp_itemreward = msg.itemreward(i);
		itemReward[i].read_from_pbmsg(temp_itemreward);
	}
}

Sheet_achievementachievement_s::Sheet_achievementachievement_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_achievementachievement_s::CreateInit() {
	return 0;
}

int Sheet_achievementachievement_s::ResumeInit() {
	return 0;
}

void Sheet_achievementachievement_s::write_to_pbmsg(::proto_ff::Sheet_achievementachievement & msg) const {
	for(int32_t i = 0; i < (int32_t)achievementachievement_List.GetSize() && i < achievementachievement_List.GetMaxSize(); ++i) {
		::proto_ff::achievementachievement* temp_achievementachievement_list = msg.add_achievementachievement_list();
		achievementachievement_List[i].write_to_pbmsg(*temp_achievementachievement_list);
	}
}

void Sheet_achievementachievement_s::read_from_pbmsg(const ::proto_ff::Sheet_achievementachievement & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_achievementachievement_s));
	achievementachievement_List.SetSize(msg.achievementachievement_list_size() > achievementachievement_List.GetMaxSize() ? achievementachievement_List.GetMaxSize() : msg.achievementachievement_list_size());
	for(int32_t i = 0; i < (int32_t)achievementachievement_List.GetSize(); ++i) {
		const ::proto_ff::achievementachievement & temp_achievementachievement_list = msg.achievementachievement_list(i);
		achievementachievement_List[i].read_from_pbmsg(temp_achievementachievement_list);
	}
}

achievementachievementreward_s::achievementachievementreward_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int achievementachievementreward_s::CreateInit() {
	achievementPrizeId = (int64_t)0;
	achievementType = (int32_t)0;
	achievementPointValue = (int32_t)0;
	achievementSkil = (int64_t)0;
	achievementDia = (int32_t)0;
	return 0;
}

int achievementachievementreward_s::ResumeInit() {
	return 0;
}

void achievementachievementreward_s::write_to_pbmsg(::proto_ff::achievementachievementreward & msg) const {
	msg.set_achievementprizeid((int64_t)achievementPrizeId);
	msg.set_achievementtype((int32_t)achievementType);
	msg.set_achievementpointvalue((int32_t)achievementPointValue);
	msg.set_achievementskil((int64_t)achievementSkil);
	msg.set_achievementdia((int32_t)achievementDia);
}

void achievementachievementreward_s::read_from_pbmsg(const ::proto_ff::achievementachievementreward & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct achievementachievementreward_s));
	achievementPrizeId = msg.achievementprizeid();
	achievementType = msg.achievementtype();
	achievementPointValue = msg.achievementpointvalue();
	achievementSkil = msg.achievementskil();
	achievementDia = msg.achievementdia();
}

Sheet_achievementachievementreward_s::Sheet_achievementachievementreward_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_achievementachievementreward_s::CreateInit() {
	return 0;
}

int Sheet_achievementachievementreward_s::ResumeInit() {
	return 0;
}

void Sheet_achievementachievementreward_s::write_to_pbmsg(::proto_ff::Sheet_achievementachievementreward & msg) const {
	for(int32_t i = 0; i < (int32_t)achievementachievementreward_List.GetSize() && i < achievementachievementreward_List.GetMaxSize(); ++i) {
		::proto_ff::achievementachievementreward* temp_achievementachievementreward_list = msg.add_achievementachievementreward_list();
		achievementachievementreward_List[i].write_to_pbmsg(*temp_achievementachievementreward_list);
	}
}

void Sheet_achievementachievementreward_s::read_from_pbmsg(const ::proto_ff::Sheet_achievementachievementreward & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_achievementachievementreward_s));
	achievementachievementreward_List.SetSize(msg.achievementachievementreward_list_size() > achievementachievementreward_List.GetMaxSize() ? achievementachievementreward_List.GetMaxSize() : msg.achievementachievementreward_list_size());
	for(int32_t i = 0; i < (int32_t)achievementachievementreward_List.GetSize(); ++i) {
		const ::proto_ff::achievementachievementreward & temp_achievementachievementreward_list = msg.achievementachievementreward_list(i);
		achievementachievementreward_List[i].read_from_pbmsg(temp_achievementachievementreward_list);
	}
}

achievementachievenName_s::achievementachievenName_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int achievementachievenName_s::CreateInit() {
	return 0;
}

int achievementachievenName_s::ResumeInit() {
	return 0;
}

void achievementachievenName_s::write_to_pbmsg(::proto_ff::achievementachievenName & msg) const {
}

void achievementachievenName_s::read_from_pbmsg(const ::proto_ff::achievementachievenName & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct achievementachievenName_s));
}

Sheet_achievementachievenName_s::Sheet_achievementachievenName_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_achievementachievenName_s::CreateInit() {
	return 0;
}

int Sheet_achievementachievenName_s::ResumeInit() {
	return 0;
}

void Sheet_achievementachievenName_s::write_to_pbmsg(::proto_ff::Sheet_achievementachievenName & msg) const {
	for(int32_t i = 0; i < (int32_t)achievementachievenName_List.GetSize() && i < achievementachievenName_List.GetMaxSize(); ++i) {
		::proto_ff::achievementachievenName* temp_achievementachievenname_list = msg.add_achievementachievenname_list();
		achievementachievenName_List[i].write_to_pbmsg(*temp_achievementachievenname_list);
	}
}

void Sheet_achievementachievenName_s::read_from_pbmsg(const ::proto_ff::Sheet_achievementachievenName & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_achievementachievenName_s));
	achievementachievenName_List.SetSize(msg.achievementachievenname_list_size() > achievementachievenName_List.GetMaxSize() ? achievementachievenName_List.GetMaxSize() : msg.achievementachievenname_list_size());
	for(int32_t i = 0; i < (int32_t)achievementachievenName_List.GetSize(); ++i) {
		const ::proto_ff::achievementachievenName & temp_achievementachievenname_list = msg.achievementachievenname_list(i);
		achievementachievenName_List[i].read_from_pbmsg(temp_achievementachievenname_list);
	}
}

}