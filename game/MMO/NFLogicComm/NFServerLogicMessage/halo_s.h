#pragma once

#include <stdint.h>
#include <NFComm/NFShmCore/NFShmString.h>
#include <NFComm/NFShmCore/NFArray.h>
#include <NFComm/NFShmCore/NFSeqOP.h>
#include <NFComm/NFShmCore/NFShmMgr.h>
#include "halo.pb.h"
#include "halo_s.h"

namespace proto_ff_s {

	struct halohaloattributeDesc_s : public NFDescStoreSeqOP {
		halohaloattributeDesc_s();
		virtual ~halohaloattributeDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t type;
		int32_t value;

		virtual void write_to_pbmsg(::proto_ff::halohaloattributeDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::halohaloattributeDesc & msg);
		static ::proto_ff::halohaloattributeDesc* new_pbmsg(){ return new ::proto_ff::halohaloattributeDesc(); }
		static ::proto_ff::halohaloattributeDesc make_pbmsg(){ return ::proto_ff::halohaloattributeDesc(); }
	};
	typedef struct halohaloattributeDesc_s halohaloattributeDesc_t;

	struct halohaloActiveAttributeDesc_s : public NFDescStoreSeqOP {
		halohaloActiveAttributeDesc_s();
		virtual ~halohaloActiveAttributeDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t type;
		int32_t value;

		virtual void write_to_pbmsg(::proto_ff::halohaloActiveAttributeDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::halohaloActiveAttributeDesc & msg);
		static ::proto_ff::halohaloActiveAttributeDesc* new_pbmsg(){ return new ::proto_ff::halohaloActiveAttributeDesc(); }
		static ::proto_ff::halohaloActiveAttributeDesc make_pbmsg(){ return ::proto_ff::halohaloActiveAttributeDesc(); }
	};
	typedef struct halohaloActiveAttributeDesc_s halohaloActiveAttributeDesc_t;

	struct halohalo_s : public NFDescStoreSeqOP {
		halohalo_s();
		virtual ~halohalo_s(){}
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
		NFArray<struct halohaloattributeDesc_s, 6> attribute;
		NFArray<struct halohaloActiveAttributeDesc_s, 6> ActiveAttribute;

		virtual void write_to_pbmsg(::proto_ff::halohalo & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::halohalo & msg);
		static ::proto_ff::halohalo* new_pbmsg(){ return new ::proto_ff::halohalo(); }
		static ::proto_ff::halohalo make_pbmsg(){ return ::proto_ff::halohalo(); }
	};
	typedef struct halohalo_s halohalo_t;

	struct Sheet_halohalo_s : public NFDescStoreSeqOP {
		Sheet_halohalo_s();
		virtual ~Sheet_halohalo_s(){}
		int CreateInit();
		int ResumeInit();
		NFArray<struct halohalo_s, 20> halohalo_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_halohalo & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_halohalo & msg);
		static ::proto_ff::Sheet_halohalo* new_pbmsg(){ return new ::proto_ff::Sheet_halohalo(); }
		static ::proto_ff::Sheet_halohalo make_pbmsg(){ return ::proto_ff::Sheet_halohalo(); }
	};
	typedef struct Sheet_halohalo_s Sheet_halohalo_t;

}

