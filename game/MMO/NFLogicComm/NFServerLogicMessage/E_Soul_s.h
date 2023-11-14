#pragma once

#include <stdint.h>
#include <NFComm/NFShmStl/NFShmString.h>
#include <NFComm/NFShmStl/NFShmVector.h>
#include <NFComm/NFShmCore/NFSeqOP.h>
#include <NFComm/NFShmCore/NFShmMgr.h>
#include "E_Soul.pb.h"
#include "E_Soul_s.h"

#define DEFINE_SHEET_SOULOPEN_E_SOULOPEN_LIST_MAX_NUM 8
#define DEFINE_SHEET_SOULSOUL_E_SOULSOUL_LIST_MAX_NUM 2
#define DEFINE_E_SOULSOULBASIC_M_ATTRIBUTE_MAX_NUM 6
#define DEFINE_SHEET_SOULSOULBASIC_E_SOULSOULBASIC_LIST_MAX_NUM 1024
#define DEFINE_E_SOULSOULADVANCE_M_ATTRIBUTE_MAX_NUM 6
#define DEFINE_SHEET_SOULSOULADVANCE_E_SOULSOULADVANCE_LIST_MAX_NUM 512
#define DEFINE_SHEET_SOULBLESS_E_SOULBLESS_LIST_MAX_NUM 4
#define DEFINE_E_SOULPRIVILEGE_M_ATTRIBUTE_MAX_NUM 4
#define DEFINE_SHEET_SOULPRIVILEGE_E_SOULPRIVILEGE_LIST_MAX_NUM 4
#define DEFINE_SHEET_SOULCRYSTAL_E_SOULCRYSTAL_LIST_MAX_NUM 512
#define DEFINE_SHEET_SOULCRYSTALLV_E_SOULCRYSTALLV_LIST_MAX_NUM 1024
#define DEFINE_E_SOULCRYSTALTOP_M_ATTRIBUTE_MAX_NUM 6
#define DEFINE_SHEET_SOULCRYSTALTOP_E_SOULCRYSTALTOP_LIST_MAX_NUM 64
#define DEFINE_SHEET_SOULCRYSTALHOLE_E_SOULCRYSTALHOLE_LIST_MAX_NUM 16
#define DEFINE_E_SOULFUSION_M_FUSION_MAX_NUM 2
#define DEFINE_SHEET_SOULFUSION_E_SOULFUSION_LIST_MAX_NUM 32
#define DEFINE_SHEET_SOULBONE_E_SOULBONE_LIST_MAX_NUM 8
#define DEFINE_E_SOULBONESKILL_M_PASSIVE_SKILL_MAX_NUM 4
#define DEFINE_SHEET_SOULBONESKILL_E_SOULBONESKILL_LIST_MAX_NUM 32
#define DEFINE_SHEET_SOULBONEKILL_E_SOULBONEKILL_LIST_MAX_NUM 1024
#define DEFINE_E_SOULBONESTRONG_M_TYPE_MAX_NUM 4
#define DEFINE_SHEET_SOULBONESTRONG_E_SOULBONESTRONG_LIST_MAX_NUM 256
#define DEFINE_SHEET_SOULGUWENTYPE_E_SOULGUWENTYPE_LIST_MAX_NUM 4
#define DEFINE_E_SOULGUWENTYPESUIT_M_ATTRIBUTE_MAX_NUM 9
#define DEFINE_SHEET_SOULGUWENTYPESUIT_E_SOULGUWENTYPESUIT_LIST_MAX_NUM 16
#define DEFINE_E_SOULGUWENSKILL_M_SKILLLEVEL_MAX_NUM 7
#define DEFINE_E_SOULGUWENSKILL_M_NUM_MAX_NUM 7
#define DEFINE_SHEET_SOULGUWENSKILL_E_SOULGUWENSKILL_LIST_MAX_NUM 8
#define DEFINE_SHEET_SOULGUWENSLOT_E_SOULGUWENSLOT_LIST_MAX_NUM 8
#define DEFINE_E_SOULGUWENSUIT_M_ATTRIBUTE_MAX_NUM 8
#define DEFINE_SHEET_SOULGUWENSUIT_E_SOULGUWENSUIT_LIST_MAX_NUM 64
#define DEFINE_SHEET_SOULGUWENUPSTAR_E_SOULGUWENUPSTAR_LIST_MAX_NUM 64
#define DEFINE_E_SOULAFFIXES_M_ATTRIBUTE_MAX_NUM 6
#define DEFINE_SHEET_SOULAFFIXES_E_SOULAFFIXES_LIST_MAX_NUM 32
#define DEFINE_E_SOULAFFIXESSUIT_M_SKILL_MAX_NUM 2
#define DEFINE_E_SOULAFFIXESSUIT_M_ATTRIBUTE_MAX_NUM 6
#define DEFINE_SHEET_SOULAFFIXESSUIT_E_SOULAFFIXESSUIT_LIST_MAX_NUM 128


namespace proto_ff_s {

	struct E_SoulOpen_s : public NFDescStoreSeqOP {
		E_SoulOpen_s();
		virtual ~E_SoulOpen_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//id
		int32_t m_lv;//解锁等级
		int32_t m_box;//奖励

		virtual void write_to_pbmsg(::proto_ff::E_SoulOpen & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_SoulOpen & msg);
		static ::proto_ff::E_SoulOpen* new_pbmsg(){ return new ::proto_ff::E_SoulOpen(); }
		static ::proto_ff::E_SoulOpen make_pbmsg(){ return ::proto_ff::E_SoulOpen(); }
	};
	typedef struct E_SoulOpen_s E_SoulOpen_t;

	struct Sheet_SoulOpen_s : public NFDescStoreSeqOP {
		Sheet_SoulOpen_s();
		virtual ~Sheet_SoulOpen_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_SoulOpen_s, DEFINE_SHEET_SOULOPEN_E_SOULOPEN_LIST_MAX_NUM> E_SoulOpen_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_SoulOpen & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_SoulOpen & msg);
		static ::proto_ff::Sheet_SoulOpen* new_pbmsg(){ return new ::proto_ff::Sheet_SoulOpen(); }
		static ::proto_ff::Sheet_SoulOpen make_pbmsg(){ return ::proto_ff::Sheet_SoulOpen(); }
	};
	typedef struct Sheet_SoulOpen_s Sheet_SoulOpen_t;

	struct E_SoulSoul_s : public NFDescStoreSeqOP {
		E_SoulSoul_s();
		virtual ~E_SoulSoul_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//id
		NFShmString<64> m_name;//名字
		int32_t m_lvItem;//升级所需道具
		int32_t m_advanceItem;//进阶所需道具
		int32_t m_sacrificeSkill;//牺牲技
		NFShmString<128> m_SkillLv;//牺牲技等级[等级;升级需要的阶级]

		virtual void write_to_pbmsg(::proto_ff::E_SoulSoul & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_SoulSoul & msg);
		static ::proto_ff::E_SoulSoul* new_pbmsg(){ return new ::proto_ff::E_SoulSoul(); }
		static ::proto_ff::E_SoulSoul make_pbmsg(){ return ::proto_ff::E_SoulSoul(); }
	};
	typedef struct E_SoulSoul_s E_SoulSoul_t;

	struct Sheet_SoulSoul_s : public NFDescStoreSeqOP {
		Sheet_SoulSoul_s();
		virtual ~Sheet_SoulSoul_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_SoulSoul_s, DEFINE_SHEET_SOULSOUL_E_SOULSOUL_LIST_MAX_NUM> E_SoulSoul_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_SoulSoul & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_SoulSoul & msg);
		static ::proto_ff::Sheet_SoulSoul* new_pbmsg(){ return new ::proto_ff::Sheet_SoulSoul(); }
		static ::proto_ff::Sheet_SoulSoul make_pbmsg(){ return ::proto_ff::Sheet_SoulSoul(); }
	};
	typedef struct Sheet_SoulSoul_s Sheet_SoulSoul_t;

	struct E_SoulSoulbasicAttributeDesc_s : public NFDescStoreSeqOP {
		E_SoulSoulbasicAttributeDesc_s();
		virtual ~E_SoulSoulbasicAttributeDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_value;//值
		int32_t m_type;//ID

		virtual void write_to_pbmsg(::proto_ff::E_SoulSoulbasicAttributeDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_SoulSoulbasicAttributeDesc & msg);
		static ::proto_ff::E_SoulSoulbasicAttributeDesc* new_pbmsg(){ return new ::proto_ff::E_SoulSoulbasicAttributeDesc(); }
		static ::proto_ff::E_SoulSoulbasicAttributeDesc make_pbmsg(){ return ::proto_ff::E_SoulSoulbasicAttributeDesc(); }
	};
	typedef struct E_SoulSoulbasicAttributeDesc_s E_SoulSoulbasicAttributeDesc_t;

	struct E_SoulSoulbasic_s : public NFDescStoreSeqOP {
		E_SoulSoulbasic_s();
		virtual ~E_SoulSoulbasic_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//id
		int32_t m_soulId;//战魂ID
		int32_t m_soulLv;//等级
		int32_t m_soulExp;//升级所需魂灵
		NFShmVector<struct E_SoulSoulbasicAttributeDesc_s, DEFINE_E_SOULSOULBASIC_M_ATTRIBUTE_MAX_NUM> m_attribute;//基础属性

		virtual void write_to_pbmsg(::proto_ff::E_SoulSoulbasic & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_SoulSoulbasic & msg);
		static ::proto_ff::E_SoulSoulbasic* new_pbmsg(){ return new ::proto_ff::E_SoulSoulbasic(); }
		static ::proto_ff::E_SoulSoulbasic make_pbmsg(){ return ::proto_ff::E_SoulSoulbasic(); }
	};
	typedef struct E_SoulSoulbasic_s E_SoulSoulbasic_t;

	struct Sheet_SoulSoulbasic_s : public NFDescStoreSeqOP {
		Sheet_SoulSoulbasic_s();
		virtual ~Sheet_SoulSoulbasic_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_SoulSoulbasic_s, DEFINE_SHEET_SOULSOULBASIC_E_SOULSOULBASIC_LIST_MAX_NUM> E_SoulSoulbasic_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_SoulSoulbasic & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_SoulSoulbasic & msg);
		static ::proto_ff::Sheet_SoulSoulbasic* new_pbmsg(){ return new ::proto_ff::Sheet_SoulSoulbasic(); }
		static ::proto_ff::Sheet_SoulSoulbasic make_pbmsg(){ return ::proto_ff::Sheet_SoulSoulbasic(); }
	};
	typedef struct Sheet_SoulSoulbasic_s Sheet_SoulSoulbasic_t;

	struct E_SoulSouladvanceAttributeDesc_s : public NFDescStoreSeqOP {
		E_SoulSouladvanceAttributeDesc_s();
		virtual ~E_SoulSouladvanceAttributeDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_value;//值
		int32_t m_type;//ID

		virtual void write_to_pbmsg(::proto_ff::E_SoulSouladvanceAttributeDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_SoulSouladvanceAttributeDesc & msg);
		static ::proto_ff::E_SoulSouladvanceAttributeDesc* new_pbmsg(){ return new ::proto_ff::E_SoulSouladvanceAttributeDesc(); }
		static ::proto_ff::E_SoulSouladvanceAttributeDesc make_pbmsg(){ return ::proto_ff::E_SoulSouladvanceAttributeDesc(); }
	};
	typedef struct E_SoulSouladvanceAttributeDesc_s E_SoulSouladvanceAttributeDesc_t;

	struct E_SoulSouladvance_s : public NFDescStoreSeqOP {
		E_SoulSouladvance_s();
		virtual ~E_SoulSouladvance_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//id
		int32_t m_soulId;//战魂ID
		int32_t m_advanceLv;//等级
		int32_t m_advanceNum;//升阶所需道具数量
		NFShmVector<struct E_SoulSouladvanceAttributeDesc_s, DEFINE_E_SOULSOULADVANCE_M_ATTRIBUTE_MAX_NUM> m_attribute;//基础属性

		virtual void write_to_pbmsg(::proto_ff::E_SoulSouladvance & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_SoulSouladvance & msg);
		static ::proto_ff::E_SoulSouladvance* new_pbmsg(){ return new ::proto_ff::E_SoulSouladvance(); }
		static ::proto_ff::E_SoulSouladvance make_pbmsg(){ return ::proto_ff::E_SoulSouladvance(); }
	};
	typedef struct E_SoulSouladvance_s E_SoulSouladvance_t;

	struct Sheet_SoulSouladvance_s : public NFDescStoreSeqOP {
		Sheet_SoulSouladvance_s();
		virtual ~Sheet_SoulSouladvance_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_SoulSouladvance_s, DEFINE_SHEET_SOULSOULADVANCE_E_SOULSOULADVANCE_LIST_MAX_NUM> E_SoulSouladvance_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_SoulSouladvance & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_SoulSouladvance & msg);
		static ::proto_ff::Sheet_SoulSouladvance* new_pbmsg(){ return new ::proto_ff::Sheet_SoulSouladvance(); }
		static ::proto_ff::Sheet_SoulSouladvance make_pbmsg(){ return ::proto_ff::Sheet_SoulSouladvance(); }
	};
	typedef struct Sheet_SoulSouladvance_s Sheet_SoulSouladvance_t;

	struct E_SoulBless_s : public NFDescStoreSeqOP {
		E_SoulBless_s();
		virtual ~E_SoulBless_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//id
		int32_t m_basic_exp;//聚灵池基础值
		int32_t m_need_gold;//元宝
		int32_t m_open_lv;//战魂等级开放升级

		virtual void write_to_pbmsg(::proto_ff::E_SoulBless & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_SoulBless & msg);
		static ::proto_ff::E_SoulBless* new_pbmsg(){ return new ::proto_ff::E_SoulBless(); }
		static ::proto_ff::E_SoulBless make_pbmsg(){ return ::proto_ff::E_SoulBless(); }
	};
	typedef struct E_SoulBless_s E_SoulBless_t;

	struct Sheet_SoulBless_s : public NFDescStoreSeqOP {
		Sheet_SoulBless_s();
		virtual ~Sheet_SoulBless_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_SoulBless_s, DEFINE_SHEET_SOULBLESS_E_SOULBLESS_LIST_MAX_NUM> E_SoulBless_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_SoulBless & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_SoulBless & msg);
		static ::proto_ff::Sheet_SoulBless* new_pbmsg(){ return new ::proto_ff::Sheet_SoulBless(); }
		static ::proto_ff::Sheet_SoulBless make_pbmsg(){ return ::proto_ff::Sheet_SoulBless(); }
	};
	typedef struct Sheet_SoulBless_s Sheet_SoulBless_t;

	struct E_SoulPrivilegeAttributeDesc_s : public NFDescStoreSeqOP {
		E_SoulPrivilegeAttributeDesc_s();
		virtual ~E_SoulPrivilegeAttributeDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_value;//值
		int32_t m_type;//ID

		virtual void write_to_pbmsg(::proto_ff::E_SoulPrivilegeAttributeDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_SoulPrivilegeAttributeDesc & msg);
		static ::proto_ff::E_SoulPrivilegeAttributeDesc* new_pbmsg(){ return new ::proto_ff::E_SoulPrivilegeAttributeDesc(); }
		static ::proto_ff::E_SoulPrivilegeAttributeDesc make_pbmsg(){ return ::proto_ff::E_SoulPrivilegeAttributeDesc(); }
	};
	typedef struct E_SoulPrivilegeAttributeDesc_s E_SoulPrivilegeAttributeDesc_t;

	struct E_SoulPrivilege_s : public NFDescStoreSeqOP {
		E_SoulPrivilege_s();
		virtual ~E_SoulPrivilege_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//id
		NFShmString<64> m_activate;//激活条件
		int32_t m_poolUp;//激活提高上限
		int32_t m_huoyuedu_to_exp;//活跃度兑换
		int32_t m_meditation_to_exp;//打坐兑换
		NFShmVector<struct E_SoulPrivilegeAttributeDesc_s, DEFINE_E_SOULPRIVILEGE_M_ATTRIBUTE_MAX_NUM> m_attribute;//基础属性

		virtual void write_to_pbmsg(::proto_ff::E_SoulPrivilege & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_SoulPrivilege & msg);
		static ::proto_ff::E_SoulPrivilege* new_pbmsg(){ return new ::proto_ff::E_SoulPrivilege(); }
		static ::proto_ff::E_SoulPrivilege make_pbmsg(){ return ::proto_ff::E_SoulPrivilege(); }
	};
	typedef struct E_SoulPrivilege_s E_SoulPrivilege_t;

	struct Sheet_SoulPrivilege_s : public NFDescStoreSeqOP {
		Sheet_SoulPrivilege_s();
		virtual ~Sheet_SoulPrivilege_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_SoulPrivilege_s, DEFINE_SHEET_SOULPRIVILEGE_E_SOULPRIVILEGE_LIST_MAX_NUM> E_SoulPrivilege_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_SoulPrivilege & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_SoulPrivilege & msg);
		static ::proto_ff::Sheet_SoulPrivilege* new_pbmsg(){ return new ::proto_ff::Sheet_SoulPrivilege(); }
		static ::proto_ff::Sheet_SoulPrivilege make_pbmsg(){ return ::proto_ff::Sheet_SoulPrivilege(); }
	};
	typedef struct Sheet_SoulPrivilege_s Sheet_SoulPrivilege_t;

	struct E_SoulCrystal_s : public NFDescStoreSeqOP {
		E_SoulCrystal_s();
		virtual ~E_SoulCrystal_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_equipId;//装备id
		NFShmString<64> m_name;//魂晶命名
		int32_t m_crystalType;//魂晶类型
		int32_t m_quality;//品质
		int32_t m_star;//星级
		int32_t m_dismantleTime;//分解获得
		int32_t m_dismantleNum;//分解数量
		int32_t m_skill;//技能类型
		int32_t m_skillLv;//技能等级
		int32_t m_handbook;//是否显示图鉴

		virtual void write_to_pbmsg(::proto_ff::E_SoulCrystal & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_SoulCrystal & msg);
		static ::proto_ff::E_SoulCrystal* new_pbmsg(){ return new ::proto_ff::E_SoulCrystal(); }
		static ::proto_ff::E_SoulCrystal make_pbmsg(){ return ::proto_ff::E_SoulCrystal(); }
	};
	typedef struct E_SoulCrystal_s E_SoulCrystal_t;

	struct Sheet_SoulCrystal_s : public NFDescStoreSeqOP {
		Sheet_SoulCrystal_s();
		virtual ~Sheet_SoulCrystal_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_SoulCrystal_s, DEFINE_SHEET_SOULCRYSTAL_E_SOULCRYSTAL_LIST_MAX_NUM> E_SoulCrystal_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_SoulCrystal & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_SoulCrystal & msg);
		static ::proto_ff::Sheet_SoulCrystal* new_pbmsg(){ return new ::proto_ff::Sheet_SoulCrystal(); }
		static ::proto_ff::Sheet_SoulCrystal make_pbmsg(){ return ::proto_ff::Sheet_SoulCrystal(); }
	};
	typedef struct Sheet_SoulCrystal_s Sheet_SoulCrystal_t;

	struct E_SoulCrystallv_s : public NFDescStoreSeqOP {
		E_SoulCrystallv_s();
		virtual ~E_SoulCrystallv_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_lv;//等级
		int32_t m_wraithsItem;//道具消耗
		int32_t m_wraithsMun;//消耗数量

		virtual void write_to_pbmsg(::proto_ff::E_SoulCrystallv & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_SoulCrystallv & msg);
		static ::proto_ff::E_SoulCrystallv* new_pbmsg(){ return new ::proto_ff::E_SoulCrystallv(); }
		static ::proto_ff::E_SoulCrystallv make_pbmsg(){ return ::proto_ff::E_SoulCrystallv(); }
	};
	typedef struct E_SoulCrystallv_s E_SoulCrystallv_t;

	struct Sheet_SoulCrystallv_s : public NFDescStoreSeqOP {
		Sheet_SoulCrystallv_s();
		virtual ~Sheet_SoulCrystallv_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_SoulCrystallv_s, DEFINE_SHEET_SOULCRYSTALLV_E_SOULCRYSTALLV_LIST_MAX_NUM> E_SoulCrystallv_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_SoulCrystallv & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_SoulCrystallv & msg);
		static ::proto_ff::Sheet_SoulCrystallv* new_pbmsg(){ return new ::proto_ff::Sheet_SoulCrystallv(); }
		static ::proto_ff::Sheet_SoulCrystallv make_pbmsg(){ return ::proto_ff::Sheet_SoulCrystallv(); }
	};
	typedef struct Sheet_SoulCrystallv_s Sheet_SoulCrystallv_t;

	struct E_SoulCrystaltopAttributeDesc_s : public NFDescStoreSeqOP {
		E_SoulCrystaltopAttributeDesc_s();
		virtual ~E_SoulCrystaltopAttributeDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_value;//值
		int32_t m_type;//ID

		virtual void write_to_pbmsg(::proto_ff::E_SoulCrystaltopAttributeDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_SoulCrystaltopAttributeDesc & msg);
		static ::proto_ff::E_SoulCrystaltopAttributeDesc* new_pbmsg(){ return new ::proto_ff::E_SoulCrystaltopAttributeDesc(); }
		static ::proto_ff::E_SoulCrystaltopAttributeDesc make_pbmsg(){ return ::proto_ff::E_SoulCrystaltopAttributeDesc(); }
	};
	typedef struct E_SoulCrystaltopAttributeDesc_s E_SoulCrystaltopAttributeDesc_t;

	struct E_SoulCrystaltop_s : public NFDescStoreSeqOP {
		E_SoulCrystaltop_s();
		virtual ~E_SoulCrystaltop_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_topLv;//突破等级
		int32_t m_wraithsItem;//道具消耗
		int32_t m_wraithsMun;//消耗数量
		NFShmVector<struct E_SoulCrystaltopAttributeDesc_s, DEFINE_E_SOULCRYSTALTOP_M_ATTRIBUTE_MAX_NUM> m_attribute;//属性

		virtual void write_to_pbmsg(::proto_ff::E_SoulCrystaltop & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_SoulCrystaltop & msg);
		static ::proto_ff::E_SoulCrystaltop* new_pbmsg(){ return new ::proto_ff::E_SoulCrystaltop(); }
		static ::proto_ff::E_SoulCrystaltop make_pbmsg(){ return ::proto_ff::E_SoulCrystaltop(); }
	};
	typedef struct E_SoulCrystaltop_s E_SoulCrystaltop_t;

	struct Sheet_SoulCrystaltop_s : public NFDescStoreSeqOP {
		Sheet_SoulCrystaltop_s();
		virtual ~Sheet_SoulCrystaltop_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_SoulCrystaltop_s, DEFINE_SHEET_SOULCRYSTALTOP_E_SOULCRYSTALTOP_LIST_MAX_NUM> E_SoulCrystaltop_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_SoulCrystaltop & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_SoulCrystaltop & msg);
		static ::proto_ff::Sheet_SoulCrystaltop* new_pbmsg(){ return new ::proto_ff::Sheet_SoulCrystaltop(); }
		static ::proto_ff::Sheet_SoulCrystaltop make_pbmsg(){ return ::proto_ff::Sheet_SoulCrystaltop(); }
	};
	typedef struct Sheet_SoulCrystaltop_s Sheet_SoulCrystaltop_t;

	struct E_SoulCrystalhole_s : public NFDescStoreSeqOP {
		E_SoulCrystalhole_s();
		virtual ~E_SoulCrystalhole_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//魂晶孔位
		NFShmString<64> m_unlock;//解锁条件

		virtual void write_to_pbmsg(::proto_ff::E_SoulCrystalhole & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_SoulCrystalhole & msg);
		static ::proto_ff::E_SoulCrystalhole* new_pbmsg(){ return new ::proto_ff::E_SoulCrystalhole(); }
		static ::proto_ff::E_SoulCrystalhole make_pbmsg(){ return ::proto_ff::E_SoulCrystalhole(); }
	};
	typedef struct E_SoulCrystalhole_s E_SoulCrystalhole_t;

	struct Sheet_SoulCrystalhole_s : public NFDescStoreSeqOP {
		Sheet_SoulCrystalhole_s();
		virtual ~Sheet_SoulCrystalhole_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_SoulCrystalhole_s, DEFINE_SHEET_SOULCRYSTALHOLE_E_SOULCRYSTALHOLE_LIST_MAX_NUM> E_SoulCrystalhole_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_SoulCrystalhole & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_SoulCrystalhole & msg);
		static ::proto_ff::Sheet_SoulCrystalhole* new_pbmsg(){ return new ::proto_ff::Sheet_SoulCrystalhole(); }
		static ::proto_ff::Sheet_SoulCrystalhole make_pbmsg(){ return ::proto_ff::Sheet_SoulCrystalhole(); }
	};
	typedef struct Sheet_SoulCrystalhole_s Sheet_SoulCrystalhole_t;

	struct E_SoulFusionFusionDesc_s : public NFDescStoreSeqOP {
		E_SoulFusionFusionDesc_s();
		virtual ~E_SoulFusionFusionDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_star;//星级
		int32_t m_quality;//品质

		virtual void write_to_pbmsg(::proto_ff::E_SoulFusionFusionDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_SoulFusionFusionDesc & msg);
		static ::proto_ff::E_SoulFusionFusionDesc* new_pbmsg(){ return new ::proto_ff::E_SoulFusionFusionDesc(); }
		static ::proto_ff::E_SoulFusionFusionDesc make_pbmsg(){ return ::proto_ff::E_SoulFusionFusionDesc(); }
	};
	typedef struct E_SoulFusionFusionDesc_s E_SoulFusionFusionDesc_t;

	struct E_SoulFusion_s : public NFDescStoreSeqOP {
		E_SoulFusion_s();
		virtual ~E_SoulFusion_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//id
		int32_t m_fusionType;//融合类型
		int32_t m_quality;//魂晶品质
		int32_t m_star;//魂晶星数
		int32_t m_condition;//是否需要自身材料
		int32_t m_qualityGet;//融合后品质
		int32_t m_starGet;//融合后星级
		int32_t m_attributeBer;//属性提升
		NFShmVector<struct E_SoulFusionFusionDesc_s, DEFINE_E_SOULFUSION_M_FUSION_MAX_NUM> m_fusion;//融合材料

		virtual void write_to_pbmsg(::proto_ff::E_SoulFusion & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_SoulFusion & msg);
		static ::proto_ff::E_SoulFusion* new_pbmsg(){ return new ::proto_ff::E_SoulFusion(); }
		static ::proto_ff::E_SoulFusion make_pbmsg(){ return ::proto_ff::E_SoulFusion(); }
	};
	typedef struct E_SoulFusion_s E_SoulFusion_t;

	struct Sheet_SoulFusion_s : public NFDescStoreSeqOP {
		Sheet_SoulFusion_s();
		virtual ~Sheet_SoulFusion_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_SoulFusion_s, DEFINE_SHEET_SOULFUSION_E_SOULFUSION_LIST_MAX_NUM> E_SoulFusion_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_SoulFusion & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_SoulFusion & msg);
		static ::proto_ff::Sheet_SoulFusion* new_pbmsg(){ return new ::proto_ff::Sheet_SoulFusion(); }
		static ::proto_ff::Sheet_SoulFusion make_pbmsg(){ return ::proto_ff::Sheet_SoulFusion(); }
	};
	typedef struct Sheet_SoulFusion_s Sheet_SoulFusion_t;

	struct E_SoulBone_s : public NFDescStoreSeqOP {
		E_SoulBone_s();
		virtual ~E_SoulBone_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//id
		int32_t m_position;//装备位置
		int32_t m_type;//魂骨类型
		int32_t m_awakening;//觉醒类型
		int32_t m_awakeningTime;//觉醒消耗
		int32_t m_awakeningNum;//消耗数量
		int32_t m_modelId;//模型id

		virtual void write_to_pbmsg(::proto_ff::E_SoulBone & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_SoulBone & msg);
		static ::proto_ff::E_SoulBone* new_pbmsg(){ return new ::proto_ff::E_SoulBone(); }
		static ::proto_ff::E_SoulBone make_pbmsg(){ return ::proto_ff::E_SoulBone(); }
	};
	typedef struct E_SoulBone_s E_SoulBone_t;

	struct Sheet_SoulBone_s : public NFDescStoreSeqOP {
		Sheet_SoulBone_s();
		virtual ~Sheet_SoulBone_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_SoulBone_s, DEFINE_SHEET_SOULBONE_E_SOULBONE_LIST_MAX_NUM> E_SoulBone_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_SoulBone & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_SoulBone & msg);
		static ::proto_ff::Sheet_SoulBone* new_pbmsg(){ return new ::proto_ff::Sheet_SoulBone(); }
		static ::proto_ff::Sheet_SoulBone make_pbmsg(){ return ::proto_ff::Sheet_SoulBone(); }
	};
	typedef struct Sheet_SoulBone_s Sheet_SoulBone_t;

	struct E_SoulBoneskill_s : public NFDescStoreSeqOP {
		E_SoulBoneskill_s();
		virtual ~E_SoulBoneskill_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//id
		int32_t m_boneId;//魂骨部位id
		int32_t m_quality;//品质
		int32_t m_star;//星级
		int32_t m_ActiveSkill;//主动技能
		int32_t m_ActiveSkillLv;//技能等级
		NFShmVector<int32_t, DEFINE_E_SOULBONESKILL_M_PASSIVE_SKILL_MAX_NUM> m_passive_Skill;//被动技能

		virtual void write_to_pbmsg(::proto_ff::E_SoulBoneskill & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_SoulBoneskill & msg);
		static ::proto_ff::E_SoulBoneskill* new_pbmsg(){ return new ::proto_ff::E_SoulBoneskill(); }
		static ::proto_ff::E_SoulBoneskill make_pbmsg(){ return ::proto_ff::E_SoulBoneskill(); }
	};
	typedef struct E_SoulBoneskill_s E_SoulBoneskill_t;

	struct Sheet_SoulBoneskill_s : public NFDescStoreSeqOP {
		Sheet_SoulBoneskill_s();
		virtual ~Sheet_SoulBoneskill_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_SoulBoneskill_s, DEFINE_SHEET_SOULBONESKILL_E_SOULBONESKILL_LIST_MAX_NUM> E_SoulBoneskill_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_SoulBoneskill & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_SoulBoneskill & msg);
		static ::proto_ff::Sheet_SoulBoneskill* new_pbmsg(){ return new ::proto_ff::Sheet_SoulBoneskill(); }
		static ::proto_ff::Sheet_SoulBoneskill make_pbmsg(){ return ::proto_ff::Sheet_SoulBoneskill(); }
	};
	typedef struct Sheet_SoulBoneskill_s Sheet_SoulBoneskill_t;

	struct E_SoulBonekill_s : public NFDescStoreSeqOP {
		E_SoulBonekill_s();
		virtual ~E_SoulBonekill_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_lv;//等级
		int32_t m_killBoss;//击杀魔王数

		virtual void write_to_pbmsg(::proto_ff::E_SoulBonekill & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_SoulBonekill & msg);
		static ::proto_ff::E_SoulBonekill* new_pbmsg(){ return new ::proto_ff::E_SoulBonekill(); }
		static ::proto_ff::E_SoulBonekill make_pbmsg(){ return ::proto_ff::E_SoulBonekill(); }
	};
	typedef struct E_SoulBonekill_s E_SoulBonekill_t;

	struct Sheet_SoulBonekill_s : public NFDescStoreSeqOP {
		Sheet_SoulBonekill_s();
		virtual ~Sheet_SoulBonekill_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_SoulBonekill_s, DEFINE_SHEET_SOULBONEKILL_E_SOULBONEKILL_LIST_MAX_NUM> E_SoulBonekill_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_SoulBonekill & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_SoulBonekill & msg);
		static ::proto_ff::Sheet_SoulBonekill* new_pbmsg(){ return new ::proto_ff::Sheet_SoulBonekill(); }
		static ::proto_ff::Sheet_SoulBonekill make_pbmsg(){ return ::proto_ff::Sheet_SoulBonekill(); }
	};
	typedef struct Sheet_SoulBonekill_s Sheet_SoulBonekill_t;

	struct E_SoulBonestrongTypeDesc_s : public NFDescStoreSeqOP {
		E_SoulBonestrongTypeDesc_s();
		virtual ~E_SoulBonestrongTypeDesc_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmString<64> m_num;//值
		int32_t m_id;//ID

		virtual void write_to_pbmsg(::proto_ff::E_SoulBonestrongTypeDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_SoulBonestrongTypeDesc & msg);
		static ::proto_ff::E_SoulBonestrongTypeDesc* new_pbmsg(){ return new ::proto_ff::E_SoulBonestrongTypeDesc(); }
		static ::proto_ff::E_SoulBonestrongTypeDesc make_pbmsg(){ return ::proto_ff::E_SoulBonestrongTypeDesc(); }
	};
	typedef struct E_SoulBonestrongTypeDesc_s E_SoulBonestrongTypeDesc_t;

	struct E_SoulBonestrong_s : public NFDescStoreSeqOP {
		E_SoulBonestrong_s();
		virtual ~E_SoulBonestrong_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//id
		int32_t m_position;//装备部位
		int32_t m_srtongUp;//强化上限
		NFShmVector<struct E_SoulBonestrongTypeDesc_s, DEFINE_E_SOULBONESTRONG_M_TYPE_MAX_NUM> m_type;//属性

		virtual void write_to_pbmsg(::proto_ff::E_SoulBonestrong & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_SoulBonestrong & msg);
		static ::proto_ff::E_SoulBonestrong* new_pbmsg(){ return new ::proto_ff::E_SoulBonestrong(); }
		static ::proto_ff::E_SoulBonestrong make_pbmsg(){ return ::proto_ff::E_SoulBonestrong(); }
	};
	typedef struct E_SoulBonestrong_s E_SoulBonestrong_t;

	struct Sheet_SoulBonestrong_s : public NFDescStoreSeqOP {
		Sheet_SoulBonestrong_s();
		virtual ~Sheet_SoulBonestrong_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_SoulBonestrong_s, DEFINE_SHEET_SOULBONESTRONG_E_SOULBONESTRONG_LIST_MAX_NUM> E_SoulBonestrong_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_SoulBonestrong & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_SoulBonestrong & msg);
		static ::proto_ff::Sheet_SoulBonestrong* new_pbmsg(){ return new ::proto_ff::Sheet_SoulBonestrong(); }
		static ::proto_ff::Sheet_SoulBonestrong make_pbmsg(){ return ::proto_ff::Sheet_SoulBonestrong(); }
	};
	typedef struct Sheet_SoulBonestrong_s Sheet_SoulBonestrong_t;

	struct E_SoulGuwentype_s : public NFDescStoreSeqOP {
		E_SoulGuwentype_s();
		virtual ~E_SoulGuwentype_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//类型id
		NFShmString<64> m_name;//名字
		int32_t m_quality;//镶嵌骨纹品质

		virtual void write_to_pbmsg(::proto_ff::E_SoulGuwentype & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_SoulGuwentype & msg);
		static ::proto_ff::E_SoulGuwentype* new_pbmsg(){ return new ::proto_ff::E_SoulGuwentype(); }
		static ::proto_ff::E_SoulGuwentype make_pbmsg(){ return ::proto_ff::E_SoulGuwentype(); }
	};
	typedef struct E_SoulGuwentype_s E_SoulGuwentype_t;

	struct Sheet_SoulGuwentype_s : public NFDescStoreSeqOP {
		Sheet_SoulGuwentype_s();
		virtual ~Sheet_SoulGuwentype_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_SoulGuwentype_s, DEFINE_SHEET_SOULGUWENTYPE_E_SOULGUWENTYPE_LIST_MAX_NUM> E_SoulGuwentype_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_SoulGuwentype & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_SoulGuwentype & msg);
		static ::proto_ff::Sheet_SoulGuwentype* new_pbmsg(){ return new ::proto_ff::Sheet_SoulGuwentype(); }
		static ::proto_ff::Sheet_SoulGuwentype make_pbmsg(){ return ::proto_ff::Sheet_SoulGuwentype(); }
	};
	typedef struct Sheet_SoulGuwentype_s Sheet_SoulGuwentype_t;

	struct E_SoulGuwentypesuitAttributeDesc_s : public NFDescStoreSeqOP {
		E_SoulGuwentypesuitAttributeDesc_s();
		virtual ~E_SoulGuwentypesuitAttributeDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_value;//值
		int32_t m_type;//ID

		virtual void write_to_pbmsg(::proto_ff::E_SoulGuwentypesuitAttributeDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_SoulGuwentypesuitAttributeDesc & msg);
		static ::proto_ff::E_SoulGuwentypesuitAttributeDesc* new_pbmsg(){ return new ::proto_ff::E_SoulGuwentypesuitAttributeDesc(); }
		static ::proto_ff::E_SoulGuwentypesuitAttributeDesc make_pbmsg(){ return ::proto_ff::E_SoulGuwentypesuitAttributeDesc(); }
	};
	typedef struct E_SoulGuwentypesuitAttributeDesc_s E_SoulGuwentypesuitAttributeDesc_t;

	struct E_SoulGuwentypesuit_s : public NFDescStoreSeqOP {
		E_SoulGuwentypesuit_s();
		virtual ~E_SoulGuwentypesuit_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//id
		int32_t m_typeId;//类型id
		int32_t m_num;//件数
		NFShmVector<struct E_SoulGuwentypesuitAttributeDesc_s, DEFINE_E_SOULGUWENTYPESUIT_M_ATTRIBUTE_MAX_NUM> m_attribute;//基础属性

		virtual void write_to_pbmsg(::proto_ff::E_SoulGuwentypesuit & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_SoulGuwentypesuit & msg);
		static ::proto_ff::E_SoulGuwentypesuit* new_pbmsg(){ return new ::proto_ff::E_SoulGuwentypesuit(); }
		static ::proto_ff::E_SoulGuwentypesuit make_pbmsg(){ return ::proto_ff::E_SoulGuwentypesuit(); }
	};
	typedef struct E_SoulGuwentypesuit_s E_SoulGuwentypesuit_t;

	struct Sheet_SoulGuwentypesuit_s : public NFDescStoreSeqOP {
		Sheet_SoulGuwentypesuit_s();
		virtual ~Sheet_SoulGuwentypesuit_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_SoulGuwentypesuit_s, DEFINE_SHEET_SOULGUWENTYPESUIT_E_SOULGUWENTYPESUIT_LIST_MAX_NUM> E_SoulGuwentypesuit_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_SoulGuwentypesuit & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_SoulGuwentypesuit & msg);
		static ::proto_ff::Sheet_SoulGuwentypesuit* new_pbmsg(){ return new ::proto_ff::Sheet_SoulGuwentypesuit(); }
		static ::proto_ff::Sheet_SoulGuwentypesuit make_pbmsg(){ return ::proto_ff::Sheet_SoulGuwentypesuit(); }
	};
	typedef struct Sheet_SoulGuwentypesuit_s Sheet_SoulGuwentypesuit_t;

	struct E_SoulGuwenskill_s : public NFDescStoreSeqOP {
		E_SoulGuwenskill_s();
		virtual ~E_SoulGuwenskill_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//id
		int32_t m_type;//技能类型(1专属2被动)
		int32_t m_skillId;//技能Id
		int32_t m_quality;//解锁需要骨纹的品质
		NFShmVector<int32_t, DEFINE_E_SOULGUWENSKILL_M_SKILLLEVEL_MAX_NUM> m_skillLevel;//技能等级
		NFShmVector<int32_t, DEFINE_E_SOULGUWENSKILL_M_NUM_MAX_NUM> m_num;//升级条件

		virtual void write_to_pbmsg(::proto_ff::E_SoulGuwenskill & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_SoulGuwenskill & msg);
		static ::proto_ff::E_SoulGuwenskill* new_pbmsg(){ return new ::proto_ff::E_SoulGuwenskill(); }
		static ::proto_ff::E_SoulGuwenskill make_pbmsg(){ return ::proto_ff::E_SoulGuwenskill(); }
	};
	typedef struct E_SoulGuwenskill_s E_SoulGuwenskill_t;

	struct Sheet_SoulGuwenskill_s : public NFDescStoreSeqOP {
		Sheet_SoulGuwenskill_s();
		virtual ~Sheet_SoulGuwenskill_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_SoulGuwenskill_s, DEFINE_SHEET_SOULGUWENSKILL_E_SOULGUWENSKILL_LIST_MAX_NUM> E_SoulGuwenskill_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_SoulGuwenskill & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_SoulGuwenskill & msg);
		static ::proto_ff::Sheet_SoulGuwenskill* new_pbmsg(){ return new ::proto_ff::Sheet_SoulGuwenskill(); }
		static ::proto_ff::Sheet_SoulGuwenskill make_pbmsg(){ return ::proto_ff::Sheet_SoulGuwenskill(); }
	};
	typedef struct Sheet_SoulGuwenskill_s Sheet_SoulGuwenskill_t;

	struct E_SoulGuwenslot_s : public NFDescStoreSeqOP {
		E_SoulGuwenslot_s();
		virtual ~E_SoulGuwenslot_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//id
		NFShmString<64> m_name;//名字
		int32_t m_position;//装备位置

		virtual void write_to_pbmsg(::proto_ff::E_SoulGuwenslot & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_SoulGuwenslot & msg);
		static ::proto_ff::E_SoulGuwenslot* new_pbmsg(){ return new ::proto_ff::E_SoulGuwenslot(); }
		static ::proto_ff::E_SoulGuwenslot make_pbmsg(){ return ::proto_ff::E_SoulGuwenslot(); }
	};
	typedef struct E_SoulGuwenslot_s E_SoulGuwenslot_t;

	struct Sheet_SoulGuwenslot_s : public NFDescStoreSeqOP {
		Sheet_SoulGuwenslot_s();
		virtual ~Sheet_SoulGuwenslot_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_SoulGuwenslot_s, DEFINE_SHEET_SOULGUWENSLOT_E_SOULGUWENSLOT_LIST_MAX_NUM> E_SoulGuwenslot_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_SoulGuwenslot & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_SoulGuwenslot & msg);
		static ::proto_ff::Sheet_SoulGuwenslot* new_pbmsg(){ return new ::proto_ff::Sheet_SoulGuwenslot(); }
		static ::proto_ff::Sheet_SoulGuwenslot make_pbmsg(){ return ::proto_ff::Sheet_SoulGuwenslot(); }
	};
	typedef struct Sheet_SoulGuwenslot_s Sheet_SoulGuwenslot_t;

	struct E_SoulGuwensuitAttributeDesc_s : public NFDescStoreSeqOP {
		E_SoulGuwensuitAttributeDesc_s();
		virtual ~E_SoulGuwensuitAttributeDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_value;//值
		int32_t m_type;//ID

		virtual void write_to_pbmsg(::proto_ff::E_SoulGuwensuitAttributeDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_SoulGuwensuitAttributeDesc & msg);
		static ::proto_ff::E_SoulGuwensuitAttributeDesc* new_pbmsg(){ return new ::proto_ff::E_SoulGuwensuitAttributeDesc(); }
		static ::proto_ff::E_SoulGuwensuitAttributeDesc make_pbmsg(){ return ::proto_ff::E_SoulGuwensuitAttributeDesc(); }
	};
	typedef struct E_SoulGuwensuitAttributeDesc_s E_SoulGuwensuitAttributeDesc_t;

	struct E_SoulGuwensuit_s : public NFDescStoreSeqOP {
		E_SoulGuwensuit_s();
		virtual ~E_SoulGuwensuit_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//id
		int32_t m_boneId;//魂骨id
		int32_t m_typeId;//类型id
		int32_t m_num;//件数
		NFShmVector<struct E_SoulGuwensuitAttributeDesc_s, DEFINE_E_SOULGUWENSUIT_M_ATTRIBUTE_MAX_NUM> m_attribute;//基础属性

		virtual void write_to_pbmsg(::proto_ff::E_SoulGuwensuit & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_SoulGuwensuit & msg);
		static ::proto_ff::E_SoulGuwensuit* new_pbmsg(){ return new ::proto_ff::E_SoulGuwensuit(); }
		static ::proto_ff::E_SoulGuwensuit make_pbmsg(){ return ::proto_ff::E_SoulGuwensuit(); }
	};
	typedef struct E_SoulGuwensuit_s E_SoulGuwensuit_t;

	struct Sheet_SoulGuwensuit_s : public NFDescStoreSeqOP {
		Sheet_SoulGuwensuit_s();
		virtual ~Sheet_SoulGuwensuit_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_SoulGuwensuit_s, DEFINE_SHEET_SOULGUWENSUIT_E_SOULGUWENSUIT_LIST_MAX_NUM> E_SoulGuwensuit_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_SoulGuwensuit & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_SoulGuwensuit & msg);
		static ::proto_ff::Sheet_SoulGuwensuit* new_pbmsg(){ return new ::proto_ff::Sheet_SoulGuwensuit(); }
		static ::proto_ff::Sheet_SoulGuwensuit make_pbmsg(){ return ::proto_ff::Sheet_SoulGuwensuit(); }
	};
	typedef struct Sheet_SoulGuwensuit_s Sheet_SoulGuwensuit_t;

	struct E_SoulGuwenupstar_s : public NFDescStoreSeqOP {
		E_SoulGuwenupstar_s();
		virtual ~E_SoulGuwenupstar_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//id
		int32_t m_quality;//当前品质
		int32_t m_star;//当前星数
		int32_t m_targetQuality;//目标品质
		int32_t m_targetStar;//目标星数
		int32_t m_samePosNum;//融合需要相同孔位的数量
		int32_t m_samePosQuality;//融合需要相同孔位的品质
		int32_t m_samePosStar;//融合需要相同孔位的星级

		virtual void write_to_pbmsg(::proto_ff::E_SoulGuwenupstar & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_SoulGuwenupstar & msg);
		static ::proto_ff::E_SoulGuwenupstar* new_pbmsg(){ return new ::proto_ff::E_SoulGuwenupstar(); }
		static ::proto_ff::E_SoulGuwenupstar make_pbmsg(){ return ::proto_ff::E_SoulGuwenupstar(); }
	};
	typedef struct E_SoulGuwenupstar_s E_SoulGuwenupstar_t;

	struct Sheet_SoulGuwenupstar_s : public NFDescStoreSeqOP {
		Sheet_SoulGuwenupstar_s();
		virtual ~Sheet_SoulGuwenupstar_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_SoulGuwenupstar_s, DEFINE_SHEET_SOULGUWENUPSTAR_E_SOULGUWENUPSTAR_LIST_MAX_NUM> E_SoulGuwenupstar_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_SoulGuwenupstar & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_SoulGuwenupstar & msg);
		static ::proto_ff::Sheet_SoulGuwenupstar* new_pbmsg(){ return new ::proto_ff::Sheet_SoulGuwenupstar(); }
		static ::proto_ff::Sheet_SoulGuwenupstar make_pbmsg(){ return ::proto_ff::Sheet_SoulGuwenupstar(); }
	};
	typedef struct Sheet_SoulGuwenupstar_s Sheet_SoulGuwenupstar_t;

	struct E_SoulAffixesAttributeDesc_s : public NFDescStoreSeqOP {
		E_SoulAffixesAttributeDesc_s();
		virtual ~E_SoulAffixesAttributeDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_value;//值
		int32_t m_type;//ID

		virtual void write_to_pbmsg(::proto_ff::E_SoulAffixesAttributeDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_SoulAffixesAttributeDesc & msg);
		static ::proto_ff::E_SoulAffixesAttributeDesc* new_pbmsg(){ return new ::proto_ff::E_SoulAffixesAttributeDesc(); }
		static ::proto_ff::E_SoulAffixesAttributeDesc make_pbmsg(){ return ::proto_ff::E_SoulAffixesAttributeDesc(); }
	};
	typedef struct E_SoulAffixesAttributeDesc_s E_SoulAffixesAttributeDesc_t;

	struct E_SoulAffixes_s : public NFDescStoreSeqOP {
		E_SoulAffixes_s();
		virtual ~E_SoulAffixes_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//id
		int32_t m_type;//类型(1攻2防3全)
		int32_t m_quality;//品质
		NFShmString<64> m_name;//名字
		NFShmVector<struct E_SoulAffixesAttributeDesc_s, DEFINE_E_SOULAFFIXES_M_ATTRIBUTE_MAX_NUM> m_attribute;//基础属性

		virtual void write_to_pbmsg(::proto_ff::E_SoulAffixes & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_SoulAffixes & msg);
		static ::proto_ff::E_SoulAffixes* new_pbmsg(){ return new ::proto_ff::E_SoulAffixes(); }
		static ::proto_ff::E_SoulAffixes make_pbmsg(){ return ::proto_ff::E_SoulAffixes(); }
	};
	typedef struct E_SoulAffixes_s E_SoulAffixes_t;

	struct Sheet_SoulAffixes_s : public NFDescStoreSeqOP {
		Sheet_SoulAffixes_s();
		virtual ~Sheet_SoulAffixes_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_SoulAffixes_s, DEFINE_SHEET_SOULAFFIXES_E_SOULAFFIXES_LIST_MAX_NUM> E_SoulAffixes_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_SoulAffixes & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_SoulAffixes & msg);
		static ::proto_ff::Sheet_SoulAffixes* new_pbmsg(){ return new ::proto_ff::Sheet_SoulAffixes(); }
		static ::proto_ff::Sheet_SoulAffixes make_pbmsg(){ return ::proto_ff::Sheet_SoulAffixes(); }
	};
	typedef struct Sheet_SoulAffixes_s Sheet_SoulAffixes_t;

	struct E_SoulAffixessuitSkillDesc_s : public NFDescStoreSeqOP {
		E_SoulAffixessuitSkillDesc_s();
		virtual ~E_SoulAffixessuitSkillDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_level;//等级
		int32_t m_id;//ID

		virtual void write_to_pbmsg(::proto_ff::E_SoulAffixessuitSkillDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_SoulAffixessuitSkillDesc & msg);
		static ::proto_ff::E_SoulAffixessuitSkillDesc* new_pbmsg(){ return new ::proto_ff::E_SoulAffixessuitSkillDesc(); }
		static ::proto_ff::E_SoulAffixessuitSkillDesc make_pbmsg(){ return ::proto_ff::E_SoulAffixessuitSkillDesc(); }
	};
	typedef struct E_SoulAffixessuitSkillDesc_s E_SoulAffixessuitSkillDesc_t;

	struct E_SoulAffixessuitAttributeDesc_s : public NFDescStoreSeqOP {
		E_SoulAffixessuitAttributeDesc_s();
		virtual ~E_SoulAffixessuitAttributeDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_value;//值
		int32_t m_type;//ID

		virtual void write_to_pbmsg(::proto_ff::E_SoulAffixessuitAttributeDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_SoulAffixessuitAttributeDesc & msg);
		static ::proto_ff::E_SoulAffixessuitAttributeDesc* new_pbmsg(){ return new ::proto_ff::E_SoulAffixessuitAttributeDesc(); }
		static ::proto_ff::E_SoulAffixessuitAttributeDesc make_pbmsg(){ return ::proto_ff::E_SoulAffixessuitAttributeDesc(); }
	};
	typedef struct E_SoulAffixessuitAttributeDesc_s E_SoulAffixessuitAttributeDesc_t;

	struct E_SoulAffixessuit_s : public NFDescStoreSeqOP {
		E_SoulAffixessuit_s();
		virtual ~E_SoulAffixessuit_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//id
		int32_t m_affixesId;//id
		int32_t m_num;//件数
		NFShmVector<struct E_SoulAffixessuitSkillDesc_s, DEFINE_E_SOULAFFIXESSUIT_M_SKILL_MAX_NUM> m_skill;//技能
		NFShmVector<struct E_SoulAffixessuitAttributeDesc_s, DEFINE_E_SOULAFFIXESSUIT_M_ATTRIBUTE_MAX_NUM> m_attribute;//基础属性

		virtual void write_to_pbmsg(::proto_ff::E_SoulAffixessuit & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_SoulAffixessuit & msg);
		static ::proto_ff::E_SoulAffixessuit* new_pbmsg(){ return new ::proto_ff::E_SoulAffixessuit(); }
		static ::proto_ff::E_SoulAffixessuit make_pbmsg(){ return ::proto_ff::E_SoulAffixessuit(); }
	};
	typedef struct E_SoulAffixessuit_s E_SoulAffixessuit_t;

	struct Sheet_SoulAffixessuit_s : public NFDescStoreSeqOP {
		Sheet_SoulAffixessuit_s();
		virtual ~Sheet_SoulAffixessuit_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_SoulAffixessuit_s, DEFINE_SHEET_SOULAFFIXESSUIT_E_SOULAFFIXESSUIT_LIST_MAX_NUM> E_SoulAffixessuit_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_SoulAffixessuit & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_SoulAffixessuit & msg);
		static ::proto_ff::Sheet_SoulAffixessuit* new_pbmsg(){ return new ::proto_ff::Sheet_SoulAffixessuit(); }
		static ::proto_ff::Sheet_SoulAffixessuit make_pbmsg(){ return ::proto_ff::Sheet_SoulAffixessuit(); }
	};
	typedef struct Sheet_SoulAffixessuit_s Sheet_SoulAffixessuit_t;

}

