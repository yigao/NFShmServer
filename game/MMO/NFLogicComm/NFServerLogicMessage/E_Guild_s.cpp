#include "E_Guild_s.h"

namespace proto_ff_s {

E_GuildConstant_s::E_GuildConstant_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_GuildConstant_s::CreateInit() {
	m_constantid = (int32_t)0;
	m_setItem = (int32_t)0;
	m_nameItem = (int32_t)0;
	m_EditRequireLV = (int32_t)0;
	m_giftCD = (int32_t)0;
	m_dismiss = (int32_t)0;
	m_transferGuild = (int32_t)0;
	m_territory = (int32_t)0;
	m_autoMinLV = (int32_t)0;
	m_autoMinBP = (int32_t)0;
	m_donateTimes = (int32_t)0;
	m_packetMaxD = (int32_t)0;
	m_packetMaxBD = (int32_t)0;
	m_packetMaxSend = (int32_t)0;
	m_packetvip = (int32_t)0;
	m_packetAdd = (int32_t)0;
	m_prestigeTasOneKeyVIP = (int32_t)0;
	m_prestigeTasOneKeyLV = (int32_t)0;
	m_prestigeTaskPrivage = (int32_t)0;
	m_prestigeTaskFlash = (int32_t)0;
	m_prestigeTaskflashPrice = (int32_t)0;
	m_prestigeTaskTimes = (int32_t)0;
	m_rewardCD = (int32_t)0;
	m_answerdelay = (int32_t)0;
	m_answerNum = (int32_t)0;
	m_answerTime = (int32_t)0;
	m_answerResultTime = (int32_t)0;
	m_answerLimit = (int32_t)0;
	m_answerFirst = (int32_t)0;
	m_answerSuccess = (int32_t)0;
	m_answeBasics = (int32_t)0;
	m_linkLvUpPer = (int32_t)0;
	m_linkLvUpMax = (int32_t)0;
	m_linkTime = (int32_t)0;
	m_monsterID = (int32_t)0;
	m_point = (int32_t)0;
	m_collectTimes = (int32_t)0;
	m_shens_dayTimes = (int32_t)0;
	m_shens_weekTimes = (int32_t)0;
	m_shens_dup = (int32_t)0;
	m_shensItem = (int32_t)0;
	m_shensCost = (int32_t)0;
	m_shensCostActive = (int32_t)0;
	m_shouh_dup = (int32_t)0;
	m_shouhExpSkill = (int32_t)0;
	m_GWDupid = (int32_t)0;
	m_GWBattleTime = (int32_t)0;
	m_GWRestTime = (int32_t)0;
	m_GWCenterMID = (int32_t)0;
	m_GWTowerMID = (int32_t)0;
	m_GWTankMID = (int32_t)0;
	m_GWBornRPoint = (int32_t)0;
	m_GWCenterRPoint = (int32_t)0;
	m_GWTankRPoint = (int32_t)0;
	m_GWBornBPoint = (int32_t)0;
	m_GWCenterBPoint = (int32_t)0;
	m_GWTankBPoint = (int32_t)0;
	m_tankNum = (int32_t)0;
	m_tankRestTime = (int32_t)0;
	m_tankRestNum = (int32_t)0;
	m_dominateDaily = (int32_t)0;
	m_dominateBossReward = (int32_t)0;
	m_freePoint = (int32_t)0;
	m_defFreePoint = (int32_t)0;
	m_playerPoint = (int32_t)0;
	m_tankPoint = (int32_t)0;
	m_towerPoint = (int32_t)0;
	m_centerPoint = (int32_t)0;
	m_assistRadio = (int32_t)0;
	m_TTeamDamageAdd = (int32_t)0;
	m_TWeekCloseTime = (int32_t)0;
	m_cyclicReward = (int32_t)0;
	m_tenCyclicReward = (int32_t)0;
	return 0;
}

int E_GuildConstant_s::ResumeInit() {
	return 0;
}

void E_GuildConstant_s::write_to_pbmsg(::proto_ff::E_GuildConstant & msg) const {
	msg.set_m_constantid((int32_t)m_constantid);
	msg.set_m_setitem((int32_t)m_setItem);
	msg.set_m_nameitem((int32_t)m_nameItem);
	msg.set_m_editrequirelv((int32_t)m_EditRequireLV);
	msg.set_m_giftcd((int32_t)m_giftCD);
	msg.set_m_dismiss((int32_t)m_dismiss);
	msg.set_m_transferguild((int32_t)m_transferGuild);
	msg.set_m_territory((int32_t)m_territory);
	msg.set_m_autominlv((int32_t)m_autoMinLV);
	msg.set_m_autominbp((int32_t)m_autoMinBP);
	msg.set_m_donatetimes((int32_t)m_donateTimes);
	msg.set_m_packetmaxd((int32_t)m_packetMaxD);
	msg.set_m_packetmaxbd((int32_t)m_packetMaxBD);
	msg.set_m_packetmaxsend((int32_t)m_packetMaxSend);
	msg.set_m_packetvip((int32_t)m_packetvip);
	msg.set_m_packetadd((int32_t)m_packetAdd);
	msg.set_m_prestigetasonekeyvip((int32_t)m_prestigeTasOneKeyVIP);
	msg.set_m_prestigetasonekeylv((int32_t)m_prestigeTasOneKeyLV);
	msg.set_m_prestigetaskprivage((int32_t)m_prestigeTaskPrivage);
	msg.set_m_prestigetaskflash((int32_t)m_prestigeTaskFlash);
	msg.set_m_prestigetaskflashprice((int32_t)m_prestigeTaskflashPrice);
	msg.set_m_prestigetasktimes((int32_t)m_prestigeTaskTimes);
	msg.set_m_rewardcd((int32_t)m_rewardCD);
	msg.set_m_answerdelay((int32_t)m_answerdelay);
	msg.set_m_answernum((int32_t)m_answerNum);
	msg.set_m_answertime((int32_t)m_answerTime);
	msg.set_m_answerresulttime((int32_t)m_answerResultTime);
	msg.set_m_answerlimit((int32_t)m_answerLimit);
	msg.set_m_answerfirst((int32_t)m_answerFirst);
	msg.set_m_answersuccess((int32_t)m_answerSuccess);
	msg.set_m_answebasics((int32_t)m_answeBasics);
	msg.set_m_linklvupper((int32_t)m_linkLvUpPer);
	msg.set_m_linklvupmax((int32_t)m_linkLvUpMax);
	msg.set_m_linktime((int32_t)m_linkTime);
	msg.set_m_monsterid((int32_t)m_monsterID);
	msg.set_m_point((int32_t)m_point);
	msg.set_m_collecttimes((int32_t)m_collectTimes);
	msg.set_m_shens_daytimes((int32_t)m_shens_dayTimes);
	msg.set_m_shens_weektimes((int32_t)m_shens_weekTimes);
	msg.set_m_shens_dup((int32_t)m_shens_dup);
	msg.set_m_shensitem((int32_t)m_shensItem);
	msg.set_m_shenscost((int32_t)m_shensCost);
	msg.set_m_shenscostactive((int32_t)m_shensCostActive);
	msg.set_m_shouh_dup((int32_t)m_shouh_dup);
	msg.set_m_shouhexpskill((int32_t)m_shouhExpSkill);
	msg.set_m_shouhmosid(m_shouhMosId.data());
	msg.set_m_gwdupid((int32_t)m_GWDupid);
	msg.set_m_gwbattletime((int32_t)m_GWBattleTime);
	msg.set_m_gwresttime((int32_t)m_GWRestTime);
	msg.set_m_gwcentermid((int32_t)m_GWCenterMID);
	msg.set_m_gwtowermid((int32_t)m_GWTowerMID);
	msg.set_m_gwtankmid((int32_t)m_GWTankMID);
	msg.set_m_gwbornrpoint((int32_t)m_GWBornRPoint);
	msg.set_m_gwcenterrpoint((int32_t)m_GWCenterRPoint);
	msg.set_m_gwtowerrpoint(m_GWTowerRPoint.data());
	msg.set_m_gwtankrpoint((int32_t)m_GWTankRPoint);
	msg.set_m_gwbornbpoint((int32_t)m_GWBornBPoint);
	msg.set_m_gwcenterbpoint((int32_t)m_GWCenterBPoint);
	msg.set_m_gwtowerbpoint(m_GWTowerBPoint.data());
	msg.set_m_gwtankbpoint((int32_t)m_GWTankBPoint);
	msg.set_m_tanknum((int32_t)m_tankNum);
	msg.set_m_tankresttime((int32_t)m_tankRestTime);
	msg.set_m_tankrestnum((int32_t)m_tankRestNum);
	msg.set_m_dominatedaily((int32_t)m_dominateDaily);
	msg.set_m_dominatebossreward((int32_t)m_dominateBossReward);
	msg.set_m_freepoint((int32_t)m_freePoint);
	msg.set_m_deffreepoint((int32_t)m_defFreePoint);
	msg.set_m_playerpoint((int32_t)m_playerPoint);
	msg.set_m_tankpoint((int32_t)m_tankPoint);
	msg.set_m_towerpoint((int32_t)m_towerPoint);
	msg.set_m_centerpoint((int32_t)m_centerPoint);
	msg.set_m_assistradio((int32_t)m_assistRadio);
	msg.set_m_tteamdamageadd((int32_t)m_TTeamDamageAdd);
	msg.set_m_tweekclosetime((int32_t)m_TWeekCloseTime);
	msg.set_m_cyclicreward((int32_t)m_cyclicReward);
	msg.set_m_tencyclicreward((int32_t)m_tenCyclicReward);
}

void E_GuildConstant_s::read_from_pbmsg(const ::proto_ff::E_GuildConstant & msg) {
	m_constantid = msg.m_constantid();
	m_setItem = msg.m_setitem();
	m_nameItem = msg.m_nameitem();
	m_EditRequireLV = msg.m_editrequirelv();
	m_giftCD = msg.m_giftcd();
	m_dismiss = msg.m_dismiss();
	m_transferGuild = msg.m_transferguild();
	m_territory = msg.m_territory();
	m_autoMinLV = msg.m_autominlv();
	m_autoMinBP = msg.m_autominbp();
	m_donateTimes = msg.m_donatetimes();
	m_packetMaxD = msg.m_packetmaxd();
	m_packetMaxBD = msg.m_packetmaxbd();
	m_packetMaxSend = msg.m_packetmaxsend();
	m_packetvip = msg.m_packetvip();
	m_packetAdd = msg.m_packetadd();
	m_prestigeTasOneKeyVIP = msg.m_prestigetasonekeyvip();
	m_prestigeTasOneKeyLV = msg.m_prestigetasonekeylv();
	m_prestigeTaskPrivage = msg.m_prestigetaskprivage();
	m_prestigeTaskFlash = msg.m_prestigetaskflash();
	m_prestigeTaskflashPrice = msg.m_prestigetaskflashprice();
	m_prestigeTaskTimes = msg.m_prestigetasktimes();
	m_rewardCD = msg.m_rewardcd();
	m_answerdelay = msg.m_answerdelay();
	m_answerNum = msg.m_answernum();
	m_answerTime = msg.m_answertime();
	m_answerResultTime = msg.m_answerresulttime();
	m_answerLimit = msg.m_answerlimit();
	m_answerFirst = msg.m_answerfirst();
	m_answerSuccess = msg.m_answersuccess();
	m_answeBasics = msg.m_answebasics();
	m_linkLvUpPer = msg.m_linklvupper();
	m_linkLvUpMax = msg.m_linklvupmax();
	m_linkTime = msg.m_linktime();
	m_monsterID = msg.m_monsterid();
	m_point = msg.m_point();
	m_collectTimes = msg.m_collecttimes();
	m_shens_dayTimes = msg.m_shens_daytimes();
	m_shens_weekTimes = msg.m_shens_weektimes();
	m_shens_dup = msg.m_shens_dup();
	m_shensItem = msg.m_shensitem();
	m_shensCost = msg.m_shenscost();
	m_shensCostActive = msg.m_shenscostactive();
	m_shouh_dup = msg.m_shouh_dup();
	m_shouhExpSkill = msg.m_shouhexpskill();
	m_shouhMosId = msg.m_shouhmosid();
	m_GWDupid = msg.m_gwdupid();
	m_GWBattleTime = msg.m_gwbattletime();
	m_GWRestTime = msg.m_gwresttime();
	m_GWCenterMID = msg.m_gwcentermid();
	m_GWTowerMID = msg.m_gwtowermid();
	m_GWTankMID = msg.m_gwtankmid();
	m_GWBornRPoint = msg.m_gwbornrpoint();
	m_GWCenterRPoint = msg.m_gwcenterrpoint();
	m_GWTowerRPoint = msg.m_gwtowerrpoint();
	m_GWTankRPoint = msg.m_gwtankrpoint();
	m_GWBornBPoint = msg.m_gwbornbpoint();
	m_GWCenterBPoint = msg.m_gwcenterbpoint();
	m_GWTowerBPoint = msg.m_gwtowerbpoint();
	m_GWTankBPoint = msg.m_gwtankbpoint();
	m_tankNum = msg.m_tanknum();
	m_tankRestTime = msg.m_tankresttime();
	m_tankRestNum = msg.m_tankrestnum();
	m_dominateDaily = msg.m_dominatedaily();
	m_dominateBossReward = msg.m_dominatebossreward();
	m_freePoint = msg.m_freepoint();
	m_defFreePoint = msg.m_deffreepoint();
	m_playerPoint = msg.m_playerpoint();
	m_tankPoint = msg.m_tankpoint();
	m_towerPoint = msg.m_towerpoint();
	m_centerPoint = msg.m_centerpoint();
	m_assistRadio = msg.m_assistradio();
	m_TTeamDamageAdd = msg.m_tteamdamageadd();
	m_TWeekCloseTime = msg.m_tweekclosetime();
	m_cyclicReward = msg.m_cyclicreward();
	m_tenCyclicReward = msg.m_tencyclicreward();
}

Sheet_GuildConstant_s::Sheet_GuildConstant_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_GuildConstant_s::CreateInit() {
	return 0;
}

int Sheet_GuildConstant_s::ResumeInit() {
	return 0;
}

void Sheet_GuildConstant_s::write_to_pbmsg(::proto_ff::Sheet_GuildConstant & msg) const {
	for(int32_t i = 0; i < (int32_t)E_GuildConstant_List.size(); ++i) {
		::proto_ff::E_GuildConstant* temp_e_guildconstant_list = msg.add_e_guildconstant_list();
		E_GuildConstant_List[i].write_to_pbmsg(*temp_e_guildconstant_list);
	}
}

void Sheet_GuildConstant_s::read_from_pbmsg(const ::proto_ff::Sheet_GuildConstant & msg) {
	E_GuildConstant_List.resize((int)msg.e_guildconstant_list_size() > (int)E_GuildConstant_List.max_size() ? E_GuildConstant_List.max_size() : msg.e_guildconstant_list_size());
	for(int32_t i = 0; i < (int32_t)E_GuildConstant_List.size(); ++i) {
		const ::proto_ff::E_GuildConstant & temp_e_guildconstant_list = msg.e_guildconstant_list(i);
		E_GuildConstant_List[i].read_from_pbmsg(temp_e_guildconstant_list);
	}
}

E_GuildLevel_s::E_GuildLevel_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_GuildLevel_s::CreateInit() {
	m_guildLevel = (int32_t)0;
	m_guildLevel_EXP = (int32_t)0;
	m_guildLevel_member = (int32_t)0;
	m_guildLevel_VP = (int32_t)0;
	m_guildLevel_NP = (int32_t)0;
	m_guildLevel_G = (int32_t)0;
	return 0;
}

int E_GuildLevel_s::ResumeInit() {
	return 0;
}

void E_GuildLevel_s::write_to_pbmsg(::proto_ff::E_GuildLevel & msg) const {
	msg.set_m_guildlevel((int32_t)m_guildLevel);
	msg.set_m_guildlevel_exp((int32_t)m_guildLevel_EXP);
	msg.set_m_guildlevel_member((int32_t)m_guildLevel_member);
	msg.set_m_guildlevel_vp((int32_t)m_guildLevel_VP);
	msg.set_m_guildlevel_np((int32_t)m_guildLevel_NP);
	msg.set_m_guildlevel_g((int32_t)m_guildLevel_G);
}

void E_GuildLevel_s::read_from_pbmsg(const ::proto_ff::E_GuildLevel & msg) {
	m_guildLevel = msg.m_guildlevel();
	m_guildLevel_EXP = msg.m_guildlevel_exp();
	m_guildLevel_member = msg.m_guildlevel_member();
	m_guildLevel_VP = msg.m_guildlevel_vp();
	m_guildLevel_NP = msg.m_guildlevel_np();
	m_guildLevel_G = msg.m_guildlevel_g();
}

Sheet_GuildLevel_s::Sheet_GuildLevel_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_GuildLevel_s::CreateInit() {
	return 0;
}

int Sheet_GuildLevel_s::ResumeInit() {
	return 0;
}

void Sheet_GuildLevel_s::write_to_pbmsg(::proto_ff::Sheet_GuildLevel & msg) const {
	for(int32_t i = 0; i < (int32_t)E_GuildLevel_List.size(); ++i) {
		::proto_ff::E_GuildLevel* temp_e_guildlevel_list = msg.add_e_guildlevel_list();
		E_GuildLevel_List[i].write_to_pbmsg(*temp_e_guildlevel_list);
	}
}

void Sheet_GuildLevel_s::read_from_pbmsg(const ::proto_ff::Sheet_GuildLevel & msg) {
	E_GuildLevel_List.resize((int)msg.e_guildlevel_list_size() > (int)E_GuildLevel_List.max_size() ? E_GuildLevel_List.max_size() : msg.e_guildlevel_list_size());
	for(int32_t i = 0; i < (int32_t)E_GuildLevel_List.size(); ++i) {
		const ::proto_ff::E_GuildLevel & temp_e_guildlevel_list = msg.e_guildlevel_list(i);
		E_GuildLevel_List[i].read_from_pbmsg(temp_e_guildlevel_list);
	}
}

E_GuildPosition_s::E_GuildPosition_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_GuildPosition_s::CreateInit() {
	m_positionId = (int32_t)0;
	m_admitNewcomer = (int32_t)0;
	m_appointAndRemoveVP = (int32_t)0;
	m_appointAndRemoveElder = (int32_t)0;
	m_appointAndRemoveG = (int32_t)0;
	m_appointAndRemoveElite = (int32_t)0;
	m_expelVP = (int32_t)0;
	m_expelElder = (int32_t)0;
	m_expelG = (int32_t)0;
	m_expelMass = (int32_t)0;
	m_announcementEditing = (int32_t)0;
	m_rName = (int32_t)0;
	m_joinCondition = (int32_t)0;
	m_guildActivity = (int32_t)0;
	m_dissolveAssignGuild = (int32_t)0;
	m_changeName = (int32_t)0;
	m_recruitChat = (int32_t)0;
	m_guildPacket = (int32_t)0;
	m_UpGuard = (int32_t)0;
	return 0;
}

int E_GuildPosition_s::ResumeInit() {
	return 0;
}

void E_GuildPosition_s::write_to_pbmsg(::proto_ff::E_GuildPosition & msg) const {
	msg.set_m_positionid((int32_t)m_positionId);
	msg.set_m_admitnewcomer((int32_t)m_admitNewcomer);
	msg.set_m_appointandremovevp((int32_t)m_appointAndRemoveVP);
	msg.set_m_appointandremoveelder((int32_t)m_appointAndRemoveElder);
	msg.set_m_appointandremoveg((int32_t)m_appointAndRemoveG);
	msg.set_m_appointandremoveelite((int32_t)m_appointAndRemoveElite);
	msg.set_m_expelvp((int32_t)m_expelVP);
	msg.set_m_expelelder((int32_t)m_expelElder);
	msg.set_m_expelg((int32_t)m_expelG);
	msg.set_m_expelmass((int32_t)m_expelMass);
	msg.set_m_announcementediting((int32_t)m_announcementEditing);
	msg.set_m_rname((int32_t)m_rName);
	msg.set_m_joincondition((int32_t)m_joinCondition);
	msg.set_m_guildactivity((int32_t)m_guildActivity);
	msg.set_m_dissolveassignguild((int32_t)m_dissolveAssignGuild);
	msg.set_m_changename((int32_t)m_changeName);
	msg.set_m_recruitchat((int32_t)m_recruitChat);
	msg.set_m_guildpacket((int32_t)m_guildPacket);
	msg.set_m_upguard((int32_t)m_UpGuard);
}

void E_GuildPosition_s::read_from_pbmsg(const ::proto_ff::E_GuildPosition & msg) {
	m_positionId = msg.m_positionid();
	m_admitNewcomer = msg.m_admitnewcomer();
	m_appointAndRemoveVP = msg.m_appointandremovevp();
	m_appointAndRemoveElder = msg.m_appointandremoveelder();
	m_appointAndRemoveG = msg.m_appointandremoveg();
	m_appointAndRemoveElite = msg.m_appointandremoveelite();
	m_expelVP = msg.m_expelvp();
	m_expelElder = msg.m_expelelder();
	m_expelG = msg.m_expelg();
	m_expelMass = msg.m_expelmass();
	m_announcementEditing = msg.m_announcementediting();
	m_rName = msg.m_rname();
	m_joinCondition = msg.m_joincondition();
	m_guildActivity = msg.m_guildactivity();
	m_dissolveAssignGuild = msg.m_dissolveassignguild();
	m_changeName = msg.m_changename();
	m_recruitChat = msg.m_recruitchat();
	m_guildPacket = msg.m_guildpacket();
	m_UpGuard = msg.m_upguard();
}

Sheet_GuildPosition_s::Sheet_GuildPosition_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_GuildPosition_s::CreateInit() {
	return 0;
}

int Sheet_GuildPosition_s::ResumeInit() {
	return 0;
}

void Sheet_GuildPosition_s::write_to_pbmsg(::proto_ff::Sheet_GuildPosition & msg) const {
	for(int32_t i = 0; i < (int32_t)E_GuildPosition_List.size(); ++i) {
		::proto_ff::E_GuildPosition* temp_e_guildposition_list = msg.add_e_guildposition_list();
		E_GuildPosition_List[i].write_to_pbmsg(*temp_e_guildposition_list);
	}
}

void Sheet_GuildPosition_s::read_from_pbmsg(const ::proto_ff::Sheet_GuildPosition & msg) {
	E_GuildPosition_List.resize((int)msg.e_guildposition_list_size() > (int)E_GuildPosition_List.max_size() ? E_GuildPosition_List.max_size() : msg.e_guildposition_list_size());
	for(int32_t i = 0; i < (int32_t)E_GuildPosition_List.size(); ++i) {
		const ::proto_ff::E_GuildPosition & temp_e_guildposition_list = msg.e_guildposition_list(i);
		E_GuildPosition_List[i].read_from_pbmsg(temp_e_guildposition_list);
	}
}

E_GuildSalaryRewardDesc_s::E_GuildSalaryRewardDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_GuildSalaryRewardDesc_s::CreateInit() {
	m_num = (int32_t)0;
	m_item = (int32_t)0;
	return 0;
}

int E_GuildSalaryRewardDesc_s::ResumeInit() {
	return 0;
}

void E_GuildSalaryRewardDesc_s::write_to_pbmsg(::proto_ff::E_GuildSalaryRewardDesc & msg) const {
	msg.set_m_num((int32_t)m_num);
	msg.set_m_item((int32_t)m_item);
}

void E_GuildSalaryRewardDesc_s::read_from_pbmsg(const ::proto_ff::E_GuildSalaryRewardDesc & msg) {
	m_num = msg.m_num();
	m_item = msg.m_item();
}

E_GuildSalary_s::E_GuildSalary_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_GuildSalary_s::CreateInit() {
	m_ID = (int32_t)0;
	m_type = (int32_t)0;
	m_typeArg = (int32_t)0;
	m_times = (int32_t)0;
	return 0;
}

int E_GuildSalary_s::ResumeInit() {
	return 0;
}

void E_GuildSalary_s::write_to_pbmsg(::proto_ff::E_GuildSalary & msg) const {
	msg.set_m_id((int32_t)m_ID);
	msg.set_m_type((int32_t)m_type);
	msg.set_m_typearg((int32_t)m_typeArg);
	msg.set_m_times((int32_t)m_times);
	for(int32_t i = 0; i < (int32_t)m_reward.size(); ++i) {
		::proto_ff::E_GuildSalaryRewardDesc* temp_m_reward = msg.add_m_reward();
		m_reward[i].write_to_pbmsg(*temp_m_reward);
	}
}

void E_GuildSalary_s::read_from_pbmsg(const ::proto_ff::E_GuildSalary & msg) {
	m_ID = msg.m_id();
	m_type = msg.m_type();
	m_typeArg = msg.m_typearg();
	m_times = msg.m_times();
	m_reward.resize((int)msg.m_reward_size() > (int)m_reward.max_size() ? m_reward.max_size() : msg.m_reward_size());
	for(int32_t i = 0; i < (int32_t)m_reward.size(); ++i) {
		const ::proto_ff::E_GuildSalaryRewardDesc & temp_m_reward = msg.m_reward(i);
		m_reward[i].read_from_pbmsg(temp_m_reward);
	}
}

Sheet_GuildSalary_s::Sheet_GuildSalary_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_GuildSalary_s::CreateInit() {
	return 0;
}

int Sheet_GuildSalary_s::ResumeInit() {
	return 0;
}

void Sheet_GuildSalary_s::write_to_pbmsg(::proto_ff::Sheet_GuildSalary & msg) const {
	for(int32_t i = 0; i < (int32_t)E_GuildSalary_List.size(); ++i) {
		::proto_ff::E_GuildSalary* temp_e_guildsalary_list = msg.add_e_guildsalary_list();
		E_GuildSalary_List[i].write_to_pbmsg(*temp_e_guildsalary_list);
	}
}

void Sheet_GuildSalary_s::read_from_pbmsg(const ::proto_ff::Sheet_GuildSalary & msg) {
	E_GuildSalary_List.resize((int)msg.e_guildsalary_list_size() > (int)E_GuildSalary_List.max_size() ? E_GuildSalary_List.max_size() : msg.e_guildsalary_list_size());
	for(int32_t i = 0; i < (int32_t)E_GuildSalary_List.size(); ++i) {
		const ::proto_ff::E_GuildSalary & temp_e_guildsalary_list = msg.e_guildsalary_list(i);
		E_GuildSalary_List[i].read_from_pbmsg(temp_e_guildsalary_list);
	}
}

E_GuildDonateRewardDesc_s::E_GuildDonateRewardDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_GuildDonateRewardDesc_s::CreateInit() {
	m_num = (int32_t)0;
	m_item = (int32_t)0;
	return 0;
}

int E_GuildDonateRewardDesc_s::ResumeInit() {
	return 0;
}

void E_GuildDonateRewardDesc_s::write_to_pbmsg(::proto_ff::E_GuildDonateRewardDesc & msg) const {
	msg.set_m_num((int32_t)m_num);
	msg.set_m_item((int32_t)m_item);
}

void E_GuildDonateRewardDesc_s::read_from_pbmsg(const ::proto_ff::E_GuildDonateRewardDesc & msg) {
	m_num = msg.m_num();
	m_item = msg.m_item();
}

E_GuildDonate_s::E_GuildDonate_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_GuildDonate_s::CreateInit() {
	m_ID = (int32_t)0;
	m_costItem = (int32_t)0;
	m_costNum = (int32_t)0;
	return 0;
}

int E_GuildDonate_s::ResumeInit() {
	return 0;
}

void E_GuildDonate_s::write_to_pbmsg(::proto_ff::E_GuildDonate & msg) const {
	msg.set_m_id((int32_t)m_ID);
	msg.set_m_costitem((int32_t)m_costItem);
	msg.set_m_costnum((int32_t)m_costNum);
	for(int32_t i = 0; i < (int32_t)m_reward.size(); ++i) {
		::proto_ff::E_GuildDonateRewardDesc* temp_m_reward = msg.add_m_reward();
		m_reward[i].write_to_pbmsg(*temp_m_reward);
	}
}

void E_GuildDonate_s::read_from_pbmsg(const ::proto_ff::E_GuildDonate & msg) {
	m_ID = msg.m_id();
	m_costItem = msg.m_costitem();
	m_costNum = msg.m_costnum();
	m_reward.resize((int)msg.m_reward_size() > (int)m_reward.max_size() ? m_reward.max_size() : msg.m_reward_size());
	for(int32_t i = 0; i < (int32_t)m_reward.size(); ++i) {
		const ::proto_ff::E_GuildDonateRewardDesc & temp_m_reward = msg.m_reward(i);
		m_reward[i].read_from_pbmsg(temp_m_reward);
	}
}

Sheet_GuildDonate_s::Sheet_GuildDonate_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_GuildDonate_s::CreateInit() {
	return 0;
}

int Sheet_GuildDonate_s::ResumeInit() {
	return 0;
}

void Sheet_GuildDonate_s::write_to_pbmsg(::proto_ff::Sheet_GuildDonate & msg) const {
	for(int32_t i = 0; i < (int32_t)E_GuildDonate_List.size(); ++i) {
		::proto_ff::E_GuildDonate* temp_e_guilddonate_list = msg.add_e_guilddonate_list();
		E_GuildDonate_List[i].write_to_pbmsg(*temp_e_guilddonate_list);
	}
}

void Sheet_GuildDonate_s::read_from_pbmsg(const ::proto_ff::Sheet_GuildDonate & msg) {
	E_GuildDonate_List.resize((int)msg.e_guilddonate_list_size() > (int)E_GuildDonate_List.max_size() ? E_GuildDonate_List.max_size() : msg.e_guilddonate_list_size());
	for(int32_t i = 0; i < (int32_t)E_GuildDonate_List.size(); ++i) {
		const ::proto_ff::E_GuildDonate & temp_e_guilddonate_list = msg.e_guilddonate_list(i);
		E_GuildDonate_List[i].read_from_pbmsg(temp_e_guilddonate_list);
	}
}

E_GuildPacket_s::E_GuildPacket_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_GuildPacket_s::CreateInit() {
	m_ID = (int32_t)0;
	m_belongType = (int32_t)0;
	m_type = (int32_t)0;
	m_typeArg = (int32_t)0;
	m_itemID = (int32_t)0;
	m_itemNum = (int32_t)0;
	m_num = (int32_t)0;
	m_pre = (int32_t)0;
	m_daily = (int32_t)0;
	return 0;
}

int E_GuildPacket_s::ResumeInit() {
	return 0;
}

void E_GuildPacket_s::write_to_pbmsg(::proto_ff::E_GuildPacket & msg) const {
	msg.set_m_id((int32_t)m_ID);
	msg.set_m_belongtype((int32_t)m_belongType);
	msg.set_m_type((int32_t)m_type);
	msg.set_m_typearg((int32_t)m_typeArg);
	msg.set_m_itemid((int32_t)m_itemID);
	msg.set_m_itemnum((int32_t)m_itemNum);
	msg.set_m_num((int32_t)m_num);
	msg.set_m_pre((int32_t)m_pre);
	msg.set_m_daily((int32_t)m_daily);
}

void E_GuildPacket_s::read_from_pbmsg(const ::proto_ff::E_GuildPacket & msg) {
	m_ID = msg.m_id();
	m_belongType = msg.m_belongtype();
	m_type = msg.m_type();
	m_typeArg = msg.m_typearg();
	m_itemID = msg.m_itemid();
	m_itemNum = msg.m_itemnum();
	m_num = msg.m_num();
	m_pre = msg.m_pre();
	m_daily = msg.m_daily();
}

Sheet_GuildPacket_s::Sheet_GuildPacket_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_GuildPacket_s::CreateInit() {
	return 0;
}

int Sheet_GuildPacket_s::ResumeInit() {
	return 0;
}

void Sheet_GuildPacket_s::write_to_pbmsg(::proto_ff::Sheet_GuildPacket & msg) const {
	for(int32_t i = 0; i < (int32_t)E_GuildPacket_List.size(); ++i) {
		::proto_ff::E_GuildPacket* temp_e_guildpacket_list = msg.add_e_guildpacket_list();
		E_GuildPacket_List[i].write_to_pbmsg(*temp_e_guildpacket_list);
	}
}

void Sheet_GuildPacket_s::read_from_pbmsg(const ::proto_ff::Sheet_GuildPacket & msg) {
	E_GuildPacket_List.resize((int)msg.e_guildpacket_list_size() > (int)E_GuildPacket_List.max_size() ? E_GuildPacket_List.max_size() : msg.e_guildpacket_list_size());
	for(int32_t i = 0; i < (int32_t)E_GuildPacket_List.size(); ++i) {
		const ::proto_ff::E_GuildPacket & temp_e_guildpacket_list = msg.e_guildpacket_list(i);
		E_GuildPacket_List[i].read_from_pbmsg(temp_e_guildpacket_list);
	}
}

E_GuildPrestigetask_s::E_GuildPrestigetask_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_GuildPrestigetask_s::CreateInit() {
	m_ID = (int32_t)0;
	m_level = (int32_t)0;
	m_lvMin = (int32_t)0;
	m_lvMax = (int32_t)0;
	m_weight = (int32_t)0;
	m_taskpool = (int32_t)0;
	m_reward = (int32_t)0;
	return 0;
}

int E_GuildPrestigetask_s::ResumeInit() {
	return 0;
}

void E_GuildPrestigetask_s::write_to_pbmsg(::proto_ff::E_GuildPrestigetask & msg) const {
	msg.set_m_id((int32_t)m_ID);
	msg.set_m_level((int32_t)m_level);
	msg.set_m_lvmin((int32_t)m_lvMin);
	msg.set_m_lvmax((int32_t)m_lvMax);
	msg.set_m_weight((int32_t)m_weight);
	msg.set_m_taskpool((int32_t)m_taskpool);
	msg.set_m_reward((int32_t)m_reward);
}

void E_GuildPrestigetask_s::read_from_pbmsg(const ::proto_ff::E_GuildPrestigetask & msg) {
	m_ID = msg.m_id();
	m_level = msg.m_level();
	m_lvMin = msg.m_lvmin();
	m_lvMax = msg.m_lvmax();
	m_weight = msg.m_weight();
	m_taskpool = msg.m_taskpool();
	m_reward = msg.m_reward();
}

Sheet_GuildPrestigetask_s::Sheet_GuildPrestigetask_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_GuildPrestigetask_s::CreateInit() {
	return 0;
}

int Sheet_GuildPrestigetask_s::ResumeInit() {
	return 0;
}

void Sheet_GuildPrestigetask_s::write_to_pbmsg(::proto_ff::Sheet_GuildPrestigetask & msg) const {
	for(int32_t i = 0; i < (int32_t)E_GuildPrestigetask_List.size(); ++i) {
		::proto_ff::E_GuildPrestigetask* temp_e_guildprestigetask_list = msg.add_e_guildprestigetask_list();
		E_GuildPrestigetask_List[i].write_to_pbmsg(*temp_e_guildprestigetask_list);
	}
}

void Sheet_GuildPrestigetask_s::read_from_pbmsg(const ::proto_ff::Sheet_GuildPrestigetask & msg) {
	E_GuildPrestigetask_List.resize((int)msg.e_guildprestigetask_list_size() > (int)E_GuildPrestigetask_List.max_size() ? E_GuildPrestigetask_List.max_size() : msg.e_guildprestigetask_list_size());
	for(int32_t i = 0; i < (int32_t)E_GuildPrestigetask_List.size(); ++i) {
		const ::proto_ff::E_GuildPrestigetask & temp_e_guildprestigetask_list = msg.e_guildprestigetask_list(i);
		E_GuildPrestigetask_List[i].read_from_pbmsg(temp_e_guildprestigetask_list);
	}
}

E_GuildLvreward_s::E_GuildLvreward_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_GuildLvreward_s::CreateInit() {
	m_lv = (int32_t)0;
	m_partyExp = (int64_t)0;
	m_partyEontribution = (int32_t)0;
	m_linkExp = (int64_t)0;
	return 0;
}

int E_GuildLvreward_s::ResumeInit() {
	return 0;
}

void E_GuildLvreward_s::write_to_pbmsg(::proto_ff::E_GuildLvreward & msg) const {
	msg.set_m_lv((int32_t)m_lv);
	msg.set_m_partyexp((int64_t)m_partyExp);
	msg.set_m_partyeontribution((int32_t)m_partyEontribution);
	msg.set_m_linkexp((int64_t)m_linkExp);
}

void E_GuildLvreward_s::read_from_pbmsg(const ::proto_ff::E_GuildLvreward & msg) {
	m_lv = msg.m_lv();
	m_partyExp = msg.m_partyexp();
	m_partyEontribution = msg.m_partyeontribution();
	m_linkExp = msg.m_linkexp();
}

Sheet_GuildLvreward_s::Sheet_GuildLvreward_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_GuildLvreward_s::CreateInit() {
	return 0;
}

int Sheet_GuildLvreward_s::ResumeInit() {
	return 0;
}

void Sheet_GuildLvreward_s::write_to_pbmsg(::proto_ff::Sheet_GuildLvreward & msg) const {
	for(int32_t i = 0; i < (int32_t)E_GuildLvreward_List.size(); ++i) {
		::proto_ff::E_GuildLvreward* temp_e_guildlvreward_list = msg.add_e_guildlvreward_list();
		E_GuildLvreward_List[i].write_to_pbmsg(*temp_e_guildlvreward_list);
	}
}

void Sheet_GuildLvreward_s::read_from_pbmsg(const ::proto_ff::Sheet_GuildLvreward & msg) {
	E_GuildLvreward_List.resize((int)msg.e_guildlvreward_list_size() > (int)E_GuildLvreward_List.max_size() ? E_GuildLvreward_List.max_size() : msg.e_guildlvreward_list_size());
	for(int32_t i = 0; i < (int32_t)E_GuildLvreward_List.size(); ++i) {
		const ::proto_ff::E_GuildLvreward & temp_e_guildlvreward_list = msg.e_guildlvreward_list(i);
		E_GuildLvreward_List[i].read_from_pbmsg(temp_e_guildlvreward_list);
	}
}

E_GuildCollegeAttributeDesc_s::E_GuildCollegeAttributeDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_GuildCollegeAttributeDesc_s::CreateInit() {
	m_value = (int32_t)0;
	m_type = (int32_t)0;
	return 0;
}

int E_GuildCollegeAttributeDesc_s::ResumeInit() {
	return 0;
}

void E_GuildCollegeAttributeDesc_s::write_to_pbmsg(::proto_ff::E_GuildCollegeAttributeDesc & msg) const {
	msg.set_m_value((int32_t)m_value);
	msg.set_m_type((int32_t)m_type);
}

void E_GuildCollegeAttributeDesc_s::read_from_pbmsg(const ::proto_ff::E_GuildCollegeAttributeDesc & msg) {
	m_value = msg.m_value();
	m_type = msg.m_type();
}

E_GuildCollege_s::E_GuildCollege_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_GuildCollege_s::CreateInit() {
	m_uid = (int32_t)0;
	m_skillid = (int32_t)0;
	m_skillLv = (int32_t)0;
	m_guildLv = (int32_t)0;
	m_playerLvLimit = (int32_t)0;
	m_preSkillid = (int32_t)0;
	m_preSkillLv = (int32_t)0;
	m_CostContribute = (int32_t)0;
	return 0;
}

int E_GuildCollege_s::ResumeInit() {
	return 0;
}

void E_GuildCollege_s::write_to_pbmsg(::proto_ff::E_GuildCollege & msg) const {
	msg.set_m_uid((int32_t)m_uid);
	msg.set_m_skillid((int32_t)m_skillid);
	msg.set_m_skilllv((int32_t)m_skillLv);
	msg.set_m_guildlv((int32_t)m_guildLv);
	msg.set_m_playerlvlimit((int32_t)m_playerLvLimit);
	msg.set_m_preskillid((int32_t)m_preSkillid);
	msg.set_m_preskilllv((int32_t)m_preSkillLv);
	msg.set_m_costcontribute((int32_t)m_CostContribute);
	for(int32_t i = 0; i < (int32_t)m_attribute.size(); ++i) {
		::proto_ff::E_GuildCollegeAttributeDesc* temp_m_attribute = msg.add_m_attribute();
		m_attribute[i].write_to_pbmsg(*temp_m_attribute);
	}
}

void E_GuildCollege_s::read_from_pbmsg(const ::proto_ff::E_GuildCollege & msg) {
	m_uid = msg.m_uid();
	m_skillid = msg.m_skillid();
	m_skillLv = msg.m_skilllv();
	m_guildLv = msg.m_guildlv();
	m_playerLvLimit = msg.m_playerlvlimit();
	m_preSkillid = msg.m_preskillid();
	m_preSkillLv = msg.m_preskilllv();
	m_CostContribute = msg.m_costcontribute();
	m_attribute.resize((int)msg.m_attribute_size() > (int)m_attribute.max_size() ? m_attribute.max_size() : msg.m_attribute_size());
	for(int32_t i = 0; i < (int32_t)m_attribute.size(); ++i) {
		const ::proto_ff::E_GuildCollegeAttributeDesc & temp_m_attribute = msg.m_attribute(i);
		m_attribute[i].read_from_pbmsg(temp_m_attribute);
	}
}

Sheet_GuildCollege_s::Sheet_GuildCollege_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_GuildCollege_s::CreateInit() {
	return 0;
}

int Sheet_GuildCollege_s::ResumeInit() {
	return 0;
}

void Sheet_GuildCollege_s::write_to_pbmsg(::proto_ff::Sheet_GuildCollege & msg) const {
	for(int32_t i = 0; i < (int32_t)E_GuildCollege_List.size(); ++i) {
		::proto_ff::E_GuildCollege* temp_e_guildcollege_list = msg.add_e_guildcollege_list();
		E_GuildCollege_List[i].write_to_pbmsg(*temp_e_guildcollege_list);
	}
}

void Sheet_GuildCollege_s::read_from_pbmsg(const ::proto_ff::Sheet_GuildCollege & msg) {
	E_GuildCollege_List.resize((int)msg.e_guildcollege_list_size() > (int)E_GuildCollege_List.max_size() ? E_GuildCollege_List.max_size() : msg.e_guildcollege_list_size());
	for(int32_t i = 0; i < (int32_t)E_GuildCollege_List.size(); ++i) {
		const ::proto_ff::E_GuildCollege & temp_e_guildcollege_list = msg.e_guildcollege_list(i);
		E_GuildCollege_List[i].read_from_pbmsg(temp_e_guildcollege_list);
	}
}

E_GuildAnswer_s::E_GuildAnswer_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_GuildAnswer_s::CreateInit() {
	m_id = (int32_t)0;
	return 0;
}

int E_GuildAnswer_s::ResumeInit() {
	return 0;
}

void E_GuildAnswer_s::write_to_pbmsg(::proto_ff::E_GuildAnswer & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_answer(m_answer.data());
}

void E_GuildAnswer_s::read_from_pbmsg(const ::proto_ff::E_GuildAnswer & msg) {
	m_id = msg.m_id();
	m_answer = msg.m_answer();
}

Sheet_GuildAnswer_s::Sheet_GuildAnswer_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_GuildAnswer_s::CreateInit() {
	return 0;
}

int Sheet_GuildAnswer_s::ResumeInit() {
	return 0;
}

void Sheet_GuildAnswer_s::write_to_pbmsg(::proto_ff::Sheet_GuildAnswer & msg) const {
	for(int32_t i = 0; i < (int32_t)E_GuildAnswer_List.size(); ++i) {
		::proto_ff::E_GuildAnswer* temp_e_guildanswer_list = msg.add_e_guildanswer_list();
		E_GuildAnswer_List[i].write_to_pbmsg(*temp_e_guildanswer_list);
	}
}

void Sheet_GuildAnswer_s::read_from_pbmsg(const ::proto_ff::Sheet_GuildAnswer & msg) {
	E_GuildAnswer_List.resize((int)msg.e_guildanswer_list_size() > (int)E_GuildAnswer_List.max_size() ? E_GuildAnswer_List.max_size() : msg.e_guildanswer_list_size());
	for(int32_t i = 0; i < (int32_t)E_GuildAnswer_List.size(); ++i) {
		const ::proto_ff::E_GuildAnswer & temp_e_guildanswer_list = msg.e_guildanswer_list(i);
		E_GuildAnswer_List[i].read_from_pbmsg(temp_e_guildanswer_list);
	}
}

E_GuildRank_reward_s::E_GuildRank_reward_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_GuildRank_reward_s::CreateInit() {
	m_id = (int32_t)0;
	m_type = (int32_t)0;
	m_rankMin = (int32_t)0;
	m_rankMax = (int32_t)0;
	m_lvMin = (int32_t)0;
	m_rewardS = (int32_t)0;
	return 0;
}

int E_GuildRank_reward_s::ResumeInit() {
	return 0;
}

void E_GuildRank_reward_s::write_to_pbmsg(::proto_ff::E_GuildRank_reward & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_type((int32_t)m_type);
	msg.set_m_note(m_note.data());
	msg.set_m_rankmin((int32_t)m_rankMin);
	msg.set_m_rankmax((int32_t)m_rankMax);
	msg.set_m_lvmin((int32_t)m_lvMin);
	msg.set_m_rewards((int32_t)m_rewardS);
}

void E_GuildRank_reward_s::read_from_pbmsg(const ::proto_ff::E_GuildRank_reward & msg) {
	m_id = msg.m_id();
	m_type = msg.m_type();
	m_note = msg.m_note();
	m_rankMin = msg.m_rankmin();
	m_rankMax = msg.m_rankmax();
	m_lvMin = msg.m_lvmin();
	m_rewardS = msg.m_rewards();
}

Sheet_GuildRank_reward_s::Sheet_GuildRank_reward_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_GuildRank_reward_s::CreateInit() {
	return 0;
}

int Sheet_GuildRank_reward_s::ResumeInit() {
	return 0;
}

void Sheet_GuildRank_reward_s::write_to_pbmsg(::proto_ff::Sheet_GuildRank_reward & msg) const {
	for(int32_t i = 0; i < (int32_t)E_GuildRank_reward_List.size(); ++i) {
		::proto_ff::E_GuildRank_reward* temp_e_guildrank_reward_list = msg.add_e_guildrank_reward_list();
		E_GuildRank_reward_List[i].write_to_pbmsg(*temp_e_guildrank_reward_list);
	}
}

void Sheet_GuildRank_reward_s::read_from_pbmsg(const ::proto_ff::Sheet_GuildRank_reward & msg) {
	E_GuildRank_reward_List.resize((int)msg.e_guildrank_reward_list_size() > (int)E_GuildRank_reward_List.max_size() ? E_GuildRank_reward_List.max_size() : msg.e_guildrank_reward_list_size());
	for(int32_t i = 0; i < (int32_t)E_GuildRank_reward_List.size(); ++i) {
		const ::proto_ff::E_GuildRank_reward & temp_e_guildrank_reward_list = msg.e_guildrank_reward_list(i);
		E_GuildRank_reward_List[i].read_from_pbmsg(temp_e_guildrank_reward_list);
	}
}

E_GuildShouhskillRewardDesc_s::E_GuildShouhskillRewardDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_GuildShouhskillRewardDesc_s::CreateInit() {
	m_Num = (int32_t)0;
	m_Id = (int32_t)0;
	return 0;
}

int E_GuildShouhskillRewardDesc_s::ResumeInit() {
	return 0;
}

void E_GuildShouhskillRewardDesc_s::write_to_pbmsg(::proto_ff::E_GuildShouhskillRewardDesc & msg) const {
	msg.set_m_num((int32_t)m_Num);
	msg.set_m_id((int32_t)m_Id);
}

void E_GuildShouhskillRewardDesc_s::read_from_pbmsg(const ::proto_ff::E_GuildShouhskillRewardDesc & msg) {
	m_Num = msg.m_num();
	m_Id = msg.m_id();
}

E_GuildShouhskill_s::E_GuildShouhskill_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_GuildShouhskill_s::CreateInit() {
	m_id = (int32_t)0;
	m_costId = (int32_t)0;
	m_costNum = (int32_t)0;
	m_skillid = (int32_t)0;
	m_times = (int32_t)0;
	return 0;
}

int E_GuildShouhskill_s::ResumeInit() {
	return 0;
}

void E_GuildShouhskill_s::write_to_pbmsg(::proto_ff::E_GuildShouhskill & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_name(m_name.data());
	msg.set_m_costid((int32_t)m_costId);
	msg.set_m_costnum((int32_t)m_costNum);
	msg.set_m_skillid((int32_t)m_skillid);
	msg.set_m_times((int32_t)m_times);
	for(int32_t i = 0; i < (int32_t)m_reward.size(); ++i) {
		::proto_ff::E_GuildShouhskillRewardDesc* temp_m_reward = msg.add_m_reward();
		m_reward[i].write_to_pbmsg(*temp_m_reward);
	}
}

void E_GuildShouhskill_s::read_from_pbmsg(const ::proto_ff::E_GuildShouhskill & msg) {
	m_id = msg.m_id();
	m_name = msg.m_name();
	m_costId = msg.m_costid();
	m_costNum = msg.m_costnum();
	m_skillid = msg.m_skillid();
	m_times = msg.m_times();
	m_reward.resize((int)msg.m_reward_size() > (int)m_reward.max_size() ? m_reward.max_size() : msg.m_reward_size());
	for(int32_t i = 0; i < (int32_t)m_reward.size(); ++i) {
		const ::proto_ff::E_GuildShouhskillRewardDesc & temp_m_reward = msg.m_reward(i);
		m_reward[i].read_from_pbmsg(temp_m_reward);
	}
}

Sheet_GuildShouhskill_s::Sheet_GuildShouhskill_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_GuildShouhskill_s::CreateInit() {
	return 0;
}

int Sheet_GuildShouhskill_s::ResumeInit() {
	return 0;
}

void Sheet_GuildShouhskill_s::write_to_pbmsg(::proto_ff::Sheet_GuildShouhskill & msg) const {
	for(int32_t i = 0; i < (int32_t)E_GuildShouhskill_List.size(); ++i) {
		::proto_ff::E_GuildShouhskill* temp_e_guildshouhskill_list = msg.add_e_guildshouhskill_list();
		E_GuildShouhskill_List[i].write_to_pbmsg(*temp_e_guildshouhskill_list);
	}
}

void Sheet_GuildShouhskill_s::read_from_pbmsg(const ::proto_ff::Sheet_GuildShouhskill & msg) {
	E_GuildShouhskill_List.resize((int)msg.e_guildshouhskill_list_size() > (int)E_GuildShouhskill_List.max_size() ? E_GuildShouhskill_List.max_size() : msg.e_guildshouhskill_list_size());
	for(int32_t i = 0; i < (int32_t)E_GuildShouhskill_List.size(); ++i) {
		const ::proto_ff::E_GuildShouhskill & temp_e_guildshouhskill_list = msg.e_guildshouhskill_list(i);
		E_GuildShouhskill_List[i].read_from_pbmsg(temp_e_guildshouhskill_list);
	}
}

E_GuildGwreward_s::E_GuildGwreward_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_GuildGwreward_s::CreateInit() {
	m_id = (int32_t)0;
	m_type = (int32_t)0;
	return 0;
}

int E_GuildGwreward_s::ResumeInit() {
	return 0;
}

void E_GuildGwreward_s::write_to_pbmsg(::proto_ff::E_GuildGwreward & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_type((int32_t)m_type);
	msg.set_m_reward(m_reward.data());
	msg.set_m_crossreward(m_Crossreward.data());
	for(int32_t i = 0; i < (int32_t)m_arg.size(); ++i) {
		msg.add_m_arg((int32_t)m_arg[i]);
	}
}

void E_GuildGwreward_s::read_from_pbmsg(const ::proto_ff::E_GuildGwreward & msg) {
	m_id = msg.m_id();
	m_type = msg.m_type();
	m_reward = msg.m_reward();
	m_Crossreward = msg.m_crossreward();
	m_arg.resize((int)msg.m_arg_size() > (int)m_arg.max_size() ? m_arg.max_size() : msg.m_arg_size());
	for(int32_t i = 0; i < (int32_t)m_arg.size(); ++i) {
		m_arg[i] = msg.m_arg(i);
	}
}

Sheet_GuildGwreward_s::Sheet_GuildGwreward_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_GuildGwreward_s::CreateInit() {
	return 0;
}

int Sheet_GuildGwreward_s::ResumeInit() {
	return 0;
}

void Sheet_GuildGwreward_s::write_to_pbmsg(::proto_ff::Sheet_GuildGwreward & msg) const {
	for(int32_t i = 0; i < (int32_t)E_GuildGwreward_List.size(); ++i) {
		::proto_ff::E_GuildGwreward* temp_e_guildgwreward_list = msg.add_e_guildgwreward_list();
		E_GuildGwreward_List[i].write_to_pbmsg(*temp_e_guildgwreward_list);
	}
}

void Sheet_GuildGwreward_s::read_from_pbmsg(const ::proto_ff::Sheet_GuildGwreward & msg) {
	E_GuildGwreward_List.resize((int)msg.e_guildgwreward_list_size() > (int)E_GuildGwreward_List.max_size() ? E_GuildGwreward_List.max_size() : msg.e_guildgwreward_list_size());
	for(int32_t i = 0; i < (int32_t)E_GuildGwreward_List.size(); ++i) {
		const ::proto_ff::E_GuildGwreward & temp_e_guildgwreward_list = msg.e_guildgwreward_list(i);
		E_GuildGwreward_List[i].read_from_pbmsg(temp_e_guildgwreward_list);
	}
}

E_GuildGwwinstreak_s::E_GuildGwwinstreak_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_GuildGwwinstreak_s::CreateInit() {
	m_id = (int32_t)0;
	m_winStreak = (int32_t)0;
	m_winReward = (int32_t)0;
	m_endReward = (int32_t)0;
	m_challengeSkill = (int32_t)0;
	return 0;
}

int E_GuildGwwinstreak_s::ResumeInit() {
	return 0;
}

void E_GuildGwwinstreak_s::write_to_pbmsg(::proto_ff::E_GuildGwwinstreak & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_winstreak((int32_t)m_winStreak);
	msg.set_m_winreward((int32_t)m_winReward);
	msg.set_m_endreward((int32_t)m_endReward);
	msg.set_m_challengeskill((int32_t)m_challengeSkill);
}

void E_GuildGwwinstreak_s::read_from_pbmsg(const ::proto_ff::E_GuildGwwinstreak & msg) {
	m_id = msg.m_id();
	m_winStreak = msg.m_winstreak();
	m_winReward = msg.m_winreward();
	m_endReward = msg.m_endreward();
	m_challengeSkill = msg.m_challengeskill();
}

Sheet_GuildGwwinstreak_s::Sheet_GuildGwwinstreak_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_GuildGwwinstreak_s::CreateInit() {
	return 0;
}

int Sheet_GuildGwwinstreak_s::ResumeInit() {
	return 0;
}

void Sheet_GuildGwwinstreak_s::write_to_pbmsg(::proto_ff::Sheet_GuildGwwinstreak & msg) const {
	for(int32_t i = 0; i < (int32_t)E_GuildGwwinstreak_List.size(); ++i) {
		::proto_ff::E_GuildGwwinstreak* temp_e_guildgwwinstreak_list = msg.add_e_guildgwwinstreak_list();
		E_GuildGwwinstreak_List[i].write_to_pbmsg(*temp_e_guildgwwinstreak_list);
	}
}

void Sheet_GuildGwwinstreak_s::read_from_pbmsg(const ::proto_ff::Sheet_GuildGwwinstreak & msg) {
	E_GuildGwwinstreak_List.resize((int)msg.e_guildgwwinstreak_list_size() > (int)E_GuildGwwinstreak_List.max_size() ? E_GuildGwwinstreak_List.max_size() : msg.e_guildgwwinstreak_list_size());
	for(int32_t i = 0; i < (int32_t)E_GuildGwwinstreak_List.size(); ++i) {
		const ::proto_ff::E_GuildGwwinstreak & temp_e_guildgwwinstreak_list = msg.e_guildgwwinstreak_list(i);
		E_GuildGwwinstreak_List[i].read_from_pbmsg(temp_e_guildgwwinstreak_list);
	}
}

E_GuildTtower_s::E_GuildTtower_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_GuildTtower_s::CreateInit() {
	m_id = (int32_t)0;
	m_dupid = (int32_t)0;
	m_breakBox = (int32_t)0;
	m_clearBox = (int32_t)0;
	return 0;
}

int E_GuildTtower_s::ResumeInit() {
	return 0;
}

void E_GuildTtower_s::write_to_pbmsg(::proto_ff::E_GuildTtower & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_dupid((int32_t)m_dupid);
	msg.set_m_breakbox((int32_t)m_breakBox);
	msg.set_m_clearbox((int32_t)m_clearBox);
}

void E_GuildTtower_s::read_from_pbmsg(const ::proto_ff::E_GuildTtower & msg) {
	m_id = msg.m_id();
	m_dupid = msg.m_dupid();
	m_breakBox = msg.m_breakbox();
	m_clearBox = msg.m_clearbox();
}

Sheet_GuildTtower_s::Sheet_GuildTtower_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_GuildTtower_s::CreateInit() {
	return 0;
}

int Sheet_GuildTtower_s::ResumeInit() {
	return 0;
}

void Sheet_GuildTtower_s::write_to_pbmsg(::proto_ff::Sheet_GuildTtower & msg) const {
	for(int32_t i = 0; i < (int32_t)E_GuildTtower_List.size(); ++i) {
		::proto_ff::E_GuildTtower* temp_e_guildttower_list = msg.add_e_guildttower_list();
		E_GuildTtower_List[i].write_to_pbmsg(*temp_e_guildttower_list);
	}
}

void Sheet_GuildTtower_s::read_from_pbmsg(const ::proto_ff::Sheet_GuildTtower & msg) {
	E_GuildTtower_List.resize((int)msg.e_guildttower_list_size() > (int)E_GuildTtower_List.max_size() ? E_GuildTtower_List.max_size() : msg.e_guildttower_list_size());
	for(int32_t i = 0; i < (int32_t)E_GuildTtower_List.size(); ++i) {
		const ::proto_ff::E_GuildTtower & temp_e_guildttower_list = msg.e_guildttower_list(i);
		E_GuildTtower_List[i].read_from_pbmsg(temp_e_guildttower_list);
	}
}

E_GuildTtowerdevelopAttributeDesc_s::E_GuildTtowerdevelopAttributeDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_GuildTtowerdevelopAttributeDesc_s::CreateInit() {
	m_value = (int32_t)0;
	m_type = (int32_t)0;
	return 0;
}

int E_GuildTtowerdevelopAttributeDesc_s::ResumeInit() {
	return 0;
}

void E_GuildTtowerdevelopAttributeDesc_s::write_to_pbmsg(::proto_ff::E_GuildTtowerdevelopAttributeDesc & msg) const {
	msg.set_m_value((int32_t)m_value);
	msg.set_m_type((int32_t)m_type);
}

void E_GuildTtowerdevelopAttributeDesc_s::read_from_pbmsg(const ::proto_ff::E_GuildTtowerdevelopAttributeDesc & msg) {
	m_value = msg.m_value();
	m_type = msg.m_type();
}

E_GuildTtowerdevelop_s::E_GuildTtowerdevelop_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_GuildTtowerdevelop_s::CreateInit() {
	m_id = (int32_t)0;
	m_type = (int32_t)0;
	m_dataGroup = (int32_t)0;
	return 0;
}

int E_GuildTtowerdevelop_s::ResumeInit() {
	return 0;
}

void E_GuildTtowerdevelop_s::write_to_pbmsg(::proto_ff::E_GuildTtowerdevelop & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_type((int32_t)m_type);
	msg.set_m_datagroup((int32_t)m_dataGroup);
	for(int32_t i = 0; i < (int32_t)m_attribute.size(); ++i) {
		::proto_ff::E_GuildTtowerdevelopAttributeDesc* temp_m_attribute = msg.add_m_attribute();
		m_attribute[i].write_to_pbmsg(*temp_m_attribute);
	}
}

void E_GuildTtowerdevelop_s::read_from_pbmsg(const ::proto_ff::E_GuildTtowerdevelop & msg) {
	m_id = msg.m_id();
	m_type = msg.m_type();
	m_dataGroup = msg.m_datagroup();
	m_attribute.resize((int)msg.m_attribute_size() > (int)m_attribute.max_size() ? m_attribute.max_size() : msg.m_attribute_size());
	for(int32_t i = 0; i < (int32_t)m_attribute.size(); ++i) {
		const ::proto_ff::E_GuildTtowerdevelopAttributeDesc & temp_m_attribute = msg.m_attribute(i);
		m_attribute[i].read_from_pbmsg(temp_m_attribute);
	}
}

Sheet_GuildTtowerdevelop_s::Sheet_GuildTtowerdevelop_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_GuildTtowerdevelop_s::CreateInit() {
	return 0;
}

int Sheet_GuildTtowerdevelop_s::ResumeInit() {
	return 0;
}

void Sheet_GuildTtowerdevelop_s::write_to_pbmsg(::proto_ff::Sheet_GuildTtowerdevelop & msg) const {
	for(int32_t i = 0; i < (int32_t)E_GuildTtowerdevelop_List.size(); ++i) {
		::proto_ff::E_GuildTtowerdevelop* temp_e_guildttowerdevelop_list = msg.add_e_guildttowerdevelop_list();
		E_GuildTtowerdevelop_List[i].write_to_pbmsg(*temp_e_guildttowerdevelop_list);
	}
}

void Sheet_GuildTtowerdevelop_s::read_from_pbmsg(const ::proto_ff::Sheet_GuildTtowerdevelop & msg) {
	E_GuildTtowerdevelop_List.resize((int)msg.e_guildttowerdevelop_list_size() > (int)E_GuildTtowerdevelop_List.max_size() ? E_GuildTtowerdevelop_List.max_size() : msg.e_guildttowerdevelop_list_size());
	for(int32_t i = 0; i < (int32_t)E_GuildTtowerdevelop_List.size(); ++i) {
		const ::proto_ff::E_GuildTtowerdevelop & temp_e_guildttowerdevelop_list = msg.e_guildttowerdevelop_list(i);
		E_GuildTtowerdevelop_List[i].read_from_pbmsg(temp_e_guildttowerdevelop_list);
	}
}

E_GuildTtowerdevelop_dataAttributeDesc_s::E_GuildTtowerdevelop_dataAttributeDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_GuildTtowerdevelop_dataAttributeDesc_s::CreateInit() {
	m_value = (int32_t)0;
	m_type = (int32_t)0;
	return 0;
}

int E_GuildTtowerdevelop_dataAttributeDesc_s::ResumeInit() {
	return 0;
}

void E_GuildTtowerdevelop_dataAttributeDesc_s::write_to_pbmsg(::proto_ff::E_GuildTtowerdevelop_dataAttributeDesc & msg) const {
	msg.set_m_value((int32_t)m_value);
	msg.set_m_type((int32_t)m_type);
}

void E_GuildTtowerdevelop_dataAttributeDesc_s::read_from_pbmsg(const ::proto_ff::E_GuildTtowerdevelop_dataAttributeDesc & msg) {
	m_value = msg.m_value();
	m_type = msg.m_type();
}

E_GuildTtowerdevelop_data_s::E_GuildTtowerdevelop_data_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_GuildTtowerdevelop_data_s::CreateInit() {
	m_id = (int32_t)0;
	m_groupID = (int32_t)0;
	m_costItem = (int32_t)0;
	m_costnum = (int32_t)0;
	return 0;
}

int E_GuildTtowerdevelop_data_s::ResumeInit() {
	return 0;
}

void E_GuildTtowerdevelop_data_s::write_to_pbmsg(::proto_ff::E_GuildTtowerdevelop_data & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_groupid((int32_t)m_groupID);
	msg.set_m_costitem((int32_t)m_costItem);
	msg.set_m_costnum((int32_t)m_costnum);
	for(int32_t i = 0; i < (int32_t)m_attribute.size(); ++i) {
		::proto_ff::E_GuildTtowerdevelop_dataAttributeDesc* temp_m_attribute = msg.add_m_attribute();
		m_attribute[i].write_to_pbmsg(*temp_m_attribute);
	}
}

void E_GuildTtowerdevelop_data_s::read_from_pbmsg(const ::proto_ff::E_GuildTtowerdevelop_data & msg) {
	m_id = msg.m_id();
	m_groupID = msg.m_groupid();
	m_costItem = msg.m_costitem();
	m_costnum = msg.m_costnum();
	m_attribute.resize((int)msg.m_attribute_size() > (int)m_attribute.max_size() ? m_attribute.max_size() : msg.m_attribute_size());
	for(int32_t i = 0; i < (int32_t)m_attribute.size(); ++i) {
		const ::proto_ff::E_GuildTtowerdevelop_dataAttributeDesc & temp_m_attribute = msg.m_attribute(i);
		m_attribute[i].read_from_pbmsg(temp_m_attribute);
	}
}

Sheet_GuildTtowerdevelop_data_s::Sheet_GuildTtowerdevelop_data_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_GuildTtowerdevelop_data_s::CreateInit() {
	return 0;
}

int Sheet_GuildTtowerdevelop_data_s::ResumeInit() {
	return 0;
}

void Sheet_GuildTtowerdevelop_data_s::write_to_pbmsg(::proto_ff::Sheet_GuildTtowerdevelop_data & msg) const {
	for(int32_t i = 0; i < (int32_t)E_GuildTtowerdevelop_data_List.size(); ++i) {
		::proto_ff::E_GuildTtowerdevelop_data* temp_e_guildttowerdevelop_data_list = msg.add_e_guildttowerdevelop_data_list();
		E_GuildTtowerdevelop_data_List[i].write_to_pbmsg(*temp_e_guildttowerdevelop_data_list);
	}
}

void Sheet_GuildTtowerdevelop_data_s::read_from_pbmsg(const ::proto_ff::Sheet_GuildTtowerdevelop_data & msg) {
	E_GuildTtowerdevelop_data_List.resize((int)msg.e_guildttowerdevelop_data_list_size() > (int)E_GuildTtowerdevelop_data_List.max_size() ? E_GuildTtowerdevelop_data_List.max_size() : msg.e_guildttowerdevelop_data_list_size());
	for(int32_t i = 0; i < (int32_t)E_GuildTtowerdevelop_data_List.size(); ++i) {
		const ::proto_ff::E_GuildTtowerdevelop_data & temp_e_guildttowerdevelop_data_list = msg.e_guildttowerdevelop_data_list(i);
		E_GuildTtowerdevelop_data_List[i].read_from_pbmsg(temp_e_guildttowerdevelop_data_list);
	}
}

}
