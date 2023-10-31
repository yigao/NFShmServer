#include "E_Welfare_s.h"

namespace proto_ff_s {

E_WelfareSign_s::E_WelfareSign_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_WelfareSign_s::CreateInit() {
	m_id = (int32_t)0;
	m_month = (int32_t)0;
	m_days = (int32_t)0;
	m_VIP = (int32_t)0;
	m_reward = (int32_t)0;
	m_rewardNum = (int32_t)0;
	return 0;
}

int E_WelfareSign_s::ResumeInit() {
	return 0;
}

void E_WelfareSign_s::write_to_pbmsg(::proto_ff::E_WelfareSign & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_month((int32_t)m_month);
	msg.set_m_days((int32_t)m_days);
	msg.set_m_vip((int32_t)m_VIP);
	msg.set_m_icon(m_icon.data());
	msg.set_m_reward((int32_t)m_reward);
	msg.set_m_rewardnum((int32_t)m_rewardNum);
}

void E_WelfareSign_s::read_from_pbmsg(const ::proto_ff::E_WelfareSign & msg) {
	m_id = msg.m_id();
	m_month = msg.m_month();
	m_days = msg.m_days();
	m_VIP = msg.m_vip();
	m_icon = msg.m_icon();
	m_reward = msg.m_reward();
	m_rewardNum = msg.m_rewardnum();
}

Sheet_WelfareSign_s::Sheet_WelfareSign_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_WelfareSign_s::CreateInit() {
	return 0;
}

int Sheet_WelfareSign_s::ResumeInit() {
	return 0;
}

void Sheet_WelfareSign_s::write_to_pbmsg(::proto_ff::Sheet_WelfareSign & msg) const {
	for(int32_t i = 0; i < (int32_t)E_WelfareSign_List.size(); ++i) {
		::proto_ff::E_WelfareSign* temp_e_welfaresign_list = msg.add_e_welfaresign_list();
		E_WelfareSign_List[i].write_to_pbmsg(*temp_e_welfaresign_list);
	}
}

void Sheet_WelfareSign_s::read_from_pbmsg(const ::proto_ff::Sheet_WelfareSign & msg) {
	E_WelfareSign_List.resize((int)msg.e_welfaresign_list_size() > (int)E_WelfareSign_List.max_size() ? E_WelfareSign_List.max_size() : msg.e_welfaresign_list_size());
	for(int32_t i = 0; i < (int32_t)E_WelfareSign_List.size(); ++i) {
		const ::proto_ff::E_WelfareSign & temp_e_welfaresign_list = msg.e_welfaresign_list(i);
		E_WelfareSign_List[i].read_from_pbmsg(temp_e_welfaresign_list);
	}
}

E_WelfareAccruereward_s::E_WelfareAccruereward_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_WelfareAccruereward_s::CreateInit() {
	m_id = (int32_t)0;
	m_month = (int32_t)0;
	m_accrueDays = (int32_t)0;
	m_reward = (int32_t)0;
	m_rewardNum = (int32_t)0;
	return 0;
}

int E_WelfareAccruereward_s::ResumeInit() {
	return 0;
}

void E_WelfareAccruereward_s::write_to_pbmsg(::proto_ff::E_WelfareAccruereward & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_month((int32_t)m_month);
	msg.set_m_accruedays((int32_t)m_accrueDays);
	msg.set_m_reward((int32_t)m_reward);
	msg.set_m_rewardnum((int32_t)m_rewardNum);
}

void E_WelfareAccruereward_s::read_from_pbmsg(const ::proto_ff::E_WelfareAccruereward & msg) {
	m_id = msg.m_id();
	m_month = msg.m_month();
	m_accrueDays = msg.m_accruedays();
	m_reward = msg.m_reward();
	m_rewardNum = msg.m_rewardnum();
}

Sheet_WelfareAccruereward_s::Sheet_WelfareAccruereward_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_WelfareAccruereward_s::CreateInit() {
	return 0;
}

int Sheet_WelfareAccruereward_s::ResumeInit() {
	return 0;
}

void Sheet_WelfareAccruereward_s::write_to_pbmsg(::proto_ff::Sheet_WelfareAccruereward & msg) const {
	for(int32_t i = 0; i < (int32_t)E_WelfareAccruereward_List.size(); ++i) {
		::proto_ff::E_WelfareAccruereward* temp_e_welfareaccruereward_list = msg.add_e_welfareaccruereward_list();
		E_WelfareAccruereward_List[i].write_to_pbmsg(*temp_e_welfareaccruereward_list);
	}
}

void Sheet_WelfareAccruereward_s::read_from_pbmsg(const ::proto_ff::Sheet_WelfareAccruereward & msg) {
	E_WelfareAccruereward_List.resize((int)msg.e_welfareaccruereward_list_size() > (int)E_WelfareAccruereward_List.max_size() ? E_WelfareAccruereward_List.max_size() : msg.e_welfareaccruereward_list_size());
	for(int32_t i = 0; i < (int32_t)E_WelfareAccruereward_List.size(); ++i) {
		const ::proto_ff::E_WelfareAccruereward & temp_e_welfareaccruereward_list = msg.e_welfareaccruereward_list(i);
		E_WelfareAccruereward_List[i].read_from_pbmsg(temp_e_welfareaccruereward_list);
	}
}

E_WelfareLvreward_s::E_WelfareLvreward_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_WelfareLvreward_s::CreateInit() {
	m_id = (int32_t)0;
	m_lv = (int32_t)0;
	m_lvReward = (int32_t)0;
	m_vip = (int32_t)0;
	m_vipReward = (int32_t)0;
	return 0;
}

int E_WelfareLvreward_s::ResumeInit() {
	return 0;
}

void E_WelfareLvreward_s::write_to_pbmsg(::proto_ff::E_WelfareLvreward & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_lv((int32_t)m_lv);
	msg.set_m_lvreward((int32_t)m_lvReward);
	msg.set_m_vip((int32_t)m_vip);
	msg.set_m_vipreward((int32_t)m_vipReward);
}

void E_WelfareLvreward_s::read_from_pbmsg(const ::proto_ff::E_WelfareLvreward & msg) {
	m_id = msg.m_id();
	m_lv = msg.m_lv();
	m_lvReward = msg.m_lvreward();
	m_vip = msg.m_vip();
	m_vipReward = msg.m_vipreward();
}

Sheet_WelfareLvreward_s::Sheet_WelfareLvreward_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_WelfareLvreward_s::CreateInit() {
	return 0;
}

int Sheet_WelfareLvreward_s::ResumeInit() {
	return 0;
}

void Sheet_WelfareLvreward_s::write_to_pbmsg(::proto_ff::Sheet_WelfareLvreward & msg) const {
	for(int32_t i = 0; i < (int32_t)E_WelfareLvreward_List.size(); ++i) {
		::proto_ff::E_WelfareLvreward* temp_e_welfarelvreward_list = msg.add_e_welfarelvreward_list();
		E_WelfareLvreward_List[i].write_to_pbmsg(*temp_e_welfarelvreward_list);
	}
}

void Sheet_WelfareLvreward_s::read_from_pbmsg(const ::proto_ff::Sheet_WelfareLvreward & msg) {
	E_WelfareLvreward_List.resize((int)msg.e_welfarelvreward_list_size() > (int)E_WelfareLvreward_List.max_size() ? E_WelfareLvreward_List.max_size() : msg.e_welfarelvreward_list_size());
	for(int32_t i = 0; i < (int32_t)E_WelfareLvreward_List.size(); ++i) {
		const ::proto_ff::E_WelfareLvreward & temp_e_welfarelvreward_list = msg.e_welfarelvreward_list(i);
		E_WelfareLvreward_List[i].read_from_pbmsg(temp_e_welfarelvreward_list);
	}
}

E_WelfareOnline_s::E_WelfareOnline_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_WelfareOnline_s::CreateInit() {
	m_id = (int32_t)0;
	m_onlineTime = (int32_t)0;
	m_lvReward = (int32_t)0;
	return 0;
}

int E_WelfareOnline_s::ResumeInit() {
	return 0;
}

void E_WelfareOnline_s::write_to_pbmsg(::proto_ff::E_WelfareOnline & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_onlinetime((int32_t)m_onlineTime);
	msg.set_m_lvreward((int32_t)m_lvReward);
}

void E_WelfareOnline_s::read_from_pbmsg(const ::proto_ff::E_WelfareOnline & msg) {
	m_id = msg.m_id();
	m_onlineTime = msg.m_onlinetime();
	m_lvReward = msg.m_lvreward();
}

Sheet_WelfareOnline_s::Sheet_WelfareOnline_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_WelfareOnline_s::CreateInit() {
	return 0;
}

int Sheet_WelfareOnline_s::ResumeInit() {
	return 0;
}

void Sheet_WelfareOnline_s::write_to_pbmsg(::proto_ff::Sheet_WelfareOnline & msg) const {
	for(int32_t i = 0; i < (int32_t)E_WelfareOnline_List.size(); ++i) {
		::proto_ff::E_WelfareOnline* temp_e_welfareonline_list = msg.add_e_welfareonline_list();
		E_WelfareOnline_List[i].write_to_pbmsg(*temp_e_welfareonline_list);
	}
}

void Sheet_WelfareOnline_s::read_from_pbmsg(const ::proto_ff::Sheet_WelfareOnline & msg) {
	E_WelfareOnline_List.resize((int)msg.e_welfareonline_list_size() > (int)E_WelfareOnline_List.max_size() ? E_WelfareOnline_List.max_size() : msg.e_welfareonline_list_size());
	for(int32_t i = 0; i < (int32_t)E_WelfareOnline_List.size(); ++i) {
		const ::proto_ff::E_WelfareOnline & temp_e_welfareonline_list = msg.e_welfareonline_list(i);
		E_WelfareOnline_List[i].read_from_pbmsg(temp_e_welfareonline_list);
	}
}

E_WelfareFraud_s::E_WelfareFraud_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_WelfareFraud_s::CreateInit() {
	m_id = (int32_t)0;
	m_correct = (int32_t)0;
	return 0;
}

int E_WelfareFraud_s::ResumeInit() {
	return 0;
}

void E_WelfareFraud_s::write_to_pbmsg(::proto_ff::E_WelfareFraud & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_picture(m_picture.data());
	msg.set_m_correct((int32_t)m_correct);
}

void E_WelfareFraud_s::read_from_pbmsg(const ::proto_ff::E_WelfareFraud & msg) {
	m_id = msg.m_id();
	m_picture = msg.m_picture();
	m_correct = msg.m_correct();
}

Sheet_WelfareFraud_s::Sheet_WelfareFraud_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_WelfareFraud_s::CreateInit() {
	return 0;
}

int Sheet_WelfareFraud_s::ResumeInit() {
	return 0;
}

void Sheet_WelfareFraud_s::write_to_pbmsg(::proto_ff::Sheet_WelfareFraud & msg) const {
	for(int32_t i = 0; i < (int32_t)E_WelfareFraud_List.size(); ++i) {
		::proto_ff::E_WelfareFraud* temp_e_welfarefraud_list = msg.add_e_welfarefraud_list();
		E_WelfareFraud_List[i].write_to_pbmsg(*temp_e_welfarefraud_list);
	}
}

void Sheet_WelfareFraud_s::read_from_pbmsg(const ::proto_ff::Sheet_WelfareFraud & msg) {
	E_WelfareFraud_List.resize((int)msg.e_welfarefraud_list_size() > (int)E_WelfareFraud_List.max_size() ? E_WelfareFraud_List.max_size() : msg.e_welfarefraud_list_size());
	for(int32_t i = 0; i < (int32_t)E_WelfareFraud_List.size(); ++i) {
		const ::proto_ff::E_WelfareFraud & temp_e_welfarefraud_list = msg.e_welfarefraud_list(i);
		E_WelfareFraud_List[i].read_from_pbmsg(temp_e_welfarefraud_list);
	}
}

E_WelfareWeekendgift_s::E_WelfareWeekendgift_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_WelfareWeekendgift_s::CreateInit() {
	m_id = (int32_t)0;
	m_lvMin = (int32_t)0;
	m_lvMax = (int32_t)0;
	m_date = (int32_t)0;
	return 0;
}

int E_WelfareWeekendgift_s::ResumeInit() {
	return 0;
}

void E_WelfareWeekendgift_s::write_to_pbmsg(::proto_ff::E_WelfareWeekendgift & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_lvmin((int32_t)m_lvMin);
	msg.set_m_lvmax((int32_t)m_lvMax);
	msg.set_m_date((int32_t)m_date);
	for(int32_t i = 0; i < (int32_t)m_rewards.size(); ++i) {
		msg.add_m_rewards((int32_t)m_rewards[i]);
	}
}

void E_WelfareWeekendgift_s::read_from_pbmsg(const ::proto_ff::E_WelfareWeekendgift & msg) {
	m_id = msg.m_id();
	m_lvMin = msg.m_lvmin();
	m_lvMax = msg.m_lvmax();
	m_date = msg.m_date();
	m_rewards.resize((int)msg.m_rewards_size() > (int)m_rewards.max_size() ? m_rewards.max_size() : msg.m_rewards_size());
	for(int32_t i = 0; i < (int32_t)m_rewards.size(); ++i) {
		m_rewards[i] = msg.m_rewards(i);
	}
}

Sheet_WelfareWeekendgift_s::Sheet_WelfareWeekendgift_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_WelfareWeekendgift_s::CreateInit() {
	return 0;
}

int Sheet_WelfareWeekendgift_s::ResumeInit() {
	return 0;
}

void Sheet_WelfareWeekendgift_s::write_to_pbmsg(::proto_ff::Sheet_WelfareWeekendgift & msg) const {
	for(int32_t i = 0; i < (int32_t)E_WelfareWeekendgift_List.size(); ++i) {
		::proto_ff::E_WelfareWeekendgift* temp_e_welfareweekendgift_list = msg.add_e_welfareweekendgift_list();
		E_WelfareWeekendgift_List[i].write_to_pbmsg(*temp_e_welfareweekendgift_list);
	}
}

void Sheet_WelfareWeekendgift_s::read_from_pbmsg(const ::proto_ff::Sheet_WelfareWeekendgift & msg) {
	E_WelfareWeekendgift_List.resize((int)msg.e_welfareweekendgift_list_size() > (int)E_WelfareWeekendgift_List.max_size() ? E_WelfareWeekendgift_List.max_size() : msg.e_welfareweekendgift_list_size());
	for(int32_t i = 0; i < (int32_t)E_WelfareWeekendgift_List.size(); ++i) {
		const ::proto_ff::E_WelfareWeekendgift & temp_e_welfareweekendgift_list = msg.e_welfareweekendgift_list(i);
		E_WelfareWeekendgift_List[i].read_from_pbmsg(temp_e_welfareweekendgift_list);
	}
}

E_WelfareConstant_s::E_WelfareConstant_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_WelfareConstant_s::CreateInit() {
	m_id = (int32_t)0;
	m_addSigncost = (int32_t)0;
	m_addSignprice = (int32_t)0;
	m_noticeReward = (int32_t)0;
	m_wrongMin = (int32_t)0;
	m_wrongMax = (int32_t)0;
	m_fraudReward = (int32_t)0;
	m_firstRcharge = (int32_t)0;
	m_secondRcharge = (int32_t)0;
	m_gemMB = (int32_t)0;
	m_starMB = (int32_t)0;
	m_kingMB = (int32_t)0;
	m_keyRebate = (int32_t)0;
	return 0;
}

int E_WelfareConstant_s::ResumeInit() {
	return 0;
}

void E_WelfareConstant_s::write_to_pbmsg(::proto_ff::E_WelfareConstant & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_addsigncost((int32_t)m_addSigncost);
	msg.set_m_addsignprice((int32_t)m_addSignprice);
	msg.set_m_noticereward((int32_t)m_noticeReward);
	msg.set_m_wrongmin((int32_t)m_wrongMin);
	msg.set_m_wrongmax((int32_t)m_wrongMax);
	msg.set_m_fraudreward((int32_t)m_fraudReward);
	msg.set_m_firstrcharge((int32_t)m_firstRcharge);
	msg.set_m_secondrcharge((int32_t)m_secondRcharge);
	msg.set_m_gemmb((int32_t)m_gemMB);
	msg.set_m_starmb((int32_t)m_starMB);
	msg.set_m_kingmb((int32_t)m_kingMB);
	msg.set_m_keyrebate((int32_t)m_keyRebate);
}

void E_WelfareConstant_s::read_from_pbmsg(const ::proto_ff::E_WelfareConstant & msg) {
	m_id = msg.m_id();
	m_addSigncost = msg.m_addsigncost();
	m_addSignprice = msg.m_addsignprice();
	m_noticeReward = msg.m_noticereward();
	m_wrongMin = msg.m_wrongmin();
	m_wrongMax = msg.m_wrongmax();
	m_fraudReward = msg.m_fraudreward();
	m_firstRcharge = msg.m_firstrcharge();
	m_secondRcharge = msg.m_secondrcharge();
	m_gemMB = msg.m_gemmb();
	m_starMB = msg.m_starmb();
	m_kingMB = msg.m_kingmb();
	m_keyRebate = msg.m_keyrebate();
}

Sheet_WelfareConstant_s::Sheet_WelfareConstant_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_WelfareConstant_s::CreateInit() {
	return 0;
}

int Sheet_WelfareConstant_s::ResumeInit() {
	return 0;
}

void Sheet_WelfareConstant_s::write_to_pbmsg(::proto_ff::Sheet_WelfareConstant & msg) const {
	for(int32_t i = 0; i < (int32_t)E_WelfareConstant_List.size(); ++i) {
		::proto_ff::E_WelfareConstant* temp_e_welfareconstant_list = msg.add_e_welfareconstant_list();
		E_WelfareConstant_List[i].write_to_pbmsg(*temp_e_welfareconstant_list);
	}
}

void Sheet_WelfareConstant_s::read_from_pbmsg(const ::proto_ff::Sheet_WelfareConstant & msg) {
	E_WelfareConstant_List.resize((int)msg.e_welfareconstant_list_size() > (int)E_WelfareConstant_List.max_size() ? E_WelfareConstant_List.max_size() : msg.e_welfareconstant_list_size());
	for(int32_t i = 0; i < (int32_t)E_WelfareConstant_List.size(); ++i) {
		const ::proto_ff::E_WelfareConstant & temp_e_welfareconstant_list = msg.e_welfareconstant_list(i);
		E_WelfareConstant_List[i].read_from_pbmsg(temp_e_welfareconstant_list);
	}
}

E_WelfareQifu_s::E_WelfareQifu_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_WelfareQifu_s::CreateInit() {
	m_constantid = (int32_t)0;
	m_constantdata = (int32_t)0;
	return 0;
}

int E_WelfareQifu_s::ResumeInit() {
	return 0;
}

void E_WelfareQifu_s::write_to_pbmsg(::proto_ff::E_WelfareQifu & msg) const {
	msg.set_m_constantid((int32_t)m_constantid);
	msg.set_m_constantdata((int32_t)m_constantdata);
	msg.set_m_stringdata(m_stringdata.data());
}

void E_WelfareQifu_s::read_from_pbmsg(const ::proto_ff::E_WelfareQifu & msg) {
	m_constantid = msg.m_constantid();
	m_constantdata = msg.m_constantdata();
	m_stringdata = msg.m_stringdata();
}

Sheet_WelfareQifu_s::Sheet_WelfareQifu_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_WelfareQifu_s::CreateInit() {
	return 0;
}

int Sheet_WelfareQifu_s::ResumeInit() {
	return 0;
}

void Sheet_WelfareQifu_s::write_to_pbmsg(::proto_ff::Sheet_WelfareQifu & msg) const {
	for(int32_t i = 0; i < (int32_t)E_WelfareQifu_List.size(); ++i) {
		::proto_ff::E_WelfareQifu* temp_e_welfareqifu_list = msg.add_e_welfareqifu_list();
		E_WelfareQifu_List[i].write_to_pbmsg(*temp_e_welfareqifu_list);
	}
}

void Sheet_WelfareQifu_s::read_from_pbmsg(const ::proto_ff::Sheet_WelfareQifu & msg) {
	E_WelfareQifu_List.resize((int)msg.e_welfareqifu_list_size() > (int)E_WelfareQifu_List.max_size() ? E_WelfareQifu_List.max_size() : msg.e_welfareqifu_list_size());
	for(int32_t i = 0; i < (int32_t)E_WelfareQifu_List.size(); ++i) {
		const ::proto_ff::E_WelfareQifu & temp_e_welfareqifu_list = msg.e_welfareqifu_list(i);
		E_WelfareQifu_List[i].read_from_pbmsg(temp_e_welfareqifu_list);
	}
}

E_WelfareWish_s::E_WelfareWish_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_WelfareWish_s::CreateInit() {
	m_level = (int32_t)0;
	m_exp = (int64_t)0;
	return 0;
}

int E_WelfareWish_s::ResumeInit() {
	return 0;
}

void E_WelfareWish_s::write_to_pbmsg(::proto_ff::E_WelfareWish & msg) const {
	msg.set_m_level((int32_t)m_level);
	msg.set_m_exp((int64_t)m_exp);
}

void E_WelfareWish_s::read_from_pbmsg(const ::proto_ff::E_WelfareWish & msg) {
	m_level = msg.m_level();
	m_exp = msg.m_exp();
}

Sheet_WelfareWish_s::Sheet_WelfareWish_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_WelfareWish_s::CreateInit() {
	return 0;
}

int Sheet_WelfareWish_s::ResumeInit() {
	return 0;
}

void Sheet_WelfareWish_s::write_to_pbmsg(::proto_ff::Sheet_WelfareWish & msg) const {
	for(int32_t i = 0; i < (int32_t)E_WelfareWish_List.size(); ++i) {
		::proto_ff::E_WelfareWish* temp_e_welfarewish_list = msg.add_e_welfarewish_list();
		E_WelfareWish_List[i].write_to_pbmsg(*temp_e_welfarewish_list);
	}
}

void Sheet_WelfareWish_s::read_from_pbmsg(const ::proto_ff::Sheet_WelfareWish & msg) {
	E_WelfareWish_List.resize((int)msg.e_welfarewish_list_size() > (int)E_WelfareWish_List.max_size() ? E_WelfareWish_List.max_size() : msg.e_welfarewish_list_size());
	for(int32_t i = 0; i < (int32_t)E_WelfareWish_List.size(); ++i) {
		const ::proto_ff::E_WelfareWish & temp_e_welfarewish_list = msg.e_welfarewish_list(i);
		E_WelfareWish_List[i].read_from_pbmsg(temp_e_welfarewish_list);
	}
}

E_WelfareLogon_s::E_WelfareLogon_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_WelfareLogon_s::CreateInit() {
	m_days = (int32_t)0;
	m_type = (int32_t)0;
	m_icon = (int32_t)0;
	m_showItem = (int32_t)0;
	m_reward = (int32_t)0;
	return 0;
}

int E_WelfareLogon_s::ResumeInit() {
	return 0;
}

void E_WelfareLogon_s::write_to_pbmsg(::proto_ff::E_WelfareLogon & msg) const {
	msg.set_m_days((int32_t)m_days);
	msg.set_m_type((int32_t)m_type);
	msg.set_m_icon((int32_t)m_icon);
	msg.set_m_showitem((int32_t)m_showItem);
	msg.set_m_reward((int32_t)m_reward);
}

void E_WelfareLogon_s::read_from_pbmsg(const ::proto_ff::E_WelfareLogon & msg) {
	m_days = msg.m_days();
	m_type = msg.m_type();
	m_icon = msg.m_icon();
	m_showItem = msg.m_showitem();
	m_reward = msg.m_reward();
}

Sheet_WelfareLogon_s::Sheet_WelfareLogon_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_WelfareLogon_s::CreateInit() {
	return 0;
}

int Sheet_WelfareLogon_s::ResumeInit() {
	return 0;
}

void Sheet_WelfareLogon_s::write_to_pbmsg(::proto_ff::Sheet_WelfareLogon & msg) const {
	for(int32_t i = 0; i < (int32_t)E_WelfareLogon_List.size(); ++i) {
		::proto_ff::E_WelfareLogon* temp_e_welfarelogon_list = msg.add_e_welfarelogon_list();
		E_WelfareLogon_List[i].write_to_pbmsg(*temp_e_welfarelogon_list);
	}
}

void Sheet_WelfareLogon_s::read_from_pbmsg(const ::proto_ff::Sheet_WelfareLogon & msg) {
	E_WelfareLogon_List.resize((int)msg.e_welfarelogon_list_size() > (int)E_WelfareLogon_List.max_size() ? E_WelfareLogon_List.max_size() : msg.e_welfarelogon_list_size());
	for(int32_t i = 0; i < (int32_t)E_WelfareLogon_List.size(); ++i) {
		const ::proto_ff::E_WelfareLogon & temp_e_welfarelogon_list = msg.e_welfarelogon_list(i);
		E_WelfareLogon_List[i].read_from_pbmsg(temp_e_welfarelogon_list);
	}
}

E_WelfareFirstcharge_s::E_WelfareFirstcharge_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_WelfareFirstcharge_s::CreateInit() {
	m_constantid = (int32_t)0;
	m_openlv = (int32_t)0;
	m_type = (int32_t)0;
	m_openDays = (int32_t)0;
	m_reward = (int32_t)0;
	return 0;
}

int E_WelfareFirstcharge_s::ResumeInit() {
	return 0;
}

void E_WelfareFirstcharge_s::write_to_pbmsg(::proto_ff::E_WelfareFirstcharge & msg) const {
	msg.set_m_constantid((int32_t)m_constantid);
	msg.set_m_openlv((int32_t)m_openlv);
	msg.set_m_type((int32_t)m_type);
	msg.set_m_opendays((int32_t)m_openDays);
	msg.set_m_reward((int32_t)m_reward);
	for(int32_t i = 0; i < (int32_t)m_model.size(); ++i) {
		msg.add_m_model(m_model[i].data());
	}
	for(int32_t i = 0; i < (int32_t)m_rewardShow.size(); ++i) {
		msg.add_m_rewardshow((int32_t)m_rewardShow[i]);
	}
	for(int32_t i = 0; i < (int32_t)m_rewardDes.size(); ++i) {
		msg.add_m_rewarddes(m_rewardDes[i].data());
	}
}

void E_WelfareFirstcharge_s::read_from_pbmsg(const ::proto_ff::E_WelfareFirstcharge & msg) {
	m_constantid = msg.m_constantid();
	m_openlv = msg.m_openlv();
	m_type = msg.m_type();
	m_openDays = msg.m_opendays();
	m_reward = msg.m_reward();
	m_model.resize((int)msg.m_model_size() > (int)m_model.max_size() ? m_model.max_size() : msg.m_model_size());
	for(int32_t i = 0; i < (int32_t)m_model.size(); ++i) {
		m_model[i] = msg.m_model(i);
	}
	m_rewardShow.resize((int)msg.m_rewardshow_size() > (int)m_rewardShow.max_size() ? m_rewardShow.max_size() : msg.m_rewardshow_size());
	for(int32_t i = 0; i < (int32_t)m_rewardShow.size(); ++i) {
		m_rewardShow[i] = msg.m_rewardshow(i);
	}
	m_rewardDes.resize((int)msg.m_rewarddes_size() > (int)m_rewardDes.max_size() ? m_rewardDes.max_size() : msg.m_rewarddes_size());
	for(int32_t i = 0; i < (int32_t)m_rewardDes.size(); ++i) {
		m_rewardDes[i] = msg.m_rewarddes(i);
	}
}

Sheet_WelfareFirstcharge_s::Sheet_WelfareFirstcharge_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_WelfareFirstcharge_s::CreateInit() {
	return 0;
}

int Sheet_WelfareFirstcharge_s::ResumeInit() {
	return 0;
}

void Sheet_WelfareFirstcharge_s::write_to_pbmsg(::proto_ff::Sheet_WelfareFirstcharge & msg) const {
	for(int32_t i = 0; i < (int32_t)E_WelfareFirstcharge_List.size(); ++i) {
		::proto_ff::E_WelfareFirstcharge* temp_e_welfarefirstcharge_list = msg.add_e_welfarefirstcharge_list();
		E_WelfareFirstcharge_List[i].write_to_pbmsg(*temp_e_welfarefirstcharge_list);
	}
}

void Sheet_WelfareFirstcharge_s::read_from_pbmsg(const ::proto_ff::Sheet_WelfareFirstcharge & msg) {
	E_WelfareFirstcharge_List.resize((int)msg.e_welfarefirstcharge_list_size() > (int)E_WelfareFirstcharge_List.max_size() ? E_WelfareFirstcharge_List.max_size() : msg.e_welfarefirstcharge_list_size());
	for(int32_t i = 0; i < (int32_t)E_WelfareFirstcharge_List.size(); ++i) {
		const ::proto_ff::E_WelfareFirstcharge & temp_e_welfarefirstcharge_list = msg.e_welfarefirstcharge_list(i);
		E_WelfareFirstcharge_List[i].read_from_pbmsg(temp_e_welfarefirstcharge_list);
	}
}

E_WelfareSctype_s::E_WelfareSctype_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_WelfareSctype_s::CreateInit() {
	m_id = (int32_t)0;
	m_functionid = (int32_t)0;
	m_rcharge = (int32_t)0;
	return 0;
}

int E_WelfareSctype_s::ResumeInit() {
	return 0;
}

void E_WelfareSctype_s::write_to_pbmsg(::proto_ff::E_WelfareSctype & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_functionid((int32_t)m_functionid);
	msg.set_m_title(m_title.data());
	msg.set_m_basemap(m_baseMap.data());
	msg.set_m_rcharge((int32_t)m_rcharge);
}

void E_WelfareSctype_s::read_from_pbmsg(const ::proto_ff::E_WelfareSctype & msg) {
	m_id = msg.m_id();
	m_functionid = msg.m_functionid();
	m_title = msg.m_title();
	m_baseMap = msg.m_basemap();
	m_rcharge = msg.m_rcharge();
}

Sheet_WelfareSctype_s::Sheet_WelfareSctype_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_WelfareSctype_s::CreateInit() {
	return 0;
}

int Sheet_WelfareSctype_s::ResumeInit() {
	return 0;
}

void Sheet_WelfareSctype_s::write_to_pbmsg(::proto_ff::Sheet_WelfareSctype & msg) const {
	for(int32_t i = 0; i < (int32_t)E_WelfareSctype_List.size(); ++i) {
		::proto_ff::E_WelfareSctype* temp_e_welfaresctype_list = msg.add_e_welfaresctype_list();
		E_WelfareSctype_List[i].write_to_pbmsg(*temp_e_welfaresctype_list);
	}
}

void Sheet_WelfareSctype_s::read_from_pbmsg(const ::proto_ff::Sheet_WelfareSctype & msg) {
	E_WelfareSctype_List.resize((int)msg.e_welfaresctype_list_size() > (int)E_WelfareSctype_List.max_size() ? E_WelfareSctype_List.max_size() : msg.e_welfaresctype_list_size());
	for(int32_t i = 0; i < (int32_t)E_WelfareSctype_List.size(); ++i) {
		const ::proto_ff::E_WelfareSctype & temp_e_welfaresctype_list = msg.e_welfaresctype_list(i);
		E_WelfareSctype_List[i].read_from_pbmsg(temp_e_welfaresctype_list);
	}
}

E_WelfareMibao_s::E_WelfareMibao_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_WelfareMibao_s::CreateInit() {
	m_id = (int32_t)0;
	m_openlv = (int32_t)0;
	m_type = (int32_t)0;
	m_rank = (int32_t)0;
	m_openDays = (int32_t)0;
	m_reward = (int32_t)0;
	return 0;
}

int E_WelfareMibao_s::ResumeInit() {
	return 0;
}

void E_WelfareMibao_s::write_to_pbmsg(::proto_ff::E_WelfareMibao & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_openlv((int32_t)m_openlv);
	msg.set_m_type((int32_t)m_type);
	msg.set_m_rank((int32_t)m_rank);
	msg.set_m_opendays((int32_t)m_openDays);
	msg.set_m_reward((int32_t)m_reward);
	msg.set_m_des(m_des.data());
}

void E_WelfareMibao_s::read_from_pbmsg(const ::proto_ff::E_WelfareMibao & msg) {
	m_id = msg.m_id();
	m_openlv = msg.m_openlv();
	m_type = msg.m_type();
	m_rank = msg.m_rank();
	m_openDays = msg.m_opendays();
	m_reward = msg.m_reward();
	m_des = msg.m_des();
}

Sheet_WelfareMibao_s::Sheet_WelfareMibao_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_WelfareMibao_s::CreateInit() {
	return 0;
}

int Sheet_WelfareMibao_s::ResumeInit() {
	return 0;
}

void Sheet_WelfareMibao_s::write_to_pbmsg(::proto_ff::Sheet_WelfareMibao & msg) const {
	for(int32_t i = 0; i < (int32_t)E_WelfareMibao_List.size(); ++i) {
		::proto_ff::E_WelfareMibao* temp_e_welfaremibao_list = msg.add_e_welfaremibao_list();
		E_WelfareMibao_List[i].write_to_pbmsg(*temp_e_welfaremibao_list);
	}
}

void Sheet_WelfareMibao_s::read_from_pbmsg(const ::proto_ff::Sheet_WelfareMibao & msg) {
	E_WelfareMibao_List.resize((int)msg.e_welfaremibao_list_size() > (int)E_WelfareMibao_List.max_size() ? E_WelfareMibao_List.max_size() : msg.e_welfaremibao_list_size());
	for(int32_t i = 0; i < (int32_t)E_WelfareMibao_List.size(); ++i) {
		const ::proto_ff::E_WelfareMibao & temp_e_welfaremibao_list = msg.e_welfaremibao_list(i);
		E_WelfareMibao_List[i].read_from_pbmsg(temp_e_welfaremibao_list);
	}
}

E_WelfareKfleichong_s::E_WelfareKfleichong_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_WelfareKfleichong_s::CreateInit() {
	m_id = (int32_t)0;
	m_money = (int32_t)0;
	m_limit = (int32_t)0;
	m_reward = (int32_t)0;
	return 0;
}

int E_WelfareKfleichong_s::ResumeInit() {
	return 0;
}

void E_WelfareKfleichong_s::write_to_pbmsg(::proto_ff::E_WelfareKfleichong & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_money((int32_t)m_money);
	msg.set_m_limit((int32_t)m_limit);
	msg.set_m_reward((int32_t)m_reward);
}

void E_WelfareKfleichong_s::read_from_pbmsg(const ::proto_ff::E_WelfareKfleichong & msg) {
	m_id = msg.m_id();
	m_money = msg.m_money();
	m_limit = msg.m_limit();
	m_reward = msg.m_reward();
}

Sheet_WelfareKfleichong_s::Sheet_WelfareKfleichong_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_WelfareKfleichong_s::CreateInit() {
	return 0;
}

int Sheet_WelfareKfleichong_s::ResumeInit() {
	return 0;
}

void Sheet_WelfareKfleichong_s::write_to_pbmsg(::proto_ff::Sheet_WelfareKfleichong & msg) const {
	for(int32_t i = 0; i < (int32_t)E_WelfareKfleichong_List.size(); ++i) {
		::proto_ff::E_WelfareKfleichong* temp_e_welfarekfleichong_list = msg.add_e_welfarekfleichong_list();
		E_WelfareKfleichong_List[i].write_to_pbmsg(*temp_e_welfarekfleichong_list);
	}
}

void Sheet_WelfareKfleichong_s::read_from_pbmsg(const ::proto_ff::Sheet_WelfareKfleichong & msg) {
	E_WelfareKfleichong_List.resize((int)msg.e_welfarekfleichong_list_size() > (int)E_WelfareKfleichong_List.max_size() ? E_WelfareKfleichong_List.max_size() : msg.e_welfarekfleichong_list_size());
	for(int32_t i = 0; i < (int32_t)E_WelfareKfleichong_List.size(); ++i) {
		const ::proto_ff::E_WelfareKfleichong & temp_e_welfarekfleichong_list = msg.e_welfarekfleichong_list(i);
		E_WelfareKfleichong_List[i].read_from_pbmsg(temp_e_welfarekfleichong_list);
	}
}

E_WelfareDailygift_s::E_WelfareDailygift_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_WelfareDailygift_s::CreateInit() {
	m_id = (int32_t)0;
	m_type = (int32_t)0;
	m_rechargeId = (int32_t)0;
	m_OneclickBuy = (int32_t)0;
	m_reward = (int32_t)0;
	m_quality = (int32_t)0;
	return 0;
}

int E_WelfareDailygift_s::ResumeInit() {
	return 0;
}

void E_WelfareDailygift_s::write_to_pbmsg(::proto_ff::E_WelfareDailygift & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_type((int32_t)m_type);
	msg.set_m_rechargeid((int32_t)m_rechargeId);
	msg.set_m_oneclickbuy((int32_t)m_OneclickBuy);
	msg.set_m_reward((int32_t)m_reward);
	msg.set_m_quality((int32_t)m_quality);
}

void E_WelfareDailygift_s::read_from_pbmsg(const ::proto_ff::E_WelfareDailygift & msg) {
	m_id = msg.m_id();
	m_type = msg.m_type();
	m_rechargeId = msg.m_rechargeid();
	m_OneclickBuy = msg.m_oneclickbuy();
	m_reward = msg.m_reward();
	m_quality = msg.m_quality();
}

Sheet_WelfareDailygift_s::Sheet_WelfareDailygift_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_WelfareDailygift_s::CreateInit() {
	return 0;
}

int Sheet_WelfareDailygift_s::ResumeInit() {
	return 0;
}

void Sheet_WelfareDailygift_s::write_to_pbmsg(::proto_ff::Sheet_WelfareDailygift & msg) const {
	for(int32_t i = 0; i < (int32_t)E_WelfareDailygift_List.size(); ++i) {
		::proto_ff::E_WelfareDailygift* temp_e_welfaredailygift_list = msg.add_e_welfaredailygift_list();
		E_WelfareDailygift_List[i].write_to_pbmsg(*temp_e_welfaredailygift_list);
	}
}

void Sheet_WelfareDailygift_s::read_from_pbmsg(const ::proto_ff::Sheet_WelfareDailygift & msg) {
	E_WelfareDailygift_List.resize((int)msg.e_welfaredailygift_list_size() > (int)E_WelfareDailygift_List.max_size() ? E_WelfareDailygift_List.max_size() : msg.e_welfaredailygift_list_size());
	for(int32_t i = 0; i < (int32_t)E_WelfareDailygift_List.size(); ++i) {
		const ::proto_ff::E_WelfareDailygift & temp_e_welfaredailygift_list = msg.e_welfaredailygift_list(i);
		E_WelfareDailygift_List[i].read_from_pbmsg(temp_e_welfaredailygift_list);
	}
}

E_WelfareLcgift_s::E_WelfareLcgift_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_WelfareLcgift_s::CreateInit() {
	m_id = (int32_t)0;
	m_type = (int32_t)0;
	m_limit = (int32_t)0;
	m_days = (int32_t)0;
	m_starNum = (int32_t)0;
	m_reward = (int32_t)0;
	m_showItem = (int32_t)0;
	return 0;
}

int E_WelfareLcgift_s::ResumeInit() {
	return 0;
}

void E_WelfareLcgift_s::write_to_pbmsg(::proto_ff::E_WelfareLcgift & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_type((int32_t)m_type);
	msg.set_m_limit((int32_t)m_limit);
	msg.set_m_days((int32_t)m_days);
	msg.set_m_starnum((int32_t)m_starNum);
	msg.set_m_reward((int32_t)m_reward);
	msg.set_m_showitem((int32_t)m_showItem);
}

void E_WelfareLcgift_s::read_from_pbmsg(const ::proto_ff::E_WelfareLcgift & msg) {
	m_id = msg.m_id();
	m_type = msg.m_type();
	m_limit = msg.m_limit();
	m_days = msg.m_days();
	m_starNum = msg.m_starnum();
	m_reward = msg.m_reward();
	m_showItem = msg.m_showitem();
}

Sheet_WelfareLcgift_s::Sheet_WelfareLcgift_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_WelfareLcgift_s::CreateInit() {
	return 0;
}

int Sheet_WelfareLcgift_s::ResumeInit() {
	return 0;
}

void Sheet_WelfareLcgift_s::write_to_pbmsg(::proto_ff::Sheet_WelfareLcgift & msg) const {
	for(int32_t i = 0; i < (int32_t)E_WelfareLcgift_List.size(); ++i) {
		::proto_ff::E_WelfareLcgift* temp_e_welfarelcgift_list = msg.add_e_welfarelcgift_list();
		E_WelfareLcgift_List[i].write_to_pbmsg(*temp_e_welfarelcgift_list);
	}
}

void Sheet_WelfareLcgift_s::read_from_pbmsg(const ::proto_ff::Sheet_WelfareLcgift & msg) {
	E_WelfareLcgift_List.resize((int)msg.e_welfarelcgift_list_size() > (int)E_WelfareLcgift_List.max_size() ? E_WelfareLcgift_List.max_size() : msg.e_welfarelcgift_list_size());
	for(int32_t i = 0; i < (int32_t)E_WelfareLcgift_List.size(); ++i) {
		const ::proto_ff::E_WelfareLcgift & temp_e_welfarelcgift_list = msg.e_welfarelcgift_list(i);
		E_WelfareLcgift_List[i].read_from_pbmsg(temp_e_welfarelcgift_list);
	}
}

E_WelfareLcraffle_s::E_WelfareLcraffle_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_WelfareLcraffle_s::CreateInit() {
	m_id = (int32_t)0;
	m_money = (int32_t)0;
	m_limit = (int32_t)0;
	m_reward = (int32_t)0;
	return 0;
}

int E_WelfareLcraffle_s::ResumeInit() {
	return 0;
}

void E_WelfareLcraffle_s::write_to_pbmsg(::proto_ff::E_WelfareLcraffle & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_money((int32_t)m_money);
	msg.set_m_limit((int32_t)m_limit);
	msg.set_m_reward((int32_t)m_reward);
}

void E_WelfareLcraffle_s::read_from_pbmsg(const ::proto_ff::E_WelfareLcraffle & msg) {
	m_id = msg.m_id();
	m_money = msg.m_money();
	m_limit = msg.m_limit();
	m_reward = msg.m_reward();
}

Sheet_WelfareLcraffle_s::Sheet_WelfareLcraffle_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_WelfareLcraffle_s::CreateInit() {
	return 0;
}

int Sheet_WelfareLcraffle_s::ResumeInit() {
	return 0;
}

void Sheet_WelfareLcraffle_s::write_to_pbmsg(::proto_ff::Sheet_WelfareLcraffle & msg) const {
	for(int32_t i = 0; i < (int32_t)E_WelfareLcraffle_List.size(); ++i) {
		::proto_ff::E_WelfareLcraffle* temp_e_welfarelcraffle_list = msg.add_e_welfarelcraffle_list();
		E_WelfareLcraffle_List[i].write_to_pbmsg(*temp_e_welfarelcraffle_list);
	}
}

void Sheet_WelfareLcraffle_s::read_from_pbmsg(const ::proto_ff::Sheet_WelfareLcraffle & msg) {
	E_WelfareLcraffle_List.resize((int)msg.e_welfarelcraffle_list_size() > (int)E_WelfareLcraffle_List.max_size() ? E_WelfareLcraffle_List.max_size() : msg.e_welfarelcraffle_list_size());
	for(int32_t i = 0; i < (int32_t)E_WelfareLcraffle_List.size(); ++i) {
		const ::proto_ff::E_WelfareLcraffle & temp_e_welfarelcraffle_list = msg.e_welfarelcraffle_list(i);
		E_WelfareLcraffle_List[i].read_from_pbmsg(temp_e_welfarelcraffle_list);
	}
}

E_WelfareLcturntableRaffleDesc_s::E_WelfareLcturntableRaffleDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_WelfareLcturntableRaffleDesc_s::CreateInit() {
	m_num = (int32_t)0;
	m_item = (int32_t)0;
	return 0;
}

int E_WelfareLcturntableRaffleDesc_s::ResumeInit() {
	return 0;
}

void E_WelfareLcturntableRaffleDesc_s::write_to_pbmsg(::proto_ff::E_WelfareLcturntableRaffleDesc & msg) const {
	msg.set_m_num((int32_t)m_num);
	msg.set_m_item((int32_t)m_item);
}

void E_WelfareLcturntableRaffleDesc_s::read_from_pbmsg(const ::proto_ff::E_WelfareLcturntableRaffleDesc & msg) {
	m_num = msg.m_num();
	m_item = msg.m_item();
}

E_WelfareLcturntable_s::E_WelfareLcturntable_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_WelfareLcturntable_s::CreateInit() {
	m_id = (int32_t)0;
	m_jackpotType = (int32_t)0;
	m_raffleTimes = (int32_t)0;
	m_raTimesRew = (int32_t)0;
	return 0;
}

int E_WelfareLcturntable_s::ResumeInit() {
	return 0;
}

void E_WelfareLcturntable_s::write_to_pbmsg(::proto_ff::E_WelfareLcturntable & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_jackpottype((int32_t)m_jackpotType);
	msg.set_m_raffletimes((int32_t)m_raffleTimes);
	msg.set_m_ratimesrew((int32_t)m_raTimesRew);
	for(int32_t i = 0; i < (int32_t)m_raffle.size(); ++i) {
		::proto_ff::E_WelfareLcturntableRaffleDesc* temp_m_raffle = msg.add_m_raffle();
		m_raffle[i].write_to_pbmsg(*temp_m_raffle);
	}
}

void E_WelfareLcturntable_s::read_from_pbmsg(const ::proto_ff::E_WelfareLcturntable & msg) {
	m_id = msg.m_id();
	m_jackpotType = msg.m_jackpottype();
	m_raffleTimes = msg.m_raffletimes();
	m_raTimesRew = msg.m_ratimesrew();
	m_raffle.resize((int)msg.m_raffle_size() > (int)m_raffle.max_size() ? m_raffle.max_size() : msg.m_raffle_size());
	for(int32_t i = 0; i < (int32_t)m_raffle.size(); ++i) {
		const ::proto_ff::E_WelfareLcturntableRaffleDesc & temp_m_raffle = msg.m_raffle(i);
		m_raffle[i].read_from_pbmsg(temp_m_raffle);
	}
}

Sheet_WelfareLcturntable_s::Sheet_WelfareLcturntable_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_WelfareLcturntable_s::CreateInit() {
	return 0;
}

int Sheet_WelfareLcturntable_s::ResumeInit() {
	return 0;
}

void Sheet_WelfareLcturntable_s::write_to_pbmsg(::proto_ff::Sheet_WelfareLcturntable & msg) const {
	for(int32_t i = 0; i < (int32_t)E_WelfareLcturntable_List.size(); ++i) {
		::proto_ff::E_WelfareLcturntable* temp_e_welfarelcturntable_list = msg.add_e_welfarelcturntable_list();
		E_WelfareLcturntable_List[i].write_to_pbmsg(*temp_e_welfarelcturntable_list);
	}
}

void Sheet_WelfareLcturntable_s::read_from_pbmsg(const ::proto_ff::Sheet_WelfareLcturntable & msg) {
	E_WelfareLcturntable_List.resize((int)msg.e_welfarelcturntable_list_size() > (int)E_WelfareLcturntable_List.max_size() ? E_WelfareLcturntable_List.max_size() : msg.e_welfarelcturntable_list_size());
	for(int32_t i = 0; i < (int32_t)E_WelfareLcturntable_List.size(); ++i) {
		const ::proto_ff::E_WelfareLcturntable & temp_e_welfarelcturntable_list = msg.e_welfarelcturntable_list(i);
		E_WelfareLcturntable_List[i].read_from_pbmsg(temp_e_welfarelcturntable_list);
	}
}

E_WelfareJackpot_s::E_WelfareJackpot_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_WelfareJackpot_s::CreateInit() {
	m_id = (int32_t)0;
	m_type = (int32_t)0;
	m_rank = (int32_t)0;
	m_item = (int32_t)0;
	m_itemNum = (int32_t)0;
	m_weight = (int32_t)0;
	return 0;
}

int E_WelfareJackpot_s::ResumeInit() {
	return 0;
}

void E_WelfareJackpot_s::write_to_pbmsg(::proto_ff::E_WelfareJackpot & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_type((int32_t)m_type);
	msg.set_m_rank((int32_t)m_rank);
	msg.set_m_item((int32_t)m_item);
	msg.set_m_itemnum((int32_t)m_itemNum);
	msg.set_m_weight((int32_t)m_weight);
}

void E_WelfareJackpot_s::read_from_pbmsg(const ::proto_ff::E_WelfareJackpot & msg) {
	m_id = msg.m_id();
	m_type = msg.m_type();
	m_rank = msg.m_rank();
	m_item = msg.m_item();
	m_itemNum = msg.m_itemnum();
	m_weight = msg.m_weight();
}

Sheet_WelfareJackpot_s::Sheet_WelfareJackpot_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_WelfareJackpot_s::CreateInit() {
	return 0;
}

int Sheet_WelfareJackpot_s::ResumeInit() {
	return 0;
}

void Sheet_WelfareJackpot_s::write_to_pbmsg(::proto_ff::Sheet_WelfareJackpot & msg) const {
	for(int32_t i = 0; i < (int32_t)E_WelfareJackpot_List.size(); ++i) {
		::proto_ff::E_WelfareJackpot* temp_e_welfarejackpot_list = msg.add_e_welfarejackpot_list();
		E_WelfareJackpot_List[i].write_to_pbmsg(*temp_e_welfarejackpot_list);
	}
}

void Sheet_WelfareJackpot_s::read_from_pbmsg(const ::proto_ff::Sheet_WelfareJackpot & msg) {
	E_WelfareJackpot_List.resize((int)msg.e_welfarejackpot_list_size() > (int)E_WelfareJackpot_List.max_size() ? E_WelfareJackpot_List.max_size() : msg.e_welfarejackpot_list_size());
	for(int32_t i = 0; i < (int32_t)E_WelfareJackpot_List.size(); ++i) {
		const ::proto_ff::E_WelfareJackpot & temp_e_welfarejackpot_list = msg.e_welfarejackpot_list(i);
		E_WelfareJackpot_List[i].read_from_pbmsg(temp_e_welfarejackpot_list);
	}
}

E_WelfareMonthlycard_s::E_WelfareMonthlycard_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_WelfareMonthlycard_s::CreateInit() {
	m_id = (int32_t)0;
	m_cardType = (int32_t)0;
	m_cardMoney = (int32_t)0;
	m_cardBuyitem = (int32_t)0;
	m_cardDailyitem = (int32_t)0;
	m_cardTime = (int32_t)0;
	m_Flmultiple = (int32_t)0;
	return 0;
}

int E_WelfareMonthlycard_s::ResumeInit() {
	return 0;
}

void E_WelfareMonthlycard_s::write_to_pbmsg(::proto_ff::E_WelfareMonthlycard & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_cardtype((int32_t)m_cardType);
	msg.set_m_cardmoney((int32_t)m_cardMoney);
	msg.set_m_cardbuyitem((int32_t)m_cardBuyitem);
	msg.set_m_carddailyitem((int32_t)m_cardDailyitem);
	msg.set_m_cardtime((int32_t)m_cardTime);
	msg.set_m_flmultiple((int32_t)m_Flmultiple);
}

void E_WelfareMonthlycard_s::read_from_pbmsg(const ::proto_ff::E_WelfareMonthlycard & msg) {
	m_id = msg.m_id();
	m_cardType = msg.m_cardtype();
	m_cardMoney = msg.m_cardmoney();
	m_cardBuyitem = msg.m_cardbuyitem();
	m_cardDailyitem = msg.m_carddailyitem();
	m_cardTime = msg.m_cardtime();
	m_Flmultiple = msg.m_flmultiple();
}

Sheet_WelfareMonthlycard_s::Sheet_WelfareMonthlycard_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_WelfareMonthlycard_s::CreateInit() {
	return 0;
}

int Sheet_WelfareMonthlycard_s::ResumeInit() {
	return 0;
}

void Sheet_WelfareMonthlycard_s::write_to_pbmsg(::proto_ff::Sheet_WelfareMonthlycard & msg) const {
	for(int32_t i = 0; i < (int32_t)E_WelfareMonthlycard_List.size(); ++i) {
		::proto_ff::E_WelfareMonthlycard* temp_e_welfaremonthlycard_list = msg.add_e_welfaremonthlycard_list();
		E_WelfareMonthlycard_List[i].write_to_pbmsg(*temp_e_welfaremonthlycard_list);
	}
}

void Sheet_WelfareMonthlycard_s::read_from_pbmsg(const ::proto_ff::Sheet_WelfareMonthlycard & msg) {
	E_WelfareMonthlycard_List.resize((int)msg.e_welfaremonthlycard_list_size() > (int)E_WelfareMonthlycard_List.max_size() ? E_WelfareMonthlycard_List.max_size() : msg.e_welfaremonthlycard_list_size());
	for(int32_t i = 0; i < (int32_t)E_WelfareMonthlycard_List.size(); ++i) {
		const ::proto_ff::E_WelfareMonthlycard & temp_e_welfaremonthlycard_list = msg.e_welfaremonthlycard_list(i);
		E_WelfareMonthlycard_List[i].read_from_pbmsg(temp_e_welfaremonthlycard_list);
	}
}

E_WelfareGoal_s::E_WelfareGoal_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_WelfareGoal_s::CreateInit() {
	m_id = (int32_t)0;
	m_functionid = (int32_t)0;
	m_taskGroup = (int32_t)0;
	m_tasknum = (int32_t)0;
	m_rewrdItem = (int32_t)0;
	m_time = (int32_t)0;
	return 0;
}

int E_WelfareGoal_s::ResumeInit() {
	return 0;
}

void E_WelfareGoal_s::write_to_pbmsg(::proto_ff::E_WelfareGoal & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_functionid((int32_t)m_functionid);
	msg.set_m_taskgroup((int32_t)m_taskGroup);
	msg.set_m_tasknum((int32_t)m_tasknum);
	msg.set_m_rewrditem((int32_t)m_rewrdItem);
	msg.set_m_time((int32_t)m_time);
}

void E_WelfareGoal_s::read_from_pbmsg(const ::proto_ff::E_WelfareGoal & msg) {
	m_id = msg.m_id();
	m_functionid = msg.m_functionid();
	m_taskGroup = msg.m_taskgroup();
	m_tasknum = msg.m_tasknum();
	m_rewrdItem = msg.m_rewrditem();
	m_time = msg.m_time();
}

Sheet_WelfareGoal_s::Sheet_WelfareGoal_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_WelfareGoal_s::CreateInit() {
	return 0;
}

int Sheet_WelfareGoal_s::ResumeInit() {
	return 0;
}

void Sheet_WelfareGoal_s::write_to_pbmsg(::proto_ff::Sheet_WelfareGoal & msg) const {
	for(int32_t i = 0; i < (int32_t)E_WelfareGoal_List.size(); ++i) {
		::proto_ff::E_WelfareGoal* temp_e_welfaregoal_list = msg.add_e_welfaregoal_list();
		E_WelfareGoal_List[i].write_to_pbmsg(*temp_e_welfaregoal_list);
	}
}

void Sheet_WelfareGoal_s::read_from_pbmsg(const ::proto_ff::Sheet_WelfareGoal & msg) {
	E_WelfareGoal_List.resize((int)msg.e_welfaregoal_list_size() > (int)E_WelfareGoal_List.max_size() ? E_WelfareGoal_List.max_size() : msg.e_welfaregoal_list_size());
	for(int32_t i = 0; i < (int32_t)E_WelfareGoal_List.size(); ++i) {
		const ::proto_ff::E_WelfareGoal & temp_e_welfaregoal_list = msg.e_welfaregoal_list(i);
		E_WelfareGoal_List[i].read_from_pbmsg(temp_e_welfaregoal_list);
	}
}

E_WelfareGoaltask_s::E_WelfareGoaltask_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_WelfareGoaltask_s::CreateInit() {
	m_id = (int32_t)0;
	m_groupID = (int32_t)0;
	m_eventType = (int32_t)0;
	m_reachPrice = (int32_t)0;
	m_itemID = (int32_t)0;
	m_itemNum = (int32_t)0;
	return 0;
}

int E_WelfareGoaltask_s::ResumeInit() {
	return 0;
}

void E_WelfareGoaltask_s::write_to_pbmsg(::proto_ff::E_WelfareGoaltask & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_groupid((int32_t)m_groupID);
	msg.set_m_eventtype((int32_t)m_eventType);
	msg.set_m_reachprice((int32_t)m_reachPrice);
	msg.set_m_itemid((int32_t)m_itemID);
	msg.set_m_itemnum((int32_t)m_itemNum);
	for(int32_t i = 0; i < (int32_t)m_param.size(); ++i) {
		msg.add_m_param((int32_t)m_param[i]);
	}
}

void E_WelfareGoaltask_s::read_from_pbmsg(const ::proto_ff::E_WelfareGoaltask & msg) {
	m_id = msg.m_id();
	m_groupID = msg.m_groupid();
	m_eventType = msg.m_eventtype();
	m_reachPrice = msg.m_reachprice();
	m_itemID = msg.m_itemid();
	m_itemNum = msg.m_itemnum();
	m_param.resize((int)msg.m_param_size() > (int)m_param.max_size() ? m_param.max_size() : msg.m_param_size());
	for(int32_t i = 0; i < (int32_t)m_param.size(); ++i) {
		m_param[i] = msg.m_param(i);
	}
}

Sheet_WelfareGoaltask_s::Sheet_WelfareGoaltask_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_WelfareGoaltask_s::CreateInit() {
	return 0;
}

int Sheet_WelfareGoaltask_s::ResumeInit() {
	return 0;
}

void Sheet_WelfareGoaltask_s::write_to_pbmsg(::proto_ff::Sheet_WelfareGoaltask & msg) const {
	for(int32_t i = 0; i < (int32_t)E_WelfareGoaltask_List.size(); ++i) {
		::proto_ff::E_WelfareGoaltask* temp_e_welfaregoaltask_list = msg.add_e_welfaregoaltask_list();
		E_WelfareGoaltask_List[i].write_to_pbmsg(*temp_e_welfaregoaltask_list);
	}
}

void Sheet_WelfareGoaltask_s::read_from_pbmsg(const ::proto_ff::Sheet_WelfareGoaltask & msg) {
	E_WelfareGoaltask_List.resize((int)msg.e_welfaregoaltask_list_size() > (int)E_WelfareGoaltask_List.max_size() ? E_WelfareGoaltask_List.max_size() : msg.e_welfaregoaltask_list_size());
	for(int32_t i = 0; i < (int32_t)E_WelfareGoaltask_List.size(); ++i) {
		const ::proto_ff::E_WelfareGoaltask & temp_e_welfaregoaltask_list = msg.e_welfaregoaltask_list(i);
		E_WelfareGoaltask_List[i].read_from_pbmsg(temp_e_welfaregoaltask_list);
	}
}

E_WelfareInvest_s::E_WelfareInvest_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_WelfareInvest_s::CreateInit() {
	m_id = (int32_t)0;
	m_functionID = (int32_t)0;
	m_price = (int32_t)0;
	m_rewardItem = (int32_t)0;
	m_rewardGroup = (int32_t)0;
	return 0;
}

int E_WelfareInvest_s::ResumeInit() {
	return 0;
}

void E_WelfareInvest_s::write_to_pbmsg(::proto_ff::E_WelfareInvest & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_functionid((int32_t)m_functionID);
	msg.set_m_price((int32_t)m_price);
	msg.set_m_rewarditem((int32_t)m_rewardItem);
	msg.set_m_rewardgroup((int32_t)m_rewardGroup);
}

void E_WelfareInvest_s::read_from_pbmsg(const ::proto_ff::E_WelfareInvest & msg) {
	m_id = msg.m_id();
	m_functionID = msg.m_functionid();
	m_price = msg.m_price();
	m_rewardItem = msg.m_rewarditem();
	m_rewardGroup = msg.m_rewardgroup();
}

Sheet_WelfareInvest_s::Sheet_WelfareInvest_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_WelfareInvest_s::CreateInit() {
	return 0;
}

int Sheet_WelfareInvest_s::ResumeInit() {
	return 0;
}

void Sheet_WelfareInvest_s::write_to_pbmsg(::proto_ff::Sheet_WelfareInvest & msg) const {
	for(int32_t i = 0; i < (int32_t)E_WelfareInvest_List.size(); ++i) {
		::proto_ff::E_WelfareInvest* temp_e_welfareinvest_list = msg.add_e_welfareinvest_list();
		E_WelfareInvest_List[i].write_to_pbmsg(*temp_e_welfareinvest_list);
	}
}

void Sheet_WelfareInvest_s::read_from_pbmsg(const ::proto_ff::Sheet_WelfareInvest & msg) {
	E_WelfareInvest_List.resize((int)msg.e_welfareinvest_list_size() > (int)E_WelfareInvest_List.max_size() ? E_WelfareInvest_List.max_size() : msg.e_welfareinvest_list_size());
	for(int32_t i = 0; i < (int32_t)E_WelfareInvest_List.size(); ++i) {
		const ::proto_ff::E_WelfareInvest & temp_e_welfareinvest_list = msg.e_welfareinvest_list(i);
		E_WelfareInvest_List[i].read_from_pbmsg(temp_e_welfareinvest_list);
	}
}

E_WelfareInvestrewardItemDesc_s::E_WelfareInvestrewardItemDesc_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_WelfareInvestrewardItemDesc_s::CreateInit() {
	m_num = (int32_t)0;
	m_id = (int32_t)0;
	return 0;
}

int E_WelfareInvestrewardItemDesc_s::ResumeInit() {
	return 0;
}

void E_WelfareInvestrewardItemDesc_s::write_to_pbmsg(::proto_ff::E_WelfareInvestrewardItemDesc & msg) const {
	msg.set_m_num((int32_t)m_num);
	msg.set_m_id((int32_t)m_id);
}

void E_WelfareInvestrewardItemDesc_s::read_from_pbmsg(const ::proto_ff::E_WelfareInvestrewardItemDesc & msg) {
	m_num = msg.m_num();
	m_id = msg.m_id();
}

E_WelfareInvestreward_s::E_WelfareInvestreward_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_WelfareInvestreward_s::CreateInit() {
	m_id = (int32_t)0;
	m_group = (int32_t)0;
	m_lv = (int32_t)0;
	return 0;
}

int E_WelfareInvestreward_s::ResumeInit() {
	return 0;
}

void E_WelfareInvestreward_s::write_to_pbmsg(::proto_ff::E_WelfareInvestreward & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_group((int32_t)m_group);
	msg.set_m_lv((int32_t)m_lv);
	for(int32_t i = 0; i < (int32_t)m_Item.size(); ++i) {
		::proto_ff::E_WelfareInvestrewardItemDesc* temp_m_item = msg.add_m_item();
		m_Item[i].write_to_pbmsg(*temp_m_item);
	}
}

void E_WelfareInvestreward_s::read_from_pbmsg(const ::proto_ff::E_WelfareInvestreward & msg) {
	m_id = msg.m_id();
	m_group = msg.m_group();
	m_lv = msg.m_lv();
	m_Item.resize((int)msg.m_item_size() > (int)m_Item.max_size() ? m_Item.max_size() : msg.m_item_size());
	for(int32_t i = 0; i < (int32_t)m_Item.size(); ++i) {
		const ::proto_ff::E_WelfareInvestrewardItemDesc & temp_m_item = msg.m_item(i);
		m_Item[i].read_from_pbmsg(temp_m_item);
	}
}

Sheet_WelfareInvestreward_s::Sheet_WelfareInvestreward_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_WelfareInvestreward_s::CreateInit() {
	return 0;
}

int Sheet_WelfareInvestreward_s::ResumeInit() {
	return 0;
}

void Sheet_WelfareInvestreward_s::write_to_pbmsg(::proto_ff::Sheet_WelfareInvestreward & msg) const {
	for(int32_t i = 0; i < (int32_t)E_WelfareInvestreward_List.size(); ++i) {
		::proto_ff::E_WelfareInvestreward* temp_e_welfareinvestreward_list = msg.add_e_welfareinvestreward_list();
		E_WelfareInvestreward_List[i].write_to_pbmsg(*temp_e_welfareinvestreward_list);
	}
}

void Sheet_WelfareInvestreward_s::read_from_pbmsg(const ::proto_ff::Sheet_WelfareInvestreward & msg) {
	E_WelfareInvestreward_List.resize((int)msg.e_welfareinvestreward_list_size() > (int)E_WelfareInvestreward_List.max_size() ? E_WelfareInvestreward_List.max_size() : msg.e_welfareinvestreward_list_size());
	for(int32_t i = 0; i < (int32_t)E_WelfareInvestreward_List.size(); ++i) {
		const ::proto_ff::E_WelfareInvestreward & temp_e_welfareinvestreward_list = msg.e_welfareinvestreward_list(i);
		E_WelfareInvestreward_List[i].read_from_pbmsg(temp_e_welfareinvestreward_list);
	}
}

E_WelfareYttlgift_s::E_WelfareYttlgift_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_WelfareYttlgift_s::CreateInit() {
	m_id = (int32_t)0;
	m_rechargeId = (int32_t)0;
	m_reward = (int32_t)0;
	return 0;
}

int E_WelfareYttlgift_s::ResumeInit() {
	return 0;
}

void E_WelfareYttlgift_s::write_to_pbmsg(::proto_ff::E_WelfareYttlgift & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_rechargeid((int32_t)m_rechargeId);
	msg.set_m_reward((int32_t)m_reward);
}

void E_WelfareYttlgift_s::read_from_pbmsg(const ::proto_ff::E_WelfareYttlgift & msg) {
	m_id = msg.m_id();
	m_rechargeId = msg.m_rechargeid();
	m_reward = msg.m_reward();
}

Sheet_WelfareYttlgift_s::Sheet_WelfareYttlgift_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_WelfareYttlgift_s::CreateInit() {
	return 0;
}

int Sheet_WelfareYttlgift_s::ResumeInit() {
	return 0;
}

void Sheet_WelfareYttlgift_s::write_to_pbmsg(::proto_ff::Sheet_WelfareYttlgift & msg) const {
	for(int32_t i = 0; i < (int32_t)E_WelfareYttlgift_List.size(); ++i) {
		::proto_ff::E_WelfareYttlgift* temp_e_welfareyttlgift_list = msg.add_e_welfareyttlgift_list();
		E_WelfareYttlgift_List[i].write_to_pbmsg(*temp_e_welfareyttlgift_list);
	}
}

void Sheet_WelfareYttlgift_s::read_from_pbmsg(const ::proto_ff::Sheet_WelfareYttlgift & msg) {
	E_WelfareYttlgift_List.resize((int)msg.e_welfareyttlgift_list_size() > (int)E_WelfareYttlgift_List.max_size() ? E_WelfareYttlgift_List.max_size() : msg.e_welfareyttlgift_list_size());
	for(int32_t i = 0; i < (int32_t)E_WelfareYttlgift_List.size(); ++i) {
		const ::proto_ff::E_WelfareYttlgift & temp_e_welfareyttlgift_list = msg.e_welfareyttlgift_list(i);
		E_WelfareYttlgift_List[i].read_from_pbmsg(temp_e_welfareyttlgift_list);
	}
}

}
