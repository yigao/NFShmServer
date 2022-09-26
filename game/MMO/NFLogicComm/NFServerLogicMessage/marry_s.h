#pragma once

#include <stdint.h>
#include <NFComm/NFShmCore/NFSizeString.h>
#include <NFComm/NFShmCore/NFArray.h>
#include <NFComm/NFShmCore/NFSeqOP.h>
#include <NFComm/NFShmCore/NFShmMgr.h>
#include "marry.pb.h"
#include "marry_s.h"

namespace proto_ff_s {

	struct marryconst_s : public NFDescStoreSeqOP {
		marryconst_s();
		int CreateInit();
		int ResumeInit();
		int32_t id;
		int64_t constantdata;
		NFSizeString<32> stringdata;

		virtual void write_to_pbmsg(::proto_ff::marryconst & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::marryconst & msg);
		static ::proto_ff::marryconst* new_pbmsg(){ return new ::proto_ff::marryconst(); }
		static ::proto_ff::marryconst make_pbmsg(){ return ::proto_ff::marryconst(); }
	};
	typedef struct marryconst_s marryconst_t;

	struct Sheet_marryconst_s : public NFDescStoreSeqOP {
		Sheet_marryconst_s();
		int CreateInit();
		int ResumeInit();
		NFArray<struct marryconst_s, 119> marryconst_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_marryconst & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_marryconst & msg);
		static ::proto_ff::Sheet_marryconst* new_pbmsg(){ return new ::proto_ff::Sheet_marryconst(); }
		static ::proto_ff::Sheet_marryconst make_pbmsg(){ return ::proto_ff::Sheet_marryconst(); }
	};
	typedef struct Sheet_marryconst_s Sheet_marryconst_t;

	struct marrybanquetfireworkDesc_s : public NFDescStoreSeqOP {
		marrybanquetfireworkDesc_s();
		int CreateInit();
		int ResumeInit();
		int64_t Item;
		int32_t Price;
		int64_t Efc;
		int32_t Warm;

		virtual void write_to_pbmsg(::proto_ff::marrybanquetfireworkDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::marrybanquetfireworkDesc & msg);
		static ::proto_ff::marrybanquetfireworkDesc* new_pbmsg(){ return new ::proto_ff::marrybanquetfireworkDesc(); }
		static ::proto_ff::marrybanquetfireworkDesc make_pbmsg(){ return ::proto_ff::marrybanquetfireworkDesc(); }
	};
	typedef struct marrybanquetfireworkDesc_s marrybanquetfireworkDesc_t;

	struct marrybanquet_s : public NFDescStoreSeqOP {
		marrybanquet_s();
		int CreateInit();
		int ResumeInit();
		int32_t id;
		int64_t orderItem;
		int32_t orderNum;
		int64_t banquetReward;
		int32_t rewardNum;
		int32_t makeLoveWarmValue;
		int32_t inviteNum;
		int32_t strangerNum;
		int32_t preludeTime;
		int32_t banquetTime;
		int64_t makeLoveEfc;
		int32_t warmValue;
		int32_t warmCycle;
		int64_t duplcateId;
		NFArray<struct marrybanquetfireworkDesc_s, 2> firework;

		virtual void write_to_pbmsg(::proto_ff::marrybanquet & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::marrybanquet & msg);
		static ::proto_ff::marrybanquet* new_pbmsg(){ return new ::proto_ff::marrybanquet(); }
		static ::proto_ff::marrybanquet make_pbmsg(){ return ::proto_ff::marrybanquet(); }
	};
	typedef struct marrybanquet_s marrybanquet_t;

	struct Sheet_marrybanquet_s : public NFDescStoreSeqOP {
		Sheet_marrybanquet_s();
		int CreateInit();
		int ResumeInit();
		NFArray<struct marrybanquet_s, 107> marrybanquet_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_marrybanquet & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_marrybanquet & msg);
		static ::proto_ff::Sheet_marrybanquet* new_pbmsg(){ return new ::proto_ff::Sheet_marrybanquet(); }
		static ::proto_ff::Sheet_marrybanquet make_pbmsg(){ return ::proto_ff::Sheet_marrybanquet(); }
	};
	typedef struct Sheet_marrybanquet_s Sheet_marrybanquet_t;

	struct marrygear_s : public NFDescStoreSeqOP {
		marrygear_s();
		int CreateInit();
		int ResumeInit();
		int32_t id;
		int64_t title;
		int64_t item;
		NFSizeString<32> nickName;
		int64_t initiate;
		int32_t usetype;
		int32_t useprice;
		int32_t AAPrice;
		NFSizeString<32> preset;
		int64_t weddingEffect;

		virtual void write_to_pbmsg(::proto_ff::marrygear & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::marrygear & msg);
		static ::proto_ff::marrygear* new_pbmsg(){ return new ::proto_ff::marrygear(); }
		static ::proto_ff::marrygear make_pbmsg(){ return ::proto_ff::marrygear(); }
	};
	typedef struct marrygear_s marrygear_t;

	struct Sheet_marrygear_s : public NFDescStoreSeqOP {
		Sheet_marrygear_s();
		int CreateInit();
		int ResumeInit();
		NFArray<struct marrygear_s, 107> marrygear_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_marrygear & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_marrygear & msg);
		static ::proto_ff::Sheet_marrygear* new_pbmsg(){ return new ::proto_ff::Sheet_marrygear(); }
		static ::proto_ff::Sheet_marrygear make_pbmsg(){ return ::proto_ff::Sheet_marrygear(); }
	};
	typedef struct Sheet_marrygear_s Sheet_marrygear_t;

	struct marrytimes_s : public NFDescStoreSeqOP {
		marrytimes_s();
		int CreateInit();
		int ResumeInit();
		int32_t id;
		NFSizeString<32> startTime;
		NFSizeString<32> endTime;
		NFSizeString<32> limit;

		virtual void write_to_pbmsg(::proto_ff::marrytimes & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::marrytimes & msg);
		static ::proto_ff::marrytimes* new_pbmsg(){ return new ::proto_ff::marrytimes(); }
		static ::proto_ff::marrytimes make_pbmsg(){ return ::proto_ff::marrytimes(); }
	};
	typedef struct marrytimes_s marrytimes_t;

	struct Sheet_marrytimes_s : public NFDescStoreSeqOP {
		Sheet_marrytimes_s();
		int CreateInit();
		int ResumeInit();
		NFArray<struct marrytimes_s, 110> marrytimes_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_marrytimes & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_marrytimes & msg);
		static ::proto_ff::Sheet_marrytimes* new_pbmsg(){ return new ::proto_ff::Sheet_marrytimes(); }
		static ::proto_ff::Sheet_marrytimes make_pbmsg(){ return ::proto_ff::Sheet_marrytimes(); }
	};
	typedef struct Sheet_marrytimes_s Sheet_marrytimes_t;

	struct marrywarm_s : public NFDescStoreSeqOP {
		marrywarm_s();
		int CreateInit();
		int ResumeInit();
		int32_t id;
		int32_t warmValue;
		int64_t monsterId;
		int32_t monsterFlashCycle;
		int32_t warmExpValue;
		int32_t warmExpCycle;
		int32_t warmGetNum;

		virtual void write_to_pbmsg(::proto_ff::marrywarm & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::marrywarm & msg);
		static ::proto_ff::marrywarm* new_pbmsg(){ return new ::proto_ff::marrywarm(); }
		static ::proto_ff::marrywarm make_pbmsg(){ return ::proto_ff::marrywarm(); }
	};
	typedef struct marrywarm_s marrywarm_t;

	struct Sheet_marrywarm_s : public NFDescStoreSeqOP {
		Sheet_marrywarm_s();
		int CreateInit();
		int ResumeInit();
		NFArray<struct marrywarm_s, 108> marrywarm_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_marrywarm & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_marrywarm & msg);
		static ::proto_ff::Sheet_marrywarm* new_pbmsg(){ return new ::proto_ff::Sheet_marrywarm(); }
		static ::proto_ff::Sheet_marrywarm make_pbmsg(){ return ::proto_ff::Sheet_marrywarm(); }
	};
	typedef struct Sheet_marrywarm_s Sheet_marrywarm_t;

	struct marrylevelexpwarmDesc_s : public NFDescStoreSeqOP {
		marrylevelexpwarmDesc_s();
		int CreateInit();
		int ResumeInit();
		int32_t Id;
		int64_t Exp;

		virtual void write_to_pbmsg(::proto_ff::marrylevelexpwarmDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::marrylevelexpwarmDesc & msg);
		static ::proto_ff::marrylevelexpwarmDesc* new_pbmsg(){ return new ::proto_ff::marrylevelexpwarmDesc(); }
		static ::proto_ff::marrylevelexpwarmDesc make_pbmsg(){ return ::proto_ff::marrylevelexpwarmDesc(); }
	};
	typedef struct marrylevelexpwarmDesc_s marrylevelexpwarmDesc_t;

	struct marrylevelexp_s : public NFDescStoreSeqOP {
		marrylevelexp_s();
		int CreateInit();
		int ResumeInit();
		int32_t level;
		NFArray<struct marrylevelexpwarmDesc_s, 4> warm;

		virtual void write_to_pbmsg(::proto_ff::marrylevelexp & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::marrylevelexp & msg);
		static ::proto_ff::marrylevelexp* new_pbmsg(){ return new ::proto_ff::marrylevelexp(); }
		static ::proto_ff::marrylevelexp make_pbmsg(){ return ::proto_ff::marrylevelexp(); }
	};
	typedef struct marrylevelexp_s marrylevelexp_t;

	struct Sheet_marrylevelexp_s : public NFDescStoreSeqOP {
		Sheet_marrylevelexp_s();
		int CreateInit();
		int ResumeInit();
		NFArray<struct marrylevelexp_s, 1604> marrylevelexp_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_marrylevelexp & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_marrylevelexp & msg);
		static ::proto_ff::Sheet_marrylevelexp* new_pbmsg(){ return new ::proto_ff::Sheet_marrylevelexp(); }
		static ::proto_ff::Sheet_marrylevelexp make_pbmsg(){ return ::proto_ff::Sheet_marrylevelexp(); }
	};
	typedef struct Sheet_marrylevelexp_s Sheet_marrylevelexp_t;

}

