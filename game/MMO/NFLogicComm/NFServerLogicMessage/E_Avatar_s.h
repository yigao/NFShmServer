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
#define DEFINE_E_AVATARVALUE_M_ATTRIBUTE_MAX_NUM 9
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
		int64_t m_fragmentid;//碎片ID
		int64_t m_item;//物品ID
		int32_t m_itemnum;//碎片使用上限
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
		int32_t m_exp;//升级需要经验
		NFShmVector<struct E_AvatarValueAttributeDesc_s, DEFINE_E_AVATARVALUE_M_ATTRIBUTE_MAX_NUM> m_attribute;//属性

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
		int32_t m_uplvtype;//升级参考类型
		NFShmString<64> m_skillid;//解锁技能组
		NFShmVector<struct E_AvatarDisplayMaterialDesc_s, DEFINE_E_AVATARDISPLAY_M_MATERIAL_MAX_NUM> m_material;//升级材料
		NFShmVector<int64_t, DEFINE_E_AVATARDISPLAY_M_FRAGMENTID_MAX_NUM> m_fragmentid;//关联碎片ID

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
		int32_t m_upvalue;//值
		int32_t m_upber;//

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
		int32_t m_uplvtype;//升级参考类型
		int64_t m_avatarskill;//变身技能
		int32_t m_avatarcd;//变身cd
		int32_t m_avatartime;//变身时长
		int32_t m_avatarshield;//变身护盾效率
		NFShmString<64> m_skillid;//解锁技能组
		int32_t m_starmax;//星星上限
		int32_t m_lvmax;//等级上限
		int32_t m_modelid;//模型id
		int32_t m_advance;//进阶类型
		int32_t m_activationitem;//激活需要的道具
		int32_t m_activationnum;//激活需要的道具数量
		int32_t m_starid;//升星需要道具ID
		NFShmString<64> m_starnum;//升星需要数量
		int32_t m_starupattributeid;//星级属性类型
		int32_t m_fununlock;//天神解锁条件
		int32_t m_maxequip;//最高装备品质
		int32_t m_equipsuit;//套装id
		int32_t m_starber;//每星级提升百分比
		NFShmVector<struct E_AvatarChangeMaterialDesc_s, DEFINE_E_AVATARCHANGE_M_MATERIAL_MAX_NUM> m_material;//升级材料
		NFShmVector<int64_t, DEFINE_E_AVATARCHANGE_M_INITIATIVESKILL_MAX_NUM> m_initiativeskill;//主动技能
		NFShmVector<struct E_AvatarChangeAttributeDesc_s, DEFINE_E_AVATARCHANGE_M_ATTRIBUTE_MAX_NUM> m_attribute;//百分比属性

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
		int32_t m_tabid;//id

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
		int32_t m_upattributeid;//进阶类型
		int32_t m_starid;//进阶专属需求星星数量
		int32_t m_skillid;//进阶专属技能
		NFShmVector<struct E_AvatarAdvanceUpattributeDesc_s, DEFINE_E_AVATARADVANCE_M_UPATTRIBUTE_MAX_NUM> m_upattribute;//激活属性

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
		int32_t m_groupid;//组id
		int32_t m_quality;//要求品质
		int32_t m_star;//要求星级
		NFShmVector<struct E_AvatarEquipsuitAttributeDesc_s, DEFINE_E_AVATAREQUIPSUIT_M_ATTRIBUTE_MAX_NUM> m_attribute;//属性

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

}

