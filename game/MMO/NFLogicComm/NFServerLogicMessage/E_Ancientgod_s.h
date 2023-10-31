#pragma once

#include <stdint.h>
#include <NFComm/NFShmStl/NFShmString.h>
#include <NFComm/NFShmStl/NFShmVector.h>
#include <NFComm/NFShmCore/NFSeqOP.h>
#include <NFComm/NFShmCore/NFShmMgr.h>
#include "E_Ancientgod.pb.h"
#include "E_Ancientgod_s.h"

#define DEFINE_E_ANCIENTGODANCIENTGOD_M_FRA_MAX_NUM 3
#define DEFINE_SHEET_ANCIENTGODANCIENTGOD_E_ANCIENTGODANCIENTGOD_LIST_MAX_NUM 16
#define DEFINE_E_ANCIENTGODLVUP_M_ATTRIBUTE_MAX_NUM 2
#define DEFINE_SHEET_ANCIENTGODLVUP_E_ANCIENTGODLVUP_LIST_MAX_NUM 2048
#define DEFINE_SHEET_ANCIENTGODEQUIPVALUE_E_ANCIENTGODEQUIPVALUE_LIST_MAX_NUM 64
#define DEFINE_E_ANCIENTGODBLESS_M_ATTRIBUTE_MAX_NUM 5
#define DEFINE_SHEET_ANCIENTGODBLESS_E_ANCIENTGODBLESS_LIST_MAX_NUM 128
#define DEFINE_E_ANCIENTGODADVANCE_M_ATTRIBUTE_MAX_NUM 20
#define DEFINE_SHEET_ANCIENTGODADVANCE_E_ANCIENTGODADVANCE_LIST_MAX_NUM 128
#define DEFINE_E_ANCIENTGODATT_M_ATTRIBUTE_MAX_NUM 5
#define DEFINE_SHEET_ANCIENTGODATT_E_ANCIENTGODATT_LIST_MAX_NUM 2048
#define DEFINE_E_ANCIENTGODSTARCOLLECT_M_ATTRIBUTE_MAX_NUM 2
#define DEFINE_SHEET_ANCIENTGODSTARCOLLECT_E_ANCIENTGODSTARCOLLECT_LIST_MAX_NUM 1024


namespace proto_ff_s {

	struct E_AncientgodAncientgodFraDesc_s : public NFDescStoreSeqOP {
		E_AncientgodAncientgodFraDesc_s();
		virtual ~E_AncientgodAncientgodFraDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_attID;//解锁获得属性ID
		int32_t m_num;//解锁数量

		virtual void write_to_pbmsg(::proto_ff::E_AncientgodAncientgodFraDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_AncientgodAncientgodFraDesc & msg);
		static ::proto_ff::E_AncientgodAncientgodFraDesc* new_pbmsg(){ return new ::proto_ff::E_AncientgodAncientgodFraDesc(); }
		static ::proto_ff::E_AncientgodAncientgodFraDesc make_pbmsg(){ return ::proto_ff::E_AncientgodAncientgodFraDesc(); }
	};
	typedef struct E_AncientgodAncientgodFraDesc_s E_AncientgodAncientgodFraDesc_t;

	struct E_AncientgodAncientgod_s : public NFDescStoreSeqOP {
		E_AncientgodAncientgod_s();
		virtual ~E_AncientgodAncientgod_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//神灵ID
		NFShmString<64> m_name;//神灵名称
		float m_parama;//神灵品质系数
		int32_t m_showLv;//神灵显示等级
		int32_t m_unlockLv;//神灵解锁等级
		NFShmString<64> m_condition;//解锁条件
		int32_t m_lvLimit;//进阶等级上限
		int32_t m_stars;//部位进阶星数
		NFShmVector<struct E_AncientgodAncientgodFraDesc_s, DEFINE_E_ANCIENTGODANCIENTGOD_M_FRA_MAX_NUM> m_fra;//碎片

		virtual void write_to_pbmsg(::proto_ff::E_AncientgodAncientgod & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_AncientgodAncientgod & msg);
		static ::proto_ff::E_AncientgodAncientgod* new_pbmsg(){ return new ::proto_ff::E_AncientgodAncientgod(); }
		static ::proto_ff::E_AncientgodAncientgod make_pbmsg(){ return ::proto_ff::E_AncientgodAncientgod(); }
	};
	typedef struct E_AncientgodAncientgod_s E_AncientgodAncientgod_t;

	struct Sheet_AncientgodAncientgod_s : public NFDescStoreSeqOP {
		Sheet_AncientgodAncientgod_s();
		virtual ~Sheet_AncientgodAncientgod_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_AncientgodAncientgod_s, DEFINE_SHEET_ANCIENTGODANCIENTGOD_E_ANCIENTGODANCIENTGOD_LIST_MAX_NUM> E_AncientgodAncientgod_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_AncientgodAncientgod & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_AncientgodAncientgod & msg);
		static ::proto_ff::Sheet_AncientgodAncientgod* new_pbmsg(){ return new ::proto_ff::Sheet_AncientgodAncientgod(); }
		static ::proto_ff::Sheet_AncientgodAncientgod make_pbmsg(){ return ::proto_ff::Sheet_AncientgodAncientgod(); }
	};
	typedef struct Sheet_AncientgodAncientgod_s Sheet_AncientgodAncientgod_t;

	struct E_AncientgodLvupAttributeDesc_s : public NFDescStoreSeqOP {
		E_AncientgodLvupAttributeDesc_s();
		virtual ~E_AncientgodLvupAttributeDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_value;//数值
		int32_t m_type;//

		virtual void write_to_pbmsg(::proto_ff::E_AncientgodLvupAttributeDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_AncientgodLvupAttributeDesc & msg);
		static ::proto_ff::E_AncientgodLvupAttributeDesc* new_pbmsg(){ return new ::proto_ff::E_AncientgodLvupAttributeDesc(); }
		static ::proto_ff::E_AncientgodLvupAttributeDesc make_pbmsg(){ return ::proto_ff::E_AncientgodLvupAttributeDesc(); }
	};
	typedef struct E_AncientgodLvupAttributeDesc_s E_AncientgodLvupAttributeDesc_t;

	struct E_AncientgodLvup_s : public NFDescStoreSeqOP {
		E_AncientgodLvup_s();
		virtual ~E_AncientgodLvup_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//id
		int32_t m_lv;//部位等级
		int32_t m_ancientID;//神灵ID
		int32_t m_itemID;//升级道具
		int32_t m_mallID;//商品ID
		int32_t m_num;//升级数量
		int32_t m_initialValue;//进阶初始值
		int32_t m_position;//部位类型
		NFShmVector<struct E_AncientgodLvupAttributeDesc_s, DEFINE_E_ANCIENTGODLVUP_M_ATTRIBUTE_MAX_NUM> m_attribute;//基础属性

		virtual void write_to_pbmsg(::proto_ff::E_AncientgodLvup & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_AncientgodLvup & msg);
		static ::proto_ff::E_AncientgodLvup* new_pbmsg(){ return new ::proto_ff::E_AncientgodLvup(); }
		static ::proto_ff::E_AncientgodLvup make_pbmsg(){ return ::proto_ff::E_AncientgodLvup(); }
	};
	typedef struct E_AncientgodLvup_s E_AncientgodLvup_t;

	struct Sheet_AncientgodLvup_s : public NFDescStoreSeqOP {
		Sheet_AncientgodLvup_s();
		virtual ~Sheet_AncientgodLvup_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_AncientgodLvup_s, DEFINE_SHEET_ANCIENTGODLVUP_E_ANCIENTGODLVUP_LIST_MAX_NUM> E_AncientgodLvup_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_AncientgodLvup & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_AncientgodLvup & msg);
		static ::proto_ff::Sheet_AncientgodLvup* new_pbmsg(){ return new ::proto_ff::Sheet_AncientgodLvup(); }
		static ::proto_ff::Sheet_AncientgodLvup make_pbmsg(){ return ::proto_ff::Sheet_AncientgodLvup(); }
	};
	typedef struct Sheet_AncientgodLvup_s Sheet_AncientgodLvup_t;

	struct E_AncientgodEquipvalue_s : public NFDescStoreSeqOP {
		E_AncientgodEquipvalue_s();
		virtual ~E_AncientgodEquipvalue_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//id
		int32_t m_quality;//装备品质
		int32_t m_wearQuality;//装备品阶
		int32_t m_star;//星级
		int32_t m_value;//初始进度值

		virtual void write_to_pbmsg(::proto_ff::E_AncientgodEquipvalue & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_AncientgodEquipvalue & msg);
		static ::proto_ff::E_AncientgodEquipvalue* new_pbmsg(){ return new ::proto_ff::E_AncientgodEquipvalue(); }
		static ::proto_ff::E_AncientgodEquipvalue make_pbmsg(){ return ::proto_ff::E_AncientgodEquipvalue(); }
	};
	typedef struct E_AncientgodEquipvalue_s E_AncientgodEquipvalue_t;

	struct Sheet_AncientgodEquipvalue_s : public NFDescStoreSeqOP {
		Sheet_AncientgodEquipvalue_s();
		virtual ~Sheet_AncientgodEquipvalue_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_AncientgodEquipvalue_s, DEFINE_SHEET_ANCIENTGODEQUIPVALUE_E_ANCIENTGODEQUIPVALUE_LIST_MAX_NUM> E_AncientgodEquipvalue_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_AncientgodEquipvalue & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_AncientgodEquipvalue & msg);
		static ::proto_ff::Sheet_AncientgodEquipvalue* new_pbmsg(){ return new ::proto_ff::Sheet_AncientgodEquipvalue(); }
		static ::proto_ff::Sheet_AncientgodEquipvalue make_pbmsg(){ return ::proto_ff::Sheet_AncientgodEquipvalue(); }
	};
	typedef struct Sheet_AncientgodEquipvalue_s Sheet_AncientgodEquipvalue_t;

	struct E_AncientgodBlessAttributeDesc_s : public NFDescStoreSeqOP {
		E_AncientgodBlessAttributeDesc_s();
		virtual ~E_AncientgodBlessAttributeDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_value;//数值
		int32_t m_type;//

		virtual void write_to_pbmsg(::proto_ff::E_AncientgodBlessAttributeDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_AncientgodBlessAttributeDesc & msg);
		static ::proto_ff::E_AncientgodBlessAttributeDesc* new_pbmsg(){ return new ::proto_ff::E_AncientgodBlessAttributeDesc(); }
		static ::proto_ff::E_AncientgodBlessAttributeDesc make_pbmsg(){ return ::proto_ff::E_AncientgodBlessAttributeDesc(); }
	};
	typedef struct E_AncientgodBlessAttributeDesc_s E_AncientgodBlessAttributeDesc_t;

	struct E_AncientgodBless_s : public NFDescStoreSeqOP {
		E_AncientgodBless_s();
		virtual ~E_AncientgodBless_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//id
		int32_t m_ancientID;//神灵ID
		int32_t m_position;//部位ID
		int32_t m_itemID;//祝福消耗道具
		int32_t m_num;//消耗数量
		NFShmVector<struct E_AncientgodBlessAttributeDesc_s, DEFINE_E_ANCIENTGODBLESS_M_ATTRIBUTE_MAX_NUM> m_attribute;//基础属性

		virtual void write_to_pbmsg(::proto_ff::E_AncientgodBless & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_AncientgodBless & msg);
		static ::proto_ff::E_AncientgodBless* new_pbmsg(){ return new ::proto_ff::E_AncientgodBless(); }
		static ::proto_ff::E_AncientgodBless make_pbmsg(){ return ::proto_ff::E_AncientgodBless(); }
	};
	typedef struct E_AncientgodBless_s E_AncientgodBless_t;

	struct Sheet_AncientgodBless_s : public NFDescStoreSeqOP {
		Sheet_AncientgodBless_s();
		virtual ~Sheet_AncientgodBless_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_AncientgodBless_s, DEFINE_SHEET_ANCIENTGODBLESS_E_ANCIENTGODBLESS_LIST_MAX_NUM> E_AncientgodBless_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_AncientgodBless & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_AncientgodBless & msg);
		static ::proto_ff::Sheet_AncientgodBless* new_pbmsg(){ return new ::proto_ff::Sheet_AncientgodBless(); }
		static ::proto_ff::Sheet_AncientgodBless make_pbmsg(){ return ::proto_ff::Sheet_AncientgodBless(); }
	};
	typedef struct Sheet_AncientgodBless_s Sheet_AncientgodBless_t;

	struct E_AncientgodAdvanceAttributeDesc_s : public NFDescStoreSeqOP {
		E_AncientgodAdvanceAttributeDesc_s();
		virtual ~E_AncientgodAdvanceAttributeDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_star;//星级
		int32_t m_value;//数值
		int32_t m_type;//类型

		virtual void write_to_pbmsg(::proto_ff::E_AncientgodAdvanceAttributeDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_AncientgodAdvanceAttributeDesc & msg);
		static ::proto_ff::E_AncientgodAdvanceAttributeDesc* new_pbmsg(){ return new ::proto_ff::E_AncientgodAdvanceAttributeDesc(); }
		static ::proto_ff::E_AncientgodAdvanceAttributeDesc make_pbmsg(){ return ::proto_ff::E_AncientgodAdvanceAttributeDesc(); }
	};
	typedef struct E_AncientgodAdvanceAttributeDesc_s E_AncientgodAdvanceAttributeDesc_t;

	struct E_AncientgodAdvance_s : public NFDescStoreSeqOP {
		E_AncientgodAdvance_s();
		virtual ~E_AncientgodAdvance_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//id
		int32_t m_ancientID;//神灵ID
		int32_t m_position;//部位ID
		NFShmVector<struct E_AncientgodAdvanceAttributeDesc_s, DEFINE_E_ANCIENTGODADVANCE_M_ATTRIBUTE_MAX_NUM> m_attribute;//属性ID

		virtual void write_to_pbmsg(::proto_ff::E_AncientgodAdvance & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_AncientgodAdvance & msg);
		static ::proto_ff::E_AncientgodAdvance* new_pbmsg(){ return new ::proto_ff::E_AncientgodAdvance(); }
		static ::proto_ff::E_AncientgodAdvance make_pbmsg(){ return ::proto_ff::E_AncientgodAdvance(); }
	};
	typedef struct E_AncientgodAdvance_s E_AncientgodAdvance_t;

	struct Sheet_AncientgodAdvance_s : public NFDescStoreSeqOP {
		Sheet_AncientgodAdvance_s();
		virtual ~Sheet_AncientgodAdvance_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_AncientgodAdvance_s, DEFINE_SHEET_ANCIENTGODADVANCE_E_ANCIENTGODADVANCE_LIST_MAX_NUM> E_AncientgodAdvance_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_AncientgodAdvance & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_AncientgodAdvance & msg);
		static ::proto_ff::Sheet_AncientgodAdvance* new_pbmsg(){ return new ::proto_ff::Sheet_AncientgodAdvance(); }
		static ::proto_ff::Sheet_AncientgodAdvance make_pbmsg(){ return ::proto_ff::Sheet_AncientgodAdvance(); }
	};
	typedef struct Sheet_AncientgodAdvance_s Sheet_AncientgodAdvance_t;

	struct E_AncientgodAttAttributeDesc_s : public NFDescStoreSeqOP {
		E_AncientgodAttAttributeDesc_s();
		virtual ~E_AncientgodAttAttributeDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_value;//数值
		int32_t m_type;//

		virtual void write_to_pbmsg(::proto_ff::E_AncientgodAttAttributeDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_AncientgodAttAttributeDesc & msg);
		static ::proto_ff::E_AncientgodAttAttributeDesc* new_pbmsg(){ return new ::proto_ff::E_AncientgodAttAttributeDesc(); }
		static ::proto_ff::E_AncientgodAttAttributeDesc make_pbmsg(){ return ::proto_ff::E_AncientgodAttAttributeDesc(); }
	};
	typedef struct E_AncientgodAttAttributeDesc_s E_AncientgodAttAttributeDesc_t;

	struct E_AncientgodAtt_s : public NFDescStoreSeqOP {
		E_AncientgodAtt_s();
		virtual ~E_AncientgodAtt_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//属性ID
		NFShmVector<struct E_AncientgodAttAttributeDesc_s, DEFINE_E_ANCIENTGODATT_M_ATTRIBUTE_MAX_NUM> m_attribute;//基础属性

		virtual void write_to_pbmsg(::proto_ff::E_AncientgodAtt & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_AncientgodAtt & msg);
		static ::proto_ff::E_AncientgodAtt* new_pbmsg(){ return new ::proto_ff::E_AncientgodAtt(); }
		static ::proto_ff::E_AncientgodAtt make_pbmsg(){ return ::proto_ff::E_AncientgodAtt(); }
	};
	typedef struct E_AncientgodAtt_s E_AncientgodAtt_t;

	struct Sheet_AncientgodAtt_s : public NFDescStoreSeqOP {
		Sheet_AncientgodAtt_s();
		virtual ~Sheet_AncientgodAtt_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_AncientgodAtt_s, DEFINE_SHEET_ANCIENTGODATT_E_ANCIENTGODATT_LIST_MAX_NUM> E_AncientgodAtt_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_AncientgodAtt & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_AncientgodAtt & msg);
		static ::proto_ff::Sheet_AncientgodAtt* new_pbmsg(){ return new ::proto_ff::Sheet_AncientgodAtt(); }
		static ::proto_ff::Sheet_AncientgodAtt make_pbmsg(){ return ::proto_ff::Sheet_AncientgodAtt(); }
	};
	typedef struct Sheet_AncientgodAtt_s Sheet_AncientgodAtt_t;

	struct E_AncientgodStarcollectAttributeDesc_s : public NFDescStoreSeqOP {
		E_AncientgodStarcollectAttributeDesc_s();
		virtual ~E_AncientgodStarcollectAttributeDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_value;//数值
		int32_t m_type;//

		virtual void write_to_pbmsg(::proto_ff::E_AncientgodStarcollectAttributeDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_AncientgodStarcollectAttributeDesc & msg);
		static ::proto_ff::E_AncientgodStarcollectAttributeDesc* new_pbmsg(){ return new ::proto_ff::E_AncientgodStarcollectAttributeDesc(); }
		static ::proto_ff::E_AncientgodStarcollectAttributeDesc make_pbmsg(){ return ::proto_ff::E_AncientgodStarcollectAttributeDesc(); }
	};
	typedef struct E_AncientgodStarcollectAttributeDesc_s E_AncientgodStarcollectAttributeDesc_t;

	struct E_AncientgodStarcollect_s : public NFDescStoreSeqOP {
		E_AncientgodStarcollect_s();
		virtual ~E_AncientgodStarcollect_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//星数
		NFShmVector<struct E_AncientgodStarcollectAttributeDesc_s, DEFINE_E_ANCIENTGODSTARCOLLECT_M_ATTRIBUTE_MAX_NUM> m_attribute;//基础属性

		virtual void write_to_pbmsg(::proto_ff::E_AncientgodStarcollect & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_AncientgodStarcollect & msg);
		static ::proto_ff::E_AncientgodStarcollect* new_pbmsg(){ return new ::proto_ff::E_AncientgodStarcollect(); }
		static ::proto_ff::E_AncientgodStarcollect make_pbmsg(){ return ::proto_ff::E_AncientgodStarcollect(); }
	};
	typedef struct E_AncientgodStarcollect_s E_AncientgodStarcollect_t;

	struct Sheet_AncientgodStarcollect_s : public NFDescStoreSeqOP {
		Sheet_AncientgodStarcollect_s();
		virtual ~Sheet_AncientgodStarcollect_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_AncientgodStarcollect_s, DEFINE_SHEET_ANCIENTGODSTARCOLLECT_E_ANCIENTGODSTARCOLLECT_LIST_MAX_NUM> E_AncientgodStarcollect_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_AncientgodStarcollect & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_AncientgodStarcollect & msg);
		static ::proto_ff::Sheet_AncientgodStarcollect* new_pbmsg(){ return new ::proto_ff::Sheet_AncientgodStarcollect(); }
		static ::proto_ff::Sheet_AncientgodStarcollect make_pbmsg(){ return ::proto_ff::Sheet_AncientgodStarcollect(); }
	};
	typedef struct Sheet_AncientgodStarcollect_s Sheet_AncientgodStarcollect_t;

}

