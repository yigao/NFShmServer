#pragma once

#include <stdint.h>
#include <NFComm/NFShmCore/NFShmString.h>
#include <NFComm/NFShmStl/NFShmVector.h>
#include <NFComm/NFShmCore/NFSeqOP.h>
#include <NFComm/NFShmCore/NFShmMgr.h>
#include "halo.pb.h"
#include "halo_s.h"

namespace proto_ff_s {

	struct E_HaloHaloAttributeDesc_s : public NFDescStoreSeqOP {
		E_HaloHaloAttributeDesc_s();
		virtual ~E_HaloHaloAttributeDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_type;
		int32_t m_value;

		virtual void write_to_pbmsg(::proto_ff::E_HaloHaloAttributeDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_HaloHaloAttributeDesc & msg);
		static ::proto_ff::E_HaloHaloAttributeDesc* new_pbmsg(){ return new ::proto_ff::E_HaloHaloAttributeDesc(); }
		static ::proto_ff::E_HaloHaloAttributeDesc make_pbmsg(){ return ::proto_ff::E_HaloHaloAttributeDesc(); }
	};
	typedef struct E_HaloHaloAttributeDesc_s E_HaloHaloAttributeDesc_t;

	struct E_HaloHaloActiveattributeDesc_s : public NFDescStoreSeqOP {
		E_HaloHaloActiveattributeDesc_s();
		virtual ~E_HaloHaloActiveattributeDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_type;
		int32_t m_value;

		virtual void write_to_pbmsg(::proto_ff::E_HaloHaloActiveattributeDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_HaloHaloActiveattributeDesc & msg);
		static ::proto_ff::E_HaloHaloActiveattributeDesc* new_pbmsg(){ return new ::proto_ff::E_HaloHaloActiveattributeDesc(); }
		static ::proto_ff::E_HaloHaloActiveattributeDesc make_pbmsg(){ return ::proto_ff::E_HaloHaloActiveattributeDesc(); }
	};
	typedef struct E_HaloHaloActiveattributeDesc_s E_HaloHaloActiveattributeDesc_t;

	struct E_HaloHalo_s : public NFDescStoreSeqOP {
		E_HaloHalo_s();
		virtual ~E_HaloHalo_s(){}
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
		NFShmVector<struct E_HaloHaloAttributeDesc_s, 6> m_attribute;
		NFShmVector<struct E_HaloHaloActiveattributeDesc_s, 6> m_activeattribute;

		virtual void write_to_pbmsg(::proto_ff::E_HaloHalo & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_HaloHalo & msg);
		static ::proto_ff::E_HaloHalo* new_pbmsg(){ return new ::proto_ff::E_HaloHalo(); }
		static ::proto_ff::E_HaloHalo make_pbmsg(){ return ::proto_ff::E_HaloHalo(); }
	};
	typedef struct E_HaloHalo_s E_HaloHalo_t;

	struct Sheet_HaloHalo_s : public NFDescStoreSeqOP {
		Sheet_HaloHalo_s();
		virtual ~Sheet_HaloHalo_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_HaloHalo_s, 20> E_HaloHalo_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_HaloHalo & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_HaloHalo & msg);
		static ::proto_ff::Sheet_HaloHalo* new_pbmsg(){ return new ::proto_ff::Sheet_HaloHalo(); }
		static ::proto_ff::Sheet_HaloHalo make_pbmsg(){ return ::proto_ff::Sheet_HaloHalo(); }
	};
	typedef struct Sheet_HaloHalo_s Sheet_HaloHalo_t;

}

