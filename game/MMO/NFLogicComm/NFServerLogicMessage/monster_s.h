#pragma once

#include <stdint.h>
#include <NFComm/NFShmCore/NFShmString.h>
#include <NFComm/NFShmCore/NFArray.h>
#include <NFComm/NFShmCore/NFSeqOP.h>
#include <NFComm/NFShmCore/NFShmMgr.h>
#include "monster.pb.h"
#include "monster_s.h"

namespace proto_ff_s {

	struct monstermonster_s : public NFDescStoreSeqOP {
		monstermonster_s();
		virtual ~monstermonster_s(){}
		int CreateInit();
		int ResumeInit();
		int64_t monsterID;
		NFShmString<60> monsterName;
		int32_t functionType;
		int64_t functionValue;
		int32_t profession;
		int32_t damageAddType;
		int32_t monsterLV;
		int32_t droplimit;
		int64_t displayID;
		int64_t valuetype;
		int32_t valueParam;
		int64_t aiId;
		int32_t hpSectionNum;
		int32_t breedProb;
		int64_t breedMonID;
		int32_t breedMonLive;
		NFShmString<60> itemCost;
		int32_t isBornActionOn;
		int32_t belongshow;
		int32_t dropGroupID;
		int32_t harmdrop_type;
		int32_t joninper;
		int32_t btnRange;
		int64_t btnId;
		int32_t drivePoint;
		int32_t corpseID;

		virtual void write_to_pbmsg(::proto_ff::monstermonster & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::monstermonster & msg);
		static ::proto_ff::monstermonster* new_pbmsg(){ return new ::proto_ff::monstermonster(); }
		static ::proto_ff::monstermonster make_pbmsg(){ return ::proto_ff::monstermonster(); }
	};
	typedef struct monstermonster_s monstermonster_t;

	struct Sheet_monstermonster_s : public NFDescStoreSeqOP {
		Sheet_monstermonster_s();
		virtual ~Sheet_monstermonster_s(){}
		int CreateInit();
		int ResumeInit();
		NFArray<struct monstermonster_s, 200> monstermonster_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_monstermonster & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_monstermonster & msg);
		static ::proto_ff::Sheet_monstermonster* new_pbmsg(){ return new ::proto_ff::Sheet_monstermonster(); }
		static ::proto_ff::Sheet_monstermonster make_pbmsg(){ return ::proto_ff::Sheet_monstermonster(); }
	};
	typedef struct Sheet_monstermonster_s Sheet_monstermonster_t;

	struct monsterdisplayskillDesc_s : public NFDescStoreSeqOP {
		monsterdisplayskillDesc_s();
		virtual ~monsterdisplayskillDesc_s(){}
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
		virtual ~monsterdisplay_s(){}
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
		virtual ~Sheet_monsterdisplay_s(){}
		int CreateInit();
		int ResumeInit();
		NFArray<struct monsterdisplay_s, 80> monsterdisplay_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_monsterdisplay & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_monsterdisplay & msg);
		static ::proto_ff::Sheet_monsterdisplay* new_pbmsg(){ return new ::proto_ff::Sheet_monsterdisplay(); }
		static ::proto_ff::Sheet_monsterdisplay make_pbmsg(){ return ::proto_ff::Sheet_monsterdisplay(); }
	};
	typedef struct Sheet_monsterdisplay_s Sheet_monsterdisplay_t;

	struct monstervalue_s : public NFDescStoreSeqOP {
		monstervalue_s();
		virtual ~monstervalue_s(){}
		int CreateInit();
		int ResumeInit();
		int64_t ID;
		int32_t type;
		int32_t monsterLV;
		int64_t max_Hp;
		int64_t atk;
		int64_t def;
		int64_t brk_Armor;
		int64_t five_Dam;
		int64_t five_Armor;
		int64_t thump_Rate;
		int64_t thump_Resist;
		int64_t sky;
		int64_t sky_Dam;
		int64_t sky_Redu_Resist;
		int64_t sky_Resist;
		int64_t kill_God;
		int64_t god_Body;
		int64_t mortal_Rate;
		int64_t mortal_Resist;
		int64_t fairy_Rate;
		int64_t fairy_Resist;
		int64_t god_Rate;
		int64_t god_Resist;
		int64_t crit_Rate;
		int64_t crit_resit_Rate;
		int64_t crit_Dam;
		int64_t crit_Redu;
		int64_t batter_Rate;
		int64_t batter_Resist;
		int64_t batter_Dam;
		int64_t batter_Redu;
		int64_t brkdown_Rate;
		int64_t brkdown_Resist;
		int64_t dam_Add;
		int64_t dam_Redu;
		int64_t all_Add;
		int64_t all_Redu;
		int64_t skill_Add;
		int64_t skill_Redu;
		int64_t rebound_Dam;
		int64_t hp_Steal;
		int64_t dodge_Rate;
		int64_t hit_Rate;
		int64_t blk_Rate;
		int64_t brk_blk_Rate;
		int64_t blk_Free;
		int64_t blk_Pierce;
		int64_t rel_Armor;
		int64_t rel_Dam;
		int64_t five_Resist;
		int64_t five_resist_Redu;
		int64_t fire_Add;
		int64_t fire_Redu;
		int64_t ice_Add;
		int64_t ice_Redu;
		int64_t thunder_Add;
		int64_t thunder_Rdu;
		int64_t player_Add;
		int64_t player_Redu;
		int64_t leader_Add;
		int64_t leader_Redu;
		int64_t mon_Add;
		int64_t mon_Redu;
		int64_t var_Redu;
		int64_t var_Add;
		int64_t unusual_Resist;
		int64_t unusual_Hit;
		int64_t hp_Recover;
		int64_t unusual_Add;
		int64_t fix_Recover;
		int64_t high_hp_Add;
		int64_t recover_hp_Add;
		int64_t week_Add;
		int64_t shield;

		virtual void write_to_pbmsg(::proto_ff::monstervalue & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::monstervalue & msg);
		static ::proto_ff::monstervalue* new_pbmsg(){ return new ::proto_ff::monstervalue(); }
		static ::proto_ff::monstervalue make_pbmsg(){ return ::proto_ff::monstervalue(); }
	};
	typedef struct monstervalue_s monstervalue_t;

	struct Sheet_monstervalue_s : public NFDescStoreSeqOP {
		Sheet_monstervalue_s();
		virtual ~Sheet_monstervalue_s(){}
		int CreateInit();
		int ResumeInit();
		NFArray<struct monstervalue_s, 200> monstervalue_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_monstervalue & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_monstervalue & msg);
		static ::proto_ff::Sheet_monstervalue* new_pbmsg(){ return new ::proto_ff::Sheet_monstervalue(); }
		static ::proto_ff::Sheet_monstervalue make_pbmsg(){ return ::proto_ff::Sheet_monstervalue(); }
	};
	typedef struct Sheet_monstervalue_s Sheet_monstervalue_t;

	struct monstervalueParam_s : public NFDescStoreSeqOP {
		monstervalueParam_s();
		virtual ~monstervalueParam_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t id;
		int32_t P_max_Hp;
		int32_t P_atk;
		int32_t P_def;
		int32_t P_brk_Armor;
		int32_t P_five_Dam;
		int32_t P_five_Armor;
		int32_t P_thump_Rate;
		int32_t P_thump_Resist;
		int32_t P_sky;
		int32_t P_sky_Dam;
		int32_t P_sky_Redu_Resist;
		int32_t P_sky_Resist;
		int32_t P_kill_God;
		int32_t P_god_Body;
		int32_t P_mortal_Rate;
		int32_t P_mortal_Resist;
		int32_t P_fairy_Rate;
		int32_t P_fairy_Resist;
		int32_t P_god_Rate;
		int32_t P_god_Resist;
		int32_t P_crit_Rate;
		int32_t P_crit_resit_Rate;
		int32_t P_crit_Dam;
		int32_t P_crit_Redu;
		int32_t P_batter_Rate;
		int32_t P_batter_Resist;
		int32_t P_batter_Dam;
		int32_t P_batter_Redu;
		int32_t P_brkdown_Rate;
		int32_t P_brkdown_Resist;
		int32_t P_dam_Add;
		int32_t P_dam_Redu;
		int32_t P_all_Add;
		int32_t P_all_Redu;
		int32_t P_skill_Add;
		int32_t P_skill_Redu;
		int32_t P_rebound_Dam;
		int32_t P_hp_Steal;
		int32_t P_dodge_Rate;
		int32_t P_hit_Rate;
		int32_t P_blk_Rate;
		int32_t P_brk_blk_Rate;
		int32_t P_blk_Free;
		int32_t P_blk_Pierce;
		int32_t P_rel_Armor;
		int32_t P_rel_Dam;
		int32_t P_five_Resist;
		int32_t P_five_resist_Redu;
		int32_t P_fire_Add;
		int32_t P_fire_Redu;
		int32_t P_ice_Add;
		int32_t P_ice_Redu;
		int32_t P_thunder_Add;
		int32_t P_thunder_Rdu;
		int32_t P_player_Add;
		int32_t P_player_Redu;
		int32_t P_leader_Add;
		int32_t P_leader_Redu;
		int32_t P_mon_Add;
		int32_t P_mon_Redu;
		int32_t P_var_Redu;
		int32_t P_var_Add;
		int32_t P_unusual_Resist;
		int32_t P_unusual_Hit;
		int32_t P_hp_Recover;
		int32_t P_unusual_Add;
		int32_t P_fix_Recover;
		int32_t P_high_hp_Add;
		int32_t P_recover_hp_Add;
		int32_t P_week_Add;
		int64_t shield;

		virtual void write_to_pbmsg(::proto_ff::monstervalueParam & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::monstervalueParam & msg);
		static ::proto_ff::monstervalueParam* new_pbmsg(){ return new ::proto_ff::monstervalueParam(); }
		static ::proto_ff::monstervalueParam make_pbmsg(){ return ::proto_ff::monstervalueParam(); }
	};
	typedef struct monstervalueParam_s monstervalueParam_t;

	struct Sheet_monstervalueParam_s : public NFDescStoreSeqOP {
		Sheet_monstervalueParam_s();
		virtual ~Sheet_monstervalueParam_s(){}
		int CreateInit();
		int ResumeInit();
		NFArray<struct monstervalueParam_s, 20> monstervalueParam_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_monstervalueParam & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_monstervalueParam & msg);
		static ::proto_ff::Sheet_monstervalueParam* new_pbmsg(){ return new ::proto_ff::Sheet_monstervalueParam(); }
		static ::proto_ff::Sheet_monstervalueParam make_pbmsg(){ return ::proto_ff::Sheet_monstervalueParam(); }
	};
	typedef struct Sheet_monstervalueParam_s Sheet_monstervalueParam_t;

	struct monsterdrop_s : public NFDescStoreSeqOP {
		monsterdrop_s();
		virtual ~monsterdrop_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t id;
		int32_t group;
		int32_t own;
		int32_t type;
		NFArray<int64_t, 5> boxID;

		virtual void write_to_pbmsg(::proto_ff::monsterdrop & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::monsterdrop & msg);
		static ::proto_ff::monsterdrop* new_pbmsg(){ return new ::proto_ff::monsterdrop(); }
		static ::proto_ff::monsterdrop make_pbmsg(){ return ::proto_ff::monsterdrop(); }
	};
	typedef struct monsterdrop_s monsterdrop_t;

	struct Sheet_monsterdrop_s : public NFDescStoreSeqOP {
		Sheet_monsterdrop_s();
		virtual ~Sheet_monsterdrop_s(){}
		int CreateInit();
		int ResumeInit();
		NFArray<struct monsterdrop_s, 20> monsterdrop_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_monsterdrop & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_monsterdrop & msg);
		static ::proto_ff::Sheet_monsterdrop* new_pbmsg(){ return new ::proto_ff::Sheet_monsterdrop(); }
		static ::proto_ff::Sheet_monsterdrop make_pbmsg(){ return ::proto_ff::Sheet_monsterdrop(); }
	};
	typedef struct Sheet_monsterdrop_s Sheet_monsterdrop_t;

}

