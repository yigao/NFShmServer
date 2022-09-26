#pragma once

#include <stdint.h>
#include <NFComm/NFShmCore/NFSizeString.h>
#include <NFComm/NFShmCore/NFArray.h>
#include <NFComm/NFShmCore/NFSeqOP.h>
#include <NFComm/NFShmCore/NFShmMgr.h>
#include "taskreward.pb.h"
#include "taskreward_s.h"

namespace proto_ff_s {

	struct taskrewardtaskrewarditemDesc_s : public NFDescStoreSeqOP {
		taskrewardtaskrewarditemDesc_s();
		int CreateInit();
		int ResumeInit();
		int32_t bind;
		int64_t id;
		int32_t val;
		int32_t prof;

		virtual void write_to_pbmsg(::proto_ff::taskrewardtaskrewarditemDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::taskrewardtaskrewarditemDesc & msg);
		static ::proto_ff::taskrewardtaskrewarditemDesc* new_pbmsg(){ return new ::proto_ff::taskrewardtaskrewarditemDesc(); }
		static ::proto_ff::taskrewardtaskrewarditemDesc make_pbmsg(){ return ::proto_ff::taskrewardtaskrewarditemDesc(); }
	};
	typedef struct taskrewardtaskrewarditemDesc_s taskrewardtaskrewarditemDesc_t;

	struct taskrewardtaskrewardattrDesc_s : public NFDescStoreSeqOP {
		taskrewardtaskrewardattrDesc_s();
		int CreateInit();
		int ResumeInit();
		int64_t id;

		virtual void write_to_pbmsg(::proto_ff::taskrewardtaskrewardattrDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::taskrewardtaskrewardattrDesc & msg);
		static ::proto_ff::taskrewardtaskrewardattrDesc* new_pbmsg(){ return new ::proto_ff::taskrewardtaskrewardattrDesc(); }
		static ::proto_ff::taskrewardtaskrewardattrDesc make_pbmsg(){ return ::proto_ff::taskrewardtaskrewardattrDesc(); }
	};
	typedef struct taskrewardtaskrewardattrDesc_s taskrewardtaskrewardattrDesc_t;

	struct taskrewardtaskreward_s : public NFDescStoreSeqOP {
		taskrewardtaskreward_s();
		int CreateInit();
		int ResumeInit();
		int64_t id;
		int32_t taskType;
		int32_t lv;
		int32_t guildExp;
		int32_t guildPoint;
		NFArray<struct taskrewardtaskrewarditemDesc_s, 5> item;
		NFArray<struct taskrewardtaskrewardattrDesc_s, 5> attr;

		virtual void write_to_pbmsg(::proto_ff::taskrewardtaskreward & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::taskrewardtaskreward & msg);
		static ::proto_ff::taskrewardtaskreward* new_pbmsg(){ return new ::proto_ff::taskrewardtaskreward(); }
		static ::proto_ff::taskrewardtaskreward make_pbmsg(){ return ::proto_ff::taskrewardtaskreward(); }
	};
	typedef struct taskrewardtaskreward_s taskrewardtaskreward_t;

	struct Sheet_taskrewardtaskreward_s : public NFDescStoreSeqOP {
		Sheet_taskrewardtaskreward_s();
		int CreateInit();
		int ResumeInit();
		NFArray<struct taskrewardtaskreward_s, 4000> taskrewardtaskreward_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_taskrewardtaskreward & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_taskrewardtaskreward & msg);
		static ::proto_ff::Sheet_taskrewardtaskreward* new_pbmsg(){ return new ::proto_ff::Sheet_taskrewardtaskreward(); }
		static ::proto_ff::Sheet_taskrewardtaskreward make_pbmsg(){ return ::proto_ff::Sheet_taskrewardtaskreward(); }
	};
	typedef struct Sheet_taskrewardtaskreward_s Sheet_taskrewardtaskreward_t;

}

