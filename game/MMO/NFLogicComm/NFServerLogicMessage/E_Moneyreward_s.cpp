#include "E_Moneyreward_s.h"

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
	m_taskMax = (int32_t)0;
	m_vipLV = (int32_t)0;
	m_timeGet = (int32_t)0;
	m_timeGetMoney = (int32_t)0;
	m_timeGo = (int32_t)0;
	return 0;
}

int E_MoneyrewardMoneyreward_s::ResumeInit() {
	return 0;
}

void E_MoneyrewardMoneyreward_s::write_to_pbmsg(::proto_ff::E_MoneyrewardMoneyreward & msg) const {
	msg.set_m_taskreward((int32_t)m_taskreward);
	msg.set_m_boxtaskreward(m_boxTaskreward.data());
	msg.set_m_boxnum(m_boxNum.data());
	msg.set_m_task((int32_t)m_task);
	msg.set_m_taskmax((int32_t)m_taskMax);
	msg.set_m_oneprice(m_onePrice.data());
	msg.set_m_freeunlocklv(m_freeUnlockLv.data());
	msg.set_m_viplv((int32_t)m_vipLV);
	msg.set_m_timeget((int32_t)m_timeGet);
	msg.set_m_timegetmoney((int32_t)m_timeGetMoney);
	msg.set_m_timego((int32_t)m_timeGo);
}

void E_MoneyrewardMoneyreward_s::read_from_pbmsg(const ::proto_ff::E_MoneyrewardMoneyreward & msg) {
	m_taskreward = msg.m_taskreward();
	m_boxTaskreward = msg.m_boxtaskreward();
	m_boxNum = msg.m_boxnum();
	m_task = msg.m_task();
	m_taskMax = msg.m_taskmax();
	m_onePrice = msg.m_oneprice();
	m_freeUnlockLv = msg.m_freeunlocklv();
	m_vipLV = msg.m_viplv();
	m_timeGet = msg.m_timeget();
	m_timeGetMoney = msg.m_timegetmoney();
	m_timeGo = msg.m_timego();
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
	E_MoneyrewardMoneyreward_List.resize((int)msg.e_moneyrewardmoneyreward_list_size() > (int)E_MoneyrewardMoneyreward_List.max_size() ? E_MoneyrewardMoneyreward_List.max_size() : msg.e_moneyrewardmoneyreward_list_size());
	for(int32_t i = 0; i < (int32_t)E_MoneyrewardMoneyreward_List.size(); ++i) {
		const ::proto_ff::E_MoneyrewardMoneyreward & temp_e_moneyrewardmoneyreward_list = msg.e_moneyrewardmoneyreward_list(i);
		E_MoneyrewardMoneyreward_List[i].read_from_pbmsg(temp_e_moneyrewardmoneyreward_list);
	}
}

}
