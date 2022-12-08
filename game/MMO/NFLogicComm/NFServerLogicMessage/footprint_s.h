#pragma once

#include <stdint.h>
#include <NFComm/NFShmCore/NFShmString.h>
#include <NFComm/NFShmCore/NFArray.h>
#include <NFComm/NFShmCore/NFSeqOP.h>
#include <NFComm/NFShmCore/NFShmMgr.h>
#include "footprint.pb.h"
#include "footprint_s.h"

namespace proto_ff_s {

	struct footprintfootprintattributeDesc_s : public NFDescStoreSeqOP {
		footprintfootprintattributeDesc_s();
		virtual ~footprintfootprintattributeDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t type;
		int32_t value;

		virtual void write_to_pbmsg(::proto_ff::footprintfootprintattributeDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::footprintfootprintattributeDesc & msg);
		static ::proto_ff::footprintfootprintattributeDesc* new_pbmsg(){ return new ::proto_ff::footprintfootprintattributeDesc(); }
		static ::proto_ff::footprintfootprintattributeDesc make_pbmsg(){ return ::proto_ff::footprintfootprintattributeDesc(); }
	};
	typedef struct footprintfootprintattributeDesc_s footprintfootprintattributeDesc_t;

	struct footprintfootprintActiveAttributeDesc_s : public NFDescStoreSeqOP {
		footprintfootprintActiveAttributeDesc_s();
		virtual ~footprintfootprintActiveAttributeDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t type;
		int32_t value;

		virtual void write_to_pbmsg(::proto_ff::footprintfootprintActiveAttributeDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::footprintfootprintActiveAttributeDesc & msg);
		static ::proto_ff::footprintfootprintActiveAttributeDesc* new_pbmsg(){ return new ::proto_ff::footprintfootprintActiveAttributeDesc(); }
		static ::proto_ff::footprintfootprintActiveAttributeDesc make_pbmsg(){ return ::proto_ff::footprintfootprintActiveAttributeDesc(); }
	};
	typedef struct footprintfootprintActiveAttributeDesc_s footprintfootprintActiveAttributeDesc_t;

	struct footprintfootprint_s : public NFDescStoreSeqOP {
		footprintfootprint_s();
		virtual ~footprintfootprint_s(){}
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
		NFArray<struct footprintfootprintattributeDesc_s, 6> attribute;
		NFArray<struct footprintfootprintActiveAttributeDesc_s, 6> ActiveAttribute;

		virtual void write_to_pbmsg(::proto_ff::footprintfootprint & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::footprintfootprint & msg);
		static ::proto_ff::footprintfootprint* new_pbmsg(){ return new ::proto_ff::footprintfootprint(); }
		static ::proto_ff::footprintfootprint make_pbmsg(){ return ::proto_ff::footprintfootprint(); }
	};
	typedef struct footprintfootprint_s footprintfootprint_t;

	struct Sheet_footprintfootprint_s : public NFDescStoreSeqOP {
		Sheet_footprintfootprint_s();
		virtual ~Sheet_footprintfootprint_s(){}
		int CreateInit();
		int ResumeInit();
		NFArray<struct footprintfootprint_s, 20> footprintfootprint_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_footprintfootprint & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_footprintfootprint & msg);
		static ::proto_ff::Sheet_footprintfootprint* new_pbmsg(){ return new ::proto_ff::Sheet_footprintfootprint(); }
		static ::proto_ff::Sheet_footprintfootprint make_pbmsg(){ return ::proto_ff::Sheet_footprintfootprint(); }
	};
	typedef struct Sheet_footprintfootprint_s Sheet_footprintfootprint_t;

}

