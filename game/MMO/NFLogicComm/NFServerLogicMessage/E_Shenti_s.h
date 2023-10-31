#pragma once

#include <stdint.h>
#include <NFComm/NFShmStl/NFShmString.h>
#include <NFComm/NFShmStl/NFShmVector.h>
#include <NFComm/NFShmCore/NFSeqOP.h>
#include <NFComm/NFShmCore/NFShmMgr.h>
#include "E_Shenti.pb.h"
#include "E_Shenti_s.h"

#define DEFINE_E_SHENTICONSTANT_M_TIME_MAX_NUM 2
#define DEFINE_SHEET_SHENTICONSTANT_E_SHENTICONSTANT_LIST_MAX_NUM 2
#define DEFINE_E_SHENTIPREPOSE_M_REWARD_MAX_NUM 5
#define DEFINE_SHEET_SHENTIPREPOSE_E_SHENTIPREPOSE_LIST_MAX_NUM 8
#define DEFINE_E_SHENTIUPGRADE_M_ATTRIBUTE_MAX_NUM 7
#define DEFINE_SHEET_SHENTIUPGRADE_E_SHENTIUPGRADE_LIST_MAX_NUM 128
#define DEFINE_E_SHENTIREMANIE_M_ATTR_MAX_NUM 6
#define DEFINE_SHEET_SHENTIREMANIE_E_SHENTIREMANIE_LIST_MAX_NUM 8
#define DEFINE_SHEET_SHENTIEQUIP_E_SHENTIEQUIP_LIST_MAX_NUM 1024
#define DEFINE_E_SHENTIATTRIBUTE_M_ATTRIBUTE_MAX_NUM 5
#define DEFINE_E_SHENTIATTRIBUTE_M_XPCOM_MAX_NUM 2
#define DEFINE_E_SHENTIATTRIBUTE_M_XPSTAR_MAX_NUM 2
#define DEFINE_E_SHENTIATTRIBUTE_M_GOD_MAX_NUM 2
#define DEFINE_E_SHENTIATTRIBUTE_M_SPECIAL_MAX_NUM 5
#define DEFINE_SHEET_SHENTIATTRIBUTE_E_SHENTIATTRIBUTE_LIST_MAX_NUM 512
#define DEFINE_E_SHENTISTRONG_M_MATERIAL_MAX_NUM 3
#define DEFINE_E_SHENTISTRONG_M_ATTRIBUTE_MAX_NUM 5
#define DEFINE_SHEET_SHENTISTRONG_E_SHENTISTRONG_LIST_MAX_NUM 512
#define DEFINE_E_SHENTIEVOLVE_M_ATTRIBUTE_MAX_NUM 5
#define DEFINE_E_SHENTIEVOLVE_M_XPCOM_MAX_NUM 7
#define DEFINE_E_SHENTIEVOLVE_M_XPSTAR_MAX_NUM 7
#define DEFINE_SHEET_SHENTIEVOLVE_E_SHENTIEVOLVE_LIST_MAX_NUM 256
#define DEFINE_E_SHENTIEVOLVEPROGRESS_M_EVOLVE_MAX_NUM 6
#define DEFINE_SHEET_SHENTIEVOLVEPROGRESS_E_SHENTIEVOLVEPROGRESS_LIST_MAX_NUM 256
#define DEFINE_E_SHENTISTARLIBRARY_M_XPCOM_MAX_NUM 7
#define DEFINE_E_SHENTISTARLIBRARY_M_XPSTAR_MAX_NUM 7
#define DEFINE_SHEET_SHENTISTARLIBRARY_E_SHENTISTARLIBRARY_LIST_MAX_NUM 64
#define DEFINE_E_SHENTIAWAKEN_M_ATTRIBUTE_MAX_NUM 4
#define DEFINE_E_SHENTIAWAKEN_M_AFFLATUSATT_MAX_NUM 3
#define DEFINE_SHEET_SHENTIAWAKEN_E_SHENTIAWAKEN_LIST_MAX_NUM 64
#define DEFINE_E_SHENTIAWAKENPROGRESS_M_AWAKEN_MAX_NUM 6
#define DEFINE_SHEET_SHENTIAWAKENPROGRESS_E_SHENTIAWAKENPROGRESS_LIST_MAX_NUM 64
#define DEFINE_E_SHENTISUIT_M_ATTRIBUTE_MAX_NUM 10
#define DEFINE_SHEET_SHENTISUIT_E_SHENTISUIT_LIST_MAX_NUM 128
#define DEFINE_SHEET_SHENTICOMPOSE_E_SHENTICOMPOSE_LIST_MAX_NUM 128
#define DEFINE_E_SHENTISTAR_UP_M_MATERIAL_MAX_NUM 2
#define DEFINE_E_SHENTISTAR_UP_M_XPSTAR_MAX_NUM 5
#define DEFINE_SHEET_SHENTISTAR_UP_E_SHENTISTAR_UP_LIST_MAX_NUM 32
#define DEFINE_E_SHENTISTRENGTITEL_M_ATTRIBUTE_MAX_NUM 2
#define DEFINE_SHEET_SHENTISTRENGTITEL_E_SHENTISTRENGTITEL_LIST_MAX_NUM 64
#define DEFINE_E_SHENTISTARTITEL_M_ATTRIBUTE_MAX_NUM 2
#define DEFINE_SHEET_SHENTISTARTITEL_E_SHENTISTARTITEL_LIST_MAX_NUM 16


namespace proto_ff_s {

	struct E_ShentiConstantTimeDesc_s : public NFDescStoreSeqOP {
		E_ShentiConstantTimeDesc_s();
		virtual ~E_ShentiConstantTimeDesc_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmString<64> m_close;//结束时间
		NFShmString<64> m_open;//开启时间

		virtual void write_to_pbmsg(::proto_ff::E_ShentiConstantTimeDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_ShentiConstantTimeDesc & msg);
		static ::proto_ff::E_ShentiConstantTimeDesc* new_pbmsg(){ return new ::proto_ff::E_ShentiConstantTimeDesc(); }
		static ::proto_ff::E_ShentiConstantTimeDesc make_pbmsg(){ return ::proto_ff::E_ShentiConstantTimeDesc(); }
	};
	typedef struct E_ShentiConstantTimeDesc_s E_ShentiConstantTimeDesc_t;

	struct E_ShentiConstant_s : public NFDescStoreSeqOP {
		E_ShentiConstant_s();
		virtual ~E_ShentiConstant_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//id
		int32_t m_lvLimit;//助阵等级要求
		int32_t m_remanieTimes;//每天免费转生次数
		int32_t m_currencyId;//消耗货币id
		int32_t m_currencyNum;//消耗货币数量
		int32_t m_currencyTimes;//最大使用货币转生次数
		int32_t m_bagLimit;//神体背包上限
		int32_t m_itemId;//神元经验道具id
		NFShmVector<struct E_ShentiConstantTimeDesc_s, DEFINE_E_SHENTICONSTANT_M_TIME_MAX_NUM> m_time;//天时时间段

		virtual void write_to_pbmsg(::proto_ff::E_ShentiConstant & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_ShentiConstant & msg);
		static ::proto_ff::E_ShentiConstant* new_pbmsg(){ return new ::proto_ff::E_ShentiConstant(); }
		static ::proto_ff::E_ShentiConstant make_pbmsg(){ return ::proto_ff::E_ShentiConstant(); }
	};
	typedef struct E_ShentiConstant_s E_ShentiConstant_t;

	struct Sheet_ShentiConstant_s : public NFDescStoreSeqOP {
		Sheet_ShentiConstant_s();
		virtual ~Sheet_ShentiConstant_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_ShentiConstant_s, DEFINE_SHEET_SHENTICONSTANT_E_SHENTICONSTANT_LIST_MAX_NUM> E_ShentiConstant_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_ShentiConstant & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_ShentiConstant & msg);
		static ::proto_ff::Sheet_ShentiConstant* new_pbmsg(){ return new ::proto_ff::Sheet_ShentiConstant(); }
		static ::proto_ff::Sheet_ShentiConstant make_pbmsg(){ return ::proto_ff::Sheet_ShentiConstant(); }
	};
	typedef struct Sheet_ShentiConstant_s Sheet_ShentiConstant_t;

	struct E_ShentiPreposeRewardDesc_s : public NFDescStoreSeqOP {
		E_ShentiPreposeRewardDesc_s();
		virtual ~E_ShentiPreposeRewardDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_num;//数量
		int32_t m_item;//道具

		virtual void write_to_pbmsg(::proto_ff::E_ShentiPreposeRewardDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_ShentiPreposeRewardDesc & msg);
		static ::proto_ff::E_ShentiPreposeRewardDesc* new_pbmsg(){ return new ::proto_ff::E_ShentiPreposeRewardDesc(); }
		static ::proto_ff::E_ShentiPreposeRewardDesc make_pbmsg(){ return ::proto_ff::E_ShentiPreposeRewardDesc(); }
	};
	typedef struct E_ShentiPreposeRewardDesc_s E_ShentiPreposeRewardDesc_t;

	struct E_ShentiPrepose_s : public NFDescStoreSeqOP {
		E_ShentiPrepose_s();
		virtual ~E_ShentiPrepose_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//id
		int32_t m_condition;//条件
		int32_t m_value;//条件值
		NFShmVector<struct E_ShentiPreposeRewardDesc_s, DEFINE_E_SHENTIPREPOSE_M_REWARD_MAX_NUM> m_reward;//奖励

		virtual void write_to_pbmsg(::proto_ff::E_ShentiPrepose & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_ShentiPrepose & msg);
		static ::proto_ff::E_ShentiPrepose* new_pbmsg(){ return new ::proto_ff::E_ShentiPrepose(); }
		static ::proto_ff::E_ShentiPrepose make_pbmsg(){ return ::proto_ff::E_ShentiPrepose(); }
	};
	typedef struct E_ShentiPrepose_s E_ShentiPrepose_t;

	struct Sheet_ShentiPrepose_s : public NFDescStoreSeqOP {
		Sheet_ShentiPrepose_s();
		virtual ~Sheet_ShentiPrepose_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_ShentiPrepose_s, DEFINE_SHEET_SHENTIPREPOSE_E_SHENTIPREPOSE_LIST_MAX_NUM> E_ShentiPrepose_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_ShentiPrepose & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_ShentiPrepose & msg);
		static ::proto_ff::Sheet_ShentiPrepose* new_pbmsg(){ return new ::proto_ff::Sheet_ShentiPrepose(); }
		static ::proto_ff::Sheet_ShentiPrepose make_pbmsg(){ return ::proto_ff::Sheet_ShentiPrepose(); }
	};
	typedef struct Sheet_ShentiPrepose_s Sheet_ShentiPrepose_t;

	struct E_ShentiUpgradeAttributeDesc_s : public NFDescStoreSeqOP {
		E_ShentiUpgradeAttributeDesc_s();
		virtual ~E_ShentiUpgradeAttributeDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_value;//值
		int32_t m_type;//ID

		virtual void write_to_pbmsg(::proto_ff::E_ShentiUpgradeAttributeDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_ShentiUpgradeAttributeDesc & msg);
		static ::proto_ff::E_ShentiUpgradeAttributeDesc* new_pbmsg(){ return new ::proto_ff::E_ShentiUpgradeAttributeDesc(); }
		static ::proto_ff::E_ShentiUpgradeAttributeDesc make_pbmsg(){ return ::proto_ff::E_ShentiUpgradeAttributeDesc(); }
	};
	typedef struct E_ShentiUpgradeAttributeDesc_s E_ShentiUpgradeAttributeDesc_t;

	struct E_ShentiUpgrade_s : public NFDescStoreSeqOP {
		E_ShentiUpgrade_s();
		virtual ~E_ShentiUpgrade_s(){}
		int CreateInit();
		int ResumeInit();
		int64_t m_id;//id
		int32_t m_lv;//等级
		int32_t m_changeLv;//转生等级
		int64_t m_exp;//下级所需神元
		int64_t m_expLimit;//神元储存上限
		NFShmVector<struct E_ShentiUpgradeAttributeDesc_s, DEFINE_E_SHENTIUPGRADE_M_ATTRIBUTE_MAX_NUM> m_attribute;//基础属性

		virtual void write_to_pbmsg(::proto_ff::E_ShentiUpgrade & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_ShentiUpgrade & msg);
		static ::proto_ff::E_ShentiUpgrade* new_pbmsg(){ return new ::proto_ff::E_ShentiUpgrade(); }
		static ::proto_ff::E_ShentiUpgrade make_pbmsg(){ return ::proto_ff::E_ShentiUpgrade(); }
	};
	typedef struct E_ShentiUpgrade_s E_ShentiUpgrade_t;

	struct Sheet_ShentiUpgrade_s : public NFDescStoreSeqOP {
		Sheet_ShentiUpgrade_s();
		virtual ~Sheet_ShentiUpgrade_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_ShentiUpgrade_s, DEFINE_SHEET_SHENTIUPGRADE_E_SHENTIUPGRADE_LIST_MAX_NUM> E_ShentiUpgrade_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_ShentiUpgrade & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_ShentiUpgrade & msg);
		static ::proto_ff::Sheet_ShentiUpgrade* new_pbmsg(){ return new ::proto_ff::Sheet_ShentiUpgrade(); }
		static ::proto_ff::Sheet_ShentiUpgrade make_pbmsg(){ return ::proto_ff::Sheet_ShentiUpgrade(); }
	};
	typedef struct Sheet_ShentiUpgrade_s Sheet_ShentiUpgrade_t;

	struct E_ShentiRemanieAttrDesc_s : public NFDescStoreSeqOP {
		E_ShentiRemanieAttrDesc_s();
		virtual ~E_ShentiRemanieAttrDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_value;//值
		int32_t m_type;//ID

		virtual void write_to_pbmsg(::proto_ff::E_ShentiRemanieAttrDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_ShentiRemanieAttrDesc & msg);
		static ::proto_ff::E_ShentiRemanieAttrDesc* new_pbmsg(){ return new ::proto_ff::E_ShentiRemanieAttrDesc(); }
		static ::proto_ff::E_ShentiRemanieAttrDesc make_pbmsg(){ return ::proto_ff::E_ShentiRemanieAttrDesc(); }
	};
	typedef struct E_ShentiRemanieAttrDesc_s E_ShentiRemanieAttrDesc_t;

	struct E_ShentiRemanie_s : public NFDescStoreSeqOP {
		E_ShentiRemanie_s();
		virtual ~E_ShentiRemanie_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//转生等级
		int32_t m_remanieLv;//转生等级要求
		int32_t m_lv;//等级要求
		int32_t m_tianSuccess;//天时增加成功率
		int32_t m_diSuccess;//地利初始成功率
		int32_t m_loseSuccess;//地利失败提升成功率
		int32_t m_renSuccess;//人和提升成功率
		int32_t m_renSuccessLimit;//人和成功率上限
		int32_t m_reward;//转生奖励
		NFShmVector<struct E_ShentiRemanieAttrDesc_s, DEFINE_E_SHENTIREMANIE_M_ATTR_MAX_NUM> m_attr;//转生属性

		virtual void write_to_pbmsg(::proto_ff::E_ShentiRemanie & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_ShentiRemanie & msg);
		static ::proto_ff::E_ShentiRemanie* new_pbmsg(){ return new ::proto_ff::E_ShentiRemanie(); }
		static ::proto_ff::E_ShentiRemanie make_pbmsg(){ return ::proto_ff::E_ShentiRemanie(); }
	};
	typedef struct E_ShentiRemanie_s E_ShentiRemanie_t;

	struct Sheet_ShentiRemanie_s : public NFDescStoreSeqOP {
		Sheet_ShentiRemanie_s();
		virtual ~Sheet_ShentiRemanie_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_ShentiRemanie_s, DEFINE_SHEET_SHENTIREMANIE_E_SHENTIREMANIE_LIST_MAX_NUM> E_ShentiRemanie_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_ShentiRemanie & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_ShentiRemanie & msg);
		static ::proto_ff::Sheet_ShentiRemanie* new_pbmsg(){ return new ::proto_ff::Sheet_ShentiRemanie(); }
		static ::proto_ff::Sheet_ShentiRemanie make_pbmsg(){ return ::proto_ff::Sheet_ShentiRemanie(); }
	};
	typedef struct Sheet_ShentiRemanie_s Sheet_ShentiRemanie_t;

	struct E_ShentiEquip_s : public NFDescStoreSeqOP {
		E_ShentiEquip_s();
		virtual ~E_ShentiEquip_s(){}
		int CreateInit();
		int ResumeInit();
		int64_t m_id;//装备ID
		NFShmString<64> m_name;//装备名称
		int32_t m_type;//装备大类
		int32_t m_remanieLv;//装备转生
		int32_t m_position;//装备位置
		NFShmString<64> m_profession;//职业限制
		int32_t m_professionLv;//转职等级
		int32_t m_quality;//装备品质
		int32_t m_attributeID;//属性ID
		int32_t m_suitGroup;//套装组
		int32_t m_starGroup;//随机星级属性组
		int32_t m_isCanbind;//是否绑定
		int32_t m_isTradeBind;//是否交易绑定
		int32_t m_sellPrice;//出售价格
		NFShmString<64> m_icon;//装备图标名
		int32_t m_broadcast;//是否播放跑马灯

		virtual void write_to_pbmsg(::proto_ff::E_ShentiEquip & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_ShentiEquip & msg);
		static ::proto_ff::E_ShentiEquip* new_pbmsg(){ return new ::proto_ff::E_ShentiEquip(); }
		static ::proto_ff::E_ShentiEquip make_pbmsg(){ return ::proto_ff::E_ShentiEquip(); }
	};
	typedef struct E_ShentiEquip_s E_ShentiEquip_t;

	struct Sheet_ShentiEquip_s : public NFDescStoreSeqOP {
		Sheet_ShentiEquip_s();
		virtual ~Sheet_ShentiEquip_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_ShentiEquip_s, DEFINE_SHEET_SHENTIEQUIP_E_SHENTIEQUIP_LIST_MAX_NUM> E_ShentiEquip_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_ShentiEquip & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_ShentiEquip & msg);
		static ::proto_ff::Sheet_ShentiEquip* new_pbmsg(){ return new ::proto_ff::Sheet_ShentiEquip(); }
		static ::proto_ff::Sheet_ShentiEquip make_pbmsg(){ return ::proto_ff::Sheet_ShentiEquip(); }
	};
	typedef struct Sheet_ShentiEquip_s Sheet_ShentiEquip_t;

	struct E_ShentiAttributeAttributeDesc_s : public NFDescStoreSeqOP {
		E_ShentiAttributeAttributeDesc_s();
		virtual ~E_ShentiAttributeAttributeDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_value;//数值
		int32_t m_type;//

		virtual void write_to_pbmsg(::proto_ff::E_ShentiAttributeAttributeDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_ShentiAttributeAttributeDesc & msg);
		static ::proto_ff::E_ShentiAttributeAttributeDesc* new_pbmsg(){ return new ::proto_ff::E_ShentiAttributeAttributeDesc(); }
		static ::proto_ff::E_ShentiAttributeAttributeDesc make_pbmsg(){ return ::proto_ff::E_ShentiAttributeAttributeDesc(); }
	};
	typedef struct E_ShentiAttributeAttributeDesc_s E_ShentiAttributeAttributeDesc_t;

	struct E_ShentiAttributeXpcomDesc_s : public NFDescStoreSeqOP {
		E_ShentiAttributeXpcomDesc_s();
		virtual ~E_ShentiAttributeXpcomDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_value;//数值
		int32_t m_type;//

		virtual void write_to_pbmsg(::proto_ff::E_ShentiAttributeXpcomDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_ShentiAttributeXpcomDesc & msg);
		static ::proto_ff::E_ShentiAttributeXpcomDesc* new_pbmsg(){ return new ::proto_ff::E_ShentiAttributeXpcomDesc(); }
		static ::proto_ff::E_ShentiAttributeXpcomDesc make_pbmsg(){ return ::proto_ff::E_ShentiAttributeXpcomDesc(); }
	};
	typedef struct E_ShentiAttributeXpcomDesc_s E_ShentiAttributeXpcomDesc_t;

	struct E_ShentiAttributeXpstarDesc_s : public NFDescStoreSeqOP {
		E_ShentiAttributeXpstarDesc_s();
		virtual ~E_ShentiAttributeXpstarDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_value;//数值
		int32_t m_type;//

		virtual void write_to_pbmsg(::proto_ff::E_ShentiAttributeXpstarDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_ShentiAttributeXpstarDesc & msg);
		static ::proto_ff::E_ShentiAttributeXpstarDesc* new_pbmsg(){ return new ::proto_ff::E_ShentiAttributeXpstarDesc(); }
		static ::proto_ff::E_ShentiAttributeXpstarDesc make_pbmsg(){ return ::proto_ff::E_ShentiAttributeXpstarDesc(); }
	};
	typedef struct E_ShentiAttributeXpstarDesc_s E_ShentiAttributeXpstarDesc_t;

	struct E_ShentiAttributeGodDesc_s : public NFDescStoreSeqOP {
		E_ShentiAttributeGodDesc_s();
		virtual ~E_ShentiAttributeGodDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_value;//数值
		int32_t m_type;//

		virtual void write_to_pbmsg(::proto_ff::E_ShentiAttributeGodDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_ShentiAttributeGodDesc & msg);
		static ::proto_ff::E_ShentiAttributeGodDesc* new_pbmsg(){ return new ::proto_ff::E_ShentiAttributeGodDesc(); }
		static ::proto_ff::E_ShentiAttributeGodDesc make_pbmsg(){ return ::proto_ff::E_ShentiAttributeGodDesc(); }
	};
	typedef struct E_ShentiAttributeGodDesc_s E_ShentiAttributeGodDesc_t;

	struct E_ShentiAttributeSpecialDesc_s : public NFDescStoreSeqOP {
		E_ShentiAttributeSpecialDesc_s();
		virtual ~E_ShentiAttributeSpecialDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_value;//数值
		int32_t m_type;//

		virtual void write_to_pbmsg(::proto_ff::E_ShentiAttributeSpecialDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_ShentiAttributeSpecialDesc & msg);
		static ::proto_ff::E_ShentiAttributeSpecialDesc* new_pbmsg(){ return new ::proto_ff::E_ShentiAttributeSpecialDesc(); }
		static ::proto_ff::E_ShentiAttributeSpecialDesc make_pbmsg(){ return ::proto_ff::E_ShentiAttributeSpecialDesc(); }
	};
	typedef struct E_ShentiAttributeSpecialDesc_s E_ShentiAttributeSpecialDesc_t;

	struct E_ShentiAttribute_s : public NFDescStoreSeqOP {
		E_ShentiAttribute_s();
		virtual ~E_ShentiAttribute_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//属性ID
		NFShmVector<struct E_ShentiAttributeAttributeDesc_s, DEFINE_E_SHENTIATTRIBUTE_M_ATTRIBUTE_MAX_NUM> m_attribute;//基础属性
		NFShmVector<struct E_ShentiAttributeXpcomDesc_s, DEFINE_E_SHENTIATTRIBUTE_M_XPCOM_MAX_NUM> m_xpcom;//星级属性
		NFShmVector<struct E_ShentiAttributeXpstarDesc_s, DEFINE_E_SHENTIATTRIBUTE_M_XPSTAR_MAX_NUM> m_xpstar;//特殊星级属性
		NFShmVector<struct E_ShentiAttributeGodDesc_s, DEFINE_E_SHENTIATTRIBUTE_M_GOD_MAX_NUM> m_god;//神装属性
		NFShmVector<struct E_ShentiAttributeSpecialDesc_s, DEFINE_E_SHENTIATTRIBUTE_M_SPECIAL_MAX_NUM> m_special;//特殊属性

		virtual void write_to_pbmsg(::proto_ff::E_ShentiAttribute & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_ShentiAttribute & msg);
		static ::proto_ff::E_ShentiAttribute* new_pbmsg(){ return new ::proto_ff::E_ShentiAttribute(); }
		static ::proto_ff::E_ShentiAttribute make_pbmsg(){ return ::proto_ff::E_ShentiAttribute(); }
	};
	typedef struct E_ShentiAttribute_s E_ShentiAttribute_t;

	struct Sheet_ShentiAttribute_s : public NFDescStoreSeqOP {
		Sheet_ShentiAttribute_s();
		virtual ~Sheet_ShentiAttribute_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_ShentiAttribute_s, DEFINE_SHEET_SHENTIATTRIBUTE_E_SHENTIATTRIBUTE_LIST_MAX_NUM> E_ShentiAttribute_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_ShentiAttribute & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_ShentiAttribute & msg);
		static ::proto_ff::Sheet_ShentiAttribute* new_pbmsg(){ return new ::proto_ff::Sheet_ShentiAttribute(); }
		static ::proto_ff::Sheet_ShentiAttribute make_pbmsg(){ return ::proto_ff::Sheet_ShentiAttribute(); }
	};
	typedef struct Sheet_ShentiAttribute_s Sheet_ShentiAttribute_t;

	struct E_ShentiStrongMaterialDesc_s : public NFDescStoreSeqOP {
		E_ShentiStrongMaterialDesc_s();
		virtual ~E_ShentiStrongMaterialDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_num;//数量
		int32_t m_id;//

		virtual void write_to_pbmsg(::proto_ff::E_ShentiStrongMaterialDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_ShentiStrongMaterialDesc & msg);
		static ::proto_ff::E_ShentiStrongMaterialDesc* new_pbmsg(){ return new ::proto_ff::E_ShentiStrongMaterialDesc(); }
		static ::proto_ff::E_ShentiStrongMaterialDesc make_pbmsg(){ return ::proto_ff::E_ShentiStrongMaterialDesc(); }
	};
	typedef struct E_ShentiStrongMaterialDesc_s E_ShentiStrongMaterialDesc_t;

	struct E_ShentiStrongAttributeDesc_s : public NFDescStoreSeqOP {
		E_ShentiStrongAttributeDesc_s();
		virtual ~E_ShentiStrongAttributeDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_value;//数值

		virtual void write_to_pbmsg(::proto_ff::E_ShentiStrongAttributeDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_ShentiStrongAttributeDesc & msg);
		static ::proto_ff::E_ShentiStrongAttributeDesc* new_pbmsg(){ return new ::proto_ff::E_ShentiStrongAttributeDesc(); }
		static ::proto_ff::E_ShentiStrongAttributeDesc make_pbmsg(){ return ::proto_ff::E_ShentiStrongAttributeDesc(); }
	};
	typedef struct E_ShentiStrongAttributeDesc_s E_ShentiStrongAttributeDesc_t;

	struct E_ShentiStrong_s : public NFDescStoreSeqOP {
		E_ShentiStrong_s();
		virtual ~E_ShentiStrong_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//id
		int32_t m_lv;//强化等级
		NFShmString<64> m_position;//强化部位
		int32_t m_remanieLv;//装备转生
		NFShmVector<struct E_ShentiStrongMaterialDesc_s, DEFINE_E_SHENTISTRONG_M_MATERIAL_MAX_NUM> m_material;//强化材料
		NFShmVector<struct E_ShentiStrongAttributeDesc_s, DEFINE_E_SHENTISTRONG_M_ATTRIBUTE_MAX_NUM> m_attribute;//强化属性

		virtual void write_to_pbmsg(::proto_ff::E_ShentiStrong & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_ShentiStrong & msg);
		static ::proto_ff::E_ShentiStrong* new_pbmsg(){ return new ::proto_ff::E_ShentiStrong(); }
		static ::proto_ff::E_ShentiStrong make_pbmsg(){ return ::proto_ff::E_ShentiStrong(); }
	};
	typedef struct E_ShentiStrong_s E_ShentiStrong_t;

	struct Sheet_ShentiStrong_s : public NFDescStoreSeqOP {
		Sheet_ShentiStrong_s();
		virtual ~Sheet_ShentiStrong_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_ShentiStrong_s, DEFINE_SHEET_SHENTISTRONG_E_SHENTISTRONG_LIST_MAX_NUM> E_ShentiStrong_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_ShentiStrong & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_ShentiStrong & msg);
		static ::proto_ff::Sheet_ShentiStrong* new_pbmsg(){ return new ::proto_ff::Sheet_ShentiStrong(); }
		static ::proto_ff::Sheet_ShentiStrong make_pbmsg(){ return ::proto_ff::Sheet_ShentiStrong(); }
	};
	typedef struct Sheet_ShentiStrong_s Sheet_ShentiStrong_t;

	struct E_ShentiEvolveAttributeDesc_s : public NFDescStoreSeqOP {
		E_ShentiEvolveAttributeDesc_s();
		virtual ~E_ShentiEvolveAttributeDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_value;//数值
		int32_t m_type;//

		virtual void write_to_pbmsg(::proto_ff::E_ShentiEvolveAttributeDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_ShentiEvolveAttributeDesc & msg);
		static ::proto_ff::E_ShentiEvolveAttributeDesc* new_pbmsg(){ return new ::proto_ff::E_ShentiEvolveAttributeDesc(); }
		static ::proto_ff::E_ShentiEvolveAttributeDesc make_pbmsg(){ return ::proto_ff::E_ShentiEvolveAttributeDesc(); }
	};
	typedef struct E_ShentiEvolveAttributeDesc_s E_ShentiEvolveAttributeDesc_t;

	struct E_ShentiEvolveXpcomDesc_s : public NFDescStoreSeqOP {
		E_ShentiEvolveXpcomDesc_s();
		virtual ~E_ShentiEvolveXpcomDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_weight;//权重

		virtual void write_to_pbmsg(::proto_ff::E_ShentiEvolveXpcomDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_ShentiEvolveXpcomDesc & msg);
		static ::proto_ff::E_ShentiEvolveXpcomDesc* new_pbmsg(){ return new ::proto_ff::E_ShentiEvolveXpcomDesc(); }
		static ::proto_ff::E_ShentiEvolveXpcomDesc make_pbmsg(){ return ::proto_ff::E_ShentiEvolveXpcomDesc(); }
	};
	typedef struct E_ShentiEvolveXpcomDesc_s E_ShentiEvolveXpcomDesc_t;

	struct E_ShentiEvolveXpstarDesc_s : public NFDescStoreSeqOP {
		E_ShentiEvolveXpstarDesc_s();
		virtual ~E_ShentiEvolveXpstarDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_weight;//权重

		virtual void write_to_pbmsg(::proto_ff::E_ShentiEvolveXpstarDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_ShentiEvolveXpstarDesc & msg);
		static ::proto_ff::E_ShentiEvolveXpstarDesc* new_pbmsg(){ return new ::proto_ff::E_ShentiEvolveXpstarDesc(); }
		static ::proto_ff::E_ShentiEvolveXpstarDesc make_pbmsg(){ return ::proto_ff::E_ShentiEvolveXpstarDesc(); }
	};
	typedef struct E_ShentiEvolveXpstarDesc_s E_ShentiEvolveXpstarDesc_t;

	struct E_ShentiEvolve_s : public NFDescStoreSeqOP {
		E_ShentiEvolve_s();
		virtual ~E_ShentiEvolve_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//id
		int32_t m_evolveLv;//进化等级
		NFShmString<64> m_position;//进化部位
		int32_t m_remanieLv;//装备转生
		int32_t m_need_quality;//装备品质要求
		int32_t m_need_star;//装备星级要求
		int32_t m_material_id;//进化材料
		int32_t m_material_num;//进化材料数量
		int32_t m_mallID;//商品ID
		int32_t m_initialValue;//进化初始值
		int32_t m_specialStar;//是否为特殊星级属性
		NFShmVector<struct E_ShentiEvolveAttributeDesc_s, DEFINE_E_SHENTIEVOLVE_M_ATTRIBUTE_MAX_NUM> m_attribute;//进化属性
		NFShmVector<struct E_ShentiEvolveXpcomDesc_s, DEFINE_E_SHENTIEVOLVE_M_XPCOM_MAX_NUM> m_xpcom;//星级属性随机库
		NFShmVector<struct E_ShentiEvolveXpstarDesc_s, DEFINE_E_SHENTIEVOLVE_M_XPSTAR_MAX_NUM> m_xpstar;//特殊星级属性随机库

		virtual void write_to_pbmsg(::proto_ff::E_ShentiEvolve & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_ShentiEvolve & msg);
		static ::proto_ff::E_ShentiEvolve* new_pbmsg(){ return new ::proto_ff::E_ShentiEvolve(); }
		static ::proto_ff::E_ShentiEvolve make_pbmsg(){ return ::proto_ff::E_ShentiEvolve(); }
	};
	typedef struct E_ShentiEvolve_s E_ShentiEvolve_t;

	struct Sheet_ShentiEvolve_s : public NFDescStoreSeqOP {
		Sheet_ShentiEvolve_s();
		virtual ~Sheet_ShentiEvolve_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_ShentiEvolve_s, DEFINE_SHEET_SHENTIEVOLVE_E_SHENTIEVOLVE_LIST_MAX_NUM> E_ShentiEvolve_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_ShentiEvolve & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_ShentiEvolve & msg);
		static ::proto_ff::Sheet_ShentiEvolve* new_pbmsg(){ return new ::proto_ff::Sheet_ShentiEvolve(); }
		static ::proto_ff::Sheet_ShentiEvolve make_pbmsg(){ return ::proto_ff::Sheet_ShentiEvolve(); }
	};
	typedef struct Sheet_ShentiEvolve_s Sheet_ShentiEvolve_t;

	struct E_ShentiEvolveprogress_s : public NFDescStoreSeqOP {
		E_ShentiEvolveprogress_s();
		virtual ~E_ShentiEvolveprogress_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//id
		int32_t m_evolveLv;//进化等级
		int32_t m_remanieLv;//装备转生
		int32_t m_equipQuality;//材料装备品质
		int32_t m_equipStar;//材料装备星级
		NFShmVector<int32_t, DEFINE_E_SHENTIEVOLVEPROGRESS_M_EVOLVE_MAX_NUM> m_evolve;//完美度

		virtual void write_to_pbmsg(::proto_ff::E_ShentiEvolveprogress & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_ShentiEvolveprogress & msg);
		static ::proto_ff::E_ShentiEvolveprogress* new_pbmsg(){ return new ::proto_ff::E_ShentiEvolveprogress(); }
		static ::proto_ff::E_ShentiEvolveprogress make_pbmsg(){ return ::proto_ff::E_ShentiEvolveprogress(); }
	};
	typedef struct E_ShentiEvolveprogress_s E_ShentiEvolveprogress_t;

	struct Sheet_ShentiEvolveprogress_s : public NFDescStoreSeqOP {
		Sheet_ShentiEvolveprogress_s();
		virtual ~Sheet_ShentiEvolveprogress_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_ShentiEvolveprogress_s, DEFINE_SHEET_SHENTIEVOLVEPROGRESS_E_SHENTIEVOLVEPROGRESS_LIST_MAX_NUM> E_ShentiEvolveprogress_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_ShentiEvolveprogress & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_ShentiEvolveprogress & msg);
		static ::proto_ff::Sheet_ShentiEvolveprogress* new_pbmsg(){ return new ::proto_ff::Sheet_ShentiEvolveprogress(); }
		static ::proto_ff::Sheet_ShentiEvolveprogress make_pbmsg(){ return ::proto_ff::Sheet_ShentiEvolveprogress(); }
	};
	typedef struct Sheet_ShentiEvolveprogress_s Sheet_ShentiEvolveprogress_t;

	struct E_ShentiStarlibraryXpcomDesc_s : public NFDescStoreSeqOP {
		E_ShentiStarlibraryXpcomDesc_s();
		virtual ~E_ShentiStarlibraryXpcomDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_value;//数值
		int32_t m_type;//

		virtual void write_to_pbmsg(::proto_ff::E_ShentiStarlibraryXpcomDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_ShentiStarlibraryXpcomDesc & msg);
		static ::proto_ff::E_ShentiStarlibraryXpcomDesc* new_pbmsg(){ return new ::proto_ff::E_ShentiStarlibraryXpcomDesc(); }
		static ::proto_ff::E_ShentiStarlibraryXpcomDesc make_pbmsg(){ return ::proto_ff::E_ShentiStarlibraryXpcomDesc(); }
	};
	typedef struct E_ShentiStarlibraryXpcomDesc_s E_ShentiStarlibraryXpcomDesc_t;

	struct E_ShentiStarlibraryXpstarDesc_s : public NFDescStoreSeqOP {
		E_ShentiStarlibraryXpstarDesc_s();
		virtual ~E_ShentiStarlibraryXpstarDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_value;//数值
		int32_t m_type;//

		virtual void write_to_pbmsg(::proto_ff::E_ShentiStarlibraryXpstarDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_ShentiStarlibraryXpstarDesc & msg);
		static ::proto_ff::E_ShentiStarlibraryXpstarDesc* new_pbmsg(){ return new ::proto_ff::E_ShentiStarlibraryXpstarDesc(); }
		static ::proto_ff::E_ShentiStarlibraryXpstarDesc make_pbmsg(){ return ::proto_ff::E_ShentiStarlibraryXpstarDesc(); }
	};
	typedef struct E_ShentiStarlibraryXpstarDesc_s E_ShentiStarlibraryXpstarDesc_t;

	struct E_ShentiStarlibrary_s : public NFDescStoreSeqOP {
		E_ShentiStarlibrary_s();
		virtual ~E_ShentiStarlibrary_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_starGroup;//随机星级属性组
		NFShmVector<struct E_ShentiStarlibraryXpcomDesc_s, DEFINE_E_SHENTISTARLIBRARY_M_XPCOM_MAX_NUM> m_xpcom;//星级属性
		NFShmVector<struct E_ShentiStarlibraryXpstarDesc_s, DEFINE_E_SHENTISTARLIBRARY_M_XPSTAR_MAX_NUM> m_xpstar;//特殊星级属性

		virtual void write_to_pbmsg(::proto_ff::E_ShentiStarlibrary & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_ShentiStarlibrary & msg);
		static ::proto_ff::E_ShentiStarlibrary* new_pbmsg(){ return new ::proto_ff::E_ShentiStarlibrary(); }
		static ::proto_ff::E_ShentiStarlibrary make_pbmsg(){ return ::proto_ff::E_ShentiStarlibrary(); }
	};
	typedef struct E_ShentiStarlibrary_s E_ShentiStarlibrary_t;

	struct Sheet_ShentiStarlibrary_s : public NFDescStoreSeqOP {
		Sheet_ShentiStarlibrary_s();
		virtual ~Sheet_ShentiStarlibrary_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_ShentiStarlibrary_s, DEFINE_SHEET_SHENTISTARLIBRARY_E_SHENTISTARLIBRARY_LIST_MAX_NUM> E_ShentiStarlibrary_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_ShentiStarlibrary & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_ShentiStarlibrary & msg);
		static ::proto_ff::Sheet_ShentiStarlibrary* new_pbmsg(){ return new ::proto_ff::Sheet_ShentiStarlibrary(); }
		static ::proto_ff::Sheet_ShentiStarlibrary make_pbmsg(){ return ::proto_ff::Sheet_ShentiStarlibrary(); }
	};
	typedef struct Sheet_ShentiStarlibrary_s Sheet_ShentiStarlibrary_t;

	struct E_ShentiAwakenAttributeDesc_s : public NFDescStoreSeqOP {
		E_ShentiAwakenAttributeDesc_s();
		virtual ~E_ShentiAwakenAttributeDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_value;//数值
		int32_t m_type;//

		virtual void write_to_pbmsg(::proto_ff::E_ShentiAwakenAttributeDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_ShentiAwakenAttributeDesc & msg);
		static ::proto_ff::E_ShentiAwakenAttributeDesc* new_pbmsg(){ return new ::proto_ff::E_ShentiAwakenAttributeDesc(); }
		static ::proto_ff::E_ShentiAwakenAttributeDesc make_pbmsg(){ return ::proto_ff::E_ShentiAwakenAttributeDesc(); }
	};
	typedef struct E_ShentiAwakenAttributeDesc_s E_ShentiAwakenAttributeDesc_t;

	struct E_ShentiAwakenAfflatusattDesc_s : public NFDescStoreSeqOP {
		E_ShentiAwakenAfflatusattDesc_s();
		virtual ~E_ShentiAwakenAfflatusattDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_value;//数值
		int32_t m_type;//

		virtual void write_to_pbmsg(::proto_ff::E_ShentiAwakenAfflatusattDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_ShentiAwakenAfflatusattDesc & msg);
		static ::proto_ff::E_ShentiAwakenAfflatusattDesc* new_pbmsg(){ return new ::proto_ff::E_ShentiAwakenAfflatusattDesc(); }
		static ::proto_ff::E_ShentiAwakenAfflatusattDesc make_pbmsg(){ return ::proto_ff::E_ShentiAwakenAfflatusattDesc(); }
	};
	typedef struct E_ShentiAwakenAfflatusattDesc_s E_ShentiAwakenAfflatusattDesc_t;

	struct E_ShentiAwaken_s : public NFDescStoreSeqOP {
		E_ShentiAwaken_s();
		virtual ~E_ShentiAwaken_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//id
		int32_t m_awakenLv;//觉醒等级
		NFShmString<64> m_position;//觉醒部位
		int32_t m_remanieLv;//装备转生
		int32_t m_need_quality;//装备品质要求
		int32_t m_need_star;//装备星级要求
		int32_t m_material_id;//觉醒材料
		int32_t m_material_num;//觉醒材料数量
		int32_t m_mallID;//商品ID
		int32_t m_initialValue;//觉醒初始值
		NFShmVector<struct E_ShentiAwakenAttributeDesc_s, DEFINE_E_SHENTIAWAKEN_M_ATTRIBUTE_MAX_NUM> m_attribute;//觉醒属性
		NFShmVector<struct E_ShentiAwakenAfflatusattDesc_s, DEFINE_E_SHENTIAWAKEN_M_AFFLATUSATT_MAX_NUM> m_afflatusAtt;//神悟属性

		virtual void write_to_pbmsg(::proto_ff::E_ShentiAwaken & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_ShentiAwaken & msg);
		static ::proto_ff::E_ShentiAwaken* new_pbmsg(){ return new ::proto_ff::E_ShentiAwaken(); }
		static ::proto_ff::E_ShentiAwaken make_pbmsg(){ return ::proto_ff::E_ShentiAwaken(); }
	};
	typedef struct E_ShentiAwaken_s E_ShentiAwaken_t;

	struct Sheet_ShentiAwaken_s : public NFDescStoreSeqOP {
		Sheet_ShentiAwaken_s();
		virtual ~Sheet_ShentiAwaken_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_ShentiAwaken_s, DEFINE_SHEET_SHENTIAWAKEN_E_SHENTIAWAKEN_LIST_MAX_NUM> E_ShentiAwaken_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_ShentiAwaken & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_ShentiAwaken & msg);
		static ::proto_ff::Sheet_ShentiAwaken* new_pbmsg(){ return new ::proto_ff::Sheet_ShentiAwaken(); }
		static ::proto_ff::Sheet_ShentiAwaken make_pbmsg(){ return ::proto_ff::Sheet_ShentiAwaken(); }
	};
	typedef struct Sheet_ShentiAwaken_s Sheet_ShentiAwaken_t;

	struct E_ShentiAwakenprogress_s : public NFDescStoreSeqOP {
		E_ShentiAwakenprogress_s();
		virtual ~E_ShentiAwakenprogress_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//id
		int32_t m_awakenLv;//觉醒等级
		int32_t m_remanieLv;//装备转生
		int32_t m_equipQuality;//材料装备品质
		int32_t m_equipStar;//材料装备星级
		NFShmVector<int32_t, DEFINE_E_SHENTIAWAKENPROGRESS_M_AWAKEN_MAX_NUM> m_awaken;//觉醒度

		virtual void write_to_pbmsg(::proto_ff::E_ShentiAwakenprogress & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_ShentiAwakenprogress & msg);
		static ::proto_ff::E_ShentiAwakenprogress* new_pbmsg(){ return new ::proto_ff::E_ShentiAwakenprogress(); }
		static ::proto_ff::E_ShentiAwakenprogress make_pbmsg(){ return ::proto_ff::E_ShentiAwakenprogress(); }
	};
	typedef struct E_ShentiAwakenprogress_s E_ShentiAwakenprogress_t;

	struct Sheet_ShentiAwakenprogress_s : public NFDescStoreSeqOP {
		Sheet_ShentiAwakenprogress_s();
		virtual ~Sheet_ShentiAwakenprogress_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_ShentiAwakenprogress_s, DEFINE_SHEET_SHENTIAWAKENPROGRESS_E_SHENTIAWAKENPROGRESS_LIST_MAX_NUM> E_ShentiAwakenprogress_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_ShentiAwakenprogress & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_ShentiAwakenprogress & msg);
		static ::proto_ff::Sheet_ShentiAwakenprogress* new_pbmsg(){ return new ::proto_ff::Sheet_ShentiAwakenprogress(); }
		static ::proto_ff::Sheet_ShentiAwakenprogress make_pbmsg(){ return ::proto_ff::Sheet_ShentiAwakenprogress(); }
	};
	typedef struct Sheet_ShentiAwakenprogress_s Sheet_ShentiAwakenprogress_t;

	struct E_ShentiSuitAttributeDesc_s : public NFDescStoreSeqOP {
		E_ShentiSuitAttributeDesc_s();
		virtual ~E_ShentiSuitAttributeDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_value;//数值
		int32_t m_type;//

		virtual void write_to_pbmsg(::proto_ff::E_ShentiSuitAttributeDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_ShentiSuitAttributeDesc & msg);
		static ::proto_ff::E_ShentiSuitAttributeDesc* new_pbmsg(){ return new ::proto_ff::E_ShentiSuitAttributeDesc(); }
		static ::proto_ff::E_ShentiSuitAttributeDesc make_pbmsg(){ return ::proto_ff::E_ShentiSuitAttributeDesc(); }
	};
	typedef struct E_ShentiSuitAttributeDesc_s E_ShentiSuitAttributeDesc_t;

	struct E_ShentiSuit_s : public NFDescStoreSeqOP {
		E_ShentiSuit_s();
		virtual ~E_ShentiSuit_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//id
		int32_t m_suitGroup;//套装组
		int32_t m_suitLv;//套装等级
		int32_t m_num;//套装激活件数
		NFShmString<64> m_name;//套装名称
		int32_t m_skill;//套装技能
		NFShmVector<struct E_ShentiSuitAttributeDesc_s, DEFINE_E_SHENTISUIT_M_ATTRIBUTE_MAX_NUM> m_attribute;//套装属性

		virtual void write_to_pbmsg(::proto_ff::E_ShentiSuit & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_ShentiSuit & msg);
		static ::proto_ff::E_ShentiSuit* new_pbmsg(){ return new ::proto_ff::E_ShentiSuit(); }
		static ::proto_ff::E_ShentiSuit make_pbmsg(){ return ::proto_ff::E_ShentiSuit(); }
	};
	typedef struct E_ShentiSuit_s E_ShentiSuit_t;

	struct Sheet_ShentiSuit_s : public NFDescStoreSeqOP {
		Sheet_ShentiSuit_s();
		virtual ~Sheet_ShentiSuit_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_ShentiSuit_s, DEFINE_SHEET_SHENTISUIT_E_SHENTISUIT_LIST_MAX_NUM> E_ShentiSuit_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_ShentiSuit & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_ShentiSuit & msg);
		static ::proto_ff::Sheet_ShentiSuit* new_pbmsg(){ return new ::proto_ff::Sheet_ShentiSuit(); }
		static ::proto_ff::Sheet_ShentiSuit make_pbmsg(){ return ::proto_ff::Sheet_ShentiSuit(); }
	};
	typedef struct Sheet_ShentiSuit_s Sheet_ShentiSuit_t;

	struct E_ShentiCompose_s : public NFDescStoreSeqOP {
		E_ShentiCompose_s();
		virtual ~E_ShentiCompose_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_need_equip;//所需装备id
		int32_t m_target_equip;//目标装备id
		int32_t m_compose_tips;//合成材料

		virtual void write_to_pbmsg(::proto_ff::E_ShentiCompose & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_ShentiCompose & msg);
		static ::proto_ff::E_ShentiCompose* new_pbmsg(){ return new ::proto_ff::E_ShentiCompose(); }
		static ::proto_ff::E_ShentiCompose make_pbmsg(){ return ::proto_ff::E_ShentiCompose(); }
	};
	typedef struct E_ShentiCompose_s E_ShentiCompose_t;

	struct Sheet_ShentiCompose_s : public NFDescStoreSeqOP {
		Sheet_ShentiCompose_s();
		virtual ~Sheet_ShentiCompose_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_ShentiCompose_s, DEFINE_SHEET_SHENTICOMPOSE_E_SHENTICOMPOSE_LIST_MAX_NUM> E_ShentiCompose_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_ShentiCompose & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_ShentiCompose & msg);
		static ::proto_ff::Sheet_ShentiCompose* new_pbmsg(){ return new ::proto_ff::Sheet_ShentiCompose(); }
		static ::proto_ff::Sheet_ShentiCompose make_pbmsg(){ return ::proto_ff::Sheet_ShentiCompose(); }
	};
	typedef struct Sheet_ShentiCompose_s Sheet_ShentiCompose_t;

	struct E_ShentiStar_upMaterialDesc_s : public NFDescStoreSeqOP {
		E_ShentiStar_upMaterialDesc_s();
		virtual ~E_ShentiStar_upMaterialDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_num;//数量
		int32_t m_id;//

		virtual void write_to_pbmsg(::proto_ff::E_ShentiStar_upMaterialDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_ShentiStar_upMaterialDesc & msg);
		static ::proto_ff::E_ShentiStar_upMaterialDesc* new_pbmsg(){ return new ::proto_ff::E_ShentiStar_upMaterialDesc(); }
		static ::proto_ff::E_ShentiStar_upMaterialDesc make_pbmsg(){ return ::proto_ff::E_ShentiStar_upMaterialDesc(); }
	};
	typedef struct E_ShentiStar_upMaterialDesc_s E_ShentiStar_upMaterialDesc_t;

	struct E_ShentiStar_upXpstarDesc_s : public NFDescStoreSeqOP {
		E_ShentiStar_upXpstarDesc_s();
		virtual ~E_ShentiStar_upXpstarDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_weight;//权重

		virtual void write_to_pbmsg(::proto_ff::E_ShentiStar_upXpstarDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_ShentiStar_upXpstarDesc & msg);
		static ::proto_ff::E_ShentiStar_upXpstarDesc* new_pbmsg(){ return new ::proto_ff::E_ShentiStar_upXpstarDesc(); }
		static ::proto_ff::E_ShentiStar_upXpstarDesc make_pbmsg(){ return ::proto_ff::E_ShentiStar_upXpstarDesc(); }
	};
	typedef struct E_ShentiStar_upXpstarDesc_s E_ShentiStar_upXpstarDesc_t;

	struct E_ShentiStar_up_s : public NFDescStoreSeqOP {
		E_ShentiStar_up_s();
		virtual ~E_ShentiStar_up_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//id
		int32_t m_star;//升星星数
		int32_t m_position;//升星部位
		int32_t m_need_quality;//装备品质要求
		NFShmVector<struct E_ShentiStar_upMaterialDesc_s, DEFINE_E_SHENTISTAR_UP_M_MATERIAL_MAX_NUM> m_material;//升星材料
		NFShmVector<struct E_ShentiStar_upXpstarDesc_s, DEFINE_E_SHENTISTAR_UP_M_XPSTAR_MAX_NUM> m_xpstar;//属性

		virtual void write_to_pbmsg(::proto_ff::E_ShentiStar_up & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_ShentiStar_up & msg);
		static ::proto_ff::E_ShentiStar_up* new_pbmsg(){ return new ::proto_ff::E_ShentiStar_up(); }
		static ::proto_ff::E_ShentiStar_up make_pbmsg(){ return ::proto_ff::E_ShentiStar_up(); }
	};
	typedef struct E_ShentiStar_up_s E_ShentiStar_up_t;

	struct Sheet_ShentiStar_up_s : public NFDescStoreSeqOP {
		Sheet_ShentiStar_up_s();
		virtual ~Sheet_ShentiStar_up_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_ShentiStar_up_s, DEFINE_SHEET_SHENTISTAR_UP_E_SHENTISTAR_UP_LIST_MAX_NUM> E_ShentiStar_up_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_ShentiStar_up & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_ShentiStar_up & msg);
		static ::proto_ff::Sheet_ShentiStar_up* new_pbmsg(){ return new ::proto_ff::Sheet_ShentiStar_up(); }
		static ::proto_ff::Sheet_ShentiStar_up make_pbmsg(){ return ::proto_ff::Sheet_ShentiStar_up(); }
	};
	typedef struct Sheet_ShentiStar_up_s Sheet_ShentiStar_up_t;

	struct E_ShentiStrengtitelAttributeDesc_s : public NFDescStoreSeqOP {
		E_ShentiStrengtitelAttributeDesc_s();
		virtual ~E_ShentiStrengtitelAttributeDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_value;//数值
		int32_t m_type;//

		virtual void write_to_pbmsg(::proto_ff::E_ShentiStrengtitelAttributeDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_ShentiStrengtitelAttributeDesc & msg);
		static ::proto_ff::E_ShentiStrengtitelAttributeDesc* new_pbmsg(){ return new ::proto_ff::E_ShentiStrengtitelAttributeDesc(); }
		static ::proto_ff::E_ShentiStrengtitelAttributeDesc make_pbmsg(){ return ::proto_ff::E_ShentiStrengtitelAttributeDesc(); }
	};
	typedef struct E_ShentiStrengtitelAttributeDesc_s E_ShentiStrengtitelAttributeDesc_t;

	struct E_ShentiStrengtitel_s : public NFDescStoreSeqOP {
		E_ShentiStrengtitel_s();
		virtual ~E_ShentiStrengtitel_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//id
		int32_t m_remanieLv;//装备转生
		int32_t m_strengLv;//强化目标
		NFShmVector<struct E_ShentiStrengtitelAttributeDesc_s, DEFINE_E_SHENTISTRENGTITEL_M_ATTRIBUTE_MAX_NUM> m_attribute;//强化属性

		virtual void write_to_pbmsg(::proto_ff::E_ShentiStrengtitel & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_ShentiStrengtitel & msg);
		static ::proto_ff::E_ShentiStrengtitel* new_pbmsg(){ return new ::proto_ff::E_ShentiStrengtitel(); }
		static ::proto_ff::E_ShentiStrengtitel make_pbmsg(){ return ::proto_ff::E_ShentiStrengtitel(); }
	};
	typedef struct E_ShentiStrengtitel_s E_ShentiStrengtitel_t;

	struct Sheet_ShentiStrengtitel_s : public NFDescStoreSeqOP {
		Sheet_ShentiStrengtitel_s();
		virtual ~Sheet_ShentiStrengtitel_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_ShentiStrengtitel_s, DEFINE_SHEET_SHENTISTRENGTITEL_E_SHENTISTRENGTITEL_LIST_MAX_NUM> E_ShentiStrengtitel_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_ShentiStrengtitel & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_ShentiStrengtitel & msg);
		static ::proto_ff::Sheet_ShentiStrengtitel* new_pbmsg(){ return new ::proto_ff::Sheet_ShentiStrengtitel(); }
		static ::proto_ff::Sheet_ShentiStrengtitel make_pbmsg(){ return ::proto_ff::Sheet_ShentiStrengtitel(); }
	};
	typedef struct Sheet_ShentiStrengtitel_s Sheet_ShentiStrengtitel_t;

	struct E_ShentiStartitelAttributeDesc_s : public NFDescStoreSeqOP {
		E_ShentiStartitelAttributeDesc_s();
		virtual ~E_ShentiStartitelAttributeDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_value;//数值
		int32_t m_type;//

		virtual void write_to_pbmsg(::proto_ff::E_ShentiStartitelAttributeDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_ShentiStartitelAttributeDesc & msg);
		static ::proto_ff::E_ShentiStartitelAttributeDesc* new_pbmsg(){ return new ::proto_ff::E_ShentiStartitelAttributeDesc(); }
		static ::proto_ff::E_ShentiStartitelAttributeDesc make_pbmsg(){ return ::proto_ff::E_ShentiStartitelAttributeDesc(); }
	};
	typedef struct E_ShentiStartitelAttributeDesc_s E_ShentiStartitelAttributeDesc_t;

	struct E_ShentiStartitel_s : public NFDescStoreSeqOP {
		E_ShentiStartitel_s();
		virtual ~E_ShentiStartitel_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//id
		int32_t m_num;//星级数量
		NFShmVector<struct E_ShentiStartitelAttributeDesc_s, DEFINE_E_SHENTISTARTITEL_M_ATTRIBUTE_MAX_NUM> m_attribute;//基础属性

		virtual void write_to_pbmsg(::proto_ff::E_ShentiStartitel & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_ShentiStartitel & msg);
		static ::proto_ff::E_ShentiStartitel* new_pbmsg(){ return new ::proto_ff::E_ShentiStartitel(); }
		static ::proto_ff::E_ShentiStartitel make_pbmsg(){ return ::proto_ff::E_ShentiStartitel(); }
	};
	typedef struct E_ShentiStartitel_s E_ShentiStartitel_t;

	struct Sheet_ShentiStartitel_s : public NFDescStoreSeqOP {
		Sheet_ShentiStartitel_s();
		virtual ~Sheet_ShentiStartitel_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_ShentiStartitel_s, DEFINE_SHEET_SHENTISTARTITEL_E_SHENTISTARTITEL_LIST_MAX_NUM> E_ShentiStartitel_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_ShentiStartitel & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_ShentiStartitel & msg);
		static ::proto_ff::Sheet_ShentiStartitel* new_pbmsg(){ return new ::proto_ff::Sheet_ShentiStartitel(); }
		static ::proto_ff::Sheet_ShentiStartitel make_pbmsg(){ return ::proto_ff::Sheet_ShentiStartitel(); }
	};
	typedef struct Sheet_ShentiStartitel_s Sheet_ShentiStartitel_t;

}

