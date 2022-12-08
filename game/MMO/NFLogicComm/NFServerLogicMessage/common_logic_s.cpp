#include "common_logic_s.h"

namespace proto_ff_s {

PacketMsg_s::PacketMsg_s() {
	CreateInit();
}

int PacketMsg_s::CreateInit() {
	cmd = (uint32_t)0;
	serverType = (uint32_t)0;
	upper_limit = (uint32_t)0;
	min_interval = (uint32_t)0;
	control_time = (uint32_t)0;
	return 0;
}

int PacketMsg_s::ResumeInit() {
	return 0;
}

void PacketMsg_s::write_to_pbmsg(::proto_ff::PacketMsg & msg) const {
	msg.set_cmd((uint32_t)cmd);
	msg.set_servertype((uint32_t)serverType);
	msg.set_upper_limit((uint32_t)upper_limit);
	msg.set_min_interval((uint32_t)min_interval);
	msg.set_control_time((uint32_t)control_time);
}

void PacketMsg_s::read_from_pbmsg(const ::proto_ff::PacketMsg & msg) {
	cmd = msg.cmd();
	serverType = msg.servertype();
	upper_limit = msg.upper_limit();
	min_interval = msg.min_interval();
	control_time = msg.control_time();
}

ServerPacketMsg_s::ServerPacketMsg_s() {
	CreateInit();
}

int ServerPacketMsg_s::CreateInit() {
	return 0;
}

int ServerPacketMsg_s::ResumeInit() {
	return 0;
}

void ServerPacketMsg_s::write_to_pbmsg(::proto_ff::ServerPacketMsg & msg) const {
	for(int32_t i = 0; i < (int32_t)PacketMsg.size(); ++i) {
		::proto_ff::PacketMsg* temp_packetmsg = msg.add_packetmsg();
		PacketMsg[i].write_to_pbmsg(*temp_packetmsg);
	}
}

void ServerPacketMsg_s::read_from_pbmsg(const ::proto_ff::ServerPacketMsg & msg) {
	PacketMsg.resize(msg.packetmsg_size());
	for(int32_t i = 0; i < (int32_t)PacketMsg.size(); ++i) {
		const ::proto_ff::PacketMsg & temp_packetmsg = msg.packetmsg(i);
		PacketMsg[i].read_from_pbmsg(temp_packetmsg);
	}
}

WorldExternalConfig_s::WorldExternalConfig_s() {
	CreateInit();
}

int WorldExternalConfig_s::CreateInit() {
	TokenTimeCheck = (bool)0;
	WhiteListState = (bool)0;
	MaxRegisterNum = (uint32_t)0;
	return 0;
}

int WorldExternalConfig_s::ResumeInit() {
	return 0;
}

void WorldExternalConfig_s::write_to_pbmsg(::proto_ff::WorldExternalConfig & msg) const {
	msg.set_tokentimecheck((bool)TokenTimeCheck);
	msg.set_whiteliststate((bool)WhiteListState);
	msg.set_maxregisternum((uint32_t)MaxRegisterNum);
}

void WorldExternalConfig_s::read_from_pbmsg(const ::proto_ff::WorldExternalConfig & msg) {
	TokenTimeCheck = msg.tokentimecheck();
	WhiteListState = msg.whiteliststate();
	MaxRegisterNum = msg.maxregisternum();
}

GameExternalConfig_s::GameExternalConfig_s() {
	CreateInit();
}

int GameExternalConfig_s::CreateInit() {
	return 0;
}

int GameExternalConfig_s::ResumeInit() {
	return 0;
}

void GameExternalConfig_s::write_to_pbmsg(::proto_ff::GameExternalConfig & msg) const {
	for(int32_t i = 0; i < (int32_t)map.size(); ++i) {
		msg.add_map((uint64_t)map[i]);
	}
}

void GameExternalConfig_s::read_from_pbmsg(const ::proto_ff::GameExternalConfig & msg) {
	map.resize(msg.map_size());
	for(int32_t i = 0; i < (int32_t)map.size(); ++i) {
		map[i] = msg.map(i);
	}
}

MapPosInfo_s::MapPosInfo_s() {
	CreateInit();
}

int MapPosInfo_s::CreateInit() {
	x = (double)0;
	y = (double)0;
	z = (double)0;
	return 0;
}

int MapPosInfo_s::ResumeInit() {
	return 0;
}

void MapPosInfo_s::write_to_pbmsg(::proto_ff::MapPosInfo & msg) const {
	msg.set_x((double)x);
	msg.set_y((double)y);
	msg.set_z((double)z);
}

void MapPosInfo_s::read_from_pbmsg(const ::proto_ff::MapPosInfo & msg) {
	x = msg.x();
	y = msg.y();
	z = msg.z();
}

MapJsonConfigObjsPos_s::MapJsonConfigObjsPos_s() {
	CreateInit();
}

int MapJsonConfigObjsPos_s::CreateInit() {
	rot = (double)0;
	return 0;
}

int MapJsonConfigObjsPos_s::ResumeInit() {
	return 0;
}

void MapJsonConfigObjsPos_s::write_to_pbmsg(::proto_ff::MapJsonConfigObjsPos & msg) const {
	::proto_ff::MapPosInfo* temp_pos = msg.mutable_pos();
	pos.write_to_pbmsg(*temp_pos);
	msg.set_rot((double)rot);
}

void MapJsonConfigObjsPos_s::read_from_pbmsg(const ::proto_ff::MapJsonConfigObjsPos & msg) {
	const ::proto_ff::MapPosInfo & temp_pos = msg.pos();
	pos.read_from_pbmsg(temp_pos);
	rot = msg.rot();
}

MapJsonConfigObjs_s::MapJsonConfigObjs_s() {
	CreateInit();
}

int MapJsonConfigObjs_s::CreateInit() {
	id = (uint64_t)0;
	return 0;
}

int MapJsonConfigObjs_s::ResumeInit() {
	return 0;
}

void MapJsonConfigObjs_s::write_to_pbmsg(::proto_ff::MapJsonConfigObjs & msg) const {
	msg.set_id((uint64_t)id);
	for(int32_t i = 0; i < (int32_t)pos.size(); ++i) {
		::proto_ff::MapJsonConfigObjsPos* temp_pos = msg.add_pos();
		pos[i].write_to_pbmsg(*temp_pos);
	}
}

void MapJsonConfigObjs_s::read_from_pbmsg(const ::proto_ff::MapJsonConfigObjs & msg) {
	id = msg.id();
	pos.resize(msg.pos_size());
	for(int32_t i = 0; i < (int32_t)pos.size(); ++i) {
		const ::proto_ff::MapJsonConfigObjsPos & temp_pos = msg.pos(i);
		pos[i].read_from_pbmsg(temp_pos);
	}
}

MapJsonConfigAreaDetail_s::MapJsonConfigAreaDetail_s() {
	CreateInit();
}

int MapJsonConfigAreaDetail_s::CreateInit() {
	radius = (double)0;
	return 0;
}

int MapJsonConfigAreaDetail_s::ResumeInit() {
	return 0;
}

void MapJsonConfigAreaDetail_s::write_to_pbmsg(::proto_ff::MapJsonConfigAreaDetail & msg) const {
	msg.set_radius((double)radius);
	::proto_ff::MapPosInfo* temp_pos = msg.mutable_pos();
	pos.write_to_pbmsg(*temp_pos);
}

void MapJsonConfigAreaDetail_s::read_from_pbmsg(const ::proto_ff::MapJsonConfigAreaDetail & msg) {
	radius = msg.radius();
	const ::proto_ff::MapPosInfo & temp_pos = msg.pos();
	pos.read_from_pbmsg(temp_pos);
}

MapJsonConfigArea_s::MapJsonConfigArea_s() {
	CreateInit();
}

int MapJsonConfigArea_s::CreateInit() {
	id = (uint64_t)0;
	return 0;
}

int MapJsonConfigArea_s::ResumeInit() {
	return 0;
}

void MapJsonConfigArea_s::write_to_pbmsg(::proto_ff::MapJsonConfigArea & msg) const {
	msg.set_id((uint64_t)id);
	for(int32_t i = 0; i < (int32_t)detail.size(); ++i) {
		::proto_ff::MapJsonConfigAreaDetail* temp_detail = msg.add_detail();
		detail[i].write_to_pbmsg(*temp_detail);
	}
}

void MapJsonConfigArea_s::read_from_pbmsg(const ::proto_ff::MapJsonConfigArea & msg) {
	id = msg.id();
	detail.resize(msg.detail_size());
	for(int32_t i = 0; i < (int32_t)detail.size(); ++i) {
		const ::proto_ff::MapJsonConfigAreaDetail & temp_detail = msg.detail(i);
		detail[i].read_from_pbmsg(temp_detail);
	}
}

MapJsonConfigPath_s::MapJsonConfigPath_s() {
	CreateInit();
}

int MapJsonConfigPath_s::CreateInit() {
	id = (uint64_t)0;
	return 0;
}

int MapJsonConfigPath_s::ResumeInit() {
	return 0;
}

void MapJsonConfigPath_s::write_to_pbmsg(::proto_ff::MapJsonConfigPath & msg) const {
	msg.set_id((uint64_t)id);
	for(int32_t i = 0; i < (int32_t)pos.size(); ++i) {
		::proto_ff::MapPosInfo* temp_pos = msg.add_pos();
		pos[i].write_to_pbmsg(*temp_pos);
	}
}

void MapJsonConfigPath_s::read_from_pbmsg(const ::proto_ff::MapJsonConfigPath & msg) {
	id = msg.id();
	pos.resize(msg.pos_size());
	for(int32_t i = 0; i < (int32_t)pos.size(); ++i) {
		const ::proto_ff::MapPosInfo & temp_pos = msg.pos(i);
		pos[i].read_from_pbmsg(temp_pos);
	}
}

MapJsonConfig_s::MapJsonConfig_s() {
	CreateInit();
}

int MapJsonConfig_s::CreateInit() {
	return 0;
}

int MapJsonConfig_s::ResumeInit() {
	return 0;
}

void MapJsonConfig_s::write_to_pbmsg(::proto_ff::MapJsonConfig & msg) const {
	for(int32_t i = 0; i < (int32_t)objs.size(); ++i) {
		::proto_ff::MapJsonConfigObjs* temp_objs = msg.add_objs();
		objs[i].write_to_pbmsg(*temp_objs);
	}
	for(int32_t i = 0; i < (int32_t)areas.size(); ++i) {
		::proto_ff::MapJsonConfigArea* temp_areas = msg.add_areas();
		areas[i].write_to_pbmsg(*temp_areas);
	}
	for(int32_t i = 0; i < (int32_t)paths.size(); ++i) {
		::proto_ff::MapJsonConfigPath* temp_paths = msg.add_paths();
		paths[i].write_to_pbmsg(*temp_paths);
	}
}

void MapJsonConfig_s::read_from_pbmsg(const ::proto_ff::MapJsonConfig & msg) {
	objs.resize(msg.objs_size());
	for(int32_t i = 0; i < (int32_t)objs.size(); ++i) {
		const ::proto_ff::MapJsonConfigObjs & temp_objs = msg.objs(i);
		objs[i].read_from_pbmsg(temp_objs);
	}
	areas.resize(msg.areas_size());
	for(int32_t i = 0; i < (int32_t)areas.size(); ++i) {
		const ::proto_ff::MapJsonConfigArea & temp_areas = msg.areas(i);
		areas[i].read_from_pbmsg(temp_areas);
	}
	paths.resize(msg.paths_size());
	for(int32_t i = 0; i < (int32_t)paths.size(); ++i) {
		const ::proto_ff::MapJsonConfigPath & temp_paths = msg.paths(i);
		paths[i].read_from_pbmsg(temp_paths);
	}
}

}