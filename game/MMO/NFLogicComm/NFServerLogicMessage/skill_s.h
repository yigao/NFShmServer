#pragma once

#include <stdint.h>
#include <NFComm/NFShmCore/NFSizeString.h>
#include <NFComm/NFShmCore/NFArray.h>
#include <NFComm/NFShmCore/NFSeqOP.h>
#include <NFComm/NFShmCore/NFShmMgr.h>
#include "skill.pb.h"
#include "skill_s.h"

namespace proto_ff_s {

	struct skillskillstateBagDesc_s : public NFDescStoreSeqOP {
		skillskillstateBagDesc_s();
		int CreateInit();
		int ResumeInit();
		int32_t Target;
		int32_t Point;
		NFSizeString<60> Parameter;
		NFSizeString<60> Rate;
		NFSizeString<60> Time;
		int32_t Type;
		int64_t ID;

		virtual void write_to_pbmsg(::proto_ff::skillskillstateBagDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::skillskillstateBagDesc & msg);
		static ::proto_ff::skillskillstateBagDesc* new_pbmsg(){ return new ::proto_ff::skillskillstateBagDesc(); }
		static ::proto_ff::skillskillstateBagDesc make_pbmsg(){ return ::proto_ff::skillskillstateBagDesc(); }
	};
	typedef struct skillskillstateBagDesc_s skillskillstateBagDesc_t;

	struct skillskill_s : public NFDescStoreSeqOP {
		skillskill_s();
		int CreateInit();
		int ResumeInit();
		int64_t skillID;
		NFSizeString<60> name;
		int32_t skillType;
		int32_t specialSkill;
		int32_t cdSkill;
		int64_t Relation;
		int64_t AddSkill;
		int32_t AddSkillTime;
		int32_t unlockLevel;
		int32_t type;
		int32_t cd;
		int32_t priority;
		NFSizeString<60> fighting;
		int32_t releaseType;
		int32_t processTypes;
		int32_t flySpeed;
		int32_t readyTime;
		int32_t attackTime;
		NFSizeString<80> damageTime;
		int32_t displaceTime;
		int32_t displaceSign;
		NFSizeString<60> displaceSpeed;
		NFSizeString<60> disTimes;
		int32_t attackDistance;
		int32_t rangeType;
		NFSizeString<60> rangeTypeValue;
		int32_t warn;
		int32_t dazeTime;
		int32_t warnTime;
		NFSizeString<60> infomationId;
		int32_t summonType;
		NFSizeString<60> summonValue;
		int32_t attackMinDistance;
		int32_t goalMaxNum;
		int32_t damageType;
		NFSizeString<60> attackValue;
		NFSizeString<60> attackRate;
		NFSizeString<60> damageValue;
		NFSizeString<100> damageRate;
		int32_t addhitrate;
		NFArray<struct skillskillstateBagDesc_s, 16> stateBag;

		virtual void write_to_pbmsg(::proto_ff::skillskill & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::skillskill & msg);
		static ::proto_ff::skillskill* new_pbmsg(){ return new ::proto_ff::skillskill(); }
		static ::proto_ff::skillskill make_pbmsg(){ return ::proto_ff::skillskill(); }
	};
	typedef struct skillskill_s skillskill_t;

	struct Sheet_skillskill_s : public NFDescStoreSeqOP {
		Sheet_skillskill_s();
		int CreateInit();
		int ResumeInit();
		NFArray<struct skillskill_s, 2000> skillskill_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_skillskill & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_skillskill & msg);
		static ::proto_ff::Sheet_skillskill* new_pbmsg(){ return new ::proto_ff::Sheet_skillskill(); }
		static ::proto_ff::Sheet_skillskill make_pbmsg(){ return ::proto_ff::Sheet_skillskill(); }
	};
	typedef struct Sheet_skillskill_s Sheet_skillskill_t;

	struct skillbuffeffectDesc_s : public NFDescStoreSeqOP {
		skillbuffeffectDesc_s();
		int CreateInit();
		int ResumeInit();
		int32_t Type;
		NFSizeString<60> Param;

		virtual void write_to_pbmsg(::proto_ff::skillbuffeffectDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::skillbuffeffectDesc & msg);
		static ::proto_ff::skillbuffeffectDesc* new_pbmsg(){ return new ::proto_ff::skillbuffeffectDesc(); }
		static ::proto_ff::skillbuffeffectDesc make_pbmsg(){ return ::proto_ff::skillbuffeffectDesc(); }
	};
	typedef struct skillbuffeffectDesc_s skillbuffeffectDesc_t;

	struct skillbuff_s : public NFDescStoreSeqOP {
		skillbuff_s();
		int CreateInit();
		int ResumeInit();
		int64_t stateBagID;
		NFSizeString<80> stateBagName;
		NFSizeString<60> stateBagIcon;
		NFSizeString<60> effectResources;
		int32_t startType;
		int32_t startProbability;
		NFSizeString<60> startTypeValue;
		NFSizeString<60> endType;
		int32_t save;
		NFSizeString<60> stateBagRule;
		int32_t label;
		int32_t mask;
		NFSizeString<60> stateBagCd;
		NFArray<struct skillbuffeffectDesc_s, 5> effect;

		virtual void write_to_pbmsg(::proto_ff::skillbuff & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::skillbuff & msg);
		static ::proto_ff::skillbuff* new_pbmsg(){ return new ::proto_ff::skillbuff(); }
		static ::proto_ff::skillbuff make_pbmsg(){ return ::proto_ff::skillbuff(); }
	};
	typedef struct skillbuff_s skillbuff_t;

	struct Sheet_skillbuff_s : public NFDescStoreSeqOP {
		Sheet_skillbuff_s();
		int CreateInit();
		int ResumeInit();
		NFArray<struct skillbuff_s, 400> skillbuff_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_skillbuff & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_skillbuff & msg);
		static ::proto_ff::Sheet_skillbuff* new_pbmsg(){ return new ::proto_ff::Sheet_skillbuff(); }
		static ::proto_ff::Sheet_skillbuff make_pbmsg(){ return ::proto_ff::Sheet_skillbuff(); }
	};
	typedef struct Sheet_skillbuff_s Sheet_skillbuff_t;

}

