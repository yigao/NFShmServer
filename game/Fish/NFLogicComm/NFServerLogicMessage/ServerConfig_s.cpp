#include "ServerConfig_s.h"

namespace proto_ff_s {

WorldExternalConfig_s::WorldExternalConfig_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int WorldExternalConfig_s::CreateInit() {
	TokenTimeCheck = (bool)0;
	WhiteListState = (bool)0;
	MaxRegisterNum = (uint32_t)0;
	StartQueueNum = (uint32_t)0;
	MaxQueueNum = (uint32_t)0;
	return 0;
}

int WorldExternalConfig_s::ResumeInit() {
	return 0;
}

void WorldExternalConfig_s::write_to_pbmsg(::proto_ff::WorldExternalConfig & msg) const {
	msg.set_tokentimecheck((bool)TokenTimeCheck);
	msg.set_whiteliststate((bool)WhiteListState);
	msg.set_maxregisternum((uint32_t)MaxRegisterNum);
	for(int32_t i = 0; i < (int32_t)WhiteList.size(); ++i) {
		msg.add_whitelist((uint64_t)WhiteList[i]);
	}
	msg.set_startqueuenum((uint32_t)StartQueueNum);
	msg.set_maxqueuenum((uint32_t)MaxQueueNum);
}

void WorldExternalConfig_s::read_from_pbmsg(const ::proto_ff::WorldExternalConfig & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct WorldExternalConfig_s));
	TokenTimeCheck = msg.tokentimecheck();
	WhiteListState = msg.whiteliststate();
	MaxRegisterNum = msg.maxregisternum();
	WhiteList.resize((int)msg.whitelist_size() > (int)WhiteList.max_size() ? WhiteList.max_size() : msg.whitelist_size());
	for(int32_t i = 0; i < (int32_t)WhiteList.size(); ++i) {
		WhiteList[i] = msg.whitelist(i);
	}
	StartQueueNum = msg.startqueuenum();
	MaxQueueNum = msg.maxqueuenum();
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

}