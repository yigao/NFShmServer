#pragma once

#include <stdint.h>
#include <NFComm/NFShmCore/NFSizeString.h>
#include <NFComm/NFShmCore/NFArray.h>
#include <NFComm/NFShmCore/NFSeqOP.h>
#include <NFComm/NFShmCore/NFShmMgr.h>
#include "handbook.pb.h"
#include "handbook_s.h"

namespace proto_ff_s {

	struct handbookhandbookattributeDesc_s : public NFDescStoreSeqOP {
		handbookhandbookattributeDesc_s();
		int CreateInit();
		int ResumeInit();
		int32_t type;
		int64_t value;

		virtual void write_to_pbmsg(::proto_ff::handbookhandbookattributeDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::handbookhandbookattributeDesc & msg);
		static ::proto_ff::handbookhandbookattributeDesc* new_pbmsg(){ return new ::proto_ff::handbookhandbookattributeDesc(); }
		static ::proto_ff::handbookhandbookattributeDesc make_pbmsg(){ return ::proto_ff::handbookhandbookattributeDesc(); }
	};
	typedef struct handbookhandbookattributeDesc_s handbookhandbookattributeDesc_t;

	struct handbookhandbook_s : public NFDescStoreSeqOP {
		handbookhandbook_s();
		int CreateInit();
		int ResumeInit();
		int64_t handbookID;
		int64_t itemId;
		NFSizeString<32> handbookName;
		int32_t handbookType;
		int32_t handbookQuality;
		int32_t handbookLv;
		int32_t handZ;
		int64_t starId;
		NFSizeString<201> starNum;
		NFArray<struct handbookhandbookattributeDesc_s, 4> attribute;

		virtual void write_to_pbmsg(::proto_ff::handbookhandbook & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::handbookhandbook & msg);
		static ::proto_ff::handbookhandbook* new_pbmsg(){ return new ::proto_ff::handbookhandbook(); }
		static ::proto_ff::handbookhandbook make_pbmsg(){ return ::proto_ff::handbookhandbook(); }
	};
	typedef struct handbookhandbook_s handbookhandbook_t;

	struct Sheet_handbookhandbook_s : public NFDescStoreSeqOP {
		Sheet_handbookhandbook_s();
		int CreateInit();
		int ResumeInit();
		NFArray<struct handbookhandbook_s, 504> handbookhandbook_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_handbookhandbook & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_handbookhandbook & msg);
		static ::proto_ff::Sheet_handbookhandbook* new_pbmsg(){ return new ::proto_ff::Sheet_handbookhandbook(); }
		static ::proto_ff::Sheet_handbookhandbook make_pbmsg(){ return ::proto_ff::Sheet_handbookhandbook(); }
	};
	typedef struct Sheet_handbookhandbook_s Sheet_handbookhandbook_t;

	struct handbookfateattributeDesc_s : public NFDescStoreSeqOP {
		handbookfateattributeDesc_s();
		int CreateInit();
		int ResumeInit();
		int32_t type;
		int64_t value;

		virtual void write_to_pbmsg(::proto_ff::handbookfateattributeDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::handbookfateattributeDesc & msg);
		static ::proto_ff::handbookfateattributeDesc* new_pbmsg(){ return new ::proto_ff::handbookfateattributeDesc(); }
		static ::proto_ff::handbookfateattributeDesc make_pbmsg(){ return ::proto_ff::handbookfateattributeDesc(); }
	};
	typedef struct handbookfateattributeDesc_s handbookfateattributeDesc_t;

	struct handbookfate_s : public NFDescStoreSeqOP {
		handbookfate_s();
		int CreateInit();
		int ResumeInit();
		int64_t fateID;
		NFSizeString<32> fateName;
		int32_t starLv;
		NFArray<struct handbookfateattributeDesc_s, 4> attribute;

		virtual void write_to_pbmsg(::proto_ff::handbookfate & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::handbookfate & msg);
		static ::proto_ff::handbookfate* new_pbmsg(){ return new ::proto_ff::handbookfate(); }
		static ::proto_ff::handbookfate make_pbmsg(){ return ::proto_ff::handbookfate(); }
	};
	typedef struct handbookfate_s handbookfate_t;

	struct Sheet_handbookfate_s : public NFDescStoreSeqOP {
		Sheet_handbookfate_s();
		int CreateInit();
		int ResumeInit();
		NFArray<struct handbookfate_s, 129> handbookfate_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_handbookfate & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_handbookfate & msg);
		static ::proto_ff::Sheet_handbookfate* new_pbmsg(){ return new ::proto_ff::Sheet_handbookfate(); }
		static ::proto_ff::Sheet_handbookfate make_pbmsg(){ return ::proto_ff::Sheet_handbookfate(); }
	};
	typedef struct Sheet_handbookfate_s Sheet_handbookfate_t;

	struct handbookattr_s : public NFDescStoreSeqOP {
		handbookattr_s();
		int CreateInit();
		int ResumeInit();
		int64_t attID;

		virtual void write_to_pbmsg(::proto_ff::handbookattr & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::handbookattr & msg);
		static ::proto_ff::handbookattr* new_pbmsg(){ return new ::proto_ff::handbookattr(); }
		static ::proto_ff::handbookattr make_pbmsg(){ return ::proto_ff::handbookattr(); }
	};
	typedef struct handbookattr_s handbookattr_t;

	struct Sheet_handbookattr_s : public NFDescStoreSeqOP {
		Sheet_handbookattr_s();
		int CreateInit();
		int ResumeInit();
		NFArray<struct handbookattr_s, 599> handbookattr_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_handbookattr & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_handbookattr & msg);
		static ::proto_ff::Sheet_handbookattr* new_pbmsg(){ return new ::proto_ff::Sheet_handbookattr(); }
		static ::proto_ff::Sheet_handbookattr make_pbmsg(){ return ::proto_ff::Sheet_handbookattr(); }
	};
	typedef struct Sheet_handbookattr_s Sheet_handbookattr_t;

}

