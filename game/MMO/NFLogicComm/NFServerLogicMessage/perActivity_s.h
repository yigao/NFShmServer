#pragma once

#include <stdint.h>
#include <NFComm/NFShmCore/NFShmString.h>
#include <NFComm/NFShmStl/NFShmVector.h>
#include <NFComm/NFShmCore/NFSeqOP.h>
#include <NFComm/NFShmCore/NFShmMgr.h>
#include "perActivity.pb.h"
#include "perActivity_s.h"

#define DEFINE_SHEET_PERACTIVITYPERACTIVITY_E_PERACTIVITYPERACTIVITY_LIST_MAX_NUM 20
#define DEFINE_E_PERACTIVITYWEEK_M_WEEK_MAX_NUM 7
#define DEFINE_SHEET_PERACTIVITYWEEK_E_PERACTIVITYWEEK_LIST_MAX_NUM 20
namespace proto_ff_s {

	struct E_PeractivityPeractivity_s : public NFDescStoreSeqOP {
		E_PeractivityPeractivity_s();
		virtual ~E_PeractivityPeractivity_s(){}
		int CreateInit();
		int ResumeInit();
		int64_t m_activeid;
		NFShmString<60> m_activename;
		int32_t m_typeid;
		int32_t m_functionid;
		NFShmString<60> m_opeday;
		NFShmString<60> m_closeday;
		int32_t m_serverdelaytime;
		int32_t m_servertime;
		int32_t m_openingtime;
		int32_t m_advancetime;
		int32_t m_intervaltime;
		int32_t m_iscross;

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
		NFShmVector<struct E_PeractivityPeractivity_s, DEFINE_SHEET_PERACTIVITYPERACTIVITY_E_PERACTIVITYPERACTIVITY_LIST_MAX_NUM> E_PeractivityPeractivity_List;

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
		int32_t m_id;
		NFShmString<60> m_time;
		NFShmVector<NFShmString<60>, DEFINE_E_PERACTIVITYWEEK_M_WEEK_MAX_NUM> m_week;

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
		NFShmVector<struct E_PeractivityWeek_s, DEFINE_SHEET_PERACTIVITYWEEK_E_PERACTIVITYWEEK_LIST_MAX_NUM> E_PeractivityWeek_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_PeractivityWeek & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_PeractivityWeek & msg);
		static ::proto_ff::Sheet_PeractivityWeek* new_pbmsg(){ return new ::proto_ff::Sheet_PeractivityWeek(); }
		static ::proto_ff::Sheet_PeractivityWeek make_pbmsg(){ return ::proto_ff::Sheet_PeractivityWeek(); }
	};
	typedef struct Sheet_PeractivityWeek_s Sheet_PeractivityWeek_t;

}

