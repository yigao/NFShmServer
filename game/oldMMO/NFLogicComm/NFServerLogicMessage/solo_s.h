#pragma once

#include <stdint.h>
#include <NFComm/NFShmCore/NFSizeString.h>
#include <NFComm/NFShmCore/NFArray.h>
#include <NFComm/NFShmCore/NFSeqOP.h>
#include <NFComm/NFShmCore/NFShmMgr.h>
#include "solo.pb.h"
#include "solo_s.h"

namespace proto_ff_s {

	struct soloduanweirewardDesc_s : public NFDescStoreSeqOP {
		soloduanweirewardDesc_s();
		int CreateInit();
		int ResumeInit();
		int32_t num;
		int64_t duanwei;

		virtual void write_to_pbmsg(::proto_ff::soloduanweirewardDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::soloduanweirewardDesc & msg);
		static ::proto_ff::soloduanweirewardDesc* new_pbmsg(){ return new ::proto_ff::soloduanweirewardDesc(); }
		static ::proto_ff::soloduanweirewardDesc make_pbmsg(){ return ::proto_ff::soloduanweirewardDesc(); }
	};
	typedef struct soloduanweirewardDesc_s soloduanweirewardDesc_t;

	struct soloduanweidayRewardItemDesc_s : public NFDescStoreSeqOP {
		soloduanweidayRewardItemDesc_s();
		int CreateInit();
		int ResumeInit();
		int32_t num;
		int64_t id;

		virtual void write_to_pbmsg(::proto_ff::soloduanweidayRewardItemDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::soloduanweidayRewardItemDesc & msg);
		static ::proto_ff::soloduanweidayRewardItemDesc* new_pbmsg(){ return new ::proto_ff::soloduanweidayRewardItemDesc(); }
		static ::proto_ff::soloduanweidayRewardItemDesc make_pbmsg(){ return ::proto_ff::soloduanweidayRewardItemDesc(); }
	};
	typedef struct soloduanweidayRewardItemDesc_s soloduanweidayRewardItemDesc_t;

	struct soloduanwei_s : public NFDescStoreSeqOP {
		soloduanwei_s();
		int CreateInit();
		int ResumeInit();
		int32_t duanweiID;
		int32_t pointMin;
		int32_t pointWin;
		int32_t pointLose;
		int32_t arenaWin;
		int32_t arenaLose;
		int32_t pipeiPoint;
		int32_t dayReward;
		int32_t diamondNum;
		NFArray<struct soloduanweirewardDesc_s, 3> reward;
		NFArray<struct soloduanweidayRewardItemDesc_s, 2> dayRewardItem;

		virtual void write_to_pbmsg(::proto_ff::soloduanwei & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::soloduanwei & msg);
		static ::proto_ff::soloduanwei* new_pbmsg(){ return new ::proto_ff::soloduanwei(); }
		static ::proto_ff::soloduanwei make_pbmsg(){ return ::proto_ff::soloduanwei(); }
	};
	typedef struct soloduanwei_s soloduanwei_t;

	struct Sheet_soloduanwei_s : public NFDescStoreSeqOP {
		Sheet_soloduanwei_s();
		int CreateInit();
		int ResumeInit();
		NFArray<struct soloduanwei_s, 40> soloduanwei_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_soloduanwei & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_soloduanwei & msg);
		static ::proto_ff::Sheet_soloduanwei* new_pbmsg(){ return new ::proto_ff::Sheet_soloduanwei(); }
		static ::proto_ff::Sheet_soloduanwei make_pbmsg(){ return ::proto_ff::Sheet_soloduanwei(); }
	};
	typedef struct Sheet_soloduanwei_s Sheet_soloduanwei_t;

	struct solorankrewardDesc_s : public NFDescStoreSeqOP {
		solorankrewardDesc_s();
		int CreateInit();
		int ResumeInit();
		int32_t num;
		int64_t rank;

		virtual void write_to_pbmsg(::proto_ff::solorankrewardDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::solorankrewardDesc & msg);
		static ::proto_ff::solorankrewardDesc* new_pbmsg(){ return new ::proto_ff::solorankrewardDesc(); }
		static ::proto_ff::solorankrewardDesc make_pbmsg(){ return ::proto_ff::solorankrewardDesc(); }
	};
	typedef struct solorankrewardDesc_s solorankrewardDesc_t;

	struct solorank_s : public NFDescStoreSeqOP {
		solorank_s();
		int CreateInit();
		int ResumeInit();
		int32_t rankID;
		int32_t maxRank;
		int32_t minRank;
		int32_t diamondNum;
		NFArray<struct solorankrewardDesc_s, 4> reward;

		virtual void write_to_pbmsg(::proto_ff::solorank & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::solorank & msg);
		static ::proto_ff::solorank* new_pbmsg(){ return new ::proto_ff::solorank(); }
		static ::proto_ff::solorank make_pbmsg(){ return ::proto_ff::solorank(); }
	};
	typedef struct solorank_s solorank_t;

	struct Sheet_solorank_s : public NFDescStoreSeqOP {
		Sheet_solorank_s();
		int CreateInit();
		int ResumeInit();
		NFArray<struct solorank_s, 20> solorank_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_solorank & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_solorank & msg);
		static ::proto_ff::Sheet_solorank* new_pbmsg(){ return new ::proto_ff::Sheet_solorank(); }
		static ::proto_ff::Sheet_solorank make_pbmsg(){ return ::proto_ff::Sheet_solorank(); }
	};
	typedef struct Sheet_solorank_s Sheet_solorank_t;

	struct solopipei_s : public NFDescStoreSeqOP {
		solopipei_s();
		int CreateInit();
		int ResumeInit();
		int32_t ID;
		int32_t num;
		int64_t reward;

		virtual void write_to_pbmsg(::proto_ff::solopipei & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::solopipei & msg);
		static ::proto_ff::solopipei* new_pbmsg(){ return new ::proto_ff::solopipei(); }
		static ::proto_ff::solopipei make_pbmsg(){ return ::proto_ff::solopipei(); }
	};
	typedef struct solopipei_s solopipei_t;

	struct Sheet_solopipei_s : public NFDescStoreSeqOP {
		Sheet_solopipei_s();
		int CreateInit();
		int ResumeInit();
		NFArray<struct solopipei_s, 20> solopipei_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_solopipei & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_solopipei & msg);
		static ::proto_ff::Sheet_solopipei* new_pbmsg(){ return new ::proto_ff::Sheet_solopipei(); }
		static ::proto_ff::Sheet_solopipei make_pbmsg(){ return ::proto_ff::Sheet_solopipei(); }
	};
	typedef struct Sheet_solopipei_s Sheet_solopipei_t;

	struct soloconstant_s : public NFDescStoreSeqOP {
		soloconstant_s();
		int CreateInit();
		int ResumeInit();
		int32_t ID;
		NFSizeString<80> constant;

		virtual void write_to_pbmsg(::proto_ff::soloconstant & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::soloconstant & msg);
		static ::proto_ff::soloconstant* new_pbmsg(){ return new ::proto_ff::soloconstant(); }
		static ::proto_ff::soloconstant make_pbmsg(){ return ::proto_ff::soloconstant(); }
	};
	typedef struct soloconstant_s soloconstant_t;

	struct Sheet_soloconstant_s : public NFDescStoreSeqOP {
		Sheet_soloconstant_s();
		int CreateInit();
		int ResumeInit();
		NFArray<struct soloconstant_s, 60> soloconstant_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_soloconstant & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_soloconstant & msg);
		static ::proto_ff::Sheet_soloconstant* new_pbmsg(){ return new ::proto_ff::Sheet_soloconstant(); }
		static ::proto_ff::Sheet_soloconstant make_pbmsg(){ return ::proto_ff::Sheet_soloconstant(); }
	};
	typedef struct Sheet_soloconstant_s Sheet_soloconstant_t;

}

