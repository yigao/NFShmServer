#pragma once

#include <stdint.h>
#include <NFComm/NFShmCore/NFShmString.h>
#include <NFComm/NFShmStl/NFShmVector.h>
#include <NFComm/NFShmCore/NFSeqOP.h>
#include <NFComm/NFShmCore/NFShmMgr.h>
#include "functionunlock.pb.h"
#include "functionunlock_s.h"

#define DEFINE_SHEET_FUNCTIONUNLOCKFUNCTIONUNLOCK_E_FUNCTIONUNLOCKFUNCTIONUNLOCK_LIST_MAX_NUM 200
#define DEFINE_SHEET_FUNCTIONUNLOCKPREVIEW_E_FUNCTIONUNLOCKPREVIEW_LIST_MAX_NUM 20
namespace proto_ff_s {

	struct E_FunctionunlockFunctionunlock_s : public NFDescStoreSeqOP {
		E_FunctionunlockFunctionunlock_s();
		virtual ~E_FunctionunlockFunctionunlock_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_functionid;
		int32_t m_opendaily;
		int32_t m_opentype;
		int64_t m_openval;
		int32_t m_iconopenval;
		int32_t m_icondisapearid;
		int32_t m_belong;

		virtual void write_to_pbmsg(::proto_ff::E_FunctionunlockFunctionunlock & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_FunctionunlockFunctionunlock & msg);
		static ::proto_ff::E_FunctionunlockFunctionunlock* new_pbmsg(){ return new ::proto_ff::E_FunctionunlockFunctionunlock(); }
		static ::proto_ff::E_FunctionunlockFunctionunlock make_pbmsg(){ return ::proto_ff::E_FunctionunlockFunctionunlock(); }
	};
	typedef struct E_FunctionunlockFunctionunlock_s E_FunctionunlockFunctionunlock_t;

	struct Sheet_FunctionunlockFunctionunlock_s : public NFDescStoreSeqOP {
		Sheet_FunctionunlockFunctionunlock_s();
		virtual ~Sheet_FunctionunlockFunctionunlock_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_FunctionunlockFunctionunlock_s, DEFINE_SHEET_FUNCTIONUNLOCKFUNCTIONUNLOCK_E_FUNCTIONUNLOCKFUNCTIONUNLOCK_LIST_MAX_NUM> E_FunctionunlockFunctionunlock_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_FunctionunlockFunctionunlock & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_FunctionunlockFunctionunlock & msg);
		static ::proto_ff::Sheet_FunctionunlockFunctionunlock* new_pbmsg(){ return new ::proto_ff::Sheet_FunctionunlockFunctionunlock(); }
		static ::proto_ff::Sheet_FunctionunlockFunctionunlock make_pbmsg(){ return ::proto_ff::Sheet_FunctionunlockFunctionunlock(); }
	};
	typedef struct Sheet_FunctionunlockFunctionunlock_s Sheet_FunctionunlockFunctionunlock_t;

	struct E_FunctionunlockPreview_s : public NFDescStoreSeqOP {
		E_FunctionunlockPreview_s();
		virtual ~E_FunctionunlockPreview_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_functionid;
		int32_t m_rewarditem;
		int32_t m_rewardnum;

		virtual void write_to_pbmsg(::proto_ff::E_FunctionunlockPreview & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_FunctionunlockPreview & msg);
		static ::proto_ff::E_FunctionunlockPreview* new_pbmsg(){ return new ::proto_ff::E_FunctionunlockPreview(); }
		static ::proto_ff::E_FunctionunlockPreview make_pbmsg(){ return ::proto_ff::E_FunctionunlockPreview(); }
	};
	typedef struct E_FunctionunlockPreview_s E_FunctionunlockPreview_t;

	struct Sheet_FunctionunlockPreview_s : public NFDescStoreSeqOP {
		Sheet_FunctionunlockPreview_s();
		virtual ~Sheet_FunctionunlockPreview_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_FunctionunlockPreview_s, DEFINE_SHEET_FUNCTIONUNLOCKPREVIEW_E_FUNCTIONUNLOCKPREVIEW_LIST_MAX_NUM> E_FunctionunlockPreview_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_FunctionunlockPreview & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_FunctionunlockPreview & msg);
		static ::proto_ff::Sheet_FunctionunlockPreview* new_pbmsg(){ return new ::proto_ff::Sheet_FunctionunlockPreview(); }
		static ::proto_ff::Sheet_FunctionunlockPreview make_pbmsg(){ return ::proto_ff::Sheet_FunctionunlockPreview(); }
	};
	typedef struct Sheet_FunctionunlockPreview_s Sheet_FunctionunlockPreview_t;

}

