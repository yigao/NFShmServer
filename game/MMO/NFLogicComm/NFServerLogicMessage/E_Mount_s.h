#pragma once

#include <stdint.h>
#include <NFComm/NFShmStl/NFShmString.h>
#include <NFComm/NFShmStl/NFShmVector.h>
#include <NFComm/NFShmCore/NFSeqOP.h>
#include <NFComm/NFShmCore/NFShmMgr.h>
#include "E_Mount.pb.h"
#include "E_Mount_s.h"

#define DEFINE_E_MOUNTFRAGMENT_M_ATTRIBUTE_MAX_NUM 5
#define DEFINE_SHEET_MOUNTFRAGMENT_E_MOUNTFRAGMENT_LIST_MAX_NUM 16
#define DEFINE_E_MOUNTVALUE_M_ATTRIBUTE_MAX_NUM 9
#define DEFINE_SHEET_MOUNTVALUE_E_MOUNTVALUE_LIST_MAX_NUM 2048
#define DEFINE_E_MOUNTDISPLAY_M_MATERIAL_MAX_NUM 2
#define DEFINE_E_MOUNTDISPLAY_M_FRAGMENTID_MAX_NUM 3
#define DEFINE_SHEET_MOUNTDISPLAY_E_MOUNTDISPLAY_LIST_MAX_NUM 32
#define DEFINE_SHEET_MOUNTUNLOCK_E_MOUNTUNLOCK_LIST_MAX_NUM 8
#define DEFINE_E_MOUNTCHANGE_M_MATERIAL_MAX_NUM 2
#define DEFINE_E_MOUNTCHANGE_M_ATTRIBUTE_MAX_NUM 4
#define DEFINE_SHEET_MOUNTCHANGE_E_MOUNTCHANGE_LIST_MAX_NUM 32
#define DEFINE_E_MOUNTADVANCE_M_UPATTRIBUTE_MAX_NUM 5
#define DEFINE_SHEET_MOUNTADVANCE_E_MOUNTADVANCE_LIST_MAX_NUM 64
#define DEFINE_SHEET_MOUNTBABY_EGG_E_MOUNTBABY_EGG_LIST_MAX_NUM 8
#define DEFINE_E_MOUNTHUAKUN_M_UPLV_MAX_NUM 4
#define DEFINE_E_MOUNTHUAKUN_M_MATERIAL_MAX_NUM 3
#define DEFINE_E_MOUNTHUAKUN_M_ADVANCE_MAX_NUM 4
#define DEFINE_E_MOUNTHUAKUN_M_UPSTARITEM_MAX_NUM 2
#define DEFINE_E_MOUNTHUAKUN_M_UPSTARNUM_MAX_NUM 2
#define DEFINE_E_MOUNTHUAKUN_M_ATTRIBUTE_MAX_NUM 4
#define DEFINE_SHEET_MOUNTHUAKUN_E_MOUNTHUAKUN_LIST_MAX_NUM 8
#define DEFINE_E_MOUNTHUAKUN_VALUE_M_ATTRIBUTE_MAX_NUM 6
#define DEFINE_SHEET_MOUNTHUAKUN_VALUE_E_MOUNTHUAKUN_VALUE_LIST_MAX_NUM 512
#define DEFINE_E_MOUNTHUAKUN_ADVANCEVALUE_M_ITEM_MAX_NUM 3
#define DEFINE_SHEET_MOUNTHUAKUN_ADVANCEVALUE_E_MOUNTHUAKUN_ADVANCEVALUE_LIST_MAX_NUM 128
#define DEFINE_E_MOUNTHUAKUN_CHANGE_M_ATTRIBUTE_MAX_NUM 4
#define DEFINE_SHEET_MOUNTHUAKUN_CHANGE_E_MOUNTHUAKUN_CHANGE_LIST_MAX_NUM 8
#define DEFINE_E_MOUNTHUAKUN_ADVANCE_M_UPATTRIBUTE_MAX_NUM 5
#define DEFINE_SHEET_MOUNTHUAKUN_ADVANCE_E_MOUNTHUAKUN_ADVANCE_LIST_MAX_NUM 128
#define DEFINE_E_MOUNTBLOOD_M_ATTRIBUTE_MAX_NUM 2
#define DEFINE_SHEET_MOUNTBLOOD_E_MOUNTBLOOD_LIST_MAX_NUM 32
#define DEFINE_SHEET_MOUNTHUAKUN_EQUIP_E_MOUNTHUAKUN_EQUIP_LIST_MAX_NUM 64
#define DEFINE_E_MOUNTEQUIP_VALUE_M_ATTRIBUTE_MAX_NUM 4
#define DEFINE_SHEET_MOUNTEQUIP_VALUE_E_MOUNTEQUIP_VALUE_LIST_MAX_NUM 4096
#define DEFINE_E_MOUNTEQUIPSUIT_M_ATTRIBUTE_MAX_NUM 3
#define DEFINE_SHEET_MOUNTEQUIPSUIT_E_MOUNTEQUIPSUIT_LIST_MAX_NUM 32
#define DEFINE_E_MOUNTEQUIPTOP_M_TOP_MAX_NUM 8
#define DEFINE_E_MOUNTEQUIPTOP_M_PERCENT_MAX_NUM 8
#define DEFINE_SHEET_MOUNTEQUIPTOP_E_MOUNTEQUIPTOP_LIST_MAX_NUM 16
#define DEFINE_SHEET_MOUNTEQUIPTOPVALUE_E_MOUNTEQUIPTOPVALUE_LIST_MAX_NUM 128
#define DEFINE_SHEET_MOUNTEQUIPPART_E_MOUNTEQUIPPART_LIST_MAX_NUM 16
#define DEFINE_SHEET_MOUNTEMPOWERMENTTOUR_DEBRIS_E_MOUNTEMPOWERMENTTOUR_DEBRIS_LIST_MAX_NUM 16
#define DEFINE_E_MOUNTEMPOWERMENT_M_TOUR_MAX_NUM 2
#define DEFINE_SHEET_MOUNTEMPOWERMENT_E_MOUNTEMPOWERMENT_LIST_MAX_NUM 128
#define DEFINE_SHEET_MOUNTEMPOWERMENT_POSITION_E_MOUNTEMPOWERMENT_POSITION_LIST_MAX_NUM 8
#define DEFINE_SHEET_MOUNTEMPOWERMENT_SLOT_E_MOUNTEMPOWERMENT_SLOT_LIST_MAX_NUM 16
#define DEFINE_SHEET_MOUNTEMPOWERMENT_EVENT_E_MOUNTEMPOWERMENT_EVENT_LIST_MAX_NUM 16


namespace proto_ff_s {

	struct E_MountFragmentAttributeDesc_s : public NFDescStoreSeqOP {
		E_MountFragmentAttributeDesc_s();
		virtual ~E_MountFragmentAttributeDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_value;//值
		int32_t m_type;//ID

		virtual void write_to_pbmsg(::proto_ff::E_MountFragmentAttributeDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_MountFragmentAttributeDesc & msg);
		static ::proto_ff::E_MountFragmentAttributeDesc* new_pbmsg(){ return new ::proto_ff::E_MountFragmentAttributeDesc(); }
		static ::proto_ff::E_MountFragmentAttributeDesc make_pbmsg(){ return ::proto_ff::E_MountFragmentAttributeDesc(); }
	};
	typedef struct E_MountFragmentAttributeDesc_s E_MountFragmentAttributeDesc_t;

	struct E_MountFragment_s : public NFDescStoreSeqOP {
		E_MountFragment_s();
		virtual ~E_MountFragment_s(){}
		int CreateInit();
		int ResumeInit();
		int64_t m_fragmentID;//碎片ID
		int64_t m_item;//物品ID
		int32_t m_itemNum;//碎片使用上限
		NFShmVector<struct E_MountFragmentAttributeDesc_s, DEFINE_E_MOUNTFRAGMENT_M_ATTRIBUTE_MAX_NUM> m_attribute;//基础属性

		virtual void write_to_pbmsg(::proto_ff::E_MountFragment & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_MountFragment & msg);
		static ::proto_ff::E_MountFragment* new_pbmsg(){ return new ::proto_ff::E_MountFragment(); }
		static ::proto_ff::E_MountFragment make_pbmsg(){ return ::proto_ff::E_MountFragment(); }
	};
	typedef struct E_MountFragment_s E_MountFragment_t;

	struct Sheet_MountFragment_s : public NFDescStoreSeqOP {
		Sheet_MountFragment_s();
		virtual ~Sheet_MountFragment_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_MountFragment_s, DEFINE_SHEET_MOUNTFRAGMENT_E_MOUNTFRAGMENT_LIST_MAX_NUM> E_MountFragment_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_MountFragment & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_MountFragment & msg);
		static ::proto_ff::Sheet_MountFragment* new_pbmsg(){ return new ::proto_ff::Sheet_MountFragment(); }
		static ::proto_ff::Sheet_MountFragment make_pbmsg(){ return ::proto_ff::Sheet_MountFragment(); }
	};
	typedef struct Sheet_MountFragment_s Sheet_MountFragment_t;

	struct E_MountValueAttributeDesc_s : public NFDescStoreSeqOP {
		E_MountValueAttributeDesc_s();
		virtual ~E_MountValueAttributeDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_value;//值
		int32_t m_type;//

		virtual void write_to_pbmsg(::proto_ff::E_MountValueAttributeDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_MountValueAttributeDesc & msg);
		static ::proto_ff::E_MountValueAttributeDesc* new_pbmsg(){ return new ::proto_ff::E_MountValueAttributeDesc(); }
		static ::proto_ff::E_MountValueAttributeDesc make_pbmsg(){ return ::proto_ff::E_MountValueAttributeDesc(); }
	};
	typedef struct E_MountValueAttributeDesc_s E_MountValueAttributeDesc_t;

	struct E_MountValue_s : public NFDescStoreSeqOP {
		E_MountValue_s();
		virtual ~E_MountValue_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//id
		int32_t m_type;//类型
		int32_t m_lv;//等级
		int32_t m_Exp;//升级需要经验
		int32_t m_speed;//默认乘骑速度值
		NFShmVector<struct E_MountValueAttributeDesc_s, DEFINE_E_MOUNTVALUE_M_ATTRIBUTE_MAX_NUM> m_Attribute;//属性

		virtual void write_to_pbmsg(::proto_ff::E_MountValue & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_MountValue & msg);
		static ::proto_ff::E_MountValue* new_pbmsg(){ return new ::proto_ff::E_MountValue(); }
		static ::proto_ff::E_MountValue make_pbmsg(){ return ::proto_ff::E_MountValue(); }
	};
	typedef struct E_MountValue_s E_MountValue_t;

	struct Sheet_MountValue_s : public NFDescStoreSeqOP {
		Sheet_MountValue_s();
		virtual ~Sheet_MountValue_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_MountValue_s, DEFINE_SHEET_MOUNTVALUE_E_MOUNTVALUE_LIST_MAX_NUM> E_MountValue_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_MountValue & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_MountValue & msg);
		static ::proto_ff::Sheet_MountValue* new_pbmsg(){ return new ::proto_ff::Sheet_MountValue(); }
		static ::proto_ff::Sheet_MountValue make_pbmsg(){ return ::proto_ff::Sheet_MountValue(); }
	};
	typedef struct Sheet_MountValue_s Sheet_MountValue_t;

	struct E_MountDisplayMaterialDesc_s : public NFDescStoreSeqOP {
		E_MountDisplayMaterialDesc_s();
		virtual ~E_MountDisplayMaterialDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_exp;//经验值
		int32_t m_id;//ID

		virtual void write_to_pbmsg(::proto_ff::E_MountDisplayMaterialDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_MountDisplayMaterialDesc & msg);
		static ::proto_ff::E_MountDisplayMaterialDesc* new_pbmsg(){ return new ::proto_ff::E_MountDisplayMaterialDesc(); }
		static ::proto_ff::E_MountDisplayMaterialDesc make_pbmsg(){ return ::proto_ff::E_MountDisplayMaterialDesc(); }
	};
	typedef struct E_MountDisplayMaterialDesc_s E_MountDisplayMaterialDesc_t;

	struct E_MountDisplay_s : public NFDescStoreSeqOP {
		E_MountDisplay_s();
		virtual ~E_MountDisplay_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//id
		int32_t m_speed;//默认乘骑速度值
		int32_t m_UpLvType;//升级参考类型
		NFShmString<64> m_skillID;//解锁技能组
		NFShmString<64> m_fxID;//幻化特效
		int32_t m_starUp;//星星上限
		int32_t m_LvMax;//等级上限
		NFShmVector<struct E_MountDisplayMaterialDesc_s, DEFINE_E_MOUNTDISPLAY_M_MATERIAL_MAX_NUM> m_material;//升级材料
		NFShmVector<int64_t, DEFINE_E_MOUNTDISPLAY_M_FRAGMENTID_MAX_NUM> m_fragmentID;//关联碎片ID

		virtual void write_to_pbmsg(::proto_ff::E_MountDisplay & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_MountDisplay & msg);
		static ::proto_ff::E_MountDisplay* new_pbmsg(){ return new ::proto_ff::E_MountDisplay(); }
		static ::proto_ff::E_MountDisplay make_pbmsg(){ return ::proto_ff::E_MountDisplay(); }
	};
	typedef struct E_MountDisplay_s E_MountDisplay_t;

	struct Sheet_MountDisplay_s : public NFDescStoreSeqOP {
		Sheet_MountDisplay_s();
		virtual ~Sheet_MountDisplay_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_MountDisplay_s, DEFINE_SHEET_MOUNTDISPLAY_E_MOUNTDISPLAY_LIST_MAX_NUM> E_MountDisplay_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_MountDisplay & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_MountDisplay & msg);
		static ::proto_ff::Sheet_MountDisplay* new_pbmsg(){ return new ::proto_ff::Sheet_MountDisplay(); }
		static ::proto_ff::Sheet_MountDisplay make_pbmsg(){ return ::proto_ff::Sheet_MountDisplay(); }
	};
	typedef struct Sheet_MountDisplay_s Sheet_MountDisplay_t;

	struct E_MountUnlock_s : public NFDescStoreSeqOP {
		E_MountUnlock_s();
		virtual ~E_MountUnlock_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//id
		int32_t m_Lv;//等级
		int32_t m_ModelID;//模型id
		NFShmString<64> m_Name;//名称

		virtual void write_to_pbmsg(::proto_ff::E_MountUnlock & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_MountUnlock & msg);
		static ::proto_ff::E_MountUnlock* new_pbmsg(){ return new ::proto_ff::E_MountUnlock(); }
		static ::proto_ff::E_MountUnlock make_pbmsg(){ return ::proto_ff::E_MountUnlock(); }
	};
	typedef struct E_MountUnlock_s E_MountUnlock_t;

	struct Sheet_MountUnlock_s : public NFDescStoreSeqOP {
		Sheet_MountUnlock_s();
		virtual ~Sheet_MountUnlock_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_MountUnlock_s, DEFINE_SHEET_MOUNTUNLOCK_E_MOUNTUNLOCK_LIST_MAX_NUM> E_MountUnlock_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_MountUnlock & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_MountUnlock & msg);
		static ::proto_ff::Sheet_MountUnlock* new_pbmsg(){ return new ::proto_ff::Sheet_MountUnlock(); }
		static ::proto_ff::Sheet_MountUnlock make_pbmsg(){ return ::proto_ff::Sheet_MountUnlock(); }
	};
	typedef struct Sheet_MountUnlock_s Sheet_MountUnlock_t;

	struct E_MountChangeMaterialDesc_s : public NFDescStoreSeqOP {
		E_MountChangeMaterialDesc_s();
		virtual ~E_MountChangeMaterialDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_exp;//经验值
		int32_t m_id;//ID

		virtual void write_to_pbmsg(::proto_ff::E_MountChangeMaterialDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_MountChangeMaterialDesc & msg);
		static ::proto_ff::E_MountChangeMaterialDesc* new_pbmsg(){ return new ::proto_ff::E_MountChangeMaterialDesc(); }
		static ::proto_ff::E_MountChangeMaterialDesc make_pbmsg(){ return ::proto_ff::E_MountChangeMaterialDesc(); }
	};
	typedef struct E_MountChangeMaterialDesc_s E_MountChangeMaterialDesc_t;

	struct E_MountChangeAttributeDesc_s : public NFDescStoreSeqOP {
		E_MountChangeAttributeDesc_s();
		virtual ~E_MountChangeAttributeDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_UpValue;//值
		int32_t m_UpBer;//

		virtual void write_to_pbmsg(::proto_ff::E_MountChangeAttributeDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_MountChangeAttributeDesc & msg);
		static ::proto_ff::E_MountChangeAttributeDesc* new_pbmsg(){ return new ::proto_ff::E_MountChangeAttributeDesc(); }
		static ::proto_ff::E_MountChangeAttributeDesc make_pbmsg(){ return ::proto_ff::E_MountChangeAttributeDesc(); }
	};
	typedef struct E_MountChangeAttributeDesc_s E_MountChangeAttributeDesc_t;

	struct E_MountChange_s : public NFDescStoreSeqOP {
		E_MountChange_s();
		virtual ~E_MountChange_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//id
		NFShmString<64> m_name;//名称
		NFShmString<64> m_advanceName;//进阶后名字
		int32_t m_speed;//默认乘骑速度值
		int32_t m_UpLvType;//升级参考类型
		int32_t m_activeSkill;//激活获得技能
		NFShmString<64> m_skillID;//解锁技能组
		NFShmString<64> m_fxID;//幻化特效
		int32_t m_starMax;//星星上限
		int32_t m_LvMax;//等级上限
		int32_t m_ModelID;//模型id
		int32_t m_activationItem;//激活需要的道具
		int32_t m_activationNum;//激活需要的道具数量
		int32_t m_starId;//升星需要道具ID
		NFShmString<256> m_starNum;//升星需要数量
		int32_t m_starBer;//每星级提升百分比
		int32_t m_upAttributeId;//进阶类型
		NFShmVector<struct E_MountChangeMaterialDesc_s, DEFINE_E_MOUNTCHANGE_M_MATERIAL_MAX_NUM> m_material;//升级材料
		NFShmVector<struct E_MountChangeAttributeDesc_s, DEFINE_E_MOUNTCHANGE_M_ATTRIBUTE_MAX_NUM> m_Attribute;//百分比属性

		virtual void write_to_pbmsg(::proto_ff::E_MountChange & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_MountChange & msg);
		static ::proto_ff::E_MountChange* new_pbmsg(){ return new ::proto_ff::E_MountChange(); }
		static ::proto_ff::E_MountChange make_pbmsg(){ return ::proto_ff::E_MountChange(); }
	};
	typedef struct E_MountChange_s E_MountChange_t;

	struct Sheet_MountChange_s : public NFDescStoreSeqOP {
		Sheet_MountChange_s();
		virtual ~Sheet_MountChange_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_MountChange_s, DEFINE_SHEET_MOUNTCHANGE_E_MOUNTCHANGE_LIST_MAX_NUM> E_MountChange_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_MountChange & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_MountChange & msg);
		static ::proto_ff::Sheet_MountChange* new_pbmsg(){ return new ::proto_ff::Sheet_MountChange(); }
		static ::proto_ff::Sheet_MountChange make_pbmsg(){ return ::proto_ff::Sheet_MountChange(); }
	};
	typedef struct Sheet_MountChange_s Sheet_MountChange_t;

	struct E_MountAdvanceUpattributeDesc_s : public NFDescStoreSeqOP {
		E_MountAdvanceUpattributeDesc_s();
		virtual ~E_MountAdvanceUpattributeDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_value;//值
		int32_t m_type;//ID

		virtual void write_to_pbmsg(::proto_ff::E_MountAdvanceUpattributeDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_MountAdvanceUpattributeDesc & msg);
		static ::proto_ff::E_MountAdvanceUpattributeDesc* new_pbmsg(){ return new ::proto_ff::E_MountAdvanceUpattributeDesc(); }
		static ::proto_ff::E_MountAdvanceUpattributeDesc make_pbmsg(){ return ::proto_ff::E_MountAdvanceUpattributeDesc(); }
	};
	typedef struct E_MountAdvanceUpattributeDesc_s E_MountAdvanceUpattributeDesc_t;

	struct E_MountAdvance_s : public NFDescStoreSeqOP {
		E_MountAdvance_s();
		virtual ~E_MountAdvance_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//id
		int32_t m_upAttributeId;//进阶类型
		int32_t m_starID;//进阶专属需求星星数量
		int32_t m_skillID;//进阶专属技能
		NFShmVector<struct E_MountAdvanceUpattributeDesc_s, DEFINE_E_MOUNTADVANCE_M_UPATTRIBUTE_MAX_NUM> m_upAttribute;//激活属性

		virtual void write_to_pbmsg(::proto_ff::E_MountAdvance & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_MountAdvance & msg);
		static ::proto_ff::E_MountAdvance* new_pbmsg(){ return new ::proto_ff::E_MountAdvance(); }
		static ::proto_ff::E_MountAdvance make_pbmsg(){ return ::proto_ff::E_MountAdvance(); }
	};
	typedef struct E_MountAdvance_s E_MountAdvance_t;

	struct Sheet_MountAdvance_s : public NFDescStoreSeqOP {
		Sheet_MountAdvance_s();
		virtual ~Sheet_MountAdvance_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_MountAdvance_s, DEFINE_SHEET_MOUNTADVANCE_E_MOUNTADVANCE_LIST_MAX_NUM> E_MountAdvance_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_MountAdvance & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_MountAdvance & msg);
		static ::proto_ff::Sheet_MountAdvance* new_pbmsg(){ return new ::proto_ff::Sheet_MountAdvance(); }
		static ::proto_ff::Sheet_MountAdvance make_pbmsg(){ return ::proto_ff::Sheet_MountAdvance(); }
	};
	typedef struct Sheet_MountAdvance_s Sheet_MountAdvance_t;

	struct E_MountBaby_egg_s : public NFDescStoreSeqOP {
		E_MountBaby_egg_s();
		virtual ~E_MountBaby_egg_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//蛋道具id
		int32_t m_item;//道具id
		int32_t m_time;//蛋生成时间
		int32_t m_itemBox;//奖励盒id

		virtual void write_to_pbmsg(::proto_ff::E_MountBaby_egg & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_MountBaby_egg & msg);
		static ::proto_ff::E_MountBaby_egg* new_pbmsg(){ return new ::proto_ff::E_MountBaby_egg(); }
		static ::proto_ff::E_MountBaby_egg make_pbmsg(){ return ::proto_ff::E_MountBaby_egg(); }
	};
	typedef struct E_MountBaby_egg_s E_MountBaby_egg_t;

	struct Sheet_MountBaby_egg_s : public NFDescStoreSeqOP {
		Sheet_MountBaby_egg_s();
		virtual ~Sheet_MountBaby_egg_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_MountBaby_egg_s, DEFINE_SHEET_MOUNTBABY_EGG_E_MOUNTBABY_EGG_LIST_MAX_NUM> E_MountBaby_egg_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_MountBaby_egg & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_MountBaby_egg & msg);
		static ::proto_ff::Sheet_MountBaby_egg* new_pbmsg(){ return new ::proto_ff::Sheet_MountBaby_egg(); }
		static ::proto_ff::Sheet_MountBaby_egg make_pbmsg(){ return ::proto_ff::Sheet_MountBaby_egg(); }
	};
	typedef struct Sheet_MountBaby_egg_s Sheet_MountBaby_egg_t;

	struct E_MountHuakunUplvDesc_s : public NFDescStoreSeqOP {
		E_MountHuakunUplvDesc_s();
		virtual ~E_MountHuakunUplvDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_UpValue;//值
		int32_t m_UpBer;//

		virtual void write_to_pbmsg(::proto_ff::E_MountHuakunUplvDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_MountHuakunUplvDesc & msg);
		static ::proto_ff::E_MountHuakunUplvDesc* new_pbmsg(){ return new ::proto_ff::E_MountHuakunUplvDesc(); }
		static ::proto_ff::E_MountHuakunUplvDesc make_pbmsg(){ return ::proto_ff::E_MountHuakunUplvDesc(); }
	};
	typedef struct E_MountHuakunUplvDesc_s E_MountHuakunUplvDesc_t;

	struct E_MountHuakunMaterialDesc_s : public NFDescStoreSeqOP {
		E_MountHuakunMaterialDesc_s();
		virtual ~E_MountHuakunMaterialDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_exp;//经验值
		int32_t m_id;//ID

		virtual void write_to_pbmsg(::proto_ff::E_MountHuakunMaterialDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_MountHuakunMaterialDesc & msg);
		static ::proto_ff::E_MountHuakunMaterialDesc* new_pbmsg(){ return new ::proto_ff::E_MountHuakunMaterialDesc(); }
		static ::proto_ff::E_MountHuakunMaterialDesc make_pbmsg(){ return ::proto_ff::E_MountHuakunMaterialDesc(); }
	};
	typedef struct E_MountHuakunMaterialDesc_s E_MountHuakunMaterialDesc_t;

	struct E_MountHuakunAdvanceDesc_s : public NFDescStoreSeqOP {
		E_MountHuakunAdvanceDesc_s();
		virtual ~E_MountHuakunAdvanceDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_UpValue;//值
		int32_t m_UpBer;//

		virtual void write_to_pbmsg(::proto_ff::E_MountHuakunAdvanceDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_MountHuakunAdvanceDesc & msg);
		static ::proto_ff::E_MountHuakunAdvanceDesc* new_pbmsg(){ return new ::proto_ff::E_MountHuakunAdvanceDesc(); }
		static ::proto_ff::E_MountHuakunAdvanceDesc make_pbmsg(){ return ::proto_ff::E_MountHuakunAdvanceDesc(); }
	};
	typedef struct E_MountHuakunAdvanceDesc_s E_MountHuakunAdvanceDesc_t;

	struct E_MountHuakunAttributeDesc_s : public NFDescStoreSeqOP {
		E_MountHuakunAttributeDesc_s();
		virtual ~E_MountHuakunAttributeDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_UpValue;//值
		int32_t m_UpBer;//

		virtual void write_to_pbmsg(::proto_ff::E_MountHuakunAttributeDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_MountHuakunAttributeDesc & msg);
		static ::proto_ff::E_MountHuakunAttributeDesc* new_pbmsg(){ return new ::proto_ff::E_MountHuakunAttributeDesc(); }
		static ::proto_ff::E_MountHuakunAttributeDesc make_pbmsg(){ return ::proto_ff::E_MountHuakunAttributeDesc(); }
	};
	typedef struct E_MountHuakunAttributeDesc_s E_MountHuakunAttributeDesc_t;

	struct E_MountHuakun_s : public NFDescStoreSeqOP {
		E_MountHuakun_s();
		virtual ~E_MountHuakun_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//id
		int32_t m_ModelID;//模型
		int32_t m_quality;//坐骑品质
		int32_t m_speed;//默认乘骑速度值
		int32_t m_UpLvType;//升级参考类型
		int32_t m_activateItem;//激活材料
		int32_t m_activateItemNum;//激活材料需要数量
		int32_t m_advanceType;//进阶类型
		int32_t m_starvanceType;//星级类型
		int32_t m_starLimit;//星级上限
		int32_t m_starBer;//每星级提升百分比
		NFShmString<64> m_skill_LG;//灵根技能
		NFShmString<64> m_skill_BD;//被动
		int32_t m_soaringAttributeId;//飞升类型
		int32_t m_comprehend;//提悟类型
		NFShmString<64> m_exclusive;//提悟专属
		NFShmString<64> m_comprehendSkill;//提悟技能
		NFShmString<64> m_potential;//潜能
		int32_t m_comprehendUpItem;//提悟升品显示
		int32_t m_comprehendType;//提悟属性类型
		int32_t m_ratio;//提悟非百分比属性比例
		int32_t m_ratioPercentage;//提悟百分比属性比例
		NFShmString<64> m_equipSuit;//鲲灵套装
		int32_t m_qualityMax;//鲲灵穿戴最大品质
		NFShmString<64> m_liLianChangeItem;//历练异化鲲掉落
		NFShmVector<struct E_MountHuakunUplvDesc_s, DEFINE_E_MOUNTHUAKUN_M_UPLV_MAX_NUM> m_UpLv;//百分比属性
		NFShmVector<struct E_MountHuakunMaterialDesc_s, DEFINE_E_MOUNTHUAKUN_M_MATERIAL_MAX_NUM> m_material;//升级材料
		NFShmVector<struct E_MountHuakunAdvanceDesc_s, DEFINE_E_MOUNTHUAKUN_M_ADVANCE_MAX_NUM> m_advance;//百分比属性
		NFShmVector<int32_t, DEFINE_E_MOUNTHUAKUN_M_UPSTARITEM_MAX_NUM> m_UpStarItem;//升星需要道具ID
		NFShmVector<NFShmString<64>, DEFINE_E_MOUNTHUAKUN_M_UPSTARNUM_MAX_NUM> m_UpStarNum;//升星总共需要数量
		NFShmVector<struct E_MountHuakunAttributeDesc_s, DEFINE_E_MOUNTHUAKUN_M_ATTRIBUTE_MAX_NUM> m_Attribute;//百分比属性

		virtual void write_to_pbmsg(::proto_ff::E_MountHuakun & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_MountHuakun & msg);
		static ::proto_ff::E_MountHuakun* new_pbmsg(){ return new ::proto_ff::E_MountHuakun(); }
		static ::proto_ff::E_MountHuakun make_pbmsg(){ return ::proto_ff::E_MountHuakun(); }
	};
	typedef struct E_MountHuakun_s E_MountHuakun_t;

	struct Sheet_MountHuakun_s : public NFDescStoreSeqOP {
		Sheet_MountHuakun_s();
		virtual ~Sheet_MountHuakun_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_MountHuakun_s, DEFINE_SHEET_MOUNTHUAKUN_E_MOUNTHUAKUN_LIST_MAX_NUM> E_MountHuakun_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_MountHuakun & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_MountHuakun & msg);
		static ::proto_ff::Sheet_MountHuakun* new_pbmsg(){ return new ::proto_ff::Sheet_MountHuakun(); }
		static ::proto_ff::Sheet_MountHuakun make_pbmsg(){ return ::proto_ff::Sheet_MountHuakun(); }
	};
	typedef struct Sheet_MountHuakun_s Sheet_MountHuakun_t;

	struct E_MountHuakun_valueAttributeDesc_s : public NFDescStoreSeqOP {
		E_MountHuakun_valueAttributeDesc_s();
		virtual ~E_MountHuakun_valueAttributeDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_value;//值
		int32_t m_type;//ID

		virtual void write_to_pbmsg(::proto_ff::E_MountHuakun_valueAttributeDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_MountHuakun_valueAttributeDesc & msg);
		static ::proto_ff::E_MountHuakun_valueAttributeDesc* new_pbmsg(){ return new ::proto_ff::E_MountHuakun_valueAttributeDesc(); }
		static ::proto_ff::E_MountHuakun_valueAttributeDesc make_pbmsg(){ return ::proto_ff::E_MountHuakun_valueAttributeDesc(); }
	};
	typedef struct E_MountHuakun_valueAttributeDesc_s E_MountHuakun_valueAttributeDesc_t;

	struct E_MountHuakun_value_s : public NFDescStoreSeqOP {
		E_MountHuakun_value_s();
		virtual ~E_MountHuakun_value_s(){}
		int CreateInit();
		int ResumeInit();
		int64_t m_id;//id
		int32_t m_huaKunType;//属性类型
		int32_t m_huaKunLv;//等级
		int32_t m_huaKunExp;//升级所需经验
		NFShmVector<struct E_MountHuakun_valueAttributeDesc_s, DEFINE_E_MOUNTHUAKUN_VALUE_M_ATTRIBUTE_MAX_NUM> m_attribute;//基础属性

		virtual void write_to_pbmsg(::proto_ff::E_MountHuakun_value & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_MountHuakun_value & msg);
		static ::proto_ff::E_MountHuakun_value* new_pbmsg(){ return new ::proto_ff::E_MountHuakun_value(); }
		static ::proto_ff::E_MountHuakun_value make_pbmsg(){ return ::proto_ff::E_MountHuakun_value(); }
	};
	typedef struct E_MountHuakun_value_s E_MountHuakun_value_t;

	struct Sheet_MountHuakun_value_s : public NFDescStoreSeqOP {
		Sheet_MountHuakun_value_s();
		virtual ~Sheet_MountHuakun_value_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_MountHuakun_value_s, DEFINE_SHEET_MOUNTHUAKUN_VALUE_E_MOUNTHUAKUN_VALUE_LIST_MAX_NUM> E_MountHuakun_value_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_MountHuakun_value & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_MountHuakun_value & msg);
		static ::proto_ff::Sheet_MountHuakun_value* new_pbmsg(){ return new ::proto_ff::Sheet_MountHuakun_value(); }
		static ::proto_ff::Sheet_MountHuakun_value make_pbmsg(){ return ::proto_ff::Sheet_MountHuakun_value(); }
	};
	typedef struct Sheet_MountHuakun_value_s Sheet_MountHuakun_value_t;

	struct E_MountHuakun_advancevalueItemDesc_s : public NFDescStoreSeqOP {
		E_MountHuakun_advancevalueItemDesc_s();
		virtual ~E_MountHuakun_advancevalueItemDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_Num;//数量
		int32_t m_id;//

		virtual void write_to_pbmsg(::proto_ff::E_MountHuakun_advancevalueItemDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_MountHuakun_advancevalueItemDesc & msg);
		static ::proto_ff::E_MountHuakun_advancevalueItemDesc* new_pbmsg(){ return new ::proto_ff::E_MountHuakun_advancevalueItemDesc(); }
		static ::proto_ff::E_MountHuakun_advancevalueItemDesc make_pbmsg(){ return ::proto_ff::E_MountHuakun_advancevalueItemDesc(); }
	};
	typedef struct E_MountHuakun_advancevalueItemDesc_s E_MountHuakun_advancevalueItemDesc_t;

	struct E_MountHuakun_advancevalue_s : public NFDescStoreSeqOP {
		E_MountHuakun_advancevalue_s();
		virtual ~E_MountHuakun_advancevalue_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//id
		int32_t m_Lv;//等级
		int32_t m_advanceType;//进阶类型
		int32_t m_winProb;//进阶成功概率
		int32_t m_failLv;//进阶失败掉级
		NFShmVector<struct E_MountHuakun_advancevalueItemDesc_s, DEFINE_E_MOUNTHUAKUN_ADVANCEVALUE_M_ITEM_MAX_NUM> m_item;//需求道具

		virtual void write_to_pbmsg(::proto_ff::E_MountHuakun_advancevalue & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_MountHuakun_advancevalue & msg);
		static ::proto_ff::E_MountHuakun_advancevalue* new_pbmsg(){ return new ::proto_ff::E_MountHuakun_advancevalue(); }
		static ::proto_ff::E_MountHuakun_advancevalue make_pbmsg(){ return ::proto_ff::E_MountHuakun_advancevalue(); }
	};
	typedef struct E_MountHuakun_advancevalue_s E_MountHuakun_advancevalue_t;

	struct Sheet_MountHuakun_advancevalue_s : public NFDescStoreSeqOP {
		Sheet_MountHuakun_advancevalue_s();
		virtual ~Sheet_MountHuakun_advancevalue_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_MountHuakun_advancevalue_s, DEFINE_SHEET_MOUNTHUAKUN_ADVANCEVALUE_E_MOUNTHUAKUN_ADVANCEVALUE_LIST_MAX_NUM> E_MountHuakun_advancevalue_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_MountHuakun_advancevalue & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_MountHuakun_advancevalue & msg);
		static ::proto_ff::Sheet_MountHuakun_advancevalue* new_pbmsg(){ return new ::proto_ff::Sheet_MountHuakun_advancevalue(); }
		static ::proto_ff::Sheet_MountHuakun_advancevalue make_pbmsg(){ return ::proto_ff::Sheet_MountHuakun_advancevalue(); }
	};
	typedef struct Sheet_MountHuakun_advancevalue_s Sheet_MountHuakun_advancevalue_t;

	struct E_MountHuakun_changeAttributeDesc_s : public NFDescStoreSeqOP {
		E_MountHuakun_changeAttributeDesc_s();
		virtual ~E_MountHuakun_changeAttributeDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_UpValue;//值
		int32_t m_UpBer;//

		virtual void write_to_pbmsg(::proto_ff::E_MountHuakun_changeAttributeDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_MountHuakun_changeAttributeDesc & msg);
		static ::proto_ff::E_MountHuakun_changeAttributeDesc* new_pbmsg(){ return new ::proto_ff::E_MountHuakun_changeAttributeDesc(); }
		static ::proto_ff::E_MountHuakun_changeAttributeDesc make_pbmsg(){ return ::proto_ff::E_MountHuakun_changeAttributeDesc(); }
	};
	typedef struct E_MountHuakun_changeAttributeDesc_s E_MountHuakun_changeAttributeDesc_t;

	struct E_MountHuakun_change_s : public NFDescStoreSeqOP {
		E_MountHuakun_change_s();
		virtual ~E_MountHuakun_change_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//id
		int32_t m_huaKunId;//名称
		int32_t m_speed;//默认乘骑速度值
		NFShmString<64> m_fxID;//幻化特效
		int32_t m_ModelID;//模型id
		int32_t m_activationItem;//激活需要的道具
		int32_t m_activationNum;//激活需要的道具数量
		int32_t m_starAttributeId;//升星类型
		int32_t m_starMax;//星星上限
		int32_t m_starId;//升星需要道具ID
		NFShmString<64> m_starNum;//升星需要数量
		int32_t m_starBer;//每星级提升百分比
		int32_t m_changeAttributeId;//异化飞升类型
		NFShmVector<struct E_MountHuakun_changeAttributeDesc_s, DEFINE_E_MOUNTHUAKUN_CHANGE_M_ATTRIBUTE_MAX_NUM> m_Attribute;//百分比属性

		virtual void write_to_pbmsg(::proto_ff::E_MountHuakun_change & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_MountHuakun_change & msg);
		static ::proto_ff::E_MountHuakun_change* new_pbmsg(){ return new ::proto_ff::E_MountHuakun_change(); }
		static ::proto_ff::E_MountHuakun_change make_pbmsg(){ return ::proto_ff::E_MountHuakun_change(); }
	};
	typedef struct E_MountHuakun_change_s E_MountHuakun_change_t;

	struct Sheet_MountHuakun_change_s : public NFDescStoreSeqOP {
		Sheet_MountHuakun_change_s();
		virtual ~Sheet_MountHuakun_change_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_MountHuakun_change_s, DEFINE_SHEET_MOUNTHUAKUN_CHANGE_E_MOUNTHUAKUN_CHANGE_LIST_MAX_NUM> E_MountHuakun_change_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_MountHuakun_change & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_MountHuakun_change & msg);
		static ::proto_ff::Sheet_MountHuakun_change* new_pbmsg(){ return new ::proto_ff::Sheet_MountHuakun_change(); }
		static ::proto_ff::Sheet_MountHuakun_change make_pbmsg(){ return ::proto_ff::Sheet_MountHuakun_change(); }
	};
	typedef struct Sheet_MountHuakun_change_s Sheet_MountHuakun_change_t;

	struct E_MountHuakun_advanceUpattributeDesc_s : public NFDescStoreSeqOP {
		E_MountHuakun_advanceUpattributeDesc_s();
		virtual ~E_MountHuakun_advanceUpattributeDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_value;//值
		int32_t m_type;//ID

		virtual void write_to_pbmsg(::proto_ff::E_MountHuakun_advanceUpattributeDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_MountHuakun_advanceUpattributeDesc & msg);
		static ::proto_ff::E_MountHuakun_advanceUpattributeDesc* new_pbmsg(){ return new ::proto_ff::E_MountHuakun_advanceUpattributeDesc(); }
		static ::proto_ff::E_MountHuakun_advanceUpattributeDesc make_pbmsg(){ return ::proto_ff::E_MountHuakun_advanceUpattributeDesc(); }
	};
	typedef struct E_MountHuakun_advanceUpattributeDesc_s E_MountHuakun_advanceUpattributeDesc_t;

	struct E_MountHuakun_advance_s : public NFDescStoreSeqOP {
		E_MountHuakun_advance_s();
		virtual ~E_MountHuakun_advance_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//id
		int32_t m_upAttributeId;//进阶类型
		int32_t m_starID;//进阶专属需求星星数量
		int32_t m_skillID;//进阶专属技能
		NFShmVector<struct E_MountHuakun_advanceUpattributeDesc_s, DEFINE_E_MOUNTHUAKUN_ADVANCE_M_UPATTRIBUTE_MAX_NUM> m_upAttribute;//激活属性

		virtual void write_to_pbmsg(::proto_ff::E_MountHuakun_advance & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_MountHuakun_advance & msg);
		static ::proto_ff::E_MountHuakun_advance* new_pbmsg(){ return new ::proto_ff::E_MountHuakun_advance(); }
		static ::proto_ff::E_MountHuakun_advance make_pbmsg(){ return ::proto_ff::E_MountHuakun_advance(); }
	};
	typedef struct E_MountHuakun_advance_s E_MountHuakun_advance_t;

	struct Sheet_MountHuakun_advance_s : public NFDescStoreSeqOP {
		Sheet_MountHuakun_advance_s();
		virtual ~Sheet_MountHuakun_advance_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_MountHuakun_advance_s, DEFINE_SHEET_MOUNTHUAKUN_ADVANCE_E_MOUNTHUAKUN_ADVANCE_LIST_MAX_NUM> E_MountHuakun_advance_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_MountHuakun_advance & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_MountHuakun_advance & msg);
		static ::proto_ff::Sheet_MountHuakun_advance* new_pbmsg(){ return new ::proto_ff::Sheet_MountHuakun_advance(); }
		static ::proto_ff::Sheet_MountHuakun_advance make_pbmsg(){ return ::proto_ff::Sheet_MountHuakun_advance(); }
	};
	typedef struct Sheet_MountHuakun_advance_s Sheet_MountHuakun_advance_t;

	struct E_MountBloodAttributeDesc_s : public NFDescStoreSeqOP {
		E_MountBloodAttributeDesc_s();
		virtual ~E_MountBloodAttributeDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_value;//数值
		int32_t m_type;//

		virtual void write_to_pbmsg(::proto_ff::E_MountBloodAttributeDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_MountBloodAttributeDesc & msg);
		static ::proto_ff::E_MountBloodAttributeDesc* new_pbmsg(){ return new ::proto_ff::E_MountBloodAttributeDesc(); }
		static ::proto_ff::E_MountBloodAttributeDesc make_pbmsg(){ return ::proto_ff::E_MountBloodAttributeDesc(); }
	};
	typedef struct E_MountBloodAttributeDesc_s E_MountBloodAttributeDesc_t;

	struct E_MountBlood_s : public NFDescStoreSeqOP {
		E_MountBlood_s();
		virtual ~E_MountBlood_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//星数
		NFShmVector<struct E_MountBloodAttributeDesc_s, DEFINE_E_MOUNTBLOOD_M_ATTRIBUTE_MAX_NUM> m_attribute;//基础属性

		virtual void write_to_pbmsg(::proto_ff::E_MountBlood & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_MountBlood & msg);
		static ::proto_ff::E_MountBlood* new_pbmsg(){ return new ::proto_ff::E_MountBlood(); }
		static ::proto_ff::E_MountBlood make_pbmsg(){ return ::proto_ff::E_MountBlood(); }
	};
	typedef struct E_MountBlood_s E_MountBlood_t;

	struct Sheet_MountBlood_s : public NFDescStoreSeqOP {
		Sheet_MountBlood_s();
		virtual ~Sheet_MountBlood_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_MountBlood_s, DEFINE_SHEET_MOUNTBLOOD_E_MOUNTBLOOD_LIST_MAX_NUM> E_MountBlood_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_MountBlood & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_MountBlood & msg);
		static ::proto_ff::Sheet_MountBlood* new_pbmsg(){ return new ::proto_ff::Sheet_MountBlood(); }
		static ::proto_ff::Sheet_MountBlood make_pbmsg(){ return ::proto_ff::Sheet_MountBlood(); }
	};
	typedef struct Sheet_MountBlood_s Sheet_MountBlood_t;

	struct E_MountHuakun_equip_s : public NFDescStoreSeqOP {
		E_MountHuakun_equip_s();
		virtual ~E_MountHuakun_equip_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_equipId;//id
		int32_t m_part;//部位
		int32_t m_quality;//品质
		int32_t m_equipIntensify;//强化类型
		int32_t m_srtongUp;//强化上限
		int32_t m_advanceIntensify;//进阶类型
		int32_t m_equipTtop;//突破类型
		int32_t m_resolve;//鲲灵分解材料
		int32_t m_resolveMun;//分解数量

		virtual void write_to_pbmsg(::proto_ff::E_MountHuakun_equip & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_MountHuakun_equip & msg);
		static ::proto_ff::E_MountHuakun_equip* new_pbmsg(){ return new ::proto_ff::E_MountHuakun_equip(); }
		static ::proto_ff::E_MountHuakun_equip make_pbmsg(){ return ::proto_ff::E_MountHuakun_equip(); }
	};
	typedef struct E_MountHuakun_equip_s E_MountHuakun_equip_t;

	struct Sheet_MountHuakun_equip_s : public NFDescStoreSeqOP {
		Sheet_MountHuakun_equip_s();
		virtual ~Sheet_MountHuakun_equip_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_MountHuakun_equip_s, DEFINE_SHEET_MOUNTHUAKUN_EQUIP_E_MOUNTHUAKUN_EQUIP_LIST_MAX_NUM> E_MountHuakun_equip_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_MountHuakun_equip & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_MountHuakun_equip & msg);
		static ::proto_ff::Sheet_MountHuakun_equip* new_pbmsg(){ return new ::proto_ff::Sheet_MountHuakun_equip(); }
		static ::proto_ff::Sheet_MountHuakun_equip make_pbmsg(){ return ::proto_ff::Sheet_MountHuakun_equip(); }
	};
	typedef struct Sheet_MountHuakun_equip_s Sheet_MountHuakun_equip_t;

	struct E_MountEquip_valueAttributeDesc_s : public NFDescStoreSeqOP {
		E_MountEquip_valueAttributeDesc_s();
		virtual ~E_MountEquip_valueAttributeDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_value;//值
		int32_t m_type;//

		virtual void write_to_pbmsg(::proto_ff::E_MountEquip_valueAttributeDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_MountEquip_valueAttributeDesc & msg);
		static ::proto_ff::E_MountEquip_valueAttributeDesc* new_pbmsg(){ return new ::proto_ff::E_MountEquip_valueAttributeDesc(); }
		static ::proto_ff::E_MountEquip_valueAttributeDesc make_pbmsg(){ return ::proto_ff::E_MountEquip_valueAttributeDesc(); }
	};
	typedef struct E_MountEquip_valueAttributeDesc_s E_MountEquip_valueAttributeDesc_t;

	struct E_MountEquip_value_s : public NFDescStoreSeqOP {
		E_MountEquip_value_s();
		virtual ~E_MountEquip_value_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_equipIntensify;//id
		int32_t m_equipValue;//属性类型
		int32_t m_equipLv;//等级
		int32_t m_equipItem;//道具消耗
		int32_t m_equipMun;//消耗数量
		NFShmVector<struct E_MountEquip_valueAttributeDesc_s, DEFINE_E_MOUNTEQUIP_VALUE_M_ATTRIBUTE_MAX_NUM> m_Attribute;//属性

		virtual void write_to_pbmsg(::proto_ff::E_MountEquip_value & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_MountEquip_value & msg);
		static ::proto_ff::E_MountEquip_value* new_pbmsg(){ return new ::proto_ff::E_MountEquip_value(); }
		static ::proto_ff::E_MountEquip_value make_pbmsg(){ return ::proto_ff::E_MountEquip_value(); }
	};
	typedef struct E_MountEquip_value_s E_MountEquip_value_t;

	struct Sheet_MountEquip_value_s : public NFDescStoreSeqOP {
		Sheet_MountEquip_value_s();
		virtual ~Sheet_MountEquip_value_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_MountEquip_value_s, DEFINE_SHEET_MOUNTEQUIP_VALUE_E_MOUNTEQUIP_VALUE_LIST_MAX_NUM> E_MountEquip_value_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_MountEquip_value & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_MountEquip_value & msg);
		static ::proto_ff::Sheet_MountEquip_value* new_pbmsg(){ return new ::proto_ff::Sheet_MountEquip_value(); }
		static ::proto_ff::Sheet_MountEquip_value make_pbmsg(){ return ::proto_ff::Sheet_MountEquip_value(); }
	};
	typedef struct Sheet_MountEquip_value_s Sheet_MountEquip_value_t;

	struct E_MountEquipsuitAttributeDesc_s : public NFDescStoreSeqOP {
		E_MountEquipsuitAttributeDesc_s();
		virtual ~E_MountEquipsuitAttributeDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_value;//值
		int32_t m_type;//

		virtual void write_to_pbmsg(::proto_ff::E_MountEquipsuitAttributeDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_MountEquipsuitAttributeDesc & msg);
		static ::proto_ff::E_MountEquipsuitAttributeDesc* new_pbmsg(){ return new ::proto_ff::E_MountEquipsuitAttributeDesc(); }
		static ::proto_ff::E_MountEquipsuitAttributeDesc make_pbmsg(){ return ::proto_ff::E_MountEquipsuitAttributeDesc(); }
	};
	typedef struct E_MountEquipsuitAttributeDesc_s E_MountEquipsuitAttributeDesc_t;

	struct E_MountEquipsuit_s : public NFDescStoreSeqOP {
		E_MountEquipsuit_s();
		virtual ~E_MountEquipsuit_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//id
		int32_t m_quality;//要求品质
		int32_t m_piece;//套装件数
		NFShmVector<struct E_MountEquipsuitAttributeDesc_s, DEFINE_E_MOUNTEQUIPSUIT_M_ATTRIBUTE_MAX_NUM> m_Attribute;//属性

		virtual void write_to_pbmsg(::proto_ff::E_MountEquipsuit & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_MountEquipsuit & msg);
		static ::proto_ff::E_MountEquipsuit* new_pbmsg(){ return new ::proto_ff::E_MountEquipsuit(); }
		static ::proto_ff::E_MountEquipsuit make_pbmsg(){ return ::proto_ff::E_MountEquipsuit(); }
	};
	typedef struct E_MountEquipsuit_s E_MountEquipsuit_t;

	struct Sheet_MountEquipsuit_s : public NFDescStoreSeqOP {
		Sheet_MountEquipsuit_s();
		virtual ~Sheet_MountEquipsuit_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_MountEquipsuit_s, DEFINE_SHEET_MOUNTEQUIPSUIT_E_MOUNTEQUIPSUIT_LIST_MAX_NUM> E_MountEquipsuit_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_MountEquipsuit & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_MountEquipsuit & msg);
		static ::proto_ff::Sheet_MountEquipsuit* new_pbmsg(){ return new ::proto_ff::Sheet_MountEquipsuit(); }
		static ::proto_ff::Sheet_MountEquipsuit make_pbmsg(){ return ::proto_ff::Sheet_MountEquipsuit(); }
	};
	typedef struct Sheet_MountEquipsuit_s Sheet_MountEquipsuit_t;

	struct E_MountEquiptopTopDesc_s : public NFDescStoreSeqOP {
		E_MountEquiptopTopDesc_s();
		virtual ~E_MountEquiptopTopDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_value;//值
		int32_t m_type;//属性

		virtual void write_to_pbmsg(::proto_ff::E_MountEquiptopTopDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_MountEquiptopTopDesc & msg);
		static ::proto_ff::E_MountEquiptopTopDesc* new_pbmsg(){ return new ::proto_ff::E_MountEquiptopTopDesc(); }
		static ::proto_ff::E_MountEquiptopTopDesc make_pbmsg(){ return ::proto_ff::E_MountEquiptopTopDesc(); }
	};
	typedef struct E_MountEquiptopTopDesc_s E_MountEquiptopTopDesc_t;

	struct E_MountEquiptopPercentDesc_s : public NFDescStoreSeqOP {
		E_MountEquiptopPercentDesc_s();
		virtual ~E_MountEquiptopPercentDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_value;//值
		int32_t m_type;//属性

		virtual void write_to_pbmsg(::proto_ff::E_MountEquiptopPercentDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_MountEquiptopPercentDesc & msg);
		static ::proto_ff::E_MountEquiptopPercentDesc* new_pbmsg(){ return new ::proto_ff::E_MountEquiptopPercentDesc(); }
		static ::proto_ff::E_MountEquiptopPercentDesc make_pbmsg(){ return ::proto_ff::E_MountEquiptopPercentDesc(); }
	};
	typedef struct E_MountEquiptopPercentDesc_s E_MountEquiptopPercentDesc_t;

	struct E_MountEquiptop_s : public NFDescStoreSeqOP {
		E_MountEquiptop_s();
		virtual ~E_MountEquiptop_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//id
		int32_t m_positionId;//装备部位id
		int32_t m_equipTtop;//突破类型
		int32_t m_quality;//品质
		NFShmVector<struct E_MountEquiptopTopDesc_s, DEFINE_E_MOUNTEQUIPTOP_M_TOP_MAX_NUM> m_top;//非百分比
		NFShmVector<struct E_MountEquiptopPercentDesc_s, DEFINE_E_MOUNTEQUIPTOP_M_PERCENT_MAX_NUM> m_percent;//百分比

		virtual void write_to_pbmsg(::proto_ff::E_MountEquiptop & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_MountEquiptop & msg);
		static ::proto_ff::E_MountEquiptop* new_pbmsg(){ return new ::proto_ff::E_MountEquiptop(); }
		static ::proto_ff::E_MountEquiptop make_pbmsg(){ return ::proto_ff::E_MountEquiptop(); }
	};
	typedef struct E_MountEquiptop_s E_MountEquiptop_t;

	struct Sheet_MountEquiptop_s : public NFDescStoreSeqOP {
		Sheet_MountEquiptop_s();
		virtual ~Sheet_MountEquiptop_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_MountEquiptop_s, DEFINE_SHEET_MOUNTEQUIPTOP_E_MOUNTEQUIPTOP_LIST_MAX_NUM> E_MountEquiptop_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_MountEquiptop & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_MountEquiptop & msg);
		static ::proto_ff::Sheet_MountEquiptop* new_pbmsg(){ return new ::proto_ff::Sheet_MountEquiptop(); }
		static ::proto_ff::Sheet_MountEquiptop make_pbmsg(){ return ::proto_ff::Sheet_MountEquiptop(); }
	};
	typedef struct Sheet_MountEquiptop_s Sheet_MountEquiptop_t;

	struct E_MountEquiptopvalue_s : public NFDescStoreSeqOP {
		E_MountEquiptopvalue_s();
		virtual ~E_MountEquiptopvalue_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//id
		int32_t m_quality;//鲲灵品质
		int32_t m_top;//鲲灵突破
		int32_t m_value;//初始进度值

		virtual void write_to_pbmsg(::proto_ff::E_MountEquiptopvalue & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_MountEquiptopvalue & msg);
		static ::proto_ff::E_MountEquiptopvalue* new_pbmsg(){ return new ::proto_ff::E_MountEquiptopvalue(); }
		static ::proto_ff::E_MountEquiptopvalue make_pbmsg(){ return ::proto_ff::E_MountEquiptopvalue(); }
	};
	typedef struct E_MountEquiptopvalue_s E_MountEquiptopvalue_t;

	struct Sheet_MountEquiptopvalue_s : public NFDescStoreSeqOP {
		Sheet_MountEquiptopvalue_s();
		virtual ~Sheet_MountEquiptopvalue_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_MountEquiptopvalue_s, DEFINE_SHEET_MOUNTEQUIPTOPVALUE_E_MOUNTEQUIPTOPVALUE_LIST_MAX_NUM> E_MountEquiptopvalue_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_MountEquiptopvalue & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_MountEquiptopvalue & msg);
		static ::proto_ff::Sheet_MountEquiptopvalue* new_pbmsg(){ return new ::proto_ff::Sheet_MountEquiptopvalue(); }
		static ::proto_ff::Sheet_MountEquiptopvalue make_pbmsg(){ return ::proto_ff::Sheet_MountEquiptopvalue(); }
	};
	typedef struct Sheet_MountEquiptopvalue_s Sheet_MountEquiptopvalue_t;

	struct E_MountEquippart_s : public NFDescStoreSeqOP {
		E_MountEquippart_s();
		virtual ~E_MountEquippart_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_part;//部位
		int32_t m_quality;//化鲲品质
		int32_t m_honeOpen;//部位解锁类型
		int32_t m_item;//所需物品
		int32_t m_num;//数量

		virtual void write_to_pbmsg(::proto_ff::E_MountEquippart & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_MountEquippart & msg);
		static ::proto_ff::E_MountEquippart* new_pbmsg(){ return new ::proto_ff::E_MountEquippart(); }
		static ::proto_ff::E_MountEquippart make_pbmsg(){ return ::proto_ff::E_MountEquippart(); }
	};
	typedef struct E_MountEquippart_s E_MountEquippart_t;

	struct Sheet_MountEquippart_s : public NFDescStoreSeqOP {
		Sheet_MountEquippart_s();
		virtual ~Sheet_MountEquippart_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_MountEquippart_s, DEFINE_SHEET_MOUNTEQUIPPART_E_MOUNTEQUIPPART_LIST_MAX_NUM> E_MountEquippart_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_MountEquippart & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_MountEquippart & msg);
		static ::proto_ff::Sheet_MountEquippart* new_pbmsg(){ return new ::proto_ff::Sheet_MountEquippart(); }
		static ::proto_ff::Sheet_MountEquippart make_pbmsg(){ return ::proto_ff::Sheet_MountEquippart(); }
	};
	typedef struct Sheet_MountEquippart_s Sheet_MountEquippart_t;

	struct E_MountEmpowermenttour_debris_s : public NFDescStoreSeqOP {
		E_MountEmpowermenttour_debris_s();
		virtual ~E_MountEmpowermenttour_debris_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_fairylandId;//仙境id
		int32_t m_fairylandNextId;//下一个仙境id
		NFShmString<64> m_fairylandSkin;//仙境获取皮肤预览

		virtual void write_to_pbmsg(::proto_ff::E_MountEmpowermenttour_debris & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_MountEmpowermenttour_debris & msg);
		static ::proto_ff::E_MountEmpowermenttour_debris* new_pbmsg(){ return new ::proto_ff::E_MountEmpowermenttour_debris(); }
		static ::proto_ff::E_MountEmpowermenttour_debris make_pbmsg(){ return ::proto_ff::E_MountEmpowermenttour_debris(); }
	};
	typedef struct E_MountEmpowermenttour_debris_s E_MountEmpowermenttour_debris_t;

	struct Sheet_MountEmpowermenttour_debris_s : public NFDescStoreSeqOP {
		Sheet_MountEmpowermenttour_debris_s();
		virtual ~Sheet_MountEmpowermenttour_debris_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_MountEmpowermenttour_debris_s, DEFINE_SHEET_MOUNTEMPOWERMENTTOUR_DEBRIS_E_MOUNTEMPOWERMENTTOUR_DEBRIS_LIST_MAX_NUM> E_MountEmpowermenttour_debris_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_MountEmpowermenttour_debris & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_MountEmpowermenttour_debris & msg);
		static ::proto_ff::Sheet_MountEmpowermenttour_debris* new_pbmsg(){ return new ::proto_ff::Sheet_MountEmpowermenttour_debris(); }
		static ::proto_ff::Sheet_MountEmpowermenttour_debris make_pbmsg(){ return ::proto_ff::Sheet_MountEmpowermenttour_debris(); }
	};
	typedef struct Sheet_MountEmpowermenttour_debris_s Sheet_MountEmpowermenttour_debris_t;

	struct E_MountEmpowermentTourDesc_s : public NFDescStoreSeqOP {
		E_MountEmpowermentTourDesc_s();
		virtual ~E_MountEmpowermentTourDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_value;//数值
		int32_t m_type;//类型

		virtual void write_to_pbmsg(::proto_ff::E_MountEmpowermentTourDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_MountEmpowermentTourDesc & msg);
		static ::proto_ff::E_MountEmpowermentTourDesc* new_pbmsg(){ return new ::proto_ff::E_MountEmpowermentTourDesc(); }
		static ::proto_ff::E_MountEmpowermentTourDesc make_pbmsg(){ return ::proto_ff::E_MountEmpowermentTourDesc(); }
	};
	typedef struct E_MountEmpowermentTourDesc_s E_MountEmpowermentTourDesc_t;

	struct E_MountEmpowerment_s : public NFDescStoreSeqOP {
		E_MountEmpowerment_s();
		virtual ~E_MountEmpowerment_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_tourId;//游记id
		int32_t m_fairylandId;//仙境id
		int32_t m_tourItem;//碎片id
		int32_t m_tourDebris;//游记总碎片
		NFShmVector<struct E_MountEmpowermentTourDesc_s, DEFINE_E_MOUNTEMPOWERMENT_M_TOUR_MAX_NUM> m_tour;//游记属性

		virtual void write_to_pbmsg(::proto_ff::E_MountEmpowerment & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_MountEmpowerment & msg);
		static ::proto_ff::E_MountEmpowerment* new_pbmsg(){ return new ::proto_ff::E_MountEmpowerment(); }
		static ::proto_ff::E_MountEmpowerment make_pbmsg(){ return ::proto_ff::E_MountEmpowerment(); }
	};
	typedef struct E_MountEmpowerment_s E_MountEmpowerment_t;

	struct Sheet_MountEmpowerment_s : public NFDescStoreSeqOP {
		Sheet_MountEmpowerment_s();
		virtual ~Sheet_MountEmpowerment_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_MountEmpowerment_s, DEFINE_SHEET_MOUNTEMPOWERMENT_E_MOUNTEMPOWERMENT_LIST_MAX_NUM> E_MountEmpowerment_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_MountEmpowerment & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_MountEmpowerment & msg);
		static ::proto_ff::Sheet_MountEmpowerment* new_pbmsg(){ return new ::proto_ff::Sheet_MountEmpowerment(); }
		static ::proto_ff::Sheet_MountEmpowerment make_pbmsg(){ return ::proto_ff::Sheet_MountEmpowerment(); }
	};
	typedef struct Sheet_MountEmpowerment_s Sheet_MountEmpowerment_t;

	struct E_MountEmpowerment_position_s : public NFDescStoreSeqOP {
		E_MountEmpowerment_position_s();
		virtual ~E_MountEmpowerment_position_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_empowermentSlot;//历练槽位
		int32_t m_unlockTime;//解锁条件
		int32_t m_unlockNum;//解锁数量

		virtual void write_to_pbmsg(::proto_ff::E_MountEmpowerment_position & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_MountEmpowerment_position & msg);
		static ::proto_ff::E_MountEmpowerment_position* new_pbmsg(){ return new ::proto_ff::E_MountEmpowerment_position(); }
		static ::proto_ff::E_MountEmpowerment_position make_pbmsg(){ return ::proto_ff::E_MountEmpowerment_position(); }
	};
	typedef struct E_MountEmpowerment_position_s E_MountEmpowerment_position_t;

	struct Sheet_MountEmpowerment_position_s : public NFDescStoreSeqOP {
		Sheet_MountEmpowerment_position_s();
		virtual ~Sheet_MountEmpowerment_position_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_MountEmpowerment_position_s, DEFINE_SHEET_MOUNTEMPOWERMENT_POSITION_E_MOUNTEMPOWERMENT_POSITION_LIST_MAX_NUM> E_MountEmpowerment_position_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_MountEmpowerment_position & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_MountEmpowerment_position & msg);
		static ::proto_ff::Sheet_MountEmpowerment_position* new_pbmsg(){ return new ::proto_ff::Sheet_MountEmpowerment_position(); }
		static ::proto_ff::Sheet_MountEmpowerment_position make_pbmsg(){ return ::proto_ff::Sheet_MountEmpowerment_position(); }
	};
	typedef struct Sheet_MountEmpowerment_position_s Sheet_MountEmpowerment_position_t;

	struct E_MountEmpowerment_slot_s : public NFDescStoreSeqOP {
		E_MountEmpowerment_slot_s();
		virtual ~E_MountEmpowerment_slot_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//id
		int32_t m_dissociateLevel;//游历级别
		int32_t m_dissociateTime;//时间档位
		int32_t m_dissociateHour;//时长
		int32_t m_dissociateItem;//游离级别消耗
		int32_t m_dissociateNum;//消耗数量
		NFShmString<64> m_eventTime;//播放事件时间间隔范围
		int32_t m_dissociateBox;//服务器奖励

		virtual void write_to_pbmsg(::proto_ff::E_MountEmpowerment_slot & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_MountEmpowerment_slot & msg);
		static ::proto_ff::E_MountEmpowerment_slot* new_pbmsg(){ return new ::proto_ff::E_MountEmpowerment_slot(); }
		static ::proto_ff::E_MountEmpowerment_slot make_pbmsg(){ return ::proto_ff::E_MountEmpowerment_slot(); }
	};
	typedef struct E_MountEmpowerment_slot_s E_MountEmpowerment_slot_t;

	struct Sheet_MountEmpowerment_slot_s : public NFDescStoreSeqOP {
		Sheet_MountEmpowerment_slot_s();
		virtual ~Sheet_MountEmpowerment_slot_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_MountEmpowerment_slot_s, DEFINE_SHEET_MOUNTEMPOWERMENT_SLOT_E_MOUNTEMPOWERMENT_SLOT_LIST_MAX_NUM> E_MountEmpowerment_slot_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_MountEmpowerment_slot & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_MountEmpowerment_slot & msg);
		static ::proto_ff::Sheet_MountEmpowerment_slot* new_pbmsg(){ return new ::proto_ff::Sheet_MountEmpowerment_slot(); }
		static ::proto_ff::Sheet_MountEmpowerment_slot make_pbmsg(){ return ::proto_ff::Sheet_MountEmpowerment_slot(); }
	};
	typedef struct Sheet_MountEmpowerment_slot_s Sheet_MountEmpowerment_slot_t;

	struct E_MountEmpowerment_event_s : public NFDescStoreSeqOP {
		E_MountEmpowerment_event_s();
		virtual ~E_MountEmpowerment_event_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//id
		int32_t m_eventType;//类型
		int32_t m_weight;//权重

		virtual void write_to_pbmsg(::proto_ff::E_MountEmpowerment_event & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_MountEmpowerment_event & msg);
		static ::proto_ff::E_MountEmpowerment_event* new_pbmsg(){ return new ::proto_ff::E_MountEmpowerment_event(); }
		static ::proto_ff::E_MountEmpowerment_event make_pbmsg(){ return ::proto_ff::E_MountEmpowerment_event(); }
	};
	typedef struct E_MountEmpowerment_event_s E_MountEmpowerment_event_t;

	struct Sheet_MountEmpowerment_event_s : public NFDescStoreSeqOP {
		Sheet_MountEmpowerment_event_s();
		virtual ~Sheet_MountEmpowerment_event_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_MountEmpowerment_event_s, DEFINE_SHEET_MOUNTEMPOWERMENT_EVENT_E_MOUNTEMPOWERMENT_EVENT_LIST_MAX_NUM> E_MountEmpowerment_event_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_MountEmpowerment_event & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_MountEmpowerment_event & msg);
		static ::proto_ff::Sheet_MountEmpowerment_event* new_pbmsg(){ return new ::proto_ff::Sheet_MountEmpowerment_event(); }
		static ::proto_ff::Sheet_MountEmpowerment_event make_pbmsg(){ return ::proto_ff::Sheet_MountEmpowerment_event(); }
	};
	typedef struct Sheet_MountEmpowerment_event_s Sheet_MountEmpowerment_event_t;

}

