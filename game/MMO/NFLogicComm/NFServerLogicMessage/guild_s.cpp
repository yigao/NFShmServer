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

}