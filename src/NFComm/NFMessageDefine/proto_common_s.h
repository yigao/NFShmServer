#pragma once

#include <stdint.h>
#include <NFComm/NFShmCore/NFSizeString.h>
#include <NFComm/NFShmCore/NFArray.h>
#include <NFComm/NFShmCore/NFSeqOP.h>
#include <NFComm/NFShmCore/NFShmMgr.h>
#include "proto_common.pb.h"
#include "proto_common_s.h"

namespace proto_ff_s {

	struct GameServerRoomInfo_s : public NFDescStoreSeqOP {
		GameServerRoomInfo_s();
		int CreateInit();
		int ResumeInit();
		uint32_t game_id;
		uint32_t room_id;
		NFSizeString<128> room_name;
		uint64_t enter_min;
		uint64_t enter_max;
		uint32_t online_count;
		uint32_t bus_id;
		uint32_t status;

		static void write_to_pbmsg(const struct GameServerRoomInfo_s & obj, ::proto_ff::GameServerRoomInfo & msg);
		static void read_from_pbmsg(const ::proto_ff::GameServerRoomInfo & msg, struct GameServerRoomInfo_s & obj);
		static ::proto_ff::GameServerRoomInfo* new_pbmsg(){ return new ::proto_ff::GameServerRoomInfo(); }
		static ::proto_ff::GameServerRoomInfo make_pbmsg(){ return ::proto_ff::GameServerRoomInfo(); }
	};
	typedef struct GameServerRoomInfo_s GameServerRoomInfo_t;

	struct tbServerMgr_s : public NFDescStoreSeqOP {
		tbServerMgr_s();
		int CreateInit();
		int ResumeInit();
		uint64_t id;
		NFSizeString<128> contract;
		NFSizeString<128> machine_addr;
		NFSizeString<128> ip;
		NFSizeString<128> bus_name;
		NFSizeString<128> server_desc;
		uint32_t cur_count;
		uint64_t last_login_time;
		uint64_t last_logout_time;
		uint64_t create_time;

		static void write_to_pbmsg(const struct tbServerMgr_s & obj, ::proto_ff::tbServerMgr & msg);
		static void read_from_pbmsg(const ::proto_ff::tbServerMgr & msg, struct tbServerMgr_s & obj);
		static ::proto_ff::tbServerMgr* new_pbmsg(){ return new ::proto_ff::tbServerMgr(); }
		static ::proto_ff::tbServerMgr make_pbmsg(){ return ::proto_ff::tbServerMgr(); }
	};
	typedef struct tbServerMgr_s tbServerMgr_t;

	struct tbContractMgr_s : public NFDescStoreSeqOP {
		tbContractMgr_s();
		int CreateInit();
		int ResumeInit();
		uint64_t id;
		NFSizeString<128> contract;
		NFSizeString<128> machine_addr;
		NFSizeString<128> ip;
		NFSizeString<128> server_desc;

		static void write_to_pbmsg(const struct tbContractMgr_s & obj, ::proto_ff::tbContractMgr & msg);
		static void read_from_pbmsg(const ::proto_ff::tbContractMgr & msg, struct tbContractMgr_s & obj);
		static ::proto_ff::tbContractMgr* new_pbmsg(){ return new ::proto_ff::tbContractMgr(); }
		static ::proto_ff::tbContractMgr make_pbmsg(){ return ::proto_ff::tbContractMgr(); }
	};
	typedef struct tbContractMgr_s tbContractMgr_t;

	struct tbAccountTable_s : public NFDescStoreSeqOP {
		tbAccountTable_s();
		int CreateInit();
		int ResumeInit();
		uint64_t player_id;
		NFSizeString<128> account;
		NFSizeString<128> password;
		uint32_t account_type;
		NFSizeString<128> device_id;
		uint64_t phonenum;
		uint64_t real_player_id;

		static void write_to_pbmsg(const struct tbAccountTable_s & obj, ::proto_ff::tbAccountTable & msg);
		static void read_from_pbmsg(const ::proto_ff::tbAccountTable & msg, struct tbAccountTable_s & obj);
		static ::proto_ff::tbAccountTable* new_pbmsg(){ return new ::proto_ff::tbAccountTable(); }
		static ::proto_ff::tbAccountTable make_pbmsg(){ return ::proto_ff::tbAccountTable(); }
	};
	typedef struct tbAccountTable_s tbAccountTable_t;

	struct ItemData_s : public NFDescStoreSeqOP {
		ItemData_s();
		int CreateInit();
		int ResumeInit();
		int32_t item_id;
		int32_t item_num;

		static void write_to_pbmsg(const struct ItemData_s & obj, ::proto_ff::ItemData & msg);
		static void read_from_pbmsg(const ::proto_ff::ItemData & msg, struct ItemData_s & obj);
		static ::proto_ff::ItemData* new_pbmsg(){ return new ::proto_ff::ItemData(); }
		static ::proto_ff::ItemData make_pbmsg(){ return ::proto_ff::ItemData(); }
	};
	typedef struct ItemData_s ItemData_t;

	struct SingleMailInfo_s : public NFDescStoreSeqOP {
		SingleMailInfo_s();
		int CreateInit();
		int ResumeInit();
		uint64_t id;
		uint32_t status;

		static void write_to_pbmsg(const struct SingleMailInfo_s & obj, ::proto_ff::SingleMailInfo & msg);
		static void read_from_pbmsg(const ::proto_ff::SingleMailInfo & msg, struct SingleMailInfo_s & obj);
		static ::proto_ff::SingleMailInfo* new_pbmsg(){ return new ::proto_ff::SingleMailInfo(); }
		static ::proto_ff::SingleMailInfo make_pbmsg(){ return ::proto_ff::SingleMailInfo(); }
	};
	typedef struct SingleMailInfo_s SingleMailInfo_t;

	struct UserSpecialMailData_s : public NFDescStoreSeqOP {
		UserSpecialMailData_s();
		int CreateInit();
		int ResumeInit();
		int32_t static_id;
		uint64_t time;

		static void write_to_pbmsg(const struct UserSpecialMailData_s & obj, ::proto_ff::UserSpecialMailData & msg);
		static void read_from_pbmsg(const ::proto_ff::UserSpecialMailData & msg, struct UserSpecialMailData_s & obj);
		static ::proto_ff::UserSpecialMailData* new_pbmsg(){ return new ::proto_ff::UserSpecialMailData(); }
		static ::proto_ff::UserSpecialMailData make_pbmsg(){ return ::proto_ff::UserSpecialMailData(); }
	};
	typedef struct UserSpecialMailData_s UserSpecialMailData_t;

	struct UserMailInfo_s : public NFDescStoreSeqOP {
		UserMailInfo_s();
		int CreateInit();
		int ResumeInit();
		NFArray<struct SingleMailInfo_s, 1000> simple_mail;
		NFArray<struct UserSpecialMailData_s, 100> receive_data;
		NFArray<uint64_t, 100> del_role_mail;

		static void write_to_pbmsg(const struct UserMailInfo_s & obj, ::proto_ff::UserMailInfo & msg);
		static void read_from_pbmsg(const ::proto_ff::UserMailInfo & msg, struct UserMailInfo_s & obj);
		static ::proto_ff::UserMailInfo* new_pbmsg(){ return new ::proto_ff::UserMailInfo(); }
		static ::proto_ff::UserMailInfo make_pbmsg(){ return ::proto_ff::UserMailInfo(); }
	};
	typedef struct UserMailInfo_s UserMailInfo_t;

	struct tbUserMailInfo_s : public NFDescStoreSeqOP {
		tbUserMailInfo_s();
		int CreateInit();
		int ResumeInit();
		uint64_t user_id;
		struct UserMailInfo_s base_info;

		static void write_to_pbmsg(const struct tbUserMailInfo_s & obj, ::proto_ff::tbUserMailInfo & msg);
		static void read_from_pbmsg(const ::proto_ff::tbUserMailInfo & msg, struct tbUserMailInfo_s & obj);
		static ::proto_ff::tbUserMailInfo* new_pbmsg(){ return new ::proto_ff::tbUserMailInfo(); }
		static ::proto_ff::tbUserMailInfo make_pbmsg(){ return ::proto_ff::tbUserMailInfo(); }
	};
	typedef struct tbUserMailInfo_s tbUserMailInfo_t;

	struct tbUserMailDetail_s : public NFDescStoreSeqOP {
		tbUserMailDetail_s();
		int CreateInit();
		int ResumeInit();
		uint64_t id;
		uint64_t user_id;
		NFSizeString<32> send_name;
		int32_t static_id;
		NFSizeString<1600> content;
		NFSizeString<64> title;
		uint64_t send_time;
		int64_t add_gold;

		static void write_to_pbmsg(const struct tbUserMailDetail_s & obj, ::proto_ff::tbUserMailDetail & msg);
		static void read_from_pbmsg(const ::proto_ff::tbUserMailDetail & msg, struct tbUserMailDetail_s & obj);
		static ::proto_ff::tbUserMailDetail* new_pbmsg(){ return new ::proto_ff::tbUserMailDetail(); }
		static ::proto_ff::tbUserMailDetail make_pbmsg(){ return ::proto_ff::tbUserMailDetail(); }
	};
	typedef struct tbUserMailDetail_s tbUserMailDetail_t;

	struct UserMailDetailInfo_s : public NFDescStoreSeqOP {
		UserMailDetailInfo_s();
		int CreateInit();
		int ResumeInit();
		NFArray<struct tbUserMailDetail_s, 50> simple_mail;

		static void write_to_pbmsg(const struct UserMailDetailInfo_s & obj, ::proto_ff::UserMailDetailInfo & msg);
		static void read_from_pbmsg(const ::proto_ff::UserMailDetailInfo & msg, struct UserMailDetailInfo_s & obj);
		static ::proto_ff::UserMailDetailInfo* new_pbmsg(){ return new ::proto_ff::UserMailDetailInfo(); }
		static ::proto_ff::UserMailDetailInfo make_pbmsg(){ return ::proto_ff::UserMailDetailInfo(); }
	};
	typedef struct UserMailDetailInfo_s UserMailDetailInfo_t;

	struct tbGiveBankJetton_s : public NFDescStoreSeqOP {
		tbGiveBankJetton_s();
		int CreateInit();
		int ResumeInit();
		uint64_t id;
		uint64_t user_id;
		NFSizeString<64> user_name;
		uint64_t user_vip_level;
		uint64_t give_user_id;
		NFSizeString<64> give_user_name;
		uint64_t give_jetton;
		uint32_t give_user_vip_level;
		uint32_t status;
		uint64_t create_time;

		static void write_to_pbmsg(const struct tbGiveBankJetton_s & obj, ::proto_ff::tbGiveBankJetton & msg);
		static void read_from_pbmsg(const ::proto_ff::tbGiveBankJetton & msg, struct tbGiveBankJetton_s & obj);
		static ::proto_ff::tbGiveBankJetton* new_pbmsg(){ return new ::proto_ff::tbGiveBankJetton(); }
		static ::proto_ff::tbGiveBankJetton make_pbmsg(){ return ::proto_ff::tbGiveBankJetton(); }
	};
	typedef struct tbGiveBankJetton_s tbGiveBankJetton_t;

	struct UserMiscData_s : public NFDescStoreSeqOP {
		UserMiscData_s();
		int CreateInit();
		int ResumeInit();
		uint64_t tmp_phone_num;
		uint32_t tmp_auth_code;
		uint64_t auth_code_stamp;
		int32_t tmp_code_type;
		bool tmp_code_success;
		int32_t tmp_redeemcard_recharge_count;

		static void write_to_pbmsg(const struct UserMiscData_s & obj, ::proto_ff::UserMiscData & msg);
		static void read_from_pbmsg(const ::proto_ff::UserMiscData & msg, struct UserMiscData_s & obj);
		static ::proto_ff::UserMiscData* new_pbmsg(){ return new ::proto_ff::UserMiscData(); }
		static ::proto_ff::UserMiscData make_pbmsg(){ return ::proto_ff::UserMiscData(); }
	};
	typedef struct UserMiscData_s UserMiscData_t;

	struct tbUserDetailData_s : public NFDescStoreSeqOP {
		tbUserDetailData_s();
		int CreateInit();
		int ResumeInit();
		uint64_t userid;
		NFSizeString<64> nickname;
		uint32_t faceid;
		uint64_t regdate;
		uint32_t gender;
		uint32_t age;
		NFSizeString<64> email;
		uint64_t phonenum;
		uint64_t jetton;
		NFSizeString<64> country;
		NFSizeString<64> province;
		NFSizeString<64> city;
		bool isrobot;
		NFSizeString<64> bank_password;
		uint64_t bank_jetton;
		NFSizeString<64> ip;
		uint64_t last_login_time;
		uint64_t last_logout_time;
		uint32_t aread_id;
		uint32_t channel_id;
		NFSizeString<64> platform_os;
		NFSizeString<64> phone_model;
		bool first_recharge;
		uint64_t agent_id;
		uint64_t referrer_id;
		uint32_t vip_level;
		struct UserMiscData_s misc_data;
		bool online;
		uint32_t game_id;
		uint32_t room_id;
		int64_t all_win;
		uint64_t all_recharge;
		uint64_t all_give;
		uint64_t all_draw;
		int64_t today_win;
		uint64_t today_recharge;
		uint64_t today_give;
		uint64_t today_draw;
		int64_t week_win;
		uint64_t week_recharge;
		uint64_t week_give;
		uint64_t week_draw;
		int64_t month_win;
		uint64_t month_recharge;
		uint64_t month_give;
		uint64_t month_draw;
		uint32_t is_ban;
		uint32_t no_transfer;
		NFSizeString<64> reg_ip;
		NFSizeString<128> device_id;
		NFSizeString<128> reg_device_id;
		uint64_t show_userid;
		uint64_t all_vip_zhuanru;
		uint64_t today_vip_zhuanru;
		uint64_t week_vip_zhuanru;
		uint64_t month_vip_zhuanru;
		uint64_t all_vip_zhuanchu;
		uint64_t today_vip_zhuanchu;
		uint64_t week_vip_zhuanchu;
		uint64_t month_vip_zhuanchu;

		static void write_to_pbmsg(const struct tbUserDetailData_s & obj, ::proto_ff::tbUserDetailData & msg);
		static void read_from_pbmsg(const ::proto_ff::tbUserDetailData & msg, struct tbUserDetailData_s & obj);
		static ::proto_ff::tbUserDetailData* new_pbmsg(){ return new ::proto_ff::tbUserDetailData(); }
		static ::proto_ff::tbUserDetailData make_pbmsg(){ return ::proto_ff::tbUserDetailData(); }
	};
	typedef struct tbUserDetailData_s tbUserDetailData_t;

	struct UserSimpleMiscData_s : public NFDescStoreSeqOP {
		UserSimpleMiscData_s();
		int CreateInit();
		int ResumeInit();
		uint64_t last_valid_player_time;
		uint64_t last_pay_player_time;

		static void write_to_pbmsg(const struct UserSimpleMiscData_s & obj, ::proto_ff::UserSimpleMiscData & msg);
		static void read_from_pbmsg(const ::proto_ff::UserSimpleMiscData & msg, struct UserSimpleMiscData_s & obj);
		static ::proto_ff::UserSimpleMiscData* new_pbmsg(){ return new ::proto_ff::UserSimpleMiscData(); }
		static ::proto_ff::UserSimpleMiscData make_pbmsg(){ return ::proto_ff::UserSimpleMiscData(); }
	};
	typedef struct UserSimpleMiscData_s UserSimpleMiscData_t;

	struct tbUserSimpleData_s : public NFDescStoreSeqOP {
		tbUserSimpleData_s();
		int CreateInit();
		int ResumeInit();
		uint64_t userid;
		NFSizeString<64> nickname;
		uint32_t face;
		uint32_t gender;
		uint32_t age;
		uint64_t agentid;
		uint64_t create_time;
		bool is_robot;
		uint32_t agent_level;
		uint64_t ach_day;
		uint64_t ach_week;
		uint64_t ach_month;
		uint64_t ach_all;
		uint64_t ach_team_day;
		uint64_t ach_team_week;
		uint64_t ach_team_month;
		uint64_t ach_team_all;
		uint64_t team_user_num;
		uint64_t new_user_day;
		uint64_t activity_user_day;
		uint32_t getrate;
		uint32_t tax_getrate;
		uint32_t takemoney;
		uint32_t tax_takemoney;
		uint64_t all_takemoney;
		uint64_t all_fee;
		uint64_t show_userid;
		uint64_t vip_level;
		struct UserSimpleMiscData_s misc_data;

		static void write_to_pbmsg(const struct tbUserSimpleData_s & obj, ::proto_ff::tbUserSimpleData & msg);
		static void read_from_pbmsg(const ::proto_ff::tbUserSimpleData & msg, struct tbUserSimpleData_s & obj);
		static ::proto_ff::tbUserSimpleData* new_pbmsg(){ return new ::proto_ff::tbUserSimpleData(); }
		static ::proto_ff::tbUserSimpleData make_pbmsg(){ return ::proto_ff::tbUserSimpleData(); }
	};
	typedef struct tbUserSimpleData_s tbUserSimpleData_t;

	struct GamePlayerWealthData_s : public NFDescStoreSeqOP {
		GamePlayerWealthData_s();
		int CreateInit();
		int ResumeInit();
		uint64_t player_id;
		int64_t recharge;
		int64_t total_lost;
		int64_t total_win;
		int64_t this_game_lost;
		int64_t this_game_win;

		static void write_to_pbmsg(const struct GamePlayerWealthData_s & obj, ::proto_ff::GamePlayerWealthData & msg);
		static void read_from_pbmsg(const ::proto_ff::GamePlayerWealthData & msg, struct GamePlayerWealthData_s & obj);
		static ::proto_ff::GamePlayerWealthData* new_pbmsg(){ return new ::proto_ff::GamePlayerWealthData(); }
		static ::proto_ff::GamePlayerWealthData make_pbmsg(){ return ::proto_ff::GamePlayerWealthData(); }
	};
	typedef struct GamePlayerWealthData_s GamePlayerWealthData_t;

	struct GamePlayerDetailData_s : public NFDescStoreSeqOP {
		GamePlayerDetailData_s();
		int CreateInit();
		int ResumeInit();
		uint64_t player_id;
		int64_t cur_money;
		uint32_t vip_level;
		uint32_t sex;
		int32_t chair_id;
		NFSizeString<64> nick_name;
		uint32_t face;
		bool isRobot;

		static void write_to_pbmsg(const struct GamePlayerDetailData_s & obj, ::proto_ff::GamePlayerDetailData & msg);
		static void read_from_pbmsg(const ::proto_ff::GamePlayerDetailData & msg, struct GamePlayerDetailData_s & obj);
		static ::proto_ff::GamePlayerDetailData* new_pbmsg(){ return new ::proto_ff::GamePlayerDetailData(); }
		static ::proto_ff::GamePlayerDetailData make_pbmsg(){ return ::proto_ff::GamePlayerDetailData(); }
	};
	typedef struct GamePlayerDetailData_s GamePlayerDetailData_t;

	struct GamePlayerAchievementData_s : public NFDescStoreSeqOP {
		GamePlayerAchievementData_s();
		int CreateInit();
		int ResumeInit();
		uint64_t cur_ach;
		uint64_t cur_fee;

		static void write_to_pbmsg(const struct GamePlayerAchievementData_s & obj, ::proto_ff::GamePlayerAchievementData & msg);
		static void read_from_pbmsg(const ::proto_ff::GamePlayerAchievementData & msg, struct GamePlayerAchievementData_s & obj);
		static ::proto_ff::GamePlayerAchievementData* new_pbmsg(){ return new ::proto_ff::GamePlayerAchievementData(); }
		static ::proto_ff::GamePlayerAchievementData make_pbmsg(){ return ::proto_ff::GamePlayerAchievementData(); }
	};
	typedef struct GamePlayerAchievementData_s GamePlayerAchievementData_t;

	struct UserSimpleData_s : public NFDescStoreSeqOP {
		UserSimpleData_s();
		int CreateInit();
		int ResumeInit();
		uint64_t userid;
		NFSizeString<64> nickname;
		uint32_t face;
		uint32_t gender;
		uint32_t age;
		uint64_t show_userid;
		uint32_t vip_level;

		static void write_to_pbmsg(const struct UserSimpleData_s & obj, ::proto_ff::UserSimpleData & msg);
		static void read_from_pbmsg(const ::proto_ff::UserSimpleData & msg, struct UserSimpleData_s & obj);
		static ::proto_ff::UserSimpleData* new_pbmsg(){ return new ::proto_ff::UserSimpleData(); }
		static ::proto_ff::UserSimpleData make_pbmsg(){ return ::proto_ff::UserSimpleData(); }
	};
	typedef struct UserSimpleData_s UserSimpleData_t;

	struct UserBankInfo_s : public NFDescStoreSeqOP {
		UserBankInfo_s();
		int CreateInit();
		int ResumeInit();
		NFArray<uint64_t, 1000> record_id;

		static void write_to_pbmsg(const struct UserBankInfo_s & obj, ::proto_ff::UserBankInfo & msg);
		static void read_from_pbmsg(const ::proto_ff::UserBankInfo & msg, struct UserBankInfo_s & obj);
		static ::proto_ff::UserBankInfo* new_pbmsg(){ return new ::proto_ff::UserBankInfo(); }
		static ::proto_ff::UserBankInfo make_pbmsg(){ return ::proto_ff::UserBankInfo(); }
	};
	typedef struct UserBankInfo_s UserBankInfo_t;

	struct tbUserMiscInfo_s : public NFDescStoreSeqOP {
		tbUserMiscInfo_s();
		int CreateInit();
		int ResumeInit();
		uint64_t user_id;
		struct UserBankInfo_s bank_info;

		static void write_to_pbmsg(const struct tbUserMiscInfo_s & obj, ::proto_ff::tbUserMiscInfo & msg);
		static void read_from_pbmsg(const ::proto_ff::tbUserMiscInfo & msg, struct tbUserMiscInfo_s & obj);
		static ::proto_ff::tbUserMiscInfo* new_pbmsg(){ return new ::proto_ff::tbUserMiscInfo(); }
		static ::proto_ff::tbUserMiscInfo make_pbmsg(){ return ::proto_ff::tbUserMiscInfo(); }
	};
	typedef struct tbUserMiscInfo_s tbUserMiscInfo_t;

	struct RankCommonInfo_s : public NFDescStoreSeqOP {
		RankCommonInfo_s();
		int CreateInit();
		int ResumeInit();
		uint64_t id;
		int32_t rank;

		static void write_to_pbmsg(const struct RankCommonInfo_s & obj, ::proto_ff::RankCommonInfo & msg);
		static void read_from_pbmsg(const ::proto_ff::RankCommonInfo & msg, struct RankCommonInfo_s & obj);
		static ::proto_ff::RankCommonInfo* new_pbmsg(){ return new ::proto_ff::RankCommonInfo(); }
		static ::proto_ff::RankCommonInfo make_pbmsg(){ return ::proto_ff::RankCommonInfo(); }
	};
	typedef struct RankCommonInfo_s RankCommonInfo_t;

	struct RankCommonScore_s : public NFDescStoreSeqOP {
		RankCommonScore_s();
		int CreateInit();
		int ResumeInit();
		uint64_t id;
		uint64_t score;

		static void write_to_pbmsg(const struct RankCommonScore_s & obj, ::proto_ff::RankCommonScore & msg);
		static void read_from_pbmsg(const ::proto_ff::RankCommonScore & msg, struct RankCommonScore_s & obj);
		static ::proto_ff::RankCommonScore* new_pbmsg(){ return new ::proto_ff::RankCommonScore(); }
		static ::proto_ff::RankCommonScore make_pbmsg(){ return ::proto_ff::RankCommonScore(); }
	};
	typedef struct RankCommonScore_s RankCommonScore_t;

	struct RankCommonBody_s : public NFDescStoreSeqOP {
		RankCommonBody_s();
		int CreateInit();
		int ResumeInit();
		NFArray<struct RankCommonScore_s, 5001> score_list;
		NFArray<struct RankCommonInfo_s, 5001> info_list;

		static void write_to_pbmsg(const struct RankCommonBody_s & obj, ::proto_ff::RankCommonBody & msg);
		static void read_from_pbmsg(const ::proto_ff::RankCommonBody & msg, struct RankCommonBody_s & obj);
		static ::proto_ff::RankCommonBody* new_pbmsg(){ return new ::proto_ff::RankCommonBody(); }
		static ::proto_ff::RankCommonBody make_pbmsg(){ return ::proto_ff::RankCommonBody(); }
	};
	typedef struct RankCommonBody_s RankCommonBody_t;

	struct tbRankCommon_s : public NFDescStoreSeqOP {
		tbRankCommon_s();
		int CreateInit();
		int ResumeInit();
		int32_t id4db;
		struct RankCommonBody_s body;

		static void write_to_pbmsg(const struct tbRankCommon_s & obj, ::proto_ff::tbRankCommon & msg);
		static void read_from_pbmsg(const ::proto_ff::tbRankCommon & msg, struct tbRankCommon_s & obj);
		static ::proto_ff::tbRankCommon* new_pbmsg(){ return new ::proto_ff::tbRankCommon(); }
		static ::proto_ff::tbRankCommon make_pbmsg(){ return ::proto_ff::tbRankCommon(); }
	};
	typedef struct tbRankCommon_s tbRankCommon_t;

	struct RobotCommonData_s : public NFDescStoreSeqOP {
		RobotCommonData_s();
		int CreateInit();
		int ResumeInit();
		uint64_t robot_id;
		NFSizeString<64> nickname;
		uint32_t face_id;
		uint32_t age;
		uint32_t gender;
		uint64_t jetton;
		bool is_use;

		static void write_to_pbmsg(const struct RobotCommonData_s & obj, ::proto_ff::RobotCommonData & msg);
		static void read_from_pbmsg(const ::proto_ff::RobotCommonData & msg, struct RobotCommonData_s & obj);
		static ::proto_ff::RobotCommonData* new_pbmsg(){ return new ::proto_ff::RobotCommonData(); }
		static ::proto_ff::RobotCommonData make_pbmsg(){ return ::proto_ff::RobotCommonData(); }
	};
	typedef struct RobotCommonData_s RobotCommonData_t;

	struct RobotCommonBody_s : public NFDescStoreSeqOP {
		RobotCommonBody_s();
		int CreateInit();
		int ResumeInit();
		NFArray<struct RobotCommonData_s, 1000> robot_data;

		static void write_to_pbmsg(const struct RobotCommonBody_s & obj, ::proto_ff::RobotCommonBody & msg);
		static void read_from_pbmsg(const ::proto_ff::RobotCommonBody & msg, struct RobotCommonBody_s & obj);
		static ::proto_ff::RobotCommonBody* new_pbmsg(){ return new ::proto_ff::RobotCommonBody(); }
		static ::proto_ff::RobotCommonBody make_pbmsg(){ return ::proto_ff::RobotCommonBody(); }
	};
	typedef struct RobotCommonBody_s RobotCommonBody_t;

	struct tbGameRobot_s : public NFDescStoreSeqOP {
		tbGameRobot_s();
		int CreateInit();
		int ResumeInit();
		int32_t id4db;
		struct RobotCommonBody_s body;

		static void write_to_pbmsg(const struct tbGameRobot_s & obj, ::proto_ff::tbGameRobot & msg);
		static void read_from_pbmsg(const ::proto_ff::tbGameRobot & msg, struct tbGameRobot_s & obj);
		static ::proto_ff::tbGameRobot* new_pbmsg(){ return new ::proto_ff::tbGameRobot(); }
		static ::proto_ff::tbGameRobot make_pbmsg(){ return ::proto_ff::tbGameRobot(); }
	};
	typedef struct tbGameRobot_s tbGameRobot_t;

	struct EventLogData_s : public NFDescStoreSeqOP {
		EventLogData_s();
		int CreateInit();
		int ResumeInit();
		::proto_ff::EventLogType event_type;

		static void write_to_pbmsg(const struct EventLogData_s & obj, ::proto_ff::EventLogData & msg);
		static void read_from_pbmsg(const ::proto_ff::EventLogData & msg, struct EventLogData_s & obj);
		static ::proto_ff::EventLogData* new_pbmsg(){ return new ::proto_ff::EventLogData(); }
		static ::proto_ff::EventLogData make_pbmsg(){ return ::proto_ff::EventLogData(); }
	};
	typedef struct EventLogData_s EventLogData_t;

	struct tbEventLog_s : public NFDescStoreSeqOP {
		tbEventLog_s();
		int CreateInit();
		int ResumeInit();
		uint64_t user_id;
		uint64_t event_id;
		int32_t create_time;
		int32_t expire_time;
		struct EventLogData_s data;

		static void write_to_pbmsg(const struct tbEventLog_s & obj, ::proto_ff::tbEventLog & msg);
		static void read_from_pbmsg(const ::proto_ff::tbEventLog & msg, struct tbEventLog_s & obj);
		static ::proto_ff::tbEventLog* new_pbmsg(){ return new ::proto_ff::tbEventLog(); }
		static ::proto_ff::tbEventLog make_pbmsg(){ return ::proto_ff::tbEventLog(); }
	};
	typedef struct tbEventLog_s tbEventLog_t;

	struct LoginCommonData_s : public NFDescStoreSeqOP {
		LoginCommonData_s();
		int CreateInit();
		int ResumeInit();
		uint32_t aread_id;
		uint64_t agent_id;
		uint32_t channel_id;
		uint32_t referral_code;
		NFSizeString<64> platform_os;
		NFSizeString<64> country;
		NFSizeString<64> province;
		NFSizeString<64> city;
		NFSizeString<64> ip;
		NFSizeString<64> phone_mode;
		NFSizeString<128> device_id;

		static void write_to_pbmsg(const struct LoginCommonData_s & obj, ::proto_ff::LoginCommonData & msg);
		static void read_from_pbmsg(const ::proto_ff::LoginCommonData & msg, struct LoginCommonData_s & obj);
		static ::proto_ff::LoginCommonData* new_pbmsg(){ return new ::proto_ff::LoginCommonData(); }
		static ::proto_ff::LoginCommonData make_pbmsg(){ return ::proto_ff::LoginCommonData(); }
	};
	typedef struct LoginCommonData_s LoginCommonData_t;

	struct LogMoneyDetail_s : public NFDescStoreSeqOP {
		LogMoneyDetail_s();
		int CreateInit();
		int ResumeInit();
		uint64_t event_id;
		uint32_t sequence;
		NFSizeString<128> bus_name;
		NFSizeString<128> event_time;
		uint64_t user_id;
		NFSizeString<128> user_name;
		uint32_t game_id;
		uint32_t room_id;
		uint32_t desk_id;
		uint32_t chair_id;
		uint32_t account_type;
		uint32_t opt_type;
		uint32_t opt_reason;
		uint64_t all_jetton;
		uint64_t jetton;
		uint64_t bank_jetton;
		uint64_t change_count;
		uint64_t agent_id;
		NFSizeString<128> ip;
		uint64_t record_id;

		static void write_to_pbmsg(const struct LogMoneyDetail_s & obj, ::proto_ff::LogMoneyDetail & msg);
		static void read_from_pbmsg(const ::proto_ff::LogMoneyDetail & msg, struct LogMoneyDetail_s & obj);
		static ::proto_ff::LogMoneyDetail* new_pbmsg(){ return new ::proto_ff::LogMoneyDetail(); }
		static ::proto_ff::LogMoneyDetail make_pbmsg(){ return ::proto_ff::LogMoneyDetail(); }
	};
	typedef struct LogMoneyDetail_s LogMoneyDetail_t;

	struct LogGameRecordDetail_s : public NFDescStoreSeqOP {
		LogGameRecordDetail_s();
		int CreateInit();
		int ResumeInit();
		uint64_t event_id;
		uint32_t sequence;
		NFSizeString<128> bus_name;
		NFSizeString<128> event_time;
		uint64_t user_id;
		NFSizeString<128> user_name;
		uint64_t record_id;
		uint32_t game_id;
		uint32_t room_id;
		uint32_t desk_id;
		uint32_t chair_id;
		NFSizeString<1024> result_info;
		uint64_t pour_jetton;
		int64_t win_jetton;
		uint64_t tax_jetton;
		NFSizeString<1024> win_list;
		NFSizeString<1024> lost_list;

		static void write_to_pbmsg(const struct LogGameRecordDetail_s & obj, ::proto_ff::LogGameRecordDetail & msg);
		static void read_from_pbmsg(const ::proto_ff::LogGameRecordDetail & msg, struct LogGameRecordDetail_s & obj);
		static ::proto_ff::LogGameRecordDetail* new_pbmsg(){ return new ::proto_ff::LogGameRecordDetail(); }
		static ::proto_ff::LogGameRecordDetail make_pbmsg(){ return ::proto_ff::LogGameRecordDetail(); }
	};
	typedef struct LogGameRecordDetail_s LogGameRecordDetail_t;

	struct LogGameDetail_s : public NFDescStoreSeqOP {
		LogGameDetail_s();
		int CreateInit();
		int ResumeInit();
		uint64_t event_id;
		uint32_t sequence;
		NFSizeString<128> bus_name;
		NFSizeString<128> event_time;
		uint64_t user_id;
		NFSizeString<128> user_name;
		uint64_t record_id;
		uint32_t game_id;
		uint32_t room_id;
		uint32_t desk_id;
		NFSizeString<1024> bet_info;
		NFSizeString<1024> result_info;
		uint64_t game_time;

		static void write_to_pbmsg(const struct LogGameDetail_s & obj, ::proto_ff::LogGameDetail & msg);
		static void read_from_pbmsg(const ::proto_ff::LogGameDetail & msg, struct LogGameDetail_s & obj);
		static ::proto_ff::LogGameDetail* new_pbmsg(){ return new ::proto_ff::LogGameDetail(); }
		static ::proto_ff::LogGameDetail make_pbmsg(){ return ::proto_ff::LogGameDetail(); }
	};
	typedef struct LogGameDetail_s LogGameDetail_t;

	struct tbLogGameDay_s : public NFDescStoreSeqOP {
		tbLogGameDay_s();
		int CreateInit();
		int ResumeInit();
		NFSizeString<32> date_id;
		uint32_t game_id;
		uint32_t room_id;
		uint64_t all_pour;
		uint64_t pour_day;
		uint64_t pour_week;
		uint64_t pour_month;
		int64_t all_win;
		int64_t win_day;
		int64_t win_week;
		int64_t win_month;
		uint64_t all_fee;
		uint64_t fee_day;
		uint64_t fee_week;
		uint64_t fee_month;
		NFSizeString<32> stat_time;

		static void write_to_pbmsg(const struct tbLogGameDay_s & obj, ::proto_ff::tbLogGameDay & msg);
		static void read_from_pbmsg(const ::proto_ff::tbLogGameDay & msg, struct tbLogGameDay_s & obj);
		static ::proto_ff::tbLogGameDay* new_pbmsg(){ return new ::proto_ff::tbLogGameDay(); }
		static ::proto_ff::tbLogGameDay make_pbmsg(){ return ::proto_ff::tbLogGameDay(); }
	};
	typedef struct tbLogGameDay_s tbLogGameDay_t;

	struct tbGameUserManagerData_s : public NFDescStoreSeqOP {
		tbGameUserManagerData_s();
		int CreateInit();
		int ResumeInit();
		uint64_t id;
		uint64_t user_id;
		NFSizeString<128> user_name;
		NFSizeString<128> create_date;
		uint32_t roster_type;
		uint64_t start_time;
		uint64_t end_time;
		uint32_t game_id;
		uint32_t room_id;
		uint32_t state;
		int64_t opt_mark;
		float rate_mark;
		int32_t control_level;
		uint64_t max_win_jetton;
		int64_t cur_win;

		static void write_to_pbmsg(const struct tbGameUserManagerData_s & obj, ::proto_ff::tbGameUserManagerData & msg);
		static void read_from_pbmsg(const ::proto_ff::tbGameUserManagerData & msg, struct tbGameUserManagerData_s & obj);
		static ::proto_ff::tbGameUserManagerData* new_pbmsg(){ return new ::proto_ff::tbGameUserManagerData(); }
		static ::proto_ff::tbGameUserManagerData make_pbmsg(){ return ::proto_ff::tbGameUserManagerData(); }
	};
	typedef struct tbGameUserManagerData_s tbGameUserManagerData_t;

	struct tbMachineManagerData_s : public NFDescStoreSeqOP {
		tbMachineManagerData_s();
		int CreateInit();
		int ResumeInit();
		uint64_t id;
		NFSizeString<128> device_id;
		NFSizeString<128> create_date;
		uint32_t roster_type;
		uint64_t start_time;
		uint64_t end_time;
		uint32_t game_id;
		uint32_t room_id;
		uint32_t state;
		int64_t opt_mark;
		float rate_mark;
		int32_t control_level;
		uint64_t max_win_jetton;
		int64_t cur_win;

		static void write_to_pbmsg(const struct tbMachineManagerData_s & obj, ::proto_ff::tbMachineManagerData & msg);
		static void read_from_pbmsg(const ::proto_ff::tbMachineManagerData & msg, struct tbMachineManagerData_s & obj);
		static ::proto_ff::tbMachineManagerData* new_pbmsg(){ return new ::proto_ff::tbMachineManagerData(); }
		static ::proto_ff::tbMachineManagerData make_pbmsg(){ return ::proto_ff::tbMachineManagerData(); }
	};
	typedef struct tbMachineManagerData_s tbMachineManagerData_t;

	struct Sheet_tbGameUserManagerData_s : public NFDescStoreSeqOP {
		Sheet_tbGameUserManagerData_s();
		int CreateInit();
		int ResumeInit();
		NFArray<struct tbGameUserManagerData_s, 5000> tbGameUserManagerData_List;

		static void write_to_pbmsg(const struct Sheet_tbGameUserManagerData_s & obj, ::proto_ff::Sheet_tbGameUserManagerData & msg);
		static void read_from_pbmsg(const ::proto_ff::Sheet_tbGameUserManagerData & msg, struct Sheet_tbGameUserManagerData_s & obj);
		static ::proto_ff::Sheet_tbGameUserManagerData* new_pbmsg(){ return new ::proto_ff::Sheet_tbGameUserManagerData(); }
		static ::proto_ff::Sheet_tbGameUserManagerData make_pbmsg(){ return ::proto_ff::Sheet_tbGameUserManagerData(); }
	};
	typedef struct Sheet_tbGameUserManagerData_s Sheet_tbGameUserManagerData_t;

	struct tbGmCtrlGiveCtrlData_s : public NFDescStoreSeqOP {
		tbGmCtrlGiveCtrlData_s();
		int CreateInit();
		int ResumeInit();
		uint64_t id;
		uint64_t user_id;
		NFSizeString<128> user_name;
		NFSizeString<128> create_date;
		uint32_t control_type;
		uint64_t start_time;
		uint64_t end_time;
		uint32_t game_id;
		uint32_t state;
		int32_t jackpot_type;
		float jackpot_rate;
		uint64_t jackpot_jetton;

		static void write_to_pbmsg(const struct tbGmCtrlGiveCtrlData_s & obj, ::proto_ff::tbGmCtrlGiveCtrlData & msg);
		static void read_from_pbmsg(const ::proto_ff::tbGmCtrlGiveCtrlData & msg, struct tbGmCtrlGiveCtrlData_s & obj);
		static ::proto_ff::tbGmCtrlGiveCtrlData* new_pbmsg(){ return new ::proto_ff::tbGmCtrlGiveCtrlData(); }
		static ::proto_ff::tbGmCtrlGiveCtrlData make_pbmsg(){ return ::proto_ff::tbGmCtrlGiveCtrlData(); }
	};
	typedef struct tbGmCtrlGiveCtrlData_s tbGmCtrlGiveCtrlData_t;

	struct Sheet_tbGmCtrlGiveCtrlData_s : public NFDescStoreSeqOP {
		Sheet_tbGmCtrlGiveCtrlData_s();
		int CreateInit();
		int ResumeInit();
		NFArray<struct tbGmCtrlGiveCtrlData_s, 5000> tbGmCtrlGiveCtrlData_List;

		static void write_to_pbmsg(const struct Sheet_tbGmCtrlGiveCtrlData_s & obj, ::proto_ff::Sheet_tbGmCtrlGiveCtrlData & msg);
		static void read_from_pbmsg(const ::proto_ff::Sheet_tbGmCtrlGiveCtrlData & msg, struct Sheet_tbGmCtrlGiveCtrlData_s & obj);
		static ::proto_ff::Sheet_tbGmCtrlGiveCtrlData* new_pbmsg(){ return new ::proto_ff::Sheet_tbGmCtrlGiveCtrlData(); }
		static ::proto_ff::Sheet_tbGmCtrlGiveCtrlData make_pbmsg(){ return ::proto_ff::Sheet_tbGmCtrlGiveCtrlData(); }
	};
	typedef struct Sheet_tbGmCtrlGiveCtrlData_s Sheet_tbGmCtrlGiveCtrlData_t;

	struct LogVipRechargeRecord_s : public NFDescStoreSeqOP {
		LogVipRechargeRecord_s();
		int CreateInit();
		int ResumeInit();
		uint64_t event_id;
		uint32_t sequence;
		NFSizeString<128> bus_name;
		NFSizeString<128> event_time;
		uint64_t user_id;
		NFSizeString<128> user_name;
		uint64_t amount;
		uint32_t recharge_id;
		NFSizeString<128> recharge_name;
		uint64_t status;

		static void write_to_pbmsg(const struct LogVipRechargeRecord_s & obj, ::proto_ff::LogVipRechargeRecord & msg);
		static void read_from_pbmsg(const ::proto_ff::LogVipRechargeRecord & msg, struct LogVipRechargeRecord_s & obj);
		static ::proto_ff::LogVipRechargeRecord* new_pbmsg(){ return new ::proto_ff::LogVipRechargeRecord(); }
		static ::proto_ff::LogVipRechargeRecord make_pbmsg(){ return ::proto_ff::LogVipRechargeRecord(); }
	};
	typedef struct LogVipRechargeRecord_s LogVipRechargeRecord_t;

	struct LogZhuangRecord_s : public NFDescStoreSeqOP {
		LogZhuangRecord_s();
		int CreateInit();
		int ResumeInit();
		uint64_t event_id;
		uint32_t sequence;
		NFSizeString<128> bus_name;
		NFSizeString<128> event_time;
		uint64_t user_id;
		NFSizeString<128> user_name;
		int64_t amount;
		uint64_t status;

		static void write_to_pbmsg(const struct LogZhuangRecord_s & obj, ::proto_ff::LogZhuangRecord & msg);
		static void read_from_pbmsg(const ::proto_ff::LogZhuangRecord & msg, struct LogZhuangRecord_s & obj);
		static ::proto_ff::LogZhuangRecord* new_pbmsg(){ return new ::proto_ff::LogZhuangRecord(); }
		static ::proto_ff::LogZhuangRecord make_pbmsg(){ return ::proto_ff::LogZhuangRecord(); }
	};
	typedef struct LogZhuangRecord_s LogZhuangRecord_t;

	struct LogRechargeOrder_s : public NFDescStoreSeqOP {
		LogRechargeOrder_s();
		int CreateInit();
		int ResumeInit();
		uint64_t event_id;
		uint32_t sequence;
		NFSizeString<128> bus_name;
		NFSizeString<128> event_time;
		uint64_t user_id;
		NFSizeString<128> user_name;
		NFSizeString<128> order_id;
		uint32_t pay_id;
		NFSizeString<128> pay_channel;
		uint32_t pay_type;
		NFSizeString<128> ch_order_id;
		uint32_t state;

		static void write_to_pbmsg(const struct LogRechargeOrder_s & obj, ::proto_ff::LogRechargeOrder & msg);
		static void read_from_pbmsg(const ::proto_ff::LogRechargeOrder & msg, struct LogRechargeOrder_s & obj);
		static ::proto_ff::LogRechargeOrder* new_pbmsg(){ return new ::proto_ff::LogRechargeOrder(); }
		static ::proto_ff::LogRechargeOrder make_pbmsg(){ return ::proto_ff::LogRechargeOrder(); }
	};
	typedef struct LogRechargeOrder_s LogRechargeOrder_t;

	struct LogGiveMoneyRecord_s : public NFDescStoreSeqOP {
		LogGiveMoneyRecord_s();
		int CreateInit();
		int ResumeInit();
		uint64_t event_id;
		uint32_t sequence;
		NFSizeString<128> bus_name;
		NFSizeString<128> event_time;
		uint64_t user_id;
		NFSizeString<128> user_name;
		uint32_t type;
		uint64_t amount;
		uint64_t status;

		static void write_to_pbmsg(const struct LogGiveMoneyRecord_s & obj, ::proto_ff::LogGiveMoneyRecord & msg);
		static void read_from_pbmsg(const ::proto_ff::LogGiveMoneyRecord & msg, struct LogGiveMoneyRecord_s & obj);
		static ::proto_ff::LogGiveMoneyRecord* new_pbmsg(){ return new ::proto_ff::LogGiveMoneyRecord(); }
		static ::proto_ff::LogGiveMoneyRecord make_pbmsg(){ return ::proto_ff::LogGiveMoneyRecord(); }
	};
	typedef struct LogGiveMoneyRecord_s LogGiveMoneyRecord_t;

	struct tbLogSystemDay_s : public NFDescStoreSeqOP {
		tbLogSystemDay_s();
		int CreateInit();
		int ResumeInit();
		NFSizeString<32> date_id;
		uint32_t active_player;
		uint32_t login_count;
		uint32_t valid_player;
		uint32_t new_player;
		uint32_t pay_player;
		uint32_t pay_times;
		uint64_t pay_all;
		uint32_t new_pay_player;
		uint32_t new_pay_all;
		uint64_t commission_all;
		uint64_t all_fee;
		uint64_t all_pour;
		int64_t all_win;
		uint64_t jetton_init;
		uint64_t all_draw;
		uint64_t jetton_in;
		uint64_t jetton_out;
		uint64_t sys_award;
		uint64_t player_jetton;
		uint64_t trd_pay_all;
		uint64_t vip_pay_all;
		uint64_t zhuangzhang_all;
		uint64_t activity_award;
		uint64_t all_bank_jetton;
		uint64_t freeze_jetton;
		uint64_t all_jetton;
		uint64_t all_player;
		uint64_t active_seven;
		uint64_t active_thirty;
		uint64_t pour_day_all;
		uint64_t pour_week_all;
		uint64_t pour_month_all;
		int64_t sys_win_day;
		int64_t sys_win_week;
		int64_t sys_win_month;
		uint64_t fee_day;
		uint64_t fee_week;
		uint64_t fee_month;
		uint64_t commision_all;
		uint64_t commision_take;
		uint64_t commision_day;
		uint64_t commision_week;
		uint64_t commision_month;
		uint64_t max_online;
		uint64_t win_cost_value;
		uint64_t day_money_value;
		uint64_t pay_day;
		uint64_t pay_week;
		uint64_t pay_month;
		uint64_t draw_day;
		uint64_t draw_week;
		uint64_t draw_month;
		uint64_t trd_pay_day;
		uint64_t trd_pay_week;
		uint64_t trd_pay_month;
		uint64_t vip_pay_day;
		uint64_t vip_pay_week;
		uint64_t vip_pay_month;
		uint64_t zhuangzhang_day;
		uint64_t zhuangzhang_week;
		uint64_t zhuangzhang_month;
		uint64_t give_day;
		uint64_t give_week;
		uint64_t give_month;
		uint64_t all_give;
		uint64_t all_vip_zhuanru;
		uint64_t today_vip_zhuanru;
		uint64_t week_vip_zhuanru;
		uint64_t month_vip_zhuanru;
		uint64_t all_vip_zhuanchu;
		uint64_t today_vip_zhuanchu;
		uint64_t week_vip_zhuanchu;
		uint64_t month_vip_zhuanchu;

		static void write_to_pbmsg(const struct tbLogSystemDay_s & obj, ::proto_ff::tbLogSystemDay & msg);
		static void read_from_pbmsg(const ::proto_ff::tbLogSystemDay & msg, struct tbLogSystemDay_s & obj);
		static ::proto_ff::tbLogSystemDay* new_pbmsg(){ return new ::proto_ff::tbLogSystemDay(); }
		static ::proto_ff::tbLogSystemDay make_pbmsg(){ return ::proto_ff::tbLogSystemDay(); }
	};
	typedef struct tbLogSystemDay_s tbLogSystemDay_t;

	struct tbRedeemCode_s : public NFDescStoreSeqOP {
		tbRedeemCode_s();
		int CreateInit();
		int ResumeInit();
		NFSizeString<128> id;
		uint64_t gold;
		uint64_t create_time;
		NFSizeString<128> code_name;
		uint32_t state;
		uint64_t user_id;
		uint64_t use_time;

		static void write_to_pbmsg(const struct tbRedeemCode_s & obj, ::proto_ff::tbRedeemCode & msg);
		static void read_from_pbmsg(const ::proto_ff::tbRedeemCode & msg, struct tbRedeemCode_s & obj);
		static ::proto_ff::tbRedeemCode* new_pbmsg(){ return new ::proto_ff::tbRedeemCode(); }
		static ::proto_ff::tbRedeemCode make_pbmsg(){ return ::proto_ff::tbRedeemCode(); }
	};
	typedef struct tbRedeemCode_s tbRedeemCode_t;

	struct LogRedeemCodeRechargeRecord_s : public NFDescStoreSeqOP {
		LogRedeemCodeRechargeRecord_s();
		int CreateInit();
		int ResumeInit();
		uint64_t event_id;
		uint32_t sequence;
		NFSizeString<128> bus_name;
		NFSizeString<128> event_time;
		uint64_t user_id;
		NFSizeString<128> user_name;
		uint64_t amount;
		uint64_t status;

		static void write_to_pbmsg(const struct LogRedeemCodeRechargeRecord_s & obj, ::proto_ff::LogRedeemCodeRechargeRecord & msg);
		static void read_from_pbmsg(const ::proto_ff::LogRedeemCodeRechargeRecord & msg, struct LogRedeemCodeRechargeRecord_s & obj);
		static ::proto_ff::LogRedeemCodeRechargeRecord* new_pbmsg(){ return new ::proto_ff::LogRedeemCodeRechargeRecord(); }
		static ::proto_ff::LogRedeemCodeRechargeRecord make_pbmsg(){ return ::proto_ff::LogRedeemCodeRechargeRecord(); }
	};
	typedef struct LogRedeemCodeRechargeRecord_s LogRedeemCodeRechargeRecord_t;

	struct GameRoomStat_s : public NFDescStoreSeqOP {
		GameRoomStat_s();
		int CreateInit();
		int ResumeInit();
		uint64_t cur_fee;
		uint64_t cur_pour;
		int64_t cur_win;

		static void write_to_pbmsg(const struct GameRoomStat_s & obj, ::proto_ff::GameRoomStat & msg);
		static void read_from_pbmsg(const ::proto_ff::GameRoomStat & msg, struct GameRoomStat_s & obj);
		static ::proto_ff::GameRoomStat* new_pbmsg(){ return new ::proto_ff::GameRoomStat(); }
		static ::proto_ff::GameRoomStat make_pbmsg(){ return ::proto_ff::GameRoomStat(); }
	};
	typedef struct GameRoomStat_s GameRoomStat_t;

	struct GamePlayerPourInfo_s : public NFDescStoreSeqOP {
		GamePlayerPourInfo_s();
		int CreateInit();
		int ResumeInit();
		uint64_t user_id;
		int64_t pour;

		static void write_to_pbmsg(const struct GamePlayerPourInfo_s & obj, ::proto_ff::GamePlayerPourInfo & msg);
		static void read_from_pbmsg(const ::proto_ff::GamePlayerPourInfo & msg, struct GamePlayerPourInfo_s & obj);
		static ::proto_ff::GamePlayerPourInfo* new_pbmsg(){ return new ::proto_ff::GamePlayerPourInfo(); }
		static ::proto_ff::GamePlayerPourInfo make_pbmsg(){ return ::proto_ff::GamePlayerPourInfo(); }
	};
	typedef struct GamePlayerPourInfo_s GamePlayerPourInfo_t;

	struct GameTablePourInfo_s : public NFDescStoreSeqOP {
		GameTablePourInfo_s();
		int CreateInit();
		int ResumeInit();

		static void write_to_pbmsg(const struct GameTablePourInfo_s & obj, ::proto_ff::GameTablePourInfo & msg);
		static void read_from_pbmsg(const ::proto_ff::GameTablePourInfo & msg, struct GameTablePourInfo_s & obj);
		static ::proto_ff::GameTablePourInfo* new_pbmsg(){ return new ::proto_ff::GameTablePourInfo(); }
		static ::proto_ff::GameTablePourInfo make_pbmsg(){ return ::proto_ff::GameTablePourInfo(); }
	};
	typedef struct GameTablePourInfo_s GameTablePourInfo_t;

}

