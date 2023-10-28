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
	m_setitem = (int32_t)0;
	m_nameitem = (int32_t)0;
	m_editrequirelv = (int32_t)0;
	m_giftcd = (int32_t)0;
	m_dismiss = (int32_t)0;
	m_transferguild = (int32_t)0;
	m_territory = (int32_t)0;
	m_autominlv = (int32_t)0;
	m_autominbp = (int32_t)0;
	m_donatetimes = (int32_t)0;
	m_packetmaxd = (int32_t)0;
	m_packetmaxbd = (int32_t)0;
	m_packetmaxsend = (int32_t)0;
	m_packetvip = (int32_t)0;
	m_packetadd = (int32_t)0;
	m_prestigetasonekeyvip = (int32_t)0;
	m_prestigetasonekeylv = (int32_t)0;
	m_prestigetaskprivage = (int32_t)0;
	m_prestigetaskflash = (int32_t)0;
	m_prestigetaskflashprice = (int32_t)0;
	m_prestigetasktimes = (int32_t)0;
	m_rewardcd = (int32_t)0;
	m_answerdelay = (int32_t)0;
	m_answernum = (int32_t)0;
	m_answertime = (int32_t)0;
	m_answerresulttime = (int32_t)0;
	m_answerlimit = (int32_t)0;
	m_answerfirst = (int32_t)0;
	m_answersuccess = (int32_t)0;
	m_answebasics = (int32_t)0;
	m_linklvupper = (int32_t)0;
	m_linklvupmax = (int32_t)0;
	m_linktime = (int32_t)0;
	m_monsterid = (int32_t)0;
	m_point = (int32_t)0;
	m_collecttimes = (int32_t)0;
	m_shens_daytimes = (int32_t)0;
	m_shens_weektimes = (int32_t)0;
	m_shens_dup = (int32_t)0;
	m_shensitem = (int32_t)0;
	m_shenscost = (int32_t)0;
	m_shenscostactive = (int32_t)0;
	m_shouh_dup = (int32_t)0;
	m_shouhexpskill = (int32_t)0;
	m_gwdupid = (int32_t)0;
	m_gwbattletime = (int32_t)0;
	m_gwresttime = (int32_t)0;
	m_gwcentermid = (int32_t)0;
	m_gwtowermid = (int32_t)0;
	m_gwtankmid = (int32_t)0;
	m_gwbornrpoint = (int32_t)0;
	m_gwcenterrpoint = (int32_t)0;
	m_gwtankrpoint = (int32_t)0;
	m_gwbornbpoint = (int32_t)0;
	m_gwcenterbpoint = (int32_t)0;
	m_gwtankbpoint = (int32_t)0;
	m_tanknum = (int32_t)0;
	m_tankresttime = (int32_t)0;
	m_tankrestnum = (int32_t)0;
	m_dominatedaily = (int32_t)0;
	m_dominatebossreward = (int32_t)0;
	m_freepoint = (int32_t)0;
	m_deffreepoint = (int32_t)0;
	m_playerpoint = (int32_t)0;
	m_tankpoint = (int32_t)0;
	m_towerpoint = (int32_t)0;
	m_centerpoint = (int32_t)0;
	m_assistradio = (int32_t)0;
	m_tteamdamageadd = (int32_t)0;
	m_tweekclosetime = (int32_t)0;
	m_cyclicreward = (int32_t)0;
	m_tencyclicreward = (int32_t)0;
	return 0;
}

int E_GuildConstant_s::ResumeInit() {
	return 0;
}

void E_GuildConstant_s::write_to_pbmsg(::proto_ff::E_GuildConstant & msg) const {
	msg.set_m_constantid((int32_t)m_constantid);
	msg.set_m_setitem((int32_t)m_setitem);
	msg.set_m_nameitem((int32_t)m_nameitem);
	msg.set_m_editrequirelv((int32_t)m_editrequirelv);
	msg.set_m_giftcd((int32_t)m_giftcd);
	msg.set_m_dismiss((int32_t)m_dismiss);
	msg.set_m_transferguild((int32_t)m_transferguild);
	msg.set_m_territory((int32_t)m_territory);
	msg.set_m_autominlv((int32_t)m_autominlv);
	msg.set_m_autominbp((int32_t)m_autominbp);
	msg.set_m_donatetimes((int32_t)m_donatetimes);
	msg.set_m_packetmaxd((int32_t)m_packetmaxd);
	msg.set_m_packetmaxbd((int32_t)m_packetmaxbd);
	msg.set_m_packetmaxsend((int32_t)m_packetmaxsend);
	msg.set_m_packetvip((int32_t)m_packetvip);
	msg.set_m_packetadd((int32_t)m_packetadd);
	msg.set_m_prestigetasonekeyvip((int32_t)m_prestigetasonekeyvip);
	msg.set_m_prestigetasonekeylv((int32_t)m_prestigetasonekeylv);
	msg.set_m_prestigetaskprivage((int32_t)m_prestigetaskprivage);
	msg.set_m_prestigetaskflash((int32_t)m_prestigetaskflash);
	msg.set_m_prestigetaskflashprice((int32_t)m_prestigetaskflashprice);
	msg.set_m_prestigetasktimes((int32_t)m_prestigetasktimes);
	msg.set_m_rewardcd((int32_t)m_rewardcd);
	msg.set_m_answerdelay((int32_t)m_answerdelay);
	msg.set_m_answernum((int32_t)m_answernum);
	msg.set_m_answertime((int32_t)m_answertime);
	msg.set_m_answerresulttime((int32_t)m_answerresulttime);
	msg.set_m_answerlimit((int32_t)m_answerlimit);
	msg.set_m_answerfirst((int32_t)m_answerfirst);
	msg.set_m_answersuccess((int32_t)m_answersuccess);
	msg.set_m_answebasics((int32_t)m_answebasics);
	msg.set_m_linklvupper((int32_t)m_linklvupper);
	msg.set_m_linklvupmax((int32_t)m_linklvupmax);
	msg.set_m_linktime((int32_t)m_linktime);
	msg.set_m_monsterid((int32_t)m_monsterid);
	msg.set_m_point((int32_t)m_point);
	msg.set_m_collecttimes((int32_t)m_collecttimes);
	msg.set_m_shens_daytimes((int32_t)m_shens_daytimes);
	msg.set_m_shens_weektimes((int32_t)m_shens_weektimes);
	msg.set_m_shens_dup((int32_t)m_shens_dup);
	msg.set_m_shensitem((int32_t)m_shensitem);
	msg.set_m_shenscost((int32_t)m_shenscost);
	msg.set_m_shenscostactive((int32_t)m_shenscostactive);
	msg.set_m_shouh_dup((int32_t)m_shouh_dup);
	msg.set_m_shouhexpskill((int32_t)m_shouhexpskill);
	msg.set_m_shouhmosid(m_shouhmosid.data());
	msg.set_m_gwdupid((int32_t)m_gwdupid);
	msg.set_m_gwbattletime((int32_t)m_gwbattletime);
	msg.set_m_gwresttime((int32_t)m_gwresttime);
	msg.set_m_gwcentermid((int32_t)m_gwcentermid);
	msg.set_m_gwtowermid((int32_t)m_gwtowermid);
	msg.set_m_gwtankmid((int32_t)m_gwtankmid);
	msg.set_m_gwbornrpoint((int32_t)m_gwbornrpoint);
	msg.set_m_gwcenterrpoint((int32_t)m_gwcenterrpoint);
	msg.set_m_gwtowerrpoint(m_gwtowerrpoint.data());
	msg.set_m_gwtankrpoint((int32_t)m_gwtankrpoint);
	msg.set_m_gwbornbpoint((int32_t)m_gwbornbpoint);
	msg.set_m_gwcenterbpoint((int32_t)m_gwcenterbpoint);
	msg.set_m_gwtowerbpoint(m_gwtowerbpoint.data());
	msg.set_m_gwtankbpoint((int32_t)m_gwtankbpoint);
	msg.set_m_tanknum((int32_t)m_tanknum);
	msg.set_m_tankresttime((int32_t)m_tankresttime);
	msg.set_m_tankrestnum((int32_t)m_tankrestnum);
	msg.set_m_dominatedaily((int32_t)m_dominatedaily);
	msg.set_m_dominatebossreward((int32_t)m_dominatebossreward);
	msg.set_m_freepoint((int32_t)m_freepoint);
	msg.set_m_deffreepoint((int32_t)m_deffreepoint);
	msg.set_m_playerpoint((int32_t)m_playerpoint);
	msg.set_m_tankpoint((int32_t)m_tankpoint);
	msg.set_m_towerpoint((int32_t)m_towerpoint);
	msg.set_m_centerpoint((int32_t)m_centerpoint);
	msg.set_m_assistradio((int32_t)m_assistradio);
	msg.set_m_tteamdamageadd((int32_t)m_tteamdamageadd);
	msg.set_m_tweekclosetime((int32_t)m_tweekclosetime);
	msg.set_m_cyclicreward((int32_t)m_cyclicreward);
	msg.set_m_tencyclicreward((int32_t)m_tencyclicreward);
}

void E_GuildConstant_s::read_from_pbmsg(const ::proto_ff::E_GuildConstant & msg) {
	m_constantid = msg.m_constantid();
	m_setitem = msg.m_setitem();
	m_nameitem = msg.m_nameitem();
	m_editrequirelv = msg.m_editrequirelv();
	m_giftcd = msg.m_giftcd();
	m_dismiss = msg.m_dismiss();
	m_transferguild = msg.m_transferguild();
	m_territory = msg.m_territory();
	m_autominlv = msg.m_autominlv();
	m_autominbp = msg.m_autominbp();
	m_donatetimes = msg.m_donatetimes();
	m_packetmaxd = msg.m_packetmaxd();
	m_packetmaxbd = msg.m_packetmaxbd();
	m_packetmaxsend = msg.m_packetmaxsend();
	m_packetvip = msg.m_packetvip();
	m_packetadd = msg.m_packetadd();
	m_prestigetasonekeyvip = msg.m_prestigetasonekeyvip();
	m_prestigetasonekeylv = msg.m_prestigetasonekeylv();
	m_prestigetaskprivage = msg.m_prestigetaskprivage();
	m_prestigetaskflash = msg.m_prestigetaskflash();
	m_prestigetaskflashprice = msg.m_prestigetaskflashprice();
	m_prestigetasktimes = msg.m_prestigetasktimes();
	m_rewardcd = msg.m_rewardcd();
	m_answerdelay = msg.m_answerdelay();
	m_answernum = msg.m_answernum();
	m_answertime = msg.m_answertime();
	m_answerresulttime = msg.m_answerresulttime();
	m_answerlimit = msg.m_answerlimit();
	m_answerfirst = msg.m_answerfirst();
	m_answersuccess = msg.m_answersuccess();
	m_answebasics = msg.m_answebasics();
	m_linklvupper = msg.m_linklvupper();
	m_linklvupmax = msg.m_linklvupmax();
	m_linktime = msg.m_linktime();
	m_monsterid = msg.m_monsterid();
	m_point = msg.m_point();
	m_collecttimes = msg.m_collecttimes();
	m_shens_daytimes = msg.m_shens_daytimes();
	m_shens_weektimes = msg.m_shens_weektimes();
	m_shens_dup = msg.m_shens_dup();
	m_shensitem = msg.m_shensitem();
	m_shenscost = msg.m_shenscost();
	m_shenscostactive = msg.m_shenscostactive();
	m_shouh_dup = msg.m_shouh_dup();
	m_shouhexpskill = msg.m_shouhexpskill();
	m_shouhmosid = msg.m_shouhmosid();
	m_gwdupid = msg.m_gwdupid();
	m_gwbattletime = msg.m_gwbattletime();
	m_gwresttime = msg.m_gwresttime();
	m_gwcentermid = msg.m_gwcentermid();
	m_gwtowermid = msg.m_gwtowermid();
	m_gwtankmid = msg.m_gwtankmid();
	m_gwbornrpoint = msg.m_gwbornrpoint();
	m_gwcenterrpoint = msg.m_gwcenterrpoint();
	m_gwtowerrpoint = msg.m_gwtowerrpoint();
	m_gwtankrpoint = msg.m_gwtankrpoint();
	m_gwbornbpoint = msg.m_gwbornbpoint();
	m_gwcenterbpoint = msg.m_gwcenterbpoint();
	m_gwtowerbpoint = msg.m_gwtowerbpoint();
	m_gwtankbpoint = msg.m_gwtankbpoint();
	m_tanknum = msg.m_tanknum();
	m_tankresttime = msg.m_tankresttime();
	m_tankrestnum = msg.m_tankrestnum();
	m_dominatedaily = msg.m_dominatedaily();
	m_dominatebossreward = msg.m_dominatebossreward();
	m_freepoint = msg.m_freepoint();
	m_deffreepoint = msg.m_deffreepoint();
	m_playerpoint = msg.m_playerpoint();
	m_tankpoint = msg.m_tankpoint();
	m_towerpoint = msg.m_towerpoint();
	m_centerpoint = msg.m_centerpoint();
	m_assistradio = msg.m_assistradio();
	m_tteamdamageadd = msg.m_tteamdamageadd();
	m_tweekclosetime = msg.m_tweekclosetime();
	m_cyclicreward = msg.m_cyclicreward();
	m_tencyclicreward = msg.m_tencyclicreward();
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
	m_guildlevel = (int32_t)0;
	m_guildlevel_exp = (int32_t)0;
	m_guildlevel_member = (int32_t)0;
	m_guildlevel_vp = (int32_t)0;
	m_guildlevel_np = (int32_t)0;
	m_guildlevel_g = (int32_t)0;
	return 0;
}

int E_GuildLevel_s::ResumeInit() {
	return 0;
}

void E_GuildLevel_s::write_to_pbmsg(::proto_ff::E_GuildLevel & msg) const {
	msg.set_m_guildlevel((int32_t)m_guildlevel);
	msg.set_m_guildlevel_exp((int32_t)m_guildlevel_exp);
	msg.set_m_guildlevel_member((int32_t)m_guildlevel_member);
	msg.set_m_guildlevel_vp((int32_t)m_guildlevel_vp);
	msg.set_m_guildlevel_np((int32_t)m_guildlevel_np);
	msg.set_m_guildlevel_g((int32_t)m_guildlevel_g);
}

void E_GuildLevel_s::read_from_pbmsg(const ::proto_ff::E_GuildLevel & msg) {
	m_guildlevel = msg.m_guildlevel();
	m_guildlevel_exp = msg.m_guildlevel_exp();
	m_guildlevel_member = msg.m_guildlevel_member();
	m_guildlevel_vp = msg.m_guildlevel_vp();
	m_guildlevel_np = msg.m_guildlevel_np();
	m_guildlevel_g = msg.m_guildlevel_g();
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
	m_positionid = (int32_t)0;
	m_admitnewcomer = (int32_t)0;
	m_appointandremovevp = (int32_t)0;
	m_appointandremoveelder = (int32_t)0;
	m_appointandremoveg = (int32_t)0;
	m_appointandremoveelite = (int32_t)0;
	m_expelvp = (int32_t)0;
	m_expelelder = (int32_t)0;
	m_expelg = (int32_t)0;
	m_expelmass = (int32_t)0;
	m_announcementediting = (int32_t)0;
	m_rname = (int32_t)0;
	m_joincondition = (int32_t)0;
	m_guildactivity = (int32_t)0;
	m_dissolveassignguild = (int32_t)0;
	m_changename = (int32_t)0;
	m_recruitchat = (int32_t)0;
	m_guildpacket = (int32_t)0;
	return 0;
}

int E_GuildPosition_s::ResumeInit() {
	return 0;
}

void E_GuildPosition_s::write_to_pbmsg(::proto_ff::E_GuildPosition & msg) const {
	msg.set_m_positionid((int32_t)m_positionid);
	msg.set_m_admitnewcomer((int32_t)m_admitnewcomer);
	msg.set_m_appointandremovevp((int32_t)m_appointandremovevp);
	msg.set_m_appointandremoveelder((int32_t)m_appointandremoveelder);
	msg.set_m_appointandremoveg((int32_t)m_appointandremoveg);
	msg.set_m_appointandremoveelite((int32_t)m_appointandremoveelite);
	msg.set_m_expelvp((int32_t)m_expelvp);
	msg.set_m_expelelder((int32_t)m_expelelder);
	msg.set_m_expelg((int32_t)m_expelg);
	msg.set_m_expelmass((int32_t)m_expelmass);
	msg.set_m_announcementediting((int32_t)m_announcementediting);
	msg.set_m_rname((int32_t)m_rname);
	msg.set_m_joincondition((int32_t)m_joincondition);
	msg.set_m_guildactivity((int32_t)m_guildactivity);
	msg.set_m_dissolveassignguild((int32_t)m_dissolveassignguild);
	msg.set_m_changename((int32_t)m_changename);
	msg.set_m_recruitchat((int32_t)m_recruitchat);
	msg.set_m_guildpacket((int32_t)m_guildpacket);
}

void E_GuildPosition_s::read_from_pbmsg(const ::proto_ff::E_GuildPosition & msg) {
	m_positionid = msg.m_positionid();
	m_admitnewcomer = msg.m_admitnewcomer();
	m_appointandremovevp = msg.m_appointandremovevp();
	m_appointandremoveelder = msg.m_appointandremoveelder();
	m_appointandremoveg = msg.m_appointandremoveg();
	m_appointandremoveelite = msg.m_appointandremoveelite();
	m_expelvp = msg.m_expelvp();
	m_expelelder = msg.m_expelelder();
	m_expelg = msg.m_expelg();
	m_expelmass = msg.m_expelmass();
	m_announcementediting = msg.m_announcementediting();
	m_rname = msg.m_rname();
	m_joincondition = msg.m_joincondition();
	m_guildactivity = msg.m_guildactivity();
	m_dissolveassignguild = msg.m_dissolveassignguild();
	m_changename = msg.m_changename();
	m_recruitchat = msg.m_recruitchat();
	m_guildpacket = msg.m_guildpacket();
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
	m_id = (int32_t)0;
	m_type = (int32_t)0;
	m_typearg = (int32_t)0;
	m_times = (int32_t)0;
	return 0;
}

int E_GuildSalary_s::ResumeInit() {
	return 0;
}

void E_GuildSalary_s::write_to_pbmsg(::proto_ff::E_GuildSalary & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_type((int32_t)m_type);
	msg.set_m_typearg((int32_t)m_typearg);
	msg.set_m_times((int32_t)m_times);
	for(int32_t i = 0; i < (int32_t)m_reward.size(); ++i) {
		::proto_ff::E_GuildSalaryRewardDesc* temp_m_reward = msg.add_m_reward();
		m_reward[i].write_to_pbmsg(*temp_m_reward);
	}
}

void E_GuildSalary_s::read_from_pbmsg(const ::proto_ff::E_GuildSalary & msg) {
	m_id = msg.m_id();
	m_type = msg.m_type();
	m_typearg = msg.m_typearg();
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
	m_id = (int32_t)0;
	m_costitem = (int32_t)0;
	m_costnum = (int32_t)0;
	return 0;
}

int E_GuildDonate_s::ResumeInit() {
	return 0;
}

void E_GuildDonate_s::write_to_pbmsg(::proto_ff::E_GuildDonate & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_costitem((int32_t)m_costitem);
	msg.set_m_costnum((int32_t)m_costnum);
	for(int32_t i = 0; i < (int32_t)m_reward.size(); ++i) {
		::proto_ff::E_GuildDonateRewardDesc* temp_m_reward = msg.add_m_reward();
		m_reward[i].write_to_pbmsg(*temp_m_reward);
	}
}

void E_GuildDonate_s::read_from_pbmsg(const ::proto_ff::E_GuildDonate & msg) {
	m_id = msg.m_id();
	m_costitem = msg.m_costitem();
	m_costnum = msg.m_costnum();
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
	m_id = (int32_t)0;
	m_belongtype = (int32_t)0;
	m_type = (int32_t)0;
	m_typearg = (int32_t)0;
	m_itemid = (int32_t)0;
	m_itemnum = (int32_t)0;
	m_num = (int32_t)0;
	m_pre = (int32_t)0;
	m_daily = (int32_t)0;
	return 0;
}

int E_GuildPacket_s::ResumeInit() {
	return 0;
}

void E_GuildPacket_s::write_to_pbmsg(::proto_ff::E_GuildPacket & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_belongtype((int32_t)m_belongtype);
	msg.set_m_type((int32_t)m_type);
	msg.set_m_typearg((int32_t)m_typearg);
	msg.set_m_itemid((int32_t)m_itemid);
	msg.set_m_itemnum((int32_t)m_itemnum);
	msg.set_m_num((int32_t)m_num);
	msg.set_m_pre((int32_t)m_pre);
	msg.set_m_daily((int32_t)m_daily);
}

void E_GuildPacket_s::read_from_pbmsg(const ::proto_ff::E_GuildPacket & msg) {
	m_id = msg.m_id();
	m_belongtype = msg.m_belongtype();
	m_type = msg.m_type();
	m_typearg = msg.m_typearg();
	m_itemid = msg.m_itemid();
	m_itemnum = msg.m_itemnum();
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
	m_id = (int32_t)0;
	m_level = (int32_t)0;
	m_lvmin = (int32_t)0;
	m_lvmax = (int32_t)0;
	m_weight = (int32_t)0;
	m_taskpool = (int32_t)0;
	m_reward = (int32_t)0;
	return 0;
}

int E_GuildPrestigetask_s::ResumeInit() {
	return 0;
}

void E_GuildPrestigetask_s::write_to_pbmsg(::proto_ff::E_GuildPrestigetask & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_level((int32_t)m_level);
	msg.set_m_lvmin((int32_t)m_lvmin);
	msg.set_m_lvmax((int32_t)m_lvmax);
	msg.set_m_weight((int32_t)m_weight);
	msg.set_m_taskpool((int32_t)m_taskpool);
	msg.set_m_reward((int32_t)m_reward);
}

void E_GuildPrestigetask_s::read_from_pbmsg(const ::proto_ff::E_GuildPrestigetask & msg) {
	m_id = msg.m_id();
	m_level = msg.m_level();
	m_lvmin = msg.m_lvmin();
	m_lvmax = msg.m_lvmax();
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
	m_partyexp = (int32_t)0;
	m_partyeontribution = (int32_t)0;
	m_linkexp = (int32_t)0;
	return 0;
}

int E_GuildLvreward_s::ResumeInit() {
	return 0;
}

void E_GuildLvreward_s::write_to_pbmsg(::proto_ff::E_GuildLvreward & msg) const {
	msg.set_m_lv((int32_t)m_lv);
	msg.set_m_partyexp((int32_t)m_partyexp);
	msg.set_m_partyeontribution((int32_t)m_partyeontribution);
	msg.set_m_linkexp((int32_t)m_linkexp);
}

void E_GuildLvreward_s::read_from_pbmsg(const ::proto_ff::E_GuildLvreward & msg) {
	m_lv = msg.m_lv();
	m_partyexp = msg.m_partyexp();
	m_partyeontribution = msg.m_partyeontribution();
	m_linkexp = msg.m_linkexp();
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
	m_skilllv = (int32_t)0;
	m_guildlv = (int32_t)0;
	m_playerlvlimit = (int32_t)0;
	m_preskillid = (int32_t)0;
	m_preskilllv = (int32_t)0;
	m_costcontribute = (int32_t)0;
	return 0;
}

int E_GuildCollege_s::ResumeInit() {
	return 0;
}

void E_GuildCollege_s::write_to_pbmsg(::proto_ff::E_GuildCollege & msg) const {
	msg.set_m_uid((int32_t)m_uid);
	msg.set_m_skillid((int32_t)m_skillid);
	msg.set_m_skilllv((int32_t)m_skilllv);
	msg.set_m_guildlv((int32_t)m_guildlv);
	msg.set_m_playerlvlimit((int32_t)m_playerlvlimit);
	msg.set_m_preskillid((int32_t)m_preskillid);
	msg.set_m_preskilllv((int32_t)m_preskilllv);
	msg.set_m_costcontribute((int32_t)m_costcontribute);
	for(int32_t i = 0; i < (int32_t)m_attribute.size(); ++i) {
		::proto_ff::E_GuildCollegeAttributeDesc* temp_m_attribute = msg.add_m_attribute();
		m_attribute[i].write_to_pbmsg(*temp_m_attribute);
	}
}

void E_GuildCollege_s::read_from_pbmsg(const ::proto_ff::E_GuildCollege & msg) {
	m_uid = msg.m_uid();
	m_skillid = msg.m_skillid();
	m_skilllv = msg.m_skilllv();
	m_guildlv = msg.m_guildlv();
	m_playerlvlimit = msg.m_playerlvlimit();
	m_preskillid = msg.m_preskillid();
	m_preskilllv = msg.m_preskilllv();
	m_costcontribute = msg.m_costcontribute();
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
	m_rankmin = (int32_t)0;
	m_rankmax = (int32_t)0;
	m_lvmin = (int32_t)0;
	m_rewards = (int32_t)0;
	return 0;
}

int E_GuildRank_reward_s::ResumeInit() {
	return 0;
}

void E_GuildRank_reward_s::write_to_pbmsg(::proto_ff::E_GuildRank_reward & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_type((int32_t)m_type);
	msg.set_m_note(m_note.data());
	msg.set_m_rankmin((int32_t)m_rankmin);
	msg.set_m_rankmax((int32_t)m_rankmax);
	msg.set_m_lvmin((int32_t)m_lvmin);
	msg.set_m_rewards((int32_t)m_rewards);
}

void E_GuildRank_reward_s::read_from_pbmsg(const ::proto_ff::E_GuildRank_reward & msg) {
	m_id = msg.m_id();
	m_type = msg.m_type();
	m_note = msg.m_note();
	m_rankmin = msg.m_rankmin();
	m_rankmax = msg.m_rankmax();
	m_lvmin = msg.m_lvmin();
	m_rewards = msg.m_rewards();
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
	m_num = (int32_t)0;
	m_id = (int32_t)0;
	return 0;
}

int E_GuildShouhskillRewardDesc_s::ResumeInit() {
	return 0;
}

void E_GuildShouhskillRewardDesc_s::write_to_pbmsg(::proto_ff::E_GuildShouhskillRewardDesc & msg) const {
	msg.set_m_num((int32_t)m_num);
	msg.set_m_id((int32_t)m_id);
}

void E_GuildShouhskillRewardDesc_s::read_from_pbmsg(const ::proto_ff::E_GuildShouhskillRewardDesc & msg) {
	m_num = msg.m_num();
	m_id = msg.m_id();
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
	m_costid = (int32_t)0;
	m_costnum = (int32_t)0;
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
	msg.set_m_costid((int32_t)m_costid);
	msg.set_m_costnum((int32_t)m_costnum);
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
	m_costid = msg.m_costid();
	m_costnum = msg.m_costnum();
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
	msg.set_m_crossreward(m_crossreward.data());
	for(int32_t i = 0; i < (int32_t)m_arg.size(); ++i) {
		msg.add_m_arg((int32_t)m_arg[i]);
	}
}

void E_GuildGwreward_s::read_from_pbmsg(const ::proto_ff::E_GuildGwreward & msg) {
	m_id = msg.m_id();
	m_type = msg.m_type();
	m_reward = msg.m_reward();
	m_crossreward = msg.m_crossreward();
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
	m_winstreak = (int32_t)0;
	m_winreward = (int32_t)0;
	m_endreward = (int32_t)0;
	m_challengeskill = (int32_t)0;
	return 0;
}

int E_GuildGwwinstreak_s::ResumeInit() {
	return 0;
}

void E_GuildGwwinstreak_s::write_to_pbmsg(::proto_ff::E_GuildGwwinstreak & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_winstreak((int32_t)m_winstreak);
	msg.set_m_winreward((int32_t)m_winreward);
	msg.set_m_endreward((int32_t)m_endreward);
	msg.set_m_challengeskill((int32_t)m_challengeskill);
}

void E_GuildGwwinstreak_s::read_from_pbmsg(const ::proto_ff::E_GuildGwwinstreak & msg) {
	m_id = msg.m_id();
	m_winstreak = msg.m_winstreak();
	m_winreward = msg.m_winreward();
	m_endreward = msg.m_endreward();
	m_challengeskill = msg.m_challengeskill();
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
	m_breakbox = (int32_t)0;
	m_clearbox = (int32_t)0;
	return 0;
}

int E_GuildTtower_s::ResumeInit() {
	return 0;
}

void E_GuildTtower_s::write_to_pbmsg(::proto_ff::E_GuildTtower & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_dupid((int32_t)m_dupid);
	msg.set_m_breakbox((int32_t)m_breakbox);
	msg.set_m_clearbox((int32_t)m_clearbox);
}

void E_GuildTtower_s::read_from_pbmsg(const ::proto_ff::E_GuildTtower & msg) {
	m_id = msg.m_id();
	m_dupid = msg.m_dupid();
	m_breakbox = msg.m_breakbox();
	m_clearbox = msg.m_clearbox();
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

}
