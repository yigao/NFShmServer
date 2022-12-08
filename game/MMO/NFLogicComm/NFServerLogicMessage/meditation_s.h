#pragma once

#include <stdint.h>
#include <NFComm/NFShmCore/NFShmString.h>
#include <NFComm/NFShmCore/NFArray.h>
#include <NFComm/NFShmCore/NFSeqOP.h>
#include <NFComm/NFShmCore/NFShmMgr.h>
#include "meditation.pb.h"
#include "meditation_s.h"

namespace proto_ff_s {

	struct meditationmeditationattributeDesc_s : public NFDescStoreSeqOP {
		meditationmeditationattributeDesc_s();
		virtual ~meditationmeditationattributeDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t type;
		int32_t value;

		virtual void write_to_pbmsg(::proto_ff::meditationmeditationattributeDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::meditationmeditationattributeDesc & msg);
		static ::proto_ff::meditationmeditationattributeDesc* new_pbmsg(){ return new ::proto_ff::meditationmeditationattributeDesc(); }
		static ::proto_ff::meditationmeditationattributeDesc make_pbmsg(){ return ::proto_ff::meditationmeditationattributeDesc(); }
	};
	typedef struct meditationmeditationattributeDesc_s meditationmeditationattributeDesc_t;

	struct meditationmeditationActiveAttributeDesc_s : public NFDescStoreSeqOP {
		meditationmeditationActiveAttributeDesc_s();
		virtual ~meditationmeditationActiveAttributeDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t type;
		int32_t value;

		virtual void write_to_pbmsg(::proto_ff::meditationmeditationActiveAttributeDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::meditationmeditationActiveAttributeDesc & msg);
		static ::proto_ff::meditationmeditationActiveAttributeDesc* new_pbmsg(){ return new ::proto_ff::meditationmeditationActiveAttributeDesc(); }
		static ::proto_ff::meditationmeditationActiveAttributeDesc make_pbmsg(){ return ::proto_ff::meditationmeditationActiveAttributeDesc(); }
	};
	typedef struct meditationmeditationActiveAttributeDesc_s meditationmeditationActiveAttributeDesc_t;

	struct meditationmeditation_s : public NFDescStoreSeqOP {
		meditationmeditation_s();
		virtual ~meditationmeditation_s(){}
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
		NFArray<struct meditationmeditationattributeDesc_s, 6> attribute;
		NFArray<struct meditationmeditationActiveAttributeDesc_s, 6> ActiveAttribute;

		virtual void write_to_pbmsg(::proto_ff::meditationmeditation & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::meditationmeditation & msg);
		static ::proto_ff::meditationmeditation* new_pbmsg(){ return new ::proto_ff::meditationmeditation(); }
		static ::proto_ff::meditationmeditation make_pbmsg(){ return ::proto_ff::meditationmeditation(); }
	};
	typedef struct meditationmeditation_s meditationmeditation_t;

	struct Sheet_meditationmeditation_s : public NFDescStoreSeqOP {
		Sheet_meditationmeditation_s();
		virtual ~Sheet_meditationmeditation_s(){}
		int CreateInit();
		int ResumeInit();
		NFArray<struct meditationmeditation_s, 20> meditationmeditation_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_meditationmeditation & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_meditationmeditation & msg);
		static ::proto_ff::Sheet_meditationmeditation* new_pbmsg(){ return new ::proto_ff::Sheet_meditationmeditation(); }
		static ::proto_ff::Sheet_meditationmeditation make_pbmsg(){ return ::proto_ff::Sheet_meditationmeditation(); }
	};
	typedef struct Sheet_meditationmeditation_s Sheet_meditationmeditation_t;

}

