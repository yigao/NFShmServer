#pragma once

#include <stdint.h>
#include <NFComm/NFShmCore/NFShmString.h>
#include <NFComm/NFShmCore/NFArray.h>
#include <NFComm/NFShmCore/NFSeqOP.h>
#include <NFComm/NFShmCore/NFShmMgr.h>
#include "daily.pb.h"
#include "daily_s.h"

namespace proto_ff_s {

	struct dailydaily_s : public NFDescStoreSeqOP {
		dailydaily_s();
		virtual ~dailydaily_s(){}
		int CreateInit();
		int ResumeInit();
		int64_t id;
		NFShmString<60> name;
		int32_t type;
		int32_t args;
		int32_t playType;
		int32_t playArgs;
		int64_t funciontID;
		int32_t number;
		int32_t viptype;
		int32_t otherNum;
		int32_t eachScore;
		int32_t cycle;
		int32_t regReward;

		virtual void write_to_pbmsg(::proto_ff::dailydaily & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::dailydaily & msg);
		static ::proto_ff::dailydaily* new_pbmsg(){ return new ::proto_ff::dailydaily(); }
		static ::proto_ff::dailydaily make_pbmsg(){ return ::proto_ff::dailydaily(); }
	};
	typedef struct dailydaily_s dailydaily_t;

	struct Sheet_dailydaily_s : public NFDescStoreSeqOP {
		Sheet_dailydaily_s();
		virtual ~Sheet_dailydaily_s(){}
		int CreateInit();
		int ResumeInit();
		NFArray<struct dailydaily_s, 20> dailydaily_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_dailydaily & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_dailydaily & msg);
		static ::proto_ff::Sheet_dailydaily* new_pbmsg(){ return new ::proto_ff::Sheet_dailydaily(); }
		static ::proto_ff::Sheet_dailydaily make_pbmsg(){ return ::proto_ff::Sheet_dailydaily(); }
	};
	typedef struct Sheet_dailydaily_s Sheet_dailydaily_t;

	struct dailyreward_s : public NFDescStoreSeqOP {
		dailyreward_s();
		virtual ~dailyreward_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t id;
		int32_t type;
		int32_t activeScore;
		int64_t rewardId;
		int32_t rewardNum;

		virtual void write_to_pbmsg(::proto_ff::dailyreward & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::dailyreward & msg);
		static ::proto_ff::dailyreward* new_pbmsg(){ return new ::proto_ff::dailyreward(); }
		static ::proto_ff::dailyreward make_pbmsg(){ return ::proto_ff::dailyreward(); }
	};
	typedef struct dailyreward_s dailyreward_t;

	struct Sheet_dailyreward_s : public NFDescStoreSeqOP {
		Sheet_dailyreward_s();
		virtual ~Sheet_dailyreward_s(){}
		int CreateInit();
		int ResumeInit();
		NFArray<struct dailyreward_s, 20> dailyreward_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_dailyreward & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_dailyreward & msg);
		static ::proto_ff::Sheet_dailyreward* new_pbmsg(){ return new ::proto_ff::Sheet_dailyreward(); }
		static ::proto_ff::Sheet_dailyreward make_pbmsg(){ return ::proto_ff::Sheet_dailyreward(); }
	};
	typedef struct Sheet_dailyreward_s Sheet_dailyreward_t;

	struct dailycultivateattributeDesc_s : public NFDescStoreSeqOP {
		dailycultivateattributeDesc_s();
		virtual ~dailycultivateattributeDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t ID;
		int32_t Value;

		virtual void write_to_pbmsg(::proto_ff::dailycultivateattributeDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::dailycultivateattributeDesc & msg);
		static ::proto_ff::dailycultivateattributeDesc* new_pbmsg(){ return new ::proto_ff::dailycultivateattributeDesc(); }
		static ::proto_ff::dailycultivateattributeDesc make_pbmsg(){ return ::proto_ff::dailycultivateattributeDesc(); }
	};
	typedef struct dailycultivateattributeDesc_s dailycultivateattributeDesc_t;

	struct dailycultivate_s : public NFDescStoreSeqOP {
		dailycultivate_s();
		virtual ~dailycultivate_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t ID;
		int32_t lv;
		int32_t exp;
		NFArray<struct dailycultivateattributeDesc_s, 4> attribute;

		virtual void write_to_pbmsg(::proto_ff::dailycultivate & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::dailycultivate & msg);
		static ::proto_ff::dailycultivate* new_pbmsg(){ return new ::proto_ff::dailycultivate(); }
		static ::proto_ff::dailycultivate make_pbmsg(){ return ::proto_ff::dailycultivate(); }
	};
	typedef struct dailycultivate_s dailycultivate_t;

	struct Sheet_dailycultivate_s : public NFDescStoreSeqOP {
		Sheet_dailycultivate_s();
		virtual ~Sheet_dailycultivate_s(){}
		int CreateInit();
		int ResumeInit();
		NFArray<struct dailycultivate_s, 40> dailycultivate_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_dailycultivate & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_dailycultivate & msg);
		static ::proto_ff::Sheet_dailycultivate* new_pbmsg(){ return new ::proto_ff::Sheet_dailycultivate(); }
		static ::proto_ff::Sheet_dailycultivate make_pbmsg(){ return ::proto_ff::Sheet_dailycultivate(); }
	};
	typedef struct Sheet_dailycultivate_s Sheet_dailycultivate_t;

}

