#pragma once

#include <stdint.h>
#include <NFComm/NFShmStl/NFShmString.h>
#include <NFComm/NFShmStl/NFShmVector.h>
#include <NFComm/NFShmCore/NFSeqOP.h>
#include <NFComm/NFShmCore/NFShmMgr.h>
#include "E_Skill.pb.h"
#include "E_Skill_s.h"

#define DEFINE_SHEET_SKILLBUFF_E_SKILLBUFF_LIST_MAX_NUM 2048
#define DEFINE_SHEET_SKILLBUFFUP_E_SKILLBUFFUP_LIST_MAX_NUM 512
#define DEFINE_E_SKILLSKILL_M_BUFF_MAX_NUM 8
#define DEFINE_E_SKILLSKILL_M_AWAKEBUFF_MAX_NUM 5
#define DEFINE_E_SKILLSKILL_M_ADVANCETYPE1BUFF_MAX_NUM 3
#define DEFINE_E_SKILLSKILL_M_ADVANCETYPE2BUFF_MAX_NUM 3
#define DEFINE_E_SKILLSKILL_M_ADVANCETYPE3BUFF_MAX_NUM 3
#define DEFINE_SHEET_SKILLSKILL_E_SKILLSKILL_LIST_MAX_NUM 4096
#define DEFINE_SHEET_SKILLSKILLADVANCE_E_SKILLSKILLADVANCE_LIST_MAX_NUM 128
#define DEFINE_SHEET_SKILLSKILLUP_E_SKILLSKILLUP_LIST_MAX_NUM 4096
#define DEFINE_SHEET_SKILLSKILLAWAKE_E_SKILLSKILLAWAKE_LIST_MAX_NUM 128
#define DEFINE_E_SKILLSKILLGROUP_M_SKILL_MAX_NUM 10
#define DEFINE_SHEET_SKILLSKILLGROUP_E_SKILLSKILLGROUP_LIST_MAX_NUM 2
#define DEFINE_E_SKILLATTGROUP_M_ATTRIBUTE_MAX_NUM 10
#define DEFINE_SHEET_SKILLATTGROUP_E_SKILLATTGROUP_LIST_MAX_NUM 2


namespace proto_ff_s {

	struct E_SkillBuff_s : public NFDescStoreSeqOP {
		E_SkillBuff_s();
		virtual ~E_SkillBuff_s(){}
		int CreateInit();
		int ResumeInit();
		int64_t m_buffID;//附加buffid
		NFShmString<64> m_buffName;//buff名称
		NFShmString<64> m_buffIcon;//buff图标
		NFShmString<64> m_effectResources;//特效路径
		int32_t m_showTpye;//显示类型
		int32_t m_startProbability;//生效概率
		int32_t m_Probability_up;//概率成长系数ID
		int32_t m_startType;//生效条件
		NFShmString<64> m_startTypeValue;//生效条件参数
		int32_t m_endType;//常规结束条件
		NFShmString<64> m_endTypeValue;//结束条件参数
		int32_t m_endTypeA;//额外结束条件A
		NFShmString<64> m_endTypeValueA;//额外结束条件参数A
		int32_t m_endTypeB;//额外结束条件B
		NFShmString<64> m_endTypeValueB;//额外结束条件参数B
		int32_t m_group;//buff组
		NFShmString<64> m_buffRule;//同一状态组叠加规则
		NFShmString<64> m_immune;//免疫的组id
		NFShmString<64> m_dispel;//驱散的组id
		int32_t m_buffCd;//buff冷却
		int32_t m_effect_Time;//buff时间
		int32_t m_effect_Type;//效果类型
		NFShmString<64> m_effect_Param;//效果参数
		int32_t m_effect_up;//成长系数ID

		virtual void write_to_pbmsg(::proto_ff::E_SkillBuff & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_SkillBuff & msg);
		static ::proto_ff::E_SkillBuff* new_pbmsg(){ return new ::proto_ff::E_SkillBuff(); }
		static ::proto_ff::E_SkillBuff make_pbmsg(){ return ::proto_ff::E_SkillBuff(); }
	};
	typedef struct E_SkillBuff_s E_SkillBuff_t;

	struct Sheet_SkillBuff_s : public NFDescStoreSeqOP {
		Sheet_SkillBuff_s();
		virtual ~Sheet_SkillBuff_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_SkillBuff_s, DEFINE_SHEET_SKILLBUFF_E_SKILLBUFF_LIST_MAX_NUM> E_SkillBuff_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_SkillBuff & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_SkillBuff & msg);
		static ::proto_ff::Sheet_SkillBuff* new_pbmsg(){ return new ::proto_ff::Sheet_SkillBuff(); }
		static ::proto_ff::Sheet_SkillBuff make_pbmsg(){ return ::proto_ff::Sheet_SkillBuff(); }
	};
	typedef struct Sheet_SkillBuff_s Sheet_SkillBuff_t;

	struct E_SkillBuffup_s : public NFDescStoreSeqOP {
		E_SkillBuffup_s();
		virtual ~E_SkillBuffup_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//id序号
		int32_t m_AddStartProbability;//概率成长值
		int32_t m_attributeId;//属性类型
		int32_t m_parama;//成长值

		virtual void write_to_pbmsg(::proto_ff::E_SkillBuffup & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_SkillBuffup & msg);
		static ::proto_ff::E_SkillBuffup* new_pbmsg(){ return new ::proto_ff::E_SkillBuffup(); }
		static ::proto_ff::E_SkillBuffup make_pbmsg(){ return ::proto_ff::E_SkillBuffup(); }
	};
	typedef struct E_SkillBuffup_s E_SkillBuffup_t;

	struct Sheet_SkillBuffup_s : public NFDescStoreSeqOP {
		Sheet_SkillBuffup_s();
		virtual ~Sheet_SkillBuffup_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_SkillBuffup_s, DEFINE_SHEET_SKILLBUFFUP_E_SKILLBUFFUP_LIST_MAX_NUM> E_SkillBuffup_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_SkillBuffup & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_SkillBuffup & msg);
		static ::proto_ff::Sheet_SkillBuffup* new_pbmsg(){ return new ::proto_ff::Sheet_SkillBuffup(); }
		static ::proto_ff::Sheet_SkillBuffup make_pbmsg(){ return ::proto_ff::Sheet_SkillBuffup(); }
	};
	typedef struct Sheet_SkillBuffup_s Sheet_SkillBuffup_t;

	struct E_SkillSkillBuffDesc_s : public NFDescStoreSeqOP {
		E_SkillSkillBuffDesc_s();
		virtual ~E_SkillSkillBuffDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_Target;//归属
		int32_t m_Point;//生效点
		int64_t m_ID;//id

		virtual void write_to_pbmsg(::proto_ff::E_SkillSkillBuffDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_SkillSkillBuffDesc & msg);
		static ::proto_ff::E_SkillSkillBuffDesc* new_pbmsg(){ return new ::proto_ff::E_SkillSkillBuffDesc(); }
		static ::proto_ff::E_SkillSkillBuffDesc make_pbmsg(){ return ::proto_ff::E_SkillSkillBuffDesc(); }
	};
	typedef struct E_SkillSkillBuffDesc_s E_SkillSkillBuffDesc_t;

	struct E_SkillSkillAwakebuffDesc_s : public NFDescStoreSeqOP {
		E_SkillSkillAwakebuffDesc_s();
		virtual ~E_SkillSkillAwakebuffDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int64_t m_ID;//id

		virtual void write_to_pbmsg(::proto_ff::E_SkillSkillAwakebuffDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_SkillSkillAwakebuffDesc & msg);
		static ::proto_ff::E_SkillSkillAwakebuffDesc* new_pbmsg(){ return new ::proto_ff::E_SkillSkillAwakebuffDesc(); }
		static ::proto_ff::E_SkillSkillAwakebuffDesc make_pbmsg(){ return ::proto_ff::E_SkillSkillAwakebuffDesc(); }
	};
	typedef struct E_SkillSkillAwakebuffDesc_s E_SkillSkillAwakebuffDesc_t;

	struct E_SkillSkillAdvancetype1buffDesc_s : public NFDescStoreSeqOP {
		E_SkillSkillAdvancetype1buffDesc_s();
		virtual ~E_SkillSkillAdvancetype1buffDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int64_t m_ID;//id

		virtual void write_to_pbmsg(::proto_ff::E_SkillSkillAdvancetype1buffDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_SkillSkillAdvancetype1buffDesc & msg);
		static ::proto_ff::E_SkillSkillAdvancetype1buffDesc* new_pbmsg(){ return new ::proto_ff::E_SkillSkillAdvancetype1buffDesc(); }
		static ::proto_ff::E_SkillSkillAdvancetype1buffDesc make_pbmsg(){ return ::proto_ff::E_SkillSkillAdvancetype1buffDesc(); }
	};
	typedef struct E_SkillSkillAdvancetype1buffDesc_s E_SkillSkillAdvancetype1buffDesc_t;

	struct E_SkillSkillAdvancetype2buffDesc_s : public NFDescStoreSeqOP {
		E_SkillSkillAdvancetype2buffDesc_s();
		virtual ~E_SkillSkillAdvancetype2buffDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int64_t m_ID;//id

		virtual void write_to_pbmsg(::proto_ff::E_SkillSkillAdvancetype2buffDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_SkillSkillAdvancetype2buffDesc & msg);
		static ::proto_ff::E_SkillSkillAdvancetype2buffDesc* new_pbmsg(){ return new ::proto_ff::E_SkillSkillAdvancetype2buffDesc(); }
		static ::proto_ff::E_SkillSkillAdvancetype2buffDesc make_pbmsg(){ return ::proto_ff::E_SkillSkillAdvancetype2buffDesc(); }
	};
	typedef struct E_SkillSkillAdvancetype2buffDesc_s E_SkillSkillAdvancetype2buffDesc_t;

	struct E_SkillSkillAdvancetype3buffDesc_s : public NFDescStoreSeqOP {
		E_SkillSkillAdvancetype3buffDesc_s();
		virtual ~E_SkillSkillAdvancetype3buffDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int64_t m_ID;//id

		virtual void write_to_pbmsg(::proto_ff::E_SkillSkillAdvancetype3buffDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_SkillSkillAdvancetype3buffDesc & msg);
		static ::proto_ff::E_SkillSkillAdvancetype3buffDesc* new_pbmsg(){ return new ::proto_ff::E_SkillSkillAdvancetype3buffDesc(); }
		static ::proto_ff::E_SkillSkillAdvancetype3buffDesc make_pbmsg(){ return ::proto_ff::E_SkillSkillAdvancetype3buffDesc(); }
	};
	typedef struct E_SkillSkillAdvancetype3buffDesc_s E_SkillSkillAdvancetype3buffDesc_t;

	struct E_SkillSkill_s : public NFDescStoreSeqOP {
		E_SkillSkill_s();
		virtual ~E_SkillSkill_s(){}
		int CreateInit();
		int ResumeInit();
		int64_t m_skillID;//技能id
		NFShmString<64> m_name;//名称
		int32_t m_skillType;//技能类型
		int32_t m_group;//技能组
		int32_t m_position;//技能位置
		int32_t m_displaceTime;//位移开始时间点
		int32_t m_displaceSign;//位移正负标记
		NFShmString<64> m_displaceSpeed;//位移速度
		NFShmString<64> m_disTimes;//位移时间
		int32_t m_targetDisplaceTime;//目标位移开始时间点
		int32_t m_targetDisplaceSign;//目标位移正负标记
		NFShmString<64> m_targetDisplaceSpeed;//目标位移速度
		NFShmString<64> m_targetDisTimes;//目标位移时间
		int32_t m_breakType;//打断类型
		int32_t m_cdSkill;//CD能否减少
		int64_t m_Relation;//普攻关联
		NFShmString<64> m_unlockCondition;//解锁条件
		int32_t m_type;//目标类型
		int32_t m_cd;//cd
		int32_t m_noLock;//是否锁定
		int32_t m_priority;//挂机使用优先级
		int32_t m_fighting;//初始战斗力
		float m_fightingParama;//战斗力成长系数
		int32_t m_releaseType;//释放类型
		int32_t m_processTypes;//过程类型
		NFShmString<64> m_releaseTime;//第几次释放
		int32_t m_flySpeed;//飞行速度
		int32_t m_actTime;//动作总时间
		int32_t m_readyTime;//攻击特效延迟时间
		int32_t m_readyTimeEx;//攻击特效延迟时间ex
		int32_t m_attackTime;//攻击总时间
		NFShmString<64> m_damageTime;//伤害生效时间点
		NFShmString<64> m_damageTimeEx;//伤害生效时间点ex
		int32_t m_attackDistance;//攻击距离
		int32_t m_rangeType;//范围类型
		NFShmString<64> m_rangeTypeValue;//范围类型值
		int32_t m_rangeTypeEx;//范围类型ex
		NFShmString<64> m_rangeTypeValueEx;//范围类型值ex
		int32_t m_warn;//预警id
		int32_t m_dazeTime;//发呆时间
		int32_t m_warnTime;//预警时间
		NFShmString<64> m_infomationId;//提示ID
		int32_t m_attackMinDistance;//攻击最小距离
		int32_t m_goalMaxNum;//目标最大数量
		int32_t m_goalMaxNumMonster;//目标最大数量（怪物）
		int32_t m_damageType;//伤害类型
		int32_t m_damageRate;//伤害倍率
		int32_t m_awakeDamageRate;//觉醒后技能倍率
		int32_t m_advanceType1DamageRate;//进阶火后技能倍率加成
		int32_t m_advanceType2DamageRate;//进阶雷后技能倍率加成
		int32_t m_advanceType3DamageRate;//进阶冰后技能倍率加成
		int32_t m_damageValue;//附加伤害初始值
		float m_damageParama;//伤害固定值成长系数
		float m_damageRateParama;//伤害倍率成长系数
		int32_t m_addhitrate;//附加命中率
		int64_t m_attackBuff;//给攻击方施加的buff
		int64_t m_behitBuff;//给受击方施加的buff
		NFShmVector<struct E_SkillSkillBuffDesc_s, DEFINE_E_SKILLSKILL_M_BUFF_MAX_NUM> m_buff;//buff包
		NFShmVector<struct E_SkillSkillAwakebuffDesc_s, DEFINE_E_SKILLSKILL_M_AWAKEBUFF_MAX_NUM> m_awakebuff;//觉醒buff包
		NFShmVector<struct E_SkillSkillAdvancetype1buffDesc_s, DEFINE_E_SKILLSKILL_M_ADVANCETYPE1BUFF_MAX_NUM> m_advanceType1buff;//进阶火buff等级
		NFShmVector<struct E_SkillSkillAdvancetype2buffDesc_s, DEFINE_E_SKILLSKILL_M_ADVANCETYPE2BUFF_MAX_NUM> m_advanceType2buff;//进阶雷buff等级
		NFShmVector<struct E_SkillSkillAdvancetype3buffDesc_s, DEFINE_E_SKILLSKILL_M_ADVANCETYPE3BUFF_MAX_NUM> m_advanceType3buff;//进阶冰buff等级

		virtual void write_to_pbmsg(::proto_ff::E_SkillSkill & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_SkillSkill & msg);
		static ::proto_ff::E_SkillSkill* new_pbmsg(){ return new ::proto_ff::E_SkillSkill(); }
		static ::proto_ff::E_SkillSkill make_pbmsg(){ return ::proto_ff::E_SkillSkill(); }
	};
	typedef struct E_SkillSkill_s E_SkillSkill_t;

	struct Sheet_SkillSkill_s : public NFDescStoreSeqOP {
		Sheet_SkillSkill_s();
		virtual ~Sheet_SkillSkill_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_SkillSkill_s, DEFINE_SHEET_SKILLSKILL_E_SKILLSKILL_LIST_MAX_NUM> E_SkillSkill_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_SkillSkill & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_SkillSkill & msg);
		static ::proto_ff::Sheet_SkillSkill* new_pbmsg(){ return new ::proto_ff::Sheet_SkillSkill(); }
		static ::proto_ff::Sheet_SkillSkill make_pbmsg(){ return ::proto_ff::Sheet_SkillSkill(); }
	};
	typedef struct Sheet_SkillSkill_s Sheet_SkillSkill_t;

	struct E_SkillSkilladvance_s : public NFDescStoreSeqOP {
		E_SkillSkilladvance_s();
		virtual ~E_SkillSkilladvance_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//id
		int32_t m_profession;//职业
		int32_t m_type;//类型
		int32_t m_advanceLv;//进阶等级
		NFShmString<64> m_advanceCondition;//进阶条件
		NFShmString<64> m_skillID;//技能ID

		virtual void write_to_pbmsg(::proto_ff::E_SkillSkilladvance & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_SkillSkilladvance & msg);
		static ::proto_ff::E_SkillSkilladvance* new_pbmsg(){ return new ::proto_ff::E_SkillSkilladvance(); }
		static ::proto_ff::E_SkillSkilladvance make_pbmsg(){ return ::proto_ff::E_SkillSkilladvance(); }
	};
	typedef struct E_SkillSkilladvance_s E_SkillSkilladvance_t;

	struct Sheet_SkillSkilladvance_s : public NFDescStoreSeqOP {
		Sheet_SkillSkilladvance_s();
		virtual ~Sheet_SkillSkilladvance_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_SkillSkilladvance_s, DEFINE_SHEET_SKILLSKILLADVANCE_E_SKILLSKILLADVANCE_LIST_MAX_NUM> E_SkillSkilladvance_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_SkillSkilladvance & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_SkillSkilladvance & msg);
		static ::proto_ff::Sheet_SkillSkilladvance* new_pbmsg(){ return new ::proto_ff::Sheet_SkillSkilladvance(); }
		static ::proto_ff::Sheet_SkillSkilladvance make_pbmsg(){ return ::proto_ff::Sheet_SkillSkilladvance(); }
	};
	typedef struct Sheet_SkillSkilladvance_s Sheet_SkillSkilladvance_t;

	struct E_SkillSkillup_s : public NFDescStoreSeqOP {
		E_SkillSkillup_s();
		virtual ~E_SkillSkillup_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//唯一id
		int32_t m_group;//组id
		int32_t m_skillLv;//技能等级
		NFShmString<128> m_skillIds;//技能ID组
		int32_t m_roleLv;//需求人物等级
		int64_t m_costItemId;//消耗的道具ID
		int32_t m_costNum;//道具数量

		virtual void write_to_pbmsg(::proto_ff::E_SkillSkillup & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_SkillSkillup & msg);
		static ::proto_ff::E_SkillSkillup* new_pbmsg(){ return new ::proto_ff::E_SkillSkillup(); }
		static ::proto_ff::E_SkillSkillup make_pbmsg(){ return ::proto_ff::E_SkillSkillup(); }
	};
	typedef struct E_SkillSkillup_s E_SkillSkillup_t;

	struct Sheet_SkillSkillup_s : public NFDescStoreSeqOP {
		Sheet_SkillSkillup_s();
		virtual ~Sheet_SkillSkillup_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_SkillSkillup_s, DEFINE_SHEET_SKILLSKILLUP_E_SKILLSKILLUP_LIST_MAX_NUM> E_SkillSkillup_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_SkillSkillup & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_SkillSkillup & msg);
		static ::proto_ff::Sheet_SkillSkillup* new_pbmsg(){ return new ::proto_ff::Sheet_SkillSkillup(); }
		static ::proto_ff::Sheet_SkillSkillup make_pbmsg(){ return ::proto_ff::Sheet_SkillSkillup(); }
	};
	typedef struct Sheet_SkillSkillup_s Sheet_SkillSkillup_t;

	struct E_SkillSkillawake_s : public NFDescStoreSeqOP {
		E_SkillSkillawake_s();
		virtual ~E_SkillSkillawake_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_skillId;//技能ID
		int32_t m_costItemId;//消耗的道具ID
		int32_t m_costNum;//道具数量

		virtual void write_to_pbmsg(::proto_ff::E_SkillSkillawake & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_SkillSkillawake & msg);
		static ::proto_ff::E_SkillSkillawake* new_pbmsg(){ return new ::proto_ff::E_SkillSkillawake(); }
		static ::proto_ff::E_SkillSkillawake make_pbmsg(){ return ::proto_ff::E_SkillSkillawake(); }
	};
	typedef struct E_SkillSkillawake_s E_SkillSkillawake_t;

	struct Sheet_SkillSkillawake_s : public NFDescStoreSeqOP {
		Sheet_SkillSkillawake_s();
		virtual ~Sheet_SkillSkillawake_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_SkillSkillawake_s, DEFINE_SHEET_SKILLSKILLAWAKE_E_SKILLSKILLAWAKE_LIST_MAX_NUM> E_SkillSkillawake_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_SkillSkillawake & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_SkillSkillawake & msg);
		static ::proto_ff::Sheet_SkillSkillawake* new_pbmsg(){ return new ::proto_ff::Sheet_SkillSkillawake(); }
		static ::proto_ff::Sheet_SkillSkillawake make_pbmsg(){ return ::proto_ff::Sheet_SkillSkillawake(); }
	};
	typedef struct Sheet_SkillSkillawake_s Sheet_SkillSkillawake_t;

	struct E_SkillSkillgroupSkillDesc_s : public NFDescStoreSeqOP {
		E_SkillSkillgroupSkillDesc_s();
		virtual ~E_SkillSkillgroupSkillDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_position;//位置
		int32_t m_Id;//ID

		virtual void write_to_pbmsg(::proto_ff::E_SkillSkillgroupSkillDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_SkillSkillgroupSkillDesc & msg);
		static ::proto_ff::E_SkillSkillgroupSkillDesc* new_pbmsg(){ return new ::proto_ff::E_SkillSkillgroupSkillDesc(); }
		static ::proto_ff::E_SkillSkillgroupSkillDesc make_pbmsg(){ return ::proto_ff::E_SkillSkillgroupSkillDesc(); }
	};
	typedef struct E_SkillSkillgroupSkillDesc_s E_SkillSkillgroupSkillDesc_t;

	struct E_SkillSkillgroup_s : public NFDescStoreSeqOP {
		E_SkillSkillgroup_s();
		virtual ~E_SkillSkillgroup_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_skillGroup;//技能组
		NFShmString<64> m_showSkillType;//显示技能类型
		NFShmVector<struct E_SkillSkillgroupSkillDesc_s, DEFINE_E_SKILLSKILLGROUP_M_SKILL_MAX_NUM> m_skill;//技能

		virtual void write_to_pbmsg(::proto_ff::E_SkillSkillgroup & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_SkillSkillgroup & msg);
		static ::proto_ff::E_SkillSkillgroup* new_pbmsg(){ return new ::proto_ff::E_SkillSkillgroup(); }
		static ::proto_ff::E_SkillSkillgroup make_pbmsg(){ return ::proto_ff::E_SkillSkillgroup(); }
	};
	typedef struct E_SkillSkillgroup_s E_SkillSkillgroup_t;

	struct Sheet_SkillSkillgroup_s : public NFDescStoreSeqOP {
		Sheet_SkillSkillgroup_s();
		virtual ~Sheet_SkillSkillgroup_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_SkillSkillgroup_s, DEFINE_SHEET_SKILLSKILLGROUP_E_SKILLSKILLGROUP_LIST_MAX_NUM> E_SkillSkillgroup_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_SkillSkillgroup & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_SkillSkillgroup & msg);
		static ::proto_ff::Sheet_SkillSkillgroup* new_pbmsg(){ return new ::proto_ff::Sheet_SkillSkillgroup(); }
		static ::proto_ff::Sheet_SkillSkillgroup make_pbmsg(){ return ::proto_ff::Sheet_SkillSkillgroup(); }
	};
	typedef struct Sheet_SkillSkillgroup_s Sheet_SkillSkillgroup_t;

	struct E_SkillAttgroupAttributeDesc_s : public NFDescStoreSeqOP {
		E_SkillAttgroupAttributeDesc_s();
		virtual ~E_SkillAttgroupAttributeDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int64_t m_value;//值
		int32_t m_type;//类型

		virtual void write_to_pbmsg(::proto_ff::E_SkillAttgroupAttributeDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_SkillAttgroupAttributeDesc & msg);
		static ::proto_ff::E_SkillAttgroupAttributeDesc* new_pbmsg(){ return new ::proto_ff::E_SkillAttgroupAttributeDesc(); }
		static ::proto_ff::E_SkillAttgroupAttributeDesc make_pbmsg(){ return ::proto_ff::E_SkillAttgroupAttributeDesc(); }
	};
	typedef struct E_SkillAttgroupAttributeDesc_s E_SkillAttgroupAttributeDesc_t;

	struct E_SkillAttgroup_s : public NFDescStoreSeqOP {
		E_SkillAttgroup_s();
		virtual ~E_SkillAttgroup_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//id
		NFShmVector<struct E_SkillAttgroupAttributeDesc_s, DEFINE_E_SKILLATTGROUP_M_ATTRIBUTE_MAX_NUM> m_attribute;//属性

		virtual void write_to_pbmsg(::proto_ff::E_SkillAttgroup & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_SkillAttgroup & msg);
		static ::proto_ff::E_SkillAttgroup* new_pbmsg(){ return new ::proto_ff::E_SkillAttgroup(); }
		static ::proto_ff::E_SkillAttgroup make_pbmsg(){ return ::proto_ff::E_SkillAttgroup(); }
	};
	typedef struct E_SkillAttgroup_s E_SkillAttgroup_t;

	struct Sheet_SkillAttgroup_s : public NFDescStoreSeqOP {
		Sheet_SkillAttgroup_s();
		virtual ~Sheet_SkillAttgroup_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_SkillAttgroup_s, DEFINE_SHEET_SKILLATTGROUP_E_SKILLATTGROUP_LIST_MAX_NUM> E_SkillAttgroup_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_SkillAttgroup & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_SkillAttgroup & msg);
		static ::proto_ff::Sheet_SkillAttgroup* new_pbmsg(){ return new ::proto_ff::Sheet_SkillAttgroup(); }
		static ::proto_ff::Sheet_SkillAttgroup make_pbmsg(){ return ::proto_ff::Sheet_SkillAttgroup(); }
	};
	typedef struct Sheet_SkillAttgroup_s Sheet_SkillAttgroup_t;

}

