#pragma once

#include <stdint.h>
#include <NFComm/NFShmStl/NFShmString.h>
#include <NFComm/NFShmStl/NFShmVector.h>
#include <NFComm/NFShmCore/NFSeqOP.h>
#include <NFComm/NFShmCore/NFShmMgr.h>
#include "back.pb.h"
#include "back_s.h"

#define DEFINE_E_BACKBACK_M_PARAM_MAX_NUM 2
#define DEFINE_SHEET_BACKBACK_E_BACKBACK_LIST_MAX_NUM 20
namespace proto_ff_s {

	struct E_BackBack_s : public NFDescStoreSeqOP {
		E_BackBack_s();
		virtual ~E_BackBack_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;
		int32_t m_type;
		int32_t m_typeparam;
		NFShmString<60> m_name;
		int32_t m_group;
		int32_t m_functionunlock;
		int32_t m_levellimit;
		int64_t m_pboxid;
		int64_t m_boxid;
		int32_t m_backday;
		int32_t m_costitemid;
		int32_t m_costnum;
		int32_t m_pcostitemid;
		int32_t m_pcostnum;
		int32_t m_acostitemid;
		int32_t m_acostnum;
		NFShmVector<int32_t, DEFINE_E_BACKBACK_M_PARAM_MAX_NUM> m_param;

		virtual void write_to_pbmsg(::proto_ff::E_BackBack & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_BackBack & msg);
		static ::proto_ff::E_BackBack* new_pbmsg(){ return new ::proto_ff::E_BackBack(); }
		static ::proto_ff::E_BackBack make_pbmsg(){ return ::proto_ff::E_BackBack(); }
	};
	typedef struct E_BackBack_s E_BackBack_t;

	struct Sheet_BackBack_s : public NFDescStoreSeqOP {
		Sheet_BackBack_s();
		virtual ~Sheet_BackBack_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_BackBack_s, DEFINE_SHEET_BACKBACK_E_BACKBACK_LIST_MAX_NUM> E_BackBack_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_BackBack & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_BackBack & msg);
		static ::proto_ff::Sheet_BackBack* new_pbmsg(){ return new ::proto_ff::Sheet_BackBack(); }
		static ::proto_ff::Sheet_BackBack make_pbmsg(){ return ::proto_ff::Sheet_BackBack(); }
	};
	typedef struct Sheet_BackBack_s Sheet_BackBack_t;

}

