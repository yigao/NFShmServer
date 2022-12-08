#pragma once

#include <stdint.h>
#include <NFComm/NFShmCore/NFShmString.h>
#include <NFComm/NFShmCore/NFArray.h>
#include <NFComm/NFShmCore/NFSeqOP.h>
#include <NFComm/NFShmCore/NFShmMgr.h>
#include "point.pb.h"
#include "point_s.h"

namespace proto_ff_s {

	struct pointpoint_s : public NFDescStoreSeqOP {
		pointpoint_s();
		virtual ~pointpoint_s(){}
		int CreateInit();
		int ResumeInit();
		int64_t id;
		int64_t belongToSceneID;

		virtual void write_to_pbmsg(::proto_ff::pointpoint & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::pointpoint & msg);
		static ::proto_ff::pointpoint* new_pbmsg(){ return new ::proto_ff::pointpoint(); }
		static ::proto_ff::pointpoint make_pbmsg(){ return ::proto_ff::pointpoint(); }
	};
	typedef struct pointpoint_s pointpoint_t;

	struct Sheet_pointpoint_s : public NFDescStoreSeqOP {
		Sheet_pointpoint_s();
		virtual ~Sheet_pointpoint_s(){}
		int CreateInit();
		int ResumeInit();
		NFArray<struct pointpoint_s, 100> pointpoint_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_pointpoint & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_pointpoint & msg);
		static ::proto_ff::Sheet_pointpoint* new_pbmsg(){ return new ::proto_ff::Sheet_pointpoint(); }
		static ::proto_ff::Sheet_pointpoint make_pbmsg(){ return ::proto_ff::Sheet_pointpoint(); }
	};
	typedef struct Sheet_pointpoint_s Sheet_pointpoint_t;

}

