#pragma once

#include <stdint.h>
#include <NFComm/NFShmStl/NFShmString.h>
#include <NFComm/NFShmStl/NFShmVector.h>
#include <NFComm/NFShmCore/NFSeqOP.h>
#include <NFComm/NFShmCore/NFShmMgr.h>
#include "E_Talent.pb.h"
#include "E_Talent_s.h"

#define DEFINE_SHEET_TALENTTALENT_E_TALENTTALENT_LIST_MAX_NUM 64
#define DEFINE_SHEET_TALENTTALENTTYPE_E_TALENTTALENTTYPE_LIST_MAX_NUM 4


namespace proto_ff_s {

	struct E_TalentTalent_s : public NFDescStoreSeqOP {
		E_TalentTalent_s();
		virtual ~E_TalentTalent_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;//天赋ID
		int32_t m_type;//天赋大类
		int32_t m_skillID;//技能ID
		int32_t m_lvLImit;//等级上限
		int32_t m_aheadSkill;//前置技能
		int32_t m_aheadLv;//前置技能等级
		int32_t m_needType;//要求天赋类型
		int32_t m_typeNum;//要求天赋点数
		int32_t m_cost;//升级消耗天赋点

		virtual void write_to_pbmsg(::proto_ff::E_TalentTalent & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_TalentTalent & msg);
		static ::proto_ff::E_TalentTalent* new_pbmsg(){ return new ::proto_ff::E_TalentTalent(); }
		static ::proto_ff::E_TalentTalent make_pbmsg(){ return ::proto_ff::E_TalentTalent(); }
	};
	typedef struct E_TalentTalent_s E_TalentTalent_t;

	struct Sheet_TalentTalent_s : public NFDescStoreSeqOP {
		Sheet_TalentTalent_s();
		virtual ~Sheet_TalentTalent_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_TalentTalent_s, DEFINE_SHEET_TALENTTALENT_E_TALENTTALENT_LIST_MAX_NUM> E_TalentTalent_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_TalentTalent & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_TalentTalent & msg);
		static ::proto_ff::Sheet_TalentTalent* new_pbmsg(){ return new ::proto_ff::Sheet_TalentTalent(); }
		static ::proto_ff::Sheet_TalentTalent make_pbmsg(){ return ::proto_ff::Sheet_TalentTalent(); }
	};
	typedef struct Sheet_TalentTalent_s Sheet_TalentTalent_t;

	struct E_TalentTalenttype_s : public NFDescStoreSeqOP {
		E_TalentTalenttype_s();
		virtual ~E_TalentTalenttype_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_type;//天赋大类

		virtual void write_to_pbmsg(::proto_ff::E_TalentTalenttype & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_TalentTalenttype & msg);
		static ::proto_ff::E_TalentTalenttype* new_pbmsg(){ return new ::proto_ff::E_TalentTalenttype(); }
		static ::proto_ff::E_TalentTalenttype make_pbmsg(){ return ::proto_ff::E_TalentTalenttype(); }
	};
	typedef struct E_TalentTalenttype_s E_TalentTalenttype_t;

	struct Sheet_TalentTalenttype_s : public NFDescStoreSeqOP {
		Sheet_TalentTalenttype_s();
		virtual ~Sheet_TalentTalenttype_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_TalentTalenttype_s, DEFINE_SHEET_TALENTTALENTTYPE_E_TALENTTALENTTYPE_LIST_MAX_NUM> E_TalentTalenttype_List;//

		virtual void write_to_pbmsg(::proto_ff::Sheet_TalentTalenttype & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_TalentTalenttype & msg);
		static ::proto_ff::Sheet_TalentTalenttype* new_pbmsg(){ return new ::proto_ff::Sheet_TalentTalenttype(); }
		static ::proto_ff::Sheet_TalentTalenttype make_pbmsg(){ return ::proto_ff::Sheet_TalentTalenttype(); }
	};
	typedef struct Sheet_TalentTalenttype_s Sheet_TalentTalenttype_t;

}

