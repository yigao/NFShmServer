#pragma once

#include <stdint.h>
#include <NFComm/NFShmStl/NFShmString.h>
#include <NFComm/NFShmStl/NFShmVector.h>
#include <NFComm/NFShmCore/NFSeqOP.h>
#include <NFComm/NFShmCore/NFShmMgr.h>
#include "E_Avatar.pb.h"
#include "E_Avatar_s.h"

#define DEFINE_E_AVATARFRAGMENT_M_ATTRIBUTE_MAX_NUM 5
#define DEFINE_SHEET_AVATARFRAGMENT_E_AVATARFRAGMENT_LIST_MAX_NUM 16
#define DEFINE_E_AVATARVALUE_M_ATTRIBUTE_MAX_NUM 13
#define DEFINE_SHEET_AVATARVALUE_E_AVATARVALUE_LIST_MAX_NUM 4096
#define DEFINE_E_AVATARDISPLAY_M_MATERIAL_MAX_NUM 3
#define DEFINE_E_AVATARDISPLAY_M_FRAGMENTID_MAX_NUM 3
#define DEFINE_SHEET_AVATARDISPLAY_E_AVATARDISPLAY_LIST_MAX_NUM 2
#define DEFINE_E_AVATARCHANGE_M_MATERIAL_MAX_NUM 3
#define DEFINE_E_AVATARCHANGE_M_INITIATIVESKILL_MAX_NUM 7
#define DEFINE_E_AVATARCHANGE_M_ATTRIBUTE_MAX_NUM 4
#define DEFINE_SHEET_AVATARCHANGE_E_AVATARCHANGE_LIST_MAX_NUM 32
#define DEFINE_SHEET_AVATARCHANGETAB_E_AVATARCHANGETAB_LIST_MAX_NUM 16
#define DEFINE_SHEET_AVATARBATTLESLOT_E_AVATARBATTLESLOT_LIST_MAX_NUM 8
#define DEFINE_E_AVATARADVANCE_M_UPATTRIBUTE_MAX_NUM 5
#define DEFINE_SHEET_AVATARADVANCE_E_AVATARADVANCE_LIST_MAX_NUM 64
#define DEFINE_SHEET_AVATARSKILL_E_AVATARSKILL_LIST_MAX_NUM 16
#define DEFINE_E_AVATAREQUIPSUIT_M_ATTRIBUTE_MAX_NUM 3
#define DEFINE_SHEET_AVATAREQUIPSUIT_E_AVATAREQUIPSUIT_LIST_MAX_NUM 16
#define DEFINE_E_AVATARMYTH_M_ATTRIBUTE_MAX_NUM 6
#define DEFINE_SHEET_AVATARMYTH_E_AVATARMYTH_LIST_MAX_NUM 4
#define DEFINE_E_AVATARMYTHWAY_M_EQUIPID_MAX_NUM 5
#define DEFINE_E_AVATARMYTHWAY_M_SPECIALID_MAX_NUM 3
#define DEFINE_E_AVATARMYTHWAY_M_ATTRIBUTE_MAX_NUM 8
#define DEFINE_SHEET_AVATARMYTHWAY_E_AVATARMYTHWAY_LIST_MAX_NUM 64
#define DEFINE_E_AVATARMYTHCORE_M_ATTRIBUTE_MAX_NUM 4
#define DEFINE_SHEET_AVATARMYTHCORE_E_AVATARMYTHCORE_LIST_MAX_NUM 64
#define DEFINE_E_AVATARMYTHEQUIP_M_ATTRIBUTE_MAX_NUM 8
#define DEFINE_SHEET_AVATARMYTHEQUIP_E_AVATARMYTHEQUIP_LIST_MAX_NUM 64


namespace proto_ff_s {

	struct E_AvatarFragmentAttributeDesc_s : public NFDescStoreSeqOP {
		E_AvatarFragmentAttributeDesc_s();
		virtual ~E_AvatarFragmentAttributeDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_value;//值
		int32_t m_type;//ID

		virtual void write_to_pbmsg(::proto_ff::E_AvatarFragmentAttributeDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_AvatarFragmentAttributeDesc & msg);
		static ::proto_ff::E_AvatarFragmentAttributeDesc* new_pbmsg(){ return new ::proto_ff::E_AvatarFragmentAttributeDesc(); }
		static ::proto_ff::E_AvatarFragmentAttributeDesc make_pbmsg(){ return ::proto_ff::E_AvatarFragmentAttributeDesc(); }
	};
	typedef struct E_AvatarFragmentAttributeDesc_s E_AvatarFragmentAttributeDesc_t;

	struct E_AvatarFragment_s : public NFDescStoreSeqOP {
		E_AvatarFragment_s();
		virtual ~E_AvatarFragment_s(){}
		int CreateInit();
		int ResumeInit();
		int64_t m_fragmentID;//碎片ID
		int64_t m_item;//物品ID
		int32_t m_itemNum;//碎片使用上限
		NFShmVector<struct E_AvatarFragmentAttributeDesc_s, DEFINE_E_AVATARFRAGMENT_M_ATTRIBUTE_MAX_NUM> m_attribute;//基础属性

		virtual void write_to_pbmsg(::proto_ff::E_AvatarFragment & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_AvatarFragment & msg);
		static ::proto_ff::E_AvatarFragment* new_pbmsg(){ return new ::proto_ff::E_AvatarFragment(); }
		static ::proto_ff::E_AvatarFragment make_pbmsg(){ return ::proto_ff::E_AvatarFragment(); }
	};
	typedef struct E_AvatarFragment_s E_AvatarFragment_t;

	struct Sheet_AvatarFragment_s : public NFDescStoreSeqOP {
		Sheet_AvatarFragment_s();
		virtual ~Sheet_AvatarFragment_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_AvatarFragment_s, DEFINE_SHEET_AVATARFRAGMENT_E_AVATARFRAGMENT_LIST_MAX_NUM> E_AvatarFragment_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_AvatarFragment & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_AvatarFragment & msg);
		static ::proto_ff::Sheet_AvatarFragment* new_pbmsg(){ return new ::proto_ff::Sheet_AvatarFragment(); }
		static ::proto_ff::Sheet_AvatarFragment make_pbmsg(){ return ::proto_ff::Sheet_AvatarFragment(); }
	};
	typedef struct Sheet_AvatarFragment_s Sheet_AvatarFragment_t;

	struct E_AvatarValueAttributeDesc_s : public NFDescStoreSeqOP {
		E_AvatarValueAttributeDesc_s();
		virtual ~E_AvatarValueAttributeDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_value;//值
		int32_t m_type;//

		virtual void write_to_pbmsg(::proto_ff::E_AvatarValueAttributeDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_AvatarValueAttributeDesc & msg);
		static ::proto_ff::E_AvatarValueAttributeDesc* new_pbmsg(){ return new ::proto_ff::E_AvatarValueAttributeDesc(); }
		static ::proto_ff::E_AvatarValueAttributeDesc make_pbmsg(){ return ::proto_ff::E_AvatarValueAttributeDesc(); }
	};
	typedef struct E_AvatarValueAttributeDesc_s E_AvatarValueAttributeDesc_t;

	struct E_AvatarValue_s : public NFDescStoreSeqOP {
		E_AvatarValue_s();
		virtual ~E_AvatarValue_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//id
		int32_t m_type;//类型
		int32_t m_lv;//等级
		int32_t m_cost;//升星消耗数量
		int32_t m_Exp;//升级需要经验
		NFShmVector<struct E_AvatarValueAttributeDesc_s, DEFINE_E_AVATARVALUE_M_ATTRIBUTE_MAX_NUM> m_Attribute;//属性

		virtual void write_to_pbmsg(::proto_ff::E_AvatarValue & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_AvatarValue & msg);
		static ::proto_ff::E_AvatarValue* new_pbmsg(){ return new ::proto_ff::E_AvatarValue(); }
		static ::proto_ff::E_AvatarValue make_pbmsg(){ return ::proto_ff::E_AvatarValue(); }
	};
	typedef struct E_AvatarValue_s E_AvatarValue_t;

	struct Sheet_AvatarValue_s : public NFDescStoreSeqOP {
		Sheet_AvatarValue_s();
		virtual ~Sheet_AvatarValue_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_AvatarValue_s, DEFINE_SHEET_AVATARVALUE_E_AVATARVALUE_LIST_MAX_NUM> E_AvatarValue_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_AvatarValue & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_AvatarValue & msg);
		static ::proto_ff::Sheet_AvatarValue* new_pbmsg(){ return new ::proto_ff::Sheet_AvatarValue(); }
		static ::proto_ff::Sheet_AvatarValue make_pbmsg(){ return ::proto_ff::Sheet_AvatarValue(); }
	};
	typedef struct Sheet_AvatarValue_s Sheet_AvatarValue_t;

	struct E_AvatarDisplayMaterialDesc_s : public NFDescStoreSeqOP {
		E_AvatarDisplayMaterialDesc_s();
		virtual ~E_AvatarDisplayMaterialDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_exp;//经验值
		int32_t m_id;//ID

		virtual void write_to_pbmsg(::proto_ff::E_AvatarDisplayMaterialDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_AvatarDisplayMaterialDesc & msg);
		static ::proto_ff::E_AvatarDisplayMaterialDesc* new_pbmsg(){ return new ::proto_ff::E_AvatarDisplayMaterialDesc(); }
		static ::proto_ff::E_AvatarDisplayMaterialDesc make_pbmsg(){ return ::proto_ff::E_AvatarDisplayMaterialDesc(); }
	};
	typedef struct E_AvatarDisplayMaterialDesc_s E_AvatarDisplayMaterialDesc_t;

	struct E_AvatarDisplay_s : public NFDescStoreSeqOP {
		E_AvatarDisplay_s();
		virtual ~E_AvatarDisplay_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//id
		int32_t m_UpLvType;//升级参考类型
		NFShmString<64> m_skillID;//解锁技能组
		NFShmVector<struct E_AvatarDisplayMaterialDesc_s, DEFINE_E_AVATARDISPLAY_M_MATERIAL_MAX_NUM> m_material;//升级材料
		NFShmVector<int64_t, DEFINE_E_AVATARDISPLAY_M_FRAGMENTID_MAX_NUM> m_fragmentID;//关联碎片ID

		virtual void write_to_pbmsg(::proto_ff::E_AvatarDisplay & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_AvatarDisplay & msg);
		static ::proto_ff::E_AvatarDisplay* new_pbmsg(){ return new ::proto_ff::E_AvatarDisplay(); }
		static ::proto_ff::E_AvatarDisplay make_pbmsg(){ return ::proto_ff::E_AvatarDisplay(); }
	};
	typedef struct E_AvatarDisplay_s E_AvatarDisplay_t;

	struct Sheet_AvatarDisplay_s : public NFDescStoreSeqOP {
		Sheet_AvatarDisplay_s();
		virtual ~Sheet_AvatarDisplay_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_AvatarDisplay_s, DEFINE_SHEET_AVATARDISPLAY_E_AVATARDISPLAY_LIST_MAX_NUM> E_AvatarDisplay_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_AvatarDisplay & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_AvatarDisplay & msg);
		static ::proto_ff::Sheet_AvatarDisplay* new_pbmsg(){ return new ::proto_ff::Sheet_AvatarDisplay(); }
		static ::proto_ff::Sheet_AvatarDisplay make_pbmsg(){ return ::proto_ff::Sheet_AvatarDisplay(); }
	};
	typedef struct Sheet_AvatarDisplay_s Sheet_AvatarDisplay_t;

	struct E_AvatarChangeMaterialDesc_s : public NFDescStoreSeqOP {
		E_AvatarChangeMaterialDesc_s();
		virtual ~E_AvatarChangeMaterialDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_exp;//经验值
		int32_t m_id;//ID

		virtual void write_to_pbmsg(::proto_ff::E_AvatarChangeMaterialDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_AvatarChangeMaterialDesc & msg);
		static ::proto_ff::E_AvatarChangeMaterialDesc* new_pbmsg(){ return new ::proto_ff::E_AvatarChangeMaterialDesc(); }
		static ::proto_ff::E_AvatarChangeMaterialDesc make_pbmsg(){ return ::proto_ff::E_AvatarChangeMaterialDesc(); }
	};
	typedef struct E_AvatarChangeMaterialDesc_s E_AvatarChangeMaterialDesc_t;

	struct E_AvatarChangeAttributeDesc_s : public NFDescStoreSeqOP {
		E_AvatarChangeAttributeDesc_s();
		virtual ~E_AvatarChangeAttributeDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_UpValue;//值
		int32_t m_UpBer;//

		virtual void write_to_pbmsg(::proto_ff::E_AvatarChangeAttributeDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_AvatarChangeAttributeDesc & msg);
		static ::proto_ff::E_AvatarChangeAttributeDesc* new_pbmsg(){ return new ::proto_ff::E_AvatarChangeAttributeDesc(); }
		static ::proto_ff::E_AvatarChangeAttributeDesc make_pbmsg(){ return ::proto_ff::E_AvatarChangeAttributeDesc(); }
	};
	typedef struct E_AvatarChangeAttributeDesc_s E_AvatarChangeAttributeDesc_t;

	struct E_AvatarChange_s : public NFDescStoreSeqOP {
		E_AvatarChange_s();
		virtual ~E_AvatarChange_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//id
		int32_t m_quality;//品质
		int32_t m_UpLvType;//升级参考类型
		int64_t m_avatarSkill;//变身技能
		int32_t m_avatarCD;//变身cd
		int32_t m_avatarTime;//变身时长
		int32_t m_avatarShield;//变身护盾效率
		NFShmString<64> m_skillID;//解锁技能组
		int32_t m_starMax;//星星上限
		int32_t m_LvMax;//等级上限
		int32_t m_ModelID;//模型id
		int32_t m_advance;//进阶类型
		int32_t m_activationItem;//激活需要的道具
		int32_t m_activationNum;//激活需要的道具数量
		int32_t m_starId;//升星需要道具ID
		NFShmString<64> m_starNum;//升星需要数量
		int32_t m_starUpAttributeId;//星级属性类型
		int32_t m_funUnlock;//天神解锁条件
		int32_t m_maxEquip;//最高装备品质
		int32_t m_equipSuit;//套装id
		int32_t m_starBer;//每星级提升百分比
		NFShmString<64> m_mythSkill;//化神被动技能
		NFShmString<64> m_mythSPSkill;//化神专属技能
		int32_t m_mythID;//化神组ID
		int32_t m_mythWayID;//神格组id
		int32_t m_mythCoreID;//神核组ID
		NFShmVector<struct E_AvatarChangeMaterialDesc_s, DEFINE_E_AVATARCHANGE_M_MATERIAL_MAX_NUM> m_material;//升级材料
		NFShmVector<int64_t, DEFINE_E_AVATARCHANGE_M_INITIATIVESKILL_MAX_NUM> m_InitiativeSkill;//主动技能
		NFShmVector<struct E_AvatarChangeAttributeDesc_s, DEFINE_E_AVATARCHANGE_M_ATTRIBUTE_MAX_NUM> m_Attribute;//百分比属性

		virtual void write_to_pbmsg(::proto_ff::E_AvatarChange & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_AvatarChange & msg);
		static ::proto_ff::E_AvatarChange* new_pbmsg(){ return new ::proto_ff::E_AvatarChange(); }
		static ::proto_ff::E_AvatarChange make_pbmsg(){ return ::proto_ff::E_AvatarChange(); }
	};
	typedef struct E_AvatarChange_s E_AvatarChange_t;

	struct Sheet_AvatarChange_s : public NFDescStoreSeqOP {
		Sheet_AvatarChange_s();
		virtual ~Sheet_AvatarChange_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_AvatarChange_s, DEFINE_SHEET_AVATARCHANGE_E_AVATARCHANGE_LIST_MAX_NUM> E_AvatarChange_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_AvatarChange & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_AvatarChange & msg);
		static ::proto_ff::Sheet_AvatarChange* new_pbmsg(){ return new ::proto_ff::Sheet_AvatarChange(); }
		static ::proto_ff::Sheet_AvatarChange make_pbmsg(){ return ::proto_ff::Sheet_AvatarChange(); }
	};
	typedef struct Sheet_AvatarChange_s Sheet_AvatarChange_t;

	struct E_AvatarChangetab_s : public NFDescStoreSeqOP {
		E_AvatarChangetab_s();
		virtual ~E_AvatarChangetab_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_tabID;//id

		virtual void write_to_pbmsg(::proto_ff::E_AvatarChangetab & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_AvatarChangetab & msg);
		static ::proto_ff::E_AvatarChangetab* new_pbmsg(){ return new ::proto_ff::E_AvatarChangetab(); }
		static ::proto_ff::E_AvatarChangetab make_pbmsg(){ return ::proto_ff::E_AvatarChangetab(); }
	};
	typedef struct E_AvatarChangetab_s E_AvatarChangetab_t;

	struct Sheet_AvatarChangetab_s : public NFDescStoreSeqOP {
		Sheet_AvatarChangetab_s();
		virtual ~Sheet_AvatarChangetab_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_AvatarChangetab_s, DEFINE_SHEET_AVATARCHANGETAB_E_AVATARCHANGETAB_LIST_MAX_NUM> E_AvatarChangetab_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_AvatarChangetab & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_AvatarChangetab & msg);
		static ::proto_ff::Sheet_AvatarChangetab* new_pbmsg(){ return new ::proto_ff::Sheet_AvatarChangetab(); }
		static ::proto_ff::Sheet_AvatarChangetab make_pbmsg(){ return ::proto_ff::Sheet_AvatarChangetab(); }
	};
	typedef struct Sheet_AvatarChangetab_s Sheet_AvatarChangetab_t;

	struct E_AvatarBattleslot_s : public NFDescStoreSeqOP {
		E_AvatarBattleslot_s();
		virtual ~E_AvatarBattleslot_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//id
		int32_t m_type;//解锁类型
		NFShmString<64> m_arg;//解锁参数

		virtual void write_to_pbmsg(::proto_ff::E_AvatarBattleslot & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_AvatarBattleslot & msg);
		static ::proto_ff::E_AvatarBattleslot* new_pbmsg(){ return new ::proto_ff::E_AvatarBattleslot(); }
		static ::proto_ff::E_AvatarBattleslot make_pbmsg(){ return ::proto_ff::E_AvatarBattleslot(); }
	};
	typedef struct E_AvatarBattleslot_s E_AvatarBattleslot_t;

	struct Sheet_AvatarBattleslot_s : public NFDescStoreSeqOP {
		Sheet_AvatarBattleslot_s();
		virtual ~Sheet_AvatarBattleslot_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_AvatarBattleslot_s, DEFINE_SHEET_AVATARBATTLESLOT_E_AVATARBATTLESLOT_LIST_MAX_NUM> E_AvatarBattleslot_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_AvatarBattleslot & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_AvatarBattleslot & msg);
		static ::proto_ff::Sheet_AvatarBattleslot* new_pbmsg(){ return new ::proto_ff::Sheet_AvatarBattleslot(); }
		static ::proto_ff::Sheet_AvatarBattleslot make_pbmsg(){ return ::proto_ff::Sheet_AvatarBattleslot(); }
	};
	typedef struct Sheet_AvatarBattleslot_s Sheet_AvatarBattleslot_t;

	struct E_AvatarAdvanceUpattributeDesc_s : public NFDescStoreSeqOP {
		E_AvatarAdvanceUpattributeDesc_s();
		virtual ~E_AvatarAdvanceUpattributeDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_value;//值
		int32_t m_type;//ID

		virtual void write_to_pbmsg(::proto_ff::E_AvatarAdvanceUpattributeDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_AvatarAdvanceUpattributeDesc & msg);
		static ::proto_ff::E_AvatarAdvanceUpattributeDesc* new_pbmsg(){ return new ::proto_ff::E_AvatarAdvanceUpattributeDesc(); }
		static ::proto_ff::E_AvatarAdvanceUpattributeDesc make_pbmsg(){ return ::proto_ff::E_AvatarAdvanceUpattributeDesc(); }
	};
	typedef struct E_AvatarAdvanceUpattributeDesc_s E_AvatarAdvanceUpattributeDesc_t;

	struct E_AvatarAdvance_s : public NFDescStoreSeqOP {
		E_AvatarAdvance_s();
		virtual ~E_AvatarAdvance_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//id
		int32_t m_upAttributeId;//进阶类型
		int32_t m_starID;//进阶专属需求星星数量
		int32_t m_skillID;//进阶专属技能
		NFShmVector<struct E_AvatarAdvanceUpattributeDesc_s, DEFINE_E_AVATARADVANCE_M_UPATTRIBUTE_MAX_NUM> m_upAttribute;//激活属性

		virtual void write_to_pbmsg(::proto_ff::E_AvatarAdvance & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_AvatarAdvance & msg);
		static ::proto_ff::E_AvatarAdvance* new_pbmsg(){ return new ::proto_ff::E_AvatarAdvance(); }
		static ::proto_ff::E_AvatarAdvance make_pbmsg(){ return ::proto_ff::E_AvatarAdvance(); }
	};
	typedef struct E_AvatarAdvance_s E_AvatarAdvance_t;

	struct Sheet_AvatarAdvance_s : public NFDescStoreSeqOP {
		Sheet_AvatarAdvance_s();
		virtual ~Sheet_AvatarAdvance_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_AvatarAdvance_s, DEFINE_SHEET_AVATARADVANCE_E_AVATARADVANCE_LIST_MAX_NUM> E_AvatarAdvance_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_AvatarAdvance & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_AvatarAdvance & msg);
		static ::proto_ff::Sheet_AvatarAdvance* new_pbmsg(){ return new ::proto_ff::Sheet_AvatarAdvance(); }
		static ::proto_ff::Sheet_AvatarAdvance make_pbmsg(){ return ::proto_ff::Sheet_AvatarAdvance(); }
	};
	typedef struct Sheet_AvatarAdvance_s Sheet_AvatarAdvance_t;

	struct E_AvatarSkill_s : public NFDescStoreSeqOP {
		E_AvatarSkill_s();
		virtual ~E_AvatarSkill_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//id
		int32_t m_belong;//归属页签
		int32_t m_order;//排序
		int32_t m_skillid;//技能id

		virtual void write_to_pbmsg(::proto_ff::E_AvatarSkill & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_AvatarSkill & msg);
		static ::proto_ff::E_AvatarSkill* new_pbmsg(){ return new ::proto_ff::E_AvatarSkill(); }
		static ::proto_ff::E_AvatarSkill make_pbmsg(){ return ::proto_ff::E_AvatarSkill(); }
	};
	typedef struct E_AvatarSkill_s E_AvatarSkill_t;

	struct Sheet_AvatarSkill_s : public NFDescStoreSeqOP {
		Sheet_AvatarSkill_s();
		virtual ~Sheet_AvatarSkill_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_AvatarSkill_s, DEFINE_SHEET_AVATARSKILL_E_AVATARSKILL_LIST_MAX_NUM> E_AvatarSkill_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_AvatarSkill & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_AvatarSkill & msg);
		static ::proto_ff::Sheet_AvatarSkill* new_pbmsg(){ return new ::proto_ff::Sheet_AvatarSkill(); }
		static ::proto_ff::Sheet_AvatarSkill make_pbmsg(){ return ::proto_ff::Sheet_AvatarSkill(); }
	};
	typedef struct Sheet_AvatarSkill_s Sheet_AvatarSkill_t;

	struct E_AvatarEquipsuitAttributeDesc_s : public NFDescStoreSeqOP {
		E_AvatarEquipsuitAttributeDesc_s();
		virtual ~E_AvatarEquipsuitAttributeDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_value;//值
		int32_t m_type;//

		virtual void write_to_pbmsg(::proto_ff::E_AvatarEquipsuitAttributeDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_AvatarEquipsuitAttributeDesc & msg);
		static ::proto_ff::E_AvatarEquipsuitAttributeDesc* new_pbmsg(){ return new ::proto_ff::E_AvatarEquipsuitAttributeDesc(); }
		static ::proto_ff::E_AvatarEquipsuitAttributeDesc make_pbmsg(){ return ::proto_ff::E_AvatarEquipsuitAttributeDesc(); }
	};
	typedef struct E_AvatarEquipsuitAttributeDesc_s E_AvatarEquipsuitAttributeDesc_t;

	struct E_AvatarEquipsuit_s : public NFDescStoreSeqOP {
		E_AvatarEquipsuit_s();
		virtual ~E_AvatarEquipsuit_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//id
		int32_t m_groupID;//组id
		int32_t m_quality;//要求品质
		int32_t m_star;//要求星级
		NFShmVector<struct E_AvatarEquipsuitAttributeDesc_s, DEFINE_E_AVATAREQUIPSUIT_M_ATTRIBUTE_MAX_NUM> m_Attribute;//属性

		virtual void write_to_pbmsg(::proto_ff::E_AvatarEquipsuit & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_AvatarEquipsuit & msg);
		static ::proto_ff::E_AvatarEquipsuit* new_pbmsg(){ return new ::proto_ff::E_AvatarEquipsuit(); }
		static ::proto_ff::E_AvatarEquipsuit make_pbmsg(){ return ::proto_ff::E_AvatarEquipsuit(); }
	};
	typedef struct E_AvatarEquipsuit_s E_AvatarEquipsuit_t;

	struct Sheet_AvatarEquipsuit_s : public NFDescStoreSeqOP {
		Sheet_AvatarEquipsuit_s();
		virtual ~Sheet_AvatarEquipsuit_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_AvatarEquipsuit_s, DEFINE_SHEET_AVATAREQUIPSUIT_E_AVATAREQUIPSUIT_LIST_MAX_NUM> E_AvatarEquipsuit_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_AvatarEquipsuit & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_AvatarEquipsuit & msg);
		static ::proto_ff::Sheet_AvatarEquipsuit* new_pbmsg(){ return new ::proto_ff::Sheet_AvatarEquipsuit(); }
		static ::proto_ff::Sheet_AvatarEquipsuit make_pbmsg(){ return ::proto_ff::Sheet_AvatarEquipsuit(); }
	};
	typedef struct Sheet_AvatarEquipsuit_s Sheet_AvatarEquipsuit_t;

	struct E_AvatarMythAttributeDesc_s : public NFDescStoreSeqOP {
		E_AvatarMythAttributeDesc_s();
		virtual ~E_AvatarMythAttributeDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_value;//值
		int32_t m_type;//

		virtual void write_to_pbmsg(::proto_ff::E_AvatarMythAttributeDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_AvatarMythAttributeDesc & msg);
		static ::proto_ff::E_AvatarMythAttributeDesc* new_pbmsg(){ return new ::proto_ff::E_AvatarMythAttributeDesc(); }
		static ::proto_ff::E_AvatarMythAttributeDesc make_pbmsg(){ return ::proto_ff::E_AvatarMythAttributeDesc(); }
	};
	typedef struct E_AvatarMythAttributeDesc_s E_AvatarMythAttributeDesc_t;

	struct E_AvatarMyth_s : public NFDescStoreSeqOP {
		E_AvatarMyth_s();
		virtual ~E_AvatarMyth_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//ID
		int32_t m_groupID;//组ID
		int32_t m_stage;//阶级
		NFShmVector<struct E_AvatarMythAttributeDesc_s, DEFINE_E_AVATARMYTH_M_ATTRIBUTE_MAX_NUM> m_Attribute;//属性

		virtual void write_to_pbmsg(::proto_ff::E_AvatarMyth & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_AvatarMyth & msg);
		static ::proto_ff::E_AvatarMyth* new_pbmsg(){ return new ::proto_ff::E_AvatarMyth(); }
		static ::proto_ff::E_AvatarMyth make_pbmsg(){ return ::proto_ff::E_AvatarMyth(); }
	};
	typedef struct E_AvatarMyth_s E_AvatarMyth_t;

	struct Sheet_AvatarMyth_s : public NFDescStoreSeqOP {
		Sheet_AvatarMyth_s();
		virtual ~Sheet_AvatarMyth_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_AvatarMyth_s, DEFINE_SHEET_AVATARMYTH_E_AVATARMYTH_LIST_MAX_NUM> E_AvatarMyth_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_AvatarMyth & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_AvatarMyth & msg);
		static ::proto_ff::Sheet_AvatarMyth* new_pbmsg(){ return new ::proto_ff::Sheet_AvatarMyth(); }
		static ::proto_ff::Sheet_AvatarMyth make_pbmsg(){ return ::proto_ff::Sheet_AvatarMyth(); }
	};
	typedef struct Sheet_AvatarMyth_s Sheet_AvatarMyth_t;

	struct E_AvatarMythwayAttributeDesc_s : public NFDescStoreSeqOP {
		E_AvatarMythwayAttributeDesc_s();
		virtual ~E_AvatarMythwayAttributeDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_value;//值
		int32_t m_type;//

		virtual void write_to_pbmsg(::proto_ff::E_AvatarMythwayAttributeDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_AvatarMythwayAttributeDesc & msg);
		static ::proto_ff::E_AvatarMythwayAttributeDesc* new_pbmsg(){ return new ::proto_ff::E_AvatarMythwayAttributeDesc(); }
		static ::proto_ff::E_AvatarMythwayAttributeDesc make_pbmsg(){ return ::proto_ff::E_AvatarMythwayAttributeDesc(); }
	};
	typedef struct E_AvatarMythwayAttributeDesc_s E_AvatarMythwayAttributeDesc_t;

	struct E_AvatarMythway_s : public NFDescStoreSeqOP {
		E_AvatarMythway_s();
		virtual ~E_AvatarMythway_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//ID
		int32_t m_groupID;//组id
		int32_t m_stage;//阶数
		int32_t m_star;//星数
		int32_t m_showStar;//显示星数
		int32_t m_mythCoreCondition;//要求神核等级
		int32_t m_posX;//坐标x
		int32_t m_posY;//坐标y
		NFShmVector<int32_t, DEFINE_E_AVATARMYTHWAY_M_EQUIPID_MAX_NUM> m_equipID;//装备id
		NFShmVector<int32_t, DEFINE_E_AVATARMYTHWAY_M_SPECIALID_MAX_NUM> m_specialID;//稀有装备id
		NFShmVector<struct E_AvatarMythwayAttributeDesc_s, DEFINE_E_AVATARMYTHWAY_M_ATTRIBUTE_MAX_NUM> m_Attribute;//属性

		virtual void write_to_pbmsg(::proto_ff::E_AvatarMythway & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_AvatarMythway & msg);
		static ::proto_ff::E_AvatarMythway* new_pbmsg(){ return new ::proto_ff::E_AvatarMythway(); }
		static ::proto_ff::E_AvatarMythway make_pbmsg(){ return ::proto_ff::E_AvatarMythway(); }
	};
	typedef struct E_AvatarMythway_s E_AvatarMythway_t;

	struct Sheet_AvatarMythway_s : public NFDescStoreSeqOP {
		Sheet_AvatarMythway_s();
		virtual ~Sheet_AvatarMythway_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_AvatarMythway_s, DEFINE_SHEET_AVATARMYTHWAY_E_AVATARMYTHWAY_LIST_MAX_NUM> E_AvatarMythway_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_AvatarMythway & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_AvatarMythway & msg);
		static ::proto_ff::Sheet_AvatarMythway* new_pbmsg(){ return new ::proto_ff::Sheet_AvatarMythway(); }
		static ::proto_ff::Sheet_AvatarMythway make_pbmsg(){ return ::proto_ff::Sheet_AvatarMythway(); }
	};
	typedef struct Sheet_AvatarMythway_s Sheet_AvatarMythway_t;

	struct E_AvatarMythcoreAttributeDesc_s : public NFDescStoreSeqOP {
		E_AvatarMythcoreAttributeDesc_s();
		virtual ~E_AvatarMythcoreAttributeDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_value;//值
		int32_t m_type;//

		virtual void write_to_pbmsg(::proto_ff::E_AvatarMythcoreAttributeDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_AvatarMythcoreAttributeDesc & msg);
		static ::proto_ff::E_AvatarMythcoreAttributeDesc* new_pbmsg(){ return new ::proto_ff::E_AvatarMythcoreAttributeDesc(); }
		static ::proto_ff::E_AvatarMythcoreAttributeDesc make_pbmsg(){ return ::proto_ff::E_AvatarMythcoreAttributeDesc(); }
	};
	typedef struct E_AvatarMythcoreAttributeDesc_s E_AvatarMythcoreAttributeDesc_t;

	struct E_AvatarMythcore_s : public NFDescStoreSeqOP {
		E_AvatarMythcore_s();
		virtual ~E_AvatarMythcore_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//ID
		int32_t m_groupID;//组ID
		int32_t m_LV;//等级
		int32_t m_costID;//消耗道具
		int32_t m_costNum;//消耗数量
		int32_t m_success;//成功率
		NFShmVector<struct E_AvatarMythcoreAttributeDesc_s, DEFINE_E_AVATARMYTHCORE_M_ATTRIBUTE_MAX_NUM> m_Attribute;//属性

		virtual void write_to_pbmsg(::proto_ff::E_AvatarMythcore & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_AvatarMythcore & msg);
		static ::proto_ff::E_AvatarMythcore* new_pbmsg(){ return new ::proto_ff::E_AvatarMythcore(); }
		static ::proto_ff::E_AvatarMythcore make_pbmsg(){ return ::proto_ff::E_AvatarMythcore(); }
	};
	typedef struct E_AvatarMythcore_s E_AvatarMythcore_t;

	struct Sheet_AvatarMythcore_s : public NFDescStoreSeqOP {
		Sheet_AvatarMythcore_s();
		virtual ~Sheet_AvatarMythcore_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_AvatarMythcore_s, DEFINE_SHEET_AVATARMYTHCORE_E_AVATARMYTHCORE_LIST_MAX_NUM> E_AvatarMythcore_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_AvatarMythcore & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_AvatarMythcore & msg);
		static ::proto_ff::Sheet_AvatarMythcore* new_pbmsg(){ return new ::proto_ff::Sheet_AvatarMythcore(); }
		static ::proto_ff::Sheet_AvatarMythcore make_pbmsg(){ return ::proto_ff::Sheet_AvatarMythcore(); }
	};
	typedef struct Sheet_AvatarMythcore_s Sheet_AvatarMythcore_t;

	struct E_AvatarMythequipAttributeDesc_s : public NFDescStoreSeqOP {
		E_AvatarMythequipAttributeDesc_s();
		virtual ~E_AvatarMythequipAttributeDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_value;//值
		int32_t m_type;//

		virtual void write_to_pbmsg(::proto_ff::E_AvatarMythequipAttributeDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_AvatarMythequipAttributeDesc & msg);
		static ::proto_ff::E_AvatarMythequipAttributeDesc* new_pbmsg(){ return new ::proto_ff::E_AvatarMythequipAttributeDesc(); }
		static ::proto_ff::E_AvatarMythequipAttributeDesc make_pbmsg(){ return ::proto_ff::E_AvatarMythequipAttributeDesc(); }
	};
	typedef struct E_AvatarMythequipAttributeDesc_s E_AvatarMythequipAttributeDesc_t;

	struct E_AvatarMythequip_s : public NFDescStoreSeqOP {
		E_AvatarMythequip_s();
		virtual ~E_AvatarMythequip_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_itemID;//物品ID
		int32_t m_star;//星级
		NFShmVector<struct E_AvatarMythequipAttributeDesc_s, DEFINE_E_AVATARMYTHEQUIP_M_ATTRIBUTE_MAX_NUM> m_Attribute;//属性

		virtual void write_to_pbmsg(::proto_ff::E_AvatarMythequip & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_AvatarMythequip & msg);
		static ::proto_ff::E_AvatarMythequip* new_pbmsg(){ return new ::proto_ff::E_AvatarMythequip(); }
		static ::proto_ff::E_AvatarMythequip make_pbmsg(){ return ::proto_ff::E_AvatarMythequip(); }
	};
	typedef struct E_AvatarMythequip_s E_AvatarMythequip_t;

	struct Sheet_AvatarMythequip_s : public NFDescStoreSeqOP {
		Sheet_AvatarMythequip_s();
		virtual ~Sheet_AvatarMythequip_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_AvatarMythequip_s, DEFINE_SHEET_AVATARMYTHEQUIP_E_AVATARMYTHEQUIP_LIST_MAX_NUM> E_AvatarMythequip_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_AvatarMythequip & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_AvatarMythequip & msg);
		static ::proto_ff::Sheet_AvatarMythequip* new_pbmsg(){ return new ::proto_ff::Sheet_AvatarMythequip(); }
		static ::proto_ff::Sheet_AvatarMythequip make_pbmsg(){ return ::proto_ff::Sheet_AvatarMythequip(); }
	};
	typedef struct Sheet_AvatarMythequip_s Sheet_AvatarMythequip_t;

}

