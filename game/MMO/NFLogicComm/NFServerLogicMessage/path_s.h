#pragma once

#include <stdint.h>
#include <NFComm/NFShmCore/NFShmString.h>
#include <NFComm/NFShmStl/NFShmVector.h>
#include <NFComm/NFShmCore/NFSeqOP.h>
#include <NFComm/NFShmCore/NFShmMgr.h>
#include "path.pb.h"
#include "path_s.h"

namespace proto_ff_s {

	struct E_PathPath_s : public NFDescStoreSeqOP {
		E_PathPath_s();
		virtual ~E_PathPath_s(){}
		int CreateInit();
		int ResumeInit();
		int64_t m_id;
		int64_t m_belongtosceneid;

		virtual void write_to_pbmsg(::proto_ff::E_PathPath & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_PathPath & msg);
		static ::proto_ff::E_PathPath* new_pbmsg(){ return new ::proto_ff::E_PathPath(); }
		static ::proto_ff::E_PathPath make_pbmsg(){ return ::proto_ff::E_PathPath(); }
	};
	typedef struct E_PathPath_s E_PathPath_t;

	struct Sheet_PathPath_s : public NFDescStoreSeqOP {
		Sheet_PathPath_s();
		virtual ~Sheet_PathPath_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_PathPath_s, 20> E_PathPath_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_PathPath & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_PathPath & msg);
		static ::proto_ff::Sheet_PathPath* new_pbmsg(){ return new ::proto_ff::Sheet_PathPath(); }
		static ::proto_ff::Sheet_PathPath make_pbmsg(){ return ::proto_ff::Sheet_PathPath(); }
	};
	typedef struct Sheet_PathPath_s Sheet_PathPath_t;

}

