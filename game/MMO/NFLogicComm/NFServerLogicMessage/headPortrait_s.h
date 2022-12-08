#pragma once

#include <stdint.h>
#include <NFComm/NFShmCore/NFShmString.h>
#include <NFComm/NFShmCore/NFArray.h>
#include <NFComm/NFShmCore/NFSeqOP.h>
#include <NFComm/NFShmCore/NFShmMgr.h>
#include "headPortrait.pb.h"
#include "headPortrait_s.h"

namespace proto_ff_s {

	struct headPortraitheadattributeDesc_s : public NFDescStoreSeqOP {
		headPortraitheadattributeDesc_s();
		virtual ~headPortraitheadattributeDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t type;
		int32_t value;

		virtual void write_to_pbmsg(::proto_ff::headPortraitheadattributeDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::headPortraitheadattributeDesc & msg);
		static ::proto_ff::headPortraitheadattributeDesc* new_pbmsg(){ return new ::proto_ff::headPortraitheadattributeDesc(); }
		static ::proto_ff::headPortraitheadattributeDesc make_pbmsg(){ return ::proto_ff::headPortraitheadattributeDesc(); }
	};
	typedef struct headPortraitheadattributeDesc_s headPortraitheadattributeDesc_t;

	struct headPortraitheadActiveAttributeDesc_s : public NFDescStoreSeqOP {
		headPortraitheadActiveAttributeDesc_s();
		virtual ~headPortraitheadActiveAttributeDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t type;
		int32_t value;

		virtual void write_to_pbmsg(::proto_ff::headPortraitheadActiveAttributeDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::headPortraitheadActiveAttributeDesc & msg);
		static ::proto_ff::headPortraitheadActiveAttributeDesc* new_pbmsg(){ return new ::proto_ff::headPortraitheadActiveAttributeDesc(); }
		static ::proto_ff::headPortraitheadActiveAttributeDesc make_pbmsg(){ return ::proto_ff::headPortraitheadActiveAttributeDesc(); }
	};
	typedef struct headPortraitheadActiveAttributeDesc_s headPortraitheadActiveAttributeDesc_t;

	struct headPortraithead_s : public NFDescStoreSeqOP {
		headPortraithead_s();
		virtual ~headPortraithead_s(){}
		int CreateInit();
		int ResumeInit();
		int64_t ID;
		NFShmString<60> name;
		int32_t type;
		int32_t quality;
		NFShmString<60> professionLimit;
		int64_t activationItem;
		int32_t activationNum;
		int64_t starId;
		NFShmString<300> starNum;
		int32_t starUp;
		int32_t starBer;
		NFArray<struct headPortraitheadattributeDesc_s, 6> attribute;
		NFArray<struct headPortraitheadActiveAttributeDesc_s, 6> ActiveAttribute;

		virtual void write_to_pbmsg(::proto_ff::headPortraithead & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::headPortraithead & msg);
		static ::proto_ff::headPortraithead* new_pbmsg(){ return new ::proto_ff::headPortraithead(); }
		static ::proto_ff::headPortraithead make_pbmsg(){ return ::proto_ff::headPortraithead(); }
	};
	typedef struct headPortraithead_s headPortraithead_t;

	struct Sheet_headPortraithead_s : public NFDescStoreSeqOP {
		Sheet_headPortraithead_s();
		virtual ~Sheet_headPortraithead_s(){}
		int CreateInit();
		int ResumeInit();
		NFArray<struct headPortraithead_s, 100> headPortraithead_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_headPortraithead & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_headPortraithead & msg);
		static ::proto_ff::Sheet_headPortraithead* new_pbmsg(){ return new ::proto_ff::Sheet_headPortraithead(); }
		static ::proto_ff::Sheet_headPortraithead make_pbmsg(){ return ::proto_ff::Sheet_headPortraithead(); }
	};
	typedef struct Sheet_headPortraithead_s Sheet_headPortraithead_t;

}

