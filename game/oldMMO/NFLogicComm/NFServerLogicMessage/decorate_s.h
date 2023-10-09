#pragma once

#include <stdint.h>
#include <NFComm/NFShmStl/NFShmString.h>
#include <NFComm/NFShmStl/NFShmVector.h>
#include <NFComm/NFShmCore/NFSeqOP.h>
#include <NFComm/NFShmCore/NFShmMgr.h>
#include "decorate.pb.h"
#include "decorate_s.h"

#define DEFINE_E_DECORATEDECORATE_M_ATTRIBUTE_MAX_NUM 6
#define DEFINE_E_DECORATEDECORATE_M_ACTIVEATTRIBUTE_MAX_NUM 6
#define DEFINE_SHEET_DECORATEDECORATE_E_DECORATEDECORATE_LIST_MAX_NUM 40
namespace proto_ff_s {

	struct E_DecorateDecorateAttributeDesc_s : public NFDescStoreSeqOP {
		E_DecorateDecorateAttributeDesc_s();
		virtual ~E_DecorateDecorateAttributeDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_type;
		int32_t m_value;

		virtual void write_to_pbmsg(::proto_ff::E_DecorateDecorateAttributeDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_DecorateDecorateAttributeDesc & msg);
		static ::proto_ff::E_DecorateDecorateAttributeDesc* new_pbmsg(){ return new ::proto_ff::E_DecorateDecorateAttributeDesc(); }
		static ::proto_ff::E_DecorateDecorateAttributeDesc make_pbmsg(){ return ::proto_ff::E_DecorateDecorateAttributeDesc(); }
	};
	typedef struct E_DecorateDecorateAttributeDesc_s E_DecorateDecorateAttributeDesc_t;

	struct E_DecorateDecorateActiveattributeDesc_s : public NFDescStoreSeqOP {
		E_DecorateDecorateActiveattributeDesc_s();
		virtual ~E_DecorateDecorateActiveattributeDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_type;
		int32_t m_value;

		virtual void write_to_pbmsg(::proto_ff::E_DecorateDecorateActiveattributeDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_DecorateDecorateActiveattributeDesc & msg);
		static ::proto_ff::E_DecorateDecorateActiveattributeDesc* new_pbmsg(){ return new ::proto_ff::E_DecorateDecorateActiveattributeDesc(); }
		static ::proto_ff::E_DecorateDecorateActiveattributeDesc make_pbmsg(){ return ::proto_ff::E_DecorateDecorateActiveattributeDesc(); }
	};
	typedef struct E_DecorateDecorateActiveattributeDesc_s E_DecorateDecorateActiveattributeDesc_t;

	struct E_DecorateDecorate_s : public NFDescStoreSeqOP {
		E_DecorateDecorate_s();
		virtual ~E_DecorateDecorate_s(){}
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
		NFShmString<200> m_starnum;
		int32_t m_starup;
		int32_t m_starber;
		NFShmVector<struct E_DecorateDecorateAttributeDesc_s, DEFINE_E_DECORATEDECORATE_M_ATTRIBUTE_MAX_NUM> m_attribute;
		NFShmVector<struct E_DecorateDecorateActiveattributeDesc_s, DEFINE_E_DECORATEDECORATE_M_ACTIVEATTRIBUTE_MAX_NUM> m_activeattribute;

		virtual void write_to_pbmsg(::proto_ff::E_DecorateDecorate & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_DecorateDecorate & msg);
		static ::proto_ff::E_DecorateDecorate* new_pbmsg(){ return new ::proto_ff::E_DecorateDecorate(); }
		static ::proto_ff::E_DecorateDecorate make_pbmsg(){ return ::proto_ff::E_DecorateDecorate(); }
	};
	typedef struct E_DecorateDecorate_s E_DecorateDecorate_t;

	struct Sheet_DecorateDecorate_s : public NFDescStoreSeqOP {
		Sheet_DecorateDecorate_s();
		virtual ~Sheet_DecorateDecorate_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_DecorateDecorate_s, DEFINE_SHEET_DECORATEDECORATE_E_DECORATEDECORATE_LIST_MAX_NUM> E_DecorateDecorate_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_DecorateDecorate & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_DecorateDecorate & msg);
		static ::proto_ff::Sheet_DecorateDecorate* new_pbmsg(){ return new ::proto_ff::Sheet_DecorateDecorate(); }
		static ::proto_ff::Sheet_DecorateDecorate make_pbmsg(){ return ::proto_ff::Sheet_DecorateDecorate(); }
	};
	typedef struct Sheet_DecorateDecorate_s Sheet_DecorateDecorate_t;

}

