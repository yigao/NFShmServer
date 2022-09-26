#pragma once

#include <stdint.h>
#include <NFComm/NFShmCore/NFSizeString.h>
#include <NFComm/NFShmCore/NFArray.h>
#include <NFComm/NFShmCore/NFSeqOP.h>
#include <NFComm/NFShmCore/NFShmMgr.h>
#include "serveropenactive.pb.h"
#include "serveropenactive_s.h"

namespace proto_ff_s {

	struct serveropenactiveserviceActivity_s : public NFDescStoreSeqOP {
		serveropenactiveserviceActivity_s();
		int CreateInit();
		int ResumeInit();
		int64_t id;
		int32_t servertype;
		int32_t timeA;
		int32_t timeB;
		NFSizeString<300> pageId;

		virtual void write_to_pbmsg(::proto_ff::serveropenactiveserviceActivity & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::serveropenactiveserviceActivity & msg);
		static ::proto_ff::serveropenactiveserviceActivity* new_pbmsg(){ return new ::proto_ff::serveropenactiveserviceActivity(); }
		static ::proto_ff::serveropenactiveserviceActivity make_pbmsg(){ return ::proto_ff::serveropenactiveserviceActivity(); }
	};
	typedef struct serveropenactiveserviceActivity_s serveropenactiveserviceActivity_t;

	struct Sheet_serveropenactiveserviceActivity_s : public NFDescStoreSeqOP {
		Sheet_serveropenactiveserviceActivity_s();
		int CreateInit();
		int ResumeInit();
		NFArray<struct serveropenactiveserviceActivity_s, 20> serveropenactiveserviceActivity_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_serveropenactiveserviceActivity & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_serveropenactiveserviceActivity & msg);
		static ::proto_ff::Sheet_serveropenactiveserviceActivity* new_pbmsg(){ return new ::proto_ff::Sheet_serveropenactiveserviceActivity(); }
		static ::proto_ff::Sheet_serveropenactiveserviceActivity make_pbmsg(){ return ::proto_ff::Sheet_serveropenactiveserviceActivity(); }
	};
	typedef struct Sheet_serveropenactiveserviceActivity_s Sheet_serveropenactiveserviceActivity_t;

	struct serveropenactivepageBook_s : public NFDescStoreSeqOP {
		serveropenactivepageBook_s();
		int CreateInit();
		int ResumeInit();
		int32_t Id;

		virtual void write_to_pbmsg(::proto_ff::serveropenactivepageBook & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::serveropenactivepageBook & msg);
		static ::proto_ff::serveropenactivepageBook* new_pbmsg(){ return new ::proto_ff::serveropenactivepageBook(); }
		static ::proto_ff::serveropenactivepageBook make_pbmsg(){ return ::proto_ff::serveropenactivepageBook(); }
	};
	typedef struct serveropenactivepageBook_s serveropenactivepageBook_t;

	struct Sheet_serveropenactivepageBook_s : public NFDescStoreSeqOP {
		Sheet_serveropenactivepageBook_s();
		int CreateInit();
		int ResumeInit();
		NFArray<struct serveropenactivepageBook_s, 20> serveropenactivepageBook_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_serveropenactivepageBook & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_serveropenactivepageBook & msg);
		static ::proto_ff::Sheet_serveropenactivepageBook* new_pbmsg(){ return new ::proto_ff::Sheet_serveropenactivepageBook(); }
		static ::proto_ff::Sheet_serveropenactivepageBook make_pbmsg(){ return ::proto_ff::Sheet_serveropenactivepageBook(); }
	};
	typedef struct Sheet_serveropenactivepageBook_s Sheet_serveropenactivepageBook_t;

	struct serveropenactivepage_s : public NFDescStoreSeqOP {
		serveropenactivepage_s();
		int CreateInit();
		int ResumeInit();
		int64_t Id;
		int32_t mType;
		int32_t mCanshu;
		NFSizeString<60> start;
		NFSizeString<60> finish;
		NFSizeString<200> miaoshu;
		NFSizeString<80> tiaojianId;
		int64_t mailid;
		int64_t youjianid;
		int64_t nonstandardmailid;

		virtual void write_to_pbmsg(::proto_ff::serveropenactivepage & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::serveropenactivepage & msg);
		static ::proto_ff::serveropenactivepage* new_pbmsg(){ return new ::proto_ff::serveropenactivepage(); }
		static ::proto_ff::serveropenactivepage make_pbmsg(){ return ::proto_ff::serveropenactivepage(); }
	};
	typedef struct serveropenactivepage_s serveropenactivepage_t;

	struct Sheet_serveropenactivepage_s : public NFDescStoreSeqOP {
		Sheet_serveropenactivepage_s();
		int CreateInit();
		int ResumeInit();
		NFArray<struct serveropenactivepage_s, 140> serveropenactivepage_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_serveropenactivepage & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_serveropenactivepage & msg);
		static ::proto_ff::Sheet_serveropenactivepage* new_pbmsg(){ return new ::proto_ff::Sheet_serveropenactivepage(); }
		static ::proto_ff::Sheet_serveropenactivepage make_pbmsg(){ return ::proto_ff::Sheet_serveropenactivepage(); }
	};
	typedef struct Sheet_serveropenactivepage_s Sheet_serveropenactivepage_t;

	struct serveropenactivemRank_s : public NFDescStoreSeqOP {
		serveropenactivemRank_s();
		int CreateInit();
		int ResumeInit();
		int32_t id;
		int32_t randtype;
		NFSizeString<100> miaoshu;
		int64_t boxid;
		NFArray<int64_t, 2> canshu;

		virtual void write_to_pbmsg(::proto_ff::serveropenactivemRank & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::serveropenactivemRank & msg);
		static ::proto_ff::serveropenactivemRank* new_pbmsg(){ return new ::proto_ff::serveropenactivemRank(); }
		static ::proto_ff::serveropenactivemRank make_pbmsg(){ return ::proto_ff::serveropenactivemRank(); }
	};
	typedef struct serveropenactivemRank_s serveropenactivemRank_t;

	struct Sheet_serveropenactivemRank_s : public NFDescStoreSeqOP {
		Sheet_serveropenactivemRank_s();
		int CreateInit();
		int ResumeInit();
		NFArray<struct serveropenactivemRank_s, 200> serveropenactivemRank_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_serveropenactivemRank & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_serveropenactivemRank & msg);
		static ::proto_ff::Sheet_serveropenactivemRank* new_pbmsg(){ return new ::proto_ff::Sheet_serveropenactivemRank(); }
		static ::proto_ff::Sheet_serveropenactivemRank make_pbmsg(){ return ::proto_ff::Sheet_serveropenactivemRank(); }
	};
	typedef struct Sheet_serveropenactivemRank_s Sheet_serveropenactivemRank_t;

	struct serveropenactivemAdvanced_s : public NFDescStoreSeqOP {
		serveropenactivemAdvanced_s();
		int CreateInit();
		int ResumeInit();
		int32_t id;
		int32_t advancedType;
		int64_t num;
		int64_t parameter;
		NFSizeString<60> miaoshu;
		int64_t jiangLi;

		virtual void write_to_pbmsg(::proto_ff::serveropenactivemAdvanced & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::serveropenactivemAdvanced & msg);
		static ::proto_ff::serveropenactivemAdvanced* new_pbmsg(){ return new ::proto_ff::serveropenactivemAdvanced(); }
		static ::proto_ff::serveropenactivemAdvanced make_pbmsg(){ return ::proto_ff::serveropenactivemAdvanced(); }
	};
	typedef struct serveropenactivemAdvanced_s serveropenactivemAdvanced_t;

	struct Sheet_serveropenactivemAdvanced_s : public NFDescStoreSeqOP {
		Sheet_serveropenactivemAdvanced_s();
		int CreateInit();
		int ResumeInit();
		NFArray<struct serveropenactivemAdvanced_s, 160> serveropenactivemAdvanced_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_serveropenactivemAdvanced & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_serveropenactivemAdvanced & msg);
		static ::proto_ff::Sheet_serveropenactivemAdvanced* new_pbmsg(){ return new ::proto_ff::Sheet_serveropenactivemAdvanced(); }
		static ::proto_ff::Sheet_serveropenactivemAdvanced make_pbmsg(){ return ::proto_ff::Sheet_serveropenactivemAdvanced(); }
	};
	typedef struct Sheet_serveropenactivemAdvanced_s Sheet_serveropenactivemAdvanced_t;

	struct serveropenactivemRecharge_s : public NFDescStoreSeqOP {
		serveropenactivemRecharge_s();
		int CreateInit();
		int ResumeInit();
		int32_t id;
		int32_t numType;
		int32_t num;
		NFSizeString<60> miaoshu;
		int64_t jiangLi;

		virtual void write_to_pbmsg(::proto_ff::serveropenactivemRecharge & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::serveropenactivemRecharge & msg);
		static ::proto_ff::serveropenactivemRecharge* new_pbmsg(){ return new ::proto_ff::serveropenactivemRecharge(); }
		static ::proto_ff::serveropenactivemRecharge make_pbmsg(){ return ::proto_ff::serveropenactivemRecharge(); }
	};
	typedef struct serveropenactivemRecharge_s serveropenactivemRecharge_t;

	struct Sheet_serveropenactivemRecharge_s : public NFDescStoreSeqOP {
		Sheet_serveropenactivemRecharge_s();
		int CreateInit();
		int ResumeInit();
		NFArray<struct serveropenactivemRecharge_s, 200> serveropenactivemRecharge_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_serveropenactivemRecharge & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_serveropenactivemRecharge & msg);
		static ::proto_ff::Sheet_serveropenactivemRecharge* new_pbmsg(){ return new ::proto_ff::Sheet_serveropenactivemRecharge(); }
		static ::proto_ff::Sheet_serveropenactivemRecharge make_pbmsg(){ return ::proto_ff::Sheet_serveropenactivemRecharge(); }
	};
	typedef struct Sheet_serveropenactivemRecharge_s Sheet_serveropenactivemRecharge_t;

	struct serveropenactivemGoods_s : public NFDescStoreSeqOP {
		serveropenactivemGoods_s();
		int CreateInit();
		int ResumeInit();
		int64_t id;
		int64_t itemid;
		int32_t currency;
		int32_t priceA;
		int32_t priceB;
		int32_t quantity;

		virtual void write_to_pbmsg(::proto_ff::serveropenactivemGoods & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::serveropenactivemGoods & msg);
		static ::proto_ff::serveropenactivemGoods* new_pbmsg(){ return new ::proto_ff::serveropenactivemGoods(); }
		static ::proto_ff::serveropenactivemGoods make_pbmsg(){ return ::proto_ff::serveropenactivemGoods(); }
	};
	typedef struct serveropenactivemGoods_s serveropenactivemGoods_t;

	struct Sheet_serveropenactivemGoods_s : public NFDescStoreSeqOP {
		Sheet_serveropenactivemGoods_s();
		int CreateInit();
		int ResumeInit();
		NFArray<struct serveropenactivemGoods_s, 160> serveropenactivemGoods_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_serveropenactivemGoods & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_serveropenactivemGoods & msg);
		static ::proto_ff::Sheet_serveropenactivemGoods* new_pbmsg(){ return new ::proto_ff::Sheet_serveropenactivemGoods(); }
		static ::proto_ff::Sheet_serveropenactivemGoods make_pbmsg(){ return ::proto_ff::Sheet_serveropenactivemGoods(); }
	};
	typedef struct Sheet_serveropenactivemGoods_s Sheet_serveropenactivemGoods_t;

}

