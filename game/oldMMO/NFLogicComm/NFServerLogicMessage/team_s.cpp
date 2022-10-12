#include "team_s.h"

namespace proto_ff_s {

teamteam_s::teamteam_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int teamteam_s::CreateInit() {
	TeamObjectID = (int32_t)0;
	FObjectNameID = (int32_t)0;
	SObjectNameID = (int32_t)0;
	duplicateId = (int64_t)0;
	activityId = (int64_t)0;
	LowLV = (int32_t)0;
	UpLV = (int32_t)0;
	isAutoMatch = (int32_t)0;
	speakChannel = (int32_t)0;
	teamnumber = (int32_t)0;
	return 0;
}

int teamteam_s::ResumeInit() {
	return 0;
}

void teamteam_s::write_to_pbmsg(::proto_ff::teamteam & msg) const {
	msg.set_teamobjectid((int32_t)TeamObjectID);
	msg.set_fobjectnameid((int32_t)FObjectNameID);
	msg.set_sobjectnameid((int32_t)SObjectNameID);
	msg.set_duplicateid((int64_t)duplicateId);
	msg.set_activityid((int64_t)activityId);
	msg.set_lowlv((int32_t)LowLV);
	msg.set_uplv((int32_t)UpLV);
	msg.set_isautomatch((int32_t)isAutoMatch);
	msg.set_speakchannel((int32_t)speakChannel);
	msg.set_teamnumber((int32_t)teamnumber);
}

void teamteam_s::read_from_pbmsg(const ::proto_ff::teamteam & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct teamteam_s));
	TeamObjectID = msg.teamobjectid();
	FObjectNameID = msg.fobjectnameid();
	SObjectNameID = msg.sobjectnameid();
	duplicateId = msg.duplicateid();
	activityId = msg.activityid();
	LowLV = msg.lowlv();
	UpLV = msg.uplv();
	isAutoMatch = msg.isautomatch();
	speakChannel = msg.speakchannel();
	teamnumber = msg.teamnumber();
}

Sheet_teamteam_s::Sheet_teamteam_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_teamteam_s::CreateInit() {
	return 0;
}

int Sheet_teamteam_s::ResumeInit() {
	return 0;
}

void Sheet_teamteam_s::write_to_pbmsg(::proto_ff::Sheet_teamteam & msg) const {
	for(int32_t i = 0; i < (int32_t)teamteam_List.GetSize() && i < teamteam_List.GetMaxSize(); ++i) {
		::proto_ff::teamteam* temp_teamteam_list = msg.add_teamteam_list();
		teamteam_List[i].write_to_pbmsg(*temp_teamteam_list);
	}
}

void Sheet_teamteam_s::read_from_pbmsg(const ::proto_ff::Sheet_teamteam & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_teamteam_s));
	teamteam_List.SetSize(msg.teamteam_list_size() > teamteam_List.GetMaxSize() ? teamteam_List.GetMaxSize() : msg.teamteam_list_size());
	for(int32_t i = 0; i < (int32_t)teamteam_List.GetSize(); ++i) {
		const ::proto_ff::teamteam & temp_teamteam_list = msg.teamteam_list(i);
		teamteam_List[i].read_from_pbmsg(temp_teamteam_list);
	}
}

}