#pragma once

#include <stdint.h>
#include <NFComm/NFShmCore/NFShmString.h>
#include <NFComm/NFShmStl/NFShmVector.h>
#include <NFComm/NFShmCore/NFSeqOP.h>
#include <NFComm/NFShmCore/NFShmMgr.h>
#include "daily.pb.h"
#include "daily_s.h"

namespace proto_ff_s {

	struct E_DailyDaily_s : public NFDescStoreSeqOP {
		E_DailyDaily_s();
		virtual ~E_DailyDaily_s(){}
		int CreateInit();
		int ResumeInit();
		int64_t m_id;
		NFShmString<60> m_name;
		int32_t m_type;
		int32_t m_args;
		int32_t m_playtype;
		int32_t m_playargs;
		int64_t m_funciontid;
		int32_t m_number;
		int32_t m_eachscore;
		int32_t m_cycle;
		int32_t m_regreward;

		virtual void write_to_pbmsg(::proto_ff::E_DailyDaily & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_DailyDaily & msg);
		static ::proto_ff::E_DailyDaily* new_pbmsg(){ return new ::proto_ff::E_DailyDaily(); }
		static ::proto_ff::E_DailyDaily make_pbmsg(){ return ::proto_ff::E_DailyDaily(); }
	};
	typedef struct E_DailyDaily_s E_DailyDaily_t;

	struct Sheet_DailyDaily_s : public NFDescStoreSeqOP {
		Sheet_DailyDaily_s();
		virtual ~Sheet_DailyDaily_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_DailyDaily_s, 60> E_DailyDaily_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_DailyDaily & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_DailyDaily & msg);
		static ::proto_ff::Sheet_DailyDaily* new_pbmsg(){ return new ::proto_ff::Sheet_DailyDaily(); }
		static ::proto_ff::Sheet_DailyDaily make_pbmsg(){ return ::proto_ff::Sheet_DailyDaily(); }
	};
	typedef struct Sheet_DailyDaily_s Sheet_DailyDaily_t;

	struct E_DailyReward_s : public NFDescStoreSeqOP {
		E_DailyReward_s();
		virtual ~E_DailyReward_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;
		int32_t m_type;
		int32_t m_activescore;
		int64_t m_rewardid;
		int32_t m_rewardnum;

		virtual void write_to_pbmsg(::proto_ff::E_DailyReward & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_DailyReward & msg);
		static ::proto_ff::E_DailyReward* new_pbmsg(){ return new ::proto_ff::E_DailyReward(); }
		static ::proto_ff::E_DailyReward make_pbmsg(){ return ::proto_ff::E_DailyReward(); }
	};
	typedef struct E_DailyReward_s E_DailyReward_t;

	struct Sheet_DailyReward_s : public NFDescStoreSeqOP {
		Sheet_DailyReward_s();
		virtual ~Sheet_DailyReward_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_DailyReward_s, 20> E_DailyReward_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_DailyReward & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_DailyReward & msg);
		static ::proto_ff::Sheet_DailyReward* new_pbmsg(){ return new ::proto_ff::Sheet_DailyReward(); }
		static ::proto_ff::Sheet_DailyReward make_pbmsg(){ return ::proto_ff::Sheet_DailyReward(); }
	};
	typedef struct Sheet_DailyReward_s Sheet_DailyReward_t;

	struct E_DailyCultivateAttributeDesc_s : public NFDescStoreSeqOP {
		E_DailyCultivateAttributeDesc_s();
		virtual ~E_DailyCultivateAttributeDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;
		int32_t m_value;

		virtual void write_to_pbmsg(::proto_ff::E_DailyCultivateAttributeDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_DailyCultivateAttributeDesc & msg);
		static ::proto_ff::E_DailyCultivateAttributeDesc* new_pbmsg(){ return new ::proto_ff::E_DailyCultivateAttributeDesc(); }
		static ::proto_ff::E_DailyCultivateAttributeDesc make_pbmsg(){ return ::proto_ff::E_DailyCultivateAttributeDesc(); }
	};
	typedef struct E_DailyCultivateAttributeDesc_s E_DailyCultivateAttributeDesc_t;

	struct E_DailyCultivate_s : public NFDescStoreSeqOP {
		E_DailyCultivate_s();
		virtual ~E_DailyCultivate_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;
		int32_t m_lv;
		int32_t m_exp;
		NFShmVector<struct E_DailyCultivateAttributeDesc_s, 4> m_attribute;

		virtual void write_to_pbmsg(::proto_ff::E_DailyCultivate & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_DailyCultivate & msg);
		static ::proto_ff::E_DailyCultivate* new_pbmsg(){ return new ::proto_ff::E_DailyCultivate(); }
		static ::proto_ff::E_DailyCultivate make_pbmsg(){ return ::proto_ff::E_DailyCultivate(); }
	};
	typedef struct E_DailyCultivate_s E_DailyCultivate_t;

	struct Sheet_DailyCultivate_s : public NFDescStoreSeqOP {
		Sheet_DailyCultivate_s();
		virtual ~Sheet_DailyCultivate_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_DailyCultivate_s, 80> E_DailyCultivate_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_DailyCultivate & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_DailyCultivate & msg);
		static ::proto_ff::Sheet_DailyCultivate* new_pbmsg(){ return new ::proto_ff::Sheet_DailyCultivate(); }
		static ::proto_ff::Sheet_DailyCultivate make_pbmsg(){ return ::proto_ff::Sheet_DailyCultivate(); }
	};
	typedef struct Sheet_DailyCultivate_s Sheet_DailyCultivate_t;

}

