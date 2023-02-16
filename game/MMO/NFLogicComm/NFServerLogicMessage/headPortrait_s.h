#pragma once

#include <stdint.h>
#include <NFComm/NFShmCore/NFShmString.h>
#include <NFComm/NFShmStl/NFShmVector.h>
#include <NFComm/NFShmCore/NFSeqOP.h>
#include <NFComm/NFShmCore/NFShmMgr.h>
#include "headPortrait.pb.h"
#include "headPortrait_s.h"

namespace proto_ff_s {

	struct E_HeadportraitHeadAttributeDesc_s : public NFDescStoreSeqOP {
		E_HeadportraitHeadAttributeDesc_s();
		virtual ~E_HeadportraitHeadAttributeDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_type;
		int32_t m_value;

		virtual void write_to_pbmsg(::proto_ff::E_HeadportraitHeadAttributeDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_HeadportraitHeadAttributeDesc & msg);
		static ::proto_ff::E_HeadportraitHeadAttributeDesc* new_pbmsg(){ return new ::proto_ff::E_HeadportraitHeadAttributeDesc(); }
		static ::proto_ff::E_HeadportraitHeadAttributeDesc make_pbmsg(){ return ::proto_ff::E_HeadportraitHeadAttributeDesc(); }
	};
	typedef struct E_HeadportraitHeadAttributeDesc_s E_HeadportraitHeadAttributeDesc_t;

	struct E_HeadportraitHeadActiveattributeDesc_s : public NFDescStoreSeqOP {
		E_HeadportraitHeadActiveattributeDesc_s();
		virtual ~E_HeadportraitHeadActiveattributeDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_type;
		int32_t m_value;

		virtual void write_to_pbmsg(::proto_ff::E_HeadportraitHeadActiveattributeDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_HeadportraitHeadActiveattributeDesc & msg);
		static ::proto_ff::E_HeadportraitHeadActiveattributeDesc* new_pbmsg(){ return new ::proto_ff::E_HeadportraitHeadActiveattributeDesc(); }
		static ::proto_ff::E_HeadportraitHeadActiveattributeDesc make_pbmsg(){ return ::proto_ff::E_HeadportraitHeadActiveattributeDesc(); }
	};
	typedef struct E_HeadportraitHeadActiveattributeDesc_s E_HeadportraitHeadActiveattributeDesc_t;

	struct E_HeadportraitHead_s : public NFDescStoreSeqOP {
		E_HeadportraitHead_s();
		virtual ~E_HeadportraitHead_s(){}
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
		NFShmVector<struct E_HeadportraitHeadAttributeDesc_s, 6> m_attribute;
		NFShmVector<struct E_HeadportraitHeadActiveattributeDesc_s, 6> m_activeattribute;

		virtual void write_to_pbmsg(::proto_ff::E_HeadportraitHead & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_HeadportraitHead & msg);
		static ::proto_ff::E_HeadportraitHead* new_pbmsg(){ return new ::proto_ff::E_HeadportraitHead(); }
		static ::proto_ff::E_HeadportraitHead make_pbmsg(){ return ::proto_ff::E_HeadportraitHead(); }
	};
	typedef struct E_HeadportraitHead_s E_HeadportraitHead_t;

	struct Sheet_HeadportraitHead_s : public NFDescStoreSeqOP {
		Sheet_HeadportraitHead_s();
		virtual ~Sheet_HeadportraitHead_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_HeadportraitHead_s, 100> E_HeadportraitHead_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_HeadportraitHead & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_HeadportraitHead & msg);
		static ::proto_ff::Sheet_HeadportraitHead* new_pbmsg(){ return new ::proto_ff::Sheet_HeadportraitHead(); }
		static ::proto_ff::Sheet_HeadportraitHead make_pbmsg(){ return ::proto_ff::Sheet_HeadportraitHead(); }
	};
	typedef struct Sheet_HeadportraitHead_s Sheet_HeadportraitHead_t;

}

