#pragma once

#include <stdint.h>
#include <NFComm/NFShmCore/NFSizeString.h>
#include <NFComm/NFShmCore/NFArray.h>
#include <NFComm/NFShmCore/NFSeqOP.h>
#include <NFComm/NFShmCore/NFShmMgr.h>
#include "godHood.pb.h"
#include "godHood_s.h"

namespace proto_ff_s {

	struct godHoodgodHoodattributeDesc_s : public NFDescStoreSeqOP {
		godHoodgodHoodattributeDesc_s();
		int CreateInit();
		int ResumeInit();
		int32_t type;
		int32_t up;
		int32_t value;

		virtual void write_to_pbmsg(::proto_ff::godHoodgodHoodattributeDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::godHoodgodHoodattributeDesc & msg);
		static ::proto_ff::godHoodgodHoodattributeDesc* new_pbmsg(){ return new ::proto_ff::godHoodgodHoodattributeDesc(); }
		static ::proto_ff::godHoodgodHoodattributeDesc make_pbmsg(){ return ::proto_ff::godHoodgodHoodattributeDesc(); }
	};
	typedef struct godHoodgodHoodattributeDesc_s godHoodgodHoodattributeDesc_t;

	struct godHoodgodHood_s : public NFDescStoreSeqOP {
		godHoodgodHood_s();
		int CreateInit();
		int ResumeInit();
		int64_t id;
		int32_t type;
		int32_t attrNum;
		int32_t quality;
		int32_t lvUp;
		int32_t basicsExp;
		NFArray<struct godHoodgodHoodattributeDesc_s, 2> attribute;

		virtual void write_to_pbmsg(::proto_ff::godHoodgodHood & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::godHoodgodHood & msg);
		static ::proto_ff::godHoodgodHood* new_pbmsg(){ return new ::proto_ff::godHoodgodHood(); }
		static ::proto_ff::godHoodgodHood make_pbmsg(){ return ::proto_ff::godHoodgodHood(); }
	};
	typedef struct godHoodgodHood_s godHoodgodHood_t;

	struct Sheet_godHoodgodHood_s : public NFDescStoreSeqOP {
		Sheet_godHoodgodHood_s();
		int CreateInit();
		int ResumeInit();
		NFArray<struct godHoodgodHood_s, 200> godHoodgodHood_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_godHoodgodHood & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_godHoodgodHood & msg);
		static ::proto_ff::Sheet_godHoodgodHood* new_pbmsg(){ return new ::proto_ff::Sheet_godHoodgodHood(); }
		static ::proto_ff::Sheet_godHoodgodHood make_pbmsg(){ return ::proto_ff::Sheet_godHoodgodHood(); }
	};
	typedef struct Sheet_godHoodgodHood_s Sheet_godHoodgodHood_t;

	struct godHoodexp_s : public NFDescStoreSeqOP {
		godHoodexp_s();
		int CreateInit();
		int ResumeInit();
		int32_t lv;
		int32_t exp;

		virtual void write_to_pbmsg(::proto_ff::godHoodexp & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::godHoodexp & msg);
		static ::proto_ff::godHoodexp* new_pbmsg(){ return new ::proto_ff::godHoodexp(); }
		static ::proto_ff::godHoodexp make_pbmsg(){ return ::proto_ff::godHoodexp(); }
	};
	typedef struct godHoodexp_s godHoodexp_t;

	struct Sheet_godHoodexp_s : public NFDescStoreSeqOP {
		Sheet_godHoodexp_s();
		int CreateInit();
		int ResumeInit();
		NFArray<struct godHoodexp_s, 300> godHoodexp_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_godHoodexp & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_godHoodexp & msg);
		static ::proto_ff::Sheet_godHoodexp* new_pbmsg(){ return new ::proto_ff::Sheet_godHoodexp(); }
		static ::proto_ff::Sheet_godHoodexp make_pbmsg(){ return ::proto_ff::Sheet_godHoodexp(); }
	};
	typedef struct Sheet_godHoodexp_s Sheet_godHoodexp_t;

}

