#include "DBProxy2_s.h"

namespace proto_ff_s {

dbServerMgr_s::dbServerMgr_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int dbServerMgr_s::CreateInit() {
	id = (uint64_t)0;
	cur_count = (uint32_t)0;
	last_login_time = (uint64_t)0;
	last_logout_time = (uint64_t)0;
	return 0;
}

int dbServerMgr_s::ResumeInit() {
	return 0;
}

void dbServerMgr_s::write_to_pbmsg(::proto_ff::dbServerMgr & msg) const {
	msg.set_id((uint64_t)id);
	msg.set_contract(contract.data());
	msg.set_machine_addr(machine_addr.data());
	msg.set_ip(ip.data());
	msg.set_bus_name(bus_name.data());
	msg.set_server_desc(server_desc.data());
	msg.set_cur_count((uint32_t)cur_count);
	msg.set_last_login_time((uint64_t)last_login_time);
	msg.set_last_logout_time((uint64_t)last_logout_time);
	for(int32_t i = 0; i < (int32_t)logout_time.size(); ++i) {
		msg.add_logout_time((uint64_t)logout_time[i]);
	}
	for(int32_t i = 0; i < (int32_t)desc.size(); ++i) {
		msg.add_desc(desc[i].data());
	}
	for(int32_t i = 0; i < (int32_t)pair.size(); ++i) {
		::proto_ff::ComPair* temp_pair = msg.add_pair();
		pair[i].write_to_pbmsg(*temp_pair);
	}
	for(int32_t i = 0; i < (int32_t)facade.size(); ++i) {
		::proto_ff::BestEQSlotInfo* temp_facade = msg.add_facade();
		facade[i].write_to_pbmsg(*temp_facade);
	}
}

void dbServerMgr_s::read_from_pbmsg(const ::proto_ff::dbServerMgr & msg) {
	id = msg.id();
	contract = msg.contract();
	machine_addr = msg.machine_addr();
	ip = msg.ip();
	bus_name = msg.bus_name();
	server_desc = msg.server_desc();
	cur_count = msg.cur_count();
	last_login_time = msg.last_login_time();
	last_logout_time = msg.last_logout_time();
	logout_time.resize((int)msg.logout_time_size() > (int)logout_time.max_size() ? logout_time.max_size() : msg.logout_time_size());
	for(int32_t i = 0; i < (int32_t)logout_time.size(); ++i) {
		logout_time[i] = msg.logout_time(i);
	}
	desc.resize((int)msg.desc_size() > (int)desc.max_size() ? desc.max_size() : msg.desc_size());
	for(int32_t i = 0; i < (int32_t)desc.size(); ++i) {
		desc[i] = msg.desc(i);
	}
	pair.resize((int)msg.pair_size() > (int)pair.max_size() ? pair.max_size() : msg.pair_size());
	for(int32_t i = 0; i < (int32_t)pair.size(); ++i) {
		const ::proto_ff::ComPair & temp_pair = msg.pair(i);
		pair[i].read_from_pbmsg(temp_pair);
	}
	facade.resize((int)msg.facade_size() > (int)facade.max_size() ? facade.max_size() : msg.facade_size());
	for(int32_t i = 0; i < (int32_t)facade.size(); ++i) {
		const ::proto_ff::BestEQSlotInfo & temp_facade = msg.facade(i);
		facade[i].read_from_pbmsg(temp_facade);
	}
}

GetRegisterNum_RoleDBData_s::GetRegisterNum_RoleDBData_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int GetRegisterNum_RoleDBData_s::CreateInit() {
	num = (uint32_t)0;
	return 0;
}

int GetRegisterNum_RoleDBData_s::ResumeInit() {
	return 0;
}

void GetRegisterNum_RoleDBData_s::write_to_pbmsg(::proto_ff::GetRegisterNum_RoleDBData & msg) const {
	msg.set_num((uint32_t)num);
}

void GetRegisterNum_RoleDBData_s::read_from_pbmsg(const ::proto_ff::GetRegisterNum_RoleDBData & msg) {
	num = msg.num();
}

RoleDBSnsSimple_s::RoleDBSnsSimple_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int RoleDBSnsSimple_s::CreateInit() {
	cid = (uint64_t)0;
	zid = (uint32_t)0;
	uid = (uint32_t)0;
	return 0;
}

int RoleDBSnsSimple_s::ResumeInit() {
	return 0;
}

void RoleDBSnsSimple_s::write_to_pbmsg(::proto_ff::RoleDBSnsSimple & msg) const {
	msg.set_cid((uint64_t)cid);
	msg.set_zid((uint32_t)zid);
	msg.set_uid((uint32_t)uid);
	::proto_ff::RoleDBBaseData* temp_base = msg.mutable_base();
	base.write_to_pbmsg(*temp_base);
}

void RoleDBSnsSimple_s::read_from_pbmsg(const ::proto_ff::RoleDBSnsSimple & msg) {
	cid = msg.cid();
	zid = msg.zid();
	uid = msg.uid();
	const ::proto_ff::RoleDBBaseData & temp_base = msg.base();
	base.read_from_pbmsg(temp_base);
}

MyFriendInfo_s::MyFriendInfo_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int MyFriendInfo_s::CreateInit() {
	return 0;
}

int MyFriendInfo_s::ResumeInit() {
	return 0;
}

void MyFriendInfo_s::write_to_pbmsg(::proto_ff::MyFriendInfo & msg) const {
}

void MyFriendInfo_s::read_from_pbmsg(const ::proto_ff::MyFriendInfo & msg) {
}

RoleDBSnsDetail_s::RoleDBSnsDetail_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int RoleDBSnsDetail_s::CreateInit() {
	cid = (uint64_t)0;
	zid = (uint32_t)0;
	uid = (uint32_t)0;
	return 0;
}

int RoleDBSnsDetail_s::ResumeInit() {
	return 0;
}

void RoleDBSnsDetail_s::write_to_pbmsg(::proto_ff::RoleDBSnsDetail & msg) const {
	msg.set_cid((uint64_t)cid);
	msg.set_zid((uint32_t)zid);
	msg.set_uid((uint32_t)uid);
	::proto_ff::MyFriendInfo* temp_friend_info = msg.mutable_friend_info();
	friend_info.write_to_pbmsg(*temp_friend_info);
}

void RoleDBSnsDetail_s::read_from_pbmsg(const ::proto_ff::RoleDBSnsDetail & msg) {
	cid = msg.cid();
	zid = msg.zid();
	uid = msg.uid();
	const ::proto_ff::MyFriendInfo & temp_friend_info = msg.friend_info();
	friend_info.read_from_pbmsg(temp_friend_info);
}

RoleEnterSceneData_s::RoleEnterSceneData_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int RoleEnterSceneData_s::CreateInit() {
	cid = (uint64_t)0;
	zid = (uint32_t)0;
	uid = (uint32_t)0;
	return 0;
}

int RoleEnterSceneData_s::ResumeInit() {
	return 0;
}

void RoleEnterSceneData_s::write_to_pbmsg(::proto_ff::RoleEnterSceneData & msg) const {
	msg.set_cid((uint64_t)cid);
	msg.set_zid((uint32_t)zid);
	msg.set_uid((uint32_t)uid);
	::proto_ff::RoleDBBaseData* temp_base = msg.mutable_base();
	base.write_to_pbmsg(*temp_base);
	::proto_ff::AttrDBData* temp_attr = msg.mutable_attr();
	attr.write_to_pbmsg(*temp_attr);
}

void RoleEnterSceneData_s::read_from_pbmsg(const ::proto_ff::RoleEnterSceneData & msg) {
	cid = msg.cid();
	zid = msg.zid();
	uid = msg.uid();
	const ::proto_ff::RoleDBBaseData & temp_base = msg.base();
	base.read_from_pbmsg(temp_base);
	const ::proto_ff::AttrDBData & temp_attr = msg.attr();
	attr.read_from_pbmsg(temp_attr);
}

RoleDBName_s::RoleDBName_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int RoleDBName_s::CreateInit() {
	return 0;
}

int RoleDBName_s::ResumeInit() {
	return 0;
}

void RoleDBName_s::write_to_pbmsg(::proto_ff::RoleDBName & msg) const {
	msg.set_name(name.data());
}

void RoleDBName_s::read_from_pbmsg(const ::proto_ff::RoleDBName & msg) {
	name = msg.name();
}

tbSnsGlobal_s::tbSnsGlobal_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int tbSnsGlobal_s::CreateInit() {
	id = (uint64_t)0;
	return 0;
}

int tbSnsGlobal_s::ResumeInit() {
	return 0;
}

void tbSnsGlobal_s::write_to_pbmsg(::proto_ff::tbSnsGlobal & msg) const {
	msg.set_id((uint64_t)id);
	msg.set_data(data.data());
}

void tbSnsGlobal_s::read_from_pbmsg(const ::proto_ff::tbSnsGlobal & msg) {
	id = msg.id();
	data = msg.data();
}

tbSnsTeam_s::tbSnsTeam_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int tbSnsTeam_s::CreateInit() {
	team_id = (uint64_t)0;
	return 0;
}

int tbSnsTeam_s::ResumeInit() {
	return 0;
}

void tbSnsTeam_s::write_to_pbmsg(::proto_ff::tbSnsTeam & msg) const {
	msg.set_team_id((uint64_t)team_id);
}

void tbSnsTeam_s::read_from_pbmsg(const ::proto_ff::tbSnsTeam & msg) {
	team_id = msg.team_id();
}

}
