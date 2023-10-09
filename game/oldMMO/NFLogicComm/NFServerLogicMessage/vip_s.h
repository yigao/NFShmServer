#pragma once

#include <stdint.h>
#include <NFComm/NFShmStl/NFShmString.h>
#include <NFComm/NFShmStl/NFShmVector.h>
#include <NFComm/NFShmCore/NFSeqOP.h>
#include <NFComm/NFShmCore/NFShmMgr.h>
#include "vip.pb.h"
#include "vip_s.h"

#define DEFINE_SHEET_VIPVIP_E_VIPVIP_LIST_MAX_NUM 20
#define DEFINE_SHEET_VIPPRIVILEGE_E_VIPPRIVILEGE_LIST_MAX_NUM 60
namespace proto_ff_s {

	struct E_VipVip_s : public NFDescStoreSeqOP {
		E_VipVip_s();
		virtual ~E_VipVip_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;
		int32_t m_level;
		int32_t m_exp;
		int32_t m_privilege_group;

		virtual void write_to_pbmsg(::proto_ff::E_VipVip & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_VipVip & msg);
		static ::proto_ff::E_VipVip* new_pbmsg(){ return new ::proto_ff::E_VipVip(); }
		static ::proto_ff::E_VipVip make_pbmsg(){ return ::proto_ff::E_VipVip(); }
	};
	typedef struct E_VipVip_s E_VipVip_t;

	struct Sheet_VipVip_s : public NFDescStoreSeqOP {
		Sheet_VipVip_s();
		virtual ~Sheet_VipVip_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_VipVip_s, DEFINE_SHEET_VIPVIP_E_VIPVIP_LIST_MAX_NUM> E_VipVip_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_VipVip & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_VipVip & msg);
		static ::proto_ff::Sheet_VipVip* new_pbmsg(){ return new ::proto_ff::Sheet_VipVip(); }
		static ::proto_ff::Sheet_VipVip make_pbmsg(){ return ::proto_ff::Sheet_VipVip(); }
	};
	typedef struct Sheet_VipVip_s Sheet_VipVip_t;

	struct E_VipPrivilege_s : public NFDescStoreSeqOP {
		E_VipPrivilege_s();
		virtual ~E_VipPrivilege_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;
		int32_t m_group;
		int32_t m_type;
		int32_t m_arg;
		NFShmString<60> m_args;

		virtual void write_to_pbmsg(::proto_ff::E_VipPrivilege & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_VipPrivilege & msg);
		static ::proto_ff::E_VipPrivilege* new_pbmsg(){ return new ::proto_ff::E_VipPrivilege(); }
		static ::proto_ff::E_VipPrivilege make_pbmsg(){ return ::proto_ff::E_VipPrivilege(); }
	};
	typedef struct E_VipPrivilege_s E_VipPrivilege_t;

	struct Sheet_VipPrivilege_s : public NFDescStoreSeqOP {
		Sheet_VipPrivilege_s();
		virtual ~Sheet_VipPrivilege_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_VipPrivilege_s, DEFINE_SHEET_VIPPRIVILEGE_E_VIPPRIVILEGE_LIST_MAX_NUM> E_VipPrivilege_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_VipPrivilege & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_VipPrivilege & msg);
		static ::proto_ff::Sheet_VipPrivilege* new_pbmsg(){ return new ::proto_ff::Sheet_VipPrivilege(); }
		static ::proto_ff::Sheet_VipPrivilege make_pbmsg(){ return ::proto_ff::Sheet_VipPrivilege(); }
	};
	typedef struct Sheet_VipPrivilege_s Sheet_VipPrivilege_t;

}

