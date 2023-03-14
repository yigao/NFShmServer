#pragma once

#include <stdint.h>
#include <NFComm/NFShmCore/NFShmString.h>
#include <NFComm/NFShmStl/NFShmVector.h>
#include <NFComm/NFShmCore/NFSeqOP.h>
#include <NFComm/NFShmCore/NFShmMgr.h>
#include "point.pb.h"
#include "point_s.h"

#define DEFINE_SHEET_POINTPOINT_E_POINTPOINT_LIST_MAX_NUM 400
namespace proto_ff_s {

	struct E_PointPoint_s : public NFDescStoreSeqOP {
		E_PointPoint_s();
		virtual ~E_PointPoint_s(){}
		int CreateInit();
		int ResumeInit();
		int64_t m_id;
		int64_t m_belongtosceneid;

		virtual void write_to_pbmsg(::proto_ff::E_PointPoint & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_PointPoint & msg);
		static ::proto_ff::E_PointPoint* new_pbmsg(){ return new ::proto_ff::E_PointPoint(); }
		static ::proto_ff::E_PointPoint make_pbmsg(){ return ::proto_ff::E_PointPoint(); }
	};
	typedef struct E_PointPoint_s E_PointPoint_t;

	struct Sheet_PointPoint_s : public NFDescStoreSeqOP {
		Sheet_PointPoint_s();
		virtual ~Sheet_PointPoint_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_PointPoint_s, DEFINE_SHEET_POINTPOINT_E_POINTPOINT_LIST_MAX_NUM> E_PointPoint_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_PointPoint & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_PointPoint & msg);
		static ::proto_ff::Sheet_PointPoint* new_pbmsg(){ return new ::proto_ff::Sheet_PointPoint(); }
		static ::proto_ff::Sheet_PointPoint make_pbmsg(){ return ::proto_ff::Sheet_PointPoint(); }
	};
	typedef struct Sheet_PointPoint_s Sheet_PointPoint_t;

}

