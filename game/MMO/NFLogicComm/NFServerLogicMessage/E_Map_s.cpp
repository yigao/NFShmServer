#include "E_Map_s.h"

namespace proto_ff_s {

E_MapMap_s::E_MapMap_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_MapMap_s::CreateInit() {
	m_mapId = (int64_t)0;
	m_levelLimit = (int32_t)0;
	m_isDyn = (int32_t)0;
	m_mapType = (int32_t)0;
	m_mapSubType = (int32_t)0;
	m_clearanceTime = (int32_t)0;
	m_mapPkmode = (int32_t)0;
	m_pklock = (int32_t)0;
	m_pk = (int32_t)0;
	m_killValue = (int32_t)0;
	m_BanGroup = (int32_t)0;
	m_reviveTime = (int32_t)0;
	m_mapWide = (int32_t)0;
	m_mapHeight = (int32_t)0;
	m_reviveSkill = (int64_t)0;
	m_reviveInPlaceType = (int32_t)0;
	m_isHangUp = (int32_t)0;
	m_itemDropType = (int32_t)0;
	m_linkOffLine = (int64_t)0;
	m_banOnHook = (int32_t)0;
	m_Rewait = (int32_t)0;
	m_REtime = (int32_t)0;
	m_HREBan = (int32_t)0;
	m_Retiered = (int32_t)0;
	m_REskillid = (int32_t)0;
	m_Reteimes = (int32_t)0;
	m_drivePoint = (int32_t)0;
	m_dieDP = (int32_t)0;
	m_timeDP = (int32_t)0;
	m_meditation = (int32_t)0;
	m_banMount = (int32_t)0;
	m_banLink = (int32_t)0;
	m_lvSupPvp = (int32_t)0;
	m_powerSupPvp = (int32_t)0;
	return 0;
}

int E_MapMap_s::ResumeInit() {
	return 0;
}

void E_MapMap_s::write_to_pbmsg(::proto_ff::E_MapMap & msg) const {
	msg.set_m_mapid((int64_t)m_mapId);
	msg.set_m_levellimit((int32_t)m_levelLimit);
	msg.set_m_advicelv(m_adviceLv.data());
	msg.set_m_isdyn((int32_t)m_isDyn);
	msg.set_m_maptype((int32_t)m_mapType);
	msg.set_m_mapsubtype((int32_t)m_mapSubType);
	msg.set_m_clearancetime((int32_t)m_clearanceTime);
	msg.set_m_mappkmode((int32_t)m_mapPkmode);
	msg.set_m_mappkvalue(m_mapPkValue.data());
	msg.set_m_pklock((int32_t)m_pklock);
	msg.set_m_pk((int32_t)m_pk);
	msg.set_m_killvalue((int32_t)m_killValue);
	msg.set_m_bangroup((int32_t)m_BanGroup);
	msg.set_m_revivetime((int32_t)m_reviveTime);
	msg.set_m_mapwide((int32_t)m_mapWide);
	msg.set_m_mapheight((int32_t)m_mapHeight);
	msg.set_m_mapresources(m_mapResources.data());
	msg.set_m_reviveskill((int64_t)m_reviveSkill);
	msg.set_m_reviveinplacetype((int32_t)m_reviveInPlaceType);
	msg.set_m_ishangup((int32_t)m_isHangUp);
	msg.set_m_itemdroptype((int32_t)m_itemDropType);
	msg.set_m_itemdropid(m_itemDropID.data());
	msg.set_m_linkoffline((int64_t)m_linkOffLine);
	msg.set_m_banonhook((int32_t)m_banOnHook);
	msg.set_m_rewait((int32_t)m_Rewait);
	msg.set_m_retime((int32_t)m_REtime);
	msg.set_m_hreban((int32_t)m_HREBan);
	msg.set_m_retiered((int32_t)m_Retiered);
	msg.set_m_reskillid((int32_t)m_REskillid);
	msg.set_m_reteimes((int32_t)m_Reteimes);
	msg.set_m_drivepoint((int32_t)m_drivePoint);
	msg.set_m_diedp((int32_t)m_dieDP);
	msg.set_m_timedp((int32_t)m_timeDP);
	msg.set_m_meditation((int32_t)m_meditation);
	msg.set_m_mapbutton(m_mapButton.data());
	msg.set_m_banmount((int32_t)m_banMount);
	msg.set_m_banlink((int32_t)m_banLink);
	msg.set_m_lvsuppvp((int32_t)m_lvSupPvp);
	msg.set_m_powersuppvp((int32_t)m_powerSupPvp);
}

void E_MapMap_s::read_from_pbmsg(const ::proto_ff::E_MapMap & msg) {
	m_mapId = msg.m_mapid();
	m_levelLimit = msg.m_levellimit();
	m_adviceLv = msg.m_advicelv();
	m_isDyn = msg.m_isdyn();
	m_mapType = msg.m_maptype();
	m_mapSubType = msg.m_mapsubtype();
	m_clearanceTime = msg.m_clearancetime();
	m_mapPkmode = msg.m_mappkmode();
	m_mapPkValue = msg.m_mappkvalue();
	m_pklock = msg.m_pklock();
	m_pk = msg.m_pk();
	m_killValue = msg.m_killvalue();
	m_BanGroup = msg.m_bangroup();
	m_reviveTime = msg.m_revivetime();
	m_mapWide = msg.m_mapwide();
	m_mapHeight = msg.m_mapheight();
	m_mapResources = msg.m_mapresources();
	m_reviveSkill = msg.m_reviveskill();
	m_reviveInPlaceType = msg.m_reviveinplacetype();
	m_isHangUp = msg.m_ishangup();
	m_itemDropType = msg.m_itemdroptype();
	m_itemDropID = msg.m_itemdropid();
	m_linkOffLine = msg.m_linkoffline();
	m_banOnHook = msg.m_banonhook();
	m_Rewait = msg.m_rewait();
	m_REtime = msg.m_retime();
	m_HREBan = msg.m_hreban();
	m_Retiered = msg.m_retiered();
	m_REskillid = msg.m_reskillid();
	m_Reteimes = msg.m_reteimes();
	m_drivePoint = msg.m_drivepoint();
	m_dieDP = msg.m_diedp();
	m_timeDP = msg.m_timedp();
	m_meditation = msg.m_meditation();
	m_mapButton = msg.m_mapbutton();
	m_banMount = msg.m_banmount();
	m_banLink = msg.m_banlink();
	m_lvSupPvp = msg.m_lvsuppvp();
	m_powerSupPvp = msg.m_powersuppvp();
}

Sheet_MapMap_s::Sheet_MapMap_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_MapMap_s::CreateInit() {
	return 0;
}

int Sheet_MapMap_s::ResumeInit() {
	return 0;
}

void Sheet_MapMap_s::write_to_pbmsg(::proto_ff::Sheet_MapMap & msg) const {
	for(int32_t i = 0; i < (int32_t)E_MapMap_List.size(); ++i) {
		::proto_ff::E_MapMap* temp_e_mapmap_list = msg.add_e_mapmap_list();
		E_MapMap_List[i].write_to_pbmsg(*temp_e_mapmap_list);
	}
}

void Sheet_MapMap_s::read_from_pbmsg(const ::proto_ff::Sheet_MapMap & msg) {
	E_MapMap_List.resize((int)msg.e_mapmap_list_size() > (int)E_MapMap_List.max_size() ? E_MapMap_List.max_size() : msg.e_mapmap_list_size());
	for(int32_t i = 0; i < (int32_t)E_MapMap_List.size(); ++i) {
		const ::proto_ff::E_MapMap & temp_e_mapmap_list = msg.e_mapmap_list(i);
		E_MapMap_List[i].read_from_pbmsg(temp_e_mapmap_list);
	}
}

E_MapItemdrop_s::E_MapItemdrop_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_MapItemdrop_s::CreateInit() {
	m_itemDropID = (int32_t)0;
	m_dropType = (int32_t)0;
	m_odds = (int32_t)0;
	m_ownProtect = (int32_t)0;
	m_belongType = (int32_t)0;
	m_numMax = (int32_t)0;
	m_dropvaluea = (int32_t)0;
	m_dropvalueb = (int32_t)0;
	m_dropvaluec = (int32_t)0;
	m_dropvalued = (int32_t)0;
	m_dropvaluee = (int32_t)0;
	m_dropvaluef = (int32_t)0;
	return 0;
}

int E_MapItemdrop_s::ResumeInit() {
	return 0;
}

void E_MapItemdrop_s::write_to_pbmsg(::proto_ff::E_MapItemdrop & msg) const {
	msg.set_m_itemdropid((int32_t)m_itemDropID);
	msg.set_m_droptype((int32_t)m_dropType);
	msg.set_m_odds((int32_t)m_odds);
	msg.set_m_ownprotect((int32_t)m_ownProtect);
	msg.set_m_belongtype((int32_t)m_belongType);
	msg.set_m_nummax((int32_t)m_numMax);
	msg.set_m_dropvaluea((int32_t)m_dropvaluea);
	msg.set_m_dropvalueb((int32_t)m_dropvalueb);
	msg.set_m_dropvaluec((int32_t)m_dropvaluec);
	msg.set_m_dropvalued((int32_t)m_dropvalued);
	msg.set_m_dropvaluee((int32_t)m_dropvaluee);
	msg.set_m_dropvaluef((int32_t)m_dropvaluef);
}

void E_MapItemdrop_s::read_from_pbmsg(const ::proto_ff::E_MapItemdrop & msg) {
	m_itemDropID = msg.m_itemdropid();
	m_dropType = msg.m_droptype();
	m_odds = msg.m_odds();
	m_ownProtect = msg.m_ownprotect();
	m_belongType = msg.m_belongtype();
	m_numMax = msg.m_nummax();
	m_dropvaluea = msg.m_dropvaluea();
	m_dropvalueb = msg.m_dropvalueb();
	m_dropvaluec = msg.m_dropvaluec();
	m_dropvalued = msg.m_dropvalued();
	m_dropvaluee = msg.m_dropvaluee();
	m_dropvaluef = msg.m_dropvaluef();
}

Sheet_MapItemdrop_s::Sheet_MapItemdrop_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_MapItemdrop_s::CreateInit() {
	return 0;
}

int Sheet_MapItemdrop_s::ResumeInit() {
	return 0;
}

void Sheet_MapItemdrop_s::write_to_pbmsg(::proto_ff::Sheet_MapItemdrop & msg) const {
	for(int32_t i = 0; i < (int32_t)E_MapItemdrop_List.size(); ++i) {
		::proto_ff::E_MapItemdrop* temp_e_mapitemdrop_list = msg.add_e_mapitemdrop_list();
		E_MapItemdrop_List[i].write_to_pbmsg(*temp_e_mapitemdrop_list);
	}
}

void Sheet_MapItemdrop_s::read_from_pbmsg(const ::proto_ff::Sheet_MapItemdrop & msg) {
	E_MapItemdrop_List.resize((int)msg.e_mapitemdrop_list_size() > (int)E_MapItemdrop_List.max_size() ? E_MapItemdrop_List.max_size() : msg.e_mapitemdrop_list_size());
	for(int32_t i = 0; i < (int32_t)E_MapItemdrop_List.size(); ++i) {
		const ::proto_ff::E_MapItemdrop & temp_e_mapitemdrop_list = msg.e_mapitemdrop_list(i);
		E_MapItemdrop_List[i].read_from_pbmsg(temp_e_mapitemdrop_list);
	}
}

E_MapDestroyitem_s::E_MapDestroyitem_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_MapDestroyitem_s::CreateInit() {
	m_destroyitemID = (int64_t)0;
	return 0;
}

int E_MapDestroyitem_s::ResumeInit() {
	return 0;
}

void E_MapDestroyitem_s::write_to_pbmsg(::proto_ff::E_MapDestroyitem & msg) const {
	msg.set_m_destroyitemid((int64_t)m_destroyitemID);
}

void E_MapDestroyitem_s::read_from_pbmsg(const ::proto_ff::E_MapDestroyitem & msg) {
	m_destroyitemID = msg.m_destroyitemid();
}

Sheet_MapDestroyitem_s::Sheet_MapDestroyitem_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_MapDestroyitem_s::CreateInit() {
	return 0;
}

int Sheet_MapDestroyitem_s::ResumeInit() {
	return 0;
}

void Sheet_MapDestroyitem_s::write_to_pbmsg(::proto_ff::Sheet_MapDestroyitem & msg) const {
	for(int32_t i = 0; i < (int32_t)E_MapDestroyitem_List.size(); ++i) {
		::proto_ff::E_MapDestroyitem* temp_e_mapdestroyitem_list = msg.add_e_mapdestroyitem_list();
		E_MapDestroyitem_List[i].write_to_pbmsg(*temp_e_mapdestroyitem_list);
	}
}

void Sheet_MapDestroyitem_s::read_from_pbmsg(const ::proto_ff::Sheet_MapDestroyitem & msg) {
	E_MapDestroyitem_List.resize((int)msg.e_mapdestroyitem_list_size() > (int)E_MapDestroyitem_List.max_size() ? E_MapDestroyitem_List.max_size() : msg.e_mapdestroyitem_list_size());
	for(int32_t i = 0; i < (int32_t)E_MapDestroyitem_List.size(); ++i) {
		const ::proto_ff::E_MapDestroyitem & temp_e_mapdestroyitem_list = msg.e_mapdestroyitem_list(i);
		E_MapDestroyitem_List[i].read_from_pbmsg(temp_e_mapdestroyitem_list);
	}
}

E_MapButton_s::E_MapButton_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_MapButton_s::CreateInit() {
	m_id = (int32_t)0;
	m_type = (int32_t)0;
	m_arg1 = (int32_t)0;
	m_arg2 = (int32_t)0;
	return 0;
}

int E_MapButton_s::ResumeInit() {
	return 0;
}

void E_MapButton_s::write_to_pbmsg(::proto_ff::E_MapButton & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_type((int32_t)m_type);
	msg.set_m_arg1((int32_t)m_arg1);
	msg.set_m_arg2((int32_t)m_arg2);
}

void E_MapButton_s::read_from_pbmsg(const ::proto_ff::E_MapButton & msg) {
	m_id = msg.m_id();
	m_type = msg.m_type();
	m_arg1 = msg.m_arg1();
	m_arg2 = msg.m_arg2();
}

Sheet_MapButton_s::Sheet_MapButton_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_MapButton_s::CreateInit() {
	return 0;
}

int Sheet_MapButton_s::ResumeInit() {
	return 0;
}

void Sheet_MapButton_s::write_to_pbmsg(::proto_ff::Sheet_MapButton & msg) const {
	for(int32_t i = 0; i < (int32_t)E_MapButton_List.size(); ++i) {
		::proto_ff::E_MapButton* temp_e_mapbutton_list = msg.add_e_mapbutton_list();
		E_MapButton_List[i].write_to_pbmsg(*temp_e_mapbutton_list);
	}
}

void Sheet_MapButton_s::read_from_pbmsg(const ::proto_ff::Sheet_MapButton & msg) {
	E_MapButton_List.resize((int)msg.e_mapbutton_list_size() > (int)E_MapButton_List.max_size() ? E_MapButton_List.max_size() : msg.e_mapbutton_list_size());
	for(int32_t i = 0; i < (int32_t)E_MapButton_List.size(); ++i) {
		const ::proto_ff::E_MapButton & temp_e_mapbutton_list = msg.e_mapbutton_list(i);
		E_MapButton_List[i].read_from_pbmsg(temp_e_mapbutton_list);
	}
}

E_MapInspireRewardDesc_s::E_MapInspireRewardDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_MapInspireRewardDesc_s::CreateInit() {
	m_Num = (int32_t)0;
	m_Id = (int32_t)0;
	return 0;
}

int E_MapInspireRewardDesc_s::ResumeInit() {
	return 0;
}

void E_MapInspireRewardDesc_s::write_to_pbmsg(::proto_ff::E_MapInspireRewardDesc & msg) const {
	msg.set_m_num((int32_t)m_Num);
	msg.set_m_id((int32_t)m_Id);
}

void E_MapInspireRewardDesc_s::read_from_pbmsg(const ::proto_ff::E_MapInspireRewardDesc & msg) {
	m_Num = msg.m_num();
	m_Id = msg.m_id();
}

E_MapInspire_s::E_MapInspire_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_MapInspire_s::CreateInit() {
	m_id = (int32_t)0;
	m_group = (int32_t)0;
	m_costId = (int32_t)0;
	m_costNum = (int32_t)0;
	m_skillid = (int32_t)0;
	m_times = (int32_t)0;
	return 0;
}

int E_MapInspire_s::ResumeInit() {
	return 0;
}

void E_MapInspire_s::write_to_pbmsg(::proto_ff::E_MapInspire & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_group((int32_t)m_group);
	msg.set_m_name(m_name.data());
	msg.set_m_costid((int32_t)m_costId);
	msg.set_m_costnum((int32_t)m_costNum);
	msg.set_m_skillid((int32_t)m_skillid);
	msg.set_m_times((int32_t)m_times);
	for(int32_t i = 0; i < (int32_t)m_reward.size(); ++i) {
		::proto_ff::E_MapInspireRewardDesc* temp_m_reward = msg.add_m_reward();
		m_reward[i].write_to_pbmsg(*temp_m_reward);
	}
}

void E_MapInspire_s::read_from_pbmsg(const ::proto_ff::E_MapInspire & msg) {
	m_id = msg.m_id();
	m_group = msg.m_group();
	m_name = msg.m_name();
	m_costId = msg.m_costid();
	m_costNum = msg.m_costnum();
	m_skillid = msg.m_skillid();
	m_times = msg.m_times();
	m_reward.resize((int)msg.m_reward_size() > (int)m_reward.max_size() ? m_reward.max_size() : msg.m_reward_size());
	for(int32_t i = 0; i < (int32_t)m_reward.size(); ++i) {
		const ::proto_ff::E_MapInspireRewardDesc & temp_m_reward = msg.m_reward(i);
		m_reward[i].read_from_pbmsg(temp_m_reward);
	}
}

Sheet_MapInspire_s::Sheet_MapInspire_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_MapInspire_s::CreateInit() {
	return 0;
}

int Sheet_MapInspire_s::ResumeInit() {
	return 0;
}

void Sheet_MapInspire_s::write_to_pbmsg(::proto_ff::Sheet_MapInspire & msg) const {
	for(int32_t i = 0; i < (int32_t)E_MapInspire_List.size(); ++i) {
		::proto_ff::E_MapInspire* temp_e_mapinspire_list = msg.add_e_mapinspire_list();
		E_MapInspire_List[i].write_to_pbmsg(*temp_e_mapinspire_list);
	}
}

void Sheet_MapInspire_s::read_from_pbmsg(const ::proto_ff::Sheet_MapInspire & msg) {
	E_MapInspire_List.resize((int)msg.e_mapinspire_list_size() > (int)E_MapInspire_List.max_size() ? E_MapInspire_List.max_size() : msg.e_mapinspire_list_size());
	for(int32_t i = 0; i < (int32_t)E_MapInspire_List.size(); ++i) {
		const ::proto_ff::E_MapInspire & temp_e_mapinspire_list = msg.e_mapinspire_list(i);
		E_MapInspire_List[i].read_from_pbmsg(temp_e_mapinspire_list);
	}
}

}
