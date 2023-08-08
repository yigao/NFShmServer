#pragma once

#include <stdint.h>
#include <NFComm/NFShmStl/NFShmString.h>
#include <NFComm/NFShmStl/NFShmVector.h>
#include <NFComm/NFShmCore/NFSeqOP.h>
#include <NFComm/NFShmCore/NFShmMgr.h>
#include "room.pb.h"
#include "room_s.h"

#define DEFINE_SHEET_ROOMROOM_E_ROOMROOM_LIST_MAX_NUM 8
namespace proto_ff_s {

	struct E_RoomRoom_s : public NFDescStoreSeqOP {
		E_RoomRoom_s();
		virtual ~E_RoomRoom_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;
		int32_t m_roomid;
		int32_t m_gameid;
		NFShmString<64> m_gamename;
		int32_t m_roomtype;
		int32_t m_roomlevel;
		NFShmString<64> m_roomname;
		int32_t m_sitenum;
		int32_t m_deskcount;
		int32_t m_maxpeople;
		int32_t m_enter_min;
		int32_t m_enter_max;
		int32_t m_auto_chair;
		int32_t m_is_exp_scene;
		int32_t m_exp_scene_gold;
		int32_t m_tax;

		virtual void write_to_pbmsg(::proto_ff::E_RoomRoom & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_RoomRoom & msg);
		static ::proto_ff::E_RoomRoom* new_pbmsg(){ return new ::proto_ff::E_RoomRoom(); }
		static ::proto_ff::E_RoomRoom make_pbmsg(){ return ::proto_ff::E_RoomRoom(); }
	};
	typedef struct E_RoomRoom_s E_RoomRoom_t;

	struct Sheet_RoomRoom_s : public NFDescStoreSeqOP {
		Sheet_RoomRoom_s();
		virtual ~Sheet_RoomRoom_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_RoomRoom_s, DEFINE_SHEET_ROOMROOM_E_ROOMROOM_LIST_MAX_NUM> E_RoomRoom_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_RoomRoom & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_RoomRoom & msg);
		static ::proto_ff::Sheet_RoomRoom* new_pbmsg(){ return new ::proto_ff::Sheet_RoomRoom(); }
		static ::proto_ff::Sheet_RoomRoom make_pbmsg(){ return ::proto_ff::Sheet_RoomRoom(); }
	};
	typedef struct Sheet_RoomRoom_s Sheet_RoomRoom_t;

}

