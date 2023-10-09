#pragma once

#include <stdint.h>
#include <NFComm/NFShmStl/NFShmString.h>
#include <NFComm/NFShmStl/NFShmVector.h>
#include <NFComm/NFShmCore/NFSeqOP.h>
#include <NFComm/NFShmCore/NFShmMgr.h>
#include "occupation.pb.h"
#include "occupation_s.h"

#define DEFINE_SHEET_OCCUPATIONOCCUPATION_E_OCCUPATIONOCCUPATION_LIST_MAX_NUM 20
#define DEFINE_SHEET_OCCUPATIONSTAGE_E_OCCUPATIONSTAGE_LIST_MAX_NUM 40
#define DEFINE_E_OCCUPATIONATTRIBUTE_M_ATTRIBUTE_MAX_NUM 6
#define DEFINE_SHEET_OCCUPATIONATTRIBUTE_E_OCCUPATIONATTRIBUTE_LIST_MAX_NUM 20
#define DEFINE_E_OCCUPATIONSOUL_M_ATTRIBUTE_MAX_NUM 6
#define DEFINE_SHEET_OCCUPATIONSOUL_E_OCCUPATIONSOUL_LIST_MAX_NUM 60
namespace proto_ff_s {

	struct E_OccupationOccupation_s : public NFDescStoreSeqOP {
		E_OccupationOccupation_s();
		virtual ~E_OccupationOccupation_s(){}
		int CreateInit();
		int ResumeInit();
		int64_t m_id;
		int32_t m_professionid;
		int32_t m_grade;
		NFShmString<60> m_equip;
		NFShmString<60> m_modelid;
		NFShmString<120> m_activedesc;
		int32_t m_level;
		int64_t m_skill_id;
		NFShmString<60> m_itemids;

		virtual void write_to_pbmsg(::proto_ff::E_OccupationOccupation & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_OccupationOccupation & msg);
		static ::proto_ff::E_OccupationOccupation* new_pbmsg(){ return new ::proto_ff::E_OccupationOccupation(); }
		static ::proto_ff::E_OccupationOccupation make_pbmsg(){ return ::proto_ff::E_OccupationOccupation(); }
	};
	typedef struct E_OccupationOccupation_s E_OccupationOccupation_t;

	struct Sheet_OccupationOccupation_s : public NFDescStoreSeqOP {
		Sheet_OccupationOccupation_s();
		virtual ~Sheet_OccupationOccupation_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_OccupationOccupation_s, DEFINE_SHEET_OCCUPATIONOCCUPATION_E_OCCUPATIONOCCUPATION_LIST_MAX_NUM> E_OccupationOccupation_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_OccupationOccupation & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_OccupationOccupation & msg);
		static ::proto_ff::Sheet_OccupationOccupation* new_pbmsg(){ return new ::proto_ff::Sheet_OccupationOccupation(); }
		static ::proto_ff::Sheet_OccupationOccupation make_pbmsg(){ return ::proto_ff::Sheet_OccupationOccupation(); }
	};
	typedef struct Sheet_OccupationOccupation_s Sheet_OccupationOccupation_t;

	struct E_OccupationStage_s : public NFDescStoreSeqOP {
		E_OccupationStage_s();
		virtual ~E_OccupationStage_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;
		int32_t m_grade;
		NFShmString<60> m_stgae;
		int32_t m_lv;
		int32_t m_stgaeattshow;
		int32_t m_stgaeatt;
		int32_t m_taskid;
		int32_t m_battle;
		int32_t m_skillid;
		NFShmString<60> m_lightsoul;
		int32_t m_soultpye;
		int32_t m_itemid;

		virtual void write_to_pbmsg(::proto_ff::E_OccupationStage & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_OccupationStage & msg);
		static ::proto_ff::E_OccupationStage* new_pbmsg(){ return new ::proto_ff::E_OccupationStage(); }
		static ::proto_ff::E_OccupationStage make_pbmsg(){ return ::proto_ff::E_OccupationStage(); }
	};
	typedef struct E_OccupationStage_s E_OccupationStage_t;

	struct Sheet_OccupationStage_s : public NFDescStoreSeqOP {
		Sheet_OccupationStage_s();
		virtual ~Sheet_OccupationStage_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_OccupationStage_s, DEFINE_SHEET_OCCUPATIONSTAGE_E_OCCUPATIONSTAGE_LIST_MAX_NUM> E_OccupationStage_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_OccupationStage & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_OccupationStage & msg);
		static ::proto_ff::Sheet_OccupationStage* new_pbmsg(){ return new ::proto_ff::Sheet_OccupationStage(); }
		static ::proto_ff::Sheet_OccupationStage make_pbmsg(){ return ::proto_ff::Sheet_OccupationStage(); }
	};
	typedef struct Sheet_OccupationStage_s Sheet_OccupationStage_t;

	struct E_OccupationAttributeAttributeDesc_s : public NFDescStoreSeqOP {
		E_OccupationAttributeAttributeDesc_s();
		virtual ~E_OccupationAttributeAttributeDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_item;
		int32_t m_value;

		virtual void write_to_pbmsg(::proto_ff::E_OccupationAttributeAttributeDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_OccupationAttributeAttributeDesc & msg);
		static ::proto_ff::E_OccupationAttributeAttributeDesc* new_pbmsg(){ return new ::proto_ff::E_OccupationAttributeAttributeDesc(); }
		static ::proto_ff::E_OccupationAttributeAttributeDesc make_pbmsg(){ return ::proto_ff::E_OccupationAttributeAttributeDesc(); }
	};
	typedef struct E_OccupationAttributeAttributeDesc_s E_OccupationAttributeAttributeDesc_t;

	struct E_OccupationAttribute_s : public NFDescStoreSeqOP {
		E_OccupationAttribute_s();
		virtual ~E_OccupationAttribute_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;
		NFShmVector<struct E_OccupationAttributeAttributeDesc_s, DEFINE_E_OCCUPATIONATTRIBUTE_M_ATTRIBUTE_MAX_NUM> m_attribute;

		virtual void write_to_pbmsg(::proto_ff::E_OccupationAttribute & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_OccupationAttribute & msg);
		static ::proto_ff::E_OccupationAttribute* new_pbmsg(){ return new ::proto_ff::E_OccupationAttribute(); }
		static ::proto_ff::E_OccupationAttribute make_pbmsg(){ return ::proto_ff::E_OccupationAttribute(); }
	};
	typedef struct E_OccupationAttribute_s E_OccupationAttribute_t;

	struct Sheet_OccupationAttribute_s : public NFDescStoreSeqOP {
		Sheet_OccupationAttribute_s();
		virtual ~Sheet_OccupationAttribute_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_OccupationAttribute_s, DEFINE_SHEET_OCCUPATIONATTRIBUTE_E_OCCUPATIONATTRIBUTE_LIST_MAX_NUM> E_OccupationAttribute_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_OccupationAttribute & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_OccupationAttribute & msg);
		static ::proto_ff::Sheet_OccupationAttribute* new_pbmsg(){ return new ::proto_ff::Sheet_OccupationAttribute(); }
		static ::proto_ff::Sheet_OccupationAttribute make_pbmsg(){ return ::proto_ff::Sheet_OccupationAttribute(); }
	};
	typedef struct Sheet_OccupationAttribute_s Sheet_OccupationAttribute_t;

	struct E_OccupationSoulAttributeDesc_s : public NFDescStoreSeqOP {
		E_OccupationSoulAttributeDesc_s();
		virtual ~E_OccupationSoulAttributeDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_type;
		int32_t m_value;

		virtual void write_to_pbmsg(::proto_ff::E_OccupationSoulAttributeDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_OccupationSoulAttributeDesc & msg);
		static ::proto_ff::E_OccupationSoulAttributeDesc* new_pbmsg(){ return new ::proto_ff::E_OccupationSoulAttributeDesc(); }
		static ::proto_ff::E_OccupationSoulAttributeDesc make_pbmsg(){ return ::proto_ff::E_OccupationSoulAttributeDesc(); }
	};
	typedef struct E_OccupationSoulAttributeDesc_s E_OccupationSoulAttributeDesc_t;

	struct E_OccupationSoul_s : public NFDescStoreSeqOP {
		E_OccupationSoul_s();
		virtual ~E_OccupationSoul_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;
		int32_t m_soultpye;
		int32_t m_position;
		NFShmVector<struct E_OccupationSoulAttributeDesc_s, DEFINE_E_OCCUPATIONSOUL_M_ATTRIBUTE_MAX_NUM> m_attribute;

		virtual void write_to_pbmsg(::proto_ff::E_OccupationSoul & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_OccupationSoul & msg);
		static ::proto_ff::E_OccupationSoul* new_pbmsg(){ return new ::proto_ff::E_OccupationSoul(); }
		static ::proto_ff::E_OccupationSoul make_pbmsg(){ return ::proto_ff::E_OccupationSoul(); }
	};
	typedef struct E_OccupationSoul_s E_OccupationSoul_t;

	struct Sheet_OccupationSoul_s : public NFDescStoreSeqOP {
		Sheet_OccupationSoul_s();
		virtual ~Sheet_OccupationSoul_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_OccupationSoul_s, DEFINE_SHEET_OCCUPATIONSOUL_E_OCCUPATIONSOUL_LIST_MAX_NUM> E_OccupationSoul_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_OccupationSoul & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_OccupationSoul & msg);
		static ::proto_ff::Sheet_OccupationSoul* new_pbmsg(){ return new ::proto_ff::Sheet_OccupationSoul(); }
		static ::proto_ff::Sheet_OccupationSoul make_pbmsg(){ return ::proto_ff::Sheet_OccupationSoul(); }
	};
	typedef struct Sheet_OccupationSoul_s Sheet_OccupationSoul_t;

}

