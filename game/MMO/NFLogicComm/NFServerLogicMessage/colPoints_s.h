#pragma once

#include <stdint.h>
#include <NFComm/NFShmCore/NFSizeString.h>
#include <NFComm/NFShmCore/NFArray.h>
#include <NFComm/NFShmCore/NFSeqOP.h>
#include <NFComm/NFShmCore/NFShmMgr.h>
#include "colPoints.pb.h"
#include "colPoints_s.h"

namespace proto_ff_s {

	struct colPointscolPoints_s : public NFDescStoreSeqOP {
		colPointscolPoints_s();
		int CreateInit();
		int ResumeInit();
		int32_t id;
		int32_t weight;
		int64_t boxid;
		int32_t beginPoint;
		int32_t targetPoint;
		NFSizeString<32> taskID;

		virtual void write_to_pbmsg(::proto_ff::colPointscolPoints & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::colPointscolPoints & msg);
		static ::proto_ff::colPointscolPoints* new_pbmsg(){ return new ::proto_ff::colPointscolPoints(); }
		static ::proto_ff::colPointscolPoints make_pbmsg(){ return ::proto_ff::colPointscolPoints(); }
	};
	typedef struct colPointscolPoints_s colPointscolPoints_t;

	struct Sheet_colPointscolPoints_s : public NFDescStoreSeqOP {
		Sheet_colPointscolPoints_s();
		int CreateInit();
		int ResumeInit();
		NFArray<struct colPointscolPoints_s, 108> colPointscolPoints_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_colPointscolPoints & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_colPointscolPoints & msg);
		static ::proto_ff::Sheet_colPointscolPoints* new_pbmsg(){ return new ::proto_ff::Sheet_colPointscolPoints(); }
		static ::proto_ff::Sheet_colPointscolPoints make_pbmsg(){ return ::proto_ff::Sheet_colPointscolPoints(); }
	};
	typedef struct Sheet_colPointscolPoints_s Sheet_colPointscolPoints_t;

	struct colPointstask_s : public NFDescStoreSeqOP {
		colPointstask_s();
		int CreateInit();
		int ResumeInit();
		int32_t id;
		int32_t point;
		int32_t num;
		int32_t task;
		NFSizeString<32> taskParam;

		virtual void write_to_pbmsg(::proto_ff::colPointstask & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::colPointstask & msg);
		static ::proto_ff::colPointstask* new_pbmsg(){ return new ::proto_ff::colPointstask(); }
		static ::proto_ff::colPointstask make_pbmsg(){ return ::proto_ff::colPointstask(); }
	};
	typedef struct colPointstask_s colPointstask_t;

	struct Sheet_colPointstask_s : public NFDescStoreSeqOP {
		Sheet_colPointstask_s();
		int CreateInit();
		int ResumeInit();
		NFArray<struct colPointstask_s, 107> colPointstask_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_colPointstask & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_colPointstask & msg);
		static ::proto_ff::Sheet_colPointstask* new_pbmsg(){ return new ::proto_ff::Sheet_colPointstask(); }
		static ::proto_ff::Sheet_colPointstask make_pbmsg(){ return ::proto_ff::Sheet_colPointstask(); }
	};
	typedef struct Sheet_colPointstask_s Sheet_colPointstask_t;

}

