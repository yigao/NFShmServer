#pragma once

#include <stdint.h>
#include <NFComm/NFShmCore/NFShmString.h>
#include <NFComm/NFShmCore/NFArray.h>
#include <NFComm/NFShmCore/NFSeqOP.h>
#include <NFComm/NFShmCore/NFShmMgr.h>
#include "box.pb.h"
#include "box_s.h"

namespace proto_ff_s {

	struct boxboxboxdataDesc_s : public NFDescStoreSeqOP {
		boxboxboxdataDesc_s();
		virtual ~boxboxboxdataDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t maxTimes;
		int64_t id;
		int32_t weight;
		int32_t minTimes;

		virtual void write_to_pbmsg(::proto_ff::boxboxboxdataDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::boxboxboxdataDesc & msg);
		static ::proto_ff::boxboxboxdataDesc* new_pbmsg(){ return new ::proto_ff::boxboxboxdataDesc(); }
		static ::proto_ff::boxboxboxdataDesc make_pbmsg(){ return ::proto_ff::boxboxboxdataDesc(); }
	};
	typedef struct boxboxboxdataDesc_s boxboxboxdataDesc_t;

	struct boxbox_s : public NFDescStoreSeqOP {
		boxbox_s();
		virtual ~boxbox_s(){}
		int CreateInit();
		int ResumeInit();
		int64_t id;
		int32_t type;
		int32_t Rate;
		int32_t Mask;
		int32_t minTimes;
		int32_t maxTimes;
		NFArray<struct boxboxboxdataDesc_s, 8> boxdata;

		virtual void write_to_pbmsg(::proto_ff::boxbox & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::boxbox & msg);
		static ::proto_ff::boxbox* new_pbmsg(){ return new ::proto_ff::boxbox(); }
		static ::proto_ff::boxbox make_pbmsg(){ return ::proto_ff::boxbox(); }
	};
	typedef struct boxbox_s boxbox_t;

	struct Sheet_boxbox_s : public NFDescStoreSeqOP {
		Sheet_boxbox_s();
		virtual ~Sheet_boxbox_s(){}
		int CreateInit();
		int ResumeInit();
		NFArray<struct boxbox_s, 20> boxbox_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_boxbox & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_boxbox & msg);
		static ::proto_ff::Sheet_boxbox* new_pbmsg(){ return new ::proto_ff::Sheet_boxbox(); }
		static ::proto_ff::Sheet_boxbox make_pbmsg(){ return ::proto_ff::Sheet_boxbox(); }
	};
	typedef struct Sheet_boxbox_s Sheet_boxbox_t;

	struct boxboxdataequipDesc_s : public NFDescStoreSeqOP {
		boxboxdataequipDesc_s();
		virtual ~boxboxdataequipDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t rand;
		int32_t minNum;
		int32_t isbind;
		int32_t maxNum;
		NFShmString<60> id;

		virtual void write_to_pbmsg(::proto_ff::boxboxdataequipDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::boxboxdataequipDesc & msg);
		static ::proto_ff::boxboxdataequipDesc* new_pbmsg(){ return new ::proto_ff::boxboxdataequipDesc(); }
		static ::proto_ff::boxboxdataequipDesc make_pbmsg(){ return ::proto_ff::boxboxdataequipDesc(); }
	};
	typedef struct boxboxdataequipDesc_s boxboxdataequipDesc_t;

	struct boxboxdataitemDesc_s : public NFDescStoreSeqOP {
		boxboxdataitemDesc_s();
		virtual ~boxboxdataitemDesc_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmString<60> rand;
		int32_t maxNum;
		int32_t rarerand;
		int32_t minNum;
		NFShmString<60> isbind;
		NFShmString<60> id;

		virtual void write_to_pbmsg(::proto_ff::boxboxdataitemDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::boxboxdataitemDesc & msg);
		static ::proto_ff::boxboxdataitemDesc* new_pbmsg(){ return new ::proto_ff::boxboxdataitemDesc(); }
		static ::proto_ff::boxboxdataitemDesc make_pbmsg(){ return ::proto_ff::boxboxdataitemDesc(); }
	};
	typedef struct boxboxdataitemDesc_s boxboxdataitemDesc_t;

	struct boxboxdata_s : public NFDescStoreSeqOP {
		boxboxdata_s();
		virtual ~boxboxdata_s(){}
		int CreateInit();
		int ResumeInit();
		int64_t id;
		int32_t drop_type;
		int32_t goldminNum;
		int32_t goldmaxNum;
		int32_t goldrand;
		int32_t bindjewelminNum;
		int32_t bindjewelmaxNum;
		int32_t bindjewelrand;
		int32_t jewelminNum;
		int32_t jewelmaxNum;
		int32_t jewelrand;
		NFShmString<60> eq_profession;
		NFArray<struct boxboxdataequipDesc_s, 8> equip;
		NFArray<struct boxboxdataitemDesc_s, 50> item;

		virtual void write_to_pbmsg(::proto_ff::boxboxdata & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::boxboxdata & msg);
		static ::proto_ff::boxboxdata* new_pbmsg(){ return new ::proto_ff::boxboxdata(); }
		static ::proto_ff::boxboxdata make_pbmsg(){ return ::proto_ff::boxboxdata(); }
	};
	typedef struct boxboxdata_s boxboxdata_t;

	struct Sheet_boxboxdata_s : public NFDescStoreSeqOP {
		Sheet_boxboxdata_s();
		virtual ~Sheet_boxboxdata_s(){}
		int CreateInit();
		int ResumeInit();
		NFArray<struct boxboxdata_s, 40> boxboxdata_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_boxboxdata & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_boxboxdata & msg);
		static ::proto_ff::Sheet_boxboxdata* new_pbmsg(){ return new ::proto_ff::Sheet_boxboxdata(); }
		static ::proto_ff::Sheet_boxboxdata make_pbmsg(){ return ::proto_ff::Sheet_boxboxdata(); }
	};
	typedef struct Sheet_boxboxdata_s Sheet_boxboxdata_t;

}

