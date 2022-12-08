#pragma once

#include <stdint.h>
#include <NFComm/NFShmCore/NFShmString.h>
#include <NFComm/NFShmCore/NFArray.h>
#include <NFComm/NFShmCore/NFSeqOP.h>
#include <NFComm/NFShmCore/NFShmMgr.h>
#include "taskreward.pb.h"
#include "taskreward_s.h"

namespace proto_ff_s {

	struct taskrewardtaskrewarditemDesc_s : public NFDescStoreSeqOP {
		taskrewardtaskrewarditemDesc_s();
		virtual ~taskrewardtaskrewarditemDesc_s(){}
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
		virtual ~taskrewardtaskrewardattrDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int64_t id;
		int64_t val;

		virtual void write_to_pbmsg(::proto_ff::taskrewardtaskrewardattrDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::taskrewardtaskrewardattrDesc & msg);
		static ::proto_ff::taskrewardtaskrewardattrDesc* new_pbmsg(){ return new ::proto_ff::taskrewardtaskrewardattrDesc(); }
		static ::proto_ff::taskrewardtaskrewardattrDesc make_pbmsg(){ return ::proto_ff::taskrewardtaskrewardattrDesc(); }
	};
	typedef struct taskrewardtaskrewardattrDesc_s taskrewardtaskrewardattrDesc_t;

	struct taskrewardtaskreward_s : public NFDescStoreSeqOP {
		taskrewardtaskreward_s();
		virtual ~taskrewardtaskreward_s(){}
		int CreateInit();
		int ResumeInit();
		int64_t id;
		int32_t taskType;
		int32_t lv;
		int32_t guildExp;
		int32_t guildPoint;
		int32_t skillId;
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
		virtual ~Sheet_taskrewardtaskreward_s(){}
		int CreateInit();
		int ResumeInit();
		NFArray<struct taskrewardtaskreward_s, 200> taskrewardtaskreward_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_taskrewardtaskreward & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_taskrewardtaskreward & msg);
		static ::proto_ff::Sheet_taskrewardtaskreward* new_pbmsg(){ return new ::proto_ff::Sheet_taskrewardtaskreward(); }
		static ::proto_ff::Sheet_taskrewardtaskreward make_pbmsg(){ return ::proto_ff::Sheet_taskrewardtaskreward(); }
	};
	typedef struct Sheet_taskrewardtaskreward_s Sheet_taskrewardtaskreward_t;

	struct taskrewardtasktype_s : public NFDescStoreSeqOP {
		taskrewardtasktype_s();
		virtual ~taskrewardtasktype_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t taskType;

		virtual void write_to_pbmsg(::proto_ff::taskrewardtasktype & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::taskrewardtasktype & msg);
		static ::proto_ff::taskrewardtasktype* new_pbmsg(){ return new ::proto_ff::taskrewardtasktype(); }
		static ::proto_ff::taskrewardtasktype make_pbmsg(){ return ::proto_ff::taskrewardtasktype(); }
	};
	typedef struct taskrewardtasktype_s taskrewardtasktype_t;

	struct Sheet_taskrewardtasktype_s : public NFDescStoreSeqOP {
		Sheet_taskrewardtasktype_s();
		virtual ~Sheet_taskrewardtasktype_s(){}
		int CreateInit();
		int ResumeInit();
		NFArray<struct taskrewardtasktype_s, 20> taskrewardtasktype_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_taskrewardtasktype & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_taskrewardtasktype & msg);
		static ::proto_ff::Sheet_taskrewardtasktype* new_pbmsg(){ return new ::proto_ff::Sheet_taskrewardtasktype(); }
		static ::proto_ff::Sheet_taskrewardtasktype make_pbmsg(){ return ::proto_ff::Sheet_taskrewardtasktype(); }
	};
	typedef struct Sheet_taskrewardtasktype_s Sheet_taskrewardtasktype_t;

}

