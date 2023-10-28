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
#define DEFINE_SHEET_MONSTERDISPLAY_E_MONSTERDISPLAY_LIST_MAX_NUM 256
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
		int64_t m_monsterid;//怪物ID
		NFShmString<64> m_monstername;//怪物名
		NFShmString<64> m_mask;//掉落标记
		int32_t m_functiontype;//功能类型
		int64_t m_functionvalue;//功能参数
		int32_t m_tasktype;//任务用怪类型
		int32_t m_profession;//怪物职业
		int32_t m_subprofession;//怪物子类型
		int32_t m_damageaddtype;//伤害加成类型
		int32_t m_monsterlv;//怪物等级
		int32_t m_droplimit;//最大掉落等级
		int64_t m_displayid;//资源与表现ID
		int32_t m_bossid;//首领ID
		int64_t m_valuetype;//数值类型
		int32_t m_valueparam;//数值参数
		int64_t m_aiid;//AI表ID
		int32_t m_hpsectionnum;//怪物血条段数
		int32_t m_breedprob;//死亡触发新怪物几率
		int64_t m_breedmonid;//触发生成怪物ID
		int32_t m_breedmonlive;//怪物存活时间
		NFShmString<64> m_itemcost;//道具消耗
		int32_t m_isbornactionon;//是否启用出生动作
		int32_t m_belongshow;//怪物掉落归属是否显示
		int32_t m_dropgroupid;//掉落ID
		int32_t m_harmdrop_type;//伤害计算方式
		int32_t m_joninper;//参与奖最低百分比
		int32_t m_btnrange;//按钮范围
		int64_t m_btnid;//按钮ID
		int32_t m_drivepoint;//怒气
		int32_t m_corpseid;//尸体ID
		int64_t m_battle;//战力
		int32_t m_lvsuppve;//等级压制
		int32_t m_powersuppve;//战力压制

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
		int64_t m_displayid;//资源与表现ID
		int32_t m_modeloffsetsx;//UI模型X坐标偏移
		int32_t m_modeloffsetsy;//UI模型Y坐标偏移
		int32_t m_modelscale;//UI模型缩放比例
		int32_t m_modelradius;//怪物模型半径
		int32_t m_pathradius;//寻路半径
		int32_t m_collisionradius;//寻路半径
		int32_t m_rspeed;//跑步速度
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
		int64_t m_id;//数值ID
		int32_t m_type;//怪物类型
		int32_t m_monsterlv;//怪物等级
		int64_t m_max_hp;//最大生命
		int64_t m_atk;//攻击
		int64_t m_def;//防御
		int64_t m_brk_armor;//破甲
		int64_t m_five_dam;//五行伤害
		int64_t m_five_armor;//五行护甲
		int64_t m_thump_rate;//重击几率
		int64_t m_thump_resist;//重击抵抗
		int64_t m_sky;//天道
		int64_t m_sky_dam;//天道伤害
		int64_t m_sky_redu_resist;//天道减抗
		int64_t m_sky_resist;//天道抗性
		int64_t m_kill_god;//弑神
		int64_t m_god_body;//神体
		int64_t m_mortal_rate;//凡免几率
		int64_t m_mortal_resist;//凡免抗性
		int64_t m_fairy_rate;//仙免几率
		int64_t m_fairy_resist;//仙免抗性
		int64_t m_god_rate;//神免几率
		int64_t m_god_resist;//神免抗性
		int64_t m_crit_rate;//暴击几率
		int64_t m_crit_resit_rate;//抗暴几率
		int64_t m_crit_dam;//暴击伤害
		int64_t m_crit_redu;//暴击减免
		int64_t m_batter_rate;//连击几率
		int64_t m_batter_resist;//连击抵抗
		int64_t m_batter_dam;//连击伤害
		int64_t m_batter_redu;//连击减免
		int64_t m_brkdown_rate;//击穿几率
		int64_t m_brkdown_resist;//击穿抵抗
		int64_t m_dam_add;//伤害加成
		int64_t m_dam_redu;//伤害减免
		int64_t m_all_add;//全能增伤
		int64_t m_all_redu;//全能减免
		int64_t m_skill_add;//技能增伤
		int64_t m_skill_redu;//技能减伤
		int64_t m_rebound_dam;//反弹伤害
		int64_t m_hp_steal;//生命窃取
		int64_t m_dodge_rate;//闪避几率
		int64_t m_hit_rate;//命中几率
		int64_t m_blk_rate;//格挡几率
		int64_t m_brk_blk_rate;//破档几率
		int64_t m_blk_free;//格挡免伤
		int64_t m_blk_pierce;//格挡穿透
		int64_t m_rel_armor;//真实护甲
		int64_t m_rel_dam;//真实伤害
		int64_t m_five_resist;//五行抗性
		int64_t m_five_resist_redu;//五行减抗
		int64_t m_fire_add;//离火增伤
		int64_t m_fire_redu;//离火减伤
		int64_t m_ice_add;//玄冰增伤
		int64_t m_ice_redu;//玄冰减伤
		int64_t m_thunder_add;//雷罚增伤
		int64_t m_thunder_rdu;//雷罚减伤
		int64_t m_player_add;//玩家减伤
		int64_t m_player_redu;//玩家增伤
		int64_t m_leader_add;//首领减伤
		int64_t m_leader_redu;//首领增伤
		int64_t m_mon_add;//怪物减伤
		int64_t m_mon_redu;//怪物增伤
		int64_t m_var_redu;//变身减伤
		int64_t m_var_add;//变身增伤
		int64_t m_unusual_resist;//异常抵抗
		int64_t m_unusual_hit;//异常命中
		int64_t m_hp_recover;//生命恢复
		int64_t m_unusual_add;//异常增伤
		int64_t m_fix_recover;//固定回复
		int64_t m_high_hp_add;//高血增伤
		int64_t m_recover_hp_add;//回血增效
		int64_t m_week_add;//虚弱增伤
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
		int32_t m_p_max_hp;//最大生命
		int32_t m_p_atk;//攻击
		int32_t m_p_def;//防御
		int32_t m_p_brk_armor;//破甲
		int32_t m_p_five_dam;//五行伤害
		int32_t m_p_five_armor;//五行护甲
		int32_t m_p_thump_rate;//重击几率
		int32_t m_p_thump_resist;//重击抵抗
		int32_t m_p_sky;//天道
		int32_t m_p_sky_dam;//天道伤害
		int32_t m_p_sky_redu_resist;//天道减抗
		int32_t m_p_sky_resist;//天道抗性
		int32_t m_p_kill_god;//弑神
		int32_t m_p_god_body;//神体
		int32_t m_p_mortal_rate;//凡免几率
		int32_t m_p_mortal_resist;//凡免抗性
		int32_t m_p_fairy_rate;//仙免几率
		int32_t m_p_fairy_resist;//仙免抗性
		int32_t m_p_god_rate;//神免几率
		int32_t m_p_god_resist;//神免抗性
		int32_t m_p_crit_rate;//暴击几率
		int32_t m_p_crit_resit_rate;//抗暴几率
		int32_t m_p_crit_dam;//暴击伤害
		int32_t m_p_crit_redu;//暴击减免
		int32_t m_p_batter_rate;//连击几率
		int32_t m_p_batter_resist;//连击抵抗
		int32_t m_p_batter_dam;//连击伤害
		int32_t m_p_batter_redu;//连击减免
		int32_t m_p_brkdown_rate;//击穿几率
		int32_t m_p_brkdown_resist;//击穿抵抗
		int32_t m_p_dam_add;//伤害加成
		int32_t m_p_dam_redu;//伤害减免
		int32_t m_p_all_add;//全能增伤
		int32_t m_p_all_redu;//全能减免
		int32_t m_p_skill_add;//技能增伤
		int32_t m_p_skill_redu;//技能减伤
		int32_t m_p_rebound_dam;//反弹伤害
		int32_t m_p_hp_steal;//生命窃取
		int32_t m_p_dodge_rate;//闪避几率
		int32_t m_p_hit_rate;//命中几率
		int32_t m_p_blk_rate;//格挡几率
		int32_t m_p_brk_blk_rate;//破档几率
		int32_t m_p_blk_free;//格挡免伤
		int32_t m_p_blk_pierce;//格挡穿透
		int32_t m_p_rel_armor;//真实护甲
		int32_t m_p_rel_dam;//真实伤害
		int32_t m_p_five_resist;//五行抗性
		int32_t m_p_five_resist_redu;//五行减抗
		int32_t m_p_fire_add;//离火增伤
		int32_t m_p_fire_redu;//离火减伤
		int32_t m_p_ice_add;//玄冰增伤
		int32_t m_p_ice_redu;//玄冰减伤
		int32_t m_p_thunder_add;//雷罚增伤
		int32_t m_p_thunder_rdu;//雷罚减伤
		int32_t m_p_player_add;//玩家减伤
		int32_t m_p_player_redu;//玩家增伤
		int32_t m_p_leader_add;//首领减伤
		int32_t m_p_leader_redu;//首领增伤
		int32_t m_p_mon_add;//怪物减伤
		int32_t m_p_mon_redu;//怪物增伤
		int32_t m_p_var_redu;//变身减伤
		int32_t m_p_var_add;//变身增伤
		int32_t m_p_unusual_resist;//异常抵抗
		int32_t m_p_unusual_hit;//异常命中
		int32_t m_p_hp_recover;//生命恢复
		int32_t m_p_unusual_add;//异常增伤
		int32_t m_p_fix_recover;//固定回复
		int32_t m_p_high_hp_add;//高血增伤
		int32_t m_p_recover_hp_add;//回血增效
		int32_t m_p_week_add;//虚弱增伤
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
		int32_t m_type;//掉落方式
		NFShmVector<int64_t, DEFINE_E_MONSTERDROP_M_BOXID_MAX_NUM> m_boxid;//box

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
		int32_t m_id;//类型
		int32_t m_type;//采集物类型
		int32_t m_num;//公共采集次数
		int32_t m_breakdown;//是否能被打断
		int32_t m_dropgroupid;//采集获得
		int32_t m_time;//读条时间
		int32_t m_gettype;//获得技能的方式
		int32_t m_skilltime;//技能间隔
		int32_t m_skillid;//采集获得技能
		int32_t m_dupid;//副本ID
		int32_t m_monsteid;//怪物ID

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

