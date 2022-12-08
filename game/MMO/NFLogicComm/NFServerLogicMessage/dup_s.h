#pragma once

#include <stdint.h>
#include <NFComm/NFShmCore/NFShmString.h>
#include <NFComm/NFShmCore/NFArray.h>
#include <NFComm/NFShmCore/NFSeqOP.h>
#include <NFComm/NFShmCore/NFShmMgr.h>
#include "dup.pb.h"
#include "dup_s.h"

namespace proto_ff_s {

	struct dupBPlevel_s : public NFDescStoreSeqOP {
		dupBPlevel_s();
		virtual ~dupBPlevel_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t lv;
		NFArray<int64_t, 5> Bgdup;

		virtual void write_to_pbmsg(::proto_ff::dupBPlevel & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::dupBPlevel & msg);
		static ::proto_ff::dupBPlevel* new_pbmsg(){ return new ::proto_ff::dupBPlevel(); }
		static ::proto_ff::dupBPlevel make_pbmsg(){ return ::proto_ff::dupBPlevel(); }
	};
	typedef struct dupBPlevel_s dupBPlevel_t;

	struct Sheet_dupBPlevel_s : public NFDescStoreSeqOP {
		Sheet_dupBPlevel_s();
		virtual ~Sheet_dupBPlevel_s(){}
		int CreateInit();
		int ResumeInit();
		NFArray<struct dupBPlevel_s, 1100> dupBPlevel_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_dupBPlevel & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_dupBPlevel & msg);
		static ::proto_ff::Sheet_dupBPlevel* new_pbmsg(){ return new ::proto_ff::Sheet_dupBPlevel(); }
		static ::proto_ff::Sheet_dupBPlevel make_pbmsg(){ return ::proto_ff::Sheet_dupBPlevel(); }
	};
	typedef struct Sheet_dupBPlevel_s Sheet_dupBPlevel_t;

	struct dupdup_s : public NFDescStoreSeqOP {
		dupdup_s();
		virtual ~dupdup_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t ID;
		int32_t scripID;
		int32_t scripType;
		int32_t dupLevel;
		int32_t groupID;
		int32_t layer;
		int32_t duplicateType;
		int64_t mapID;
		int32_t levelLimit;
		int32_t pre;
		int32_t isAutoFight;
		NFShmString<60> condition;
		int32_t reviveMaxTimes;
		int32_t TeamObjectID;
		NFShmString<60> gradeCondition;
		int64_t sweepRewardBoxID;
		int32_t sweepRewardExp;
		NFShmString<60> trackpoint;
		NFShmString<60> pathOfmonster;
		int32_t isPatrol;
		int32_t sweepType;
		NFArray<int32_t, 3> box;

		virtual void write_to_pbmsg(::proto_ff::dupdup & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::dupdup & msg);
		static ::proto_ff::dupdup* new_pbmsg(){ return new ::proto_ff::dupdup(); }
		static ::proto_ff::dupdup make_pbmsg(){ return ::proto_ff::dupdup(); }
	};
	typedef struct dupdup_s dupdup_t;

	struct Sheet_dupdup_s : public NFDescStoreSeqOP {
		Sheet_dupdup_s();
		virtual ~Sheet_dupdup_s(){}
		int CreateInit();
		int ResumeInit();
		NFArray<struct dupdup_s, 80> dupdup_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_dupdup & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_dupdup & msg);
		static ::proto_ff::Sheet_dupdup* new_pbmsg(){ return new ::proto_ff::Sheet_dupdup(); }
		static ::proto_ff::Sheet_dupdup make_pbmsg(){ return ::proto_ff::Sheet_dupdup(); }
	};
	typedef struct Sheet_dupdup_s Sheet_dupdup_t;

	struct duptowerReward_s : public NFDescStoreSeqOP {
		duptowerReward_s();
		virtual ~duptowerReward_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t id;
		int32_t type;
		int32_t cond;
		int32_t boxID;

		virtual void write_to_pbmsg(::proto_ff::duptowerReward & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::duptowerReward & msg);
		static ::proto_ff::duptowerReward* new_pbmsg(){ return new ::proto_ff::duptowerReward(); }
		static ::proto_ff::duptowerReward make_pbmsg(){ return ::proto_ff::duptowerReward(); }
	};
	typedef struct duptowerReward_s duptowerReward_t;

	struct Sheet_duptowerReward_s : public NFDescStoreSeqOP {
		Sheet_duptowerReward_s();
		virtual ~Sheet_duptowerReward_s(){}
		int CreateInit();
		int ResumeInit();
		NFArray<struct duptowerReward_s, 20> duptowerReward_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_duptowerReward & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_duptowerReward & msg);
		static ::proto_ff::Sheet_duptowerReward* new_pbmsg(){ return new ::proto_ff::Sheet_duptowerReward(); }
		static ::proto_ff::Sheet_duptowerReward make_pbmsg(){ return ::proto_ff::Sheet_duptowerReward(); }
	};
	typedef struct Sheet_duptowerReward_s Sheet_duptowerReward_t;

	struct dupgroup_s : public NFDescStoreSeqOP {
		dupgroup_s();
		virtual ~dupgroup_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t id;
		NFShmString<60> name;
		int32_t privilegeType;
		int32_t dynamiclevel;
		int32_t groupTimesType;
		int32_t groupTimes;
		int32_t enterItemID;
		int32_t sweepCondition;
		int32_t mergeCondition;
		int32_t addItemID;
		int32_t buyType;
		int32_t buyItemId;
		NFShmString<60> buyCost;
		int32_t countDown;
		int32_t endDown;
		int32_t accountDown;
		int32_t funcionID;

		virtual void write_to_pbmsg(::proto_ff::dupgroup & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::dupgroup & msg);
		static ::proto_ff::dupgroup* new_pbmsg(){ return new ::proto_ff::dupgroup(); }
		static ::proto_ff::dupgroup make_pbmsg(){ return ::proto_ff::dupgroup(); }
	};
	typedef struct dupgroup_s dupgroup_t;

	struct Sheet_dupgroup_s : public NFDescStoreSeqOP {
		Sheet_dupgroup_s();
		virtual ~Sheet_dupgroup_s(){}
		int CreateInit();
		int ResumeInit();
		NFArray<struct dupgroup_s, 20> dupgroup_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_dupgroup & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_dupgroup & msg);
		static ::proto_ff::Sheet_dupgroup* new_pbmsg(){ return new ::proto_ff::Sheet_dupgroup(); }
		static ::proto_ff::Sheet_dupgroup make_pbmsg(){ return ::proto_ff::Sheet_dupgroup(); }
	};
	typedef struct Sheet_dupgroup_s Sheet_dupgroup_t;

}

