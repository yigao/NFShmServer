#pragma once

#include <stdint.h>
#include <NFComm/NFShmCore/NFSizeString.h>
#include <NFComm/NFShmCore/NFArray.h>
#include <NFComm/NFShmCore/NFSeqOP.h>
#include <NFComm/NFShmCore/NFShmMgr.h>
#include "box.pb.h"
#include "box_s.h"

namespace proto_ff_s {

	struct boxequipDesc_s : public NFDescStoreSeqOP {
		boxequipDesc_s();
		int CreateInit();
		int ResumeInit();
		int32_t rand;
		int32_t minNum;
		int32_t isbind;
		int32_t maxNum;

		virtual void write_to_pbmsg(::proto_ff::boxequipDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::boxequipDesc & msg);
		static ::proto_ff::boxequipDesc* new_pbmsg(){ return new ::proto_ff::boxequipDesc(); }
		static ::proto_ff::boxequipDesc make_pbmsg(){ return ::proto_ff::boxequipDesc(); }
	};
	typedef struct boxequipDesc_s boxequipDesc_t;

	struct boxitemDesc_s : public NFDescStoreSeqOP {
		boxitemDesc_s();
		int CreateInit();
		int ResumeInit();
		int32_t maxNum;
		int32_t rarerand;
		int32_t minNum;

		virtual void write_to_pbmsg(::proto_ff::boxitemDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::boxitemDesc & msg);
		static ::proto_ff::boxitemDesc* new_pbmsg(){ return new ::proto_ff::boxitemDesc(); }
		static ::proto_ff::boxitemDesc make_pbmsg(){ return ::proto_ff::boxitemDesc(); }
	};
	typedef struct boxitemDesc_s boxitemDesc_t;

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
		NFSizeString<32> eq_profession;
		NFArray<struct boxequipDesc_s, 8> equip;
		NFArray<struct boxitemDesc_s, 50> item;

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
		NFArray<struct boxbox_s, 5132> boxbox_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_boxbox & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_boxbox & msg);
		static ::proto_ff::Sheet_boxbox* new_pbmsg(){ return new ::proto_ff::Sheet_boxbox(); }
		static ::proto_ff::Sheet_boxbox make_pbmsg(){ return ::proto_ff::Sheet_boxbox(); }
	};
	typedef struct Sheet_boxbox_s Sheet_boxbox_t;

}

