#pragma once

#include <stdint.h>
#include <NFComm/NFShmCore/NFShmString.h>
#include <NFComm/NFShmStl/NFShmVector.h>
#include <NFComm/NFShmCore/NFSeqOP.h>
#include <NFComm/NFShmCore/NFShmMgr.h>
#include "ui.pb.h"
#include "ui_s.h"

namespace proto_ff_s {

	struct E_UiEffect_s : public NFDescStoreSeqOP {
		E_UiEffect_s();
		virtual ~E_UiEffect_s(){}
		int CreateInit();
		int ResumeInit();
		int64_t m_id;
		int32_t m_time;

		virtual void write_to_pbmsg(::proto_ff::E_UiEffect & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_UiEffect & msg);
		static ::proto_ff::E_UiEffect* new_pbmsg(){ return new ::proto_ff::E_UiEffect(); }
		static ::proto_ff::E_UiEffect make_pbmsg(){ return ::proto_ff::E_UiEffect(); }
	};
	typedef struct E_UiEffect_s E_UiEffect_t;

	struct Sheet_UiEffect_s : public NFDescStoreSeqOP {
		Sheet_UiEffect_s();
		virtual ~Sheet_UiEffect_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_UiEffect_s, 20> E_UiEffect_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_UiEffect & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_UiEffect & msg);
		static ::proto_ff::Sheet_UiEffect* new_pbmsg(){ return new ::proto_ff::Sheet_UiEffect(); }
		static ::proto_ff::Sheet_UiEffect make_pbmsg(){ return ::proto_ff::Sheet_UiEffect(); }
	};
	typedef struct Sheet_UiEffect_s Sheet_UiEffect_t;

}

