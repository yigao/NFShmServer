#pragma once

#include <stdint.h>
#include <NFComm/NFShmStl/NFShmString.h>
#include <NFComm/NFShmStl/NFShmVector.h>
#include <NFComm/NFShmCore/NFSeqOP.h>
#include <NFComm/NFShmCore/NFShmMgr.h>
#include "E_Jinglian.pb.h"
#include "E_Jinglian_s.h"

#define DEFINE_E_JINGLIANSIMPLE_M_OPEN_ATTR_MAX_NUM 3
#define DEFINE_SHEET_JINGLIANSIMPLE_E_JINGLIANSIMPLE_LIST_MAX_NUM 16
#define DEFINE_E_JINGLIANLV_M_COST_MAX_NUM 3
#define DEFINE_E_JINGLIANLV_M_ATTR_MAX_NUM 6
#define DEFINE_SHEET_JINGLIANLV_E_JINGLIANLV_LIST_MAX_NUM 1024
#define DEFINE_SHEET_JINGLIANRACE_E_JINGLIANRACE_LIST_MAX_NUM 8
#define DEFINE_E_JINGLIANCOST_M_COST_MAX_NUM 2
#define DEFINE_SHEET_JINGLIANCOST_E_JINGLIANCOST_LIST_MAX_NUM 8
#define DEFINE_SHEET_JINGLIANGM_E_JINGLIANGM_LIST_MAX_NUM 16


namespace proto_ff_s {

	struct E_JinglianSimple_s : public NFDescStoreSeqOP {
		E_JinglianSimple_s();
		virtual ~E_JinglianSimple_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_position;//装备部位对应ID
		int32_t m_groupId;//对应属性组ID
		int32_t m_openlv;//开启等级
		int32_t m_default_attrs;//默认属性条数
		NFShmVector<int32_t, DEFINE_E_JINGLIANSIMPLE_M_OPEN_ATTR_MAX_NUM> m_open_attr;//解锁属性精炼等级

		virtual void write_to_pbmsg(::proto_ff::E_JinglianSimple & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_JinglianSimple & msg);
		static ::proto_ff::E_JinglianSimple* new_pbmsg(){ return new ::proto_ff::E_JinglianSimple(); }
		static ::proto_ff::E_JinglianSimple make_pbmsg(){ return ::proto_ff::E_JinglianSimple(); }
	};
	typedef struct E_JinglianSimple_s E_JinglianSimple_t;

	struct Sheet_JinglianSimple_s : public NFDescStoreSeqOP {
		Sheet_JinglianSimple_s();
		virtual ~Sheet_JinglianSimple_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_JinglianSimple_s, DEFINE_SHEET_JINGLIANSIMPLE_E_JINGLIANSIMPLE_LIST_MAX_NUM> E_JinglianSimple_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_JinglianSimple & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_JinglianSimple & msg);
		static ::proto_ff::Sheet_JinglianSimple* new_pbmsg(){ return new ::proto_ff::Sheet_JinglianSimple(); }
		static ::proto_ff::Sheet_JinglianSimple make_pbmsg(){ return ::proto_ff::Sheet_JinglianSimple(); }
	};
	typedef struct Sheet_JinglianSimple_s Sheet_JinglianSimple_t;

	struct E_JinglianLvCostDesc_s : public NFDescStoreSeqOP {
		E_JinglianLvCostDesc_s();
		virtual ~E_JinglianLvCostDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_num;//数量
		int32_t m_item;//id

		virtual void write_to_pbmsg(::proto_ff::E_JinglianLvCostDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_JinglianLvCostDesc & msg);
		static ::proto_ff::E_JinglianLvCostDesc* new_pbmsg(){ return new ::proto_ff::E_JinglianLvCostDesc(); }
		static ::proto_ff::E_JinglianLvCostDesc make_pbmsg(){ return ::proto_ff::E_JinglianLvCostDesc(); }
	};
	typedef struct E_JinglianLvCostDesc_s E_JinglianLvCostDesc_t;

	struct E_JinglianLvAttrDesc_s : public NFDescStoreSeqOP {
		E_JinglianLvAttrDesc_s();
		virtual ~E_JinglianLvAttrDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_value;//值
		int32_t m_id;//id

		virtual void write_to_pbmsg(::proto_ff::E_JinglianLvAttrDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_JinglianLvAttrDesc & msg);
		static ::proto_ff::E_JinglianLvAttrDesc* new_pbmsg(){ return new ::proto_ff::E_JinglianLvAttrDesc(); }
		static ::proto_ff::E_JinglianLvAttrDesc make_pbmsg(){ return ::proto_ff::E_JinglianLvAttrDesc(); }
	};
	typedef struct E_JinglianLvAttrDesc_s E_JinglianLvAttrDesc_t;

	struct E_JinglianLv_s : public NFDescStoreSeqOP {
		E_JinglianLv_s();
		virtual ~E_JinglianLv_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//id
		int32_t m_groupId;//对应属性组ID
		int32_t m_lv;//等级
		NFShmVector<struct E_JinglianLvCostDesc_s, DEFINE_E_JINGLIANLV_M_COST_MAX_NUM> m_cost;//精炼升级
		NFShmVector<struct E_JinglianLvAttrDesc_s, DEFINE_E_JINGLIANLV_M_ATTR_MAX_NUM> m_attr;//属性

		virtual void write_to_pbmsg(::proto_ff::E_JinglianLv & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_JinglianLv & msg);
		static ::proto_ff::E_JinglianLv* new_pbmsg(){ return new ::proto_ff::E_JinglianLv(); }
		static ::proto_ff::E_JinglianLv make_pbmsg(){ return ::proto_ff::E_JinglianLv(); }
	};
	typedef struct E_JinglianLv_s E_JinglianLv_t;

	struct Sheet_JinglianLv_s : public NFDescStoreSeqOP {
		Sheet_JinglianLv_s();
		virtual ~Sheet_JinglianLv_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_JinglianLv_s, DEFINE_SHEET_JINGLIANLV_E_JINGLIANLV_LIST_MAX_NUM> E_JinglianLv_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_JinglianLv & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_JinglianLv & msg);
		static ::proto_ff::Sheet_JinglianLv* new_pbmsg(){ return new ::proto_ff::Sheet_JinglianLv(); }
		static ::proto_ff::Sheet_JinglianLv make_pbmsg(){ return ::proto_ff::Sheet_JinglianLv(); }
	};
	typedef struct Sheet_JinglianLv_s Sheet_JinglianLv_t;

	struct E_JinglianRace_s : public NFDescStoreSeqOP {
		E_JinglianRace_s();
		virtual ~E_JinglianRace_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_quality;//词条品质
		int32_t m_min;//词条品质范围
		int32_t m_max;//词条品质范围
		int32_t m_quanz;//词条抽取权重
		int32_t m_min_1;//词条品质范围
		int32_t m_max_1;//词条品质范围
		int32_t m_quanz_1;//词条抽取权重

		virtual void write_to_pbmsg(::proto_ff::E_JinglianRace & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_JinglianRace & msg);
		static ::proto_ff::E_JinglianRace* new_pbmsg(){ return new ::proto_ff::E_JinglianRace(); }
		static ::proto_ff::E_JinglianRace make_pbmsg(){ return ::proto_ff::E_JinglianRace(); }
	};
	typedef struct E_JinglianRace_s E_JinglianRace_t;

	struct Sheet_JinglianRace_s : public NFDescStoreSeqOP {
		Sheet_JinglianRace_s();
		virtual ~Sheet_JinglianRace_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_JinglianRace_s, DEFINE_SHEET_JINGLIANRACE_E_JINGLIANRACE_LIST_MAX_NUM> E_JinglianRace_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_JinglianRace & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_JinglianRace & msg);
		static ::proto_ff::Sheet_JinglianRace* new_pbmsg(){ return new ::proto_ff::Sheet_JinglianRace(); }
		static ::proto_ff::Sheet_JinglianRace make_pbmsg(){ return ::proto_ff::Sheet_JinglianRace(); }
	};
	typedef struct Sheet_JinglianRace_s Sheet_JinglianRace_t;

	struct E_JinglianCostCostDesc_s : public NFDescStoreSeqOP {
		E_JinglianCostCostDesc_s();
		virtual ~E_JinglianCostCostDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_num;//数量
		int32_t m_item;//id

		virtual void write_to_pbmsg(::proto_ff::E_JinglianCostCostDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_JinglianCostCostDesc & msg);
		static ::proto_ff::E_JinglianCostCostDesc* new_pbmsg(){ return new ::proto_ff::E_JinglianCostCostDesc(); }
		static ::proto_ff::E_JinglianCostCostDesc make_pbmsg(){ return ::proto_ff::E_JinglianCostCostDesc(); }
	};
	typedef struct E_JinglianCostCostDesc_s E_JinglianCostCostDesc_t;

	struct E_JinglianCost_s : public NFDescStoreSeqOP {
		E_JinglianCost_s();
		virtual ~E_JinglianCost_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_lockid;//锁定词条数量
		NFShmVector<struct E_JinglianCostCostDesc_s, DEFINE_E_JINGLIANCOST_M_COST_MAX_NUM> m_cost;//精炼洗属性

		virtual void write_to_pbmsg(::proto_ff::E_JinglianCost & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_JinglianCost & msg);
		static ::proto_ff::E_JinglianCost* new_pbmsg(){ return new ::proto_ff::E_JinglianCost(); }
		static ::proto_ff::E_JinglianCost make_pbmsg(){ return ::proto_ff::E_JinglianCost(); }
	};
	typedef struct E_JinglianCost_s E_JinglianCost_t;

	struct Sheet_JinglianCost_s : public NFDescStoreSeqOP {
		Sheet_JinglianCost_s();
		virtual ~Sheet_JinglianCost_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_JinglianCost_s, DEFINE_SHEET_JINGLIANCOST_E_JINGLIANCOST_LIST_MAX_NUM> E_JinglianCost_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_JinglianCost & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_JinglianCost & msg);
		static ::proto_ff::Sheet_JinglianCost* new_pbmsg(){ return new ::proto_ff::Sheet_JinglianCost(); }
		static ::proto_ff::Sheet_JinglianCost make_pbmsg(){ return ::proto_ff::Sheet_JinglianCost(); }
	};
	typedef struct Sheet_JinglianCost_s Sheet_JinglianCost_t;

	struct E_JinglianGm_s : public NFDescStoreSeqOP {
		E_JinglianGm_s();
		virtual ~E_JinglianGm_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_lv;//精炼共鸣等级
		int32_t m_lock_num;//解锁数量
		int32_t m_lock_quality;//解锁品质
		int32_t m_addval;//加成万分比

		virtual void write_to_pbmsg(::proto_ff::E_JinglianGm & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_JinglianGm & msg);
		static ::proto_ff::E_JinglianGm* new_pbmsg(){ return new ::proto_ff::E_JinglianGm(); }
		static ::proto_ff::E_JinglianGm make_pbmsg(){ return ::proto_ff::E_JinglianGm(); }
	};
	typedef struct E_JinglianGm_s E_JinglianGm_t;

	struct Sheet_JinglianGm_s : public NFDescStoreSeqOP {
		Sheet_JinglianGm_s();
		virtual ~Sheet_JinglianGm_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_JinglianGm_s, DEFINE_SHEET_JINGLIANGM_E_JINGLIANGM_LIST_MAX_NUM> E_JinglianGm_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_JinglianGm & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_JinglianGm & msg);
		static ::proto_ff::Sheet_JinglianGm* new_pbmsg(){ return new ::proto_ff::Sheet_JinglianGm(); }
		static ::proto_ff::Sheet_JinglianGm make_pbmsg(){ return ::proto_ff::Sheet_JinglianGm(); }
	};
	typedef struct Sheet_JinglianGm_s Sheet_JinglianGm_t;

}

