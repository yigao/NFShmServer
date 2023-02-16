#pragma once

#include <stdint.h>
#include <NFComm/NFShmCore/NFShmString.h>
#include <NFComm/NFShmStl/NFShmVector.h>
#include <NFComm/NFShmCore/NFSeqOP.h>
#include <NFComm/NFShmCore/NFShmMgr.h>
#include "constant.pb.h"
#include "constant_s.h"

namespace proto_ff_s {

	struct E_ConstantConstant_s : public NFDescStoreSeqOP {
		E_ConstantConstant_s();
		virtual ~E_ConstantConstant_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_constantid;
		int64_t m_constantdata;
		NFShmString<200> m_stringdata;

		virtual void write_to_pbmsg(::proto_ff::E_ConstantConstant & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_ConstantConstant & msg);
		static ::proto_ff::E_ConstantConstant* new_pbmsg(){ return new ::proto_ff::E_ConstantConstant(); }
		static ::proto_ff::E_ConstantConstant make_pbmsg(){ return ::proto_ff::E_ConstantConstant(); }
	};
	typedef struct E_ConstantConstant_s E_ConstantConstant_t;

	struct Sheet_ConstantConstant_s : public NFDescStoreSeqOP {
		Sheet_ConstantConstant_s();
		virtual ~Sheet_ConstantConstant_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_ConstantConstant_s, 300> E_ConstantConstant_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_ConstantConstant & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_ConstantConstant & msg);
		static ::proto_ff::Sheet_ConstantConstant* new_pbmsg(){ return new ::proto_ff::Sheet_ConstantConstant(); }
		static ::proto_ff::Sheet_ConstantConstant make_pbmsg(){ return ::proto_ff::Sheet_ConstantConstant(); }
	};
	typedef struct Sheet_ConstantConstant_s Sheet_ConstantConstant_t;

}

