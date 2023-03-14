#pragma once

#include <stdint.h>
#include <NFComm/NFShmCore/NFShmString.h>
#include <NFComm/NFShmStl/NFShmVector.h>
#include <NFComm/NFShmCore/NFSeqOP.h>
#include <NFComm/NFShmCore/NFShmMgr.h>
#include "link.pb.h"
#include "link_s.h"

#define DEFINE_SHEET_LINKLINK_E_LINKLINK_LIST_MAX_NUM 160
namespace proto_ff_s {

	struct E_LinkLink_s : public NFDescStoreSeqOP {
		E_LinkLink_s();
		virtual ~E_LinkLink_s(){}
		int CreateInit();
		int ResumeInit();
		int64_t m_id;
		NFShmString<60> m_icon;
		NFShmString<60> m_dbargs;
		NFShmString<60> m_argsm;
		int32_t m_functionunlock;
		NFShmString<60> m_linknpc;

		virtual void write_to_pbmsg(::proto_ff::E_LinkLink & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_LinkLink & msg);
		static ::proto_ff::E_LinkLink* new_pbmsg(){ return new ::proto_ff::E_LinkLink(); }
		static ::proto_ff::E_LinkLink make_pbmsg(){ return ::proto_ff::E_LinkLink(); }
	};
	typedef struct E_LinkLink_s E_LinkLink_t;

	struct Sheet_LinkLink_s : public NFDescStoreSeqOP {
		Sheet_LinkLink_s();
		virtual ~Sheet_LinkLink_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_LinkLink_s, DEFINE_SHEET_LINKLINK_E_LINKLINK_LIST_MAX_NUM> E_LinkLink_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_LinkLink & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_LinkLink & msg);
		static ::proto_ff::Sheet_LinkLink* new_pbmsg(){ return new ::proto_ff::Sheet_LinkLink(); }
		static ::proto_ff::Sheet_LinkLink make_pbmsg(){ return ::proto_ff::Sheet_LinkLink(); }
	};
	typedef struct Sheet_LinkLink_s Sheet_LinkLink_t;

}

