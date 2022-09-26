#pragma once

#include <stdint.h>
#include <NFComm/NFShmCore/NFSizeString.h>
#include <NFComm/NFShmCore/NFArray.h>
#include <NFComm/NFShmCore/NFSeqOP.h>
#include <NFComm/NFShmCore/NFShmMgr.h>
#include "monster.pb.h"
#include "monster_s.h"

namespace proto_ff_s {

	struct monstermonster_s : public NFDescStoreSeqOP {
		monstermonster_s();
		int CreateInit();
		int ResumeInit();
		int64_t monsterID;
		NFSizeString<32> monsterName;
		int32_t functionType;
		int64_t functionValue;
		int32_t profession;
		int32_t damageAddType;
		int32_t monsterLV;
		int32_t droplimit;
		int64_t displayID;
		int64_t valuetype;
		int64_t aiId;
		int32_t hpSectionNum;
		int32_t showGuild;
		int32_t breedProb;
		int64_t breedMonID;
		int32_t breedMonLive;
		NFSizeString<32> itemCost;
		int32_t isBornActionOn;
		int64_t exp;
		int32_t dropType;
		int32_t isBelongToPlayer;
		int64_t dropDefault;
		int64_t dropBoxID;
		int32_t ifMultiple;
		int64_t dropRool;
		int64_t lastBox;
		int32_t btnRange;
		int64_t btnId;

		virtual void write_to_pbmsg(::proto_ff::monstermonster & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::monstermonster & msg);
		static ::proto_ff::monstermonster* new_pbmsg(){ return new ::proto_ff::monstermonster(); }
		static ::proto_ff::monstermonster make_pbmsg(){ return ::proto_ff::monstermonster(); }
	};
	typedef struct monstermonster_s monstermonster_t;

	struct Sheet_monstermonster_s : public NFDescStoreSeqOP {
		Sheet_monstermonster_s();
		int CreateInit();
		int ResumeInit();
		NFArray<struct monstermonster_s, 2031> monstermonster_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_monstermonster & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_monstermonster & msg);
		static ::proto_ff::Sheet_monstermonster* new_pbmsg(){ return new ::proto_ff::Sheet_monstermonster(); }
		static ::proto_ff::Sheet_monstermonster make_pbmsg(){ return ::proto_ff::Sheet_monstermonster(); }
	};
	typedef struct Sheet_monstermonster_s Sheet_monstermonster_t;

	struct monsterdisplayskillDesc_s : public NFDescStoreSeqOP {
		monsterdisplayskillDesc_s();
		int CreateInit();
		int ResumeInit();
		int64_t id;

		virtual void write_to_pbmsg(::proto_ff::monsterdisplayskillDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::monsterdisplayskillDesc & msg);
		static ::proto_ff::monsterdisplayskillDesc* new_pbmsg(){ return new ::proto_ff::monsterdisplayskillDesc(); }
		static ::proto_ff::monsterdisplayskillDesc make_pbmsg(){ return ::proto_ff::monsterdisplayskillDesc(); }
	};
	typedef struct monsterdisplayskillDesc_s monsterdisplayskillDesc_t;

	struct monsterdisplay_s : public NFDescStoreSeqOP {
		monsterdisplay_s();
		int CreateInit();
		int ResumeInit();
		int64_t displayID;
		int32_t modelOffsetsX;
		int32_t modelOffsetsY;
		int32_t modelScale;
		int32_t modelRadius;
		int32_t pathRadius;
		int32_t collisionRadius;
		int32_t rSpeed;
		NFArray<struct monsterdisplayskillDesc_s, 7> skill;

		virtual void write_to_pbmsg(::proto_ff::monsterdisplay & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::monsterdisplay & msg);
		static ::proto_ff::monsterdisplay* new_pbmsg(){ return new ::proto_ff::monsterdisplay(); }
		static ::proto_ff::monsterdisplay make_pbmsg(){ return ::proto_ff::monsterdisplay(); }
	};
	typedef struct monsterdisplay_s monsterdisplay_t;

	struct Sheet_monsterdisplay_s : public NFDescStoreSeqOP {
		Sheet_monsterdisplay_s();
		int CreateInit();
		int ResumeInit();
		NFArray<struct monsterdisplay_s, 310> monsterdisplay_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_monsterdisplay & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_monsterdisplay & msg);
		static ::proto_ff::Sheet_monsterdisplay* new_pbmsg(){ return new ::proto_ff::Sheet_monsterdisplay(); }
		static ::proto_ff::Sheet_monsterdisplay make_pbmsg(){ return ::proto_ff::Sheet_monsterdisplay(); }
	};
	typedef struct Sheet_monsterdisplay_s Sheet_monsterdisplay_t;

	struct monstervalue_s : public NFDescStoreSeqOP {
		monstervalue_s();
		int CreateInit();
		int ResumeInit();
		int64_t ID;
		int32_t type;
		int32_t monsterLV;
		int64_t maxHp;
		int64_t attack;
		int64_t defense;
		int64_t pierce;
		int64_t divineAtt;
		int64_t divineDef;
		int64_t hitRate;
		int64_t dodgeRate;
		int64_t critRate;
		int64_t toughRate;
		int64_t killRate;
		int64_t parryRate;
		int64_t critDam;
		int64_t critRedu;
		int64_t killDam;
		int64_t killRedu;
		int64_t attDam;
		int64_t attRedu;
		int64_t fightingCapacity;
		int32_t isFightPress;
		int64_t exp;

		virtual void write_to_pbmsg(::proto_ff::monstervalue & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::monstervalue & msg);
		static ::proto_ff::monstervalue* new_pbmsg(){ return new ::proto_ff::monstervalue(); }
		static ::proto_ff::monstervalue make_pbmsg(){ return ::proto_ff::monstervalue(); }
	};
	typedef struct monstervalue_s monstervalue_t;

	struct Sheet_monstervalue_s : public NFDescStoreSeqOP {
		Sheet_monstervalue_s();
		int CreateInit();
		int ResumeInit();
		NFArray<struct monstervalue_s, 42194> monstervalue_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_monstervalue & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_monstervalue & msg);
		static ::proto_ff::Sheet_monstervalue* new_pbmsg(){ return new ::proto_ff::Sheet_monstervalue(); }
		static ::proto_ff::Sheet_monstervalue make_pbmsg(){ return ::proto_ff::Sheet_monstervalue(); }
	};
	typedef struct Sheet_monstervalue_s Sheet_monstervalue_t;

}

