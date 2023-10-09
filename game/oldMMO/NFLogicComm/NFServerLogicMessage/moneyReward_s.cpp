#include "moneyReward_s.h"

namespace proto_ff_s {

E_MoneyrewardMoneyreward_s::E_MoneyrewardMoneyreward_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_MoneyrewardMoneyreward_s::CreateInit() {
	m_taskreward = (int32_t)0;
	m_task = (int32_t)0;
	m_taskmax = (int32_t)0;
	m_freeunlocklv = (int32_t)0;
	m_viplv = (int32_t)0;
	m_timeget = (int32_t)0;
	m_timegetmoney = (int32_t)0;
	m_timego = (int32_t)0;
	return 0;
}

int E_MoneyrewardMoneyreward_s::ResumeInit() {
	return 0;
}

void E_MoneyrewardMoneyreward_s::write_to_pbmsg(::proto_ff::E_MoneyrewardMoneyreward & msg) const {
	msg.set_m_taskreward((int32_t)m_taskreward);
	msg.set_m_boxtaskreward((const char*)m_boxtaskreward.data());
	msg.set_m_boxnum((const char*)m_boxnum.data());
	msg.set_m_task((int32_t)m_task);
	msg.set_m_taskmax((int32_t)m_taskmax);
	msg.set_m_oneprice((const char*)m_oneprice.data());
	msg.set_m_freeunlocklv((int32_t)m_freeunlocklv);
	msg.set_m_viplv((int32_t)m_viplv);
	msg.set_m_timeget((int32_t)m_timeget);
	msg.set_m_timegetmoney((int32_t)m_timegetmoney);
	msg.set_m_timego((int32_t)m_timego);
}

void E_MoneyrewardMoneyreward_s::read_from_pbmsg(const ::proto_ff::E_MoneyrewardMoneyreward & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct E_MoneyrewardMoneyreward_s));
	m_taskreward = msg.m_taskreward();
	m_boxtaskreward = msg.m_boxtaskreward();
	m_boxnum = msg.m_boxnum();
	m_task = msg.m_task();
	m_taskmax = msg.m_taskmax();
	m_oneprice = msg.m_oneprice();
	m_freeunlocklv = msg.m_freeunlocklv();
	m_viplv = msg.m_viplv();
	m_timeget = msg.m_timeget();
	m_timegetmoney = msg.m_timegetmoney();
	m_timego = msg.m_timego();
}

Sheet_MoneyrewardMoneyreward_s::Sheet_MoneyrewardMoneyreward_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_MoneyrewardMoneyreward_s::CreateInit() {
	return 0;
}

int Sheet_MoneyrewardMoneyreward_s::ResumeInit() {
	return 0;
}

void Sheet_MoneyrewardMoneyreward_s::write_to_pbmsg(::proto_ff::Sheet_MoneyrewardMoneyreward & msg) const {
	for(int32_t i = 0; i < (int32_t)E_MoneyrewardMoneyreward_List.size(); ++i) {
		::proto_ff::E_MoneyrewardMoneyreward* temp_e_moneyrewardmoneyreward_list = msg.add_e_moneyrewardmoneyreward_list();
		E_MoneyrewardMoneyreward_List[i].write_to_pbmsg(*temp_e_moneyrewardmoneyreward_list);
	}
}

void Sheet_MoneyrewardMoneyreward_s::read_from_pbmsg(const ::proto_ff::Sheet_MoneyrewardMoneyreward & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_MoneyrewardMoneyreward_s));
	E_MoneyrewardMoneyreward_List.resize((int)msg.e_moneyrewardmoneyreward_list_size() > (int)E_MoneyrewardMoneyreward_List.max_size() ? E_MoneyrewardMoneyreward_List.max_size() : msg.e_moneyrewardmoneyreward_list_size());
	for(int32_t i = 0; i < (int32_t)E_MoneyrewardMoneyreward_List.size(); ++i) {
		const ::proto_ff::E_MoneyrewardMoneyreward & temp_e_moneyrewardmoneyreward_list = msg.e_moneyrewardmoneyreward_list(i);
		E_MoneyrewardMoneyreward_List[i].read_from_pbmsg(temp_e_moneyrewardmoneyreward_list);
	}
}

}