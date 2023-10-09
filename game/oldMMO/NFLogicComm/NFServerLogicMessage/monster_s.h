#pragma once

#include <stdint.h>
#include <NFComm/NFShmStl/NFShmString.h>
#include <NFComm/NFShmStl/NFShmVector.h>
#include <NFComm/NFShmCore/NFSeqOP.h>
#include <NFComm/NFShmCore/NFShmMgr.h>
#include "monster.pb.h"
#include "monster_s.h"

#define DEFINE_SHEET_MONSTERMONSTER_E_MONSTERMONSTER_LIST_MAX_NUM 400
#define DEFINE_E_MONSTERDISPLAY_M_SKILL_MAX_NUM 7
#define DEFINE_SHEET_MONSTERDISPLAY_E_MONSTERDISPLAY_LIST_MAX_NUM 100
#define DEFINE_SHEET_MONSTERVALUE_E_MONSTERVALUE_LIST_MAX_NUM 2000
#define DEFINE_SHEET_MONSTERVALUEPARAM_E_MONSTERVALUEPARAM_LIST_MAX_NUM 20
#define DEFINE_E_MONSTERDROP_M_BOXID_MAX_NUM 5
#define DEFINE_SHEET_MONSTERDROP_E_MONSTERDROP_LIST_MAX_NUM 20
namespace proto_ff_s {

	struct E_MonsterMonster_s : public NFDescStoreSeqOP {
		E_MonsterMonster_s();
		virtual ~E_MonsterMonster_s(){}
		int CreateInit();
		int ResumeInit();
		int64_t m_monsterid;
		NFShmString<60> m_monstername;
		int32_t m_functiontype;
		int64_t m_functionvalue;
		int32_t m_profession;
		int32_t m_damageaddtype;
		int32_t m_monsterlv;
		int32_t m_droplimit;
		int64_t m_displayid;
		int64_t m_valuetype;
		int32_t m_valueparam;
		int64_t m_aiid;
		int32_t m_hpsectionnum;
		int32_t m_breedprob;
		int64_t m_breedmonid;
		int32_t m_breedmonlive;
		NFShmString<60> m_itemcost;
		int32_t m_isbornactionon;
		int32_t m_belongshow;
		int32_t m_dropgroupid;
		int32_t m_harmdrop_type;
		int32_t m_joninper;
		int32_t m_btnrange;
		int64_t m_btnid;
		int32_t m_drivepoint;
		int32_t m_corpseid;

		virtual void write_to_pbmsg(::proto_ff::E_MonsterMonster & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_MonsterMonster & msg);
		static ::proto_ff::E_MonsterMonster* new_pbmsg(){ return new ::proto_ff::E_MonsterMonster(); }
		static ::proto_ff::E_MonsterMonster make_pbmsg(){ return ::proto_ff::E_MonsterMonster(); }
	};
	typedef struct E_MonsterMonster_s E_MonsterMonster_t;

	struct Sheet_MonsterMonster_s : public NFDescStoreSeqOP {
		Sheet_MonsterMonster_s();
		virtual ~Sheet_MonsterMonster_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_MonsterMonster_s, DEFINE_SHEET_MONSTERMONSTER_E_MONSTERMONSTER_LIST_MAX_NUM> E_MonsterMonster_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_MonsterMonster & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_MonsterMonster & msg);
		static ::proto_ff::Sheet_MonsterMonster* new_pbmsg(){ return new ::proto_ff::Sheet_MonsterMonster(); }
		static ::proto_ff::Sheet_MonsterMonster make_pbmsg(){ return ::proto_ff::Sheet_MonsterMonster(); }
	};
	typedef struct Sheet_MonsterMonster_s Sheet_MonsterMonster_t;

	struct E_MonsterDisplaySkillDesc_s : public NFDescStoreSeqOP {
		E_MonsterDisplaySkillDesc_s();
		virtual ~E_MonsterDisplaySkillDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int64_t m_id;

		virtual void write_to_pbmsg(::proto_ff::E_MonsterDisplaySkillDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_MonsterDisplaySkillDesc & msg);
		static ::proto_ff::E_MonsterDisplaySkillDesc* new_pbmsg(){ return new ::proto_ff::E_MonsterDisplaySkillDesc(); }
		static ::proto_ff::E_MonsterDisplaySkillDesc make_pbmsg(){ return ::proto_ff::E_MonsterDisplaySkillDesc(); }
	};
	typedef struct E_MonsterDisplaySkillDesc_s E_MonsterDisplaySkillDesc_t;

	struct E_MonsterDisplay_s : public NFDescStoreSeqOP {
		E_MonsterDisplay_s();
		virtual ~E_MonsterDisplay_s(){}
		int CreateInit();
		int ResumeInit();
		int64_t m_displayid;
		int32_t m_modeloffsetsx;
		int32_t m_modeloffsetsy;
		int32_t m_modelscale;
		int32_t m_modelradius;
		int32_t m_pathradius;
		int32_t m_collisionradius;
		int32_t m_rspeed;
		NFShmVector<struct E_MonsterDisplaySkillDesc_s, DEFINE_E_MONSTERDISPLAY_M_SKILL_MAX_NUM> m_skill;

		virtual void write_to_pbmsg(::proto_ff::E_MonsterDisplay & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_MonsterDisplay & msg);
		static ::proto_ff::E_MonsterDisplay* new_pbmsg(){ return new ::proto_ff::E_MonsterDisplay(); }
		static ::proto_ff::E_MonsterDisplay make_pbmsg(){ return ::proto_ff::E_MonsterDisplay(); }
	};
	typedef struct E_MonsterDisplay_s E_MonsterDisplay_t;

	struct Sheet_MonsterDisplay_s : public NFDescStoreSeqOP {
		Sheet_MonsterDisplay_s();
		virtual ~Sheet_MonsterDisplay_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_MonsterDisplay_s, DEFINE_SHEET_MONSTERDISPLAY_E_MONSTERDISPLAY_LIST_MAX_NUM> E_MonsterDisplay_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_MonsterDisplay & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_MonsterDisplay & msg);
		static ::proto_ff::Sheet_MonsterDisplay* new_pbmsg(){ return new ::proto_ff::Sheet_MonsterDisplay(); }
		static ::proto_ff::Sheet_MonsterDisplay make_pbmsg(){ return ::proto_ff::Sheet_MonsterDisplay(); }
	};
	typedef struct Sheet_MonsterDisplay_s Sheet_MonsterDisplay_t;

	struct E_MonsterValue_s : public NFDescStoreSeqOP {
		E_MonsterValue_s();
		virtual ~E_MonsterValue_s(){}
		int CreateInit();
		int ResumeInit();
		int64_t m_id;
		int32_t m_type;
		int32_t m_monsterlv;
		int64_t m_max_hp;
		int64_t m_atk;
		int64_t m_def;
		int64_t m_brk_armor;
		int64_t m_five_dam;
		int64_t m_five_armor;
		int64_t m_thump_rate;
		int64_t m_thump_resist;
		int64_t m_sky;
		int64_t m_sky_dam;
		int64_t m_sky_redu_resist;
		int64_t m_sky_resist;
		int64_t m_kill_god;
		int64_t m_god_body;
		int64_t m_mortal_rate;
		int64_t m_mortal_resist;
		int64_t m_fairy_rate;
		int64_t m_fairy_resist;
		int64_t m_god_rate;
		int64_t m_god_resist;
		int64_t m_crit_rate;
		int64_t m_crit_resit_rate;
		int64_t m_crit_dam;
		int64_t m_crit_redu;
		int64_t m_batter_rate;
		int64_t m_batter_resist;
		int64_t m_batter_dam;
		int64_t m_batter_redu;
		int64_t m_brkdown_rate;
		int64_t m_brkdown_resist;
		int64_t m_dam_add;
		int64_t m_dam_redu;
		int64_t m_all_add;
		int64_t m_all_redu;
		int64_t m_skill_add;
		int64_t m_skill_redu;
		int64_t m_rebound_dam;
		int64_t m_hp_steal;
		int64_t m_dodge_rate;
		int64_t m_hit_rate;
		int64_t m_blk_rate;
		int64_t m_brk_blk_rate;
		int64_t m_blk_free;
		int64_t m_blk_pierce;
		int64_t m_rel_armor;
		int64_t m_rel_dam;
		int64_t m_five_resist;
		int64_t m_five_resist_redu;
		int64_t m_fire_add;
		int64_t m_fire_redu;
		int64_t m_ice_add;
		int64_t m_ice_redu;
		int64_t m_thunder_add;
		int64_t m_thunder_rdu;
		int64_t m_player_add;
		int64_t m_player_redu;
		int64_t m_leader_add;
		int64_t m_leader_redu;
		int64_t m_mon_add;
		int64_t m_mon_redu;
		int64_t m_var_redu;
		int64_t m_var_add;
		int64_t m_unusual_resist;
		int64_t m_unusual_hit;
		int64_t m_hp_recover;
		int64_t m_unusual_add;
		int64_t m_fix_recover;
		int64_t m_high_hp_add;
		int64_t m_recover_hp_add;
		int64_t m_week_add;
		int64_t m_shield;
		int64_t m_exp;

		virtual void write_to_pbmsg(::proto_ff::E_MonsterValue & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_MonsterValue & msg);
		static ::proto_ff::E_MonsterValue* new_pbmsg(){ return new ::proto_ff::E_MonsterValue(); }
		static ::proto_ff::E_MonsterValue make_pbmsg(){ return ::proto_ff::E_MonsterValue(); }
	};
	typedef struct E_MonsterValue_s E_MonsterValue_t;

	struct Sheet_MonsterValue_s : public NFDescStoreSeqOP {
		Sheet_MonsterValue_s();
		virtual ~Sheet_MonsterValue_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_MonsterValue_s, DEFINE_SHEET_MONSTERVALUE_E_MONSTERVALUE_LIST_MAX_NUM> E_MonsterValue_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_MonsterValue & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_MonsterValue & msg);
		static ::proto_ff::Sheet_MonsterValue* new_pbmsg(){ return new ::proto_ff::Sheet_MonsterValue(); }
		static ::proto_ff::Sheet_MonsterValue make_pbmsg(){ return ::proto_ff::Sheet_MonsterValue(); }
	};
	typedef struct Sheet_MonsterValue_s Sheet_MonsterValue_t;

	struct E_MonsterValueparam_s : public NFDescStoreSeqOP {
		E_MonsterValueparam_s();
		virtual ~E_MonsterValueparam_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;
		int32_t m_p_max_hp;
		int32_t m_p_atk;
		int32_t m_p_def;
		int32_t m_p_brk_armor;
		int32_t m_p_five_dam;
		int32_t m_p_five_armor;
		int32_t m_p_thump_rate;
		int32_t m_p_thump_resist;
		int32_t m_p_sky;
		int32_t m_p_sky_dam;
		int32_t m_p_sky_redu_resist;
		int32_t m_p_sky_resist;
		int32_t m_p_kill_god;
		int32_t m_p_god_body;
		int32_t m_p_mortal_rate;
		int32_t m_p_mortal_resist;
		int32_t m_p_fairy_rate;
		int32_t m_p_fairy_resist;
		int32_t m_p_god_rate;
		int32_t m_p_god_resist;
		int32_t m_p_crit_rate;
		int32_t m_p_crit_resit_rate;
		int32_t m_p_crit_dam;
		int32_t m_p_crit_redu;
		int32_t m_p_batter_rate;
		int32_t m_p_batter_resist;
		int32_t m_p_batter_dam;
		int32_t m_p_batter_redu;
		int32_t m_p_brkdown_rate;
		int32_t m_p_brkdown_resist;
		int32_t m_p_dam_add;
		int32_t m_p_dam_redu;
		int32_t m_p_all_add;
		int32_t m_p_all_redu;
		int32_t m_p_skill_add;
		int32_t m_p_skill_redu;
		int32_t m_p_rebound_dam;
		int32_t m_p_hp_steal;
		int32_t m_p_dodge_rate;
		int32_t m_p_hit_rate;
		int32_t m_p_blk_rate;
		int32_t m_p_brk_blk_rate;
		int32_t m_p_blk_free;
		int32_t m_p_blk_pierce;
		int32_t m_p_rel_armor;
		int32_t m_p_rel_dam;
		int32_t m_p_five_resist;
		int32_t m_p_five_resist_redu;
		int32_t m_p_fire_add;
		int32_t m_p_fire_redu;
		int32_t m_p_ice_add;
		int32_t m_p_ice_redu;
		int32_t m_p_thunder_add;
		int32_t m_p_thunder_rdu;
		int32_t m_p_player_add;
		int32_t m_p_player_redu;
		int32_t m_p_leader_add;
		int32_t m_p_leader_redu;
		int32_t m_p_mon_add;
		int32_t m_p_mon_redu;
		int32_t m_p_var_redu;
		int32_t m_p_var_add;
		int32_t m_p_unusual_resist;
		int32_t m_p_unusual_hit;
		int32_t m_p_hp_recover;
		int32_t m_p_unusual_add;
		int32_t m_p_fix_recover;
		int32_t m_p_high_hp_add;
		int32_t m_p_recover_hp_add;
		int32_t m_p_week_add;
		int64_t m_shield;

		virtual void write_to_pbmsg(::proto_ff::E_MonsterValueparam & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_MonsterValueparam & msg);
		static ::proto_ff::E_MonsterValueparam* new_pbmsg(){ return new ::proto_ff::E_MonsterValueparam(); }
		static ::proto_ff::E_MonsterValueparam make_pbmsg(){ return ::proto_ff::E_MonsterValueparam(); }
	};
	typedef struct E_MonsterValueparam_s E_MonsterValueparam_t;

	struct Sheet_MonsterValueparam_s : public NFDescStoreSeqOP {
		Sheet_MonsterValueparam_s();
		virtual ~Sheet_MonsterValueparam_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_MonsterValueparam_s, DEFINE_SHEET_MONSTERVALUEPARAM_E_MONSTERVALUEPARAM_LIST_MAX_NUM> E_MonsterValueparam_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_MonsterValueparam & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_MonsterValueparam & msg);
		static ::proto_ff::Sheet_MonsterValueparam* new_pbmsg(){ return new ::proto_ff::Sheet_MonsterValueparam(); }
		static ::proto_ff::Sheet_MonsterValueparam make_pbmsg(){ return ::proto_ff::Sheet_MonsterValueparam(); }
	};
	typedef struct Sheet_MonsterValueparam_s Sheet_MonsterValueparam_t;

	struct E_MonsterDrop_s : public NFDescStoreSeqOP {
		E_MonsterDrop_s();
		virtual ~E_MonsterDrop_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;
		int32_t m_group;
		int32_t m_own;
		int32_t m_type;
		NFShmVector<int64_t, DEFINE_E_MONSTERDROP_M_BOXID_MAX_NUM> m_boxid;

		virtual void write_to_pbmsg(::proto_ff::E_MonsterDrop & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_MonsterDrop & msg);
		static ::proto_ff::E_MonsterDrop* new_pbmsg(){ return new ::proto_ff::E_MonsterDrop(); }
		static ::proto_ff::E_MonsterDrop make_pbmsg(){ return ::proto_ff::E_MonsterDrop(); }
	};
	typedef struct E_MonsterDrop_s E_MonsterDrop_t;

	struct Sheet_MonsterDrop_s : public NFDescStoreSeqOP {
		Sheet_MonsterDrop_s();
		virtual ~Sheet_MonsterDrop_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_MonsterDrop_s, DEFINE_SHEET_MONSTERDROP_E_MONSTERDROP_LIST_MAX_NUM> E_MonsterDrop_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_MonsterDrop & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_MonsterDrop & msg);
		static ::proto_ff::Sheet_MonsterDrop* new_pbmsg(){ return new ::proto_ff::Sheet_MonsterDrop(); }
		static ::proto_ff::Sheet_MonsterDrop make_pbmsg(){ return ::proto_ff::Sheet_MonsterDrop(); }
	};
	typedef struct Sheet_MonsterDrop_s Sheet_MonsterDrop_t;

}

