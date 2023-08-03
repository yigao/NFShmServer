#include "Com_s.h"

namespace proto_ff_s {

EmptyMessage_s::EmptyMessage_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int EmptyMessage_s::CreateInit() {
	return 0;
}

int EmptyMessage_s::ResumeInit() {
	return 0;
}

void EmptyMessage_s::write_to_pbmsg(::proto_ff::EmptyMessage & msg) const {
}

void EmptyMessage_s::read_from_pbmsg(const ::proto_ff::EmptyMessage & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct EmptyMessage_s));
}

ComPair_s::ComPair_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int ComPair_s::CreateInit() {
	key = (uint32_t)0;
	value = (uint32_t)0;
	return 0;
}

int ComPair_s::ResumeInit() {
	return 0;
}

void ComPair_s::write_to_pbmsg(::proto_ff::ComPair & msg) const {
	msg.set_key((uint32_t)key);
	msg.set_value((uint32_t)value);
}

void ComPair_s::read_from_pbmsg(const ::proto_ff::ComPair & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct ComPair_s));
	key = msg.key();
	value = msg.value();
}

ComPair64_s::ComPair64_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int ComPair64_s::CreateInit() {
	key = (uint64_t)0;
	value = (uint64_t)0;
	return 0;
}

int ComPair64_s::ResumeInit() {
	return 0;
}

void ComPair64_s::write_to_pbmsg(::proto_ff::ComPair64 & msg) const {
	msg.set_key((uint64_t)key);
	msg.set_value((uint64_t)value);
}

void ComPair64_s::read_from_pbmsg(const ::proto_ff::ComPair64 & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct ComPair64_s));
	key = msg.key();
	value = msg.value();
}

ComPairBool_s::ComPairBool_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int ComPairBool_s::CreateInit() {
	key = (uint32_t)0;
	value = (bool)0;
	return 0;
}

int ComPairBool_s::ResumeInit() {
	return 0;
}

void ComPairBool_s::write_to_pbmsg(::proto_ff::ComPairBool & msg) const {
	msg.set_key((uint32_t)key);
	msg.set_value((bool)value);
}

void ComPairBool_s::read_from_pbmsg(const ::proto_ff::ComPairBool & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct ComPairBool_s));
	key = msg.key();
	value = msg.value();
}

ComItem_s::ComItem_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int ComItem_s::CreateInit() {
	item_id = (uint64_t)0;
	item_num = (uint64_t)0;
	return 0;
}

int ComItem_s::ResumeInit() {
	return 0;
}

void ComItem_s::write_to_pbmsg(::proto_ff::ComItem & msg) const {
	msg.set_item_id((uint64_t)item_id);
	msg.set_item_num((uint64_t)item_num);
}

void ComItem_s::read_from_pbmsg(const ::proto_ff::ComItem & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct ComItem_s));
	item_id = msg.item_id();
	item_num = msg.item_num();
}

ComItemWithType_s::ComItemWithType_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int ComItemWithType_s::CreateInit() {
	item_id = (uint64_t)0;
	item_num = (uint64_t)0;
	type = (uint32_t)0;
	return 0;
}

int ComItemWithType_s::ResumeInit() {
	return 0;
}

void ComItemWithType_s::write_to_pbmsg(::proto_ff::ComItemWithType & msg) const {
	msg.set_item_id((uint64_t)item_id);
	msg.set_item_num((uint64_t)item_num);
	msg.set_type((uint32_t)type);
}

void ComItemWithType_s::read_from_pbmsg(const ::proto_ff::ComItemWithType & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct ComItemWithType_s));
	item_id = msg.item_id();
	item_num = msg.item_num();
	type = msg.type();
}

Vector3PB_s::Vector3PB_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Vector3PB_s::CreateInit() {
	x = (float)0;
	y = (float)0;
	z = (float)0;
	return 0;
}

int Vector3PB_s::ResumeInit() {
	return 0;
}

void Vector3PB_s::write_to_pbmsg(::proto_ff::Vector3PB & msg) const {
	msg.set_x((float)x);
	msg.set_y((float)y);
	msg.set_z((float)z);
}

void Vector3PB_s::read_from_pbmsg(const ::proto_ff::Vector3PB & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Vector3PB_s));
	x = msg.x();
	y = msg.y();
	z = msg.z();
}

Vector2PB_s::Vector2PB_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Vector2PB_s::CreateInit() {
	x = (float)0;
	y = (float)0;
	return 0;
}

int Vector2PB_s::ResumeInit() {
	return 0;
}

void Vector2PB_s::write_to_pbmsg(::proto_ff::Vector2PB & msg) const {
	msg.set_x((float)x);
	msg.set_y((float)y);
}

void Vector2PB_s::read_from_pbmsg(const ::proto_ff::Vector2PB & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Vector2PB_s));
	x = msg.x();
	y = msg.y();
}

Attr64_s::Attr64_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Attr64_s::CreateInit() {
	id = (uint32_t)0;
	value = (int64_t)0;
	return 0;
}

int Attr64_s::ResumeInit() {
	return 0;
}

void Attr64_s::write_to_pbmsg(::proto_ff::Attr64 & msg) const {
	msg.set_id((uint32_t)id);
	msg.set_value((int64_t)value);
}

void Attr64_s::read_from_pbmsg(const ::proto_ff::Attr64 & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Attr64_s));
	id = msg.id();
	value = msg.value();
}

Proto_UserLoginExternalData_s::Proto_UserLoginExternalData_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Proto_UserLoginExternalData_s::CreateInit() {
	aread_id = (uint32_t)0;
	agent_id = (uint32_t)0;
	channel_id = (uint32_t)0;
	referral_code = (uint64_t)0;
	return 0;
}

int Proto_UserLoginExternalData_s::ResumeInit() {
	return 0;
}

void Proto_UserLoginExternalData_s::write_to_pbmsg(::proto_ff::Proto_UserLoginExternalData & msg) const {
	msg.set_aread_id((uint32_t)aread_id);
	msg.set_agent_id((uint32_t)agent_id);
	msg.set_channel_id((uint32_t)channel_id);
	msg.set_referral_code((uint64_t)referral_code);
	msg.set_platform_os((const char*)platform_os.data());
	msg.set_country((const char*)country.data());
	msg.set_province((const char*)province.data());
	msg.set_city((const char*)city.data());
	msg.set_phone_mode((const char*)phone_mode.data());
	msg.set_device_id((const char*)device_id.data());
}

void Proto_UserLoginExternalData_s::read_from_pbmsg(const ::proto_ff::Proto_UserLoginExternalData & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Proto_UserLoginExternalData_s));
	aread_id = msg.aread_id();
	agent_id = msg.agent_id();
	channel_id = msg.channel_id();
	referral_code = msg.referral_code();
	platform_os = msg.platform_os();
	country = msg.country();
	province = msg.province();
	city = msg.city();
	phone_mode = msg.phone_mode();
	device_id = msg.device_id();
}

Proto_UserDetailCommonData_s::Proto_UserDetailCommonData_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Proto_UserDetailCommonData_s::CreateInit() {
	face_id = (uint32_t)0;
	gender = (uint32_t)0;
	jetton = (uint64_t)0;
	bank_jetton = (uint64_t)0;
	agent_id = (uint64_t)0;
	phonenum = (uint64_t)0;
	return 0;
}

int Proto_UserDetailCommonData_s::ResumeInit() {
	return 0;
}

void Proto_UserDetailCommonData_s::write_to_pbmsg(::proto_ff::Proto_UserDetailCommonData & msg) const {
	msg.set_nick_name((const char*)nick_name.data());
	msg.set_face_id((uint32_t)face_id);
	msg.set_gender((uint32_t)gender);
	msg.set_jetton((uint64_t)jetton);
	msg.set_bank_jetton((uint64_t)bank_jetton);
	msg.set_agent_id((uint64_t)agent_id);
	msg.set_phonenum((uint64_t)phonenum);
}

void Proto_UserDetailCommonData_s::read_from_pbmsg(const ::proto_ff::Proto_UserDetailCommonData & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Proto_UserDetailCommonData_s));
	nick_name = msg.nick_name();
	face_id = msg.face_id();
	gender = msg.gender();
	jetton = msg.jetton();
	bank_jetton = msg.bank_jetton();
	agent_id = msg.agent_id();
	phonenum = msg.phonenum();
}

Proto_LTSSyncData_s::Proto_LTSSyncData_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Proto_LTSSyncData_s::CreateInit() {
	create_player_db_data = (bool)0;
	face_id = (uint32_t)0;
	return 0;
}

int Proto_LTSSyncData_s::ResumeInit() {
	return 0;
}

void Proto_LTSSyncData_s::write_to_pbmsg(::proto_ff::Proto_LTSSyncData & msg) const {
	msg.set_create_player_db_data((bool)create_player_db_data);
	msg.set_nick_name((const char*)nick_name.data());
	msg.set_face_id((uint32_t)face_id);
}

void Proto_LTSSyncData_s::read_from_pbmsg(const ::proto_ff::Proto_LTSSyncData & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Proto_LTSSyncData_s));
	create_player_db_data = msg.create_player_db_data();
	nick_name = msg.nick_name();
	face_id = msg.face_id();
}

tbGiveBankJetton_s::tbGiveBankJetton_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int tbGiveBankJetton_s::CreateInit() {
	id = (uint64_t)0;
	user_id = (uint64_t)0;
	give_user_id = (uint64_t)0;
	give_jetton = (uint64_t)0;
	create_time = (uint64_t)0;
	return 0;
}

int tbGiveBankJetton_s::ResumeInit() {
	return 0;
}

void tbGiveBankJetton_s::write_to_pbmsg(::proto_ff::tbGiveBankJetton & msg) const {
	msg.set_id((uint64_t)id);
	msg.set_user_id((uint64_t)user_id);
	msg.set_user_name((const char*)user_name.data());
	msg.set_give_user_id((uint64_t)give_user_id);
	msg.set_give_user_name((const char*)give_user_name.data());
	msg.set_give_jetton((uint64_t)give_jetton);
	msg.set_create_time((uint64_t)create_time);
}

void tbGiveBankJetton_s::read_from_pbmsg(const ::proto_ff::tbGiveBankJetton & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct tbGiveBankJetton_s));
	id = msg.id();
	user_id = msg.user_id();
	user_name = msg.user_name();
	give_user_id = msg.give_user_id();
	give_user_name = msg.give_user_name();
	give_jetton = msg.give_jetton();
	create_time = msg.create_time();
}

Proto_UserSimpleData_s::Proto_UserSimpleData_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int Proto_UserSimpleData_s::CreateInit() {
	userid = (uint64_t)0;
	face = (uint32_t)0;
	gender = (uint32_t)0;
	age = (uint32_t)0;
	return 0;
}

int Proto_UserSimpleData_s::ResumeInit() {
	return 0;
}

void Proto_UserSimpleData_s::write_to_pbmsg(::proto_ff::Proto_UserSimpleData & msg) const {
	msg.set_userid((uint64_t)userid);
	msg.set_nickname((const char*)nickname.data());
	msg.set_face((uint32_t)face);
	msg.set_gender((uint32_t)gender);
	msg.set_age((uint32_t)age);
}

void Proto_UserSimpleData_s::read_from_pbmsg(const ::proto_ff::Proto_UserSimpleData & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct Proto_UserSimpleData_s));
	userid = msg.userid();
	nickname = msg.nickname();
	face = msg.face();
	gender = msg.gender();
	age = msg.age();
}

GamePlayerDetailData_s::GamePlayerDetailData_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int GamePlayerDetailData_s::CreateInit() {
	player_id = (uint64_t)0;
	cur_money = (int64_t)0;
	vip_level = (uint32_t)0;
	sex = (uint32_t)0;
	chair_id = (int32_t)0;
	face = (uint32_t)0;
	isRobot = (bool)0;
	return 0;
}

int GamePlayerDetailData_s::ResumeInit() {
	return 0;
}

void GamePlayerDetailData_s::write_to_pbmsg(::proto_ff::GamePlayerDetailData & msg) const {
	msg.set_player_id((uint64_t)player_id);
	msg.set_cur_money((int64_t)cur_money);
	msg.set_vip_level((uint32_t)vip_level);
	msg.set_sex((uint32_t)sex);
	msg.set_chair_id((int32_t)chair_id);
	msg.set_nick_name((const char*)nick_name.data());
	msg.set_face((uint32_t)face);
	msg.set_isrobot((bool)isRobot);
}

void GamePlayerDetailData_s::read_from_pbmsg(const ::proto_ff::GamePlayerDetailData & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct GamePlayerDetailData_s));
	player_id = msg.player_id();
	cur_money = msg.cur_money();
	vip_level = msg.vip_level();
	sex = msg.sex();
	chair_id = msg.chair_id();
	nick_name = msg.nick_name();
	face = msg.face();
	isRobot = msg.isrobot();
}

GamePlayerWealthData_s::GamePlayerWealthData_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int GamePlayerWealthData_s::CreateInit() {
	player_id = (uint64_t)0;
	recharge = (int64_t)0;
	total_lost = (int64_t)0;
	total_win = (int64_t)0;
	this_game_lost = (int64_t)0;
	this_game_win = (int64_t)0;
	return 0;
}

int GamePlayerWealthData_s::ResumeInit() {
	return 0;
}

void GamePlayerWealthData_s::write_to_pbmsg(::proto_ff::GamePlayerWealthData & msg) const {
	msg.set_player_id((uint64_t)player_id);
	msg.set_recharge((int64_t)recharge);
	msg.set_total_lost((int64_t)total_lost);
	msg.set_total_win((int64_t)total_win);
	msg.set_this_game_lost((int64_t)this_game_lost);
	msg.set_this_game_win((int64_t)this_game_win);
}

void GamePlayerWealthData_s::read_from_pbmsg(const ::proto_ff::GamePlayerWealthData & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct GamePlayerWealthData_s));
	player_id = msg.player_id();
	recharge = msg.recharge();
	total_lost = msg.total_lost();
	total_win = msg.total_win();
	this_game_lost = msg.this_game_lost();
	this_game_win = msg.this_game_win();
}

GamePlayerAchievementData_s::GamePlayerAchievementData_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int GamePlayerAchievementData_s::CreateInit() {
	cur_ach = (uint64_t)0;
	cur_fee = (uint64_t)0;
	return 0;
}

int GamePlayerAchievementData_s::ResumeInit() {
	return 0;
}

void GamePlayerAchievementData_s::write_to_pbmsg(::proto_ff::GamePlayerAchievementData & msg) const {
	msg.set_cur_ach((uint64_t)cur_ach);
	msg.set_cur_fee((uint64_t)cur_fee);
}

void GamePlayerAchievementData_s::read_from_pbmsg(const ::proto_ff::GamePlayerAchievementData & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct GamePlayerAchievementData_s));
	cur_ach = msg.cur_ach();
	cur_fee = msg.cur_fee();
}

GameRoomStat_s::GameRoomStat_s() {
	if (EN_OBJ_MODE_INIT == NFShmMgr::Instance()->GetCreateMode()) {
		CreateInit();
	} else {
		ResumeInit();
	}
}

int GameRoomStat_s::CreateInit() {
	cur_fee = (uint64_t)0;
	cur_pour = (uint64_t)0;
	cur_win = (int64_t)0;
	return 0;
}

int GameRoomStat_s::ResumeInit() {
	return 0;
}

void GameRoomStat_s::write_to_pbmsg(::proto_ff::GameRoomStat & msg) const {
	msg.set_cur_fee((uint64_t)cur_fee);
	msg.set_cur_pour((uint64_t)cur_pour);
	msg.set_cur_win((int64_t)cur_win);
}

void GameRoomStat_s::read_from_pbmsg(const ::proto_ff::GameRoomStat & msg) {
	//dont't use memset, the class maybe has virtual //memset(this, 0, sizeof(struct GameRoomStat_s));
	cur_fee = msg.cur_fee();
	cur_pour = msg.cur_pour();
	cur_win = msg.cur_win();
}

}