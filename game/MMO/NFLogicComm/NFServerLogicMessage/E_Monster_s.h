#pragma once

#include <stdint.h>
#include <NFComm/NFShmStl/NFShmString.h>
#include <NFComm/NFShmStl/NFShmVector.h>
#include <NFComm/NFShmCore/NFSeqOP.h>
#include <NFComm/NFShmCore/NFShmMgr.h>
#include "E_Monster.pb.h"
#include "E_Monster_s.h"

#define DEFINE_SHEET_MONSTERMONSTER_E_MONSTERMONSTER_LIST_MAX_NUM 2048
#define DEFINE_E_MONSTERDISPLAY_M_SKILL_MAX_NUM 7
#define DEFINE_SHEET_MONSTERDISPLAY_E_MONSTERDISPLAY_LIST_MAX_NUM 512
#define DEFINE_SHEET_MONSTERVALUE_E_MONSTERVALUE_LIST_MAX_NUM 8192
#define DEFINE_SHEET_MONSTERVALUEPARAM_E_MONSTERVALUEPARAM_LIST_MAX_NUM 128
#define DEFINE_E_MONSTERDROP_M_BOXID_MAX_NUM 5
#define DEFINE_SHEET_MONSTERDROP_E_MONSTERDROP_LIST_MAX_NUM 512
#define DEFINE_SHEET_MONSTERCOLLECT_E_MONSTERCOLLECT_LIST_MAX_NUM 32


namespace proto_ff_s {

	struct E_MonsterMonster_s : public NFDescStoreSeqOP {
		E_MonsterMonster_s();
		virtual ~E_MonsterMonster_s(){}
		int CreateInit();
		int ResumeInit();
		int64_t m_monsterID;//怪物ID
		NFShmString<64> m_monsterName;//怪物名
		NFShmString<64> m_mask;//掉落标记
		int32_t m_functionType;//功能类型
		int64_t m_functionValue;//功能参数
		int32_t m_taskType;//任务用怪类型
		int32_t m_profession;//怪物职业
		int32_t m_subProfession;//怪物子类型
		int32_t m_damageAddType;//伤害加成类型
		int32_t m_monsterLV;//怪物等级
		int32_t m_droplimit;//最大掉落等级
		int64_t m_displayID;//资源与表现ID
		int32_t m_bossID;//首领ID
		int64_t m_valuetype;//数值类型
		int32_t m_valueParam;//数值参数
		int64_t m_aiId;//AI表ID
		int32_t m_hpSectionNum;//怪物血条段数
		int32_t m_breedProb;//死亡触发新怪物几率
		int64_t m_breedMonID;//触发生成怪物ID
		int32_t m_breedMonLive;//怪物存活时间
		NFShmString<64> m_itemCost;//道具消耗
		int32_t m_isBornActionOn;//是否启用出生动作
		int32_t m_belongshow;//怪物掉落归属是否显示
		int32_t m_dropGroupID;//掉落ID
		int32_t m_harmdrop_type;//伤害计算方式
		int32_t m_joninper;//参与奖最低百分比
		int32_t m_btnRange;//按钮范围
		int64_t m_btnId;//按钮ID
		int32_t m_drivePoint;//怒气
		int32_t m_corpseID;//尸体ID
		int64_t m_battle;//战力
		int32_t m_lvSupPve;//等级压制
		int32_t m_powerSupPve;//战力压制

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
		NFShmVector<struct E_MonsterMonster_s, DEFINE_SHEET_MONSTERMONSTER_E_MONSTERMONSTER_LIST_MAX_NUM> E_MonsterMonster_List;//

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
		int64_t m_id;//id

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
		int64_t m_displayID;//资源与表现ID
		int32_t m_modelOffsetsX;//UI模型X坐标偏移
		int32_t m_modelOffsetsY;//UI模型Y坐标偏移
		int32_t m_modelScale;//UI模型缩放比例
		int32_t m_modelRadius;//怪物模型半径
		int32_t m_pathRadius;//寻路半径
		int32_t m_collisionRadius;//寻路半径
		int32_t m_rSpeed;//跑步速度
		NFShmVector<struct E_MonsterDisplaySkillDesc_s, DEFINE_E_MONSTERDISPLAY_M_SKILL_MAX_NUM> m_skill;//技能

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
		NFShmVector<struct E_MonsterDisplay_s, DEFINE_SHEET_MONSTERDISPLAY_E_MONSTERDISPLAY_LIST_MAX_NUM> E_MonsterDisplay_List;//

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
		int64_t m_ID;//数值ID
		int32_t m_type;//怪物类型
		int32_t m_monsterLV;//怪物等级
		int64_t m_max_Hp;//最大生命
		int64_t m_atk;//攻击
		int64_t m_def;//防御
		int64_t m_brk_Armor;//破甲
		int64_t m_five_Dam;//五行伤害
		int64_t m_five_Armor;//五行护甲
		int64_t m_thump_Rate;//重击几率
		int64_t m_thump_Resist;//重击抵抗
		int64_t m_sky;//天道
		int64_t m_sky_Dam;//天道伤害
		int64_t m_sky_Redu_Resist;//天道减抗
		int64_t m_sky_Resist;//天道抗性
		int64_t m_kill_God;//弑神
		int64_t m_god_Body;//神体
		int64_t m_mortal_Rate;//凡免几率
		int64_t m_mortal_Resist;//凡免抗性
		int64_t m_fairy_Rate;//仙免几率
		int64_t m_fairy_Resist;//仙免抗性
		int64_t m_god_Rate;//神免几率
		int64_t m_god_Resist;//神免抗性
		int64_t m_crit_Rate;//暴击几率
		int64_t m_crit_resit_Rate;//抗暴几率
		int64_t m_crit_Dam;//暴击伤害
		int64_t m_crit_Redu;//暴击减免
		int64_t m_batter_Rate;//连击几率
		int64_t m_batter_Resist;//连击抵抗
		int64_t m_batter_Dam;//连击伤害
		int64_t m_batter_Redu;//连击减免
		int64_t m_brkdown_Rate;//击穿几率
		int64_t m_brkdown_Resist;//击穿抵抗
		int64_t m_dam_Add;//伤害加成
		int64_t m_dam_Redu;//伤害减免
		int64_t m_all_Add;//全能增伤
		int64_t m_all_Redu;//全能减免
		int64_t m_skill_Add;//技能增伤
		int64_t m_skill_Redu;//技能减伤
		int64_t m_rebound_Dam;//反弹伤害
		int64_t m_hp_Steal;//生命窃取
		int64_t m_dodge_Rate;//闪避几率
		int64_t m_hit_Rate;//命中几率
		int64_t m_blk_Rate;//格挡几率
		int64_t m_brk_blk_Rate;//破档几率
		int64_t m_blk_Free;//格挡免伤
		int64_t m_blk_Pierce;//格挡穿透
		int64_t m_rel_Armor;//真实护甲
		int64_t m_rel_Dam;//真实伤害
		int64_t m_five_Resist;//五行抗性
		int64_t m_five_resist_Redu;//五行减抗
		int64_t m_fire_Add;//离火增伤
		int64_t m_fire_Redu;//离火减伤
		int64_t m_ice_Add;//玄冰增伤
		int64_t m_ice_Redu;//玄冰减伤
		int64_t m_thunder_Add;//雷罚增伤
		int64_t m_thunder_Rdu;//雷罚减伤
		int64_t m_player_Add;//玩家减伤
		int64_t m_player_Redu;//玩家增伤
		int64_t m_leader_Add;//首领减伤
		int64_t m_leader_Redu;//首领增伤
		int64_t m_mon_Add;//怪物减伤
		int64_t m_mon_Redu;//怪物增伤
		int64_t m_var_Redu;//变身减伤
		int64_t m_var_Add;//变身增伤
		int64_t m_unusual_Resist;//异常抵抗
		int64_t m_unusual_Hit;//异常命中
		int64_t m_hp_Recover;//生命恢复
		int64_t m_unusual_Add;//异常增伤
		int64_t m_fix_Recover;//固定回复
		int64_t m_high_hp_Add;//高血增伤
		int64_t m_recover_hp_Add;//回血增效
		int64_t m_week_Add;//虚弱增伤
		int64_t m_shield;//护盾
		int64_t m_exp;//怪物经验

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
		NFShmVector<struct E_MonsterValue_s, DEFINE_SHEET_MONSTERVALUE_E_MONSTERVALUE_LIST_MAX_NUM> E_MonsterValue_List;//

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
		int32_t m_id;//id
		int32_t m_P_max_Hp;//最大生命
		int32_t m_P_atk;//攻击
		int32_t m_P_def;//防御
		int32_t m_P_brk_Armor;//破甲
		int32_t m_P_five_Dam;//五行伤害
		int32_t m_P_five_Armor;//五行护甲
		int32_t m_P_thump_Rate;//重击几率
		int32_t m_P_thump_Resist;//重击抵抗
		int32_t m_P_sky;//天道
		int32_t m_P_sky_Dam;//天道伤害
		int32_t m_P_sky_Redu_Resist;//天道减抗
		int32_t m_P_sky_Resist;//天道抗性
		int32_t m_P_kill_God;//弑神
		int32_t m_P_god_Body;//神体
		int32_t m_P_mortal_Rate;//凡免几率
		int32_t m_P_mortal_Resist;//凡免抗性
		int32_t m_P_fairy_Rate;//仙免几率
		int32_t m_P_fairy_Resist;//仙免抗性
		int32_t m_P_god_Rate;//神免几率
		int32_t m_P_god_Resist;//神免抗性
		int32_t m_P_crit_Rate;//暴击几率
		int32_t m_P_crit_resit_Rate;//抗暴几率
		int32_t m_P_crit_Dam;//暴击伤害
		int32_t m_P_crit_Redu;//暴击减免
		int32_t m_P_batter_Rate;//连击几率
		int32_t m_P_batter_Resist;//连击抵抗
		int32_t m_P_batter_Dam;//连击伤害
		int32_t m_P_batter_Redu;//连击减免
		int32_t m_P_brkdown_Rate;//击穿几率
		int32_t m_P_brkdown_Resist;//击穿抵抗
		int32_t m_P_dam_Add;//伤害加成
		int32_t m_P_dam_Redu;//伤害减免
		int32_t m_P_all_Add;//全能增伤
		int32_t m_P_all_Redu;//全能减免
		int32_t m_P_skill_Add;//技能增伤
		int32_t m_P_skill_Redu;//技能减伤
		int32_t m_P_rebound_Dam;//反弹伤害
		int32_t m_P_hp_Steal;//生命窃取
		int32_t m_P_dodge_Rate;//闪避几率
		int32_t m_P_hit_Rate;//命中几率
		int32_t m_P_blk_Rate;//格挡几率
		int32_t m_P_brk_blk_Rate;//破档几率
		int32_t m_P_blk_Free;//格挡免伤
		int32_t m_P_blk_Pierce;//格挡穿透
		int32_t m_P_rel_Armor;//真实护甲
		int32_t m_P_rel_Dam;//真实伤害
		int32_t m_P_five_Resist;//五行抗性
		int32_t m_P_five_resist_Redu;//五行减抗
		int32_t m_P_fire_Add;//离火增伤
		int32_t m_P_fire_Redu;//离火减伤
		int32_t m_P_ice_Add;//玄冰增伤
		int32_t m_P_ice_Redu;//玄冰减伤
		int32_t m_P_thunder_Add;//雷罚增伤
		int32_t m_P_thunder_Rdu;//雷罚减伤
		int32_t m_P_player_Add;//玩家减伤
		int32_t m_P_player_Redu;//玩家增伤
		int32_t m_P_leader_Add;//首领减伤
		int32_t m_P_leader_Redu;//首领增伤
		int32_t m_P_mon_Add;//怪物减伤
		int32_t m_P_mon_Redu;//怪物增伤
		int32_t m_P_var_Redu;//变身减伤
		int32_t m_P_var_Add;//变身增伤
		int32_t m_P_unusual_Resist;//异常抵抗
		int32_t m_P_unusual_Hit;//异常命中
		int32_t m_P_hp_Recover;//生命恢复
		int32_t m_P_unusual_Add;//异常增伤
		int32_t m_P_fix_Recover;//固定回复
		int32_t m_P_high_hp_Add;//高血增伤
		int32_t m_P_recover_hp_Add;//回血增效
		int32_t m_P_week_Add;//虚弱增伤
		int64_t m_shield;//护盾
		int64_t m_exp;//怪物经验

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
		NFShmVector<struct E_MonsterValueparam_s, DEFINE_SHEET_MONSTERVALUEPARAM_E_MONSTERVALUEPARAM_LIST_MAX_NUM> E_MonsterValueparam_List;//

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
		int32_t m_id;//掉落包ID
		int32_t m_group;//掉落组
		int32_t m_own;//归属权
		int32_t m_ownProtect;//归属保护
		int32_t m_type;//掉落方式
		NFShmVector<int64_t, DEFINE_E_MONSTERDROP_M_BOXID_MAX_NUM> m_boxID;//box

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
		NFShmVector<struct E_MonsterDrop_s, DEFINE_SHEET_MONSTERDROP_E_MONSTERDROP_LIST_MAX_NUM> E_MonsterDrop_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_MonsterDrop & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_MonsterDrop & msg);
		static ::proto_ff::Sheet_MonsterDrop* new_pbmsg(){ return new ::proto_ff::Sheet_MonsterDrop(); }
		static ::proto_ff::Sheet_MonsterDrop make_pbmsg(){ return ::proto_ff::Sheet_MonsterDrop(); }
	};
	typedef struct Sheet_MonsterDrop_s Sheet_MonsterDrop_t;

	struct E_MonsterCollect_s : public NFDescStoreSeqOP {
		E_MonsterCollect_s();
		virtual ~E_MonsterCollect_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_ID;//类型
		int32_t m_type;//采集物类型
		int32_t m_num;//公共采集次数
		int32_t m_breakDown;//是否能被打断
		int32_t m_dropGroupID;//采集获得
		int32_t m_time;//读条时间
		int32_t m_getType;//获得技能的方式
		int32_t m_skillTime;//技能间隔
		int32_t m_skillID;//采集获得技能
		int32_t m_dupID;//副本ID
		int32_t m_monsteID;//怪物ID

		virtual void write_to_pbmsg(::proto_ff::E_MonsterCollect & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_MonsterCollect & msg);
		static ::proto_ff::E_MonsterCollect* new_pbmsg(){ return new ::proto_ff::E_MonsterCollect(); }
		static ::proto_ff::E_MonsterCollect make_pbmsg(){ return ::proto_ff::E_MonsterCollect(); }
	};
	typedef struct E_MonsterCollect_s E_MonsterCollect_t;

	struct Sheet_MonsterCollect_s : public NFDescStoreSeqOP {
		Sheet_MonsterCollect_s();
		virtual ~Sheet_MonsterCollect_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_MonsterCollect_s, DEFINE_SHEET_MONSTERCOLLECT_E_MONSTERCOLLECT_LIST_MAX_NUM> E_MonsterCollect_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_MonsterCollect & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_MonsterCollect & msg);
		static ::proto_ff::Sheet_MonsterCollect* new_pbmsg(){ return new ::proto_ff::Sheet_MonsterCollect(); }
		static ::proto_ff::Sheet_MonsterCollect make_pbmsg(){ return ::proto_ff::Sheet_MonsterCollect(); }
	};
	typedef struct Sheet_MonsterCollect_s Sheet_MonsterCollect_t;

}

