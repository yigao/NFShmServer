#include "room_s.h"

namespace proto_ff_s {

E_RoomRoom_s::E_RoomRoom_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int E_RoomRoom_s::CreateInit() {
	m_id = (int32_t)0;
	m_roomid = (int32_t)0;
	m_gameid = (int32_t)0;
	m_roomtype = (int32_t)0;
	m_roomlevel = (int32_t)0;
	m_sitenum = (int32_t)0;
	m_deskcount = (int32_t)0;
	m_maxpeople = (int32_t)0;
	m_enter_min = (int32_t)0;
	m_enter_max = (int32_t)0;
	m_auto_chair = (int32_t)0;
	m_is_exp_scene = (int32_t)0;
	m_exp_scene_gold = (int32_t)0;
	m_tax = (int32_t)0;
	return 0;
}

int E_RoomRoom_s::ResumeInit() {
	return 0;
}

void E_RoomRoom_s::write_to_pbmsg(::proto_ff::E_RoomRoom & msg) const {
	msg.set_m_id((int32_t)m_id);
	msg.set_m_roomid((int32_t)m_roomid);
	msg.set_m_gameid((int32_t)m_gameid);
	msg.set_m_gamename((const char*)m_gamename.data());
	msg.set_m_roomtype((int32_t)m_roomtype);
	msg.set_m_roomlevel((int32_t)m_roomlevel);
	msg.set_m_roomname((const char*)m_roomname.data());
	msg.set_m_sitenum((int32_t)m_sitenum);
	msg.set_m_deskcount((int32_t)m_deskcount);
	msg.set_m_maxpeople((int32_t)m_maxpeople);
	msg.set_m_enter_min((int32_t)m_enter_min);
	msg.set_m_enter_max((int32_t)m_enter_max);
	msg.set_m_auto_chair((int32_t)m_auto_chair);
	msg.set_m_is_exp_scene((int32_t)m_is_exp_scene);
	msg.set_m_exp_scene_gold((int32_t)m_exp_scene_gold);
	msg.set_m_tax((int32_t)m_tax);
}

void E_RoomRoom_s::read_from_pbmsg(const ::proto_ff::E_RoomRoom & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct E_RoomRoom_s));
	m_id = msg.m_id();
	m_roomid = msg.m_roomid();
	m_gameid = msg.m_gameid();
	m_gamename = msg.m_gamename();
	m_roomtype = msg.m_roomtype();
	m_roomlevel = msg.m_roomlevel();
	m_roomname = msg.m_roomname();
	m_sitenum = msg.m_sitenum();
	m_deskcount = msg.m_deskcount();
	m_maxpeople = msg.m_maxpeople();
	m_enter_min = msg.m_enter_min();
	m_enter_max = msg.m_enter_max();
	m_auto_chair = msg.m_auto_chair();
	m_is_exp_scene = msg.m_is_exp_scene();
	m_exp_scene_gold = msg.m_exp_scene_gold();
	m_tax = msg.m_tax();
}

Sheet_RoomRoom_s::Sheet_RoomRoom_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Sheet_RoomRoom_s::CreateInit() {
	return 0;
}

int Sheet_RoomRoom_s::ResumeInit() {
	return 0;
}

void Sheet_RoomRoom_s::write_to_pbmsg(::proto_ff::Sheet_RoomRoom & msg) const {
	for(int32_t i = 0; i < (int32_t)E_RoomRoom_List.size(); ++i) {
		::proto_ff::E_RoomRoom* temp_e_roomroom_list = msg.add_e_roomroom_list();
		E_RoomRoom_List[i].write_to_pbmsg(*temp_e_roomroom_list);
	}
}

void Sheet_RoomRoom_s::read_from_pbmsg(const ::proto_ff::Sheet_RoomRoom & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Sheet_RoomRoom_s));
	E_RoomRoom_List.resize((int)msg.e_roomroom_list_size() > (int)E_RoomRoom_List.max_size() ? E_RoomRoom_List.max_size() : msg.e_roomroom_list_size());
	for(int32_t i = 0; i < (int32_t)E_RoomRoom_List.size(); ++i) {
		const ::proto_ff::E_RoomRoom & temp_e_roomroom_list = msg.e_roomroom_list(i);
		E_RoomRoom_List[i].read_from_pbmsg(temp_e_roomroom_list);
	}
}

}