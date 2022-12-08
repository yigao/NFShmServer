#pragma once

#include <stdint.h>
#include <NFComm/NFShmCore/NFShmString.h>
#include <NFComm/NFShmCore/NFArray.h>
#include <NFComm/NFShmCore/NFSeqOP.h>
#include <NFComm/NFShmCore/NFShmMgr.h>
#include "skill.pb.h"
#include "skill_s.h"

namespace proto_ff_s {

	struct skillbuff_s : public NFDescStoreSeqOP {
		skillbuff_s();
		virtual ~skillbuff_s(){}
		int CreateInit();
		int ResumeInit();
		int64_t buffID;
		NFShmString<60> buffName;
		NFShmString<60> buffIcon;
		NFShmString<60> effectResources;
		int32_t showTpye;
		int32_t startProbability;
		int32_t Probability_up;
		int32_t startType;
		NFShmString<60> startTypeValue;
		int32_t endType;
		NFShmString<60> endTypeValue;
		int32_t group;
		NFShmString<60> buffRule;
		NFShmString<60> immune;
		NFShmString<60> dispel;
		int32_t buffCd;
		int32_t effect_Time;
		int32_t effect_Type;
		NFShmString<60> effect_Param;
		int32_t effect_up;

		virtual void write_to_pbmsg(::proto_ff::skillbuff & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::skillbuff & msg);
		static ::proto_ff::skillbuff* new_pbmsg(){ return new ::proto_ff::skillbuff(); }
		static ::proto_ff::skillbuff make_pbmsg(){ return ::proto_ff::skillbuff(); }
	};
	typedef struct skillbuff_s skillbuff_t;

	struct Sheet_skillbuff_s : public NFDescStoreSeqOP {
		Sheet_skillbuff_s();
		virtual ~Sheet_skillbuff_s(){}
		int CreateInit();
		int ResumeInit();
		NFArray<struct skillbuff_s, 100> skillbuff_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_skillbuff & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_skillbuff & msg);
		static ::proto_ff::Sheet_skillbuff* new_pbmsg(){ return new ::proto_ff::Sheet_skillbuff(); }
		static ::proto_ff::Sheet_skillbuff make_pbmsg(){ return ::proto_ff::Sheet_skillbuff(); }
	};
	typedef struct Sheet_skillbuff_s Sheet_skillbuff_t;

	struct skillskilladvanceType1buffDesc_s : public NFDescStoreSeqOP {
		skillskilladvanceType1buffDesc_s();
		virtual ~skillskilladvanceType1buffDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int64_t ID;

		virtual void write_to_pbmsg(::proto_ff::skillskilladvanceType1buffDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::skillskilladvanceType1buffDesc & msg);
		static ::proto_ff::skillskilladvanceType1buffDesc* new_pbmsg(){ return new ::proto_ff::skillskilladvanceType1buffDesc(); }
		static ::proto_ff::skillskilladvanceType1buffDesc make_pbmsg(){ return ::proto_ff::skillskilladvanceType1buffDesc(); }
	};
	typedef struct skillskilladvanceType1buffDesc_s skillskilladvanceType1buffDesc_t;

	struct skillskilladvanceType2buffDesc_s : public NFDescStoreSeqOP {
		skillskilladvanceType2buffDesc_s();
		virtual ~skillskilladvanceType2buffDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int64_t ID;

		virtual void write_to_pbmsg(::proto_ff::skillskilladvanceType2buffDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::skillskilladvanceType2buffDesc & msg);
		static ::proto_ff::skillskilladvanceType2buffDesc* new_pbmsg(){ return new ::proto_ff::skillskilladvanceType2buffDesc(); }
		static ::proto_ff::skillskilladvanceType2buffDesc make_pbmsg(){ return ::proto_ff::skillskilladvanceType2buffDesc(); }
	};
	typedef struct skillskilladvanceType2buffDesc_s skillskilladvanceType2buffDesc_t;

	struct skillskillawakebuffDesc_s : public NFDescStoreSeqOP {
		skillskillawakebuffDesc_s();
		virtual ~skillskillawakebuffDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int64_t ID;

		virtual void write_to_pbmsg(::proto_ff::skillskillawakebuffDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::skillskillawakebuffDesc & msg);
		static ::proto_ff::skillskillawakebuffDesc* new_pbmsg(){ return new ::proto_ff::skillskillawakebuffDesc(); }
		static ::proto_ff::skillskillawakebuffDesc make_pbmsg(){ return ::proto_ff::skillskillawakebuffDesc(); }
	};
	typedef struct skillskillawakebuffDesc_s skillskillawakebuffDesc_t;

	struct skillskilladvanceType3buffDesc_s : public NFDescStoreSeqOP {
		skillskilladvanceType3buffDesc_s();
		virtual ~skillskilladvanceType3buffDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int64_t ID;

		virtual void write_to_pbmsg(::proto_ff::skillskilladvanceType3buffDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::skillskilladvanceType3buffDesc & msg);
		static ::proto_ff::skillskilladvanceType3buffDesc* new_pbmsg(){ return new ::proto_ff::skillskilladvanceType3buffDesc(); }
		static ::proto_ff::skillskilladvanceType3buffDesc make_pbmsg(){ return ::proto_ff::skillskilladvanceType3buffDesc(); }
	};
	typedef struct skillskilladvanceType3buffDesc_s skillskilladvanceType3buffDesc_t;

	struct skillskillbuffDesc_s : public NFDescStoreSeqOP {
		skillskillbuffDesc_s();
		virtual ~skillskillbuffDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t Target;
		int64_t ID;
		int32_t Point;

		virtual void write_to_pbmsg(::proto_ff::skillskillbuffDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::skillskillbuffDesc & msg);
		static ::proto_ff::skillskillbuffDesc* new_pbmsg(){ return new ::proto_ff::skillskillbuffDesc(); }
		static ::proto_ff::skillskillbuffDesc make_pbmsg(){ return ::proto_ff::skillskillbuffDesc(); }
	};
	typedef struct skillskillbuffDesc_s skillskillbuffDesc_t;

	struct skillskill_s : public NFDescStoreSeqOP {
		skillskill_s();
		virtual ~skillskill_s(){}
		int CreateInit();
		int ResumeInit();
		int64_t skillID;
		NFShmString<60> name;
		int32_t skillType;
		int32_t group;
		int32_t position;
		int32_t displaceTime;
		int32_t displaceSign;
		NFShmString<60> displaceSpeed;
		NFShmString<60> disTimes;
		int32_t breakType;
		int32_t cdSkill;
		int64_t Relation;
		NFShmString<60> unlockCondition;
		int32_t type;
		int32_t cd;
		int32_t noLock;
		int32_t priority;
		NFShmString<60> fighting;
		float fightingParama;
		int32_t releaseType;
		int32_t processTypes;
		int32_t flySpeed;
		int32_t actTime;
		int32_t readyTime;
		int32_t attackTime;
		NFShmString<60> damageTime;
		int32_t attackDistance;
		int32_t rangeType;
		NFShmString<60> rangeTypeValue;
		int32_t warn;
		int32_t dazeTime;
		int32_t warnTime;
		NFShmString<60> infomationId;
		int32_t attackMinDistance;
		int32_t goalMaxNum;
		int32_t goalMaxNumMonster;
		int32_t damageType;
		int32_t damageRate;
		int32_t awakeDamageRate;
		int32_t advanceType1DamageRate;
		int32_t advanceType2DamageRate;
		int32_t advanceType3DamageRate;
		int32_t damageValue;
		float damageParama;
		int32_t addhitrate;
		int32_t awakeItemId;
		int32_t awakeCostNum;
		NFArray<struct skillskilladvanceType1buffDesc_s, 5> advanceType1buff;
		NFArray<struct skillskilladvanceType2buffDesc_s, 5> advanceType2buff;
		NFArray<struct skillskillawakebuffDesc_s, 5> awakebuff;
		NFArray<struct skillskilladvanceType3buffDesc_s, 5> advanceType3buff;
		NFArray<struct skillskillbuffDesc_s, 5> buff;

		virtual void write_to_pbmsg(::proto_ff::skillskill & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::skillskill & msg);
		static ::proto_ff::skillskill* new_pbmsg(){ return new ::proto_ff::skillskill(); }
		static ::proto_ff::skillskill make_pbmsg(){ return ::proto_ff::skillskill(); }
	};
	typedef struct skillskill_s skillskill_t;

	struct Sheet_skillskill_s : public NFDescStoreSeqOP {
		Sheet_skillskill_s();
		virtual ~Sheet_skillskill_s(){}
		int CreateInit();
		int ResumeInit();
		NFArray<struct skillskill_s, 180> skillskill_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_skillskill & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_skillskill & msg);
		static ::proto_ff::Sheet_skillskill* new_pbmsg(){ return new ::proto_ff::Sheet_skillskill(); }
		static ::proto_ff::Sheet_skillskill make_pbmsg(){ return ::proto_ff::Sheet_skillskill(); }
	};
	typedef struct Sheet_skillskill_s Sheet_skillskill_t;

	struct skillbuffUp_s : public NFDescStoreSeqOP {
		skillbuffUp_s();
		virtual ~skillbuffUp_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t id;
		int32_t AddStartProbability;
		int32_t attributeId;
		int32_t parama;

		virtual void write_to_pbmsg(::proto_ff::skillbuffUp & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::skillbuffUp & msg);
		static ::proto_ff::skillbuffUp* new_pbmsg(){ return new ::proto_ff::skillbuffUp(); }
		static ::proto_ff::skillbuffUp make_pbmsg(){ return ::proto_ff::skillbuffUp(); }
	};
	typedef struct skillbuffUp_s skillbuffUp_t;

	struct Sheet_skillbuffUp_s : public NFDescStoreSeqOP {
		Sheet_skillbuffUp_s();
		virtual ~Sheet_skillbuffUp_s(){}
		int CreateInit();
		int ResumeInit();
		NFArray<struct skillbuffUp_s, 40> skillbuffUp_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_skillbuffUp & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_skillbuffUp & msg);
		static ::proto_ff::Sheet_skillbuffUp* new_pbmsg(){ return new ::proto_ff::Sheet_skillbuffUp(); }
		static ::proto_ff::Sheet_skillbuffUp make_pbmsg(){ return ::proto_ff::Sheet_skillbuffUp(); }
	};
	typedef struct Sheet_skillbuffUp_s Sheet_skillbuffUp_t;

	struct skillskillUp_s : public NFDescStoreSeqOP {
		skillskillUp_s();
		virtual ~skillskillUp_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t id;
		int32_t group;
		int32_t skillLv;
		NFShmString<80> skillIds;
		int32_t roleLv;
		int64_t costItemId;
		int32_t costNum;

		virtual void write_to_pbmsg(::proto_ff::skillskillUp & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::skillskillUp & msg);
		static ::proto_ff::skillskillUp* new_pbmsg(){ return new ::proto_ff::skillskillUp(); }
		static ::proto_ff::skillskillUp make_pbmsg(){ return ::proto_ff::skillskillUp(); }
	};
	typedef struct skillskillUp_s skillskillUp_t;

	struct Sheet_skillskillUp_s : public NFDescStoreSeqOP {
		Sheet_skillskillUp_s();
		virtual ~Sheet_skillskillUp_s(){}
		int CreateInit();
		int ResumeInit();
		NFArray<struct skillskillUp_s, 140> skillskillUp_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_skillskillUp & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_skillskillUp & msg);
		static ::proto_ff::Sheet_skillskillUp* new_pbmsg(){ return new ::proto_ff::Sheet_skillskillUp(); }
		static ::proto_ff::Sheet_skillskillUp make_pbmsg(){ return ::proto_ff::Sheet_skillskillUp(); }
	};
	typedef struct Sheet_skillskillUp_s Sheet_skillskillUp_t;

	struct skillskillAwake_s : public NFDescStoreSeqOP {
		skillskillAwake_s();
		virtual ~skillskillAwake_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t skillId;
		int32_t costItemId;
		int32_t costNum;

		virtual void write_to_pbmsg(::proto_ff::skillskillAwake & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::skillskillAwake & msg);
		static ::proto_ff::skillskillAwake* new_pbmsg(){ return new ::proto_ff::skillskillAwake(); }
		static ::proto_ff::skillskillAwake make_pbmsg(){ return ::proto_ff::skillskillAwake(); }
	};
	typedef struct skillskillAwake_s skillskillAwake_t;

	struct Sheet_skillskillAwake_s : public NFDescStoreSeqOP {
		Sheet_skillskillAwake_s();
		virtual ~Sheet_skillskillAwake_s(){}
		int CreateInit();
		int ResumeInit();
		NFArray<struct skillskillAwake_s, 20> skillskillAwake_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_skillskillAwake & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_skillskillAwake & msg);
		static ::proto_ff::Sheet_skillskillAwake* new_pbmsg(){ return new ::proto_ff::Sheet_skillskillAwake(); }
		static ::proto_ff::Sheet_skillskillAwake make_pbmsg(){ return ::proto_ff::Sheet_skillskillAwake(); }
	};
	typedef struct Sheet_skillskillAwake_s Sheet_skillskillAwake_t;

}

