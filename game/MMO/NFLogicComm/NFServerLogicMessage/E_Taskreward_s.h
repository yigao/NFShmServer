#pragma once

#include <stdint.h>
#include <NFComm/NFShmStl/NFShmString.h>
#include <NFComm/NFShmStl/NFShmVector.h>
#include <NFComm/NFShmCore/NFSeqOP.h>
#include <NFComm/NFShmCore/NFShmMgr.h>
#include "E_Taskreward.pb.h"
#include "E_Taskreward_s.h"

#define DEFINE_E_TASKREWARDTASKREWARD_M_ATTR_MAX_NUM 5
#define DEFINE_E_TASKREWARDTASKREWARD_M_ITEM_MAX_NUM 5
#define DEFINE_SHEET_TASKREWARDTASKREWARD_E_TASKREWARDTASKREWARD_LIST_MAX_NUM 8192
#define DEFINE_SHEET_TASKREWARDTASKTYPE_E_TASKREWARDTASKTYPE_LIST_MAX_NUM 4


namespace proto_ff_s {

	struct E_TaskrewardTaskrewardAttrDesc_s : public NFDescStoreSeqOP {
		E_TaskrewardTaskrewardAttrDesc_s();
		virtual ~E_TaskrewardTaskrewardAttrDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int64_t m_val;//值
		int64_t m_id;//id

		virtual void write_to_pbmsg(::proto_ff::E_TaskrewardTaskrewardAttrDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_TaskrewardTaskrewardAttrDesc & msg);
		static ::proto_ff::E_TaskrewardTaskrewardAttrDesc* new_pbmsg(){ return new ::proto_ff::E_TaskrewardTaskrewardAttrDesc(); }
		static ::proto_ff::E_TaskrewardTaskrewardAttrDesc make_pbmsg(){ return ::proto_ff::E_TaskrewardTaskrewardAttrDesc(); }
	};
	typedef struct E_TaskrewardTaskrewardAttrDesc_s E_TaskrewardTaskrewardAttrDesc_t;

	struct E_TaskrewardTaskrewardItemDesc_s : public NFDescStoreSeqOP {
		E_TaskrewardTaskrewardItemDesc_s();
		virtual ~E_TaskrewardTaskrewardItemDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_prof;//职业
		int32_t m_bind;//绑定
		int32_t m_val;//数量
		int64_t m_id;//id

		virtual void write_to_pbmsg(::proto_ff::E_TaskrewardTaskrewardItemDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_TaskrewardTaskrewardItemDesc & msg);
		static ::proto_ff::E_TaskrewardTaskrewardItemDesc* new_pbmsg(){ return new ::proto_ff::E_TaskrewardTaskrewardItemDesc(); }
		static ::proto_ff::E_TaskrewardTaskrewardItemDesc make_pbmsg(){ return ::proto_ff::E_TaskrewardTaskrewardItemDesc(); }
	};
	typedef struct E_TaskrewardTaskrewardItemDesc_s E_TaskrewardTaskrewardItemDesc_t;

	struct E_TaskrewardTaskreward_s : public NFDescStoreSeqOP {
		E_TaskrewardTaskreward_s();
		virtual ~E_TaskrewardTaskreward_s(){}
		int CreateInit();
		int ResumeInit();
		int64_t m_id;//奖励id
		int32_t m_tasktype;//任务类型
		int32_t m_lv;//等级
		int32_t m_guildexp;//公会经验
		int32_t m_guildpoint;//公会贡献
		int32_t m_skillid;//技能ID
		NFShmVector<struct E_TaskrewardTaskrewardAttrDesc_s, DEFINE_E_TASKREWARDTASKREWARD_M_ATTR_MAX_NUM> m_attr;//属性
		NFShmVector<struct E_TaskrewardTaskrewardItemDesc_s, DEFINE_E_TASKREWARDTASKREWARD_M_ITEM_MAX_NUM> m_item;//物品

		virtual void write_to_pbmsg(::proto_ff::E_TaskrewardTaskreward & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_TaskrewardTaskreward & msg);
		static ::proto_ff::E_TaskrewardTaskreward* new_pbmsg(){ return new ::proto_ff::E_TaskrewardTaskreward(); }
		static ::proto_ff::E_TaskrewardTaskreward make_pbmsg(){ return ::proto_ff::E_TaskrewardTaskreward(); }
	};
	typedef struct E_TaskrewardTaskreward_s E_TaskrewardTaskreward_t;

	struct Sheet_TaskrewardTaskreward_s : public NFDescStoreSeqOP {
		Sheet_TaskrewardTaskreward_s();
		virtual ~Sheet_TaskrewardTaskreward_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_TaskrewardTaskreward_s, DEFINE_SHEET_TASKREWARDTASKREWARD_E_TASKREWARDTASKREWARD_LIST_MAX_NUM> E_TaskrewardTaskreward_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_TaskrewardTaskreward & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_TaskrewardTaskreward & msg);
		static ::proto_ff::Sheet_TaskrewardTaskreward* new_pbmsg(){ return new ::proto_ff::Sheet_TaskrewardTaskreward(); }
		static ::proto_ff::Sheet_TaskrewardTaskreward make_pbmsg(){ return ::proto_ff::Sheet_TaskrewardTaskreward(); }
	};
	typedef struct Sheet_TaskrewardTaskreward_s Sheet_TaskrewardTaskreward_t;

	struct E_TaskrewardTasktype_s : public NFDescStoreSeqOP {
		E_TaskrewardTasktype_s();
		virtual ~E_TaskrewardTasktype_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_tasktype;//任务类型

		virtual void write_to_pbmsg(::proto_ff::E_TaskrewardTasktype & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_TaskrewardTasktype & msg);
		static ::proto_ff::E_TaskrewardTasktype* new_pbmsg(){ return new ::proto_ff::E_TaskrewardTasktype(); }
		static ::proto_ff::E_TaskrewardTasktype make_pbmsg(){ return ::proto_ff::E_TaskrewardTasktype(); }
	};
	typedef struct E_TaskrewardTasktype_s E_TaskrewardTasktype_t;

	struct Sheet_TaskrewardTasktype_s : public NFDescStoreSeqOP {
		Sheet_TaskrewardTasktype_s();
		virtual ~Sheet_TaskrewardTasktype_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_TaskrewardTasktype_s, DEFINE_SHEET_TASKREWARDTASKTYPE_E_TASKREWARDTASKTYPE_LIST_MAX_NUM> E_TaskrewardTasktype_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_TaskrewardTasktype & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_TaskrewardTasktype & msg);
		static ::proto_ff::Sheet_TaskrewardTasktype* new_pbmsg(){ return new ::proto_ff::Sheet_TaskrewardTasktype(); }
		static ::proto_ff::Sheet_TaskrewardTasktype make_pbmsg(){ return ::proto_ff::Sheet_TaskrewardTasktype(); }
	};
	typedef struct Sheet_TaskrewardTasktype_s Sheet_TaskrewardTasktype_t;

}

