#pragma once

#include <stdint.h>
#include <NFComm/NFShmCore/NFSizeString.h>
#include <NFComm/NFShmCore/NFArray.h>
#include <NFComm/NFShmCore/NFSeqOP.h>
#include <NFComm/NFShmCore/NFShmMgr.h>
#include "box.pb.h"
#include "box_s.h"

namespace proto_ff_s {

	struct boxboxequipDesc_s : public NFDescStoreSeqOP {
		boxboxequipDesc_s();
		int CreateInit();
		int ResumeInit();
		int32_t rand;
		int32_t minNum;
		int32_t isbind;
		int32_t maxNum;
		NFSizeString<80> id;

		virtual void write_to_pbmsg(::proto_ff::boxboxequipDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::boxboxequipDesc & msg);
		static ::proto_ff::boxboxequipDesc* new_pbmsg(){ return new ::proto_ff::boxboxequipDesc(); }
		static ::proto_ff::boxboxequipDesc make_pbmsg(){ return ::proto_ff::boxboxequipDesc(); }
	};
	typedef struct boxboxequipDesc_s boxboxequipDesc_t;

	struct boxboxitemDesc_s : public NFDescStoreSeqOP {
		boxboxitemDesc_s();
		int CreateInit();
		int ResumeInit();
		NFSizeString<400> rand;
		int32_t maxNum;
		int32_t rarerand;
		int32_t minNum;
		NFSizeString<200> isbind;
		NFSizeString<800> id;

		virtual void write_to_pbmsg(::proto_ff::boxboxitemDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::boxboxitemDesc & msg);
		static ::proto_ff::boxboxitemDesc* new_pbmsg(){ return new ::proto_ff::boxboxitemDesc(); }
		static ::proto_ff::boxboxitemDesc make_pbmsg(){ return ::proto_ff::boxboxitemDesc(); }
	};
	typedef struct boxboxitemDesc_s boxboxitemDesc_t;

	struct boxbox_s : public NFDescStoreSeqOP {
		boxbox_s();
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
		int32_t godjewelminNum;
		int32_t godjewelmaxNum;
		int32_t godjewelrand;
		NFSizeString<60> eq_profession;
		NFArray<struct boxboxequipDesc_s, 8> equip;
		NFArray<struct boxboxitemDesc_s, 50> item;

		virtual void write_to_pbmsg(::proto_ff::boxbox & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::boxbox & msg);
		static ::proto_ff::boxbox* new_pbmsg(){ return new ::proto_ff::boxbox(); }
		static ::proto_ff::boxbox make_pbmsg(){ return ::proto_ff::boxbox(); }
	};
	typedef struct boxbox_s boxbox_t;

	struct Sheet_boxbox_s : public NFDescStoreSeqOP {
		Sheet_boxbox_s();
		int CreateInit();
		int ResumeInit();
		NFArray<struct boxbox_s, 6000> boxbox_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_boxbox & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_boxbox & msg);
		static ::proto_ff::Sheet_boxbox* new_pbmsg(){ return new ::proto_ff::Sheet_boxbox(); }
		static ::proto_ff::Sheet_boxbox make_pbmsg(){ return ::proto_ff::Sheet_boxbox(); }
	};
	typedef struct Sheet_boxbox_s Sheet_boxbox_t;

}

