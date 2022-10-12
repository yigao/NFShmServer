#pragma once

#include <stdint.h>
#include <NFComm/NFShmCore/NFSizeString.h>
#include <NFComm/NFShmCore/NFArray.h>
#include <NFComm/NFShmCore/NFSeqOP.h>
#include <NFComm/NFShmCore/NFShmMgr.h>
#include "area.pb.h"
#include "area_s.h"

namespace proto_ff_s {

	struct areaarea_s : public NFDescStoreSeqOP {
		areaarea_s();
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
		int CreateInit();
		int ResumeInit();
		NFArray<struct areaarea_s, 300> areaarea_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_areaarea & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_areaarea & msg);
		static ::proto_ff::Sheet_areaarea* new_pbmsg(){ return new ::proto_ff::Sheet_areaarea(); }
		static ::proto_ff::Sheet_areaarea make_pbmsg(){ return ::proto_ff::Sheet_areaarea(); }
	};
	typedef struct Sheet_areaarea_s Sheet_areaarea_t;

	struct areapath_s : public NFDescStoreSeqOP {
		areapath_s();
		int CreateInit();
		int ResumeInit();
		int64_t id;
		int64_t belongToSceneID;

		virtual void write_to_pbmsg(::proto_ff::areapath & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::areapath & msg);
		static ::proto_ff::areapath* new_pbmsg(){ return new ::proto_ff::areapath(); }
		static ::proto_ff::areapath make_pbmsg(){ return ::proto_ff::areapath(); }
	};
	typedef struct areapath_s areapath_t;

	struct Sheet_areapath_s : public NFDescStoreSeqOP {
		Sheet_areapath_s();
		int CreateInit();
		int ResumeInit();
		NFArray<struct areapath_s, 2000> areapath_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_areapath & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_areapath & msg);
		static ::proto_ff::Sheet_areapath* new_pbmsg(){ return new ::proto_ff::Sheet_areapath(); }
		static ::proto_ff::Sheet_areapath make_pbmsg(){ return ::proto_ff::Sheet_areapath(); }
	};
	typedef struct Sheet_areapath_s Sheet_areapath_t;

}

