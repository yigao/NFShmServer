#pragma once

#include <stdint.h>
#include <NFComm/NFShmCore/NFShmString.h>
#include <NFComm/NFShmCore/NFArray.h>
#include <NFComm/NFShmCore/NFSeqOP.h>
#include <NFComm/NFShmCore/NFShmMgr.h>
#include "area.pb.h"
#include "area_s.h"

namespace proto_ff_s {

	struct areaarea_s : public NFDescStoreSeqOP {
		areaarea_s();
		virtual ~areaarea_s(){}
		int CreateInit();
		int ResumeInit();
		int64_t id;
		int32_t subType;
		int64_t belongToSceneID;
		int32_t shapeType;
		int32_t isNotice;

		virtual void write_to_pbmsg(::proto_ff::areaarea & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::areaarea & msg);
		static ::proto_ff::areaarea* new_pbmsg(){ return new ::proto_ff::areaarea(); }
		static ::proto_ff::areaarea make_pbmsg(){ return ::proto_ff::areaarea(); }
	};
	typedef struct areaarea_s areaarea_t;

	struct Sheet_areaarea_s : public NFDescStoreSeqOP {
		Sheet_areaarea_s();
		virtual ~Sheet_areaarea_s(){}
		int CreateInit();
		int ResumeInit();
		NFArray<struct areaarea_s, 20> areaarea_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_areaarea & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_areaarea & msg);
		static ::proto_ff::Sheet_areaarea* new_pbmsg(){ return new ::proto_ff::Sheet_areaarea(); }
		static ::proto_ff::Sheet_areaarea make_pbmsg(){ return ::proto_ff::Sheet_areaarea(); }
	};
	typedef struct Sheet_areaarea_s Sheet_areaarea_t;

}

