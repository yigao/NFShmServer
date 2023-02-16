#pragma once

#include <stdint.h>
#include <NFComm/NFShmCore/NFShmString.h>
#include <NFComm/NFShmStl/NFShmVector.h>
#include <NFComm/NFShmCore/NFSeqOP.h>
#include <NFComm/NFShmCore/NFShmMgr.h>
#include "fashion.pb.h"
#include "fashion_s.h"

namespace proto_ff_s {

	struct E_FashionFashionAttributeDesc_s : public NFDescStoreSeqOP {
		E_FashionFashionAttributeDesc_s();
		virtual ~E_FashionFashionAttributeDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_type;
		int32_t m_value;

		virtual void write_to_pbmsg(::proto_ff::E_FashionFashionAttributeDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_FashionFashionAttributeDesc & msg);
		static ::proto_ff::E_FashionFashionAttributeDesc* new_pbmsg(){ return new ::proto_ff::E_FashionFashionAttributeDesc(); }
		static ::proto_ff::E_FashionFashionAttributeDesc make_pbmsg(){ return ::proto_ff::E_FashionFashionAttributeDesc(); }
	};
	typedef struct E_FashionFashionAttributeDesc_s E_FashionFashionAttributeDesc_t;

	struct E_FashionFashionActiveattributeDesc_s : public NFDescStoreSeqOP {
		E_FashionFashionActiveattributeDesc_s();
		virtual ~E_FashionFashionActiveattributeDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_type;
		int32_t m_value;

		virtual void write_to_pbmsg(::proto_ff::E_FashionFashionActiveattributeDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_FashionFashionActiveattributeDesc & msg);
		static ::proto_ff::E_FashionFashionActiveattributeDesc* new_pbmsg(){ return new ::proto_ff::E_FashionFashionActiveattributeDesc(); }
		static ::proto_ff::E_FashionFashionActiveattributeDesc make_pbmsg(){ return ::proto_ff::E_FashionFashionActiveattributeDesc(); }
	};
	typedef struct E_FashionFashionActiveattributeDesc_s E_FashionFashionActiveattributeDesc_t;

	struct E_FashionFashion_s : public NFDescStoreSeqOP {
		E_FashionFashion_s();
		virtual ~E_FashionFashion_s(){}
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
		NFShmVector<struct E_FashionFashionAttributeDesc_s, 5> m_attribute;
		NFShmVector<struct E_FashionFashionActiveattributeDesc_s, 6> m_activeattribute;

		virtual void write_to_pbmsg(::proto_ff::E_FashionFashion & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_FashionFashion & msg);
		static ::proto_ff::E_FashionFashion* new_pbmsg(){ return new ::proto_ff::E_FashionFashion(); }
		static ::proto_ff::E_FashionFashion make_pbmsg(){ return ::proto_ff::E_FashionFashion(); }
	};
	typedef struct E_FashionFashion_s E_FashionFashion_t;

	struct Sheet_FashionFashion_s : public NFDescStoreSeqOP {
		Sheet_FashionFashion_s();
		virtual ~Sheet_FashionFashion_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_FashionFashion_s, 20> E_FashionFashion_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_FashionFashion & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_FashionFashion & msg);
		static ::proto_ff::Sheet_FashionFashion* new_pbmsg(){ return new ::proto_ff::Sheet_FashionFashion(); }
		static ::proto_ff::Sheet_FashionFashion make_pbmsg(){ return ::proto_ff::Sheet_FashionFashion(); }
	};
	typedef struct Sheet_FashionFashion_s Sheet_FashionFashion_t;

}

