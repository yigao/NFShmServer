#pragma once

#include <stdint.h>
#include <NFComm/NFShmCore/NFShmString.h>
#include <NFComm/NFShmStl/NFShmVector.h>
#include <NFComm/NFShmCore/NFSeqOP.h>
#include <NFComm/NFShmCore/NFShmMgr.h>
#include "area.pb.h"
#include "area_s.h"

#define DEFINE_SHEET_AREAAREA_E_AREAAREA_LIST_MAX_NUM 20
namespace proto_ff_s {

	struct E_AreaArea_s : public NFDescStoreSeqOP {
		E_AreaArea_s();
		virtual ~E_AreaArea_s(){}
		int CreateInit();
		int ResumeInit();
		int64_t m_id;
		int32_t m_subtype;
		int64_t m_belongtosceneid;
		int32_t m_shapetype;
		int32_t m_isnotice;

		virtual void write_to_pbmsg(::proto_ff::E_AreaArea & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_AreaArea & msg);
		static ::proto_ff::E_AreaArea* new_pbmsg(){ return new ::proto_ff::E_AreaArea(); }
		static ::proto_ff::E_AreaArea make_pbmsg(){ return ::proto_ff::E_AreaArea(); }
	};
	typedef struct E_AreaArea_s E_AreaArea_t;

	struct Sheet_AreaArea_s : public NFDescStoreSeqOP {
		Sheet_AreaArea_s();
		virtual ~Sheet_AreaArea_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_AreaArea_s, DEFINE_SHEET_AREAAREA_E_AREAAREA_LIST_MAX_NUM> E_AreaArea_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_AreaArea & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_AreaArea & msg);
		static ::proto_ff::Sheet_AreaArea* new_pbmsg(){ return new ::proto_ff::Sheet_AreaArea(); }
		static ::proto_ff::Sheet_AreaArea make_pbmsg(){ return ::proto_ff::Sheet_AreaArea(); }
	};
	typedef struct Sheet_AreaArea_s Sheet_AreaArea_t;

}

