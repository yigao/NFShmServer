#pragma once

#include <stdint.h>
#include <NFComm/NFShmStl/NFShmString.h>
#include <NFComm/NFShmStl/NFShmVector.h>
#include <NFComm/NFShmCore/NFSeqOP.h>
#include <NFComm/NFShmCore/NFShmMgr.h>
#include "E_Waremblem.pb.h"
#include "E_Waremblem_s.h"

#define DEFINE_E_WAREMBLEMWAREMBLEM_M_SKILL_MAX_NUM 5
#define DEFINE_SHEET_WAREMBLEMWAREMBLEM_E_WAREMBLEMWAREMBLEM_LIST_MAX_NUM 64
#define DEFINE_E_WAREMBLEMLV_M_ATTRIBUTE_MAX_NUM 4
#define DEFINE_SHEET_WAREMBLEMLV_E_WAREMBLEMLV_LIST_MAX_NUM 512
#define DEFINE_E_WAREMBLEMSTAR_M_ATTRIBUTE_MAX_NUM 5
#define DEFINE_SHEET_WAREMBLEMSTAR_E_WAREMBLEMSTAR_LIST_MAX_NUM 256


namespace proto_ff_s {

	struct E_WaremblemWaremblemSkillDesc_s : public NFDescStoreSeqOP {
		E_WaremblemWaremblemSkillDesc_s();
		virtual ~E_WaremblemWaremblemSkillDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_star;//解锁星级
		int32_t m_id;//id

		virtual void write_to_pbmsg(::proto_ff::E_WaremblemWaremblemSkillDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_WaremblemWaremblemSkillDesc & msg);
		static ::proto_ff::E_WaremblemWaremblemSkillDesc* new_pbmsg(){ return new ::proto_ff::E_WaremblemWaremblemSkillDesc(); }
		static ::proto_ff::E_WaremblemWaremblemSkillDesc make_pbmsg(){ return ::proto_ff::E_WaremblemWaremblemSkillDesc(); }
	};
	typedef struct E_WaremblemWaremblemSkillDesc_s E_WaremblemWaremblemSkillDesc_t;

	struct E_WaremblemWaremblem_s : public NFDescStoreSeqOP {
		E_WaremblemWaremblem_s();
		virtual ~E_WaremblemWaremblem_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//id
		int32_t m_type;//类型
		int32_t m_order;//解锁顺序
		int32_t m_lvIndex;//lv索引
		int32_t m_starIndex;//星级索引
		NFShmVector<struct E_WaremblemWaremblemSkillDesc_s, DEFINE_E_WAREMBLEMWAREMBLEM_M_SKILL_MAX_NUM> m_skill;//技能

		virtual void write_to_pbmsg(::proto_ff::E_WaremblemWaremblem & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_WaremblemWaremblem & msg);
		static ::proto_ff::E_WaremblemWaremblem* new_pbmsg(){ return new ::proto_ff::E_WaremblemWaremblem(); }
		static ::proto_ff::E_WaremblemWaremblem make_pbmsg(){ return ::proto_ff::E_WaremblemWaremblem(); }
	};
	typedef struct E_WaremblemWaremblem_s E_WaremblemWaremblem_t;

	struct Sheet_WaremblemWaremblem_s : public NFDescStoreSeqOP {
		Sheet_WaremblemWaremblem_s();
		virtual ~Sheet_WaremblemWaremblem_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_WaremblemWaremblem_s, DEFINE_SHEET_WAREMBLEMWAREMBLEM_E_WAREMBLEMWAREMBLEM_LIST_MAX_NUM> E_WaremblemWaremblem_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_WaremblemWaremblem & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_WaremblemWaremblem & msg);
		static ::proto_ff::Sheet_WaremblemWaremblem* new_pbmsg(){ return new ::proto_ff::Sheet_WaremblemWaremblem(); }
		static ::proto_ff::Sheet_WaremblemWaremblem make_pbmsg(){ return ::proto_ff::Sheet_WaremblemWaremblem(); }
	};
	typedef struct Sheet_WaremblemWaremblem_s Sheet_WaremblemWaremblem_t;

	struct E_WaremblemLvAttributeDesc_s : public NFDescStoreSeqOP {
		E_WaremblemLvAttributeDesc_s();
		virtual ~E_WaremblemLvAttributeDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_value;//值
		int32_t m_type;//ID

		virtual void write_to_pbmsg(::proto_ff::E_WaremblemLvAttributeDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_WaremblemLvAttributeDesc & msg);
		static ::proto_ff::E_WaremblemLvAttributeDesc* new_pbmsg(){ return new ::proto_ff::E_WaremblemLvAttributeDesc(); }
		static ::proto_ff::E_WaremblemLvAttributeDesc make_pbmsg(){ return ::proto_ff::E_WaremblemLvAttributeDesc(); }
	};
	typedef struct E_WaremblemLvAttributeDesc_s E_WaremblemLvAttributeDesc_t;

	struct E_WaremblemLv_s : public NFDescStoreSeqOP {
		E_WaremblemLv_s();
		virtual ~E_WaremblemLv_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//id
		int32_t m_index;//索引
		int32_t m_lv;//lv
		int32_t m_classBonus;//阶级加成
		int32_t m_costId;//消耗道具ID
		int32_t m_costNum;//消耗数量
		NFShmVector<struct E_WaremblemLvAttributeDesc_s, DEFINE_E_WAREMBLEMLV_M_ATTRIBUTE_MAX_NUM> m_attribute;//基础属性

		virtual void write_to_pbmsg(::proto_ff::E_WaremblemLv & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_WaremblemLv & msg);
		static ::proto_ff::E_WaremblemLv* new_pbmsg(){ return new ::proto_ff::E_WaremblemLv(); }
		static ::proto_ff::E_WaremblemLv make_pbmsg(){ return ::proto_ff::E_WaremblemLv(); }
	};
	typedef struct E_WaremblemLv_s E_WaremblemLv_t;

	struct Sheet_WaremblemLv_s : public NFDescStoreSeqOP {
		Sheet_WaremblemLv_s();
		virtual ~Sheet_WaremblemLv_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_WaremblemLv_s, DEFINE_SHEET_WAREMBLEMLV_E_WAREMBLEMLV_LIST_MAX_NUM> E_WaremblemLv_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_WaremblemLv & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_WaremblemLv & msg);
		static ::proto_ff::Sheet_WaremblemLv* new_pbmsg(){ return new ::proto_ff::Sheet_WaremblemLv(); }
		static ::proto_ff::Sheet_WaremblemLv make_pbmsg(){ return ::proto_ff::Sheet_WaremblemLv(); }
	};
	typedef struct Sheet_WaremblemLv_s Sheet_WaremblemLv_t;

	struct E_WaremblemStarAttributeDesc_s : public NFDescStoreSeqOP {
		E_WaremblemStarAttributeDesc_s();
		virtual ~E_WaremblemStarAttributeDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_value;//值
		int32_t m_type;//ID

		virtual void write_to_pbmsg(::proto_ff::E_WaremblemStarAttributeDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_WaremblemStarAttributeDesc & msg);
		static ::proto_ff::E_WaremblemStarAttributeDesc* new_pbmsg(){ return new ::proto_ff::E_WaremblemStarAttributeDesc(); }
		static ::proto_ff::E_WaremblemStarAttributeDesc make_pbmsg(){ return ::proto_ff::E_WaremblemStarAttributeDesc(); }
	};
	typedef struct E_WaremblemStarAttributeDesc_s E_WaremblemStarAttributeDesc_t;

	struct E_WaremblemStar_s : public NFDescStoreSeqOP {
		E_WaremblemStar_s();
		virtual ~E_WaremblemStar_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//id
		int32_t m_index;//索引
		int32_t m_star;//星级
		int32_t m_costId;//消耗道具
		int32_t m_costNum;//消耗数量
		int32_t m_succes;//成功率
		NFShmVector<struct E_WaremblemStarAttributeDesc_s, DEFINE_E_WAREMBLEMSTAR_M_ATTRIBUTE_MAX_NUM> m_attribute;//基础属性

		virtual void write_to_pbmsg(::proto_ff::E_WaremblemStar & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_WaremblemStar & msg);
		static ::proto_ff::E_WaremblemStar* new_pbmsg(){ return new ::proto_ff::E_WaremblemStar(); }
		static ::proto_ff::E_WaremblemStar make_pbmsg(){ return ::proto_ff::E_WaremblemStar(); }
	};
	typedef struct E_WaremblemStar_s E_WaremblemStar_t;

	struct Sheet_WaremblemStar_s : public NFDescStoreSeqOP {
		Sheet_WaremblemStar_s();
		virtual ~Sheet_WaremblemStar_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_WaremblemStar_s, DEFINE_SHEET_WAREMBLEMSTAR_E_WAREMBLEMSTAR_LIST_MAX_NUM> E_WaremblemStar_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_WaremblemStar & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_WaremblemStar & msg);
		static ::proto_ff::Sheet_WaremblemStar* new_pbmsg(){ return new ::proto_ff::Sheet_WaremblemStar(); }
		static ::proto_ff::Sheet_WaremblemStar make_pbmsg(){ return ::proto_ff::Sheet_WaremblemStar(); }
	};
	typedef struct Sheet_WaremblemStar_s Sheet_WaremblemStar_t;

}

