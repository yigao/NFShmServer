#pragma once

#include <stdint.h>
#include <NFComm/NFShmStl/NFShmString.h>
#include <NFComm/NFShmStl/NFShmVector.h>
#include <NFComm/NFShmCore/NFSeqOP.h>
#include <NFComm/NFShmCore/NFShmMgr.h>
#include "E_Rune.pb.h"
#include "E_Rune_s.h"

#define DEFINE_SHEET_RUNECONST_E_RUNECONST_LIST_MAX_NUM 2
#define DEFINE_E_RUNERUNE_M_ATTRIBUTE_MAX_NUM 4
#define DEFINE_SHEET_RUNERUNE_E_RUNERUNE_LIST_MAX_NUM 32
#define DEFINE_SHEET_RUNERUNEWORDS_E_RUNERUNEWORDS_LIST_MAX_NUM 128
#define DEFINE_SHEET_RUNEQUENCHING_E_RUNEQUENCHING_LIST_MAX_NUM 16
#define DEFINE_SHEET_RUNECOMPARE_E_RUNECOMPARE_LIST_MAX_NUM 64
#define DEFINE_E_RUNESTUNTSKILL_M_ACTIVATE_MAX_NUM 3
#define DEFINE_SHEET_RUNESTUNTSKILL_E_RUNESTUNTSKILL_LIST_MAX_NUM 16
#define DEFINE_E_RUNEPASSIVESKILL_M_TYPE_MAX_NUM 6
#define DEFINE_SHEET_RUNEPASSIVESKILL_E_RUNEPASSIVESKILL_LIST_MAX_NUM 8
#define DEFINE_E_RUNEUPGRADE_M_TYPE_MAX_NUM 4
#define DEFINE_SHEET_RUNEUPGRADE_E_RUNEUPGRADE_LIST_MAX_NUM 32
#define DEFINE_SHEET_RUNEUPGRADEEXP_E_RUNEUPGRADEEXP_LIST_MAX_NUM 512
#define DEFINE_E_RUNEADVANCED_M_ATTRIBUTE_MAX_NUM 4
#define DEFINE_SHEET_RUNEADVANCED_E_RUNEADVANCED_LIST_MAX_NUM 256
#define DEFINE_E_RUNESOARING_M_ATTRIBUTE_MAX_NUM 6
#define DEFINE_SHEET_RUNESOARING_E_RUNESOARING_LIST_MAX_NUM 64
#define DEFINE_SHEET_RUNEHANDBOOK_E_RUNEHANDBOOK_LIST_MAX_NUM 128


namespace proto_ff_s {

	struct E_RuneConst_s : public NFDescStoreSeqOP {
		E_RuneConst_s();
		virtual ~E_RuneConst_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//id
		int32_t m_costItem;//保护道具id
		int32_t m_lokCostNum;//封印单个格子扣除物品
		int32_t m_mallID;//商品id
		int32_t m_quenching_max;//淬炼格子最大数

		virtual void write_to_pbmsg(::proto_ff::E_RuneConst & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_RuneConst & msg);
		static ::proto_ff::E_RuneConst* new_pbmsg(){ return new ::proto_ff::E_RuneConst(); }
		static ::proto_ff::E_RuneConst make_pbmsg(){ return ::proto_ff::E_RuneConst(); }
	};
	typedef struct E_RuneConst_s E_RuneConst_t;

	struct Sheet_RuneConst_s : public NFDescStoreSeqOP {
		Sheet_RuneConst_s();
		virtual ~Sheet_RuneConst_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_RuneConst_s, DEFINE_SHEET_RUNECONST_E_RUNECONST_LIST_MAX_NUM> E_RuneConst_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_RuneConst & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_RuneConst & msg);
		static ::proto_ff::Sheet_RuneConst* new_pbmsg(){ return new ::proto_ff::Sheet_RuneConst(); }
		static ::proto_ff::Sheet_RuneConst make_pbmsg(){ return ::proto_ff::Sheet_RuneConst(); }
	};
	typedef struct Sheet_RuneConst_s Sheet_RuneConst_t;

	struct E_RuneRuneAttributeDesc_s : public NFDescStoreSeqOP {
		E_RuneRuneAttributeDesc_s();
		virtual ~E_RuneRuneAttributeDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_value;//数值
		int32_t m_type;//

		virtual void write_to_pbmsg(::proto_ff::E_RuneRuneAttributeDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_RuneRuneAttributeDesc & msg);
		static ::proto_ff::E_RuneRuneAttributeDesc* new_pbmsg(){ return new ::proto_ff::E_RuneRuneAttributeDesc(); }
		static ::proto_ff::E_RuneRuneAttributeDesc make_pbmsg(){ return ::proto_ff::E_RuneRuneAttributeDesc(); }
	};
	typedef struct E_RuneRuneAttributeDesc_s E_RuneRuneAttributeDesc_t;

	struct E_RuneRune_s : public NFDescStoreSeqOP {
		E_RuneRune_s();
		virtual ~E_RuneRune_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//id
		int32_t m_positionType;//符文部位类型
		int32_t m_attributeType;//符文属性类型
		int32_t m_subType;//符文子类型
		int32_t m_quality;//符文品质
		int32_t m_level;//穿戴等级限制
		int32_t m_quenchingLminit;//淬炼上限
		int32_t m_disassemble;//是否可分解
		int32_t m_disassembleId;//分解物品id
		int32_t m_disassembleNum;//分解物品数量
		NFShmVector<struct E_RuneRuneAttributeDesc_s, DEFINE_E_RUNERUNE_M_ATTRIBUTE_MAX_NUM> m_attribute;//属性

		virtual void write_to_pbmsg(::proto_ff::E_RuneRune & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_RuneRune & msg);
		static ::proto_ff::E_RuneRune* new_pbmsg(){ return new ::proto_ff::E_RuneRune(); }
		static ::proto_ff::E_RuneRune make_pbmsg(){ return ::proto_ff::E_RuneRune(); }
	};
	typedef struct E_RuneRune_s E_RuneRune_t;

	struct Sheet_RuneRune_s : public NFDescStoreSeqOP {
		Sheet_RuneRune_s();
		virtual ~Sheet_RuneRune_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_RuneRune_s, DEFINE_SHEET_RUNERUNE_E_RUNERUNE_LIST_MAX_NUM> E_RuneRune_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_RuneRune & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_RuneRune & msg);
		static ::proto_ff::Sheet_RuneRune* new_pbmsg(){ return new ::proto_ff::Sheet_RuneRune(); }
		static ::proto_ff::Sheet_RuneRune make_pbmsg(){ return ::proto_ff::Sheet_RuneRune(); }
	};
	typedef struct Sheet_RuneRune_s Sheet_RuneRune_t;

	struct E_RuneRunewords_s : public NFDescStoreSeqOP {
		E_RuneRunewords_s();
		virtual ~E_RuneRunewords_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//id
		NFShmString<64> m_name;//符文之语名称
		int32_t m_skill;//符文之语技能
		int32_t m_quenchingLminit;//淬炼上限
		int32_t m_disassembleId;//分解物品id
		int32_t m_disassembleNum;//分解物品数量
		int32_t m_starLvMax;//最大升星等级
		int32_t m_costItem;//升星材料
		int32_t m_costNum;//升星材料数量

		virtual void write_to_pbmsg(::proto_ff::E_RuneRunewords & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_RuneRunewords & msg);
		static ::proto_ff::E_RuneRunewords* new_pbmsg(){ return new ::proto_ff::E_RuneRunewords(); }
		static ::proto_ff::E_RuneRunewords make_pbmsg(){ return ::proto_ff::E_RuneRunewords(); }
	};
	typedef struct E_RuneRunewords_s E_RuneRunewords_t;

	struct Sheet_RuneRunewords_s : public NFDescStoreSeqOP {
		Sheet_RuneRunewords_s();
		virtual ~Sheet_RuneRunewords_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_RuneRunewords_s, DEFINE_SHEET_RUNERUNEWORDS_E_RUNERUNEWORDS_LIST_MAX_NUM> E_RuneRunewords_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_RuneRunewords & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_RuneRunewords & msg);
		static ::proto_ff::Sheet_RuneRunewords* new_pbmsg(){ return new ::proto_ff::Sheet_RuneRunewords(); }
		static ::proto_ff::Sheet_RuneRunewords make_pbmsg(){ return ::proto_ff::Sheet_RuneRunewords(); }
	};
	typedef struct Sheet_RuneRunewords_s Sheet_RuneRunewords_t;

	struct E_RuneQuenching_s : public NFDescStoreSeqOP {
		E_RuneQuenching_s();
		virtual ~E_RuneQuenching_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//槽位id
		int32_t m_expandProb;//淬炼拓展概率
		int32_t m_qualityLimit;//扩展符文品质要求

		virtual void write_to_pbmsg(::proto_ff::E_RuneQuenching & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_RuneQuenching & msg);
		static ::proto_ff::E_RuneQuenching* new_pbmsg(){ return new ::proto_ff::E_RuneQuenching(); }
		static ::proto_ff::E_RuneQuenching make_pbmsg(){ return ::proto_ff::E_RuneQuenching(); }
	};
	typedef struct E_RuneQuenching_s E_RuneQuenching_t;

	struct Sheet_RuneQuenching_s : public NFDescStoreSeqOP {
		Sheet_RuneQuenching_s();
		virtual ~Sheet_RuneQuenching_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_RuneQuenching_s, DEFINE_SHEET_RUNEQUENCHING_E_RUNEQUENCHING_LIST_MAX_NUM> E_RuneQuenching_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_RuneQuenching & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_RuneQuenching & msg);
		static ::proto_ff::Sheet_RuneQuenching* new_pbmsg(){ return new ::proto_ff::Sheet_RuneQuenching(); }
		static ::proto_ff::Sheet_RuneQuenching make_pbmsg(){ return ::proto_ff::Sheet_RuneQuenching(); }
	};
	typedef struct Sheet_RuneQuenching_s Sheet_RuneQuenching_t;

	struct E_RuneCompare_s : public NFDescStoreSeqOP {
		E_RuneCompare_s();
		virtual ~E_RuneCompare_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//id
		int32_t m_positionType;//符文部位类型
		int32_t m_attributeType;//符文属性类型
		int32_t m_quality;//符文品质

		virtual void write_to_pbmsg(::proto_ff::E_RuneCompare & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_RuneCompare & msg);
		static ::proto_ff::E_RuneCompare* new_pbmsg(){ return new ::proto_ff::E_RuneCompare(); }
		static ::proto_ff::E_RuneCompare make_pbmsg(){ return ::proto_ff::E_RuneCompare(); }
	};
	typedef struct E_RuneCompare_s E_RuneCompare_t;

	struct Sheet_RuneCompare_s : public NFDescStoreSeqOP {
		Sheet_RuneCompare_s();
		virtual ~Sheet_RuneCompare_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_RuneCompare_s, DEFINE_SHEET_RUNECOMPARE_E_RUNECOMPARE_LIST_MAX_NUM> E_RuneCompare_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_RuneCompare & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_RuneCompare & msg);
		static ::proto_ff::Sheet_RuneCompare* new_pbmsg(){ return new ::proto_ff::Sheet_RuneCompare(); }
		static ::proto_ff::Sheet_RuneCompare make_pbmsg(){ return ::proto_ff::Sheet_RuneCompare(); }
	};
	typedef struct Sheet_RuneCompare_s Sheet_RuneCompare_t;

	struct E_RuneStuntskillActivateDesc_s : public NFDescStoreSeqOP {
		E_RuneStuntskillActivateDesc_s();
		virtual ~E_RuneStuntskillActivateDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_num;//数量
		int32_t m_quality;//品质
		int32_t m_attributeType;//属性类型
		int32_t m_positionType;//部位类型

		virtual void write_to_pbmsg(::proto_ff::E_RuneStuntskillActivateDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_RuneStuntskillActivateDesc & msg);
		static ::proto_ff::E_RuneStuntskillActivateDesc* new_pbmsg(){ return new ::proto_ff::E_RuneStuntskillActivateDesc(); }
		static ::proto_ff::E_RuneStuntskillActivateDesc make_pbmsg(){ return ::proto_ff::E_RuneStuntskillActivateDesc(); }
	};
	typedef struct E_RuneStuntskillActivateDesc_s E_RuneStuntskillActivateDesc_t;

	struct E_RuneStuntskill_s : public NFDescStoreSeqOP {
		E_RuneStuntskill_s();
		virtual ~E_RuneStuntskill_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_skillId;//技能id
		int32_t m_position;//装备部位
		int32_t m_quality;//技能品质
		NFShmVector<struct E_RuneStuntskillActivateDesc_s, DEFINE_E_RUNESTUNTSKILL_M_ACTIVATE_MAX_NUM> m_activate;//激活条件

		virtual void write_to_pbmsg(::proto_ff::E_RuneStuntskill & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_RuneStuntskill & msg);
		static ::proto_ff::E_RuneStuntskill* new_pbmsg(){ return new ::proto_ff::E_RuneStuntskill(); }
		static ::proto_ff::E_RuneStuntskill make_pbmsg(){ return ::proto_ff::E_RuneStuntskill(); }
	};
	typedef struct E_RuneStuntskill_s E_RuneStuntskill_t;

	struct Sheet_RuneStuntskill_s : public NFDescStoreSeqOP {
		Sheet_RuneStuntskill_s();
		virtual ~Sheet_RuneStuntskill_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_RuneStuntskill_s, DEFINE_SHEET_RUNESTUNTSKILL_E_RUNESTUNTSKILL_LIST_MAX_NUM> E_RuneStuntskill_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_RuneStuntskill & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_RuneStuntskill & msg);
		static ::proto_ff::Sheet_RuneStuntskill* new_pbmsg(){ return new ::proto_ff::Sheet_RuneStuntskill(); }
		static ::proto_ff::Sheet_RuneStuntskill make_pbmsg(){ return ::proto_ff::Sheet_RuneStuntskill(); }
	};
	typedef struct Sheet_RuneStuntskill_s Sheet_RuneStuntskill_t;

	struct E_RunePassiveskillTypeDesc_s : public NFDescStoreSeqOP {
		E_RunePassiveskillTypeDesc_s();
		virtual ~E_RunePassiveskillTypeDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_num;//值
		int32_t m_id;//ID

		virtual void write_to_pbmsg(::proto_ff::E_RunePassiveskillTypeDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_RunePassiveskillTypeDesc & msg);
		static ::proto_ff::E_RunePassiveskillTypeDesc* new_pbmsg(){ return new ::proto_ff::E_RunePassiveskillTypeDesc(); }
		static ::proto_ff::E_RunePassiveskillTypeDesc make_pbmsg(){ return ::proto_ff::E_RunePassiveskillTypeDesc(); }
	};
	typedef struct E_RunePassiveskillTypeDesc_s E_RunePassiveskillTypeDesc_t;

	struct E_RunePassiveskill_s : public NFDescStoreSeqOP {
		E_RunePassiveskill_s();
		virtual ~E_RunePassiveskill_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//id
		int32_t m_position;//装备部位
		int32_t m_lv;//被动等级
		int32_t m_quality;//技能品质
		int32_t m_activateQuality;//激活条件品质
		int32_t m_activateNum;//激活条件数量
		NFShmVector<struct E_RunePassiveskillTypeDesc_s, DEFINE_E_RUNEPASSIVESKILL_M_TYPE_MAX_NUM> m_type;//属性

		virtual void write_to_pbmsg(::proto_ff::E_RunePassiveskill & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_RunePassiveskill & msg);
		static ::proto_ff::E_RunePassiveskill* new_pbmsg(){ return new ::proto_ff::E_RunePassiveskill(); }
		static ::proto_ff::E_RunePassiveskill make_pbmsg(){ return ::proto_ff::E_RunePassiveskill(); }
	};
	typedef struct E_RunePassiveskill_s E_RunePassiveskill_t;

	struct Sheet_RunePassiveskill_s : public NFDescStoreSeqOP {
		Sheet_RunePassiveskill_s();
		virtual ~Sheet_RunePassiveskill_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_RunePassiveskill_s, DEFINE_SHEET_RUNEPASSIVESKILL_E_RUNEPASSIVESKILL_LIST_MAX_NUM> E_RunePassiveskill_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_RunePassiveskill & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_RunePassiveskill & msg);
		static ::proto_ff::Sheet_RunePassiveskill* new_pbmsg(){ return new ::proto_ff::Sheet_RunePassiveskill(); }
		static ::proto_ff::Sheet_RunePassiveskill make_pbmsg(){ return ::proto_ff::Sheet_RunePassiveskill(); }
	};
	typedef struct Sheet_RunePassiveskill_s Sheet_RunePassiveskill_t;

	struct E_RuneUpgradeTypeDesc_s : public NFDescStoreSeqOP {
		E_RuneUpgradeTypeDesc_s();
		virtual ~E_RuneUpgradeTypeDesc_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmString<64> m_num;//值
		int32_t m_id;//ID

		virtual void write_to_pbmsg(::proto_ff::E_RuneUpgradeTypeDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_RuneUpgradeTypeDesc & msg);
		static ::proto_ff::E_RuneUpgradeTypeDesc* new_pbmsg(){ return new ::proto_ff::E_RuneUpgradeTypeDesc(); }
		static ::proto_ff::E_RuneUpgradeTypeDesc make_pbmsg(){ return ::proto_ff::E_RuneUpgradeTypeDesc(); }
	};
	typedef struct E_RuneUpgradeTypeDesc_s E_RuneUpgradeTypeDesc_t;

	struct E_RuneUpgrade_s : public NFDescStoreSeqOP {
		E_RuneUpgrade_s();
		virtual ~E_RuneUpgrade_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_runeId;//符文id
		int32_t m_upgradeUp;//升级上限
		NFShmVector<struct E_RuneUpgradeTypeDesc_s, DEFINE_E_RUNEUPGRADE_M_TYPE_MAX_NUM> m_type;//属性

		virtual void write_to_pbmsg(::proto_ff::E_RuneUpgrade & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_RuneUpgrade & msg);
		static ::proto_ff::E_RuneUpgrade* new_pbmsg(){ return new ::proto_ff::E_RuneUpgrade(); }
		static ::proto_ff::E_RuneUpgrade make_pbmsg(){ return ::proto_ff::E_RuneUpgrade(); }
	};
	typedef struct E_RuneUpgrade_s E_RuneUpgrade_t;

	struct Sheet_RuneUpgrade_s : public NFDescStoreSeqOP {
		Sheet_RuneUpgrade_s();
		virtual ~Sheet_RuneUpgrade_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_RuneUpgrade_s, DEFINE_SHEET_RUNEUPGRADE_E_RUNEUPGRADE_LIST_MAX_NUM> E_RuneUpgrade_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_RuneUpgrade & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_RuneUpgrade & msg);
		static ::proto_ff::Sheet_RuneUpgrade* new_pbmsg(){ return new ::proto_ff::Sheet_RuneUpgrade(); }
		static ::proto_ff::Sheet_RuneUpgrade make_pbmsg(){ return ::proto_ff::Sheet_RuneUpgrade(); }
	};
	typedef struct Sheet_RuneUpgrade_s Sheet_RuneUpgrade_t;

	struct E_RuneUpgradeexp_s : public NFDescStoreSeqOP {
		E_RuneUpgradeexp_s();
		virtual ~E_RuneUpgradeexp_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_Lv;//等级
		int32_t m_costItem;//消耗道具
		int32_t m_costNum;//道具数量

		virtual void write_to_pbmsg(::proto_ff::E_RuneUpgradeexp & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_RuneUpgradeexp & msg);
		static ::proto_ff::E_RuneUpgradeexp* new_pbmsg(){ return new ::proto_ff::E_RuneUpgradeexp(); }
		static ::proto_ff::E_RuneUpgradeexp make_pbmsg(){ return ::proto_ff::E_RuneUpgradeexp(); }
	};
	typedef struct E_RuneUpgradeexp_s E_RuneUpgradeexp_t;

	struct Sheet_RuneUpgradeexp_s : public NFDescStoreSeqOP {
		Sheet_RuneUpgradeexp_s();
		virtual ~Sheet_RuneUpgradeexp_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_RuneUpgradeexp_s, DEFINE_SHEET_RUNEUPGRADEEXP_E_RUNEUPGRADEEXP_LIST_MAX_NUM> E_RuneUpgradeexp_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_RuneUpgradeexp & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_RuneUpgradeexp & msg);
		static ::proto_ff::Sheet_RuneUpgradeexp* new_pbmsg(){ return new ::proto_ff::Sheet_RuneUpgradeexp(); }
		static ::proto_ff::Sheet_RuneUpgradeexp make_pbmsg(){ return ::proto_ff::Sheet_RuneUpgradeexp(); }
	};
	typedef struct Sheet_RuneUpgradeexp_s Sheet_RuneUpgradeexp_t;

	struct E_RuneAdvancedAttributeDesc_s : public NFDescStoreSeqOP {
		E_RuneAdvancedAttributeDesc_s();
		virtual ~E_RuneAdvancedAttributeDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_value;//值
		int32_t m_type;//ID

		virtual void write_to_pbmsg(::proto_ff::E_RuneAdvancedAttributeDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_RuneAdvancedAttributeDesc & msg);
		static ::proto_ff::E_RuneAdvancedAttributeDesc* new_pbmsg(){ return new ::proto_ff::E_RuneAdvancedAttributeDesc(); }
		static ::proto_ff::E_RuneAdvancedAttributeDesc make_pbmsg(){ return ::proto_ff::E_RuneAdvancedAttributeDesc(); }
	};
	typedef struct E_RuneAdvancedAttributeDesc_s E_RuneAdvancedAttributeDesc_t;

	struct E_RuneAdvanced_s : public NFDescStoreSeqOP {
		E_RuneAdvanced_s();
		virtual ~E_RuneAdvanced_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//id
		int32_t m_wearQuality;//品阶
		int32_t m_runeId;//符文id
		int32_t m_costItem;//消耗道具
		int32_t m_costNum;//道具数量
		NFShmVector<struct E_RuneAdvancedAttributeDesc_s, DEFINE_E_RUNEADVANCED_M_ATTRIBUTE_MAX_NUM> m_attribute;//基础属性

		virtual void write_to_pbmsg(::proto_ff::E_RuneAdvanced & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_RuneAdvanced & msg);
		static ::proto_ff::E_RuneAdvanced* new_pbmsg(){ return new ::proto_ff::E_RuneAdvanced(); }
		static ::proto_ff::E_RuneAdvanced make_pbmsg(){ return ::proto_ff::E_RuneAdvanced(); }
	};
	typedef struct E_RuneAdvanced_s E_RuneAdvanced_t;

	struct Sheet_RuneAdvanced_s : public NFDescStoreSeqOP {
		Sheet_RuneAdvanced_s();
		virtual ~Sheet_RuneAdvanced_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_RuneAdvanced_s, DEFINE_SHEET_RUNEADVANCED_E_RUNEADVANCED_LIST_MAX_NUM> E_RuneAdvanced_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_RuneAdvanced & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_RuneAdvanced & msg);
		static ::proto_ff::Sheet_RuneAdvanced* new_pbmsg(){ return new ::proto_ff::Sheet_RuneAdvanced(); }
		static ::proto_ff::Sheet_RuneAdvanced make_pbmsg(){ return ::proto_ff::Sheet_RuneAdvanced(); }
	};
	typedef struct Sheet_RuneAdvanced_s Sheet_RuneAdvanced_t;

	struct E_RuneSoaringAttributeDesc_s : public NFDescStoreSeqOP {
		E_RuneSoaringAttributeDesc_s();
		virtual ~E_RuneSoaringAttributeDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_value;//值
		int32_t m_type;//ID

		virtual void write_to_pbmsg(::proto_ff::E_RuneSoaringAttributeDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_RuneSoaringAttributeDesc & msg);
		static ::proto_ff::E_RuneSoaringAttributeDesc* new_pbmsg(){ return new ::proto_ff::E_RuneSoaringAttributeDesc(); }
		static ::proto_ff::E_RuneSoaringAttributeDesc make_pbmsg(){ return ::proto_ff::E_RuneSoaringAttributeDesc(); }
	};
	typedef struct E_RuneSoaringAttributeDesc_s E_RuneSoaringAttributeDesc_t;

	struct E_RuneSoaring_s : public NFDescStoreSeqOP {
		E_RuneSoaring_s();
		virtual ~E_RuneSoaring_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//id
		int32_t m_lvId;//飞升等级
		int32_t m_wearQuality;//品阶要求
		int32_t m_runeId;//符文id
		NFShmVector<struct E_RuneSoaringAttributeDesc_s, DEFINE_E_RUNESOARING_M_ATTRIBUTE_MAX_NUM> m_attribute;//基础属性

		virtual void write_to_pbmsg(::proto_ff::E_RuneSoaring & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_RuneSoaring & msg);
		static ::proto_ff::E_RuneSoaring* new_pbmsg(){ return new ::proto_ff::E_RuneSoaring(); }
		static ::proto_ff::E_RuneSoaring make_pbmsg(){ return ::proto_ff::E_RuneSoaring(); }
	};
	typedef struct E_RuneSoaring_s E_RuneSoaring_t;

	struct Sheet_RuneSoaring_s : public NFDescStoreSeqOP {
		Sheet_RuneSoaring_s();
		virtual ~Sheet_RuneSoaring_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_RuneSoaring_s, DEFINE_SHEET_RUNESOARING_E_RUNESOARING_LIST_MAX_NUM> E_RuneSoaring_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_RuneSoaring & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_RuneSoaring & msg);
		static ::proto_ff::Sheet_RuneSoaring* new_pbmsg(){ return new ::proto_ff::Sheet_RuneSoaring(); }
		static ::proto_ff::Sheet_RuneSoaring make_pbmsg(){ return ::proto_ff::Sheet_RuneSoaring(); }
	};
	typedef struct Sheet_RuneSoaring_s Sheet_RuneSoaring_t;

	struct E_RuneHandbook_s : public NFDescStoreSeqOP {
		E_RuneHandbook_s();
		virtual ~E_RuneHandbook_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//id
		int32_t m_lvId;//物品id
		int32_t m_rank;//排序
		int32_t m_type;//图鉴类型
		NFShmString<64> m_typeName;//图鉴类型名称
		int32_t m_subType;//图鉴子类型
		NFShmString<64> m_subTypeName;//图鉴子类型名称

		virtual void write_to_pbmsg(::proto_ff::E_RuneHandbook & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_RuneHandbook & msg);
		static ::proto_ff::E_RuneHandbook* new_pbmsg(){ return new ::proto_ff::E_RuneHandbook(); }
		static ::proto_ff::E_RuneHandbook make_pbmsg(){ return ::proto_ff::E_RuneHandbook(); }
	};
	typedef struct E_RuneHandbook_s E_RuneHandbook_t;

	struct Sheet_RuneHandbook_s : public NFDescStoreSeqOP {
		Sheet_RuneHandbook_s();
		virtual ~Sheet_RuneHandbook_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_RuneHandbook_s, DEFINE_SHEET_RUNEHANDBOOK_E_RUNEHANDBOOK_LIST_MAX_NUM> E_RuneHandbook_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_RuneHandbook & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_RuneHandbook & msg);
		static ::proto_ff::Sheet_RuneHandbook* new_pbmsg(){ return new ::proto_ff::Sheet_RuneHandbook(); }
		static ::proto_ff::Sheet_RuneHandbook make_pbmsg(){ return ::proto_ff::Sheet_RuneHandbook(); }
	};
	typedef struct Sheet_RuneHandbook_s Sheet_RuneHandbook_t;

}

