#pragma once

#include <stdint.h>
#include <NFComm/NFShmStl/NFShmString.h>
#include <NFComm/NFShmStl/NFShmVector.h>
#include <NFComm/NFShmCore/NFSeqOP.h>
#include <NFComm/NFShmCore/NFShmMgr.h>
#include "E_Shenequip.pb.h"
#include "E_Shenequip_s.h"

#define DEFINE_SHEET_SHENEQUIPEQUIP_E_SHENEQUIPEQUIP_LIST_MAX_NUM 64
#define DEFINE_E_SHENEQUIPATT_M_ATTRIBUTE_MAX_NUM 4
#define DEFINE_E_SHENEQUIPATT_M_STAR_MAX_NUM 7
#define DEFINE_SHEET_SHENEQUIPATT_E_SHENEQUIPATT_LIST_MAX_NUM 4096
#define DEFINE_E_SHENEQUIPLVUP_M_ATTRIBUTE_MAX_NUM 2
#define DEFINE_SHEET_SHENEQUIPLVUP_E_SHENEQUIPLVUP_LIST_MAX_NUM 4096
#define DEFINE_E_SHENEQUIPCLEAR_M_PERCENT_MAX_NUM 2
#define DEFINE_SHEET_SHENEQUIPCLEAR_E_SHENEQUIPCLEAR_LIST_MAX_NUM 128
#define DEFINE_E_SHENEQUIPAWAKEN_M_ATTRIBUTE_MAX_NUM 6
#define DEFINE_SHEET_SHENEQUIPAWAKEN_E_SHENEQUIPAWAKEN_LIST_MAX_NUM 16
#define DEFINE_E_SHENEQUIPSTARUP_M_MATERIAL_MAX_NUM 2
#define DEFINE_SHEET_SHENEQUIPSTARUP_E_SHENEQUIPSTARUP_LIST_MAX_NUM 128
#define DEFINE_E_SHENEQUIPPREPOSE_M_REWARD_MAX_NUM 5
#define DEFINE_SHEET_SHENEQUIPPREPOSE_E_SHENEQUIPPREPOSE_LIST_MAX_NUM 8
#define DEFINE_SHEET_SHENEQUIPDOMINANCE_E_SHENEQUIPDOMINANCE_LIST_MAX_NUM 8
#define DEFINE_E_SHENEQUIPADVANCED_M_ATTRIBUTE_MAX_NUM 5
#define DEFINE_SHEET_SHENEQUIPADVANCED_E_SHENEQUIPADVANCED_LIST_MAX_NUM 64
#define DEFINE_E_SHENEQUIPTALENT_M_CONDITION_MAX_NUM 2
#define DEFINE_SHEET_SHENEQUIPTALENT_E_SHENEQUIPTALENT_LIST_MAX_NUM 64
#define DEFINE_SHEET_SHENEQUIPTALENTTYPE_E_SHENEQUIPTALENTTYPE_LIST_MAX_NUM 8
#define DEFINE_E_SHENEQUIPPREVIEW_M_REWARD_MAX_NUM 5
#define DEFINE_SHEET_SHENEQUIPPREVIEW_E_SHENEQUIPPREVIEW_LIST_MAX_NUM 8


namespace proto_ff_s {

	struct E_ShenequipEquip_s : public NFDescStoreSeqOP {
		E_ShenequipEquip_s();
		virtual ~E_ShenequipEquip_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//装备ID
		NFShmString<64> m_name;//装备名称
		int32_t m_type;//装备大类
		int32_t m_grade;//装备评级
		int32_t m_subType;//装备子类
		int32_t m_level;//穿戴等级限制
		int32_t m_quality;//装备品质
		int32_t m_star;//初始星级
		int32_t m_attributeID;//属性ID
		NFShmString<64> m_decompose;//分解获得
		int32_t m_isCanbind;//是否绑定
		int32_t m_isTradeBind;//是否交易绑定
		int32_t m_time;//限时装备
		int32_t m_broadcast;//是否播放跑马灯
		int32_t m_exclusiveID;//专属技能
		NFShmString<64> m_secretSkill;//秘技技能
		NFShmString<64> m_crypticSkill;//暗术技能
		NFShmString<64> m_passiveSkill;//被动技能

		virtual void write_to_pbmsg(::proto_ff::E_ShenequipEquip & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_ShenequipEquip & msg);
		static ::proto_ff::E_ShenequipEquip* new_pbmsg(){ return new ::proto_ff::E_ShenequipEquip(); }
		static ::proto_ff::E_ShenequipEquip make_pbmsg(){ return ::proto_ff::E_ShenequipEquip(); }
	};
	typedef struct E_ShenequipEquip_s E_ShenequipEquip_t;

	struct Sheet_ShenequipEquip_s : public NFDescStoreSeqOP {
		Sheet_ShenequipEquip_s();
		virtual ~Sheet_ShenequipEquip_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_ShenequipEquip_s, DEFINE_SHEET_SHENEQUIPEQUIP_E_SHENEQUIPEQUIP_LIST_MAX_NUM> E_ShenequipEquip_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_ShenequipEquip & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_ShenequipEquip & msg);
		static ::proto_ff::Sheet_ShenequipEquip* new_pbmsg(){ return new ::proto_ff::Sheet_ShenequipEquip(); }
		static ::proto_ff::Sheet_ShenequipEquip make_pbmsg(){ return ::proto_ff::Sheet_ShenequipEquip(); }
	};
	typedef struct Sheet_ShenequipEquip_s Sheet_ShenequipEquip_t;

	struct E_ShenequipAttAttributeDesc_s : public NFDescStoreSeqOP {
		E_ShenequipAttAttributeDesc_s();
		virtual ~E_ShenequipAttAttributeDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_value;//数值
		int32_t m_type;//

		virtual void write_to_pbmsg(::proto_ff::E_ShenequipAttAttributeDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_ShenequipAttAttributeDesc & msg);
		static ::proto_ff::E_ShenequipAttAttributeDesc* new_pbmsg(){ return new ::proto_ff::E_ShenequipAttAttributeDesc(); }
		static ::proto_ff::E_ShenequipAttAttributeDesc make_pbmsg(){ return ::proto_ff::E_ShenequipAttAttributeDesc(); }
	};
	typedef struct E_ShenequipAttAttributeDesc_s E_ShenequipAttAttributeDesc_t;

	struct E_ShenequipAttStarDesc_s : public NFDescStoreSeqOP {
		E_ShenequipAttStarDesc_s();
		virtual ~E_ShenequipAttStarDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_value;//数值
		int32_t m_type;//

		virtual void write_to_pbmsg(::proto_ff::E_ShenequipAttStarDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_ShenequipAttStarDesc & msg);
		static ::proto_ff::E_ShenequipAttStarDesc* new_pbmsg(){ return new ::proto_ff::E_ShenequipAttStarDesc(); }
		static ::proto_ff::E_ShenequipAttStarDesc make_pbmsg(){ return ::proto_ff::E_ShenequipAttStarDesc(); }
	};
	typedef struct E_ShenequipAttStarDesc_s E_ShenequipAttStarDesc_t;

	struct E_ShenequipAtt_s : public NFDescStoreSeqOP {
		E_ShenequipAtt_s();
		virtual ~E_ShenequipAtt_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//属性ID
		NFShmVector<struct E_ShenequipAttAttributeDesc_s, DEFINE_E_SHENEQUIPATT_M_ATTRIBUTE_MAX_NUM> m_attribute;//基础属性
		NFShmVector<struct E_ShenequipAttStarDesc_s, DEFINE_E_SHENEQUIPATT_M_STAR_MAX_NUM> m_star;//星级属性

		virtual void write_to_pbmsg(::proto_ff::E_ShenequipAtt & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_ShenequipAtt & msg);
		static ::proto_ff::E_ShenequipAtt* new_pbmsg(){ return new ::proto_ff::E_ShenequipAtt(); }
		static ::proto_ff::E_ShenequipAtt make_pbmsg(){ return ::proto_ff::E_ShenequipAtt(); }
	};
	typedef struct E_ShenequipAtt_s E_ShenequipAtt_t;

	struct Sheet_ShenequipAtt_s : public NFDescStoreSeqOP {
		Sheet_ShenequipAtt_s();
		virtual ~Sheet_ShenequipAtt_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_ShenequipAtt_s, DEFINE_SHEET_SHENEQUIPATT_E_SHENEQUIPATT_LIST_MAX_NUM> E_ShenequipAtt_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_ShenequipAtt & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_ShenequipAtt & msg);
		static ::proto_ff::Sheet_ShenequipAtt* new_pbmsg(){ return new ::proto_ff::Sheet_ShenequipAtt(); }
		static ::proto_ff::Sheet_ShenequipAtt make_pbmsg(){ return ::proto_ff::Sheet_ShenequipAtt(); }
	};
	typedef struct Sheet_ShenequipAtt_s Sheet_ShenequipAtt_t;

	struct E_ShenequipLvupAttributeDesc_s : public NFDescStoreSeqOP {
		E_ShenequipLvupAttributeDesc_s();
		virtual ~E_ShenequipLvupAttributeDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_stepId;//阶段
		int32_t m_lvId;//升级

		virtual void write_to_pbmsg(::proto_ff::E_ShenequipLvupAttributeDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_ShenequipLvupAttributeDesc & msg);
		static ::proto_ff::E_ShenequipLvupAttributeDesc* new_pbmsg(){ return new ::proto_ff::E_ShenequipLvupAttributeDesc(); }
		static ::proto_ff::E_ShenequipLvupAttributeDesc make_pbmsg(){ return ::proto_ff::E_ShenequipLvupAttributeDesc(); }
	};
	typedef struct E_ShenequipLvupAttributeDesc_s E_ShenequipLvupAttributeDesc_t;

	struct E_ShenequipLvup_s : public NFDescStoreSeqOP {
		E_ShenequipLvup_s();
		virtual ~E_ShenequipLvup_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//id
		int32_t m_lv;//注灵等级
		int32_t m_type;//装备大类
		int32_t m_itemID;//升级道具
		int32_t m_num;//升级数量
		int32_t m_advanceItem;//进阶道具
		int32_t m_advanceNum;//进阶数量
		NFShmVector<struct E_ShenequipLvupAttributeDesc_s, DEFINE_E_SHENEQUIPLVUP_M_ATTRIBUTE_MAX_NUM> m_attribute;//属性

		virtual void write_to_pbmsg(::proto_ff::E_ShenequipLvup & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_ShenequipLvup & msg);
		static ::proto_ff::E_ShenequipLvup* new_pbmsg(){ return new ::proto_ff::E_ShenequipLvup(); }
		static ::proto_ff::E_ShenequipLvup make_pbmsg(){ return ::proto_ff::E_ShenequipLvup(); }
	};
	typedef struct E_ShenequipLvup_s E_ShenequipLvup_t;

	struct Sheet_ShenequipLvup_s : public NFDescStoreSeqOP {
		Sheet_ShenequipLvup_s();
		virtual ~Sheet_ShenequipLvup_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_ShenequipLvup_s, DEFINE_SHEET_SHENEQUIPLVUP_E_SHENEQUIPLVUP_LIST_MAX_NUM> E_ShenequipLvup_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_ShenequipLvup & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_ShenequipLvup & msg);
		static ::proto_ff::Sheet_ShenequipLvup* new_pbmsg(){ return new ::proto_ff::Sheet_ShenequipLvup(); }
		static ::proto_ff::Sheet_ShenequipLvup make_pbmsg(){ return ::proto_ff::Sheet_ShenequipLvup(); }
	};
	typedef struct Sheet_ShenequipLvup_s Sheet_ShenequipLvup_t;

	struct E_ShenequipClear_s : public NFDescStoreSeqOP {
		E_ShenequipClear_s();
		virtual ~E_ShenequipClear_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//id
		int32_t m_type;//装备大类
		int32_t m_lv;//等级
		int32_t m_itemID;//铭刻道具
		int32_t m_num;//消耗数量
		int32_t m_breakItem;//突破道具
		int32_t m_breakNum;//突破数量
		int32_t m_breakProgress;//突破进度值
		int32_t m_randomCounts;//随机条目数
		int32_t m_minus;//负数百分比
		int32_t m_nextID;//下段ID
		NFShmVector<int32_t, DEFINE_E_SHENEQUIPCLEAR_M_PERCENT_MAX_NUM> m_percent;//百分比区间值

		virtual void write_to_pbmsg(::proto_ff::E_ShenequipClear & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_ShenequipClear & msg);
		static ::proto_ff::E_ShenequipClear* new_pbmsg(){ return new ::proto_ff::E_ShenequipClear(); }
		static ::proto_ff::E_ShenequipClear make_pbmsg(){ return ::proto_ff::E_ShenequipClear(); }
	};
	typedef struct E_ShenequipClear_s E_ShenequipClear_t;

	struct Sheet_ShenequipClear_s : public NFDescStoreSeqOP {
		Sheet_ShenequipClear_s();
		virtual ~Sheet_ShenequipClear_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_ShenequipClear_s, DEFINE_SHEET_SHENEQUIPCLEAR_E_SHENEQUIPCLEAR_LIST_MAX_NUM> E_ShenequipClear_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_ShenequipClear & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_ShenequipClear & msg);
		static ::proto_ff::Sheet_ShenequipClear* new_pbmsg(){ return new ::proto_ff::Sheet_ShenequipClear(); }
		static ::proto_ff::Sheet_ShenequipClear make_pbmsg(){ return ::proto_ff::Sheet_ShenequipClear(); }
	};
	typedef struct Sheet_ShenequipClear_s Sheet_ShenequipClear_t;

	struct E_ShenequipAwakenAttributeDesc_s : public NFDescStoreSeqOP {
		E_ShenequipAwakenAttributeDesc_s();
		virtual ~E_ShenequipAwakenAttributeDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_value;//数值
		int32_t m_type;//

		virtual void write_to_pbmsg(::proto_ff::E_ShenequipAwakenAttributeDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_ShenequipAwakenAttributeDesc & msg);
		static ::proto_ff::E_ShenequipAwakenAttributeDesc* new_pbmsg(){ return new ::proto_ff::E_ShenequipAwakenAttributeDesc(); }
		static ::proto_ff::E_ShenequipAwakenAttributeDesc make_pbmsg(){ return ::proto_ff::E_ShenequipAwakenAttributeDesc(); }
	};
	typedef struct E_ShenequipAwakenAttributeDesc_s E_ShenequipAwakenAttributeDesc_t;

	struct E_ShenequipAwaken_s : public NFDescStoreSeqOP {
		E_ShenequipAwaken_s();
		virtual ~E_ShenequipAwaken_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//id
		int32_t m_type;//装备大类
		int32_t m_lv;//技能等级
		int32_t m_itemID;//觉醒材料
		int32_t m_num;//材料数量
		int32_t m_awakeSkillID;//觉醒技能
		NFShmVector<struct E_ShenequipAwakenAttributeDesc_s, DEFINE_E_SHENEQUIPAWAKEN_M_ATTRIBUTE_MAX_NUM> m_attribute;//基础属性

		virtual void write_to_pbmsg(::proto_ff::E_ShenequipAwaken & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_ShenequipAwaken & msg);
		static ::proto_ff::E_ShenequipAwaken* new_pbmsg(){ return new ::proto_ff::E_ShenequipAwaken(); }
		static ::proto_ff::E_ShenequipAwaken make_pbmsg(){ return ::proto_ff::E_ShenequipAwaken(); }
	};
	typedef struct E_ShenequipAwaken_s E_ShenequipAwaken_t;

	struct Sheet_ShenequipAwaken_s : public NFDescStoreSeqOP {
		Sheet_ShenequipAwaken_s();
		virtual ~Sheet_ShenequipAwaken_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_ShenequipAwaken_s, DEFINE_SHEET_SHENEQUIPAWAKEN_E_SHENEQUIPAWAKEN_LIST_MAX_NUM> E_ShenequipAwaken_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_ShenequipAwaken & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_ShenequipAwaken & msg);
		static ::proto_ff::Sheet_ShenequipAwaken* new_pbmsg(){ return new ::proto_ff::Sheet_ShenequipAwaken(); }
		static ::proto_ff::Sheet_ShenequipAwaken make_pbmsg(){ return ::proto_ff::Sheet_ShenequipAwaken(); }
	};
	typedef struct Sheet_ShenequipAwaken_s Sheet_ShenequipAwaken_t;

	struct E_ShenequipStarupMaterialDesc_s : public NFDescStoreSeqOP {
		E_ShenequipStarupMaterialDesc_s();
		virtual ~E_ShenequipStarupMaterialDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_star;//星级
		int32_t m_quality;//品质
		int32_t m_num;//数量
		int32_t m_grade;//评级
		int32_t m_type;//类型

		virtual void write_to_pbmsg(::proto_ff::E_ShenequipStarupMaterialDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_ShenequipStarupMaterialDesc & msg);
		static ::proto_ff::E_ShenequipStarupMaterialDesc* new_pbmsg(){ return new ::proto_ff::E_ShenequipStarupMaterialDesc(); }
		static ::proto_ff::E_ShenequipStarupMaterialDesc make_pbmsg(){ return ::proto_ff::E_ShenequipStarupMaterialDesc(); }
	};
	typedef struct E_ShenequipStarupMaterialDesc_s E_ShenequipStarupMaterialDesc_t;

	struct E_ShenequipStarup_s : public NFDescStoreSeqOP {
		E_ShenequipStarup_s();
		virtual ~E_ShenequipStarup_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//id
		int32_t m_grade;//装备评级
		int32_t m_quality;//装备品质
		int32_t m_stars;//装备星级
		int32_t m_nextID;//下级装备
		int32_t m_lastID;//上级装备
		int32_t m_percent;//提升增加的百分比
		NFShmVector<struct E_ShenequipStarupMaterialDesc_s, DEFINE_E_SHENEQUIPSTARUP_M_MATERIAL_MAX_NUM> m_material;//升级材料

		virtual void write_to_pbmsg(::proto_ff::E_ShenequipStarup & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_ShenequipStarup & msg);
		static ::proto_ff::E_ShenequipStarup* new_pbmsg(){ return new ::proto_ff::E_ShenequipStarup(); }
		static ::proto_ff::E_ShenequipStarup make_pbmsg(){ return ::proto_ff::E_ShenequipStarup(); }
	};
	typedef struct E_ShenequipStarup_s E_ShenequipStarup_t;

	struct Sheet_ShenequipStarup_s : public NFDescStoreSeqOP {
		Sheet_ShenequipStarup_s();
		virtual ~Sheet_ShenequipStarup_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_ShenequipStarup_s, DEFINE_SHEET_SHENEQUIPSTARUP_E_SHENEQUIPSTARUP_LIST_MAX_NUM> E_ShenequipStarup_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_ShenequipStarup & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_ShenequipStarup & msg);
		static ::proto_ff::Sheet_ShenequipStarup* new_pbmsg(){ return new ::proto_ff::Sheet_ShenequipStarup(); }
		static ::proto_ff::Sheet_ShenequipStarup make_pbmsg(){ return ::proto_ff::Sheet_ShenequipStarup(); }
	};
	typedef struct Sheet_ShenequipStarup_s Sheet_ShenequipStarup_t;

	struct E_ShenequipPreposeRewardDesc_s : public NFDescStoreSeqOP {
		E_ShenequipPreposeRewardDesc_s();
		virtual ~E_ShenequipPreposeRewardDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_num;//数量
		int32_t m_item;//道具

		virtual void write_to_pbmsg(::proto_ff::E_ShenequipPreposeRewardDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_ShenequipPreposeRewardDesc & msg);
		static ::proto_ff::E_ShenequipPreposeRewardDesc* new_pbmsg(){ return new ::proto_ff::E_ShenequipPreposeRewardDesc(); }
		static ::proto_ff::E_ShenequipPreposeRewardDesc make_pbmsg(){ return ::proto_ff::E_ShenequipPreposeRewardDesc(); }
	};
	typedef struct E_ShenequipPreposeRewardDesc_s E_ShenequipPreposeRewardDesc_t;

	struct E_ShenequipPrepose_s : public NFDescStoreSeqOP {
		E_ShenequipPrepose_s();
		virtual ~E_ShenequipPrepose_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//id
		int32_t m_condition;//条件
		int32_t m_value;//条件值
		NFShmVector<struct E_ShenequipPreposeRewardDesc_s, DEFINE_E_SHENEQUIPPREPOSE_M_REWARD_MAX_NUM> m_reward;//奖励

		virtual void write_to_pbmsg(::proto_ff::E_ShenequipPrepose & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_ShenequipPrepose & msg);
		static ::proto_ff::E_ShenequipPrepose* new_pbmsg(){ return new ::proto_ff::E_ShenequipPrepose(); }
		static ::proto_ff::E_ShenequipPrepose make_pbmsg(){ return ::proto_ff::E_ShenequipPrepose(); }
	};
	typedef struct E_ShenequipPrepose_s E_ShenequipPrepose_t;

	struct Sheet_ShenequipPrepose_s : public NFDescStoreSeqOP {
		Sheet_ShenequipPrepose_s();
		virtual ~Sheet_ShenequipPrepose_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_ShenequipPrepose_s, DEFINE_SHEET_SHENEQUIPPREPOSE_E_SHENEQUIPPREPOSE_LIST_MAX_NUM> E_ShenequipPrepose_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_ShenequipPrepose & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_ShenequipPrepose & msg);
		static ::proto_ff::Sheet_ShenequipPrepose* new_pbmsg(){ return new ::proto_ff::Sheet_ShenequipPrepose(); }
		static ::proto_ff::Sheet_ShenequipPrepose make_pbmsg(){ return ::proto_ff::Sheet_ShenequipPrepose(); }
	};
	typedef struct Sheet_ShenequipPrepose_s Sheet_ShenequipPrepose_t;

	struct E_ShenequipDominance_s : public NFDescStoreSeqOP {
		E_ShenequipDominance_s();
		virtual ~E_ShenequipDominance_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//id
		int32_t m_slotId;//槽位id
		int32_t m_type;//装备大类
		NFShmString<64> m_sign;//标志
		int32_t m_quality;//解锁品质
		int32_t m_star;//解锁星级
		int32_t m_control;//统御属性比例
		int32_t m_secret;//统御秘技比例
		int32_t m_passive;//统御被动比例
		int32_t m_dark;//统御暗术比例

		virtual void write_to_pbmsg(::proto_ff::E_ShenequipDominance & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_ShenequipDominance & msg);
		static ::proto_ff::E_ShenequipDominance* new_pbmsg(){ return new ::proto_ff::E_ShenequipDominance(); }
		static ::proto_ff::E_ShenequipDominance make_pbmsg(){ return ::proto_ff::E_ShenequipDominance(); }
	};
	typedef struct E_ShenequipDominance_s E_ShenequipDominance_t;

	struct Sheet_ShenequipDominance_s : public NFDescStoreSeqOP {
		Sheet_ShenequipDominance_s();
		virtual ~Sheet_ShenequipDominance_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_ShenequipDominance_s, DEFINE_SHEET_SHENEQUIPDOMINANCE_E_SHENEQUIPDOMINANCE_LIST_MAX_NUM> E_ShenequipDominance_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_ShenequipDominance & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_ShenequipDominance & msg);
		static ::proto_ff::Sheet_ShenequipDominance* new_pbmsg(){ return new ::proto_ff::Sheet_ShenequipDominance(); }
		static ::proto_ff::Sheet_ShenequipDominance make_pbmsg(){ return ::proto_ff::Sheet_ShenequipDominance(); }
	};
	typedef struct Sheet_ShenequipDominance_s Sheet_ShenequipDominance_t;

	struct E_ShenequipAdvancedAttributeDesc_s : public NFDescStoreSeqOP {
		E_ShenequipAdvancedAttributeDesc_s();
		virtual ~E_ShenequipAdvancedAttributeDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_value;//值
		int32_t m_type;//

		virtual void write_to_pbmsg(::proto_ff::E_ShenequipAdvancedAttributeDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_ShenequipAdvancedAttributeDesc & msg);
		static ::proto_ff::E_ShenequipAdvancedAttributeDesc* new_pbmsg(){ return new ::proto_ff::E_ShenequipAdvancedAttributeDesc(); }
		static ::proto_ff::E_ShenequipAdvancedAttributeDesc make_pbmsg(){ return ::proto_ff::E_ShenequipAdvancedAttributeDesc(); }
	};
	typedef struct E_ShenequipAdvancedAttributeDesc_s E_ShenequipAdvancedAttributeDesc_t;

	struct E_ShenequipAdvanced_s : public NFDescStoreSeqOP {
		E_ShenequipAdvanced_s();
		virtual ~E_ShenequipAdvanced_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//id
		int32_t m_type;//装备大类
		int32_t m_lv;//进阶等级
		int32_t m_starLimit;//统御总星级要求
		int32_t m_materials;//消耗材料
		int32_t m_num;//材料数量
		int32_t m_luckyMax;//满幸运值
		int32_t m_luckyAdd;//失败增加幸运值
		NFShmVector<struct E_ShenequipAdvancedAttributeDesc_s, DEFINE_E_SHENEQUIPADVANCED_M_ATTRIBUTE_MAX_NUM> m_attribute;//进阶属性

		virtual void write_to_pbmsg(::proto_ff::E_ShenequipAdvanced & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_ShenequipAdvanced & msg);
		static ::proto_ff::E_ShenequipAdvanced* new_pbmsg(){ return new ::proto_ff::E_ShenequipAdvanced(); }
		static ::proto_ff::E_ShenequipAdvanced make_pbmsg(){ return ::proto_ff::E_ShenequipAdvanced(); }
	};
	typedef struct E_ShenequipAdvanced_s E_ShenequipAdvanced_t;

	struct Sheet_ShenequipAdvanced_s : public NFDescStoreSeqOP {
		Sheet_ShenequipAdvanced_s();
		virtual ~Sheet_ShenequipAdvanced_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_ShenequipAdvanced_s, DEFINE_SHEET_SHENEQUIPADVANCED_E_SHENEQUIPADVANCED_LIST_MAX_NUM> E_ShenequipAdvanced_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_ShenequipAdvanced & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_ShenequipAdvanced & msg);
		static ::proto_ff::Sheet_ShenequipAdvanced* new_pbmsg(){ return new ::proto_ff::Sheet_ShenequipAdvanced(); }
		static ::proto_ff::Sheet_ShenequipAdvanced make_pbmsg(){ return ::proto_ff::Sheet_ShenequipAdvanced(); }
	};
	typedef struct Sheet_ShenequipAdvanced_s Sheet_ShenequipAdvanced_t;

	struct E_ShenequipTalentConditionDesc_s : public NFDescStoreSeqOP {
		E_ShenequipTalentConditionDesc_s();
		virtual ~E_ShenequipTalentConditionDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_lv;//等级
		int32_t m_id;//id

		virtual void write_to_pbmsg(::proto_ff::E_ShenequipTalentConditionDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_ShenequipTalentConditionDesc & msg);
		static ::proto_ff::E_ShenequipTalentConditionDesc* new_pbmsg(){ return new ::proto_ff::E_ShenequipTalentConditionDesc(); }
		static ::proto_ff::E_ShenequipTalentConditionDesc make_pbmsg(){ return ::proto_ff::E_ShenequipTalentConditionDesc(); }
	};
	typedef struct E_ShenequipTalentConditionDesc_s E_ShenequipTalentConditionDesc_t;

	struct E_ShenequipTalent_s : public NFDescStoreSeqOP {
		E_ShenequipTalent_s();
		virtual ~E_ShenequipTalent_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//id
		int32_t m_type;//装备大类
		int32_t m_talentType;//天赋大类
		int32_t m_location;//天赋位置
		int32_t m_skillId;//技能id
		int32_t m_lvLImit;//等级上限
		int32_t m_talenLvLimit;//天赋总投入要求
		int32_t m_attribute_value;//天赋升级消耗
		int32_t m_attribute_type;//天赋升级消耗数量
		int32_t m_posX;//坐标x
		int32_t m_posY;//坐标y
		NFShmVector<struct E_ShenequipTalentConditionDesc_s, DEFINE_E_SHENEQUIPTALENT_M_CONDITION_MAX_NUM> m_condition;//前置技能

		virtual void write_to_pbmsg(::proto_ff::E_ShenequipTalent & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_ShenequipTalent & msg);
		static ::proto_ff::E_ShenequipTalent* new_pbmsg(){ return new ::proto_ff::E_ShenequipTalent(); }
		static ::proto_ff::E_ShenequipTalent make_pbmsg(){ return ::proto_ff::E_ShenequipTalent(); }
	};
	typedef struct E_ShenequipTalent_s E_ShenequipTalent_t;

	struct Sheet_ShenequipTalent_s : public NFDescStoreSeqOP {
		Sheet_ShenequipTalent_s();
		virtual ~Sheet_ShenequipTalent_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_ShenequipTalent_s, DEFINE_SHEET_SHENEQUIPTALENT_E_SHENEQUIPTALENT_LIST_MAX_NUM> E_ShenequipTalent_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_ShenequipTalent & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_ShenequipTalent & msg);
		static ::proto_ff::Sheet_ShenequipTalent* new_pbmsg(){ return new ::proto_ff::Sheet_ShenequipTalent(); }
		static ::proto_ff::Sheet_ShenequipTalent make_pbmsg(){ return ::proto_ff::Sheet_ShenequipTalent(); }
	};
	typedef struct Sheet_ShenequipTalent_s Sheet_ShenequipTalent_t;

	struct E_ShenequipTalenttype_s : public NFDescStoreSeqOP {
		E_ShenequipTalenttype_s();
		virtual ~E_ShenequipTalenttype_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//id
		int32_t m_type;//装备大类
		int32_t m_talentType;//天赋大类
		int32_t m_qualityLimit;//神级神机装备品质要求
		int32_t m_starLimit;//神级神机装备星级要求
		int32_t m_talenLvLimit;//天赋总投入要求

		virtual void write_to_pbmsg(::proto_ff::E_ShenequipTalenttype & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_ShenequipTalenttype & msg);
		static ::proto_ff::E_ShenequipTalenttype* new_pbmsg(){ return new ::proto_ff::E_ShenequipTalenttype(); }
		static ::proto_ff::E_ShenequipTalenttype make_pbmsg(){ return ::proto_ff::E_ShenequipTalenttype(); }
	};
	typedef struct E_ShenequipTalenttype_s E_ShenequipTalenttype_t;

	struct Sheet_ShenequipTalenttype_s : public NFDescStoreSeqOP {
		Sheet_ShenequipTalenttype_s();
		virtual ~Sheet_ShenequipTalenttype_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_ShenequipTalenttype_s, DEFINE_SHEET_SHENEQUIPTALENTTYPE_E_SHENEQUIPTALENTTYPE_LIST_MAX_NUM> E_ShenequipTalenttype_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_ShenequipTalenttype & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_ShenequipTalenttype & msg);
		static ::proto_ff::Sheet_ShenequipTalenttype* new_pbmsg(){ return new ::proto_ff::Sheet_ShenequipTalenttype(); }
		static ::proto_ff::Sheet_ShenequipTalenttype make_pbmsg(){ return ::proto_ff::Sheet_ShenequipTalenttype(); }
	};
	typedef struct Sheet_ShenequipTalenttype_s Sheet_ShenequipTalenttype_t;

	struct E_ShenequipPreviewRewardDesc_s : public NFDescStoreSeqOP {
		E_ShenequipPreviewRewardDesc_s();
		virtual ~E_ShenequipPreviewRewardDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_num;//数量
		int32_t m_item;//道具

		virtual void write_to_pbmsg(::proto_ff::E_ShenequipPreviewRewardDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_ShenequipPreviewRewardDesc & msg);
		static ::proto_ff::E_ShenequipPreviewRewardDesc* new_pbmsg(){ return new ::proto_ff::E_ShenequipPreviewRewardDesc(); }
		static ::proto_ff::E_ShenequipPreviewRewardDesc make_pbmsg(){ return ::proto_ff::E_ShenequipPreviewRewardDesc(); }
	};
	typedef struct E_ShenequipPreviewRewardDesc_s E_ShenequipPreviewRewardDesc_t;

	struct E_ShenequipPreview_s : public NFDescStoreSeqOP {
		E_ShenequipPreview_s();
		virtual ~E_ShenequipPreview_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//id
		int32_t m_condition;//条件
		int32_t m_value;//条件值
		NFShmVector<struct E_ShenequipPreviewRewardDesc_s, DEFINE_E_SHENEQUIPPREVIEW_M_REWARD_MAX_NUM> m_reward;//奖励

		virtual void write_to_pbmsg(::proto_ff::E_ShenequipPreview & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_ShenequipPreview & msg);
		static ::proto_ff::E_ShenequipPreview* new_pbmsg(){ return new ::proto_ff::E_ShenequipPreview(); }
		static ::proto_ff::E_ShenequipPreview make_pbmsg(){ return ::proto_ff::E_ShenequipPreview(); }
	};
	typedef struct E_ShenequipPreview_s E_ShenequipPreview_t;

	struct Sheet_ShenequipPreview_s : public NFDescStoreSeqOP {
		Sheet_ShenequipPreview_s();
		virtual ~Sheet_ShenequipPreview_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_ShenequipPreview_s, DEFINE_SHEET_SHENEQUIPPREVIEW_E_SHENEQUIPPREVIEW_LIST_MAX_NUM> E_ShenequipPreview_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_ShenequipPreview & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_ShenequipPreview & msg);
		static ::proto_ff::Sheet_ShenequipPreview* new_pbmsg(){ return new ::proto_ff::Sheet_ShenequipPreview(); }
		static ::proto_ff::Sheet_ShenequipPreview make_pbmsg(){ return ::proto_ff::Sheet_ShenequipPreview(); }
	};
	typedef struct Sheet_ShenequipPreview_s Sheet_ShenequipPreview_t;

}

