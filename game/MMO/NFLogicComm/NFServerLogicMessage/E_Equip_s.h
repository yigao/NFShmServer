#pragma once

#include <stdint.h>
#include <NFComm/NFShmStl/NFShmString.h>
#include <NFComm/NFShmStl/NFShmVector.h>
#include <NFComm/NFShmCore/NFSeqOP.h>
#include <NFComm/NFShmCore/NFShmMgr.h>
#include "E_Equip.pb.h"
#include "E_Equip_s.h"

#define DEFINE_SHEET_EQUIPEQUIP_E_EQUIPEQUIP_LIST_MAX_NUM 16384
#define DEFINE_E_EQUIPATTRIBUTE_M_ATTRIBUTE_MAX_NUM 11
#define DEFINE_E_EQUIPATTRIBUTE_M_STAR_LIBRARY_MAX_NUM 7
#define DEFINE_SHEET_EQUIPATTRIBUTE_E_EQUIPATTRIBUTE_LIST_MAX_NUM 16384
#define DEFINE_E_EQUIPSPECATT_M_ATTRIBUTE_MAX_NUM 5
#define DEFINE_SHEET_EQUIPSPECATT_E_EQUIPSPECATT_LIST_MAX_NUM 128
#define DEFINE_E_EQUIPSTRONG_M_TYPE_MAX_NUM 4
#define DEFINE_SHEET_EQUIPSTRONG_E_EQUIPSTRONG_LIST_MAX_NUM 2048
#define DEFINE_E_EQUIPSTRONGEXP_M_POSITIONTYPE_MAX_NUM 3
#define DEFINE_E_EQUIPSTRONGEXP_M_COST_MAX_NUM 3
#define DEFINE_SHEET_EQUIPSTRONGEXP_E_EQUIPSTRONGEXP_LIST_MAX_NUM 512
#define DEFINE_E_EQUIPBEASTSTRONG_M_TYPE_MAX_NUM 3
#define DEFINE_SHEET_EQUIPBEASTSTRONG_E_EQUIPBEASTSTRONG_LIST_MAX_NUM 128
#define DEFINE_E_EQUIPSTRONGTOTAL_M_ATTRIBUTE_MAX_NUM 4
#define DEFINE_SHEET_EQUIPSTRONGTOTAL_E_EQUIPSTRONGTOTAL_LIST_MAX_NUM 256
#define DEFINE_E_EQUIPGEM_M_GEMUNLOCK_MAX_NUM 4
#define DEFINE_SHEET_EQUIPGEM_E_EQUIPGEM_LIST_MAX_NUM 16
#define DEFINE_SHEET_EQUIPGEMLV_E_EQUIPGEMLV_LIST_MAX_NUM 512
#define DEFINE_E_EQUIPSTOVEATT_M_ATTRIBUTE_MAX_NUM 4
#define DEFINE_SHEET_EQUIPSTOVEATT_E_EQUIPSTOVEATT_LIST_MAX_NUM 2048
#define DEFINE_SHEET_EQUIPSTOVEEXP_E_EQUIPSTOVEEXP_LIST_MAX_NUM 128
#define DEFINE_SHEET_EQUIPGRADE_E_EQUIPGRADE_LIST_MAX_NUM 32
#define DEFINE_E_EQUIPCLEAR_M_ATTRIBUTE_MAX_NUM 3
#define DEFINE_E_EQUIPCLEAR_M_SECTION_MAX_NUM 6
#define DEFINE_SHEET_EQUIPCLEAR_E_EQUIPCLEAR_LIST_MAX_NUM 16
#define DEFINE_E_EQUIPSUIT_M_ATTRIBUTE_MAX_NUM 3
#define DEFINE_E_EQUIPSUIT_M_MALEPOSITION_MAX_NUM 10
#define DEFINE_E_EQUIPSUIT_M_FEMALEPOSITION_MAX_NUM 10
#define DEFINE_SHEET_EQUIPSUIT_E_EQUIPSUIT_LIST_MAX_NUM 64
#define DEFINE_E_EQUIPBREAK_M_BREAK_MAX_NUM 2
#define DEFINE_SHEET_EQUIPBREAK_E_EQUIPBREAK_LIST_MAX_NUM 32


namespace proto_ff_s {

	struct E_EquipEquip_s : public NFDescStoreSeqOP {
		E_EquipEquip_s();
		virtual ~E_EquipEquip_s(){}
		int CreateInit();
		int ResumeInit();
		int64_t m_id;//装备ID
		NFShmString<64> m_name;//装备名称
		int32_t m_type;//装备大类
		int32_t m_wearQuality;//装备品阶
		int32_t m_position;//装备位置
		NFShmString<64> m_profession;//职业限制
		int32_t m_professionLv;//转职等级
		int32_t m_level;//穿戴等级限制
		int32_t m_quality;//装备品质
		int32_t m_attributeID;//属性ID
		int32_t m_star;//装备星级
		int32_t m_notCompose;//不参与合成
		int32_t m_isCanbind;//是否绑定
		int32_t m_isTradeBind;//是否交易绑定
		int32_t m_sellPrice;//出售价格
		NFShmString<64> m_icon;//装备图标名
		int32_t m_time;//限时装备
		int32_t m_broadcast;//是否播放跑马灯
		NFShmString<64> m_meltingResult;//熔炼产出
		NFShmString<64> m_skillId;//附带技能
		int32_t m_privilegeGroupId;//特权组ID

		virtual void write_to_pbmsg(::proto_ff::E_EquipEquip & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_EquipEquip & msg);
		static ::proto_ff::E_EquipEquip* new_pbmsg(){ return new ::proto_ff::E_EquipEquip(); }
		static ::proto_ff::E_EquipEquip make_pbmsg(){ return ::proto_ff::E_EquipEquip(); }
	};
	typedef struct E_EquipEquip_s E_EquipEquip_t;

	struct Sheet_EquipEquip_s : public NFDescStoreSeqOP {
		Sheet_EquipEquip_s();
		virtual ~Sheet_EquipEquip_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_EquipEquip_s, DEFINE_SHEET_EQUIPEQUIP_E_EQUIPEQUIP_LIST_MAX_NUM> E_EquipEquip_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_EquipEquip & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_EquipEquip & msg);
		static ::proto_ff::Sheet_EquipEquip* new_pbmsg(){ return new ::proto_ff::Sheet_EquipEquip(); }
		static ::proto_ff::Sheet_EquipEquip make_pbmsg(){ return ::proto_ff::Sheet_EquipEquip(); }
	};
	typedef struct Sheet_EquipEquip_s Sheet_EquipEquip_t;

	struct E_EquipAttributeAttributeDesc_s : public NFDescStoreSeqOP {
		E_EquipAttributeAttributeDesc_s();
		virtual ~E_EquipAttributeAttributeDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_valueMax;//最大数值
		int32_t m_valueMin;//最小数值
		int32_t m_type;//

		virtual void write_to_pbmsg(::proto_ff::E_EquipAttributeAttributeDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_EquipAttributeAttributeDesc & msg);
		static ::proto_ff::E_EquipAttributeAttributeDesc* new_pbmsg(){ return new ::proto_ff::E_EquipAttributeAttributeDesc(); }
		static ::proto_ff::E_EquipAttributeAttributeDesc make_pbmsg(){ return ::proto_ff::E_EquipAttributeAttributeDesc(); }
	};
	typedef struct E_EquipAttributeAttributeDesc_s E_EquipAttributeAttributeDesc_t;

	struct E_EquipAttribute_s : public NFDescStoreSeqOP {
		E_EquipAttribute_s();
		virtual ~E_EquipAttribute_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//属性ID
		int32_t m_blueStarNum;//蓝色星级属性条数
		NFShmString<64> m_blueStar_type;//蓝色星级属性类型库
		NFShmString<64> m_blueStar_lv;//蓝色星级等级间隔差
		NFShmString<64> m_blueStar_number;//蓝色星级每级增加值
		int32_t m_specid;//特殊属性id
		int32_t m_specialAttributeDown;//特殊属性数量下限
		int32_t m_specialAttributeUp;//特殊属性数量上限
		NFShmString<64> m_specialAttribute_typeLibrary;//特殊星级属性库
		NFShmString<64> m_specialAttribute_valueMin;//特殊属性最小值
		NFShmString<64> m_specialAttribute_valueMax;//特殊属性最大值
		NFShmString<64> m_godAttribute_type;//仙尊属性
		NFShmString<64> m_godAttribute_valueMin;//仙尊属性最小数值
		NFShmString<64> m_godAttribute_valueMax;//仙尊属性最大数值
		NFShmString<64> m_silverStarLib;//白星属性库
		NFShmString<64> m_silverStarValue;//白星属性值
		NFShmString<64> m_goldStarLib;//金星属性库
		NFShmString<64> m_goldStarValue;//金星属性值
		NFShmString<64> m_godeviAtt;//神品属性库
		NFShmString<64> m_godeviAttValue;//神品属性值
		NFShmString<64> m_godevilSkill;//神魔技能
		NFShmVector<struct E_EquipAttributeAttributeDesc_s, DEFINE_E_EQUIPATTRIBUTE_M_ATTRIBUTE_MAX_NUM> m_attribute;//基础属性
		NFShmVector<NFShmString<64>, DEFINE_E_EQUIPATTRIBUTE_M_STAR_LIBRARY_MAX_NUM> m_star_Library;//星级属性库

		virtual void write_to_pbmsg(::proto_ff::E_EquipAttribute & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_EquipAttribute & msg);
		static ::proto_ff::E_EquipAttribute* new_pbmsg(){ return new ::proto_ff::E_EquipAttribute(); }
		static ::proto_ff::E_EquipAttribute make_pbmsg(){ return ::proto_ff::E_EquipAttribute(); }
	};
	typedef struct E_EquipAttribute_s E_EquipAttribute_t;

	struct Sheet_EquipAttribute_s : public NFDescStoreSeqOP {
		Sheet_EquipAttribute_s();
		virtual ~Sheet_EquipAttribute_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_EquipAttribute_s, DEFINE_SHEET_EQUIPATTRIBUTE_E_EQUIPATTRIBUTE_LIST_MAX_NUM> E_EquipAttribute_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_EquipAttribute & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_EquipAttribute & msg);
		static ::proto_ff::Sheet_EquipAttribute* new_pbmsg(){ return new ::proto_ff::Sheet_EquipAttribute(); }
		static ::proto_ff::Sheet_EquipAttribute make_pbmsg(){ return ::proto_ff::Sheet_EquipAttribute(); }
	};
	typedef struct Sheet_EquipAttribute_s Sheet_EquipAttribute_t;

	struct E_EquipSpecattAttributeDesc_s : public NFDescStoreSeqOP {
		E_EquipSpecattAttributeDesc_s();
		virtual ~E_EquipSpecattAttributeDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_value;//值
		int32_t m_type;//类型

		virtual void write_to_pbmsg(::proto_ff::E_EquipSpecattAttributeDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_EquipSpecattAttributeDesc & msg);
		static ::proto_ff::E_EquipSpecattAttributeDesc* new_pbmsg(){ return new ::proto_ff::E_EquipSpecattAttributeDesc(); }
		static ::proto_ff::E_EquipSpecattAttributeDesc make_pbmsg(){ return ::proto_ff::E_EquipSpecattAttributeDesc(); }
	};
	typedef struct E_EquipSpecattAttributeDesc_s E_EquipSpecattAttributeDesc_t;

	struct E_EquipSpecatt_s : public NFDescStoreSeqOP {
		E_EquipSpecatt_s();
		virtual ~E_EquipSpecatt_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//id
		int32_t m_groupid;//首饰组id
		int32_t m_lv;//真炼等级
		NFShmString<64> m_Zlname;//等级描述
		NFShmVector<struct E_EquipSpecattAttributeDesc_s, DEFINE_E_EQUIPSPECATT_M_ATTRIBUTE_MAX_NUM> m_attribute;//属性

		virtual void write_to_pbmsg(::proto_ff::E_EquipSpecatt & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_EquipSpecatt & msg);
		static ::proto_ff::E_EquipSpecatt* new_pbmsg(){ return new ::proto_ff::E_EquipSpecatt(); }
		static ::proto_ff::E_EquipSpecatt make_pbmsg(){ return ::proto_ff::E_EquipSpecatt(); }
	};
	typedef struct E_EquipSpecatt_s E_EquipSpecatt_t;

	struct Sheet_EquipSpecatt_s : public NFDescStoreSeqOP {
		Sheet_EquipSpecatt_s();
		virtual ~Sheet_EquipSpecatt_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_EquipSpecatt_s, DEFINE_SHEET_EQUIPSPECATT_E_EQUIPSPECATT_LIST_MAX_NUM> E_EquipSpecatt_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_EquipSpecatt & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_EquipSpecatt & msg);
		static ::proto_ff::Sheet_EquipSpecatt* new_pbmsg(){ return new ::proto_ff::Sheet_EquipSpecatt(); }
		static ::proto_ff::Sheet_EquipSpecatt make_pbmsg(){ return ::proto_ff::Sheet_EquipSpecatt(); }
	};
	typedef struct Sheet_EquipSpecatt_s Sheet_EquipSpecatt_t;

	struct E_EquipStrongTypeDesc_s : public NFDescStoreSeqOP {
		E_EquipStrongTypeDesc_s();
		virtual ~E_EquipStrongTypeDesc_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmString<64> m_num;//值
		int32_t m_id;//ID

		virtual void write_to_pbmsg(::proto_ff::E_EquipStrongTypeDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_EquipStrongTypeDesc & msg);
		static ::proto_ff::E_EquipStrongTypeDesc* new_pbmsg(){ return new ::proto_ff::E_EquipStrongTypeDesc(); }
		static ::proto_ff::E_EquipStrongTypeDesc make_pbmsg(){ return ::proto_ff::E_EquipStrongTypeDesc(); }
	};
	typedef struct E_EquipStrongTypeDesc_s E_EquipStrongTypeDesc_t;

	struct E_EquipStrong_s : public NFDescStoreSeqOP {
		E_EquipStrong_s();
		virtual ~E_EquipStrong_s(){}
		int CreateInit();
		int ResumeInit();
		int64_t m_id;//部位ID
		int32_t m_position;//装备部位
		int32_t m_wearQuality;//装备品阶
		int32_t m_srtongUp;//强化上限
		NFShmVector<struct E_EquipStrongTypeDesc_s, DEFINE_E_EQUIPSTRONG_M_TYPE_MAX_NUM> m_type;//属性

		virtual void write_to_pbmsg(::proto_ff::E_EquipStrong & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_EquipStrong & msg);
		static ::proto_ff::E_EquipStrong* new_pbmsg(){ return new ::proto_ff::E_EquipStrong(); }
		static ::proto_ff::E_EquipStrong make_pbmsg(){ return ::proto_ff::E_EquipStrong(); }
	};
	typedef struct E_EquipStrong_s E_EquipStrong_t;

	struct Sheet_EquipStrong_s : public NFDescStoreSeqOP {
		Sheet_EquipStrong_s();
		virtual ~Sheet_EquipStrong_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_EquipStrong_s, DEFINE_SHEET_EQUIPSTRONG_E_EQUIPSTRONG_LIST_MAX_NUM> E_EquipStrong_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_EquipStrong & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_EquipStrong & msg);
		static ::proto_ff::Sheet_EquipStrong* new_pbmsg(){ return new ::proto_ff::Sheet_EquipStrong(); }
		static ::proto_ff::Sheet_EquipStrong make_pbmsg(){ return ::proto_ff::Sheet_EquipStrong(); }
	};
	typedef struct Sheet_EquipStrong_s Sheet_EquipStrong_t;

	struct E_EquipStrongexpCostDesc_s : public NFDescStoreSeqOP {
		E_EquipStrongexpCostDesc_s();
		virtual ~E_EquipStrongexpCostDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_Num;//道具数量
		int32_t m_Item;//消耗道具

		virtual void write_to_pbmsg(::proto_ff::E_EquipStrongexpCostDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_EquipStrongexpCostDesc & msg);
		static ::proto_ff::E_EquipStrongexpCostDesc* new_pbmsg(){ return new ::proto_ff::E_EquipStrongexpCostDesc(); }
		static ::proto_ff::E_EquipStrongexpCostDesc make_pbmsg(){ return ::proto_ff::E_EquipStrongexpCostDesc(); }
	};
	typedef struct E_EquipStrongexpCostDesc_s E_EquipStrongexpCostDesc_t;

	struct E_EquipStrongexp_s : public NFDescStoreSeqOP {
		E_EquipStrongexp_s();
		virtual ~E_EquipStrongexp_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_Lv;//等级
		int32_t m_gold;//强化消耗金币
		NFShmVector<NFShmString<64>, DEFINE_E_EQUIPSTRONGEXP_M_POSITIONTYPE_MAX_NUM> m_positionType;//部位类型
		NFShmVector<struct E_EquipStrongexpCostDesc_s, DEFINE_E_EQUIPSTRONGEXP_M_COST_MAX_NUM> m_cost;//部位类型

		virtual void write_to_pbmsg(::proto_ff::E_EquipStrongexp & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_EquipStrongexp & msg);
		static ::proto_ff::E_EquipStrongexp* new_pbmsg(){ return new ::proto_ff::E_EquipStrongexp(); }
		static ::proto_ff::E_EquipStrongexp make_pbmsg(){ return ::proto_ff::E_EquipStrongexp(); }
	};
	typedef struct E_EquipStrongexp_s E_EquipStrongexp_t;

	struct Sheet_EquipStrongexp_s : public NFDescStoreSeqOP {
		Sheet_EquipStrongexp_s();
		virtual ~Sheet_EquipStrongexp_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_EquipStrongexp_s, DEFINE_SHEET_EQUIPSTRONGEXP_E_EQUIPSTRONGEXP_LIST_MAX_NUM> E_EquipStrongexp_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_EquipStrongexp & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_EquipStrongexp & msg);
		static ::proto_ff::Sheet_EquipStrongexp* new_pbmsg(){ return new ::proto_ff::Sheet_EquipStrongexp(); }
		static ::proto_ff::Sheet_EquipStrongexp make_pbmsg(){ return ::proto_ff::Sheet_EquipStrongexp(); }
	};
	typedef struct Sheet_EquipStrongexp_s Sheet_EquipStrongexp_t;

	struct E_EquipBeaststrongTypeDesc_s : public NFDescStoreSeqOP {
		E_EquipBeaststrongTypeDesc_s();
		virtual ~E_EquipBeaststrongTypeDesc_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmString<64> m_num;//值
		int32_t m_id;//ID

		virtual void write_to_pbmsg(::proto_ff::E_EquipBeaststrongTypeDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_EquipBeaststrongTypeDesc & msg);
		static ::proto_ff::E_EquipBeaststrongTypeDesc* new_pbmsg(){ return new ::proto_ff::E_EquipBeaststrongTypeDesc(); }
		static ::proto_ff::E_EquipBeaststrongTypeDesc make_pbmsg(){ return ::proto_ff::E_EquipBeaststrongTypeDesc(); }
	};
	typedef struct E_EquipBeaststrongTypeDesc_s E_EquipBeaststrongTypeDesc_t;

	struct E_EquipBeaststrong_s : public NFDescStoreSeqOP {
		E_EquipBeaststrong_s();
		virtual ~E_EquipBeaststrong_s(){}
		int CreateInit();
		int ResumeInit();
		int64_t m_id;//部位ID
		int32_t m_position;//装备部位
		int32_t m_wearQuality;//装备品质
		int32_t m_srtongUp;//强化上限
		NFShmVector<struct E_EquipBeaststrongTypeDesc_s, DEFINE_E_EQUIPBEASTSTRONG_M_TYPE_MAX_NUM> m_type;//属性

		virtual void write_to_pbmsg(::proto_ff::E_EquipBeaststrong & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_EquipBeaststrong & msg);
		static ::proto_ff::E_EquipBeaststrong* new_pbmsg(){ return new ::proto_ff::E_EquipBeaststrong(); }
		static ::proto_ff::E_EquipBeaststrong make_pbmsg(){ return ::proto_ff::E_EquipBeaststrong(); }
	};
	typedef struct E_EquipBeaststrong_s E_EquipBeaststrong_t;

	struct Sheet_EquipBeaststrong_s : public NFDescStoreSeqOP {
		Sheet_EquipBeaststrong_s();
		virtual ~Sheet_EquipBeaststrong_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_EquipBeaststrong_s, DEFINE_SHEET_EQUIPBEASTSTRONG_E_EQUIPBEASTSTRONG_LIST_MAX_NUM> E_EquipBeaststrong_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_EquipBeaststrong & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_EquipBeaststrong & msg);
		static ::proto_ff::Sheet_EquipBeaststrong* new_pbmsg(){ return new ::proto_ff::Sheet_EquipBeaststrong(); }
		static ::proto_ff::Sheet_EquipBeaststrong make_pbmsg(){ return ::proto_ff::Sheet_EquipBeaststrong(); }
	};
	typedef struct Sheet_EquipBeaststrong_s Sheet_EquipBeaststrong_t;

	struct E_EquipStrongtotalAttributeDesc_s : public NFDescStoreSeqOP {
		E_EquipStrongtotalAttributeDesc_s();
		virtual ~E_EquipStrongtotalAttributeDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_value;//值
		int32_t m_type;//ID

		virtual void write_to_pbmsg(::proto_ff::E_EquipStrongtotalAttributeDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_EquipStrongtotalAttributeDesc & msg);
		static ::proto_ff::E_EquipStrongtotalAttributeDesc* new_pbmsg(){ return new ::proto_ff::E_EquipStrongtotalAttributeDesc(); }
		static ::proto_ff::E_EquipStrongtotalAttributeDesc make_pbmsg(){ return ::proto_ff::E_EquipStrongtotalAttributeDesc(); }
	};
	typedef struct E_EquipStrongtotalAttributeDesc_s E_EquipStrongtotalAttributeDesc_t;

	struct E_EquipStrongtotal_s : public NFDescStoreSeqOP {
		E_EquipStrongtotal_s();
		virtual ~E_EquipStrongtotal_s(){}
		int CreateInit();
		int ResumeInit();
		int64_t m_id;//总等级ID
		int32_t m_idType;//总等级类型
		int32_t m_idNum;//总等级
		NFShmVector<struct E_EquipStrongtotalAttributeDesc_s, DEFINE_E_EQUIPSTRONGTOTAL_M_ATTRIBUTE_MAX_NUM> m_attribute;//基础属性

		virtual void write_to_pbmsg(::proto_ff::E_EquipStrongtotal & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_EquipStrongtotal & msg);
		static ::proto_ff::E_EquipStrongtotal* new_pbmsg(){ return new ::proto_ff::E_EquipStrongtotal(); }
		static ::proto_ff::E_EquipStrongtotal make_pbmsg(){ return ::proto_ff::E_EquipStrongtotal(); }
	};
	typedef struct E_EquipStrongtotal_s E_EquipStrongtotal_t;

	struct Sheet_EquipStrongtotal_s : public NFDescStoreSeqOP {
		Sheet_EquipStrongtotal_s();
		virtual ~Sheet_EquipStrongtotal_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_EquipStrongtotal_s, DEFINE_SHEET_EQUIPSTRONGTOTAL_E_EQUIPSTRONGTOTAL_LIST_MAX_NUM> E_EquipStrongtotal_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_EquipStrongtotal & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_EquipStrongtotal & msg);
		static ::proto_ff::Sheet_EquipStrongtotal* new_pbmsg(){ return new ::proto_ff::Sheet_EquipStrongtotal(); }
		static ::proto_ff::Sheet_EquipStrongtotal make_pbmsg(){ return ::proto_ff::Sheet_EquipStrongtotal(); }
	};
	typedef struct Sheet_EquipStrongtotal_s Sheet_EquipStrongtotal_t;

	struct E_EquipGem_s : public NFDescStoreSeqOP {
		E_EquipGem_s();
		virtual ~E_EquipGem_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_position;//装备部位
		NFShmString<64> m_gemType;//普通槽位宝石类型
		int32_t m_speciallyGemType;//特殊槽位宝石类型
		int32_t m_payUnlockItem;//付费解锁槽道具
		int32_t m_payUnlockNnm;//解锁道具数量
		NFShmString<64> m_commonGemBuy;//普通槽位快捷购买
		NFShmString<64> m_speciallyGemBuy;//特殊槽位快捷购买
		NFShmVector<int32_t, DEFINE_E_EQUIPGEM_M_GEMUNLOCK_MAX_NUM> m_gemUnlock;//装备槽解锁品阶

		virtual void write_to_pbmsg(::proto_ff::E_EquipGem & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_EquipGem & msg);
		static ::proto_ff::E_EquipGem* new_pbmsg(){ return new ::proto_ff::E_EquipGem(); }
		static ::proto_ff::E_EquipGem make_pbmsg(){ return ::proto_ff::E_EquipGem(); }
	};
	typedef struct E_EquipGem_s E_EquipGem_t;

	struct Sheet_EquipGem_s : public NFDescStoreSeqOP {
		Sheet_EquipGem_s();
		virtual ~Sheet_EquipGem_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_EquipGem_s, DEFINE_SHEET_EQUIPGEM_E_EQUIPGEM_LIST_MAX_NUM> E_EquipGem_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_EquipGem & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_EquipGem & msg);
		static ::proto_ff::Sheet_EquipGem* new_pbmsg(){ return new ::proto_ff::Sheet_EquipGem(); }
		static ::proto_ff::Sheet_EquipGem make_pbmsg(){ return ::proto_ff::Sheet_EquipGem(); }
	};
	typedef struct Sheet_EquipGem_s Sheet_EquipGem_t;

	struct E_EquipGemlv_s : public NFDescStoreSeqOP {
		E_EquipGemlv_s();
		virtual ~E_EquipGemlv_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//id
		int32_t m_preId;//上级宝石ID
		int32_t m_nextId;//下级宝石ID
		NFShmString<64> m_numb;//对应一级宝石数量
		int32_t m_nextValue;//下级差值
		int32_t m_costGold;//下级消耗金币
		int32_t m_mallID;//补足商品的id

		virtual void write_to_pbmsg(::proto_ff::E_EquipGemlv & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_EquipGemlv & msg);
		static ::proto_ff::E_EquipGemlv* new_pbmsg(){ return new ::proto_ff::E_EquipGemlv(); }
		static ::proto_ff::E_EquipGemlv make_pbmsg(){ return ::proto_ff::E_EquipGemlv(); }
	};
	typedef struct E_EquipGemlv_s E_EquipGemlv_t;

	struct Sheet_EquipGemlv_s : public NFDescStoreSeqOP {
		Sheet_EquipGemlv_s();
		virtual ~Sheet_EquipGemlv_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_EquipGemlv_s, DEFINE_SHEET_EQUIPGEMLV_E_EQUIPGEMLV_LIST_MAX_NUM> E_EquipGemlv_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_EquipGemlv & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_EquipGemlv & msg);
		static ::proto_ff::Sheet_EquipGemlv* new_pbmsg(){ return new ::proto_ff::Sheet_EquipGemlv(); }
		static ::proto_ff::Sheet_EquipGemlv make_pbmsg(){ return ::proto_ff::Sheet_EquipGemlv(); }
	};
	typedef struct Sheet_EquipGemlv_s Sheet_EquipGemlv_t;

	struct E_EquipStoveattAttributeDesc_s : public NFDescStoreSeqOP {
		E_EquipStoveattAttributeDesc_s();
		virtual ~E_EquipStoveattAttributeDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_value;//值
		int32_t m_type;//ID

		virtual void write_to_pbmsg(::proto_ff::E_EquipStoveattAttributeDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_EquipStoveattAttributeDesc & msg);
		static ::proto_ff::E_EquipStoveattAttributeDesc* new_pbmsg(){ return new ::proto_ff::E_EquipStoveattAttributeDesc(); }
		static ::proto_ff::E_EquipStoveattAttributeDesc make_pbmsg(){ return ::proto_ff::E_EquipStoveattAttributeDesc(); }
	};
	typedef struct E_EquipStoveattAttributeDesc_s E_EquipStoveattAttributeDesc_t;

	struct E_EquipStoveatt_s : public NFDescStoreSeqOP {
		E_EquipStoveatt_s();
		virtual ~E_EquipStoveatt_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_lv;//等级
		int64_t m_exp;//总经验值
		NFShmVector<struct E_EquipStoveattAttributeDesc_s, DEFINE_E_EQUIPSTOVEATT_M_ATTRIBUTE_MAX_NUM> m_attribute;//基础属性

		virtual void write_to_pbmsg(::proto_ff::E_EquipStoveatt & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_EquipStoveatt & msg);
		static ::proto_ff::E_EquipStoveatt* new_pbmsg(){ return new ::proto_ff::E_EquipStoveatt(); }
		static ::proto_ff::E_EquipStoveatt make_pbmsg(){ return ::proto_ff::E_EquipStoveatt(); }
	};
	typedef struct E_EquipStoveatt_s E_EquipStoveatt_t;

	struct Sheet_EquipStoveatt_s : public NFDescStoreSeqOP {
		Sheet_EquipStoveatt_s();
		virtual ~Sheet_EquipStoveatt_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_EquipStoveatt_s, DEFINE_SHEET_EQUIPSTOVEATT_E_EQUIPSTOVEATT_LIST_MAX_NUM> E_EquipStoveatt_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_EquipStoveatt & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_EquipStoveatt & msg);
		static ::proto_ff::Sheet_EquipStoveatt* new_pbmsg(){ return new ::proto_ff::Sheet_EquipStoveatt(); }
		static ::proto_ff::Sheet_EquipStoveatt make_pbmsg(){ return ::proto_ff::Sheet_EquipStoveatt(); }
	};
	typedef struct Sheet_EquipStoveatt_s Sheet_EquipStoveatt_t;

	struct E_EquipStoveexp_s : public NFDescStoreSeqOP {
		E_EquipStoveexp_s();
		virtual ~E_EquipStoveexp_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_ID;//序号
		int32_t m_exp;//经验值
		int32_t m_wearQuality;//装备品阶
		int32_t m_quality;//装备品质

		virtual void write_to_pbmsg(::proto_ff::E_EquipStoveexp & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_EquipStoveexp & msg);
		static ::proto_ff::E_EquipStoveexp* new_pbmsg(){ return new ::proto_ff::E_EquipStoveexp(); }
		static ::proto_ff::E_EquipStoveexp make_pbmsg(){ return ::proto_ff::E_EquipStoveexp(); }
	};
	typedef struct E_EquipStoveexp_s E_EquipStoveexp_t;

	struct Sheet_EquipStoveexp_s : public NFDescStoreSeqOP {
		Sheet_EquipStoveexp_s();
		virtual ~Sheet_EquipStoveexp_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_EquipStoveexp_s, DEFINE_SHEET_EQUIPSTOVEEXP_E_EQUIPSTOVEEXP_LIST_MAX_NUM> E_EquipStoveexp_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_EquipStoveexp & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_EquipStoveexp & msg);
		static ::proto_ff::Sheet_EquipStoveexp* new_pbmsg(){ return new ::proto_ff::Sheet_EquipStoveexp(); }
		static ::proto_ff::Sheet_EquipStoveexp make_pbmsg(){ return ::proto_ff::Sheet_EquipStoveexp(); }
	};
	typedef struct Sheet_EquipStoveexp_s Sheet_EquipStoveexp_t;

	struct E_EquipGrade_s : public NFDescStoreSeqOP {
		E_EquipGrade_s();
		virtual ~E_EquipGrade_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_ID;//序号

		virtual void write_to_pbmsg(::proto_ff::E_EquipGrade & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_EquipGrade & msg);
		static ::proto_ff::E_EquipGrade* new_pbmsg(){ return new ::proto_ff::E_EquipGrade(); }
		static ::proto_ff::E_EquipGrade make_pbmsg(){ return ::proto_ff::E_EquipGrade(); }
	};
	typedef struct E_EquipGrade_s E_EquipGrade_t;

	struct Sheet_EquipGrade_s : public NFDescStoreSeqOP {
		Sheet_EquipGrade_s();
		virtual ~Sheet_EquipGrade_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_EquipGrade_s, DEFINE_SHEET_EQUIPGRADE_E_EQUIPGRADE_LIST_MAX_NUM> E_EquipGrade_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_EquipGrade & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_EquipGrade & msg);
		static ::proto_ff::Sheet_EquipGrade* new_pbmsg(){ return new ::proto_ff::Sheet_EquipGrade(); }
		static ::proto_ff::Sheet_EquipGrade make_pbmsg(){ return ::proto_ff::Sheet_EquipGrade(); }
	};
	typedef struct Sheet_EquipGrade_s Sheet_EquipGrade_t;

	struct E_EquipClearAttributeDesc_s : public NFDescStoreSeqOP {
		E_EquipClearAttributeDesc_s();
		virtual ~E_EquipClearAttributeDesc_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmString<64> m_value;//属性

		virtual void write_to_pbmsg(::proto_ff::E_EquipClearAttributeDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_EquipClearAttributeDesc & msg);
		static ::proto_ff::E_EquipClearAttributeDesc* new_pbmsg(){ return new ::proto_ff::E_EquipClearAttributeDesc(); }
		static ::proto_ff::E_EquipClearAttributeDesc make_pbmsg(){ return ::proto_ff::E_EquipClearAttributeDesc(); }
	};
	typedef struct E_EquipClearAttributeDesc_s E_EquipClearAttributeDesc_t;

	struct E_EquipClearSectionDesc_s : public NFDescStoreSeqOP {
		E_EquipClearSectionDesc_s();
		virtual ~E_EquipClearSectionDesc_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmString<64> m_up;//最大值
		NFShmString<64> m_down;//最小值
		NFShmString<64> m_type;//库
		NFShmString<64> m_g;//高级洗练
		int32_t m_p;//普通洗练

		virtual void write_to_pbmsg(::proto_ff::E_EquipClearSectionDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_EquipClearSectionDesc & msg);
		static ::proto_ff::E_EquipClearSectionDesc* new_pbmsg(){ return new ::proto_ff::E_EquipClearSectionDesc(); }
		static ::proto_ff::E_EquipClearSectionDesc make_pbmsg(){ return ::proto_ff::E_EquipClearSectionDesc(); }
	};
	typedef struct E_EquipClearSectionDesc_s E_EquipClearSectionDesc_t;

	struct E_EquipClear_s : public NFDescStoreSeqOP {
		E_EquipClear_s();
		virtual ~E_EquipClear_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//部位id
		NFShmString<64> m_value;//开孔绑钻花费
		int32_t m_unlockItem;//开孔道具
		NFShmString<64> m_unlockNum;//开孔道具数量
		int64_t m_consumeId;//消耗道具ID
		NFShmString<64> m_consumeNum;//消耗道具数量
		NFShmString<64> m_lockingId;//高级道具ID
		NFShmString<64> m_lockingNum;//高级道具数量
		NFShmVector<struct E_EquipClearAttributeDesc_s, DEFINE_E_EQUIPCLEAR_M_ATTRIBUTE_MAX_NUM> m_attribute;//属性达标激活
		NFShmVector<struct E_EquipClearSectionDesc_s, DEFINE_E_EQUIPCLEAR_M_SECTION_MAX_NUM> m_Section;//属性类型

		virtual void write_to_pbmsg(::proto_ff::E_EquipClear & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_EquipClear & msg);
		static ::proto_ff::E_EquipClear* new_pbmsg(){ return new ::proto_ff::E_EquipClear(); }
		static ::proto_ff::E_EquipClear make_pbmsg(){ return ::proto_ff::E_EquipClear(); }
	};
	typedef struct E_EquipClear_s E_EquipClear_t;

	struct Sheet_EquipClear_s : public NFDescStoreSeqOP {
		Sheet_EquipClear_s();
		virtual ~Sheet_EquipClear_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_EquipClear_s, DEFINE_SHEET_EQUIPCLEAR_E_EQUIPCLEAR_LIST_MAX_NUM> E_EquipClear_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_EquipClear & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_EquipClear & msg);
		static ::proto_ff::Sheet_EquipClear* new_pbmsg(){ return new ::proto_ff::Sheet_EquipClear(); }
		static ::proto_ff::Sheet_EquipClear make_pbmsg(){ return ::proto_ff::Sheet_EquipClear(); }
	};
	typedef struct Sheet_EquipClear_s Sheet_EquipClear_t;

	struct E_EquipSuitAttributeDesc_s : public NFDescStoreSeqOP {
		E_EquipSuitAttributeDesc_s();
		virtual ~E_EquipSuitAttributeDesc_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmString<64> m_value;//数值
		int32_t m_sctivation;//

		virtual void write_to_pbmsg(::proto_ff::E_EquipSuitAttributeDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_EquipSuitAttributeDesc & msg);
		static ::proto_ff::E_EquipSuitAttributeDesc* new_pbmsg(){ return new ::proto_ff::E_EquipSuitAttributeDesc(); }
		static ::proto_ff::E_EquipSuitAttributeDesc make_pbmsg(){ return ::proto_ff::E_EquipSuitAttributeDesc(); }
	};
	typedef struct E_EquipSuitAttributeDesc_s E_EquipSuitAttributeDesc_t;

	struct E_EquipSuit_s : public NFDescStoreSeqOP {
		E_EquipSuit_s();
		virtual ~E_EquipSuit_s(){}
		int CreateInit();
		int ResumeInit();
		int64_t m_id;//套装ID
		int32_t m_type;//类型
		int32_t m_suitLv;//套装等级
		int32_t m_wearQuality;//装备品阶
		int32_t m_colour;//套装打造品质
		NFShmString<64> m_afterName;//套装命前缀
		int32_t m_suiteValue;//套装套件数量
		NFShmVector<struct E_EquipSuitAttributeDesc_s, DEFINE_E_EQUIPSUIT_M_ATTRIBUTE_MAX_NUM> m_attribute;//套件激活属性
		NFShmVector<NFShmString<64>, DEFINE_E_EQUIPSUIT_M_MALEPOSITION_MAX_NUM> m_malePosition;//男部位
		NFShmVector<NFShmString<64>, DEFINE_E_EQUIPSUIT_M_FEMALEPOSITION_MAX_NUM> m_femalePosition;//女部位

		virtual void write_to_pbmsg(::proto_ff::E_EquipSuit & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_EquipSuit & msg);
		static ::proto_ff::E_EquipSuit* new_pbmsg(){ return new ::proto_ff::E_EquipSuit(); }
		static ::proto_ff::E_EquipSuit make_pbmsg(){ return ::proto_ff::E_EquipSuit(); }
	};
	typedef struct E_EquipSuit_s E_EquipSuit_t;

	struct Sheet_EquipSuit_s : public NFDescStoreSeqOP {
		Sheet_EquipSuit_s();
		virtual ~Sheet_EquipSuit_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_EquipSuit_s, DEFINE_SHEET_EQUIPSUIT_E_EQUIPSUIT_LIST_MAX_NUM> E_EquipSuit_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_EquipSuit & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_EquipSuit & msg);
		static ::proto_ff::Sheet_EquipSuit* new_pbmsg(){ return new ::proto_ff::Sheet_EquipSuit(); }
		static ::proto_ff::Sheet_EquipSuit make_pbmsg(){ return ::proto_ff::Sheet_EquipSuit(); }
	};
	typedef struct Sheet_EquipSuit_s Sheet_EquipSuit_t;

	struct E_EquipBreakBreakDesc_s : public NFDescStoreSeqOP {
		E_EquipBreakBreakDesc_s();
		virtual ~E_EquipBreakBreakDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_Num;//道具数量
		int32_t m_Item;//消耗道具

		virtual void write_to_pbmsg(::proto_ff::E_EquipBreakBreakDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_EquipBreakBreakDesc & msg);
		static ::proto_ff::E_EquipBreakBreakDesc* new_pbmsg(){ return new ::proto_ff::E_EquipBreakBreakDesc(); }
		static ::proto_ff::E_EquipBreakBreakDesc make_pbmsg(){ return ::proto_ff::E_EquipBreakBreakDesc(); }
	};
	typedef struct E_EquipBreakBreakDesc_s E_EquipBreakBreakDesc_t;

	struct E_EquipBreak_s : public NFDescStoreSeqOP {
		E_EquipBreak_s();
		virtual ~E_EquipBreak_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_Lv;//id
		int32_t m_step;//阶数
		NFShmString<64> m_positionType;//部位类型
		int32_t m_basic;//提升基础属性万分比
		int32_t m_star;//提升星级属性万分比
		NFShmVector<struct E_EquipBreakBreakDesc_s, DEFINE_E_EQUIPBREAK_M_BREAK_MAX_NUM> m_break;//突破消耗

		virtual void write_to_pbmsg(::proto_ff::E_EquipBreak & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_EquipBreak & msg);
		static ::proto_ff::E_EquipBreak* new_pbmsg(){ return new ::proto_ff::E_EquipBreak(); }
		static ::proto_ff::E_EquipBreak make_pbmsg(){ return ::proto_ff::E_EquipBreak(); }
	};
	typedef struct E_EquipBreak_s E_EquipBreak_t;

	struct Sheet_EquipBreak_s : public NFDescStoreSeqOP {
		Sheet_EquipBreak_s();
		virtual ~Sheet_EquipBreak_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_EquipBreak_s, DEFINE_SHEET_EQUIPBREAK_E_EQUIPBREAK_LIST_MAX_NUM> E_EquipBreak_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_EquipBreak & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_EquipBreak & msg);
		static ::proto_ff::Sheet_EquipBreak* new_pbmsg(){ return new ::proto_ff::Sheet_EquipBreak(); }
		static ::proto_ff::Sheet_EquipBreak make_pbmsg(){ return ::proto_ff::Sheet_EquipBreak(); }
	};
	typedef struct Sheet_EquipBreak_s Sheet_EquipBreak_t;

}

