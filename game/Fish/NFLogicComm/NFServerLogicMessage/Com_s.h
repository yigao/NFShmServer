#pragma once

#include <stdint.h>
#include <NFComm/NFShmStl/NFShmString.h>
#include <NFComm/NFShmStl/NFShmVector.h>
#include <NFComm/NFShmCore/NFSeqOP.h>
#include <NFComm/NFShmCore/NFShmMgr.h>
#include "Com.pb.h"
#include "Com_s.h"
#include "ComDefine.pb.h"
#include "ComDefine_s.h"



namespace proto_ff_s {

	struct EmptyMessage_s : public NFDescStoreSeqOP {
		EmptyMessage_s();
		virtual ~EmptyMessage_s(){}
		int CreateInit();
		int ResumeInit();

		virtual void write_to_pbmsg(::proto_ff::EmptyMessage & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::EmptyMessage & msg);
		static ::proto_ff::EmptyMessage* new_pbmsg(){ return new ::proto_ff::EmptyMessage(); }
		static ::proto_ff::EmptyMessage make_pbmsg(){ return ::proto_ff::EmptyMessage(); }
	};
	typedef struct EmptyMessage_s EmptyMessage_t;

	struct ComPair_s : public NFDescStoreSeqOP {
		ComPair_s();
		virtual ~ComPair_s(){}
		int CreateInit();
		int ResumeInit();
		uint32_t key;//
		uint32_t value;//

		virtual void write_to_pbmsg(::proto_ff::ComPair & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::ComPair & msg);
		static ::proto_ff::ComPair* new_pbmsg(){ return new ::proto_ff::ComPair(); }
		static ::proto_ff::ComPair make_pbmsg(){ return ::proto_ff::ComPair(); }
	};
	typedef struct ComPair_s ComPair_t;

	struct ComPair64_s : public NFDescStoreSeqOP {
		ComPair64_s();
		virtual ~ComPair64_s(){}
		int CreateInit();
		int ResumeInit();
		uint64_t key;//
		uint64_t value;//

		virtual void write_to_pbmsg(::proto_ff::ComPair64 & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::ComPair64 & msg);
		static ::proto_ff::ComPair64* new_pbmsg(){ return new ::proto_ff::ComPair64(); }
		static ::proto_ff::ComPair64 make_pbmsg(){ return ::proto_ff::ComPair64(); }
	};
	typedef struct ComPair64_s ComPair64_t;

	struct ComPairBool_s : public NFDescStoreSeqOP {
		ComPairBool_s();
		virtual ~ComPairBool_s(){}
		int CreateInit();
		int ResumeInit();
		uint32_t key;//
		bool value;//

		virtual void write_to_pbmsg(::proto_ff::ComPairBool & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::ComPairBool & msg);
		static ::proto_ff::ComPairBool* new_pbmsg(){ return new ::proto_ff::ComPairBool(); }
		static ::proto_ff::ComPairBool make_pbmsg(){ return ::proto_ff::ComPairBool(); }
	};
	typedef struct ComPairBool_s ComPairBool_t;

	struct ComItem_s : public NFDescStoreSeqOP {
		ComItem_s();
		virtual ~ComItem_s(){}
		int CreateInit();
		int ResumeInit();
		uint64_t item_id;//
		uint64_t item_num;//

		virtual void write_to_pbmsg(::proto_ff::ComItem & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::ComItem & msg);
		static ::proto_ff::ComItem* new_pbmsg(){ return new ::proto_ff::ComItem(); }
		static ::proto_ff::ComItem make_pbmsg(){ return ::proto_ff::ComItem(); }
	};
	typedef struct ComItem_s ComItem_t;

	struct ComItemWithType_s : public NFDescStoreSeqOP {
		ComItemWithType_s();
		virtual ~ComItemWithType_s(){}
		int CreateInit();
		int ResumeInit();
		uint64_t item_id;//
		uint64_t item_num;//
		uint32_t type;//

		virtual void write_to_pbmsg(::proto_ff::ComItemWithType & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::ComItemWithType & msg);
		static ::proto_ff::ComItemWithType* new_pbmsg(){ return new ::proto_ff::ComItemWithType(); }
		static ::proto_ff::ComItemWithType make_pbmsg(){ return ::proto_ff::ComItemWithType(); }
	};
	typedef struct ComItemWithType_s ComItemWithType_t;

	struct Vector3PB_s : public NFDescStoreSeqOP {
		Vector3PB_s();
		virtual ~Vector3PB_s(){}
		int CreateInit();
		int ResumeInit();
		float x;//
		float y;//
		float z;//

		virtual void write_to_pbmsg(::proto_ff::Vector3PB & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Vector3PB & msg);
		static ::proto_ff::Vector3PB* new_pbmsg(){ return new ::proto_ff::Vector3PB(); }
		static ::proto_ff::Vector3PB make_pbmsg(){ return ::proto_ff::Vector3PB(); }
	};
	typedef struct Vector3PB_s Vector3PB_t;

	struct Vector2PB_s : public NFDescStoreSeqOP {
		Vector2PB_s();
		virtual ~Vector2PB_s(){}
		int CreateInit();
		int ResumeInit();
		float x;//
		float y;//

		virtual void write_to_pbmsg(::proto_ff::Vector2PB & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Vector2PB & msg);
		static ::proto_ff::Vector2PB* new_pbmsg(){ return new ::proto_ff::Vector2PB(); }
		static ::proto_ff::Vector2PB make_pbmsg(){ return ::proto_ff::Vector2PB(); }
	};
	typedef struct Vector2PB_s Vector2PB_t;

	struct Attr64_s : public NFDescStoreSeqOP {
		Attr64_s();
		virtual ~Attr64_s(){}
		int CreateInit();
		int ResumeInit();
		uint32_t id;//
		int64_t value;//

		virtual void write_to_pbmsg(::proto_ff::Attr64 & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Attr64 & msg);
		static ::proto_ff::Attr64* new_pbmsg(){ return new ::proto_ff::Attr64(); }
		static ::proto_ff::Attr64 make_pbmsg(){ return ::proto_ff::Attr64(); }
	};
	typedef struct Attr64_s Attr64_t;

	struct Proto_UserLoginExternalData_s : public NFDescStoreSeqOP {
		Proto_UserLoginExternalData_s();
		virtual ~Proto_UserLoginExternalData_s(){}
		int CreateInit();
		int ResumeInit();
		uint32_t aread_id;//
		uint32_t agent_id;//
		uint32_t channel_id;//
		uint64_t referral_code;//
		NFShmString<32> platform_os;//
		NFShmString<32> country;//
		NFShmString<32> province;//
		NFShmString<32> city;//
		NFShmString<32> phone_mode;//
		NFShmString<32> device_id;//

		virtual void write_to_pbmsg(::proto_ff::Proto_UserLoginExternalData & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Proto_UserLoginExternalData & msg);
		static ::proto_ff::Proto_UserLoginExternalData* new_pbmsg(){ return new ::proto_ff::Proto_UserLoginExternalData(); }
		static ::proto_ff::Proto_UserLoginExternalData make_pbmsg(){ return ::proto_ff::Proto_UserLoginExternalData(); }
	};
	typedef struct Proto_UserLoginExternalData_s Proto_UserLoginExternalData_t;

	struct Proto_UserDetailCommonData_s : public NFDescStoreSeqOP {
		Proto_UserDetailCommonData_s();
		virtual ~Proto_UserDetailCommonData_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmString<32> nick_name;//
		uint32_t face_id;//
		uint32_t gender;//
		uint64_t jetton;//
		uint64_t bank_jetton;//
		uint64_t agent_id;//
		uint64_t phonenum;//

		virtual void write_to_pbmsg(::proto_ff::Proto_UserDetailCommonData & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Proto_UserDetailCommonData & msg);
		static ::proto_ff::Proto_UserDetailCommonData* new_pbmsg(){ return new ::proto_ff::Proto_UserDetailCommonData(); }
		static ::proto_ff::Proto_UserDetailCommonData make_pbmsg(){ return ::proto_ff::Proto_UserDetailCommonData(); }
	};
	typedef struct Proto_UserDetailCommonData_s Proto_UserDetailCommonData_t;

	struct tbGiveBankJetton_s : public NFDescStoreSeqOP {
		tbGiveBankJetton_s();
		virtual ~tbGiveBankJetton_s(){}
		int CreateInit();
		int ResumeInit();
		uint64_t id;//
		uint64_t user_id;//
		NFShmString<32> user_name;//
		uint64_t give_user_id;//
		NFShmString<32> give_user_name;//
		uint64_t give_jetton;//
		uint64_t create_time;//

		virtual void write_to_pbmsg(::proto_ff::tbGiveBankJetton & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::tbGiveBankJetton & msg);
		static ::proto_ff::tbGiveBankJetton* new_pbmsg(){ return new ::proto_ff::tbGiveBankJetton(); }
		static ::proto_ff::tbGiveBankJetton make_pbmsg(){ return ::proto_ff::tbGiveBankJetton(); }
	};
	typedef struct tbGiveBankJetton_s tbGiveBankJetton_t;

	struct Proto_UserSimpleData_s : public NFDescStoreSeqOP {
		Proto_UserSimpleData_s();
		virtual ~Proto_UserSimpleData_s(){}
		int CreateInit();
		int ResumeInit();
		uint64_t userid;//
		NFShmString<32> nickname;//
		uint32_t face;//
		uint32_t gender;//
		uint32_t age;//

		virtual void write_to_pbmsg(::proto_ff::Proto_UserSimpleData & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Proto_UserSimpleData & msg);
		static ::proto_ff::Proto_UserSimpleData* new_pbmsg(){ return new ::proto_ff::Proto_UserSimpleData(); }
		static ::proto_ff::Proto_UserSimpleData make_pbmsg(){ return ::proto_ff::Proto_UserSimpleData(); }
	};
	typedef struct Proto_UserSimpleData_s Proto_UserSimpleData_t;

	struct GamePlayerDetailData_s : public NFDescStoreSeqOP {
		GamePlayerDetailData_s();
		virtual ~GamePlayerDetailData_s(){}
		int CreateInit();
		int ResumeInit();
		uint64_t player_id;//
		int64_t cur_money;//
		uint32_t vip_level;//
		uint32_t sex;//
		int32_t chair_id;//
		NFShmString<128> nick_name;//
		uint32_t face;//
		bool isRobot;//

		virtual void write_to_pbmsg(::proto_ff::GamePlayerDetailData & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::GamePlayerDetailData & msg);
		static ::proto_ff::GamePlayerDetailData* new_pbmsg(){ return new ::proto_ff::GamePlayerDetailData(); }
		static ::proto_ff::GamePlayerDetailData make_pbmsg(){ return ::proto_ff::GamePlayerDetailData(); }
	};
	typedef struct GamePlayerDetailData_s GamePlayerDetailData_t;

	struct GamePlayerWealthData_s : public NFDescStoreSeqOP {
		GamePlayerWealthData_s();
		virtual ~GamePlayerWealthData_s(){}
		int CreateInit();
		int ResumeInit();
		uint64_t player_id;//
		int64_t recharge;//
		int64_t total_lost;//
		int64_t total_win;//
		int64_t this_game_lost;//
		int64_t this_game_win;//

		virtual void write_to_pbmsg(::proto_ff::GamePlayerWealthData & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::GamePlayerWealthData & msg);
		static ::proto_ff::GamePlayerWealthData* new_pbmsg(){ return new ::proto_ff::GamePlayerWealthData(); }
		static ::proto_ff::GamePlayerWealthData make_pbmsg(){ return ::proto_ff::GamePlayerWealthData(); }
	};
	typedef struct GamePlayerWealthData_s GamePlayerWealthData_t;

	struct GamePlayerAchievementData_s : public NFDescStoreSeqOP {
		GamePlayerAchievementData_s();
		virtual ~GamePlayerAchievementData_s(){}
		int CreateInit();
		int ResumeInit();
		uint64_t cur_ach;//
		uint64_t cur_fee;//

		virtual void write_to_pbmsg(::proto_ff::GamePlayerAchievementData & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::GamePlayerAchievementData & msg);
		static ::proto_ff::GamePlayerAchievementData* new_pbmsg(){ return new ::proto_ff::GamePlayerAchievementData(); }
		static ::proto_ff::GamePlayerAchievementData make_pbmsg(){ return ::proto_ff::GamePlayerAchievementData(); }
	};
	typedef struct GamePlayerAchievementData_s GamePlayerAchievementData_t;

	struct GameRoomStat_s : public NFDescStoreSeqOP {
		GameRoomStat_s();
		virtual ~GameRoomStat_s(){}
		int CreateInit();
		int ResumeInit();
		uint64_t cur_fee;//
		uint64_t cur_pour;//
		int64_t cur_win;//

		virtual void write_to_pbmsg(::proto_ff::GameRoomStat & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::GameRoomStat & msg);
		static ::proto_ff::GameRoomStat* new_pbmsg(){ return new ::proto_ff::GameRoomStat(); }
		static ::proto_ff::GameRoomStat make_pbmsg(){ return ::proto_ff::GameRoomStat(); }
	};
	typedef struct GameRoomStat_s GameRoomStat_t;

}

