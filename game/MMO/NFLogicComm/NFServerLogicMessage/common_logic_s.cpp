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

}