#include "warland_s.h"

namespace proto_ff_s {

warlandconstant_s::warlandconstant_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int warlandconstant_s::CreateInit() {
	id = (int32_t)0;
	winscore = (int32_t)0;
	scoreareaID = (int64_t)0;
	OccupyScore = (int32_t)0;
	OccupyContribution = (int32_t)0;
	KillArea = (int32_t)0;
	KillContribution = (int32_t)0;
	KillRangeContribution = (int32_t)0;
	KillRange = (int32_t)0;
	SkillIdA = (int64_t)0;
	SkillIdB = (int64_t)0;
	GuardskillId = (int64_t)0;
	PrepareBuff = (int64_t)0;
	PrepareTime = (int32_t)0;
	invincibleSkillId = (int64_t)0;
	allplayerSkillId = (int64_t)0;
	killHelpPoint = (int32_t)0;
	return 0;
}

int warlandconstant_s::ResumeInit() {
	return 0;
}

void warlandconstant_s::write_to_pbmsg(::proto_ff::warlandconstant & msg) const {
	msg.set_id((int32_t)id);
	msg.set_winscore((int32_t)winscore);
	msg.set_scoreareaid((int64_t)scoreareaID);
	msg.set_occupyscore((int32_t)OccupyScore);
	msg.set_occupycontribution((int32_t)OccupyContribution);
	msg.set_killarea((int32_t)KillArea);
	msg.set_killcontribution((int32_t)KillContribution);
	msg.set_killrangecontribution((int32_t)KillRangeContribution);
	msg.set_killrange((int32_t)KillRange);
	msg.set_skillida((int64_t)SkillIdA);
	msg.set_skillidb((int64_t)SkillIdB);
	msg.set_guardskillid((int64_t)GuardskillId);
	msg.set_continuouskillbuffid((const char*)ContinuousKillBuffId.Get());
	msg.set_winreward((const char*)WinReward.Get());
	msg.set_losereward((const char*)LoseReward.Get());
	msg.set_preparebuff((int64_t)PrepareBuff);
	msg.set_preparetime((int32_t)PrepareTime);
	msg.set_invincibleskillid((int64_t)invincibleSkillId);
	msg.set_allplayerskillid((int64_t)allplayerSkillId);
	msg.set_killhelppoint((int32_t)killHelpPoint);
}

void warlandconstant_s::read_from_pbmsg(const ::proto_ff::warlandconstant & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct warlandconstant_s));
	id = msg.id();
	winscore = msg.winscore();
	scoreareaID = msg.scoreareaid();
	OccupyScore = msg.occupyscore();
	OccupyContribution = msg.occupycontribution();
	KillArea = msg.killarea();
	KillContribution = msg.killcontribution();
	KillRangeContribution = msg.killrangecontribution();
	KillRange = msg.killrange();
	SkillIdA = msg.skillida();
	SkillIdB = msg.skillidb();
	GuardskillId = msg.guardskillid();
	ContinuousKillBuffId.Copy(msg.continuouskillbuffid());
	WinReward.Copy(msg.winreward());
	LoseReward.Copy(msg.losereward());
	PrepareBuff = msg.preparebuff();
	PrepareTime = msg.preparetime();
	invincibleSkillId = msg.invincibleskillid();
	allplayerSkillId = msg.allplayerskillid();
	killHelpPoint = msg.killhelppoint();
}

Sheet_warlandconstant_s::Sheet_warlandconstant_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_warlandconstant_s::CreateInit() {
	return 0;
}

int Sheet_warlandconstant_s::ResumeInit() {
	return 0;
}

void Sheet_warlandconstant_s::write_to_pbmsg(::proto_ff::Sheet_warlandconstant & msg) const {
	for(int32_t i = 0; i < (int32_t)warlandconstant_List.GetSize() && i < warlandconstant_List.GetMaxSize(); ++i) {
		::proto_ff::warlandconstant* temp_warlandconstant_list = msg.add_warlandconstant_list();
		warlandconstant_List[i].write_to_pbmsg(*temp_warlandconstant_list);
	}
}

void Sheet_warlandconstant_s::read_from_pbmsg(const ::proto_ff::Sheet_warlandconstant & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_warlandconstant_s));
	warlandconstant_List.SetSize(msg.warlandconstant_list_size() > warlandconstant_List.GetMaxSize() ? warlandconstant_List.GetMaxSize() : msg.warlandconstant_list_size());
	for(int32_t i = 0; i < (int32_t)warlandconstant_List.GetSize(); ++i) {
		const ::proto_ff::warlandconstant & temp_warlandconstant_list = msg.warlandconstant_list(i);
		warlandconstant_List[i].read_from_pbmsg(temp_warlandconstant_list);
	}
}

warlandmultiKill_s::warlandmultiKill_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int warlandmultiKill_s::CreateInit() {
	multiKillNum = (int32_t)0;
	endMultiKillscore = (int32_t)0;
	endMultiKillPoint = (int32_t)0;
	return 0;
}

int warlandmultiKill_s::ResumeInit() {
	return 0;
}

void warlandmultiKill_s::write_to_pbmsg(::proto_ff::warlandmultiKill & msg) const {
	msg.set_multikillnum((int32_t)multiKillNum);
	msg.set_multikillicon((const char*)multiKillIcon.Get());
	msg.set_endmultikillscore((int32_t)endMultiKillscore);
	msg.set_endmultikillpoint((int32_t)endMultiKillPoint);
}

void warlandmultiKill_s::read_from_pbmsg(const ::proto_ff::warlandmultiKill & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct warlandmultiKill_s));
	multiKillNum = msg.multikillnum();
	multiKillIcon.Copy(msg.multikillicon());
	endMultiKillscore = msg.endmultikillscore();
	endMultiKillPoint = msg.endmultikillpoint();
}

Sheet_warlandmultiKill_s::Sheet_warlandmultiKill_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_warlandmultiKill_s::CreateInit() {
	return 0;
}

int Sheet_warlandmultiKill_s::ResumeInit() {
	return 0;
}

void Sheet_warlandmultiKill_s::write_to_pbmsg(::proto_ff::Sheet_warlandmultiKill & msg) const {
	for(int32_t i = 0; i < (int32_t)warlandmultiKill_List.GetSize() && i < warlandmultiKill_List.GetMaxSize(); ++i) {
		::proto_ff::warlandmultiKill* temp_warlandmultikill_list = msg.add_warlandmultikill_list();
		warlandmultiKill_List[i].write_to_pbmsg(*temp_warlandmultikill_list);
	}
}

void Sheet_warlandmultiKill_s::read_from_pbmsg(const ::proto_ff::Sheet_warlandmultiKill & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_warlandmultiKill_s));
	warlandmultiKill_List.SetSize(msg.warlandmultikill_list_size() > warlandmultiKill_List.GetMaxSize() ? warlandmultiKill_List.GetMaxSize() : msg.warlandmultikill_list_size());
	for(int32_t i = 0; i < (int32_t)warlandmultiKill_List.GetSize(); ++i) {
		const ::proto_ff::warlandmultiKill & temp_warlandmultikill_list = msg.warlandmultikill_list(i);
		warlandmultiKill_List[i].read_from_pbmsg(temp_warlandmultikill_list);
	}
}

warlandrankreward_s::warlandrankreward_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int warlandrankreward_s::CreateInit() {
	stageId = (int32_t)0;
	MinRanking = (int32_t)0;
	MaxRanking = (int32_t)0;
	return 0;
}

int warlandrankreward_s::ResumeInit() {
	return 0;
}

void warlandrankreward_s::write_to_pbmsg(::proto_ff::warlandrankreward & msg) const {
	msg.set_stageid((int32_t)stageId);
	msg.set_minranking((int32_t)MinRanking);
	msg.set_maxranking((int32_t)MaxRanking);
	msg.set_reward((const char*)Reward.Get());
}

void warlandrankreward_s::read_from_pbmsg(const ::proto_ff::warlandrankreward & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct warlandrankreward_s));
	stageId = msg.stageid();
	MinRanking = msg.minranking();
	MaxRanking = msg.maxranking();
	Reward.Copy(msg.reward());
}

Sheet_warlandrankreward_s::Sheet_warlandrankreward_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_warlandrankreward_s::CreateInit() {
	return 0;
}

int Sheet_warlandrankreward_s::ResumeInit() {
	return 0;
}

void Sheet_warlandrankreward_s::write_to_pbmsg(::proto_ff::Sheet_warlandrankreward & msg) const {
	for(int32_t i = 0; i < (int32_t)warlandrankreward_List.GetSize() && i < warlandrankreward_List.GetMaxSize(); ++i) {
		::proto_ff::warlandrankreward* temp_warlandrankreward_list = msg.add_warlandrankreward_list();
		warlandrankreward_List[i].write_to_pbmsg(*temp_warlandrankreward_list);
	}
}

void Sheet_warlandrankreward_s::read_from_pbmsg(const ::proto_ff::Sheet_warlandrankreward & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_warlandrankreward_s));
	warlandrankreward_List.SetSize(msg.warlandrankreward_list_size() > warlandrankreward_List.GetMaxSize() ? warlandrankreward_List.GetMaxSize() : msg.warlandrankreward_list_size());
	for(int32_t i = 0; i < (int32_t)warlandrankreward_List.GetSize(); ++i) {
		const ::proto_ff::warlandrankreward & temp_warlandrankreward_list = msg.warlandrankreward_list(i);
		warlandrankreward_List[i].read_from_pbmsg(temp_warlandrankreward_list);
	}
}

}