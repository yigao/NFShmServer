#pragma once

#include <stdint.h>
#include <NFComm/NFShmStl/NFShmString.h>
#include <NFComm/NFShmStl/NFShmVector.h>
#include <NFComm/NFShmCore/NFSeqOP.h>
#include <NFComm/NFShmCore/NFShmMgr.h>
#include "E_Fish.pb.h"
#include "E_Fish_s.h"

#define DEFINE_SHEET_FISHROOM_E_FISHROOM_LIST_MAX_NUM 32
#define DEFINE_SHEET_FISHGUNVALUE_E_FISHGUNVALUE_LIST_MAX_NUM 256
#define DEFINE_SHEET_FISHCTRLLEVEL_E_FISHCTRLLEVEL_LIST_MAX_NUM 16


namespace proto_ff_s {

	struct E_FishRoom_s : public NFDescStoreSeqOP {
		E_FishRoom_s();
		virtual ~E_FishRoom_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//唯一ID
		int32_t m_RoomId;//房间ID
		int32_t m_gameid;//游戏ID
		NFShmString<64> m_gamename;//游戏名
		int32_t m_roomtype;//房间类型
		int32_t m_roomlevel;//房间等级
		NFShmString<64> m_roomname;//房间名
		int32_t m_sitenum;//座位数
		int32_t m_deskcount;//桌子数
		int32_t m_maxpeople;//最大玩家数
		int32_t m_entermin;//最小筹码
		int32_t m_entermax;//最大筹码
		int32_t m_autochair;//选位置
		int32_t m_isexpscene;//体验场
		int32_t m_expscenegold;//体验场金币
		int32_t m_tax;//抽水率

		virtual void write_to_pbmsg(::proto_ff::E_FishRoom & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_FishRoom & msg);
		static ::proto_ff::E_FishRoom* new_pbmsg(){ return new ::proto_ff::E_FishRoom(); }
		static ::proto_ff::E_FishRoom make_pbmsg(){ return ::proto_ff::E_FishRoom(); }
	};
	typedef struct E_FishRoom_s E_FishRoom_t;

	struct Sheet_FishRoom_s : public NFDescStoreSeqOP {
		Sheet_FishRoom_s();
		virtual ~Sheet_FishRoom_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_FishRoom_s, DEFINE_SHEET_FISHROOM_E_FISHROOM_LIST_MAX_NUM> E_FishRoom_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_FishRoom & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_FishRoom & msg);
		static ::proto_ff::Sheet_FishRoom* new_pbmsg(){ return new ::proto_ff::Sheet_FishRoom(); }
		static ::proto_ff::Sheet_FishRoom make_pbmsg(){ return ::proto_ff::Sheet_FishRoom(); }
	};
	typedef struct Sheet_FishRoom_s Sheet_FishRoom_t;

	struct E_FishGunvalue_s : public NFDescStoreSeqOP {
		E_FishGunvalue_s();
		virtual ~E_FishGunvalue_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//唯一ID
		int32_t m_value;//值
		int32_t m_gameid;//游戏Id
		int32_t m_roomid;//房间ID
		int32_t m_gunid;//炮Id

		virtual void write_to_pbmsg(::proto_ff::E_FishGunvalue & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_FishGunvalue & msg);
		static ::proto_ff::E_FishGunvalue* new_pbmsg(){ return new ::proto_ff::E_FishGunvalue(); }
		static ::proto_ff::E_FishGunvalue make_pbmsg(){ return ::proto_ff::E_FishGunvalue(); }
	};
	typedef struct E_FishGunvalue_s E_FishGunvalue_t;

	struct Sheet_FishGunvalue_s : public NFDescStoreSeqOP {
		Sheet_FishGunvalue_s();
		virtual ~Sheet_FishGunvalue_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_FishGunvalue_s, DEFINE_SHEET_FISHGUNVALUE_E_FISHGUNVALUE_LIST_MAX_NUM> E_FishGunvalue_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_FishGunvalue & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_FishGunvalue & msg);
		static ::proto_ff::Sheet_FishGunvalue* new_pbmsg(){ return new ::proto_ff::Sheet_FishGunvalue(); }
		static ::proto_ff::Sheet_FishGunvalue make_pbmsg(){ return ::proto_ff::Sheet_FishGunvalue(); }
	};
	typedef struct Sheet_FishGunvalue_s Sheet_FishGunvalue_t;

	struct E_FishCtrllevel_s : public NFDescStoreSeqOP {
		E_FishCtrllevel_s();
		virtual ~E_FishCtrllevel_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_controllevel;//唯一ID
		int32_t m_controlrate;//控制概率

		virtual void write_to_pbmsg(::proto_ff::E_FishCtrllevel & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_FishCtrllevel & msg);
		static ::proto_ff::E_FishCtrllevel* new_pbmsg(){ return new ::proto_ff::E_FishCtrllevel(); }
		static ::proto_ff::E_FishCtrllevel make_pbmsg(){ return ::proto_ff::E_FishCtrllevel(); }
	};
	typedef struct E_FishCtrllevel_s E_FishCtrllevel_t;

	struct Sheet_FishCtrllevel_s : public NFDescStoreSeqOP {
		Sheet_FishCtrllevel_s();
		virtual ~Sheet_FishCtrllevel_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_FishCtrllevel_s, DEFINE_SHEET_FISHCTRLLEVEL_E_FISHCTRLLEVEL_LIST_MAX_NUM> E_FishCtrllevel_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_FishCtrllevel & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_FishCtrllevel & msg);
		static ::proto_ff::Sheet_FishCtrllevel* new_pbmsg(){ return new ::proto_ff::Sheet_FishCtrllevel(); }
		static ::proto_ff::Sheet_FishCtrllevel make_pbmsg(){ return ::proto_ff::Sheet_FishCtrllevel(); }
	};
	typedef struct Sheet_FishCtrllevel_s Sheet_FishCtrllevel_t;

}

