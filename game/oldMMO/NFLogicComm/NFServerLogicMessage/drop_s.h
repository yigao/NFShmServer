#pragma once

#include <stdint.h>
#include <NFComm/NFShmCore/NFSizeString.h>
#include <NFComm/NFShmCore/NFArray.h>
#include <NFComm/NFShmCore/NFSeqOP.h>
#include <NFComm/NFShmCore/NFShmMgr.h>
#include "drop.pb.h"
#include "drop_s.h"

namespace proto_ff_s {

	struct dropdropitemDesc_s : public NFDescStoreSeqOP {
		dropdropitemDesc_s();
		int CreateInit();
		int ResumeInit();
		NFSizeString<300> bd;
		int32_t rand;
		int32_t maxNum;
		NFSizeString<300> QZ;
		int32_t minNum;
		NFSizeString<700> id;

		virtual void write_to_pbmsg(::proto_ff::dropdropitemDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::dropdropitemDesc & msg);
		static ::proto_ff::dropdropitemDesc* new_pbmsg(){ return new ::proto_ff::dropdropitemDesc(); }
		static ::proto_ff::dropdropitemDesc make_pbmsg(){ return ::proto_ff::dropdropitemDesc(); }
	};
	typedef struct dropdropitemDesc_s dropdropitemDesc_t;

	struct dropdropitemTeamDesc_s : public NFDescStoreSeqOP {
		dropdropitemTeamDesc_s();
		int CreateInit();
		int ResumeInit();
		NFSizeString<60> bd;
		int32_t rand;
		int32_t maxNum;
		NFSizeString<120> QZ;
		int32_t minNum;
		NFSizeString<200> id;

		virtual void write_to_pbmsg(::proto_ff::dropdropitemTeamDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::dropdropitemTeamDesc & msg);
		static ::proto_ff::dropdropitemTeamDesc* new_pbmsg(){ return new ::proto_ff::dropdropitemTeamDesc(); }
		static ::proto_ff::dropdropitemTeamDesc make_pbmsg(){ return ::proto_ff::dropdropitemTeamDesc(); }
	};
	typedef struct dropdropitemTeamDesc_s dropdropitemTeamDesc_t;

	struct dropdropequipDesc_s : public NFDescStoreSeqOP {
		dropdropequipDesc_s();
		int CreateInit();
		int ResumeInit();
		int32_t rand;
		int32_t maxNum;
		NFSizeString<80> weight;
		int32_t minNum;
		NFSizeString<60> isbind;
		NFSizeString<60> prof;
		NFSizeString<180> id;

		virtual void write_to_pbmsg(::proto_ff::dropdropequipDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::dropdropequipDesc & msg);
		static ::proto_ff::dropdropequipDesc* new_pbmsg(){ return new ::proto_ff::dropdropequipDesc(); }
		static ::proto_ff::dropdropequipDesc make_pbmsg(){ return ::proto_ff::dropdropequipDesc(); }
	};
	typedef struct dropdropequipDesc_s dropdropequipDesc_t;

	struct dropdrop_s : public NFDescStoreSeqOP {
		dropdrop_s();
		int CreateInit();
		int ResumeInit();
		int64_t id;
		int32_t goldlow;
		int32_t goldup;
		int32_t gold_heapMin;
		int32_t gold_heapMax;
		int32_t gold_rand;
		NFArray<struct dropdropitemDesc_s, 32> item;
		NFArray<struct dropdropitemTeamDesc_s, 5> itemTeam;
		NFArray<struct dropdropequipDesc_s, 1> equip;

		virtual void write_to_pbmsg(::proto_ff::dropdrop & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::dropdrop & msg);
		static ::proto_ff::dropdrop* new_pbmsg(){ return new ::proto_ff::dropdrop(); }
		static ::proto_ff::dropdrop make_pbmsg(){ return ::proto_ff::dropdrop(); }
	};
	typedef struct dropdrop_s dropdrop_t;

	struct Sheet_dropdrop_s : public NFDescStoreSeqOP {
		Sheet_dropdrop_s();
		int CreateInit();
		int ResumeInit();
		NFArray<struct dropdrop_s, 2000> dropdrop_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_dropdrop & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_dropdrop & msg);
		static ::proto_ff::Sheet_dropdrop* new_pbmsg(){ return new ::proto_ff::Sheet_dropdrop(); }
		static ::proto_ff::Sheet_dropdrop make_pbmsg(){ return ::proto_ff::Sheet_dropdrop(); }
	};
	typedef struct Sheet_dropdrop_s Sheet_dropdrop_t;

}

