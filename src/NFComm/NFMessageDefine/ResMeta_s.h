#pragma once

#include <stdint.h>
#include <NFComm/NFShmCore/NFSizeString.h>
#include <NFComm/NFShmCore/NFArray.h>
#include <NFComm/NFShmCore/NFSeqOP.h>
#include <NFComm/NFShmCore/NFShmMgr.h>
#include "ResMeta.pb.h"
#include "ResMeta_s.h"
#include "proto_common.pb.h"
#include "proto_common_s.h"

namespace proto_ff_s {

	struct MailDesc_s : public NFDescStoreSeqOP {
		MailDesc_s();
		int CreateInit();
		int ResumeInit();
		int32_t id;
		NFSizeString<64> title;
		int32_t type;
		NFSizeString<512> content;
		NFSizeString<32> send_name;
		NFSizeString<32> start_time_str;
		NFSizeString<32> end_time_str;
		uint64_t start_time;
		uint64_t end_time;
		int32_t add_gold;

		static void write_to_pbmsg(const struct MailDesc_s & obj, ::proto_ff::MailDesc & msg);
		static void read_from_pbmsg(const ::proto_ff::MailDesc & msg, struct MailDesc_s & obj);
		static ::proto_ff::MailDesc* new_pbmsg(){ return new ::proto_ff::MailDesc(); }
		static ::proto_ff::MailDesc make_pbmsg(){ return ::proto_ff::MailDesc(); }
	};
	typedef struct MailDesc_s MailDesc_t;

	struct Sheet_MailDesc_s : public NFDescStoreSeqOP {
		Sheet_MailDesc_s();
		int CreateInit();
		int ResumeInit();
		NFArray<struct MailDesc_s, 200> MailDesc_List;

		static void write_to_pbmsg(const struct Sheet_MailDesc_s & obj, ::proto_ff::Sheet_MailDesc & msg);
		static void read_from_pbmsg(const ::proto_ff::Sheet_MailDesc & msg, struct Sheet_MailDesc_s & obj);
		static ::proto_ff::Sheet_MailDesc* new_pbmsg(){ return new ::proto_ff::Sheet_MailDesc(); }
		static ::proto_ff::Sheet_MailDesc make_pbmsg(){ return ::proto_ff::Sheet_MailDesc(); }
	};
	typedef struct Sheet_MailDesc_s Sheet_MailDesc_t;

	struct ConstDesc_s : public NFDescStoreSeqOP {
		ConstDesc_s();
		int CreateInit();
		int ResumeInit();
		int32_t id;
		NFSizeString<128> value;

		static void write_to_pbmsg(const struct ConstDesc_s & obj, ::proto_ff::ConstDesc & msg);
		static void read_from_pbmsg(const ::proto_ff::ConstDesc & msg, struct ConstDesc_s & obj);
		static ::proto_ff::ConstDesc* new_pbmsg(){ return new ::proto_ff::ConstDesc(); }
		static ::proto_ff::ConstDesc make_pbmsg(){ return ::proto_ff::ConstDesc(); }
	};
	typedef struct ConstDesc_s ConstDesc_t;

	struct Sheet_ConstDesc_s : public NFDescStoreSeqOP {
		Sheet_ConstDesc_s();
		int CreateInit();
		int ResumeInit();
		NFArray<struct ConstDesc_s, 100> ConstDesc_List;

		static void write_to_pbmsg(const struct Sheet_ConstDesc_s & obj, ::proto_ff::Sheet_ConstDesc & msg);
		static void read_from_pbmsg(const ::proto_ff::Sheet_ConstDesc & msg, struct Sheet_ConstDesc_s & obj);
		static ::proto_ff::Sheet_ConstDesc* new_pbmsg(){ return new ::proto_ff::Sheet_ConstDesc(); }
		static ::proto_ff::Sheet_ConstDesc make_pbmsg(){ return ::proto_ff::Sheet_ConstDesc(); }
	};
	typedef struct Sheet_ConstDesc_s Sheet_ConstDesc_t;

	struct NameDesc_s : public NFDescStoreSeqOP {
		NameDesc_s();
		int CreateInit();
		int ResumeInit();
		uint64_t id;
		NFSizeString<64> name;

		static void write_to_pbmsg(const struct NameDesc_s & obj, ::proto_ff::NameDesc & msg);
		static void read_from_pbmsg(const ::proto_ff::NameDesc & msg, struct NameDesc_s & obj);
		static ::proto_ff::NameDesc* new_pbmsg(){ return new ::proto_ff::NameDesc(); }
		static ::proto_ff::NameDesc make_pbmsg(){ return ::proto_ff::NameDesc(); }
	};
	typedef struct NameDesc_s NameDesc_t;

	struct Sheet_NameDesc_s : public NFDescStoreSeqOP {
		Sheet_NameDesc_s();
		int CreateInit();
		int ResumeInit();
		NFArray<struct NameDesc_s, 100> NameDesc_List;

		static void write_to_pbmsg(const struct Sheet_NameDesc_s & obj, ::proto_ff::Sheet_NameDesc & msg);
		static void read_from_pbmsg(const ::proto_ff::Sheet_NameDesc & msg, struct Sheet_NameDesc_s & obj);
		static ::proto_ff::Sheet_NameDesc* new_pbmsg(){ return new ::proto_ff::Sheet_NameDesc(); }
		static ::proto_ff::Sheet_NameDesc make_pbmsg(){ return ::proto_ff::Sheet_NameDesc(); }
	};
	typedef struct Sheet_NameDesc_s Sheet_NameDesc_t;

	struct GameRoomDesc_s : public NFDescStoreSeqOP {
		GameRoomDesc_s();
		int CreateInit();
		int ResumeInit();
		int32_t RoomID;
		int32_t GameID;
		NFSizeString<128> GameName;
		int32_t RoomType;
		NFSizeString<128> RoomName;
		int32_t SiteNum;
		int32_t DeskCount;
		int32_t MaxPeople;
		int64_t enter_min;
		int64_t enter_max;
		int32_t auto_chair;
		int32_t is_exp_scene;
		int64_t exp_scene_gold;
		int32_t robot_num;
		int32_t status;
		int32_t RoomLevel;
		int32_t Tax;
		int32_t StartTime;

		static void write_to_pbmsg(const struct GameRoomDesc_s & obj, ::proto_ff::GameRoomDesc & msg);
		static void read_from_pbmsg(const ::proto_ff::GameRoomDesc & msg, struct GameRoomDesc_s & obj);
		static ::proto_ff::GameRoomDesc* new_pbmsg(){ return new ::proto_ff::GameRoomDesc(); }
		static ::proto_ff::GameRoomDesc make_pbmsg(){ return ::proto_ff::GameRoomDesc(); }
	};
	typedef struct GameRoomDesc_s GameRoomDesc_t;

	struct Sheet_GameRoomDesc_s : public NFDescStoreSeqOP {
		Sheet_GameRoomDesc_s();
		int CreateInit();
		int ResumeInit();
		NFArray<struct GameRoomDesc_s, 100> GameRoomDesc_List;

		static void write_to_pbmsg(const struct Sheet_GameRoomDesc_s & obj, ::proto_ff::Sheet_GameRoomDesc & msg);
		static void read_from_pbmsg(const ::proto_ff::Sheet_GameRoomDesc & msg, struct Sheet_GameRoomDesc_s & obj);
		static ::proto_ff::Sheet_GameRoomDesc* new_pbmsg(){ return new ::proto_ff::Sheet_GameRoomDesc(); }
		static ::proto_ff::Sheet_GameRoomDesc make_pbmsg(){ return ::proto_ff::Sheet_GameRoomDesc(); }
	};
	typedef struct Sheet_GameRoomDesc_s Sheet_GameRoomDesc_t;

}

