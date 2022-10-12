#pragma once

#include <stdint.h>
#include <NFComm/NFShmCore/NFSizeString.h>
#include <NFComm/NFShmCore/NFArray.h>
#include <NFComm/NFShmCore/NFSeqOP.h>
#include <NFComm/NFShmCore/NFShmMgr.h>
#include "witch.pb.h"
#include "witch_s.h"

namespace proto_ff_s {

	struct witchawarditemDesc_s : public NFDescStoreSeqOP {
		witchawarditemDesc_s();
		int CreateInit();
		int ResumeInit();
		int32_t num;
		int64_t name;

		virtual void write_to_pbmsg(::proto_ff::witchawarditemDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::witchawarditemDesc & msg);
		static ::proto_ff::witchawarditemDesc* new_pbmsg(){ return new ::proto_ff::witchawarditemDesc(); }
		static ::proto_ff::witchawarditemDesc make_pbmsg(){ return ::proto_ff::witchawarditemDesc(); }
	};
	typedef struct witchawarditemDesc_s witchawarditemDesc_t;

	struct witchaward_s : public NFDescStoreSeqOP {
		witchaward_s();
		int CreateInit();
		int ResumeInit();
		int32_t id;
		int32_t rank1;
		int32_t rank2;
		int32_t integral_blue_nub;
		int32_t integral_purple_nub;
		int32_t integral_red_nub;
		NFArray<struct witchawarditemDesc_s, 3> item;

		virtual void write_to_pbmsg(::proto_ff::witchaward & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::witchaward & msg);
		static ::proto_ff::witchaward* new_pbmsg(){ return new ::proto_ff::witchaward(); }
		static ::proto_ff::witchaward make_pbmsg(){ return ::proto_ff::witchaward(); }
	};
	typedef struct witchaward_s witchaward_t;

	struct Sheet_witchaward_s : public NFDescStoreSeqOP {
		Sheet_witchaward_s();
		int CreateInit();
		int ResumeInit();
		NFArray<struct witchaward_s, 20> witchaward_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_witchaward & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_witchaward & msg);
		static ::proto_ff::Sheet_witchaward* new_pbmsg(){ return new ::proto_ff::Sheet_witchaward(); }
		static ::proto_ff::Sheet_witchaward make_pbmsg(){ return ::proto_ff::Sheet_witchaward(); }
	};
	typedef struct Sheet_witchaward_s Sheet_witchaward_t;

	struct witchsummon_s : public NFDescStoreSeqOP {
		witchsummon_s();
		int CreateInit();
		int ResumeInit();
		int32_t id;
		int32_t consume;
		int64_t bossId;
		int64_t item;
		int32_t purpleDrill;
		int32_t xzhou;
		int32_t yzhou;
		int32_t zzhou;

		virtual void write_to_pbmsg(::proto_ff::witchsummon & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::witchsummon & msg);
		static ::proto_ff::witchsummon* new_pbmsg(){ return new ::proto_ff::witchsummon(); }
		static ::proto_ff::witchsummon make_pbmsg(){ return ::proto_ff::witchsummon(); }
	};
	typedef struct witchsummon_s witchsummon_t;

	struct Sheet_witchsummon_s : public NFDescStoreSeqOP {
		Sheet_witchsummon_s();
		int CreateInit();
		int ResumeInit();
		NFArray<struct witchsummon_s, 20> witchsummon_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_witchsummon & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_witchsummon & msg);
		static ::proto_ff::Sheet_witchsummon* new_pbmsg(){ return new ::proto_ff::Sheet_witchsummon(); }
		static ::proto_ff::Sheet_witchsummon make_pbmsg(){ return ::proto_ff::Sheet_witchsummon(); }
	};
	typedef struct Sheet_witchsummon_s Sheet_witchsummon_t;

	struct witchrewardExp_s : public NFDescStoreSeqOP {
		witchrewardExp_s();
		int CreateInit();
		int ResumeInit();
		int32_t lv;
		int64_t reward_Exp;

		virtual void write_to_pbmsg(::proto_ff::witchrewardExp & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::witchrewardExp & msg);
		static ::proto_ff::witchrewardExp* new_pbmsg(){ return new ::proto_ff::witchrewardExp(); }
		static ::proto_ff::witchrewardExp make_pbmsg(){ return ::proto_ff::witchrewardExp(); }
	};
	typedef struct witchrewardExp_s witchrewardExp_t;

	struct Sheet_witchrewardExp_s : public NFDescStoreSeqOP {
		Sheet_witchrewardExp_s();
		int CreateInit();
		int ResumeInit();
		NFArray<struct witchrewardExp_s, 2000> witchrewardExp_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_witchrewardExp & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_witchrewardExp & msg);
		static ::proto_ff::Sheet_witchrewardExp* new_pbmsg(){ return new ::proto_ff::Sheet_witchrewardExp(); }
		static ::proto_ff::Sheet_witchrewardExp make_pbmsg(){ return ::proto_ff::Sheet_witchrewardExp(); }
	};
	typedef struct Sheet_witchrewardExp_s Sheet_witchrewardExp_t;

}

