#pragma once

#include <stdint.h>
#include <NFComm/NFShmStl/NFShmString.h>
#include <NFComm/NFShmStl/NFShmVector.h>
#include <NFComm/NFShmCore/NFSeqOP.h>
#include <NFComm/NFShmCore/NFShmMgr.h>
#include "GunValue.pb.h"
#include "GunValue_s.h"

#define DEFINE_SHEET_GUNVALUECONFIG_E_GUNVALUECONFIG_LIST_MAX_NUM 100
namespace proto_ff_s {

	struct E_GunvalueConfig_s : public NFDescStoreSeqOP {
		E_GunvalueConfig_s();
		virtual ~E_GunvalueConfig_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;
		int32_t m_value;
		int32_t m_roomid;
		int32_t m_gunid;

		virtual void write_to_pbmsg(::proto_ff::E_GunvalueConfig & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_GunvalueConfig & msg);
		static ::proto_ff::E_GunvalueConfig* new_pbmsg(){ return new ::proto_ff::E_GunvalueConfig(); }
		static ::proto_ff::E_GunvalueConfig make_pbmsg(){ return ::proto_ff::E_GunvalueConfig(); }
	};
	typedef struct E_GunvalueConfig_s E_GunvalueConfig_t;

	struct Sheet_GunvalueConfig_s : public NFDescStoreSeqOP {
		Sheet_GunvalueConfig_s();
		virtual ~Sheet_GunvalueConfig_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_GunvalueConfig_s, DEFINE_SHEET_GUNVALUECONFIG_E_GUNVALUECONFIG_LIST_MAX_NUM> E_GunvalueConfig_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_GunvalueConfig & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_GunvalueConfig & msg);
		static ::proto_ff::Sheet_GunvalueConfig* new_pbmsg(){ return new ::proto_ff::Sheet_GunvalueConfig(); }
		static ::proto_ff::Sheet_GunvalueConfig make_pbmsg(){ return ::proto_ff::Sheet_GunvalueConfig(); }
	};
	typedef struct Sheet_GunvalueConfig_s Sheet_GunvalueConfig_t;

}

