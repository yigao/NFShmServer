#pragma once

#include <stdint.h>
#include <NFComm/NFShmCore/NFShmString.h>
#include <NFComm/NFShmStl/NFShmVector.h>
#include <NFComm/NFShmCore/NFSeqOP.h>
#include <NFComm/NFShmCore/NFShmMgr.h>
#include "godevil.pb.h"
#include "godevil_s.h"

namespace proto_ff_s {

	struct E_GodevilPreposetask_s : public NFDescStoreSeqOP {
		E_GodevilPreposetask_s();
		virtual ~E_GodevilPreposetask_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_id;
		int32_t m_type;
		int32_t m_modeltype;
		int32_t m_starttask;
		int32_t m_endtask;
		int32_t m_condition;
		int32_t m_value;
		int32_t m_rewardid;

		virtual void write_to_pbmsg(::proto_ff::E_GodevilPreposetask & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_GodevilPreposetask & msg);
		static ::proto_ff::E_GodevilPreposetask* new_pbmsg(){ return new ::proto_ff::E_GodevilPreposetask(); }
		static ::proto_ff::E_GodevilPreposetask make_pbmsg(){ return ::proto_ff::E_GodevilPreposetask(); }
	};
	typedef struct E_GodevilPreposetask_s E_GodevilPreposetask_t;

	struct Sheet_GodevilPreposetask_s : public NFDescStoreSeqOP {
		Sheet_GodevilPreposetask_s();
		virtual ~Sheet_GodevilPreposetask_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_GodevilPreposetask_s, 20> E_GodevilPreposetask_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_GodevilPreposetask & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_GodevilPreposetask & msg);
		static ::proto_ff::Sheet_GodevilPreposetask* new_pbmsg(){ return new ::proto_ff::Sheet_GodevilPreposetask(); }
		static ::proto_ff::Sheet_GodevilPreposetask make_pbmsg(){ return ::proto_ff::Sheet_GodevilPreposetask(); }
	};
	typedef struct Sheet_GodevilPreposetask_s Sheet_GodevilPreposetask_t;

	struct E_GodevilGodevillvAttributeDesc_s : public NFDescStoreSeqOP {
		E_GodevilGodevillvAttributeDesc_s();
		virtual ~E_GodevilGodevillvAttributeDesc_s(){}
		int CreateInit();
		int ResumeInit();
		int32_t m_type;
		int32_t m_value;

		virtual void write_to_pbmsg(::proto_ff::E_GodevilGodevillvAttributeDesc & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_GodevilGodevillvAttributeDesc & msg);
		static ::proto_ff::E_GodevilGodevillvAttributeDesc* new_pbmsg(){ return new ::proto_ff::E_GodevilGodevillvAttributeDesc(); }
		static ::proto_ff::E_GodevilGodevillvAttributeDesc make_pbmsg(){ return ::proto_ff::E_GodevilGodevillvAttributeDesc(); }
	};
	typedef struct E_GodevilGodevillvAttributeDesc_s E_GodevilGodevillvAttributeDesc_t;

	struct E_GodevilGodevillv_s : public NFDescStoreSeqOP {
		E_GodevilGodevillv_s();
		virtual ~E_GodevilGodevillv_s(){}
		int CreateInit();
		int ResumeInit();
		int64_t m_id;
		int64_t m_exp;
		int64_t m_explimit;
		int32_t m_itemid;
		int32_t m_num;
		NFShmVector<struct E_GodevilGodevillvAttributeDesc_s, 7> m_attribute;

		virtual void write_to_pbmsg(::proto_ff::E_GodevilGodevillv & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_GodevilGodevillv & msg);
		static ::proto_ff::E_GodevilGodevillv* new_pbmsg(){ return new ::proto_ff::E_GodevilGodevillv(); }
		static ::proto_ff::E_GodevilGodevillv make_pbmsg(){ return ::proto_ff::E_GodevilGodevillv(); }
	};
	typedef struct E_GodevilGodevillv_s E_GodevilGodevillv_t;

	struct Sheet_GodevilGodevillv_s : public NFDescStoreSeqOP {
		Sheet_GodevilGodevillv_s();
		virtual ~Sheet_GodevilGodevillv_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_GodevilGodevillv_s, 40> E_GodevilGodevillv_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_GodevilGodevillv & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_GodevilGodevillv & msg);
		static ::proto_ff::Sheet_GodevilGodevillv* new_pbmsg(){ return new ::proto_ff::Sheet_GodevilGodevillv(); }
		static ::proto_ff::Sheet_GodevilGodevillv make_pbmsg(){ return ::proto_ff::Sheet_GodevilGodevillv(); }
	};
	typedef struct Sheet_GodevilGodevillv_s Sheet_GodevilGodevillv_t;

	struct E_GodevilGodevilprivilege_s : public NFDescStoreSeqOP {
		E_GodevilGodevilprivilege_s();
		virtual ~E_GodevilGodevilprivilege_s(){}
		int CreateInit();
		int ResumeInit();
		int64_t m_id;
		int32_t m_oldprice;
		int32_t m_newprice;
		int32_t m_rechargid;
		int32_t m_type;
		int32_t m_lv;
		int32_t m_functiontype;
		int32_t m_parama;
		int32_t m_equipmentid;

		virtual void write_to_pbmsg(::proto_ff::E_GodevilGodevilprivilege & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::E_GodevilGodevilprivilege & msg);
		static ::proto_ff::E_GodevilGodevilprivilege* new_pbmsg(){ return new ::proto_ff::E_GodevilGodevilprivilege(); }
		static ::proto_ff::E_GodevilGodevilprivilege make_pbmsg(){ return ::proto_ff::E_GodevilGodevilprivilege(); }
	};
	typedef struct E_GodevilGodevilprivilege_s E_GodevilGodevilprivilege_t;

	struct Sheet_GodevilGodevilprivilege_s : public NFDescStoreSeqOP {
		Sheet_GodevilGodevilprivilege_s();
		virtual ~Sheet_GodevilGodevilprivilege_s(){}
		int CreateInit();
		int ResumeInit();
		NFShmVector<struct E_GodevilGodevilprivilege_s, 40> E_GodevilGodevilprivilege_List;

		virtual void write_to_pbmsg(::proto_ff::Sheet_GodevilGodevilprivilege & msg) const;
		virtual void read_from_pbmsg(const ::proto_ff::Sheet_GodevilGodevilprivilege & msg);
		static ::proto_ff::Sheet_GodevilGodevilprivilege* new_pbmsg(){ return new ::proto_ff::Sheet_GodevilGodevilprivilege(); }
		static ::proto_ff::Sheet_GodevilGodevilprivilege make_pbmsg(){ return ::proto_ff::Sheet_GodevilGodevilprivilege(); }
	};
	typedef struct Sheet_GodevilGodevilprivilege_s Sheet_GodevilGodevilprivilege_t;

}

