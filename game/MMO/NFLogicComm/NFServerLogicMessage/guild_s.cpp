#include "guild_s.h"

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
}

void E_GuildConstant_s::read_from_pbmsg(const ::proto_ff::E_GuildConstant & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct E_GuildConstant_s));
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
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_GuildConstant_s));
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
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct E_GuildLevel_s));
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
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_GuildLevel_s));
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
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct E_GuildPosition_s));
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
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_GuildPosition_s));
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
	m_item = (int32_t)0;
	m_num = (int32_t)0;
	return 0;
}

int E_GuildSalaryRewardDesc_s::ResumeInit() {
	return 0;
}

void E_GuildSalaryRewardDesc_s::write_to_pbmsg(::proto_ff::E_GuildSalaryRewardDesc & msg) const {
	msg.set_m_item((int32_t)m_item);
	msg.set_m_num((int32_t)m_num);
}

void E_GuildSalaryRewardDesc_s::read_from_pbmsg(const ::proto_ff::E_GuildSalaryRewardDesc & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct E_GuildSalaryRewardDesc_s));
	m_item = msg.m_item();
	m_num = msg.m_num();
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
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct E_GuildSalary_s));
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
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_GuildSalary_s));
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
	m_item = (int32_t)0;
	m_num = (int32_t)0;
	return 0;
}

int E_GuildDonateRewardDesc_s::ResumeInit() {
	return 0;
}

void E_GuildDonateRewardDesc_s::write_to_pbmsg(::proto_ff::E_GuildDonateRewardDesc & msg) const {
	msg.set_m_item((int32_t)m_item);
	msg.set_m_num((int32_t)m_num);
}

void E_GuildDonateRewardDesc_s::read_from_pbmsg(const ::proto_ff::E_GuildDonateRewardDesc & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct E_GuildDonateRewardDesc_s));
	m_item = msg.m_item();
	m_num = msg.m_num();
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
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct E_GuildDonate_s));
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
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_GuildDonate_s));
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
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct E_GuildPacket_s));
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
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_GuildPacket_s));
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
	msg.set_m_weight((int32_t)m_weight);
	msg.set_m_taskpool((int32_t)m_taskpool);
	msg.set_m_reward((int32_t)m_reward);
}

void E_GuildPrestigetask_s::read_from_pbmsg(const ::proto_ff::E_GuildPrestigetask & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct E_GuildPrestigetask_s));
	m_id = msg.m_id();
	m_level = msg.m_level();
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
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_GuildPrestigetask_s));
	E_GuildPrestigetask_List.resize((int)msg.e_guildprestigetask_list_size() > (int)E_GuildPrestigetask_List.max_size() ? E_GuildPrestigetask_List.max_size() : msg.e_guildprestigetask_list_size());
	for(int32_t i = 0; i < (int32_t)E_GuildPrestigetask_List.size(); ++i) {
		const ::proto_ff::E_GuildPrestigetask & temp_e_guildprestigetask_list = msg.e_guildprestigetask_list(i);
		E_GuildPrestigetask_List[i].read_from_pbmsg(temp_e_guildprestigetask_list);
	}
}

}