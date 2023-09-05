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

GameExternalGame_s::GameExternalGame_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int GameExternalGame_s::CreateInit() {
	GameId = (uint32_t)0;
	return 0;
}

int GameExternalGame_s::ResumeInit() {
	return 0;
}

void GameExternalGame_s::write_to_pbmsg(::proto_ff::GameExternalGame & msg) const {
	msg.set_gameid((uint32_t)GameId);
	for(int32_t i = 0; i < (int32_t)RoomId.size(); ++i) {
		msg.add_roomid((uint32_t)RoomId[i]);
	}
}

void GameExternalGame_s::read_from_pbmsg(const ::proto_ff::GameExternalGame & msg) {
	GameId = msg.gameid();
	RoomId.resize((int)msg.roomid_size() > (int)RoomId.max_size() ? RoomId.max_size() : msg.roomid_size());
	for(int32_t i = 0; i < (int32_t)RoomId.size(); ++i) {
		RoomId[i] = msg.roomid(i);
	}
}

GameExternalConfig_s::GameExternalConfig_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int GameExternalConfig_s::CreateInit() {
	MaxDeskNunOneRoom = (uint32_t)0;
	return 0;
}

int GameExternalConfig_s::ResumeInit() {
	return 0;
}

void GameExternalConfig_s::write_to_pbmsg(::proto_ff::GameExternalConfig & msg) const {
	for(int32_t i = 0; i < (int32_t)Game.size(); ++i) {
		::proto_ff::GameExternalGame* temp_game = msg.add_game();
		Game[i].write_to_pbmsg(*temp_game);
	}
	msg.set_maxdesknunoneroom((uint32_t)MaxDeskNunOneRoom);
}

void GameExternalConfig_s::read_from_pbmsg(const ::proto_ff::GameExternalConfig & msg) {
	Game.resize((int)msg.game_size() > (int)Game.max_size() ? Game.max_size() : msg.game_size());
	for(int32_t i = 0; i < (int32_t)Game.size(); ++i) {
		const ::proto_ff::GameExternalGame & temp_game = msg.game(i);
		Game[i].read_from_pbmsg(temp_game);
	}
	MaxDeskNunOneRoom = msg.maxdesknunoneroom();
}

}
