#pragma once

#include <stdint.h>
#include <NFComm/NFShmStl/NFShmString.h>
#include <NFComm/NFShmStl/NFShmVector.h>
#include <NFComm/NFShmCore/NFSeqOP.h>
#include <NFComm/NFShmCore/NFShmMgr.h>
#include "E_Peractivity.pb.h"
#include "E_Peractivity_s.h"

#define DEFINE_SHEET_PERACTIVITYPERACTIVITY_E_PERACTIVITYPERACTIVITY_LIST_MAX_NUM 32
#define DEFINE_E_PERACTIVITYWEEK_M_WEEK_MAX_NUM 7
#define DEFINE_SHEET_PERACTIVITYWEEK_E_PERACTIVITYWEEK_LIST_MAX_NUM 32


namespace proto_ff_s {

	struct E_PeractivityPeractivity_s : public NFDescStoreSeqOP {
		E_PeractivityPeractivity_s();
		virtual ~E_PeractivityPeractivity_s(){}
		int CreateInit();
		int ResumeInit();
		int64_t m_activeid;//活动ID
		NFShmString<64> m_activename;//活动名称
		int32_t m_typeid;//类型ID
		int32_t m_functionid;//功能开放ID
		NFShmString<64> m_opeday;//开放日期
		NFShmString<64> m_closeday;//关闭日期
		int32_t m_serverdelaytime;//开服后多少天活动开启
		int32_t m_servertime;//开服后多少活动结束
		int32_t m_openingtime;//开启时长
		int32_t m_advancetime;//提前广播时间
		int32_t m_intervaltime;//广播间隔
		int32_t m_iscross;//是否跨服
		int32_t m_isfestvial;//是否限时活动

		virtual void write_to_pbmsg(::proto_ff::E_PeractivityPeractivity & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_PeractivityPeractivity & msg);
		static ::proto_ff::E_PeractivityPeractivity* new_pbmsg(){ return new ::proto_ff::E_PeractivityPeractivity(); }
		static ::proto_ff::E_PeractivityPeractivity make_pbmsg(){ return ::proto_ff::E_PeractivityPeractivity(); }
	};
	typedef struct E_PeractivityPeractivity_s E_PeractivityPeractivity_t;

	struct Sheet_PeractivityPeractivity_s : public NFDescStoreSeqOP {
		Sheet_PeractivityPeractivity_s();
		virtual ~Sheet_PeractivityPeractivity_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_PeractivityPeractivity_s, DEFINE_SHEET_PERACTIVITYPERACTIVITY_E_PERACTIVITYPERACTIVITY_LIST_MAX_NUM> E_PeractivityPeractivity_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_PeractivityPeractivity & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_PeractivityPeractivity & msg);
		static ::proto_ff::Sheet_PeractivityPeractivity* new_pbmsg(){ return new ::proto_ff::Sheet_PeractivityPeractivity(); }
		static ::proto_ff::Sheet_PeractivityPeractivity make_pbmsg(){ return ::proto_ff::Sheet_PeractivityPeractivity(); }
	};
	typedef struct Sheet_PeractivityPeractivity_s Sheet_PeractivityPeractivity_t;

	struct E_PeractivityWeek_s : public NFDescStoreSeqOP {
		E_PeractivityWeek_s();
		virtual ~E_PeractivityWeek_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//序号
		NFShmString<64> m_time;//时间
		NFShmVector<NFShmString<64>, DEFINE_E_PERACTIVITYWEEK_M_WEEK_MAX_NUM> m_week;//周

		virtual void write_to_pbmsg(::proto_ff::E_PeractivityWeek & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_PeractivityWeek & msg);
		static ::proto_ff::E_PeractivityWeek* new_pbmsg(){ return new ::proto_ff::E_PeractivityWeek(); }
		static ::proto_ff::E_PeractivityWeek make_pbmsg(){ return ::proto_ff::E_PeractivityWeek(); }
	};
	typedef struct E_PeractivityWeek_s E_PeractivityWeek_t;

	struct Sheet_PeractivityWeek_s : public NFDescStoreSeqOP {
		Sheet_PeractivityWeek_s();
		virtual ~Sheet_PeractivityWeek_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_PeractivityWeek_s, DEFINE_SHEET_PERACTIVITYWEEK_E_PERACTIVITYWEEK_LIST_MAX_NUM> E_PeractivityWeek_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_PeractivityWeek & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_PeractivityWeek & msg);
		static ::proto_ff::Sheet_PeractivityWeek* new_pbmsg(){ return new ::proto_ff::Sheet_PeractivityWeek(); }
		static ::proto_ff::Sheet_PeractivityWeek make_pbmsg(){ return ::proto_ff::Sheet_PeractivityWeek(); }
	};
	typedef struct Sheet_PeractivityWeek_s Sheet_PeractivityWeek_t;

}

