#pragma once

#include <stdint.h>
#include <NFComm/NFShmCore/NFSizeString.h>
#include <NFComm/NFShmCore/NFArray.h>
#include <NFComm/NFShmCore/NFSeqOP.h>
#include <NFComm/NFShmCore/NFShmMgr.h>
#include "wing.pb.h"
#include "wing_s.h"

namespace proto_ff_s {

	struct wingwingattributeDesc_s : public NFDescStoreSeqOP {
		wingwingattributeDesc_s();
		int CreateInit();
		int ResumeInit();
		int32_t type;
		int32_t value;

		virtual void write_to_pbmsg(::proto_ff::wingwingattributeDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::wingwingattributeDesc & msg);
		static ::proto_ff::wingwingattributeDesc* new_pbmsg(){ return new ::proto_ff::wingwingattributeDesc(); }
		static ::proto_ff::wingwingattributeDesc make_pbmsg(){ return ::proto_ff::wingwingattributeDesc(); }
	};
	typedef struct wingwingattributeDesc_s wingwingattributeDesc_t;

	struct wingwing_s : public NFDescStoreSeqOP {
		wingwing_s();
		int CreateInit();
		int ResumeInit();
		int64_t id;
		NFSizeString<60> resource;
		NFSizeString<60> name;
		NFSizeString<100> activeDesc;
		int32_t realLevel;
		int64_t materialID;
		int32_t materialEXP;
		int32_t exp;
		int64_t skillID;
		int64_t BreakMaterialID;
		int32_t BreakMaterialCost;
		NFArray<struct wingwingattributeDesc_s, 4> attribute;
		NFArray<int64_t, 3> fragmentID;

		virtual void write_to_pbmsg(::proto_ff::wingwing & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::wingwing & msg);
		static ::proto_ff::wingwing* new_pbmsg(){ return new ::proto_ff::wingwing(); }
		static ::proto_ff::wingwing make_pbmsg(){ return ::proto_ff::wingwing(); }
	};
	typedef struct wingwing_s wingwing_t;

	struct Sheet_wingwing_s : public NFDescStoreSeqOP {
		Sheet_wingwing_s();
		int CreateInit();
		int ResumeInit();
		NFArray<struct wingwing_s, 500> wingwing_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_wingwing & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_wingwing & msg);
		static ::proto_ff::Sheet_wingwing* new_pbmsg(){ return new ::proto_ff::Sheet_wingwing(); }
		static ::proto_ff::Sheet_wingwing make_pbmsg(){ return ::proto_ff::Sheet_wingwing(); }
	};
	typedef struct Sheet_wingwing_s Sheet_wingwing_t;

	struct wingchangeattributeDesc_s : public NFDescStoreSeqOP {
		wingchangeattributeDesc_s();
		int CreateInit();
		int ResumeInit();
		int32_t type;
		int32_t value;

		virtual void write_to_pbmsg(::proto_ff::wingchangeattributeDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::wingchangeattributeDesc & msg);
		static ::proto_ff::wingchangeattributeDesc* new_pbmsg(){ return new ::proto_ff::wingchangeattributeDesc(); }
		static ::proto_ff::wingchangeattributeDesc make_pbmsg(){ return ::proto_ff::wingchangeattributeDesc(); }
	};
	typedef struct wingchangeattributeDesc_s wingchangeattributeDesc_t;

	struct wingchange_s : public NFDescStoreSeqOP {
		wingchange_s();
		int CreateInit();
		int ResumeInit();
		int64_t id;
		NFSizeString<60> resource;
		NFSizeString<60> name;
		NFSizeString<160> activeDesc;
		int32_t quality;
		int64_t starId;
		NFSizeString<200> starNum;
		int32_t starUp;
		int32_t starBer;
		int64_t upAttributeId;
		NFArray<struct wingchangeattributeDesc_s, 5> attribute;

		virtual void write_to_pbmsg(::proto_ff::wingchange & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::wingchange & msg);
		static ::proto_ff::wingchange* new_pbmsg(){ return new ::proto_ff::wingchange(); }
		static ::proto_ff::wingchange make_pbmsg(){ return ::proto_ff::wingchange(); }
	};
	typedef struct wingchange_s wingchange_t;

	struct Sheet_wingchange_s : public NFDescStoreSeqOP {
		Sheet_wingchange_s();
		int CreateInit();
		int ResumeInit();
		NFArray<struct wingchange_s, 40> wingchange_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_wingchange & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_wingchange & msg);
		static ::proto_ff::Sheet_wingchange* new_pbmsg(){ return new ::proto_ff::Sheet_wingchange(); }
		static ::proto_ff::Sheet_wingchange make_pbmsg(){ return ::proto_ff::Sheet_wingchange(); }
	};
	typedef struct Sheet_wingchange_s Sheet_wingchange_t;

	struct wingfragmentattributeDesc_s : public NFDescStoreSeqOP {
		wingfragmentattributeDesc_s();
		int CreateInit();
		int ResumeInit();
		int32_t type;
		int32_t value;

		virtual void write_to_pbmsg(::proto_ff::wingfragmentattributeDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::wingfragmentattributeDesc & msg);
		static ::proto_ff::wingfragmentattributeDesc* new_pbmsg(){ return new ::proto_ff::wingfragmentattributeDesc(); }
		static ::proto_ff::wingfragmentattributeDesc make_pbmsg(){ return ::proto_ff::wingfragmentattributeDesc(); }
	};
	typedef struct wingfragmentattributeDesc_s wingfragmentattributeDesc_t;

	struct wingfragment_s : public NFDescStoreSeqOP {
		wingfragment_s();
		int CreateInit();
		int ResumeInit();
		int64_t fragmentID;
		int64_t item;
		int32_t itemNum;
		NFArray<struct wingfragmentattributeDesc_s, 3> attribute;

		virtual void write_to_pbmsg(::proto_ff::wingfragment & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::wingfragment & msg);
		static ::proto_ff::wingfragment* new_pbmsg(){ return new ::proto_ff::wingfragment(); }
		static ::proto_ff::wingfragment make_pbmsg(){ return ::proto_ff::wingfragment(); }
	};
	typedef struct wingfragment_s wingfragment_t;

	struct Sheet_wingfragment_s : public NFDescStoreSeqOP {
		Sheet_wingfragment_s();
		int CreateInit();
		int ResumeInit();
		NFArray<struct wingfragment_s, 20> wingfragment_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_wingfragment & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_wingfragment & msg);
		static ::proto_ff::Sheet_wingfragment* new_pbmsg(){ return new ::proto_ff::Sheet_wingfragment(); }
		static ::proto_ff::Sheet_wingfragment make_pbmsg(){ return ::proto_ff::Sheet_wingfragment(); }
	};
	typedef struct Sheet_wingfragment_s Sheet_wingfragment_t;

	struct wingstarUpupAttributeDesc_s : public NFDescStoreSeqOP {
		wingstarUpupAttributeDesc_s();
		int CreateInit();
		int ResumeInit();
		int32_t type;
		int32_t value;

		virtual void write_to_pbmsg(::proto_ff::wingstarUpupAttributeDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::wingstarUpupAttributeDesc & msg);
		static ::proto_ff::wingstarUpupAttributeDesc* new_pbmsg(){ return new ::proto_ff::wingstarUpupAttributeDesc(); }
		static ::proto_ff::wingstarUpupAttributeDesc make_pbmsg(){ return ::proto_ff::wingstarUpupAttributeDesc(); }
	};
	typedef struct wingstarUpupAttributeDesc_s wingstarUpupAttributeDesc_t;

	struct wingstarUp_s : public NFDescStoreSeqOP {
		wingstarUp_s();
		int CreateInit();
		int ResumeInit();
		int32_t ID;
		int64_t upAttributeId;
		int32_t starID;
		NFArray<struct wingstarUpupAttributeDesc_s, 2> upAttribute;

		virtual void write_to_pbmsg(::proto_ff::wingstarUp & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::wingstarUp & msg);
		static ::proto_ff::wingstarUp* new_pbmsg(){ return new ::proto_ff::wingstarUp(); }
		static ::proto_ff::wingstarUp make_pbmsg(){ return ::proto_ff::wingstarUp(); }
	};
	typedef struct wingstarUp_s wingstarUp_t;

	struct Sheet_wingstarUp_s : public NFDescStoreSeqOP {
		Sheet_wingstarUp_s();
		int CreateInit();
		int ResumeInit();
		NFArray<struct wingstarUp_s, 40> wingstarUp_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_wingstarUp & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_wingstarUp & msg);
		static ::proto_ff::Sheet_wingstarUp* new_pbmsg(){ return new ::proto_ff::Sheet_wingstarUp(); }
		static ::proto_ff::Sheet_wingstarUp make_pbmsg(){ return ::proto_ff::Sheet_wingstarUp(); }
	};
	typedef struct Sheet_wingstarUp_s Sheet_wingstarUp_t;

}

