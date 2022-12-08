#pragma once

#include <stdint.h>
#include <NFComm/NFShmCore/NFShmString.h>
#include <NFComm/NFShmCore/NFArray.h>
#include <NFComm/NFShmCore/NFSeqOP.h>
#include <NFComm/NFShmCore/NFShmMgr.h>
#include "decorate.pb.h"
#include "decorate_s.h"

namespace proto_ff_s {

	struct decoratedecorateattributeDesc_s : public NFDescStoreSeqOP {
		decoratedecorateattributeDesc_s();
		virtual ~decoratedecorateattributeDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t type;
		int32_t value;

		virtual void write_to_pbmsg(::proto_ff::decoratedecorateattributeDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::decoratedecorateattributeDesc & msg);
		static ::proto_ff::decoratedecorateattributeDesc* new_pbmsg(){ return new ::proto_ff::decoratedecorateattributeDesc(); }
		static ::proto_ff::decoratedecorateattributeDesc make_pbmsg(){ return ::proto_ff::decoratedecorateattributeDesc(); }
	};
	typedef struct decoratedecorateattributeDesc_s decoratedecorateattributeDesc_t;

	struct decoratedecorateActiveAttributeDesc_s : public NFDescStoreSeqOP {
		decoratedecorateActiveAttributeDesc_s();
		virtual ~decoratedecorateActiveAttributeDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t type;
		int32_t value;

		virtual void write_to_pbmsg(::proto_ff::decoratedecorateActiveAttributeDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::decoratedecorateActiveAttributeDesc & msg);
		static ::proto_ff::decoratedecorateActiveAttributeDesc* new_pbmsg(){ return new ::proto_ff::decoratedecorateActiveAttributeDesc(); }
		static ::proto_ff::decoratedecorateActiveAttributeDesc make_pbmsg(){ return ::proto_ff::decoratedecorateActiveAttributeDesc(); }
	};
	typedef struct decoratedecorateActiveAttributeDesc_s decoratedecorateActiveAttributeDesc_t;

	struct decoratedecorate_s : public NFDescStoreSeqOP {
		decoratedecorate_s();
		virtual ~decoratedecorate_s(){}
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
		NFShmString<200> starNum;
		int32_t starUp;
		int32_t starBer;
		NFArray<struct decoratedecorateattributeDesc_s, 6> attribute;
		NFArray<struct decoratedecorateActiveAttributeDesc_s, 6> ActiveAttribute;

		virtual void write_to_pbmsg(::proto_ff::decoratedecorate & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::decoratedecorate & msg);
		static ::proto_ff::decoratedecorate* new_pbmsg(){ return new ::proto_ff::decoratedecorate(); }
		static ::proto_ff::decoratedecorate make_pbmsg(){ return ::proto_ff::decoratedecorate(); }
	};
	typedef struct decoratedecorate_s decoratedecorate_t;

	struct Sheet_decoratedecorate_s : public NFDescStoreSeqOP {
		Sheet_decoratedecorate_s();
		virtual ~Sheet_decoratedecorate_s(){}
		int CreateInit();
		int ResumeInit();
		NFArray<struct decoratedecorate_s, 40> decoratedecorate_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_decoratedecorate & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_decoratedecorate & msg);
		static ::proto_ff::Sheet_decoratedecorate* new_pbmsg(){ return new ::proto_ff::Sheet_decoratedecorate(); }
		static ::proto_ff::Sheet_decoratedecorate make_pbmsg(){ return ::proto_ff::Sheet_decoratedecorate(); }
	};
	typedef struct Sheet_decoratedecorate_s Sheet_decoratedecorate_t;

}

