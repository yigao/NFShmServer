#pragma once

#include <stdint.h>
#include <NFComm/NFShmStl/NFShmString.h>
#include <NFComm/NFShmStl/NFShmVector.h>
#include <NFComm/NFShmCore/NFSeqOP.h>
#include <NFComm/NFShmCore/NFShmMgr.h>
#include "footprint.pb.h"
#include "footprint_s.h"

#define DEFINE_E_FOOTPRINTFOOTPRINT_M_ATTRIBUTE_MAX_NUM 6
#define DEFINE_E_FOOTPRINTFOOTPRINT_M_ACTIVEATTRIBUTE_MAX_NUM 6
#define DEFINE_SHEET_FOOTPRINTFOOTPRINT_E_FOOTPRINTFOOTPRINT_LIST_MAX_NUM 20
namespace proto_ff_s {

	struct E_FootprintFootprintAttributeDesc_s : public NFDescStoreSeqOP {
		E_FootprintFootprintAttributeDesc_s();
		virtual ~E_FootprintFootprintAttributeDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_type;
		int32_t m_value;

		virtual void write_to_pbmsg(::proto_ff::E_FootprintFootprintAttributeDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_FootprintFootprintAttributeDesc & msg);
		static ::proto_ff::E_FootprintFootprintAttributeDesc* new_pbmsg(){ return new ::proto_ff::E_FootprintFootprintAttributeDesc(); }
		static ::proto_ff::E_FootprintFootprintAttributeDesc make_pbmsg(){ return ::proto_ff::E_FootprintFootprintAttributeDesc(); }
	};
	typedef struct E_FootprintFootprintAttributeDesc_s E_FootprintFootprintAttributeDesc_t;

	struct E_FootprintFootprintActiveattributeDesc_s : public NFDescStoreSeqOP {
		E_FootprintFootprintActiveattributeDesc_s();
		virtual ~E_FootprintFootprintActiveattributeDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_type;
		int32_t m_value;

		virtual void write_to_pbmsg(::proto_ff::E_FootprintFootprintActiveattributeDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_FootprintFootprintActiveattributeDesc & msg);
		static ::proto_ff::E_FootprintFootprintActiveattributeDesc* new_pbmsg(){ return new ::proto_ff::E_FootprintFootprintActiveattributeDesc(); }
		static ::proto_ff::E_FootprintFootprintActiveattributeDesc make_pbmsg(){ return ::proto_ff::E_FootprintFootprintActiveattributeDesc(); }
	};
	typedef struct E_FootprintFootprintActiveattributeDesc_s E_FootprintFootprintActiveattributeDesc_t;

	struct E_FootprintFootprint_s : public NFDescStoreSeqOP {
		E_FootprintFootprint_s();
		virtual ~E_FootprintFootprint_s(){}
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
		NFShmVector<struct E_FootprintFootprintAttributeDesc_s, DEFINE_E_FOOTPRINTFOOTPRINT_M_ATTRIBUTE_MAX_NUM> m_attribute;
		NFShmVector<struct E_FootprintFootprintActiveattributeDesc_s, DEFINE_E_FOOTPRINTFOOTPRINT_M_ACTIVEATTRIBUTE_MAX_NUM> m_activeattribute;

		virtual void write_to_pbmsg(::proto_ff::E_FootprintFootprint & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_FootprintFootprint & msg);
		static ::proto_ff::E_FootprintFootprint* new_pbmsg(){ return new ::proto_ff::E_FootprintFootprint(); }
		static ::proto_ff::E_FootprintFootprint make_pbmsg(){ return ::proto_ff::E_FootprintFootprint(); }
	};
	typedef struct E_FootprintFootprint_s E_FootprintFootprint_t;

	struct Sheet_FootprintFootprint_s : public NFDescStoreSeqOP {
		Sheet_FootprintFootprint_s();
		virtual ~Sheet_FootprintFootprint_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_FootprintFootprint_s, DEFINE_SHEET_FOOTPRINTFOOTPRINT_E_FOOTPRINTFOOTPRINT_LIST_MAX_NUM> E_FootprintFootprint_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_FootprintFootprint & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_FootprintFootprint & msg);
		static ::proto_ff::Sheet_FootprintFootprint* new_pbmsg(){ return new ::proto_ff::Sheet_FootprintFootprint(); }
		static ::proto_ff::Sheet_FootprintFootprint make_pbmsg(){ return ::proto_ff::Sheet_FootprintFootprint(); }
	};
	typedef struct Sheet_FootprintFootprint_s Sheet_FootprintFootprint_t;

}

