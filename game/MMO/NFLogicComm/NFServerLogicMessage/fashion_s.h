#pragma once

#include <stdint.h>
#include <NFComm/NFShmCore/NFShmString.h>
#include <NFComm/NFShmCore/NFArray.h>
#include <NFComm/NFShmCore/NFSeqOP.h>
#include <NFComm/NFShmCore/NFShmMgr.h>
#include "fashion.pb.h"
#include "fashion_s.h"

namespace proto_ff_s {

	struct fashionfashionattributeDesc_s : public NFDescStoreSeqOP {
		fashionfashionattributeDesc_s();
		virtual ~fashionfashionattributeDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t type;
		int32_t value;

		virtual void write_to_pbmsg(::proto_ff::fashionfashionattributeDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::fashionfashionattributeDesc & msg);
		static ::proto_ff::fashionfashionattributeDesc* new_pbmsg(){ return new ::proto_ff::fashionfashionattributeDesc(); }
		static ::proto_ff::fashionfashionattributeDesc make_pbmsg(){ return ::proto_ff::fashionfashionattributeDesc(); }
	};
	typedef struct fashionfashionattributeDesc_s fashionfashionattributeDesc_t;

	struct fashionfashionActiveAttributeDesc_s : public NFDescStoreSeqOP {
		fashionfashionActiveAttributeDesc_s();
		virtual ~fashionfashionActiveAttributeDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t type;
		int32_t value;

		virtual void write_to_pbmsg(::proto_ff::fashionfashionActiveAttributeDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::fashionfashionActiveAttributeDesc & msg);
		static ::proto_ff::fashionfashionActiveAttributeDesc* new_pbmsg(){ return new ::proto_ff::fashionfashionActiveAttributeDesc(); }
		static ::proto_ff::fashionfashionActiveAttributeDesc make_pbmsg(){ return ::proto_ff::fashionfashionActiveAttributeDesc(); }
	};
	typedef struct fashionfashionActiveAttributeDesc_s fashionfashionActiveAttributeDesc_t;

	struct fashionfashion_s : public NFDescStoreSeqOP {
		fashionfashion_s();
		virtual ~fashionfashion_s(){}
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
		NFArray<struct fashionfashionattributeDesc_s, 5> attribute;
		NFArray<struct fashionfashionActiveAttributeDesc_s, 6> ActiveAttribute;

		virtual void write_to_pbmsg(::proto_ff::fashionfashion & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::fashionfashion & msg);
		static ::proto_ff::fashionfashion* new_pbmsg(){ return new ::proto_ff::fashionfashion(); }
		static ::proto_ff::fashionfashion make_pbmsg(){ return ::proto_ff::fashionfashion(); }
	};
	typedef struct fashionfashion_s fashionfashion_t;

	struct Sheet_fashionfashion_s : public NFDescStoreSeqOP {
		Sheet_fashionfashion_s();
		virtual ~Sheet_fashionfashion_s(){}
		int CreateInit();
		int ResumeInit();
		NFArray<struct fashionfashion_s, 20> fashionfashion_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_fashionfashion & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_fashionfashion & msg);
		static ::proto_ff::Sheet_fashionfashion* new_pbmsg(){ return new ::proto_ff::Sheet_fashionfashion(); }
		static ::proto_ff::Sheet_fashionfashion make_pbmsg(){ return ::proto_ff::Sheet_fashionfashion(); }
	};
	typedef struct Sheet_fashionfashion_s Sheet_fashionfashion_t;

}

