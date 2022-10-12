#pragma once

#include <stdint.h>
#include <NFComm/NFShmCore/NFSizeString.h>
#include <NFComm/NFShmCore/NFArray.h>
#include <NFComm/NFShmCore/NFSeqOP.h>
#include <NFComm/NFShmCore/NFShmMgr.h>
#include "star.pb.h"
#include "star_s.h"

namespace proto_ff_s {

	struct starpoint_s : public NFDescStoreSeqOP {
		starpoint_s();
		int CreateInit();
		int ResumeInit();
		int32_t starID;
		int32_t starNum;

		virtual void write_to_pbmsg(::proto_ff::starpoint & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::starpoint & msg);
		static ::proto_ff::starpoint* new_pbmsg(){ return new ::proto_ff::starpoint(); }
		static ::proto_ff::starpoint make_pbmsg(){ return ::proto_ff::starpoint(); }
	};
	typedef struct starpoint_s starpoint_t;

	struct Sheet_starpoint_s : public NFDescStoreSeqOP {
		Sheet_starpoint_s();
		int CreateInit();
		int ResumeInit();
		NFArray<struct starpoint_s, 20> starpoint_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_starpoint & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_starpoint & msg);
		static ::proto_ff::Sheet_starpoint* new_pbmsg(){ return new ::proto_ff::Sheet_starpoint(); }
		static ::proto_ff::Sheet_starpoint make_pbmsg(){ return ::proto_ff::Sheet_starpoint(); }
	};
	typedef struct Sheet_starpoint_s Sheet_starpoint_t;

	struct starstarstarDesc_s : public NFDescStoreSeqOP {
		starstarstarDesc_s();
		int CreateInit();
		int ResumeInit();
		int32_t Att;
		int32_t Attnum;

		virtual void write_to_pbmsg(::proto_ff::starstarstarDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::starstarstarDesc & msg);
		static ::proto_ff::starstarstarDesc* new_pbmsg(){ return new ::proto_ff::starstarstarDesc(); }
		static ::proto_ff::starstarstarDesc make_pbmsg(){ return ::proto_ff::starstarstarDesc(); }
	};
	typedef struct starstarstarDesc_s starstarstarDesc_t;

	struct starstar_s : public NFDescStoreSeqOP {
		starstar_s();
		int CreateInit();
		int ResumeInit();
		int64_t starID;
		NFSizeString<60> starName;
		int32_t starQuality;
		int32_t starNum;
		int32_t change;
		int32_t LvUp;
		int32_t starSq;
		int32_t starDs;
		int32_t rock;
		int32_t exp;
		int32_t starType;
		NFArray<NFSizeString<60>, 2> LvAdd;
		NFArray<struct starstarstarDesc_s, 2> star;

		virtual void write_to_pbmsg(::proto_ff::starstar & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::starstar & msg);
		static ::proto_ff::starstar* new_pbmsg(){ return new ::proto_ff::starstar(); }
		static ::proto_ff::starstar make_pbmsg(){ return ::proto_ff::starstar(); }
	};
	typedef struct starstar_s starstar_t;

	struct Sheet_starstar_s : public NFDescStoreSeqOP {
		Sheet_starstar_s();
		int CreateInit();
		int ResumeInit();
		NFArray<struct starstar_s, 200> starstar_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_starstar & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_starstar & msg);
		static ::proto_ff::Sheet_starstar* new_pbmsg(){ return new ::proto_ff::Sheet_starstar(); }
		static ::proto_ff::Sheet_starstar make_pbmsg(){ return ::proto_ff::Sheet_starstar(); }
	};
	typedef struct Sheet_starstar_s Sheet_starstar_t;

	struct starexp_s : public NFDescStoreSeqOP {
		starexp_s();
		int CreateInit();
		int ResumeInit();
		int64_t id;
		int32_t starDs;
		int32_t starQuality;
		int32_t starLv;
		int32_t exp;

		virtual void write_to_pbmsg(::proto_ff::starexp & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::starexp & msg);
		static ::proto_ff::starexp* new_pbmsg(){ return new ::proto_ff::starexp(); }
		static ::proto_ff::starexp make_pbmsg(){ return ::proto_ff::starexp(); }
	};
	typedef struct starexp_s starexp_t;

	struct Sheet_starexp_s : public NFDescStoreSeqOP {
		Sheet_starexp_s();
		int CreateInit();
		int ResumeInit();
		NFArray<struct starexp_s, 2000> starexp_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_starexp & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_starexp & msg);
		static ::proto_ff::Sheet_starexp* new_pbmsg(){ return new ::proto_ff::Sheet_starexp(); }
		static ::proto_ff::Sheet_starexp make_pbmsg(){ return ::proto_ff::Sheet_starexp(); }
	};
	typedef struct Sheet_starexp_s Sheet_starexp_t;

	struct starastrology_s : public NFDescStoreSeqOP {
		starastrology_s();
		int CreateInit();
		int ResumeInit();
		int32_t astrology;
		int64_t itemId;
		int32_t itemNum;
		int32_t fragment;
		int32_t essence;
		int32_t time;
		int32_t coinTye;
		int32_t number;
		NFArray<int32_t, 5> gailv;
		NFArray<int32_t, 5> probability;

		virtual void write_to_pbmsg(::proto_ff::starastrology & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::starastrology & msg);
		static ::proto_ff::starastrology* new_pbmsg(){ return new ::proto_ff::starastrology(); }
		static ::proto_ff::starastrology make_pbmsg(){ return ::proto_ff::starastrology(); }
	};
	typedef struct starastrology_s starastrology_t;

	struct Sheet_starastrology_s : public NFDescStoreSeqOP {
		Sheet_starastrology_s();
		int CreateInit();
		int ResumeInit();
		NFArray<struct starastrology_s, 20> starastrology_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_starastrology & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_starastrology & msg);
		static ::proto_ff::Sheet_starastrology* new_pbmsg(){ return new ::proto_ff::Sheet_starastrology(); }
		static ::proto_ff::Sheet_starastrology make_pbmsg(){ return ::proto_ff::Sheet_starastrology(); }
	};
	typedef struct Sheet_starastrology_s Sheet_starastrology_t;

}

