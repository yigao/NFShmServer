#pragma once

#include <stdint.h>
#include <NFComm/NFShmStl/NFShmString.h>
#include <NFComm/NFShmStl/NFShmVector.h>
#include <NFComm/NFShmCore/NFSeqOP.h>
#include <NFComm/NFShmCore/NFShmMgr.h>
#include "meditation.pb.h"
#include "meditation_s.h"

#define DEFINE_E_MEDITATIONMEDITATION_M_ATTRIBUTE_MAX_NUM 6
#define DEFINE_E_MEDITATIONMEDITATION_M_ACTIVEATTRIBUTE_MAX_NUM 6
#define DEFINE_SHEET_MEDITATIONMEDITATION_E_MEDITATIONMEDITATION_LIST_MAX_NUM 20
namespace proto_ff_s {

	struct E_MeditationMeditationAttributeDesc_s : public NFDescStoreSeqOP {
		E_MeditationMeditationAttributeDesc_s();
		virtual ~E_MeditationMeditationAttributeDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_type;
		int32_t m_value;

		virtual void write_to_pbmsg(::proto_ff::E_MeditationMeditationAttributeDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_MeditationMeditationAttributeDesc & msg);
		static ::proto_ff::E_MeditationMeditationAttributeDesc* new_pbmsg(){ return new ::proto_ff::E_MeditationMeditationAttributeDesc(); }
		static ::proto_ff::E_MeditationMeditationAttributeDesc make_pbmsg(){ return ::proto_ff::E_MeditationMeditationAttributeDesc(); }
	};
	typedef struct E_MeditationMeditationAttributeDesc_s E_MeditationMeditationAttributeDesc_t;

	struct E_MeditationMeditationActiveattributeDesc_s : public NFDescStoreSeqOP {
		E_MeditationMeditationActiveattributeDesc_s();
		virtual ~E_MeditationMeditationActiveattributeDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_type;
		int32_t m_value;

		virtual void write_to_pbmsg(::proto_ff::E_MeditationMeditationActiveattributeDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_MeditationMeditationActiveattributeDesc & msg);
		static ::proto_ff::E_MeditationMeditationActiveattributeDesc* new_pbmsg(){ return new ::proto_ff::E_MeditationMeditationActiveattributeDesc(); }
		static ::proto_ff::E_MeditationMeditationActiveattributeDesc make_pbmsg(){ return ::proto_ff::E_MeditationMeditationActiveattributeDesc(); }
	};
	typedef struct E_MeditationMeditationActiveattributeDesc_s E_MeditationMeditationActiveattributeDesc_t;

	struct E_MeditationMeditation_s : public NFDescStoreSeqOP {
		E_MeditationMeditation_s();
		virtual ~E_MeditationMeditation_s(){}
		int CreateInit();
		int ResumeInit();
		int64_t m_id;
		NFShmString<60> m_name;
		int32_t m_type;
		int32_t m_quality;
		NFShmString<60> m_professionlimit;
		int64_t m_activationitem;
		int32_t m_activationnum;
		int64_t m_starid;
		NFShmString<300> m_starnum;
		int32_t m_starup;
		int32_t m_starber;
		NFShmVector<struct E_MeditationMeditationAttributeDesc_s, DEFINE_E_MEDITATIONMEDITATION_M_ATTRIBUTE_MAX_NUM> m_attribute;
		NFShmVector<struct E_MeditationMeditationActiveattributeDesc_s, DEFINE_E_MEDITATIONMEDITATION_M_ACTIVEATTRIBUTE_MAX_NUM> m_activeattribute;

		virtual void write_to_pbmsg(::proto_ff::E_MeditationMeditation & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_MeditationMeditation & msg);
		static ::proto_ff::E_MeditationMeditation* new_pbmsg(){ return new ::proto_ff::E_MeditationMeditation(); }
		static ::proto_ff::E_MeditationMeditation make_pbmsg(){ return ::proto_ff::E_MeditationMeditation(); }
	};
	typedef struct E_MeditationMeditation_s E_MeditationMeditation_t;

	struct Sheet_MeditationMeditation_s : public NFDescStoreSeqOP {
		Sheet_MeditationMeditation_s();
		virtual ~Sheet_MeditationMeditation_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_MeditationMeditation_s, DEFINE_SHEET_MEDITATIONMEDITATION_E_MEDITATIONMEDITATION_LIST_MAX_NUM> E_MeditationMeditation_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_MeditationMeditation & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_MeditationMeditation & msg);
		static ::proto_ff::Sheet_MeditationMeditation* new_pbmsg(){ return new ::proto_ff::Sheet_MeditationMeditation(); }
		static ::proto_ff::Sheet_MeditationMeditation make_pbmsg(){ return ::proto_ff::Sheet_MeditationMeditation(); }
	};
	typedef struct Sheet_MeditationMeditation_s Sheet_MeditationMeditation_t;

}

