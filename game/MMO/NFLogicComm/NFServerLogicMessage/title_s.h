#pragma once

#include <stdint.h>
#include <NFComm/NFShmCore/NFSizeString.h>
#include <NFComm/NFShmCore/NFArray.h>
#include <NFComm/NFShmCore/NFSeqOP.h>
#include <NFComm/NFShmCore/NFShmMgr.h>
#include "title.pb.h"
#include "title_s.h"

namespace proto_ff_s {

	struct titletype_s : public NFDescStoreSeqOP {
		titletype_s();
		int CreateInit();
		int ResumeInit();
		int32_t type;

		virtual void write_to_pbmsg(::proto_ff::titletype & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::titletype & msg);
		static ::proto_ff::titletype* new_pbmsg(){ return new ::proto_ff::titletype(); }
		static ::proto_ff::titletype make_pbmsg(){ return ::proto_ff::titletype(); }
	};
	typedef struct titletype_s titletype_t;

	struct Sheet_titletype_s : public NFDescStoreSeqOP {
		Sheet_titletype_s();
		int CreateInit();
		int ResumeInit();
		NFArray<struct titletype_s, 109> titletype_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_titletype & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_titletype & msg);
		static ::proto_ff::Sheet_titletype* new_pbmsg(){ return new ::proto_ff::Sheet_titletype(); }
		static ::proto_ff::Sheet_titletype make_pbmsg(){ return ::proto_ff::Sheet_titletype(); }
	};
	typedef struct Sheet_titletype_s Sheet_titletype_t;

	struct titletitleattributeDesc_s : public NFDescStoreSeqOP {
		titletitleattributeDesc_s();
		int CreateInit();
		int ResumeInit();
		int32_t type;
		int32_t value;

		virtual void write_to_pbmsg(::proto_ff::titletitleattributeDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::titletitleattributeDesc & msg);
		static ::proto_ff::titletitleattributeDesc* new_pbmsg(){ return new ::proto_ff::titletitleattributeDesc(); }
		static ::proto_ff::titletitleattributeDesc make_pbmsg(){ return ::proto_ff::titletitleattributeDesc(); }
	};
	typedef struct titletitleattributeDesc_s titletitleattributeDesc_t;

	struct titletitle_s : public NFDescStoreSeqOP {
		titletitle_s();
		int CreateInit();
		int ResumeInit();
		int64_t id;
		NFSizeString<32> name;
		int32_t type;
		int32_t subType;
		NFSizeString<32> eventValue;
		NFSizeString<61> describe;
		int32_t addTime;
		int32_t lifeTime;
		NFArray<struct titletitleattributeDesc_s, 4> attribute;

		virtual void write_to_pbmsg(::proto_ff::titletitle & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::titletitle & msg);
		static ::proto_ff::titletitle* new_pbmsg(){ return new ::proto_ff::titletitle(); }
		static ::proto_ff::titletitle make_pbmsg(){ return ::proto_ff::titletitle(); }
	};
	typedef struct titletitle_s titletitle_t;

	struct Sheet_titletitle_s : public NFDescStoreSeqOP {
		Sheet_titletitle_s();
		int CreateInit();
		int ResumeInit();
		NFArray<struct titletitle_s, 169> titletitle_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_titletitle & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_titletitle & msg);
		static ::proto_ff::Sheet_titletitle* new_pbmsg(){ return new ::proto_ff::Sheet_titletitle(); }
		static ::proto_ff::Sheet_titletitle make_pbmsg(){ return ::proto_ff::Sheet_titletitle(); }
	};
	typedef struct Sheet_titletitle_s Sheet_titletitle_t;

}

